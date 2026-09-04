declare name "Parametric EQ";
declare description "Low shelf + peaking band + high shelf (fi.low_shelf / fi.peak_eq / fi.high_shelf) from the Faust parametric EQ example";
declare author "Julius O. Smith III";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faust/examples/filtering/parametricEqualizer.dsp dm.parametric_eq_demo";
declare category "guitar";
declare family "utility";
import("stdfaust.lib");

LL = hslider("[0] Low Gain[unit:dB]", 0, -20, 20, 0.1) : si.smoo;
FL = hslider("[1] Low Freq[unit:Hz][scale:log]", 200, 20, 2000, 1) : si.smoo;
LP = hslider("[2] Peak Gain[unit:dB]", 0, -20, 20, 0.1) : si.smoo;
FP = hslider("[3] Peak Freq[unit:Hz][scale:log]", 1000, 60, 8000, 1) : si.smoo;
Q  = hslider("[4] Peak Q", 2, 0.5, 20, 0.1);
LH = hslider("[5] High Gain[unit:dB]", 0, -20, 20, 0.1) : si.smoo;
FH = hslider("[6] High Freq[unit:Hz][scale:log]", 4000, 1000, 12000, 1) : si.smoo;
process = fi.low_shelf(LL, FL) : fi.peak_eq(LP, FP, FP/Q) : fi.high_shelf(LH, FH);
