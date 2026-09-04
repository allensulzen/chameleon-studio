declare name "Zita Spread";
declare description "Zita-rev1 FDN variant with a Spread control scaling the delay-line lengths (tiny room to huge hall), RT and HF decay";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust rects/rev_01.dsp (zita_rev_fdn by JOS)";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

pp_predel = hslider("[0] Predelay[unit:ms]", 20, 1, 500, 1);
pp_spread = hslider("[1] Spread", 0.5, 0.2, 2, 0.05);
pp_rt     = hslider("[2] RT[unit:s]", 3, 1, 10, 0.05);
pp_decay  = hslider("[3] HF Decay", 0.5, 0, 1, 0.05);
dry_wet   = hslider("[4] Dry/Wet", 0.4, 0, 1, 0.05) : si.smoo;

zita_rev_mod1(spread,rt,f_decay,fsmax) =
  ((si.bus(2*N) :> allpass_combs(N) : feedbackmatrix(N)) ~ (delayfilters(N,freqs,durs) : fbdelaylines(N)))
with {
  N = 8;
  apdelays = (0.020346, 0.024421, 0.031604, 0.027333, 0.022904, 0.029291, 0.013458, 0.019123);
  tdelays = ( 0.153129, 0.210389, 0.127837, 0.256891, 0.174713, 0.192303, 0.125000, 0.219991);
  tdelay(i) = floor(0.5 + ma.SR*ba.take(i+1,tdelays)*spread);
  apdelay(i) = floor(0.5 + ma.SR*ba.take(i+1,apdelays));
  fbdelay(i) = max(1, tdelay(i) - apdelay(i));
  tdelaymaxfs(i) = floor(0.5 + fsmax*ba.take(i+1,tdelays)*2);
  apdelaymaxfs(i) = floor(0.5 + fsmax*ba.take(i+1,apdelays));
  fbdelaymaxfs(i) = tdelaymaxfs(i) - apdelaymaxfs(i);
  nextpow2(x) = ceil(log(x)/log(2.0));
  maxapdelay(i) = int(2.0^max(1.0,nextpow2(apdelaymaxfs(i))));
  maxfbdelay(i) = int(2.0^max(1.0,nextpow2(fbdelaymaxfs(i))));
  apcoeff(i) = select2(i&1,0.6,-0.6);
  allpass_combs(N) = par(i,N,(fi.allpass_comb(maxapdelay(i),apdelay(i),apcoeff(i))));
  fbdelaylines(N) = par(i,N,(de.delay(maxfbdelay(i),(fbdelay(i)))));
  freqs = (200,200+f_decay*8000); durs = (rt+2,rt);
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
wet = de.fdelay(32768, pp_predel*ma.SR/1000) <: si.bus(8) : zita_rev_mod1(pp_spread, pp_rt, pp_decay, 48000) :> *(0.25);
process = _ <: *(1-dry_wet), (wet : *(dry_wet)) :> _;
