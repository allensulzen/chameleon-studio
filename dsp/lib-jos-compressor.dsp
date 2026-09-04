declare name "JOS Compressor";
declare description "Classic ratio/threshold/attack/release compressor (co.compressor_mono) with makeup - the Faust textbook compressor";
declare author "Julius O. Smith III";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faust/examples/dynamic/compressor.dsp co.compressor_mono";
declare category "drum";
declare family "dynamics";
import("stdfaust.lib");

ratio  = hslider("[0] Ratio", 4, 1, 20, 0.1);
thresh = hslider("[1] Threshold[unit:dB]", -24, -60, 0, 0.1);
att    = hslider("[2] Attack[unit:ms]", 10, 0.1, 500, 0.1) : /(1000);
rel    = hslider("[3] Release[unit:ms]", 150, 1, 1000, 1) : /(1000);
makeup = hslider("[4] Makeup[unit:dB]", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;
process = co.compressor_mono(ratio, thresh, att, rel) : *(makeup);
