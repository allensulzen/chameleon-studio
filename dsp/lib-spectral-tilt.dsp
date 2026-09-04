declare name "Spectral Tilt";
declare description "JOS spectral tilt filter: constant-slope dB/octave tilt across a chosen band (pink/brown-ish shaping)";
declare author "Julius O. Smith III";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faust/examples/filtering/spectralTilt.dsp fi.spectral_tilt";
declare category "guitar";
declare family "utility";
import("stdfaust.lib");

alpha = hslider("[0] Slope", -0.5, -1, 1, 0.001) : si.smoo;
f0    = hslider("[1] Band Start[unit:Hz][scale:log]", 100, 20, 10000, 1);
bw    = hslider("[2] Band Width[unit:Hz]", 5000, 100, 10000, 1);
level = hslider("[3] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;
process = fi.spectral_tilt(4, f0, bw, alpha) : *(level);
