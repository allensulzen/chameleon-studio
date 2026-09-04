declare name "3-Band Compressor";
declare description "fi.filterbank 3-way split into three Bart Brouns feed-forward compressors with per-band strength - multiband drum control";
declare author "Bart Brouns (compressors), Julius O. Smith III (filterbank)";
declare license "GPL-3.0-only";
declare source "grame-cncm/faustlibraries/compressors.lib co.FFcompressor_N_chan + fi.filterbank";
declare category "drum";
declare family "dynamics";
import("stdfaust.lib");

xlo    = hslider("[0] Low Xover[unit:Hz][scale:log]", 200, 60, 800, 1);
xhi    = hslider("[1] High Xover[unit:Hz][scale:log]", 2500, 800, 8000, 1);
sLo    = hslider("[2] Low Strength", 0.6, 0, 1, 0.01) : si.smoo;
sMid   = hslider("[3] Mid Strength", 0.5, 0, 1, 0.01) : si.smoo;
sHi    = hslider("[4] High Strength", 0.4, 0, 1, 0.01) : si.smoo;
thresh = hslider("[5] Threshold[unit:dB]", -30, -60, 0, 0.1) : si.smoo;
att    = hslider("[6] Attack[unit:ms]", 8, 0.1, 100, 0.1) : /(1000);
rel    = hslider("[7] Release[unit:ms]", 150, 10, 1000, 1) : /(1000);
makeup = hslider("[8] Makeup[unit:dB]", 6, 0, 30, 0.1) : ba.db2linear : si.smoo;

comp(s) = co.FFcompressor_N_chan(s, thresh, att, rel, 6, 0, 0, _, 1);
process = fi.filterbank(3, (xlo, xhi)) : comp(sHi), comp(sMid), comp(sLo) :> *(makeup);
