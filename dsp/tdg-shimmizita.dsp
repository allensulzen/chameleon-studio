declare name "Shimmizita";
declare description "Zita-rev1 FDN with a pitch shifter inside each of the 8 feedback lines - shimmer reverb whose shift can be envelope/LFO driven";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust shimmizita.dsp + shimmizita.inc (zita_rev_fdn by JOS)";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

f1       = hslider("[0] LF Crossover[unit:Hz]", 200, 50, 1000, 1);
t60dc    = hslider("[1] Low RT60[unit:s]", 3, 1, 8, 0.1);
t60m     = hslider("[2] Mid RT60[unit:s]", 2, 1, 8, 0.1);
f2       = hslider("[3] HF Damping[unit:Hz]", 6000, 1500, 20000, 1);
shift    = hslider("[4] Shift[unit:semi]", 12, -12, 12, 0.1) : si.smoo;
mode     = hslider("[5] Mode", 0, -3, 3, 0.05) : si.smoo;
envelope = hslider("[6] Envelope[unit:s]", 1, 0.1, 3, 0.05);
ctrl     = hslider("[7] Env/LFO", 0.5, 0, 1, 0.05) : si.smoo;
speed    = hslider("[8] LFO Speed[unit:Hz]", 0.1, 0.1, 10, 0.05);
depth    = hslider("[9] Mod Depth", 0, 0, 1, 0.05) : si.smoo;
ps_dw    = hslider("[10] Shift Amount", 0.5, 0, 1, 0.05) : si.smoo;
dry_wet  = hslider("[11] Dry/Wet", 0.4, 0, 1, 0.05) : si.smoo;
fsmax = 48000.0;

par_ps(sh, env_t, c, freq, dep, dw) = _ <: _, (_ <: parametric_controller(c, env_t, freq, dep)*sh, _ : ef.transpose(c_samples, c_xfade)) : mixer(dw)
with {
    c_samples = 2048; c_xfade = 1024; c_folower_colibration = 6;
    parametric_controller(mix, envelope_t, fr, dp) = (an.amp_follower(envelope_t) : _*c_folower_colibration : _*dp, os.osc(fr)*0.5 : _, _*dp) : mixer(mix) : _+0.5;
    mixer(mix) = _*(1 - mix), _*mix :> _;
};
shimmizita_rev_fdn(f1,f2,t60dc,t60m, mode, shift,envelope,ctl,freq,depth,dry_wet, fsmax) =
  ((si.bus(2*N) :> allpass_combs(N) : feedbackmatrix(N)) ~ (delayfilters(N,freqs,durs) : pitchshifters(N) : fbdelaylines(N)))
with {
  N = 8;
  apdelays = (0.020346, 0.024421, 0.031604, 0.027333, 0.022904, 0.029291, 0.013458, 0.019123);
  tdelays = ( 0.153129, 0.210389, 0.127837, 0.256891, 0.174713, 0.192303, 0.125000, 0.219991);
  tdelay(i) = floor(0.5 + ma.SR*ba.take(i+1,tdelays));
  apdelay(i) = floor(0.5 + ma.SR*ba.take(i+1,apdelays));
  fbdelay(i) = tdelay(i) - apdelay(i);
  tdelaymaxfs(i) = floor(0.5 + fsmax*ba.take(i+1,tdelays));
  apdelaymaxfs(i) = floor(0.5 + fsmax*ba.take(i+1,apdelays));
  fbdelaymaxfs(i) = tdelaymaxfs(i) - apdelaymaxfs(i);
  nextpow2(x) = ceil(log(x)/log(2.0));
  maxapdelay(i) = int(2.0^max(1.0,nextpow2(apdelaymaxfs(i))));
  maxfbdelay(i) = int(2.0^max(1.0,nextpow2(fbdelaymaxfs(i))));
  apcoeff(i) = select2(i&1,0.6,-0.6);
  allpass_combs(N) = par(i,N,(fi.allpass_comb(maxapdelay(i),apdelay(i),apcoeff(i))));
  fbdelaylines(N) = par(i,N,(de.delay(maxfbdelay(i),(fbdelay(i)))));
  shiftcoefs_m1 = (1/2,1/3,1/2,1/4,1/2,1/8,1/2,1/3);
  shiftcoefs_m2 = (1/5,-1/2,1/3,-1/2,1/6,-1/3,1/3,1/2);
  shiftdunc(i, sh, md) = md <: _>=0, _<0 : ((_*(sh+sh*md*ba.take(i+1,shiftcoefs_m1))), (_*(sh+sh*md*ba.take(i+1,shiftcoefs_m2)))) :> _;
  pitchshifters(N) = par(i, N, par_ps(shiftdunc(i, shift, mode), envelope, ctl, freq, depth, dry_wet));
  freqs = (f1,f2); durs = (t60dc,t60m);
  delayfilters(N,freqs,durs) = par(i,N,filter(i,freqs,durs));
  feedbackmatrix(N) = ro.hadamard(N);
  staynormal = 10.0^(-20);
  special_lowpass(g,f) = si.smooth(p) with {
    p = mbo2 - sqrt(max(0,mbo2*mbo2 - 1.0));
    mbo2 = (1.0 - gs*c)/(1.0 - gs);
    gs = g*g;
    c = cos(2.0*ma.PI*f/float(ma.SR));
  };
  filter(i,freqs,durs) = lowshelf_lowpass(i)/sqrt(float(N))+staynormal
  with {
    lowshelf_lowpass(i) = gM*fi.low_shelf1_l(g0/gM,f(1)) : special_lowpass(gM,f(2));
    g0 = g(0,i); gM = g(1,i);
    f(k) = ba.take(k,freqs);
    dur(j) = ba.take(j+1,durs);
    n60(j) = dur(j)*ma.SR;
    g(j,i) = exp(-3.0*log(10.0)*tdelay(i)/n60(j));
  };
};
wet = _ <: si.bus(8) : shimmizita_rev_fdn(f1,f2,t60dc,t60m, mode, shift, envelope, ctrl, speed, depth, ps_dw, fsmax) :> *(0.25);
process = _ <: *(1-dry_wet), (wet : *(dry_wet)) :> _;
