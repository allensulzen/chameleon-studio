declare name "Barabas Tube Screamer";
declare description "Minimal TS-style overdrive: 720 Hz input highpass, cubic soft clip, sweepable 1-pole tone (350-4500 Hz), volume";
declare author "Barabas Raffai";
declare license "GPL-3.0-or-later";
declare source "Barabas5532/TubeScreamer tubescreamer.dsp";
declare category "guitar";
declare family "dirt";
import("stdfaust.lib");

gain   = hslider("[0] Gain", 0.5, 0, 1, 0.01) : si.smoo;
tone   = hslider("[1] Tone", 0.5, 0, 1, 0.01) : si.smoo;
volume = hslider("[2] Volume", 0.7, 0, 1, 0.01) : si.smoo;
input_filter = fi.highpass(1, 720);
clipping = ef.cubicnl(gain, 0);
post_filter = fi.lowpass(1, 350 + (tone * (4500 - 350)));
volume_control = ba.db2linear((volume - 1) * 40);
process = input_filter : clipping : post_filter * volume_control;
