declare name "BeatRepeater";
declare description "Buffer stutter: plays each captured slice N times before grabbing a new one";
declare author "Chameleon DSP";
import("stdfaust.lib");

slice = hslider("Slice Size[unit:ms]", 125, 25, 500, 5) * 0.001;
reps  = hslider("Repeats", 4, 1, 8, 1);
mix   = hslider("Dry/Wet", 0.8, 0, 1.0, 0.01) : si.smoo;

MAXDEL = 262144;
W    = slice * ma.SR : int : max(256);
ph   = ba.period(W);
trig = ph < ph';
// which repeat are we on (0 = live audio, 1..reps-1 = repeats)
n    = (+(trig) : %(int(reps))) ~ _;
d    = n * W : min(MAXDEL - 4);
// short fade at slice edges hides the jump
fade = 96;
g    = min(1, min(ph / fade, (W - ph) / fade));

stutter(x) = de.delay(MAXDEL, d, x) * g;
process(x) = x * (1 - mix) + stutter(x) * mix;
