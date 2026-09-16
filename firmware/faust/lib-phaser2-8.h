/* ------------------------------------------------------------
author: "Julius O. Smith III"
license: "LicenseRef-STK-4.3"
name: "Phaser 8 Notch"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibPhaser28 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibPhaser28_H__
#define  __LibPhaser28_H__

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
#define FAUSTCLASS LibPhaser28
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

static float LibPhaser28_faustpower8_f(float value) {
	return value * value * value * value * value * value * value * value;
}
static float LibPhaser28_faustpower7_f(float value) {
	return value * value * value * value * value * value * value;
}
static float LibPhaser28_faustpower6_f(float value) {
	return value * value * value * value * value * value;
}
static float LibPhaser28_faustpower5_f(float value) {
	return value * value * value * value * value;
}
static float LibPhaser28_faustpower4_f(float value) {
	return value * value * value * value;
}
static float LibPhaser28_faustpower3_f(float value) {
	return value * value * value;
}
static float LibPhaser28_faustpower2_f(float value) {
	return value * value;
}

class LibPhaser28 : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec3[2];
	float fConst3;
	float fRec1[2];
	float fRec2[2];
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fConst4;
	FAUSTFLOAT fHslider4;
	float fRec12[2];
	float fConst5;
	FAUSTFLOAT fHslider5;
	float fRec13[2];
	float fRec11[3];
	float fRec10[3];
	float fRec9[3];
	float fRec8[3];
	float fRec7[3];
	float fRec6[3];
	float fRec5[3];
	float fRec4[3];
	float fRec0[2];
	FAUSTFLOAT fHslider6;
	float fRec14[2];
	
 public:
	LibPhaser28() {
	}
	
	LibPhaser28(const LibPhaser28&) = default;
	
	virtual ~LibPhaser28() = default;
	
	LibPhaser28& operator=(const LibPhaser28&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Julius O. Smith III");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibPhaser28 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "JOS phaser2 with 8 swept notches, feedback and depth - thick, deep phase sweep");
		m->declare("family", "mod");
		m->declare("filename", "lib-phaser2-8.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "LicenseRef-STK-4.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Phaser 8 Notch");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("phaflangers.lib/name", "Faust Phaser and Flanger Library");
		m->declare("phaflangers.lib/version", "1.1.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/phaflangers.lib pf.phaser2_mono");
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
		fConst3 = 6.2831855f / fConst0;
		fConst4 = 1.0f / fConst0;
		fConst5 = 3.1415927f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider1 = static_cast<FAUSTFLOAT>(8e+02f);
		fHslider2 = static_cast<FAUSTFLOAT>(1e+02f);
		fHslider3 = static_cast<FAUSTFLOAT>(1.5f);
		fHslider4 = static_cast<FAUSTFLOAT>(1e+03f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider6 = static_cast<FAUSTFLOAT>(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec12[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec13[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec11[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec10[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec9[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec7[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 3; l11 = faust_wrap_add(l11, 1)) {
			fRec6[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 3; l12 = faust_wrap_add(l12, 1)) {
			fRec5[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = faust_wrap_add(l13, 1)) {
			fRec4[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec0[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec14[l15] = 0.0f;
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
	
	virtual LibPhaser28* clone() {
		return new LibPhaser28(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Phaser 8 Notch");
		ui_interface->declare(&fHslider0, "0", "");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("Speed", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider6, "1", "");
		ui_interface->addHorizontalSlider("Depth", &fHslider6, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider5, "2", "");
		ui_interface->addHorizontalSlider("Feedback", &fHslider5, FAUSTFLOAT(0.3f), FAUSTFLOAT(-0.95f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider4, "3", "");
		ui_interface->declare(&fHslider4, "scale", "log");
		ui_interface->declare(&fHslider4, "unit", "Hz");
		ui_interface->addHorizontalSlider("Notch Width", &fHslider4, FAUSTFLOAT(1e+03f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(5e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "4", "");
		ui_interface->declare(&fHslider2, "scale", "log");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("Min Notch", &fHslider2, FAUSTFLOAT(1e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(5e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "5", "");
		ui_interface->declare(&fHslider1, "scale", "log");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Max Notch", &fHslider1, FAUSTFLOAT(8e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "6", "");
		ui_interface->addHorizontalSlider("Notch Ratio", &fHslider3, FAUSTFLOAT(1.5f), FAUSTFLOAT(1.1f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = static_cast<float>(fHslider2);
		float fSlow2 = 3.1415927f * (fSlow1 - static_cast<float>(fHslider1));
		float fSlow3 = 6.2831855f * fSlow1;
		float fSlow4 = static_cast<float>(fHslider3);
		float fSlow5 = fConst4 * LibPhaser28_faustpower8_f(fSlow4);
		float fSlow6 = fConst4 * LibPhaser28_faustpower7_f(fSlow4);
		float fSlow7 = fConst4 * LibPhaser28_faustpower6_f(fSlow4);
		float fSlow8 = fConst4 * LibPhaser28_faustpower5_f(fSlow4);
		float fSlow9 = fConst4 * LibPhaser28_faustpower4_f(fSlow4);
		float fSlow10 = fConst4 * LibPhaser28_faustpower3_f(fSlow4);
		float fSlow11 = fConst4 * LibPhaser28_faustpower2_f(fSlow4);
		float fSlow12 = fConst4 * fSlow4;
		float fSlow13 = fConst1 * static_cast<float>(fHslider4);
		float fSlow14 = fConst1 * static_cast<float>(fHslider5);
		float fSlow15 = fConst1 * static_cast<float>(fHslider6);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec3[0] = fSlow0 + fConst2 * fRec3[1];
			float fTemp0 = fConst3 * fRec3[0];
			float fTemp1 = std::cos(fTemp0);
			float fTemp2 = std::sin(fTemp0);
			fRec1[0] = fRec2[1] * fTemp2 + fRec1[1] * fTemp1;
			fRec2[0] = static_cast<float>(faust_wrap_sub(1, iVec0[1])) + fRec2[1] * fTemp1 - fTemp2 * fRec1[1];
			float fTemp3 = fSlow3 - fSlow2 * (1.0f - fRec1[0]);
			float fTemp4 = std::cos(fSlow5 * fTemp3);
			float fTemp5 = fRec5[1] * std::cos(fSlow6 * fTemp3);
			float fTemp6 = fRec6[1] * std::cos(fSlow7 * fTemp3);
			float fTemp7 = fRec7[1] * std::cos(fSlow8 * fTemp3);
			float fTemp8 = fRec8[1] * std::cos(fSlow9 * fTemp3);
			float fTemp9 = fRec9[1] * std::cos(fSlow10 * fTemp3);
			float fTemp10 = fRec10[1] * std::cos(fSlow11 * fTemp3);
			float fTemp11 = std::cos(fSlow12 * fTemp3);
			fRec12[0] = fSlow13 + fConst2 * fRec12[1];
			float fTemp12 = std::exp(-(fConst5 * fRec12[0]));
			float fTemp13 = LibPhaser28_faustpower2_f(fTemp12);
			fRec13[0] = fSlow14 + fConst2 * fRec13[1];
			float fTemp14 = static_cast<float>(input0[i0]);
			fRec11[0] = fTemp14 + fRec13[0] * fRec0[1] + 2.0f * fRec11[1] * fTemp12 * fTemp11 - fRec11[2] * fTemp13;
			fRec10[0] = fRec11[2] + fTemp13 * (fRec11[0] - fRec10[2]) - 2.0f * fTemp12 * (fRec11[1] * fTemp11 - fTemp10);
			fRec9[0] = fRec10[2] + fTemp13 * (fRec10[0] - fRec9[2]) - 2.0f * fTemp12 * (fTemp10 - fTemp9);
			fRec8[0] = fRec9[2] + fTemp13 * (fRec9[0] - fRec8[2]) - 2.0f * fTemp12 * (fTemp9 - fTemp8);
			fRec7[0] = fRec8[2] + fTemp13 * (fRec8[0] - fRec7[2]) - 2.0f * fTemp12 * (fTemp8 - fTemp7);
			fRec6[0] = fRec7[2] + fTemp13 * (fRec7[0] - fRec6[2]) - 2.0f * fTemp12 * (fTemp7 - fTemp6);
			fRec5[0] = fRec6[2] + fTemp13 * (fRec6[0] - fRec5[2]) - 2.0f * fTemp12 * (fTemp6 - fTemp5);
			fRec4[0] = fRec5[2] + fTemp13 * (fRec5[0] - fRec4[2]) - 2.0f * fTemp12 * (fTemp5 - fRec4[1] * fTemp4);
			fRec0[0] = fRec4[2] + fRec4[0] * fTemp13 - 2.0f * fTemp12 * fRec4[1] * fTemp4;
			fRec14[0] = fSlow15 + fConst2 * fRec14[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp14 * (1.0f - 0.5f * fRec14[0]) + 0.5f * fRec14[0] * fRec0[0]);
			iVec0[1] = iVec0[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec0[1] = fRec0[0];
			fRec14[1] = fRec14[0];
		}
	}

};

#endif
