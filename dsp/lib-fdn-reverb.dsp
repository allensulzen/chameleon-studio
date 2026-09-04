declare name "FDN Reverb 16";
declare description "16-line feedback delay network with 5-band decay times and room dimension (fdnrev0)";
declare author "Julius O. Smith III";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faustlibraries/reverbs.lib re.fdnrev0";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

N = 16; NB = 5; BBSO = 3; MAXDELAY = 8192;
pathmin = hslider("[0] Room Min[unit:m][scale:log]", 20, 0.5, 63, 0.1);
pathmax = hslider("[1] Room Max[unit:m][scale:log]", 45, 0.5, 63, 0.1);
t60lo   = hslider("[2] Low RT60[unit:s]", 3.0, 0.1, 20, 0.1);
t60hi   = hslider("[3] High RT60[unit:s]", 1.2, 0.1, 20, 0.1);
mix     = hslider("[4] Mix", 0.35, 0, 1, 0.01) : si.smoo;

durs = par(i, NB, t60hi + (t60lo - t60hi) * i / (NB-1));
freqs = (500, 1000, 2000, 4000);
delays = de.prime_power_delays(N, pathmin, pathmax);
wet = _ <: si.bus(N) : re.fdnrev0(MAXDELAY, delays, BBSO, freqs, durs, 1.0, 0) :> *(0.03);
process = _ <: *(1-mix), (wet : *(mix)) :> _;
