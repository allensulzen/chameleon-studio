/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Multi Band Compressor"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbc -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxMbc_H__
#define  __GxMbc_H__

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
#define FAUSTCLASS GxMbc
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

static double GxMbc_faustpower2_f(double value) {
	return value * value;
}

class GxMbc : public chdsp {
	
 private:
	
	int fSampleRate;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	double fConst2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	double fVec0[2];
	double fRec15[2];
	double fRec14[3];
	double fVec1[2];
	double fRec13[2];
	double fRec12[3];
	double fVec2[2];
	double fRec11[2];
	double fRec10[3];
	double fVec3[2];
	double fRec9[2];
	double fRec8[3];
	double fRec5[2];
	int iRec6[2];
	double fRec7[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider6;
	double fRec4[2];
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	double fRec3[2];
	FAUSTFLOAT fHslider9;
	double fRec16[2];
	double fRec0[2];
	int iRec1[2];
	double fRec2[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	double fRec26[2];
	double fRec25[3];
	double fRec22[2];
	int iRec23[2];
	double fRec24[2];
	FAUSTFLOAT fVbargraph2;
	FAUSTFLOAT fHslider12;
	double fRec21[2];
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	double fRec20[2];
	FAUSTFLOAT fHslider15;
	double fRec27[2];
	double fRec17[2];
	int iRec18[2];
	double fRec19[2];
	FAUSTFLOAT fVbargraph3;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	double fRec38[2];
	double fRec37[3];
	double fRec36[3];
	double fRec33[2];
	int iRec34[2];
	double fRec35[2];
	FAUSTFLOAT fVbargraph4;
	FAUSTFLOAT fHslider18;
	double fRec32[2];
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	double fRec31[2];
	FAUSTFLOAT fHslider21;
	double fRec39[2];
	double fRec28[2];
	int iRec29[2];
	double fRec30[2];
	FAUSTFLOAT fVbargraph5;
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fHslider23;
	double fRec51[2];
	double fRec50[3];
	double fRec49[3];
	double fRec48[3];
	double fRec45[2];
	int iRec46[2];
	double fRec47[2];
	FAUSTFLOAT fVbargraph6;
	FAUSTFLOAT fHslider24;
	double fRec44[2];
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	double fRec43[2];
	FAUSTFLOAT fHslider27;
	double fRec52[2];
	double fRec40[2];
	int iRec41[2];
	double fRec42[2];
	FAUSTFLOAT fVbargraph7;
	FAUSTFLOAT fHslider28;
	FAUSTFLOAT fHslider29;
	double fRec65[2];
	double fRec64[3];
	double fRec63[3];
	double fRec62[3];
	double fRec61[3];
	double fRec58[2];
	int iRec59[2];
	double fRec60[2];
	FAUSTFLOAT fVbargraph8;
	FAUSTFLOAT fHslider30;
	double fRec57[2];
	FAUSTFLOAT fHslider31;
	FAUSTFLOAT fHslider32;
	double fRec56[2];
	FAUSTFLOAT fHslider33;
	double fRec66[2];
	double fRec53[2];
	int iRec54[2];
	double fRec55[2];
	FAUSTFLOAT fVbargraph9;
	
 public:
	GxMbc() {
	}
	
	GxMbc(const GxMbc&) = default;
	
	virtual ~GxMbc() = default;
	
	GxMbc& operator=(const GxMbc&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/bypass1:author", "Julius Smith");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Guitar Effects");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbc -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("compressors.lib/compression_gain_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compression_gain_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compression_gain_mono:license", "LicenseRef-STK-4.3");
		m->declare("compressors.lib/compressor_lad_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_lad_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_lad_mono:license", "LicenseRef-STK-4.3");
		m->declare("compressors.lib/compressor_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_mono:license", "LicenseRef-STK-4.3");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "1.6.0");
		m->declare("description", "Multi Band Compressor contributed by kokoko3k");
		m->declare("filename", "gx-mbc.dsp");
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
		m->declare("id", "mbc");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Multi Band Compressor");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reducemaps.lib/author", "Yann Orlarey");
		m->declare("reducemaps.lib/copyright", "Grame and Yann Orlarey");
		m->declare("reducemaps.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("reducemaps.lib/name", "Reduce Library");
		m->declare("reducemaps.lib/version", "1.2.0");
		m->declare("shortname", "MB Compressor");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "LicenseRef-STK-4.3");
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
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(1.0);
		fHslider1 = static_cast<FAUSTFLOAT>(0.012);
		fHslider2 = static_cast<FAUSTFLOAT>(8e+01);
		fHslider3 = static_cast<FAUSTFLOAT>(2.1e+02);
		fHslider4 = static_cast<FAUSTFLOAT>(1.7e+03);
		fHslider5 = static_cast<FAUSTFLOAT>(5e+03);
		fHslider6 = static_cast<FAUSTFLOAT>(1.25);
		fHslider7 = static_cast<FAUSTFLOAT>(13.0);
		fHslider8 = static_cast<FAUSTFLOAT>(2.0);
		fHslider9 = static_cast<FAUSTFLOAT>(2.0);
		fHslider10 = static_cast<FAUSTFLOAT>(1.0);
		fHslider11 = static_cast<FAUSTFLOAT>(0.012);
		fHslider12 = static_cast<FAUSTFLOAT>(1.25);
		fHslider13 = static_cast<FAUSTFLOAT>(1e+01);
		fHslider14 = static_cast<FAUSTFLOAT>(2.0);
		fHslider15 = static_cast<FAUSTFLOAT>(2.0);
		fHslider16 = static_cast<FAUSTFLOAT>(1.0);
		fHslider17 = static_cast<FAUSTFLOAT>(0.012);
		fHslider18 = static_cast<FAUSTFLOAT>(1.25);
		fHslider19 = static_cast<FAUSTFLOAT>(4.0);
		fHslider20 = static_cast<FAUSTFLOAT>(2.0);
		fHslider21 = static_cast<FAUSTFLOAT>(2.0);
		fHslider22 = static_cast<FAUSTFLOAT>(1.0);
		fHslider23 = static_cast<FAUSTFLOAT>(0.012);
		fHslider24 = static_cast<FAUSTFLOAT>(1.25);
		fHslider25 = static_cast<FAUSTFLOAT>(8.0);
		fHslider26 = static_cast<FAUSTFLOAT>(2.0);
		fHslider27 = static_cast<FAUSTFLOAT>(2.0);
		fHslider28 = static_cast<FAUSTFLOAT>(1.0);
		fHslider29 = static_cast<FAUSTFLOAT>(0.012);
		fHslider30 = static_cast<FAUSTFLOAT>(1.25);
		fHslider31 = static_cast<FAUSTFLOAT>(11.0);
		fHslider32 = static_cast<FAUSTFLOAT>(2.0);
		fHslider33 = static_cast<FAUSTFLOAT>(2.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec15[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec14[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec13[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec12[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec2[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec11[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec10[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fVec3[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec9[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 3; l11 = faust_wrap_add(l11, 1)) {
			fRec8[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec5[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			iRec6[l13] = 0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec7[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec4[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec3[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec16[l17] = 0.0;
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
			fRec26[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 3; l22 = faust_wrap_add(l22, 1)) {
			fRec25[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec22[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			iRec23[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec24[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec21[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec20[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec27[l28] = 0.0;
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
			fRec38[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 3; l33 = faust_wrap_add(l33, 1)) {
			fRec37[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 3; l34 = faust_wrap_add(l34, 1)) {
			fRec36[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec33[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			iRec34[l36] = 0;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec35[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fRec32[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec31[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec39[l40] = 0.0;
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
			fRec51[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 3; l45 = faust_wrap_add(l45, 1)) {
			fRec50[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 3; l46 = faust_wrap_add(l46, 1)) {
			fRec49[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 3; l47 = faust_wrap_add(l47, 1)) {
			fRec48[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec45[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			iRec46[l49] = 0;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec47[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fRec44[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec43[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fRec52[l53] = 0.0;
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
			fRec65[l57] = 0.0;
		}
		for (int l58 = 0; l58 < 3; l58 = faust_wrap_add(l58, 1)) {
			fRec64[l58] = 0.0;
		}
		for (int l59 = 0; l59 < 3; l59 = faust_wrap_add(l59, 1)) {
			fRec63[l59] = 0.0;
		}
		for (int l60 = 0; l60 < 3; l60 = faust_wrap_add(l60, 1)) {
			fRec62[l60] = 0.0;
		}
		for (int l61 = 0; l61 < 3; l61 = faust_wrap_add(l61, 1)) {
			fRec61[l61] = 0.0;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			fRec58[l62] = 0.0;
		}
		for (int l63 = 0; l63 < 2; l63 = faust_wrap_add(l63, 1)) {
			iRec59[l63] = 0;
		}
		for (int l64 = 0; l64 < 2; l64 = faust_wrap_add(l64, 1)) {
			fRec60[l64] = 0.0;
		}
		for (int l65 = 0; l65 < 2; l65 = faust_wrap_add(l65, 1)) {
			fRec57[l65] = 0.0;
		}
		for (int l66 = 0; l66 < 2; l66 = faust_wrap_add(l66, 1)) {
			fRec56[l66] = 0.0;
		}
		for (int l67 = 0; l67 < 2; l67 = faust_wrap_add(l67, 1)) {
			fRec66[l67] = 0.0;
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
	
	virtual GxMbc* clone() {
		return new GxMbc(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Multi Band Compressor");
		ui_interface->declare(&fHslider0, "enum", "Compress|Bypass|Mute");
		ui_interface->declare(&fHslider0, "tooltip", "Compress or Mute the selected band, or Bypass The Compressor");
		ui_interface->addHorizontalSlider("Mode1", &fHslider0, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(3.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider10, "enum", "Compress|Bypass|Mute");
		ui_interface->declare(&fHslider10, "tooltip", "Compress or Mute the selected band, or Bypass The Compressor");
		ui_interface->addHorizontalSlider("Mode2", &fHslider10, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(3.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider16, "enum", "Compress|Bypass|Mute");
		ui_interface->declare(&fHslider16, "tooltip", "Compress or Mute the selected band, or Bypass The Compressor");
		ui_interface->addHorizontalSlider("Mode3", &fHslider16, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(3.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider22, "enum", "Compress|Bypass|Mute");
		ui_interface->declare(&fHslider22, "tooltip", "Compress or Mute the selected band, or Bypass The Compressor");
		ui_interface->addHorizontalSlider("Mode4", &fHslider22, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(3.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider28, "enum", "Compress|Bypass|Mute");
		ui_interface->declare(&fHslider28, "tooltip", "Compress or Mute the selected band, or Bypass The Compressor");
		ui_interface->addHorizontalSlider("Mode5", &fHslider28, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(3.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider7, "5", "");
		ui_interface->declare(&fHslider7, "tooltip", "Post amplification and threshold");
		ui_interface->addHorizontalSlider("Makeup1", &fHslider7, FAUSTFLOAT(13.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(5e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider13, "5", "");
		ui_interface->declare(&fHslider13, "tooltip", "Post amplification and threshold");
		ui_interface->addHorizontalSlider("Makeup2", &fHslider13, FAUSTFLOAT(1e+01), FAUSTFLOAT(-5e+01), FAUSTFLOAT(5e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider19, "5", "");
		ui_interface->declare(&fHslider19, "tooltip", "Post amplification and threshold");
		ui_interface->addHorizontalSlider("Makeup3", &fHslider19, FAUSTFLOAT(4.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(5e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider25, "5", "");
		ui_interface->declare(&fHslider25, "tooltip", "Post amplification and threshold");
		ui_interface->addHorizontalSlider("Makeup4", &fHslider25, FAUSTFLOAT(8.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(5e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider31, "5", "");
		ui_interface->declare(&fHslider31, "tooltip", "Post amplification and threshold");
		ui_interface->addHorizontalSlider("Makeup5", &fHslider31, FAUSTFLOAT(11.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(5e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider9, "6", "");
		ui_interface->declare(&fHslider9, "tooltip", "Threshold correction, an anticlip measure");
		ui_interface->addHorizontalSlider("MakeupThreshold1", &fHslider9, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider15, "6", "");
		ui_interface->declare(&fHslider15, "tooltip", "Threshold correction, an anticlip measure");
		ui_interface->addHorizontalSlider("MakeupThreshold2", &fHslider15, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider21, "6", "");
		ui_interface->declare(&fHslider21, "tooltip", "Threshold correction, an anticlip measure");
		ui_interface->addHorizontalSlider("MakeupThreshold3", &fHslider21, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider27, "6", "");
		ui_interface->declare(&fHslider27, "tooltip", "Threshold correction, an anticlip measure");
		ui_interface->addHorizontalSlider("MakeupThreshold4", &fHslider27, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider33, "6", "");
		ui_interface->declare(&fHslider33, "tooltip", "Threshold correction, an anticlip measure");
		ui_interface->addHorizontalSlider("MakeupThreshold5", &fHslider33, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider8, "9", "");
		ui_interface->declare(&fHslider8, "tooltip", "Compression ratio");
		ui_interface->addHorizontalSlider("Ratio1", &fHslider8, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider14, "9", "");
		ui_interface->declare(&fHslider14, "tooltip", "Compression ratio");
		ui_interface->addHorizontalSlider("Ratio2", &fHslider14, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider20, "9", "");
		ui_interface->declare(&fHslider20, "tooltip", "Compression ratio");
		ui_interface->addHorizontalSlider("Ratio3", &fHslider20, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider26, "9", "");
		ui_interface->declare(&fHslider26, "tooltip", "Compression ratio");
		ui_interface->addHorizontalSlider("Ratio4", &fHslider26, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider32, "9", "");
		ui_interface->declare(&fHslider32, "tooltip", "Compression ratio");
		ui_interface->addHorizontalSlider("Ratio5", &fHslider32, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider1, "A", "");
		ui_interface->declare(&fHslider1, "tooltip", "Time before the compressor starts to kick in");
		ui_interface->addHorizontalSlider("Attack1", &fHslider1, FAUSTFLOAT(0.012), FAUSTFLOAT(0.001), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fHslider11, "A", "");
		ui_interface->declare(&fHslider11, "tooltip", "Time before the compressor starts to kick in");
		ui_interface->addHorizontalSlider("Attack2", &fHslider11, FAUSTFLOAT(0.012), FAUSTFLOAT(0.001), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fHslider17, "A", "");
		ui_interface->declare(&fHslider17, "tooltip", "Time before the compressor starts to kick in");
		ui_interface->addHorizontalSlider("Attack3", &fHslider17, FAUSTFLOAT(0.012), FAUSTFLOAT(0.001), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fHslider23, "A", "");
		ui_interface->declare(&fHslider23, "tooltip", "Time before the compressor starts to kick in");
		ui_interface->addHorizontalSlider("Attack4", &fHslider23, FAUSTFLOAT(0.012), FAUSTFLOAT(0.001), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fHslider29, "A", "");
		ui_interface->declare(&fHslider29, "tooltip", "Time before the compressor starts to kick in");
		ui_interface->addHorizontalSlider("Attack5", &fHslider29, FAUSTFLOAT(0.012), FAUSTFLOAT(0.001), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fHslider6, "B", "");
		ui_interface->declare(&fHslider6, "tooltip", "Time before the compressor releases the sound");
		ui_interface->addHorizontalSlider("Release1", &fHslider6, FAUSTFLOAT(1.25), FAUSTFLOAT(0.01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider12, "B", "");
		ui_interface->declare(&fHslider12, "tooltip", "Time before the compressor releases the sound");
		ui_interface->addHorizontalSlider("Release2", &fHslider12, FAUSTFLOAT(1.25), FAUSTFLOAT(0.01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider18, "B", "");
		ui_interface->declare(&fHslider18, "tooltip", "Time before the compressor releases the sound");
		ui_interface->addHorizontalSlider("Release3", &fHslider18, FAUSTFLOAT(1.25), FAUSTFLOAT(0.01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider24, "B", "");
		ui_interface->declare(&fHslider24, "tooltip", "Time before the compressor releases the sound");
		ui_interface->addHorizontalSlider("Release4", &fHslider24, FAUSTFLOAT(1.25), FAUSTFLOAT(0.01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider30, "B", "");
		ui_interface->declare(&fHslider30, "tooltip", "Time before the compressor releases the sound");
		ui_interface->addHorizontalSlider("Release5", &fHslider30, FAUSTFLOAT(1.25), FAUSTFLOAT(0.01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider2, "log", "");
		ui_interface->declare(&fHslider2, "name", "Crossover B1-B2 (hz)");
		ui_interface->declare(&fHslider2, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b1_b2", &fHslider2, FAUSTFLOAT(8e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fHslider3, "log", "");
		ui_interface->declare(&fHslider3, "name", "Crossover B2-B3 (hz)");
		ui_interface->declare(&fHslider3, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b2_b3", &fHslider3, FAUSTFLOAT(2.1e+02), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fHslider4, "log", "");
		ui_interface->declare(&fHslider4, "name", "Crossover B3-B4 (hz)");
		ui_interface->declare(&fHslider4, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b3_b4", &fHslider4, FAUSTFLOAT(1.7e+03), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fHslider5, "log", "");
		ui_interface->declare(&fHslider5, "name", "Crossover B4-B5 (hz)");
		ui_interface->declare(&fHslider5, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b4_b5", &fHslider5, FAUSTFLOAT(5e+03), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fVbargraph8, "tooltip", "no");
		ui_interface->addVerticalBargraph("v10", &fVbargraph8, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph1, "tooltip", "no");
		ui_interface->addVerticalBargraph("v1", &fVbargraph1, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph3, "tooltip", "no");
		ui_interface->addVerticalBargraph("v2", &fVbargraph3, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph5, "tooltip", "no");
		ui_interface->addVerticalBargraph("v3", &fVbargraph5, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph7, "tooltip", "no");
		ui_interface->addVerticalBargraph("v4", &fVbargraph7, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph9, "tooltip", "no");
		ui_interface->addVerticalBargraph("v5", &fVbargraph9, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph0, "tooltip", "no");
		ui_interface->addVerticalBargraph("v6", &fVbargraph0, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph2, "tooltip", "no");
		ui_interface->addVerticalBargraph("v7", &fVbargraph2, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph4, "tooltip", "no");
		ui_interface->addVerticalBargraph("v8", &fVbargraph4, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph6, "tooltip", "no");
		ui_interface->addVerticalBargraph("v9", &fVbargraph6, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fHslider0);
		double fSlow1 = std::max<double>(0.0, fSlow0 + -1.0);
		int iSlow2 = static_cast<int>(fSlow1);
		double fSlow3 = static_cast<double>(fHslider1);
		double fSlow4 = 0.5 * fSlow3;
		int iSlow5 = std::fabs(fSlow4) < 2.220446049250313e-16;
		double fSlow6 = ((iSlow5) ? 0.0 : std::exp(-(fConst1 / ((iSlow5) ? 1.0 : fSlow4))));
		double fSlow7 = std::tan(fConst2 * static_cast<double>(fHslider2));
		double fSlow8 = GxMbc_faustpower2_f(fSlow7);
		double fSlow9 = 2.0 * (1.0 - 1.0 / fSlow8);
		double fSlow10 = 1.0 / fSlow7;
		double fSlow11 = (fSlow10 + -1.0000000000000004) / fSlow7 + 1.0;
		double fSlow12 = (fSlow10 + 1.0000000000000004) / fSlow7 + 1.0;
		double fSlow13 = 1.0 / fSlow12;
		double fSlow14 = std::tan(fConst2 * static_cast<double>(fHslider3));
		double fSlow15 = GxMbc_faustpower2_f(fSlow14);
		double fSlow16 = 2.0 * (1.0 - 1.0 / fSlow15);
		double fSlow17 = 1.0 / fSlow14;
		double fSlow18 = (fSlow17 + -1.0000000000000004) / fSlow14 + 1.0;
		double fSlow19 = (fSlow17 + 1.0000000000000004) / fSlow14 + 1.0;
		double fSlow20 = 1.0 / fSlow19;
		double fSlow21 = std::tan(fConst2 * static_cast<double>(fHslider4));
		double fSlow22 = GxMbc_faustpower2_f(fSlow21);
		double fSlow23 = 2.0 * (1.0 - 1.0 / fSlow22);
		double fSlow24 = 1.0 / fSlow21;
		double fSlow25 = (fSlow24 + -1.0000000000000004) / fSlow21 + 1.0;
		double fSlow26 = (fSlow24 + 1.0000000000000004) / fSlow21 + 1.0;
		double fSlow27 = 1.0 / fSlow26;
		double fSlow28 = std::tan(fConst2 * static_cast<double>(fHslider5));
		double fSlow29 = GxMbc_faustpower2_f(fSlow28);
		double fSlow30 = 2.0 * (1.0 - 1.0 / fSlow29);
		double fSlow31 = 1.0 / fSlow28;
		double fSlow32 = (fSlow31 + -1.0000000000000004) / fSlow28 + 1.0;
		double fSlow33 = (fSlow31 + 1.0000000000000004) / fSlow28 + 1.0;
		double fSlow34 = 1.0 / fSlow33;
		double fSlow35 = 1.0 - fSlow31;
		double fSlow36 = 1.0 / (fSlow31 + 1.0);
		double fSlow37 = 1.0 - fSlow24;
		double fSlow38 = fSlow24 + 1.0;
		double fSlow39 = 1.0 / fSlow38;
		double fSlow40 = 1.0 - fSlow17;
		double fSlow41 = fSlow17 + 1.0;
		double fSlow42 = 1.0 / fSlow41;
		double fSlow43 = 1.0 - fSlow10;
		double fSlow44 = fSlow10 + 1.0;
		double fSlow45 = 1.0 / fSlow44;
		double fSlow46 = static_cast<double>(fHslider6);
		int iSlow47 = std::fabs(fSlow46) < 2.220446049250313e-16;
		double fSlow48 = ((iSlow47) ? 0.0 : std::exp(-(fConst1 / ((iSlow47) ? 1.0 : fSlow46))));
		int iSlow49 = std::fabs(fSlow3) < 2.220446049250313e-16;
		double fSlow50 = ((iSlow49) ? 0.0 : std::exp(-(fConst1 / ((iSlow49) ? 1.0 : fSlow3))));
		double fSlow51 = static_cast<double>(fHslider7);
		double fSlow52 = 1.0 - fSlow6;
		double fSlow53 = 1.0 / std::max<double>(2.220446049250313e-16, static_cast<double>(fHslider8)) + -1.0;
		double fSlow54 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (fSlow51 - static_cast<double>(fHslider9)) * std::fabs(fSlow1 + -1.0));
		double fSlow55 = std::fabs(std::max<double>(0.0, fSlow0 + -2.0) + -1.0);
		double fSlow56 = static_cast<double>(fHslider10);
		double fSlow57 = std::max<double>(0.0, fSlow56 + -1.0);
		int iSlow58 = static_cast<int>(fSlow57);
		double fSlow59 = static_cast<double>(fHslider11);
		double fSlow60 = 0.5 * fSlow59;
		int iSlow61 = std::fabs(fSlow60) < 2.220446049250313e-16;
		double fSlow62 = ((iSlow61) ? 0.0 : std::exp(-(fConst1 / ((iSlow61) ? 1.0 : fSlow60))));
		double fSlow63 = 1.0 / (fSlow8 * fSlow12);
		double fSlow64 = static_cast<double>(fHslider12);
		int iSlow65 = std::fabs(fSlow64) < 2.220446049250313e-16;
		double fSlow66 = ((iSlow65) ? 0.0 : std::exp(-(fConst1 / ((iSlow65) ? 1.0 : fSlow64))));
		int iSlow67 = std::fabs(fSlow59) < 2.220446049250313e-16;
		double fSlow68 = ((iSlow67) ? 0.0 : std::exp(-(fConst1 / ((iSlow67) ? 1.0 : fSlow59))));
		double fSlow69 = static_cast<double>(fHslider13);
		double fSlow70 = 1.0 - fSlow62;
		double fSlow71 = 1.0 / std::max<double>(2.220446049250313e-16, static_cast<double>(fHslider14)) + -1.0;
		double fSlow72 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (fSlow69 - static_cast<double>(fHslider15)) * std::fabs(fSlow57 + -1.0));
		double fSlow73 = std::fabs(std::max<double>(0.0, fSlow56 + -2.0) + -1.0);
		double fSlow74 = static_cast<double>(fHslider16);
		double fSlow75 = std::max<double>(0.0, fSlow74 + -1.0);
		int iSlow76 = static_cast<int>(fSlow75);
		double fSlow77 = static_cast<double>(fHslider17);
		double fSlow78 = 0.5 * fSlow77;
		int iSlow79 = std::fabs(fSlow78) < 2.220446049250313e-16;
		double fSlow80 = ((iSlow79) ? 0.0 : std::exp(-(fConst1 / ((iSlow79) ? 1.0 : fSlow78))));
		double fSlow81 = 1.0 - fSlow43 / fSlow7;
		double fSlow82 = 1.0 / (fSlow44 / fSlow7 + 1.0);
		double fSlow83 = 1.0 / (fSlow15 * fSlow19);
		double fSlow84 = static_cast<double>(fHslider18);
		int iSlow85 = std::fabs(fSlow84) < 2.220446049250313e-16;
		double fSlow86 = ((iSlow85) ? 0.0 : std::exp(-(fConst1 / ((iSlow85) ? 1.0 : fSlow84))));
		int iSlow87 = std::fabs(fSlow77) < 2.220446049250313e-16;
		double fSlow88 = ((iSlow87) ? 0.0 : std::exp(-(fConst1 / ((iSlow87) ? 1.0 : fSlow77))));
		double fSlow89 = static_cast<double>(fHslider19);
		double fSlow90 = 1.0 - fSlow80;
		double fSlow91 = 1.0 / std::max<double>(2.220446049250313e-16, static_cast<double>(fHslider20)) + -1.0;
		double fSlow92 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (fSlow89 - static_cast<double>(fHslider21)) * std::fabs(fSlow75 + -1.0));
		double fSlow93 = std::fabs(std::max<double>(0.0, fSlow74 + -2.0) + -1.0);
		double fSlow94 = static_cast<double>(fHslider22);
		double fSlow95 = std::max<double>(0.0, fSlow94 + -1.0);
		int iSlow96 = static_cast<int>(fSlow95);
		double fSlow97 = static_cast<double>(fHslider23);
		double fSlow98 = 0.5 * fSlow97;
		int iSlow99 = std::fabs(fSlow98) < 2.220446049250313e-16;
		double fSlow100 = ((iSlow99) ? 0.0 : std::exp(-(fConst1 / ((iSlow99) ? 1.0 : fSlow98))));
		double fSlow101 = 1.0 - fSlow40 / fSlow14;
		double fSlow102 = 1.0 / (fSlow41 / fSlow14 + 1.0);
		double fSlow103 = 1.0 / (fSlow22 * fSlow26);
		double fSlow104 = static_cast<double>(fHslider24);
		int iSlow105 = std::fabs(fSlow104) < 2.220446049250313e-16;
		double fSlow106 = ((iSlow105) ? 0.0 : std::exp(-(fConst1 / ((iSlow105) ? 1.0 : fSlow104))));
		int iSlow107 = std::fabs(fSlow97) < 2.220446049250313e-16;
		double fSlow108 = ((iSlow107) ? 0.0 : std::exp(-(fConst1 / ((iSlow107) ? 1.0 : fSlow97))));
		double fSlow109 = static_cast<double>(fHslider25);
		double fSlow110 = 1.0 - fSlow100;
		double fSlow111 = 1.0 / std::max<double>(2.220446049250313e-16, static_cast<double>(fHslider26)) + -1.0;
		double fSlow112 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (fSlow109 - static_cast<double>(fHslider27)) * std::fabs(fSlow95 + -1.0));
		double fSlow113 = std::fabs(std::max<double>(0.0, fSlow94 + -2.0) + -1.0);
		double fSlow114 = static_cast<double>(fHslider28);
		double fSlow115 = std::max<double>(0.0, fSlow114 + -1.0);
		int iSlow116 = static_cast<int>(fSlow115);
		double fSlow117 = static_cast<double>(fHslider29);
		double fSlow118 = 0.5 * fSlow117;
		int iSlow119 = std::fabs(fSlow118) < 2.220446049250313e-16;
		double fSlow120 = ((iSlow119) ? 0.0 : std::exp(-(fConst1 / ((iSlow119) ? 1.0 : fSlow118))));
		double fSlow121 = 1.0 - fSlow37 / fSlow21;
		double fSlow122 = 1.0 / (fSlow38 / fSlow21 + 1.0);
		double fSlow123 = 1.0 / (fSlow29 * fSlow33);
		double fSlow124 = static_cast<double>(fHslider30);
		int iSlow125 = std::fabs(fSlow124) < 2.220446049250313e-16;
		double fSlow126 = ((iSlow125) ? 0.0 : std::exp(-(fConst1 / ((iSlow125) ? 1.0 : fSlow124))));
		int iSlow127 = std::fabs(fSlow117) < 2.220446049250313e-16;
		double fSlow128 = ((iSlow127) ? 0.0 : std::exp(-(fConst1 / ((iSlow127) ? 1.0 : fSlow117))));
		double fSlow129 = static_cast<double>(fHslider31);
		double fSlow130 = 1.0 - fSlow120;
		double fSlow131 = 1.0 / std::max<double>(2.220446049250313e-16, static_cast<double>(fHslider32)) + -1.0;
		double fSlow132 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (fSlow129 - static_cast<double>(fHslider33)) * std::fabs(fSlow115 + -1.0));
		double fSlow133 = std::fabs(std::max<double>(0.0, fSlow114 + -2.0) + -1.0);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			int iTemp0 = iRec1[1] < 4096;
			int iTemp1 = iRec6[1] < 4096;
			double fTemp2 = static_cast<double>(input0[i0]);
			fVec0[0] = fTemp2;
			fRec15[0] = -(fSlow36 * (fSlow35 * fRec15[1] - (fTemp2 + fVec0[1])));
			fRec14[0] = fRec15[0] - fSlow34 * (fSlow32 * fRec14[2] + fSlow30 * fRec14[1]);
			double fTemp3 = fSlow34 * (fRec14[2] + fRec14[0] + 2.0 * fRec14[1]);
			fVec1[0] = fTemp3;
			fRec13[0] = -(fSlow39 * (fSlow37 * fRec13[1] - (fTemp3 + fVec1[1])));
			fRec12[0] = fRec13[0] - fSlow27 * (fSlow25 * fRec12[2] + fSlow23 * fRec12[1]);
			double fTemp4 = fSlow27 * (fRec12[2] + fRec12[0] + 2.0 * fRec12[1]);
			fVec2[0] = fTemp4;
			fRec11[0] = -(fSlow42 * (fSlow40 * fRec11[1] - (fTemp4 + fVec2[1])));
			fRec10[0] = fRec11[0] - fSlow20 * (fSlow18 * fRec10[2] + fSlow16 * fRec10[1]);
			double fTemp5 = fSlow20 * (fRec10[2] + fRec10[0] + 2.0 * fRec10[1]);
			fVec3[0] = fTemp5;
			fRec9[0] = -(fSlow45 * (fSlow43 * fRec9[1] - (fTemp5 + fVec3[1])));
			fRec8[0] = fRec9[0] - fSlow13 * (fSlow11 * fRec8[2] + fSlow9 * fRec8[1]);
			double fTemp6 = fSlow13 * (fRec8[2] + fRec8[0] + 2.0 * fRec8[1]);
			double fTemp7 = std::max<double>(fConst1, std::fabs(fTemp6));
			fRec5[0] = ((iTemp1) ? std::max<double>(fRec5[1], fTemp7) : fTemp7);
			iRec6[0] = ((iTemp1) ? faust_wrap_add(iRec6[1], 1) : 1);
			fRec7[0] = ((iTemp1) ? fRec7[1] : fRec5[1]);
			fVbargraph0 = static_cast<FAUSTFLOAT>(fRec7[0]);
			double fTemp8 = fTemp6;
			double fTemp9 = ((iSlow2) ? 0.0 : fTemp8);
			double fTemp10 = std::fabs(fTemp9);
			double fTemp11 = ((fTemp10 > fRec4[1]) ? fSlow50 : fSlow48);
			fRec4[0] = fTemp10 * (1.0 - fTemp11) + fRec4[1] * fTemp11;
			fRec3[0] = fSlow53 * fSlow52 * std::max<double>(fSlow51 + 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec4[0])), 0.0) + fSlow6 * fRec3[1];
			fRec16[0] = fSlow54 + 0.999 * fRec16[1];
			double fTemp12 = fSlow55 * fRec16[0] * ((iSlow2) ? fTemp8 : fTemp9 * std::pow(1e+01, 0.05 * fRec3[0]));
			double fTemp13 = std::max<double>(fConst1, std::fabs(fTemp12));
			fRec0[0] = ((iTemp0) ? std::max<double>(fRec0[1], fTemp13) : fTemp13);
			iRec1[0] = ((iTemp0) ? faust_wrap_add(iRec1[1], 1) : 1);
			fRec2[0] = ((iTemp0) ? fRec2[1] : fRec0[1]);
			fVbargraph1 = static_cast<FAUSTFLOAT>(fRec2[0]);
			int iTemp14 = iRec18[1] < 4096;
			int iTemp15 = iRec23[1] < 4096;
			fRec26[0] = -(fSlow45 * (fSlow43 * fRec26[1] - fSlow10 * (fTemp5 - fVec3[1])));
			fRec25[0] = fRec26[0] - fSlow13 * (fSlow11 * fRec25[2] + fSlow9 * fRec25[1]);
			double fTemp16 = fSlow63 * (fRec25[2] + (fRec25[0] - 2.0 * fRec25[1]));
			double fTemp17 = std::max<double>(fConst1, std::fabs(fTemp16));
			fRec22[0] = ((iTemp15) ? std::max<double>(fRec22[1], fTemp17) : fTemp17);
			iRec23[0] = ((iTemp15) ? faust_wrap_add(iRec23[1], 1) : 1);
			fRec24[0] = ((iTemp15) ? fRec24[1] : fRec22[1]);
			fVbargraph2 = static_cast<FAUSTFLOAT>(fRec24[0]);
			double fTemp18 = fTemp16;
			double fTemp19 = ((iSlow58) ? 0.0 : fTemp18);
			double fTemp20 = std::fabs(fTemp19);
			double fTemp21 = ((fTemp20 > fRec21[1]) ? fSlow68 : fSlow66);
			fRec21[0] = fTemp20 * (1.0 - fTemp21) + fRec21[1] * fTemp21;
			fRec20[0] = fSlow71 * fSlow70 * std::max<double>(fSlow69 + 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec21[0])), 0.0) + fSlow62 * fRec20[1];
			fRec27[0] = fSlow72 + 0.999 * fRec27[1];
			double fTemp22 = fSlow73 * fRec27[0] * ((iSlow58) ? fTemp18 : fTemp19 * std::pow(1e+01, 0.05 * fRec20[0]));
			double fTemp23 = std::max<double>(fConst1, std::fabs(fTemp22));
			fRec17[0] = ((iTemp14) ? std::max<double>(fRec17[1], fTemp23) : fTemp23);
			iRec18[0] = ((iTemp14) ? faust_wrap_add(iRec18[1], 1) : 1);
			fRec19[0] = ((iTemp14) ? fRec19[1] : fRec17[1]);
			fVbargraph3 = static_cast<FAUSTFLOAT>(fRec19[0]);
			int iTemp24 = iRec29[1] < 4096;
			int iTemp25 = iRec34[1] < 4096;
			double fTemp26 = fSlow9 * fRec36[1];
			fRec38[0] = -(fSlow42 * (fSlow40 * fRec38[1] - fSlow17 * (fTemp4 - fVec2[1])));
			fRec37[0] = fRec38[0] - fSlow20 * (fSlow18 * fRec37[2] + fSlow16 * fRec37[1]);
			fRec36[0] = fSlow83 * (fRec37[2] + (fRec37[0] - 2.0 * fRec37[1])) - fSlow82 * (fSlow81 * fRec36[2] + fTemp26);
			double fTemp27 = fRec36[2] + fSlow82 * (fTemp26 + fSlow81 * fRec36[0]);
			double fTemp28 = std::max<double>(fConst1, std::fabs(fTemp27));
			fRec33[0] = ((iTemp25) ? std::max<double>(fRec33[1], fTemp28) : fTemp28);
			iRec34[0] = ((iTemp25) ? faust_wrap_add(iRec34[1], 1) : 1);
			fRec35[0] = ((iTemp25) ? fRec35[1] : fRec33[1]);
			fVbargraph4 = static_cast<FAUSTFLOAT>(fRec35[0]);
			double fTemp29 = fTemp27;
			double fTemp30 = ((iSlow76) ? 0.0 : fTemp29);
			double fTemp31 = std::fabs(fTemp30);
			double fTemp32 = ((fTemp31 > fRec32[1]) ? fSlow88 : fSlow86);
			fRec32[0] = fTemp31 * (1.0 - fTemp32) + fRec32[1] * fTemp32;
			fRec31[0] = fSlow91 * fSlow90 * std::max<double>(fSlow89 + 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec32[0])), 0.0) + fSlow80 * fRec31[1];
			fRec39[0] = fSlow92 + 0.999 * fRec39[1];
			double fTemp33 = fSlow93 * fRec39[0] * ((iSlow76) ? fTemp29 : fTemp30 * std::pow(1e+01, 0.05 * fRec31[0]));
			double fTemp34 = std::max<double>(fConst1, std::fabs(fTemp33));
			fRec28[0] = ((iTemp24) ? std::max<double>(fRec28[1], fTemp34) : fTemp34);
			iRec29[0] = ((iTemp24) ? faust_wrap_add(iRec29[1], 1) : 1);
			fRec30[0] = ((iTemp24) ? fRec30[1] : fRec28[1]);
			fVbargraph5 = static_cast<FAUSTFLOAT>(fRec30[0]);
			int iTemp35 = iRec41[1] < 4096;
			int iTemp36 = iRec46[1] < 4096;
			double fTemp37 = fSlow9 * fRec48[1];
			double fTemp38 = fSlow16 * fRec49[1];
			fRec51[0] = -(fSlow39 * (fSlow37 * fRec51[1] - fSlow24 * (fTemp3 - fVec1[1])));
			fRec50[0] = fRec51[0] - fSlow27 * (fSlow25 * fRec50[2] + fSlow23 * fRec50[1]);
			fRec49[0] = fSlow103 * (fRec50[2] + (fRec50[0] - 2.0 * fRec50[1])) - fSlow102 * (fSlow101 * fRec49[2] + fTemp38);
			fRec48[0] = fRec49[2] + fSlow102 * (fTemp38 + fSlow101 * fRec49[0]) - fSlow82 * (fSlow81 * fRec48[2] + fTemp37);
			double fTemp39 = fRec48[2] + fSlow82 * (fTemp37 + fSlow81 * fRec48[0]);
			double fTemp40 = std::max<double>(fConst1, std::fabs(fTemp39));
			fRec45[0] = ((iTemp36) ? std::max<double>(fRec45[1], fTemp40) : fTemp40);
			iRec46[0] = ((iTemp36) ? faust_wrap_add(iRec46[1], 1) : 1);
			fRec47[0] = ((iTemp36) ? fRec47[1] : fRec45[1]);
			fVbargraph6 = static_cast<FAUSTFLOAT>(fRec47[0]);
			double fTemp41 = fTemp39;
			double fTemp42 = ((iSlow96) ? 0.0 : fTemp41);
			double fTemp43 = std::fabs(fTemp42);
			double fTemp44 = ((fTemp43 > fRec44[1]) ? fSlow108 : fSlow106);
			fRec44[0] = fTemp43 * (1.0 - fTemp44) + fRec44[1] * fTemp44;
			fRec43[0] = fSlow111 * fSlow110 * std::max<double>(fSlow109 + 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec44[0])), 0.0) + fSlow100 * fRec43[1];
			fRec52[0] = fSlow112 + 0.999 * fRec52[1];
			double fTemp45 = fSlow113 * fRec52[0] * ((iSlow96) ? fTemp41 : fTemp42 * std::pow(1e+01, 0.05 * fRec43[0]));
			double fTemp46 = std::max<double>(fConst1, std::fabs(fTemp45));
			fRec40[0] = ((iTemp35) ? std::max<double>(fRec40[1], fTemp46) : fTemp46);
			iRec41[0] = ((iTemp35) ? faust_wrap_add(iRec41[1], 1) : 1);
			fRec42[0] = ((iTemp35) ? fRec42[1] : fRec40[1]);
			fVbargraph7 = static_cast<FAUSTFLOAT>(fRec42[0]);
			int iTemp47 = iRec54[1] < 4096;
			int iTemp48 = iRec59[1] < 4096;
			double fTemp49 = fSlow9 * fRec61[1];
			double fTemp50 = fSlow16 * fRec62[1];
			double fTemp51 = fSlow23 * fRec63[1];
			fRec65[0] = -(fSlow36 * (fSlow35 * fRec65[1] - fSlow31 * (fTemp2 - fVec0[1])));
			fRec64[0] = fRec65[0] - fSlow34 * (fSlow32 * fRec64[2] + fSlow30 * fRec64[1]);
			fRec63[0] = fSlow123 * (fRec64[2] + (fRec64[0] - 2.0 * fRec64[1])) - fSlow122 * (fSlow121 * fRec63[2] + fTemp51);
			fRec62[0] = fRec63[2] + fSlow122 * (fTemp51 + fSlow121 * fRec63[0]) - fSlow102 * (fSlow101 * fRec62[2] + fTemp50);
			fRec61[0] = fRec62[2] + fSlow102 * (fTemp50 + fSlow101 * fRec62[0]) - fSlow82 * (fSlow81 * fRec61[2] + fTemp49);
			double fTemp52 = fRec61[2] + fSlow82 * (fTemp49 + fSlow81 * fRec61[0]);
			double fTemp53 = std::max<double>(fConst1, std::fabs(fTemp52));
			fRec58[0] = ((iTemp48) ? std::max<double>(fRec58[1], fTemp53) : fTemp53);
			iRec59[0] = ((iTemp48) ? faust_wrap_add(iRec59[1], 1) : 1);
			fRec60[0] = ((iTemp48) ? fRec60[1] : fRec58[1]);
			fVbargraph8 = static_cast<FAUSTFLOAT>(fRec60[0]);
			double fTemp54 = fTemp52;
			double fTemp55 = ((iSlow116) ? 0.0 : fTemp54);
			double fTemp56 = std::fabs(fTemp55);
			double fTemp57 = ((fTemp56 > fRec57[1]) ? fSlow128 : fSlow126);
			fRec57[0] = fTemp56 * (1.0 - fTemp57) + fRec57[1] * fTemp57;
			fRec56[0] = fSlow131 * fSlow130 * std::max<double>(fSlow129 + 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec57[0])), 0.0) + fSlow120 * fRec56[1];
			fRec66[0] = fSlow132 + 0.999 * fRec66[1];
			double fTemp58 = fSlow133 * fRec66[0] * ((iSlow116) ? fTemp54 : fTemp55 * std::pow(1e+01, 0.05 * fRec56[0]));
			double fTemp59 = std::max<double>(fConst1, std::fabs(fTemp58));
			fRec53[0] = ((iTemp47) ? std::max<double>(fRec53[1], fTemp59) : fTemp59);
			iRec54[0] = ((iTemp47) ? faust_wrap_add(iRec54[1], 1) : 1);
			fRec55[0] = ((iTemp47) ? fRec55[1] : fRec53[1]);
			fVbargraph9 = static_cast<FAUSTFLOAT>(fRec55[0]);
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp58 + fTemp45 + fTemp33 + fTemp22 + fTemp12);
			fVec0[1] = fVec0[0];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fVec1[1] = fVec1[0];
			fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fVec2[1] = fVec2[0];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fVec3[1] = fVec3[0];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec5[1] = fRec5[0];
			iRec6[1] = iRec6[0];
			fRec7[1] = fRec7[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec16[1] = fRec16[0];
			fRec0[1] = fRec0[0];
			iRec1[1] = iRec1[0];
			fRec2[1] = fRec2[0];
			fRec26[1] = fRec26[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec22[1] = fRec22[0];
			iRec23[1] = iRec23[0];
			fRec24[1] = fRec24[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec27[1] = fRec27[0];
			fRec17[1] = fRec17[0];
			iRec18[1] = iRec18[0];
			fRec19[1] = fRec19[0];
			fRec38[1] = fRec38[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec33[1] = fRec33[0];
			iRec34[1] = iRec34[0];
			fRec35[1] = fRec35[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec39[1] = fRec39[0];
			fRec28[1] = fRec28[0];
			iRec29[1] = iRec29[0];
			fRec30[1] = fRec30[0];
			fRec51[1] = fRec51[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec45[1] = fRec45[0];
			iRec46[1] = iRec46[0];
			fRec47[1] = fRec47[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec52[1] = fRec52[0];
			fRec40[1] = fRec40[0];
			iRec41[1] = iRec41[0];
			fRec42[1] = fRec42[0];
			fRec65[1] = fRec65[0];
			fRec64[2] = fRec64[1];
			fRec64[1] = fRec64[0];
			fRec63[2] = fRec63[1];
			fRec63[1] = fRec63[0];
			fRec62[2] = fRec62[1];
			fRec62[1] = fRec62[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fRec58[1] = fRec58[0];
			iRec59[1] = iRec59[0];
			fRec60[1] = fRec60[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec66[1] = fRec66[0];
			fRec53[1] = fRec53[0];
			iRec54[1] = iRec54[0];
			fRec55[1] = fRec55[0];
		}
	}

};

#endif
