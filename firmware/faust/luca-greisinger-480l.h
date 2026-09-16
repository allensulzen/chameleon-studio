/* ------------------------------------------------------------
author: "Luca Spanedda"
license: "MIT"
name: "Greisinger 480L"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LucaGreisinger480l -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LucaGreisinger480l_H__
#define  __LucaGreisinger480l_H__

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
#define FAUSTCLASS LucaGreisinger480l
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

class LucaGreisinger480lSIG0 {
	
  private:
	
	int iVec7[2];
	int iRec23[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsLucaGreisinger480lSIG0() {
		return 0;
	}
	int getNumOutputsLucaGreisinger480lSIG0() {
		return 1;
	}
	
	void instanceInitLucaGreisinger480lSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			iVec7[l13] = 0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			iRec23[l14] = 0;
		}
	}
	
	void fillLucaGreisinger480lSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec7[0] = 1;
			iRec23[0] = (faust_wrap_add(iVec7[1], iRec23[1])) % 65536;
			table[i1] = std::sin(9.58738e-05f * static_cast<float>(iRec23[0]));
			iVec7[1] = iVec7[0];
			iRec23[1] = iRec23[0];
		}
	}

};

static LucaGreisinger480lSIG0* newLucaGreisinger480lSIG0() { return (LucaGreisinger480lSIG0*)new LucaGreisinger480lSIG0(); }
static void deleteLucaGreisinger480lSIG0(LucaGreisinger480lSIG0* dsp) { delete dsp; }

static float DSY_SDRAM_BSS ftbl0LucaGreisinger480lSIG0[65536];

class LucaGreisinger480l : public chdsp {
	
 private:
	
	int iVec0[2];
	int IOTA0;
	float fVec1[8192];
	int fSampleRate;
	float fConst0;
	int iConst1;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider0;
	float fRec22[2];
	float fRec21[2];
	float fVec2[1024];
	int iConst4;
	float fRec19[2];
	float fVec3[1024];
	int iConst5;
	float fRec17[2];
	float fVec4[4096];
	int iConst6;
	float fRec15[2];
	float fVec5[2048];
	int iConst7;
	float fRec13[2];
	float fVec6[8192];
	int iConst8;
	int iConst9;
	int iConst10;
	float fConst11;
	float fRec24[2];
	float fConst12;
	float fConst13;
	float fRec11[2];
	float fVec8[32768];
	int iConst14;
	float fRec10[2];
	float fVec9[16384];
	int iConst15;
	float fRec8[2];
	float fVec10[32768];
	int iConst16;
	int iConst17;
	FAUSTFLOAT fHslider1;
	float fRec25[2];
	float fRec0[2];
	float fVec11[8192];
	int iConst18;
	int iConst19;
	float fConst20;
	float fRec31[2];
	float fConst21;
	float fRec29[2];
	float fVec12[32768];
	int iConst22;
	float fRec28[2];
	float fVec13[32768];
	int iConst23;
	float fRec26[2];
	float fVec14[32768];
	int iConst24;
	int iConst25;
	float fRec1[2];
	float fRec2[32768];
	float fRec3[16384];
	float fRec4[16384];
	float fRec5[32768];
	float fRec6[8192];
	float fRec7[32768];
	int iConst26;
	int iConst27;
	int iConst28;
	int iConst29;
	int iConst30;
	int iConst31;
	int iConst32;
	int iConst33;
	int iConst34;
	int iConst35;
	int iConst36;
	int iConst37;
	int iConst38;
	int iConst39;
	FAUSTFLOAT fHslider2;
	float fRec32[2];
	
 public:
	LucaGreisinger480l() {
	}
	
	LucaGreisinger480l(const LucaGreisinger480l&) = default;
	
	virtual ~LucaGreisinger480l() = default;
	
	LucaGreisinger480l& operator=(const LucaGreisinger480l&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Luca Spanedda");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LucaGreisinger480l -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Dattorro/Greisinger Lexicon 480L-topology plate reverb (Tom Erbe's design): modulated allpass loops with cross-coupled tanks, mono wrap");
		m->declare("family", "reverb");
		m->declare("filename", "luca-greisinger-480l.dsp");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Greisinger 480L");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "LucaSpanedda/Digital_Reverberation_in_Faust src/reverberation.lib greisingerReverb");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		LucaGreisinger480lSIG0* sig0 = newLucaGreisinger480lSIG0();
		sig0->instanceInitLucaGreisinger480lSIG0(sample_rate);
		sig0->fillLucaGreisinger480lSIG0(65536, ftbl0LucaGreisinger480lSIG0);
		deleteLucaGreisinger480lSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		iConst1 = std::max<int>(2, static_cast<int>(0.03f * fConst0));
		fConst2 = 44.1f / fConst0;
		fConst3 = 1.0f - fConst2;
		iConst4 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.004771f * fConst0)), -1);
		iConst5 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.003595f * fConst0)), -1);
		iConst6 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.01273f * fConst0)), -1);
		iConst7 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.009307f * fConst0)), -1);
		iConst8 = std::max<int>(2, static_cast<int>(0.004f * fConst0));
		iConst9 = std::max<int>(2, static_cast<int>(0.02258f * fConst0));
		iConst10 = faust_wrap_add(iConst9, iConst8);
		fConst11 = 0.07f / fConst0;
		fConst12 = static_cast<float>(iConst8);
		fConst13 = static_cast<float>(faust_wrap_add(iConst9, -1));
		iConst14 = std::max<int>(2, static_cast<int>(0.14962f * fConst0));
		iConst15 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.06048f * fConst0)), -1);
		iConst16 = std::max<int>(2, static_cast<int>(0.125f * fConst0));
		iConst17 = faust_wrap_add(iConst16, -1);
		iConst18 = std::max<int>(2, static_cast<int>(0.03051f * fConst0));
		iConst19 = faust_wrap_add(iConst8, iConst18);
		fConst20 = 0.1f / fConst0;
		fConst21 = static_cast<float>(faust_wrap_add(iConst18, -1));
		iConst22 = std::max<int>(2, static_cast<int>(0.14169f * fConst0));
		iConst23 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.08924f * fConst0)), -1);
		iConst24 = std::max<int>(2, static_cast<int>(0.10628f * fConst0));
		iConst25 = faust_wrap_add(iConst24, -1);
		iConst26 = std::max<int>(2, static_cast<int>(0.0708f * fConst0));
		iConst27 = std::max<int>(2, static_cast<int>(0.0998f * fConst0));
		iConst28 = std::max<int>(2, static_cast<int>(0.0358f * fConst0));
		iConst29 = std::max<int>(2, static_cast<int>(0.0668f * fConst0));
		iConst30 = std::max<int>(2, static_cast<int>(0.0642f * fConst0));
		iConst31 = std::max<int>(2, static_cast<int>(0.0089f * fConst0));
		iConst32 = std::max<int>(2, static_cast<int>(0.067f * fConst0));
		iConst33 = std::max<int>(2, static_cast<int>(0.0063f * fConst0));
		iConst34 = std::max<int>(2, static_cast<int>(0.0041f * fConst0));
		iConst35 = std::max<int>(2, static_cast<int>(0.1217f * fConst0));
		iConst36 = std::max<int>(2, static_cast<int>(0.0897f * fConst0));
		iConst37 = std::max<int>(2, static_cast<int>(0.0112f * fConst0));
		iConst38 = std::max<int>(2, static_cast<int>(0.0118f * fConst0));
		iConst39 = std::max<int>(2, static_cast<int>(0.0412f * fConst0));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.4f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.7f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.35f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 8192; l1 = faust_wrap_add(l1, 1)) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec22[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec21[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 1024; l4 = faust_wrap_add(l4, 1)) {
			fVec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec19[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 1024; l6 = faust_wrap_add(l6, 1)) {
			fVec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec17[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 4096; l8 = faust_wrap_add(l8, 1)) {
			fVec4[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec15[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2048; l10 = faust_wrap_add(l10, 1)) {
			fVec5[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec13[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 8192; l12 = faust_wrap_add(l12, 1)) {
			fVec6[l12] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec24[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec11[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 32768; l17 = faust_wrap_add(l17, 1)) {
			fVec8[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec10[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 16384; l19 = faust_wrap_add(l19, 1)) {
			fVec9[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec8[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 32768; l21 = faust_wrap_add(l21, 1)) {
			fVec10[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec25[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec0[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 8192; l24 = faust_wrap_add(l24, 1)) {
			fVec11[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec31[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec29[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 32768; l27 = faust_wrap_add(l27, 1)) {
			fVec12[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec28[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 32768; l29 = faust_wrap_add(l29, 1)) {
			fVec13[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec26[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 32768; l31 = faust_wrap_add(l31, 1)) {
			fVec14[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec1[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 32768; l33 = faust_wrap_add(l33, 1)) {
			fRec2[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 16384; l34 = faust_wrap_add(l34, 1)) {
			fRec3[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 16384; l35 = faust_wrap_add(l35, 1)) {
			fRec4[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 32768; l36 = faust_wrap_add(l36, 1)) {
			fRec5[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 8192; l37 = faust_wrap_add(l37, 1)) {
			fRec6[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 32768; l38 = faust_wrap_add(l38, 1)) {
			fRec7[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec32[l39] = 0.0f;
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
	
	virtual LucaGreisinger480l* clone() {
		return new LucaGreisinger480l(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Greisinger 480L");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->addHorizontalSlider("Decay", &fHslider1, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->addHorizontalSlider("Damping", &fHslider0, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.9f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider2, FAUSTFLOAT(0.35f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst2 * static_cast<float>(fHslider0);
		float fSlow1 = fConst2 * static_cast<float>(fHslider1);
		float fSlow2 = fConst2 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			float fTemp0 = static_cast<float>(input0[i0]);
			fVec1[IOTA0 & 8191] = fTemp0;
			fRec22[0] = fSlow0 + fConst3 * fRec22[1];
			float fTemp1 = 1.0f - std::fabs(fRec22[0]);
			fRec21[0] = fRec22[0] * fRec21[1] + fTemp1 * fVec1[(faust_wrap_sub(IOTA0, iConst1)) & 8191];
			float fTemp2 = fRec21[0] + 0.75f * fRec19[1];
			fVec2[IOTA0 & 1023] = fTemp2;
			fRec19[0] = fVec2[(faust_wrap_sub(IOTA0, iConst4)) & 1023];
			float fRec20 = -(0.75f * fTemp2);
			float fTemp3 = fRec19[1] + fRec20 + 0.75f * fRec17[1];
			fVec3[IOTA0 & 1023] = fTemp3;
			fRec17[0] = fVec3[(faust_wrap_sub(IOTA0, iConst5)) & 1023];
			float fRec18 = -(0.75f * fTemp3);
			float fTemp4 = fRec17[1] + fRec18 + 0.625f * fRec15[1];
			fVec4[IOTA0 & 4095] = fTemp4;
			fRec15[0] = fVec4[(faust_wrap_sub(IOTA0, iConst6)) & 4095];
			float fRec16 = -(0.625f * fTemp4);
			float fTemp5 = fRec15[1] + fRec16 + 0.625f * fRec13[1];
			fVec5[IOTA0 & 2047] = fTemp5;
			fRec13[0] = fVec5[(faust_wrap_sub(IOTA0, iConst7)) & 2047];
			float fRec14 = -(0.625f * fTemp5);
			float fTemp6 = fRec13[1] + fRec1[1] + fRec14 + 0.7f * fRec11[1];
			fVec6[IOTA0 & 8191] = fTemp6;
			int iTemp7 = faust_wrap_sub(1, iVec0[1]);
			float fTemp8 = ((iTemp7) ? 0.0f : fConst11 + fRec24[1]);
			fRec24[0] = fTemp8 - std::floor(fTemp8);
			float fTemp9 = fConst12 * ftbl0LucaGreisinger480lSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec24[0]), 65535))];
			float fTemp10 = fConst13 + fTemp9;
			int iTemp11 = static_cast<int>(fTemp10);
			float fTemp12 = std::floor(fTemp10);
			fRec11[0] = fVec6[(faust_wrap_sub(IOTA0, std::min<int>(iConst10, std::max<int>(0, iTemp11)))) & 8191] * (fTemp12 + (1.0f - fTemp9) - fConst13) + (fConst13 + (fTemp9 - fTemp12)) * fVec6[(faust_wrap_sub(IOTA0, std::min<int>(iConst10, std::max<int>(0, faust_wrap_add(iTemp11, 1))))) & 8191];
			float fRec12 = -(0.7f * fTemp6);
			fVec8[IOTA0 & 32767] = fRec12 + fRec11[1];
			float fTemp13 = fVec8[(faust_wrap_sub(IOTA0, iConst14)) & 32767];
			fRec10[0] = fRec22[0] * fRec10[1] + fTemp1 * fTemp13;
			float fTemp14 = fRec10[0] + 0.5f * fRec8[1];
			fVec9[IOTA0 & 16383] = fTemp14;
			fRec8[0] = fVec9[(faust_wrap_sub(IOTA0, iConst15)) & 16383];
			float fRec9 = -(0.5f * fTemp14);
			float fTemp15 = fRec9 + fRec8[1];
			fVec10[IOTA0 & 32767] = fTemp15;
			fRec25[0] = fSlow1 + fConst3 * fRec25[1];
			fRec0[0] = fRec25[0] * fVec10[(faust_wrap_sub(IOTA0, iConst17)) & 32767];
			float fTemp16 = fRec0[1] + fRec14 + fRec13[1] + 0.7f * fRec29[1];
			fVec11[IOTA0 & 8191] = fTemp16;
			float fTemp17 = ((iTemp7) ? 0.0f : fConst20 + fRec31[1]);
			fRec31[0] = fTemp17 - std::floor(fTemp17);
			float fTemp18 = fConst12 * ftbl0LucaGreisinger480lSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec31[0]), 65535))];
			float fTemp19 = fConst21 + fTemp18;
			int iTemp20 = static_cast<int>(fTemp19);
			float fTemp21 = std::floor(fTemp19);
			fRec29[0] = fVec11[(faust_wrap_sub(IOTA0, std::min<int>(iConst19, std::max<int>(0, iTemp20)))) & 8191] * (fTemp21 + (1.0f - fTemp18) - fConst21) + (fConst21 + (fTemp18 - fTemp21)) * fVec11[(faust_wrap_sub(IOTA0, std::min<int>(iConst19, std::max<int>(0, faust_wrap_add(iTemp20, 1))))) & 8191];
			float fRec30 = -(0.7f * fTemp16);
			fVec12[IOTA0 & 32767] = fRec30 + fRec29[1];
			float fTemp22 = fVec12[(faust_wrap_sub(IOTA0, iConst22)) & 32767];
			fRec28[0] = fRec22[0] * fRec28[1] + fTemp1 * fTemp22;
			float fTemp23 = fRec28[0] + 0.5f * fRec26[1];
			fVec13[IOTA0 & 32767] = fTemp23;
			fRec26[0] = fVec13[(faust_wrap_sub(IOTA0, iConst23)) & 32767];
			float fRec27 = -(0.5f * fTemp23);
			float fTemp24 = fRec27 + fRec26[1];
			fVec14[IOTA0 & 32767] = fTemp24;
			fRec1[0] = fRec25[0] * fVec14[(faust_wrap_sub(IOTA0, iConst25)) & 32767];
			fRec2[IOTA0 & 32767] = fTemp22;
			fRec3[IOTA0 & 16383] = fTemp24;
			fRec4[IOTA0 & 16383] = fVec14[(faust_wrap_sub(IOTA0, iConst24)) & 32767];
			fRec5[IOTA0 & 32767] = fTemp13;
			fRec6[IOTA0 & 8191] = fTemp15;
			fRec7[IOTA0 & 32767] = fVec10[(faust_wrap_sub(IOTA0, iConst16)) & 32767];
			fRec32[0] = fSlow2 + fConst3 * fRec32[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec32[0]) + 0.5f * fRec32[0] * (fRec6[(faust_wrap_sub(IOTA0, iConst39)) & 8191] + fRec5[(faust_wrap_sub(IOTA0, iConst38)) & 32767] + fRec3[(faust_wrap_sub(IOTA0, iConst37)) & 16383] + fRec7[(faust_wrap_sub(IOTA0, iConst36)) & 32767] + fRec5[(faust_wrap_sub(IOTA0, iConst35)) & 32767] + fRec4[(faust_wrap_sub(IOTA0, iConst34)) & 16383] + fRec6[(faust_wrap_sub(IOTA0, iConst33)) & 8191] + fRec4[(faust_wrap_sub(IOTA0, iConst32)) & 16383] + fRec2[(faust_wrap_sub(IOTA0, iConst31)) & 32767] + fRec3[(faust_wrap_sub(IOTA0, iConst30)) & 16383] + fRec5[(faust_wrap_sub(IOTA0, iConst29)) & 32767] + fRec7[(faust_wrap_sub(IOTA0, iConst28)) & 32767] + fRec2[(faust_wrap_sub(IOTA0, iConst27)) & 32767] + fRec2[(faust_wrap_sub(IOTA0, iConst26)) & 32767]));
			iVec0[1] = iVec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec17[1] = fRec17[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec24[1] = fRec24[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
			fRec25[1] = fRec25[0];
			fRec0[1] = fRec0[0];
			fRec31[1] = fRec31[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec1[1] = fRec1[0];
			fRec32[1] = fRec32[0];
		}
	}

};

#endif
