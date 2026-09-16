/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "auto"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxAutowah -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxAutowah_H__
#define  __GxAutowah_H__

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
#define FAUSTCLASS GxAutowah
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

static double GxAutowah_faustpower2_f(double value) {
	return value * value;
}

class GxAutowah : public chdsp {
	
 private:
	
	int IOTA0;
	int iVec0[1024];
	int iRec2[2];
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec1[2];
	double fConst2;
	double fRec3[2];
	double fRec4[2];
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT fVslider2;
	double fRec0[3];
	
 public:
	GxAutowah() {
	}
	
	GxAutowah(const GxAutowah&) = default;
	
	virtual ~GxAutowah() = default;
	
	GxAutowah& operator=(const GxAutowah&) = default;
	
	void metadata(Meta* m) { 
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxAutowah -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-autowah.dsp");
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
		m->declare("id", "auto");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "auto");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/version", "1.6.0");
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
		IOTA0 = 0;
		for (int l0 = 0; l0 < 1024; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iRec2[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec1[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec3[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec0[l5] = 0.0;
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
	
	virtual GxAutowah* clone() {
		return new GxAutowah(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("auto");
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
		double fSlow0 = 2.384185791015625e-10 * static_cast<double>(fVslider0);
		double fSlow1 = static_cast<double>(fVslider2);
		double fSlow2 = 0.01 * fSlow1 * static_cast<double>(fVslider1);
		double fSlow3 = 1.0 - 0.01 * fSlow1;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			int iTemp1 = std::abs(static_cast<int>(4194304.0 * fTemp0));
			iVec0[IOTA0 & 1023] = iTemp1;
			iRec2[0] = faust_wrap_sub(faust_wrap_add(iRec2[1], iTemp1), iVec0[(faust_wrap_sub(IOTA0, 1000)) & 1023]);
			double fTemp2 = std::min<double>(1.0, std::max<double>(0.0, fSlow0 * static_cast<double>(iRec2[0])));
			double fTemp3 = std::pow(2.0, 2.3 * fTemp2);
			double fTemp4 = 1.0 - fConst1 * (fTemp3 / std::pow(2.0, 2.0 * (1.0 - fTemp2) + 1.0));
			fRec1[0] = 0.0010000000000000009 * GxAutowah_faustpower2_f(fTemp4) + 0.999 * fRec1[1];
			fRec3[0] = 0.999 * fRec3[1] - 0.0020000000000000018 * fTemp4 * std::cos(fConst2 * fTemp3);
			fRec4[0] = 0.0001000000000000001 * std::pow(4.0, fTemp2) + 0.999 * fRec4[1];
			fRec0[0] = fSlow2 * fTemp0 * fRec4[0] - (fRec3[0] * fRec0[1] + fRec1[0] * fRec0[2]);
			output0[i0] = static_cast<FAUSTFLOAT>(fRec0[0] + fSlow3 * fTemp0 - fRec0[1]);
			IOTA0 = faust_wrap_add(IOTA0, 1);
			iRec2[1] = iRec2[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
