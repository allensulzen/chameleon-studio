declare name "8-Voice Chorus";
declare description "JOS multi-voice chorus from the SHARC Audio Module example: 8 delay taps with per-voice LFO rates and phase-spread deviation, summed to mono";
declare author "Julius O. Smith III, GRAME";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faust/examples/SAM/effects/chorus.dsp";
declare category "guitar";
declare family "mod";
import("stdfaust.lib");

voices = 8;
dmax = 8192;
curdel = dmax*hslider("[0] Delay", 0.5, 0, 1, 0.01) : si.smooth(0.999);
rate   = hslider("[1] Rate[unit:Hz]", 0.5, 0.01, 7, 0.01) : si.smooth(ba.tau2pole(0.15661/6.91));
depth  = hslider("[2] Depth", 0.5, 0, 1, 0.001) : si.smooth(ba.tau2pole(0.15661/6.91));
sigma  = 0.5*curdel/voices*hslider("[3] Deviation", 0.5, 0, 1, 0.001) : si.smooth(0.999);
chorus_mono(dmax, curdel, rate, sigma, do2, voices) = _ <: (*(1-do2) <: _, _), (*(do2) <: par(i, voices, voice(i)) :> _, _) : ro.interleave(2, 2) : +, +
    with {
        angle(i) = 2*ma.PI*(i/2)/voices+(i%2)*ma.PI/2;
        voice(i) = de.fdelay(dmax, min(dmax, del(i)))*cos(angle(i));
        del(i) = curdel*(i+1)/voices+dev(i);
        rates(i) = rate/float(i+1);
        dev(i) = sigma*os.oscp(rates(i), i*2*ma.PI/voices);
    };
process = chorus_mono(dmax, curdel, rate, sigma, depth, voices) :> *(0.5);
