/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Parametric Pitch Shifter"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgParametricPitchShifter -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgParametricPitchShifter_H__
#define  __TdgParametricPitchShifter_H__

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
#define FAUSTCLASS TdgParametricPitchShifter
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

class TdgParametricPitchShifterSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec1[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsTdgParametricPitchShifterSIG0() {
		return 0;
	}
	int getNumOutputsTdgParametricPitchShifterSIG0() {
		return 1;
	}
	
	void instanceInitTdgParametricPitchShifterSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iRec1[l1] = 0;
		}
	}
	
	void fillTdgParametricPitchShifterSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec0[0] = 1;
			iRec1[0] = (faust_wrap_add(iVec0[1], iRec1[1])) % 65536;
			table[i1] = std::sin(9.58738e-05f * static_cast<float>(iRec1[0]));
			iVec0[1] = iVec0[0];
			iRec1[1] = iRec1[0];
		}
	}

};

static TdgParametricPitchShifterSIG0* newTdgParametricPitchShifterSIG0() { return (TdgParametricPitchShifterSIG0*)new TdgParametricPitchShifterSIG0(); }
static void deleteTdgParametricPitchShifterSIG0(TdgParametricPitchShifterSIG0* dsp) { delete dsp; }

static float DSY_SDRAM_BSS ftbl0TdgParametricPitchShifterSIG0[65536];

class TdgParametricPitchShifter : public chdsp {
	
 private:
	
	int iVec1[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec3[2];
	float fConst3;
	float fRec2[2];
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	int IOTA0;
	float fVec2[131072];
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	float fRec6[2];
	FAUSTFLOAT fHslider4;
	float fRec7[2];
	float fRec0[2];
	FAUSTFLOAT fHslider5;
	float fRec8[2];
	
 public:
	TdgParametricPitchShifter() {
	}
	
	TdgParametricPitchShifter(const TdgParametricPitchShifter&) = default;
	
	virtual ~TdgParametricPitchShifter() = default;
	
	TdgParametricPitchShifter& operator=(const TdgParametricPitchShifter&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgParametricPitchShifter -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Pitch shifter whose shift amount is driven by a blend of envelope follower and LFO - auto-bends, warbles and touch-octaves");
		m->declare("family", "pitch");
		m->declare("filename", "tdg-parametric-pitch-shifter.dsp");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "Parametric Pitch Shifter");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust parametric_pitch_shifter.dsp");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		TdgParametricPitchShifterSIG0* sig0 = newTdgParametricPitchShifterSIG0();
		sig0->instanceInitTdgParametricPitchShifterSIG0(sample_rate);
		sig0->fillTdgParametricPitchShifterSIG0(65536, ftbl0TdgParametricPitchShifterSIG0);
		deleteTdgParametricPitchShifterSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.0f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider4 = static_cast<FAUSTFLOAT>(2.0f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			iVec1[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0f;
		}
		IOTA0 = 0;
		for (int l6 = 0; l6 < 131072; l6 = faust_wrap_add(l6, 1)) {
			fVec2[l6] = 0.0f;
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
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
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
	
	virtual TdgParametricPitchShifter* clone() {
		return new TdgParametricPitchShifter(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Parametric Pitch Shifter");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "unit", "s");
		ui_interface->addHorizontalSlider("Envelope", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("LFO Speed", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.1f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->addHorizontalSlider("Depth", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->addHorizontalSlider("Env/LFO", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider4, "4", "");
		ui_interface->declare(&fHslider4, "unit", "semi");
		ui_interface->addHorizontalSlider("Shift", &fHslider4, FAUSTFLOAT(2.0f), FAUSTFLOAT(-6.0f), FAUSTFLOAT(6.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider5, "5", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider5, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = static_cast<float>(fHslider2);
		int iSlow3 = std::fabs(fSlow2) < 1.1920929e-07f;
		float fSlow4 = ((iSlow3) ? 0.0f : std::exp(-(fConst3 / ((iSlow3) ? 1.0f : fSlow2))));
		float fSlow5 = 1.0f - fSlow4;
		float fSlow6 = fConst1 * static_cast<float>(fHslider3);
		float fSlow7 = fConst1 * static_cast<float>(fHslider4);
		float fSlow8 = fConst1 * static_cast<float>(fHslider5);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec1[0] = 1;
			fRec3[0] = fSlow0 + fConst2 * fRec3[1];
			float fTemp0 = ((faust_wrap_sub(1, iVec1[1])) ? 0.0f : fRec2[1] + fConst3 * fRec3[0]);
			fRec2[0] = fTemp0 - std::floor(fTemp0);
			fRec4[0] = fSlow1 + fConst2 * fRec4[1];
			float fTemp1 = static_cast<float>(input0[i0]);
			fVec2[IOTA0 & 131071] = fTemp1;
			float fTemp2 = std::fabs(fTemp1);
			fRec5[0] = std::max<float>(fTemp2, fRec5[1] * fSlow4 + fTemp2 * fSlow5);
			fRec6[0] = fSlow6 + fConst2 * fRec6[1];
			fRec7[0] = fSlow7 + fConst2 * fRec7[1];
			fRec0[0] = std::fmod(fRec0[1] + (2049.0f - std::pow(2.0f, 0.16666667f * fRec7[0] * (fRec6[0] * (6.0f * fRec5[0] * (1.0f - fRec4[0]) + 0.5f * fRec4[0] * ftbl0TdgParametricPitchShifterSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec2[0]), 65535))]) + 0.5f))), 2048.0f);
			float fTemp3 = std::min<float>(0.0009765625f * fRec0[0], 1.0f);
			float fTemp4 = fRec0[0] + 2048.0f;
			float fTemp5 = std::floor(fTemp4);
			int iTemp6 = static_cast<int>(fTemp4);
			int iTemp7 = static_cast<int>(fRec0[0]);
			float fTemp8 = std::floor(fRec0[0]);
			fRec8[0] = fSlow8 + fConst2 * fRec8[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp1 * (1.0f - fRec8[0]) + fRec8[0] * ((fVec2[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp7)))) & 131071] * (fTemp8 + (1.0f - fRec0[0])) + (fRec0[0] - fTemp8) * fVec2[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp7, 1))))) & 131071]) * fTemp3 + (fVec2[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp6)))) & 131071] * (fTemp5 + (-2047.0f - fRec0[0])) + fVec2[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp6, 1))))) & 131071] * (fRec0[0] + (2048.0f - fTemp5))) * (1.0f - fTemp3)));
			iVec1[1] = iVec1[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec0[1] = fRec0[0];
			fRec8[1] = fRec8[0];
		}
	}

};

#endif
