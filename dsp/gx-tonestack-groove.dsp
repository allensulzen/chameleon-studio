// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/tonestack_groove.dsp (GPL-2.0-or-later).
declare license "GPL-2.0-or-later";
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision
declare id "Trio Preamp"; // in tonestack ba.selector
declare name "Trio Preamp";

tstack = component("gx-tonestack.dsp");
process = tstack[tse=tstack.ts.groove;];
