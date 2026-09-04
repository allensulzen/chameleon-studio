declare name "CryBaby Auto-Wah";
declare description "CryBaby wah driven by an amplitude follower - envelope filter / touch-wah";
declare author "Julius O. Smith III";
declare license "MIT";
declare source "grame-cncm/faustlibraries/vaeffects.lib ve.autowah";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

sens  = hslider("[0] Sensitivity[unit:dB]", 12, 0, 40, 0.1) : ba.db2linear : si.smoo;
mixamt= hslider("[1] Effect", 1, 0, 1, 0.01) : si.smoo;
rel   = hslider("[2] Release[unit:ms]", 100, 10, 1000, 1);
level = hslider("[3] Level[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;

env(x) = an.amp_follower_ud(0.005, rel/1000, x*sens) : min(1);
process(x) = (mixamt * ve.crybaby(env(x), x) + (1-mixamt) * x) * level;
