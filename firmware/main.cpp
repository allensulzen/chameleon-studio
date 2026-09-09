/**
 * Chameleon Pedal — Daisy Seed firmware
 *
 * Control surface + multi-stage Faust engine.
 *   footswitch  : physical pin 28 (D21) to DGND, internal pull-up. tap = bypass, hold = next patch
 *   pots        : wipers on physical pins 22/23/24 (A0/A1/A2), ends to 3V3_A (pin 38) and AGND (pin 20)
 *   audio       : IN L pin 16, OUT L pin 18 (mono; OUT R mirrors)
 *   LED         : onboard user LED. solid = active, off = bypass, N blinks = patch N after a hold
 *
 * Effects are Faust classes generated into firmware/faust/*.h; the patch table is patches.h.
 * Pot rule: stored values win until a pot moves (>2 % of travel) and catches up — see PotTakeover.
 */
#include <cstdio>
#include <new>
#include "daisy_seed.h"
#include "chameleon_faust.h"
#include "patches.h"

using namespace daisy;

static DaisySeed     hw;
static Switch        footswitch;
static AnalogControl pots[3];

static constexpr int   BLOCK      = 48;
static constexpr float HOLD_MS    = 650.f;
static constexpr float POT_DEADBAND = 0.02f;

// ------------------------------------------------------------------ effect factory
enum EffectId {
#define X(cls, id) EFFECT_##cls,
    CH_EFFECTS(X)
#undef X
    NUM_EFFECTS
};

// Faust objects live in SDRAM (64 MB) so reverbs and long delays never fight the 512 KB of core RAM.
static char DSY_SDRAM_BSS sdram_pool[16 * 1024 * 1024];
static size_t sdram_used = 0;
static void* sdram_alloc(size_t n) { n = (n + 31) & ~size_t(31); void* p = sdram_pool + sdram_used; sdram_used += n; return p; }

static chdsp* make_effect(int idx) {
    switch (idx) {
#define X(cls, id) case EFFECT_##cls: return new (sdram_alloc(sizeof(cls))) cls();
        CH_EFFECTS(X)
#undef X
        default: return nullptr;
    }
}

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

static volatile int  current_patch = 0;
static volatile bool effect_active = true;
static bool          hold_fired    = false;
static float         sr            = 48000.f;

static float bufA[BLOCK], bufB[BLOCK], bufR[BLOCK];

static void build_patches() {
    for (int p = 0; p < NUM_PATCHES; p++) {
        const PatchDef& def = PATCHES[p]; Patch& pt = patches[p];
        pt.nstages = def.nstages; pt.potsLocked = def.potsLocked;
        for (int s = 0; s < def.nstages; s++) {
            const StageDef& sd = def.stages[s]; Stage& st = pt.stages[s];
            st.dsp = make_effect(sd.effect); if (!st.dsp) { st.on = false; continue; }
            st.dsp->init((int)sr);
            st.nin = st.dsp->getNumInputs(); st.nout = st.dsp->getNumOutputs();
            st.params.build(st.dsp);
            for (int v = 0; v < sd.nvalues; v++) st.params.set(sd.values[v].path, sd.values[v].value);
            st.on = sd.on;
        }
        for (int k = 0; k < 3; k++) {
            const PotDef& pd = def.pots[k];
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

static void blink(int n) {
    for (int i = 0; i < n; i++) { hw.SetLed(true); System::Delay(90); hw.SetLed(false); System::Delay(140); }
    hw.SetLed(effect_active);
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
    if (footswitch.FallingEdge()) { if (!hold_fired) { effect_active = !effect_active; hw.SetLed(effect_active); } hold_fired = false; }

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

    build_patches();
    float raw[3] = { 0.f, 0.f, 0.f };
    load_patch(0, raw);

    hw.SetLed(true);
    hw.StartAudio(AudioCallback);

    // pending patch-change blinks run here, outside the audio callback
    int shown = 0;
    while (1) {
        if (shown != current_patch) { shown = current_patch; blink(shown + 1); }
        System::Delay(20);
    }
}
