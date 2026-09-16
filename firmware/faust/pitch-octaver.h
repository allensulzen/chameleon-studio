/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "PitchOctaver"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn PitchOctaver -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __PitchOctaver_H__
#define  __PitchOctaver_H__

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
#define FAUSTCLASS PitchOctaver
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

static float PitchOctaver_faustpower2_f(float value) {
	return value * value;
}

class PitchOctaver : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	float fRec2[2];
	int IOTA0;
	float fVec0[131072];
	float fVec1[2];
	float fConst3;
	float fConst4;
	float fConst5;
	float fRec1[2];
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fRec4[2];
	float fRec3[3];
	FAUSTFLOAT fHslider1;
	float fRec5[2];
	float fConst12;
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	
 public:
	PitchOctaver() {
	}
	
	PitchOctaver(const PitchOctaver&) = default;
	
	virtual ~PitchOctaver() = default;
	
	PitchOctaver& operator=(const PitchOctaver&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn PitchOctaver -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Polyphonic sub-octave and upper-octave blend");
		m->declare("filename", "pitch-octaver.dsp");
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
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "PitchOctaver");
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
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.0f / std::tan(502.65482f / fConst0);
		fConst4 = 1.0f - fConst3;
		fConst5 = 1.0f / (fConst3 + 1.0f);
		fConst6 = std::tan(5654.8667f / fConst0);
		fConst7 = 2.0f * (1.0f - 1.0f / PitchOctaver_faustpower2_f(fConst6));
		fConst8 = 1.0f / fConst6;
		fConst9 = (fConst8 + -1.4142135f) / fConst6 + 1.0f;
		fConst10 = (fConst8 + 1.4142135f) / fConst6 + 1.0f;
		fConst11 = 1.0f / fConst10;
		fConst12 = 0.7f / fConst10;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.4f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.7f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec2[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 131072; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec5[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec6[l8] = 0.0f;
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
	
	virtual PitchOctaver* clone() {
		return new PitchOctaver(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("PitchOctaver");
		ui_interface->addHorizontalSlider("Dry", &fHslider2, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Sub", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Up", &fHslider0, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			fRec2[0] = std::fmod(fRec2[1] + 1023.0f, 1024.0f);
			float fTemp0 = std::min<float>(0.00390625f * fRec2[0], 1.0f);
			float fTemp1 = fRec2[0] + 1024.0f;
			float fTemp2 = std::floor(fTemp1);
			float fTemp3 = static_cast<float>(input0[i0]);
			fVec0[IOTA0 & 131071] = fTemp3;
			int iTemp4 = static_cast<int>(fTemp1);
			int iTemp5 = static_cast<int>(fRec2[0]);
			float fTemp6 = std::floor(fRec2[0]);
			float fTemp7 = (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp5)))) & 131071] * (fTemp6 + (1.0f - fRec2[0])) + (fRec2[0] - fTemp6) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp5, 1))))) & 131071]) * fTemp0 + (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp4)))) & 131071] * (fTemp2 + (-1023.0f - fRec2[0])) + fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp4, 1))))) & 131071] * (fRec2[0] + (1024.0f - fTemp2))) * (1.0f - fTemp0);
			fVec1[0] = fTemp7;
			fRec1[0] = -(fConst5 * (fConst4 * fRec1[1] - fConst3 * (fTemp7 - fVec1[1])));
			fRec4[0] = std::fmod(fRec4[1] + 2048.5f, 2048.0f);
			float fTemp8 = std::min<float>(0.001953125f * fRec4[0], 1.0f);
			float fTemp9 = fRec4[0] + 2048.0f;
			float fTemp10 = std::floor(fTemp9);
			int iTemp11 = static_cast<int>(fTemp9);
			int iTemp12 = static_cast<int>(fRec4[0]);
			float fTemp13 = std::floor(fRec4[0]);
			fRec3[0] = (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp12)))) & 131071] * (fTemp13 + (1.0f - fRec4[0])) + (fRec4[0] - fTemp13) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp12, 1))))) & 131071]) * fTemp8 + (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp11)))) & 131071] * (fTemp10 + (-2047.0f - fRec4[0])) + fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp11, 1))))) & 131071] * (fRec4[0] + (2048.0f - fTemp10))) * (1.0f - fTemp8) - fConst11 * (fConst9 * fRec3[2] + fConst7 * fRec3[1]);
			fRec5[0] = fSlow1 + fConst2 * fRec5[1];
			fRec6[0] = fSlow2 + fConst2 * fRec6[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp3 * fRec6[0] + fConst12 * fRec5[0] * (fRec3[2] + fRec3[0] + 2.0f * fRec3[1]) + 0.6f * fRec1[0] * fRec0[0]);
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
		}
	}

};

#endif
