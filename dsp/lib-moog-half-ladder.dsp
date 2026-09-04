declare name "Moog Half Ladder";
declare description "2-pole Moog half-ladder lowpass (Zavalishin VA) - the lighter, brighter cousin of the 4-pole ladder";
declare author "Eric Tarr";
declare license "MIT";
declare source "grame-cncm/faustlibraries/vaeffects.lib ve.moogHalfLadder";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

freq  = hslider("[0] Cutoff[unit:Hz][scale:log]", 1500, 40, 12000, 1) : si.smoo;
q     = hslider("[1] Resonance", 2, 0.707, 20, 0.01) : si.smoo;
drive = hslider("[2] Drive[unit:dB]", 0, 0, 30, 0.1) : ba.db2linear : si.smoo;
level = hslider("[3] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;
normFreq = log10(max(20, freq)/20) / 3 : min(0.99);
process = *(drive) : ve.moogHalfLadder(normFreq, max(0.707, q)) : *(level);
