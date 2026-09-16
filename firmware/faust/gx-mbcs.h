/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Multi Band Compressor Stereo"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbcs -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxMbcs_H__
#define  __GxMbcs_H__

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
#define FAUSTCLASS GxMbcs
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

static double GxMbcs_faustpower2_f(double value) {
	return value * value;
}

class GxMbcs : public chdsp {
	
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
	double fRec9[2];
	double fRec8[3];
	double fRec7[3];
	double fRec6[3];
	double fRec5[3];
	FAUSTFLOAT fHslider6;
	double fRec4[2];
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	double fRec3[2];
	FAUSTFLOAT fHslider9;
	double fRec10[2];
	double fRec0[2];
	int iRec1[2];
	double fRec2[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	double fRec18[2];
	double fRec17[3];
	double fVec1[2];
	double fRec16[2];
	double fRec15[3];
	double fRec14[3];
	double fRec13[3];
	FAUSTFLOAT fHslider12;
	double fRec12[2];
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	double fRec11[2];
	FAUSTFLOAT fHslider15;
	double fRec19[2];
	double fRec20[2];
	int iRec21[2];
	double fRec22[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	double fRec29[2];
	double fRec28[3];
	double fVec2[2];
	double fRec27[2];
	double fRec26[3];
	double fRec25[3];
	FAUSTFLOAT fHslider18;
	double fRec24[2];
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	double fRec23[2];
	FAUSTFLOAT fHslider21;
	double fRec30[2];
	double fRec31[2];
	int iRec32[2];
	double fRec33[2];
	FAUSTFLOAT fVbargraph2;
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fHslider23;
	double fRec39[2];
	double fRec38[3];
	double fVec3[2];
	double fRec37[2];
	double fRec36[3];
	FAUSTFLOAT fHslider24;
	double fRec35[2];
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	double fRec34[2];
	FAUSTFLOAT fHslider27;
	double fRec40[2];
	double fRec41[2];
	int iRec42[2];
	double fRec43[2];
	FAUSTFLOAT fVbargraph3;
	FAUSTFLOAT fHslider28;
	FAUSTFLOAT fHslider29;
	double fRec47[2];
	double fRec46[3];
	FAUSTFLOAT fHslider30;
	double fRec45[2];
	FAUSTFLOAT fHslider31;
	FAUSTFLOAT fHslider32;
	double fRec44[2];
	FAUSTFLOAT fHslider33;
	double fRec48[2];
	double fRec49[2];
	int iRec50[2];
	double fRec51[2];
	FAUSTFLOAT fVbargraph4;
	
 public:
	GxMbcs() {
	}
	
	GxMbcs(const GxMbcs&) = default;
	
	virtual ~GxMbcs() = default;
	
	GxMbcs& operator=(const GxMbcs&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/bypass2:author", "Julius Smith");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Guitar Effects");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbcs -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("compressors.lib/compression_gain_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compression_gain_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compression_gain_mono:license", "LicenseRef-STK-4.3");
		m->declare("compressors.lib/compressor_stereo:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_stereo:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_stereo:license", "LicenseRef-STK-4.3");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "1.6.0");
		m->declare("description", "Multi Band Compressor contributed by kokoko3k");
		m->declare("filename", "gx-mbcs.dsp");
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
		m->declare("id", "mbcs");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Multi Band Compressor Stereo");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reducemaps.lib/author", "Yann Orlarey");
		m->declare("reducemaps.lib/copyright", "Grame and Yann Orlarey");
		m->declare("reducemaps.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("reducemaps.lib/name", "Reduce Library");
		m->declare("reducemaps.lib/version", "1.2.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("shortname", "MB Comp St");
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
		fHslider7 = static_cast<FAUSTFLOAT>(11.0);
		fHslider8 = static_cast<FAUSTFLOAT>(2.0);
		fHslider9 = static_cast<FAUSTFLOAT>(2.0);
		fHslider10 = static_cast<FAUSTFLOAT>(1.0);
		fHslider11 = static_cast<FAUSTFLOAT>(0.012);
		fHslider12 = static_cast<FAUSTFLOAT>(1.25);
		fHslider13 = static_cast<FAUSTFLOAT>(8.0);
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
		fHslider25 = static_cast<FAUSTFLOAT>(1e+01);
		fHslider26 = static_cast<FAUSTFLOAT>(2.0);
		fHslider27 = static_cast<FAUSTFLOAT>(2.0);
		fHslider28 = static_cast<FAUSTFLOAT>(1.0);
		fHslider29 = static_cast<FAUSTFLOAT>(0.012);
		fHslider30 = static_cast<FAUSTFLOAT>(1.25);
		fHslider31 = static_cast<FAUSTFLOAT>(13.0);
		fHslider32 = static_cast<FAUSTFLOAT>(2.0);
		fHslider33 = static_cast<FAUSTFLOAT>(2.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec9[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec8[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fRec7[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec6[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec5[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec4[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec3[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec10[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec0[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			iRec1[l10] = 0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec2[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec18[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 3; l13 = faust_wrap_add(l13, 1)) {
			fRec17[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fVec1[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec16[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 3; l16 = faust_wrap_add(l16, 1)) {
			fRec15[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 3; l17 = faust_wrap_add(l17, 1)) {
			fRec14[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 3; l18 = faust_wrap_add(l18, 1)) {
			fRec13[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec12[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec11[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec19[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec20[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			iRec21[l23] = 0;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec22[l24] = 0.0;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec29[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 3; l26 = faust_wrap_add(l26, 1)) {
			fRec28[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fVec2[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec27[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 3; l29 = faust_wrap_add(l29, 1)) {
			fRec26[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 3; l30 = faust_wrap_add(l30, 1)) {
			fRec25[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec24[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec23[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec30[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec31[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			iRec32[l35] = 0;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec33[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec39[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 3; l38 = faust_wrap_add(l38, 1)) {
			fRec38[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fVec3[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec37[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 3; l41 = faust_wrap_add(l41, 1)) {
			fRec36[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			fRec35[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec34[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec40[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec41[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			iRec42[l46] = 0;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fRec43[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec47[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 3; l49 = faust_wrap_add(l49, 1)) {
			fRec46[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec45[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fRec44[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec48[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fRec49[l53] = 0.0;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			iRec50[l54] = 0;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			fRec51[l55] = 0.0;
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
	
	virtual GxMbcs* clone() {
		return new GxMbcs(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Multi Band Compressor Stereo");
		ui_interface->declare(&fHslider28, "enum", "Compress|Bypass|Mute");
		ui_interface->declare(&fHslider28, "tooltip", "Compress or Mute the selected band, or Bypass The Compressor");
		ui_interface->addHorizontalSlider("Mode1", &fHslider28, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(3.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider22, "enum", "Compress|Bypass|Mute");
		ui_interface->declare(&fHslider22, "tooltip", "Compress or Mute the selected band, or Bypass The Compressor");
		ui_interface->addHorizontalSlider("Mode2", &fHslider22, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(3.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider16, "enum", "Compress|Bypass|Mute");
		ui_interface->declare(&fHslider16, "tooltip", "Compress or Mute the selected band, or Bypass The Compressor");
		ui_interface->addHorizontalSlider("Mode3", &fHslider16, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(3.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider10, "enum", "Compress|Bypass|Mute");
		ui_interface->declare(&fHslider10, "tooltip", "Compress or Mute the selected band, or Bypass The Compressor");
		ui_interface->addHorizontalSlider("Mode4", &fHslider10, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(3.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider0, "enum", "Compress|Bypass|Mute");
		ui_interface->declare(&fHslider0, "tooltip", "Compress or Mute the selected band, or Bypass The Compressor");
		ui_interface->addHorizontalSlider("Mode5", &fHslider0, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(3.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider31, "5", "");
		ui_interface->declare(&fHslider31, "tooltip", "Post amplification and threshold");
		ui_interface->addHorizontalSlider("Makeup1", &fHslider31, FAUSTFLOAT(13.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(5e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider25, "5", "");
		ui_interface->declare(&fHslider25, "tooltip", "Post amplification and threshold");
		ui_interface->addHorizontalSlider("Makeup2", &fHslider25, FAUSTFLOAT(1e+01), FAUSTFLOAT(-5e+01), FAUSTFLOAT(5e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider19, "5", "");
		ui_interface->declare(&fHslider19, "tooltip", "Post amplification and threshold");
		ui_interface->addHorizontalSlider("Makeup3", &fHslider19, FAUSTFLOAT(4.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(5e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider13, "5", "");
		ui_interface->declare(&fHslider13, "tooltip", "Post amplification and threshold");
		ui_interface->addHorizontalSlider("Makeup4", &fHslider13, FAUSTFLOAT(8.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(5e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider7, "5", "");
		ui_interface->declare(&fHslider7, "tooltip", "Post amplification and threshold");
		ui_interface->addHorizontalSlider("Makeup5", &fHslider7, FAUSTFLOAT(11.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(5e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider33, "6", "");
		ui_interface->declare(&fHslider33, "tooltip", "Threshold correction, an anticlip measure");
		ui_interface->addHorizontalSlider("Makeup-Threshold1", &fHslider33, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider27, "6", "");
		ui_interface->declare(&fHslider27, "tooltip", "Threshold correction, an anticlip measure");
		ui_interface->addHorizontalSlider("Makeup-Threshold2", &fHslider27, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider21, "6", "");
		ui_interface->declare(&fHslider21, "tooltip", "Threshold correction, an anticlip measure");
		ui_interface->addHorizontalSlider("Makeup-Threshold3", &fHslider21, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider15, "6", "");
		ui_interface->declare(&fHslider15, "tooltip", "Threshold correction, an anticlip measure");
		ui_interface->addHorizontalSlider("Makeup-Threshold4", &fHslider15, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider9, "6", "");
		ui_interface->declare(&fHslider9, "tooltip", "Threshold correction, an anticlip measure");
		ui_interface->addHorizontalSlider("Makeup-Threshold5", &fHslider9, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider32, "9", "");
		ui_interface->declare(&fHslider32, "tooltip", "Compression ratio");
		ui_interface->addHorizontalSlider("Ratio1", &fHslider32, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider26, "9", "");
		ui_interface->declare(&fHslider26, "tooltip", "Compression ratio");
		ui_interface->addHorizontalSlider("Ratio2", &fHslider26, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider20, "9", "");
		ui_interface->declare(&fHslider20, "tooltip", "Compression ratio");
		ui_interface->addHorizontalSlider("Ratio3", &fHslider20, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider14, "9", "");
		ui_interface->declare(&fHslider14, "tooltip", "Compression ratio");
		ui_interface->addHorizontalSlider("Ratio4", &fHslider14, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider8, "9", "");
		ui_interface->declare(&fHslider8, "tooltip", "Compression ratio");
		ui_interface->addHorizontalSlider("Ratio5", &fHslider8, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider29, "A", "");
		ui_interface->declare(&fHslider29, "tooltip", "Time before the compressor starts to kick in");
		ui_interface->addHorizontalSlider("Attack1", &fHslider29, FAUSTFLOAT(0.012), FAUSTFLOAT(0.001), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fHslider23, "A", "");
		ui_interface->declare(&fHslider23, "tooltip", "Time before the compressor starts to kick in");
		ui_interface->addHorizontalSlider("Attack2", &fHslider23, FAUSTFLOAT(0.012), FAUSTFLOAT(0.001), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fHslider17, "A", "");
		ui_interface->declare(&fHslider17, "tooltip", "Time before the compressor starts to kick in");
		ui_interface->addHorizontalSlider("Attack3", &fHslider17, FAUSTFLOAT(0.012), FAUSTFLOAT(0.001), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fHslider11, "A", "");
		ui_interface->declare(&fHslider11, "tooltip", "Time before the compressor starts to kick in");
		ui_interface->addHorizontalSlider("Attack4", &fHslider11, FAUSTFLOAT(0.012), FAUSTFLOAT(0.001), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fHslider1, "A", "");
		ui_interface->declare(&fHslider1, "tooltip", "Time before the compressor starts to kick in");
		ui_interface->addHorizontalSlider("Attack5", &fHslider1, FAUSTFLOAT(0.012), FAUSTFLOAT(0.001), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fHslider30, "B", "");
		ui_interface->declare(&fHslider30, "tooltip", "Time before the compressor releases the sound");
		ui_interface->addHorizontalSlider("Release1", &fHslider30, FAUSTFLOAT(1.25), FAUSTFLOAT(0.01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider24, "B", "");
		ui_interface->declare(&fHslider24, "tooltip", "Time before the compressor releases the sound");
		ui_interface->addHorizontalSlider("Release2", &fHslider24, FAUSTFLOAT(1.25), FAUSTFLOAT(0.01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider18, "B", "");
		ui_interface->declare(&fHslider18, "tooltip", "Time before the compressor releases the sound");
		ui_interface->addHorizontalSlider("Release3", &fHslider18, FAUSTFLOAT(1.25), FAUSTFLOAT(0.01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider12, "B", "");
		ui_interface->declare(&fHslider12, "tooltip", "Time before the compressor releases the sound");
		ui_interface->addHorizontalSlider("Release4", &fHslider12, FAUSTFLOAT(1.25), FAUSTFLOAT(0.01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider6, "B", "");
		ui_interface->declare(&fHslider6, "tooltip", "Time before the compressor releases the sound");
		ui_interface->addHorizontalSlider("Release5", &fHslider6, FAUSTFLOAT(1.25), FAUSTFLOAT(0.01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
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
		ui_interface->declare(&fVbargraph4, "log", "");
		ui_interface->declare(&fVbargraph4, "nomidi", "");
		ui_interface->declare(&fVbargraph4, "tooltip", "Sum of Band1");
		ui_interface->addVerticalBargraph("v1", &fVbargraph4, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph3, "log", "");
		ui_interface->declare(&fVbargraph3, "nomidi", "");
		ui_interface->declare(&fVbargraph3, "tooltip", "Sum of Band2");
		ui_interface->addVerticalBargraph("v2", &fVbargraph3, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph2, "log", "");
		ui_interface->declare(&fVbargraph2, "nomidi", "");
		ui_interface->declare(&fVbargraph2, "tooltip", "Sum of Band3");
		ui_interface->addVerticalBargraph("v3", &fVbargraph2, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph1, "log", "");
		ui_interface->declare(&fVbargraph1, "nomidi", "");
		ui_interface->declare(&fVbargraph1, "tooltip", "Sum of Band4");
		ui_interface->addVerticalBargraph("v4", &fVbargraph1, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph0, "log", "");
		ui_interface->declare(&fVbargraph0, "nomidi", "");
		ui_interface->declare(&fVbargraph0, "tooltip", "Sum of Band5");
		ui_interface->addVerticalBargraph("v5", &fVbargraph0, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
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
		double fSlow8 = GxMbcs_faustpower2_f(fSlow7);
		double fSlow9 = 2.0 * (1.0 - 1.0 / fSlow8);
		double fSlow10 = 1.0 / fSlow7;
		double fSlow11 = 1.0 - fSlow10;
		double fSlow12 = 1.0 - fSlow11 / fSlow7;
		double fSlow13 = fSlow10 + 1.0;
		double fSlow14 = 1.0 / (fSlow13 / fSlow7 + 1.0);
		double fSlow15 = std::tan(fConst2 * static_cast<double>(fHslider3));
		double fSlow16 = GxMbcs_faustpower2_f(fSlow15);
		double fSlow17 = 2.0 * (1.0 - 1.0 / fSlow16);
		double fSlow18 = 1.0 / fSlow15;
		double fSlow19 = 1.0 - fSlow18;
		double fSlow20 = 1.0 - fSlow19 / fSlow15;
		double fSlow21 = fSlow18 + 1.0;
		double fSlow22 = 1.0 / (fSlow21 / fSlow15 + 1.0);
		double fSlow23 = std::tan(fConst2 * static_cast<double>(fHslider4));
		double fSlow24 = GxMbcs_faustpower2_f(fSlow23);
		double fSlow25 = 2.0 * (1.0 - 1.0 / fSlow24);
		double fSlow26 = 1.0 / fSlow23;
		double fSlow27 = 1.0 - fSlow26;
		double fSlow28 = 1.0 - fSlow27 / fSlow23;
		double fSlow29 = fSlow26 + 1.0;
		double fSlow30 = 1.0 / (fSlow29 / fSlow23 + 1.0);
		double fSlow31 = std::tan(fConst2 * static_cast<double>(fHslider5));
		double fSlow32 = GxMbcs_faustpower2_f(fSlow31);
		double fSlow33 = 2.0 * (1.0 - 1.0 / fSlow32);
		double fSlow34 = 1.0 / fSlow31;
		double fSlow35 = (fSlow34 + -1.0000000000000004) / fSlow31 + 1.0;
		double fSlow36 = (fSlow34 + 1.0000000000000004) / fSlow31 + 1.0;
		double fSlow37 = 1.0 / fSlow36;
		double fSlow38 = 1.0 - fSlow34;
		double fSlow39 = 1.0 / (fSlow34 + 1.0);
		double fSlow40 = 1.0 / (fSlow32 * fSlow36);
		double fSlow41 = static_cast<double>(fHslider6);
		int iSlow42 = std::fabs(fSlow41) < 2.220446049250313e-16;
		double fSlow43 = ((iSlow42) ? 0.0 : std::exp(-(fConst1 / ((iSlow42) ? 1.0 : fSlow41))));
		int iSlow44 = std::fabs(fSlow3) < 2.220446049250313e-16;
		double fSlow45 = ((iSlow44) ? 0.0 : std::exp(-(fConst1 / ((iSlow44) ? 1.0 : fSlow3))));
		double fSlow46 = static_cast<double>(fHslider7);
		double fSlow47 = 1.0 - fSlow6;
		double fSlow48 = 1.0 / std::max<double>(2.220446049250313e-16, static_cast<double>(fHslider8)) + -1.0;
		double fSlow49 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (fSlow46 - static_cast<double>(fHslider9)) * std::fabs(fSlow1 + -1.0));
		double fSlow50 = std::fabs(std::max<double>(0.0, fSlow0 + -2.0) + -1.0);
		double fSlow51 = static_cast<double>(fHslider10);
		double fSlow52 = std::max<double>(0.0, fSlow51 + -1.0);
		int iSlow53 = static_cast<int>(fSlow52);
		double fSlow54 = static_cast<double>(fHslider11);
		double fSlow55 = 0.5 * fSlow54;
		int iSlow56 = std::fabs(fSlow55) < 2.220446049250313e-16;
		double fSlow57 = ((iSlow56) ? 0.0 : std::exp(-(fConst1 / ((iSlow56) ? 1.0 : fSlow55))));
		double fSlow58 = (fSlow26 + -1.0000000000000004) / fSlow23 + 1.0;
		double fSlow59 = (fSlow26 + 1.0000000000000004) / fSlow23 + 1.0;
		double fSlow60 = 1.0 / fSlow59;
		double fSlow61 = 1.0 / fSlow29;
		double fSlow62 = 1.0 / (fSlow24 * fSlow59);
		double fSlow63 = static_cast<double>(fHslider12);
		int iSlow64 = std::fabs(fSlow63) < 2.220446049250313e-16;
		double fSlow65 = ((iSlow64) ? 0.0 : std::exp(-(fConst1 / ((iSlow64) ? 1.0 : fSlow63))));
		int iSlow66 = std::fabs(fSlow54) < 2.220446049250313e-16;
		double fSlow67 = ((iSlow66) ? 0.0 : std::exp(-(fConst1 / ((iSlow66) ? 1.0 : fSlow54))));
		double fSlow68 = static_cast<double>(fHslider13);
		double fSlow69 = 1.0 - fSlow57;
		double fSlow70 = 1.0 / std::max<double>(2.220446049250313e-16, static_cast<double>(fHslider14)) + -1.0;
		double fSlow71 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (fSlow68 - static_cast<double>(fHslider15)) * std::fabs(fSlow52 + -1.0));
		double fSlow72 = std::fabs(std::max<double>(0.0, fSlow51 + -2.0) + -1.0);
		double fSlow73 = static_cast<double>(fHslider16);
		double fSlow74 = std::max<double>(0.0, fSlow73 + -1.0);
		int iSlow75 = static_cast<int>(fSlow74);
		double fSlow76 = static_cast<double>(fHslider17);
		double fSlow77 = 0.5 * fSlow76;
		int iSlow78 = std::fabs(fSlow77) < 2.220446049250313e-16;
		double fSlow79 = ((iSlow78) ? 0.0 : std::exp(-(fConst1 / ((iSlow78) ? 1.0 : fSlow77))));
		double fSlow80 = (fSlow18 + -1.0000000000000004) / fSlow15 + 1.0;
		double fSlow81 = (fSlow18 + 1.0000000000000004) / fSlow15 + 1.0;
		double fSlow82 = 1.0 / fSlow81;
		double fSlow83 = 1.0 / fSlow21;
		double fSlow84 = 1.0 / (fSlow16 * fSlow81);
		double fSlow85 = static_cast<double>(fHslider18);
		int iSlow86 = std::fabs(fSlow85) < 2.220446049250313e-16;
		double fSlow87 = ((iSlow86) ? 0.0 : std::exp(-(fConst1 / ((iSlow86) ? 1.0 : fSlow85))));
		int iSlow88 = std::fabs(fSlow76) < 2.220446049250313e-16;
		double fSlow89 = ((iSlow88) ? 0.0 : std::exp(-(fConst1 / ((iSlow88) ? 1.0 : fSlow76))));
		double fSlow90 = static_cast<double>(fHslider19);
		double fSlow91 = 1.0 - fSlow79;
		double fSlow92 = 1.0 / std::max<double>(2.220446049250313e-16, static_cast<double>(fHslider20)) + -1.0;
		double fSlow93 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (fSlow90 - static_cast<double>(fHslider21)) * std::fabs(fSlow74 + -1.0));
		double fSlow94 = std::fabs(std::max<double>(0.0, fSlow73 + -2.0) + -1.0);
		double fSlow95 = static_cast<double>(fHslider22);
		double fSlow96 = std::max<double>(0.0, fSlow95 + -1.0);
		int iSlow97 = static_cast<int>(fSlow96);
		double fSlow98 = static_cast<double>(fHslider23);
		double fSlow99 = 0.5 * fSlow98;
		int iSlow100 = std::fabs(fSlow99) < 2.220446049250313e-16;
		double fSlow101 = ((iSlow100) ? 0.0 : std::exp(-(fConst1 / ((iSlow100) ? 1.0 : fSlow99))));
		double fSlow102 = (fSlow10 + -1.0000000000000004) / fSlow7 + 1.0;
		double fSlow103 = (fSlow10 + 1.0000000000000004) / fSlow7 + 1.0;
		double fSlow104 = 1.0 / fSlow103;
		double fSlow105 = 1.0 / fSlow13;
		double fSlow106 = 1.0 / (fSlow8 * fSlow103);
		double fSlow107 = static_cast<double>(fHslider24);
		int iSlow108 = std::fabs(fSlow107) < 2.220446049250313e-16;
		double fSlow109 = ((iSlow108) ? 0.0 : std::exp(-(fConst1 / ((iSlow108) ? 1.0 : fSlow107))));
		int iSlow110 = std::fabs(fSlow98) < 2.220446049250313e-16;
		double fSlow111 = ((iSlow110) ? 0.0 : std::exp(-(fConst1 / ((iSlow110) ? 1.0 : fSlow98))));
		double fSlow112 = static_cast<double>(fHslider25);
		double fSlow113 = 1.0 - fSlow101;
		double fSlow114 = 1.0 / std::max<double>(2.220446049250313e-16, static_cast<double>(fHslider26)) + -1.0;
		double fSlow115 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (fSlow112 - static_cast<double>(fHslider27)) * std::fabs(fSlow96 + -1.0));
		double fSlow116 = std::fabs(std::max<double>(0.0, fSlow95 + -2.0) + -1.0);
		double fSlow117 = static_cast<double>(fHslider28);
		double fSlow118 = std::max<double>(0.0, fSlow117 + -1.0);
		int iSlow119 = static_cast<int>(fSlow118);
		double fSlow120 = static_cast<double>(fHslider29);
		double fSlow121 = 0.5 * fSlow120;
		int iSlow122 = std::fabs(fSlow121) < 2.220446049250313e-16;
		double fSlow123 = ((iSlow122) ? 0.0 : std::exp(-(fConst1 / ((iSlow122) ? 1.0 : fSlow121))));
		double fSlow124 = static_cast<double>(fHslider30);
		int iSlow125 = std::fabs(fSlow124) < 2.220446049250313e-16;
		double fSlow126 = ((iSlow125) ? 0.0 : std::exp(-(fConst1 / ((iSlow125) ? 1.0 : fSlow124))));
		int iSlow127 = std::fabs(fSlow120) < 2.220446049250313e-16;
		double fSlow128 = ((iSlow127) ? 0.0 : std::exp(-(fConst1 / ((iSlow127) ? 1.0 : fSlow120))));
		double fSlow129 = static_cast<double>(fHslider31);
		double fSlow130 = 1.0 - fSlow123;
		double fSlow131 = 1.0 / std::max<double>(2.220446049250313e-16, static_cast<double>(fHslider32)) + -1.0;
		double fSlow132 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (fSlow129 - static_cast<double>(fHslider33)) * std::fabs(fSlow118 + -1.0));
		double fSlow133 = std::fabs(std::max<double>(0.0, fSlow117 + -2.0) + -1.0);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			int iTemp0 = iRec1[1] < 4096;
			double fTemp1 = fSlow9 * fRec5[1];
			double fTemp2 = fSlow17 * fRec6[1];
			double fTemp3 = fSlow25 * fRec7[1];
			double fTemp4 = static_cast<double>(input0[i0]);
			fVec0[0] = fTemp4;
			fRec9[0] = -(fSlow39 * (fSlow38 * fRec9[1] - fSlow34 * (fTemp4 - fVec0[1])));
			fRec8[0] = fRec9[0] - fSlow37 * (fSlow35 * fRec8[2] + fSlow33 * fRec8[1]);
			fRec7[0] = fSlow40 * (fRec8[2] + (fRec8[0] - 2.0 * fRec8[1])) - fSlow30 * (fSlow28 * fRec7[2] + fTemp3);
			fRec6[0] = fRec7[2] + fSlow30 * (fTemp3 + fSlow28 * fRec7[0]) - fSlow22 * (fSlow20 * fRec6[2] + fTemp2);
			fRec5[0] = fRec6[2] + fSlow22 * (fTemp2 + fSlow20 * fRec6[0]) - fSlow14 * (fSlow12 * fRec5[2] + fTemp1);
			double fTemp5 = fRec5[2] + fSlow14 * (fTemp1 + fSlow12 * fRec5[0]);
			double fTemp6 = ((iSlow2) ? 0.0 : fTemp5);
			double fTemp7 = std::fabs(2.0 * std::fabs(fTemp6));
			double fTemp8 = ((fTemp7 > fRec4[1]) ? fSlow45 : fSlow43);
			fRec4[0] = fTemp7 * (1.0 - fTemp8) + fRec4[1] * fTemp8;
			fRec3[0] = fSlow48 * fSlow47 * std::max<double>(fSlow46 + 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec4[0])), 0.0) + fSlow6 * fRec3[1];
			fRec10[0] = fSlow49 + 0.999 * fRec10[1];
			double fTemp9 = fSlow50 * fRec10[0] * ((iSlow2) ? fTemp5 : fTemp6 * std::pow(1e+01, 0.05 * fRec3[0]));
			double fTemp10 = std::max<double>(fConst1, 2.0 * std::fabs(fTemp9));
			fRec0[0] = ((iTemp0) ? fTemp10 + fRec0[1] : fTemp10);
			iRec1[0] = ((iTemp0) ? faust_wrap_add(iRec1[1], 1) : 1);
			fRec2[0] = ((iTemp0) ? fRec2[1] : 0.000244140625 * fRec0[1]);
			fVbargraph0 = static_cast<FAUSTFLOAT>(0.5 * fRec2[0]);
			double fTemp11 = fSlow9 * fRec13[1];
			double fTemp12 = fSlow17 * fRec14[1];
			fRec18[0] = -(fSlow39 * (fSlow38 * fRec18[1] - (fTemp4 + fVec0[1])));
			fRec17[0] = fRec18[0] - fSlow37 * (fSlow35 * fRec17[2] + fSlow33 * fRec17[1]);
			double fTemp13 = fSlow37 * (fRec17[2] + fRec17[0] + 2.0 * fRec17[1]);
			fVec1[0] = fTemp13;
			fRec16[0] = -(fSlow61 * (fSlow27 * fRec16[1] - fSlow26 * (fTemp13 - fVec1[1])));
			fRec15[0] = fRec16[0] - fSlow60 * (fSlow58 * fRec15[2] + fSlow25 * fRec15[1]);
			fRec14[0] = fSlow62 * (fRec15[2] + (fRec15[0] - 2.0 * fRec15[1])) - fSlow22 * (fSlow20 * fRec14[2] + fTemp12);
			fRec13[0] = fRec14[2] + fSlow22 * (fTemp12 + fSlow20 * fRec14[0]) - fSlow14 * (fSlow12 * fRec13[2] + fTemp11);
			double fTemp14 = fRec13[2] + fSlow14 * (fTemp11 + fSlow12 * fRec13[0]);
			double fTemp15 = ((iSlow53) ? 0.0 : fTemp14);
			double fTemp16 = std::fabs(2.0 * std::fabs(fTemp15));
			double fTemp17 = ((fTemp16 > fRec12[1]) ? fSlow67 : fSlow65);
			fRec12[0] = fTemp16 * (1.0 - fTemp17) + fRec12[1] * fTemp17;
			fRec11[0] = fSlow70 * fSlow69 * std::max<double>(fSlow68 + 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec12[0])), 0.0) + fSlow57 * fRec11[1];
			fRec19[0] = fSlow71 + 0.999 * fRec19[1];
			double fTemp18 = fSlow72 * fRec19[0] * ((iSlow53) ? fTemp14 : fTemp15 * std::pow(1e+01, 0.05 * fRec11[0]));
			int iTemp19 = iRec21[1] < 4096;
			double fTemp20 = std::max<double>(fConst1, 2.0 * std::fabs(fTemp18));
			fRec20[0] = ((iTemp19) ? fTemp20 + fRec20[1] : fTemp20);
			iRec21[0] = ((iTemp19) ? faust_wrap_add(iRec21[1], 1) : 1);
			fRec22[0] = ((iTemp19) ? fRec22[1] : 0.000244140625 * fRec20[1]);
			fVbargraph1 = static_cast<FAUSTFLOAT>(0.5 * fRec22[0]);
			double fTemp21 = fSlow9 * fRec25[1];
			fRec29[0] = -(fSlow61 * (fSlow27 * fRec29[1] - (fTemp13 + fVec1[1])));
			fRec28[0] = fRec29[0] - fSlow60 * (fSlow58 * fRec28[2] + fSlow25 * fRec28[1]);
			double fTemp22 = fSlow60 * (fRec28[2] + fRec28[0] + 2.0 * fRec28[1]);
			fVec2[0] = fTemp22;
			fRec27[0] = -(fSlow83 * (fSlow19 * fRec27[1] - fSlow18 * (fTemp22 - fVec2[1])));
			fRec26[0] = fRec27[0] - fSlow82 * (fSlow80 * fRec26[2] + fSlow17 * fRec26[1]);
			fRec25[0] = fSlow84 * (fRec26[2] + (fRec26[0] - 2.0 * fRec26[1])) - fSlow14 * (fSlow12 * fRec25[2] + fTemp21);
			double fTemp23 = fRec25[2] + fSlow14 * (fTemp21 + fSlow12 * fRec25[0]);
			double fTemp24 = ((iSlow75) ? 0.0 : fTemp23);
			double fTemp25 = std::fabs(2.0 * std::fabs(fTemp24));
			double fTemp26 = ((fTemp25 > fRec24[1]) ? fSlow89 : fSlow87);
			fRec24[0] = fTemp25 * (1.0 - fTemp26) + fRec24[1] * fTemp26;
			fRec23[0] = fSlow92 * fSlow91 * std::max<double>(fSlow90 + 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec24[0])), 0.0) + fSlow79 * fRec23[1];
			fRec30[0] = fSlow93 + 0.999 * fRec30[1];
			double fTemp27 = fSlow94 * fRec30[0] * ((iSlow75) ? fTemp23 : fTemp24 * std::pow(1e+01, 0.05 * fRec23[0]));
			int iTemp28 = iRec32[1] < 4096;
			double fTemp29 = std::max<double>(fConst1, 2.0 * std::fabs(fTemp27));
			fRec31[0] = ((iTemp28) ? fTemp29 + fRec31[1] : fTemp29);
			iRec32[0] = ((iTemp28) ? faust_wrap_add(iRec32[1], 1) : 1);
			fRec33[0] = ((iTemp28) ? fRec33[1] : 0.000244140625 * fRec31[1]);
			fVbargraph2 = static_cast<FAUSTFLOAT>(0.5 * fRec33[0]);
			fRec39[0] = -(fSlow83 * (fSlow19 * fRec39[1] - (fTemp22 + fVec2[1])));
			fRec38[0] = fRec39[0] - fSlow82 * (fSlow80 * fRec38[2] + fSlow17 * fRec38[1]);
			double fTemp30 = fSlow82 * (fRec38[2] + fRec38[0] + 2.0 * fRec38[1]);
			fVec3[0] = fTemp30;
			fRec37[0] = -(fSlow105 * (fSlow11 * fRec37[1] - fSlow10 * (fTemp30 - fVec3[1])));
			fRec36[0] = fRec37[0] - fSlow104 * (fSlow102 * fRec36[2] + fSlow9 * fRec36[1]);
			double fTemp31 = fSlow106 * (fRec36[2] + (fRec36[0] - 2.0 * fRec36[1]));
			double fTemp32 = ((iSlow97) ? 0.0 : fTemp31);
			double fTemp33 = std::fabs(2.0 * std::fabs(fTemp32));
			double fTemp34 = ((fTemp33 > fRec35[1]) ? fSlow111 : fSlow109);
			fRec35[0] = fTemp33 * (1.0 - fTemp34) + fRec35[1] * fTemp34;
			fRec34[0] = fSlow114 * fSlow113 * std::max<double>(fSlow112 + 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec35[0])), 0.0) + fSlow101 * fRec34[1];
			fRec40[0] = fSlow115 + 0.999 * fRec40[1];
			double fTemp35 = fSlow116 * fRec40[0] * ((iSlow97) ? fTemp31 : fTemp32 * std::pow(1e+01, 0.05 * fRec34[0]));
			int iTemp36 = iRec42[1] < 4096;
			double fTemp37 = std::max<double>(fConst1, 2.0 * std::fabs(fTemp35));
			fRec41[0] = ((iTemp36) ? fTemp37 + fRec41[1] : fTemp37);
			iRec42[0] = ((iTemp36) ? faust_wrap_add(iRec42[1], 1) : 1);
			fRec43[0] = ((iTemp36) ? fRec43[1] : 0.000244140625 * fRec41[1]);
			fVbargraph3 = static_cast<FAUSTFLOAT>(0.5 * fRec43[0]);
			fRec47[0] = -(fSlow105 * (fSlow11 * fRec47[1] - (fTemp30 + fVec3[1])));
			fRec46[0] = fRec47[0] - fSlow104 * (fSlow102 * fRec46[2] + fSlow9 * fRec46[1]);
			double fTemp38 = fSlow104 * (fRec46[2] + fRec46[0] + 2.0 * fRec46[1]);
			double fTemp39 = ((iSlow119) ? 0.0 : fTemp38);
			double fTemp40 = std::fabs(2.0 * std::fabs(fTemp39));
			double fTemp41 = ((fTemp40 > fRec45[1]) ? fSlow128 : fSlow126);
			fRec45[0] = fTemp40 * (1.0 - fTemp41) + fRec45[1] * fTemp41;
			fRec44[0] = fSlow131 * fSlow130 * std::max<double>(fSlow129 + 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec45[0])), 0.0) + fSlow123 * fRec44[1];
			fRec48[0] = fSlow132 + 0.999 * fRec48[1];
			double fTemp42 = fSlow133 * fRec48[0] * ((iSlow119) ? fTemp38 : fTemp39 * std::pow(1e+01, 0.05 * fRec44[0]));
			int iTemp43 = iRec50[1] < 4096;
			double fTemp44 = std::max<double>(fConst1, 2.0 * std::fabs(fTemp42));
			fRec49[0] = ((iTemp43) ? fTemp44 + fRec49[1] : fTemp44);
			iRec50[0] = ((iTemp43) ? faust_wrap_add(iRec50[1], 1) : 1);
			fRec51[0] = ((iTemp43) ? fRec51[1] : 0.000244140625 * fRec49[1]);
			fVbargraph4 = static_cast<FAUSTFLOAT>(0.5 * fRec51[0]);
			output0[i0] = static_cast<FAUSTFLOAT>(0.5 * (fTemp42 + fTemp42 + fTemp35 + fTemp35 + fTemp27 + fTemp27 + fTemp18 + fTemp18 + fTemp9 + fTemp9));
			fVec0[1] = fVec0[0];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec10[1] = fRec10[0];
			fRec0[1] = fRec0[0];
			iRec1[1] = iRec1[0];
			fRec2[1] = fRec2[0];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fVec1[1] = fVec1[0];
			fRec16[1] = fRec16[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
			iRec21[1] = iRec21[0];
			fRec22[1] = fRec22[0];
			fRec29[1] = fRec29[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fVec2[1] = fVec2[0];
			fRec27[1] = fRec27[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec30[1] = fRec30[0];
			fRec31[1] = fRec31[0];
			iRec32[1] = iRec32[0];
			fRec33[1] = fRec33[0];
			fRec39[1] = fRec39[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fVec3[1] = fVec3[0];
			fRec37[1] = fRec37[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			iRec42[1] = iRec42[0];
			fRec43[1] = fRec43[0];
			fRec47[1] = fRec47[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec48[1] = fRec48[0];
			fRec49[1] = fRec49[0];
			iRec50[1] = iRec50[0];
			fRec51[1] = fRec51[0];
		}
	}

};

#endif
