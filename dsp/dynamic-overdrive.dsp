declare name "DynamicOverdrive";
declare description "Asymmetric tube-style overdrive with pre-emphasis and post tone";
declare author "Chameleon DSP";
import("stdfaust.lib");

gain  = hslider("Gain[unit:dB]", 18, 1, 50, 0.5) : si.smoo : ba.db2linear;
tone  = hslider("Tone[unit:Hz]", 2800, 500, 6000, 50) : si.smoo;
level = hslider("Level", 0.6, 0, 1.0, 0.01) : si.smoo;

// input conditioning: cut mud, tube-screamer style mid hump before the clipper
pre   = fi.highpass(1, 90) : fi.peak_eq(5, 750, 900);

// asymmetric soft clip: positive half saturates later than negative half
clip(x) = select2(x > 0, ma.tanh(x * 1.5) / 1.5, ma.tanh(x));

// keep loudness roughly steady as gain climbs
comp  = 2.0 / pow(gain, 0.5) : min(1.3);
post  = fi.dcblocker : fi.lowpass(2, tone) : fi.highpass(1, 60);

process = pre : *(gain) : clip : post : *(comp * level);
