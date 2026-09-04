declare name "Tri Chorus";
declare description "Three flanger_mono voices with phase-offset and saw-delayed LFOs summed - thick tri-chorus (from rects/mod_01 trichor)";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust rects/mod_01.dsp trichor()";
declare category "guitar";
declare family "mod";
import("stdfaust.lib");

speed = hslider("[0] Speed[unit:Hz]", 0.8, 0.1, 10, 0.01) : si.smoo;
depth = hslider("[1] Depth", 0.5, 0, 1, 0.01) : si.smoo;
fb    = hslider("[2] Feedback", 0.2, 0, 0.9, 0.01) : si.smoo;
mix   = hslider("[3] Mix", 0.6, 0, 1, 0.01) : si.smoo;

samps_max = 512;
flange(lfo,dp,fbk) = pf.flanger_mono(samps_max, ((lfo+1)*0.5)*dp*(samps_max-2) + 1, dp, fbk, 0);
lfo = os.osc(speed);
trichor(lfo,dp,fbk) = _ <: flange(lfo,dp,fbk*0.3),
    flange(lfo : de.fdelay(1024, os.osc(3):_+1:_*0.5:_*200) : _*-1, dp, fbk*0.7),
    flange(lfo : de.fdelay(1024, os.lf_sawpos(0.78*speed):_*200), dp, fbk*0.5) :> *(0.33);
process = _ <: *(1-mix), (trichor(lfo, depth, fb) : *(mix)) :> _;
