declare name "JCRev Schroeder";
declare description "John Chowning's classic Schroeder reverb (3 allpasses + 4 combs) - vintage computer-music hall";
declare author "Julius O. Smith III";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faustlibraries/reverbs.lib re.jcrev";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

mix = hslider("[0] Mix", 0.3, 0, 1, 0.01) : si.smoo;
tone = hslider("[1] Tone[unit:Hz][scale:log]", 6000, 1000, 16000, 1) : si.smoo;
wet = re.jcrev :> *(0.25) : fi.lowpass(1, tone);
process = _ <: *(1-mix), (wet : *(mix)) :> _;
