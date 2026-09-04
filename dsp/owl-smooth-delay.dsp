declare name "Smooth Delay";
declare description "Yann Orlarey's click-free variable delay (de.sdelay) with feedback - delay time can be swept live without zipper noise";
declare author "Yann Orlarey (GRAME), OWL wrapper Rebel Technology";
declare license "LicenseRef-STK-4.3";
declare source "pingdynasty/OwlPatches Faust/SmoothDelay.dsp";
declare category "guitar";
declare family "time";
import("stdfaust.lib");

dtime  = hslider("[0] Delay[unit:ms]", 300, 1, 2000, 0.1) * ma.SR/1000.0 : si.smooth(0.999);
fback  = hslider("[1] Feedback", 0.4, 0, 0.98, 0.01) : si.smoo;
interp = hslider("[2] Interpolation[unit:ms]", 10, 1, 100, 0.1) * ma.SR/1000.0;
mix    = hslider("[3] Dry/Wet", 0.4, 0, 1, 0.01) : si.smoo;

N = int(2^17);
smoothdelay = (+ : de.sdelay(N, interp, dtime)) ~ *(fback);
process = _ <: *(1-mix), (*(mix) : smoothdelay) :> _;
