declare name "Lookahead Limiter";
declare description "Dario Sanfilippo's IEM-style lookahead brickwall limiter with ceiling, hold and release";
declare author "Dario Sanfilippo";
declare license "GPL-3.0-only";
declare source "grame-cncm/faustlibraries/compressors.lib co.limiter_lad_N";
declare category "drum";
declare family "dynamics";
import("stdfaust.lib");

ingain  = hslider("[0] Input[unit:dB]", 12, 0, 40, 0.1) : ba.db2linear : si.smoo;
ceiling = hslider("[1] Ceiling[unit:dB]", -1, -20, 0, 0.1) : ba.db2linear;
att     = hslider("[2] Attack[unit:ms]", 3, 0.5, 6, 0.1) : /(1000);
hold    = hslider("[3] Hold[unit:ms]", 30, 0, 500, 1) : /(1000);
rel     = hslider("[4] Release[unit:ms]", 100, 5, 1000, 1) : /(1000);
process = *(ingain) : co.limiter_lad_N(1, 0.01, ceiling, att, hold, rel);
