declare name "ReverseDelay";
declare description "Windowed backwards playback with crossfaded read heads and feedback";
declare author "Chameleon DSP";
import("stdfaust.lib");

wtime = hslider("Window Time[unit:ms]", 600, 100, 1500, 10) * 0.001 : si.smooth(ba.tau2pole(0.2));
fb    = hslider("Feedback", 0.4, 0, 0.9, 0.01) : si.smoo;
mix   = hslider("Mix", 0.5, 0, 1.0, 0.01) : si.smoo;

MAXDEL = 131072;
W   = wtime * ma.SR : max(256) : min(MAXDEL / 2 - 4);   // never 0: the period counter divides by W
// two read heads, half a window apart, each running backwards through the buffer
ph1 = ba.period(W);
ph2 = (ph1 + W * 0.5) : fmod(_, W);
win(p) = sin(ma.PI * p / W);
head(p, x) = de.fdelay(MAXDEL, 2 * p, x) * win(p);
rev(x) = (head(ph1, x) + head(ph2, x)) * 0.75;

loop = (+ : rev) ~ (fi.lowpass(1, 4500) : *(fb) : ma.tanh);
process = _ <: *(1 - mix), (loop : *(mix)) :> _;
