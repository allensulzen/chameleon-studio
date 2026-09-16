/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Multi Band Chorus"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbchor -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxMbchor_H__
#define  __GxMbchor_H__

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
#define FAUSTCLASS GxMbchor
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

class GxMbchorSIG0 {
	
  private:
	
	int iRec8[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsGxMbchorSIG0() {
		return 0;
	}
	int getNumOutputsGxMbchorSIG0() {
		return 1;
	}
	
	void instanceInitGxMbchorSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			iRec8[l7] = 0;
		}
	}
	
	void fillGxMbchorSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iRec8[0] = faust_wrap_add(iRec8[1], 1);
			table[i1] = std::sin(9.587379924285257e-05 * static_cast<double>(iRec8[1]));
			iRec8[1] = iRec8[0];
		}
	}

};

static GxMbchorSIG0* newGxMbchorSIG0() { return (GxMbchorSIG0*)new GxMbchorSIG0(); }
static void deleteGxMbchorSIG0(GxMbchorSIG0* dsp) { delete dsp; }

static double GxMbchor_faustpower2_f(double value) {
	return value * value;
}
static double DSY_SDRAM_BSS ftbl0GxMbchorSIG0[65536];

class GxMbchor : public chdsp {
	
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
	double fRec7[2];
	double fRec6[3];
	double fRec5[3];
	double fRec4[3];
	double fRec3[3];
	int IOTA0;
	double fVec1[131072];
	FAUSTFLOAT fHslider4;
	double fConst3;
	double fRec9[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	double fRec10[2];
	double fConst4;
	FAUSTFLOAT fHslider7;
	double fRec0[2];
	int iRec1[2];
	double fRec2[2];
	FAUSTFLOAT fVbargraph0;
	double fRec19[2];
	double fRec18[3];
	double fVec2[2];
	double fRec17[2];
	double fRec16[3];
	double fRec15[3];
	double fRec14[3];
	double fVec3[131072];
	FAUSTFLOAT fHslider8;
	double fRec20[2];
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	double fRec21[2];
	FAUSTFLOAT fHslider11;
	double fRec11[2];
	int iRec12[2];
	double fRec13[2];
	FAUSTFLOAT fVbargraph1;
	double fRec29[2];
	double fRec28[3];
	double fVec4[2];
	double fRec27[2];
	double fRec26[3];
	double fRec25[3];
	double fVec5[131072];
	FAUSTFLOAT fHslider12;
	double fRec30[2];
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	double fRec31[2];
	FAUSTFLOAT fHslider15;
	double fRec22[2];
	int iRec23[2];
	double fRec24[2];
	FAUSTFLOAT fVbargraph2;
	double fRec38[2];
	double fRec37[3];
	double fVec6[2];
	double fRec36[2];
	double fRec35[3];
	double fVec7[131072];
	FAUSTFLOAT fHslider16;
	double fRec39[2];
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	double fRec40[2];
	FAUSTFLOAT fHslider19;
	double fRec32[2];
	int iRec33[2];
	double fRec34[2];
	FAUSTFLOAT fVbargraph3;
	double fRec45[2];
	double fRec44[3];
	double fVec8[131072];
	FAUSTFLOAT fHslider20;
	double fRec46[2];
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	double fRec47[2];
	FAUSTFLOAT fHslider23;
	double fRec41[2];
	int iRec42[2];
	double fRec43[2];
	FAUSTFLOAT fVbargraph4;
	
 public:
	GxMbchor() {
	}
	
	GxMbchor(const GxMbchor&) = default;
	
	virtual ~GxMbchor() = default;
	
	GxMbchor& operator=(const GxMbchor&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Modulation");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbchor -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Multi Band Chorus");
		m->declare("filename", "gx-mbchor.dsp");
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
		m->declare("id", "mbchor");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Multi Band Chorus");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reducemaps.lib/author", "Yann Orlarey");
		m->declare("reducemaps.lib/copyright", "Grame and Yann Orlarey");
		m->declare("reducemaps.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("reducemaps.lib/name", "Reduce Library");
		m->declare("reducemaps.lib/version", "1.2.0");
		m->declare("shortname", "MB Chorus");
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
		GxMbchorSIG0* sig0 = newGxMbchorSIG0();
		sig0->instanceInitGxMbchorSIG0(sample_rate);
		sig0->fillGxMbchorSIG0(65536, ftbl0GxMbchorSIG0);
		deleteGxMbchorSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 1.0 / fConst0;
		fConst2 = 3.141592653589793 / fConst0;
		fConst3 = 0.016666666666666666 / fConst0;
		fConst4 = 0.5 * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(8e+01);
		fHslider1 = static_cast<FAUSTFLOAT>(2.1e+02);
		fHslider2 = static_cast<FAUSTFLOAT>(1.7e+03);
		fHslider3 = static_cast<FAUSTFLOAT>(5e+03);
		fHslider4 = static_cast<FAUSTFLOAT>(1.5e+02);
		fHslider5 = static_cast<FAUSTFLOAT>(0.1);
		fHslider6 = static_cast<FAUSTFLOAT>(0.1);
		fHslider7 = static_cast<FAUSTFLOAT>(0.5);
		fHslider8 = static_cast<FAUSTFLOAT>(1.2e+02);
		fHslider9 = static_cast<FAUSTFLOAT>(0.08);
		fHslider10 = static_cast<FAUSTFLOAT>(0.08);
		fHslider11 = static_cast<FAUSTFLOAT>(0.5);
		fHslider12 = static_cast<FAUSTFLOAT>(9e+01);
		fHslider13 = static_cast<FAUSTFLOAT>(0.06);
		fHslider14 = static_cast<FAUSTFLOAT>(0.06);
		fHslider15 = static_cast<FAUSTFLOAT>(0.5);
		fHslider16 = static_cast<FAUSTFLOAT>(6e+01);
		fHslider17 = static_cast<FAUSTFLOAT>(0.04);
		fHslider18 = static_cast<FAUSTFLOAT>(0.04);
		fHslider19 = static_cast<FAUSTFLOAT>(0.5);
		fHslider20 = static_cast<FAUSTFLOAT>(3e+01);
		fHslider21 = static_cast<FAUSTFLOAT>(0.02);
		fHslider22 = static_cast<FAUSTFLOAT>(0.02);
		fHslider23 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec7[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec6[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fRec5[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0;
		}
		IOTA0 = 0;
		for (int l6 = 0; l6 < 131072; l6 = faust_wrap_add(l6, 1)) {
			fVec1[l6] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec9[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec10[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec0[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			iRec1[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec2[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec19[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 3; l14 = faust_wrap_add(l14, 1)) {
			fRec18[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fVec2[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec17[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 3; l17 = faust_wrap_add(l17, 1)) {
			fRec16[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 3; l18 = faust_wrap_add(l18, 1)) {
			fRec15[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 3; l19 = faust_wrap_add(l19, 1)) {
			fRec14[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 131072; l20 = faust_wrap_add(l20, 1)) {
			fVec3[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec20[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec21[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec11[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			iRec12[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec13[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec29[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 3; l27 = faust_wrap_add(l27, 1)) {
			fRec28[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fVec4[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec27[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 3; l30 = faust_wrap_add(l30, 1)) {
			fRec26[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 3; l31 = faust_wrap_add(l31, 1)) {
			fRec25[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 131072; l32 = faust_wrap_add(l32, 1)) {
			fVec5[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec30[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec31[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec22[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			iRec23[l36] = 0;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec24[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fRec38[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 3; l39 = faust_wrap_add(l39, 1)) {
			fRec37[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fVec6[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec36[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 3; l42 = faust_wrap_add(l42, 1)) {
			fRec35[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 131072; l43 = faust_wrap_add(l43, 1)) {
			fVec7[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec39[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec40[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fRec32[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			iRec33[l47] = 0;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec34[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec45[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 3; l50 = faust_wrap_add(l50, 1)) {
			fRec44[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 131072; l51 = faust_wrap_add(l51, 1)) {
			fVec8[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec46[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fRec47[l53] = 0.0;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fRec41[l54] = 0.0;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			iRec42[l55] = 0;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fRec43[l56] = 0.0;
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
	
	virtual GxMbchor* clone() {
		return new GxMbchor(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Multi Band Chorus");
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
		ui_interface->addHorizontalSlider("delay1", &fHslider22, FAUSTFLOAT(0.02), FAUSTFLOAT(0.0), FAUSTFLOAT(0.2), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("delay2", &fHslider18, FAUSTFLOAT(0.04), FAUSTFLOAT(0.0), FAUSTFLOAT(0.2), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("delay3", &fHslider14, FAUSTFLOAT(0.06), FAUSTFLOAT(0.0), FAUSTFLOAT(0.2), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("delay4", &fHslider10, FAUSTFLOAT(0.08), FAUSTFLOAT(0.0), FAUSTFLOAT(0.2), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("delay5", &fHslider6, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(0.2), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("depth1", &fHslider21, FAUSTFLOAT(0.02), FAUSTFLOAT(0.01), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("depth2", &fHslider17, FAUSTFLOAT(0.04), FAUSTFLOAT(0.01), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("depth3", &fHslider13, FAUSTFLOAT(0.06), FAUSTFLOAT(0.01), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("depth4", &fHslider9, FAUSTFLOAT(0.08), FAUSTFLOAT(0.01), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("depth5", &fHslider5, FAUSTFLOAT(0.1), FAUSTFLOAT(0.01), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider20, "tooltip", "Beats per Minute");
		ui_interface->addHorizontalSlider("freq1", &fHslider20, FAUSTFLOAT(3e+01), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider16, "tooltip", "Beats per Minute");
		ui_interface->addHorizontalSlider("freq2", &fHslider16, FAUSTFLOAT(6e+01), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider12, "tooltip", "Beats per Minute");
		ui_interface->addHorizontalSlider("freq3", &fHslider12, FAUSTFLOAT(9e+01), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider8, "tooltip", "Beats per Minute");
		ui_interface->addHorizontalSlider("freq4", &fHslider8, FAUSTFLOAT(1.2e+02), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider4, "tooltip", "Beats per Minute");
		ui_interface->addHorizontalSlider("freq5", &fHslider4, FAUSTFLOAT(1.5e+02), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->addHorizontalSlider("level1", &fHslider23, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("level2", &fHslider19, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("level3", &fHslider15, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("level4", &fHslider11, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("level5", &fHslider7, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVbargraph4, "log", "");
		ui_interface->declare(&fVbargraph4, "nomidi", "");
		ui_interface->addVerticalBargraph("v1", &fVbargraph4, FAUSTFLOAT(0.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVbargraph3, "log", "");
		ui_interface->declare(&fVbargraph3, "nomidi", "");
		ui_interface->addVerticalBargraph("v2", &fVbargraph3, FAUSTFLOAT(0.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVbargraph2, "log", "");
		ui_interface->declare(&fVbargraph2, "nomidi", "");
		ui_interface->addVerticalBargraph("v3", &fVbargraph2, FAUSTFLOAT(0.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVbargraph1, "log", "");
		ui_interface->declare(&fVbargraph1, "nomidi", "");
		ui_interface->addVerticalBargraph("v4", &fVbargraph1, FAUSTFLOAT(0.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVbargraph0, "log", "");
		ui_interface->declare(&fVbargraph0, "nomidi", "");
		ui_interface->addVerticalBargraph("v5", &fVbargraph0, FAUSTFLOAT(0.0), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = std::tan(fConst2 * static_cast<double>(fHslider0));
		double fSlow1 = GxMbchor_faustpower2_f(fSlow0);
		double fSlow2 = 2.0 * (1.0 - 1.0 / fSlow1);
		double fSlow3 = 1.0 / fSlow0;
		double fSlow4 = 1.0 - fSlow3;
		double fSlow5 = 1.0 - fSlow4 / fSlow0;
		double fSlow6 = fSlow3 + 1.0;
		double fSlow7 = 1.0 / (fSlow6 / fSlow0 + 1.0);
		double fSlow8 = std::tan(fConst2 * static_cast<double>(fHslider1));
		double fSlow9 = GxMbchor_faustpower2_f(fSlow8);
		double fSlow10 = 2.0 * (1.0 - 1.0 / fSlow9);
		double fSlow11 = 1.0 / fSlow8;
		double fSlow12 = 1.0 - fSlow11;
		double fSlow13 = 1.0 - fSlow12 / fSlow8;
		double fSlow14 = fSlow11 + 1.0;
		double fSlow15 = 1.0 / (fSlow14 / fSlow8 + 1.0);
		double fSlow16 = std::tan(fConst2 * static_cast<double>(fHslider2));
		double fSlow17 = GxMbchor_faustpower2_f(fSlow16);
		double fSlow18 = 2.0 * (1.0 - 1.0 / fSlow17);
		double fSlow19 = 1.0 / fSlow16;
		double fSlow20 = 1.0 - fSlow19;
		double fSlow21 = 1.0 - fSlow20 / fSlow16;
		double fSlow22 = fSlow19 + 1.0;
		double fSlow23 = 1.0 / (fSlow22 / fSlow16 + 1.0);
		double fSlow24 = std::tan(fConst2 * static_cast<double>(fHslider3));
		double fSlow25 = GxMbchor_faustpower2_f(fSlow24);
		double fSlow26 = 2.0 * (1.0 - 1.0 / fSlow25);
		double fSlow27 = 1.0 / fSlow24;
		double fSlow28 = (fSlow27 + -1.0000000000000004) / fSlow24 + 1.0;
		double fSlow29 = (fSlow27 + 1.0000000000000004) / fSlow24 + 1.0;
		double fSlow30 = 1.0 / fSlow29;
		double fSlow31 = 1.0 - fSlow27;
		double fSlow32 = 1.0 / (fSlow27 + 1.0);
		double fSlow33 = 1.0 / (fSlow25 * fSlow29);
		double fSlow34 = fConst3 * static_cast<double>(fHslider4);
		double fSlow35 = 0.1 * static_cast<double>(fHslider5);
		double fSlow36 = 0.0010000000000000009 * static_cast<double>(fHslider6);
		double fSlow37 = static_cast<double>(fHslider7);
		double fSlow38 = (fSlow19 + -1.0000000000000004) / fSlow16 + 1.0;
		double fSlow39 = (fSlow19 + 1.0000000000000004) / fSlow16 + 1.0;
		double fSlow40 = 1.0 / fSlow39;
		double fSlow41 = 1.0 / fSlow22;
		double fSlow42 = 1.0 / (fSlow17 * fSlow39);
		double fSlow43 = fConst3 * static_cast<double>(fHslider8);
		double fSlow44 = 0.1 * static_cast<double>(fHslider9);
		double fSlow45 = 0.0010000000000000009 * static_cast<double>(fHslider10);
		double fSlow46 = static_cast<double>(fHslider11);
		double fSlow47 = (fSlow11 + -1.0000000000000004) / fSlow8 + 1.0;
		double fSlow48 = (fSlow11 + 1.0000000000000004) / fSlow8 + 1.0;
		double fSlow49 = 1.0 / fSlow48;
		double fSlow50 = 1.0 / fSlow14;
		double fSlow51 = 1.0 / (fSlow9 * fSlow48);
		double fSlow52 = fConst3 * static_cast<double>(fHslider12);
		double fSlow53 = 0.1 * static_cast<double>(fHslider13);
		double fSlow54 = 0.0010000000000000009 * static_cast<double>(fHslider14);
		double fSlow55 = static_cast<double>(fHslider15);
		double fSlow56 = (fSlow3 + -1.0000000000000004) / fSlow0 + 1.0;
		double fSlow57 = (fSlow3 + 1.0000000000000004) / fSlow0 + 1.0;
		double fSlow58 = 1.0 / fSlow57;
		double fSlow59 = 1.0 / fSlow6;
		double fSlow60 = 1.0 / (fSlow1 * fSlow57);
		double fSlow61 = fConst3 * static_cast<double>(fHslider16);
		double fSlow62 = 0.1 * static_cast<double>(fHslider17);
		double fSlow63 = 0.0010000000000000009 * static_cast<double>(fHslider18);
		double fSlow64 = static_cast<double>(fHslider19);
		double fSlow65 = fConst3 * static_cast<double>(fHslider20);
		double fSlow66 = 0.1 * static_cast<double>(fHslider21);
		double fSlow67 = 0.0010000000000000009 * static_cast<double>(fHslider22);
		double fSlow68 = static_cast<double>(fHslider23);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			int iTemp0 = iRec1[1] < 4096;
			double fTemp1 = fSlow2 * fRec3[1];
			double fTemp2 = fSlow10 * fRec4[1];
			double fTemp3 = fSlow18 * fRec5[1];
			double fTemp4 = static_cast<double>(input0[i0]);
			fVec0[0] = fTemp4;
			fRec7[0] = -(fSlow32 * (fSlow31 * fRec7[1] - fSlow27 * (fTemp4 - fVec0[1])));
			fRec6[0] = fRec7[0] - fSlow30 * (fSlow28 * fRec6[2] + fSlow26 * fRec6[1]);
			fRec5[0] = fSlow33 * (fRec6[2] + (fRec6[0] - 2.0 * fRec6[1])) - fSlow23 * (fSlow21 * fRec5[2] + fTemp3);
			fRec4[0] = fRec5[2] + fSlow23 * (fTemp3 + fSlow21 * fRec5[0]) - fSlow15 * (fSlow13 * fRec4[2] + fTemp2);
			fRec3[0] = fRec4[2] + fSlow15 * (fTemp2 + fSlow13 * fRec4[0]) - fSlow7 * (fSlow5 * fRec3[2] + fTemp1);
			double fTemp5 = fRec3[2] + fSlow7 * (fTemp1 + fSlow5 * fRec3[0]);
			fVec1[IOTA0 & 131071] = fTemp5;
			fRec9[0] = fSlow34 + (fRec9[1] - std::floor(fSlow34 + fRec9[1]));
			double fTemp6 = 65536.0 * (fRec9[0] - std::floor(fRec9[0]));
			double fTemp7 = std::floor(fTemp6);
			int iTemp8 = static_cast<int>(fTemp7);
			fRec10[0] = fSlow36 + 0.999 * fRec10[1];
			double fTemp9 = fConst4 * fRec10[0] * (fSlow35 * ((fTemp7 + (1.0 - fTemp6)) * ftbl0GxMbchorSIG0[iTemp8 & 65535] + (fTemp6 - fTemp7) * ftbl0GxMbchorSIG0[(faust_wrap_add(iTemp8, 1)) & 65535]) + 1.0);
			int iTemp10 = static_cast<int>(fTemp9);
			double fTemp11 = std::floor(fTemp9);
			double fTemp12 = fSlow37 * (fTemp5 + fSlow37 * (fVec1[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp10)))) & 131071] * (fTemp11 + (1.0 - fTemp9)) + (fTemp9 - fTemp11) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp10, 1))))) & 131071]));
			double fTemp13 = std::max<double>(fConst1, std::fabs(fTemp12));
			fRec0[0] = ((iTemp0) ? fTemp13 + fRec0[1] : fTemp13);
			iRec1[0] = ((iTemp0) ? faust_wrap_add(iRec1[1], 1) : 1);
			fRec2[0] = ((iTemp0) ? fRec2[1] : 0.000244140625 * fRec0[1]);
			fVbargraph0 = static_cast<FAUSTFLOAT>(fRec2[0]);
			int iTemp14 = iRec12[1] < 4096;
			double fTemp15 = fSlow2 * fRec14[1];
			double fTemp16 = fSlow10 * fRec15[1];
			fRec19[0] = -(fSlow32 * (fSlow31 * fRec19[1] - (fTemp4 + fVec0[1])));
			fRec18[0] = fRec19[0] - fSlow30 * (fSlow28 * fRec18[2] + fSlow26 * fRec18[1]);
			double fTemp17 = fSlow30 * (fRec18[2] + fRec18[0] + 2.0 * fRec18[1]);
			fVec2[0] = fTemp17;
			fRec17[0] = -(fSlow41 * (fSlow20 * fRec17[1] - fSlow19 * (fTemp17 - fVec2[1])));
			fRec16[0] = fRec17[0] - fSlow40 * (fSlow38 * fRec16[2] + fSlow18 * fRec16[1]);
			fRec15[0] = fSlow42 * (fRec16[2] + (fRec16[0] - 2.0 * fRec16[1])) - fSlow15 * (fSlow13 * fRec15[2] + fTemp16);
			fRec14[0] = fRec15[2] + fSlow15 * (fTemp16 + fSlow13 * fRec15[0]) - fSlow7 * (fSlow5 * fRec14[2] + fTemp15);
			double fTemp18 = fRec14[2] + fSlow7 * (fTemp15 + fSlow5 * fRec14[0]);
			fVec3[IOTA0 & 131071] = fTemp18;
			fRec20[0] = fSlow43 + (fRec20[1] - std::floor(fSlow43 + fRec20[1]));
			double fTemp19 = 65536.0 * (fRec20[0] - std::floor(fRec20[0]));
			double fTemp20 = std::floor(fTemp19);
			int iTemp21 = static_cast<int>(fTemp20);
			fRec21[0] = fSlow45 + 0.999 * fRec21[1];
			double fTemp22 = fConst4 * fRec21[0] * (fSlow44 * ((fTemp20 + (1.0 - fTemp19)) * ftbl0GxMbchorSIG0[iTemp21 & 65535] + (fTemp19 - fTemp20) * ftbl0GxMbchorSIG0[(faust_wrap_add(iTemp21, 1)) & 65535]) + 1.0);
			int iTemp23 = static_cast<int>(fTemp22);
			double fTemp24 = std::floor(fTemp22);
			double fTemp25 = fSlow46 * (fTemp18 + fSlow46 * (fVec3[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp23)))) & 131071] * (fTemp24 + (1.0 - fTemp22)) + (fTemp22 - fTemp24) * fVec3[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp23, 1))))) & 131071]));
			double fTemp26 = std::max<double>(fConst1, std::fabs(fTemp25));
			fRec11[0] = ((iTemp14) ? fTemp26 + fRec11[1] : fTemp26);
			iRec12[0] = ((iTemp14) ? faust_wrap_add(iRec12[1], 1) : 1);
			fRec13[0] = ((iTemp14) ? fRec13[1] : 0.000244140625 * fRec11[1]);
			fVbargraph1 = static_cast<FAUSTFLOAT>(fRec13[0]);
			int iTemp27 = iRec23[1] < 4096;
			double fTemp28 = fSlow2 * fRec25[1];
			fRec29[0] = -(fSlow41 * (fSlow20 * fRec29[1] - (fTemp17 + fVec2[1])));
			fRec28[0] = fRec29[0] - fSlow40 * (fSlow38 * fRec28[2] + fSlow18 * fRec28[1]);
			double fTemp29 = fSlow40 * (fRec28[2] + fRec28[0] + 2.0 * fRec28[1]);
			fVec4[0] = fTemp29;
			fRec27[0] = -(fSlow50 * (fSlow12 * fRec27[1] - fSlow11 * (fTemp29 - fVec4[1])));
			fRec26[0] = fRec27[0] - fSlow49 * (fSlow47 * fRec26[2] + fSlow10 * fRec26[1]);
			fRec25[0] = fSlow51 * (fRec26[2] + (fRec26[0] - 2.0 * fRec26[1])) - fSlow7 * (fSlow5 * fRec25[2] + fTemp28);
			double fTemp30 = fRec25[2] + fSlow7 * (fTemp28 + fSlow5 * fRec25[0]);
			fVec5[IOTA0 & 131071] = fTemp30;
			fRec30[0] = fSlow52 + (fRec30[1] - std::floor(fSlow52 + fRec30[1]));
			double fTemp31 = 65536.0 * (fRec30[0] - std::floor(fRec30[0]));
			double fTemp32 = std::floor(fTemp31);
			int iTemp33 = static_cast<int>(fTemp32);
			fRec31[0] = fSlow54 + 0.999 * fRec31[1];
			double fTemp34 = fConst4 * fRec31[0] * (fSlow53 * ((fTemp32 + (1.0 - fTemp31)) * ftbl0GxMbchorSIG0[iTemp33 & 65535] + (fTemp31 - fTemp32) * ftbl0GxMbchorSIG0[(faust_wrap_add(iTemp33, 1)) & 65535]) + 1.0);
			int iTemp35 = static_cast<int>(fTemp34);
			double fTemp36 = std::floor(fTemp34);
			double fTemp37 = fSlow55 * (fTemp30 + fSlow55 * (fVec5[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp35)))) & 131071] * (fTemp36 + (1.0 - fTemp34)) + (fTemp34 - fTemp36) * fVec5[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp35, 1))))) & 131071]));
			double fTemp38 = std::max<double>(fConst1, std::fabs(fTemp37));
			fRec22[0] = ((iTemp27) ? fTemp38 + fRec22[1] : fTemp38);
			iRec23[0] = ((iTemp27) ? faust_wrap_add(iRec23[1], 1) : 1);
			fRec24[0] = ((iTemp27) ? fRec24[1] : 0.000244140625 * fRec22[1]);
			fVbargraph2 = static_cast<FAUSTFLOAT>(fRec24[0]);
			int iTemp39 = iRec33[1] < 4096;
			fRec38[0] = -(fSlow50 * (fSlow12 * fRec38[1] - (fTemp29 + fVec4[1])));
			fRec37[0] = fRec38[0] - fSlow49 * (fSlow47 * fRec37[2] + fSlow10 * fRec37[1]);
			double fTemp40 = fSlow49 * (fRec37[2] + fRec37[0] + 2.0 * fRec37[1]);
			fVec6[0] = fTemp40;
			fRec36[0] = -(fSlow59 * (fSlow4 * fRec36[1] - fSlow3 * (fTemp40 - fVec6[1])));
			fRec35[0] = fRec36[0] - fSlow58 * (fSlow56 * fRec35[2] + fSlow2 * fRec35[1]);
			double fTemp41 = fSlow60 * (fRec35[2] + (fRec35[0] - 2.0 * fRec35[1]));
			fVec7[IOTA0 & 131071] = fTemp41;
			fRec39[0] = fSlow61 + (fRec39[1] - std::floor(fSlow61 + fRec39[1]));
			double fTemp42 = 65536.0 * (fRec39[0] - std::floor(fRec39[0]));
			double fTemp43 = std::floor(fTemp42);
			int iTemp44 = static_cast<int>(fTemp43);
			fRec40[0] = fSlow63 + 0.999 * fRec40[1];
			double fTemp45 = fConst4 * fRec40[0] * (fSlow62 * ((fTemp43 + (1.0 - fTemp42)) * ftbl0GxMbchorSIG0[iTemp44 & 65535] + (fTemp42 - fTemp43) * ftbl0GxMbchorSIG0[(faust_wrap_add(iTemp44, 1)) & 65535]) + 1.0);
			int iTemp46 = static_cast<int>(fTemp45);
			double fTemp47 = std::floor(fTemp45);
			double fTemp48 = fSlow64 * (fTemp41 + fSlow64 * (fVec7[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp46)))) & 131071] * (fTemp47 + (1.0 - fTemp45)) + (fTemp45 - fTemp47) * fVec7[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp46, 1))))) & 131071]));
			double fTemp49 = std::max<double>(fConst1, std::fabs(fTemp48));
			fRec32[0] = ((iTemp39) ? fTemp49 + fRec32[1] : fTemp49);
			iRec33[0] = ((iTemp39) ? faust_wrap_add(iRec33[1], 1) : 1);
			fRec34[0] = ((iTemp39) ? fRec34[1] : 0.000244140625 * fRec32[1]);
			fVbargraph3 = static_cast<FAUSTFLOAT>(fRec34[0]);
			int iTemp50 = iRec42[1] < 4096;
			fRec45[0] = -(fSlow59 * (fSlow4 * fRec45[1] - (fTemp40 + fVec6[1])));
			fRec44[0] = fRec45[0] - fSlow58 * (fSlow56 * fRec44[2] + fSlow2 * fRec44[1]);
			double fTemp51 = fSlow58 * (fRec44[2] + fRec44[0] + 2.0 * fRec44[1]);
			fVec8[IOTA0 & 131071] = fTemp51;
			fRec46[0] = fSlow65 + (fRec46[1] - std::floor(fSlow65 + fRec46[1]));
			double fTemp52 = 65536.0 * (fRec46[0] - std::floor(fRec46[0]));
			double fTemp53 = std::floor(fTemp52);
			int iTemp54 = static_cast<int>(fTemp53);
			fRec47[0] = fSlow67 + 0.999 * fRec47[1];
			double fTemp55 = fConst4 * fRec47[0] * (fSlow66 * ((fTemp53 + (1.0 - fTemp52)) * ftbl0GxMbchorSIG0[iTemp54 & 65535] + (fTemp52 - fTemp53) * ftbl0GxMbchorSIG0[(faust_wrap_add(iTemp54, 1)) & 65535]) + 1.0);
			int iTemp56 = static_cast<int>(fTemp55);
			double fTemp57 = std::floor(fTemp55);
			double fTemp58 = fSlow68 * (fTemp51 + fSlow68 * (fVec8[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp56)))) & 131071] * (fTemp57 + (1.0 - fTemp55)) + (fTemp55 - fTemp57) * fVec8[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp56, 1))))) & 131071]));
			double fTemp59 = std::max<double>(fConst1, std::fabs(fTemp58));
			fRec41[0] = ((iTemp50) ? fTemp59 + fRec41[1] : fTemp59);
			iRec42[0] = ((iTemp50) ? faust_wrap_add(iRec42[1], 1) : 1);
			fRec43[0] = ((iTemp50) ? fRec43[1] : 0.000244140625 * fRec41[1]);
			fVbargraph4 = static_cast<FAUSTFLOAT>(fRec43[0]);
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp58 + fTemp48 + fTemp37 + fTemp25 + fTemp4 + fTemp12);
			fVec0[1] = fVec0[0];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec0[1] = fRec0[0];
			iRec1[1] = iRec1[0];
			fRec2[1] = fRec2[0];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fVec2[1] = fVec2[0];
			fRec17[1] = fRec17[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec11[1] = fRec11[0];
			iRec12[1] = iRec12[0];
			fRec13[1] = fRec13[0];
			fRec29[1] = fRec29[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fVec4[1] = fVec4[0];
			fRec27[1] = fRec27[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec30[1] = fRec30[0];
			fRec31[1] = fRec31[0];
			fRec22[1] = fRec22[0];
			iRec23[1] = iRec23[0];
			fRec24[1] = fRec24[0];
			fRec38[1] = fRec38[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fVec6[1] = fVec6[0];
			fRec36[1] = fRec36[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec39[1] = fRec39[0];
			fRec40[1] = fRec40[0];
			fRec32[1] = fRec32[0];
			iRec33[1] = iRec33[0];
			fRec34[1] = fRec34[0];
			fRec45[1] = fRec45[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec46[1] = fRec46[0];
			fRec47[1] = fRec47[0];
			fRec41[1] = fRec41[0];
			iRec42[1] = iRec42[0];
			fRec43[1] = fRec43[0];
		}
	}

};

#endif
