declare name "Wavefolder";
declare description "ef.wavefold triangle-style folding with pre-gain - Buchla/Serge-like harmonic bloom";
declare author "Grame";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/misceffects.lib ef.wavefold";
declare category "guitar";
declare family "dirt";
import("stdfaust.lib");

gain  = hslider("[0] Drive[unit:dB]", 12, 0, 40, 0.1) : ba.db2linear : si.smoo;
width = hslider("[1] Fold Width", 0.5, 0.05, 1, 0.01) : si.smoo;
tone  = hslider("[2] Tone[unit:Hz][scale:log]", 5000, 800, 12000, 1) : si.smoo;
level = hslider("[3] Level[unit:dB]", -6, -30, 12, 0.1) : ba.db2linear : si.smoo;
process = *(gain) : ma.tanh : ef.wavefold(max(0.05, width)) : fi.dcblocker : fi.lowpass(1, tone) : *(level);
