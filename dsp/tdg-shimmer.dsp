declare name "Shimmer";
declare description "ValhallaShimmer-inspired reverb: modulated nested allpass diffusers with pitch-shifted feedback path (envelope/LFO controllable shift)";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust shimmer.dsp";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

envelope   = hslider("[0] Envelope[unit:s]", 1, 0.1, 3, 0.05);
speed      = hslider("[1] LFO Speed[unit:Hz]", 0.1, 0.1, 10, 0.05);
depth      = hslider("[2] Mod Depth", 0, 0, 1, 0.05) : si.smoo;
ctrl       = hslider("[3] Env/LFO", 0.5, 0, 1, 0.05) : si.smoo;
shift      = hslider("[4] Shift[unit:semi]", 12, -12, 12, 0.1) : si.smoo : *(2);
size       = hslider("[5] Size", 1.5, 1, 3, 0.05);
diffusion  = hslider("[6] Diffusion", 0.5, 0.1, 0.7, 0.05) : si.smoo;
feedback   = hslider("[7] Feedback", 0.25, 0, 0.35, 0.01) : si.smoo;
hf_damping = hslider("[8] HF Damping", 0.3, 0.005, 0.995, 0.005) : si.smoo;
dry_wet    = hslider("[9] Dry/Wet", 0.5, 0, 1, 0.05) : si.smoo;

mixer(mix) = _*(1 - mix), _*mix :> _;
c_folower_colibration = 6;
parametric_controller(mix, envelope_t, freq, dp) = (an.amp_follower(envelope_t) : _*c_folower_colibration : _*dp, os.osc(freq)*0.5 : _, _*dp) : mixer(mix) : _+0.5;
X = (_,_) <: (!,_,_,!);
opf(a) = (_+_*(1-a) ~ @(1)*a);
allpass_with_fdelay(dt1,coef,dt2,dt2pos) = (_,_ <: (*(coef),_:+:@(dt1):de.fdelay(dt2,dt2pos)), -) ~ _ : (!,_);
allpass(dt,fb) = (_,_ <: (*(fb),_:+:@(dt)), -) ~ _ : (!,_);
APFB(dt1,fb1,dtv,dtvpos,dt2,fb2) = allpass_with_fdelay(dt1,fb1,dtv,dtvpos) : allpass(dt2,fb2);
c_samples = 2048; c_xfade = 1024;
sh(x) = x : parametric_controller(ctrl, envelope, speed, depth) : _*shift;
core(x,y) = x,y : (_,_ :
    (_,X,_ : (
    (_*feedback+_*0.3 :> APFB(601*size,0.7*diffusion,50,49*(os.osc(1)+1)/2,613*size,0.75*diffusion) : opf(hf_damping)),
    (_*feedback+_*0.3 :> APFB(2043*size,0.75*diffusion,50,49*(os.osc(1.5)+1)/2,2087*size,0.75*diffusion) : opf(hf_damping))
    ) : X) ~ (
    (_*feedback : fi.dcblockerat(80) : @(4325) : APFB(2337*size,0.7*diffusion,50,49*(os.osc(0.7)+1)/2,2377*size,0.4*diffusion) : @(2969) : ef.transpose(c_samples,c_xfade,sh(x))),
    (_*feedback : fi.dcblockerat(80) : @(4763) : APFB(1087*size,0.7*diffusion,50,49*(os.osc(1.3)+1)/2,1113*size,0.4*diffusion) : @(3111) : ef.transpose(c_samples,c_xfade,sh(y)))));
process(x) = core(x,x) :> *(0.5) <: mixer(dry_wet, x, _);
