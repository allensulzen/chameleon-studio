// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tube.dsp (GPL-2.0-or-later).
declare license "GPL-2.0-or-later";
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision

import("stdfaust.lib");
import("guitarix.lib");

fuzzy = vslider("fuzzy[name:ba.count]", 1, -3, 10, 1);
process = fuzzy_tube(a,b,c,fuzzy)
with {
  a = 2;
  b = 1;
  c = 0.5;
};
