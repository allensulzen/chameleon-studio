declare name "Room Simulator";
declare description "Gardner nested-allpass room reverbs (small/medium/large) with continuous morph between room sizes and pre-delay";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust room_simulator.dsp";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

p_predelay = hslider("[0] Predelay[unit:ms]", 20, 1, 200, 1);
p_rsize    = hslider("[1] Room Size", 1, 0, 2, 0.05) : si.smoo;
p_rt       = hslider("[2] Reverb Time", 0.3, 0, 0.9, 0.01) : si.smoo;
p_drw      = hslider("[3] Dry/Wet", 0.4, 0, 1, 0.01) : si.smoo;

ms2sps(ms) = int(ms*ma.SR/1000);
mix2(c,x,y) = (1-c)*x + c*y;
mix3(val) = _,_,_ <: select3(int(val)), select3(min(2,int(val)+1)) : mix2(val-floor(val));
opf(a) = (_+_*(1-a) ~ @(1)*a);
allpass(dt,fb,f_nest) = (+ <: (de.delay(maxdel,dt-1):f_nest),*(fb)) ~ *(-fb) : mem,_ : + with { maxdel = 8192; };
sn_allpass(dt1,dt2,fb1,fb2) = allpass(dt1,fb1,allpass(dt2,fb2,_));
dn_allpass(dt1,dt2,dt3,fb1,fb2,fb3) = allpass(dt1,fb1,allpass(dt2,fb2,allpass(dt3,fb3,_)));
small_room(rt,hf_damping) = fi.lowpass(4,6000) :
    ((_,_ :> @(ms2sps(24)) : dn_allpass(ms2sps(35),ms2sps(22),ms2sps(8.3),0.15,0.25,0.3) <: sn_allpass(ms2sps(66),ms2sps(30),0.08,0.3),_)
    ~ (_*0.99 : fi.highpass(2,800) : fi.lowpass(2,1600) : _*rt : opf(hf_damping))) : _*0.5,_*0.5 :> _;
medium_room(rt,hf_damping,x) = x : fi.lowpass(4,6000) :
    ((_,_ :> dn_allpass(ms2sps(35),ms2sps(8.3),ms2sps(22),0.25,0.35,0.45) <: @(ms2sps(5)),_*0.5 : allpass(ms2sps(30),0.45,_),_ : (@(ms2sps(67)) <: _,_*0.5),_ :
    (@(ms2sps(15)) : _*rt),_+_ : (_*0.4 : _+x : sn_allpass(ms2sps(39),ms2sps(9.8),0.25,0.35)),_)
    ~ (fi.highpass(2,500) : fi.lowpass(2,1000) : opf(hf_damping) : _*rt : _*1.299)) : _*0.5,_ : _+_;
large_room(rt,hf_damping) = fi.lowpass(4,4000) :
    ((_,_ :> allpass(ms2sps(8),0.3,_) : allpass(ms2sps(12),0.3,_) : @(ms2sps(4)) <: _,_*1.5 : ((@(ms2sps(17)) : sn_allpass(ms2sps(87),ms2sps(62),0.5,0.25) : @(ms2sps(31)) <: _,_*0.8),_ : _,_+_) :
    ((@(ms2sps(3)) : dn_allpass(ms2sps(120),ms2sps(76),ms2sps(30),0.5,0.25,0.25)),_))
    ~ (_*0.5 : _*rt : opf(hf_damping) : fi.highpass(2,500) : fi.lowpass(2,1000) : _*1.299)) : _+_*0.8;
process = _ <: (de.fdelay(16384, ms2sps(p_predelay)) <: small_room(p_rt, 0), medium_room(p_rt, 0), large_room(p_rt, 0) : mix3(p_rsize)), _ : mix2(1 - p_drw);
