declare name "Pitch Shifter";
declare description "Grame's classic dual-delay crossfade pitch shifter, octave down to octave up with mix";
declare author "Grame";
declare license "BSD-3-Clause";
declare source "grame-cncm/faust/examples/pitchShifting/pitchShifter.dsp ef.transpose";
declare category "guitar";
declare family "pitch";
import("stdfaust.lib");

shift = hslider("[0] Shift[unit:semi]", 12, -24, 24, 0.1) : si.smoo;
win   = hslider("[1] Window[unit:samples]", 1000, 200, 4000, 1);
xfade = hslider("[2] Crossfade[unit:samples]", 200, 10, 2000, 1);
mix   = hslider("[3] Mix", 0.5, 0, 1, 0.01) : si.smoo;
process = _ <: *(1-mix), (ef.transpose(win, min(win, xfade), shift) : *(mix)) :> _;
