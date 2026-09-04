# Open-source Faust guitar effects — survey and shoot-out

*September 2026. Companion to the listening page at `compare/` (open the studio, click **Shoot-out**).*

## TL;DR

There are essentially three serious bodies of open-source Faust guitar code, and they sit at very
different licence tiers:

| Source | What it is | Licence | Verdict |
|---|---|---|---|
| **Faust standard library** (`faustlibraries`) | `ve.klonCentaur` (full WDF Klon), `aa.*` anti-aliased clippers, `re.springreverb`, `re.dattorro_rev`, `co.limiter_1176_R4`, `hy.ja_hysteresis` (tape), `ts.*` 27 tone stacks, `tu.*` tube tables, `ve.crybaby/autowah`, `wd.*` WDF toolkit | LGPL-2.1+ / STK-4.3 (MIT-like) / BSD-3 for the Klon | **Use freely.** Already in our toolchain; nothing to vendor. Klon is now effect #31. |
| **Guitarix** (`brummer10/guitarix`, `trunk/src/LV2/faust`) | ~60 DK-method *circuit simulations* generated from schematics with component values: TS-9, Boss DS-1, Big Muff, three Fuzz Faces, Tone Bender, Rangemaster, Cry Baby GCB-95 + 9 other wahs, Boss OC-2, vactrol tremolo, Watkins Copicat tape echo, 18 tube amps, 27 tone stacks. | **GPL-2+** | **The best-sounding drives/fuzz/wah/tremolo in Faust, full stop.** Usable only if the pedal firmware ships as GPL (source published). Needs 96 kHz and C++ lookup-table headers — works on the Daisy, does **not** compile in the browser as-is. |
| **KPP** (Kapitonov Plugins Pack) | Hand-tuned waveshaper pedals (Bluedream TS-style, Distruction, Fuzz, Octaver, tube amp) | GPL-3 | Decent but not modelled; nothing we can't write ourselves. Skip. |

Everything else found (OWL patches, DSPedal, TubeScreamer toy, thedrgreenthumb reverbs) is either
unlicensed, toy-grade, or targets the old pre-`stdfaust` library and would need porting. The full
catalog of 1 338 `.dsp` files across 16 repos is in `tools/compare/EXTERNAL-FAUST-CATALOG.md`.

Two structural gaps worth knowing: **no BBD (bucket-brigade) chorus/delay model exists anywhere in
Faust**, and **no dispersive spring reverb** (the standard library's `re.springreverb` is a
Hadamard FDN "spring-flavoured" design). Ours are currently the only Faust attempts at both.

## How the shoot-out was done

- Every candidate was compiled with the *native* Faust 2.87.11 compiler to C++ (double precision) and
  rendered through the same offline host (`tools/compare/host.cpp`). Guitarix circuit sims were run at
  96 kHz as they declare, then resampled; ours at 48 kHz as they'll run on the pedal.
- Input: **dry DI guitar** (`samples/di-*.wav`, MIT / CC0 — see `samples/ATTRIBUTION.md`) at −6 dBFS
  peak, three clips: single-note line with rests, strummed chords, riff with muted chops.
- Every render is **loudness-matched** (RMS over the louder half of 50 ms frames → −20 dBFS) before
  encoding, so the louder one can't win by default. The gain applied is shown on each row.
- Drives additionally got a 220 Hz sine at −12 dBFS to measure THD, even/odd harmonic balance and
  non-harmonic (aliasing) energy.

Only ears decide the rest. The page at `compare/` lets you switch between variants at the same
playback position.

## Measured harmonic profile (220 Hz sine, −12 dBFS)

| Set | Variant | Licence | THD | even/odd | non-harmonic |
|---|---|---|---|---|---|
| Overdrive | Ours — Dynamic Overdrive | ours | 22.1% | -8.0 dB | -117.4 dB |
| Overdrive | Klon Centaur — faustlibraries ve.klonCentaur (WDF) | BSD-3 (Chowdhury-DSP) | 11.0% | odd only | -116.3 dB |
| Overdrive | Tube Screamer TS-9 — guitarix ts9sim | GPL-2+ | 15.3% | odd only | -70.9 dB |
| Overdrive | Boss DS-1 — guitarix DK circuit sim | GPL-2+ | 7.8% | -8.4 dB | -80.7 dB |
| Overdrive | ProCo RAT — guitarix aclipper | GPL-2+ | 27.7% | -19.4 dB | -64.8 dB |
| Overdrive | KPP Bluedream | GPL-3 | 13.6% | odd only | -77.8 dB |
| Fuzz | Ours — Silicon Fuzz | ours | 41.5% | -28.9 dB | -52.5 dB |
| Fuzz | Fuzz Face — guitarix DK circuit sim | GPL-2+ | 33.7% | -2.2 dB | -54.1 dB |
| Fuzz | Big Muff Pi — guitarix DK circuit sim | GPL-2+ | 5.8% | odd only | -85.5 dB |
| Fuzz | KPP Fuzz | GPL-3 | 0.0% | -26.6 dB | -118.3 dB |
| Boost | Ours — JFET Boost | ours | 0.5% | odd only | -118.3 dB |
| Boost | Rangemaster — guitarix DK sim | GPL-2+ | 0.0% | -59.4 dB | -112.5 dB |
| Boost | Screaming Bird — guitarix DK sim | GPL-2+ | 0.0% | -54.6 dB | -114.9 dB |

Reading it: the Klon and TS-9 are symmetric clippers (odd harmonics only), which is correct for those
circuits. The **Fuzz Face has even harmonics only 2 dB below odd** — that's the "warm/sputtery"
germanium character, and it's the single biggest thing our fuzz lacks (ours is −29 dB even, i.e. it
sounds like a symmetric clipper with a gate). The Big Muff and KPP Fuzz read low here only because a
−12 dBFS sine under-drives them at these settings; on the riff clip they're plenty saturated.
The "non-harmonic" column is aliasing plus resampling residue: our drives are clean at 48 kHz because
they're gentle `tanh`; the circuit sims run at 96 kHz and still show −65 to −85 dB, which is the
price of hard-knee diode/transistor models without oversampling.

## What ours is actually missing (the honest part)

1. **Drives are one nonlinearity plus filters.** Real pedals are a *chain* of interacting stages
   whose bias points move with the signal (DS-1: buffer → transistor boost → op-amp clip → tone;
   Fuzz Face: two transistors that starve each other). That interaction is where "touch" comes
   from, and the DK sims have it because they solve the circuit. Ours can't get there with a static
   waveshaper — it needs either the WDF approach (`wd.*` in the standard library, exactly how the Klon
   is done) or a copied DK model.
2. **Our fuzz has no even-harmonic content and a hard gate.** See the table.
3. **Tape delay:** the Copicat model has four real head positions, a pentode record driver and two
   12AX7 playback stages; ours has wow/flutter, a saturator and a filter. Ours is a good "tape-ish
   digital delay"; theirs is a tape echo.
4. **Tremolo:** the vactrol model's photocell has asymmetric attack/decay, so the pulse is lopsided
   in a way that sine-LFO tremolos aren't. Small change, very audible.
5. **Chorus/flanger/phaser/plate:** roughly at parity — guitarix uses the same standard-library
   building blocks we do. Not where the gap is.
6. **Spring:** genuinely different designs; A/B them. Ours chirps (dispersive), theirs is a smooth FDN.

## Recommendations, in order

**Do now (no licence cost):**

1. **Klon Centaur is in the library as effect #31** (`dsp/klon-centaur.dsp`, BSD-3). It takes ~20 s
   to compile in a browser tab, so `tools/build-catalog.mjs` now precompiles every effect to
   `precompiled/<id>/` and the studio loads those instantly (falls back to in-browser compile if
   missing). Rebuild after any `.dsp` edit.
2. Rebuild **Dynamic Overdrive** with the standard library's tools: `aa.*` (ADAA) clippers instead of
   plain `tanh` (alias-free at 48 kHz), a real Fender/Marshall tone stack from `ts.*` instead of a
   lowpass, and two cascaded asymmetric stages with a DC-shifting bias so it "breathes". This is a
   redesign of one file, not a licence question.
3. Give **Silicon Fuzz** real even harmonics: a bias-shifted second stage and an envelope-driven
   bias sag (the Fuzz Face "cleans up when you roll the volume back" behaviour), soft gate instead
   of hard.
4. **Tape saturation** via `hy.ja_hysteresis` (Jiles-Atherton, the CHOW Tape model) in the tape
   delay's loop and in the drum tape saturator.
5. **Compressor:** A/B ours against `co.limiter_1176_R4` in the shoot-out; if the 1176 wins, it's a
   two-line swap.

**Decide (needs a GPL call):**

6. If you're comfortable with the *firmware* being GPL-2+ (the web studio can stay under any
   licence; only the code that goes on the pedal is affected), **adopt the guitarix DK sims** for
   TS-9, DS-1, Fuzz Face, Big Muff, Rangemaster, GCB-95 Cry Baby (as the wah core), vactrol tremolo
   and the Copicat. That is, by a wide margin, the fastest route to a pedal that sounds like the
   pedals it's named after. Two engineering tasks come with it:
   - the sims use C++ lookup-table headers (`ffunction`) for the transistor/diode curves, so they
     don't compile in the browser. The fix is a script that converts each table header into a Faust
     `waveform` + `rdtable` — mechanical, and it makes the browser preview and the firmware the same
     code again;
   - they want 96 kHz. The Daisy can do it; the pedal would run at 96 kHz or the sims get wrapped in
     a 2× oversampler.
7. If you'd rather keep the firmware permissively licensed, use the guitarix schematics
   (`trunk/tools/ampsim/DK/gschem-schematics/*.sch`) as *reference* and build the same circuits with
   the standard library's WDF toolkit (`wd.*`) — that's how the Klon got into the library
   (BSD, from Chowdhury-DSP). Slower, but clean.

## Samples: the reverb problem is fixed

The previous "clean" guitar samples were CC0 but recorded in a room, so every delay and reverb was
being judged on top of baked-in ambience. They're replaced with **true DI recordings**:
`di-lead.wav` (single-note line with rests, sequenced from CC0 Karoryfer DI single-note samples),
`di-chords.wav` and `di-riff.wav` (cut from the MIT-licensed DI take in `sdatkinson/NeuralAmpModelerPlugin`),
plus `di-full-take.wav` (the whole 16 s). Gaps between notes measure below −56 dBFS.

Two caveats: the lead line is sequenced, not a human performance (no dry CC/MIT single-note lead
performance was reachable — GuitarSet and EGFxSet are CC-BY but live on Zenodo, which the sandbox
can't reach; they'd be the upgrade if you download them yourself). And the amped riff is kept as
a source but labelled as not dry.

## Reproducing the shoot-out

`tools/compare/` holds `compare.py` (sets, params, level matching, metrics), `host.cpp` (offline host),
`build.sh` (Faust → C++ → binary, with the guitarix table headers on the include path) and the
`wrap/*.dsp` one-liners for the standard-library candidates. It expects the native Faust compiler and
the cloned repos; the catalog lists exactly which repos and paths were used.
