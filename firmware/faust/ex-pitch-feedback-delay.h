/* ------------------------------------------------------------
author: "GRAME (Bela examples)"
license: "LGPL-2.1-or-later"
name: "Pitch Feedback Delay"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn ExPitchFeedbackDelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __ExPitchFeedbackDelay_H__
#define  __ExPitchFeedbackDelay_H__

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
#define FAUSTCLASS ExPitchFeedbackDelay
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

static float ExPitchFeedbackDelay_faustpower2_f(float value) {
	return value * value;
}

class ExPitchFeedbackDelay : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	float fConst3;
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	float fRec5[2];
	int IOTA0;
	FAUSTFLOAT fHslider3;
	float fRec7[2];
	float fRec4[3];
	float fRec2[3];
	float fVec0[131072];
	FAUSTFLOAT fHslider4;
	float fRec12[2];
	float fRec8[2];
	float fRec9[2];
	float fRec10[2];
	float fRec11[2];
	float fVec1[131072];
	FAUSTFLOAT fHslider5;
	float fRec17[2];
	float fRec13[2];
	float fRec14[2];
	float fRec15[2];
	float fRec16[2];
	float fRec0[131072];
	FAUSTFLOAT fHslider6;
	float fRec18[2];
	
 public:
	ExPitchFeedbackDelay() {
	}
	
	ExPitchFeedbackDelay(const ExPitchFeedbackDelay&) = default;
	
	virtual ~ExPitchFeedbackDelay() = default;
	
	ExPitchFeedbackDelay& operator=(const ExPitchFeedbackDelay&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "GRAME (Bela examples)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn ExPitchFeedbackDelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Mono version of the Bela crossDelay2 example: pre-delay, filtered feedback and a pitch shifter inside the loop - each repeat climbs or falls");
		m->declare("family", "time");
		m->declare("filename", "ex-pitch-feedback-delay.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass0_highpass1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "LGPL-2.1-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "Pitch Feedback Delay");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faust/examples/bela/crossDelay2.dsp");
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
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(8e+01f);
		fHslider1 = static_cast<FAUSTFLOAT>(6e+03f);
		fHslider2 = static_cast<FAUSTFLOAT>(5.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider5 = static_cast<FAUSTFLOAT>(4e+02f);
		fHslider6 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec6[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec5[l3] = 0.0f;
		}
		IOTA0 = 0;
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec7[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 131072; l7 = faust_wrap_add(l7, 1)) {
			fVec0[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec12[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 131072; l13 = faust_wrap_add(l13, 1)) {
			fVec1[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec17[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec13[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 131072; l19 = faust_wrap_add(l19, 1)) {
			fRec0[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec18[l20] = 0.0f;
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
	
	virtual ExPitchFeedbackDelay* clone() {
		return new ExPitchFeedbackDelay(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Pitch Feedback Delay");
		ui_interface->declare(&fHslider4, "0", "");
		ui_interface->declare(&fHslider4, "unit", "ms");
		ui_interface->addHorizontalSlider("Pre-Delay", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider5, "1", "");
		ui_interface->declare(&fHslider5, "unit", "ms");
		ui_interface->addHorizontalSlider("Delay", &fHslider5, FAUSTFLOAT(4e+02f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->addHorizontalSlider("Feedback", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->declare(&fHslider1, "scale", "log");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Feedback Lowpass", &fHslider1, FAUSTFLOAT(6e+03f), FAUSTFLOAT(2e+02f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "4", "");
		ui_interface->declare(&fHslider0, "scale", "log");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("Feedback Highpass", &fHslider0, FAUSTFLOAT(8e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "5", "");
		ui_interface->declare(&fHslider2, "unit", "semi");
		ui_interface->addHorizontalSlider("Shift", &fHslider2, FAUSTFLOAT(5.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider6, "6", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider6, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		float fSlow4 = 0.0441f * static_cast<float>(fHslider4);
		float fSlow5 = 0.0441f * static_cast<float>(fHslider5);
		float fSlow6 = fConst1 * static_cast<float>(fHslider6);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow0 + fConst2 * fRec1[1];
			float fTemp0 = std::tan(fConst3 * fRec1[0]);
			float fTemp1 = 1.0f / fTemp0;
			float fTemp2 = (fTemp1 + 1.4142135f) / fTemp0 + 1.0f;
			float fTemp3 = ExPitchFeedbackDelay_faustpower2_f(fTemp0);
			fRec3[0] = fSlow1 + fConst2 * fRec3[1];
			float fTemp4 = std::tan(fConst3 * fRec3[0]);
			float fTemp5 = 1.0f / fTemp4;
			float fTemp6 = (fTemp5 + 1.4142135f) / fTemp4 + 1.0f;
			fRec6[0] = fSlow2 + fConst2 * fRec6[1];
			fRec5[0] = std::fmod(fRec5[1] + (513.0f - std::pow(2.0f, 0.083333336f * fRec6[0])), 512.0f);
			float fTemp7 = std::min<float>(0.00390625f * fRec5[0], 1.0f);
			float fTemp8 = fRec5[0] + 512.0f;
			int iTemp9 = static_cast<int>(fTemp8);
			float fTemp10 = std::floor(fTemp8);
			int iTemp11 = static_cast<int>(fRec5[0]);
			float fTemp12 = std::floor(fRec5[0]);
			fRec7[0] = fSlow3 + fConst2 * fRec7[1];
			fRec4[0] = fRec7[0] * ((fRec0[(faust_wrap_sub(IOTA0, faust_wrap_add(std::min<int>(65537, std::max<int>(0, iTemp11)), 1))) & 131071] * (fTemp12 + (1.0f - fRec5[0])) + (fRec5[0] - fTemp12) * fRec0[(faust_wrap_sub(IOTA0, faust_wrap_add(std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp11, 1))), 1))) & 131071]) * fTemp7 + (fRec0[(faust_wrap_sub(IOTA0, faust_wrap_add(std::min<int>(65537, std::max<int>(0, iTemp9)), 1))) & 131071] * (fTemp10 + (-511.0f - fRec5[0])) + (fRec5[0] + (512.0f - fTemp10)) * fRec0[(faust_wrap_sub(IOTA0, faust_wrap_add(std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp9, 1))), 1))) & 131071]) * (1.0f - fTemp7)) - (fRec4[2] * ((fTemp5 + -1.4142135f) / fTemp4 + 1.0f) + 2.0f * fRec4[1] * (1.0f - 1.0f / ExPitchFeedbackDelay_faustpower2_f(fTemp4))) / fTemp6;
			fRec2[0] = (fRec4[2] + fRec4[0] + 2.0f * fRec4[1]) / fTemp6 - (fRec2[2] * ((fTemp1 + -1.4142135f) / fTemp0 + 1.0f) + 2.0f * fRec2[1] * (1.0f - 1.0f / fTemp3)) / fTemp2;
			float fTemp13 = static_cast<float>(input0[i0]);
			fVec0[IOTA0 & 131071] = fTemp13;
			fRec12[0] = fSlow4 + fConst2 * fRec12[1];
			float fTemp14 = ((fRec8[1] != 0.0f) ? (((fRec9[1] > 0.0f) & (fRec9[1] < 1.0f)) ? fRec8[1] : 0.0f) : (((fRec9[1] == 0.0f) & (fRec12[0] != fRec10[1])) ? 0.001953125f : (((fRec9[1] == 1.0f) & (fRec12[0] != fRec11[1])) ? -0.001953125f : 0.0f)));
			fRec8[0] = fTemp14;
			fRec9[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec9[1] + fTemp14));
			fRec10[0] = (((fRec9[1] >= 1.0f) & (fRec11[1] != fRec12[0])) ? fRec12[0] : fRec10[1]);
			fRec11[0] = (((fRec9[1] <= 0.0f) & (fRec10[1] != fRec12[0])) ? fRec12[0] : fRec11[1]);
			float fTemp15 = fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(65536.0f, std::max<float>(0.0f, fRec10[0]))))) & 131071];
			float fTemp16 = fTemp15 + fRec9[0] * (fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(65536.0f, std::max<float>(0.0f, fRec11[0]))))) & 131071] - fTemp15) + (fRec2[2] + (fRec2[0] - 2.0f * fRec2[1])) / (fTemp3 * fTemp2);
			fVec1[IOTA0 & 131071] = fTemp16;
			fRec17[0] = fSlow5 + fConst2 * fRec17[1];
			float fTemp17 = ((fRec13[1] != 0.0f) ? (((fRec14[1] > 0.0f) & (fRec14[1] < 1.0f)) ? fRec13[1] : 0.0f) : (((fRec14[1] == 0.0f) & (fRec17[0] != fRec15[1])) ? 0.001953125f : (((fRec14[1] == 1.0f) & (fRec17[0] != fRec16[1])) ? -0.001953125f : 0.0f)));
			fRec13[0] = fTemp17;
			fRec14[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec14[1] + fTemp17));
			fRec15[0] = (((fRec14[1] >= 1.0f) & (fRec16[1] != fRec17[0])) ? fRec17[0] : fRec15[1]);
			fRec16[0] = (((fRec14[1] <= 0.0f) & (fRec15[1] != fRec17[0])) ? fRec17[0] : fRec16[1]);
			float fTemp18 = fVec1[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(65536.0f, std::max<float>(0.0f, fRec15[0]))))) & 131071];
			fRec0[IOTA0 & 131071] = fTemp18 + fRec14[0] * (fVec1[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(65536.0f, std::max<float>(0.0f, fRec16[0]))))) & 131071] - fTemp18);
			fRec18[0] = fSlow6 + fConst2 * fRec18[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp13 * (1.0f - fRec18[0]) + fRec18[0] * fRec0[IOTA0 & 131071]);
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec7[1] = fRec7[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec12[1] = fRec12[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec17[1] = fRec17[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec18[1] = fRec18[0];
		}
	}

};

#endif
