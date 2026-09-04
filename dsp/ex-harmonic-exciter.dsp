declare name "Harmonic Exciter";
declare description "Aphex-style psychoacoustic exciter (US4150253): highpass, compress, cubic harmonic generator, blend back with the dry signal";
declare author "Priyanka Shekar, Julius O. Smith III (revised by Romain Michon)";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faust/examples/psychoacoustic/harmonicExciter.dsp dm.exciter";
declare category "drum";
declare family "utility";
import("stdfaust.lib");

fc     = hslider("[0] Cutoff[unit:Hz][scale:log]", 5000, 1000, 10000, 100) : si.smoo;
ph     = hslider("[1] Harmonics[unit:percent]", 20, 1, 200, 1) : si.smoo : max(1) : /(100);
ratio  = hslider("[2] Ratio", 5, 1, 20, 0.1);
thresh = hslider("[3] Threshold[unit:dB]", -30, -100, 10, 0.1);
ml     = hslider("[4] Mix", 0.5, 0, 1, 0.01) : si.smoo;

compressor = co.compressor_mono(ratio, thresh, 0.05, 0.5);
harmonicCreator(x) = x <: cubDist1, cubDist2, cubDist3 :> _;
cubDist1(x) = (x < 0) * x;
cubDist2(x) = (x >= 0) * (x <= 1) * (x - x ^ 3 / 3);
cubDist3(x) = (x > 1) * 2/3;
process = _ <: (fi.highpass(2, fc) : compressor : *(ph) : harmonicCreator : *(1/ph)), _ : (_ * ml), (_ * (1.0 - ml)) :> _;
