/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "HF Brightener"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxHfb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxHfb_H__
#define  __GxHfb_H__

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
#define FAUSTCLASS GxHfb
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

static double GxHfb_faustpower2_f(double value) {
	return value * value;
}

class GxHfb : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	double fRec0[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	FAUSTFLOAT fVslider1;
	double fRec1[2];
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	double fConst11;
	double fRec2[3];
	
 public:
	GxHfb() {
	}
	
	GxHfb(const GxHfb&) = default;
	
	virtual ~GxHfb() = default;
	
	GxHfb& operator=(const GxHfb&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Tone Control");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxHfb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "High Frequency Brightener");
		m->declare("filename", "gx-hfb.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "hfb");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "HF Brightener");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "HF Brightener");
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
		fConst1 = 2.36551040815034e-10 * fConst0;
		fConst2 = fConst1 + 1.32257544516629e-08;
		fConst3 = 1.17023754306854e-09 * fConst0;
		fConst4 = -6.50608604711861e-08 - fConst3;
		fConst5 = 1.18275520407517e-09 * fConst0;
		fConst6 = fConst5 + 6.61287722583147e-08;
		fConst7 = GxHfb_faustpower2_f(fConst0);
		fConst8 = 1.06027340359031e-06 * fConst0;
		fConst9 = fConst1 + -1.32257544516629e-08;
		fConst10 = 6.50608604711861e-08 - fConst3;
		fConst11 = fConst5 + -6.61287722583147e-08;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0;
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
	
	virtual GxHfb* clone() {
		return new GxHfb(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("HF Brightener");
		ui_interface->declare(&fVslider1, "name", "Intensity");
		ui_interface->addVerticalSlider("Intensity", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider0, "name", "Volume");
		ui_interface->addVerticalSlider("Volume", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * (1.0 - static_cast<double>(fVslider0));
		double fSlow1 = 0.007000000000000006 * static_cast<double>(fVslider1);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			fRec1[0] = fSlow1 + 0.993 * fRec1[1];
			double fTemp0 = fConst0 * (fRec1[0] * (fConst6 + fConst4 * fRec1[0]) + fConst2 * fRec0[0] + 7.88503469383447e-07) + 4.40858481722098e-05;
			double fTemp1 = fConst7 * (fRec1[0] * (5.12666523663255e-23 * fRec1[0] + -1.59041010538546e-09) - 3.18082021077091e-10 * fRec0[0]);
			fRec2[0] = static_cast<double>(input0[i0]) - (fRec2[1] * (fConst7 * (fRec1[0] * (2.34047508613708e-09 * fRec1[0] + -2.36551040815034e-09) - 4.73102081630068e-10 * fRec0[0]) + 8.81716963444196e-05) + fRec2[2] * (fConst0 * (fRec1[0] * (fConst11 + fConst10 * fRec1[0]) + fConst9 * fRec0[0] + -7.88503469383447e-07) + 4.40858481722098e-05)) / fTemp0;
			output0[i0] = static_cast<FAUSTFLOAT>((fRec2[0] * (fTemp1 - fConst8) + fConst7 * fRec2[1] * (6.36164042154183e-10 * fRec0[0] + fRec1[0] * (3.18082021077092e-09 - 1.02533304732651e-22 * fRec1[0])) + fRec2[2] * (fConst8 + fTemp1)) / fTemp0);
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
		}
	}

};

#endif
