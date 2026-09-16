/* ------------------------------------------------------------
author: "Oleg Kapitonov"
license: "GPL-3.0-or-later"
name: "KPP Blue Dream"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn KppBluedream -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __KppBluedream_H__
#define  __KppBluedream_H__

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
#define FAUSTCLASS KppBluedream
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

static float KppBluedream_faustpower2_f(float value) {
	return value * value;
}

class KppBluedream : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	FAUSTFLOAT fHslider3;
	float fRec7[2];
	FAUSTFLOAT fHslider4;
	float fRec8[2];
	FAUSTFLOAT fHslider5;
	float fRec10[2];
	float fVec0[2];
	float fRec11[2];
	float fVec1[2];
	float fConst15;
	float fConst16;
	float fConst17;
	float fRec12[2];
	float fVec2[2];
	float fConst18;
	float fConst19;
	float fConst20;
	float fRec9[2];
	float fRec6[3];
	float fRec4[3];
	float fRec2[3];
	float fVec3[2];
	float fRec13[2];
	float fVec4[2];
	float fRec0[2];
	
 public:
	KppBluedream() {
	}
	
	KppBluedream(const KppBluedream&) = default;
	
	virtual ~KppBluedream() = default;
	
	KppBluedream& operator=(const KppBluedream&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Oleg Kapitonov");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn KppBluedream -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Booster/overdrive with voice knob (booster left, tube-screamer right), push-pull tube waveshaper and 3-band EQ");
		m->declare("family", "dirt");
		m->declare("filename", "kpp-bluedream.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/peak_eq:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "LicenseRef-STK-4.3");
		m->declare("license", "GPL-3.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "KPP Blue Dream");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_bluedream/kpp_bluedream.dsp");
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
		fConst3 = 56548.668f / (fConst0 * std::sin(62831.85f / fConst0));
		fConst4 = std::tan(31415.926f / fConst0);
		fConst5 = 1.0f / fConst4;
		fConst6 = 2.0f * (1.0f - 1.0f / KppBluedream_faustpower2_f(fConst4));
		fConst7 = 2199.1147f / (fConst0 * std::sin(3141.5928f / fConst0));
		fConst8 = std::tan(1570.7964f / fConst0);
		fConst9 = 1.0f / fConst8;
		fConst10 = 2.0f * (1.0f - 1.0f / KppBluedream_faustpower2_f(fConst8));
		fConst11 = 628.31854f / (fConst0 * std::sin(439.82297f / fConst0));
		fConst12 = std::tan(219.91148f / fConst0);
		fConst13 = 1.0f / fConst12;
		fConst14 = 2.0f * (1.0f - 1.0f / KppBluedream_faustpower2_f(fConst12));
		fConst15 = 1.0f / std::tan(2261.9468f / fConst0);
		fConst16 = 1.0f - fConst15;
		fConst17 = 1.0f / (fConst15 + 1.0f);
		fConst18 = 1.0f / std::tan(28274.334f / fConst0);
		fConst19 = 1.0f - fConst18;
		fConst20 = 1.0f / (fConst18 + 1.0f);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.8f);
		fHslider5 = static_cast<FAUSTFLOAT>(63.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec5[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec7[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec8[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec10[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec0[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec11[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fVec1[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec12[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec9[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 3; l12 = faust_wrap_add(l12, 1)) {
			fRec6[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = faust_wrap_add(l13, 1)) {
			fRec4[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = faust_wrap_add(l14, 1)) {
			fRec2[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fVec3[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec13[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fVec4[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec0[l18] = 0.0f;
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
	
	virtual KppBluedream* clone() {
		return new KppBluedream(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("KPP Blue Dream");
		ui_interface->declare(&fHslider5, "0", "");
		ui_interface->addHorizontalSlider("Drive", &fHslider5, FAUSTFLOAT(63.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->addHorizontalSlider("Voice", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("Bass", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("Middle", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider0, "4", "");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("Treble", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider4, "5", "");
		ui_interface->addHorizontalSlider("Volume", &fHslider4, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		float fSlow4 = fConst1 * static_cast<float>(fHslider4);
		float fSlow5 = fConst1 * static_cast<float>(fHslider5);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow0 + fConst2 * fRec1[1];
			int iTemp0 = fRec1[0] > 0.0f;
			float fTemp1 = fConst3 * std::pow(1e+01f, 0.05f * std::fabs(fRec1[0]));
			float fTemp2 = ((iTemp0) ? fConst3 : fTemp1);
			float fTemp3 = fConst5 * (fConst5 + fTemp2) + 1.0f;
			float fTemp4 = ((iTemp0) ? fTemp1 : fConst3);
			float fTemp5 = fConst6 * fRec2[1];
			fRec3[0] = fSlow1 + fConst2 * fRec3[1];
			int iTemp6 = fRec3[0] > 0.0f;
			float fTemp7 = fConst7 * std::pow(1e+01f, 0.05f * std::fabs(fRec3[0]));
			float fTemp8 = ((iTemp6) ? fConst7 : fTemp7);
			float fTemp9 = fConst9 * (fConst9 + fTemp8) + 1.0f;
			float fTemp10 = ((iTemp6) ? fTemp7 : fConst7);
			float fTemp11 = fConst10 * fRec4[1];
			fRec5[0] = fSlow2 + fConst2 * fRec5[1];
			int iTemp12 = fRec5[0] > 0.0f;
			float fTemp13 = fConst11 * std::pow(1e+01f, 0.05f * std::fabs(fRec5[0]));
			float fTemp14 = ((iTemp12) ? fConst11 : fTemp13);
			float fTemp15 = fConst13 * (fConst13 + fTemp14) + 1.0f;
			float fTemp16 = ((iTemp12) ? fTemp13 : fConst11);
			float fTemp17 = fConst14 * fRec6[1];
			fRec7[0] = fSlow3 + fConst2 * fRec7[1];
			fRec8[0] = fSlow4 + fConst2 * fRec8[1];
			fRec10[0] = fSlow5 + fConst2 * fRec10[1];
			float fTemp18 = 0.0075f * fRec10[0];
			float fTemp19 = std::max<float>(fRec7[0] - fTemp18, 0.0f);
			float fTemp20 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp20;
			fRec11[0] = fTemp20 + 0.995f * fRec11[1] - fVec0[1];
			float fTemp21 = std::max<float>(-2.0f, std::min<float>(2.0f, fRec11[0])) * (std::pow(1e+01f, 0.02f * fRec10[0] * (1.0f - 0.5f * fRec7[0])) + -1.0f);
			fVec1[0] = fTemp21;
			float fTemp22 = std::min<float>(fTemp18 + (1.0f - fRec7[0]), 1.0f);
			fRec12[0] = -(fConst17 * (fConst16 * fRec12[1] - fConst15 * (fTemp21 - fVec1[1])));
			float fTemp23 = fRec12[0] * fTemp22 + fTemp21 * fTemp19;
			fVec2[0] = fTemp23;
			fRec9[0] = -(fConst20 * (fConst19 * fRec9[1] - (fTemp23 + fVec2[1])));
			float fTemp24 = std::max<float>(-0.2f - fRec9[0], 0.0f) + 1.0f;
			float fTemp25 = std::max<float>(fRec9[0] + -0.2f, 0.0f) + 1.0f;
			fRec6[0] = 0.01f * (std::max<float>(0.0f, fRec9[0] / fTemp25 + 0.2f * (1.0f - 1.0f / fTemp25 + 1.0f)) - std::max<float>(0.0f, 0.2f * (1.0f - 1.0f / fTemp24 + 1.0f) - fRec9[0] / fTemp24)) * std::pow(1e+01f, 2.5f * fRec8[0] * (1.0f - 0.25f * fRec7[0])) - (fRec6[2] * (fConst13 * (fConst13 - fTemp14) + 1.0f) + fTemp17) / fTemp15;
			fRec4[0] = (fTemp17 + fRec6[0] * (fConst13 * (fConst13 + fTemp16) + 1.0f) + fRec6[2] * (fConst13 * (fConst13 - fTemp16) + 1.0f)) / fTemp15 - (fRec4[2] * (fConst9 * (fConst9 - fTemp8) + 1.0f) + fTemp11) / fTemp9;
			fRec2[0] = (fTemp11 + fRec4[0] * (fConst9 * (fConst9 + fTemp10) + 1.0f) + fRec4[2] * (fConst9 * (fConst9 - fTemp10) + 1.0f)) / fTemp9 - (fRec2[2] * (fConst5 * (fConst5 - fTemp2) + 1.0f) + fTemp5) / fTemp3;
			float fTemp26 = std::max<float>(-2.0f, std::min<float>(2.0f, (fTemp5 + fRec2[0] * (fConst5 * (fConst5 + fTemp4) + 1.0f) + fRec2[2] * (fConst5 * (fConst5 - fTemp4) + 1.0f)) / fTemp3));
			fVec3[0] = fTemp26;
			float fTemp27 = fTemp19 * fTemp26;
			fRec13[0] = -(fConst17 * (fConst16 * fRec13[1] - (fTemp26 + fVec3[1])));
			float fTemp28 = fRec13[0] * fTemp22;
			fVec4[0] = fTemp28 + fTemp27;
			fRec0[0] = fTemp27 + 0.995f * fRec0[1] + fTemp28 - fVec4[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fRec0[0]);
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			fVec0[1] = fVec0[0];
			fRec11[1] = fRec11[0];
			fVec1[1] = fVec1[0];
			fRec12[1] = fRec12[0];
			fVec2[1] = fVec2[0];
			fRec9[1] = fRec9[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fVec3[1] = fVec3[0];
			fRec13[1] = fRec13[0];
			fVec4[1] = fVec4[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
