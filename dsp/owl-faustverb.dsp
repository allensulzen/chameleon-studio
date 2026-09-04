declare name "FaustVerb";
declare description "GRAME's primitive-level Freeverb (8 combs, 4 allpasses) as shipped on the OWL pedal";
declare author "GRAME, OWL wrapper Rebel Technology";
declare license "BSD-3-Clause";
declare source "pingdynasty/OwlPatches Faust/FaustVerb.dsp";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

fixedgain = 0.015; scaledamp = 0.4; scaleroom = 0.28; offsetroom = 0.7; allpassfeed = 0.5;
roomsize = hslider("[0] Room Size", 0.5, 0, 1, 0.01) : si.smoo : *(scaleroom) : +(offsetroom);
damp     = hslider("[1] Damp", 0.5, 0, 1, 0.01) : si.smoo : *(scaledamp);
wet      = hslider("[2] Dry/Wet", 0.3333, 0, 1, 0.01) : si.smoo;

allpass(dt,fb) = (_,_ <: (*(fb),_:+:@(dt)), -) ~ _ : (!,_);
comb(dt, fb, dmp) = (+:@(dt)) ~ (*(1-dmp) : (+ ~ *(dmp)) : *(fb));
monoReverb(fb1, fb2, dmp) = _ <: comb(1116,fb1,dmp), comb(1188,fb1,dmp), comb(1277,fb1,dmp), comb(1356,fb1,dmp),
    comb(1422,fb1,dmp), comb(1491,fb1,dmp), comb(1557,fb1,dmp), comb(1617,fb1,dmp)
    +> allpass(556,fb2) : allpass(441,fb2) : allpass(341,fb2) : allpass(225,fb2);
process = _ <: (*(fixedgain) : monoReverb(roomsize, allpassfeed, damp) : *(wet)), *(1-wet) :> _;
