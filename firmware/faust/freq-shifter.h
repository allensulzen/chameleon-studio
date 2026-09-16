/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "FrequencyShifter"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn FreqShifter -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FreqShifter_H__
#define  __FreqShifter_H__

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
#define FAUSTCLASS FreqShifter
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

class FreqShifterSIG0 {
	
  private:
	
	int iVec2[2];
	int iRec7[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsFreqShifterSIG0() {
		return 0;
	}
	int getNumOutputsFreqShifterSIG0() {
		return 1;
	}
	
	void instanceInitFreqShifterSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			iVec2[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			iRec7[l9] = 0;
		}
	}
	
	void fillFreqShifterSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec2[0] = 1;
			iRec7[0] = (faust_wrap_add(iVec2[1], iRec7[1])) % 65536;
			table[i1] = std::cos(9.58738e-05f * static_cast<float>(iRec7[0]));
			iVec2[1] = iVec2[0];
			iRec7[1] = iRec7[0];
		}
	}

};

static FreqShifterSIG0* newFreqShifterSIG0() { return (FreqShifterSIG0*)new FreqShifterSIG0(); }
static void deleteFreqShifterSIG0(FreqShifterSIG0* dsp) { delete dsp; }

class FreqShifterSIG1 {
	
  private:
	
	int iVec3[2];
	int iRec10[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsFreqShifterSIG1() {
		return 0;
	}
	int getNumOutputsFreqShifterSIG1() {
		return 1;
	}
	
	void instanceInitFreqShifterSIG1(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			iVec3[l12] = 0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			iRec10[l13] = 0;
		}
	}
	
	void fillFreqShifterSIG1(int count, float* table) {
		for (int i2 = 0; i2 < count; i2 = faust_wrap_add(i2, 1)) {
			iVec3[0] = 1;
			iRec10[0] = (faust_wrap_add(iVec3[1], iRec10[1])) % 65536;
			table[i2] = std::sin(9.58738e-05f * static_cast<float>(iRec10[0]));
			iVec3[1] = iVec3[0];
			iRec10[1] = iRec10[0];
		}
	}

};

static FreqShifterSIG1* newFreqShifterSIG1() { return (FreqShifterSIG1*)new FreqShifterSIG1(); }
static void deleteFreqShifterSIG1(FreqShifterSIG1* dsp) { delete dsp; }

static float DSY_SDRAM_BSS ftbl0FreqShifterSIG0[65536];
static float DSY_SDRAM_BSS ftbl1FreqShifterSIG1[65536];

class FreqShifter : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec5[2];
	float fConst3;
	float fConst4;
	float fConst5;
	float fRec6[2];
	float fVec1[3];
	float fRec4[3];
	float fRec3[3];
	float fRec2[3];
	float fRec1[3];
	FAUSTFLOAT fHslider1;
	float fRec9[2];
	float fConst6;
	float fRec8[2];
	float fRec14[3];
	float fRec13[3];
	float fRec12[3];
	float fRec11[3];
	float fRec0[3];
	FAUSTFLOAT fHslider2;
	float fRec15[2];
	
 public:
	FreqShifter() {
	}
	
	FreqShifter(const FreqShifter&) = default;
	
	virtual ~FreqShifter() = default;
	
	FreqShifter& operator=(const FreqShifter&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn FreqShifter -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Bode-style single-sideband frequency shifter (Hilbert allpass pair)");
		m->declare("filename", "freq-shifter.dsp");
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
		m->declare("name", "FrequencyShifter");
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
		FreqShifterSIG0* sig0 = newFreqShifterSIG0();
		sig0->instanceInitFreqShifterSIG0(sample_rate);
		sig0->fillFreqShifterSIG0(65536, ftbl0FreqShifterSIG0);
		FreqShifterSIG1* sig1 = newFreqShifterSIG1();
		sig1->instanceInitFreqShifterSIG1(sample_rate);
		sig1->fillFreqShifterSIG1(65536, ftbl1FreqShifterSIG1);
		deleteFreqShifterSIG0(sig0);
		deleteFreqShifterSIG1(sig1);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.0f / std::tan(18849.557f / fConst0);
		fConst4 = 1.0f - fConst3;
		fConst5 = 1.0f / (fConst3 + 1.0f);
		fConst6 = 1.0f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.2f);
		fHslider1 = static_cast<FAUSTFLOAT>(85.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.6f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec5[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec6[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec1[l7] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec8[l11] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = faust_wrap_add(l14, 1)) {
			fRec14[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 3; l15 = faust_wrap_add(l15, 1)) {
			fRec13[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 3; l16 = faust_wrap_add(l16, 1)) {
			fRec12[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 3; l17 = faust_wrap_add(l17, 1)) {
			fRec11[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 3; l18 = faust_wrap_add(l18, 1)) {
			fRec0[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec15[l19] = 0.0f;
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
	
	virtual FreqShifter* clone() {
		return new FreqShifter(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("FrequencyShifter");
		ui_interface->addHorizontalSlider("Feedback", &fHslider0, FAUSTFLOAT(0.2f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.8f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Mix", &fHslider2, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Shift Amount", &fHslider1, FAUSTFLOAT(85.0f), FAUSTFLOAT(-5e+02f), FAUSTFLOAT(5e+02f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec5[0] = fSlow0 + fConst2 * fRec5[1];
			fRec6[0] = -(fConst5 * (fConst4 * fRec6[1] - (fRec0[1] + fRec0[2])));
			float fTemp0 = static_cast<float>(input0[i0]);
			float fTemp1 = fTemp0 + tanhf(fRec6[0] * fRec5[0]);
			fVec1[0] = fTemp1;
			fRec4[0] = 0.1617585f * (fTemp1 + fRec4[2]) - fVec1[2];
			fRec3[0] = 0.73302895f * (fRec4[0] + fRec3[2]) - fRec4[2];
			fRec2[0] = 0.9453497f * (fRec3[0] + fRec2[2]) - fRec3[2];
			fRec1[0] = 0.99059916f * (fRec2[0] + fRec1[2]) - fRec2[2];
			fRec9[0] = fSlow1 + fConst2 * fRec9[1];
			float fTemp2 = ((faust_wrap_sub(1, iVec0[1])) ? 0.0f : fRec8[1] + fConst6 * fRec9[0]);
			fRec8[0] = fTemp2 - std::floor(fTemp2);
			int iTemp3 = std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec8[0]), 65535));
			fRec14[0] = 0.47940087f * (fTemp1 + fRec14[2]) - fVec1[2];
			fRec13[0] = 0.8762185f * (fRec14[0] + fRec13[2]) - fRec14[2];
			fRec12[0] = 0.9765976f * (fRec13[0] + fRec12[2]) - fRec13[2];
			fRec11[0] = 0.9974992f * (fRec12[0] + fRec11[2]) - fRec12[2];
			fRec0[0] = fRec11[0] * ftbl1FreqShifterSIG1[iTemp3] - ftbl0FreqShifterSIG0[iTemp3] * fRec1[1];
			fRec15[0] = fSlow2 + fConst2 * fRec15[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec15[0]) + fRec15[0] * fRec0[0]);
			iVec0[1] = iVec0[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fVec1[2] = fVec1[1];
			fVec1[1] = fVec1[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec15[1] = fRec15[0];
		}
	}

};

#endif
