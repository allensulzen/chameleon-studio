declare name "Spring Tank";
declare description "Spring-flavoured reverb (Chaos Audio Stratus): diffusion into damped delay bank with Hadamard feedback";
declare author "Daniel Leonov";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faustlibraries/reverbs.lib re.springreverb";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

dwell   = hslider("[0] Dwell", 0.5, 0, 1, 0.01) : si.smoo;
blend   = hslider("[1] Blend", 0.5, 0, 1, 0.01) : si.smoo;
tone    = hslider("[2] Tone", 0.5, 0, 1, 0.01) : si.smoo;
tension = hslider("[3] Tension", 0.5, 0, 1, 0.01) : si.smoo;
springs = nentry("[4] Springs[style:menu{'Left':0;'Right':1;'Middle':2}]", 1, 0, 2, 1);
mix     = hslider("[5] Mix", 0.5, 0, 1, 0.01) : si.smoo;

process = _ <: *(1-mix), (re.springreverb(dwell, blend, tone, tension, springs) : *(mix)) :> _;
