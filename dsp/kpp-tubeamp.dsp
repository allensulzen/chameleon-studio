declare name "KPP Tube Amp";
declare description "Profile-driven tube amp: preamp waveshaper, 3-band tonestack, push-pull power stage with supply sag. 8 built-in profiles (American Clean/Vintage, British Crunch, Modern Metal, Classic Hard, JCM800, MarkII, Twin) baked in from the .tapf files";
declare author "Oleg Kapitonov";
declare license "GPL-3.0-or-later";
declare source "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_tubeamp/kpp_tubeamp.dsp (+ profiles/*.tapf header values)";
declare category "guitar";
declare family "amp";
import("stdfaust.lib");

profile    = nentry("[0] Profile[style:menu{'American Clean':0;'American Vintage':1;'British Crunch':2;'Modern Metal':3;'Classic Hard':4;'JCM800':5;'MarkII':6;'Twin Reverb':7}]", 2, 0, 7, 1);
drive      = hslider("[1] Drive", 100, 0, 100, 0.1) : si.smoo;
bass       = hslider("[2] Bass[unit:dB]", 0, -10, 10, 0.1) : si.smoo;
middle     = hslider("[3] Middle[unit:dB]", 0, -10, 10, 0.1) : si.smoo;
treble     = hslider("[4] Treble[unit:dB]", 0, -10, 10, 0.1) : si.smoo;
mastergain = hslider("[5] Master", 50, 0, 100, 0.1) : si.smoo;
volume     = hslider("[6] Volume", 1, 0, 1, 0.001) : si.smoo;
cabmix     = hslider("[7] Cab Sim", 1, 0, 1, 0.01) : si.smoo;

sel(l) = ba.selectn(8, profile, l);
preamp_level = sel((0.005, 0.005, 0.005, 2.0, 0.0071, 0.0795, 0.1155, 0.005));
preamp_bias  = 0.0;
preamp_Kreg  = sel((0.8, 0.8, 0.8, 2.0, 0.8, 0.8, 6.57, 0.8));
preamp_Upor  = sel((0.8, 0.8, 0.8, 0.2, 0.8, 0.8, 0.39, 0.8));
amp_level    = sel((0.2, 0.25, 1.5, 0.06, 10.0, 0.7925, 0.1811, 0.5909));
amp_bias     = 0.2;
amp_Kreg     = sel((0.5, 0.7, 0.7, 1.0, 0.7, 0.7, 1.0, 0.7));
amp_Upor     = sel((0.2, 0.2, 0.2, 0.5, 0.2, 0.2, 0.5, 0.2));
sag_time     = sel((0.3, 0.3, 0.3, 0.1, 0.3, 0.3, 0.1, 0.3));
sag_coeff    = sel((0.0, 5.0, 0.5, 0.0, 0.5, 0.5, 0.0, 0.68));
output_level = sel((0.3125, 0.5, 0.1333, 0.2, 0.06, 0.13, 0.33, 0.18));
ts_low_freq = 20; ts_low_band = 400; ts_mid_freq = 500; ts_mid_band = 400; ts_high_freq = 10000; ts_high_band = 18000;

tube(Kreg,Upor,bias,cut) = main : +(bias) : max(cut) with {
    Ks(x) = 1/(max((x-Upor)*(Kreg),0)+1);
    Ksplus(x) = Upor - x*Upor;
    main(Uin) = (Uin * Ks(Uin) + Ksplus(Ks(Uin)));
};
stage_preamp = fi.lowpass(1,11000) : tube(preamp_Kreg,preamp_Upor,preamp_bias,-preamp_Upor);
stage_tonestack = fi.peak_eq(bass,ts_low_freq,ts_low_band) : fi.peak_eq(middle,ts_mid_freq,ts_mid_band) : fi.peak_eq(treble,ts_high_freq,ts_high_band) : fi.lowpass(1,11000);
stage_amp = _ <: _,*(-1.0) : tube(amp_Kreg,amp_Upor,amp_bias,0), tube(amp_Kreg,amp_Upor,amp_bias,0) : - : fi.lowpass(1, 11000);
pre_sag = fi.dcblocker : *(ba.db2linear(drive * 0.4) - 1) : *(preamp_level) : stage_preamp : fi.dcblocker : *(amp_level) : *(ba.db2linear(mastergain * 0.4) - 1) : stage_tonestack;
sag = (_,_ : (_ <: (1.0/_),_),_ : _,* : _,stage_amp : *) ~ (_ <: _,_ : * : fi.lowpass(1,sag_time) : *(sag_coeff) : max(1.0) : min(2.5));
// simple stand-in for the profile's 100 ms cabinet IR (not embedded)
cab = _ <: *(1-cabmix), (*(cabmix) : fi.highpass(2, 90) : fi.peak_eq(4, 2500, 1500) : fi.lowpass(3, 5200)) :> _;
process = pre_sag : sag : *(volume) : *(output_level) : fi.dcblocker : cab;
