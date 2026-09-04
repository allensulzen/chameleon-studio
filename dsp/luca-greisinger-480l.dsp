declare name "Greisinger 480L";
declare description "Dattorro/Greisinger Lexicon 480L-topology plate reverb (Tom Erbe's design): modulated allpass loops with cross-coupled tanks, mono wrap";
declare author "Luca Spanedda";
declare license "MIT";
declare source "LucaSpanedda/Digital_Reverberation_in_Faust src/reverberation.lib greisingerReverb";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

decay = hslider("[0] Decay", 0.7, 0, 0.95, 0.01) : si.smoo;
damp  = hslider("[1] Damping", 0.4, 0, 0.9, 0.01) : si.smoo;
mix   = hslider("[2] Mix", 0.35, 0, 1, 0.01) : si.smoo;

msasamps(t) = max(2, int((ma.SR / 1000) * t));
op(b1) = _ * (1 - abs(b1)) : + ~ * (b1);
apf(t, g) = _ : (+ : _ <: @ (t  - 1), * (- g)) ~ * (g) : mem, _ : + : _;
delaymod(mod, t, tMod) = de.fdelay(tMax, modIndx) with { tMax = t + tMod; modIndx = t + (mod * tMod); };
apfMod(mod, t, tMod, g) = _ : (+ : _ <: delaymod(mod, t - 1, tMod), * (- g)) ~ * (g) : mem, _ : + : _;
greisingerReverb(decay, damp) = (si.bus(2) :> _ * (1 / 2) : predelay : op(damp) : apfsec) <: si.bus(2) : (ro.interleave(2, 2) : (par(i, 2, (_, _) :> + : loopsec(i)) : ro.crossNM(4, 1), si.bus(3))) ~ si.bus(2) : (si.block(2), si.bus(6)) : routing
with{
    predelay = _ @ msasamps(30);
    apfsec = apf(msasamps(4.771), 0.75) : apf(msasamps(3.595), 0.75) : apf(msasamps(12.73), 0.625) : apf(msasamps(9.307), 0.625);
    loopsec(0) = apfMod(os.osc(0.10), msasamps(30.51), msasamps(4), 0.7) : _ @ msasamps(141.69) : (_ <: _, _) : (op(damp), _) :
        (apf(msasamps(89.24), 0.5) <: _, _), _ : (_ @ (msasamps(106.28) - 1) <: _, mem), _, _ : (_ * decay, _, _, _) : (_, ro.cross(3));
    loopsec(1) = apfMod(os.osc(0.07), msasamps(22.58), msasamps(4), 0.7) : _ @ msasamps(149.62) : (_ <: _, _) : (op(damp), _) :
        (apf(msasamps(60.48), 0.5) <: _, _), _ : (_ @ (msasamps(125.00) - 1) <: _, mem), _, _ : (_ * decay, _, _, _) : (_, ro.cross(3));
    routing(dA0, ap0, dB0, dA1, ap1, dB1) =
        ((dA0 @ msasamps(8.90), dA0 @ msasamps(99.8), ap0 @ msasamps(64.2), dB0 @ msasamps(67), dA1 @ msasamps(66.8), ap1 @ msasamps(6.3), dB1 @ msasamps(35.8), 0) :> +),
        ((dA0 @ msasamps(70.8), ap0 @ msasamps(11.2), dB0 @ msasamps(4.1), dA1 @ msasamps(11.8), dA1 @ msasamps(121.7), ap1 @ msasamps(41.2), dB1 @ msasamps(89.7), 0) :> +);
};
wet = _ <: greisingerReverb(decay, damp) :> *(0.5);
process = _ <: *(1-mix), (wet : *(mix)) :> _;
