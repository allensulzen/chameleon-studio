declare name "Oberheim SEM BPF";
declare description "Oberheim SEM state-variable bandpass - honky, vocal band sweeps";
declare author "Eric Tarr";
declare license "MIT";
declare source "grame-cncm/faustlibraries/vaeffects.lib ve.oberheimBPF";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

freq  = hslider("[0] Center[unit:Hz][scale:log]", 800, 60, 8000, 1) : si.smoo;
q     = hslider("[1] Resonance", 2, 0.5, 10, 0.01) : si.smoo;
level = hslider("[2] Level[unit:dB]", 6, -20, 24, 0.1) : ba.db2linear : si.smoo;

normFreq = log10(max(20, freq)/20) / 3 : min(0.99);
process = ve.oberheimBPF(normFreq, max(0.5, q)) : *(level);
