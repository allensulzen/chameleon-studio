declare name "Shaped Tremolo";
declare description "Mono version of the Faust autopan example: LFO amplitude modulation with a tanh shape control (sine to square)";
declare author "GRAME";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faust/examples/misc/autopan.dsp";
declare category "guitar";
declare family "mod";
import("stdfaust.lib");

amount = hslider("[0] Depth", 0.7, 0, 1, 0.001) : si.smoo;
rate   = hslider("[1] Rate[unit:Hz][scale:log]", 4, 0.1, 30, 0.01) : si.smoo;
shape  = hslider("[2] Shape", 0.2, 0, 1, 0.001) : si.smoo;

saturator(sh, x) = x, ma.tanh(x*10.) : it.interpolate_linear(sh);
g = os.osc(rate) : saturator(shape) : it.remap(-1., 1., 1.-amount, 1.);
process = *(g);
