/* ------------------------------------------------------------
author: "Bart Brouns (port of a Pure Data patch by Scott Nordlund, 2011)"
license: "GPL-3.0"
name: "Constant Detune Chorus"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn MagConstantDetuneChorus -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __MagConstantDetuneChorus_H__
#define  __MagConstantDetuneChorus_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
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
#define FAUSTCLASS MagConstantDetuneChorus
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

static float MagConstantDetuneChorus_faustpower2_f(float value) {
	return value * value;
}

class MagConstantDetuneChorus : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec2[2];
	float fVec1[2];
	float fConst3;
	float fRec1[2];
	int IOTA0;
	float fVec2[8192];
	FAUSTFLOAT fHslider1;
	float fRec10[2];
	float fConst4;
	float fConst5;
	int iRec14[2];
	float fRec16[2];
	int iRec15[2];
	int iRec17[2];
	float fRec13[2];
	float fRec12[3];
	float fVec3[2];
	float fConst6;
	float fRec11[2];
	float fVec4[2];
	float fRec8[2];
	float fRec9[2];
	float fConst7;
	float fRec7[2];
	FAUSTFLOAT fHslider2;
	float fRec26[2];
	float fVec5[2];
	float fRec24[2];
	float fRec25[2];
	FAUSTFLOAT fHslider3;
	float fRec30[2];
	float fRec35[2];
	int iRec34[2];
	float fRec33[2];
	float fRec32[3];
	float fVec6[2];
	float fRec31[2];
	float fVec7[2];
	float fRec28[2];
	float fRec29[2];
	float fRec27[2];
	FAUSTFLOAT fHslider4;
	float fRec38[2];
	float fVec8[2];
	float fRec36[2];
	float fRec37[2];
	float fConst8;
	float fRec3[2];
	float fRec4[2];
	float fRec5[2];
	float fRec6[2];
	float fRec50[2];
	int iRec49[2];
	float fRec48[2];
	float fRec47[3];
	float fVec9[2];
	float fRec46[2];
	float fVec10[2];
	float fRec44[2];
	float fRec45[2];
	float fRec43[2];
	float fVec11[2];
	float fRec51[2];
	float fRec52[2];
	float fRec60[2];
	int iRec59[2];
	float fRec58[2];
	float fRec57[3];
	float fVec12[2];
	float fRec56[2];
	float fVec13[2];
	float fRec54[2];
	float fRec55[2];
	float fRec53[2];
	float fVec14[2];
	float fRec61[2];
	float fRec62[2];
	float fRec39[2];
	float fRec40[2];
	float fRec41[2];
	float fRec42[2];
	float fRec74[2];
	int iRec73[2];
	float fRec72[2];
	float fRec71[3];
	float fVec15[2];
	float fRec70[2];
	float fVec16[2];
	float fRec68[2];
	float fRec69[2];
	float fRec67[2];
	float fVec17[2];
	float fRec75[2];
	float fRec76[2];
	float fRec84[2];
	int iRec83[2];
	float fRec82[2];
	float fRec81[3];
	float fVec18[2];
	float fRec80[2];
	float fVec19[2];
	float fRec78[2];
	float fRec79[2];
	float fRec77[2];
	float fVec20[2];
	float fRec85[2];
	float fRec86[2];
	float fRec63[2];
	float fRec64[2];
	float fRec65[2];
	float fRec66[2];
	float fRec0[2];
	float fConst9;
	float fConst10;
	FAUSTFLOAT fHslider5;
	float fRec87[2];
	
 public:
	MagConstantDetuneChorus() {
	}
	
	MagConstantDetuneChorus(const MagConstantDetuneChorus&) = default;
	
	virtual ~MagConstantDetuneChorus() = default;
	
	MagConstantDetuneChorus& operator=(const MagConstantDetuneChorus&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Bart Brouns (port of a Pure Data patch by Scott Nordlund, 2011)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn MagConstantDetuneChorus -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Bart Brouns' port of Scott Nordlund's chorus: three delay taps with Poisson-timed random slow+fast LFOs whose warped triangles keep detune constant and symmetric in cents");
		m->declare("family", "mod");
		m->declare("filename", "mag-constant-detune-chorus.dsp");
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
		m->declare("license", "GPL-3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Constant Detune Chorus");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.6.0");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "LicenseRef-STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "magnetophon/constant-detune-chorus ConstantDetuneChorus.dsp");
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
		fConst1 = 628.31854f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.0f / (fConst1 + 1.0f);
		fConst4 = 4.444f * fConst0;
		fConst5 = 0.667f * fConst0;
		fConst6 = 1e+03f / fConst0;
		fConst7 = 1.0f / fConst0;
		fConst8 = 0.001f * fConst0;
		fConst9 = 44.1f / fConst0;
		fConst10 = 1.0f - fConst9;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(4.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.57f);
		fHslider4 = static_cast<FAUSTFLOAT>(4.0f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.6f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec1[l3] = 0.0f;
		}
		IOTA0 = 0;
		for (int l4 = 0; l4 < 8192; l4 = faust_wrap_add(l4, 1)) {
			fVec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec10[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			iRec14[l6] = 0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec16[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			iRec15[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			iRec17[l9] = 0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec13[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 3; l11 = faust_wrap_add(l11, 1)) {
			fRec12[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fVec3[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec11[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fVec4[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec8[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec9[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec7[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec26[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fVec5[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec24[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec25[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec30[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec35[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			iRec34[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec33[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 3; l26 = faust_wrap_add(l26, 1)) {
			fRec32[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fVec6[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec31[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fVec7[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec28[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec29[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec27[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec38[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fVec8[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec36[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec37[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec3[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fRec4[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec5[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec6[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec50[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			iRec49[l42] = 0;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec48[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 3; l44 = faust_wrap_add(l44, 1)) {
			fRec47[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fVec9[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fRec46[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fVec10[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec44[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec45[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec43[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fVec11[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec51[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fRec52[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fRec60[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			iRec59[l55] = 0;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fRec58[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 3; l57 = faust_wrap_add(l57, 1)) {
			fRec57[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = faust_wrap_add(l58, 1)) {
			fVec12[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = faust_wrap_add(l59, 1)) {
			fRec56[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = faust_wrap_add(l60, 1)) {
			fVec13[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = faust_wrap_add(l61, 1)) {
			fRec54[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			fRec55[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = faust_wrap_add(l63, 1)) {
			fRec53[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 2; l64 = faust_wrap_add(l64, 1)) {
			fVec14[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 2; l65 = faust_wrap_add(l65, 1)) {
			fRec61[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = faust_wrap_add(l66, 1)) {
			fRec62[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 2; l67 = faust_wrap_add(l67, 1)) {
			fRec39[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 2; l68 = faust_wrap_add(l68, 1)) {
			fRec40[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 2; l69 = faust_wrap_add(l69, 1)) {
			fRec41[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2; l70 = faust_wrap_add(l70, 1)) {
			fRec42[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = faust_wrap_add(l71, 1)) {
			fRec74[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = faust_wrap_add(l72, 1)) {
			iRec73[l72] = 0;
		}
		for (int l73 = 0; l73 < 2; l73 = faust_wrap_add(l73, 1)) {
			fRec72[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 3; l74 = faust_wrap_add(l74, 1)) {
			fRec71[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 2; l75 = faust_wrap_add(l75, 1)) {
			fVec15[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 2; l76 = faust_wrap_add(l76, 1)) {
			fRec70[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 2; l77 = faust_wrap_add(l77, 1)) {
			fVec16[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 2; l78 = faust_wrap_add(l78, 1)) {
			fRec68[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 2; l79 = faust_wrap_add(l79, 1)) {
			fRec69[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 2; l80 = faust_wrap_add(l80, 1)) {
			fRec67[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 2; l81 = faust_wrap_add(l81, 1)) {
			fVec17[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 2; l82 = faust_wrap_add(l82, 1)) {
			fRec75[l82] = 0.0f;
		}
		for (int l83 = 0; l83 < 2; l83 = faust_wrap_add(l83, 1)) {
			fRec76[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 2; l84 = faust_wrap_add(l84, 1)) {
			fRec84[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 2; l85 = faust_wrap_add(l85, 1)) {
			iRec83[l85] = 0;
		}
		for (int l86 = 0; l86 < 2; l86 = faust_wrap_add(l86, 1)) {
			fRec82[l86] = 0.0f;
		}
		for (int l87 = 0; l87 < 3; l87 = faust_wrap_add(l87, 1)) {
			fRec81[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 2; l88 = faust_wrap_add(l88, 1)) {
			fVec18[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 2; l89 = faust_wrap_add(l89, 1)) {
			fRec80[l89] = 0.0f;
		}
		for (int l90 = 0; l90 < 2; l90 = faust_wrap_add(l90, 1)) {
			fVec19[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 2; l91 = faust_wrap_add(l91, 1)) {
			fRec78[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 2; l92 = faust_wrap_add(l92, 1)) {
			fRec79[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 2; l93 = faust_wrap_add(l93, 1)) {
			fRec77[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 2; l94 = faust_wrap_add(l94, 1)) {
			fVec20[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 2; l95 = faust_wrap_add(l95, 1)) {
			fRec85[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 2; l96 = faust_wrap_add(l96, 1)) {
			fRec86[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 2; l97 = faust_wrap_add(l97, 1)) {
			fRec63[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 2; l98 = faust_wrap_add(l98, 1)) {
			fRec64[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 2; l99 = faust_wrap_add(l99, 1)) {
			fRec65[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 2; l100 = faust_wrap_add(l100, 1)) {
			fRec66[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 2; l101 = faust_wrap_add(l101, 1)) {
			fRec0[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 2; l102 = faust_wrap_add(l102, 1)) {
			fRec87[l102] = 0.0f;
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
	
	virtual MagConstantDetuneChorus* clone() {
		return new MagConstantDetuneChorus(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Constant Detune Chorus");
		ui_interface->declare(&fHslider3, "0", "");
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("Slow Rate", &fHslider3, FAUSTFLOAT(0.57f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider4, "1", "");
		ui_interface->addHorizontalSlider("Slow Depth", &fHslider4, FAUSTFLOAT(4.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Fast Rate", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "3", "");
		ui_interface->addHorizontalSlider("Fast Depth", &fHslider2, FAUSTFLOAT(4.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "4", "");
		ui_interface->addHorizontalSlider("Feedback", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider5, "5", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider5, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = 0.0008f * static_cast<float>(fHslider0);
		float fSlow1 = 0.001f * static_cast<float>(fHslider1);
		float fSlow2 = 0.001f * MagConstantDetuneChorus_faustpower2_f(static_cast<float>(fHslider2));
		float fSlow3 = 0.001f * static_cast<float>(fHslider3);
		float fSlow4 = 0.001f * MagConstantDetuneChorus_faustpower2_f(static_cast<float>(fHslider4));
		float fSlow5 = fConst9 * static_cast<float>(fHslider5);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec2[0] = fSlow0 + 0.999f * fRec2[1];
			float fTemp0 = fRec2[0] * fRec0[1];
			fVec1[0] = fTemp0;
			fRec1[0] = fConst3 * (fTemp0 - fVec1[1] + fConst2 * fRec1[1]);
			float fTemp1 = static_cast<float>(input0[i0]);
			float fTemp2 = fTemp1 + 0.25f * tanhf(2.0f * fRec1[0]);
			fVec2[IOTA0 & 8191] = fTemp2;
			int iTemp3 = faust_wrap_sub(1, iVec0[1]);
			fRec10[0] = fSlow1 + 0.999f * fRec10[1];
			float fTemp4 = std::log(fRec10[0]);
			float fTemp5 = std::log(1.75f * fRec10[0]) - fTemp4;
			iRec14[0] = faust_wrap_add(iRec14[1], 1);
			int iTemp6 = iRec14[1] < 1;
			float fTemp7 = std::min<float>(fConst4, std::max<float>(fConst5, fRec12[1]));
			fRec16[0] = ((((std::fabs(fRec12[1] - fRec12[2]) > 0.0f) * iRec15[1]) > 0) ? 0.0f : std::min<float>(fTemp7, fRec16[1] + 1.0f));
			iRec15[0] = fRec16[0] == fTemp7;
			int iTemp8 = (std::abs(faust_wrap_sub(iRec15[0], iRec15[1])) > 0) | iTemp6;
			int iTemp9 = faust_wrap_mul(1103515245, faust_wrap_add(iRec17[1], 12345));
			int iTemp10 = faust_wrap_mul(1103515245, faust_wrap_add(iTemp9, 12345));
			int iTemp11 = faust_wrap_mul(1103515245, faust_wrap_add(iTemp10, 12345));
			int iTemp12 = faust_wrap_mul(1103515245, faust_wrap_add(iTemp11, 12345));
			int iTemp13 = faust_wrap_mul(1103515245, faust_wrap_add(iTemp12, 12345));
			int iTemp14 = faust_wrap_mul(1103515245, faust_wrap_add(iTemp13, 12345));
			int iTemp15 = faust_wrap_mul(1103515245, faust_wrap_add(iTemp14, 12345));
			int iTemp16 = faust_wrap_mul(1103515245, faust_wrap_add(iTemp15, 12345));
			int iTemp17 = faust_wrap_mul(1103515245, faust_wrap_add(iTemp16, 12345));
			int iTemp18 = faust_wrap_mul(1103515245, faust_wrap_add(iTemp17, 12345));
			int iTemp19 = faust_wrap_mul(1103515245, faust_wrap_add(iTemp18, 12345));
			int iTemp20 = faust_wrap_mul(1103515245, faust_wrap_add(iTemp19, 12345));
			iRec17[0] = faust_wrap_mul(1103515245, faust_wrap_add(iTemp20, 12345));
			int iRec18 = iTemp20;
			int iRec19 = iTemp19;
			int iRec20 = iTemp18;
			int iRec21 = iTemp17;
			int iRec22 = iTemp16;
			int iRec23 = iTemp15;
			fRec13[0] = fRec13[1] * static_cast<float>(faust_wrap_sub(1, iTemp8)) + (2.3283064e-10f * static_cast<float>(iRec23) + 0.5f) * static_cast<float>(iTemp8);
			fRec12[0] = -(fConst0 * std::log(fRec13[0]));
			float fTemp21 = std::min<float>(fConst4, std::max<float>(fConst5, fRec12[0]));
			fVec3[0] = fTemp21;
			int iTemp22 = std::fabs(fConst6 * (fTemp21 - fVec3[1])) > 0.0f;
			float fTemp23 = 2.3283064e-10f * static_cast<float>(iRec22) + 0.5f;
			fRec11[0] = fRec11[1] * static_cast<float>(faust_wrap_sub(1, iTemp22)) + fTemp23 * static_cast<float>(iTemp22);
			float fTemp24 = std::exp(fTemp4 + fRec11[0] * fTemp5);
			fVec4[0] = fTemp24;
			float fTemp25 = ((fTemp24 != fVec4[1]) ? fTemp21 : fRec8[1] + -1.0f);
			fRec8[0] = fTemp25;
			fRec9[0] = ((fTemp25 <= 0.0f) ? fTemp24 : fRec9[1] + (fTemp24 - fRec9[1]) / fTemp25);
			float fTemp26 = ((iTemp3) ? 0.0f : fRec7[1] + fConst7 * fRec9[0]);
			fRec7[0] = fTemp26 - std::floor(fTemp26);
			fRec26[0] = fSlow2 + 0.999f * fRec26[1];
			float fTemp27 = std::pow(2.0f, 0.00083333335f * fRec26[0]);
			float fTemp28 = fTemp27 + 1.0f;
			float fTemp29 = fTemp27 + -1.0f;
			float fTemp30 = fTemp29 / (fTemp28 * fTemp24);
			fVec5[0] = fTemp30;
			float fTemp31 = 318.30988f * fTemp30;
			float fTemp32 = ((fTemp31 != (318.30988f * fVec5[1])) ? fTemp21 : fRec24[1] + -1.0f);
			fRec24[0] = fTemp32;
			fRec25[0] = ((fTemp32 <= 0.0f) ? fTemp31 : fRec25[1] + (fTemp31 - fRec25[1]) / fTemp32);
			fRec30[0] = fSlow3 + 0.999f * fRec30[1];
			float fTemp33 = std::log(fRec30[0]);
			float fTemp34 = std::log(1.25f * fRec30[0]) - fTemp33;
			float fTemp35 = std::min<float>(fConst4, std::max<float>(fConst5, fRec32[1]));
			fRec35[0] = ((((std::fabs(fRec32[1] - fRec32[2]) > 0.0f) * iRec34[1]) > 0) ? 0.0f : std::min<float>(fTemp35, fRec35[1] + 1.0f));
			iRec34[0] = fRec35[0] == fTemp35;
			int iTemp36 = (std::abs(faust_wrap_sub(iRec34[0], iRec34[1])) > 0) | iTemp6;
			fRec33[0] = fRec33[1] * static_cast<float>(faust_wrap_sub(1, iTemp36)) + fTemp23 * static_cast<float>(iTemp36);
			fRec32[0] = -(fConst0 * std::log(fRec33[0]));
			float fTemp37 = std::min<float>(fConst4, std::max<float>(fConst5, fRec32[0]));
			fVec6[0] = fTemp37;
			int iTemp38 = std::fabs(fConst6 * (fTemp37 - fVec6[1])) > 0.0f;
			float fTemp39 = 2.3283064e-10f * static_cast<float>(iRec21) + 0.5f;
			fRec31[0] = fRec31[1] * static_cast<float>(faust_wrap_sub(1, iTemp38)) + fTemp39 * static_cast<float>(iTemp38);
			float fTemp40 = std::exp(fTemp33 + fRec31[0] * fTemp34);
			fVec7[0] = fTemp40;
			float fTemp41 = ((fTemp40 != fVec7[1]) ? fTemp37 : fRec28[1] + -1.0f);
			fRec28[0] = fTemp41;
			fRec29[0] = ((fTemp41 <= 0.0f) ? fTemp40 : fRec29[1] + (fTemp40 - fRec29[1]) / fTemp41);
			float fTemp42 = ((iTemp3) ? 0.0f : fRec27[1] + fConst7 * fRec29[0]);
			fRec27[0] = fTemp42 - std::floor(fTemp42);
			fRec38[0] = fSlow4 + 0.999f * fRec38[1];
			float fTemp43 = std::pow(2.0f, 0.00083333335f * fRec38[0]);
			float fTemp44 = fTemp43 + 1.0f;
			float fTemp45 = fTemp43 + -1.0f;
			float fTemp46 = fTemp45 / (fTemp44 * std::exp(fTemp4 + fRec31[0] * fTemp5));
			fVec8[0] = fTemp46;
			float fTemp47 = 2e+03f * fTemp46;
			float fTemp48 = ((fTemp47 != (2e+03f * fVec8[1])) ? fTemp37 : fRec36[1] + -1.0f);
			fRec36[0] = fTemp48;
			fRec37[0] = ((fTemp48 <= 0.0f) ? fTemp47 : fRec37[1] + (fTemp47 - fRec37[1]) / fTemp48);
			float fTemp49 = fConst8 * (fRec37[0] * std::fabs(fRec27[0] + -0.5f) + fRec25[0] * (std::sin(fRec7[0]) + 1.0f) + 1e+01f);
			float fTemp50 = ((fRec3[1] != 0.0f) ? (((fRec4[1] > 0.0f) & (fRec4[1] < 1.0f)) ? fRec3[1] : 0.0f) : (((fRec4[1] == 0.0f) & (fTemp49 != fRec5[1])) ? 0.0009765625f : (((fRec4[1] == 1.0f) & (fTemp49 != fRec6[1])) ? -0.0009765625f : 0.0f)));
			fRec3[0] = fTemp50;
			fRec4[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec4[1] + fTemp50));
			fRec5[0] = (((fRec4[1] >= 1.0f) & (fRec6[1] != fTemp49)) ? fTemp49 : fRec5[1]);
			fRec6[0] = (((fRec4[1] <= 0.0f) & (fRec5[1] != fTemp49)) ? fTemp49 : fRec6[1]);
			float fTemp51 = fVec2[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(4096.0f, std::max<float>(0.0f, fRec5[0]))))) & 8191];
			float fTemp52 = std::min<float>(fConst4, std::max<float>(fConst5, fRec47[1]));
			fRec50[0] = ((((std::fabs(fRec47[1] - fRec47[2]) > 0.0f) * iRec49[1]) > 0) ? 0.0f : std::min<float>(fTemp52, fRec50[1] + 1.0f));
			iRec49[0] = fRec50[0] == fTemp52;
			int iTemp53 = (std::abs(faust_wrap_sub(iRec49[0], iRec49[1])) > 0) | iTemp6;
			fRec48[0] = fRec48[1] * static_cast<float>(faust_wrap_sub(1, iTemp53)) + fTemp39 * static_cast<float>(iTemp53);
			fRec47[0] = -(fConst0 * std::log(fRec48[0]));
			float fTemp54 = std::min<float>(fConst4, std::max<float>(fConst5, fRec47[0]));
			fVec9[0] = fTemp54;
			int iTemp55 = std::fabs(fConst6 * (fTemp54 - fVec9[1])) > 0.0f;
			float fTemp56 = 2.3283064e-10f * static_cast<float>(iRec20) + 0.5f;
			fRec46[0] = fRec46[1] * static_cast<float>(faust_wrap_sub(1, iTemp55)) + fTemp56 * static_cast<float>(iTemp55);
			float fTemp57 = std::exp(fTemp4 + fRec46[0] * fTemp5);
			fVec10[0] = fTemp57;
			float fTemp58 = ((fTemp57 != fVec10[1]) ? fTemp54 : fRec44[1] + -1.0f);
			fRec44[0] = fTemp58;
			fRec45[0] = ((fTemp58 <= 0.0f) ? fTemp57 : fRec45[1] + (fTemp57 - fRec45[1]) / fTemp58);
			float fTemp59 = ((iTemp3) ? 0.0f : fRec43[1] + fConst7 * fRec45[0]);
			fRec43[0] = fTemp59 - std::floor(fTemp59);
			float fTemp60 = fTemp29 / (fTemp28 * fTemp57);
			fVec11[0] = fTemp60;
			float fTemp61 = 318.30988f * fTemp60;
			float fTemp62 = ((fTemp61 != (318.30988f * fVec11[1])) ? fTemp54 : fRec51[1] + -1.0f);
			fRec51[0] = fTemp62;
			fRec52[0] = ((fTemp62 <= 0.0f) ? fTemp61 : fRec52[1] + (fTemp61 - fRec52[1]) / fTemp62);
			float fTemp63 = std::min<float>(fConst4, std::max<float>(fConst5, fRec57[1]));
			fRec60[0] = ((((std::fabs(fRec57[1] - fRec57[2]) > 0.0f) * iRec59[1]) > 0) ? 0.0f : std::min<float>(fTemp63, fRec60[1] + 1.0f));
			iRec59[0] = fRec60[0] == fTemp63;
			int iTemp64 = (std::abs(faust_wrap_sub(iRec59[0], iRec59[1])) > 0) | iTemp6;
			fRec58[0] = fRec58[1] * static_cast<float>(faust_wrap_sub(1, iTemp64)) + fTemp56 * static_cast<float>(iTemp64);
			fRec57[0] = -(fConst0 * std::log(fRec58[0]));
			float fTemp65 = std::min<float>(fConst4, std::max<float>(fConst5, fRec57[0]));
			fVec12[0] = fTemp65;
			int iTemp66 = std::fabs(fConst6 * (fTemp65 - fVec12[1])) > 0.0f;
			float fTemp67 = 2.3283064e-10f * static_cast<float>(iRec19) + 0.5f;
			fRec56[0] = fRec56[1] * static_cast<float>(faust_wrap_sub(1, iTemp66)) + fTemp67 * static_cast<float>(iTemp66);
			float fTemp68 = std::exp(fTemp33 + fRec56[0] * fTemp34);
			fVec13[0] = fTemp68;
			float fTemp69 = ((fTemp68 != fVec13[1]) ? fTemp65 : fRec54[1] + -1.0f);
			fRec54[0] = fTemp69;
			fRec55[0] = ((fTemp69 <= 0.0f) ? fTemp68 : fRec55[1] + (fTemp68 - fRec55[1]) / fTemp69);
			float fTemp70 = ((iTemp3) ? 0.0f : fRec53[1] + fConst7 * fRec55[0]);
			fRec53[0] = fTemp70 - std::floor(fTemp70);
			float fTemp71 = fTemp45 / (fTemp44 * std::exp(fTemp4 + fRec56[0] * fTemp5));
			fVec14[0] = fTemp71;
			float fTemp72 = 2e+03f * fTemp71;
			float fTemp73 = ((fTemp72 != (2e+03f * fVec14[1])) ? fTemp65 : fRec61[1] + -1.0f);
			fRec61[0] = fTemp73;
			fRec62[0] = ((fTemp73 <= 0.0f) ? fTemp72 : fRec62[1] + (fTemp72 - fRec62[1]) / fTemp73);
			float fTemp74 = fConst8 * (fRec62[0] * std::fabs(fRec53[0] + -0.5f) + fRec52[0] * (std::sin(fRec43[0]) + 1.0f) + 7.0f);
			float fTemp75 = ((fRec39[1] != 0.0f) ? (((fRec40[1] > 0.0f) & (fRec40[1] < 1.0f)) ? fRec39[1] : 0.0f) : (((fRec40[1] == 0.0f) & (fTemp74 != fRec41[1])) ? 0.0009765625f : (((fRec40[1] == 1.0f) & (fTemp74 != fRec42[1])) ? -0.0009765625f : 0.0f)));
			fRec39[0] = fTemp75;
			fRec40[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec40[1] + fTemp75));
			fRec41[0] = (((fRec40[1] >= 1.0f) & (fRec42[1] != fTemp74)) ? fTemp74 : fRec41[1]);
			fRec42[0] = (((fRec40[1] <= 0.0f) & (fRec41[1] != fTemp74)) ? fTemp74 : fRec42[1]);
			float fTemp76 = fVec2[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(4096.0f, std::max<float>(0.0f, fRec41[0]))))) & 8191];
			float fTemp77 = std::min<float>(fConst4, std::max<float>(fConst5, fRec71[1]));
			fRec74[0] = ((((std::fabs(fRec71[1] - fRec71[2]) > 0.0f) * iRec73[1]) > 0) ? 0.0f : std::min<float>(fTemp77, fRec74[1] + 1.0f));
			iRec73[0] = fRec74[0] == fTemp77;
			int iTemp78 = (std::abs(faust_wrap_sub(iRec73[0], iRec73[1])) > 0) | iTemp6;
			fRec72[0] = fRec72[1] * static_cast<float>(faust_wrap_sub(1, iTemp78)) + fTemp67 * static_cast<float>(iTemp78);
			fRec71[0] = -(fConst0 * std::log(fRec72[0]));
			float fTemp79 = std::min<float>(fConst4, std::max<float>(fConst5, fRec71[0]));
			fVec15[0] = fTemp79;
			int iTemp80 = std::fabs(fConst6 * (fTemp79 - fVec15[1])) > 0.0f;
			float fTemp81 = 2.3283064e-10f * static_cast<float>(iRec18) + 0.5f;
			fRec70[0] = fRec70[1] * static_cast<float>(faust_wrap_sub(1, iTemp80)) + fTemp81 * static_cast<float>(iTemp80);
			float fTemp82 = std::exp(fTemp4 + fRec70[0] * fTemp5);
			fVec16[0] = fTemp82;
			float fTemp83 = ((fTemp82 != fVec16[1]) ? fTemp79 : fRec68[1] + -1.0f);
			fRec68[0] = fTemp83;
			fRec69[0] = ((fTemp83 <= 0.0f) ? fTemp82 : fRec69[1] + (fTemp82 - fRec69[1]) / fTemp83);
			float fTemp84 = ((iTemp3) ? 0.0f : fRec67[1] + fConst7 * fRec69[0]);
			fRec67[0] = fTemp84 - std::floor(fTemp84);
			float fTemp85 = fTemp29 / (fTemp82 * fTemp28);
			fVec17[0] = fTemp85;
			float fTemp86 = 318.30988f * fTemp85;
			float fTemp87 = ((fTemp86 != (318.30988f * fVec17[1])) ? fTemp79 : fRec75[1] + -1.0f);
			fRec75[0] = fTemp87;
			fRec76[0] = ((fTemp87 <= 0.0f) ? fTemp86 : fRec76[1] + (fTemp86 - fRec76[1]) / fTemp87);
			float fTemp88 = std::min<float>(fConst4, std::max<float>(fConst5, fRec81[1]));
			fRec84[0] = ((((std::fabs(fRec81[1] - fRec81[2]) > 0.0f) * iRec83[1]) > 0) ? 0.0f : std::min<float>(fTemp88, fRec84[1] + 1.0f));
			iRec83[0] = fRec84[0] == fTemp88;
			int iTemp89 = (std::abs(faust_wrap_sub(iRec83[0], iRec83[1])) > 0) | iTemp6;
			fRec82[0] = fRec82[1] * static_cast<float>(faust_wrap_sub(1, iTemp89)) + fTemp81 * static_cast<float>(iTemp89);
			fRec81[0] = -(fConst0 * std::log(fRec82[0]));
			float fTemp90 = std::min<float>(fConst4, std::max<float>(fConst5, fRec81[0]));
			fVec18[0] = fTemp90;
			int iTemp91 = std::fabs(fConst6 * (fTemp90 - fVec18[1])) > 0.0f;
			fRec80[0] = fRec80[1] * static_cast<float>(faust_wrap_sub(1, iTemp91)) + (2.3283064e-10f * static_cast<float>(iRec17[0]) + 0.5f) * static_cast<float>(iTemp91);
			float fTemp92 = std::exp(fTemp33 + fRec80[0] * fTemp34);
			fVec19[0] = fTemp92;
			float fTemp93 = ((fTemp92 != fVec19[1]) ? fTemp90 : fRec78[1] + -1.0f);
			fRec78[0] = fTemp93;
			fRec79[0] = ((fTemp93 <= 0.0f) ? fTemp92 : fRec79[1] + (fTemp92 - fRec79[1]) / fTemp93);
			float fTemp94 = ((iTemp3) ? 0.0f : fRec77[1] + fConst7 * fRec79[0]);
			fRec77[0] = fTemp94 - std::floor(fTemp94);
			float fTemp95 = fTemp45 / (fTemp44 * std::exp(fTemp4 + fRec80[0] * fTemp5));
			fVec20[0] = fTemp95;
			float fTemp96 = 2e+03f * fTemp95;
			float fTemp97 = ((fTemp96 != (2e+03f * fVec20[1])) ? fTemp90 : fRec85[1] + -1.0f);
			fRec85[0] = fTemp97;
			fRec86[0] = ((fTemp97 <= 0.0f) ? fTemp96 : fRec86[1] + (fTemp96 - fRec86[1]) / fTemp97);
			float fTemp98 = fConst8 * (fRec86[0] * std::fabs(fRec77[0] + -0.5f) + fRec76[0] * (std::sin(fRec67[0]) + 1.0f) + 3.0f);
			float fTemp99 = ((fRec63[1] != 0.0f) ? (((fRec64[1] > 0.0f) & (fRec64[1] < 1.0f)) ? fRec63[1] : 0.0f) : (((fRec64[1] == 0.0f) & (fTemp98 != fRec65[1])) ? 0.0009765625f : (((fRec64[1] == 1.0f) & (fTemp98 != fRec66[1])) ? -0.0009765625f : 0.0f)));
			fRec63[0] = fTemp99;
			fRec64[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec64[1] + fTemp99));
			fRec65[0] = (((fRec64[1] >= 1.0f) & (fRec66[1] != fTemp98)) ? fTemp98 : fRec65[1]);
			fRec66[0] = (((fRec64[1] <= 0.0f) & (fRec65[1] != fTemp98)) ? fTemp98 : fRec66[1]);
			float fTemp100 = fVec2[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(4096.0f, std::max<float>(0.0f, fRec65[0]))))) & 8191];
			fRec0[0] = fRec4[0] * (fVec2[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(4096.0f, std::max<float>(0.0f, fRec6[0]))))) & 8191] - fTemp51) + fRec40[0] * (fVec2[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(4096.0f, std::max<float>(0.0f, fRec42[0]))))) & 8191] - fTemp76) + fTemp100 + fRec64[0] * (fVec2[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(4096.0f, std::max<float>(0.0f, fRec66[0]))))) & 8191] - fTemp100) + fTemp76 + fTemp51;
			fRec87[0] = fSlow5 + fConst10 * fRec87[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp1 * (1.0f - fRec87[0]) + 0.5f * fRec87[0] * fRec0[0]);
			iVec0[1] = iVec0[0];
			fRec2[1] = fRec2[0];
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec10[1] = fRec10[0];
			iRec14[1] = iRec14[0];
			fRec16[1] = fRec16[0];
			iRec15[1] = iRec15[0];
			iRec17[1] = iRec17[0];
			fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fVec3[1] = fVec3[0];
			fRec11[1] = fRec11[0];
			fVec4[1] = fVec4[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fRec26[1] = fRec26[0];
			fVec5[1] = fVec5[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec30[1] = fRec30[0];
			fRec35[1] = fRec35[0];
			iRec34[1] = iRec34[0];
			fRec33[1] = fRec33[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fVec6[1] = fVec6[0];
			fRec31[1] = fRec31[0];
			fVec7[1] = fVec7[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec38[1] = fRec38[0];
			fVec8[1] = fVec8[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec50[1] = fRec50[0];
			iRec49[1] = iRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fVec9[1] = fVec9[0];
			fRec46[1] = fRec46[0];
			fVec10[1] = fVec10[0];
			fRec44[1] = fRec44[0];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fVec11[1] = fVec11[0];
			fRec51[1] = fRec51[0];
			fRec52[1] = fRec52[0];
			fRec60[1] = fRec60[0];
			iRec59[1] = iRec59[0];
			fRec58[1] = fRec58[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fVec12[1] = fVec12[0];
			fRec56[1] = fRec56[0];
			fVec13[1] = fVec13[0];
			fRec54[1] = fRec54[0];
			fRec55[1] = fRec55[0];
			fRec53[1] = fRec53[0];
			fVec14[1] = fVec14[0];
			fRec61[1] = fRec61[0];
			fRec62[1] = fRec62[0];
			fRec39[1] = fRec39[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec42[1] = fRec42[0];
			fRec74[1] = fRec74[0];
			iRec73[1] = iRec73[0];
			fRec72[1] = fRec72[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fVec15[1] = fVec15[0];
			fRec70[1] = fRec70[0];
			fVec16[1] = fVec16[0];
			fRec68[1] = fRec68[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fVec17[1] = fVec17[0];
			fRec75[1] = fRec75[0];
			fRec76[1] = fRec76[0];
			fRec84[1] = fRec84[0];
			iRec83[1] = iRec83[0];
			fRec82[1] = fRec82[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			fVec18[1] = fVec18[0];
			fRec80[1] = fRec80[0];
			fVec19[1] = fVec19[0];
			fRec78[1] = fRec78[0];
			fRec79[1] = fRec79[0];
			fRec77[1] = fRec77[0];
			fVec20[1] = fVec20[0];
			fRec85[1] = fRec85[0];
			fRec86[1] = fRec86[0];
			fRec63[1] = fRec63[0];
			fRec64[1] = fRec64[0];
			fRec65[1] = fRec65[0];
			fRec66[1] = fRec66[0];
			fRec0[1] = fRec0[0];
			fRec87[1] = fRec87[0];
		}
	}

};

#endif
