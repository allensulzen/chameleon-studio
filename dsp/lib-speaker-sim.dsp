declare name "Speaker Bandpass";
declare description "Simple cabinet emulation: two DC-blocking highpasses and a 4th-order Butterworth lowpass";
declare author "Julius O. Smith III";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/misceffects.lib ef.speakerbp";
declare category "guitar";
declare family "utility";
import("stdfaust.lib");

f1 = hslider("[0] Low Cut[unit:Hz][scale:log]", 130, 40, 400, 1) : si.smoo;
f2 = hslider("[1] High Cut[unit:Hz][scale:log]", 5000, 2000, 12000, 1) : si.smoo;
level = hslider("[2] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;
process = ef.speakerbp(f1, f2) : *(level);
