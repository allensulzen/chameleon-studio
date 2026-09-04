declare name "Spin ROM Reverb";
declare description "Keith Barr's Spin Semiconductor rom_rev1 allpass-loop reverb - classic FV-1 pedal tail";
declare author "Luca Spanedda (Faust port), Keith Barr";
declare license "GPL-3.0-only";
declare source "grame-cncm/faustlibraries/reverbs.lib re.kb_rom_rev1";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

rt   = hslider("[0] Reverb Time", 0.6, 0, 0.95, 0.001) : si.smoo;
damp = hslider("[1] Damping", 0.3, 0, 0.99, 0.001) : si.smoo;
mix  = hslider("[2] Mix", 0.4, 0, 1, 0.01) : si.smoo;

wet = _ <: re.kb_rom_rev1(rt, damp) :> *(0.5);
process = _ <: *(1-mix), (wet : *(mix)) :> _;
