declare name "DrumSlammer";
declare description "1176-style peak limiter into a variable-hardness clipper";
declare author "Chameleon DSP";
import("stdfaust.lib");

drive   = hslider("Threshold / Drive[unit:dB]", 12, 0, 24, 0.5) : si.smoo : ba.db2linear;
hard    = hslider("Hardness", 0.7, 0, 1.0, 0.01) : si.smoo;
ceilDb  = hslider("Ceiling[unit:dB]", -0.5, -12, 0, 0.1) : si.smoo;

ceilLin = ceilDb : ba.db2linear;
soft(x) = ma.tanh(x);
hclip(x) = max(-1, min(1, x));
clipper(x) = soft(x) * (1 - hard) + hclip(x) * hard;

process = *(drive) : co.limiter_1176_R4_mono : clipper : *(ceilLin);
