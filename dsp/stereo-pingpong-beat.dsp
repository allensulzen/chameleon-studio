declare name "MultiTapBeatDelay";
declare description "Rhythmic two-tap delay (straight + dotted) with filtered feedback";
declare author "Chameleon DSP";
import("stdfaust.lib");

time   = hslider("Tempo / Time[unit:ms]", 240, 50, 600, 5) * 0.001 : si.smooth(ba.tau2pole(0.1));
fb     = hslider("Feedback", 0.45, 0, 0.9, 0.01) : si.smoo;
dotted = hslider("Dotted Tap", 0.8, 0, 1.0, 0.01) : si.smoo;

MAXDEL = 65536;
d1 = time * ma.SR : min(MAXDEL - 4);
d2 = time * 0.75 * ma.SR : min(MAXDEL - 4);

tone = fi.lowpass(1, 5000) : fi.highpass(1, 120);
tap  = (+ : de.fdelay(MAXDEL, d1)) ~ (tone : *(fb));
dot  = de.fdelay(MAXDEL, d2) : fi.lowpass(1, 3500);

process(x) = x * 0.9 + tap(x) * 0.65 + dot(x) * dotted * 0.45;
