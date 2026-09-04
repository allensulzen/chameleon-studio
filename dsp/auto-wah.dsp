declare name "AutoWah";
declare description "Envelope-following resonant band-pass (Q-Tron style)";
declare author "Chameleon DSP";
import("stdfaust.lib");

sens = hslider("Sensitivity", 0.6, 0, 1.0, 0.01) : si.smoo;
q    = hslider("Resonance", 7.0, 1, 15, 0.5) : si.smoo;
mix  = hslider("Mix", 0.8, 0, 1.0, 0.01) : si.smoo;

env(x) = an.amp_follower_ud(0.004, 0.12, x) * (2 + sens * 14) : min(1);
// exponential sweep 280 Hz .. 2600 Hz
fc(x)  = 280 * pow(2600 / 280, env(x));
wah(x) = fi.resonbp(fc(x), q, 1, x) * (1 + q * 0.03) : ma.tanh;

process(x) = x * (1 - mix) + wah(x) * mix;
