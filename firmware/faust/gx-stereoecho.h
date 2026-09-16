/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Stereo Echo"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxStereoecho -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxStereoecho_H__
#define  __GxStereoecho_H__

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
#define FAUSTCLASS GxStereoecho
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


class GxStereoecho : public chdsp {
	
 private:
	
	int iVec0[2];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec1[2];
	double fRec2[2];
	FAUSTFLOAT fCheckbox0;
	int IOTA0;
	FAUSTFLOAT fVslider0;
	double fConst2;
	double fRec3[2];
	double fRec4[2];
	int iRec5[2];
	int iRec6[2];
	FAUSTFLOAT fVslider1;
	double fRec0[262144];
	FAUSTFLOAT fVslider2;
	double fRec8[2];
	double fRec9[2];
	int iRec10[2];
	int iRec11[2];
	FAUSTFLOAT fVslider3;
	double fRec7[262144];
	
 public:
	GxStereoecho() {
	}
	
	GxStereoecho(const GxStereoecho&) = default;
	
	virtual ~GxStereoecho() = default;
	
	GxStereoecho& operator=(const GxStereoecho&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/millisec:deprecated", "the 1s..43s names are power-of-two related ranges in milliseconds of a fixed slider, not seconds");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Echo / Delay");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxStereoecho -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-stereoecho.dsp");
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
		m->declare("name", "Stereo Echo");
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
		fVslider0 = static_cast<FAUSTFLOAT>(1.0);
		fVslider1 = static_cast<FAUSTFLOAT>(0.0);
		fVslider2 = static_cast<FAUSTFLOAT>(1.0);
		fVslider3 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0;
		}
		IOTA0 = 0;
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec3[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			iRec5[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			iRec6[l6] = 0;
		}
		for (int l7 = 0; l7 < 262144; l7 = faust_wrap_add(l7, 1)) {
			fRec0[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec8[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec9[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			iRec10[l10] = 0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			iRec11[l11] = 0;
		}
		for (int l12 = 0; l12 < 262144; l12 = faust_wrap_add(l12, 1)) {
			fRec7[l12] = 0.0;
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
	
	virtual GxStereoecho* clone() {
		return new GxStereoecho(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Stereo Echo");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("LFO freq", &fHslider0, FAUSTFLOAT(0.2), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fCheckbox0, "enum", "linear|pingpong");
		ui_interface->addCheckButton("invert", &fCheckbox0);
		ui_interface->addVerticalSlider("percent_l", &fVslider3, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("percent_r", &fVslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("time_l", &fVslider2, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(2e+03), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("time_r", &fVslider0, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(2e+03), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = fConst1 * static_cast<double>(fHslider0);
		double fSlow1 = std::cos(fSlow0);
		double fSlow2 = std::sin(fSlow0);
		double fSlow3 = static_cast<double>(fCheckbox0);
		int iSlow4 = faust_wrap_add(static_cast<int>(fConst2 * static_cast<double>(fVslider0)), -1);
		double fSlow5 = 0.01 * static_cast<double>(fVslider1);
		int iSlow6 = faust_wrap_add(static_cast<int>(fConst2 * static_cast<double>(fVslider2)), -1);
		double fSlow7 = 0.01 * static_cast<double>(fVslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec1[0] = fSlow2 * fRec2[1] + fSlow1 * fRec1[1];
			fRec2[0] = static_cast<double>(faust_wrap_sub(1, iVec0[1])) + fSlow1 * fRec2[1] - fSlow2 * fRec1[1];
			double fTemp0 = fSlow3 * fRec1[0];
			double fTemp1 = ((fRec3[1] != 0.0) ? (((fRec4[1] > 0.0) & (fRec4[1] < 1.0)) ? fRec3[1] : 0.0) : (((fRec4[1] == 0.0) & (iSlow4 != iRec5[1])) ? 0.0009765625 : (((fRec4[1] == 1.0) & (iSlow4 != iRec6[1])) ? -0.0009765625 : 0.0)));
			fRec3[0] = fTemp1;
			fRec4[0] = std::max<double>(0.0, std::min<double>(1.0, fRec4[1] + fTemp1));
			iRec5[0] = (((fRec4[1] >= 1.0) & (iRec6[1] != iSlow4)) ? iSlow4 : iRec5[1]);
			iRec6[0] = (((fRec4[1] <= 0.0) & (iRec5[1] != iSlow4)) ? iSlow4 : iRec6[1]);
			double fTemp2 = fRec0[(faust_wrap_sub(IOTA0, faust_wrap_add(std::min<int>(131072, std::max<int>(0, iRec5[0])), 1))) & 262143];
			double fTemp3 = static_cast<double>(input0[i0]);
			fRec0[IOTA0 & 262143] = fTemp3 + fSlow5 * (fTemp2 + fRec4[0] * (fRec0[(faust_wrap_sub(IOTA0, faust_wrap_add(std::min<int>(131072, std::max<int>(0, iRec6[0])), 1))) & 262143] - fTemp2)) * (fTemp0 + 1.0);
			double fTemp4 = ((fRec8[1] != 0.0) ? (((fRec9[1] > 0.0) & (fRec9[1] < 1.0)) ? fRec8[1] : 0.0) : (((fRec9[1] == 0.0) & (iSlow6 != iRec10[1])) ? 0.0009765625 : (((fRec9[1] == 1.0) & (iSlow6 != iRec11[1])) ? -0.0009765625 : 0.0)));
			fRec8[0] = fTemp4;
			fRec9[0] = std::max<double>(0.0, std::min<double>(1.0, fRec9[1] + fTemp4));
			iRec10[0] = (((fRec9[1] >= 1.0) & (iRec11[1] != iSlow6)) ? iSlow6 : iRec10[1]);
			iRec11[0] = (((fRec9[1] <= 0.0) & (iRec10[1] != iSlow6)) ? iSlow6 : iRec11[1]);
			double fTemp5 = fRec7[(faust_wrap_sub(IOTA0, faust_wrap_add(std::min<int>(131072, std::max<int>(0, iRec10[0])), 1))) & 262143];
			fRec7[IOTA0 & 262143] = fTemp3 + fSlow7 * (fTemp5 + fRec9[0] * (fRec7[(faust_wrap_sub(IOTA0, faust_wrap_add(std::min<int>(131072, std::max<int>(0, iRec11[0])), 1))) & 262143] - fTemp5)) * (1.0 - fTemp0);
			output0[i0] = static_cast<FAUSTFLOAT>(0.5 * (fRec7[IOTA0 & 262143] + fRec0[IOTA0 & 262143]));
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			iRec5[1] = iRec5[0];
			iRec6[1] = iRec6[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			iRec10[1] = iRec10[0];
			iRec11[1] = iRec11[0];
		}
	}

};

#endif
