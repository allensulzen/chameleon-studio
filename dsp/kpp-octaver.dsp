declare name "KPP Octaver";
declare description "Analog-style octaver: extracts the fundamental, squares it, divides by 2 and 4 and modulates the input for -1 and -2 octave tones";
declare author "Oleg Kapitonov";
declare license "GPL-3.0-or-later";
declare source "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_octaver/kpp_octaver.dsp";
declare category "guitar";
declare family "pitch";
import("stdfaust.lib");

level_d1  = hslider("[0] Octave 1", 20, 0, 30, 0.01) : si.smoo : -(20) : ba.db2linear;
level_d2  = hslider("[1] Octave 2", 10, 0, 30, 0.01) : si.smoo : -(20) : ba.db2linear;
level_dry = hslider("[2] Dry", 30, 0, 30, 0.01) : si.smoo : -(30) : ba.db2linear;
cutoff    = hslider("[3] Cutoff[unit:Hz]", 160, 100, 200, 0.1);

pre_filter = fi.dcblocker : fi.lowpass(3, 80) : fi.peak_eq(30, 100, 80) : fi.peak_eq(20, 440, 200);
distortion = (+ : co.compressor_mono(100, -80, 0.1, 0.1) : ma.signum : max(-0.0000001) : min(0.0000001)) ~ _;
octaver = distortion : fi.zero(1) : max(0.0) : ma.signum : *(-2.0) : +(1.0) :
  (* : +(0.1) : *(10000.0) : max(-1.0) : min(1.0)) ~ _ : max(0.0) : min(1.0);
down1 = _ <: fi.highpass(1,260), (pre_filter : octaver) : * : fi.lowpass(3, cutoff) : fi.highpass(3, 40) : fi.highpass(1, 80);
down2 = _ <: fi.highpass(5,240), (pre_filter : octaver : -(0.5) : octaver) : * : fi.lowpass(3, cutoff / 2.0);
stomp = _ <: down1, down2 : *(level_d1), *(level_d2) : + : *(2.0) : fi.dcblocker;
process = _ <: *(level_dry), stomp : +;
