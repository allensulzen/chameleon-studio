declare name "SubBassResonator";
declare description "Tuned low resonator excited by kick transients";
declare author "Chameleon DSP";
import("stdfaust.lib");

freq  = hslider("Tuned Frequency[unit:Hz]", 52, 35, 90, 1) : si.smoo;
decay = hslider("Decay Length[unit:ms]", 320, 50, 800, 10) * 0.001 : si.smoo;
vol   = hslider("Sub Volume", 0.7, 0, 1.0, 0.01) : si.smoo;

// 2-pole resonator: t60 ~= Q * ln(1000) / (pi * f)  ->  Q = t60 * pi * f / 6.9
q      = decay * ma.PI * freq / 6.9 : max(2) : min(120);
// excite with the transient of the low band only
exc(x) = fi.lowpass(2, 140, x) * 6 : ma.tanh;
sub(x) = fi.resonbp(freq, q, 1, exc(x)) * 1.2 : ma.tanh : *(0.45);

process(x) = x * 0.9 + sub(x) * vol;
