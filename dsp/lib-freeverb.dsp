declare name "Freeverb";
declare description "Jezar's Freeverb: 8 lowpass-comb filters + 4 allpasses, the classic free reverb";
declare author "Romain Michon (Faust port), Jezar at Dreampoint";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/reverbs.lib re.mono_freeverb";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

size = hslider("[0] Room Size", 0.6, 0, 1, 0.01) : si.smoo;
damp = hslider("[1] Damping", 0.5, 0, 1, 0.01) : si.smoo;
mix  = hslider("[2] Mix", 0.35, 0, 1, 0.01) : si.smoo;

fb1 = 0.7 + 0.28 * size;
process = _ <: *(1-mix), (re.mono_freeverb(fb1, 0.5, damp*0.4, 0) : *(mix)) :> _;
