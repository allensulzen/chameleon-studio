declare name "Ring Modulator";
declare description "Sine-carrier ring modulation with carrier blend and lowpass - bells, clangs and robot tones";
declare author "GRAME (os.osc)";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/oscillators.lib os.osc";
declare category "guitar";
declare family "mod";
import("stdfaust.lib");

freq = hslider("[0] Carrier[unit:Hz][scale:log]", 220, 20, 4000, 0.1) : si.smoo;
mix  = hslider("[1] Mix", 0.7, 0, 1, 0.01) : si.smoo;
tone = hslider("[2] Tone[unit:Hz][scale:log]", 6000, 800, 16000, 1) : si.smoo;
process = _ <: *(1-mix), (*(os.osc(freq)) : *(mix)) :> fi.lowpass(1, tone);
