declare name "Tone Stack";
declare description "Passive amp tone stacks from exact component values: Bassman, JCM800, Twin, AC30, Mesa, Soldano, Princeton";
declare author "Guitarix project / David Yeh (tonestack analysis)";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/tonestacks.lib";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");
ts = library("tonestacks.lib");

model = nentry("[0] Model[style:menu{'Bassman':0;'JCM800':1;'Twin':2;'AC30':3;'Mesa':4;'Soldano':5;'Princeton':6}]", 0, 0, 6, 1);
b = hslider("[1] Bass", 0.5, 0, 1, 0.01) : si.smoo;
m = hslider("[2] Middle", 0.5, 0, 1, 0.01) : si.smoo;
t = hslider("[3] Treble", 0.5, 0, 1, 0.01) : si.smoo;
level = hslider("[4] Level[unit:dB]", 6, -20, 24, 0.1) : ba.db2linear : si.smoo;

stacks = ts.bassman(t,m,b), ts.jcm800(t,m,b), ts.twin(t,m,b), ts.ac30(t,m,b), ts.mesa(t,m,b), ts.soldano(t,m,b), ts.princeton(t,m,b);
process = _ <: stacks : ba.selectn(7, model) : *(level);
