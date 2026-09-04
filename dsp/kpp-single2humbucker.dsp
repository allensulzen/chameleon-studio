declare name "KPP Single to Humbucker";
declare description "Primitive humbucker imitation for single-coil guitars: comb from a second delayed coil, lowpass and mid bump, bass cut";
declare author "Oleg Kapitonov";
declare license "GPL-3.0-or-later";
declare source "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_single2humbucker/kpp_single2humbucker.dsp";
declare category "guitar";
declare family "utility";
import("stdfaust.lib");

effect_knob = hslider("[0] Humbuckerize", 1, 0, 1, 0.001) : si.smoo;
filter_knob = hslider("[1] Bass Cut[unit:Hz]", 20, 20, 720, 0.1) : si.smoo;
level       = hslider("[2] Level[unit:dB]", -4, -20, 20, 0.1) : ba.db2linear : si.smoo;
delay_samples = ma.SR / 2880 / 2;
effect = fi.highpass(1,20) <: _, de.delay(50, delay_samples) : + : fi.lowpass(2, 5500) : fi.peak_eq(6.0, 550, 750);
process = _ <: (*(effect_knob) : effect), (*(1.0 - effect_knob)) : + : fi.highpass(1, max(20, filter_knob)) : *(level);
