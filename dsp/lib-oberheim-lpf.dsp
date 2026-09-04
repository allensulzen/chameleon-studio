declare name "Oberheim SEM LPF";
declare description "Oberheim SEM state-variable lowpass (Zavalishin VA model) - smooth, musical resonance";
declare author "Eric Tarr";
declare license "MIT";
declare source "grame-cncm/faustlibraries/vaeffects.lib ve.oberheimLPF";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

freq  = hslider("[0] Cutoff[unit:Hz][scale:log]", 1500, 40, 12000, 1) : si.smoo;
q     = hslider("[1] Resonance", 1.5, 0.5, 10, 0.01) : si.smoo;
level = hslider("[2] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;

normFreq = log10(max(20, freq)/20) / 3 : min(0.99);
process = ve.oberheimLPF(normFreq, max(0.5, q)) : *(level);
