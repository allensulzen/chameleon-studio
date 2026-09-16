/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "MultiBand Echo"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbe -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxMbe_H__
#define  __GxMbe_H__

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
#define FAUSTCLASS GxMbe
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

static double GxMbe_faustpower2_f(double value) {
	return value * value;
}

class GxMbe : public chdsp {
	
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
	double fRec11[2];
	double fRec10[3];
	double fVec1[2];
	double fRec9[2];
	double fRec8[3];
	double fVec2[2];
	double fRec7[2];
	double fRec6[3];
	double fVec3[2];
	double fRec5[2];
	double fRec4[3];
	int IOTA0;
	FAUSTFLOAT fHslider4;
	double fConst3;
	double fConst4;
	double fRec12[2];
	double fRec13[2];
	double fRec14[2];
	double fRec15[2];
	FAUSTFLOAT fHslider5;
	double fRec16[2];
	double fRec3[524288];
	double fRec0[2];
	int iRec1[2];
	double fRec2[2];
	FAUSTFLOAT fVbargraph0;
	double fRec22[2];
	double fRec21[3];
	FAUSTFLOAT fHslider6;
	double fRec23[2];
	double fRec24[2];
	double fRec25[2];
	double fRec26[2];
	FAUSTFLOAT fHslider7;
	double fRec27[2];
	double fRec20[524288];
	double fRec17[2];
	int iRec18[2];
	double fRec19[2];
	FAUSTFLOAT fVbargraph1;
	double fRec34[2];
	double fRec33[3];
	double fRec32[3];
	FAUSTFLOAT fHslider8;
	double fRec35[2];
	double fRec36[2];
	double fRec37[2];
	double fRec38[2];
	FAUSTFLOAT fHslider9;
	double fRec39[2];
	double fRec31[524288];
	double fRec28[2];
	int iRec29[2];
	double fRec30[2];
	FAUSTFLOAT fVbargraph2;
	double fRec47[2];
	double fRec46[3];
	double fRec45[3];
	double fRec44[3];
	FAUSTFLOAT fHslider10;
	double fRec48[2];
	double fRec49[2];
	double fRec50[2];
	double fRec51[2];
	FAUSTFLOAT fHslider11;
	double fRec52[2];
	double fRec43[524288];
	double fRec40[2];
	int iRec41[2];
	double fRec42[2];
	FAUSTFLOAT fVbargraph3;
	double fRec61[2];
	double fRec60[3];
	double fRec59[3];
	double fRec58[3];
	double fRec57[3];
	FAUSTFLOAT fHslider12;
	double fRec62[2];
	double fRec63[2];
	double fRec64[2];
	double fRec65[2];
	FAUSTFLOAT fHslider13;
	double fRec66[2];
	double fRec56[524288];
	double fRec53[2];
	int iRec54[2];
	double fRec55[2];
	FAUSTFLOAT fVbargraph4;
	
 public:
	GxMbe() {
	}
	
	GxMbe(const GxMbe&) = default;
	
	virtual ~GxMbe() = default;
	
	GxMbe& operator=(const GxMbe&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Echo / Delay");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbe -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Multi Band Echo");
		m->declare("filename", "gx-mbe.dsp");
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
		m->declare("id", "mbe");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "MultiBand Echo");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reducemaps.lib/author", "Yann Orlarey");
		m->declare("reducemaps.lib/copyright", "Grame and Yann Orlarey");
		m->declare("reducemaps.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("reducemaps.lib/name", "Reduce Library");
		m->declare("reducemaps.lib/version", "1.2.0");
		m->declare("shortname", "MB Echo");
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
		fHslider4 = static_cast<FAUSTFLOAT>(3e+01);
		fHslider5 = static_cast<FAUSTFLOAT>(1e+01);
		fHslider6 = static_cast<FAUSTFLOAT>(6e+01);
		fHslider7 = static_cast<FAUSTFLOAT>(3e+01);
		fHslider8 = static_cast<FAUSTFLOAT>(1.2e+02);
		fHslider9 = static_cast<FAUSTFLOAT>(45.0);
		fHslider10 = static_cast<FAUSTFLOAT>(1.5e+02);
		fHslider11 = static_cast<FAUSTFLOAT>(2e+01);
		fHslider12 = static_cast<FAUSTFLOAT>(2.4e+02);
		fHslider13 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec11[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec10[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec9[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec8[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec2[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec7[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec6[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fVec3[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec5[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 3; l11 = faust_wrap_add(l11, 1)) {
			fRec4[l11] = 0.0;
		}
		IOTA0 = 0;
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec12[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec13[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec14[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec15[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec16[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 524288; l17 = faust_wrap_add(l17, 1)) {
			fRec3[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec0[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			iRec1[l19] = 0;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec2[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec22[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 3; l22 = faust_wrap_add(l22, 1)) {
			fRec21[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec23[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec24[l24] = 0.0;
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
		for (int l28 = 0; l28 < 524288; l28 = faust_wrap_add(l28, 1)) {
			fRec20[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec17[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			iRec18[l30] = 0;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec19[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec34[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 3; l33 = faust_wrap_add(l33, 1)) {
			fRec33[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 3; l34 = faust_wrap_add(l34, 1)) {
			fRec32[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec35[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec36[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec37[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fRec38[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec39[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 524288; l40 = faust_wrap_add(l40, 1)) {
			fRec31[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec28[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			iRec29[l42] = 0;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec30[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec47[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 3; l45 = faust_wrap_add(l45, 1)) {
			fRec46[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 3; l46 = faust_wrap_add(l46, 1)) {
			fRec45[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 3; l47 = faust_wrap_add(l47, 1)) {
			fRec44[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec48[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec49[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec50[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fRec51[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec52[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 524288; l53 = faust_wrap_add(l53, 1)) {
			fRec43[l53] = 0.0;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fRec40[l54] = 0.0;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			iRec41[l55] = 0;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fRec42[l56] = 0.0;
		}
		for (int l57 = 0; l57 < 2; l57 = faust_wrap_add(l57, 1)) {
			fRec61[l57] = 0.0;
		}
		for (int l58 = 0; l58 < 3; l58 = faust_wrap_add(l58, 1)) {
			fRec60[l58] = 0.0;
		}
		for (int l59 = 0; l59 < 3; l59 = faust_wrap_add(l59, 1)) {
			fRec59[l59] = 0.0;
		}
		for (int l60 = 0; l60 < 3; l60 = faust_wrap_add(l60, 1)) {
			fRec58[l60] = 0.0;
		}
		for (int l61 = 0; l61 < 3; l61 = faust_wrap_add(l61, 1)) {
			fRec57[l61] = 0.0;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			fRec62[l62] = 0.0;
		}
		for (int l63 = 0; l63 < 2; l63 = faust_wrap_add(l63, 1)) {
			fRec63[l63] = 0.0;
		}
		for (int l64 = 0; l64 < 2; l64 = faust_wrap_add(l64, 1)) {
			fRec64[l64] = 0.0;
		}
		for (int l65 = 0; l65 < 2; l65 = faust_wrap_add(l65, 1)) {
			fRec65[l65] = 0.0;
		}
		for (int l66 = 0; l66 < 2; l66 = faust_wrap_add(l66, 1)) {
			fRec66[l66] = 0.0;
		}
		for (int l67 = 0; l67 < 524288; l67 = faust_wrap_add(l67, 1)) {
			fRec56[l67] = 0.0;
		}
		for (int l68 = 0; l68 < 2; l68 = faust_wrap_add(l68, 1)) {
			fRec53[l68] = 0.0;
		}
		for (int l69 = 0; l69 < 2; l69 = faust_wrap_add(l69, 1)) {
			iRec54[l69] = 0;
		}
		for (int l70 = 0; l70 < 2; l70 = faust_wrap_add(l70, 1)) {
			fRec55[l70] = 0.0;
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
	
	virtual GxMbe* clone() {
		return new GxMbe(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("MultiBand Echo");
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
		ui_interface->addHorizontalSlider("percent1", &fHslider5, FAUSTFLOAT(1e+01), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->addHorizontalSlider("percent2", &fHslider7, FAUSTFLOAT(3e+01), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->addHorizontalSlider("percent3", &fHslider9, FAUSTFLOAT(45.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->addHorizontalSlider("percent4", &fHslider11, FAUSTFLOAT(2e+01), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->addHorizontalSlider("percent5", &fHslider13, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider4, "tooltip", "Echo in Beats per Minute");
		ui_interface->addHorizontalSlider("time1", &fHslider4, FAUSTFLOAT(3e+01), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider6, "tooltip", "Echo in Beats per Minute");
		ui_interface->addHorizontalSlider("time2", &fHslider6, FAUSTFLOAT(6e+01), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider8, "tooltip", "Echo in Beats per Minute");
		ui_interface->addHorizontalSlider("time3", &fHslider8, FAUSTFLOAT(1.2e+02), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider10, "tooltip", "Echo in Beats per Minute");
		ui_interface->addHorizontalSlider("time4", &fHslider10, FAUSTFLOAT(1.5e+02), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider12, "tooltip", "Echo in Beats per Minute");
		ui_interface->addHorizontalSlider("time5", &fHslider12, FAUSTFLOAT(2.4e+02), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVbargraph0, "nomidi", "no");
		ui_interface->addVerticalBargraph("v1", &fVbargraph0, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph1, "nomidi", "no");
		ui_interface->addVerticalBargraph("v2", &fVbargraph1, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph2, "nomidi", "no");
		ui_interface->addVerticalBargraph("v3", &fVbargraph2, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph3, "nomidi", "no");
		ui_interface->addVerticalBargraph("v4", &fVbargraph3, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph4, "nomidi", "no");
		ui_interface->addVerticalBargraph("v5", &fVbargraph4, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = std::tan(fConst2 * static_cast<double>(fHslider0));
		double fSlow1 = GxMbe_faustpower2_f(fSlow0);
		double fSlow2 = 2.0 * (1.0 - 1.0 / fSlow1);
		double fSlow3 = 1.0 / fSlow0;
		double fSlow4 = (fSlow3 + -1.0000000000000004) / fSlow0 + 1.0;
		double fSlow5 = (fSlow3 + 1.0000000000000004) / fSlow0 + 1.0;
		double fSlow6 = 1.0 / fSlow5;
		double fSlow7 = std::tan(fConst2 * static_cast<double>(fHslider1));
		double fSlow8 = GxMbe_faustpower2_f(fSlow7);
		double fSlow9 = 2.0 * (1.0 - 1.0 / fSlow8);
		double fSlow10 = 1.0 / fSlow7;
		double fSlow11 = (fSlow10 + -1.0000000000000004) / fSlow7 + 1.0;
		double fSlow12 = (fSlow10 + 1.0000000000000004) / fSlow7 + 1.0;
		double fSlow13 = 1.0 / fSlow12;
		double fSlow14 = std::tan(fConst2 * static_cast<double>(fHslider2));
		double fSlow15 = GxMbe_faustpower2_f(fSlow14);
		double fSlow16 = 2.0 * (1.0 - 1.0 / fSlow15);
		double fSlow17 = 1.0 / fSlow14;
		double fSlow18 = (fSlow17 + -1.0000000000000004) / fSlow14 + 1.0;
		double fSlow19 = (fSlow17 + 1.0000000000000004) / fSlow14 + 1.0;
		double fSlow20 = 1.0 / fSlow19;
		double fSlow21 = std::tan(fConst2 * static_cast<double>(fHslider3));
		double fSlow22 = GxMbe_faustpower2_f(fSlow21);
		double fSlow23 = 2.0 * (1.0 - 1.0 / fSlow22);
		double fSlow24 = 1.0 / fSlow21;
		double fSlow25 = (fSlow24 + -1.0000000000000004) / fSlow21 + 1.0;
		double fSlow26 = (fSlow24 + 1.0000000000000004) / fSlow21 + 1.0;
		double fSlow27 = 1.0 / fSlow26;
		double fSlow28 = 1.0 - fSlow24;
		double fSlow29 = 1.0 / (fSlow24 + 1.0);
		double fSlow30 = 1.0 - fSlow17;
		double fSlow31 = fSlow17 + 1.0;
		double fSlow32 = 1.0 / fSlow31;
		double fSlow33 = 1.0 - fSlow10;
		double fSlow34 = fSlow10 + 1.0;
		double fSlow35 = 1.0 / fSlow34;
		double fSlow36 = 1.0 - fSlow3;
		double fSlow37 = fSlow3 + 1.0;
		double fSlow38 = 1.0 / fSlow37;
		double fSlow39 = fConst3 / static_cast<double>(fHslider4);
		double fSlow40 = 1.000000000000001e-05 * static_cast<double>(fHslider5);
		double fSlow41 = 1.0 / (fSlow1 * fSlow5);
		double fSlow42 = fConst3 / static_cast<double>(fHslider6);
		double fSlow43 = 1.000000000000001e-05 * static_cast<double>(fHslider7);
		double fSlow44 = 1.0 - fSlow36 / fSlow0;
		double fSlow45 = 1.0 / (fSlow37 / fSlow0 + 1.0);
		double fSlow46 = 1.0 / (fSlow8 * fSlow12);
		double fSlow47 = fConst3 / static_cast<double>(fHslider8);
		double fSlow48 = 1.000000000000001e-05 * static_cast<double>(fHslider9);
		double fSlow49 = 1.0 - fSlow33 / fSlow7;
		double fSlow50 = 1.0 / (fSlow34 / fSlow7 + 1.0);
		double fSlow51 = 1.0 / (fSlow15 * fSlow19);
		double fSlow52 = fConst3 / static_cast<double>(fHslider10);
		double fSlow53 = 1.000000000000001e-05 * static_cast<double>(fHslider11);
		double fSlow54 = 1.0 - fSlow30 / fSlow14;
		double fSlow55 = 1.0 / (fSlow31 / fSlow14 + 1.0);
		double fSlow56 = 1.0 / (fSlow22 * fSlow26);
		double fSlow57 = fConst3 / static_cast<double>(fHslider12);
		double fSlow58 = 1.000000000000001e-05 * static_cast<double>(fHslider13);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			int iTemp0 = iRec1[1] < 4096;
			double fTemp1 = static_cast<double>(input0[i0]);
			fVec0[0] = fTemp1;
			fRec11[0] = -(fSlow29 * (fSlow28 * fRec11[1] - (fTemp1 + fVec0[1])));
			fRec10[0] = fRec11[0] - fSlow27 * (fSlow25 * fRec10[2] + fSlow23 * fRec10[1]);
			double fTemp2 = fSlow27 * (fRec10[2] + fRec10[0] + 2.0 * fRec10[1]);
			fVec1[0] = fTemp2;
			fRec9[0] = -(fSlow32 * (fSlow30 * fRec9[1] - (fTemp2 + fVec1[1])));
			fRec8[0] = fRec9[0] - fSlow20 * (fSlow18 * fRec8[2] + fSlow16 * fRec8[1]);
			double fTemp3 = fSlow20 * (fRec8[2] + fRec8[0] + 2.0 * fRec8[1]);
			fVec2[0] = fTemp3;
			fRec7[0] = -(fSlow35 * (fSlow33 * fRec7[1] - (fTemp3 + fVec2[1])));
			fRec6[0] = fRec7[0] - fSlow13 * (fSlow11 * fRec6[2] + fSlow9 * fRec6[1]);
			double fTemp4 = fSlow13 * (fRec6[2] + fRec6[0] + 2.0 * fRec6[1]);
			fVec3[0] = fTemp4;
			fRec5[0] = -(fSlow38 * (fSlow36 * fRec5[1] - (fTemp4 + fVec3[1])));
			fRec4[0] = fRec5[0] - fSlow6 * (fSlow4 * fRec4[2] + fSlow2 * fRec4[1]);
			double fTemp5 = ((fRec12[1] != 0.0) ? (((fRec13[1] > 0.0) & (fRec13[1] < 1.0)) ? fRec12[1] : 0.0) : (((fRec13[1] == 0.0) & (fSlow39 != fRec14[1])) ? fConst4 : (((fRec13[1] == 1.0) & (fSlow39 != fRec15[1])) ? -fConst4 : 0.0)));
			fRec12[0] = fTemp5;
			fRec13[0] = std::max<double>(0.0, std::min<double>(1.0, fRec13[1] + fTemp5));
			fRec14[0] = (((fRec13[1] >= 1.0) & (fRec15[1] != fSlow39)) ? fSlow39 : fRec14[1]);
			fRec15[0] = (((fRec13[1] <= 0.0) & (fRec14[1] != fSlow39)) ? fSlow39 : fRec15[1]);
			double fTemp6 = fRec3[(faust_wrap_sub(IOTA0, faust_wrap_add(static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec14[0]))), 1))) & 524287];
			fRec16[0] = fSlow40 + 0.999 * fRec16[1];
			fRec3[IOTA0 & 524287] = fRec16[0] * (fTemp6 + fRec13[0] * (fRec3[(faust_wrap_sub(IOTA0, faust_wrap_add(static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec15[0]))), 1))) & 524287] - fTemp6)) + fSlow6 * (fRec4[2] + fRec4[0] + 2.0 * fRec4[1]);
			double fTemp7 = fRec3[IOTA0 & 524287];
			double fTemp8 = std::max<double>(fConst1, std::fabs(fTemp7));
			fRec0[0] = ((iTemp0) ? std::max<double>(fRec0[1], fTemp8) : fTemp8);
			iRec1[0] = ((iTemp0) ? faust_wrap_add(iRec1[1], 1) : 1);
			fRec2[0] = ((iTemp0) ? fRec2[1] : fRec0[1]);
			fVbargraph0 = static_cast<FAUSTFLOAT>(fRec2[0]);
			int iTemp9 = iRec18[1] < 4096;
			fRec22[0] = -(fSlow38 * (fSlow36 * fRec22[1] - fSlow3 * (fTemp4 - fVec3[1])));
			fRec21[0] = fRec22[0] - fSlow6 * (fSlow4 * fRec21[2] + fSlow2 * fRec21[1]);
			double fTemp10 = ((fRec23[1] != 0.0) ? (((fRec24[1] > 0.0) & (fRec24[1] < 1.0)) ? fRec23[1] : 0.0) : (((fRec24[1] == 0.0) & (fSlow42 != fRec25[1])) ? fConst4 : (((fRec24[1] == 1.0) & (fSlow42 != fRec26[1])) ? -fConst4 : 0.0)));
			fRec23[0] = fTemp10;
			fRec24[0] = std::max<double>(0.0, std::min<double>(1.0, fRec24[1] + fTemp10));
			fRec25[0] = (((fRec24[1] >= 1.0) & (fRec26[1] != fSlow42)) ? fSlow42 : fRec25[1]);
			fRec26[0] = (((fRec24[1] <= 0.0) & (fRec25[1] != fSlow42)) ? fSlow42 : fRec26[1]);
			double fTemp11 = fRec20[(faust_wrap_sub(IOTA0, faust_wrap_add(static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec25[0]))), 1))) & 524287];
			fRec27[0] = fSlow43 + 0.999 * fRec27[1];
			fRec20[IOTA0 & 524287] = fRec27[0] * (fTemp11 + fRec24[0] * (fRec20[(faust_wrap_sub(IOTA0, faust_wrap_add(static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec26[0]))), 1))) & 524287] - fTemp11)) + fSlow41 * (fRec21[2] + (fRec21[0] - 2.0 * fRec21[1]));
			double fTemp12 = fRec20[IOTA0 & 524287];
			double fTemp13 = std::max<double>(fConst1, std::fabs(fTemp12));
			fRec17[0] = ((iTemp9) ? std::max<double>(fRec17[1], fTemp13) : fTemp13);
			iRec18[0] = ((iTemp9) ? faust_wrap_add(iRec18[1], 1) : 1);
			fRec19[0] = ((iTemp9) ? fRec19[1] : fRec17[1]);
			fVbargraph1 = static_cast<FAUSTFLOAT>(fRec19[0]);
			int iTemp14 = iRec29[1] < 4096;
			double fTemp15 = fSlow2 * fRec32[1];
			fRec34[0] = -(fSlow35 * (fSlow33 * fRec34[1] - fSlow10 * (fTemp3 - fVec2[1])));
			fRec33[0] = fRec34[0] - fSlow13 * (fSlow11 * fRec33[2] + fSlow9 * fRec33[1]);
			fRec32[0] = fSlow46 * (fRec33[2] + (fRec33[0] - 2.0 * fRec33[1])) - fSlow45 * (fSlow44 * fRec32[2] + fTemp15);
			double fTemp16 = ((fRec35[1] != 0.0) ? (((fRec36[1] > 0.0) & (fRec36[1] < 1.0)) ? fRec35[1] : 0.0) : (((fRec36[1] == 0.0) & (fSlow47 != fRec37[1])) ? fConst4 : (((fRec36[1] == 1.0) & (fSlow47 != fRec38[1])) ? -fConst4 : 0.0)));
			fRec35[0] = fTemp16;
			fRec36[0] = std::max<double>(0.0, std::min<double>(1.0, fRec36[1] + fTemp16));
			fRec37[0] = (((fRec36[1] >= 1.0) & (fRec38[1] != fSlow47)) ? fSlow47 : fRec37[1]);
			fRec38[0] = (((fRec36[1] <= 0.0) & (fRec37[1] != fSlow47)) ? fSlow47 : fRec38[1]);
			double fTemp17 = fRec31[(faust_wrap_sub(IOTA0, faust_wrap_add(static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec37[0]))), 1))) & 524287];
			fRec39[0] = fSlow48 + 0.999 * fRec39[1];
			fRec31[IOTA0 & 524287] = fSlow45 * (fTemp15 + fSlow44 * fRec32[0]) + fRec39[0] * (fTemp17 + fRec36[0] * (fRec31[(faust_wrap_sub(IOTA0, faust_wrap_add(static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec38[0]))), 1))) & 524287] - fTemp17)) + fRec32[2];
			double fTemp18 = fRec31[IOTA0 & 524287];
			double fTemp19 = std::max<double>(fConst1, std::fabs(fTemp18));
			fRec28[0] = ((iTemp14) ? std::max<double>(fRec28[1], fTemp19) : fTemp19);
			iRec29[0] = ((iTemp14) ? faust_wrap_add(iRec29[1], 1) : 1);
			fRec30[0] = ((iTemp14) ? fRec30[1] : fRec28[1]);
			fVbargraph2 = static_cast<FAUSTFLOAT>(fRec30[0]);
			int iTemp20 = iRec41[1] < 4096;
			double fTemp21 = fSlow2 * fRec44[1];
			double fTemp22 = fSlow9 * fRec45[1];
			fRec47[0] = -(fSlow32 * (fSlow30 * fRec47[1] - fSlow17 * (fTemp2 - fVec1[1])));
			fRec46[0] = fRec47[0] - fSlow20 * (fSlow18 * fRec46[2] + fSlow16 * fRec46[1]);
			fRec45[0] = fSlow51 * (fRec46[2] + (fRec46[0] - 2.0 * fRec46[1])) - fSlow50 * (fSlow49 * fRec45[2] + fTemp22);
			fRec44[0] = fRec45[2] + fSlow50 * (fTemp22 + fSlow49 * fRec45[0]) - fSlow45 * (fSlow44 * fRec44[2] + fTemp21);
			double fTemp23 = ((fRec48[1] != 0.0) ? (((fRec49[1] > 0.0) & (fRec49[1] < 1.0)) ? fRec48[1] : 0.0) : (((fRec49[1] == 0.0) & (fSlow52 != fRec50[1])) ? fConst4 : (((fRec49[1] == 1.0) & (fSlow52 != fRec51[1])) ? -fConst4 : 0.0)));
			fRec48[0] = fTemp23;
			fRec49[0] = std::max<double>(0.0, std::min<double>(1.0, fRec49[1] + fTemp23));
			fRec50[0] = (((fRec49[1] >= 1.0) & (fRec51[1] != fSlow52)) ? fSlow52 : fRec50[1]);
			fRec51[0] = (((fRec49[1] <= 0.0) & (fRec50[1] != fSlow52)) ? fSlow52 : fRec51[1]);
			double fTemp24 = fRec43[(faust_wrap_sub(IOTA0, faust_wrap_add(static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec50[0]))), 1))) & 524287];
			fRec52[0] = fSlow53 + 0.999 * fRec52[1];
			fRec43[IOTA0 & 524287] = fSlow45 * (fTemp21 + fSlow44 * fRec44[0]) + fRec52[0] * (fTemp24 + fRec49[0] * (fRec43[(faust_wrap_sub(IOTA0, faust_wrap_add(static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec51[0]))), 1))) & 524287] - fTemp24)) + fRec44[2];
			double fTemp25 = fRec43[IOTA0 & 524287];
			double fTemp26 = std::max<double>(fConst1, std::fabs(fTemp25));
			fRec40[0] = ((iTemp20) ? std::max<double>(fRec40[1], fTemp26) : fTemp26);
			iRec41[0] = ((iTemp20) ? faust_wrap_add(iRec41[1], 1) : 1);
			fRec42[0] = ((iTemp20) ? fRec42[1] : fRec40[1]);
			fVbargraph3 = static_cast<FAUSTFLOAT>(fRec42[0]);
			int iTemp27 = iRec54[1] < 4096;
			double fTemp28 = fSlow2 * fRec57[1];
			double fTemp29 = fSlow9 * fRec58[1];
			double fTemp30 = fSlow16 * fRec59[1];
			fRec61[0] = -(fSlow29 * (fSlow28 * fRec61[1] - fSlow24 * (fTemp1 - fVec0[1])));
			fRec60[0] = fRec61[0] - fSlow27 * (fSlow25 * fRec60[2] + fSlow23 * fRec60[1]);
			fRec59[0] = fSlow56 * (fRec60[2] + (fRec60[0] - 2.0 * fRec60[1])) - fSlow55 * (fSlow54 * fRec59[2] + fTemp30);
			fRec58[0] = fRec59[2] + fSlow55 * (fTemp30 + fSlow54 * fRec59[0]) - fSlow50 * (fSlow49 * fRec58[2] + fTemp29);
			fRec57[0] = fRec58[2] + fSlow50 * (fTemp29 + fSlow49 * fRec58[0]) - fSlow45 * (fSlow44 * fRec57[2] + fTemp28);
			double fTemp31 = ((fRec62[1] != 0.0) ? (((fRec63[1] > 0.0) & (fRec63[1] < 1.0)) ? fRec62[1] : 0.0) : (((fRec63[1] == 0.0) & (fSlow57 != fRec64[1])) ? fConst4 : (((fRec63[1] == 1.0) & (fSlow57 != fRec65[1])) ? -fConst4 : 0.0)));
			fRec62[0] = fTemp31;
			fRec63[0] = std::max<double>(0.0, std::min<double>(1.0, fRec63[1] + fTemp31));
			fRec64[0] = (((fRec63[1] >= 1.0) & (fRec65[1] != fSlow57)) ? fSlow57 : fRec64[1]);
			fRec65[0] = (((fRec63[1] <= 0.0) & (fRec64[1] != fSlow57)) ? fSlow57 : fRec65[1]);
			double fTemp32 = fRec56[(faust_wrap_sub(IOTA0, faust_wrap_add(static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec64[0]))), 1))) & 524287];
			fRec66[0] = fSlow58 + 0.999 * fRec66[1];
			fRec56[IOTA0 & 524287] = fSlow45 * (fTemp28 + fSlow44 * fRec57[0]) + fRec66[0] * (fTemp32 + fRec63[0] * (fRec56[(faust_wrap_sub(IOTA0, faust_wrap_add(static_cast<int>(std::min<double>(262144.0, std::max<double>(0.0, fRec65[0]))), 1))) & 524287] - fTemp32)) + fRec57[2];
			double fTemp33 = fRec56[IOTA0 & 524287];
			double fTemp34 = std::max<double>(fConst1, std::fabs(fTemp33));
			fRec53[0] = ((iTemp27) ? std::max<double>(fRec53[1], fTemp34) : fTemp34);
			iRec54[0] = ((iTemp27) ? faust_wrap_add(iRec54[1], 1) : 1);
			fRec55[0] = ((iTemp27) ? fRec55[1] : fRec53[1]);
			fVbargraph4 = static_cast<FAUSTFLOAT>(fRec55[0]);
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp33 + fTemp25 + fTemp18 + fTemp12 + fTemp7);
			fVec0[1] = fVec0[0];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fVec1[1] = fVec1[0];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fVec2[1] = fVec2[0];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fVec3[1] = fVec3[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec0[1] = fRec0[0];
			iRec1[1] = iRec1[0];
			fRec2[1] = fRec2[0];
			fRec22[1] = fRec22[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec23[1] = fRec23[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec26[1] = fRec26[0];
			fRec27[1] = fRec27[0];
			fRec17[1] = fRec17[0];
			iRec18[1] = iRec18[0];
			fRec19[1] = fRec19[0];
			fRec34[1] = fRec34[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fRec28[1] = fRec28[0];
			iRec29[1] = iRec29[0];
			fRec30[1] = fRec30[0];
			fRec47[1] = fRec47[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec48[1] = fRec48[0];
			fRec49[1] = fRec49[0];
			fRec50[1] = fRec50[0];
			fRec51[1] = fRec51[0];
			fRec52[1] = fRec52[0];
			fRec40[1] = fRec40[0];
			iRec41[1] = iRec41[0];
			fRec42[1] = fRec42[0];
			fRec61[1] = fRec61[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec62[1] = fRec62[0];
			fRec63[1] = fRec63[0];
			fRec64[1] = fRec64[0];
			fRec65[1] = fRec65[0];
			fRec66[1] = fRec66[0];
			fRec53[1] = fRec53[0];
			iRec54[1] = iRec54[0];
			fRec55[1] = fRec55[0];
		}
	}

};

#endif
