declare name "Moorer Reverb";
declare description "James Moorer's 1979 reverb: 18-tap early reflections into 6 lowpass-feedback combs - classic natural-sounding room";
declare author "Luca Spanedda";
declare license "MIT";
declare source "LucaSpanedda/Digital_Reverberation_in_Faust src/reverberation.lib moorerReverb";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

mix = hslider("[0] Mix", 0.35, 0, 1, 0.01) : si.smoo;
size = hslider("[1] Comb Feedback", 0.7, 0.3, 0.9, 0.01) : si.smoo;
damp = hslider("[2] Damping", 0.4, 0, 0.9, 0.01) : si.smoo;

sasamps(t) = int(ma.SR * t);
lbcf(t, fb, dmp) = (+ : @ (max(0, (t - 1)))) ~ (_ * (1 - dmp) : + ~ * (dmp) : * (fb)) : mem;
moorerReverb = _ * 0.1 : earlyReflections <: combSection + _
with{
    earlyReflections = _ <: (_ @ sasamps(0.0043)) * 0.841, (_ @ sasamps(0.0215)) * 0.504, (_ @ sasamps(0.0225)) * 0.491, (_ @ sasamps(0.0268)) * 0.379,
        (_ @ sasamps(0.0270)) * 0.380, (_ @ sasamps(0.0298)) * 0.346, (_ @ sasamps(0.0458)) * 0.289, (_ @ sasamps(0.0485)) * 0.272,
        (_ @ sasamps(0.0572)) * 0.192, (_ @ sasamps(0.0587)) * 0.193, (_ @ sasamps(0.0595)) * 0.217, (_ @ sasamps(0.0612)) * 0.181,
        (_ @ sasamps(0.0707)) * 0.180, (_ @ sasamps(0.0708)) * 0.181, (_ @ sasamps(0.0726)) * 0.176, (_ @ sasamps(0.0741)) * 0.142,
        (_ @ sasamps(0.0753)) * 0.167, (_ @ sasamps(0.0797)) * 0.134 :> _;
    combSection = _ <: lbcf(sasamps(0.050), size, damp), lbcf(sasamps(0.056), size, damp), lbcf(sasamps(0.061), size, damp),
        lbcf(sasamps(0.068), size, damp), lbcf(sasamps(0.072), size, damp), lbcf(sasamps(0.078), size, damp) :> _ * 0.3;
};
process = _ <: *(1-mix), (moorerReverb : *(3) : *(mix)) :> _;
