declare name "Reverse Echo";
declare description "N overlapping reverse-delay ramps (ef.reverseEchoN) - backwards-tape swells";
declare author "Grame";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/misceffects.lib ef.reverseEchoN";
declare category "guitar";
declare family "time";
import("stdfaust.lib");

N = 4;
delMax = 48000;
mix = hslider("[0] Mix", 0.5, 0, 1, 0.01) : si.smoo;
wet = ef.reverseEchoN(N, delMax) :> /(N) : *(1.5);
process = _ <: *(1-mix), (wet : *(mix)) :> _;
