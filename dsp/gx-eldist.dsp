// PORTED by tools/port/gx-port.py from guitarix src/plugins/eldist.dsp (GPL-2.0-or-later).
declare license "GPL-2.0-or-later";
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision
// generated automatically
// DO NOT MODIFY!
declare id "eldist";
declare name "Electra Distortion";
declare category "Distortion";
declare shortname "Electra Dst";
declare description "Electra Distortion";
declare samplerate "96000";

import("stdfaust.lib");

gxc = library("clipping.lib");

process = pre : fi.iir((b0/a0,b1/a0),(a1/a0)) : clip with {
    LogPot(a, x) = ba.if(a, (exp(a * x) - 1) / (exp(a) - 1), x);
    Inverted(b, x) = ba.if(b, 1 - x, x);
    s = 0.993;
    fs = float(ma.SR);
    pre = _;
    //clip(x) = (min(0.4514,max(-0.4514,x)));
asymclip = gxc.asymclip;
    clip = (_ : asymclip);

    
        Drive = vslider("Drive[name:Drive]", 0.5, 0, 1, 0.01) : Inverted(0) : si.smooth(s);
    
    b0 = -8.14686408743197e-8*Drive*fs - 0.00018716364572377*fs;

    b1 = 8.14686408743197e-8*Drive*fs + 0.00018716364572377*fs;

    a0 = Drive*(-3.9949101411109e-5*fs - 8.66687668918243e-5) + 4.07955525542246e-5*fs + 0.000635245647283505;

    a1 = Drive*(3.9949101411109e-5*fs - 8.66687668918243e-5) - 4.07955525542246e-5*fs + 0.000635245647283505;
};
