declare name "KPP Dead Gate";
declare description "Aggressive noise gate: instant dead-zone clamp plus a 7-band multiband gate (10 ms attack, 20 ms hold/release)";
declare author "Oleg Kapitonov";
declare license "GPL-3.0-or-later";
declare source "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_deadgate/kpp_deadgate.dsp";
declare category "guitar";
declare family "dynamics";
import("stdfaust.lib");

deadzone_knob  = hslider("[0] Dead Zone[unit:dB]", -60, -120, 0, 0.1) : ba.db2linear;
noizegate_knob = hslider("[1] Noise Gate[unit:dB]", -60, -120, 0, 0.1);
level = hslider("[2] Level[unit:dB]", 0, -20, 20, 0.1);
deadzone = _ <: (max(deadzone_knob) : -(deadzone_knob)), (min(-deadzone_knob) : +(deadzone_knob)) : +;
multigate = fi.filterbank(3, (65, 150, 300, 600, 1200, 2400)) : par(i, 7, ef.gate_mono(noizegate_knob, 0.01, 0.02, 0.02)) :> _;
process = fi.highpass(1,10) : deadzone : multigate : *(ba.db2linear(level));
