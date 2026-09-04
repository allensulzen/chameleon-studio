declare name "Progenitor";
declare description "Port of Freeverb3's Progenitor (Dattorro-style nested allpass tank) with chorus, definition and 3 decay stages. Author notes it can be unstable at extreme settings";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust freeverb3.dsp";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

chorus      = hslider("[0] Chorus", 0.5, 0, 1, 0.01) : si.smoo;
definition  = hslider("[1] Definition", 0.5, 0, 1, 0.01) : si.smoo : *(0.25);
decay1      = hslider("[2] Decay 1", 0.5, 0, 1, 0.01) : si.smoo : *(0.938);
decay2      = hslider("[3] Decay 2", 0.5, 0, 1, 0.01) : si.smoo : *(0.844);
decay3      = hslider("[4] Decay 3", 0.5, 0, 1, 0.01) : si.smoo : *(0.906);
diffusion1  = hslider("[5] Diffusion 1", 0.5, 0, 1, 0.01) : si.smoo : *(0.312);
diffusion2  = hslider("[6] Diffusion 2", 0.5, 0, 1, 0.01) : si.smoo : *(0.375);
decay_diff  = hslider("[7] Decay Diffusion", 0.5, 0, 1, 0.01) : si.smoo : *(0.406);
damping     = hslider("[8] Damping", 0.5, 0, 1, 0.01) : si.smoo : *(0.312);
hf_bw       = hslider("[9] HF Bandwidth", 0.5, 0, 1, 0.01) : si.smoo : *(0.188);
dry_wet     = hslider("[10] Dry/Wet", 0.4, 0, 1, 0.01) : si.smoo;

X = (_,_) <: (!,_,_,!);
opf(a) = (_+_*(1-a) ~ @(1)*a);
ozf(b) = _ <: (@(1):_*(1-b)), _*b :> _;
n_ap(dt,c1,c2,next) = (_+_ <: (next:@(dt)), _*-c1) ~ _*c1 : _*c2, _ :> _;
left_branch = (opf(hf_bw):@(1):_*0.5), (_ <: ((opf(0.875):_*0.156), _*0.344)) :> opf(damping) :
    n_ap(239,diffusion2,decay2,_) : @(2) : n_ap(392,diffusion1,decay3,_) <: @(1055),_ :
    n_ap(612,decay_diff,decay2,n_ap(1944,definition,decay1,_)),_ : @(344),_ :
    n_ap(1264,decay_diff,decay2,n_ap(816,definition,decay1,n_ap(1212,definition,0.938,@(121):ozf(chorus*0.781)))),_ : @(1572),_;
right_branch = (opf(hf_bw):@(1):_*0.5), (_ <: ((opf(0.875):_*0.156), _*0.344)) :> opf(damping) :
    n_ap(205,diffusion2,decay2,_) : @(1) : n_ap(329,diffusion1,decay3,_) <: @(625),_ : @(835),_ :
    n_ap(368,decay_diff,decay2,n_ap(2032,definition,decay1,_)),_ : @(500),_ :
    n_ap(1340,decay_diff,decay2,n_ap(688,definition,decay1,n_ap(1452,definition,0.938,@(5):ozf(chorus*0.188)))),_ : @(16),_;
freeverb3 = _,_ : (_,X,_ : (X:left_branch),(X:right_branch) : _,X,_) ~ X :> _,_;
process = _ <: _, (_ <: freeverb3 :> *(0.5)) : (_*(1-dry_wet) + _*dry_wet);
