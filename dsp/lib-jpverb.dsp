declare name "JPverb";
declare description "Julian Parker's lush algorithmic reverb with modulation and 3-band decay";
declare author "Till Bovermann, Julian Parker";
declare license "GPL-2.0-or-later";
declare source "grame-cncm/faustlibraries/reverbs.lib re.jpverb";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

t60   = hslider("[0] Decay[unit:s]", 2, 0.1, 30, 0.1);
damp  = hslider("[1] Damping", 0.2, 0, 0.999, 0.001) : si.smoo;
size  = hslider("[2] Size", 1, 0.5, 3, 0.01);
ediff = hslider("[3] Early Diffusion", 0.707, 0, 0.99, 0.001) : si.smoo;
md    = hslider("[4] Mod Depth", 0.1, 0, 1, 0.001) : si.smoo;
mf    = hslider("[5] Mod Rate[unit:Hz]", 2, 0, 10, 0.01) : si.smoo;
low   = hslider("[6] Low Decay X", 1, 0, 1, 0.01) : si.smoo;
mid   = hslider("[7] Mid Decay X", 1, 0, 1, 0.01) : si.smoo;
high  = hslider("[8] High Decay X", 0.8, 0, 1, 0.01) : si.smoo;
lc    = hslider("[9] Low Band[unit:Hz]", 500, 100, 6000, 1);
hc    = hslider("[10] High Band[unit:Hz]", 2000, 1000, 10000, 1);
mix   = hslider("[11] Mix", 0.35, 0, 1, 0.01) : si.smoo;

wet = _ <: re.jpverb(t60, damp, size, ediff, md, mf, low, mid, high, lc, hc) :> *(0.5);
process = _ <: *(1-mix), (wet : *(mix)) :> _;
