declare name "PitchOctaver";
declare description "Polyphonic sub-octave and upper-octave blend";
declare author "Chameleon DSP";
import("stdfaust.lib");

sub_vol = hslider("Sub", 0.5, 0, 1.0, 0.01) : si.smoo;
up_vol  = hslider("Up", 0.4, 0, 1.0, 0.01) : si.smoo;
dry_vol = hslider("Dry", 0.7, 0, 1.0, 0.01) : si.smoo;

// ef.transpose(window, crossfade, semitones)
sub = ef.transpose(2048, 512, -12) : fi.lowpass(2, 1800);
up  = ef.transpose(1024, 256, 12) : fi.highpass(1, 160);

process = _ <: *(dry_vol), (sub : *(sub_vol * 0.7)), (up : *(up_vol * 0.6)) :> _;
