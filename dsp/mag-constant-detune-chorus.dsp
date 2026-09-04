declare name "Constant Detune Chorus";
declare description "Bart Brouns' port of Scott Nordlund's chorus: three delay taps with Poisson-timed random slow+fast LFOs whose warped triangles keep detune constant and symmetric in cents";
declare author "Bart Brouns (port of a Pure Data patch by Scott Nordlund, 2011)";
declare license "GPL-3.0";
declare source "magnetophon/constant-detune-chorus ConstantDetuneChorus.dsp";
declare category "guitar";
declare family "mod";
import("stdfaust.lib");
mix = hslider("[5] Mix", 0.6, 0, 1, 0.01) : si.smoo;
line (value, time) = state~(_,_):!,_
	with {
		state (t, c) = nt, ba.if (nt <= 0, value, c+(value - c) / nt)
		with {
			nt = ba.if( value != value', samples, t-1);
			samples = time*ma.SR/1000.0;
		};
	};
noiseMax	= 13;
poisStart	= noiseMax/2;
start = ba.time<1;
ms		= ma.SR/1000;
poisMin		= 667;
poisMax 	= 4444;
delMax		= 4096;
chorusGroup(x) = x;
slowFreq	= chorusGroup(hslider("[0] Slow Rate[unit:Hz]",	0.57, 0, 5, 0.01):si.smooth(0.999));
slowDepth	= chorusGroup(hslider("[1] Slow Depth",	4, 0, 5, 0.01):pow(2):si.smooth(0.999));
fastFreq	= chorusGroup(hslider("[2] Fast Rate[unit:Hz]",	1, 0, 10, 0.01):si.smooth(0.999));
fastDepth	= chorusGroup(hslider("[3] Fast Depth",	4, 0, 10, 0.01):pow(2):si.smooth(0.999));
feedback	= chorusGroup(hslider("[4] Feedback",	0, -1, 1, 0.01)*0.8:si.smooth(0.999));
SH(trig,x) = (*(1 - trig) + x * trig) ~_;
changePulse= _ <: _, mem: - : abs:_>(0);
noiseNr(nr) =(no.noises(noiseMax,nr)/2)+0.5;
pois(nr) = ((SH((_|start),noiseNr(nr+1)):log:*(-1000):*(ms)) ~ (silentFor<:_,_)) :max(poisMin*ms):min(poisMax*ms):_/ms
with {
silentFor(time) =  (ba.countup((time:max(poisMin*ms):min(poisMax*ms)), ((time:changePulse)*_))==(time:max(poisMin*ms):min(poisMax*ms)))~_:changePulse;
};
smin = slowFreq;
smax = slowFreq*1.25;
freq(Fmin,Fmax,nr) = ((SH((pois(nr):changePulse),noiseNr(nr))  * ((Fmax:log)-(Fmin:log))) + (Fmin:log)):exp ;
slowD(nr) = (slowDepth:expr1:expr2) / freq(Fmin,Fmax,nr)
  with {
  expr1 = pow(2, _/1200);
  expr2 = _<:(2000*(_-1)/(_+1));
  };
slowTotal(nr) = ((os.lf_sawpos(line(freq(smin,smax,nr), pois(nr)))-0.5):abs) * (line((slowD(nr)),pois(nr)));
Fmin = fastFreq;
Fmax = fastFreq*1.75;
fastD(nr) = (fastDepth:expr1:expr2) / freq(Fmin,Fmax,nr)
  with {
  expr1 = pow(2, _/1200);
  expr2 = _<:(318.309886*(_-1)/(_+1));
  };
fastTotal(nr) = ((os.lf_sawpos(line(freq(Fmin,Fmax,nr), pois(nr))):sin:_+1) * (line((fastD(nr)),pois(nr))) );
delayed(nr,add) = de.sdelay(delMax,1024,((slowTotal(nr)+fastTotal(nr+1)+add)*ms));
monoChorus(nr) = (_,_:+:_<:delayed(0+nr,3),delayed(2+nr,7),delayed(4+nr,10):>_)~( (_*feedback) : fi.dcblockerat(200)*2: ma.tanh*0.25) ;
process = _ <: *(1-mix), (monoChorus(0) : *(0.5) : *(mix)) :> _;
