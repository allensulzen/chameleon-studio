/* ------------------------------------------------------------
author: "GRAME, OWL wrapper Rebel Technology"
license: "BSD-3-Clause"
name: "FaustVerb"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn OwlFaustverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __OwlFaustverb_H__
#define  __OwlFaustverb_H__

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
#define FAUSTCLASS OwlFaustverb
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


class OwlFaustverb : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec10[2];
	FAUSTFLOAT fHslider2;
	float fRec12[2];
	float fRec11[2];
	int IOTA0;
	float fVec0[2048];
	float fRec9[2];
	float fRec14[2];
	float fVec1[2048];
	float fRec13[2];
	float fRec16[2];
	float fVec2[2048];
	float fRec15[2];
	float fRec18[2];
	float fVec3[2048];
	float fRec17[2];
	float fRec20[2];
	float fVec4[2048];
	float fRec19[2];
	float fRec22[2];
	float fVec5[2048];
	float fRec21[2];
	float fRec24[2];
	float fVec6[2048];
	float fRec23[2];
	float fRec26[2];
	float fVec7[2048];
	float fRec25[2];
	float fVec8[1024];
	float fRec7[2];
	float fVec9[512];
	float fRec5[2];
	float fVec10[512];
	float fRec3[2];
	float fVec11[256];
	float fRec1[2];
	
 public:
	OwlFaustverb() {
	}
	
	OwlFaustverb(const OwlFaustverb&) = default;
	
	virtual ~OwlFaustverb() = default;
	
	OwlFaustverb& operator=(const OwlFaustverb&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "GRAME, OWL wrapper Rebel Technology");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn OwlFaustverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "GRAME's primitive-level Freeverb (8 combs, 4 allpasses) as shipped on the OWL pedal");
		m->declare("family", "reverb");
		m->declare("filename", "owl-faustverb.dsp");
		m->declare("license", "BSD-3-Clause");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "FaustVerb");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "pingdynasty/OwlPatches Faust/FaustVerb.dsp");
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
		fHslider0 = static_cast<FAUSTFLOAT>(0.3333f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec10[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec12[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec11[l3] = 0.0f;
		}
		IOTA0 = 0;
		for (int l4 = 0; l4 < 2048; l4 = faust_wrap_add(l4, 1)) {
			fVec0[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec9[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec14[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2048; l7 = faust_wrap_add(l7, 1)) {
			fVec1[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec13[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec16[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2048; l10 = faust_wrap_add(l10, 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec15[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec18[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2048; l13 = faust_wrap_add(l13, 1)) {
			fVec3[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec17[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec20[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2048; l16 = faust_wrap_add(l16, 1)) {
			fVec4[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec19[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec22[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2048; l19 = faust_wrap_add(l19, 1)) {
			fVec5[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec21[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec24[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2048; l22 = faust_wrap_add(l22, 1)) {
			fVec6[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec23[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec26[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2048; l25 = faust_wrap_add(l25, 1)) {
			fVec7[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec25[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 1024; l27 = faust_wrap_add(l27, 1)) {
			fVec8[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec7[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 512; l29 = faust_wrap_add(l29, 1)) {
			fVec9[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec5[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 512; l31 = faust_wrap_add(l31, 1)) {
			fVec10[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec3[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 256; l33 = faust_wrap_add(l33, 1)) {
			fVec11[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec1[l34] = 0.0f;
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
	
	virtual OwlFaustverb* clone() {
		return new OwlFaustverb(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("FaustVerb");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->addHorizontalSlider("Room Size", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->addHorizontalSlider("Damp", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider0, FAUSTFLOAT(0.3333f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst0 * static_cast<float>(fHslider0);
		float fSlow1 = fConst0 * static_cast<float>(fHslider1);
		float fSlow2 = fConst0 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst1 * fRec0[1];
			float fTemp0 = static_cast<float>(input0[i0]);
			fRec10[0] = fSlow1 + fConst1 * fRec10[1];
			float fTemp1 = 0.28f * fRec10[0] + 0.7f;
			fRec12[0] = fSlow2 + fConst1 * fRec12[1];
			float fTemp2 = 1.0f - 0.4f * fRec12[0];
			fRec11[0] = 0.4f * fRec12[0] * fRec11[1] + fTemp2 * fRec9[1];
			float fTemp3 = 0.015f * fTemp0;
			fVec0[IOTA0 & 2047] = fTemp3 + fRec11[0] * fTemp1;
			fRec9[0] = fVec0[(faust_wrap_sub(IOTA0, 1617)) & 2047];
			fRec14[0] = 0.4f * fRec12[0] * fRec14[1] + fTemp2 * fRec13[1];
			fVec1[IOTA0 & 2047] = fTemp3 + fRec14[0] * fTemp1;
			fRec13[0] = fVec1[(faust_wrap_sub(IOTA0, 1557)) & 2047];
			fRec16[0] = 0.4f * fRec12[0] * fRec16[1] + fTemp2 * fRec15[1];
			fVec2[IOTA0 & 2047] = fTemp3 + fRec16[0] * fTemp1;
			fRec15[0] = fVec2[(faust_wrap_sub(IOTA0, 1491)) & 2047];
			fRec18[0] = 0.4f * fRec12[0] * fRec18[1] + fTemp2 * fRec17[1];
			fVec3[IOTA0 & 2047] = fTemp3 + fRec18[0] * fTemp1;
			fRec17[0] = fVec3[(faust_wrap_sub(IOTA0, 1422)) & 2047];
			fRec20[0] = 0.4f * fRec12[0] * fRec20[1] + fTemp2 * fRec19[1];
			fVec4[IOTA0 & 2047] = fTemp3 + fRec20[0] * fTemp1;
			fRec19[0] = fVec4[(faust_wrap_sub(IOTA0, 1356)) & 2047];
			fRec22[0] = 0.4f * fRec12[0] * fRec22[1] + fTemp2 * fRec21[1];
			fVec5[IOTA0 & 2047] = fTemp3 + fRec22[0] * fTemp1;
			fRec21[0] = fVec5[(faust_wrap_sub(IOTA0, 1277)) & 2047];
			fRec24[0] = 0.4f * fRec12[0] * fRec24[1] + fTemp2 * fRec23[1];
			fVec6[IOTA0 & 2047] = fTemp3 + fRec24[0] * fTemp1;
			fRec23[0] = fVec6[(faust_wrap_sub(IOTA0, 1188)) & 2047];
			fRec26[0] = 0.4f * fRec12[0] * fRec26[1] + fRec25[1] * fTemp2;
			fVec7[IOTA0 & 2047] = fRec26[0] * fTemp1 + fTemp3;
			fRec25[0] = fVec7[(faust_wrap_sub(IOTA0, 1116)) & 2047];
			float fTemp4 = fRec25[0] + fRec23[0] + fRec21[0] + fRec19[0] + fRec17[0] + fRec15[0] + fRec13[0] + fRec9[0];
			fVec8[IOTA0 & 1023] = fTemp4 + 0.5f * fRec7[1];
			fRec7[0] = fVec8[(faust_wrap_sub(IOTA0, 556)) & 1023];
			float fRec8 = fRec7[1] - fTemp4;
			fVec9[IOTA0 & 511] = fRec8 + 0.5f * fRec5[1];
			fRec5[0] = fVec9[(faust_wrap_sub(IOTA0, 441)) & 511];
			float fRec6 = fRec5[1] - fRec8;
			fVec10[IOTA0 & 511] = fRec6 + 0.5f * fRec3[1];
			fRec3[0] = fVec10[(faust_wrap_sub(IOTA0, 341)) & 511];
			float fRec4 = fRec3[1] - fRec6;
			fVec11[IOTA0 & 255] = fRec4 + 0.5f * fRec1[1];
			fRec1[0] = fVec11[(faust_wrap_sub(IOTA0, 225)) & 255];
			float fRec2 = fRec1[1] - fRec4;
			output0[i0] = static_cast<FAUSTFLOAT>(fRec2 * fRec0[0] + fTemp0 * (1.0f - fRec0[0]));
			fRec0[1] = fRec0[0];
			fRec10[1] = fRec10[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec9[1] = fRec9[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec7[1] = fRec7[0];
			fRec5[1] = fRec5[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
