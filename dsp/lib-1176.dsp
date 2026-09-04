declare name "1176 Limiter R4";
declare description "co.limiter_1176_R4_mono: UREI 1176-style FET limiter at ratio 4, fast attack, with input/output gain";
declare author "Julius O. Smith III";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/compressors.lib co.limiter_1176_R4_mono";
declare category "guitar";
declare family "dynamics";
import("stdfaust.lib");

ingain  = hslider("[0] Input[unit:dB]", 12, 0, 40, 0.1) : ba.db2linear : si.smoo;
outgain = hslider("[1] Output[unit:dB]", -6, -30, 12, 0.1) : ba.db2linear : si.smoo;
process = *(ingain) : co.limiter_1176_R4_mono : *(outgain);
