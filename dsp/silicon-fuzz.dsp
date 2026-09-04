declare name "SiliconFuzz";
declare description "Gated silicon fuzz with bias control and wavefold spit";
declare author "Chameleon DSP";
import("stdfaust.lib");

fuzz  = hslider("Fuzz[unit:dB]", 40, 1, 60, 1) : si.smoo : ba.db2linear;
bias  = hslider("Bias", 0.35, 0, 1.0, 0.01) : si.smoo;
level = hslider("Level", 0.5, 0, 1.0, 0.01) : si.smoo;

// envelope-driven gate: starved-bias transistors choke quiet signals
env(x)  = an.amp_follower_ud(0.002, 0.06, x);
gthr    = 0.004 + bias * 0.06;
gate(x) = x * (env(x) > gthr : si.smooth(ba.tau2pole(0.004)));

// bias shifts the operating point -> asymmetric clipping / even harmonics
hard(x) = max(-1, min(1, x));
stage(x) = x + bias * 0.4 : hard : fi.dcblocker;
// a little wavefold on the peaks for the "spitting" quality
fold(x) = x - 0.18 * sin(x * ma.PI * 1.5);

process = fi.highpass(1, 70) : *(fuzz) : ma.tanh : stage : fold : gate : fi.lowpass(2, 4200) : *(level * 0.9);
