declare name "MultiStagePhaser";
declare description "Six-notch all-pass phaser with resonant feedback (Phase 90 to Small Stone)";
declare author "Chameleon DSP";
import("stdfaust.lib");

rate  = hslider("Rate[unit:Hz]", 1.5, 0.1, 8.0, 0.05) : si.smoo;
depth = hslider("Depth", 0.75, 0, 1.0, 0.01) : si.smoo;
fb    = hslider("Feedback", 0.55, 0, 0.9, 0.01) : si.smoo;

// phaser2_mono(Notches, phase01, width, frqmin, fratio, frqmax, speed, depth, fb, invert)
process = pf.phaser2_mono(3, 0, 1000, 120, 1.5, 3200, rate, depth, fb, 0) : ma.tanh;
