declare name "Character Compressor";
declare description "Bart Brouns' blushcomp-derived colour compressor (after Sampo Savolainen): peak/RMS detector, power/curve/shape gain-law, rate-limited GR, gain-vs-high-shelf output";
declare author "Bart Brouns (based on blushcomp by Sampo Savolainen)";
declare license "GPL-2.0";
declare source "magnetophon/CharacterCompressor CharacterCompressorMono.dsp + lib/*.lib";
declare category "guitar";
declare family "dynamics";
import("stdfaust.lib");
COEFF2DB(x) = log10(max(x, 1e-9)) * 20;
DB2COEFF(x) = pow(10, x / 20);
THRESH(t,x) = (x-t) * (t < x);
SMOOTH(a, r, prevx, x) =
	(x     *      select2( (x < prevx), a, r )) +
	(prevx * (1 - select2( (x < prevx), a, r)));
DETECTOR = (	COEFF2DB :
		THRESH(threshold) :
		SMOOTH(attack, release) ~ _ );
RATIO(x) = 0 - (x - (x/ratio));
time_ratio_target = 1.5;
time_ratio_target_atk = 8.0;
time_ratio_target_rel = 1.5;
time_ratio_attack(t) = exp(1) / ( t * ma.SR * time_ratio_target_atk );
time_ratio_release(t) = exp(1) / ( t * ma.SR * time_ratio_target_rel );
DRYWET(ratio) = ( *(1 - ratio),  * (ratio)) : +;
DRYWET_STEREO(l, r, ratio) = ( (DRYWET(l, ratio)), (DRYWET(r, ratio)));
RATELIMITER_INTERNAL(maximum_rate,pt, ct, prevx, x) =
     select2( abs(ct-pt) > maximum_rate, x,
              prevx - pt + maximum_rate * select2( (x < prevx), 1.0, -1.0) );
OVERSHOOT_CORRECTION(limited_gain, target_gain, tangent) =
	select2( (tangent > 0.0),
		 select2( (limited_gain > target_gain), limited_gain, target_gain),
		 select2( (limited_gain > target_gain), target_gain, limited_gain));
RATELIMITER(maximum_rate,prevx, x) =
	( RATELIMITER_INTERNAL( prevx@1 - prevx, prevx - x, prevx, x,maximum_rate), x, (prevx - x) ) :
	  OVERSHOOT_CORRECTION;
M_LN2 = 0.69314718055994530942;
biquad_basics_alpha(bw, omega, sn, cs) =
	(omega, sn, cs, sn * ma.sinh( M_LN2 / 2.0 * bw * omega / sn) );
biquad_basics(samplerate, bw, cutoff) =
	(2.0 * ma.PI * cutoff / samplerate)
	<: ( _ <: (_, sin) , cos)
	: biquad_basics_alpha(bw);
biquad_hp_params_a0r(omega,sn,cs,alpha) =
	(omega, sn, cs, alpha, 1.0 / ( 1.0 + alpha));
biquad_hp_params_coeffs(omega, sn, cs, alpha, a0r) =
	( a0r * ( 1.0 + cs ) * 0.5
	, a0r * (-1.0 - cs )
	, a0r * ( 1.0 + cs ) * 0.5
	, a0r * ( 2.0 * cs )
	, a0r * (alpha - 1.0) );
biquad_hp_params(samplerate, bw, cutoff) =
	  biquad_basics(samplerate, bw, cutoff)
	: biquad_hp_params_a0r
	: biquad_hp_params_coeffs;
biquad_run(y, b0, b1, b2, a1, a2, x) =
	(b0 * x@0) + (b1 * x@1) + (b2 * x@2) +
	             (a1 * y@0) + (a2 * y@1);
biquad_hp(cutoff,x) = (biquad_hp_params(ma.SR, 3.0, cutoff), x) : biquad_run ~ _;
HPF(freq) =  biquad_hp(freq);
slidingReduce(N,maxN,op,disabledVal,x) =
par(i,maxNrBits,fixedDelayOp(1<<i,x)@sumOfPrevDelays(N,maxN,i) :useVal(i)):combine(maxNrBits) with {
  fixedDelayOp = case {
    (1,x) => x;
    (N,x) =>  op(fixedDelayOp(N/2,x) , fixedDelayOp(N/2,x)@(N/2));
  };
  sumOfPrevDelays(N,maxN,0) = 0;
  sumOfPrevDelays(N,maxN,i) = (ba.subseq((allDelays(N,maxN)),0,i):>_) with {
    allDelays(N,maxN) = par(j, maxNrBits, (1<<j) *  ba.take(j+1,(int2bin(N,maxN))) );
  };
  maxNrBits = int2nrOfBits(maxN);
  combine(2) = op;
  combine(N) = op(combine(N-1),_);
  useVal(i) =
    _<:select2((i==0) & (N==0) ,
      select2( ba.take(i+1,(int2bin(N,maxN))) , disabledVal,_),
      _
    );
};
newSlidingReduce(N,maxN,op,disabledVal,x) =
par(i,maxNrBits,fixedDelayOp(1<<i,x)@sumOfPrevDelays(N,maxN,i) )
:switched_combine(N,maxN)
with {
  fixedDelayOp = case {
    (1,x) => x;
    (N,x) =>  op(fixedDelayOp(N/2,x) , fixedDelayOp(N/2,x)@(N/2));
  };
  sumOfPrevDelays(N,maxN,0) = 0;
  sumOfPrevDelays(N,maxN,i) = (ba.subseq((allDelays(N,maxN)),0,i):>_) with {
    allDelays(N,maxN) = par(j, maxNrBits, (1<<j) *  ba.take(j+1,(int2bin(N,maxN))) );
  };
  maxNrBits = int2nrOfBits(maxN);
  combine(0) = 0:!;
  combine(1) = _;
  combine(2) = op;
  combine(N) = op(combine(N-1),_);
  isUsed(i,n) = int(floor(i/(1<<n))%2);
  nrOfUsedBits(i,n) = par(j,int2nrOfBits(n),isUsed(i,j)):>_;
  switched_combine(i,n) =
    si.bus(int2nrOfBits(n))<:
      par(j,n,
        par(k,int2nrOfBits(n),S(isUsed(j+1,k))):combine(nrOfUsedBits(j+1,n))
      )
      : par(j, n, _*(i==j+1)):>_
  with {
    S(0) = !;
    S(1) = _;
  };
};
int2bin(N,maxN) = par(i,int2nrOfBits(maxN),int(floor(N/(1<<i)))%2);
int2nrOfBits(0) = 0;
int2nrOfBits(maxN) = int(floor(log(maxN)/log(2))+1);
slidingSumN(n,maxn) = slidingReduce(n,maxn,+,0);
slidingMaxN(n,maxn) = slidingReduce(n,maxn,max,-INFINITY);
slidingMinN(n,maxn) = slidingReduce(n,maxn,min,INFINITY);
slidingMeanN(n,maxn) = slidingSumN(n,maxn)/n;
slidingRMSn(n,maxn) = pow(2):slidingMeanN(n,maxn) : sqrt;
INFINITY = 1e30;
rmsMaxSize = 512;
MAX_flt = 3.0e38;
MIN_flt = 1.0e-38;
main_group(x) = x;
meter_group(x) = x;
knob_group(x) = x;
detector_group(x) = x;
post_group(x) = x;
ratelimit_group(x) = x;
shape_group(x) = x;
out_group(x) = x;
envelop = abs : max ~ -(1.0/ma.SR) : max(ba.db2linear(-70)) : ba.linear2db;
meter = _;
drywet        = detector_group(hslider("[99]dry-wet[tooltip: ]", 1.0, 0.0, 1.0, 0.1));
ingain        = detector_group(hslider("[1] Input Gain [unit:dB]   [tooltip: The input signal level is increased by this amount (in dB) to make up for the level lost due to compression]",0, -40, 40, 0.1) : ba.db2linear : si.smooth(0.999));
peakRMS       = detector_group(hslider("[2] peak/RMS [tooltip: Peak or RMS level detection",1, 0, 1, 0.001));
rms_speed     = detector_group(hslider("[3]RMS size[tooltip: ]",96, 1,   rmsMaxSize,   1)*44100/ma.SR);
threshold     = detector_group(hslider("[4] Threshold [unit:dB]   [tooltip: When the signal level exceeds the Threshold (in dB), its level is compressed according to the Ratio]", -27.1, -80, 0, 0.1));
ratio         = detector_group(hslider("[5] Ratio   [tooltip: A compression Ratio of N means that for each N dB increase in input signal level above Threshold, the output level goes up 1 dB]", 20, 1, 20, 0.1));
attack        = detector_group(time_ratio_attack(hslider("[6] Attack [unit:ms]   [tooltip: Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new lower target level (the compression `kicking in')]", 23.7, 0.1, 500, 0.1)/1000)) ;
release       = detector_group(time_ratio_release(hslider("[7] Release [unit:ms]   [tooltip: Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new higher target level (the compression 'releasing')]",0.1, 0.1, 2000, 0.1)/1000));
hpf_freq      = detector_group( hslider("[8]sidechain hpf[tooltip: ]", 154, 1, 400, 1));
powerScale(x) =((x>=0)*(1/((x+1):pow(3))))+((x<0)* (((x*-1)+1):pow(3)));
power          = shape_group(hslider("[1]power[tooltip: ]", 1.881 , -33, 33 , 0.001):powerScale);
maxGR          = shape_group(hslider("[2] Max Gain Reduction [unit:dB]   [tooltip: The maximum amount of gain reduction]",-15, -60, 0, 0.1) : ba.db2linear : si.smooth(0.999));
curve          = shape_group(hslider("[3]curve[tooltip: ]", 0, -1, 1 , 0.001)*-1);
shape          = shape_group(((hslider("[4]shape[tooltip: ]", 94, 1, 100 , 0.001)*-1)+101):pow(2));
feedFwBw     = out_group(hslider("[0]feedback/feedforward[tooltip: ]", 0, 0, 1 , 0.001));
hiShelfFreq  = out_group(hslider("[1]hi shelf freq[tooltip: ]",134, 1,   400,   1));
gainHS       = out_group(hslider("[2]gain/hi-shelve crossfade[tooltip: ]", 0.811, 0, 1 , 0.001));
outgain      = out_group(hslider("[3]output gain (dB)[tooltip: ]",           0,      -40,   40,   0.1):si.smooth(0.999));
ratelimit      = ratelimit_group(hslider("[0]ratelimit amount[tooltip: ]", 1, 0, 1 , 0.001));
maxRateAttack  = ratelimit_group(hslider("[1]max attack[unit:dB/s][tooltip: ]", 1020, 6, 8000 , 1)/ma.SR);
maxRateDecay   = ratelimit_group(hslider("[2]max decay[unit:dB/s][tooltip: ]", 3813, 6, 8000 , 1)/ma.SR);
decayMult      = ratelimit_group(hslider("[3]decayMult[tooltip: ]", 20000 , 0,20000 , 0.001)/100);
decayPower     = ratelimit_group(hslider("[4]decayPower[tooltip: ]", 50, 0, 50 , 0.001));
IM_size        = ratelimit_group(hslider("[5]IM_size[tooltip: ]",108, 1,   rmsMaxSize,   1)*44100/ma.SR);
powlim(x,base) = x:max(log(MAX_flt)/log(base)):  min(log(MIN_flt)/log(base));
gainPlusMeter(gain,dry) = (dry * (gain:meter));
hiShelfPlusMeter(gain,dry) = (dry :fi.high_shelf(gain:meter:ba.linear2db,hiShelfFreq));
gainHiShelfCrossfade(crossfade,gain,dry) = (dry * ((gain:meter:ba.linear2db)*(1-crossfade):ba.db2linear)): fi.high_shelf(((gain:ba.linear2db)*crossfade),hiShelfFreq);
crossfade(x,a,b) = a*(1-x),b*x : +;
rmsFade = _<:crossfade(peakRMS,_,slidingRMSn( rms_speed, rmsMaxSize));
detector = ((_ <: ( HPF(hpf_freq) :rmsFade: DETECTOR : RATIO : ba.db2linear:min(0.99999):max(MIN_flt)))<:_,_:pow(powlim(power)));
preRateLim = _;
maxGRshaper = _;
tanshape(amp,x) =(ma.tanh(amp*(x-1)))+1;
curve_pow(fact,x) = ((x*(x>0):pow(p))+(x*-1*(x<=0):pow(p)*-1)) with
{
    p = exp(fact*10*(log(2)));
};
rateLimiter(maxRateAttack,maxRateDecay,prevx,x) = prevx+newtangent:min(0):max(maxGR:ba.linear2db)
with {
    tangent     = x- prevx;
    avgChange   = abs((tangent@1)-(tangent@2)):slidingMeanN(IM_size,rmsMaxSize)*decayMult:_+1:pow(decayPower)-1;
    newtangent  = select2(tangent>0,minus,plus):max(maxRateAttack*-1):min(maxRateDecay);
    plus        = tangent*((abs(avgChange)*-1):ba.db2linear);
    minus       = tangent;
    };
COMP = detector:maxGRshaper:(_-maxGR)*(1/(1-maxGR)): curve_pow(curve):tanshape(shape):_*(1-maxGR):_+maxGR:ba.linear2db
<: _,( rateLimiter(maxRateAttack,maxRateDecay) ~ _ ):crossfade(ratelimit) : ba.db2linear;
blushcomp =_*ingain: (_ <:( crossfade(feedFwBw,_,_),_ : ( COMP , _ ) : gainHiShelfCrossfade(gainHS))~_)*(ba.db2linear(outgain));
midStereoBlushComp(x,y) =(x+y)*ingain: ((( (crossfade(feedFwBw,_,_): ( COMP ))<:(_,_)) :((_,(x*ingain):gainHiShelfCrossfade(gainHS)),(_,(y*ingain):gainHiShelfCrossfade(gainHS))))~((_,_):+)):((_*(ba.db2linear(outgain))),(_*(ba.db2linear(outgain))));
midBlushComp(x,y) =(x+y)*ingain: (_ <:( crossfade(feedFwBw,_,_),_ : ( COMP , _ ) : gainHiShelfCrossfade(gainHS))~_)
*(ba.db2linear(outgain))<:((_-(y:fi.high_shelf(0,hiShelfFreq))),(_-(x:fi.high_shelf(0,hiShelfFreq))));
detect= (ba.linear2db :
		THRESH(threshold)
		:RATIO);
predelay = 0.05*ma.SR;
delayed(x) = x@predelay;
prevgain=1;
lookaheadLimiter(x,prevgain,prevtotal) =
select2(goingdown,(prevgain+up:min(0),(prevgain+down))),
(totaldown:dbmeter)
with {
    dbmeter =ba.db2linear:meter: ba.linear2db;
    currentlevel = ((abs(x)):ba.linear2db);
    goingdown = ((currentlevel+prevgain)>(threshold))|(prevgain>prevtotal);
    down = (totaldown-prevgain)/predelay;
    totaldown =
       select2(prevgain>=prevtotal', 0  , newdown  );
    newdown =
    min(prevtotal,0-((currentlevel):THRESH(threshold)));
    up = 800/ma.SR;
    tangent     = x- prevx;
    avgChange   = abs((tangent@1)-(tangent@2)):slidingMeanN(IM_size,rmsMaxSize)*decayMult:_+1:pow(decayPower)-1;
    newtangent  = select2(tangent>0,minus,plus):max(maxRateAttack*-1):min(maxRateDecay);
    plus        = tangent*((abs(avgChange)*-1):ba.db2linear);
    minus       = tangent;
    };
limiter(x) = (lookaheadLimiter(x)~(_,_)):((_:ba.db2linear)*x@predelay,!);
lookaheadLimite(x,prevgain,prevtotal) =
select2(abs(x):ba.linear2db-prevgain>threshold,(prevgain+3),(prevgain+4:min(0))),
select2(abs(x):ba.linear2db-prevgain>threshold,1,2);
process = blushcomp;
