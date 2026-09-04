declare name "LoFiBitcrusher";
declare description "Sample-rate decimation and bit-depth reduction";
declare author "Chameleon DSP";
import("stdfaust.lib");

sr_target = hslider("Sample Rate[unit:Hz]", 8000, 500, 44100, 100) : si.smoo;
bits      = hslider("Bit Depth", 6, 2, 16, 1);
mix       = hslider("Mix", 0.7, 0, 1.0, 0.01) : si.smoo;

// sample & hold clocked at the target rate
ph      = os.lf_sawpos(sr_target);
trig    = ph < ph';
levels  = pow(2, bits - 1);
quant(x) = floor(x * levels + 0.5) / levels;
crush   = ba.sAndH(trig) : quant;

process(x) = x * (1 - mix) + crush(x) * mix;
