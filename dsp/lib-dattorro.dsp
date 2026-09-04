declare name "Dattorro Plate";
declare description "Jon Dattorro's 1997 figure-of-eight plate reverb (input diffusion + modulated tank)";
declare author "Jakob Zerbian (Faust port), Jon Dattorro";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faustlibraries/reverbs.lib re.dattorro_rev";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

bw    = hslider("[0] Bandwidth", 0.7, 0, 1, 0.001) : si.smoo;
idiff = hslider("[1] Input Diffusion", 0.625, 0, 1, 0.001) : si.smoo;
decay = hslider("[2] Decay", 0.6, 0, 0.99, 0.001) : si.smoo;
ddiff = hslider("[3] Tank Diffusion", 0.625, 0, 1, 0.001) : si.smoo;
damp  = hslider("[4] Damping", 0.5, 0, 1, 0.001) : si.smoo;
mix   = hslider("[5] Mix", 0.35, 0, 1, 0.01) : si.smoo;

wet = _ <: re.dattorro_rev(0, bw, idiff, idiff*0.8, decay, ddiff*1.12, ddiff, damp) :> *(0.5);
process = _ <: *(1-mix), (wet : *(mix)) :> _;
