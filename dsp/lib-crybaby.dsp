declare name "CryBaby Wah";
declare description "JOS digitization of the Dunlop CryBaby wah pedal (manual pedal position)";
declare author "Julius O. Smith III";
declare license "MIT";
declare source "grame-cncm/faustlibraries/vaeffects.lib ve.crybaby";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

wah   = hslider("[0] Pedal", 0.5, 0, 1, 0.01) : si.smoo;
level = hslider("[1] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;
process = ve.crybaby(wah) : *(level);
