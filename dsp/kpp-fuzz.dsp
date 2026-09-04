declare name "KPP Fuzz";
declare description "Vintage fuzz: low-impedance pre-filter, two asymmetric class-A transistor-style cascades with dynamic bias shift, high-shelf tone";
declare author "Oleg Kapitonov";
declare license "GPL-3.0-or-later";
declare source "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_fuzz/kpp_fuzz.dsp";
declare category "guitar";
declare family "dirt";
import("stdfaust.lib");

fuzz   = hslider("[0] Fuzz", 50, 0, 100, 0.01) : si.smoo;
tone   = hslider("[1] Tone[unit:dB]", -7.5, -15, 0, 0.1) : si.smoo;
volume = hslider("[2] Volume", 0.5, 0, 1, 0.001) : si.smoo;

pre_filter = fi.dcblocker : fi.lowpass(1, 2000.0);
biaser(Uin) = Uout letrec {
  'Ulimited = Uin : max(-50.0 + Ubias) : -(Ubias);
  'Ubias = min(Ubias + 100.0*Ulimited/ma.SR - 0.0*Ubias/ma.SR, 2000.0);
  'Uout = Uin - Ubias;
};
distortion = *(100.0) : *(ba.db2linear(fuzz/5.0) - 1.0) : biaser : *(ba.db2linear(fuzz/100.0*6.0)) : max(-50.0) : min(100.0) : fi.dcblocker;
filter = fi.high_shelf(tone + 12.5, 720.0);
process = pre_filter : filter : distortion : *(ba.db2linear(volume * 25.0) / 100.0) : /(20.0);
