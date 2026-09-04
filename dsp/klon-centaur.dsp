declare name "KlonCentaur";
declare description "Klon Centaur overdrive: full wave-digital-filter circuit model (ve.klonCentaur, port of ChowCentaur)";
declare author "Chameleon DSP (wrapper) / Jatin Chowdhury (model)";
declare license "BSD-3-Clause";
import("stdfaust.lib");

gain   = hslider("Gain", 0.55, 0, 1.0, 0.01) : si.smoo;
treble = hslider("Treble", 0.5, 0, 1.0, 0.01) : si.smoo;
level  = hslider("Level", 0.7, 0, 1.0, 0.01) : si.smoo;

// The model expects a guitar-level signal (~0.1-0.5 peak) and runs the real
// gain-pot / diode-clipper / tone network as a WDF tree.
process = ve.klonCentaur(gain, treble, level);
