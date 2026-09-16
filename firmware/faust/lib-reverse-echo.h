/* ------------------------------------------------------------
author: "Grame"
license: "LGPL-2.1-or-later"
name: "Reverse Echo"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibReverseEcho -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibReverseEcho_H__
#define  __LibReverseEcho_H__

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
#define FAUSTCLASS LibReverseEcho
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


class LibReverseEcho : public chdsp {
	
 private:
	
	int iVec0[2];
	int iRec0[2];
	int IOTA0;
	float fVec1[65536];
	int iRec1[2];
	int iRec2[2];
	int iRec3[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fRec4[2];
	
 public:
	LibReverseEcho() {
	}
	
	LibReverseEcho(const LibReverseEcho&) = default;
	
	virtual ~LibReverseEcho() = default;
	
	LibReverseEcho& operator=(const LibReverseEcho&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Grame");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibReverseEcho -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "N overlapping reverse-delay ramps (ef.reverseEchoN) - backwards-tape swells");
		m->declare("family", "time");
		m->declare("filename", "lib-reverse-echo.dsp");
		m->declare("license", "LGPL-2.1-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/reverseDelayRamped:author", "Julius O. Smith III");
		m->declare("misceffects.lib/reverseDelayRamped:license", "LicenseRef-STK-4.3");
		m->declare("misceffects.lib/reverseEchoN:author", "Julius O. Smith III");
		m->declare("misceffects.lib/reverseEchoN:license", "LicenseRef-STK-4.3");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "Reverse Echo");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/misceffects.lib ef.reverseEchoN");
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
		fHslider0 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iRec0[l1] = 0;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 65536; l2 = faust_wrap_add(l2, 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			iRec1[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			iRec2[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			iRec3[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec4[l6] = 0.0f;
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
	
	virtual LibReverseEcho* clone() {
		return new LibReverseEcho(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Reverse Echo");
		ui_interface->declare(&fHslider0, "0", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst0 * static_cast<float>(fHslider0);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			int iTemp0 = faust_wrap_sub(1, iVec0[1]);
			iRec0[0] = faust_wrap_add(faust_wrap_add(faust_wrap_mul(36000, iTemp0), iRec0[1]), 2);
			int iTemp1 = iRec0[0] & 47999;
			float fTemp2 = static_cast<float>(iTemp1);
			float fTemp3 = static_cast<float>(input0[i0]);
			fVec1[IOTA0 & 65535] = fTemp3;
			iRec1[0] = faust_wrap_add(faust_wrap_add(faust_wrap_mul(24000, iTemp0), iRec1[1]), 2);
			int iTemp4 = iRec1[0] & 47999;
			float fTemp5 = static_cast<float>(iTemp4);
			iRec2[0] = faust_wrap_add(faust_wrap_add(faust_wrap_mul(12000, iTemp0), iRec2[1]), 2);
			int iTemp6 = iRec2[0] & 47999;
			float fTemp7 = static_cast<float>(iTemp6);
			iRec3[0] = faust_wrap_add(iRec3[1], 2);
			int iTemp8 = iRec3[0] & 47999;
			float fTemp9 = static_cast<float>(iTemp8);
			fRec4[0] = fSlow0 + fConst1 * fRec4[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp3 * (1.0f - fRec4[0]) + 3.125e-05f * fRec4[0] * (fVec1[(faust_wrap_sub(IOTA0, std::min<int>(48000, std::max<int>(0, iTemp8)))) & 65535] * fTemp9 * (1.0f - 2.0833333e-05f * fTemp9) + fVec1[(faust_wrap_sub(IOTA0, std::min<int>(48000, std::max<int>(0, iTemp6)))) & 65535] * fTemp7 * (1.0f - 2.0833333e-05f * fTemp7) + fVec1[(faust_wrap_sub(IOTA0, std::min<int>(48000, std::max<int>(0, iTemp4)))) & 65535] * fTemp5 * (1.0f - 2.0833333e-05f * fTemp5) + fVec1[(faust_wrap_sub(IOTA0, std::min<int>(48000, std::max<int>(0, iTemp1)))) & 65535] * fTemp2 * (1.0f - 2.0833333e-05f * fTemp2)));
			iVec0[1] = iVec0[0];
			iRec0[1] = iRec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			iRec1[1] = iRec1[0];
			iRec2[1] = iRec2[0];
			iRec3[1] = iRec3[0];
			fRec4[1] = fRec4[0];
		}
	}

};

#endif
