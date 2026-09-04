declare name "TapeSaturator";
declare description "Tape-style saturation with low-end warmth and HF softening";
declare author "Chameleon DSP";
import("stdfaust.lib");

drive  = hslider("Tape Drive", 0.45, 0, 1.0, 0.01) : si.smoo;
warmth = hslider("Warmth", 0.6, 0, 1.0, 0.01) : si.smoo;
out    = hslider("Output Level", 0.75, 0, 1.0, 0.01) : si.smoo;

g      = 1 + drive * 6;
sat(x) = ma.tanh(x * g) / pow(g, 0.6);
hfroll = 16000 - drive * 8000;

process = fi.low_shelf(warmth * 6, 160) : sat : fi.dcblocker : fi.lowpass(1, hfroll) : *(out * 1.2);
