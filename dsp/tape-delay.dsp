declare name "TapeDelay";
declare description "Tape echo: wow/flutter, saturated repeats, dark feedback path";
declare author "Chameleon DSP";
import("stdfaust.lib");

time = hslider("Time[unit:ms]", 420, 20, 1200, 1) * 0.001 : si.smooth(ba.tau2pole(0.12));
fb   = hslider("Feedback", 0.5, 0, 1.0, 0.01) : si.smoo;
mix  = hslider("Mix", 0.45, 0, 1.0, 0.01) : si.smoo;

MAXDEL = 65536;
// slow wow + fast flutter, as a fraction of the delay time
wow   = os.osc(0.55) * 0.0025 + os.osc(6.3) * 0.0004;
dt    = time * (1 + wow) * ma.SR : min(MAXDEL - 4);

// tape head + electronics colouration in the repeat path
head  = fi.lowpass(1, 3400) : fi.highpass(1, 110);
sat(x) = ma.tanh(x * 1.4) / 1.4;

// >~87% on the knob pushes the loop into (tanh-bounded) self-oscillation, like a real tape echo
echo  = (+ : sat : de.fdelay(MAXDEL, dt)) ~ (head : *(fb * 1.15));
process = _ <: *(1 - mix), (echo : *(mix)) :> _;
