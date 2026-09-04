declare name "WavefolderDirt";
declare description "Sine wavefolder with symmetry offset and DC restoration";
declare author "Chameleon DSP";
import("stdfaust.lib");

folds = hslider("Fold Depth", 4.0, 1, 10, 0.1) : si.smoo;
sym   = hslider("Symmetry", 0, -0.5, 0.5, 0.01) : si.smoo;
mix   = hslider("Mix", 0.75, 0, 1.0, 0.01) : si.smoo;

fold(x) = sin((x * folds + sym) * ma.PI * 0.5);
wet = fold : fi.dcblocker : fi.lowpass(1, 12000) : *(0.55);

process(x) = x * (1 - mix) + wet(x) * mix;
