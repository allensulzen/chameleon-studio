/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "manual"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxCrybaby -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxCrybaby_H__
#define  __GxCrybaby_H__

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
#define FAUSTCLASS GxCrybaby
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

static double GxCrybaby_faustpower2_f(double value) {
	return value * value;
}

class GxCrybaby : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec1[2];
	double fConst2;
	double fRec2[2];
	double fRec3[2];
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT fVslider2;
	double fRec0[3];
	
 public:
	GxCrybaby() {
	}
	
	GxCrybaby(const GxCrybaby&) = default;
	
	virtual ~GxCrybaby() = default;
	
	GxCrybaby& operator=(const GxCrybaby&) = default;
	
	void metadata(Meta* m) { 
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxCrybaby -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-crybaby.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "manual");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "manual");
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
		fConst1 = 1413.7166941154069 / fConst0;
		fConst2 = 2827.4333882308138 / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider1 = static_cast<FAUSTFLOAT>(0.1);
		fVslider2 = static_cast<FAUSTFLOAT>(1e+02);
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
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
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
	
	virtual GxCrybaby* clone() {
		return new GxCrybaby(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("manual");
		ui_interface->declare(&fVslider1, "alias", "");
		ui_interface->addVerticalSlider("crybaby.level", &fVslider1, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider0, "alias", "");
		ui_interface->addVerticalSlider("crybaby.wah", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider2, "alias", "");
		ui_interface->declare(&fVslider2, "name", "wet/dry");
		ui_interface->addVerticalSlider("crybaby.wet_dry", &fVslider2, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fVslider0);
		double fSlow1 = std::pow(2.0, 2.3 * fSlow0);
		double fSlow2 = 1.0 - fConst1 * (fSlow1 / std::pow(2.0, 2.0 * (1.0 - fSlow0) + 1.0));
		double fSlow3 = 0.0010000000000000009 * GxCrybaby_faustpower2_f(fSlow2);
		double fSlow4 = 0.0020000000000000018 * fSlow2 * std::cos(fConst2 * fSlow1);
		double fSlow5 = 0.0001000000000000001 * std::pow(4.0, fSlow0);
		double fSlow6 = static_cast<double>(fVslider2);
		double fSlow7 = 0.01 * fSlow6 * static_cast<double>(fVslider1);
		double fSlow8 = 1.0 - 0.01 * fSlow6;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow3 + 0.999 * fRec1[1];
			fRec2[0] = 0.999 * fRec2[1] - fSlow4;
			fRec3[0] = fSlow5 + 0.999 * fRec3[1];
			double fTemp0 = static_cast<double>(input0[i0]);
			fRec0[0] = fSlow7 * fTemp0 * fRec3[0] - 0.996 * (fRec2[0] * fRec0[1] + fRec1[0] * fRec0[2]);
			output0[i0] = static_cast<FAUSTFLOAT>(fRec0[0] + fSlow8 * fTemp0 - 0.996 * fRec0[1]);
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
