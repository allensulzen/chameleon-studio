declare name "Korg 35 LPF";
declare description "MS-20 style Korg35 2-pole lowpass with screaming self-oscillating resonance";
declare author "Eric Tarr";
declare license "MIT";
declare source "grame-cncm/faustlibraries/vaeffects.lib ve.korg35LPF";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

freq  = hslider("[0] Cutoff[unit:Hz][scale:log]", 1500, 40, 12000, 1) : si.smoo;
q     = hslider("[1] Resonance", 2, 0.707, 9.9, 0.01) : si.smoo;
drive = hslider("[2] Drive[unit:dB]", 0, 0, 30, 0.1) : ba.db2linear : si.smoo;
level = hslider("[3] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;

normFreq = log10(max(20, freq)/20) / 3 : min(0.99);
process = *(drive) : ve.korg35LPF(normFreq, max(0.707, q)) : ma.tanh : *(level);
