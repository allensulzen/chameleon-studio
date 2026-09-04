declare name "ResonantDJFilter";
declare description "One-knob DJ filter: low-pass left of centre, high-pass right of centre";
declare author "Chameleon DSP";
import("stdfaust.lib");

sweep = hslider("Filter Sweep", 0, -100, 100, 1) * 0.01 : si.smoo;
q     = hslider("Resonance", 8, 1, 20, 0.5) : si.smoo;
drive = hslider("Drive", 0.3, 0, 1.0, 0.01) : si.smoo;

// dead zone around centre so the knob has a clean "off"
dz   = 0.06;
lpa  = max(0, (0 - sweep) - dz) / (1 - dz);   // 0..1 as the knob goes left
hpa  = max(0, sweep - dz) / (1 - dz);          // 0..1 as the knob goes right
lp_f = 18000 * pow(60 / 18000, lpa);           // exponential 18k -> 60 Hz
hp_f = 20 * pow(8000 / 20, hpa);               // exponential 20 -> 8k Hz

pre(x)  = ma.tanh(x * (1 + drive * 4)) / (1 + drive * 1.5);
lp = fi.resonlp(lp_f, q, 1);
hp = fi.resonhp(hp_f, q, 1);

// resonant peaks saturate like an analog ladder rather than clipping the codec
process = pre : lp : hp : fi.lowpass(1, 19000) : ma.tanh;
