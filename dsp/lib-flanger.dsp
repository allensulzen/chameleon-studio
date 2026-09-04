declare name "Flanger Mono";
declare description "JOS flanger_mono: LFO-modulated short delay with bipolar feedback and invert";
declare author "Julius O. Smith III";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faustlibraries/phaflangers.lib pf.flanger_mono";
declare category "guitar";
declare family "mod";
import("stdfaust.lib");

speed = hslider("[0] Speed[unit:Hz]", 0.5, 0, 10, 0.01) : si.smoo;
depth = hslider("[1] Depth", 1, 0, 1, 0.001) : si.smoo;
fb    = hslider("[2] Feedback", 0.3, -0.95, 0.95, 0.001) : si.smoo;
dmax  = hslider("[3] Delay[unit:ms]", 6, 0.5, 20, 0.01) : si.smoo;
inv   = checkbox("[4] Invert");
curdel = dmax * ma.SR/1000 * (1 + os.oscrs(speed)) * 0.5;
process = pf.flanger_mono(2048, curdel, depth, fb, inv) : *(0.7);
