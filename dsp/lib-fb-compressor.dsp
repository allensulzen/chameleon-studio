declare name "FB Compressor";
declare description "Bart Brouns feed-back peak compressor - vintage-style program-dependent behaviour";
declare author "Bart Brouns";
declare license "GPL-3.0-only";
declare source "grame-cncm/faustlibraries/compressors.lib co.FBcompressor_N_chan";
declare category "guitar";
declare family "dynamics";
import("stdfaust.lib");

strength = hslider("[0] Strength", 0.6, 0, 1, 0.01) : si.smoo;
thresh   = hslider("[1] Threshold[unit:dB]", -24, -60, 0, 0.1) : si.smoo;
att      = hslider("[2] Attack[unit:ms]", 5, 0.1, 100, 0.1) : /(1000);
rel      = hslider("[3] Release[unit:ms]", 150, 10, 1000, 1) : /(1000);
knee     = hslider("[4] Knee[unit:dB]", 6, 0, 24, 0.1) : si.smoo;
makeup   = hslider("[5] Makeup[unit:dB]", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;
process = co.FBcompressor_N_chan(strength, thresh, att, rel, knee, 0, 0, _, 1) : *(makeup);
