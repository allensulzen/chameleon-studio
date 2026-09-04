declare name "Wah4 Moog";
declare description "JOS 4th-order wah built from a Moog VCF - fat, vowel-like pedal wah";
declare author "Julius O. Smith III";
declare license "MIT";
declare source "grame-cncm/faustlibraries/vaeffects.lib ve.wah4";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

fr    = hslider("[0] Pedal[unit:Hz][scale:log]", 800, 100, 2000, 1);
level = hslider("[1] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;
process = fi.dcblocker : ve.wah4(fr) : *(level);
