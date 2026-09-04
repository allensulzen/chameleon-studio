declare name "Delay Flange";
declare description "Feedback delay with a resonant flanger on the repeats, swept in time with the delay";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust circles/delay_flange.dsp + geometry.lib";
declare category "guitar";
declare family "time";
import("stdfaust.lib");
mix2(c,x,y) = (1-c)*x + c*y;
// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors
mono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;
p_time = hslider("[0] Time[unit:ms]", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));
p_fb   = hslider("[1] Feedback", 0.3, 0, 0.95, 0.01) : si.smoo;
p_dw   = hslider("[9] Dry/Wet", 0.5, 0, 1, 0.01) : si.smoo;
p_fl = hslider("[2] Flange", 0.3, 0, 1, 0.01) : si.smoo;
flanger(lfo,depth) = _ <: _, (- : de.fdelay(2048, ((lfo+1)/2)*depth*0.9*2047 + 1)) ~ *(0.5) : _, *(-1) : + : *(0.5);
process = _ <: _, (mono_delay(p_time, p_fb, _, _) : flanger(os.osc(1000/p_time), p_fl)) : mix2(p_dw);
