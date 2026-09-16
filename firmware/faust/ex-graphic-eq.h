/* ------------------------------------------------------------
author: "Julius O. Smith III"
license: "LicenseRef-STK-4.3"
name: "Graphic EQ 7"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn ExGraphicEq -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __ExGraphicEq_H__
#define  __ExGraphicEq_H__

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
#define FAUSTCLASS ExGraphicEq
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

static float ExGraphicEq_faustpower2_f(float value) {
	return value * value;
}

class ExGraphicEq : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
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
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fConst30;
	float fConst31;
	float fConst32;
	float fConst33;
	float fConst34;
	float fConst35;
	float fConst36;
	float fConst37;
	float fConst38;
	float fConst39;
	float fConst40;
	float fConst41;
	float fConst42;
	float fConst43;
	float fConst44;
	float fConst45;
	float fConst46;
	float fConst47;
	float fVec0[2];
	float fConst48;
	float fConst49;
	float fRec6[2];
	float fRec5[3];
	float fConst50;
	float fRec4[3];
	float fRec3[3];
	float fRec2[3];
	float fRec1[3];
	float fRec0[3];
	float fConst51;
	float fConst52;
	FAUSTFLOAT fHslider0;
	float fRec7[2];
	float fConst53;
	float fConst54;
	float fConst55;
	float fRec15[2];
	float fRec14[3];
	float fVec1[2];
	float fConst56;
	float fConst57;
	float fRec13[2];
	float fRec12[3];
	float fConst58;
	float fRec11[3];
	float fRec10[3];
	float fRec9[3];
	float fRec8[3];
	FAUSTFLOAT fHslider1;
	float fRec16[2];
	float fConst59;
	float fConst60;
	float fConst61;
	float fRec23[2];
	float fRec22[3];
	float fVec2[2];
	float fConst62;
	float fConst63;
	float fRec21[2];
	float fRec20[3];
	float fConst64;
	float fRec19[3];
	float fRec18[3];
	float fRec17[3];
	FAUSTFLOAT fHslider2;
	float fRec24[2];
	float fConst65;
	float fConst66;
	float fConst67;
	float fRec30[2];
	float fRec29[3];
	float fVec3[2];
	float fConst68;
	float fConst69;
	float fRec28[2];
	float fRec27[3];
	float fConst70;
	float fRec26[3];
	float fRec25[3];
	FAUSTFLOAT fHslider3;
	float fRec31[2];
	float fConst71;
	float fConst72;
	float fConst73;
	float fRec36[2];
	float fRec35[3];
	float fVec4[2];
	float fConst74;
	float fConst75;
	float fRec34[2];
	float fRec33[3];
	float fConst76;
	float fRec32[3];
	FAUSTFLOAT fHslider4;
	float fRec37[2];
	float fConst77;
	float fConst78;
	float fRec41[2];
	float fRec40[3];
	float fVec5[2];
	float fConst79;
	float fConst80;
	float fRec39[2];
	float fRec38[3];
	FAUSTFLOAT fHslider5;
	float fRec42[2];
	float fRec44[2];
	float fRec43[3];
	FAUSTFLOAT fHslider6;
	float fRec45[2];
	
 public:
	ExGraphicEq() {
	}
	
	ExGraphicEq(const ExGraphicEq&) = default;
	
	virtual ~ExGraphicEq() = default;
	
	ExGraphicEq& operator=(const ExGraphicEq&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Julius O. Smith III");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn ExGraphicEq -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "7-band graphic equalizer built on fi.filterbank (Butterworth crossovers) with per-band gain");
		m->declare("family", "utility");
		m->declare("filename", "ex-graphic-eq.dsp");
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
		m->declare("license", "LicenseRef-STK-4.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Graphic EQ 7");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faust/examples/filtering/graphicEqLab.dsp fi.filterbank");
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
		fConst1 = std::tan(442.96457f / fConst0);
		fConst2 = 1.0f / ExGraphicEq_faustpower2_f(fConst1);
		fConst3 = 2.0f * (1.0f - fConst2);
		fConst4 = 1.0f / fConst1;
		fConst5 = 1.0f - fConst4;
		fConst6 = 1.0f - fConst5 / fConst1;
		fConst7 = fConst4 + 1.0f;
		fConst8 = 1.0f / (fConst7 / fConst1 + 1.0f);
		fConst9 = std::tan(889.07074f / fConst0);
		fConst10 = ExGraphicEq_faustpower2_f(fConst9);
		fConst11 = 2.0f * (1.0f - 1.0f / fConst10);
		fConst12 = 1.0f / fConst9;
		fConst13 = 1.0f - fConst12;
		fConst14 = 1.0f - fConst13 / fConst9;
		fConst15 = fConst12 + 1.0f;
		fConst16 = 1.0f / (fConst15 / fConst9 + 1.0f);
		fConst17 = std::tan(1778.1415f / fConst0);
		fConst18 = ExGraphicEq_faustpower2_f(fConst17);
		fConst19 = 2.0f * (1.0f - 1.0f / fConst18);
		fConst20 = 1.0f / fConst17;
		fConst21 = 1.0f - fConst20;
		fConst22 = 1.0f - fConst21 / fConst17;
		fConst23 = fConst20 + 1.0f;
		fConst24 = 1.0f / (fConst23 / fConst17 + 1.0f);
		fConst25 = std::tan(3553.1414f / fConst0);
		fConst26 = ExGraphicEq_faustpower2_f(fConst25);
		fConst27 = 2.0f * (1.0f - 1.0f / fConst26);
		fConst28 = 1.0f / fConst25;
		fConst29 = 1.0f - fConst28;
		fConst30 = 1.0f - fConst29 / fConst25;
		fConst31 = fConst28 + 1.0f;
		fConst32 = 1.0f / (fConst31 / fConst25 + 1.0f);
		fConst33 = std::tan(7109.4243f / fConst0);
		fConst34 = ExGraphicEq_faustpower2_f(fConst33);
		fConst35 = 2.0f * (1.0f - 1.0f / fConst34);
		fConst36 = 1.0f / fConst33;
		fConst37 = 1.0f - fConst36;
		fConst38 = 1.0f - fConst37 / fConst33;
		fConst39 = fConst36 + 1.0f;
		fConst40 = 1.0f / (fConst39 / fConst33 + 1.0f);
		fConst41 = std::tan(14215.707f / fConst0);
		fConst42 = ExGraphicEq_faustpower2_f(fConst41);
		fConst43 = 2.0f * (1.0f - 1.0f / fConst42);
		fConst44 = 1.0f / fConst41;
		fConst45 = (fConst44 + -1.0f) / fConst41 + 1.0f;
		fConst46 = (fConst44 + 1.0f) / fConst41 + 1.0f;
		fConst47 = 1.0f / fConst46;
		fConst48 = 1.0f - fConst44;
		fConst49 = 1.0f / (fConst44 + 1.0f);
		fConst50 = 1.0f / (fConst42 * fConst46);
		fConst51 = 44.1f / fConst0;
		fConst52 = 1.0f - fConst51;
		fConst53 = (fConst36 + -1.0f) / fConst33 + 1.0f;
		fConst54 = (fConst36 + 1.0f) / fConst33 + 1.0f;
		fConst55 = 1.0f / fConst54;
		fConst56 = 1.0f / (fConst33 * fConst46);
		fConst57 = 1.0f / fConst39;
		fConst58 = 1.0f / (fConst34 * fConst54);
		fConst59 = (fConst28 + -1.0f) / fConst25 + 1.0f;
		fConst60 = (fConst28 + 1.0f) / fConst25 + 1.0f;
		fConst61 = 1.0f / fConst60;
		fConst62 = 1.0f / (fConst25 * fConst54);
		fConst63 = 1.0f / fConst31;
		fConst64 = 1.0f / (fConst26 * fConst60);
		fConst65 = (fConst20 + -1.0f) / fConst17 + 1.0f;
		fConst66 = (fConst20 + 1.0f) / fConst17 + 1.0f;
		fConst67 = 1.0f / fConst66;
		fConst68 = 1.0f / (fConst17 * fConst60);
		fConst69 = 1.0f / fConst23;
		fConst70 = 1.0f / (fConst18 * fConst66);
		fConst71 = (fConst12 + -1.0f) / fConst9 + 1.0f;
		fConst72 = (fConst12 + 1.0f) / fConst9 + 1.0f;
		fConst73 = 1.0f / fConst72;
		fConst74 = 1.0f / (fConst9 * fConst66);
		fConst75 = 1.0f / fConst15;
		fConst76 = 1.0f / (fConst10 * fConst72);
		fConst77 = (fConst4 + -1.0f) / fConst1 + 1.0f;
		fConst78 = 1.0f / ((fConst4 + 1.0f) / fConst1 + 1.0f);
		fConst79 = 1.0f / (fConst1 * fConst72);
		fConst80 = 1.0f / fConst7;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider6 = static_cast<FAUSTFLOAT>(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec6[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec5[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec2[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec1[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec0[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec15[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec14[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fVec1[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = faust_wrap_add(l13, 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = faust_wrap_add(l14, 1)) {
			fRec11[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 3; l15 = faust_wrap_add(l15, 1)) {
			fRec10[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 3; l16 = faust_wrap_add(l16, 1)) {
			fRec9[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 3; l17 = faust_wrap_add(l17, 1)) {
			fRec8[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec23[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 3; l20 = faust_wrap_add(l20, 1)) {
			fRec22[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fVec2[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec21[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 3; l23 = faust_wrap_add(l23, 1)) {
			fRec20[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 3; l24 = faust_wrap_add(l24, 1)) {
			fRec19[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 3; l25 = faust_wrap_add(l25, 1)) {
			fRec18[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 3; l26 = faust_wrap_add(l26, 1)) {
			fRec17[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec24[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec30[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 3; l29 = faust_wrap_add(l29, 1)) {
			fRec29[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fVec3[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec28[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 3; l32 = faust_wrap_add(l32, 1)) {
			fRec27[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 3; l33 = faust_wrap_add(l33, 1)) {
			fRec26[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 3; l34 = faust_wrap_add(l34, 1)) {
			fRec25[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec31[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec36[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 3; l37 = faust_wrap_add(l37, 1)) {
			fRec35[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fVec4[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec34[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 3; l40 = faust_wrap_add(l40, 1)) {
			fRec33[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 3; l41 = faust_wrap_add(l41, 1)) {
			fRec32[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			fRec37[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec41[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 3; l44 = faust_wrap_add(l44, 1)) {
			fRec40[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fVec5[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fRec39[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 3; l47 = faust_wrap_add(l47, 1)) {
			fRec38[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec42[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec44[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 3; l50 = faust_wrap_add(l50, 1)) {
			fRec43[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fRec45[l51] = 0.0f;
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
	
	virtual ExGraphicEq* clone() {
		return new ExGraphicEq(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Graphic EQ 7");
		ui_interface->declare(&fHslider6, "0", "");
		ui_interface->declare(&fHslider6, "unit", "dB");
		ui_interface->addHorizontalSlider("100 Hz", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider5, "1", "");
		ui_interface->declare(&fHslider5, "unit", "dB");
		ui_interface->addHorizontalSlider("200 Hz", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider4, "2", "");
		ui_interface->declare(&fHslider4, "unit", "dB");
		ui_interface->addHorizontalSlider("400 Hz", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->declare(&fHslider3, "unit", "dB");
		ui_interface->addHorizontalSlider("800 Hz", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider2, "4", "");
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("1600 Hz", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "5", "");
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("3200 Hz", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider0, "6", "");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("6400 Hz", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst51 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider0));
		float fSlow1 = fConst51 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider1));
		float fSlow2 = fConst51 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider2));
		float fSlow3 = fConst51 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider3));
		float fSlow4 = fConst51 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider4));
		float fSlow5 = fConst51 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider5));
		float fSlow6 = fConst51 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider6));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			float fTemp0 = fConst3 * fRec0[1];
			float fTemp1 = fConst11 * fRec1[1];
			float fTemp2 = fConst19 * fRec2[1];
			float fTemp3 = fConst27 * fRec3[1];
			float fTemp4 = fConst35 * fRec4[1];
			float fTemp5 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp5;
			fRec6[0] = -(fConst49 * (fConst48 * fRec6[1] - fConst44 * (fTemp5 - fVec0[1])));
			fRec5[0] = fRec6[0] - fConst47 * (fConst45 * fRec5[2] + fConst43 * fRec5[1]);
			fRec4[0] = fConst50 * (fRec5[2] + (fRec5[0] - 2.0f * fRec5[1])) - fConst40 * (fConst38 * fRec4[2] + fTemp4);
			fRec3[0] = fRec4[2] + fConst40 * (fTemp4 + fConst38 * fRec4[0]) - fConst32 * (fConst30 * fRec3[2] + fTemp3);
			fRec2[0] = fRec3[2] + fConst32 * (fTemp3 + fConst30 * fRec3[0]) - fConst24 * (fConst22 * fRec2[2] + fTemp2);
			fRec1[0] = fRec2[2] + fConst24 * (fTemp2 + fConst22 * fRec2[0]) - fConst16 * (fConst14 * fRec1[2] + fTemp1);
			fRec0[0] = fRec1[2] + fConst16 * (fTemp1 + fConst14 * fRec1[0]) - fConst8 * (fConst6 * fRec0[2] + fTemp0);
			fRec7[0] = fSlow0 + fConst52 * fRec7[1];
			float fTemp6 = fConst3 * fRec8[1];
			float fTemp7 = fConst11 * fRec9[1];
			float fTemp8 = fConst19 * fRec10[1];
			float fTemp9 = fConst27 * fRec11[1];
			fRec15[0] = -(fConst49 * (fConst48 * fRec15[1] - (fTemp5 + fVec0[1])));
			fRec14[0] = fRec15[0] - fConst47 * (fConst45 * fRec14[2] + fConst43 * fRec14[1]);
			float fTemp10 = fRec14[2] + fRec14[0] + 2.0f * fRec14[1];
			fVec1[0] = fTemp10;
			fRec13[0] = -(fConst57 * (fConst37 * fRec13[1] - fConst56 * (fTemp10 - fVec1[1])));
			fRec12[0] = fRec13[0] - fConst55 * (fConst53 * fRec12[2] + fConst35 * fRec12[1]);
			fRec11[0] = fConst58 * (fRec12[2] + (fRec12[0] - 2.0f * fRec12[1])) - fConst32 * (fConst30 * fRec11[2] + fTemp9);
			fRec10[0] = fRec11[2] + fConst32 * (fTemp9 + fConst30 * fRec11[0]) - fConst24 * (fConst22 * fRec10[2] + fTemp8);
			fRec9[0] = fRec10[2] + fConst24 * (fTemp8 + fConst22 * fRec10[0]) - fConst16 * (fConst14 * fRec9[2] + fTemp7);
			fRec8[0] = fRec9[2] + fConst16 * (fTemp7 + fConst14 * fRec9[0]) - fConst8 * (fConst6 * fRec8[2] + fTemp6);
			fRec16[0] = fSlow1 + fConst52 * fRec16[1];
			float fTemp11 = fConst3 * fRec17[1];
			float fTemp12 = fConst11 * fRec18[1];
			float fTemp13 = fConst19 * fRec19[1];
			fRec23[0] = -(fConst57 * (fConst37 * fRec23[1] - fConst47 * (fTemp10 + fVec1[1])));
			fRec22[0] = fRec23[0] - fConst55 * (fConst53 * fRec22[2] + fConst35 * fRec22[1]);
			float fTemp14 = fRec22[2] + fRec22[0] + 2.0f * fRec22[1];
			fVec2[0] = fTemp14;
			fRec21[0] = -(fConst63 * (fConst29 * fRec21[1] - fConst62 * (fTemp14 - fVec2[1])));
			fRec20[0] = fRec21[0] - fConst61 * (fConst59 * fRec20[2] + fConst27 * fRec20[1]);
			fRec19[0] = fConst64 * (fRec20[2] + (fRec20[0] - 2.0f * fRec20[1])) - fConst24 * (fConst22 * fRec19[2] + fTemp13);
			fRec18[0] = fRec19[2] + fConst24 * (fTemp13 + fConst22 * fRec19[0]) - fConst16 * (fConst14 * fRec18[2] + fTemp12);
			fRec17[0] = fRec18[2] + fConst16 * (fTemp12 + fConst14 * fRec18[0]) - fConst8 * (fConst6 * fRec17[2] + fTemp11);
			fRec24[0] = fSlow2 + fConst52 * fRec24[1];
			float fTemp15 = fConst3 * fRec25[1];
			float fTemp16 = fConst11 * fRec26[1];
			fRec30[0] = -(fConst63 * (fConst29 * fRec30[1] - fConst55 * (fTemp14 + fVec2[1])));
			fRec29[0] = fRec30[0] - fConst61 * (fConst59 * fRec29[2] + fConst27 * fRec29[1]);
			float fTemp17 = fRec29[2] + fRec29[0] + 2.0f * fRec29[1];
			fVec3[0] = fTemp17;
			fRec28[0] = -(fConst69 * (fConst21 * fRec28[1] - fConst68 * (fTemp17 - fVec3[1])));
			fRec27[0] = fRec28[0] - fConst67 * (fConst65 * fRec27[2] + fConst19 * fRec27[1]);
			fRec26[0] = fConst70 * (fRec27[2] + (fRec27[0] - 2.0f * fRec27[1])) - fConst16 * (fConst14 * fRec26[2] + fTemp16);
			fRec25[0] = fRec26[2] + fConst16 * (fTemp16 + fConst14 * fRec26[0]) - fConst8 * (fConst6 * fRec25[2] + fTemp15);
			fRec31[0] = fSlow3 + fConst52 * fRec31[1];
			float fTemp18 = fConst3 * fRec32[1];
			fRec36[0] = -(fConst69 * (fConst21 * fRec36[1] - fConst61 * (fTemp17 + fVec3[1])));
			fRec35[0] = fRec36[0] - fConst67 * (fConst65 * fRec35[2] + fConst19 * fRec35[1]);
			float fTemp19 = fRec35[2] + fRec35[0] + 2.0f * fRec35[1];
			fVec4[0] = fTemp19;
			fRec34[0] = -(fConst75 * (fConst13 * fRec34[1] - fConst74 * (fTemp19 - fVec4[1])));
			fRec33[0] = fRec34[0] - fConst73 * (fConst71 * fRec33[2] + fConst11 * fRec33[1]);
			fRec32[0] = fConst76 * (fRec33[2] + (fRec33[0] - 2.0f * fRec33[1])) - fConst8 * (fConst6 * fRec32[2] + fTemp18);
			fRec37[0] = fSlow4 + fConst52 * fRec37[1];
			fRec41[0] = -(fConst75 * (fConst13 * fRec41[1] - fConst67 * (fTemp19 + fVec4[1])));
			fRec40[0] = fRec41[0] - fConst73 * (fConst71 * fRec40[2] + fConst11 * fRec40[1]);
			float fTemp20 = fRec40[2] + fRec40[0] + 2.0f * fRec40[1];
			fVec5[0] = fTemp20;
			fRec39[0] = -(fConst80 * (fConst5 * fRec39[1] - fConst79 * (fTemp20 - fVec5[1])));
			fRec38[0] = fRec39[0] - fConst78 * (fConst77 * fRec38[2] + fConst3 * fRec38[1]);
			fRec42[0] = fSlow5 + fConst52 * fRec42[1];
			fRec44[0] = -(fConst80 * (fConst5 * fRec44[1] - fConst73 * (fTemp20 + fVec5[1])));
			fRec43[0] = fRec44[0] - fConst78 * (fConst77 * fRec43[2] + fConst3 * fRec43[1]);
			fRec45[0] = fSlow6 + fConst52 * fRec45[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fConst78 * (fRec45[0] * (fRec43[2] + fRec43[0] + 2.0f * fRec43[1]) + fConst2 * fRec42[0] * (fRec38[2] + (fRec38[0] - 2.0f * fRec38[1]))) + fRec37[0] * (fRec32[2] + fConst8 * (fTemp18 + fConst6 * fRec32[0])) + fRec31[0] * (fRec25[2] + fConst8 * (fTemp15 + fConst6 * fRec25[0])) + fRec24[0] * (fRec17[2] + fConst8 * (fTemp11 + fConst6 * fRec17[0])) + fRec16[0] * (fRec8[2] + fConst8 * (fTemp6 + fConst6 * fRec8[0])) + fRec7[0] * (fRec0[2] + fConst8 * (fTemp0 + fConst6 * fRec0[0])));
			fVec0[1] = fVec0[0];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec7[1] = fRec7[0];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fVec1[1] = fVec1[0];
			fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec16[1] = fRec16[0];
			fRec23[1] = fRec23[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fVec2[1] = fVec2[0];
			fRec21[1] = fRec21[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec24[1] = fRec24[0];
			fRec30[1] = fRec30[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fVec3[1] = fVec3[0];
			fRec28[1] = fRec28[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec31[1] = fRec31[0];
			fRec36[1] = fRec36[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fVec4[1] = fVec4[0];
			fRec34[1] = fRec34[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec37[1] = fRec37[0];
			fRec41[1] = fRec41[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fVec5[1] = fVec5[0];
			fRec39[1] = fRec39[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec42[1] = fRec42[0];
			fRec44[1] = fRec44[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec45[1] = fRec45[0];
		}
	}

};

#endif
