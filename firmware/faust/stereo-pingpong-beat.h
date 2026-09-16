/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "MultiTapBeatDelay"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn StereoPingpongBeat -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __StereoPingpongBeat_H__
#define  __StereoPingpongBeat_H__

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
#define FAUSTCLASS StereoPingpongBeat
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


class StereoPingpongBeat : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	int IOTA0;
	float fVec0[65536];
	float fConst3;
	FAUSTFLOAT fHslider1;
	float fConst4;
	float fRec2[2];
	float fConst5;
	float fVec1[2];
	float fConst6;
	float fConst7;
	float fConst8;
	float fRec1[2];
	FAUSTFLOAT fHslider2;
	float fRec4[2];
	float fConst9;
	float fConst10;
	float fConst11;
	float fRec6[2];
	float fConst12;
	float fConst13;
	float fConst14;
	float fRec5[2];
	float fVec2[65536];
	float fRec3[3];
	
 public:
	StereoPingpongBeat() {
	}
	
	StereoPingpongBeat(const StereoPingpongBeat&) = default;
	
	virtual ~StereoPingpongBeat() = default;
	
	StereoPingpongBeat& operator=(const StereoPingpongBeat&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn StereoPingpongBeat -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Rhythmic two-tap delay (straight + dotted) with filtered feedback");
		m->declare("filename", "stereo-pingpong-beat.dsp");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
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
		m->declare("name", "MultiTapBeatDelay");
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
		fConst3 = std::exp(-(1e+01f / fConst0));
		fConst4 = 0.001f * (1.0f - fConst3);
		fConst5 = 0.75f * fConst0;
		fConst6 = 1.0f / std::tan(10995.574f / fConst0);
		fConst7 = 1.0f - fConst6;
		fConst8 = 1.0f / (fConst6 + 1.0f);
		fConst9 = 1.0f / std::tan(15707.963f / fConst0);
		fConst10 = 1.0f - fConst9;
		fConst11 = 1.0f / (fConst9 + 1.0f);
		fConst12 = 1.0f / std::tan(376.99112f / fConst0);
		fConst13 = 1.0f - fConst12;
		fConst14 = 1.0f / (fConst12 + 1.0f);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.8f);
		fHslider1 = static_cast<FAUSTFLOAT>(2.4e+02f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.45f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 65536; l1 = faust_wrap_add(l1, 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0f;
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
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec5[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 65536; l8 = faust_wrap_add(l8, 1)) {
			fVec2[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec3[l9] = 0.0f;
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
	
	virtual StereoPingpongBeat* clone() {
		return new StereoPingpongBeat(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("MultiTapBeatDelay");
		ui_interface->addHorizontalSlider("Dotted Tap", &fHslider0, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Feedback", &fHslider2, FAUSTFLOAT(0.45f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.9f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "unit", "ms");
		ui_interface->addHorizontalSlider("Tempo / Time", &fHslider1, FAUSTFLOAT(2.4e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(6e+02f), FAUSTFLOAT(5.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst4 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = static_cast<float>(input0[i0]);
			fVec0[IOTA0 & 65535] = fTemp0;
			fRec2[0] = fSlow1 + fConst3 * fRec2[1];
			float fTemp1 = std::min<float>(65532.0f, fConst5 * fRec2[0]);
			int iTemp2 = static_cast<int>(fTemp1);
			float fTemp3 = std::floor(fTemp1);
			float fTemp4 = fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp2)))) & 65535] * (fTemp3 + (1.0f - fTemp1)) + (fTemp1 - fTemp3) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp2, 1))))) & 65535];
			fVec1[0] = fTemp4;
			fRec1[0] = -(fConst8 * (fConst7 * fRec1[1] - (fTemp4 + fVec1[1])));
			fRec4[0] = fSlow2 + fConst2 * fRec4[1];
			fRec6[0] = -(fConst11 * (fConst10 * fRec6[1] - (fRec3[1] + fRec3[2])));
			fRec5[0] = -(fConst14 * (fConst13 * fRec5[1] - fConst12 * (fRec6[0] - fRec6[1])));
			float fTemp5 = fTemp0 + fRec5[0] * fRec4[0];
			fVec2[IOTA0 & 65535] = fTemp5;
			float fTemp6 = std::min<float>(65532.0f, fConst0 * fRec2[0]);
			int iTemp7 = static_cast<int>(fTemp6);
			float fTemp8 = std::floor(fTemp6);
			fRec3[0] = fVec2[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp7)))) & 65535] * (fTemp8 + (1.0f - fTemp6)) + (fTemp6 - fTemp8) * fVec2[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp7, 1))))) & 65535];
			output0[i0] = static_cast<FAUSTFLOAT>(0.9f * fTemp0 + 0.65f * fRec3[0] + 0.45f * fRec1[0] * fRec0[0]);
			fRec0[1] = fRec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec2[1] = fRec2[0];
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
