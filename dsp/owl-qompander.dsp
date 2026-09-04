declare name "Qompander";
declare description "Katja Vetter's Hilbert-envelope compander (Bart Brouns port): upward companding that adds sustain and bite";
declare author "Bart Brouns (port of Katja Vetter's qompander), Hilbert coefficients by Olli Niemitalo";
declare license "GPL-3.0";
declare source "pingdynasty/OwlPatches Faust/Qompander.dsp";
declare category "guitar";
declare family "dynamics";
import("stdfaust.lib");

factor    = hslider("[0] Factor", 3, 0.8, 8, 0.01) : si.smooth(0.999);
threshold = hslider("[1] Threshold[unit:dB]", -40, -96, -20, 0.01) : si.smooth(0.999);
attack    = hslider("[2] Attack[unit:ms]", 1, 1, 20, 0.01) : si.smooth(0.999);
release   = hslider("[3] Release[unit:ms]", 20, 20, 1000, 0.01) : si.smooth(0.999);
level     = hslider("[4] Level[unit:dB]", -6, -20, 20, 0.1) : ba.db2linear : si.smoo;

magnitude = threshold : ba.db2linear;
exponent = log(magnitude)/log(sin(factor*magnitude*ma.PI/2));
olli1(x) = x : fi.tf2(0.161758, 0, -1, 0, -0.161758) : fi.tf2(0.733029, 0, -1, 0, -0.733029) : fi.tf2(0.94535, 0, -1, 0, -0.94535) : fi.tf2(0.990598, 0, -1, 0, -0.990598);
olli2(x) = x : mem : fi.tf2(0.479401, 0, -1, 0, -0.479401) : fi.tf2(0.876218, 0, -1, 0, -0.876218) : fi.tf2(0.976599, 0, -1, 0, -0.976599) : fi.tf2(0.9975, 0, -1, 0, -0.9975);
pyth(x) = sqrt((olli1(x)*olli1(x))+(olli2(x)*olli2(x))) : max(0.00001) : min(100);
attackDecay(x) = pyth(x) : an.amp_follower_ud(max(0.001, attack/1000), max(0.02, release/1000));
mapping(x) = attackDecay(x) : ((sin((min(1/factor)*(factor/4)) * (2*ma.PI)) : max(0.0000001) : min(1), exponent) : pow);
qompander(x) = (mapping(x) / attackDecay(x)) <: (_,olli1(x):*),(_,olli2(x):*) :+ : _*(sqrt(0.5));
process(x) = qompander(x) * level;
