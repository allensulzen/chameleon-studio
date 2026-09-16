/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "DunWah"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxDunwah -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxDunwah_H__
#define  __GxDunwah_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

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
#define FAUSTCLASS GxDunwah
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

static double GxDunwah_faustpower2_f(double value) {
	return value * value;
}

class GxDunwah : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fRec1[2];
	double fConst3;
	double fRec2[2];
	double fConst4;
	double fRec3[2];
	double fRec0[4];
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	double fConst11;
	double fConst12;
	
 public:
	GxDunwah() {
	}
	
	GxDunwah(const GxDunwah&) = default;
	
	virtual ~GxDunwah() = default;
	
	GxDunwah& operator=(const GxDunwah&) = default;
	
	void metadata(Meta* m) { 
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxDunwah -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-dunwah.dsp");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("filter.lib/version", "1.29");
		m->declare("id", "dunwah");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/version", "1.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/version", "1.0");
		m->declare("name", "DunWah");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 1.0 / fConst0;
		fConst2 = 0.5 / fConst0;
		fConst3 = std::exp(-(1236.9027460477864 / fConst0));
		fConst4 = 0.007000000000000006 * (fConst0 * (1.73888e-06 - 8.38823e-12 * fConst0) + -0.193457);
		fConst5 = 1.54419e-05 - 6.43963e-11 * fConst0;
		fConst6 = fConst0 * fConst5 + -0.386688;
		fConst7 = 1.77528e-06 - 8.52216e-12 * fConst0;
		fConst8 = fConst0 * fConst7 + 0.879905;
		fConst9 = fConst8 * fConst6;
		fConst10 = 1.00038 * fConst9;
		fConst11 = 1.00038 * (fConst8 + fConst6) + fConst9;
		fConst12 = -1.4935970000000003 - fConst0 * (fConst7 + fConst5);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec1[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec2[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec3[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 4; l3 = faust_wrap_add(l3, 1)) {
			fRec0[l3] = 0.0;
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
	
	virtual GxDunwah* clone() {
		return new GxDunwah(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("DunWah");
		ui_interface->addVerticalSlider("wah", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fVslider0);
		double fSlow1 = 1973.48 - 1e+03 / (fSlow0 * (fSlow0 * (fSlow0 * (fSlow0 * (fSlow0 * (12.499 * fSlow0 + -40.3658) + 49.9836) + -28.3434) + 5.76598) + 1.9841) + -1.6086);
		double fSlow2 = fConst2 * (fSlow1 / (fSlow0 * (fSlow0 * (fSlow0 * (fSlow0 * (115.375 - 52.3051 * fSlow0) + -99.7712) + 42.2734) + -24.555) + 21.9737));
		double fSlow3 = 0.014000000000000012 * (fSlow2 - 1.0) * std::cos(fConst1 * fSlow1);
		double fSlow4 = 0.007000000000000006 * GxDunwah_faustpower2_f(1.0 - fSlow2);
		double fSlow5 = fConst4 * (-0.933975 - 1.0 / (fSlow0 * (fSlow0 * (fSlow0 * (fSlow0 * (2.85511 * fSlow0 + -5.20364) + 3.64419) + -0.86331) + 0.270546) + -0.814203));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow3 + 0.993 * fRec1[1];
			fRec2[0] = fSlow4 + 0.993 * fRec2[1];
			fRec3[0] = fSlow5 + 0.993 * fRec3[1];
			fRec0[0] = static_cast<double>(input0[i0]) * fRec3[0] + fConst3 * fRec2[0] * fRec0[3] - (fRec0[1] * (fRec1[0] - fConst3) + fRec0[2] * (fRec2[0] - fConst3 * fRec1[0]));
			output0[i0] = static_cast<FAUSTFLOAT>(fRec0[0] + fConst12 * fRec0[1] + fConst11 * fRec0[2] - fConst10 * fRec0[3]);
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			for (int j0 = 3; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec0[j0] = fRec0[faust_wrap_sub(j0, 1)];
			}
		}
	}

};

#endif
