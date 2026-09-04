declare name "Tape Stop";
declare description "David Braun's tape-stop: engage Stop and playback decelerates to a halt with adjustable curve";
declare author "David Braun";
declare license "LicenseRef-STK-4.3";
declare source "grame-cncm/faustlibraries/misceffects.lib ef.tapeStop";
declare category "guitar";
declare family "pitch";
import("stdfaust.lib");

stop      = checkbox("[0] Stop");
stopTime  = hslider("[1] Stop Time[unit:ms]", 600, 10, 4000, 1) : *(ma.SR/1000);
stopAlpha = hslider("[2] Stop Curve", 1, 0.01, 2, 0.01);
gainAlpha = hslider("[3] Gain Curve", 1, 0.01, 2, 0.01);
xfade     = hslider("[4] Crossfade[unit:ms]", 3, 0, 125, 1) : *(ma.SR/1000);
MAXS = 4 * 48000;
process = ef.tapeStop(1, 3, MAXS, xfade, gainAlpha, stopAlpha, stopTime, stop);
