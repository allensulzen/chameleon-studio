declare name "Graphic EQ 7";
declare description "7-band graphic equalizer built on fi.filterbank (Butterworth crossovers) with per-band gain";
declare author "Julius O. Smith III";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faust/examples/filtering/graphicEqLab.dsp fi.filterbank";
declare category "guitar";
declare family "utility";
import("stdfaust.lib");

g(i, f) = hslider("[%i] %f Hz[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;
gains = g(0, 100), g(1, 200), g(2, 400), g(3, 800), g(4, 1600), g(5, 3200), g(6, 6400);
process = fi.filterbank(3, (141, 283, 566, 1131, 2263, 4525)) : ro.cross(7) : par(i, 7, *(ba.take(i+1, gains))) :> _;
