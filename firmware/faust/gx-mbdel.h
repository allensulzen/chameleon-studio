/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "MultiBand Delay"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbdel -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxMbdel_H__
#define  __GxMbdel_H__

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
#define FAUSTCLASS GxMbdel
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

static double GxMbdel_faustpower2_f(double value) {
	return value * value;
}

class GxMbdel : public chdsp {
	
 private:
	
	int fSampleRate;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fHslider0;
	double fConst2;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	double fVec0[2];
	double fRec8[2];
	double fRec7[3];
	double fRec6[3];
	double fRec5[3];
	double fRec4[3];
	FAUSTFLOAT fVslider0;
	double fRec9[2];
	FAUSTFLOAT fVslider1;
	int IOTA0;
	double fVec1[524288];
	FAUSTFLOAT fHslider4;
	double fConst3;
	double fConst4;
	double fRec10[2];
	double fRec11[2];
	double fRec12[2];
	double fRec13[2];
	double fRec3[2];
	double fRec0[2];
	int iRec1[2];
	double fRec2[2];
	FAUSTFLOAT fVbargraph0;
	double fRec23[2];
	double fRec22[3];
	double fVec2[2];
	double fRec21[2];
	double fRec20[3];
	double fRec19[3];
	double fRec18[3];
	FAUSTFLOAT fVslider2;
	double fRec24[2];
	FAUSTFLOAT fVslider3;
	double fVec3[524288];
	FAUSTFLOAT fHslider5;
	double fRec25[2];
	double fRec26[2];
	double fRec27[2];
	double fRec28[2];
	double fRec17[2];
	double fRec14[2];
	int iRec15[2];
	double fRec16[2];
	FAUSTFLOAT fVbargraph1;
	double fRec37[2];
	double fRec36[3];
	double fVec4[2];
	double fRec35[2];
	double fRec34[3];
	double fRec33[3];
	FAUSTFLOAT fVslider4;
	double fRec38[2];
	FAUSTFLOAT fVslider5;
	double fVec5[524288];
	FAUSTFLOAT fHslider6;
	double fRec39[2];
	double fRec40[2];
	double fRec41[2];
	double fRec42[2];
	double fRec32[2];
	double fRec29[2];
	int iRec30[2];
	double fRec31[2];
	FAUSTFLOAT fVbargraph2;
	double fRec50[2];
	double fRec49[3];
	double fVec6[2];
	double fRec48[2];
	double fRec47[3];
	FAUSTFLOAT fVslider6;
	double fRec51[2];
	FAUSTFLOAT fVslider7;
	double fVec7[524288];
	FAUSTFLOAT fHslider7;
	double fRec52[2];
	double fRec53[2];
	double fRec54[2];
	double fRec55[2];
	double fRec46[2];
	double fRec43[2];
	int iRec44[2];
	double fRec45[2];
	FAUSTFLOAT fVbargraph3;
	double fRec61[2];
	double fRec60[3];
	FAUSTFLOAT fVslider8;
	double fRec62[2];
	FAUSTFLOAT fVslider9;
	double fVec8[524288];
	FAUSTFLOAT fHslider8;
	double fRec63[2];
	double fRec64[2];
	double fRec65[2];
	double fRec66[2];
	double fRec59[2];
	double fRec56[2];
	int iRec57[2];
	double fRec58[2];
	FAUSTFLOAT fVbargraph4;
	
 public:
	GxMbdel() {
	}
	
	GxMbdel(const GxMbdel&) = default;
	
	virtual ~GxMbdel() = default;
	
	GxMbdel& operator=(const GxMbdel&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Echo / Delay");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbdel -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Multi Band Delay");
		m->declare("filename", "gx-mbdel.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass_plus_lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass_plus_lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "mbdel");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "MultiBand Delay");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reducemaps.lib/author", "Yann Orlarey");
		m->declare("reducemaps.lib/copyright", "Grame and Yann Orlarey");
		m->declare("reducemaps.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("reducemaps.lib/name", "Reduce Library");
		m->declare("reducemaps.lib/version", "1.2.0");
		m->declare("shortname", "MB Delay");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
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
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 1.0 / fConst0;
		fConst2 = 3.141592653589793 / fConst0;
		fConst3 = 6e+01 * fConst0;
		fConst4 = 1e+01 / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(8e+01);
		fHslider1 = static_cast<FAUSTFLOAT>(2.1e+02);
		fHslider2 = static_cast<FAUSTFLOAT>(1.7e+03);
		fHslider3 = static_cast<FAUSTFLOAT>(5e+03);
		fVslider0 = static_cast<FAUSTFLOAT>(-1e+01);
		fVslider1 = static_cast<FAUSTFLOAT>(5e+01);
		fHslider4 = static_cast<FAUSTFLOAT>(1.5e+02);
		fVslider2 = static_cast<FAUSTFLOAT>(0.0);
		fVslider3 = static_cast<FAUSTFLOAT>(5e+01);
		fHslider5 = static_cast<FAUSTFLOAT>(1.2e+02);
		fVslider4 = static_cast<FAUSTFLOAT>(-2.0);
		fVslider5 = static_cast<FAUSTFLOAT>(5e+01);
		fHslider6 = static_cast<FAUSTFLOAT>(9e+01);
		fVslider6 = static_cast<FAUSTFLOAT>(-5.0);
		fVslider7 = static_cast<FAUSTFLOAT>(5e+01);
		fHslider7 = static_cast<FAUSTFLOAT>(6e+01);
		fVslider8 = static_cast<FAUSTFLOAT>(-1e+01);
		fVslider9 = static_cast<FAUSTFLOAT>(5e+01);
		fHslider8 = static_cast<FAUSTFLOAT>(3e+01);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec8[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec7[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fRec6[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec5[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec9[l6] = 0.0;
		}
		IOTA0 = 0;
		for (int l7 = 0; l7 < 524288; l7 = faust_wrap_add(l7, 1)) {
			fVec1[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec10[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec11[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec12[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec13[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec3[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec0[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			iRec1[l14] = 0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec2[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec23[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 3; l17 = faust_wrap_add(l17, 1)) {
			fRec22[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fVec2[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec21[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 3; l20 = faust_wrap_add(l20, 1)) {
			fRec20[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 3; l21 = faust_wrap_add(l21, 1)) {
			fRec19[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 3; l22 = faust_wrap_add(l22, 1)) {
			fRec18[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec24[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 524288; l24 = faust_wrap_add(l24, 1)) {
			fVec3[l24] = 0.0;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec25[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec26[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec27[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec28[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec17[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec14[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			iRec15[l31] = 0;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec16[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec37[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 3; l34 = faust_wrap_add(l34, 1)) {
			fRec36[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fVec4[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec35[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 3; l37 = faust_wrap_add(l37, 1)) {
			fRec34[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 3; l38 = faust_wrap_add(l38, 1)) {
			fRec33[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec38[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 524288; l40 = faust_wrap_add(l40, 1)) {
			fVec5[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec39[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			fRec40[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec41[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec42[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec32[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fRec29[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			iRec30[l47] = 0;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec31[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec50[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 3; l50 = faust_wrap_add(l50, 1)) {
			fRec49[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fVec6[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec48[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 3; l53 = faust_wrap_add(l53, 1)) {
			fRec47[l53] = 0.0;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fRec51[l54] = 0.0;
		}
		for (int l55 = 0; l55 < 524288; l55 = faust_wrap_add(l55, 1)) {
			fVec7[l55] = 0.0;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fRec52[l56] = 0.0;
		}
		for (int l57 = 0; l57 < 2; l57 = faust_wrap_add(l57, 1)) {
			fRec53[l57] = 0.0;
		}
		for (int l58 = 0; l58 < 2; l58 = faust_wrap_add(l58, 1)) {
			fRec54[l58] = 0.0;
		}
		for (int l59 = 0; l59 < 2; l59 = faust_wrap_add(l59, 1)) {
			fRec55[l59] = 0.0;
		}
		for (int l60 = 0; l60 < 2; l60 = faust_wrap_add(l60, 1)) {
			fRec46[l60] = 0.0;
		}
		for (int l61 = 0; l61 < 2; l61 = faust_wrap_add(l61, 1)) {
			fRec43[l61] = 0.0;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			iRec44[l62] = 0;
		}
		for (int l63 = 0; l63 < 2; l63 = faust_wrap_add(l63, 1)) {
			fRec45[l63] = 0.0;
		}
		for (int l64 = 0; l64 < 2; l64 = faust_wrap_add(l64, 1)) {
			fRec61[l64] = 0.0;
		}
		for (int l65 = 0; l65 < 3; l65 = faust_wrap_add(l65, 1)) {
			fRec60[l65] = 0.0;
		}
		for (int l66 = 0; l66 < 2; l66 = faust_wrap_add(l66, 1)) {
			fRec62[l66] = 0.0;
		}
		for (int l67 = 0; l67 < 524288; l67 = faust_wrap_add(l67, 1)) {
			fVec8[l67] = 0.0;
		}
		for (int l68 = 0; l68 < 2; l68 = faust_wrap_add(l68, 1)) {
			fRec63[l68] = 0.0;
		}
		for (int l69 = 0; l69 < 2; l69 = faust_wrap_add(l69, 1)) {
			fRec64[l69] = 0.0;
		}
		for (int l70 = 0; l70 < 2; l70 = faust_wrap_add(l70, 1)) {
			fRec65[l70] = 0.0;
		}
		for (int l71 = 0; l71 < 2; l71 = faust_wrap_add(l71, 1)) {
			fRec66[l71] = 0.0;
		}
		for (int l72 = 0; l72 < 2; l72 = faust_wrap_add(l72, 1)) {
			fRec59[l72] = 0.0;
		}
		for (int l73 = 0; l73 < 2; l73 = faust_wrap_add(l73, 1)) {
			fRec56[l73] = 0.0;
		}
		for (int l74 = 0; l74 < 2; l74 = faust_wrap_add(l74, 1)) {
			iRec57[l74] = 0;
		}
		for (int l75 = 0; l75 < 2; l75 = faust_wrap_add(l75, 1)) {
			fRec58[l75] = 0.0;
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
	
	virtual GxMbdel* clone() {
		return new GxMbdel(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("MultiBand Delay");
		ui_interface->declare(&fHslider0, "log", "");
		ui_interface->declare(&fHslider0, "name", "Crossover B1-B2 (hz)");
		ui_interface->declare(&fHslider0, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b1_b2", &fHslider0, FAUSTFLOAT(8e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fHslider1, "log", "");
		ui_interface->declare(&fHslider1, "name", "Crossover B2-B3 (hz)");
		ui_interface->declare(&fHslider1, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b2_b3", &fHslider1, FAUSTFLOAT(2.1e+02), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fHslider2, "log", "");
		ui_interface->declare(&fHslider2, "name", "Crossover B3-B4 (hz)");
		ui_interface->declare(&fHslider2, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b3_b4", &fHslider2, FAUSTFLOAT(1.7e+03), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fHslider3, "log", "");
		ui_interface->declare(&fHslider3, "name", "Crossover B4-B5 (hz)");
		ui_interface->declare(&fHslider3, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b4_b5", &fHslider3, FAUSTFLOAT(5e+03), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fHslider8, "tooltip", "Delay in Beats per Minute");
		ui_interface->addHorizontalSlider("delay1", &fHslider8, FAUSTFLOAT(3e+01), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider7, "tooltip", "Delay in Beats per Minute");
		ui_interface->addHorizontalSlider("delay2", &fHslider7, FAUSTFLOAT(6e+01), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider6, "tooltip", "Delay in Beats per Minute");
		ui_interface->addHorizontalSlider("delay3", &fHslider6, FAUSTFLOAT(9e+01), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider5, "tooltip", "Delay in Beats per Minute");
		ui_interface->addHorizontalSlider("delay4", &fHslider5, FAUSTFLOAT(1.2e+02), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider4, "tooltip", "Delay in Beats per Minute");
		ui_interface->addHorizontalSlider("delay5", &fHslider4, FAUSTFLOAT(1.5e+02), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider9, "tooltip", "percentage of the feedback level in the de.delay loop");
		ui_interface->addVerticalSlider("feedback1", &fVslider9, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider7, "tooltip", "percentage of the feedback level in the de.delay loop");
		ui_interface->addVerticalSlider("feedback2", &fVslider7, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider5, "tooltip", "percentage of the feedback level in the de.delay loop");
		ui_interface->addVerticalSlider("feedback3", &fVslider5, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider3, "tooltip", "percentage of the feedback level in the de.delay loop");
		ui_interface->addVerticalSlider("feedback4", &fVslider3, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider1, "tooltip", "percentage of the feedback level in the de.delay loop");
		ui_interface->addVerticalSlider("feedback5", &fVslider1, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("gain1", &fVslider8, FAUSTFLOAT(-1e+01), FAUSTFLOAT(-2e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("gain2", &fVslider6, FAUSTFLOAT(-5.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("gain3", &fVslider4, FAUSTFLOAT(-2.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("gain4", &fVslider2, FAUSTFLOAT(0.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("gain5", &fVslider0, FAUSTFLOAT(-1e+01), FAUSTFLOAT(-2e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVbargraph4, "nomidi", "no");
		ui_interface->addVerticalBargraph("v1", &fVbargraph4, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph3, "nomidi", "no");
		ui_interface->addVerticalBargraph("v2", &fVbargraph3, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph2, "nomidi", "no");
		ui_interface->addVerticalBargraph("v3", &fVbargraph2, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph1, "nomidi", "no");
		ui_interface->addVerticalBargraph("v4", &fVbargraph1, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph0, "nomidi", "no");
		ui_interface->addVerticalBargraph("v5", &fVbargraph0, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = std::tan(fConst2 * static_cast<double>(fHslider0));
		double fSlow1 = GxMbdel_faustpower2_f(fSlow0);
		double fSlow2 = 2.0 * (1.0 - 1.0 / fSlow1);
		double fSlow3 = 1.0 / fSlow0;
		double fSlow4 = 1.0 - fSlow3;
		double fSlow5 = 1.0 - fSlow4 / fSlow0;
		double fSlow6 = fSlow3 + 1.0;
		double fSlow7 = 1.0 / (fSlow6 / fSlow0 + 1.0);
		double fSlow8 = std::tan(fConst2 * static_cast<double>(fHslider1));
		double fSlow9 = GxMbdel_faustpower2_f(fSlow8);
		double fSlow10 = 2.0 * (1.0 - 1.0 / fSlow9);
		double fSlow11 = 1.0 / fSlow8;
		double fSlow12 = 1.0 - fSlow11;
		double fSlow13 = 1.0 - fSlow12 / fSlow8;
		double fSlow14 = fSlow11 + 1.0;
		double fSlow15 = 1.0 / (fSlow14 / fSlow8 + 1.0);
		double fSlow16 = std::tan(fConst2 * static_cast<double>(fHslider2));
		double fSlow17 = GxMbdel_faustpower2_f(fSlow16);
		double fSlow18 = 2.0 * (1.0 - 1.0 / fSlow17);
		double fSlow19 = 1.0 / fSlow16;
		double fSlow20 = 1.0 - fSlow19;
		double fSlow21 = 1.0 - fSlow20 / fSlow16;
		double fSlow22 = fSlow19 + 1.0;
		double fSlow23 = 1.0 / (fSlow22 / fSlow16 + 1.0);
		double fSlow24 = std::tan(fConst2 * static_cast<double>(fHslider3));
		double fSlow25 = GxMbdel_faustpower2_f(fSlow24);
		double fSlow26 = 2.0 * (1.0 - 1.0 / fSlow25);
		double fSlow27 = 1.0 / fSlow24;
		double fSlow28 = (fSlow27 + -1.0000000000000004) / fSlow24 + 1.0;
		double fSlow29 = (fSlow27 + 1.0000000000000004) / fSlow24 + 1.0;
		double fSlow30 = 1.0 / fSlow29;
		double fSlow31 = 1.0 - fSlow27;
		double fSlow32 = 1.0 / (fSlow27 + 1.0);
		double fSlow33 = 1.0 / (fSlow25 * fSlow29);
		double fSlow34 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider0));
		double fSlow35 = 0.01 * static_cast<double>(fVslider1);
		double fSlow36 = fConst3 / static_cast<double>(fHslider4);
		double fSlow37 = (fSlow19 + -1.0000000000000004) / fSlow16 + 1.0;
		double fSlow38 = (fSlow19 + 1.0000000000000004) / fSlow16 + 1.0;
		double fSlow39 = 1.0 / fSlow38;
		double fSlow40 = 1.0 / fSlow22;
		double fSlow41 = 1.0 / (fSlow17 * fSlow38);
		double fSlow42 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider2));
		double fSlow43 = 0.01 * static_cast<double>(fVslider3);
		double fSlow44 = fConst3 / static_cast<double>(fHslider5);
		double fSlow45 = (fSlow11 + -1.0000000000000004) / fSlow8 + 1.0;
		double fSlow46 = (fSlow11 + 1.0000000000000004) / fSlow8 + 1.0;
		double fSlow47 = 1.0 / fSlow46;
		double fSlow48 = 1.0 / fSlow14;
		double fSlow49 = 1.0 / (fSlow9 * fSlow46);
		double fSlow50 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider4));
		double fSlow51 = 0.01 * static_cast<double>(fVslider5);
		double fSlow52 = fConst3 / static_cast<double>(fHslider6);
		double fSlow53 = (fSlow3 + -1.0000000000000004) / fSlow0 + 1.0;
		double fSlow54 = (fSlow3 + 1.0000000000000004) / fSlow0 + 1.0;
		double fSlow55 = 1.0 / fSlow54;
		double fSlow56 = 1.0 / fSlow6;
		double fSlow57 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider6));
		double fSlow58 = 1.0 / (fSlow1 * fSlow54);
		double fSlow59 = 0.01 * static_cast<double>(fVslider7);
		double fSlow60 = fConst3 / static_cast<double>(fHslider7);
		double fSlow61 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider8));
		double fSlow62 = 0.01 * static_cast<double>(fVslider9);
		double fSlow63 = fConst3 / static_cast<double>(fHslider8);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			int iTemp0 = iRec1[1] < 4096;
			double fTemp1 = fSlow2 * fRec4[1];
			double fTemp2 = fSlow10 * fRec5[1];
			double fTemp3 = fSlow18 * fRec6[1];
			double fTemp4 = static_cast<double>(input0[i0]);
			fVec0[0] = fTemp4;
			fRec8[0] = -(fSlow32 * (fSlow31 * fRec8[1] - fSlow27 * (fTemp4 - fVec0[1])));
			fRec7[0] = fRec8[0] - fSlow30 * (fSlow28 * fRec7[2] + fSlow26 * fRec7[1]);
			fRec6[0] = fSlow33 * (fRec7[2] + (fRec7[0] - 2.0 * fRec7[1])) - fSlow23 * (fSlow21 * fRec6[2] + fTemp3);
			fRec5[0] = fRec6[2] + fSlow23 * (fTemp3 + fSlow21 * fRec6[0]) - fSlow15 * (fSlow13 * fRec5[2] + fTemp2);
			fRec4[0] = fRec5[2] + fSlow15 * (fTemp2 + fSlow13 * fRec5[0]) - fSlow7 * (fSlow5 * fRec4[2] + fTemp1);
			fRec9[0] = fSlow34 + 0.999 * fRec9[1];
			double fTemp5 = fSlow35 * fRec3[1] + fRec9[0] * (fRec4[2] + fSlow7 * (fTemp1 + fSlow5 * fRec4[0]));
			fVec1[IOTA0 & 524287] = fTemp5;
			double fTemp6 = ((fRec10[1] != 0.0) ? (((fRec11[1] > 0.0) & (fRec11[1] < 1.0)) ? fRec10[1] : 0.0) : (((fRec11[1] == 0.0) & (fSlow36 != fRec12[1])) ? fConst4 : (((fRec11[1] == 1.0) & (fSlow36 != fRec13[1])) ? -fConst4 : 0.0)));
			fRec10[0] = fTemp6;
			fRec11[0] = std::max<double>(0.0, std::min<double>(1.0, fRec11[1] + fTemp6));
			fRec12[0] = (((fRec11[1] >= 1.0) & (fRec13[1] != fSlow36)) ? fSlow36 : fRec12[1]);
			fRec13[0] = (((fRec11[1] <= 0.0) & (fRec12[1] != fSlow36)) ? fSlow36 : fRec13[1]);
			double fTemp7 = fVec1[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec12[0]))))) & 524287];
			fRec3[0] = fTemp7 + fRec11[0] * (fVec1[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec13[0]))))) & 524287] - fTemp7);
			double fTemp8 = std::max<double>(fConst1, std::fabs(fRec3[0]));
			fRec0[0] = ((iTemp0) ? std::max<double>(fRec0[1], fTemp8) : fTemp8);
			iRec1[0] = ((iTemp0) ? faust_wrap_add(iRec1[1], 1) : 1);
			fRec2[0] = ((iTemp0) ? fRec2[1] : fRec0[1]);
			fVbargraph0 = static_cast<FAUSTFLOAT>(fRec2[0]);
			int iTemp9 = iRec15[1] < 4096;
			double fTemp10 = fSlow2 * fRec18[1];
			double fTemp11 = fSlow10 * fRec19[1];
			fRec23[0] = -(fSlow32 * (fSlow31 * fRec23[1] - (fTemp4 + fVec0[1])));
			fRec22[0] = fRec23[0] - fSlow30 * (fSlow28 * fRec22[2] + fSlow26 * fRec22[1]);
			double fTemp12 = fSlow30 * (fRec22[2] + fRec22[0] + 2.0 * fRec22[1]);
			fVec2[0] = fTemp12;
			fRec21[0] = -(fSlow40 * (fSlow20 * fRec21[1] - fSlow19 * (fTemp12 - fVec2[1])));
			fRec20[0] = fRec21[0] - fSlow39 * (fSlow37 * fRec20[2] + fSlow18 * fRec20[1]);
			fRec19[0] = fSlow41 * (fRec20[2] + (fRec20[0] - 2.0 * fRec20[1])) - fSlow15 * (fSlow13 * fRec19[2] + fTemp11);
			fRec18[0] = fRec19[2] + fSlow15 * (fTemp11 + fSlow13 * fRec19[0]) - fSlow7 * (fSlow5 * fRec18[2] + fTemp10);
			fRec24[0] = fSlow42 + 0.999 * fRec24[1];
			double fTemp13 = fSlow43 * fRec17[1] + fRec24[0] * (fRec18[2] + fSlow7 * (fTemp10 + fSlow5 * fRec18[0]));
			fVec3[IOTA0 & 524287] = fTemp13;
			double fTemp14 = ((fRec25[1] != 0.0) ? (((fRec26[1] > 0.0) & (fRec26[1] < 1.0)) ? fRec25[1] : 0.0) : (((fRec26[1] == 0.0) & (fSlow44 != fRec27[1])) ? fConst4 : (((fRec26[1] == 1.0) & (fSlow44 != fRec28[1])) ? -fConst4 : 0.0)));
			fRec25[0] = fTemp14;
			fRec26[0] = std::max<double>(0.0, std::min<double>(1.0, fRec26[1] + fTemp14));
			fRec27[0] = (((fRec26[1] >= 1.0) & (fRec28[1] != fSlow44)) ? fSlow44 : fRec27[1]);
			fRec28[0] = (((fRec26[1] <= 0.0) & (fRec27[1] != fSlow44)) ? fSlow44 : fRec28[1]);
			double fTemp15 = fVec3[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec27[0]))))) & 524287];
			fRec17[0] = fTemp15 + fRec26[0] * (fVec3[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec28[0]))))) & 524287] - fTemp15);
			double fTemp16 = std::max<double>(fConst1, std::fabs(fRec17[0]));
			fRec14[0] = ((iTemp9) ? std::max<double>(fRec14[1], fTemp16) : fTemp16);
			iRec15[0] = ((iTemp9) ? faust_wrap_add(iRec15[1], 1) : 1);
			fRec16[0] = ((iTemp9) ? fRec16[1] : fRec14[1]);
			fVbargraph1 = static_cast<FAUSTFLOAT>(fRec16[0]);
			int iTemp17 = iRec30[1] < 4096;
			double fTemp18 = fSlow2 * fRec33[1];
			fRec37[0] = -(fSlow40 * (fSlow20 * fRec37[1] - (fTemp12 + fVec2[1])));
			fRec36[0] = fRec37[0] - fSlow39 * (fSlow37 * fRec36[2] + fSlow18 * fRec36[1]);
			double fTemp19 = fSlow39 * (fRec36[2] + fRec36[0] + 2.0 * fRec36[1]);
			fVec4[0] = fTemp19;
			fRec35[0] = -(fSlow48 * (fSlow12 * fRec35[1] - fSlow11 * (fTemp19 - fVec4[1])));
			fRec34[0] = fRec35[0] - fSlow47 * (fSlow45 * fRec34[2] + fSlow10 * fRec34[1]);
			fRec33[0] = fSlow49 * (fRec34[2] + (fRec34[0] - 2.0 * fRec34[1])) - fSlow7 * (fSlow5 * fRec33[2] + fTemp18);
			fRec38[0] = fSlow50 + 0.999 * fRec38[1];
			double fTemp20 = fSlow51 * fRec32[1] + fRec38[0] * (fRec33[2] + fSlow7 * (fTemp18 + fSlow5 * fRec33[0]));
			fVec5[IOTA0 & 524287] = fTemp20;
			double fTemp21 = ((fRec39[1] != 0.0) ? (((fRec40[1] > 0.0) & (fRec40[1] < 1.0)) ? fRec39[1] : 0.0) : (((fRec40[1] == 0.0) & (fSlow52 != fRec41[1])) ? fConst4 : (((fRec40[1] == 1.0) & (fSlow52 != fRec42[1])) ? -fConst4 : 0.0)));
			fRec39[0] = fTemp21;
			fRec40[0] = std::max<double>(0.0, std::min<double>(1.0, fRec40[1] + fTemp21));
			fRec41[0] = (((fRec40[1] >= 1.0) & (fRec42[1] != fSlow52)) ? fSlow52 : fRec41[1]);
			fRec42[0] = (((fRec40[1] <= 0.0) & (fRec41[1] != fSlow52)) ? fSlow52 : fRec42[1]);
			double fTemp22 = fVec5[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec41[0]))))) & 524287];
			fRec32[0] = fTemp22 + fRec40[0] * (fVec5[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec42[0]))))) & 524287] - fTemp22);
			double fTemp23 = std::max<double>(fConst1, std::fabs(fRec32[0]));
			fRec29[0] = ((iTemp17) ? std::max<double>(fRec29[1], fTemp23) : fTemp23);
			iRec30[0] = ((iTemp17) ? faust_wrap_add(iRec30[1], 1) : 1);
			fRec31[0] = ((iTemp17) ? fRec31[1] : fRec29[1]);
			fVbargraph2 = static_cast<FAUSTFLOAT>(fRec31[0]);
			int iTemp24 = iRec44[1] < 4096;
			fRec50[0] = -(fSlow48 * (fSlow12 * fRec50[1] - (fTemp19 + fVec4[1])));
			fRec49[0] = fRec50[0] - fSlow47 * (fSlow45 * fRec49[2] + fSlow10 * fRec49[1]);
			double fTemp25 = fSlow47 * (fRec49[2] + fRec49[0] + 2.0 * fRec49[1]);
			fVec6[0] = fTemp25;
			fRec48[0] = -(fSlow56 * (fSlow4 * fRec48[1] - fSlow3 * (fTemp25 - fVec6[1])));
			fRec47[0] = fRec48[0] - fSlow55 * (fSlow53 * fRec47[2] + fSlow2 * fRec47[1]);
			fRec51[0] = fSlow57 + 0.999 * fRec51[1];
			double fTemp26 = fSlow59 * fRec46[1] + fSlow58 * fRec51[0] * (fRec47[2] + (fRec47[0] - 2.0 * fRec47[1]));
			fVec7[IOTA0 & 524287] = fTemp26;
			double fTemp27 = ((fRec52[1] != 0.0) ? (((fRec53[1] > 0.0) & (fRec53[1] < 1.0)) ? fRec52[1] : 0.0) : (((fRec53[1] == 0.0) & (fSlow60 != fRec54[1])) ? fConst4 : (((fRec53[1] == 1.0) & (fSlow60 != fRec55[1])) ? -fConst4 : 0.0)));
			fRec52[0] = fTemp27;
			fRec53[0] = std::max<double>(0.0, std::min<double>(1.0, fRec53[1] + fTemp27));
			fRec54[0] = (((fRec53[1] >= 1.0) & (fRec55[1] != fSlow60)) ? fSlow60 : fRec54[1]);
			fRec55[0] = (((fRec53[1] <= 0.0) & (fRec54[1] != fSlow60)) ? fSlow60 : fRec55[1]);
			double fTemp28 = fVec7[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec54[0]))))) & 524287];
			fRec46[0] = fTemp28 + fRec53[0] * (fVec7[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec55[0]))))) & 524287] - fTemp28);
			double fTemp29 = std::max<double>(fConst1, std::fabs(fRec46[0]));
			fRec43[0] = ((iTemp24) ? std::max<double>(fRec43[1], fTemp29) : fTemp29);
			iRec44[0] = ((iTemp24) ? faust_wrap_add(iRec44[1], 1) : 1);
			fRec45[0] = ((iTemp24) ? fRec45[1] : fRec43[1]);
			fVbargraph3 = static_cast<FAUSTFLOAT>(fRec45[0]);
			int iTemp30 = iRec57[1] < 4096;
			fRec61[0] = -(fSlow56 * (fSlow4 * fRec61[1] - (fTemp25 + fVec6[1])));
			fRec60[0] = fRec61[0] - fSlow55 * (fSlow53 * fRec60[2] + fSlow2 * fRec60[1]);
			fRec62[0] = fSlow61 + 0.999 * fRec62[1];
			double fTemp31 = fSlow62 * fRec59[1] + fSlow55 * fRec62[0] * (fRec60[2] + fRec60[0] + 2.0 * fRec60[1]);
			fVec8[IOTA0 & 524287] = fTemp31;
			double fTemp32 = ((fRec63[1] != 0.0) ? (((fRec64[1] > 0.0) & (fRec64[1] < 1.0)) ? fRec63[1] : 0.0) : (((fRec64[1] == 0.0) & (fSlow63 != fRec65[1])) ? fConst4 : (((fRec64[1] == 1.0) & (fSlow63 != fRec66[1])) ? -fConst4 : 0.0)));
			fRec63[0] = fTemp32;
			fRec64[0] = std::max<double>(0.0, std::min<double>(1.0, fRec64[1] + fTemp32));
			fRec65[0] = (((fRec64[1] >= 1.0) & (fRec66[1] != fSlow63)) ? fSlow63 : fRec65[1]);
			fRec66[0] = (((fRec64[1] <= 0.0) & (fRec65[1] != fSlow63)) ? fSlow63 : fRec66[1]);
			double fTemp33 = fVec8[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec65[0]))))) & 524287];
			fRec59[0] = fTemp33 + fRec64[0] * (fVec8[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec66[0]))))) & 524287] - fTemp33);
			double fTemp34 = std::max<double>(fConst1, std::fabs(fRec59[0]));
			fRec56[0] = ((iTemp30) ? std::max<double>(fRec56[1], fTemp34) : fTemp34);
			iRec57[0] = ((iTemp30) ? faust_wrap_add(iRec57[1], 1) : 1);
			fRec58[0] = ((iTemp30) ? fRec58[1] : fRec56[1]);
			fVbargraph4 = static_cast<FAUSTFLOAT>(fRec58[0]);
			output0[i0] = static_cast<FAUSTFLOAT>(fRec59[0] + fRec46[0] + fRec32[0] + fRec17[0] + fTemp4 + fRec3[0]);
			fVec0[1] = fVec0[0];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec9[1] = fRec9[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec3[1] = fRec3[0];
			fRec0[1] = fRec0[0];
			iRec1[1] = iRec1[0];
			fRec2[1] = fRec2[0];
			fRec23[1] = fRec23[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fVec2[1] = fVec2[0];
			fRec21[1] = fRec21[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec26[1] = fRec26[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec17[1] = fRec17[0];
			fRec14[1] = fRec14[0];
			iRec15[1] = iRec15[0];
			fRec16[1] = fRec16[0];
			fRec37[1] = fRec37[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fVec4[1] = fVec4[0];
			fRec35[1] = fRec35[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec42[1] = fRec42[0];
			fRec32[1] = fRec32[0];
			fRec29[1] = fRec29[0];
			iRec30[1] = iRec30[0];
			fRec31[1] = fRec31[0];
			fRec50[1] = fRec50[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fVec6[1] = fVec6[0];
			fRec48[1] = fRec48[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec51[1] = fRec51[0];
			fRec52[1] = fRec52[0];
			fRec53[1] = fRec53[0];
			fRec54[1] = fRec54[0];
			fRec55[1] = fRec55[0];
			fRec46[1] = fRec46[0];
			fRec43[1] = fRec43[0];
			iRec44[1] = iRec44[0];
			fRec45[1] = fRec45[0];
			fRec61[1] = fRec61[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec62[1] = fRec62[0];
			fRec63[1] = fRec63[0];
			fRec64[1] = fRec64[0];
			fRec65[1] = fRec65[0];
			fRec66[1] = fRec66[0];
			fRec59[1] = fRec59[0];
			fRec56[1] = fRec56[0];
			iRec57[1] = iRec57[0];
			fRec58[1] = fRec58[0];
		}
	}

};

#endif
