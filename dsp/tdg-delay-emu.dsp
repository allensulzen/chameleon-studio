declare name "Delay Emu";
declare description "Delay with morphable character: 8-bit reduction (digital) to clean to tape-capstan wow with bandlimiting and hiss (analog)";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust circles/delay_emu.dsp + geometry.lib";
declare category "guitar";
declare family "time";
import("stdfaust.lib");
mix2(c,x,y) = (1-c)*x + c*y;
// mono collapse of geometry.lib pp_delay: feedback delay with post-delay (in-loop) and feedback-path (out-of-loop) processors
mono_delay(time_ms, fb, f_post, f_fb) = (+ : de.fdelay(131072, time_ms*ma.SR/1000) : f_post) ~ *(fb) : f_fb;
p_time = hslider("[0] Time[unit:ms]", 500, 50, 2000, 1) : si.smooth(ba.tau2pole(0.05));
p_fb   = hslider("[1] Feedback", 0.3, 0, 0.95, 0.01) : si.smoo;
p_dw   = hslider("[9] Dry/Wet", 0.5, 0, 1, 0.01) : si.smoo;
pp_ad = hslider("[2] Digital/Analog", 1, 0, 2, 0.01) : si.smoo;

mix3(val) = _,_,_ <: select3(int(val)), select3(min(2, int(val)+1)) : mix2(val-floor(val));
bits_reducing(bits) = _*pow(2,bits) : ceil : _/pow(2,bits) : fi.lowpass(4,4000);
tape_capstan_emu(band_width, del_osc_freq, del_width, noise_lev_db) = fi.lowpass(4,band_width) :
    _+((noise_lev_db : ba.db2linear : si.smooth(0.999))*no.lfnoise0(12000)) :
    de.fdelay(1024, os.osc(del_osc_freq) : _+1 : _/2 : _*del_width);
analog_digital(val) = _ <: bits_reducing(8), _, tape_capstan_emu(4000,6,25,-70) : mix3(val);
process = _ <: _, (mono_delay(p_time, p_fb, _, _) : analog_digital(pp_ad)) : mix2(p_dw);
