declare name "Sweep Wah";
declare description "CryBaby wah swept by an LFO between two pedal positions, with dry/wet";
declare author "Rebel Technology / OWL (JOS crybaby)";
declare license "GPL-2.0";
declare source "pingdynasty/OwlPatches Faust/SweepWah.dsp";
declare category "guitar";
declare family "filter";
import("stdfaust.lib");

freq = hslider("[0] Rate[unit:Hz]", 2, 0.05, 12, 0.001) : si.smoo;
lo   = hslider("[1] Low", 0.2, 0, 1, 0.01) : si.smoo;
hi   = hslider("[2] High", 0.8, 0, 1, 0.01) : si.smoo;
wet  = hslider("[3] Dry/Wet", 0.8, 0, 1, 0.01) : si.smoo;

lfo = os.oscrs(freq) + 1.0 : *(0.5);
wah = lo*lfo + hi*(1.0-lfo);
process = _ <: (ve.crybaby(wah) : *(wet)), *(1-wet) :> _;
