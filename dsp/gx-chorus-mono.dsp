// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/chorus_mono.dsp (GPL-2.0-or-later).
declare license "GPL-2.0-or-later";
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision
declare name "Chorus Mono";
declare category "Modulation";

declare author "Albert Graef";
declare version "1.0";

import("stdfaust.lib");

level	= hslider("level", 0.5, 0, 1, 0.01);
freq	= hslider("freq", 2, 0, 10, 0.01);
dtime	= 0.02 ;//hslider("de.delay", 0.02, 0, 0.2, 0.01);

depth	= 0.02 ;//hslider("depth", 0.02, 0, 1, 0.01);
wet = vslider("wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]",  100, 0, 100, 1) : /(100);
dry = 1 - wet;

process			= _<:*(dry),(*(wet): component("gx-chorus.dsp").chorus(dtime,freq,depth,0)):>_;
