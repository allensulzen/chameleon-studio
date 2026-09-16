/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Shimmer"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgShimmer -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgShimmer_H__
#define  __TdgShimmer_H__

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
#define FAUSTCLASS TdgShimmer
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

class TdgShimmerSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec10[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsTdgShimmerSIG0() {
		return 0;
	}
	int getNumOutputsTdgShimmerSIG0() {
		return 1;
	}
	
	void instanceInitTdgShimmerSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			iVec1[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			iRec10[l4] = 0;
		}
	}
	
	void fillTdgShimmerSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec1[0] = 1;
			iRec10[0] = (faust_wrap_add(iVec1[1], iRec10[1])) % 65536;
			table[i1] = std::sin(9.58738e-05f * static_cast<float>(iRec10[0]));
			iVec1[1] = iVec1[0];
			iRec10[1] = iRec10[0];
		}
	}

};

static TdgShimmerSIG0* newTdgShimmerSIG0() { return (TdgShimmerSIG0*)new TdgShimmerSIG0(); }
static void deleteTdgShimmerSIG0(TdgShimmerSIG0* dsp) { delete dsp; }

static float DSY_SDRAM_BSS ftbl0TdgShimmerSIG0[65536];

class TdgShimmer : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec3[2];
	FAUSTFLOAT fHslider1;
	float fRec6[2];
	FAUSTFLOAT fHslider2;
	float fConst3;
	float fRec11[2];
	FAUSTFLOAT fHslider3;
	float fRec12[2];
	FAUSTFLOAT fHslider4;
	float fRec13[2];
	FAUSTFLOAT fHslider5;
	float fRec14[2];
	FAUSTFLOAT fHslider6;
	float fRec15[2];
	float fRec9[2];
	int IOTA0;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider7;
	float fRec21[2];
	float fVec2[2];
	float fConst6;
	float fRec20[8192];
	float fVec3[4096];
	FAUSTFLOAT fHslider8;
	float fVec4[64];
	float fConst7;
	float fRec22[2];
	float fRec18[2];
	float fVec5[4096];
	float fRec16[2];
	float fRec17[131072];
	float fVec6[8192];
	float fVec7[64];
	float fConst8;
	float fRec23[2];
	float fRec7[2];
	float fVec8[8192];
	float fRec4[2];
	float fRec2[3];
	float fRec0[2];
	float fVec9[2];
	float fRec33[8192];
	float fVec10[8192];
	float fVec11[64];
	float fConst9;
	float fRec34[2];
	float fRec31[2];
	float fVec12[8192];
	float fRec29[2];
	float fRec30[131072];
	float fVec13[2048];
	float fVec14[64];
	float fRec35[2];
	float fRec27[2];
	float fVec15[2048];
	float fRec25[2];
	float fRec24[3];
	float fRec1[2];
	FAUSTFLOAT fHslider9;
	float fRec36[2];
	
 public:
	TdgShimmer() {
	}
	
	TdgShimmer(const TdgShimmer&) = default;
	
	virtual ~TdgShimmer() = default;
	
	TdgShimmer& operator=(const TdgShimmer&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgShimmer -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "ValhallaShimmer-inspired reverb: modulated nested allpass diffusers with pitch-shifted feedback path (envelope/LFO controllable shift)");
		m->declare("family", "reverb");
		m->declare("filename", "tdg-shimmer.dsp");
		m->declare("filters.lib/dcblockerat:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblockerat:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblockerat:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "LicenseRef-STK-4.3");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "Shimmer");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust shimmer.dsp");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		TdgShimmerSIG0* sig0 = newTdgShimmerSIG0();
		sig0->instanceInitTdgShimmerSIG0(sample_rate);
		sig0->fillTdgShimmerSIG0(65536, ftbl0TdgShimmerSIG0);
		deleteTdgShimmerSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.0f / fConst0;
		fConst4 = 251.32741f / fConst0;
		fConst5 = 1.0f - fConst4;
		fConst6 = 1.0f / (fConst4 + 1.0f);
		fConst7 = 1.3f / fConst0;
		fConst8 = 1.5f / fConst0;
		fConst9 = 0.7f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.1f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider4 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider6 = static_cast<FAUSTFLOAT>(12.0f);
		fHslider7 = static_cast<FAUSTFLOAT>(0.25f);
		fHslider8 = static_cast<FAUSTFLOAT>(1.5f);
		fHslider9 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec6[l2] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec11[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec12[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec13[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec14[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec15[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec9[l10] = 0.0f;
		}
		IOTA0 = 0;
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec21[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fVec2[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 8192; l13 = faust_wrap_add(l13, 1)) {
			fRec20[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 4096; l14 = faust_wrap_add(l14, 1)) {
			fVec3[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 64; l15 = faust_wrap_add(l15, 1)) {
			fVec4[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec22[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec18[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 4096; l18 = faust_wrap_add(l18, 1)) {
			fVec5[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec16[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 131072; l20 = faust_wrap_add(l20, 1)) {
			fRec17[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 8192; l21 = faust_wrap_add(l21, 1)) {
			fVec6[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 64; l22 = faust_wrap_add(l22, 1)) {
			fVec7[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec23[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec7[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 8192; l25 = faust_wrap_add(l25, 1)) {
			fVec8[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec4[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 3; l27 = faust_wrap_add(l27, 1)) {
			fRec2[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec0[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fVec9[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 8192; l30 = faust_wrap_add(l30, 1)) {
			fRec33[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 8192; l31 = faust_wrap_add(l31, 1)) {
			fVec10[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 64; l32 = faust_wrap_add(l32, 1)) {
			fVec11[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec34[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec31[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 8192; l35 = faust_wrap_add(l35, 1)) {
			fVec12[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec29[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 131072; l37 = faust_wrap_add(l37, 1)) {
			fRec30[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2048; l38 = faust_wrap_add(l38, 1)) {
			fVec13[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 64; l39 = faust_wrap_add(l39, 1)) {
			fVec14[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec35[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec27[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2048; l42 = faust_wrap_add(l42, 1)) {
			fVec15[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec25[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 3; l44 = faust_wrap_add(l44, 1)) {
			fRec24[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec1[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fRec36[l46] = 0.0f;
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
	
	virtual TdgShimmer* clone() {
		return new TdgShimmer(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Shimmer");
		ui_interface->declare(&fHslider4, "0", "");
		ui_interface->declare(&fHslider4, "unit", "s");
		ui_interface->addHorizontalSlider("Envelope", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("LFO Speed", &fHslider2, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.1f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider5, "2", "");
		ui_interface->addHorizontalSlider("Mod Depth", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->addHorizontalSlider("Env/LFO", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider6, "4", "");
		ui_interface->declare(&fHslider6, "unit", "semi");
		ui_interface->addHorizontalSlider("Shift", &fHslider6, FAUSTFLOAT(12.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider8, "5", "");
		ui_interface->addHorizontalSlider("Size", &fHslider8, FAUSTFLOAT(1.5f), FAUSTFLOAT(1.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider1, "6", "");
		ui_interface->addHorizontalSlider("Diffusion", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.1f), FAUSTFLOAT(0.7f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider7, "7", "");
		ui_interface->addHorizontalSlider("Feedback", &fHslider7, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.35f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "8", "");
		ui_interface->addHorizontalSlider("HF Damping", &fHslider0, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.005f), FAUSTFLOAT(0.995f), FAUSTFLOAT(0.005f));
		ui_interface->declare(&fHslider9, "9", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider9, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst3 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		float fSlow4 = static_cast<float>(fHslider4);
		int iSlow5 = std::fabs(fSlow4) < 1.1920929e-07f;
		float fSlow6 = ((iSlow5) ? 0.0f : std::exp(-(fConst3 / ((iSlow5) ? 1.0f : fSlow4))));
		float fSlow7 = 1.0f - fSlow6;
		float fSlow8 = fConst1 * static_cast<float>(fHslider5);
		float fSlow9 = fConst1 * static_cast<float>(fHslider6);
		float fSlow10 = fConst1 * static_cast<float>(fHslider7);
		float fSlow11 = static_cast<float>(fHslider8);
		int iSlow12 = static_cast<int>(1087.0f * fSlow11);
		int iSlow13 = static_cast<int>(1113.0f * fSlow11);
		int iSlow14 = static_cast<int>(2043.0f * fSlow11);
		int iSlow15 = static_cast<int>(2087.0f * fSlow11);
		int iSlow16 = static_cast<int>(2337.0f * fSlow11);
		int iSlow17 = static_cast<int>(2377.0f * fSlow11);
		int iSlow18 = static_cast<int>(601.0f * fSlow11);
		int iSlow19 = static_cast<int>(613.0f * fSlow11);
		float fSlow20 = fConst1 * static_cast<float>(fHslider9);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec3[0] = fSlow0 + fConst2 * fRec3[1];
			float fTemp0 = 1.0f - fRec3[0];
			fRec6[0] = fSlow1 + fConst2 * fRec6[1];
			float fTemp1 = static_cast<float>(input0[i0]);
			float fTemp2 = 0.3f * fTemp1;
			int iTemp3 = faust_wrap_sub(1, iVec0[1]);
			float fTemp4 = ((iTemp3) ? 0.0f : fSlow2 + fRec11[1]);
			fRec11[0] = fTemp4 - std::floor(fTemp4);
			fRec12[0] = fSlow3 + fConst2 * fRec12[1];
			float fTemp5 = std::fabs(fTemp1);
			fRec13[0] = std::max<float>(fTemp5, fRec13[1] * fSlow6 + fTemp5 * fSlow7);
			fRec14[0] = fSlow8 + fConst2 * fRec14[1];
			fRec15[0] = fSlow9 + fConst2 * fRec15[1];
			fRec9[0] = std::fmod(fRec9[1] + (2049.0f - std::pow(2.0f, 0.16666667f * fRec15[0] * (fRec14[0] * (6.0f * fRec13[0] * (1.0f - fRec12[0]) + 0.5f * fRec12[0] * ftbl0TdgShimmerSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec11[0]), 65535))]) + 0.5f))), 2048.0f);
			float fTemp6 = std::min<float>(0.0009765625f * fRec9[0], 1.0f);
			float fTemp7 = 1.0f - fTemp6;
			fRec21[0] = fSlow10 + fConst2 * fRec21[1];
			float fTemp8 = fRec21[0] * fRec1[1];
			fVec2[0] = fTemp8;
			fRec20[IOTA0 & 8191] = fConst6 * (fTemp8 - fVec2[1] + fConst5 * fRec20[(faust_wrap_sub(IOTA0, 1)) & 8191]);
			float fTemp9 = fRec20[(faust_wrap_sub(IOTA0, 4763)) & 8191];
			fVec3[IOTA0 & 4095] = 0.7f * fRec6[0] * fRec18[1] + fTemp9;
			float fTemp10 = fVec3[(faust_wrap_sub(IOTA0, iSlow12)) & 4095];
			fVec4[IOTA0 & 63] = fTemp10;
			float fTemp11 = ((iTemp3) ? 0.0f : fConst7 + fRec22[1]);
			fRec22[0] = fTemp11 - std::floor(fTemp11);
			float fTemp12 = 24.5f * (ftbl0TdgShimmerSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec22[0]), 65535))] + 1.0f);
			int iTemp13 = static_cast<int>(fTemp12);
			float fTemp14 = std::floor(fTemp12);
			fRec18[0] = fVec4[(faust_wrap_sub(IOTA0, std::min<int>(51, std::max<int>(0, iTemp13)))) & 63] * (fTemp14 + (1.0f - fTemp12)) + (fTemp12 - fTemp14) * fVec4[(faust_wrap_sub(IOTA0, std::min<int>(51, std::max<int>(0, faust_wrap_add(iTemp13, 1))))) & 63];
			float fRec19 = fRec18[1] - fTemp9;
			fVec5[IOTA0 & 4095] = fRec19 + 0.4f * fRec6[0] * fRec16[1];
			fRec16[0] = fVec5[(faust_wrap_sub(IOTA0, iSlow13)) & 4095];
			fRec17[IOTA0 & 131071] = fRec16[1] - fRec19;
			float fTemp15 = fRec9[0] + 2048.0f;
			int iTemp16 = static_cast<int>(fTemp15);
			int iTemp17 = std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp16, 1)));
			float fTemp18 = std::floor(fTemp15);
			float fTemp19 = fRec9[0] + (2048.0f - fTemp18);
			float fTemp20 = fTemp18 + (-2047.0f - fRec9[0]);
			int iTemp21 = std::min<int>(65537, std::max<int>(0, iTemp16));
			int iTemp22 = static_cast<int>(fRec9[0]);
			int iTemp23 = std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp22, 1)));
			float fTemp24 = std::floor(fRec9[0]);
			float fTemp25 = fRec9[0] - fTemp24;
			float fTemp26 = fTemp24 + (1.0f - fRec9[0]);
			int iTemp27 = std::min<int>(65537, std::max<int>(0, iTemp22));
			float fTemp28 = fRec21[0] * ((fRec17[(faust_wrap_sub(IOTA0, faust_wrap_add(iTemp27, 3111))) & 131071] * fTemp26 + fTemp25 * fRec17[(faust_wrap_sub(IOTA0, faust_wrap_add(iTemp23, 3111))) & 131071]) * fTemp6 + (fRec17[(faust_wrap_sub(IOTA0, faust_wrap_add(iTemp21, 3111))) & 131071] * fTemp20 + fTemp19 * fRec17[(faust_wrap_sub(IOTA0, faust_wrap_add(iTemp17, 3111))) & 131071]) * fTemp7);
			fVec6[IOTA0 & 8191] = fTemp28 + 0.75f * fRec6[0] * fRec7[1] + fTemp2;
			float fTemp29 = fVec6[(faust_wrap_sub(IOTA0, iSlow14)) & 8191];
			fVec7[IOTA0 & 63] = fTemp29;
			float fTemp30 = ((iTemp3) ? 0.0f : fConst8 + fRec23[1]);
			fRec23[0] = fTemp30 - std::floor(fTemp30);
			float fTemp31 = 24.5f * (ftbl0TdgShimmerSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec23[0]), 65535))] + 1.0f);
			int iTemp32 = static_cast<int>(fTemp31);
			float fTemp33 = std::floor(fTemp31);
			fRec7[0] = fVec7[(faust_wrap_sub(IOTA0, std::min<int>(51, std::max<int>(0, iTemp32)))) & 63] * (fTemp33 + (1.0f - fTemp31)) + (fTemp31 - fTemp33) * fVec7[(faust_wrap_sub(IOTA0, std::min<int>(51, std::max<int>(0, faust_wrap_add(iTemp32, 1))))) & 63];
			float fRec8 = fRec7[1] - (fTemp28 + fTemp2);
			fVec8[IOTA0 & 8191] = fRec8 + 0.75f * fRec6[0] * fRec4[1];
			fRec4[0] = fVec8[(faust_wrap_sub(IOTA0, iSlow15)) & 8191];
			float fRec5 = fRec4[1] - fRec8;
			fRec2[0] = fRec5 * fTemp0 + fRec3[0] * fRec2[2];
			fRec0[0] = fRec2[0];
			float fTemp34 = fRec21[0] * fRec0[1];
			fVec9[0] = fTemp34;
			fRec33[IOTA0 & 8191] = fConst6 * (fTemp34 - fVec9[1] + fConst5 * fRec33[(faust_wrap_sub(IOTA0, 1)) & 8191]);
			float fTemp35 = fRec33[(faust_wrap_sub(IOTA0, 4325)) & 8191];
			fVec10[IOTA0 & 8191] = 0.7f * fRec6[0] * fRec31[1] + fTemp35;
			float fTemp36 = fVec10[(faust_wrap_sub(IOTA0, iSlow16)) & 8191];
			fVec11[IOTA0 & 63] = fTemp36;
			float fTemp37 = ((iTemp3) ? 0.0f : fConst9 + fRec34[1]);
			fRec34[0] = fTemp37 - std::floor(fTemp37);
			float fTemp38 = 24.5f * (ftbl0TdgShimmerSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec34[0]), 65535))] + 1.0f);
			int iTemp39 = static_cast<int>(fTemp38);
			float fTemp40 = std::floor(fTemp38);
			fRec31[0] = fVec11[(faust_wrap_sub(IOTA0, std::min<int>(51, std::max<int>(0, iTemp39)))) & 63] * (fTemp40 + (1.0f - fTemp38)) + (fTemp38 - fTemp40) * fVec11[(faust_wrap_sub(IOTA0, std::min<int>(51, std::max<int>(0, faust_wrap_add(iTemp39, 1))))) & 63];
			float fRec32 = fRec31[1] - fTemp35;
			fVec12[IOTA0 & 8191] = fRec32 + 0.4f * fRec6[0] * fRec29[1];
			fRec29[0] = fVec12[(faust_wrap_sub(IOTA0, iSlow17)) & 8191];
			fRec30[IOTA0 & 131071] = fRec29[1] - fRec32;
			float fTemp41 = fRec21[0] * (fTemp6 * (fTemp26 * fRec30[(faust_wrap_sub(IOTA0, faust_wrap_add(iTemp27, 2969))) & 131071] + fTemp25 * fRec30[(faust_wrap_sub(IOTA0, faust_wrap_add(iTemp23, 2969))) & 131071]) + fTemp7 * (fTemp20 * fRec30[(faust_wrap_sub(IOTA0, faust_wrap_add(iTemp21, 2969))) & 131071] + fTemp19 * fRec30[(faust_wrap_sub(IOTA0, faust_wrap_add(iTemp17, 2969))) & 131071]));
			fVec13[IOTA0 & 2047] = fTemp41 + fTemp2 + 0.7f * fRec6[0] * fRec27[1];
			float fTemp42 = fVec13[(faust_wrap_sub(IOTA0, iSlow18)) & 2047];
			fVec14[IOTA0 & 63] = fTemp42;
			float fTemp43 = ((iTemp3) ? 0.0f : fConst3 + fRec35[1]);
			fRec35[0] = fTemp43 - std::floor(fTemp43);
			float fTemp44 = 24.5f * (ftbl0TdgShimmerSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec35[0]), 65535))] + 1.0f);
			int iTemp45 = static_cast<int>(fTemp44);
			float fTemp46 = std::floor(fTemp44);
			fRec27[0] = fVec14[(faust_wrap_sub(IOTA0, std::min<int>(51, std::max<int>(0, iTemp45)))) & 63] * (fTemp46 + (1.0f - fTemp44)) + (fTemp44 - fTemp46) * fVec14[(faust_wrap_sub(IOTA0, std::min<int>(51, std::max<int>(0, faust_wrap_add(iTemp45, 1))))) & 63];
			float fRec28 = fRec27[1] - (fTemp2 + fTemp41);
			fVec15[IOTA0 & 2047] = fRec28 + 0.75f * fRec6[0] * fRec25[1];
			fRec25[0] = fVec15[(faust_wrap_sub(IOTA0, iSlow19)) & 2047];
			float fRec26 = fRec25[1] - fRec28;
			fRec24[0] = fRec26 * fTemp0 + fRec3[0] * fRec24[2];
			fRec1[0] = fRec24[0];
			fRec36[0] = fSlow20 + fConst2 * fRec36[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp1 * (1.0f - fRec36[0]) + 0.5f * fRec36[0] * (fRec0[0] + fRec1[0]));
			iVec0[1] = iVec0[0];
			fRec3[1] = fRec3[0];
			fRec6[1] = fRec6[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec9[1] = fRec9[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec21[1] = fRec21[0];
			fVec2[1] = fVec2[0];
			fRec22[1] = fRec22[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec23[1] = fRec23[0];
			fRec7[1] = fRec7[0];
			fRec4[1] = fRec4[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fVec9[1] = fVec9[0];
			fRec34[1] = fRec34[0];
			fRec31[1] = fRec31[0];
			fRec29[1] = fRec29[0];
			fRec35[1] = fRec35[0];
			fRec27[1] = fRec27[0];
			fRec25[1] = fRec25[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec1[1] = fRec1[0];
			fRec36[1] = fRec36[0];
		}
	}

};

#endif
