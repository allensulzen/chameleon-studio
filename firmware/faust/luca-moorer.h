/* ------------------------------------------------------------
author: "Luca Spanedda"
license: "MIT"
name: "Moorer Reverb"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LucaMoorer -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LucaMoorer_H__
#define  __LucaMoorer_H__

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
#define FAUSTCLASS LucaMoorer
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


class LucaMoorer : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec2[2];
	float fRec1[2];
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	int IOTA0;
	float fVec0[16384];
	int iConst3;
	int iConst4;
	int iConst5;
	int iConst6;
	int iConst7;
	int iConst8;
	int iConst9;
	int iConst10;
	int iConst11;
	int iConst12;
	int iConst13;
	int iConst14;
	int iConst15;
	int iConst16;
	int iConst17;
	int iConst18;
	int iConst19;
	int iConst20;
	float fVec1[16384];
	int iConst21;
	float fRec0[2];
	float fRec5[2];
	float fVec2[16384];
	int iConst22;
	float fRec4[2];
	float fRec7[2];
	float fVec3[16384];
	int iConst23;
	float fRec6[2];
	float fRec9[2];
	float fVec4[16384];
	int iConst24;
	float fRec8[2];
	float fRec11[2];
	float fVec5[16384];
	int iConst25;
	float fRec10[2];
	float fRec13[2];
	float fVec6[16384];
	int iConst26;
	float fRec12[2];
	FAUSTFLOAT fHslider2;
	float fRec14[2];
	
 public:
	LucaMoorer() {
	}
	
	LucaMoorer(const LucaMoorer&) = default;
	
	virtual ~LucaMoorer() = default;
	
	LucaMoorer& operator=(const LucaMoorer&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Luca Spanedda");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LucaMoorer -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "James Moorer's 1979 reverb: 18-tap early reflections into 6 lowpass-feedback combs - classic natural-sounding room");
		m->declare("family", "reverb");
		m->declare("filename", "luca-moorer.dsp");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Moorer Reverb");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "LucaSpanedda/Digital_Reverberation_in_Faust src/reverberation.lib moorerReverb");
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
		iConst3 = static_cast<int>(0.0797f * fConst0);
		iConst4 = static_cast<int>(0.0753f * fConst0);
		iConst5 = static_cast<int>(0.0741f * fConst0);
		iConst6 = static_cast<int>(0.0726f * fConst0);
		iConst7 = static_cast<int>(0.0707f * fConst0);
		iConst8 = static_cast<int>(0.0595f * fConst0);
		iConst9 = static_cast<int>(0.0587f * fConst0);
		iConst10 = static_cast<int>(0.0572f * fConst0);
		iConst11 = static_cast<int>(0.0485f * fConst0);
		iConst12 = static_cast<int>(0.0458f * fConst0);
		iConst13 = static_cast<int>(0.0298f * fConst0);
		iConst14 = static_cast<int>(0.027f * fConst0);
		iConst15 = static_cast<int>(0.0268f * fConst0);
		iConst16 = static_cast<int>(0.0225f * fConst0);
		iConst17 = static_cast<int>(0.0215f * fConst0);
		iConst18 = static_cast<int>(0.0043f * fConst0);
		iConst19 = static_cast<int>(0.0708f * fConst0);
		iConst20 = static_cast<int>(0.0612f * fConst0);
		iConst21 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.078f * fConst0), -1));
		iConst22 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.072f * fConst0), -1));
		iConst23 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.068f * fConst0), -1));
		iConst24 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.061f * fConst0), -1));
		iConst25 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.056f * fConst0), -1));
		iConst26 = std::max<int>(0, faust_wrap_add(static_cast<int>(0.05f * fConst0), -1));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.4f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.7f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.35f);
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
		IOTA0 = 0;
		for (int l3 = 0; l3 < 16384; l3 = faust_wrap_add(l3, 1)) {
			fVec0[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 16384; l4 = faust_wrap_add(l4, 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec0[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 16384; l7 = faust_wrap_add(l7, 1)) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec4[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 16384; l10 = faust_wrap_add(l10, 1)) {
			fVec3[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec6[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec9[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 16384; l13 = faust_wrap_add(l13, 1)) {
			fVec4[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec8[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec11[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 16384; l16 = faust_wrap_add(l16, 1)) {
			fVec5[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec10[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec13[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 16384; l19 = faust_wrap_add(l19, 1)) {
			fVec6[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec12[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec14[l21] = 0.0f;
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
	
	virtual LucaMoorer* clone() {
		return new LucaMoorer(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Moorer Reverb");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider2, FAUSTFLOAT(0.35f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Comb Feedback", &fHslider1, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.3f), FAUSTFLOAT(0.9f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->addHorizontalSlider("Damping", &fHslider0, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.9f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec2[0] = fSlow0 + fConst2 * fRec2[1];
			float fTemp0 = 1.0f - fRec2[0];
			fRec1[0] = fRec2[0] * fRec1[1] + fTemp0 * fRec0[1];
			fRec3[0] = fSlow1 + fConst2 * fRec3[1];
			float fTemp1 = static_cast<float>(input0[i0]);
			fVec0[IOTA0 & 16383] = fTemp1;
			float fTemp2 = 0.0134f * fVec0[(faust_wrap_sub(IOTA0, iConst3)) & 16383];
			float fTemp3 = 0.0167f * fVec0[(faust_wrap_sub(IOTA0, iConst4)) & 16383];
			float fTemp4 = 0.0142f * fVec0[(faust_wrap_sub(IOTA0, iConst5)) & 16383];
			float fTemp5 = 0.0176f * fVec0[(faust_wrap_sub(IOTA0, iConst6)) & 16383];
			float fTemp6 = 0.018f * fVec0[(faust_wrap_sub(IOTA0, iConst7)) & 16383];
			float fTemp7 = 0.0217f * fVec0[(faust_wrap_sub(IOTA0, iConst8)) & 16383];
			float fTemp8 = 0.0193f * fVec0[(faust_wrap_sub(IOTA0, iConst9)) & 16383];
			float fTemp9 = 0.0192f * fVec0[(faust_wrap_sub(IOTA0, iConst10)) & 16383];
			float fTemp10 = 0.0272f * fVec0[(faust_wrap_sub(IOTA0, iConst11)) & 16383];
			float fTemp11 = 0.0289f * fVec0[(faust_wrap_sub(IOTA0, iConst12)) & 16383];
			float fTemp12 = 0.0346f * fVec0[(faust_wrap_sub(IOTA0, iConst13)) & 16383];
			float fTemp13 = 0.038f * fVec0[(faust_wrap_sub(IOTA0, iConst14)) & 16383];
			float fTemp14 = 0.0379f * fVec0[(faust_wrap_sub(IOTA0, iConst15)) & 16383];
			float fTemp15 = 0.0491f * fVec0[(faust_wrap_sub(IOTA0, iConst16)) & 16383];
			float fTemp16 = 0.0504f * fVec0[(faust_wrap_sub(IOTA0, iConst17)) & 16383];
			float fTemp17 = 0.0841f * fVec0[(faust_wrap_sub(IOTA0, iConst18)) & 16383];
			float fTemp18 = 0.0181f * (fVec0[(faust_wrap_sub(IOTA0, iConst20)) & 16383] + fVec0[(faust_wrap_sub(IOTA0, iConst19)) & 16383]);
			float fTemp19 = fTemp18 + fTemp17 + fTemp16 + fTemp15 + fTemp14 + fTemp13 + fTemp12 + fTemp11 + fTemp10 + fTemp9 + fTemp8 + fTemp7 + fTemp6 + fTemp5 + fTemp4 + fTemp3 + fTemp2;
			fVec1[IOTA0 & 16383] = fTemp19 + fRec3[0] * fRec1[0];
			fRec0[0] = fVec1[(faust_wrap_sub(IOTA0, iConst21)) & 16383];
			fRec5[0] = fRec2[0] * fRec5[1] + fTemp0 * fRec4[1];
			fVec2[IOTA0 & 16383] = fTemp19 + fRec3[0] * fRec5[0];
			fRec4[0] = fVec2[(faust_wrap_sub(IOTA0, iConst22)) & 16383];
			fRec7[0] = fRec2[0] * fRec7[1] + fTemp0 * fRec6[1];
			fVec3[IOTA0 & 16383] = fTemp19 + fRec3[0] * fRec7[0];
			fRec6[0] = fVec3[(faust_wrap_sub(IOTA0, iConst23)) & 16383];
			fRec9[0] = fRec2[0] * fRec9[1] + fTemp0 * fRec8[1];
			fVec4[IOTA0 & 16383] = fTemp19 + fRec3[0] * fRec9[0];
			fRec8[0] = fVec4[(faust_wrap_sub(IOTA0, iConst24)) & 16383];
			fRec11[0] = fRec2[0] * fRec11[1] + fTemp0 * fRec10[1];
			fVec5[IOTA0 & 16383] = fTemp19 + fRec3[0] * fRec11[0];
			fRec10[0] = fVec5[(faust_wrap_sub(IOTA0, iConst25)) & 16383];
			fRec13[0] = fRec2[0] * fRec13[1] + fTemp0 * fRec12[1];
			fVec6[IOTA0 & 16383] = fTemp2 + fTemp3 + fTemp4 + fTemp5 + fTemp18 + fTemp6 + fTemp7 + fTemp8 + fTemp9 + fTemp10 + fTemp11 + fTemp12 + fTemp13 + fTemp14 + fTemp15 + fTemp16 + fRec13[0] * fRec3[0] + fTemp17;
			fRec12[0] = fVec6[(faust_wrap_sub(IOTA0, iConst26)) & 16383];
			fRec14[0] = fSlow2 + fConst2 * fRec14[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp1 * (1.0f - fRec14[0]) + 3.0f * fRec14[0] * (fTemp19 + 0.3f * (fRec12[1] + fRec10[1] + fRec8[1] + fRec6[1] + fRec4[1] + fRec0[1])));
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec0[1] = fRec0[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec14[1] = fRec14[0];
		}
	}

};

#endif
