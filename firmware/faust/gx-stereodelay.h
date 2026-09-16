/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Stereo Delay"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxStereodelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxStereodelay_H__
#define  __GxStereodelay_H__

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
#define FAUSTCLASS GxStereodelay
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


class GxStereodelay : public chdsp {
	
 private:
	
	int IOTA0;
	double fVec0[524288];
	int iVec1[2];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec0[2];
	double fRec1[2];
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fVslider0;
	double fConst2;
	double fRec2[2];
	double fRec3[2];
	double fRec4[2];
	double fRec5[2];
	FAUSTFLOAT fVslider1;
	double fRec6[2];
	FAUSTFLOAT fVslider2;
	double fRec7[2];
	double fRec8[2];
	double fRec9[2];
	double fRec10[2];
	FAUSTFLOAT fVslider3;
	double fRec11[2];
	
 public:
	GxStereodelay() {
	}
	
	GxStereodelay(const GxStereodelay&) = default;
	
	virtual ~GxStereodelay() = default;
	
	GxStereodelay& operator=(const GxStereodelay&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Echo / Delay");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxStereodelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-stereodelay.dsp");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Stereo Delay");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
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
		fConst1 = 6.283185307179586 / fConst0;
		fConst2 = 0.001 * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.2);
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider1 = static_cast<FAUSTFLOAT>(0.0);
		fVslider2 = static_cast<FAUSTFLOAT>(0.0);
		fVslider3 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 524288; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec0[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec2[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec4[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec5[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec6[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec7[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec8[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec9[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec10[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec11[l13] = 0.0;
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
	
	virtual GxStereodelay* clone() {
		return new GxStereodelay(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Stereo Delay");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("LFO freq", &fHslider0, FAUSTFLOAT(0.2), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fCheckbox0, "enum", "linear|pingpong");
		ui_interface->addCheckButton("invert", &fCheckbox0);
		ui_interface->addVerticalSlider("l_delay", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5e+03), FAUSTFLOAT(1e+01));
		ui_interface->addVerticalSlider("l_gain", &fVslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("r_delay", &fVslider2, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5e+03), FAUSTFLOAT(1e+01));
		ui_interface->addVerticalSlider("r_gain", &fVslider3, FAUSTFLOAT(0.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = fConst1 * static_cast<double>(fHslider0);
		double fSlow1 = std::cos(fSlow0);
		double fSlow2 = std::sin(fSlow0);
		double fSlow3 = static_cast<double>(fCheckbox0);
		double fSlow4 = fConst2 * static_cast<double>(fVslider0);
		double fSlow5 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider1));
		double fSlow6 = fConst2 * static_cast<double>(fVslider2);
		double fSlow7 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider3));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			fVec0[IOTA0 & 524287] = fTemp0;
			iVec1[0] = 1;
			fRec0[0] = fSlow2 * fRec1[1] + fSlow1 * fRec0[1];
			fRec1[0] = static_cast<double>(faust_wrap_sub(1, iVec1[1])) + fSlow1 * fRec1[1] - fSlow2 * fRec0[1];
			double fTemp1 = fSlow3 * fRec0[0];
			double fTemp2 = ((fRec2[1] != 0.0) ? (((fRec3[1] > 0.0) & (fRec3[1] < 1.0)) ? fRec2[1] : 0.0) : (((fRec3[1] == 0.0) & (fSlow4 != fRec4[1])) ? 0.0009765625 : (((fRec3[1] == 1.0) & (fSlow4 != fRec5[1])) ? -0.0009765625 : 0.0)));
			fRec2[0] = fTemp2;
			fRec3[0] = std::max<double>(0.0, std::min<double>(1.0, fRec3[1] + fTemp2));
			fRec4[0] = (((fRec3[1] >= 1.0) & (fRec5[1] != fSlow4)) ? fSlow4 : fRec4[1]);
			fRec5[0] = (((fRec3[1] <= 0.0) & (fRec4[1] != fSlow4)) ? fSlow4 : fRec5[1]);
			double fTemp3 = fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec4[0]))))) & 524287];
			fRec6[0] = fSlow5 + 0.999 * fRec6[1];
			double fTemp4 = ((fRec7[1] != 0.0) ? (((fRec8[1] > 0.0) & (fRec8[1] < 1.0)) ? fRec7[1] : 0.0) : (((fRec8[1] == 0.0) & (fSlow6 != fRec9[1])) ? 0.0009765625 : (((fRec8[1] == 1.0) & (fSlow6 != fRec10[1])) ? -0.0009765625 : 0.0)));
			fRec7[0] = fTemp4;
			fRec8[0] = std::max<double>(0.0, std::min<double>(1.0, fRec8[1] + fTemp4));
			fRec9[0] = (((fRec8[1] >= 1.0) & (fRec10[1] != fSlow6)) ? fSlow6 : fRec9[1]);
			fRec10[0] = (((fRec8[1] <= 0.0) & (fRec9[1] != fSlow6)) ? fSlow6 : fRec10[1]);
			double fTemp5 = fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec9[0]))))) & 524287];
			fRec11[0] = fSlow7 + 0.999 * fRec11[1];
			output0[i0] = static_cast<FAUSTFLOAT>(0.5 * (fRec11[0] * (fTemp5 + fRec8[0] * (fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec10[0]))))) & 524287] - fTemp5)) * (fTemp1 + 1.0) + fRec6[0] * (fTemp3 + fRec3[0] * (fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec5[0]))))) & 524287] - fTemp3)) * (1.0 - fTemp1) + 2.0 * fTemp0));
			IOTA0 = faust_wrap_add(IOTA0, 1);
			iVec1[1] = iVec1[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
		}
	}

};

#endif
