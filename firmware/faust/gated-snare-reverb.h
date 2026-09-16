/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "GatedSnareReverb"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GatedSnareReverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __GatedSnareReverb_H__
#define  __GatedSnareReverb_H__

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
#define FAUSTCLASS GatedSnareReverb
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

static float GatedSnareReverb_faustpower2_f(float value) {
	return value * value;
}

class GatedSnareReverb : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec9[2];
	float fRec10[2];
	float fVec0[2];
	float fConst3;
	float fConst4;
	float fConst5;
	float fRec11[2];
	int IOTA0;
	float fVec1[8192];
	int iConst6;
	int iConst7;
	float fRec8[2];
	float fRec13[2];
	float fVec2[8192];
	int iConst8;
	int iConst9;
	float fRec12[2];
	float fRec15[2];
	float fVec3[8192];
	int iConst10;
	int iConst11;
	float fRec14[2];
	float fRec17[2];
	float fVec4[8192];
	int iConst12;
	int iConst13;
	float fRec16[2];
	float fRec19[2];
	float fVec5[8192];
	int iConst14;
	int iConst15;
	float fRec18[2];
	float fRec21[2];
	float fVec6[8192];
	int iConst16;
	int iConst17;
	float fRec20[2];
	float fRec23[2];
	float fVec7[8192];
	int iConst18;
	int iConst19;
	float fRec22[2];
	float fRec25[2];
	float fVec8[8192];
	int iConst20;
	int iConst21;
	float fRec24[2];
	float fVec9[2048];
	int iConst22;
	int iConst23;
	float fRec6[2];
	float fVec10[2048];
	int iConst24;
	int iConst25;
	float fRec4[2];
	float fVec11[2048];
	int iConst26;
	int iConst27;
	float fRec2[2];
	float fVec12[1024];
	int iConst28;
	int iConst29;
	float fRec0[2];
	float fRec35[2];
	float fVec13[8192];
	int iConst30;
	float fRec34[2];
	float fRec37[2];
	float fVec14[8192];
	int iConst31;
	float fRec36[2];
	float fRec39[2];
	float fVec15[8192];
	int iConst32;
	float fRec38[2];
	float fRec41[2];
	float fVec16[8192];
	int iConst33;
	float fRec40[2];
	float fRec43[2];
	float fVec17[8192];
	int iConst34;
	float fRec42[2];
	float fRec45[2];
	float fVec18[8192];
	int iConst35;
	float fRec44[2];
	float fRec47[2];
	float fVec19[8192];
	int iConst36;
	float fRec46[2];
	float fRec49[2];
	float fVec20[8192];
	int iConst37;
	float fRec48[2];
	float fVec21[2048];
	int iConst38;
	float fRec32[2];
	float fVec22[2048];
	int iConst39;
	float fRec30[2];
	float fVec23[2048];
	int iConst40;
	float fRec28[2];
	float fVec24[1024];
	int iConst41;
	float fRec26[2];
	float fConst42;
	float fConst43;
	float fConst44;
	float fConst45;
	float fConst46;
	float fConst47;
	float fConst48;
	float fConst49;
	float fConst50;
	float fConst51;
	float fConst52;
	float fConst53;
	float fRec52[3];
	float fConst54;
	FAUSTFLOAT fHslider1;
	float fConst55;
	float fRec51[2];
	float fConst56;
	float fRec50[2];
	FAUSTFLOAT fHslider2;
	float fRec53[2];
	
 public:
	GatedSnareReverb() {
	}
	
	GatedSnareReverb(const GatedSnareReverb&) = default;
	
	virtual ~GatedSnareReverb() = default;
	
	GatedSnareReverb& operator=(const GatedSnareReverb&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Chameleon DSP");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GatedSnareReverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Big room reverb keyed by the dry input and slammed shut after a hold time");
		m->declare("filename", "gated-snare-reverb.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/bandpass0_bandstop1:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass0_bandstop1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass0_bandstop1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/bandpass:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass0_highpass1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1sb:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1sb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1sb:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "GatedSnareReverb");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/mono_freeverb:author", "Romain Michon");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/stereo_freeverb:author", "Romain Michon");
		m->declare("reverbs.lib/version", "1.5.1");
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
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.0f / std::tan(439.82297f / fConst0);
		fConst4 = 1.0f - fConst3;
		fConst5 = 1.0f / (fConst3 + 1.0f);
		iConst6 = static_cast<int>(0.025306122f * fConst0);
		iConst7 = static_cast<int>(std::max<float>(0.0f, static_cast<float>(iConst6) + -0.3f));
		iConst8 = static_cast<int>(0.026938776f * fConst0);
		iConst9 = static_cast<int>(std::max<float>(0.0f, static_cast<float>(iConst8) + -0.3f));
		iConst10 = static_cast<int>(0.028956916f * fConst0);
		iConst11 = static_cast<int>(std::max<float>(0.0f, static_cast<float>(iConst10) + -0.3f));
		iConst12 = static_cast<int>(0.030748298f * fConst0);
		iConst13 = static_cast<int>(std::max<float>(0.0f, static_cast<float>(iConst12) + -0.3f));
		iConst14 = static_cast<int>(0.0322449f * fConst0);
		iConst15 = static_cast<int>(std::max<float>(0.0f, static_cast<float>(iConst14) + -0.3f));
		iConst16 = static_cast<int>(0.033809524f * fConst0);
		iConst17 = static_cast<int>(std::max<float>(0.0f, static_cast<float>(iConst16) + -0.3f));
		iConst18 = static_cast<int>(0.035306122f * fConst0);
		iConst19 = static_cast<int>(std::max<float>(0.0f, static_cast<float>(iConst18) + -0.3f));
		iConst20 = static_cast<int>(0.036666665f * fConst0);
		iConst21 = static_cast<int>(std::max<float>(0.0f, static_cast<float>(iConst20) + -0.3f));
		iConst22 = static_cast<int>(0.0126077095f * fConst0);
		iConst23 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, static_cast<float>(iConst22) + -0.3f)));
		iConst24 = static_cast<int>(0.01f * fConst0);
		iConst25 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, static_cast<float>(iConst24) + -0.3f)));
		iConst26 = static_cast<int>(0.0077324263f * fConst0);
		iConst27 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, static_cast<float>(iConst26) + -0.3f)));
		iConst28 = static_cast<int>(0.0051020407f * fConst0);
		iConst29 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, static_cast<float>(iConst28) + -0.3f)));
		iConst30 = std::max<int>(0, faust_wrap_add(iConst6, -1));
		iConst31 = std::max<int>(0, faust_wrap_add(iConst8, -1));
		iConst32 = std::max<int>(0, faust_wrap_add(iConst10, -1));
		iConst33 = std::max<int>(0, faust_wrap_add(iConst12, -1));
		iConst34 = std::max<int>(0, faust_wrap_add(iConst14, -1));
		iConst35 = std::max<int>(0, faust_wrap_add(iConst16, -1));
		iConst36 = std::max<int>(0, faust_wrap_add(iConst18, -1));
		iConst37 = std::max<int>(0, faust_wrap_add(iConst20, -1));
		iConst38 = std::min<int>(1024, std::max<int>(0, faust_wrap_add(iConst22, -1)));
		iConst39 = std::min<int>(1024, std::max<int>(0, faust_wrap_add(iConst24, -1)));
		iConst40 = std::min<int>(1024, std::max<int>(0, faust_wrap_add(iConst26, -1)));
		iConst41 = std::min<int>(1024, std::max<int>(0, faust_wrap_add(iConst28, -1)));
		fConst42 = std::exp(-(333.33334f / fConst0));
		fConst43 = std::tan(5026.5483f / fConst0);
		fConst44 = fConst0 * fConst43;
		fConst45 = GatedSnareReverb_faustpower2_f(std::sqrt(4.0f * GatedSnareReverb_faustpower2_f(fConst0) * std::tan(282.74335f / fConst0) * fConst43));
		fConst46 = 2.0f * fConst44 - 0.5f * (fConst45 / fConst44);
		fConst47 = 2.0f * (fConst46 / fConst0);
		fConst48 = 1.0f / fConst0;
		fConst49 = GatedSnareReverb_faustpower2_f(fConst48) * fConst45;
		fConst50 = fConst49 + (4.0f - fConst47);
		fConst51 = 2.0f * fConst49 + -8.0f;
		fConst52 = fConst49 + fConst47 + 4.0f;
		fConst53 = 1.0f / fConst52;
		fConst54 = 2.0f * (fConst46 / (fConst0 * fConst52));
		fConst55 = std::exp(-(2e+03f / fConst0));
		fConst56 = 1.0f - fConst42;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.8f);
		fHslider1 = static_cast<FAUSTFLOAT>(2.2e+02f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.6f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec9[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec10[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec11[l3] = 0.0f;
		}
		IOTA0 = 0;
		for (int l4 = 0; l4 < 8192; l4 = faust_wrap_add(l4, 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec8[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec13[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 8192; l7 = faust_wrap_add(l7, 1)) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec12[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec15[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 8192; l10 = faust_wrap_add(l10, 1)) {
			fVec3[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec14[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec17[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 8192; l13 = faust_wrap_add(l13, 1)) {
			fVec4[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec16[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec19[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 8192; l16 = faust_wrap_add(l16, 1)) {
			fVec5[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec18[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec21[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 8192; l19 = faust_wrap_add(l19, 1)) {
			fVec6[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec20[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec23[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 8192; l22 = faust_wrap_add(l22, 1)) {
			fVec7[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec22[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec25[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 8192; l25 = faust_wrap_add(l25, 1)) {
			fVec8[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec24[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2048; l27 = faust_wrap_add(l27, 1)) {
			fVec9[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec6[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2048; l29 = faust_wrap_add(l29, 1)) {
			fVec10[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec4[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2048; l31 = faust_wrap_add(l31, 1)) {
			fVec11[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec2[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 1024; l33 = faust_wrap_add(l33, 1)) {
			fVec12[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec0[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec35[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 8192; l36 = faust_wrap_add(l36, 1)) {
			fVec13[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec34[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fRec37[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 8192; l39 = faust_wrap_add(l39, 1)) {
			fVec14[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec36[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec39[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 8192; l42 = faust_wrap_add(l42, 1)) {
			fVec15[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec38[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec41[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 8192; l45 = faust_wrap_add(l45, 1)) {
			fVec16[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fRec40[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fRec43[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 8192; l48 = faust_wrap_add(l48, 1)) {
			fVec17[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec42[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec45[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 8192; l51 = faust_wrap_add(l51, 1)) {
			fVec18[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec44[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fRec47[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 8192; l54 = faust_wrap_add(l54, 1)) {
			fVec19[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			fRec46[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fRec49[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 8192; l57 = faust_wrap_add(l57, 1)) {
			fVec20[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = faust_wrap_add(l58, 1)) {
			fRec48[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2048; l59 = faust_wrap_add(l59, 1)) {
			fVec21[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = faust_wrap_add(l60, 1)) {
			fRec32[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2048; l61 = faust_wrap_add(l61, 1)) {
			fVec22[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			fRec30[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2048; l63 = faust_wrap_add(l63, 1)) {
			fVec23[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 2; l64 = faust_wrap_add(l64, 1)) {
			fRec28[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 1024; l65 = faust_wrap_add(l65, 1)) {
			fVec24[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = faust_wrap_add(l66, 1)) {
			fRec26[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 3; l67 = faust_wrap_add(l67, 1)) {
			fRec52[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 2; l68 = faust_wrap_add(l68, 1)) {
			fRec51[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 2; l69 = faust_wrap_add(l69, 1)) {
			fRec50[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2; l70 = faust_wrap_add(l70, 1)) {
			fRec53[l70] = 0.0f;
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
	
	virtual GatedSnareReverb* clone() {
		return new GatedSnareReverb(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("GatedSnareReverb");
		ui_interface->declare(&fHslider1, "unit", "ms");
		ui_interface->addHorizontalSlider("Gate Hold", &fHslider1, FAUSTFLOAT(2.2e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(5e+02f), FAUSTFLOAT(5.0f));
		ui_interface->addHorizontalSlider("Room Size", &fHslider0, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.1f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->addHorizontalSlider("Wet Mix", &fHslider2, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = 0.001f * static_cast<float>(fHslider1);
		int iSlow2 = std::fabs(fSlow1) < 1.1920929e-07f;
		float fSlow3 = ((iSlow2) ? 0.0f : std::exp(-(fConst48 / ((iSlow2) ? 1.0f : fSlow1))));
		float fSlow4 = fConst1 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec9[0] = fSlow0 + fConst2 * fRec9[1];
			float fTemp0 = 0.25f * fRec9[0] + 0.7f;
			fRec10[0] = 0.25f * fRec10[1] + 0.75f * fRec8[1];
			float fTemp1 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp1;
			fRec11[0] = -(fConst5 * (fConst4 * fRec11[1] - fConst3 * (fTemp1 - fVec0[1])));
			float fTemp2 = 2.0f * fRec11[0];
			fVec1[IOTA0 & 8191] = fTemp2 + fRec10[0] * fTemp0;
			fRec8[0] = fVec1[(faust_wrap_sub(IOTA0, iConst7)) & 8191];
			fRec13[0] = 0.25f * fRec13[1] + 0.75f * fRec12[1];
			fVec2[IOTA0 & 8191] = fTemp2 + fRec13[0] * fTemp0;
			fRec12[0] = fVec2[(faust_wrap_sub(IOTA0, iConst9)) & 8191];
			fRec15[0] = 0.25f * fRec15[1] + 0.75f * fRec14[1];
			fVec3[IOTA0 & 8191] = fTemp2 + fRec15[0] * fTemp0;
			fRec14[0] = fVec3[(faust_wrap_sub(IOTA0, iConst11)) & 8191];
			fRec17[0] = 0.25f * fRec17[1] + 0.75f * fRec16[1];
			fVec4[IOTA0 & 8191] = fTemp2 + fRec17[0] * fTemp0;
			fRec16[0] = fVec4[(faust_wrap_sub(IOTA0, iConst13)) & 8191];
			fRec19[0] = 0.25f * fRec19[1] + 0.75f * fRec18[1];
			fVec5[IOTA0 & 8191] = fTemp2 + fRec19[0] * fTemp0;
			fRec18[0] = fVec5[(faust_wrap_sub(IOTA0, iConst15)) & 8191];
			fRec21[0] = 0.25f * fRec21[1] + 0.75f * fRec20[1];
			fVec6[IOTA0 & 8191] = fTemp2 + fRec21[0] * fTemp0;
			fRec20[0] = fVec6[(faust_wrap_sub(IOTA0, iConst17)) & 8191];
			fRec23[0] = 0.25f * fRec23[1] + 0.75f * fRec22[1];
			fVec7[IOTA0 & 8191] = fTemp2 + fRec23[0] * fTemp0;
			fRec22[0] = fVec7[(faust_wrap_sub(IOTA0, iConst19)) & 8191];
			fRec25[0] = 0.25f * fRec25[1] + 0.75f * fRec24[1];
			fVec8[IOTA0 & 8191] = fTemp2 + fRec25[0] * fTemp0;
			fRec24[0] = fVec8[(faust_wrap_sub(IOTA0, iConst21)) & 8191];
			float fTemp3 = fRec24[1] + fRec22[1] + fRec20[1] + fRec18[1] + fRec16[1] + fRec14[1] + fRec12[1] + 0.5f * fRec6[1] + fRec8[1];
			fVec9[IOTA0 & 2047] = fTemp3;
			fRec6[0] = fVec9[(faust_wrap_sub(IOTA0, iConst23)) & 2047];
			float fRec7 = -(0.5f * fTemp3);
			float fTemp4 = fRec6[1] + fRec7 + 0.5f * fRec4[1];
			fVec10[IOTA0 & 2047] = fTemp4;
			fRec4[0] = fVec10[(faust_wrap_sub(IOTA0, iConst25)) & 2047];
			float fRec5 = -(0.5f * fTemp4);
			float fTemp5 = fRec4[1] + fRec5 + 0.5f * fRec2[1];
			fVec11[IOTA0 & 2047] = fTemp5;
			fRec2[0] = fVec11[(faust_wrap_sub(IOTA0, iConst27)) & 2047];
			float fRec3 = -(0.5f * fTemp5);
			float fTemp6 = fRec2[1] + fRec3 + 0.5f * fRec0[1];
			fVec12[IOTA0 & 1023] = fTemp6;
			fRec0[0] = fVec12[(faust_wrap_sub(IOTA0, iConst29)) & 1023];
			float fRec1 = -(0.5f * fTemp6);
			fRec35[0] = 0.25f * fRec35[1] + 0.75f * fRec34[1];
			fVec13[IOTA0 & 8191] = fRec35[0] * fTemp0 + fTemp2;
			fRec34[0] = fVec13[(faust_wrap_sub(IOTA0, iConst30)) & 8191];
			fRec37[0] = 0.25f * fRec37[1] + 0.75f * fRec36[1];
			fVec14[IOTA0 & 8191] = fTemp2 + fRec37[0] * fTemp0;
			fRec36[0] = fVec14[(faust_wrap_sub(IOTA0, iConst31)) & 8191];
			fRec39[0] = 0.25f * fRec39[1] + 0.75f * fRec38[1];
			fVec15[IOTA0 & 8191] = fTemp2 + fRec39[0] * fTemp0;
			fRec38[0] = fVec15[(faust_wrap_sub(IOTA0, iConst32)) & 8191];
			fRec41[0] = 0.25f * fRec41[1] + 0.75f * fRec40[1];
			fVec16[IOTA0 & 8191] = fTemp2 + fRec41[0] * fTemp0;
			fRec40[0] = fVec16[(faust_wrap_sub(IOTA0, iConst33)) & 8191];
			fRec43[0] = 0.25f * fRec43[1] + 0.75f * fRec42[1];
			fVec17[IOTA0 & 8191] = fTemp2 + fRec43[0] * fTemp0;
			fRec42[0] = fVec17[(faust_wrap_sub(IOTA0, iConst34)) & 8191];
			fRec45[0] = 0.25f * fRec45[1] + 0.75f * fRec44[1];
			fVec18[IOTA0 & 8191] = fTemp2 + fRec45[0] * fTemp0;
			fRec44[0] = fVec18[(faust_wrap_sub(IOTA0, iConst35)) & 8191];
			fRec47[0] = 0.25f * fRec47[1] + 0.75f * fRec46[1];
			fVec19[IOTA0 & 8191] = fTemp2 + fRec47[0] * fTemp0;
			fRec46[0] = fVec19[(faust_wrap_sub(IOTA0, iConst36)) & 8191];
			fRec49[0] = 0.25f * fRec49[1] + 0.75f * fRec48[1];
			fVec20[IOTA0 & 8191] = fTemp2 + fRec49[0] * fTemp0;
			fRec48[0] = fVec20[(faust_wrap_sub(IOTA0, iConst37)) & 8191];
			float fTemp7 = fRec48[1] + fRec46[1] + fRec44[1] + fRec42[1] + fRec40[1] + fRec38[1] + fRec36[1] + 0.5f * fRec32[1] + fRec34[1];
			fVec21[IOTA0 & 2047] = fTemp7;
			fRec32[0] = fVec21[(faust_wrap_sub(IOTA0, iConst38)) & 2047];
			float fRec33 = -(0.5f * fTemp7);
			float fTemp8 = fRec32[1] + fRec33 + 0.5f * fRec30[1];
			fVec22[IOTA0 & 2047] = fTemp8;
			fRec30[0] = fVec22[(faust_wrap_sub(IOTA0, iConst39)) & 2047];
			float fRec31 = -(0.5f * fTemp8);
			float fTemp9 = fRec30[1] + fRec31 + 0.5f * fRec28[1];
			fVec23[IOTA0 & 2047] = fTemp9;
			fRec28[0] = fVec23[(faust_wrap_sub(IOTA0, iConst40)) & 2047];
			float fRec29 = -(0.5f * fTemp9);
			float fTemp10 = fRec28[1] + fRec29 + 0.5f * fRec26[1];
			fVec24[IOTA0 & 1023] = fTemp10;
			fRec26[0] = fVec24[(faust_wrap_sub(IOTA0, iConst41)) & 1023];
			float fRec27 = -(0.5f * fTemp10);
			fRec52[0] = fTemp1 - fConst53 * (fConst51 * fRec52[1] + fConst50 * fRec52[2]);
			float fTemp11 = std::fabs(fConst54 * (fRec52[0] - fRec52[2]));
			float fTemp12 = ((fTemp11 > fRec51[1]) ? fConst55 : fSlow3);
			fRec51[0] = fTemp11 * (1.0f - fTemp12) + fRec51[1] * fTemp12;
			fRec50[0] = fConst56 * static_cast<float>(fRec51[0] > 0.1f) + fConst42 * fRec50[1];
			fRec53[0] = fSlow4 + fConst2 * fRec53[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp1 * (1.0f - fRec53[0]) + fRec53[0] * fRec50[0] * tanhf(0.07f * (fRec0[1] + fRec26[1] + fRec27 + fRec1)));
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fVec0[1] = fVec0[0];
			fRec11[1] = fRec11[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec8[1] = fRec8[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
			fRec53[1] = fRec53[0];
		}
	}

};

#endif
