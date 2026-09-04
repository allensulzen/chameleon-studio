declare name "Rotary Speakers";
declare description "Leslie-style rotary: two counter-modulated delay lines with amplitude modulation and horn/drum coloration, summed to mono";
declare author "thedrgreenthumb (Sergey Konstantinov)";
declare license "MIT";
declare source "thedrgreenthumb/faust rotary_speakers.dsp";
declare category "guitar";
declare family "mod";
import("stdfaust.lib");

speed      = hslider("[0] Speed[unit:Hz]", 6, 0.5, 12, 0.1) : si.smoo;
depth      = hslider("[1] Depth[unit:samples]", 50, 10, 200, 1) : si.smoo;
coloration = hslider("[2] Coloration", 0, -1, 1, 0.05) : si.smoo;
dry_wet    = hslider("[3] Dry/Wet", 1, 0, 1, 0.05) : si.smoo;

coloration_filter(col) = _ <: (fi.lowshelf(5,(1 - col)*12,440), fi.highshelf(5,col*12,880)) :> _*ba.db2linear(-15);
lfo = os.osc(speed);
rot = _ <: (de.fdelay(500, depth*(lfo+1)*0.5 + 1)*(1-lfo)), (de.fdelay(500, depth*(lfo+1)*0.5 + 1)*(1+lfo)) : coloration_filter(coloration), coloration_filter(coloration) :> *(2);
process = _ <: *(1-dry_wet), (rot : *(dry_wet)) :> _;
