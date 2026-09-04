declare name "FrequencyShifter";
declare description "Bode-style single-sideband frequency shifter (Hilbert allpass pair)";
declare author "Chameleon DSP";
import("stdfaust.lib");

shift = hslider("Shift Amount[unit:Hz]", 85, -500, 500, 1) : si.smoo;
fb    = hslider("Feedback", 0.2, 0, 0.8, 0.01) : si.smoo;
mix   = hslider("Mix", 0.6, 0, 1.0, 0.01) : si.smoo;

// Niemitalo 90-degree allpass network
ap(a, x) = y with { a2 = a * a; y = (a2 * x - x@2 + a2 * _) ~ mem; };
pathA = ap(0.6923878) : ap(0.9360654322959) : ap(0.9882295226860) : ap(0.9987488452737);
pathB = ap(0.4021921162426) : ap(0.8561710882420) : ap(0.9722909545651) : ap(0.9952884791278) : mem;

ssb(x) = pathA(x) * os.oscp(shift, 0) - pathB(x) * os.oscp(shift, ma.PI * 0.5);
loop = (+ : ssb) ~ (fi.lowpass(1, 6000) : *(fb) : ma.tanh);

process(x) = x * (1 - mix) + loop(x) * mix;
