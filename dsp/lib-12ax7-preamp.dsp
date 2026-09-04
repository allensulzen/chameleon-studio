declare name "12AX7 Preamp";
declare description "Three cascaded table-driven 12AX7 triode stages (tubes.lib) with gain, JCM800 tone stack and master";
declare author "Guitarix project (tube tables), GRAME";
declare license "GPL-2.0-or-later";
declare source "grame-cncm/faustlibraries/tubes.lib tu.T1_12AX7/T2/T3 + tonestacks.lib";
declare category "guitar";
declare family "amp";
import("stdfaust.lib");
tu = library("tubes.lib");
ts = library("tonestacks.lib");

pre    = hslider("[0] Pregain[unit:dB]", 12, -20, 40, 0.1) : ba.db2linear : si.smoo;
gain   = hslider("[1] Gain[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;
bass   = hslider("[2] Bass", 0.5, 0, 1, 0.01) : si.smoo;
mid    = hslider("[3] Middle", 0.5, 0, 1, 0.01) : si.smoo;
treble = hslider("[4] Treble", 0.5, 0, 1, 0.01) : si.smoo;
master = hslider("[5] Master[unit:dB]", 0, -30, 20, 0.1) : ba.db2linear : si.smoo;

stage1 = *(pre) : tu.T1_12AX7 : fi.lowpass(1, 6531) : tu.T2_12AX7 : *(gain);
stage2 = fi.lowpass(1, 6531) : tu.T3_12AX7;
process = stage1 : stage2 : ts.jcm800(treble, mid, bass) : fi.dcblocker : *(master);
