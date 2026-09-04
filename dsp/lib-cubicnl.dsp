declare name "Cubic Soft Clip";
declare description "JOS cubic nonlinearity distortion with DC offset for even harmonics and a tone control";
declare author "Julius O. Smith III";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/misceffects.lib ef.cubicnl";
declare category "guitar";
declare family "dirt";
import("stdfaust.lib");

drive  = hslider("[0] Drive", 0.5, 0, 1, 0.01) : si.smoo;
offset = hslider("[1] Offset", 0.1, 0, 0.5, 0.01) : si.smoo;
tone   = hslider("[2] Tone[unit:Hz][scale:log]", 4000, 500, 12000, 1) : si.smoo;
level  = hslider("[3] Level[unit:dB]", -3, -30, 12, 0.1) : ba.db2linear : si.smoo;
process = ef.cubicnl_nodc(drive, offset) : fi.lowpass(1, tone) : *(level);
