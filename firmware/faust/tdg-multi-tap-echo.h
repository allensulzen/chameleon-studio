/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Multi-Tap Echo"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgMultiTapEcho -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgMultiTapEcho_H__
#define  __TdgMultiTapEcho_H__

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
#define FAUSTCLASS TdgMultiTapEcho
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

static float TdgMultiTapEcho_faustpower2_f(float value) {
	return value * value;
}

class TdgMultiTapEcho : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	int IOTA0;
	float fVec0[262144];
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	float fRec6[2];
	FAUSTFLOAT fHslider4;
	float fConst13;
	FAUSTFLOAT fHslider5;
	float fRec7[2];
	FAUSTFLOAT fHslider6;
	float fRec8[2];
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	float fConst18;
	float fConst19;
	float fRec15[2];
	float fVec1[4096];
	float fRec14[2];
	float fRec17[2];
	float fVec2[4096];
	float fRec16[2];
	float fRec19[2];
	float fVec3[4096];
	float fRec18[2];
	float fRec21[2];
	float fVec4[4096];
	float fRec20[2];
	float fRec23[2];
	float fVec5[4096];
	float fRec22[2];
	float fRec25[2];
	float fVec6[4096];
	float fRec24[2];
	float fRec27[2];
	float fVec7[4096];
	float fRec26[2];
	float fRec29[2];
	float fVec8[4096];
	float fRec28[2];
	float fVec9[1024];
	float fRec12[2];
	float fVec10[512];
	float fRec10[2];
	float fRec9[3];
	float fConst20;
	float fVec11[2];
	float fConst21;
	float fConst22;
	float fRec3[2];
	float fRec2[3];
	float fConst23;
	float fRec1[3];
	float fRec32[2];
	float fRec31[3];
	float fRec30[3];
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fConst30;
	float fConst31;
	float fConst32;
	float fConst33;
	float fConst34;
	float fConst35;
	float fRec35[2];
	float fRec34[3];
	float fConst36;
	float fRec33[3];
	FAUSTFLOAT fHslider7;
	float fRec36[2];
	float fRec39[2];
	float fRec38[3];
	float fRec37[3];
	
 public:
	TdgMultiTapEcho() {
	}
	
	TdgMultiTapEcho(const TdgMultiTapEcho&) = default;
	
	virtual ~TdgMultiTapEcho() = default;
	
	TdgMultiTapEcho& operator=(const TdgMultiTapEcho&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgMultiTapEcho -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Up to 12 evenly spaced echo taps with rising/falling level distribution, into a Schroeder reverb and LF/HF coloration");
		m->declare("family", "time");
		m->declare("filename", "tdg-multi-tap-echo.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/highshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass0_highpass1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/lowshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowshelf:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Multi-Tap Echo");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust rects/ech_01.dsp + rectangles.lib");
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
		fConst3 = std::tan(2764.6016f / fConst0);
		fConst4 = TdgMultiTapEcho_faustpower2_f(fConst3);
		fConst5 = 1.0f / fConst4;
		fConst6 = 2.0f * (1.0f - fConst5);
		fConst7 = 1.0f / fConst3;
		fConst8 = (fConst7 + -0.618034f) / fConst3 + 1.0f;
		fConst9 = 1.0f / ((fConst7 + 0.618034f) / fConst3 + 1.0f);
		fConst10 = (fConst7 + -1.618034f) / fConst3 + 1.0f;
		fConst11 = (fConst7 + 1.618034f) / fConst3 + 1.0f;
		fConst12 = 1.0f / fConst11;
		fConst13 = 0.001f * fConst0;
		fConst14 = std::tan(12566.371f / fConst0);
		fConst15 = 2.0f * (1.0f - 1.0f / TdgMultiTapEcho_faustpower2_f(fConst14));
		fConst16 = 1.0f / fConst14;
		fConst17 = (fConst16 + -1.4142135f) / fConst14 + 1.0f;
		fConst18 = (fConst16 + 1.4142135f) / fConst14 + 1.0f;
		fConst19 = 1.0f / fConst18;
		fConst20 = 0.5f / fConst18;
		fConst21 = 1.0f - fConst7;
		fConst22 = 1.0f / (fConst7 + 1.0f);
		fConst23 = 1.0f / (fConst4 * fConst11);
		fConst24 = std::tan(1382.3008f / fConst0);
		fConst25 = TdgMultiTapEcho_faustpower2_f(fConst24);
		fConst26 = 1.0f / fConst25;
		fConst27 = 2.0f * (1.0f - fConst26);
		fConst28 = 1.0f / fConst24;
		fConst29 = (fConst28 + -0.618034f) / fConst24 + 1.0f;
		fConst30 = 1.0f / ((fConst28 + 0.618034f) / fConst24 + 1.0f);
		fConst31 = (fConst28 + -1.618034f) / fConst24 + 1.0f;
		fConst32 = (fConst28 + 1.618034f) / fConst24 + 1.0f;
		fConst33 = 1.0f / fConst32;
		fConst34 = 1.0f - fConst28;
		fConst35 = 1.0f / (fConst28 + 1.0f);
		fConst36 = 1.0f / (fConst25 * fConst32);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(2e+01f);
		fHslider3 = static_cast<FAUSTFLOAT>(1e+02f);
		fHslider4 = static_cast<FAUSTFLOAT>(4.0f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider6 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider7 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec4[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 262144; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec6[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec7[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec8[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec15[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 4096; l8 = faust_wrap_add(l8, 1)) {
			fVec1[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec14[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec17[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 4096; l11 = faust_wrap_add(l11, 1)) {
			fVec2[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec16[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec19[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 4096; l14 = faust_wrap_add(l14, 1)) {
			fVec3[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec18[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec21[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 4096; l17 = faust_wrap_add(l17, 1)) {
			fVec4[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec20[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec23[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 4096; l20 = faust_wrap_add(l20, 1)) {
			fVec5[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec22[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec25[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 4096; l23 = faust_wrap_add(l23, 1)) {
			fVec6[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec24[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec27[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 4096; l26 = faust_wrap_add(l26, 1)) {
			fVec7[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec26[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec29[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 4096; l29 = faust_wrap_add(l29, 1)) {
			fVec8[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec28[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 1024; l31 = faust_wrap_add(l31, 1)) {
			fVec9[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec12[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 512; l33 = faust_wrap_add(l33, 1)) {
			fVec10[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec10[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 3; l35 = faust_wrap_add(l35, 1)) {
			fRec9[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fVec11[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec3[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 3; l38 = faust_wrap_add(l38, 1)) {
			fRec2[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 3; l39 = faust_wrap_add(l39, 1)) {
			fRec1[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec32[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 3; l41 = faust_wrap_add(l41, 1)) {
			fRec31[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 3; l42 = faust_wrap_add(l42, 1)) {
			fRec30[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec35[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 3; l44 = faust_wrap_add(l44, 1)) {
			fRec34[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 3; l45 = faust_wrap_add(l45, 1)) {
			fRec33[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fRec36[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fRec39[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 3; l48 = faust_wrap_add(l48, 1)) {
			fRec38[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 3; l49 = faust_wrap_add(l49, 1)) {
			fRec37[l49] = 0.0f;
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
	
	virtual TdgMultiTapEcho* clone() {
		return new TdgMultiTapEcho(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Multi-Tap Echo");
		ui_interface->declare(&fHslider4, "0", "");
		ui_interface->addHorizontalSlider("Taps", &fHslider4, FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->declare(&fHslider3, "unit", "ms");
		ui_interface->addHorizontalSlider("Time", &fHslider3, FAUSTFLOAT(1e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "unit", "ms");
		ui_interface->addHorizontalSlider("Step", &fHslider2, FAUSTFLOAT(2e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->addHorizontalSlider("Distribution", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider5, "4", "");
		ui_interface->addHorizontalSlider("Reverb", &fHslider5, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider7, "5", "");
		ui_interface->addHorizontalSlider("LF", &fHslider7, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "6", "");
		ui_interface->addHorizontalSlider("HF", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider6, "7", "");
		ui_interface->addHorizontalSlider("Taps Volume", &fHslider6, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		float fSlow4 = static_cast<float>(fHslider4);
		float fSlow5 = static_cast<float>(11.0f < fSlow4);
		float fSlow6 = static_cast<float>(1e+01f < fSlow4);
		float fSlow7 = static_cast<float>(9.0f < fSlow4);
		float fSlow8 = static_cast<float>(8.0f < fSlow4);
		float fSlow9 = static_cast<float>(7.0f < fSlow4);
		float fSlow10 = static_cast<float>(6.0f < fSlow4);
		float fSlow11 = static_cast<float>(5.0f < fSlow4);
		float fSlow12 = static_cast<float>(4.0f < fSlow4);
		float fSlow13 = static_cast<float>(3.0f < fSlow4);
		float fSlow14 = static_cast<float>(2.0f < fSlow4);
		float fSlow15 = static_cast<float>(1.0f < fSlow4);
		float fSlow16 = static_cast<float>(0.0f < fSlow4);
		float fSlow17 = fConst1 * static_cast<float>(fHslider5);
		float fSlow18 = fConst1 * static_cast<float>(fHslider6);
		float fSlow19 = fConst1 * static_cast<float>(fHslider7);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			fRec4[0] = fSlow1 + fConst2 * fRec4[1];
			float fTemp0 = 1.0f - fRec4[0];
			float fTemp1 = static_cast<float>(input0[i0]);
			fVec0[IOTA0 & 262143] = fTemp1;
			fRec5[0] = fSlow2 + fConst2 * fRec5[1];
			fRec6[0] = fSlow3 + fConst2 * fRec6[1];
			float fTemp2 = 0.001f * fRec6[0];
			float fTemp3 = fConst0 * (fTemp2 + 0.011f * fRec5[0]);
			int iTemp4 = static_cast<int>(fTemp3);
			float fTemp5 = std::floor(fTemp3);
			float fTemp6 = fConst0 * (fTemp2 + 0.01f * fRec5[0]);
			int iTemp7 = static_cast<int>(fTemp6);
			float fTemp8 = std::floor(fTemp6);
			float fTemp9 = fConst0 * (fTemp2 + 0.009f * fRec5[0]);
			int iTemp10 = static_cast<int>(fTemp9);
			float fTemp11 = std::floor(fTemp9);
			float fTemp12 = fConst0 * (fTemp2 + 0.008f * fRec5[0]);
			int iTemp13 = static_cast<int>(fTemp12);
			float fTemp14 = std::floor(fTemp12);
			float fTemp15 = fConst0 * (fTemp2 + 0.007f * fRec5[0]);
			int iTemp16 = static_cast<int>(fTemp15);
			float fTemp17 = std::floor(fTemp15);
			float fTemp18 = fConst0 * (fTemp2 + 0.006f * fRec5[0]);
			int iTemp19 = static_cast<int>(fTemp18);
			float fTemp20 = std::floor(fTemp18);
			float fTemp21 = fConst0 * (fTemp2 + 0.005f * fRec5[0]);
			int iTemp22 = static_cast<int>(fTemp21);
			float fTemp23 = std::floor(fTemp21);
			float fTemp24 = fConst0 * (fTemp2 + 0.004f * fRec5[0]);
			int iTemp25 = static_cast<int>(fTemp24);
			float fTemp26 = std::floor(fTemp24);
			float fTemp27 = fConst0 * (fTemp2 + 0.003f * fRec5[0]);
			int iTemp28 = static_cast<int>(fTemp27);
			float fTemp29 = std::floor(fTemp27);
			float fTemp30 = fConst0 * (fTemp2 + 0.002f * fRec5[0]);
			int iTemp31 = static_cast<int>(fTemp30);
			float fTemp32 = std::floor(fTemp30);
			float fTemp33 = fConst13 * (fRec6[0] + fRec5[0]);
			int iTemp34 = static_cast<int>(fTemp33);
			float fTemp35 = std::floor(fTemp33);
			float fTemp36 = fConst13 * fRec6[0];
			int iTemp37 = static_cast<int>(fTemp36);
			float fTemp38 = std::floor(fTemp36);
			float fTemp39 = fSlow16 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp37)))) & 262143] * (fTemp38 + (1.0f - fTemp36)) + (fTemp36 - fTemp38) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp37, 1))))) & 262143]) * (fTemp0 + 0.4f * fRec4[0]) + fSlow15 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp34)))) & 262143] * (fTemp35 + (1.0f - fTemp33)) + (fTemp33 - fTemp35) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp34, 1))))) & 262143]) * (0.45f * fRec4[0] + 0.9f * fTemp0) + fSlow14 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp31)))) & 262143] * (fTemp32 + (1.0f - fTemp30)) + (fTemp30 - fTemp32) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp31, 1))))) & 262143]) * (0.5f * fRec4[0] + 0.85f * fTemp0) + fSlow13 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp28)))) & 262143] * (fTemp29 + (1.0f - fTemp27)) + (fTemp27 - fTemp29) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp28, 1))))) & 262143]) * (0.55f * fRec4[0] + 0.8f * fTemp0) + fSlow12 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp25)))) & 262143] * (fTemp26 + (1.0f - fTemp24)) + (fTemp24 - fTemp26) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp25, 1))))) & 262143]) * (0.6f * fRec4[0] + 0.75f * fTemp0) + fSlow11 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp22)))) & 262143] * (fTemp23 + (1.0f - fTemp21)) + (fTemp21 - fTemp23) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp22, 1))))) & 262143]) * (0.65f * fRec4[0] + 0.7f * fTemp0) + fSlow10 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp19)))) & 262143] * (fTemp20 + (1.0f - fTemp18)) + (fTemp18 - fTemp20) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp19, 1))))) & 262143]) * (0.7f * fRec4[0] + 0.65f * fTemp0) + fSlow9 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp16)))) & 262143] * (fTemp17 + (1.0f - fTemp15)) + (fTemp15 - fTemp17) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp16, 1))))) & 262143]) * (0.75f * fRec4[0] + 0.6f * fTemp0) + fSlow8 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp13)))) & 262143] * (fTemp14 + (1.0f - fTemp12)) + (fTemp12 - fTemp14) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp13, 1))))) & 262143]) * (0.8f * fRec4[0] + 0.55f * fTemp0) + fSlow7 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp10)))) & 262143] * (fTemp11 + (1.0f - fTemp9)) + (fTemp9 - fTemp11) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp10, 1))))) & 262143]) * (0.85f * fRec4[0] + 0.5f * fTemp0) + fSlow6 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp7)))) & 262143] * (fTemp8 + (1.0f - fTemp6)) + (fTemp6 - fTemp8) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp7, 1))))) & 262143]) * (0.9f * fRec4[0] + 0.45f * fTemp0) + fSlow5 * (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp4)))) & 262143] * (fTemp5 + (1.0f - fTemp3)) + (fTemp3 - fTemp5) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp4, 1))))) & 262143]) * (fRec4[0] + 0.4f * fTemp0);
			fRec7[0] = fSlow17 + fConst2 * fRec7[1];
			fRec8[0] = fSlow18 + fConst2 * fRec8[1];
			fRec15[0] = 0.7f * fRec15[1] + 0.3f * fRec14[1];
			float fTemp40 = fRec8[0] * fTemp39;
			fVec1[IOTA0 & 4095] = fTemp40 + 0.7f * fRec15[0];
			fRec14[0] = fVec1[(faust_wrap_sub(IOTA0, 2617)) & 4095];
			fRec17[0] = 0.7f * fRec17[1] + 0.3f * fRec16[1];
			fVec2[IOTA0 & 4095] = fTemp40 + 0.7f * fRec17[0];
			fRec16[0] = fVec2[(faust_wrap_sub(IOTA0, 2557)) & 4095];
			fRec19[0] = 0.7f * fRec19[1] + 0.3f * fRec18[1];
			fVec3[IOTA0 & 4095] = fTemp40 + 0.7f * fRec19[0];
			fRec18[0] = fVec3[(faust_wrap_sub(IOTA0, 2491)) & 4095];
			fRec21[0] = 0.7f * fRec21[1] + 0.3f * fRec20[1];
			fVec4[IOTA0 & 4095] = fTemp40 + 0.7f * fRec21[0];
			fRec20[0] = fVec4[(faust_wrap_sub(IOTA0, 2422)) & 4095];
			fRec23[0] = 0.7f * fRec23[1] + 0.3f * fRec22[1];
			fVec5[IOTA0 & 4095] = fTemp40 + 0.7f * fRec23[0];
			fRec22[0] = fVec5[(faust_wrap_sub(IOTA0, 2356)) & 4095];
			fRec25[0] = 0.7f * fRec25[1] + 0.3f * fRec24[1];
			fVec6[IOTA0 & 4095] = fTemp40 + 0.7f * fRec25[0];
			fRec24[0] = fVec6[(faust_wrap_sub(IOTA0, 2277)) & 4095];
			fRec27[0] = 0.7f * fRec27[1] + 0.3f * fRec26[1];
			fVec7[IOTA0 & 4095] = fTemp40 + 0.7f * fRec27[0];
			fRec26[0] = fVec7[(faust_wrap_sub(IOTA0, 2188)) & 4095];
			fRec29[0] = 0.7f * fRec29[1] + 0.3f * fRec28[1];
			fVec8[IOTA0 & 4095] = 0.7f * fRec29[0] + fTemp40;
			fRec28[0] = fVec8[(faust_wrap_sub(IOTA0, 2116)) & 4095];
			float fTemp41 = fRec28[0] + fRec26[0] + fRec24[0] + fRec22[0] + fRec20[0] + fRec18[0] + fRec16[0] + fRec14[0];
			fVec9[IOTA0 & 1023] = fTemp41 + 0.25f * fRec12[1];
			fRec12[0] = fVec9[(faust_wrap_sub(IOTA0, 556)) & 1023];
			float fRec13 = fRec12[1] - fTemp41;
			fVec10[IOTA0 & 511] = fRec13 + 0.25f * fRec10[1];
			fRec10[0] = fVec10[(faust_wrap_sub(IOTA0, 441)) & 511];
			float fRec11 = fRec10[1] - fRec13;
			fRec9[0] = fRec11 - fConst19 * (fConst17 * fRec9[2] + fConst15 * fRec9[1]);
			float fTemp42 = fConst20 * fRec7[0] * (fRec9[2] + fRec9[0] + 2.0f * fRec9[1]) + fRec8[0] * (1.0f - fRec7[0]) * fTemp39;
			fVec11[0] = fTemp42;
			float fTemp43 = fTemp42 - fVec11[1];
			fRec3[0] = -(fConst22 * (fConst21 * fRec3[1] - fConst7 * fTemp43));
			fRec2[0] = fRec3[0] - fConst12 * (fConst10 * fRec2[2] + fConst6 * fRec2[1]);
			fRec1[0] = fConst23 * (fRec2[2] + (fRec2[0] - 2.0f * fRec2[1])) - fConst9 * (fConst8 * fRec1[2] + fConst6 * fRec1[1]);
			float fTemp44 = fTemp42 + fVec11[1];
			fRec32[0] = -(fConst22 * (fConst21 * fRec32[1] - fTemp44));
			fRec31[0] = fRec32[0] - fConst12 * (fConst10 * fRec31[2] + fConst6 * fRec31[1]);
			fRec30[0] = fConst12 * (fRec31[2] + fRec31[0] + 2.0f * fRec31[1]) - fConst9 * (fConst8 * fRec30[2] + fConst6 * fRec30[1]);
			fRec35[0] = -(fConst35 * (fConst34 * fRec35[1] - fConst28 * fTemp43));
			fRec34[0] = fRec35[0] - fConst33 * (fConst31 * fRec34[2] + fConst27 * fRec34[1]);
			fRec33[0] = fConst36 * (fRec34[2] + (fRec34[0] - 2.0f * fRec34[1])) - fConst30 * (fConst29 * fRec33[2] + fConst27 * fRec33[1]);
			fRec36[0] = fSlow19 + fConst2 * fRec36[1];
			fRec39[0] = -(fConst35 * (fConst34 * fRec39[1] - fTemp44));
			fRec38[0] = fRec39[0] - fConst33 * (fConst31 * fRec38[2] + fConst27 * fRec38[1]);
			fRec37[0] = fConst33 * (fRec38[2] + fRec38[0] + 2.0f * fRec38[1]) - fConst30 * (fConst29 * fRec37[2] + fConst27 * fRec37[1]);
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp1 + 0.25118864f * (fConst30 * ((fRec37[2] + fRec37[0] + 2.0f * fRec37[1]) * std::pow(1e+01f, 1.2f * (fRec36[0] + -0.5f)) + fConst26 * (fRec33[2] + (fRec33[0] - 2.0f * fRec33[1]))) + fConst9 * (fRec30[2] + fRec30[0] + 2.0f * fRec30[1] + fConst5 * (fRec1[2] + (fRec1[0] - 2.0f * fRec1[1])) * std::pow(1e+01f, 1.2f * (fRec0[0] + -0.5f)))));
			fRec0[1] = fRec0[0];
			fRec4[1] = fRec4[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
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
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fVec11[1] = fVec11[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec32[1] = fRec32[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec35[1] = fRec35[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec36[1] = fRec36[0];
			fRec39[1] = fRec39[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
		}
	}

};

#endif
