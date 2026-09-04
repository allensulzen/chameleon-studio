declare name "JFETBoost";
declare description "Class-A JFET style boost with tilt EQ and gentle saturation";
declare author "Chameleon DSP";
import("stdfaust.lib");

boost  = hslider("Boost[unit:dB]", 12, 0, 25, 0.5) : si.smoo : ba.db2linear;
tilt   = hslider("Tilt EQ[unit:dB]", 2, -10, 10, 0.5) : si.smoo;
master = hslider("Master", 0.8, 0, 1.0, 0.01) : si.smoo;

// tilt around 900 Hz: +tilt on highs, -tilt on lows
tilteq = fi.low_shelf(0 - tilt, 900) : fi.high_shelf(tilt, 900);
// JFET: mostly linear, rounds off only the peaks
jfet(x) = x - 0.12 * x * x * x : max(-1.4) : min(1.4);

process = fi.highpass(1, 40) : tilteq : *(boost * 0.5) : jfet : *(master * 1.0);
