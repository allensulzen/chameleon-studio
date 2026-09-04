// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_roland.dsp (GPL-2.0-or-later).
declare license "GPL-2.0-or-later";
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision
declare id "Roland"; // in tonestack ba.selector
declare name "Roland";

tstack = component("gx-tonestack.dsp");
process = tstack[tse=tstack.ts.roland;];
