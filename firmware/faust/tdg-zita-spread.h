/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Zita Spread"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgZitaSpread -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgZitaSpread_H__
#define  __TdgZitaSpread_H__

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
#define FAUSTCLASS TdgZitaSpread
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

static float TdgZitaSpread_faustpower2_f(float value) {
	return value * value;
}

class TdgZitaSpread : public chdsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider2;
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fRec11[2];
	float fRec10[2];
	int IOTA0;
	float fVec0[32768];
	float fConst7;
	float fVec1[65536];
	FAUSTFLOAT fHslider3;
	float fConst8;
	float fVec2[4096];
	int iConst9;
	float fRec8[2];
	float fConst10;
	float fRec15[2];
	float fRec14[2];
	float fVec3[32768];
	float fConst11;
	float fVec4[2048];
	int iConst12;
	float fRec12[2];
	float fConst13;
	float fRec19[2];
	float fRec18[2];
	float fVec5[32768];
	float fConst14;
	float fVec6[4096];
	int iConst15;
	float fRec16[2];
	float fConst16;
	float fRec23[2];
	float fRec22[2];
	float fVec7[32768];
	float fConst17;
	float fVec8[2048];
	int iConst18;
	float fRec20[2];
	float fConst19;
	float fRec27[2];
	float fRec26[2];
	float fVec9[65536];
	float fConst20;
	float fVec10[4096];
	int iConst21;
	float fRec24[2];
	float fConst22;
	float fRec31[2];
	float fRec30[2];
	float fVec11[65536];
	float fConst23;
	float fVec12[4096];
	int iConst24;
	float fRec28[2];
	float fConst25;
	float fRec35[2];
	float fRec34[2];
	float fVec13[65536];
	float fConst26;
	float fVec14[4096];
	int iConst27;
	float fRec32[2];
	float fConst28;
	float fRec39[2];
	float fRec38[2];
	float fVec15[65536];
	float fConst29;
	float fVec16[2048];
	int iConst30;
	float fRec36[2];
	float fRec0[3];
	float fRec1[3];
	float fRec2[3];
	float fRec3[3];
	float fRec4[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	float fConst31;
	float fConst32;
	FAUSTFLOAT fHslider4;
	float fRec40[2];
	
 public:
	TdgZitaSpread() {
	}
	
	TdgZitaSpread(const TdgZitaSpread&) = default;
	
	virtual ~TdgZitaSpread() = default;
	
	TdgZitaSpread& operator=(const TdgZitaSpread&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgZitaSpread -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Zita-rev1 FDN variant with a Spread control scaling the delay-line lengths (tiny room to huge hall), RT and HF decay");
		m->declare("family", "reverb");
		m->declare("filename", "tdg-zita-spread.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/low_shelf1_l:author", "Julius O. Smith III");
		m->declare("filters.lib/low_shelf1_l:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/low_shelf1_l:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass0_highpass1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Zita Spread");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/hadamard:author", "Remy Muller, revised by Romain Michon");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust rects/rev_01.dsp (zita_rev_fdn by JOS)");
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
		fConst1 = 0.174713f * fConst0;
		fConst2 = 6.9077554f / fConst0;
		fConst3 = 6.2831855f / fConst0;
		fConst4 = 1.0f / std::tan(628.31854f / fConst0);
		fConst5 = 1.0f - fConst4;
		fConst6 = 1.0f / (fConst4 + 1.0f);
		fConst7 = std::floor(0.022904f * fConst0 + 0.5f);
		fConst8 = 0.001f * fConst0;
		iConst9 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst7 + -1.0f)));
		fConst10 = 0.153129f * fConst0;
		fConst11 = std::floor(0.020346f * fConst0 + 0.5f);
		iConst12 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, fConst11 + -1.0f)));
		fConst13 = 0.127837f * fConst0;
		fConst14 = std::floor(0.031604f * fConst0 + 0.5f);
		iConst15 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst14 + -1.0f)));
		fConst16 = 0.125f * fConst0;
		fConst17 = std::floor(0.013458f * fConst0 + 0.5f);
		iConst18 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, fConst17 + -1.0f)));
		fConst19 = 0.210389f * fConst0;
		fConst20 = std::floor(0.024421f * fConst0 + 0.5f);
		iConst21 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst20 + -1.0f)));
		fConst22 = 0.192303f * fConst0;
		fConst23 = std::floor(0.029291f * fConst0 + 0.5f);
		iConst24 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst23 + -1.0f)));
		fConst25 = 0.256891f * fConst0;
		fConst26 = std::floor(0.027333f * fConst0 + 0.5f);
		iConst27 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst26 + -1.0f)));
		fConst28 = 0.219991f * fConst0;
		fConst29 = std::floor(0.019123f * fConst0 + 0.5f);
		iConst30 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, fConst29 + -1.0f)));
		fConst31 = 44.1f / fConst0;
		fConst32 = 1.0f - fConst31;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(3.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider3 = static_cast<FAUSTFLOAT>(2e+01f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.4f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec11[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec10[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 32768; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 65536; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 4096; l4 = faust_wrap_add(l4, 1)) {
			fVec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec8[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec15[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec14[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 32768; l8 = faust_wrap_add(l8, 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2048; l9 = faust_wrap_add(l9, 1)) {
			fVec4[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec12[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec19[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec18[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 32768; l13 = faust_wrap_add(l13, 1)) {
			fVec5[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 4096; l14 = faust_wrap_add(l14, 1)) {
			fVec6[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec16[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec23[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec22[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 32768; l18 = faust_wrap_add(l18, 1)) {
			fVec7[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2048; l19 = faust_wrap_add(l19, 1)) {
			fVec8[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec20[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec27[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec26[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 65536; l23 = faust_wrap_add(l23, 1)) {
			fVec9[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 4096; l24 = faust_wrap_add(l24, 1)) {
			fVec10[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec24[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec31[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec30[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 65536; l28 = faust_wrap_add(l28, 1)) {
			fVec11[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 4096; l29 = faust_wrap_add(l29, 1)) {
			fVec12[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec28[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec35[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec34[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 65536; l33 = faust_wrap_add(l33, 1)) {
			fVec13[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 4096; l34 = faust_wrap_add(l34, 1)) {
			fVec14[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec32[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec39[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec38[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 65536; l38 = faust_wrap_add(l38, 1)) {
			fVec15[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2048; l39 = faust_wrap_add(l39, 1)) {
			fVec16[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec36[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 3; l41 = faust_wrap_add(l41, 1)) {
			fRec0[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 3; l42 = faust_wrap_add(l42, 1)) {
			fRec1[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 3; l43 = faust_wrap_add(l43, 1)) {
			fRec2[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 3; l44 = faust_wrap_add(l44, 1)) {
			fRec3[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 3; l45 = faust_wrap_add(l45, 1)) {
			fRec4[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 3; l46 = faust_wrap_add(l46, 1)) {
			fRec5[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 3; l47 = faust_wrap_add(l47, 1)) {
			fRec6[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 3; l48 = faust_wrap_add(l48, 1)) {
			fRec7[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec40[l49] = 0.0f;
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
	
	virtual TdgZitaSpread* clone() {
		return new TdgZitaSpread(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Zita Spread");
		ui_interface->declare(&fHslider3, "0", "");
		ui_interface->declare(&fHslider3, "unit", "ms");
		ui_interface->addHorizontalSlider("Predelay", &fHslider3, FAUSTFLOAT(2e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(5e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Spread", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.2f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->declare(&fHslider0, "unit", "s");
		ui_interface->addHorizontalSlider("RT", &fHslider0, FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider2, "3", "");
		ui_interface->addHorizontalSlider("HF Decay", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider4, "4", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider4, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = static_cast<float>(fHslider0);
		float fSlow1 = static_cast<float>(fHslider1);
		float fSlow2 = std::floor(fConst1 * fSlow1 + 0.5f);
		float fSlow3 = std::exp(-(fConst2 * (fSlow2 / fSlow0)));
		float fSlow4 = TdgZitaSpread_faustpower2_f(fSlow3);
		float fSlow5 = 1.0f - fSlow4;
		float fSlow6 = std::cos(fConst3 * (8e+03f * static_cast<float>(fHslider2) + 2e+02f));
		float fSlow7 = 1.0f - fSlow6 * fSlow4;
		float fSlow8 = std::sqrt(std::max<float>(0.0f, TdgZitaSpread_faustpower2_f(fSlow7) / TdgZitaSpread_faustpower2_f(fSlow5) + -1.0f));
		float fSlow9 = fSlow7 / fSlow5;
		float fSlow10 = fSlow9 - fSlow8;
		float fSlow11 = fSlow0 + 2.0f;
		float fSlow12 = std::exp(-(fConst2 * (fSlow2 / fSlow11))) / fSlow3 + -1.0f;
		float fSlow13 = fSlow3 * (fSlow8 + (1.0f - fSlow9));
		int iSlow14 = static_cast<int>(std::min<float>(16384.0f, std::max<float>(0.0f, std::max<float>(1.0f, fSlow2 - fConst7))));
		float fSlow15 = fConst8 * static_cast<float>(fHslider3);
		int iSlow16 = static_cast<int>(fSlow15);
		int iSlow17 = std::min<int>(32769, std::max<int>(0, faust_wrap_add(iSlow16, 1)));
		float fSlow18 = std::floor(fSlow15);
		float fSlow19 = fSlow15 - fSlow18;
		int iSlow20 = std::min<int>(32769, std::max<int>(0, iSlow16));
		float fSlow21 = fSlow18 + (1.0f - fSlow15);
		float fSlow22 = std::floor(fConst10 * fSlow1 + 0.5f);
		float fSlow23 = std::exp(-(fConst2 * (fSlow22 / fSlow0)));
		float fSlow24 = TdgZitaSpread_faustpower2_f(fSlow23);
		float fSlow25 = 1.0f - fSlow24;
		float fSlow26 = 1.0f - fSlow24 * fSlow6;
		float fSlow27 = std::sqrt(std::max<float>(0.0f, TdgZitaSpread_faustpower2_f(fSlow26) / TdgZitaSpread_faustpower2_f(fSlow25) + -1.0f));
		float fSlow28 = fSlow26 / fSlow25;
		float fSlow29 = fSlow28 - fSlow27;
		float fSlow30 = std::exp(-(fConst2 * (fSlow22 / fSlow11))) / fSlow23 + -1.0f;
		float fSlow31 = fSlow23 * (fSlow27 + (1.0f - fSlow28));
		int iSlow32 = static_cast<int>(std::min<float>(16384.0f, std::max<float>(0.0f, std::max<float>(1.0f, fSlow22 - fConst11))));
		float fSlow33 = std::floor(fConst13 * fSlow1 + 0.5f);
		float fSlow34 = std::exp(-(fConst2 * (fSlow33 / fSlow0)));
		float fSlow35 = TdgZitaSpread_faustpower2_f(fSlow34);
		float fSlow36 = 1.0f - fSlow35;
		float fSlow37 = 1.0f - fSlow6 * fSlow35;
		float fSlow38 = std::sqrt(std::max<float>(0.0f, TdgZitaSpread_faustpower2_f(fSlow37) / TdgZitaSpread_faustpower2_f(fSlow36) + -1.0f));
		float fSlow39 = fSlow37 / fSlow36;
		float fSlow40 = fSlow39 - fSlow38;
		float fSlow41 = std::exp(-(fConst2 * (fSlow33 / fSlow11))) / fSlow34 + -1.0f;
		float fSlow42 = fSlow34 * (fSlow38 + (1.0f - fSlow39));
		int iSlow43 = static_cast<int>(std::min<float>(16384.0f, std::max<float>(0.0f, std::max<float>(1.0f, fSlow33 - fConst14))));
		float fSlow44 = std::floor(fConst16 * fSlow1 + 0.5f);
		float fSlow45 = std::exp(-(fConst2 * (fSlow44 / fSlow0)));
		float fSlow46 = TdgZitaSpread_faustpower2_f(fSlow45);
		float fSlow47 = 1.0f - fSlow46;
		float fSlow48 = 1.0f - fSlow6 * fSlow46;
		float fSlow49 = std::sqrt(std::max<float>(0.0f, TdgZitaSpread_faustpower2_f(fSlow48) / TdgZitaSpread_faustpower2_f(fSlow47) + -1.0f));
		float fSlow50 = fSlow48 / fSlow47;
		float fSlow51 = fSlow50 - fSlow49;
		float fSlow52 = std::exp(-(fConst2 * (fSlow44 / fSlow11))) / fSlow45 + -1.0f;
		float fSlow53 = fSlow45 * (fSlow49 + (1.0f - fSlow50));
		int iSlow54 = static_cast<int>(std::min<float>(16384.0f, std::max<float>(0.0f, std::max<float>(1.0f, fSlow44 - fConst17))));
		float fSlow55 = std::floor(fConst19 * fSlow1 + 0.5f);
		float fSlow56 = std::exp(-(fConst2 * (fSlow55 / fSlow0)));
		float fSlow57 = TdgZitaSpread_faustpower2_f(fSlow56);
		float fSlow58 = 1.0f - fSlow57;
		float fSlow59 = 1.0f - fSlow6 * fSlow57;
		float fSlow60 = std::sqrt(std::max<float>(0.0f, TdgZitaSpread_faustpower2_f(fSlow59) / TdgZitaSpread_faustpower2_f(fSlow58) + -1.0f));
		float fSlow61 = fSlow59 / fSlow58;
		float fSlow62 = fSlow61 - fSlow60;
		float fSlow63 = std::exp(-(fConst2 * (fSlow55 / fSlow11))) / fSlow56 + -1.0f;
		float fSlow64 = fSlow56 * (fSlow60 + (1.0f - fSlow61));
		int iSlow65 = static_cast<int>(std::min<float>(32768.0f, std::max<float>(0.0f, std::max<float>(1.0f, fSlow55 - fConst20))));
		float fSlow66 = std::floor(fConst22 * fSlow1 + 0.5f);
		float fSlow67 = std::exp(-(fConst2 * (fSlow66 / fSlow0)));
		float fSlow68 = TdgZitaSpread_faustpower2_f(fSlow67);
		float fSlow69 = 1.0f - fSlow68;
		float fSlow70 = 1.0f - fSlow6 * fSlow68;
		float fSlow71 = std::sqrt(std::max<float>(0.0f, TdgZitaSpread_faustpower2_f(fSlow70) / TdgZitaSpread_faustpower2_f(fSlow69) + -1.0f));
		float fSlow72 = fSlow70 / fSlow69;
		float fSlow73 = fSlow72 - fSlow71;
		float fSlow74 = std::exp(-(fConst2 * (fSlow66 / fSlow11))) / fSlow67 + -1.0f;
		float fSlow75 = fSlow67 * (fSlow71 + (1.0f - fSlow72));
		int iSlow76 = static_cast<int>(std::min<float>(32768.0f, std::max<float>(0.0f, std::max<float>(1.0f, fSlow66 - fConst23))));
		float fSlow77 = std::floor(fConst25 * fSlow1 + 0.5f);
		float fSlow78 = std::exp(-(fConst2 * (fSlow77 / fSlow0)));
		float fSlow79 = TdgZitaSpread_faustpower2_f(fSlow78);
		float fSlow80 = 1.0f - fSlow79;
		float fSlow81 = 1.0f - fSlow6 * fSlow79;
		float fSlow82 = std::sqrt(std::max<float>(0.0f, TdgZitaSpread_faustpower2_f(fSlow81) / TdgZitaSpread_faustpower2_f(fSlow80) + -1.0f));
		float fSlow83 = fSlow81 / fSlow80;
		float fSlow84 = fSlow83 - fSlow82;
		float fSlow85 = std::exp(-(fConst2 * (fSlow77 / fSlow11))) / fSlow78 + -1.0f;
		float fSlow86 = fSlow78 * (fSlow82 + (1.0f - fSlow83));
		int iSlow87 = static_cast<int>(std::min<float>(32768.0f, std::max<float>(0.0f, std::max<float>(1.0f, fSlow77 - fConst26))));
		float fSlow88 = std::floor(fConst28 * fSlow1 + 0.5f);
		float fSlow89 = std::exp(-(fConst2 * (fSlow88 / fSlow0)));
		float fSlow90 = TdgZitaSpread_faustpower2_f(fSlow89);
		float fSlow91 = 1.0f - fSlow90;
		float fSlow92 = 1.0f - fSlow6 * fSlow90;
		float fSlow93 = std::sqrt(std::max<float>(0.0f, TdgZitaSpread_faustpower2_f(fSlow92) / TdgZitaSpread_faustpower2_f(fSlow91) + -1.0f));
		float fSlow94 = fSlow92 / fSlow91;
		float fSlow95 = fSlow94 - fSlow93;
		float fSlow96 = std::exp(-(fConst2 * (fSlow88 / fSlow11))) / fSlow89 + -1.0f;
		float fSlow97 = fSlow89 * (fSlow93 + (1.0f - fSlow94));
		int iSlow98 = static_cast<int>(std::min<float>(32768.0f, std::max<float>(0.0f, std::max<float>(1.0f, fSlow88 - fConst29))));
		float fSlow99 = fConst31 * static_cast<float>(fHslider4);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec11[0] = -(fConst6 * (fConst5 * fRec11[1] - (fRec4[1] + fRec4[2])));
			fRec10[0] = fSlow13 * (fRec4[1] + fSlow12 * fRec11[0]) + fSlow10 * fRec10[1];
			fVec0[IOTA0 & 32767] = 0.35355338f * fRec10[0] + 1e-20f;
			float fTemp0 = static_cast<float>(input0[i0]);
			fVec1[IOTA0 & 65535] = fTemp0;
			float fTemp1 = fSlow19 * fVec1[(faust_wrap_sub(IOTA0, iSlow17)) & 65535];
			float fTemp2 = fSlow21 * fVec1[(faust_wrap_sub(IOTA0, iSlow20)) & 65535];
			float fTemp3 = fTemp2 + fTemp1;
			float fTemp4 = fTemp3 + fVec0[(faust_wrap_sub(IOTA0, iSlow14)) & 32767] - 0.6f * fRec8[1];
			fVec2[IOTA0 & 4095] = fTemp4;
			fRec8[0] = fVec2[(faust_wrap_sub(IOTA0, iConst9)) & 4095];
			float fRec9 = 0.6f * fTemp4;
			fRec15[0] = -(fConst6 * (fConst5 * fRec15[1] - (fRec0[1] + fRec0[2])));
			fRec14[0] = fSlow31 * (fRec0[1] + fSlow30 * fRec15[0]) + fSlow29 * fRec14[1];
			fVec3[IOTA0 & 32767] = 0.35355338f * fRec14[0] + 1e-20f;
			float fTemp5 = fTemp1 + fVec3[(faust_wrap_sub(IOTA0, iSlow32)) & 32767] + fTemp2 - 0.6f * fRec12[1];
			fVec4[IOTA0 & 2047] = fTemp5;
			fRec12[0] = fVec4[(faust_wrap_sub(IOTA0, iConst12)) & 2047];
			float fRec13 = 0.6f * fTemp5;
			float fTemp6 = fRec13 + fRec9;
			fRec19[0] = -(fConst6 * (fConst5 * fRec19[1] - (fRec2[1] + fRec2[2])));
			fRec18[0] = fSlow42 * (fRec2[1] + fSlow41 * fRec19[0]) + fSlow40 * fRec18[1];
			fVec5[IOTA0 & 32767] = 0.35355338f * fRec18[0] + 1e-20f;
			float fTemp7 = fTemp3 + fVec5[(faust_wrap_sub(IOTA0, iSlow43)) & 32767] - 0.6f * fRec16[1];
			fVec6[IOTA0 & 4095] = fTemp7;
			fRec16[0] = fVec6[(faust_wrap_sub(IOTA0, iConst15)) & 4095];
			float fRec17 = 0.6f * fTemp7;
			fRec23[0] = -(fConst6 * (fConst5 * fRec23[1] - (fRec6[1] + fRec6[2])));
			fRec22[0] = fSlow53 * (fRec6[1] + fSlow52 * fRec23[0]) + fSlow51 * fRec22[1];
			fVec7[IOTA0 & 32767] = 0.35355338f * fRec22[0] + 1e-20f;
			float fTemp8 = fTemp3 + fVec7[(faust_wrap_sub(IOTA0, iSlow54)) & 32767] - 0.6f * fRec20[1];
			fVec8[IOTA0 & 2047] = fTemp8;
			fRec20[0] = fVec8[(faust_wrap_sub(IOTA0, iConst18)) & 2047];
			float fRec21 = 0.6f * fTemp8;
			float fTemp9 = fRec21 + fRec17 + fTemp6;
			fRec27[0] = -(fConst6 * (fConst5 * fRec27[1] - (fRec1[1] + fRec1[2])));
			fRec26[0] = fSlow64 * (fRec1[1] + fSlow63 * fRec27[0]) + fSlow62 * fRec26[1];
			fVec9[IOTA0 & 65535] = 0.35355338f * fRec26[0] + 1e-20f;
			float fTemp10 = fVec9[(faust_wrap_sub(IOTA0, iSlow65)) & 65535] + fTemp3 + 0.6f * fRec24[1];
			fVec10[IOTA0 & 4095] = fTemp10;
			fRec24[0] = fVec10[(faust_wrap_sub(IOTA0, iConst21)) & 4095];
			float fRec25 = -(0.6f * fTemp10);
			fRec31[0] = -(fConst6 * (fConst5 * fRec31[1] - (fRec5[1] + fRec5[2])));
			fRec30[0] = fSlow75 * (fRec5[1] + fSlow74 * fRec31[0]) + fSlow73 * fRec30[1];
			fVec11[IOTA0 & 65535] = 0.35355338f * fRec30[0] + 1e-20f;
			float fTemp11 = fVec11[(faust_wrap_sub(IOTA0, iSlow76)) & 65535] + fTemp3 + 0.6f * fRec28[1];
			fVec12[IOTA0 & 4095] = fTemp11;
			fRec28[0] = fVec12[(faust_wrap_sub(IOTA0, iConst24)) & 4095];
			float fRec29 = -(0.6f * fTemp11);
			fRec35[0] = -(fConst6 * (fConst5 * fRec35[1] - (fRec3[1] + fRec3[2])));
			fRec34[0] = fSlow86 * (fRec3[1] + fSlow85 * fRec35[0]) + fSlow84 * fRec34[1];
			fVec13[IOTA0 & 65535] = 0.35355338f * fRec34[0] + 1e-20f;
			float fTemp12 = fVec13[(faust_wrap_sub(IOTA0, iSlow87)) & 65535] + fTemp3 + 0.6f * fRec32[1];
			fVec14[IOTA0 & 4095] = fTemp12;
			fRec32[0] = fVec14[(faust_wrap_sub(IOTA0, iConst27)) & 4095];
			float fRec33 = -(0.6f * fTemp12);
			fRec39[0] = -(fConst6 * (fConst5 * fRec39[1] - (fRec7[1] + fRec7[2])));
			fRec38[0] = fSlow97 * (fRec7[1] + fSlow96 * fRec39[0]) + fSlow95 * fRec38[1];
			fVec15[IOTA0 & 65535] = 0.35355338f * fRec38[0] + 1e-20f;
			float fTemp13 = fVec15[(faust_wrap_sub(IOTA0, iSlow98)) & 65535] + fTemp3 + 0.6f * fRec36[1];
			fVec16[IOTA0 & 2047] = fTemp13;
			fRec36[0] = fVec16[(faust_wrap_sub(IOTA0, iConst30)) & 2047];
			float fRec37 = -(0.6f * fTemp13);
			fRec0[0] = fRec36[1] + fRec32[1] + fRec28[1] + fRec24[1] + fRec20[1] + fRec16[1] + fRec8[1] + fRec12[1] + fRec37 + fRec33 + fRec29 + fRec25 + fTemp9;
			fRec1[0] = fRec20[1] + fRec16[1] + fRec8[1] + fRec12[1] + fTemp9 - (fRec36[1] + fRec32[1] + fRec28[1] + fRec24[1] + fRec37 + fRec33 + fRec25 + fRec29);
			float fTemp14 = fRec17 + fRec21;
			fRec2[0] = fRec28[1] + fRec24[1] + fRec8[1] + fRec12[1] + fRec29 + fRec25 + fTemp6 - (fRec36[1] + fRec32[1] + fRec20[1] + fRec16[1] + fRec37 + fRec33 + fTemp14);
			fRec3[0] = fRec36[1] + fRec32[1] + fRec8[1] + fRec12[1] + fRec37 + fRec33 + fTemp6 - (fRec28[1] + fRec24[1] + fRec20[1] + fRec16[1] + fRec29 + fRec25 + fTemp14);
			float fTemp15 = fRec9 + fRec21;
			float fTemp16 = fRec13 + fRec17;
			fRec4[0] = fRec32[1] + fRec24[1] + fRec16[1] + fRec12[1] + fRec33 + fRec25 + fTemp16 - (fRec36[1] + fRec28[1] + fRec20[1] + fRec8[1] + fRec37 + fRec29 + fTemp15);
			fRec5[0] = fRec36[1] + fRec28[1] + fRec16[1] + fRec12[1] + fRec37 + fRec29 + fTemp16 - (fRec32[1] + fRec24[1] + fRec20[1] + fRec8[1] + fRec33 + fRec25 + fTemp15);
			float fTemp17 = fRec9 + fRec17;
			float fTemp18 = fRec13 + fRec21;
			fRec6[0] = fRec36[1] + fRec24[1] + fRec20[1] + fRec12[1] + fRec37 + fRec25 + fTemp18 - (fRec32[1] + fRec28[1] + fRec16[1] + fRec8[1] + fRec33 + fRec29 + fTemp17);
			fRec7[0] = fRec32[1] + fRec28[1] + fRec20[1] + fRec12[1] + fRec33 + fRec29 + fTemp18 - (fRec36[1] + fRec24[1] + fRec16[1] + fRec8[1] + fRec37 + fRec25 + fTemp17);
			fRec40[0] = fSlow99 + fConst32 * fRec40[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec40[0]) + 0.25f * fRec40[0] * (fRec0[0] + fRec1[0] + fRec2[0] + fRec3[0] + fRec4[0] + fRec5[0] + fRec6[0] + fRec7[0]));
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec8[1] = fRec8[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec20[1] = fRec20[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec36[1] = fRec36[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec40[1] = fRec40[0];
		}
	}

};

#endif
