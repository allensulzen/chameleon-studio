/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "BeatRepeater"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn BeatRepeater -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __BeatRepeater_H__
#define  __BeatRepeater_H__

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
#define FAUSTCLASS BeatRepeater
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


class BeatRepeater : public chdsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	int iVec0[2];
	int iRec0[2];
	int IOTA0;
	float fVec1[262144];
	FAUSTFLOAT fHslider1;
	int iRec1[2];
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fRec2[2];
	
 public:
	BeatRepeater() {
	}
	
	BeatRepeater(const BeatRepeater&) = default;
	
	virtual ~BeatRepeater() = default;
	
	BeatRepeater& operator=(const BeatRepeater&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn BeatRepeater -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Buffer stutter: plays each captured slice N times before grabbing a new one");
		m->declare("filename", "beat-repeater.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "BeatRepeater");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 0.001f * fConst0;
		fConst2 = 44.1f / fConst0;
		fConst3 = 1.0f - fConst2;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(125.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(4.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.8f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iRec0[l1] = 0;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 262144; l2 = faust_wrap_add(l2, 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			iRec1[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec2[l4] = 0.0f;
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
	
	virtual BeatRepeater* clone() {
		return new BeatRepeater(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("BeatRepeater");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider2, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Repeats", &fHslider1, FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "unit", "ms");
		ui_interface->addHorizontalSlider("Slice Size", &fHslider0, FAUSTFLOAT(125.0f), FAUSTFLOAT(25.0f), FAUSTFLOAT(5e+02f), FAUSTFLOAT(5.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		int iSlow0 = std::max<int>(256, static_cast<int>(fConst1 * static_cast<float>(fHslider0)));
		int iSlow1 = static_cast<int>(static_cast<float>(fHslider1));
		float fSlow2 = fConst2 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			iRec0[0] = (faust_wrap_add(iVec0[1], iRec0[1])) % iSlow0;
			float fTemp0 = static_cast<float>(input0[i0]);
			fVec1[IOTA0 & 262143] = fTemp0;
			iRec1[0] = (faust_wrap_add(iRec1[1], iRec0[0] < iRec0[1])) % iSlow1;
			fRec2[0] = fSlow2 + fConst3 * fRec2[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec2[0]) + fRec2[0] * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(262144, std::max<int>(0, std::min<int>(262140, faust_wrap_mul(iSlow0, iRec1[0])))))) & 262143] * std::min<float>(1.0f, std::min<float>(0.010416667f * static_cast<float>(iRec0[0]), 0.010416667f * static_cast<float>(faust_wrap_sub(iSlow0, iRec0[0])))));
			iVec0[1] = iVec0[0];
			iRec0[1] = iRec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			iRec1[1] = iRec1[0];
			fRec2[1] = fRec2[0];
		}
	}

};

#endif
