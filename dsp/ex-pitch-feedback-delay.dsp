declare name "Pitch Feedback Delay";
declare description "Mono version of the Bela crossDelay2 example: pre-delay, filtered feedback and a pitch shifter inside the loop - each repeat climbs or falls";
declare author "GRAME (Bela examples)";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faust/examples/bela/crossDelay2.dsp";
declare category "guitar";
declare family "time";
import("stdfaust.lib");

preDel   = hslider("[0] Pre-Delay[unit:ms]", 0, 0, 1000, 1) : *(ma.SR/1000) : si.smoo;
del      = hslider("[1] Delay[unit:ms]", 400, 10, 2000, 1) : *(ma.SR/1000) : si.smoo;
feedback = hslider("[2] Feedback", 0.5, 0, 0.95, 0.001) : si.smoo;
feedbLF  = hslider("[3] Feedback Lowpass[unit:Hz][scale:log]", 6000, 200, 20000, 1) : si.smoo;
feedbHF  = hslider("[4] Feedback Highpass[unit:Hz][scale:log]", 80, 20, 2000, 1) : si.smoo;
pitch    = hslider("[5] Shift[unit:semi]", 5, -12, 12, 0.01) : si.smoo;
mix      = hslider("[6] Mix", 0.5, 0, 1, 0.01) : si.smoo;

loop = de.sdelay(65536, 512, preDel) : (+ : de.sdelay(65536, 512, del)) ~ (ef.transpose(512, 256, pitch) : *(feedback) : fi.lowpass(2, feedbLF) : fi.highpass(2, feedbHF));
process = _ <: *(1-mix), (loop : *(mix)) :> _;
