declare name "Korg 35 HPF";
declare description "MS-20 style Korg35 resonant highpass - thin, squelchy filter sweeps";
declare author "Eric Tarr";
declare license "MIT";
declare source "grame-cncm/faustlibraries/vaeffects.lib ve.korg35HPF";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

freq  = hslider("[0] Cutoff[unit:Hz][scale:log]", 300, 20, 8000, 1) : si.smoo;
q     = hslider("[1] Resonance", 2, 0.707, 9.9, 0.01) : si.smoo;
level = hslider("[2] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;

normFreq = log10(max(20, freq)/20) / 3 : min(0.99);
process = ve.korg35HPF(normFreq, max(0.707, q)) : ma.tanh : *(level);
