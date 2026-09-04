declare name "Granular Gate";
declare description "Bela granulator example turned into a rhythmic stutter gate: the input is chopped by probabilistic noise-burst envelopes at a settable rate and grain size";
declare author "Christophe Lebreton (sfIter), adapted by GRAME";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faust/examples/bela/granulator.dsp";
declare category "drum";
declare family "utility";
import("stdfaust.lib");

freq  = hslider("[0] Grain Size", 200, 5, 2205, 1);
speed = hslider("[1] Speed", 10, 1, 20, 0.01) : fi.lowpass(1, 1);
proba = hslider("[2] Probability", 70, 50, 100, 1)*(0.01) : fi.lowpass(1, 1);
mix   = hslider("[3] Mix", 1, 0, 1, 0.01) : si.smoo;

excitation = noiseburst(gate, P);
ampf = an.amp_follower_ud(duree_env, duree_env);
noiseburst(gate, P) = no.noise : *(gate : trigger(P))
    with {
        upfront(x) = (x-x')>0;
        decay(n, x) = x-(x>0)/n;
        release(n) = +~decay(n);
        trigger(n) = upfront : release(n) : >(0.0);
    };
P = freq;
phasor_bin(init) = (+(float(speed)/float(ma.SR)) : fmod(_, 1.0)) ~ *(init);
gate = phasor_bin(1) : -(0.001) : pulsar;
pulsar = _ <: ((_<(ratio_env)) : @(100))*(proba>(_, abs(no.noise) : ba.latch));
ratio_env = 0.5;
fade = 0.5;
duree_env = 1/(speed : /(ratio_env*(0.25)*fade));
env = excitation : ampf : min(1) : *(3) : min(1);
process = _ <: *(1-mix), (*(env) : *(mix)) :> _;
