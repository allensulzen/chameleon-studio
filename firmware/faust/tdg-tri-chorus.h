/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Tri Chorus"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgTriChorus -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgTriChorus_H__
#define  __TdgTriChorus_H__

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
#define FAUSTCLASS TdgTriChorus
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

class TdgTriChorusSIG0 {
	
  private:
	
	int iVec2[2];
	int iRec2[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsTdgTriChorusSIG0() {
		return 0;
	}
	int getNumOutputsTdgTriChorusSIG0() {
		return 1;
	}
	
	void instanceInitTdgTriChorusSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			iVec2[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			iRec2[l4] = 0;
		}
	}
	
	void fillTdgTriChorusSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec2[0] = 1;
			iRec2[0] = (faust_wrap_add(iVec2[1], iRec2[1])) % 65536;
			table[i1] = std::sin(9.58738e-05f * static_cast<float>(iRec2[0]));
			iVec2[1] = iVec2[0];
			iRec2[1] = iRec2[0];
		}
	}

};

static TdgTriChorusSIG0* newTdgTriChorusSIG0() { return (TdgTriChorusSIG0*)new TdgTriChorusSIG0(); }
static void deleteTdgTriChorusSIG0(TdgTriChorusSIG0* dsp) { delete dsp; }

static float DSY_SDRAM_BSS ftbl0TdgTriChorusSIG0[65536];

class TdgTriChorus : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	int IOTA0;
	float fVec1[1024];
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	float fConst3;
	float fRec3[2];
	float fVec3[2048];
	float fConst4;
	float fRec5[2];
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	float fRec0[2];
	float fVec4[1024];
	float fConst5;
	float fRec8[2];
	float fRec7[2];
	float fVec5[1024];
	float fRec9[2];
	FAUSTFLOAT fHslider3;
	float fRec10[2];
	
 public:
	TdgTriChorus() {
	}
	
	TdgTriChorus(const TdgTriChorus&) = default;
	
	virtual ~TdgTriChorus() = default;
	
	TdgTriChorus& operator=(const TdgTriChorus&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgTriChorus -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Three flanger_mono voices with phase-offset and saw-delayed LFOs summed - thick tri-chorus (from rects/mod_01 trichor)");
		m->declare("family", "mod");
		m->declare("filename", "tdg-tri-chorus.dsp");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Tri Chorus");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "LicenseRef-STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("phaflangers.lib/name", "Faust Phaser and Flanger Library");
		m->declare("phaflangers.lib/version", "1.1.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust rects/mod_01.dsp trichor()");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		TdgTriChorusSIG0* sig0 = newTdgTriChorusSIG0();
		sig0->instanceInitTdgTriChorusSIG0(sample_rate);
		sig0->fillTdgTriChorusSIG0(65536, ftbl0TdgTriChorusSIG0);
		deleteTdgTriChorusSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.0f / fConst0;
		fConst4 = 0.78f / fConst0;
		fConst5 = 3.0f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.2f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.8f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.6f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 1024; l2 = faust_wrap_add(l2, 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2048; l7 = faust_wrap_add(l7, 1)) {
			fVec3[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec5[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec6[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec0[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 1024; l11 = faust_wrap_add(l11, 1)) {
			fVec4[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec8[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec7[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 1024; l14 = faust_wrap_add(l14, 1)) {
			fVec5[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec9[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec10[l16] = 0.0f;
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
	
	virtual TdgTriChorus* clone() {
		return new TdgTriChorus(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Tri Chorus");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Speed", &fHslider1, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.1f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->addHorizontalSlider("Depth", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->addHorizontalSlider("Feedback", &fHslider0, FAUSTFLOAT(0.2f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.9f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider3, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			float fTemp0 = static_cast<float>(input0[i0]);
			iVec0[0] = 1;
			fRec1[0] = fSlow0 + fConst2 * fRec1[1];
			float fTemp1 = 0.5f * fRec1[0] * fRec0[1] - fTemp0;
			fVec1[IOTA0 & 1023] = fTemp1;
			int iTemp2 = faust_wrap_sub(1, iVec0[1]);
			fRec4[0] = fSlow1 + fConst2 * fRec4[1];
			float fTemp3 = ((iTemp2) ? 0.0f : fRec3[1] + fConst3 * fRec4[0]);
			fRec3[0] = fTemp3 - std::floor(fTemp3);
			float fTemp4 = ftbl0TdgTriChorusSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec3[0]), 65535))];
			fVec3[IOTA0 & 2047] = fTemp4;
			float fTemp5 = ((iTemp2) ? 0.0f : fRec5[1] + fConst4 * fRec4[0]);
			fRec5[0] = fTemp5 - std::floor(fTemp5);
			float fTemp6 = 2e+02f * fRec5[0];
			int iTemp7 = static_cast<int>(fTemp6);
			float fTemp8 = std::floor(fTemp6);
			fRec6[0] = fSlow2 + fConst2 * fRec6[1];
			float fTemp9 = 255.0f * fRec6[0] * (fVec3[(faust_wrap_sub(IOTA0, std::min<int>(1025, std::max<int>(0, iTemp7)))) & 2047] * (fTemp8 + (1.0f - fTemp6)) + (fTemp6 - fTemp8) * fVec3[(faust_wrap_sub(IOTA0, std::min<int>(1025, std::max<int>(0, faust_wrap_add(iTemp7, 1))))) & 2047] + 1.0f);
			float fTemp10 = fTemp9 + 1.0f;
			int iTemp11 = static_cast<int>(fTemp10);
			float fTemp12 = std::floor(fTemp10);
			fRec0[0] = fVec1[(faust_wrap_sub(IOTA0, std::min<int>(513, std::max<int>(0, iTemp11)))) & 1023] * (fTemp12 - fTemp9) + (fTemp9 + (1.0f - fTemp12)) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(513, std::max<int>(0, faust_wrap_add(iTemp11, 1))))) & 1023];
			float fTemp13 = 0.7f * fRec1[0] * fRec7[1] - fTemp0;
			fVec4[IOTA0 & 1023] = fTemp13;
			float fTemp14 = ((iTemp2) ? 0.0f : fConst5 + fRec8[1]);
			fRec8[0] = fTemp14 - std::floor(fTemp14);
			float fTemp15 = 1e+02f * (ftbl0TdgTriChorusSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec8[0]), 65535))] + 1.0f);
			int iTemp16 = static_cast<int>(fTemp15);
			float fTemp17 = std::floor(fTemp15);
			float fTemp18 = 255.0f * fRec6[0] * (1.0f - (fVec3[(faust_wrap_sub(IOTA0, std::min<int>(1025, std::max<int>(0, iTemp16)))) & 2047] * (fTemp17 + (1.0f - fTemp15)) + (fTemp15 - fTemp17) * fVec3[(faust_wrap_sub(IOTA0, std::min<int>(1025, std::max<int>(0, faust_wrap_add(iTemp16, 1))))) & 2047]));
			float fTemp19 = fTemp18 + 1.0f;
			int iTemp20 = static_cast<int>(fTemp19);
			float fTemp21 = std::floor(fTemp19);
			fRec7[0] = fVec4[(faust_wrap_sub(IOTA0, std::min<int>(513, std::max<int>(0, iTemp20)))) & 1023] * (fTemp21 - fTemp18) + (fTemp18 + (1.0f - fTemp21)) * fVec4[(faust_wrap_sub(IOTA0, std::min<int>(513, std::max<int>(0, faust_wrap_add(iTemp20, 1))))) & 1023];
			float fTemp22 = 0.3f * fRec1[0] * fRec9[1] - fTemp0;
			fVec5[IOTA0 & 1023] = fTemp22;
			float fTemp23 = 255.0f * fRec6[0] * (fTemp4 + 1.0f);
			float fTemp24 = fTemp23 + 1.0f;
			int iTemp25 = static_cast<int>(fTemp24);
			float fTemp26 = std::floor(fTemp24);
			fRec9[0] = fVec5[(faust_wrap_sub(IOTA0, std::min<int>(513, std::max<int>(0, iTemp25)))) & 1023] * (fTemp26 - fTemp23) + (fTemp23 + (1.0f - fTemp26)) * fVec5[(faust_wrap_sub(IOTA0, std::min<int>(513, std::max<int>(0, faust_wrap_add(iTemp25, 1))))) & 1023];
			fRec10[0] = fSlow3 + fConst2 * fRec10[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec10[0]) + 0.165f * fRec10[0] * (fTemp0 + fRec6[0] * fRec9[0] + fTemp0 + fRec6[0] * fRec7[0] + fTemp0 + fRec6[0] * fRec0[0]));
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec0[1] = fRec0[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
		}
	}

};

#endif
