declare name "ExpanderGate";
declare description "Downward expander / noise gate with range control";
declare author "Chameleon DSP";
import("stdfaust.lib");

thresh = hslider("Threshold[unit:dB]", -38, -60, -10, 1) : si.smoo;
rel    = hslider("Release Speed[unit:ms]", 75, 10, 300, 5) * 0.001;
range  = hslider("Floor Cut[unit:dB]", -28, -40, 0, 1) : si.smoo;

ratio  = 4;
lvl(x) = an.amp_follower_ud(0.0005, rel, x) : ba.linear2db;
// below threshold, reduce by (ratio-1) dB per dB, but never more than 'range'
gdb(x) = (lvl(x) - thresh) * (ratio - 1) : min(0) : max(range);
gain(x) = gdb(x) : ba.db2linear : si.smooth(ba.tau2pole(0.002));

process(x) = x * gain(x);
