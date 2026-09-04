declare name "Delay Wah";
declare description "Feedback delay with an envelope-follower auto-wah on the repeats";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust circles/delay_wah.dsp + geometry.lib";
declare category "guitar";
declare family "time";
import("stdfaust.lib");
mix2(c,x,y) = (1-c)*x + c*y;
// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors
mono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;
p_time = hslider("[0] Time[unit:ms]", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));
p_fb   = hslider("[1] Feedback", 0.3, 0, 0.95, 0.01) : si.smoo;
p_dw   = hslider("[9] Dry/Wet", 0.5, 0, 1, 0.01) : si.smoo;
p_wah = hslider("[2] Wah", 0.5, 0, 1, 0.01) : si.smoo;
process = _ <: _, (mono_delay(p_time, p_fb, _, _) : ve.autowah(p_wah)) : mix2(p_dw);
