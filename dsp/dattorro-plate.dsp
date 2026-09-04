declare name "DattorroPlate";
declare description "Dattorro figure-eight plate reverb (true Dattorro tank topology)";
declare author "Chameleon DSP";
import("stdfaust.lib");

decay = hslider("Decay", 0.6, 0, 1.0, 0.01) : si.smoo;
tone  = hslider("Tone", 0.65, 0, 1.0, 0.01) : si.smoo;
mix   = hslider("Mix", 0.4, 0, 1.0, 0.01) : si.smoo;

// map knobs to Dattorro coefficients
dec   = 0.5 + decay * 0.48;         // 0.5 .. 0.98 tank feedback
damp  = 0.02 + (1 - tone) * 0.85;   // higher = darker tail
bw    = 0.4 + tone * 0.59;          // input bandwidth

plate = re.dattorro_rev(480, bw, 0.75, 0.625, dec, 0.7, 0.5, damp);
wet   = fi.highpass(1, 90) <: plate :> *(0.5);
process = _ <: *(1 - mix), (wet : *(mix)) :> _;
