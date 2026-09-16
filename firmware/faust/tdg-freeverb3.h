/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Progenitor"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgFreeverb3 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgFreeverb3_H__
#define  __TdgFreeverb3_H__

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
#define FAUSTCLASS TdgFreeverb3
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


class TdgFreeverb3 : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fRec10[2];
	FAUSTFLOAT fHslider1;
	float fRec13[2];
	FAUSTFLOAT fHslider2;
	float fRec16[2];
	FAUSTFLOAT fHslider3;
	float fRec17[2];
	FAUSTFLOAT fHslider4;
	float fRec20[2];
	FAUSTFLOAT fHslider5;
	float fRec23[2];
	FAUSTFLOAT fHslider6;
	float fRec25[2];
	float fRec26[3];
	FAUSTFLOAT fHslider7;
	float fRec28[2];
	float fRec27[3];
	float fRec24[3];
	int IOTA0;
	float fVec0[256];
	float fRec21[2];
	float fVec1[3];
	FAUSTFLOAT fHslider8;
	float fRec29[2];
	float fVec2[512];
	float fRec18[2];
	float fVec3[2048];
	float fVec4[2048];
	float fRec14[2];
	float fVec5[1024];
	float fRec11[2];
	float fVec6[512];
	float fVec7[128];
	FAUSTFLOAT fHslider9;
	float fRec30[2];
	float fVec8[2048];
	float fRec8[2];
	float fVec9[1024];
	float fRec6[2];
	float fVec10[2048];
	float fRec4[2];
	float fVec11[2048];
	float fRec0[2];
	float fRec46[3];
	float fRec45[3];
	float fVec12[256];
	float fRec43[2];
	float fVec13[2];
	float fVec14[512];
	float fRec41[2];
	float fVec15[2048];
	float fVec16[2048];
	float fRec39[2];
	float fVec17[512];
	float fRec37[2];
	float fVec18[512];
	float fVec19[7];
	float fVec20[2048];
	float fRec35[2];
	float fVec21[1024];
	float fRec33[2];
	float fVec22[2048];
	float fRec31[2];
	float fVec23[32];
	float fRec1[2];
	FAUSTFLOAT fHslider10;
	float fRec47[2];
	
 public:
	TdgFreeverb3() {
	}
	
	TdgFreeverb3(const TdgFreeverb3&) = default;
	
	virtual ~TdgFreeverb3() = default;
	
	TdgFreeverb3& operator=(const TdgFreeverb3&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgFreeverb3 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Port of Freeverb3's Progenitor (Dattorro-style nested allpass tank) with chorus, definition and 3 decay stages. Author notes it can be unstable at extreme settings");
		m->declare("family", "reverb");
		m->declare("filename", "tdg-freeverb3.dsp");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Progenitor");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust freeverb3.dsp");
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
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider6 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider7 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider8 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider9 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider10 = static_cast<FAUSTFLOAT>(0.4f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec10[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec13[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec16[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec17[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec20[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec23[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec25[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec26[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec28[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec27[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec24[l10] = 0.0f;
		}
		IOTA0 = 0;
		for (int l11 = 0; l11 < 256; l11 = faust_wrap_add(l11, 1)) {
			fVec0[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec21[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = faust_wrap_add(l13, 1)) {
			fVec1[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec29[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 512; l15 = faust_wrap_add(l15, 1)) {
			fVec2[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec18[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2048; l17 = faust_wrap_add(l17, 1)) {
			fVec3[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2048; l18 = faust_wrap_add(l18, 1)) {
			fVec4[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec14[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 1024; l20 = faust_wrap_add(l20, 1)) {
			fVec5[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec11[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 512; l22 = faust_wrap_add(l22, 1)) {
			fVec6[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 128; l23 = faust_wrap_add(l23, 1)) {
			fVec7[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec30[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2048; l25 = faust_wrap_add(l25, 1)) {
			fVec8[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec8[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 1024; l27 = faust_wrap_add(l27, 1)) {
			fVec9[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec6[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2048; l29 = faust_wrap_add(l29, 1)) {
			fVec10[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec4[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2048; l31 = faust_wrap_add(l31, 1)) {
			fVec11[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec0[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 3; l33 = faust_wrap_add(l33, 1)) {
			fRec46[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 3; l34 = faust_wrap_add(l34, 1)) {
			fRec45[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 256; l35 = faust_wrap_add(l35, 1)) {
			fVec12[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec43[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fVec13[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 512; l38 = faust_wrap_add(l38, 1)) {
			fVec14[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec41[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2048; l40 = faust_wrap_add(l40, 1)) {
			fVec15[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2048; l41 = faust_wrap_add(l41, 1)) {
			fVec16[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			fRec39[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 512; l43 = faust_wrap_add(l43, 1)) {
			fVec17[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec37[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 512; l45 = faust_wrap_add(l45, 1)) {
			fVec18[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 7; l46 = faust_wrap_add(l46, 1)) {
			fVec19[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2048; l47 = faust_wrap_add(l47, 1)) {
			fVec20[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec35[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 1024; l49 = faust_wrap_add(l49, 1)) {
			fVec21[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec33[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2048; l51 = faust_wrap_add(l51, 1)) {
			fVec22[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec31[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 32; l53 = faust_wrap_add(l53, 1)) {
			fVec23[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fRec1[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			fRec47[l55] = 0.0f;
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
	
	virtual TdgFreeverb3* clone() {
		return new TdgFreeverb3(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Progenitor");
		ui_interface->declare(&fHslider9, "0", "");
		ui_interface->addHorizontalSlider("Chorus", &fHslider9, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider10, "10", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider10, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->addHorizontalSlider("Definition", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->addHorizontalSlider("Decay 1", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider4, "3", "");
		ui_interface->addHorizontalSlider("Decay 2", &fHslider4, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "4", "");
		ui_interface->addHorizontalSlider("Decay 3", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider8, "5", "");
		ui_interface->addHorizontalSlider("Diffusion 1", &fHslider8, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider5, "6", "");
		ui_interface->addHorizontalSlider("Diffusion 2", &fHslider5, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "7", "");
		ui_interface->addHorizontalSlider("Decay Diffusion", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider6, "8", "");
		ui_interface->addHorizontalSlider("Damping", &fHslider6, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider7, "9", "");
		ui_interface->addHorizontalSlider("HF Bandwidth", &fHslider7, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst0 * static_cast<float>(fHslider0);
		float fSlow1 = fConst0 * static_cast<float>(fHslider1);
		float fSlow2 = fConst0 * static_cast<float>(fHslider2);
		float fSlow3 = fConst0 * static_cast<float>(fHslider3);
		float fSlow4 = fConst0 * static_cast<float>(fHslider4);
		float fSlow5 = fConst0 * static_cast<float>(fHslider5);
		float fSlow6 = fConst0 * static_cast<float>(fHslider6);
		float fSlow7 = fConst0 * static_cast<float>(fHslider7);
		float fSlow8 = fConst0 * static_cast<float>(fHslider8);
		float fSlow9 = fConst0 * static_cast<float>(fHslider9);
		float fSlow10 = fConst0 * static_cast<float>(fHslider10);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec10[0] = fSlow0 + fConst1 * fRec10[1];
			fRec13[0] = fSlow1 + fConst1 * fRec13[1];
			fRec16[0] = fSlow2 + fConst1 * fRec16[1];
			float fTemp0 = 0.406f * fRec16[0] * fRec11[1];
			fRec17[0] = fSlow3 + fConst1 * fRec17[1];
			fRec20[0] = fSlow4 + fConst1 * fRec20[1];
			fRec23[0] = fSlow5 + fConst1 * fRec23[1];
			fRec25[0] = fSlow6 + fConst1 * fRec25[1];
			float fTemp1 = 1.0f - 0.312f * fRec25[0];
			fRec26[0] = 0.875f * fRec26[2] + 0.125f * fRec1[1];
			fRec28[0] = fSlow7 + fConst1 * fRec28[1];
			float fTemp2 = static_cast<float>(input0[i0]);
			fRec27[0] = 0.188f * fRec28[0] * fRec27[2] + fTemp2 * (1.0f - 0.188f * fRec28[0]);
			float fTemp3 = 0.5f * fRec27[1];
			fRec24[0] = 0.312f * fRec25[0] * fRec24[2] + (fTemp3 + 0.156f * fRec26[0] + 0.344f * fRec1[1]) * fTemp1;
			float fTemp4 = fRec24[0] + 0.375f * fRec23[0] * fRec21[1];
			fVec0[IOTA0 & 255] = fTemp4;
			fRec21[0] = fVec0[(faust_wrap_sub(IOTA0, 239)) & 255];
			float fRec22 = -(0.375f * fRec23[0] * fTemp4);
			fVec1[0] = fRec22 + 0.844f * fRec21[0] * fRec20[0];
			fRec29[0] = fSlow8 + fConst1 * fRec29[1];
			float fTemp5 = 0.312f * fRec29[0] * fRec18[1] + fVec1[2];
			fVec2[IOTA0 & 511] = fTemp5;
			fRec18[0] = fVec2[(faust_wrap_sub(IOTA0, 392)) & 511];
			float fRec19 = -(0.312f * fRec29[0] * fTemp5);
			float fTemp6 = fRec19 + 0.906f * fRec18[0] * fRec17[0];
			fVec3[IOTA0 & 2047] = fTemp6;
			float fTemp7 = fVec3[(faust_wrap_sub(IOTA0, 1055)) & 2047];
			float fTemp8 = fTemp7 + 0.25f * fRec10[0] * fRec14[1] + fTemp0;
			fVec4[IOTA0 & 2047] = fTemp8;
			fRec14[0] = fVec4[(faust_wrap_sub(IOTA0, 1944)) & 2047];
			float fRec15 = -(0.25f * fRec10[0] * fTemp8);
			fVec5[IOTA0 & 1023] = fRec15 + 0.938f * fRec14[0] * fRec13[0];
			fRec11[0] = fVec5[(faust_wrap_sub(IOTA0, 612)) & 1023];
			float fRec12 = -(0.406f * fRec16[0] * (fTemp0 + fTemp7));
			fVec6[IOTA0 & 511] = fRec12 + 0.844f * fRec20[0] * fRec11[0];
			float fTemp9 = fVec6[(faust_wrap_sub(IOTA0, 344)) & 511];
			float fTemp10 = 0.406f * fRec16[0] * fRec4[1];
			float fTemp11 = fTemp10 + fTemp9;
			float fTemp12 = fTemp11 + 0.25f * fRec10[0] * (fRec8[1] + fRec6[1]);
			fVec7[IOTA0 & 127] = fTemp12;
			fRec30[0] = fSlow9 + fConst1 * fRec30[1];
			fVec8[IOTA0 & 2047] = fVec7[(faust_wrap_sub(IOTA0, 122)) & 127] * (1.0f - 0.781f * fRec30[0]) + 0.781f * fRec30[0] * fVec7[(faust_wrap_sub(IOTA0, 121)) & 127];
			fRec8[0] = fVec8[(faust_wrap_sub(IOTA0, 1212)) & 2047];
			float fRec9 = -(0.25f * fRec10[0] * fTemp12);
			fVec9[IOTA0 & 1023] = fRec9 + 0.938f * fRec8[0];
			fRec6[0] = fVec9[(faust_wrap_sub(IOTA0, 816)) & 1023];
			float fRec7 = -(0.25f * fRec10[0] * (fTemp9 + 0.25f * fRec10[0] * fRec6[1] + fTemp10));
			fVec10[IOTA0 & 2047] = fRec7 + 0.938f * fRec13[0] * fRec6[0];
			fRec4[0] = fVec10[(faust_wrap_sub(IOTA0, 1264)) & 2047];
			float fRec5 = -(0.406f * fRec16[0] * fTemp11);
			fVec11[IOTA0 & 2047] = fRec5 + 0.844f * fRec20[0] * fRec4[0];
			fRec0[0] = fVec11[(faust_wrap_sub(IOTA0, 1572)) & 2047];
			float fTemp13 = 0.406f * fRec16[0] * fRec37[1];
			fRec46[0] = 0.875f * fRec46[2] + 0.125f * fRec0[1];
			fRec45[0] = 0.312f * fRec25[0] * fRec45[2] + fTemp1 * (fTemp3 + 0.156f * fRec46[0] + 0.344f * fRec0[1]);
			float fTemp14 = fRec45[0] + 0.375f * fRec23[0] * fRec43[1];
			fVec12[IOTA0 & 255] = fTemp14;
			fRec43[0] = fVec12[(faust_wrap_sub(IOTA0, 205)) & 255];
			float fRec44 = -(0.375f * fRec23[0] * fTemp14);
			fVec13[0] = fRec44 + 0.844f * fRec20[0] * fRec43[0];
			float fTemp15 = 0.312f * fRec29[0] * fRec41[1] + fVec13[1];
			fVec14[IOTA0 & 511] = fTemp15;
			fRec41[0] = fVec14[(faust_wrap_sub(IOTA0, 329)) & 511];
			float fRec42 = -(0.312f * fRec29[0] * fTemp15);
			float fTemp16 = fRec42 + 0.906f * fRec17[0] * fRec41[0];
			fVec15[IOTA0 & 2047] = fTemp16;
			float fTemp17 = fVec15[(faust_wrap_sub(IOTA0, 1460)) & 2047];
			float fTemp18 = fTemp17 + 0.25f * fRec10[0] * fRec39[1] + fTemp13;
			fVec16[IOTA0 & 2047] = fTemp18;
			fRec39[0] = fVec16[(faust_wrap_sub(IOTA0, 2032)) & 2047];
			float fRec40 = -(0.25f * fRec10[0] * fTemp18);
			fVec17[IOTA0 & 511] = fRec40 + 0.938f * fRec13[0] * fRec39[0];
			fRec37[0] = fVec17[(faust_wrap_sub(IOTA0, 368)) & 511];
			float fRec38 = -(0.406f * fRec16[0] * (fTemp13 + fTemp17));
			fVec18[IOTA0 & 511] = fRec38 + 0.844f * fRec20[0] * fRec37[0];
			float fTemp19 = fVec18[(faust_wrap_sub(IOTA0, 500)) & 511];
			float fTemp20 = 0.406f * fRec16[0] * fRec31[1];
			float fTemp21 = fTemp20 + fTemp19;
			float fTemp22 = fTemp21 + 0.25f * fRec10[0] * (fRec35[1] + fRec33[1]);
			fVec19[0] = fTemp22;
			fVec20[IOTA0 & 2047] = fVec19[6] * (1.0f - 0.188f * fRec30[0]) + 0.188f * fRec30[0] * fVec19[5];
			fRec35[0] = fVec20[(faust_wrap_sub(IOTA0, 1452)) & 2047];
			float fRec36 = -(0.25f * fRec10[0] * fTemp22);
			fVec21[IOTA0 & 1023] = fRec36 + 0.938f * fRec35[0];
			fRec33[0] = fVec21[(faust_wrap_sub(IOTA0, 688)) & 1023];
			float fRec34 = -(0.25f * fRec10[0] * (fTemp19 + 0.25f * fRec10[0] * fRec33[1] + fTemp20));
			fVec22[IOTA0 & 2047] = fRec34 + 0.938f * fRec13[0] * fRec33[0];
			fRec31[0] = fVec22[(faust_wrap_sub(IOTA0, 1340)) & 2047];
			float fRec32 = -(0.406f * fRec16[0] * fTemp21);
			fVec23[IOTA0 & 31] = fRec32 + 0.844f * fRec20[0] * fRec31[0];
			fRec1[0] = fVec23[(faust_wrap_sub(IOTA0, 16)) & 31];
			float fRec2 = fTemp6;
			float fRec3 = fTemp16;
			fRec47[0] = fSlow10 + fConst1 * fRec47[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp2 * (1.0f - fRec47[0]) + 0.5f * fRec47[0] * (fRec3 + fRec0[0] + fRec2 + fRec1[0]));
			fRec10[1] = fRec10[0];
			fRec13[1] = fRec13[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec20[1] = fRec20[0];
			fRec23[1] = fRec23[0];
			fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec28[1] = fRec28[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec21[1] = fRec21[0];
			fVec1[2] = fVec1[1];
			fVec1[1] = fVec1[0];
			fRec29[1] = fRec29[0];
			fRec18[1] = fRec18[0];
			fRec14[1] = fRec14[0];
			fRec11[1] = fRec11[0];
			fRec30[1] = fRec30[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec0[1] = fRec0[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fVec13[1] = fVec13[0];
			fRec41[1] = fRec41[0];
			fRec39[1] = fRec39[0];
			fRec37[1] = fRec37[0];
			for (int j0 = 6; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fVec19[j0] = fVec19[faust_wrap_sub(j0, 1)];
			}
			fRec35[1] = fRec35[0];
			fRec33[1] = fRec33[0];
			fRec31[1] = fRec31[0];
			fRec1[1] = fRec1[0];
			fRec47[1] = fRec47[0];
		}
	}

};

#endif
