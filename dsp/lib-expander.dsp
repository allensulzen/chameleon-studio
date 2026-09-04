declare name "Expander";
declare description "Downward expander (co.expander_N_chan) with range, hold and knee - tightens noise between notes";
declare author "Bart Brouns";
declare license "GPL-3.0-only";
declare source "grame-cncm/faustlibraries/compressors.lib co.expander_N_chan";
declare category "guitar";
declare family "dynamics";
import("stdfaust.lib");

strength = hslider("[0] Strength", 2, 0.1, 10, 0.1) : si.smoo;
thresh   = hslider("[1] Threshold[unit:dB]", -40, -80, 0, 0.1) : si.smoo;
range    = hslider("[2] Range[unit:dB]", 40, 0, 80, 1) : *(-1);
att      = hslider("[3] Attack[unit:ms]", 2, 0.1, 100, 0.1) : /(1000);
hold     = hslider("[4] Hold[unit:ms]", 20, 0, 500, 1) : /(1000);
rel      = hslider("[5] Release[unit:ms]", 100, 10, 1000, 1) : /(1000);
knee     = hslider("[6] Knee[unit:dB]", 6, 0, 24, 0.1) : si.smoo;
process = co.expander_N_chan(strength, thresh, range, att, hold, rel, knee, 0, 0, _, 24000, 1);
