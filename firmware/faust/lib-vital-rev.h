/* ------------------------------------------------------------
author: "David Braun (Faust port), Matt Tytel (Vital)"
license: "GPL-3.0-only"
name: "Vital Reverb"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibVitalRev -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibVitalRev_H__
#define  __LibVitalRev_H__

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
#define FAUSTCLASS LibVitalRev
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

static float LibVitalRev_faustpower2_f(float value) {
	return value * value;
}

class LibVitalRev : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec19[2];
	FAUSTFLOAT fHslider2;
	float fRec20[2];
	FAUSTFLOAT fHslider3;
	float fRec21[2];
	FAUSTFLOAT fHslider4;
	float fRec23[2];
	float fConst3;
	FAUSTFLOAT fHslider5;
	float fRec24[2];
	FAUSTFLOAT fHslider6;
	float fRec26[2];
	float fRec25[2];
	float fRec27[2];
	float fVec1[2];
	float fRec22[2];
	float fRec28[2];
	int IOTA0;
	float fVec2[131072];
	float fConst4;
	FAUSTFLOAT fHslider7;
	float fRec30[2];
	float fConst5;
	float fRec29[2];
	FAUSTFLOAT fHslider8;
	float fRec31[2];
	FAUSTFLOAT fHslider9;
	float fRec33[2];
	FAUSTFLOAT fHslider10;
	float fRec35[2];
	float fVec3[65536];
	float fConst6;
	FAUSTFLOAT fHslider11;
	float fRec36[2];
	float fVec4[2];
	float fRec34[2];
	float fRec32[2];
	float fVec5[1024];
	float fRec17[2];
	float fRec40[2];
	float fRec41[2];
	float fVec6[2];
	float fRec39[2];
	float fRec42[2];
	float fVec7[131072];
	float fRec43[2];
	float fVec8[1024];
	float fRec37[2];
	float fRec47[2];
	float fRec48[2];
	float fVec9[2];
	float fRec46[2];
	float fRec49[2];
	float fVec10[131072];
	float fRec50[2];
	float fVec11[1024];
	float fRec44[2];
	float fRec54[2];
	float fRec55[2];
	float fVec12[2];
	float fRec53[2];
	float fRec56[2];
	float fVec13[131072];
	float fRec57[2];
	float fVec14[1024];
	float fRec51[2];
	float fRec61[2];
	float fRec62[2];
	float fVec15[2];
	float fRec60[2];
	float fRec63[2];
	float fVec16[131072];
	float fVec17[1024];
	float fRec58[2];
	float fRec67[2];
	float fRec68[2];
	float fVec18[2];
	float fRec66[2];
	float fRec69[2];
	float fVec19[65536];
	float fRec70[2];
	float fVec20[1024];
	float fRec64[2];
	float fRec74[2];
	float fRec75[2];
	float fVec21[2];
	float fRec73[2];
	float fRec76[2];
	float fVec22[65536];
	float fVec23[1024];
	float fRec71[2];
	float fRec80[2];
	float fRec81[2];
	float fVec24[2];
	float fRec79[2];
	float fRec82[2];
	float fVec25[131072];
	float fVec26[1024];
	float fRec77[2];
	float fRec86[2];
	float fRec87[2];
	float fVec27[2];
	float fRec85[2];
	float fRec88[2];
	float fVec28[65536];
	float fRec89[2];
	float fVec29[1024];
	float fRec83[2];
	float fRec93[2];
	float fRec94[2];
	float fVec30[2];
	float fRec92[2];
	float fRec95[2];
	float fVec31[131072];
	float fVec32[1024];
	float fRec90[2];
	float fRec99[2];
	float fRec100[2];
	float fVec33[2];
	float fRec98[2];
	float fRec101[2];
	float fVec34[131072];
	float fVec35[1024];
	float fRec96[2];
	float fRec105[2];
	float fRec106[2];
	float fVec36[2];
	float fRec104[2];
	float fRec107[2];
	float fVec37[65536];
	float fRec108[2];
	float fVec38[1024];
	float fRec102[2];
	float fRec112[2];
	float fRec113[2];
	float fVec39[2];
	float fRec111[2];
	float fRec114[2];
	float fVec40[131072];
	float fVec41[1024];
	float fRec109[2];
	float fRec118[2];
	float fRec119[2];
	float fVec42[2];
	float fRec117[2];
	float fRec120[2];
	float fVec43[131072];
	float fVec44[1024];
	float fRec115[2];
	float fRec124[2];
	float fRec125[2];
	float fVec45[2];
	float fRec123[2];
	float fRec126[2];
	float fVec46[131072];
	float fRec127[2];
	float fVec47[1024];
	float fRec121[2];
	float fRec131[2];
	float fRec132[2];
	float fVec48[2];
	float fRec130[2];
	float fRec133[2];
	float fVec49[131072];
	float fVec50[1024];
	float fRec128[2];
	float fRec1[3];
	float fRec2[3];
	float fRec3[3];
	float fRec4[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	float fRec8[3];
	float fRec9[3];
	float fRec10[3];
	float fRec11[3];
	float fRec12[3];
	float fRec13[3];
	float fRec14[3];
	float fRec15[3];
	float fRec16[3];
	
 public:
	LibVitalRev() {
	}
	
	LibVitalRev(const LibVitalRev&) = default;
	
	virtual ~LibVitalRev() = default;
	
	LibVitalRev& operator=(const LibVitalRev&) = default;
	
	void metadata(Meta* m) { 
		m->declare("aanl.lib/clip:deprecated", "internal helper, renamed _clip");
		m->declare("aanl.lib/name", "Faust Antialiased Nonlinearities");
		m->declare("aanl.lib/version", "1.5.0");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "David Braun (Faust port), Matt Tytel (Vital)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibVitalRev -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/fdelayltv:author", "Julius O. Smith III");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Matt Tytel's Vital synth reverb: pre-filter, shelving, chorused FDN tail");
		m->declare("family", "reverb");
		m->declare("filename", "lib-vital-rev.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/highshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/version", "1.9.0");
		m->declare("interpolators.lib/interpolate_linear:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolate_linear:licence", "MIT");
		m->declare("interpolators.lib/name", "Faust Interpolator Library");
		m->declare("interpolators.lib/remap:author", "David Braun");
		m->declare("interpolators.lib/version", "1.6.0");
		m->declare("license", "GPL-3.0-only");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/dryWetMixerConstantPower:author", "David Braun, revised by Stéphane Letz");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "Vital Reverb");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.5.1");
		m->declare("reverbs.lib/vital_rev:author", "David Braun");
		m->declare("reverbs.lib/vital_rev:license", "GPL-3.0-only");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/reverbs.lib re.vital_rev");
		m->declare("spats.lib/name", "Faust Spatialization Library");
		m->declare("spats.lib/version", "1.3.0");
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
		fConst3 = 1382.3008f / fConst0;
		fConst4 = 0.62716556f * fConst0;
		fConst5 = 1.0f / fConst0;
		fConst6 = 0.3f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.4f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.83f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.62f);
		fHslider5 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider6 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider7 = static_cast<FAUSTFLOAT>(0.1f);
		fHslider8 = static_cast<FAUSTFLOAT>(0.01f);
		fHslider9 = static_cast<FAUSTFLOAT>(0.79f);
		fHslider10 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider11 = static_cast<FAUSTFLOAT>(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec19[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec20[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec21[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec23[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec24[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec26[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec25[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec27[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fVec1[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec22[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec28[l12] = 0.0f;
		}
		IOTA0 = 0;
		for (int l13 = 0; l13 < 131072; l13 = faust_wrap_add(l13, 1)) {
			fVec2[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec30[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec29[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec31[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec33[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec35[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 65536; l19 = faust_wrap_add(l19, 1)) {
			fVec3[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec36[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fVec4[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec34[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec32[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 1024; l24 = faust_wrap_add(l24, 1)) {
			fVec5[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec17[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec40[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec41[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fVec6[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec39[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec42[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 131072; l31 = faust_wrap_add(l31, 1)) {
			fVec7[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec43[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 1024; l33 = faust_wrap_add(l33, 1)) {
			fVec8[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec37[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec47[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec48[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fVec9[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fRec46[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec49[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 131072; l40 = faust_wrap_add(l40, 1)) {
			fVec10[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec50[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 1024; l42 = faust_wrap_add(l42, 1)) {
			fVec11[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec44[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec54[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec55[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fVec12[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fRec53[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec56[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 131072; l49 = faust_wrap_add(l49, 1)) {
			fVec13[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec57[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 1024; l51 = faust_wrap_add(l51, 1)) {
			fVec14[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec51[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fRec61[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fRec62[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			fVec15[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fRec60[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = faust_wrap_add(l57, 1)) {
			fRec63[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 131072; l58 = faust_wrap_add(l58, 1)) {
			fVec16[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 1024; l59 = faust_wrap_add(l59, 1)) {
			fVec17[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = faust_wrap_add(l60, 1)) {
			fRec58[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = faust_wrap_add(l61, 1)) {
			fRec67[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			fRec68[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = faust_wrap_add(l63, 1)) {
			fVec18[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 2; l64 = faust_wrap_add(l64, 1)) {
			fRec66[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 2; l65 = faust_wrap_add(l65, 1)) {
			fRec69[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 65536; l66 = faust_wrap_add(l66, 1)) {
			fVec19[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 2; l67 = faust_wrap_add(l67, 1)) {
			fRec70[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 1024; l68 = faust_wrap_add(l68, 1)) {
			fVec20[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 2; l69 = faust_wrap_add(l69, 1)) {
			fRec64[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2; l70 = faust_wrap_add(l70, 1)) {
			fRec74[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = faust_wrap_add(l71, 1)) {
			fRec75[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = faust_wrap_add(l72, 1)) {
			fVec21[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 2; l73 = faust_wrap_add(l73, 1)) {
			fRec73[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 2; l74 = faust_wrap_add(l74, 1)) {
			fRec76[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 65536; l75 = faust_wrap_add(l75, 1)) {
			fVec22[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 1024; l76 = faust_wrap_add(l76, 1)) {
			fVec23[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 2; l77 = faust_wrap_add(l77, 1)) {
			fRec71[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 2; l78 = faust_wrap_add(l78, 1)) {
			fRec80[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 2; l79 = faust_wrap_add(l79, 1)) {
			fRec81[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 2; l80 = faust_wrap_add(l80, 1)) {
			fVec24[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 2; l81 = faust_wrap_add(l81, 1)) {
			fRec79[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 2; l82 = faust_wrap_add(l82, 1)) {
			fRec82[l82] = 0.0f;
		}
		for (int l83 = 0; l83 < 131072; l83 = faust_wrap_add(l83, 1)) {
			fVec25[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 1024; l84 = faust_wrap_add(l84, 1)) {
			fVec26[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 2; l85 = faust_wrap_add(l85, 1)) {
			fRec77[l85] = 0.0f;
		}
		for (int l86 = 0; l86 < 2; l86 = faust_wrap_add(l86, 1)) {
			fRec86[l86] = 0.0f;
		}
		for (int l87 = 0; l87 < 2; l87 = faust_wrap_add(l87, 1)) {
			fRec87[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 2; l88 = faust_wrap_add(l88, 1)) {
			fVec27[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 2; l89 = faust_wrap_add(l89, 1)) {
			fRec85[l89] = 0.0f;
		}
		for (int l90 = 0; l90 < 2; l90 = faust_wrap_add(l90, 1)) {
			fRec88[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 65536; l91 = faust_wrap_add(l91, 1)) {
			fVec28[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 2; l92 = faust_wrap_add(l92, 1)) {
			fRec89[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 1024; l93 = faust_wrap_add(l93, 1)) {
			fVec29[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 2; l94 = faust_wrap_add(l94, 1)) {
			fRec83[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 2; l95 = faust_wrap_add(l95, 1)) {
			fRec93[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 2; l96 = faust_wrap_add(l96, 1)) {
			fRec94[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 2; l97 = faust_wrap_add(l97, 1)) {
			fVec30[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 2; l98 = faust_wrap_add(l98, 1)) {
			fRec92[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 2; l99 = faust_wrap_add(l99, 1)) {
			fRec95[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 131072; l100 = faust_wrap_add(l100, 1)) {
			fVec31[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 1024; l101 = faust_wrap_add(l101, 1)) {
			fVec32[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 2; l102 = faust_wrap_add(l102, 1)) {
			fRec90[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 2; l103 = faust_wrap_add(l103, 1)) {
			fRec99[l103] = 0.0f;
		}
		for (int l104 = 0; l104 < 2; l104 = faust_wrap_add(l104, 1)) {
			fRec100[l104] = 0.0f;
		}
		for (int l105 = 0; l105 < 2; l105 = faust_wrap_add(l105, 1)) {
			fVec33[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 2; l106 = faust_wrap_add(l106, 1)) {
			fRec98[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 2; l107 = faust_wrap_add(l107, 1)) {
			fRec101[l107] = 0.0f;
		}
		for (int l108 = 0; l108 < 131072; l108 = faust_wrap_add(l108, 1)) {
			fVec34[l108] = 0.0f;
		}
		for (int l109 = 0; l109 < 1024; l109 = faust_wrap_add(l109, 1)) {
			fVec35[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 2; l110 = faust_wrap_add(l110, 1)) {
			fRec96[l110] = 0.0f;
		}
		for (int l111 = 0; l111 < 2; l111 = faust_wrap_add(l111, 1)) {
			fRec105[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 2; l112 = faust_wrap_add(l112, 1)) {
			fRec106[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 2; l113 = faust_wrap_add(l113, 1)) {
			fVec36[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 2; l114 = faust_wrap_add(l114, 1)) {
			fRec104[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 2; l115 = faust_wrap_add(l115, 1)) {
			fRec107[l115] = 0.0f;
		}
		for (int l116 = 0; l116 < 65536; l116 = faust_wrap_add(l116, 1)) {
			fVec37[l116] = 0.0f;
		}
		for (int l117 = 0; l117 < 2; l117 = faust_wrap_add(l117, 1)) {
			fRec108[l117] = 0.0f;
		}
		for (int l118 = 0; l118 < 1024; l118 = faust_wrap_add(l118, 1)) {
			fVec38[l118] = 0.0f;
		}
		for (int l119 = 0; l119 < 2; l119 = faust_wrap_add(l119, 1)) {
			fRec102[l119] = 0.0f;
		}
		for (int l120 = 0; l120 < 2; l120 = faust_wrap_add(l120, 1)) {
			fRec112[l120] = 0.0f;
		}
		for (int l121 = 0; l121 < 2; l121 = faust_wrap_add(l121, 1)) {
			fRec113[l121] = 0.0f;
		}
		for (int l122 = 0; l122 < 2; l122 = faust_wrap_add(l122, 1)) {
			fVec39[l122] = 0.0f;
		}
		for (int l123 = 0; l123 < 2; l123 = faust_wrap_add(l123, 1)) {
			fRec111[l123] = 0.0f;
		}
		for (int l124 = 0; l124 < 2; l124 = faust_wrap_add(l124, 1)) {
			fRec114[l124] = 0.0f;
		}
		for (int l125 = 0; l125 < 131072; l125 = faust_wrap_add(l125, 1)) {
			fVec40[l125] = 0.0f;
		}
		for (int l126 = 0; l126 < 1024; l126 = faust_wrap_add(l126, 1)) {
			fVec41[l126] = 0.0f;
		}
		for (int l127 = 0; l127 < 2; l127 = faust_wrap_add(l127, 1)) {
			fRec109[l127] = 0.0f;
		}
		for (int l128 = 0; l128 < 2; l128 = faust_wrap_add(l128, 1)) {
			fRec118[l128] = 0.0f;
		}
		for (int l129 = 0; l129 < 2; l129 = faust_wrap_add(l129, 1)) {
			fRec119[l129] = 0.0f;
		}
		for (int l130 = 0; l130 < 2; l130 = faust_wrap_add(l130, 1)) {
			fVec42[l130] = 0.0f;
		}
		for (int l131 = 0; l131 < 2; l131 = faust_wrap_add(l131, 1)) {
			fRec117[l131] = 0.0f;
		}
		for (int l132 = 0; l132 < 2; l132 = faust_wrap_add(l132, 1)) {
			fRec120[l132] = 0.0f;
		}
		for (int l133 = 0; l133 < 131072; l133 = faust_wrap_add(l133, 1)) {
			fVec43[l133] = 0.0f;
		}
		for (int l134 = 0; l134 < 1024; l134 = faust_wrap_add(l134, 1)) {
			fVec44[l134] = 0.0f;
		}
		for (int l135 = 0; l135 < 2; l135 = faust_wrap_add(l135, 1)) {
			fRec115[l135] = 0.0f;
		}
		for (int l136 = 0; l136 < 2; l136 = faust_wrap_add(l136, 1)) {
			fRec124[l136] = 0.0f;
		}
		for (int l137 = 0; l137 < 2; l137 = faust_wrap_add(l137, 1)) {
			fRec125[l137] = 0.0f;
		}
		for (int l138 = 0; l138 < 2; l138 = faust_wrap_add(l138, 1)) {
			fVec45[l138] = 0.0f;
		}
		for (int l139 = 0; l139 < 2; l139 = faust_wrap_add(l139, 1)) {
			fRec123[l139] = 0.0f;
		}
		for (int l140 = 0; l140 < 2; l140 = faust_wrap_add(l140, 1)) {
			fRec126[l140] = 0.0f;
		}
		for (int l141 = 0; l141 < 131072; l141 = faust_wrap_add(l141, 1)) {
			fVec46[l141] = 0.0f;
		}
		for (int l142 = 0; l142 < 2; l142 = faust_wrap_add(l142, 1)) {
			fRec127[l142] = 0.0f;
		}
		for (int l143 = 0; l143 < 1024; l143 = faust_wrap_add(l143, 1)) {
			fVec47[l143] = 0.0f;
		}
		for (int l144 = 0; l144 < 2; l144 = faust_wrap_add(l144, 1)) {
			fRec121[l144] = 0.0f;
		}
		for (int l145 = 0; l145 < 2; l145 = faust_wrap_add(l145, 1)) {
			fRec131[l145] = 0.0f;
		}
		for (int l146 = 0; l146 < 2; l146 = faust_wrap_add(l146, 1)) {
			fRec132[l146] = 0.0f;
		}
		for (int l147 = 0; l147 < 2; l147 = faust_wrap_add(l147, 1)) {
			fVec48[l147] = 0.0f;
		}
		for (int l148 = 0; l148 < 2; l148 = faust_wrap_add(l148, 1)) {
			fRec130[l148] = 0.0f;
		}
		for (int l149 = 0; l149 < 2; l149 = faust_wrap_add(l149, 1)) {
			fRec133[l149] = 0.0f;
		}
		for (int l150 = 0; l150 < 131072; l150 = faust_wrap_add(l150, 1)) {
			fVec49[l150] = 0.0f;
		}
		for (int l151 = 0; l151 < 1024; l151 = faust_wrap_add(l151, 1)) {
			fVec50[l151] = 0.0f;
		}
		for (int l152 = 0; l152 < 2; l152 = faust_wrap_add(l152, 1)) {
			fRec128[l152] = 0.0f;
		}
		for (int l153 = 0; l153 < 3; l153 = faust_wrap_add(l153, 1)) {
			fRec1[l153] = 0.0f;
		}
		for (int l154 = 0; l154 < 3; l154 = faust_wrap_add(l154, 1)) {
			fRec2[l154] = 0.0f;
		}
		for (int l155 = 0; l155 < 3; l155 = faust_wrap_add(l155, 1)) {
			fRec3[l155] = 0.0f;
		}
		for (int l156 = 0; l156 < 3; l156 = faust_wrap_add(l156, 1)) {
			fRec4[l156] = 0.0f;
		}
		for (int l157 = 0; l157 < 3; l157 = faust_wrap_add(l157, 1)) {
			fRec5[l157] = 0.0f;
		}
		for (int l158 = 0; l158 < 3; l158 = faust_wrap_add(l158, 1)) {
			fRec6[l158] = 0.0f;
		}
		for (int l159 = 0; l159 < 3; l159 = faust_wrap_add(l159, 1)) {
			fRec7[l159] = 0.0f;
		}
		for (int l160 = 0; l160 < 3; l160 = faust_wrap_add(l160, 1)) {
			fRec8[l160] = 0.0f;
		}
		for (int l161 = 0; l161 < 3; l161 = faust_wrap_add(l161, 1)) {
			fRec9[l161] = 0.0f;
		}
		for (int l162 = 0; l162 < 3; l162 = faust_wrap_add(l162, 1)) {
			fRec10[l162] = 0.0f;
		}
		for (int l163 = 0; l163 < 3; l163 = faust_wrap_add(l163, 1)) {
			fRec11[l163] = 0.0f;
		}
		for (int l164 = 0; l164 < 3; l164 = faust_wrap_add(l164, 1)) {
			fRec12[l164] = 0.0f;
		}
		for (int l165 = 0; l165 < 3; l165 = faust_wrap_add(l165, 1)) {
			fRec13[l165] = 0.0f;
		}
		for (int l166 = 0; l166 < 3; l166 = faust_wrap_add(l166, 1)) {
			fRec14[l166] = 0.0f;
		}
		for (int l167 = 0; l167 < 3; l167 = faust_wrap_add(l167, 1)) {
			fRec15[l167] = 0.0f;
		}
		for (int l168 = 0; l168 < 3; l168 = faust_wrap_add(l168, 1)) {
			fRec16[l168] = 0.0f;
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
	
	virtual LibVitalRev* clone() {
		return new LibVitalRev(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Vital Reverb");
		ui_interface->declare(&fHslider10, "0", "");
		ui_interface->addHorizontalSlider("Pre Low Cut", &fHslider10, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "10", "");
		ui_interface->addHorizontalSlider("Size", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "11", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider0, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider9, "1", "");
		ui_interface->addHorizontalSlider("Pre High Cut", &fHslider9, FAUSTFLOAT(0.79f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider6, "2", "");
		ui_interface->addHorizontalSlider("Low Shelf", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider5, "3", "");
		ui_interface->addHorizontalSlider("Low Gain", &fHslider5, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider4, "4", "");
		ui_interface->addHorizontalSlider("High Shelf", &fHslider4, FAUSTFLOAT(0.62f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "5", "");
		ui_interface->addHorizontalSlider("High Gain", &fHslider3, FAUSTFLOAT(0.83f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider8, "6", "");
		ui_interface->addHorizontalSlider("Chorus Amount", &fHslider8, FAUSTFLOAT(0.01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider7, "7", "");
		ui_interface->addHorizontalSlider("Chorus Rate", &fHslider7, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider11, "8", "");
		ui_interface->addHorizontalSlider("Pre-Delay", &fHslider11, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "9", "");
		ui_interface->addHorizontalSlider("Decay Time", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		float fSlow4 = fConst1 * static_cast<float>(fHslider4);
		float fSlow5 = fConst1 * static_cast<float>(fHslider5);
		float fSlow6 = fConst1 * static_cast<float>(fHslider6);
		float fSlow7 = fConst1 * static_cast<float>(fHslider7);
		float fSlow8 = fConst1 * static_cast<float>(fHslider8);
		float fSlow9 = fConst1 * static_cast<float>(fHslider9);
		float fSlow10 = fConst1 * static_cast<float>(fHslider10);
		float fSlow11 = fConst1 * static_cast<float>(fHslider11);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = 1.5707964f * std::max<float>(0.0f, std::min<float>(1.0f, fRec0[0]));
			float fTemp1 = std::sin(fTemp0);
			fRec19[0] = fSlow1 + fConst2 * fRec19[1];
			fRec20[0] = fSlow2 + fConst2 * fRec20[1];
			float fTemp2 = std::pow(2.0f, 4.0f * std::max<float>(0.0f, std::min<float>(1.0f, fRec20[0])) + -3.0f);
			float fTemp3 = fTemp2 / std::max<float>(0.1f, std::min<float>(1e+02f, std::exp(12.0f * fRec19[0] + -6.0f)));
			fRec21[0] = fSlow3 + fConst2 * fRec21[1];
			float fTemp4 = std::pow(1e+01f, -(1.2f * (1.0f - std::max<float>(0.0f, std::min<float>(1.0f, fRec21[0])))));
			fRec23[0] = fSlow4 + fConst2 * fRec23[1];
			float fTemp5 = std::tan(fConst3 * std::pow(2.0f, 0.083333336f * (119.0f * std::max<float>(0.0f, std::min<float>(1.0f, fRec23[0])) + -53.0f)));
			float fTemp6 = 1.0f / fTemp5;
			float fTemp7 = fTemp6 + 1.0f;
			fRec24[0] = fSlow5 + fConst2 * fRec24[1];
			float fTemp8 = std::pow(1e+01f, -(1.2f * (1.0f - std::max<float>(0.0f, std::min<float>(1.0f, fRec24[0])))));
			fRec26[0] = fSlow6 + fConst2 * fRec26[1];
			float fTemp9 = std::tan(fConst3 * std::pow(2.0f, 0.083333336f * (119.0f * std::max<float>(0.0f, std::min<float>(1.0f, fRec26[0])) + -53.0f)));
			float fTemp10 = 1.0f / fTemp9;
			float fTemp11 = fTemp10 + 1.0f;
			float fTemp12 = 1.0f - fTemp10;
			fRec25[0] = -((fTemp12 * fRec25[1] - (fRec2[1] + fRec2[2])) / fTemp11);
			fRec27[0] = -((fTemp12 * fRec27[1] - (fRec2[1] - fRec2[2]) / fTemp9) / fTemp11);
			float fTemp13 = fRec27[0] + fRec25[0] * fTemp8;
			fVec1[0] = fTemp13;
			float fTemp14 = 1.0f - fTemp6;
			fRec22[0] = -((fTemp14 * fRec22[1] - (fTemp13 - fVec1[1]) / fTemp5) / fTemp7);
			fRec28[0] = -((fTemp14 * fRec28[1] - (fTemp13 + fVec1[1])) / fTemp7);
			float fTemp15 = (fRec28[0] + fRec22[0] * fTemp4) * std::pow(0.001f, 0.21039456f * fTemp3);
			fVec2[IOTA0 & 131071] = fTemp15;
			int iTemp16 = faust_wrap_sub(1, iVec0[1]);
			fRec30[0] = fSlow7 + fConst2 * fRec30[1];
			float fTemp17 = fConst5 * std::min<float>(16.0f, std::exp(11.0f * fRec30[0] + -8.0f));
			float fTemp18 = ((iTemp16) ? 0.3125f : fTemp17 + fRec29[1]);
			fRec29[0] = fTemp18 - std::floor(fTemp18);
			fRec31[0] = fSlow8 + fConst2 * fRec31[1];
			float fTemp19 = LibVitalRev_faustpower2_f(std::max<float>(0.0f, std::min<float>(1.0f, fRec31[0])));
			float fTemp20 = 0.05668934f * fTemp19 * std::sin(6.2831855f * fRec29[0]);
			float fTemp21 = std::max<float>(1.0f, fConst0 * fTemp2 * (fTemp20 + 0.21039456f));
			float fTemp22 = fTemp21 + -0.999995f;
			int iTemp23 = static_cast<int>(fTemp22);
			float fTemp24 = std::floor(fTemp22);
			float fTemp25 = fTemp21 + (-1.0f - fTemp24);
			float fTemp26 = fTemp21 - fTemp24;
			float fTemp27 = fTemp26 * fTemp25;
			float fTemp28 = fTemp21 + (-2.0f - fTemp24);
			fRec33[0] = fSlow9 + fConst2 * fRec33[1];
			float fTemp29 = 1.0f / std::tan(fConst3 * std::pow(2.0f, 0.083333336f * (119.0f * std::max<float>(0.0f, std::min<float>(1.0f, fRec33[0])) + -53.0f)));
			fRec35[0] = fSlow10 + fConst2 * fRec35[1];
			float fTemp30 = std::tan(fConst3 * std::pow(2.0f, 0.083333336f * (119.0f * std::max<float>(0.0f, std::min<float>(1.0f, fRec35[0])) + -53.0f)));
			float fTemp31 = 1.0f / fTemp30;
			float fTemp32 = static_cast<float>(input0[i0]);
			fVec3[IOTA0 & 65535] = fTemp32;
			fRec36[0] = fSlow11 + fConst2 * fRec36[1];
			float fTemp33 = std::max<float>(1.0f, fConst6 * std::max<float>(0.0f, std::min<float>(1.0f, fRec36[0])));
			float fTemp34 = fTemp33 + -0.999995f;
			int iTemp35 = static_cast<int>(fTemp34);
			float fTemp36 = std::floor(fTemp34);
			float fTemp37 = fTemp33 + (-2.0f - fTemp36);
			float fTemp38 = fTemp33 + (-1.0f - fTemp36);
			float fTemp39 = fTemp33 - fTemp36;
			float fTemp40 = fTemp39 * fTemp38;
			float fTemp41 = (fTemp33 + (-3.0f - fTemp36)) * (fTemp37 * (0.5f * fTemp39 * fVec3[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst6, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp35, 1))))))) & 65535] - 0.16666667f * fVec3[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst6, static_cast<float>(std::max<int>(0, iTemp35)))))) & 65535] * fTemp38) - 0.5f * fTemp40 * fVec3[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst6, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp35, 2))))))) & 65535]) + 0.16666667f * fTemp40 * fTemp37 * fVec3[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst6, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp35, 3))))))) & 65535];
			fVec4[0] = fTemp41;
			fRec34[0] = -((fRec34[1] * (1.0f - fTemp31) - (fTemp41 - fVec4[1]) / fTemp30) / (fTemp31 + 1.0f));
			fRec32[0] = -((fRec32[1] * (1.0f - fTemp29) - (fRec34[0] + fRec34[1])) / (fTemp29 + 1.0f));
			float fTemp42 = 0.25f * fRec32[0];
			float fTemp43 = 0.16666667f * fTemp27 * fTemp28 * fVec2[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp23, 3))))))) & 131071] + fTemp42 + (fTemp21 + (-3.0f - fTemp24)) * (fTemp28 * (0.5f * fTemp26 * fVec2[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp23, 1))))))) & 131071] - 0.16666667f * fVec2[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp23)))))) & 131071] * fTemp25) - 0.5f * fTemp27 * fVec2[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp23, 2))))))) & 131071]) - 0.6f * fRec17[1];
			fVec5[IOTA0 & 1023] = fTemp43;
			fRec17[0] = fVec5[(faust_wrap_sub(IOTA0, 798)) & 1023];
			float fRec18 = 0.6f * fTemp43;
			fRec40[0] = -((fTemp12 * fRec40[1] - (fRec1[1] + fRec1[2])) / fTemp11);
			fRec41[0] = -((fRec41[1] * fTemp12 - (fRec1[1] - fRec1[2]) / fTemp9) / fTemp11);
			float fTemp44 = fRec41[0] + fRec40[0] * fTemp8;
			fVec6[0] = fTemp44;
			fRec39[0] = -((fRec39[1] * fTemp14 - (fTemp44 - fVec6[1]) / fTemp5) / fTemp7);
			fRec42[0] = -((fTemp14 * fRec42[1] - (fTemp44 + fVec6[1])) / fTemp7);
			float fTemp45 = (fRec42[0] + fRec39[0] * fTemp4) * std::pow(0.001f, 0.15313378f * fTemp3);
			fVec7[IOTA0 & 131071] = fTemp45;
			float fTemp46 = ((iTemp16) ? 0.25f : fRec43[1] + fTemp17);
			fRec43[0] = fTemp46 - std::floor(fTemp46);
			float fTemp47 = 0.05668934f * fTemp19 * std::sin(6.2831855f * fRec43[0]);
			float fTemp48 = std::max<float>(1.0f, fConst0 * fTemp2 * (fTemp47 + 0.15313378f));
			float fTemp49 = fTemp48 + -0.999995f;
			int iTemp50 = static_cast<int>(fTemp49);
			float fTemp51 = std::floor(fTemp49);
			float fTemp52 = fTemp48 + (-1.0f - fTemp51);
			float fTemp53 = fTemp48 - fTemp51;
			float fTemp54 = fTemp53 * fTemp52;
			float fTemp55 = fTemp48 + (-2.0f - fTemp51);
			float fTemp56 = 0.16666667f * fTemp54 * fTemp55 * fVec7[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp50, 3))))))) & 131071] + (fTemp48 + (-3.0f - fTemp51)) * (fTemp55 * (0.5f * fTemp53 * fVec7[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp50, 1))))))) & 131071] - 0.16666667f * fVec7[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp50)))))) & 131071] * fTemp52) - 0.5f * fTemp54 * fVec7[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp50, 2))))))) & 131071]) + fTemp42 - 0.6f * fRec37[1];
			fVec8[IOTA0 & 1023] = fTemp56;
			fRec37[0] = fVec8[(faust_wrap_sub(IOTA0, 1000)) & 1023];
			float fRec38 = 0.6f * fTemp56;
			fRec47[0] = -((fTemp12 * fRec47[1] - (fRec3[1] + fRec3[2])) / fTemp11);
			fRec48[0] = -((fTemp12 * fRec48[1] - (fRec3[1] - fRec3[2]) / fTemp9) / fTemp11);
			float fTemp57 = fRec48[0] + fRec47[0] * fTemp8;
			fVec9[0] = fTemp57;
			fRec46[0] = -((fTemp14 * fRec46[1] - (fTemp57 - fVec9[1]) / fTemp5) / fTemp7);
			fRec49[0] = -((fTemp14 * fRec49[1] - (fTemp57 + fVec9[1])) / fTemp7);
			float fTemp58 = (fRec49[0] + fRec46[0] * fTemp4) * std::pow(0.001f, 0.17470522f * fTemp3);
			fVec10[IOTA0 & 131071] = fTemp58;
			float fTemp59 = ((iTemp16) ? 0.375f : fTemp17 + fRec50[1]);
			fRec50[0] = fTemp59 - std::floor(fTemp59);
			float fTemp60 = 0.05668934f * fTemp19 * std::sin(6.2831855f * fRec50[0]);
			float fTemp61 = std::max<float>(1.0f, fConst0 * fTemp2 * (fTemp60 + 0.17470522f));
			float fTemp62 = fTemp61 + -0.999995f;
			int iTemp63 = static_cast<int>(fTemp62);
			float fTemp64 = std::floor(fTemp62);
			float fTemp65 = fTemp61 + (-1.0f - fTemp64);
			float fTemp66 = fTemp61 - fTemp64;
			float fTemp67 = fTemp66 * fTemp65;
			float fTemp68 = fTemp61 + (-2.0f - fTemp64);
			float fTemp69 = 0.16666667f * fTemp67 * fTemp68 * fVec10[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp63, 3))))))) & 131071] + fTemp42 + (fTemp61 + (-3.0f - fTemp64)) * (fTemp68 * (0.5f * fTemp66 * fVec10[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp63, 1))))))) & 131071] - 0.16666667f * fVec10[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp63)))))) & 131071] * fTemp65) - 0.5f * fTemp67 * fVec10[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp63, 2))))))) & 131071]) - 0.6f * fRec44[1];
			fVec11[IOTA0 & 1023] = fTemp69;
			fRec44[0] = fVec11[(faust_wrap_sub(IOTA0, 932)) & 1023];
			float fRec45 = 0.6f * fTemp69;
			fRec54[0] = -((fTemp12 * fRec54[1] - (fRec4[1] + fRec4[2])) / fTemp11);
			fRec55[0] = -((fTemp12 * fRec55[1] - (fRec4[1] - fRec4[2]) / fTemp9) / fTemp11);
			float fTemp70 = fRec55[0] + fRec54[0] * fTemp8;
			fVec12[0] = fTemp70;
			fRec53[0] = -((fTemp14 * fRec53[1] - (fTemp70 - fVec12[1]) / fTemp5) / fTemp7);
			fRec56[0] = -((fTemp14 * fRec56[1] - (fTemp70 + fVec12[1])) / fTemp7);
			float fTemp71 = (fRec56[0] + fRec53[0] * fTemp4) * std::pow(0.001f, 0.25688207f * fTemp3);
			fVec13[IOTA0 & 131071] = fTemp71;
			float fTemp72 = ((iTemp16) ? 0.4375f : fTemp17 + fRec57[1]);
			fRec57[0] = fTemp72 - std::floor(fTemp72);
			float fTemp73 = 0.05668934f * fTemp19 * std::sin(6.2831855f * fRec57[0]);
			float fTemp74 = std::max<float>(1.0f, fConst0 * fTemp2 * (fTemp73 + 0.25688207f));
			float fTemp75 = fTemp74 + -0.999995f;
			int iTemp76 = static_cast<int>(fTemp75);
			float fTemp77 = std::floor(fTemp75);
			float fTemp78 = fTemp74 + (-1.0f - fTemp77);
			float fTemp79 = fTemp74 - fTemp77;
			float fTemp80 = fTemp79 * fTemp78;
			float fTemp81 = fTemp74 + (-2.0f - fTemp77);
			float fTemp82 = 0.16666667f * fTemp80 * fTemp81 * fVec13[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp76, 3))))))) & 131071] + fTemp42 + (fTemp74 + (-3.0f - fTemp77)) * (fTemp81 * (0.5f * fTemp79 * fVec13[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp76, 1))))))) & 131071] - 0.16666667f * fVec13[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp76)))))) & 131071] * fTemp78) - 0.5f * fTemp80 * fVec13[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp76, 2))))))) & 131071]) - 0.6f * fRec51[1];
			fVec14[IOTA0 & 1023] = fTemp82;
			fRec51[0] = fVec14[(faust_wrap_sub(IOTA0, 875)) & 1023];
			float fRec52 = 0.6f * fTemp82;
			float fTemp83 = fRec51[1] + fRec44[1] + fRec17[1] + fRec37[1] + fRec52 + fRec45 + fRec38 + fRec18;
			fRec61[0] = -((fTemp12 * fRec61[1] - (fRec5[1] + fRec5[2])) / fTemp11);
			fRec62[0] = -((fTemp12 * fRec62[1] - (fRec5[1] - fRec5[2]) / fTemp9) / fTemp11);
			float fTemp84 = fRec62[0] + fRec61[0] * fTemp8;
			fVec15[0] = fTemp84;
			fRec60[0] = -((fTemp14 * fRec60[1] - (fTemp84 - fVec15[1]) / fTemp5) / fTemp7);
			fRec63[0] = -((fTemp14 * fRec63[1] - (fTemp84 + fVec15[1])) / fTemp7);
			float fTemp85 = (fRec63[0] + fRec60[0] * fTemp4) * std::pow(0.001f, 0.21998005f * fTemp3);
			fVec16[IOTA0 & 131071] = fTemp85;
			float fTemp86 = std::max<float>(1.0f, fConst0 * fTemp2 * (0.21998005f - fTemp47));
			float fTemp87 = fTemp86 + -0.999995f;
			int iTemp88 = static_cast<int>(fTemp87);
			float fTemp89 = std::floor(fTemp87);
			float fTemp90 = fTemp86 + (-1.0f - fTemp89);
			float fTemp91 = fTemp86 - fTemp89;
			float fTemp92 = fTemp91 * fTemp90;
			float fTemp93 = fTemp86 + (-2.0f - fTemp89);
			float fTemp94 = 0.16666667f * fTemp92 * fTemp93 * fVec16[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp88, 3))))))) & 131071] + fTemp42 + (fTemp86 + (-3.0f - fTemp89)) * (fTemp93 * (0.5f * fTemp91 * fVec16[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp88, 1))))))) & 131071] - 0.16666667f * fVec16[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp88)))))) & 131071] * fTemp90) - 0.5f * fTemp92 * fVec16[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp88, 2))))))) & 131071]) - 0.6f * fRec58[1];
			fVec17[IOTA0 & 1023] = fTemp94;
			fRec58[0] = fVec17[(faust_wrap_sub(IOTA0, 894)) & 1023];
			float fRec59 = 0.6f * fTemp94;
			fRec67[0] = -((fTemp12 * fRec67[1] - (fRec9[1] + fRec9[2])) / fTemp11);
			fRec68[0] = -((fTemp12 * fRec68[1] - (fRec9[1] - fRec9[2]) / fTemp9) / fTemp11);
			float fTemp95 = fRec68[0] + fRec67[0] * fTemp8;
			fVec18[0] = fTemp95;
			fRec66[0] = -((fTemp14 * fRec66[1] - (fTemp95 - fVec18[1]) / fTemp5) / fTemp7);
			fRec69[0] = -((fTemp14 * fRec69[1] - (fTemp95 + fVec18[1])) / fTemp7);
			float fTemp96 = (fRec69[0] + fRec66[0] * fTemp4) * std::pow(0.001f, 0.070764855f * fTemp3);
			fVec19[IOTA0 & 65535] = fTemp96;
			float fTemp97 = ((iTemp16) ? 0.0f : fTemp17 + fRec70[1]);
			fRec70[0] = fTemp97 - std::floor(fTemp97);
			float fTemp98 = 0.05668934f * fTemp19 * std::sin(6.2831855f * fRec70[0]);
			float fTemp99 = std::max<float>(1.0f, fConst0 * fTemp2 * (fTemp98 + 0.070764855f));
			float fTemp100 = fTemp99 + -0.999995f;
			int iTemp101 = static_cast<int>(fTemp100);
			float fTemp102 = std::floor(fTemp100);
			float fTemp103 = fTemp99 + (-1.0f - fTemp102);
			float fTemp104 = fTemp99 - fTemp102;
			float fTemp105 = fTemp104 * fTemp103;
			float fTemp106 = fTemp99 + (-2.0f - fTemp102);
			float fTemp107 = 0.16666667f * fTemp105 * fTemp106 * fVec19[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp101, 3))))))) & 65535] + fTemp42 + (fTemp99 + (-3.0f - fTemp102)) * (fTemp106 * (0.5f * fTemp104 * fVec19[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp101, 1))))))) & 65535] - 0.16666667f * fVec19[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp101)))))) & 65535] * fTemp103) - 0.5f * fTemp105 * fVec19[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp101, 2))))))) & 65535]) - 0.6f * fRec64[1];
			fVec20[IOTA0 & 1023] = fTemp107;
			fRec64[0] = fVec20[(faust_wrap_sub(IOTA0, 956)) & 1023];
			float fRec65 = 0.6f * fTemp107;
			fRec74[0] = -((fTemp12 * fRec74[1] - (fRec13[1] + fRec13[2])) / fTemp11);
			fRec75[0] = -((fTemp12 * fRec75[1] - (fRec13[1] - fRec13[2]) / fTemp9) / fTemp11);
			float fTemp108 = fRec75[0] + fRec74[0] * fTemp8;
			fVec21[0] = fTemp108;
			fRec73[0] = -((fTemp14 * fRec73[1] - (fTemp108 - fVec21[1]) / fTemp5) / fTemp7);
			fRec76[0] = -((fTemp14 * fRec76[1] - (fTemp108 + fVec21[1])) / fTemp7);
			float fTemp109 = (fRec76[0] + fRec73[0] * fTemp4) * std::pow(0.001f, 0.10252925f * fTemp3);
			fVec22[IOTA0 & 65535] = fTemp109;
			float fTemp110 = std::max<float>(1.0f, fConst0 * fTemp2 * (0.10252925f - fTemp98));
			float fTemp111 = fTemp110 + -0.999995f;
			int iTemp112 = static_cast<int>(fTemp111);
			float fTemp113 = std::floor(fTemp111);
			float fTemp114 = fTemp110 + (-1.0f - fTemp113);
			float fTemp115 = fTemp110 - fTemp113;
			float fTemp116 = fTemp115 * fTemp114;
			float fTemp117 = fTemp110 + (-2.0f - fTemp113);
			float fTemp118 = 0.16666667f * fTemp116 * fTemp117 * fVec22[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp112, 3))))))) & 65535] + fTemp42 + (fTemp110 + (-3.0f - fTemp113)) * (fTemp117 * (0.5f * fTemp115 * fVec22[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp112, 1))))))) & 65535] - 0.16666667f * fVec22[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp112)))))) & 65535] * fTemp114) - 0.5f * fTemp116 * fVec22[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp112, 2))))))) & 65535]) - 0.6f * fRec71[1];
			fVec23[IOTA0 & 1023] = fTemp118;
			fRec71[0] = fVec23[(faust_wrap_sub(IOTA0, 832)) & 1023];
			float fRec72 = 0.6f * fTemp118;
			float fTemp119 = fRec72 + fRec65 + fRec38 + fRec59;
			float fTemp120 = fRec71[1] + fRec64[1] + fRec58[1] + fRec37[1] + fTemp119;
			fRec80[0] = -((fTemp12 * fRec80[1] - (fRec6[1] + fRec6[2])) / fTemp11);
			fRec81[0] = -((fTemp12 * fRec81[1] - (fRec6[1] - fRec6[2]) / fTemp9) / fTemp11);
			float fTemp121 = fRec81[0] + fRec80[0] * fTemp8;
			fVec24[0] = fTemp121;
			fRec79[0] = -((fTemp14 * fRec79[1] - (fTemp121 - fVec24[1]) / fTemp5) / fTemp7);
			fRec82[0] = -((fTemp14 * fRec82[1] - (fTemp121 + fVec24[1])) / fTemp7);
			float fTemp122 = (fRec82[0] + fRec79[0] * fTemp4) * std::pow(0.001f, 0.125f * fTemp3);
			fVec25[IOTA0 & 131071] = fTemp122;
			float fTemp123 = std::max<float>(1.0f, fConst0 * fTemp2 * (0.125f - fTemp20));
			float fTemp124 = fTemp123 + -0.999995f;
			int iTemp125 = static_cast<int>(fTemp124);
			float fTemp126 = std::floor(fTemp124);
			float fTemp127 = fTemp123 + (-1.0f - fTemp126);
			float fTemp128 = fTemp123 - fTemp126;
			float fTemp129 = fTemp128 * fTemp127;
			float fTemp130 = fTemp123 + (-2.0f - fTemp126);
			float fTemp131 = 0.16666667f * fTemp129 * fTemp130 * fVec25[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp125, 3))))))) & 131071] + fTemp42 + (fTemp123 + (-3.0f - fTemp126)) * (fTemp130 * (0.5f * fTemp128 * fVec25[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp125, 1))))))) & 131071] - 0.16666667f * fVec25[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp125)))))) & 131071] * fTemp127) - 0.5f * fTemp129 * fVec25[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp125, 2))))))) & 131071]) - 0.6f * fRec77[1];
			fVec26[IOTA0 & 1023] = fTemp131;
			fRec77[0] = fVec26[(faust_wrap_sub(IOTA0, 806)) & 1023];
			float fRec78 = 0.6f * fTemp131;
			fRec86[0] = -((fTemp12 * fRec86[1] - (fRec10[1] + fRec10[2])) / fTemp11);
			fRec87[0] = -((fTemp12 * fRec87[1] - (fRec10[1] - fRec10[2]) / fTemp9) / fTemp11);
			float fTemp132 = fRec87[0] + fRec86[0] * fTemp8;
			fVec27[0] = fTemp132;
			fRec85[0] = -((fTemp14 * fRec85[1] - (fTemp132 - fVec27[1]) / fTemp5) / fTemp7);
			fRec88[0] = -((fTemp14 * fRec88[1] - (fTemp132 + fVec27[1])) / fTemp7);
			float fTemp133 = (fRec88[0] + fRec85[0] * fTemp4) * std::pow(0.001f, 0.07776644f * fTemp3);
			fVec28[IOTA0 & 65535] = fTemp133;
			float fTemp134 = ((iTemp16) ? 0.0625f : fTemp17 + fRec89[1]);
			fRec89[0] = fTemp134 - std::floor(fTemp134);
			float fTemp135 = 0.05668934f * fTemp19 * std::sin(6.2831855f * fRec89[0]);
			float fTemp136 = std::max<float>(1.0f, fConst0 * fTemp2 * (fTemp135 + 0.07776644f));
			float fTemp137 = fTemp136 + -0.999995f;
			int iTemp138 = static_cast<int>(fTemp137);
			float fTemp139 = std::floor(fTemp137);
			float fTemp140 = fTemp136 + (-1.0f - fTemp139);
			float fTemp141 = fTemp136 - fTemp139;
			float fTemp142 = fTemp141 * fTemp140;
			float fTemp143 = fTemp136 + (-2.0f - fTemp139);
			float fTemp144 = 0.16666667f * fTemp142 * fTemp143 * fVec28[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp138, 3))))))) & 65535] + fTemp42 + (fTemp136 + (-3.0f - fTemp139)) * (fTemp143 * (0.5f * fTemp141 * fVec28[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp138, 1))))))) & 65535] - 0.16666667f * fVec28[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp138)))))) & 65535] * fTemp140) - 0.5f * fTemp142 * fVec28[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp138, 2))))))) & 65535]) - 0.6f * fRec83[1];
			fVec29[IOTA0 & 1023] = fTemp144;
			fRec83[0] = fVec29[(faust_wrap_sub(IOTA0, 1001)) & 1023];
			float fRec84 = 0.6f * fTemp144;
			fRec93[0] = -((fTemp12 * fRec93[1] - (fRec14[1] + fRec14[2])) / fTemp11);
			fRec94[0] = -((fTemp12 * fRec94[1] - (fRec14[1] - fRec14[2]) / fTemp9) / fTemp11);
			float fTemp145 = fRec94[0] + fRec93[0] * fTemp8;
			fVec30[0] = fTemp145;
			fRec92[0] = -((fTemp14 * fRec92[1] - (fTemp145 - fVec30[1]) / fTemp5) / fTemp7);
			fRec95[0] = -((fTemp14 * fRec95[1] - (fTemp145 + fVec30[1])) / fTemp7);
			float fTemp146 = (fRec95[0] + fRec92[0] * fTemp4) * std::pow(0.001f, 0.14782245f * fTemp3);
			fVec31[IOTA0 & 131071] = fTemp146;
			float fTemp147 = std::max<float>(1.0f, fConst0 * fTemp2 * (0.14782245f - fTemp135));
			float fTemp148 = fTemp147 + -0.999995f;
			int iTemp149 = static_cast<int>(fTemp148);
			float fTemp150 = std::floor(fTemp148);
			float fTemp151 = fTemp147 + (-1.0f - fTemp150);
			float fTemp152 = fTemp147 - fTemp150;
			float fTemp153 = fTemp152 * fTemp151;
			float fTemp154 = fTemp147 + (-2.0f - fTemp150);
			float fTemp155 = 0.16666667f * fTemp153 * fTemp154 * fVec31[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp149, 3))))))) & 131071] + fTemp42 + (fTemp147 + (-3.0f - fTemp150)) * (fTemp154 * (0.5f * fTemp152 * fVec31[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp149, 1))))))) & 131071] - 0.16666667f * fVec31[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp149)))))) & 131071] * fTemp151) - 0.5f * fTemp153 * fVec31[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp149, 2))))))) & 131071]) - 0.6f * fRec90[1];
			fVec32[IOTA0 & 1023] = fTemp155;
			fRec90[0] = fVec32[(faust_wrap_sub(IOTA0, 778)) & 1023];
			float fRec91 = 0.6f * fTemp155;
			fRec99[0] = -((fTemp12 * fRec99[1] - (fRec7[1] + fRec7[2])) / fTemp11);
			fRec100[0] = -((fTemp12 * fRec100[1] - (fRec7[1] - fRec7[2]) / fTemp9) / fTemp11);
			float fTemp156 = fRec100[0] + fRec99[0] * fTemp8;
			fVec33[0] = fTemp156;
			fRec98[0] = -((fTemp14 * fRec98[1] - (fTemp156 - fVec33[1]) / fTemp5) / fTemp7);
			fRec101[0] = -((fTemp14 * fRec101[1] - (fTemp156 + fVec33[1])) / fTemp7);
			float fTemp157 = (fRec101[0] + fRec98[0] * fTemp4) * std::pow(0.001f, 0.19230045f * fTemp3);
			fVec34[IOTA0 & 131071] = fTemp157;
			float fTemp158 = std::max<float>(1.0f, fConst0 * fTemp2 * (0.19230045f - fTemp60));
			float fTemp159 = fTemp158 + -0.999995f;
			int iTemp160 = static_cast<int>(fTemp159);
			float fTemp161 = std::floor(fTemp159);
			float fTemp162 = fTemp158 + (-1.0f - fTemp161);
			float fTemp163 = fTemp158 - fTemp161;
			float fTemp164 = fTemp163 * fTemp162;
			float fTemp165 = fTemp158 + (-2.0f - fTemp161);
			float fTemp166 = 0.16666667f * fTemp164 * fTemp165 * fVec34[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp160, 3))))))) & 131071] + fTemp42 + (fTemp158 + (-3.0f - fTemp161)) * (fTemp165 * (0.5f * fTemp163 * fVec34[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp160, 1))))))) & 131071] - 0.16666667f * fVec34[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp160)))))) & 131071] * fTemp162) - 0.5f * fTemp164 * fVec34[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp160, 2))))))) & 131071]) - 0.6f * fRec96[1];
			fVec35[IOTA0 & 1023] = fTemp166;
			fRec96[0] = fVec35[(faust_wrap_sub(IOTA0, 906)) & 1023];
			float fRec97 = 0.6f * fTemp166;
			fRec105[0] = -((fTemp12 * fRec105[1] - (fRec11[1] + fRec11[2])) / fTemp11);
			fRec106[0] = -((fTemp12 * fRec106[1] - (fRec11[1] - fRec11[2]) / fTemp9) / fTemp11);
			float fTemp167 = fRec106[0] + fRec105[0] * fTemp8;
			fVec36[0] = fTemp167;
			fRec104[0] = -((fTemp14 * fRec104[1] - (fTemp167 - fVec36[1]) / fTemp5) / fTemp7);
			fRec107[0] = -((fTemp14 * fRec107[1] - (fTemp167 + fVec36[1])) / fTemp7);
			float fTemp168 = (fRec107[0] + fRec104[0] * fTemp4) * std::pow(0.001f, 0.08223061f * fTemp3);
			fVec37[IOTA0 & 65535] = fTemp168;
			float fTemp169 = ((iTemp16) ? 0.125f : fTemp17 + fRec108[1]);
			fRec108[0] = fTemp169 - std::floor(fTemp169);
			float fTemp170 = 0.05668934f * fTemp19 * std::sin(6.2831855f * fRec108[0]);
			float fTemp171 = std::max<float>(1.0f, fConst0 * fTemp2 * (fTemp170 + 0.08223061f));
			float fTemp172 = fTemp171 + -0.999995f;
			int iTemp173 = static_cast<int>(fTemp172);
			float fTemp174 = std::floor(fTemp172);
			float fTemp175 = fTemp171 + (-1.0f - fTemp174);
			float fTemp176 = fTemp171 - fTemp174;
			float fTemp177 = fTemp176 * fTemp175;
			float fTemp178 = fTemp171 + (-2.0f - fTemp174);
			float fTemp179 = 0.16666667f * fTemp177 * fTemp178 * fVec37[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp173, 3))))))) & 65535] + fTemp42 + (fTemp171 + (-3.0f - fTemp174)) * (fTemp178 * (0.5f * fTemp176 * fVec37[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp173, 1))))))) & 65535] - 0.16666667f * fVec37[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp173)))))) & 65535] * fTemp175) - 0.5f * fTemp177 * fVec37[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp173, 2))))))) & 65535]) - 0.6f * fRec102[1];
			fVec38[IOTA0 & 1023] = fTemp179;
			fRec102[0] = fVec38[(faust_wrap_sub(IOTA0, 710)) & 1023];
			float fRec103 = 0.6f * fTemp179;
			fRec112[0] = -((fTemp12 * fRec112[1] - (fRec15[1] + fRec15[2])) / fTemp11);
			fRec113[0] = -((fTemp12 * fRec113[1] - (fRec15[1] - fRec15[2]) / fTemp9) / fTemp11);
			float fTemp180 = fRec113[0] + fRec112[0] * fTemp8;
			fVec39[0] = fTemp180;
			fRec111[0] = -((fTemp14 * fRec111[1] - (fTemp180 - fVec39[1]) / fTemp5) / fTemp7);
			fRec114[0] = -((fTemp14 * fRec114[1] - (fTemp180 + fVec39[1])) / fTemp7);
			float fTemp181 = (fRec114[0] + fRec111[0] * fTemp4) * std::pow(0.001f, 0.11940046f * fTemp3);
			fVec40[IOTA0 & 131071] = fTemp181;
			float fTemp182 = std::max<float>(1.0f, fConst0 * fTemp2 * (0.11940046f - fTemp170));
			float fTemp183 = fTemp182 + -0.999995f;
			int iTemp184 = static_cast<int>(fTemp183);
			float fTemp185 = std::floor(fTemp183);
			float fTemp186 = fTemp182 + (-1.0f - fTemp185);
			float fTemp187 = fTemp182 - fTemp185;
			float fTemp188 = fTemp187 * fTemp186;
			float fTemp189 = fTemp182 + (-2.0f - fTemp185);
			float fTemp190 = 0.16666667f * fTemp188 * fTemp189 * fVec40[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp184, 3))))))) & 131071] + fTemp42 + (fTemp182 + (-3.0f - fTemp185)) * (fTemp189 * (0.5f * fTemp187 * fVec40[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp184, 1))))))) & 131071] - 0.16666667f * fVec40[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp184)))))) & 131071] * fTemp186) - 0.5f * fTemp188 * fVec40[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp184, 2))))))) & 131071]) - 0.6f * fRec109[1];
			fVec41[IOTA0 & 1023] = fTemp190;
			fRec109[0] = fVec41[(faust_wrap_sub(IOTA0, 662)) & 1023];
			float fRec110 = 0.6f * fTemp190;
			fRec118[0] = -((fTemp12 * fRec118[1] - (fRec8[1] + fRec8[2])) / fTemp11);
			fRec119[0] = -((fTemp12 * fRec119[1] - (fRec8[1] - fRec8[2]) / fTemp9) / fTemp11);
			float fTemp191 = fRec119[0] + fRec118[0] * fTemp8;
			fVec42[0] = fTemp191;
			fRec117[0] = -((fTemp14 * fRec117[1] - (fTemp191 - fVec42[1]) / fTemp5) / fTemp7);
			fRec120[0] = -((fTemp14 * fRec120[1] - (fTemp191 + fVec42[1])) / fTemp7);
			float fTemp192 = (fRec120[0] + fRec117[0] * fTemp4) * std::pow(0.001f, 0.12786055f * fTemp3);
			fVec43[IOTA0 & 131071] = fTemp192;
			float fTemp193 = std::max<float>(1.0f, fConst0 * fTemp2 * (0.12786055f - fTemp73));
			float fTemp194 = fTemp193 + -0.999995f;
			int iTemp195 = static_cast<int>(fTemp194);
			float fTemp196 = std::floor(fTemp194);
			float fTemp197 = fTemp193 + (-1.0f - fTemp196);
			float fTemp198 = fTemp193 - fTemp196;
			float fTemp199 = fTemp198 * fTemp197;
			float fTemp200 = fTemp193 + (-2.0f - fTemp196);
			float fTemp201 = 0.16666667f * fTemp199 * fTemp200 * fVec43[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp195, 3))))))) & 131071] + fTemp42 + (fTemp193 + (-3.0f - fTemp196)) * (fTemp200 * (0.5f * fTemp198 * fVec43[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp195, 1))))))) & 131071] - 0.16666667f * fVec43[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp195)))))) & 131071] * fTemp197) - 0.5f * fTemp199 * fVec43[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp195, 2))))))) & 131071]) - 0.6f * fRec115[1];
			fVec44[IOTA0 & 1023] = fTemp201;
			fRec115[0] = fVec44[(faust_wrap_sub(IOTA0, 852)) & 1023];
			float fRec116 = 0.6f * fTemp201;
			fRec124[0] = -((fTemp12 * fRec124[1] - (fRec12[1] + fRec12[2])) / fTemp11);
			fRec125[0] = -((fTemp12 * fRec125[1] - (fRec12[1] - fRec12[2]) / fTemp9) / fTemp11);
			float fTemp202 = fRec125[0] + fRec124[0] * fTemp8;
			fVec45[0] = fTemp202;
			fRec123[0] = -((fTemp14 * fRec123[1] - (fTemp202 - fVec45[1]) / fTemp5) / fTemp7);
			fRec126[0] = -((fTemp14 * fRec126[1] - (fTemp202 + fVec45[1])) / fTemp7);
			float fTemp203 = (fRec126[0] + fRec123[0] * fTemp4) * std::pow(0.001f, 0.17490976f * fTemp3);
			fVec46[IOTA0 & 131071] = fTemp203;
			float fTemp204 = ((iTemp16) ? 0.1875f : fTemp17 + fRec127[1]);
			fRec127[0] = fTemp204 - std::floor(fTemp204);
			float fTemp205 = 0.05668934f * fTemp19 * std::sin(6.2831855f * fRec127[0]);
			float fTemp206 = std::max<float>(1.0f, fConst0 * fTemp2 * (fTemp205 + 0.17490976f));
			float fTemp207 = fTemp206 + -0.999995f;
			int iTemp208 = static_cast<int>(fTemp207);
			float fTemp209 = std::floor(fTemp207);
			float fTemp210 = fTemp206 + (-1.0f - fTemp209);
			float fTemp211 = fTemp206 - fTemp209;
			float fTemp212 = fTemp211 * fTemp210;
			float fTemp213 = fTemp206 + (-2.0f - fTemp209);
			float fTemp214 = 0.16666667f * fTemp212 * fTemp213 * fVec46[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp208, 3))))))) & 131071] + fTemp42 + (fTemp206 + (-3.0f - fTemp209)) * (fTemp213 * (0.5f * fTemp211 * fVec46[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp208, 1))))))) & 131071] - 0.16666667f * fVec46[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp208)))))) & 131071] * fTemp210) - 0.5f * fTemp212 * fVec46[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp208, 2))))))) & 131071]) - 0.6f * fRec121[1];
			fVec47[IOTA0 & 1023] = fTemp214;
			fRec121[0] = fVec47[(faust_wrap_sub(IOTA0, 566)) & 1023];
			float fRec122 = 0.6f * fTemp214;
			fRec131[0] = -((fTemp12 * fRec131[1] - (fRec16[1] + fRec16[2])) / fTemp11);
			fRec132[0] = -((fTemp12 * fRec132[1] - (fRec16[1] - fRec16[2]) / fTemp9) / fTemp11);
			float fTemp215 = fRec132[0] + fRec131[0] * fTemp8;
			fVec48[0] = fTemp215;
			fRec130[0] = -((fTemp14 * fRec130[1] - (fTemp215 - fVec48[1]) / fTemp5) / fTemp7);
			fRec133[0] = -((fTemp14 * fRec133[1] - (fTemp215 + fVec48[1])) / fTemp7);
			float fTemp216 = (fRec133[0] + fRec130[0] * fTemp4) * std::pow(0.001f, 0.12767006f * fTemp3);
			fVec49[IOTA0 & 131071] = fTemp216;
			float fTemp217 = std::max<float>(1.0f, fConst0 * fTemp2 * (0.12767006f - fTemp205));
			float fTemp218 = fTemp217 + -0.999995f;
			int iTemp219 = static_cast<int>(fTemp218);
			float fTemp220 = std::floor(fTemp218);
			float fTemp221 = fTemp217 + (-1.0f - fTemp220);
			float fTemp222 = fTemp217 - fTemp220;
			float fTemp223 = fTemp222 * fTemp221;
			float fTemp224 = fTemp217 + (-2.0f - fTemp220);
			float fTemp225 = 0.16666667f * fTemp223 * fTemp224 * fVec49[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp219, 3))))))) & 131071] + fTemp42 + (fTemp217 + (-3.0f - fTemp220)) * (fTemp224 * (0.5f * fTemp222 * fVec49[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp219, 1))))))) & 131071] - 0.16666667f * fVec49[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, iTemp219)))))) & 131071] * fTemp221) - 0.5f * fTemp223 * fVec49[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst4, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp219, 2))))))) & 131071]) - 0.6f * fRec128[1];
			fVec50[IOTA0 & 1023] = fTemp225;
			fRec128[0] = fVec50[(faust_wrap_sub(IOTA0, 996)) & 1023];
			float fRec129 = 0.6f * fTemp225;
			float fTemp226 = 0.25f * (fRec128[1] + fRec121[1] + fRec115[1] + fRec51[1] + fRec109[1] + fRec102[1] + fRec96[1] + fRec44[1] + fRec90[1] + fRec83[1] + fRec77[1] + fRec17[1] + fRec71[1] + fRec64[1] + fRec58[1] + fRec37[1] + fRec129 + fRec122 + fRec116 + fRec52 + fRec110 + fRec103 + fRec97 + fRec45 + fRec91 + fRec84 + fRec78 + fRec18 + fTemp119);
			fRec1[0] = fRec38 + fRec37[1] + fTemp226 - 0.5f * (fTemp120 + fTemp83);
			float fTemp227 = fRec90[1] + fRec83[1] + fRec77[1] + fRec17[1] + fRec91 + fRec84 + fRec18 + fRec78;
			fRec2[0] = fRec18 + fRec17[1] + fTemp226 - 0.5f * (fTemp227 + fTemp83);
			float fTemp228 = fRec109[1] + fRec102[1] + fRec96[1] + fRec44[1] + fRec110 + fRec103 + fRec45 + fRec97;
			fRec3[0] = fRec45 + fRec44[1] + fTemp226 - 0.5f * (fTemp228 + fTemp83);
			float fTemp229 = fRec128[1] + fRec121[1] + fRec115[1] + fRec51[1] + fRec129 + fRec122 + fRec52 + fRec116;
			fRec4[0] = fRec52 + fRec51[1] + fTemp226 - 0.5f * (fTemp229 + fTemp83);
			float fTemp230 = fRec115[1] + fRec96[1] + fRec77[1] + fRec58[1] + fRec116 + fRec97 + fRec59 + fRec78;
			fRec5[0] = fRec59 + fRec58[1] + fTemp226 - 0.5f * (fTemp120 + fTemp230);
			fRec6[0] = fRec78 + fRec77[1] + fTemp226 - 0.5f * (fTemp227 + fTemp230);
			fRec7[0] = fRec97 + fRec96[1] + fTemp226 - 0.5f * (fTemp228 + fTemp230);
			fRec8[0] = fRec116 + fRec115[1] + fTemp226 - 0.5f * (fTemp229 + fTemp230);
			float fTemp231 = fRec121[1] + fRec102[1] + fRec83[1] + fRec64[1] + fRec122 + fRec103 + fRec65 + fRec84;
			fRec9[0] = fRec65 + fRec64[1] + fTemp226 - 0.5f * (fTemp120 + fTemp231);
			fRec10[0] = fRec84 + fRec83[1] + fTemp226 - 0.5f * (fTemp227 + fTemp231);
			fRec11[0] = fRec103 + fRec102[1] + fTemp226 - 0.5f * (fTemp228 + fTemp231);
			fRec12[0] = fRec122 + fRec121[1] + fTemp226 - 0.5f * (fTemp229 + fTemp231);
			float fTemp232 = fRec128[1] + fRec109[1] + fRec90[1] + fRec71[1] + fRec129 + fRec110 + fRec72 + fRec91;
			fRec13[0] = fRec72 + fRec71[1] + fTemp226 - 0.5f * (fTemp120 + fTemp232);
			fRec14[0] = fRec91 + fRec90[1] + fTemp226 - 0.5f * (fTemp227 + fTemp232);
			fRec15[0] = fRec110 + fRec109[1] + fTemp226 - 0.5f * (fTemp228 + fTemp232);
			fRec16[0] = fRec129 + fRec128[1] + fTemp226 - 0.5f * (fTemp229 + fTemp232);
			float fTemp233 = 0.70710677f * fTemp32 * std::cos(fTemp0);
			output0[i0] = static_cast<FAUSTFLOAT>(0.70710677f * (0.35355338f * (fRec2[0] + fRec4[0] + fRec6[0] + fRec8[0] + fRec10[0] + fRec12[0] + fRec14[0] + fRec16[0]) * fTemp1 + fTemp233 + fTemp233 + 0.35355338f * (fRec1[0] + fRec3[0] + fRec5[0] + fRec7[0] + fRec9[0] + fRec11[0] + fRec13[0] + fRec15[0]) * fTemp1));
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec23[1] = fRec23[0];
			fRec24[1] = fRec24[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec27[1] = fRec27[0];
			fVec1[1] = fVec1[0];
			fRec22[1] = fRec22[0];
			fRec28[1] = fRec28[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec31[1] = fRec31[0];
			fRec33[1] = fRec33[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fVec4[1] = fVec4[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec17[1] = fRec17[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fVec6[1] = fVec6[0];
			fRec39[1] = fRec39[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			fRec37[1] = fRec37[0];
			fRec47[1] = fRec47[0];
			fRec48[1] = fRec48[0];
			fVec9[1] = fVec9[0];
			fRec46[1] = fRec46[0];
			fRec49[1] = fRec49[0];
			fRec50[1] = fRec50[0];
			fRec44[1] = fRec44[0];
			fRec54[1] = fRec54[0];
			fRec55[1] = fRec55[0];
			fVec12[1] = fVec12[0];
			fRec53[1] = fRec53[0];
			fRec56[1] = fRec56[0];
			fRec57[1] = fRec57[0];
			fRec51[1] = fRec51[0];
			fRec61[1] = fRec61[0];
			fRec62[1] = fRec62[0];
			fVec15[1] = fVec15[0];
			fRec60[1] = fRec60[0];
			fRec63[1] = fRec63[0];
			fRec58[1] = fRec58[0];
			fRec67[1] = fRec67[0];
			fRec68[1] = fRec68[0];
			fVec18[1] = fVec18[0];
			fRec66[1] = fRec66[0];
			fRec69[1] = fRec69[0];
			fRec70[1] = fRec70[0];
			fRec64[1] = fRec64[0];
			fRec74[1] = fRec74[0];
			fRec75[1] = fRec75[0];
			fVec21[1] = fVec21[0];
			fRec73[1] = fRec73[0];
			fRec76[1] = fRec76[0];
			fRec71[1] = fRec71[0];
			fRec80[1] = fRec80[0];
			fRec81[1] = fRec81[0];
			fVec24[1] = fVec24[0];
			fRec79[1] = fRec79[0];
			fRec82[1] = fRec82[0];
			fRec77[1] = fRec77[0];
			fRec86[1] = fRec86[0];
			fRec87[1] = fRec87[0];
			fVec27[1] = fVec27[0];
			fRec85[1] = fRec85[0];
			fRec88[1] = fRec88[0];
			fRec89[1] = fRec89[0];
			fRec83[1] = fRec83[0];
			fRec93[1] = fRec93[0];
			fRec94[1] = fRec94[0];
			fVec30[1] = fVec30[0];
			fRec92[1] = fRec92[0];
			fRec95[1] = fRec95[0];
			fRec90[1] = fRec90[0];
			fRec99[1] = fRec99[0];
			fRec100[1] = fRec100[0];
			fVec33[1] = fVec33[0];
			fRec98[1] = fRec98[0];
			fRec101[1] = fRec101[0];
			fRec96[1] = fRec96[0];
			fRec105[1] = fRec105[0];
			fRec106[1] = fRec106[0];
			fVec36[1] = fVec36[0];
			fRec104[1] = fRec104[0];
			fRec107[1] = fRec107[0];
			fRec108[1] = fRec108[0];
			fRec102[1] = fRec102[0];
			fRec112[1] = fRec112[0];
			fRec113[1] = fRec113[0];
			fVec39[1] = fVec39[0];
			fRec111[1] = fRec111[0];
			fRec114[1] = fRec114[0];
			fRec109[1] = fRec109[0];
			fRec118[1] = fRec118[0];
			fRec119[1] = fRec119[0];
			fVec42[1] = fVec42[0];
			fRec117[1] = fRec117[0];
			fRec120[1] = fRec120[0];
			fRec115[1] = fRec115[0];
			fRec124[1] = fRec124[0];
			fRec125[1] = fRec125[0];
			fVec45[1] = fVec45[0];
			fRec123[1] = fRec123[0];
			fRec126[1] = fRec126[0];
			fRec127[1] = fRec127[0];
			fRec121[1] = fRec121[0];
			fRec131[1] = fRec131[0];
			fRec132[1] = fRec132[0];
			fVec48[1] = fVec48[0];
			fRec130[1] = fRec130[0];
			fRec133[1] = fRec133[0];
			fRec128[1] = fRec128[0];
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
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
		}
	}

};

#endif
