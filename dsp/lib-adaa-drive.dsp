declare name "ADAA Drive";
declare description "Alias-suppressed clipper (antiderivative anti-aliasing) with hard/tanh/quadratic modes, pre-gain and tone";
declare author "Dario Sanfilippo";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/aanl.lib aa.hardclip aa.tanh1 aa.softclipQuadratic1";
declare category "guitar";
declare family "dirt";
import("stdfaust.lib");

mode  = nentry("[0] Mode[style:menu{'Hard':0;'Tanh':1;'Quadratic':2}]", 1, 0, 2, 1);
drive = hslider("[1] Drive[unit:dB]", 18, 0, 48, 0.1) : ba.db2linear : si.smoo;
bass  = hslider("[2] Low Cut[unit:Hz][scale:log]", 100, 30, 800, 1) : si.smoo;
tone  = hslider("[3] Tone[unit:Hz][scale:log]", 4500, 800, 12000, 1) : si.smoo;
level = hslider("[4] Level[unit:dB]", -6, -30, 12, 0.1) : ba.db2linear : si.smoo;

clip = _ <: aa.hardclip, aa.tanh1, aa.softclipQuadratic1 : ba.selectn(3, mode);
process = fi.highpass(1, bass) : *(drive) : clip : fi.dcblocker : fi.lowpass(1, tone) : *(level);
