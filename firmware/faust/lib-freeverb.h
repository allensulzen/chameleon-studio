/* ------------------------------------------------------------
author: "Romain Michon (Faust port), Jezar at Dreampoint"
license: "LGPL-2.1-or-later"
name: "Freeverb"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibFreeverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibFreeverb_H__
#define  __LibFreeverb_H__

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
#define FAUSTCLASS LibFreeverb
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


class LibFreeverb : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec9[2];
	FAUSTFLOAT fHslider1;
	float fRec11[2];
	float fRec10[2];
	int IOTA0;
	float fVec0[8192];
	int iConst3;
	float fRec8[2];
	float fRec13[2];
	float fVec1[8192];
	int iConst4;
	float fRec12[2];
	float fRec15[2];
	float fVec2[8192];
	int iConst5;
	float fRec14[2];
	float fRec17[2];
	float fVec3[8192];
	int iConst6;
	float fRec16[2];
	float fRec19[2];
	float fVec4[8192];
	int iConst7;
	float fRec18[2];
	float fRec21[2];
	float fVec5[8192];
	int iConst8;
	float fRec20[2];
	float fRec23[2];
	float fVec6[8192];
	int iConst9;
	float fRec22[2];
	float fRec25[2];
	float fVec7[8192];
	int iConst10;
	float fRec24[2];
	float fVec8[2048];
	int iConst11;
	float fRec6[2];
	float fVec9[2048];
	int iConst12;
	float fRec4[2];
	float fVec10[2048];
	int iConst13;
	float fRec2[2];
	float fVec11[1024];
	int iConst14;
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	float fRec26[2];
	
 public:
	LibFreeverb() {
	}
	
	LibFreeverb(const LibFreeverb&) = default;
	
	virtual ~LibFreeverb() = default;
	
	LibFreeverb& operator=(const LibFreeverb&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Romain Michon (Faust port), Jezar at Dreampoint");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibFreeverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Jezar's Freeverb: 8 lowpass-comb filters + 4 allpasses, the classic free reverb");
		m->declare("family", "reverb");
		m->declare("filename", "lib-freeverb.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "LGPL-2.1-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Freeverb");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/mono_freeverb:author", "Romain Michon");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.5.1");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/reverbs.lib re.mono_freeverb");
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
		iConst3 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.025306122f * fConst0), -1));
		iConst4 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.026938776f * fConst0), -1));
		iConst5 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.028956916f * fConst0), -1));
		iConst6 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.030748298f * fConst0), -1));
		iConst7 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.0322449f * fConst0), -1));
		iConst8 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.033809524f * fConst0), -1));
		iConst9 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.035306122f * fConst0), -1));
		iConst10 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.036666665f * fConst0), -1));
		iConst11 = std::min<int>(1024, std::max<int>(0, faust_wrap_add(static_cast<int>(0.0126077095f * fConst0), -1)));
		iConst12 = std::min<int>(1024, std::max<int>(0, faust_wrap_add(static_cast<int>(0.01f * fConst0), -1)));
		iConst13 = std::min<int>(1024, std::max<int>(0, faust_wrap_add(static_cast<int>(0.0077324263f * fConst0), -1)));
		iConst14 = std::min<int>(1024, std::max<int>(0, faust_wrap_add(static_cast<int>(0.0051020407f * fConst0), -1)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.6f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.35f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec9[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec11[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec10[l2] = 0.0f;
		}
		IOTA0 = 0;
		for (int l3 = 0; l3 < 8192; l3 = faust_wrap_add(l3, 1)) {
			fVec0[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec8[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec13[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 8192; l6 = faust_wrap_add(l6, 1)) {
			fVec1[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec12[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec15[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 8192; l9 = faust_wrap_add(l9, 1)) {
			fVec2[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec14[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec17[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 8192; l12 = faust_wrap_add(l12, 1)) {
			fVec3[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec16[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec19[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 8192; l15 = faust_wrap_add(l15, 1)) {
			fVec4[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec18[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec21[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 8192; l18 = faust_wrap_add(l18, 1)) {
			fVec5[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec20[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec23[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 8192; l21 = faust_wrap_add(l21, 1)) {
			fVec6[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec22[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec25[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 8192; l24 = faust_wrap_add(l24, 1)) {
			fVec7[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec24[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2048; l26 = faust_wrap_add(l26, 1)) {
			fVec8[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec6[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2048; l28 = faust_wrap_add(l28, 1)) {
			fVec9[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec4[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2048; l30 = faust_wrap_add(l30, 1)) {
			fVec10[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec2[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 1024; l32 = faust_wrap_add(l32, 1)) {
			fVec11[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec0[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec26[l34] = 0.0f;
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
	
	virtual LibFreeverb* clone() {
		return new LibFreeverb(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Freeverb");
		ui_interface->declare(&fHslider0, "0", "");
		ui_interface->addHorizontalSlider("Room Size", &fHslider0, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Damping", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider2, FAUSTFLOAT(0.35f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec9[0] = fSlow0 + fConst2 * fRec9[1];
			float fTemp0 = 0.28f * fRec9[0] + 0.7f;
			fRec11[0] = fSlow1 + fConst2 * fRec11[1];
			float fTemp1 = 1.0f - 0.4f * fRec11[0];
			fRec10[0] = 0.4f * fRec11[0] * fRec10[1] + fRec8[1] * fTemp1;
			float fTemp2 = static_cast<float>(input0[i0]);
			fVec0[IOTA0 & 8191] = fTemp2 + fRec10[0] * fTemp0;
			fRec8[0] = fVec0[(faust_wrap_sub(IOTA0, iConst3)) & 8191];
			fRec13[0] = 0.4f * fRec11[0] * fRec13[1] + fTemp1 * fRec12[1];
			fVec1[IOTA0 & 8191] = fTemp2 + fRec13[0] * fTemp0;
			fRec12[0] = fVec1[(faust_wrap_sub(IOTA0, iConst4)) & 8191];
			fRec15[0] = 0.4f * fRec11[0] * fRec15[1] + fTemp1 * fRec14[1];
			fVec2[IOTA0 & 8191] = fTemp2 + fRec15[0] * fTemp0;
			fRec14[0] = fVec2[(faust_wrap_sub(IOTA0, iConst5)) & 8191];
			fRec17[0] = 0.4f * fRec11[0] * fRec17[1] + fTemp1 * fRec16[1];
			fVec3[IOTA0 & 8191] = fTemp2 + fRec17[0] * fTemp0;
			fRec16[0] = fVec3[(faust_wrap_sub(IOTA0, iConst6)) & 8191];
			fRec19[0] = 0.4f * fRec11[0] * fRec19[1] + fTemp1 * fRec18[1];
			fVec4[IOTA0 & 8191] = fTemp2 + fRec19[0] * fTemp0;
			fRec18[0] = fVec4[(faust_wrap_sub(IOTA0, iConst7)) & 8191];
			fRec21[0] = 0.4f * fRec11[0] * fRec21[1] + fTemp1 * fRec20[1];
			fVec5[IOTA0 & 8191] = fTemp2 + fRec21[0] * fTemp0;
			fRec20[0] = fVec5[(faust_wrap_sub(IOTA0, iConst8)) & 8191];
			fRec23[0] = 0.4f * fRec11[0] * fRec23[1] + fTemp1 * fRec22[1];
			fVec6[IOTA0 & 8191] = fTemp2 + fRec23[0] * fTemp0;
			fRec22[0] = fVec6[(faust_wrap_sub(IOTA0, iConst9)) & 8191];
			fRec25[0] = 0.4f * fRec11[0] * fRec25[1] + fTemp1 * fRec24[1];
			fVec7[IOTA0 & 8191] = fTemp2 + fRec25[0] * fTemp0;
			fRec24[0] = fVec7[(faust_wrap_sub(IOTA0, iConst10)) & 8191];
			float fTemp3 = fRec24[1] + fRec22[1] + fRec20[1] + fRec18[1] + fRec16[1] + fRec14[1] + fRec12[1] + 0.5f * fRec6[1] + fRec8[1];
			fVec8[IOTA0 & 2047] = fTemp3;
			fRec6[0] = fVec8[(faust_wrap_sub(IOTA0, iConst11)) & 2047];
			float fRec7 = -(0.5f * fTemp3);
			float fTemp4 = fRec6[1] + fRec7 + 0.5f * fRec4[1];
			fVec9[IOTA0 & 2047] = fTemp4;
			fRec4[0] = fVec9[(faust_wrap_sub(IOTA0, iConst12)) & 2047];
			float fRec5 = -(0.5f * fTemp4);
			float fTemp5 = fRec4[1] + fRec5 + 0.5f * fRec2[1];
			fVec10[IOTA0 & 2047] = fTemp5;
			fRec2[0] = fVec10[(faust_wrap_sub(IOTA0, iConst13)) & 2047];
			float fRec3 = -(0.5f * fTemp5);
			float fTemp6 = fRec2[1] + fRec3 + 0.5f * fRec0[1];
			fVec11[IOTA0 & 1023] = fTemp6;
			fRec0[0] = fVec11[(faust_wrap_sub(IOTA0, iConst14)) & 1023];
			float fRec1 = -(0.5f * fTemp6);
			fRec26[0] = fSlow2 + fConst2 * fRec26[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp2 * (1.0f - fRec26[0]) + fRec26[0] * (fRec1 + fRec0[1]));
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec8[1] = fRec8[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec26[1] = fRec26[0];
		}
	}

};

#endif
