# External Faust guitar-effect catalog

Cloned 2026-09-04 into `/home/claude/chameleon/ext/` (all `--depth 1`, ~1.9 GB, most of it the
`grame-cncm/faust` tree). Nothing has been compiled. Totals across every clone:
**1338 `.dsp` files, 95 `.lib` files**. Guitar-relevant subset is far smaller (see per-repo sections).

Legend for the "seriousness" flag:

* **[CIRCUIT]** = derived from a real schematic with component values (guitarix DK-simulator
  output, WDF trees, Kenéz TS9 analysis, etc.). Best reference material.
* **[TABLE]** = nonlinearity is a precomputed lookup table of a solved circuit (guitarix
  `tubestage`, `tranystage`, `ts9nonlin.h`).
* **[OS/AA]** = has explicit oversampling / anti-aliasing (guitarix files declare
  `samplerate "96000"` and expect the host to run them at 96k; the LV2 wrappers resample).
* **[ALGO]** = decent generic DSP (JOS/Graef-quality filters, phasers, reverbs) but no circuit.
* **[TOY]** = a few lines of `tanh`/`cubicnl` and a filter; fine for reference of parameter
  ranges only.

Library-generation legend (needed for porting):

* **std** = `import("stdfaust.lib")` with `fi.`/`de.`/`ef.`/`os.` prefixes: compiles on current Faust.
* **OLD** = `effect.lib` / `filter.lib` / `music.lib` / `math.lib` / `oscillator.lib`
  (pre-2017 naming, `SR`, `PI`, `smooth`, `fdelay` unprefixed). Needs porting; the old
  libs are still shipped in `grame-cncm_faustlibraries/old/` so they *can* be compiled
  with `-I ext/grame-cncm_faustlibraries/old`.

---

## Repo overview

| Dir | Upstream | License (from LICENSE/COPYING) | Type | .dsp | Faust gen | Verdict |
|---|---|---|---|---|---|---|
| `brummer10_guitarix` | brummer10/guitarix | `trunk/COPYING`: "GPL version 2 or later" (some files GPL-3+/LGPL-3+) | GPL-2.0-or-later | 442 | std + `guitarix.lib`/`trany.lib`/`redeye.lib` (1 file still `filter.lib`) | **The motherlode.** ~60 circuit-simulated pedals, 18 tube-stage amps, 27 tone stacks, tape echo, tremolo, chorus/flanger/phaser, compressors. |
| `brummer10_GxPlugins.lv2` | brummer10/GxPlugins.lv2 (+ 47 submodules cloned) | per-plugin `LICENSE` = GPL-3.0 | GPL-3.0 | **0** | n/a | Only *compiled* Faust output (`*/dsp/*.cc`, headers say "generated from file './/sd1sim.dsp' by dsp2cc"). The `.dsp` sources are NOT in git. Still useful: the `.cc` files are readable state-space filter coefficient dumps + clipper tables for SD1, Tube Screamer-alikes, Big Muff variants, Plexi, SVT, Bottle Rocket, Guvnor, Supersonic etc. |
| `grame-cncm_faustlibraries` | grame-cncm/faustlibraries | Per-library: most are LGPL-2.1+ *with* the Faust "generated code exception"; `phaflangers/reverbs/vaeffects` are STK-4.3 (MIT-style); `tonestacks.lib` is copyright Guitarix but declared `LGPL-2.1-or-later`; `tubes.lib` copyright Guitarix, no license declare (assume guitarix GPL-2+); `wdmodels.lib` per-function `LicenseRef-STK-4.3` (Roosenburg) | LGPL-2.1+ w/ exception (mostly) | 71 (tests) / 56 libs | std (current master) | Reference implementations: `ve.klonCentaur` (WDF), `wd.*` WDF toolkit, `aa.*` ADAA anti-aliased clippers, `tu.*` tube tables, `ts.*` tone stacks, `re.springreverb`, `hy.ja_hysteresis` (tape), `co.limiter_1176_R4`, `pf.phaser2`, `ef.tapeStop`. |
| `grame-cncm_faust` | grame-cncm/faust | `COPYING.txt`: LGPL-2.1+ (compiler); examples are BSD/LGPL/STK per file `declare license` | LGPL-2.1+ | 737 (whole tree) | std | `examples/{reverb,delayEcho,dynamic,phasing,filtering,pitchShifting,misc}` -- ~40 guitar-relevant demo wrappers around the libraries above (incl. `springreverb.dsp`, `cryBaby.dsp`, `wahPedal.dsp`, `distortion.dsp`, `guitarix.dsp`). |
| `thedrgreenthumb_faust` | thedrgreenthumb/faust | `LICENSE`: MIT (c) 2014 | MIT | 22 | **OLD** (`effect.lib`, `music.lib`, `geometry.lib`, `rectangles.lib`) | Reverb/delay experiments: `shimmizita` (shimmer on zita), `duck_reverb`, `freeverb3` (Progenitor; author says unstable), `room_simulator` (Gardner), `rotary_speakers`, `parametric_pitch_shifter`, 9 "circles" delay variants (tape/analog emu, ping-pong, detune, flange, wah, ringmod). |
| `olilarkin_OL-OWLPatches` | olilarkin/OL-OWLPatches | no LICENSE file; README only. Treat as **unlicensed / all rights reserved** unless author confirms | none | 6 | std | `ThruZeroFlanger`, `WeirdPhaser` (SSB/Hilbert phaser), `DualPitchShifter`, `Stereo/DualFreqShifter` (IIR Hilbert), `Blipper`. |
| `jmiskovic_DSPedal` | jmiskovic/DSPedal | no LICENSE file (README only) | none | 2 | **OLD** (`library("filter.lib")` etc.) | Hardware project; `wah.dsp` = JOS crybaby, `looper.dsp`. Toy. |
| `pingdynasty_OwlPatches` | pingdynasty/OwlPatches | `LICENSE`: GPL-2.0 | GPL-2.0 | 27 | mixed: `Faust/` std; `Guitarix/` mostly **OLD** | `Faust/`: Crybaby, AutoWah, StereoWah, SweepWah, Echo, StereoEcho, SmoothDelay, FaustVerb (freeverb), PitchShifter, Qompander (Bart Brouns), shelf filters. `Guitarix/`: 2013-era ports of guitarix BMfp, Compressor, Distortion1, Dunwah, FlangerGX, Moog, OscTube, Overdrive, Phaser(+Mono), Tone + old `guitarix.lib`. |
| `RebelTechnology/OwlPatches` | -- | -- | -- | -- | -- | **Clone failed (404 / does not exist under that org).** pingdynasty is the canonical one. |
| `Barabas5532_TubeScreamer` | Barabas5532/TubeScreamer | `COPYING`: GPL-3.0 | GPL-3.0 | 1 | std | `tubescreamer.dsp` = 1st-order HPF 720 Hz -> `ef.cubicnl` -> 1-pole LPF 350-4500 Hz -> volume. **[TOY]** (JUCE wrapper is the interesting part). |
| `olegkapitonov_Kapitonov-Plugins-Pack` | olegkapitonov/Kapitonov-Plugins-Pack (KPP) -- found via search | `LICENSE.txt`: GPL-3.0 | GPL-3.0 | 13 (LV2 + LADSPA duplicates of 7 plugins) | std | `kpp_tubeamp` (profile-driven tube amp with tonestack, pre/power stage), `kpp_bluedream` (TS-style OD w/ "tube" waveshaper), `kpp_distruction` (hi-gain), `kpp_fuzz`, `kpp_octaver`, `kpp_deadgate`, `kpp_single2humbucker`. Hand-tuned piecewise waveshapers, not circuit sims. |
| `jatinchowdhury18_wdf-bakeoff` | jatinchowdhury18/wdf-bakeoff -- found via search | **no LICENSE file** at root (submodules not cloned) | none stated | 6 | std (`wd.` WDF lib) | The only Faust `.dsp` from Chowdhury: `src/faust_wdf/diode_clipper.dsp` (RC + antiparallel diode, Is=2.52e-9, Vt=25.85mV), `bassman.dsp` (Fender Bassman tone stack WDF), `baxandall.dsp`, `pultec.dsp`, `ff2.dsp`, `lpf2.dsp`. Other jatinchowdhury18 repos (AnalogTapeModel, KlonCentaur, ChowKick, BYOD) are C++ -- not cloned. |
| `magnetophon_faustCompressors` | magnetophon/faustCompressors (Bart Brouns) -- found via search | `LICENSE`: GPL-3.0 | GPL-3.0 | 10 | std (`compressors.lib` here is his older private copy, superseded by upstream `co.`) | FF / FB / FBFF / RMS compressors, `RMS_FBcompressor_peak_limiter`, `autoComp`, `drumDuxpander`. Origin of `co.FBFFcompressor_N_chan` etc. |
| `LucaSpanedda_Digital_Reverberation_in_Faust` | -- found via search | `LICENSE.md`: MIT | MIT | 1 (+`reverberation.lib`) | std | Teaching library: comb/allpass/FDN/Schroeder/Dattorro building blocks. No spring. |
| `electro-smith_DaisyExamples` | electro-smith/DaisyExamples | MIT | MIT | 0 | -- | Only `seed/DSP/faustnoise/` = pre-generated `faust.cpp` from a noise example. **No .dsp.** C++/DaisySP otherwise. |
| `bkshepherd_DaisySeedProjects` | bkshepherd/DaisySeedProjects | MIT | MIT | 0 | -- | **Pure C++** (DaisySP effect modules under `Software/GuitarPedal/Effect-Modules`). No Faust. |
| `clevelandmusicco_HothouseExamples` | clevelandmusicco/HothouseExamples | GPL-3.0 | GPL-3.0 | 0 | -- | **Pure C++/DaisySP** (BasicSpringReverb, TapeSimulator, EchoKing, TriChorus, GlowjobPhotonVibe...). README only *mentions* `faust2hothouse` and the Wampler Faust course; no `.dsp` in repo. |

Not found / skipped: `olilarkin/faust-examples` (404), `madskjeldgaard/faust-effects` (404),
`Barabas5532/shrapnel` (404 with depth-1 clone), `sadko4u/faust-plugins` (404),
`Rafael-Pauli` / `ArneRC` / `aleksandr-gorbachev` (no verifiable repo name; skipped),
`mod-audio/guitarix` mirror not needed (brummer10 clone succeeded). `moddevices/mod-pitchshifter`,
`brummer10/Ratatouille.lv2`, `brummer10/Fluida.lv2`, `dariosanfilippo/edgeofchaos` were cloned,
found to have 0 `.dsp`, and deleted. `agraef/lac16-faust-demo` cloned, is a synth tutorial, deleted.

---

## Guitarix layout (read this first)

`brummer10_guitarix/trunk/src/`

* `LV2/faust/` (226 dsp) -- the current set, used by the LV2 plugins. All `std`.
* `faust/` (170 dsp) -- older copies of mostly the same names (used by the standalone app); fewer pedals.
  Prefer `LV2/faust/` when both exist.
* `plugins/` (43 dsp) -- the "generated automatically / DO NOT MODIFY" pedal sims produced by the
  DK simulator plus a few hand-written (ts9sim, mxrdist, dunwah, flanger_gx, zita_rev1, multiband).
* `tools/ampsim/DK/` -- the Python DK-method circuit simulator (`dk_simulator.py`, `circ.py`,
  `models.py`, `trany_table_gen.py`, `diode_table_gen.py`) and **`gschem-schematics/*.sch`**: the
  actual schematics (BigMuffPi, FuzzfaceJH1, FuzzfaceRogerMayer, FuzzfaceFullerMods, Rangemaster,
  Hornet, Hogsfoot, Ruiner, Superfuzz, RolandFuzz, VintageFuzzMaster, VoxToneBlender,
  ColorsoundToneblender, LPB-1/2, Stratoblaster, ScreamingBird, MaestroBoomerang, FoxyLady, FatFreak,
  BlueClipper, Rocket, Supersonic, Sustainer, Vox/Jen/Fox/Dallas/Selmer/Roland/Colorsound wahs,
  TweedChamp, Princeton, PlexiPowerAmpEL34, jcm800_power, OrangeDarkTerror, W20, alembic1, studiopre,
  baxandall/tonestack, triode.sch + triode.spec). This is where the component values live.
* `LV2/faust/guitarix.lib` -- `valve` environment (Bendiksen triode from swh-plugins), `tubestage*`
  (table-interpolated triode stages with anti-alias step), `clip`, `softclip`, `anti_denormal`.
* `LV2/faust/trany.lib` -- `tranystage(TB_xxx, ...)` transistor stage tables (used by all fuzz sims).
* `LV2/faust/redeye.lib` -- Redeye Chump/BigChump preamp + power-amp state-space filters and
  12AX7/12AU7 input/output stage clippers (used by tube delay / tube tremolo / tape).
* Every circuit-sim file carries `declare samplerate "96000"` -> designed to run 2x oversampled.

---

## Catalog by effect type

Paths below are relative to `/home/claude/chameleon/ext/`. `GX` = `brummer10_guitarix/trunk/src`.

### 1. Overdrive / distortion / fuzz

| File | What | Flag | Gen |
|---|---|---|---|
| `GX/plugins/ts9sim.dsp` (+`ts9nonlin.cc/.h`) | Ibanez TS-9: bilinear clipping-stage filter from R1=4k7, R2=51k+500k pot, C=47n, nonlinearity via `ffunction ts9nonlin()` (Kenéz analysis, Newton solve in C++), tone LPF, level | [CIRCUIT][TABLE] needs C foreign fn | std |
| `GX/LV2/faust/scream.dsp`, `plugins/scream.dsp` | "Screaming Bird" treble booster (DK generated) | [CIRCUIT] | std |
| `GX/LV2/faust/bossds1.dsp` | Boss DS-1: input buffer, transistor boost, opamp clip, tone, all as `fi.iir` coefficient polynomials in fs and pot positions | [CIRCUIT] | std |
| `GX/LV2/faust/mxrdist.dsp` | MXR Distortion+ (hand-written, opamp gain + diode clip approx) | [ALGO] | std |
| `GX/LV2/faust/aclipper.dsp` | "Rat" (ProCo RAT) -- opamp + clipper | [ALGO] | std |
| `GX/LV2/faust/bmp.dsp`, `muff.dsp`, `bmfp.dsp` | Big Muff Pi: `bmp` = DK generated full circuit; `muff` = generated w/ `trany.lib` transistor stages; `bmfp` = older hand-written polynomial fuzz | bmp/muff [CIRCUIT][TABLE]; bmfp [TOY] | std |
| `GX/LV2/faust/bigmuff.dsp` | Big Muff *tone* section only (two filters mixed by pot) | [CIRCUIT-ish] | std |
| `GX/LV2/faust/fuzzface.dsp`, `fuzzfacefm.dsp`, `plugins/fuzzfacerm.dsp` | Fuzz Face (JH1), Fuller-mods, Roger Mayer variants: 5th-order state-space `fi.iir` whose coefficients are polynomials in Fuzz/Level pots, then 3x `tranystage` transistor tables | [CIRCUIT][TABLE] | std (fuzzfacerm still `filter.lib` -> OLD) |
| `GX/plugins/{astrofuzz,axface,bfuzz,buzz,foxeylady,fuzzdrive,ruin,rolandfuzz*}.dsp` | Astro-tone fuzz, Ax-Face, Baldwin-Burns Buzzaround, Foxey Lady, Fuzz-drive, Ruiner, Roland Bee Baa | [CIRCUIT][TABLE] | std |
| `GX/LV2/faust/cstb.dsp`, `plugins/cstb.dsp` | Colorsound Tone Bender | [CIRCUIT][TABLE] | std |
| `GX/LV2/faust/fumaster.dsp` | Vintage Fuzz Master | [CIRCUIT][TABLE] | std |
| `GX/LV2/faust/hornet.dsp`, `hogsfoot.dsp`, `rangem.dsp`, `mole.dsp`, `hfb.dsp`, `plugins/lpbboost.dsp`, `plugins/buffb.dsp`, `plugins/coverd.dsp`, `plugins/eldist.dsp`, `plugins/ffreak.dsp` | Hornet, Hogs Foot, Rangemaster (treble booster), Mole (bass booster), High-Freq Brightener, LPB-1 booster, transistor buffer, Colorsound Overdriver, Electra distortion, Fat Freak | [CIRCUIT] | std |
| `GX/LV2/faust/susta.dsp` | Sustainer / compressor-ish fuzz circuit | [CIRCUIT][TABLE] | std |
| `GX/LV2/faust/{overdrive,drive,distortion,distortion1,gxdistortion,gx_distortion,thick_distortion,softclip,clipper,hardlim}.dsp` | Guitarix's older generic drives: multi-band distortion with speaker-emu filters, `valve` triode overdrive, soft/hard clip | [ALGO] (some use `valve` table) | std |
| `GX/LV2/faust/mbd.dsp`, `plugins/mbclipper.dsp` | Multi-band distortion / clipper (kokoko3k) | [ALGO] | std |
| `GX/LV2/faust/gx_w20.dsp` | W20 (Wem/Watkins) preamp? DK-generated | [CIRCUIT] | std |
| `olegkapitonov_Kapitonov-Plugins-Pack/LV2/kpp_bluedream/kpp_bluedream.dsp` | TS-style overdrive: input HPF, pot-scaled gain, asymmetric "tube" waveshaper `tube(Kreg,Upor,bias,cut)` applied to +/- halves, tone | [ALGO] | std |
| `.../kpp_distruction/kpp_distruction.dsp` | Hi-gain distortion (same waveshaper family, more stages + EQ) | [ALGO] | std |
| `.../kpp_fuzz/kpp_fuzz.dsp` | Fuzz, hard-clip style | [ALGO] | std |
| `jatinchowdhury18_wdf-bakeoff/src/faust_wdf/diode_clipper.dsp` | Canonical RC + antiparallel-diode clipper as a `wd.buildtree` WDF (R=4k7, C=47n, Is=2.52nA, Vt=25.85mV) -- 10 lines, exact | [CIRCUIT] WDF | std |
| `grame-cncm_faustlibraries/vaeffects.lib` -> `ve.klonCentaur(gain,treble,level)` | Klon Centaur full WDF model (port of ChowCentaur), gain pot 2k-102k | [CIRCUIT] WDF | std |
| `grame-cncm_faustlibraries/aanl.lib` -> `aa.hardclip/tanh1/tanh2/arctan/softclipQuadratic1..2/cubic1/...` | ADAA (1st & 2nd order antiderivative anti-aliased) clippers -- the cheap way to get alias-free clipping without oversampling | [OS/AA] | std |
| `grame-cncm_faustlibraries/misceffects.lib` -> `ef.cubicnl`, `ef.softclipQuadratic`, `ef.wavefold` | Generic soft clippers | [TOY] | std |
| `grame-cncm_faust/examples/dynamic/distortion.dsp` | Demo of `ef.cubicnl` | [TOY] | std |
| `Barabas5532_TubeScreamer/tubescreamer.dsp` | HPF -> cubicnl -> LPF | [TOY] | std |
| `pingdynasty_OwlPatches/Guitarix/{GuitarixBMfp,GuitarixDistortion1,GuitarixOverdrive}.dsp` | 2013 OWL ports of guitarix drives | [TOY]/[ALGO] | OLD |

### 2. Tube / preamp / power-amp models

| File | What | Flag | Gen |
|---|---|---|---|
| `GX/LV2/faust/gxamp.dsp` .. `gxamp18.dsp` (+`_stereo`) | 18 amp topologies from `tubestage` tables: 12AX7, 12AU7, 12AT7, 6DJ8, 6V6, 6C16 preamps, "pre X / master 6V6", "push-pull 6V6", "X feedback". Each is `tubestage(tubetable, fck, Rk, Vk0)` chains with inter-stage LPFs | [TABLE][OS/AA] (`anti_aliase` step in `tubestageF`) | std |
| `GX/LV2/faust/guitarix.lib` + `grame-cncm_faustlibraries/tubes.lib` | The tube tables themselves (`tubetable_12AX7_rtable_0/1` etc.), `tubestage`, `T1_/T2_/T3_` per tube. `tubes.lib` is the upstream-packaged version | [TABLE] | std |
| `GX/LV2/faust/gxmetal_amp.dsp`, `gxmetal_head.dsp` | Hi-gain 4-stage 12AX7 head using `tubestageP` | [TABLE] | std |
| `GX/LV2/faust/gx_chump.dsp`, `gx_bigchump.dsp`, `gx_vibrochump.dsp`, `redeye.lib` | Redeye Chump / Big Chump small tube amps (DK state-space preamp + power stage w/ feedback + tremolo variant) | [CIRCUIT][TABLE] | std |
| `GX/LV2/faust/alembic-mono.dsp`, `gx_alembic.dsp`, `gx_studiopre.dsp` | Alembic F-2B (Fender-style) tube studio preamp | [CIRCUIT] | std |
| `GX/faust/{champ,princeton,epiphone,plexiel34,orangedarkterror,supersonic}.dsp` | Tweed Champ, Princeton, Epiphone Valve Jr output, Plexi EL34 power amp, Orange Dark Terror, Supersonic -- DK generated | [CIRCUIT][TABLE] | std |
| `GX/faust/{valve,valve_rect,tube,tube3,stage3,osc_tube,reso_tube,preamp,preampmono,preampstereo,amp2}.dsp` | Older generic triode stages (Bendiksen model) & rectifier sag (`valve_rect`) | [ALGO]/[TABLE] | std |
| `GX/tools/ampsim/{gxpreamp,gxpoweramp}.dsp`, `tools/tubestage.dsp` | Reference preamp/power amp test harnesses | [TABLE] | std |
| `grame-cncm_faust/examples/misc/guitarix.dsp` | Complete 3-stage 12AX7 amp + selectable tone stack using `tubes.lib`/`tonestacks.lib` -- the cleanest self-contained starting point | [TABLE] | std |
| `olegkapitonov_Kapitonov-Plugins-Pack/LV2/kpp_tubeamp/kpp_tubeamp.dsp` | Profile-driven amp: preamp waveshaper (bias/Upor/Kreg) -> tonestack (bass/mid/treble freq+band from profile) -> power amp with sag/feedback -> convolver cab (outside Faust). Parameters via `fvariable` from `.tapf` files | [ALGO] (measured-profile approach) | std |
| `brummer10_GxPlugins.lv2/*/dsp/*.cc` | Compiled-only: GxPlexi, GxSVT (Ampeg SVT p1..p5), GxBlueAmp, GxShakaTube, GxBoobTube, GxValveCaster, GxBaJaTubeDriver, GxTubeDistortion, GxVBassPreAmp, GxLiquidDrive, GxTimRay, GxSaturator, GxSuperFuzz, GxSuppaToneBender, GxSD1, GxSD2Lead, GxBottleRocket, GxGuvnor, GxHyperion, GxLuna, GxEpic, GxEternity, GxClubDrive, GxCreamMachine, GxKnightFuzz, GxSunFace, GxToneMachine (Foxx), GxFz1b/Fz1s (Maestro), GxQuack, GxUVox720k, GxSlowGear, GxSloopyBlue, GxDOP250, GxHeathkit, GxMicroAmp, GxUltraCab | [CIRCUIT] but **no .dsp** -- coefficients readable from C++ | -- |

### 3. Compressor / gate / expander

| File | What | Flag | Gen |
|---|---|---|---|
| `GX/LV2/faust/compressor.dsp` | Graef's compressor/limiter (RMS detector, ratio/knee/attack/release) | [ALGO] | std |
| `GX/LV2/faust/{expander,noisegate}.dsp` | Expander, gate | [ALGO] | std |
| `GX/LV2/faust/mbc.dsp`, `plugins/mbcs.dsp` | Multi-band compressor (kokoko3k) | [ALGO] | std |
| `GX/LV2/faust/susta.dsp` | Sustainer circuit sim (transistor compressor pedal) | [CIRCUIT] | std |
| `grame-cncm_faustlibraries/compressors.lib` | `co.compressor_mono/stereo`, `co.FFcompressor_N_chan`, `co.FBcompressor_N_chan`, `co.FBFFcompressor_N_chan`, `co.RMS_*`, `co.limiter_1176_R4_mono/stereo` (1176 ratio-4 emulation), `co.limiter_lad_*` (look-ahead), `co.expander_N_chan` | [ALGO] | std |
| `magnetophon_faustCompressors/*.dsp` | Source of the above (FF/FB/FBFF/RMS + peak limiter, autoComp) | [ALGO] | std |
| `grame-cncm_faust/examples/dynamic/{compressor,gateCompressor,noiseGate}.dsp` | Demos | [ALGO] | std |
| `olegkapitonov_.../kpp_deadgate.dsp` | Noise gate | [ALGO] | std |
| `pingdynasty_OwlPatches/Faust/Qompander.dsp` | Bart Brouns compander | [ALGO] | std |

### 4. Delay / echo / tape

| File | What | Flag | Gen |
|---|---|---|---|
| `GX/LV2/faust/gxechocat.dsp` (154 lines) | **Watkins Copicat / Selmer tape echo**: 4 playback heads at real inch spacings & ips -> ms, record-head pentode driver, 2-stage valve amp via `redeye.lib` 12AX7 stages, staggered tape band-limit filters, saturation. Best tape-echo reference here | [CIRCUIT-informed][TABLE] | std |
| `GX/LV2/faust/tapesim.dsp`, `gxtape.dsp`, `gxtape_st.dsp` | Tape machine sim: wow (0-4 Hz) & flutter (4-60 Hz) modulated `de.sdelay`, tape saturation, freq response | [ALGO] | std |
| `GX/LV2/faust/gxtubedelay.dsp` | 2.5 s delay with 12AX7 input/output stages (redeye) | [TABLE] | std |
| `GX/LV2/faust/{delay,echo,stereodelay,stereoecho,digital_delay(_st),duck_delay(_st),mbdel,mbe}.dsp` | Plain / stereo / ducking / multi-band delays | [ALGO] | std |
| `grame-cncm_faustlibraries/misceffects.lib` -> `ef.echo`, `ef.reverseEchoN`, `ef.reverseDelayRamped`, `ef.tapeStop` | Library echoes; `tapeStop` = tape-stop pitch-drop | [ALGO] | std |
| `grame-cncm_faustlibraries/hysteresis.lib` -> `hy.ja_hysteresis`, `hy.ja_processor` | Jiles-Atherton tape magnetic hysteresis (port of CHOW Tape) -- the serious tape *saturation* model | [CIRCUIT-grade physics] | std |
| `grame-cncm_faustlibraries/delays.lib` | `de.fdelay*` (Lagrange/Thiran fractional), `de.sdelay` (click-free), `de.multiTapSincDelay` | [ALGO] | std |
| `grame-cncm_faust/examples/delayEcho/{echo,stereoEcho,quadEcho,smoothDelay,tapiir}.dsp` | Demos (echo/stereoEcho flagged "legacy example") | [ALGO] | std |
| `thedrgreenthumb_faust/circles/delay_{emu,colored,pingpong,detune,duck,flange,ps,ringmod,wah}.dsp` | 9 stereo delay variants; `delay_emu` has analog/digital (BBD-ish darkening) emulation | [ALGO] | OLD |
| `thedrgreenthumb_faust/rects/{del_01,del_02,ech_01}.dsp` | More delay/echo experiments | [ALGO] | OLD |
| `pingdynasty_OwlPatches/Faust/{Echo,StereoEcho,SmoothDelay}.dsp` | Grame demos as OWL patches | [TOY] | std |

No true BBD (bucket-brigade, clock-noise/compander) model was found in any Faust source.

### 5. Reverb (spring / plate / algorithmic)

| File | What | Flag | Gen |
|---|---|---|---|
| `grame-cncm_faustlibraries/reverbs.lib` -> `re.springreverb(dwell,blend,tone,tension,springs)` + `grame-cncm_faust/examples/reverb/springreverb.dsp` | Spring-*inspired* reverb (Chaos Audio Stratus): diffusion -> bank of damped delay lines with Hadamard feedback. Not a physical spring (no dispersive allpass chirp) | [ALGO] | std |
| `reverbs.lib` -> `re.dattorro_rev`, `re.zita_rev1_stereo`, `re.zita_rev_fdn`, `re.fdnrev0`, `re.jpverb`, `re.greyhole`, `re.vital_rev`, `re.kb_rom_rev1`, `re.jcrev`, `re.satrev`, `re.mono/stereo_freeverb` | Dattorro plate, Zita FDN, JPverb, Greyhole, Vital's reverb, Freeverb, Schroeder | [ALGO] | std |
| `grame-cncm_faust/examples/reverb/*.dsp` (13) | Demos of each incl. `reverbDesigner.dsp`, `reverbTank.dsp` | [ALGO] | std |
| `GX/LV2/faust/{freeverb,stereoverb,gx_zita_rev1,room_simulator,shimmizita,mbreverb,dattorros_progenitor(faust/)}.dsp` | Freeverb, Zita (modified defaults), Gardner room sim, shimmer-on-zita, Progenitor | [ALGO] | std |
| `thedrgreenthumb_faust/{shimmizita,shimmer,duck_reverb,freeverb3,room_simulator,rects/rev_01}.dsp` | Origin of guitarix shimmizita/room_simulator; `shimmer.dsp` modelled on ValhallaShimmer; `freeverb3` = Progenitor port (author: unstable) | [ALGO] | OLD |
| `LucaSpanedda_Digital_Reverberation_in_Faust/src/reverberation.lib` | Reverb primitives (teaching) | [ALGO] | std |
| `pingdynasty_OwlPatches/Faust/FaustVerb.dsp` | freeverb | [TOY] | old-ish (no import; primitives) |

No dispersive spring model (Parker / Välimäki-style allpass chain with chirp) exists in these sources;
`re.springreverb` is the only spring-flavoured one.

### 6. Chorus / flanger / phaser / vibe

| File | What | Flag | Gen |
|---|---|---|---|
| `GX/LV2/faust/chorus.dsp`, `chorus_mono.dsp` | Graef stereo chorus: table-LFO, `de.sdelay(1<<16)`, per-channel phase offset | [ALGO] | std |
| `GX/plugins/mbchor.dsp` | Multi-band chorus | [ALGO] | std |
| `GX/LV2/faust/flanger.dsp`, `flanger_mono.dsp`, `gx_flanger.dsp`/`plugins/flanger_gx.dsp` | `pf.flanger_stereo` wrapper; `gx_flanger` = hand-written with feedback & width in ms | [ALGO] | std |
| `GX/LV2/faust/phaser.dsp`, `phaser_mono.dsp` | JOS `phaser2` (2nd-order allpass sections, notch spread) copied from effect.lib | [ALGO] | std |
| `GX/LV2/faust/gxtubevibrato.dsp`, `tubevibrato.dsp`, `faust/vibe_*.dsp` | Tube vibrato (12AX7 stage + delay-mod), Uni-Vibe-ish LFO sine/triangle variants (`vibe_lfo_*`, `uniBar.dsp`) | [TABLE]/[ALGO] | std |
| `grame-cncm_faustlibraries/phaflangers.lib` | `pf.flanger_mono/stereo`, `pf.phaser2_mono/stereo`, `pf.vibrato2_mono` | [ALGO] | std |
| `grame-cncm_faust/examples/phasing/{flanger,phaser,phaserFlangerLab}.dsp` | Demos | [ALGO] | std |
| `olilarkin_OL-OWLPatches/ThruZeroFlanger.dsp` | Through-zero flanger (delayed dry path, can null) | [ALGO] | std |
| `olilarkin_OL-OWLPatches/WeirdPhaser.dsp` + `IIRHilbert.lib` | SSB-modulation "phaser" (Favreau/Puckette IIR Hilbert) | [ALGO] | std |
| `thedrgreenthumb_faust/rotary_speakers.dsp` | Leslie / rotary (Zölzer DAFX) | [ALGO] | OLD |
| `thedrgreenthumb_faust/rects/{flt_01,mod_01}.dsp` | phaser/mod experiments | [ALGO] | OLD |
| `pingdynasty_OwlPatches/Guitarix/{GuitarixPhaser,GuitarixPhaserMono,GuitarixFlangerGX}.dsp` | Old ports | [ALGO] | OLD |

No BBD chorus model found.

### 7. Tremolo / vibrato

| File | What | Flag | Gen |
|---|---|---|---|
| `GX/LV2/faust/tremolo.dsp` | **Vactrol/LDR opto tremolo** (transmogrifox model): CdS cell RC dynamics `cds`, `vactrol = pow(1.9) : cds : ...: R1/(R+R1)` with R1=2k7, Ra=1M, Rb=300, plus hysteretic triangle LFO | [CIRCUIT] | std |
| `GX/LV2/faust/gxtubetremelo.dsp` | Tube (bias-wiggle) tremolo through 12AX7 stages | [TABLE] | std |
| `GX/LV2/faust/switched_tremolo.dsp` | Line-6 POD style switched/square tremolo | [ALGO] | std |
| `GX/LV2/faust/gx_vibrochump.dsp` | Vibro Chump amp w/ tremolo | [CIRCUIT][TABLE] | std |
| `GX/LV2/faust/{gxtubevibrato,tubevibrato}.dsp`, `pf.vibrato2_mono` | Pitch vibrato | [ALGO] | std |
| `grame-cncm_faust/examples/misc/autopan.dsp` | Auto-pan | [TOY] | std |

### 8. Wah / filter / envelope filter

| File | What | Flag | Gen |
|---|---|---|---|
| `GX/LV2/faust/gcb_95.dsp` (generated by `scripts/build_GCB_95.py`) | **Dunlop GCB-95 Cry Baby** full circuit (inductor + transistor stages) | [CIRCUIT] | std |
| `GX/LV2/faust/{voxwah,jenwah,foxwah,dallaswah,colwah,colbwah,maestrowah,selwah,rolwah/rolandwah}.dsp` | Vox V847, Jen, Foxx, Dallas (Rangemaster-era), Colorsound, Colorsound bass, Maestro Boomerang, Selmer, Roland wahs -- all DK generated from the `.sch` files | [CIRCUIT] | std |
| `GX/plugins/dunwah.dsp` | Dunlop wah, coefficients from `dunwah1.py` fit | [CIRCUIT-fit] | std |
| `GX/LV2/faust/crybaby.dsp`, `autowah.dsp`, `plugins/fuzzwah.dsp` | JOS crybaby biquad fit (`ve.crybaby`), envelope-follower auto-wah, fuzz+wah combo | [ALGO] | std |
| `GX/LV2/faust/moog.dsp` | Moog ladder (`ve.moog_vcf`) | [ALGO] | std |
| `grame-cncm_faustlibraries/vaeffects.lib` | `ve.crybaby`, `ve.autowah`, `ve.wah4`, `ve.moogLadder`, `ve.diodeLadder`, `ve.korg35*`, `ve.oberheim*`, `ve.sallenKey*` (Pirkle VA filters), matched-Z biquads | [ALGO] (virtual-analog, no circuit values) | std |
| `grame-cncm_faust/examples/filtering/{cryBaby,wahPedal,vcfWahLab,moogVCF,moogLadder,diodeLadder,...}.dsp` | Demos | [ALGO] | std |
| `pingdynasty_OwlPatches/Faust/{Crybaby,AutoWah,StereoWah,SweepWah}.dsp`, `jmiskovic_DSPedal/faust_dsp/wah.dsp`, `pingdynasty_OwlPatches/Guitarix/GuitarixDunwah.dsp` | JOS crybaby variants | [TOY] | std / OLD |
| `GX/LV2/faust/{eq,graphiceq,selecteq,peak_eq,multifilter,low_high_pass,low_high_cut,biquad,HighShelf,gxtilttone}.dsp` | EQs, tilt tone | [ALGO] | std |

### 9. Pitch / octave / shift

| File | What | Flag | Gen |
|---|---|---|---|
| `GX/LV2/faust/oc_2.dsp` + `tools/plugins/oc_2/oc_2.lib` | **Boss OC-2** partial emulation (flip-flop divider style, data from `oc_2.py`) | [CIRCUIT-partial] | std |
| `olegkapitonov_.../kpp_octaver.dsp` | Analog-style octaver (extract fundamental, rectify/divide) | [ALGO] | std |
| `grame-cncm_faustlibraries/misceffects.lib` -> `ef.transpose`, `ef.transpose_windowed`, `ef.granular`, `ef.doppler_shift` | Delay-line pitch shifters | [ALGO] | std |
| `grame-cncm_faust/examples/pitchShifting/pitchShifter.dsp`, `pingdynasty_OwlPatches/Faust/PitchShifter.dsp`, `olilarkin_OL-OWLPatches/DualPitchShifter.dsp` | Same Grame shifter | [ALGO] | std |
| `olilarkin_OL-OWLPatches/{StereoFreqShifter,DualFreqShifter}.dsp` + `FrequencyShifter.lib` | Bode/SSB frequency shifter via IIR Hilbert | [ALGO] | std |
| `thedrgreenthumb_faust/parametric_pitch_shifter.dsp` | Envelope/LFO-modulated pitch shifter | [ALGO] | OLD |
| `GX/LV2/faust/{ring_modulator,ring_modulator_st}.dsp` (in `faust/`) | Ring mod | [TOY] | std |

### 10. Tone stacks / cab sims / speaker

| File | What | Flag | Gen |
|---|---|---|---|
| `GX/LV2/faust/tonestack.dsp` + `tonestack_{ac15,ac30,ampeg,ampeg_rev,bassman,bm,bogner,crunch,default,engl,fender_blues,fender_default,fender_deville,gibsen,groove,ibanez,jcm2000,jcm800,jtm45,m2199,mesa,mlead,peavey,princeton,roland,soldano,sovtek,twin}.dsp` (+`_stereo`) | 27 passive tone-stack models: symbolic 3rd-order transfer function in R/C component values (bilinear), comment says use double precision | [CIRCUIT] | std |
| `grame-cncm_faustlibraries/tonestacks.lib` | Same 27 packaged as `ts.bassman(t,m,l)` etc. | [CIRCUIT] | std |
| `GX/faust/baxandall.dsp`, `jatinchowdhury18_wdf-bakeoff/src/faust_wdf/{bassman,baxandall,pultec}.dsp` | Baxandall active tone (DK) / WDF Bassman & Baxandall & Pultec EQ | [CIRCUIT] WDF | std |
| `GX/LV2/faust/{cabinet_impulse_former,preamp_impulse_former,impulseresponse}.dsp`, `faust/jconv_post*.dsp` | Cabinet "impulse former" = parametric multi-band EQ shaped to IRs; jconv post filters. Guitarix real cabs are convolution (`trunk/IR/`), outside Faust | [ALGO] | std |
| `grame-cncm_faustlibraries/misceffects.lib` -> `ef.speakerbp` | Bandpass speaker sim | [TOY] | std |
| `GX/LV2/faust/{presence_level,bassbooster,highbooster,bass_enhancer,tone,tonecontroll,gx_ampmodul,gx_ampout,AntiAlias,dcblocker,fizz_remover}.dsp` | Amp-block utilities: presence, boosters, 3-band tone, post-amp, anti-alias LPF, fizz remover | [ALGO] | std |
| `olegkapitonov_.../kpp_single2humbucker.dsp` | Pickup EQ (single-coil -> humbucker) | [ALGO] | std |

---

## Most sonically serious (short list to actually study)

1. **Guitarix DK-generated pedal sims** (`GX/LV2/faust/*.dsp` with "generated automatically" header
   + `tools/ampsim/DK/gschem-schematics/*.sch`): bossds1, bmp/muff, fuzzface(fm/rm), cstb,
   fumaster, hornet, hogsfoot, rangem, gcb_95, voxwah/jenwah/foxwah/dallaswah/colwah,
   scream, mole, hfb, susta, w20, plus `plugins/` extras. True state-space circuit solutions with
   pot-dependent coefficient polynomials and transistor/diode lookup tables; expect 96 kHz.
2. **`ts9sim.dsp`** (TS-9 with Newton-solved diode clipper in C) and **`tremolo.dsp`** (vactrol).
3. **Tube library** (`tubes.lib` / `guitarix.lib` `tubestage`) + `gxamp*.dsp` + `examples/misc/guitarix.dsp`
   + `redeye.lib` (Chump).
4. **Tone stacks** (`tonestacks.lib` / `tonestack_*.dsp`): exact component-value transfer functions.
5. **WDF**: `ve.klonCentaur`, `wd.*` (`wdmodels.lib`, 3330 lines), `wdf-bakeoff/src/faust_wdf/diode_clipper.dsp`.
6. **`aanl.lib`** ADAA clippers -- the modern alias-free clipper toolkit.
7. **`hysteresis.lib`** (tape J-A model), **`gxechocat.dsp`** (Copicat multi-head), `tapesim.dsp` (wow/flutter).
8. `re.springreverb`, `re.dattorro_rev`, `re.zita_rev1_stereo`, `co.limiter_1176_R4_*`.

Toy / reference-only: Barabas5532 TubeScreamer, DSPedal wah, OWL Faust demos, guitarix `bmfp`,
`overdrive`, `softclip`, `ef.cubicnl`-based anything, KPP (decent hand-tuned but not modelled).

## Library-version / porting notes

* All of guitarix `LV2/faust`, `faust`, `plugins` are `stdfaust.lib` **except** `plugins/fuzzfacerm.dsp`
  (`import("filter.lib")`). They also need `guitarix.lib`, `trany.lib`, `redeye.lib` from the same
  dir (`-I trunk/src/LV2/faust`), `ts9sim` needs `ts9nonlin.h/.cc` (foreign function), `oc_2` needs
  `oc_2.lib` + `oc_2.include`, `shimmizita.dsp` needs `shimmizita.inc`, `gxtape*.dsp` uses
  `component("tapesim.dsp")`. `HighShelf.dsp` uses `maxmsp.lib` (still exists upstream).
* Guitarix circuit sims declare `samplerate "96000"`; the tube stages have an internal
  `anti_aliase` LPF. Running them at 48k without oversampling will alias.
* `thedrgreenthumb_faust` (all), `jmiskovic_DSPedal`, `pingdynasty_OwlPatches/Guitarix/*` are OLD
  (`effect.lib`/`music.lib`/`filter.lib`/`math.lib`/`oscillator.lib`). Compile with
  `-I grame-cncm_faustlibraries/old` or rewrite to `ef./fi./ma./os.` prefixes; `SR`->`ma.SR`,
  `PI`->`ma.PI`, `smooth`->`si.smooth`, `fdelay`->`de.fdelay`, `zita_rev1_stereo`->`re.`.
* `magnetophon_faustCompressors` imports its own `compressors.lib` (older API than upstream `co.`);
  prefer upstream.
* `grame-cncm_faustlibraries` is master as of clone date (`misceffects` 2.6.0, `reverbs` 1.5.1,
  `compressors` 1.6.0, `vaeffects` 1.6.0, `wdmodels` 1.4.0, `aanl` 1.5.0, `tonestacks` 1.28.0,
  `tubes` 1.1.0, `hysteresis` 1.0.1, `phaflangers` 1.1.0, `delays` 1.2.0). `ve.klonCentaur`,
  `re.springreverb`, `hy.*` are recent additions -- they need a Faust >= 2.79-ish compiler.

## License summary for reuse

* GPL-2.0+ : guitarix (and everything derived: `tubes.lib` carries "copyright Guitarix project" with no license declare -- assume GPL;
  `tonestacks.lib` is explicitly relicensed LGPL-2.1-or-later), pingdynasty OwlPatches.
* GPL-3.0 : GxPlugins.lv2, KPP, Barabas5532 TubeScreamer, magnetophon faustCompressors, HothouseExamples.
* LGPL-2.1+ with generated-code exception : Faust compiler + most `faustlibraries` (`misceffects`,
  `compressors`, `delays`, `aanl`, `hysteresis`, `filters`, `basics`...). STK-4.3 (MIT-like): `reverbs`,
  `phaflangers`, `vaeffects` (`ve.klonCentaur` itself declares `copyright "Chowdhury-DSP"`, `license "BSD-3-Clause"`).
  `wdmodels` functions declare `LicenseRef-STK-4.3`.
* MIT : thedrgreenthumb, LucaSpanedda, DaisyExamples, DaisySeedProjects.
* No license file : olilarkin OL-OWLPatches, jmiskovic DSPedal, jatinchowdhury18 wdf-bakeoff (treat as
  all-rights-reserved; study only).
