declare name "Duck Reverb";
declare description "Freeverb ducked by an envelope follower: the tail stays out of the way while you play and blooms in the gaps";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust duck_reverb.dsp + freeverb.dspi";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

p_attack  = hslider("[0] Attack[unit:s]", 0.1, 0.05, 0.5, 0.01);
p_release = hslider("[1] Release[unit:s]", 0.3, 0.05, 2, 0.01);
p_amount  = hslider("[2] Duck Amount[unit:dB]", 18, 0, 40, 0.5) : si.smoo;
roomsize  = hslider("[3] Room Size", 0.6, 0, 1, 0.01) : si.smoo : *(0.28) : +(0.7);
damp      = hslider("[4] Damp", 0.5, 0, 1, 0.01) : si.smoo;
wet_dry   = hslider("[5] Wet/Dry", 0.5, 0, 1, 0.01) : si.smoo;

rev = re.mono_freeverb(roomsize, 0.5, damp*0.4, 23) : *(0.015);
// proportional ducking: reverb/delay level drops by up to `depth` dB as the input envelope rises
// (the original used a hard gate — env*amount > 1 — which mutes the wet path entirely while playing,
// so a 100 % wet mix went silent)
duck_gain(att, rel, depth_db, x) = ba.db2linear(0 - depth_db * min(1, an.amp_follower_ud(att, rel, x) * 4)) : si.smooth(ba.tau2pole(0.02));
process(x) = x*(1-wet_dry) + (rev(x) * duck_gain(p_attack, p_release, p_amount, x)) * wet_dry * 3;
