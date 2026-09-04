// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/overdrive.dsp (GPL-2.0-or-later).
declare license "GPL-2.0-or-later";
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision
declare name "Overdrive";
declare category "Distortion";

import("stdfaust.lib");
import("guitarix.lib");

drive = vslider("drive", 1, 1, 20, 0.1);
f = drive * -0.5 : ba.db2linear : smoothi(0.999);

wet = vslider("wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]",  100, 0, 100, 1) : /(100);
dry = 1 - wet;

overdrive(x) = (x*(abs(x) + drive)/(x*x + (drive-1)*abs(x) + 1)) * f;

process =  _<:*(dry),(*(wet) : overdrive):>_;
