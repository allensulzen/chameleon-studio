declare name "Phaser 8 Notch";
declare description "JOS phaser2 with 8 swept notches, feedback and depth - thick, deep phase sweep";
declare author "Julius O. Smith III";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faustlibraries/phaflangers.lib pf.phaser2_mono";
declare category "guitar";
declare family "mod";
import("stdfaust.lib");

speed = hslider("[0] Speed[unit:Hz]", 0.5, 0, 10, 0.001) : si.smoo;
depth = hslider("[1] Depth", 1, 0, 1, 0.001) : si.smoo;
fb    = hslider("[2] Feedback", 0.3, -0.95, 0.95, 0.001) : si.smoo;
width = hslider("[3] Notch Width[unit:Hz][scale:log]", 1000, 10, 5000, 1) : si.smoo;
fmin  = hslider("[4] Min Notch[unit:Hz][scale:log]", 100, 20, 5000, 1);
fmax  = hslider("[5] Max Notch[unit:Hz][scale:log]", 800, 20, 10000, 1);
ratio = hslider("[6] Notch Ratio", 1.5, 1.1, 4, 0.01);
process = pf.phaser2_mono(8, 0, width, fmin, ratio, fmax, speed, depth, fb, 0);
