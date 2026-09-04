declare name "Chamberlin Reverb";
declare description "Hal Chamberlin's 1979 all-allpass reverberator (3 series + 2x2 output allpasses) with T60 decay control - vintage chip-reverb smear";
declare author "Luca Spanedda";
declare license "MIT";
declare source "LucaSpanedda/Digital_Reverberation_in_Faust src/reverberation.lib chamberlinDecay";
declare category "guitar";
declare family "reverb";
import("stdfaust.lib");

t60 = hslider("[0] Decay[unit:s]", 3, 0.2, 15, 0.1);
mix = hslider("[1] Mix", 0.35, 0, 1, 0.01) : si.smoo;

msasamps(t) = max(2, int((ma.SR / 1000) * t));
t60_ms(ms, tt) = pow(0.001, (ms / 1000) / tt);
apf(t, g) = _ : (+ : _ <: @ (t  - 1), * (- g)) ~ * (g) : mem, _ : + : _;
chamberlinDecay(seconds) = ap3ch <: apout1ch, apout2ch
with{
    ap3ch = apf(msasamps(49.6), t60_ms(49.6, seconds)) : apf(msasamps(34.75), t60_ms(34.75, seconds)) : apf(msasamps(24.18), t60_ms(24.18, seconds));
    apout1ch = apf(msasamps(17.85), t60_ms(17.85, seconds)) : apf(msasamps(10.98), t60_ms(10.98, seconds));
    apout2ch = apf(msasamps(18.01), t60_ms(18.01, seconds)) : apf(msasamps(10.82), t60_ms(10.82, seconds));
};
wet = chamberlinDecay(t60) :> *(0.5);
process = _ <: *(1-mix), (wet : *(mix)) :> _;
