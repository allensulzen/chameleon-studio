// PORTED by tools/port/gx-port.py from guitarix src/LV2/faust/valve.dsp (GPL-2.0-or-later).
declare license "GPL-2.0-or-later";
declare chameleon_flags "-double";   // DK circuit sims are numerically unstable in single precision
// dsp algorithm from swh ladspa valve plugin (Steve Harrison)

import("stdfaust.lib");
import("guitarix.lib");

vt = valve.vt(dist, q) : ma.neg : valve.vt(dist, q) : ma.neg with
{
        q_p = vslider("q", 0, -1.7, 1.7, 0.01);
        dist_p = vslider("dist", 0, -2, 2, 0.01);
        q = q_p*q_p*q_p;
        dist = pow(10,dist_p);
};

vtu = valve.vt(dist, q) with
{
        q_p = vslider("q", 0, -1.7, 1.7, 0.01);
        dist_p = vslider("dist", 0, -2, 2, 0.01);
        q = q_p*q_p*q_p;
        dist = pow(10,dist_p);
};

vts(x) = abs(x) : ma.neg : valve.vt(dist, q) : ma.neg : copysign(_,x)
with
{
        q_p = vslider("q", 0, -1.7, 1.7, 0.01);
        dist_p = vslider("dist", 0, -2, 2, 0.01);
        q = q_p*q_p*q_p;
        dist = pow(10,dist_p);
copysign = ma.copysign;
};

process = vt;
