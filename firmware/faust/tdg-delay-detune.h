/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Delay Detune"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgDelayDetune -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgDelayDetune_H__
#define  __TdgDelayDetune_H__

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
#define FAUSTCLASS TdgDelayDetune
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

class TdgDelayDetuneSIG0 {
	
  private:
	
	int iVec2[2];
	int iRec3[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsTdgDelayDetuneSIG0() {
		return 0;
	}
	int getNumOutputsTdgDelayDetuneSIG0() {
		return 1;
	}
	
	void instanceInitTdgDelayDetuneSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			iVec2[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			iRec3[l6] = 0;
		}
	}
	
	void fillTdgDelayDetuneSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec2[0] = 1;
			iRec3[0] = (faust_wrap_add(iVec2[1], iRec3[1])) % 65536;
			table[i1] = std::sin(9.58738e-05f * static_cast<float>(iRec3[0]));
			iVec2[1] = iVec2[0];
			iRec3[1] = iRec3[0];
		}
	}

};

static TdgDelayDetuneSIG0* newTdgDelayDetuneSIG0() { return (TdgDelayDetuneSIG0*)new TdgDelayDetuneSIG0(); }
static void deleteTdgDelayDetuneSIG0(TdgDelayDetuneSIG0* dsp) { delete dsp; }

static float DSY_SDRAM_BSS ftbl0TdgDelayDetuneSIG0[65536];

class TdgDelayDetune : public chdsp {
	
 private:
	
	int IOTA0;
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	float fVec1[262144];
	float fConst3;
	FAUSTFLOAT fHslider1;
	float fConst4;
	float fRec2[2];
	float fConst5;
	float fRec0[2048];
	float fConst6;
	float fRec4[2];
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	float fRec6[2];
	
 public:
	TdgDelayDetune() {
	}
	
	TdgDelayDetune(const TdgDelayDetune&) = default;
	
	virtual ~TdgDelayDetune() = default;
	
	TdgDelayDetune& operator=(const TdgDelayDetune&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgDelayDetune -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Feedback delay whose repeats pass through an LFO-modulated micro-delay, detuning each echo (chorus-delay)");
		m->declare("family", "time");
		m->declare("filename", "tdg-delay-detune.dsp");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Delay Detune");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust circles/delay_detune.dsp + geometry.lib");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		TdgDelayDetuneSIG0* sig0 = newTdgDelayDetuneSIG0();
		sig0->instanceInitTdgDelayDetuneSIG0(sample_rate);
		sig0->fillTdgDelayDetuneSIG0(65536, ftbl0TdgDelayDetuneSIG0);
		deleteTdgDelayDetuneSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = std::exp(-(2e+01f / fConst0));
		fConst4 = 1.0f - fConst3;
		fConst5 = 0.001f * fConst0;
		fConst6 = 1e+03f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider1 = static_cast<FAUSTFLOAT>(5e+02f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 262144; l2 = faust_wrap_add(l2, 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2048; l4 = faust_wrap_add(l4, 1)) {
			fRec0[l4] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec4[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec5[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec6[l9] = 0.0f;
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
	
	virtual TdgDelayDetune* clone() {
		return new TdgDelayDetune(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Delay Detune");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->declare(&fHslider1, "unit", "ms");
		ui_interface->addHorizontalSlider("Time", &fHslider1, FAUSTFLOAT(5e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->addHorizontalSlider("Feedback", &fHslider0, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->addHorizontalSlider("Detune", &fHslider2, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "9", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst4 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec1[0] = fSlow0 + fConst2 * fRec1[1];
			float fTemp0 = static_cast<float>(input0[i0]);
			float fTemp1 = fTemp0 + fRec1[0] * fRec0[(faust_wrap_sub(IOTA0, 1)) & 2047];
			fVec1[IOTA0 & 262143] = fTemp1;
			fRec2[0] = fSlow1 + fConst3 * fRec2[1];
			float fTemp2 = fConst5 * fRec2[0];
			int iTemp3 = static_cast<int>(fTemp2);
			float fTemp4 = std::floor(fTemp2);
			fRec0[IOTA0 & 2047] = fVec1[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp3)))) & 262143] * (fTemp4 + (1.0f - fTemp2)) + (fTemp2 - fTemp4) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp3, 1))))) & 262143];
			float fTemp5 = ((faust_wrap_sub(1, iVec0[1])) ? 0.0f : fRec4[1] + fConst6 / fRec2[0]);
			fRec4[0] = fTemp5 - std::floor(fTemp5);
			fRec5[0] = fSlow2 + fConst2 * fRec5[1];
			float fTemp6 = 2e+02f * fRec5[0] * (ftbl0TdgDelayDetuneSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec4[0]), 65535))] + 1.0f);
			float fTemp7 = fTemp6 + 1.0f;
			int iTemp8 = static_cast<int>(fTemp7);
			float fTemp9 = std::floor(fTemp7);
			fRec6[0] = fSlow3 + fConst2 * fRec6[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec6[0]) + fRec6[0] * (fRec0[(faust_wrap_sub(IOTA0, std::min<int>(1025, std::max<int>(0, iTemp8)))) & 2047] * (fTemp9 - fTemp6) + (fTemp6 + (1.0f - fTemp9)) * fRec0[(faust_wrap_sub(IOTA0, std::min<int>(1025, std::max<int>(0, faust_wrap_add(iTemp8, 1))))) & 2047]));
			IOTA0 = faust_wrap_add(IOTA0, 1);
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
		}
	}

};

#endif
