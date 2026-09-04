declare name "BBDChorus";
declare description "Two-voice bucket-brigade chorus with band-limited delay lines";
declare author "Chameleon DSP";
import("stdfaust.lib");

rate  = hslider("Speed[unit:Hz]", 1.2, 0.1, 8.0, 0.05) : si.smoo;
depth = hslider("Depth", 0.65, 0, 1.0, 0.01) : si.smoo;
blend = hslider("Blend", 0.5, 0, 1.0, 0.01) : si.smoo;

MAXDEL = 2048;
lfo1 = os.osc(rate);
lfo2 = os.oscp(rate * 0.93, ma.PI * 0.5);
d1 = (0.0065 + depth * 0.0030 * lfo1) * ma.SR;
d2 = (0.0090 + depth * 0.0028 * lfo2) * ma.SR;

// BBD clock filtering: anti-alias/reconstruction lowpass + slight companding grit
bbd = fi.lowpass(2, 7500);
voice(d, x) = de.fdelay(MAXDEL, d, x) : bbd;
wet(x) = (voice(d1, x) + voice(d2, x)) * 0.55;

process(x) = x * (1 - blend * 0.5) + wet(x) * blend;
