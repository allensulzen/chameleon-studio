/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Delay Duck"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgDelayDuck -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgDelayDuck_H__
#define  __TdgDelayDuck_H__

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
#define FAUSTCLASS TdgDelayDuck
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


class TdgDelayDuck : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	float fConst4;
	float fRec2[2];
	float fConst5;
	float fRec1[2];
	float fConst6;
	float fConst7;
	FAUSTFLOAT fHslider0;
	float fRec3[2];
	float fConst8;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec5[2];
	int IOTA0;
	float fVec0[262144];
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	float fConst9;
	float fRec4[2];
	FAUSTFLOAT fHslider3;
	float fRec7[2];
	
 public:
	TdgDelayDuck() {
	}
	
	TdgDelayDuck(const TdgDelayDuck&) = default;
	
	virtual ~TdgDelayDuck() = default;
	
	TdgDelayDuck& operator=(const TdgDelayDuck&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgDelayDuck -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Ducking delay: repeats are pushed down while you play and swell back in the gaps");
		m->declare("family", "time");
		m->declare("filename", "tdg-delay-duck.dsp");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Delay Duck");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust circles/delay_duck.dsp + geometry.lib");
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
		fConst1 = std::exp(-(5e+01f / fConst0));
		fConst2 = std::exp(-(2e+01f / fConst0));
		fConst3 = std::exp(-(1e+01f / fConst0));
		fConst4 = 1.0f - fConst3;
		fConst5 = 1.0f - fConst2;
		fConst6 = 44.1f / fConst0;
		fConst7 = 1.0f - fConst6;
		fConst8 = 1.0f - fConst1;
		fConst9 = 0.001f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider2 = static_cast<FAUSTFLOAT>(5e+02f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec2[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec0[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec5[l4] = 0.0f;
		}
		IOTA0 = 0;
		for (int l5 = 0; l5 < 262144; l5 = faust_wrap_add(l5, 1)) {
			fVec0[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec4[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec7[l8] = 0.0f;
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
	
	virtual TdgDelayDuck* clone() {
		return new TdgDelayDuck(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Delay Duck");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "unit", "ms");
		ui_interface->addHorizontalSlider("Time", &fHslider2, FAUSTFLOAT(5e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Feedback", &fHslider1, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->addHorizontalSlider("Ducking", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "9", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst6 * static_cast<float>(fHslider0);
		float fSlow1 = fConst6 * static_cast<float>(fHslider1);
		float fSlow2 = fConst5 * static_cast<float>(fHslider2);
		float fSlow3 = fConst6 * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			float fTemp0 = static_cast<float>(input0[i0]);
			float fTemp1 = std::fabs(fTemp0);
			fRec2[0] = std::max<float>(fTemp1, fConst3 * fRec2[1] + fConst4 * fTemp1);
			fRec1[0] = fConst5 * fRec2[0] + fConst2 * fRec1[1];
			fRec3[0] = fSlow0 + fConst7 * fRec3[1];
			fRec0[0] = fConst8 * std::pow(1e+01f, -(2.0f * fRec3[0] * std::min<float>(1.0f, 4.0f * fRec1[0]))) + fConst1 * fRec0[1];
			fRec5[0] = fSlow1 + fConst7 * fRec5[1];
			float fTemp2 = fTemp0 + fRec5[0] * fRec4[1];
			fVec0[IOTA0 & 262143] = fTemp2;
			fRec6[0] = fSlow2 + fConst2 * fRec6[1];
			float fTemp3 = fConst9 * fRec6[0];
			int iTemp4 = static_cast<int>(fTemp3);
			float fTemp5 = std::floor(fTemp3);
			fRec4[0] = fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp4)))) & 262143] * (fTemp5 + (1.0f - fTemp3)) + (fTemp3 - fTemp5) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp4, 1))))) & 262143];
			fRec7[0] = fSlow3 + fConst7 * fRec7[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec7[0]) + fRec7[0] * fRec4[0] * fRec0[0]);
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec0[1] = fRec0[0];
			fRec5[1] = fRec5[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec7[1] = fRec7[0];
		}
	}

};

#endif
