/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Zita Rev1"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxZitaRev1 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxZitaRev1_H__
#define  __GxZitaRev1_H__

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
#define FAUSTCLASS GxZitaRev1
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

static double GxZitaRev1_faustpower2_f(double value) {
	return value * value;
}

class GxZitaRev1 : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	int fSampleRate;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fVslider4;
	double fConst2;
	double fConst3;
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT fVslider6;
	double fConst4;
	double fRec13[2];
	FAUSTFLOAT fVslider7;
	double fRec12[2];
	int IOTA0;
	double fVec0[16384];
	double fConst5;
	int iConst6;
	double fVec1[16384];
	FAUSTFLOAT fVslider8;
	double fConst7;
	double fVec2[4096];
	int iConst8;
	double fRec10[2];
	double fConst9;
	double fConst10;
	double fRec17[2];
	double fRec16[2];
	double fVec3[16384];
	double fConst11;
	int iConst12;
	double fVec4[2048];
	int iConst13;
	double fRec14[2];
	double fConst14;
	double fConst15;
	double fRec21[2];
	double fRec20[2];
	double fVec5[16384];
	double fConst16;
	int iConst17;
	double fVec6[4096];
	int iConst18;
	double fRec18[2];
	double fConst19;
	double fConst20;
	double fRec25[2];
	double fRec24[2];
	double fVec7[16384];
	double fConst21;
	int iConst22;
	double fVec8[2048];
	int iConst23;
	double fRec22[2];
	double fConst24;
	double fConst25;
	double fRec29[2];
	double fRec28[2];
	double fVec9[32768];
	double fConst26;
	int iConst27;
	double fVec10[4096];
	int iConst28;
	double fRec26[2];
	double fConst29;
	double fConst30;
	double fRec33[2];
	double fRec32[2];
	double fVec11[16384];
	double fConst31;
	int iConst32;
	double fVec12[4096];
	int iConst33;
	double fRec30[2];
	double fConst34;
	double fConst35;
	double fRec37[2];
	double fRec36[2];
	double fVec13[32768];
	double fConst36;
	int iConst37;
	double fVec14[4096];
	int iConst38;
	double fRec34[2];
	double fConst39;
	double fConst40;
	double fRec41[2];
	double fRec40[2];
	double fVec15[32768];
	double fConst41;
	int iConst42;
	double fVec16[2048];
	int iConst43;
	double fRec38[2];
	double fRec2[3];
	double fRec3[3];
	double fRec4[3];
	double fRec5[3];
	double fRec6[3];
	double fRec7[3];
	double fRec8[3];
	double fRec9[3];
	double fRec1[3];
	double fRec0[3];
	FAUSTFLOAT fVslider9;
	double fRec42[2];
	double fRec44[3];
	double fRec43[3];
	FAUSTFLOAT fVslider10;
	double fRec45[2];
	
 public:
	GxZitaRev1() {
	}
	
	GxZitaRev1(const GxZitaRev1&) = default;
	
	virtual ~GxZitaRev1() = default;
	
	GxZitaRev1& operator=(const GxZitaRev1&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Reverb");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxZitaRev1 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-zita-rev1.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/peak_eq_rm:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq_rm:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq_rm:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "zita_rev1");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Zita Rev1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.5.1");
		m->declare("routes.lib/hadamard:author", "Remy Muller, revised by Romain Michon");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
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
		fConst1 = 6.283185307179586 / fConst0;
		fConst2 = std::floor(0.174713 * fConst0 + 0.5);
		fConst3 = 6.907755278982138 * (fConst2 / fConst0);
		fConst4 = 3.141592653589793 / fConst0;
		fConst5 = std::floor(0.022904 * fConst0 + 0.5);
		iConst6 = static_cast<int>(std::min<double>(8192.0, std::max<double>(0.0, fConst2 - fConst5)));
		fConst7 = 0.001 * fConst0;
		iConst8 = static_cast<int>(std::min<double>(2048.0, std::max<double>(0.0, fConst5 + -1.0)));
		fConst9 = std::floor(0.153129 * fConst0 + 0.5);
		fConst10 = 6.907755278982138 * (fConst9 / fConst0);
		fConst11 = std::floor(0.020346 * fConst0 + 0.5);
		iConst12 = static_cast<int>(std::min<double>(8192.0, std::max<double>(0.0, fConst9 - fConst11)));
		iConst13 = static_cast<int>(std::min<double>(1024.0, std::max<double>(0.0, fConst11 + -1.0)));
		fConst14 = std::floor(0.127837 * fConst0 + 0.5);
		fConst15 = 6.907755278982138 * (fConst14 / fConst0);
		fConst16 = std::floor(0.031604 * fConst0 + 0.5);
		iConst17 = static_cast<int>(std::min<double>(8192.0, std::max<double>(0.0, fConst14 - fConst16)));
		iConst18 = static_cast<int>(std::min<double>(2048.0, std::max<double>(0.0, fConst16 + -1.0)));
		fConst19 = std::floor(0.125 * fConst0 + 0.5);
		fConst20 = 6.907755278982138 * (fConst19 / fConst0);
		fConst21 = std::floor(0.013458 * fConst0 + 0.5);
		iConst22 = static_cast<int>(std::min<double>(8192.0, std::max<double>(0.0, fConst19 - fConst21)));
		iConst23 = static_cast<int>(std::min<double>(1024.0, std::max<double>(0.0, fConst21 + -1.0)));
		fConst24 = std::floor(0.210389 * fConst0 + 0.5);
		fConst25 = 6.907755278982138 * (fConst24 / fConst0);
		fConst26 = std::floor(0.024421 * fConst0 + 0.5);
		iConst27 = static_cast<int>(std::min<double>(16384.0, std::max<double>(0.0, fConst24 - fConst26)));
		iConst28 = static_cast<int>(std::min<double>(2048.0, std::max<double>(0.0, fConst26 + -1.0)));
		fConst29 = std::floor(0.192303 * fConst0 + 0.5);
		fConst30 = 6.907755278982138 * (fConst29 / fConst0);
		fConst31 = std::floor(0.029291 * fConst0 + 0.5);
		iConst32 = static_cast<int>(std::min<double>(8192.0, std::max<double>(0.0, fConst29 - fConst31)));
		iConst33 = static_cast<int>(std::min<double>(2048.0, std::max<double>(0.0, fConst31 + -1.0)));
		fConst34 = std::floor(0.256891 * fConst0 + 0.5);
		fConst35 = 6.907755278982138 * (fConst34 / fConst0);
		fConst36 = std::floor(0.027333 * fConst0 + 0.5);
		iConst37 = static_cast<int>(std::min<double>(16384.0, std::max<double>(0.0, fConst34 - fConst36)));
		iConst38 = static_cast<int>(std::min<double>(2048.0, std::max<double>(0.0, fConst36 + -1.0)));
		fConst39 = std::floor(0.219991 * fConst0 + 0.5);
		fConst40 = 6.907755278982138 * (fConst39 / fConst0);
		fConst41 = std::floor(0.019123 * fConst0 + 0.5);
		iConst42 = static_cast<int>(std::min<double>(16384.0, std::max<double>(0.0, fConst39 - fConst41)));
		iConst43 = static_cast<int>(std::min<double>(1024.0, std::max<double>(0.0, fConst41 + -1.0)));
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider1 = static_cast<FAUSTFLOAT>(1.5e+03);
		fVslider2 = static_cast<FAUSTFLOAT>(0.0);
		fVslider3 = static_cast<FAUSTFLOAT>(315.0);
		fVslider4 = static_cast<FAUSTFLOAT>(2.0);
		fVslider5 = static_cast<FAUSTFLOAT>(6e+03);
		fVslider6 = static_cast<FAUSTFLOAT>(2e+02);
		fVslider7 = static_cast<FAUSTFLOAT>(3.0);
		fVslider8 = static_cast<FAUSTFLOAT>(6e+01);
		fVslider9 = static_cast<FAUSTFLOAT>(0.0);
		fVslider10 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec13[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec12[l1] = 0.0;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 16384; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 16384; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 4096; l4 = faust_wrap_add(l4, 1)) {
			fVec2[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec10[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec17[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec16[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 16384; l8 = faust_wrap_add(l8, 1)) {
			fVec3[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2048; l9 = faust_wrap_add(l9, 1)) {
			fVec4[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec14[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec21[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec20[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 16384; l13 = faust_wrap_add(l13, 1)) {
			fVec5[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 4096; l14 = faust_wrap_add(l14, 1)) {
			fVec6[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec18[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec25[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec24[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 16384; l18 = faust_wrap_add(l18, 1)) {
			fVec7[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2048; l19 = faust_wrap_add(l19, 1)) {
			fVec8[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec22[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec29[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec28[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 32768; l23 = faust_wrap_add(l23, 1)) {
			fVec9[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 4096; l24 = faust_wrap_add(l24, 1)) {
			fVec10[l24] = 0.0;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec26[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec33[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec32[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 16384; l28 = faust_wrap_add(l28, 1)) {
			fVec11[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 4096; l29 = faust_wrap_add(l29, 1)) {
			fVec12[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec30[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec37[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec36[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 32768; l33 = faust_wrap_add(l33, 1)) {
			fVec13[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 4096; l34 = faust_wrap_add(l34, 1)) {
			fVec14[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec34[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec41[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec40[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 32768; l38 = faust_wrap_add(l38, 1)) {
			fVec15[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 2048; l39 = faust_wrap_add(l39, 1)) {
			fVec16[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec38[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 3; l41 = faust_wrap_add(l41, 1)) {
			fRec2[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 3; l42 = faust_wrap_add(l42, 1)) {
			fRec3[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 3; l43 = faust_wrap_add(l43, 1)) {
			fRec4[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 3; l44 = faust_wrap_add(l44, 1)) {
			fRec5[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 3; l45 = faust_wrap_add(l45, 1)) {
			fRec6[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 3; l46 = faust_wrap_add(l46, 1)) {
			fRec7[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 3; l47 = faust_wrap_add(l47, 1)) {
			fRec8[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 3; l48 = faust_wrap_add(l48, 1)) {
			fRec9[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 3; l49 = faust_wrap_add(l49, 1)) {
			fRec1[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 3; l50 = faust_wrap_add(l50, 1)) {
			fRec0[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fRec42[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 3; l52 = faust_wrap_add(l52, 1)) {
			fRec44[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 3; l53 = faust_wrap_add(l53, 1)) {
			fRec43[l53] = 0.0;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fRec45[l54] = 0.0;
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
	
	virtual GxZitaRev1* clone() {
		return new GxZitaRev1(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->declare(0, "name", "Zita_Rev1");
		ui_interface->declare(0, "tooltip", "~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER ALLPASS-COMB REVERBERATOR (8x8). See Faust's effect.lib for documentation and references");
		ui_interface->openHorizontalBox("zita_rev1");
		ui_interface->declare(0, "name", "Decay Times in Bands");
		ui_interface->openHorizontalBox("decay_times");
		ui_interface->declare(&fVslider5, "log", "");
		ui_interface->declare(&fVslider5, "name", "HF Damp");
		ui_interface->declare(&fVslider5, "style", "knob");
		ui_interface->declare(&fVslider5, "tooltip", "Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60");
		ui_interface->declare(&fVslider5, "unit", "Hz");
		ui_interface->addVerticalSlider("hf_damping", &fVslider5, FAUSTFLOAT(6e+03), FAUSTFLOAT(1.5e+03), FAUSTFLOAT(2.352e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fVslider6, "log", "");
		ui_interface->declare(&fVslider6, "name", "Freq X");
		ui_interface->declare(&fVslider6, "style", "knob");
		ui_interface->declare(&fVslider6, "tooltip", "Crossover frequency (Hz) separating low and middle frequencies");
		ui_interface->declare(&fVslider6, "unit", "Hz");
		ui_interface->addVerticalSlider("lf_x", &fVslider6, FAUSTFLOAT(2e+02), FAUSTFLOAT(5e+01), FAUSTFLOAT(1e+03), FAUSTFLOAT(1.08));
		ui_interface->declare(&fVslider7, "log", "");
		ui_interface->declare(&fVslider7, "name", "Low");
		ui_interface->declare(&fVslider7, "style", "knob");
		ui_interface->declare(&fVslider7, "tooltip", "T60 = time (in seconds) to decay 60dB in low-frequency band");
		ui_interface->declare(&fVslider7, "unit", "s");
		ui_interface->addVerticalSlider("low_rt60", &fVslider7, FAUSTFLOAT(3.0), FAUSTFLOAT(1.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.08));
		ui_interface->declare(&fVslider4, "log", "");
		ui_interface->declare(&fVslider4, "name", "Mid");
		ui_interface->declare(&fVslider4, "style", "knob");
		ui_interface->declare(&fVslider4, "tooltip", "T60 = time (in seconds) to decay 60dB in middle band");
		ui_interface->declare(&fVslider4, "unit", "s");
		ui_interface->addVerticalSlider("mid_rt60", &fVslider4, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.08));
		ui_interface->closeBox();
		ui_interface->declare(0, "name", "RM Peaking Equalizer 1");
		ui_interface->openHorizontalBox("equalizer1");
		ui_interface->declare(&fVslider3, "log", "");
		ui_interface->declare(&fVslider3, "name", "Freq");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider3, "unit", "Hz");
		ui_interface->addVerticalSlider("eq1_freq", &fVslider3, FAUSTFLOAT(315.0), FAUSTFLOAT(4e+01), FAUSTFLOAT(2.5e+03), FAUSTFLOAT(1.08));
		ui_interface->declare(&fVslider2, "name", "Level");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "Peak level in dB of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider2, "unit", "dB");
		ui_interface->addVerticalSlider("eq1_level", &fVslider2, FAUSTFLOAT(0.0), FAUSTFLOAT(-15.0), FAUSTFLOAT(15.0), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
		ui_interface->declare(0, "name", "RM Peaking Equalizer 2");
		ui_interface->openHorizontalBox("equalizer2");
		ui_interface->declare(&fVslider1, "log", "");
		ui_interface->declare(&fVslider1, "name", "Freq");
		ui_interface->declare(&fVslider1, "style", "knob");
		ui_interface->declare(&fVslider1, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider1, "unit", "Hz");
		ui_interface->addVerticalSlider("eq2_freq", &fVslider1, FAUSTFLOAT(1.5e+03), FAUSTFLOAT(1.6e+02), FAUSTFLOAT(1e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fVslider0, "name", "Level");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->declare(&fVslider0, "tooltip", "Peak level in dB of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider0, "unit", "dB");
		ui_interface->addVerticalSlider("eq2_level", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(-15.0), FAUSTFLOAT(15.0), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
		ui_interface->declare(0, "name", "Input");
		ui_interface->openHorizontalBox("input");
		ui_interface->declare(&fVslider8, "name", "Pre Delay");
		ui_interface->declare(&fVslider8, "style", "knob");
		ui_interface->declare(&fVslider8, "tooltip", "Delay in ms before reverberation begins");
		ui_interface->declare(&fVslider8, "unit", "ms");
		ui_interface->addVerticalSlider("in_delay", &fVslider8, FAUSTFLOAT(6e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
		ui_interface->declare(0, "name", "Output");
		ui_interface->openHorizontalBox("output");
		ui_interface->declare(&fVslider9, "name", "Dry/Wet");
		ui_interface->declare(&fVslider9, "style", "knob");
		ui_interface->declare(&fVslider9, "tooltip", "-1 = dry, 1 = wet");
		ui_interface->addVerticalSlider("dry_wet_mix", &fVslider9, FAUSTFLOAT(0.0), FAUSTFLOAT(-1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider10, "name", "Level");
		ui_interface->declare(&fVslider10, "style", "knob");
		ui_interface->declare(&fVslider10, "tooltip", "Output scale factor");
		ui_interface->declare(&fVslider10, "unit", "dB");
		ui_interface->addVerticalSlider("level", &fVslider10, FAUSTFLOAT(0.0), FAUSTFLOAT(-7e+01), FAUSTFLOAT(4e+01), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = std::pow(1e+01, 0.05 * static_cast<double>(fVslider0));
		double fSlow1 = static_cast<double>(fVslider1);
		double fSlow2 = fConst1 * (fSlow1 / std::sqrt(fSlow0));
		double fSlow3 = (1.0 - fSlow2) / (fSlow2 + 1.0);
		double fSlow4 = std::cos(fConst1 * fSlow1) * (fSlow3 + 1.0);
		double fSlow5 = std::pow(1e+01, 0.05 * static_cast<double>(fVslider2));
		double fSlow6 = static_cast<double>(fVslider3);
		double fSlow7 = fConst1 * (fSlow6 / std::sqrt(fSlow5));
		double fSlow8 = (1.0 - fSlow7) / (fSlow7 + 1.0);
		double fSlow9 = std::cos(fConst1 * fSlow6) * (fSlow8 + 1.0);
		double fSlow10 = static_cast<double>(fVslider4);
		double fSlow11 = std::exp(-(fConst3 / fSlow10));
		double fSlow12 = GxZitaRev1_faustpower2_f(fSlow11);
		double fSlow13 = 1.0 - fSlow12;
		double fSlow14 = std::cos(fConst1 * static_cast<double>(fVslider5));
		double fSlow15 = 1.0 - fSlow14 * fSlow12;
		double fSlow16 = std::sqrt(std::max<double>(0.0, GxZitaRev1_faustpower2_f(fSlow15) / GxZitaRev1_faustpower2_f(fSlow13) + -1.0));
		double fSlow17 = fSlow15 / fSlow13;
		double fSlow18 = fSlow17 - fSlow16;
		double fSlow19 = 1.0 / std::tan(fConst4 * static_cast<double>(fVslider6));
		double fSlow20 = 1.0 - fSlow19;
		double fSlow21 = 1.0 / (fSlow19 + 1.0);
		double fSlow22 = static_cast<double>(fVslider7);
		double fSlow23 = std::exp(-(fConst3 / fSlow22)) / fSlow11 + -1.0;
		double fSlow24 = fSlow11 * (fSlow16 + (1.0 - fSlow17));
		int iSlow25 = static_cast<int>(std::min<double>(8192.0, std::max<double>(0.0, fConst7 * static_cast<double>(fVslider8))));
		double fSlow26 = std::exp(-(fConst10 / fSlow10));
		double fSlow27 = GxZitaRev1_faustpower2_f(fSlow26);
		double fSlow28 = 1.0 - fSlow27;
		double fSlow29 = 1.0 - fSlow27 * fSlow14;
		double fSlow30 = std::sqrt(std::max<double>(0.0, GxZitaRev1_faustpower2_f(fSlow29) / GxZitaRev1_faustpower2_f(fSlow28) + -1.0));
		double fSlow31 = fSlow29 / fSlow28;
		double fSlow32 = fSlow31 - fSlow30;
		double fSlow33 = std::exp(-(fConst10 / fSlow22)) / fSlow26 + -1.0;
		double fSlow34 = fSlow26 * (fSlow30 + (1.0 - fSlow31));
		double fSlow35 = std::exp(-(fConst15 / fSlow10));
		double fSlow36 = GxZitaRev1_faustpower2_f(fSlow35);
		double fSlow37 = 1.0 - fSlow36;
		double fSlow38 = 1.0 - fSlow14 * fSlow36;
		double fSlow39 = std::sqrt(std::max<double>(0.0, GxZitaRev1_faustpower2_f(fSlow38) / GxZitaRev1_faustpower2_f(fSlow37) + -1.0));
		double fSlow40 = fSlow38 / fSlow37;
		double fSlow41 = fSlow40 - fSlow39;
		double fSlow42 = std::exp(-(fConst15 / fSlow22)) / fSlow35 + -1.0;
		double fSlow43 = fSlow35 * (fSlow39 + (1.0 - fSlow40));
		double fSlow44 = std::exp(-(fConst20 / fSlow10));
		double fSlow45 = GxZitaRev1_faustpower2_f(fSlow44);
		double fSlow46 = 1.0 - fSlow45;
		double fSlow47 = 1.0 - fSlow14 * fSlow45;
		double fSlow48 = std::sqrt(std::max<double>(0.0, GxZitaRev1_faustpower2_f(fSlow47) / GxZitaRev1_faustpower2_f(fSlow46) + -1.0));
		double fSlow49 = fSlow47 / fSlow46;
		double fSlow50 = fSlow49 - fSlow48;
		double fSlow51 = std::exp(-(fConst20 / fSlow22)) / fSlow44 + -1.0;
		double fSlow52 = fSlow44 * (fSlow48 + (1.0 - fSlow49));
		double fSlow53 = std::exp(-(fConst25 / fSlow10));
		double fSlow54 = GxZitaRev1_faustpower2_f(fSlow53);
		double fSlow55 = 1.0 - fSlow54;
		double fSlow56 = 1.0 - fSlow14 * fSlow54;
		double fSlow57 = std::sqrt(std::max<double>(0.0, GxZitaRev1_faustpower2_f(fSlow56) / GxZitaRev1_faustpower2_f(fSlow55) + -1.0));
		double fSlow58 = fSlow56 / fSlow55;
		double fSlow59 = fSlow58 - fSlow57;
		double fSlow60 = std::exp(-(fConst25 / fSlow22)) / fSlow53 + -1.0;
		double fSlow61 = fSlow53 * (fSlow57 + (1.0 - fSlow58));
		double fSlow62 = std::exp(-(fConst30 / fSlow10));
		double fSlow63 = GxZitaRev1_faustpower2_f(fSlow62);
		double fSlow64 = 1.0 - fSlow63;
		double fSlow65 = 1.0 - fSlow14 * fSlow63;
		double fSlow66 = std::sqrt(std::max<double>(0.0, GxZitaRev1_faustpower2_f(fSlow65) / GxZitaRev1_faustpower2_f(fSlow64) + -1.0));
		double fSlow67 = fSlow65 / fSlow64;
		double fSlow68 = fSlow67 - fSlow66;
		double fSlow69 = std::exp(-(fConst30 / fSlow22)) / fSlow62 + -1.0;
		double fSlow70 = fSlow62 * (fSlow66 + (1.0 - fSlow67));
		double fSlow71 = std::exp(-(fConst35 / fSlow10));
		double fSlow72 = GxZitaRev1_faustpower2_f(fSlow71);
		double fSlow73 = 1.0 - fSlow72;
		double fSlow74 = 1.0 - fSlow14 * fSlow72;
		double fSlow75 = std::sqrt(std::max<double>(0.0, GxZitaRev1_faustpower2_f(fSlow74) / GxZitaRev1_faustpower2_f(fSlow73) + -1.0));
		double fSlow76 = fSlow74 / fSlow73;
		double fSlow77 = fSlow76 - fSlow75;
		double fSlow78 = std::exp(-(fConst35 / fSlow22)) / fSlow71 + -1.0;
		double fSlow79 = fSlow71 * (fSlow75 + (1.0 - fSlow76));
		double fSlow80 = std::exp(-(fConst40 / fSlow10));
		double fSlow81 = GxZitaRev1_faustpower2_f(fSlow80);
		double fSlow82 = 1.0 - fSlow81;
		double fSlow83 = 1.0 - fSlow14 * fSlow81;
		double fSlow84 = std::sqrt(std::max<double>(0.0, GxZitaRev1_faustpower2_f(fSlow83) / GxZitaRev1_faustpower2_f(fSlow82) + -1.0));
		double fSlow85 = fSlow83 / fSlow82;
		double fSlow86 = fSlow85 - fSlow84;
		double fSlow87 = std::exp(-(fConst40 / fSlow22)) / fSlow80 + -1.0;
		double fSlow88 = fSlow80 * (fSlow84 + (1.0 - fSlow85));
		double fSlow89 = 0.0010000000000000009 * static_cast<double>(fVslider9);
		double fSlow90 = 0.0010000000000000009 * static_cast<double>(fVslider10);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = fSlow4 * fRec0[1];
			double fTemp1 = fSlow9 * fRec1[1];
			fRec13[0] = -(fSlow21 * (fSlow20 * fRec13[1] - (fRec6[1] + fRec6[2])));
			fRec12[0] = fSlow24 * (fRec6[1] + fSlow23 * fRec13[0]) + fSlow18 * fRec12[1];
			fVec0[IOTA0 & 16383] = 0.35355339059327373 * fRec12[0] + 1e-20;
			double fTemp2 = static_cast<double>(input0[i0]);
			fVec1[IOTA0 & 16383] = fTemp2;
			double fTemp3 = 0.3 * fVec1[(faust_wrap_sub(IOTA0, iSlow25)) & 16383];
			double fTemp4 = fTemp3 + fVec0[(faust_wrap_sub(IOTA0, iConst6)) & 16383] - 0.6 * fRec10[1];
			fVec2[IOTA0 & 4095] = fTemp4;
			fRec10[0] = fVec2[(faust_wrap_sub(IOTA0, iConst8)) & 4095];
			double fRec11 = 0.6 * fTemp4;
			fRec17[0] = -(fSlow21 * (fSlow20 * fRec17[1] - (fRec2[1] + fRec2[2])));
			fRec16[0] = fSlow34 * (fRec2[1] + fSlow33 * fRec17[0]) + fSlow32 * fRec16[1];
			fVec3[IOTA0 & 16383] = 0.35355339059327373 * fRec16[0] + 1e-20;
			double fTemp5 = fVec3[(faust_wrap_sub(IOTA0, iConst12)) & 16383] + fTemp3 - 0.6 * fRec14[1];
			fVec4[IOTA0 & 2047] = fTemp5;
			fRec14[0] = fVec4[(faust_wrap_sub(IOTA0, iConst13)) & 2047];
			double fRec15 = 0.6 * fTemp5;
			double fTemp6 = fRec15 + fRec11;
			fRec21[0] = -(fSlow21 * (fSlow20 * fRec21[1] - (fRec4[1] + fRec4[2])));
			fRec20[0] = fSlow43 * (fRec4[1] + fSlow42 * fRec21[0]) + fSlow41 * fRec20[1];
			fVec5[IOTA0 & 16383] = 0.35355339059327373 * fRec20[0] + 1e-20;
			double fTemp7 = fVec5[(faust_wrap_sub(IOTA0, iConst17)) & 16383] - (fTemp3 + 0.6 * fRec18[1]);
			fVec6[IOTA0 & 4095] = fTemp7;
			fRec18[0] = fVec6[(faust_wrap_sub(IOTA0, iConst18)) & 4095];
			double fRec19 = 0.6 * fTemp7;
			fRec25[0] = -(fSlow21 * (fSlow20 * fRec25[1] - (fRec8[1] + fRec8[2])));
			fRec24[0] = fSlow52 * (fRec8[1] + fSlow51 * fRec25[0]) + fSlow50 * fRec24[1];
			fVec7[IOTA0 & 16383] = 0.35355339059327373 * fRec24[0] + 1e-20;
			double fTemp8 = fVec7[(faust_wrap_sub(IOTA0, iConst22)) & 16383] - (fTemp3 + 0.6 * fRec22[1]);
			fVec8[IOTA0 & 2047] = fTemp8;
			fRec22[0] = fVec8[(faust_wrap_sub(IOTA0, iConst23)) & 2047];
			double fRec23 = 0.6 * fTemp8;
			double fTemp9 = fRec23 + fRec19 + fTemp6;
			fRec29[0] = -(fSlow21 * (fSlow20 * fRec29[1] - (fRec3[1] + fRec3[2])));
			fRec28[0] = fSlow61 * (fRec3[1] + fSlow60 * fRec29[0]) + fSlow59 * fRec28[1];
			fVec9[IOTA0 & 32767] = 0.35355339059327373 * fRec28[0] + 1e-20;
			double fTemp10 = fVec9[(faust_wrap_sub(IOTA0, iConst27)) & 32767] + fTemp3 + 0.6 * fRec26[1];
			fVec10[IOTA0 & 4095] = fTemp10;
			fRec26[0] = fVec10[(faust_wrap_sub(IOTA0, iConst28)) & 4095];
			double fRec27 = -(0.6 * fTemp10);
			fRec33[0] = -(fSlow21 * (fSlow20 * fRec33[1] - (fRec7[1] + fRec7[2])));
			fRec32[0] = fSlow70 * (fRec7[1] + fSlow69 * fRec33[0]) + fSlow68 * fRec32[1];
			fVec11[IOTA0 & 16383] = 0.35355339059327373 * fRec32[0] + 1e-20;
			double fTemp11 = fVec11[(faust_wrap_sub(IOTA0, iConst32)) & 16383] + fTemp3 + 0.6 * fRec30[1];
			fVec12[IOTA0 & 4095] = fTemp11;
			fRec30[0] = fVec12[(faust_wrap_sub(IOTA0, iConst33)) & 4095];
			double fRec31 = -(0.6 * fTemp11);
			fRec37[0] = -(fSlow21 * (fSlow20 * fRec37[1] - (fRec5[1] + fRec5[2])));
			fRec36[0] = fSlow79 * (fRec5[1] + fSlow78 * fRec37[0]) + fSlow77 * fRec36[1];
			fVec13[IOTA0 & 32767] = 0.35355339059327373 * fRec36[0] + 1e-20;
			double fTemp12 = 0.6 * fRec34[1] + fVec13[(faust_wrap_sub(IOTA0, iConst37)) & 32767];
			fVec14[IOTA0 & 4095] = fTemp12 - fTemp3;
			fRec34[0] = fVec14[(faust_wrap_sub(IOTA0, iConst38)) & 4095];
			double fRec35 = 0.6 * (fTemp3 - fTemp12);
			fRec41[0] = -(fSlow21 * (fSlow20 * fRec41[1] - (fRec9[1] + fRec9[2])));
			fRec40[0] = fSlow88 * (fRec9[1] + fSlow87 * fRec41[0]) + fSlow86 * fRec40[1];
			fVec15[IOTA0 & 32767] = 0.35355339059327373 * fRec40[0] + 1e-20;
			double fTemp13 = 0.6 * fRec38[1] + fVec15[(faust_wrap_sub(IOTA0, iConst42)) & 32767];
			fVec16[IOTA0 & 2047] = fTemp13 - fTemp3;
			fRec38[0] = fVec16[(faust_wrap_sub(IOTA0, iConst43)) & 2047];
			double fRec39 = 0.6 * (fTemp3 - fTemp13);
			fRec2[0] = fRec38[1] + fRec34[1] + fRec30[1] + fRec26[1] + fRec22[1] + fRec18[1] + fRec10[1] + fRec14[1] + fRec39 + fRec35 + fRec31 + fRec27 + fTemp9;
			fRec3[0] = fRec22[1] + fRec18[1] + fRec10[1] + fRec14[1] + fTemp9 - (fRec38[1] + fRec34[1] + fRec30[1] + fRec26[1] + fRec39 + fRec35 + fRec27 + fRec31);
			double fTemp14 = fRec19 + fRec23;
			fRec4[0] = fRec30[1] + fRec26[1] + fRec10[1] + fRec14[1] + fRec31 + fRec27 + fTemp6 - (fRec38[1] + fRec34[1] + fRec22[1] + fRec18[1] + fRec39 + fRec35 + fTemp14);
			fRec5[0] = fRec38[1] + fRec34[1] + fRec10[1] + fRec14[1] + fRec39 + fRec35 + fTemp6 - (fRec30[1] + fRec26[1] + fRec22[1] + fRec18[1] + fRec31 + fRec27 + fTemp14);
			double fTemp15 = fRec11 + fRec23;
			double fTemp16 = fRec15 + fRec19;
			fRec6[0] = fRec34[1] + fRec26[1] + fRec18[1] + fRec14[1] + fRec35 + fRec27 + fTemp16 - (fRec38[1] + fRec30[1] + fRec22[1] + fRec10[1] + fRec39 + fRec31 + fTemp15);
			fRec7[0] = fRec38[1] + fRec30[1] + fRec18[1] + fRec14[1] + fRec39 + fRec31 + fTemp16 - (fRec34[1] + fRec26[1] + fRec22[1] + fRec10[1] + fRec35 + fRec27 + fTemp15);
			double fTemp17 = fRec11 + fRec19;
			double fTemp18 = fRec15 + fRec23;
			fRec8[0] = fRec38[1] + fRec26[1] + fRec22[1] + fRec14[1] + fRec39 + fRec27 + fTemp18 - (fRec34[1] + fRec30[1] + fRec18[1] + fRec10[1] + fRec35 + fRec31 + fTemp17);
			fRec9[0] = fRec34[1] + fRec30[1] + fRec22[1] + fRec14[1] + fRec35 + fRec31 + fTemp18 - (fRec38[1] + fRec26[1] + fRec18[1] + fRec10[1] + fRec39 + fRec27 + fTemp17);
			double fTemp19 = 0.37 * (fRec3[0] - fRec4[0]);
			double fTemp20 = fTemp19 + fTemp1;
			fRec1[0] = fTemp20 - fSlow8 * fRec1[2];
			double fTemp21 = fSlow8 * fRec1[0];
			double fTemp22 = 0.5 * (fTemp21 + fTemp19 + fRec1[2] - fTemp1 + fSlow5 * (fRec1[2] + fTemp21 - fTemp20));
			double fTemp23 = fTemp22 + fTemp0;
			fRec0[0] = fTemp23 - fSlow3 * fRec0[2];
			double fTemp24 = fSlow3 * fRec0[0];
			fRec42[0] = fSlow89 + 0.999 * fRec42[1];
			double fTemp25 = fRec42[0] + 1.0;
			double fTemp26 = fTemp2 * (1.0 - 0.5 * fTemp25);
			double fTemp27 = fSlow4 * fRec43[1];
			double fTemp28 = fSlow9 * fRec44[1];
			double fTemp29 = 0.37 * (fRec3[0] + fRec4[0]);
			double fTemp30 = fTemp29 + fTemp28;
			fRec44[0] = fTemp30 - fSlow8 * fRec44[2];
			double fTemp31 = fSlow8 * fRec44[0];
			double fTemp32 = 0.5 * (fTemp31 + fTemp29 + fRec44[2] - fTemp28 + fSlow5 * (fRec44[2] + fTemp31 - fTemp30));
			double fTemp33 = fTemp32 + fTemp27;
			fRec43[0] = fTemp33 - fSlow3 * fRec43[2];
			double fTemp34 = fSlow3 * fRec43[0];
			fRec45[0] = fSlow90 + 0.999 * fRec45[1];
			output0[i0] = static_cast<FAUSTFLOAT>(0.5 * std::pow(1e+01, 0.05 * fRec45[0]) * (0.25 * fTemp25 * (fTemp34 + fTemp32 + fRec43[2] - fTemp27 + fSlow0 * (fRec43[2] + fTemp34 - fTemp33)) + fTemp26 + fTemp26 + 0.25 * fTemp25 * (fTemp24 + fTemp22 + fRec0[2] - fTemp0 + fSlow0 * (fRec0[2] + fTemp24 - fTemp23))));
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec10[1] = fRec10[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec14[1] = fRec14[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec18[1] = fRec18[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec22[1] = fRec22[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec38[1] = fRec38[0];
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
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec42[1] = fRec42[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec45[1] = fRec45[0];
		}
	}

};

#endif
