declare name "HarmonicTremolo";
declare description "Brownface harmonic tremolo: LR crossover, bands modulated in anti-phase";
declare author "Chameleon DSP";
import("stdfaust.lib");

rate  = hslider("Rate[unit:Hz]", 4.0, 0.5, 12.0, 0.1) : si.smoo;
depth = hslider("Depth", 0.75, 0, 1.0, 0.01) : si.smoo;
level = hslider("Level", 0.7, 0, 1.0, 0.01) : si.smoo;

xover = 650;
lo = fi.lowpass(2, xover) : fi.lowpass(2, xover);    // Linkwitz-Riley 4
hi = fi.highpass(2, xover) : fi.highpass(2, xover);

// slightly rounded, tube-bias style LFO
lfo    = os.osc(rate) : *(1.25) : ma.tanh : /(0.848);
g_lo   = 1 - depth * 0.5 * (1 + lfo);
g_hi   = 1 - depth * 0.5 * (1 - lfo);
gain   = 0.5 + level * 1.0;

process(x) = (lo(x) * g_lo + hi(x) * g_hi) * gain;
