declare name "Moog VCF";
declare description "JOS Moog VCF (4 one-poles with feedback) - classic analog-style resonant lowpass";
declare author "Julius O. Smith III";
declare license "MIT";
declare source "grame-cncm/faustlibraries/vaeffects.lib ve.moog_vcf";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

freq  = hslider("[0] Cutoff[unit:Hz][scale:log]", 1200, 40, 10000, 1) : si.smoo;
res   = hslider("[1] Resonance", 0.6, 0, 0.99, 0.01) : si.smoo;
level = hslider("[2] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;
process = ve.moog_vcf(res, freq) : *(level);
