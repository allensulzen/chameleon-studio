// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/moog.dsp (GPL-2.0-or-later).
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision
declare id      "moog";
declare name    "Moog Filter";
declare category "Tone Control";
declare license "BSD";

import("stdfaust.lib");
import("guitarix.lib");

Q 		= hslider("Q", 1, 0, 4, 0.1);
fr 		= hslider("fr", 3000, 440, 6000, 10): smoothi(0.999);

process_wide = ( +(anti_denormal_ac): moogvcfN(Q,fr)), (+(anti_denormal_ac): moogvcfN(Q,fr));

// mono wrapper added by the Chameleon port (pedal is mono in / mono out)
process = _ <: process_wide :> *(0.5);
