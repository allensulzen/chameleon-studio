declare name "DarkBBDDelay";
declare description "Bucket-brigade delay: dark, compressed repeats that get darker each pass";
declare author "Chameleon DSP";
import("stdfaust.lib");

time = hslider("Delay Time[unit:ms]", 280, 30, 800, 5) * 0.001 : si.smooth(ba.tau2pole(0.1));
fb   = hslider("Feedback", 0.55, 0, 0.95, 0.01) : si.smoo;
dark = hslider("Darkness[unit:Hz]", 1800, 500, 5000, 50) : si.smoo;

MAXDEL = 65536;
d = time * ma.SR : min(MAXDEL - 4);
// BBD compander + clock filter in the loop
bbd(x) = ma.tanh(x * 1.6) / 1.6 : fi.lowpass(2, dark) : fi.highpass(1, 90);
echo = (+ : de.fdelay(MAXDEL, d)) ~ (bbd : *(fb));

process(x) = x * 0.9 + echo(x) * 0.7;
