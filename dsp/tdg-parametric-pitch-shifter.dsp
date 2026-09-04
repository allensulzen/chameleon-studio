declare name "Parametric Pitch Shifter";
declare description "Pitch shifter whose shift amount is driven by a blend of envelope follower and LFO - auto-bends, warbles and touch-octaves";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust parametric_pitch_shifter.dsp";
declare category "guitar";
declare family "pitch";
import("stdfaust.lib");

envelope = hslider("[0] Envelope[unit:s]", 1, 0.1, 3, 0.05);
speed    = hslider("[1] LFO Speed[unit:Hz]", 0.5, 0.1, 10, 0.05) : si.smoo;
depth    = hslider("[2] Depth", 0.5, 0, 1, 0.05) : si.smoo;
ctrl     = hslider("[3] Env/LFO", 0.5, 0, 1, 0.05) : si.smoo;
shift    = hslider("[4] Shift[unit:semi]", 2, -6, 6, 0.1) : si.smoo : *(2);
dry_wet  = hslider("[5] Dry/Wet", 0.5, 0, 1, 0.05) : si.smoo;

mixer(mix) = _*(1 - mix), _*mix :> _;
c_folower_colibration = 6;
parametric_controller(mix, envelope_t, freq, dep) = (an.amp_follower(envelope_t) : _*c_folower_colibration : _*dep, os.osc(freq)*0.5 : _, _*dep) : mixer(mix) : _+0.5;
process = _ <: _, (_ <: parametric_controller(ctrl, envelope, speed, depth)*shift, _ : ef.transpose(2048, 1024)) : mixer(dry_wet);
