# Chameleon Studio

A zero-install, browser-based visual patch builder, Faust DSP library, and WebUSB firmware flasher for the **Chameleon Guitar & Drum Machine Multi-Effects Pedal** (powered by the **Electro-Smith Daisy Seed 3**).

---

## How the effects work (read this first)

**`dsp/*.dsp` is the single source of truth for every effect.** Each file is a self-contained
[Faust](https://faust.grame.fr/) program, mono in / mono out, with any number of sliders. A patch on
the pedal is a **series chain of up to 7 effects**; every parameter of every stage keeps the value
you set in the studio, and you choose which **three** parameters (of any stages) sit on the pedal's
three physical pots.

The same Faust code is used in three places:

| Where | How |
|---|---|
| **Browser preview** | `js/faust-engine.js` compiles the `.dsp` in your browser with [faustwasm](https://github.com/grame-cncm/faustwasm) into an AudioWorklet. What you hear in the studio is the real algorithm, not a Web Audio approximation. |
| **Effect catalog / UI** | `node tools/build-catalog.mjs` compiles every `.dsp`, pulls the knob labels/ranges/defaults straight from the sliders, merges the blurbs in `dsp/catalog.json`, and writes `js/effects-data.js`. **Never edit `effects-data.js` by hand.** |
| **Pedal firmware** | The Faust Daisy backend (`faust2daisy` / `faust -a daisy`) turns the `.dsp` into C++ for libDaisy. See *Firmware pipeline* below. |

### Editing or adding an effect

1. Edit or create `dsp/<effect-id>.dsp`. Keep it **mono in / mono out**; any number of sliders.
   Put the unit in the label (`"Time[unit:ms]"`) so the UI can show it; 0…1 sliders are shown as
   percentages. Metadata comes from declares: `name`, `description`, `author`, `license`,
   `category` (`guitar`/`drum`), `family` (`dirt`, `amp`, `time`, `reverb`, `mod`, `dynamics`,
   `filter`, `eq`, `pitch`, `utility`). Add `declare chameleon_flags "-double";` for code that needs
   double precision (all guitarix circuit sims do).
2. Optionally override the UI entry in `dsp/catalog.json` (name, family, blurb) — needed only for
   files without declares.
3. Rebuild the catalog — it refuses to write if anything fails to compile or has the wrong shape,
   and it precompiles every effect to `precompiled/<id>/` so the studio loads them instantly
   (the Klon WDF model alone takes ~20 s to compile in a browser tab):
   ```bash
   node tools/build-catalog.mjs          # or: npm run build
   node tools/build-catalog.mjs --check  # compile-only
   ```
   Icons are Tabler Icons bundled by `node tools/build-icons.mjs` (needs `npm i @iconify-json/tabler`);
   reference any icon as `tabler:<name>` in `catalog.json` or the HTML/JS and rebuild.
4. Hear it without a browser or a pedal:
   ```bash
   node tools/render-effect.mjs tape-delay samples/guitar-lead.wav /tmp/out.wav Feedback=0.9 Time=350
   ```
   Knob names are matched against the slider labels; the tool prints the peak level and flags NaN.

### Design rules baked into the library

- Every slider is smoothed (`si.smoo`) so pot sweeps don't zipper.
- Delay lines are sized for 48 kHz and clamped (`min(MAXDEL - 4)`); integer period counters are clamped
  away from zero (a `% 0` is a hard fault on the Cortex-M7).
- Feedback paths are bounded (`ma.tanh` or filtered gain < 1) so nothing can run away.
- Gain staging targets a guitar/drum-machine input sitting well below full scale; resonant peaks saturate
  instead of clipping the codec.
- Reverb/delay tails were measured with an impulse: plate 0.2 s → 25 s, spring ~2.4 s (4 s at full Dwell),
  tape echo self-oscillates past ~85 % Feedback.

---

## The library

Around 280 effects from four sources, all compiled from Faust source in `dsp/`:

| Prefix | Source | Licence | What |
|---|---|---|---|
| *(none)* | Chameleon originals | MIT | the 31 effects written for this pedal, incl. the Klon Centaur wrapper (BSD) |
| `gx-` | [guitarix](https://github.com/brummer10/guitarix) | **GPL-2.0-or-later** | ~160 files: DK-method circuit sims (TS-9, DS-1, Big Muff, Fuzz Faces, Tone Bender, Rangemaster, Cry Baby & 9 other wahs, Sustainer, Copicat, W20…), 18 tube amps, 27 tone stacks, vactrol tremolo, chorus/phaser/flanger, compressors, delays, reverbs |
| `lib-`, `ex-` | Faust standard library & examples | LGPL / STK (MIT-like) | ~57 wrappers: zita/greyhole/jpverb/spring reverbs, VA filters (Moog, diode, Korg35, Oberheim…), ADAA drive, 1176, tape hysteresis, tone-stack menu, 12AX7 preamp… |
| `tdg-`, `owl-`, `kpp-`, `mag-`, `luca-`, `barabas-` | thedrgreenthumb, OWL patches, Kapitonov Plugins, magnetophon, L. Spanedda, Barabas | MIT / GPL-2 / GPL-3 | shimmer & duck reverbs, rotary, delays, Bluedream/Distruction/Fuzz/Octaver/Tubeamp, Character Compressor, constant-detune chorus… |

The guitarix sims were ported by `tools/port/gx-port.py`, which turns their C++ lookup tables
(diode/transistor/tube curves) into pure-Faust `waveform` tables in `dsp/lib/gx_tables.lib` so the
same source runs in the browser and on the Daisy. The ported DS-1 matches the C++ original within
−63 dB. **Because those files are GPL, the pedal firmware is GPL-2.0-or-later** (a deliberate choice).

## Features

- **Patches & chains:** four patches on the pedal (hold the footswitch to cycle); each is a series chain of up to 7 stages with per-stage bypass, drag-to-reorder, every parameter editable, and any three parameters bound to the physical pots. Patches persist in the browser and export/import as JSON.
- **The pedal:** 3 draggable knobs (drag, wheel, arrow keys, ⇧ for fine, double-click to reset), LCD, footswitch that works like the hardware (tap = bypass, hold = next slot) with 1-to-4 LED flash feedback; the enclosure recolours to the loaded effect's family and the LCD shows a live oscilloscope.
- **Real-DSP In-Browser Auditioning:** the loaded slot's Faust code runs live on royalty-free sample loops
  (dry DI guitar: lead line, chords, riff, full take; an amped riff; analog drum machine, lo-fi
  boom-bap, Amen break — licenses in `samples/ATTRIBUTION.md`). Knob drags update parameters in real time.
- **Effect shoot-out** (`compare/`, button in the top bar): our effects A/B'd against the best open-source Faust pedal code (guitarix circuit sims, standard-library Klon/spring/1176, KPP) on dry DI guitar, loudness-matched. Findings and recommendations in `COMPARISON.md`.
- **~280-effect Faust library** (table above), filterable by family and source, searchable, with the Faust source one click away.
- **C++ Firmware Exporter:** generates a libDaisy control-surface skeleton with the 4 slots' Faust sources embedded, plus a `Makefile`.
- **WebUSB DFU driver** (`js/webdfu.js`) for flashing a Daisy Seed from the browser — see the status note below.

---

## Quick Start

The app must be served over HTTP (the Faust compiler is WebAssembly and is loaded as an ES module;
that doesn't work from `file://`):

```bash
cd chameleon-studio
python3 server.py        # opens http://localhost:8020 in your browser
```

Chrome / Edge / Brave for WebUSB. Firefox and Safari can run the audio preview but not flash.

---

## Project Structure

```
chameleon-studio/
├── index.html               # Main single-page interface
├── server.py                # Local dev server (required — serves the wasm compiler)
├── package.json             # npm run build / check / render / start
├── css/style.css
├── dsp/                     # ★ SOURCE OF TRUTH: one Faust file per effect (~280)
│   ├── catalog.json         #   UI metadata overrides (name, family, blurbs)
│   └── lib/                 #   guitarix libs + generated gx_tables.lib (GPL)
├── js/
│   ├── icons.js             # GENERATED by tools/build-icons.mjs
│   ├── faust-engine.js      # Loads precompiled modules (or compiles dsp in-browser) into AudioWorklets
│   ├── effects-data.js      # GENERATED by tools/build-catalog.mjs — do not edit
│   ├── app.js               # State, pedal UI, sample player, Faust preview wiring, exporter
│   └── webdfu.js            # WebUSB DFU 1.1 driver
├── samples/                 # Royalty-free preview loops (dry DI guitar + drums) + ATTRIBUTION.md
├── precompiled/             # GENERATED per-effect wasm modules (instant load in the studio)
├── compare/                 # Effect shoot-out listening page + level-matched renders
├── COMPARISON.md            # Survey of open-source Faust pedal code, measurements, recommendations
├── tools/
│   ├── build-catalog.mjs    # dsp/*.dsp -> js/effects-data.js + precompiled/ (compile-verified)
│   ├── build-icons.mjs      # Tabler icons -> js/icons.js
│   ├── render-effect.mjs    # Offline render of any effect through a WAV
│   ├── port/gx-port.py      # guitarix C++-table circuit sims -> pure Faust
│   └── compare/             # Shoot-out tooling (native host, build script, external catalog)
├── vendor/faustwasm/        # Faust compiler as WebAssembly (used by browser + tools)
└── firmware/Makefile        # libDaisy Makefile for the generated C++
```

---

## Firmware pipeline (Daisy Seed 3)

What exists today, and what does not — so nobody is surprised when the Seed arrives:

**Written and in the repo**

- The DSP: every effect is a `.dsp` file that the Faust compiler turns into a C++ class (`faust -lang cpp -double`).
  The same files the browser runs are what the pedal runs; nothing gets re-implemented.
- The control surface, emitted by the *Firmware* modal (`generateFirmware()` in `js/app.js`): three pots on
  ADC pins 22/23/24, footswitch on pin 28 with a debounced tap / 650 ms hold state machine (tap = bypass,
  hold = next patch), status LED, and a `PotTakeover` struct that implements the rule you asked for — a
  stored value stays exactly where the patch programmed it until the physical pot moves past a 2 % deadband,
  then the pot catches up and takes over smoothly (no jumps).
- A per-patch **pot lock** (the `POTS LIVE / POTS LOCKED` toggle on the pedal, or press `L`): a locked patch
  ignores the physical pots entirely, so nothing on stage can be changed by a foot; values stay editable in the studio.
- The patch table: the four patches, their chain of up to seven stages, every parameter value, and which
  (stage, parameter) each of the three pots is bound to, all emitted as constant data.

**Building and flashing (firmware/)**

```bash
brew install faust dfu-util && brew install --cask gcc-arm-embedded   # once
git clone --recurse-submodules https://github.com/electro-smith/libDaisy ../fw/libDaisy && make -C ../fw/libDaisy
git clone https://github.com/electro-smith/DaisySP ../fw/DaisySP && make -C ../fw/DaisySP
cd firmware && ./gen-faust.sh dynamic-overdrive   # regenerate faust/*.h for the effects in patches.h
make                                              # -> build/chameleon.bin ; cp it to firmware/chameleon.bin for the studio
make program-dfu                                  # or: Seed in DFU mode, Flash Pedal in the studio
```

`main.cpp` is the engine (control surface, PotTakeover, series chain, SDRAM pool for effect state), `patches.h` the
patch table, `chameleon_faust.h` the tiny Faust runtime. The studio's Flash button streams `firmware/chameleon.bin`
over real DfuSe (`js/webdfu.js`). Internal flash is 128 KB, enough for a couple of light effects; the full library
build will target the Daisy bootloader / 8 MB QSPI (`APP_TYPE=BOOT_QSPI`).

**Not written yet**

- `tools/build-firmware.mjs`: generate `patches.h` + the faust/ headers straight from a studio patch export.
- The bootloader/QSPI build for chains that don't fit in 128 KB (guitarix table effects are megabytes).
- CPU budgeting per chain.

So: the day the Seed shows up, the build is `faust -lang cpp -double -a daisy.cpp dsp/<effect>.dsp` for each
stage, the generated control-surface file, the glue, `make`, then `make program-dfu` (or the studio's Flash
button, which streams the `.bin` over WebUSB to the STM32 bootloader). CPU budget on the Seed 3 (Cortex-M7,
480 MHz) is roughly 7 light effects or 3-4 guitarix circuit sims at 48 kHz; the studio warns nothing about
this yet, so keep an eye on it.

### Flashing your Daisy Seed (when a .bin exists)

1. Connect the pedal over a **USB-C data cable**.
2. Enter DFU mode: hold **BOOT**, tap **RESET**, release **BOOT**.
3. Click **Flash Pedal** and pick **STM32 BOOTLOADER / DFU in FS Mode**.

## Deploying the studio

It is a static site — no server, no build step at deploy time (the catalog is committed already built). Any static host
works; **Vercel** is the easiest and the free tier is enough. The one hard requirement is **HTTPS**: WebUSB and
AudioWorklet are only exposed to secure origins (and `localhost`), and every real host gives you HTTPS for free.

```bash
git init && git add -A && git commit -m "Chameleon Studio"
npx vercel        # or push to GitHub and import the repo at vercel.com — framework preset: "Other"
```

`vercel.json` sets the `application/wasm` content type, long cache headers for the precompiled modules, vendor
bundle and audio, and `Permissions-Policy: usb=(self)` so WebUSB stays allowed on the page. Railway, Netlify,
Cloudflare Pages and GitHub Pages all work equally well for the same reason; Railway is a container host, so
you would pay for an always-on process to serve files that never change — no advantage here.

Repo size is ~53 MB (12 MB precompiled wasm, 21 MB comparison audio, 9 MB samples); comfortably inside every
host's limits. If you ever want to shrink it, `compare/audio` is the first thing to move to object storage.
