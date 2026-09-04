declare name "Sallen-Key LPF";
declare description "2nd-order Sallen-Key virtual-analog lowpass (Zavalishin) - smooth op-amp filter tone";
declare author "Eric Tarr";
declare license "MIT";
declare source "grame-cncm/faustlibraries/vaeffects.lib ve.sallenKey2ndOrderLPF";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

freq  = hslider("[0] Cutoff[unit:Hz][scale:log]", 2000, 40, 12000, 1) : si.smoo;
q     = hslider("[1] Resonance", 1, 0.5, 10, 0.01) : si.smoo;
level = hslider("[2] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;

normFreq = log10(max(20, freq)/20) / 3 : min(0.99);
process = ve.sallenKey2ndOrderLPF(normFreq, max(0.5, q)) : *(level);
