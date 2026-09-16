/* ------------------------------------------------------------
author: "Daniel Leonov"
license: "LicenseRef-STK-4.3"
name: "Spring Tank"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibSpringreverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibSpringreverb_H__
#define  __LibSpringreverb_H__

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
#define FAUSTCLASS LibSpringreverb
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

static float LibSpringreverb_faustpower2_f(float value) {
	return value * value;
}

class LibSpringreverb : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec1[2];
	float fConst3;
	int IOTA0;
	float fVec0[8192];
	float fConst4;
	float fConst5;
	int iConst6;
	int iConst7;
	int iConst8;
	int iConst9;
	int iConst10;
	int iConst11;
	int iConst12;
	int iConst13;
	float fVec1[8192];
	int iConst14;
	float fVec2[4096];
	int iConst15;
	float fVec3[8192];
	int iConst16;
	float fVec4[4096];
	int iConst17;
	float fVec5[8192];
	int iConst18;
	float fVec6[4096];
	int iConst19;
	float fVec7[4096];
	int iConst20;
	float fVec8[2048];
	int iConst21;
	float fVec9[8192];
	int iConst22;
	float fVec10[4096];
	int iConst23;
	float fVec11[4096];
	int iConst24;
	float fVec12[4096];
	int iConst25;
	float fVec13[4096];
	int iConst26;
	float fVec14[4096];
	int iConst27;
	float fVec15[4096];
	int iConst28;
	float fVec16[2048];
	int iConst29;
	float fVec17[2048];
	FAUSTFLOAT fHslider2;
	float fRec12[2];
	float fVec18[16384];
	float fConst30;
	FAUSTFLOAT fHslider3;
	float fRec13[2];
	FAUSTFLOAT fEntry0;
	float fVec19[2];
	float fRec11[2];
	float fRec3[2];
	float fVec20[4096];
	float fVec21[16384];
	float fVec22[2];
	float fRec14[2];
	float fRec4[2];
	float fVec23[4096];
	int iConst31;
	float fVec24[16384];
	float fVec25[2];
	float fRec15[2];
	float fRec5[2];
	float fVec26[4096];
	int iConst32;
	float fVec27[16384];
	float fVec28[2];
	float fRec16[2];
	float fRec6[2];
	float fVec29[4096];
	int iConst33;
	float fVec30[16384];
	float fVec31[2];
	float fRec17[2];
	float fRec7[2];
	float fVec32[8192];
	int iConst34;
	float fVec33[16384];
	float fVec34[2];
	float fRec18[2];
	float fRec8[2];
	float fVec35[8192];
	int iConst35;
	float fVec36[16384];
	float fVec37[2];
	float fRec19[2];
	float fRec9[2];
	float fVec38[8192];
	int iConst36;
	float fVec39[16384];
	float fVec40[2];
	float fRec20[2];
	float fRec10[2];
	float fVec41[2];
	float fConst37;
	float fConst38;
	float fConst39;
	float fRec2[2];
	FAUSTFLOAT fHslider4;
	float fRec21[2];
	
 public:
	LibSpringreverb() {
	}
	
	LibSpringreverb(const LibSpringreverb&) = default;
	
	virtual ~LibSpringreverb() = default;
	
	LibSpringreverb& operator=(const LibSpringreverb&) = default;
	
	void metadata(Meta* m) { 
		m->declare("aanl.lib/ADAA1:author", "Dario Sanfilippo");
		m->declare("aanl.lib/ADAA1:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/ADAA1:license", "MIT");
		m->declare("aanl.lib/hardclip:author", "Dario Sanfilippo");
		m->declare("aanl.lib/hardclip:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/hardclip:license", "MIT");
		m->declare("aanl.lib/name", "Faust Antialiased Nonlinearities");
		m->declare("aanl.lib/version", "1.5.0");
		m->declare("author", "Daniel Leonov");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibSpringreverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Spring-flavoured reverb (Chaos Audio Stratus): diffusion into damped delay bank with Hadamard feedback");
		m->declare("family", "reverb");
		m->declare("filename", "lib-springreverb.dsp");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "LicenseRef-STK-4.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Spring Tank");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/springreverb:author", "Daniel Leonov");
		m->declare("reverbs.lib/version", "1.5.1");
		m->declare("routes.lib/hadamard:author", "Remy Muller, revised by Romain Michon");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/reverbs.lib re.springreverb");
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
		fConst3 = 3.1415927f / fConst0;
		fConst4 = std::round(0.035f * fConst0);
		fConst5 = std::max<float>(0.0f, fConst4);
		iConst6 = static_cast<int>(std::min<float>(std::round(0.02375f * fConst0), fConst5));
		iConst7 = static_cast<int>(std::min<float>(std::round(0.03875f * fConst0), fConst5));
		iConst8 = static_cast<int>(std::min<float>(std::round(0.03125f * fConst0), fConst5));
		iConst9 = static_cast<int>(std::min<float>(std::round(0.04625f * fConst0), fConst5));
		iConst10 = static_cast<int>(std::min<float>(std::round(0.0275f * fConst0), fConst5));
		iConst11 = static_cast<int>(std::min<float>(std::round(0.0425f * fConst0), fConst5));
		iConst12 = static_cast<int>(std::min<float>(fConst4, fConst5));
		iConst13 = static_cast<int>(std::min<float>(std::round(0.05f * fConst0), fConst5));
		iConst14 = static_cast<int>(std::min<float>(std::round(0.027375f * fConst0), fConst5));
		iConst15 = static_cast<int>(std::min<float>(std::round(0.016875f * fConst0), fConst5));
		iConst16 = static_cast<int>(std::min<float>(std::round(0.022125f * fConst0), fConst5));
		iConst17 = static_cast<int>(std::min<float>(std::round(0.011625f * fConst0), fConst5));
		iConst18 = static_cast<int>(std::min<float>(std::round(0.02475f * fConst0), fConst5));
		iConst19 = static_cast<int>(std::min<float>(std::round(0.01425f * fConst0), fConst5));
		iConst20 = static_cast<int>(std::min<float>(std::round(0.0195f * fConst0), fConst5));
		iConst21 = static_cast<int>(std::min<float>(std::round(0.009f * fConst0), fConst5));
		iConst22 = static_cast<int>(std::min<float>(std::round(0.023125f * fConst0), fConst5));
		iConst23 = static_cast<int>(std::min<float>(std::round(0.015625f * fConst0), fConst5));
		iConst24 = static_cast<int>(std::min<float>(std::round(0.019375f * fConst0), fConst5));
		iConst25 = static_cast<int>(std::min<float>(std::round(0.011875f * fConst0), fConst5));
		iConst26 = static_cast<int>(std::min<float>(std::round(0.02125f * fConst0), fConst5));
		iConst27 = static_cast<int>(std::min<float>(std::round(0.01375f * fConst0), fConst5));
		iConst28 = static_cast<int>(std::min<float>(std::round(0.0175f * fConst0), fConst5));
		iConst29 = static_cast<int>(std::min<float>(std::round(0.01f * fConst0), fConst5));
		fConst30 = std::round(0.08f * fConst0);
		iConst31 = static_cast<int>(std::min<float>(std::round(0.01475f * fConst0), fConst5));
		iConst32 = static_cast<int>(std::min<float>(std::round(0.017625f * fConst0), fConst5));
		iConst33 = static_cast<int>(std::min<float>(std::round(0.0205f * fConst0), fConst5));
		iConst34 = static_cast<int>(std::min<float>(std::round(0.023375f * fConst0), fConst5));
		iConst35 = static_cast<int>(std::min<float>(std::round(0.02625f * fConst0), fConst5));
		iConst36 = static_cast<int>(std::min<float>(std::round(0.029125f * fConst0), fConst5));
		fConst37 = 1.0f / std::tan(471.2389f / fConst0);
		fConst38 = 1.0f - fConst37;
		fConst39 = 1.0f / (fConst37 + 1.0f);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
		fEntry0 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 8192; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 8192; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 4096; l4 = faust_wrap_add(l4, 1)) {
			fVec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 8192; l5 = faust_wrap_add(l5, 1)) {
			fVec3[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 4096; l6 = faust_wrap_add(l6, 1)) {
			fVec4[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 8192; l7 = faust_wrap_add(l7, 1)) {
			fVec5[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 4096; l8 = faust_wrap_add(l8, 1)) {
			fVec6[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 4096; l9 = faust_wrap_add(l9, 1)) {
			fVec7[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2048; l10 = faust_wrap_add(l10, 1)) {
			fVec8[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 8192; l11 = faust_wrap_add(l11, 1)) {
			fVec9[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 4096; l12 = faust_wrap_add(l12, 1)) {
			fVec10[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 4096; l13 = faust_wrap_add(l13, 1)) {
			fVec11[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 4096; l14 = faust_wrap_add(l14, 1)) {
			fVec12[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 4096; l15 = faust_wrap_add(l15, 1)) {
			fVec13[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 4096; l16 = faust_wrap_add(l16, 1)) {
			fVec14[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 4096; l17 = faust_wrap_add(l17, 1)) {
			fVec15[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2048; l18 = faust_wrap_add(l18, 1)) {
			fVec16[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2048; l19 = faust_wrap_add(l19, 1)) {
			fVec17[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec12[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 16384; l21 = faust_wrap_add(l21, 1)) {
			fVec18[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec13[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fVec19[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec11[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec3[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 4096; l26 = faust_wrap_add(l26, 1)) {
			fVec20[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 16384; l27 = faust_wrap_add(l27, 1)) {
			fVec21[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fVec22[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec14[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec4[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 4096; l31 = faust_wrap_add(l31, 1)) {
			fVec23[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 16384; l32 = faust_wrap_add(l32, 1)) {
			fVec24[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fVec25[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec15[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec5[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 4096; l36 = faust_wrap_add(l36, 1)) {
			fVec26[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 16384; l37 = faust_wrap_add(l37, 1)) {
			fVec27[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fVec28[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec16[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec6[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 4096; l41 = faust_wrap_add(l41, 1)) {
			fVec29[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 16384; l42 = faust_wrap_add(l42, 1)) {
			fVec30[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fVec31[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec17[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec7[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 8192; l46 = faust_wrap_add(l46, 1)) {
			fVec32[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 16384; l47 = faust_wrap_add(l47, 1)) {
			fVec33[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fVec34[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec18[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec8[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 8192; l51 = faust_wrap_add(l51, 1)) {
			fVec35[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 16384; l52 = faust_wrap_add(l52, 1)) {
			fVec36[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fVec37[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fRec19[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			fRec9[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 8192; l56 = faust_wrap_add(l56, 1)) {
			fVec38[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 16384; l57 = faust_wrap_add(l57, 1)) {
			fVec39[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = faust_wrap_add(l58, 1)) {
			fVec40[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = faust_wrap_add(l59, 1)) {
			fRec20[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = faust_wrap_add(l60, 1)) {
			fRec10[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = faust_wrap_add(l61, 1)) {
			fVec41[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			fRec2[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = faust_wrap_add(l63, 1)) {
			fRec21[l63] = 0.0f;
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
	
	virtual LibSpringreverb* clone() {
		return new LibSpringreverb(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Spring Tank");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->addHorizontalSlider("Dwell", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Blend", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->addHorizontalSlider("Tone", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->addHorizontalSlider("Tension", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fEntry0, "4", "");
		ui_interface->declare(&fEntry0, "style", "menu{'Left':0;'Right':1;'Middle':2}");
		ui_interface->addNumEntry("Springs", &fEntry0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider4, "5", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider4, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		float fSlow4 = std::max<float>(0.0f, std::min<float>(2.0f, std::round(static_cast<float>(fEntry0))));
		float fSlow5 = ((fSlow4 == 0.0f) ? 2e-06f : ((fSlow4 == 1.0f) ? 0.0005f : 2.8e-05f));
		float fSlow6 = 2.0f * fSlow5;
		float fSlow7 = 3.0f * fSlow5;
		float fSlow8 = 5.0f * fSlow5;
		float fSlow9 = 7.0f * fSlow5;
		float fSlow10 = 11.0f * fSlow5;
		float fSlow11 = 13.0f * fSlow5;
		float fSlow12 = 17.0f * fSlow5;
		float fSlow13 = fConst1 * static_cast<float>(fHslider4);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = std::max<float>(0.0f, std::min<float>(1e+01f, 1e+01f * fRec0[0]));
			float fTemp1 = fTemp0 * (1.9e+02f * fTemp0 + 5e+01f) + 1.5e+03f;
			fRec1[0] = fSlow1 + fConst2 * fRec1[1];
			float fTemp2 = 1.0f / std::tan(fConst3 * fTemp1);
			float fTemp3 = fTemp2 + 1.0f;
			float fTemp4 = static_cast<float>(input0[i0]);
			fVec0[IOTA0 & 8191] = fTemp4;
			float fTemp5 = fVec0[(faust_wrap_sub(IOTA0, iConst6)) & 8191];
			float fTemp6 = fVec0[(faust_wrap_sub(IOTA0, iConst7)) & 8191];
			float fTemp7 = fTemp6 - fTemp5;
			float fTemp8 = fVec0[(faust_wrap_sub(IOTA0, iConst8)) & 8191];
			float fTemp9 = fVec0[(faust_wrap_sub(IOTA0, iConst9)) & 8191];
			float fTemp10 = fTemp9 - fTemp8;
			float fTemp11 = fTemp10 - fTemp7;
			float fTemp12 = fVec0[(faust_wrap_sub(IOTA0, iConst10)) & 8191];
			float fTemp13 = fVec0[(faust_wrap_sub(IOTA0, iConst11)) & 8191];
			float fTemp14 = fTemp13 - fTemp12;
			float fTemp15 = fVec0[(faust_wrap_sub(IOTA0, iConst12)) & 8191];
			float fTemp16 = fVec0[(faust_wrap_sub(IOTA0, iConst13)) & 8191];
			float fTemp17 = fTemp16 - fTemp15;
			float fTemp18 = fTemp17 - fTemp14;
			fVec1[IOTA0 & 8191] = fTemp18 - fTemp11;
			float fTemp19 = fVec1[(faust_wrap_sub(IOTA0, iConst14)) & 8191];
			float fTemp20 = fTemp6 + fTemp5;
			float fTemp21 = fTemp9 + fTemp8;
			float fTemp22 = fTemp21 - fTemp20;
			float fTemp23 = fTemp13 + fTemp12;
			float fTemp24 = fTemp16 + fTemp15;
			float fTemp25 = fTemp24 - fTemp23;
			fVec2[IOTA0 & 4095] = fTemp25 - fTemp22;
			float fTemp26 = fVec2[(faust_wrap_sub(IOTA0, iConst15)) & 4095];
			float fTemp27 = fTemp26 + fTemp19;
			float fTemp28 = fTemp10 + fTemp7;
			float fTemp29 = fTemp17 + fTemp14;
			fVec3[IOTA0 & 8191] = fTemp29 - fTemp28;
			float fTemp30 = fVec3[(faust_wrap_sub(IOTA0, iConst16)) & 8191];
			float fTemp31 = fTemp21 + fTemp20;
			float fTemp32 = fTemp24 + fTemp23;
			fVec4[IOTA0 & 4095] = fTemp32 - fTemp31;
			float fTemp33 = fVec4[(faust_wrap_sub(IOTA0, iConst17)) & 4095];
			float fTemp34 = fTemp33 + fTemp30;
			float fTemp35 = fTemp34 + fTemp27;
			fVec5[IOTA0 & 8191] = fTemp18 + fTemp11;
			float fTemp36 = fVec5[(faust_wrap_sub(IOTA0, iConst18)) & 8191];
			fVec6[IOTA0 & 4095] = fTemp25 + fTemp22;
			float fTemp37 = fVec6[(faust_wrap_sub(IOTA0, iConst19)) & 4095];
			float fTemp38 = fTemp37 + fTemp36;
			fVec7[IOTA0 & 4095] = fTemp29 + fTemp28;
			float fTemp39 = fVec7[(faust_wrap_sub(IOTA0, iConst20)) & 4095];
			fVec8[IOTA0 & 2047] = fTemp32 + fTemp31;
			float fTemp40 = fVec8[(faust_wrap_sub(IOTA0, iConst21)) & 2047];
			float fTemp41 = fTemp40 + fTemp39;
			float fTemp42 = fTemp41 - fTemp38;
			fVec9[IOTA0 & 8191] = fTemp42 + fTemp35;
			float fTemp43 = fVec9[(faust_wrap_sub(IOTA0, iConst22)) & 8191];
			float fTemp44 = fTemp26 - fTemp19;
			float fTemp45 = fTemp33 - fTemp30;
			float fTemp46 = fTemp45 + fTemp44;
			float fTemp47 = fTemp37 - fTemp36;
			float fTemp48 = fTemp40 - fTemp39;
			float fTemp49 = fTemp48 - fTemp47;
			fVec10[IOTA0 & 4095] = fTemp49 + fTemp46;
			float fTemp50 = fVec10[(faust_wrap_sub(IOTA0, iConst23)) & 4095];
			float fTemp51 = fTemp50 + fTemp43;
			float fTemp52 = fTemp34 - fTemp27;
			float fTemp53 = fTemp41 + fTemp38;
			fVec11[IOTA0 & 4095] = fTemp53 + fTemp52;
			float fTemp54 = fVec11[(faust_wrap_sub(IOTA0, iConst24)) & 4095];
			float fTemp55 = fTemp45 - fTemp44;
			float fTemp56 = fTemp48 + fTemp47;
			fVec12[IOTA0 & 4095] = fTemp56 + fTemp55;
			float fTemp57 = fVec12[(faust_wrap_sub(IOTA0, iConst25)) & 4095];
			float fTemp58 = fTemp57 + fTemp54;
			float fTemp59 = fTemp58 - fTemp51;
			fVec13[IOTA0 & 4095] = fTemp42 - fTemp35;
			float fTemp60 = fVec13[(faust_wrap_sub(IOTA0, iConst26)) & 4095];
			fVec14[IOTA0 & 4095] = fTemp49 - fTemp46;
			float fTemp61 = fVec14[(faust_wrap_sub(IOTA0, iConst27)) & 4095];
			float fTemp62 = fTemp61 + fTemp60;
			fVec15[IOTA0 & 4095] = fTemp53 - fTemp52;
			float fTemp63 = fVec15[(faust_wrap_sub(IOTA0, iConst28)) & 4095];
			fVec16[IOTA0 & 2047] = fTemp56 - fTemp55;
			float fTemp64 = fVec16[(faust_wrap_sub(IOTA0, iConst29)) & 2047];
			float fTemp65 = fTemp64 - fTemp63;
			float fTemp66 = fTemp65 - fTemp62;
			fVec17[IOTA0 & 2047] = fTemp66 - fTemp59;
			fRec12[0] = fSlow2 + fConst2 * fRec12[1];
			float fTemp67 = std::max<float>(0.0f, std::min<float>(1e+01f, 1e+01f * fRec12[0]));
			float fTemp68 = fTemp67 * (0.013f - 0.0006f * fTemp67) + 0.26f;
			float fTemp69 = fRec3[1] + fRec7[1];
			float fTemp70 = fRec9[1] + fTemp69 + fRec5[1];
			fVec18[IOTA0 & 16383] = (fRec10[1] + fRec6[1] + fRec8[1] + fTemp70 + fRec4[1]) * fTemp68 - 0.01f * fVec17[(faust_wrap_sub(IOTA0, iConst21)) & 2047];
			fRec13[0] = fSlow3 + fConst2 * fRec13[1];
			float fTemp71 = std::max<float>(0.0f, std::min<float>(1e+01f, 1e+01f * fRec13[0]));
			float fTemp72 = fTemp71 * (0.00032f * fTemp71 + -0.0072f);
			float fTemp73 = fVec18[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst30, std::max<float>(0.0f, std::round(fConst0 * (fSlow5 + fTemp72 + 0.07f))))))) & 16383];
			fVec19[0] = fTemp73;
			float fTemp74 = 1.0f - fTemp2;
			fRec11[0] = -((fRec11[1] * fTemp74 - (fTemp73 + fVec19[1])) / fTemp3);
			float fTemp75 = fRec11[0] - fRec11[1];
			fRec3[0] = ((std::fabs(fTemp75) <= 0.001f) ? std::max<float>(-1.0f, std::min<float>(1.0f, 0.5f * (fRec11[0] + fRec11[1]))) : ((((fRec11[0] <= 1.0f) & (fRec11[0] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec11[0]) : fRec11[0] * static_cast<float>((fRec11[0] > 0.0f) - (fRec11[0] < 0.0f)) + -0.5f) - (((fRec11[1] <= 1.0f) & (fRec11[1] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec11[1]) : fRec11[1] * static_cast<float>((fRec11[1] > 0.0f) - (fRec11[1] < 0.0f)) + -0.5f)) / fTemp75);
			fVec20[IOTA0 & 4095] = fTemp66 + fTemp59;
			fVec21[IOTA0 & 16383] = fTemp68 * (fTemp70 - (fRec10[1] + fRec4[1] + fRec8[1] + fRec6[1])) + 0.01f * fVec20[(faust_wrap_sub(IOTA0, iConst25)) & 4095];
			float fTemp76 = fVec21[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst30, std::max<float>(0.0f, std::round(fConst0 * (fSlow6 + fTemp72 + 0.07f))))))) & 16383];
			fVec22[0] = fTemp76;
			fRec14[0] = -((fTemp74 * fRec14[1] - (fTemp76 + fVec22[1])) / fTemp3);
			float fTemp77 = fRec14[0] - fRec14[1];
			fRec4[0] = ((std::fabs(fTemp77) <= 0.001f) ? std::max<float>(-1.0f, std::min<float>(1.0f, 0.5f * (fRec14[0] + fRec14[1]))) : ((((fRec14[0] <= 1.0f) & (fRec14[0] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec14[0]) : fRec14[0] * static_cast<float>((fRec14[0] > 0.0f) - (fRec14[0] < 0.0f)) + -0.5f) - (((fRec14[1] <= 1.0f) & (fRec14[1] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec14[1]) : fRec14[1] * static_cast<float>((fRec14[1] > 0.0f) - (fRec14[1] < 0.0f)) + -0.5f)) / fTemp77);
			float fTemp78 = fTemp58 + fTemp51;
			float fTemp79 = fTemp65 + fTemp62;
			fVec23[IOTA0 & 4095] = fTemp79 - fTemp78;
			float fTemp80 = fRec5[1] + fRec9[1];
			fVec24[IOTA0 & 16383] = fTemp68 * (fRec8[1] + fTemp69 + fRec4[1] - (fRec10[1] + fTemp80 + fRec6[1])) + 0.01f * fVec23[(faust_wrap_sub(IOTA0, iConst31)) & 4095];
			float fTemp81 = fVec24[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst30, std::max<float>(0.0f, std::round(fConst0 * (fSlow7 + fTemp72 + 0.07f))))))) & 16383];
			fVec25[0] = fTemp81;
			fRec15[0] = -((fTemp74 * fRec15[1] - (fTemp81 + fVec25[1])) / fTemp3);
			float fTemp82 = fRec15[0] - fRec15[1];
			fRec5[0] = ((std::fabs(fTemp82) <= 0.001f) ? std::max<float>(-1.0f, std::min<float>(1.0f, 0.5f * (fRec15[0] + fRec15[1]))) : ((((fRec15[0] <= 1.0f) & (fRec15[0] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec15[0]) : fRec15[0] * static_cast<float>((fRec15[0] > 0.0f) - (fRec15[0] < 0.0f)) + -0.5f) - (((fRec15[1] <= 1.0f) & (fRec15[1] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec15[1]) : fRec15[1] * static_cast<float>((fRec15[1] > 0.0f) - (fRec15[1] < 0.0f)) + -0.5f)) / fTemp82);
			fVec26[IOTA0 & 4095] = fTemp79 + fTemp78;
			fVec27[IOTA0 & 16383] = fTemp68 * (fRec10[1] + fTemp69 + fRec6[1] - (fRec8[1] + fTemp80 + fRec4[1])) - 0.01f * fVec26[(faust_wrap_sub(IOTA0, iConst32)) & 4095];
			float fTemp83 = fVec27[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst30, std::max<float>(0.0f, std::round(fConst0 * (fSlow8 + fTemp72 + 0.07f))))))) & 16383];
			fVec28[0] = fTemp83;
			fRec16[0] = -((fTemp74 * fRec16[1] - (fTemp83 + fVec28[1])) / fTemp3);
			float fTemp84 = fRec16[0] - fRec16[1];
			fRec6[0] = ((std::fabs(fTemp84) <= 0.001f) ? std::max<float>(-1.0f, std::min<float>(1.0f, 0.5f * (fRec16[0] + fRec16[1]))) : ((((fRec16[0] <= 1.0f) & (fRec16[0] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec16[0]) : fRec16[0] * static_cast<float>((fRec16[0] > 0.0f) - (fRec16[0] < 0.0f)) + -0.5f) - (((fRec16[1] <= 1.0f) & (fRec16[1] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec16[1]) : fRec16[1] * static_cast<float>((fRec16[1] > 0.0f) - (fRec16[1] < 0.0f)) + -0.5f)) / fTemp84);
			float fTemp85 = fTemp50 - fTemp43;
			float fTemp86 = fTemp57 - fTemp54;
			float fTemp87 = fTemp86 - fTemp85;
			float fTemp88 = fTemp61 - fTemp60;
			float fTemp89 = fTemp64 + fTemp63;
			float fTemp90 = fTemp89 - fTemp88;
			fVec29[IOTA0 & 4095] = fTemp90 - fTemp87;
			float fTemp91 = fRec7[1] + fRec9[1];
			float fTemp92 = fRec3[1] + fRec5[1];
			fVec30[IOTA0 & 16383] = fTemp68 * (fRec6[1] + fRec4[1] + fTemp92 - (fRec10[1] + fRec8[1] + fTemp91)) - 0.01f * fVec29[(faust_wrap_sub(IOTA0, iConst33)) & 4095];
			float fTemp93 = fVec30[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst30, std::max<float>(0.0f, std::round(fConst0 * (fSlow9 + fTemp72 + 0.07f))))))) & 16383];
			fVec31[0] = fTemp93;
			fRec17[0] = -((fTemp74 * fRec17[1] - (fTemp93 + fVec31[1])) / fTemp3);
			float fTemp94 = fRec17[0] - fRec17[1];
			fRec7[0] = ((std::fabs(fTemp94) <= 0.001f) ? std::max<float>(-1.0f, std::min<float>(1.0f, 0.5f * (fRec17[0] + fRec17[1]))) : ((((fRec17[0] <= 1.0f) & (fRec17[0] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec17[0]) : fRec17[0] * static_cast<float>((fRec17[0] > 0.0f) - (fRec17[0] < 0.0f)) + -0.5f) - (((fRec17[1] <= 1.0f) & (fRec17[1] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec17[1]) : fRec17[1] * static_cast<float>((fRec17[1] > 0.0f) - (fRec17[1] < 0.0f)) + -0.5f)) / fTemp94);
			fVec32[IOTA0 & 8191] = fTemp90 + fTemp87;
			fVec33[IOTA0 & 16383] = fTemp68 * (fRec10[1] + fRec8[1] + fTemp92 - (fRec6[1] + fRec4[1] + fTemp91)) - 0.01f * fVec32[(faust_wrap_sub(IOTA0, iConst34)) & 8191];
			float fTemp95 = fVec33[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst30, std::max<float>(0.0f, std::round(fConst0 * (fSlow10 + fTemp72 + 0.07f))))))) & 16383];
			fVec34[0] = fTemp95;
			fRec18[0] = -((fTemp74 * fRec18[1] - (fTemp95 + fVec34[1])) / fTemp3);
			float fTemp96 = fRec18[0] - fRec18[1];
			fRec8[0] = ((std::fabs(fTemp96) <= 0.001f) ? std::max<float>(-1.0f, std::min<float>(1.0f, 0.5f * (fRec18[0] + fRec18[1]))) : ((((fRec18[0] <= 1.0f) & (fRec18[0] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec18[0]) : fRec18[0] * static_cast<float>((fRec18[0] > 0.0f) - (fRec18[0] < 0.0f)) + -0.5f) - (((fRec18[1] <= 1.0f) & (fRec18[1] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec18[1]) : fRec18[1] * static_cast<float>((fRec18[1] > 0.0f) - (fRec18[1] < 0.0f)) + -0.5f)) / fTemp96);
			float fTemp97 = fTemp86 + fTemp85;
			float fTemp98 = fTemp89 + fTemp88;
			fVec35[IOTA0 & 8191] = fTemp98 - fTemp97;
			float fTemp99 = fRec7[1] + fRec5[1];
			float fTemp100 = fRec3[1] + fRec9[1];
			fVec36[IOTA0 & 16383] = fTemp68 * (fRec10[1] + fRec4[1] + fTemp100 - (fRec6[1] + fRec8[1] + fTemp99)) + 0.01f * fVec35[(faust_wrap_sub(IOTA0, iConst35)) & 8191];
			float fTemp101 = fVec36[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst30, std::max<float>(0.0f, std::round(fConst0 * (fSlow11 + fTemp72 + 0.07f))))))) & 16383];
			fVec37[0] = fTemp101;
			fRec19[0] = -((fTemp74 * fRec19[1] - (fTemp101 + fVec37[1])) / fTemp3);
			float fTemp102 = fRec19[0] - fRec19[1];
			fRec9[0] = ((std::fabs(fTemp102) <= 0.001f) ? std::max<float>(-1.0f, std::min<float>(1.0f, 0.5f * (fRec19[0] + fRec19[1]))) : ((((fRec19[0] <= 1.0f) & (fRec19[0] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec19[0]) : fRec19[0] * static_cast<float>((fRec19[0] > 0.0f) - (fRec19[0] < 0.0f)) + -0.5f) - (((fRec19[1] <= 1.0f) & (fRec19[1] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec19[1]) : fRec19[1] * static_cast<float>((fRec19[1] > 0.0f) - (fRec19[1] < 0.0f)) + -0.5f)) / fTemp102);
			fVec38[IOTA0 & 8191] = fTemp98 + fTemp97;
			fVec39[IOTA0 & 16383] = fTemp68 * (fRec6[1] + fRec8[1] + fTemp100 - (fRec10[1] + fRec4[1] + fTemp99)) - 0.01f * fVec38[(faust_wrap_sub(IOTA0, iConst36)) & 8191];
			float fTemp103 = fVec39[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst30, std::max<float>(0.0f, std::round(fConst0 * (fSlow12 + fTemp72 + 0.07f))))))) & 16383];
			fVec40[0] = fTemp103;
			fRec20[0] = -((fTemp74 * fRec20[1] - (fTemp103 + fVec40[1])) / fTemp3);
			float fTemp104 = fRec20[0] - fRec20[1];
			fRec10[0] = ((std::fabs(fTemp104) <= 0.001f) ? std::max<float>(-1.0f, std::min<float>(1.0f, 0.5f * (fRec20[0] + fRec20[1]))) : ((((fRec20[0] <= 1.0f) & (fRec20[0] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec20[0]) : fRec20[0] * static_cast<float>((fRec20[0] > 0.0f) - (fRec20[0] < 0.0f)) + -0.5f) - (((fRec20[1] <= 1.0f) & (fRec20[1] >= -1.0f)) ? 0.5f * LibSpringreverb_faustpower2_f(fRec20[1]) : fRec20[1] * static_cast<float>((fRec20[1] > 0.0f) - (fRec20[1] < 0.0f)) + -0.5f)) / fTemp104);
			float fTemp105 = fRec3[0] + fRec4[0] + fRec5[0] + fRec6[0] + fRec7[0] + fRec8[0] + fRec9[0] + fRec10[0];
			fVec41[0] = fTemp105;
			fRec2[0] = -(fConst39 * (fConst38 * fRec2[1] - fConst37 * (fTemp105 - fVec41[1])));
			fRec21[0] = fSlow13 + fConst2 * fRec21[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp4 * (1.0f - fRec21[0]) + fRec21[0] * (fTemp4 + 0.04f * fRec2[0] * std::max<float>(0.0f, std::min<float>(1e+01f, 1e+01f * fRec1[0])) * std::min<float>(5.0f, 2e+03f / fTemp1 + 1.0f)));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fVec19[1] = fVec19[0];
			fRec11[1] = fRec11[0];
			fRec3[1] = fRec3[0];
			fVec22[1] = fVec22[0];
			fRec14[1] = fRec14[0];
			fRec4[1] = fRec4[0];
			fVec25[1] = fVec25[0];
			fRec15[1] = fRec15[0];
			fRec5[1] = fRec5[0];
			fVec28[1] = fVec28[0];
			fRec16[1] = fRec16[0];
			fRec6[1] = fRec6[0];
			fVec31[1] = fVec31[0];
			fRec17[1] = fRec17[0];
			fRec7[1] = fRec7[0];
			fVec34[1] = fVec34[0];
			fRec18[1] = fRec18[0];
			fRec8[1] = fRec8[0];
			fVec37[1] = fVec37[0];
			fRec19[1] = fRec19[0];
			fRec9[1] = fRec9[0];
			fVec40[1] = fVec40[0];
			fRec20[1] = fRec20[0];
			fRec10[1] = fRec10[0];
			fVec41[1] = fVec41[0];
			fRec2[1] = fRec2[0];
			fRec21[1] = fRec21[0];
		}
	}

};

#endif
