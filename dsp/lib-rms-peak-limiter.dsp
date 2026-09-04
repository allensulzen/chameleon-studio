declare name "RMS Comp + Peak Limiter";
declare description "Bart Brouns RMS feedback compressor followed by a peak limiter - drum bus glue with brickwall safety";
declare author "Bart Brouns";
declare license "GPL-3.0-only";
declare source "grame-cncm/faustlibraries/compressors.lib co.RMS_FBcompressor_peak_limiter_N_chan (origin magnetophon/faustCompressors)";
declare category "drum";
declare family "dynamics";
import("stdfaust.lib");

strength  = hslider("[0] Strength", 0.5, 0, 1, 0.01) : si.smoo;
thresh    = hslider("[1] Threshold[unit:dB]", -24, -60, 0, 0.1) : si.smoo;
threshLim = hslider("[2] Limit[unit:dB]", -3, -30, 0, 0.1) : si.smoo;
att       = hslider("[3] Attack[unit:ms]", 20, 1, 200, 0.1) : /(1000);
rel       = hslider("[4] Release[unit:ms]", 120, 10, 1500, 1) : /(1000);
knee      = hslider("[5] Knee[unit:dB]", 6, 0, 24, 0.1) : si.smoo;
makeup    = hslider("[6] Makeup[unit:dB]", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;
process = *(makeup) : co.RMS_FBcompressor_peak_limiter_N_chan(strength, thresh, threshLim, att, rel, knee, 0, _, _, 1);
