/**
 * Chameleon Studio - Effect Catalog
 * GENERATED FILE — do not edit by hand.
 * Source of truth: dsp/*.dsp (Faust) + dsp/catalog.json (UI metadata overrides).
 * Regenerate with:  node tools/build-catalog.mjs
 * Built 2026-09-05T00:53:36.099Z with Faust 2.87.11 — 269 effects
 */
const EFFECTS_CATALOG = [
 {
  "id": "tape-delay",
  "name": "Tape Delay",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Warm analog tape echo with flutter and high-frequency roll-off.",
  "description": "Tape echo model: wow and flutter on the delay time, saturated repeats, and a dark, band-limited feedback path. Past ~85% the Feedback knob pushes the loop into self-oscillation like a real tape echo.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Time",
    "min": 20,
    "max": 1200,
    "default": 420,
    "step": 1,
    "unit": "ms",
    "path": "/TapeDelay/Time"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/TapeDelay/Feedback"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.45,
    "step": 0.01,
    "unit": "",
    "path": "/TapeDelay/Mix"
   }
  ],
  "faustCode": "declare name \"TapeDelay\";\ndeclare description \"Tape echo: wow/flutter, saturated repeats, dark feedback path\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\ntime = hslider(\"Time[unit:ms]\", 420, 20, 1200, 1) * 0.001 : si.smooth(ba.tau2pole(0.12));\nfb   = hslider(\"Feedback\", 0.5, 0, 1.0, 0.01) : si.smoo;\nmix  = hslider(\"Mix\", 0.45, 0, 1.0, 0.01) : si.smoo;\n\nMAXDEL = 65536;\n// slow wow + fast flutter, as a fraction of the delay time\nwow   = os.osc(0.55) * 0.0025 + os.osc(6.3) * 0.0004;\ndt    = time * (1 + wow) * ma.SR : min(MAXDEL - 4);\n\n// tape head + electronics colouration in the repeat path\nhead  = fi.lowpass(1, 3400) : fi.highpass(1, 110);\nsat(x) = ma.tanh(x * 1.4) / 1.4;\n\n// >~87% on the knob pushes the loop into (tanh-bounded) self-oscillation, like a real tape echo\necho  = (+ : sat : de.fdelay(MAXDEL, dt)) ~ (head : *(fb * 1.15));\nprocess = _ <: *(1 - mix), (echo : *(mix)) :> _;"
 },
 {
  "id": "dattorro-plate",
  "name": "Dattorro Plate Reverb",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Rich spatial diffusion based on the legendary Dattorro plate topology.",
  "description": "True Dattorro plate topology: input diffusion allpasses feeding a figure-eight tank of cross-coupled delay lines with damping. Decay runs from a tight 0.2 s slap to a 25 s wash.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Decay",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/DattorroPlate/Decay"
   },
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.65,
    "step": 0.01,
    "unit": "",
    "path": "/DattorroPlate/Tone"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/DattorroPlate/Mix"
   }
  ],
  "faustCode": "declare name \"DattorroPlate\";\ndeclare description \"Dattorro figure-eight plate reverb (true Dattorro tank topology)\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\ndecay = hslider(\"Decay\", 0.6, 0, 1.0, 0.01) : si.smoo;\ntone  = hslider(\"Tone\", 0.65, 0, 1.0, 0.01) : si.smoo;\nmix   = hslider(\"Mix\", 0.4, 0, 1.0, 0.01) : si.smoo;\n\n// map knobs to Dattorro coefficients\ndec   = 0.5 + decay * 0.48;         // 0.5 .. 0.98 tank feedback\ndamp  = 0.02 + (1 - tone) * 0.85;   // higher = darker tail\nbw    = 0.4 + tone * 0.59;          // input bandwidth\n\nplate = re.dattorro_rev(480, bw, 0.75, 0.625, dec, 0.7, 0.5, damp);\nwet   = fi.highpass(1, 90) <: plate :> *(0.5);\nprocess = _ <: *(1 - mix), (wet : *(mix)) :> _;"
 },
 {
  "id": "bbd-chorus",
  "name": "BBD Stereo Chorus",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Lush bucket-brigade analog chorus and pitch vibrato.",
  "description": "Recreates the warm, dimensional swirl of dual bucket-brigade delay lines with anti-phase sinusoidal LFO modulation.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Speed",
    "min": 0.1,
    "max": 8,
    "default": 1.2,
    "step": 0.05,
    "unit": "Hz",
    "path": "/BBDChorus/Speed"
   },
   {
    "label": "Depth",
    "min": 0,
    "max": 1,
    "default": 0.65,
    "step": 0.01,
    "unit": "",
    "path": "/BBDChorus/Depth"
   },
   {
    "label": "Blend",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/BBDChorus/Blend"
   }
  ],
  "faustCode": "declare name \"BBDChorus\";\ndeclare description \"Two-voice bucket-brigade chorus with band-limited delay lines\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nrate  = hslider(\"Speed[unit:Hz]\", 1.2, 0.1, 8.0, 0.05) : si.smoo;\ndepth = hslider(\"Depth\", 0.65, 0, 1.0, 0.01) : si.smoo;\nblend = hslider(\"Blend\", 0.5, 0, 1.0, 0.01) : si.smoo;\n\nMAXDEL = 2048;\nlfo1 = os.osc(rate);\nlfo2 = os.oscp(rate * 0.93, ma.PI * 0.5);\nd1 = (0.0065 + depth * 0.0030 * lfo1) * ma.SR;\nd2 = (0.0090 + depth * 0.0028 * lfo2) * ma.SR;\n\n// BBD clock filtering: anti-alias/reconstruction lowpass + slight companding grit\nbbd = fi.lowpass(2, 7500);\nvoice(d, x) = de.fdelay(MAXDEL, d, x) : bbd;\nwet(x) = (voice(d1, x) + voice(d2, x)) * 0.55;\n\nprocess(x) = x * (1 - blend * 0.5) + wet(x) * blend;"
 },
 {
  "id": "harmonic-tremolo",
  "name": "Harmonic Tremolo",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Vintage brownface dual-band phase-split tremolo.",
  "description": "Splits the signal into high-pass and low-pass crossover bands, modulating them 180 degrees out of phase for a hypnotic, Doppler-like pulse.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Rate",
    "min": 0.5,
    "max": 12,
    "default": 4,
    "step": 0.1,
    "unit": "Hz",
    "path": "/HarmonicTremolo/Rate"
   },
   {
    "label": "Depth",
    "min": 0,
    "max": 1,
    "default": 0.75,
    "step": 0.01,
    "unit": "",
    "path": "/HarmonicTremolo/Depth"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/HarmonicTremolo/Level"
   }
  ],
  "faustCode": "declare name \"HarmonicTremolo\";\ndeclare description \"Brownface harmonic tremolo: LR crossover, bands modulated in anti-phase\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nrate  = hslider(\"Rate[unit:Hz]\", 4.0, 0.5, 12.0, 0.1) : si.smoo;\ndepth = hslider(\"Depth\", 0.75, 0, 1.0, 0.01) : si.smoo;\nlevel = hslider(\"Level\", 0.7, 0, 1.0, 0.01) : si.smoo;\n\nxover = 650;\nlo = fi.lowpass(2, xover) : fi.lowpass(2, xover);    // Linkwitz-Riley 4\nhi = fi.highpass(2, xover) : fi.highpass(2, xover);\n\n// slightly rounded, tube-bias style LFO\nlfo    = os.osc(rate) : *(1.25) : ma.tanh : /(0.848);\ng_lo   = 1 - depth * 0.5 * (1 + lfo);\ng_hi   = 1 - depth * 0.5 * (1 - lfo);\ngain   = 0.5 + level * 1.0;\n\nprocess(x) = (lo(x) * g_lo + hi(x) * g_hi) * gain;"
 },
 {
  "id": "dynamic-overdrive",
  "name": "Dynamic Overdrive",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Asymmetric soft-clipping tube-style drive with pick dynamics.",
  "description": "Touch-sensitive tube saturation utilizing polynomial hyperbolic tangent waveshaping, pre-emphasis mid-boost, and post-drive cabinet smoothing.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Gain",
    "min": 1,
    "max": 50,
    "default": 18,
    "step": 0.5,
    "unit": "dB",
    "path": "/DynamicOverdrive/Gain"
   },
   {
    "label": "Tone",
    "min": 500,
    "max": 6000,
    "default": 2800,
    "step": 50,
    "unit": "Hz",
    "path": "/DynamicOverdrive/Tone"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/DynamicOverdrive/Level"
   }
  ],
  "faustCode": "declare name \"DynamicOverdrive\";\ndeclare description \"Asymmetric tube-style overdrive with pre-emphasis and post tone\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\ngain  = hslider(\"Gain[unit:dB]\", 18, 1, 50, 0.5) : si.smoo : ba.db2linear;\ntone  = hslider(\"Tone[unit:Hz]\", 2800, 500, 6000, 50) : si.smoo;\nlevel = hslider(\"Level\", 0.6, 0, 1.0, 0.01) : si.smoo;\n\n// input conditioning: cut mud, tube-screamer style mid hump before the clipper\npre   = fi.highpass(1, 90) : fi.peak_eq(5, 750, 900);\n\n// asymmetric soft clip: positive half saturates later than negative half\nclip(x) = select2(x > 0, ma.tanh(x * 1.5) / 1.5, ma.tanh(x));\n\n// keep loudness roughly steady as gain climbs\ncomp  = 2.0 / pow(gain, 0.5) : min(1.3);\npost  = fi.dcblocker : fi.lowpass(2, tone) : fi.highpass(1, 60);\n\nprocess = pre : *(gain) : clip : post : *(comp * level);"
 },
 {
  "id": "klon-centaur",
  "name": "Klon Centaur",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "BSD-3-Clause",
  "shortDesc": "Full circuit model of the Klon Centaur: transparent, touch-sensitive overdrive.",
  "description": "Wave-digital-filter model of the real Centaur circuit (gain pot, germanium diode clipper, tone network) from the Faust standard library (ve.klonCentaur, Jatin Chowdhury's ChowCentaur port) — BSD licensed, so it ships cleanly. Chameleon only wraps it with three knobs.",
  "author": "Chameleon DSP (wrapper) / Jatin Chowdhury (model)",
  "flags": "",
  "params": [
   {
    "label": "Gain",
    "min": 0,
    "max": 1,
    "default": 0.55,
    "step": 0.01,
    "unit": "",
    "path": "/KlonCentaur/Gain"
   },
   {
    "label": "Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/KlonCentaur/Treble"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/KlonCentaur/Level"
   }
  ],
  "faustCode": "declare name \"KlonCentaur\";\ndeclare description \"Klon Centaur overdrive: full wave-digital-filter circuit model (ve.klonCentaur, port of ChowCentaur)\";\ndeclare author \"Chameleon DSP (wrapper) / Jatin Chowdhury (model)\";\ndeclare license \"BSD-3-Clause\";\nimport(\"stdfaust.lib\");\n\ngain   = hslider(\"Gain\", 0.55, 0, 1.0, 0.01) : si.smoo;\ntreble = hslider(\"Treble\", 0.5, 0, 1.0, 0.01) : si.smoo;\nlevel  = hslider(\"Level\", 0.7, 0, 1.0, 0.01) : si.smoo;\n\n// The model expects a guitar-level signal (~0.1-0.5 peak) and runs the real\n// gain-pot / diode-clipper / tone network as a WDF tree.\nprocess = ve.klonCentaur(gain, treble, level);"
 },
 {
  "id": "infinite-compressor",
  "name": "Infinite Sustain Compressor",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "High-ratio leveling amplifier for endless singing sustain.",
  "description": "Squashes harsh picking spikes and continuously ramps up automatic makeup gain as notes fade, holding guitar sustain flat for 15+ seconds.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Sustain",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/InfiniteSustainCompressor/Sustain"
   },
   {
    "label": "Attack",
    "min": 1,
    "max": 50,
    "default": 15,
    "step": 1,
    "unit": "ms",
    "path": "/InfiniteSustainCompressor/Attack"
   },
   {
    "label": "Blend",
    "min": 0,
    "max": 1,
    "default": 0.85,
    "step": 0.01,
    "unit": "",
    "path": "/InfiniteSustainCompressor/Blend"
   }
  ],
  "faustCode": "declare name \"InfiniteSustainCompressor\";\ndeclare description \"High-ratio sustainer with automatic make-up gain and soft ceiling\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nsustain = hslider(\"Sustain\", 0.7, 0, 1.0, 0.01) : si.smoo;\natt     = hslider(\"Attack[unit:ms]\", 15, 1, 50, 1) * 0.001;\nblend   = hslider(\"Blend\", 0.85, 0, 1.0, 0.01) : si.smoo;\n\nratio   = 4 + sustain * 12;\nthresh  = -12 - sustain * 36;         // dB\nrel     = 0.25 + sustain * 0.45;      // longer release = more sustain\nmakeup  = -thresh * (1 - 1/ratio) * 0.8 : ba.db2linear;\n\ncomp(x) = co.compressor_mono(ratio, thresh, att, rel, x) * makeup;\nceiling(x) = ma.tanh(x);\n\nprocess(x) = x * (1 - blend) + (comp(x) : ceiling) * blend;"
 },
 {
  "id": "multi-phaser",
  "name": "Multi-Stage Phaser",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Cascaded all-pass phase shifter with feedback.",
  "description": "Generates shifting spectral notches across 4 to 8 allpass filter stages. Moves smoothly from vintage Phase 90 sweeps to chewy, resonant vortexes.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Rate",
    "min": 0.1,
    "max": 8,
    "default": 1.5,
    "step": 0.05,
    "unit": "Hz",
    "path": "/MultiStagePhaser/Rate"
   },
   {
    "label": "Depth",
    "min": 0,
    "max": 1,
    "default": 0.75,
    "step": 0.01,
    "unit": "",
    "path": "/MultiStagePhaser/Depth"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.9,
    "default": 0.55,
    "step": 0.01,
    "unit": "",
    "path": "/MultiStagePhaser/Feedback"
   }
  ],
  "faustCode": "declare name \"MultiStagePhaser\";\ndeclare description \"Six-notch all-pass phaser with resonant feedback (Phase 90 to Small Stone)\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nrate  = hslider(\"Rate[unit:Hz]\", 1.5, 0.1, 8.0, 0.05) : si.smoo;\ndepth = hslider(\"Depth\", 0.75, 0, 1.0, 0.01) : si.smoo;\nfb    = hslider(\"Feedback\", 0.55, 0, 0.9, 0.01) : si.smoo;\n\n// phaser2_mono(Notches, phase01, width, frqmin, fratio, frqmax, speed, depth, fb, invert)\nprocess = pf.phaser2_mono(3, 0, 1000, 120, 1.5, 3200, rate, depth, fb, 0) : ma.tanh;"
 },
 {
  "id": "silicon-fuzz",
  "name": "Silicon Fuzz & Wavefolder",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Hard-clipping gated fuzz with wavefolding bite.",
  "description": "High-gain silicon fuzz with a bias control that shifts the clipping symmetry (even harmonics) and starves quiet signals through a gate, plus a touch of wavefolding on the peaks.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Fuzz",
    "min": 1,
    "max": 60,
    "default": 40,
    "step": 1,
    "unit": "dB",
    "path": "/SiliconFuzz/Fuzz"
   },
   {
    "label": "Bias",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/SiliconFuzz/Bias"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/SiliconFuzz/Level"
   }
  ],
  "faustCode": "declare name \"SiliconFuzz\";\ndeclare description \"Gated silicon fuzz with bias control and wavefold spit\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nfuzz  = hslider(\"Fuzz[unit:dB]\", 40, 1, 60, 1) : si.smoo : ba.db2linear;\nbias  = hslider(\"Bias\", 0.35, 0, 1.0, 0.01) : si.smoo;\nlevel = hslider(\"Level\", 0.5, 0, 1.0, 0.01) : si.smoo;\n\n// envelope-driven gate: starved-bias transistors choke quiet signals\nenv(x)  = an.amp_follower_ud(0.002, 0.06, x);\ngthr    = 0.004 + bias * 0.06;\ngate(x) = x * (env(x) > gthr : si.smooth(ba.tau2pole(0.004)));\n\n// bias shifts the operating point -> asymmetric clipping / even harmonics\nhard(x) = max(-1, min(1, x));\nstage(x) = x + bias * 0.4 : hard : fi.dcblocker;\n// a little wavefold on the peaks for the \"spitting\" quality\nfold(x) = x - 0.18 * sin(x * ma.PI * 1.5);\n\nprocess = fi.highpass(1, 70) : *(fuzz) : ma.tanh : stage : fold : gate : fi.lowpass(2, 4200) : *(level * 0.9);"
 },
 {
  "id": "auto-wah",
  "name": "Auto-Wah / Envelope Filter",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Dynamic resonant band-pass filter tracking pick attack.",
  "description": "Vintage Q-Tron envelope follower that tracks your picking velocity to sweep a resonant 2nd-order state-variable bandpass filter.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Sensitivity",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/AutoWah/Sensitivity"
   },
   {
    "label": "Resonance",
    "min": 1,
    "max": 15,
    "default": 7,
    "step": 0.5,
    "unit": "",
    "path": "/AutoWah/Resonance"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.8,
    "step": 0.01,
    "unit": "",
    "path": "/AutoWah/Mix"
   }
  ],
  "faustCode": "declare name \"AutoWah\";\ndeclare description \"Envelope-following resonant band-pass (Q-Tron style)\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nsens = hslider(\"Sensitivity\", 0.6, 0, 1.0, 0.01) : si.smoo;\nq    = hslider(\"Resonance\", 7.0, 1, 15, 0.5) : si.smoo;\nmix  = hslider(\"Mix\", 0.8, 0, 1.0, 0.01) : si.smoo;\n\nenv(x) = an.amp_follower_ud(0.004, 0.12, x) * (2 + sens * 14) : min(1);\n// exponential sweep 280 Hz .. 2600 Hz\nfc(x)  = 280 * pow(2600 / 280, env(x));\nwah(x) = fi.resonbp(fc(x), q, 1, x) * (1 + q * 0.03) : ma.tanh;\n\nprocess(x) = x * (1 - mix) + wah(x) * mix;"
 },
 {
  "id": "pitch-octaver",
  "name": "Dual Pitch Octaver",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Polyphonic sub-octave and upper octave harmonic generator.",
  "description": "Creates thick multi-octave guitar sounds with clean tracking. Generates a deep -1 octave sub tone and a shimmering +1 octave upper tone.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Sub",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/PitchOctaver/Sub"
   },
   {
    "label": "Up",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/PitchOctaver/Up"
   },
   {
    "label": "Dry",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/PitchOctaver/Dry"
   }
  ],
  "faustCode": "declare name \"PitchOctaver\";\ndeclare description \"Polyphonic sub-octave and upper-octave blend\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nsub_vol = hslider(\"Sub\", 0.5, 0, 1.0, 0.01) : si.smoo;\nup_vol  = hslider(\"Up\", 0.4, 0, 1.0, 0.01) : si.smoo;\ndry_vol = hslider(\"Dry\", 0.7, 0, 1.0, 0.01) : si.smoo;\n\n// ef.transpose(window, crossfade, semitones)\nsub = ef.transpose(2048, 512, -12) : fi.lowpass(2, 1800);\nup  = ef.transpose(1024, 256, 12) : fi.highpass(1, 160);\n\nprocess = _ <: *(dry_vol), (sub : *(sub_vol * 0.7)), (up : *(up_vol * 0.6)) :> _;"
 },
 {
  "id": "analog-flanger",
  "name": "Jet Flanger",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Resonant comb filter with jet-plane through-zero sweep.",
  "description": "Short modulated delay lines coupled with aggressive inverted feedback create massive comb filter hollow sweeps and jet airplane passes.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Rate",
    "min": 0.05,
    "max": 5,
    "default": 0.4,
    "step": 0.02,
    "unit": "Hz",
    "path": "/JetFlanger/Rate"
   },
   {
    "label": "Depth",
    "min": 0,
    "max": 1,
    "default": 0.8,
    "step": 0.01,
    "unit": "",
    "path": "/JetFlanger/Depth"
   },
   {
    "label": "Resonance",
    "min": -0.95,
    "max": 0.95,
    "default": 0.75,
    "step": 0.01,
    "unit": "",
    "path": "/JetFlanger/Resonance"
   }
  ],
  "faustCode": "declare name \"JetFlanger\";\ndeclare description \"Resonant flanger with through-zero style sweep and bipolar feedback\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nrate  = hslider(\"Rate[unit:Hz]\", 0.4, 0.05, 5.0, 0.02) : si.smoo;\ndepth = hslider(\"Depth\", 0.8, 0, 1.0, 0.01) : si.smoo;\nres   = hslider(\"Resonance\", 0.75, -0.95, 0.95, 0.01) : si.smoo;\n\n// triangle-ish LFO gives the classic \"jet\" sweep\nlfo   = os.osc(rate) : *(1.8) : ma.tanh : /(0.947);\ndel   = (0.0006 + depth * 0.0055 * 0.5 * (1 + lfo)) * ma.SR;\n// flanger_mono(dmax, curdel, depth, fb, invert)\nprocess = pf.flanger_mono(1024, del, 1.0, res, 0) : ma.tanh;"
 },
 {
  "id": "spring-reverb",
  "name": "Spring Reverb Tank",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Physical model of dual-spring mechanical reverb bounce.",
  "description": "Spring tank model: a drive stage into a chain of dispersive allpass sections (the \"boing\") feeding two spring lines of different lengths with dark feedback.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Dwell",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/SpringReverb/Dwell"
   },
   {
    "label": "Tone",
    "min": 800,
    "max": 7000,
    "default": 3200,
    "step": 50,
    "unit": "Hz",
    "path": "/SpringReverb/Tone"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.45,
    "step": 0.01,
    "unit": "",
    "path": "/SpringReverb/Mix"
   }
  ],
  "faustCode": "declare name \"SpringReverb\";\ndeclare description \"Dispersive spring tank model: allpass chirp chain + twin springs\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\ndwell = hslider(\"Dwell\", 0.6, 0, 1.0, 0.01) : si.smoo;\ntone  = hslider(\"Tone[unit:Hz]\", 3200, 800, 7000, 50) : si.smoo;\nmix   = hslider(\"Mix\", 0.45, 0, 1.0, 0.01) : si.smoo;\n\n// drive into the transducer\ndrive(x) = ma.tanh(x * (1 + dwell * 3)) / (1 + dwell * 1.2);\npre = fi.highpass(1, 220) : drive;\n\n// dispersion: a chain of allpass sections smears transients into the \"boing\"\nchirp = seq(i, 10, fi.allpass_comb(128, 23 + i * 5, 0.62));\n\n// two springs of different length, each a lowpassed feedback loop\nspring(len, g) = (+ : de.delay(8192, len)) ~ (*(g) : fi.lowpass(1, 2600));\nfbk = 0.82 + dwell * 0.13;\ntank = _ <: spring(2103, fbk), spring(3379, fbk * 0.95) :> *(0.5);\n\nwet = pre : chirp : tank : fi.lowpass(2, tone) : fi.highpass(1, 150);\nprocess = _ <: *(1 - mix), (wet : *(mix * 1.1)) :> _;"
 },
 {
  "id": "clean-boost",
  "name": "JFET Preamp Boost",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Discrete Class-A JFET boost with tilt-EQ saturation.",
  "description": "Pushes tube amp front ends into natural breakup while adding harmonic sheen. Center knob tilts between low-end fatness and treble sparkle.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Boost",
    "min": 0,
    "max": 25,
    "default": 12,
    "step": 0.5,
    "unit": "dB",
    "path": "/JFETBoost/Boost"
   },
   {
    "label": "Tilt EQ",
    "min": -10,
    "max": 10,
    "default": 2,
    "step": 0.5,
    "unit": "dB",
    "path": "/JFETBoost/Tilt_EQ"
   },
   {
    "label": "Master",
    "min": 0,
    "max": 1,
    "default": 0.8,
    "step": 0.01,
    "unit": "",
    "path": "/JFETBoost/Master"
   }
  ],
  "faustCode": "declare name \"JFETBoost\";\ndeclare description \"Class-A JFET style boost with tilt EQ and gentle saturation\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nboost  = hslider(\"Boost[unit:dB]\", 12, 0, 25, 0.5) : si.smoo : ba.db2linear;\ntilt   = hslider(\"Tilt EQ[unit:dB]\", 2, -10, 10, 0.5) : si.smoo;\nmaster = hslider(\"Master\", 0.8, 0, 1.0, 0.01) : si.smoo;\n\n// tilt around 900 Hz: +tilt on highs, -tilt on lows\ntilteq = fi.low_shelf(0 - tilt, 900) : fi.high_shelf(tilt, 900);\n// JFET: mostly linear, rounds off only the peaks\njfet(x) = x - 0.12 * x * x * x : max(-1.4) : min(1.4);\n\nprocess = fi.highpass(1, 40) : tilteq : *(boost * 0.5) : jfet : *(master * 1.0);"
 },
 {
  "id": "reverse-delay",
  "name": "Reverse Delay",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Backwards buffer playback for psychedelic textures.",
  "description": "Two backwards-running read heads half a window apart, crossfaded so the reversed audio has no seams, with a filtered feedback path.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Window Time",
    "min": 100,
    "max": 1500,
    "default": 600,
    "step": 10,
    "unit": "ms",
    "path": "/ReverseDelay/Window_Time"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.9,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/ReverseDelay/Feedback"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/ReverseDelay/Mix"
   }
  ],
  "faustCode": "declare name \"ReverseDelay\";\ndeclare description \"Windowed backwards playback with crossfaded read heads and feedback\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nwtime = hslider(\"Window Time[unit:ms]\", 600, 100, 1500, 10) * 0.001 : si.smooth(ba.tau2pole(0.2));\nfb    = hslider(\"Feedback\", 0.4, 0, 0.9, 0.01) : si.smoo;\nmix   = hslider(\"Mix\", 0.5, 0, 1.0, 0.01) : si.smoo;\n\nMAXDEL = 131072;\nW   = wtime * ma.SR : max(256) : min(MAXDEL / 2 - 4);   // never 0: the period counter divides by W\n// two read heads, half a window apart, each running backwards through the buffer\nph1 = ba.period(W);\nph2 = (ph1 + W * 0.5) : fmod(_, W);\nwin(p) = sin(ma.PI * p / W);\nhead(p, x) = de.fdelay(MAXDEL, 2 * p, x) * win(p);\nrev(x) = (head(ph1, x) + head(ph2, x)) * 0.75;\n\nloop = (+ : rev) ~ (fi.lowpass(1, 4500) : *(fb) : ma.tanh);\nprocess = _ <: *(1 - mix), (loop : *(mix)) :> _;"
 },
 {
  "id": "lofi-bitcrush",
  "name": "Lo-Fi Bitcrusher",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Sample rate decimation and dynamic bit reduction.",
  "description": "Sample-and-hold decimation at the target rate plus bit-depth quantisation, blended against the dry signal.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Sample Rate",
    "min": 500,
    "max": 44100,
    "default": 8000,
    "step": 100,
    "unit": "Hz",
    "path": "/LoFiBitcrusher/Sample_Rate"
   },
   {
    "label": "Bit Depth",
    "min": 2,
    "max": 16,
    "default": 6,
    "step": 1,
    "unit": "",
    "path": "/LoFiBitcrusher/Bit_Depth"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/LoFiBitcrusher/Mix"
   }
  ],
  "faustCode": "declare name \"LoFiBitcrusher\";\ndeclare description \"Sample-rate decimation and bit-depth reduction\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nsr_target = hslider(\"Sample Rate[unit:Hz]\", 8000, 500, 44100, 100) : si.smoo;\nbits      = hslider(\"Bit Depth\", 6, 2, 16, 1);\nmix       = hslider(\"Mix\", 0.7, 0, 1.0, 0.01) : si.smoo;\n\n// sample & hold clocked at the target rate\nph      = os.lf_sawpos(sr_target);\ntrig    = ph < ph';\nlevels  = pow(2, bits - 1);\nquant(x) = floor(x * levels + 0.5) / levels;\ncrush   = ba.sAndH(trig) : quant;\n\nprocess(x) = x * (1 - mix) + crush(x) * mix;"
 },
 {
  "id": "drum-pumping-comp",
  "name": "Pumping VCA Drum Compressor",
  "category": "drum",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Aggressive sidechain-style pumping compressor for dance beats.",
  "description": "Designed specifically for analog drum machines. Clamps down heavily on kick transients and breathes out with exaggerated, musical pumping.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Threshold",
    "min": -40,
    "max": 0,
    "default": -22,
    "step": 1,
    "unit": "dB",
    "path": "/PumpingDrumCompressor/Threshold"
   },
   {
    "label": "Pump Release",
    "min": 40,
    "max": 600,
    "default": 140,
    "step": 5,
    "unit": "ms",
    "path": "/PumpingDrumCompressor/Pump_Release"
   },
   {
    "label": "Blend",
    "min": 0,
    "max": 1,
    "default": 0.9,
    "step": 0.01,
    "unit": "",
    "path": "/PumpingDrumCompressor/Blend"
   }
  ],
  "faustCode": "declare name \"PumpingDrumCompressor\";\ndeclare description \"Fast VCA bus compressor with exaggerated pump and auto make-up\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nthresh = hslider(\"Threshold[unit:dB]\", -22, -40, 0, 1) : si.smoo;\nrel    = hslider(\"Pump Release[unit:ms]\", 140, 40, 600, 5) * 0.001 : si.smoo;\nblend  = hslider(\"Blend\", 0.9, 0, 1.0, 0.01) : si.smoo;\n\nratio  = 8;\nmakeup = -thresh * (1 - 1/ratio) * 0.7 : ba.db2linear;\ncomp(x) = co.compressor_mono(ratio, thresh, 0.0015, rel, x) * makeup;\nceiling(x) = ma.tanh(x);\n\nprocess(x) = x * (1 - blend) + (comp(x) : ceiling) * blend;"
 },
 {
  "id": "gated-snare-reverb",
  "name": "80s Gated Snare Reverb",
  "category": "drum",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Explosive non-linear gated reverb tail that cuts off abruptly.",
  "description": "Big room (Freeverb) keyed from the kick/snare band of the dry input; the gate slams shut a set hold time after each hit.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Gate Hold",
    "min": 50,
    "max": 500,
    "default": 220,
    "step": 5,
    "unit": "ms",
    "path": "/GatedSnareReverb/Gate_Hold"
   },
   {
    "label": "Room Size",
    "min": 0.1,
    "max": 1,
    "default": 0.8,
    "step": 0.05,
    "unit": "",
    "path": "/GatedSnareReverb/Room_Size"
   },
   {
    "label": "Wet Mix",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/GatedSnareReverb/Wet_Mix"
   }
  ],
  "faustCode": "declare name \"GatedSnareReverb\";\ndeclare description \"Big room reverb keyed by the dry input and slammed shut after a hold time\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nhold = hslider(\"Gate Hold[unit:ms]\", 220, 50, 500, 5) * 0.001;\nsize = hslider(\"Room Size\", 0.8, 0.1, 1.0, 0.05) : si.smoo;\nmix  = hslider(\"Wet Mix\", 0.6, 0, 1.0, 0.01) : si.smoo;\n\nroom = 0.7 + size * 0.25;\nverb = fi.highpass(1, 140) <: re.stereo_freeverb(room, 0.5, 0.25, 0.7) :> *(0.07);\n\n// gate keyed from the dry input, not the reverb tail\n// key on the kick/snare band so hi-hats don't hold the gate open\nkey(x)  = fi.bandpass(1, 90, 1600, x) : an.amp_follower_ar(0.0005, hold) > 0.10;\ngate(x) = key(x) : si.smooth(ba.tau2pole(0.003));\n\nprocess(x) = x * (1 - mix) + (verb(x) : ma.tanh) * gate(x) * mix;"
 },
 {
  "id": "resonant-dj-filter",
  "name": "Resonant DJ Dual Filter",
  "category": "drum",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "High-resonance Low-Pass (turn left) and High-Pass (turn right) sweep.",
  "description": "One knob, centre is clean: sweep left for a resonant low-pass down to 60 Hz, right for a resonant high-pass up to 8 kHz. Exponential sweep, analog-style saturation at high resonance.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Filter Sweep",
    "min": -100,
    "max": 100,
    "default": 0,
    "step": 1,
    "unit": "",
    "path": "/ResonantDJFilter/Filter_Sweep"
   },
   {
    "label": "Resonance",
    "min": 1,
    "max": 20,
    "default": 8,
    "step": 0.5,
    "unit": "",
    "path": "/ResonantDJFilter/Resonance"
   },
   {
    "label": "Drive",
    "min": 0,
    "max": 1,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/ResonantDJFilter/Drive"
   }
  ],
  "faustCode": "declare name \"ResonantDJFilter\";\ndeclare description \"One-knob DJ filter: low-pass left of centre, high-pass right of centre\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nsweep = hslider(\"Filter Sweep\", 0, -100, 100, 1) * 0.01 : si.smoo;\nq     = hslider(\"Resonance\", 8, 1, 20, 0.5) : si.smoo;\ndrive = hslider(\"Drive\", 0.3, 0, 1.0, 0.01) : si.smoo;\n\n// dead zone around centre so the knob has a clean \"off\"\ndz   = 0.06;\nlpa  = max(0, (0 - sweep) - dz) / (1 - dz);   // 0..1 as the knob goes left\nhpa  = max(0, sweep - dz) / (1 - dz);          // 0..1 as the knob goes right\nlp_f = 18000 * pow(60 / 18000, lpa);           // exponential 18k -> 60 Hz\nhp_f = 20 * pow(8000 / 20, hpa);               // exponential 20 -> 8k Hz\n\npre(x)  = ma.tanh(x * (1 + drive * 4)) / (1 + drive * 1.5);\nlp = fi.resonlp(lp_f, q, 1);\nhp = fi.resonhp(hp_f, q, 1);\n\n// resonant peaks saturate like an analog ladder rather than clipping the codec\nprocess = pre : lp : hp : fi.lowpass(1, 19000) : ma.tanh;"
 },
 {
  "id": "tape-saturation-drum",
  "name": "Analog Tape Saturator",
  "category": "drum",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Fat analog tape drive that glues kicks and rounds harsh cymbals.",
  "description": "Harmonic saturation tuned for analog drum machines. Tames piercing metallic cymbals on the DrumBrute/Volca and fattens low-end kick body.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Tape Drive",
    "min": 0,
    "max": 1,
    "default": 0.45,
    "step": 0.01,
    "unit": "",
    "path": "/TapeSaturator/Tape_Drive"
   },
   {
    "label": "Warmth",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/TapeSaturator/Warmth"
   },
   {
    "label": "Output Level",
    "min": 0,
    "max": 1,
    "default": 0.75,
    "step": 0.01,
    "unit": "",
    "path": "/TapeSaturator/Output_Level"
   }
  ],
  "faustCode": "declare name \"TapeSaturator\";\ndeclare description \"Tape-style saturation with low-end warmth and HF softening\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\ndrive  = hslider(\"Tape Drive\", 0.45, 0, 1.0, 0.01) : si.smoo;\nwarmth = hslider(\"Warmth\", 0.6, 0, 1.0, 0.01) : si.smoo;\nout    = hslider(\"Output Level\", 0.75, 0, 1.0, 0.01) : si.smoo;\n\ng      = 1 + drive * 6;\nsat(x) = ma.tanh(x * g) / pow(g, 0.6);\nhfroll = 16000 - drive * 8000;\n\nprocess = fi.low_shelf(warmth * 6, 160) : sat : fi.dcblocker : fi.lowpass(1, hfroll) : *(out * 1.2);"
 },
 {
  "id": "beat-repeater",
  "name": "Beat Repeater / Stutter",
  "category": "drum",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Buffer stutter: grabs a slice and repeats it N times in tempo-sized subdivisions.",
  "description": "Captures a slice of the incoming beat and plays it back N times before grabbing a fresh one. Short slices give glitchy rolls; long slices give bar-level loops.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Slice Size",
    "min": 25,
    "max": 500,
    "default": 125,
    "step": 5,
    "unit": "ms",
    "path": "/BeatRepeater/Slice_Size"
   },
   {
    "label": "Repeats",
    "min": 1,
    "max": 8,
    "default": 4,
    "step": 1,
    "unit": "",
    "path": "/BeatRepeater/Repeats"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.8,
    "step": 0.01,
    "unit": "",
    "path": "/BeatRepeater/Dry_Wet"
   }
  ],
  "faustCode": "declare name \"BeatRepeater\";\ndeclare description \"Buffer stutter: plays each captured slice N times before grabbing a new one\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nslice = hslider(\"Slice Size[unit:ms]\", 125, 25, 500, 5) * 0.001;\nreps  = hslider(\"Repeats\", 4, 1, 8, 1);\nmix   = hslider(\"Dry/Wet\", 0.8, 0, 1.0, 0.01) : si.smoo;\n\nMAXDEL = 262144;\nW    = slice * ma.SR : int : max(256);\nph   = ba.period(W);\ntrig = ph < ph';\n// which repeat are we on (0 = live audio, 1..reps-1 = repeats)\nn    = (+(trig) : %(int(reps))) ~ _;\nd    = n * W : min(MAXDEL - 4);\n// short fade at slice edges hides the jump\nfade = 96;\ng    = min(1, min(ph / fade, (W - ph) / fade));\n\nstutter(x) = de.delay(MAXDEL, d, x) * g;\nprocess(x) = x * (1 - mix) + stutter(x) * mix;"
 },
 {
  "id": "sub-resonator",
  "name": "808 Sub-Bass Resonator",
  "category": "drum",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Triggers a massive 40-60Hz sine boom on drum transients.",
  "description": "A tuned 2-pole resonator excited only by the low band of the input, with Q derived from the Decay knob so the boom rings for the time you set.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Tuned Frequency",
    "min": 35,
    "max": 90,
    "default": 52,
    "step": 1,
    "unit": "Hz",
    "path": "/SubBassResonator/Tuned_Frequency"
   },
   {
    "label": "Decay Length",
    "min": 50,
    "max": 800,
    "default": 320,
    "step": 10,
    "unit": "ms",
    "path": "/SubBassResonator/Decay_Length"
   },
   {
    "label": "Sub Volume",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/SubBassResonator/Sub_Volume"
   }
  ],
  "faustCode": "declare name \"SubBassResonator\";\ndeclare description \"Tuned low resonator excited by kick transients\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"Tuned Frequency[unit:Hz]\", 52, 35, 90, 1) : si.smoo;\ndecay = hslider(\"Decay Length[unit:ms]\", 320, 50, 800, 10) * 0.001 : si.smoo;\nvol   = hslider(\"Sub Volume\", 0.7, 0, 1.0, 0.01) : si.smoo;\n\n// 2-pole resonator: t60 ~= Q * ln(1000) / (pi * f)  ->  Q = t60 * pi * f / 6.9\nq      = decay * ma.PI * freq / 6.9 : max(2) : min(120);\n// excite with the transient of the low band only\nexc(x) = fi.lowpass(2, 140, x) * 6 : ma.tanh;\nsub(x) = fi.resonbp(freq, q, 1, exc(x)) * 1.2 : ma.tanh : *(0.45);\n\nprocess(x) = x * 0.9 + sub(x) * vol;"
 },
 {
  "id": "drum-slammer",
  "name": "Drum Slammer Peak Limiter",
  "category": "drum",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Brickwall peak limiter maximizing perceived drum loudness.",
  "description": "Over-the-top peak limiter and clipper. Crushes drum dynamics to create that explosive, in-your-face room sound without digital overs.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Threshold / Drive",
    "min": 0,
    "max": 24,
    "default": 12,
    "step": 0.5,
    "unit": "dB",
    "path": "/DrumSlammer/Threshold___Drive"
   },
   {
    "label": "Hardness",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/DrumSlammer/Hardness"
   },
   {
    "label": "Ceiling",
    "min": -12,
    "max": 0,
    "default": -0.5,
    "step": 0.1,
    "unit": "dB",
    "path": "/DrumSlammer/Ceiling"
   }
  ],
  "faustCode": "declare name \"DrumSlammer\";\ndeclare description \"1176-style peak limiter into a variable-hardness clipper\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\ndrive   = hslider(\"Threshold / Drive[unit:dB]\", 12, 0, 24, 0.5) : si.smoo : ba.db2linear;\nhard    = hslider(\"Hardness\", 0.7, 0, 1.0, 0.01) : si.smoo;\nceilDb  = hslider(\"Ceiling[unit:dB]\", -0.5, -12, 0, 0.1) : si.smoo;\n\nceilLin = ceilDb : ba.db2linear;\nsoft(x) = ma.tanh(x);\nhclip(x) = max(-1, min(1, x));\nclipper(x) = soft(x) * (1 - hard) + hclip(x) * hard;\n\nprocess = *(drive) : co.limiter_1176_R4_mono : clipper : *(ceilLin);"
 },
 {
  "id": "ring-mod-percussion",
  "name": "Metallic Ring Modulator",
  "category": "drum",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Frequency multiplication for robotic, metallic drum timbres.",
  "description": "Multiplies drum hits with a carrier sine/square wave to create clanging cowbells, futuristic laser toms, and dissonant industrial hi-hats.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Carrier Freq",
    "min": 50,
    "max": 2500,
    "default": 440,
    "step": 10,
    "unit": "Hz",
    "path": "/RingModulator/Carrier_Freq"
   },
   {
    "label": "Wave Shape",
    "min": 0,
    "max": 1,
    "default": 0.2,
    "step": 0.01,
    "unit": "",
    "path": "/RingModulator/Wave_Shape"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/RingModulator/Mix"
   }
  ],
  "faustCode": "declare name \"RingModulator\";\ndeclare description \"Ring modulator with sine-to-square carrier morph\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"Carrier Freq[unit:Hz]\", 440, 50, 2500, 10) : si.smoo;\nshape = hslider(\"Wave Shape\", 0.2, 0, 1.0, 0.01) : si.smoo;\nmix   = hslider(\"Mix\", 0.5, 0, 1.0, 0.01) : si.smoo;\n\n// morph sine -> square by driving the sine into a clipper\ncarrier = os.osc(freq) * (1 + shape * 12) : ma.tanh;\nprocess(x) = x * (1 - mix) + x * carrier * mix;"
 },
 {
  "id": "transient-shaper",
  "name": "Drum Transient Shaper",
  "category": "drum",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Independent attack click boost and sustain body control.",
  "description": "Compares a fast and a slow envelope follower; attacks are boosted or cut where the fast envelope leads, sustain where it lags.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Attack Boost",
    "min": -12,
    "max": 12,
    "default": 6,
    "step": 0.5,
    "unit": "dB",
    "path": "/TransientShaper/Attack_Boost"
   },
   {
    "label": "Sustain Tail",
    "min": -12,
    "max": 12,
    "default": -3,
    "step": 0.5,
    "unit": "dB",
    "path": "/TransientShaper/Sustain_Tail"
   },
   {
    "label": "Output Gain",
    "min": -6,
    "max": 6,
    "default": 0,
    "step": 0.5,
    "unit": "dB",
    "path": "/TransientShaper/Output_Gain"
   }
  ],
  "faustCode": "declare name \"TransientShaper\";\ndeclare description \"Attack/sustain shaper from fast vs slow envelope ratio\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\natt = hslider(\"Attack Boost[unit:dB]\", 6, -12, 12, 0.5) : si.smoo : ba.db2linear;\nsus = hslider(\"Sustain Tail[unit:dB]\", -3, -12, 12, 0.5) : si.smoo : ba.db2linear;\nout = hslider(\"Output Gain[unit:dB]\", 0, -6, 6, 0.5) : si.smoo : ba.db2linear;\n\nfast(x) = an.amp_follower_ud(0.0005, 0.020, x);\nslow(x) = an.amp_follower_ud(0.020, 0.200, x);\nratio(x) = fast(x) / (slow(x) + 1e-5);\na(x) = ratio(x) - 1 : max(0) : min(1);      // 1 during attacks\ns(x) = 1 - ratio(x) : max(0) : min(1);      // 1 during decay/sustain\ngain(x) = pow(att, a(x)) * pow(sus, s(x)) : si.smooth(ba.tau2pole(0.0005));\n\nprocess(x) = x * gain(x) * out : ma.tanh;"
 },
 {
  "id": "stereo-pingpong-beat",
  "name": "Multi-Tap Beat Delay",
  "category": "drum",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Rhythmic straight + dotted-eighth two-tap delay with filtered feedback.",
  "description": "Two rhythmic taps (straight and dotted) with a dark filtered feedback path. The pedal has one output jack, so this replaces the stereo ping-pong idea with a mono multi-tap pattern that gives the same syncopation.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Tempo / Time",
    "min": 50,
    "max": 600,
    "default": 240,
    "step": 5,
    "unit": "ms",
    "path": "/MultiTapBeatDelay/Tempo___Time"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.9,
    "default": 0.45,
    "step": 0.01,
    "unit": "",
    "path": "/MultiTapBeatDelay/Feedback"
   },
   {
    "label": "Dotted Tap",
    "min": 0,
    "max": 1,
    "default": 0.8,
    "step": 0.01,
    "unit": "",
    "path": "/MultiTapBeatDelay/Dotted_Tap"
   }
  ],
  "faustCode": "declare name \"MultiTapBeatDelay\";\ndeclare description \"Rhythmic two-tap delay (straight + dotted) with filtered feedback\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\ntime   = hslider(\"Tempo / Time[unit:ms]\", 240, 50, 600, 5) * 0.001 : si.smooth(ba.tau2pole(0.1));\nfb     = hslider(\"Feedback\", 0.45, 0, 0.9, 0.01) : si.smoo;\ndotted = hslider(\"Dotted Tap\", 0.8, 0, 1.0, 0.01) : si.smoo;\n\nMAXDEL = 65536;\nd1 = time * ma.SR : min(MAXDEL - 4);\nd2 = time * 0.75 * ma.SR : min(MAXDEL - 4);\n\ntone = fi.lowpass(1, 5000) : fi.highpass(1, 120);\ntap  = (+ : de.fdelay(MAXDEL, d1)) ~ (tone : *(fb));\ndot  = de.fdelay(MAXDEL, d2) : fi.lowpass(1, 3500);\n\nprocess(x) = x * 0.9 + tap(x) * 0.65 + dot(x) * dotted * 0.45;"
 },
 {
  "id": "wavefolder-dirt",
  "name": "Buchla Drum Wavefolder",
  "category": "drum",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Non-linear wavefolding for aggressive industrial drum harmonics.",
  "description": "Instead of clipping waveforms, wavefolders fold high-level peaks backwards towards zero, turning simple analog kicks into aggressive techno monsters.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Fold Depth",
    "min": 1,
    "max": 10,
    "default": 4,
    "step": 0.1,
    "unit": "",
    "path": "/WavefolderDirt/Fold_Depth"
   },
   {
    "label": "Symmetry",
    "min": -0.5,
    "max": 0.5,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/WavefolderDirt/Symmetry"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.75,
    "step": 0.01,
    "unit": "",
    "path": "/WavefolderDirt/Mix"
   }
  ],
  "faustCode": "declare name \"WavefolderDirt\";\ndeclare description \"Sine wavefolder with symmetry offset and DC restoration\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nfolds = hslider(\"Fold Depth\", 4.0, 1, 10, 0.1) : si.smoo;\nsym   = hslider(\"Symmetry\", 0, -0.5, 0.5, 0.01) : si.smoo;\nmix   = hslider(\"Mix\", 0.75, 0, 1.0, 0.01) : si.smoo;\n\nfold(x) = sin((x * folds + sym) * ma.PI * 0.5);\nwet = fold : fi.dcblocker : fi.lowpass(1, 12000) : *(0.55);\n\nprocess(x) = x * (1 - mix) + wet(x) * mix;"
 },
 {
  "id": "comb-resonator",
  "name": "Comb Filter Resonator",
  "category": "drum",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Pitched resonant comb filter turning drum bursts into synth notes.",
  "description": "Highly tuned feedback comb filter that rings at precise musical pitches when excited by noisy snare cracks or sharp rimshots.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Tuned Pitch",
    "min": 50,
    "max": 800,
    "default": 130,
    "step": 1,
    "unit": "Hz",
    "path": "/CombResonator/Tuned_Pitch"
   },
   {
    "label": "Ring Decay",
    "min": 0.5,
    "max": 0.99,
    "default": 0.92,
    "step": 0.01,
    "unit": "",
    "path": "/CombResonator/Ring_Decay"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/CombResonator/Dry_Wet"
   }
  ],
  "faustCode": "declare name \"CombResonator\";\ndeclare description \"Tuned feedback comb that rings drum hits at a musical pitch\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nf     = hslider(\"Tuned Pitch[unit:Hz]\", 130, 50, 800, 1) : si.smoo;\ndecay = hslider(\"Ring Decay\", 0.92, 0.5, 0.99, 0.01) : si.smoo;\nmix   = hslider(\"Dry/Wet\", 0.5, 0, 1.0, 0.01) : si.smoo;\n\nMAXDEL = 2048;\ndel  = ma.SR / f : min(MAXDEL - 4);\n// positive feedback => resonates at f and its harmonics; lowpass tames the top\ncomb = (+ : de.fdelay(MAXDEL, del)) ~ (*(decay) : fi.lowpass(1, 6000));\nwet  = comb : *(1 - decay * 0.7) : ma.tanh;\n\nprocess(x) = x * (1 - mix) + wet(x) * mix;"
 },
 {
  "id": "freq-shifter",
  "name": "Bode Frequency Shifter",
  "category": "drum",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Linear frequency shifting for dissonant alien percussion.",
  "description": "Single-sideband frequency shifter built on a Hilbert allpass pair: every partial moves by the same number of Hz, wrecking harmonic relationships for bell-like, inharmonic percussion.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Shift Amount",
    "min": -500,
    "max": 500,
    "default": 85,
    "step": 1,
    "unit": "Hz",
    "path": "/FrequencyShifter/Shift_Amount"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.8,
    "default": 0.2,
    "step": 0.01,
    "unit": "",
    "path": "/FrequencyShifter/Feedback"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/FrequencyShifter/Mix"
   }
  ],
  "faustCode": "declare name \"FrequencyShifter\";\ndeclare description \"Bode-style single-sideband frequency shifter (Hilbert allpass pair)\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nshift = hslider(\"Shift Amount[unit:Hz]\", 85, -500, 500, 1) : si.smoo;\nfb    = hslider(\"Feedback\", 0.2, 0, 0.8, 0.01) : si.smoo;\nmix   = hslider(\"Mix\", 0.6, 0, 1.0, 0.01) : si.smoo;\n\n// Niemitalo 90-degree allpass network\nap(a, x) = y with { a2 = a * a; y = (a2 * x - x@2 + a2 * _) ~ mem; };\npathA = ap(0.6923878) : ap(0.9360654322959) : ap(0.9882295226860) : ap(0.9987488452737);\npathB = ap(0.4021921162426) : ap(0.8561710882420) : ap(0.9722909545651) : ap(0.9952884791278) : mem;\n\nssb(x) = pathA(x) * os.oscp(shift, 0) - pathB(x) * os.oscp(shift, ma.PI * 0.5);\nloop = (+ : ssb) ~ (fi.lowpass(1, 6000) : *(fb) : ma.tanh);\n\nprocess(x) = x * (1 - mix) + loop(x) * mix;"
 },
 {
  "id": "bbd-drum-delay",
  "name": "Dark BBD Percussion Delay",
  "category": "drum",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Dark, saturated analog bucket-brigade delay for drums.",
  "description": "Filtered repeats that sit neatly behind drum grooves without cluttering the mix. Features progressive high-cut filtering on successive echoes.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Delay Time",
    "min": 30,
    "max": 800,
    "default": 280,
    "step": 5,
    "unit": "ms",
    "path": "/DarkBBDDelay/Delay_Time"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.95,
    "default": 0.55,
    "step": 0.01,
    "unit": "",
    "path": "/DarkBBDDelay/Feedback"
   },
   {
    "label": "Darkness",
    "min": 500,
    "max": 5000,
    "default": 1800,
    "step": 50,
    "unit": "Hz",
    "path": "/DarkBBDDelay/Darkness"
   }
  ],
  "faustCode": "declare name \"DarkBBDDelay\";\ndeclare description \"Bucket-brigade delay: dark, compressed repeats that get darker each pass\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\ntime = hslider(\"Delay Time[unit:ms]\", 280, 30, 800, 5) * 0.001 : si.smooth(ba.tau2pole(0.1));\nfb   = hslider(\"Feedback\", 0.55, 0, 0.95, 0.01) : si.smoo;\ndark = hslider(\"Darkness[unit:Hz]\", 1800, 500, 5000, 50) : si.smoo;\n\nMAXDEL = 65536;\nd = time * ma.SR : min(MAXDEL - 4);\n// BBD compander + clock filter in the loop\nbbd(x) = ma.tanh(x * 1.6) / 1.6 : fi.lowpass(2, dark) : fi.highpass(1, 90);\necho = (+ : de.fdelay(MAXDEL, d)) ~ (bbd : *(fb));\n\nprocess(x) = x * 0.9 + echo(x) * 0.7;"
 },
 {
  "id": "expander-gate",
  "name": "Drum Expander / Noise Gate",
  "category": "drum",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "DrumBrute / Volca",
  "source": "Chameleon",
  "license": "MIT",
  "shortDesc": "Fast downward expander cutting background hiss and hum.",
  "description": "Downward expander with a 4:1 slope below threshold and a range control so hiss can be reduced rather than hard-muted.",
  "author": "Chameleon DSP",
  "flags": "",
  "params": [
   {
    "label": "Threshold",
    "min": -60,
    "max": -10,
    "default": -38,
    "step": 1,
    "unit": "dB",
    "path": "/ExpanderGate/Threshold"
   },
   {
    "label": "Release Speed",
    "min": 10,
    "max": 300,
    "default": 75,
    "step": 5,
    "unit": "ms",
    "path": "/ExpanderGate/Release_Speed"
   },
   {
    "label": "Floor Cut",
    "min": -40,
    "max": 0,
    "default": -28,
    "step": 1,
    "unit": "dB",
    "path": "/ExpanderGate/Floor_Cut"
   }
  ],
  "faustCode": "declare name \"ExpanderGate\";\ndeclare description \"Downward expander / noise gate with range control\";\ndeclare author \"Chameleon DSP\";\nimport(\"stdfaust.lib\");\n\nthresh = hslider(\"Threshold[unit:dB]\", -38, -60, -10, 1) : si.smoo;\nrel    = hslider(\"Release Speed[unit:ms]\", 75, 10, 300, 5) * 0.001;\nrange  = hslider(\"Floor Cut[unit:dB]\", -28, -40, 0, 1) : si.smoo;\n\nratio  = 4;\nlvl(x) = an.amp_follower_ud(0.0005, rel, x) : ba.linear2db;\n// below threshold, reduce by (ratio-1) dB per dB, but never more than 'range'\ngdb(x) = (lvl(x) - thresh) * (ratio - 1) : min(0) : max(range);\ngain(x) = gdb(x) : ba.db2linear : si.smooth(ba.tau2pole(0.002));\n\nprocess(x) = x * gain(x);"
 },
 {
  "id": "lib-12ax7-preamp",
  "name": "12AX7 Preamp",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Three cascaded table-driven 12AX7 triode stages (tubes.lib) with gain, JCM800 tone stack and master",
  "description": "Three cascaded table-driven 12AX7 triode stages (tubes.lib) with gain, JCM800 tone stack and master",
  "author": "Guitarix project (tube tables), GRAME",
  "flags": "",
  "params": [
   {
    "label": "Pregain",
    "min": -20,
    "max": 40,
    "default": 12,
    "step": 0.1,
    "unit": "dB",
    "path": "/12AX7_Preamp/Pregain"
   },
   {
    "label": "Gain",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/12AX7_Preamp/Gain"
   },
   {
    "label": "Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/12AX7_Preamp/Bass"
   },
   {
    "label": "Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/12AX7_Preamp/Middle"
   },
   {
    "label": "Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/12AX7_Preamp/Treble"
   },
   {
    "label": "Master",
    "min": -30,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/12AX7_Preamp/Master"
   }
  ],
  "faustCode": "declare name \"12AX7 Preamp\";\ndeclare description \"Three cascaded table-driven 12AX7 triode stages (tubes.lib) with gain, JCM800 tone stack and master\";\ndeclare author \"Guitarix project (tube tables), GRAME\";\ndeclare license \"GPL-2.0-or-later\";\ndeclare source \"grame-cncm/faustlibraries/tubes.lib tu.T1_12AX7/T2/T3 + tonestacks.lib\";\ndeclare category \"guitar\";\ndeclare family \"amp\";\nimport(\"stdfaust.lib\");\ntu = library(\"tubes.lib\");\nts = library(\"tonestacks.lib\");\n\npre    = hslider(\"[0] Pregain[unit:dB]\", 12, -20, 40, 0.1) : ba.db2linear : si.smoo;\ngain   = hslider(\"[1] Gain[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\nbass   = hslider(\"[2] Bass\", 0.5, 0, 1, 0.01) : si.smoo;\nmid    = hslider(\"[3] Middle\", 0.5, 0, 1, 0.01) : si.smoo;\ntreble = hslider(\"[4] Treble\", 0.5, 0, 1, 0.01) : si.smoo;\nmaster = hslider(\"[5] Master[unit:dB]\", 0, -30, 20, 0.1) : ba.db2linear : si.smoo;\n\nstage1 = *(pre) : tu.T1_12AX7 : fi.lowpass(1, 6531) : tu.T2_12AX7 : *(gain);\nstage2 = fi.lowpass(1, 6531) : tu.T3_12AX7;\nprocess = stage1 : stage2 : ts.jcm800(treble, mid, bass) : fi.dcblocker : *(master);"
 },
 {
  "id": "gx-gx-studiopre",
  "name": "Alembic F-2B Studio Preamp",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Full Alembic F-2B: two 12AX7 sections, Bright/Normal, tone stack and master.",
  "description": "DK circuit simulation from the schematic of the Alembic F-2B studio preamp (two 12AX7 sections with a Fender-style tone stack), with Bright and Normal channel clip tables, an output stage table and a five-band split. A clean, warm tube preamp with Bass/Middle/Treble, Volume and Master.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Bass L",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/gx_gx_studiopre/Bass_L"
   },
   {
    "label": "Middle L",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/gx_gx_studiopre/Middle_L"
   },
   {
    "label": "Volume L",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/gx_gx_studiopre/Volume_L"
   },
   {
    "label": "Treble L",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/gx_gx_studiopre/Treble_L"
   },
   {
    "label": "Master L",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/gx_gx_studiopre/Master_L"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gx_studiopre.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n\nimport(\"stdfaust.lib\"); \n\ngxt = library(\"gx_tables.lib\");\n\n//  Based on simple Alembic F-2B vstudio preamp\nnormal = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0)) : alembic_normclip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n    Bass_L = vslider(\"Bass_L[name:Bass_L]\", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(3) : si.smooth(s);\n\n\n    Middle_L = vslider(\"Middle_L[name:Middle_L]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n\n    Volume_L = vslider(\"Volume_L[name:Volume_L]\", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(3) : si.smooth(s);\n\n\n    Treble_L = vslider(\"Treble_L[name:Treble_L]\", 0.5, 0, 1, 0.01) : Inverted(1) : si.smooth(s);\n\n    b0 = Volume_L*(Bass_L*(Treble_L*pow(fs,3)*(1.17882146159178e-17*fs + 7.85880974394511e-17) + fs*(fs*(fs*(-1.17882146159178e-17*fs - 2.07004392829875e-15) - 1.0070880757276e-11) - 6.70506959004678e-11)) + Middle_L*(Bass_L*pow(fs,2)*(fs*(-1.65035004622849e-18*fs - 9.46515045560758e-15) - 6.30276541464398e-14) + fs*(fs*(-1.03234662466208e-16*fs - 5.91603840340603e-13) - 3.93943739504993e-12)) + Treble_L*fs*(fs*(7.37390446187197e-16*fs + 2.99972440013567e-14) + 1.67208717956279e-13) + fs*(fs*(-7.37390446187197e-16*fs - 2.99972440013567e-14) - 1.67208717956279e-13));\n\n    b1 = Volume_L*(Bass_L*(Treble_L*pow(fs,3)*(-4.71528584636711e-17*fs - 1.57176194878902e-16) + fs*(pow(fs,2)*(4.71528584636711e-17*fs + 4.1400878565975e-15) - 1.34101391800936e-10)) + Middle_L*(Bass_L*pow(fs,3)*(6.60140018491395e-18*fs + 1.89303009112152e-14) + fs*(2.06469324932415e-16*pow(fs,2) - 7.87887479009986e-12)) + Treble_L*fs*(-1.47478089237439e-15*pow(fs,2) + 3.34417435912558e-13) + fs*(1.47478089237439e-15*pow(fs,2) - 3.34417435912558e-13));\n\n    b2 = Volume_L*(Bass_L*(7.07292876955067e-17*Treble_L*pow(fs,4) + pow(fs,2)*(-7.07292876955067e-17*pow(fs,2) + 2.0141761514552e-11)) + Middle_L*(Bass_L*pow(fs,2)*(-9.90210027737093e-18*pow(fs,2) + 1.2605530829288e-13) + 1.18320768068121e-12*pow(fs,2)) - 5.99944880027134e-14*Treble_L*pow(fs,2) + 5.99944880027134e-14*pow(fs,2));\n\n    b3 = Volume_L*(Bass_L*(Treble_L*pow(fs,3)*(-4.71528584636711e-17*fs + 1.57176194878902e-16) + fs*(pow(fs,2)*(4.71528584636711e-17*fs - 4.1400878565975e-15) + 1.34101391800936e-10)) + Middle_L*(Bass_L*pow(fs,3)*(6.60140018491395e-18*fs - 1.89303009112152e-14) + fs*(-2.06469324932415e-16*pow(fs,2) + 7.87887479009986e-12)) + Treble_L*fs*(1.47478089237439e-15*pow(fs,2) - 3.34417435912558e-13) + fs*(-1.47478089237439e-15*pow(fs,2) + 3.34417435912558e-13));\n\n    b4 = Volume_L*(Bass_L*(Treble_L*pow(fs,3)*(1.17882146159178e-17*fs - 7.85880974394511e-17) + fs*(fs*(fs*(-1.17882146159178e-17*fs + 2.07004392829875e-15) - 1.0070880757276e-11) + 6.70506959004678e-11)) + Middle_L*(Bass_L*pow(fs,2)*(fs*(-1.65035004622849e-18*fs + 9.46515045560758e-15) - 6.30276541464398e-14) + fs*(fs*(1.03234662466208e-16*fs - 5.91603840340603e-13) + 3.93943739504993e-12)) + Treble_L*fs*(fs*(-7.37390446187197e-16*fs + 2.99972440013567e-14) - 1.67208717956279e-13) + fs*(fs*(7.37390446187197e-16*fs - 2.99972440013567e-14) + 1.67208717956279e-13));\n\n    a0 = Bass_L*(Treble_L*(Treble_L*pow(fs,2)*(fs*(-6.53947709737567e-20*fs - 8.63258735389604e-18) - 9.72567351449023e-17) + fs*(fs*(fs*(5.86784894739014e-20*fs - 5.12285438072112e-16) - 6.87767642075504e-14) - 7.76108746456321e-13)) + fs*(fs*(fs*(2.95160491394304e-19*fs + 2.67064048181331e-15) + 3.79482593534319e-13) + 6.46231565548504e-12) + 2.61733091315125e-11) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(-4.86040672241183e-21*fs - 6.21913816572845e-20) + pow(fs,2)*(fs*(6.80456941137657e-21*fs - 3.86989777105262e-17) - 4.9628722562513e-16)) + fs*(fs*(fs*(2.8158557055486e-20*fs + 2.16252174019074e-16) + 4.38213044301358e-15) + 1.99261186829939e-14)) + Treble_L*(Treble_L*pow(fs,2)*(-3.04033952423208e-19*fs - 3.89026940579609e-18) + fs*(fs*(4.25647533392492e-19*fs - 2.42268872585805e-15) - 3.10692264109157e-14)) + fs*(fs*(1.76140761155593e-18*fs + 1.35192183493901e-14) + 2.58417996561413e-13) + 1.0469323652605e-12) + Treble_L*(Treble_L*fs*(fs*(-4.09065163112436e-18*fs - 3.1996842386608e-16) - 3.26835558922325e-15) + fs*(fs*(3.67052678836745e-18*fs - 3.2490595714095e-14) - 2.55967413440181e-12) - 2.61733091315125e-11) + fs*(fs*(1.8463230738282e-17*fs + 1.6533269438527e-13) + 1.28277858723121e-11) + 1.30866545657562e-10;\n\n    a1 = Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(2.61579083895027e-19*fs + 1.72651747077921e-17) + fs*(pow(fs,2)*(-2.34713957895606e-19*fs + 1.02457087614422e-15) - 1.55221749291264e-12)) + fs*(pow(fs,2)*(-1.18064196557721e-18*fs - 5.34128096362661e-15) + 1.29246313109701e-11) + 1.0469323652605e-10) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(1.94416268896473e-20*fs + 1.24382763314569e-19) + pow(fs,3)*(-2.72182776455063e-20*fs + 7.73979554210525e-17)) + fs*(pow(fs,2)*(-1.12634228221944e-19*fs - 4.32504348038148e-16) + 3.98522373659879e-14)) + Treble_L*(6.08067904846417e-19*Treble_L*pow(fs,3) + fs*(-8.51295066784983e-19*pow(fs,2) - 6.21384528218315e-14)) + fs*(-3.52281522311187e-18*pow(fs,2) + 5.16835993122826e-13) + 4.187729461042e-12) + Treble_L*(Treble_L*fs*(8.18130326224871e-18*pow(fs,2) - 6.5367111784465e-15) + fs*(-7.3410535767349e-18*pow(fs,2) - 5.11934826880362e-12) - 1.0469323652605e-10) + fs*(-3.69264614765639e-17*pow(fs,2) + 2.56555717446241e-11) + 5.2346618263025e-10;\n\n    a2 = Bass_L*(Treble_L*(Treble_L*pow(fs,2)*(-3.9236862584254e-19*pow(fs,2) + 1.94513470289805e-16) + pow(fs,2)*(3.52070936843408e-19*pow(fs,2) + 1.37553528415101e-13)) + pow(fs,2)*(1.77096294836582e-18*pow(fs,2) - 7.58965187068638e-13) + 1.57039854789075e-10) + Middle_L*(Bass_L*(Treble_L*(-2.9162440334471e-20*Treble_L*pow(fs,4) + pow(fs,2)*(4.08274164682594e-20*pow(fs,2) + 9.9257445125026e-16)) + pow(fs,2)*(1.68951342332916e-19*pow(fs,2) - 8.76426088602715e-15)) + Treble_L*(7.78053881159219e-18*Treble_L*pow(fs,2) + 4.84537745171611e-15*pow(fs,2)) - 2.70384366987801e-14*pow(fs,2) + 6.281594191563e-12) + Treble_L*(6.3993684773216e-16*Treble_L*pow(fs,2) + 6.498119142819e-14*pow(fs,2) - 1.57039854789075e-10) - 3.3066538877054e-13*pow(fs,2) + 7.85199273945375e-10;\n\n    a3 = Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(2.61579083895027e-19*fs - 1.72651747077921e-17) + fs*(pow(fs,2)*(-2.34713957895606e-19*fs - 1.02457087614422e-15) + 1.55221749291264e-12)) + fs*(pow(fs,2)*(-1.18064196557721e-18*fs + 5.34128096362661e-15) - 1.29246313109701e-11) + 1.0469323652605e-10) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(1.94416268896473e-20*fs - 1.24382763314569e-19) + pow(fs,3)*(-2.72182776455063e-20*fs - 7.73979554210525e-17)) + fs*(pow(fs,2)*(-1.12634228221944e-19*fs + 4.32504348038148e-16) - 3.98522373659879e-14)) + Treble_L*(-6.08067904846417e-19*Treble_L*pow(fs,3) + fs*(8.51295066784983e-19*pow(fs,2) + 6.21384528218315e-14)) + fs*(3.52281522311187e-18*pow(fs,2) - 5.16835993122826e-13) + 4.187729461042e-12) + Treble_L*(Treble_L*fs*(-8.18130326224871e-18*pow(fs,2) + 6.5367111784465e-15) + fs*(7.3410535767349e-18*pow(fs,2) + 5.11934826880362e-12) - 1.0469323652605e-10) + fs*(3.69264614765639e-17*pow(fs,2) - 2.56555717446241e-11) + 5.2346618263025e-10;\n\n    a4 = Bass_L*(Treble_L*(Treble_L*pow(fs,2)*(fs*(-6.53947709737567e-20*fs + 8.63258735389604e-18) - 9.72567351449023e-17) + fs*(fs*(fs*(5.86784894739014e-20*fs + 5.12285438072112e-16) - 6.87767642075504e-14) + 7.76108746456321e-13)) + fs*(fs*(fs*(2.95160491394304e-19*fs - 2.67064048181331e-15) + 3.79482593534319e-13) - 6.46231565548504e-12) + 2.61733091315125e-11) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(-4.86040672241183e-21*fs + 6.21913816572845e-20) + pow(fs,2)*(fs*(6.80456941137657e-21*fs + 3.86989777105262e-17) - 4.9628722562513e-16)) + fs*(fs*(fs*(2.8158557055486e-20*fs - 2.16252174019074e-16) + 4.38213044301358e-15) - 1.99261186829939e-14)) + Treble_L*(Treble_L*pow(fs,2)*(3.04033952423208e-19*fs - 3.89026940579609e-18) + fs*(fs*(-4.25647533392492e-19*fs - 2.42268872585805e-15) + 3.10692264109157e-14)) + fs*(fs*(-1.76140761155593e-18*fs + 1.35192183493901e-14) - 2.58417996561413e-13) + 1.0469323652605e-12) + Treble_L*(Treble_L*fs*(fs*(4.09065163112436e-18*fs - 3.1996842386608e-16) + 3.26835558922325e-15) + fs*(fs*(-3.67052678836745e-18*fs - 3.2490595714095e-14) + 2.55967413440181e-12) - 2.61733091315125e-11) + fs*(fs*(-1.8463230738282e-17*fs + 1.6533269438527e-13) - 1.28277858723121e-11) + 1.30866545657562e-10;\n};\n\nalembic_normclip = _<: ba.if(signbit(_), alembic_norm_neg_clip, alembic_norm_clip) :>_ with {\nsignbit(x) = (x < 0);alembic_norm_clip = gxt.alembic_normclip;alembic_norm_neg_clip = gxt.alembic_norm_negclip;\n};\n\nbright = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0)) : alembic_briteclip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n    Bass_L = vslider(\"Bass_L[name:Bass_L]\", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(3) : si.smooth(s);\n\n\n    Middle_L = vslider(\"Middle_L[name:Middle_L]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n\n    Volume_L = vslider(\"Volume_L[name:Volume_L]\", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(3) : si.smooth(s);\n\n\n    Treble_L = vslider(\"Treble_L[name:Treble_L]\", 0.5, 0, 1, 0.01) : Inverted(1) : si.smooth(s);\n\n    b0 = Volume_L*(Bass_L*(Treble_L*pow(fs,3)*(fs*(6.91874396840722e-22*fs + 2.88742248281528e-18) + 1.92187332455754e-17) + fs*(fs*(fs*(fs*(-6.91874396840722e-22*fs - 3.00430509368582e-18) - 1.09731017637039e-15) - 2.46677102772048e-12) - 1.63972596414378e-11)) + Middle_L*(Bass_L*pow(fs,2)*(fs*(fs*(-9.68624155577011e-23*fs - 9.59122413860399e-19) - 2.31840345387224e-15) - 1.54134240629515e-14) + fs*(fs*(fs*(-6.05905322850301e-21*fs - 5.99684930400747e-17) - 1.44908038300355e-13) - 9.63390117586717e-13)) + Treble_L*fs*(fs*(fs*(4.32789516321643e-20*fs + 1.82089564663e-16) + 7.34564519198978e-15) + 4.08909217990967e-14) + Volume_L*(Bass_L*(Treble_L*pow(fs,4)*(-6.91874396840722e-22*fs - 4.6124959789381e-21) + pow(fs,2)*(fs*(fs*(6.91874396840722e-22*fs + 1.21495106849477e-19) + 5.91080564497569e-16) + 3.93534231394506e-15)) + Middle_L*(Bass_L*pow(fs,3)*(fs*(9.68624155577011e-23*fs + 5.55529015703311e-19) + 3.69922177510836e-18) + pow(fs,2)*(fs*(6.05905322850301e-21*fs + 3.47224379213122e-17) + 2.31213628220812e-16)) + Treble_L*pow(fs,2)*(fs*(-4.32789516321643e-20*fs - 1.76059952898192e-18) - 9.8138212317832e-18) + pow(fs,2)*(fs*(4.32789516321643e-20*fs + 1.76059952898192e-18) + 9.8138212317832e-18)) + fs*(fs*(fs*(-4.32789516321643e-20*fs - 1.82089564663e-16) - 7.34564519198978e-15) - 4.08909217990967e-14));\n\n    b1 = Volume_L*(Bass_L*(Treble_L*pow(fs,3)*(fs*(-3.45937198420361e-21*fs - 8.66226744844584e-18) - 1.92187332455754e-17) + fs*(fs*(fs*(fs*(3.45937198420361e-21*fs + 9.01291528105746e-18) + 1.09731017637039e-15) - 2.46677102772048e-12) - 4.91917789243133e-11)) + Middle_L*(Bass_L*pow(fs,2)*(fs*(fs*(4.84312077788506e-22*fs + 2.8773672415812e-18) + 2.31840345387224e-15) - 1.54134240629515e-14) + fs*(fs*(fs*(1.8177159685509e-20*fs + 5.99684930400747e-17) - 1.44908038300355e-13) - 2.89017035276015e-12)) + Treble_L*fs*(fs*(fs*(-1.29836854896493e-19*fs - 1.82089564663e-16) + 7.34564519198978e-15) + 1.2267276539729e-13) + Volume_L*(Bass_L*(Treble_L*pow(fs,4)*(3.45937198420361e-21*fs + 1.38374879368143e-20) + pow(fs,2)*(fs*(fs*(-3.45937198420361e-21*fs - 3.64485320548431e-19) - 5.91080564497569e-16) + 3.93534231394506e-15)) + Middle_L*(Bass_L*pow(fs,3)*(fs*(-4.84312077788506e-22*fs - 1.66658704710993e-18) - 3.69922177510836e-18) + pow(fs,2)*(fs*(-1.8177159685509e-20*fs - 3.47224379213122e-17) + 2.31213628220812e-16)) + Treble_L*pow(fs,2)*(fs*(1.29836854896493e-19*fs + 1.76059952898192e-18) - 9.8138212317832e-18) + pow(fs,2)*(fs*(-1.29836854896493e-19*fs - 1.76059952898192e-18) + 9.8138212317832e-18)) + fs*(fs*(fs*(1.29836854896493e-19*fs + 1.82089564663e-16) - 7.34564519198978e-15) - 1.2267276539729e-13));\n\n    b2 = Volume_L*(Bass_L*(Treble_L*pow(fs,3)*(fs*(6.91874396840722e-21*fs + 5.77484496563056e-18) - 3.84374664911509e-17) + fs*(fs*(fs*(fs*(-6.91874396840722e-21*fs - 6.00861018737164e-18) + 2.19462035274078e-15) + 4.93354205544096e-12) - 3.27945192828755e-11)) + Middle_L*(Bass_L*pow(fs,2)*(fs*(fs*(-9.68624155577011e-22*fs - 1.9182448277208e-18) + 4.63680690774447e-15) + 3.0826848125903e-14) + fs*(fs*(fs*(-1.2118106457006e-20*fs + 1.19936986080149e-16) + 2.8981607660071e-13) - 1.92678023517343e-12)) + Treble_L*fs*(fs*(fs*(8.65579032643287e-20*fs - 3.64179129326e-16) - 1.46912903839796e-14) + 8.17818435981933e-14) + Volume_L*(Bass_L*(Treble_L*pow(fs,4)*(-6.91874396840722e-21*fs - 9.2249919578762e-21) + pow(fs,2)*(fs*(fs*(6.91874396840722e-21*fs + 2.42990213698954e-19) - 1.18216112899514e-15) - 7.87068462789012e-15)) + Middle_L*(Bass_L*pow(fs,3)*(fs*(9.68624155577011e-22*fs + 1.11105803140662e-18) - 7.39844355021672e-18) + pow(fs,2)*(fs*(1.2118106457006e-20*fs - 6.94448758426244e-17) - 4.62427256441624e-16)) + Treble_L*pow(fs,2)*(fs*(-8.65579032643287e-20*fs + 3.52119905796384e-18) + 1.96276424635664e-17) + pow(fs,2)*(fs*(8.65579032643287e-20*fs - 3.52119905796384e-18) - 1.96276424635664e-17)) + fs*(fs*(fs*(-8.65579032643287e-20*fs + 3.64179129326e-16) + 1.46912903839796e-14) - 8.17818435981933e-14));\n\n    b3 = Volume_L*(Bass_L*(Treble_L*pow(fs,3)*(fs*(-6.91874396840722e-21*fs + 5.77484496563056e-18) + 3.84374664911509e-17) + fs*(fs*(fs*(fs*(6.91874396840722e-21*fs - 6.00861018737164e-18) - 2.19462035274078e-15) + 4.93354205544096e-12) + 3.27945192828755e-11)) + Middle_L*(Bass_L*pow(fs,2)*(fs*(fs*(9.68624155577011e-22*fs - 1.9182448277208e-18) - 4.63680690774447e-15) + 3.0826848125903e-14) + fs*(fs*(fs*(-1.2118106457006e-20*fs - 1.19936986080149e-16) + 2.8981607660071e-13) + 1.92678023517343e-12)) + Treble_L*fs*(fs*(fs*(8.65579032643287e-20*fs + 3.64179129326e-16) - 1.46912903839796e-14) - 8.17818435981933e-14) + Volume_L*(Bass_L*(Treble_L*pow(fs,4)*(6.91874396840722e-21*fs - 9.2249919578762e-21) + pow(fs,2)*(fs*(fs*(-6.91874396840722e-21*fs + 2.42990213698954e-19) + 1.18216112899514e-15) - 7.87068462789012e-15)) + Middle_L*(Bass_L*pow(fs,3)*(fs*(-9.68624155577011e-22*fs + 1.11105803140662e-18) + 7.39844355021672e-18) + pow(fs,2)*(fs*(1.2118106457006e-20*fs + 6.94448758426244e-17) - 4.62427256441624e-16)) + Treble_L*pow(fs,2)*(fs*(-8.65579032643287e-20*fs - 3.52119905796384e-18) + 1.96276424635664e-17) + pow(fs,2)*(fs*(8.65579032643287e-20*fs + 3.52119905796384e-18) - 1.96276424635664e-17)) + fs*(fs*(fs*(-8.65579032643287e-20*fs - 3.64179129326e-16) + 1.46912903839796e-14) + 8.17818435981933e-14));\n\n    b4 = Volume_L*(Bass_L*(Treble_L*pow(fs,3)*(fs*(3.45937198420361e-21*fs - 8.66226744844584e-18) + 1.92187332455754e-17) + fs*(fs*(fs*(fs*(-3.45937198420361e-21*fs + 9.01291528105746e-18) - 1.09731017637039e-15) - 2.46677102772048e-12) + 4.91917789243133e-11)) + Middle_L*(Bass_L*pow(fs,2)*(fs*(fs*(-4.84312077788506e-22*fs + 2.8773672415812e-18) - 2.31840345387224e-15) - 1.54134240629515e-14) + fs*(fs*(fs*(1.8177159685509e-20*fs - 5.99684930400747e-17) - 1.44908038300355e-13) + 2.89017035276015e-12)) + Treble_L*fs*(fs*(fs*(-1.29836854896493e-19*fs + 1.82089564663e-16) + 7.34564519198978e-15) - 1.2267276539729e-13) + Volume_L*(Bass_L*(Treble_L*pow(fs,4)*(-3.45937198420361e-21*fs + 1.38374879368143e-20) + pow(fs,2)*(fs*(fs*(3.45937198420361e-21*fs - 3.64485320548431e-19) + 5.91080564497569e-16) + 3.93534231394506e-15)) + Middle_L*(Bass_L*pow(fs,3)*(fs*(4.84312077788506e-22*fs - 1.66658704710993e-18) + 3.69922177510836e-18) + pow(fs,2)*(fs*(-1.8177159685509e-20*fs + 3.47224379213122e-17) + 2.31213628220812e-16)) + Treble_L*pow(fs,2)*(fs*(1.29836854896493e-19*fs - 1.76059952898192e-18) - 9.8138212317832e-18) + pow(fs,2)*(fs*(-1.29836854896493e-19*fs + 1.76059952898192e-18) + 9.8138212317832e-18)) + fs*(fs*(fs*(1.29836854896493e-19*fs - 1.82089564663e-16) - 7.34564519198978e-15) + 1.2267276539729e-13));\n\n    b5 = Volume_L*(Bass_L*(Treble_L*pow(fs,3)*(fs*(-6.91874396840722e-22*fs + 2.88742248281528e-18) - 1.92187332455754e-17) + fs*(fs*(fs*(fs*(6.91874396840722e-22*fs - 3.00430509368582e-18) + 1.09731017637039e-15) - 2.46677102772048e-12) + 1.63972596414378e-11)) + Middle_L*(Bass_L*pow(fs,2)*(fs*(fs*(9.68624155577011e-23*fs - 9.59122413860399e-19) + 2.31840345387224e-15) - 1.54134240629515e-14) + fs*(fs*(fs*(-6.05905322850301e-21*fs + 5.99684930400747e-17) - 1.44908038300355e-13) + 9.63390117586717e-13)) + Treble_L*fs*(fs*(fs*(4.32789516321643e-20*fs - 1.82089564663e-16) + 7.34564519198978e-15) - 4.08909217990967e-14) + Volume_L*(Bass_L*(Treble_L*pow(fs,4)*(6.91874396840722e-22*fs - 4.6124959789381e-21) + pow(fs,2)*(fs*(fs*(-6.91874396840722e-22*fs + 1.21495106849477e-19) - 5.91080564497569e-16) + 3.93534231394506e-15)) + Middle_L*(Bass_L*pow(fs,3)*(fs*(-9.68624155577011e-23*fs + 5.55529015703311e-19) - 3.69922177510836e-18) + pow(fs,2)*(fs*(6.05905322850301e-21*fs - 3.47224379213122e-17) + 2.31213628220812e-16)) + Treble_L*pow(fs,2)*(fs*(-4.32789516321643e-20*fs + 1.76059952898192e-18) - 9.8138212317832e-18) + pow(fs,2)*(fs*(4.32789516321643e-20*fs - 1.76059952898192e-18) + 9.8138212317832e-18)) + fs*(fs*(fs*(-4.32789516321643e-20*fs + 1.82089564663e-16) - 7.34564519198978e-15) + 4.08909217990967e-14));\n\n    a0 = Bass_L*(Treble_L*(Treble_L*pow(fs,2)*(fs*(fs*(-3.83815344221861e-24*fs - 1.64989702525133e-20) - 2.11680921042765e-18) - 2.37841533602171e-17) + fs*(fs*(fs*(fs*(3.44396099549798e-24*fs - 1.57172472604439e-20) - 1.29316168998563e-16) - 1.68649232502658e-14) - 1.89797543814532e-13)) + fs*(fs*(fs*(fs*(3.9419244672063e-25*fs + 1.03020062404785e-19) + 6.59092588471003e-16) + 9.2998714565051e-14) + 1.58189673716889e-12) + 6.40068780224617e-12) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(-2.85267232541704e-25*fs - 1.19226360837823e-21) - 1.52089143936082e-20) + pow(fs,2)*(fs*(fs*(3.99374125558385e-25*fs - 6.07263463953272e-22) - 9.49297111470724e-18) - 1.21367136860993e-16)) + fs*(fs*(fs*(fs*(5.51869425408882e-26*fs + 1.04066508425183e-20) + 5.30246139994882e-17) + 1.0728203737318e-15) + 4.87293617171206e-15)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(-1.78443758228215e-23*fs - 7.45798938006809e-20) - 9.51366134408682e-19) + fs*(fs*(fs*(2.49821261519501e-23*fs - 3.81003746381788e-20) - 5.94292545384613e-16) - 7.59798531833873e-15)) + fs*(fs*(fs*(3.45211938447258e-24*fs + 6.50953455217104e-19) + 3.31397583073083e-15) + 6.32576187894833e-14) + 2.56027512089847e-13) + Treble_L*(Treble_L*fs*(fs*(fs*(-2.40088747236654e-22*fs - 1.01914938263382e-18) - 7.84401701489674e-17) - 7.99276990472601e-16) + fs*(fs*(fs*(2.15430751633278e-22*fs - 1.00931167420926e-18) - 8.09581504534201e-15) - 6.27504999577649e-13) - 6.40068780224617e-12) + Volume_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(3.83815344221861e-24*fs + 5.06664243269087e-22) + 5.70819680645209e-21) + pow(fs,2)*(fs*(fs*(-3.44396099549798e-24*fs + 3.00670847416855e-20) + 4.03664924154006e-18) + 4.55514105154877e-17)) + fs*(fs*(fs*(fs*(1.65351911090363e-23*fs + 9.5068384229614e-20) + 1.02988983768651e-17) - 1.30486302011578e-17) - 1.53616507253908e-15)) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,4)*(2.85267232541704e-25*fs + 3.65013945446597e-24) + pow(fs,3)*(fs*(-3.99374125558385e-25*fs + 2.27132232044654e-21) + 2.91281128466384e-20)) + pow(fs,2)*(fs*(fs*(1.54230955969265e-24*fs + 5.65134377825805e-21) - 2.30032611736055e-20) - 1.1695046812109e-18)) + Treble_L*(Treble_L*pow(fs,3)*(1.78443758228215e-23*fs + 2.28327872258084e-22) + pow(fs,2)*(fs*(-2.49821261519501e-23*fs + 1.42192566937971e-19) + 1.82351647640129e-18)) + fs*(fs*(fs*(9.64763852233277e-23*fs + 3.53068929659391e-19) - 5.29245486955245e-19) - 6.14466029015632e-17)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(2.40088747236654e-22*fs + 1.8779602481101e-20) + 1.91826477713424e-19) + fs*(fs*(fs*(-2.15430751633278e-22*fs + 1.90693980601459e-18) + 1.50232520281226e-16) + 1.53616507253908e-15)) + Volume_L*(Bass_L*pow(fs,2)*(fs*(fs*(-1.6929383555757e-23*fs - 1.25906879957409e-19) - 1.62857548261884e-17) - 1.83118953550983e-16) + Middle_L*(Bass_L*pow(fs,3)*(fs*(-1.59749650223354e-24*fs - 9.17181360088287e-21) - 1.17096473699268e-19) + pow(fs,2)*(fs*(-9.99285046078002e-23*fs - 5.73269784908691e-19) - 7.31891791891218e-18)) + fs*(fs*(fs*(-1.05898697136012e-21*fs - 7.77799604390716e-18) - 6.02464692946613e-16) - 6.14466029015632e-15)) + fs*(fs*(fs*(1.03432897575674e-21*fs + 5.85227663541147e-18) + 4.52040346187673e-16) + 4.60849521761724e-15)) + fs*(fs*(fs*(2.46579956033756e-23*fs + 6.44090677084358e-18) + 4.05825720651041e-14) + 3.13857383051234e-12) + 3.20034390112309e-11;\n\n    a1 = Bass_L*(Treble_L*(Treble_L*pow(fs,2)*(fs*(fs*(1.91907672110931e-23*fs + 4.94969107575399e-20) + 2.11680921042765e-18) - 2.37841533602171e-17) + fs*(fs*(fs*(fs*(-1.72198049774899e-23*fs + 4.71517417813316e-20) + 1.29316168998563e-16) - 1.68649232502658e-14) - 5.69392631443596e-13)) + fs*(fs*(fs*(fs*(-1.97096223360315e-24*fs - 3.09060187214354e-19) - 6.59092588471003e-16) + 9.2998714565051e-14) + 4.74569021150667e-12) + 3.20034390112309e-11) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(1.42633616270852e-24*fs + 3.5767908251347e-21) + 1.52089143936082e-20) + pow(fs,2)*(fs*(fs*(-1.99687062779193e-24*fs + 1.82179039185982e-21) + 9.49297111470724e-18) - 1.21367136860993e-16)) + fs*(fs*(fs*(fs*(-2.75934712704441e-25*fs - 3.12199525275548e-20) - 5.30246139994882e-17) + 1.0728203737318e-15) + 1.46188085151362e-14)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(5.35331274684644e-23*fs + 7.45798938006809e-20) - 9.51366134408682e-19) + fs*(fs*(fs*(-7.49463784558502e-23*fs + 3.81003746381788e-20) - 5.94292545384613e-16) - 2.27939559550162e-14)) + fs*(fs*(fs*(-1.03563581534178e-23*fs - 6.50953455217104e-19) + 3.31397583073083e-15) + 1.8977285636845e-13) + 1.28013756044923e-12) + Treble_L*(Treble_L*fs*(fs*(fs*(7.20266241709961e-22*fs + 1.01914938263382e-18) - 7.84401701489674e-17) - 2.3978309714178e-15) + fs*(fs*(fs*(-6.46292254899834e-22*fs + 1.00931167420926e-18) - 8.09581504534201e-15) - 1.88251499873295e-12) - 3.20034390112309e-11) + Volume_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(-1.91907672110931e-23*fs - 1.51999272980726e-21) - 5.70819680645209e-21) + pow(fs,2)*(fs*(fs*(1.72198049774899e-23*fs - 9.02012542250564e-20) - 4.03664924154006e-18) + 4.55514105154877e-17)) + fs*(fs*(fs*(fs*(-8.26759555451817e-23*fs - 2.85205152688842e-19) - 1.02988983768651e-17) - 1.30486302011578e-17) - 4.60849521761724e-15)) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,4)*(-1.42633616270852e-24*fs - 1.09504183633979e-23) + pow(fs,3)*(fs*(1.99687062779193e-24*fs - 6.81396696133963e-21) - 2.91281128466384e-20)) + pow(fs,2)*(fs*(fs*(-7.71154779846327e-24*fs - 1.69540313347742e-20) + 2.30032611736055e-20) - 1.1695046812109e-18)) + Treble_L*(Treble_L*pow(fs,3)*(-5.35331274684644e-23*fs - 2.28327872258084e-22) + pow(fs,2)*(fs*(7.49463784558502e-23*fs - 1.42192566937971e-19) + 1.82351647640129e-18)) + fs*(fs*(fs*(-2.89429155669983e-22*fs - 3.53068929659391e-19) - 5.29245486955245e-19) - 1.8433980870469e-16)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(-7.20266241709961e-22*fs - 1.8779602481101e-20) + 1.91826477713424e-19) + fs*(fs*(fs*(6.46292254899834e-22*fs - 1.90693980601459e-18) + 1.50232520281226e-16) + 4.60849521761724e-15)) + Volume_L*(Bass_L*pow(fs,2)*(fs*(fs*(8.46469177787849e-23*fs + 3.77720639872226e-19) + 1.62857548261884e-17) - 1.83118953550983e-16) + Middle_L*(Bass_L*pow(fs,3)*(fs*(7.98748251116771e-24*fs + 2.75154408026486e-20) + 1.17096473699268e-19) + pow(fs,2)*(fs*(2.99785513823401e-22*fs + 5.73269784908691e-19) - 7.31891791891218e-18)) + fs*(fs*(fs*(3.17696091408035e-21*fs + 7.77799604390716e-18) - 6.02464692946613e-16) - 1.8433980870469e-14)) + fs*(fs*(fs*(-3.10298692727022e-21*fs - 5.85227663541147e-18) + 4.52040346187673e-16) + 1.38254856528517e-14)) + fs*(fs*(fs*(-7.39739868101268e-23*fs - 6.44090677084358e-18) + 4.05825720651041e-14) + 9.41572149153703e-12) + 1.60017195056154e-10;\n\n    a2 = Bass_L*(Treble_L*(Treble_L*pow(fs,2)*(fs*(fs*(-3.83815344221861e-23*fs - 3.29979405050266e-20) + 4.23361842085529e-18) + 4.75683067204341e-17) + fs*(fs*(fs*(fs*(3.44396099549798e-23*fs - 3.14344945208878e-20) + 2.58632337997126e-16) + 3.37298465005315e-14) - 3.79595087629064e-13)) + fs*(fs*(fs*(fs*(3.9419244672063e-24*fs + 2.06040124809569e-19) - 1.31818517694201e-15) - 1.85997429130102e-13) + 3.16379347433778e-12) + 6.40068780224617e-11) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(-2.85267232541704e-24*fs - 2.38452721675646e-21) + 3.04178287872164e-20) + pow(fs,2)*(fs*(fs*(3.99374125558385e-24*fs - 1.21452692790654e-21) + 1.89859422294145e-17) + 2.42734273721987e-16)) + fs*(fs*(fs*(fs*(5.51869425408882e-25*fs + 2.08133016850365e-20) - 1.06049227998976e-16) - 2.1456407474636e-15) + 9.74587234342413e-15)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(-3.56887516456429e-23*fs + 1.49159787601362e-19) + 1.90273226881736e-18) + fs*(fs*(fs*(4.99642523039001e-23*fs + 7.62007492763576e-20) + 1.18858509076923e-15) - 1.51959706366775e-14)) + fs*(fs*(fs*(6.90423876894517e-24*fs - 1.30190691043421e-18) - 6.62795166146167e-15) + 1.26515237578967e-13) + 2.56027512089847e-12) + Treble_L*(Treble_L*fs*(fs*(fs*(-4.80177494473307e-22*fs + 2.03829876526765e-18) + 1.56880340297935e-16) - 1.5985539809452e-15) + fs*(fs*(fs*(4.30861503266556e-22*fs + 2.01862334841852e-18) + 1.6191630090684e-14) - 1.2550099991553e-12) - 6.40068780224617e-11) + Volume_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(3.83815344221861e-23*fs + 1.01332848653817e-21) - 1.14163936129042e-20) + pow(fs,2)*(fs*(fs*(-3.44396099549798e-23*fs + 6.01341694833709e-20) - 8.07329848308013e-18) - 9.11028210309754e-17)) + fs*(fs*(fs*(fs*(1.65351911090363e-22*fs + 1.90136768459228e-19) - 2.05977967537302e-17) + 2.60972604023156e-17) - 3.07233014507816e-15)) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,4)*(2.85267232541704e-24*fs + 7.30027890893193e-24) + pow(fs,3)*(fs*(-3.99374125558385e-24*fs + 4.54264464089309e-21) - 5.82562256932768e-20)) + pow(fs,2)*(fs*(fs*(1.54230955969265e-23*fs + 1.13026875565161e-20) + 4.60065223472111e-20) + 2.33900936242179e-18)) + Treble_L*(Treble_L*pow(fs,3)*(3.56887516456429e-23*fs - 4.56655744516168e-22) + pow(fs,2)*(fs*(-4.99642523039001e-23*fs - 2.84385133875941e-19) - 3.64703295280259e-18)) + fs*(fs*(fs*(1.92952770446655e-22*fs - 7.06137859318782e-19) + 1.05849097391049e-18) - 1.22893205803126e-16)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(4.80177494473307e-22*fs - 3.75592049622019e-20) - 3.83652955426848e-19) + fs*(fs*(fs*(-4.30861503266556e-22*fs - 3.81387961202917e-18) - 3.00465040562453e-16) + 3.07233014507816e-15)) + Volume_L*(Bass_L*pow(fs,2)*(fs*(fs*(-1.6929383555757e-22*fs - 2.51813759914817e-19) + 3.25715096523769e-17) + 3.66237907101966e-16) + Middle_L*(Bass_L*pow(fs,3)*(fs*(-1.59749650223354e-23*fs - 1.83436272017657e-20) + 2.34192947398536e-19) + pow(fs,2)*(fs*(-1.998570092156e-22*fs + 1.14653956981738e-18) + 1.46378358378244e-17)) + fs*(fs*(fs*(-2.11797394272023e-21*fs + 1.55559920878143e-17) + 1.20492938589323e-15) - 1.22893205803126e-14)) + fs*(fs*(fs*(2.06865795151348e-21*fs - 1.17045532708229e-17) - 9.04080692375347e-16) + 9.21699043523448e-15)) + fs*(fs*(fs*(4.93159912067512e-23*fs - 1.28818135416872e-17) - 8.11651441302083e-14) + 6.27714766102469e-12) + 3.20034390112308e-10;\n\n    a3 = Bass_L*(Treble_L*(Treble_L*pow(fs,2)*(fs*(fs*(3.83815344221861e-23*fs - 3.29979405050266e-20) - 4.23361842085529e-18) + 4.75683067204341e-17) + fs*(fs*(fs*(fs*(-3.44396099549798e-23*fs - 3.14344945208878e-20) - 2.58632337997126e-16) + 3.37298465005315e-14) + 3.79595087629064e-13)) + fs*(fs*(fs*(fs*(-3.9419244672063e-24*fs + 2.06040124809569e-19) + 1.31818517694201e-15) - 1.85997429130102e-13) - 3.16379347433778e-12) + 6.40068780224617e-11) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(2.85267232541704e-24*fs - 2.38452721675646e-21) - 3.04178287872164e-20) + pow(fs,2)*(fs*(fs*(-3.99374125558385e-24*fs - 1.21452692790654e-21) - 1.89859422294145e-17) + 2.42734273721987e-16)) + fs*(fs*(fs*(fs*(-5.51869425408882e-25*fs + 2.08133016850365e-20) + 1.06049227998976e-16) - 2.1456407474636e-15) - 9.74587234342413e-15)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(-3.56887516456429e-23*fs - 1.49159787601362e-19) + 1.90273226881736e-18) + fs*(fs*(fs*(4.99642523039001e-23*fs - 7.62007492763576e-20) + 1.18858509076923e-15) + 1.51959706366775e-14)) + fs*(fs*(fs*(6.90423876894517e-24*fs + 1.30190691043421e-18) - 6.62795166146167e-15) - 1.26515237578967e-13) + 2.56027512089847e-12) + Treble_L*(Treble_L*fs*(fs*(fs*(-4.80177494473307e-22*fs - 2.03829876526765e-18) + 1.56880340297935e-16) + 1.5985539809452e-15) + fs*(fs*(fs*(4.30861503266556e-22*fs - 2.01862334841852e-18) + 1.6191630090684e-14) + 1.2550099991553e-12) - 6.40068780224617e-11) + Volume_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(-3.83815344221861e-23*fs + 1.01332848653817e-21) + 1.14163936129042e-20) + pow(fs,2)*(fs*(fs*(3.44396099549798e-23*fs + 6.01341694833709e-20) + 8.07329848308013e-18) - 9.11028210309754e-17)) + fs*(fs*(fs*(fs*(-1.65351911090363e-22*fs + 1.90136768459228e-19) + 2.05977967537302e-17) + 2.60972604023156e-17) + 3.07233014507816e-15)) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,4)*(-2.85267232541704e-24*fs + 7.30027890893193e-24) + pow(fs,3)*(fs*(3.99374125558385e-24*fs + 4.54264464089309e-21) + 5.82562256932768e-20)) + pow(fs,2)*(fs*(fs*(-1.54230955969265e-23*fs + 1.13026875565161e-20) - 4.60065223472111e-20) + 2.33900936242179e-18)) + Treble_L*(Treble_L*pow(fs,3)*(3.56887516456429e-23*fs + 4.56655744516168e-22) + pow(fs,2)*(fs*(-4.99642523039001e-23*fs + 2.84385133875941e-19) - 3.64703295280259e-18)) + fs*(fs*(fs*(1.92952770446655e-22*fs + 7.06137859318782e-19) + 1.05849097391049e-18) + 1.22893205803126e-16)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(4.80177494473307e-22*fs + 3.75592049622019e-20) - 3.83652955426848e-19) + fs*(fs*(fs*(-4.30861503266556e-22*fs + 3.81387961202917e-18) - 3.00465040562453e-16) - 3.07233014507816e-15)) + Volume_L*(Bass_L*pow(fs,2)*(fs*(fs*(1.6929383555757e-22*fs - 2.51813759914817e-19) - 3.25715096523769e-17) + 3.66237907101966e-16) + Middle_L*(Bass_L*pow(fs,3)*(fs*(1.59749650223354e-23*fs - 1.83436272017657e-20) - 2.34192947398536e-19) + pow(fs,2)*(fs*(-1.998570092156e-22*fs - 1.14653956981738e-18) + 1.46378358378244e-17)) + fs*(fs*(fs*(-2.11797394272023e-21*fs - 1.55559920878143e-17) + 1.20492938589323e-15) + 1.22893205803126e-14)) + fs*(fs*(fs*(2.06865795151348e-21*fs + 1.17045532708229e-17) - 9.04080692375347e-16) - 9.21699043523448e-15)) + fs*(fs*(fs*(4.93159912067512e-23*fs + 1.28818135416872e-17) - 8.11651441302083e-14) - 6.27714766102469e-12) + 3.20034390112308e-10;\n\n    a4 = Bass_L*(Treble_L*(Treble_L*pow(fs,2)*(fs*(fs*(-1.91907672110931e-23*fs + 4.94969107575399e-20) - 2.11680921042765e-18) - 2.37841533602171e-17) + fs*(fs*(fs*(fs*(1.72198049774899e-23*fs + 4.71517417813316e-20) - 1.29316168998563e-16) - 1.68649232502658e-14) + 5.69392631443596e-13)) + fs*(fs*(fs*(fs*(1.97096223360315e-24*fs - 3.09060187214354e-19) + 6.59092588471003e-16) + 9.2998714565051e-14) - 4.74569021150667e-12) + 3.20034390112309e-11) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(-1.42633616270852e-24*fs + 3.5767908251347e-21) - 1.52089143936082e-20) + pow(fs,2)*(fs*(fs*(1.99687062779193e-24*fs + 1.82179039185982e-21) - 9.49297111470724e-18) - 1.21367136860993e-16)) + fs*(fs*(fs*(fs*(2.75934712704441e-25*fs - 3.12199525275548e-20) + 5.30246139994882e-17) + 1.0728203737318e-15) - 1.46188085151362e-14)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(5.35331274684644e-23*fs - 7.45798938006809e-20) - 9.51366134408682e-19) + fs*(fs*(fs*(-7.49463784558502e-23*fs - 3.81003746381788e-20) - 5.94292545384613e-16) + 2.27939559550162e-14)) + fs*(fs*(fs*(-1.03563581534178e-23*fs + 6.50953455217104e-19) + 3.31397583073083e-15) - 1.8977285636845e-13) + 1.28013756044923e-12) + Treble_L*(Treble_L*fs*(fs*(fs*(7.20266241709961e-22*fs - 1.01914938263382e-18) - 7.84401701489674e-17) + 2.3978309714178e-15) + fs*(fs*(fs*(-6.46292254899834e-22*fs - 1.00931167420926e-18) - 8.09581504534201e-15) + 1.88251499873295e-12) - 3.20034390112309e-11) + Volume_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(1.91907672110931e-23*fs - 1.51999272980726e-21) + 5.70819680645209e-21) + pow(fs,2)*(fs*(fs*(-1.72198049774899e-23*fs - 9.02012542250564e-20) + 4.03664924154006e-18) + 4.55514105154877e-17)) + fs*(fs*(fs*(fs*(8.26759555451817e-23*fs - 2.85205152688842e-19) + 1.02988983768651e-17) - 1.30486302011578e-17) + 4.60849521761724e-15)) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,4)*(1.42633616270852e-24*fs - 1.09504183633979e-23) + pow(fs,3)*(fs*(-1.99687062779193e-24*fs - 6.81396696133963e-21) + 2.91281128466384e-20)) + pow(fs,2)*(fs*(fs*(7.71154779846327e-24*fs - 1.69540313347742e-20) - 2.30032611736055e-20) - 1.1695046812109e-18)) + Treble_L*(Treble_L*pow(fs,3)*(-5.35331274684644e-23*fs + 2.28327872258084e-22) + pow(fs,2)*(fs*(7.49463784558502e-23*fs + 1.42192566937971e-19) + 1.82351647640129e-18)) + fs*(fs*(fs*(-2.89429155669983e-22*fs + 3.53068929659391e-19) - 5.29245486955245e-19) + 1.8433980870469e-16)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(-7.20266241709961e-22*fs + 1.8779602481101e-20) + 1.91826477713424e-19) + fs*(fs*(fs*(6.46292254899834e-22*fs + 1.90693980601459e-18) + 1.50232520281226e-16) - 4.60849521761724e-15)) + Volume_L*(Bass_L*pow(fs,2)*(fs*(fs*(-8.46469177787849e-23*fs + 3.77720639872226e-19) - 1.62857548261884e-17) - 1.83118953550983e-16) + Middle_L*(Bass_L*pow(fs,3)*(fs*(-7.98748251116771e-24*fs + 2.75154408026486e-20) - 1.17096473699268e-19) + pow(fs,2)*(fs*(2.99785513823401e-22*fs - 5.73269784908691e-19) - 7.31891791891218e-18)) + fs*(fs*(fs*(3.17696091408035e-21*fs - 7.77799604390716e-18) - 6.02464692946613e-16) + 1.8433980870469e-14)) + fs*(fs*(fs*(-3.10298692727022e-21*fs + 5.85227663541147e-18) + 4.52040346187673e-16) - 1.38254856528517e-14)) + fs*(fs*(fs*(-7.39739868101268e-23*fs + 6.44090677084358e-18) + 4.05825720651041e-14) - 9.41572149153703e-12) + 1.60017195056154e-10;\n\n    a5 = Bass_L*(Treble_L*(Treble_L*pow(fs,2)*(fs*(fs*(3.83815344221861e-24*fs - 1.64989702525133e-20) + 2.11680921042765e-18) - 2.37841533602171e-17) + fs*(fs*(fs*(fs*(-3.44396099549798e-24*fs - 1.57172472604439e-20) + 1.29316168998563e-16) - 1.68649232502658e-14) + 1.89797543814532e-13)) + fs*(fs*(fs*(fs*(-3.9419244672063e-25*fs + 1.03020062404785e-19) - 6.59092588471003e-16) + 9.2998714565051e-14) - 1.58189673716889e-12) + 6.40068780224617e-12) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(2.85267232541704e-25*fs - 1.19226360837823e-21) + 1.52089143936082e-20) + pow(fs,2)*(fs*(fs*(-3.99374125558385e-25*fs - 6.07263463953272e-22) + 9.49297111470724e-18) - 1.21367136860993e-16)) + fs*(fs*(fs*(fs*(-5.51869425408882e-26*fs + 1.04066508425183e-20) - 5.30246139994882e-17) + 1.0728203737318e-15) - 4.87293617171206e-15)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(-1.78443758228215e-23*fs + 7.45798938006809e-20) - 9.51366134408682e-19) + fs*(fs*(fs*(2.49821261519501e-23*fs + 3.81003746381788e-20) - 5.94292545384613e-16) + 7.59798531833873e-15)) + fs*(fs*(fs*(3.45211938447258e-24*fs - 6.50953455217104e-19) + 3.31397583073083e-15) - 6.32576187894833e-14) + 2.56027512089847e-13) + Treble_L*(Treble_L*fs*(fs*(fs*(-2.40088747236654e-22*fs + 1.01914938263382e-18) - 7.84401701489674e-17) + 7.99276990472601e-16) + fs*(fs*(fs*(2.15430751633278e-22*fs + 1.00931167420926e-18) - 8.09581504534201e-15) + 6.27504999577649e-13) - 6.40068780224617e-12) + Volume_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,3)*(fs*(-3.83815344221861e-24*fs + 5.06664243269087e-22) - 5.70819680645209e-21) + pow(fs,2)*(fs*(fs*(3.44396099549798e-24*fs + 3.00670847416855e-20) - 4.03664924154006e-18) + 4.55514105154877e-17)) + fs*(fs*(fs*(fs*(-1.65351911090363e-23*fs + 9.5068384229614e-20) - 1.02988983768651e-17) - 1.30486302011578e-17) + 1.53616507253908e-15)) + Middle_L*(Bass_L*(Treble_L*(Treble_L*pow(fs,4)*(-2.85267232541704e-25*fs + 3.65013945446597e-24) + pow(fs,3)*(fs*(3.99374125558385e-25*fs + 2.27132232044654e-21) - 2.91281128466384e-20)) + pow(fs,2)*(fs*(fs*(-1.54230955969265e-24*fs + 5.65134377825805e-21) + 2.30032611736055e-20) - 1.1695046812109e-18)) + Treble_L*(Treble_L*pow(fs,3)*(1.78443758228215e-23*fs - 2.28327872258084e-22) + pow(fs,2)*(fs*(-2.49821261519501e-23*fs - 1.42192566937971e-19) + 1.82351647640129e-18)) + fs*(fs*(fs*(9.64763852233277e-23*fs - 3.53068929659391e-19) - 5.29245486955245e-19) + 6.14466029015632e-17)) + Treble_L*(Treble_L*pow(fs,2)*(fs*(2.40088747236654e-22*fs - 1.8779602481101e-20) + 1.91826477713424e-19) + fs*(fs*(fs*(-2.15430751633278e-22*fs - 1.90693980601459e-18) + 1.50232520281226e-16) - 1.53616507253908e-15)) + Volume_L*(Bass_L*pow(fs,2)*(fs*(fs*(1.6929383555757e-23*fs - 1.25906879957409e-19) + 1.62857548261884e-17) - 1.83118953550983e-16) + Middle_L*(Bass_L*pow(fs,3)*(fs*(1.59749650223354e-24*fs - 9.17181360088287e-21) + 1.17096473699268e-19) + pow(fs,2)*(fs*(-9.99285046078002e-23*fs + 5.73269784908691e-19) - 7.31891791891218e-18)) + fs*(fs*(fs*(-1.05898697136012e-21*fs + 7.77799604390716e-18) - 6.02464692946613e-16) + 6.14466029015632e-15)) + fs*(fs*(fs*(1.03432897575674e-21*fs - 5.85227663541147e-18) + 4.52040346187673e-16) - 4.60849521761724e-15)) + fs*(fs*(fs*(2.46579956033756e-23*fs - 6.44090677084358e-18) + 4.05825720651041e-14) - 3.13857383051234e-12) + 3.20034390112309e-11;\n};\n\nalembic_briteclip = _<: ba.if(signbit(_), alembic_brite_neg_clip, alembic_brite_clip) :>_ with {\nsignbit(x) = (x < 0);alembic_brite_clip = gxt.alembic_briteclip;alembic_brite_neg_clip = gxt.alembic_brite_negclip;\n};\n\noutput = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) : alembic_outclip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n    Master_L = vslider(\"Master_L[name:Master_L]\", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(3) : si.smooth(s);\n\n    b0 = Master_L*fs*(-2.54284690253705e-8*fs - 1.69523126835804e-7);\n\n    b1 = 5.0856938050741e-8*Master_L*pow(fs,2);\n\n    b2 = Master_L*fs*(-2.54284690253705e-8*fs + 1.69523126835804e-7);\n\n    a0 = fs*(4.33864919358014e-10*fs + 7.81664517527894e-9) + 2.68307231780644e-8;\n\n    a1 = -8.67729838716027e-10*pow(fs,2) + 5.36614463561288e-8;\n\n    a2 = fs*(4.33864919358014e-10*fs - 7.81664517527894e-9) + 2.68307231780644e-8;\n};\n\nalembic_outclip = _<: ba.if(signbit(_), alembic_out_neg_clip, alembic_out_clip) :>_ with {\nsignbit(x) = (x < 0);alembic_out_clip = gxt.alembic_outclip;alembic_out_neg_clip = gxt.alembic_out_negclip;\n};\n\n// Brite normal \nbriteswitch = _<:bright,normal:select2( checkbox(\"bright_L\" ));\n\namp = briteswitch:output;\nfreq_split = fi.filterbank(3, (86.0,210.0,1200.0,6531.0));\nprocess    = freq_split: ( amp , amp , amp, amp, amp) :>_;"
 },
 {
  "id": "gx-gxamp15",
  "name": "Amp: 12AT7 pre → 6V6 master",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "12AT7 preamp into a single-ended 6V6 master stage.",
  "description": "Three 12AT7 triode stages feed a paralleled pair of 6V6 tube-table stages acting as a single-ended power stage, with the drive/wet-dry block between them. Mid-gain preamp bite with 6V6 output compression as Gain is raised.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/pre_12AT7__master_6V6/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/pre_12AT7__master_6V6/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12AT7__master_6V6/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12AT7__master_6V6/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp15.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"pre 12AT7/ master 6V6\"; // in amp tube ba.selector\ndeclare name \"pre 12AT7/ master 6V6\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube amp Emulation stage 1 - 2 - 3\n *  12AT7 -> master 6V6\n */\n \na = 0.75;\nr(x) = x-sym_clip(a*0.88);\nsoft_clip(x) = x:sym_clip(a*0.75) <:+(r(x)*0.333);\nhard_clip = sym_clip(0.88);\n\ngx_drive(drive) = _ <: _ + nonlin(4,4,0.125) * drive * 10 ;\n\nprocess = hgroup(\"stage1\", stage1) : component(\"gx-gxdistortion.dsp\").dist(drive,wet_dry) : \n          hgroup(\"stage2\", stage2)  \n          with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n*/\n    stage1 = *(preamp): tubestage(TB_12AT7_68k,86.0,2700.0,2.617753) :\n    fi.lowpass(1,6531.0) : tubestage(TB_12AT7_250k,132.0,1500.0,1.887332) :tubestage(TB_12AT7_250k,194.0,820.0,1.256962); \n    stage2 = fi.lowpass(1,6531.0) : *(gain1)  <: (tubestage(TB_6V6_250k,6531.0,820.0,1.130462),tubestage(TB_6V6_68k,6531.0,820.0,1.130740)) :> _ \n    with {\n        gain1 = ampctrl.gain1;\n    /*\n        gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n    */\n    } ;\n};"
 },
 {
  "id": "gx-gxamp16",
  "name": "Amp: 12AT7 pre → 6V6 push-pull",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "12AT7 preamp with feedback into a push-pull 6V6 output.",
  "description": "Three 12AT7 stages with inter-stage feedback loops feed a push-pull pair of 6V6 tube-table stages with asymmetric clipping, plus the drive/wet-dry block. Mid-gain preamp with power-amp style push-pull saturation.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/pre_12AT7__push_pull_6V6/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/pre_12AT7__push_pull_6V6/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12AT7__push_pull_6V6/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12AT7__push_pull_6V6/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp16.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"pre 12AT7/ push pull 6V6\"; // in amp tube ba.selector\ndeclare name \"pre 12AT7/ push pull 6V6\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube amp Emulation stage 1 - 2 - 3\n *   12AT7 -> push pull 6V6\n */\n\npeak1 = fi.allpassn(4,(-0.2, 0.3, 0.4, 0.5));\n\ngx_drive(drive) = _ <: _ + nonlin(4,4,0.125) * drive * 10 ;\n\nprocess = hgroup(\"stage1\", stage1) : \n          component(\"gx-gxdistortion.dsp\").dist2(drive,wet_dry) : \n          hgroup(\"stage2\", stage2)  \n          with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n*/\n    atten = 0.6;\n    stage1 =\n     *(preamp) : (tubestage(TB_12AT7_68k,86.0,2700.0,2.617753) : + ~ (atten*tubestage(TB_12AT7_250k,132.0,1500.0,1.887333))):\n    fi.lowpass(1,6531.0) : (tubestage(TB_12AT7_250k,132.0,1500.0,1.887333) : + ~ (atten*tubestage(TB_12AT7_250k,194.0,820.0,1.256962))) : tubestage(TB_12AT7_250k,194.0,820.0,1.256962); \n    stage2 = fi.lowpass(1,6531.0) : *(gain1)  <: ((min(0.7,tubestage(TB_6V6_250k,6531.0,410.0,0.659761))),(max(-0.75,tubestage(TB_6V6_68k,6531.0,410.0,0.664541)))) :> \n    peak1\n    with {\n        gain1 = ampctrl.gain1;\n    /*\n        gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n    */\n    };\n};"
 },
 {
  "id": "gx-gxamp14",
  "name": "Amp: 12AT7 three-stage",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Three 12AT7 stages; medium gain between the 12AX7 and 12AU7 amps.",
  "description": "Three 12AT7 triode stages through tube tables with inter-stage low-pass filters, preceded by the drive/wet-dry distortion block. The 12AT7 sits between the 12AX7 and 12AU7 in gain, giving a punchy mid-gain preamp voice.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/12AT7/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/12AT7/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12AT7/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12AT7/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp14.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"12AT7\"; // in amp tube ba.selector\ndeclare name \"12AT7\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n *         12AT7\n */\n \n\ntubeax(preamp,gain1) =  hgroup(\"stage1\", stage1) :\n          hgroup(\"stage2\", stage2) \n          with {\n          \n    stage1 = tubestage(TB_12AT7_68k,86.0,2700.0,2.617753) : *(preamp):\n    fi.lowpass(1,6531.0) : tubestage(TB_12AT7_250k,132.0,1500.0,1.887332) : *(preamp); \n    stage2 = fi.lowpass(1,6531.0) : tubestage(TB_12AT7_250k,194.0,820.0,1.256962) : *(gain1); \n    \n} ;\n\nprocess = component(\"gx-gxdistortion.dsp\").dist(drive,wet_dry): tubeax(preamp,gain1) with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);     \n    gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n*/\n};"
 },
 {
  "id": "gx-gxamp17",
  "name": "Amp: 12AT7 with feedback",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Three 12AT7 stages with inter-stage negative feedback; tight mid-gain crunch.",
  "description": "Three 12AT7 stages through tube tables with negative feedback around the first two stages and an envelope-following level tracker in front. Feedback tightens the response for a firmer, more controlled mid-gain sound.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/12AT7_feedback/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/12AT7_feedback/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12AT7_feedback/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12AT7_feedback/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp17.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"12AT7 feedback\"; // in amp tube ba.selector\ndeclare name \"12AT7 feedback\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n *   12AT7  feedback\n */\n \nval(x) = valve.vt(dist, q(x), x)\nwith {\n    dist =  40.1;\n    q(x) = lp1tm1(x) * 1 - lp2tm1(x) * 1.02 - 1.0 : clip(-1,-0.01);\n    lp(a) = *(1 - a) : + ~ *(a);\n    lp1tm1 = abs <: lp(0.9999), _ : max;\n    avgs = lp1tm1 : avg;\n    avg_size = ma.SR/9;\n    avg(x) = x - de.delay1s(avg_size,x) : + ~ _ : /(avg_size);\n    lp2tm1 = avgs : lp(0.999);\n};\n\ntubeax(preamp,gain1) =  hgroup(\"stage1\", stage1) :\n          hgroup(\"stage2\", stage2) \n          with {\n\n    atten = 0.6;\n    stage1 = tubestage(TB_12AT7_68k,86.0,2700.0,2.617753) : - ~ (atten*tubestage(TB_12AT7_250k,132.0,1500.0,1.887332)) : *(preamp):\n    fi.lowpass(1,6531.0) : tubestage(TB_12AT7_250k,132.0,1500.0,1.887332): + ~ (atten*tubestage(TB_12AT7_250k,194.0,820.0,1.256962)); \n    stage2 = fi.lowpass(1,6531.0) : tubestage(TB_12AT7_250k,194.0,820.0,1.256962) : *(gain1); \n\n} ;\n\nprocess = val : component(\"gx-gxdistortion.dsp\").dist1(drive,wet_dry) : tubeax(preamp,gain1) with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n    gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n*/\n};"
 },
 {
  "id": "gx-gxamp4",
  "name": "Amp: 12AU7 pre → 6V6 master",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "12AU7 three-stage preamp into a single-ended 6V6 master stage.",
  "description": "Three 12AU7 triode stages (130 V tube table) feed a paralleled pair of 6V6 tube-table stages acting as a single-ended power stage, with the drive/wet-dry distortion block in between. Pregain drives the preamp, Gain pushes the 6V6 output for power-amp style compression.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/pre_12AU7__master_6V6/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/pre_12AU7__master_6V6/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12AU7__master_6V6/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12AU7__master_6V6/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp4.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"pre 12AU7/ master 6V6\"; // in amp tube ba.selector\ndeclare name \"pre 12AU7/ master 6V6\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n \nbifilter = fi.tf2(b0,b1,b2,a1,a2) with\n{\n    c = 1.059;\n    R = 0.9221;\n    lc0 = 0.00506158;\n    lc1 = 0.06446806;\n    lc2 = 0.27547621;\n    lc3 = 0.43359433;\n    lc4 = 1.31282248;\n    lc5 = 0.07238887;\n    fc = 1200 : *(2*ma.PI/ma.SR) : log;\n    p = lc0*pow(fc,5) + lc1*pow(fc,4) + lc2*pow(fc,3) + lc3*pow(fc,2) + lc4*fc + lc5 : exp;\n    //b0 = 1;\n    //b1 = -1.01;\n    //b2 = 0;\n    //a1 = -1.84;\n    //a2 = 0.846416;\n    b0 = 1;\n    b1 = -c;\n    b2 = 0;\n    a1 = -2*R*cos(p);\n    a2 = R*R;\n};\n\nprocess = hgroup(\"stage1\", stage1) :\n          component(\"gx-gxdistortion.dsp\").dist(drive,wet_dry) : \n          hgroup(\"stage2\", stage2) \n          with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n*/\n    stage1 = *(preamp): tubestage130_10(TB_12AU7_68k,86.0,2700.0,1.257240) :\n    fi.lowpass(1,6531.0) : tubestage130_10(TB_12AU7_250k,132.0,1500.0,0.776162): tubestage130_10(TB_12AU7_250k,194.0,820.0,0.445487); \n    stage2 = fi.lowpass(1,6531.0) : *(gain1) <: (tubestage(TB_6V6_250k,6531.0,820.0,1.130462),tubestage(TB_6V6_68k,6531.0,820.0,1.130740)) :>_\n    with {\n        gain1 = ampctrl.gain1;\n    /*\n        gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n    */\n    };\n};"
 },
 {
  "id": "gx-gxamp8",
  "name": "Amp: 12AU7 pre → 6V6 push-pull",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Clean-leaning 12AU7 preamp into a push-pull 6V6 output stage.",
  "description": "Three 12AU7 stages (130 V table) with inter-stage feedback loops feed a push-pull pair of 6V6 tube-table stages with asymmetric clipping, plus the drive/wet-dry block. A lower-gain front end with power-amp style saturation at the back.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/pre_12AU7__push-pull_6V6/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/pre_12AU7__push-pull_6V6/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12AU7__push-pull_6V6/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12AU7__push-pull_6V6/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp8.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"pre 12AU7/ push-pull 6V6\"; // in amp tube ba.selector\ndeclare name \"pre 12AU7/ push-pull 6V6\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n *   12AU7 -> pusch pull 6V6\n */\n\npeak1 = fi.allpassn(4,(-0.2, 0.3, 0.4, 0.5));\n\ngx_drive(drive) = _ <: _ + nonlin(4,4,0.125) * drive * 10 ;\n\nprocess = hgroup(\"stage1\", stage1) : \n          component(\"gx-gxdistortion.dsp\").dist2(drive,wet_dry) : \n          hgroup(\"stage2\", stage2)  \n          with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n*/\n    atten = 0.6;\n    stage1 =\n     *(preamp):*(2.0): (tubestage130_10(TB_12AU7_68k,86.0,2700.0,1.257240) : + ~ (atten*tubestage130_10(TB_12AU7_250k,132.0,1500.0,0.776162))):\n    fi.lowpass(1,6531.0) : (tubestage130_10(TB_12AU7_250k,132.0,1500.0,0.776162) : + ~ (atten*tubestage130_10(TB_12AU7_250k,194.0,820.0,0.445487))) : tubestage130_10(TB_12AU7_250k,194.0,820.0,0.445487); \n    stage2 = fi.lowpass(1,6531.0) : *(gain1)  <: ((min(0.7,tubestage(TB_6V6_250k,6531.0,410.0,0.659761))),(max(-0.75,tubestage(TB_6V6_68k,6531.0,410.0,0.664541)))) :> \n    peak1\n    with {\n        gain1 = ampctrl.gain1;\n    /*\n        gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n    */\n    };\n};"
 },
 {
  "id": "gx-gxamp3",
  "name": "Amp: 12AU7 three-stage",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Three low-mu 12AU7 stages; cleaner headroom with a gentle, late breakup.",
  "description": "Three 12AU7 triode stages through tube tables with inter-stage low-pass filters and extra make-up gain, preceded by the drive/wet-dry distortion block. The low-gain 12AU7 stays clean longer, making this the most headroom-friendly of the gxamp set.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/12AU7/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/12AU7/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12AU7/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12AU7/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp3.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"12AU7\"; // in amp tube ba.selector\ndeclare name \"12AU7\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n\ntubeax(preamp,gain1) =  hgroup(\"stage1\", stage1) :\n          hgroup(\"stage2\", stage2) \n          with {\n\n    stage1 = tubestage(TB_12AU7_68k,86.0,2700.0,3.718962) : *(preamp):*(2.0):\n    fi.lowpass(1,6531.0) : tubestage(TB_12AU7_250k,132.0,1500.0,2.314844) : *(preamp) :*(2.0); \n    stage2 = fi.lowpass(1,6531.0) : tubestage(TB_12AU7_250k,194.0,820.0,1.356567) : *(gain1):*(2.0); \n\n} ;\n\nprocess = component(\"gx-gxdistortion.dsp\").dist(drive,wet_dry): tubeax(preamp,gain1) with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n    gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n*/\n};"
 },
 {
  "id": "gx-gxamp11",
  "name": "Amp: 12AU7 with feedback",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Three 12AU7 stages with inter-stage negative feedback; very clean, compressed edge.",
  "description": "Three 12AU7 stages through 130 V tube tables with negative feedback around the first two stages and an envelope-following level tracker in front. The lowest-gain of the feedback amps: mostly clean with a soft edge when pushed.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/12AU7_feedback/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/12AU7_feedback/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12AU7_feedback/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12AU7_feedback/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp11.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"12AU7 feedback\"; // in amp tube ba.selector\ndeclare name \"12AU7 feedback\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n *   12AU7 feedback\n */\n \nval(x) = valve.vt(dist, q(x), x)\nwith {\n    dist =  40.1;\n    q(x) = lp1tm1(x) * 1 - lp2tm1(x) * 1.02 - 1.0 : clip(-1,-0.01);\n    lp(a) = *(1 - a) : + ~ *(a);\n    lp1tm1 = abs <: lp(0.9999), _ : max;\n    avgs = lp1tm1 : avg;\n    avg_size = ma.SR/9;\n    avg(x) = x - de.delay1s(avg_size,x) : + ~ _ : /(avg_size);\n    lp2tm1 = avgs : lp(0.999);\n};\n\ntubeax(preamp,gain1) =  hgroup(\"stage1\", stage1) :\n          hgroup(\"stage2\", stage2) \n          with {\n          \n    stage1 = tubestage130_10(TB_12AU7_68k,86.0,2700.0,1.257240) : - ~ tubestage130_10(TB_12AU7_250k,132.0,1500.0,0.776162) : *(preamp):\n    fi.lowpass(1,6531.0) : tubestage130_10(TB_12AU7_250k,132.0,1500.0,0.776162): + ~ tubestage130_10(TB_12AU7_250k,194.0,820.0,0.445487) ; \n    stage2 = fi.lowpass(1,6531.0) : tubestage130_10(TB_12AU7_250k,194.0,820.0,0.445487) : *(gain1); \n    \n} ;\n\nprocess = val : component(\"gx-gxdistortion.dsp\").dist1(drive,wet_dry) : tubeax(preamp,gain1) with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n    gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n*/\n} ;"
 },
 {
  "id": "gx-gxamp5",
  "name": "Amp: 12AX7 pre → 6V6 master",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Classic 12AX7 preamp into a 6V6 master stage; tweed-style crunch.",
  "description": "Three 12AX7 triode stages feed a paralleled pair of 6V6 tube-table stages that act as a single-ended power stage, with the drive/wet-dry distortion block in between. Pregain sets preamp drive and Gain how hard the 6V6 output is pushed.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/pre_12ax7__master_6V6/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/pre_12ax7__master_6V6/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12ax7__master_6V6/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12ax7__master_6V6/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp5.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"pre 12ax7/ master 6V6\"; // in amp tube ba.selector\ndeclare name \"pre 12ax7/ master 6V6\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n \nbifilter = fi.tf2(b0,b1,b2,a1,a2) with\n{\n    c = 1.059;\n    R = 0.9221;\n    lc0 = 0.00506158;\n    lc1 = 0.06446806;\n    lc2 = 0.27547621;\n    lc3 = 0.43359433;\n    lc4 = 1.31282248;\n    lc5 = 0.07238887;\n    fc = 1200 : *(2*ma.PI/ma.SR) : log;\n    p = lc0*pow(fc,5) + lc1*pow(fc,4) + lc2*pow(fc,3) + lc3*pow(fc,2) + lc4*fc + lc5 : exp;\n    //b0 = 1;\n    //b1 = -1.01;\n    //b2 = 0;\n    //a1 = -1.84;\n    //a2 = 0.846416;\n    b0 = 1;\n    b1 = -c;\n    b2 = 0;\n    a1 = -2*R*cos(p);\n    a2 = R*R;\n};\n\nprocess = hgroup(\"stage1\", stage1) : \n          component(\"gx-gxdistortion.dsp\").dist(drive,wet_dry) : \n          hgroup(\"stage2\", stage2) \n          with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n*/\n    stage1 = *(preamp): tubestage(TB_12AX7_68k,86.0,2700.0,1.581656):\n    fi.lowpass(1,6531.0) : tubestage(TB_12AX7_250k,132.0,1500.0,1.204285):tubestage(TB_12AX7_250k,194.0,820.0,0.840703); \n    stage2 = fi.lowpass(1,6531.0) : *(gain1)  <: (tubestage(TB_6V6_250k,6531.0,820.0,1.130462),tubestage(TB_6V6_68k,6531.0,820.0,1.130740)) :>_\n    with {\n        gain1 = ampctrl.gain1;\n    /*\n        gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n    */\n    };\n};"
 },
 {
  "id": "gx-gxamp7",
  "name": "Amp: 12AX7 pre → 6V6 push-pull",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "12AX7 preamp with feedback into a push-pull 6V6 output; the fullest gxamp voice.",
  "description": "Three 12AX7 triode stages with inter-stage feedback loops feed a push-pull pair of 6V6 tube-table stages with asymmetric clipping, with the drive/wet-dry distortion block in the chain. Pregain sets preamp drive and Gain the output-stage push.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/pre_12ax7__push-pull_6V6/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/pre_12ax7__push-pull_6V6/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12ax7__push-pull_6V6/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_12ax7__push-pull_6V6/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp7.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"pre 12ax7/ push-pull 6V6\"; // in amp tube ba.selector\ndeclare name \"pre 12ax7/ push-pull 6V6\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n *        12ax7 -> pusch pull 6V6\n */\n\npeak1 = fi.allpassn(4,(-0.2, 0.3, 0.4, 0.5));\n\ngx_drive(drive) = _ <: _ + nonlin(4,4,0.125) * drive * 10 ;\n\nprocess = hgroup(\"stage1\", stage1)\n                         : component(\"gx-gxdistortion.dsp\").dist2(drive,wet_dry)\n                         : hgroup(\"stage2\", stage2)\n          with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n*/\n    atten = 0.6;\n    stage1 =\n    *(preamp): (tubestage(TB_12AX7_68k,86.0,2700.0,1.581656) : + ~ (atten*tubestage(TB_12AX7_250k,132.0,1500.0,1.204285)))\n     : fi.lowpass(1,6531.0) : (tubestage(TB_12AX7_250k,132.0,1500.0,1.204285) : + ~ (atten*tubestage(TB_12AX7_250k,194.0,820.0,0.840703))) : tubestage(TB_12AX7_250k,194.0,820.0,0.840703); \n    stage2 = fi.lowpass(1,6531.0) : *(gain1)  <: ((min(0.7,tubestage(TB_6V6_250k,6531.0,410.0,0.659761))),(max(-0.75,tubestage(TB_6V6_68k,6531.0,410.0,0.664541)))) :> \n    peak1\n    with {\n        gain1 = ampctrl.gain1;\n    /*\n        gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n    */\n    };\n};"
 },
 {
  "id": "gx-gxamp",
  "name": "Amp: 12AX7 three-stage",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Three cascaded 12AX7 triode stages; the classic guitarix high-gain preamp voice.",
  "description": "Three 12AX7 triode stages run through the guitarix tube tables with 6.5 kHz inter-stage low-pass filters, fed by the drive/wet-dry distortion block. Pregain sets how hard the first two stages are hit, Gain the third; the standard bright, saturating 12AX7 preamp.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/12ax7/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/12ax7/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12ax7/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12ax7/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"12ax7\"; // in amp tube ba.selector\ndeclare name \"12ax7\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n\ntubeax(preamp,gain1) =  hgroup(\"stage1\", stage1) :\n          hgroup(\"stage2\", stage2) \n          with {\n    stage1 = tubestage(TB_12AX7_68k,86.0,2700.0,1.581656) : *(preamp):\n    fi.lowpass(1,6531.0) : tubestage(TB_12AX7_250k,132.0,1500.0,1.204285) : *(preamp); \n    stage2 = fi.lowpass(1,6531.0) : tubestage(TB_12AX7_250k,194.0,820.0,0.840703) : *(gain1); \n};\n\nprocess = component(\"gx-gxdistortion.dsp\").dist(drive,wet_dry) : tubeax(preamp,gain1) with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n};"
 },
 {
  "id": "gx-gxamp9",
  "name": "Amp: 12AX7 with feedback",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Three 12AX7 stages with negative feedback around them; tighter than the plain version.",
  "description": "Three 12AX7 triode stages through tube tables, with negative feedback wrapped around the first two stages and an envelope-following level tracker in front. Feedback tightens the response and lowers the effective gain compared with the plain 12AX7 amp.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/12ax7_feedback/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/12ax7_feedback/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12ax7_feedback/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/12ax7_feedback/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp9.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"12ax7 feedback\"; // in amp tube ba.selector\ndeclare name \"12ax7 feedback\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n *   12ax7 feedback\n */\n \nval(x) = valve.vt(dist, q(x), x)\nwith {\n    dist =  40.1;\n    q(x) = lp1tm1(x) * 1 - lp2tm1(x) * 1.02 - 1.0 : clip(-1,-0.01);\n    lp(a) = *(1 - a) : + ~ *(a);\n    lp1tm1 = abs <: lp(0.9999), _ : max;\n    avgs = lp1tm1 : avg;\n    avg_size = ma.SR/9;\n    avg(x) = x - de.delay1s(avg_size,x) : + ~ _ : /(avg_size);\n    lp2tm1 = avgs : lp(0.999);\n};\n\ntubeax(preamp,gain1) =  hgroup(\"stage1\", stage1) :\n          hgroup(\"stage2\", stage2) \n          with {\n          \n    atten = 0.6;\n    stage1 = tubestage(TB_12AX7_68k,86.0,2700.0,1.581656) : - ~ (atten*tubestage(TB_12AX7_250k,132.0,1500.0,1.204285)) : *(preamp):\n    fi.lowpass(1,6531.0) : tubestage(TB_12AX7_250k,132.0,1500.0,1.204285): + ~ (atten*tubestage(TB_12AX7_250k,194.0,820.0,0.840702)); \n    stage2 = fi.lowpass(1,6531.0) : tubestage(TB_12AX7_250k,194.0,820.0,0.840702) : *(gain1); \n    \n} ;\n\nprocess = val : component(\"gx-gxdistortion.dsp\").dist1(drive,wet_dry) : tubeax(preamp,gain1) with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n    gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n*/\n};"
 },
 {
  "id": "gx-gxamp18",
  "name": "Amp: 6C16 three-stage",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Three stages through the 6C16 tube table; a hotter, more aggressive preamp.",
  "description": "Three triode stages through the 6C16 tube table with inter-stage low-pass filters, preceded by the drive/wet-dry distortion block. Runs hotter than the 12AX7 set; Pregain and Gain set the per-stage drive.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/6C16/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/6C16/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/6C16/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/6C16/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp18.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"6C16\"; // in amp tube ba.selector\ndeclare name \"6C16\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n \ntubeax(preamp,gain1) =  hgroup(\"stage1\", stage1) :\n          hgroup(\"stage2\", stage2) \n          with {\n    stage1 = tubestage(TB_6C16_68k,86.0,2700.0,2.921806) : *(preamp):\n    fi.lowpass(1,6531.0) : tubestage(TB_6C16_250k,132.0,1500.0,2.097743) : *(preamp); \n    stage2 = fi.lowpass(1,6531.0) : tubestage(TB_6C16_250k,194.0,820.0,1.378742) : *(gain1); \n};\n\nprocess = component(\"gx-gxdistortion.dsp\").dist(drive,wet_dry) : tubeax(preamp,gain1) with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n};"
 },
 {
  "id": "gx-gxamp12",
  "name": "Amp: 6DJ8 pre → 6V6 master",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "6DJ8 three-stage preamp into a single-ended 6V6 master stage.",
  "description": "Three 6DJ8 triode stages (130 V table) feed a paralleled pair of 6V6 tube-table stages acting as a single-ended power stage, with the drive/wet-dry block between them. Smooth preamp character with output-stage compression from the 6V6.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/pre_6DJ8__master_6V6/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/pre_6DJ8__master_6V6/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_6DJ8__master_6V6/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_6DJ8__master_6V6/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp12.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"pre 6DJ8/ master 6V6\"; // in amp tube ba.selector\ndeclare name \"pre 6DJ8/ master 6V6\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n \na = 0.75;\nr(x) = x-sym_clip(a*0.88);\nsoft_clip(x) = x:sym_clip(a*0.75) <:+(r(x)*0.333);\nhard_clip = sym_clip(0.88);\n\ngx_drive(drive) = _ <: _ + nonlin(4,4,0.125) * drive * 10 ;\n\nprocess = hgroup(\"stage1\", stage1) : component(\"gx-gxdistortion.dsp\").dist(drive,wet_dry) : \n          hgroup(\"stage2\", stage2)  \n          with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n*/\n    stage1 = *(preamp): tubestage130_20(TB_6DJ8_68k,86.0,2700.0,1.863946) :\n    fi.lowpass(1,6531.0) : tubestage130_20(TB_6DJ8_250k,132.0,1500.0,1.271609) :tubestage130_20(TB_6DJ8_250k,194.0,820.0,0.797043); \n    stage2 = fi.lowpass(1,6531.0) : *(gain1)  <: (tubestage(TB_6V6_250k,6531.0,820.0,1.130462),tubestage(TB_6V6_68k,6531.0,820.0,1.130740)) :> _ \n    with {\n        gain1 = ampctrl.gain1;\n        /*\n        gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n        */\n    } ;\n};"
 },
 {
  "id": "gx-gxamp6",
  "name": "Amp: 6DJ8 pre → 6V6 push-pull",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "6DJ8 preamp with local feedback into an asymmetric push-pull 6V6 output.",
  "description": "Three 6DJ8 stages with inter-stage feedback loops feed a push-pull pair of 6V6 tube-table stages with asymmetric clipping limits, plus the drive/wet-dry block. Pregain drives the preamp and Gain the push-pull output.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/pre_6DJ8__push-pull_6V6/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/pre_6DJ8__push-pull_6V6/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_6DJ8__push-pull_6V6/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/pre_6DJ8__push-pull_6V6/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp6.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"pre 6DJ8/ push-pull 6V6\"; // in amp tube ba.selector\ndeclare name \"pre 6DJ8/ push-pull 6V6\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n\npeak1 = fi.allpassn(4,(-0.2, 0.3, 0.4, 0.5));\n\ngx_drive(drive) = _ <: _ + nonlin(4,4,0.125) * drive * 10 ;\n\nprocess = hgroup(\"stage1\", stage1) : \n          component(\"gx-gxdistortion.dsp\").dist2(drive,wet_dry) : \n          hgroup(\"stage2\", stage2)  \n          with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n*/\n    atten = 0.6;\n    stage1 =\n     *(preamp): (tubestage130_20(TB_6DJ8_68k,86.0,2700.0,1.863946) : + ~ (atten*tubestage130_20(TB_6DJ8_250k,132.0,1500.0,1.271609))):\n    fi.lowpass(1,6531.0) : (tubestage130_20(TB_6DJ8_250k,132.0,1500.0,1.271609) : + ~ (atten*tubestage130_20(TB_6DJ8_250k,194.0,820.0,0.797043))) : tubestage130_20(TB_6DJ8_250k,194.0,820.0,0.797043) ; \n    stage2 = fi.lowpass(1,6531.0) : *(gain1)  <: ((min(0.7,tubestage(TB_6V6_250k,6531.0,410.0,0.659761))),(max(-0.75,tubestage(TB_6V6_68k,6531.0,410.0,0.664541)))) :> \n    peak1\n    with {\n        gain1 = ampctrl.gain1;\n    /*\n        gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n    */\n    };\n};"
 },
 {
  "id": "gx-gxamp10",
  "name": "Amp: 6DJ8 three-stage",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Three 6DJ8 stages ending in a paralleled pair; smooth, mid-gain tube crunch.",
  "description": "Two 6DJ8 triode stages followed by a paralleled 6DJ8 pair, all through 130 V tube tables with inter-stage low-pass filters, preceded by the drive/wet-dry distortion block. The 6DJ8 gives a smoother, less fizzy breakup than the 12AX7 amps.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/6DJ8/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/6DJ8/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/6DJ8/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/6DJ8/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp10.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"6DJ8\"; // in amp tube ba.selector\ndeclare name \"6DJ8\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n\ntubeax(preamp,gain1) =  hgroup(\"stage1\", stage1) :\n          hgroup(\"stage2\", stage2) \n          with {\n    stage1 = tubestage130_20(TB_6DJ8_68k,86.0,2700.0,1.863946) : *(preamp):\n    fi.lowpass(1,6531.0) : tubestage130_20(TB_6DJ8_250k,132.0,1500.0,1.271609) : *(preamp) ; \n    stage2 = fi.lowpass(1,6531.0) <: ( tubestage130_20(TB_6DJ8_68k,194.0,820.0,0.799031), tubestage130_20(TB_6DJ8_250k,194.0,820.0,0.797043)) :> *(gain1); \n    \n} ;\n\nprocess = component(\"gx-gxdistortion.dsp\").dist(drive,wet_dry): tubeax(preamp,gain1) with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n    gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n*/\n};"
 },
 {
  "id": "gx-gxamp13",
  "name": "Amp: 6DJ8 with feedback",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Three 6DJ8 stages with inter-stage negative feedback; smooth and controlled.",
  "description": "Three 6DJ8 stages through 130 V tube tables with negative feedback around the first two stages and an envelope-following level tracker in front. Feedback trims the gain and evens out the response for a controlled, smooth crunch.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/6DJ8_feedback/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/6DJ8_feedback/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/6DJ8_feedback/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/6DJ8_feedback/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp13.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"6DJ8 feedback\"; // in amp tube ba.selector\ndeclare name \"6DJ8 feedback\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n \nval(x) = valve.vt(dist, q(x), x)\nwith {\n    dist =  40.1;\n    q(x) = lp1tm1(x) * 1 - lp2tm1(x) * 1.02 - 1.0 : clip(-1,-0.01);\n    lp(a) = *(1 - a) : + ~ *(a);\n    lp1tm1 = abs <: lp(0.9999), _ : max;\n    avgs = lp1tm1 : avg;\n    avg_size = ma.SR/9;\n    avg(x) = x - de.delay1s(avg_size,x) : + ~ _ : /(avg_size);\n    lp2tm1 = avgs : lp(0.999);\n};\n\ntubeax(preamp,gain1) =  hgroup(\"stage1\", stage1) :\n          hgroup(\"stage2\", stage2) \n          with {\n          \n    atten = 0.6;\n    stage1 = tubestage130_20(TB_6DJ8_68k,86.0,2700.0,1.863946) : - ~ (atten*tubestage130_20(TB_6DJ8_250k,132.0,1500.0,1.271609)) : *(preamp):\n    fi.lowpass(1,6531.0) : tubestage130_20(TB_6DJ8_250k,132.0,1500.0,1.271609): + ~ (atten*tubestage130_20(TB_6DJ8_250k,194.0,820.0,0.797043));\n    stage2 = fi.lowpass(1,6531.0) : tubestage130_20(TB_6DJ8_250k,194.0,820.0,0.797043) : *(gain1); \n    \n};\n\nprocess = val : component(\"gx-gxdistortion.dsp\").dist1(drive,wet_dry) : tubeax(preamp,gain1) with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n    gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n*/\n};"
 },
 {
  "id": "gx-gxamp2",
  "name": "Amp: 6V6 three-stage",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Three 6V6 stages driven like a preamp; rounder, softer clip than the 12AX7 amps.",
  "description": "Three stages through the 6V6 tube table with inter-stage low-pass filters, preceded by the drive/wet-dry distortion block. Sounds softer and more compressed than the 12AX7 version; Pregain and Gain set the per-stage drive.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/6V6/.gxdistortion.drive"
   },
   {
    "label": ".gxdistortion.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/6V6/.gxdistortion.wet_dry"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/6V6/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/6V6/stage2/.amp2.stage2.gain1"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxamp2.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"6V6\"; // in amp tube ba.selector\ndeclare name \"6V6\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n \nbifilter = fi.tf2(b0,b1,b2,a1,a2) with\n{\n    c = 1.059;\n    R = 0.9221;\n    lc0 = 0.00506158;\n    lc1 = 0.06446806;\n    lc2 = 0.27547621;\n    lc3 = 0.43359433;\n    lc4 = 1.31282248;\n    lc5 = 0.07238887;\n    fc = 1200 : *(2*ma.PI/ma.SR) : log;\n    p = lc0*pow(fc,5) + lc1*pow(fc,4) + lc2*pow(fc,3) + lc3*pow(fc,2) + lc4*fc + lc5 : exp;\n    //b0 = 1;\n    //b1 = -1.01;\n    //b2 = 0;\n    //a1 = -1.84;\n    //a2 = 0.846416;\n    b0 = 1;\n    b1 = -c;\n    b2 = 0;\n    a1 = -2*R*cos(p);\n    a2 = R*R;\n};\n\ntubec(preamp,gain1) = hgroup(\"stage1\", stage1) :\n          hgroup(\"stage2\", stage2) \n          with {\n          \n    stage1 =  tubestage(TB_6V6_68k,86.0,2700.0,2.296150):\n    fi.lowpass(1,6531.0) : *(preamp) : tubestage(TB_6V6_250k,132.0,1500.0,1.675587); \n    stage2 = fi.lowpass(1,6531.0) : *(gain1) : tubestage(TB_6V6_250k,194.0,820.0,1.130462);\n    \n};\n\ntubeax(preamp,gain1) = hgroup(\"stage1\", stage1) :\n          hgroup(\"stage2\", stage2) \n          with {\n          \n    stage1 = *(preamp): tubestage(TB_6V6_68k,86.0,2700.0,2.296150): *(0.77) :\n    fi.lowpass(1,6531.0) : *(preamp) : tubestage(TB_6V6_250k,132.0,1500.0,1.675587): *(0.77); \n    stage2 = fi.lowpass(1,6531.0) : *(gain1) : bifilter : tubestage(TB_6V6_250k,194.0,820.0,1.130462) : *(0.77);\n    \n} ;\n\nprocess = component(\"gx-gxdistortion.dsp\").dist(drive,wet_dry) : tubeax(preamp,gain1) with {\n    drive = ampctrl.drive;\n    wet_dry = ampctrl.wet_dry;\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n/*\n    drive = vslider(\".gxdistortion.drive[alias]\",0.35, 0, 1, 0.01);\n    wet_dry = vslider(\".gxdistortion.wet_dry[alias]\",  100, 0, 100, 1) : /(100) : smoothi(0.999);\n    preamp =  vslider(\".amp2.stage1.Pregain[alias]\",0,-20,20,0.1) : ba.db2linear : smoothi(0.999);\n    gain1 = vslider(\".amp2.stage2.gain1[alias]\", 6, -20.0, 20.0, 0.1) : ba.db2linear : smoothi(0.999);\n*/\n};"
 },
 {
  "id": "gx-tube",
  "name": "Fuzzy Tube",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Single 'fuzzy tube' polynomial waveshaper; simple, gritty tube-ish drive.",
  "description": "One stage of guitarix's fuzzy_tube polynomial waveshaper with fixed curve parameters; the Fuzzy control sets the amount. A simple gritty drive, not a circuit model.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "fuzzy",
    "min": -3,
    "max": 10,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/gx_tube/fuzzy"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tube.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nfuzzy = vslider(\"fuzzy[name:ba.count]\", 1, -3, 10, 1);\nprocess = fuzzy_tube(a,b,c,fuzzy)\nwith {\n  a = 2;\n  b = 1;\n  c = 0.5;\n};"
 },
 {
  "id": "ex-guitarix-amp",
  "name": "Guitarix Lite Amp",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "Faust examples",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Self-contained guitarix example: TS9 table clipper into 3x 12AX7 stages, JCM2000 tone stack and cabinet EQ",
  "description": "Self-contained guitarix example: TS9 table clipper into 3x 12AX7 stages, JCM2000 tone stack and cabinet EQ",
  "author": "Guitarix project (Hermann Meyer, James Warden, Andreas Degert, Pete Shorthose), adapted by GRAME",
  "flags": "",
  "params": [
   {
    "label": "TS Drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Guitarix_Lite_Amp/TS_Drive"
   },
   {
    "label": "TS Tone",
    "min": 100,
    "max": 1000,
    "default": 400,
    "step": 1,
    "unit": "Hz",
    "path": "/Guitarix_Lite_Amp/TS_Tone"
   },
   {
    "label": "TS Level",
    "min": -20,
    "max": 12,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Guitarix_Lite_Amp/TS_Level"
   },
   {
    "label": "Pregain",
    "min": -20,
    "max": 30,
    "default": 3,
    "step": 0.1,
    "unit": "dB",
    "path": "/Guitarix_Lite_Amp/Pregain"
   },
   {
    "label": "Gain",
    "min": -20,
    "max": 30,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Guitarix_Lite_Amp/Gain"
   },
   {
    "label": "Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Guitarix_Lite_Amp/Treble"
   },
   {
    "label": "Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Guitarix_Lite_Amp/Middle"
   },
   {
    "label": "Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Guitarix_Lite_Amp/Bass"
   },
   {
    "label": "Cab Mix",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Guitarix_Lite_Amp/Cab_Mix"
   },
   {
    "label": "Cab Level",
    "min": -30,
    "max": 20,
    "default": -10,
    "step": 0.1,
    "unit": "dB",
    "path": "/Guitarix_Lite_Amp/Cab_Level"
   }
  ],
  "faustCode": "declare name \"Guitarix Lite Amp\";\ndeclare description \"Self-contained guitarix example: TS9 table clipper into 3x 12AX7 stages, JCM2000 tone stack and cabinet EQ\";\ndeclare author \"Guitarix project (Hermann Meyer, James Warden, Andreas Degert, Pete Shorthose), adapted by GRAME\";\ndeclare license \"GPL-2.0-or-later\";\ndeclare source \"grame-cncm/faust/examples/misc/guitarix.dsp\";\ndeclare category \"guitar\";\ndeclare family \"amp\";\nimport(\"stdfaust.lib\");\ntu = library(\"tubes.lib\");\nts = library(\"tonestacks.lib\");\n\ndrive  = hslider(\"[0] TS Drive\", 0.5, 0, 1, 0.01);\ntsTone = hslider(\"[1] TS Tone[unit:Hz][scale:log]\", 400, 100, 1000, 1);\ntsLvl  = hslider(\"[2] TS Level[unit:dB]\", 0, -20, 12, 0.1) : ba.db2linear : si.smoo;\npre    = hslider(\"[3] Pregain[unit:dB]\", 3, -20, 30, 0.1) : ba.db2linear : si.smoo;\ngain   = hslider(\"[4] Gain[unit:dB]\", 0, -20, 30, 0.1) : ba.db2linear : si.smoo;\ntreble = hslider(\"[5] Treble\", 0.5, 0, 1, 0.01) : si.smoo;\nmiddle = hslider(\"[6] Middle\", 0.5, 0, 1, 0.01) : si.smoo;\nbass   = hslider(\"[7] Bass\", 0.5, 0, 1, 0.01) : si.smoo;\ncabmix = hslider(\"[8] Cab Mix\", 1, 0, 1, 0.01) : si.smoo;\ncab    = hslider(\"[9] Cab Level[unit:dB]\", -10, -30, 20, 0.1) : ba.db2linear : si.smoo;\n\n// ---- TS9 nonlinearity table (generated by guitarix tools/ts9sim.py) ----\nnonlininterpolation(table, low, high, step, size, x) = ts9(low, step, size, table, x), inverse(x) : ccopysign;\nts9(low, step, size, table, x) = interpolation(table, getCoef(low, step, size, x), nonlinindex(low, step, x) : boundIndex(size));\nnonlinindex(low, step, x) = (abs(x)/(3.0+abs(x))-low)*step;\ngetCoef(low, step, size, x) = boundFactor(size, nonlinindex(low, step, x), nonlinindex(low, step, x) : boundIndex(size));\nboundIndex(size, index) = int(max(0, min(index, size-1)));\nboundFactor(size, index, bindex) = index - bindex : max(0) : min(1);\ninterpolation(table, coef, index) = table, index : rdtable, (table, index+1 : rdtable) : (_, _ : it.interpolate_linear(coef));\ninverse(x) = -x;\nccopysign(x, s) = abs(x) * ma.signum(s) + (s == 0) * x;\nts9comp = nonlininterpolation(ts9table, low, high, step, size)\nwith {\n    low = 0.0; high = 0.970874; step = 101.97; size = 99;\n    ts9table = waveform{0.0, -0.0296990148227, -0.0599780676992, -0.0908231643281, -0.122163239629, -0.15376009788, -0.184938007182, -0.214177260107, -0.239335434213, -0.259232575019, -0.274433909887, -0.286183308354, -0.29553854444, -0.303222323477, -0.309706249977, -0.315301338712, -0.320218440785, -0.324604982281, -0.328567120703, -0.332183356975, -0.335513124719, -0.33860236542, -0.34148724693, -0.344196707008, -0.346754233717, -0.34917913798, -0.351487480543, -0.35369275887, -0.355806424152, -0.357838275995, -0.359796767655, -0.361689244919, -0.363522135105, -0.365301098113, -0.367031148289, -0.368716753588, -0.370361916943, -0.371970243537, -0.373544996828, -0.375089145544, -0.376605403346, -0.378096262548, -0.379564022938, -0.381010816596, -0.382438629377, -0.383849319643, -0.385244634694, -0.386626225283, -0.387995658543, -0.389354429565, -0.39070397188, -0.392045667012, -0.393380853288, -0.39471083403, -0.396036885269, -0.397360263098, -0.398682210753, -0.400003965547, -0.401326765733, -0.402651857394, -0.403980501471, -0.405313980999, -0.406653608692, -0.40800073496, -0.409356756504, -0.410723125631, -0.412101360439, -0.413493056085, -0.414899897347, -0.416323672745, -0.417766290556, -0.419229797097, -0.420716397759, -0.422228481377, -0.423768648654, -0.425339745558, -0.426944902828, -0.428587583057, -0.430271637224, -0.432001373102, -0.433781638746, -0.435617925286, -0.437516494692, -0.439484540257, -0.441530390423, -0.443663770898, -0.445896146322, -0.448241172434, -0.450715304661, -0.453338632988, -0.45613605235, -0.45913894467, -0.46238766699, -0.465935359011, -0.469854010456, -0.474244617411, -0.479255257451, -0.48511588606, -0.492212726244, -0.501272723631};\n};\nts9sim = ts9nonlin : fi.lowpass(1, tsTone) : *(tsLvl)\nwith {\n    R1 = 4700; R2 = 51000+500000*drive; C = 0.047*1e-6;\n    a1 = (R1+R2)*C*2*ma.SR; a2 = R1*C*2*ma.SR;\n    B0 = (1+a1)/(1+a2); B1 = (1-a1)/(1+a2); A1 = (1-a2)/(1+a2);\n    X2 = fi.tf1(B0, B1, A1);\n    ts9nonlin = _ <: _, (X2, _ : - : ts9comp) : - :> _;\n};\nstage1 = tu.T1_12AX7 : *(pre) : fi.lowpass(1, 6531.0) : tu.T2_12AX7 : *(pre);\nstage2 = fi.lowpass(1, 6531.0) : tu.T3_12AX7 : *(gain);\ncabinet = _ <: *(1-cabmix), (*(cabmix) : fi.conv((0.000488281, -0.0020752, 0.000561523, -0.00231934, 0.000634766, -0.00247803, 0.000512695, -0.00247803, 0.000146484, -0.00219727, -0.000622559, -0.00145264, -0.00202637, -2.44141e-05, -0.00438232, 0.00247803, -0.00822754, 0.00706787, -0.0159546, 0.0202148, -0.0471558, 0.0953003, -0.208582, 0.312427, 0.75, -0.26803, 0.399963, 0.200696, -0.146655, -0.29303, -0.222168, -0.113098, 0.0267334, 0.0312134, 0.164685, 0.0443481, 0.186621, 0.0540039, 0.123303, 0.0805054, 0.0739868, 0.0591797, 0.0661743, 0.0400391, 0.0429932, 0.0339844, 0.0320557, 0.02323, 0.0217285, 0.0182007, 0.0157227, 0.0130005, 0.0103882, 0.00942383, 0.00718994, 0.0067749, 0.00458984, 0.00455322, 0.00272217, 0.00294189, 0.00140381, 0.00170898, 0.000402832, 0.000720215, -0.000354004, -2.44141e-05, -0.000915527, -0.000610352, -0.00134277, -0.0010498, -0.00166016, -0.0013916, -0.0019043, -0.00166016, -0.0020874, -0.00187988, -0.00224609, -0.00203857, -0.00235596, -0.00217285, -0.0024292, -0.0022583, -0.00247803, -0.00233154, -0.00252686, -0.00238037, -0.00256348, -0.0024292, 0.75, -0.00246582, -0.0026001, -0.00247803, -0.0026001, -0.00249023, -0.0026001, -0.00250244, -0.0026001, -0.00251465, -0.0026001, -0.00251465, -0.0026001, -0.00251465, -0.0026001, -0.00252686, -0.00258789, -0.00252686, -0.00258789, -0.00251465, -0.00257568, -0.00251465, -0.00256348, -0.00251465, -0.00256348, -0.00251465, -0.00256348, -0.00251465, -0.00256348, -0.00251465, -0.00256348, -0.00251465, -0.00256348, -0.00252686, -0.00256348, -0.00252686, -0.00255127, -0.00252686, -0.00255127, -0.00252686, -0.00255127, -0.00252686, -0.00255127, -0.00252686, -0.00256348))) :> *(cab);\nprocess = ts9sim : stage1 : stage2 : ts.jcm2000(treble, middle, bass) : cabinet;"
 },
 {
  "id": "kpp-tubeamp",
  "name": "KPP Tube Amp",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "KPP",
  "license": "GPL-3.0-or-later",
  "shortDesc": "Profile-driven tube amp: preamp waveshaper, 3-band tonestack, push-pull power stage with supply sag. 8 built-in profiles (American Clean/Vintage, British Crunch, Modern Metal, Classic Hard, JCM800, MarkII, Twin) baked in from the .tapf files",
  "description": "Profile-driven tube amp: preamp waveshaper, 3-band tonestack, push-pull power stage with supply sag. 8 built-in profiles (American Clean/Vintage, British Crunch, Modern Metal, Classic Hard, JCM800, MarkII, Twin) baked in from the .tapf files",
  "author": "Oleg Kapitonov",
  "flags": "",
  "params": [
   {
    "label": "Drive",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 0.1,
    "unit": "",
    "path": "/KPP_Tube_Amp/Drive"
   },
   {
    "label": "Bass",
    "min": -10,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Tube_Amp/Bass"
   },
   {
    "label": "Middle",
    "min": -10,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Tube_Amp/Middle"
   },
   {
    "label": "Treble",
    "min": -10,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Tube_Amp/Treble"
   },
   {
    "label": "Master",
    "min": 0,
    "max": 100,
    "default": 50,
    "step": 0.1,
    "unit": "",
    "path": "/KPP_Tube_Amp/Master"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.001,
    "unit": "",
    "path": "/KPP_Tube_Amp/Volume"
   },
   {
    "label": "Cab Sim",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/KPP_Tube_Amp/Cab_Sim"
   },
   {
    "label": "Profile",
    "min": 0,
    "max": 7,
    "default": 2,
    "step": 1,
    "unit": "",
    "path": "/KPP_Tube_Amp/Profile"
   }
  ],
  "faustCode": "declare name \"KPP Tube Amp\";\ndeclare description \"Profile-driven tube amp: preamp waveshaper, 3-band tonestack, push-pull power stage with supply sag. 8 built-in profiles (American Clean/Vintage, British Crunch, Modern Metal, Classic Hard, JCM800, MarkII, Twin) baked in from the .tapf files\";\ndeclare author \"Oleg Kapitonov\";\ndeclare license \"GPL-3.0-or-later\";\ndeclare source \"olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_tubeamp/kpp_tubeamp.dsp (+ profiles/*.tapf header values)\";\ndeclare category \"guitar\";\ndeclare family \"amp\";\nimport(\"stdfaust.lib\");\n\nprofile    = nentry(\"[0] Profile[style:menu{'American Clean':0;'American Vintage':1;'British Crunch':2;'Modern Metal':3;'Classic Hard':4;'JCM800':5;'MarkII':6;'Twin Reverb':7}]\", 2, 0, 7, 1);\ndrive      = hslider(\"[1] Drive\", 100, 0, 100, 0.1) : si.smoo;\nbass       = hslider(\"[2] Bass[unit:dB]\", 0, -10, 10, 0.1) : si.smoo;\nmiddle     = hslider(\"[3] Middle[unit:dB]\", 0, -10, 10, 0.1) : si.smoo;\ntreble     = hslider(\"[4] Treble[unit:dB]\", 0, -10, 10, 0.1) : si.smoo;\nmastergain = hslider(\"[5] Master\", 50, 0, 100, 0.1) : si.smoo;\nvolume     = hslider(\"[6] Volume\", 1, 0, 1, 0.001) : si.smoo;\ncabmix     = hslider(\"[7] Cab Sim\", 1, 0, 1, 0.01) : si.smoo;\n\nsel(l) = ba.selectn(8, profile, l);\npreamp_level = sel((0.005, 0.005, 0.005, 2.0, 0.0071, 0.0795, 0.1155, 0.005));\npreamp_bias  = 0.0;\npreamp_Kreg  = sel((0.8, 0.8, 0.8, 2.0, 0.8, 0.8, 6.57, 0.8));\npreamp_Upor  = sel((0.8, 0.8, 0.8, 0.2, 0.8, 0.8, 0.39, 0.8));\namp_level    = sel((0.2, 0.25, 1.5, 0.06, 10.0, 0.7925, 0.1811, 0.5909));\namp_bias     = 0.2;\namp_Kreg     = sel((0.5, 0.7, 0.7, 1.0, 0.7, 0.7, 1.0, 0.7));\namp_Upor     = sel((0.2, 0.2, 0.2, 0.5, 0.2, 0.2, 0.5, 0.2));\nsag_time     = sel((0.3, 0.3, 0.3, 0.1, 0.3, 0.3, 0.1, 0.3));\nsag_coeff    = sel((0.0, 5.0, 0.5, 0.0, 0.5, 0.5, 0.0, 0.68));\noutput_level = sel((0.3125, 0.5, 0.1333, 0.2, 0.06, 0.13, 0.33, 0.18));\nts_low_freq = 20; ts_low_band = 400; ts_mid_freq = 500; ts_mid_band = 400; ts_high_freq = 10000; ts_high_band = 18000;\n\ntube(Kreg,Upor,bias,cut) = main : +(bias) : max(cut) with {\n    Ks(x) = 1/(max((x-Upor)*(Kreg),0)+1);\n    Ksplus(x) = Upor - x*Upor;\n    main(Uin) = (Uin * Ks(Uin) + Ksplus(Ks(Uin)));\n};\nstage_preamp = fi.lowpass(1,11000) : tube(preamp_Kreg,preamp_Upor,preamp_bias,-preamp_Upor);\nstage_tonestack = fi.peak_eq(bass,ts_low_freq,ts_low_band) : fi.peak_eq(middle,ts_mid_freq,ts_mid_band) : fi.peak_eq(treble,ts_high_freq,ts_high_band) : fi.lowpass(1,11000);\nstage_amp = _ <: _,*(-1.0) : tube(amp_Kreg,amp_Upor,amp_bias,0), tube(amp_Kreg,amp_Upor,amp_bias,0) : - : fi.lowpass(1, 11000);\npre_sag = fi.dcblocker : *(ba.db2linear(drive * 0.4) - 1) : *(preamp_level) : stage_preamp : fi.dcblocker : *(amp_level) : *(ba.db2linear(mastergain * 0.4) - 1) : stage_tonestack;\nsag = (_,_ : (_ <: (1.0/_),_),_ : _,* : _,stage_amp : *) ~ (_ <: _,_ : * : fi.lowpass(1,sag_time) : *(sag_coeff) : max(1.0) : min(2.5));\n// simple stand-in for the profile's 100 ms cabinet IR (not embedded)\ncab = _ <: *(1-cabmix), (*(cabmix) : fi.highpass(2, 90) : fi.peak_eq(4, 2500, 1500) : fi.lowpass(3, 5200)) :> _;\nprocess = pre_sag : sag : *(volume) : *(output_level) : fi.dcblocker : cab;"
 },
 {
  "id": "gx-gxmetal-amp",
  "name": "Metal Amp: 12AY7 pre → EL34 push-pull",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "High-gain head: 12AY7 preamp stages, tone control and an EL34 push-pull power stage.",
  "description": "Three 12AY7 triode stages through tube tables feed a tone control and a push-pull EL34 power stage modelled with the plate-loaded tubestageP table, driven by a distortion block. Pregain, Gain and Tone shape a saturated hi-gain voice.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/GxMetal_head/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp.tonestack.tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/GxMetal_head/stage2/.amp.tonestack.tone"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/GxMetal_head/stage2/.amp2.stage2.gain1"
   },
   {
    "label": "drive",
    "min": 1,
    "max": 20,
    "default": 1,
    "step": 0.1,
    "unit": "",
    "path": "/GxMetal_head/drive"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxmetal_amp.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"metal\"; // in amp tube ba.selector\ndeclare name \"GxMetal_head\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\ntstack = component(\"gx-tonestack-bm.dsp\");\ntone = tstack[tse=tstack.ts.sovtek;];\n\noverdrive(drive,x) = (x*(abs(x) + drive)/(x*x + (drive-1)*abs(x) + 1)) ;\n\nsharp = 10.0;\npress = 5 * sharp;\n\nattack  = 0.005;\nrelease = 10;\nknee    = 10.5;\nratio   = 1.5;\n\nenv = abs : max(1);\n\ncompress(env) = level * (1-r)/r\nwith {\n\tlevel = env : h ~ _ : ba.linear2db : (_ + press) : max(0)\n\twith {\n\t\th(x,y)  = f*x+(1-f)*y with { f = (x<y)*ga+(x>=y)*gr; };\n\t\tga      = exp(-1/(ma.SR*attack));\n\t\tgr      = exp(-1/(ma.SR*release));\n\t};\n\tp = level/(knee+eps) : max(0) : min(1) with { eps = 0.001; };\n\tr = 1 - p + p * ratio;\n};\n\nsharper(x) = g(x) * x\nwith {\n\tg = env : compress + sharp : ba.db2linear;\n};\n\nguitarboost = fi.highpass(2,40) : fi.lowpass(2,12000.0) : fi.allpassn(4,(-0.2, 0.3, 0.4, 0.5));\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n\ntubeax(preamp,gain1) =  hgroup(\"stage1\", stage1)  :\n                        hgroup(\"stage2\", stage2) \n                        with {\n    stage1 = tubestage(TB_12AY7_68k,86.0,2700.0,2.775058) : *(preamp):\n        fi.lowpass(1,6531.0) : tubestage(TB_12AY7_250k,132.0,1500.0,1.954308); \n    stage2 = fi.lowpass(1,6531.0) : tubestage(TB_12AY7_250k,194.0,820.0,1.264916) : *(gain1) : \n        tone : sharper<:( tubestageP(TB_EL34_68k,495.0,10.0,3.5e3, 256.0,230.0, 15.743945),\n         tubestageP(TB_EL34_250k,495.0,10.0,3.5e3, 256.0,230.0, 15.743945)):> fi.highpass(2,40) : fi.lowpass(2,12000.0) : *(gain1) ;\n};\n //tubestageP(tb,vplus,divider,Rp,fck,Rk,Vk0)\n //tubestage(tb,fck,Rk,Vk0)\nprocess =  overdrive(drive) : tubeax(preamp,gain1) : div_drive with {\n    drive = vslider(\"drive\", 1, 1, 20, 0.1);\n    div_drive = *((drive*-0.4):ba.db2linear : smoothi(0.999));\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n};"
 },
 {
  "id": "gx-gxmetal-head",
  "name": "Metal Head: 12AX7 pre → 6L6 push-pull",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "High-gain 12AX7 head into a 6L6GC push-pull power stage; tight modern distortion.",
  "description": "Three 12AX7 triode stages through tube tables feed a paralleled 6L6GC push-pull power stage modelled with the plate-loaded tubestageP table, driven by a distortion block. Pregain and Gain stack up gain for a tight, saturated metal head.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".gxdistortion.drive",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/GxMetal_head/.gxdistortion.drive"
   },
   {
    "label": ".amp2.stage1.Pregain",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/GxMetal_head/stage1/.amp2.stage1.Pregain"
   },
   {
    "label": ".amp2.stage2.gain1",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "",
    "path": "/GxMetal_head/stage3/.amp2.stage2.gain1"
   },
   {
    "label": "tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/GxMetal_head/tone"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxmetal_head.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"metal\"; // in amp tube ba.selector\ndeclare name \"GxMetal_head\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n */\n\ntubeax(preamp,gain1) =  hgroup(\"stage1\", stage1)  :\n                        hgroup(\"stage2\", stage2) : tone :\n                        hgroup(\"stage3\", stage3)\n                        with {\n    stage1 = tubestage(TB_12AX7_68k,86.0,2700.0,1.581656) : *(preamp):\n        fi.lowpass(1,6531.0) : tubestage(TB_12AX7_250k,132.0,1500.0,1.204285); \n    stage2 = fi.lowpass(1,6531.0) : tubestage(TB_12AX7_250k,194.0,820.0,0.840703)  ; \n    tone = component(\"gx-bigmuff.dsp\").bigmuff ;\n    stage3 =  *(gain1) : _<:(tubestageP(TB_6L6CG_68k,450.0,40.0,5000, 256.0,490.0,20.063657),\n        tubestageP(TB_6L6CG_250k,450.0,40.0,5000, 256.0,490.0,20.063657)):> *(gain1) :fi.lowpass(1,6531.0) ;\n};\n //tubestageP(tb,vplus,divider,Rp,fck,Rk,Vk0)\n //tubestage(tb,fck,Rk,Vk0)\n\nprocess = component(\"gx-gxdistortion.dsp\").distdrive1(drive) :\n          tubeax(preamp,gain1) : div_drive with {\n    drive = ampctrl.drive;\n    div_drive = *((drive*-12):ba.db2linear : smoothi(0.999));\n    preamp = ampctrl.preamp;\n    gain1 = ampctrl.gain1;\n};"
 },
 {
  "id": "gx-preamp",
  "name": "Polynomial Preamp",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Simple polynomial-waveshaper preamp with atan normalisation; soft drive.",
  "description": "Two cascaded low-order polynomial nonlinearities with a 3-sample moving-average filter on each side and an atan-normalised output; the drive control sets how hard the atan stage is hit. A simple soft-drive preamp, not a circuit model.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "atan",
    "min": 1,
    "max": 10,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/gx_preamp/atan"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/preamp.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n//declare name \t\t\"preamp\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nfatan = vslider(\"atan[name:drive][tooltip:Input level for pre-amp (higher level gives more distortion)]\", 1, 1, 10, 1);\nmoving_filter(x) = (x+x'+x'')/3;\nnonlin1p(x) = (x-0.15*x*x)-(0.15*(x+anti_denormal_ac)*x*x);\nnonlin2p(x) = 1.5*x - 0.5*(x+anti_denormal_ac)*x*x;\nnormalize(fatan) =  1/atan(fatan) * atan(_*fatan);\nprocess =  moving_filter : nonlin1p : nonlin2p : normalize(fatan)*0.75 : moving_filter;\n/*\n** old definition was:\n** moving_filter*0.001 : nonlin1 : nonlin2 : normalize(fatan)*750;\n*/"
 },
 {
  "id": "gx-gx-bigchump",
  "name": "Redeye Big Chump",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Redeye Big Chump small tube amp: two DK preamp stages into a power stage.",
  "description": "DK circuit simulation from the Redeye Chump schematics: two preamp stages and a power stage from the redeye library, each a pot-dependent filter followed by a clip table, run in a five-band split. Small-amp tube warmth with Gain and Tone; the feedback switch is noted in the source as not yet working.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Gain",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Redeye_Big_Chump/Gain"
   },
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Redeye_Big_Chump/Tone"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Redeye_Big_Chump/Volume"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gx_bigchump.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Redeye Big Chump\";\ndeclare category \"Amplifier\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\nimport(\"redeye.lib\");\n\ntrannie = coil1,coil2:>_ with {\n\tcoil1 = fi.lowpass( 1, ( 8075 )  ):fi.highpass( 1, 84):*(0.98)  ;\n\tcoil2 = fi.lowpass( 1, 8925 ):fi.highpass( 1, 76) ;\n}; \n\namp = bigChumpPre:bigChumpPre2:bigChumpPower:*(volume) with {\n\t\n\t// Try this as -12 -> +12 dB\n\tvolume = vslider(\"Volume[2][alias][style:knob]\",0.5, 0.0, 1.0,0.01) : smoothi(0.999);\n\n\t// This does not work at present may cut it out\n\tfeedback = *(checkbox(\"feedback\") ):fi.high_shelf( 3, 6531 ):*(-0.5);\n\n\n};\nfreq_split = fi.filterbank(3, (86.0,210.0,1200.0,6531.0));\nprocess    = freq_split: ( amp , amp , amp, amp, amp) :>_;"
 },
 {
  "id": "gx-gx-chump",
  "name": "Redeye Chump",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Redeye Chump small tube amp with selectable power-amp feedback; sweet low-watt breakup.",
  "description": "DK circuit simulation from the Redeye Chump schematic: a preamp stage with Gain and Tone into a power stage, each a pot-dependent filter followed by a clip table, with a switch between feedback and no-feedback power-amp models. Low-wattage tube breakup that stays touch sensitive.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Gain",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Redeye_Chump/Gain"
   },
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Redeye_Chump/Tone"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 4,
    "default": 2,
    "step": 0.01,
    "unit": "",
    "path": "/Redeye_Chump/Volume"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gx_chump.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Redeye Chump\"; \ndeclare name \"Redeye Chump\";\ndeclare category \"Amplifier\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\nimport(\"redeye.lib\");\n\n\ngxt = library(\"gx_tables.lib\");\n\n// Power Amp With Feedback\n\npowerfb = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) : redeyechumppowfclip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n    b0 = fs*(fs*(5.2572119847844e-14*fs + 2.22632342602781e-12) + 5.41994006909799e-15);\n\n    b1 = fs*(fs*(-1.57716359543532e-13*fs - 2.22632342602781e-12) + 5.41994006909799e-15);\n\n    b2 = fs*(fs*(1.57716359543532e-13*fs - 2.22632342602781e-12) - 5.41994006909799e-15);\n\n    b3 = fs*(fs*(-5.2572119847844e-14*fs + 2.22632342602781e-12) - 5.41994006909799e-15);\n\n    a0 = fs*(fs*(9.01314076551628e-15*fs + 1.3955910672935e-12) + 6.86346038146649e-11) + 1.79996158094636e-10;\n\n    a1 = fs*(fs*(-2.70394222965488e-14*fs - 1.3955910672935e-12) + 6.86346038146649e-11) + 5.39988474283909e-10;\n\n    a2 = fs*(fs*(2.70394222965488e-14*fs - 1.3955910672935e-12) - 6.86346038146649e-11) + 5.39988474283909e-10;\n\n    a3 = fs*(fs*(-9.01314076551628e-15*fs + 1.3955910672935e-12) - 6.86346038146649e-11) + 1.79996158094636e-10;\n};\n\nredeyechumppowfclip = _<: ba.if(signbit(_), redeyechumppowf_neg_clip, redeyechumppowf_clip) :>_ with {\nsignbit(x) = (x < 0);redeyechumppowf_clip = gxt.redeyechumppowfclip;redeyechumppowf_neg_clip = gxt.redeyechumppowf_negclip;\n};\n// Power Amp No feedback\npowernfb = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) : redeyechumppowclip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n    b0 = pow(fs,2)*(8.08665507806617e-14*fs + 3.42440032262935e-12);\n\n    b1 = pow(fs,2)*(-2.42599652341985e-13*fs - 3.42440032262935e-12);\n\n    b2 = pow(fs,2)*(2.42599652341985e-13*fs - 3.42440032262935e-12);\n\n    b3 = pow(fs,2)*(-8.08665507806617e-14*fs + 3.42440032262935e-12);\n\n    a0 = fs*(fs*(9.00050108040552e-15*fs + 2.00144504609273e-12) + 1.09475884941298e-10) + 2.87117546539927e-10;\n\n    a1 = fs*(fs*(-2.70015032412166e-14*fs - 2.00144504609273e-12) + 1.09475884941298e-10) + 8.6135263961978e-10;\n\n    a2 = fs*(fs*(2.70015032412166e-14*fs - 2.00144504609273e-12) - 1.09475884941298e-10) + 8.6135263961978e-10;\n\n    a3 = fs*(fs*(-9.00050108040552e-15*fs + 2.00144504609273e-12) - 1.09475884941298e-10) + 2.87117546539927e-10;\n};\n\nredeyechumppowclip = _<: ba.if(signbit(_), redeyechumppow_neg_clip, redeyechumppow_clip) :>_ with {\nsignbit(x) = (x < 0);redeyechumppow_clip = gxt.redeyechumppowclip;redeyechumppow_neg_clip = gxt.redeyechumppow_negclip;\n};\n\n\n//volume =  vslider(\"Volume[alias][style:knob]\",3.0,0.0,12.0,0.01):ba.db2linear:smoothi(0.999);\nvolume =  vslider(\"Volume[alias][style:knob]\",2.0,0.0,4.0,0.01):smoothi(0.999);\n\namp = chumpPreamp:poweramp:*(volume) ;\npoweramp = _<:powerfb,powernfb:select2( checkbox(\"feedback\") ) ;\n\nfreq_split = fi.filterbank(3, (86.0,210.0,1200.0,6531.0));\nprocess    = freq_split: ( amp , amp , amp, amp, amp) :>_;"
 },
 {
  "id": "gx-gx-vibrochump",
  "name": "Redeye Vibro Chump",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Redeye Chump amp with vactrol tremolo and a presence-style power-stage feedback loop.",
  "description": "DK circuit simulation of the Redeye Chump preamp and power stage, with a feedback loop around the power tube that acts as a presence control and a built-in vactrol (LDR) tremolo with Speed and Intensity. A small tube amp with amp-style tremolo.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Gain",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Redeye_Vibro_Chumo/Gain"
   },
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Redeye_Vibro_Chumo/Tone"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Redeye_Vibro_Chumo/Amp/Volume"
   },
   {
    "label": "speed",
    "min": 0.1,
    "max": 10,
    "default": 5,
    "step": 0.1,
    "unit": "",
    "path": "/Redeye_Vibro_Chumo/Tremelo/speed"
   },
   {
    "label": "intensity",
    "min": 0,
    "max": 10,
    "default": 5,
    "step": 0.1,
    "unit": "",
    "path": "/Redeye_Vibro_Chumo/Tremelo/intensity"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gx_vibrochump.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Redeye Vibro Chump\"; // in amp tube ba.selector\ndeclare name \"Redeye Vibro Chumo\";\ndeclare category \"Amplifier\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\nimport(\"redeye.lib\");\n\n/****************************************************************\n ** Tube Preamp Emulation stage 1 - 2 \n**\n** SHP : Experiment with the presence control as a feedback loop\n**\tCreated a loop with high shelf filter cutting around 1khz and up \n**    pot controls the amount of cut 0 > -70dB \n**    If feedback loop is inverted get mad distortion and feedback!\n**   With no inversion get required effect so guess the combination \n**  of filter and processing de.delay may be shifting phase some\n**\n** To do :\n**\tPlay with amp structure say a champ clone\n** \ttube:eq:tube:tube\n**\t12AX7:??:12AX7:6V6\n**\n**\tMove feedback loop in more complex amp around driver and power tube\n**\t12AX7:EQ:(12AX7:6V6)~FEEDBACK \n*/\n\n/*\n** Model of a vactrol tremolo unit by \"transmogrify\"\n** c.f. http://sourceforge.net/apps/phpbb/guitarix/viewtopic.php?f=7&t=44&p=233&hilit=transmogrifox#p233\n** http://transmogrifox.webs.com/vactrol.m\n*/\n/* vactrol model */\n\nR1 = 2700;\nRa = 1e6;\nRb = 300;\nb = exp(log(Ra)/log(Rb)) - exp(1);\ndTC = 0.06;\nminTC = log(0.005/dTC);\n\ncds = ((_ <: _,_),_ : _+(1-alpha)*_) ~ (_<:*(alpha)) with {\n    iSR = 1/ma.SR;\n    dRC = dTC * exp(*(minTC));\n    alpha = 1 - iSR / (dRC + iSR);\n};\n\nvactrol = pow(_,1.9) : cds : *(b) + exp(1) : exp(log(Ra)/log) : R1/(_ + R1);\n\n/* os.triangle oscillator (not bandlimited, frequency is approximate) */\n\ntrianglewave(freq) = _ ~ (_ <: _ + hyst) : /(periodsamps) with {\n    if(c,t,e) = select2(c,e,t);\n    hyst(x) = if(_ > 0, 2 * (x < periodsamps) - 1, 1 - 2 * (x > 0)) ~ _;\n    periodsamps = int(ma.SR / (2*float(freq)));\n};\n \namp = bigChumpPre:*(vibe):bigChumpPre2:bigChumpPower:*(volume) with{\n\n\tvolume =  hgroup( \"Amp\",vslider(\"Volume[alias][style:knob]\",0.5,0,1,0.01):smoothi(0.999) );\n\t\n\t// Tremelo effect\n\n/* tremolo unit, using os.triangle or sine oscillator as lfo */\n\ntremolo(freq, depth) = lfo * depth + 1 - depth : vactrol with {\n    sine(freq) = (os.oscs(freq) + 1) / 2 : max(0); // max(0) because of numerical inaccuracy\n\n    SINE=hgroup( \"Tremelo\",checkbox(\"SINEWAVE[3][enum:os.triangle|sine]\") );\n    \n    lfo = select2(SINE, trianglewave(freq), sine(freq));\n};\n\n\tspeed = hgroup( \"Tremelo\",vslider(\"speed[2][style:knob]\",5,0.1,10,0.1) ) ;\n\tintensity = hgroup( \"Tremelo\", vslider(\"intensity[1][style:knob]\",5,0,10,0.1)/10.2 ) ;\n\teffect =  tremolo(speed,intensity);\n\tvof = hgroup( \"Tremelo\",checkbox(\"vibe[0][enum:Off|On]\"));\n\tvibe = select2(vof, effect, 1.0) ;\n\n\t\n};\nfreq_split = fi.filterbank(3, (86.0,210.0,1200.0,6531.0));\nprocess    = freq_split: ( amp , amp , amp, amp, amp) :>_;"
 },
 {
  "id": "gx-reso-tube",
  "name": "Resonant Tube",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Tube-style clipper feeding a short resonant delay; fuzzy, ringing overtones.",
  "description": "A polynomial tube-style nonlinearity into a short feedback comb resonator (Vibrato sets the delay, Resonance the feedback) with symmetric clipping, mixed with the dry signal. Adds ringing, resonant harmonics rather than modelling a specific circuit.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "vibrato",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/gx_reso_tube/vibrato"
   },
   {
    "label": "resonanz",
    "min": 0,
    "max": 0.9,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/gx_reso_tube/resonanz"
   },
   {
    "label": "fuzzy",
    "min": -3,
    "max": 10,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/gx_reso_tube/fuzzy"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/reso_tube.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"tube2\";\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nresonator = (+ <: (de.delay(4096, d-1) + de.delay(4096, d))/2.0)~*(1.0-a)\nwith {\n//d = vslider(\"vibrato\", 0.5, 0, 1, 0.01);\nd = 1 - vslider(\"vibrato[alias]\", 1, 0, 1, 0.01);\n//a = vslider(\"trigger\", 0.12, 0, 1, 0.01);\na = 0.9 - vslider(\"resonanz[alias]\", 0.5, 0, 0.9, 0.01);\n};\n\n//fuzzy = vslider(\"fuzzy\", 0.5, 0, 1, 0.01);\nfuzzy = vslider(\"fuzzy[name:tube][alias]\", 1, -3, 10, 1);\ntube1 = nonlin1 : resonator * fuzzy * 0.5 : sym_clip(0.7) : ma.neg;\n\nprocess = add_dc <: _ + tube1 : sym_clip(0.7);"
 },
 {
  "id": "gx-tube3",
  "name": "Valve Stage (Bendiksen ×2, gain)",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Two Bendiksen triode-model stages with gain, Q and dist controls; ported from swh Valve.",
  "description": "Two inverting passes through the Bendiksen valve model from Steve Harris's swh-plugins Valve, with an inter-stage gain control. Dist sets distortion amount and Q the asymmetry, giving a soft triode-style saturation.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "g",
    "min": 0.2,
    "max": 2,
    "default": 1,
    "step": 0.1,
    "unit": "",
    "path": "/gx_tube3/g"
   },
   {
    "label": "q",
    "min": 0.4,
    "max": 1,
    "default": 0.4,
    "step": 0.001,
    "unit": "",
    "path": "/gx_tube3/q"
   },
   {
    "label": "dist",
    "min": 0,
    "max": 1.7,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/gx_tube3/dist"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tube3.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// dsp algorithm from swh ladspa valve plugin (Steve Harrison)\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\ng = vslider(\"g\", 1, 0.2, 2, 0.1);\n\nvt = valve.vt(dist, q) : *(g) : ma.neg : valve.vt(dist, q) : ma.neg with\n{\n        q_p = vslider(\"q\", 0.4, 0.4, 1, 0.001);\n        dist_p = vslider(\"dist\", 0, 0, 1.7, 0.01);\n        q = -q_p*-q_p*-q_p;\n        dist = pow(10,dist_p);\n};\n\nprocess = vt  ;"
 },
 {
  "id": "gx-valve",
  "name": "Valve Stage (Bendiksen ×2)",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Two Bendiksen triode-model stages back to back; soft valve saturation.",
  "description": "Two inverting passes through the Bendiksen valve model from Steve Harris's swh-plugins Valve. Dist controls the distortion amount and Q the bias/asymmetry, giving a soft, even-harmonic valve saturation.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "q",
    "min": -1.7,
    "max": 1.7,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/gx_valve/q"
   },
   {
    "label": "dist",
    "min": -2,
    "max": 2,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/gx_valve/dist"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/valve.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// dsp algorithm from swh ladspa valve plugin (Steve Harrison)\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nvt = valve.vt(dist, q) : ma.neg : valve.vt(dist, q) : ma.neg with\n{\n        q_p = vslider(\"q\", 0, -1.7, 1.7, 0.01);\n        dist_p = vslider(\"dist\", 0, -2, 2, 0.01);\n        q = q_p*q_p*q_p;\n        dist = pow(10,dist_p);\n};\n\nvtu = valve.vt(dist, q) with\n{\n        q_p = vslider(\"q\", 0, -1.7, 1.7, 0.01);\n        dist_p = vslider(\"dist\", 0, -2, 2, 0.01);\n        q = q_p*q_p*q_p;\n        dist = pow(10,dist_p);\n};\n\nvts(x) = abs(x) : ma.neg : valve.vt(dist, q) : ma.neg : copysign(_,x)\nwith\n{\n        q_p = vslider(\"q\", 0, -1.7, 1.7, 0.01);\n        dist_p = vslider(\"dist\", 0, -2, 2, 0.01);\n        q = q_p*q_p*q_p;\n        dist = pow(10,dist_p);\ncopysign = ma.copysign;\n};\n\nprocess = vt;"
 },
 {
  "id": "gx-gx-w20",
  "name": "Westbury W-20",
  "category": "guitar",
  "family": "amp",
  "familyName": "Amp & Tube",
  "icon": "tabler:device-speaker",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Westbury W-20 12AX7 preamp with Gain and Level; clean-to-crunch tube preamp.",
  "description": "DK circuit simulation from the schematic of the Westbury W-20 preamp: two 12AX7 stages as pot-dependent filters with clip tables, run in a five-band split. A straightforward Gain/Level tube preamp for clean to crunchy tones.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Gain",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Westbury_W-20/Gain"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Westbury_W-20/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gx_w20.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"w20\";\ndeclare name \"Westbury W-20\";\ndeclare category \"External\";\n\nimport(\"stdfaust.lib\");\n\ngxt = library(\"gx_tables.lib\");\n\np1 = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) : w20_1clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n    Gain = vslider(\"Gain[name:Gain]\", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(3) : si.smooth(s);\n\n    b0 = Gain*(Gain*pow(fs,2)*(1.44375296887024e-12*fs + 2.1875044982882e-11) + fs*(fs*(-1.44375296887024e-12*fs - 7.24063988933406e-9) - 1.0937522491441e-7));\n\n    b1 = Gain*(Gain*pow(fs,2)*(-4.33125890661071e-12*fs - 2.1875044982882e-11) + fs*(fs*(4.33125890661071e-12*fs + 7.24063988933406e-9) - 1.0937522491441e-7));\n\n    b2 = Gain*(Gain*pow(fs,2)*(4.33125890661071e-12*fs - 2.1875044982882e-11) + fs*(fs*(-4.33125890661071e-12*fs + 7.24063988933406e-9) + 1.0937522491441e-7));\n\n    b3 = Gain*(Gain*pow(fs,2)*(-1.44375296887024e-12*fs + 2.1875044982882e-11) + fs*(fs*(1.44375296887024e-12*fs - 7.24063988933406e-9) + 1.0937522491441e-7));\n\n    a0 = Gain*(Gain*pow(fs,2)*(-2.37114810573187e-14*fs - 6.90938348698522e-13) + fs*(fs*(2.29013691097909e-14*fs - 1.12102439518276e-11) - 3.45469174349261e-10)) + fs*(fs*(8.10111947527771e-16*fs + 1.34509147324758e-10) + 6.33060724204724e-8) + 1.72734587174631e-6;\n\n    a1 = Gain*(Gain*pow(fs,2)*(7.1134443171956e-14*fs + 6.90938348698522e-13) + fs*(fs*(-6.87041073293727e-14*fs + 1.12102439518276e-11) - 3.45469174349261e-10)) + fs*(fs*(-2.43033584258331e-15*fs - 1.34509147324758e-10) + 6.33060724204724e-8) + 5.18203761523892e-6;\n\n    a2 = Gain*(Gain*pow(fs,2)*(-7.1134443171956e-14*fs + 6.90938348698522e-13) + fs*(fs*(6.87041073293727e-14*fs + 1.12102439518276e-11) + 3.45469174349261e-10)) + fs*(fs*(2.43033584258331e-15*fs - 1.34509147324758e-10) - 6.33060724204724e-8) + 5.18203761523892e-6;\n\n    a3 = Gain*(Gain*pow(fs,2)*(2.37114810573187e-14*fs - 6.90938348698522e-13) + fs*(fs*(-2.29013691097909e-14*fs - 1.12102439518276e-11) + 3.45469174349261e-10)) + fs*(fs*(-8.10111947527771e-16*fs + 1.34509147324758e-10) - 6.33060724204724e-8) + 1.72734587174631e-6;\n};\n\nw20_1clip = _<: ba.if(signbit(_), w20_1_neg_clip, w20_1_clip) :>_ with {\nsignbit(x) = (x < 0);w20_1_clip = gxt.w20_1clip;w20_1_neg_clip = gxt.w20_1_negclip;\n};\n\np2 =  pre : fi.iir((b0/a0,b1/a0),(a1/a0)) : w20_2aclip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n    Level = vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(3) : si.smooth(s);\n\n    b0 = -0.000616100994039436*Level*fs;\n\n    b1 = 0.000616100994039436*Level*fs;\n\n    a0 = 2.07411011655813e-5*fs + 0.00442714405209691;\n\n    a1 = -2.07411011655813e-5*fs + 0.00442714405209691;\n};\n\nw20_2aclip = _<: ba.if(signbit(_), w20_2a_neg_clip, w20_2a_clip) :>_ with {\nsignbit(x) = (x < 0);w20_2a_clip = gxt.w20_2aclip;w20_2a_neg_clip = gxt.w20_2a_negclip;\n};\n\namp =  p1:p2 ;\nfreq_split = fi.filterbank(3, (86.0,210.0,1200.0,6531.0));\nprocess    = freq_split: ( amp , amp , amp, amp, amp) :>_;"
 },
 {
  "id": "lib-adaa-drive",
  "name": "ADAA Drive",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Alias-suppressed clipper (antiderivative anti-aliasing) with hard/tanh/quadratic modes, pre-gain and tone",
  "description": "Alias-suppressed clipper (antiderivative anti-aliasing) with hard/tanh/quadratic modes, pre-gain and tone",
  "author": "Dario Sanfilippo",
  "flags": "",
  "params": [
   {
    "label": "Mode",
    "min": 0,
    "max": 2,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/ADAA_Drive/Mode"
   },
   {
    "label": "Drive",
    "min": 0,
    "max": 48,
    "default": 18,
    "step": 0.1,
    "unit": "dB",
    "path": "/ADAA_Drive/Drive"
   },
   {
    "label": "Low Cut",
    "min": 30,
    "max": 800,
    "default": 100,
    "step": 1,
    "unit": "Hz",
    "path": "/ADAA_Drive/Low_Cut"
   },
   {
    "label": "Tone",
    "min": 800,
    "max": 12000,
    "default": 4500,
    "step": 1,
    "unit": "Hz",
    "path": "/ADAA_Drive/Tone"
   },
   {
    "label": "Level",
    "min": -30,
    "max": 12,
    "default": -6,
    "step": 0.1,
    "unit": "dB",
    "path": "/ADAA_Drive/Level"
   }
  ],
  "faustCode": "declare name \"ADAA Drive\";\ndeclare description \"Alias-suppressed clipper (antiderivative anti-aliasing) with hard/tanh/quadratic modes, pre-gain and tone\";\ndeclare author \"Dario Sanfilippo\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/aanl.lib aa.hardclip aa.tanh1 aa.softclipQuadratic1\";\ndeclare category \"guitar\";\ndeclare family \"dirt\";\nimport(\"stdfaust.lib\");\n\nmode  = nentry(\"[0] Mode[style:menu{'Hard':0;'Tanh':1;'Quadratic':2}]\", 1, 0, 2, 1);\ndrive = hslider(\"[1] Drive[unit:dB]\", 18, 0, 48, 0.1) : ba.db2linear : si.smoo;\nbass  = hslider(\"[2] Low Cut[unit:Hz][scale:log]\", 100, 30, 800, 1) : si.smoo;\ntone  = hslider(\"[3] Tone[unit:Hz][scale:log]\", 4500, 800, 12000, 1) : si.smoo;\nlevel = hslider(\"[4] Level[unit:dB]\", -6, -30, 12, 0.1) : ba.db2linear : si.smoo;\n\nclip = _ <: aa.hardclip, aa.tanh1, aa.softclipQuadratic1 : ba.selectn(3, mode);\nprocess = fi.highpass(1, bass) : *(drive) : clip : fi.dcblocker : fi.lowpass(1, tone) : *(level);"
 },
 {
  "id": "gx-astrofuzz",
  "name": "Astrotone Fuzz",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Sam Ash Astrotone-style two-transistor fuzz with Tone, Volume and Attack.",
  "description": "DK circuit simulation from the Astrotone schematic: pot-dependent filters followed by two transistor-stage tables. A smooth, vintage two-transistor fuzz where Attack sets the fuzz amount and Tone tilts the voicing.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Astrotone_Fuzz/Tone"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Astrotone_Fuzz/Volume"
   },
   {
    "label": "Attack",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Astrotone_Fuzz/Attack"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/astrofuzz.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"astrofuzz\";\ndeclare name \"Astrotone Fuzz\";\ndeclare category \"Fuzz\";\ndeclare shortname \"Astrotone\";\ndeclare description \"Astrotone Fuzz\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\nprocess = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) : clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    clip = tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) ;\n\n    \n        Tone = vslider(\"Tone[name:Tone]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Volume = vslider(\"Volume[name:Volume]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Attack = vslider(\"Attack[name:Attack]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Attack*Volume*(1.00499515996459e-12*Tone*pow(fs,3) - 1.18589428875822e-12*pow(fs,3));\n\n    b1 = Attack*Volume*(-3.01498547989378e-12*Tone*pow(fs,3) + 3.55768286627466e-12*pow(fs,3));\n\n    b2 = Attack*Volume*(3.01498547989378e-12*Tone*pow(fs,3) - 3.55768286627466e-12*pow(fs,3));\n\n    b3 = Attack*Volume*(-1.00499515996459e-12*Tone*pow(fs,3) + 1.18589428875822e-12*pow(fs,3));\n\n    a0 = Attack*(Attack*(Tone*fs*(fs*(3.46486099611082e-14*fs + 3.92502015729988e-11) + 2.59598111483739e-9) + fs*(fs*(-4.09854197590519e-14*fs - 8.31252171811903e-11) - 5.6592388303455e-9)) + Tone*fs*(fs*(-3.46486099611082e-14*fs - 3.92502015729988e-11) - 2.59598111483739e-9) + fs*(fs*(4.09854197590519e-14*fs + 8.31252171811903e-11) + 5.6592388303455e-9)) + Tone*(fs*(fs*(-3.79430966640243e-15*fs - 7.96218897097081e-12) - 4.44205261980514e-9) - 2.76168203706105e-7) + fs*(fs*(4.49290068884749e-15*fs + 1.34316849964884e-11) + 9.42407659969146e-9) + 6.02046684079309e-7;\n\n    a1 = Attack*(Attack*(Tone*fs*(fs*(-1.03945829883325e-13*fs - 3.92502015729988e-11) + 2.59598111483739e-9) + fs*(fs*(1.22956259277156e-13*fs + 8.31252171811903e-11) - 5.6592388303455e-9)) + Tone*fs*(fs*(1.03945829883325e-13*fs + 3.92502015729988e-11) - 2.59598111483739e-9) + fs*(fs*(-1.22956259277156e-13*fs - 8.31252171811903e-11) + 5.6592388303455e-9)) + Tone*(fs*(fs*(1.13829289992073e-14*fs + 7.96218897097081e-12) - 4.44205261980514e-9) - 8.28504611118315e-7) + fs*(fs*(-1.34787020665425e-14*fs - 1.34316849964884e-11) + 9.42407659969146e-9) + 1.80614005223793e-6;\n\n    a2 = Attack*(Attack*(Tone*fs*(fs*(1.03945829883325e-13*fs - 3.92502015729988e-11) - 2.59598111483739e-9) + fs*(fs*(-1.22956259277156e-13*fs + 8.31252171811903e-11) + 5.6592388303455e-9)) + Tone*fs*(fs*(-1.03945829883325e-13*fs + 3.92502015729988e-11) + 2.59598111483739e-9) + fs*(fs*(1.22956259277156e-13*fs - 8.31252171811903e-11) - 5.6592388303455e-9)) + Tone*(fs*(fs*(-1.13829289992073e-14*fs + 7.96218897097081e-12) + 4.44205261980514e-9) - 8.28504611118315e-7) + fs*(fs*(1.34787020665425e-14*fs - 1.34316849964884e-11) - 9.42407659969146e-9) + 1.80614005223793e-6;\n\n    a3 = Attack*(Attack*(Tone*fs*(fs*(-3.46486099611082e-14*fs + 3.92502015729988e-11) - 2.59598111483739e-9) + fs*(fs*(4.09854197590519e-14*fs - 8.31252171811903e-11) + 5.6592388303455e-9)) + Tone*fs*(fs*(3.46486099611082e-14*fs - 3.92502015729988e-11) + 2.59598111483739e-9) + fs*(fs*(-4.09854197590519e-14*fs + 8.31252171811903e-11) - 5.6592388303455e-9)) + Tone*(fs*(fs*(3.79430966640243e-15*fs - 7.96218897097081e-12) + 4.44205261980514e-9) - 2.76168203706105e-7) + fs*(fs*(-4.49290068884749e-15*fs + 1.34316849964884e-11) - 9.42407659969146e-9) + 6.02046684079309e-7;\n};"
 },
 {
  "id": "gx-axface",
  "name": "Ax Face",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Fuzz Face-style transistor fuzz with Attack, Smooth and Level.",
  "description": "DK circuit simulation from the schematic of the Ax Face fuzz: a pot-dependent state-space filter followed by two transistor-stage tables. Attack sets the fuzz amount and Smooth softens the edge for a vintage two-transistor fuzz.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Attack",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Axis_Face/Attack"
   },
   {
    "label": "Smooth",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Axis_Face/Smooth"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Axis_Face/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/axface.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"axface\";\ndeclare name \"Axis Face\";\ndeclare category \"Fuzz\";\ndeclare shortname \"Axis Face\";\ndeclare description \"Axis Face\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\nprocess = pre :  fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0)) : clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    clip = tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) ;\n\n    \n        Attack = vslider(\"Attack[name:Attack]\", 0.5, 0, 1, 0.01) : Inverted(0)  : si.smooth(s);\n    \n        Smooth = vslider(\"Smooth[name:Smooth]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Level = vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Attack*(Attack*Level*pow(fs,3)*(3.38149630023061e-21*fs - 1.69477435943983e-16) + Level*pow(fs,3)*(-3.86160790724035e-21*fs + 1.70600223084551e-14)) + Level*pow(fs,2)*(-1.28720263574678e-19*fs + 5.68667410281837e-13);\n\n    b1 = Attack*(Attack*Level*pow(fs,3)*(-1.01444889006918e-20*fs + 1.69477435943983e-16) + Level*pow(fs,3)*(1.15848237217211e-20*fs - 1.70600223084551e-14)) + Level*pow(fs,2)*(1.28720263574678e-19*fs + 5.68667410281837e-13);\n\n    b2 = Attack*(Attack*Level*pow(fs,3)*(6.76299260046122e-21*fs + 3.38954871887967e-16) + Level*pow(fs,3)*(-7.7232158144807e-21*fs - 3.41200446169102e-14)) + Level*pow(fs,2)*(2.57440527149357e-19*fs - 1.13733482056367e-12);\n\n    b3 = Attack*(Attack*Level*pow(fs,3)*(6.76299260046122e-21*fs - 3.38954871887967e-16) + Level*pow(fs,3)*(-7.7232158144807e-21*fs + 3.41200446169102e-14)) + Level*pow(fs,2)*(-2.57440527149357e-19*fs - 1.13733482056367e-12);\n\n    b4 = Attack*(Attack*Level*pow(fs,3)*(-1.01444889006918e-20*fs - 1.69477435943983e-16) + Level*pow(fs,3)*(1.15848237217211e-20*fs + 1.70600223084551e-14)) + Level*pow(fs,2)*(-1.28720263574678e-19*fs + 5.68667410281837e-13);\n\n    b5 = Attack*(Attack*Level*pow(fs,3)*(3.38149630023061e-21*fs + 1.69477435943983e-16) + Level*pow(fs,3)*(-3.86160790724035e-21*fs - 1.70600223084551e-14)) + Level*pow(fs,2)*(1.28720263574678e-19*fs + 5.68667410281837e-13);\n\n    a0 = Attack*(Attack*fs*(fs*(fs*(fs*(-4.03791059191999e-25*fs - 1.13427407987086e-18) - 1.49739128868709e-14) - 7.44393603614497e-12) - 1.60942285815325e-10) + fs*(fs*(fs*(fs*(5.1173274738794e-25*fs + 1.13834320666478e-18) + 1.49968987528957e-14) + 7.45459961503187e-12) + 1.61087815478651e-10)) + Smooth*(Attack*(Attack*pow(fs,2)*(fs*(fs*(3.77313513934094e-25*fs + 1.13011470525257e-18) + 1.48978106454603e-14) + 7.08146057587431e-12) + pow(fs,2)*(fs*(fs*(-4.4415330562134e-25*fs - 1.13263345455505e-18) - 1.49120085362402e-14) - 7.08786388106065e-12)) + fs*(fs*(fs*(-1.4805110187378e-23*fs - 3.77544484851683e-17) - 4.97066951208006e-13) - 2.36262129368688e-10)) + fs*(fs*(fs*(1.70577582462647e-23*fs + 3.79447735554928e-17) + 4.99896625096522e-13) + 2.48486653834396e-10) + 5.36959384928837e-9;\n\n    a1 = Attack*(Attack*fs*(fs*(fs*(fs*(2.01895529596e-24*fs + 3.40282223961257e-18) + 1.49739128868709e-14) - 7.44393603614497e-12) - 4.82826857445976e-10) + fs*(fs*(fs*(fs*(-2.5586637369397e-24*fs - 3.41502961999435e-18) - 1.49968987528957e-14) + 7.45459961503187e-12) + 4.83263446435953e-10)) + Smooth*(Attack*(Attack*pow(fs,2)*(fs*(fs*(-1.88656756967047e-24*fs - 3.39034411575772e-18) - 1.48978106454603e-14) + 7.08146057587431e-12) + pow(fs,2)*(fs*(fs*(2.2207665281067e-24*fs + 3.39790036366515e-18) + 1.49120085362402e-14) - 7.08786388106065e-12)) + fs*(fs*(fs*(4.4415330562134e-23*fs + 3.77544484851683e-17) - 4.97066951208006e-13) - 7.08786388106065e-10)) + fs*(fs*(fs*(-5.1173274738794e-23*fs - 3.79447735554928e-17) + 4.99896625096522e-13) + 7.45459961503187e-10) + 2.68479692464418e-8;\n\n    a2 = Attack*(Attack*fs*(fs*(fs*(fs*(-4.03791059191999e-24*fs - 2.26854815974171e-18) + 2.99478257737419e-14) + 1.48878720722899e-11) - 3.21884571630651e-10) + fs*(fs*(fs*(fs*(5.1173274738794e-24*fs + 2.27668641332957e-18) - 2.99937975057913e-14) - 1.49091992300637e-11) + 3.22175630957302e-10)) + Smooth*(Attack*(Attack*pow(fs,2)*(fs*(fs*(3.77313513934094e-24*fs + 2.26022941050514e-18) - 2.97956212909206e-14) - 1.41629211517486e-11) + pow(fs,2)*(fs*(fs*(-4.4415330562134e-24*fs - 2.2652669091101e-18) + 2.98240170724803e-14) + 1.41757277621213e-11)) + fs*(fs*(fs*(-2.9610220374756e-23*fs + 7.55088969703365e-17) + 9.94133902416011e-13) - 4.72524258737377e-10)) + fs*(fs*(fs*(3.41155164925293e-23*fs - 7.58895471109855e-17) - 9.99793250193045e-13) + 4.96973307668791e-10) + 5.36959384928837e-8;\n\n    a3 = Attack*(Attack*fs*(fs*(fs*(fs*(4.03791059191999e-24*fs - 2.26854815974171e-18) - 2.99478257737419e-14) + 1.48878720722899e-11) + 3.21884571630651e-10) + fs*(fs*(fs*(fs*(-5.1173274738794e-24*fs + 2.27668641332957e-18) + 2.99937975057913e-14) - 1.49091992300637e-11) - 3.22175630957302e-10)) + Smooth*(Attack*(Attack*pow(fs,2)*(fs*(fs*(-3.77313513934094e-24*fs + 2.26022941050514e-18) + 2.97956212909206e-14) - 1.41629211517486e-11) + pow(fs,2)*(fs*(fs*(4.4415330562134e-24*fs - 2.2652669091101e-18) - 2.98240170724803e-14) + 1.41757277621213e-11)) + fs*(fs*(fs*(-2.9610220374756e-23*fs - 7.55088969703365e-17) + 9.94133902416011e-13) + 4.72524258737377e-10)) + fs*(fs*(fs*(3.41155164925293e-23*fs + 7.58895471109855e-17) - 9.99793250193045e-13) - 4.96973307668791e-10) + 5.36959384928837e-8;\n\n    a4 = Attack*(Attack*fs*(fs*(fs*(fs*(-2.01895529596e-24*fs + 3.40282223961257e-18) - 1.49739128868709e-14) - 7.44393603614497e-12) + 4.82826857445976e-10) + fs*(fs*(fs*(fs*(2.5586637369397e-24*fs - 3.41502961999435e-18) + 1.49968987528957e-14) + 7.45459961503187e-12) - 4.83263446435953e-10)) + Smooth*(Attack*(Attack*pow(fs,2)*(fs*(fs*(1.88656756967047e-24*fs - 3.39034411575772e-18) + 1.48978106454603e-14) + 7.08146057587431e-12) + pow(fs,2)*(fs*(fs*(-2.2207665281067e-24*fs + 3.39790036366515e-18) - 1.49120085362402e-14) - 7.08786388106065e-12)) + fs*(fs*(fs*(4.4415330562134e-23*fs - 3.77544484851683e-17) - 4.97066951208006e-13) + 7.08786388106065e-10)) + fs*(fs*(fs*(-5.1173274738794e-23*fs + 3.79447735554928e-17) + 4.99896625096522e-13) - 7.45459961503187e-10) + 2.68479692464418e-8;\n\n    a5 = Attack*(Attack*fs*(fs*(fs*(fs*(4.03791059191999e-25*fs - 1.13427407987086e-18) + 1.49739128868709e-14) - 7.44393603614497e-12) + 1.60942285815325e-10) + fs*(fs*(fs*(fs*(-5.1173274738794e-25*fs + 1.13834320666478e-18) - 1.49968987528957e-14) + 7.45459961503187e-12) - 1.61087815478651e-10)) + Smooth*(Attack*(Attack*pow(fs,2)*(fs*(fs*(-3.77313513934094e-25*fs + 1.13011470525257e-18) - 1.48978106454603e-14) + 7.08146057587431e-12) + pow(fs,2)*(fs*(fs*(4.4415330562134e-25*fs - 1.13263345455505e-18) + 1.49120085362402e-14) - 7.08786388106065e-12)) + fs*(fs*(fs*(-1.4805110187378e-23*fs + 3.77544484851683e-17) - 4.97066951208006e-13) + 2.36262129368688e-10)) + fs*(fs*(fs*(1.70577582462647e-23*fs - 3.79447735554928e-17) + 4.99896625096522e-13) - 2.48486653834396e-10) + 5.36959384928837e-9;\n};"
 },
 {
  "id": "barabas-tubescreamer",
  "name": "Barabas Tube Screamer",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "Barabas5532",
  "license": "GPL-3.0-or-later",
  "shortDesc": "Minimal TS-style overdrive: 720 Hz input highpass, cubic soft clip, sweepable 1-pole tone (350-4500 Hz), volume",
  "description": "Minimal TS-style overdrive: 720 Hz input highpass, cubic soft clip, sweepable 1-pole tone (350-4500 Hz), volume",
  "author": "Barabas Raffai",
  "flags": "",
  "params": [
   {
    "label": "Gain",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Barabas_Tube_Screamer/Gain"
   },
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Barabas_Tube_Screamer/Tone"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/Barabas_Tube_Screamer/Volume"
   }
  ],
  "faustCode": "declare name \"Barabas Tube Screamer\";\ndeclare description \"Minimal TS-style overdrive: 720 Hz input highpass, cubic soft clip, sweepable 1-pole tone (350-4500 Hz), volume\";\ndeclare author \"Barabas Raffai\";\ndeclare license \"GPL-3.0-or-later\";\ndeclare source \"Barabas5532/TubeScreamer tubescreamer.dsp\";\ndeclare category \"guitar\";\ndeclare family \"dirt\";\nimport(\"stdfaust.lib\");\n\ngain   = hslider(\"[0] Gain\", 0.5, 0, 1, 0.01) : si.smoo;\ntone   = hslider(\"[1] Tone\", 0.5, 0, 1, 0.01) : si.smoo;\nvolume = hslider(\"[2] Volume\", 0.7, 0, 1, 0.01) : si.smoo;\ninput_filter = fi.highpass(1, 720);\nclipping = ef.cubicnl(gain, 0);\npost_filter = fi.lowpass(1, 350 + (tone * (4500 - 350)));\nvolume_control = ba.db2linear((volume - 1) * 40);\nprocess = input_filter : clipping : post_filter * volume_control;"
 },
 {
  "id": "gx-bfuzz",
  "name": "Bass Fuzz",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Bass fuzz pedal with Drive, Thickness and wet/dry blend to keep the low end.",
  "description": "DK circuit simulation from the schematic of a bass fuzz pedal with a transistor clipper stage, plus a wet/dry control so the clean low end can be blended back in. Thickness shapes the body of the fuzz.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Bass_Fuzz_Pedal/wet_dry"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Bass_Fuzz_Pedal/Level"
   },
   {
    "label": "Drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Bass_Fuzz_Pedal/Drive"
   },
   {
    "label": "Thickness",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Bass_Fuzz_Pedal/Thickness"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/bfuzz.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"bfuzz\";\ndeclare name \"Bass Fuzz Pedal\";\ndeclare category \"Fuzz\";\ndeclare shortname \"Bass Fuzz\";\ndeclare description \"Bass Fuzz Pedal\";\ndeclare insert_p \"tranyclipper\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\nprocess = pre : _<:*(dry),(*(wet) : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0)) ):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    wet = vslider(\"wet_dry[name:Wet/Dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\n    dry = 1 - wet;\n    clip = tranystageb(TB_7199P_68k,86.0,2700.0,5.571981) : tranystageb(TB_7199P_68k,86.0,2700.0,5.571981) ;\n\n    \n        Level = vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Drive = vslider(\"Drive[name:Drive]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Thickness = vslider(\"Thickness[name:Thickness]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Drive*Level*pow(fs,2)*(-1.65780932898435e-16*fs - 8.29281439339673e-13) + Level*pow(fs,2)*(-7.76911913609341e-14*fs - 3.88632527694127e-10) + Thickness*(1.65780932898435e-16*Drive*Level*pow(fs,3) + 7.76911913609341e-14*Level*pow(fs,3));\n\n    b1 = 3.3156186579687e-16*Drive*Level*pow(fs,3) + 1.55382382721868e-13*Level*pow(fs,3) + Thickness*(-3.3156186579687e-16*Drive*Level*pow(fs,3) - 1.55382382721868e-13*Level*pow(fs,3));\n\n    b2 = 1.65856287867935e-12*Drive*Level*pow(fs,2) + 7.77265055388254e-10*Level*pow(fs,2);\n\n    b3 = -3.3156186579687e-16*Drive*Level*pow(fs,3) - 1.55382382721868e-13*Level*pow(fs,3) + Thickness*(3.3156186579687e-16*Drive*Level*pow(fs,3) + 1.55382382721868e-13*Level*pow(fs,3));\n\n    b4 = Drive*Level*pow(fs,2)*(1.65780932898435e-16*fs - 8.29281439339673e-13) + Level*pow(fs,2)*(7.76911913609341e-14*fs - 3.88632527694127e-10) + Thickness*(-1.65780932898435e-16*Drive*Level*pow(fs,3) - 7.76911913609341e-14*Level*pow(fs,3));\n\n    a0 = Drive*(fs*(fs*(fs*(-1.8235902618655e-20*fs - 8.82979918090661e-15) - 5.32286268006641e-11) - 2.42569918771087e-9) - 9.41937118747331e-10) + Thickness*(Drive*fs*(fs*(fs*(1.8235902618655e-20*fs + 8.73857822258011e-15) + 9.51587528271067e-12) + 4.14452332248826e-10) + fs*(fs*(fs*(-1.90624114055858e-19*fs - 9.05150991318089e-15) - 9.57238853136628e-11) - 4.70914107604798e-9)) + fs*(fs*(fs*(1.90624114055858e-19*fs + 1.0005063720083e-14) + 1.41002006493022e-10) + 6.98583678876617e-9) + 1.07025933546545e-8;\n\n    a1 = Drive*(fs*(pow(fs,2)*(7.294361047462e-20*fs + 1.76595983618132e-14) - 4.85139837542174e-9) - 3.76774847498933e-9) + Thickness*(Drive*fs*(pow(fs,2)*(-7.294361047462e-20*fs - 1.74771564451602e-14) + 8.28904664497652e-10) + fs*(pow(fs,2)*(7.6249645622343e-19*fs + 1.81030198263618e-14) - 9.41828215209595e-9)) + fs*(pow(fs,2)*(-7.6249645622343e-19*fs - 2.00101274401661e-14) + 1.39716735775323e-8) + 4.2810373418618e-8;\n\n    a2 = Drive*(pow(fs,2)*(-1.0941541571193e-19*pow(fs,2) + 1.06457253601328e-10) - 5.65162271248399e-9) + Thickness*(Drive*pow(fs,2)*(1.0941541571193e-19*pow(fs,2) - 1.90317505654213e-11) + pow(fs,2)*(-1.14374468433515e-18*pow(fs,2) + 1.91447770627326e-10)) + pow(fs,2)*(1.14374468433515e-18*pow(fs,2) - 2.82004012986045e-10) + 6.4215560127927e-8;\n\n    a3 = Drive*(fs*(pow(fs,2)*(7.294361047462e-20*fs - 1.76595983618132e-14) + 4.85139837542174e-9) - 3.76774847498933e-9) + Thickness*(Drive*fs*(pow(fs,2)*(-7.294361047462e-20*fs + 1.74771564451602e-14) - 8.28904664497652e-10) + fs*(pow(fs,2)*(7.6249645622343e-19*fs - 1.81030198263618e-14) + 9.41828215209595e-9)) + fs*(pow(fs,2)*(-7.6249645622343e-19*fs + 2.00101274401661e-14) - 1.39716735775323e-8) + 4.2810373418618e-8;\n\n    a4 = Drive*(fs*(fs*(fs*(-1.8235902618655e-20*fs + 8.82979918090661e-15) - 5.32286268006641e-11) + 2.42569918771087e-9) - 9.41937118747331e-10) + Thickness*(Drive*fs*(fs*(fs*(1.8235902618655e-20*fs - 8.73857822258011e-15) + 9.51587528271067e-12) - 4.14452332248826e-10) + fs*(fs*(fs*(-1.90624114055858e-19*fs + 9.05150991318089e-15) - 9.57238853136628e-11) + 4.70914107604798e-9)) + fs*(fs*(fs*(1.90624114055858e-19*fs - 1.0005063720083e-14) + 1.41002006493022e-10) - 6.98583678876617e-9) + 1.07025933546545e-8;\n};"
 },
 {
  "id": "gx-bmp",
  "name": "Big Muff Pi",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Electro-Harmonix Big Muff Pi: thick, sustaining four-transistor fuzz; Sustain and Tone.",
  "description": "DK circuit simulation from the Big Muff Pi schematic: pot-dependent state-space filters with a symmetric diode clip stage, at 96 kHz. Sustain drives the clipping stages for the Big Muff's wall of thick, singing fuzz; Tone scoops between bass and treble.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Sustain",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/BigMuffPi/Sustain"
   },
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/BigMuffPi/Tone"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/BigMuffPi/Volume"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/bmp.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"bmp\";\ndeclare name \"BigMuffPi\";\ndeclare category \"Fuzz\";\ndeclare shortname \"BMP\";\ndeclare description \"BigMuffPi\";\ndeclare samplerate \"96000\";\n\nimport(\"stdfaust.lib\");\n\ngxc = library(\"clipping.lib\");\n\nbpmin = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n    \n    b0 = 3.7454979802542e-6*fs;\n\n    b1 = 0;\n\n    b2 = -3.7454979802542e-6*fs;\n\n    a0 = 2.08287704934496e-5*fs + 0.000219016314271736;\n\n    a1 = 0.000438032628543473;\n\n    a2 = -2.08287704934496e-5*fs + 0.000219016314271736;\n};\n\nbpmamp1 = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n    \n        Sustain = vslider(\"Sustain[name:Sustain]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Sustain*fs*(2.26293387153501e-12*fs - 1.17905906929765e-5) + fs*(2.26293387153501e-14*fs - 1.17905906929765e-7);\n\n    b1 = -4.52586774307001e-12*Sustain*pow(fs,2) - 4.52586774307001e-14*pow(fs,2);\n\n    b2 = Sustain*fs*(2.26293387153501e-12*fs + 1.17905906929765e-5) + fs*(2.26293387153501e-14*fs + 1.17905906929765e-7);\n\n    a0 = Sustain*(Sustain*fs*(-1.13446519814126e-9*fs - 2.89110812782566e-6) + fs*(1.12312054615984e-9*fs + 2.8621970465474e-6)) + fs*(1.2821120020393e-10*fs + 6.26521815410076e-7) + 0.000146000960455196;\n\n    a1 = Sustain*(2.26893039628251e-9*Sustain*pow(fs,2) - 2.24624109231969e-9*pow(fs,2)) - 2.5642240040786e-10*pow(fs,2) + 0.000292001920910392;\n\n    a2 = Sustain*(Sustain*fs*(-1.13446519814126e-9*fs + 2.89110812782566e-6) + fs*(1.12312054615984e-9*fs - 2.8621970465474e-6)) + fs*(1.2821120020393e-10*fs - 6.26521815410076e-7) + 0.000146000960455196;\n};\n\nbpmamp2 = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n    \n    b0 = fs*(7.66731214399861e-12*fs - 3.99490857178962e-5);\n\n    b1 = -1.53346242879972e-11*pow(fs,2);\n\n    b2 = fs*(7.66731214399861e-12*fs + 3.99490857178962e-5);\n\n    a0 = fs*(3.920487958595e-10*fs + 2.00478727462711e-6) + 0.000489785157611555;\n\n    a1 = -7.84097591718999e-10*pow(fs,2) + 0.000979570315223111;\n\n    a2 = fs*(3.920487958595e-10*fs - 2.00478727462711e-6) + 0.000489785157611555;\n};\n\nbpmtone = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n    \n        Tone = vslider(\"Tone[name:Tone]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Tone*(3.68688858465455e-10*pow(fs,2) - 0.00316091270975185) + 8.67101574539126e-7*fs + 0.00401435914138484;\n\n    b1 = Tone*(-7.37377716930911e-10*pow(fs,2) - 0.00632182541950369) + 0.00802871828276969;\n\n    b2 = Tone*(3.68688858465455e-10*pow(fs,2) - 0.00316091270975185) - 8.67101574539126e-7*fs + 0.00401435914138484;\n\n    a0 = fs*(3.68688858465455e-10*fs + 3.03485551088694e-6) + 0.00486780557301784;\n\n    a1 = -7.37377716930911e-10*pow(fs,2) + 0.00973561114603569;\n\n    a2 = fs*(3.68688858465455e-10*fs - 3.03485551088694e-6) + 0.00486780557301784;\n};\n\nbpmout = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n    \n        Volume = vslider(\"Volume[name:Volume]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = -1.74325899023428e-9*Volume*pow(fs,2);\n\n    b1 = 3.48651798046856e-9*Volume*pow(fs,2);\n\n    b2 = -1.74325899023428e-9*Volume*pow(fs,2);\n\n    a0 = fs*(4.33884681055068e-10*fs + 6.86809013445937e-9) + 2.65226702159437e-8;\n\n    a1 = -8.67769362110135e-10*pow(fs,2) + 5.30453404318874e-8;\n\n    a2 = fs*(4.33884681055068e-10*fs - 6.86809013445937e-9) + 2.65226702159437e-8;\n};\n\nantialiasing = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n    \n    b0 = fs*(4.68362091734077e-13*fs + 7.44521670106066e-7);\n\n    b1 = 1.48904334021213e-6*fs;\n\n    b2 = -9.36724183468154e-13*pow(fs,2);\n\n    b3 = -1.48904334021213e-6*fs;\n\n    b4 = fs*(4.68362091734077e-13*fs - 7.44521670106066e-7);\n\n    a0 = fs*(7.55757331680132e-11*fs + 8.45438325675249e-7) + 0.000114185647251642;\n\n    a1 = 1.6908766513505e-6*fs + 0.00045674258900657;\n\n    a2 = -1.51151466336026e-10*pow(fs,2) + 0.000685113883509854;\n\n    a3 = -1.6908766513505e-6*fs + 0.00045674258900657;\n\n    a4 = fs*(7.55757331680132e-11*fs - 8.45438325675249e-7) + 0.000114185647251642;\n};\nsymclip = gxc.symclip;\n    sclip = (_ : symclip);\n\nprocess = bpmin : bpmamp1 : sclip  : bpmamp2 : sclip  : bpmtone : bpmout : fi.peak_eq_cq(-8.5,12000,8.5);"
 },
 {
  "id": "gx-bossds1",
  "name": "Boss DS-1",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Boss DS-1 Distortion: transistor boost into an op-amp hard clipper with the DS-1 tone.",
  "description": "DK circuit simulation from the Boss DS-1 schematic: input buffer, transistor gain stage, op-amp asymmetric hard-clipping stage and the DS-1 active tone control as pot-dependent filters, at 96 kHz. Tight, buzzy rock distortion with Tone, Drive and Level.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/Boss_DS1/Tone"
   },
   {
    "label": "drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Boss_DS1/drive"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 12,
    "default": 3,
    "step": 0.1,
    "unit": "",
    "path": "/Boss_DS1/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/bossds1.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id          \"bossds1\";\ndeclare name        \"Boss DS1\";\ndeclare category    \"Distortion\";\ndeclare shortname   \"DS1\";\ndeclare description \"Boss DS1\";\ndeclare samplerate  \"96000\";\n\nimport(\"stdfaust.lib\");\n\ngxc = library(\"clipping.lib\");\n\nds1_in = fi.iir((b0/a0,b1/a0),(a1/a0)) with {\n    fs = float(ma.SR);\n\n    b0 = 2.07110717442793e-5*fs;\n\n    b1 = -2.07110717442793e-5*fs;\n\n    a0 = 2.08232145615427e-5*fs + 0.000485701045951343;\n\n    a1 = -2.08232145615427e-5*fs + 0.000485701045951343;\n};\n\nds1_boost= fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) with {\n    fs = float(ma.SR);\n\n    b0 = -5.51041967277497e-9*pow(fs,2);\n\n    b1 = 5.51041967277497e-9*pow(fs,2);\n\n    b2 = 5.51041967277497e-9*pow(fs,2);\n\n    b3 = -5.51041967277497e-9*pow(fs,2);\n\n    a0 = fs*(3.53982651634833e-10*fs + 2.38582349500046e-7) + 1.94656546234155e-5;\n\n    a1 = fs*(-3.53982651634833e-10*fs + 2.38582349500046e-7) + 5.83969638702466e-5;\n\n    a2 = fs*(-3.53982651634833e-10*fs - 2.38582349500046e-7) + 5.83969638702466e-5;\n\n    a3 = fs*(3.53982651634833e-10*fs - 2.38582349500046e-7) + 1.94656546234155e-5;\n};\n\nds1_tone = fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    s = 0.993;\n\n    fs = float(ma.SR);\n\n        Tone = vslider(\"Tone[name:Tone]\", 0.7, 0, 1, 0.01) : si.smooth(s);\n    \n    b0 = Tone*(fs*(-2.18842400636233e-10*fs + 5.20602596669238e-8) + 0.000537812599864916) + (fs*(2.18842400636233e-10*fs + 2.33324618325395e-7) + 0.000182856283954071);\n\n    b1 = Tone*(4.37684801272465e-10*pow(fs,2) + 0.00107562519972983) + (-4.37684801272465e-10*pow(fs,2) + 0.000365712567908143);\n\n    b2 = Tone*(fs*(-2.18842400636233e-10*fs - 5.20602596669238e-8) + 0.000537812599864916) + (fs*(2.18842400636233e-10*fs - 2.33324618325395e-7) + 0.000182856283954071);\n\n    a0 = Tone*(Tone*(fs*(-2.89644353783249e-10*fs - 9.44398925362792e-7) - 0.000537812599864916) + fs*(2.65571689713263e-10*fs + 7.50424979344313e-7) + 0.000537812599864916) + fs*(3.3778968192322e-10*fs + 1.55559824875468e-6) + 0.00114855258827151;\n\n    a1 = Tone*(Tone*(5.79288707566498e-10*pow(fs,2) - 0.00107562519972983) - 5.31143379426527e-10*pow(fs,2) + 0.00107562519972983) - 6.7557936384644e-10*pow(fs,2) + 0.00229710517654303;\n\n    a2 = Tone*(Tone*(fs*(-2.89644353783249e-10*fs + 9.44398925362792e-7) - 0.000537812599864916) + fs*(2.65571689713263e-10*fs - 7.50424979344313e-7) + 0.000537812599864916) + fs*(3.3778968192322e-10*fs - 1.55559824875468e-6) + 0.00114855258827151;\n};\n\nds1_out = fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    fs = float(ma.SR);\n\n    b0 = 4.28019579852603e-10*pow(fs,2);\n\n    b1 = -8.56039159705207e-10*pow(fs,2);\n\n    b2 = 4.28019579852603e-10*pow(fs,2);\n\n    a0 = fs*(4.33879508860142e-10*fs + 7.11639898820675e-9) + 2.44347979826776e-8;\n\n    a1 = -8.67759017720285e-10*pow(fs,2) + 4.88695959653553e-8;\n\n    a2 = fs*(4.33879508860142e-10*fs - 7.11639898820675e-9) + 2.44347979826776e-8;\n};\n\nds1_drive = fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    fs = float(ma.SR);\n\n    b0 = drive*(-3.18093350083904e-10*drive*pow(fs,2) + fs*(3.0314296262996e-10*fs + 1.59012835323858e-5)) + fs*(1.49503874539434e-11*fs + 7.50903344506575e-7) + 0.000169198590470161;\n\n    b1 = drive*(6.36186700167807e-10*drive*pow(fs,2) - 6.0628592525992e-10*pow(fs,2)) - 2.99007749078869e-11*pow(fs,2) + 0.000338397180940323;\n\n    b2 = drive*(-3.18093350083904e-10*drive*pow(fs,2) + fs*(3.0314296262996e-10*fs - 1.59012835323858e-5)) + fs*(1.49503874539434e-11*fs - 7.50903344506575e-7) + 0.000169198590470161;\n\n    a0 = drive*(-3.18093350083904e-10*drive*pow(fs,2) + fs*(3.0314296262996e-10*fs - 3.38397180940322e-9)) + fs*(1.49503874539434e-11*fs + 1.66555708487018e-5) + 0.000169198590470162;\n\n    a1 = drive*(6.36186700167807e-10*drive*pow(fs,2) - 6.0628592525992e-10*pow(fs,2)) - 2.99007749078869e-11*pow(fs,2) + 0.000338397180940324;\n\n    a2 = drive*(-3.18093350083904e-10*drive*pow(fs,2) + fs*(3.0314296262996e-10*fs + 3.38397180940322e-9)) + fs*(1.49503874539434e-11*fs - 1.66555708487018e-5) + 0.000169198590470162;\n};\n\n    s = 0.993;\n    drive =  hslider(\"drive[name:Drive]\", 0.5, 0, 1, 0.01) : *(0.314): si.smooth(s);\n\nprocess = ds1_in : ds1_boost : ds1_drive : sclip : hf : X1 : X3 : lf  : clip  : ds1_tone : ds1_out : *(gain)  with {\n    R1 = 4700 + 100000 * (1.0 - drive);\n    R2 = 100000 + 100000 * drive;\n    C = 0.047 * 1e-6;\n    a1 = (R1 + R2) * C * 2 * ma.SR;\n    a2 = R1 * C * 2 * ma.SR;\n    B0 = (1 + a1) / (1 + a2);\n    B1 = (1 - a1) / (1 + a2);\n    A1 = (1 - a2) / (1 + a2);\n    X2 = fi.tf1(B0, B1, A1);\n    s = 0.993;\n    hf = fi.highpass(2,23.);\n    lf = fi.lowpass(2,7200.);\nsymclip = gxc.asymclip3;\n    sclip = (_ : symclip);\nopamp = gxc.opamp;\n    X1 = _ <: _ - (_ : opamp) :> _ ;\n    X3 = _ <: _ - (X2-_ : opamp) :> _ ;\nasymclip = gxc.asymhardclip2;\n    clip = (_ : asymclip);\n    gain = hslider(\"Level[name:Level]\", 3, -20, 12, 0.1) : ba.db2linear : si.smooth(s);\n};"
 },
 {
  "id": "gx-buzz",
  "name": "Buzz Box",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Baldwin-Burns Buzzaround-style transistor fuzz with a wet/dry blend.",
  "description": "DK circuit simulation from the schematic of a Buzzaround-style fuzz box with a transistor clipper stage and a wet/dry blend. A raspy, sputtery 1960s fuzz with Level.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Buzz_Box/wet_dry"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Buzz_Box/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/buzz.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"buzz\";\ndeclare name \"Buzz Box\";\ndeclare category \"Fuzz\";\ndeclare shortname \"Buzz Box\";\ndeclare description \"Buzz Box\";\ndeclare insert_p \"tranyclipper\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\nprocess = pre : _<:*(dry),(*(wet) : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) ):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    wet = vslider(\"wet_dry[name:Wet/Dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\n    dry = 1 - wet;\n    clip = tranystageb(TB_7199P_68k,86.0,2700.0,5.571981) : tranystageb(TB_7199P_68k,86.0,2700.0,5.571981) ;\n\n    \n        Level = vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = 3.81347663375185e-13*Level*pow(fs,3);\n\n    b1 = -1.14404299012556e-12*Level*pow(fs,3);\n\n    b2 = 1.14404299012556e-12*Level*pow(fs,3);\n\n    b3 = -3.81347663375185e-13*Level*pow(fs,3);\n\n    a0 = fs*(fs*(9.04201686922855e-15*fs + 1.0967885210812e-14) + 8.14058347559848e-15) + 2.46256378077601e-15;\n\n    a1 = fs*(fs*(-2.71260506076857e-14*fs - 1.0967885210812e-14) + 8.14058347559848e-15) + 7.38769134232804e-15;\n\n    a2 = fs*(fs*(2.71260506076857e-14*fs - 1.0967885210812e-14) - 8.14058347559848e-15) + 7.38769134232804e-15;\n\n    a3 = fs*(fs*(-9.04201686922855e-15*fs + 1.0967885210812e-14) - 8.14058347559848e-15) + 2.46256378077601e-15;\n};"
 },
 {
  "id": "gx-coverd",
  "name": "Colorsound Overdriver",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Colorsound Overdriver: transistor booster/overdrive with Bass and Treble.",
  "description": "DK circuit simulation from the schematic of the Colorsound Overdriver as a pot-dependent linear filter (Volume, Bass, Treble) with a wet/dry blend. In this port it acts as a coloured booster with the Overdriver's tone controls.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/C_Overdrive/wet_dry"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/C_Overdrive/Volume"
   },
   {
    "label": "Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/C_Overdrive/Bass"
   },
   {
    "label": "Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/C_Overdrive/Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/coverd.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"coverd\";\ndeclare name \"C Overdrive\";\ndeclare category \"Distortion\";\ndeclare shortname \"C Overdrive\";\ndeclare description \"Colorsound Overdrive\";\n\nimport(\"stdfaust.lib\");\n\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    \n    wet = vslider(\"wet_dry[name:Wet/Dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\n    dry = 1 - wet;\n\np1 = fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0)) : overdrive with {\n\n        Gain = vslider(\"Volume[name:Volume]\", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(1) : si.smooth(s);\n    \n    overdrive(x) = (x*(abs(x) + 0.5)/(x*x + (0.5-1)*abs(x) + 1)) * Gain;\n    \n    b0 = Gain*fs*(fs*(fs*(fs*(3.97647190322603e-27*fs - 4.95880631786145e-19) - 2.12282875792926e-17) - 2.95727845714664e-18) - 2.63401345836477e-31) + fs*(fs*(fs*(fs*(-7.42702058644117e-27*fs + 7.89889133199585e-19) + 3.48875412150739e-17) + 5.04598373508118e-17) + 6.57172990476634e-18);\n\n    b1 = Gain*fs*(fs*(fs*(fs*(-1.98823595161302e-26*fs + 1.48764189535843e-18) + 2.12282875792926e-17) - 2.95727845714664e-18) - 7.9020403750943e-31) + fs*(fs*(fs*(fs*(3.71351029322059e-26*fs - 2.36966739959876e-18) - 3.48875412150739e-17) + 5.04598373508118e-17) + 1.9715189714299e-17);\n\n    b2 = Gain*fs*(fs*(fs*(fs*(3.97647190322603e-26*fs - 9.91761263572289e-19) + 4.24565751585853e-17) + 5.91455691429328e-18) - 5.26802691672954e-31) + fs*(fs*(fs*(fs*(-7.42702058644117e-26*fs + 1.57977826639917e-18) - 6.97750824301479e-17) - 1.00919674701624e-16) + 1.31434598095327e-17);\n\n    b3 = Gain*fs*(fs*(fs*(fs*(-3.97647190322603e-26*fs - 9.91761263572289e-19) - 4.24565751585853e-17) + 5.91455691429328e-18) + 5.26802691672954e-31) + fs*(fs*(fs*(fs*(7.42702058644117e-26*fs + 1.57977826639917e-18) + 6.97750824301479e-17) - 1.00919674701624e-16) - 1.31434598095327e-17);\n\n    b4 = Gain*fs*(fs*(fs*(fs*(1.98823595161302e-26*fs + 1.48764189535843e-18) - 2.12282875792926e-17) - 2.95727845714664e-18) + 7.9020403750943e-31) + fs*(fs*(fs*(fs*(-3.71351029322059e-26*fs - 2.36966739959876e-18) + 3.48875412150739e-17) + 5.04598373508118e-17) - 1.9715189714299e-17);\n\n    b5 = Gain*fs*(fs*(fs*(fs*(-3.97647190322603e-27*fs - 4.95880631786145e-19) + 2.12282875792926e-17) - 2.95727845714664e-18) + 2.63401345836477e-31) + fs*(fs*(fs*(fs*(7.42702058644117e-27*fs + 7.89889133199585e-19) - 3.48875412150739e-17) + 5.04598373508118e-17) - 6.57172990476634e-18);\n\n    a0 = Gain*(fs*(fs*(fs*(fs*(-2.40788246727257e-24*fs - 1.83337089189981e-19) - 1.0884037880131e-17) - 2.17663092851014e-16) - 5.23377299648722e-16) - 4.66166061483529e-29) + fs*(fs*(fs*(fs*(2.78713041660513e-24*fs + 2.03907877623046e-19) + 1.25272695161612e-17) + 3.13137866048362e-16) + 1.42685467015479e-15) + 1.16306066588601e-15;\n\n    a1 = Gain*(fs*(fs*(fs*(fs*(1.20394123363628e-23*fs + 5.50011267569942e-19) + 1.0884037880131e-17) - 2.17663092851014e-16) - 1.57013189894617e-15) - 2.33083030741764e-28) + fs*(fs*(fs*(fs*(-1.39356520830257e-23*fs - 6.11723632869138e-19) - 1.25272695161612e-17) + 3.13137866048362e-16) + 4.28056401046438e-15) + 5.81530332943008e-15;\n\n    a2 = Gain*(fs*(fs*(fs*(fs*(-2.40788246727257e-23*fs - 3.66674178379961e-19) + 2.17680757602621e-17) + 4.35326185702027e-16) - 1.04675459929744e-15) - 4.66166061483529e-28) + fs*(fs*(fs*(fs*(2.78713041660513e-23*fs + 4.07815755246092e-19) - 2.50545390323223e-17) - 6.26275732096724e-16) + 2.85370934030959e-15) + 1.16306066588602e-14;\n\n    a3 = Gain*(fs*(fs*(fs*(fs*(2.40788246727257e-23*fs - 3.66674178379961e-19) - 2.17680757602621e-17) + 4.35326185702027e-16) + 1.04675459929744e-15) - 4.66166061483529e-28) + fs*(fs*(fs*(fs*(-2.78713041660513e-23*fs + 4.07815755246092e-19) + 2.50545390323223e-17) - 6.26275732096724e-16) - 2.85370934030959e-15) + 1.16306066588602e-14;\n\n    a4 = Gain*(fs*(fs*(fs*(fs*(-1.20394123363628e-23*fs + 5.50011267569942e-19) - 1.0884037880131e-17) - 2.17663092851014e-16) + 1.57013189894617e-15) - 2.33083030741764e-28) + fs*(fs*(fs*(fs*(1.39356520830257e-23*fs - 6.11723632869138e-19) + 1.25272695161612e-17) + 3.13137866048362e-16) - 4.28056401046438e-15) + 5.81530332943008e-15;\n\n    a5 = Gain*(fs*(fs*(fs*(fs*(2.40788246727257e-24*fs - 1.83337089189981e-19) + 1.0884037880131e-17) - 2.17663092851014e-16) + 5.23377299648722e-16) - 4.66166061483529e-29) + fs*(fs*(fs*(fs*(-2.78713041660513e-24*fs + 2.03907877623046e-19) - 1.25272695161612e-17) + 3.13137866048362e-16) - 1.42685467015479e-15) + 1.16306066588601e-15;\n};\n\np2 =  fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0)) with {\n\n        Bass = vslider(\"Bass[name:Bass]\", 0.5, 0, 1, 0.01) : Inverted(1) : si.smooth(s);\n    \n        Treble = vslider(\"Treble[name:Treble]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Bass*(Bass*pow(fs,2)*(fs*(fs*(-2.08000946656956e-27*fs + 3.29838842203039e-21) + 1.40184395777108e-19) + 3.53984542064284e-34) + fs*(fs*(fs*(fs*(3.70058120006252e-25*fs + 3.84955928653808e-22) + 1.66273197458755e-18) + 7.0086493617754e-17) + 1.76992271032142e-31)) + Treble*(Bass*(Bass*pow(fs,3)*(fs*(6.58813040006868e-24*fs + 2.80345974471016e-22) + 7.07969084128568e-37) + pow(fs,3)*(fs*(1.91438372832372e-27*fs - 9.28894735127254e-24) - 2.28170831993645e-23)) + Treble*(Bass*pow(fs,3)*(fs*(-6.58813040006868e-24*fs - 2.80345974471016e-22) - 7.07969084128568e-37) + pow(fs,3)*(fs*(6.88899571441955e-24*fs + 2.95929420463955e-22) + 1.1408541599688e-23)) + pow(fs,3)*(fs*(-1.0025039931634e-23*fs - 4.24692905313867e-22) - 6.08366393926321e-36)) + fs*(fs*(fs*(fs*(-3.8335982187148e-25*fs - 5.42251622369686e-21) - 1.95786469833648e-18) - 7.39993880685971e-17) - 2.85213539992201e-18);\n\n    b1 = Bass*(Bass*pow(fs,2)*(fs*(fs*(1.04000473328478e-26*fs - 9.89516526609117e-21) - 1.40184395777108e-19) + 3.53984542064284e-34) + fs*(fs*(fs*(fs*(-1.85029060003126e-24*fs - 1.15486778596142e-21) - 1.66273197458755e-18) + 7.0086493617754e-17) + 5.30976813096426e-31)) + Treble*(Bass*(Bass*pow(fs,3)*(fs*(-3.29406520003434e-23*fs - 8.41037923413049e-22) - 7.07969084128568e-37) + pow(fs,3)*(fs*(-9.57191864161859e-27*fs + 2.78668420538176e-23) + 2.28170831993645e-23)) + Treble*(Bass*pow(fs,3)*(fs*(3.29406520003434e-23*fs + 8.41037923413049e-22) + 7.07969084128568e-37) + pow(fs,3)*(fs*(-3.44449785720978e-23*fs - 8.87788261391865e-22) - 1.1408541599688e-23)) + pow(fs,3)*(fs*(5.012519965817e-23*fs + 1.2740787159416e-21) + 6.08366393926321e-36)) + fs*(fs*(fs*(fs*(1.9167991093574e-24*fs + 1.62675486710906e-20) + 1.95786469833648e-18) - 7.39993880685971e-17) - 8.55640619976602e-18);\n\n    b2 = Bass*(Bass*pow(fs,2)*(fs*(fs*(-2.08000946656956e-26*fs + 6.59677684406078e-21) - 2.80368791554216e-19) - 7.07969084128568e-34) + fs*(fs*(fs*(fs*(3.70058120006252e-24*fs + 7.69911857307616e-22) - 3.32546394917509e-18) - 1.40172987235508e-16) + 3.53984542064284e-31)) + Treble*(Bass*(Bass*pow(fs,3)*(fs*(6.58813040006868e-23*fs + 5.60691948942032e-22) - 1.41593816825714e-36) + pow(fs,3)*(fs*(1.91438372832372e-26*fs - 1.85778947025451e-23) + 4.56341663987291e-23)) + Treble*(Bass*pow(fs,3)*(fs*(-6.58813040006868e-23*fs - 5.60691948942032e-22) + 1.41593816825714e-36) + pow(fs,3)*(fs*(6.88899571441955e-23*fs + 5.9185884092791e-22) - 2.28170831993761e-23)) + pow(fs,3)*(fs*(-1.0025039931634e-22*fs - 8.49385810627733e-22) + 1.21673278785264e-35)) + fs*(fs*(fs*(fs*(-3.8335982187148e-24*fs - 1.08450324473937e-20) + 3.91572939667295e-18) + 1.47998776137194e-16) - 5.70427079984401e-18);\n\n    b3 = Bass*(Bass*pow(fs,2)*(fs*(fs*(2.08000946656956e-26*fs + 6.59677684406078e-21) + 2.80368791554216e-19) - 7.07969084128568e-34) + fs*(fs*(fs*(fs*(-3.70058120006252e-24*fs + 7.69911857307616e-22) + 3.32546394917509e-18) - 1.40172987235508e-16) - 3.53984542064284e-31)) + Treble*(Bass*(Bass*pow(fs,3)*(fs*(-6.58813040006868e-23*fs + 5.60691948942032e-22) + 1.41593816825714e-36) + pow(fs,3)*(fs*(-1.91438372832372e-26*fs - 1.85778947025451e-23) - 4.56341663987291e-23)) + Treble*(Bass*pow(fs,3)*(fs*(6.58813040006868e-23*fs - 5.60691948942032e-22) - 1.41593816825714e-36) + pow(fs,3)*(fs*(-6.88899571441955e-23*fs + 5.9185884092791e-22) + 2.28170831993761e-23)) + pow(fs,3)*(fs*(1.0025039931634e-22*fs - 8.49385810627733e-22) - 1.21673278785264e-35)) + fs*(fs*(fs*(fs*(3.8335982187148e-24*fs - 1.08450324473937e-20) - 3.91572939667295e-18) + 1.47998776137194e-16) + 5.70427079984401e-18);\n\n    b4 = Bass*(Bass*pow(fs,2)*(fs*(fs*(-1.04000473328478e-26*fs - 9.89516526609117e-21) + 1.40184395777108e-19) + 3.53984542064284e-34) + fs*(fs*(fs*(fs*(1.85029060003126e-24*fs - 1.15486778596142e-21) + 1.66273197458755e-18) + 7.0086493617754e-17) - 5.30976813096426e-31)) + Treble*(Bass*(Bass*pow(fs,3)*(fs*(3.29406520003434e-23*fs - 8.41037923413049e-22) + 7.07969084128568e-37) + pow(fs,3)*(fs*(9.57191864161859e-27*fs + 2.78668420538176e-23) - 2.28170831993645e-23)) + Treble*(Bass*pow(fs,3)*(fs*(-3.29406520003434e-23*fs + 8.41037923413049e-22) - 7.07969084128568e-37) + pow(fs,3)*(fs*(3.44449785720978e-23*fs - 8.87788261391865e-22) + 1.1408541599688e-23)) + pow(fs,3)*(fs*(-5.012519965817e-23*fs + 1.2740787159416e-21) - 6.08366393926321e-36)) + fs*(fs*(fs*(fs*(-1.9167991093574e-24*fs + 1.62675486710906e-20) - 1.95786469833648e-18) - 7.39993880685971e-17) + 8.55640619976602e-18);\n\n    b5 = Bass*(Bass*pow(fs,2)*(fs*(fs*(2.08000946656956e-27*fs + 3.29838842203039e-21) - 1.40184395777108e-19) + 3.53984542064284e-34) + fs*(fs*(fs*(fs*(-3.70058120006252e-25*fs + 3.84955928653808e-22) - 1.66273197458755e-18) + 7.0086493617754e-17) - 1.76992271032142e-31)) + Treble*(Bass*(Bass*pow(fs,3)*(fs*(-6.58813040006868e-24*fs + 2.80345974471016e-22) - 7.07969084128568e-37) + pow(fs,3)*(fs*(-1.91438372832372e-27*fs - 9.28894735127254e-24) + 2.28170831993645e-23)) + Treble*(Bass*pow(fs,3)*(fs*(6.58813040006868e-24*fs - 2.80345974471016e-22) + 7.07969084128568e-37) + pow(fs,3)*(fs*(-6.88899571441955e-24*fs + 2.95929420463955e-22) - 1.1408541599688e-23)) + pow(fs,3)*(fs*(1.0025039931634e-23*fs - 4.24692905313867e-22) + 6.08366393926321e-36)) + fs*(fs*(fs*(fs*(3.8335982187148e-25*fs - 5.42251622369686e-21) + 1.95786469833648e-18) - 7.39993880685971e-17) + 2.85213539992201e-18);\n\n    a0 = Bass*(Bass*(fs*(fs*(fs*(fs*(-6.72581680534004e-24*fs - 4.41586600140972e-21) - 7.47371530788388e-19) - 9.57970935359556e-17) + 1.78867236680673e-28) + 4.51350125457133e-43) + fs*(fs*(fs*(fs*(7.09491773348213e-24*fs + 8.1036807179337e-21) + 2.55872993315156e-18) + 1.677855547693e-16) + 8.47611869896916e-17) - 1.90136609408475e-28) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(5.49427436280305e-24*fs - 3.14344447184204e-23) + 3.39044747960198e-22) - 7.60546437633897e-34) + pow(fs,2)*(fs*(fs*(1.11582073532266e-24*fs + 3.23543557700559e-22) + 8.5311710434333e-22) + 3.39044747959503e-20)) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(1.11390635159433e-24*fs + 3.18702063081927e-22) - 7.14108820102165e-34) - 1.80540050182853e-48) + pow(fs,2)*(fs*(fs*(-7.72208706599171e-24*fs - 6.05969681445433e-22) - 3.39044747958769e-22) + 7.605464376339e-34)) + pow(fs,2)*(fs*(fs*(-9.07610804066639e-25*fs - 3.13971543026984e-22) - 1.80077239576117e-20) - 1.69522373979748e-20)) + pow(fs,2)*(fs*(fs*(-2.23797473617709e-24*fs + 1.74849041434644e-22) + 1.74198245202729e-20) + 6.97469477751319e-35)) + fs*(fs*(fs*(fs*(3.22318393238815e-24*fs + 2.32489770791907e-21) + 5.44196016387214e-19) + 9.66029729825488e-17) + 4.5272406798381e-15) + 4.23805934949371e-15;\n\n    a1 = Bass*(Bass*(fs*(fs*(fs*(fs*(3.36290840267002e-23*fs + 1.32475980042292e-20) + 7.47371530788388e-19) - 9.57970935359556e-17) + 5.3660171004202e-28) + 2.25675062728566e-42) + fs*(fs*(fs*(fs*(-3.54745886674106e-23*fs - 2.43110421538011e-20) - 2.55872993315156e-18) + 1.677855547693e-16) + 2.54283560969075e-16) - 9.50683047042375e-28) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(-2.74713718140152e-23*fs + 9.43033341552612e-23) - 3.39044747960198e-22) - 7.60546437633897e-34) + pow(fs,2)*(fs*(fs*(-5.57910367661329e-24*fs - 9.70630673101678e-22) - 8.5311710434333e-22) + 3.39044747959503e-20)) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(-5.56953175797167e-24*fs - 9.5610618924578e-22) + 7.14108820102165e-34) - 1.80540050182853e-48) + pow(fs,2)*(fs*(fs*(3.86104353299586e-23*fs + 1.8179090443363e-21) + 3.39044747958769e-22) + 7.605464376339e-34)) + pow(fs,2)*(fs*(fs*(4.53805402033319e-24*fs + 9.41914629080951e-22) + 1.80077239576117e-20) - 1.69522373979748e-20)) + pow(fs,2)*(fs*(fs*(1.11898736808855e-23*fs - 5.24547124303932e-22) - 1.74198245202729e-20) + 6.97469477751319e-35)) + fs*(fs*(fs*(fs*(-1.61159196619408e-23*fs - 6.9746931237572e-21) - 5.44196016387214e-19) + 9.66029729825488e-17) + 1.35817220395143e-14) + 2.11902967474685e-14;\n\n    a2 = Bass*(Bass*(fs*(fs*(fs*(fs*(-6.72581680534004e-23*fs - 8.83173200281944e-21) + 1.49474306157678e-18) + 1.91594187071911e-16) + 3.57734473361347e-28) + 4.51350125457133e-42) + fs*(fs*(fs*(fs*(7.09491773348213e-23*fs + 1.62073614358674e-20) - 5.11745986630311e-18) - 3.35571109538599e-16) + 1.69522373979383e-16) - 1.90136609408475e-27) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(5.49427436280305e-23*fs - 6.28688894368408e-23) - 6.78089495920395e-22) + 1.52109287526779e-33) + pow(fs,2)*(fs*(fs*(1.11582073532266e-23*fs + 6.47087115401119e-22) - 1.70623420868666e-21) - 6.78089495919005e-20)) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(1.11390635159433e-23*fs + 6.37404126163853e-22) + 1.42821764020433e-33) + 3.61080100365706e-48) + pow(fs,2)*(fs*(fs*(-7.72208706599171e-23*fs - 1.21193936289087e-21) + 6.78089495917539e-22) - 1.5210928752678e-33)) + pow(fs,2)*(fs*(fs*(-9.07610804066639e-24*fs - 6.27943086053967e-22) + 3.60154479152234e-20) + 3.39044747959497e-20)) + pow(fs,2)*(fs*(fs*(-2.23797473617709e-23*fs + 3.49698082869288e-22) - 3.48396490405458e-20) - 1.39493895550264e-34)) + fs*(fs*(fs*(fs*(3.22318393238815e-23*fs + 4.64979541583813e-21) - 1.08839203277443e-18) - 1.93205945965098e-16) + 9.05448135967619e-15) + 4.23805934949371e-14;\n\n    a3 = Bass*(Bass*(fs*(fs*(fs*(fs*(6.72581680534004e-23*fs - 8.83173200281944e-21) - 1.49474306157678e-18) + 1.91594187071911e-16) - 3.57734473361347e-28) + 4.51350125457133e-42) + fs*(fs*(fs*(fs*(-7.09491773348213e-23*fs + 1.62073614358674e-20) + 5.11745986630311e-18) - 3.35571109538599e-16) - 1.69522373979383e-16) - 1.90136609408475e-27) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(-5.49427436280305e-23*fs - 6.28688894368408e-23) + 6.78089495920395e-22) + 1.52109287526779e-33) + pow(fs,2)*(fs*(fs*(-1.11582073532266e-23*fs + 6.47087115401119e-22) + 1.70623420868666e-21) - 6.78089495919005e-20)) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(-1.11390635159433e-23*fs + 6.37404126163853e-22) - 1.42821764020433e-33) + 3.61080100365706e-48) + pow(fs,2)*(fs*(fs*(7.72208706599171e-23*fs - 1.21193936289087e-21) - 6.78089495917539e-22) - 1.5210928752678e-33)) + pow(fs,2)*(fs*(fs*(9.07610804066639e-24*fs - 6.27943086053967e-22) - 3.60154479152234e-20) + 3.39044747959497e-20)) + pow(fs,2)*(fs*(fs*(2.23797473617709e-23*fs + 3.49698082869288e-22) + 3.48396490405458e-20) - 1.39493895550264e-34)) + fs*(fs*(fs*(fs*(-3.22318393238815e-23*fs + 4.64979541583813e-21) + 1.08839203277443e-18) - 1.93205945965098e-16) - 9.05448135967619e-15) + 4.23805934949371e-14;\n\n    a4 = Bass*(Bass*(fs*(fs*(fs*(fs*(-3.36290840267002e-23*fs + 1.32475980042292e-20) - 7.47371530788388e-19) - 9.57970935359556e-17) - 5.3660171004202e-28) + 2.25675062728566e-42) + fs*(fs*(fs*(fs*(3.54745886674106e-23*fs - 2.43110421538011e-20) + 2.55872993315156e-18) + 1.677855547693e-16) - 2.54283560969075e-16) - 9.50683047042375e-28) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(2.74713718140152e-23*fs + 9.43033341552612e-23) + 3.39044747960198e-22) - 7.60546437633897e-34) + pow(fs,2)*(fs*(fs*(5.57910367661329e-24*fs - 9.70630673101678e-22) + 8.5311710434333e-22) + 3.39044747959503e-20)) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(5.56953175797167e-24*fs - 9.5610618924578e-22) - 7.14108820102165e-34) - 1.80540050182853e-48) + pow(fs,2)*(fs*(fs*(-3.86104353299586e-23*fs + 1.8179090443363e-21) - 3.39044747958769e-22) + 7.605464376339e-34)) + pow(fs,2)*(fs*(fs*(-4.53805402033319e-24*fs + 9.41914629080951e-22) - 1.80077239576117e-20) - 1.69522373979748e-20)) + pow(fs,2)*(fs*(fs*(-1.11898736808855e-23*fs - 5.24547124303932e-22) + 1.74198245202729e-20) + 6.97469477751319e-35)) + fs*(fs*(fs*(fs*(1.61159196619408e-23*fs - 6.9746931237572e-21) + 5.44196016387214e-19) + 9.66029729825488e-17) - 1.35817220395143e-14) + 2.11902967474685e-14;\n\n    a5 = Bass*(Bass*(fs*(fs*(fs*(fs*(6.72581680534004e-24*fs - 4.41586600140972e-21) + 7.47371530788388e-19) - 9.57970935359556e-17) - 1.78867236680673e-28) + 4.51350125457133e-43) + fs*(fs*(fs*(fs*(-7.09491773348213e-24*fs + 8.1036807179337e-21) - 2.55872993315156e-18) + 1.677855547693e-16) - 8.47611869896916e-17) - 1.90136609408475e-28) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(-5.49427436280305e-24*fs - 3.14344447184204e-23) - 3.39044747960198e-22) - 7.60546437633897e-34) + pow(fs,2)*(fs*(fs*(-1.11582073532266e-24*fs + 3.23543557700559e-22) - 8.5311710434333e-22) + 3.39044747959503e-20)) + Treble*(Bass*(Bass*pow(fs,2)*(fs*(fs*(-1.11390635159433e-24*fs + 3.18702063081927e-22) + 7.14108820102165e-34) - 1.80540050182853e-48) + pow(fs,2)*(fs*(fs*(7.72208706599171e-24*fs - 6.05969681445433e-22) + 3.39044747958769e-22) + 7.605464376339e-34)) + pow(fs,2)*(fs*(fs*(9.07610804066639e-25*fs - 3.13971543026984e-22) + 1.80077239576117e-20) - 1.69522373979748e-20)) + pow(fs,2)*(fs*(fs*(2.23797473617709e-24*fs + 1.74849041434644e-22) - 1.74198245202729e-20) + 6.97469477751319e-35)) + fs*(fs*(fs*(fs*(-3.22318393238815e-24*fs + 2.32489770791907e-21) - 5.44196016387214e-19) + 9.66029729825488e-17) - 4.5272406798381e-15) + 4.23805934949371e-15;\n};\n\nprocess =  _<:*(dry),(*(wet) :p1:p2):>_;"
 },
 {
  "id": "gx-cstb",
  "name": "Colorsound Tone Bender",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Colorsound Tone Bender two-transistor fuzz with Attack, Level and wet/dry.",
  "description": "DK circuit simulation from the Colorsound Tone Bender schematic: pot-dependent filters followed by two transistor-stage tables, with a wet/dry blend. Attack sets the fuzz for a raw, sustaining British fuzz.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Colorsound_Tone_Blender/wet_dry"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Colorsound_Tone_Blender/Level"
   },
   {
    "label": "Attack",
    "min": 0,
    "max": 0.95,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Colorsound_Tone_Blender/Attack"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/cstb.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"cstb\";\ndeclare name \"Colorsound Tone Blender\";\ndeclare category \"Distortion\";\ndeclare shortname \"CS Toneblender\";\ndeclare description \"Colorsound Tone Blender\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\nprocess = pre : _<:*(dry),(*(wet) : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0)) : clip ):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    wet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100) : si.smooth(s);\n    dry = 1 - wet;\n    clip =  tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) ;\n    //clip(x) = 0.3 * (min(0.7514,max(-0.4514,x)));\n        \n        Level =  vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Attack = vslider(\"Attack[name:Attack]\", 0.5, 0, 0.95, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Attack*(Attack*(2.34677954600673e-19*Level*pow(fs,4) + 2.34677954600673e-22*pow(fs,4)) - 2.35728909376724e-17*Level*pow(fs,4) - 2.35728909376724e-20*pow(fs,4)) - 2.50775435507154e-15*Level*pow(fs,3) - 2.50775435507154e-18*pow(fs,3);\n\n    b1 = Attack*(Attack*(-9.38711818402692e-19*Level*pow(fs,4) - 9.38711818402692e-22*pow(fs,4)) + 9.42915637506898e-17*Level*pow(fs,4) + 9.42915637506898e-20*pow(fs,4)) + 5.01550871014307e-15*Level*pow(fs,3) + 5.01550871014307e-18*pow(fs,3);\n\n    b2 = Attack*(Attack*(1.40806772760404e-18*Level*pow(fs,4) + 1.40806772760404e-21*pow(fs,4)) - 1.41437345626035e-16*Level*pow(fs,4) - 1.41437345626035e-19*pow(fs,4));\n\n    b3 = Attack*(Attack*(-9.38711818402692e-19*Level*pow(fs,4) - 9.38711818402692e-22*pow(fs,4)) + 9.42915637506898e-17*Level*pow(fs,4) + 9.42915637506898e-20*pow(fs,4)) - 5.01550871014307e-15*Level*pow(fs,3) - 5.01550871014307e-18*pow(fs,3);\n\n    b4 = Attack*(Attack*(2.34677954600673e-19*Level*pow(fs,4) + 2.34677954600673e-22*pow(fs,4)) - 2.35728909376724e-17*Level*pow(fs,4) - 2.35728909376724e-20*pow(fs,4)) + 2.50775435507154e-15*Level*pow(fs,3) + 2.50775435507154e-18*pow(fs,3);\n\n    a0 = Attack*(Attack*fs*(fs*(fs*(-7.13788307669893e-19*fs - 3.81274375281155e-16) - 1.78337596435683e-14) - 3.57720562427687e-14) + fs*(fs*(fs*(7.26395344169953e-19*fs + 3.82634300978431e-16) + 1.78716714442828e-14) + 3.58457860428614e-14)) + fs*(fs*(7.72761004436121e-17*fs + 4.0705776699833e-14) + 1.90124164300881e-12) + 3.81338149392143e-12;\n\n    a1 = Attack*(Attack*fs*(pow(fs,2)*(2.85515323067957e-18*fs + 7.6254875056231e-16) - 7.15441124855374e-14) + fs*(pow(fs,2)*(-2.90558137667981e-18*fs - 7.65268601956861e-16) + 7.16915720857228e-14)) + fs*(-1.54552200887224e-16*pow(fs,2) + 3.80248328601762e-12) + 1.52535259756857e-11;\n\n    a2 = Attack*(Attack*pow(fs,2)*(-4.28272984601936e-18*pow(fs,2) + 3.56675192871367e-14) + pow(fs,2)*(4.35837206501972e-18*pow(fs,2) - 3.57433428885656e-14)) - 8.14115533996661e-14*pow(fs,2) + 2.28802889635286e-11;\n\n    a3 = Attack*(Attack*fs*(pow(fs,2)*(2.85515323067957e-18*fs - 7.6254875056231e-16) + 7.15441124855374e-14) + fs*(pow(fs,2)*(-2.90558137667981e-18*fs + 7.65268601956861e-16) - 7.16915720857228e-14)) + fs*(1.54552200887224e-16*pow(fs,2) - 3.80248328601762e-12) + 1.52535259756857e-11;\n\n    a4 = Attack*(Attack*fs*(fs*(fs*(-7.13788307669893e-19*fs + 3.81274375281155e-16) - 1.78337596435683e-14) + 3.57720562427687e-14) + fs*(fs*(fs*(7.26395344169953e-19*fs - 3.82634300978431e-16) + 1.78716714442828e-14) - 3.58457860428614e-14)) + fs*(fs*(-7.72761004436121e-17*fs + 4.0705776699833e-14) - 1.90124164300881e-12) + 3.81338149392143e-12;\n};"
 },
 {
  "id": "lib-cubicnl",
  "name": "Cubic Soft Clip",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "JOS cubic nonlinearity distortion with DC offset for even harmonics and a tone control",
  "description": "JOS cubic nonlinearity distortion with DC offset for even harmonics and a tone control",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Cubic_Soft_Clip/Drive"
   },
   {
    "label": "Offset",
    "min": 0,
    "max": 0.5,
    "default": 0.1,
    "step": 0.01,
    "unit": "",
    "path": "/Cubic_Soft_Clip/Offset"
   },
   {
    "label": "Tone",
    "min": 500,
    "max": 12000,
    "default": 4000,
    "step": 1,
    "unit": "Hz",
    "path": "/Cubic_Soft_Clip/Tone"
   },
   {
    "label": "Level",
    "min": -30,
    "max": 12,
    "default": -3,
    "step": 0.1,
    "unit": "dB",
    "path": "/Cubic_Soft_Clip/Level"
   }
  ],
  "faustCode": "declare name \"Cubic Soft Clip\";\ndeclare description \"JOS cubic nonlinearity distortion with DC offset for even harmonics and a tone control\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/misceffects.lib ef.cubicnl\";\ndeclare category \"guitar\";\ndeclare family \"dirt\";\nimport(\"stdfaust.lib\");\n\ndrive  = hslider(\"[0] Drive\", 0.5, 0, 1, 0.01) : si.smoo;\noffset = hslider(\"[1] Offset\", 0.1, 0, 0.5, 0.01) : si.smoo;\ntone   = hslider(\"[2] Tone[unit:Hz][scale:log]\", 4000, 500, 12000, 1) : si.smoo;\nlevel  = hslider(\"[3] Level[unit:dB]\", -3, -30, 12, 0.1) : ba.db2linear : si.smoo;\nprocess = ef.cubicnl_nodc(drive, offset) : fi.lowpass(1, tone) : *(level);"
 },
 {
  "id": "gx-rangem",
  "name": "Dallas Rangemaster",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Dallas Rangemaster germanium treble booster; cuts lows and drives an amp's front end.",
  "description": "DK circuit simulation from the Rangemaster schematic as a pot-dependent linear filter with a wet/dry blend. Boost adds the Rangemaster's bright, bass-shy push that sharpens an overdriven amp.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Rangemaster/wet_dry"
   },
   {
    "label": "Boost",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Rangemaster/Boost"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/rangem.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"rangem\";\ndeclare name \"Rangemaster\";\ndeclare category \"Tone Control\";\ndeclare shortname \"Rangemaster\";\ndeclare description \"High Frequency Booster\";\n\nimport(\"stdfaust.lib\");\n\nprocess = pre : _<:*(dry),(*(wet) : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0))):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    wet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\n    dry = 1 - wet;\n\n    \n        Boost = vslider(\"Boost[name:Boost]\", 0.5, 0, 1, 0.01) : Inverted(1) : si.smooth(s);\n    \n    b0 = Boost*pow(fs,2)*(8.31466608544754e-13*fs + 2.24531902904193e-12) + pow(fs,2)*(-8.32852386225662e-13*fs - 2.24906122742367e-12);\n\n    b1 = Boost*pow(fs,2)*(-2.49439982563426e-12*fs - 2.24531902904193e-12) + pow(fs,2)*(2.49855715867699e-12*fs + 2.24906122742367e-12);\n\n    b2 = Boost*pow(fs,2)*(2.49439982563426e-12*fs - 2.24531902904193e-12) + pow(fs,2)*(-2.49855715867699e-12*fs + 2.24906122742367e-12);\n\n    b3 = Boost*pow(fs,2)*(-8.31466608544754e-13*fs + 2.24531902904193e-12) + pow(fs,2)*(8.32852386225662e-13*fs - 2.24906122742367e-12);\n\n    a0 = Boost*(Boost*(fs*(fs*(-9.6103977657166e-17*fs - 1.29828683375003e-11) - 3.77055394062117e-11) - 6.47756445986258e-23) + fs*(fs*(-6.03049472237275e-17*fs + 1.26333088694976e-11) + 1.95791953523286e-11) + 3.36357739377656e-23) + fs*(fs*(4.37071753217797e-15*fs + 2.23510911173716e-10) + 1.20972656728663e-8) + 4.663130715952e-8;\n\n    a1 = Boost*(Boost*(fs*(fs*(2.88311932971498e-16*fs + 1.29828683375003e-11) - 3.77055394062117e-11) - 1.94326933795877e-22) + fs*(fs*(1.80914841671183e-16*fs - 1.26333088694976e-11) + 1.95791953523286e-11) + 1.00907321813297e-22) + fs*(fs*(-1.31121525965339e-14*fs - 2.23510911173716e-10) + 1.20972656728663e-8) + 1.3989392147856e-7;\n\n    a2 = Boost*(Boost*(fs*(fs*(-2.88311932971498e-16*fs + 1.29828683375003e-11) + 3.77055394062117e-11) - 1.94326933795877e-22) + fs*(fs*(-1.80914841671183e-16*fs - 1.26333088694976e-11) - 1.95791953523286e-11) + 1.00907321813297e-22) + fs*(fs*(1.31121525965339e-14*fs - 2.23510911173716e-10) - 1.20972656728663e-8) + 1.3989392147856e-7;\n\n    a3 = Boost*(Boost*(fs*(fs*(9.6103977657166e-17*fs - 1.29828683375003e-11) + 3.77055394062117e-11) - 6.47756445986258e-23) + fs*(fs*(6.03049472237275e-17*fs + 1.26333088694976e-11) - 1.95791953523286e-11) + 3.36357739377656e-23) + fs*(fs*(-4.37071753217797e-15*fs + 2.23510911173716e-10) - 1.20972656728663e-8) + 4.663130715952e-8;\n};"
 },
 {
  "id": "gx-ruin",
  "name": "Devi Ever Ruiner",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Devi Ever Ruiner / Dark Boost: nasty, splattery fuzz with Intensity and Level.",
  "description": "DK circuit simulation from the Ruiner schematic: pot-dependent filters with a symmetric clip table, at 96 kHz. Intensity pushes it from a dark boost into an unhinged, splattery fuzz.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Intensity",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Ruiner/Intensity"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Ruiner/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/ruin.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"ruin\";\ndeclare name \"Ruiner\";\ndeclare category \"Fuzz\";\ndeclare shortname \"Ruiner\";\ndeclare description \"Devi Ever Dark Boost\";\ndeclare drywetbox \"true\";\ndeclare samplerate \"96000\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\ngxc = library(\"clipping.lib\");\n\nruinerp1 = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n    \n        \n        Intensity = vslider(\"Intensity[name:Intensity]\", 0.5, 0, 1, 0.01) : Inverted(1) : si.smooth(s);\n            \n    b0 = -3.68740376472719e-5*fs;\n\n    b1 = 0;\n\n    b2 = 3.68740376472719e-5*fs;\n\n    a0 = Intensity*fs*(3.23341143501596e-10*fs + 1.83849805831657e-6) + fs*(2.50211258533327e-10*fs + 1.41841348392955e-7) + 9.19249029158284e-5;\n\n    a1 = -6.46682287003193e-10*Intensity*pow(fs,2) - 5.00422517066654e-10*pow(fs,2) + 0.000183849805831657;\n\n    a2 = Intensity*fs*(3.23341143501596e-10*fs - 1.83849805831657e-6) + fs*(2.50211258533327e-10*fs - 1.41841348392955e-7) + 9.19249029158284e-5;\n};\n\nruinerp2  = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n    \n        \n        Level = vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n            \n    b0 = -1.11891193819806e-10*Level*pow(fs,2) - 1.11891193819806e-12*pow(fs,2);\n\n    b1 = 1.11891193819806e-10*Level*pow(fs,2) + 1.11891193819806e-12*pow(fs,2);\n\n    b2 = 1.11891193819806e-10*Level*pow(fs,2) + 1.11891193819806e-12*pow(fs,2);\n\n    b3 = -1.11891193819806e-10*Level*pow(fs,2) - 1.11891193819806e-12*pow(fs,2);\n\n    a0 = Level*(Level*fs*(fs*(-8.62067474057856e-16*fs - 4.46379387426086e-13) - 5.75832602737396e-11) + fs*(fs*(8.53446799317278e-16*fs + 5.28122340957611e-13) + 7.99957173492034e-11) + 2.87916301368698e-9) + fs*(fs*(8.71550216272493e-15*fs + 5.37582514840965e-12) + 8.12279541046302e-10) + 2.88204217670067e-8;\n\n    a1 = Level*(Level*fs*(fs*(2.58620242217357e-15*fs + 4.46379387426086e-13) - 5.75832602737396e-11) + fs*(fs*(-2.56034039795183e-15*fs - 5.28122340957611e-13) + 7.99957173492034e-11) + 8.63748904106094e-9) + fs*(fs*(-2.61465064881748e-14*fs - 5.37582514840965e-12) + 8.12279541046302e-10) + 8.646126530102e-8;\n\n    a2 = Level*(Level*fs*(fs*(-2.58620242217357e-15*fs + 4.46379387426086e-13) + 5.75832602737396e-11) + fs*(fs*(2.56034039795183e-15*fs - 5.28122340957611e-13) - 7.99957173492034e-11) + 8.63748904106094e-9) + fs*(fs*(2.61465064881748e-14*fs - 5.37582514840965e-12) - 8.12279541046302e-10) + 8.646126530102e-8;\n\n    a3 = Level*(Level*fs*(fs*(8.62067474057856e-16*fs - 4.46379387426086e-13) + 5.75832602737396e-11) + fs*(fs*(-8.53446799317278e-16*fs + 5.28122340957611e-13) - 7.99957173492034e-11) + 2.87916301368698e-9) + fs*(fs*(-8.71550216272493e-15*fs + 5.37582514840965e-12) - 8.12279541046302e-10) + 2.88204217670067e-8;\n};\n\n    preclip =  min(1) : max(-1); \n    //clip(x) = ((exp(x*4)-exp(-x*4*1.2))/(exp(x*4)+exp(-x*4)))/4;\nclip = gxc.symclip;\n    aclip(x) = atan(x)/ma.PI;\n    //tclip = tranystageb(TB_SVEL34_68k,86.0,2700.0,25.922163) : tranystageb(TB_SVEL34_68k,86.0,2700.0,25.922163) ;\n    tclip = tranystageb(TB_7199P_68k,86.0,2700.0,5.571981) : tranystageb(TB_7199P_68k,86.0,2700.0,5.571981) ;\nprocess = ruinerp1 : clip : ruinerp2  ;"
 },
 {
  "id": "gx-eldist",
  "name": "Electra Distortion",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Electra one-transistor distortion: single gain stage with asymmetric diode clipping.",
  "description": "DK circuit simulation from the schematic of the Electra distortion circuit: a transistor gain stage as a pot-dependent filter with an asymmetric clip table, at 96 kHz. A raw, touch-sensitive single-knob (Drive) distortion.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Electra_Distortion/Drive"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/eldist.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"eldist\";\ndeclare name \"Electra Distortion\";\ndeclare category \"Distortion\";\ndeclare shortname \"Electra Dst\";\ndeclare description \"Electra Distortion\";\ndeclare samplerate \"96000\";\n\nimport(\"stdfaust.lib\");\n\ngxc = library(\"clipping.lib\");\n\nprocess = pre : fi.iir((b0/a0,b1/a0),(a1/a0)) : clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    //clip(x) = (min(0.4514,max(-0.4514,x)));\nasymclip = gxc.asymclip;\n    clip = (_ : asymclip);\n\n    \n        Drive = vslider(\"Drive[name:Drive]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = -8.14686408743197e-8*Drive*fs - 0.00018716364572377*fs;\n\n    b1 = 8.14686408743197e-8*Drive*fs + 0.00018716364572377*fs;\n\n    a0 = Drive*(-3.9949101411109e-5*fs - 8.66687668918243e-5) + 4.07955525542246e-5*fs + 0.000635245647283505;\n\n    a1 = Drive*(3.9949101411109e-5*fs - 8.66687668918243e-5) - 4.07955525542246e-5*fs + 0.000635245647283505;\n};"
 },
 {
  "id": "gx-ffreak",
  "name": "Fat Furry Freak",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Extreme bass fuzz with Fuzz, Tone, Gate and Level; huge and gated.",
  "description": "DK circuit simulation from the Fat Freak schematic: pot-dependent filters with clipping stages and an atan-shaped gate. An over-the-top bass fuzz whose Gate control chokes the decay for sputtery, velcro-style textures.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Fuzz",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fat_Furry_Freak/Fuzz"
   },
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fat_Furry_Freak/Tone"
   },
   {
    "label": "Gate",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fat_Furry_Freak/Gate"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fat_Furry_Freak/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/ffreak.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"ffreak\";\ndeclare name \"Fat Furry Freak\";\ndeclare category \"Fuzz\";\ndeclare shortname \"Fat FFreak\";\ndeclare description \"Extreme Bass Fuzz Monster\";\ndeclare drywetbox \"true\";\n\nimport(\"stdfaust.lib\");\n\nprocess = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0))  : clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    clip(x) =  atan(x)/ma.PI;\n\n    \n        \n        Fuzz = vslider(\"Fuzz[name:Fuzz]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n            \n        \n        Tone = vslider(\"Tone[name:Tone]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n            \n        \n        Gate = vslider(\"Gate[name:Gate]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n            \n        \n        Level = vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : +(0.01) : *(0.05) : Inverted(0) : si.smooth(s);\n            \n    b0 = Gate*(Tone*Level*(Fuzz*pow(fs,4)*(2.31663605170274e-21*fs + 1.15904771305164e-17) + pow(fs,3)*(fs*(-3.33595591445214e-21*fs - 1.66926037039962e-17) - 1.15904771305164e-17)) + Level*(Fuzz*pow(fs,3)*(1.55887720056646e-18*fs + 1.29589876827223e-14) + pow(fs,2)*(fs*(-2.24478316881583e-18*fs - 1.86625011403217e-14) - 1.29589876827223e-14))) + Tone*Level*(Fuzz*pow(fs,4)*(-2.79019064029167e-21*fs - 1.39597416617563e-17) + pow(fs,3)*(fs*(4.01337447559094e-21*fs + 2.00823037773104e-17) + 1.39597416617563e-17)) + Level*(Fuzz*pow(fs,3)*(-1.87753470001801e-18*fs - 1.56079959618215e-14) + pow(fs,2)*(fs*(2.70062186191725e-18*fs + 2.24522189930002e-14) + 1.56079959618215e-14));\n\n    b1 = Gate*(Tone*Level*(Fuzz*pow(fs,4)*(-1.15831802585137e-20*fs - 3.47714313915491e-17) + pow(fs,3)*(fs*(1.66797795722607e-20*fs + 5.00778111119886e-17) + 1.15904771305164e-17)) + Level*(Fuzz*pow(fs,3)*(-4.67663160169938e-18*fs - 1.29589876827223e-14) + pow(fs,2)*(fs*(6.7343495064475e-18*fs + 1.86625011403217e-14) - 1.29589876827223e-14))) + Tone*Level*(Fuzz*pow(fs,4)*(1.39509532014583e-20*fs + 4.18792249852688e-17) + pow(fs,3)*(fs*(-2.00668723779547e-20*fs - 6.02469113319311e-17) - 1.39597416617563e-17)) + Level*(Fuzz*pow(fs,3)*(5.63260410005403e-18*fs + 1.56079959618215e-14) + pow(fs,2)*(fs*(-8.10186558575176e-18*fs - 2.24522189930002e-14) + 1.56079959618215e-14));\n\n    b2 = Gate*(Tone*Level*(Fuzz*pow(fs,4)*(2.31663605170274e-20*fs + 2.31809542610327e-17) + pow(fs,3)*(fs*(-3.33595591445214e-20*fs - 3.33852074079924e-17) + 2.31809542610327e-17)) + Level*(Fuzz*pow(fs,3)*(3.11775440113292e-18*fs - 2.59179753654445e-14) + pow(fs,2)*(fs*(-4.48956633763166e-18*fs + 3.73250022806433e-14) + 2.59179753654445e-14))) + Tone*Level*(Fuzz*pow(fs,4)*(-2.79019064029167e-20*fs - 2.79194833235126e-17) + pow(fs,3)*(fs*(4.01337447559094e-20*fs + 4.01646075546207e-17) - 2.79194833235126e-17)) + Level*(Fuzz*pow(fs,3)*(-3.75506940003602e-18*fs + 3.12159919236431e-14) + pow(fs,2)*(fs*(5.40124372383451e-18*fs - 4.49044379860004e-14) - 3.12159919236431e-14));\n\n    b3 = Gate*(Tone*Level*(Fuzz*pow(fs,4)*(-2.31663605170274e-20*fs + 2.31809542610327e-17) + pow(fs,3)*(fs*(3.33595591445214e-20*fs - 3.33852074079924e-17) - 2.31809542610327e-17)) + Level*(Fuzz*pow(fs,3)*(3.11775440113292e-18*fs + 2.59179753654445e-14) + pow(fs,2)*(fs*(-4.48956633763166e-18*fs - 3.73250022806433e-14) + 2.59179753654445e-14))) + Tone*Level*(Fuzz*pow(fs,4)*(2.79019064029167e-20*fs - 2.79194833235126e-17) + pow(fs,3)*(fs*(-4.01337447559094e-20*fs + 4.01646075546207e-17) + 2.79194833235126e-17)) + Level*(Fuzz*pow(fs,3)*(-3.75506940003602e-18*fs - 3.12159919236431e-14) + pow(fs,2)*(fs*(5.40124372383451e-18*fs + 4.49044379860004e-14) - 3.12159919236431e-14));\n\n    b4 = Gate*(Tone*Level*(Fuzz*pow(fs,4)*(1.15831802585137e-20*fs - 3.47714313915491e-17) + pow(fs,3)*(fs*(-1.66797795722607e-20*fs + 5.00778111119886e-17) - 1.15904771305164e-17)) + Level*(Fuzz*pow(fs,3)*(-4.67663160169938e-18*fs + 1.29589876827223e-14) + pow(fs,2)*(fs*(6.7343495064475e-18*fs - 1.86625011403217e-14) - 1.29589876827223e-14))) + Tone*Level*(Fuzz*pow(fs,4)*(-1.39509532014583e-20*fs + 4.18792249852688e-17) + pow(fs,3)*(fs*(2.00668723779547e-20*fs - 6.02469113319311e-17) + 1.39597416617563e-17)) + Level*(Fuzz*pow(fs,3)*(5.63260410005403e-18*fs - 1.56079959618215e-14) + pow(fs,2)*(fs*(-8.10186558575176e-18*fs + 2.24522189930002e-14) + 1.56079959618215e-14));\n\n    b5 = Gate*(Tone*Level*(Fuzz*pow(fs,4)*(-2.31663605170274e-21*fs + 1.15904771305164e-17) + pow(fs,3)*(fs*(3.33595591445214e-21*fs - 1.66926037039962e-17) + 1.15904771305164e-17)) + Level*(Fuzz*pow(fs,3)*(1.55887720056646e-18*fs - 1.29589876827223e-14) + pow(fs,2)*(fs*(-2.24478316881583e-18*fs + 1.86625011403217e-14) - 1.29589876827223e-14))) + Tone*Level*(Fuzz*pow(fs,4)*(2.79019064029167e-21*fs - 1.39597416617563e-17) + pow(fs,3)*(fs*(-4.01337447559094e-21*fs + 2.00823037773104e-17) - 1.39597416617563e-17)) + Level*(Fuzz*pow(fs,3)*(-1.87753470001801e-18*fs + 1.56079959618215e-14) + pow(fs,2)*(fs*(2.70062186191725e-18*fs - 2.24522189930002e-14) + 1.56079959618215e-14));\n\n    a0 = Fuzz*fs*(fs*(fs*(fs*(-7.85412319843037e-24*fs - 7.78792746651557e-20) - 9.37831383212842e-17) - 2.2395439003671e-14) - 6.9809489892874e-15) + Gate*(Fuzz*fs*(fs*(fs*(fs*(6.54379653368279e-24*fs + 5.8178250366366e-20) + 1.85568523263077e-17) + 1.66102929456909e-16) + 5.00381548719697e-17) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(6.54379653368279e-24*fs + 5.62612870500991e-20) + 3.66325429672487e-18) + 2.81398235873665e-17) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-4.65295447579144e-24*fs - 2.3734396603456e-20) - 2.32762902199933e-18) - 1.88310920685508e-17) + fs*(fs*(fs*(fs*(4.76440117855883e-24*fs + 2.43075314241076e-20) + 2.40711435730575e-18) + 2.16097599157672e-17) + 1.88310920685508e-17)) + fs*(fs*(fs*(fs*(-6.70053233478593e-24*fs - 5.76153907610497e-20) - 3.80725717138185e-18) - 3.24770777204501e-17) - 2.81398235873665e-17)) + fs*(fs*(fs*(fs*(-6.70053233478593e-24*fs - 5.95782688271891e-20) - 1.90595008624394e-17) - 1.88638248347695e-16) - 2.17339588935373e-16) - 5.00381548719697e-17) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-7.85412319843037e-24*fs - 7.55784595381368e-20) - 7.35486357301917e-17) - 3.92585764869989e-15) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(5.5846598379774e-24*fs + 3.42119219586653e-20) + 3.19454127568422e-17) + 2.62717307381708e-15) + fs*(fs*(fs*(fs*(-5.71839588129828e-24*fs - 3.49001694087958e-20) - 3.20489931550843e-17) - 2.65988017960028e-15) - 2.62717307381708e-15)) + fs*(fs*(fs*(fs*(8.04220615975415e-24*fs + 7.72040670186403e-20) + 7.37353569889037e-17) + 4.00054450346227e-15) + 3.92585764869989e-15)) + fs*(fs*(fs*(fs*(8.04220615975415e-24*fs + 7.95599798455062e-20) + 9.44004344622607e-17) + 2.24958749395835e-14) + 2.93784119708285e-14) + 6.9809489892874e-15;\n\n    a1 = Fuzz*fs*(fs*(fs*(fs*(3.92706159921519e-23*fs + 2.33637823995467e-19) + 9.37831383212842e-17) - 2.2395439003671e-14) - 2.09428469678622e-14) + Gate*(Fuzz*fs*(fs*(fs*(fs*(-3.27189826684139e-23*fs - 1.74534751099098e-19) - 1.85568523263077e-17) + 1.66102929456909e-16) + 1.50114464615909e-16) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-3.27189826684139e-23*fs - 1.68783861150297e-19) - 3.66325429672487e-18) + 2.81398235873665e-17) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(2.32647723789572e-23*fs + 7.1203189810368e-20) + 2.32762902199933e-18) - 1.88310920685508e-17) + fs*(fs*(fs*(fs*(-2.38220058927942e-23*fs - 7.29225942723227e-20) - 2.40711435730575e-18) + 2.16097599157672e-17) + 5.64932762056525e-17)) + fs*(fs*(fs*(fs*(3.35026616739297e-23*fs + 1.72846172283149e-19) + 3.80725717138185e-18) - 3.24770777204501e-17) - 8.44194707620995e-17)) + fs*(fs*(fs*(fs*(3.35026616739297e-23*fs + 1.78734806481567e-19) + 1.90595008624394e-17) - 1.88638248347695e-16) - 6.52018766806119e-16) - 2.50190774359849e-16) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(3.92706159921519e-23*fs + 2.2673537861441e-19) + 7.35486357301917e-17) - 3.92585764869989e-15) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-2.7923299189887e-23*fs - 1.02635765875996e-19) - 3.19454127568422e-17) + 2.62717307381708e-15) + fs*(fs*(fs*(fs*(2.85919794064914e-23*fs + 1.04700508226387e-19) + 3.20489931550843e-17) - 2.65988017960028e-15) - 7.88151922145125e-15)) + fs*(fs*(fs*(fs*(-4.02110307987707e-23*fs - 2.31612201055921e-19) - 7.37353569889037e-17) + 4.00054450346227e-15) + 1.17775729460997e-14)) + fs*(fs*(fs*(fs*(-4.02110307987707e-23*fs - 2.38679939536519e-19) - 9.44004344622607e-17) + 2.24958749395835e-14) + 8.81352359124856e-14) + 3.4904744946437e-14;\n\n    a2 = Fuzz*fs*(fs*(fs*(fs*(-7.85412319843037e-23*fs - 1.55758549330311e-19) + 1.87566276642568e-16) + 4.4790878007342e-14) - 1.39618979785748e-14) + Gate*(Fuzz*fs*(fs*(fs*(fs*(6.54379653368279e-23*fs + 1.16356500732732e-19) - 3.71137046526153e-17) - 3.32205858913818e-16) + 1.00076309743939e-16) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(6.54379653368279e-23*fs + 1.12522574100198e-19) - 7.32650859344974e-18) - 5.6279647174733e-17) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-4.65295447579144e-23*fs - 4.7468793206912e-20) + 4.65525804399867e-18) + 3.76621841371017e-17) + fs*(fs*(fs*(fs*(4.76440117855883e-23*fs + 4.86150628482151e-20) - 4.8142287146115e-18) - 4.32195198315344e-17) + 3.76621841371017e-17)) + fs*(fs*(fs*(fs*(-6.70053233478593e-23*fs - 1.15230781522099e-19) + 7.6145143427637e-18) + 6.49541554409002e-17) - 5.6279647174733e-17)) + fs*(fs*(fs*(fs*(-6.70053233478593e-23*fs - 1.19156537654378e-19) + 3.81190017248788e-17) + 3.7727649669539e-16) - 4.34679177870746e-16) - 5.00381548719697e-16) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-7.85412319843037e-23*fs - 1.51156919076274e-19) + 1.47097271460383e-16) + 7.85171529739978e-15) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(5.5846598379774e-23*fs + 6.84238439173306e-20) - 6.38908255136844e-17) - 5.25434614763417e-15) + fs*(fs*(fs*(fs*(-5.71839588129828e-23*fs - 6.98003388175915e-20) + 6.40979863101685e-17) + 5.31976035920056e-15) - 5.25434614763417e-15)) + fs*(fs*(fs*(fs*(8.04220615975415e-23*fs + 1.54408134037281e-19) - 1.47470713977807e-16) - 8.00108900692453e-15) + 7.85171529739978e-15)) + fs*(fs*(fs*(fs*(8.04220615975415e-23*fs + 1.59119959691012e-19) - 1.88800868924521e-16) - 4.49917498791669e-14) + 5.87568239416571e-14) + 6.9809489892874e-14;\n\n    a3 = Fuzz*fs*(fs*(fs*(fs*(7.85412319843037e-23*fs - 1.55758549330311e-19) - 1.87566276642568e-16) + 4.4790878007342e-14) + 1.39618979785748e-14) + Gate*(Fuzz*fs*(fs*(fs*(fs*(-6.54379653368279e-23*fs + 1.16356500732732e-19) + 3.71137046526153e-17) - 3.32205858913818e-16) - 1.00076309743939e-16) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-6.54379653368279e-23*fs + 1.12522574100198e-19) + 7.32650859344974e-18) - 5.6279647174733e-17) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(4.65295447579144e-23*fs - 4.7468793206912e-20) - 4.65525804399867e-18) + 3.76621841371017e-17) + fs*(fs*(fs*(fs*(-4.76440117855883e-23*fs + 4.86150628482151e-20) + 4.8142287146115e-18) - 4.32195198315344e-17) - 3.76621841371017e-17)) + fs*(fs*(fs*(fs*(6.70053233478593e-23*fs - 1.15230781522099e-19) - 7.6145143427637e-18) + 6.49541554409002e-17) + 5.6279647174733e-17)) + fs*(fs*(fs*(fs*(6.70053233478593e-23*fs - 1.19156537654378e-19) - 3.81190017248788e-17) + 3.7727649669539e-16) + 4.34679177870746e-16) - 5.00381548719697e-16) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(7.85412319843037e-23*fs - 1.51156919076274e-19) - 1.47097271460383e-16) + 7.85171529739978e-15) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-5.5846598379774e-23*fs + 6.84238439173306e-20) + 6.38908255136844e-17) - 5.25434614763417e-15) + fs*(fs*(fs*(fs*(5.71839588129828e-23*fs - 6.98003388175915e-20) - 6.40979863101685e-17) + 5.31976035920056e-15) + 5.25434614763417e-15)) + fs*(fs*(fs*(fs*(-8.04220615975415e-23*fs + 1.54408134037281e-19) + 1.47470713977807e-16) - 8.00108900692453e-15) - 7.85171529739978e-15)) + fs*(fs*(fs*(fs*(-8.04220615975415e-23*fs + 1.59119959691012e-19) + 1.88800868924521e-16) - 4.49917498791669e-14) - 5.87568239416571e-14) + 6.9809489892874e-14;\n\n    a4 = Fuzz*fs*(fs*(fs*(fs*(-3.92706159921519e-23*fs + 2.33637823995467e-19) - 9.37831383212842e-17) - 2.2395439003671e-14) + 2.09428469678622e-14) + Gate*(Fuzz*fs*(fs*(fs*(fs*(3.27189826684139e-23*fs - 1.74534751099098e-19) + 1.85568523263077e-17) + 1.66102929456909e-16) - 1.50114464615909e-16) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(3.27189826684139e-23*fs - 1.68783861150297e-19) + 3.66325429672487e-18) + 2.81398235873665e-17) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-2.32647723789572e-23*fs + 7.1203189810368e-20) - 2.32762902199933e-18) - 1.88310920685508e-17) + fs*(fs*(fs*(fs*(2.38220058927942e-23*fs - 7.29225942723227e-20) + 2.40711435730575e-18) + 2.16097599157672e-17) - 5.64932762056525e-17)) + fs*(fs*(fs*(fs*(-3.35026616739297e-23*fs + 1.72846172283149e-19) - 3.80725717138185e-18) - 3.24770777204501e-17) + 8.44194707620995e-17)) + fs*(fs*(fs*(fs*(-3.35026616739297e-23*fs + 1.78734806481567e-19) - 1.90595008624394e-17) - 1.88638248347695e-16) + 6.52018766806119e-16) - 2.50190774359849e-16) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-3.92706159921519e-23*fs + 2.2673537861441e-19) - 7.35486357301917e-17) - 3.92585764869989e-15) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(2.7923299189887e-23*fs - 1.02635765875996e-19) + 3.19454127568422e-17) + 2.62717307381708e-15) + fs*(fs*(fs*(fs*(-2.85919794064914e-23*fs + 1.04700508226387e-19) - 3.20489931550843e-17) - 2.65988017960028e-15) + 7.88151922145125e-15)) + fs*(fs*(fs*(fs*(4.02110307987707e-23*fs - 2.31612201055921e-19) + 7.37353569889037e-17) + 4.00054450346227e-15) - 1.17775729460997e-14)) + fs*(fs*(fs*(fs*(4.02110307987707e-23*fs - 2.38679939536519e-19) + 9.44004344622607e-17) + 2.24958749395835e-14) - 8.81352359124856e-14) + 3.4904744946437e-14;\n\n    a5 = Fuzz*fs*(fs*(fs*(fs*(7.85412319843037e-24*fs - 7.78792746651557e-20) + 9.37831383212842e-17) - 2.2395439003671e-14) + 6.9809489892874e-15) + Gate*(Fuzz*fs*(fs*(fs*(fs*(-6.54379653368279e-24*fs + 5.8178250366366e-20) - 1.85568523263077e-17) + 1.66102929456909e-16) - 5.00381548719697e-17) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-6.54379653368279e-24*fs + 5.62612870500991e-20) - 3.66325429672487e-18) + 2.81398235873665e-17) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(4.65295447579144e-24*fs - 2.3734396603456e-20) + 2.32762902199933e-18) - 1.88310920685508e-17) + fs*(fs*(fs*(fs*(-4.76440117855883e-24*fs + 2.43075314241076e-20) - 2.40711435730575e-18) + 2.16097599157672e-17) - 1.88310920685508e-17)) + fs*(fs*(fs*(fs*(6.70053233478593e-24*fs - 5.76153907610497e-20) + 3.80725717138185e-18) - 3.24770777204501e-17) + 2.81398235873665e-17)) + fs*(fs*(fs*(fs*(6.70053233478593e-24*fs - 5.95782688271891e-20) + 1.90595008624394e-17) - 1.88638248347695e-16) + 2.17339588935373e-16) - 5.00381548719697e-17) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(7.85412319843037e-24*fs - 7.55784595381368e-20) + 7.35486357301917e-17) - 3.92585764869989e-15) + Tone*(Fuzz*pow(fs,2)*(fs*(fs*(-5.5846598379774e-24*fs + 3.42119219586653e-20) - 3.19454127568422e-17) + 2.62717307381708e-15) + fs*(fs*(fs*(fs*(5.71839588129828e-24*fs - 3.49001694087958e-20) + 3.20489931550843e-17) - 2.65988017960028e-15) + 2.62717307381708e-15)) + fs*(fs*(fs*(fs*(-8.04220615975415e-24*fs + 7.72040670186403e-20) - 7.37353569889037e-17) + 4.00054450346227e-15) - 3.92585764869989e-15)) + fs*(fs*(fs*(fs*(-8.04220615975415e-24*fs + 7.95599798455062e-20) - 9.44004344622607e-17) + 2.24958749395835e-14) - 2.93784119708285e-14) + 6.9809489892874e-15;\n};"
 },
 {
  "id": "gx-foxeylady",
  "name": "Foxey Lady",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Guild Foxey Lady (Tone Bender-style) three-transistor fuzz with Fuzz and Level.",
  "description": "DK circuit simulation from the Foxey Lady schematic: pot-dependent state-space filters followed by three transistor-stage tables. A thick, saturated three-transistor fuzz in the Tone Bender family.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Fuzz",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Foxey_Lady/Fuzz"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Foxey_Lady/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/foxeylady.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"foxeylady\";\ndeclare name \"Foxey Lady\";\ndeclare category \"Fuzz\";\ndeclare shortname \"Foxey Lady\";\ndeclare description \"Foxey Lady fuzz pedal simulation\";\ndeclare insert_p \"tranyclipper\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\nprocess =  fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0,b6/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0,a6/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    //clip = tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) ;\n    \n        Level = vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Fuzz = vslider(\"Fuzz[name:Fuzz]\", 0.5, 0, 1, 0.01) : Inverted(1) : si.smooth(s);\n    \n    b0 = Fuzz*(Level*pow(fs,2)*(fs*(fs*(fs*(6.42669378638762e-27*fs + 2.86240593005591e-23) + 1.79551930386446e-19) + 3.55668379874028e-17) + 4.84302033942378e-16) + pow(fs,2)*(fs*(fs*(fs*(6.42669378638762e-29*fs + 2.86240593005591e-25) + 1.79551930386446e-21) + 3.55668379874028e-19) + 4.84302033942378e-18)) + Level*pow(fs,2)*(fs*(fs*(fs*(-3.28344197367049e-28*fs - 1.8701619702637e-23) - 2.16157324062859e-19) - 4.33524374895714e-17) - 5.90848481409701e-16) + pow(fs,2)*(fs*(fs*(fs*(-3.28344197367049e-30*fs - 1.8701619702637e-25) - 2.16157324062859e-21) - 4.33524374895714e-19) - 5.90848481409701e-18);\n\n    b1 = Fuzz*(Level*pow(fs,2)*(pow(fs,2)*(fs*(-3.85601627183257e-26*fs - 1.14496237202237e-22) - 3.59103860772892e-19) + 9.68604067884756e-16) + pow(fs,2)*(pow(fs,2)*(fs*(-3.85601627183257e-28*fs - 1.14496237202237e-24) - 3.59103860772892e-21) + 9.68604067884756e-18)) + Level*pow(fs,2)*(pow(fs,2)*(fs*(1.97006518420229e-27*fs + 7.48064788105479e-23) + 4.32314648125718e-19) - 1.1816969628194e-15) + pow(fs,2)*(pow(fs,2)*(fs*(1.97006518420229e-29*fs + 7.48064788105479e-25) + 4.32314648125718e-21) - 1.1816969628194e-17);\n\n    b2 = Fuzz*(Level*pow(fs,2)*(fs*(fs*(fs*(9.64004067958143e-26*fs + 1.43120296502796e-22) - 1.79551930386446e-19) - 1.06700513962208e-16) - 4.84302033942378e-16) + pow(fs,2)*(fs*(fs*(fs*(9.64004067958143e-28*fs + 1.43120296502796e-24) - 1.79551930386446e-21) - 1.06700513962208e-18) - 4.84302033942378e-18)) + Level*pow(fs,2)*(fs*(fs*(fs*(-4.92516296050573e-27*fs - 9.35080985131849e-23) + 2.16157324062859e-19) + 1.30057312468714e-16) + 5.90848481409701e-16) + pow(fs,2)*(fs*(fs*(fs*(-4.92516296050573e-29*fs - 9.35080985131849e-25) + 2.16157324062859e-21) + 1.30057312468714e-18) + 5.90848481409701e-18);\n\n    b3 = Fuzz*(Level*pow(fs,2)*(pow(fs,2)*(-1.28533875727752e-25*pow(fs,2) + 7.18207721545784e-19) - 1.93720813576951e-15) + pow(fs,2)*(pow(fs,2)*(-1.28533875727752e-27*pow(fs,2) + 7.18207721545784e-21) - 1.93720813576951e-17)) + Level*pow(fs,2)*(pow(fs,2)*(6.56688394734098e-27*pow(fs,2) - 8.64629296251435e-19) + 2.3633939256388e-15) + pow(fs,2)*(pow(fs,2)*(6.56688394734098e-29*pow(fs,2) - 8.64629296251435e-21) + 2.3633939256388e-17);\n\n    b4 = Fuzz*(Level*pow(fs,2)*(fs*(fs*(fs*(9.64004067958143e-26*fs - 1.43120296502796e-22) - 1.79551930386446e-19) + 1.06700513962208e-16) - 4.84302033942378e-16) + pow(fs,2)*(fs*(fs*(fs*(9.64004067958143e-28*fs - 1.43120296502796e-24) - 1.79551930386446e-21) + 1.06700513962208e-18) - 4.84302033942378e-18)) + Level*pow(fs,2)*(fs*(fs*(fs*(-4.92516296050573e-27*fs + 9.35080985131849e-23) + 2.16157324062859e-19) - 1.30057312468714e-16) + 5.90848481409701e-16) + pow(fs,2)*(fs*(fs*(fs*(-4.92516296050573e-29*fs + 9.35080985131849e-25) + 2.16157324062859e-21) - 1.30057312468714e-18) + 5.90848481409701e-18);\n\n    b5 = Fuzz*(Level*pow(fs,2)*(pow(fs,2)*(fs*(-3.85601627183257e-26*fs + 1.14496237202237e-22) - 3.59103860772892e-19) + 9.68604067884756e-16) + pow(fs,2)*(pow(fs,2)*(fs*(-3.85601627183257e-28*fs + 1.14496237202237e-24) - 3.59103860772892e-21) + 9.68604067884756e-18)) + Level*pow(fs,2)*(pow(fs,2)*(fs*(1.97006518420229e-27*fs - 7.48064788105479e-23) + 4.32314648125718e-19) - 1.1816969628194e-15) + pow(fs,2)*(pow(fs,2)*(fs*(1.97006518420229e-29*fs - 7.48064788105479e-25) + 4.32314648125718e-21) - 1.1816969628194e-17);\n\n    b6 = Fuzz*(Level*pow(fs,2)*(fs*(fs*(fs*(6.42669378638762e-27*fs - 2.86240593005591e-23) + 1.79551930386446e-19) - 3.55668379874028e-17) + 4.84302033942378e-16) + pow(fs,2)*(fs*(fs*(fs*(6.42669378638762e-29*fs - 2.86240593005591e-25) + 1.79551930386446e-21) - 3.55668379874028e-19) + 4.84302033942378e-18)) + Level*pow(fs,2)*(fs*(fs*(fs*(-3.28344197367049e-28*fs + 1.8701619702637e-23) - 2.16157324062859e-19) + 4.33524374895714e-17) - 5.90848481409701e-16) + pow(fs,2)*(fs*(fs*(fs*(-3.28344197367049e-30*fs + 1.8701619702637e-25) - 2.16157324062859e-21) + 4.33524374895714e-19) - 5.90848481409701e-18);\n\n    a0 = Fuzz*(Fuzz*fs*(fs*(fs*(fs*(fs*(-4.59387215604116e-29*fs - 4.36933720361044e-25) - 8.96539812308464e-22) - 3.5938048928126e-19) - 4.96738293767392e-17) - 2.0568206880379e-15) + fs*(fs*(fs*(fs*(fs*(4.57704216569471e-29*fs + 4.12221097685163e-25) + 2.55877854891379e-22) - 9.9587457844786e-19) - 4.94708666311112e-16) - 7.32065571555064e-14) - 3.1163949818756e-12) + fs*(fs*(fs*(fs*(fs*(5.24588897595767e-29*fs + 7.02844574269719e-25) + 2.89396306244108e-21) + 3.61888994332083e-18) + 1.29693461432975e-15) + 1.71281273151154e-13) + 6.94956080958259e-12;\n\n    a1 = Fuzz*(Fuzz*fs*(fs*(pow(fs,2)*(fs*(2.7563232936247e-28*fs + 1.74773488144418e-24) + 1.79307962461693e-21) - 9.93476587534785e-17) - 8.22728275215159e-15) + fs*(fs*(pow(fs,2)*(fs*(-2.74622529941683e-28*fs - 1.64888439074065e-24) - 5.11755709782759e-22) - 9.89417332622223e-16) - 2.92826228622026e-13) - 1.86983698912536e-11) + fs*(fs*(pow(fs,2)*(fs*(-3.1475333855746e-28*fs - 2.81137829707888e-24) - 5.78792612488216e-21) + 2.5938692286595e-15) + 6.85125092604618e-13) + 4.16973648574956e-11;\n\n    a2 = Fuzz*(Fuzz*fs*(fs*(fs*(fs*(fs*(-6.89080823406175e-28*fs - 2.18466860180522e-24) + 8.96539812308464e-22) + 1.07814146784378e-18) + 4.96738293767392e-17) - 1.02841034401895e-14) + fs*(fs*(fs*(fs*(fs*(6.86556324854206e-28*fs + 2.06110548842582e-24) - 2.55877854891379e-22) + 2.98762373534358e-18) + 4.94708666311112e-16) - 3.66032785777532e-13) - 4.6745924728134e-11) + fs*(fs*(fs*(fs*(fs*(7.8688334639365e-28*fs + 3.51422287134859e-24) - 2.89396306244108e-21) - 1.08566698299625e-17) - 1.29693461432975e-15) + 8.56406365755772e-13) + 1.04243412143739e-10;\n\n    a3 = Fuzz*(Fuzz*pow(fs,2)*(pow(fs,2)*(9.18774431208233e-28*pow(fs,2) - 3.58615924923386e-21) + 1.98695317506957e-16) + pow(fs,2)*(pow(fs,2)*(-9.15408433138942e-28*pow(fs,2) + 1.02351141956552e-21) + 1.97883466524445e-15) - 6.23278996375121e-11) + pow(fs,2)*(pow(fs,2)*(-1.04917779519153e-27*pow(fs,2) + 1.15758522497643e-20) - 5.18773845731899e-15) + 1.38991216191652e-10;\n\n    a4 = Fuzz*(Fuzz*fs*(fs*(fs*(fs*(fs*(-6.89080823406175e-28*fs + 2.18466860180522e-24) + 8.96539812308464e-22) - 1.07814146784378e-18) + 4.96738293767392e-17) + 1.02841034401895e-14) + fs*(fs*(fs*(fs*(fs*(6.86556324854206e-28*fs - 2.06110548842582e-24) - 2.55877854891379e-22) - 2.98762373534358e-18) + 4.94708666311112e-16) + 3.66032785777532e-13) - 4.6745924728134e-11) + fs*(fs*(fs*(fs*(fs*(7.8688334639365e-28*fs - 3.51422287134859e-24) - 2.89396306244108e-21) + 1.08566698299625e-17) - 1.29693461432975e-15) - 8.56406365755772e-13) + 1.04243412143739e-10;\n\n    a5 = Fuzz*(Fuzz*fs*(fs*(pow(fs,2)*(fs*(2.7563232936247e-28*fs - 1.74773488144418e-24) + 1.79307962461693e-21) - 9.93476587534785e-17) + 8.22728275215159e-15) + fs*(fs*(pow(fs,2)*(fs*(-2.74622529941683e-28*fs + 1.64888439074065e-24) - 5.11755709782759e-22) - 9.89417332622223e-16) + 2.92826228622026e-13) - 1.86983698912536e-11) + fs*(fs*(pow(fs,2)*(fs*(-3.1475333855746e-28*fs + 2.81137829707888e-24) - 5.78792612488216e-21) + 2.5938692286595e-15) - 6.85125092604618e-13) + 4.16973648574956e-11;\n\n    a6 = Fuzz*(Fuzz*fs*(fs*(fs*(fs*(fs*(-4.59387215604116e-29*fs + 4.36933720361044e-25) - 8.96539812308464e-22) + 3.5938048928126e-19) - 4.96738293767392e-17) + 2.0568206880379e-15) + fs*(fs*(fs*(fs*(fs*(4.57704216569471e-29*fs - 4.12221097685163e-25) + 2.55877854891379e-22) + 9.9587457844786e-19) - 4.94708666311112e-16) + 7.32065571555064e-14) - 3.1163949818756e-12) + fs*(fs*(fs*(fs*(fs*(5.24588897595767e-29*fs - 7.02844574269719e-25) + 2.89396306244108e-21) - 3.61888994332083e-18) + 1.29693461432975e-15) - 1.71281273151154e-13) + 6.94956080958259e-12;\n};"
 },
 {
  "id": "gx-fuzzfacefm",
  "name": "Fuzz Face (Fuller Mods)",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Fuzz Face with Mike Fuller's mods, adding a Drive control for finer gain range.",
  "description": "DK circuit simulation from the Fuzz Face Fuller-mods schematic: pot-dependent state-space filters with transistor-stage tables, with an added Drive control. A more controllable Fuzz Face with Fuzz, Drive and Level.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Fuzz",
    "min": 0,
    "max": 0.99,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fuzz_Face_Fuller/Fuzz"
   },
   {
    "label": "Drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fuzz_Face_Fuller/Drive"
   },
   {
    "label": "AUDIO IN",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fuzz_Face_Fuller/AUDIO_IN"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fuzz_Face_Fuller/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/fuzzfacefm.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"fuzzfacefm\";\ndeclare name \"Fuzz Face Fuller\";\ndeclare category \"Distortion\";\ndeclare shortname \"Fuzz Face FM\";\ndeclare description \"Micke Fuller Fuzz Face simulation\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\nprocess = fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) : clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    clip = tranystage(TB_KT88_68k,86.0,2700.0,5.562895) : tranystage(TB_KT88_68k,86.0,2700.0,5.562895) ;\n   \n        Drive = vslider(\"Drive[name:Drive]\", 0.5, 0, 1, 0.01) : Inverted(1) : si.smooth(s);\n    \n        Fuzz = vslider(\"Fuzz[name:Fuzz]\", 0.5, 0, 0.99, 0.01) : Inverted(1) : si.smooth(s);\n    \n        Input = vslider(\"AUDIO_IN[name:Input]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Level = vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : Inverted(1) : si.smooth(s);\n    \n    b0 = Drive*(Fuzz*(Fuzz*(-1.12927979815576e-15*Level*pow(fs,3) + 1.4115997476947e-15*pow(fs,3)) - 1.11420586447254e-13*Level*pow(fs,3) + 1.39275733059067e-13*pow(fs,3)) + Level*pow(fs,2)*(1.12549866245409e-13*fs + 2.58361695553557e-12) + pow(fs,2)*(-1.40687332806762e-13*fs - 3.22952119441946e-12)) + Fuzz*(Fuzz*(1.66004130328897e-15*Level*pow(fs,3) - 2.07505162911121e-15*pow(fs,3)) + 1.63788262077463e-13*Level*pow(fs,3) - 2.04735327596828e-13*pow(fs,3)) + Level*pow(fs,2)*(-1.65448303380752e-13*fs - 3.79791692463729e-12) + pow(fs,2)*(2.0681037922594e-13*fs + 4.74739615579661e-12);\n\n    b1 = Drive*(Fuzz*(Fuzz*(3.38783939446729e-15*Level*pow(fs,3) - 4.23479924308411e-15*pow(fs,3)) + 3.34261759341761e-13*Level*pow(fs,3) - 4.17827199177201e-13*pow(fs,3)) + Level*pow(fs,2)*(-3.37649598736228e-13*fs - 2.58361695553557e-12) + pow(fs,2)*(4.22061998420285e-13*fs + 3.22952119441946e-12)) + Fuzz*(Fuzz*(-4.98012390986691e-15*Level*pow(fs,3) + 6.22515488733364e-15*pow(fs,3)) - 4.91364786232388e-13*Level*pow(fs,3) + 6.14205982790485e-13*pow(fs,3)) + Level*pow(fs,2)*(4.96344910142255e-13*fs + 3.79791692463729e-12) + pow(fs,2)*(-6.20431137677819e-13*fs - 4.74739615579661e-12);\n\n    b2 = Drive*(Fuzz*(Fuzz*(-3.38783939446729e-15*Level*pow(fs,3) + 4.23479924308411e-15*pow(fs,3)) - 3.34261759341761e-13*Level*pow(fs,3) + 4.17827199177201e-13*pow(fs,3)) + Level*pow(fs,2)*(3.37649598736228e-13*fs - 2.58361695553557e-12) + pow(fs,2)*(-4.22061998420285e-13*fs + 3.22952119441946e-12)) + Fuzz*(Fuzz*(4.98012390986691e-15*Level*pow(fs,3) - 6.22515488733364e-15*pow(fs,3)) + 4.91364786232388e-13*Level*pow(fs,3) - 6.14205982790485e-13*pow(fs,3)) + Level*pow(fs,2)*(-4.96344910142255e-13*fs + 3.79791692463729e-12) + pow(fs,2)*(6.20431137677819e-13*fs - 4.74739615579661e-12);\n\n    b3 = Drive*(Fuzz*(Fuzz*(1.12927979815576e-15*Level*pow(fs,3) - 1.4115997476947e-15*pow(fs,3)) + 1.11420586447254e-13*Level*pow(fs,3) - 1.39275733059067e-13*pow(fs,3)) + Level*pow(fs,2)*(-1.12549866245409e-13*fs + 2.58361695553557e-12) + pow(fs,2)*(1.40687332806762e-13*fs - 3.22952119441946e-12)) + Fuzz*(Fuzz*(-1.66004130328897e-15*Level*pow(fs,3) + 2.07505162911121e-15*pow(fs,3)) - 1.63788262077463e-13*Level*pow(fs,3) + 2.04735327596828e-13*pow(fs,3)) + Level*pow(fs,2)*(1.65448303380752e-13*fs - 3.79791692463729e-12) + pow(fs,2)*(-2.0681037922594e-13*fs + 4.74739615579661e-12);\n\n    a0 = Drive*(Fuzz*(Fuzz*fs*(fs*(1.42504059392599e-16*fs + 6.43443174346988e-16) - 3.26234246975457e-55) + fs*(fs*(-1.42392288693486e-16*fs - 6.43214948741896e-16) + 3.45797348759893e-55)) + fs*(fs*(-1.1177069911304e-19*fs - 3.24149709132582e-15) - 1.46288954534563e-14) + 6.96979875434139e-54) + Fuzz*(Fuzz*fs*(fs*(-7.14615106636066e-14*fs - 7.44787041826973e-12) - 3.21721587173494e-11) + fs*(fs*(7.14054610111223e-14*fs + 7.44216743501989e-12) + 3.21607474370948e-11)) + Input*(Drive*(Fuzz*(Fuzz*pow(fs,2)*(-1.41557498356337e-16*fs + 7.17715343346006e-56) + pow(fs,2)*(1.41507288723217e-16*fs - 7.60754167271764e-56)) + fs*(fs*(5.02096331201311e-20*fs + 3.21835699976039e-15) - 1.53335572595511e-54)) + Fuzz*(Fuzz*pow(fs,2)*(7.09868387007524e-14*fs + 7.07787491781686e-12) + pow(fs,2)*(-7.09616600760317e-14*fs - 7.07536443616085e-12)) + fs*(fs*(-2.51786247207522e-17*fs - 1.61641996632585e-12) - 1.6091784998802e-10)) + fs*(fs*(5.60496524842164e-17*fs + 1.63110208134281e-12) + 1.69410806769336e-10) + 7.31444772672817e-10;\n\n    a1 = Drive*(Fuzz*(Fuzz*fs*(fs*(-4.27512178177797e-16*fs - 6.43443174346988e-16) - 3.26234246975457e-55) + fs*(fs*(4.27176866080457e-16*fs + 6.43214948741896e-16) + 3.45797348759893e-55)) + fs*(fs*(3.35312097339121e-19*fs + 3.24149709132582e-15) - 1.46288954534563e-14) + 2.09093962630242e-53) + Fuzz*(Fuzz*fs*(fs*(2.1438453199082e-13*fs + 7.44787041826973e-12) - 3.21721587173494e-11) + fs*(fs*(-2.14216383033367e-13*fs - 7.44216743501989e-12) + 3.21607474370948e-11)) + Input*(Drive*(Fuzz*(Fuzz*pow(fs,2)*(4.24672495069012e-16*fs - 7.17715343346006e-56) + pow(fs,2)*(-4.24521866169651e-16*fs + 7.60754167271764e-56)) + fs*(fs*(-1.50628899360393e-19*fs - 3.21835699976039e-15) - 1.53335572595511e-54)) + Fuzz*(Fuzz*pow(fs,2)*(-2.12960516102257e-13*fs - 7.07787491781686e-12) + pow(fs,2)*(2.12884980228095e-13*fs + 7.07536443616085e-12)) + fs*(fs*(7.55358741622564e-17*fs + 1.61641996632585e-12) - 1.6091784998802e-10)) + fs*(fs*(-1.68148957452649e-16*fs - 1.63110208134281e-12) + 1.69410806769336e-10) + 2.19433431801845e-9;\n\n    a2 = Drive*(Fuzz*(Fuzz*fs*(fs*(4.27512178177797e-16*fs - 6.43443174346988e-16) + 3.26234246975457e-55) + fs*(fs*(-4.27176866080457e-16*fs + 6.43214948741896e-16) - 3.45797348759893e-55)) + fs*(fs*(-3.35312097339121e-19*fs + 3.24149709132582e-15) + 1.46288954534563e-14) + 2.09093962630242e-53) + Fuzz*(Fuzz*fs*(fs*(-2.1438453199082e-13*fs + 7.44787041826973e-12) + 3.21721587173494e-11) + fs*(fs*(2.14216383033367e-13*fs - 7.44216743501989e-12) - 3.21607474370948e-11)) + Input*(Drive*(Fuzz*(Fuzz*pow(fs,2)*(-4.24672495069012e-16*fs - 7.17715343346006e-56) + pow(fs,2)*(4.24521866169651e-16*fs + 7.60754167271764e-56)) + fs*(fs*(1.50628899360393e-19*fs - 3.21835699976039e-15) + 1.53335572595511e-54)) + Fuzz*(Fuzz*pow(fs,2)*(2.12960516102257e-13*fs - 7.07787491781686e-12) + pow(fs,2)*(-2.12884980228095e-13*fs + 7.07536443616085e-12)) + fs*(fs*(-7.55358741622564e-17*fs + 1.61641996632585e-12) + 1.6091784998802e-10)) + fs*(fs*(1.68148957452649e-16*fs - 1.63110208134281e-12) - 1.69410806769336e-10) + 2.19433431801845e-9;\n\n    a3 = Drive*(Fuzz*(Fuzz*fs*(fs*(-1.42504059392599e-16*fs + 6.43443174346988e-16) + 3.26234246975457e-55) + fs*(fs*(1.42392288693486e-16*fs - 6.43214948741896e-16) - 3.45797348759893e-55)) + fs*(fs*(1.1177069911304e-19*fs - 3.24149709132582e-15) + 1.46288954534563e-14) + 6.96979875434139e-54) + Fuzz*(Fuzz*fs*(fs*(7.14615106636066e-14*fs - 7.44787041826973e-12) + 3.21721587173494e-11) + fs*(fs*(-7.14054610111223e-14*fs + 7.44216743501989e-12) - 3.21607474370948e-11)) + Input*(Drive*(Fuzz*(Fuzz*pow(fs,2)*(1.41557498356337e-16*fs + 7.17715343346006e-56) + pow(fs,2)*(-1.41507288723217e-16*fs - 7.60754167271764e-56)) + fs*(fs*(-5.02096331201311e-20*fs + 3.21835699976039e-15) + 1.53335572595511e-54)) + Fuzz*(Fuzz*pow(fs,2)*(-7.09868387007524e-14*fs + 7.07787491781686e-12) + pow(fs,2)*(7.09616600760317e-14*fs - 7.07536443616085e-12)) + fs*(fs*(2.51786247207522e-17*fs - 1.61641996632585e-12) + 1.6091784998802e-10)) + fs*(fs*(-5.60496524842164e-17*fs + 1.63110208134281e-12) - 1.69410806769336e-10) + 7.31444772672817e-10;\n};"
 },
 {
  "id": "gx-fuzzface",
  "name": "Fuzz Face (JH-1)",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Dallas Arbiter Fuzz Face (JH-1): warm two-transistor fuzz that cleans up with volume.",
  "description": "DK circuit simulation from the Fuzz Face JH-1 schematic: a 5th-order state-space filter whose coefficients follow the Fuzz and Level pots, followed by transistor-stage tables. Classic Hendrix-style fuzz with Fuzz and Level.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Fuzz",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fuzz_Face/Fuzz"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fuzz_Face/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/fuzzface.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"fuzzface\";\ndeclare name \"Fuzz Face\";\ndeclare category \"Distortion\";\ndeclare description \"J Hendrix Fuzz Face simulation\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\nprocess = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0)) : clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    clip = tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) ;\n    //clip(x) = 0.4 * (min(0.7514,max(-0.4514,x)));\n\n    \n        Level = 1.0 - vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Fuzz = 1.0 - vslider(\"Fuzz[name:Fuzz]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Fuzz*(Fuzz*(Level*pow(fs,3)*(4.76991513499346e-20*fs + 5.38351707988916e-15) + pow(fs,3)*(-4.76991513499346e-20*fs - 5.38351707988916e-15)) + Level*pow(fs,3)*(-4.76991513499346e-20*fs + 5.00346713698171e-13) + pow(fs,3)*(4.76991513499346e-20*fs - 5.00346713698171e-13)) + Level*pow(fs,2)*(-5.05730339185222e-13*fs - 1.16162215422261e-12) + pow(fs,2)*(5.05730339185222e-13*fs + 1.16162215422261e-12);\n\n    b1 = Fuzz*(Fuzz*(Level*pow(fs,3)*(-1.43097454049804e-19*fs - 5.38351707988916e-15) + pow(fs,3)*(1.43097454049804e-19*fs + 5.38351707988916e-15)) + Level*pow(fs,3)*(1.43097454049804e-19*fs - 5.00346713698171e-13) + pow(fs,3)*(-1.43097454049804e-19*fs + 5.00346713698171e-13)) + Level*pow(fs,2)*(5.05730339185222e-13*fs - 1.16162215422261e-12) + pow(fs,2)*(-5.05730339185222e-13*fs + 1.16162215422261e-12);\n\n    b2 = Fuzz*(Fuzz*(Level*pow(fs,3)*(9.53983026998693e-20*fs - 1.07670341597783e-14) + pow(fs,3)*(-9.53983026998693e-20*fs + 1.07670341597783e-14)) + Level*pow(fs,3)*(-9.53983026998693e-20*fs - 1.00069342739634e-12) + pow(fs,3)*(9.53983026998693e-20*fs + 1.00069342739634e-12)) + Level*pow(fs,2)*(1.01146067837044e-12*fs + 2.32324430844522e-12) + pow(fs,2)*(-1.01146067837044e-12*fs - 2.32324430844522e-12);\n\n    b3 = Fuzz*(Fuzz*(Level*pow(fs,3)*(9.53983026998693e-20*fs + 1.07670341597783e-14) + pow(fs,3)*(-9.53983026998693e-20*fs - 1.07670341597783e-14)) + Level*pow(fs,3)*(-9.53983026998693e-20*fs + 1.00069342739634e-12) + pow(fs,3)*(9.53983026998693e-20*fs - 1.00069342739634e-12)) + Level*pow(fs,2)*(-1.01146067837044e-12*fs + 2.32324430844522e-12) + pow(fs,2)*(1.01146067837044e-12*fs - 2.32324430844522e-12);\n\n    b4 = Fuzz*(Fuzz*(Level*pow(fs,3)*(-1.43097454049804e-19*fs + 5.38351707988916e-15) + pow(fs,3)*(1.43097454049804e-19*fs - 5.38351707988916e-15)) + Level*pow(fs,3)*(1.43097454049804e-19*fs + 5.00346713698171e-13) + pow(fs,3)*(-1.43097454049804e-19*fs - 5.00346713698171e-13)) + Level*pow(fs,2)*(-5.05730339185222e-13*fs - 1.16162215422261e-12) + pow(fs,2)*(5.05730339185222e-13*fs + 1.16162215422261e-12);\n\n    b5 = Fuzz*(Fuzz*(Level*pow(fs,3)*(4.76991513499346e-20*fs - 5.38351707988916e-15) + pow(fs,3)*(-4.76991513499346e-20*fs + 5.38351707988916e-15)) + Level*pow(fs,3)*(-4.76991513499346e-20*fs - 5.00346713698171e-13) + pow(fs,3)*(4.76991513499346e-20*fs + 5.00346713698171e-13)) + Level*pow(fs,2)*(5.05730339185222e-13*fs - 1.16162215422261e-12) + pow(fs,2)*(-5.05730339185222e-13*fs + 1.16162215422261e-12);\n\n    a0 = Fuzz*(Fuzz*fs*(fs*(fs*(fs*(-3.73292075290073e-29*fs - 1.05633134620746e-20) - 3.11506369039915e-14) - 2.30719916990074e-11) - 1.07493164710329e-9) + fs*(fs*(fs*(fs*(3.73292075290073e-29*fs + 1.01643277726662e-20) + 2.91602352831988e-14) + 2.29636966370042e-11) + 1.07449105454163e-9)) + fs*(fs*(fs*(3.98985774247549e-22*fs + 1.99042653510896e-15) + 1.83615604104971e-13) + 5.31230624730483e-11) + 2.44402781742033e-9;\n\n    a1 = Fuzz*(Fuzz*fs*(fs*(fs*(fs*(1.86646037645036e-28*fs + 3.16899403862238e-20) + 3.11506369039915e-14) - 2.30719916990074e-11) - 3.22479494130986e-9) + fs*(fs*(fs*(fs*(-1.86646037645036e-28*fs - 3.04929833179984e-20) - 2.91602352831988e-14) + 2.29636966370042e-11) + 3.22347316362488e-9)) + fs*(fs*(fs*(-1.19695732274265e-21*fs - 1.99042653510896e-15) + 1.83615604104971e-13) + 1.59369187419145e-10) + 1.22201390871017e-8;\n\n    a2 = Fuzz*(Fuzz*fs*(fs*(fs*(fs*(-3.73292075290073e-28*fs - 2.11266269241492e-20) + 6.2301273807983e-14) + 4.61439833980148e-11) - 2.14986329420657e-9) + fs*(fs*(fs*(fs*(3.73292075290073e-28*fs + 2.03286555453323e-20) - 5.83204705663976e-14) - 4.59273932740084e-11) + 2.14898210908325e-9)) + fs*(fs*(fs*(7.97971548495099e-22*fs - 3.98085307021793e-15) - 3.67231208209942e-13) + 1.06246124946097e-10) + 2.44402781742033e-8;\n\n    a3 = Fuzz*(Fuzz*fs*(fs*(fs*(fs*(3.73292075290073e-28*fs - 2.11266269241492e-20) - 6.2301273807983e-14) + 4.61439833980148e-11) + 2.14986329420657e-9) + fs*(fs*(fs*(fs*(-3.73292075290073e-28*fs + 2.03286555453323e-20) + 5.83204705663976e-14) - 4.59273932740084e-11) - 2.14898210908325e-9)) + fs*(fs*(fs*(7.97971548495099e-22*fs + 3.98085307021793e-15) - 3.67231208209942e-13) - 1.06246124946097e-10) + 2.44402781742033e-8;\n\n    a4 = Fuzz*(Fuzz*fs*(fs*(fs*(fs*(-1.86646037645036e-28*fs + 3.16899403862238e-20) - 3.11506369039915e-14) - 2.30719916990074e-11) + 3.22479494130986e-9) + fs*(fs*(fs*(fs*(1.86646037645036e-28*fs - 3.04929833179984e-20) + 2.91602352831988e-14) + 2.29636966370042e-11) - 3.22347316362488e-9)) + fs*(fs*(fs*(-1.19695732274265e-21*fs + 1.99042653510896e-15) + 1.83615604104971e-13) - 1.59369187419145e-10) + 1.22201390871017e-8;\n\n    a5 = Fuzz*(Fuzz*fs*(fs*(fs*(fs*(3.73292075290073e-29*fs - 1.05633134620746e-20) + 3.11506369039915e-14) - 2.30719916990074e-11) + 1.07493164710329e-9) + fs*(fs*(fs*(fs*(-3.73292075290073e-29*fs + 1.01643277726662e-20) - 2.91602352831988e-14) + 2.29636966370042e-11) - 1.07449105454163e-9)) + fs*(fs*(fs*(3.98985774247549e-22*fs - 1.99042653510896e-15) + 1.83615604104971e-13) - 5.31230624730483e-11) + 2.44402781742033e-9;\n};"
 },
 {
  "id": "gx-fuzzfacerm",
  "name": "Fuzz Face (Roger Mayer)",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Roger Mayer's Fuzz Face variant; smoother, more refined fuzz with Fuzz and Level.",
  "description": "DK circuit simulation from the Roger Mayer Fuzz Face schematic: pot-dependent state-space filters followed by two transistor-stage tables. A smoother, more polished take on the Fuzz Face circuit.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Fuzz",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fuzz_Face_Mayer/Fuzz"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fuzz_Face_Mayer/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/fuzzfacerm.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n/// generated automatically\n// DO NOT MODIFY!\ndeclare id \"fuzzfacerm\";\ndeclare name \"Fuzz Face Mayer\";\ndeclare category \"Fuzz\";\ndeclare shortname \"FF Mayer\";\ndeclare description \"Roger Mayer Fuzz Face simulation\";\ndeclare insert_p \"tranyclipper3\";\n\nimport(\"filter.lib\");\nimport(\"trany.lib\");\n\nprocess = iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0))  with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(SR);\n    pre = _;\n    //clip = tranystage(TB_KT88_68k,86.0,2700.0,5.562895) : tranystage(TB_KT88_68k,86.0,2700.0,5.562895) ;\n  \n        Fuzz = vslider(\"Fuzz[name:Fuzz]\", 0.5, 0, 1, 0.01) : Inverted(1)  : smooth(s);\n    \n        Level = vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : LogPot(3) : Inverted(1) : smooth(s);\n    \n    b0 = Fuzz*(Fuzz*(4.47934267089816e-14*Level*pow(fs,3) - 4.57075782744711e-14*pow(fs,3)) + 2.1870008532593e-12*Level*pow(fs,3) - 2.23163352373398e-12*pow(fs,3)) + Level*pow(fs,2)*(-2.23179427996828e-12*fs - 2.84573463334658e-11) + pow(fs,2)*(2.27734110200845e-12*fs + 2.90381085035365e-11);\n\n    b1 = Fuzz*(Fuzz*(-1.34380280126945e-13*Level*pow(fs,3) + 1.37122734823413e-13*pow(fs,3)) - 6.5610025597779e-12*Level*pow(fs,3) + 6.69490057120194e-12*pow(fs,3)) + Level*pow(fs,2)*(6.69538283990485e-12*fs + 2.84573463334658e-11) + pow(fs,2)*(-6.83202330602535e-12*fs - 2.90381085035365e-11);\n\n    b2 = Fuzz*(Fuzz*(1.34380280126945e-13*Level*pow(fs,3) - 1.37122734823413e-13*pow(fs,3)) + 6.5610025597779e-12*Level*pow(fs,3) - 6.69490057120194e-12*pow(fs,3)) + Level*pow(fs,2)*(-6.69538283990485e-12*fs + 2.84573463334658e-11) + pow(fs,2)*(6.83202330602535e-12*fs - 2.90381085035365e-11);\n\n    b3 = Fuzz*(Fuzz*(-4.47934267089816e-14*Level*pow(fs,3) + 4.57075782744711e-14*pow(fs,3)) - 2.1870008532593e-12*Level*pow(fs,3) + 2.23163352373398e-12*pow(fs,3)) + Level*pow(fs,2)*(2.23179427996828e-12*fs - 2.84573463334658e-11) + pow(fs,2)*(-2.27734110200845e-12*fs + 2.90381085035365e-11);\n\n    a0 = Fuzz*(Fuzz*(Level*(Level*fs*(fs*(-6.18674104772942e-29*fs - 4.00204457374009e-26) - 2.83832448080453e-29) + fs*(fs*(-1.26259937209307e-31*fs - 2.15993317197785e-28) - 8.68874841067831e-26)) + fs*(fs*(-3.22405119745267e-14*fs - 2.08898268350887e-11) - 2.21793415696022e-11)) + Level*(Level*fs*(fs*(5.85504578964162e-29*fs + 4.00083755606776e-26) + 2.83746860731297e-29) + fs*(fs*(1.19490650740761e-31*fs + 2.08767320417856e-28) + 8.68612838978577e-26)) + fs*(fs*(3.05119726906337e-14*fs + 2.08816997599123e-11) + 2.21726535708769e-11)) + Level*(Level*(fs*(fs*(3.31695258087803e-30*fs + 8.26874714950455e-28) + 5.00406457485288e-25) + 3.54897544287011e-28) + fs*(fs*(6.76928646854567e-33*fs + 8.88886207590151e-30) + 2.81644163364677e-27) + 1.08642105394636e-24) + fs*(fs*(1.72853928389298e-15*fs + 4.32740215906676e-13) + 2.6123111187704e-10) + 2.77325369604093e-10;\n\n    a1 = Fuzz*(Fuzz*(Level*(Level*fs*(fs*(1.85602231431883e-28*fs + 4.00204457374009e-26) - 2.83832448080453e-29) + fs*(fs*(3.78779811627921e-31*fs + 2.15993317197785e-28) - 8.68874841067831e-26)) + fs*(fs*(9.67215359235801e-14*fs + 2.08898268350887e-11) - 2.21793415696022e-11)) + Level*(Level*fs*(fs*(-1.75651373689249e-28*fs - 4.00083755606776e-26) + 2.83746860731297e-29) + fs*(fs*(-3.58471952222284e-31*fs - 2.08767320417856e-28) + 8.68612838978577e-26)) + fs*(fs*(-9.15359180719011e-14*fs - 2.08816997599123e-11) + 2.21726535708769e-11)) + Level*(Level*(fs*(fs*(-9.95085774263408e-30*fs - 8.26874714950455e-28) + 5.00406457485288e-25) + 1.06469263286103e-27) + fs*(fs*(-2.0307859405637e-32*fs - 8.88886207590151e-30) + 2.81644163364677e-27) + 3.25926316183907e-24) + fs*(fs*(-5.18561785167894e-15*fs - 4.32740215906676e-13) + 2.6123111187704e-10) + 8.3197610881228e-10;\n\n    a2 = Fuzz*(Fuzz*(Level*(Level*fs*(fs*(-1.85602231431883e-28*fs + 4.00204457374009e-26) + 2.83832448080453e-29) + fs*(fs*(-3.78779811627921e-31*fs + 2.15993317197785e-28) + 8.68874841067831e-26)) + fs*(fs*(-9.67215359235801e-14*fs + 2.08898268350887e-11) + 2.21793415696022e-11)) + Level*(Level*fs*(fs*(1.75651373689249e-28*fs - 4.00083755606776e-26) - 2.83746860731297e-29) + fs*(fs*(3.58471952222284e-31*fs - 2.08767320417856e-28) - 8.68612838978577e-26)) + fs*(fs*(9.15359180719011e-14*fs - 2.08816997599123e-11) - 2.21726535708769e-11)) + Level*(Level*(fs*(fs*(9.95085774263408e-30*fs - 8.26874714950455e-28) - 5.00406457485288e-25) + 1.06469263286103e-27) + fs*(fs*(2.0307859405637e-32*fs - 8.88886207590151e-30) - 2.81644163364677e-27) + 3.25926316183907e-24) + fs*(fs*(5.18561785167894e-15*fs - 4.32740215906676e-13) - 2.6123111187704e-10) + 8.3197610881228e-10;\n\n    a3 = Fuzz*(Fuzz*(Level*(Level*fs*(fs*(6.18674104772942e-29*fs - 4.00204457374009e-26) + 2.83832448080453e-29) + fs*(fs*(1.26259937209307e-31*fs - 2.15993317197785e-28) + 8.68874841067831e-26)) + fs*(fs*(3.22405119745267e-14*fs - 2.08898268350887e-11) + 2.21793415696022e-11)) + Level*(Level*fs*(fs*(-5.85504578964162e-29*fs + 4.00083755606776e-26) - 2.83746860731297e-29) + fs*(fs*(-1.19490650740761e-31*fs + 2.08767320417856e-28) - 8.68612838978577e-26)) + fs*(fs*(-3.05119726906337e-14*fs + 2.08816997599123e-11) - 2.21726535708769e-11)) + Level*(Level*(fs*(fs*(-3.31695258087803e-30*fs + 8.26874714950455e-28) - 5.00406457485288e-25) + 3.54897544287011e-28) + fs*(fs*(-6.76928646854567e-33*fs + 8.88886207590151e-30) - 2.81644163364677e-27) + 1.08642105394636e-24) + fs*(fs*(-1.72853928389298e-15*fs + 4.32740215906676e-13) - 2.6123111187704e-10) + 2.77325369604093e-10;\n};"
 },
 {
  "id": "gx-drive",
  "name": "Fuzzy Tube Drive",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Fuzzy-tube polynomial waveshaper with a hotter curve than the Tube stage; gritty drive.",
  "description": "One pass through guitarix's fuzzy_tube polynomial waveshaper with a more aggressive fixed curve than the Tube stage; Drive sets the amount. A simple, gritty drive rather than a circuit model.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "value",
    "min": 1,
    "max": 10,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/gx_drive/value"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/drive.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nfuzzy = vslider(\"value[name:drive]\", 1, 1, 10, 1);\nprocess = fuzzy_tube(a,b,c,fuzzy)\nwith {\n  a = 4;\n  b = 4;\n  c = 0.125;\n};"
 },
 {
  "id": "gx-hornet",
  "name": "Hornet",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Electro-Harmonix Hornet-style fuzz with Volume, Sustain and Fuzz.",
  "description": "DK circuit simulation from the Hornet schematic: pot-dependent filters with clipping stages. A compact, sustaining fuzz with separate Sustain and Fuzz controls.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Hornet/Volume"
   },
   {
    "label": "Sustain",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Hornet/Sustain"
   },
   {
    "label": "Fuzz",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Hornet/Fuzz"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/hornet.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"hornet\";\ndeclare name \"Hornet\";\ndeclare category \"Distortion\";\ndeclare description \"Hornet simulation\";\n\nimport(\"stdfaust.lib\");\n\nprocess =  fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0)) : clip   with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    a = 1.2715 - Fuzz ;\n    clip(x) = (0.4 * (min(0.7514,max(-0.4514,x))));\n\n        Volume = vslider(\"Volume[name:Volume]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Sustain = vslider(\"Sustain[name:Sustain]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Fuzz = vslider(\"Fuzz[name:Fuzz]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Fuzz*(Fuzz*Volume*pow(fs,3)*(-3.36831187151837e-20*fs - 1.75582214579149e-16) + Volume*pow(fs,3)*(9.4649563589667e-21*fs + 4.93386022967413e-17)) + Sustain*(Fuzz*(Fuzz*Volume*pow(fs,3)*(2.89798007739403e-18*fs + 1.51064918927987e-14) + Volume*pow(fs,3)*(2.28655633153439e-18*fs + 1.19192830048069e-14)) + Volume*pow(fs,2)*(fs*(1.45891323583538e-19*fs + 7.40489463150802e-16) - 1.04296301457845e-13)) + Volume*pow(fs,2)*(fs*(2.4218162356217e-20*fs + 1.26859583357635e-16) + 3.21091305171869e-15);\n\n    b1 = Fuzz*(Fuzz*Volume*pow(fs,3)*(1.34732474860735e-19*fs + 3.51164429158298e-16) + Volume*pow(fs,3)*(-3.78598254358668e-20*fs - 9.86772045934826e-17)) + Sustain*(Fuzz*(Fuzz*Volume*pow(fs,3)*(-1.15919203095761e-17*fs - 3.02129837855973e-14) + Volume*pow(fs,3)*(-9.14622532613756e-18*fs - 2.38385660096139e-14)) + Volume*pow(fs,3)*(-5.83565294334152e-19*fs - 1.4809789263016e-15)) + Volume*pow(fs,3)*(-9.6872649424868e-20*fs - 2.53719166715271e-16);\n\n    b2 = Fuzz*(-2.02098712291102e-19*Fuzz*Volume*pow(fs,4) + 5.67897381538002e-20*Volume*pow(fs,4)) + Sustain*(Fuzz*(1.73878804643642e-17*Fuzz*Volume*pow(fs,4) + 1.37193379892063e-17*Volume*pow(fs,4)) + Volume*pow(fs,2)*(8.75347941501228e-19*pow(fs,2) + 2.08592602915691e-13)) + Volume*pow(fs,2)*(1.45308974137302e-19*pow(fs,2) - 6.42182610343738e-15);\n\n    b3 = Fuzz*(Fuzz*Volume*pow(fs,3)*(1.34732474860735e-19*fs - 3.51164429158298e-16) + Volume*pow(fs,3)*(-3.78598254358668e-20*fs + 9.86772045934826e-17)) + Sustain*(Fuzz*(Fuzz*Volume*pow(fs,3)*(-1.15919203095761e-17*fs + 3.02129837855973e-14) + Volume*pow(fs,3)*(-9.14622532613756e-18*fs + 2.38385660096139e-14)) + Volume*pow(fs,3)*(-5.83565294334152e-19*fs + 1.4809789263016e-15)) + Volume*pow(fs,3)*(-9.6872649424868e-20*fs + 2.53719166715271e-16);\n\n    b4 = Fuzz*(Fuzz*Volume*pow(fs,3)*(-3.36831187151837e-20*fs + 1.75582214579149e-16) + Volume*pow(fs,3)*(9.4649563589667e-21*fs - 4.93386022967413e-17)) + Sustain*(Fuzz*(Fuzz*Volume*pow(fs,3)*(2.89798007739403e-18*fs - 1.51064918927987e-14) + Volume*pow(fs,3)*(2.28655633153439e-18*fs - 1.19192830048069e-14)) + Volume*pow(fs,2)*(fs*(1.45891323583538e-19*fs - 7.40489463150802e-16) - 1.04296301457845e-13)) + Volume*pow(fs,2)*(fs*(2.4218162356217e-20*fs - 1.26859583357635e-16) + 3.21091305171869e-15);\n\n    a0 = Fuzz*(Fuzz*fs*(fs*(fs*(-2.57087433571955e-21*fs - 3.20282580029198e-16) - 1.59955479510613e-12) - 1.59265781983301e-11) + fs*(fs*(fs*(7.22415688337201e-22*fs + 1.15708148345401e-16) + 5.83730418035165e-13) + 5.81517816570128e-12)) + Sustain*(Fuzz*(Fuzz*fs*(fs*(fs*(-2.22731835703847e-20*fs - 1.15680872556631e-16) - 1.02110226030461e-14) - 8.86189120121937e-14) + fs*(fs*(fs*(2.63346198155234e-19*fs + 1.39560593212619e-15) + 1.23553821745518e-13) + 1.09557219057811e-12)) + fs*(fs*(fs*(2.00860283725342e-19*fs + 1.06638545237487e-15) + 1.10730441129884e-13) + 2.30413820563986e-12) + 1.30107041069324e-11) + fs*(fs*(fs*(1.84845864738235e-21*fs + 2.48814775695488e-16) + 1.25274019677064e-12) + 4.3094216014379e-11) + 3.05506357605318e-10;\n\n    a1 = Fuzz*(Fuzz*fs*(pow(fs,2)*(1.02834973428782e-20*fs + 6.40565160058397e-16) - 3.18531563966602e-11) + fs*(pow(fs,2)*(-2.8896627533488e-21*fs - 2.31416296690802e-16) + 1.16303563314026e-11)) + Sustain*(Fuzz*(Fuzz*fs*(pow(fs,2)*(8.9092734281539e-20*fs + 2.31361745113263e-16) - 1.77237824024387e-13) + fs*(pow(fs,2)*(-1.05338479262093e-18*fs - 2.79121186425238e-15) + 2.19114438115622e-12)) + fs*(pow(fs,2)*(-8.03441134901368e-19*fs - 2.13277090474974e-15) + 4.60827641127972e-12) + 5.20428164277295e-11) + fs*(pow(fs,2)*(-7.39383458952941e-21*fs - 4.97629551390976e-16) + 8.6188432028758e-11) + 1.22202543042127e-9;\n\n    a2 = Fuzz*(Fuzz*pow(fs,2)*(-1.54252460143173e-20*pow(fs,2) + 3.19910959021226e-12) + pow(fs,2)*(4.33449413002321e-21*pow(fs,2) - 1.16746083607033e-12)) + Sustain*(Fuzz*(Fuzz*pow(fs,2)*(-1.33639101422308e-19*pow(fs,2) + 2.04220452060922e-14) + pow(fs,2)*(1.5800771889314e-18*pow(fs,2) - 2.47107643491035e-13)) + pow(fs,2)*(1.20516170235205e-18*pow(fs,2) - 2.21460882259768e-13) + 7.80642246415943e-11) + pow(fs,2)*(1.10907518842941e-20*pow(fs,2) - 2.50548039354128e-12) + 1.83303814563191e-9;\n\n    a3 = Fuzz*(Fuzz*fs*(pow(fs,2)*(1.02834973428782e-20*fs - 6.40565160058397e-16) + 3.18531563966602e-11) + fs*(pow(fs,2)*(-2.8896627533488e-21*fs + 2.31416296690802e-16) - 1.16303563314026e-11)) + Sustain*(Fuzz*(Fuzz*fs*(pow(fs,2)*(8.9092734281539e-20*fs - 2.31361745113263e-16) + 1.77237824024387e-13) + fs*(pow(fs,2)*(-1.05338479262093e-18*fs + 2.79121186425238e-15) - 2.19114438115622e-12)) + fs*(pow(fs,2)*(-8.03441134901368e-19*fs + 2.13277090474974e-15) - 4.60827641127972e-12) + 5.20428164277295e-11) + fs*(pow(fs,2)*(-7.39383458952941e-21*fs + 4.97629551390976e-16) - 8.6188432028758e-11) + 1.22202543042127e-9;\n\n    a4 = Fuzz*(Fuzz*fs*(fs*(fs*(-2.57087433571955e-21*fs + 3.20282580029198e-16) - 1.59955479510613e-12) + 1.59265781983301e-11) + fs*(fs*(fs*(7.22415688337201e-22*fs - 1.15708148345401e-16) + 5.83730418035165e-13) - 5.81517816570128e-12)) + Sustain*(Fuzz*(Fuzz*fs*(fs*(fs*(-2.22731835703847e-20*fs + 1.15680872556631e-16) - 1.02110226030461e-14) + 8.86189120121937e-14) + fs*(fs*(fs*(2.63346198155234e-19*fs - 1.39560593212619e-15) + 1.23553821745518e-13) - 1.09557219057811e-12)) + fs*(fs*(fs*(2.00860283725342e-19*fs - 1.06638545237487e-15) + 1.10730441129884e-13) - 2.30413820563986e-12) + 1.30107041069324e-11) + fs*(fs*(fs*(1.84845864738235e-21*fs - 2.48814775695488e-16) + 1.25274019677064e-12) - 4.3094216014379e-11) + 3.05506357605318e-10;\n};"
 },
 {
  "id": "gx-ts9sim",
  "name": "Ibanez TS9 Tube Screamer",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Ibanez TS-9 Tube Screamer: mid-hump op-amp overdrive with Drive, Tone, Level.",
  "description": "Circuit model of the Ibanez TS-9 from the schematic (Kenéz analysis): the clipping stage's bilinear filter from the real R/C values with a Newton-solved diode nonlinearity via a C foreign function, then the tone low-pass and level, at 96 kHz. The classic smooth, mid-forward overdrive.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tube_Screamer/drive"
   },
   {
    "label": "tone",
    "min": 100,
    "max": 1000,
    "default": 400,
    "step": 1.03,
    "unit": "",
    "path": "/Tube_Screamer/tone"
   },
   {
    "label": "level",
    "min": -20,
    "max": 4,
    "default": -16,
    "step": 0.1,
    "unit": "",
    "path": "/Tube_Screamer/level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/ts9sim.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \t\t\"ts9sim\";\ndeclare name            \"Tube Screamer\";\ndeclare category        \"Distortion\";\ndeclare samplerate \"96000\";\n\nimport(\"stdfaust.lib\");\n\ngxt = library(\"gx_tables.lib\");\n\n/*\n** based on a circuit diagram of the Ibanez TS-9 and\n** a mathematical analysis published by Tamás Kenéz\n*/\n\nsmoothi(c) = *(1-c) : +~*(c);\n\nprocess = ts9 : lowpass : *(gain) with {\n   // ma.SR = component(\"math.lib\").ma.SR;\n    R1 = 4700;\n    R2 = 51000 + 500000 * hslider(\"drive[name:Drive]\", 0.5, 0, 1, 0.01);\n    C = 0.047 * 1e-6;\n    a1 = (R1 + R2) * C * 2 * ma.SR;\n    a2 = R1 * C * 2 * ma.SR;\n    B0 = (1 + a1) / (1 + a2);\n    B1 = (1 - a1) / (1 + a2);\n    A1 = (1 - a2) / (1 + a2);\n    X2 = fi.tf1(B0, B1, A1);\nts9nonlin = gxt.ts9nonlin;\n    ts9 = _ <: _ - (X2-_ : ts9nonlin) :> _;\n    fc = hslider(\"tone[log][name:Tone]\", 400, 100, 1000, 1.03);\n    lowpass = fi.lowpass(1,fc);\n    gain = hslider(\"level[name:Level]\", -16, -20, 4, 0.1) : ba.db2linear : smoothi(0.999);\n};"
 },
 {
  "id": "kpp-bluedream",
  "name": "KPP Blue Dream",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "KPP",
  "license": "GPL-3.0-or-later",
  "shortDesc": "Booster/overdrive with voice knob (booster left, tube-screamer right), push-pull tube waveshaper and 3-band EQ",
  "description": "Booster/overdrive with voice knob (booster left, tube-screamer right), push-pull tube waveshaper and 3-band EQ",
  "author": "Oleg Kapitonov",
  "flags": "",
  "params": [
   {
    "label": "Drive",
    "min": 0,
    "max": 100,
    "default": 63,
    "step": 0.01,
    "unit": "",
    "path": "/KPP_Blue_Dream/Drive"
   },
   {
    "label": "Voice",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.001,
    "unit": "",
    "path": "/KPP_Blue_Dream/Voice"
   },
   {
    "label": "Bass",
    "min": -15,
    "max": 15,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Blue_Dream/Bass"
   },
   {
    "label": "Middle",
    "min": -15,
    "max": 15,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Blue_Dream/Middle"
   },
   {
    "label": "Treble",
    "min": -15,
    "max": 15,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Blue_Dream/Treble"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.8,
    "step": 0.001,
    "unit": "",
    "path": "/KPP_Blue_Dream/Volume"
   }
  ],
  "faustCode": "declare name \"KPP Blue Dream\";\ndeclare description \"Booster/overdrive with voice knob (booster left, tube-screamer right), push-pull tube waveshaper and 3-band EQ\";\ndeclare author \"Oleg Kapitonov\";\ndeclare license \"GPL-3.0-or-later\";\ndeclare source \"olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_bluedream/kpp_bluedream.dsp\";\ndeclare category \"guitar\";\ndeclare family \"dirt\";\nimport(\"stdfaust.lib\");\n\ndrive  = hslider(\"[0] Drive\", 63, 0, 100, 0.01) : si.smoo;\nvoice  = hslider(\"[1] Voice\", 0.5, 0, 1, 0.001) : si.smoo;\nbass   = hslider(\"[2] Bass[unit:dB]\", 0, -15, 15, 0.1) : si.smoo;\nmiddle = hslider(\"[3] Middle[unit:dB]\", 0, -15, 15, 0.1) : si.smoo;\ntreble = hslider(\"[4] Treble[unit:dB]\", 0, -15, 15, 0.1) : si.smoo;\nvolume = hslider(\"[5] Volume\", 0.8, 0, 1, 0.001) : si.smoo;\n\nclamp = min(2.0) : max(-2.0);\nbias = 0.2; Upor = 0.2; Kreg = 1.0;\ntube(Kreg,Upor,bias,cut) = main : +(bias) : max(cut) with {\n    Ks(x) = 1/(max((x-Upor)*(Kreg),0)+1);\n    Ksplus(x) = Upor - x*Upor;\n    main(Uin) = (Uin * Ks(Uin) + Ksplus(Ks(Uin)));\n};\npre_filter = _ <: fi.highpass(1, 720) * min((1 - voice + 0.75 * drive / 100), 1), *(max((voice - 0.75 * drive / 100), 0)) : +;\npost_filter = _ <: fi.lowpass(1, 720) * min((1 - voice + 0.75 * drive / 100), 1), *(max((voice - 0.75 * drive / 100), 0)) : +;\nstage_stomp = pre_filter : fi.lowpass(1,9000) : _ <: _,*(-1.0) : tube(Kreg,Upor,bias,0), tube(Kreg,Upor,bias,0) : - :\n    *(ba.db2linear(volume * 50.0 * (1 - voice * 0.25)) / 100.0) :\n    fi.peak_eq(bass, 70, 200) : fi.peak_eq(middle, 500, 700) : fi.peak_eq(treble, 10000, 18000) : clamp : post_filter;\nprocess = fi.dcblocker : clamp : *(ba.db2linear(drive * 0.4 * (1 - voice * 0.5))-1) : stage_stomp : fi.dcblocker;"
 },
 {
  "id": "kpp-distruction",
  "name": "KPP Distruction",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "KPP",
  "license": "GPL-3.0-or-later",
  "shortDesc": "Hi-gain distortion: bandpassed pre-filter, push-pull tube clipper, 3-band EQ, voice-controlled presence",
  "description": "Hi-gain distortion: bandpassed pre-filter, push-pull tube clipper, 3-band EQ, voice-controlled presence",
  "author": "Oleg Kapitonov",
  "flags": "",
  "params": [
   {
    "label": "Drive",
    "min": 0,
    "max": 100,
    "default": 63,
    "step": 0.01,
    "unit": "",
    "path": "/KPP_Distruction/Drive"
   },
   {
    "label": "Voice",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.001,
    "unit": "",
    "path": "/KPP_Distruction/Voice"
   },
   {
    "label": "Bass",
    "min": -15,
    "max": 15,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Distruction/Bass"
   },
   {
    "label": "Middle",
    "min": -15,
    "max": 15,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Distruction/Middle"
   },
   {
    "label": "Treble",
    "min": -15,
    "max": 15,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Distruction/Treble"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.8,
    "step": 0.001,
    "unit": "",
    "path": "/KPP_Distruction/Volume"
   },
   {
    "label": "Level",
    "min": -12,
    "max": 24,
    "default": 12,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Distruction/Level"
   }
  ],
  "faustCode": "declare name \"KPP Distruction\";\ndeclare description \"Hi-gain distortion: bandpassed pre-filter, push-pull tube clipper, 3-band EQ, voice-controlled presence\";\ndeclare author \"Oleg Kapitonov\";\ndeclare license \"GPL-3.0-or-later\";\ndeclare source \"olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_distruction/kpp_distruction.dsp\";\ndeclare category \"guitar\";\ndeclare family \"dirt\";\nimport(\"stdfaust.lib\");\n\ndrive  = hslider(\"[0] Drive\", 63, 0, 100, 0.01) : si.smoo;\nvoice  = hslider(\"[1] Voice\", 0.5, 0, 1, 0.001) : si.smoo;\nbass   = hslider(\"[2] Bass[unit:dB]\", 0, -15, 15, 0.1) : si.smoo;\nmiddle = hslider(\"[3] Middle[unit:dB]\", 0, -15, 15, 0.1) : si.smoo;\ntreble = hslider(\"[4] Treble[unit:dB]\", 0, -15, 15, 0.1) : si.smoo;\nvolume = hslider(\"[5] Volume\", 0.8, 0, 1, 0.001) : si.smoo;\nlevel  = hslider(\"[6] Level[unit:dB]\", 12, -12, 24, 0.1) : ba.db2linear : si.smoo;\n\nclamp = min(2.0) : max(-2.0);\nUpor = 0.2; bias = 0.2; Kreg = 1.0;\npre_filter = fi.lowpass(1, 3000) <: fi.highpass(1, 3300);\npost_filter = fi.lowpass(1, 3000) : fi.highpass(1,30) : fi.peak_eq(-6, 550, 500) : fi.high_shelf(-20 + voice*20, 550);\ntube(Kreg,Upor,bias,cut) = main : +(bias) : max(cut) with {\n    Ks(x) = 1/(max((x-Upor)*(Kreg),0)+1);\n    Ksplus(x) = Upor - x*Upor;\n    main(Uin) = (Uin * Ks(Uin) + Ksplus(Ks(Uin)));\n};\nstage_stomp = pre_filter : _ <: _,*(-1.0) : tube(Kreg,Upor,bias,0), tube(Kreg,Upor,bias,0) : - :\n    fi.peak_eq(bass, 100, 200) : fi.peak_eq(middle, 700, 700) : fi.peak_eq(treble, 3300, 2000) : post_filter : clamp;\nprocess = fi.dcblocker : clamp : *(ba.db2linear(drive * 70.0 / 100.0)-1) : *(5) : stage_stomp : *((ba.db2linear(volume * 25.0)-1) / 100.0) : fi.dcblocker : *(level);"
 },
 {
  "id": "kpp-fuzz",
  "name": "KPP Fuzz",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "KPP",
  "license": "GPL-3.0-or-later",
  "shortDesc": "Vintage fuzz: low-impedance pre-filter, two asymmetric class-A transistor-style cascades with dynamic bias shift, high-shelf tone",
  "description": "Vintage fuzz: low-impedance pre-filter, two asymmetric class-A transistor-style cascades with dynamic bias shift, high-shelf tone",
  "author": "Oleg Kapitonov",
  "flags": "",
  "params": [
   {
    "label": "Fuzz",
    "min": 0,
    "max": 100,
    "default": 50,
    "step": 0.01,
    "unit": "",
    "path": "/KPP_Fuzz/Fuzz"
   },
   {
    "label": "Tone",
    "min": -15,
    "max": 0,
    "default": -7.5,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Fuzz/Tone"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.001,
    "unit": "",
    "path": "/KPP_Fuzz/Volume"
   }
  ],
  "faustCode": "declare name \"KPP Fuzz\";\ndeclare description \"Vintage fuzz: low-impedance pre-filter, two asymmetric class-A transistor-style cascades with dynamic bias shift, high-shelf tone\";\ndeclare author \"Oleg Kapitonov\";\ndeclare license \"GPL-3.0-or-later\";\ndeclare source \"olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_fuzz/kpp_fuzz.dsp\";\ndeclare category \"guitar\";\ndeclare family \"dirt\";\nimport(\"stdfaust.lib\");\n\nfuzz   = hslider(\"[0] Fuzz\", 50, 0, 100, 0.01) : si.smoo;\ntone   = hslider(\"[1] Tone[unit:dB]\", -7.5, -15, 0, 0.1) : si.smoo;\nvolume = hslider(\"[2] Volume\", 0.5, 0, 1, 0.001) : si.smoo;\n\npre_filter = fi.dcblocker : fi.lowpass(1, 2000.0);\nbiaser(Uin) = Uout letrec {\n  'Ulimited = Uin : max(-50.0 + Ubias) : -(Ubias);\n  'Ubias = min(Ubias + 100.0*Ulimited/ma.SR - 0.0*Ubias/ma.SR, 2000.0);\n  'Uout = Uin - Ubias;\n};\ndistortion = *(100.0) : *(ba.db2linear(fuzz/5.0) - 1.0) : biaser : *(ba.db2linear(fuzz/100.0*6.0)) : max(-50.0) : min(100.0) : fi.dcblocker;\nfilter = fi.high_shelf(tone + 12.5, 720.0);\nprocess = pre_filter : filter : distortion : *(ba.db2linear(volume * 25.0) / 100.0) : /(20.0);"
 },
 {
  "id": "gx-lpbboost",
  "name": "LPB-1 Linear Power Booster",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Electro-Harmonix LPB-1 one-transistor clean boost with a single Boost knob.",
  "description": "DK circuit simulation from the LPB-1 schematic as a pot-dependent linear filter. A near-transparent single-transistor boost for pushing an amp harder.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Boost",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/LPB-1_Booster/Boost"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/lpbboost.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"lpbboost\";\ndeclare name \"LPB-1 Booster\";\ndeclare category \"Tone Control\";\ndeclare shortname \"LPB-1 Boost\";\ndeclare description \"LPB-1 Linear Power Booster \";\n\nimport(\"stdfaust.lib\");\n\nprocess = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n    \n        Boost = vslider(\"Boost[name:Boost]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = -8.68034563926398e-9*Boost*pow(fs,2) - 8.68034563926398e-11*pow(fs,2);\n\n    b1 = 1.7360691278528e-8*Boost*pow(fs,2) + 1.7360691278528e-10*pow(fs,2);\n\n    b2 = -8.68034563926398e-9*Boost*pow(fs,2) - 8.68034563926398e-11*pow(fs,2);\n\n    a0 = fs*(4.33054407650898e-10*fs + 4.66962506103765e-8) + 1.22474303201741e-6;\n\n    a1 = -8.66108815301797e-10*pow(fs,2) + 2.44948606403482e-6;\n\n    a2 = fs*(4.33054407650898e-10*fs - 4.66962506103765e-8) + 1.22474303201741e-6;\n};"
 },
 {
  "id": "gx-muff",
  "name": "Muff (transistor-stage Big Muff)",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Big Muff-style fuzz built from three transistor-stage tables with a Tone control.",
  "description": "DK circuit simulation from the Muff schematic: pot-dependent filters followed by three transistor-stage tables and the Muff tone control. A variant Big Muff model that uses the transistor library rather than diode clip tables.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Muff/Tone"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/muff.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"muff\";\ndeclare name \"Muff\";\ndeclare category \"Fuzz\";\ndeclare shortname \"Muff\";\ndeclare description \"Muff\";\ndeclare insert_p \"tranyclipper\";\ndeclare volume_p \"Volume\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\nprocess = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0,b6/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0,a6/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    //clip = tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) ;\n\n        Tone = vslider(\"Tone[name:Tone]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        //Level = vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01): *(0.8) : Inverted(0) : si.smooth(s);\n    \n    b0 = Tone*pow(fs,3)*(fs*(fs*(-1.29955117406144e-31*fs + 3.73173380397863e-25) + 1.11415567049164e-24) - 3.19936025718332e-18) + (Tone*pow(fs,3)*(fs*(fs*(-5.90705079118838e-30*fs + 1.6962426381721e-23) + 5.06434395678016e-23) - 1.45425466235606e-16) + pow(fs,3)*(fs*(-1.38925083422393e-26*fs + 3.98287967295002e-20) + 1.84690342119219e-16)) + pow(fs,3)*(fs*(-3.05635183529265e-28*fs + 8.76233528049005e-22) + 4.06318752662282e-18);\n\n    b1 = Tone*pow(fs,4)*(fs*(7.79730704436866e-31*fs - 1.49269352159145e-24) - 2.22831134098327e-24) + (Tone*pow(fs,4)*(fs*(3.54423047471303e-29*fs - 6.78497055268842e-23) - 1.01286879135603e-22) + pow(fs,4)*(5.55700333689573e-26*fs - 7.96575934590005e-20)) + pow(fs,4)*(1.22254073411706e-27*fs - 1.75246705609801e-21);\n\n    b2 = Tone*pow(fs,3)*(fs*(fs*(-1.94932676109216e-30*fs + 1.86586690198932e-24) - 1.11415567049164e-24) + 9.59808077154997e-18) + (Tone*pow(fs,3)*(fs*(fs*(-8.86057618678257e-29*fs + 8.48121319086052e-23) - 5.06434395678016e-23) + 4.36276398706817e-16) + pow(fs,3)*(fs*(-6.94625417111967e-26*fs - 3.98287967295002e-20) - 5.54071026357658e-16)) + pow(fs,3)*(fs*(-1.52817591764633e-27*fs - 8.76233528049005e-22) - 1.21895625798685e-17);\n\n    b3 = Tone*pow(fs,4)*(2.59910234812289e-30*pow(fs,2) + 4.45662268196654e-24) + (Tone*pow(fs,4)*(1.18141015823768e-28*pow(fs,2) + 2.02573758271206e-22) + 1.59315186918001e-19*pow(fs,4)) + 3.50493411219602e-21*pow(fs,4);\n\n    b4 = Tone*pow(fs,3)*(fs*(fs*(-1.94932676109216e-30*fs - 1.86586690198932e-24) - 1.11415567049164e-24) - 9.59808077154997e-18) + (Tone*pow(fs,3)*(fs*(fs*(-8.86057618678257e-29*fs - 8.48121319086052e-23) - 5.06434395678016e-23) - 4.36276398706817e-16) + pow(fs,3)*(fs*(6.94625417111967e-26*fs - 3.98287967295002e-20) + 5.54071026357658e-16)) + pow(fs,3)*(fs*(1.52817591764633e-27*fs - 8.76233528049005e-22) + 1.21895625798685e-17);\n\n    b5 = Tone*pow(fs,4)*(fs*(7.79730704436866e-31*fs + 1.49269352159145e-24) - 2.22831134098327e-24) + (Tone*pow(fs,4)*(fs*(3.54423047471303e-29*fs + 6.78497055268842e-23) - 1.01286879135603e-22) + pow(fs,4)*(-5.55700333689573e-26*fs - 7.96575934590005e-20)) + pow(fs,4)*(-1.22254073411706e-27*fs - 1.75246705609801e-21);\n\n    b6 = Tone*pow(fs,3)*(fs*(fs*(-1.29955117406144e-31*fs - 3.73173380397863e-25) + 1.11415567049164e-24) + 3.19936025718332e-18) + (Tone*pow(fs,3)*(fs*(fs*(-5.90705079118838e-30*fs - 1.6962426381721e-23) + 5.06434395678016e-23) + 1.45425466235606e-16) + pow(fs,3)*(fs*(1.38925083422393e-26*fs + 3.98287967295002e-20) - 1.84690342119219e-16)) + pow(fs,3)*(fs*(3.05635183529265e-28*fs + 8.76233528049005e-22) - 4.06318752662282e-18);\n\n    a0 = Tone*(Tone*fs*(fs*(fs*(fs*(fs*(-5.75452574944698e-29*fs - 7.27469124190795e-25) - 2.36761929650589e-21) - 2.15665382234029e-18) - 5.3389212423117e-16) - 3.40686364113531e-15) + fs*(fs*(fs*(fs*(fs*(5.77317651704237e-29*fs + 7.91492198040202e-25) + 2.5773097315087e-21) + 2.02385759012812e-18) + 5.21709009014916e-16) + 3.33278467477534e-15)) + fs*(fs*(fs*(fs*(fs*(4.64196013276193e-29*fs + 7.1140905248404e-25) + 2.87245155338884e-21) + 3.60543982135142e-18) + 8.93675308928682e-16) + 1.16723639524299e-14) + 3.91224189243262e-14;\n\n    a1 = Tone*(Tone*fs*(fs*(pow(fs,2)*(fs*(3.45271544966819e-28*fs + 2.90987649676318e-24) + 4.73523859301178e-21) - 1.06778424846234e-15) - 1.36274545645413e-14) + fs*(fs*(pow(fs,2)*(fs*(-3.46390591022542e-28*fs - 3.16596879216081e-24) - 5.15461946301739e-21) + 1.04341801802983e-15) + 1.33311386991013e-14)) + fs*(fs*(pow(fs,2)*(fs*(-2.78517607965716e-28*fs - 2.84563620993616e-24) - 5.74490310677768e-21) + 1.78735061785736e-15) + 4.66894558097195e-14) + 2.34734513545957e-13;\n\n    a2 = Tone*(Tone*fs*(fs*(fs*(fs*(fs*(-8.63178862417047e-28*fs - 3.63734562095397e-24) + 2.36761929650589e-21) + 6.46996146702087e-18) + 5.3389212423117e-16) - 1.70343182056766e-14) + fs*(fs*(fs*(fs*(fs*(8.65976477556356e-28*fs + 3.95746099020101e-24) - 2.5773097315087e-21) - 6.07157277038437e-18) - 5.21709009014916e-16) + 1.66639233738767e-14)) + fs*(fs*(fs*(fs*(fs*(6.96294019914289e-28*fs + 3.5570452624202e-24) - 2.87245155338884e-21) - 1.08163194640543e-17) - 8.93675308928682e-16) + 5.83618197621494e-14) + 5.86836283864892e-13;\n\n    a3 = Tone*(Tone*pow(fs,2)*(pow(fs,2)*(1.1509051498894e-27*pow(fs,2) - 9.47047718602356e-21) + 2.13556849692468e-15) + pow(fs,2)*(pow(fs,2)*(-1.15463530340847e-27*pow(fs,2) + 1.03092389260348e-20) - 2.08683603605967e-15)) + pow(fs,2)*(pow(fs,2)*(-9.28392026552386e-28*pow(fs,2) + 1.14898062135554e-20) - 3.57470123571473e-15) + 7.82448378486523e-13;\n\n    a4 = Tone*(Tone*fs*(fs*(fs*(fs*(fs*(-8.63178862417047e-28*fs + 3.63734562095397e-24) + 2.36761929650589e-21) - 6.46996146702087e-18) + 5.3389212423117e-16) + 1.70343182056766e-14) + fs*(fs*(fs*(fs*(fs*(8.65976477556356e-28*fs - 3.95746099020101e-24) - 2.5773097315087e-21) + 6.07157277038437e-18) - 5.21709009014916e-16) - 1.66639233738767e-14)) + fs*(fs*(fs*(fs*(fs*(6.96294019914289e-28*fs - 3.5570452624202e-24) - 2.87245155338884e-21) + 1.08163194640543e-17) - 8.93675308928682e-16) - 5.83618197621494e-14) + 5.86836283864892e-13;\n\n    a5 = Tone*(Tone*fs*(fs*(pow(fs,2)*(fs*(3.45271544966819e-28*fs - 2.90987649676318e-24) + 4.73523859301178e-21) - 1.06778424846234e-15) + 1.36274545645413e-14) + fs*(fs*(pow(fs,2)*(fs*(-3.46390591022542e-28*fs + 3.16596879216081e-24) - 5.15461946301739e-21) + 1.04341801802983e-15) - 1.33311386991013e-14)) + fs*(fs*(pow(fs,2)*(fs*(-2.78517607965716e-28*fs + 2.84563620993616e-24) - 5.74490310677768e-21) + 1.78735061785736e-15) - 4.66894558097195e-14) + 2.34734513545957e-13;\n\n    a6 = Tone*(Tone*fs*(fs*(fs*(fs*(fs*(-5.75452574944698e-29*fs + 7.27469124190795e-25) - 2.36761929650589e-21) + 2.15665382234029e-18) - 5.3389212423117e-16) + 3.40686364113531e-15) + fs*(fs*(fs*(fs*(fs*(5.77317651704237e-29*fs - 7.91492198040202e-25) + 2.5773097315087e-21) - 2.02385759012812e-18) + 5.21709009014916e-16) - 3.33278467477534e-15)) + fs*(fs*(fs*(fs*(fs*(4.64196013276193e-29*fs - 7.1140905248404e-25) + 2.87245155338884e-21) - 3.60543982135142e-18) + 8.93675308928682e-16) - 1.16723639524299e-14) + 3.91224189243262e-14;\n};"
 },
 {
  "id": "gx-mbclipper",
  "name": "Multi-Band Clipper",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Five-band clipper with independent Drive and Gain per band.",
  "description": "Splits the input into five bands at four adjustable crossovers and hard-clips each band with its own Drive and Gain. Useful for controlled, band-limited distortion without low-end mud.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "crossover b1 b2",
    "min": 20,
    "max": 20000,
    "default": 80,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Clipper/crossover_b1_b2"
   },
   {
    "label": "crossover b2 b3",
    "min": 20,
    "max": 20000,
    "default": 210,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Clipper/crossover_b2_b3"
   },
   {
    "label": "crossover b3 b4",
    "min": 20,
    "max": 20000,
    "default": 1700,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Clipper/crossover_b3_b4"
   },
   {
    "label": "crossover b4 b5",
    "min": 20,
    "max": 20000,
    "default": 5000,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Clipper/crossover_b4_b5"
   },
   {
    "label": "Drive1",
    "min": 0,
    "max": 1,
    "default": 0.33,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Clipper/Drive1"
   },
   {
    "label": "Gain",
    "min": -40,
    "max": 4,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Clipper/Gain"
   },
   {
    "label": "Gain1",
    "min": -40,
    "max": 4,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Clipper/Gain1"
   },
   {
    "label": "Drive2",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Clipper/Drive2"
   },
   {
    "label": "Gain2",
    "min": -40,
    "max": 4,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Clipper/Gain2"
   },
   {
    "label": "Drive3",
    "min": 0,
    "max": 1,
    "default": 0.65,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Clipper/Drive3"
   },
   {
    "label": "Gain3",
    "min": -40,
    "max": 4,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Clipper/Gain3"
   },
   {
    "label": "Drive4",
    "min": 0,
    "max": 1,
    "default": 0.33,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Clipper/Drive4"
   },
   {
    "label": "Gain4",
    "min": -40,
    "max": 4,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Clipper/Gain4"
   },
   {
    "label": "Drive5",
    "min": 0,
    "max": 1,
    "default": 0.1,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Clipper/Drive5"
   },
   {
    "label": "Gain5",
    "min": -40,
    "max": 4,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Clipper/Gain5"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/mbclipper.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"mbclip\";\ndeclare name \"MultiBand Clipper\";\ndeclare shortname \"MB Clipper\";\ndeclare category \"Distortion\";\ndeclare description \"MultiBand Clipper\";\n\nimport(\"stdfaust.lib\");\nimport(\"reducemaps.lib\");\n\ngxc = library(\"clipping.lib\");\n\nanti_denormal = pow(10,-20);\nanti_denormal_ac = 1 - 1' : *(anti_denormal) : + ~ *(-1);\n\nhifr1      =hslider(\"crossover_b1_b2 [log][name:Crossover B1-B2 (hz)][tooltip: Crossover fi.bandpass frequency]\" ,80 , 20, 20000, 1.08);\nhifr2      =hslider(\"crossover_b2_b3 [log][name:Crossover B2-B3 (hz)][tooltip: Crossover fi.bandpass frequency]\",210,20,20000,1.08);\nhifr3      =hslider(\"crossover_b3_b4 [log][name:Crossover B3-B4 (hz)][tooltip: Crossover fi.bandpass frequency]\",1700,20,20000,1.08);\nhifr4      =hslider(\"crossover_b4_b5 [log][name:Crossover B4-B5 (hz)][tooltip: Crossover fi.bandpass frequency]\",5000,20,20000,1.08);\n\ngeq = fi.filterbank(3, (hifr1,hifr2,hifr3,hifr4));\n\ndrive1     = hslider(\"Drive1 [tooltip: Amount of distortion]\", 0.33, 0, 1, 0.01);\ngain_1     = vslider(\"Gain1\", 0, -40, 4, 0.1) : ba.db2linear : si.smooth(0.999);\ndrive2     = hslider(\"Drive2 [tooltip: Amount of distortion]\", 0.5, 0, 1, 0.01);\ngain_2     = vslider(\"Gain2\", 0, -40, 4, 0.1) : ba.db2linear : si.smooth(0.999);\ndrive3     = hslider(\"Drive3 [tooltip: Amount of distortion]\", 0.65, 0, 1, 0.01);\ngain_3     = vslider(\"Gain3\", 0, -40, 4, 0.1) : ba.db2linear : si.smooth(0.999);\ndrive4     = hslider(\"Drive4 [tooltip: Amount of distortion]\", 0.33, 0, 1, 0.01);\ngain_4     = vslider(\"Gain4\", 0, -40, 4, 0.1) : ba.db2linear : si.smooth(0.999);\ndrive5     = hslider(\"Drive5 [tooltip: Amount of distortion]\", 0.1, 0, 1, 0.01);\ngain_5     = vslider(\"Gain5\", 0, -40, 4, 0.1) : ba.db2linear : si.smooth(0.999);\n\ngain      = vslider(\"Gain\", 0, -40, 4, 0.1) : ba.db2linear : si.smooth(0.999);\n\nvmeter1(x)\t\t= attach(x, envelop(x) : vbargraph(\"v1[nomidi][log]\", -70, +5));\nvmeter2(x)\t\t= attach(x, envelop(x) : vbargraph(\"v2[nomidi][log]\", -70, +5));\nvmeter3(x)\t\t= attach(x, envelop(x) : vbargraph(\"v3[nomidi][log]\", -70, +5));\nvmeter4(x)\t\t= attach(x, envelop(x) : vbargraph(\"v4[nomidi][log]\", -70, +5));\nvmeter5(x)\t\t= attach(x, envelop(x) : vbargraph(\"v5[nomidi][log]\", -70, +5));\n\nenvelop         = abs : max ~ (1.0/ma.SR) : mean(4096); // : max(ba.db2linear(-70)) : ba.linear2db;\n    \nclip(drive) = *(pregain) : clip : *(postgain) with {\n    pregain = pow(10.0,2*drive);\nclip = gxc.symclip;\n    postgain = max(1.0,1.0/pregain);\n};\n    \neclip(drive) = *(pregain) : clip : *(postgain) with {\n    pregain = pow(10.0,2*drive);    \n    clip(x) = ((exp(x*4)-exp(-x*4*1.2))/(exp(x*4)+exp(-x*4)))/4;\n    postgain = max(1.0,1.0/(pregain*2.5));\n};\n\ncclip(drive) = *(pregain) : clip : *(postgain) with {\n    pregain = pow(10.0,drive);\n    clip(x) = ma.tanh((drive+0.0001)*x)/ma.tanh(drive+0.0001);\n    postgain = max(1.0,1.0/pregain);\n};\n\naclip(drive) = *(pregain) : clip : *(postgain) with {\n    pregain = pow(10.0,2*drive);\n    clip(x) = atan(x)/ma.PI;\n    postgain = max(1.0,1.0/pregain);\n};\n\nprocess    = _: +(anti_denormal_ac): geq: ( dist5s , dist4s , dist3s, dist2s, dist1s) :> *(gain) with { \n    dist1s = clip(drive1: si.smooth(0.999)) : *(gain_1) : vmeter1;\n    dist2s = clip(drive2: si.smooth(0.999)) : *(gain_2) : vmeter2;\n    dist3s = clip(drive3: si.smooth(0.999)) : *(gain_3) : vmeter3;\n    dist4s = clip(drive4: si.smooth(0.999)) : *(gain_4) : vmeter4;\n    dist5s = clip(drive5: si.smooth(0.999)) : *(gain_5) : vmeter5;\n    \n};"
 },
 {
  "id": "gx-mbd",
  "name": "Multi-Band Distortion",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Five-band distortion with per-band Drive and DC Offset for asymmetric clipping.",
  "description": "Splits the input into five bands at four adjustable crossovers and distorts each with its own Drive and Offset (bias for asymmetry), then a master Gain. Lets bass stay clean while highs saturate.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "crossover b1 b2",
    "min": 20,
    "max": 20000,
    "default": 80,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Distortion/crossover_b1_b2"
   },
   {
    "label": "crossover b2 b3",
    "min": 20,
    "max": 20000,
    "default": 210,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Distortion/crossover_b2_b3"
   },
   {
    "label": "crossover b3 b4",
    "min": 20,
    "max": 20000,
    "default": 1700,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Distortion/crossover_b3_b4"
   },
   {
    "label": "crossover b4 b5",
    "min": 20,
    "max": 20000,
    "default": 5000,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Distortion/crossover_b4_b5"
   },
   {
    "label": "Drive1",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Distortion/Drive1"
   },
   {
    "label": "Offset1",
    "min": 0,
    "max": 0.5,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Distortion/Offset1"
   },
   {
    "label": "Drive2",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Distortion/Drive2"
   },
   {
    "label": "Offset2",
    "min": 0,
    "max": 0.5,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Distortion/Offset2"
   },
   {
    "label": "Drive3",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Distortion/Drive3"
   },
   {
    "label": "Offset3",
    "min": 0,
    "max": 0.5,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Distortion/Offset3"
   },
   {
    "label": "Drive4",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Distortion/Drive4"
   },
   {
    "label": "Offset4",
    "min": 0,
    "max": 0.5,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Distortion/Offset4"
   },
   {
    "label": "Drive5",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Distortion/Drive5"
   },
   {
    "label": "Offset5",
    "min": 0,
    "max": 0.5,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/MultiBand_Distortion/Offset5"
   },
   {
    "label": "Gain",
    "min": -40,
    "max": 4,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Distortion/Gain"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/mbd.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"mbd\";\ndeclare name \"MultiBand Distortion\";\ndeclare shortname \"MB Distortion\";\ndeclare category \"Distortion\";\ndeclare description \"MultiBand Distortion\";\n\nimport(\"stdfaust.lib\");\nrd = library(\"reducemaps.lib\");\n\nanti_denormal = pow(10,-20);\nanti_denormal_ac = 1 - 1' : *(anti_denormal) : + ~ *(-1);\n\nhifr1      =hslider(\"crossover_b1_b2 [log][name:Crossover B1-B2 (hz)][tooltip: Crossover fi.bandpass frequency]\" ,80 , 20, 20000, 1.08);\nhifr2      =hslider(\"crossover_b2_b3 [log][name:Crossover B2-B3 (hz)][tooltip: Crossover fi.bandpass frequency]\",210,20,20000,1.08);\nhifr3      =hslider(\"crossover_b3_b4 [log][name:Crossover B3-B4 (hz)][tooltip: Crossover fi.bandpass frequency]\",1700,20,20000,1.08);\nhifr4      =hslider(\"crossover_b4_b5 [log][name:Crossover B4-B5 (hz)][tooltip: Crossover fi.bandpass frequency]\",5000,20,20000,1.08);\n\ngeq = fi.filterbank(3, (hifr1,hifr2,hifr3,hifr4));\n\ndrive1     = hslider(\"Drive1 [tooltip: Amount of distortion]\", 0, 0, 1, 0.01): si.smooth(0.999);\noffset1    = hslider(\"Offset1 [tooltip: Brings in even harmonics]\", 0, 0, 0.5, 0.01): si.smooth(0.999);\ndrive2     = hslider(\"Drive2 [tooltip: Amount of distortion]\", 0, 0, 1, 0.01): si.smooth(0.999);\noffset2    = hslider(\"Offset2 [tooltip: Brings in even harmonics]\", 0, 0, 0.5, 0.01): si.smooth(0.999);\ndrive3     = hslider(\"Drive3 [tooltip: Amount of distortion]\", 0, 0, 1, 0.01): si.smooth(0.999);\noffset3    = hslider(\"Offset3 [tooltip: Brings in even harmonics]\", 0, 0, 0.5, 0.01): si.smooth(0.999);\ndrive4     = hslider(\"Drive4 [tooltip: Amount of distortion]\", 0, 0, 1, 0.01): si.smooth(0.999);\noffset4    = hslider(\"Offset4 [tooltip: Brings in even harmonics]\", 0, 0, 0.5, 0.01): si.smooth(0.999);\ndrive5     = hslider(\"Drive5 [tooltip: Amount of distortion]\", 0, 0, 1, 0.01): si.smooth(0.999);\noffset5    = hslider(\"Offset5 [tooltip: Brings in even harmonics]\", 0, 0, 0.5, 0.01): si.smooth(0.999);\n\ngain1      = vslider(\"Gain\", 0, -40, 4, 0.1) : ba.db2linear : si.smooth(0.999);\n\nvmeter1(x)\t\t= attach(x, envelop(x) : vbargraph(\"v1[nomidi:no]\", -70, +5));\nvmeter2(x)\t\t= attach(x, envelop(x) : vbargraph(\"v2[nomidi:no]\", -70, +5));\nvmeter3(x)\t\t= attach(x, envelop(x) : vbargraph(\"v3[nomidi:no]\", -70, +5));\nvmeter4(x)\t\t= attach(x, envelop(x) : vbargraph(\"v4[nomidi:no]\", -70, +5));\nvmeter5(x)\t\t= attach(x, envelop(x) : vbargraph(\"v5[nomidi:no]\", -70, +5));\n\nenvelop         = abs : max ~ (1.0/ma.SR) : rd.maxn(4096) ;\n//envelop         = abs : max ~ (1.0/ma.SR) : mean(4096); // : max(ba.db2linear(-70)) : ba.linear2db;\n\nprocess    = _: +(anti_denormal_ac): geq: ( dist5s , dist4s , dist3s, dist2s, dist1s) :> *(gain1) with { \n    dist1s = ef.cubicnl(drive1,offset1) : fi.dcblockerat(1.0) : vmeter1;\n    dist2s = ef.cubicnl(drive2,offset2) : fi.dcblockerat(1.0) : vmeter2;\n    dist3s = ef.cubicnl(drive3,offset3) : fi.dcblockerat(1.0) : vmeter3;\n    dist4s = ef.cubicnl(drive4,offset4) : fi.dcblockerat(1.0) : vmeter4;\n    dist5s = ef.cubicnl(drive5,offset5) : fi.dcblockerat(1.0) : vmeter5;\n    \n};"
 },
 {
  "id": "gx-gx-distortion",
  "name": "Multi-Band Distortion (guitarix)",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Guitarix's original four-band distortion with per-band drive/gain, resonator and wet/dry.",
  "description": "Splits the signal at three adjustable crossover frequencies and applies separate drive and gain per band, with an optional resonator and a wet/dry blend. The original guitarix distortion block; an algorithmic design rather than a pedal model.",
  "author": "brummer",
  "flags": "-double",
  "params": [
   {
    "label": "split low freq",
    "min": 20,
    "max": 600,
    "default": 250,
    "step": 10,
    "unit": "",
    "path": "/Multi_Band_Distortion/split_low_freq"
   },
   {
    "label": "split middle freq",
    "min": 600,
    "max": 1250,
    "default": 650,
    "step": 10,
    "unit": "",
    "path": "/Multi_Band_Distortion/split_middle_freq"
   },
   {
    "label": "split high freq",
    "min": 1250,
    "max": 12000,
    "default": 1250,
    "step": 10,
    "unit": "",
    "path": "/Multi_Band_Distortion/split_high_freq"
   },
   {
    "label": "level",
    "min": 0,
    "max": 0.5,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Distortion/level"
   },
   {
    "label": "gain",
    "min": -10,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Distortion/gain"
   },
   {
    "label": "low gain",
    "min": -10,
    "max": 20,
    "default": 10,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Distortion/low_gain"
   },
   {
    "label": "high gain",
    "min": -10,
    "max": 20,
    "default": 10,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Distortion/high_gain"
   },
   {
    "label": "middle l gain",
    "min": -10,
    "max": 20,
    "default": 10,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Distortion/middle_l_gain"
   },
   {
    "label": "middle h gain",
    "min": -10,
    "max": 20,
    "default": 10,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Distortion/middle_h_gain"
   },
   {
    "label": "drive",
    "min": 0,
    "max": 1,
    "default": 0.64,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Distortion/drive"
   },
   {
    "label": "low drive",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Distortion/low_drive"
   },
   {
    "label": "high drive",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Distortion/high_drive"
   },
   {
    "label": "middle l drive",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Distortion/middle_l_drive"
   },
   {
    "label": "middle h drive",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Distortion/middle_h_drive"
   },
   {
    "label": "vibrato",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Distortion/vibrato"
   },
   {
    "label": "trigger",
    "min": 0,
    "max": 1,
    "default": 0.12,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Distortion/trigger"
   },
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Distortion/wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gx_distortion.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \t\t\"Multi Band Distortion\";\ndeclare shortname       \"Distortion\";\ndeclare category        \"Distortion\";\ndeclare groups \"resonator[Distortion resonator]\";\ndeclare version \t\"0.01\";\ndeclare author \t\t\"brummer\";\ndeclare license \t\"BSD\";\ndeclare copyright \t\"(c)brummer 2008\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nF = nentry(\"split_low_freq\", 250, 20, 600, 10);\nF1 = nentry(\"split_middle_freq\", 650, 600, 1250, 10);\nF2 = nentry(\"split_high_freq\", 1250, 1250, 12000, 10);\n\n/**********************************************************************\n*** this part is included here for backward compatibility from 0.9.27 to\n*** 0.9.24 \n***********************************************************************/\n\n//------------------------------ ba.count and ba.take --------------------------------------\n\ncountN ((xs, xxs)) = 1 + countN(xxs);\ncountN (xx) = 1;\n\ntakeN (1, (xs, xxs))     = xs;\ntakeN (1, xs)                    = xs;\ntakeN (nn, (xs, xxs))    = takeN (nn-1, xxs);\n\n//------------------------------ low/high-passfilters --------------------------------------\n\ntf1N(b0,b1,a1) = _ <: *(b0), (mem : *(b1)) :> + ~ *(0-a1);\n\ntf2N(b0,b1,b2,a1,a2) = sub ~ conv2(a1,a2) : conv3(b0,b1,b2)\nwith {\n  conv3(k0,k1,k2,x)     = k0*x + k1*x' + k2*x'';\n  conv2(k0,k1,x)        = k0*x + k1*x';\n  sub(x,y)              = y-x;\n};\n\ntf1sN(b1,b0,a0,w1) = tf1N(b0d,b1d,a1d)\nwith {\n  c   = 1/tan((w1)*0.5/ma.SR); // bilinear-transform scale-factor\n  d   = a0 + c;\n  b1d = (b0 - b1*c) / d;\n  b0d = (b0 + b1*c) / d;\n  a1d = (a0 - c) / d;\n};\n\ntf2sN(b2,b1,b0,a1,a0,w1) = tf2N(b0d,b1d,b2d,a1d,a2d)\nwith {\n  c   = 1/tan((w1)*0.5/ma.SR); // bilinear-transform scale-factor\n  csq = c*c;\n  d   = a0 + a1 * c + csq;\n  b0d = (b0 + b1 * c + b2 * csq)/d;\n  b1d = 2 * (b0 - b2 * csq)/d;\n  b2d = (b0 - b1 * c + b2 * csq)/d;\n  a1d = 2 * (a0 - csq)/d;\n  a2d = (a0 - a1*c + csq)/d;\n};\n\nlowpassN(N,fc) = lowpass0_highpass1N(0,N,fc);\nhighpassN(N,fc) = lowpass0_highpass1N(1,N,fc);\nlowpass0_highpass1N(s,N,fc) = lphpr(s,N,N,fc)\nwith {\n  lphpr(s,0,N,fc) = _;\n  lphpr(s,1,N,fc) = tf1sN(s,1-s,1,2*ma.PI*fc);\n  lphpr(s,O,N,fc) = lphpr(s,(O-2),N,fc) : tf2sN(s,0,1-s,a1s,1,w1) with {\n    parity = N % 2;\n    S = (O-parity)/2; // current section number\n    a1s = -2*cos(-ma.PI + (1-parity)*ma.PI/(2*N) + (S-1+parity)*ma.PI/N);\n    w1 = 2*ma.PI*fc;\n  };\n};\n\n//------------------------------ an.analyzer --------------------------------------\nanalyzern(O,lfreqs) = _ <: bsplit(nb) with\n{\n   nb = countN(lfreqs);\n   fc(n) = takeN(n, lfreqs);\n   lp(n) = lowpassN(O,fc(n));\n   hp(n) = highpassN(O,fc(n));\n   bsplit(0) = _;\n   bsplit(i) = hp(i), (lp(i) <: bsplit(i-1));\n};\n\nanalyzerN(lfreqs) = analyzern(3,lfreqs);\n\nfilterbankn(O,lfreqs) = analyzern(O,lfreqs) : delayeq with\n{\n   nb = ba.count(lfreqs);\n   fc(n) = ba.take(n, lfreqs);\n   ap(n) = fi.highpass_plus_lowpass(O,fc(n));\n   delayeq = par(i,nb-1,apchain(nb-1-i)),_,_;\n   apchain(0) = _;\n   apchain(i) =  ap(i) : apchain(i-1);\n};\n\nfilterbankN(lfreqs) = fi.filterbank(3,lfreqs);\n\n/**********************************************************************\n*** end for backward compatibility from 0.9.27 to\n*** 0.9.24 , it could removed when switch completely to > 0.9.27\n***********************************************************************/\n\n//----------distortion---------\n\n//-distortion\ndrivelevel      = vslider(\"level\", 0.0, 0, 0.5, 0.01);\ndrivegain1      = vslider(\"gain\", 2, -10, 10, 0.1)-10 : ba.db2linear : smoothi(0.999);\nlow_gain      \t= vslider(\"low_gain[name:low]\", 10, -10, 20, 0.1)-10 : ba.db2linear : smoothi(0.999);\nhigh_gain      \t= vslider(\"high_gain[name:high]\", 10, -10, 20, 0.1)-10 : ba.db2linear : smoothi(0.999);\nmiddle_gain_l     = vslider(\"middle_l_gain[name:middle l.]\", 10, -10, 20, 0.1)-10 : ba.db2linear : smoothi(0.999);\nmiddle_gain_h     = vslider(\"middle_h_gain[name:middle h.]\", 10, -10, 20, 0.1)-10 : ba.db2linear : smoothi(0.999);\ndrive\t\t\t= vslider(\"drive\", 0.64, 0, 1, 0.01);\ndrive1\t\t\t= vslider(\"low_drive[name:low]\", 1, 0, 1, 0.01)*drive;\ndrive2\t\t\t= vslider(\"high_drive[name:high]\", 1, 0, 1, 0.01)*drive;\ndrive3\t\t\t= vslider(\"middle_l_drive[name:middle l.]\", 1, 0, 1, 0.01)*drive;\ndrive4\t\t\t= vslider(\"middle_h_drive[name:middle h.]\", 1, 0, 1, 0.01)*drive;\ndistortion1 \t=  _:ef.cubicnl(drive1,drivelevel): *(low_gain); \ndistortion2 \t=  _:ef.cubicnl(drive2,drivelevel) : *(high_gain);\ndistortion3 \t=  _:ef.cubicnl(drive3,drivelevel) : *(middle_gain_l);\ndistortion4 \t=  _:ef.cubicnl(drive4,drivelevel) : *(middle_gain_h);\ndistortion\t= fi.lowpass(2,15000.0): fi.highpass(1,31.0)  : filterbankN((F,(F1,F2))) : distortion2,distortion4 ,distortion3,distortion1 :>fi.lowpass(1,6531.0);\n\n//-resonator\nresonator \t\t= (+ <: (de.delay(4096, d-1) + de.delay(4096, d)) / 2) ~ *(1.0-a)\nwith {\n  d = vslider(\"vibrato\", 1, 0, 1, 0.01);\n  a = vslider(\"trigger\", 0.12, 0, 1, 0.01);\n};\n\nswitch2       \t= checkbox(\"resonator.on_off[name:resonat]\");\n//reso \t\t\t= hgroup(\"resonator\", bypass(switch2, resonator));\nmoving_filter(x) = (x+x'+x'')/3;\n\nwet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\ndry = 1 - wet;\n\nprocess_dist \t\t= bypass(switch2, resonator) : +(anti_denormal_ac) : distortion : *(drivegain1) ;\n\nprocess = _<:*(dry),(*(wet): process_dist):>_;"
 },
 {
  "id": "gx-mxrdist",
  "name": "MXR Distortion+",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "MXR Distortion+: op-amp gain into germanium-style diode clipping; crunchy, mid-forward.",
  "description": "Hand-written model of the MXR Distortion+ with input and output filters as pot-dependent filters and a diode clipper approximation, at 96 kHz. Drive and Volume give the classic crunchy, slightly nasal 1970s distortion.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/MXR_Distortion_Plus/drive"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/MXR_Distortion_Plus/Volume"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/mxrdist.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id         \"mxrdis\";\ndeclare name       \"MXR Distortion Plus\";\ndeclare shortname  \"MXR+\";\ndeclare category   \"Distortion\";\ndeclare samplerate \"96000\";\n\nimport(\"stdfaust.lib\");\n\ngxc = library(\"clipping.lib\");\n\ns = 0.993;\nfs = float(ma.SR);\ndrive =  0.75 + hslider(\"drive[name:Drive]\", 0.5, 0, 1, 0.01) * 0.25 : si.smooth(s);\n\nmxr_in = fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    \n    b0 = fs*(4.29274359816386e-10*fs + 6.43911539724579e-10);\n\n    b1 = -8.58548719632772e-10*pow(fs,2);\n\n    b2 = fs*(4.29274359816386e-10*fs - 6.43911539724579e-10);\n\n    a0 = fs*(4.3356710341455e-10*fs + 2.2111922274142e-8) + 2.14637179908193e-8;\n\n    a1 = -8.671342068291e-10*pow(fs,2) + 4.29274359816386e-8;\n\n    a2 = fs*(4.3356710341455e-10*fs - 2.2111922274142e-8) + 2.14637179908193e-8;\n};\n\nmxr_out = fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n\n       Volume = vslider(\"Volume[name:Volume]\", 0.5, 0, 1, 0.01) : si.smooth(s);\n    \n    b0 = 7.03343695930453e-6*Volume*fs;\n\n    b1 = 0;\n\n    b2 = -7.03343695930453e-6*Volume*fs;\n\n    a0 = fs*(1.40668739186091e-10*fs + 1.40739073555684e-5) + 0.000351671847965227;\n\n    a1 = -2.81337478372181e-10*pow(fs,2) + 0.000703343695930453;\n\n    a2 = fs*(1.40668739186091e-10*fs - 1.40739073555684e-5) + 0.000351671847965227;\n};\n\nmxr_drive = fi.iir((b0/a0,b1/a0),(a1/a0)) with {\n\n    b0 = -1.38434672619083e-5*(1.0-drive)*fs + 1.39085315580392e-5*fs + 0.000147270928318173;\n\n    b1 = 1.38434672619083e-5*(1.0-drive)*fs - 1.39085315580392e-5*fs + 0.000147270928318173;\n\n    a0 = -1.38434672619083e-5*(1.0-drive)*fs + 2.77519988199475e-5*fs + 0.000147270928318173;\n\n    a1 = 1.38434672619083e-5*(1.0-drive)*fs - 2.77519988199475e-5*fs + 0.000147270928318173;\n};\n\nprocess = mxr_in : X3 : lf : mxr_out   with {\n    R1 = 4700 + 500000 * (1.0 -drive);\n    R2 = 5000 + 500000 * drive;\n    C = 0.047 * 1e-6;\n    a1 = (R1 + R2) * C * 2 * ma.SR;\n    a2 = R1 * C * 2 * ma.SR;\n    B0 = (1 + a1) / (1 + a2);\n    B1 = (1 - a1) / (1 + a2);\n    A1 = (1 - a2) / (1 + a2);\n    X2 = fi.tf1(B0, B1, A1);\nopamp = gxc.opamp2;\n    X3 = _ <: _ - (X2-_ : opamp) :> _ ;\nasymclip = gxc.asymhardclip2;\n    clip = (_ : asymclip);\n    lf = fi.lowpass(3,16200.);\n};"
 },
 {
  "id": "gx-overdrive",
  "name": "Overdrive (rational waveshaper)",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Simple rational-function overdrive with drive-compensated level and wet/dry.",
  "description": "A single rational waveshaper x(|x|+d)/(x²+(d-1)|x|+1) with automatic level compensation and a wet/dry blend. Smooth, generic overdrive; not a circuit model.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "drive",
    "min": 1,
    "max": 20,
    "default": 1,
    "step": 0.1,
    "unit": "",
    "path": "/Overdrive/drive"
   },
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Overdrive/wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/overdrive.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Overdrive\";\ndeclare category \"Distortion\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\ndrive = vslider(\"drive\", 1, 1, 20, 0.1);\nf = drive * -0.5 : ba.db2linear : smoothi(0.999);\n\nwet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\ndry = 1 - wet;\n\noverdrive(x) = (x*(abs(x) + drive)/(x*x + (drive-1)*abs(x) + 1)) * f;\n\nprocess =  _<:*(dry),(*(wet) : overdrive):>_;"
 },
 {
  "id": "gx-aclipper",
  "name": "ProCo RAT",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "ProCo RAT-style op-amp distortion with asymmetric hard clipping, tone and level.",
  "description": "Op-amp gain-stage model into an asymmetric hard-clip table with a tone low-pass and level, at 96 kHz. Delivers the RAT's aggressive, saturated crunch from Drive, Tone and Level.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Rat/drive"
   },
   {
    "label": "tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Rat/tone"
   },
   {
    "label": "level",
    "min": -20,
    "max": 12,
    "default": -2,
    "step": 0.1,
    "unit": "",
    "path": "/Rat/level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/aclipper.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \t\t\"aclipper\";\ndeclare name            \"Rat\";\ndeclare category        \"Distortion\";\ndeclare samplerate \"96000\";\n\nimport(\"stdfaust.lib\");\n\ngxc = library(\"clipping.lib\");\n\ns = 0.993;\nfs = float(ma.SR);\ndrive =  hslider(\"drive[name:Drive]\", 0.5, 0, 1, 0.01) : si.smooth(s);\n\nrat_in = fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n\n    b0 = 1.82432723786905e-5*fs;\n\n    b1 = 0.000829239653576842;\n\n    b2 = -1.82432723786905e-5*fs;\n\n    a0 = fs*(3.64865447573811e-11*fs + 1.9073341271921e-5) + 0.000414619826788421;\n\n    a1 = -7.29730895147621e-11*pow(fs,2) + 0.000829239653576842;\n\n    a2 = fs*(3.64865447573811e-11*fs - 1.9073341271921e-5) + 0.000414619826788421;\n};\n\nrat_out = fi.iir((b0/a0,b1/a0),(a1/a0)) with {\n\n    b0 = 2.08332871602678e-5*fs;\n\n    b1 = -2.08332871602678e-5*fs;\n\n    a0 = 2.08332871602678e-5*fs + 2.21630714470934e-6;\n\n    a1 = -2.08332871602678e-5*fs + 2.21630714470934e-6;\n};\n\nrat_tone =  fi.iir((b0/a0,b1/a0),(a1/a0)) with {\n\n    Tone = 1.0 - vslider(\"tone[name:Tone]\", 0.5, 0, 1, 0.01) : si.smooth(s);\n    \n    b0 = 0.0593824228028504;\n\n    b1 = 0.0593824228028504;\n\n    a0 = -3.91923990498812e-5*Tone*fs + 3.91923990498812e-5*fs + 0.0593824228028504;\n\n    a1 = 3.91923990498812e-5*Tone*fs - 3.91923990498812e-5*fs + 0.0593824228028504;\n};\n\nratdrive = fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n\n    Volume = 0.5 + drive * 0.75 ;\n    \n    b0 = -9.26800656732889e-10*Volume*pow(fs,2);\n\n    b1 = 1.85360131346578e-9*Volume*pow(fs,2);\n\n    b2 = -9.26800656732889e-10*Volume*pow(fs,2);\n\n    a0 = fs*(4.3384046341364e-10*fs + 8.99037897457717e-9) + 3.41041934946762e-8;\n\n    a1 = -8.6768092682728e-10*pow(fs,2) + 6.82083869893523e-8;\n\n    a2 = fs*(4.3384046341364e-10*fs - 8.99037897457717e-9) + 3.41041934946762e-8;\n};\n\nprocess = rat_in : X3 : rat_out : ratdrive : clip : rat_tone : *(gain)  with {\n    R1 = 4700;\n    R2 = 1000 + 500000 * drive;\n    C = 0.047 * 1e-6;\n    a1 = (R1 + R2) * C * 2 * ma.SR;\n    a2 = R1 * C * 2 * ma.SR;\n    B0 = (1 + a1) / (1 + a2);\n    B1 = (1 - a1) / (1 + a2);\n    A1 = (1 - a2) / (1 + a2);\n    X1 = _<:_,(rat_drive):>_;\n    X2 = fi.tf1(B0, B1, A1);\nopamp = gxc.opamp;\n    X3 = _ <: _ - (X2-_ : opamp) :> _ ;\nasymclip = gxc.asymhardclip2;\n    clip = (_ : asymclip);\n    gain = hslider(\"level[name:Level]\", -2, -20, 12, 0.1) : ba.db2linear : si.smooth(s);\n};"
 },
 {
  "id": "gx-scream",
  "name": "Screaming Bird",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Electro-Harmonix Screaming Bird treble booster; bright single-transistor boost.",
  "description": "DK circuit simulation from the Screaming Bird schematic: a transistor stage as a pot-dependent filter with clipping. The Scream knob adds a piercing, bass-cut treble boost.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Scream",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Screaming_Bird/Scream"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/scream.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"scream\";\ndeclare name \"Screaming Bird\";\ndeclare category \"Distortion\";\ndeclare shortname \"Scream Bird\";\ndeclare description \"Screaming Bird\";\n\nimport(\"stdfaust.lib\");\n\nprocess = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) : clip  with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    a = 1.2715 - Scream ;\n    clip(x) = min(0.4514,max(-0.2514,x));\n\n    \n        Scream = vslider(\"Scream[name:Scream]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = -6.82076449438528e-9*Scream*pow(fs,2) - 6.82076449438528e-10*pow(fs,2);\n\n    b1 = 1.36415289887706e-8*Scream*pow(fs,2) + 1.36415289887706e-9*pow(fs,2);\n\n    b2 = -6.82076449438528e-9*Scream*pow(fs,2) - 6.82076449438528e-10*pow(fs,2);\n\n    a0 = fs*(3.64434266110822e-10*fs + 3.23311541086178e-6) + 0.00515391115930048;\n\n    a1 = -7.28868532221644e-10*pow(fs,2) + 0.010307822318601;\n\n    a2 = fs*(3.64434266110822e-10*fs - 3.23311541086178e-6) + 0.00515391115930048;\n};"
 },
 {
  "id": "gx-softclip",
  "name": "Soft Clip",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Symmetric soft clipper with a residual blend; gentle, generic saturation.",
  "description": "Symmetric clipping at a threshold set by the Fuzz control, with a third of the clipped-off residual mixed back in. A basic saturation stage rather than a pedal model.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.fuzz",
    "min": 0,
    "max": 1.99,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/gx_softclip/.amp.fuzz"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/softclip.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"amp.clip\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\nb = hslider(\".amp.fuzz\", 0.0, 0.0, 1.99, 0.01);\na = 2-b;\n//cut(x) = (ma.fabs (x-a) -ma.fabs (x+a))*0.5;\nr(x) = x-sym_clip(a*0.88);\nprocess(x) = x:sym_clip(a*0.88) <:+(r(x)*0.33);"
 },
 {
  "id": "lib-tape-hysteresis",
  "name": "Tape Hysteresis",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Jiles-Atherton magnetic hysteresis tape saturator (CHOW Tape port) - soft, dynamic tape compression",
  "description": "Jiles-Atherton magnetic hysteresis tape saturator (CHOW Tape port) - soft, dynamic tape compression",
  "author": "Jatin Chowdhury (model), Faust port in hysteresis.lib",
  "flags": "",
  "params": [
   {
    "label": "Drive",
    "min": -20,
    "max": 40,
    "default": 12,
    "step": 0.1,
    "unit": "dB",
    "path": "/Tape_Hysteresis/Drive"
   },
   {
    "label": "Saturation",
    "min": 100,
    "max": 1000,
    "default": 380,
    "step": 1,
    "unit": "",
    "path": "/Tape_Hysteresis/Saturation"
   },
   {
    "label": "Loop Width",
    "min": 50,
    "max": 1000,
    "default": 380,
    "step": 1,
    "unit": "",
    "path": "/Tape_Hysteresis/Loop_Width"
   },
   {
    "label": "Bias",
    "min": 0,
    "max": 1,
    "default": 0.25,
    "step": 0.01,
    "unit": "",
    "path": "/Tape_Hysteresis/Bias"
   },
   {
    "label": "Trim",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Tape_Hysteresis/Trim"
   }
  ],
  "faustCode": "declare name \"Tape Hysteresis\";\ndeclare description \"Jiles-Atherton magnetic hysteresis tape saturator (CHOW Tape port) - soft, dynamic tape compression\";\ndeclare author \"Jatin Chowdhury (model), Faust port in hysteresis.lib\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/hysteresis.lib hy.ja_processor\";\ndeclare category \"guitar\";\ndeclare family \"dirt\";\nimport(\"stdfaust.lib\");\n\ndrive = hslider(\"[0] Drive[unit:dB]\", 12, -20, 40, 0.1) : ba.db2linear : si.smoo;\nsat   = hslider(\"[1] Saturation\", 380, 100, 1000, 1);\nwidth = hslider(\"[2] Loop Width\", 380, 50, 1000, 1);\nbias  = hslider(\"[3] Bias\", 0.25, 0, 1, 0.01);\ntrim  = hslider(\"[4] Trim[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\nprocess = hy.ja_processor(sat, 720, 0.015, width, bias, drive, trim);"
 },
 {
  "id": "gx-buffb",
  "name": "Transistor Buffer Boost",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Single-transistor buffer/booster; clean level lift with a slight tonal change.",
  "description": "DK circuit simulation from the transistor buffer schematic: a linear pot-dependent filter for Volume and Intensity. A clean boost with the mild colouring of a discrete transistor buffer.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Buffer_Booster/Volume"
   },
   {
    "label": "Intensity",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Buffer_Booster/Intensity"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/buffb.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"buffb\";\ndeclare name \"Buffer Booster\";\ndeclare category \"Tone Control\";\ndeclare shortname \"Buffer Boost\";\ndeclare description \"Buffer Booster\";\n\nimport(\"stdfaust.lib\");\n\nprocess = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n    \n        Volume = vslider(\"Volume[name:Volume]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Intensity = vslider(\"Intensity[name:Intensity]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Intensity*(Intensity*Volume*pow(fs,3)*(-2.84995035519639e-20*fs - 6.45077038297955e-16) + Volume*pow(fs,3)*(2.97690025361778e-20*fs - 3.02300377935444e-13)) + Volume*pow(fs,2)*(6.76568239458587e-19*fs - 6.87046313489645e-12);\n\n    b1 = Intensity*(Intensity*Volume*pow(fs,3)*(1.13998014207856e-19*fs + 1.29015407659591e-15) + Volume*pow(fs,3)*(-1.19076010144711e-19*fs + 6.04600755870888e-13)) - 1.35313647891717e-18*Volume*pow(fs,3);\n\n    b2 = Intensity*(-1.70997021311783e-19*Intensity*Volume*pow(fs,4) + 1.78614015217067e-19*Volume*pow(fs,4)) + 1.37409262697929e-11*Volume*pow(fs,2);\n\n    b3 = Intensity*(Intensity*Volume*pow(fs,3)*(1.13998014207856e-19*fs - 1.29015407659591e-15) + Volume*pow(fs,3)*(-1.19076010144711e-19*fs - 6.04600755870888e-13)) + 1.35313647891717e-18*Volume*pow(fs,3);\n\n    b4 = Intensity*(Intensity*Volume*pow(fs,3)*(-2.84995035519639e-20*fs + 6.45077038297955e-16) + Volume*pow(fs,3)*(2.97690025361778e-20*fs + 3.02300377935444e-13)) + Volume*pow(fs,2)*(-6.76568239458587e-19*fs - 6.87046313489645e-12);\n\n    a0 = Intensity*(Intensity*fs*(fs*(fs*(-2.88228949502788e-20*fs - 3.1353376203179e-14) - 9.57866164137552e-13) - 4.00199516463868e-12) + fs*(fs*(fs*(3.01067992749548e-20*fs + 3.28941142776728e-14) + 4.37053187936949e-12) + 2.10094331121784e-11)) + fs*(fs*(6.84245438067155e-19*fs + 7.47593506310745e-13) + 9.93302699856702e-11) + 4.77487116185873e-10;\n\n    a1 = Intensity*(Intensity*fs*(pow(fs,2)*(1.15291579801115e-19*fs + 6.27067524063581e-14) - 8.00399032927735e-12) + fs*(pow(fs,2)*(-1.20427197099819e-19*fs - 6.57882285553455e-14) + 4.20188662243568e-11)) + fs*(-1.36849087613431e-18*pow(fs,2) + 1.9866053997134e-10) + 1.90994846474349e-9;\n\n    a2 = Intensity*(Intensity*pow(fs,2)*(-1.72937369701673e-19*pow(fs,2) + 1.9157323282751e-12) + pow(fs,2)*(1.80640795649729e-19*pow(fs,2) - 8.74106375873897e-12)) - 1.49518701262149e-12*pow(fs,2) + 2.86492269711524e-9;\n\n    a3 = Intensity*(Intensity*fs*(pow(fs,2)*(1.15291579801115e-19*fs - 6.27067524063581e-14) + 8.00399032927735e-12) + fs*(pow(fs,2)*(-1.20427197099819e-19*fs + 6.57882285553455e-14) - 4.20188662243568e-11)) + fs*(1.36849087613431e-18*pow(fs,2) - 1.9866053997134e-10) + 1.90994846474349e-9;\n\n    a4 = Intensity*(Intensity*fs*(fs*(fs*(-2.88228949502788e-20*fs + 3.1353376203179e-14) - 9.57866164137552e-13) + 4.00199516463868e-12) + fs*(fs*(fs*(3.01067992749548e-20*fs - 3.28941142776728e-14) + 4.37053187936949e-12) - 2.10094331121784e-11)) + fs*(fs*(-6.84245438067155e-19*fs + 7.47593506310745e-13) - 9.93302699856702e-11) + 4.77487116185873e-10;\n};"
 },
 {
  "id": "gx-fumaster",
  "name": "Vintage Fuzz Master",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Vintage Fuzz Master three-transistor fuzz with Tone, Volume and a wet/dry blend.",
  "description": "DK circuit simulation from the Vintage Fuzz Master schematic: pot-dependent filters followed by three transistor-stage tables, plus a wet/dry blend. A gnarly 1960s-style fuzz with a Tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Fuzz_Master/wet_dry"
   },
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fuzz_Master/Tone"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fuzz_Master/Volume"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/fumaster.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"fumaster\";\ndeclare name \"Fuzz Master\";\ndeclare category \"Distortion\";\ndeclare shortname \"Fuzz Master\";\ndeclare description \"Vintage Fuzz Master\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\nprocess = pre : _<:*(dry),(*(wet) : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0,b6/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0,a6/a0)): clip):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    wet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\n    dry = 1 - wet;\n    clip = tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) ;\n\n    \n        Tone = vslider(\"Tone[name:Tone]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Volume = vslider(\"Volume[name:Volume]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Tone*(Volume*pow(fs,5)*(-1.41775270516311e-27*fs + 4.71779589725812e-22) + pow(fs,5)*(-1.41775270516311e-29*fs + 4.71779589725812e-24)) + Volume*pow(fs,4)*(fs*(1.41775270516311e-27*fs - 4.70999825737972e-22) - 2.59478774349197e-19) + pow(fs,4)*(fs*(1.41775270516311e-29*fs - 4.70999825737972e-24) - 2.59478774349197e-21);\n\n    b1 = Tone*(Volume*pow(fs,5)*(8.50651623097868e-27*fs - 1.88711835890325e-21) + pow(fs,5)*(8.50651623097868e-29*fs - 1.88711835890325e-23)) + Volume*pow(fs,4)*(fs*(-8.50651623097868e-27*fs + 1.88399930295189e-21) + 5.18957548698393e-19) + pow(fs,4)*(fs*(-8.50651623097868e-29*fs + 1.88399930295189e-23) + 5.18957548698393e-21);\n\n    b2 = Tone*(Volume*pow(fs,5)*(-2.12662905774467e-26*fs + 2.35889794862906e-21) + pow(fs,5)*(-2.12662905774467e-28*fs + 2.35889794862906e-23)) + Volume*pow(fs,4)*(fs*(2.12662905774467e-26*fs - 2.35499912868986e-21) + 2.59478774349197e-19) + pow(fs,4)*(fs*(2.12662905774467e-28*fs - 2.35499912868986e-23) + 2.59478774349197e-21);\n\n    b3 = Tone*(2.83550541032623e-26*Volume*pow(fs,6) + 2.83550541032623e-28*pow(fs,6)) + Volume*pow(fs,4)*(-2.83550541032623e-26*pow(fs,2) - 1.03791509739679e-18) + pow(fs,4)*(-2.83550541032623e-28*pow(fs,2) - 1.03791509739679e-20);\n\n    b4 = Tone*(Volume*pow(fs,5)*(-2.12662905774467e-26*fs - 2.35889794862906e-21) + pow(fs,5)*(-2.12662905774467e-28*fs - 2.35889794862906e-23)) + Volume*pow(fs,4)*(fs*(2.12662905774467e-26*fs + 2.35499912868986e-21) + 2.59478774349197e-19) + pow(fs,4)*(fs*(2.12662905774467e-28*fs + 2.35499912868986e-23) + 2.59478774349197e-21);\n\n    b5 = Tone*(Volume*pow(fs,5)*(8.50651623097868e-27*fs + 1.88711835890325e-21) + pow(fs,5)*(8.50651623097868e-29*fs + 1.88711835890325e-23)) + Volume*pow(fs,4)*(fs*(-8.50651623097868e-27*fs - 1.88399930295189e-21) + 5.18957548698393e-19) + pow(fs,4)*(fs*(-8.50651623097868e-29*fs - 1.88399930295189e-23) + 5.18957548698393e-21);\n\n    b6 = Tone*(Volume*pow(fs,5)*(-1.41775270516311e-27*fs - 4.71779589725812e-22) + pow(fs,5)*(-1.41775270516311e-29*fs - 4.71779589725812e-24)) + Volume*pow(fs,4)*(fs*(1.41775270516311e-27*fs + 4.70999825737972e-22) - 2.59478774349197e-19) + pow(fs,4)*(fs*(1.41775270516311e-29*fs + 4.70999825737972e-24) - 2.59478774349197e-21);\n\n    a0 = Tone*(Tone*pow(fs,2)*(fs*(fs*(fs*(-1.00799506674223e-28*fs - 2.59175366383786e-25) - 4.35259230096405e-22) - 1.02583553103419e-19) - 2.16974948431515e-18) + fs*(fs*(fs*(fs*(fs*(-1.5016846937505e-31*fs + 4.96235474586462e-26) + 1.27917670111645e-22) + 2.16655787499057e-19) + 5.11414335446406e-17) + 1.08487474215758e-15)) + fs*(fs*(fs*(fs*(fs*(1.00949675143598e-28*fs + 3.20513868924941e-25) + 5.95381363906935e-22) + 3.72110810064138e-19) + 7.52873102578757e-17) + 3.94912717206244e-15) + 5.42437371078787e-14;\n\n    a1 = Tone*(Tone*pow(fs,2)*(pow(fs,2)*(fs*(6.0479704004534e-28*fs + 1.03670146553514e-24) + 8.70518460192809e-22) - 4.3394989686303e-18) + fs*(fs*(pow(fs,2)*(fs*(9.01010816250298e-31*fs - 1.98494189834585e-25) - 2.5583534022329e-22) + 1.02282867089281e-16) + 4.3394989686303e-15)) + fs*(fs*(pow(fs,2)*(fs*(-6.0569805086159e-28*fs - 1.28205547569977e-24) - 1.19076272781387e-21) + 1.50574620515751e-16) + 1.57965086882498e-14) + 3.25462422647273e-13;\n\n    a2 = Tone*(Tone*pow(fs,2)*(fs*(fs*(fs*(-1.51199260011335e-27*fs - 1.29587683191893e-24) + 4.35259230096405e-22) + 3.07750659310257e-19) + 2.16974948431515e-18) + fs*(fs*(fs*(fs*(fs*(-2.25252704062574e-30*fs + 2.48117737293231e-25) - 1.27917670111645e-22) - 6.4996736249717e-19) - 5.11414335446406e-17) + 5.42437371078788e-15)) + fs*(fs*(fs*(fs*(fs*(1.51424512715397e-27*fs + 1.60256934462471e-24) - 5.95381363906935e-22) - 1.11633243019242e-18) - 7.52873102578757e-17) + 1.97456358603122e-14) + 8.13656056618181e-13;\n\n    a3 = Tone*(Tone*pow(fs,2)*(pow(fs,2)*(2.01599013348447e-27*pow(fs,2) - 1.74103692038562e-21) + 8.6789979372606e-18) + pow(fs,2)*(pow(fs,2)*(3.00336938750099e-30*pow(fs,2) + 5.11670680446579e-22) - 2.04565734178562e-16)) + pow(fs,2)*(pow(fs,2)*(-2.01899350287197e-27*pow(fs,2) + 2.38152545562774e-21) - 3.01149241031503e-16) + 1.08487474215758e-12;\n\n    a4 = Tone*(Tone*pow(fs,2)*(fs*(fs*(fs*(-1.51199260011335e-27*fs + 1.29587683191893e-24) + 4.35259230096405e-22) - 3.07750659310257e-19) + 2.16974948431515e-18) + fs*(fs*(fs*(fs*(fs*(-2.25252704062574e-30*fs - 2.48117737293231e-25) - 1.27917670111645e-22) + 6.4996736249717e-19) - 5.11414335446406e-17) - 5.42437371078788e-15)) + fs*(fs*(fs*(fs*(fs*(1.51424512715397e-27*fs - 1.60256934462471e-24) - 5.95381363906935e-22) + 1.11633243019242e-18) - 7.52873102578757e-17) - 1.97456358603122e-14) + 8.13656056618181e-13;\n\n    a5 = Tone*(Tone*pow(fs,2)*(pow(fs,2)*(fs*(6.0479704004534e-28*fs - 1.03670146553514e-24) + 8.70518460192809e-22) - 4.3394989686303e-18) + fs*(fs*(pow(fs,2)*(fs*(9.01010816250298e-31*fs + 1.98494189834585e-25) - 2.5583534022329e-22) + 1.02282867089281e-16) - 4.3394989686303e-15)) + fs*(fs*(pow(fs,2)*(fs*(-6.0569805086159e-28*fs + 1.28205547569977e-24) - 1.19076272781387e-21) + 1.50574620515751e-16) - 1.57965086882498e-14) + 3.25462422647273e-13;\n\n    a6 = Tone*(Tone*pow(fs,2)*(fs*(fs*(fs*(-1.00799506674223e-28*fs + 2.59175366383786e-25) - 4.35259230096405e-22) + 1.02583553103419e-19) - 2.16974948431515e-18) + fs*(fs*(fs*(fs*(fs*(-1.5016846937505e-31*fs - 4.96235474586462e-26) + 1.27917670111645e-22) - 2.16655787499057e-19) + 5.11414335446406e-17) - 1.08487474215758e-15)) + fs*(fs*(fs*(fs*(fs*(1.00949675143598e-28*fs - 3.20513868924941e-25) + 5.95381363906935e-22) - 3.72110810064138e-19) + 7.52873102578757e-17) - 3.94912717206244e-15) + 5.42437371078787e-14;\n};"
 },
 {
  "id": "lib-wavefolder",
  "name": "Wavefolder",
  "category": "guitar",
  "family": "dirt",
  "familyName": "Dirt",
  "icon": "tabler:flame",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "ef.wavefold triangle-style folding with pre-gain - Buchla/Serge-like harmonic bloom",
  "description": "ef.wavefold triangle-style folding with pre-gain - Buchla/Serge-like harmonic bloom",
  "author": "Grame",
  "flags": "",
  "params": [
   {
    "label": "Drive",
    "min": 0,
    "max": 40,
    "default": 12,
    "step": 0.1,
    "unit": "dB",
    "path": "/Wavefolder/Drive"
   },
   {
    "label": "Fold Width",
    "min": 0.05,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Wavefolder/Fold_Width"
   },
   {
    "label": "Tone",
    "min": 800,
    "max": 12000,
    "default": 5000,
    "step": 1,
    "unit": "Hz",
    "path": "/Wavefolder/Tone"
   },
   {
    "label": "Level",
    "min": -30,
    "max": 12,
    "default": -6,
    "step": 0.1,
    "unit": "dB",
    "path": "/Wavefolder/Level"
   }
  ],
  "faustCode": "declare name \"Wavefolder\";\ndeclare description \"ef.wavefold triangle-style folding with pre-gain - Buchla/Serge-like harmonic bloom\";\ndeclare author \"Grame\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/misceffects.lib ef.wavefold\";\ndeclare category \"guitar\";\ndeclare family \"dirt\";\nimport(\"stdfaust.lib\");\n\ngain  = hslider(\"[0] Drive[unit:dB]\", 12, 0, 40, 0.1) : ba.db2linear : si.smoo;\nwidth = hslider(\"[1] Fold Width\", 0.5, 0.05, 1, 0.01) : si.smoo;\ntone  = hslider(\"[2] Tone[unit:Hz][scale:log]\", 5000, 800, 12000, 1) : si.smoo;\nlevel = hslider(\"[3] Level[unit:dB]\", -6, -30, 12, 0.1) : ba.db2linear : si.smoo;\nprocess = *(gain) : ma.tanh : ef.wavefold(max(0.05, width)) : fi.dcblocker : fi.lowpass(1, tone) : *(level);"
 },
 {
  "id": "lib-1176",
  "name": "1176 Limiter R4",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "co.limiter_1176_R4_mono: UREI 1176-style FET limiter at ratio 4, fast attack, with input/output gain",
  "description": "co.limiter_1176_R4_mono: UREI 1176-style FET limiter at ratio 4, fast attack, with input/output gain",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Input",
    "min": 0,
    "max": 40,
    "default": 12,
    "step": 0.1,
    "unit": "dB",
    "path": "/1176_Limiter_R4/Input"
   },
   {
    "label": "Output",
    "min": -30,
    "max": 12,
    "default": -6,
    "step": 0.1,
    "unit": "dB",
    "path": "/1176_Limiter_R4/Output"
   }
  ],
  "faustCode": "declare name \"1176 Limiter R4\";\ndeclare description \"co.limiter_1176_R4_mono: UREI 1176-style FET limiter at ratio 4, fast attack, with input/output gain\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/compressors.lib co.limiter_1176_R4_mono\";\ndeclare category \"guitar\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\ningain  = hslider(\"[0] Input[unit:dB]\", 12, 0, 40, 0.1) : ba.db2linear : si.smoo;\noutgain = hslider(\"[1] Output[unit:dB]\", -6, -30, 12, 0.1) : ba.db2linear : si.smoo;\nprocess = *(ingain) : co.limiter_1176_R4_mono : *(outgain);"
 },
 {
  "id": "lib-3band-compressor",
  "name": "3-Band Compressor",
  "category": "drum",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "DrumBrute / Volca",
  "source": "faustlibraries",
  "license": "GPL-3.0-only",
  "shortDesc": "fi.filterbank 3-way split into three Bart Brouns feed-forward compressors with per-band strength - multiband drum control",
  "description": "fi.filterbank 3-way split into three Bart Brouns feed-forward compressors with per-band strength - multiband drum control",
  "author": "Bart Brouns (compressors), Julius O. Smith III (filterbank)",
  "flags": "",
  "params": [
   {
    "label": "Low Xover",
    "min": 60,
    "max": 800,
    "default": 200,
    "step": 1,
    "unit": "Hz",
    "path": "/3-Band_Compressor/Low_Xover"
   },
   {
    "label": "High Xover",
    "min": 800,
    "max": 8000,
    "default": 2500,
    "step": 1,
    "unit": "Hz",
    "path": "/3-Band_Compressor/High_Xover"
   },
   {
    "label": "Low Strength",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/3-Band_Compressor/Low_Strength"
   },
   {
    "label": "Mid Strength",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/3-Band_Compressor/Mid_Strength"
   },
   {
    "label": "High Strength",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/3-Band_Compressor/High_Strength"
   },
   {
    "label": "Threshold",
    "min": -60,
    "max": 0,
    "default": -30,
    "step": 0.1,
    "unit": "dB",
    "path": "/3-Band_Compressor/Threshold"
   },
   {
    "label": "Attack",
    "min": 0.1,
    "max": 100,
    "default": 8,
    "step": 0.1,
    "unit": "ms",
    "path": "/3-Band_Compressor/Attack"
   },
   {
    "label": "Release",
    "min": 10,
    "max": 1000,
    "default": 150,
    "step": 1,
    "unit": "ms",
    "path": "/3-Band_Compressor/Release"
   },
   {
    "label": "Makeup",
    "min": 0,
    "max": 30,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/3-Band_Compressor/Makeup"
   }
  ],
  "faustCode": "declare name \"3-Band Compressor\";\ndeclare description \"fi.filterbank 3-way split into three Bart Brouns feed-forward compressors with per-band strength - multiband drum control\";\ndeclare author \"Bart Brouns (compressors), Julius O. Smith III (filterbank)\";\ndeclare license \"GPL-3.0-only\";\ndeclare source \"grame-cncm/faustlibraries/compressors.lib co.FFcompressor_N_chan + fi.filterbank\";\ndeclare category \"drum\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\nxlo    = hslider(\"[0] Low Xover[unit:Hz][scale:log]\", 200, 60, 800, 1);\nxhi    = hslider(\"[1] High Xover[unit:Hz][scale:log]\", 2500, 800, 8000, 1);\nsLo    = hslider(\"[2] Low Strength\", 0.6, 0, 1, 0.01) : si.smoo;\nsMid   = hslider(\"[3] Mid Strength\", 0.5, 0, 1, 0.01) : si.smoo;\nsHi    = hslider(\"[4] High Strength\", 0.4, 0, 1, 0.01) : si.smoo;\nthresh = hslider(\"[5] Threshold[unit:dB]\", -30, -60, 0, 0.1) : si.smoo;\natt    = hslider(\"[6] Attack[unit:ms]\", 8, 0.1, 100, 0.1) : /(1000);\nrel    = hslider(\"[7] Release[unit:ms]\", 150, 10, 1000, 1) : /(1000);\nmakeup = hslider(\"[8] Makeup[unit:dB]\", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;\n\ncomp(s) = co.FFcompressor_N_chan(s, thresh, att, rel, 6, 0, 0, _, 1);\nprocess = fi.filterbank(3, (xlo, xhi)) : comp(sHi), comp(sMid), comp(sLo) :> *(makeup);"
 },
 {
  "id": "mag-character-compressor",
  "name": "Character Compressor",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "magnetophon",
  "license": "GPL-2.0",
  "shortDesc": "Bart Brouns' blushcomp-derived colour compressor (after Sampo Savolainen): peak/RMS detector, power/curve/shape gain-law, rate-limited GR, gain-vs-high-shelf output",
  "description": "Bart Brouns' blushcomp-derived colour compressor (after Sampo Savolainen): peak/RMS detector, power/curve/shape gain-law, rate-limited GR, gain-vs-high-shelf output",
  "author": "Bart Brouns (based on blushcomp by Sampo Savolainen)",
  "flags": "",
  "params": [
   {
    "label": "feedback/feedforward",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.001,
    "unit": "",
    "path": "/Character_Compressor/feedback_feedforward"
   },
   {
    "label": "ratelimit amount",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.001,
    "unit": "",
    "path": "/Character_Compressor/ratelimit_amount"
   },
   {
    "label": "Input Gain",
    "min": -40,
    "max": 40,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Character_Compressor/Input_Gain"
   },
   {
    "label": "hi shelf freq",
    "min": 1,
    "max": 400,
    "default": 134,
    "step": 1,
    "unit": "",
    "path": "/Character_Compressor/hi_shelf_freq"
   },
   {
    "label": "max attack",
    "min": 6,
    "max": 8000,
    "default": 1020,
    "step": 1,
    "unit": "dB/s",
    "path": "/Character_Compressor/max_attack"
   },
   {
    "label": "power",
    "min": -33,
    "max": 33,
    "default": 1.881,
    "step": 0.001,
    "unit": "",
    "path": "/Character_Compressor/power"
   },
   {
    "label": "Max Gain Reduction",
    "min": -60,
    "max": 0,
    "default": -15,
    "step": 0.1,
    "unit": "dB",
    "path": "/Character_Compressor/Max_Gain_Reduction"
   },
   {
    "label": "peak/RMS",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.001,
    "unit": "",
    "path": "/Character_Compressor/peak_RMS"
   },
   {
    "label": "gain/hi-shelve crossfade",
    "min": 0,
    "max": 1,
    "default": 0.811,
    "step": 0.001,
    "unit": "",
    "path": "/Character_Compressor/gain_hi-shelve_crossfade"
   },
   {
    "label": "max decay",
    "min": 6,
    "max": 8000,
    "default": 3813,
    "step": 1,
    "unit": "dB/s",
    "path": "/Character_Compressor/max_decay"
   },
   {
    "label": "RMS size",
    "min": 1,
    "max": 512,
    "default": 96,
    "step": 1,
    "unit": "",
    "path": "/Character_Compressor/RMS_size"
   },
   {
    "label": "curve",
    "min": -1,
    "max": 1,
    "default": 0,
    "step": 0.001,
    "unit": "",
    "path": "/Character_Compressor/curve"
   },
   {
    "label": "decayMult",
    "min": 0,
    "max": 20000,
    "default": 20000,
    "step": 0.001,
    "unit": "",
    "path": "/Character_Compressor/decayMult"
   },
   {
    "label": "output gain (dB)",
    "min": -40,
    "max": 40,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Character_Compressor/output_gain__dB_"
   },
   {
    "label": "Threshold",
    "min": -80,
    "max": 0,
    "default": -27.1,
    "step": 0.1,
    "unit": "dB",
    "path": "/Character_Compressor/Threshold"
   },
   {
    "label": "decayPower",
    "min": 0,
    "max": 50,
    "default": 50,
    "step": 0.001,
    "unit": "",
    "path": "/Character_Compressor/decayPower"
   },
   {
    "label": "shape",
    "min": 1,
    "max": 100,
    "default": 94,
    "step": 0.001,
    "unit": "",
    "path": "/Character_Compressor/shape"
   },
   {
    "label": "Ratio",
    "min": 1,
    "max": 20,
    "default": 20,
    "step": 0.1,
    "unit": "",
    "path": "/Character_Compressor/Ratio"
   },
   {
    "label": "IM size",
    "min": 1,
    "max": 512,
    "default": 108,
    "step": 1,
    "unit": "",
    "path": "/Character_Compressor/IM_size"
   },
   {
    "label": "Attack",
    "min": 0.1,
    "max": 500,
    "default": 23.7,
    "step": 0.1,
    "unit": "ms",
    "path": "/Character_Compressor/Attack"
   },
   {
    "label": "Release",
    "min": 0.1,
    "max": 2000,
    "default": 0.1,
    "step": 0.1,
    "unit": "ms",
    "path": "/Character_Compressor/Release"
   },
   {
    "label": "sidechain hpf",
    "min": 1,
    "max": 400,
    "default": 154,
    "step": 1,
    "unit": "",
    "path": "/Character_Compressor/sidechain_hpf"
   }
  ],
  "faustCode": "declare name \"Character Compressor\";\ndeclare description \"Bart Brouns' blushcomp-derived colour compressor (after Sampo Savolainen): peak/RMS detector, power/curve/shape gain-law, rate-limited GR, gain-vs-high-shelf output\";\ndeclare author \"Bart Brouns (based on blushcomp by Sampo Savolainen)\";\ndeclare license \"GPL-2.0\";\ndeclare source \"magnetophon/CharacterCompressor CharacterCompressorMono.dsp + lib/*.lib\";\ndeclare category \"guitar\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\nCOEFF2DB(x) = log10(max(x, 1e-9)) * 20;\nDB2COEFF(x) = pow(10, x / 20);\nTHRESH(t,x) = (x-t) * (t < x);\nSMOOTH(a, r, prevx, x) =\n\t(x     *      select2( (x < prevx), a, r )) +\n\t(prevx * (1 - select2( (x < prevx), a, r)));\nDETECTOR = (\tCOEFF2DB :\n\t\tTHRESH(threshold) :\n\t\tSMOOTH(attack, release) ~ _ );\nRATIO(x) = 0 - (x - (x/ratio));\ntime_ratio_target = 1.5;\ntime_ratio_target_atk = 8.0;\ntime_ratio_target_rel = 1.5;\ntime_ratio_attack(t) = exp(1) / ( t * ma.SR * time_ratio_target_atk );\ntime_ratio_release(t) = exp(1) / ( t * ma.SR * time_ratio_target_rel );\nDRYWET(ratio) = ( *(1 - ratio),  * (ratio)) : +;\nDRYWET_STEREO(l, r, ratio) = ( (DRYWET(l, ratio)), (DRYWET(r, ratio)));\nRATELIMITER_INTERNAL(maximum_rate,pt, ct, prevx, x) =\n     select2( abs(ct-pt) > maximum_rate, x,\n              prevx - pt + maximum_rate * select2( (x < prevx), 1.0, -1.0) );\nOVERSHOOT_CORRECTION(limited_gain, target_gain, tangent) =\n\tselect2( (tangent > 0.0),\n\t\t select2( (limited_gain > target_gain), limited_gain, target_gain),\n\t\t select2( (limited_gain > target_gain), target_gain, limited_gain));\nRATELIMITER(maximum_rate,prevx, x) =\n\t( RATELIMITER_INTERNAL( prevx@1 - prevx, prevx - x, prevx, x,maximum_rate), x, (prevx - x) ) :\n\t  OVERSHOOT_CORRECTION;\nM_LN2 = 0.69314718055994530942;\nbiquad_basics_alpha(bw, omega, sn, cs) =\n\t(omega, sn, cs, sn * ma.sinh( M_LN2 / 2.0 * bw * omega / sn) );\nbiquad_basics(samplerate, bw, cutoff) =\n\t(2.0 * ma.PI * cutoff / samplerate)\n\t<: ( _ <: (_, sin) , cos)\n\t: biquad_basics_alpha(bw);\nbiquad_hp_params_a0r(omega,sn,cs,alpha) =\n\t(omega, sn, cs, alpha, 1.0 / ( 1.0 + alpha));\nbiquad_hp_params_coeffs(omega, sn, cs, alpha, a0r) =\n\t( a0r * ( 1.0 + cs ) * 0.5\n\t, a0r * (-1.0 - cs )\n\t, a0r * ( 1.0 + cs ) * 0.5\n\t, a0r * ( 2.0 * cs )\n\t, a0r * (alpha - 1.0) );\nbiquad_hp_params(samplerate, bw, cutoff) =\n\t  biquad_basics(samplerate, bw, cutoff)\n\t: biquad_hp_params_a0r\n\t: biquad_hp_params_coeffs;\nbiquad_run(y, b0, b1, b2, a1, a2, x) =\n\t(b0 * x@0) + (b1 * x@1) + (b2 * x@2) +\n\t             (a1 * y@0) + (a2 * y@1);\nbiquad_hp(cutoff,x) = (biquad_hp_params(ma.SR, 3.0, cutoff), x) : biquad_run ~ _;\nHPF(freq) =  biquad_hp(freq);\nslidingReduce(N,maxN,op,disabledVal,x) =\npar(i,maxNrBits,fixedDelayOp(1<<i,x)@sumOfPrevDelays(N,maxN,i) :useVal(i)):combine(maxNrBits) with {\n  fixedDelayOp = case {\n    (1,x) => x;\n    (N,x) =>  op(fixedDelayOp(N/2,x) , fixedDelayOp(N/2,x)@(N/2));\n  };\n  sumOfPrevDelays(N,maxN,0) = 0;\n  sumOfPrevDelays(N,maxN,i) = (ba.subseq((allDelays(N,maxN)),0,i):>_) with {\n    allDelays(N,maxN) = par(j, maxNrBits, (1<<j) *  ba.take(j+1,(int2bin(N,maxN))) );\n  };\n  maxNrBits = int2nrOfBits(maxN);\n  combine(2) = op;\n  combine(N) = op(combine(N-1),_);\n  useVal(i) =\n    _<:select2((i==0) & (N==0) ,\n      select2( ba.take(i+1,(int2bin(N,maxN))) , disabledVal,_),\n      _\n    );\n};\nnewSlidingReduce(N,maxN,op,disabledVal,x) =\npar(i,maxNrBits,fixedDelayOp(1<<i,x)@sumOfPrevDelays(N,maxN,i) )\n:switched_combine(N,maxN)\nwith {\n  fixedDelayOp = case {\n    (1,x) => x;\n    (N,x) =>  op(fixedDelayOp(N/2,x) , fixedDelayOp(N/2,x)@(N/2));\n  };\n  sumOfPrevDelays(N,maxN,0) = 0;\n  sumOfPrevDelays(N,maxN,i) = (ba.subseq((allDelays(N,maxN)),0,i):>_) with {\n    allDelays(N,maxN) = par(j, maxNrBits, (1<<j) *  ba.take(j+1,(int2bin(N,maxN))) );\n  };\n  maxNrBits = int2nrOfBits(maxN);\n  combine(0) = 0:!;\n  combine(1) = _;\n  combine(2) = op;\n  combine(N) = op(combine(N-1),_);\n  isUsed(i,n) = int(floor(i/(1<<n))%2);\n  nrOfUsedBits(i,n) = par(j,int2nrOfBits(n),isUsed(i,j)):>_;\n  switched_combine(i,n) =\n    si.bus(int2nrOfBits(n))<:\n      par(j,n,\n        par(k,int2nrOfBits(n),S(isUsed(j+1,k))):combine(nrOfUsedBits(j+1,n))\n      )\n      : par(j, n, _*(i==j+1)):>_\n  with {\n    S(0) = !;\n    S(1) = _;\n  };\n};\nint2bin(N,maxN) = par(i,int2nrOfBits(maxN),int(floor(N/(1<<i)))%2);\nint2nrOfBits(0) = 0;\nint2nrOfBits(maxN) = int(floor(log(maxN)/log(2))+1);\nslidingSumN(n,maxn) = slidingReduce(n,maxn,+,0);\nslidingMaxN(n,maxn) = slidingReduce(n,maxn,max,-INFINITY);\nslidingMinN(n,maxn) = slidingReduce(n,maxn,min,INFINITY);\nslidingMeanN(n,maxn) = slidingSumN(n,maxn)/n;\nslidingRMSn(n,maxn) = pow(2):slidingMeanN(n,maxn) : sqrt;\nINFINITY = 1e30;\nrmsMaxSize = 512;\nMAX_flt = 3.0e38;\nMIN_flt = 1.0e-38;\nmain_group(x) = x;\nmeter_group(x) = x;\nknob_group(x) = x;\ndetector_group(x) = x;\npost_group(x) = x;\nratelimit_group(x) = x;\nshape_group(x) = x;\nout_group(x) = x;\nenvelop = abs : max ~ -(1.0/ma.SR) : max(ba.db2linear(-70)) : ba.linear2db;\nmeter = _;\ndrywet        = detector_group(hslider(\"[99]dry-wet[tooltip: ]\", 1.0, 0.0, 1.0, 0.1));\ningain        = detector_group(hslider(\"[1] Input Gain [unit:dB]   [tooltip: The input signal level is increased by this amount (in dB) to make up for the level lost due to compression]\",0, -40, 40, 0.1) : ba.db2linear : si.smooth(0.999));\npeakRMS       = detector_group(hslider(\"[2] peak/RMS [tooltip: Peak or RMS level detection\",1, 0, 1, 0.001));\nrms_speed     = detector_group(hslider(\"[3]RMS size[tooltip: ]\",96, 1,   rmsMaxSize,   1)*44100/ma.SR);\nthreshold     = detector_group(hslider(\"[4] Threshold [unit:dB]   [tooltip: When the signal level exceeds the Threshold (in dB), its level is compressed according to the Ratio]\", -27.1, -80, 0, 0.1));\nratio         = detector_group(hslider(\"[5] Ratio   [tooltip: A compression Ratio of N means that for each N dB increase in input signal level above Threshold, the output level goes up 1 dB]\", 20, 1, 20, 0.1));\nattack        = detector_group(time_ratio_attack(hslider(\"[6] Attack [unit:ms]   [tooltip: Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new lower target level (the compression `kicking in')]\", 23.7, 0.1, 500, 0.1)/1000)) ;\nrelease       = detector_group(time_ratio_release(hslider(\"[7] Release [unit:ms]   [tooltip: Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new higher target level (the compression 'releasing')]\",0.1, 0.1, 2000, 0.1)/1000));\nhpf_freq      = detector_group( hslider(\"[8]sidechain hpf[tooltip: ]\", 154, 1, 400, 1));\npowerScale(x) =((x>=0)*(1/((x+1):pow(3))))+((x<0)* (((x*-1)+1):pow(3)));\npower          = shape_group(hslider(\"[1]power[tooltip: ]\", 1.881 , -33, 33 , 0.001):powerScale);\nmaxGR          = shape_group(hslider(\"[2] Max Gain Reduction [unit:dB]   [tooltip: The maximum amount of gain reduction]\",-15, -60, 0, 0.1) : ba.db2linear : si.smooth(0.999));\ncurve          = shape_group(hslider(\"[3]curve[tooltip: ]\", 0, -1, 1 , 0.001)*-1);\nshape          = shape_group(((hslider(\"[4]shape[tooltip: ]\", 94, 1, 100 , 0.001)*-1)+101):pow(2));\nfeedFwBw     = out_group(hslider(\"[0]feedback/feedforward[tooltip: ]\", 0, 0, 1 , 0.001));\nhiShelfFreq  = out_group(hslider(\"[1]hi shelf freq[tooltip: ]\",134, 1,   400,   1));\ngainHS       = out_group(hslider(\"[2]gain/hi-shelve crossfade[tooltip: ]\", 0.811, 0, 1 , 0.001));\noutgain      = out_group(hslider(\"[3]output gain (dB)[tooltip: ]\",           0,      -40,   40,   0.1):si.smooth(0.999));\nratelimit      = ratelimit_group(hslider(\"[0]ratelimit amount[tooltip: ]\", 1, 0, 1 , 0.001));\nmaxRateAttack  = ratelimit_group(hslider(\"[1]max attack[unit:dB/s][tooltip: ]\", 1020, 6, 8000 , 1)/ma.SR);\nmaxRateDecay   = ratelimit_group(hslider(\"[2]max decay[unit:dB/s][tooltip: ]\", 3813, 6, 8000 , 1)/ma.SR);\ndecayMult      = ratelimit_group(hslider(\"[3]decayMult[tooltip: ]\", 20000 , 0,20000 , 0.001)/100);\ndecayPower     = ratelimit_group(hslider(\"[4]decayPower[tooltip: ]\", 50, 0, 50 , 0.001));\nIM_size        = ratelimit_group(hslider(\"[5]IM_size[tooltip: ]\",108, 1,   rmsMaxSize,   1)*44100/ma.SR);\npowlim(x,base) = x:max(log(MAX_flt)/log(base)):  min(log(MIN_flt)/log(base));\ngainPlusMeter(gain,dry) = (dry * (gain:meter));\nhiShelfPlusMeter(gain,dry) = (dry :fi.high_shelf(gain:meter:ba.linear2db,hiShelfFreq));\ngainHiShelfCrossfade(crossfade,gain,dry) = (dry * ((gain:meter:ba.linear2db)*(1-crossfade):ba.db2linear)): fi.high_shelf(((gain:ba.linear2db)*crossfade),hiShelfFreq);\ncrossfade(x,a,b) = a*(1-x),b*x : +;\nrmsFade = _<:crossfade(peakRMS,_,slidingRMSn( rms_speed, rmsMaxSize));\ndetector = ((_ <: ( HPF(hpf_freq) :rmsFade: DETECTOR : RATIO : ba.db2linear:min(0.99999):max(MIN_flt)))<:_,_:pow(powlim(power)));\npreRateLim = _;\nmaxGRshaper = _;\ntanshape(amp,x) =(ma.tanh(amp*(x-1)))+1;\ncurve_pow(fact,x) = ((x*(x>0):pow(p))+(x*-1*(x<=0):pow(p)*-1)) with\n{\n    p = exp(fact*10*(log(2)));\n};\nrateLimiter(maxRateAttack,maxRateDecay,prevx,x) = prevx+newtangent:min(0):max(maxGR:ba.linear2db)\nwith {\n    tangent     = x- prevx;\n    avgChange   = abs((tangent@1)-(tangent@2)):slidingMeanN(IM_size,rmsMaxSize)*decayMult:_+1:pow(decayPower)-1;\n    newtangent  = select2(tangent>0,minus,plus):max(maxRateAttack*-1):min(maxRateDecay);\n    plus        = tangent*((abs(avgChange)*-1):ba.db2linear);\n    minus       = tangent;\n    };\nCOMP = detector:maxGRshaper:(_-maxGR)*(1/(1-maxGR)): curve_pow(curve):tanshape(shape):_*(1-maxGR):_+maxGR:ba.linear2db\n<: _,( rateLimiter(maxRateAttack,maxRateDecay) ~ _ ):crossfade(ratelimit) : ba.db2linear;\nblushcomp =_*ingain: (_ <:( crossfade(feedFwBw,_,_),_ : ( COMP , _ ) : gainHiShelfCrossfade(gainHS))~_)*(ba.db2linear(outgain));\nmidStereoBlushComp(x,y) =(x+y)*ingain: ((( (crossfade(feedFwBw,_,_): ( COMP ))<:(_,_)) :((_,(x*ingain):gainHiShelfCrossfade(gainHS)),(_,(y*ingain):gainHiShelfCrossfade(gainHS))))~((_,_):+)):((_*(ba.db2linear(outgain))),(_*(ba.db2linear(outgain))));\nmidBlushComp(x,y) =(x+y)*ingain: (_ <:( crossfade(feedFwBw,_,_),_ : ( COMP , _ ) : gainHiShelfCrossfade(gainHS))~_)\n*(ba.db2linear(outgain))<:((_-(y:fi.high_shelf(0,hiShelfFreq))),(_-(x:fi.high_shelf(0,hiShelfFreq))));\ndetect= (ba.linear2db :\n\t\tTHRESH(threshold)\n\t\t:RATIO);\npredelay = 0.05*ma.SR;\ndelayed(x) = x@predelay;\nprevgain=1;\nlookaheadLimiter(x,prevgain,prevtotal) =\nselect2(goingdown,(prevgain+up:min(0),(prevgain+down))),\n(totaldown:dbmeter)\nwith {\n    dbmeter =ba.db2linear:meter: ba.linear2db;\n    currentlevel = ((abs(x)):ba.linear2db);\n    goingdown = ((currentlevel+prevgain)>(threshold))|(prevgain>prevtotal);\n    down = (totaldown-prevgain)/predelay;\n    totaldown =\n       select2(prevgain>=prevtotal', 0  , newdown  );\n    newdown =\n    min(prevtotal,0-((currentlevel):THRESH(threshold)));\n    up = 800/ma.SR;\n    tangent     = x- prevx;\n    avgChange   = abs((tangent@1)-(tangent@2)):slidingMeanN(IM_size,rmsMaxSize)*decayMult:_+1:pow(decayPower)-1;\n    newtangent  = select2(tangent>0,minus,plus):max(maxRateAttack*-1):min(maxRateDecay);\n    plus        = tangent*((abs(avgChange)*-1):ba.db2linear);\n    minus       = tangent;\n    };\nlimiter(x) = (lookaheadLimiter(x)~(_,_)):((_:ba.db2linear)*x@predelay,!);\nlookaheadLimite(x,prevgain,prevtotal) =\nselect2(abs(x):ba.linear2db-prevgain>threshold,(prevgain+3),(prevgain+4:min(0))),\nselect2(abs(x):ba.linear2db-prevgain>threshold,1,2);\nprocess = blushcomp;"
 },
 {
  "id": "gx-compressor",
  "name": "Compressor",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Albert Graef's compressor/limiter with ratio, threshold, knee, attack and release.",
  "description": "Feed-forward compressor with an envelope detector and a soft knee; Ratio, Threshold, Knee, Attack and Release. A clean, general-purpose compressor for evening out picking dynamics.",
  "author": "Albert Graef",
  "flags": "-double",
  "params": [
   {
    "label": "ratio",
    "min": 1,
    "max": 20,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Compressor/ratio"
   },
   {
    "label": "threshold",
    "min": -96,
    "max": 10,
    "default": -20,
    "step": 0.1,
    "unit": "",
    "path": "/Compressor/threshold"
   },
   {
    "label": "knee",
    "min": 0,
    "max": 20,
    "default": 3,
    "step": 0.1,
    "unit": "",
    "path": "/Compressor/knee"
   },
   {
    "label": "attack",
    "min": 0,
    "max": 1,
    "default": 0.002,
    "step": 0.001,
    "unit": "",
    "path": "/Compressor/attack"
   },
   {
    "label": "release",
    "min": 0,
    "max": 10,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Compressor/release"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/compressor.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Compressor\";\ndeclare category \"Guitar Effects\";\n\n/* Compressor unit. */\n\n//declare name \"compressor -- compressor/limiter unit\";\ndeclare author \"Albert Graef\";\ndeclare version \"1.0\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\n/* Controls. */\n\n// partition the controls into these three groups\ncomp_group(x)\t= hgroup(\"1-compression\", x);\nenv_group(x)\t= vgroup(\"2-envelop\", x);\ngain_group(x)\t= vgroup(\"3-gain\", x);\n\n// compressor controls: ratio, threshold and knee size\nratio\t\t= nentry(\"ratio\", 2, 1, 20, 0.1);\nthreshold\t= nentry(\"threshold\", -20, -96, 10, 0.1);\nknee\t\t= nentry(\"knee\", 3, 0, 20, 0.1);\n\n// attack and release controls; clamped to a minimum of 1 sample\nattack\t\t= hslider(\"attack\", 0.002, 0, 1, 0.001) : max(1/ma.SR);\nrelease\t\t= hslider(\"release\", 0.5, 0, 10, 0.01) : max(1/ma.SR);\n\n// gain controls: make-up gain, compression gain meter\nmakeup_gain\t= gain_group(hslider(\"makeup gain\", 0, -96, 96, 0.1));\ngain(x)\t\t= attach(x, x : gain_group(hbargraph(\"gain\", -96, 0)));\n\nt\t\t= 0.1;\ng\t\t= exp(-1/(ma.SR*t));\nenv\t\t= abs : *(1-g) : + ~ *(g);\nrms\t\t= sqr : *(1-g) : + ~ *(g) : sqrt;\nsqr(x)\t\t= x*x;\n\n/* Compute the envelop of a stereo signal. Replace env with rms ba.if you want to\n   use the RMS value instead. */\n\n//env2(x,y)\t= max(env(x),env(y));\nenv2(x)\t= max(env(x));\n\n/* Compute the compression factor for the current input level. The gain is\n   always 0 dB ba.if we're below the reduced threshold, threshold-knee. Beyond\n   the real threshold value the level is scaled by 1/ratio. Between these two\n   extremes we return a convex combination of those factors. This is also\n   known as \"soft-knee\" compression: the compression kicks in gradually at\n   threshold-knee and reaches its full value at threshold. For special\n   effects, you can also achieve old-school \"hard-knee\" compression by setting\n   the knee value to fi.zero. Also note that, before computing the gain, the\n   input level is first smoothed out using a 1 fi.pole IIR to prevent clicks when\n   the input level changes abruptly. The attack and release times of this\n   filter are configured with the corresponding envelop controls of the\n   compressor. */\n\ncompress(env)\t= level*(1-r)/r\nwith {\n\t// the (filtered) input level above the threshold\n\tlevel\t= env : h ~ _ : ba.linear2db : (_-threshold+knee) : max(0)\n\twith {\n\t\th(x,y)\t= f*x+(1-f)*y with { f = (x<y)*ga+(x>=y)*gr; };\n\t\tga\t= exp(-1/(ma.SR*attack));\n\t\tgr\t= exp(-1/(ma.SR*release));\n\t};\n\t// the knee factor, clamped to 0..1; we add a small perturbation in\n\t// the denominator to prevent infinities and nan when knee<<1\n\tp\t= level/(knee+eps) : max(0) : min(1) with { eps = 0.001; };\n\t// the actual compression ratio\n\tr\t= 1-p+p*ratio;\n};\n\nprocess(x)\t= g(x)*x\nwith {\n\t//g\t= env2(x) : compress : gain : +(makeup_gain) : ba.db2linear ;\n\tg\t= add_dc : env : compress : ba.db2linear ;\n};"
 },
 {
  "id": "gx-expander",
  "name": "Expander",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Downward expander that attenuates signals below the threshold; gentle noise reduction.",
  "description": "The compressor in reverse: applies Ratio to attenuate levels below Threshold with a soft Knee, Attack and Release. Use it as a subtle gate to tame hum and hiss between phrases.",
  "author": "Albert Graef",
  "flags": "-double",
  "params": [
   {
    "label": "ratio",
    "min": 1,
    "max": 20,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Expander/ratio"
   },
   {
    "label": "threshold",
    "min": -96,
    "max": 10,
    "default": -40,
    "step": 0.1,
    "unit": "",
    "path": "/Expander/threshold"
   },
   {
    "label": "knee",
    "min": 0,
    "max": 20,
    "default": 3,
    "step": 0.1,
    "unit": "",
    "path": "/Expander/knee"
   },
   {
    "label": "attack",
    "min": 0,
    "max": 1,
    "default": 0.001,
    "step": 0.001,
    "unit": "",
    "path": "/Expander/attack"
   },
   {
    "label": "release",
    "min": 0,
    "max": 10,
    "default": 0.1,
    "step": 0.01,
    "unit": "",
    "path": "/Expander/release"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/expander.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n\n/* Expander unit. */\n\n/* This is pretty much the same as compressor.dsp, but here the given ratio is\n   applied to *attenuate* levels *below* the threshold. */\n\ndeclare name \"Expander\";\ndeclare category \"Guitar Effects\";\n\ndeclare description \"expander unit\";\ndeclare author \"Albert Graef\";\ndeclare version \"1.0\";\n\nimport(\"stdfaust.lib\");\n\n/* Controls. */\n\nratio\t\t= nentry(\"ratio\", 2, 1, 20, 0.1);\nthreshold\t= nentry(\"threshold\", -40, -96, 10, 0.1);\nknee\t\t= nentry(\"knee\", 3, 0, 20, 0.1);\n\nattack\t\t= hslider(\"attack\", 0.001, 0, 1, 0.001) : max(1/ma.SR);\nrelease\t\t= hslider(\"release\", 0.1, 0, 10, 0.01) : max(1/ma.SR);\n\nt\t\t= 0.1;\ng\t\t= exp(-1/(ma.SR*t));\nenv\t\t= abs : *(1-g) : + ~ *(g);\nrms\t\t= sqr : *(1-g) : + ~ *(g) : sqrt;\nsqr(x)\t\t= x*x;\n\nenv2(x)\t= max(env(x));\n\nexpand(env)\t= level*(1-r)\nwith {\n\tlevel\t= env : h ~ _ : ba.linear2db : (threshold+knee-_) : max(0)\n\twith {\n\t\th(x,y)\t= f*x+(1-f)*y with { f = (x<y)*ga+(x>=y)*gr; };\n\t\tga\t= exp(-1/(ma.SR*attack));\n\t\tgr\t= exp(-1/(ma.SR*release));\n\t};\n\tp\t= level/(knee+eps) : max(0) : min(1) with { eps = 0.001; };\n\tr\t= 1-p+p*ratio;\n};\n\nprocess(x)\t= (g(x)*x)\nwith {\n\tg\t= env2(x) : expand : ba.db2linear;\n};"
 },
 {
  "id": "lib-expander",
  "name": "Expander",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "GPL-3.0-only",
  "shortDesc": "Downward expander (co.expander_N_chan) with range, hold and knee - tightens noise between notes",
  "description": "Downward expander (co.expander_N_chan) with range, hold and knee - tightens noise between notes",
  "author": "Bart Brouns",
  "flags": "",
  "params": [
   {
    "label": "Strength",
    "min": 0.1,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Expander/Strength"
   },
   {
    "label": "Threshold",
    "min": -80,
    "max": 0,
    "default": -40,
    "step": 0.1,
    "unit": "dB",
    "path": "/Expander/Threshold"
   },
   {
    "label": "Range",
    "min": 0,
    "max": 80,
    "default": 40,
    "step": 1,
    "unit": "dB",
    "path": "/Expander/Range"
   },
   {
    "label": "Attack",
    "min": 0.1,
    "max": 100,
    "default": 2,
    "step": 0.1,
    "unit": "ms",
    "path": "/Expander/Attack"
   },
   {
    "label": "Hold",
    "min": 0,
    "max": 500,
    "default": 20,
    "step": 1,
    "unit": "ms",
    "path": "/Expander/Hold"
   },
   {
    "label": "Release",
    "min": 10,
    "max": 1000,
    "default": 100,
    "step": 1,
    "unit": "ms",
    "path": "/Expander/Release"
   },
   {
    "label": "Knee",
    "min": 0,
    "max": 24,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/Expander/Knee"
   }
  ],
  "faustCode": "declare name \"Expander\";\ndeclare description \"Downward expander (co.expander_N_chan) with range, hold and knee - tightens noise between notes\";\ndeclare author \"Bart Brouns\";\ndeclare license \"GPL-3.0-only\";\ndeclare source \"grame-cncm/faustlibraries/compressors.lib co.expander_N_chan\";\ndeclare category \"guitar\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\nstrength = hslider(\"[0] Strength\", 2, 0.1, 10, 0.1) : si.smoo;\nthresh   = hslider(\"[1] Threshold[unit:dB]\", -40, -80, 0, 0.1) : si.smoo;\nrange    = hslider(\"[2] Range[unit:dB]\", 40, 0, 80, 1) : *(-1);\natt      = hslider(\"[3] Attack[unit:ms]\", 2, 0.1, 100, 0.1) : /(1000);\nhold     = hslider(\"[4] Hold[unit:ms]\", 20, 0, 500, 1) : /(1000);\nrel      = hslider(\"[5] Release[unit:ms]\", 100, 10, 1000, 1) : /(1000);\nknee     = hslider(\"[6] Knee[unit:dB]\", 6, 0, 24, 0.1) : si.smoo;\nprocess = co.expander_N_chan(strength, thresh, range, att, hold, rel, knee, 0, 0, _, 24000, 1);"
 },
 {
  "id": "lib-fb-compressor",
  "name": "FB Compressor",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "GPL-3.0-only",
  "shortDesc": "Bart Brouns feed-back peak compressor - vintage-style program-dependent behaviour",
  "description": "Bart Brouns feed-back peak compressor - vintage-style program-dependent behaviour",
  "author": "Bart Brouns",
  "flags": "",
  "params": [
   {
    "label": "Strength",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/FB_Compressor/Strength"
   },
   {
    "label": "Threshold",
    "min": -60,
    "max": 0,
    "default": -24,
    "step": 0.1,
    "unit": "dB",
    "path": "/FB_Compressor/Threshold"
   },
   {
    "label": "Attack",
    "min": 0.1,
    "max": 100,
    "default": 5,
    "step": 0.1,
    "unit": "ms",
    "path": "/FB_Compressor/Attack"
   },
   {
    "label": "Release",
    "min": 10,
    "max": 1000,
    "default": 150,
    "step": 1,
    "unit": "ms",
    "path": "/FB_Compressor/Release"
   },
   {
    "label": "Knee",
    "min": 0,
    "max": 24,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/FB_Compressor/Knee"
   },
   {
    "label": "Makeup",
    "min": 0,
    "max": 30,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/FB_Compressor/Makeup"
   }
  ],
  "faustCode": "declare name \"FB Compressor\";\ndeclare description \"Bart Brouns feed-back peak compressor - vintage-style program-dependent behaviour\";\ndeclare author \"Bart Brouns\";\ndeclare license \"GPL-3.0-only\";\ndeclare source \"grame-cncm/faustlibraries/compressors.lib co.FBcompressor_N_chan\";\ndeclare category \"guitar\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\nstrength = hslider(\"[0] Strength\", 0.6, 0, 1, 0.01) : si.smoo;\nthresh   = hslider(\"[1] Threshold[unit:dB]\", -24, -60, 0, 0.1) : si.smoo;\natt      = hslider(\"[2] Attack[unit:ms]\", 5, 0.1, 100, 0.1) : /(1000);\nrel      = hslider(\"[3] Release[unit:ms]\", 150, 10, 1000, 1) : /(1000);\nknee     = hslider(\"[4] Knee[unit:dB]\", 6, 0, 24, 0.1) : si.smoo;\nmakeup   = hslider(\"[5] Makeup[unit:dB]\", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;\nprocess = co.FBcompressor_N_chan(strength, thresh, att, rel, knee, 0, 0, _, 1) : *(makeup);"
 },
 {
  "id": "lib-ff-compressor",
  "name": "FF Compressor",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "GPL-3.0-only",
  "shortDesc": "Bart Brouns feed-forward peak compressor with strength, knee and attack/release - transparent squash",
  "description": "Bart Brouns feed-forward peak compressor with strength, knee and attack/release - transparent squash",
  "author": "Bart Brouns",
  "flags": "",
  "params": [
   {
    "label": "Strength",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/FF_Compressor/Strength"
   },
   {
    "label": "Threshold",
    "min": -60,
    "max": 0,
    "default": -24,
    "step": 0.1,
    "unit": "dB",
    "path": "/FF_Compressor/Threshold"
   },
   {
    "label": "Attack",
    "min": 0.1,
    "max": 100,
    "default": 5,
    "step": 0.1,
    "unit": "ms",
    "path": "/FF_Compressor/Attack"
   },
   {
    "label": "Release",
    "min": 10,
    "max": 1000,
    "default": 120,
    "step": 1,
    "unit": "ms",
    "path": "/FF_Compressor/Release"
   },
   {
    "label": "Knee",
    "min": 0,
    "max": 24,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/FF_Compressor/Knee"
   },
   {
    "label": "Makeup",
    "min": 0,
    "max": 30,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/FF_Compressor/Makeup"
   }
  ],
  "faustCode": "declare name \"FF Compressor\";\ndeclare description \"Bart Brouns feed-forward peak compressor with strength, knee and attack/release - transparent squash\";\ndeclare author \"Bart Brouns\";\ndeclare license \"GPL-3.0-only\";\ndeclare source \"grame-cncm/faustlibraries/compressors.lib co.FFcompressor_N_chan\";\ndeclare category \"guitar\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\nstrength = hslider(\"[0] Strength\", 0.6, 0, 1, 0.01) : si.smoo;\nthresh   = hslider(\"[1] Threshold[unit:dB]\", -24, -60, 0, 0.1) : si.smoo;\natt      = hslider(\"[2] Attack[unit:ms]\", 5, 0.1, 100, 0.1) : /(1000);\nrel      = hslider(\"[3] Release[unit:ms]\", 120, 10, 1000, 1) : /(1000);\nknee     = hslider(\"[4] Knee[unit:dB]\", 6, 0, 24, 0.1) : si.smoo;\nmakeup   = hslider(\"[5] Makeup[unit:dB]\", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;\nprocess = co.FFcompressor_N_chan(strength, thresh, att, rel, knee, 0, 0, _, 1) : *(makeup);"
 },
 {
  "id": "ex-granular-gate",
  "name": "Granular Gate",
  "category": "drum",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "DrumBrute / Volca",
  "source": "Faust examples",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Bela granulator example turned into a rhythmic stutter gate: the input is chopped by probabilistic noise-burst envelopes at a settable rate and grain size",
  "description": "Bela granulator example turned into a rhythmic stutter gate: the input is chopped by probabilistic noise-burst envelopes at a settable rate and grain size",
  "author": "Christophe Lebreton (sfIter), adapted by GRAME",
  "flags": "",
  "params": [
   {
    "label": "Grain Size",
    "min": 5,
    "max": 2205,
    "default": 200,
    "step": 1,
    "unit": "",
    "path": "/Granular_Gate/Grain_Size"
   },
   {
    "label": "Speed",
    "min": 1,
    "max": 20,
    "default": 10,
    "step": 0.01,
    "unit": "",
    "path": "/Granular_Gate/Speed"
   },
   {
    "label": "Probability",
    "min": 50,
    "max": 100,
    "default": 70,
    "step": 1,
    "unit": "",
    "path": "/Granular_Gate/Probability"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Granular_Gate/Mix"
   }
  ],
  "faustCode": "declare name \"Granular Gate\";\ndeclare description \"Bela granulator example turned into a rhythmic stutter gate: the input is chopped by probabilistic noise-burst envelopes at a settable rate and grain size\";\ndeclare author \"Christophe Lebreton (sfIter), adapted by GRAME\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faust/examples/bela/granulator.dsp\";\ndeclare category \"drum\";\ndeclare family \"utility\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"[0] Grain Size\", 200, 5, 2205, 1);\nspeed = hslider(\"[1] Speed\", 10, 1, 20, 0.01) : fi.lowpass(1, 1);\nproba = hslider(\"[2] Probability\", 70, 50, 100, 1)*(0.01) : fi.lowpass(1, 1);\nmix   = hslider(\"[3] Mix\", 1, 0, 1, 0.01) : si.smoo;\n\nexcitation = noiseburst(gate, P);\nampf = an.amp_follower_ud(duree_env, duree_env);\nnoiseburst(gate, P) = no.noise : *(gate : trigger(P))\n    with {\n        upfront(x) = (x-x')>0;\n        decay(n, x) = x-(x>0)/n;\n        release(n) = +~decay(n);\n        trigger(n) = upfront : release(n) : >(0.0);\n    };\nP = freq;\nphasor_bin(init) = (+(float(speed)/float(ma.SR)) : fmod(_, 1.0)) ~ *(init);\ngate = phasor_bin(1) : -(0.001) : pulsar;\npulsar = _ <: ((_<(ratio_env)) : @(100))*(proba>(_, abs(no.noise) : ba.latch));\nratio_env = 0.5;\nfade = 0.5;\nduree_env = 1/(speed : /(ratio_env*(0.25)*fade));\nenv = excitation : ampf : min(1) : *(3) : min(1);\nprocess = _ <: *(1-mix), (*(env) : *(mix)) :> _;"
 },
 {
  "id": "lib-jos-compressor",
  "name": "JOS Compressor",
  "category": "drum",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "DrumBrute / Volca",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Classic ratio/threshold/attack/release compressor (co.compressor_mono) with makeup - the Faust textbook compressor",
  "description": "Classic ratio/threshold/attack/release compressor (co.compressor_mono) with makeup - the Faust textbook compressor",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Ratio",
    "min": 1,
    "max": 20,
    "default": 4,
    "step": 0.1,
    "unit": "",
    "path": "/JOS_Compressor/Ratio"
   },
   {
    "label": "Threshold",
    "min": -60,
    "max": 0,
    "default": -24,
    "step": 0.1,
    "unit": "dB",
    "path": "/JOS_Compressor/Threshold"
   },
   {
    "label": "Attack",
    "min": 0.1,
    "max": 500,
    "default": 10,
    "step": 0.1,
    "unit": "ms",
    "path": "/JOS_Compressor/Attack"
   },
   {
    "label": "Release",
    "min": 1,
    "max": 1000,
    "default": 150,
    "step": 1,
    "unit": "ms",
    "path": "/JOS_Compressor/Release"
   },
   {
    "label": "Makeup",
    "min": 0,
    "max": 30,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/JOS_Compressor/Makeup"
   }
  ],
  "faustCode": "declare name \"JOS Compressor\";\ndeclare description \"Classic ratio/threshold/attack/release compressor (co.compressor_mono) with makeup - the Faust textbook compressor\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faust/examples/dynamic/compressor.dsp co.compressor_mono\";\ndeclare category \"drum\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\nratio  = hslider(\"[0] Ratio\", 4, 1, 20, 0.1);\nthresh = hslider(\"[1] Threshold[unit:dB]\", -24, -60, 0, 0.1);\natt    = hslider(\"[2] Attack[unit:ms]\", 10, 0.1, 500, 0.1) : /(1000);\nrel    = hslider(\"[3] Release[unit:ms]\", 150, 1, 1000, 1) : /(1000);\nmakeup = hslider(\"[4] Makeup[unit:dB]\", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;\nprocess = co.compressor_mono(ratio, thresh, att, rel) : *(makeup);"
 },
 {
  "id": "kpp-deadgate",
  "name": "KPP Dead Gate",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "KPP",
  "license": "GPL-3.0-or-later",
  "shortDesc": "Aggressive noise gate: instant dead-zone clamp plus a 7-band multiband gate (10 ms attack, 20 ms hold/release)",
  "description": "Aggressive noise gate: instant dead-zone clamp plus a 7-band multiband gate (10 ms attack, 20 ms hold/release)",
  "author": "Oleg Kapitonov",
  "flags": "",
  "params": [
   {
    "label": "Dead Zone",
    "min": -120,
    "max": 0,
    "default": -60,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Dead_Gate/Dead_Zone"
   },
   {
    "label": "Noise Gate",
    "min": -120,
    "max": 0,
    "default": -60,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Dead_Gate/Noise_Gate"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Dead_Gate/Level"
   }
  ],
  "faustCode": "declare name \"KPP Dead Gate\";\ndeclare description \"Aggressive noise gate: instant dead-zone clamp plus a 7-band multiband gate (10 ms attack, 20 ms hold/release)\";\ndeclare author \"Oleg Kapitonov\";\ndeclare license \"GPL-3.0-or-later\";\ndeclare source \"olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_deadgate/kpp_deadgate.dsp\";\ndeclare category \"guitar\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\ndeadzone_knob  = hslider(\"[0] Dead Zone[unit:dB]\", -60, -120, 0, 0.1) : ba.db2linear;\nnoizegate_knob = hslider(\"[1] Noise Gate[unit:dB]\", -60, -120, 0, 0.1);\nlevel = hslider(\"[2] Level[unit:dB]\", 0, -20, 20, 0.1);\ndeadzone = _ <: (max(deadzone_knob) : -(deadzone_knob)), (min(-deadzone_knob) : +(deadzone_knob)) : +;\nmultigate = fi.filterbank(3, (65, 150, 300, 600, 1200, 2400)) : par(i, 7, ef.gate_mono(noizegate_knob, 0.01, 0.02, 0.02)) :> _;\nprocess = fi.highpass(1,10) : deadzone : multigate : *(ba.db2linear(level));"
 },
 {
  "id": "lib-lookahead-limiter",
  "name": "Lookahead Limiter",
  "category": "drum",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "DrumBrute / Volca",
  "source": "faustlibraries",
  "license": "GPL-3.0-only",
  "shortDesc": "Dario Sanfilippo's IEM-style lookahead brickwall limiter with ceiling, hold and release",
  "description": "Dario Sanfilippo's IEM-style lookahead brickwall limiter with ceiling, hold and release",
  "author": "Dario Sanfilippo",
  "flags": "",
  "params": [
   {
    "label": "Input",
    "min": 0,
    "max": 40,
    "default": 12,
    "step": 0.1,
    "unit": "dB",
    "path": "/Lookahead_Limiter/Input"
   },
   {
    "label": "Ceiling",
    "min": -20,
    "max": 0,
    "default": -1,
    "step": 0.1,
    "unit": "dB",
    "path": "/Lookahead_Limiter/Ceiling"
   },
   {
    "label": "Attack",
    "min": 0.5,
    "max": 6,
    "default": 3,
    "step": 0.1,
    "unit": "ms",
    "path": "/Lookahead_Limiter/Attack"
   },
   {
    "label": "Hold",
    "min": 0,
    "max": 500,
    "default": 30,
    "step": 1,
    "unit": "ms",
    "path": "/Lookahead_Limiter/Hold"
   },
   {
    "label": "Release",
    "min": 5,
    "max": 1000,
    "default": 100,
    "step": 1,
    "unit": "ms",
    "path": "/Lookahead_Limiter/Release"
   }
  ],
  "faustCode": "declare name \"Lookahead Limiter\";\ndeclare description \"Dario Sanfilippo's IEM-style lookahead brickwall limiter with ceiling, hold and release\";\ndeclare author \"Dario Sanfilippo\";\ndeclare license \"GPL-3.0-only\";\ndeclare source \"grame-cncm/faustlibraries/compressors.lib co.limiter_lad_N\";\ndeclare category \"drum\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\ningain  = hslider(\"[0] Input[unit:dB]\", 12, 0, 40, 0.1) : ba.db2linear : si.smoo;\nceiling = hslider(\"[1] Ceiling[unit:dB]\", -1, -20, 0, 0.1) : ba.db2linear;\natt     = hslider(\"[2] Attack[unit:ms]\", 3, 0.5, 6, 0.1) : /(1000);\nhold    = hslider(\"[3] Hold[unit:ms]\", 30, 0, 500, 1) : /(1000);\nrel     = hslider(\"[4] Release[unit:ms]\", 100, 5, 1000, 1) : /(1000);\nprocess = *(ingain) : co.limiter_lad_N(1, 0.01, ceiling, att, hold, rel);"
 },
 {
  "id": "gx-mbc",
  "name": "Multi-Band Compressor",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Five-band compressor with per-band ratio, threshold, makeup, attack, release and mode.",
  "description": "Splits the signal at four adjustable crossovers and compresses each band independently with Ratio, Makeup, Threshold, Attack, Release and a per-band Mode. Controls dynamics per frequency range without pumping the whole signal.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Makeup1",
    "min": -50,
    "max": 50,
    "default": 13,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Makeup1"
   },
   {
    "label": "Makeup2",
    "min": -50,
    "max": 50,
    "default": 10,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Makeup2"
   },
   {
    "label": "Makeup3",
    "min": -50,
    "max": 50,
    "default": 4,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Makeup3"
   },
   {
    "label": "Makeup4",
    "min": -50,
    "max": 50,
    "default": 8,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Makeup4"
   },
   {
    "label": "Makeup5",
    "min": -50,
    "max": 50,
    "default": 11,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Makeup5"
   },
   {
    "label": "MakeupThreshold1",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/MakeupThreshold1"
   },
   {
    "label": "MakeupThreshold2",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/MakeupThreshold2"
   },
   {
    "label": "MakeupThreshold3",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/MakeupThreshold3"
   },
   {
    "label": "MakeupThreshold4",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/MakeupThreshold4"
   },
   {
    "label": "MakeupThreshold5",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/MakeupThreshold5"
   },
   {
    "label": "Ratio1",
    "min": 1,
    "max": 100,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Ratio1"
   },
   {
    "label": "Ratio2",
    "min": 1,
    "max": 100,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Ratio2"
   },
   {
    "label": "Ratio3",
    "min": 1,
    "max": 100,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Ratio3"
   },
   {
    "label": "Ratio4",
    "min": 1,
    "max": 100,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Ratio4"
   },
   {
    "label": "Ratio5",
    "min": 1,
    "max": 100,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Ratio5"
   },
   {
    "label": "Attack1",
    "min": 0.001,
    "max": 1,
    "default": 0.012,
    "step": 0.001,
    "unit": "",
    "path": "/Multi_Band_Compressor/Attack1"
   },
   {
    "label": "Attack2",
    "min": 0.001,
    "max": 1,
    "default": 0.012,
    "step": 0.001,
    "unit": "",
    "path": "/Multi_Band_Compressor/Attack2"
   },
   {
    "label": "Attack3",
    "min": 0.001,
    "max": 1,
    "default": 0.012,
    "step": 0.001,
    "unit": "",
    "path": "/Multi_Band_Compressor/Attack3"
   },
   {
    "label": "Attack4",
    "min": 0.001,
    "max": 1,
    "default": 0.012,
    "step": 0.001,
    "unit": "",
    "path": "/Multi_Band_Compressor/Attack4"
   },
   {
    "label": "Attack5",
    "min": 0.001,
    "max": 1,
    "default": 0.012,
    "step": 0.001,
    "unit": "",
    "path": "/Multi_Band_Compressor/Attack5"
   },
   {
    "label": "Release1",
    "min": 0.01,
    "max": 10,
    "default": 1.25,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Compressor/Release1"
   },
   {
    "label": "Release2",
    "min": 0.01,
    "max": 10,
    "default": 1.25,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Compressor/Release2"
   },
   {
    "label": "Release3",
    "min": 0.01,
    "max": 10,
    "default": 1.25,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Compressor/Release3"
   },
   {
    "label": "Release4",
    "min": 0.01,
    "max": 10,
    "default": 1.25,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Compressor/Release4"
   },
   {
    "label": "Release5",
    "min": 0.01,
    "max": 10,
    "default": 1.25,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Compressor/Release5"
   },
   {
    "label": "Mode1",
    "min": 1,
    "max": 3,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Mode1"
   },
   {
    "label": "Mode2",
    "min": 1,
    "max": 3,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Mode2"
   },
   {
    "label": "Mode3",
    "min": 1,
    "max": 3,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Mode3"
   },
   {
    "label": "Mode4",
    "min": 1,
    "max": 3,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Mode4"
   },
   {
    "label": "Mode5",
    "min": 1,
    "max": 3,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Compressor/Mode5"
   },
   {
    "label": "crossover b1 b2",
    "min": 20,
    "max": 20000,
    "default": 80,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Compressor/crossover_b1_b2"
   },
   {
    "label": "crossover b2 b3",
    "min": 20,
    "max": 20000,
    "default": 210,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Compressor/crossover_b2_b3"
   },
   {
    "label": "crossover b3 b4",
    "min": 20,
    "max": 20000,
    "default": 1700,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Compressor/crossover_b3_b4"
   },
   {
    "label": "crossover b4 b5",
    "min": 20,
    "max": 20000,
    "default": 5000,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Compressor/crossover_b4_b5"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/mbc.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"mbc\";\ndeclare name \"Multi Band Compressor\";\ndeclare shortname \"MB Compressor\";\ndeclare category \"Guitar Effects\";\ndeclare description \"Multi Band Compressor contributed by kokoko3k\";\n\nimport(\"stdfaust.lib\");\nrd = library(\"reducemaps.lib\");\n\nvmeter1(x)\t\t= attach(x, envelop(x) : vbargraph(\"v1[tooltip:no]\", -70, +5));\nvmeter2(x)\t\t= attach(x, envelop(x) : vbargraph(\"v2[tooltip:no]\", -70, +5));\nvmeter3(x)\t\t= attach(x, envelop(x) : vbargraph(\"v3[tooltip:no]\", -70, +5));\nvmeter4(x)\t\t= attach(x, envelop(x) : vbargraph(\"v4[tooltip:no]\", -70, +5));\nvmeter5(x)\t\t= attach(x, envelop(x) : vbargraph(\"v5[tooltip:no]\", -70, +5));\nvmeter6(x)\t\t= attach(x, envelop(x) : vbargraph(\"v6[tooltip:no]\", -70, +5));\nvmeter7(x)\t\t= attach(x, envelop(x) : vbargraph(\"v7[tooltip:no]\", -70, +5));\nvmeter8(x)\t\t= attach(x, envelop(x) : vbargraph(\"v8[tooltip:no]\", -70, +5));\nvmeter9(x)\t\t= attach(x, envelop(x) : vbargraph(\"v9[tooltip:no]\", -70, +5));\nvmeter10(x)\t\t= attach(x, envelop(x) : vbargraph(\"v10[tooltip:no]\", -70, +5));\n\nenvelop         = abs : max ~ (1.0/ma.SR) : rd.maxn(4096) ;\n//envelop         = abs : max ~ (1.0/ma.SR) : mean(4096) ; // : max(ba.db2linear(-70)) : ba.linear2db;\n\n//Mono \nprocess =   geq : ( gcomp5s , gcomp4s , gcomp3s, gcomp2s, gcomp1s) :>_ with { \ngcomp1s = vmeter6:ba.bypass1(bswitch1,co.compressor_mono(ratio1,-push1,attack1,release1)):*(Makeup1) : vmeter1;\ngcomp2s = vmeter7:ba.bypass1(bswitch2,co.compressor_mono(ratio2,-push2,attack2,release2)):*(Makeup2) : vmeter2;\ngcomp3s = vmeter8:ba.bypass1(bswitch3,co.compressor_mono(ratio3,-push3,attack3,release3)):*(Makeup3) : vmeter3;\ngcomp4s = vmeter9:ba.bypass1(bswitch4,co.compressor_mono(ratio4,-push4,attack4,release4)):*(Makeup4) : vmeter4;\ngcomp5s = vmeter10:ba.bypass1(bswitch5,co.compressor_mono(ratio5,-push5,attack5,release5)):*(Makeup5) : vmeter5;\n};\n\nsel1         = hslider(\"Mode1[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]\",1,1,3,1);\nsel2         = hslider(\"Mode2[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]\",1,1,3,1);\nsel3         = hslider(\"Mode3[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]\",1,1,3,1);\nsel4         = hslider(\"Mode4[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]\",1,1,3,1);\nsel5         = hslider(\"Mode5[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]\",1,1,3,1);\n\nnot(x) \t= abs(x-1);\nmute1\t\t= not(max(0,sel1-2));\nmute2\t\t= not(max(0,sel2-2));\nmute3\t\t= not(max(0,sel3-2));\nmute4\t\t= not(max(0,sel4-2));\nmute5\t\t= not(max(0,sel5-2));\n\nbypass(switch, block) = _ <: select2(switch, _, block);\n\nbswitch1\t= max(0,sel1-1);\nbswitch2\t= max(0,sel2-1);\nbswitch3\t= max(0,sel3-1);\nbswitch4\t= max(0,sel4-1);\nbswitch5\t= max(0,sel5-1);\n\nhifr1\t\t\t=hslider(\"crossover_b1_b2 [log][name:Crossover B1-B2 (hz)][tooltip: Crossover fi.bandpass frequency]\" ,80 , 20, 20000, 1.08);\nhifr2\t\t\t=hslider(\"crossover_b2_b3 [log][name:Crossover B2-B3 (hz)][tooltip: Crossover fi.bandpass frequency]\",210,20,20000,1.08);\nhifr3\t\t\t=hslider(\"crossover_b3_b4 [log][name:Crossover B3-B4 (hz)][tooltip: Crossover fi.bandpass frequency]\",1700,20,20000,1.08);\nhifr4\t\t\t=hslider(\"crossover_b4_b5 [log][name:Crossover B4-B5 (hz)][tooltip: Crossover fi.bandpass frequency]\",5000,20,20000,1.08);\n\ngeq = fi.filterbank(3, (hifr1,hifr2,hifr3,hifr4));\n\nratio1 \t\t= hslider(\"[9] Ratio1 [tooltip: Compression ratio]\",2,1,100,0.1);\nattack1\t\t= hslider(\"[A] Attack1 [tooltip: Time before the compressor starts to kick in]\", 0.012, 0.001, 1, 0.001);\nrelease1 \t= hslider(\"[B] Release1 [tooltip: Time before the compressor releases the sound]\", 1.25, 0.01, 10, 0.01);\n\nratio2 \t\t= hslider(\"[9] Ratio2 [tooltip: Compression ratio]\",2,1,100,0.1);\nattack2\t\t= hslider(\"[A] Attack2 [tooltip: Time before the compressor starts to kick in]\", 0.012, 0.001, 1, 0.001);\nrelease2 \t= hslider(\"[B] Release2 [tooltip: Time before the compressor releases the sound]\", 1.25, 0.01, 10, 0.01);\n\nratio3 \t\t= hslider(\"[9] Ratio3 [tooltip: Compression ratio]\",2,1,100,0.1);\nattack3\t\t= hslider(\"[A] Attack3 [tooltip: Time before the compressor starts to kick in]\", 0.012, 0.001, 1, 0.001);\nrelease3 \t= hslider(\"[B] Release3 [tooltip: Time before the compressor releases the sound]\", 1.25, 0.01, 10, 0.01);\n\nratio4 \t\t= hslider(\"[9] Ratio4 [tooltip: Compression ratio]\",2,1,100,0.1);\nattack4\t\t= hslider(\"[A] Attack4 [tooltip: Time before the compressor starts to kick in]\", 0.012, 0.001, 1, 0.001);\nrelease4 \t= hslider(\"[B] Release4 [tooltip: Time before the compressor releases the sound]\", 1.25, 0.01, 10, 0.01);\n\nratio5 \t\t= hslider(\"[9] Ratio5 [tooltip: Compression ratio]\",2,1,100,0.1);\nattack5\t\t= hslider(\"[A] Attack5 [tooltip: Time before the compressor starts to kick in]\", 0.012, 0.001, 1, 0.001);\nrelease5 \t= hslider(\"[B] Release5 [tooltip: Time before the compressor releases the sound]\", 1.25, 0.01, 10, 0.01);\n\npush1 \t\t= hslider(\"[5] Makeup1 [tooltip: Post amplification and threshold]\"   , 13, -50, +50, 0.1) ; // threshold-=push ;  makeup+=push\npush2 \t\t= hslider(\"[5] Makeup2 [tooltip: Post amplification and threshold]\"   , 10, -50, +50, 0.1) ; // threshold-=push ;  makeup+=push\npush3 \t\t= hslider(\"[5] Makeup3 [tooltip: Post amplification and threshold]\"   , 4,  -50, +50, 0.1) ; // threshold-=push ;  makeup+=push\npush4 \t\t= hslider(\"[5] Makeup4 [tooltip: Post amplification and threshold]\"   , 8,  -50, +50, 0.1) ; // threshold-=push ;  makeup+=push\npush5 \t\t= hslider(\"[5] Makeup5 [tooltip: Post amplification and threshold]\"   , 11, -50, +50, 0.1) ; // threshold-=push ;  makeup+=push\n\nsafe1 \t= hslider(\"[6] MakeupThreshold1 [tooltip: Threshold correction, an anticlip measure]\" , 2, 0, +10, 0.1) ; // makeup-=safe\nsafe2 \t= hslider(\"[6] MakeupThreshold2 [tooltip: Threshold correction, an anticlip measure]\" , 2, 0, +10, 0.1) ; // makeup-=safe\nsafe3 \t= hslider(\"[6] MakeupThreshold3 [tooltip: Threshold correction, an anticlip measure]\" , 2, 0, +10, 0.1) ; // makeup-=safe\nsafe4 \t= hslider(\"[6] MakeupThreshold4 [tooltip: Threshold correction, an anticlip measure]\" , 2, 0, +10, 0.1) ; // makeup-=safe\nsafe5 \t= hslider(\"[6] MakeupThreshold5 [tooltip: Threshold correction, an anticlip measure]\" , 2, 0, +10, 0.1) ; // makeup-=safe\n\nMakeup1\t=  mute1* (not(bswitch1)*(push1-safe1)  : ba.db2linear : si.smooth(0.999));\nMakeup2\t=  mute2* (not(bswitch2)*(push2-safe2)  : ba.db2linear : si.smooth(0.999));\nMakeup3\t=  mute3* (not(bswitch3)*(push3-safe3)  : ba.db2linear : si.smooth(0.999));\nMakeup4\t=  mute4* (not(bswitch4)*(push4-safe4)  : ba.db2linear : si.smooth(0.999));\nMakeup5\t=  mute5* (not(bswitch5)*(push5-safe5)  : ba.db2linear : si.smooth(0.999));\n\n//Low end headsets: 13,10,4,8,11 (split 80,210,1700,5000)\n//Mid-high end headsets: 17,20.5,20,10.5,10 (split 44,180,800,5000)"
 },
 {
  "id": "gx-mbcs",
  "name": "Multi-Band Compressor (stereo)",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Stereo version of the five-band compressor with linked per-band controls.",
  "description": "Stereo build of the five-band compressor: four adjustable crossovers, per-band Ratio, Makeup, Threshold, Attack, Release and Mode. Same processing as the mono version but with a stereo detector path.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Makeup1",
    "min": -50,
    "max": 50,
    "default": 13,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Makeup1"
   },
   {
    "label": "Makeup2",
    "min": -50,
    "max": 50,
    "default": 10,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Makeup2"
   },
   {
    "label": "Makeup3",
    "min": -50,
    "max": 50,
    "default": 4,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Makeup3"
   },
   {
    "label": "Makeup4",
    "min": -50,
    "max": 50,
    "default": 8,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Makeup4"
   },
   {
    "label": "Makeup5",
    "min": -50,
    "max": 50,
    "default": 11,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Makeup5"
   },
   {
    "label": "Makeup-Threshold1",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Makeup-Threshold1"
   },
   {
    "label": "Makeup-Threshold2",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Makeup-Threshold2"
   },
   {
    "label": "Makeup-Threshold3",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Makeup-Threshold3"
   },
   {
    "label": "Makeup-Threshold4",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Makeup-Threshold4"
   },
   {
    "label": "Makeup-Threshold5",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Makeup-Threshold5"
   },
   {
    "label": "Ratio1",
    "min": 1,
    "max": 100,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Ratio1"
   },
   {
    "label": "Ratio2",
    "min": 1,
    "max": 100,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Ratio2"
   },
   {
    "label": "Ratio3",
    "min": 1,
    "max": 100,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Ratio3"
   },
   {
    "label": "Ratio4",
    "min": 1,
    "max": 100,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Ratio4"
   },
   {
    "label": "Ratio5",
    "min": 1,
    "max": 100,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Ratio5"
   },
   {
    "label": "Attack1",
    "min": 0.001,
    "max": 1,
    "default": 0.012,
    "step": 0.001,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Attack1"
   },
   {
    "label": "Attack2",
    "min": 0.001,
    "max": 1,
    "default": 0.012,
    "step": 0.001,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Attack2"
   },
   {
    "label": "Attack3",
    "min": 0.001,
    "max": 1,
    "default": 0.012,
    "step": 0.001,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Attack3"
   },
   {
    "label": "Attack4",
    "min": 0.001,
    "max": 1,
    "default": 0.012,
    "step": 0.001,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Attack4"
   },
   {
    "label": "Attack5",
    "min": 0.001,
    "max": 1,
    "default": 0.012,
    "step": 0.001,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Attack5"
   },
   {
    "label": "Release1",
    "min": 0.01,
    "max": 10,
    "default": 1.25,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Release1"
   },
   {
    "label": "Release2",
    "min": 0.01,
    "max": 10,
    "default": 1.25,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Release2"
   },
   {
    "label": "Release3",
    "min": 0.01,
    "max": 10,
    "default": 1.25,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Release3"
   },
   {
    "label": "Release4",
    "min": 0.01,
    "max": 10,
    "default": 1.25,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Release4"
   },
   {
    "label": "Release5",
    "min": 0.01,
    "max": 10,
    "default": 1.25,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Release5"
   },
   {
    "label": "Mode1",
    "min": 1,
    "max": 3,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Mode1"
   },
   {
    "label": "Mode2",
    "min": 1,
    "max": 3,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Mode2"
   },
   {
    "label": "Mode3",
    "min": 1,
    "max": 3,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Mode3"
   },
   {
    "label": "Mode4",
    "min": 1,
    "max": 3,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Mode4"
   },
   {
    "label": "Mode5",
    "min": 1,
    "max": 3,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/Mode5"
   },
   {
    "label": "crossover b1 b2",
    "min": 20,
    "max": 20000,
    "default": 80,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/crossover_b1_b2"
   },
   {
    "label": "crossover b2 b3",
    "min": 20,
    "max": 20000,
    "default": 210,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/crossover_b2_b3"
   },
   {
    "label": "crossover b3 b4",
    "min": 20,
    "max": 20000,
    "default": 1700,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/crossover_b3_b4"
   },
   {
    "label": "crossover b4 b5",
    "min": 20,
    "max": 20000,
    "default": 5000,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Compressor_Stereo/crossover_b4_b5"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/mbcs.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"mbcs\";\ndeclare name \"Multi Band Compressor Stereo\";\ndeclare shortname \"MB Comp St\";\ndeclare category \"Guitar Effects\";\ndeclare description \"Multi Band Compressor contributed by kokoko3k\";\n\nimport(\"stdfaust.lib\");\nimport(\"reducemaps.lib\");\n\nsel1         = hslider(\"Mode1[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]\",1,1,3,1);\nsel2         = hslider(\"Mode2[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]\",1,1,3,1);\nsel3         = hslider(\"Mode3[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]\",1,1,3,1);\nsel4         = hslider(\"Mode4[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]\",1,1,3,1);\nsel5         = hslider(\"Mode5[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]\",1,1,3,1);\n\nnot(x) \t= abs(x-1);\nmute1\t\t= not(max(0,sel1-2));\nmute2\t\t= not(max(0,sel2-2));\nmute3\t\t= not(max(0,sel3-2));\nmute4\t\t= not(max(0,sel4-2));\nmute5\t\t= not(max(0,sel5-2));\n\nbypass(switch, block) = _ <: select2(switch, _, block);\n\nbswitch1\t= max(0,sel1-1);\nbswitch2\t= max(0,sel2-1);\nbswitch3\t= max(0,sel3-1);\nbswitch4\t= max(0,sel4-1);\nbswitch5\t= max(0,sel5-1);\n\nvmeter1(x,y)\t\t= attach(x, envelop(abs(x)+abs(y)) : vbargraph(\"v1[nomidi][log][tooltip: Sum of Band1 ]\", -70, +5)),y;\nvmeter2(x,y)\t\t= attach(x, envelop(abs(x)+abs(y)) : vbargraph(\"v2[nomidi][log][tooltip: Sum of Band2 ]\", -70, +5)),y;\nvmeter3(x,y)\t\t= attach(x, envelop(abs(x)+abs(y)) : vbargraph(\"v3[nomidi][log][tooltip: Sum of Band3 ]\", -70, +5)),y;\nvmeter4(x,y)\t\t= attach(x, envelop(abs(x)+abs(y)) : vbargraph(\"v4[nomidi][log][tooltip: Sum of Band4 ]\", -70, +5)),y;\nvmeter5(x,y)\t\t= attach(x, envelop(abs(x)+abs(y)) : vbargraph(\"v5[nomidi][log][tooltip: Sum of Band5 ]\", -70, +5)),y;\n\nenvelop         = _ : max ~ (1.0/ma.SR) : mean(4096) : *(0.5); // : max(ba.db2linear(-70)) : ba.linear2db;\n\n//Stereo \nprocess_wide =   (_,_):geqs: ( gcomp5s , gcomp4s , gcomp3s, gcomp2s, gcomp1s) :>(_,_) with { \ngcomp1s = ba.bypass2(bswitch1,co.compressor_stereo(ratio1,-push1,attack1,release1)):*(Makeup1),*(Makeup1) : vmeter1;\ngcomp2s = ba.bypass2(bswitch2,co.compressor_stereo(ratio2,-push2,attack2,release2)):*(Makeup2),*(Makeup2) : vmeter2;\ngcomp3s = ba.bypass2(bswitch3,co.compressor_stereo(ratio3,-push3,attack3,release3)):*(Makeup3),*(Makeup3) : vmeter3;\ngcomp4s = ba.bypass2(bswitch4,co.compressor_stereo(ratio4,-push4,attack4,release4)):*(Makeup4),*(Makeup4) : vmeter4;\ngcomp5s = ba.bypass2(bswitch5,co.compressor_stereo(ratio5,-push5,attack5,release5)):*(Makeup5),*(Makeup5) : vmeter5;\n};\n\nhifr1\t\t\t=hslider(\"crossover_b1_b2 [log][name:Crossover B1-B2 (hz)][tooltip: Crossover fi.bandpass frequency]\" ,80 , 20, 20000, 1.08);\nhifr2\t\t\t=hslider(\"crossover_b2_b3 [log][name:Crossover B2-B3 (hz)][tooltip: Crossover fi.bandpass frequency]\",210,20,20000,1.08);\nhifr3\t\t\t=hslider(\"crossover_b3_b4 [log][name:Crossover B3-B4 (hz)][tooltip: Crossover fi.bandpass frequency]\",1700,20,20000,1.08);\nhifr4\t\t\t=hslider(\"crossover_b4_b5 [log][name:Crossover B4-B5 (hz)][tooltip: Crossover fi.bandpass frequency]\",5000,20,20000,1.08);\n\ngeq = fi.filterbank(3, (hifr1,hifr2,hifr3,hifr4));\ncross5 =  _,!,!,!,!,_,!,!,!,!,!,_,!,!,!,!,_,!,!,!,!,!,_,!,!,!,!,_,!,!,!,!,!,_,!,!,!,!,_,!,!,!,!,!,_,!,!,!,!,_ ;\ngeqs = (geq,geq) <: cross5;\n\nratio1 \t\t= hslider(\"[9] Ratio1 [tooltip: Compression ratio]\",2,1,100,0.1);\nattack1\t\t= hslider(\"[A] Attack1 [tooltip: Time before the compressor starts to kick in]\", 0.012, 0.001, 1, 0.001);\nrelease1 \t= hslider(\"[B] Release1 [tooltip: Time before the compressor releases the sound]\", 1.25, 0.01, 10, 0.01);\n\nratio2 \t\t= hslider(\"[9] Ratio2 [tooltip: Compression ratio]\",2,1,100,0.1);\nattack2\t\t= hslider(\"[A] Attack2 [tooltip: Time before the compressor starts to kick in]\", 0.012, 0.001, 1, 0.001);\nrelease2 \t= hslider(\"[B] Release2 [tooltip: Time before the compressor releases the sound]\", 1.25, 0.01, 10, 0.01);\n\nratio3 \t\t= hslider(\"[9] Ratio3 [tooltip: Compression ratio]\",2,1,100,0.1);\nattack3\t\t= hslider(\"[A] Attack3 [tooltip: Time before the compressor starts to kick in]\", 0.012, 0.001, 1, 0.001);\nrelease3 \t= hslider(\"[B] Release3 [tooltip: Time before the compressor releases the sound]\", 1.25, 0.01, 10, 0.01);\n\nratio4 \t\t= hslider(\"[9] Ratio4 [tooltip: Compression ratio]\",2,1,100,0.1);\nattack4\t\t= hslider(\"[A] Attack4 [tooltip: Time before the compressor starts to kick in]\", 0.012, 0.001, 1, 0.001);\nrelease4 \t= hslider(\"[B] Release4 [tooltip: Time before the compressor releases the sound]\", 1.25, 0.01, 10, 0.01);\n\nratio5 \t\t= hslider(\"[9] Ratio5 [tooltip: Compression ratio]\",2,1,100,0.1);\nattack5\t\t= hslider(\"[A] Attack5 [tooltip: Time before the compressor starts to kick in]\", 0.012, 0.001, 1, 0.001);\nrelease5 \t= hslider(\"[B] Release5 [tooltip: Time before the compressor releases the sound]\", 1.25, 0.01, 10, 0.01);\n\npush1 \t\t= hslider(\"[5] Makeup1 [tooltip: Post amplification and threshold]\"   , 13, -50, +50, 0.1) ; // threshold-=push ;  makeup+=push\npush2 \t\t= hslider(\"[5] Makeup2 [tooltip: Post amplification and threshold]\"   , 10, -50, +50, 0.1) ; // threshold-=push ;  makeup+=push\npush3 \t\t= hslider(\"[5] Makeup3 [tooltip: Post amplification and threshold]\"   , 4,  -50, +50, 0.1) ; // threshold-=push ;  makeup+=push\npush4 \t\t= hslider(\"[5] Makeup4 [tooltip: Post amplification and threshold]\"   , 8,  -50, +50, 0.1) ; // threshold-=push ;  makeup+=push\npush5 \t\t= hslider(\"[5] Makeup5 [tooltip: Post amplification and threshold]\"   , 11, -50, +50, 0.1) ; // threshold-=push ;  makeup+=push\n\nsafe1 \t= hslider(\"[6] Makeup-Threshold1 [tooltip: Threshold correction, an anticlip measure]\" , 2, 0, +10, 0.1) ; // makeup-=safe\nsafe2 \t= hslider(\"[6] Makeup-Threshold2 [tooltip: Threshold correction, an anticlip measure]\" , 2, 0, +10, 0.1) ; // makeup-=safe\nsafe3 \t= hslider(\"[6] Makeup-Threshold3 [tooltip: Threshold correction, an anticlip measure]\" , 2, 0, +10, 0.1) ; // makeup-=safe\nsafe4 \t= hslider(\"[6] Makeup-Threshold4 [tooltip: Threshold correction, an anticlip measure]\" , 2, 0, +10, 0.1) ; // makeup-=safe\nsafe5 \t= hslider(\"[6] Makeup-Threshold5 [tooltip: Threshold correction, an anticlip measure]\" , 2, 0, +10, 0.1) ; // makeup-=safe\n\nMakeup1\t=  mute1* (not(bswitch1)*(push1-safe1)  : ba.db2linear : si.smooth(0.999));\nMakeup2\t=  mute2* (not(bswitch2)*(push2-safe2)  : ba.db2linear : si.smooth(0.999));\nMakeup3\t=  mute3* (not(bswitch3)*(push3-safe3)  : ba.db2linear : si.smooth(0.999));\nMakeup4\t=  mute4* (not(bswitch4)*(push4-safe4)  : ba.db2linear : si.smooth(0.999));\nMakeup5\t=  mute5* (not(bswitch5)*(push5-safe5)  : ba.db2linear : si.smooth(0.999));\n\n//Low end headsets: 13,10,4,8,11 (split 80,210,1700,5000)\n//Mid-high end headsets: 17,20.5,20,10.5,10 (split 44,180,800,5000)\n\n// mono wrapper added by the Chameleon port (pedal is mono in / mono out)\nprocess = _ <: process_wide :> *(0.5);"
 },
 {
  "id": "lib-gate",
  "name": "Noise Gate",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "JOS ef.gate_mono: threshold gate with attack, hold and release",
  "description": "JOS ef.gate_mono: threshold gate with attack, hold and release",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Threshold",
    "min": -90,
    "max": 0,
    "default": -40,
    "step": 0.1,
    "unit": "dB",
    "path": "/Noise_Gate/Threshold"
   },
   {
    "label": "Attack",
    "min": 0.02,
    "max": 100,
    "default": 1,
    "step": 0.01,
    "unit": "ms",
    "path": "/Noise_Gate/Attack"
   },
   {
    "label": "Hold",
    "min": 1,
    "max": 1000,
    "default": 50,
    "step": 1,
    "unit": "ms",
    "path": "/Noise_Gate/Hold"
   },
   {
    "label": "Release",
    "min": 1,
    "max": 1000,
    "default": 100,
    "step": 1,
    "unit": "ms",
    "path": "/Noise_Gate/Release"
   }
  ],
  "faustCode": "declare name \"Noise Gate\";\ndeclare description \"JOS ef.gate_mono: threshold gate with attack, hold and release\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/misceffects.lib ef.gate_mono\";\ndeclare category \"guitar\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\nthresh = hslider(\"[0] Threshold[unit:dB]\", -40, -90, 0, 0.1);\natt    = hslider(\"[1] Attack[unit:ms]\", 1, 0.02, 100, 0.01) : /(1000);\nhold   = hslider(\"[2] Hold[unit:ms]\", 50, 1, 1000, 1) : /(1000);\nrel    = hslider(\"[3] Release[unit:ms]\", 100, 1, 1000, 1) : /(1000);\nprocess = ef.gate_mono(thresh, att, hold, rel);"
 },
 {
  "id": "owl-qompander",
  "name": "Qompander",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "OWL patches",
  "license": "GPL-3.0",
  "shortDesc": "Katja Vetter's Hilbert-envelope compander (Bart Brouns port): upward companding that adds sustain and bite",
  "description": "Katja Vetter's Hilbert-envelope compander (Bart Brouns port): upward companding that adds sustain and bite",
  "author": "Bart Brouns (port of Katja Vetter's qompander), Hilbert coefficients by Olli Niemitalo",
  "flags": "",
  "params": [
   {
    "label": "Factor",
    "min": 0.8,
    "max": 8,
    "default": 3,
    "step": 0.01,
    "unit": "",
    "path": "/Qompander/Factor"
   },
   {
    "label": "Threshold",
    "min": -96,
    "max": -20,
    "default": -40,
    "step": 0.01,
    "unit": "dB",
    "path": "/Qompander/Threshold"
   },
   {
    "label": "Attack",
    "min": 1,
    "max": 20,
    "default": 1,
    "step": 0.01,
    "unit": "ms",
    "path": "/Qompander/Attack"
   },
   {
    "label": "Release",
    "min": 20,
    "max": 1000,
    "default": 20,
    "step": 0.01,
    "unit": "ms",
    "path": "/Qompander/Release"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": -6,
    "step": 0.1,
    "unit": "dB",
    "path": "/Qompander/Level"
   }
  ],
  "faustCode": "declare name \"Qompander\";\ndeclare description \"Katja Vetter's Hilbert-envelope compander (Bart Brouns port): upward companding that adds sustain and bite\";\ndeclare author \"Bart Brouns (port of Katja Vetter's qompander), Hilbert coefficients by Olli Niemitalo\";\ndeclare license \"GPL-3.0\";\ndeclare source \"pingdynasty/OwlPatches Faust/Qompander.dsp\";\ndeclare category \"guitar\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\nfactor    = hslider(\"[0] Factor\", 3, 0.8, 8, 0.01) : si.smooth(0.999);\nthreshold = hslider(\"[1] Threshold[unit:dB]\", -40, -96, -20, 0.01) : si.smooth(0.999);\nattack    = hslider(\"[2] Attack[unit:ms]\", 1, 1, 20, 0.01) : si.smooth(0.999);\nrelease   = hslider(\"[3] Release[unit:ms]\", 20, 20, 1000, 0.01) : si.smooth(0.999);\nlevel     = hslider(\"[4] Level[unit:dB]\", -6, -20, 20, 0.1) : ba.db2linear : si.smoo;\n\nmagnitude = threshold : ba.db2linear;\nexponent = log(magnitude)/log(sin(factor*magnitude*ma.PI/2));\nolli1(x) = x : fi.tf2(0.161758, 0, -1, 0, -0.161758) : fi.tf2(0.733029, 0, -1, 0, -0.733029) : fi.tf2(0.94535, 0, -1, 0, -0.94535) : fi.tf2(0.990598, 0, -1, 0, -0.990598);\nolli2(x) = x : mem : fi.tf2(0.479401, 0, -1, 0, -0.479401) : fi.tf2(0.876218, 0, -1, 0, -0.876218) : fi.tf2(0.976599, 0, -1, 0, -0.976599) : fi.tf2(0.9975, 0, -1, 0, -0.9975);\npyth(x) = sqrt((olli1(x)*olli1(x))+(olli2(x)*olli2(x))) : max(0.00001) : min(100);\nattackDecay(x) = pyth(x) : an.amp_follower_ud(max(0.001, attack/1000), max(0.02, release/1000));\nmapping(x) = attackDecay(x) : ((sin((min(1/factor)*(factor/4)) * (2*ma.PI)) : max(0.0000001) : min(1), exponent) : pow);\nqompander(x) = (mapping(x) / attackDecay(x)) <: (_,olli1(x):*),(_,olli2(x):*) :+ : _*(sqrt(0.5));\nprocess(x) = qompander(x) * level;"
 },
 {
  "id": "lib-rms-peak-limiter",
  "name": "RMS Comp + Peak Limiter",
  "category": "drum",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "DrumBrute / Volca",
  "source": "faustlibraries",
  "license": "GPL-3.0-only",
  "shortDesc": "Bart Brouns RMS feedback compressor followed by a peak limiter - drum bus glue with brickwall safety",
  "description": "Bart Brouns RMS feedback compressor followed by a peak limiter - drum bus glue with brickwall safety",
  "author": "Bart Brouns",
  "flags": "",
  "params": [
   {
    "label": "Strength",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/RMS_Comp_+_Peak_Limiter/Strength"
   },
   {
    "label": "Threshold",
    "min": -60,
    "max": 0,
    "default": -24,
    "step": 0.1,
    "unit": "dB",
    "path": "/RMS_Comp_+_Peak_Limiter/Threshold"
   },
   {
    "label": "Limit",
    "min": -30,
    "max": 0,
    "default": -3,
    "step": 0.1,
    "unit": "dB",
    "path": "/RMS_Comp_+_Peak_Limiter/Limit"
   },
   {
    "label": "Attack",
    "min": 1,
    "max": 200,
    "default": 20,
    "step": 0.1,
    "unit": "ms",
    "path": "/RMS_Comp_+_Peak_Limiter/Attack"
   },
   {
    "label": "Release",
    "min": 10,
    "max": 1500,
    "default": 120,
    "step": 1,
    "unit": "ms",
    "path": "/RMS_Comp_+_Peak_Limiter/Release"
   },
   {
    "label": "Knee",
    "min": 0,
    "max": 24,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/RMS_Comp_+_Peak_Limiter/Knee"
   },
   {
    "label": "Makeup",
    "min": 0,
    "max": 30,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/RMS_Comp_+_Peak_Limiter/Makeup"
   }
  ],
  "faustCode": "declare name \"RMS Comp + Peak Limiter\";\ndeclare description \"Bart Brouns RMS feedback compressor followed by a peak limiter - drum bus glue with brickwall safety\";\ndeclare author \"Bart Brouns\";\ndeclare license \"GPL-3.0-only\";\ndeclare source \"grame-cncm/faustlibraries/compressors.lib co.RMS_FBcompressor_peak_limiter_N_chan (origin magnetophon/faustCompressors)\";\ndeclare category \"drum\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\nstrength  = hslider(\"[0] Strength\", 0.5, 0, 1, 0.01) : si.smoo;\nthresh    = hslider(\"[1] Threshold[unit:dB]\", -24, -60, 0, 0.1) : si.smoo;\nthreshLim = hslider(\"[2] Limit[unit:dB]\", -3, -30, 0, 0.1) : si.smoo;\natt       = hslider(\"[3] Attack[unit:ms]\", 20, 1, 200, 0.1) : /(1000);\nrel       = hslider(\"[4] Release[unit:ms]\", 120, 10, 1500, 1) : /(1000);\nknee      = hslider(\"[5] Knee[unit:dB]\", 6, 0, 24, 0.1) : si.smoo;\nmakeup    = hslider(\"[6] Makeup[unit:dB]\", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;\nprocess = *(makeup) : co.RMS_FBcompressor_peak_limiter_N_chan(strength, thresh, threshLim, att, rel, knee, 0, _, _, 1);"
 },
 {
  "id": "lib-rms-compressor",
  "name": "RMS Compressor",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "GPL-3.0-only",
  "shortDesc": "RMS-detected compression gain (co.RMS_compression_gain_mono) - smooth, level-riding sustain",
  "description": "RMS-detected compression gain (co.RMS_compression_gain_mono) - smooth, level-riding sustain",
  "author": "Bart Brouns",
  "flags": "",
  "params": [
   {
    "label": "Strength",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/RMS_Compressor/Strength"
   },
   {
    "label": "Threshold",
    "min": -60,
    "max": 0,
    "default": -30,
    "step": 0.1,
    "unit": "dB",
    "path": "/RMS_Compressor/Threshold"
   },
   {
    "label": "Attack",
    "min": 1,
    "max": 200,
    "default": 20,
    "step": 0.1,
    "unit": "ms",
    "path": "/RMS_Compressor/Attack"
   },
   {
    "label": "Release",
    "min": 10,
    "max": 1500,
    "default": 200,
    "step": 1,
    "unit": "ms",
    "path": "/RMS_Compressor/Release"
   },
   {
    "label": "Knee",
    "min": 0,
    "max": 24,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/RMS_Compressor/Knee"
   },
   {
    "label": "Makeup",
    "min": 0,
    "max": 30,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/RMS_Compressor/Makeup"
   }
  ],
  "faustCode": "declare name \"RMS Compressor\";\ndeclare description \"RMS-detected compression gain (co.RMS_compression_gain_mono) - smooth, level-riding sustain\";\ndeclare author \"Bart Brouns\";\ndeclare license \"GPL-3.0-only\";\ndeclare source \"grame-cncm/faustlibraries/compressors.lib co.RMS_compression_gain_mono\";\ndeclare category \"guitar\";\ndeclare family \"dynamics\";\nimport(\"stdfaust.lib\");\n\nstrength = hslider(\"[0] Strength\", 0.7, 0, 1, 0.01) : si.smoo;\nthresh   = hslider(\"[1] Threshold[unit:dB]\", -30, -60, 0, 0.1) : si.smoo;\natt      = hslider(\"[2] Attack[unit:ms]\", 20, 1, 200, 0.1) : /(1000);\nrel      = hslider(\"[3] Release[unit:ms]\", 200, 10, 1500, 1) : /(1000);\nknee     = hslider(\"[4] Knee[unit:dB]\", 6, 0, 24, 0.1) : si.smoo;\nmakeup   = hslider(\"[5] Makeup[unit:dB]\", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;\nprocess(x) = x * co.RMS_compression_gain_mono(strength, thresh, att, rel, knee, 0, x) * makeup;"
 },
 {
  "id": "gx-susta",
  "name": "Sustainer",
  "category": "guitar",
  "family": "dynamics",
  "familyName": "Dynamics",
  "icon": "tabler:activity",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Transistor sustainer/compressor pedal circuit; squashy, long sustain with a fuzzy edge.",
  "description": "DK circuit simulation from the Sustainer schematic: pot-dependent filters followed by three transistor-stage tables. Sustain and Volume give a squashed, compressor-like sustain that breaks into light fuzz when pushed.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Sustain",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Sustainer/Sustain"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Sustainer/Volume"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/susta.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"susta\";\ndeclare name \"Sustainer\";\ndeclare category \"Distortion\";\ndeclare shortname \"Sustainer\";\ndeclare description \"Sustainer\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\nprocess = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0)) : clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    clip = tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) : tranystage(TB_7199P_68k,86.0,2700.0,3.571981) ;\n\n    \n        Volume = vslider(\"Volume[name:Volume]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n        Sustain = vslider(\"Sustain[name:Sustain]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Sustain*pow(fs,3)*(fs*(4.07249439024394e-27*fs - 1.34118849842818e-20) + 1.23525177556824e-15) + Volume*(Sustain*pow(fs,3)*(fs*(-3.9514408494262e-27*fs + 1.26300907176988e-20) + 2.68904213585766e-17) + pow(fs,3)*(fs*(-3.9514408494262e-29*fs + 1.26300907176988e-22) + 2.68904213585766e-19)) + pow(fs,3)*(fs*(4.07249439024394e-29*fs - 1.34118849842818e-22) + 1.23525177556824e-17);\n\n    b1 = Sustain*pow(fs,3)*(fs*(-2.03624719512197e-26*fs + 4.02356549528453e-20) - 1.23525177556824e-15) + Volume*(Sustain*pow(fs,3)*(fs*(1.9757204247131e-26*fs - 3.78902721530964e-20) - 2.68904213585766e-17) + pow(fs,3)*(fs*(1.9757204247131e-28*fs - 3.78902721530964e-22) - 2.68904213585766e-19)) + pow(fs,3)*(fs*(-2.03624719512197e-28*fs + 4.02356549528453e-22) - 1.23525177556824e-17);\n\n    b2 = Sustain*pow(fs,3)*(fs*(4.07249439024394e-26*fs - 2.68237699685635e-20) - 2.47050355113649e-15) + Volume*(Sustain*pow(fs,3)*(fs*(-3.9514408494262e-26*fs + 2.52601814353976e-20) - 5.37808427171532e-17) + pow(fs,3)*(fs*(-3.9514408494262e-28*fs + 2.52601814353976e-22) - 5.37808427171532e-19)) + pow(fs,3)*(fs*(4.07249439024394e-28*fs - 2.68237699685635e-22) - 2.47050355113649e-17);\n\n    b3 = Sustain*pow(fs,3)*(fs*(-4.07249439024394e-26*fs - 2.68237699685635e-20) + 2.47050355113649e-15) + Volume*(Sustain*pow(fs,3)*(fs*(3.9514408494262e-26*fs + 2.52601814353976e-20) + 5.37808427171532e-17) + pow(fs,3)*(fs*(3.9514408494262e-28*fs + 2.52601814353976e-22) + 5.37808427171532e-19)) + pow(fs,3)*(fs*(-4.07249439024394e-28*fs - 2.68237699685635e-22) + 2.47050355113649e-17);\n\n    b4 = Sustain*pow(fs,3)*(fs*(2.03624719512197e-26*fs + 4.02356549528453e-20) + 1.23525177556824e-15) + Volume*(Sustain*pow(fs,3)*(fs*(-1.9757204247131e-26*fs - 3.78902721530964e-20) + 2.68904213585766e-17) + pow(fs,3)*(fs*(-1.9757204247131e-28*fs - 3.78902721530964e-22) + 2.68904213585766e-19)) + pow(fs,3)*(fs*(2.03624719512197e-28*fs + 4.02356549528453e-22) + 1.23525177556824e-17);\n\n    b5 = Sustain*pow(fs,3)*(fs*(-4.07249439024394e-27*fs - 1.34118849842818e-20) - 1.23525177556824e-15) + Volume*(Sustain*pow(fs,3)*(fs*(3.9514408494262e-27*fs + 1.26300907176988e-20) - 2.68904213585766e-17) + pow(fs,3)*(fs*(3.9514408494262e-29*fs + 1.26300907176988e-22) - 2.68904213585766e-19)) + pow(fs,3)*(fs*(-4.07249439024394e-29*fs - 1.34118849842818e-22) - 1.23525177556824e-17);\n\n    a0 = Sustain*(Sustain*pow(fs,2)*(fs*(fs*(-9.91377586985301e-24*fs - 9.36483991458906e-20) - 1.70486053448624e-16) - 2.12307123308889e-15) + fs*(fs*(fs*(fs*(9.84499037599778e-24*fs + 9.42766173980015e-20) + 1.78421312766784e-16) + 3.39775512445924e-15) + 1.56108178903595e-14)) + Volume*(Sustain*(Sustain*pow(fs,2)*(fs*(fs*(5.11091507074998e-24*fs + 6.98874158230498e-20) + 1.4095256819997e-16) + 1.75646845862514e-15) + fs*(fs*(fs*(fs*(-5.07545362580621e-24*fs - 7.00613593632107e-20) - 1.47460849525455e-16) - 2.81034919192636e-15) - 1.29152092545966e-14)) + fs*(fs*(fs*(fs*(-1.03973026841637e-24*fs - 5.71785438210912e-20) - 1.41224926366503e-16) - 3.77185698680303e-15) - 3.30317585349598e-14) - 9.49647739308574e-14) + fs*(fs*(fs*(fs*(1.58888527196851e-24*fs + 6.14378170525581e-20) + 1.4867852143994e-16) + 4.14135154627774e-15) + 3.80287926742832e-14) + 1.14785425664408e-13;\n\n    a1 = Sustain*(Sustain*pow(fs,2)*(fs*(fs*(4.95688793492651e-23*fs + 2.80945197437672e-19) + 1.70486053448624e-16) - 2.12307123308889e-15) + fs*(fs*(fs*(fs*(-4.92249518799889e-23*fs - 2.82829852194005e-19) - 1.78421312766784e-16) + 3.39775512445924e-15) + 4.68324536710785e-14)) + Volume*(Sustain*(Sustain*pow(fs,2)*(fs*(fs*(-2.55545753537499e-23*fs - 2.09662247469149e-19) - 1.4095256819997e-16) + 1.75646845862514e-15) + fs*(fs*(fs*(fs*(2.53772681290311e-23*fs + 2.10184078089632e-19) + 1.47460849525455e-16) - 2.81034919192636e-15) - 3.87456277637898e-14)) + fs*(fs*(fs*(fs*(5.19865134208184e-24*fs + 1.71535631463274e-19) + 1.41224926366503e-16) - 3.77185698680303e-15) - 9.90952756048795e-14) - 4.74823869654287e-13) + fs*(fs*(fs*(fs*(-7.94442635984257e-24*fs - 1.84313451157674e-19) - 1.4867852143994e-16) + 4.14135154627774e-15) + 1.1408637802285e-13) + 5.7392712832204e-13;\n\n    a2 = Sustain*(Sustain*pow(fs,2)*(fs*(fs*(-9.91377586985301e-23*fs - 1.87296798291781e-19) + 3.40972106897249e-16) + 4.24614246617778e-15) + fs*(fs*(fs*(fs*(9.84499037599778e-23*fs + 1.88553234796003e-19) - 3.56842625533568e-16) - 6.79551024891847e-15) + 3.1221635780719e-14)) + Volume*(Sustain*(Sustain*pow(fs,2)*(fs*(fs*(5.11091507074998e-23*fs + 1.397748316461e-19) - 2.81905136399941e-16) - 3.51293691725028e-15) + fs*(fs*(fs*(fs*(-5.07545362580621e-23*fs - 1.40122718726421e-19) + 2.94921699050911e-16) + 5.62069838385272e-15) - 2.58304185091932e-14)) + fs*(fs*(fs*(fs*(-1.03973026841637e-23*fs - 1.14357087642182e-19) + 2.82449852733007e-16) + 7.54371397360606e-15) - 6.60635170699196e-14) - 9.49647739308574e-13) + fs*(fs*(fs*(fs*(1.58888527196851e-23*fs + 1.22875634105116e-19) - 2.97357042879881e-16) - 8.28270309255548e-15) + 7.60575853485664e-14) + 1.14785425664408e-12;\n\n    a3 = Sustain*(Sustain*pow(fs,2)*(fs*(fs*(9.91377586985301e-23*fs - 1.87296798291781e-19) - 3.40972106897249e-16) + 4.24614246617778e-15) + fs*(fs*(fs*(fs*(-9.84499037599778e-23*fs + 1.88553234796003e-19) + 3.56842625533568e-16) - 6.79551024891847e-15) - 3.1221635780719e-14)) + Volume*(Sustain*(Sustain*pow(fs,2)*(fs*(fs*(-5.11091507074998e-23*fs + 1.397748316461e-19) + 2.81905136399941e-16) - 3.51293691725028e-15) + fs*(fs*(fs*(fs*(5.07545362580621e-23*fs - 1.40122718726421e-19) - 2.94921699050911e-16) + 5.62069838385272e-15) + 2.58304185091932e-14)) + fs*(fs*(fs*(fs*(1.03973026841637e-23*fs - 1.14357087642182e-19) - 2.82449852733007e-16) + 7.54371397360606e-15) + 6.60635170699196e-14) - 9.49647739308574e-13) + fs*(fs*(fs*(fs*(-1.58888527196851e-23*fs + 1.22875634105116e-19) + 2.97357042879881e-16) - 8.28270309255548e-15) - 7.60575853485664e-14) + 1.14785425664408e-12;\n\n    a4 = Sustain*(Sustain*pow(fs,2)*(fs*(fs*(-4.95688793492651e-23*fs + 2.80945197437672e-19) - 1.70486053448624e-16) - 2.12307123308889e-15) + fs*(fs*(fs*(fs*(4.92249518799889e-23*fs - 2.82829852194005e-19) + 1.78421312766784e-16) + 3.39775512445924e-15) - 4.68324536710785e-14)) + Volume*(Sustain*(Sustain*pow(fs,2)*(fs*(fs*(2.55545753537499e-23*fs - 2.09662247469149e-19) + 1.4095256819997e-16) + 1.75646845862514e-15) + fs*(fs*(fs*(fs*(-2.53772681290311e-23*fs + 2.10184078089632e-19) - 1.47460849525455e-16) - 2.81034919192636e-15) + 3.87456277637898e-14)) + fs*(fs*(fs*(fs*(-5.19865134208184e-24*fs + 1.71535631463274e-19) - 1.41224926366503e-16) - 3.77185698680303e-15) + 9.90952756048795e-14) - 4.74823869654287e-13) + fs*(fs*(fs*(fs*(7.94442635984257e-24*fs - 1.84313451157674e-19) + 1.4867852143994e-16) + 4.14135154627774e-15) - 1.1408637802285e-13) + 5.7392712832204e-13;\n\n    a5 = Sustain*(Sustain*pow(fs,2)*(fs*(fs*(9.91377586985301e-24*fs - 9.36483991458906e-20) + 1.70486053448624e-16) - 2.12307123308889e-15) + fs*(fs*(fs*(fs*(-9.84499037599778e-24*fs + 9.42766173980015e-20) - 1.78421312766784e-16) + 3.39775512445924e-15) - 1.56108178903595e-14)) + Volume*(Sustain*(Sustain*pow(fs,2)*(fs*(fs*(-5.11091507074998e-24*fs + 6.98874158230498e-20) - 1.4095256819997e-16) + 1.75646845862514e-15) + fs*(fs*(fs*(fs*(5.07545362580621e-24*fs - 7.00613593632107e-20) + 1.47460849525455e-16) - 2.81034919192636e-15) + 1.29152092545966e-14)) + fs*(fs*(fs*(fs*(1.03973026841637e-24*fs - 5.71785438210912e-20) + 1.41224926366503e-16) - 3.77185698680303e-15) + 3.30317585349598e-14) - 9.49647739308574e-14) + fs*(fs*(fs*(fs*(-1.58888527196851e-24*fs + 6.14378170525581e-20) - 1.4867852143994e-16) + 4.14135154627774e-15) - 3.80287926742832e-14) + 1.14785425664408e-13;\n};"
 },
 {
  "id": "gx-eq",
  "name": "10-Band Parametric EQ",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Ten octave-spaced peaking filters (31 Hz–16 kHz) with per-band gain and Q.",
  "description": "Ten cascaded peaking filters at octave centres from 31.25 Hz to 16 kHz, each with its own gain (-50 to +10 dB) and Q. A graphic-style EQ with adjustable bandwidth per band.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Q31 25",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/gx_eq/Q31_25"
   },
   {
    "label": "f31 25",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_eq/f31_25"
   },
   {
    "label": "Q62 5",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/gx_eq/Q62_5"
   },
   {
    "label": "f62 5",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_eq/f62_5"
   },
   {
    "label": "Q125",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/gx_eq/Q125"
   },
   {
    "label": "f125",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_eq/f125"
   },
   {
    "label": "Q250",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/gx_eq/Q250"
   },
   {
    "label": "f250",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_eq/f250"
   },
   {
    "label": "Q500",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/gx_eq/Q500"
   },
   {
    "label": "f500",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_eq/f500"
   },
   {
    "label": "Q1k",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/gx_eq/Q1k"
   },
   {
    "label": "f1k",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_eq/f1k"
   },
   {
    "label": "Q2k",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/gx_eq/Q2k"
   },
   {
    "label": "f2k",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_eq/f2k"
   },
   {
    "label": "Q4k",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/gx_eq/Q4k"
   },
   {
    "label": "f4k",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_eq/f4k"
   },
   {
    "label": "Q8k",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/gx_eq/Q8k"
   },
   {
    "label": "f8k",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_eq/f8k"
   },
   {
    "label": "Q16k",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/gx_eq/Q16k"
   },
   {
    "label": "f16k",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_eq/f16k"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/eq.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \t\t\"eq\";\ndeclare license \t\"BSD\";\ndeclare copyright \t\"(c)GRAME 2006\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\n//------------------------- Process --------------------------------\n\nprocess =   ifilter(vslider(\"Q31_25\", 50, 1, 100, 1),   31.25, vslider(\"f31_25[tooltip:gain (dB) at 31.25 Hz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Q62_5\", 50, 1, 100, 1),   62.5,  vslider(\"f62_5 [tooltip:gain (dB) at 62.5 Hz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Q125\", 50, 1, 100, 1),  125,    vslider(\"f125  [tooltip:gain (dB) at 125 Hz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Q250\", 50, 1, 100, 1),  250,    vslider(\"f250  [tooltip:gain (dB) at 250 Hz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Q500\", 50, 1, 100, 1),  500,    vslider(\"f500  [tooltip:gain (dB) at 500 Hz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Q1k\", 50, 1, 100, 1), 1000,    vslider(\"f1k   [tooltip:gain (dB) at 1 kHz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Q2k\", 50, 1, 100, 1), 2000,    vslider(\"f2k   [tooltip:gain (dB) at 2 kHz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Q4k\", 50, 1, 100, 1), 4000,    vslider(\"f4k   [tooltip:gain (dB) at 4 kHz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Q8k\", 50, 1, 100, 1), 8000,    vslider(\"f8k   [tooltip:gain (dB) at 8 kHz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Q16k\", 50, 1, 100, 1),16000,    vslider(\"f16k  [tooltip:gain (dB) at 16 kHz]\", 0, -50, 10, 0.1))\n          ;"
 },
 {
  "id": "gx-selecteq",
  "name": "10-Band Scalable EQ",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Ten fully parametric peaking bands with adjustable centre frequency, gain and Q.",
  "description": "Ten cascaded peaking filters, each with adjustable centre frequency (20 Hz–20 kHz), gain (-50 to +10 dB) and Q. The parametric sibling of the 10-band EQ.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Qs31 25",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/Qs31_25"
   },
   {
    "label": "freq31 25",
    "min": 20,
    "max": 20000,
    "default": 31,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/freq31_25"
   },
   {
    "label": "fs31 25",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Scaleable_EQ/fs31_25"
   },
   {
    "label": "Qs62 5",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/Qs62_5"
   },
   {
    "label": "freq62 5",
    "min": 20,
    "max": 20000,
    "default": 62,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/freq62_5"
   },
   {
    "label": "fs62 5",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Scaleable_EQ/fs62_5"
   },
   {
    "label": "Qs125",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/Qs125"
   },
   {
    "label": "freq125",
    "min": 20,
    "max": 20000,
    "default": 125,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/freq125"
   },
   {
    "label": "fs125",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Scaleable_EQ/fs125"
   },
   {
    "label": "Qs250",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/Qs250"
   },
   {
    "label": "freq250",
    "min": 20,
    "max": 20000,
    "default": 250,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/freq250"
   },
   {
    "label": "fs250",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Scaleable_EQ/fs250"
   },
   {
    "label": "Qs500",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/Qs500"
   },
   {
    "label": "freq500",
    "min": 20,
    "max": 20000,
    "default": 500,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/freq500"
   },
   {
    "label": "fs500",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Scaleable_EQ/fs500"
   },
   {
    "label": "Qs1k",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/Qs1k"
   },
   {
    "label": "freq1k",
    "min": 20,
    "max": 20000,
    "default": 1000,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/freq1k"
   },
   {
    "label": "fs1k",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Scaleable_EQ/fs1k"
   },
   {
    "label": "Qs2k",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/Qs2k"
   },
   {
    "label": "freq2k",
    "min": 20,
    "max": 20000,
    "default": 2000,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/freq2k"
   },
   {
    "label": "fs2k",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Scaleable_EQ/fs2k"
   },
   {
    "label": "Qs4k",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/Qs4k"
   },
   {
    "label": "freq4k",
    "min": 20,
    "max": 20000,
    "default": 4000,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/freq4k"
   },
   {
    "label": "fs4k",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Scaleable_EQ/fs4k"
   },
   {
    "label": "Qs8k",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/Qs8k"
   },
   {
    "label": "freq8k",
    "min": 20,
    "max": 20000,
    "default": 8000,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/freq8k"
   },
   {
    "label": "fs8k",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Scaleable_EQ/fs8k"
   },
   {
    "label": "Qs16k",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/Qs16k"
   },
   {
    "label": "freq16k",
    "min": 20,
    "max": 20000,
    "default": 16000,
    "step": 1,
    "unit": "",
    "path": "/Scaleable_EQ/freq16k"
   },
   {
    "label": "fs16k",
    "min": -50,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Scaleable_EQ/fs16k"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/selecteq.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \t\t\"eqs\";\ndeclare name            \"Scaleable EQ\";\ndeclare category        \"Tone Control\";\ndeclare license \t\"BSD\";\ndeclare copyright \t\"(c)GRAME 2006\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\n//------------------------- Process --------------------------------\n\nprocess =   ifilter(vslider(\"Qs31_25\", 50, 1, 100, 1),   vslider(\"freq31_25 [tooltip:Hz]\",31, 20, 20000, 1), vslider(\"fs31_25[tooltip:gain (dB) at 31.25 Hz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Qs62_5\", 50, 1, 100, 1),   vslider(\"freq62_5 [tooltip:Hz]\",62, 20, 20000, 1),  vslider(\"fs62_5 [tooltip:gain (dB) at 62.5 Hz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Qs125\", 50, 1, 100, 1),  vslider(\"freq125 [tooltip:Hz]\",125., 20, 20000, 1),    vslider(\"fs125  [tooltip:gain (dB) at 125 Hz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Qs250\", 50, 1, 100, 1),  vslider(\"freq250 [tooltip:Hz]\",250., 20, 20000, 1),    vslider(\"fs250  [tooltip:gain (dB) at 250 Hz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Qs500\", 50, 1, 100, 1),  vslider(\"freq500 [tooltip:Hz]\",500., 20, 20000, 1),    vslider(\"fs500  [tooltip:gain (dB) at 500 Hz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Qs1k\", 50, 1, 100, 1), vslider(\"freq1k [tooltip:Hz]\",1000., 20, 20000, 1),    vslider(\"fs1k   [tooltip:gain (dB) at 1 kHz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Qs2k\", 50, 1, 100, 1), vslider(\"freq2k [tooltip:Hz]\",2000., 20, 20000, 1),    vslider(\"fs2k   [tooltip:gain (dB) at 2 kHz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Qs4k\", 50, 1, 100, 1), vslider(\"freq4k [tooltip:Hz]\",4000., 20, 20000, 1),    vslider(\"fs4k   [tooltip:gain (dB) at 4 kHz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Qs8k\", 50, 1, 100, 1), vslider(\"freq8k [tooltip:Hz]\",8000., 20, 20000, 1),    vslider(\"fs8k   [tooltip:gain (dB) at 8 kHz]\", 0, -50, 10, 0.1))\n          : ifilter(vslider(\"Qs16k\", 50, 1, 100, 1),vslider(\"freq16k [tooltip:Hz]\",16000., 20, 20000, 1),    vslider(\"fs16k  [tooltip:gain (dB) at 16 kHz]\", 0, -50, 10, 0.1))\n          ;"
 },
 {
  "id": "gx-graphiceq",
  "name": "11-Band Graphic EQ",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Eleven-band graphic equaliser with slider gains from sub-bass to air.",
  "description": "A filterbank graphic EQ with eleven fixed bands and a gain slider per band. Straightforward broad tone shaping.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "g1",
    "min": -60,
    "max": 5.2,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Graphic_EQ/g1"
   },
   {
    "label": "g2",
    "min": -30,
    "max": 5.2,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Graphic_EQ/g2"
   },
   {
    "label": "g3",
    "min": -30,
    "max": 5.2,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Graphic_EQ/g3"
   },
   {
    "label": "g4",
    "min": -30,
    "max": 5.2,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Graphic_EQ/g4"
   },
   {
    "label": "g5",
    "min": -30,
    "max": 5.2,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Graphic_EQ/g5"
   },
   {
    "label": "g6",
    "min": -30,
    "max": 5.2,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Graphic_EQ/g6"
   },
   {
    "label": "g7",
    "min": -30,
    "max": 5.2,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Graphic_EQ/g7"
   },
   {
    "label": "g8",
    "min": -30,
    "max": 5.2,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Graphic_EQ/g8"
   },
   {
    "label": "g9",
    "min": -30,
    "max": 5.2,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Graphic_EQ/g9"
   },
   {
    "label": "g10",
    "min": -30,
    "max": 5.2,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Graphic_EQ/g10"
   },
   {
    "label": "g11",
    "min": -30,
    "max": 5.2,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Graphic_EQ/g11"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/graphiceq.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"graphiceq\";\ndeclare name \"Graphic EQ\";\ndeclare category \"Tone Control\";\ndeclare description \"Graphic EQ\";\n\nimport(\"stdfaust.lib\");\nrd = library(\"reducemaps.lib\");\n\n//geq = fi.filterbank(3, (31.25, 62.5, 125., 250., 500., 1000., 2000., 4000., 8000., 16000.));\ngeq = fi.filterbank(3, (44., 88., 177., 354., 707., 1414., 2828., 5657., 11384., 18110.));\n\ng1 = vslider(\"g1[tooltip:gain (dB) below 31.25 Hz]\", 0, -60, 5.2, 0.1) : ba.db2linear : si.smooth(0.999);\ng2 = vslider(\"g2 [tooltip:gain (dB) at 62.5 Hz]\", 0, -30, 5.2, 0.1) : ba.db2linear : si.smooth(0.999);\ng3 = vslider(\"g3  [tooltip:gain (dB) at 125 Hz]\", 0, -30, 5.2, 0.1) : ba.db2linear : si.smooth(0.999);\ng4 = vslider(\"g4  [tooltip:gain (dB) at 250 Hz]\", 0, -30, 5.2, 0.1) : ba.db2linear : si.smooth(0.999);\ng5 = vslider(\"g5  [tooltip:gain (dB) at 500 Hz]\", 0, -30, 5.2, 0.1) : ba.db2linear : si.smooth(0.999);\ng6 = vslider(\"g6   [tooltip:gain (dB) at 1 kHz]\", 0, -30, 5.2, 0.1) : ba.db2linear : si.smooth(0.999);\ng7 = vslider(\"g7   [tooltip:gain (dB) at 2 kHz]\", 0, -30, 5.2, 0.1) : ba.db2linear : si.smooth(0.999);\ng8 = vslider(\"g8   [tooltip:gain (dB) at 4 kHz]\", 0, -30, 5.2, 0.1) : ba.db2linear : si.smooth(0.999);\ng9 = vslider(\"g9   [tooltip:gain (dB) at 8 kHz]\", 0, -30, 5.2, 0.1) : ba.db2linear : si.smooth(0.999);\ng10 = vslider(\"g10  [tooltip:gain (dB) at 16 kHz]\", 0, -30, 5.2, 0.1) : ba.db2linear : si.smooth(0.999);\ng11 = vslider(\"g11  [tooltip:gain (dB) above 16 kHz]\", 0, -30, 5.2, 0.1) : ba.db2linear : si.smooth(0.999);\n\nv1(x)\t\t= attach(x, envelop(x) : vbargraph(\"v1[nomidi:no]\", -70, +5));\nv2(x)\t\t= attach(x, envelop(x) : vbargraph(\"v2[nomidi:no]\", -70, +5));\nv3(x)\t\t= attach(x, envelop(x) : vbargraph(\"v3[nomidi:no]\", -70, +5));\nv4(x)\t\t= attach(x, envelop(x) : vbargraph(\"v4[nomidi:no]\", -70, +5));\nv5(x)\t\t= attach(x, envelop(x) : vbargraph(\"v5[nomidi:no]\", -70, +5));\n\nv6(x)\t\t= attach(x, envelop(x) : vbargraph(\"v6[nomidi:no]\", -70, +5));\nv7(x)\t\t= attach(x, envelop(x) : vbargraph(\"v7[nomidi:no]\", -70, +5));\nv8(x)\t\t= attach(x, envelop(x) : vbargraph(\"v8[nomidi:no]\", -70, +5));\nv9(x)\t\t= attach(x, envelop(x) : vbargraph(\"v9[nomidi:no]\", -70, +5));\nv10(x)\t\t= attach(x, envelop(x) : vbargraph(\"v10[nomidi:no]\", -70, +5));\nv11(x)\t\t= attach(x, envelop(x) : vbargraph(\"v11[nomidi:no]\", -70, +5));\n\nenvelop         = abs : max ~ (1.0/ma.SR) : rd.maxn(4096) ;\n\nprocess = geq :(*(g11):v11), (*(g10):v10),(*(g9):v9),(*(g8):v8),(*(g7):v7),(*(g6):v6),\n               (*(g5):v5),(*(g4):v4),(*(g3):v3),(*(g2):v2),(*(g1):v1) :>_;"
 },
 {
  "id": "gx-tonecontroll",
  "name": "3-Band Tone Control",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Three-band crossover EQ with Bass/Middle/Treble gains and a 'sharper' compression stage.",
  "description": "Splits the signal into bass, mid and treble bands with a filterbank at 600 Hz and 2.4 kHz, applies per-band gain, then a compressor whose Sharper control tightens the result. A simple active three-band tone shaper.",
  "author": "brummer",
  "flags": "-double",
  "params": [
   {
    "label": "Treble",
    "min": -5,
    "max": 5,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/3_Band_EQ/Treble"
   },
   {
    "label": "Middle",
    "min": -5,
    "max": 5,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/3_Band_EQ/Middle"
   },
   {
    "label": "Bass",
    "min": -5,
    "max": 5,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/3_Band_EQ/Bass"
   },
   {
    "label": "sharper",
    "min": -2.5,
    "max": 5,
    "default": -2,
    "step": 0.1,
    "unit": "",
    "path": "/3_Band_EQ/sharper"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonecontroll.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \t\t\"tonemodul\";\ndeclare name            \"3 Band EQ\";\ndeclare category        \"Tone Control\";\ndeclare version \t\"0.01\";\ndeclare author \t\t\"brummer\";\ndeclare license \t\"BSD\";\ndeclare copyright \t\"(c)brummer 2008\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nF = 600; //nentry(\"split_low_freq\", 250, 20, 600, 10);\nF1 = 1200; //nentry(\"split_middle_freq\", 650, 600, 1250, 10);\nF2 = 2400; //nentry(\"split_high_freq\", 1250, 1250, 12000, 10);\n\n/**********************************************************************\n*** this part is included here for backward compatibility from 0.9.27 to\n*** 0.9.24 \n***********************************************************************/\n\n//------------------------------ ba.count and ba.take --------------------------------------\n\ncountN ((xs, xxs)) = 1 + countN(xxs);\ncountN (xx) = 1;\n\ntakeN (1, (xs, xxs))     = xs;\ntakeN (1, xs)                    = xs;\ntakeN (nn, (xs, xxs))    = takeN (nn-1, xxs);\n\n//------------------------------ low/high-passfilters --------------------------------------\n\ntf1N(b0,b1,a1) = _ <: *(b0), (mem : *(b1)) :> + ~ *(0-a1);\n\ntf2N(b0,b1,b2,a1,a2) = sub ~ conv2(a1,a2) : conv3(b0,b1,b2)\nwith {\n  conv3(k0,k1,k2,x)     = k0*x + k1*x' + k2*x'';\n  conv2(k0,k1,x)        = k0*x + k1*x';\n  sub(x,y)              = y-x;\n};\n\ntf1sN(b1,b0,a0,w1) = tf1N(b0d,b1d,a1d)\nwith {\n  c   = 1/tan((w1)*0.5/ma.SR); // bilinear-transform scale-factor\n  d   = a0 + c;\n  b1d = (b0 - b1*c) / d;\n  b0d = (b0 + b1*c) / d;\n  a1d = (a0 - c) / d;\n};\n\ntf2sN(b2,b1,b0,a1,a0,w1) = tf2N(b0d,b1d,b2d,a1d,a2d)\nwith {\n  c   = 1/tan((w1)*0.5/ma.SR); // bilinear-transform scale-factor\n  csq = c*c;\n  d   = a0 + a1 * c + csq;\n  b0d = (b0 + b1 * c + b2 * csq)/d;\n  b1d = 2 * (b0 - b2 * csq)/d;\n  b2d = (b0 - b1 * c + b2 * csq)/d;\n  a1d = 2 * (a0 - csq)/d;\n  a2d = (a0 - a1*c + csq)/d;\n};\n\nlowpassN(N,fc) = lowpass0_highpass1N(0,N,fc);\nhighpassN(N,fc) = lowpass0_highpass1N(1,N,fc);\nlowpass0_highpass1N(s,N,fc) = lphpr(s,N,N,fc)\nwith {\n  lphpr(s,0,N,fc) = _;\n  lphpr(s,1,N,fc) = tf1sN(s,1-s,1,2*ma.PI*fc);\n  lphpr(s,O,N,fc) = lphpr(s,(O-2),N,fc) : tf2sN(s,0,1-s,a1s,1,w1) with {\n    parity = N % 2;\n    S = (O-parity)/2; // current section number\n    a1s = -2*cos(-ma.PI + (1-parity)*ma.PI/(2*N) + (S-1+parity)*ma.PI/N);\n    w1 = 2*ma.PI*fc;\n  };\n};\n\n//------------------------------ an.analyzer --------------------------------------\nanalyzern(O,lfreqs) = _ <: bsplit(nb) with\n{\n   nb = countN(lfreqs);\n   fc(n) = takeN(n, lfreqs);\n   lp(n) = lowpassN(O,fc(n));\n   hp(n) = highpassN(O,fc(n));\n   bsplit(0) = _;\n   bsplit(i) = hp(i), (lp(i) <: bsplit(i-1));\n};\n\nanalyzerN(lfreqs) = analyzern(3,lfreqs);\n\nfilterbankn(O,lfreqs) = analyzern(O,lfreqs) : delayeq with\n{\n   nb = ba.count(lfreqs);\n   fc(n) = ba.take(n, lfreqs);\n   ap(n) = fi.highpass_plus_lowpass(O,fc(n));\n   delayeq = par(i,nb-1,apchain(nb-1-i)),_,_;\n   apchain(0) = _;\n   apchain(i) =  ap(i) : apchain(i-1);\n};\n\nfilterbankN(lfreqs) = fi.filterbank(3,lfreqs);\n\n/**********************************************************************\n*** end for backward compatibility from 0.9.27 to\n*** 0.9.24 , it could removed when switch completely to > 0.9.27\n***********************************************************************/\n\n//----------tone_controll---------\n\nt = vslider(\"Treble\", 0., -5., 5, 0.01): ba.db2linear : smoothi(0.999);\nm = vslider(\"Middle\", 0., -5., 5, 0.01): ba.db2linear : smoothi(0.999);\nl = vslider(\"Bass\", 0., -5., 5, 0.01): ba.db2linear : smoothi(0.999) ;\n\n//tstack = component(\"gx-tonestack.dsp\");\nsharp = vslider(\"sharper[name:sharper]\", -2, -2.5, 5, 0.1);\npress = -5. * sharp;\n\nattack  = 0.005;\nrelease = 5.0;\nknee    = 10.5;\nratio   = 3.0;\n\nenv = abs : max(1);\n\ncompress(env) = level * (1-r)/r\nwith {\n\tlevel = env : h ~ _ : ba.linear2db : (_ - press ) : max(0)\n\twith {\n\t\th(x,y)  = f*x+(1-f)*y with { f = (x<y)*ga+(x>=y)*gr; };\n\t\tga      = exp(-1/(ma.SR*attack));\n\t\tgr      = exp(-1/(ma.SR*release));\n\t};\n\tp = level/(knee+eps) : max(0) : min(1) with { eps = 0.001; };\n\tr = 1 - p + p * ratio;\n};\n\ncomp1(x) = g(x) * x\nwith {\n\tg = env : compress + sharp : ba.db2linear;\n};\ncomp = BP( comp1);\n\ntone_controll =  _ : filterbankN((F,F2)): *(t),*(m),*(l):>_;\n\nprocess_wide \t\t=  (tone_controll : comp) ,(tone_controll : comp);\n\n// mono wrapper added by the Chameleon port (pedal is mono in / mono out)\nprocess = _ <: process_wide :> *(0.5);"
 },
 {
  "id": "gx-bassboom",
  "name": "Bass Boom",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Sub-bass enhancer that generates harmonics from the band below 110 Hz.",
  "description": "Splits off the band below 110 Hz, runs it through a distortion stage to generate sub-bass harmonics (Drive), and mixes it back in with the rest of the signal (Gain). Adds weight and audibility to bass rather than colouring the whole signal.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Drive",
    "min": 0,
    "max": 1,
    "default": 0.33,
    "step": 0.01,
    "unit": "",
    "path": "/Bass_Boom/Drive"
   },
   {
    "label": "Gain",
    "min": -40,
    "max": 4,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Bass_Boom/Gain"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/bassboom.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"bboom\";\ndeclare name \"Bass Boom\";\ndeclare shortname \"B Boom\";\ndeclare category \"Distortion\";\ndeclare description \"Sub Bass Booster\";\n\nimport(\"stdfaust.lib\");\n\ngxc = library(\"clipping.lib\");\n\nanti_denormal = pow(10,-20);\nanti_denormal_ac = 1 - 1' : *(anti_denormal) : + ~ *(-1);\n\ngeq = fi.filterbank(3, (110));\n\nDrive     = hslider(\"Drive [tooltip: Amount of SubBass Harmonics]\", 0.33, 0, 1, 0.01);\n\nGain      = vslider(\"Gain\", 0, -40, 4, 0.1) : ba.db2linear : si.smooth(0.999);\n   \nbassclip(drive) = *(pregain) : preclip : clip : *(postgain) with {\n    pregain = pow(10.0,1.5*drive); \n    preclip =  min(1) : max(-1); \n    clip(x) = ((exp(x*4)-exp(-x*4*1.2))/(exp(x*4)+exp(-x*4)))/4;\n    postgain = max(1.0,1.0/(pregain*2.5));\n};\n    \nclip(drive) = *(pregain) : clip : *(postgain) with {\n    pregain = pow(10.0,2*drive);\nclip = gxc.symclip;\n    postgain = max(1.0,1.0/pregain);\n};\n \nprocess    = _: +(anti_denormal_ac): geq: ( _, dist1s) :> *(Gain) with { \n    dist1s = bassclip(Drive: si.smooth(0.999)) ;\n    \n};"
 },
 {
  "id": "gx-bassbooster",
  "name": "Bass Booster",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Second-order low shelf boost at 120 Hz with a single Level control.",
  "description": "A DAFX-style second-order low-shelving filter fixed at 120 Hz; Level sets the boost in dB. A clean low-end lift with no distortion.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".bassbooster.Level",
    "min": 0.5,
    "max": 20,
    "default": 10,
    "step": 0.5,
    "unit": "",
    "path": "/Bassbooster/.bassbooster.Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/bassbooster.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id     \"amp.bass_boost\";\ndeclare name   \"Bassbooster\";\ndeclare groups \".bassbooster[Bassbooster]\";\n\nimport(\"stdfaust.lib\");\n\n//------------------------------------------------------------------\n// DAFX, Digital Audio Effects (Wiley ed.)\n// chapter 2 : filters\n// section 2.3 : Equalizers\n// page 53 : second order shelving filter design\n//------------------------------------------------------------------\n\nlfboost(F,G) = fi.tf2(b0,b1,b2,a0,a1)\nwith {\n  V = ba.db2linear(G);\n  K = tan(ma.PI*F/ma.SR);\n  D = 1 + sqrt(2)*K + K*K;\n\n  b0 = (1 + sqrt(2*V)*K + V*K*K) / D;\n  b1 = 2 * (V*K*K - 1) / D;\n  b2 = (1 - sqrt(2*V)*K + V*K*K) / D;\n  a0 = 2 * (K*K - 1) / D;\n  a1 = (1 - sqrt(2)*K + K*K) / D;\n};\nlevel = vslider(\".bassbooster.Level\", 10, 0.5, 20, 0.5) ;\nprocess = lfboost(120, level);"
 },
 {
  "id": "gx-bigmuff",
  "name": "Big Muff Tone Stage",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Only the Big Muff Pi tone control: low-pass and high-pass blended by one knob.",
  "description": "Models just the Big Muff Pi passive tone stack as a 408 Hz low-pass and a 1.86 kHz high-pass mixed by the Tone knob. No distortion; the source notes it lacks the real unit's 1 kHz dip.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/gx_bigmuff/tone"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/bigmuff.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// Big Muff tone model\n//\n\nimport(\"stdfaust.lib\");\n\n// Is basically 2 filters mixed together with a knob.\n\n//Top filter is   39K( R1 ) -> 0.01u( C2 ) to ground - 408Hz fi.lowpass\n// Bottom filter is 3900pF( C1 )  -> 22k( R2 ) to ground - 1855.9Hz\n\n// Seems OK but does not create the 1K dip seen on real thing\n// assume that the tone pot needs better model as must intercat with the\n// other 2 filters such that at mid point both filters are still working \n// There should be interaction between the pot ( R3 ) and both of the other RC filters\n// Also as pot changes so do cutoff frequencies\n// Reduction moves both frequencies up by roughly 400Hz max\n// Increase moves both down by around same\n// So need +-400Hz calculated by current tone position\n// pot = 0  -> +400\n// pot = 1 -> -400\n\nbigmuff = _<: filter1,filter2:>_   with {\n\ttone = vslider(\"tone[style:knob]\",0.5,0,1,0.01);\n\tfilter1  = fi.highpass( 1, 1856):*(tone)  ;\n\tfilter2 = fi.lowpass( 1, 408 ) :*(1-tone ) ;\n};\nprocess = bigmuff ;"
 },
 {
  "id": "gx-mole",
  "name": "EHX Mole Bass Booster",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Electro-Harmonix Mole bass booster; single-knob low-end boost with wet/dry.",
  "description": "DK circuit simulation from the Mole schematic as a pot-dependent linear filter with a wet/dry blend. Boost lifts the low end for a fatter tone.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/The_Mole/wet_dry"
   },
   {
    "label": "Boost",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/The_Mole/Boost"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/mole.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"mole\";\ndeclare name \"The Mole\";\ndeclare category \"Tone Control\";\ndeclare shortname \"The Mole\";\ndeclare description \"EHX Mole\";\n\nimport(\"stdfaust.lib\");\n\nprocess = pre : _<:*(dry),(*(wet) : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0))):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    wet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\n    dry = 1 - wet;\n\n    \n        Boost = vslider(\"Boost[name:Boost]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = -9.74268345040146e-11*Boost*pow(fs,2);\n\n    b1 = 9.74268345040146e-11*Boost*pow(fs,2);\n\n    b2 = 9.74268345040146e-11*Boost*pow(fs,2);\n\n    b3 = -9.74268345040146e-11*Boost*pow(fs,2);\n\n    a0 = fs*(fs*(8.93878454194095e-15*fs + 4.96556855945694e-12) + 2.64572840995574e-11) + 2.70404912477885e-11;\n\n    a1 = fs*(fs*(-2.68163536258229e-14*fs - 4.96556855945694e-12) + 2.64572840995574e-11) + 8.11214737433656e-11;\n\n    a2 = fs*(fs*(2.68163536258229e-14*fs - 4.96556855945694e-12) - 2.64572840995574e-11) + 8.11214737433656e-11;\n\n    a3 = fs*(fs*(-8.93878454194095e-15*fs + 4.96556855945694e-12) - 2.64572840995574e-11) + 2.70404912477885e-11;\n};"
 },
 {
  "id": "ex-graphic-eq",
  "name": "Graphic EQ 7",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "Faust examples",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "7-band graphic equalizer built on fi.filterbank (Butterworth crossovers) with per-band gain",
  "description": "7-band graphic equalizer built on fi.filterbank (Butterworth crossovers) with per-band gain",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "100 Hz",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Graphic_EQ_7/100_Hz"
   },
   {
    "label": "200 Hz",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Graphic_EQ_7/200_Hz"
   },
   {
    "label": "400 Hz",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Graphic_EQ_7/400_Hz"
   },
   {
    "label": "800 Hz",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Graphic_EQ_7/800_Hz"
   },
   {
    "label": "1600 Hz",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Graphic_EQ_7/1600_Hz"
   },
   {
    "label": "3200 Hz",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Graphic_EQ_7/3200_Hz"
   },
   {
    "label": "6400 Hz",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Graphic_EQ_7/6400_Hz"
   }
  ],
  "faustCode": "declare name \"Graphic EQ 7\";\ndeclare description \"7-band graphic equalizer built on fi.filterbank (Butterworth crossovers) with per-band gain\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faust/examples/filtering/graphicEqLab.dsp fi.filterbank\";\ndeclare category \"guitar\";\ndeclare family \"utility\";\nimport(\"stdfaust.lib\");\n\ng(i, f) = hslider(\"[%i] %f Hz[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\ngains = g(0, 100), g(1, 200), g(2, 400), g(3, 800), g(4, 1600), g(5, 3200), g(6, 6400);\nprocess = fi.filterbank(3, (141, 283, 566, 1131, 2263, 4525)) : ro.cross(7) : par(i, 7, *(ba.take(i+1, gains))) :> _;"
 },
 {
  "id": "gx-hfb",
  "name": "HF Brightener",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Transistor high-frequency brightener with Volume and Intensity.",
  "description": "DK circuit simulation from the High Frequency Brightener schematic as a pot-dependent linear filter. Intensity adds sparkle and presence without distortion.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/HF_Brightener/Volume"
   },
   {
    "label": "Intensity",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/HF_Brightener/Intensity"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/hfb.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"hfb\";\ndeclare name \"HF Brightener\";\ndeclare category \"Tone Control\";\ndeclare shortname \"HF Brightener\";\ndeclare description \"High Frequency Brightener\";\n\nimport(\"stdfaust.lib\");\n\nprocess = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n    \n        Volume = vslider(\"Volume[name:Volume]\", 0.5, 0, 1, 0.01) : Inverted(1) : si.smooth(s);\n    \n        Intensity = vslider(\"Intensity[name:Intensity]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Intensity*(5.12666523663255e-23*Intensity*pow(fs,2) - 1.59041010538546e-9*pow(fs,2)) - 3.18082021077091e-10*Volume*pow(fs,2) - 1.06027340359031e-6*fs;\n\n    b1 = Intensity*(-1.02533304732651e-22*Intensity*pow(fs,2) + 3.18082021077092e-9*pow(fs,2)) + 6.36164042154183e-10*Volume*pow(fs,2);\n\n    b2 = Intensity*(5.12666523663255e-23*Intensity*pow(fs,2) - 1.59041010538546e-9*pow(fs,2)) - 3.18082021077091e-10*Volume*pow(fs,2) + 1.06027340359031e-6*fs;\n\n    a0 = Intensity*(Intensity*fs*(-1.17023754306854e-9*fs - 6.50608604711861e-8) + fs*(1.18275520407517e-9*fs + 6.61287722583147e-8)) + Volume*fs*(2.36551040815034e-10*fs + 1.32257544516629e-8) + 7.88503469383447e-7*fs + 4.40858481722098e-5;\n\n    a1 = Intensity*(2.34047508613708e-9*Intensity*pow(fs,2) - 2.36551040815034e-9*pow(fs,2)) - 4.73102081630068e-10*Volume*pow(fs,2) + 8.81716963444196e-5;\n\n    a2 = Intensity*(Intensity*fs*(-1.17023754306854e-9*fs + 6.50608604711861e-8) + fs*(1.18275520407517e-9*fs - 6.61287722583147e-8)) + Volume*fs*(2.36551040815034e-10*fs - 1.32257544516629e-8) - 7.88503469383447e-7*fs + 4.40858481722098e-5;\n};"
 },
 {
  "id": "gx-hogsfoot",
  "name": "Hogs Foot Bass Booster",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Electro-Harmonix Hog's Foot bass booster; low-end lift with a wet/dry blend.",
  "description": "DK circuit simulation from the Hog's Foot schematic as a pot-dependent linear filter with Volume and a wet/dry blend. A simple transistor bass booster for adding weight to the low end.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Hogs_Foot/wet_dry"
   },
   {
    "label": "Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Hogs_Foot/Volume"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/hogsfoot.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"hogsfoot\";\ndeclare name \"Hogs Foot\";\ndeclare category \"Tone Control\";\ndeclare shortname \"Hogs Foot\";\ndeclare description \"Hogs Foot Bass Booster\";\n\nimport(\"stdfaust.lib\");\n\nprocess = pre : _<:*(dry),(*(wet) : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0))):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n    wet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\n    dry = 1 - wet;\n\n    \n        Volume = vslider(\"Volume[name:Volume]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = -9.64632260709932e-11*Volume*pow(fs,2) - 9.64632260709932e-13*pow(fs,2);\n\n    b1 = 9.64632260709932e-11*Volume*pow(fs,2) + 9.64632260709932e-13*pow(fs,2);\n\n    b2 = 9.64632260709932e-11*Volume*pow(fs,2) + 9.64632260709932e-13*pow(fs,2);\n\n    b3 = -9.64632260709932e-11*Volume*pow(fs,2) - 9.64632260709932e-13*pow(fs,2);\n\n    a0 = fs*(fs*(8.93887847679127e-15*fs + 4.96106145708971e-12) + 2.63723081667839e-11) + 2.67730449581491e-11;\n\n    a1 = fs*(fs*(-2.68166354303738e-14*fs - 4.96106145708971e-12) + 2.63723081667839e-11) + 8.03191348744474e-11;\n\n    a2 = fs*(fs*(2.68166354303738e-14*fs - 4.96106145708971e-12) - 2.63723081667839e-11) + 8.03191348744474e-11;\n\n    a3 = fs*(fs*(-8.93887847679127e-15*fs + 4.96106145708971e-12) - 2.63723081667839e-11) + 2.67730449581491e-11;\n};"
 },
 {
  "id": "kpp-single2humbucker",
  "name": "KPP Single to Humbucker",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "KPP",
  "license": "GPL-3.0-or-later",
  "shortDesc": "Primitive humbucker imitation for single-coil guitars: comb from a second delayed coil, lowpass and mid bump, bass cut",
  "description": "Primitive humbucker imitation for single-coil guitars: comb from a second delayed coil, lowpass and mid bump, bass cut",
  "author": "Oleg Kapitonov",
  "flags": "",
  "params": [
   {
    "label": "Humbuckerize",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.001,
    "unit": "",
    "path": "/KPP_Single_to_Humbucker/Humbuckerize"
   },
   {
    "label": "Bass Cut",
    "min": 20,
    "max": 720,
    "default": 20,
    "step": 0.1,
    "unit": "Hz",
    "path": "/KPP_Single_to_Humbucker/Bass_Cut"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": -4,
    "step": 0.1,
    "unit": "dB",
    "path": "/KPP_Single_to_Humbucker/Level"
   }
  ],
  "faustCode": "declare name \"KPP Single to Humbucker\";\ndeclare description \"Primitive humbucker imitation for single-coil guitars: comb from a second delayed coil, lowpass and mid bump, bass cut\";\ndeclare author \"Oleg Kapitonov\";\ndeclare license \"GPL-3.0-or-later\";\ndeclare source \"olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_single2humbucker/kpp_single2humbucker.dsp\";\ndeclare category \"guitar\";\ndeclare family \"utility\";\nimport(\"stdfaust.lib\");\n\neffect_knob = hslider(\"[0] Humbuckerize\", 1, 0, 1, 0.001) : si.smoo;\nfilter_knob = hslider(\"[1] Bass Cut[unit:Hz]\", 20, 20, 720, 0.1) : si.smoo;\nlevel       = hslider(\"[2] Level[unit:dB]\", -4, -20, 20, 0.1) : ba.db2linear : si.smoo;\ndelay_samples = ma.SR / 2880 / 2;\neffect = fi.highpass(1,20) <: _, de.delay(50, delay_samples) : + : fi.lowpass(2, 5500) : fi.peak_eq(6.0, 550, 750);\nprocess = _ <: (*(effect_knob) : effect), (*(1.0 - effect_knob)) : + : fi.highpass(1, max(20, filter_knob)) : *(level);"
 },
 {
  "id": "ex-parametric-eq",
  "name": "Parametric EQ",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "Faust examples",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "Low shelf + peaking band + high shelf (fi.low_shelf / fi.peak_eq / fi.high_shelf) from the Faust parametric EQ example",
  "description": "Low shelf + peaking band + high shelf (fi.low_shelf / fi.peak_eq / fi.high_shelf) from the Faust parametric EQ example",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Low Gain",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Parametric_EQ/Low_Gain"
   },
   {
    "label": "Low Freq",
    "min": 20,
    "max": 2000,
    "default": 200,
    "step": 1,
    "unit": "Hz",
    "path": "/Parametric_EQ/Low_Freq"
   },
   {
    "label": "Peak Gain",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Parametric_EQ/Peak_Gain"
   },
   {
    "label": "Peak Freq",
    "min": 60,
    "max": 8000,
    "default": 1000,
    "step": 1,
    "unit": "Hz",
    "path": "/Parametric_EQ/Peak_Freq"
   },
   {
    "label": "Peak Q",
    "min": 0.5,
    "max": 20,
    "default": 2,
    "step": 0.1,
    "unit": "",
    "path": "/Parametric_EQ/Peak_Q"
   },
   {
    "label": "High Gain",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Parametric_EQ/High_Gain"
   },
   {
    "label": "High Freq",
    "min": 1000,
    "max": 12000,
    "default": 4000,
    "step": 1,
    "unit": "Hz",
    "path": "/Parametric_EQ/High_Freq"
   }
  ],
  "faustCode": "declare name \"Parametric EQ\";\ndeclare description \"Low shelf + peaking band + high shelf (fi.low_shelf / fi.peak_eq / fi.high_shelf) from the Faust parametric EQ example\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faust/examples/filtering/parametricEqualizer.dsp dm.parametric_eq_demo\";\ndeclare category \"guitar\";\ndeclare family \"utility\";\nimport(\"stdfaust.lib\");\n\nLL = hslider(\"[0] Low Gain[unit:dB]\", 0, -20, 20, 0.1) : si.smoo;\nFL = hslider(\"[1] Low Freq[unit:Hz][scale:log]\", 200, 20, 2000, 1) : si.smoo;\nLP = hslider(\"[2] Peak Gain[unit:dB]\", 0, -20, 20, 0.1) : si.smoo;\nFP = hslider(\"[3] Peak Freq[unit:Hz][scale:log]\", 1000, 60, 8000, 1) : si.smoo;\nQ  = hslider(\"[4] Peak Q\", 2, 0.5, 20, 0.1);\nLH = hslider(\"[5] High Gain[unit:dB]\", 0, -20, 20, 0.1) : si.smoo;\nFH = hslider(\"[6] High Freq[unit:Hz][scale:log]\", 4000, 1000, 12000, 1) : si.smoo;\nprocess = fi.low_shelf(LL, FL) : fi.peak_eq(LP, FP, FP/Q) : fi.high_shelf(LH, FH);"
 },
 {
  "id": "lib-speaker-sim",
  "name": "Speaker Bandpass",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Simple cabinet emulation: two DC-blocking highpasses and a 4th-order Butterworth lowpass",
  "description": "Simple cabinet emulation: two DC-blocking highpasses and a 4th-order Butterworth lowpass",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Low Cut",
    "min": 40,
    "max": 400,
    "default": 130,
    "step": 1,
    "unit": "Hz",
    "path": "/Speaker_Bandpass/Low_Cut"
   },
   {
    "label": "High Cut",
    "min": 2000,
    "max": 12000,
    "default": 5000,
    "step": 1,
    "unit": "Hz",
    "path": "/Speaker_Bandpass/High_Cut"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Speaker_Bandpass/Level"
   }
  ],
  "faustCode": "declare name \"Speaker Bandpass\";\ndeclare description \"Simple cabinet emulation: two DC-blocking highpasses and a 4th-order Butterworth lowpass\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/misceffects.lib ef.speakerbp\";\ndeclare category \"guitar\";\ndeclare family \"utility\";\nimport(\"stdfaust.lib\");\n\nf1 = hslider(\"[0] Low Cut[unit:Hz][scale:log]\", 130, 40, 400, 1) : si.smoo;\nf2 = hslider(\"[1] High Cut[unit:Hz][scale:log]\", 5000, 2000, 12000, 1) : si.smoo;\nlevel = hslider(\"[2] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\nprocess = ef.speakerbp(f1, f2) : *(level);"
 },
 {
  "id": "lib-spectral-tilt",
  "name": "Spectral Tilt",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "JOS spectral tilt filter: constant-slope dB/octave tilt across a chosen band (pink/brown-ish shaping)",
  "description": "JOS spectral tilt filter: constant-slope dB/octave tilt across a chosen band (pink/brown-ish shaping)",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Slope",
    "min": -1,
    "max": 1,
    "default": -0.5,
    "step": 0.001,
    "unit": "",
    "path": "/Spectral_Tilt/Slope"
   },
   {
    "label": "Band Start",
    "min": 20,
    "max": 10000,
    "default": 100,
    "step": 1,
    "unit": "Hz",
    "path": "/Spectral_Tilt/Band_Start"
   },
   {
    "label": "Band Width",
    "min": 100,
    "max": 10000,
    "default": 5000,
    "step": 1,
    "unit": "Hz",
    "path": "/Spectral_Tilt/Band_Width"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Spectral_Tilt/Level"
   }
  ],
  "faustCode": "declare name \"Spectral Tilt\";\ndeclare description \"JOS spectral tilt filter: constant-slope dB/octave tilt across a chosen band (pink/brown-ish shaping)\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faust/examples/filtering/spectralTilt.dsp fi.spectral_tilt\";\ndeclare category \"guitar\";\ndeclare family \"utility\";\nimport(\"stdfaust.lib\");\n\nalpha = hslider(\"[0] Slope\", -0.5, -1, 1, 0.001) : si.smoo;\nf0    = hslider(\"[1] Band Start[unit:Hz][scale:log]\", 100, 20, 10000, 1);\nbw    = hslider(\"[2] Band Width[unit:Hz]\", 5000, 100, 10000, 1);\nlevel = hslider(\"[3] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\nprocess = fi.spectral_tilt(4, f0, bw, alpha) : *(level);"
 },
 {
  "id": "gx-gxtilttone",
  "name": "Tilt Tone Pro",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Tilt-style tone control with Body and Drive and a soft clip stage; EQ with a little grit.",
  "description": "DK circuit simulation from the tilt-tone schematic: a 4th-order pot-dependent filter (Body, Tone, Drive) with input and output clip tables and a Level stage. Tone tilts the spectrum, lifting highs while cutting lows or vice versa, with mild saturation from Drive.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Body",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tilt_Tone_Pro/Body"
   },
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tilt_Tone_Pro/Tone"
   },
   {
    "label": "Drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tilt_Tone_Pro/Drive"
   },
   {
    "label": "Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tilt_Tone_Pro/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxtilttone.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"tiltdrive\";\ndeclare name \"Tilt Tone Pro\";\ndeclare category \"External\";\n\nimport(\"stdfaust.lib\");\n\n\ngxt = library(\"gx_tables.lib\");\n\np1 = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0)) : tiltdrivepro_inclip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n\n    Body = vslider(\"Body[name:Body]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n\n    Tone = vslider(\"Tone[name:Tone]\", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(1) : si.smooth(s);\n\n    Drive = vslider(\"Drive[name:Drive]\", 0.5, 0, 1, 0.01) : Inverted(1) : LogPot(1) : si.smooth(s);\n\n    b0 = Body*(Drive*fs*(fs*(7.4702418575578e-15*fs + 1.59088484003545e-12) + 5.76407550737481e-11) + Tone*(Drive*pow(fs,2)*(fs*(3.65730590942934e-18*fs + 6.09550984904878e-16) - 9.63708565903573e-28) + pow(fs,2)*(fs*(-3.65730590942934e-18*fs - 6.09550984904878e-16) + 9.63708565903573e-28)) + fs*(fs*(-7.4702418575578e-15*fs - 1.59088484003545e-12) - 5.76407550737481e-11)) + Drive*fs*(fs*(9.8607192519763e-16*fs + 3.66844210330959e-12) + 5.84016130407215e-10) + Tone*(Drive*fs*(fs*(fs*(4.82764380044673e-19*fs + 8.0460730007444e-17) - 3.45844530442491e-12) - 5.7640755073748e-10) + fs*(fs*(fs*(-4.82764380044673e-19*fs - 8.0460730007444e-17) + 3.45844530442491e-12) + 5.7640755073748e-10)) + fs*(fs*(-9.8607192519763e-16*fs - 3.66844210330959e-12) - 5.84016130407215e-10);\n\n    b1 = Body*(Drive*fs*(-1.49404837151156e-14*pow(fs,2) + 1.15281510147496e-10) + Tone*(Drive*pow(fs,3)*(-1.46292236377174e-17*fs - 1.21910196980976e-15) + pow(fs,3)*(1.46292236377174e-17*fs + 1.21910196980976e-15)) + fs*(1.49404837151156e-14*pow(fs,2) - 1.15281510147496e-10)) + Drive*fs*(-1.97214385039526e-15*pow(fs,2) + 1.16803226081443e-9) + Tone*(Drive*fs*(pow(fs,2)*(-1.93105752017869e-18*fs - 1.60921460014888e-16) - 1.15281510147496e-9) + fs*(pow(fs,2)*(1.93105752017869e-18*fs + 1.60921460014888e-16) + 1.15281510147496e-9)) + fs*(1.97214385039526e-15*pow(fs,2) - 1.16803226081443e-9);\n\n    b2 = Body*(-3.18176968007089e-12*Drive*pow(fs,2) + Tone*(Drive*pow(fs,2)*(2.1943835456576e-17*pow(fs,2) + 1.92741713180715e-27) + pow(fs,2)*(-2.1943835456576e-17*pow(fs,2) - 1.92741713180715e-27)) + 3.18176968007089e-12*pow(fs,2)) - 7.33688420661919e-12*Drive*pow(fs,2) + Tone*(Drive*pow(fs,2)*(2.89658628026804e-18*pow(fs,2) + 6.91689060884983e-12) + pow(fs,2)*(-2.89658628026804e-18*pow(fs,2) - 6.91689060884983e-12)) + 7.33688420661919e-12*pow(fs,2);\n\n    b3 = Body*(Drive*fs*(1.49404837151156e-14*pow(fs,2) - 1.15281510147496e-10) + Tone*(Drive*pow(fs,3)*(-1.46292236377174e-17*fs + 1.21910196980976e-15) + pow(fs,3)*(1.46292236377174e-17*fs - 1.21910196980976e-15)) + fs*(-1.49404837151156e-14*pow(fs,2) + 1.15281510147496e-10)) + Drive*fs*(1.97214385039526e-15*pow(fs,2) - 1.16803226081443e-9) + Tone*(Drive*fs*(pow(fs,2)*(-1.93105752017869e-18*fs + 1.60921460014888e-16) + 1.15281510147496e-9) + fs*(pow(fs,2)*(1.93105752017869e-18*fs - 1.60921460014888e-16) - 1.15281510147496e-9)) + fs*(-1.97214385039526e-15*pow(fs,2) + 1.16803226081443e-9);\n\n    b4 = Body*(Drive*fs*(fs*(-7.4702418575578e-15*fs + 1.59088484003545e-12) - 5.76407550737481e-11) + Tone*(Drive*pow(fs,2)*(fs*(3.65730590942934e-18*fs - 6.09550984904878e-16) - 9.63708565903573e-28) + pow(fs,2)*(fs*(-3.65730590942934e-18*fs + 6.09550984904878e-16) + 9.63708565903573e-28)) + fs*(fs*(7.4702418575578e-15*fs - 1.59088484003545e-12) + 5.76407550737481e-11)) + Drive*fs*(fs*(-9.8607192519763e-16*fs + 3.66844210330959e-12) - 5.84016130407215e-10) + Tone*(Drive*fs*(fs*(fs*(4.82764380044673e-19*fs - 8.0460730007444e-17) - 3.45844530442491e-12) + 5.7640755073748e-10) + fs*(fs*(fs*(-4.82764380044673e-19*fs + 8.0460730007444e-17) + 3.45844530442491e-12) - 5.7640755073748e-10)) + fs*(fs*(9.8607192519763e-16*fs - 3.66844210330959e-12) + 5.84016130407215e-10);\n\n    a0 = Body*(Drive*(Drive*(fs*(fs*(fs*(-7.30862585054866e-20*fs - 1.67322263662277e-16) - 5.1124129373811e-14) - 1.94898394972096e-12) + 1.96683234297117e-25) + fs*(fs*(fs*(7.30862585054866e-20*fs + 1.42960177493781e-16) + 3.6417513972127e-14) - 5.41394578846342e-14) - 4.14677436110847e-11) + Tone*(Drive*(fs*(fs*(fs*(-1.82715646263716e-20*fs - 1.61866577328053e-18) + 8.22617247056166e-17) - 4.8724598743024e-13) + 4.91708085742792e-26) + Tone*(Drive*fs*(fs*(fs*(1.61878313287101e-20*fs + 1.69238926121966e-17) + 3.65434490572681e-15) - 3.68781064307094e-28) + fs*(fs*(fs*(-3.23756626574203e-20*fs - 3.38477852243932e-17) - 7.30868981145362e-15) + 7.37562128614188e-28)) + fs*(fs*(fs*(3.65431292527433e-20*fs + 3.23733154656106e-18) - 1.64523449411233e-16) + 9.7449197486048e-13) - 9.83416171485584e-26) + fs*(fs*(fs*(7.30862585054866e-20*fs + 2.16046435999268e-16) + 8.0537360177179e-14) + 5.95523076493215e-12) + 8.29354872221687e-11) + Drive*(Drive*(fs*(fs*(fs*(-9.29967180291844e-20*fs - 3.84360911986598e-16) - 4.45548735927406e-13) - 9.98720416827966e-11) - 1.65870974444338e-9) + fs*(fs*(fs*(9.29967180291844e-20*fs + 3.5336200597687e-16) + 3.79597819598007e-13) + 8.2686476087768e-11) + 1.23855856617587e-9) + Tone*(Drive*(fs*(fs*(fs*(-2.32491795072961e-20*fs - 3.52160359068941e-17) + 1.83300570278997e-14) + 8.87429618975008e-12) + 4.14677436110845e-10) + Tone*(Drive*(fs*(fs*(fs*(2.29741267120048e-20*fs + 6.50194364851177e-17) + 4.61728181436945e-14) + 7.98254064513374e-12) - 4.91708085742792e-25) + fs*(fs*(fs*(-4.59482534240096e-20*fs - 1.30038872970235e-16) - 9.23456362873891e-14) - 1.59650812902675e-11) + 9.83416171485584e-25) + fs*(fs*(fs*(4.64983590145922e-20*fs + 7.04320718137881e-17) - 3.66601140557995e-14) - 1.77485923795002e-11) - 8.2935487222169e-10) + fs*(fs*(fs*(9.29967180291844e-20*fs + 4.46358724006055e-16) + 5.77450568586205e-13) + 1.34243172872854e-10) + 2.49901210097839e-9;\n\n    a1 = Body*(Drive*(Drive*(fs*(pow(fs,2)*(2.92345034021946e-19*fs + 3.34644527324554e-16) - 3.89796789944192e-12) + 7.86732937188467e-25) + fs*(pow(fs,2)*(-2.92345034021946e-19*fs - 2.85920354987563e-16) - 1.08278915769268e-13) - 1.65870974444339e-10) + Tone*(Drive*(fs*(pow(fs,2)*(7.30862585054866e-20*fs + 3.23733154656106e-18) - 9.7449197486048e-13) + 1.96683234297117e-25) + Tone*(Drive*fs*(pow(fs,2)*(-6.47513253148406e-20*fs - 3.38477852243932e-17) - 7.37562128614188e-28) + fs*(pow(fs,2)*(1.29502650629681e-19*fs + 6.76955704487864e-17) + 1.47512425722838e-27)) + fs*(pow(fs,2)*(-1.46172517010973e-19*fs - 6.47466309312212e-18) + 1.94898394972096e-12) - 3.93366468594234e-25) + fs*(pow(fs,2)*(-2.92345034021946e-19*fs - 4.32092871998536e-16) + 1.19104615298643e-11) + 3.31741948888675e-10) + Drive*(Drive*(fs*(pow(fs,2)*(3.71986872116738e-19*fs + 7.68721823973197e-16) - 1.99744083365593e-10) - 6.63483897777351e-9) + fs*(pow(fs,2)*(-3.71986872116738e-19*fs - 7.06724011953741e-16) + 1.65372952175536e-10) + 4.95423426470347e-9) + Tone*(Drive*(fs*(pow(fs,2)*(9.29967180291844e-20*fs + 7.04320718137881e-17) + 1.77485923795002e-11) + 1.65870974444338e-9) + Tone*(Drive*(fs*(pow(fs,2)*(-9.18965068480191e-20*fs - 1.30038872970235e-16) + 1.59650812902675e-11) - 1.96683234297117e-24) + fs*(pow(fs,2)*(1.83793013696038e-19*fs + 2.60077745940471e-16) - 3.1930162580535e-11) + 3.93366468594234e-24) + fs*(pow(fs,2)*(-1.85993436058369e-19*fs - 1.40864143627576e-16) - 3.54971847590003e-11) - 3.31741948888676e-9) + fs*(pow(fs,2)*(-3.71986872116738e-19*fs - 8.92717448012109e-16) + 2.68486345745707e-10) + 9.99604840391357e-9;\n\n    a2 = Body*(Drive*(Drive*(pow(fs,2)*(-4.38517551032919e-19*pow(fs,2) + 1.02248258747622e-13) + 1.1800994057827e-24) + pow(fs,2)*(4.38517551032919e-19*pow(fs,2) - 7.2835027944254e-14) - 2.48806461666508e-10) + Tone*(Drive*(pow(fs,2)*(-1.0962938775823e-19*pow(fs,2) - 1.64523449411233e-16) + 2.95024851445675e-25) + Tone*(Drive*pow(fs,2)*(9.71269879722608e-20*pow(fs,2) - 7.30868981145362e-15) + pow(fs,2)*(-1.94253975944522e-19*pow(fs,2) + 1.46173796229072e-14)) + pow(fs,2)*(2.1925877551646e-19*pow(fs,2) + 3.29046898822466e-16) - 5.90049702891351e-25) + pow(fs,2)*(4.38517551032919e-19*pow(fs,2) - 1.61074720354358e-13) + 4.97612923333012e-10) + Drive*(Drive*(pow(fs,2)*(-5.57980308175106e-19*pow(fs,2) + 8.91097471854812e-13) - 9.95225846666026e-9) + pow(fs,2)*(5.57980308175106e-19*pow(fs,2) - 7.59195639196014e-13) + 7.43135139705521e-9) + Tone*(Drive*(pow(fs,2)*(-1.39495077043777e-19*pow(fs,2) - 3.66601140557995e-14) + 2.48806461666507e-9) + Tone*(Drive*(pow(fs,2)*(1.37844760272029e-19*pow(fs,2) - 9.23456362873891e-14) - 2.95024851445675e-24) + pow(fs,2)*(-2.75689520544057e-19*pow(fs,2) + 1.84691272574778e-13) + 5.90049702891351e-24) + pow(fs,2)*(2.78990154087553e-19*pow(fs,2) + 7.33202281115989e-14) - 4.97612923333014e-9) + pow(fs,2)*(5.57980308175106e-19*pow(fs,2) - 1.15490113717241e-12) + 1.49940726058704e-8;\n\n    a3 = Body*(Drive*(Drive*(fs*(pow(fs,2)*(2.92345034021946e-19*fs - 3.34644527324554e-16) + 3.89796789944192e-12) + 7.86732937188467e-25) + fs*(pow(fs,2)*(-2.92345034021946e-19*fs + 2.85920354987563e-16) + 1.08278915769268e-13) - 1.65870974444339e-10) + Tone*(Drive*(fs*(pow(fs,2)*(7.30862585054866e-20*fs - 3.23733154656106e-18) + 9.7449197486048e-13) + 1.96683234297117e-25) + Tone*(Drive*fs*(pow(fs,2)*(-6.47513253148406e-20*fs + 3.38477852243932e-17) + 7.37562128614188e-28) + fs*(pow(fs,2)*(1.29502650629681e-19*fs - 6.76955704487864e-17) - 1.47512425722838e-27)) + fs*(pow(fs,2)*(-1.46172517010973e-19*fs + 6.47466309312212e-18) - 1.94898394972096e-12) - 3.93366468594234e-25) + fs*(pow(fs,2)*(-2.92345034021946e-19*fs + 4.32092871998536e-16) - 1.19104615298643e-11) + 3.31741948888675e-10) + Drive*(Drive*(fs*(pow(fs,2)*(3.71986872116738e-19*fs - 7.68721823973197e-16) + 1.99744083365593e-10) - 6.63483897777351e-9) + fs*(pow(fs,2)*(-3.71986872116738e-19*fs + 7.06724011953741e-16) - 1.65372952175536e-10) + 4.95423426470347e-9) + Tone*(Drive*(fs*(pow(fs,2)*(9.29967180291844e-20*fs - 7.04320718137881e-17) - 1.77485923795002e-11) + 1.65870974444338e-9) + Tone*(Drive*(fs*(pow(fs,2)*(-9.18965068480191e-20*fs + 1.30038872970235e-16) - 1.59650812902675e-11) - 1.96683234297117e-24) + fs*(pow(fs,2)*(1.83793013696038e-19*fs - 2.60077745940471e-16) + 3.1930162580535e-11) + 3.93366468594234e-24) + fs*(pow(fs,2)*(-1.85993436058369e-19*fs + 1.40864143627576e-16) + 3.54971847590003e-11) - 3.31741948888676e-9) + fs*(pow(fs,2)*(-3.71986872116738e-19*fs + 8.92717448012109e-16) - 2.68486345745707e-10) + 9.99604840391357e-9;\n\n    a4 = Body*(Drive*(Drive*(fs*(fs*(fs*(-7.30862585054866e-20*fs + 1.67322263662277e-16) - 5.1124129373811e-14) + 1.94898394972096e-12) + 1.96683234297117e-25) + fs*(fs*(fs*(7.30862585054866e-20*fs - 1.42960177493781e-16) + 3.6417513972127e-14) + 5.41394578846342e-14) - 4.14677436110847e-11) + Tone*(Drive*(fs*(fs*(fs*(-1.82715646263716e-20*fs + 1.61866577328053e-18) + 8.22617247056166e-17) + 4.8724598743024e-13) + 4.91708085742792e-26) + Tone*(Drive*fs*(fs*(fs*(1.61878313287101e-20*fs - 1.69238926121966e-17) + 3.65434490572681e-15) + 3.68781064307094e-28) + fs*(fs*(fs*(-3.23756626574203e-20*fs + 3.38477852243932e-17) - 7.30868981145362e-15) - 7.37562128614188e-28)) + fs*(fs*(fs*(3.65431292527433e-20*fs - 3.23733154656106e-18) - 1.64523449411233e-16) - 9.7449197486048e-13) - 9.83416171485584e-26) + fs*(fs*(fs*(7.30862585054866e-20*fs - 2.16046435999268e-16) + 8.0537360177179e-14) - 5.95523076493215e-12) + 8.29354872221687e-11) + Drive*(Drive*(fs*(fs*(fs*(-9.29967180291844e-20*fs + 3.84360911986598e-16) - 4.45548735927406e-13) + 9.98720416827966e-11) - 1.65870974444338e-9) + fs*(fs*(fs*(9.29967180291844e-20*fs - 3.5336200597687e-16) + 3.79597819598007e-13) - 8.2686476087768e-11) + 1.23855856617587e-9) + Tone*(Drive*(fs*(fs*(fs*(-2.32491795072961e-20*fs + 3.52160359068941e-17) + 1.83300570278997e-14) - 8.87429618975008e-12) + 4.14677436110845e-10) + Tone*(Drive*(fs*(fs*(fs*(2.29741267120048e-20*fs - 6.50194364851177e-17) + 4.61728181436945e-14) - 7.98254064513374e-12) - 4.91708085742792e-25) + fs*(fs*(fs*(-4.59482534240096e-20*fs + 1.30038872970235e-16) - 9.23456362873891e-14) + 1.59650812902675e-11) + 9.83416171485584e-25) + fs*(fs*(fs*(4.64983590145922e-20*fs - 7.04320718137881e-17) - 3.66601140557995e-14) + 1.77485923795002e-11) - 8.2935487222169e-10) + fs*(fs*(fs*(9.29967180291844e-20*fs - 4.46358724006055e-16) + 5.77450568586205e-13) - 1.34243172872854e-10) + 2.49901210097839e-9;\n};\n\ntiltdrivepro_inclip = _<: ba.if(signbit(_), tiltdrivepro_in_neg_clip, tiltdrivepro_in_clip) :>_ with {\nsignbit(x) = (x < 0);tiltdrivepro_in_clip = gxt.tiltdrivepro_inclip;tiltdrivepro_in_neg_clip = gxt.tiltdrivepro_in_negclip;\n};\np2 = pre : fi.iir((b0/a0,b1/a0),(a1/a0)) : tiltdrivepro_out_3clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n    Level = vslider(\"Level[name:Level]\", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(3) : si.smooth(s);\n\n    b0 = -0.000487217249496405*Level*fs;\n\n    b1 = 0.000487217249496405*Level*fs;\n\n    a0 = 2.08313095376176e-5*fs + 9.71421943566398e-5;\n\n    a1 = -2.08313095376176e-5*fs + 9.71421943566398e-5;\n};\n\ntiltdrivepro_out_3clip = _<: ba.if(signbit(_), tiltdrivepro_out_3_neg_clip, tiltdrivepro_out_3_clip) :>_ with {\nsignbit(x) = (x < 0);tiltdrivepro_out_3_clip = gxt.tiltdrivepro_out_3clip;tiltdrivepro_out_3_neg_clip = gxt.tiltdrivepro_out_3_negclip;\n};\n\n\namp =  p1 : p2 ;\nfreq_split = fi.filterbank(3, (86.0,210.0,1200.0,6531.0));\nprocess    = freq_split: ( amp , amp , amp, amp, amp) :>_;"
 },
 {
  "id": "gx-tone",
  "name": "Tone (Bass/Mid/Treble shelves)",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Three-band shelving/peak tone control from the RBJ Audio EQ Cookbook, ±20 dB.",
  "description": "Low shelf, mid peak and high shelf filters at fixed frequencies (RBJ Audio EQ Cookbook) with Bass, Middle and Treble gains of ±20 dB. A clean, non-interactive three-band tone control.",
  "author": "brummer",
  "flags": "-double",
  "params": [
   {
    "label": "bass",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_tone/bass"
   },
   {
    "label": "middle",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_tone/middle"
   },
   {
    "label": "treble",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_tone/treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tone.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \t\t\"amp.tone\";\ndeclare version \t\"0.01\";\ndeclare author \t\t\"brummer\";\ndeclare license \t\"BSD\";\ndeclare copyright \t\"(c)brummer 2008\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\n/*-----------------------------------------------\n\t\t      The tone control\n   Low and high shelf filters, from Robert Bristow-Johnson's \"Audio\n   EQ Cookbook\", see http://www.musicdsp.org/files/Audio-EQ-Cookbook.txt.\n  -----------------------------------------------*/\n\nfilter(b0,b1,b2,a0,a1,a2)\t= f : (+ ~ g)\nwith {\n\tf(x)\t= (b0/a0)*x+(b1/a0)*x'+(b2/a0)*x'';\n\tg(y)\t= 0-(a1/a0)*y-(a2/a0)*y';\n};\n\ngxlow_shelf(f0,g)\t\t= filter(b0,b1,b2,a0,a1,a2)\nwith {\n\tS  \t\t= 1;\n\tA  \t\t= pow(10,g/40);\n\tw0 \t\t= 2*ma.PI*f0/ma.SR;\n\talpha \t= sin(w0)/2 * sqrt( (A + 1/A)*(1/S - 1) + 2 );\n\n\tb0 \t\t=    A*( (A+1) - (A-1)*cos(w0) + 2*sqrt(A)*alpha );\n\tb1 \t\t=  2*A*( (A-1) - (A+1)*cos(w0)                   );\n\tb2 \t\t=    A*( (A+1) - (A-1)*cos(w0) - 2*sqrt(A)*alpha );\n\ta0 \t\t=        (A+1) + (A-1)*cos(w0) + 2*sqrt(A)*alpha;\n\ta1 \t\t=   -2*( (A-1) + (A+1)*cos(w0)                   );\n\ta2 \t\t=        (A+1) + (A-1)*cos(w0) - 2*sqrt(A)*alpha;\n};\n\ngxhigh_shelf(f0,g)\t= filter(b0,b1,b2,a0,a1,a2)\nwith {\n\tS  \t\t= 1;\n\tA  \t\t= pow(10,g/40);\n\tw0 \t\t= 2*ma.PI*f0/ma.SR;\n\talpha \t= sin(w0)/2 * sqrt( (A + 1/A)*(1/S - 1) + 2 );\n\n\tb0 \t\t=    A*( (A+1) + (A-1)*cos(w0) + 2*sqrt(A)*alpha );\n\tb1 \t\t= -2*A*( (A-1) + (A+1)*cos(w0)                   );\n\tb2 \t\t=    A*( (A+1) + (A-1)*cos(w0) - 2*sqrt(A)*alpha );\n\ta0 \t\t=        (A+1) - (A-1)*cos(w0) + 2*sqrt(A)*alpha;\n\ta1 \t\t=    2*( (A-1) - (A+1)*cos(w0)                   );\n\ta2 \t\t=        (A+1) - (A-1)*cos(w0) - 2*sqrt(A)*alpha;\n};\n\n/* Fixed bass and treble frequencies.*/\nbass_freq\t= 600;\ntreble_freq\t= 2400;\n\nbass_gain\t= vslider(\"bass[name:bass]\", 0, -20, 20, 0.1);\nmid_gain\t= vslider(\"middle[name:middle]\", 0, -20, 20, 0.1)/2;\ntreble_gain\t= vslider(\"treble[name:treble]\", 0, -20, 20, 0.1);\ntone(b,m,t)     = gxlow_shelf(bass_freq,b-m) :\n\t\t\t\t  gxlow_shelf(treble_freq,m):\n                  gxhigh_shelf(bass_freq,m) :\n                  gxhigh_shelf(treble_freq,t-m);\nprocess\t\t= add_dc :\n                  gxlow_shelf(bass_freq,bass_gain-mid_gain) :\n                  gxlow_shelf(treble_freq,mid_gain):\n                  gxhigh_shelf(bass_freq,mid_gain) :\n                  gxhigh_shelf(treble_freq,treble_gain-mid_gain);"
 },
 {
  "id": "gx-tonestack-ampeg-rev",
  "name": "Tone Stack — Ampeg Reverberocket",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Ampeg Reverberocket values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Ampeg Reverberocket. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Rev.Rocket/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Rev.Rocket/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Rev.Rocket/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_ampeg_rev.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Rev.Rocket\"; // in tonestack ba.selector\ndeclare name \"Rev.Rocket\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.ampeg_rev;];"
 },
 {
  "id": "gx-tonestack-ampeg",
  "name": "Tone Stack — Ampeg VL-501",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Ampeg VL-501 component values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Ampeg VL-501. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Ampeg/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Ampeg/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Ampeg/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_ampeg.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Ampeg\"; // in tonestack ba.selector\ndeclare name \"Ampeg\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.ampeg;];"
 },
 {
  "id": "gx-tonestack-bm",
  "name": "Tone Stack — Bassman (single Tone knob)",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Bassman passive tone stack driven by one Tone knob that moves all three bands.",
  "description": "The Bassman 5F6-A passive tone stack model with a single Tone control linked to Bass, Middle and Treble at once. A one-knob variant for simple pedal layouts.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/gx_tonestack_bm/.amp.tonestack.tone"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_bm.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n//tonestack ba.selector\n\ndeclare id \t\t\"tonestack_bm\";\n\nimport(\"stdfaust.lib\");\n\n/****************************************************************\n **           Equalisation 3 bandes\n **                    C1\n **       IN >---------||---------\n **            |                 |\n **           | | R4            | | R1 Treble\n **           | |               | |<------<  Out\n **           | |               | | \n **            |       C2        |\n **            |-------||--------|------\n **            |                 |     |\n **            |                | |    |\n **            |                | |<---- R2 Bass\n **            |                | |\n **            |                 |\n **            |       C3       | |\n **            --------||------>| |  R3 Middle\n **                             | |\n **                              |\n **                             _|_\n **                              -\n */\n/****************************************************************\n ** Guitar tone stacks\n ** values from CAPS plugin tonestack (based on work from D.T. Yeh)\n ** this version use only one controller like the Big Muff\n */\n \nts = environment {\n    k = *(1e3);\n    M = *(1e6);\n    nF = *(1e-9);\n    pF = *(1e-12);\n\n    /* Fender */\n\n    bassman = environment { /* 59 Bassman 5F6-A */\n\tR1 = 250:k;\n        R2 = 1:M;\n        R3 = 25:k;\n        R4 = 56:k;\n        C1 = 250:pF;\n        C2 = 20:nF;\n        C3 = 20:nF;\n        };\n        \n    \n    mesa = environment { /* Mesa Boogie Mark */\n\tR1 = 250:k;\n        R2 = 250:k;\n        R3 = 25:k;\n        R4 = 100:k;\n        C1 = 250:pF;\n        C2 = 100:nF;\n        C3 = 47:nF;\n        };\n        \n    twin = environment { /* 69 Twin Reverb AA270 */\n\tR1 = 250:k;\n        R2 = 250:k;\n        R3 = 10:k;\n        R4 = 100:k;\n        C1 = 120:pF;\n        C2 = 100:nF;\n        C3 = 47:nF;\n        };\n\n    princeton = environment { /* 64 Princeton AA1164 */\n\tR1 = 250:k;\n        R2 = 250:k;\n        R3 = 4.8:k;\n        R4 = 100:k;\n        C1 = 250:pF;\n        C2 = 100:nF;\n        C3 = 47:nF;\n        };\n\n    /* Marshall */\n\n    jcm800 = environment { /* 59/81 JCM-800 Lead 100 2203 */\n\tR1 = 220:k;\n        R2 = 1:M;\n        R3 = 22:k;\n        R4 = 33:k;\n        C1 = 470:pF;\n        C2 = 22:nF;\n        C3 = 22:nF;\n        };\n    /* 90 JCM-900 Master 2100: same as JCM-800 */\n\n    jcm2000 = environment { /* 81 2000 Lead */\n\tR1 = 250:k;\n        R2 = 1:M;\n        R3 = 25:k;\n        R4 = 56:k; /* a 10 k fixed + 100 k pot in series actually */\n        C1 = 500:pF;\n        C2 = 22:nF;\n        C3 = 22:nF;\n        };\n        \n    jtm45 = environment { /* JTM 45 */\n\tR1 = 250:k;\n        R2 = 1:M;\n        R3 = 25:k;\n        R4 = 33:k; \n        C1 = 270:pF;\n        C2 = 22:nF;\n        C3 = 22:nF;\n        };\n\n\t/* parameter order is R1 - R4, C1 - C3 */\n    mlead = environment { /* 67 Major Lead 200 */\n\tR1 = 250:k;\n        R2 = 1:M;\n        R3 = 25:k;\n        R4 = 33:k;\n        C1 = 500:pF;\n        C2 = 22:nF;\n        C3 = 22:nF;\n        };\n\n    m2199 = environment { /* undated M2199 30W solid state */\n        R1 = 250:k;\n        R2 = 250:k;\n        R3 = 25:k;\n        R4 = 56:k;\n        C1 = 250:pF;\n        C2 = 47:nF;\n        C3 = 47:nF;\n        };\n\n    /* Vox */\n    ac30 = environment { /* 59/86 AC-30 */\n        /* R3 is fixed (circuit differs anyway) */\n        R1 = 1:M;\n        R2 = 1:M;\n        R3 = 10:k;\n        R4 = 100:k;\n        C1 = 50:pF;\n        C2 = 22:nF;\n        C3 = 22:nF;\n        };\n        \n    ac15 = environment { /* VOX AC-15 */\n    R1 = 220:k;\n        R2 = 220:k;\n        R3 = 220:k;\n        R4 = 100:k;\n        C1 = 470:pF;\n        C2 = 100:nF;\n        C3 = 47:nF;\n        };\n        \n    soldano = environment { /* Soldano SLO 100 */\n\tR1 = 250:k;\n        R2 = 1:M;\n        R3 = 25:k;\n        R4 = 47:k;\n        C1 = 470:pF;\n        C2 = 20:nF;\n        C3 = 20:nF;\n        };\n        \n    sovtek = environment { /* MIG 100 H*/\n\tR1 = 500:k;\n        R2 = 1:M;\n        R3 = 10:k;\n        R4 = 47:k;\n        C1 = 470:pF;\n        C2 = 22:nF;\n        C3 = 22:nF;\n        };\n\n    peavey = environment { /* c20*/\n\tR1 = 250:k;\n        R2 = 250:k;\n        R3 = 20:k;\n        R4 = 68:k;\n        C1 = 270:pF;\n        C2 = 22:nF;\n        C3 = 22:nF;\n        };\n        \n    ibanez = environment { /* gx20 */\n\tR1 = 250:k;\n        R2 = 250:k;\n        R3 = 10:k;\n        R4 = 100:k;\n        C1 = 270:pF;\n        C2 = 100:nF;\n        C3 = 40:nF;\n        };\n        \n    roland = environment { /* Cube 60 */\n\tR1 = 250:k;\n        R2 = 250:k;\n        R3 = 10:k;\n        R4 = 41:k;\n        C1 = 240:pF;\n        C2 = 33:nF;\n        C3 = 82:nF;\n        };\n        \n    ampeg = environment { /* VL 501 */\n\tR1 = 250:k;\n        R2 = 1:M;\n        R3 = 25:k;\n        R4 = 32:k;\n        C1 = 470:pF;\n        C2 = 22:nF;\n        C3 = 22:nF;\n        };\n    \n    ampeg_rev = environment { /* reverbrocket*/\n\tR1 = 250:k;\n        R2 = 250:k;\n        R3 = 10:k;\n        R4 = 100:k;\n        C1 = 100:pF;\n        C2 = 100:nF;\n        C3 = 47:nF;\n        };\n        \n    bogner = environment { /* Triple Giant Preamp  */\n\tR1 = 250:k;\n        R2 = 1:M;\n        R3 = 33:k;\n        R4 = 51:k;\n        C1 = 220:pF;\n        C2 = 15:nF;\n        C3 = 47:nF;\n        };\n        \n    groove = environment { /* Trio Preamp  */\n\tR1 = 220:k;\n        R2 = 1:M;\n        R3 = 22:k;\n        R4 = 68:k;\n        C1 = 470:pF;\n        C2 = 22:nF;\n        C3 = 22:nF;\n        };\n        \n    crunch = environment { /* Hughes&Kettner  */\n\tR1 = 220:k;\n        R2 = 220:k;\n        R3 = 10:k;\n        R4 = 100:k;\n        C1 = 220:pF;\n        C2 = 47:nF;\n        C3 = 47:nF;\n        };\n        \n    fender_blues = environment { /* Fender blues junior  */\n    R1 = 250:k;\n        R2 = 250:k;\n        R3 = 25:k;\n        R4 = 100:k;\n        C1 = 250:pF;\n        C2 = 22:nF;\n        C3 = 22:nF;\n        };\n        \n    fender_default = environment { /* Fender   */\n    R1 = 250:k;\n        R2 = 250:k;\n        R3 = 10:k;\n        R4 = 100:k;\n        C1 = 250:pF;\n        C2 = 100:nF;\n        C3 = 47:nF;\n        };\n        \n    fender_deville = environment { /* Fender Hot Rod  */\n    R1 = 250:k;\n        R2 = 250:k;\n        R3 = 25:k;\n        R4 = 130:k;\n        C1 = 250:pF;\n        C2 = 100:nF;\n        C3 = 22:nF;\n        };\n        \n    gibsen = environment { /* gs12 reverbrocket   */\n    R1 = 1:M;\n        R2 = 1:M;\n        R3 = 94:k;  // 47k fixed\n        R4 = 270:k;\n        C1 = 25:pF;\n        C2 = 60:nF;\n        C3 = 20:nF;\n        };\n        \n    \n};\n\nt = vslider(\".amp.tonestack.tone[alias]\", 0.5, 0, 1, 0.01);\nm = 0.5;\nl = 1-t : (_-1)*3.4 : exp;\n\ntonestack = 1/A0*fi.iir((B0,B1,B2,B3),(A1/A0,A2/A0,A3/A0)) with {\n    C1 = tse.C1;\n    C2 = tse.C2;\n    C3 = tse.C3;\n    R1 = tse.R1;\n    R2 = tse.R2;\n    R3 = tse.R3;\n    R4 = tse.R4;\n\n    b1 = t*C1*R1 + m*C3*R3 + l*(C1*R2 + C2*R2) + (C1*R3 + C2*R3);\n\n    b2 = t*(C1*C2*R1*R4 + C1*C3*R1*R4) - m*m*(C1*C3*R3*R3 + C2*C3*R3*R3)\n         + m*(C1*C3*R1*R3 + C1*C3*R3*R3 + C2*C3*R3*R3)\n         + l*(C1*C2*R1*R2 + C1*C2*R2*R4 + C1*C3*R2*R4)\n         + l*m*(C1*C3*R2*R3 + C2*C3*R2*R3)\n         + (C1*C2*R1*R3 + C1*C2*R3*R4 + C1*C3*R3*R4);\n\n    b3 = l*m*(C1*C2*C3*R1*R2*R3 + C1*C2*C3*R2*R3*R4)\n         - m*m*(C1*C2*C3*R1*R3*R3 + C1*C2*C3*R3*R3*R4)\n         + m*(C1*C2*C3*R1*R3*R3 + C1*C2*C3*R3*R3*R4)\n         + t*C1*C2*C3*R1*R3*R4 - t*m*C1*C2*C3*R1*R3*R4\n         + t*l*C1*C2*C3*R1*R2*R4;\n\n    a0 = 1;\n\n    a1 = (C1*R1 + C1*R3 + C2*R3 + C2*R4 + C3*R4)\n         + m*C3*R3 + l*(C1*R2 + C2*R2);\n\n    a2 = m*(C1*C3*R1*R3 - C2*C3*R3*R4 + C1*C3*R3*R3 + C2*C3*R3*R3)\n         + l*m*(C1*C3*R2*R3 + C2*C3*R2*R3)\n         - m*m*(C1*C3*R3*R3 + C2*C3*R3*R3)\n         + l*(C1*C2*R2*R4 + C1*C2*R1*R2 + C1*C3*R2*R4 + C2*C3*R2*R4)\n         + (C1*C2*R1*R4 + C1*C3*R1*R4 + C1*C2*R3*R4 + C1*C2*R1*R3 + C1*C3*R3*R4 + C2*C3*R3*R4);\n\n    a3 = l*m*(C1*C2*C3*R1*R2*R3 + C1*C2*C3*R2*R3*R4)\n         - m*m*(C1*C2*C3*R1*R3*R3 + C1*C2*C3*R3*R3*R4)\n         + m*(C1*C2*C3*R3*R3*R4 + C1*C2*C3*R1*R3*R3 - C1*C2*C3*R1*R3*R4)\n         + l*C1*C2*C3*R1*R2*R4\n         + C1*C2*C3*R1*R3*R4;\n\n    c = 2*float(ma.SR);\n\n    B0 = -b1*c - b2*pow(c,2) - b3*pow(c,3);\n    B1 = -b1*c + b2*pow(c,2) + 3*b3*pow(c,3);\n    B2 = b1*c + b2*pow(c,2) - 3*b3*pow(c,3);\n    B3 = b1*c - b2*pow(c,2) + b3*pow(c,3);\n    A0 = -a0 - a1*c - a2*pow(c,2) - a3*pow(c,3);\n    A1 = -3*a0 - a1*c + a2*pow(c,2) + 3*a3*pow(c,3);\n    A2 = -3*a0 + a1*c + a2*pow(c,2) - 3*a3*pow(c,3);\n    A3 = -a0 + a1*c - a2*pow(c,2) + a3*pow(c,3);\n};\n\ntse = ts.bassman;\nprocess = tonestack;"
 },
 {
  "id": "gx-tonestack-bogner",
  "name": "Tone Stack — Bogner Triple Giant",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Bogner Triple Giant preamp values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Bogner Triple Giant preamp. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Triple_Giant/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Triple_Giant/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Triple_Giant/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_bogner.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Triple Giant\"; // in tonestack ba.selector\ndeclare name \"Triple Giant\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.bogner;];"
 },
 {
  "id": "gx-tonestack-engl",
  "name": "Tone Stack — Engl",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Engl component values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from an Engl amplifier. Interactive three-band tone control with a tight, modern voicing.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Engl/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Engl/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Engl/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_engl.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Engl\"; // in tonestack ba.selector\ndeclare name \"Engl\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.engl;];"
 },
 {
  "id": "gx-tonestack-fender-default",
  "name": "Tone Stack — Fender",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with generic Fender blackface values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with typical Fender blackface R and C values. Interactive Bass, Middle and Treble with the scooped Fender character.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fender/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fender/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Fender/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_fender_default.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Fender\"; // in tonestack ba.selector\ndeclare name \"Fender\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.fender_default;];"
 },
 {
  "id": "gx-tonestack-bassman",
  "name": "Tone Stack — Fender Bassman",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with '59 Bassman 5F6-A values; the archetypal stack.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the 1959 Fender Bassman 5F6-A. The stack most tweed and Marshall circuits descend from; interactive Bass, Middle and Treble.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Bassman/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Bassman/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Bassman/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_bassman.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Bassman\"; // in tonestack ba.selector\ndeclare name \"Bassman\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.bassman;];"
 },
 {
  "id": "gx-tonestack-fender-blues",
  "name": "Tone Stack — Fender Blues Junior",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Fender Blues Junior values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Fender Blues Junior. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Junior/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Junior/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Junior/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_fender_blues.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Junior\"; // in tonestack ba.selector\ndeclare name \"Junior\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.fender_blues;];"
 },
 {
  "id": "gx-tonestack-fender-deville",
  "name": "Tone Stack — Fender Hot Rod DeVille",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Fender Hot Rod DeVille values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Fender Hot Rod DeVille. Interactive three-band tone control with a modern Fender voicing.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Deville/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Deville/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Deville/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_fender_deville.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Deville\"; // in tonestack ba.selector\ndeclare name \"Deville\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.fender_deville;];"
 },
 {
  "id": "gx-tonestack-princeton",
  "name": "Tone Stack — Fender Princeton",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with '64 Fender Princeton AA1164 values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the 1964 Fender Princeton AA1164. Interactive three-band tone control with a small-Fender voicing.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Princeton/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Princeton/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Princeton/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_princeton.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Princeton\"; // in tonestack ba.selector\ndeclare name \"Princeton\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.princeton;];"
 },
 {
  "id": "gx-tonestack-twin",
  "name": "Tone Stack — Fender Twin Reverb",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with '69 Fender Twin Reverb AA270 values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the 1969 Fender Twin Reverb AA270. Interactive three-band tone control with the blackface scoop.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Twin_Reverb/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Twin_Reverb/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Twin_Reverb/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_twin.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Twin Reverb\"; // in tonestack ba.selector\ndeclare name \"Twin Reverb\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.twin;];"
 },
 {
  "id": "gx-tonestack-gibsen",
  "name": "Tone Stack — Gibson GS-12 Reverb Rocket",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Gibson GS-12 Reverb Rocket values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Gibson GS-12 Reverb Rocket. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Gibsen/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Gibsen/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Gibsen/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_gibsen.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Gibsen\"; // in tonestack ba.selector\ndeclare name \"Gibsen\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.gibsen;];"
 },
 {
  "id": "gx-tonestack-groove",
  "name": "Tone Stack — Groove Tubes Trio Preamp",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Trio Preamp values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Trio Preamp. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Trio_Preamp/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Trio_Preamp/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Trio_Preamp/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_groove.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Trio Preamp\"; // in tonestack ba.selector\ndeclare name \"Trio Preamp\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.groove;];"
 },
 {
  "id": "gx-tonestack-crunch",
  "name": "Tone Stack — Hughes & Kettner",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Hughes & Kettner crunch-channel values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from a Hughes & Kettner crunch channel. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Hughes&Kettner/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Hughes&Kettner/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Hughes&Kettner/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_crunch.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Hughes&Kettner\"; // in tonestack ba.selector\ndeclare name \"Hughes&Kettner\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.crunch;];"
 },
 {
  "id": "gx-tonestack-ibanez",
  "name": "Tone Stack — Ibanez GX20",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Ibanez GX20 values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Ibanez GX20. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Ibanez/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Ibanez/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Ibanez/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_ibanez.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Ibanez\"; // in tonestack ba.selector\ndeclare name \"Ibanez\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.ibanez;];"
 },
 {
  "id": "gx-tonestack-jcm2000",
  "name": "Tone Stack — Marshall JCM2000",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Marshall JCM2000 lead-channel values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Marshall JCM2000 lead channel. Interactive three-band tone control with a modern Marshall voicing.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/JCM-2000/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/JCM-2000/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/JCM-2000/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_jcm2000.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"JCM-2000\"; // in tonestack ba.selector\ndeclare name \"JCM-2000\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.jcm2000;];"
 },
 {
  "id": "gx-tonestack-jcm800",
  "name": "Tone Stack — Marshall JCM800",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Marshall JCM800 2203 values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Marshall JCM800 Lead 100 (2203). Interactive three-band tone control with the classic Marshall mid push.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/JCM-800/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/JCM-800/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/JCM-800/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_jcm800.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"JCM-800\"; // in tonestack ba.selector\ndeclare name \"JCM-800\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.jcm800;];"
 },
 {
  "id": "gx-tonestack-jtm45",
  "name": "Tone Stack — Marshall JTM45",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Marshall JTM45 values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Marshall JTM45. Interactive three-band tone control, close to the Bassman it was copied from.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/JTM-45/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/JTM-45/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/JTM-45/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_jtm45.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"JTM-45\"; // in tonestack ba.selector\ndeclare name \"JTM-45\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.jtm45;];"
 },
 {
  "id": "gx-tonestack-m2199",
  "name": "Tone Stack — Marshall M2199",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Marshall M2199 solid-state values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Marshall M2199 30 W solid-state amp. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/M2199/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/M2199/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/M2199/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_m2199.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"M2199\"; // in tonestack ba.selector\ndeclare name \"M2199\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.m2199;];"
 },
 {
  "id": "gx-tonestack-mlead",
  "name": "Tone Stack — Marshall Major Lead",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with '67 Marshall Major Lead 200 values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the 1967 Marshall Major Lead 200. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/M-Lead/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/M-Lead/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/M-Lead/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_mlead.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"M-Lead\"; // in tonestack ba.selector\ndeclare name \"M-Lead\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.mlead;];"
 },
 {
  "id": "gx-tonestack-mesa",
  "name": "Tone Stack — Mesa Boogie Mark",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Mesa Boogie Mark values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Mesa Boogie Mark series. Interactive three-band tone control with the Boogie's mid focus.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Mesa_Boogie/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Mesa_Boogie/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Mesa_Boogie/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_mesa.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Mesa Boogie\"; // in tonestack ba.selector\ndeclare name \"Mesa Boogie\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.mesa;];"
 },
 {
  "id": "gx-tonestack-peavey",
  "name": "Tone Stack — Peavey C20",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Peavey C20 values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Peavey C20. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Peavey/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Peavey/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Peavey/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_peavey.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Peavey\"; // in tonestack ba.selector\ndeclare name \"Peavey\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.peavey;];"
 },
 {
  "id": "gx-tonestack-roland",
  "name": "Tone Stack — Roland Cube 60",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Roland Cube 60 values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Roland Cube 60. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Roland/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Roland/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Roland/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_roland.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"Roland\"; // in tonestack ba.selector\ndeclare name \"Roland\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.roland;];"
 },
 {
  "id": "gx-tonestack-soldano",
  "name": "Tone Stack — Soldano SLO-100",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Soldano SLO-100 values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Soldano SLO-100. Interactive three-band tone control with a tight hi-gain voicing.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/SOL_100/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/SOL_100/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/SOL_100/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_soldano.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"SOL 100\"; // in tonestack ba.selector\ndeclare name \"SOL 100\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.soldano;];"
 },
 {
  "id": "gx-tonestack-sovtek",
  "name": "Tone Stack — Sovtek MIG 100H",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Sovtek MIG 100H values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Sovtek MIG 100H. Interactive three-band tone control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/MIG_100_H/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/MIG_100_H/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/MIG_100_H/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_sovtek.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"MIG 100 H\"; // in tonestack ba.selector\ndeclare name \"MIG 100 H\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.sovtek;];"
 },
 {
  "id": "gx-tonestack-ac15",
  "name": "Tone Stack — Vox AC15",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with the Vox AC15's component values.",
  "description": "Symbolic third-order transfer function of the classic passive amp tone stack (after Yeh / CAPS), with R and C values from the Vox AC15. Bass, Middle and Treble interact the way they do on the real amp.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/AC-15/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/AC-15/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/AC-15/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_ac15.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"AC-15\"; // in tonestack ba.selector\ndeclare name \"AC-15\"; \ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.ac15;];"
 },
 {
  "id": "gx-tonestack-ac30",
  "name": "Tone Stack — Vox AC30",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Passive Bass/Middle/Treble tone stack with Vox AC30 component values.",
  "description": "Symbolic third-order transfer function of the passive amp tone stack with R and C values from the Vox AC30 ('59/'86). Interactive Bass, Middle and Treble with the AC30's chimey top end.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".amp.tonestack.Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/AC-30/.amp.tonestack.Bass"
   },
   {
    "label": ".amp.tonestack.Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/AC-30/.amp.tonestack.Middle"
   },
   {
    "label": ".amp.tonestack.Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/AC-30/.amp.tonestack.Treble"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_ac30.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"AC-30\"; // in tonestack ba.selector\ndeclare name \"AC-30\";\n\ntstack = component(\"gx-tonestack.dsp\");\nprocess = tstack[tse=tstack.ts.ac30;];"
 },
 {
  "id": "gx-highbooster",
  "name": "Treble Boost",
  "category": "guitar",
  "family": "eq",
  "familyName": "EQ & Tone",
  "icon": "tabler:adjustments",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "First-order high-pass boost above 1.5 kHz, 0–20 dB.",
  "description": "Adds a first-order high-passed copy of the signal above 1.5 kHz scaled by Level (0–20 dB). A clean, simple treble lift.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Level",
    "min": 0,
    "max": 20,
    "default": 0.5,
    "step": 0.5,
    "unit": "",
    "path": "/Treble_boost/Level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/highbooster.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name   \"Treble boost\";\ndeclare category \"Tone Control\";\n\nimport(\"stdfaust.lib\");\n\nlevel = vslider(\"Level\", 0.5, 0.0, 20, 0.5) ;\nhfboost(level,fx,x) = x + (ba.db2linear(level)-1)*fi.highpass(1,fx,x);\n\nprocess = hfboost(level, 1500);"
 },
 {
  "id": "gx-autowah",
  "name": "Auto Wah (Cry Baby)",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Envelope-following auto-wah built on the Cry Baby biquad fit; touch-controlled quack.",
  "description": "Uses the Cry Baby wah biquad approximation (Julius Smith's fit of the Dunlop circuit) swept by an envelope follower instead of a pedal, with Wah range, Level and wet/dry. Picking dynamics open and close the filter.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "crybaby.level",
    "min": 0,
    "max": 1,
    "default": 0.1,
    "step": 0.01,
    "unit": "",
    "path": "/auto/crybaby.level"
   },
   {
    "label": "crybaby.wah",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/auto/crybaby.wah"
   },
   {
    "label": "crybaby.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/auto/crybaby.wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/autowah.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"auto\"; // ba.selector ve.crybaby / ve.autowah\ndeclare name \"auto\";\n\n//-----------------------------------------------\n//     Auto-Wah\n//-----------------------------------------------\n\nimport(\"stdfaust.lib\"); //for ve.crybaby definition\nimport(\"guitarix.lib\");\n\nl = crybaby_ctrl.level;\na = crybaby_ctrl.wah;\nw = crybaby_ctrl.wet_dry;\n/*\na = 20 * vslider(\".ve.crybaby.wah[alias]\", 0, 0, 1, 0.01);\nw = vslider(\".ve.crybaby.wet_dry[alias]\", 100, 0, 100, 0.1):/(100);\nl = vslider(\".ve.crybaby.level[alias]\", 0, -1, 1, 0.1);\n*/\n\nd = 1-w;\nSum(n,x) = +(x - (x @ n)) ~_ ;\n\nAverage(n,x) = x * (1<<22) : int : abs : Sum(n) : float : /(1<<22)\n                 : /(n);\n\nMap(x) = x * a : max(0) : min(1) ;\n \n\nprocess(x) = x : _<:*(d),(*(w):*(l) :ve.crybaby(x : Average(1000) : Map)):>_ ;"
 },
 {
  "id": "gx-colwah",
  "name": "Colorsound Wah",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Colorsound inductorless wah with Wah position, frequency, mode and wet/dry.",
  "description": "DK circuit simulation from the Colorsound Wah schematic as a pot-dependent filter with a mode switch and wet/dry. A vocal, mid-forward British wah.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".wah.Wah",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/ColorSound_Wah/.wah.Wah"
   },
   {
    "label": ".wah.freq",
    "min": 24,
    "max": 360,
    "default": 24,
    "step": 1,
    "unit": "",
    "path": "/ColorSound_Wah/.wah.freq"
   },
   {
    "label": ".wah.mode",
    "min": 0,
    "max": 2,
    "default": 0,
    "step": 1,
    "unit": "",
    "path": "/ColorSound_Wah/.wah.mode"
   },
   {
    "label": ".wah.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/ColorSound_Wah/.wah.wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/colwah.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"colwah\";\ndeclare name \"ColorSound Wah\";\ndeclare category \"Guitar Effects\";\ndeclare shortname \"ColorSound Wah\";\ndeclare description \"ColorSound Wah\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nprocess(x) = x : _<:*(dry),(*(wet) : pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0))):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    wet = wah_ctrl.wet_dry;\n    dry = 1 - wet;\n    pre = fi.dcblockerat(156.537925581);\n\n    Wah1 = (x : an.amp_follower_ud(0.01,0.1) : min(1) : max(0.02) ) : si.smooth(s);\n\n    Wah2 = wah_ctrl.wah : max(0.01) : Inverted(1) : LogPot(5) : si.smooth(s);\n \n    sl = wah_ctrl.mode;\n\n    Wah3 = (os.oscs(freq) + 1) / 2 : min(0.98) : max(0.02) : Inverted(1) with {\n        freq = wah_ctrl.freq;\n    }; \n\n    Wah = select3(sl, Wah2, Wah1, Wah3);\n    \n    b0 = Wah*(Wah*pow(fs,2)*(fs*(8.31249052050881e-22*fs + 1.912505767204e-17) + 2.9122542229415e-14) + fs*(fs*(fs*(-8.22579827731233e-22*fs - 1.89445663105706e-17) - 2.92311751105741e-14) - 6.25519484069141e-13)) + fs*(fs*(fs*(-2.66926675132622e-21*fs - 8.43534115306834e-17) - 1.31405791553819e-13) - 6.81633101368958e-13);\n\n    b1 = Wah*(Wah*pow(fs,3)*(-3.32499620820352e-21*fs - 3.825011534408e-17) + fs*(pow(fs,2)*(3.29031931092493e-21*fs + 3.78891326211413e-17) - 1.25103896813828e-12)) + fs*(pow(fs,2)*(1.06770670053049e-20*fs + 1.68706823061367e-16) - 1.36326620273792e-12);\n\n    b2 = Wah*(Wah*pow(fs,2)*(4.98749431230529e-21*pow(fs,2) - 5.824508445883e-14) + pow(fs,2)*(-4.9354789663874e-21*pow(fs,2) + 5.84623502211483e-14)) + pow(fs,2)*(-1.60156005079573e-20*pow(fs,2) + 2.62811583107638e-13);\n\n    b3 = Wah*(Wah*pow(fs,3)*(-3.32499620820352e-21*fs + 3.825011534408e-17) + fs*(pow(fs,2)*(3.29031931092493e-21*fs - 3.78891326211413e-17) + 1.25103896813828e-12)) + fs*(pow(fs,2)*(1.06770670053049e-20*fs - 1.68706823061367e-16) + 1.36326620273792e-12);\n\n    b4 = Wah*(Wah*pow(fs,2)*(fs*(8.31249052050881e-22*fs - 1.912505767204e-17) + 2.9122542229415e-14) + fs*(fs*(fs*(-8.22579827731233e-22*fs + 1.89445663105706e-17) - 2.92311751105741e-14) + 6.25519484069141e-13)) + fs*(fs*(fs*(-2.66926675132622e-21*fs + 8.43534115306834e-17) - 1.31405791553819e-13) + 6.81633101368958e-13);\n\n    a0 = Wah*(Wah*fs*(fs*(fs*(-6.9713352578405e-20*fs - 5.83030654431973e-18) - 2.29684974478901e-14) - 2.35672055328543e-13) + fs*(fs*(fs*(3.97687174092932e-19*fs + 2.70551577331849e-17) + 1.90255378851155e-14) + 7.09396691797023e-13)) + fs*(fs*(fs*(6.54938497087849e-21*fs + 5.15430968663743e-18) + 1.2663530557943e-13) + 3.94769224069978e-12) + 1.63948058636323e-11;\n\n    a1 = Wah*(Wah*fs*(pow(fs,2)*(2.7885341031362e-19*fs + 1.16606130886395e-17) - 4.71344110657085e-13) + fs*(pow(fs,2)*(-1.59074869637173e-18*fs - 5.41103154663699e-17) + 1.41879338359405e-12)) + fs*(pow(fs,2)*(-2.6197539883514e-20*fs - 1.03086193732749e-17) + 7.89538448139956e-12) + 6.55792234545291e-11;\n\n    a2 = Wah*(Wah*pow(fs,2)*(-4.1828011547043e-19*pow(fs,2) + 4.59369948957802e-14) + pow(fs,2)*(2.38612304455759e-18*pow(fs,2) - 3.8051075770231e-14)) + pow(fs,2)*(3.9296309825271e-20*pow(fs,2) - 2.5327061115886e-13) + 9.83688351817936e-11;\n\n    a3 = Wah*(Wah*fs*(pow(fs,2)*(2.7885341031362e-19*fs - 1.16606130886395e-17) + 4.71344110657085e-13) + fs*(pow(fs,2)*(-1.59074869637173e-18*fs + 5.41103154663699e-17) - 1.41879338359405e-12)) + fs*(pow(fs,2)*(-2.6197539883514e-20*fs + 1.03086193732749e-17) - 7.89538448139956e-12) + 6.55792234545291e-11;\n\n    a4 = Wah*(Wah*fs*(fs*(fs*(-6.9713352578405e-20*fs + 5.83030654431973e-18) - 2.29684974478901e-14) + 2.35672055328543e-13) + fs*(fs*(fs*(3.97687174092932e-19*fs - 2.70551577331849e-17) + 1.90255378851155e-14) - 7.09396691797023e-13)) + fs*(fs*(fs*(6.54938497087849e-21*fs - 5.15430968663743e-18) + 1.2663530557943e-13) - 3.94769224069978e-12) + 1.63948058636323e-11;\n};"
 },
 {
  "id": "gx-crybaby",
  "name": "Cry Baby Wah (manual)",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Manual Cry Baby wah from the JOS biquad fit, with Wah, Level and wet/dry.",
  "description": "Julius Smith's biquad approximation of the Dunlop Cry Baby wah, swept manually by the Wah control, with Level and wet/dry. A light, reliable wah for expression-pedal control.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "crybaby.level",
    "min": 0,
    "max": 1,
    "default": 0.1,
    "step": 0.01,
    "unit": "",
    "path": "/manual/crybaby.level"
   },
   {
    "label": "crybaby.wah",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/manual/crybaby.wah"
   },
   {
    "label": "crybaby.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/manual/crybaby.wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/crybaby.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"manual\";\ndeclare name \"manual\"; // ba.selector ve.crybaby / ve.autowah\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\n_crybaby(wah) = *(gs(s)) : fi.tf2(1,-1*0.996,0,a1s(s)*0.996,a2s(s)*0.996)\nwith {\n  s = 0.999; // smoothing parameter (one-fi.pole fi.pole location)\n  Q  = pow(2.0,(2.0*(1.0-wah)+1.0)); // Resonance \"quality factor\"\n  fr = 450.0*pow(2.0,2.3*wah);       // Resonance tuning\n  g  = 0.1*pow(4.0,wah);             // gain (optional)\n\n  // Biquad fit using z = exp(s T) ~ 1 + sT for low frequencies:\n  frn = fr/ma.SR; // Normalized fi.pole frequency (cycles per sample)\n  R = 1 - ma.PI*frn/Q; // fi.pole radius\n  theta = 2*ma.PI*frn; // fi.pole angle\n  a1 = 0-2.0*R*cos(theta); // biquad coeff\n  a2 = R*R;                // biquad coeff\n\n  // dezippering of slider-driven signals:\n  a1s(s) = a1 : si.smooth(s);\n  a2s(s) = a2 : si.smooth(s);\n  gs(s) =  g  : si.smooth(s);\n};\n\nlevel   = crybaby_ctrl.level;\nwah     = crybaby_ctrl.wah;\nwet_dry = crybaby_ctrl.wet_dry;\n\ndry = 1 - wet_dry;\n\nprocess =  _<:*(dry),(*(wet_dry): *(level) : _crybaby(wah)):>_;"
 },
 {
  "id": "lib-autowah",
  "name": "CryBaby Auto-Wah",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "CryBaby wah driven by an amplitude follower - envelope filter / touch-wah",
  "description": "CryBaby wah driven by an amplitude follower - envelope filter / touch-wah",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Sensitivity",
    "min": 0,
    "max": 40,
    "default": 12,
    "step": 0.1,
    "unit": "dB",
    "path": "/CryBaby_Auto-Wah/Sensitivity"
   },
   {
    "label": "Effect",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/CryBaby_Auto-Wah/Effect"
   },
   {
    "label": "Release",
    "min": 10,
    "max": 1000,
    "default": 100,
    "step": 1,
    "unit": "ms",
    "path": "/CryBaby_Auto-Wah/Release"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/CryBaby_Auto-Wah/Level"
   }
  ],
  "faustCode": "declare name \"CryBaby Auto-Wah\";\ndeclare description \"CryBaby wah driven by an amplitude follower - envelope filter / touch-wah\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.autowah\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nsens  = hslider(\"[0] Sensitivity[unit:dB]\", 12, 0, 40, 0.1) : ba.db2linear : si.smoo;\nmixamt= hslider(\"[1] Effect\", 1, 0, 1, 0.01) : si.smoo;\nrel   = hslider(\"[2] Release[unit:ms]\", 100, 10, 1000, 1);\nlevel = hslider(\"[3] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\n\nenv(x) = an.amp_follower_ud(0.005, rel/1000, x*sens) : min(1);\nprocess(x) = (mixamt * ve.crybaby(env(x), x) + (1-mixamt) * x) * level;"
 },
 {
  "id": "lib-crybaby",
  "name": "CryBaby Wah",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "JOS digitization of the Dunlop CryBaby wah pedal (manual pedal position)",
  "description": "JOS digitization of the Dunlop CryBaby wah pedal (manual pedal position)",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Pedal",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/CryBaby_Wah/Pedal"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/CryBaby_Wah/Level"
   }
  ],
  "faustCode": "declare name \"CryBaby Wah\";\ndeclare description \"JOS digitization of the Dunlop CryBaby wah pedal (manual pedal position)\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.crybaby\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nwah   = hslider(\"[0] Pedal\", 0.5, 0, 1, 0.01) : si.smoo;\nlevel = hslider(\"[1] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\nprocess = ve.crybaby(wah) : *(level);"
 },
 {
  "id": "gx-dallaswah",
  "name": "Dallas Arbiter Wah",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Dallas Arbiter wah pedal with Wah position, frequency, mode and wet/dry.",
  "description": "DK circuit simulation from the Dallas Wah schematic as a pot-dependent filter with a mode switch and wet/dry. A 1960s-style wah with a throaty sweep.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".wah.Wah",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Dallas_Wah/.wah.Wah"
   },
   {
    "label": ".wah.freq",
    "min": 24,
    "max": 360,
    "default": 24,
    "step": 1,
    "unit": "",
    "path": "/Dallas_Wah/.wah.freq"
   },
   {
    "label": ".wah.mode",
    "min": 0,
    "max": 2,
    "default": 0,
    "step": 1,
    "unit": "",
    "path": "/Dallas_Wah/.wah.mode"
   },
   {
    "label": ".wah.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Dallas_Wah/.wah.wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/dallaswah.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"dallaswah\";\ndeclare name \"Dallas Wah\";\ndeclare category \"Guitar Effects\";\ndeclare shortname \"Dallas  Wah\";\ndeclare description \"Dallas Arbiter Wah\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nprocess(x) = x  : _<:*(dry),(*(wet) : pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0))):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = fi.dcblockerat(583.714419367);\n    \n    wet = wah_ctrl.wet_dry;\n    dry = 1 - wet;\n\n    Wah1 = (x : an.amp_follower_ud(0.01,0.1) : min(1) : max(0.02) ) : si.smooth(s);\n\n    Wah2 = wah_ctrl.wah : max(0.01) : Inverted(1) : LogPot(5) : si.smooth(s);\n \n    sl = wah_ctrl.mode;\n\n    Wah3 = (os.oscs(freq) + 1) / 2 : min(0.98) : max(0.02) : Inverted(1) with {\n        freq = wah_ctrl.freq;\n    }; \n\n    Wah = select3(sl, Wah2, Wah1, Wah3);\n    \n    b0 = Wah*(Wah*fs*(fs*(fs*(2.83510090714092e-21*fs + 1.04896968320146e-16) + 1.59534818623044e-13) - 1.53357283072645e-26) + fs*(fs*(fs*(-2.32347860461171e-21*fs - 8.64108311643329e-17) - 1.33575525905195e-13) - 3.41675778537176e-12)) + fs*(fs*(fs*(-7.07917432005204e-21*fs - 5.52389028989215e-16) - 8.63117119019868e-13) - 5.62135356398181e-12);\n\n    b1 = Wah*(Wah*fs*(pow(fs,2)*(-1.13404036285637e-20*fs - 2.09793936640293e-16) - 3.06714566145289e-26) + fs*(pow(fs,2)*(9.29391441844685e-21*fs + 1.72821662328666e-16) - 6.83351557074351e-12)) + fs*(pow(fs,2)*(2.83166972802082e-20*fs + 1.10477805797843e-15) - 1.12427071279636e-11);\n\n    b2 = Wah*(Wah*pow(fs,2)*(1.70106054428455e-20*pow(fs,2) - 3.19069637246088e-13) + pow(fs,2)*(-1.39408716276703e-20*pow(fs,2) + 2.6715105181039e-13)) + pow(fs,2)*(-4.24750459203123e-20*pow(fs,2) + 1.72623423803974e-12);\n\n    b3 = Wah*(Wah*fs*(pow(fs,2)*(-1.13404036285637e-20*fs + 2.09793936640293e-16) + 3.06714566145289e-26) + fs*(pow(fs,2)*(9.29391441844685e-21*fs - 1.72821662328666e-16) + 6.83351557074351e-12)) + fs*(pow(fs,2)*(2.83166972802082e-20*fs - 1.10477805797843e-15) + 1.12427071279636e-11);\n\n    b4 = Wah*(Wah*fs*(fs*(fs*(2.83510090714092e-21*fs - 1.04896968320146e-16) + 1.59534818623044e-13) + 1.53357283072645e-26) + fs*(fs*(fs*(-2.32347860461171e-21*fs + 8.64108311643329e-17) - 1.33575525905195e-13) + 3.41675778537176e-12)) + fs*(fs*(fs*(-7.07917432005204e-21*fs + 5.52389028989215e-16) - 8.63117119019868e-13) + 5.62135356398181e-12);\n\n    a0 = Wah*(Wah*fs*(fs*(fs*(-4.47972527031659e-20*fs - 1.0922674147551e-17) - 2.09610231217262e-13) + 2.01493666656321e-26) + fs*(fs*(fs*(2.74906060407121e-19*fs + 2.45407810123387e-17) + 1.4198849343527e-13) + 5.60455163682517e-12) - 5.38753119401928e-25) + fs*(fs*(fs*(6.05097478328861e-20*fs + 3.86741226880994e-17) + 1.39111781189056e-12) + 3.46679367777423e-11) + 1.49854321840248e-10;\n\n    a1 = Wah*(Wah*fs*(pow(fs,2)*(1.79189010812664e-19*fs + 2.18453482951021e-17) + 4.02987333312642e-26) + fs*(pow(fs,2)*(-1.09962424162848e-18*fs - 4.90815620246775e-17) + 1.12091032736503e-11) - 2.15501247760771e-24) + fs*(pow(fs,2)*(-2.42038991331544e-19*fs - 7.73482453761989e-17) + 6.93358735554846e-11) + 5.99417287360993e-10;\n\n    a2 = Wah*(Wah*pow(fs,2)*(-2.68783516218996e-19*pow(fs,2) + 4.19220462434524e-13) + pow(fs,2)*(1.64943636244273e-18*pow(fs,2) - 2.8397698687054e-13) - 3.23251871641157e-24) + pow(fs,2)*(3.63058486997317e-19*pow(fs,2) - 2.78223562378113e-12) + 8.99125931041489e-10;\n\n    a3 = Wah*(Wah*fs*(pow(fs,2)*(1.79189010812664e-19*fs - 2.18453482951021e-17) - 4.02987333312642e-26) + fs*(pow(fs,2)*(-1.09962424162848e-18*fs + 4.90815620246775e-17) - 1.12091032736503e-11) - 2.15501247760771e-24) + fs*(pow(fs,2)*(-2.42038991331544e-19*fs + 7.73482453761989e-17) - 6.93358735554846e-11) + 5.99417287360993e-10;\n\n    a4 = Wah*(Wah*fs*(fs*(fs*(-4.47972527031659e-20*fs + 1.0922674147551e-17) - 2.09610231217262e-13) - 2.01493666656321e-26) + fs*(fs*(fs*(2.74906060407121e-19*fs - 2.45407810123387e-17) + 1.4198849343527e-13) - 5.60455163682517e-12) - 5.38753119401928e-25) + fs*(fs*(fs*(6.05097478328861e-20*fs - 3.86741226880994e-17) + 1.39111781189056e-12) - 3.46679367777423e-11) + 1.49854321840248e-10;\n};"
 },
 {
  "id": "lib-diode-ladder",
  "name": "Diode Ladder",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "EMS/TB-303 style diode ladder lowpass (Zavalishin) with soft-clipped input",
  "description": "EMS/TB-303 style diode ladder lowpass (Zavalishin) with soft-clipped input",
  "author": "Eric Tarr",
  "flags": "",
  "params": [
   {
    "label": "Cutoff",
    "min": 40,
    "max": 12000,
    "default": 1500,
    "step": 1,
    "unit": "Hz",
    "path": "/Diode_Ladder/Cutoff"
   },
   {
    "label": "Resonance",
    "min": 0.707,
    "max": 17,
    "default": 3,
    "step": 0.01,
    "unit": "",
    "path": "/Diode_Ladder/Resonance"
   },
   {
    "label": "Drive",
    "min": 0,
    "max": 30,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/Diode_Ladder/Drive"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Diode_Ladder/Level"
   }
  ],
  "faustCode": "declare name \"Diode Ladder\";\ndeclare description \"EMS/TB-303 style diode ladder lowpass (Zavalishin) with soft-clipped input\";\ndeclare author \"Eric Tarr\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.diodeLadder\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"[0] Cutoff[unit:Hz][scale:log]\", 1500, 40, 12000, 1) : si.smoo;\nq     = hslider(\"[1] Resonance\", 3, 0.707, 17, 0.01) : si.smoo;\ndrive = hslider(\"[2] Drive[unit:dB]\", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;\nlevel = hslider(\"[3] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\n\nnormFreq = log10(max(20, freq)/20) / 3 : min(0.99);\nprocess = *(drive) : ve.diodeLadder(normFreq, max(0.707, q)) : *(level);"
 },
 {
  "id": "gx-gcb-95",
  "name": "Dunlop GCB-95 Cry Baby",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Full linear model of the Dunlop GCB-95 Cry Baby circuit with a hot-potz sweep.",
  "description": "Linear circuit simulation of the GCB-95 Cry Baby (inductor plus transistor stages) as a 4th-order filter whose coefficients follow the pedal pot, generated from the schematic. Hotpotz sets the sweep position and Volume the output.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Volume",
    "min": -20,
    "max": 4,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/GCB_95/Volume"
   },
   {
    "label": "hotpotz",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/GCB_95/hotpotz"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gcb_95.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated by scripts/build_GCB_95.py\n// DO NOT MODIFY!\ndeclare id \"GCB_95\";\ndeclare name \"GCB 95\";\ndeclare category \"Guitar Effects\";\ndeclare description \"Linear filter simulating the GCB 95 ve.crybaby circuit\";\n\nimport(\"stdfaust.lib\");\n\nprocess = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0)) : *(Volume) with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = fi.dcblockerat(228.105325695);\n    \n        Volume = vslider(\"Volume\", 0, -20, +4, 0.1) : ba.db2linear : si.smooth(s);\n\n        hotpotz = vslider(\"hotpotz[name:Wah]\", 0.5, 0, 1, 0.01) : Inverted(1) : LogPot(5) : si.smooth(s);\n    \n    b0 = fs*(fs*(fs*(-7.41350388334374e-21*fs - 2.47418541205506e-16) - 3.69672787496925e-13) - 1.8397056665289e-12) + hotpotz*(pow(fs,2)*hotpotz*(fs*(1.96834437163512e-21*fs + 5.48587515516469e-17) + 8.09470493272714e-14) + fs*(fs*(fs*(-1.96653248770188e-21*fs - 5.48942867863191e-17) - 8.21432353321142e-14) - 1.78155704878595e-12));\n\n    b1 = fs*(pow(fs,2)*(2.9654015533375e-20*fs + 4.94837082411013e-16) - 3.67941133305779e-12) + hotpotz*(pow(fs,3)*hotpotz*(-7.87337748654046e-21*fs - 1.09717503103294e-16) + fs*(pow(fs,2)*(7.86612995080753e-21*fs + 1.09788573572638e-16) - 3.56311409757189e-12));\n\n    b2 = pow(fs,2)*(-4.44810233000624e-20*pow(fs,2) + 7.39345574993849e-13) + hotpotz*(pow(fs,2)*hotpotz*(1.18100662298107e-20*pow(fs,2) - 1.61894098654543e-13) + pow(fs,2)*(-1.17991949262113e-20*pow(fs,2) + 1.64286470664228e-13));\n\n    b3 = fs*(pow(fs,2)*(2.9654015533375e-20*fs - 4.94837082411013e-16) + 3.67941133305779e-12) + hotpotz*(pow(fs,3)*hotpotz*(-7.87337748654046e-21*fs + 1.09717503103294e-16) + fs*(pow(fs,2)*(7.86612995080753e-21*fs - 1.09788573572638e-16) + 3.56311409757189e-12));\n\n    b4 = fs*(fs*(fs*(-7.41350388334374e-21*fs + 2.47418541205506e-16) - 3.69672787496925e-13) + 1.8397056665289e-12) + hotpotz*(pow(fs,2)*hotpotz*(fs*(1.96834437163512e-21*fs - 5.48587515516469e-17) + 8.09470493272714e-14) + fs*(fs*(fs*(-1.96653248770188e-21*fs + 5.48942867863191e-17) - 8.21432353321142e-14) + 1.78155704878595e-12));\n\n    a0 = fs*(fs*(fs*(1.08819023657393e-20*fs + 2.80985481683452e-17) + 5.44712113689982e-13) + 1.29191360120173e-11) + hotpotz*(pow(fs,2)*hotpotz*(fs*(-6.9672955745145e-20*fs - 9.30061422376548e-18) - 9.53707992555105e-14) + fs*(fs*(fs*(3.8766476861454e-19*fs + 2.92076464853813e-17) + 7.68323461702748e-14) + 2.16751816489796e-12)) + 4.92617764749537e-11;\n\n    a1 = fs*(pow(fs,2)*(-4.3527609462957e-20*fs - 5.61970963366905e-17) + 2.58382720240347e-11) + hotpotz*(pow(fs,3)*hotpotz*(2.7869182298058e-19*fs + 1.8601228447531e-17) + fs*(pow(fs,2)*(-1.55065907445816e-18*fs - 5.84152929707626e-17) + 4.33503632979593e-12)) + 1.97047105899815e-10;\n\n    a2 = pow(fs,2)*(6.52914141944355e-20*pow(fs,2) - 1.08942422737996e-12) + hotpotz*(pow(fs,2)*hotpotz*(-4.1803773447087e-19*pow(fs,2) + 1.90741598511021e-13) + pow(fs,2)*(2.32598861168724e-18*pow(fs,2) - 1.5366469234055e-13)) + 2.95570658849723e-10;\n\n    a3 = fs*(pow(fs,2)*(-4.3527609462957e-20*fs + 5.61970963366905e-17) - 2.58382720240347e-11) + hotpotz*(pow(fs,3)*hotpotz*(2.7869182298058e-19*fs - 1.8601228447531e-17) + fs*(pow(fs,2)*(-1.55065907445816e-18*fs + 5.84152929707626e-17) - 4.33503632979593e-12)) + 1.97047105899815e-10;\n\n    a4 = fs*(fs*(fs*(1.08819023657393e-20*fs - 2.80985481683452e-17) + 5.44712113689982e-13) - 1.29191360120173e-11) + hotpotz*(pow(fs,2)*hotpotz*(fs*(-6.9672955745145e-20*fs + 9.30061422376548e-18) - 9.53707992555105e-14) + fs*(fs*(fs*(3.8766476861454e-19*fs - 2.92076464853813e-17) + 7.68323461702748e-14) - 2.16751816489796e-12)) + 4.92617764749537e-11;\n};"
 },
 {
  "id": "gx-dunwah",
  "name": "Dunlop Wah (fitted)",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Dunlop-style wah as two biquads fitted to the circuit response; one Wah control.",
  "description": "Two cascaded biquads whose coefficients were fitted to the Dunlop wah circuit response by guitarix's dunwah scripts, swept by a single Wah control. A lightweight wah model.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "wah",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/DunWah/wah"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/dunwah.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"dunwah\";\ndeclare name \"DunWah\";\n\nimport(\"stdfaust.lib\");\n\ndunwah = *(gs) : tf2(1,-1,0,a1s,a2s)\nwith {\n    // calculated by dunwah1.py\n    theta2pi = (1892.75 - 1 / (((0.000927476*wah+-0.00197293)*wah+0.002474)*wah+-0.00152132))/ma.SR;\n    Q = ((-12.1248*wah+21.9241)*wah+-33.2116)*wah+25.8564;\n    g = 0.025 - 1 / ((((-127.479*wah+387.412)*wah+-466.009)*wah+302.062)*wah+-96.9872);\n\n    R = 1 - theta2pi/(2*Q);\n    a1 = 0-2.0*R*cos(theta2pi); // biquad coeff\n    a2 = R*R;                   // biquad coeff\n\n    // dezippering of slider-driven signals:\n    s = 0.999; // smoothing parameter (one-pole pole location)\n    a1s = a1 : si.smooth(s);\n    a2s = a2 : si.smooth(s);\n    gs =  g  : si.smooth(s);\n\n    tf2 = component(\"filter.lib\").tf2;\n    //wah = vslider(\"wah\", 0, 0, 1, 0.01) : *(9) : +(1) : log10;\n    wah = vslider(\"wah\", 0, 0, 1, 0.01);\n};\n\ndunwah2 = *(gs) : iir((b0, b1, b2, b3), (A1, A2, A3))\nwith {\n    // calculated by dunwah2.py\n    theta2pi = (1973.48 - 1000 / ((((((12.499*wah+-40.3658)*wah+49.9836)*wah+-28.3434)*wah+5.76598)*wah+1.9841)*wah+-1.6086)) / ma.SR;\n    Q = ((((-52.3051*wah+115.375)*wah+-99.7712)*wah+42.2734)*wah+-24.555)*wah+21.9737;\n    g = -0.933975 - 1 / (((((2.85511*wah+-5.20364)*wah+3.64419)*wah+-0.86331)*wah+0.270546)*wah+-0.814203);\n    gc = (-8.38823e-12*ma.SR+1.73888e-06)*ma.SR+-0.193457;\n    p1 = exp(-1000/(0.808471*ma.SR));\n    z1 = 1.00038;\n    z2 = (-8.52216e-12*ma.SR+1.77528e-06)*ma.SR+0.879905;\n    z3 = (-6.43963e-11*ma.SR+1.54419e-05)*ma.SR+-0.386688;\n\n    b0 = 1.0;\n    b1 = -z1-z2-z3;\n    b2 = z1*z2+z1*z3+z2*z3;\n    b3 = -z1*z2*z3;\n\n    // dezippering of slider-driven signals:\n    s = 0.993; // smoothing parameter (one-pole pole location)\n\n    R = 1 - theta2pi/(2*Q);\n    a1 = -2.0*R*cos(theta2pi) : si.smooth(s); // biquad coeff\n    a2 = R*R : si.smooth(s);                  // biquad coeff\n    gs =  g * gc : si.smooth(s);\n\n    A1 = a1 - p1;\n    A2 = a2 - a1 * p1;\n    A3 = -a2 * p1;\n\n    iir = component(\"filter.lib\").iir;\n\n    //wah = vslider(\"wah\", 0, 0, 1, 0.01) : *(9) : +(1) : log10;\n    wah = vslider(\"wah\", 0, 0, 1, 0.01);\n};\n\nprocess = dunwah2;"
 },
 {
  "id": "gx-foxwah",
  "name": "Foxx Wah",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Foxx wah pedal with Wah position, frequency, mode and wet/dry.",
  "description": "DK circuit simulation from the Foxx Wah schematic as a pot-dependent filter with a mode switch and wet/dry. A wide, fuzzy-era wah sweep.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".wah.Wah",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Foxx_Wah/.wah.Wah"
   },
   {
    "label": ".wah.freq",
    "min": 24,
    "max": 360,
    "default": 24,
    "step": 1,
    "unit": "",
    "path": "/Foxx_Wah/.wah.freq"
   },
   {
    "label": ".wah.mode",
    "min": 0,
    "max": 2,
    "default": 0,
    "step": 1,
    "unit": "",
    "path": "/Foxx_Wah/.wah.mode"
   },
   {
    "label": ".wah.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Foxx_Wah/.wah.wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/foxwah.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"foxwah\";\ndeclare name \"Foxx Wah\";\ndeclare category \"Guitar Effects\";\ndeclare shortname \"Foxx Wah\";\ndeclare description \"Foxx Wah\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nprocess(x) = x : _<:*(dry),(*(wet) : pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0))):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    wet = wah_ctrl.wet_dry;\n    dry = 1 - wet;\n    pre = fi.dcblockerat(228.232162503);\n\n    Wah1 = (x : an.amp_follower_ud(0.01,0.1) : min(0.98) : max(0.02) : Inverted(1)): si.smooth(s);\n\n    Wah2 = wah_ctrl.wah : max(0.01) : LogPot(1) : si.smooth(s);\n \n    sl = wah_ctrl.mode;\n\n    Wah3 = (os.oscs(freq) + 1) / 2 : min(0.98) : max(0.02) : Inverted(1) with {\n        freq = wah_ctrl.freq;\n    }; \n\n    Wah = select3(sl, Wah2, Wah1, Wah3);\n    \n    b0 = Wah*(Wah*pow(fs,2)*(fs*(1.83199828084009e-21*fs + 4.37177575394138e-17) + 5.9658637492238e-14) + fs*(fs*(fs*(-2.03749178510912e-21*fs - 4.85447818408113e-17) - 6.52701543961359e-14) + 1.41209804493283e-12)) + fs*(fs*(fs*(-7.06526492747902e-21*fs - 2.33820876003629e-16) - 3.26825644515106e-13) - 3.24292143859646e-12);\n\n    b1 = Wah*(Wah*pow(fs,3)*(-7.32799312336037e-21*fs - 8.74355150788276e-17) + fs*(pow(fs,2)*(8.14996714043648e-21*fs + 9.70895636816225e-17) + 2.82419608986565e-12)) + fs*(pow(fs,2)*(2.82610597099161e-20*fs + 4.67641752007259e-16) - 6.48584287719292e-12);\n\n    b2 = Wah*(Wah*pow(fs,2)*(1.09919896850405e-20*pow(fs,2) - 1.19317274984476e-13) + pow(fs,2)*(-1.22249507106547e-20*pow(fs,2) + 1.30540308792272e-13)) + pow(fs,2)*(-4.23915895648741e-20*pow(fs,2) + 6.53651289030211e-13);\n\n    b3 = Wah*(Wah*pow(fs,3)*(-7.32799312336037e-21*fs + 8.74355150788276e-17) + fs*(pow(fs,2)*(8.14996714043648e-21*fs - 9.70895636816225e-17) - 2.82419608986565e-12)) + fs*(pow(fs,2)*(2.82610597099161e-20*fs - 4.67641752007259e-16) + 6.48584287719292e-12);\n\n    b4 = Wah*(Wah*pow(fs,2)*(fs*(1.83199828084009e-21*fs - 4.37177575394138e-17) + 5.9658637492238e-14) + fs*(fs*(fs*(-2.03749178510912e-21*fs + 4.85447818408113e-17) - 6.52701543961359e-14) - 1.41209804493283e-12)) + fs*(fs*(fs*(-7.06526492747902e-21*fs + 2.33820876003629e-16) - 3.26825644515106e-13) + 3.24292143859646e-12);\n\n    a0 = Wah*(Wah*pow(fs,2)*(fs*(-5.27939482245346e-20*fs - 3.84581222788281e-18) - 4.45118937547182e-14) + fs*(fs*(fs*(-2.11837046611975e-19*fs - 1.50671579237021e-18) + 5.84262202161266e-14) - 1.12403772107874e-12)) + fs*(fs*(fs*(3.06896988210923e-19*fs + 2.40276998984285e-17) + 2.93439745158876e-13) + 8.49404844378593e-12) + 2.83847909363319e-11;\n\n    a1 = Wah*(Wah*pow(fs,3)*(2.11175792898138e-19*fs + 7.69162445576562e-18) + fs*(pow(fs,2)*(8.473481864479e-19*fs + 3.01343158474042e-18) - 2.24807544215749e-12)) + fs*(pow(fs,2)*(-1.22758795284369e-18*fs - 4.80553997968569e-17) + 1.69880968875719e-11) + 1.13539163745328e-10;\n\n    a2 = Wah*(Wah*pow(fs,2)*(-3.16763689347207e-19*pow(fs,2) + 8.90237875094365e-14) + pow(fs,2)*(-1.27102227967185e-18*pow(fs,2) - 1.16852440432253e-13)) + pow(fs,2)*(1.84138192926554e-18*pow(fs,2) - 5.86879490317752e-13) + 1.70308745617991e-10;\n\n    a3 = Wah*(Wah*pow(fs,3)*(2.11175792898138e-19*fs - 7.69162445576562e-18) + fs*(pow(fs,2)*(8.473481864479e-19*fs - 3.01343158474042e-18) + 2.24807544215749e-12)) + fs*(pow(fs,2)*(-1.22758795284369e-18*fs + 4.80553997968569e-17) - 1.69880968875719e-11) + 1.13539163745328e-10;\n\n    a4 = Wah*(Wah*pow(fs,2)*(fs*(-5.27939482245346e-20*fs + 3.84581222788281e-18) - 4.45118937547182e-14) + fs*(fs*(fs*(-2.11837046611975e-19*fs + 1.50671579237021e-18) + 5.84262202161266e-14) + 1.12403772107874e-12)) + fs*(fs*(fs*(3.06896988210923e-19*fs - 2.40276998984285e-17) + 2.93439745158876e-13) - 8.49404844378593e-12) + 2.83847909363319e-11;\n};"
 },
 {
  "id": "gx-jenwah",
  "name": "Jen Wah",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Jen Cry Baby wah with Wah position, frequency, mode and wet/dry.",
  "description": "DK circuit simulation from the Jen Wah schematic as a pot-dependent filter with a mode switch and wet/dry. The Italian-made Cry Baby voice.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".wah.Wah",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Jen_Wah/.wah.Wah"
   },
   {
    "label": ".wah.freq",
    "min": 24,
    "max": 360,
    "default": 24,
    "step": 1,
    "unit": "",
    "path": "/Jen_Wah/.wah.freq"
   },
   {
    "label": ".wah.mode",
    "min": 0,
    "max": 2,
    "default": 0,
    "step": 1,
    "unit": "",
    "path": "/Jen_Wah/.wah.mode"
   },
   {
    "label": ".wah.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Jen_Wah/.wah.wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/jenwah.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"jenwah\";\ndeclare name \"Jen Wah\";\ndeclare category \"Guitar Effects\";\ndeclare shortname \"Jen Wah\";\ndeclare description \"Jen Wah\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nprocess(x) = x : _<:*(dry),(*(wet) : pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0))):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = fi.dcblockerat(228.220182634);\n\n    wet = wah_ctrl.wet_dry;\n    dry = 1 - wet;\n\n    Wah1 = (x : an.amp_follower_ud(0.01,0.1) : min(0.99) : max(0.1)): si.smooth(s);\n    \n    Wah2 = wah_ctrl.wah : Inverted(1) :  si.smooth(s);\n    \n    sl = wah_ctrl.mode;\n\n    Wah3 = (os.oscs(freq) + 1) / 2 : min(0.98) : max(0.01) : Inverted(1) with {\n        freq = wah_ctrl.freq;\n    }; \n\n    Wah = select3(sl, Wah2, Wah1, Wah3);\n    \n    b0 = Wah*(Wah*pow(fs,2)*(fs*(4.26313918949843e-21*fs + 6.7438235280676e-17) + 9.21166476483994e-14) + fs*(fs*(fs*(-4.24968880185418e-21*fs - 6.74722090896416e-17) - 9.33056295237144e-14) - 1.7091597982174e-12)) + fs*(fs*(fs*(-7.44753937081794e-21*fs - 2.45894566379345e-16) - 3.53469573143013e-13) - 2.09356017382726e-14);\n\n    b1 = Wah*(Wah*pow(fs,3)*(-1.70525567579937e-20*fs - 1.34876470561352e-16) + fs*(pow(fs,2)*(1.69987552074167e-20*fs + 1.34944418179283e-16) - 3.41831959643481e-12)) + fs*(pow(fs,2)*(2.97901574832717e-20*fs + 4.9178913275869e-16) - 4.18712034765452e-14);\n\n    b2 = Wah*(Wah*pow(fs,2)*(2.55788351369906e-20*pow(fs,2) - 1.84233295296799e-13) + pow(fs,2)*(-2.54981328111251e-20*pow(fs,2) + 1.86611259047429e-13)) + pow(fs,2)*(-4.46852362249076e-20*pow(fs,2) + 7.06939146286026e-13);\n\n    b3 = Wah*(Wah*pow(fs,3)*(-1.70525567579937e-20*fs + 1.34876470561352e-16) + fs*(pow(fs,2)*(1.69987552074167e-20*fs - 1.34944418179283e-16) + 3.41831959643481e-12)) + fs*(pow(fs,2)*(2.97901574832717e-20*fs - 4.9178913275869e-16) + 4.18712034765452e-14);\n\n    b4 = Wah*(Wah*pow(fs,2)*(fs*(4.26313918949843e-21*fs - 6.7438235280676e-17) + 9.21166476483994e-14) + fs*(fs*(fs*(-4.24968880185418e-21*fs + 6.74722090896416e-17) - 9.33056295237144e-14) + 1.7091597982174e-12)) + fs*(fs*(fs*(-7.44753937081794e-21*fs + 2.45894566379345e-16) - 3.53469573143013e-13) + 2.09356017382726e-14);\n\n    a0 = Wah*(Wah*pow(fs,2)*(fs*(-6.99671191908366e-20*fs - 1.39394278118629e-17) - 1.21159485597039e-13) + fs*(fs*(fs*(3.85720103312511e-19*fs + 2.77707619975565e-17) + 1.05494945988648e-13) + 2.75362467265997e-12)) + fs*(fs*(fs*(1.18553561246751e-20*fs + 3.2569797714609e-17) + 5.79248390117011e-13) + 1.0981649358109e-11) + 6.25823789240903e-13;\n\n    a1 = Wah*(Wah*pow(fs,3)*(2.79868476763347e-19*fs + 2.78788556237258e-17) + fs*(pow(fs,2)*(-1.54288041325004e-18*fs - 5.55415239951129e-17) + 5.50724934531995e-12)) + fs*(pow(fs,2)*(-4.74214244987003e-20*fs - 6.51395954292179e-17) + 2.19632987162179e-11) + 2.50329515696361e-12;\n\n    a2 = Wah*(Wah*pow(fs,2)*(-4.1980271514502e-19*pow(fs,2) + 2.42318971194078e-13) + pow(fs,2)*(2.31432061987506e-18*pow(fs,2) - 2.10989891977295e-13)) + pow(fs,2)*(7.11321367480505e-20*pow(fs,2) - 1.15849678023402e-12) + 3.75494273544542e-12;\n\n    a3 = Wah*(Wah*pow(fs,3)*(2.79868476763347e-19*fs - 2.78788556237258e-17) + fs*(pow(fs,2)*(-1.54288041325004e-18*fs + 5.55415239951129e-17) - 5.50724934531995e-12)) + fs*(pow(fs,2)*(-4.74214244987003e-20*fs + 6.51395954292179e-17) - 2.19632987162179e-11) + 2.50329515696361e-12;\n\n    a4 = Wah*(Wah*pow(fs,2)*(fs*(-6.99671191908366e-20*fs + 1.39394278118629e-17) - 1.21159485597039e-13) + fs*(fs*(fs*(3.85720103312511e-19*fs - 2.77707619975565e-17) + 1.05494945988648e-13) - 2.75362467265997e-12)) + fs*(fs*(fs*(1.18553561246751e-20*fs - 3.2569797714609e-17) + 5.79248390117011e-13) - 1.0981649358109e-11) + 6.25823789240903e-13;\n};"
 },
 {
  "id": "lib-korg35-hpf",
  "name": "Korg 35 HPF",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "MS-20 style Korg35 resonant highpass - thin, squelchy filter sweeps",
  "description": "MS-20 style Korg35 resonant highpass - thin, squelchy filter sweeps",
  "author": "Eric Tarr",
  "flags": "",
  "params": [
   {
    "label": "Cutoff",
    "min": 20,
    "max": 8000,
    "default": 300,
    "step": 1,
    "unit": "Hz",
    "path": "/Korg_35_HPF/Cutoff"
   },
   {
    "label": "Resonance",
    "min": 0.707,
    "max": 9.9,
    "default": 2,
    "step": 0.01,
    "unit": "",
    "path": "/Korg_35_HPF/Resonance"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Korg_35_HPF/Level"
   }
  ],
  "faustCode": "declare name \"Korg 35 HPF\";\ndeclare description \"MS-20 style Korg35 resonant highpass - thin, squelchy filter sweeps\";\ndeclare author \"Eric Tarr\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.korg35HPF\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"[0] Cutoff[unit:Hz][scale:log]\", 300, 20, 8000, 1) : si.smoo;\nq     = hslider(\"[1] Resonance\", 2, 0.707, 9.9, 0.01) : si.smoo;\nlevel = hslider(\"[2] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\n\nnormFreq = log10(max(20, freq)/20) / 3 : min(0.99);\nprocess = ve.korg35HPF(normFreq, max(0.707, q)) : ma.tanh : *(level);"
 },
 {
  "id": "lib-korg35-lpf",
  "name": "Korg 35 LPF",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "MS-20 style Korg35 2-pole lowpass with screaming self-oscillating resonance",
  "description": "MS-20 style Korg35 2-pole lowpass with screaming self-oscillating resonance",
  "author": "Eric Tarr",
  "flags": "",
  "params": [
   {
    "label": "Cutoff",
    "min": 40,
    "max": 12000,
    "default": 1500,
    "step": 1,
    "unit": "Hz",
    "path": "/Korg_35_LPF/Cutoff"
   },
   {
    "label": "Resonance",
    "min": 0.707,
    "max": 9.9,
    "default": 2,
    "step": 0.01,
    "unit": "",
    "path": "/Korg_35_LPF/Resonance"
   },
   {
    "label": "Drive",
    "min": 0,
    "max": 30,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Korg_35_LPF/Drive"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Korg_35_LPF/Level"
   }
  ],
  "faustCode": "declare name \"Korg 35 LPF\";\ndeclare description \"MS-20 style Korg35 2-pole lowpass with screaming self-oscillating resonance\";\ndeclare author \"Eric Tarr\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.korg35LPF\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"[0] Cutoff[unit:Hz][scale:log]\", 1500, 40, 12000, 1) : si.smoo;\nq     = hslider(\"[1] Resonance\", 2, 0.707, 9.9, 0.01) : si.smoo;\ndrive = hslider(\"[2] Drive[unit:dB]\", 0, 0, 30, 0.1) : ba.db2linear : si.smoo;\nlevel = hslider(\"[3] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\n\nnormFreq = log10(max(20, freq)/20) / 3 : min(0.99);\nprocess = *(drive) : ve.korg35LPF(normFreq, max(0.707, q)) : ma.tanh : *(level);"
 },
 {
  "id": "gx-low-high-pass",
  "name": "Low/High Pass Filter",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Adjustable low-cut and high-cut filters plus band-limiting speaker-style pass filters.",
  "description": "A pair of adjustable high-pass and low-pass filters (low freq / high freq) followed by fixed band-limiting filters used in guitarix for speaker emulation. Trims rumble and fizz from a signal chain.",
  "author": "brummer",
  "flags": "-double",
  "params": [
   {
    "label": "lowfreq",
    "min": 20,
    "max": 1000,
    "default": 130,
    "step": 10,
    "unit": "",
    "path": "/low_high_pass/.low_high_pass.lhc/lowfreq"
   },
   {
    "label": "highfreq",
    "min": 1000,
    "max": 12000,
    "default": 5000,
    "step": 10,
    "unit": "",
    "path": "/low_high_pass/.low_high_pass.lhc/highfreq"
   },
   {
    "label": "low freq",
    "min": 20,
    "max": 12000,
    "default": 5000,
    "step": 10,
    "unit": "",
    "path": "/low_high_pass/.low_high_pass.lhp/low_freq"
   },
   {
    "label": "high freq",
    "min": 20,
    "max": 7040,
    "default": 130,
    "step": 10,
    "unit": "",
    "path": "/low_high_pass/.low_high_pass.lhp/high_freq"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/low_high_pass.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id     \"low_highpass\";\ndeclare name   \"low high pass\";\ndeclare shortname \"L/H/Filter\";\ndeclare category \"Tone Control\";\ndeclare groups \".low_high_pass.lhp[low_highpass], .low_high_pass.lhc[low_highcutoff]\";\n\ndeclare version \t\"0.01\";\ndeclare author \t\t\"brummer\";\ndeclare license \t\"BSD\";\ndeclare copyright \t\"(c)brummer 2008\";\n\nimport(\"stdfaust.lib\"); \nimport(\"guitarix.lib\");\n\n//-speaker emulation\nsbp1    \t\t= vslider(\"lowfreq[name:low freq][tooltip:low-freq cutoff Hz]\",130,20,1000,10);\nsbp2    \t\t= vslider(\"highfreq[name:high freq][tooltip:high-freq cutoff Hz]\",5000,1000,12000,10);\nswitch1 \t\t= checkbox(\"onoff[name:low highcutoff]\");\nsbp \t\t\t= hgroup(\".low_high_pass.lhc\", bypass(switch1, +(anti_denormal_ac) : ef.speakerbp(sbp1,sbp2)));\n\n//------------------------------ low/high-passfilters --------------------------------------\n\ntf1N(b0,b1,a1) = _ <: *(b0), (mem : *(b1)) :> + ~ *(0-a1);\n\ntf2N(b0,b1,b2,a1,a2) = sub ~ conv2(a1,a2) : conv3(b0,b1,b2)\nwith {\n  conv3(k0,k1,k2,x)     = k0*x + k1*x' + k2*x'';\n  conv2(k0,k1,x)        = k0*x + k1*x';\n  sub(x,y)              = y-x;\n};\n\ntf1sN(b1,b0,a0,w1) = tf1N(b0d,b1d,a1d)\nwith {\n  c   = 1/tan((w1)*0.5/ma.SR); // bilinear-transform scale-factor\n  d   = a0 + c;\n  b1d = (b0 - b1*c) / d;\n  b0d = (b0 + b1*c) / d;\n  a1d = (a0 - c) / d;\n};\n\ntf2sN(b2,b1,b0,a1,a0,w1) = tf2N(b0d,b1d,b2d,a1d,a2d)\nwith {\n  c   = 1/tan((w1)*0.5/ma.SR); // bilinear-transform scale-factor\n  csq = c*c;\n  d   = a0 + a1 * c + csq;\n  b0d = (b0 + b1 * c + b2 * csq)/d;\n  b1d = 2 * (b0 - b2 * csq)/d;\n  b2d = (b0 - b1 * c + b2 * csq)/d;\n  a1d = 2 * (a0 - csq)/d;\n  a2d = (a0 - a1*c + csq)/d;\n};\n\nlowpassN(N,fc) = lowpass0_highpass1N(0,N,fc);\nhighpassN(N,fc) = lowpass0_highpass1N(1,N,fc);\nlowpass0_highpass1N(s,N,fc) = lphpr(s,N,N,fc)\nwith {\n  lphpr(s,0,N,fc) = _;\n  lphpr(s,1,N,fc) = tf1sN(s,1-s,1,2*ma.PI*fc);\n  lphpr(s,O,N,fc) = lphpr(s,(O-2),N,fc) : tf2sN(s,0,1-s,a1s,1,w1) with {\n    parity = N % 2;\n    S = (O-parity)/2; // current section number\n    a1s = -2*cos(-ma.PI + (1-parity)*ma.PI/(2*N) + (S-1+parity)*ma.PI/N);\n    w1 = 2*ma.PI*fc;\n  };\n};\n\n//-low and fi.highpass\n\nlowpassfreq  \t= nentry(\"low_freq[name:low freq]\", 5000, 20, 12000, 10);\nhighpassfreq \t= nentry(\"high_freq[name:high freq]\", 130, 20, 7040, 10);\nswitch       \t= checkbox(\"on_off[name:low fi.highpass]\");\npasso \t\t \t= +(anti_denormal_ac) : lowpassN(1,lowpassfreq) : highpassN(1,highpassfreq);\npass \t\t \t= hgroup(\".low_high_pass.lhp\", bypass(switch, passo));\n\nprocess \t\t=  pass  : sbp ;"
 },
 {
  "id": "gx-maestrowah",
  "name": "Maestro Boomerang Wah",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Maestro Boomerang EG-1 wah with Wah position, frequency, mode and wet/dry.",
  "description": "DK circuit simulation from the Maestro Boomerang schematic as a pot-dependent filter with a mode switch and wet/dry. A deep, vocal wah sweep.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".wah.Wah",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Maestro_Wah/.wah.Wah"
   },
   {
    "label": ".wah.freq",
    "min": 24,
    "max": 360,
    "default": 24,
    "step": 1,
    "unit": "",
    "path": "/Maestro_Wah/.wah.freq"
   },
   {
    "label": ".wah.mode",
    "min": 0,
    "max": 2,
    "default": 0,
    "step": 1,
    "unit": "",
    "path": "/Maestro_Wah/.wah.mode"
   },
   {
    "label": ".wah.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Maestro_Wah/.wah.wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/maestrowah.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"maestrowah\";\ndeclare name \"Maestro Wah\";\ndeclare category \"Guitar Effects\";\ndeclare shortname \"Maestro Wah\";\ndeclare description \"Maestro Boomerang  Wah  EG-1\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nprocess(x) = x : _<:*(dry),(*(wet) : pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0))):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = fi.dcblockerat(64.7682298922);\n\n    wet = wah_ctrl.wet_dry;\n    dry = 1 - wet;\n\n    Wah1 = (x : an.amp_follower_ud(0.01,0.1) : min(0.75) : max(0.09) );\n\n    Wah2 = wah_ctrl.wah : Inverted(1) : LogPot(1) : si.smooth(s);\n \n    sl = wah_ctrl.mode;\n\n    Wah3 = (os.oscs(freq) + 1) / 2 : min(0.91) : max(0.25) : Inverted(1) with {\n        freq = wah_ctrl.freq;\n    }; \n\n    Wah = select3(sl, Wah2, Wah1, Wah3);\n    \n    b0 = Wah*(Wah*pow(fs,2)*(fs*(2.72075590065939e-21*fs + 2.47828940556324e-17) + 8.86819759919558e-14) + pow(fs,2)*(fs*(-2.71455853073723e-21*fs - 2.47794028705763e-17) - 8.86817888313842e-14)) + fs*(fs*(fs*(-3.51316538913314e-20*fs - 4.11229500551683e-16) - 1.76902751745081e-12) - 1.98647626221981e-11);\n\n    b1 = Wah*(Wah*pow(fs,3)*(-1.08830236026375e-20*fs - 4.95657881112649e-17) + pow(fs,3)*(1.08582341229489e-20*fs + 4.95588057411526e-17)) + fs*(pow(fs,2)*(1.40526615565326e-19*fs + 8.22459001103366e-16) - 3.97295252443962e-11);\n\n    b2 = Wah*(Wah*pow(fs,2)*(1.63245354039563e-20*pow(fs,2) - 1.77363951983912e-13) + pow(fs,2)*(-1.62873511844234e-20*pow(fs,2) + 1.77363577662768e-13)) + pow(fs,2)*(-2.10789923347988e-19*pow(fs,2) + 3.53805503490162e-12);\n\n    b3 = Wah*(Wah*pow(fs,3)*(-1.08830236026375e-20*fs + 4.95657881112649e-17) + pow(fs,3)*(1.08582341229489e-20*fs - 4.95588057411526e-17)) + fs*(pow(fs,2)*(1.40526615565326e-19*fs - 8.22459001103366e-16) + 3.97295252443962e-11);\n\n    b4 = Wah*(Wah*pow(fs,2)*(fs*(2.72075590065939e-21*fs - 2.47828940556324e-17) + 8.86819759919558e-14) + pow(fs,2)*(fs*(-2.71455853073723e-21*fs + 2.47794028705763e-17) - 8.86817888313842e-14)) + fs*(fs*(fs*(-3.51316538913314e-20*fs + 4.11229500551683e-16) - 1.76902751745081e-12) + 1.98647626221981e-11);\n\n    a0 = Wah*(Wah*pow(fs,2)*(fs*(-4.53925105453318e-22*fs - 2.20007271917577e-18) - 1.9840085993285e-14) + fs*(fs*(fs*(3.15399184914731e-19*fs + 2.2050952353796e-17) + 2.81635784152467e-14) + 3.968017198657e-12)) + fs*(fs*(fs*(2.95651915836617e-20*fs + 3.70386813965067e-17) + 5.39738799500148e-13) + 7.65730526965241e-11) + 7.93603439731401e-10;\n\n    a1 = Wah*(Wah*pow(fs,3)*(1.81570042181327e-21*fs + 4.40014543835154e-18) + fs*(pow(fs,2)*(-1.26159673965892e-18*fs - 4.4101904707592e-17) + 7.93603439731401e-12)) + fs*(pow(fs,2)*(-1.18260766334647e-19*fs - 7.40773627930135e-17) + 1.53146105393048e-10) + 3.1744137589256e-9;\n\n    a2 = Wah*(Wah*pow(fs,2)*(-2.72355063271991e-21*pow(fs,2) + 3.968017198657e-14) + pow(fs,2)*(1.89239510948839e-18*pow(fs,2) - 5.63271568304933e-14)) + pow(fs,2)*(1.7739114950197e-19*pow(fs,2) - 1.0794775990003e-12) + 4.76162063838841e-9;\n\n    a3 = Wah*(Wah*pow(fs,3)*(1.81570042181327e-21*fs - 4.40014543835154e-18) + fs*(pow(fs,2)*(-1.26159673965892e-18*fs + 4.4101904707592e-17) - 7.93603439731401e-12)) + fs*(pow(fs,2)*(-1.18260766334647e-19*fs + 7.40773627930135e-17) - 1.53146105393048e-10) + 3.1744137589256e-9;\n\n    a4 = Wah*(Wah*pow(fs,2)*(fs*(-4.53925105453318e-22*fs + 2.20007271917577e-18) - 1.9840085993285e-14) + fs*(fs*(fs*(3.15399184914731e-19*fs - 2.2050952353796e-17) + 2.81635784152467e-14) - 3.968017198657e-12)) + fs*(fs*(fs*(2.95651915836617e-20*fs - 3.70386813965067e-17) + 5.39738799500148e-13) - 7.65730526965241e-11) + 7.93603439731401e-10;\n};"
 },
 {
  "id": "lib-moog-half-ladder",
  "name": "Moog Half Ladder",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "2-pole Moog half-ladder lowpass (Zavalishin VA) - the lighter, brighter cousin of the 4-pole ladder",
  "description": "2-pole Moog half-ladder lowpass (Zavalishin VA) - the lighter, brighter cousin of the 4-pole ladder",
  "author": "Eric Tarr",
  "flags": "",
  "params": [
   {
    "label": "Cutoff",
    "min": 40,
    "max": 12000,
    "default": 1500,
    "step": 1,
    "unit": "Hz",
    "path": "/Moog_Half_Ladder/Cutoff"
   },
   {
    "label": "Resonance",
    "min": 0.707,
    "max": 20,
    "default": 2,
    "step": 0.01,
    "unit": "",
    "path": "/Moog_Half_Ladder/Resonance"
   },
   {
    "label": "Drive",
    "min": 0,
    "max": 30,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Moog_Half_Ladder/Drive"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Moog_Half_Ladder/Level"
   }
  ],
  "faustCode": "declare name \"Moog Half Ladder\";\ndeclare description \"2-pole Moog half-ladder lowpass (Zavalishin VA) - the lighter, brighter cousin of the 4-pole ladder\";\ndeclare author \"Eric Tarr\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.moogHalfLadder\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"[0] Cutoff[unit:Hz][scale:log]\", 1500, 40, 12000, 1) : si.smoo;\nq     = hslider(\"[1] Resonance\", 2, 0.707, 20, 0.01) : si.smoo;\ndrive = hslider(\"[2] Drive[unit:dB]\", 0, 0, 30, 0.1) : ba.db2linear : si.smoo;\nlevel = hslider(\"[3] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\nnormFreq = log10(max(20, freq)/20) / 3 : min(0.99);\nprocess = *(drive) : ve.moogHalfLadder(normFreq, max(0.707, q)) : *(level);"
 },
 {
  "id": "lib-moog-ladder",
  "name": "Moog Ladder",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "Zavalishin-style virtual-analog Moog transistor ladder lowpass with resonance and drive",
  "description": "Zavalishin-style virtual-analog Moog transistor ladder lowpass with resonance and drive",
  "author": "Eric Tarr",
  "flags": "",
  "params": [
   {
    "label": "Cutoff",
    "min": 40,
    "max": 12000,
    "default": 1200,
    "step": 1,
    "unit": "Hz",
    "path": "/Moog_Ladder/Cutoff"
   },
   {
    "label": "Resonance",
    "min": 0.707,
    "max": 20,
    "default": 2,
    "step": 0.01,
    "unit": "",
    "path": "/Moog_Ladder/Resonance"
   },
   {
    "label": "Drive",
    "min": 0,
    "max": 30,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/Moog_Ladder/Drive"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Moog_Ladder/Level"
   }
  ],
  "faustCode": "declare name \"Moog Ladder\";\ndeclare description \"Zavalishin-style virtual-analog Moog transistor ladder lowpass with resonance and drive\";\ndeclare author \"Eric Tarr\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.moogLadder\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"[0] Cutoff[unit:Hz][scale:log]\", 1200, 40, 12000, 1) : si.smoo;\nq     = hslider(\"[1] Resonance\", 2, 0.707, 20, 0.01) : si.smoo;\ndrive = hslider(\"[2] Drive[unit:dB]\", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;\nlevel = hslider(\"[3] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\n\nnormFreq = log10(max(20, freq)/20) / 3 : min(0.99);\nprocess = *(drive) : ve.moogLadder(normFreq, max(0.707, q)) : *(level);"
 },
 {
  "id": "gx-moog",
  "name": "Moog Ladder Filter",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Moog-style ladder low-pass with cutoff and resonance.",
  "description": "A Moog ladder low-pass filter (moogvcf) with Q (resonance) and cutoff frequency controls. Synth-style filtering for guitar.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Q",
    "min": 0,
    "max": 4,
    "default": 1,
    "step": 0.1,
    "unit": "",
    "path": "/Moog_Filter/Q"
   },
   {
    "label": "fr",
    "min": 440,
    "max": 6000,
    "default": 3000,
    "step": 10,
    "unit": "",
    "path": "/Moog_Filter/fr"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/moog.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id      \"moog\";\ndeclare name    \"Moog Filter\";\ndeclare category \"Tone Control\";\ndeclare license \"BSD\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nQ \t\t= hslider(\"Q\", 1, 0, 4, 0.1);\nfr \t\t= hslider(\"fr\", 3000, 440, 6000, 10): smoothi(0.999);\n\nprocess_wide = ( +(anti_denormal_ac): moogvcfN(Q,fr)), (+(anti_denormal_ac): moogvcfN(Q,fr));\n\n// mono wrapper added by the Chameleon port (pedal is mono in / mono out)\nprocess = _ <: process_wide :> *(0.5);"
 },
 {
  "id": "lib-moog-vcf",
  "name": "Moog VCF",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "JOS Moog VCF (4 one-poles with feedback) - classic analog-style resonant lowpass",
  "description": "JOS Moog VCF (4 one-poles with feedback) - classic analog-style resonant lowpass",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Cutoff",
    "min": 40,
    "max": 10000,
    "default": 1200,
    "step": 1,
    "unit": "Hz",
    "path": "/Moog_VCF/Cutoff"
   },
   {
    "label": "Resonance",
    "min": 0,
    "max": 0.99,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/Moog_VCF/Resonance"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Moog_VCF/Level"
   }
  ],
  "faustCode": "declare name \"Moog VCF\";\ndeclare description \"JOS Moog VCF (4 one-poles with feedback) - classic analog-style resonant lowpass\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.moog_vcf\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"[0] Cutoff[unit:Hz][scale:log]\", 1200, 40, 10000, 1) : si.smoo;\nres   = hslider(\"[1] Resonance\", 0.6, 0, 0.99, 0.01) : si.smoo;\nlevel = hslider(\"[2] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\nprocess = ve.moog_vcf(res, freq) : *(level);"
 },
 {
  "id": "lib-oberheim-bpf",
  "name": "Oberheim SEM BPF",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "Oberheim SEM state-variable bandpass - honky, vocal band sweeps",
  "description": "Oberheim SEM state-variable bandpass - honky, vocal band sweeps",
  "author": "Eric Tarr",
  "flags": "",
  "params": [
   {
    "label": "Center",
    "min": 60,
    "max": 8000,
    "default": 800,
    "step": 1,
    "unit": "Hz",
    "path": "/Oberheim_SEM_BPF/Center"
   },
   {
    "label": "Resonance",
    "min": 0.5,
    "max": 10,
    "default": 2,
    "step": 0.01,
    "unit": "",
    "path": "/Oberheim_SEM_BPF/Resonance"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 24,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/Oberheim_SEM_BPF/Level"
   }
  ],
  "faustCode": "declare name \"Oberheim SEM BPF\";\ndeclare description \"Oberheim SEM state-variable bandpass - honky, vocal band sweeps\";\ndeclare author \"Eric Tarr\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.oberheimBPF\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"[0] Center[unit:Hz][scale:log]\", 800, 60, 8000, 1) : si.smoo;\nq     = hslider(\"[1] Resonance\", 2, 0.5, 10, 0.01) : si.smoo;\nlevel = hslider(\"[2] Level[unit:dB]\", 6, -20, 24, 0.1) : ba.db2linear : si.smoo;\n\nnormFreq = log10(max(20, freq)/20) / 3 : min(0.99);\nprocess = ve.oberheimBPF(normFreq, max(0.5, q)) : *(level);"
 },
 {
  "id": "lib-oberheim-hpf",
  "name": "Oberheim SEM HPF",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "Oberheim SEM state-variable highpass - resonant thinning and telephone tones",
  "description": "Oberheim SEM state-variable highpass - resonant thinning and telephone tones",
  "author": "Eric Tarr",
  "flags": "",
  "params": [
   {
    "label": "Cutoff",
    "min": 20,
    "max": 8000,
    "default": 400,
    "step": 1,
    "unit": "Hz",
    "path": "/Oberheim_SEM_HPF/Cutoff"
   },
   {
    "label": "Resonance",
    "min": 0.5,
    "max": 10,
    "default": 1.5,
    "step": 0.01,
    "unit": "",
    "path": "/Oberheim_SEM_HPF/Resonance"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Oberheim_SEM_HPF/Level"
   }
  ],
  "faustCode": "declare name \"Oberheim SEM HPF\";\ndeclare description \"Oberheim SEM state-variable highpass - resonant thinning and telephone tones\";\ndeclare author \"Eric Tarr\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.oberheimHPF\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"[0] Cutoff[unit:Hz][scale:log]\", 400, 20, 8000, 1) : si.smoo;\nq     = hslider(\"[1] Resonance\", 1.5, 0.5, 10, 0.01) : si.smoo;\nlevel = hslider(\"[2] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\nnormFreq = log10(max(20, freq)/20) / 3 : min(0.99);\nprocess = ve.oberheimHPF(normFreq, max(0.5, q)) : *(level);"
 },
 {
  "id": "lib-oberheim-lpf",
  "name": "Oberheim SEM LPF",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "Oberheim SEM state-variable lowpass (Zavalishin VA model) - smooth, musical resonance",
  "description": "Oberheim SEM state-variable lowpass (Zavalishin VA model) - smooth, musical resonance",
  "author": "Eric Tarr",
  "flags": "",
  "params": [
   {
    "label": "Cutoff",
    "min": 40,
    "max": 12000,
    "default": 1500,
    "step": 1,
    "unit": "Hz",
    "path": "/Oberheim_SEM_LPF/Cutoff"
   },
   {
    "label": "Resonance",
    "min": 0.5,
    "max": 10,
    "default": 1.5,
    "step": 0.01,
    "unit": "",
    "path": "/Oberheim_SEM_LPF/Resonance"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Oberheim_SEM_LPF/Level"
   }
  ],
  "faustCode": "declare name \"Oberheim SEM LPF\";\ndeclare description \"Oberheim SEM state-variable lowpass (Zavalishin VA model) - smooth, musical resonance\";\ndeclare author \"Eric Tarr\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.oberheimLPF\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"[0] Cutoff[unit:Hz][scale:log]\", 1500, 40, 12000, 1) : si.smoo;\nq     = hslider(\"[1] Resonance\", 1.5, 0.5, 10, 0.01) : si.smoo;\nlevel = hslider(\"[2] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\n\nnormFreq = log10(max(20, freq)/20) / 3 : min(0.99);\nprocess = ve.oberheimLPF(normFreq, max(0.5, q)) : *(level);"
 },
 {
  "id": "gx-rolandwah",
  "name": "Roland Double Beat",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Roland AW-10 Double Beat fuzz-wah with an LFO-driven wah and transistor fuzz.",
  "description": "DK circuit simulation from the Roland Wah schematic combined with a transistor fuzz stage (two transistor-stage tables); the wah is swept by an LFO set in BPM. Fuzz, Wah and wet/dry recreate the Double Beat's fuzz-wah combo.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Roland_Double_Beat/wet_dry"
   },
   {
    "label": "Fuzz",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Roland_Double_Beat/Fuzz"
   },
   {
    "label": "Wah",
    "min": 0.02,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Roland_Double_Beat/Wah"
   },
   {
    "label": "lfobpm",
    "min": 24,
    "max": 360,
    "default": 24,
    "step": 1,
    "unit": "",
    "path": "/Roland_Double_Beat/lfobpm"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/rolandwah.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"rolandwah\";\ndeclare name \"Roland Double Beat\";\ndeclare category \"Guitar Effects\";\ndeclare shortname \"Double Beat\";\ndeclare description \"Roland Double Beat\";\n\nimport(\"stdfaust.lib\");\nimport(\"trany.lib\");\n\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n\n    wet = vslider(\"wet_dry[name:Dry/Wet][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\n    dry = 1 - wet;\n   // gain = vslider(\"Gain[name:Gain][tooltip:Gain of the Fuzz Section (dB)]\", -12, -40, 4, 0.1) : ba.db2linear : si.smooth(s);\n    clip = tranystage(TB_KT88_68k,86.0,2700.0,5.562895) : tranystage(TB_KT88_68k,86.0,2700.0,5.562895) ;\n\nfuzz = fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0,b6/a0,b7/a0,b8/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0,a6/a0,a7/a0,a8/a0))  with {\n    shape = (1.1 -Fuzz ) * 20.;\n    atan_v=1.0/atan(shape);\n    //clip(x) = 0.4 * (min(0.7514,max(-0.4514,x)));\n\n    Fuzz = vslider(\"Fuzz[name:Fuzz]\", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);\n    \n    b0 = Fuzz*pow(fs,4)*(fs*(fs*(8.60349117319693e-33*fs + 7.42470650533226e-26) + 3.80828462584721e-23) + 8.28085042193987e-22) + pow(fs,3)*(fs*(fs*(fs*(-2.62267793598193e-32*fs - 2.30252524666021e-25) - 1.21809214941527e-22) - 4.47006878788668e-21) - 4.14042521096994e-20);\n\n    b1 = Fuzz*pow(fs,5)*(fs*(-5.16209470391816e-32*fs - 2.9698826021329e-25) - 7.61656925169443e-23) + pow(fs,3)*(pow(fs,2)*(fs*(1.57360676158916e-31*fs + 9.21010098664083e-25) + 2.43618429883054e-22) - 8.28085042193987e-20);\n\n    b2 = Fuzz*pow(fs,4)*(fs*(fs*(1.20448876424757e-31*fs + 2.9698826021329e-25) - 7.61656925169443e-23) - 3.31234016877595e-21) + pow(fs,3)*(fs*(fs*(fs*(-3.6717491103747e-31*fs - 9.21010098664083e-25) + 2.43618429883054e-22) + 1.78802751515467e-20) + 8.28085042193987e-20);\n\n    b3 = Fuzz*pow(fs,5)*(fs*(-1.20448876424757e-31*fs + 2.9698826021329e-25) + 2.28497077550833e-22) + pow(fs,3)*(pow(fs,2)*(fs*(3.6717491103747e-31*fs - 9.21010098664083e-25) - 7.30855289649162e-22) + 2.48425512658196e-19);\n\n    b4 = Fuzz*pow(fs,4)*(-7.42470650533226e-25*pow(fs,2) + 4.96851025316392e-21) + pow(fs,4)*(2.30252524666021e-24*pow(fs,2) - 2.68204127273201e-20);\n\n    b5 = Fuzz*pow(fs,5)*(fs*(1.20448876424757e-31*fs + 2.9698826021329e-25) - 2.28497077550833e-22) + pow(fs,3)*(pow(fs,2)*(fs*(-3.6717491103747e-31*fs - 9.21010098664083e-25) + 7.30855289649162e-22) - 2.48425512658196e-19);\n\n    b6 = Fuzz*pow(fs,4)*(fs*(fs*(-1.20448876424757e-31*fs + 2.9698826021329e-25) + 7.61656925169443e-23) - 3.31234016877595e-21) + pow(fs,3)*(fs*(fs*(fs*(3.6717491103747e-31*fs - 9.21010098664083e-25) - 2.43618429883054e-22) + 1.78802751515467e-20) - 8.28085042193987e-20);\n\n    b7 = Fuzz*pow(fs,5)*(fs*(5.16209470391816e-32*fs - 2.9698826021329e-25) + 7.61656925169443e-23) + pow(fs,3)*(pow(fs,2)*(fs*(-1.57360676158916e-31*fs + 9.21010098664083e-25) - 2.43618429883054e-22) + 8.28085042193987e-20);\n\n    b8 = Fuzz*pow(fs,4)*(fs*(fs*(-8.60349117319693e-33*fs + 7.42470650533226e-26) - 3.80828462584721e-23) + 8.28085042193987e-22) + pow(fs,3)*(fs*(fs*(fs*(2.62267793598193e-32*fs - 2.30252524666021e-25) + 1.21809214941527e-22) - 4.47006878788668e-21) + 4.14042521096994e-20);\n\n    a0 = Fuzz*fs*(fs*(fs*(fs*(fs*(fs*(fs*(9.64198439050231e-55*fs - 5.76952472985784e-34) - 1.84629565839962e-29) - 5.28116058056682e-26) - 3.4488417342687e-23) - 6.7753494863719e-21) - 1.6046797673707e-19) - 6.03074438986166e-19) + fs*(fs*(fs*(fs*(fs*(fs*(fs*(-1.08067210692624e-54*fs + 1.6917880698614e-33) + 2.29812823706864e-29) + 5.73340871630524e-26) + 3.80795187898005e-23) + 8.56555972538848e-21) + 5.00114968075696e-19) + 8.62923424920947e-18) + 3.01537219493083e-17;\n\n    a1 = Fuzz*fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(-7.71358751240185e-54*fs + 3.46171483791471e-33) + 7.38518263359847e-29) + 1.05623211611336e-25) - 1.35506989727438e-20) - 6.41871906948282e-19) - 3.618446633917e-18) + fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(8.64537685540996e-54*fs - 1.01507284191684e-32) - 9.19251294827458e-29) - 1.14668174326105e-25) + 1.7131119450777e-20) + 2.00045987230279e-18) + 5.17754054952568e-17) + 2.41229775594467e-16;\n\n    a2 = Fuzz*fs*(fs*(fs*(fs*(fs*(fs*(fs*(2.69975562934065e-53*fs - 8.07733462180098e-33) - 7.38518263359847e-29) + 1.05623211611336e-25) + 1.37953669370748e-22) + 1.35506989727438e-20) - 6.41871906948282e-19) - 8.44304214580633e-18) + fs*(fs*(fs*(fs*(fs*(fs*(fs*(-3.02588189939348e-53*fs + 2.36850329780596e-32) + 9.19251294827458e-29) - 1.14668174326105e-25) - 1.52318075159202e-22) - 1.7131119450777e-20) + 2.00045987230279e-18) + 1.20809279488933e-16) + 8.44304214580633e-16;\n\n    a3 = Fuzz*fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(-5.3995112586813e-53*fs + 8.07733462180098e-33) - 7.38518263359847e-29) - 3.16869634834009e-25) + 4.06520969182314e-20) + 6.41871906948282e-19) - 8.44304214580633e-18) + fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(6.05176379878697e-53*fs - 2.36850329780596e-32) + 9.19251294827458e-29) + 3.44004522978315e-25) - 5.13933583523309e-20) - 2.00045987230279e-18) + 1.20809279488933e-16) + 1.68860842916127e-15;\n\n    a4 = Fuzz*pow(fs,2)*(pow(fs,2)*(pow(fs,2)*(6.74938907335162e-53*pow(fs,2) + 1.84629565839962e-28) - 2.06930504056122e-22) + 1.6046797673707e-18) + pow(fs,2)*(pow(fs,2)*(pow(fs,2)*(-7.56470474848371e-53*pow(fs,2) - 2.29812823706864e-28) + 2.28477112738803e-22) - 5.00114968075697e-18) + 2.11076053645158e-15;\n\n    a5 = Fuzz*fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(-5.3995112586813e-53*fs - 8.07733462180098e-33) - 7.38518263359847e-29) + 3.16869634834009e-25) - 4.06520969182314e-20) + 6.41871906948282e-19) + 8.44304214580633e-18) + fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(6.05176379878697e-53*fs + 2.36850329780596e-32) + 9.19251294827458e-29) - 3.44004522978315e-25) + 5.13933583523309e-20) - 2.00045987230279e-18) - 1.20809279488933e-16) + 1.68860842916127e-15;\n\n    a6 = Fuzz*fs*(fs*(fs*(fs*(fs*(fs*(fs*(2.69975562934065e-53*fs + 8.07733462180098e-33) - 7.38518263359847e-29) - 1.05623211611336e-25) + 1.37953669370748e-22) - 1.35506989727438e-20) - 6.41871906948282e-19) + 8.44304214580633e-18) + fs*(fs*(fs*(fs*(fs*(fs*(fs*(-3.02588189939348e-53*fs - 2.36850329780596e-32) + 9.19251294827458e-29) + 1.14668174326105e-25) - 1.52318075159202e-22) + 1.7131119450777e-20) + 2.00045987230279e-18) - 1.20809279488933e-16) + 8.44304214580633e-16;\n\n    a7 = Fuzz*fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(-7.71358751240185e-54*fs - 3.46171483791471e-33) + 7.38518263359847e-29) - 1.05623211611336e-25) + 1.35506989727438e-20) - 6.41871906948282e-19) + 3.618446633917e-18) + fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(8.64537685540996e-54*fs + 1.01507284191684e-32) - 9.19251294827458e-29) + 1.14668174326105e-25) - 1.7131119450777e-20) + 2.00045987230279e-18) - 5.17754054952568e-17) + 2.41229775594467e-16;\n\n    a8 = Fuzz*fs*(fs*(fs*(fs*(fs*(fs*(fs*(9.64198439050231e-55*fs + 5.76952472985784e-34) - 1.84629565839962e-29) + 5.28116058056682e-26) - 3.4488417342687e-23) + 6.7753494863719e-21) - 1.6046797673707e-19) + 6.03074438986166e-19) + fs*(fs*(fs*(fs*(fs*(fs*(fs*(-1.08067210692624e-54*fs - 1.6917880698614e-33) + 2.29812823706864e-29) - 5.73340871630524e-26) + 3.80795187898005e-23) - 8.56555972538848e-21) + 5.00114968075696e-19) - 8.62923424920947e-18) + 3.01537219493083e-17;\n};\n\nwah(x) = x : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0,b6/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0,a6/a0)) with {\n\n    Wah1 = (x : an.amp_follower_ud(0.01,0.1) : min(0.9) : max(0.09) );\n    \n    Wah2 = vslider(\"Wah[name:Wah]\", 0.5, 0.02, 1, 0.01) : Inverted(1) : LogPot(1) : si.smooth(s);\n    \n    sl = checkbox(\"mode[enum:manual|auto|alien]\");\n\n    Wah3 = (os.oscs(freq) + 1) / 2 : min(0.9) : max(0.09) : Inverted(1) with {\n        freq = vslider(\"lfobpm[name:Alien Freq][tooltip:LFO in Beats per Minute]\",24,24,360,1)/60;\n    }; \n\n    Wah = select3(sl, Wah2, Wah1, Wah3);\n\n    b0 = Wah*(Wah*pow(fs,3)*(fs*(fs*(7.18082556296232e-31*fs + 1.2196809675607e-26) + 1.81635217972948e-23) + 9.8345184835125e-22) + pow(fs,2)*(fs*(fs*(fs*(-7.16633351212421e-31*fs - 1.22012125074374e-26) - 1.83126711766163e-23) - 1.21592229012527e-21) - 1.2608516331659e-20)) + pow(fs,2)*(fs*(fs*(fs*(-9.65744972703433e-31*fs - 3.08822188644282e-26) - 4.82624719521696e-23) - 2.88264605310366e-21) - 1.49007855810795e-20);\n\n    b1 = Wah*(Wah*pow(fs,4)*(fs*(-4.30849533777739e-30*fs - 4.87872387024281e-26) - 3.63270435945895e-23) + pow(fs,2)*(pow(fs,2)*(fs*(4.29980010727452e-30*fs + 4.88048500297496e-26) + 3.66253423532326e-23) - 2.5217032663318e-20)) + pow(fs,2)*(pow(fs,2)*(fs*(5.7944698362206e-30*fs + 1.23528875457713e-25) + 9.65249439043393e-23) - 2.98015711621591e-20);\n\n    b2 = Wah*(Wah*pow(fs,3)*(fs*(fs*(1.07712383444435e-29*fs + 6.09840483780351e-26) - 1.81635217972948e-23) - 2.95035554505375e-21) + pow(fs,2)*(fs*(fs*(fs*(-1.07495002681863e-29*fs - 6.1006062537187e-26) + 1.83126711766163e-23) + 3.64776687037582e-21) + 1.2608516331659e-20)) + pow(fs,2)*(fs*(fs*(fs*(-1.44861745905515e-29*fs - 1.54411094322141e-25) + 4.82624719521696e-23) + 8.64793815931099e-21) + 1.49007855810795e-20);\n\n    b3 = Wah*(Wah*pow(fs,4)*(-1.43616511259246e-29*pow(fs,2) + 7.2654087189179e-23) + pow(fs,2)*(pow(fs,2)*(1.43326670242484e-29*pow(fs,2) - 7.32506847064652e-23) + 5.0434065326636e-20)) + pow(fs,2)*(pow(fs,2)*(1.93148994540687e-29*pow(fs,2) - 1.93049887808679e-22) + 5.96031423243182e-20);\n\n    b4 = Wah*(Wah*pow(fs,3)*(fs*(fs*(1.07712383444435e-29*fs - 6.09840483780351e-26) - 1.81635217972948e-23) + 2.95035554505375e-21) + pow(fs,2)*(fs*(fs*(fs*(-1.07495002681863e-29*fs + 6.1006062537187e-26) + 1.83126711766163e-23) - 3.64776687037582e-21) + 1.2608516331659e-20)) + pow(fs,2)*(fs*(fs*(fs*(-1.44861745905515e-29*fs + 1.54411094322141e-25) + 4.82624719521696e-23) - 8.64793815931099e-21) + 1.49007855810795e-20);\n\n    b5 = Wah*(Wah*pow(fs,4)*(fs*(-4.30849533777739e-30*fs + 4.87872387024281e-26) - 3.63270435945895e-23) + pow(fs,2)*(pow(fs,2)*(fs*(4.29980010727452e-30*fs - 4.88048500297496e-26) + 3.66253423532326e-23) - 2.5217032663318e-20)) + pow(fs,2)*(pow(fs,2)*(fs*(5.7944698362206e-30*fs - 1.23528875457713e-25) + 9.65249439043393e-23) - 2.98015711621591e-20);\n\n    b6 = Wah*(Wah*pow(fs,3)*(fs*(fs*(7.18082556296232e-31*fs - 1.2196809675607e-26) + 1.81635217972948e-23) - 9.8345184835125e-22) + pow(fs,2)*(fs*(fs*(fs*(-7.16633351212421e-31*fs + 1.22012125074374e-26) - 1.83126711766163e-23) + 1.21592229012527e-21) - 1.2608516331659e-20)) + pow(fs,2)*(fs*(fs*(fs*(-9.65744972703433e-31*fs + 3.08822188644282e-26) - 4.82624719521696e-23) + 2.88264605310366e-21) - 1.49007855810795e-20);\n\n    a0 = Wah*(Wah*pow(fs,2)*(fs*(fs*(fs*(-4.29845675581904e-29*fs - 3.19373566665743e-26) - 8.90038927961101e-23) - 4.87042253786579e-20) - 3.50713071672392e-19) + fs*(fs*(fs*(fs*(fs*(1.72206886126217e-28*fs + 1.1453389852842e-25) + 9.7683567600612e-23) + 5.2144154673581e-20) + 1.07969798611464e-18) + 5.31383441927866e-18)) + fs*(fs*(fs*(fs*(fs*(5.0345082751012e-30*fs + 1.05561747816346e-26) + 2.55142258602227e-22) + 1.48648313435063e-19) + 3.76182116601294e-18) + 3.09198451037471e-17) + 8.05126427163433e-17;\n\n    a1 = Wah*(Wah*pow(fs,2)*(pow(fs,2)*(fs*(2.57907405349142e-28*fs + 1.27749426666297e-25) + 1.7800778559222e-22) - 7.01426143344783e-19) + fs*(fs*(pow(fs,2)*(fs*(-1.0332413167573e-27*fs - 4.5813559411368e-25) - 1.95367135201224e-22) + 2.15939597222928e-18) + 2.12553376771146e-17)) + fs*(fs*(pow(fs,2)*(fs*(-3.02070496506072e-29*fs - 4.22246991265385e-26) - 5.10284517204454e-22) + 7.52364233202588e-18) + 1.23679380414989e-16) + 4.8307585629806e-16;\n\n    a2 = Wah*(Wah*pow(fs,2)*(fs*(fs*(fs*(-6.44768513372856e-28*fs - 1.59686783332872e-25) + 8.90038927961101e-23) + 1.46112676135974e-19) + 3.50713071672392e-19) + fs*(fs*(fs*(fs*(fs*(2.58310329189325e-27*fs + 5.726694926421e-25) - 9.7683567600612e-23) - 1.56432464020743e-19) - 1.07969798611464e-18) + 2.65691720963933e-17)) + fs*(fs*(fs*(fs*(fs*(7.55176241265181e-29*fs + 5.27808739081731e-26) - 2.55142258602227e-22) - 4.4594494030519e-19) - 3.76182116601294e-18) + 1.54599225518736e-16) + 1.20768964074515e-15;\n\n    a3 = Wah*(Wah*pow(fs,2)*(pow(fs,2)*(8.59691351163808e-28*pow(fs,2) - 3.5601557118444e-22) + 1.40285228668957e-18) + pow(fs,2)*(pow(fs,2)*(-3.44413772252433e-27*pow(fs,2) + 3.90734270402448e-22) - 4.31879194445857e-18)) + pow(fs,2)*(pow(fs,2)*(-1.00690165502024e-28*pow(fs,2) + 1.02056903440891e-21) - 1.50472846640518e-17) + 1.61025285432687e-15;\n\n    a4 = Wah*(Wah*pow(fs,2)*(fs*(fs*(fs*(-6.44768513372856e-28*fs + 1.59686783332872e-25) + 8.90038927961101e-23) - 1.46112676135974e-19) + 3.50713071672392e-19) + fs*(fs*(fs*(fs*(fs*(2.58310329189325e-27*fs - 5.726694926421e-25) - 9.7683567600612e-23) + 1.56432464020743e-19) - 1.07969798611464e-18) - 2.65691720963933e-17)) + fs*(fs*(fs*(fs*(fs*(7.55176241265181e-29*fs - 5.27808739081731e-26) - 2.55142258602227e-22) + 4.4594494030519e-19) - 3.76182116601294e-18) - 1.54599225518736e-16) + 1.20768964074515e-15;\n\n    a5 = Wah*(Wah*pow(fs,2)*(pow(fs,2)*(fs*(2.57907405349142e-28*fs - 1.27749426666297e-25) + 1.7800778559222e-22) - 7.01426143344783e-19) + fs*(fs*(pow(fs,2)*(fs*(-1.0332413167573e-27*fs + 4.5813559411368e-25) - 1.95367135201224e-22) + 2.15939597222928e-18) - 2.12553376771146e-17)) + fs*(fs*(pow(fs,2)*(fs*(-3.02070496506072e-29*fs + 4.22246991265385e-26) - 5.10284517204454e-22) + 7.52364233202588e-18) - 1.23679380414989e-16) + 4.8307585629806e-16;\n\n    a6 = Wah*(Wah*pow(fs,2)*(fs*(fs*(fs*(-4.29845675581904e-29*fs + 3.19373566665743e-26) - 8.90038927961101e-23) + 4.87042253786579e-20) - 3.50713071672392e-19) + fs*(fs*(fs*(fs*(fs*(1.72206886126217e-28*fs - 1.1453389852842e-25) + 9.7683567600612e-23) - 5.2144154673581e-20) + 1.07969798611464e-18) - 5.31383441927866e-18)) + fs*(fs*(fs*(fs*(fs*(5.0345082751012e-30*fs - 1.05561747816346e-26) + 2.55142258602227e-22) - 1.48648313435063e-19) + 3.76182116601294e-18) - 3.09198451037471e-17) + 8.05126427163433e-17;\n};\n\nprocess =  _<:*(dry),(*(wet)  : fuzz  : wah : clip ):>_;"
 },
 {
  "id": "lib-sallenkey-lpf",
  "name": "Sallen-Key LPF",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "2nd-order Sallen-Key virtual-analog lowpass (Zavalishin) - smooth op-amp filter tone",
  "description": "2nd-order Sallen-Key virtual-analog lowpass (Zavalishin) - smooth op-amp filter tone",
  "author": "Eric Tarr",
  "flags": "",
  "params": [
   {
    "label": "Cutoff",
    "min": 40,
    "max": 12000,
    "default": 2000,
    "step": 1,
    "unit": "Hz",
    "path": "/Sallen-Key_LPF/Cutoff"
   },
   {
    "label": "Resonance",
    "min": 0.5,
    "max": 10,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Sallen-Key_LPF/Resonance"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Sallen-Key_LPF/Level"
   }
  ],
  "faustCode": "declare name \"Sallen-Key LPF\";\ndeclare description \"2nd-order Sallen-Key virtual-analog lowpass (Zavalishin) - smooth op-amp filter tone\";\ndeclare author \"Eric Tarr\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.sallenKey2ndOrderLPF\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfreq  = hslider(\"[0] Cutoff[unit:Hz][scale:log]\", 2000, 40, 12000, 1) : si.smoo;\nq     = hslider(\"[1] Resonance\", 1, 0.5, 10, 0.01) : si.smoo;\nlevel = hslider(\"[2] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\n\nnormFreq = log10(max(20, freq)/20) / 3 : min(0.99);\nprocess = ve.sallenKey2ndOrderLPF(normFreq, max(0.5, q)) : *(level);"
 },
 {
  "id": "gx-selwah",
  "name": "Selmer Wah",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Selmer wah pedal with Wah position, frequency, mode and wet/dry.",
  "description": "DK circuit simulation from the Selmer Wah schematic as a pot-dependent filter with a mode switch and wet/dry. A British 1960s wah voice.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".wah.Wah",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Selmer_Wah/.wah.Wah"
   },
   {
    "label": ".wah.freq",
    "min": 24,
    "max": 360,
    "default": 24,
    "step": 1,
    "unit": "",
    "path": "/Selmer_Wah/.wah.freq"
   },
   {
    "label": ".wah.mode",
    "min": 0,
    "max": 2,
    "default": 0,
    "step": 1,
    "unit": "",
    "path": "/Selmer_Wah/.wah.mode"
   },
   {
    "label": ".wah.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Selmer_Wah/.wah.wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/selwah.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"selwah\";\ndeclare name \"Selmer Wah\";\ndeclare category \"Guitar Effects\";\ndeclare shortname \"Selmer Wah\";\ndeclare description \"Selmer Wah\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nprocess(x) = x : _<:*(dry),(*(wet) : pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0))):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = fi.dcblockerat(696.855682347);\n\n    wet = wah_ctrl.wet_dry;\n    dry = 1 - wet;\n\n    Wah1 = (x : an.amp_follower_ud(0.01,0.1) : min(0.99) : max(0.1) : Inverted(1)): si.smooth(s);\n    \n    Wah2 = wah_ctrl.wah :  si.smooth(s);\n    \n    sl = wah_ctrl.mode;\n\n    Wah3 = (os.oscs(freq) + 1) / 2 : min(0.90) : max(0.01) with {\n        freq = wah_ctrl.freq;\n    }; \n\n    Wah = select3(sl, Wah2, Wah1, Wah3);\n    \n    b0 = Wah*(Wah*pow(fs,2)*(fs*(9.34067018664482e-21*fs + 1.87102855759734e-16) + 2.81828342103572e-13) + fs*(fs*(fs*(-9.34656187780755e-21*fs - 1.86919114730712e-16) - 2.77734086106026e-13) + 6.21752156007224e-12)) + fs*(fs*(fs*(-3.81791996652528e-20*fs - 8.47349775377979e-16) - 1.29923285740847e-12) - 2.03089386652508e-11);\n\n    b1 = Wah*(Wah*pow(fs,3)*(-3.73626807465793e-20*fs - 3.74205711519468e-16) + fs*(pow(fs,2)*(3.73862475112302e-20*fs + 3.73838229461424e-16) + 1.24350431201445e-11)) + fs*(pow(fs,2)*(1.52716798661011e-19*fs + 1.69469955075596e-15) - 4.06178773305017e-11);\n\n    b2 = Wah*(Wah*pow(fs,2)*(5.60440211198689e-20*pow(fs,2) - 5.63656684207144e-13) + pow(fs,2)*(-5.60793712668453e-20*pow(fs,2) + 5.55468172212051e-13)) + pow(fs,2)*(-2.29075197991517e-19*pow(fs,2) + 2.59846571481694e-12);\n\n    b3 = Wah*(Wah*pow(fs,3)*(-3.73626807465793e-20*fs + 3.74205711519468e-16) + fs*(pow(fs,2)*(3.73862475112302e-20*fs - 3.73838229461424e-16) - 1.24350431201445e-11)) + fs*(pow(fs,2)*(1.52716798661011e-19*fs - 1.69469955075596e-15) + 4.06178773305017e-11);\n\n    b4 = Wah*(Wah*pow(fs,2)*(fs*(9.34067018664482e-21*fs - 1.87102855759734e-16) + 2.81828342103572e-13) + fs*(fs*(fs*(-9.34656187780755e-21*fs + 1.86919114730712e-16) - 2.77734086106026e-13) - 6.21752156007224e-12)) + fs*(fs*(fs*(-3.81791996652528e-20*fs + 8.47349775377979e-16) - 1.29923285740847e-12) + 2.03089386652508e-11);\n\n    a0 = Wah*(Wah*pow(fs,2)*(fs*(-6.9507309070366e-20*fs - 1.01737279942973e-17) - 8.91391550989893e-14) + fs*(fs*(fs*(-2.47965348716056e-19*fs - 9.25643357134141e-18) + 1.10300249541729e-13) - 2.02588988861339e-12)) + fs*(fs*(fs*(3.2847328592148e-19*fs + 5.6599406495133e-17) + 5.11880447644045e-13) + 1.73599395967319e-11) + 1.0129449443067e-10;\n\n    a1 = Wah*(Wah*pow(fs,3)*(2.78029236281464e-19*fs + 2.03474559885945e-17) + fs*(pow(fs,2)*(9.91861394864224e-19*fs + 1.85128671426828e-17) - 4.05177977722679e-12)) + fs*(pow(fs,2)*(-1.31389314368592e-18*fs - 1.13198812990266e-16) + 3.47198791934638e-11) + 4.05177977722679e-10;\n\n    a2 = Wah*(Wah*pow(fs,2)*(-4.17043854422196e-19*pow(fs,2) + 1.78278310197979e-13) + pow(fs,2)*(-1.48779209229634e-18*pow(fs,2) - 2.20600499083458e-13)) + pow(fs,2)*(1.97083971552888e-18*pow(fs,2) - 1.02376089528809e-12) + 6.07766966584018e-10;\n\n    a3 = Wah*(Wah*pow(fs,3)*(2.78029236281464e-19*fs - 2.03474559885945e-17) + fs*(pow(fs,2)*(9.91861394864224e-19*fs - 1.85128671426828e-17) + 4.05177977722679e-12)) + fs*(pow(fs,2)*(-1.31389314368592e-18*fs + 1.13198812990266e-16) - 3.47198791934638e-11) + 4.05177977722679e-10;\n\n    a4 = Wah*(Wah*pow(fs,2)*(fs*(-6.9507309070366e-20*fs + 1.01737279942973e-17) - 8.91391550989893e-14) + fs*(fs*(fs*(-2.47965348716056e-19*fs + 9.25643357134141e-18) + 1.10300249541729e-13) + 2.02588988861339e-12)) + fs*(fs*(fs*(3.2847328592148e-19*fs - 5.6599406495133e-17) + 5.11880447644045e-13) - 1.73599395967319e-11) + 1.0129449443067e-10;\n};"
 },
 {
  "id": "owl-sweep-wah",
  "name": "Sweep Wah",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "OWL patches",
  "license": "GPL-2.0",
  "shortDesc": "CryBaby wah swept by an LFO between two pedal positions, with dry/wet",
  "description": "CryBaby wah swept by an LFO between two pedal positions, with dry/wet",
  "author": "Rebel Technology / OWL (JOS crybaby)",
  "flags": "",
  "params": [
   {
    "label": "Rate",
    "min": 0.05,
    "max": 12,
    "default": 2,
    "step": 0.001,
    "unit": "Hz",
    "path": "/Sweep_Wah/Rate"
   },
   {
    "label": "Low",
    "min": 0,
    "max": 1,
    "default": 0.2,
    "step": 0.01,
    "unit": "",
    "path": "/Sweep_Wah/Low"
   },
   {
    "label": "High",
    "min": 0,
    "max": 1,
    "default": 0.8,
    "step": 0.01,
    "unit": "",
    "path": "/Sweep_Wah/High"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.8,
    "step": 0.01,
    "unit": "",
    "path": "/Sweep_Wah/Dry_Wet"
   }
  ],
  "faustCode": "declare name \"Sweep Wah\";\ndeclare description \"CryBaby wah swept by an LFO between two pedal positions, with dry/wet\";\ndeclare author \"Rebel Technology / OWL (JOS crybaby)\";\ndeclare license \"GPL-2.0\";\ndeclare source \"pingdynasty/OwlPatches Faust/SweepWah.dsp\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfreq = hslider(\"[0] Rate[unit:Hz]\", 2, 0.05, 12, 0.001) : si.smoo;\nlo   = hslider(\"[1] Low\", 0.2, 0, 1, 0.01) : si.smoo;\nhi   = hslider(\"[2] High\", 0.8, 0, 1, 0.01) : si.smoo;\nwet  = hslider(\"[3] Dry/Wet\", 0.8, 0, 1, 0.01) : si.smoo;\n\nlfo = os.oscrs(freq) + 1.0 : *(0.5);\nwah = lo*lfo + hi*(1.0-lfo);\nprocess = _ <: (ve.crybaby(wah) : *(wet)), *(1-wet) :> _;"
 },
 {
  "id": "lib-tone-stack",
  "name": "Tone Stack",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Passive amp tone stacks from exact component values: Bassman, JCM800, Twin, AC30, Mesa, Soldano, Princeton",
  "description": "Passive amp tone stacks from exact component values: Bassman, JCM800, Twin, AC30, Mesa, Soldano, Princeton",
  "author": "Guitarix project / David Yeh (tonestack analysis)",
  "flags": "",
  "params": [
   {
    "label": "Model",
    "min": 0,
    "max": 6,
    "default": 0,
    "step": 1,
    "unit": "",
    "path": "/Tone_Stack/Model"
   },
   {
    "label": "Bass",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tone_Stack/Bass"
   },
   {
    "label": "Middle",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tone_Stack/Middle"
   },
   {
    "label": "Treble",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tone_Stack/Treble"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 24,
    "default": 6,
    "step": 0.1,
    "unit": "dB",
    "path": "/Tone_Stack/Level"
   }
  ],
  "faustCode": "declare name \"Tone Stack\";\ndeclare description \"Passive amp tone stacks from exact component values: Bassman, JCM800, Twin, AC30, Mesa, Soldano, Princeton\";\ndeclare author \"Guitarix project / David Yeh (tonestack analysis)\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/tonestacks.lib\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\nts = library(\"tonestacks.lib\");\n\nmodel = nentry(\"[0] Model[style:menu{'Bassman':0;'JCM800':1;'Twin':2;'AC30':3;'Mesa':4;'Soldano':5;'Princeton':6}]\", 0, 0, 6, 1);\nb = hslider(\"[1] Bass\", 0.5, 0, 1, 0.01) : si.smoo;\nm = hslider(\"[2] Middle\", 0.5, 0, 1, 0.01) : si.smoo;\nt = hslider(\"[3] Treble\", 0.5, 0, 1, 0.01) : si.smoo;\nlevel = hslider(\"[4] Level[unit:dB]\", 6, -20, 24, 0.1) : ba.db2linear : si.smoo;\n\nstacks = ts.bassman(t,m,b), ts.jcm800(t,m,b), ts.twin(t,m,b), ts.ac30(t,m,b), ts.mesa(t,m,b), ts.soldano(t,m,b), ts.princeton(t,m,b);\nprocess = _ <: stacks : ba.selectn(7, model) : *(level);"
 },
 {
  "id": "gx-voxwah",
  "name": "Vox V847 Wah",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Vox V847 wah with Wah position, frequency, mode and wet/dry.",
  "description": "DK circuit simulation from the Vox V847 schematic as a pot-dependent filter with a mode switch and wet/dry. The classic Vox wah sweep.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": ".wah.Wah",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Vox_Wah_V847/.wah.Wah"
   },
   {
    "label": ".wah.freq",
    "min": 24,
    "max": 360,
    "default": 24,
    "step": 1,
    "unit": "",
    "path": "/Vox_Wah_V847/.wah.freq"
   },
   {
    "label": ".wah.mode",
    "min": 0,
    "max": 2,
    "default": 0,
    "step": 1,
    "unit": "",
    "path": "/Vox_Wah_V847/.wah.mode"
   },
   {
    "label": ".wah.wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Vox_Wah_V847/.wah.wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/voxwah.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// generated automatically\n// DO NOT MODIFY!\ndeclare id \"voxwah\";\ndeclare name \"Vox Wah V847\";\ndeclare category \"Guitar Effects\";\ndeclare shortname \"Vox Wah\";\ndeclare description \"Vox Wah V847\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nprocess(x) = x : _<:*(dry),(*(wet) : pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0),(a1/a0,a2/a0,a3/a0,a4/a0))):>_ with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = fi.dcblockerat(228.092318097);\n    \n    wet = wah_ctrl.wet_dry;\n    dry = 1 - wet;\n\n    Wah1 = (x : an.amp_follower_ud(0.01,0.1) : min(0.98) : max(0.03) : Inverted(1)): si.smooth(s);\n    \n    Wah2 = wah_ctrl.wah : max(0.03) :  si.smooth(s);\n    \n    sl = wah_ctrl.mode;\n\n    Wah3 = (os.oscs(freq) + 1) / 2 : min(1) : max(0.03) with {\n        freq = wah_ctrl.freq;\n    }; \n\n    Wah = select3(sl, Wah2, Wah1, Wah3);\n    \n    b0 = Wah*(Wah*pow(fs,2)*(fs*(1.25354929341128e-21*fs + 3.48240441721223e-17) + 5.13677938435808e-14) + fs*(fs*(fs*(-1.25190991353587e-21*fs - 3.48523283463119e-17) - 5.2316993137229e-14) - 1.41321715016552e-12)) + fs*(fs*(fs*(-7.56083860086155e-21*fs - 2.50316072026991e-16) - 3.73895528534631e-13) - 2.00079255014785e-12);\n\n    b1 = Wah*(Wah*pow(fs,3)*(-5.01419717364513e-21*fs - 6.96480883442447e-17) + fs*(pow(fs,2)*(5.00763965414349e-21*fs + 6.97046566926238e-17) - 2.82643430033104e-12)) + fs*(pow(fs,2)*(3.02433544034462e-20*fs + 5.00632144053981e-16) - 4.0015851002957e-12);\n\n    b2 = Wah*(Wah*pow(fs,2)*(7.52129576046769e-21*pow(fs,2) - 1.02735587687162e-13) + pow(fs,2)*(-7.51145948121523e-21*pow(fs,2) + 1.04633986274458e-13)) + pow(fs,2)*(-4.53650316051693e-20*pow(fs,2) + 7.47791057069262e-13);\n\n    b3 = Wah*(Wah*pow(fs,3)*(-5.01419717364513e-21*fs + 6.96480883442447e-17) + fs*(pow(fs,2)*(5.00763965414349e-21*fs - 6.97046566926238e-17) + 2.82643430033104e-12)) + fs*(pow(fs,2)*(3.02433544034462e-20*fs - 5.00632144053981e-16) + 4.0015851002957e-12);\n\n    b4 = Wah*(Wah*pow(fs,2)*(fs*(1.25354929341128e-21*fs - 3.48240441721223e-17) + 5.13677938435808e-14) + fs*(fs*(fs*(-1.25190991353587e-21*fs + 3.48523283463119e-17) - 5.2316993137229e-14) + 1.41321715016552e-12)) + fs*(fs*(fs*(-7.56083860086155e-21*fs + 2.50316072026991e-16) - 3.73895528534631e-13) + 2.00079255014785e-12);\n\n    a0 = Wah*(Wah*pow(fs,2)*(fs*(-4.43653850017937e-20*fs - 6.36752117258257e-18) - 6.90511452608771e-14) + fs*(fs*(fs*(2.96437047678913e-19*fs + 2.2065454697261e-17) + 5.22620199701727e-14) + 1.9616802630931e-12)) + fs*(fs*(fs*(5.00642970027606e-20*fs + 3.44255097160751e-17) + 6.23836917215568e-13) + 1.48605150842693e-11) + 5.57295529287812e-11;\n\n    a1 = Wah*(Wah*pow(fs,3)*(1.77461540007175e-19*fs + 1.27350423451651e-17) + fs*(pow(fs,2)*(-1.18574819071565e-18*fs - 4.4130909394522e-17) + 3.9233605261862e-12)) + fs*(pow(fs,2)*(-2.00257188011043e-19*fs - 6.88510194321502e-17) + 2.97210301685387e-11) + 2.22918211715125e-10;\n\n    a2 = Wah*(Wah*pow(fs,2)*(-2.66192310010762e-19*pow(fs,2) + 1.38102290521754e-13) + pow(fs,2)*(1.77862228607348e-18*pow(fs,2) - 1.04524039940345e-13)) + pow(fs,2)*(3.00385782016564e-19*pow(fs,2) - 1.24767383443114e-12) + 3.34377317572687e-10;\n\n    a3 = Wah*(Wah*pow(fs,3)*(1.77461540007175e-19*fs - 1.27350423451651e-17) + fs*(pow(fs,2)*(-1.18574819071565e-18*fs + 4.4130909394522e-17) - 3.9233605261862e-12)) + fs*(pow(fs,2)*(-2.00257188011043e-19*fs + 6.88510194321502e-17) - 2.97210301685387e-11) + 2.22918211715125e-10;\n\n    a4 = Wah*(Wah*pow(fs,2)*(fs*(-4.43653850017937e-20*fs + 6.36752117258257e-18) - 6.90511452608771e-14) + fs*(fs*(fs*(2.96437047678913e-19*fs - 2.2065454697261e-17) + 5.22620199701727e-14) - 1.9616802630931e-12)) + fs*(fs*(fs*(5.00642970027606e-20*fs - 3.44255097160751e-17) + 6.23836917215568e-13) - 1.48605150842693e-11) + 5.57295529287812e-11;\n};"
 },
 {
  "id": "lib-wah4",
  "name": "Wah4 Moog",
  "category": "guitar",
  "family": "filter",
  "familyName": "Filter",
  "icon": "tabler:filter",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "MIT",
  "shortDesc": "JOS 4th-order wah built from a Moog VCF - fat, vowel-like pedal wah",
  "description": "JOS 4th-order wah built from a Moog VCF - fat, vowel-like pedal wah",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Pedal",
    "min": 100,
    "max": 2000,
    "default": 800,
    "step": 1,
    "unit": "Hz",
    "path": "/Wah4_Moog/Pedal"
   },
   {
    "label": "Level",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Wah4_Moog/Level"
   }
  ],
  "faustCode": "declare name \"Wah4 Moog\";\ndeclare description \"JOS 4th-order wah built from a Moog VCF - fat, vowel-like pedal wah\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"MIT\";\ndeclare source \"grame-cncm/faustlibraries/vaeffects.lib ve.wah4\";\ndeclare category \"guitar\";\ndeclare family \"filter\";\nimport(\"stdfaust.lib\");\n\nfr    = hslider(\"[0] Pedal[unit:Hz][scale:log]\", 800, 100, 2000, 1);\nlevel = hslider(\"[1] Level[unit:dB]\", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;\nprocess = fi.dcblocker : ve.wah4(fr) : *(level);"
 },
 {
  "id": "ex-chorus-8voice",
  "name": "8-Voice Chorus",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "Faust examples",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "JOS multi-voice chorus from the SHARC Audio Module example: 8 delay taps with per-voice LFO rates and phase-spread deviation, summed to mono",
  "description": "JOS multi-voice chorus from the SHARC Audio Module example: 8 delay taps with per-voice LFO rates and phase-spread deviation, summed to mono",
  "author": "Julius O. Smith III, GRAME",
  "flags": "",
  "params": [
   {
    "label": "Delay",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/8-Voice_Chorus/Delay"
   },
   {
    "label": "Rate",
    "min": 0.01,
    "max": 7,
    "default": 0.5,
    "step": 0.01,
    "unit": "Hz",
    "path": "/8-Voice_Chorus/Rate"
   },
   {
    "label": "Depth",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.001,
    "unit": "",
    "path": "/8-Voice_Chorus/Depth"
   },
   {
    "label": "Deviation",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.001,
    "unit": "",
    "path": "/8-Voice_Chorus/Deviation"
   }
  ],
  "faustCode": "declare name \"8-Voice Chorus\";\ndeclare description \"JOS multi-voice chorus from the SHARC Audio Module example: 8 delay taps with per-voice LFO rates and phase-spread deviation, summed to mono\";\ndeclare author \"Julius O. Smith III, GRAME\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faust/examples/SAM/effects/chorus.dsp\";\ndeclare category \"guitar\";\ndeclare family \"mod\";\nimport(\"stdfaust.lib\");\n\nvoices = 8;\ndmax = 8192;\ncurdel = dmax*hslider(\"[0] Delay\", 0.5, 0, 1, 0.01) : si.smooth(0.999);\nrate   = hslider(\"[1] Rate[unit:Hz]\", 0.5, 0.01, 7, 0.01) : si.smooth(ba.tau2pole(0.15661/6.91));\ndepth  = hslider(\"[2] Depth\", 0.5, 0, 1, 0.001) : si.smooth(ba.tau2pole(0.15661/6.91));\nsigma  = 0.5*curdel/voices*hslider(\"[3] Deviation\", 0.5, 0, 1, 0.001) : si.smooth(0.999);\nchorus_mono(dmax, curdel, rate, sigma, do2, voices) = _ <: (*(1-do2) <: _, _), (*(do2) <: par(i, voices, voice(i)) :> _, _) : ro.interleave(2, 2) : +, +\n    with {\n        angle(i) = 2*ma.PI*(i/2)/voices+(i%2)*ma.PI/2;\n        voice(i) = de.fdelay(dmax, min(dmax, del(i)))*cos(angle(i));\n        del(i) = curdel*(i+1)/voices+dev(i);\n        rates(i) = rate/float(i+1);\n        dev(i) = sigma*os.oscp(rates(i), i*2*ma.PI/voices);\n    };\nprocess = chorus_mono(dmax, curdel, rate, sigma, depth, voices) :> *(0.5);"
 },
 {
  "id": "gx-chorus",
  "name": "Chorus",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Albert Graef's chorus with level, rate, delay and depth; summed to mono here.",
  "description": "Table-LFO modulated delay-line chorus with Level, Freq, Delay and Depth; originally stereo with a per-channel phase offset, wrapped to mono for the pedal. A classic clean digital chorus.",
  "author": "Albert Graef",
  "flags": "-double",
  "params": [
   {
    "label": "level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/chorus/level"
   },
   {
    "label": "freq",
    "min": 0,
    "max": 10,
    "default": 3,
    "step": 0.01,
    "unit": "",
    "path": "/chorus/freq"
   },
   {
    "label": "de.delay",
    "min": 0,
    "max": 0.2,
    "default": 0.02,
    "step": 0.01,
    "unit": "",
    "path": "/chorus/de.delay"
   },
   {
    "label": "depth",
    "min": 0,
    "max": 1,
    "default": 0.02,
    "step": 0.01,
    "unit": "",
    "path": "/chorus/depth"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/chorus.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Chorus\";\ndeclare category \"Modulation\";\n\n/* Stereo chorus. */\n\n// declare name \"chorus -- stereo chorus effect\";\ndeclare author \"Albert Graef\";\ndeclare version \"1.0\";\n\nimport(\"stdfaust.lib\");\n\nlevel\t= hslider(\"level\", 0.5, 0, 1, 0.01) : si.smooth(0.993);\nfreq\t= hslider(\"freq\", 3, 0, 10, 0.01) : si.smooth(0.993);\ndtime\t= hslider(\"de.delay\", 0.02, 0, 0.2, 0.01) : si.smooth(0.993);\ndepth\t= hslider(\"depth\", 0.02, 0, 1, 0.01) : si.smooth(0.993);\n\ntblosc(n,f,freq,mod)\t= (1-d)*rdtable(n,wform,i&(n-1)) +\n\t\t\t  d*rdtable(n,wform,(i+1)&(n-1))\nwith {\n\twform \t= ba.time*(2.0*ma.PI)/n : f;\n\tphase\t\t= freq/ma.SR : (+ : ma.decimal) ~ _;\n\tmodphase\t= ma.decimal(phase+mod/(2*ma.PI))*n;\n\ti\t\t= int(floor(modphase));\n\td\t\t= ma.decimal(modphase);\n};\n\ninterp = ma.SR/1000.0;\n\nchorus(dtime,freq,depth,phase,x)\n\t\t\t= x+level*de.sdelay(1<<16, interp, t, x)\nwith {\n\tt\t\t= ma.SR*dtime/2*(1+depth*tblosc(1<<16, sin, freq, phase));\n};\n\nprocess_wide\t\t\t= vgroup(\"chorus\", (left, right))\nwith {\n\tleft\t\t= chorus(dtime,freq,depth,0);\n\tright\t\t= chorus(dtime,freq,depth,ma.PI/2);\n};\n\n// mono wrapper added by the Chameleon port (pedal is mono in / mono out)\nprocess = _ <: process_wide :> *(0.5);"
 },
 {
  "id": "gx-chorus-mono",
  "name": "Chorus Mono",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Simplified mono chorus with level, rate and wet/dry.",
  "description": "Mono version of the Graef chorus with fixed delay and depth, exposing only Level, Freq and wet/dry. A quick, set-and-forget chorus.",
  "author": "Albert Graef",
  "flags": "-double",
  "params": [
   {
    "label": "level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Chorus_Mono/level"
   },
   {
    "label": "freq",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.01,
    "unit": "",
    "path": "/Chorus_Mono/freq"
   },
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Chorus_Mono/wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/chorus_mono.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Chorus Mono\";\ndeclare category \"Modulation\";\n\ndeclare author \"Albert Graef\";\ndeclare version \"1.0\";\n\nimport(\"stdfaust.lib\");\n\nlevel\t= hslider(\"level\", 0.5, 0, 1, 0.01);\nfreq\t= hslider(\"freq\", 2, 0, 10, 0.01);\ndtime\t= 0.02 ;//hslider(\"de.delay\", 0.02, 0, 0.2, 0.01);\n\ndepth\t= 0.02 ;//hslider(\"depth\", 0.02, 0, 1, 0.01);\nwet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\ndry = 1 - wet;\n\nprocess\t\t\t= _<:*(dry),(*(wet): component(\"gx-chorus.dsp\").chorus(dtime,freq,depth,0)):>_;"
 },
 {
  "id": "mag-constant-detune-chorus",
  "name": "Constant Detune Chorus",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "magnetophon",
  "license": "GPL-3.0",
  "shortDesc": "Bart Brouns' port of Scott Nordlund's chorus: three delay taps with Poisson-timed random slow+fast LFOs whose warped triangles keep detune constant and symmetric in cents",
  "description": "Bart Brouns' port of Scott Nordlund's chorus: three delay taps with Poisson-timed random slow+fast LFOs whose warped triangles keep detune constant and symmetric in cents",
  "author": "Bart Brouns (port of a Pure Data patch by Scott Nordlund, 2011)",
  "flags": "",
  "params": [
   {
    "label": "Slow Rate",
    "min": 0,
    "max": 5,
    "default": 0.57,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Constant_Detune_Chorus/Slow_Rate"
   },
   {
    "label": "Slow Depth",
    "min": 0,
    "max": 5,
    "default": 4,
    "step": 0.01,
    "unit": "",
    "path": "/Constant_Detune_Chorus/Slow_Depth"
   },
   {
    "label": "Fast Rate",
    "min": 0,
    "max": 10,
    "default": 1,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Constant_Detune_Chorus/Fast_Rate"
   },
   {
    "label": "Fast Depth",
    "min": 0,
    "max": 10,
    "default": 4,
    "step": 0.01,
    "unit": "",
    "path": "/Constant_Detune_Chorus/Fast_Depth"
   },
   {
    "label": "Feedback",
    "min": -1,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Constant_Detune_Chorus/Feedback"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/Constant_Detune_Chorus/Mix"
   }
  ],
  "faustCode": "declare name \"Constant Detune Chorus\";\ndeclare description \"Bart Brouns' port of Scott Nordlund's chorus: three delay taps with Poisson-timed random slow+fast LFOs whose warped triangles keep detune constant and symmetric in cents\";\ndeclare author \"Bart Brouns (port of a Pure Data patch by Scott Nordlund, 2011)\";\ndeclare license \"GPL-3.0\";\ndeclare source \"magnetophon/constant-detune-chorus ConstantDetuneChorus.dsp\";\ndeclare category \"guitar\";\ndeclare family \"mod\";\nimport(\"stdfaust.lib\");\nmix = hslider(\"[5] Mix\", 0.6, 0, 1, 0.01) : si.smoo;\nline (value, time) = state~(_,_):!,_\n\twith {\n\t\tstate (t, c) = nt, ba.if (nt <= 0, value, c+(value - c) / nt)\n\t\twith {\n\t\t\tnt = ba.if( value != value', samples, t-1);\n\t\t\tsamples = time*ma.SR/1000.0;\n\t\t};\n\t};\nnoiseMax\t= 13;\npoisStart\t= noiseMax/2;\nstart = ba.time<1;\nms\t\t= ma.SR/1000;\npoisMin\t\t= 667;\npoisMax \t= 4444;\ndelMax\t\t= 4096;\nchorusGroup(x) = x;\nslowFreq\t= chorusGroup(hslider(\"[0] Slow Rate[unit:Hz]\",\t0.57, 0, 5, 0.01):si.smooth(0.999));\nslowDepth\t= chorusGroup(hslider(\"[1] Slow Depth\",\t4, 0, 5, 0.01):pow(2):si.smooth(0.999));\nfastFreq\t= chorusGroup(hslider(\"[2] Fast Rate[unit:Hz]\",\t1, 0, 10, 0.01):si.smooth(0.999));\nfastDepth\t= chorusGroup(hslider(\"[3] Fast Depth\",\t4, 0, 10, 0.01):pow(2):si.smooth(0.999));\nfeedback\t= chorusGroup(hslider(\"[4] Feedback\",\t0, -1, 1, 0.01)*0.8:si.smooth(0.999));\nSH(trig,x) = (*(1 - trig) + x * trig) ~_;\nchangePulse= _ <: _, mem: - : abs:_>(0);\nnoiseNr(nr) =(no.noises(noiseMax,nr)/2)+0.5;\npois(nr) = ((SH((_|start),noiseNr(nr+1)):log:*(-1000):*(ms)) ~ (silentFor<:_,_)) :max(poisMin*ms):min(poisMax*ms):_/ms\nwith {\nsilentFor(time) =  (ba.countup((time:max(poisMin*ms):min(poisMax*ms)), ((time:changePulse)*_))==(time:max(poisMin*ms):min(poisMax*ms)))~_:changePulse;\n};\nsmin = slowFreq;\nsmax = slowFreq*1.25;\nfreq(Fmin,Fmax,nr) = ((SH((pois(nr):changePulse),noiseNr(nr))  * ((Fmax:log)-(Fmin:log))) + (Fmin:log)):exp ;\nslowD(nr) = (slowDepth:expr1:expr2) / freq(Fmin,Fmax,nr)\n  with {\n  expr1 = pow(2, _/1200);\n  expr2 = _<:(2000*(_-1)/(_+1));\n  };\nslowTotal(nr) = ((os.lf_sawpos(line(freq(smin,smax,nr), pois(nr)))-0.5):abs) * (line((slowD(nr)),pois(nr)));\nFmin = fastFreq;\nFmax = fastFreq*1.75;\nfastD(nr) = (fastDepth:expr1:expr2) / freq(Fmin,Fmax,nr)\n  with {\n  expr1 = pow(2, _/1200);\n  expr2 = _<:(318.309886*(_-1)/(_+1));\n  };\nfastTotal(nr) = ((os.lf_sawpos(line(freq(Fmin,Fmax,nr), pois(nr))):sin:_+1) * (line((fastD(nr)),pois(nr))) );\ndelayed(nr,add) = de.sdelay(delMax,1024,((slowTotal(nr)+fastTotal(nr+1)+add)*ms));\nmonoChorus(nr) = (_,_:+:_<:delayed(0+nr,3),delayed(2+nr,7),delayed(4+nr,10):>_)~( (_*feedback) : fi.dcblockerat(200)*2: ma.tanh*0.25) ;\nprocess = _ <: *(1-mix), (monoChorus(0) : *(0.5) : *(mix)) :> _;"
 },
 {
  "id": "gx-flanger",
  "name": "Flanger",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Faust library stereo flanger (delay, offset, rate, depth, feedback) summed to mono.",
  "description": "Wrapper around the Faust library flanger with flange delay, delay offset, LFO rate, depth, feedback gain and level; originally stereo with sine/cosine LFOs, wrapped to mono for the pedal. A jet-like swept comb filter.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "flange de.delay",
    "min": 0,
    "max": 20,
    "default": 10,
    "step": 0.01,
    "unit": "ms",
    "path": "/Flanger/flange_de.delay"
   },
   {
    "label": "flange de.delay offset",
    "min": 0,
    "max": 20,
    "default": 1,
    "step": 0.01,
    "unit": "ms",
    "path": "/Flanger/flange_de.delay_offset"
   },
   {
    "label": "LFO freq",
    "min": 0,
    "max": 5,
    "default": 0.2,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Flanger/LFO_freq"
   },
   {
    "label": "depth",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Flanger/depth"
   },
   {
    "label": "feedback gain",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Flanger/feedback_gain"
   },
   {
    "label": "level",
    "min": -60,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Flanger/level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/flanger.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \t\t\"flanger\";\ndeclare name            \"Flanger\";\ndeclare category        \"Modulation\";\ndeclare license \t\"BSD\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nflangerstereogx = *(level),*(level) : flangerstereoN(dmax,curdel1,curdel2,depth,fb,invert) // change to pf.flanger_stereo for faust >= 0.9.27\nwith {\n  lfol = os.oscrs; // sine for left channel\n  lfor = os.oscrc; // cosine for right channel\n  dmax = 2048;\n  dflange = 0.001 * ma.SR * hslider(\"flange de.delay [unit:ms]\", 10, 0, 20, 0.01);\n  odflange = 0.001 * ma.SR * hslider(\"flange de.delay offset [unit:ms]\", 1, 0, 20, 0.01);\n  freq\t = hslider(\"LFO freq [unit:Hz]\", 0.2, 0, 5, 0.01);\n  depth\t = hslider(\"depth\", 1, 0, 1, 0.01);\n  fb\t = hslider(\"feedback gain\", 0, 0, 1, 0.01);\n  invert   = checkbox(\"invert[enum:linear|invert]\");\n  level\t = hslider(\"level [unit:dB]\", 0, -60, 10, 0.1) : ba.db2linear;\n  curdel1 = odflange+dflange*(1 + lfol(freq))/2; \n  curdel2 = odflange+dflange*(1 + lfor(freq))/2; \n};\n\nprocess_wide = flangerstereogx;\n\n// mono wrapper added by the Chameleon port (pedal is mono in / mono out)\nprocess = _ <: process_wide :> *(0.5);"
 },
 {
  "id": "gx-flanger-gx",
  "name": "Flanger GX",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Guitarix's hand-written mono flanger with width in ms, depth, rate, feedback, wet and mix.",
  "description": "A hand-written mono flanger with Width (ms), Depth, Freq, Feedback, Wet and Mix. Same code as the gx_flanger entry.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "width",
    "min": 0,
    "max": 10,
    "default": 5,
    "step": 0.01,
    "unit": "",
    "path": "/Flanger_GX/width"
   },
   {
    "label": "depth",
    "min": 0,
    "max": 5,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Flanger_GX/depth"
   },
   {
    "label": "freq",
    "min": 0.05,
    "max": 10,
    "default": 0.2,
    "step": 1.06,
    "unit": "Hz",
    "path": "/Flanger_GX/freq"
   },
   {
    "label": "feedback",
    "min": -0.99,
    "max": 0.99,
    "default": -0.707,
    "step": 0.01,
    "unit": "",
    "path": "/Flanger_GX/feedback"
   },
   {
    "label": "wet",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Flanger_GX/wet"
   },
   {
    "label": "mix",
    "min": -1,
    "max": 1,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Flanger_GX/mix"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/flanger_gx.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \t\t\"flanger_mono_gx\";\ndeclare name            \"Flanger GX\";\ndeclare category        \"Modulation\";\n\nimport(\"stdfaust.lib\");\n\nh_flanger(dmax, curdel, fb, wet) = _ <: _, (dly : (+:dly)~*(fb)) : mix with {\n    dly = de.fdelay(dmax/2, curdel/2);\n    mix = *(2-wet), _*(wet) : +;\n};\n\nflanger(dmax, curdel, fb, wet) = _ <: _, (+:dly)~*(fb) : mix with {\n    dly = de.fdelay(dmax, curdel);\n    mix = *(2-wet), _*(wet) : +;\n};\n\nprocess = h_flanger(dmax, curdel,  fb, wet1) :\n          flanger(  dmax, curdel, -fb, wet2) :\n          *(0.25) with {\n   // ma.SR = component(\"math.lib\").ma.SR;\n    dflange = 0.001 * ma.SR *  hslider(\"width[name:Width]\", 5.0, 0, 10, 0.01);\n    odflange = 0.001 * ma.SR *  hslider(\"depth[name:Depth]\", 0.5, 0, 5, 0.01);\n    dmax = 2048; // > max(dflange+odflange) at rate 96000\n    freq = hslider(\"freq[log][name:Speed][unit:Hz]\", 0.2, 0.05, 10, 1.06);\n    fb = hslider(\"feedback[name:Feedback]\", -0.707, -0.99, 0.99, 0.01) * (2+abs(mix))/3;\n    lfo = os.oscrs;\n    curdel = odflange+dflange*(1+lfo(freq))/2;\n    //curdel = hslider(\"de.delay\", 20, 0, 400, 0.1);\n    wet = hslider(\"wet[name:Wet]\", 100, 0, 100, 1)/100;\n    mix = hslider(\"mix[name:Mix]\", 0, -1, 1, 0.1);\n    wet1 = wet*min(1,1+mix);\n    wet2 = wet*min(1,1-mix);\n};"
 },
 {
  "id": "gx-flanger-mono",
  "name": "Flanger Mono",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Simple mono flanger with rate, level and wet/dry.",
  "description": "Mono flanger built on the Faust library flanger with fixed delay settings, exposing Freq, Level and wet/dry. A quick one-knob-style flange.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "freq",
    "min": 0,
    "max": 5,
    "default": 0.2,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Flanger_Mono/freq"
   },
   {
    "label": "level",
    "min": -60,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Flanger_Mono/level"
   },
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Flanger_Mono/wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/flanger_mono.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \t\t\"flanger_mono\";\ndeclare name            \"Flanger Mono\";\ndeclare category        \"Modulation\";\ndeclare license \t\"BSD\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\n\nflangermono(curdel)\n  = _<: _, (-:de.fdelay(2048,curdel)) ~ *(0.5) : _, \n  *(-1) : + : *(0.5);\n  \n\nflangermonogx = *(level):flangermono(curdel)\nwith {\n\t  lfol = os.oscrs; \n\t  dflange = 0.001 * ma.SR *  10.0;\n\t  odflange = 0.001 * ma.SR *  1.0;\n\t  freq\t = hslider(\"freq [unit:Hz]\", 0.2, 0, 5, 0.01);\n\t  level\t = hslider(\"level [unit:dB]\", 0, -60, 10, 0.1) : ba.db2linear;\n\t  curdel = odflange+dflange*(1 + lfol(freq))/2; \n  };\n  \nwet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\ndry = 1 - wet;\n  \nprocess =  _<:*(dry),(*(wet): flangermonogx ):>_;"
 },
 {
  "id": "lib-flanger",
  "name": "Flanger Mono",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "JOS flanger_mono: LFO-modulated short delay with bipolar feedback and invert",
  "description": "JOS flanger_mono: LFO-modulated short delay with bipolar feedback and invert",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Speed",
    "min": 0,
    "max": 10,
    "default": 0.5,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Flanger_Mono/Speed"
   },
   {
    "label": "Depth",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.001,
    "unit": "",
    "path": "/Flanger_Mono/Depth"
   },
   {
    "label": "Feedback",
    "min": -0.95,
    "max": 0.95,
    "default": 0.3,
    "step": 0.001,
    "unit": "",
    "path": "/Flanger_Mono/Feedback"
   },
   {
    "label": "Delay",
    "min": 0.5,
    "max": 20,
    "default": 6,
    "step": 0.01,
    "unit": "ms",
    "path": "/Flanger_Mono/Delay"
   }
  ],
  "faustCode": "declare name \"Flanger Mono\";\ndeclare description \"JOS flanger_mono: LFO-modulated short delay with bipolar feedback and invert\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faustlibraries/phaflangers.lib pf.flanger_mono\";\ndeclare category \"guitar\";\ndeclare family \"mod\";\nimport(\"stdfaust.lib\");\n\nspeed = hslider(\"[0] Speed[unit:Hz]\", 0.5, 0, 10, 0.01) : si.smoo;\ndepth = hslider(\"[1] Depth\", 1, 0, 1, 0.001) : si.smoo;\nfb    = hslider(\"[2] Feedback\", 0.3, -0.95, 0.95, 0.001) : si.smoo;\ndmax  = hslider(\"[3] Delay[unit:ms]\", 6, 0.5, 20, 0.01) : si.smoo;\ninv   = checkbox(\"[4] Invert\");\ncurdel = dmax * ma.SR/1000 * (1 + os.oscrs(speed)) * 0.5;\nprocess = pf.flanger_mono(2048, curdel, depth, fb, inv) : *(0.7);"
 },
 {
  "id": "gx-mbchor",
  "name": "Multi-Band Chorus",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Five-band chorus with independent level, rate, delay and depth per band.",
  "description": "Splits the signal at four adjustable crossovers and applies a separate chorus (Level, Freq, Delay, Depth) to each band. Lets the low end stay steady while the highs shimmer.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "crossover b1 b2",
    "min": 20,
    "max": 20000,
    "default": 80,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Chorus/crossover_b1_b2"
   },
   {
    "label": "crossover b2 b3",
    "min": 20,
    "max": 20000,
    "default": 210,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Chorus/crossover_b2_b3"
   },
   {
    "label": "crossover b3 b4",
    "min": 20,
    "max": 20000,
    "default": 1700,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Chorus/crossover_b3_b4"
   },
   {
    "label": "crossover b4 b5",
    "min": 20,
    "max": 20000,
    "default": 5000,
    "step": 1.08,
    "unit": "",
    "path": "/Multi_Band_Chorus/crossover_b4_b5"
   },
   {
    "label": "level1",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/level1"
   },
   {
    "label": "freq1",
    "min": 24,
    "max": 360,
    "default": 30,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Chorus/freq1"
   },
   {
    "label": "delay1",
    "min": 0,
    "max": 0.2,
    "default": 0.02,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/delay1"
   },
   {
    "label": "depth1",
    "min": 0.01,
    "max": 1,
    "default": 0.02,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/depth1"
   },
   {
    "label": "level2",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/level2"
   },
   {
    "label": "freq2",
    "min": 24,
    "max": 360,
    "default": 60,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Chorus/freq2"
   },
   {
    "label": "delay2",
    "min": 0,
    "max": 0.2,
    "default": 0.04,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/delay2"
   },
   {
    "label": "depth2",
    "min": 0.01,
    "max": 1,
    "default": 0.04,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/depth2"
   },
   {
    "label": "level3",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/level3"
   },
   {
    "label": "freq3",
    "min": 24,
    "max": 360,
    "default": 90,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Chorus/freq3"
   },
   {
    "label": "delay3",
    "min": 0,
    "max": 0.2,
    "default": 0.06,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/delay3"
   },
   {
    "label": "depth3",
    "min": 0.01,
    "max": 1,
    "default": 0.06,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/depth3"
   },
   {
    "label": "level4",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/level4"
   },
   {
    "label": "freq4",
    "min": 24,
    "max": 360,
    "default": 120,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Chorus/freq4"
   },
   {
    "label": "delay4",
    "min": 0,
    "max": 0.2,
    "default": 0.08,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/delay4"
   },
   {
    "label": "depth4",
    "min": 0.01,
    "max": 1,
    "default": 0.08,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/depth4"
   },
   {
    "label": "level5",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/level5"
   },
   {
    "label": "freq5",
    "min": 24,
    "max": 360,
    "default": 150,
    "step": 1,
    "unit": "",
    "path": "/Multi_Band_Chorus/freq5"
   },
   {
    "label": "delay5",
    "min": 0,
    "max": 0.2,
    "default": 0.1,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/delay5"
   },
   {
    "label": "depth5",
    "min": 0.01,
    "max": 1,
    "default": 0.1,
    "step": 0.01,
    "unit": "",
    "path": "/Multi_Band_Chorus/depth5"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/mbchor.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"mbchor\";\ndeclare name \"Multi Band Chorus\";\ndeclare shortname \"MB Chorus\";\ndeclare category \"Modulation\";\ndeclare description \"Multi Band Chorus\";\n\nimport(\"stdfaust.lib\");\nimport(\"reducemaps.lib\");\n\nhifr1      =hslider(\"crossover_b1_b2 [log][name:Crossover B1-B2 (hz)][tooltip: Crossover fi.bandpass frequency]\" ,80 , 20, 20000, 1.08);\nhifr2      =hslider(\"crossover_b2_b3 [log][name:Crossover B2-B3 (hz)][tooltip: Crossover fi.bandpass frequency]\",210,20,20000,1.08);\nhifr3      =hslider(\"crossover_b3_b4 [log][name:Crossover B3-B4 (hz)][tooltip: Crossover fi.bandpass frequency]\",1700,20,20000,1.08);\nhifr4      =hslider(\"crossover_b4_b5 [log][name:Crossover B4-B5 (hz)][tooltip: Crossover fi.bandpass frequency]\",5000,20,20000,1.08);\n\ngeq = fi.filterbank(3, (hifr1,hifr2,hifr3,hifr4));\n\nl1\t= hslider(\"level1\", 0.5, 0, 1, 0.01);\nf1\t= hslider(\"freq1[tooltip:Beats per Minute]\",30,24,360,1)/60;\nd1\t= hslider(\"delay1\", 0.02, 0, 0.2, 0.01): si.smooth(0.999);\nde1\t= hslider(\"depth1\", 0.02, 0.01, 1, 0.01)/10;\nl2\t= hslider(\"level2\", 0.5, 0, 1, 0.01);\nf2\t= hslider(\"freq2[tooltip:Beats per Minute]\",60,24,360,1)/60;\nd2\t= hslider(\"delay2\", 0.04, 0, 0.2, 0.01): si.smooth(0.999);\nde2\t= hslider(\"depth2\", 0.04, 0.01, 1, 0.01)/10;\nl3\t= hslider(\"level3\", 0.5, 0, 1, 0.01);\nf3\t= hslider(\"freq3[tooltip:Beats per Minute]\",90,24,360,1)/60;\nd3\t= hslider(\"delay3\", 0.06, 0, 0.2, 0.01): si.smooth(0.999);\nde3\t= hslider(\"depth3\", 0.06, 0.01, 1, 0.01)/10;\nl4\t= hslider(\"level4\", 0.5, 0, 1, 0.01);\nf4\t= hslider(\"freq4[tooltip:Beats per Minute]\",120,24,360,1)/60;\nd4\t= hslider(\"delay4\", 0.08, 0, 0.2, 0.01): si.smooth(0.999);\nde4\t= hslider(\"depth4\", 0.08, 0.01, 1, 0.01)/10;\nl5\t= hslider(\"level5\", 0.5, 0, 1, 0.01);\nf5\t= hslider(\"freq5[tooltip:Beats per Minute]\",150,24,360,1)/60;\nd5\t= hslider(\"delay5\", 0.10, 0, 0.2, 0.01): si.smooth(0.999);\nde5\t= hslider(\"depth5\", 0.10, 0.01, 1, 0.01)/10;\n\ntblosc(n,f,freq,mod)\t= (1-d)*rdtable(n,wform,i&(n-1)) +\n\t\t\t  d*rdtable(n,wform,(i+1)&(n-1))\nwith {\n\twform \t= ba.time*(2.0*ma.PI)/n : f;\n\tphase\t\t= freq/ma.SR : (+ : ma.decimal) ~ _;\n\tmodphase\t= ma.decimal(phase+mod/(2*ma.PI))*n;\n\ti\t\t= int(floor(modphase));\n\td\t\t= ma.decimal(modphase);\n};\n\nchor(dtime,freq,depth,lev)  = chorus(dtime,freq,depth,lev,0) : *(lev)\nwith {\nchorus(dtime,freq,depth,lev,phase,x)\n\t\t\t= x+lev*de.fdelay(1<<16, t, x)\nwith {\n\tt\t\t= ma.SR*dtime/2*(1+depth*tblosc(1<<16, sin, freq, phase));\n};\n};\n\nvmeter1(x)\t\t= attach(x, envelop(x) : vbargraph(\"v1[nomidi][log]\", -0, +1));\nvmeter2(x)\t\t= attach(x, envelop(x) : vbargraph(\"v2[nomidi][log]\", -0, +1));\nvmeter3(x)\t\t= attach(x, envelop(x) : vbargraph(\"v3[nomidi][log]\", -0, +1));\nvmeter4(x)\t\t= attach(x, envelop(x) : vbargraph(\"v4[nomidi][log]\", -0, +1));\nvmeter5(x)\t\t= attach(x, envelop(x) : vbargraph(\"v5[nomidi][log]\", -0, +1));\n\nenvelop         = abs : max ~ (1.0/ma.SR) :mean(4096) ; // : max(ba.db2linear(-70)) : ba.linear2db;\n\nprocess    = _<:(geq:( dist5s , dist4s , dist3s, dist2s, dist1s)),_ :>_ with { \n    dist1s = chor(d1,f1,de1,l1) : vmeter1;\n    dist2s = chor(d2,f2,de2,l2) : vmeter2;\n    dist3s = chor(d3,f3,de3,l3) : vmeter3;\n    dist4s = chor(d4,f4,de4,l4) : vmeter4;\n    dist5s = chor(d5,f5,de5,l5) : vmeter5;\n    \n};"
 },
 {
  "id": "lib-vibrato2",
  "name": "Phase Vibrato",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "JOS vibrato2: LFO-swept allpass sections give a pitch-wobble vibrato (Univibe-adjacent)",
  "description": "JOS vibrato2: LFO-swept allpass sections give a pitch-wobble vibrato (Univibe-adjacent)",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Speed",
    "min": 0.1,
    "max": 12,
    "default": 4,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Phase_Vibrato/Speed"
   },
   {
    "label": "Width",
    "min": 100,
    "max": 4000,
    "default": 1000,
    "step": 1,
    "unit": "Hz",
    "path": "/Phase_Vibrato/Width"
   },
   {
    "label": "Feedback",
    "min": -0.9,
    "max": 0.9,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Phase_Vibrato/Feedback"
   },
   {
    "label": "Min Freq",
    "min": 50,
    "max": 1000,
    "default": 200,
    "step": 1,
    "unit": "Hz",
    "path": "/Phase_Vibrato/Min_Freq"
   },
   {
    "label": "Max Freq",
    "min": 1000,
    "max": 8000,
    "default": 3000,
    "step": 1,
    "unit": "Hz",
    "path": "/Phase_Vibrato/Max_Freq"
   }
  ],
  "faustCode": "declare name \"Phase Vibrato\";\ndeclare description \"JOS vibrato2: LFO-swept allpass sections give a pitch-wobble vibrato (Univibe-adjacent)\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faustlibraries/phaflangers.lib pf.vibrato2_mono\";\ndeclare category \"guitar\";\ndeclare family \"mod\";\nimport(\"stdfaust.lib\");\n\nspeed = hslider(\"[0] Speed[unit:Hz]\", 4, 0.1, 12, 0.01) : si.smoo;\nwidth = hslider(\"[1] Width[unit:Hz]\", 1000, 100, 4000, 1) : si.smoo;\nfb    = hslider(\"[2] Feedback\", 0, -0.9, 0.9, 0.01) : si.smoo;\nfmin  = hslider(\"[3] Min Freq[unit:Hz][scale:log]\", 200, 50, 1000, 1);\nfmax  = hslider(\"[4] Max Freq[unit:Hz][scale:log]\", 3000, 1000, 8000, 1);\nprocess = pf.vibrato2_mono(4, 0, fb, width, fmin, 1.5, fmax, speed);"
 },
 {
  "id": "gx-phaser",
  "name": "Phaser",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "JOS phaser2: swept second-order allpass notches with speed, depth, feedback and spread.",
  "description": "Julius Smith's phaser2 from the Faust effect library: a chain of second-order resonant allpasses swept by an LFO, with Speed, Depth, Feedback, Notch Width, min/max notch frequency and notch spread; wrapped to mono. A rich, adjustable analog-style phaser.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Speed",
    "min": 0,
    "max": 10,
    "default": 0.5,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Phaser/Speed"
   },
   {
    "label": "depth",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Phaser/depth"
   },
   {
    "label": "feedback gain",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Phaser/feedback_gain"
   },
   {
    "label": "Notch width",
    "min": 10,
    "max": 5000,
    "default": 1000,
    "step": 1,
    "unit": "Hz",
    "path": "/Phaser/Notch_width"
   },
   {
    "label": "MinNotch1Freq",
    "min": 20,
    "max": 5000,
    "default": 100,
    "step": 1,
    "unit": "Hz",
    "path": "/Phaser/MinNotch1Freq"
   },
   {
    "label": "MaxNotch1Freq",
    "min": 20,
    "max": 10000,
    "default": 800,
    "step": 1,
    "unit": "Hz",
    "path": "/Phaser/MaxNotch1Freq"
   },
   {
    "label": "NotchFreq",
    "min": 1.1,
    "max": 4,
    "default": 1.5,
    "step": 0.01,
    "unit": "",
    "path": "/Phaser/NotchFreq"
   },
   {
    "label": "level",
    "min": -60,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Phaser/level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/phaser.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id   \"phaser\";\ndeclare name \"Phaser\";\ndeclare category \"Modulation\";\n\n//phaser taken from effect.lib \n// by Julius O. Smith III\n\nimport(\"stdfaust.lib\");\nimport(\"stdfaust.lib\");\n\nvibrato_mono(sections,phase01,fb,width,frqmin,fratio,frqmax,speed) = \n (+ : seq(i,sections,ap2p(R,th(i)))) ~ *(fb)\nwith {\n     // second-order resonant digital allpass given fi.pole radius and angle:\n     ap2p(R,th) = fi.tf2(a2,a1,1,a1,a2) with {\n       a2 = R^2;\n       a1 = -2*R*cos(th);\n     };\n     R = exp(-pi*width/ma.SR);\n     cososc = os.oscrc;\n     sinosc = os.oscrs;\n     osc = cososc(speed) * phase01 + sinosc(speed) * (1-phase01);\n     lfo = (1-osc)/2; // in [0,1]\n     pi = 4*atan(1);\n     thmin = 2*pi*frqmin/ma.SR;\n     thmax = 2*pi*frqmax/ma.SR;\n     th1 = thmin + (thmax-thmin)*lfo;\n     th(i) = (fratio^(i+1))*th1;\n};\n\nphaser_mono(Notches,phase01,width,frqmin,fratio,frqmax,speed,depth,fb,invert) = \n      _ <: *(g1) + g2mi*vibrato_mono(Notches,phase01,fb,width,frqmin,fratio,frqmax,speed)\nwith {               // depth=0 => direct-signal only\n     g1 = 1-depth/2; // depth=1 => phaser mode (equal sum of direct and allpass-pm.chain)\n     g2 = depth/2;   // depth=2 => vibrato mode (allpass-pm.chain signal only)\n     g2mi = select2(invert,g2,-g2); // inversion negates the allpass-pm.chain signal\n};\n  \nphaser_stereo(Notches,width,frqmin,fratio,frqmax,speed,depth,fb,invert)\n   = phaser_mono(Notches,0,width,frqmin,fratio,frqmax,speed,depth,fb,invert),\n     phaser_mono(Notches,1,width,frqmin,fratio,frqmax,speed,depth,fb,invert);\n\nphaser_stereogx = *(level),*(level) : phaser_stereo(Notches,width,frqmin,fratio,frqmax,freq,mdepth,fb,invert)\nwith {\n  Notches = 4;\n  freq  = hslider(\"Speed [unit:Hz] \", 0.5, 0, 10, 0.01);\n  \n  depth\t = hslider(\"depth\", 1, 0, 1, 0.01);\n  fb\t = hslider(\"feedback gain\", 0, 0, 1, 0.01);\n  width  = hslider(\"Notch width [unit:Hz]\", 1000, 10, 5000, 1);\n  vibr   = checkbox(\"VibratoMode[enum:direct | vibrato]\");\n  frqmin = hslider(\"MinNotch1Freq [unit:Hz] \", 100, 20, 5000, 1);\n  frqmax = hslider(\"MaxNotch1Freq [unit:Hz] \", 800, 20, 10000, 1) : max(frqmin);\n  fratio = hslider(\"NotchFreq\", 1.5, 1.1, 4, 0.01);\n  mdepth = select2(vibr,depth,2); \n  \n  invert   = checkbox(\"invert[enum:linear|invert]\");\n  level\t = hslider(\"level [unit:dB]\", 0, -60, 10, 0.1) : ba.db2linear;\n  \n};\n\nprocess_wide = phaser_stereogx;\n\n// mono wrapper added by the Chameleon port (pedal is mono in / mono out)\nprocess = _ <: process_wide :> *(0.5);"
 },
 {
  "id": "lib-phaser2-8",
  "name": "Phaser 8 Notch",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "JOS phaser2 with 8 swept notches, feedback and depth - thick, deep phase sweep",
  "description": "JOS phaser2 with 8 swept notches, feedback and depth - thick, deep phase sweep",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Speed",
    "min": 0,
    "max": 10,
    "default": 0.5,
    "step": 0.001,
    "unit": "Hz",
    "path": "/Phaser_8_Notch/Speed"
   },
   {
    "label": "Depth",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.001,
    "unit": "",
    "path": "/Phaser_8_Notch/Depth"
   },
   {
    "label": "Feedback",
    "min": -0.95,
    "max": 0.95,
    "default": 0.3,
    "step": 0.001,
    "unit": "",
    "path": "/Phaser_8_Notch/Feedback"
   },
   {
    "label": "Notch Width",
    "min": 10,
    "max": 5000,
    "default": 1000,
    "step": 1,
    "unit": "Hz",
    "path": "/Phaser_8_Notch/Notch_Width"
   },
   {
    "label": "Min Notch",
    "min": 20,
    "max": 5000,
    "default": 100,
    "step": 1,
    "unit": "Hz",
    "path": "/Phaser_8_Notch/Min_Notch"
   },
   {
    "label": "Max Notch",
    "min": 20,
    "max": 10000,
    "default": 800,
    "step": 1,
    "unit": "Hz",
    "path": "/Phaser_8_Notch/Max_Notch"
   },
   {
    "label": "Notch Ratio",
    "min": 1.1,
    "max": 4,
    "default": 1.5,
    "step": 0.01,
    "unit": "",
    "path": "/Phaser_8_Notch/Notch_Ratio"
   }
  ],
  "faustCode": "declare name \"Phaser 8 Notch\";\ndeclare description \"JOS phaser2 with 8 swept notches, feedback and depth - thick, deep phase sweep\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faustlibraries/phaflangers.lib pf.phaser2_mono\";\ndeclare category \"guitar\";\ndeclare family \"mod\";\nimport(\"stdfaust.lib\");\n\nspeed = hslider(\"[0] Speed[unit:Hz]\", 0.5, 0, 10, 0.001) : si.smoo;\ndepth = hslider(\"[1] Depth\", 1, 0, 1, 0.001) : si.smoo;\nfb    = hslider(\"[2] Feedback\", 0.3, -0.95, 0.95, 0.001) : si.smoo;\nwidth = hslider(\"[3] Notch Width[unit:Hz][scale:log]\", 1000, 10, 5000, 1) : si.smoo;\nfmin  = hslider(\"[4] Min Notch[unit:Hz][scale:log]\", 100, 20, 5000, 1);\nfmax  = hslider(\"[5] Max Notch[unit:Hz][scale:log]\", 800, 20, 10000, 1);\nratio = hslider(\"[6] Notch Ratio\", 1.5, 1.1, 4, 0.01);\nprocess = pf.phaser2_mono(8, 0, width, fmin, ratio, fmax, speed, depth, fb, 0);"
 },
 {
  "id": "gx-phaser-mono",
  "name": "Phaser Mono",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Simplified mono phaser with speed, level and wet/dry.",
  "description": "Mono phaser built on the JOS phaser2 with fixed depth, feedback and notch settings, exposing Speed, Level and wet/dry. A simple, classic phase sweep.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Speed",
    "min": 0,
    "max": 10,
    "default": 0.5,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Phaser_Mono/Speed"
   },
   {
    "label": "level",
    "min": -60,
    "max": 10,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/Phaser_Mono/level"
   },
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Phaser_Mono/wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/phaser_mono.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id   \"phaser_mono\";\ndeclare name \"Phaser Mono\";\ndeclare category \"Modulation\";\n\nimport(\"stdfaust.lib\");\n\nphaser_monogx = *(level): component(\"gx-phaser.dsp\").phaser_mono(Notches,0,width,frqmin,fratio,frqmax,freq,mdepth,fb,invert)\nwith {\n  Notches = 4;\n  freq  = hslider(\"Speed [unit:Hz] \", 0.5, 0, 10, 0.01);\n  \n  depth\t = 1 ;//hslider(\"depth\", 1, 0, 1, 0.01);\n  fb\t = 0.5 ;//hslider(\"feedback gain\", 0, 0, 1, 0.01);\n  width  = 1000 ;//hslider(\"Notch width [unit:Hz]\", 1000, 10, 5000, 1);\n  vibr   = 1 ;//checkbox(\"VibratoMode[enum:direct | vibrato]\");\n  frqmin = 100 ;//hslider(\"MinNotch1Freq [unit:Hz] \", 100, 20, 5000, 1);\n  frqmax = 800: max(frqmin) ;//hslider(\"MaxNotch1Freq [unit:Hz] \", 800, 20, 10000, 1) : max(frqmin);\n  fratio = 2.0 ;//hslider(\"NotchFreq\", 1.5, 1.1, 4, 0.01);\n  mdepth = 2 ;//select2(vibr,depth,2); \n  \n  invert   = 1 ;//checkbox(\"invert[enum:linear|invert]\");\n  level\t = hslider(\"level [unit:dB]\", 0, -60, 10, 0.1) : ba.db2linear;\n  \n};\n\nwet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\ndry = 1 - wet;\n\nprocess =  _<:*(dry),(*(wet): phaser_monogx ):>_;"
 },
 {
  "id": "lib-ring-mod",
  "name": "Ring Modulator",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Sine-carrier ring modulation with carrier blend and lowpass - bells, clangs and robot tones",
  "description": "Sine-carrier ring modulation with carrier blend and lowpass - bells, clangs and robot tones",
  "author": "GRAME (os.osc)",
  "flags": "",
  "params": [
   {
    "label": "Carrier",
    "min": 20,
    "max": 4000,
    "default": 220,
    "step": 0.1,
    "unit": "Hz",
    "path": "/Ring_Modulator/Carrier"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/Ring_Modulator/Mix"
   },
   {
    "label": "Tone",
    "min": 800,
    "max": 16000,
    "default": 6000,
    "step": 1,
    "unit": "Hz",
    "path": "/Ring_Modulator/Tone"
   }
  ],
  "faustCode": "declare name \"Ring Modulator\";\ndeclare description \"Sine-carrier ring modulation with carrier blend and lowpass - bells, clangs and robot tones\";\ndeclare author \"GRAME (os.osc)\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/oscillators.lib os.osc\";\ndeclare category \"guitar\";\ndeclare family \"mod\";\nimport(\"stdfaust.lib\");\n\nfreq = hslider(\"[0] Carrier[unit:Hz][scale:log]\", 220, 20, 4000, 0.1) : si.smoo;\nmix  = hslider(\"[1] Mix\", 0.7, 0, 1, 0.01) : si.smoo;\ntone = hslider(\"[2] Tone[unit:Hz][scale:log]\", 6000, 800, 16000, 1) : si.smoo;\nprocess = _ <: *(1-mix), (*(os.osc(freq)) : *(mix)) :> fi.lowpass(1, tone);"
 },
 {
  "id": "tdg-rotary-speakers",
  "name": "Rotary Speakers",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Leslie-style rotary: two counter-modulated delay lines with amplitude modulation and horn/drum coloration, summed to mono",
  "description": "Leslie-style rotary: two counter-modulated delay lines with amplitude modulation and horn/drum coloration, summed to mono",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Speed",
    "min": 0.5,
    "max": 12,
    "default": 6,
    "step": 0.1,
    "unit": "Hz",
    "path": "/Rotary_Speakers/Speed"
   },
   {
    "label": "Depth",
    "min": 10,
    "max": 200,
    "default": 50,
    "step": 1,
    "unit": "samples",
    "path": "/Rotary_Speakers/Depth"
   },
   {
    "label": "Coloration",
    "min": -1,
    "max": 1,
    "default": 0,
    "step": 0.05,
    "unit": "",
    "path": "/Rotary_Speakers/Coloration"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.05,
    "unit": "",
    "path": "/Rotary_Speakers/Dry_Wet"
   }
  ],
  "faustCode": "declare name \"Rotary Speakers\";\ndeclare description \"Leslie-style rotary: two counter-modulated delay lines with amplitude modulation and horn/drum coloration, summed to mono\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust rotary_speakers.dsp\";\ndeclare category \"guitar\";\ndeclare family \"mod\";\nimport(\"stdfaust.lib\");\n\nspeed      = hslider(\"[0] Speed[unit:Hz]\", 6, 0.5, 12, 0.1) : si.smoo;\ndepth      = hslider(\"[1] Depth[unit:samples]\", 50, 10, 200, 1) : si.smoo;\ncoloration = hslider(\"[2] Coloration\", 0, -1, 1, 0.05) : si.smoo;\ndry_wet    = hslider(\"[3] Dry/Wet\", 1, 0, 1, 0.05) : si.smoo;\n\ncoloration_filter(col) = _ <: (fi.lowshelf(5,(1 - col)*12,440), fi.highshelf(5,col*12,880)) :> _*ba.db2linear(-15);\nlfo = os.osc(speed);\nrot = _ <: (de.fdelay(500, depth*(lfo+1)*0.5 + 1)*(1-lfo)), (de.fdelay(500, depth*(lfo+1)*0.5 + 1)*(1+lfo)) : coloration_filter(coloration), coloration_filter(coloration) :> *(2);\nprocess = _ <: *(1-dry_wet), (rot : *(dry_wet)) :> _;"
 },
 {
  "id": "ex-tremolo-autopan",
  "name": "Shaped Tremolo",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "Faust examples",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Mono version of the Faust autopan example: LFO amplitude modulation with a tanh shape control (sine to square)",
  "description": "Mono version of the Faust autopan example: LFO amplitude modulation with a tanh shape control (sine to square)",
  "author": "GRAME",
  "flags": "",
  "params": [
   {
    "label": "Depth",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.001,
    "unit": "",
    "path": "/Shaped_Tremolo/Depth"
   },
   {
    "label": "Rate",
    "min": 0.1,
    "max": 30,
    "default": 4,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Shaped_Tremolo/Rate"
   },
   {
    "label": "Shape",
    "min": 0,
    "max": 1,
    "default": 0.2,
    "step": 0.001,
    "unit": "",
    "path": "/Shaped_Tremolo/Shape"
   }
  ],
  "faustCode": "declare name \"Shaped Tremolo\";\ndeclare description \"Mono version of the Faust autopan example: LFO amplitude modulation with a tanh shape control (sine to square)\";\ndeclare author \"GRAME\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faust/examples/misc/autopan.dsp\";\ndeclare category \"guitar\";\ndeclare family \"mod\";\nimport(\"stdfaust.lib\");\n\namount = hslider(\"[0] Depth\", 0.7, 0, 1, 0.001) : si.smoo;\nrate   = hslider(\"[1] Rate[unit:Hz][scale:log]\", 4, 0.1, 30, 0.01) : si.smoo;\nshape  = hslider(\"[2] Shape\", 0.2, 0, 1, 0.001) : si.smoo;\n\nsaturator(sh, x) = x, ma.tanh(x*10.) : it.interpolate_linear(sh);\ng = os.osc(rate) : saturator(shape) : it.remap(-1., 1., 1.-amount, 1.);\nprocess = *(g);"
 },
 {
  "id": "gx-switched-tremolo",
  "name": "Switched Tremolo",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Line 6 POD-style tremolo that steps between up to four LFO rates.",
  "description": "Tremolo whose modulation cycles through up to four oscillator frequencies (Steps, Switch Freq, Freq 0–3) with Depth and wet/dry, inspired by the Line 6 POD. Produces rhythmic, pattern-like tremolo.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Steps",
    "min": 1,
    "max": 4,
    "default": 4,
    "step": 1,
    "unit": "",
    "path": "/gx_switched_tremolo/Steps"
   },
   {
    "label": "Switch Freq",
    "min": 0.25,
    "max": 5,
    "default": 1,
    "step": 0.25,
    "unit": "",
    "path": "/gx_switched_tremolo/Switch_Freq"
   },
   {
    "label": "Freq 0",
    "min": 0.25,
    "max": 15,
    "default": 1,
    "step": 0.5,
    "unit": "",
    "path": "/gx_switched_tremolo/Freq_0"
   },
   {
    "label": "Freq 1",
    "min": 0.25,
    "max": 15,
    "default": 1,
    "step": 0.5,
    "unit": "",
    "path": "/gx_switched_tremolo/Freq_1"
   },
   {
    "label": "Freq 2",
    "min": 0.25,
    "max": 15,
    "default": 1,
    "step": 0.5,
    "unit": "",
    "path": "/gx_switched_tremolo/Freq_2"
   },
   {
    "label": "Freq 3",
    "min": 0.25,
    "max": 15,
    "default": 1,
    "step": 0.5,
    "unit": "",
    "path": "/gx_switched_tremolo/Freq_3"
   },
   {
    "label": "Depth",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.05,
    "unit": "",
    "path": "/gx_switched_tremolo/Depth"
   },
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/gx_switched_tremolo/wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/switched_tremolo.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n//------------------------------------\n//Inspired by:Line 6 POD-3\n//Found this effect somewhere here\n//------------------------------------\n\n//------------------------------------\n//Description:\n//The modulated signal got using 4 oscillations,\n//which are switched.\n//\n//Parameters description:\n//steps - number of oscillators in bank\n//sw_freq - oscillators switching freq\n//freq0..4 - oscillators freqs\n//depth - as is\n//------------------------------------\n\nimport(\"stdfaust.lib\");\n\nsteps = hslider(\"Steps\", 4, 1, 4, 1);\nsw_freq = hslider(\"Switch Freq\", 1, 0.25, 5, 0.25);\nfreq0 = hslider(\"Freq 0\", 1, 0.25, 15, 0.5);\nfreq1 = hslider(\"Freq 1\", 1, 0.25, 15, 0.5);\nfreq2 = hslider(\"Freq 2\", 1, 0.25, 15, 0.5);\nfreq3 = hslider(\"Freq 3\", 1, 0.25, 15, 0.5);\ndepth = hslider(\"Depth\", 0.5, 0, 1, 0.05);\n\nwet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\ndry = 1 - wet;\n\nin_range(min_val, max_val, x) = x>min_val,x<=max_val:*:_;\n\nN = 4;\nfreqs = (freq0, freq1, freq2, freq3);\nprocess = _<:*(dry),(*(wet):(par(i,N,os.osc(ba.take(i+1,freqs))),\n\t(os.lf_sawpos(sw_freq)<:par(i,N,in_range(i/steps,(i+1)/steps):\n\tsi.smooth(ba.tau2pole(0.05))))),_:\n\t(si.dot(N):_*depth:_+1:_-depth),_:_*_:_):>_;"
 },
 {
  "id": "tdg-tri-chorus",
  "name": "Tri Chorus",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Three flanger_mono voices with phase-offset and saw-delayed LFOs summed - thick tri-chorus (from rects/mod_01 trichor)",
  "description": "Three flanger_mono voices with phase-offset and saw-delayed LFOs summed - thick tri-chorus (from rects/mod_01 trichor)",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Speed",
    "min": 0.1,
    "max": 10,
    "default": 0.8,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Tri_Chorus/Speed"
   },
   {
    "label": "Depth",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tri_Chorus/Depth"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.9,
    "default": 0.2,
    "step": 0.01,
    "unit": "",
    "path": "/Tri_Chorus/Feedback"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/Tri_Chorus/Mix"
   }
  ],
  "faustCode": "declare name \"Tri Chorus\";\ndeclare description \"Three flanger_mono voices with phase-offset and saw-delayed LFOs summed - thick tri-chorus (from rects/mod_01 trichor)\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust rects/mod_01.dsp trichor()\";\ndeclare category \"guitar\";\ndeclare family \"mod\";\nimport(\"stdfaust.lib\");\n\nspeed = hslider(\"[0] Speed[unit:Hz]\", 0.8, 0.1, 10, 0.01) : si.smoo;\ndepth = hslider(\"[1] Depth\", 0.5, 0, 1, 0.01) : si.smoo;\nfb    = hslider(\"[2] Feedback\", 0.2, 0, 0.9, 0.01) : si.smoo;\nmix   = hslider(\"[3] Mix\", 0.6, 0, 1, 0.01) : si.smoo;\n\nsamps_max = 512;\nflange(lfo,dp,fbk) = pf.flanger_mono(samps_max, ((lfo+1)*0.5)*dp*(samps_max-2) + 1, dp, fbk, 0);\nlfo = os.osc(speed);\ntrichor(lfo,dp,fbk) = _ <: flange(lfo,dp,fbk*0.3),\n    flange(lfo : de.fdelay(1024, os.osc(3):_+1:_*0.5:_*200) : _*-1, dp, fbk*0.7),\n    flange(lfo : de.fdelay(1024, os.lf_sawpos(0.78*speed):_*200), dp, fbk*0.5) :> *(0.33);\nprocess = _ <: *(1-mix), (trichor(lfo, depth, fb) : *(mix)) :> _;"
 },
 {
  "id": "gx-gxtubetremelo",
  "name": "Tube Tremolo",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Vactrol tremolo wrapped in 12AX7 input and output tube stages, in five bands.",
  "description": "The vactrol (LDR) tremolo model placed between 12AX7 input and output tube-table stages across a five-band split, with Drive for tube grit, Speed, Depth and Output. Amp-style tremolo with tube warmth.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tube_Tremolo/Drive"
   },
   {
    "label": "output",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Tube_Tremolo/output"
   },
   {
    "label": "speed",
    "min": 0.1,
    "max": 14,
    "default": 5,
    "step": 0.1,
    "unit": "",
    "path": "/Tube_Tremolo/speed"
   },
   {
    "label": "depth",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tube_Tremolo/depth"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxtubetremelo.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Tube Tremolo\";\ndeclare category \"Modulation\";\n\n/*\n** Model of a vactrol tremolo unit by \"transmogrify\"\n** c.f. http://sourceforge.net/apps/phpbb/guitarix/viewtopic.php?f=7&t=44&p=233&hilit=transmogrifox#p233\n** http://transmogrifox.webs.com/vactrol.m\n*/\n\nimport(\"stdfaust.lib\");\nimport(\"redeye.lib\");\n\n/* vactrol model */\n\nR1 = 2700;\nRa = 1e6;\nRb = 300;\n\nb = exp(log(Ra)/log(Rb)) - exp(1);\ndTC = 0.06;\nminTC = log(0.005/dTC);\n\ncds = ((_ <: _,_),_ : _+(1-alpha)*_) ~ (_<:*(alpha)) with {\n    iSR = 1/ma.SR;\n    dRC = dTC * exp(*(minTC));\n    alpha = 1 - iSR / (dRC + iSR);\n};\n\nvactrol = pow(_,1.9) : cds : *(b) + exp(1) : exp(log(Ra)/log) : R1/(_ + R1);\n\n/* os.triangle oscillator (not bandlimited, frequency is approximate) */\n\ntrianglewave(freq) = _ ~ (_ <: _ + hyst) : /(periodsamps) with {\n    if(c,t,e) = select2(c,e,t);\n    hyst(x) = if(_ > 0, 2 * (x < periodsamps) - 1, 1 - 2 * (x > 0)) ~ _;\n    periodsamps = int(ma.SR / (2*float(freq)));\n};\n\n/* tremolo unit, using os.triangle or sine oscillator as lfo */\n\ntremolo(freq, depth) = lfo * depth + 1 - depth : vactrol with {\n    sine(freq) = (os.oscs(freq) + 1) / 2 : max(0); // max(0) because of numerical inaccuracy\n    SINE=checkbox(\"SINEWAVE[enum:os.triangle|sine]\");\n    lfo = select2(SINE, trianglewave(freq), sine(freq));\n};\n\noutput = vslider(\"output[style:knob]\", 0.0, -20.0, 20.0, 0.1):ba.db2linear:si.smooth(0.993);\n\namp = input12ax7:*(tremolo(vslider(\"speed[style:knob]\",5,0.1,14,0.1),vslider(\"depth[style:knob]\",0.5,0,1,0.01))):output12ax7:*(output);\nfreq_split = fi.filterbank(3, (86.0,210.0,1200.0,6531.0));\nprocess    = freq_split: ( amp , amp , amp, amp, amp) :>_;"
 },
 {
  "id": "gx-gxtubevibrato",
  "name": "Tube Vibrato",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "True pitch vibrato from a modulated delay, wrapped in 12AX7 tube stages, in five bands.",
  "description": "A delay-line pitch vibrato with Speed and Depth, whose LFO can be triangle or sine, run inside 12AX7 input and output tube-table stages across a five-band split. Drive sets the tube grit and Output the level.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/gx_gxtubevibrato/Drive"
   },
   {
    "label": "speed",
    "min": 0,
    "max": 14,
    "default": 5,
    "step": 0.1,
    "unit": "",
    "path": "/gx_gxtubevibrato/speed"
   },
   {
    "label": "depth",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/gx_gxtubevibrato/depth"
   },
   {
    "label": "output",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/gx_gxtubevibrato/output"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxtubevibrato.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n/*\nAttempt at a true vibrato\nAnd it works well!\nSounds very sweet with tubes wrapped\n\nNeed\nLFO to modulate de.delay\t- LFO 5 - 14Hz\n\tspeed and depth\n*/\nimport(\"stdfaust.lib\");\nimport(\"redeye.lib\");\n\n\n/* os.triangle oscillator (not bandlimited, frequency is approximate) */\n\ntrianglewave(freq) = _ ~ (_ <: _ + hyst) : /(periodsamps) with {\n    if(c,t,e) = select2(c,e,t);\n    hyst(x) = if(_ > 0, 2 * (x < periodsamps) - 1, 1 - 2 * (x > 0)) ~ _;\n    periodsamps = int(ma.SR / (2*float(freq)));\n};\n\n/* vibrato unit, using os.triangle or sine oscillator as lfo \n\tto modulate the de.delay time \n*/\n\nvibrato = ((( lfo + 1 ) *5)+5)*depth with {\n    sine(freq) = (os.oscs(freq) + 1) / 2 : max(0); // max(0) because of numerical inaccuracy\n    SINE=checkbox(\"SINEWAVE[enum:os.triangle|sine]\");\n    lfo = select2(SINE, trianglewave(freq), sine(freq));\n\tfreq = vslider(\"speed[style:knob]\",5,0,14,0.1) ;\n\tdepth = vslider(\"depth[style:knob]\",0.5,0.0,1.0,0.01) ;\n};\n\ndelayed  = de.sdelay(65536, interp, vibrato*ma.SR/1000.0) with{\n\tN \t\t= int(2^12); //65536\n\tinterp = 100.0 *ma.SR/1000.0;\n\tdtime\t= hslider(\"delay[unit:ms][style:knob]\", 0, 0, 14, 0.1)*ma.SR/1000.0;\n};\n\noutput = vslider(\"output[style:knob]\", 0.0, -20.0, 20.0, 0.1):ba.db2linear:si.smooth(0.993);\namp = input12ax7:delayed:output12ax7:*(output);\nfreq_split = fi.filterbank(3, (86.0,210.0,1200.0,6531.0));\nprocess    = freq_split: ( amp , amp , amp, amp, amp) :>_;"
 },
 {
  "id": "gx-tremolo",
  "name": "Vactrol Tremolo",
  "category": "guitar",
  "family": "mod",
  "familyName": "Modulation",
  "icon": "tabler:wave-sine",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Opto (vactrol/LDR) tremolo with CdS-cell lag; smooth amp-style throb.",
  "description": "Model of a vactrol tremolo by transmogrifox: a hysteretic triangle LFO drives a CdS photocell model with RC lag and a resistive divider. Freq, Depth and wet/dry give the smooth, slightly asymmetric pulse of an optical amp tremolo.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 100,
    "step": 1,
    "unit": "",
    "path": "/Tremolo/wet_dry"
   },
   {
    "label": "freq",
    "min": 0.1,
    "max": 50,
    "default": 5,
    "step": 0.1,
    "unit": "",
    "path": "/Tremolo/freq"
   },
   {
    "label": "depth",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tremolo/depth"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tremolo.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Tremolo\";\ndeclare category \"Modulation\";\n\n/*\n** Model of a vactrol tremolo unit by \"transmogrify\"\n** c.f. http://sourceforge.net/apps/phpbb/guitarix/viewtopic.php?f=7&t=44&p=233&hilit=transmogrifox#p233\n** http://transmogrifox.webs.com/vactrol.m\n*/\n\nimport(\"stdfaust.lib\");\n\n/* vactrol model */\n\nR1 = 2700;\nRa = 1e6;\nRb = 300;\nb = exp(log(Ra)/log(Rb)) - exp(1);\ndTC = 0.06;\nminTC = log(0.005/dTC);\n\ncds = ((_ <: _,_),_ : _+(1-alpha)*_) ~ (_<:*(alpha)) with {\n    iSR = 1/ma.SR;\n    dRC = dTC * exp(*(minTC));\n    alpha = 1 - iSR / (dRC + iSR);\n};\n\nvactrol = pow(_,1.9) : cds : *(b) + exp(1) : exp(log(Ra)/log) : R1/(_ + R1);\n\n/* os.triangle oscillator (not bandlimited, frequency is approximate) */\n\ntrianglewave(freq) = _ ~ (_ <: _ + hyst) : /(periodsamps) with {\n    if(c,t,e) = select2(c,e,t);\n    hyst(x) = if(_ > 0, 2 * (x < periodsamps) - 1, 1 - 2 * (x > 0)) ~ _;\n    periodsamps = int(ma.SR / (2*float(freq)));\n};\n\n/* tremolo unit, using os.triangle or sine oscillator as lfo */\n\ntremolo(freq, depth) = lfo * depth + 1 - depth : vactrol with {\n    sine(freq) = (os.oscs(freq) + 1) / 2 : max(0); // max(0) because of numerical inaccuracy\n    SINE=checkbox(\"SINE[enum:os.triangle|sine]\");\n    lfo = select2(SINE, trianglewave(freq), sine(freq));\n};\n\nwet = vslider(\"wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]\",  100, 0, 100, 1) : /(100);\ndry = 1 - wet;\n\nprocess =  _<:*(dry),(*(wet): *(tremolo(vslider(\"freq\",5,0.1,50,0.1),vslider(\"depth\",0.5,0,1,0.01)))):>_;"
 },
 {
  "id": "ex-harmonic-exciter",
  "name": "Harmonic Exciter",
  "category": "drum",
  "family": "pitch",
  "familyName": "Pitch",
  "icon": "tabler:music",
  "tag": "DrumBrute / Volca",
  "source": "Faust examples",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "Aphex-style psychoacoustic exciter (US4150253): highpass, compress, cubic harmonic generator, blend back with the dry signal",
  "description": "Aphex-style psychoacoustic exciter (US4150253): highpass, compress, cubic harmonic generator, blend back with the dry signal",
  "author": "Priyanka Shekar, Julius O. Smith III (revised by Romain Michon)",
  "flags": "",
  "params": [
   {
    "label": "Cutoff",
    "min": 1000,
    "max": 10000,
    "default": 5000,
    "step": 100,
    "unit": "Hz",
    "path": "/Harmonic_Exciter/Cutoff"
   },
   {
    "label": "Harmonics",
    "min": 1,
    "max": 200,
    "default": 20,
    "step": 1,
    "unit": "percent",
    "path": "/Harmonic_Exciter/Harmonics"
   },
   {
    "label": "Ratio",
    "min": 1,
    "max": 20,
    "default": 5,
    "step": 0.1,
    "unit": "",
    "path": "/Harmonic_Exciter/Ratio"
   },
   {
    "label": "Threshold",
    "min": -100,
    "max": 10,
    "default": -30,
    "step": 0.1,
    "unit": "dB",
    "path": "/Harmonic_Exciter/Threshold"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Harmonic_Exciter/Mix"
   }
  ],
  "faustCode": "declare name \"Harmonic Exciter\";\ndeclare description \"Aphex-style psychoacoustic exciter (US4150253): highpass, compress, cubic harmonic generator, blend back with the dry signal\";\ndeclare author \"Priyanka Shekar, Julius O. Smith III (revised by Romain Michon)\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faust/examples/psychoacoustic/harmonicExciter.dsp dm.exciter\";\ndeclare category \"drum\";\ndeclare family \"utility\";\nimport(\"stdfaust.lib\");\n\nfc     = hslider(\"[0] Cutoff[unit:Hz][scale:log]\", 5000, 1000, 10000, 100) : si.smoo;\nph     = hslider(\"[1] Harmonics[unit:percent]\", 20, 1, 200, 1) : si.smoo : max(1) : /(100);\nratio  = hslider(\"[2] Ratio\", 5, 1, 20, 0.1);\nthresh = hslider(\"[3] Threshold[unit:dB]\", -30, -100, 10, 0.1);\nml     = hslider(\"[4] Mix\", 0.5, 0, 1, 0.01) : si.smoo;\n\ncompressor = co.compressor_mono(ratio, thresh, 0.05, 0.5);\nharmonicCreator(x) = x <: cubDist1, cubDist2, cubDist3 :> _;\ncubDist1(x) = (x < 0) * x;\ncubDist2(x) = (x >= 0) * (x <= 1) * (x - x ^ 3 / 3);\ncubDist3(x) = (x > 1) * 2/3;\nprocess = _ <: (fi.highpass(2, fc) : compressor : *(ph) : harmonicCreator : *(1/ph)), _ : (_ * ml), (_ * (1.0 - ml)) :> _;"
 },
 {
  "id": "lib-harmonizer",
  "name": "Harmonizer",
  "category": "guitar",
  "family": "pitch",
  "familyName": "Pitch",
  "icon": "tabler:music",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Two ef.transpose voices at independent intervals mixed with the dry note - instant intervals",
  "description": "Two ef.transpose voices at independent intervals mixed with the dry note - instant intervals",
  "author": "Grame (ef.transpose)",
  "flags": "",
  "params": [
   {
    "label": "Voice 1",
    "min": -24,
    "max": 24,
    "default": 7,
    "step": 1,
    "unit": "semi",
    "path": "/Harmonizer/Voice_1"
   },
   {
    "label": "Voice 1 Level",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/Harmonizer/Voice_1_Level"
   },
   {
    "label": "Voice 2",
    "min": -24,
    "max": 24,
    "default": -12,
    "step": 1,
    "unit": "semi",
    "path": "/Harmonizer/Voice_2"
   },
   {
    "label": "Voice 2 Level",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Harmonizer/Voice_2_Level"
   },
   {
    "label": "Dry",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Harmonizer/Dry"
   }
  ],
  "faustCode": "declare name \"Harmonizer\";\ndeclare description \"Two ef.transpose voices at independent intervals mixed with the dry note - instant intervals\";\ndeclare author \"Grame (ef.transpose)\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/misceffects.lib ef.transpose\";\ndeclare category \"guitar\";\ndeclare family \"pitch\";\nimport(\"stdfaust.lib\");\n\ns1 = hslider(\"[0] Voice 1[unit:semi]\", 7, -24, 24, 1) : si.smoo;\nl1 = hslider(\"[1] Voice 1 Level\", 0.7, 0, 1, 0.01) : si.smoo;\ns2 = hslider(\"[2] Voice 2[unit:semi]\", -12, -24, 24, 1) : si.smoo;\nl2 = hslider(\"[3] Voice 2 Level\", 0.5, 0, 1, 0.01) : si.smoo;\ndry = hslider(\"[4] Dry\", 1, 0, 1, 0.01) : si.smoo;\nwin = 1500;\nprocess = _ <: *(dry), (ef.transpose(win, 300, s1) : *(l1)), (ef.transpose(win, 300, s2) : *(l2)) :> _;"
 },
 {
  "id": "kpp-octaver",
  "name": "KPP Octaver",
  "category": "guitar",
  "family": "pitch",
  "familyName": "Pitch",
  "icon": "tabler:music",
  "tag": "Guitar",
  "source": "KPP",
  "license": "GPL-3.0-or-later",
  "shortDesc": "Analog-style octaver: extracts the fundamental, squares it, divides by 2 and 4 and modulates the input for -1 and -2 octave tones",
  "description": "Analog-style octaver: extracts the fundamental, squares it, divides by 2 and 4 and modulates the input for -1 and -2 octave tones",
  "author": "Oleg Kapitonov",
  "flags": "",
  "params": [
   {
    "label": "Octave 1",
    "min": 0,
    "max": 30,
    "default": 20,
    "step": 0.01,
    "unit": "",
    "path": "/KPP_Octaver/Octave_1"
   },
   {
    "label": "Octave 2",
    "min": 0,
    "max": 30,
    "default": 10,
    "step": 0.01,
    "unit": "",
    "path": "/KPP_Octaver/Octave_2"
   },
   {
    "label": "Dry",
    "min": 0,
    "max": 30,
    "default": 30,
    "step": 0.01,
    "unit": "",
    "path": "/KPP_Octaver/Dry"
   },
   {
    "label": "Cutoff",
    "min": 100,
    "max": 200,
    "default": 160,
    "step": 0.1,
    "unit": "Hz",
    "path": "/KPP_Octaver/Cutoff"
   }
  ],
  "faustCode": "declare name \"KPP Octaver\";\ndeclare description \"Analog-style octaver: extracts the fundamental, squares it, divides by 2 and 4 and modulates the input for -1 and -2 octave tones\";\ndeclare author \"Oleg Kapitonov\";\ndeclare license \"GPL-3.0-or-later\";\ndeclare source \"olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_octaver/kpp_octaver.dsp\";\ndeclare category \"guitar\";\ndeclare family \"pitch\";\nimport(\"stdfaust.lib\");\n\nlevel_d1  = hslider(\"[0] Octave 1\", 20, 0, 30, 0.01) : si.smoo : -(20) : ba.db2linear;\nlevel_d2  = hslider(\"[1] Octave 2\", 10, 0, 30, 0.01) : si.smoo : -(20) : ba.db2linear;\nlevel_dry = hslider(\"[2] Dry\", 30, 0, 30, 0.01) : si.smoo : -(30) : ba.db2linear;\ncutoff    = hslider(\"[3] Cutoff[unit:Hz]\", 160, 100, 200, 0.1);\n\npre_filter = fi.dcblocker : fi.lowpass(3, 80) : fi.peak_eq(30, 100, 80) : fi.peak_eq(20, 440, 200);\ndistortion = (+ : co.compressor_mono(100, -80, 0.1, 0.1) : ma.signum : max(-0.0000001) : min(0.0000001)) ~ _;\noctaver = distortion : fi.zero(1) : max(0.0) : ma.signum : *(-2.0) : +(1.0) :\n  (* : +(0.1) : *(10000.0) : max(-1.0) : min(1.0)) ~ _ : max(0.0) : min(1.0);\ndown1 = _ <: fi.highpass(1,260), (pre_filter : octaver) : * : fi.lowpass(3, cutoff) : fi.highpass(3, 40) : fi.highpass(1, 80);\ndown2 = _ <: fi.highpass(5,240), (pre_filter : octaver : -(0.5) : octaver) : * : fi.lowpass(3, cutoff / 2.0);\nstomp = _ <: down1, down2 : *(level_d1), *(level_d2) : + : *(2.0) : fi.dcblocker;\nprocess = _ <: *(level_dry), stomp : +;"
 },
 {
  "id": "tdg-parametric-pitch-shifter",
  "name": "Parametric Pitch Shifter",
  "category": "guitar",
  "family": "pitch",
  "familyName": "Pitch",
  "icon": "tabler:music",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Pitch shifter whose shift amount is driven by a blend of envelope follower and LFO - auto-bends, warbles and touch-octaves",
  "description": "Pitch shifter whose shift amount is driven by a blend of envelope follower and LFO - auto-bends, warbles and touch-octaves",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Envelope",
    "min": 0.1,
    "max": 3,
    "default": 1,
    "step": 0.05,
    "unit": "s",
    "path": "/Parametric_Pitch_Shifter/Envelope"
   },
   {
    "label": "LFO Speed",
    "min": 0.1,
    "max": 10,
    "default": 0.5,
    "step": 0.05,
    "unit": "Hz",
    "path": "/Parametric_Pitch_Shifter/LFO_Speed"
   },
   {
    "label": "Depth",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.05,
    "unit": "",
    "path": "/Parametric_Pitch_Shifter/Depth"
   },
   {
    "label": "Env/LFO",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.05,
    "unit": "",
    "path": "/Parametric_Pitch_Shifter/Env_LFO"
   },
   {
    "label": "Shift",
    "min": -6,
    "max": 6,
    "default": 2,
    "step": 0.1,
    "unit": "semi",
    "path": "/Parametric_Pitch_Shifter/Shift"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.05,
    "unit": "",
    "path": "/Parametric_Pitch_Shifter/Dry_Wet"
   }
  ],
  "faustCode": "declare name \"Parametric Pitch Shifter\";\ndeclare description \"Pitch shifter whose shift amount is driven by a blend of envelope follower and LFO - auto-bends, warbles and touch-octaves\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust parametric_pitch_shifter.dsp\";\ndeclare category \"guitar\";\ndeclare family \"pitch\";\nimport(\"stdfaust.lib\");\n\nenvelope = hslider(\"[0] Envelope[unit:s]\", 1, 0.1, 3, 0.05);\nspeed    = hslider(\"[1] LFO Speed[unit:Hz]\", 0.5, 0.1, 10, 0.05) : si.smoo;\ndepth    = hslider(\"[2] Depth\", 0.5, 0, 1, 0.05) : si.smoo;\nctrl     = hslider(\"[3] Env/LFO\", 0.5, 0, 1, 0.05) : si.smoo;\nshift    = hslider(\"[4] Shift[unit:semi]\", 2, -6, 6, 0.1) : si.smoo : *(2);\ndry_wet  = hslider(\"[5] Dry/Wet\", 0.5, 0, 1, 0.05) : si.smoo;\n\nmixer(mix) = _*(1 - mix), _*mix :> _;\nc_folower_colibration = 6;\nparametric_controller(mix, envelope_t, freq, dep) = (an.amp_follower(envelope_t) : _*c_folower_colibration : _*dep, os.osc(freq)*0.5 : _, _*dep) : mixer(mix) : _+0.5;\nprocess = _ <: _, (_ <: parametric_controller(ctrl, envelope, speed, depth)*shift, _ : ef.transpose(2048, 1024)) : mixer(dry_wet);"
 },
 {
  "id": "lib-pitch-shift",
  "name": "Pitch Shifter",
  "category": "guitar",
  "family": "pitch",
  "familyName": "Pitch",
  "icon": "tabler:music",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "BSD-3-Clause",
  "shortDesc": "Grame's classic dual-delay crossfade pitch shifter, octave down to octave up with mix",
  "description": "Grame's classic dual-delay crossfade pitch shifter, octave down to octave up with mix",
  "author": "Grame",
  "flags": "",
  "params": [
   {
    "label": "Shift",
    "min": -24,
    "max": 24,
    "default": 12,
    "step": 0.1,
    "unit": "semi",
    "path": "/Pitch_Shifter/Shift"
   },
   {
    "label": "Window",
    "min": 200,
    "max": 4000,
    "default": 1000,
    "step": 1,
    "unit": "samples",
    "path": "/Pitch_Shifter/Window"
   },
   {
    "label": "Crossfade",
    "min": 10,
    "max": 2000,
    "default": 200,
    "step": 1,
    "unit": "samples",
    "path": "/Pitch_Shifter/Crossfade"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Pitch_Shifter/Mix"
   }
  ],
  "faustCode": "declare name \"Pitch Shifter\";\ndeclare description \"Grame's classic dual-delay crossfade pitch shifter, octave down to octave up with mix\";\ndeclare author \"Grame\";\ndeclare license \"BSD-3-Clause\";\ndeclare source \"grame-cncm/faust/examples/pitchShifting/pitchShifter.dsp ef.transpose\";\ndeclare category \"guitar\";\ndeclare family \"pitch\";\nimport(\"stdfaust.lib\");\n\nshift = hslider(\"[0] Shift[unit:semi]\", 12, -24, 24, 0.1) : si.smoo;\nwin   = hslider(\"[1] Window[unit:samples]\", 1000, 200, 4000, 1);\nxfade = hslider(\"[2] Crossfade[unit:samples]\", 200, 10, 2000, 1);\nmix   = hslider(\"[3] Mix\", 0.5, 0, 1, 0.01) : si.smoo;\nprocess = _ <: *(1-mix), (ef.transpose(win, min(win, xfade), shift) : *(mix)) :> _;"
 },
 {
  "id": "lib-tape-stop",
  "name": "Tape Stop",
  "category": "guitar",
  "family": "pitch",
  "familyName": "Pitch",
  "icon": "tabler:music",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "David Braun's tape-stop: engage Stop and playback decelerates to a halt with adjustable curve",
  "description": "David Braun's tape-stop: engage Stop and playback decelerates to a halt with adjustable curve",
  "author": "David Braun",
  "flags": "",
  "params": [
   {
    "label": "Stop Time",
    "min": 10,
    "max": 4000,
    "default": 600,
    "step": 1,
    "unit": "ms",
    "path": "/Tape_Stop/Stop_Time"
   },
   {
    "label": "Stop Curve",
    "min": 0.01,
    "max": 2,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Tape_Stop/Stop_Curve"
   },
   {
    "label": "Gain Curve",
    "min": 0.01,
    "max": 2,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Tape_Stop/Gain_Curve"
   },
   {
    "label": "Crossfade",
    "min": 0,
    "max": 125,
    "default": 3,
    "step": 1,
    "unit": "ms",
    "path": "/Tape_Stop/Crossfade"
   }
  ],
  "faustCode": "declare name \"Tape Stop\";\ndeclare description \"David Braun's tape-stop: engage Stop and playback decelerates to a halt with adjustable curve\";\ndeclare author \"David Braun\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faustlibraries/misceffects.lib ef.tapeStop\";\ndeclare category \"guitar\";\ndeclare family \"pitch\";\nimport(\"stdfaust.lib\");\n\nstop      = checkbox(\"[0] Stop\");\nstopTime  = hslider(\"[1] Stop Time[unit:ms]\", 600, 10, 4000, 1) : *(ma.SR/1000);\nstopAlpha = hslider(\"[2] Stop Curve\", 1, 0.01, 2, 0.01);\ngainAlpha = hslider(\"[3] Gain Curve\", 1, 0.01, 2, 0.01);\nxfade     = hslider(\"[4] Crossfade[unit:ms]\", 3, 0, 125, 1) : *(ma.SR/1000);\nMAXS = 4 * 48000;\nprocess = ef.tapeStop(1, 3, MAXS, xfade, gainAlpha, stopAlpha, stopTime, stop);"
 },
 {
  "id": "luca-chamberlin",
  "name": "Chamberlin Reverb",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "L. Spanedda",
  "license": "MIT",
  "shortDesc": "Hal Chamberlin's 1979 all-allpass reverberator (3 series + 2x2 output allpasses) with T60 decay control - vintage chip-reverb smear",
  "description": "Hal Chamberlin's 1979 all-allpass reverberator (3 series + 2x2 output allpasses) with T60 decay control - vintage chip-reverb smear",
  "author": "Luca Spanedda",
  "flags": "",
  "params": [
   {
    "label": "Decay",
    "min": 0.2,
    "max": 15,
    "default": 3,
    "step": 0.1,
    "unit": "s",
    "path": "/Chamberlin_Reverb/Decay"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/Chamberlin_Reverb/Mix"
   }
  ],
  "faustCode": "declare name \"Chamberlin Reverb\";\ndeclare description \"Hal Chamberlin's 1979 all-allpass reverberator (3 series + 2x2 output allpasses) with T60 decay control - vintage chip-reverb smear\";\ndeclare author \"Luca Spanedda\";\ndeclare license \"MIT\";\ndeclare source \"LucaSpanedda/Digital_Reverberation_in_Faust src/reverberation.lib chamberlinDecay\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nt60 = hslider(\"[0] Decay[unit:s]\", 3, 0.2, 15, 0.1);\nmix = hslider(\"[1] Mix\", 0.35, 0, 1, 0.01) : si.smoo;\n\nmsasamps(t) = max(2, int((ma.SR / 1000) * t));\nt60_ms(ms, tt) = pow(0.001, (ms / 1000) / tt);\napf(t, g) = _ : (+ : _ <: @ (t  - 1), * (- g)) ~ * (g) : mem, _ : + : _;\nchamberlinDecay(seconds) = ap3ch <: apout1ch, apout2ch\nwith{\n    ap3ch = apf(msasamps(49.6), t60_ms(49.6, seconds)) : apf(msasamps(34.75), t60_ms(34.75, seconds)) : apf(msasamps(24.18), t60_ms(24.18, seconds));\n    apout1ch = apf(msasamps(17.85), t60_ms(17.85, seconds)) : apf(msasamps(10.98), t60_ms(10.98, seconds));\n    apout2ch = apf(msasamps(18.01), t60_ms(18.01, seconds)) : apf(msasamps(10.82), t60_ms(10.82, seconds));\n};\nwet = chamberlinDecay(t60) :> *(0.5);\nprocess = _ <: *(1-mix), (wet : *(mix)) :> _;"
 },
 {
  "id": "lib-dattorro",
  "name": "Dattorro Plate",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "Jon Dattorro's 1997 figure-of-eight plate reverb (input diffusion + modulated tank)",
  "description": "Jon Dattorro's 1997 figure-of-eight plate reverb (input diffusion + modulated tank)",
  "author": "Jakob Zerbian (Faust port), Jon Dattorro",
  "flags": "",
  "params": [
   {
    "label": "Bandwidth",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.001,
    "unit": "",
    "path": "/Dattorro_Plate/Bandwidth"
   },
   {
    "label": "Input Diffusion",
    "min": 0,
    "max": 1,
    "default": 0.625,
    "step": 0.001,
    "unit": "",
    "path": "/Dattorro_Plate/Input_Diffusion"
   },
   {
    "label": "Decay",
    "min": 0,
    "max": 0.99,
    "default": 0.6,
    "step": 0.001,
    "unit": "",
    "path": "/Dattorro_Plate/Decay"
   },
   {
    "label": "Tank Diffusion",
    "min": 0,
    "max": 1,
    "default": 0.625,
    "step": 0.001,
    "unit": "",
    "path": "/Dattorro_Plate/Tank_Diffusion"
   },
   {
    "label": "Damping",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.001,
    "unit": "",
    "path": "/Dattorro_Plate/Damping"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/Dattorro_Plate/Mix"
   }
  ],
  "faustCode": "declare name \"Dattorro Plate\";\ndeclare description \"Jon Dattorro's 1997 figure-of-eight plate reverb (input diffusion + modulated tank)\";\ndeclare author \"Jakob Zerbian (Faust port), Jon Dattorro\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faustlibraries/reverbs.lib re.dattorro_rev\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nbw    = hslider(\"[0] Bandwidth\", 0.7, 0, 1, 0.001) : si.smoo;\nidiff = hslider(\"[1] Input Diffusion\", 0.625, 0, 1, 0.001) : si.smoo;\ndecay = hslider(\"[2] Decay\", 0.6, 0, 0.99, 0.001) : si.smoo;\nddiff = hslider(\"[3] Tank Diffusion\", 0.625, 0, 1, 0.001) : si.smoo;\ndamp  = hslider(\"[4] Damping\", 0.5, 0, 1, 0.001) : si.smoo;\nmix   = hslider(\"[5] Mix\", 0.35, 0, 1, 0.01) : si.smoo;\n\nwet = _ <: re.dattorro_rev(0, bw, idiff, idiff*0.8, decay, ddiff*1.12, ddiff, damp) :> *(0.5);\nprocess = _ <: *(1-mix), (wet : *(mix)) :> _;"
 },
 {
  "id": "tdg-duck-reverb",
  "name": "Duck Reverb",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Freeverb ducked by an envelope follower: the tail stays out of the way while you play and blooms in the gaps",
  "description": "Freeverb ducked by an envelope follower: the tail stays out of the way while you play and blooms in the gaps",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Attack",
    "min": 0.05,
    "max": 0.5,
    "default": 0.1,
    "step": 0.01,
    "unit": "s",
    "path": "/Duck_Reverb/Attack"
   },
   {
    "label": "Release",
    "min": 0.05,
    "max": 2,
    "default": 0.3,
    "step": 0.01,
    "unit": "s",
    "path": "/Duck_Reverb/Release"
   },
   {
    "label": "Duck Amount",
    "min": 0,
    "max": 40,
    "default": 18,
    "step": 0.5,
    "unit": "dB",
    "path": "/Duck_Reverb/Duck_Amount"
   },
   {
    "label": "Room Size",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/Duck_Reverb/Room_Size"
   },
   {
    "label": "Damp",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Duck_Reverb/Damp"
   },
   {
    "label": "Wet/Dry",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Duck_Reverb/Wet_Dry"
   }
  ],
  "faustCode": "declare name \"Duck Reverb\";\ndeclare description \"Freeverb ducked by an envelope follower: the tail stays out of the way while you play and blooms in the gaps\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust duck_reverb.dsp + freeverb.dspi\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\np_attack  = hslider(\"[0] Attack[unit:s]\", 0.1, 0.05, 0.5, 0.01);\np_release = hslider(\"[1] Release[unit:s]\", 0.3, 0.05, 2, 0.01);\np_amount  = hslider(\"[2] Duck Amount[unit:dB]\", 18, 0, 40, 0.5) : si.smoo;\nroomsize  = hslider(\"[3] Room Size\", 0.6, 0, 1, 0.01) : si.smoo : *(0.28) : +(0.7);\ndamp      = hslider(\"[4] Damp\", 0.5, 0, 1, 0.01) : si.smoo;\nwet_dry   = hslider(\"[5] Wet/Dry\", 0.5, 0, 1, 0.01) : si.smoo;\n\nrev = re.mono_freeverb(roomsize, 0.5, damp*0.4, 23) : *(0.015);\n// proportional ducking: reverb/delay level drops by up to `depth` dB as the input envelope rises\n// (the original used a hard gate — env*amount > 1 — which mutes the wet path entirely while playing,\n// so a 100 % wet mix went silent)\nduck_gain(att, rel, depth_db, x) = ba.db2linear(0 - depth_db * min(1, an.amp_follower_ud(att, rel, x) * 4)) : si.smooth(ba.tau2pole(0.02));\nprocess(x) = x*(1-wet_dry) + (rev(x) * duck_gain(p_attack, p_release, p_amount, x)) * wet_dry * 3;"
 },
 {
  "id": "owl-faustverb",
  "name": "FaustVerb",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "OWL patches",
  "license": "BSD-3-Clause",
  "shortDesc": "GRAME's primitive-level Freeverb (8 combs, 4 allpasses) as shipped on the OWL pedal",
  "description": "GRAME's primitive-level Freeverb (8 combs, 4 allpasses) as shipped on the OWL pedal",
  "author": "GRAME, OWL wrapper Rebel Technology",
  "flags": "",
  "params": [
   {
    "label": "Room Size",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/FaustVerb/Room_Size"
   },
   {
    "label": "Damp",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/FaustVerb/Damp"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.3333,
    "step": 0.01,
    "unit": "",
    "path": "/FaustVerb/Dry_Wet"
   }
  ],
  "faustCode": "declare name \"FaustVerb\";\ndeclare description \"GRAME's primitive-level Freeverb (8 combs, 4 allpasses) as shipped on the OWL pedal\";\ndeclare author \"GRAME, OWL wrapper Rebel Technology\";\ndeclare license \"BSD-3-Clause\";\ndeclare source \"pingdynasty/OwlPatches Faust/FaustVerb.dsp\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nfixedgain = 0.015; scaledamp = 0.4; scaleroom = 0.28; offsetroom = 0.7; allpassfeed = 0.5;\nroomsize = hslider(\"[0] Room Size\", 0.5, 0, 1, 0.01) : si.smoo : *(scaleroom) : +(offsetroom);\ndamp     = hslider(\"[1] Damp\", 0.5, 0, 1, 0.01) : si.smoo : *(scaledamp);\nwet      = hslider(\"[2] Dry/Wet\", 0.3333, 0, 1, 0.01) : si.smoo;\n\nallpass(dt,fb) = (_,_ <: (*(fb),_:+:@(dt)), -) ~ _ : (!,_);\ncomb(dt, fb, dmp) = (+:@(dt)) ~ (*(1-dmp) : (+ ~ *(dmp)) : *(fb));\nmonoReverb(fb1, fb2, dmp) = _ <: comb(1116,fb1,dmp), comb(1188,fb1,dmp), comb(1277,fb1,dmp), comb(1356,fb1,dmp),\n    comb(1422,fb1,dmp), comb(1491,fb1,dmp), comb(1557,fb1,dmp), comb(1617,fb1,dmp)\n    +> allpass(556,fb2) : allpass(441,fb2) : allpass(341,fb2) : allpass(225,fb2);\nprocess = _ <: (*(fixedgain) : monoReverb(roomsize, allpassfeed, damp) : *(wet)), *(1-wet) :> _;"
 },
 {
  "id": "lib-fdn-reverb",
  "name": "FDN Reverb 16",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "16-line feedback delay network with 5-band decay times and room dimension (fdnrev0)",
  "description": "16-line feedback delay network with 5-band decay times and room dimension (fdnrev0)",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Room Min",
    "min": 0.5,
    "max": 63,
    "default": 20,
    "step": 0.1,
    "unit": "m",
    "path": "/FDN_Reverb_16/Room_Min"
   },
   {
    "label": "Room Max",
    "min": 0.5,
    "max": 63,
    "default": 45,
    "step": 0.1,
    "unit": "m",
    "path": "/FDN_Reverb_16/Room_Max"
   },
   {
    "label": "Low RT60",
    "min": 0.1,
    "max": 20,
    "default": 3,
    "step": 0.1,
    "unit": "s",
    "path": "/FDN_Reverb_16/Low_RT60"
   },
   {
    "label": "High RT60",
    "min": 0.1,
    "max": 20,
    "default": 1.2,
    "step": 0.1,
    "unit": "s",
    "path": "/FDN_Reverb_16/High_RT60"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/FDN_Reverb_16/Mix"
   }
  ],
  "faustCode": "declare name \"FDN Reverb 16\";\ndeclare description \"16-line feedback delay network with 5-band decay times and room dimension (fdnrev0)\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faustlibraries/reverbs.lib re.fdnrev0\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nN = 16; NB = 5; BBSO = 3; MAXDELAY = 8192;\npathmin = hslider(\"[0] Room Min[unit:m][scale:log]\", 20, 0.5, 63, 0.1);\npathmax = hslider(\"[1] Room Max[unit:m][scale:log]\", 45, 0.5, 63, 0.1);\nt60lo   = hslider(\"[2] Low RT60[unit:s]\", 3.0, 0.1, 20, 0.1);\nt60hi   = hslider(\"[3] High RT60[unit:s]\", 1.2, 0.1, 20, 0.1);\nmix     = hslider(\"[4] Mix\", 0.35, 0, 1, 0.01) : si.smoo;\n\ndurs = par(i, NB, t60hi + (t60lo - t60hi) * i / (NB-1));\nfreqs = (500, 1000, 2000, 4000);\ndelays = de.prime_power_delays(N, pathmin, pathmax);\nwet = _ <: si.bus(N) : re.fdnrev0(MAXDELAY, delays, BBSO, freqs, durs, 1.0, 0) :> *(0.03);\nprocess = _ <: *(1-mix), (wet : *(mix)) :> _;"
 },
 {
  "id": "gx-freeverb",
  "name": "Freeverb",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Schroeder/Moorer Freeverb with room size, damping and wet/dry.",
  "description": "The classic Freeverb algorithm (parallel combs into series allpasses) with RoomSize, Damp and wet/dry. A simple, smooth digital room reverb.",
  "author": "brummer",
  "flags": "-double",
  "params": [
   {
    "label": "RoomSize",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/Freeverb/RoomSize"
   },
   {
    "label": "damp",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/Freeverb/damp"
   },
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Freeverb/wet_dry"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/freeverb.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Freeverb\";\ndeclare category \"Reverb\";\n\ndeclare version \t\"0.01\";\ndeclare author \t\t\"brummer\";\ndeclare license \t\"BSD\";\ndeclare copyright \t\"(c)brummer 2008\";\n\nimport(\"stdfaust.lib\");\n\nimport(\"guitarix.lib\");\n\n/*-----------------------------------------------\n\t\tfreeverb  by \"Grame\"\n  -----------------------------------------------*/\n\n// Filter Parameters\n\ncombtuningL1\t= 1116;\ncombtuningL2\t= 1188;\ncombtuningL3\t= 1277;\ncombtuningL4\t= 1356;\ncombtuningL5\t= 1422;\ncombtuningL6\t= 1491;\ncombtuningL7\t= 1557;\ncombtuningL8\t= 1617;\n\nallpasstuningL1\t= 556;\nallpasstuningL2\t= 441;\nallpasstuningL3\t= 341;\nallpasstuningL4\t= 225;\n\nroomsizeSlider \t= vslider(\"RoomSize\", 0.5, 0, 1, 0.025)*0.28 + 0.7;\ndampslider \t= vslider(\"damp\",0.5, 0, 1, 0.025);\ncombfeed \t= roomsizeSlider;\n//wetslider \t= 0.5 + vslider(\"wet_dry[name:wet/dry]\", 0, -0.5, 0.5, 0.1);\nwet_dry = vslider(\"wet_dry[name:wet/dry]\",  50, 0, 100, 1) : /(100);\ndry = 1 - wet_dry;\n\n// Reverb components\n\nmonoReverb(fb1, fb2, damp, spread)\n\t= _ <:\tcomb(combtuningL1+spread, fb1, damp),\n\t\t\tcomb(combtuningL2+spread, fb1, damp),\n\t\t\tcomb(combtuningL3+spread, fb1, damp),\n\t\t\tcomb(combtuningL4+spread, fb1, damp),\n\t\t\tcomb(combtuningL5+spread, fb1, damp),\n\t\t\tcomb(combtuningL6+spread, fb1, damp),\n\t\t\tcomb(combtuningL7+spread, fb1, damp),\n\t\t\tcomb(combtuningL8+spread, fb1, damp)\n\t\t+>\n\t\t \tallpass (allpasstuningL1+spread, fb2)\n\t\t:\tallpass (allpasstuningL2+spread, fb2)\n\t\t:\tallpass (allpasstuningL3+spread, fb2)\n\t\t:\tallpass (allpasstuningL4+spread, fb2)\n\t\t;\n\n//----------------------------------------------------------------\n\nfxctrl(g,w,Fx) =  _ <: (*(g) <: _ + Fx ), *(1-w) +> _;\nprocess = _<:*(dry),(*(wet_dry):fxctrl(0.015,wet_dry, monoReverb(combfeed, 0.5, dampslider, 23))):>_;"
 },
 {
  "id": "lib-freeverb",
  "name": "Freeverb",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Jezar's Freeverb: 8 lowpass-comb filters + 4 allpasses, the classic free reverb",
  "description": "Jezar's Freeverb: 8 lowpass-comb filters + 4 allpasses, the classic free reverb",
  "author": "Romain Michon (Faust port), Jezar at Dreampoint",
  "flags": "",
  "params": [
   {
    "label": "Room Size",
    "min": 0,
    "max": 1,
    "default": 0.6,
    "step": 0.01,
    "unit": "",
    "path": "/Freeverb/Room_Size"
   },
   {
    "label": "Damping",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Freeverb/Damping"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/Freeverb/Mix"
   }
  ],
  "faustCode": "declare name \"Freeverb\";\ndeclare description \"Jezar's Freeverb: 8 lowpass-comb filters + 4 allpasses, the classic free reverb\";\ndeclare author \"Romain Michon (Faust port), Jezar at Dreampoint\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/reverbs.lib re.mono_freeverb\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nsize = hslider(\"[0] Room Size\", 0.6, 0, 1, 0.01) : si.smoo;\ndamp = hslider(\"[1] Damping\", 0.5, 0, 1, 0.01) : si.smoo;\nmix  = hslider(\"[2] Mix\", 0.35, 0, 1, 0.01) : si.smoo;\n\nfb1 = 0.7 + 0.28 * size;\nprocess = _ <: *(1-mix), (re.mono_freeverb(fb1, 0.5, damp*0.4, 0) : *(mix)) :> _;"
 },
 {
  "id": "luca-greisinger-480l",
  "name": "Greisinger 480L",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "L. Spanedda",
  "license": "MIT",
  "shortDesc": "Dattorro/Greisinger Lexicon 480L-topology plate reverb (Tom Erbe's design): modulated allpass loops with cross-coupled tanks, mono wrap",
  "description": "Dattorro/Greisinger Lexicon 480L-topology plate reverb (Tom Erbe's design): modulated allpass loops with cross-coupled tanks, mono wrap",
  "author": "Luca Spanedda",
  "flags": "",
  "params": [
   {
    "label": "Decay",
    "min": 0,
    "max": 0.95,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/Greisinger_480L/Decay"
   },
   {
    "label": "Damping",
    "min": 0,
    "max": 0.9,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/Greisinger_480L/Damping"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/Greisinger_480L/Mix"
   }
  ],
  "faustCode": "declare name \"Greisinger 480L\";\ndeclare description \"Dattorro/Greisinger Lexicon 480L-topology plate reverb (Tom Erbe's design): modulated allpass loops with cross-coupled tanks, mono wrap\";\ndeclare author \"Luca Spanedda\";\ndeclare license \"MIT\";\ndeclare source \"LucaSpanedda/Digital_Reverberation_in_Faust src/reverberation.lib greisingerReverb\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\ndecay = hslider(\"[0] Decay\", 0.7, 0, 0.95, 0.01) : si.smoo;\ndamp  = hslider(\"[1] Damping\", 0.4, 0, 0.9, 0.01) : si.smoo;\nmix   = hslider(\"[2] Mix\", 0.35, 0, 1, 0.01) : si.smoo;\n\nmsasamps(t) = max(2, int((ma.SR / 1000) * t));\nop(b1) = _ * (1 - abs(b1)) : + ~ * (b1);\napf(t, g) = _ : (+ : _ <: @ (t  - 1), * (- g)) ~ * (g) : mem, _ : + : _;\ndelaymod(mod, t, tMod) = de.fdelay(tMax, modIndx) with { tMax = t + tMod; modIndx = t + (mod * tMod); };\napfMod(mod, t, tMod, g) = _ : (+ : _ <: delaymod(mod, t - 1, tMod), * (- g)) ~ * (g) : mem, _ : + : _;\ngreisingerReverb(decay, damp) = (si.bus(2) :> _ * (1 / 2) : predelay : op(damp) : apfsec) <: si.bus(2) : (ro.interleave(2, 2) : (par(i, 2, (_, _) :> + : loopsec(i)) : ro.crossNM(4, 1), si.bus(3))) ~ si.bus(2) : (si.block(2), si.bus(6)) : routing\nwith{\n    predelay = _ @ msasamps(30);\n    apfsec = apf(msasamps(4.771), 0.75) : apf(msasamps(3.595), 0.75) : apf(msasamps(12.73), 0.625) : apf(msasamps(9.307), 0.625);\n    loopsec(0) = apfMod(os.osc(0.10), msasamps(30.51), msasamps(4), 0.7) : _ @ msasamps(141.69) : (_ <: _, _) : (op(damp), _) :\n        (apf(msasamps(89.24), 0.5) <: _, _), _ : (_ @ (msasamps(106.28) - 1) <: _, mem), _, _ : (_ * decay, _, _, _) : (_, ro.cross(3));\n    loopsec(1) = apfMod(os.osc(0.07), msasamps(22.58), msasamps(4), 0.7) : _ @ msasamps(149.62) : (_ <: _, _) : (op(damp), _) :\n        (apf(msasamps(60.48), 0.5) <: _, _), _ : (_ @ (msasamps(125.00) - 1) <: _, mem), _, _ : (_ * decay, _, _, _) : (_, ro.cross(3));\n    routing(dA0, ap0, dB0, dA1, ap1, dB1) =\n        ((dA0 @ msasamps(8.90), dA0 @ msasamps(99.8), ap0 @ msasamps(64.2), dB0 @ msasamps(67), dA1 @ msasamps(66.8), ap1 @ msasamps(6.3), dB1 @ msasamps(35.8), 0) :> +),\n        ((dA0 @ msasamps(70.8), ap0 @ msasamps(11.2), dB0 @ msasamps(4.1), dA1 @ msasamps(11.8), dA1 @ msasamps(121.7), ap1 @ msasamps(41.2), dB1 @ msasamps(89.7), 0) :> +);\n};\nwet = _ <: greisingerReverb(decay, damp) :> *(0.5);\nprocess = _ <: *(1-mix), (wet : *(mix)) :> _;"
 },
 {
  "id": "lib-greyhole",
  "name": "Greyhole",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Diffuser in feedback with a long modulated delay - spacey, smeared washes (Eventide-inspired)",
  "description": "Diffuser in feedback with a long modulated delay - spacey, smeared washes (Eventide-inspired)",
  "author": "Till Bovermann, Julian Parker",
  "flags": "",
  "params": [
   {
    "label": "Delay Time",
    "min": 0.001,
    "max": 1.45,
    "default": 0.2,
    "step": 0.001,
    "unit": "s",
    "path": "/Greyhole/Delay_Time"
   },
   {
    "label": "Damping",
    "min": 0,
    "max": 0.99,
    "default": 0.2,
    "step": 0.001,
    "unit": "",
    "path": "/Greyhole/Damping"
   },
   {
    "label": "Size",
    "min": 0.5,
    "max": 3,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Greyhole/Size"
   },
   {
    "label": "Diffusion",
    "min": 0,
    "max": 0.99,
    "default": 0.5,
    "step": 0.001,
    "unit": "",
    "path": "/Greyhole/Diffusion"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 1,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/Greyhole/Feedback"
   },
   {
    "label": "Mod Depth",
    "min": 0,
    "max": 1,
    "default": 0.1,
    "step": 0.001,
    "unit": "",
    "path": "/Greyhole/Mod_Depth"
   },
   {
    "label": "Mod Rate",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Greyhole/Mod_Rate"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/Greyhole/Mix"
   }
  ],
  "faustCode": "declare name \"Greyhole\";\ndeclare description \"Diffuser in feedback with a long modulated delay - spacey, smeared washes (Eventide-inspired)\";\ndeclare author \"Till Bovermann, Julian Parker\";\ndeclare license \"GPL-2.0-or-later\";\ndeclare source \"grame-cncm/faustlibraries/reverbs.lib re.greyhole\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\ndt   = hslider(\"[0] Delay Time[unit:s]\", 0.2, 0.001, 1.45, 0.001) : si.smoo;\ndamp = hslider(\"[1] Damping\", 0.2, 0, 0.99, 0.001) : si.smoo;\nsize = hslider(\"[2] Size\", 1, 0.5, 3, 0.01);\ndiff = hslider(\"[3] Diffusion\", 0.5, 0, 0.99, 0.001) : si.smoo;\nfb   = hslider(\"[4] Feedback\", 0.7, 0, 1, 0.01) : si.smoo;\nmd   = hslider(\"[5] Mod Depth\", 0.1, 0, 1, 0.001) : si.smoo;\nmf   = hslider(\"[6] Mod Rate[unit:Hz]\", 2, 0, 10, 0.01) : si.smoo;\nmix  = hslider(\"[7] Mix\", 0.4, 0, 1, 0.01) : si.smoo;\n\nwet = _ <: re.greyhole(dt, damp, size, diff, fb, md, mf) :> *(0.5);\nprocess = _ <: *(1-mix), (wet : *(mix)) :> _;"
 },
 {
  "id": "lib-jcrev",
  "name": "JCRev Schroeder",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "John Chowning's classic Schroeder reverb (3 allpasses + 4 combs) - vintage computer-music hall",
  "description": "John Chowning's classic Schroeder reverb (3 allpasses + 4 combs) - vintage computer-music hall",
  "author": "Julius O. Smith III",
  "flags": "",
  "params": [
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/JCRev_Schroeder/Mix"
   },
   {
    "label": "Tone",
    "min": 1000,
    "max": 16000,
    "default": 6000,
    "step": 1,
    "unit": "Hz",
    "path": "/JCRev_Schroeder/Tone"
   }
  ],
  "faustCode": "declare name \"JCRev Schroeder\";\ndeclare description \"John Chowning's classic Schroeder reverb (3 allpasses + 4 combs) - vintage computer-music hall\";\ndeclare author \"Julius O. Smith III\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faustlibraries/reverbs.lib re.jcrev\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nmix = hslider(\"[0] Mix\", 0.3, 0, 1, 0.01) : si.smoo;\ntone = hslider(\"[1] Tone[unit:Hz][scale:log]\", 6000, 1000, 16000, 1) : si.smoo;\nwet = re.jcrev :> *(0.25) : fi.lowpass(1, tone);\nprocess = _ <: *(1-mix), (wet : *(mix)) :> _;"
 },
 {
  "id": "lib-jpverb",
  "name": "JPverb",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Julian Parker's lush algorithmic reverb with modulation and 3-band decay",
  "description": "Julian Parker's lush algorithmic reverb with modulation and 3-band decay",
  "author": "Till Bovermann, Julian Parker",
  "flags": "",
  "params": [
   {
    "label": "Decay",
    "min": 0.1,
    "max": 30,
    "default": 2,
    "step": 0.1,
    "unit": "s",
    "path": "/JPverb/Decay"
   },
   {
    "label": "High Band",
    "min": 1000,
    "max": 10000,
    "default": 2000,
    "step": 1,
    "unit": "Hz",
    "path": "/JPverb/High_Band"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/JPverb/Mix"
   },
   {
    "label": "Damping",
    "min": 0,
    "max": 0.999,
    "default": 0.2,
    "step": 0.001,
    "unit": "",
    "path": "/JPverb/Damping"
   },
   {
    "label": "Size",
    "min": 0.5,
    "max": 3,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/JPverb/Size"
   },
   {
    "label": "Early Diffusion",
    "min": 0,
    "max": 0.99,
    "default": 0.707,
    "step": 0.001,
    "unit": "",
    "path": "/JPverb/Early_Diffusion"
   },
   {
    "label": "Mod Depth",
    "min": 0,
    "max": 1,
    "default": 0.1,
    "step": 0.001,
    "unit": "",
    "path": "/JPverb/Mod_Depth"
   },
   {
    "label": "Mod Rate",
    "min": 0,
    "max": 10,
    "default": 2,
    "step": 0.01,
    "unit": "Hz",
    "path": "/JPverb/Mod_Rate"
   },
   {
    "label": "Low Decay X",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/JPverb/Low_Decay_X"
   },
   {
    "label": "Mid Decay X",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/JPverb/Mid_Decay_X"
   },
   {
    "label": "High Decay X",
    "min": 0,
    "max": 1,
    "default": 0.8,
    "step": 0.01,
    "unit": "",
    "path": "/JPverb/High_Decay_X"
   },
   {
    "label": "Low Band",
    "min": 100,
    "max": 6000,
    "default": 500,
    "step": 1,
    "unit": "Hz",
    "path": "/JPverb/Low_Band"
   }
  ],
  "faustCode": "declare name \"JPverb\";\ndeclare description \"Julian Parker's lush algorithmic reverb with modulation and 3-band decay\";\ndeclare author \"Till Bovermann, Julian Parker\";\ndeclare license \"GPL-2.0-or-later\";\ndeclare source \"grame-cncm/faustlibraries/reverbs.lib re.jpverb\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nt60   = hslider(\"[0] Decay[unit:s]\", 2, 0.1, 30, 0.1);\ndamp  = hslider(\"[1] Damping\", 0.2, 0, 0.999, 0.001) : si.smoo;\nsize  = hslider(\"[2] Size\", 1, 0.5, 3, 0.01);\nediff = hslider(\"[3] Early Diffusion\", 0.707, 0, 0.99, 0.001) : si.smoo;\nmd    = hslider(\"[4] Mod Depth\", 0.1, 0, 1, 0.001) : si.smoo;\nmf    = hslider(\"[5] Mod Rate[unit:Hz]\", 2, 0, 10, 0.01) : si.smoo;\nlow   = hslider(\"[6] Low Decay X\", 1, 0, 1, 0.01) : si.smoo;\nmid   = hslider(\"[7] Mid Decay X\", 1, 0, 1, 0.01) : si.smoo;\nhigh  = hslider(\"[8] High Decay X\", 0.8, 0, 1, 0.01) : si.smoo;\nlc    = hslider(\"[9] Low Band[unit:Hz]\", 500, 100, 6000, 1);\nhc    = hslider(\"[10] High Band[unit:Hz]\", 2000, 1000, 10000, 1);\nmix   = hslider(\"[11] Mix\", 0.35, 0, 1, 0.01) : si.smoo;\n\nwet = _ <: re.jpverb(t60, damp, size, ediff, md, mf, low, mid, high, lc, hc) :> *(0.5);\nprocess = _ <: *(1-mix), (wet : *(mix)) :> _;"
 },
 {
  "id": "luca-moorer",
  "name": "Moorer Reverb",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "L. Spanedda",
  "license": "MIT",
  "shortDesc": "James Moorer's 1979 reverb: 18-tap early reflections into 6 lowpass-feedback combs - classic natural-sounding room",
  "description": "James Moorer's 1979 reverb: 18-tap early reflections into 6 lowpass-feedback combs - classic natural-sounding room",
  "author": "Luca Spanedda",
  "flags": "",
  "params": [
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/Moorer_Reverb/Mix"
   },
   {
    "label": "Comb Feedback",
    "min": 0.3,
    "max": 0.9,
    "default": 0.7,
    "step": 0.01,
    "unit": "",
    "path": "/Moorer_Reverb/Comb_Feedback"
   },
   {
    "label": "Damping",
    "min": 0,
    "max": 0.9,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/Moorer_Reverb/Damping"
   }
  ],
  "faustCode": "declare name \"Moorer Reverb\";\ndeclare description \"James Moorer's 1979 reverb: 18-tap early reflections into 6 lowpass-feedback combs - classic natural-sounding room\";\ndeclare author \"Luca Spanedda\";\ndeclare license \"MIT\";\ndeclare source \"LucaSpanedda/Digital_Reverberation_in_Faust src/reverberation.lib moorerReverb\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nmix = hslider(\"[0] Mix\", 0.35, 0, 1, 0.01) : si.smoo;\nsize = hslider(\"[1] Comb Feedback\", 0.7, 0.3, 0.9, 0.01) : si.smoo;\ndamp = hslider(\"[2] Damping\", 0.4, 0, 0.9, 0.01) : si.smoo;\n\nsasamps(t) = int(ma.SR * t);\nlbcf(t, fb, dmp) = (+ : @ (max(0, (t - 1)))) ~ (_ * (1 - dmp) : + ~ * (dmp) : * (fb)) : mem;\nmoorerReverb = _ * 0.1 : earlyReflections <: combSection + _\nwith{\n    earlyReflections = _ <: (_ @ sasamps(0.0043)) * 0.841, (_ @ sasamps(0.0215)) * 0.504, (_ @ sasamps(0.0225)) * 0.491, (_ @ sasamps(0.0268)) * 0.379,\n        (_ @ sasamps(0.0270)) * 0.380, (_ @ sasamps(0.0298)) * 0.346, (_ @ sasamps(0.0458)) * 0.289, (_ @ sasamps(0.0485)) * 0.272,\n        (_ @ sasamps(0.0572)) * 0.192, (_ @ sasamps(0.0587)) * 0.193, (_ @ sasamps(0.0595)) * 0.217, (_ @ sasamps(0.0612)) * 0.181,\n        (_ @ sasamps(0.0707)) * 0.180, (_ @ sasamps(0.0708)) * 0.181, (_ @ sasamps(0.0726)) * 0.176, (_ @ sasamps(0.0741)) * 0.142,\n        (_ @ sasamps(0.0753)) * 0.167, (_ @ sasamps(0.0797)) * 0.134 :> _;\n    combSection = _ <: lbcf(sasamps(0.050), size, damp), lbcf(sasamps(0.056), size, damp), lbcf(sasamps(0.061), size, damp),\n        lbcf(sasamps(0.068), size, damp), lbcf(sasamps(0.072), size, damp), lbcf(sasamps(0.078), size, damp) :> _ * 0.3;\n};\nprocess = _ <: *(1-mix), (moorerReverb : *(3) : *(mix)) :> _;"
 },
 {
  "id": "gx-mbreverb",
  "name": "Multi-Band Reverb",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Five-band Freeverb with independent room size, damping and wet/dry per band.",
  "description": "Splits the signal at four adjustable crossovers and applies a separate Freeverb (RoomSize, Damp, wet/dry) to each band. Keeps the lows dry while the highs bloom.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "crossover b1 b2",
    "min": 20,
    "max": 20000,
    "default": 80,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Reverb/crossover_b1_b2"
   },
   {
    "label": "crossover b2 b3",
    "min": 20,
    "max": 20000,
    "default": 210,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Reverb/crossover_b2_b3"
   },
   {
    "label": "crossover b3 b4",
    "min": 20,
    "max": 20000,
    "default": 1700,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Reverb/crossover_b3_b4"
   },
   {
    "label": "crossover b4 b5",
    "min": 20,
    "max": 20000,
    "default": 5000,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Reverb/crossover_b4_b5"
   },
   {
    "label": "RoomSize1",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/MultiBand_Reverb/RoomSize1"
   },
   {
    "label": "damp1",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/MultiBand_Reverb/damp1"
   },
   {
    "label": "wet dry1",
    "min": 0,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Reverb/wet_dry1"
   },
   {
    "label": "RoomSize2",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/MultiBand_Reverb/RoomSize2"
   },
   {
    "label": "damp2",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/MultiBand_Reverb/damp2"
   },
   {
    "label": "wet dry2",
    "min": 0,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Reverb/wet_dry2"
   },
   {
    "label": "RoomSize3",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/MultiBand_Reverb/RoomSize3"
   },
   {
    "label": "damp3",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/MultiBand_Reverb/damp3"
   },
   {
    "label": "wet dry3",
    "min": 0,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Reverb/wet_dry3"
   },
   {
    "label": "RoomSize4",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/MultiBand_Reverb/RoomSize4"
   },
   {
    "label": "damp4",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/MultiBand_Reverb/damp4"
   },
   {
    "label": "wet dry4",
    "min": 0,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Reverb/wet_dry4"
   },
   {
    "label": "RoomSize5",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/MultiBand_Reverb/RoomSize5"
   },
   {
    "label": "damp5",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/MultiBand_Reverb/damp5"
   },
   {
    "label": "wet dry5",
    "min": 0,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Reverb/wet_dry5"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/mbreverb.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"mbe\";\ndeclare name \"MultiBand Reverb\";\ndeclare shortname \"MB Reverb\";\ndeclare category \"Reverb\";\ndeclare description \"Multi Band Reverb\";\n\nimport(\"stdfaust.lib\");\nrd = library(\"reducemaps.lib\");\n\nimport(\"guitarix.lib\");\n\nhifr1      =hslider(\"crossover_b1_b2 [log][name:Crossover B1-B2 (hz)][tooltip: Crossover fi.bandpass frequency]\" ,80 , 20, 20000, 1.08);\nhifr2      =hslider(\"crossover_b2_b3 [log][name:Crossover B2-B3 (hz)][tooltip: Crossover fi.bandpass frequency]\",210,20,20000,1.08);\nhifr3      =hslider(\"crossover_b3_b4 [log][name:Crossover B3-B4 (hz)][tooltip: Crossover fi.bandpass frequency]\",1700,20,20000,1.08);\nhifr4      =hslider(\"crossover_b4_b5 [log][name:Crossover B4-B5 (hz)][tooltip: Crossover fi.bandpass frequency]\",5000,20,20000,1.08);\n\ngeq = fi.filterbank(3, (hifr1,hifr2,hifr3,hifr4));\n\nvmeter1(x)\t\t= attach(x, envelop(x) : vbargraph(\"v1[nomidi:no]\", -70, +5));\nvmeter2(x)\t\t= attach(x, envelop(x) : vbargraph(\"v2[nomidi:no]\", -70, +5));\nvmeter3(x)\t\t= attach(x, envelop(x) : vbargraph(\"v3[nomidi:no]\", -70, +5));\nvmeter4(x)\t\t= attach(x, envelop(x) : vbargraph(\"v4[nomidi:no]\", -70, +5));\nvmeter5(x)\t\t= attach(x, envelop(x) : vbargraph(\"v5[nomidi:no]\", -70, +5));\n\nenvelop         = abs : max ~ (1.0/ma.SR) : rd.maxn(4096) ;\n//envelop         = abs : max ~ (1.0/ma.SR) : mean(4096) ; // : max(ba.db2linear(-70)) : ba.linear2db;\n\n/*-----------------------------------------------\n\t\tfreeverb  by \"Grame\"\n  -----------------------------------------------*/\n\nc1 \t= vslider(\"RoomSize1\", 0.5, 0, 1, 0.025)*0.28 + 0.7;\nd1 \t= vslider(\"damp1\",0.5, 0, 1, 0.025);\nwet1 = vslider(\"wet_dry1[name:wet/dry]\",  50, 0, 100, 1) : /(100);\ndry1 = 1 - wet1;\n\nc2 \t= vslider(\"RoomSize2\", 0.5, 0, 1, 0.025)*0.28 + 0.7;\nd2 \t= vslider(\"damp2\",0.5, 0, 1, 0.025);\nwet2 = vslider(\"wet_dry2[name:wet/dry]\",  50, 0, 100, 1) : /(100);\ndry2 = 1 - wet2;\n\nc3 \t= vslider(\"RoomSize3\", 0.5, 0, 1, 0.025)*0.28 + 0.7;\nd3 \t= vslider(\"damp3\",0.5, 0, 1, 0.025);\nwet3 = vslider(\"wet_dry3[name:wet/dry]\",  50, 0, 100, 1) : /(100);\ndry3 = 1 - wet3;\n\nc4 \t= vslider(\"RoomSize4\", 0.5, 0, 1, 0.025)*0.28 + 0.7;\nd4 \t= vslider(\"damp4\",0.5, 0, 1, 0.025);\nwet4 = vslider(\"wet_dry4[name:wet/dry]\",  50, 0, 100, 1) : /(100);\ndry4 = 1 - wet4;\n\nc5 \t= vslider(\"RoomSize5\", 0.5, 0, 1, 0.025)*0.28 + 0.7;\nd5 \t= vslider(\"damp5\",0.5, 0, 1, 0.025);\nwet5 = vslider(\"wet_dry5[name:wet/dry]\",  50, 0, 100, 1) : /(100);\ndry5 = 1 - wet5;\n\n// Filter Parameters\n\ncombtuningL1\t= 1116;\ncombtuningL2\t= 1188;\ncombtuningL3\t= 1277;\ncombtuningL4\t= 1356;\ncombtuningL5\t= 1422;\ncombtuningL6\t= 1491;\ncombtuningL7\t= 1557;\ncombtuningL8\t= 1617;\n\nallpasstuningL1\t= 556;\nallpasstuningL2\t= 441;\nallpasstuningL3\t= 341;\nallpasstuningL4\t= 225;\n\n// Reverb components\n\nmonoReverb(fb1, fb2, damp, spread)\n\t= _ <:\tcomb(combtuningL1+spread, fb1, damp),\n\t\t\tcomb(combtuningL2+spread, fb1, damp),\n\t\t\tcomb(combtuningL3+spread, fb1, damp),\n\t\t\tcomb(combtuningL4+spread, fb1, damp),\n\t\t\tcomb(combtuningL5+spread, fb1, damp),\n\t\t\tcomb(combtuningL6+spread, fb1, damp),\n\t\t\tcomb(combtuningL7+spread, fb1, damp),\n\t\t\tcomb(combtuningL8+spread, fb1, damp)\n\t\t+>\n\t\t \tallpass (allpasstuningL1+spread, fb2)\n\t\t:\tallpass (allpasstuningL2+spread, fb2)\n\t\t:\tallpass (allpasstuningL3+spread, fb2)\n\t\t:\tallpass (allpasstuningL4+spread, fb2)\n\t\t;\n\n//----------------------------------------------------------------\n\nfxctrl(g,w,Fx) =  _ <: (*(g) <: _ + Fx ), *(1-w) +> _;\nreverb(dry, wet_dry, combfeed, dampslider) = _<:*(dry),(*(wet_dry):fxctrl(0.015,wet_dry, monoReverb(combfeed, 0.5, dampslider, 23))):>_;\n\nprocess    = geq: ( dist5s , dist4s , dist3s, dist2s, dist1s) :>_ with { \n    dist1s = reverb(dry1,wet1,c1,d1) : vmeter1 ;\n    dist2s = reverb(dry2,wet2,c2,d2) : vmeter2;\n    dist3s = reverb(dry3,wet3,c3,d3) : vmeter3;\n    dist4s = reverb(dry4,wet4,c4,d4) : vmeter4;\n    dist5s = reverb(dry5,wet5,c5,d5) : vmeter5;\n    \n};"
 },
 {
  "id": "tdg-freeverb3",
  "name": "Progenitor",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Port of Freeverb3's Progenitor (Dattorro-style nested allpass tank) with chorus, definition and 3 decay stages. Author notes it can be unstable at extreme settings",
  "description": "Port of Freeverb3's Progenitor (Dattorro-style nested allpass tank) with chorus, definition and 3 decay stages. Author notes it can be unstable at extreme settings",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Chorus",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Progenitor/Chorus"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/Progenitor/Dry_Wet"
   },
   {
    "label": "Definition",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Progenitor/Definition"
   },
   {
    "label": "Decay 1",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Progenitor/Decay_1"
   },
   {
    "label": "Decay 2",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Progenitor/Decay_2"
   },
   {
    "label": "Decay 3",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Progenitor/Decay_3"
   },
   {
    "label": "Diffusion 1",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Progenitor/Diffusion_1"
   },
   {
    "label": "Diffusion 2",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Progenitor/Diffusion_2"
   },
   {
    "label": "Decay Diffusion",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Progenitor/Decay_Diffusion"
   },
   {
    "label": "Damping",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Progenitor/Damping"
   },
   {
    "label": "HF Bandwidth",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Progenitor/HF_Bandwidth"
   }
  ],
  "faustCode": "declare name \"Progenitor\";\ndeclare description \"Port of Freeverb3's Progenitor (Dattorro-style nested allpass tank) with chorus, definition and 3 decay stages. Author notes it can be unstable at extreme settings\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust freeverb3.dsp\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nchorus      = hslider(\"[0] Chorus\", 0.5, 0, 1, 0.01) : si.smoo;\ndefinition  = hslider(\"[1] Definition\", 0.5, 0, 1, 0.01) : si.smoo : *(0.25);\ndecay1      = hslider(\"[2] Decay 1\", 0.5, 0, 1, 0.01) : si.smoo : *(0.938);\ndecay2      = hslider(\"[3] Decay 2\", 0.5, 0, 1, 0.01) : si.smoo : *(0.844);\ndecay3      = hslider(\"[4] Decay 3\", 0.5, 0, 1, 0.01) : si.smoo : *(0.906);\ndiffusion1  = hslider(\"[5] Diffusion 1\", 0.5, 0, 1, 0.01) : si.smoo : *(0.312);\ndiffusion2  = hslider(\"[6] Diffusion 2\", 0.5, 0, 1, 0.01) : si.smoo : *(0.375);\ndecay_diff  = hslider(\"[7] Decay Diffusion\", 0.5, 0, 1, 0.01) : si.smoo : *(0.406);\ndamping     = hslider(\"[8] Damping\", 0.5, 0, 1, 0.01) : si.smoo : *(0.312);\nhf_bw       = hslider(\"[9] HF Bandwidth\", 0.5, 0, 1, 0.01) : si.smoo : *(0.188);\ndry_wet     = hslider(\"[10] Dry/Wet\", 0.4, 0, 1, 0.01) : si.smoo;\n\nX = (_,_) <: (!,_,_,!);\nopf(a) = (_+_*(1-a) ~ @(1)*a);\nozf(b) = _ <: (@(1):_*(1-b)), _*b :> _;\nn_ap(dt,c1,c2,next) = (_+_ <: (next:@(dt)), _*-c1) ~ _*c1 : _*c2, _ :> _;\nleft_branch = (opf(hf_bw):@(1):_*0.5), (_ <: ((opf(0.875):_*0.156), _*0.344)) :> opf(damping) :\n    n_ap(239,diffusion2,decay2,_) : @(2) : n_ap(392,diffusion1,decay3,_) <: @(1055),_ :\n    n_ap(612,decay_diff,decay2,n_ap(1944,definition,decay1,_)),_ : @(344),_ :\n    n_ap(1264,decay_diff,decay2,n_ap(816,definition,decay1,n_ap(1212,definition,0.938,@(121):ozf(chorus*0.781)))),_ : @(1572),_;\nright_branch = (opf(hf_bw):@(1):_*0.5), (_ <: ((opf(0.875):_*0.156), _*0.344)) :> opf(damping) :\n    n_ap(205,diffusion2,decay2,_) : @(1) : n_ap(329,diffusion1,decay3,_) <: @(625),_ : @(835),_ :\n    n_ap(368,decay_diff,decay2,n_ap(2032,definition,decay1,_)),_ : @(500),_ :\n    n_ap(1340,decay_diff,decay2,n_ap(688,definition,decay1,n_ap(1452,definition,0.938,@(5):ozf(chorus*0.188)))),_ : @(16),_;\nfreeverb3 = _,_ : (_,X,_ : (X:left_branch),(X:right_branch) : _,X,_) ~ X :> _,_;\nprocess = _ <: _, (_ <: freeverb3 :> *(0.5)) : (_*(1-dry_wet) + _*dry_wet);"
 },
 {
  "id": "tdg-room-simulator",
  "name": "Room Simulator",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Gardner nested-allpass room reverbs (small/medium/large) with continuous morph between room sizes and pre-delay",
  "description": "Gardner nested-allpass room reverbs (small/medium/large) with continuous morph between room sizes and pre-delay",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Predelay",
    "min": 1,
    "max": 200,
    "default": 20,
    "step": 1,
    "unit": "ms",
    "path": "/Room_Simulator/Predelay"
   },
   {
    "label": "Room Size",
    "min": 0,
    "max": 2,
    "default": 1,
    "step": 0.05,
    "unit": "",
    "path": "/Room_Simulator/Room_Size"
   },
   {
    "label": "Reverb Time",
    "min": 0,
    "max": 0.9,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Room_Simulator/Reverb_Time"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/Room_Simulator/Dry_Wet"
   }
  ],
  "faustCode": "declare name \"Room Simulator\";\ndeclare description \"Gardner nested-allpass room reverbs (small/medium/large) with continuous morph between room sizes and pre-delay\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust room_simulator.dsp\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\np_predelay = hslider(\"[0] Predelay[unit:ms]\", 20, 1, 200, 1);\np_rsize    = hslider(\"[1] Room Size\", 1, 0, 2, 0.05) : si.smoo;\np_rt       = hslider(\"[2] Reverb Time\", 0.3, 0, 0.9, 0.01) : si.smoo;\np_drw      = hslider(\"[3] Dry/Wet\", 0.4, 0, 1, 0.01) : si.smoo;\n\nms2sps(ms) = int(ms*ma.SR/1000);\nmix2(c,x,y) = (1-c)*x + c*y;\nmix3(val) = _,_,_ <: select3(int(val)), select3(min(2,int(val)+1)) : mix2(val-floor(val));\nopf(a) = (_+_*(1-a) ~ @(1)*a);\nallpass(dt,fb,f_nest) = (+ <: (de.delay(maxdel,dt-1):f_nest),*(fb)) ~ *(-fb) : mem,_ : + with { maxdel = 8192; };\nsn_allpass(dt1,dt2,fb1,fb2) = allpass(dt1,fb1,allpass(dt2,fb2,_));\ndn_allpass(dt1,dt2,dt3,fb1,fb2,fb3) = allpass(dt1,fb1,allpass(dt2,fb2,allpass(dt3,fb3,_)));\nsmall_room(rt,hf_damping) = fi.lowpass(4,6000) :\n    ((_,_ :> @(ms2sps(24)) : dn_allpass(ms2sps(35),ms2sps(22),ms2sps(8.3),0.15,0.25,0.3) <: sn_allpass(ms2sps(66),ms2sps(30),0.08,0.3),_)\n    ~ (_*0.99 : fi.highpass(2,800) : fi.lowpass(2,1600) : _*rt : opf(hf_damping))) : _*0.5,_*0.5 :> _;\nmedium_room(rt,hf_damping,x) = x : fi.lowpass(4,6000) :\n    ((_,_ :> dn_allpass(ms2sps(35),ms2sps(8.3),ms2sps(22),0.25,0.35,0.45) <: @(ms2sps(5)),_*0.5 : allpass(ms2sps(30),0.45,_),_ : (@(ms2sps(67)) <: _,_*0.5),_ :\n    (@(ms2sps(15)) : _*rt),_+_ : (_*0.4 : _+x : sn_allpass(ms2sps(39),ms2sps(9.8),0.25,0.35)),_)\n    ~ (fi.highpass(2,500) : fi.lowpass(2,1000) : opf(hf_damping) : _*rt : _*1.299)) : _*0.5,_ : _+_;\nlarge_room(rt,hf_damping) = fi.lowpass(4,4000) :\n    ((_,_ :> allpass(ms2sps(8),0.3,_) : allpass(ms2sps(12),0.3,_) : @(ms2sps(4)) <: _,_*1.5 : ((@(ms2sps(17)) : sn_allpass(ms2sps(87),ms2sps(62),0.5,0.25) : @(ms2sps(31)) <: _,_*0.8),_ : _,_+_) :\n    ((@(ms2sps(3)) : dn_allpass(ms2sps(120),ms2sps(76),ms2sps(30),0.5,0.25,0.25)),_))\n    ~ (_*0.5 : _*rt : opf(hf_damping) : fi.highpass(2,500) : fi.lowpass(2,1000) : _*1.299)) : _+_*0.8;\nprocess = _ <: (de.fdelay(16384, ms2sps(p_predelay)) <: small_room(p_rt, 0), medium_room(p_rt, 0), large_room(p_rt, 0) : mix3(p_rsize)), _ : mix2(1 - p_drw);"
 },
 {
  "id": "tdg-shimmer",
  "name": "Shimmer",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "ValhallaShimmer-inspired reverb: modulated nested allpass diffusers with pitch-shifted feedback path (envelope/LFO controllable shift)",
  "description": "ValhallaShimmer-inspired reverb: modulated nested allpass diffusers with pitch-shifted feedback path (envelope/LFO controllable shift)",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Envelope",
    "min": 0.1,
    "max": 3,
    "default": 1,
    "step": 0.05,
    "unit": "s",
    "path": "/Shimmer/Envelope"
   },
   {
    "label": "LFO Speed",
    "min": 0.1,
    "max": 10,
    "default": 0.1,
    "step": 0.05,
    "unit": "Hz",
    "path": "/Shimmer/LFO_Speed"
   },
   {
    "label": "Mod Depth",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.05,
    "unit": "",
    "path": "/Shimmer/Mod_Depth"
   },
   {
    "label": "Env/LFO",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.05,
    "unit": "",
    "path": "/Shimmer/Env_LFO"
   },
   {
    "label": "Shift",
    "min": -12,
    "max": 12,
    "default": 12,
    "step": 0.1,
    "unit": "semi",
    "path": "/Shimmer/Shift"
   },
   {
    "label": "Size",
    "min": 1,
    "max": 3,
    "default": 1.5,
    "step": 0.05,
    "unit": "",
    "path": "/Shimmer/Size"
   },
   {
    "label": "Diffusion",
    "min": 0.1,
    "max": 0.7,
    "default": 0.5,
    "step": 0.05,
    "unit": "",
    "path": "/Shimmer/Diffusion"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.35,
    "default": 0.25,
    "step": 0.01,
    "unit": "",
    "path": "/Shimmer/Feedback"
   },
   {
    "label": "HF Damping",
    "min": 0.005,
    "max": 0.995,
    "default": 0.3,
    "step": 0.005,
    "unit": "",
    "path": "/Shimmer/HF_Damping"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.05,
    "unit": "",
    "path": "/Shimmer/Dry_Wet"
   }
  ],
  "faustCode": "declare name \"Shimmer\";\ndeclare description \"ValhallaShimmer-inspired reverb: modulated nested allpass diffusers with pitch-shifted feedback path (envelope/LFO controllable shift)\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust shimmer.dsp\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nenvelope   = hslider(\"[0] Envelope[unit:s]\", 1, 0.1, 3, 0.05);\nspeed      = hslider(\"[1] LFO Speed[unit:Hz]\", 0.1, 0.1, 10, 0.05);\ndepth      = hslider(\"[2] Mod Depth\", 0, 0, 1, 0.05) : si.smoo;\nctrl       = hslider(\"[3] Env/LFO\", 0.5, 0, 1, 0.05) : si.smoo;\nshift      = hslider(\"[4] Shift[unit:semi]\", 12, -12, 12, 0.1) : si.smoo : *(2);\nsize       = hslider(\"[5] Size\", 1.5, 1, 3, 0.05);\ndiffusion  = hslider(\"[6] Diffusion\", 0.5, 0.1, 0.7, 0.05) : si.smoo;\nfeedback   = hslider(\"[7] Feedback\", 0.25, 0, 0.35, 0.01) : si.smoo;\nhf_damping = hslider(\"[8] HF Damping\", 0.3, 0.005, 0.995, 0.005) : si.smoo;\ndry_wet    = hslider(\"[9] Dry/Wet\", 0.5, 0, 1, 0.05) : si.smoo;\n\nmixer(mix) = _*(1 - mix), _*mix :> _;\nc_folower_colibration = 6;\nparametric_controller(mix, envelope_t, freq, dp) = (an.amp_follower(envelope_t) : _*c_folower_colibration : _*dp, os.osc(freq)*0.5 : _, _*dp) : mixer(mix) : _+0.5;\nX = (_,_) <: (!,_,_,!);\nopf(a) = (_+_*(1-a) ~ @(1)*a);\nallpass_with_fdelay(dt1,coef,dt2,dt2pos) = (_,_ <: (*(coef),_:+:@(dt1):de.fdelay(dt2,dt2pos)), -) ~ _ : (!,_);\nallpass(dt,fb) = (_,_ <: (*(fb),_:+:@(dt)), -) ~ _ : (!,_);\nAPFB(dt1,fb1,dtv,dtvpos,dt2,fb2) = allpass_with_fdelay(dt1,fb1,dtv,dtvpos) : allpass(dt2,fb2);\nc_samples = 2048; c_xfade = 1024;\nsh(x) = x : parametric_controller(ctrl, envelope, speed, depth) : _*shift;\ncore(x,y) = x,y : (_,_ :\n    (_,X,_ : (\n    (_*feedback+_*0.3 :> APFB(601*size,0.7*diffusion,50,49*(os.osc(1)+1)/2,613*size,0.75*diffusion) : opf(hf_damping)),\n    (_*feedback+_*0.3 :> APFB(2043*size,0.75*diffusion,50,49*(os.osc(1.5)+1)/2,2087*size,0.75*diffusion) : opf(hf_damping))\n    ) : X) ~ (\n    (_*feedback : fi.dcblockerat(80) : @(4325) : APFB(2337*size,0.7*diffusion,50,49*(os.osc(0.7)+1)/2,2377*size,0.4*diffusion) : @(2969) : ef.transpose(c_samples,c_xfade,sh(x))),\n    (_*feedback : fi.dcblockerat(80) : @(4763) : APFB(1087*size,0.7*diffusion,50,49*(os.osc(1.3)+1)/2,1113*size,0.4*diffusion) : @(3111) : ef.transpose(c_samples,c_xfade,sh(y)))));\nprocess(x) = core(x,x) :> *(0.5) <: mixer(dry_wet, x, _);"
 },
 {
  "id": "tdg-shimmizita",
  "name": "Shimmizita",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Zita-rev1 FDN with a pitch shifter inside each of the 8 feedback lines - shimmer reverb whose shift can be envelope/LFO driven",
  "description": "Zita-rev1 FDN with a pitch shifter inside each of the 8 feedback lines - shimmer reverb whose shift can be envelope/LFO driven",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "LF Crossover",
    "min": 50,
    "max": 1000,
    "default": 200,
    "step": 1,
    "unit": "Hz",
    "path": "/Shimmizita/LF_Crossover"
   },
   {
    "label": "Shift Amount",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.05,
    "unit": "",
    "path": "/Shimmizita/Shift_Amount"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.05,
    "unit": "",
    "path": "/Shimmizita/Dry_Wet"
   },
   {
    "label": "Low RT60",
    "min": 1,
    "max": 8,
    "default": 3,
    "step": 0.1,
    "unit": "s",
    "path": "/Shimmizita/Low_RT60"
   },
   {
    "label": "Mid RT60",
    "min": 1,
    "max": 8,
    "default": 2,
    "step": 0.1,
    "unit": "s",
    "path": "/Shimmizita/Mid_RT60"
   },
   {
    "label": "HF Damping",
    "min": 1500,
    "max": 20000,
    "default": 6000,
    "step": 1,
    "unit": "Hz",
    "path": "/Shimmizita/HF_Damping"
   },
   {
    "label": "Shift",
    "min": -12,
    "max": 12,
    "default": 12,
    "step": 0.1,
    "unit": "semi",
    "path": "/Shimmizita/Shift"
   },
   {
    "label": "Mode",
    "min": -3,
    "max": 3,
    "default": 0,
    "step": 0.05,
    "unit": "",
    "path": "/Shimmizita/Mode"
   },
   {
    "label": "Envelope",
    "min": 0.1,
    "max": 3,
    "default": 1,
    "step": 0.05,
    "unit": "s",
    "path": "/Shimmizita/Envelope"
   },
   {
    "label": "Env/LFO",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.05,
    "unit": "",
    "path": "/Shimmizita/Env_LFO"
   },
   {
    "label": "LFO Speed",
    "min": 0.1,
    "max": 10,
    "default": 0.1,
    "step": 0.05,
    "unit": "Hz",
    "path": "/Shimmizita/LFO_Speed"
   },
   {
    "label": "Mod Depth",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.05,
    "unit": "",
    "path": "/Shimmizita/Mod_Depth"
   }
  ],
  "faustCode": "declare name \"Shimmizita\";\ndeclare description \"Zita-rev1 FDN with a pitch shifter inside each of the 8 feedback lines - shimmer reverb whose shift can be envelope/LFO driven\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust shimmizita.dsp + shimmizita.inc (zita_rev_fdn by JOS)\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nf1       = hslider(\"[0] LF Crossover[unit:Hz]\", 200, 50, 1000, 1);\nt60dc    = hslider(\"[1] Low RT60[unit:s]\", 3, 1, 8, 0.1);\nt60m     = hslider(\"[2] Mid RT60[unit:s]\", 2, 1, 8, 0.1);\nf2       = hslider(\"[3] HF Damping[unit:Hz]\", 6000, 1500, 20000, 1);\nshift    = hslider(\"[4] Shift[unit:semi]\", 12, -12, 12, 0.1) : si.smoo;\nmode     = hslider(\"[5] Mode\", 0, -3, 3, 0.05) : si.smoo;\nenvelope = hslider(\"[6] Envelope[unit:s]\", 1, 0.1, 3, 0.05);\nctrl     = hslider(\"[7] Env/LFO\", 0.5, 0, 1, 0.05) : si.smoo;\nspeed    = hslider(\"[8] LFO Speed[unit:Hz]\", 0.1, 0.1, 10, 0.05);\ndepth    = hslider(\"[9] Mod Depth\", 0, 0, 1, 0.05) : si.smoo;\nps_dw    = hslider(\"[10] Shift Amount\", 0.5, 0, 1, 0.05) : si.smoo;\ndry_wet  = hslider(\"[11] Dry/Wet\", 0.4, 0, 1, 0.05) : si.smoo;\nfsmax = 48000.0;\n\npar_ps(sh, env_t, c, freq, dep, dw) = _ <: _, (_ <: parametric_controller(c, env_t, freq, dep)*sh, _ : ef.transpose(c_samples, c_xfade)) : mixer(dw)\nwith {\n    c_samples = 2048; c_xfade = 1024; c_folower_colibration = 6;\n    parametric_controller(mix, envelope_t, fr, dp) = (an.amp_follower(envelope_t) : _*c_folower_colibration : _*dp, os.osc(fr)*0.5 : _, _*dp) : mixer(mix) : _+0.5;\n    mixer(mix) = _*(1 - mix), _*mix :> _;\n};\nshimmizita_rev_fdn(f1,f2,t60dc,t60m, mode, shift,envelope,ctl,freq,depth,dry_wet, fsmax) =\n  ((si.bus(2*N) :> allpass_combs(N) : feedbackmatrix(N)) ~ (delayfilters(N,freqs,durs) : pitchshifters(N) : fbdelaylines(N)))\nwith {\n  N = 8;\n  apdelays = (0.020346, 0.024421, 0.031604, 0.027333, 0.022904, 0.029291, 0.013458, 0.019123);\n  tdelays = ( 0.153129, 0.210389, 0.127837, 0.256891, 0.174713, 0.192303, 0.125000, 0.219991);\n  tdelay(i) = floor(0.5 + ma.SR*ba.take(i+1,tdelays));\n  apdelay(i) = floor(0.5 + ma.SR*ba.take(i+1,apdelays));\n  fbdelay(i) = tdelay(i) - apdelay(i);\n  tdelaymaxfs(i) = floor(0.5 + fsmax*ba.take(i+1,tdelays));\n  apdelaymaxfs(i) = floor(0.5 + fsmax*ba.take(i+1,apdelays));\n  fbdelaymaxfs(i) = tdelaymaxfs(i) - apdelaymaxfs(i);\n  nextpow2(x) = ceil(log(x)/log(2.0));\n  maxapdelay(i) = int(2.0^max(1.0,nextpow2(apdelaymaxfs(i))));\n  maxfbdelay(i) = int(2.0^max(1.0,nextpow2(fbdelaymaxfs(i))));\n  apcoeff(i) = select2(i&1,0.6,-0.6);\n  allpass_combs(N) = par(i,N,(fi.allpass_comb(maxapdelay(i),apdelay(i),apcoeff(i))));\n  fbdelaylines(N) = par(i,N,(de.delay(maxfbdelay(i),(fbdelay(i)))));\n  shiftcoefs_m1 = (1/2,1/3,1/2,1/4,1/2,1/8,1/2,1/3);\n  shiftcoefs_m2 = (1/5,-1/2,1/3,-1/2,1/6,-1/3,1/3,1/2);\n  shiftdunc(i, sh, md) = md <: _>=0, _<0 : ((_*(sh+sh*md*ba.take(i+1,shiftcoefs_m1))), (_*(sh+sh*md*ba.take(i+1,shiftcoefs_m2)))) :> _;\n  pitchshifters(N) = par(i, N, par_ps(shiftdunc(i, shift, mode), envelope, ctl, freq, depth, dry_wet));\n  freqs = (f1,f2); durs = (t60dc,t60m);\n  delayfilters(N,freqs,durs) = par(i,N,filter(i,freqs,durs));\n  feedbackmatrix(N) = ro.hadamard(N);\n  staynormal = 10.0^(-20);\n  special_lowpass(g,f) = si.smooth(p) with {\n    p = mbo2 - sqrt(max(0,mbo2*mbo2 - 1.0));\n    mbo2 = (1.0 - gs*c)/(1.0 - gs);\n    gs = g*g;\n    c = cos(2.0*ma.PI*f/float(ma.SR));\n  };\n  filter(i,freqs,durs) = lowshelf_lowpass(i)/sqrt(float(N))+staynormal\n  with {\n    lowshelf_lowpass(i) = gM*fi.low_shelf1_l(g0/gM,f(1)) : special_lowpass(gM,f(2));\n    g0 = g(0,i); gM = g(1,i);\n    f(k) = ba.take(k,freqs);\n    dur(j) = ba.take(j+1,durs);\n    n60(j) = dur(j)*ma.SR;\n    g(j,i) = exp(-3.0*log(10.0)*tdelay(i)/n60(j));\n  };\n};\nwet = _ <: si.bus(8) : shimmizita_rev_fdn(f1,f2,t60dc,t60m, mode, shift, envelope, ctrl, speed, depth, ps_dw, fsmax) :> *(0.25);\nprocess = _ <: *(1-dry_wet), (wet : *(dry_wet)) :> _;"
 },
 {
  "id": "lib-kb-rom-rev1",
  "name": "Spin ROM Reverb",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "GPL-3.0-only",
  "shortDesc": "Keith Barr's Spin Semiconductor rom_rev1 allpass-loop reverb - classic FV-1 pedal tail",
  "description": "Keith Barr's Spin Semiconductor rom_rev1 allpass-loop reverb - classic FV-1 pedal tail",
  "author": "Luca Spanedda (Faust port), Keith Barr",
  "flags": "",
  "params": [
   {
    "label": "Reverb Time",
    "min": 0,
    "max": 0.95,
    "default": 0.6,
    "step": 0.001,
    "unit": "",
    "path": "/Spin_ROM_Reverb/Reverb_Time"
   },
   {
    "label": "Damping",
    "min": 0,
    "max": 0.99,
    "default": 0.3,
    "step": 0.001,
    "unit": "",
    "path": "/Spin_ROM_Reverb/Damping"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/Spin_ROM_Reverb/Mix"
   }
  ],
  "faustCode": "declare name \"Spin ROM Reverb\";\ndeclare description \"Keith Barr's Spin Semiconductor rom_rev1 allpass-loop reverb - classic FV-1 pedal tail\";\ndeclare author \"Luca Spanedda (Faust port), Keith Barr\";\ndeclare license \"GPL-3.0-only\";\ndeclare source \"grame-cncm/faustlibraries/reverbs.lib re.kb_rom_rev1\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nrt   = hslider(\"[0] Reverb Time\", 0.6, 0, 0.95, 0.001) : si.smoo;\ndamp = hslider(\"[1] Damping\", 0.3, 0, 0.99, 0.001) : si.smoo;\nmix  = hslider(\"[2] Mix\", 0.4, 0, 1, 0.01) : si.smoo;\n\nwet = _ <: re.kb_rom_rev1(rt, damp) :> *(0.5);\nprocess = _ <: *(1-mix), (wet : *(mix)) :> _;"
 },
 {
  "id": "lib-springreverb",
  "name": "Spring Tank",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "Spring-flavoured reverb (Chaos Audio Stratus): diffusion into damped delay bank with Hadamard feedback",
  "description": "Spring-flavoured reverb (Chaos Audio Stratus): diffusion into damped delay bank with Hadamard feedback",
  "author": "Daniel Leonov",
  "flags": "",
  "params": [
   {
    "label": "Dwell",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Spring_Tank/Dwell"
   },
   {
    "label": "Blend",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Spring_Tank/Blend"
   },
   {
    "label": "Tone",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Spring_Tank/Tone"
   },
   {
    "label": "Tension",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Spring_Tank/Tension"
   },
   {
    "label": "Springs",
    "min": 0,
    "max": 2,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Spring_Tank/Springs"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Spring_Tank/Mix"
   }
  ],
  "faustCode": "declare name \"Spring Tank\";\ndeclare description \"Spring-flavoured reverb (Chaos Audio Stratus): diffusion into damped delay bank with Hadamard feedback\";\ndeclare author \"Daniel Leonov\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faustlibraries/reverbs.lib re.springreverb\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\ndwell   = hslider(\"[0] Dwell\", 0.5, 0, 1, 0.01) : si.smoo;\nblend   = hslider(\"[1] Blend\", 0.5, 0, 1, 0.01) : si.smoo;\ntone    = hslider(\"[2] Tone\", 0.5, 0, 1, 0.01) : si.smoo;\ntension = hslider(\"[3] Tension\", 0.5, 0, 1, 0.01) : si.smoo;\nsprings = nentry(\"[4] Springs[style:menu{'Left':0;'Right':1;'Middle':2}]\", 1, 0, 2, 1);\nmix     = hslider(\"[5] Mix\", 0.5, 0, 1, 0.01) : si.smoo;\n\nprocess = _ <: *(1-mix), (re.springreverb(dwell, blend, tone, tension, springs) : *(mix)) :> _;"
 },
 {
  "id": "gx-stereoverb",
  "name": "Stereo Verb",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Freeverb with an LFO-modulated stereo spread, summed to mono here.",
  "description": "Freeverb (RoomSize, Damp, wet/dry) with an LFO that modulates the stereo image; wrapped to mono for the pedal, so the LFO adds subtle movement rather than width.",
  "author": "brummer",
  "flags": "-double",
  "params": [
   {
    "label": "RoomSize",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/Stereo_Verb/RoomSize"
   },
   {
    "label": "damp",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.025,
    "unit": "",
    "path": "/Stereo_Verb/damp"
   },
   {
    "label": "wet dry",
    "min": 0,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/Stereo_Verb/wet_dry"
   },
   {
    "label": "LFO freq",
    "min": 0,
    "max": 5,
    "default": 0.2,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Stereo_Verb/LFO_freq"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/stereoverb.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \t\t\"Stereo Verb\";\ndeclare category        \"Reverb\";\ndeclare version \t\"0.01\";\ndeclare author \t\t\"brummer\";\ndeclare license \t\"BSD\";\ndeclare copyright \t\"(c)brummer 2008\";\n\nimport(\"stdfaust.lib\");\n\nimport(\"guitarix.lib\");\n\n/*-----------------------------------------------\n\t\tfreeverb  by \"Grame\"\n  -----------------------------------------------*/\n\n// Filter Parameters\n\ncombtuningL1\t= 1116;\ncombtuningL2\t= 1188;\ncombtuningL3\t= 1277;\ncombtuningL4\t= 1356;\ncombtuningL5\t= 1422;\ncombtuningL6\t= 1491;\ncombtuningL7\t= 1557;\ncombtuningL8\t= 1617;\n\nallpasstuningL1\t= 556;\nallpasstuningL2\t= 441;\nallpasstuningL3\t= 341;\nallpasstuningL4\t= 225;\n\nroomsizeSlider \t= vslider(\"RoomSize\", 0.5, 0, 1, 0.025)*0.28 + 0.7;\ndampslider \t= vslider(\"damp\",0.5, 0, 1, 0.025);\ncombfeed \t= roomsizeSlider;\n//wetslider \t= 0.5 + vslider(\"wet_dry[name:wet/dry]\", 0, -0.5, 0.5, 0.1);\nwet_dry = vslider(\"wet_dry[name:wet/dry]\",  50, 0, 100, 1) : /(100);\ndry = 1 - wet_dry;\n\n// Reverb components\n\nmonoReverb(fb1, fb2, damp, spread)\n\t= _ <:\tcomb(combtuningL1+spread, fb1, damp),\n\t\t\tcomb(combtuningL2+spread, fb1, damp),\n\t\t\tcomb(combtuningL3+spread, fb1, damp),\n\t\t\tcomb(combtuningL4+spread, fb1, damp),\n\t\t\tcomb(combtuningL5+spread, fb1, damp),\n\t\t\tcomb(combtuningL6+spread, fb1, damp),\n\t\t\tcomb(combtuningL7+spread, fb1, damp),\n\t\t\tcomb(combtuningL8+spread, fb1, damp)\n\t\t+>\n\t\t \tallpass (allpasstuningL1+spread, fb2)\n\t\t:\tallpass (allpasstuningL2+spread, fb2)\n\t\t:\tallpass (allpasstuningL3+spread, fb2)\n\t\t:\tallpass (allpasstuningL4+spread, fb2)\n\t\t;\n\n//----------------------------------------------------------------\n\nlfol = os.oscrs; // sine for left channel\n\nfreq\t = hslider(\"LFO freq [unit:Hz]\", 0.2, 0, 5, 0.01);\npingpong   = checkbox(\"invert[enum:linear|pingpong]\");\n\nfxctrl(g,w,Fx) =  _ <: (*(g) <: _ + Fx ), *(1-w) +> _;\n\nfreeverb_r = (_<:*(dry),(*(wet_dry):fxctrl(0.015,wet_dry, monoReverb(combfeed, 0.5, dampslider, 23))* (1-(lfol(freq)*pingpong))):>_);\nfreeverb_l = (_<:*(dry),(*(wet_dry):fxctrl(0.015,wet_dry, monoReverb(combfeed, 0.5, dampslider, 23))* (1-(-1*lfol(freq)*pingpong))):>_);\nprocess_wide = freeverb_r, freeverb_l;\n\n// mono wrapper added by the Chameleon port (pedal is mono in / mono out)\nprocess = _ <: process_wide :> *(0.5);"
 },
 {
  "id": "lib-vital-rev",
  "name": "Vital Reverb",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "GPL-3.0-only",
  "shortDesc": "Matt Tytel's Vital synth reverb: pre-filter, shelving, chorused FDN tail",
  "description": "Matt Tytel's Vital synth reverb: pre-filter, shelving, chorused FDN tail",
  "author": "David Braun (Faust port), Matt Tytel (Vital)",
  "flags": "",
  "params": [
   {
    "label": "Pre Low Cut",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/Pre_Low_Cut"
   },
   {
    "label": "Size",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/Size"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/Mix"
   },
   {
    "label": "Pre High Cut",
    "min": 0,
    "max": 1,
    "default": 0.79,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/Pre_High_Cut"
   },
   {
    "label": "Low Shelf",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/Low_Shelf"
   },
   {
    "label": "Low Gain",
    "min": 0,
    "max": 1,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/Low_Gain"
   },
   {
    "label": "High Shelf",
    "min": 0,
    "max": 1,
    "default": 0.62,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/High_Shelf"
   },
   {
    "label": "High Gain",
    "min": 0,
    "max": 1,
    "default": 0.83,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/High_Gain"
   },
   {
    "label": "Chorus Amount",
    "min": 0,
    "max": 1,
    "default": 0.01,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/Chorus_Amount"
   },
   {
    "label": "Chorus Rate",
    "min": 0,
    "max": 1,
    "default": 0.1,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/Chorus_Rate"
   },
   {
    "label": "Pre-Delay",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/Pre-Delay"
   },
   {
    "label": "Decay Time",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Vital_Reverb/Decay_Time"
   }
  ],
  "faustCode": "declare name \"Vital Reverb\";\ndeclare description \"Matt Tytel's Vital synth reverb: pre-filter, shelving, chorused FDN tail\";\ndeclare author \"David Braun (Faust port), Matt Tytel (Vital)\";\ndeclare license \"GPL-3.0-only\";\ndeclare source \"grame-cncm/faustlibraries/reverbs.lib re.vital_rev\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nprelow  = hslider(\"[0] Pre Low Cut\", 0, 0, 1, 0.01) : si.smoo;\nprehigh = hslider(\"[1] Pre High Cut\", 0.79, 0, 1, 0.01) : si.smoo;\nlowcut  = hslider(\"[2] Low Shelf\", 0, 0, 1, 0.01) : si.smoo;\nlowgain = hslider(\"[3] Low Gain\", 1, 0, 1, 0.01) : si.smoo;\nhighcut = hslider(\"[4] High Shelf\", 0.62, 0, 1, 0.01) : si.smoo;\nhighgain= hslider(\"[5] High Gain\", 0.83, 0, 1, 0.01) : si.smoo;\nchamt   = hslider(\"[6] Chorus Amount\", 0.01, 0, 1, 0.01) : si.smoo;\nchrate  = hslider(\"[7] Chorus Rate\", 0.1, 0, 1, 0.01) : si.smoo;\npredel  = hslider(\"[8] Pre-Delay\", 0, 0, 1, 0.01) : si.smoo;\ntime    = hslider(\"[9] Decay Time\", 0.5, 0, 1, 0.01) : si.smoo;\nsize    = hslider(\"[10] Size\", 0.5, 0, 1, 0.01) : si.smoo;\nmix     = hslider(\"[11] Mix\", 0.4, 0, 1, 0.01) : si.smoo;\n\nprocess = _ <: re.vital_rev(prelow, prehigh, lowcut, highcut, lowgain, highgain, chamt, chrate, predel, time, size, mix) :> *(0.5);"
 },
 {
  "id": "gx-zita-rev1",
  "name": "Zita Rev1",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Fons Adriaensen's zita-rev1 FDN hall reverb with RT60 per band and built-in EQ.",
  "description": "The zita-rev1 eight-line feedback-delay-network reverb from the Faust library with guitarix defaults: pre-delay, low and mid RT60 with crossover, HF damping, two parametric EQ bands and dry/wet; wrapped to mono. A lush, natural hall.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "in delay",
    "min": 20,
    "max": 100,
    "default": 60,
    "step": 1,
    "unit": "ms",
    "path": "/zita_rev1/input/in_delay"
   },
   {
    "label": "lf x",
    "min": 50,
    "max": 1000,
    "default": 200,
    "step": 1.08,
    "unit": "Hz",
    "path": "/zita_rev1/decay_times/lf_x"
   },
   {
    "label": "low rt60",
    "min": 1,
    "max": 8,
    "default": 3,
    "step": 1.08,
    "unit": "s",
    "path": "/zita_rev1/decay_times/low_rt60"
   },
   {
    "label": "mid rt60",
    "min": 1,
    "max": 8,
    "default": 2,
    "step": 1.08,
    "unit": "s",
    "path": "/zita_rev1/decay_times/mid_rt60"
   },
   {
    "label": "hf damping",
    "min": 1500,
    "max": 23520,
    "default": 6000,
    "step": 1.08,
    "unit": "Hz",
    "path": "/zita_rev1/decay_times/hf_damping"
   },
   {
    "label": "eq1 freq",
    "min": 40,
    "max": 2500,
    "default": 315,
    "step": 1.08,
    "unit": "Hz",
    "path": "/zita_rev1/equalizer1/eq1_freq"
   },
   {
    "label": "eq1 level",
    "min": -15,
    "max": 15,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/zita_rev1/equalizer1/eq1_level"
   },
   {
    "label": "eq2 freq",
    "min": 160,
    "max": 10000,
    "default": 1500,
    "step": 1.08,
    "unit": "Hz",
    "path": "/zita_rev1/equalizer2/eq2_freq"
   },
   {
    "label": "eq2 level",
    "min": -15,
    "max": 15,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/zita_rev1/equalizer2/eq2_level"
   },
   {
    "label": "dry wet mix",
    "min": -1,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/zita_rev1/output/dry_wet_mix"
   },
   {
    "label": "level",
    "min": -70,
    "max": 40,
    "default": 0,
    "step": 0.1,
    "unit": "dB",
    "path": "/zita_rev1/output/level"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/plugins/zita_rev1.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\n// this code is copied from faust effect.lib and\n// some parameter texts and defaults changed\n\ndeclare id \"zita_rev1\";\ndeclare name \"Zita Rev1\";\ndeclare category \"Reverb\";\n\nimport(\"stdfaust.lib\");\n\nprocess_wide(x,y) = re.zita_rev1_stereo(rdel,f1,f2,t60dc,t60m,fsmax,x,y)\n\t  : out_eq : dry_wet(x,y) : out_level\nwith {\n\n  fsmax = 48000.0;  // highest sampling rate that will be used\n\n  fdn_group(x) = hgroup(\n    \"zita_rev1[name:Zita_Rev1] [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER ALLPASS-COMB REVERBERATOR (8x8). See Faust's effect.lib for documentation and references]\", x);\n\n  in_group(x) = fdn_group(hgroup(\"input[name:Input]\", x));\n\n  rdel = in_group(vslider(\"in_delay[name:Pre Delay] [unit:ms] [style:knob] \n                  [tooltip: Delay in ms before reverberation begins]\",\n                  60,20,100,1));\n\n  freq_group(x) = fdn_group(hgroup(\"decay_times[name:Decay Times in Bands]\", x));\n\n  f1 = freq_group(vslider(\"lf_x[name:Freq X] [unit:Hz] [style:knob] [log]\n       [tooltip: Crossover frequency (Hz) separating low and middle frequencies]\",\n       200, 50, 1000, 1.08));\n\n  t60dc = freq_group(vslider(\"low_rt60[name:Low] [unit:s] [style:knob] [log]\n          [style:knob] [tooltip: T60 = time (in seconds) to decay 60dB in low-frequency band]\", \n\t  3, 1, 8, 1.08));\n\n  t60m = freq_group(vslider(\"mid_rt60[name:Mid] [unit:s] [style:knob] [log]\n          [tooltip: T60 = time (in seconds) to decay 60dB in middle band]\", \n\t  2, 1, 8, 1.08));\n\n  f2 = freq_group(vslider(\"hf_damping[name:HF Damp] [unit:Hz] [style:knob] [log]\n       [tooltip: Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60]\",\n       6000, 1500, 0.49*fsmax, 1.08));\n\n  out_eq = pareq_stereo(eq1f,eq1l,eq1q) : pareq_stereo(eq2f,eq2l,eq2q);\n// Zolzer style peaking eq (not used in zita-fi.rev1) (filter.lib):\n// pareq_stereo(eqf,eql,Q) = fi.peak_eq(eql,eqf,eqf/Q), fi.peak_eq(eql,eqf,eqf/Q);\n// Regalia-Mitra peaking eq with \"Q\" hard-wired near sqrt(g)/2 (filter.lib):\n  pareq_stereo(eqf,eql,Q) = fi.peak_eq_rm(eql,eqf,tpbt), fi.peak_eq_rm(eql,eqf,tpbt)\n  with {\n    tpbt = wcT/sqrt(g); // tan(ma.PI*B/ma.SR) where B bandwidth in Hz (Q^2 ~ g/4)\n    wcT = 2*ma.PI*eqf/ma.SR;  // peak frequency in rad/sample\n    g = ba.db2linear(eql); // peak gain\n  };\n\n  eq1_group(x) = fdn_group(hgroup(\"equalizer1[name:RM Peaking Equalizer 1]\", x));\n\n  eq1f = eq1_group(vslider(\"eq1_freq[name:Freq] [unit:Hz] [style:knob] [log]\n       [tooltip: Center-frequency of second-order Regalia-Mitra peaking equalizer section 1]\",\n       315, 40, 2500, 1.08));\n  \n  eq1l = eq1_group(vslider(\"eq1_level[name:Level] [unit:dB] [style:knob]\n       [tooltip: Peak level in dB of second-order Regalia-Mitra peaking equalizer section 1]\",\n       0, -15, 15, 0.1));\n  \n  eq1q = eq1_group(vslider(\"eq1_q[name:Q] [style:knob]\n       [tooltip: Q = centerFrequency/bandwidth of second-order peaking equalizer section 1]\",\n       3, 0.1, 10, 0.1));\n  \n  eq2_group(x) = fdn_group(hgroup(\"equalizer2[name:RM Peaking Equalizer 2]\", x));\n\n  eq2f = eq2_group(vslider(\"eq2_freq[name:Freq] [unit:Hz] [style:knob] [log]\n       [tooltip: Center-frequency of second-order Regalia-Mitra peaking equalizer section 2]\",\n       1500, 160, 10000, 1.08));\n  \n  eq2l = eq2_group(vslider(\"eq2_level[name:Level] [unit:dB] [style:knob]\n       [tooltip: Peak level in dB of second-order Regalia-Mitra peaking equalizer section 2]\",\n       0, -15, 15, 0.1));\n\n  eq2q = eq2_group(vslider(\"eq2_q[name:Q] [style:knob]\n       [tooltip: Q = centerFrequency/bandwidth of second-order peaking equalizer section 2]\",\n       3, 0.1, 10, 0.1));\n  \n  out_group(x)  = fdn_group(hgroup(\"output[name:Output]\", x));\n\n  dry_wet(x,y) = *(wet) + dry*x, *(wet) + dry*y with { \n    wet = 0.5*(drywet+1.0);\n    dry = 1.0-wet; \n  };\n\n  drywet = out_group(vslider(\"dry_wet_mix[name:Dry/Wet] [style:knob]\n       [tooltip: -1 = dry, 1 = wet]\",\n       0, -1.0, 1.0, 0.01)) : si.smooth(0.999);\n\n  out_level = *(gain),*(gain);\n\n  gain = out_group(vslider(\"level[name:Level] [unit:dB] [style:knob]\n    [tooltip: Output scale factor]\", 0, -70, 40, 0.1)) \n    : si.smooth(0.999) : ba.db2linear; \n\n};\n\n// mono wrapper added by the Chameleon port (pedal is mono in / mono out)\nprocess = _ <: process_wide :> *(0.5);"
 },
 {
  "id": "lib-zita-rev1",
  "name": "Zita Rev1",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "Fons Adriaensen's zita-rev1 8x8 FDN hall reverb, mono wrap with per-band decay",
  "description": "Fons Adriaensen's zita-rev1 8x8 FDN hall reverb, mono wrap with per-band decay",
  "author": "Julius O. Smith III (Faust port of Fons Adriaensen's zita-rev1)",
  "flags": "",
  "params": [
   {
    "label": "Pre-delay",
    "min": 20,
    "max": 100,
    "default": 40,
    "step": 1,
    "unit": "ms",
    "path": "/Zita_Rev1/Pre-delay"
   },
   {
    "label": "LF Crossover",
    "min": 50,
    "max": 1000,
    "default": 200,
    "step": 1,
    "unit": "Hz",
    "path": "/Zita_Rev1/LF_Crossover"
   },
   {
    "label": "Low RT60",
    "min": 1,
    "max": 8,
    "default": 3,
    "step": 0.1,
    "unit": "s",
    "path": "/Zita_Rev1/Low_RT60"
   },
   {
    "label": "Mid RT60",
    "min": 1,
    "max": 8,
    "default": 2,
    "step": 0.1,
    "unit": "s",
    "path": "/Zita_Rev1/Mid_RT60"
   },
   {
    "label": "HF Damping",
    "min": 1500,
    "max": 20000,
    "default": 6000,
    "step": 1,
    "unit": "Hz",
    "path": "/Zita_Rev1/HF_Damping"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.35,
    "step": 0.01,
    "unit": "",
    "path": "/Zita_Rev1/Mix"
   }
  ],
  "faustCode": "declare name \"Zita Rev1\";\ndeclare description \"Fons Adriaensen's zita-rev1 8x8 FDN hall reverb, mono wrap with per-band decay\";\ndeclare author \"Julius O. Smith III (Faust port of Fons Adriaensen's zita-rev1)\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"grame-cncm/faustlibraries/reverbs.lib re.zita_rev1_stereo\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\nrdel  = hslider(\"[0] Pre-delay[unit:ms]\", 40, 20, 100, 1);\nf1    = hslider(\"[1] LF Crossover[unit:Hz][scale:log]\", 200, 50, 1000, 1);\nt60dc = hslider(\"[2] Low RT60[unit:s]\", 3, 1, 8, 0.1);\nt60m  = hslider(\"[3] Mid RT60[unit:s]\", 2, 1, 8, 0.1);\nf2    = hslider(\"[4] HF Damping[unit:Hz][scale:log]\", 6000, 1500, 20000, 1);\nmix   = hslider(\"[5] Mix\", 0.35, 0, 1, 0.01) : si.smoo;\n\nwet = _ <: re.zita_rev1_stereo(rdel, f1, f2, t60dc, t60m, 48000) :> *(0.5);\nprocess = _ <: *(1-mix), (wet : *(mix)) :> _;"
 },
 {
  "id": "tdg-zita-spread",
  "name": "Zita Spread",
  "category": "guitar",
  "family": "reverb",
  "familyName": "Reverb",
  "icon": "tabler:ripple",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Zita-rev1 FDN variant with a Spread control scaling the delay-line lengths (tiny room to huge hall), RT and HF decay",
  "description": "Zita-rev1 FDN variant with a Spread control scaling the delay-line lengths (tiny room to huge hall), RT and HF decay",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Predelay",
    "min": 1,
    "max": 500,
    "default": 20,
    "step": 1,
    "unit": "ms",
    "path": "/Zita_Spread/Predelay"
   },
   {
    "label": "Spread",
    "min": 0.2,
    "max": 2,
    "default": 0.5,
    "step": 0.05,
    "unit": "",
    "path": "/Zita_Spread/Spread"
   },
   {
    "label": "RT",
    "min": 1,
    "max": 10,
    "default": 3,
    "step": 0.05,
    "unit": "s",
    "path": "/Zita_Spread/RT"
   },
   {
    "label": "HF Decay",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.05,
    "unit": "",
    "path": "/Zita_Spread/HF_Decay"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.05,
    "unit": "",
    "path": "/Zita_Spread/Dry_Wet"
   }
  ],
  "faustCode": "declare name \"Zita Spread\";\ndeclare description \"Zita-rev1 FDN variant with a Spread control scaling the delay-line lengths (tiny room to huge hall), RT and HF decay\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust rects/rev_01.dsp (zita_rev_fdn by JOS)\";\ndeclare category \"guitar\";\ndeclare family \"reverb\";\nimport(\"stdfaust.lib\");\n\npp_predel = hslider(\"[0] Predelay[unit:ms]\", 20, 1, 500, 1);\npp_spread = hslider(\"[1] Spread\", 0.5, 0.2, 2, 0.05);\npp_rt     = hslider(\"[2] RT[unit:s]\", 3, 1, 10, 0.05);\npp_decay  = hslider(\"[3] HF Decay\", 0.5, 0, 1, 0.05);\ndry_wet   = hslider(\"[4] Dry/Wet\", 0.4, 0, 1, 0.05) : si.smoo;\n\nzita_rev_mod1(spread,rt,f_decay,fsmax) =\n  ((si.bus(2*N) :> allpass_combs(N) : feedbackmatrix(N)) ~ (delayfilters(N,freqs,durs) : fbdelaylines(N)))\nwith {\n  N = 8;\n  apdelays = (0.020346, 0.024421, 0.031604, 0.027333, 0.022904, 0.029291, 0.013458, 0.019123);\n  tdelays = ( 0.153129, 0.210389, 0.127837, 0.256891, 0.174713, 0.192303, 0.125000, 0.219991);\n  tdelay(i) = floor(0.5 + ma.SR*ba.take(i+1,tdelays)*spread);\n  apdelay(i) = floor(0.5 + ma.SR*ba.take(i+1,apdelays));\n  fbdelay(i) = max(1, tdelay(i) - apdelay(i));\n  tdelaymaxfs(i) = floor(0.5 + fsmax*ba.take(i+1,tdelays)*2);\n  apdelaymaxfs(i) = floor(0.5 + fsmax*ba.take(i+1,apdelays));\n  fbdelaymaxfs(i) = tdelaymaxfs(i) - apdelaymaxfs(i);\n  nextpow2(x) = ceil(log(x)/log(2.0));\n  maxapdelay(i) = int(2.0^max(1.0,nextpow2(apdelaymaxfs(i))));\n  maxfbdelay(i) = int(2.0^max(1.0,nextpow2(fbdelaymaxfs(i))));\n  apcoeff(i) = select2(i&1,0.6,-0.6);\n  allpass_combs(N) = par(i,N,(fi.allpass_comb(maxapdelay(i),apdelay(i),apcoeff(i))));\n  fbdelaylines(N) = par(i,N,(de.delay(maxfbdelay(i),(fbdelay(i)))));\n  freqs = (200,200+f_decay*8000); durs = (rt+2,rt);\n  delayfilters(N,freqs,durs) = par(i,N,filter(i,freqs,durs));\n  feedbackmatrix(N) = ro.hadamard(N);\n  staynormal = 10.0^(-20);\n  special_lowpass(g,f) = si.smooth(p) with {\n    p = mbo2 - sqrt(max(0,mbo2*mbo2 - 1.0));\n    mbo2 = (1.0 - gs*c)/(1.0 - gs);\n    gs = g*g;\n    c = cos(2.0*ma.PI*f/float(ma.SR));\n  };\n  filter(i,freqs,durs) = lowshelf_lowpass(i)/sqrt(float(N))+staynormal\n  with {\n    lowshelf_lowpass(i) = gM*fi.low_shelf1_l(g0/gM,f(1)) : special_lowpass(gM,f(2));\n    g0 = g(0,i); gM = g(1,i);\n    f(k) = ba.take(k,freqs);\n    dur(j) = ba.take(j+1,durs);\n    n60(j) = dur(j)*ma.SR;\n    g(j,i) = exp(-3.0*log(10.0)*tdelay(i)/n60(j));\n  };\n};\nwet = de.fdelay(32768, pp_predel*ma.SR/1000) <: si.bus(8) : zita_rev_mod1(pp_spread, pp_rt, pp_decay, 48000) :> *(0.25);\nprocess = _ <: *(1-dry_wet), (wet : *(dry_wet)) :> _;"
 },
 {
  "id": "gx-gxechocat",
  "name": "Copicat Tape Echo",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Watkins/Selmer Copicat-style multi-head tape echo with tube record/replay stages and wow.",
  "description": "Tape echo built from real head spacings and tape speed (four playback heads), with DK-simulated record and replay valve stages from the Copicat circuit, band-limited tape filtering and a little wow. BPM sets head timing, Swell the repeats and Sustain the feedback.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "BPM",
    "min": 24,
    "max": 360,
    "default": 120,
    "step": 0.1,
    "unit": "",
    "path": "/Tape_Delay/Tape_Heads/Echo/BPM"
   },
   {
    "label": "Swell",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Tape_Delay/Echo/Swell"
   },
   {
    "label": "Sustain",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Tape_Delay/Echo/Sustain"
   },
   {
    "label": "AUDIO IN",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tape_Delay/AUDIO_IN"
   },
   {
    "label": "Output",
    "min": 0,
    "max": 2,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Tape_Delay/Output"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxechocat.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Tape Delay\";\ndeclare category \"Echo / Delay\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\nimport(\"redeye.lib\");\n\ngxt = library(\"gx_tables.lib\");\n\n/*\nHEAD SPACING\n\nI have lold Selmer unit where playback heads are 1.5 inches apart\nand record head is 1.8 inches from last playback so :\n\n\trecord - play4 - play 3 - play 2 - play 1\n\n\t\t1.8  - 1.5 - 1.5 - 1.5 - 1.5\n \nSe we have record -1.8inches - head1, 2.3 to head2, 3.8 to head3 5.3 to head 4 !\n Or\tat 15ips\thead1 120ms head2 220ms head3 320ms head4 420ms\n\nAccording to what I have read the heads are not parallel but output from each one is fed into next ??? What ??? Also max de.delay from one head is 425ms\nApparently originsl units has 23 inch tapes!\n  \nActual topology\nIn -> stage1 -> pentode driver for record head ->play heads -> 2stage valve amp ->mixer->out and feedback to pentode\nSounds OK maybe too much bandwidth loss try cleaner path\nLook ay adding soft clip before machine to simulate saturation \nFrequency response of tape in copicat would be poor due to design and use\nTape usually has steep low end drop with a hump and not quite so steep high drop, maybe as for guitar we can lower this but would guess that should start around\n\t40 - 80Hz steep fi.highpass with possible hump ( ? resonant filter )\n\t5- 6k fi.lowpass\nAm concerned that as each valve stage already has same lowapss filter that this\nmay have same effect as in real amp of creating a resonance an will try same solution : stagger filters and identify dominant one ( biggest effect ) and slug it or drastically reduce it.\n*/\n\n// So we need multiple de.delay heads\n// Each head can be bypassed or moved to alter de.delay time\n// so tape speed in inches per second\n// distance from record head in inches\n// thus we get de.delay in milliseconds\n//speed = 7.5 ;\n\nbpm = hgroup( \"Echo\", vslider(\"BPM[style:knob]\", 120, 24, 360, 0.1)) ;\n\n// The wow should be preset by experiment...\n// Lets introduce just a little\nsine(freq) = (os.oscs(freq) + 1) / 2 : max(0); // max(0) because of numerical inaccuracy\nfreq= 4 ; // 4Hz\ndepth = 0.005 ;\t// Play with this\nwow =  sine( freq) * depth ;\nspeed = ( 72/(2*bpm))  ;\ntapespeed = hgroup( \"Tape Control\",speed + wow ); \n\nLogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\ns = 0.993;\n\necho = hgroup( \"Echo\", vslider(\"Swell[style:knob]\", 0, 0, 1, 0.01)): LogPot(1):si.smooth(s):*(0.25) ;\nfeedback = hgroup( \"Echo\", vslider(\"Sustain[style:knob]\", 0, 0.0, 1.0, 0.01)):LogPot(1):si.smooth(s):*(0.25);\n\n// Play with delays to get following ranges \n// 83.33ms => 1.25s on head1 \n// 166.6ms => 2.5s on head1 \n// 250ms => 3.75s on head1 \ndtime1 = ma.SR*( 30/bpm) ;\ndtime2 = ma.SR*( 60/ bpm) ;\ndtime3 = ma.SR*( 90/bpm ) ;\ndtime4 = ma.SR*( 240/bpm ) ;\n\nhead1 = de.sdelay(N, interp, dtime1):*(checkbox(\"Head1\")) with {\n\tinterp = ma.SR/10.0; // 100*SER/1000\n \tN = int( 2^19 ) ;\n};\nhead2 = de.sdelay(N, interp, dtime2):*(checkbox(\"Head2\")) with {\n\tinterp = 100*ma.SR/1000.0;\n \tN = int( 2^19 ) ;\n};\nhead3 = de.sdelay(N, interp, dtime3):*(checkbox(\"Head3\")) with {\n\tinterp = 100*ma.SR/1000.0;\n \tN = int( 2^19 ) ;\n};\nhead4 = de.sdelay(N, interp, dtime4):*(checkbox(\"Head4\")) with {\n\tinterp = 100*ma.SR/1000.0;\n \tN = int( 2^19 ) ;\n};\n\n\ninput = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) : copicat1clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n//    Input = vslider(\"Input[name:Input]\", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(3) : si.smooth(s);\n    Input = vslider(\"AUDIO_IN[name:Input]\", 0.5, 0, 1, 0.01) : si.smooth(s);\n\n    b0 = Input*fs*(-2.06740841499587e-8*fs - 5.51308910665569e-7);\n\n    b1 = 4.13481682999174e-8*Input*pow(fs,2);\n\n    b2 = Input*fs*(-2.06740841499587e-8*fs + 5.51308910665569e-7);\n\n    a0 = Input*(Input*fs*(-7.83789728824443e-11*fs - 3.13458049067171e-9) + fs*(8.32844278169955e-11*fs + 5.0418669893366e-9) + 6.26916098134342e-8) + fs*(4.11425073415965e-10*fs + 2.49068229273233e-8) + 3.09696552478371e-7;\n\n    a1 = Input*(1.56757945764889e-10*Input*pow(fs,2) - 1.66568855633991e-10*pow(fs,2) + 1.25383219626868e-7) - 8.22850146831931e-10*pow(fs,2) + 6.19393104956741e-7;\n\n    a2 = Input*(Input*fs*(-7.83789728824443e-11*fs + 3.13458049067171e-9) + fs*(8.32844278169955e-11*fs - 5.0418669893366e-9) + 6.26916098134342e-8) + fs*(4.11425073415965e-10*fs - 2.49068229273233e-8) + 3.09696552478371e-7;\n};\n\ncopicat1clip = _<: ba.if(signbit(_), copicat1_neg_clip, copicat1_clip) :>_ with {\nsignbit(x) = (x < 0);copicat1_clip = gxt.copicat1clip;copicat1_neg_clip = gxt.copicat1_negclip;\n};\nrecord = pre : fi.iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) : copicatrecord_2clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n    b0 = fs*(-1.23938408071082e-8*fs - 7.13052376187718e-7) - 9.98795811595446e-6;\n\n    b1 = fs*(1.23938408071082e-8*fs - 7.13052376187718e-7) - 2.99638743478634e-5;\n\n    b2 = fs*(1.23938408071082e-8*fs + 7.13052376187718e-7) - 2.99638743478634e-5;\n\n    b3 = fs*(-1.23938408071082e-8*fs + 7.13052376187718e-7) - 9.98795811595446e-6;\n\n    a0 = fs*(fs*(6.73029102377671e-15*fs + 1.10493997854221e-10) + 2.30183843147656e-8) + 6.01595252726883e-7;\n\n    a1 = fs*(fs*(-2.01908730713301e-14*fs - 1.10493997854221e-10) + 2.30183843147656e-8) + 1.80478575818065e-6;\n\n    a2 = fs*(fs*(2.01908730713301e-14*fs - 1.10493997854221e-10) - 2.30183843147656e-8) + 1.80478575818065e-6;\n\n    a3 = fs*(fs*(-6.73029102377671e-15*fs + 1.10493997854221e-10) - 2.30183843147656e-8) + 6.01595252726883e-7;\n};\n\ncopicatrecord_2clip = _<: ba.if(signbit(_), copicatrecord_2_neg_clip, copicatrecord_2_clip) :>_ with {\nsignbit(x) = (x < 0);copicatrecord_2_clip = gxt.copicatrecord_2clip;copicatrecord_2_neg_clip = gxt.copicatrecord_2_negclip;\n};\nreplay1 = pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) : copicatreplay1clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n    b0 = fs*(-2.16461324600193e-8*fs - 1.31188681575873e-7);\n\n    b1 = 4.32922649200386e-8*pow(fs,2);\n\n    b2 = fs*(-2.16461324600193e-8*fs + 1.31188681575873e-7);\n\n    a0 = fs*(4.33785780482415e-10*fs + 1.16144315716444e-8) + 6.90530766455131e-8;\n\n    a1 = -8.6757156096483e-10*pow(fs,2) + 1.38106153291026e-7;\n\n    a2 = fs*(4.33785780482415e-10*fs - 1.16144315716444e-8) + 6.90530766455131e-8;\n};\n\ncopicatreplay1clip = _<: ba.if(signbit(_), copicatreplay1_neg_clip, copicatreplay1_clip) :>_ with {\nsignbit(x) = (x < 0);copicatreplay1_clip = gxt.copicatreplay1clip;copicatreplay1_neg_clip = gxt.copicatreplay1_negclip;\n};\nreplay2 =  pre : fi.iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) : copicatreplay2clip with {\n    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\n    Inverted(b, x) = ba.if(b, 1 - x, x);\n    s = 0.993;\n    fs = float(ma.SR);\n    pre = _;\n\n\n    b0 = fs*(-1.02325156488485e-9*fs - 1.05707806289759e-8);\n\n    b1 = 2.0465031297697e-9*pow(fs,2);\n\n    b2 = fs*(-1.02325156488485e-9*fs + 1.05707806289759e-8);\n\n    a0 = fs*(4.3361242466424e-10*fs + 1.99329936161353e-8) + 1.89880017035189e-7;\n\n    a1 = -8.6722484932848e-10*pow(fs,2) + 3.79760034070379e-7;\n\n    a2 = fs*(4.3361242466424e-10*fs - 1.99329936161353e-8) + 1.89880017035189e-7;\n};\n\n\ncopicatreplay2clip = _<: ba.if(signbit(_), copicatreplay2_neg_clip, copicatreplay2_clip) :>_ with {\nsignbit(x) = (x < 0);copicatreplay2_clip = gxt.copicatreplay2clip;copicatreplay2_neg_clip = gxt.copicatreplay2_negclip;\n};\n\n\nmachine = record:vgroup( \"Tape Heads\", fi.highpass( 4, 40 )<:head1,head2,head3:>fi.lowpass( 1, 6500 ):fi.dcblocker ):replay1:replay2;\n\n// May need to look at levels here\nfbloop = fi.lowpass( 1, 7500 ):*(feedback):fi.highpass( 1, 150 )  ;\n\nOutput = vslider(\"Output[name:Output]\", 1.0, 0.0, 2.0, 0.01) : LogPot(3) : si.smooth(s);\n\namp = input<:_,((+:_<:machine :>_)~fbloop:*(echo)):>*(Output) ;\n\nfreq_split = fi.filterbank(3, (86.0,210.0,1200.0,6531.0));\nprocess    = freq_split: ( amp , amp , amp, amp, amp) :>_;"
 },
 {
  "id": "gx-delay",
  "name": "Delay",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Plain single-tap delay with gain and time.",
  "description": "A single delay line with Delay time and feedback Gain. A basic, clean digital delay.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "gain",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Delay/gain"
   },
   {
    "label": "de.delay",
    "min": 0,
    "max": 5000,
    "default": 0,
    "step": 10,
    "unit": "",
    "path": "/Delay/de.delay"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/delay.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Delay\";\ndeclare category \"Echo / Delay\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\nmsec\t= ma.SR/1000.0;\ngain = vslider(\"gain\", 0, -20, 20, 0.1) : ba.db2linear : smoothi(0.999);\nd = vslider(\"de.delay\", 0, 0, 5000, 10)*msec;\nprocess = _ <: _ + gain * de.fdelay5s(d) :> _;"
 },
 {
  "id": "tdg-delay-colored",
  "name": "Delay Colored",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Feedback delay with a tilt-style coloration filter on the repeats (dark low-shelf to bright high-shelf)",
  "description": "Feedback delay with a tilt-style coloration filter on the repeats (dark low-shelf to bright high-shelf)",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Time",
    "min": 50,
    "max": 2000,
    "default": 500,
    "step": 1,
    "unit": "ms",
    "path": "/Delay_Colored/Time"
   },
   {
    "label": "Coloration",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Colored/Coloration"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Colored/Dry_Wet"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.95,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Colored/Feedback"
   }
  ],
  "faustCode": "declare name \"Delay Colored\";\ndeclare description \"Feedback delay with a tilt-style coloration filter on the repeats (dark low-shelf to bright high-shelf)\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust circles/delay_colored.dsp + geometry.lib\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\nmix2(c,x,y) = (1-c)*x + c*y;\n// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors\nmono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;\np_time = hslider(\"[0] Time[unit:ms]\", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));\np_fb   = hslider(\"[1] Feedback\", 0.3, 0, 0.95, 0.01) : si.smoo;\np_dw   = hslider(\"[9] Dry/Wet\", 0.5, 0, 1, 0.01) : si.smoo;\np_col = hslider(\"[2] Coloration\", 0.5, 0, 1, 0.01) : si.smoo;\ncoloration_filter1(coloration) = _ <: (fi.lowshelf(5,(1 - coloration)*12,440), fi.highshelf(5,coloration*12,880)) :> _*ba.db2linear(-15);\nprocess = _ <: _, (mono_delay(p_time, p_fb, _, _) : coloration_filter1(p_col)) : mix2(p_dw);"
 },
 {
  "id": "tdg-delay-detune",
  "name": "Delay Detune",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Feedback delay whose repeats pass through an LFO-modulated micro-delay, detuning each echo (chorus-delay)",
  "description": "Feedback delay whose repeats pass through an LFO-modulated micro-delay, detuning each echo (chorus-delay)",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Time",
    "min": 50,
    "max": 2000,
    "default": 500,
    "step": 1,
    "unit": "ms",
    "path": "/Delay_Detune/Time"
   },
   {
    "label": "Detune",
    "min": 0,
    "max": 1,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Detune/Detune"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Detune/Dry_Wet"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.95,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Detune/Feedback"
   }
  ],
  "faustCode": "declare name \"Delay Detune\";\ndeclare description \"Feedback delay whose repeats pass through an LFO-modulated micro-delay, detuning each echo (chorus-delay)\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust circles/delay_detune.dsp + geometry.lib\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\nmix2(c,x,y) = (1-c)*x + c*y;\n// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors\nmono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;\np_time = hslider(\"[0] Time[unit:ms]\", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));\np_fb   = hslider(\"[1] Feedback\", 0.3, 0, 0.95, 0.01) : si.smoo;\np_dw   = hslider(\"[9] Dry/Wet\", 0.5, 0, 1, 0.01) : si.smoo;\np_dt = hslider(\"[2] Detune\", 0.3, 0, 1, 0.01) : si.smoo;\ndetune(lfo,depth) = de.fdelay(1024, ((lfo+1)*0.5)*depth*400 + 1);\nprocess = _ <: _, (mono_delay(p_time, p_fb, _, _) : detune(os.osc(1000/p_time), p_dt)) : mix2(p_dw);"
 },
 {
  "id": "tdg-delay-duck",
  "name": "Delay Duck",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Ducking delay: repeats are pushed down while you play and swell back in the gaps",
  "description": "Ducking delay: repeats are pushed down while you play and swell back in the gaps",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Time",
    "min": 50,
    "max": 2000,
    "default": 500,
    "step": 1,
    "unit": "ms",
    "path": "/Delay_Duck/Time"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.95,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Duck/Feedback"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Duck/Dry_Wet"
   },
   {
    "label": "Ducking",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Duck/Ducking"
   }
  ],
  "faustCode": "declare name \"Delay Duck\";\ndeclare description \"Ducking delay: repeats are pushed down while you play and swell back in the gaps\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust circles/delay_duck.dsp + geometry.lib\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\nmix2(c,x,y) = (1-c)*x + c*y;\n// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors\nmono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;\np_time = hslider(\"[0] Time[unit:ms]\", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));\np_fb   = hslider(\"[1] Feedback\", 0.3, 0, 0.95, 0.01) : si.smoo;\np_dw   = hslider(\"[9] Dry/Wet\", 0.5, 0, 1, 0.01) : si.smoo;\np_duck = hslider(\"[2] Ducking\", 0.5, 0, 1, 0.01) : si.smoo;\n// proportional ducking: reverb/delay level drops by up to `depth` dB as the input envelope rises\n// (the original used a hard gate — env*amount > 1 — which mutes the wet path entirely while playing,\n// so a 100 % wet mix went silent)\nduck_gain(att, rel, depth_db, x) = ba.db2linear(0 - depth_db * min(1, an.amp_follower_ud(att, rel, x) * 4)) : si.smooth(ba.tau2pole(0.02));\nprocess(x) = mix2(p_dw, x, mono_delay(p_time, p_fb, _, _, x) * duck_gain(0.05, 0.1, p_duck*40, x));"
 },
 {
  "id": "tdg-delay-emu",
  "name": "Delay Emu",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Delay with morphable character: 8-bit reduction (digital) to clean to tape-capstan wow with bandlimiting and hiss (analog)",
  "description": "Delay with morphable character: 8-bit reduction (digital) to clean to tape-capstan wow with bandlimiting and hiss (analog)",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Time",
    "min": 50,
    "max": 2000,
    "default": 500,
    "step": 1,
    "unit": "ms",
    "path": "/Delay_Emu/Time"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.95,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Emu/Feedback"
   },
   {
    "label": "Digital/Analog",
    "min": 0,
    "max": 2,
    "default": 1,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Emu/Digital_Analog"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Emu/Dry_Wet"
   }
  ],
  "faustCode": "declare name \"Delay Emu\";\ndeclare description \"Delay with morphable character: 8-bit reduction (digital) to clean to tape-capstan wow with bandlimiting and hiss (analog)\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust circles/delay_emu.dsp + geometry.lib\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\nmix2(c,x,y) = (1-c)*x + c*y;\n// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors\nmono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;\np_time = hslider(\"[0] Time[unit:ms]\", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));\np_fb   = hslider(\"[1] Feedback\", 0.3, 0, 0.95, 0.01) : si.smoo;\np_dw   = hslider(\"[9] Dry/Wet\", 0.5, 0, 1, 0.01) : si.smoo;\npp_ad = hslider(\"[2] Digital/Analog\", 1, 0, 2, 0.01) : si.smoo;\n\nmix3(val) = _,_,_ <: select3(int(val)), select3(min(2, int(val)+1)) : mix2(val-floor(val));\nbits_reducing(bits) = _*pow(2,bits) : ceil : _/pow(2,bits) : fi.lowpass(4,4000);\ntape_capstan_emu(band_width, del_osc_freq, del_width, noise_lev_db) = fi.lowpass(4,band_width) :\n    _+((noise_lev_db : ba.db2linear : si.smooth(0.999))*no.lfnoise0(12000)) :\n    de.fdelay(1024, os.osc(del_osc_freq) : _+1 : _/2 : _*del_width);\nanalog_digital(val) = _ <: bits_reducing(8), _, tape_capstan_emu(4000,6,25,-70) : mix3(val);\nprocess = _ <: _, (mono_delay(p_time, p_fb, _, _) : analog_digital(pp_ad)) : mix2(p_dw);"
 },
 {
  "id": "tdg-delay-flange",
  "name": "Delay Flange",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Feedback delay with a resonant flanger on the repeats, swept in time with the delay",
  "description": "Feedback delay with a resonant flanger on the repeats, swept in time with the delay",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Time",
    "min": 50,
    "max": 2000,
    "default": 500,
    "step": 1,
    "unit": "ms",
    "path": "/Delay_Flange/Time"
   },
   {
    "label": "Flange",
    "min": 0,
    "max": 1,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Flange/Flange"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Flange/Dry_Wet"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.95,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Flange/Feedback"
   }
  ],
  "faustCode": "declare name \"Delay Flange\";\ndeclare description \"Feedback delay with a resonant flanger on the repeats, swept in time with the delay\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust circles/delay_flange.dsp + geometry.lib\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\nmix2(c,x,y) = (1-c)*x + c*y;\n// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors\nmono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;\np_time = hslider(\"[0] Time[unit:ms]\", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));\np_fb   = hslider(\"[1] Feedback\", 0.3, 0, 0.95, 0.01) : si.smoo;\np_dw   = hslider(\"[9] Dry/Wet\", 0.5, 0, 1, 0.01) : si.smoo;\np_fl = hslider(\"[2] Flange\", 0.3, 0, 1, 0.01) : si.smoo;\nflanger(lfo,depth) = _ <: _, (- : de.fdelay(2048, ((lfo+1)/2)*depth*0.9*2047 + 1)) ~ *(0.5) : _, *(-1) : + : *(0.5);\nprocess = _ <: _, (mono_delay(p_time, p_fb, _, _) : flanger(os.osc(1000/p_time), p_fl)) : mix2(p_dw);"
 },
 {
  "id": "tdg-delay-ps",
  "name": "Delay Pitch Shift",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Feedback delay with a pitch shifter (up to +/-8 semitones) on the wet path - shimmering or dive-bombing echoes",
  "description": "Feedback delay with a pitch shifter (up to +/-8 semitones) on the wet path - shimmering or dive-bombing echoes",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Time",
    "min": 50,
    "max": 2000,
    "default": 500,
    "step": 1,
    "unit": "ms",
    "path": "/Delay_Pitch_Shift/Time"
   },
   {
    "label": "Pitch",
    "min": -12,
    "max": 12,
    "default": 12,
    "step": 0.05,
    "unit": "semi",
    "path": "/Delay_Pitch_Shift/Pitch"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Pitch_Shift/Dry_Wet"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.95,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Pitch_Shift/Feedback"
   }
  ],
  "faustCode": "declare name \"Delay Pitch Shift\";\ndeclare description \"Feedback delay with a pitch shifter (up to +/-8 semitones) on the wet path - shimmering or dive-bombing echoes\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust circles/delay_ps.dsp + geometry.lib\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\nmix2(c,x,y) = (1-c)*x + c*y;\n// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors\nmono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;\np_time = hslider(\"[0] Time[unit:ms]\", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));\np_fb   = hslider(\"[1] Feedback\", 0.3, 0, 0.95, 0.01) : si.smoo;\np_dw   = hslider(\"[9] Dry/Wet\", 0.5, 0, 1, 0.01) : si.smoo;\np_ps = hslider(\"[2] Pitch[unit:semi]\", 12, -12, 12, 0.05) : si.smoo;\npitch_shift(val,dry_wet) = _ <: _, ef.transpose(4096,2048,val) : mix2(dry_wet);\nprocess = _ <: _, (mono_delay(p_time, p_fb, _, _) : pitch_shift(p_ps, 0.8)) : mix2(p_dw);"
 },
 {
  "id": "tdg-delay-ringmod",
  "name": "Delay Ring Mod",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Feedback delay with a sine ring modulator on the repeats - metallic, inharmonic echoes",
  "description": "Feedback delay with a sine ring modulator on the repeats - metallic, inharmonic echoes",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Time",
    "min": 50,
    "max": 2000,
    "default": 500,
    "step": 1,
    "unit": "ms",
    "path": "/Delay_Ring_Mod/Time"
   },
   {
    "label": "Ring Freq",
    "min": 50,
    "max": 4000,
    "default": 500,
    "step": 1,
    "unit": "Hz",
    "path": "/Delay_Ring_Mod/Ring_Freq"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Ring_Mod/Dry_Wet"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.95,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Ring_Mod/Feedback"
   }
  ],
  "faustCode": "declare name \"Delay Ring Mod\";\ndeclare description \"Feedback delay with a sine ring modulator on the repeats - metallic, inharmonic echoes\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust circles/delay_ringmod.dsp + geometry.lib\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\nmix2(c,x,y) = (1-c)*x + c*y;\n// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors\nmono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;\np_time = hslider(\"[0] Time[unit:ms]\", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));\np_fb   = hslider(\"[1] Feedback\", 0.3, 0, 0.95, 0.01) : si.smoo;\np_dw   = hslider(\"[9] Dry/Wet\", 0.5, 0, 1, 0.01) : si.smoo;\np_freq = hslider(\"[2] Ring Freq[unit:Hz]\", 500, 50, 4000, 1) : si.smoo;\nring_modulator(freq, dry_wet) = _ <: ((1 - dry_wet)*_, (_*os.osc(freq))*dry_wet) :> _;\nprocess = _ <: _, (mono_delay(p_time, p_fb, _, _) : ring_modulator(p_freq, 0.5)) : mix2(p_dw);"
 },
 {
  "id": "tdg-delay-wah",
  "name": "Delay Wah",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Feedback delay with an envelope-follower auto-wah on the repeats",
  "description": "Feedback delay with an envelope-follower auto-wah on the repeats",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Time",
    "min": 50,
    "max": 2000,
    "default": 500,
    "step": 1,
    "unit": "ms",
    "path": "/Delay_Wah/Time"
   },
   {
    "label": "Wah",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Wah/Wah"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Wah/Dry_Wet"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.95,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Delay_Wah/Feedback"
   }
  ],
  "faustCode": "declare name \"Delay Wah\";\ndeclare description \"Feedback delay with an envelope-follower auto-wah on the repeats\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust circles/delay_wah.dsp + geometry.lib\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\nmix2(c,x,y) = (1-c)*x + c*y;\n// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors\nmono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;\np_time = hslider(\"[0] Time[unit:ms]\", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));\np_fb   = hslider(\"[1] Feedback\", 0.3, 0, 0.95, 0.01) : si.smoo;\np_dw   = hslider(\"[9] Dry/Wet\", 0.5, 0, 1, 0.01) : si.smoo;\np_wah = hslider(\"[2] Wah\", 0.5, 0, 1, 0.01) : si.smoo;\nprocess = _ <: _, (mono_delay(p_time, p_fb, _, _) : ve.autowah(p_wah)) : mix2(p_dw);"
 },
 {
  "id": "gx-duck-delay",
  "name": "Duck Delay",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Ducking delay that fades the repeats down while you play and up when you stop.",
  "description": "A feedback delay whose wet level is controlled by an envelope follower on the input: loud playing ducks the repeats, silence lets them through. Attack, Amount, Time, Feedback and Release, inspired by the Axe-FX ducking delay.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "attack",
    "min": 0.05,
    "max": 0.5,
    "default": 0.1,
    "step": 0.05,
    "unit": "",
    "path": "/Duck_Delay/attack"
   },
   {
    "label": "amount",
    "min": 0,
    "max": 40,
    "default": 12,
    "step": 0.5,
    "unit": "",
    "path": "/Duck_Delay/amount"
   },
   {
    "label": "time",
    "min": 1,
    "max": 2000,
    "default": 500,
    "step": 1,
    "unit": "",
    "path": "/Duck_Delay/time"
   },
   {
    "label": "feedback",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.05,
    "unit": "",
    "path": "/Duck_Delay/feedback"
   },
   {
    "label": "relese",
    "min": 0.05,
    "max": 2,
    "default": 0.1,
    "step": 0.05,
    "unit": "",
    "path": "/Duck_Delay/relese"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/duck_delay.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id   \"duckDelay\";\ndeclare name \"Duck Delay\";\ndeclare category \"Echo / Delay\";\n\n//------------------------------------\n//Inspired by:\n//http://www.gvst.co.uk/gduckdly.htm\n//Axe-FX II Owner's manual:5.6\n//------------------------------------\n\n//------------------------------------\n//Description:\n//The delayed signal added to output dependent of input signal amplitude. \n//If the input signal is high. The delayed signal turned off, and vise versa.\n//The switching controlled by envelope follower \n//(parameters: \"attack\", \"release\", and main - \"amount\", what controls envelope follower influence).\n//\n//Parameters description:\n//time - de.delay time in milliseconds \n//feedback - de.delay feedback\n//attack, release - envelope follower time in seconds controls\n//amount dB - envelope follower influence\n//------------------------------------\n\nimport(\"stdfaust.lib\");\n\n//Constrols\np_time = hslider(\"time\", 500, 1, 2000, 1):si.smooth(ba.tau2pole(0.1));\np_feedback = hslider(\"feedback\", 0, 0, 1, 0.05);\np_attack_time = hslider(\"attack\", 0.1, 0.05, 0.5, 0.05);\np_release_time = hslider(\"relese\", 0.1, 0.05, 2, 0.05);\np_amount = hslider(\"amount\", 12, 0,40, 0.5):si.smoo;\n\n//Consts\nc_channels_sw_time = 0.1;\nc_fdelay_max_len = 393216;\n\nget_delay_length(x) = x*ma.SR:_*0.001;\n\nprocess = _<:\n\t_,(_<:(_+_:de.fdelay(c_fdelay_max_len,get_delay_length(p_time)))~_*p_feedback,\t\t\n\t(ba.db2linear(0 - p_amount * min(1, an.amp_follower_ud(p_attack_time,p_release_time) * 4)) :\n\tsi.smooth(ba.tau2pole(c_channels_sw_time)))):_,_*_\n\t:>_;"
 },
 {
  "id": "gx-echo",
  "name": "Echo",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "BSD",
  "shortDesc": "Simple echo with time and feedback percent.",
  "description": "A single feedback echo with Time and Percent (feedback) controls. A basic slapback-to-repeat echo.",
  "author": "brummer",
  "flags": "-double",
  "params": [
   {
    "label": "time",
    "min": 1,
    "max": 2000,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Echo/time"
   },
   {
    "label": "percent",
    "min": 0,
    "max": 100,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Echo/percent"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/echo.dsp (GPL-2.0-or-later).\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Echo\";\ndeclare category \"Echo / Delay\";\n\ndeclare version \t\"0.01\";\ndeclare author \t\t\"brummer\";\ndeclare license \t\"BSD\";\ndeclare copyright \t\"(c)brummer 2008\";\n\nimport(\"stdfaust.lib\");\n\nt = vslider(\"time\", 1, 1, 2000, 1);\nrelease = vslider(\"percent\", 0, 0,  100, 0.1);\n\necho1  = +~(de.delay(131072,   int(t*ba.millisec)-1) * (release/100.0));\nprocess = echo1;"
 },
 {
  "id": "gx-mbdel",
  "name": "Multi-Band Delay",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Five-band delay with independent time, gain and feedback per band.",
  "description": "Splits the signal at four adjustable crossovers and applies a separate feedback delay (Delay, Gain, Feedback) to each band. Frequency-dependent rhythmic echoes.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "crossover b1 b2",
    "min": 20,
    "max": 20000,
    "default": 80,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Delay/crossover_b1_b2"
   },
   {
    "label": "crossover b2 b3",
    "min": 20,
    "max": 20000,
    "default": 210,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Delay/crossover_b2_b3"
   },
   {
    "label": "crossover b3 b4",
    "min": 20,
    "max": 20000,
    "default": 1700,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Delay/crossover_b3_b4"
   },
   {
    "label": "crossover b4 b5",
    "min": 20,
    "max": 20000,
    "default": 5000,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Delay/crossover_b4_b5"
   },
   {
    "label": "gain1",
    "min": -20,
    "max": 20,
    "default": -10,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Delay/gain1"
   },
   {
    "label": "delay1",
    "min": 24,
    "max": 360,
    "default": 30,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Delay/delay1"
   },
   {
    "label": "gain2",
    "min": -20,
    "max": 20,
    "default": -5,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Delay/gain2"
   },
   {
    "label": "delay2",
    "min": 24,
    "max": 360,
    "default": 60,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Delay/delay2"
   },
   {
    "label": "gain3",
    "min": -20,
    "max": 20,
    "default": -2,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Delay/gain3"
   },
   {
    "label": "delay3",
    "min": 24,
    "max": 360,
    "default": 90,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Delay/delay3"
   },
   {
    "label": "gain4",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Delay/gain4"
   },
   {
    "label": "delay4",
    "min": 24,
    "max": 360,
    "default": 120,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Delay/delay4"
   },
   {
    "label": "gain5",
    "min": -20,
    "max": 20,
    "default": -10,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Delay/gain5"
   },
   {
    "label": "delay5",
    "min": 24,
    "max": 360,
    "default": 150,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Delay/delay5"
   },
   {
    "label": "feedback1",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Delay/feedback1"
   },
   {
    "label": "feedback2",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Delay/feedback2"
   },
   {
    "label": "feedback3",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Delay/feedback3"
   },
   {
    "label": "feedback4",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Delay/feedback4"
   },
   {
    "label": "feedback5",
    "min": 1,
    "max": 100,
    "default": 50,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Delay/feedback5"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/mbdel.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"mbdel\";\ndeclare name \"MultiBand Delay\";\ndeclare shortname \"MB Delay\";\ndeclare category \"Echo / Delay\";\ndeclare description \"Multi Band Delay\";\n\nimport(\"stdfaust.lib\");\nrd = library(\"reducemaps.lib\");\n\nhifr1      =hslider(\"crossover_b1_b2 [log][name:Crossover B1-B2 (hz)][tooltip: Crossover fi.bandpass frequency]\" ,80 , 20, 20000, 1.08);\nhifr2      =hslider(\"crossover_b2_b3 [log][name:Crossover B2-B3 (hz)][tooltip: Crossover fi.bandpass frequency]\",210,20,20000,1.08);\nhifr3      =hslider(\"crossover_b3_b4 [log][name:Crossover B3-B4 (hz)][tooltip: Crossover fi.bandpass frequency]\",1700,20,20000,1.08);\nhifr4      =hslider(\"crossover_b4_b5 [log][name:Crossover B4-B5 (hz)][tooltip: Crossover fi.bandpass frequency]\",5000,20,20000,1.08);\n\ngeq = fi.filterbank(3, (hifr1,hifr2,hifr3,hifr4));\n\ninterp     = 100*ma.SR/1000.0;\nN          = int( 2^18);\ng1         = vslider(\"gain1\", -10, -20, 20, 0.1) : ba.db2linear : si.smooth(0.999);\nd1         = ba.tempo(hslider(\"delay1[tooltip:Delay in Beats per Minute]\",30,24,360,1));\ng2         = vslider(\"gain2\", -5, -20, 20, 0.1) : ba.db2linear : si.smooth(0.999);\nd2         = ba.tempo(hslider(\"delay2[tooltip:Delay in Beats per Minute]\",60,24,360,1));\ng3         = vslider(\"gain3\", -2, -20, 20, 0.1) : ba.db2linear : si.smooth(0.999);\nd3         = ba.tempo(hslider(\"delay3[tooltip:Delay in Beats per Minute]\",90,24,360,1));\ng4         = vslider(\"gain4\", 0, -20, 20, 0.1) : ba.db2linear : si.smooth(0.999);\nd4         = ba.tempo(hslider(\"delay4[tooltip:Delay in Beats per Minute]\",120,24,360,1));\ng5         = vslider(\"gain5\", -10, -20, 20, 0.1) : ba.db2linear : si.smooth(0.999);\nd5         = ba.tempo(hslider(\"delay5[tooltip:Delay in Beats per Minute]\",150,24,360,1));\n\ndel(g,d,f)   = *(g) : (+: de.sdelay(N, interp,d))~(*(f)) ;\n\nvmeter1(x)\t\t= attach(x, envelop(x) : vbargraph(\"v1[nomidi:no]\", -70, +5));\nvmeter2(x)\t\t= attach(x, envelop(x) : vbargraph(\"v2[nomidi:no]\", -70, +5));\nvmeter3(x)\t\t= attach(x, envelop(x) : vbargraph(\"v3[nomidi:no]\", -70, +5));\nvmeter4(x)\t\t= attach(x, envelop(x) : vbargraph(\"v4[nomidi:no]\", -70, +5));\nvmeter5(x)\t\t= attach(x, envelop(x) : vbargraph(\"v5[nomidi:no]\", -70, +5));\n\nf1 = vslider(\"feedback1[tooltip:percentage of the feedback level in the de.delay loop]\", 50, 1, 100, 1)/100 ;\nf2 = vslider(\"feedback2[tooltip:percentage of the feedback level in the de.delay loop]\", 50, 1, 100, 1)/100 ;\nf3 = vslider(\"feedback3[tooltip:percentage of the feedback level in the de.delay loop]\", 50, 1, 100, 1)/100 ;\nf4 = vslider(\"feedback4[tooltip:percentage of the feedback level in the de.delay loop]\", 50, 1, 100, 1)/100 ;\nf5 = vslider(\"feedback5[tooltip:percentage of the feedback level in the de.delay loop]\", 50, 1, 100, 1)/100 ;\n\nenvelop         = abs : max ~ (1.0/ma.SR) : rd.maxn(4096) ;\n//envelop         = abs : max ~ (1.0/ma.SR) : mean(4096) ; // : max(ba.db2linear(-70)) : ba.linear2db;\n\nprocess    = _<:(geq: ( dist5s , dist4s , dist3s, dist2s, dist1s)),_:>_  with { \n    dist1s = del(g1,d1,f1) : vmeter1;\n    dist2s = del(g2,d2,f2) : vmeter2;\n    dist3s = del(g3,d3,f3) : vmeter3;\n    dist4s = del(g4,d4,f4) : vmeter4;\n    dist5s = del(g5,d5,f5) : vmeter5;\n    \n};"
 },
 {
  "id": "gx-mbe",
  "name": "Multi-Band Echo",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Five-band echo with independent time and feedback percent per band.",
  "description": "Splits the signal at four adjustable crossovers and applies a separate echo (Time, Percent) to each band. Frequency-dependent echo textures.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "crossover b1 b2",
    "min": 20,
    "max": 20000,
    "default": 80,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Echo/crossover_b1_b2"
   },
   {
    "label": "crossover b2 b3",
    "min": 20,
    "max": 20000,
    "default": 210,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Echo/crossover_b2_b3"
   },
   {
    "label": "crossover b3 b4",
    "min": 20,
    "max": 20000,
    "default": 1700,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Echo/crossover_b3_b4"
   },
   {
    "label": "crossover b4 b5",
    "min": 20,
    "max": 20000,
    "default": 5000,
    "step": 1.08,
    "unit": "",
    "path": "/MultiBand_Echo/crossover_b4_b5"
   },
   {
    "label": "time1",
    "min": 24,
    "max": 360,
    "default": 30,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Echo/time1"
   },
   {
    "label": "percent1",
    "min": 0,
    "max": 100,
    "default": 10,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Echo/percent1"
   },
   {
    "label": "time2",
    "min": 24,
    "max": 360,
    "default": 60,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Echo/time2"
   },
   {
    "label": "percent2",
    "min": 0,
    "max": 100,
    "default": 30,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Echo/percent2"
   },
   {
    "label": "time3",
    "min": 24,
    "max": 360,
    "default": 120,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Echo/time3"
   },
   {
    "label": "percent3",
    "min": 0,
    "max": 100,
    "default": 45,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Echo/percent3"
   },
   {
    "label": "time4",
    "min": 24,
    "max": 360,
    "default": 150,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Echo/time4"
   },
   {
    "label": "percent4",
    "min": 0,
    "max": 100,
    "default": 20,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Echo/percent4"
   },
   {
    "label": "time5",
    "min": 24,
    "max": 360,
    "default": 240,
    "step": 1,
    "unit": "",
    "path": "/MultiBand_Echo/time5"
   },
   {
    "label": "percent5",
    "min": 0,
    "max": 100,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/MultiBand_Echo/percent5"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/mbe.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare id \"mbe\";\ndeclare name \"MultiBand Echo\";\ndeclare shortname \"MB Echo\";\ndeclare category \"Echo / Delay\";\ndeclare description \"Multi Band Echo\";\n\nimport(\"stdfaust.lib\");\nrd = library(\"reducemaps.lib\");\n\nhifr1      =hslider(\"crossover_b1_b2 [log][name:Crossover B1-B2 (hz)][tooltip: Crossover fi.bandpass frequency]\" ,80 , 20, 20000, 1.08);\nhifr2      =hslider(\"crossover_b2_b3 [log][name:Crossover B2-B3 (hz)][tooltip: Crossover fi.bandpass frequency]\",210,20,20000,1.08);\nhifr3      =hslider(\"crossover_b3_b4 [log][name:Crossover B3-B4 (hz)][tooltip: Crossover fi.bandpass frequency]\",1700,20,20000,1.08);\nhifr4      =hslider(\"crossover_b4_b5 [log][name:Crossover B4-B5 (hz)][tooltip: Crossover fi.bandpass frequency]\",5000,20,20000,1.08);\n\ngeq = fi.filterbank(3, (hifr1,hifr2,hifr3,hifr4));\n\n      \nt1 = ba.tempo(hslider(\"time1[tooltip:Echo in Beats per Minute]\",30,24,360,1));\nr1 = hslider(\"percent1\", 10, 0,  100, 0.1)/100.0 : si.smooth(0.999);\nt2 = ba.tempo(hslider(\"time2[tooltip:Echo in Beats per Minute]\",60,24,360,1));\nr2 = hslider(\"percent2\", 30, 0,  100, 0.1)/100.0 : si.smooth(0.999);\nt3 = ba.tempo(hslider(\"time3[tooltip:Echo in Beats per Minute]\",120,24,360,1));\nr3 = hslider(\"percent3\", 45, 0,  100, 0.1)/100.0 : si.smooth(0.999);\nt4 = ba.tempo(hslider(\"time4[tooltip:Echo in Beats per Minute]\",150,24,360,1));\nr4 = hslider(\"percent4\", 20, 0,  100, 0.1)/100.0 : si.smooth(0.999);\nt5 = ba.tempo(hslider(\"time5[tooltip:Echo in Beats per Minute]\",240,24,360,1));\nr5 = hslider(\"percent5\", 0, 0,  100, 0.1)/100.0 : si.smooth(0.999);\n\nvmeter1(x)\t\t= attach(x, envelop(x) : vbargraph(\"v1[nomidi:no]\", -70, +5));\nvmeter2(x)\t\t= attach(x, envelop(x) : vbargraph(\"v2[nomidi:no]\", -70, +5));\nvmeter3(x)\t\t= attach(x, envelop(x) : vbargraph(\"v3[nomidi:no]\", -70, +5));\nvmeter4(x)\t\t= attach(x, envelop(x) : vbargraph(\"v4[nomidi:no]\", -70, +5));\nvmeter5(x)\t\t= attach(x, envelop(x) : vbargraph(\"v5[nomidi:no]\", -70, +5));\n\nenvelop         = abs : max ~ (1.0/ma.SR) : rd.maxn(4096) ;\n//envelop         = abs : max ~ (1.0/ma.SR) : mean(4096) ; // : max(ba.db2linear(-70)) : ba.linear2db;\n\necho1(t,r)  = +~(de.sdelay(int(2^18), 100*ma.SR/1000.0, t) * (r));\n\nprocess    = geq: ( dist5s , dist4s , dist3s, dist2s, dist1s) :>_ with { \n    dist1s = echo1(t1,r1) : vmeter1 ;\n    dist2s = echo1(t2,r2) : vmeter2;\n    dist3s = echo1(t3,r3) : vmeter3;\n    dist4s = echo1(t4,r4) : vmeter4;\n    dist5s = echo1(t5,r5) : vmeter5;\n    \n};"
 },
 {
  "id": "tdg-multi-tap-echo",
  "name": "Multi-Tap Echo",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "thedrgreenthumb",
  "license": "MIT",
  "shortDesc": "Up to 12 evenly spaced echo taps with rising/falling level distribution, into a Schroeder reverb and LF/HF coloration",
  "description": "Up to 12 evenly spaced echo taps with rising/falling level distribution, into a Schroeder reverb and LF/HF coloration",
  "author": "thedrgreenthumb (Sergey Konstantinov)",
  "flags": "",
  "params": [
   {
    "label": "Taps",
    "min": 1,
    "max": 12,
    "default": 4,
    "step": 1,
    "unit": "",
    "path": "/Multi-Tap_Echo/Taps"
   },
   {
    "label": "Time",
    "min": 50,
    "max": 1000,
    "default": 100,
    "step": 1,
    "unit": "ms",
    "path": "/Multi-Tap_Echo/Time"
   },
   {
    "label": "Step",
    "min": 10,
    "max": 100,
    "default": 20,
    "step": 1,
    "unit": "ms",
    "path": "/Multi-Tap_Echo/Step"
   },
   {
    "label": "Distribution",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Multi-Tap_Echo/Distribution"
   },
   {
    "label": "Reverb",
    "min": 0,
    "max": 1,
    "default": 0.3,
    "step": 0.01,
    "unit": "",
    "path": "/Multi-Tap_Echo/Reverb"
   },
   {
    "label": "LF",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Multi-Tap_Echo/LF"
   },
   {
    "label": "HF",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Multi-Tap_Echo/HF"
   },
   {
    "label": "Taps Volume",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Multi-Tap_Echo/Taps_Volume"
   }
  ],
  "faustCode": "declare name \"Multi-Tap Echo\";\ndeclare description \"Up to 12 evenly spaced echo taps with rising/falling level distribution, into a Schroeder reverb and LF/HF coloration\";\ndeclare author \"thedrgreenthumb (Sergey Konstantinov)\";\ndeclare license \"MIT\";\ndeclare source \"thedrgreenthumb/faust rects/ech_01.dsp + rectangles.lib\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\n\npp_reps_num   = hslider(\"[0] Taps\", 4, 1, 12, 1);\npp_reps_time  = hslider(\"[1] Time[unit:ms]\", 100, 50, 1000, 1) : si.smoo;\npp_reps_rate  = hslider(\"[2] Step[unit:ms]\", 20, 10, 100, 1) : si.smoo;\npp_reps_distr = hslider(\"[3] Distribution\", 0, 0, 1, 0.01) : si.smoo;\npp_rev        = hslider(\"[4] Reverb\", 0.3, 0, 1, 0.01) : si.smoo;\npp_lf         = hslider(\"[5] LF\", 0.5, 0, 1, 0.01) : si.smoo : -(0.5) : *(2);\npp_hf         = hslider(\"[6] HF\", 0.5, 0, 1, 0.01) : si.smoo : -(0.5) : *(2);\npp_reps_vol   = hslider(\"[7] Taps Volume\", 0.5, 0, 1, 0.01) : si.smoo;\n\nN = 12;\nmix2(c,x,y) = (1-c)*x + c*y;\nget_delay_length(x) = x*ma.SR*0.001;\ntaps_distr0 = (1,0.9,0.85,0.8,0.75,0.7,0.65,0.6,0.55,0.5,0.45,0.4);\ntaps_distr1 = (0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,1);\nallpass(dt,fb) = (_,_ <: (*(fb),_:+:@(dt)), -) ~ _ : (!,_);\ncomb(dt, fb, damp) = (+:@(dt)) ~ (*(1-damp) : (+ ~ *(damp)) : *(fb));\nschoeders2(fb1, fb2, damp, spread) = _ <: par(i, 8, comb(ba.take(i+1, (1116,1188,1277,1356,1422,1491,1557,1617))+spread, fb1, damp)) :> allpass(556, fb2) : allpass(441, fb2);\nreverb(mix) = _ <: (schoeders2(0.7, 0.25, 0.7, 1000) : fi.lowpass(2,4000) : _*0.5), _ : mix2(1 - mix);\ncoloration_filter2(lf, hf) = _ <: (fi.lowshelf(5,lf*12,440), fi.highshelf(5,hf*12,880)) :> _*ba.db2linear(-12);\ntaps = par(i, N, de.fdelay(131072, get_delay_length(pp_reps_time)+i*get_delay_length(pp_reps_rate)) : *(pp_reps_vol) : *(i < pp_reps_num))\n    <: par(i,N,_*ba.take(i+1,taps_distr0)), par(i,N,_*ba.take(i+1,taps_distr1)) : ro.interleave(12,2) : par(i,N,mix2(pp_reps_distr)) :> _;\nprocess = _ <: _, (taps : reverb(pp_rev) : coloration_filter2(pp_lf,pp_hf)) :> _;"
 },
 {
  "id": "ex-pitch-feedback-delay",
  "name": "Pitch Feedback Delay",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "Faust examples",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Mono version of the Bela crossDelay2 example: pre-delay, filtered feedback and a pitch shifter inside the loop - each repeat climbs or falls",
  "description": "Mono version of the Bela crossDelay2 example: pre-delay, filtered feedback and a pitch shifter inside the loop - each repeat climbs or falls",
  "author": "GRAME (Bela examples)",
  "flags": "",
  "params": [
   {
    "label": "Pre-Delay",
    "min": 0,
    "max": 1000,
    "default": 0,
    "step": 1,
    "unit": "ms",
    "path": "/Pitch_Feedback_Delay/Pre-Delay"
   },
   {
    "label": "Delay",
    "min": 10,
    "max": 2000,
    "default": 400,
    "step": 1,
    "unit": "ms",
    "path": "/Pitch_Feedback_Delay/Delay"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.95,
    "default": 0.5,
    "step": 0.001,
    "unit": "",
    "path": "/Pitch_Feedback_Delay/Feedback"
   },
   {
    "label": "Feedback Lowpass",
    "min": 200,
    "max": 20000,
    "default": 6000,
    "step": 1,
    "unit": "Hz",
    "path": "/Pitch_Feedback_Delay/Feedback_Lowpass"
   },
   {
    "label": "Feedback Highpass",
    "min": 20,
    "max": 2000,
    "default": 80,
    "step": 1,
    "unit": "Hz",
    "path": "/Pitch_Feedback_Delay/Feedback_Highpass"
   },
   {
    "label": "Shift",
    "min": -12,
    "max": 12,
    "default": 5,
    "step": 0.01,
    "unit": "semi",
    "path": "/Pitch_Feedback_Delay/Shift"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Pitch_Feedback_Delay/Mix"
   }
  ],
  "faustCode": "declare name \"Pitch Feedback Delay\";\ndeclare description \"Mono version of the Bela crossDelay2 example: pre-delay, filtered feedback and a pitch shifter inside the loop - each repeat climbs or falls\";\ndeclare author \"GRAME (Bela examples)\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faust/examples/bela/crossDelay2.dsp\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\n\npreDel   = hslider(\"[0] Pre-Delay[unit:ms]\", 0, 0, 1000, 1) : *(ma.SR/1000) : si.smoo;\ndel      = hslider(\"[1] Delay[unit:ms]\", 400, 10, 2000, 1) : *(ma.SR/1000) : si.smoo;\nfeedback = hslider(\"[2] Feedback\", 0.5, 0, 0.95, 0.001) : si.smoo;\nfeedbLF  = hslider(\"[3] Feedback Lowpass[unit:Hz][scale:log]\", 6000, 200, 20000, 1) : si.smoo;\nfeedbHF  = hslider(\"[4] Feedback Highpass[unit:Hz][scale:log]\", 80, 20, 2000, 1) : si.smoo;\npitch    = hslider(\"[5] Shift[unit:semi]\", 5, -12, 12, 0.01) : si.smoo;\nmix      = hslider(\"[6] Mix\", 0.5, 0, 1, 0.01) : si.smoo;\n\nloop = de.sdelay(65536, 512, preDel) : (+ : de.sdelay(65536, 512, del)) ~ (ef.transpose(512, 256, pitch) : *(feedback) : fi.lowpass(2, feedbLF) : fi.highpass(2, feedbHF));\nprocess = _ <: *(1-mix), (loop : *(mix)) :> _;"
 },
 {
  "id": "lib-reverse-echo",
  "name": "Reverse Echo",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "N overlapping reverse-delay ramps (ef.reverseEchoN) - backwards-tape swells",
  "description": "N overlapping reverse-delay ramps (ef.reverseEchoN) - backwards-tape swells",
  "author": "Grame",
  "flags": "",
  "params": [
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Reverse_Echo/Mix"
   }
  ],
  "faustCode": "declare name \"Reverse Echo\";\ndeclare description \"N overlapping reverse-delay ramps (ef.reverseEchoN) - backwards-tape swells\";\ndeclare author \"Grame\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/misceffects.lib ef.reverseEchoN\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\n\nN = 4;\ndelMax = 48000;\nmix = hslider(\"[0] Mix\", 0.5, 0, 1, 0.01) : si.smoo;\nwet = ef.reverseEchoN(N, delMax) :> /(N) : *(1.5);\nprocess = _ <: *(1-mix), (wet : *(mix)) :> _;"
 },
 {
  "id": "lib-echo",
  "name": "Simple Echo",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "faustlibraries",
  "license": "LGPL-2.1-or-later",
  "shortDesc": "Plain feedback echo (ef.echo) with tone control in the feedback loop",
  "description": "Plain feedback echo (ef.echo) with tone control in the feedback loop",
  "author": "Grame",
  "flags": "",
  "params": [
   {
    "label": "Time",
    "min": 10,
    "max": 2000,
    "default": 375,
    "step": 1,
    "unit": "ms",
    "path": "/Simple_Echo/Time"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.95,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/Simple_Echo/Feedback"
   },
   {
    "label": "Tone",
    "min": 500,
    "max": 12000,
    "default": 4000,
    "step": 1,
    "unit": "Hz",
    "path": "/Simple_Echo/Tone"
   },
   {
    "label": "Mix",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/Simple_Echo/Mix"
   }
  ],
  "faustCode": "declare name \"Simple Echo\";\ndeclare description \"Plain feedback echo (ef.echo) with tone control in the feedback loop\";\ndeclare author \"Grame\";\ndeclare license \"LGPL-2.1-or-later\";\ndeclare source \"grame-cncm/faustlibraries/misceffects.lib ef.echo\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\n\ntime = hslider(\"[0] Time[unit:ms]\", 375, 10, 2000, 1) : si.smoo : /(1000);\nfb   = hslider(\"[1] Feedback\", 0.4, 0, 0.95, 0.01) : si.smoo;\ntone = hslider(\"[2] Tone[unit:Hz][scale:log]\", 4000, 500, 12000, 1) : si.smoo;\nmix  = hslider(\"[3] Mix\", 0.4, 0, 1, 0.01) : si.smoo;\necho = (+ : de.delay(2*48000, max(1, time*ma.SR))) ~ (fi.lowpass(1, tone) : *(fb));\nprocess = _ <: *(1-mix), (echo : *(mix)) :> _;"
 },
 {
  "id": "owl-smooth-delay",
  "name": "Smooth Delay",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "OWL patches",
  "license": "LicenseRef-STK-4.3",
  "shortDesc": "Yann Orlarey's click-free variable delay (de.sdelay) with feedback - delay time can be swept live without zipper noise",
  "description": "Yann Orlarey's click-free variable delay (de.sdelay) with feedback - delay time can be swept live without zipper noise",
  "author": "Yann Orlarey (GRAME), OWL wrapper Rebel Technology",
  "flags": "",
  "params": [
   {
    "label": "Delay",
    "min": 1,
    "max": 2000,
    "default": 300,
    "step": 0.1,
    "unit": "ms",
    "path": "/Smooth_Delay/Delay"
   },
   {
    "label": "Feedback",
    "min": 0,
    "max": 0.98,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/Smooth_Delay/Feedback"
   },
   {
    "label": "Interpolation",
    "min": 1,
    "max": 100,
    "default": 10,
    "step": 0.1,
    "unit": "ms",
    "path": "/Smooth_Delay/Interpolation"
   },
   {
    "label": "Dry/Wet",
    "min": 0,
    "max": 1,
    "default": 0.4,
    "step": 0.01,
    "unit": "",
    "path": "/Smooth_Delay/Dry_Wet"
   }
  ],
  "faustCode": "declare name \"Smooth Delay\";\ndeclare description \"Yann Orlarey's click-free variable delay (de.sdelay) with feedback - delay time can be swept live without zipper noise\";\ndeclare author \"Yann Orlarey (GRAME), OWL wrapper Rebel Technology\";\ndeclare license \"LicenseRef-STK-4.3\";\ndeclare source \"pingdynasty/OwlPatches Faust/SmoothDelay.dsp\";\ndeclare category \"guitar\";\ndeclare family \"time\";\nimport(\"stdfaust.lib\");\n\ndtime  = hslider(\"[0] Delay[unit:ms]\", 300, 1, 2000, 0.1) * ma.SR/1000.0 : si.smooth(0.999);\nfback  = hslider(\"[1] Feedback\", 0.4, 0, 0.98, 0.01) : si.smoo;\ninterp = hslider(\"[2] Interpolation[unit:ms]\", 10, 1, 100, 0.1) * ma.SR/1000.0;\nmix    = hslider(\"[3] Dry/Wet\", 0.4, 0, 1, 0.01) : si.smoo;\n\nN = int(2^17);\nsmoothdelay = (+ : de.sdelay(N, interp, dtime)) ~ *(fback);\nprocess = _ <: *(1-mix), (*(mix) : smoothdelay) :> _;"
 },
 {
  "id": "gx-stereodelay",
  "name": "Stereo Delay",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Two-channel delay with independent L/R time and gain plus an LFO; summed to mono here.",
  "description": "Independent left and right delay times and gains with an LFO modulator; wrapped to mono for the pedal, so it behaves as a dual-tap delay.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "LFO freq",
    "min": 0,
    "max": 5,
    "default": 0.2,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Stereo_Delay/LFO_freq"
   },
   {
    "label": "l gain",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Stereo_Delay/l_gain"
   },
   {
    "label": "r gain",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Stereo_Delay/r_gain"
   },
   {
    "label": "l delay",
    "min": 0,
    "max": 5000,
    "default": 0,
    "step": 10,
    "unit": "",
    "path": "/Stereo_Delay/l_delay"
   },
   {
    "label": "r delay",
    "min": 0,
    "max": 5000,
    "default": 0,
    "step": 10,
    "unit": "",
    "path": "/Stereo_Delay/r_delay"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/stereodelay.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Stereo Delay\";\ndeclare category \"Echo / Delay\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\nmsec\t= ma.SR/1000.0;\n\nlfol = os.oscrs; // sine for left channel\n\nfreq\t = hslider(\"LFO freq [unit:Hz]\", 0.2, 0, 5, 0.01);\npingpong   = checkbox(\"invert[enum:linear|pingpong]\");\nl_gain = vslider(\"l_gain\", 0, -20, 20, 0.1) : ba.db2linear : smoothi(0.999);\nr_gain = vslider(\"r_gain\", 0, -20, 20, 0.1) : ba.db2linear : smoothi(0.999);\nd = vslider(\"l_delay\", 0, 0, 5000, 10)*msec;\nr = vslider(\"r_delay\", 0, 0, 5000, 10)*msec;\nprocess_wide = (_ <: _ + l_gain*(1-(lfol(freq)*pingpong)) * de.sdelay(262144, 1024, d) :> _),\n\t\t  (_ <: _ + r_gain*(1-((-1*lfol(freq))*pingpong)) * de.sdelay(262144, 1024, r) :> _);\n\n// mono wrapper added by the Chameleon port (pedal is mono in / mono out)\nprocess = _ <: process_wide :> *(0.5);"
 },
 {
  "id": "gx-stereoecho",
  "name": "Stereo Echo",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Two-channel echo with independent L/R time and feedback plus an LFO; summed to mono here.",
  "description": "Independent left and right echo times and feedback percentages with an LFO modulator; wrapped to mono for the pedal, so it behaves as a dual-tap echo.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "LFO freq",
    "min": 0,
    "max": 5,
    "default": 0.2,
    "step": 0.01,
    "unit": "Hz",
    "path": "/Stereo_Echo/LFO_freq"
   },
   {
    "label": "time l",
    "min": 1,
    "max": 2000,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Stereo_Echo/time_l"
   },
   {
    "label": "percent l",
    "min": 0,
    "max": 100,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Stereo_Echo/percent_l"
   },
   {
    "label": "time r",
    "min": 1,
    "max": 2000,
    "default": 1,
    "step": 1,
    "unit": "",
    "path": "/Stereo_Echo/time_r"
   },
   {
    "label": "percent r",
    "min": 0,
    "max": 100,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Stereo_Echo/percent_r"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/stereoecho.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Stereo Echo\";\ndeclare category \"Echo / Delay\";\n\nimport(\"stdfaust.lib\");\nimport(\"guitarix.lib\");\nmsec\t= ma.SR/1000.0;\n\nlfol = os.oscrs; // sine for left channel\n\nfreq\t = hslider(\"LFO freq [unit:Hz]\", 0.2, 0, 5, 0.01);\npingpong   = checkbox(\"invert[enum:linear|pingpong]\");\n\ntl = vslider(\"time_l\", 1, 1, 2000, 1);\nreleasel = vslider(\"percent_l\", 0, 0,  100, 0.1);\ntr = vslider(\"time_r\", 1, 1, 2000, 1);\nreleaser = vslider(\"percent_r\", 0, 0,  100, 0.1);\n\necho1  = +~(de.sdelay(131072, 1024,  int(tl*ba.millisec)-1) * ((releasel/100.0)*(1-(lfol(freq)*pingpong))) );\necho2  = +~(de.sdelay(131072, 1024,  int(tr*ba.millisec)-1) * ((releaser/100.0)*(1-((-1*lfol(freq))*pingpong))) );\nprocess_wide = echo1,echo2;\n\n// mono wrapper added by the Chameleon port (pedal is mono in / mono out)\nprocess = _ <: process_wide :> *(0.5);"
 },
 {
  "id": "gx-gxtubedelay",
  "name": "Tube Delay",
  "category": "guitar",
  "family": "time",
  "familyName": "Delay",
  "icon": "tabler:repeat",
  "tag": "Guitar",
  "source": "guitarix",
  "license": "GPL-2.0-or-later",
  "shortDesc": "Up to 2.5 s delay wrapped in 12AX7 input and output tube stages with filtered feedback.",
  "description": "A feedback delay (up to 2.5 s) placed between 12AX7 input and output tube-table stages, with a high/low-pass in the feedback loop to prevent runaway. Drive adds tube grit; Level, Feedback, Delay and Output complete the set.",
  "author": "",
  "flags": "-double",
  "params": [
   {
    "label": "Drive",
    "min": 0,
    "max": 1,
    "default": 0.5,
    "step": 0.01,
    "unit": "",
    "path": "/Tube_Delay/Drive"
   },
   {
    "label": "level",
    "min": 0,
    "max": 1,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Tube_Delay/level"
   },
   {
    "label": "feedback",
    "min": 0,
    "max": 0.7,
    "default": 0,
    "step": 0.01,
    "unit": "",
    "path": "/Tube_Delay/feedback"
   },
   {
    "label": "de.delay",
    "min": 0.1,
    "max": 2500,
    "default": 0.1,
    "step": 0.1,
    "unit": "ms",
    "path": "/Tube_Delay/de.delay"
   },
   {
    "label": "output",
    "min": -20,
    "max": 20,
    "default": 0,
    "step": 0.1,
    "unit": "",
    "path": "/Tube_Delay/output"
   }
  ],
  "faustCode": "// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/gxtubedelay.dsp (GPL-2.0-or-later).\ndeclare license \"GPL-2.0-or-later\";\ndeclare chameleon_flags \"-double\";   // DK circuit sims are numerically unstable in single precision\ndeclare name \"Tube Delay\";\ndeclare category \"Echo / Delay\";\n\nimport(\"stdfaust.lib\");\nimport(\"redeye.lib\");\n\nLogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);\nlevel = vslider(\"level[style:knob]\", 0, 0, 1, 0.1):LogPot(1):si.smooth(0.993);\nfeedback = vslider(\"feedback[style:knob]\", 0, 0.0, 0.7, 0.01);\ndtime\t= vslider(\"de.delay[unit:ms][style:knob]\", 0.1, 0.1, 2500, 0.1)*ma.SR/1000.0;\noutput = vslider(\"output[style:knob]\", 0.0, -20.0, 20.0, 0.1):ba.db2linear:si.smooth(0.993);\ninterp = 100*ma.SR/1000.0;\n\n// for a 2.5 sec de.delay\nN = int( 2^17 ) ;\ndelayed = de.sdelay(N, interp, dtime) ;\n\n// added a de.delay bypass output to get a real tape de.delay,\n// and a low/fi.highpass filter section in the feedback loop\n// to avoid self oscillation\n\namp =  input12ax7<:((+:_<:_ ,( delayed:*(level)) :>_)~(*(feedback): fi.highpass(2,120.0):fi.lowpass(2,12000.0))):>output12ax7:*(output);\nfreq_split = fi.filterbank(3, (86.0,210.0,1200.0,6531.0));\nprocess    = freq_split: ( amp , amp , amp, amp, amp) :>_;"
 }
];

const FAMILY_NAMES = {"time":"Delay","reverb":"Reverb","mod":"Modulation","dirt":"Dirt","dynamics":"Dynamics","filter":"Filter","pitch":"Pitch","amp":"Amp & Tube","utility":"Utility","eq":"EQ & Tone"};
function getEffectById(id) { return EFFECTS_CATALOG.find(e => e.id === id) || null; }
