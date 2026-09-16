/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Flanger GX"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFlangerGx -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxFlangerGx_H__
#define  __GxFlangerGx_H__

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
#define FAUSTCLASS GxFlangerGx
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


class GxFlangerGx : public chdsp {
	
 private:
	
	int iVec0[2];
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec2[2];
	double fRec3[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	double fConst2;
	int IOTA0;
	double fVec1[2048];
	double fVec2[2048];
	double fRec1[2];
	FAUSTFLOAT fHslider5;
	double fVec3[4096];
	double fRec0[2];
	
 public:
	GxFlangerGx() {
	}
	
	GxFlangerGx(const GxFlangerGx&) = default;
	
	virtual ~GxFlangerGx() = default;
	
	GxFlangerGx& operator=(const GxFlangerGx&) = default;
	
	void metadata(Meta* m) { 
		m->declare("category", "Modulation");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFlangerGx -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-flanger-gx.dsp");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "flanger_mono_gx");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Flanger GX");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
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
		fConst2 = 0.5 * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.0);
		fHslider1 = static_cast<FAUSTFLOAT>(-0.707);
		fHslider2 = static_cast<FAUSTFLOAT>(0.2);
		fHslider3 = static_cast<FAUSTFLOAT>(5.0);
		fHslider4 = static_cast<FAUSTFLOAT>(0.5);
		fHslider5 = static_cast<FAUSTFLOAT>(1e+02);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec2[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec3[l2] = 0.0;
		}
		IOTA0 = 0;
		for (int l3 = 0; l3 < 2048; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2048; l4 = faust_wrap_add(l4, 1)) {
			fVec2[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec1[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 4096; l6 = faust_wrap_add(l6, 1)) {
			fVec3[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec0[l7] = 0.0;
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
	
	virtual GxFlangerGx* clone() {
		return new GxFlangerGx(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Flanger GX");
		ui_interface->declare(&fHslider4, "name", "Depth");
		ui_interface->addHorizontalSlider("depth", &fHslider4, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider1, "name", "Feedback");
		ui_interface->addHorizontalSlider("feedback", &fHslider1, FAUSTFLOAT(-0.707), FAUSTFLOAT(-0.99), FAUSTFLOAT(0.99), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider2, "log", "");
		ui_interface->declare(&fHslider2, "name", "Speed");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(0.2), FAUSTFLOAT(0.05), FAUSTFLOAT(1e+01), FAUSTFLOAT(1.06));
		ui_interface->declare(&fHslider0, "name", "Mix");
		ui_interface->addHorizontalSlider("mix", &fHslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(-1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider5, "name", "Wet");
		ui_interface->addHorizontalSlider("wet", &fHslider5, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider3, "name", "Width");
		ui_interface->addHorizontalSlider("width", &fHslider3, FAUSTFLOAT(5.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fHslider0);
		double fSlow1 = 0.3333333333333333 * static_cast<double>(fHslider1) * (std::fabs(fSlow0) + 2.0);
		double fSlow2 = fConst1 * static_cast<double>(fHslider2);
		double fSlow3 = std::cos(fSlow2);
		double fSlow4 = std::sin(fSlow2);
		double fSlow5 = 0.0005 * static_cast<double>(fHslider3);
		double fSlow6 = 0.001 * static_cast<double>(fHslider4);
		double fSlow7 = static_cast<double>(fHslider5);
		double fSlow8 = 0.01 * fSlow7 * std::min<double>(1.0, fSlow0 + 1.0);
		double fSlow9 = 2.0 - fSlow8;
		double fSlow10 = 0.01 * fSlow7 * std::min<double>(1.0, 1.0 - fSlow0);
		double fSlow11 = 2.0 - fSlow10;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec2[0] = fSlow4 * fRec3[1] + fSlow3 * fRec2[1];
			fRec3[0] = static_cast<double>(faust_wrap_sub(1, iVec0[1])) + fSlow3 * fRec3[1] - fSlow4 * fRec2[1];
			double fTemp0 = fSlow6 + fSlow5 * (fRec2[0] + 1.0);
			double fTemp1 = fConst2 * fTemp0;
			double fTemp2 = std::floor(fTemp1);
			double fTemp3 = fTemp2 + (1.0 - fTemp1);
			double fTemp4 = static_cast<double>(input0[i0]);
			fVec1[IOTA0 & 2047] = fTemp4;
			int iTemp5 = static_cast<int>(fTemp1);
			int iTemp6 = std::min<int>(1025, std::max<int>(0, iTemp5));
			int iTemp7 = std::min<int>(1025, std::max<int>(0, faust_wrap_add(iTemp5, 1)));
			double fTemp8 = fTemp1 - fTemp2;
			double fTemp9 = fTemp8 * fVec1[(faust_wrap_sub(IOTA0, iTemp7)) & 2047] + fSlow1 * fRec1[1] + fVec1[(faust_wrap_sub(IOTA0, iTemp6)) & 2047] * fTemp3;
			fVec2[IOTA0 & 2047] = fTemp9;
			fRec1[0] = fTemp3 * fVec2[(faust_wrap_sub(IOTA0, iTemp6)) & 2047] + fTemp8 * fVec2[(faust_wrap_sub(IOTA0, iTemp7)) & 2047];
			double fTemp10 = fSlow9 * fTemp4 + fSlow8 * fRec1[0];
			double fTemp11 = fTemp10 - fSlow1 * fRec0[1];
			fVec3[IOTA0 & 4095] = fTemp11;
			double fTemp12 = fConst0 * fTemp0;
			int iTemp13 = static_cast<int>(fTemp12);
			double fTemp14 = std::floor(fTemp12);
			fRec0[0] = fVec3[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, iTemp13)))) & 4095] * (fTemp14 + (1.0 - fTemp12)) + (fTemp12 - fTemp14) * fVec3[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, faust_wrap_add(iTemp13, 1))))) & 4095];
			output0[i0] = static_cast<FAUSTFLOAT>(0.25 * (fSlow11 * fTemp10 + fSlow10 * fRec0[0]));
			iVec0[1] = iVec0[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
