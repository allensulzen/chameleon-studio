declare name "InfiniteSustainCompressor";
declare description "High-ratio sustainer with automatic make-up gain and soft ceiling";
declare author "Chameleon DSP";
import("stdfaust.lib");

sustain = hslider("Sustain", 0.7, 0, 1.0, 0.01) : si.smoo;
att     = hslider("Attack[unit:ms]", 15, 1, 50, 1) * 0.001;
blend   = hslider("Blend", 0.85, 0, 1.0, 0.01) : si.smoo;

ratio   = 4 + sustain * 12;
thresh  = -12 - sustain * 36;         // dB
rel     = 0.25 + sustain * 0.45;      // longer release = more sustain
makeup  = -thresh * (1 - 1/ratio) * 0.8 : ba.db2linear;

comp(x) = co.compressor_mono(ratio, thresh, att, rel, x) * makeup;
ceiling(x) = ma.tanh(x);

process(x) = x * (1 - blend) + (comp(x) : ceiling) * blend;
