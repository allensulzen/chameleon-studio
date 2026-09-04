// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/echo.dsp (GPL-2.0-or-later).
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision
declare name "Echo";
declare category "Echo / Delay";

declare version 	"0.01";
declare author 		"brummer";
declare license 	"BSD";
declare copyright 	"(c)brummer 2008";

import("stdfaust.lib");

t = vslider("time", 1, 1, 2000, 1);
release = vslider("percent", 0, 0,  100, 0.1);

echo1  = +~(de.delay(131072,   int(t*ba.millisec)-1) * (release/100.0));
process = echo1;
