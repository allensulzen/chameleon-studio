/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Shimmizita"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgShimmizita -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgShimmizita_H__
#define  __TdgShimmizita_H__

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
#define FAUSTCLASS TdgShimmizita
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

class TdgShimmizitaSIG0 {
	
  private:
	
	int iVec2[2];
	int iRec16[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsTdgShimmizitaSIG0() {
		return 0;
	}
	int getNumOutputsTdgShimmizitaSIG0() {
		return 1;
	}
	
	void instanceInitTdgShimmizitaSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			iVec2[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			iRec16[l8] = 0;
		}
	}
	
	void fillTdgShimmizitaSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec2[0] = 1;
			iRec16[0] = (faust_wrap_add(iVec2[1], iRec16[1])) % 65536;
			table[i1] = std::sin(9.58738e-05f * static_cast<float>(iRec16[0]));
			iVec2[1] = iVec2[0];
			iRec16[1] = iRec16[0];
		}
	}

};

static TdgShimmizitaSIG0* newTdgShimmizitaSIG0() { return (TdgShimmizitaSIG0*)new TdgShimmizitaSIG0(); }
static void deleteTdgShimmizitaSIG0(TdgShimmizitaSIG0* dsp) { delete dsp; }

static float TdgShimmizita_faustpower2_f(float value) {
	return value * value;
}
static float DSY_SDRAM_BSS ftbl0TdgShimmizitaSIG0[65536];

class TdgShimmizita : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec11[2];
	FAUSTFLOAT fHslider1;
	float fRec12[2];
	FAUSTFLOAT fHslider2;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider3;
	float fConst5;
	FAUSTFLOAT fHslider4;
	float fConst6;
	float fRec15[2];
	FAUSTFLOAT fHslider5;
	float fRec14[2];
	int IOTA0;
	float fVec1[131072];
	FAUSTFLOAT fHslider6;
	float fConst7;
	float fRec13[2];
	FAUSTFLOAT fHslider7;
	float fRec17[2];
	FAUSTFLOAT fHslider8;
	float fRec18[2];
	FAUSTFLOAT fHslider9;
	float fRec19[2];
	float fRec10[2];
	FAUSTFLOAT fHslider10;
	float fRec20[2];
	float fVec3[16384];
	float fConst8;
	int iConst9;
	float fVec4[4096];
	int iConst10;
	float fRec8[2];
	float fConst11;
	float fConst12;
	float fRec26[2];
	float fRec25[2];
	float fVec5[131072];
	float fRec24[2];
	float fRec23[2];
	float fVec6[16384];
	float fConst13;
	int iConst14;
	float fVec7[2048];
	int iConst15;
	float fRec21[2];
	float fConst16;
	float fConst17;
	float fRec32[2];
	float fRec31[2];
	float fVec8[131072];
	float fRec30[2];
	float fRec29[2];
	float fVec9[16384];
	float fConst18;
	int iConst19;
	float fVec10[4096];
	int iConst20;
	float fRec27[2];
	float fConst21;
	float fConst22;
	float fRec38[2];
	float fRec37[2];
	float fVec11[131072];
	float fRec36[2];
	float fRec35[2];
	float fVec12[16384];
	float fConst23;
	int iConst24;
	float fVec13[2048];
	int iConst25;
	float fRec33[2];
	float fConst26;
	float fConst27;
	float fRec44[2];
	float fRec43[2];
	float fVec14[131072];
	float fRec42[2];
	float fRec41[2];
	float fVec15[32768];
	float fConst28;
	int iConst29;
	float fVec16[4096];
	int iConst30;
	float fRec39[2];
	float fConst31;
	float fConst32;
	float fRec50[2];
	float fRec49[2];
	float fVec17[131072];
	float fRec48[2];
	float fRec47[2];
	float fVec18[16384];
	float fConst33;
	int iConst34;
	float fVec19[4096];
	int iConst35;
	float fRec45[2];
	float fConst36;
	float fConst37;
	float fRec56[2];
	float fRec55[2];
	float fVec20[131072];
	float fRec54[2];
	float fRec53[2];
	float fVec21[32768];
	float fConst38;
	int iConst39;
	float fVec22[4096];
	int iConst40;
	float fRec51[2];
	float fConst41;
	float fConst42;
	float fRec62[2];
	float fRec61[2];
	float fVec23[131072];
	float fRec60[2];
	float fRec59[2];
	float fVec24[32768];
	float fConst43;
	int iConst44;
	float fVec25[2048];
	int iConst45;
	float fRec57[2];
	float fRec0[3];
	float fRec1[3];
	float fRec2[3];
	float fRec3[3];
	float fRec4[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	FAUSTFLOAT fHslider11;
	float fRec63[2];
	
 public:
	TdgShimmizita() {
	}
	
	TdgShimmizita(const TdgShimmizita&) = default;
	
	virtual ~TdgShimmizita() = default;
	
	TdgShimmizita& operator=(const TdgShimmizita&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgShimmizita -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Zita-rev1 FDN with a pitch shifter inside each of the 8 feedback lines - shimmer reverb whose shift can be envelope/LFO driven");
		m->declare("family", "reverb");
		m->declare("filename", "tdg-shimmizita.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/low_shelf1_l:author", "Julius O. Smith III");
		m->declare("filters.lib/low_shelf1_l:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/low_shelf1_l:license", "LicenseRef-STK-4.3");
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
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "Shimmizita");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/hadamard:author", "Remy Muller, revised by Romain Michon");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust shimmizita.dsp + shimmizita.inc (zita_rev_fdn by JOS)");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		TdgShimmizitaSIG0* sig0 = newTdgShimmizitaSIG0();
		sig0->instanceInitTdgShimmizitaSIG0(sample_rate);
		sig0->fillTdgShimmizitaSIG0(65536, ftbl0TdgShimmizitaSIG0);
		deleteTdgShimmizitaSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = std::floor(0.174713f * fConst0 + 0.5f);
		fConst4 = 6.9077554f * (fConst3 / fConst0);
		fConst5 = 6.2831855f / fConst0;
		fConst6 = 3.1415927f / fConst0;
		fConst7 = 1.0f / fConst0;
		fConst8 = std::floor(0.022904f * fConst0 + 0.5f);
		iConst9 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fConst3 - fConst8)));
		iConst10 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst8 + -1.0f)));
		fConst11 = std::floor(0.153129f * fConst0 + 0.5f);
		fConst12 = 6.9077554f * (fConst11 / fConst0);
		fConst13 = std::floor(0.020346f * fConst0 + 0.5f);
		iConst14 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fConst11 - fConst13)));
		iConst15 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, fConst13 + -1.0f)));
		fConst16 = std::floor(0.127837f * fConst0 + 0.5f);
		fConst17 = 6.9077554f * (fConst16 / fConst0);
		fConst18 = std::floor(0.031604f * fConst0 + 0.5f);
		iConst19 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fConst16 - fConst18)));
		iConst20 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst18 + -1.0f)));
		fConst21 = std::floor(0.125f * fConst0 + 0.5f);
		fConst22 = 6.9077554f * (fConst21 / fConst0);
		fConst23 = std::floor(0.013458f * fConst0 + 0.5f);
		iConst24 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fConst21 - fConst23)));
		iConst25 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, fConst23 + -1.0f)));
		fConst26 = std::floor(0.210389f * fConst0 + 0.5f);
		fConst27 = 6.9077554f * (fConst26 / fConst0);
		fConst28 = std::floor(0.024421f * fConst0 + 0.5f);
		iConst29 = static_cast<int>(std::min<float>(16384.0f, std::max<float>(0.0f, fConst26 - fConst28)));
		iConst30 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst28 + -1.0f)));
		fConst31 = std::floor(0.192303f * fConst0 + 0.5f);
		fConst32 = 6.9077554f * (fConst31 / fConst0);
		fConst33 = std::floor(0.029291f * fConst0 + 0.5f);
		iConst34 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fConst31 - fConst33)));
		iConst35 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst33 + -1.0f)));
		fConst36 = std::floor(0.256891f * fConst0 + 0.5f);
		fConst37 = 6.9077554f * (fConst36 / fConst0);
		fConst38 = std::floor(0.027333f * fConst0 + 0.5f);
		iConst39 = static_cast<int>(std::min<float>(16384.0f, std::max<float>(0.0f, fConst36 - fConst38)));
		iConst40 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst38 + -1.0f)));
		fConst41 = std::floor(0.219991f * fConst0 + 0.5f);
		fConst42 = 6.9077554f * (fConst41 / fConst0);
		fConst43 = std::floor(0.019123f * fConst0 + 0.5f);
		iConst44 = static_cast<int>(std::min<float>(16384.0f, std::max<float>(0.0f, fConst41 - fConst43)));
		iConst45 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, fConst43 + -1.0f)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(2.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(6e+03f);
		fHslider4 = static_cast<FAUSTFLOAT>(2e+02f);
		fHslider5 = static_cast<FAUSTFLOAT>(3.0f);
		fHslider6 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider7 = static_cast<FAUSTFLOAT>(0.1f);
		fHslider8 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider9 = static_cast<FAUSTFLOAT>(12.0f);
		fHslider10 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider11 = static_cast<FAUSTFLOAT>(0.4f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec11[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec12[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec15[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec14[l4] = 0.0f;
		}
		IOTA0 = 0;
		for (int l5 = 0; l5 < 131072; l5 = faust_wrap_add(l5, 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec13[l6] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec17[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec18[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec19[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec10[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec20[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 16384; l14 = faust_wrap_add(l14, 1)) {
			fVec3[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 4096; l15 = faust_wrap_add(l15, 1)) {
			fVec4[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec8[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec26[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec25[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 131072; l19 = faust_wrap_add(l19, 1)) {
			fVec5[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec24[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec23[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 16384; l22 = faust_wrap_add(l22, 1)) {
			fVec6[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2048; l23 = faust_wrap_add(l23, 1)) {
			fVec7[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec21[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec32[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec31[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 131072; l27 = faust_wrap_add(l27, 1)) {
			fVec8[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec30[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec29[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 16384; l30 = faust_wrap_add(l30, 1)) {
			fVec9[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 4096; l31 = faust_wrap_add(l31, 1)) {
			fVec10[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec27[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec38[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec37[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 131072; l35 = faust_wrap_add(l35, 1)) {
			fVec11[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec36[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec35[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 16384; l38 = faust_wrap_add(l38, 1)) {
			fVec12[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2048; l39 = faust_wrap_add(l39, 1)) {
			fVec13[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec33[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec44[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			fRec43[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 131072; l43 = faust_wrap_add(l43, 1)) {
			fVec14[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec42[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec41[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 32768; l46 = faust_wrap_add(l46, 1)) {
			fVec15[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 4096; l47 = faust_wrap_add(l47, 1)) {
			fVec16[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec39[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec50[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec49[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 131072; l51 = faust_wrap_add(l51, 1)) {
			fVec17[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec48[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fRec47[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 16384; l54 = faust_wrap_add(l54, 1)) {
			fVec18[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 4096; l55 = faust_wrap_add(l55, 1)) {
			fVec19[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fRec45[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = faust_wrap_add(l57, 1)) {
			fRec56[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = faust_wrap_add(l58, 1)) {
			fRec55[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 131072; l59 = faust_wrap_add(l59, 1)) {
			fVec20[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = faust_wrap_add(l60, 1)) {
			fRec54[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = faust_wrap_add(l61, 1)) {
			fRec53[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 32768; l62 = faust_wrap_add(l62, 1)) {
			fVec21[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 4096; l63 = faust_wrap_add(l63, 1)) {
			fVec22[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 2; l64 = faust_wrap_add(l64, 1)) {
			fRec51[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 2; l65 = faust_wrap_add(l65, 1)) {
			fRec62[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = faust_wrap_add(l66, 1)) {
			fRec61[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 131072; l67 = faust_wrap_add(l67, 1)) {
			fVec23[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 2; l68 = faust_wrap_add(l68, 1)) {
			fRec60[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 2; l69 = faust_wrap_add(l69, 1)) {
			fRec59[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 32768; l70 = faust_wrap_add(l70, 1)) {
			fVec24[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2048; l71 = faust_wrap_add(l71, 1)) {
			fVec25[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = faust_wrap_add(l72, 1)) {
			fRec57[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 3; l73 = faust_wrap_add(l73, 1)) {
			fRec0[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 3; l74 = faust_wrap_add(l74, 1)) {
			fRec1[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 3; l75 = faust_wrap_add(l75, 1)) {
			fRec2[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 3; l76 = faust_wrap_add(l76, 1)) {
			fRec3[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 3; l77 = faust_wrap_add(l77, 1)) {
			fRec4[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 3; l78 = faust_wrap_add(l78, 1)) {
			fRec5[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 3; l79 = faust_wrap_add(l79, 1)) {
			fRec6[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 3; l80 = faust_wrap_add(l80, 1)) {
			fRec7[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 2; l81 = faust_wrap_add(l81, 1)) {
			fRec63[l81] = 0.0f;
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
	
	virtual TdgShimmizita* clone() {
		return new TdgShimmizita(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Shimmizita");
		ui_interface->declare(&fHslider4, "0", "");
		ui_interface->declare(&fHslider4, "unit", "Hz");
		ui_interface->addHorizontalSlider("LF Crossover", &fHslider4, FAUSTFLOAT(2e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider10, "10", "");
		ui_interface->addHorizontalSlider("Shift Amount", &fHslider10, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider11, "11", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider11, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider5, "1", "");
		ui_interface->declare(&fHslider5, "unit", "s");
		ui_interface->addHorizontalSlider("Low RT60", &fHslider5, FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "unit", "s");
		ui_interface->addHorizontalSlider("Mid RT60", &fHslider2, FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("HF Damping", &fHslider3, FAUSTFLOAT(6e+03f), FAUSTFLOAT(1.5e+03f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider9, "4", "");
		ui_interface->declare(&fHslider9, "unit", "semi");
		ui_interface->addHorizontalSlider("Shift", &fHslider9, FAUSTFLOAT(12.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider0, "5", "");
		ui_interface->addHorizontalSlider("Mode", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-3.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider6, "6", "");
		ui_interface->declare(&fHslider6, "unit", "s");
		ui_interface->addHorizontalSlider("Envelope", &fHslider6, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider1, "7", "");
		ui_interface->addHorizontalSlider("Env/LFO", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider7, "8", "");
		ui_interface->declare(&fHslider7, "unit", "Hz");
		ui_interface->addHorizontalSlider("LFO Speed", &fHslider7, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.1f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider8, "9", "");
		ui_interface->addHorizontalSlider("Mod Depth", &fHslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = static_cast<float>(fHslider2);
		float fSlow3 = std::exp(-(fConst4 / fSlow2));
		float fSlow4 = TdgShimmizita_faustpower2_f(fSlow3);
		float fSlow5 = 1.0f - fSlow4;
		float fSlow6 = std::cos(fConst5 * static_cast<float>(fHslider3));
		float fSlow7 = 1.0f - fSlow6 * fSlow4;
		float fSlow8 = std::sqrt(std::max<float>(0.0f, TdgShimmizita_faustpower2_f(fSlow7) / TdgShimmizita_faustpower2_f(fSlow5) + -1.0f));
		float fSlow9 = fSlow7 / fSlow5;
		float fSlow10 = fSlow9 - fSlow8;
		float fSlow11 = 1.0f / std::tan(fConst6 * static_cast<float>(fHslider4));
		float fSlow12 = 1.0f - fSlow11;
		float fSlow13 = 1.0f / (fSlow11 + 1.0f);
		float fSlow14 = static_cast<float>(fHslider5);
		float fSlow15 = std::exp(-(fConst4 / fSlow14)) / fSlow3 + -1.0f;
		float fSlow16 = fSlow3 * (fSlow8 + (1.0f - fSlow9));
		float fSlow17 = static_cast<float>(fHslider6);
		int iSlow18 = std::fabs(fSlow17) < 1.1920929e-07f;
		float fSlow19 = ((iSlow18) ? 0.0f : std::exp(-(fConst7 / ((iSlow18) ? 1.0f : fSlow17))));
		float fSlow20 = 1.0f - fSlow19;
		float fSlow21 = fConst7 * static_cast<float>(fHslider7);
		float fSlow22 = fConst1 * static_cast<float>(fHslider8);
		float fSlow23 = fConst1 * static_cast<float>(fHslider9);
		float fSlow24 = fConst1 * static_cast<float>(fHslider10);
		float fSlow25 = std::exp(-(fConst12 / fSlow2));
		float fSlow26 = TdgShimmizita_faustpower2_f(fSlow25);
		float fSlow27 = 1.0f - fSlow26;
		float fSlow28 = 1.0f - fSlow26 * fSlow6;
		float fSlow29 = std::sqrt(std::max<float>(0.0f, TdgShimmizita_faustpower2_f(fSlow28) / TdgShimmizita_faustpower2_f(fSlow27) + -1.0f));
		float fSlow30 = fSlow28 / fSlow27;
		float fSlow31 = fSlow30 - fSlow29;
		float fSlow32 = std::exp(-(fConst12 / fSlow14)) / fSlow25 + -1.0f;
		float fSlow33 = fSlow25 * (fSlow29 + (1.0f - fSlow30));
		float fSlow34 = std::exp(-(fConst17 / fSlow2));
		float fSlow35 = TdgShimmizita_faustpower2_f(fSlow34);
		float fSlow36 = 1.0f - fSlow35;
		float fSlow37 = 1.0f - fSlow6 * fSlow35;
		float fSlow38 = std::sqrt(std::max<float>(0.0f, TdgShimmizita_faustpower2_f(fSlow37) / TdgShimmizita_faustpower2_f(fSlow36) + -1.0f));
		float fSlow39 = fSlow37 / fSlow36;
		float fSlow40 = fSlow39 - fSlow38;
		float fSlow41 = std::exp(-(fConst17 / fSlow14)) / fSlow34 + -1.0f;
		float fSlow42 = fSlow34 * (fSlow38 + (1.0f - fSlow39));
		float fSlow43 = std::exp(-(fConst22 / fSlow2));
		float fSlow44 = TdgShimmizita_faustpower2_f(fSlow43);
		float fSlow45 = 1.0f - fSlow44;
		float fSlow46 = 1.0f - fSlow6 * fSlow44;
		float fSlow47 = std::sqrt(std::max<float>(0.0f, TdgShimmizita_faustpower2_f(fSlow46) / TdgShimmizita_faustpower2_f(fSlow45) + -1.0f));
		float fSlow48 = fSlow46 / fSlow45;
		float fSlow49 = fSlow48 - fSlow47;
		float fSlow50 = std::exp(-(fConst22 / fSlow14)) / fSlow43 + -1.0f;
		float fSlow51 = fSlow43 * (fSlow47 + (1.0f - fSlow48));
		float fSlow52 = std::exp(-(fConst27 / fSlow2));
		float fSlow53 = TdgShimmizita_faustpower2_f(fSlow52);
		float fSlow54 = 1.0f - fSlow53;
		float fSlow55 = 1.0f - fSlow6 * fSlow53;
		float fSlow56 = std::sqrt(std::max<float>(0.0f, TdgShimmizita_faustpower2_f(fSlow55) / TdgShimmizita_faustpower2_f(fSlow54) + -1.0f));
		float fSlow57 = fSlow55 / fSlow54;
		float fSlow58 = fSlow57 - fSlow56;
		float fSlow59 = std::exp(-(fConst27 / fSlow14)) / fSlow52 + -1.0f;
		float fSlow60 = fSlow52 * (fSlow56 + (1.0f - fSlow57));
		float fSlow61 = std::exp(-(fConst32 / fSlow2));
		float fSlow62 = TdgShimmizita_faustpower2_f(fSlow61);
		float fSlow63 = 1.0f - fSlow62;
		float fSlow64 = 1.0f - fSlow6 * fSlow62;
		float fSlow65 = std::sqrt(std::max<float>(0.0f, TdgShimmizita_faustpower2_f(fSlow64) / TdgShimmizita_faustpower2_f(fSlow63) + -1.0f));
		float fSlow66 = fSlow64 / fSlow63;
		float fSlow67 = fSlow66 - fSlow65;
		float fSlow68 = std::exp(-(fConst32 / fSlow14)) / fSlow61 + -1.0f;
		float fSlow69 = fSlow61 * (fSlow65 + (1.0f - fSlow66));
		float fSlow70 = std::exp(-(fConst37 / fSlow2));
		float fSlow71 = TdgShimmizita_faustpower2_f(fSlow70);
		float fSlow72 = 1.0f - fSlow71;
		float fSlow73 = 1.0f - fSlow6 * fSlow71;
		float fSlow74 = std::sqrt(std::max<float>(0.0f, TdgShimmizita_faustpower2_f(fSlow73) / TdgShimmizita_faustpower2_f(fSlow72) + -1.0f));
		float fSlow75 = fSlow73 / fSlow72;
		float fSlow76 = fSlow75 - fSlow74;
		float fSlow77 = std::exp(-(fConst37 / fSlow14)) / fSlow70 + -1.0f;
		float fSlow78 = fSlow70 * (fSlow74 + (1.0f - fSlow75));
		float fSlow79 = std::exp(-(fConst42 / fSlow2));
		float fSlow80 = TdgShimmizita_faustpower2_f(fSlow79);
		float fSlow81 = 1.0f - fSlow80;
		float fSlow82 = 1.0f - fSlow6 * fSlow80;
		float fSlow83 = std::sqrt(std::max<float>(0.0f, TdgShimmizita_faustpower2_f(fSlow82) / TdgShimmizita_faustpower2_f(fSlow81) + -1.0f));
		float fSlow84 = fSlow82 / fSlow81;
		float fSlow85 = fSlow84 - fSlow83;
		float fSlow86 = std::exp(-(fConst42 / fSlow14)) / fSlow79 + -1.0f;
		float fSlow87 = fSlow79 * (fSlow83 + (1.0f - fSlow84));
		float fSlow88 = fConst1 * static_cast<float>(fHslider11);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec11[0] = fSlow0 + fConst2 * fRec11[1];
			float fTemp0 = static_cast<float>(fRec11[0] < 0.0f);
			float fTemp1 = 0.5f * fRec11[0];
			float fTemp2 = fTemp1 + 1.0f;
			float fTemp3 = static_cast<float>(fRec11[0] >= 0.0f);
			float fTemp4 = fTemp3 * fTemp2;
			fRec12[0] = fSlow1 + fConst2 * fRec12[1];
			float fTemp5 = 1.0f - fRec12[0];
			fRec15[0] = -(fSlow13 * (fSlow12 * fRec15[1] - (fRec4[1] + fRec4[2])));
			fRec14[0] = fSlow16 * (fRec4[1] + fSlow15 * fRec15[0]) + fSlow10 * fRec14[1];
			float fTemp6 = 0.35355338f * fRec14[0] + 1e-20f;
			fVec1[IOTA0 & 131071] = fTemp6;
			float fTemp7 = std::fabs(fTemp6);
			fRec13[0] = std::max<float>(fTemp7, fSlow19 * fRec13[1] + fSlow20 * fTemp7);
			float fTemp8 = ((faust_wrap_sub(1, iVec0[1])) ? 0.0f : fSlow21 + fRec17[1]);
			fRec17[0] = fTemp8 - std::floor(fTemp8);
			float fTemp9 = 0.5f * fRec12[0] * ftbl0TdgShimmizitaSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec17[0]), 65535))];
			fRec18[0] = fSlow22 + fConst2 * fRec18[1];
			fRec19[0] = fSlow23 + fConst2 * fRec19[1];
			fRec10[0] = std::fmod(fRec10[1] + (2049.0f - std::pow(2.0f, 0.083333336f * fRec19[0] * (fRec18[0] * (fTemp9 + 6.0f * fRec13[0] * fTemp5) + 0.5f) * (fTemp4 + fTemp0 * (0.16666667f * fRec11[0] + 1.0f)))), 2048.0f);
			float fTemp10 = std::min<float>(0.0009765625f * fRec10[0], 1.0f);
			float fTemp11 = fRec10[0] + 2048.0f;
			int iTemp12 = static_cast<int>(fTemp11);
			float fTemp13 = std::floor(fTemp11);
			int iTemp14 = static_cast<int>(fRec10[0]);
			float fTemp15 = std::floor(fRec10[0]);
			fRec20[0] = fSlow24 + fConst2 * fRec20[1];
			float fTemp16 = 1.0f - fRec20[0];
			fVec3[IOTA0 & 16383] = fTemp16 * fTemp6 + fRec20[0] * ((fVec1[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp14)))) & 131071] * (fTemp15 + (1.0f - fRec10[0])) + (fRec10[0] - fTemp15) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp14, 1))))) & 131071]) * fTemp10 + (fVec1[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp12)))) & 131071] * (fTemp13 + (-2047.0f - fRec10[0])) + (fRec10[0] + (2048.0f - fTemp13)) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp12, 1))))) & 131071]) * (1.0f - fTemp10));
			float fTemp17 = static_cast<float>(input0[i0]);
			float fTemp18 = fTemp17 + fVec3[(faust_wrap_sub(IOTA0, iConst9)) & 16383] - 0.6f * fRec8[1];
			fVec4[IOTA0 & 4095] = fTemp18;
			fRec8[0] = fVec4[(faust_wrap_sub(IOTA0, iConst10)) & 4095];
			float fRec9 = 0.6f * fTemp18;
			fRec26[0] = -(fSlow13 * (fSlow12 * fRec26[1] - (fRec0[1] + fRec0[2])));
			fRec25[0] = fSlow33 * (fRec0[1] + fSlow32 * fRec26[0]) + fSlow31 * fRec25[1];
			float fTemp19 = 0.35355338f * fRec25[0] + 1e-20f;
			fVec5[IOTA0 & 131071] = fTemp19;
			float fTemp20 = std::fabs(fTemp19);
			fRec24[0] = std::max<float>(fTemp20, fRec24[1] * fSlow19 + fTemp20 * fSlow20);
			fRec23[0] = std::fmod(fRec23[1] + (2049.0f - std::pow(2.0f, 0.083333336f * fRec19[0] * (fRec18[0] * (6.0f * fRec24[0] * fTemp5 + fTemp9) + 0.5f) * (fTemp4 + fTemp0 * (0.2f * fRec11[0] + 1.0f)))), 2048.0f);
			float fTemp21 = std::min<float>(0.0009765625f * fRec23[0], 1.0f);
			float fTemp22 = fRec23[0] + 2048.0f;
			int iTemp23 = static_cast<int>(fTemp22);
			float fTemp24 = std::floor(fTemp22);
			int iTemp25 = static_cast<int>(fRec23[0]);
			float fTemp26 = std::floor(fRec23[0]);
			fVec6[IOTA0 & 16383] = fTemp16 * fTemp19 + fRec20[0] * ((fVec5[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp25)))) & 131071] * (fTemp26 + (1.0f - fRec23[0])) + (fRec23[0] - fTemp26) * fVec5[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp25, 1))))) & 131071]) * fTemp21 + (fVec5[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp23)))) & 131071] * (fTemp24 + (-2047.0f - fRec23[0])) + (fRec23[0] + (2048.0f - fTemp24)) * fVec5[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp23, 1))))) & 131071]) * (1.0f - fTemp21));
			float fTemp27 = fTemp17 + fVec6[(faust_wrap_sub(IOTA0, iConst14)) & 16383] - 0.6f * fRec21[1];
			fVec7[IOTA0 & 2047] = fTemp27;
			fRec21[0] = fVec7[(faust_wrap_sub(IOTA0, iConst15)) & 2047];
			float fRec22 = 0.6f * fTemp27;
			float fTemp28 = fRec22 + fRec9;
			float fTemp29 = 0.33333334f * fRec11[0];
			float fTemp30 = fTemp29 + 1.0f;
			float fTemp31 = fTemp4 + fTemp0 * fTemp30;
			fRec32[0] = -(fSlow13 * (fSlow12 * fRec32[1] - (fRec2[1] + fRec2[2])));
			fRec31[0] = fSlow42 * (fRec2[1] + fSlow41 * fRec32[0]) + fSlow40 * fRec31[1];
			float fTemp32 = 0.35355338f * fRec31[0] + 1e-20f;
			fVec8[IOTA0 & 131071] = fTemp32;
			float fTemp33 = std::fabs(fTemp32);
			fRec30[0] = std::max<float>(fTemp33, fSlow19 * fRec30[1] + fSlow20 * fTemp33);
			fRec29[0] = std::fmod(fRec29[1] + (2049.0f - std::pow(2.0f, 0.083333336f * fRec19[0] * (fRec18[0] * (fTemp9 + 6.0f * fRec30[0] * fTemp5) + 0.5f) * fTemp31)), 2048.0f);
			float fTemp34 = std::min<float>(0.0009765625f * fRec29[0], 1.0f);
			float fTemp35 = fRec29[0] + 2048.0f;
			int iTemp36 = static_cast<int>(fTemp35);
			float fTemp37 = std::floor(fTemp35);
			int iTemp38 = static_cast<int>(fRec29[0]);
			float fTemp39 = std::floor(fRec29[0]);
			fVec9[IOTA0 & 16383] = fTemp16 * fTemp32 + fRec20[0] * ((fVec8[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp38)))) & 131071] * (fTemp39 + (1.0f - fRec29[0])) + (fRec29[0] - fTemp39) * fVec8[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp38, 1))))) & 131071]) * fTemp34 + (fVec8[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp36)))) & 131071] * (fTemp37 + (-2047.0f - fRec29[0])) + (fRec29[0] + (2048.0f - fTemp37)) * fVec8[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp36, 1))))) & 131071]) * (1.0f - fTemp34));
			float fTemp40 = fTemp17 + fVec9[(faust_wrap_sub(IOTA0, iConst19)) & 16383] - 0.6f * fRec27[1];
			fVec10[IOTA0 & 4095] = fTemp40;
			fRec27[0] = fVec10[(faust_wrap_sub(IOTA0, iConst20)) & 4095];
			float fRec28 = 0.6f * fTemp40;
			fRec38[0] = -(fSlow13 * (fSlow12 * fRec38[1] - (fRec6[1] + fRec6[2])));
			fRec37[0] = fSlow51 * (fRec6[1] + fSlow50 * fRec38[0]) + fSlow49 * fRec37[1];
			float fTemp41 = 0.35355338f * fRec37[0] + 1e-20f;
			fVec11[IOTA0 & 131071] = fTemp41;
			float fTemp42 = std::fabs(fTemp41);
			fRec36[0] = std::max<float>(fTemp42, fSlow19 * fRec36[1] + fSlow20 * fTemp42);
			fRec35[0] = std::fmod(fRec35[1] + (2049.0f - std::pow(2.0f, 0.083333336f * fRec19[0] * fTemp31 * (fRec18[0] * (fTemp9 + 6.0f * fRec36[0] * fTemp5) + 0.5f))), 2048.0f);
			float fTemp43 = std::min<float>(0.0009765625f * fRec35[0], 1.0f);
			float fTemp44 = fRec35[0] + 2048.0f;
			int iTemp45 = static_cast<int>(fTemp44);
			float fTemp46 = std::floor(fTemp44);
			int iTemp47 = static_cast<int>(fRec35[0]);
			float fTemp48 = std::floor(fRec35[0]);
			fVec12[IOTA0 & 16383] = fTemp16 * fTemp41 + fRec20[0] * ((fVec11[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp47)))) & 131071] * (fTemp48 + (1.0f - fRec35[0])) + (fRec35[0] - fTemp48) * fVec11[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp47, 1))))) & 131071]) * fTemp43 + (fVec11[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp45)))) & 131071] * (fTemp46 + (-2047.0f - fRec35[0])) + (fRec35[0] + (2048.0f - fTemp46)) * fVec11[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp45, 1))))) & 131071]) * (1.0f - fTemp43));
			float fTemp49 = fTemp17 + fVec12[(faust_wrap_sub(IOTA0, iConst24)) & 16383] - 0.6f * fRec33[1];
			fVec13[IOTA0 & 2047] = fTemp49;
			fRec33[0] = fVec13[(faust_wrap_sub(IOTA0, iConst25)) & 2047];
			float fRec34 = 0.6f * fTemp49;
			float fTemp50 = fRec34 + fRec28 + fTemp28;
			float fTemp51 = fTemp0 * (1.0f - fTemp1);
			float fTemp52 = fTemp3 * fTemp30;
			fRec44[0] = -(fSlow13 * (fSlow12 * fRec44[1] - (fRec1[1] + fRec1[2])));
			fRec43[0] = fSlow60 * (fRec1[1] + fSlow59 * fRec44[0]) + fSlow58 * fRec43[1];
			float fTemp53 = 0.35355338f * fRec43[0] + 1e-20f;
			fVec14[IOTA0 & 131071] = fTemp53;
			float fTemp54 = std::fabs(fTemp53);
			fRec42[0] = std::max<float>(fTemp54, fSlow19 * fRec42[1] + fSlow20 * fTemp54);
			fRec41[0] = std::fmod(fRec41[1] + (2049.0f - std::pow(2.0f, 0.083333336f * fRec19[0] * (fRec18[0] * (fTemp9 + 6.0f * fRec42[0] * fTemp5) + 0.5f) * (fTemp52 + fTemp51))), 2048.0f);
			float fTemp55 = std::min<float>(0.0009765625f * fRec41[0], 1.0f);
			float fTemp56 = fRec41[0] + 2048.0f;
			int iTemp57 = static_cast<int>(fTemp56);
			float fTemp58 = std::floor(fTemp56);
			int iTemp59 = static_cast<int>(fRec41[0]);
			float fTemp60 = std::floor(fRec41[0]);
			fVec15[IOTA0 & 32767] = fTemp16 * fTemp53 + fRec20[0] * ((fVec14[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp59)))) & 131071] * (fTemp60 + (1.0f - fRec41[0])) + (fRec41[0] - fTemp60) * fVec14[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp59, 1))))) & 131071]) * fTemp55 + (fVec14[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp57)))) & 131071] * (fTemp58 + (-2047.0f - fRec41[0])) + (fRec41[0] + (2048.0f - fTemp58)) * fVec14[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp57, 1))))) & 131071]) * (1.0f - fTemp55));
			float fTemp61 = fVec15[(faust_wrap_sub(IOTA0, iConst29)) & 32767] + fTemp17 + 0.6f * fRec39[1];
			fVec16[IOTA0 & 4095] = fTemp61;
			fRec39[0] = fVec16[(faust_wrap_sub(IOTA0, iConst30)) & 4095];
			float fRec40 = -(0.6f * fTemp61);
			fRec50[0] = -(fSlow13 * (fSlow12 * fRec50[1] - (fRec5[1] + fRec5[2])));
			fRec49[0] = fSlow69 * (fRec5[1] + fSlow68 * fRec50[0]) + fSlow67 * fRec49[1];
			float fTemp62 = 0.35355338f * fRec49[0] + 1e-20f;
			fVec17[IOTA0 & 131071] = fTemp62;
			float fTemp63 = std::fabs(fTemp62);
			fRec48[0] = std::max<float>(fTemp63, fSlow19 * fRec48[1] + fSlow20 * fTemp63);
			fRec47[0] = std::fmod(fRec47[1] + (2049.0f - std::pow(2.0f, 0.083333336f * fRec19[0] * (fRec18[0] * (fTemp9 + 6.0f * fRec48[0] * fTemp5) + 0.5f) * (fTemp3 * (0.125f * fRec11[0] + 1.0f) + fTemp0 * (1.0f - fTemp29)))), 2048.0f);
			float fTemp64 = std::min<float>(0.0009765625f * fRec47[0], 1.0f);
			float fTemp65 = fRec47[0] + 2048.0f;
			int iTemp66 = static_cast<int>(fTemp65);
			float fTemp67 = std::floor(fTemp65);
			int iTemp68 = static_cast<int>(fRec47[0]);
			float fTemp69 = std::floor(fRec47[0]);
			fVec18[IOTA0 & 16383] = fTemp16 * fTemp62 + fRec20[0] * ((fVec17[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp68)))) & 131071] * (fTemp69 + (1.0f - fRec47[0])) + (fRec47[0] - fTemp69) * fVec17[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp68, 1))))) & 131071]) * fTemp64 + (fVec17[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp66)))) & 131071] * (fTemp67 + (-2047.0f - fRec47[0])) + (fRec47[0] + (2048.0f - fTemp67)) * fVec17[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp66, 1))))) & 131071]) * (1.0f - fTemp64));
			float fTemp70 = fVec18[(faust_wrap_sub(IOTA0, iConst34)) & 16383] + fTemp17 + 0.6f * fRec45[1];
			fVec19[IOTA0 & 4095] = fTemp70;
			fRec45[0] = fVec19[(faust_wrap_sub(IOTA0, iConst35)) & 4095];
			float fRec46 = -(0.6f * fTemp70);
			fRec56[0] = -(fSlow13 * (fSlow12 * fRec56[1] - (fRec3[1] + fRec3[2])));
			fRec55[0] = fSlow78 * (fRec3[1] + fSlow77 * fRec56[0]) + fSlow76 * fRec55[1];
			float fTemp71 = 0.35355338f * fRec55[0] + 1e-20f;
			fVec20[IOTA0 & 131071] = fTemp71;
			float fTemp72 = std::fabs(fTemp71);
			fRec54[0] = std::max<float>(fTemp72, fSlow19 * fRec54[1] + fSlow20 * fTemp72);
			fRec53[0] = std::fmod(fRec53[1] + (2049.0f - std::pow(2.0f, 0.083333336f * fRec19[0] * (fRec18[0] * (fTemp9 + 6.0f * fRec54[0] * fTemp5) + 0.5f) * (fTemp51 + fTemp3 * (0.25f * fRec11[0] + 1.0f)))), 2048.0f);
			float fTemp73 = std::min<float>(0.0009765625f * fRec53[0], 1.0f);
			float fTemp74 = fRec53[0] + 2048.0f;
			int iTemp75 = static_cast<int>(fTemp74);
			float fTemp76 = std::floor(fTemp74);
			int iTemp77 = static_cast<int>(fRec53[0]);
			float fTemp78 = std::floor(fRec53[0]);
			fVec21[IOTA0 & 32767] = fTemp16 * fTemp71 + fRec20[0] * ((fVec20[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp77)))) & 131071] * (fTemp78 + (1.0f - fRec53[0])) + (fRec53[0] - fTemp78) * fVec20[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp77, 1))))) & 131071]) * fTemp73 + (fVec20[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp75)))) & 131071] * (fTemp76 + (-2047.0f - fRec53[0])) + (fRec53[0] + (2048.0f - fTemp76)) * fVec20[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp75, 1))))) & 131071]) * (1.0f - fTemp73));
			float fTemp79 = fVec21[(faust_wrap_sub(IOTA0, iConst39)) & 32767] + fTemp17 + 0.6f * fRec51[1];
			fVec22[IOTA0 & 4095] = fTemp79;
			fRec51[0] = fVec22[(faust_wrap_sub(IOTA0, iConst40)) & 4095];
			float fRec52 = -(0.6f * fTemp79);
			fRec62[0] = -(fSlow13 * (fSlow12 * fRec62[1] - (fRec7[1] + fRec7[2])));
			fRec61[0] = fSlow87 * (fRec7[1] + fSlow86 * fRec62[0]) + fSlow85 * fRec61[1];
			float fTemp80 = 0.35355338f * fRec61[0] + 1e-20f;
			fVec23[IOTA0 & 131071] = fTemp80;
			float fTemp81 = std::fabs(fTemp80);
			fRec60[0] = std::max<float>(fTemp81, fSlow19 * fRec60[1] + fSlow20 * fTemp81);
			fRec59[0] = std::fmod(fRec59[1] + (2049.0f - std::pow(2.0f, 0.083333336f * fRec19[0] * (fRec18[0] * (fTemp9 + 6.0f * fRec60[0] * fTemp5) + 0.5f) * (fTemp52 + fTemp0 * fTemp2))), 2048.0f);
			float fTemp82 = std::min<float>(0.0009765625f * fRec59[0], 1.0f);
			float fTemp83 = fRec59[0] + 2048.0f;
			int iTemp84 = static_cast<int>(fTemp83);
			float fTemp85 = std::floor(fTemp83);
			int iTemp86 = static_cast<int>(fRec59[0]);
			float fTemp87 = std::floor(fRec59[0]);
			fVec24[IOTA0 & 32767] = fTemp16 * fTemp80 + fRec20[0] * ((fVec23[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp86)))) & 131071] * (fTemp87 + (1.0f - fRec59[0])) + (fRec59[0] - fTemp87) * fVec23[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp86, 1))))) & 131071]) * fTemp82 + (fVec23[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp84)))) & 131071] * (fTemp85 + (-2047.0f - fRec59[0])) + (fRec59[0] + (2048.0f - fTemp85)) * fVec23[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp84, 1))))) & 131071]) * (1.0f - fTemp82));
			float fTemp88 = fVec24[(faust_wrap_sub(IOTA0, iConst44)) & 32767] + fTemp17 + 0.6f * fRec57[1];
			fVec25[IOTA0 & 2047] = fTemp88;
			fRec57[0] = fVec25[(faust_wrap_sub(IOTA0, iConst45)) & 2047];
			float fRec58 = -(0.6f * fTemp88);
			fRec0[0] = fRec57[1] + fRec51[1] + fRec45[1] + fRec39[1] + fRec33[1] + fRec27[1] + fRec8[1] + fRec21[1] + fRec58 + fRec52 + fRec46 + fRec40 + fTemp50;
			fRec1[0] = fRec33[1] + fRec27[1] + fRec8[1] + fRec21[1] + fTemp50 - (fRec57[1] + fRec51[1] + fRec45[1] + fRec39[1] + fRec58 + fRec52 + fRec40 + fRec46);
			float fTemp89 = fRec28 + fRec34;
			fRec2[0] = fRec45[1] + fRec39[1] + fRec8[1] + fRec21[1] + fRec46 + fRec40 + fTemp28 - (fRec57[1] + fRec51[1] + fRec33[1] + fRec27[1] + fRec58 + fRec52 + fTemp89);
			fRec3[0] = fRec57[1] + fRec51[1] + fRec8[1] + fRec21[1] + fRec58 + fRec52 + fTemp28 - (fRec45[1] + fRec39[1] + fRec33[1] + fRec27[1] + fRec46 + fRec40 + fTemp89);
			float fTemp90 = fRec9 + fRec34;
			float fTemp91 = fRec22 + fRec28;
			fRec4[0] = fRec51[1] + fRec39[1] + fRec27[1] + fRec21[1] + fRec52 + fRec40 + fTemp91 - (fRec57[1] + fRec45[1] + fRec33[1] + fRec8[1] + fRec58 + fRec46 + fTemp90);
			fRec5[0] = fRec57[1] + fRec45[1] + fRec27[1] + fRec21[1] + fRec58 + fRec46 + fTemp91 - (fRec51[1] + fRec39[1] + fRec33[1] + fRec8[1] + fRec52 + fRec40 + fTemp90);
			float fTemp92 = fRec9 + fRec28;
			float fTemp93 = fRec22 + fRec34;
			fRec6[0] = fRec57[1] + fRec39[1] + fRec33[1] + fRec21[1] + fRec58 + fRec40 + fTemp93 - (fRec51[1] + fRec45[1] + fRec27[1] + fRec8[1] + fRec52 + fRec46 + fTemp92);
			fRec7[0] = fRec51[1] + fRec45[1] + fRec33[1] + fRec21[1] + fRec52 + fRec46 + fTemp93 - (fRec57[1] + fRec39[1] + fRec27[1] + fRec8[1] + fRec58 + fRec40 + fTemp92);
			fRec63[0] = fSlow88 + fConst2 * fRec63[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp17 * (1.0f - fRec63[0]) + 0.25f * fRec63[0] * (fRec0[0] + fRec1[0] + fRec2[0] + fRec3[0] + fRec4[0] + fRec5[0] + fRec6[0] + fRec7[0]));
			iVec0[1] = iVec0[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec13[1] = fRec13[0];
			fRec17[1] = fRec17[0];
			fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
			fRec10[1] = fRec10[0];
			fRec20[1] = fRec20[0];
			fRec8[1] = fRec8[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec21[1] = fRec21[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec33[1] = fRec33[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec39[1] = fRec39[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec45[1] = fRec45[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec51[1] = fRec51[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec57[1] = fRec57[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
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
			fRec63[1] = fRec63[0];
		}
	}

};

#endif
