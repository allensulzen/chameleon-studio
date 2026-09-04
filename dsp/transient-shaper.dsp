declare name "TransientShaper";
declare description "Attack/sustain shaper from fast vs slow envelope ratio";
declare author "Chameleon DSP";
import("stdfaust.lib");

att = hslider("Attack Boost[unit:dB]", 6, -12, 12, 0.5) : si.smoo : ba.db2linear;
sus = hslider("Sustain Tail[unit:dB]", -3, -12, 12, 0.5) : si.smoo : ba.db2linear;
out = hslider("Output Gain[unit:dB]", 0, -6, 6, 0.5) : si.smoo : ba.db2linear;

fast(x) = an.amp_follower_ud(0.0005, 0.020, x);
slow(x) = an.amp_follower_ud(0.020, 0.200, x);
ratio(x) = fast(x) / (slow(x) + 1e-5);
a(x) = ratio(x) - 1 : max(0) : min(1);      // 1 during attacks
s(x) = 1 - ratio(x) : max(0) : min(1);      // 1 during decay/sustain
gain(x) = pow(att, a(x)) * pow(sus, s(x)) : si.smooth(ba.tau2pole(0.0005));

process(x) = x * gain(x) * out : ma.tanh;
