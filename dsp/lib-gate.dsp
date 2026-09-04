declare name "Noise Gate";
declare description "JOS ef.gate_mono: threshold gate with attack, hold and release";
declare author "Julius O. Smith III";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/misceffects.lib ef.gate_mono";
declare category "guitar";
declare family "dynamics";
import("stdfaust.lib");

thresh = hslider("[0] Threshold[unit:dB]", -40, -90, 0, 0.1);
att    = hslider("[1] Attack[unit:ms]", 1, 0.02, 100, 0.01) : /(1000);
hold   = hslider("[2] Hold[unit:ms]", 50, 1, 1000, 1) : /(1000);
rel    = hslider("[3] Release[unit:ms]", 100, 1, 1000, 1) : /(1000);
process = ef.gate_mono(thresh, att, hold, rel);
