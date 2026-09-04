declare name "SpringReverb";
declare description "Dispersive spring tank model: allpass chirp chain + twin springs";
declare author "Chameleon DSP";
import("stdfaust.lib");

dwell = hslider("Dwell", 0.6, 0, 1.0, 0.01) : si.smoo;
tone  = hslider("Tone[unit:Hz]", 3200, 800, 7000, 50) : si.smoo;
mix   = hslider("Mix", 0.45, 0, 1.0, 0.01) : si.smoo;

// drive into the transducer
drive(x) = ma.tanh(x * (1 + dwell * 3)) / (1 + dwell * 1.2);
pre = fi.highpass(1, 220) : drive;

// dispersion: a chain of allpass sections smears transients into the "boing"
chirp = seq(i, 10, fi.allpass_comb(128, 23 + i * 5, 0.62));

// two springs of different length, each a lowpassed feedback loop
spring(len, g) = (+ : de.delay(8192, len)) ~ (*(g) : fi.lowpass(1, 2600));
fbk = 0.82 + dwell * 0.13;
tank = _ <: spring(2103, fbk), spring(3379, fbk * 0.95) :> *(0.5);

wet = pre : chirp : tank : fi.lowpass(2, tone) : fi.highpass(1, 150);
process = _ <: *(1 - mix), (wet : *(mix * 1.1)) :> _;
