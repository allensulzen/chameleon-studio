/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Room Simulator"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgRoomSimulator -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgRoomSimulator_H__
#define  __TdgRoomSimulator_H__

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
#define FAUSTCLASS TdgRoomSimulator
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

static float TdgRoomSimulator_faustpower2_f(float value) {
	return value * value;
}

class TdgRoomSimulator : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	int IOTA0;
	float fVec0[32768];
	FAUSTFLOAT fHslider1;
	float fRec1[2];
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	FAUSTFLOAT fHslider2;
	float fConst10;
	float fRec19[3];
	float fRec18[3];
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	float fConst18;
	float fConst19;
	float fConst20;
	float fConst21;
	float fConst22;
	float fConst23;
	FAUSTFLOAT fHslider3;
	float fRec23[2];
	float fRec21[3];
	float fConst24;
	float fRec20[3];
	float fConst25;
	float fVec1[2048];
	int iConst26;
	float fRec16[2];
	float fVec2[4096];
	int iConst27;
	float fRec14[2];
	float fVec3[4096];
	int iConst28;
	int iConst29;
	float fVec4[16384];
	int iConst30;
	float fVec5[16384];
	int iConst31;
	float fRec12[2];
	float fRec10[2];
	float fVec6[8192];
	int iConst32;
	int iConst33;
	float fVec7[16384];
	int iConst34;
	float fVec8[16384];
	int iConst35;
	float fVec9[8192];
	int iConst36;
	float fRec8[2];
	float fRec6[2];
	float fRec4[2];
	float fRec2[2];
	float fConst37;
	float fConst38;
	float fConst39;
	float fConst40;
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec39[3];
	float fRec38[3];
	float fRec42[3];
	float fRec41[3];
	float fVec10[8192];
	int iConst44;
	float fVec11[2048];
	int iConst45;
	float fVec12[8192];
	int iConst46;
	float fRec36[2];
	float fRec34[2];
	float fRec32[2];
	float fVec13[1024];
	int iConst47;
	float fVec14[8192];
	float fRec30[2];
	float fVec15[16384];
	int iConst48;
	int iConst49;
	float fVec16[8192];
	int iConst50;
	float fVec17[2048];
	int iConst51;
	float fRec28[2];
	float fRec26[2];
	float fRec24[2];
	float fConst52;
	float fConst53;
	float fConst54;
	float fConst55;
	float fConst56;
	float fConst57;
	float fConst58;
	float fConst59;
	float fConst60;
	float fConst61;
	float fConst62;
	float fConst63;
	float fRec57[3];
	float fConst64;
	float fRec56[3];
	float fVec18[8192];
	int iConst65;
	float fVec19[8192];
	float fVec20[8192];
	float fVec21[2048];
	float fRec53[2];
	float fRec51[2];
	float fRec49[2];
	float fVec22[16384];
	int iConst66;
	float fVec23[8192];
	float fRec47[2];
	float fRec45[2];
	float fRec43[2];
	
 public:
	TdgRoomSimulator() {
	}
	
	TdgRoomSimulator(const TdgRoomSimulator&) = default;
	
	virtual ~TdgRoomSimulator() = default;
	
	TdgRoomSimulator& operator=(const TdgRoomSimulator&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgRoomSimulator -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Gardner nested-allpass room reverbs (small/medium/large) with continuous morph between room sizes and pre-delay");
		m->declare("family", "reverb");
		m->declare("filename", "tdg-room-simulator.dsp");
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
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Room Simulator");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust room_simulator.dsp");
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
		fConst3 = std::tan(12566.371f / fConst0);
		fConst4 = 2.0f * (1.0f - 1.0f / TdgRoomSimulator_faustpower2_f(fConst3));
		fConst5 = 1.0f / fConst3;
		fConst6 = (fConst5 + -0.76536685f) / fConst3 + 1.0f;
		fConst7 = 1.0f / ((fConst5 + 0.76536685f) / fConst3 + 1.0f);
		fConst8 = (fConst5 + -1.847759f) / fConst3 + 1.0f;
		fConst9 = 1.0f / ((fConst5 + 1.847759f) / fConst3 + 1.0f);
		fConst10 = 0.001f * fConst0;
		fConst11 = std::tan(3141.5928f / fConst0);
		fConst12 = 2.0f * (1.0f - 1.0f / TdgRoomSimulator_faustpower2_f(fConst11));
		fConst13 = 1.0f / fConst11;
		fConst14 = (fConst13 + -1.4142135f) / fConst11 + 1.0f;
		fConst15 = (fConst13 + 1.4142135f) / fConst11 + 1.0f;
		fConst16 = 1.0f / fConst15;
		fConst17 = std::tan(1570.7964f / fConst0);
		fConst18 = TdgRoomSimulator_faustpower2_f(fConst17);
		fConst19 = 2.0f * (1.0f - 1.0f / fConst18);
		fConst20 = 1.0f / fConst17;
		fConst21 = (fConst20 + -1.4142135f) / fConst17 + 1.0f;
		fConst22 = (fConst20 + 1.4142135f) / fConst17 + 1.0f;
		fConst23 = 1.0f / fConst22;
		fConst24 = 1.0f / (fConst18 * fConst22);
		fConst25 = 1.299f / fConst15;
		iConst26 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.008f * fConst0), -1)));
		iConst27 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.012f * fConst0), -1)));
		iConst28 = static_cast<int>(0.004f * fConst0);
		iConst29 = faust_wrap_add(iConst28, static_cast<int>(0.017f * fConst0));
		iConst30 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.087f * fConst0), -1)));
		iConst31 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.062f * fConst0), -1)));
		iConst32 = static_cast<int>(0.031f * fConst0);
		iConst33 = faust_wrap_add(iConst32, static_cast<int>(0.003f * fConst0));
		iConst34 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.12f * fConst0), -1)));
		iConst35 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.076f * fConst0), -1)));
		iConst36 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.03f * fConst0), -1)));
		fConst37 = std::tan(18849.557f / fConst0);
		fConst38 = 2.0f * (1.0f - 1.0f / TdgRoomSimulator_faustpower2_f(fConst37));
		fConst39 = 1.0f / fConst37;
		fConst40 = (fConst39 + -0.76536685f) / fConst37 + 1.0f;
		fConst41 = 1.0f / ((fConst39 + 0.76536685f) / fConst37 + 1.0f);
		fConst42 = (fConst39 + -1.847759f) / fConst37 + 1.0f;
		fConst43 = 1.0f / ((fConst39 + 1.847759f) / fConst37 + 1.0f);
		iConst44 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.035f * fConst0), -1)));
		iConst45 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.0083f * fConst0), -1)));
		iConst46 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.022f * fConst0), -1)));
		iConst47 = static_cast<int>(0.005f * fConst0);
		iConst48 = static_cast<int>(0.067f * fConst0);
		iConst49 = faust_wrap_add(iConst48, static_cast<int>(0.015f * fConst0));
		iConst50 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.039f * fConst0), -1)));
		iConst51 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.0098f * fConst0), -1)));
		fConst52 = std::tan(5026.5483f / fConst0);
		fConst53 = 2.0f * (1.0f - 1.0f / TdgRoomSimulator_faustpower2_f(fConst52));
		fConst54 = 1.0f / fConst52;
		fConst55 = (fConst54 + -1.4142135f) / fConst52 + 1.0f;
		fConst56 = 1.0f / ((fConst54 + 1.4142135f) / fConst52 + 1.0f);
		fConst57 = std::tan(2513.2742f / fConst0);
		fConst58 = TdgRoomSimulator_faustpower2_f(fConst57);
		fConst59 = 2.0f * (1.0f - 1.0f / fConst58);
		fConst60 = 1.0f / fConst57;
		fConst61 = (fConst60 + -1.4142135f) / fConst57 + 1.0f;
		fConst62 = (fConst60 + 1.4142135f) / fConst57 + 1.0f;
		fConst63 = 1.0f / fConst62;
		fConst64 = 1.0f / (fConst58 * fConst62);
		iConst65 = static_cast<int>(0.024f * fConst0);
		iConst66 = std::min<int>(8192, std::max<int>(0, faust_wrap_add(static_cast<int>(0.066f * fConst0), -1)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.4f);
		fHslider1 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(2e+01f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.3f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 32768; l1 = faust_wrap_add(l1, 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fRec19[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec18[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec23[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec21[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec20[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2048; l8 = faust_wrap_add(l8, 1)) {
			fVec1[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec16[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 4096; l10 = faust_wrap_add(l10, 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec14[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 4096; l12 = faust_wrap_add(l12, 1)) {
			fVec3[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 16384; l13 = faust_wrap_add(l13, 1)) {
			fVec4[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 16384; l14 = faust_wrap_add(l14, 1)) {
			fVec5[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec12[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec10[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 8192; l17 = faust_wrap_add(l17, 1)) {
			fVec6[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 16384; l18 = faust_wrap_add(l18, 1)) {
			fVec7[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 16384; l19 = faust_wrap_add(l19, 1)) {
			fVec8[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 8192; l20 = faust_wrap_add(l20, 1)) {
			fVec9[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec8[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec6[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec4[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec2[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 3; l25 = faust_wrap_add(l25, 1)) {
			fRec39[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 3; l26 = faust_wrap_add(l26, 1)) {
			fRec38[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 3; l27 = faust_wrap_add(l27, 1)) {
			fRec42[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 3; l28 = faust_wrap_add(l28, 1)) {
			fRec41[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 8192; l29 = faust_wrap_add(l29, 1)) {
			fVec10[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2048; l30 = faust_wrap_add(l30, 1)) {
			fVec11[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 8192; l31 = faust_wrap_add(l31, 1)) {
			fVec12[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec36[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec34[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec32[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 1024; l35 = faust_wrap_add(l35, 1)) {
			fVec13[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 8192; l36 = faust_wrap_add(l36, 1)) {
			fVec14[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec30[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 16384; l38 = faust_wrap_add(l38, 1)) {
			fVec15[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 8192; l39 = faust_wrap_add(l39, 1)) {
			fVec16[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2048; l40 = faust_wrap_add(l40, 1)) {
			fVec17[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec28[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			fRec26[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec24[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 3; l44 = faust_wrap_add(l44, 1)) {
			fRec57[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 3; l45 = faust_wrap_add(l45, 1)) {
			fRec56[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 8192; l46 = faust_wrap_add(l46, 1)) {
			fVec18[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 8192; l47 = faust_wrap_add(l47, 1)) {
			fVec19[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 8192; l48 = faust_wrap_add(l48, 1)) {
			fVec20[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2048; l49 = faust_wrap_add(l49, 1)) {
			fVec21[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec53[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fRec51[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec49[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 16384; l53 = faust_wrap_add(l53, 1)) {
			fVec22[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 8192; l54 = faust_wrap_add(l54, 1)) {
			fVec23[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			fRec47[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fRec45[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = faust_wrap_add(l57, 1)) {
			fRec43[l57] = 0.0f;
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
	
	virtual TdgRoomSimulator* clone() {
		return new TdgRoomSimulator(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Room Simulator");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "unit", "ms");
		ui_interface->addHorizontalSlider("Predelay", &fHslider2, FAUSTFLOAT(2e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Room Size", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->addHorizontalSlider("Reverb Time", &fHslider3, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.9f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "3", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider0, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		int iSlow2 = static_cast<int>(fConst10 * static_cast<float>(fHslider2));
		int iSlow3 = std::min<int>(16385, std::max<int>(0, faust_wrap_add(iSlow2, 1)));
		float fSlow4 = static_cast<float>(iSlow2);
		float fSlow5 = std::floor(fSlow4);
		float fSlow6 = fSlow4 - fSlow5;
		int iSlow7 = std::min<int>(16385, std::max<int>(0, iSlow2));
		float fSlow8 = fSlow5 + (1.0f - fSlow4);
		float fSlow9 = fConst1 * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = static_cast<float>(input0[i0]);
			fVec0[IOTA0 & 32767] = fTemp0;
			fRec1[0] = fSlow1 + fConst2 * fRec1[1];
			int iTemp1 = static_cast<int>(fRec1[0]);
			int iTemp2 = std::min<int>(2, faust_wrap_add(iTemp1, 1));
			float fTemp3 = fSlow8 * fVec0[(faust_wrap_sub(IOTA0, iSlow7)) & 32767] + fSlow6 * fVec0[(faust_wrap_sub(IOTA0, iSlow3)) & 32767];
			fRec19[0] = fTemp3 - fConst9 * (fConst8 * fRec19[2] + fConst4 * fRec19[1]);
			fRec18[0] = fConst9 * (fRec19[2] + fRec19[0] + 2.0f * fRec19[1]) - fConst7 * (fConst6 * fRec18[2] + fConst4 * fRec18[1]);
			fRec23[0] = fSlow9 + fConst2 * fRec23[1];
			float fRec22 = 0.5f * fRec23[0] * fRec2[1];
			fRec21[0] = fRec22 - fConst23 * (fConst21 * fRec21[2] + fConst19 * fRec21[1]);
			fRec20[0] = fConst24 * (fRec21[2] + (fRec21[0] - 2.0f * fRec21[1])) - fConst16 * (fConst14 * fRec20[2] + fConst12 * fRec20[1]);
			float fTemp4 = fConst25 * (fRec20[2] + fRec20[0] + 2.0f * fRec20[1]) + fConst7 * (fRec18[2] + fRec18[0] + 2.0f * fRec18[1]) - 0.3f * fRec16[1];
			fVec1[IOTA0 & 2047] = fTemp4;
			fRec16[0] = fVec1[(faust_wrap_sub(IOTA0, iConst26)) & 2047];
			float fRec17 = 0.3f * fTemp4;
			float fTemp5 = fRec17 + fRec16[1] - 0.3f * fRec14[1];
			fVec2[IOTA0 & 4095] = fTemp5;
			fRec14[0] = fVec2[(faust_wrap_sub(IOTA0, iConst27)) & 4095];
			float fRec15 = 0.3f * fTemp5;
			float fTemp6 = fRec15 + fRec14[1];
			fVec3[IOTA0 & 4095] = fTemp6;
			float fTemp7 = fVec3[(faust_wrap_sub(IOTA0, iConst29)) & 4095] - 0.5f * fRec10[1];
			fVec4[IOTA0 & 16383] = fTemp7;
			float fTemp8 = fVec4[(faust_wrap_sub(IOTA0, iConst30)) & 16383] - 0.25f * fRec12[1];
			fVec5[IOTA0 & 16383] = fTemp8;
			fRec12[0] = fVec5[(faust_wrap_sub(IOTA0, iConst31)) & 16383];
			float fRec13 = 0.25f * fTemp8;
			fRec10[0] = fRec13 + fRec12[1];
			float fRec11 = 0.5f * fTemp7;
			float fTemp9 = fRec11 + fRec10[1];
			fVec6[IOTA0 & 8191] = fTemp9;
			float fTemp10 = fVec6[(faust_wrap_sub(IOTA0, iConst33)) & 8191] - 0.5f * fRec4[1];
			fVec7[IOTA0 & 16383] = fTemp10;
			float fTemp11 = fVec7[(faust_wrap_sub(IOTA0, iConst34)) & 16383] - 0.25f * fRec6[1];
			fVec8[IOTA0 & 16383] = fTemp11;
			float fTemp12 = fVec8[(faust_wrap_sub(IOTA0, iConst35)) & 16383] - 0.25f * fRec8[1];
			fVec9[IOTA0 & 8191] = fTemp12;
			fRec8[0] = fVec9[(faust_wrap_sub(IOTA0, iConst36)) & 8191];
			float fRec9 = 0.25f * fTemp12;
			fRec6[0] = fRec9 + fRec8[1];
			float fRec7 = 0.25f * fTemp11;
			fRec4[0] = fRec7 + fRec6[1];
			float fRec5 = 0.5f * fTemp10;
			fRec2[0] = fRec5 + fRec4[1];
			float fRec3 = 0.8f * fVec6[(faust_wrap_sub(IOTA0, iConst32)) & 8191] + 1.5f * fVec3[(faust_wrap_sub(IOTA0, iConst28)) & 4095];
			float fTemp13 = fRec2[0] + 0.8f * fRec3;
			fRec39[0] = fTemp3 - fConst43 * (fConst42 * fRec39[2] + fConst38 * fRec39[1]);
			fRec38[0] = fConst43 * (fRec39[2] + fRec39[0] + 2.0f * fRec39[1]) - fConst41 * (fConst40 * fRec38[2] + fConst38 * fRec38[1]);
			float fTemp14 = fConst41 * (fRec38[2] + fRec38[0] + 2.0f * fRec38[1]);
			fRec42[0] = fRec24[1] - fConst23 * (fConst21 * fRec42[2] + fConst19 * fRec42[1]);
			fRec41[0] = fConst24 * (fRec42[2] + (fRec42[0] - 2.0f * fRec42[1])) - fConst16 * (fConst14 * fRec41[2] + fConst12 * fRec41[1]);
			float fRec40 = fConst16 * (fRec41[2] + fRec41[0] + 2.0f * fRec41[1]);
			float fTemp15 = 1.299f * fRec23[0] * fRec40 + fTemp14 - 0.25f * fRec32[1];
			fVec10[IOTA0 & 8191] = fTemp15;
			float fTemp16 = fVec10[(faust_wrap_sub(IOTA0, iConst44)) & 8191] - 0.35f * fRec34[1];
			fVec11[IOTA0 & 2047] = fTemp16;
			float fTemp17 = fVec11[(faust_wrap_sub(IOTA0, iConst45)) & 2047] - 0.45f * fRec36[1];
			fVec12[IOTA0 & 8191] = fTemp17;
			fRec36[0] = fVec12[(faust_wrap_sub(IOTA0, iConst46)) & 8191];
			float fRec37 = 0.45f * fTemp17;
			fRec34[0] = fRec37 + fRec36[1];
			float fRec35 = 0.35f * fTemp16;
			fRec32[0] = fRec35 + fRec34[1];
			float fRec33 = 0.25f * fTemp15;
			float fTemp18 = fRec33 + fRec32[1];
			fVec13[IOTA0 & 1023] = fTemp18;
			float fTemp19 = fVec13[(faust_wrap_sub(IOTA0, iConst47)) & 1023] - 0.45f * fRec30[1];
			fVec14[IOTA0 & 8191] = fTemp19;
			fRec30[0] = fVec14[(faust_wrap_sub(IOTA0, iConst36)) & 8191];
			float fRec31 = 0.45f * fTemp19;
			float fTemp20 = fRec31 + fRec30[1];
			fVec15[IOTA0 & 16383] = fTemp20;
			float fTemp21 = fTemp3 + 0.4f * fRec23[0] * fVec15[(faust_wrap_sub(IOTA0, iConst49)) & 16383] - 0.25f * fRec26[1];
			fVec16[IOTA0 & 8191] = fTemp21;
			float fTemp22 = fVec16[(faust_wrap_sub(IOTA0, iConst50)) & 8191] - 0.35f * fRec28[1];
			fVec17[IOTA0 & 2047] = fTemp22;
			fRec28[0] = fVec17[(faust_wrap_sub(IOTA0, iConst51)) & 2047];
			float fRec29 = 0.35f * fTemp22;
			fRec26[0] = fRec29 + fRec28[1];
			float fRec27 = 0.25f * fTemp21;
			fRec24[0] = fRec27 + fRec26[1];
			float fRec25 = 0.5f * (fTemp18 + fVec15[(faust_wrap_sub(IOTA0, iConst48)) & 16383]);
			float fTemp23 = fRec25 + 0.5f * fRec24[0];
			fRec57[0] = 0.99f * fRec43[1] - fConst63 * (fConst61 * fRec57[2] + fConst59 * fRec57[1]);
			fRec56[0] = fConst64 * (fRec57[2] + (fRec57[0] - 2.0f * fRec57[1])) - fConst56 * (fConst55 * fRec56[2] + fConst53 * fRec56[1]);
			float fRec55 = fConst56 * fRec23[0] * (fRec56[2] + fRec56[0] + 2.0f * fRec56[1]);
			fVec18[IOTA0 & 8191] = fRec55 + fTemp14;
			float fTemp24 = fVec18[(faust_wrap_sub(IOTA0, iConst65)) & 8191] - 0.15f * fRec49[1];
			fVec19[IOTA0 & 8191] = fTemp24;
			float fTemp25 = fVec19[(faust_wrap_sub(IOTA0, iConst44)) & 8191] - 0.25f * fRec51[1];
			fVec20[IOTA0 & 8191] = fTemp25;
			float fTemp26 = fVec20[(faust_wrap_sub(IOTA0, iConst46)) & 8191] - 0.3f * fRec53[1];
			fVec21[IOTA0 & 2047] = fTemp26;
			fRec53[0] = fVec21[(faust_wrap_sub(IOTA0, iConst45)) & 2047];
			float fRec54 = 0.3f * fTemp26;
			fRec51[0] = fRec54 + fRec53[1];
			float fRec52 = 0.25f * fTemp25;
			fRec49[0] = fRec52 + fRec51[1];
			float fRec50 = 0.15f * fTemp24;
			float fTemp27 = fRec50 + fRec49[1];
			float fTemp28 = fTemp27 - 0.08f * fRec45[1];
			fVec22[IOTA0 & 16383] = fTemp28;
			float fTemp29 = fVec22[(faust_wrap_sub(IOTA0, iConst66)) & 16383] - 0.3f * fRec47[1];
			fVec23[IOTA0 & 8191] = fTemp29;
			fRec47[0] = fVec23[(faust_wrap_sub(IOTA0, iConst36)) & 8191];
			float fRec48 = 0.3f * fTemp29;
			fRec45[0] = fRec48 + fRec47[1];
			float fRec46 = 0.08f * fTemp28;
			fRec43[0] = fRec46 + fRec45[1];
			float fRec44 = fTemp27;
			float fTemp30 = 0.5f * (fRec43[0] + fRec44);
			float fTemp31 = std::floor(fRec1[0]);
			output0[i0] = static_cast<FAUSTFLOAT>(fRec0[0] * ((fTemp31 + (1.0f - fRec1[0])) * ((iTemp1 == 0) ? fTemp30 : ((iTemp1 == 1) ? fTemp23 : fTemp13)) + (fRec1[0] - fTemp31) * ((iTemp2 == 0) ? fTemp30 : ((iTemp2 == 1) ? fTemp23 : fTemp13))) + fTemp0 * (1.0f - fRec0[0]));
			fRec0[1] = fRec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec1[1] = fRec1[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec23[1] = fRec23[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec16[1] = fRec16[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fRec53[1] = fRec53[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec47[1] = fRec47[0];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
		}
	}

};

#endif
