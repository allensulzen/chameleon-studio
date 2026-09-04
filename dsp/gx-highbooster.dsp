// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/highbooster.dsp (GPL-2.0-or-later).
declare license "GPL-2.0-or-later";
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision
declare name   "Treble boost";
declare category "Tone Control";

import("stdfaust.lib");

level = vslider("Level", 0.5, 0.0, 20, 0.5) ;
hfboost(level,fx,x) = x + (ba.db2linear(level)-1)*fi.highpass(1,fx,x);

process = hfboost(level, 1500);
