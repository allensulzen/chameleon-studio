/* ------------------------------------------------------------
author: "Julius O. Smith III, GRAME"
license: "LGPL-2.1-or-later"
name: "8-Voice Chorus"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn ExChorus8voice -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __ExChorus8voice_H__
#define  __ExChorus8voice_H__

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
#define FAUSTCLASS ExChorus8voice
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

class ExChorus8voiceSIG0 {
	
  private:
	
	int iVec2[2];
	int iRec1[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsExChorus8voiceSIG0() {
		return 0;
	}
	int getNumOutputsExChorus8voiceSIG0() {
		return 1;
	}
	
	void instanceInitExChorus8voiceSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			iVec2[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			iRec1[l4] = 0;
		}
	}
	
	void fillExChorus8voiceSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec2[0] = 1;
			iRec1[0] = (faust_wrap_add(iVec2[1], iRec1[1])) % 65536;
			table[i1] = std::cos(9.58738e-05f * static_cast<float>(iRec1[0]));
			iVec2[1] = iVec2[0];
			iRec1[1] = iRec1[0];
		}
	}

};

static ExChorus8voiceSIG0* newExChorus8voiceSIG0() { return (ExChorus8voiceSIG0*)new ExChorus8voiceSIG0(); }
static void deleteExChorus8voiceSIG0(ExChorus8voiceSIG0* dsp) { delete dsp; }

class ExChorus8voiceSIG1 {
	
  private:
	
	int iVec3[2];
	int iRec4[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsExChorus8voiceSIG1() {
		return 0;
	}
	int getNumOutputsExChorus8voiceSIG1() {
		return 1;
	}
	
	void instanceInitExChorus8voiceSIG1(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			iVec3[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			iRec4[l8] = 0;
		}
	}
	
	void fillExChorus8voiceSIG1(int count, float* table) {
		for (int i2 = 0; i2 < count; i2 = faust_wrap_add(i2, 1)) {
			iVec3[0] = 1;
			iRec4[0] = (faust_wrap_add(iVec3[1], iRec4[1])) % 65536;
			table[i2] = std::sin(9.58738e-05f * static_cast<float>(iRec4[0]));
			iVec3[1] = iVec3[0];
			iRec4[1] = iRec4[0];
		}
	}

};

static ExChorus8voiceSIG1* newExChorus8voiceSIG1() { return (ExChorus8voiceSIG1*)new ExChorus8voiceSIG1(); }
static void deleteExChorus8voiceSIG1(ExChorus8voiceSIG1* dsp) { delete dsp; }

static float DSY_SDRAM_BSS ftbl0ExChorus8voiceSIG0[65536];
static float DSY_SDRAM_BSS ftbl1ExChorus8voiceSIG1[65536];

class ExChorus8voice : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec0[2];
	int IOTA0;
	float fVec1[16384];
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	float fConst3;
	float fRec2[2];
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	FAUSTFLOAT fHslider3;
	float fRec5[2];
	float fConst4;
	float fRec7[2];
	float fConst5;
	float fRec8[2];
	float fConst6;
	float fRec9[2];
	float fConst7;
	float fRec10[2];
	float fConst8;
	float fRec11[2];
	float fConst9;
	float fRec12[2];
	
 public:
	ExChorus8voice() {
	}
	
	ExChorus8voice(const ExChorus8voice&) = default;
	
	virtual ~ExChorus8voice() = default;
	
	ExChorus8voice& operator=(const ExChorus8voice&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Julius O. Smith III, GRAME");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn ExChorus8voice -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "JOS multi-voice chorus from the SHARC Audio Module example: 8 delay taps with per-voice LFO rates and phase-spread deviation, summed to mono");
		m->declare("family", "mod");
		m->declare("filename", "ex-chorus-8voice.dsp");
		m->declare("license", "LGPL-2.1-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "8-Voice Chorus");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faust/examples/SAM/effects/chorus.dsp");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		ExChorus8voiceSIG0* sig0 = newExChorus8voiceSIG0();
		sig0->instanceInitExChorus8voiceSIG0(sample_rate);
		sig0->fillExChorus8voiceSIG0(65536, ftbl0ExChorus8voiceSIG0);
		ExChorus8voiceSIG1* sig1 = newExChorus8voiceSIG1();
		sig1->instanceInitExChorus8voiceSIG1(sample_rate);
		sig1->fillExChorus8voiceSIG1(65536, ftbl1ExChorus8voiceSIG1);
		deleteExChorus8voiceSIG0(sig0);
		deleteExChorus8voiceSIG1(sig1);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = std::exp(-(44.12234f / fConst0));
		fConst2 = 1.0f - fConst1;
		fConst3 = 0.5f / fConst0;
		fConst4 = 0.14285715f / fConst0;
		fConst5 = 0.25f / fConst0;
		fConst6 = 0.16666667f / fConst0;
		fConst7 = 0.125f / fConst0;
		fConst8 = 1.0f / fConst0;
		fConst9 = 0.33333334f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec0[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 16384; l2 = faust_wrap_add(l2, 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec2[l6] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec6[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec5[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec7[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec8[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec9[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec10[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec11[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec12[l16] = 0.0f;
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
	
	virtual ExChorus8voice* clone() {
		return new ExChorus8voice(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("8-Voice Chorus");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->addHorizontalSlider("Delay", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Rate", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.01f), FAUSTFLOAT(7.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->addHorizontalSlider("Depth", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->addHorizontalSlider("Deviation", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst2 * static_cast<float>(fHslider0);
		float fSlow1 = fConst2 * static_cast<float>(fHslider1);
		float fSlow2 = 8.192f * static_cast<float>(fHslider2);
		float fSlow3 = 6.25e-05f * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec0[0] = fSlow0 + fConst1 * fRec0[1];
			float fTemp0 = static_cast<float>(input0[i0]);
			float fTemp1 = fTemp0 * fRec0[0];
			fVec1[IOTA0 & 16383] = fTemp1;
			int iTemp2 = faust_wrap_sub(1, iVec0[1]);
			fRec3[0] = fSlow1 + fConst1 * fRec3[1];
			float fTemp3 = ((iTemp2) ? 0.0f : fRec2[1] + fConst3 * fRec3[0]);
			fRec2[0] = fTemp3 - std::floor(fTemp3);
			int iTemp4 = std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec2[0]), 65535));
			fRec6[0] = fSlow2 + 0.999f * fRec6[1];
			fRec5[0] = fSlow3 * fRec6[0] + 0.999f * fRec5[1];
			float fTemp5 = std::min<float>(8192.0f, 0.25f * fRec6[0] + fRec5[0] * (0.70710677f * ftbl1ExChorus8voiceSIG1[iTemp4] + 0.70710677f * ftbl0ExChorus8voiceSIG0[iTemp4]));
			int iTemp6 = static_cast<int>(fTemp5);
			float fTemp7 = std::floor(fTemp5);
			float fTemp8 = ((iTemp2) ? 0.0f : fRec7[1] + fConst4 * fRec3[0]);
			fRec7[0] = fTemp8 - std::floor(fTemp8);
			float fTemp9 = std::min<float>(8192.0f, 0.875f * fRec6[0] - fRec5[0] * ftbl0ExChorus8voiceSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec7[0]), 65535))]);
			int iTemp10 = static_cast<int>(fTemp9);
			float fTemp11 = std::floor(fTemp9);
			float fTemp12 = ((iTemp2) ? 0.0f : fRec8[1] + fConst5 * fRec3[0]);
			fRec8[0] = fTemp12 - std::floor(fTemp12);
			int iTemp13 = std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec8[0]), 65535));
			float fTemp14 = std::min<float>(8192.0f, 0.5f * fRec6[0] + fRec5[0] * (0.70710677f * ftbl0ExChorus8voiceSIG0[iTemp13] - 0.70710677f * ftbl1ExChorus8voiceSIG1[iTemp13]));
			int iTemp15 = static_cast<int>(fTemp14);
			float fTemp16 = std::floor(fTemp14);
			float fTemp17 = ((iTemp2) ? 0.0f : fRec9[1] + fConst6 * fRec3[0]);
			fRec9[0] = fTemp17 - std::floor(fTemp17);
			int iTemp18 = std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec9[0]), 65535));
			float fTemp19 = std::min<float>(8192.0f, 0.75f * fRec6[0] - fRec5[0] * (0.70710677f * ftbl1ExChorus8voiceSIG1[iTemp18] + 0.70710677f * ftbl0ExChorus8voiceSIG0[iTemp18]));
			int iTemp20 = static_cast<int>(fTemp19);
			float fTemp21 = std::floor(fTemp19);
			float fTemp22 = ((iTemp2) ? 0.0f : fRec10[1] + fConst7 * fRec3[0]);
			fRec10[0] = fTemp22 - std::floor(fTemp22);
			int iTemp23 = std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec10[0]), 65535));
			float fTemp24 = std::min<float>(8192.0f, fRec6[0] + fRec5[0] * (0.70710677f * ftbl1ExChorus8voiceSIG1[iTemp23] - 0.70710677f * ftbl0ExChorus8voiceSIG0[iTemp23]));
			int iTemp25 = static_cast<int>(fTemp24);
			float fTemp26 = std::floor(fTemp24);
			float fTemp27 = ((iTemp2) ? 0.0f : fRec11[1] + fConst8 * fRec3[0]);
			fRec11[0] = fTemp27 - std::floor(fTemp27);
			float fTemp28 = std::min<float>(8192.0f, 0.125f * fRec6[0] + fRec5[0] * ftbl1ExChorus8voiceSIG1[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec11[0]), 65535))]);
			float fTemp29 = std::floor(fTemp28);
			int iTemp30 = static_cast<int>(fTemp28);
			float fTemp31 = ((iTemp2) ? 0.0f : fRec12[1] + fConst9 * fRec3[0]);
			fRec12[0] = fTemp31 - std::floor(fTemp31);
			float fTemp32 = std::min<float>(8192.0f, 0.375f * fRec6[0] + fRec5[0] * ftbl0ExChorus8voiceSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec12[0]), 65535))]);
			int iTemp33 = static_cast<int>(fTemp32);
			float fTemp34 = std::floor(fTemp32);
			output0[i0] = static_cast<FAUSTFLOAT>(0.5f * (0.70710677f * (fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, iTemp33)))) & 16383] * (fTemp34 + (1.0f - fTemp32)) + (fTemp32 - fTemp34) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, faust_wrap_add(iTemp33, 1))))) & 16383]) + (fTemp28 - fTemp29) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, faust_wrap_add(iTemp30, 1))))) & 16383] + fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, iTemp30)))) & 16383] * (fTemp29 + (1.0f - fTemp28)) + 2.0f * fTemp0 * (1.0f - fRec0[0]) - (0.38268343f * (fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, iTemp25)))) & 16383] * (fTemp26 + (1.0f - fTemp24)) + (fTemp24 - fTemp26) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, faust_wrap_add(iTemp25, 1))))) & 16383]) + 0.9238795f * (fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, iTemp20)))) & 16383] * (fTemp21 + (1.0f - fTemp19)) + (fTemp19 - fTemp21) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, faust_wrap_add(iTemp20, 1))))) & 16383]) + 0.9238795f * (fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, iTemp15)))) & 16383] * (fTemp16 + (1.0f - fTemp14)) + (fTemp14 - fTemp16) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, faust_wrap_add(iTemp15, 1))))) & 16383]) + 0.70710677f * (fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, iTemp10)))) & 16383] * (fTemp11 + (1.0f - fTemp9)) + (fTemp9 - fTemp11) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, faust_wrap_add(iTemp10, 1))))) & 16383]) + 0.38268343f * (fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, iTemp6)))) & 16383] * (fTemp7 + (1.0f - fTemp5)) + (fTemp5 - fTemp7) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8193, std::max<int>(0, faust_wrap_add(iTemp6, 1))))) & 16383]))));
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
		}
	}

};

#endif
