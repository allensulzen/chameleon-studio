declare name "Greyhole";
declare description "Diffuser in feedback with a long modulated delay - spacey, smeared washes (Eventide-inspired)";
declare author "Till Bovermann, Julian Parker";
declare license "GPL-2.0-or-later";
declare source "grame-cncm/faustlibraries/reverbs.lib re.greyhole";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

dt   = hslider("[0] Delay Time[unit:s]", 0.2, 0.001, 1.45, 0.001) : si.smoo;
damp = hslider("[1] Damping", 0.2, 0, 0.99, 0.001) : si.smoo;
size = hslider("[2] Size", 1, 0.5, 3, 0.01);
diff = hslider("[3] Diffusion", 0.5, 0, 0.99, 0.001) : si.smoo;
fb   = hslider("[4] Feedback", 0.7, 0, 1, 0.01) : si.smoo;
md   = hslider("[5] Mod Depth", 0.1, 0, 1, 0.001) : si.smoo;
mf   = hslider("[6] Mod Rate[unit:Hz]", 2, 0, 10, 0.01) : si.smoo;
mix  = hslider("[7] Mix", 0.4, 0, 1, 0.01) : si.smoo;

wet = _ <: re.greyhole(dt, damp, size, diff, fb, md, mf) :> *(0.5);
process = _ <: *(1-mix), (wet : *(mix)) :> _;
