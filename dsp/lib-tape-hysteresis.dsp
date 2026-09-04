declare name "Tape Hysteresis";
declare description "Jiles-Atherton magnetic hysteresis tape saturator (CHOW Tape port) - soft, dynamic tape compression";
declare author "Jatin Chowdhury (model), Faust port in hysteresis.lib";
declare license "LGPL-2.1-or-later";
declare source "grame-cncm/faustlibraries/hysteresis.lib hy.ja_processor";
declare category "guitar";
declare family "dirt";
import("stdfaust.lib");

drive = hslider("[0] Drive[unit:dB]", 12, -20, 40, 0.1) : ba.db2linear : si.smoo;
sat   = hslider("[1] Saturation", 380, 100, 1000, 1);
width = hslider("[2] Loop Width", 380, 50, 1000, 1);
bias  = hslider("[3] Bias", 0.25, 0, 1, 0.01);
trim  = hslider("[4] Trim[unit:dB]", 0, -20, 20, 0.1) : ba.db2linear : si.smoo;
process = hy.ja_processor(sat, 720, 0.015, width, bias, drive, trim);
