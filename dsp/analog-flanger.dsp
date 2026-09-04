declare name "JetFlanger";
declare description "Resonant flanger with through-zero style sweep and bipolar feedback";
declare author "Chameleon DSP";
import("stdfaust.lib");

rate  = hslider("Rate[unit:Hz]", 0.4, 0.05, 5.0, 0.02) : si.smoo;
depth = hslider("Depth", 0.8, 0, 1.0, 0.01) : si.smoo;
res   = hslider("Resonance", 0.75, -0.95, 0.95, 0.01) : si.smoo;

// triangle-ish LFO gives the classic "jet" sweep
lfo   = os.osc(rate) : *(1.8) : ma.tanh : /(0.947);
del   = (0.0006 + depth * 0.0055 * 0.5 * (1 + lfo)) * ma.SR;
// flanger_mono(dmax, curdel, depth, fb, invert)
process = pf.flanger_mono(1024, del, 1.0, res, 0) : ma.tanh;
