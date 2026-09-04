declare name "Multi-Tap Echo";
declare description "Up to 12 evenly spaced echo taps with rising/falling level distribution, into a Schroeder reverb and LF/HF coloration";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust rects/ech_01.dsp + rectangles.lib";
declare category "guitar";
declare family "time";
import("stdfaust.lib");

pp_reps_num   = hslider("[0] Taps", 4, 1, 12, 1);
pp_reps_time  = hslider("[1] Time[unit:ms]", 100, 50, 1000, 1) : si.smoo;
pp_reps_rate  = hslider("[2] Step[unit:ms]", 20, 10, 100, 1) : si.smoo;
pp_reps_distr = hslider("[3] Distribution", 0, 0, 1, 0.01) : si.smoo;
pp_rev        = hslider("[4] Reverb", 0.3, 0, 1, 0.01) : si.smoo;
pp_lf         = hslider("[5] LF", 0.5, 0, 1, 0.01) : si.smoo : -(0.5) : *(2);
pp_hf         = hslider("[6] HF", 0.5, 0, 1, 0.01) : si.smoo : -(0.5) : *(2);
pp_reps_vol   = hslider("[7] Taps Volume", 0.5, 0, 1, 0.01) : si.smoo;

N = 12;
mix2(c,x,y) = (1-c)*x + c*y;
get_delay_length(x) = x*ma.SR*0.001;
taps_distr0 = (1,0.9,0.85,0.8,0.75,0.7,0.65,0.6,0.55,0.5,0.45,0.4);
taps_distr1 = (0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,1);
allpass(dt,fb) = (_,_ <: (*(fb),_:+:@(dt)), -) ~ _ : (!,_);
comb(dt, fb, damp) = (+:@(dt)) ~ (*(1-damp) : (+ ~ *(damp)) : *(fb));
schoeders2(fb1, fb2, damp, spread) = _ <: par(i, 8, comb(ba.take(i+1, (1116,1188,1277,1356,1422,1491,1557,1617))+spread, fb1, damp)) :> allpass(556, fb2) : allpass(441, fb2);
reverb(mix) = _ <: (schoeders2(0.7, 0.25, 0.7, 1000) : fi.lowpass(2,4000) : _*0.5), _ : mix2(1 - mix);
coloration_filter2(lf, hf) = _ <: (fi.lowshelf(5,lf*12,440), fi.highshelf(5,hf*12,880)) :> _*ba.db2linear(-12);
taps = par(i, N, de.fdelay(131072, get_delay_length(pp_reps_time)+i*get_delay_length(pp_reps_rate)) : *(pp_reps_vol) : *(i < pp_reps_num))
    <: par(i,N,_*ba.take(i+1,taps_distr0)), par(i,N,_*ba.take(i+1,taps_distr1)) : ro.interleave(12,2) : par(i,N,mix2(pp_reps_distr)) :> _;
process = _ <: _, (taps : reverb(pp_rev) : coloration_filter2(pp_lf,pp_hf)) :> _;
