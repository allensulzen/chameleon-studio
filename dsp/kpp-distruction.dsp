declare name "KPP Distruction";
declare description "Hi-gain distortion: bandpassed pre-filter, push-pull tube clipper, 3-band EQ, voice-controlled presence";
declare author "Oleg Kapitonov";
declare license "GPL-3.0-or-later";
declare source "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_distruction/kpp_distruction.dsp";
declare category "guitar";
declare family "dirt";
import("stdfaust.lib");

drive  = hslider("[0] Drive", 63, 0, 100, 0.01) : si.smoo;
voice  = hslider("[1] Voice", 0.5, 0, 1, 0.001) : si.smoo;
bass   = hslider("[2] Bass[unit:dB]", 0, -15, 15, 0.1) : si.smoo;
middle = hslider("[3] Middle[unit:dB]", 0, -15, 15, 0.1) : si.smoo;
treble = hslider("[4] Treble[unit:dB]", 0, -15, 15, 0.1) : si.smoo;
volume = hslider("[5] Volume", 0.8, 0, 1, 0.001) : si.smoo;
level  = hslider("[6] Level[unit:dB]", 12, -12, 24, 0.1) : ba.db2linear : si.smoo;

clamp = min(2.0) : max(-2.0);
Upor = 0.2; bias = 0.2; Kreg = 1.0;
pre_filter = fi.lowpass(1, 3000) <: fi.highpass(1, 3300);
post_filter = fi.lowpass(1, 3000) : fi.highpass(1,30) : fi.peak_eq(-6, 550, 500) : fi.high_shelf(-20 + voice*20, 550);
tube(Kreg,Upor,bias,cut) = main : +(bias) : max(cut) with {
    Ks(x) = 1/(max((x-Upor)*(Kreg),0)+1);
    Ksplus(x) = Upor - x*Upor;
    main(Uin) = (Uin * Ks(Uin) + Ksplus(Ks(Uin)));
};
stage_stomp = pre_filter : _ <: _,*(-1.0) : tube(Kreg,Upor,bias,0), tube(Kreg,Upor,bias,0) : - :
    fi.peak_eq(bass, 100, 200) : fi.peak_eq(middle, 700, 700) : fi.peak_eq(treble, 3300, 2000) : post_filter : clamp;
process = fi.dcblocker : clamp : *(ba.db2linear(drive * 70.0 / 100.0)-1) : *(5) : stage_stomp : *((ba.db2linear(volume * 25.0)-1) / 100.0) : fi.dcblocker : *(level);
