declare name "Phase Vibrato";
declare description "JOS vibrato2: LFO-swept allpass sections give a pitch-wobble vibrato (Univibe-adjacent)";
declare author "Julius O. Smith III";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faustlibraries/phaflangers.lib pf.vibrato2_mono";
declare category "guitar";
declare family "mod";
import("stdfaust.lib");

speed = hslider("[0] Speed[unit:Hz]", 4, 0.1, 12, 0.01) : si.smoo;
width = hslider("[1] Width[unit:Hz]", 1000, 100, 4000, 1) : si.smoo;
fb    = hslider("[2] Feedback", 0, -0.9, 0.9, 0.01) : si.smoo;
fmin  = hslider("[3] Min Freq[unit:Hz][scale:log]", 200, 50, 1000, 1);
fmax  = hslider("[4] Max Freq[unit:Hz][scale:log]", 3000, 1000, 8000, 1);
process = pf.vibrato2_mono(4, 0, fb, width, fmin, 1.5, fmax, speed);
