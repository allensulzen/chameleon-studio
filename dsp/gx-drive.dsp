// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/drive.dsp (GPL-2.0-or-later).
declare license "GPL-2.0-or-later";
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision

import("stdfaust.lib");
import("guitarix.lib");

fuzzy = vslider("value[name:drive]", 1, 1, 10, 1);
process = fuzzy_tube(a,b,c,fuzzy)
with {
  a = 4;
  b = 4;
  c = 0.125;
};
