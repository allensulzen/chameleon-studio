/* ------------------------------------------------------------
author: "Christophe Lebreton (sfIter), adapted by GRAME"
license: "LGPL-2.1-or-later"
name: "Granular Gate"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn ExGranularGate -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __ExGranularGate_H__
#define  __ExGranularGate_H__

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
#define FAUSTCLASS ExGranularGate
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


class ExGranularGate : public chdsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	float fVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	float fRec1[2];
	float fConst4;
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	float fVec1[2];
	int IOTA0;
	int iVec2[128];
	int iRec6[2];
	float fRec5[2];
	FAUSTFLOAT fHslider2;
	float fVec3[2];
	float fRec7[2];
	int iVec4[2];
	float fRec3[2];
	float fRec2[2];
	float fRec0[2];
	float fConst5;
	float fConst6;
	FAUSTFLOAT fHslider3;
	float fRec8[2];
	
 public:
	ExGranularGate() {
	}
	
	ExGranularGate(const ExGranularGate&) = default;
	
	virtual ~ExGranularGate() = default;
	
	ExGranularGate& operator=(const ExGranularGate&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Christophe Lebreton (sfIter), adapted by GRAME");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "drum");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn ExGranularGate -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Bela granulator example turned into a rhythmic stutter gate: the input is chopped by probabilistic noise-burst envelopes at a settable rate and grain size");
		m->declare("family", "utility");
		m->declare("filename", "ex-granular-gate.dsp");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass0_highpass1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "LGPL-2.1-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Granular Gate");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.6.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faust/examples/bela/granulator.dsp");
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
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 1.0f / std::tan(3.1415927f / fConst0);
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.0f / (fConst1 + 1.0f);
		fConst4 = 1.0f / fConst0;
		fConst5 = 44.1f / fConst0;
		fConst6 = 1.0f - fConst5;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(1e+01f);
		fHslider1 = static_cast<FAUSTFLOAT>(2e+02f);
		fHslider2 = static_cast<FAUSTFLOAT>(7e+01f);
		fHslider3 = static_cast<FAUSTFLOAT>(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec4[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0f;
		}
		IOTA0 = 0;
		for (int l4 = 0; l4 < 128; l4 = faust_wrap_add(l4, 1)) {
			iVec2[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			iRec6[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fVec3[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			iVec4[l9] = 0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec3[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec2[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec0[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec8[l13] = 0.0f;
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
	
	virtual ExGranularGate* clone() {
		return new ExGranularGate(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Granular Gate");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->addHorizontalSlider("Grain Size", &fHslider1, FAUSTFLOAT(2e+02f), FAUSTFLOAT(5.0f), FAUSTFLOAT(2205.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->addHorizontalSlider("Speed", &fHslider0, FAUSTFLOAT(1e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->addHorizontalSlider("Probability", &fHslider2, FAUSTFLOAT(7e+01f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = static_cast<float>(fHslider0);
		float fSlow1 = 1.0f / static_cast<float>(fHslider1);
		float fSlow2 = static_cast<float>(fHslider2);
		float fSlow3 = fConst5 * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fVec0[0] = fSlow0;
			fRec1[0] = -(fConst3 * (fConst2 * fRec1[1] - (fSlow0 + fVec0[1])));
			float fTemp0 = 0.0625f / fRec1[0];
			int iTemp1 = std::fabs(fTemp0) < 1.1920929e-07f;
			float fTemp2 = ((iTemp1) ? 0.0f : std::exp(-(fConst4 / ((iTemp1) ? 1.0f : fTemp0))));
			float fTemp3 = 1.0f - fTemp2;
			fRec4[0] = std::fmod(fRec4[1] + fConst4 * fRec1[0], 1.0f);
			float fTemp4 = fRec4[0] + -0.001f;
			fVec1[0] = fTemp4;
			iVec2[IOTA0 & 127] = fTemp4 < 0.5f;
			int iTemp5 = (fVec1[1] <= 0.0f) & (fTemp4 > 0.0f);
			iRec6[0] = faust_wrap_add(faust_wrap_mul(1103515245, iRec6[1]), 12345);
			float fTemp6 = static_cast<float>(iRec6[0]);
			fRec5[0] = fRec5[1] * static_cast<float>(faust_wrap_sub(1, iTemp5)) + std::fabs(4.656613e-10f * fTemp6) * static_cast<float>(iTemp5);
			fVec3[0] = fSlow2;
			fRec7[0] = fConst3 * (0.01f * (fSlow2 + fVec3[1]) - fConst2 * fRec7[1]);
			int iTemp7 = (fRec7[0] > fRec5[0]) * iVec2[(faust_wrap_sub(IOTA0, 100)) & 127];
			iVec4[0] = iTemp7;
			fRec3[0] = fRec3[1] + static_cast<float>((faust_wrap_sub(iTemp7, iVec4[1])) > 0) - fSlow1 * static_cast<float>(fRec3[1] > 0.0f);
			float fTemp8 = std::fabs(4.656613e-10f * fTemp6 * static_cast<float>(fRec3[0] > 0.0f));
			fRec2[0] = std::max<float>(fTemp8, fTemp2 * fRec2[1] + fTemp3 * fTemp8);
			fRec0[0] = fRec2[0] * fTemp3 + fTemp2 * fRec0[1];
			fRec8[0] = fSlow3 + fConst6 * fRec8[1];
			output0[i0] = static_cast<FAUSTFLOAT>(static_cast<float>(input0[i0]) * (1.0f - fRec8[0] + fRec8[0] * std::min<float>(1.0f, 3.0f * std::min<float>(1.0f, fRec0[0]))));
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			fRec4[1] = fRec4[0];
			fVec1[1] = fVec1[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			iRec6[1] = iRec6[0];
			fRec5[1] = fRec5[0];
			fVec3[1] = fVec3[0];
			fRec7[1] = fRec7[0];
			iVec4[1] = iVec4[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec8[1] = fRec8[0];
		}
	}

};

#endif
