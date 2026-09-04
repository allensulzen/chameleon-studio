declare name "Vital Reverb";
declare description "Matt Tytel's Vital synth reverb: pre-filter, shelving, chorused FDN tail";
declare author "David Braun (Faust port), Matt Tytel (Vital)";
declare license "GPL-3.0-only";
declare source "grame-cncm/faustlibraries/reverbs.lib re.vital_rev";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

prelow  = hslider("[0] Pre Low Cut", 0, 0, 1, 0.01) : si.smoo;
prehigh = hslider("[1] Pre High Cut", 0.79, 0, 1, 0.01) : si.smoo;
lowcut  = hslider("[2] Low Shelf", 0, 0, 1, 0.01) : si.smoo;
lowgain = hslider("[3] Low Gain", 1, 0, 1, 0.01) : si.smoo;
highcut = hslider("[4] High Shelf", 0.62, 0, 1, 0.01) : si.smoo;
highgain= hslider("[5] High Gain", 0.83, 0, 1, 0.01) : si.smoo;
chamt   = hslider("[6] Chorus Amount", 0.01, 0, 1, 0.01) : si.smoo;
chrate  = hslider("[7] Chorus Rate", 0.1, 0, 1, 0.01) : si.smoo;
predel  = hslider("[8] Pre-Delay", 0, 0, 1, 0.01) : si.smoo;
time    = hslider("[9] Decay Time", 0.5, 0, 1, 0.01) : si.smoo;
size    = hslider("[10] Size", 0.5, 0, 1, 0.01) : si.smoo;
mix     = hslider("[11] Mix", 0.4, 0, 1, 0.01) : si.smoo;

process = _ <: re.vital_rev(prelow, prehigh, lowcut, highcut, lowgain, highgain, chamt, chrate, predel, time, size, mix) :> *(0.5);
