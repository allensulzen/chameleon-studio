declare name "PumpingDrumCompressor";
declare description "Fast VCA bus compressor with exaggerated pump and auto make-up";
declare author "Chameleon DSP";
import("stdfaust.lib");

thresh = hslider("Threshold[unit:dB]", -22, -40, 0, 1) : si.smoo;
rel    = hslider("Pump Release[unit:ms]", 140, 40, 600, 5) * 0.001 : si.smoo;
blend  = hslider("Blend", 0.9, 0, 1.0, 0.01) : si.smoo;

ratio  = 8;
makeup = -thresh * (1 - 1/ratio) * 0.7 : ba.db2linear;
comp(x) = co.compressor_mono(ratio, thresh, 0.0015, rel, x) * makeup;
ceiling(x) = ma.tanh(x);

process(x) = x * (1 - blend) + (comp(x) : ceiling) * blend;
