/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "ReverseDelay"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn ReverseDelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __ReverseDelay_H__
#define  __ReverseDelay_H__

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
#define FAUSTCLASS ReverseDelay
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


class ReverseDelay : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec1[2];
	int iRec2[2];
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	float fConst5;
	float fConst6;
	float fConst7;
	float fRec4[2];
	int IOTA0;
	float fVec1[262144];
	float fRec0[3];
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	
 public:
	ReverseDelay() {
	}
	
	ReverseDelay(const ReverseDelay&) = default;
	
	virtual ~ReverseDelay() = default;
	
	ReverseDelay& operator=(const ReverseDelay&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn ReverseDelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Windowed backwards playback with crossfaded read heads and feedback");
		m->declare("filename", "reverse-delay.dsp");
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
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "ReverseDelay");
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
		fConst1 = std::exp(-(5.0f / fConst0));
		fConst2 = 0.001f * (1.0f - fConst1);
		fConst3 = 44.1f / fConst0;
		fConst4 = 1.0f - fConst3;
		fConst5 = 1.0f / std::tan(14137.167f / fConst0);
		fConst6 = 1.0f - fConst5;
		fConst7 = 1.0f / (fConst5 + 1.0f);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(6e+02f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.4f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			iRec2[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0f;
		}
		IOTA0 = 0;
		for (int l5 = 0; l5 < 262144; l5 = faust_wrap_add(l5, 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec0[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec5[l7] = 0.0f;
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
	
	virtual ReverseDelay* clone() {
		return new ReverseDelay(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("ReverseDelay");
		ui_interface->addHorizontalSlider("Feedback", &fHslider1, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.9f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Mix", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "unit", "ms");
		ui_interface->addHorizontalSlider("Window Time", &fHslider0, FAUSTFLOAT(6e+02f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.5e+03f), FAUSTFLOAT(1e+01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst2 * static_cast<float>(fHslider0);
		float fSlow1 = fConst3 * static_cast<float>(fHslider1);
		float fSlow2 = fConst3 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec1[0] = fSlow0 + fConst1 * fRec1[1];
			float fTemp0 = std::min<float>(65532.0f, std::max<float>(256.0f, fConst0 * fRec1[0]));
			iRec2[0] = (faust_wrap_add(iVec0[1], iRec2[1])) % static_cast<int>(fTemp0);
			float fTemp1 = static_cast<float>(iRec2[0]);
			float fTemp2 = std::fmod(fTemp1 + 0.5f * fTemp0, fTemp0);
			fRec3[0] = fSlow1 + fConst4 * fRec3[1];
			fRec4[0] = -(fConst7 * (fConst6 * fRec4[1] - (fRec0[1] + fRec0[2])));
			float fTemp3 = static_cast<float>(input0[i0]);
			float fTemp4 = fTemp3 + tanhf(fRec4[0] * fRec3[0]);
			fVec1[IOTA0 & 262143] = fTemp4;
			float fTemp5 = 2.0f * fTemp2;
			int iTemp6 = static_cast<int>(fTemp5);
			float fTemp7 = std::floor(fTemp5);
			int iTemp8 = faust_wrap_mul(2, iRec2[0]);
			float fTemp9 = static_cast<float>(iTemp8);
			float fTemp10 = std::floor(fTemp9);
			fRec0[0] = 0.75f * ((fVec1[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp8)))) & 262143] * (fTemp10 + (1.0f - fTemp9)) + (fTemp9 - fTemp10) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp8, 1))))) & 262143]) * std::sin(3.1415927f * (fTemp1 / fTemp0)) + (fVec1[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp6)))) & 262143] * (fTemp7 + (1.0f - fTemp5)) + (fTemp5 - fTemp7) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp6, 1))))) & 262143]) * std::sin(3.1415927f * (fTemp2 / fTemp0)));
			fRec5[0] = fSlow2 + fConst4 * fRec5[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp3 * (1.0f - fRec5[0]) + fRec5[0] * fRec0[0]);
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			iRec2[1] = iRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec5[1] = fRec5[0];
		}
	}

};

#endif
