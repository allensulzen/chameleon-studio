declare name "Harmonizer";
declare description "Two ef.transpose voices at independent intervals mixed with the dry note - instant intervals";
declare author "Grame (ef.transpose)";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/misceffects.lib ef.transpose";
declare category "guitar";
declare family "pitch";
import("stdfaust.lib");

s1 = hslider("[0] Voice 1[unit:semi]", 7, -24, 24, 1) : si.smoo;
l1 = hslider("[1] Voice 1 Level", 0.7, 0, 1, 0.01) : si.smoo;
s2 = hslider("[2] Voice 2[unit:semi]", -12, -24, 24, 1) : si.smoo;
l2 = hslider("[3] Voice 2 Level", 0.5, 0, 1, 0.01) : si.smoo;
dry = hslider("[4] Dry", 1, 0, 1, 0.01) : si.smoo;
win = 1500;
process = _ <: *(dry), (ef.transpose(win, 300, s1) : *(l1)), (ef.transpose(win, 300, s2) : *(l2)) :> _;
