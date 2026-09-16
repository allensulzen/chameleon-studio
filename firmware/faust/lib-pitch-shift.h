/* ------------------------------------------------------------
author: "Grame"
license: "BSD-3-Clause"
name: "Pitch Shifter"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibPitchShift -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibPitchShift_H__
#define  __LibPitchShift_H__

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
#define FAUSTCLASS LibPitchShift
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


class LibPitchShift : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	FAUSTFLOAT fHslider1;
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	int IOTA0;
	float fVec0[131072];
	FAUSTFLOAT fHslider3;
	float fRec2[2];
	
 public:
	LibPitchShift() {
	}
	
	LibPitchShift(const LibPitchShift&) = default;
	
	virtual ~LibPitchShift() = default;
	
	LibPitchShift& operator=(const LibPitchShift&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Grame");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibPitchShift -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Grame's classic dual-delay crossfade pitch shifter, octave down to octave up with mix");
		m->declare("family", "pitch");
		m->declare("filename", "lib-pitch-shift.dsp");
		m->declare("license", "BSD-3-Clause");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "Pitch Shifter");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faust/examples/pitchShifting/pitchShifter.dsp ef.transpose");
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
		fConst0 = 44.1f / std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 1.0f - fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(12.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(1e+03f);
		fHslider2 = static_cast<FAUSTFLOAT>(2e+02f);
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
		for (int l2 = 0; l2 < 131072; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec2[l3] = 0.0f;
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
	
	virtual LibPitchShift* clone() {
		return new LibPitchShift(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Pitch Shifter");
		ui_interface->declare(&fHslider0, "0", "");
		ui_interface->declare(&fHslider0, "unit", "semi");
		ui_interface->addHorizontalSlider("Shift", &fHslider0, FAUSTFLOAT(12.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "unit", "samples");
		ui_interface->addHorizontalSlider("Window", &fHslider1, FAUSTFLOAT(1e+03f), FAUSTFLOAT(2e+02f), FAUSTFLOAT(4e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "unit", "samples");
		ui_interface->addHorizontalSlider("Crossfade", &fHslider2, FAUSTFLOAT(2e+02f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst0 * static_cast<float>(fHslider0);
		float fSlow1 = static_cast<float>(fHslider1);
		float fSlow2 = 1.0f / std::min<float>(fSlow1, static_cast<float>(fHslider2));
		float fSlow3 = fConst0 * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow0 + fConst1 * fRec1[1];
			fRec0[0] = std::fmod(fSlow1 + fRec0[1] + (1.0f - std::pow(2.0f, 0.083333336f * fRec1[0])), fSlow1);
			float fTemp0 = std::min<float>(fSlow2 * fRec0[0], 1.0f);
			float fTemp1 = static_cast<float>(input0[i0]);
			fVec0[IOTA0 & 131071] = fTemp1;
			float fTemp2 = fSlow1 + fRec0[0];
			int iTemp3 = static_cast<int>(fTemp2);
			float fTemp4 = std::floor(fTemp2);
			float fTemp5 = 1.0f - fRec0[0];
			int iTemp6 = static_cast<int>(fRec0[0]);
			float fTemp7 = std::floor(fRec0[0]);
			fRec2[0] = fSlow3 + fConst1 * fRec2[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp1 * (1.0f - fRec2[0]) + fRec2[0] * ((fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp6)))) & 131071] * (fTemp7 + fTemp5) + (fRec0[0] - fTemp7) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp6, 1))))) & 131071]) * fTemp0 + (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp3)))) & 131071] * (fTemp4 + fTemp5 - fSlow1) + (fSlow1 + (fRec0[0] - fTemp4)) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp3, 1))))) & 131071]) * (1.0f - fTemp0)));
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec2[1] = fRec2[0];
		}
	}

};

#endif
