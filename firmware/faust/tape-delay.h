/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "TapeDelay"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TapeDelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TapeDelay_H__
#define  __TapeDelay_H__

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
#define FAUSTCLASS TapeDelay
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

class TapeDelaySIG0 {
	
  private:
	
	int iVec2[2];
	int iRec4[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsTapeDelaySIG0() {
		return 0;
	}
	int getNumOutputsTapeDelaySIG0() {
		return 1;
	}
	
	void instanceInitTapeDelaySIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			iVec2[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			iRec4[l6] = 0;
		}
	}
	
	void fillTapeDelaySIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec2[0] = 1;
			iRec4[0] = (faust_wrap_add(iVec2[1], iRec4[1])) % 65536;
			table[i1] = std::sin(9.58738e-05f * static_cast<float>(iRec4[0]));
			iVec2[1] = iVec2[0];
			iRec4[1] = iRec4[0];
		}
	}

};

static TapeDelaySIG0* newTapeDelaySIG0() { return (TapeDelaySIG0*)new TapeDelaySIG0(); }
static void deleteTapeDelaySIG0(TapeDelaySIG0* dsp) { delete dsp; }

static float DSY_SDRAM_BSS ftbl0TapeDelaySIG0[65536];

class TapeDelay : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	float fConst3;
	float fConst4;
	float fConst5;
	float fRec3[2];
	float fConst6;
	float fConst7;
	float fConst8;
	float fRec2[2];
	int IOTA0;
	float fVec1[65536];
	float fConst9;
	float fRec5[2];
	float fConst10;
	float fRec6[2];
	float fConst11;
	FAUSTFLOAT fHslider1;
	float fConst12;
	float fRec7[2];
	float fRec0[3];
	FAUSTFLOAT fHslider2;
	float fRec8[2];
	
 public:
	TapeDelay() {
	}
	
	TapeDelay(const TapeDelay&) = default;
	
	virtual ~TapeDelay() = default;
	
	TapeDelay& operator=(const TapeDelay&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TapeDelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Tape echo: wow/flutter, saturated repeats, dark feedback path");
		m->declare("filename", "tape-delay.dsp");
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
		m->declare("name", "TapeDelay");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
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
		TapeDelaySIG0* sig0 = newTapeDelaySIG0();
		sig0->instanceInitTapeDelaySIG0(sample_rate);
		sig0->fillTapeDelaySIG0(65536, ftbl0TapeDelaySIG0);
		deleteTapeDelaySIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.0f / std::tan(10681.415f / fConst0);
		fConst4 = 1.0f - fConst3;
		fConst5 = 1.0f / (fConst3 + 1.0f);
		fConst6 = 1.0f / std::tan(345.5752f / fConst0);
		fConst7 = 1.0f - fConst6;
		fConst8 = 1.0f / (fConst6 + 1.0f);
		fConst9 = 6.3f / fConst0;
		fConst10 = 0.55f / fConst0;
		fConst11 = std::exp(-(8.333333f / fConst0));
		fConst12 = 0.001f * (1.0f - fConst11);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider1 = static_cast<FAUSTFLOAT>(4.2e+02f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.45f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec2[l3] = 0.0f;
		}
		IOTA0 = 0;
		for (int l4 = 0; l4 < 65536; l4 = faust_wrap_add(l4, 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec5[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec0[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec8[l11] = 0.0f;
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
	
	virtual TapeDelay* clone() {
		return new TapeDelay(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("TapeDelay");
		ui_interface->addHorizontalSlider("Feedback", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Mix", &fHslider2, FAUSTFLOAT(0.45f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "unit", "ms");
		ui_interface->addHorizontalSlider("Time", &fHslider1, FAUSTFLOAT(4.2e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(1.2e+03f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst12 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec1[0] = fSlow0 + fConst2 * fRec1[1];
			fRec3[0] = -(fConst5 * (fConst4 * fRec3[1] - (fRec0[1] + fRec0[2])));
			fRec2[0] = -(fConst8 * (fConst7 * fRec2[1] - fConst6 * (fRec3[0] - fRec3[1])));
			float fTemp0 = static_cast<float>(input0[i0]);
			float fTemp1 = tanhf(1.4f * (fTemp0 + 1.15f * fRec2[0] * fRec1[0]));
			fVec1[IOTA0 & 65535] = fTemp1;
			int iTemp2 = faust_wrap_sub(1, iVec0[1]);
			float fTemp3 = ((iTemp2) ? 0.0f : fConst9 + fRec5[1]);
			fRec5[0] = fTemp3 - std::floor(fTemp3);
			float fTemp4 = ((iTemp2) ? 0.0f : fConst10 + fRec6[1]);
			fRec6[0] = fTemp4 - std::floor(fTemp4);
			fRec7[0] = fSlow1 + fConst11 * fRec7[1];
			float fTemp5 = std::min<float>(65532.0f, fConst0 * fRec7[0] * (0.0025f * ftbl0TapeDelaySIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec6[0]), 65535))] + 0.0004f * ftbl0TapeDelaySIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec5[0]), 65535))] + 1.0f));
			int iTemp6 = static_cast<int>(fTemp5);
			float fTemp7 = std::floor(fTemp5);
			fRec0[0] = 0.71428573f * (fVec1[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp6)))) & 65535] * (fTemp7 + (1.0f - fTemp5)) + (fTemp5 - fTemp7) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp6, 1))))) & 65535]);
			fRec8[0] = fSlow2 + fConst2 * fRec8[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec8[0]) + fRec8[0] * fRec0[0]);
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec8[1] = fRec8[0];
		}
	}

};

#endif
