/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "MultiBand Distortion"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbd -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxMbd_H__
#define  __GxMbd_H__

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
#define FAUSTCLASS GxMbd
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

static double GxMbd_faustpower2_f(double value) {
	return value * value;
}

class GxMbd : public chdsp {
	
 private:
	
	int iVec0[2];
	FAUSTFLOAT fVslider0;
	double fRec0[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	double fRec13[2];
	double fVec1[2];
	double fRec12[2];
	double fRec11[3];
	double fVec2[2];
	double fRec10[2];
	double fRec9[3];
	double fVec3[2];
	double fRec8[2];
	double fRec7[3];
	double fVec4[2];
	double fRec6[2];
	double fRec5[3];
	FAUSTFLOAT fHslider4;
	double fRec14[2];
	FAUSTFLOAT fHslider5;
	double fRec15[2];
	double fVec5[2];
	double fConst4;
	double fRec4[2];
	double fRec1[2];
	int iRec2[2];
	double fRec3[2];
	FAUSTFLOAT fVbargraph0;
	double fRec21[2];
	double fRec20[3];
	FAUSTFLOAT fHslider6;
	double fRec22[2];
	FAUSTFLOAT fHslider7;
	double fRec23[2];
	double fVec6[2];
	double fRec19[2];
	double fRec16[2];
	int iRec17[2];
	double fRec18[2];
	FAUSTFLOAT fVbargraph1;
	double fRec30[2];
	double fRec29[3];
	double fRec28[3];
	FAUSTFLOAT fHslider8;
	double fRec31[2];
	FAUSTFLOAT fHslider9;
	double fRec32[2];
	double fVec7[2];
	double fRec27[2];
	double fRec24[2];
	int iRec25[2];
	double fRec26[2];
	FAUSTFLOAT fVbargraph2;
	double fRec40[2];
	double fRec39[3];
	double fRec38[3];
	double fRec37[3];
	FAUSTFLOAT fHslider10;
	double fRec41[2];
	FAUSTFLOAT fHslider11;
	double fRec42[2];
	double fVec8[2];
	double fRec36[2];
	double fRec33[2];
	int iRec34[2];
	double fRec35[2];
	FAUSTFLOAT fVbargraph3;
	double fRec51[2];
	double fRec50[3];
	double fRec49[3];
	double fRec48[3];
	double fRec47[3];
	FAUSTFLOAT fHslider12;
	double fRec52[2];
	FAUSTFLOAT fHslider13;
	double fRec53[2];
	double fVec9[2];
	double fRec46[2];
	double fRec43[2];
	int iRec44[2];
	double fRec45[2];
	FAUSTFLOAT fVbargraph4;
	
 public:
	GxMbd() {
	}
	
	GxMbd(const GxMbd&) = default;
	
	virtual ~GxMbd() = default;
	
	GxMbd& operator=(const GxMbd&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Distortion");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbd -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "MultiBand Distortion");
		m->declare("filename", "gx-mbd.dsp");
		m->declare("filters.lib/dcblockerat:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblockerat:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblockerat:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "LicenseRef-STK-4.3");
		m->declare("id", "mbd");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/cubicnl:author", "Julius O. Smith III");
		m->declare("misceffects.lib/cubicnl:license", "LicenseRef-STK-4.3");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "MultiBand Distortion");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reducemaps.lib/author", "Yann Orlarey");
		m->declare("reducemaps.lib/copyright", "Grame and Yann Orlarey");
		m->declare("reducemaps.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("reducemaps.lib/name", "Reduce Library");
		m->declare("reducemaps.lib/version", "1.2.0");
		m->declare("shortname", "MB Distortion");
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
		fConst3 = 1.0 - fConst2;
		fConst4 = 1.0 / (fConst2 + 1.0);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
		fHslider0 = static_cast<FAUSTFLOAT>(8e+01);
		fHslider1 = static_cast<FAUSTFLOAT>(2.1e+02);
		fHslider2 = static_cast<FAUSTFLOAT>(1.7e+03);
		fHslider3 = static_cast<FAUSTFLOAT>(5e+03);
		fHslider4 = static_cast<FAUSTFLOAT>(0.0);
		fHslider5 = static_cast<FAUSTFLOAT>(0.0);
		fHslider6 = static_cast<FAUSTFLOAT>(0.0);
		fHslider7 = static_cast<FAUSTFLOAT>(0.0);
		fHslider8 = static_cast<FAUSTFLOAT>(0.0);
		fHslider9 = static_cast<FAUSTFLOAT>(0.0);
		fHslider10 = static_cast<FAUSTFLOAT>(0.0);
		fHslider11 = static_cast<FAUSTFLOAT>(0.0);
		fHslider12 = static_cast<FAUSTFLOAT>(0.0);
		fHslider13 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec0[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec13[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec12[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec11[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec2[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec10[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec9[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fVec3[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec8[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 3; l11 = faust_wrap_add(l11, 1)) {
			fRec7[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fVec4[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec6[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 3; l14 = faust_wrap_add(l14, 1)) {
			fRec5[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec14[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec15[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fVec5[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec4[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec1[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			iRec2[l20] = 0;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec3[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec21[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 3; l23 = faust_wrap_add(l23, 1)) {
			fRec20[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec22[l24] = 0.0;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec23[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fVec6[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec19[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec16[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			iRec17[l29] = 0;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec18[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec30[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 3; l32 = faust_wrap_add(l32, 1)) {
			fRec29[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 3; l33 = faust_wrap_add(l33, 1)) {
			fRec28[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec31[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec32[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fVec7[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec27[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fRec24[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			iRec25[l39] = 0;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec26[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec40[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 3; l42 = faust_wrap_add(l42, 1)) {
			fRec39[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 3; l43 = faust_wrap_add(l43, 1)) {
			fRec38[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 3; l44 = faust_wrap_add(l44, 1)) {
			fRec37[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec41[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fRec42[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fVec8[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec36[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec33[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			iRec34[l50] = 0;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fRec35[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec51[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 3; l53 = faust_wrap_add(l53, 1)) {
			fRec50[l53] = 0.0;
		}
		for (int l54 = 0; l54 < 3; l54 = faust_wrap_add(l54, 1)) {
			fRec49[l54] = 0.0;
		}
		for (int l55 = 0; l55 < 3; l55 = faust_wrap_add(l55, 1)) {
			fRec48[l55] = 0.0;
		}
		for (int l56 = 0; l56 < 3; l56 = faust_wrap_add(l56, 1)) {
			fRec47[l56] = 0.0;
		}
		for (int l57 = 0; l57 < 2; l57 = faust_wrap_add(l57, 1)) {
			fRec52[l57] = 0.0;
		}
		for (int l58 = 0; l58 < 2; l58 = faust_wrap_add(l58, 1)) {
			fRec53[l58] = 0.0;
		}
		for (int l59 = 0; l59 < 2; l59 = faust_wrap_add(l59, 1)) {
			fVec9[l59] = 0.0;
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
	
	virtual GxMbd* clone() {
		return new GxMbd(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("MultiBand Distortion");
		ui_interface->declare(&fHslider4, "tooltip", "Amount of distortion");
		ui_interface->addHorizontalSlider("Drive1", &fHslider4, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider6, "tooltip", "Amount of distortion");
		ui_interface->addHorizontalSlider("Drive2", &fHslider6, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider8, "tooltip", "Amount of distortion");
		ui_interface->addHorizontalSlider("Drive3", &fHslider8, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider10, "tooltip", "Amount of distortion");
		ui_interface->addHorizontalSlider("Drive4", &fHslider10, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider12, "tooltip", "Amount of distortion");
		ui_interface->addHorizontalSlider("Drive5", &fHslider12, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addVerticalSlider("Gain", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(-4e+01), FAUSTFLOAT(4.0), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider5, "tooltip", "Brings in even harmonics");
		ui_interface->addHorizontalSlider("Offset1", &fHslider5, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(0.5), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider7, "tooltip", "Brings in even harmonics");
		ui_interface->addHorizontalSlider("Offset2", &fHslider7, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(0.5), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider9, "tooltip", "Brings in even harmonics");
		ui_interface->addHorizontalSlider("Offset3", &fHslider9, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(0.5), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider11, "tooltip", "Brings in even harmonics");
		ui_interface->addHorizontalSlider("Offset4", &fHslider11, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(0.5), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider13, "tooltip", "Brings in even harmonics");
		ui_interface->addHorizontalSlider("Offset5", &fHslider13, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(0.5), FAUSTFLOAT(0.01));
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
		double fSlow0 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider0));
		double fSlow1 = std::tan(fConst2 * static_cast<double>(fHslider0));
		double fSlow2 = GxMbd_faustpower2_f(fSlow1);
		double fSlow3 = 2.0 * (1.0 - 1.0 / fSlow2);
		double fSlow4 = 1.0 / fSlow1;
		double fSlow5 = (fSlow4 + -1.0000000000000004) / fSlow1 + 1.0;
		double fSlow6 = (fSlow4 + 1.0000000000000004) / fSlow1 + 1.0;
		double fSlow7 = 1.0 / fSlow6;
		double fSlow8 = std::tan(fConst2 * static_cast<double>(fHslider1));
		double fSlow9 = GxMbd_faustpower2_f(fSlow8);
		double fSlow10 = 2.0 * (1.0 - 1.0 / fSlow9);
		double fSlow11 = 1.0 / fSlow8;
		double fSlow12 = (fSlow11 + -1.0000000000000004) / fSlow8 + 1.0;
		double fSlow13 = (fSlow11 + 1.0000000000000004) / fSlow8 + 1.0;
		double fSlow14 = 1.0 / fSlow13;
		double fSlow15 = std::tan(fConst2 * static_cast<double>(fHslider2));
		double fSlow16 = GxMbd_faustpower2_f(fSlow15);
		double fSlow17 = 2.0 * (1.0 - 1.0 / fSlow16);
		double fSlow18 = 1.0 / fSlow15;
		double fSlow19 = (fSlow18 + -1.0000000000000004) / fSlow15 + 1.0;
		double fSlow20 = (fSlow18 + 1.0000000000000004) / fSlow15 + 1.0;
		double fSlow21 = 1.0 / fSlow20;
		double fSlow22 = std::tan(fConst2 * static_cast<double>(fHslider3));
		double fSlow23 = GxMbd_faustpower2_f(fSlow22);
		double fSlow24 = 2.0 * (1.0 - 1.0 / fSlow23);
		double fSlow25 = 1.0 / fSlow22;
		double fSlow26 = (fSlow25 + -1.0000000000000004) / fSlow22 + 1.0;
		double fSlow27 = (fSlow25 + 1.0000000000000004) / fSlow22 + 1.0;
		double fSlow28 = 1.0 / fSlow27;
		double fSlow29 = 1.0 - fSlow25;
		double fSlow30 = 1.0 / (fSlow25 + 1.0);
		double fSlow31 = 1.0 - fSlow18;
		double fSlow32 = fSlow18 + 1.0;
		double fSlow33 = 1.0 / fSlow32;
		double fSlow34 = 1.0 - fSlow11;
		double fSlow35 = fSlow11 + 1.0;
		double fSlow36 = 1.0 / fSlow35;
		double fSlow37 = 1.0 - fSlow4;
		double fSlow38 = fSlow4 + 1.0;
		double fSlow39 = 1.0 / fSlow38;
		double fSlow40 = 0.0010000000000000009 * static_cast<double>(fHslider4);
		double fSlow41 = 0.0010000000000000009 * static_cast<double>(fHslider5);
		double fSlow42 = 0.0010000000000000009 * static_cast<double>(fHslider6);
		double fSlow43 = 1.0 / (fSlow2 * fSlow6);
		double fSlow44 = 0.0010000000000000009 * static_cast<double>(fHslider7);
		double fSlow45 = 1.0 - fSlow37 / fSlow1;
		double fSlow46 = 1.0 / (fSlow38 / fSlow1 + 1.0);
		double fSlow47 = 1.0 / (fSlow9 * fSlow13);
		double fSlow48 = 0.0010000000000000009 * static_cast<double>(fHslider8);
		double fSlow49 = 0.0010000000000000009 * static_cast<double>(fHslider9);
		double fSlow50 = 1.0 - fSlow34 / fSlow8;
		double fSlow51 = 1.0 / (fSlow35 / fSlow8 + 1.0);
		double fSlow52 = 1.0 / (fSlow16 * fSlow20);
		double fSlow53 = 0.0010000000000000009 * static_cast<double>(fHslider10);
		double fSlow54 = 0.0010000000000000009 * static_cast<double>(fHslider11);
		double fSlow55 = 1.0 - fSlow31 / fSlow15;
		double fSlow56 = 1.0 / (fSlow32 / fSlow15 + 1.0);
		double fSlow57 = 1.0 / (fSlow23 * fSlow27);
		double fSlow58 = 0.0010000000000000009 * static_cast<double>(fHslider12);
		double fSlow59 = 0.0010000000000000009 * static_cast<double>(fHslider13);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec0[0] = fSlow0 + 0.999 * fRec0[1];
			int iTemp0 = iRec2[1] < 4096;
			fRec13[0] = 1e-20 * static_cast<double>(faust_wrap_sub(1, iVec0[1])) - fRec13[1];
			double fTemp1 = static_cast<double>(input0[i0]) + fRec13[0];
			fVec1[0] = fTemp1;
			fRec12[0] = -(fSlow30 * (fSlow29 * fRec12[1] - (fTemp1 + fVec1[1])));
			fRec11[0] = fRec12[0] - fSlow28 * (fSlow26 * fRec11[2] + fSlow24 * fRec11[1]);
			double fTemp2 = fSlow28 * (fRec11[2] + fRec11[0] + 2.0 * fRec11[1]);
			fVec2[0] = fTemp2;
			fRec10[0] = -(fSlow33 * (fSlow31 * fRec10[1] - (fTemp2 + fVec2[1])));
			fRec9[0] = fRec10[0] - fSlow21 * (fSlow19 * fRec9[2] + fSlow17 * fRec9[1]);
			double fTemp3 = fSlow21 * (fRec9[2] + fRec9[0] + 2.0 * fRec9[1]);
			fVec3[0] = fTemp3;
			fRec8[0] = -(fSlow36 * (fSlow34 * fRec8[1] - (fTemp3 + fVec3[1])));
			fRec7[0] = fRec8[0] - fSlow14 * (fSlow12 * fRec7[2] + fSlow10 * fRec7[1]);
			double fTemp4 = fSlow14 * (fRec7[2] + fRec7[0] + 2.0 * fRec7[1]);
			fVec4[0] = fTemp4;
			fRec6[0] = -(fSlow39 * (fSlow37 * fRec6[1] - (fTemp4 + fVec4[1])));
			fRec5[0] = fRec6[0] - fSlow7 * (fSlow5 * fRec5[2] + fSlow3 * fRec5[1]);
			fRec14[0] = fSlow40 + 0.999 * fRec14[1];
			fRec15[0] = fSlow41 + 0.999 * fRec15[1];
			double fTemp5 = std::max<double>(-1.0, std::min<double>(1.0, fRec15[0] + fSlow7 * std::pow(1e+01, 2.0 * fRec14[0]) * (fRec5[2] + fRec5[0] + 2.0 * fRec5[1])));
			double fTemp6 = fTemp5 * (1.0 - 0.3333333333333333 * GxMbd_faustpower2_f(fTemp5));
			fVec5[0] = fTemp6;
			fRec4[0] = fConst4 * (fTemp6 - fVec5[1] + fConst3 * fRec4[1]);
			double fTemp7 = std::max<double>(fConst1, std::fabs(fRec4[0]));
			fRec1[0] = ((iTemp0) ? std::max<double>(fRec1[1], fTemp7) : fTemp7);
			iRec2[0] = ((iTemp0) ? faust_wrap_add(iRec2[1], 1) : 1);
			fRec3[0] = ((iTemp0) ? fRec3[1] : fRec1[1]);
			fVbargraph0 = static_cast<FAUSTFLOAT>(fRec3[0]);
			int iTemp8 = iRec17[1] < 4096;
			fRec21[0] = -(fSlow39 * (fSlow37 * fRec21[1] - fSlow4 * (fTemp4 - fVec4[1])));
			fRec20[0] = fRec21[0] - fSlow7 * (fSlow5 * fRec20[2] + fSlow3 * fRec20[1]);
			fRec22[0] = fSlow42 + 0.999 * fRec22[1];
			fRec23[0] = fSlow44 + 0.999 * fRec23[1];
			double fTemp9 = std::max<double>(-1.0, std::min<double>(1.0, fRec23[0] + fSlow43 * std::pow(1e+01, 2.0 * fRec22[0]) * (fRec20[2] + (fRec20[0] - 2.0 * fRec20[1]))));
			double fTemp10 = fTemp9 * (1.0 - 0.3333333333333333 * GxMbd_faustpower2_f(fTemp9));
			fVec6[0] = fTemp10;
			fRec19[0] = fConst4 * (fTemp10 - fVec6[1] + fConst3 * fRec19[1]);
			double fTemp11 = std::max<double>(fConst1, std::fabs(fRec19[0]));
			fRec16[0] = ((iTemp8) ? std::max<double>(fRec16[1], fTemp11) : fTemp11);
			iRec17[0] = ((iTemp8) ? faust_wrap_add(iRec17[1], 1) : 1);
			fRec18[0] = ((iTemp8) ? fRec18[1] : fRec16[1]);
			fVbargraph1 = static_cast<FAUSTFLOAT>(fRec18[0]);
			int iTemp12 = iRec25[1] < 4096;
			double fTemp13 = fSlow3 * fRec28[1];
			fRec30[0] = -(fSlow36 * (fSlow34 * fRec30[1] - fSlow11 * (fTemp3 - fVec3[1])));
			fRec29[0] = fRec30[0] - fSlow14 * (fSlow12 * fRec29[2] + fSlow10 * fRec29[1]);
			fRec28[0] = fSlow47 * (fRec29[2] + (fRec29[0] - 2.0 * fRec29[1])) - fSlow46 * (fSlow45 * fRec28[2] + fTemp13);
			fRec31[0] = fSlow48 + 0.999 * fRec31[1];
			fRec32[0] = fSlow49 + 0.999 * fRec32[1];
			double fTemp14 = std::max<double>(-1.0, std::min<double>(1.0, fRec32[0] + std::pow(1e+01, 2.0 * fRec31[0]) * (fRec28[2] + fSlow46 * (fTemp13 + fSlow45 * fRec28[0]))));
			double fTemp15 = fTemp14 * (1.0 - 0.3333333333333333 * GxMbd_faustpower2_f(fTemp14));
			fVec7[0] = fTemp15;
			fRec27[0] = fConst4 * (fTemp15 - fVec7[1] + fConst3 * fRec27[1]);
			double fTemp16 = std::max<double>(fConst1, std::fabs(fRec27[0]));
			fRec24[0] = ((iTemp12) ? std::max<double>(fRec24[1], fTemp16) : fTemp16);
			iRec25[0] = ((iTemp12) ? faust_wrap_add(iRec25[1], 1) : 1);
			fRec26[0] = ((iTemp12) ? fRec26[1] : fRec24[1]);
			fVbargraph2 = static_cast<FAUSTFLOAT>(fRec26[0]);
			int iTemp17 = iRec34[1] < 4096;
			double fTemp18 = fSlow3 * fRec37[1];
			double fTemp19 = fSlow10 * fRec38[1];
			fRec40[0] = -(fSlow33 * (fSlow31 * fRec40[1] - fSlow18 * (fTemp2 - fVec2[1])));
			fRec39[0] = fRec40[0] - fSlow21 * (fSlow19 * fRec39[2] + fSlow17 * fRec39[1]);
			fRec38[0] = fSlow52 * (fRec39[2] + (fRec39[0] - 2.0 * fRec39[1])) - fSlow51 * (fSlow50 * fRec38[2] + fTemp19);
			fRec37[0] = fRec38[2] + fSlow51 * (fTemp19 + fSlow50 * fRec38[0]) - fSlow46 * (fSlow45 * fRec37[2] + fTemp18);
			fRec41[0] = fSlow53 + 0.999 * fRec41[1];
			fRec42[0] = fSlow54 + 0.999 * fRec42[1];
			double fTemp20 = std::max<double>(-1.0, std::min<double>(1.0, fRec42[0] + std::pow(1e+01, 2.0 * fRec41[0]) * (fRec37[2] + fSlow46 * (fTemp18 + fSlow45 * fRec37[0]))));
			double fTemp21 = fTemp20 * (1.0 - 0.3333333333333333 * GxMbd_faustpower2_f(fTemp20));
			fVec8[0] = fTemp21;
			fRec36[0] = fConst4 * (fTemp21 - fVec8[1] + fConst3 * fRec36[1]);
			double fTemp22 = std::max<double>(fConst1, std::fabs(fRec36[0]));
			fRec33[0] = ((iTemp17) ? std::max<double>(fRec33[1], fTemp22) : fTemp22);
			iRec34[0] = ((iTemp17) ? faust_wrap_add(iRec34[1], 1) : 1);
			fRec35[0] = ((iTemp17) ? fRec35[1] : fRec33[1]);
			fVbargraph3 = static_cast<FAUSTFLOAT>(fRec35[0]);
			int iTemp23 = iRec44[1] < 4096;
			double fTemp24 = fSlow3 * fRec47[1];
			double fTemp25 = fSlow10 * fRec48[1];
			double fTemp26 = fSlow17 * fRec49[1];
			fRec51[0] = -(fSlow30 * (fSlow29 * fRec51[1] - fSlow25 * (fTemp1 - fVec1[1])));
			fRec50[0] = fRec51[0] - fSlow28 * (fSlow26 * fRec50[2] + fSlow24 * fRec50[1]);
			fRec49[0] = fSlow57 * (fRec50[2] + (fRec50[0] - 2.0 * fRec50[1])) - fSlow56 * (fSlow55 * fRec49[2] + fTemp26);
			fRec48[0] = fRec49[2] + fSlow56 * (fTemp26 + fSlow55 * fRec49[0]) - fSlow51 * (fSlow50 * fRec48[2] + fTemp25);
			fRec47[0] = fRec48[2] + fSlow51 * (fTemp25 + fSlow50 * fRec48[0]) - fSlow46 * (fSlow45 * fRec47[2] + fTemp24);
			fRec52[0] = fSlow58 + 0.999 * fRec52[1];
			fRec53[0] = fSlow59 + 0.999 * fRec53[1];
			double fTemp27 = std::max<double>(-1.0, std::min<double>(1.0, fRec53[0] + std::pow(1e+01, 2.0 * fRec52[0]) * (fRec47[2] + fSlow46 * (fTemp24 + fSlow45 * fRec47[0]))));
			double fTemp28 = fTemp27 * (1.0 - 0.3333333333333333 * GxMbd_faustpower2_f(fTemp27));
			fVec9[0] = fTemp28;
			fRec46[0] = fConst4 * (fTemp28 - fVec9[1] + fConst3 * fRec46[1]);
			double fTemp29 = std::max<double>(fConst1, std::fabs(fRec46[0]));
			fRec43[0] = ((iTemp23) ? std::max<double>(fRec43[1], fTemp29) : fTemp29);
			iRec44[0] = ((iTemp23) ? faust_wrap_add(iRec44[1], 1) : 1);
			fRec45[0] = ((iTemp23) ? fRec45[1] : fRec43[1]);
			fVbargraph4 = static_cast<FAUSTFLOAT>(fRec45[0]);
			output0[i0] = static_cast<FAUSTFLOAT>((fRec46[0] + fRec36[0] + fRec27[0] + fRec19[0] + fRec4[0]) * fRec0[0]);
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			fRec13[1] = fRec13[0];
			fVec1[1] = fVec1[0];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fVec2[1] = fVec2[0];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fVec3[1] = fVec3[0];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fVec4[1] = fVec4[0];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fVec5[1] = fVec5[0];
			fRec4[1] = fRec4[0];
			fRec1[1] = fRec1[0];
			iRec2[1] = iRec2[0];
			fRec3[1] = fRec3[0];
			fRec21[1] = fRec21[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fVec6[1] = fVec6[0];
			fRec19[1] = fRec19[0];
			fRec16[1] = fRec16[0];
			iRec17[1] = iRec17[0];
			fRec18[1] = fRec18[0];
			fRec30[1] = fRec30[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec31[1] = fRec31[0];
			fRec32[1] = fRec32[0];
			fVec7[1] = fVec7[0];
			fRec27[1] = fRec27[0];
			fRec24[1] = fRec24[0];
			iRec25[1] = iRec25[0];
			fRec26[1] = fRec26[0];
			fRec40[1] = fRec40[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec41[1] = fRec41[0];
			fRec42[1] = fRec42[0];
			fVec8[1] = fVec8[0];
			fRec36[1] = fRec36[0];
			fRec33[1] = fRec33[0];
			iRec34[1] = iRec34[0];
			fRec35[1] = fRec35[0];
			fRec51[1] = fRec51[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec52[1] = fRec52[0];
			fRec53[1] = fRec53[0];
			fVec9[1] = fVec9[0];
			fRec46[1] = fRec46[0];
			fRec43[1] = fRec43[0];
			iRec44[1] = iRec44[0];
			fRec45[1] = fRec45[0];
		}
	}

};

#endif
