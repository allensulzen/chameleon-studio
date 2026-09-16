/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Electra Distortion"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxEldist -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxEldist_H__
#define  __GxEldist_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>
#ifndef FAUST_INT_WRAP
#define FAUST_INT_WRAP
inline int faust_wrap_add(int a, int b) { return int((unsigned int)a + (unsigned int)b); }
inline int faust_wrap_sub(int a, int b) { return int((unsigned int)a - (unsigned int)b); }
inline int faust_wrap_mul(int a, int b) { return int((unsigned int)a * (unsigned int)b); }
#endif


#ifndef FAUSTCLASS 
#define FAUSTCLASS GxEldist
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

const static double fGxEldistSIG0Wave0[100] = {0.00548195523019,0.0164458656904,0.0274097761501,0.0383736866088,0.0493375970657,0.0603015075192,0.071265417967,0.082229328405,0.0931932388259,0.104157149217,0.115121059557,0.126084969809,0.137048879907,0.148012789741,0.158976699115,0.169940607697,0.180904514906,0.19186841974,0.202832320465,0.213796214083,0.224760095401,0.235723955442,0.24668777867,0.257651538208,0.268615187559,0.279578646281,0.290541775224,0.301504333702,0.31246590549,0.323425771038,0.334382687141,0.345334508004,0.356277536338,0.36720542057,0.378107305219,0.388964799793,0.39974721221,0.410404597847,0.420859012966,0.430996762036,0.440668575786,0.449707178596,0.45796452493,0.465352673431,0.471862566939,0.477551600417,0.482514574087,0.486856857354,0.490677923318,0.494064268475,0.497087986537,0.499807950264,0.502271855575,0.504518314813,0.506578692135,0.508478608197,0.510239134989,0.511877730826,0.513408968151,0.514845100082,0.516196502828,0.517472022884,0.518679251142,0.519824740714,0.5209141812,0.521952539054,0.522944171412,0.523892918995,0.524802182408,0.525674985201,0.526514026277,0.527321723696,0.528100251477,0.528851570689,0.529577455822,0.530279517274,0.530959220607,0.531617903101,0.532256788046,0.532876997124,0.533479561183,0.534065429631,0.534635478673,0.535190518535,0.535731299833,0.536258519204,0.536772824291,0.537274818172,0.537765063306,0.538244085058,0.53871237485,0.539170392992,0.539618571221,0.540057314992,0.540487005551,0.540908001798,0.541320641986,0.541725245255,0.542122113037,0.542511530324};
class GxEldistSIG0 {
	
  private:
	
	int fGxEldistSIG0Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxEldistSIG0() {
		return 0;
	}
	int getNumOutputsGxEldistSIG0() {
		return 1;
	}
	
	void instanceInitGxEldistSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		fGxEldistSIG0Wave0_idx = 0;
	}
	
	void fillGxEldistSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			table[i1] = fGxEldistSIG0Wave0[fGxEldistSIG0Wave0_idx];
			fGxEldistSIG0Wave0_idx = (faust_wrap_add(1, fGxEldistSIG0Wave0_idx)) % 100;
		}
	}

};

static GxEldistSIG0* newGxEldistSIG0() { return (GxEldistSIG0*)new GxEldistSIG0(); }
static void deleteGxEldistSIG0(GxEldistSIG0* dsp) { delete dsp; }

const static double fGxEldistSIG1Wave0[100] = {0.00548195522984,0.0164458656887,0.0274097761447,0.0383736865927,0.0493375970208,0.0603015073993,0.0712654176541,0.0822293276003,0.0931932367771,0.104157144035,0.11512104651,0.126084937057,0.137048797865,0.148012584519,0.158976186287,0.169939327112,0.180901318968,0.191860448193,0.202812453537,0.213746781788,0.224637558478,0.235422881479,0.245963037986,0.255981272682,0.265056774549,0.272796438414,0.279086380931,0.284103404685,0.288129383241,0.29141818239,0.29416079535,0.29649293643,0.298510269206,0.300281012405,0.301854732568,0.30326818924,0.304549194955,0.305719189036,0.306794981789,0.307789958469,0.308714926055,0.309578719626,0.310388644094,0.311150801115,0.311870334639,0.312551617847,0.31319839728,0.313813905242,0.314400948411,0.314961978382,0.315499148345,0.316014359013,0.316509296137,0.316985461359,0.317444197792,0.31788671133,0.318314088536,0.318727311728,0.31912727177,0.319514778982,0.319890572474,0.320255328186,0.320609665818,0.32095415486,0.321289319821,0.321615644816,0.321933577573,0.322243532968,0.322545896136,0.32284102523,0.323129253866,0.3234108933,0.323686234368,0.323955549227,0.324219092904,0.324477104703,0.324729809459,0.324977418675,0.325220131553,0.32545813592,0.325691609076,0.325920718563,0.32614562286,0.326366472027,0.326583408283,0.326796566545,0.327006074914,0.327212055124,0.327414622958,0.327613888624,0.32780995711,0.328002928502,0.328192898288,0.328379957631,0.328564193627,0.328745689541,0.328924525028,0.329100776338,0.329274516508,0.329445815535};
class GxEldistSIG1 {
	
  private:
	
	int fGxEldistSIG1Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxEldistSIG1() {
		return 0;
	}
	int getNumOutputsGxEldistSIG1() {
		return 1;
	}
	
	void instanceInitGxEldistSIG1(int sample_rate) {
		fSampleRate = sample_rate;
		fGxEldistSIG1Wave0_idx = 0;
	}
	
	void fillGxEldistSIG1(int count, double* table) {
		for (int i2 = 0; i2 < count; i2 = faust_wrap_add(i2, 1)) {
			table[i2] = fGxEldistSIG1Wave0[fGxEldistSIG1Wave0_idx];
			fGxEldistSIG1Wave0_idx = (faust_wrap_add(1, fGxEldistSIG1Wave0_idx)) % 100;
		}
	}

};

static GxEldistSIG1* newGxEldistSIG1() { return (GxEldistSIG1*)new GxEldistSIG1(); }
static void deleteGxEldistSIG1(GxEldistSIG1* dsp) { delete dsp; }

static double DSY_SDRAM_BSS ftbl0GxEldistSIG0[100];
static double DSY_SDRAM_BSS ftbl1GxEldistSIG1[100];

class GxEldist : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	double fRec0[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fRec1[2];
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	
 public:
	GxEldist() {
	}
	
	GxEldist(const GxEldist&) = default;
	
	virtual ~GxEldist() = default;
	
	GxEldist& operator=(const GxEldist&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Distortion");
		m->declare("chameleon_flags", "-double");
		m->declare("clipping.lib/license", "GPL-2.0-or-later");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxEldist -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Electra Distortion");
		m->declare("filename", "gx-eldist.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("gx_tables.lib/license", "GPL-2.0-or-later");
		m->declare("id", "eldist");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Electra Distortion");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("samplerate", "96000");
		m->declare("shortname", "Electra Dst");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		GxEldistSIG0* sig0 = newGxEldistSIG0();
		sig0->instanceInitGxEldistSIG0(sample_rate);
		sig0->fillGxEldistSIG0(100, ftbl0GxEldistSIG0);
		GxEldistSIG1* sig1 = newGxEldistSIG1();
		sig1->instanceInitGxEldistSIG1(sample_rate);
		sig1->fillGxEldistSIG1(100, ftbl1GxEldistSIG1);
		deleteGxEldistSIG0(sig0);
		deleteGxEldistSIG1(sig1);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 3.9949101411109e-05 * fConst0;
		fConst2 = -8.66687668918243e-05 - fConst1;
		fConst3 = 4.07955525542246e-05 * fConst0;
		fConst4 = fConst1 + -8.66687668918243e-05;
		fConst5 = ftbl0GxEldistSIG0[99];
		fConst6 = ftbl0GxEldistSIG0[0];
		fConst7 = ftbl1GxEldistSIG1[99];
		fConst8 = ftbl1GxEldistSIG1[0];
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual GxEldist* clone() {
		return new GxEldist(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Electra Distortion");
		ui_interface->declare(&fVslider0, "name", "Drive");
		ui_interface->addVerticalSlider("Drive", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * static_cast<double>(fVslider0);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			double fTemp0 = fConst3 + fConst2 * fRec0[0] + 0.000635245647283505;
			double fTemp1 = 8.14686408743197e-08 * fRec0[0];
			fRec1[0] = static_cast<double>(input0[i0]) - fRec1[1] * (fConst4 * fRec0[0] + 0.000635245647283505 - fConst3) / fTemp0;
			double fTemp2 = fConst0 * ((fRec1[0] * (-0.00018716364572377 - fTemp1) + fRec1[1] * (fTemp1 + 0.00018716364572377)) / fTemp0);
			double fTemp3 = std::fabs(fTemp2);
			double fTemp4 = 101.97 * (fTemp3 / (fTemp3 + 3.0) + -0.005);
			double fTemp5 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp4) | std::isinf(fTemp4)) ? 0.0 : fTemp4)));
			int iTemp6 = static_cast<int>(fTemp5);
			int iTemp7 = iTemp6 < 0;
			int iTemp8 = iTemp6 >= 99;
			int iTemp9 = std::max<int>(0, std::min<int>(98, iTemp6));
			int iTemp10 = faust_wrap_add(iTemp9, 1);
			double fTemp11 = static_cast<double>(iTemp9);
			double fTemp12 = fTemp5 - fTemp11;
			double fTemp13 = fTemp11 + (1.0 - fTemp5);
			output0[i0] = static_cast<FAUSTFLOAT>(copysign(((fTemp2 < 0.0) ? ((iTemp7) ? fConst8 : ((iTemp8) ? fConst7 : fTemp13 * ftbl1GxEldistSIG1[iTemp9] + fTemp12 * ftbl1GxEldistSIG1[iTemp10])) : ((iTemp7) ? fConst6 : ((iTemp8) ? fConst5 : ftbl0GxEldistSIG0[iTemp9] * fTemp13 + fTemp12 * ftbl0GxEldistSIG0[iTemp10]))), -fTemp2));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
