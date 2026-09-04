declare name "Simple Echo";
declare description "Plain feedback echo (ef.echo) with tone control in the feedback loop";
declare author "Grame";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/misceffects.lib ef.echo";
declare category "guitar";
declare family "time";
import("stdfaust.lib");

time = hslider("[0] Time[unit:ms]", 375, 10, 2000, 1) : si.smoo : /(1000);
fb   = hslider("[1] Feedback", 0.4, 0, 0.95, 0.01) : si.smoo;
tone = hslider("[2] Tone[unit:Hz][scale:log]", 4000, 500, 12000, 1) : si.smoo;
mix  = hslider("[3] Mix", 0.4, 0, 1, 0.01) : si.smoo;
echo = (+ : de.delay(2*48000, max(1, time*ma.SR))) ~ (fi.lowpass(1, tone) : *(fb));
process = _ <: *(1-mix), (echo : *(mix)) :> _;
