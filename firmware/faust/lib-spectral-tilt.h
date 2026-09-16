/* ------------------------------------------------------------
author: "Julius O. Smith III"
license: "LicenseRef-STK-4.3"
name: "Spectral Tilt"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibSpectralTilt -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibSpectralTilt_H__
#define  __LibSpectralTilt_H__

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
#define FAUSTCLASS LibSpectralTilt
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

static float LibSpectralTilt_faustpower2_f(float value) {
	return value * value;
}
static float LibSpectralTilt_faustpower3_f(float value) {
	return value * value * value;
}

class LibSpectralTilt : public chdsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider2;
	float fRec0[2];
	float fConst3;
	FAUSTFLOAT fHslider3;
	float fRec1[2];
	float fConst4;
	float fVec0[2];
	float fRec5[2];
	float fVec1[2];
	float fRec4[2];
	float fVec2[2];
	float fRec3[2];
	float fVec3[2];
	float fRec2[2];
	
 public:
	LibSpectralTilt() {
	}
	
	LibSpectralTilt(const LibSpectralTilt&) = default;
	
	virtual ~LibSpectralTilt() = default;
	
	LibSpectralTilt& operator=(const LibSpectralTilt&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Julius O. Smith III");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibSpectralTilt -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "JOS spectral tilt filter: constant-slope dB/octave tilt across a chosen band (pink/brown-ish shaping)");
		m->declare("family", "utility");
		m->declare("filename", "lib-spectral-tilt.dsp");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/spectral_tilt:author", "Julius O. Smith III");
		m->declare("filters.lib/spectral_tilt:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/spectral_tilt:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "LicenseRef-STK-4.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Spectral Tilt");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faust/examples/filtering/spectralTilt.dsp fi.spectral_tilt");
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
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 3.1415927f / fConst0;
		fConst4 = 1.0f / std::tan(0.5f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(1e+02f);
		fHslider1 = static_cast<FAUSTFLOAT>(5e+03f);
		fHslider2 = static_cast<FAUSTFLOAT>(-0.5f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec3[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec2[l9] = 0.0f;
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
	
	virtual LibSpectralTilt* clone() {
		return new LibSpectralTilt(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Spectral Tilt");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->addHorizontalSlider("Slope", &fHslider2, FAUSTFLOAT(-0.5f), FAUSTFLOAT(-1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "scale", "log");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("Band Start", &fHslider0, FAUSTFLOAT(1e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Band Width", &fHslider1, FAUSTFLOAT(5e+03f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->declare(&fHslider3, "unit", "dB");
		ui_interface->addHorizontalSlider("Level", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = std::max<float>(static_cast<float>(fHslider0), 1.1920929e-07f);
		float fSlow1 = std::pow((static_cast<float>(fHslider1) + fSlow0) / fSlow0, 0.33333334f);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		float fSlow3 = fConst3 * fSlow0;
		float fSlow4 = fConst1 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider3));
		float fSlow5 = std::tan(fSlow3);
		float fSlow6 = 6.2831855f * (fSlow0 / fSlow5);
		float fSlow7 = 6.2831855f * fSlow0;
		float fSlow8 = fSlow7 - fConst4;
		float fSlow9 = 1.0f / (fConst4 + fSlow7);
		float fSlow10 = std::tan(fConst3 * fSlow0 * fSlow1);
		float fSlow11 = 6.2831855f * (fSlow0 * fSlow10 / fSlow5);
		float fSlow12 = fSlow11 - fConst4;
		float fSlow13 = 1.0f / (fConst4 + fSlow11);
		float fSlow14 = std::tan(fConst3 * fSlow0 * LibSpectralTilt_faustpower2_f(fSlow1));
		float fSlow15 = 6.2831855f * (fSlow0 * fSlow14 / fSlow5);
		float fSlow16 = fSlow15 - fConst4;
		float fSlow17 = 1.0f / (fConst4 + fSlow15);
		float fSlow18 = std::tan(fConst3 * fSlow0 * LibSpectralTilt_faustpower3_f(fSlow1));
		float fSlow19 = 6.2831855f * (fSlow0 * fSlow18 / fSlow5);
		float fSlow20 = fSlow19 - fConst4;
		float fSlow21 = 1.0f / (fConst4 + fSlow19);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow2 + fConst2 * fRec0[1];
			float fTemp0 = std::tan(fSlow3 * std::pow(fSlow1, 3.0f - fRec0[0]));
			fRec1[0] = fSlow4 + fConst2 * fRec1[1];
			float fTemp1 = std::tan(fSlow3 * std::pow(fSlow1, 2.0f - fRec0[0]));
			float fTemp2 = fSlow6 * fTemp0;
			float fTemp3 = std::tan(fSlow3 * std::pow(fSlow1, 1.0f - fRec0[0]));
			float fTemp4 = fSlow6 * fTemp1;
			float fTemp5 = std::tan(fSlow3 * std::pow(fSlow1, -fRec0[0]));
			float fTemp6 = fSlow6 * fTemp3;
			float fTemp7 = fSlow6 * fTemp5;
			float fTemp8 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp8;
			fRec5[0] = -(fSlow9 * (fSlow8 * fRec5[1] - (fTemp8 * (fConst4 + fTemp7) + fVec0[1] * (fTemp7 - fConst4))));
			fVec1[0] = fSlow5 * (fRec5[0] / fTemp5);
			fRec4[0] = -(fSlow13 * (fSlow12 * fRec4[1] - (fVec1[1] * (fTemp6 - fConst4) + fSlow5 * (fRec5[0] * (fConst4 + fTemp6) / fTemp5))));
			fVec2[0] = fSlow10 * (fRec4[0] / fTemp3);
			fRec3[0] = -(fSlow17 * (fSlow16 * fRec3[1] - (fVec2[1] * (fTemp4 - fConst4) + fSlow10 * (fRec4[0] * (fConst4 + fTemp4) / fTemp3))));
			fVec3[0] = fSlow14 * (fRec3[0] / fTemp1);
			fRec2[0] = -(fSlow21 * (fSlow20 * fRec2[1] - (fVec3[1] * (fTemp2 - fConst4) + fSlow14 * (fRec3[0] * (fConst4 + fTemp2) / fTemp1))));
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow18 * (fRec2[0] * fRec1[0] / fTemp0));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fVec0[1] = fVec0[0];
			fRec5[1] = fRec5[0];
			fVec1[1] = fVec1[0];
			fRec4[1] = fRec4[0];
			fVec2[1] = fVec2[0];
			fRec3[1] = fRec3[0];
			fVec3[1] = fVec3[0];
			fRec2[1] = fRec2[0];
		}
	}

};

#endif
