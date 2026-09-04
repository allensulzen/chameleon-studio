// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_bassman.dsp (GPL-2.0-or-later).
declare license "GPL-2.0-or-later";
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision
declare id "Bassman"; // in tonestack ba.selector
declare name "Bassman";

tstack = component("gx-tonestack.dsp");
process = tstack[tse=tstack.ts.bassman;];
