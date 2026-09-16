/* ------------------------------------------------------------
author: "Jatin Chowdhury (model), Faust port in hysteresis.lib"
license: "LGPL-2.1-or-later"
name: "Tape Hysteresis"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibTapeHysteresis -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibTapeHysteresis_H__
#define  __LibTapeHysteresis_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
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
#define FAUSTCLASS LibTapeHysteresis
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

static float LibTapeHysteresis_faustpower2_f(float value) {
	return value * value;
}

class LibTapeHysteresis : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec1[2];
	float fConst3;
	float fConst4;
	float fVec0[3];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec5[2];
	float fConst5;
	float fConst6;
	float fConst7;
	float fRec2[2];
	float fConst8;
	float fRec3[2];
	float fConst9;
	
 public:
	LibTapeHysteresis() {
	}
	
	LibTapeHysteresis(const LibTapeHysteresis&) = default;
	
	virtual ~LibTapeHysteresis() = default;
	
	LibTapeHysteresis& operator=(const LibTapeHysteresis&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Jatin Chowdhury (model), Faust port in hysteresis.lib");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibTapeHysteresis -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Jiles-Atherton magnetic hysteresis tape saturator (CHOW Tape port) - soft, dynamic tape compression");
		m->declare("family", "dirt");
		m->declare("filename", "lib-tape-hysteresis.dsp");
		m->declare("filters.lib/SVFTPT:author", "Dario Sanfilippo");
		m->declare("filters.lib/SVFTPT:copyright", "Copyright (C) 2024 Dario Sanfilippo <sanfilippo.dario@gmail.com>");
		m->declare("filters.lib/SVFTPT:license", "MIT");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("hysteresis.lib/author", "Thomas Mandolini");
		m->declare("hysteresis.lib/contributor", "Bart Brouns a.k.a magnetophon");
		m->declare("hysteresis.lib/ja_hysteresis:author", "Thomas Mandolini");
		m->declare("hysteresis.lib/ja_hysteresis:license", "LGPL-2.1-only");
		m->declare("hysteresis.lib/ja_processor:author", "Thomas Mandolini");
		m->declare("hysteresis.lib/ja_processor:license", "LGPL-2.1-only");
		m->declare("hysteresis.lib/name", "Faust Hysteresis Library");
		m->declare("hysteresis.lib/version", "1.0.1");
		m->declare("license", "LGPL-2.1-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Tape Hysteresis");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/hysteresis.lib hy.ja_processor");
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
		fConst3 = std::tan(21.991148f / fConst0);
		fConst4 = fConst3 + 1.4142271f;
		fConst5 = fConst3 * fConst4 + 1.0f;
		fConst6 = fConst3 / fConst5;
		fConst7 = 2.0f * fConst6;
		fConst8 = 2.0f * fConst3;
		fConst9 = 1.0f / fConst5;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(12.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(3.8e+02f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.25f);
		fHslider4 = static_cast<FAUSTFLOAT>(3.8e+02f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0f;
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
	
	virtual LibTapeHysteresis* clone() {
		return new LibTapeHysteresis(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Tape Hysteresis");
		ui_interface->declare(&fHslider0, "0", "");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("Drive", &fHslider0, FAUSTFLOAT(12.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->addHorizontalSlider("Saturation", &fHslider2, FAUSTFLOAT(3.8e+02f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider4, "2", "");
		ui_interface->addHorizontalSlider("Loop Width", &fHslider4, FAUSTFLOAT(3.8e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->addHorizontalSlider("Bias", &fHslider3, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "4", "");
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("Trim", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider0));
		float fSlow1 = fConst1 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider1));
		float fSlow2 = static_cast<float>(fHslider2);
		float fSlow3 = std::max<float>(fSlow2, 1e-06f);
		float fSlow4 = std::max<float>(7.2e+02f / fSlow3, 1e-09f);
		float fSlow5 = 1.0f / fSlow4;
		float fSlow6 = static_cast<float>(fHslider3);
		float fSlow7 = fSlow6 / fSlow4;
		float fSlow8 = 0.015f * fSlow7;
		float fSlow9 = static_cast<float>(fHslider4) / fSlow3;
		float fSlow10 = 7.2e+02f / std::max<float>(0.01f, fSlow2 * fSlow6);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			fRec1[0] = fSlow1 + fConst2 * fRec1[1];
			float fTemp0 = static_cast<float>(input0[i0]) * fRec0[0];
			fVec0[0] = fTemp0;
			float fTemp1 = fTemp0 - fVec0[1];
			float fTemp2 = 0.0004446953f * fTemp1;
			float fTemp3 = 0.00014823176f * fTemp1;
			float fTemp4 = 0.00049410586f * fTemp0;
			float fTemp5 = 0.002668172f * fVec0[1];
			float fTemp6 = fVec0[1] - fVec0[2];
			float fTemp7 = 0.0004446953f * fTemp6;
			float fTemp8 = tanhf(fSlow5 * (fTemp7 + fTemp5 + fTemp4 + 0.015f * fRec5[1] - fTemp3));
			float fTemp9 = 1.0f - LibTapeHysteresis_faustpower2_f(fTemp8);
			float fTemp10 = fTemp8 - fRec5[1];
			float fTemp11 = 3.0f * std::fabs(fTemp10) + 1.0f;
			float fTemp12 = fTemp7 + fTemp4 - (fTemp3 + 0.00049410586f * fVec0[1]);
			float fTemp13 = std::max<float>(-1.0f, std::min<float>(1.0f, fRec5[1] + fTemp12 * (fSlow7 * fTemp9 + fTemp10 / (fTemp11 * (fSlow9 * ((fTemp12 >= 0.0f) ? 1.0f : -1.0f) + (0.001f - 0.015f * (fTemp10 / fTemp11))))) / (1.0f - fSlow8 * fTemp9)));
			float fTemp14 = 0.0015811388f * (fTemp0 + fVec0[1]);
			float fTemp15 = 0.0003952847f * (fTemp6 - fTemp1);
			float fTemp16 = tanhf(fSlow5 * (fTemp15 + fTemp14 + 0.015f * fTemp13));
			float fTemp17 = 1.0f - LibTapeHysteresis_faustpower2_f(fTemp16);
			float fTemp18 = fTemp16 - fTemp13;
			float fTemp19 = 3.0f * std::fabs(fTemp18) + 1.0f;
			float fTemp20 = fTemp15 + fTemp3 + fTemp14 - (fTemp7 + fTemp5 + fTemp4);
			float fTemp21 = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp13 + fTemp20 * (fSlow7 * fTemp17 + fTemp18 / (fTemp19 * (fSlow9 * ((fTemp20 >= 0.0f) ? 1.0f : -1.0f) + (0.001f - 0.015f * (fTemp18 / fTemp19))))) / (1.0f - fSlow8 * fTemp17)));
			float fTemp22 = 0.00049410586f * fVec0[1];
			float fTemp23 = 0.00014823176f * fTemp6;
			float fTemp24 = fTemp23 + fTemp22 + 0.002668172f * fTemp0;
			float fTemp25 = tanhf(fSlow5 * (fTemp24 + 0.015f * fTemp21 - fTemp2));
			float fTemp26 = 1.0f - LibTapeHysteresis_faustpower2_f(fTemp25);
			float fTemp27 = fTemp25 - fTemp21;
			float fTemp28 = 3.0f * std::fabs(fTemp27) + 1.0f;
			float fTemp29 = fTemp24 - (fTemp15 + fTemp14 + fTemp2);
			float fTemp30 = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp21 + fTemp29 * (fSlow7 * fTemp26 + fTemp27 / (fTemp28 * (fSlow9 * ((fTemp29 >= 0.0f) ? 1.0f : -1.0f) + (0.001f - 0.015f * (fTemp27 / fTemp28))))) / (1.0f - fSlow8 * fTemp26)));
			float fTemp31 = tanhf(fSlow5 * (0.0031622776f * fTemp0 + 0.015f * fTemp30));
			float fTemp32 = 1.0f - LibTapeHysteresis_faustpower2_f(fTemp31);
			float fTemp33 = fTemp31 - fTemp30;
			float fTemp34 = 3.0f * std::fabs(fTemp33) + 1.0f;
			float fTemp35 = fTemp2 + 0.00049410586f * fTemp0 - (fTemp22 + fTemp23);
			fRec5[0] = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp30 + fTemp35 * (fSlow7 * fTemp32 + fTemp33 / (fTemp34 * (fSlow9 * ((fTemp35 >= 0.0f) ? 1.0f : -1.0f) + (0.001f - 0.015f * (fTemp33 / fTemp34))))) / (1.0f - fSlow8 * fTemp32)));
			float fTemp36 = fSlow10 * fRec5[0];
			float fTemp37 = fTemp36 - (fConst4 * fRec2[1] + fRec3[1]);
			fRec2[0] = fRec2[1] + fConst7 * fTemp37;
			float fTemp38 = fRec2[1] + fConst6 * fTemp37;
			fRec3[0] = fRec3[1] + fConst8 * fTemp38;
			float fTemp39 = fConst9 * fTemp37;
			float fRec4 = fTemp39;
			output0[i0] = static_cast<FAUSTFLOAT>(316.22775f * (fRec4 * fRec1[0] / std::max<float>(0.001f, fRec0[0])));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fVec0[2] = fVec0[1];
			fVec0[1] = fVec0[0];
			fRec5[1] = fRec5[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
