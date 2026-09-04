declare name "RingModulator";
declare description "Ring modulator with sine-to-square carrier morph";
declare author "Chameleon DSP";
import("stdfaust.lib");

freq  = hslider("Carrier Freq[unit:Hz]", 440, 50, 2500, 10) : si.smoo;
shape = hslider("Wave Shape", 0.2, 0, 1.0, 0.01) : si.smoo;
mix   = hslider("Mix", 0.5, 0, 1.0, 0.01) : si.smoo;

// morph sine -> square by driving the sine into a clipper
carrier = os.osc(freq) * (1 + shape * 12) : ma.tanh;
process(x) = x * (1 - mix) + x * carrier * mix;
