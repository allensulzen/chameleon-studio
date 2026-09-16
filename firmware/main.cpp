/**
 * Chameleon Pedal — Daisy Seed firmware
 *
 * Control surface + multi-stage Faust engine.
 *   footswitch  : physical pin 28 (D21) to GND (pin 40), internal pull-up. tap = bypass, hold = next patch
 *   pots        : wipers on physical pins 22/23/24 (A0/A1/A2), ends to 3V3A (pin 21) and AGND (pin 20)
 *   audio       : IN L pin 16, OUT L pin 18 (mono; OUT R mirrors)
 *   LED         : onboard user LED (solid = active) plus an RGB LED on TIM3 PWM —
 *                 red pin 10 (D9), green pin 11 (D10), blue pin 5 (D4), common cathode to AGND, 150/100/100 Ω.
 *                 Colour = the patch's hue (same rule as the studio); dim = bypass; N flashes of the new colour = patch N.
 *
 * Every effect in the catalog is compiled in (firmware/fx/<id>.cpp, one factory per effect, listed in
 * effects.h). Patches are DATA: the studio writes a PatchBlob (patchblob.h) into QSPI at PATCH_BLOB_ADDR
 * and the firmware reads it at boot — no rebuild to change patches. patches.h is only the fallback set
 * used when no valid blob is present (fresh flash).
 * Pot rule: stored values win until a pot moves (>2 % of travel) and catches up — see PotTakeover.
 */
#include <cstdio>
#include <cstring>
#include <new>
#include "daisy_seed.h"
#include "chameleon_faust.h"
#include "effects.h"
#include "patchblob.h"
#include "patches.h"

#ifndef FW_ID
#define FW_ID "dev"
#endif

using namespace daisy;

static DaisySeed     hw;
static Switch        footswitch;
static AnalogControl pots[3];
static PWMHandle     pwm;                 // TIM3: ch1 D9 (red), ch2 D10 (green), ch3 D4 (blue)

static constexpr int   BLOCK      = 48;
static constexpr float HOLD_MS    = 650.f;
static constexpr float POT_DEADBAND = 0.02f;

// ------------------------------------------------------------------ effect factory
// Faust objects live in SDRAM (64 MB) so reverbs and long delays never fight the 512 KB of core RAM.
static char DSY_SDRAM_BSS sdram_pool[16 * 1024 * 1024];
static size_t sdram_used = 0;
static void* sdram_alloc(size_t n) { n = (n + 31) & ~size_t(31); void* p = sdram_pool + sdram_used; sdram_used += n; return p; }

static chdsp* make_effect(int idx) {
    if (idx < 0 || idx >= NUM_EFFECTS) return nullptr;
    const EffectEntry& e = EFFECTS[idx];
    return e.make(sdram_alloc(e.size()));
}
static int effect_index(const char* id) { for (int i = 0; i < NUM_EFFECTS; i++) if (!strcmp(EFFECTS[i].id, id)) return i; return -1; }

// ------------------------------------------------------------------ pot takeover
struct PotTakeover {
    float stored = 0.f, origin = 0.f; bool armed = false, live = false;
    void Load(float storedNorm, float potNow) { stored = storedNorm; origin = potNow; armed = false; live = false; }
    float Update(float potNow) {
        if (!armed) { if (fabsf(potNow - origin) > POT_DEADBAND) armed = true; else return stored; }
        if (!live)  { if (fabsf(potNow - stored) < POT_DEADBAND || (potNow - stored) * (origin - stored) < 0.f) live = true; else return stored; }
        return potNow;
    }
};

// ------------------------------------------------------------------ runtime patch/stage state
struct Stage { chdsp* dsp = nullptr; ParamMap params; bool on = false; int nin = 1, nout = 1; };
struct Patch {
    Stage stages[MAX_STAGES]; int nstages = 0;
    ParamMap::Param* potParam[3] = { nullptr, nullptr, nullptr };
    PotTakeover pot[3];
    bool potsLocked = false;
};
static Patch patches[NUM_PATCHES];

// The live patch table: copied out of QSPI (studio-written blob) or synthesised from patches.h.
static PatchBlob DSY_SDRAM_BSS blob;
static bool blob_from_qspi = false;

static volatile int  current_patch = 0;
static volatile bool effect_active = true;
static bool          hold_fired    = false;
static volatile bool led_dirty     = false;   // set in the audio thread, serviced in main()
static volatile bool want_dfu      = false;   // set by the USB command "DFU", serviced in main()

// ---- USB serial (CDC) command port: the studio talks to the running pedal over this.
//   "ID?"  -> "CHAMELEON <patch> <active>\n"   (also lets the site recognise a Chameleon)
//   "DFU"  -> reboot into the Daisy bootloader and stay there until flashed. No buttons.
static char usb_line[32]; static int usb_len = 0;
static void usb_rx(uint8_t* buf, uint32_t* len) {
    for (uint32_t i = 0; i < *len; i++) {
        char c = (char)buf[i];
        if (c == '\n' || c == '\r') {
            usb_line[usb_len] = 0;
            if (!strcmp(usb_line, "DFU")) { want_dfu = true; }
            else if (!strcmp(usb_line, "ID?")) { char r[96]; int n = snprintf(r, sizeof r, "CHAMELEON %d %d %s %d %s\n", current_patch + 1, effect_active ? 1 : 0, FW_ID, NUM_EFFECTS, blob_from_qspi ? "blob" : "builtin"); hw.usb_handle.TransmitInternal((uint8_t*)r, n); }
            usb_len = 0;
        } else if (usb_len < (int)sizeof(usb_line) - 1) usb_line[usb_len++] = c;
    }
}
static float         sr            = 48000.f;

static float bufA[BLOCK], bufB[BLOCK], bufR[BLOCK];

// patches.h (fallback) -> blob, so there is one code path
static void blob_from_builtin() {
    memset(&blob, 0, sizeof blob);
    blob.h.magic = PATCH_BLOB_MAGIC; blob.h.version = PATCH_BLOB_VERSION; blob.h.length = sizeof blob; blob.h.npatches = PB_PATCHES;
    for (int p = 0; p < NUM_PATCHES && p < PB_PATCHES; p++) {
        const PatchDef& def = PATCHES[p]; PbPatch& pb = blob.patches[p];
        strncpy(pb.name, def.name, PB_NAME - 1); pb.potsLocked = def.potsLocked; pb.hue = (uint16_t)def.hue; pb.nstages = def.nstages;
        for (int s = 0; s < def.nstages && s < PB_STAGES; s++) {
            const StageDef& sd = def.stages[s]; PbStage& ps = pb.stages[s];
            ps.effect = (uint16_t)sd.effect; strncpy(ps.id, EFFECTS[sd.effect].id, PB_ID - 1); ps.on = sd.on; ps.nvalues = sd.nvalues;
            for (int v = 0; v < sd.nvalues && v < PB_VALUES; v++) { strncpy(ps.values[v].path, sd.values[v].path, PB_PATH - 1); ps.values[v].value = sd.values[v].value; }
        }
        for (int k = 0; k < 3; k++) { pb.pots[k].stage = (int8_t)def.pots[k].stage; strncpy(pb.pots[k].path, def.pots[k].path, PB_PATH - 1); }
    }
}

static void load_blob() {
    const PatchBlob* q = (const PatchBlob*)PATCH_BLOB_ADDR;   // QSPI is memory-mapped under the Daisy bootloader
    if (pb_valid(q)) { memcpy(&blob, q, sizeof blob); blob_from_qspi = true; }
    else blob_from_builtin();
}

static void build_patches() {
    for (int p = 0; p < NUM_PATCHES; p++) {
        const PbPatch& def = blob.patches[p]; Patch& pt = patches[p];
        pt.nstages = def.nstages > PB_STAGES ? PB_STAGES : def.nstages; pt.potsLocked = def.potsLocked;
        for (int s = 0; s < pt.nstages; s++) {
            const PbStage& sd = def.stages[s]; Stage& st = pt.stages[s];
            // trust the id string over the index, so a blob written for another firmware build still resolves
            int idx = (sd.effect < NUM_EFFECTS && !strncmp(EFFECTS[sd.effect].id, sd.id, PB_ID)) ? sd.effect : effect_index(sd.id);
            st.dsp = make_effect(idx); if (!st.dsp) { st.on = false; continue; }
            st.dsp->init((int)sr);
            st.nin = st.dsp->getNumInputs(); st.nout = st.dsp->getNumOutputs();
            st.params.build(st.dsp);
            int nv = sd.nvalues > PB_VALUES ? PB_VALUES : sd.nvalues;
            for (int v = 0; v < nv; v++) st.params.set(sd.values[v].path, sd.values[v].value);
            st.on = sd.on != 0;
        }
        for (int k = 0; k < 3; k++) {
            const PbPot& pd = def.pots[k];
            pt.potParam[k] = (pd.stage >= 0 && pd.stage < pt.nstages) ? pt.stages[pd.stage].params.find(pd.path) : nullptr;
        }
    }
}

static void load_patch(int p, const float raw[3]) {
    Patch& pt = patches[p];
    for (int k = 0; k < 3; k++) {
        ParamMap::Param* prm = pt.potParam[k];
        pt.pot[k].Load(prm ? ParamMap::norm(prm, *prm->zone) : 0.f, raw[k]);
    }
}

// ---- RGB LED: hue (0-360) -> gamma-corrected PWM, so the box shows the studio's colour
static void led_rgb(float r, float g, float b) {
    auto gam = [](float x) { x = x < 0 ? 0 : x > 1 ? 1 : x; return x * x; };
    pwm.Channel1().Set(gam(r)); pwm.Channel2().Set(gam(g) * 0.75f); pwm.Channel3().Set(gam(b) * 0.85f);   // green/blue LEDs run brighter per mA; trim to balance
}
static void led_hue(int hue, float level) {
    float h = fmodf((float)hue, 360.f) / 60.f; if (h < 0) h += 6.f;
    float x = 1.f - fabsf(fmodf(h, 2.f) - 1.f), r = 0, g = 0, b = 0;
    if (h < 1) { r = 1; g = x; } else if (h < 2) { r = x; g = 1; } else if (h < 3) { g = 1; b = x; } else if (h < 4) { g = x; b = 1; } else if (h < 5) { r = x; b = 1; } else { r = 1; b = x; }
    led_rgb(r * level, g * level, b * level);
}
static void led_show() {
    hw.SetLed(effect_active);
    led_hue(blob.patches[current_patch].hue, effect_active ? 1.f : 0.06f);
}
static void blink(int n) {
    int hue = blob.patches[current_patch].hue;
    for (int i = 0; i < n; i++) { hw.SetLed(true); led_hue(hue, 1.f); System::Delay(90); hw.SetLed(false); led_rgb(0, 0, 0); System::Delay(140); }
    led_show();
}

// ------------------------------------------------------------------ audio
static void AudioCallback(AudioHandle::InputBuffer in, AudioHandle::OutputBuffer out, size_t size) {
    float raw[3];
    for (int k = 0; k < 3; k++) raw[k] = pots[k].Process();

    Patch& pt = patches[current_patch];
    if (!pt.potsLocked) {
        for (int k = 0; k < 3; k++) {
            ParamMap::Param* prm = pt.potParam[k]; if (!prm) continue;
            float n = pt.pot[k].Update(raw[k]);
            if (pt.pot[k].live) *prm->zone = prm->min + (prm->max - prm->min) * n;
        }
    }

    // footswitch: tap = bypass toggle, hold = next patch
    footswitch.Debounce();
    if (footswitch.Pressed() && footswitch.TimeHeldMs() > HOLD_MS && !hold_fired) {
        hold_fired = true;
        current_patch = (current_patch + 1) % NUM_PATCHES;
        load_patch(current_patch, raw);
    }
    if (footswitch.FallingEdge()) { if (!hold_fired) { effect_active = !effect_active; led_dirty = true; } hold_fired = false; }

    // series chain, mono
    size_t n = size > (size_t)BLOCK ? BLOCK : size;
    float* cur = bufA; float* nxt = bufB;
    for (size_t i = 0; i < n; i++) cur[i] = in[0][i];
    if (effect_active) {
        for (int s = 0; s < pt.nstages; s++) {
            Stage& st = pt.stages[s]; if (!st.on || !st.dsp) continue;
            float* ins[2]  = { cur, cur };
            float* outs[2] = { nxt, bufR };             // stereo effects: keep L, drop R
            st.dsp->compute((int)n, ins, outs);
            float* t = cur; cur = nxt; nxt = t;
        }
    }
    for (size_t i = 0; i < n; i++) { out[0][i] = cur[i]; out[1][i] = cur[i]; }
}

// ------------------------------------------------------------------ main
int main(void) {
    hw.Init(true);                       // boost: 480 MHz
    hw.SetAudioBlockSize(BLOCK);
    hw.SetAudioSampleRate(SaiHandle::Config::SampleRate::SAI_48KHZ);
    sr = hw.AudioSampleRate();

    footswitch.Init(seed::D21, sr / BLOCK);   // physical pin 28
    AdcChannelConfig adc[3];
    adc[0].InitSingle(seed::A0); adc[1].InitSingle(seed::A1); adc[2].InitSingle(seed::A2);   // physical pins 22/23/24
    hw.adc.Init(adc, 3);
    for (int k = 0; k < 3; k++) pots[k].Init(hw.adc.GetPtr(k), sr / BLOCK);
    hw.adc.Start();

    load_blob();
    build_patches();
    float raw[3] = { 0.f, 0.f, 0.f };
    load_patch(0, raw);

    // RGB LED on TIM3 (24 kHz PWM, no visible flicker, above the audio band's neighbours)
    PWMHandle::Config pc; pc.periph = PWMHandle::Config::Peripheral::TIM_3; pc.prescaler = 0; pc.period = 10000;
    pwm.Init(pc);
    PWMHandle::Channel::Config c1(seed::D9), c2(seed::D10), c3(seed::D4);
    pwm.Channel1().Init(c1); pwm.Channel2().Init(c2); pwm.Channel3().Init(c3);

    // USB serial so the studio can identify the pedal and send it to the bootloader without buttons
    hw.usb_handle.Init(UsbHandle::FS_INTERNAL);
    hw.usb_handle.SetReceiveCallback(usb_rx, UsbHandle::FS_INTERNAL);

    led_show();
    hw.StartAudio(AudioCallback);

    // LED work runs here, outside the audio callback (blinks take real time)
    int shown = 0;
    while (1) {
        if (want_dfu) { hw.StopAudio(); led_rgb(1, 1, 1); System::Delay(150); System::ResetToBootloader(System::BootloaderMode::DAISY_INFINITE_TIMEOUT); }
        if (shown != current_patch) { shown = current_patch; blink(shown + 1); }
        else if (led_dirty) { led_dirty = false; led_show(); }
        System::Delay(20);
    }
}
