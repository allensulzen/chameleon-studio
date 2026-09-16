/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Delay Pitch Shift"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgDelayPs -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgDelayPs_H__
#define  __TdgDelayPs_H__

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
#define FAUSTCLASS TdgDelayPs
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


class TdgDelayPs : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	float fRec0[2];
	int IOTA0;
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	float fVec0[262144];
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fConst4;
	float fRec4[2];
	float fConst5;
	float fRec2[131072];
	FAUSTFLOAT fHslider3;
	float fRec5[2];
	
 public:
	TdgDelayPs() {
	}
	
	TdgDelayPs(const TdgDelayPs&) = default;
	
	virtual ~TdgDelayPs() = default;
	
	TdgDelayPs& operator=(const TdgDelayPs&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgDelayPs -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Feedback delay with a pitch shifter (up to +/-8 semitones) on the wet path - shimmering or dive-bombing echoes");
		m->declare("family", "time");
		m->declare("filename", "tdg-delay-ps.dsp");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "Delay Pitch Shift");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust circles/delay_ps.dsp + geometry.lib");
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
		fConst3 = std::exp(-(2e+01f / fConst0));
		fConst4 = 1.0f - fConst3;
		fConst5 = 0.001f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(12.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider2 = static_cast<FAUSTFLOAT>(5e+02f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec0[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 262144; l3 = faust_wrap_add(l3, 1)) {
			fVec0[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 131072; l5 = faust_wrap_add(l5, 1)) {
			fRec2[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec5[l6] = 0.0f;
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
	
	virtual TdgDelayPs* clone() {
		return new TdgDelayPs(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Delay Pitch Shift");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "unit", "ms");
		ui_interface->addHorizontalSlider("Time", &fHslider2, FAUSTFLOAT(5e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Feedback", &fHslider1, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->declare(&fHslider0, "unit", "semi");
		ui_interface->addHorizontalSlider("Pitch", &fHslider0, FAUSTFLOAT(12.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider3, "9", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst4 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow0 + fConst2 * fRec1[1];
			fRec0[0] = std::fmod(fRec0[1] + (4097.0f - std::pow(2.0f, 0.083333336f * fRec1[0])), 4096.0f);
			float fTemp0 = std::min<float>(0.00048828125f * fRec0[0], 1.0f);
			fRec3[0] = fSlow1 + fConst2 * fRec3[1];
			float fTemp1 = static_cast<float>(input0[i0]);
			float fTemp2 = fTemp1 + fRec3[0] * fRec2[(faust_wrap_sub(IOTA0, 1)) & 131071];
			fVec0[IOTA0 & 262143] = fTemp2;
			fRec4[0] = fSlow2 + fConst3 * fRec4[1];
			float fTemp3 = fConst5 * fRec4[0];
			int iTemp4 = static_cast<int>(fTemp3);
			float fTemp5 = std::floor(fTemp3);
			fRec2[IOTA0 & 131071] = fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp4)))) & 262143] * (fTemp5 + (1.0f - fTemp3)) + (fTemp3 - fTemp5) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp4, 1))))) & 262143];
			float fTemp6 = fRec0[0] + 4096.0f;
			int iTemp7 = static_cast<int>(fTemp6);
			float fTemp8 = std::floor(fTemp6);
			int iTemp9 = static_cast<int>(fRec0[0]);
			float fTemp10 = std::floor(fRec0[0]);
			fRec5[0] = fSlow3 + fConst2 * fRec5[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp1 * (1.0f - fRec5[0]) + fRec5[0] * (0.2f * fRec2[IOTA0 & 131071] + 0.8f * ((fRec2[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp9)))) & 131071] * (fTemp10 + (1.0f - fRec0[0])) + (fRec0[0] - fTemp10) * fRec2[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp9, 1))))) & 131071]) * fTemp0 + (fRec2[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp7)))) & 131071] * (fTemp8 + (-4095.0f - fRec0[0])) + (fRec0[0] + (4096.0f - fTemp8)) * fRec2[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp7, 1))))) & 131071]) * (1.0f - fTemp0))));
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
		}
	}

};

#endif
