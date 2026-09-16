/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Delay Emu"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgDelayEmu -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgDelayEmu_H__
#define  __TdgDelayEmu_H__

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
#define FAUSTCLASS TdgDelayEmu
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

class TdgDelayEmuSIG0 {
	
  private:
	
	int iVec3[2];
	int iRec11[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsTdgDelayEmuSIG0() {
		return 0;
	}
	int getNumOutputsTdgDelayEmuSIG0() {
		return 1;
	}
	
	void instanceInitTdgDelayEmuSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			iVec3[l14] = 0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			iRec11[l15] = 0;
		}
	}
	
	void fillTdgDelayEmuSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec3[0] = 1;
			iRec11[0] = (faust_wrap_add(iVec3[1], iRec11[1])) % 65536;
			table[i1] = std::sin(9.58738e-05f * static_cast<float>(iRec11[0]));
			iVec3[1] = iVec3[0];
			iRec11[1] = iRec11[0];
		}
	}

};

static TdgDelayEmuSIG0* newTdgDelayEmuSIG0() { return (TdgDelayEmuSIG0*)new TdgDelayEmuSIG0(); }
static void deleteTdgDelayEmuSIG0(TdgDelayEmuSIG0* dsp) { delete dsp; }

static float TdgDelayEmu_faustpower2_f(float value) {
	return value * value;
}
static float DSY_SDRAM_BSS ftbl0TdgDelayEmuSIG0[65536];

class TdgDelayEmu : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	int IOTA0;
	float fVec1[262144];
	float fConst10;
	FAUSTFLOAT fHslider2;
	float fConst11;
	float fRec5[2];
	float fConst12;
	float fRec3[2];
	float fRec2[3];
	float fRec1[3];
	float fConst13;
	float fConst14;
	float fConst15;
	float fRec7[2];
	float fRec8[2];
	int iRec9[2];
	float fRec6[2];
	float fRec10[2];
	float fVec2[32];
	float fConst16;
	float fRec12[2];
	float fRec14[3];
	float fRec13[3];
	FAUSTFLOAT fHslider3;
	float fRec15[2];
	
 public:
	TdgDelayEmu() {
	}
	
	TdgDelayEmu(const TdgDelayEmu&) = default;
	
	virtual ~TdgDelayEmu() = default;
	
	TdgDelayEmu& operator=(const TdgDelayEmu&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgDelayEmu -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Delay with morphable character: 8-bit reduction (digital) to clean to tape-capstan wow with bandlimiting and hiss (analog)");
		m->declare("family", "time");
		m->declare("filename", "tdg-delay-emu.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Delay Emu");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.6.0");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust circles/delay_emu.dsp + geometry.lib");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		TdgDelayEmuSIG0* sig0 = newTdgDelayEmuSIG0();
		sig0->instanceInitTdgDelayEmuSIG0(sample_rate);
		sig0->fillTdgDelayEmuSIG0(65536, ftbl0TdgDelayEmuSIG0);
		deleteTdgDelayEmuSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = std::tan(12566.371f / fConst0);
		fConst4 = 2.0f * (1.0f - 1.0f / TdgDelayEmu_faustpower2_f(fConst3));
		fConst5 = 1.0f / fConst3;
		fConst6 = (fConst5 + -0.76536685f) / fConst3 + 1.0f;
		fConst7 = 1.0f / ((fConst5 + 0.76536685f) / fConst3 + 1.0f);
		fConst8 = (fConst5 + -1.847759f) / fConst3 + 1.0f;
		fConst9 = 1.0f / ((fConst5 + 1.847759f) / fConst3 + 1.0f);
		fConst10 = std::exp(-(2e+01f / fConst0));
		fConst11 = 1.0f - fConst10;
		fConst12 = 0.001f * fConst0;
		fConst13 = 75398.23f / fConst0;
		fConst14 = std::cos(fConst13);
		fConst15 = std::sin(fConst13);
		fConst16 = 6.0f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider2 = static_cast<FAUSTFLOAT>(5e+02f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec4[l2] = 0.0f;
		}
		IOTA0 = 0;
		for (int l3 = 0; l3 < 262144; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec1[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			iRec9[l10] = 0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec6[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec10[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 32; l13 = faust_wrap_add(l13, 1)) {
			fVec2[l13] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec12[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 3; l17 = faust_wrap_add(l17, 1)) {
			fRec14[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 3; l18 = faust_wrap_add(l18, 1)) {
			fRec13[l18] = 0.0f;
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
	
	virtual TdgDelayEmu* clone() {
		return new TdgDelayEmu(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Delay Emu");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "unit", "ms");
		ui_interface->addHorizontalSlider("Time", &fHslider2, FAUSTFLOAT(5e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Feedback", &fHslider1, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->addHorizontalSlider("Digital/Analog", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "9", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst11 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			int iTemp0 = static_cast<int>(fRec0[0]);
			int iTemp1 = std::min<int>(2, faust_wrap_add(iTemp0, 1));
			fRec4[0] = fSlow1 + fConst2 * fRec4[1];
			float fTemp2 = static_cast<float>(input0[i0]);
			float fTemp3 = fTemp2 + fRec4[0] * fRec3[1];
			fVec1[IOTA0 & 262143] = fTemp3;
			fRec5[0] = fSlow2 + fConst10 * fRec5[1];
			float fTemp4 = fConst12 * fRec5[0];
			int iTemp5 = static_cast<int>(fTemp4);
			float fTemp6 = std::floor(fTemp4);
			fRec3[0] = fVec1[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp5)))) & 262143] * (fTemp6 + (1.0f - fTemp4)) + (fTemp4 - fTemp6) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp5, 1))))) & 262143];
			fRec2[0] = fRec3[0] - fConst9 * (fConst8 * fRec2[2] + fConst4 * fRec2[1]);
			fRec1[0] = fConst9 * (fRec2[2] + fRec2[0] + 2.0f * fRec2[1]) - fConst7 * (fConst6 * fRec1[2] + fConst4 * fRec1[1]);
			fRec7[0] = fConst15 * fRec8[1] + fConst14 * fRec7[1];
			int iTemp7 = faust_wrap_sub(1, iVec0[1]);
			fRec8[0] = static_cast<float>(iTemp7) + fConst14 * fRec8[1] - fConst15 * fRec7[1];
			int iTemp8 = (fRec7[1] <= 0.0f) & (fRec7[0] > 0.0f);
			iRec9[0] = faust_wrap_add(faust_wrap_mul(1103515245, iRec9[1]), 12345);
			fRec6[0] = fRec6[1] * static_cast<float>(faust_wrap_sub(1, iTemp8)) + 4.656613e-10f * static_cast<float>(iRec9[0]) * static_cast<float>(iTemp8);
			fRec10[0] = 0.999f * fRec10[1] + 3.1622776e-07f;
			float fTemp9 = fRec10[0] * fRec6[0] + fConst7 * (fRec1[2] + fRec1[0] + 2.0f * fRec1[1]);
			fVec2[IOTA0 & 31] = fTemp9;
			float fTemp10 = ((iTemp7) ? 0.0f : fConst16 + fRec12[1]);
			fRec12[0] = fTemp10 - std::floor(fTemp10);
			float fTemp11 = 12.5f * (ftbl0TdgDelayEmuSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec12[0]), 65535))] + 1.0f);
			int iTemp12 = static_cast<int>(fTemp11);
			float fTemp13 = std::floor(fTemp11);
			float fTemp14 = fVec2[(faust_wrap_sub(IOTA0, std::min<int>(1025, std::max<int>(0, iTemp12)))) & 31] * (fTemp13 + (1.0f - fTemp11)) + (fTemp11 - fTemp13) * fVec2[(faust_wrap_sub(IOTA0, std::min<int>(1025, std::max<int>(0, faust_wrap_add(iTemp12, 1))))) & 31];
			fRec14[0] = 0.00390625f * std::ceil(256.0f * fRec3[0]) - fConst9 * (fConst8 * fRec14[2] + fConst4 * fRec14[1]);
			fRec13[0] = fConst9 * (fRec14[2] + fRec14[0] + 2.0f * fRec14[1]) - fConst7 * (fConst6 * fRec13[2] + fConst4 * fRec13[1]);
			float fTemp15 = fConst7 * (fRec13[2] + fRec13[0] + 2.0f * fRec13[1]);
			float fTemp16 = std::floor(fRec0[0]);
			fRec15[0] = fSlow3 + fConst2 * fRec15[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp2 * (1.0f - fRec15[0]) + fRec15[0] * ((fTemp16 + (1.0f - fRec0[0])) * ((iTemp0 == 0) ? fTemp15 : ((iTemp0 == 1) ? fRec3[0] : fTemp14)) + (fRec0[0] - fTemp16) * ((iTemp1 == 0) ? fTemp15 : ((iTemp1 == 1) ? fRec3[0] : fTemp14))));
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			fRec4[1] = fRec4[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec5[1] = fRec5[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			iRec9[1] = iRec9[0];
			fRec6[1] = fRec6[0];
			fRec10[1] = fRec10[0];
			fRec12[1] = fRec12[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec15[1] = fRec15[0];
		}
	}

};

#endif
