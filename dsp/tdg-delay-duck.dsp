declare name "Delay Duck";
declare description "Ducking delay: repeats are pushed down while you play and swell back in the gaps";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust circles/delay_duck.dsp + geometry.lib";
declare category "guitar";
declare family "time";
import("stdfaust.lib");
mix2(c,x,y) = (1-c)*x + c*y;
// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors
mono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;
p_time = hslider("[0] Time[unit:ms]", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));
p_fb   = hslider("[1] Feedback", 0.3, 0, 0.95, 0.01) : si.smoo;
p_dw   = hslider("[9] Dry/Wet", 0.5, 0, 1, 0.01) : si.smoo;
p_duck = hslider("[2] Ducking", 0.5, 0, 1, 0.01) : si.smoo;
// proportional ducking: reverb/delay level drops by up to `depth` dB as the input envelope rises
// (the original used a hard gate — env*amount > 1 — which mutes the wet path entirely while playing,
// so a 100 % wet mix went silent)
duck_gain(att, rel, depth_db, x) = ba.db2linear(0 - depth_db * min(1, an.amp_follower_ud(att, rel, x) * 4)) : si.smooth(ba.tau2pole(0.02));
process(x) = mix2(p_dw, x, mono_delay(p_time, p_fb, _, _, x) * duck_gain(0.05, 0.1, p_duck*40, x));
