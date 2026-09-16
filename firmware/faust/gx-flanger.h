/* ------------------------------------------------------------
license: "BSD"
name: "Flanger"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFlanger -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxFlanger_H__
#define  __GxFlanger_H__

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
#define FAUSTCLASS GxFlanger
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


class GxFlanger : public chdsp {
	
 private:
	
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int iVec0[2];
	FAUSTFLOAT fHslider2;
	int IOTA0;
	double fVec1[4096];
	FAUSTFLOAT fHslider3;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec1[2];
	double fRec2[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	double fRec0[2];
	double fVec2[4096];
	double fRec3[2];
	
 public:
	GxFlanger() {
	}
	
	GxFlanger(const GxFlanger&) = default;
	
	virtual ~GxFlanger() = default;
	
	GxFlanger& operator=(const GxFlanger&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Modulation");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFlanger -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-flanger.dsp");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "flanger");
		m->declare("license", "BSD");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Flanger");
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
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0);
		fHslider0 = static_cast<FAUSTFLOAT>(1.0);
		fHslider1 = static_cast<FAUSTFLOAT>(0.0);
		fHslider2 = static_cast<FAUSTFLOAT>(0.0);
		fHslider3 = static_cast<FAUSTFLOAT>(0.2);
		fHslider4 = static_cast<FAUSTFLOAT>(1e+01);
		fHslider5 = static_cast<FAUSTFLOAT>(1.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 4096; l1 = faust_wrap_add(l1, 1)) {
			fVec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec1[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec2[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec0[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 4096; l5 = faust_wrap_add(l5, 1)) {
			fVec2[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec3[l6] = 0.0;
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
	
	virtual GxFlanger* clone() {
		return new GxFlanger(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Flanger");
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("LFO freq", &fHslider3, FAUSTFLOAT(0.2), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("depth", &fHslider0, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("feedback gain", &fHslider2, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider4, "unit", "ms");
		ui_interface->addHorizontalSlider("flange de.delay", &fHslider4, FAUSTFLOAT(1e+01), FAUSTFLOAT(0.0), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider5, "unit", "ms");
		ui_interface->addHorizontalSlider("flange de.delay offset", &fHslider5, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fCheckbox0, "enum", "linear|invert");
		ui_interface->addCheckButton("invert", &fCheckbox0);
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("level", &fHslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-6e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fHslider0);
		double fSlow1 = ((static_cast<int>(static_cast<double>(fCheckbox0))) ? -fSlow0 : fSlow0);
		double fSlow2 = std::pow(1e+01, 0.05 * static_cast<double>(fHslider1));
		double fSlow3 = static_cast<double>(fHslider2);
		double fSlow4 = fConst1 * static_cast<double>(fHslider3);
		double fSlow5 = std::cos(fSlow4);
		double fSlow6 = std::sin(fSlow4);
		double fSlow7 = 0.0005 * static_cast<double>(fHslider4);
		double fSlow8 = 0.001 * static_cast<double>(fHslider5);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = fSlow2 * static_cast<double>(input0[i0]);
			iVec0[0] = 1;
			double fTemp1 = fSlow3 * fRec0[1] - fTemp0;
			fVec1[IOTA0 & 4095] = fTemp1;
			fRec1[0] = fSlow6 * fRec2[1] + fSlow5 * fRec1[1];
			fRec2[0] = static_cast<double>(faust_wrap_sub(1, iVec0[1])) + fSlow5 * fRec2[1] - fSlow6 * fRec1[1];
			double fTemp2 = fConst0 * (fSlow8 + fSlow7 * (fRec2[0] + 1.0));
			int iTemp3 = static_cast<int>(fTemp2);
			double fTemp4 = std::floor(fTemp2);
			fRec0[0] = fVec1[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, iTemp3)))) & 4095] * (fTemp4 + (1.0 - fTemp2)) + (fTemp2 - fTemp4) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, faust_wrap_add(iTemp3, 1))))) & 4095];
			double fTemp5 = fSlow3 * fRec3[1] - fTemp0;
			fVec2[IOTA0 & 4095] = fTemp5;
			double fTemp6 = fConst0 * (fSlow8 + fSlow7 * (fRec1[0] + 1.0));
			int iTemp7 = static_cast<int>(fTemp6);
			double fTemp8 = std::floor(fTemp6);
			fRec3[0] = fVec2[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, iTemp7)))) & 4095] * (fTemp8 + (1.0 - fTemp6)) + (fTemp6 - fTemp8) * fVec2[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, faust_wrap_add(iTemp7, 1))))) & 4095];
			output0[i0] = static_cast<FAUSTFLOAT>(0.25 * (fTemp0 + fRec3[0] * fSlow1 + fTemp0 + fRec0[0] * fSlow1));
			iVec0[1] = iVec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
