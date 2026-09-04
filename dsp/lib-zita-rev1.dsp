declare name "Zita Rev1";
declare description "Fons Adriaensen's zita-rev1 8x8 FDN hall reverb, mono wrap with per-band decay";
declare author "Julius O. Smith III (Faust port of Fons Adriaensen's zita-rev1)";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faustlibraries/reverbs.lib re.zita_rev1_stereo";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

rdel  = hslider("[0] Pre-delay[unit:ms]", 40, 20, 100, 1);
f1    = hslider("[1] LF Crossover[unit:Hz][scale:log]", 200, 50, 1000, 1);
t60dc = hslider("[2] Low RT60[unit:s]", 3, 1, 8, 0.1);
t60m  = hslider("[3] Mid RT60[unit:s]", 2, 1, 8, 0.1);
f2    = hslider("[4] HF Damping[unit:Hz][scale:log]", 6000, 1500, 20000, 1);
mix   = hslider("[5] Mix", 0.35, 0, 1, 0.01) : si.smoo;

wet = _ <: re.zita_rev1_stereo(rdel, f1, f2, t60dc, t60m, 48000) :> *(0.5);
process = _ <: *(1-mix), (wet : *(mix)) :> _;
