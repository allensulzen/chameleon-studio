declare name "KPP Blue Dream";
declare description "Booster/overdrive with voice knob (booster left, tube-screamer right), push-pull tube waveshaper and 3-band EQ";
declare author "Oleg Kapitonov";
declare license "GPL-3.0-or-later";
declare source "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_bluedream/kpp_bluedream.dsp";
declare category "guitar";
declare family "dirt";
import("stdfaust.lib");

drive  = hslider("[0] Drive", 63, 0, 100, 0.01) : si.smoo;
voice  = hslider("[1] Voice", 0.5, 0, 1, 0.001) : si.smoo;
bass   = hslider("[2] Bass[unit:dB]", 0, -15, 15, 0.1) : si.smoo;
middle = hslider("[3] Middle[unit:dB]", 0, -15, 15, 0.1) : si.smoo;
treble = hslider("[4] Treble[unit:dB]", 0, -15, 15, 0.1) : si.smoo;
volume = hslider("[5] Volume", 0.8, 0, 1, 0.001) : si.smoo;

clamp = min(2.0) : max(-2.0);
bias = 0.2; Upor = 0.2; Kreg = 1.0;
tube(Kreg,Upor,bias,cut) = main : +(bias) : max(cut) with {
    Ks(x) = 1/(max((x-Upor)*(Kreg),0)+1);
    Ksplus(x) = Upor - x*Upor;
    main(Uin) = (Uin * Ks(Uin) + Ksplus(Ks(Uin)));
};
pre_filter = _ <: fi.highpass(1, 720) * min((1 - voice + 0.75 * drive / 100), 1), *(max((voice - 0.75 * drive / 100), 0)) : +;
post_filter = _ <: fi.lowpass(1, 720) * min((1 - voice + 0.75 * drive / 100), 1), *(max((voice - 0.75 * drive / 100), 0)) : +;
stage_stomp = pre_filter : fi.lowpass(1,9000) : _ <: _,*(-1.0) : tube(Kreg,Upor,bias,0), tube(Kreg,Upor,bias,0) : - :
    *(ba.db2linear(volume * 50.0 * (1 - voice * 0.25)) / 100.0) :
    fi.peak_eq(bass, 70, 200) : fi.peak_eq(middle, 500, 700) : fi.peak_eq(treble, 10000, 18000) : clamp : post_filter;
process = fi.dcblocker : clamp : *(ba.db2linear(drive * 0.4 * (1 - voice * 0.5))-1) : stage_stomp : fi.dcblocker;
