// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_peavey.dsp (GPL-2.0-or-later).
declare license "GPL-2.0-or-later";
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision
declare id "Peavey"; // in tonestack ba.selector
declare name "Peavey";

tstack = component("gx-tonestack.dsp");
process = tstack[tse=tstack.ts.peavey;];
