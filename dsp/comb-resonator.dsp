declare name "CombResonator";
declare description "Tuned feedback comb that rings drum hits at a musical pitch";
declare author "Chameleon DSP";
import("stdfaust.lib");

f     = hslider("Tuned Pitch[unit:Hz]", 130, 50, 800, 1) : si.smoo;
decay = hslider("Ring Decay", 0.92, 0.5, 0.99, 0.01) : si.smoo;
mix   = hslider("Dry/Wet", 0.5, 0, 1.0, 0.01) : si.smoo;

MAXDEL = 2048;
del  = ma.SR / f : min(MAXDEL - 4);
// positive feedback => resonates at f and its harmonics; lowpass tames the top
comb = (+ : de.fdelay(MAXDEL, del)) ~ (*(decay) : fi.lowpass(1, 6000));
wet  = comb : *(1 - decay * 0.7) : ma.tanh;

process(x) = x * (1 - mix) + wet(x) * mix;
