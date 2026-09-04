declare name "Oberheim SEM HPF";
declare description "Oberheim SEM state-variable highpass - resonant thinning and telephone tones";
declare author "Eric Tarr";
declare license "MIT";
declare source "grame-cncm/faustlibraries/vaeffects.lib ve.oberheimHPF";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

freq  = hslider("[0] Cutoff[unit:Hz][scale:log]", 400, 20, 8000, 1) : si.smoo;
q     = hslider("[1] Resonance", 1.5, 0.5, 10, 0.01) : si.smoo;
level = hslider("[2] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;
normFreq = log10(max(20, freq)/20) / 3 : min(0.99);
process = ve.oberheimHPF(normFreq, max(0.5, q)) : *(level);
