declare name "GatedSnareReverb";
declare description "Big room reverb keyed by the dry input and slammed shut after a hold time";
declare author "Chameleon DSP";
import("stdfaust.lib");

hold = hslider("Gate Hold[unit:ms]", 220, 50, 500, 5) * 0.001;
size = hslider("Room Size", 0.8, 0.1, 1.0, 0.05) : si.smoo;
mix  = hslider("Wet Mix", 0.6, 0, 1.0, 0.01) : si.smoo;

room = 0.7 + size * 0.25;
verb = fi.highpass(1, 140) <: re.stereo_freeverb(room, 0.5, 0.25, 0.7) :> *(0.07);

// gate keyed from the dry input, not the reverb tail
// key on the kick/snare band so hi-hats don't hold the gate open
key(x)  = fi.bandpass(1, 90, 1600, x) : an.amp_follower_ar(0.0005, hold) > 0.10;
gate(x) = key(x) : si.smooth(ba.tau2pole(0.003));

process(x) = x * (1 - mix) + (verb(x) : ma.tanh) * gate(x) * mix;
