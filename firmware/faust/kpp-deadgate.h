/* ------------------------------------------------------------
author: "Oleg Kapitonov"
license: "GPL-3.0-or-later"
name: "KPP Dead Gate"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn KppDeadgate -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __KppDeadgate_H__
#define  __KppDeadgate_H__

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
#define FAUSTCLASS KppDeadgate
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

static float KppDeadgate_faustpower2_f(float value) {
	return value * value;
}

class KppDeadgate : public chdsp {
	
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
	FAUSTFLOAT fHslider0;
	float fVec0[2];
	float fConst44;
	float fConst45;
	float fConst46;
	float fRec12[2];
	float fVec1[2];
	float fConst47;
	float fConst48;
	float fRec11[2];
	float fRec10[3];
	float fVec2[2];
	float fConst49;
	float fConst50;
	float fConst51;
	float fRec9[2];
	float fRec8[3];
	float fVec3[2];
	float fConst52;
	float fConst53;
	float fConst54;
	float fRec7[2];
	float fRec6[3];
	float fVec4[2];
	float fConst55;
	float fConst56;
	float fConst57;
	float fRec5[2];
	float fRec4[3];
	float fVec5[2];
	float fConst58;
	float fConst59;
	float fConst60;
	float fRec3[2];
	float fRec2[3];
	float fVec6[2];
	float fConst61;
	float fConst62;
	float fConst63;
	float fConst64;
	float fRec1[2];
	float fRec0[3];
	FAUSTFLOAT fHslider1;
	float fConst65;
	float fConst66;
	float fConst67;
	float fRec14[2];
	int iVec7[2];
	int iConst68;
	int iRec15[2];
	float fConst69;
	float fRec13[2];
	float fRec17[2];
	float fRec16[3];
	float fRec19[2];
	int iVec8[2];
	int iRec20[2];
	float fRec18[2];
	float fConst70;
	float fConst71;
	float fConst72;
	float fRec23[2];
	float fRec22[3];
	float fConst73;
	float fRec21[3];
	float fRec25[2];
	int iVec9[2];
	int iRec26[2];
	float fRec24[2];
	float fConst74;
	float fConst75;
	float fConst76;
	float fRec30[2];
	float fRec29[3];
	float fConst77;
	float fRec28[3];
	float fRec27[3];
	float fRec32[2];
	int iVec10[2];
	int iRec33[2];
	float fRec31[2];
	float fConst78;
	float fConst79;
	float fConst80;
	float fRec38[2];
	float fRec37[3];
	float fConst81;
	float fRec36[3];
	float fRec35[3];
	float fRec34[3];
	float fRec40[2];
	int iVec11[2];
	int iRec41[2];
	float fRec39[2];
	float fConst82;
	float fConst83;
	float fConst84;
	float fRec47[2];
	float fRec46[3];
	float fConst85;
	float fRec45[3];
	float fRec44[3];
	float fRec43[3];
	float fRec42[3];
	float fRec49[2];
	int iVec12[2];
	int iRec50[2];
	float fRec48[2];
	float fConst86;
	float fConst87;
	float fRec57[2];
	float fRec56[3];
	float fConst88;
	float fRec55[3];
	float fRec54[3];
	float fRec53[3];
	float fRec52[3];
	float fRec51[3];
	float fRec59[2];
	int iVec13[2];
	int iRec60[2];
	float fRec58[2];
	FAUSTFLOAT fHslider2;
	
 public:
	KppDeadgate() {
	}
	
	KppDeadgate(const KppDeadgate&) = default;
	
	virtual ~KppDeadgate() = default;
	
	KppDeadgate& operator=(const KppDeadgate&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Oleg Kapitonov");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn KppDeadgate -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Aggressive noise gate: instant dead-zone clamp plus a 7-band multiband gate (10 ms attack, 20 ms hold/release)");
		m->declare("family", "dynamics");
		m->declare("filename", "kpp-deadgate.dsp");
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
		m->declare("license", "GPL-3.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/gate_gain_mono:author", "Julius O. Smith III");
		m->declare("misceffects.lib/gate_gain_mono:license", "LicenseRef-STK-4.3");
		m->declare("misceffects.lib/gate_mono:author", "Julius O. Smith III");
		m->declare("misceffects.lib/gate_mono:license", "LicenseRef-STK-4.3");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "KPP Dead Gate");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "LicenseRef-STK-4.3");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_deadgate/kpp_deadgate.dsp");
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
		fConst1 = std::tan(204.20352f / fConst0);
		fConst2 = KppDeadgate_faustpower2_f(fConst1);
		fConst3 = 1.0f / fConst2;
		fConst4 = 2.0f * (1.0f - fConst3);
		fConst5 = 1.0f / fConst1;
		fConst6 = (fConst5 + -1.0f) / fConst1 + 1.0f;
		fConst7 = (fConst5 + 1.0f) / fConst1 + 1.0f;
		fConst8 = 1.0f / fConst7;
		fConst9 = std::tan(471.2389f / fConst0);
		fConst10 = KppDeadgate_faustpower2_f(fConst9);
		fConst11 = 2.0f * (1.0f - 1.0f / fConst10);
		fConst12 = 1.0f / fConst9;
		fConst13 = (fConst12 + -1.0f) / fConst9 + 1.0f;
		fConst14 = (fConst12 + 1.0f) / fConst9 + 1.0f;
		fConst15 = 1.0f / fConst14;
		fConst16 = std::tan(942.4778f / fConst0);
		fConst17 = KppDeadgate_faustpower2_f(fConst16);
		fConst18 = 2.0f * (1.0f - 1.0f / fConst17);
		fConst19 = 1.0f / fConst16;
		fConst20 = (fConst19 + -1.0f) / fConst16 + 1.0f;
		fConst21 = (fConst19 + 1.0f) / fConst16 + 1.0f;
		fConst22 = 1.0f / fConst21;
		fConst23 = std::tan(1884.9556f / fConst0);
		fConst24 = KppDeadgate_faustpower2_f(fConst23);
		fConst25 = 2.0f * (1.0f - 1.0f / fConst24);
		fConst26 = 1.0f / fConst23;
		fConst27 = (fConst26 + -1.0f) / fConst23 + 1.0f;
		fConst28 = (fConst26 + 1.0f) / fConst23 + 1.0f;
		fConst29 = 1.0f / fConst28;
		fConst30 = std::tan(3769.9111f / fConst0);
		fConst31 = KppDeadgate_faustpower2_f(fConst30);
		fConst32 = 2.0f * (1.0f - 1.0f / fConst31);
		fConst33 = 1.0f / fConst30;
		fConst34 = (fConst33 + -1.0f) / fConst30 + 1.0f;
		fConst35 = (fConst33 + 1.0f) / fConst30 + 1.0f;
		fConst36 = 1.0f / fConst35;
		fConst37 = std::tan(7539.8223f / fConst0);
		fConst38 = KppDeadgate_faustpower2_f(fConst37);
		fConst39 = 2.0f * (1.0f - 1.0f / fConst38);
		fConst40 = 1.0f / fConst37;
		fConst41 = (fConst40 + -1.0f) / fConst37 + 1.0f;
		fConst42 = (fConst40 + 1.0f) / fConst37 + 1.0f;
		fConst43 = 1.0f / fConst42;
		fConst44 = 1.0f / std::tan(31.415926f / fConst0);
		fConst45 = 1.0f - fConst44;
		fConst46 = 1.0f / (fConst44 + 1.0f);
		fConst47 = 1.0f - fConst40;
		fConst48 = 1.0f / (fConst40 + 1.0f);
		fConst49 = 1.0f - fConst33;
		fConst50 = fConst33 + 1.0f;
		fConst51 = 1.0f / fConst50;
		fConst52 = 1.0f - fConst26;
		fConst53 = fConst26 + 1.0f;
		fConst54 = 1.0f / fConst53;
		fConst55 = 1.0f - fConst19;
		fConst56 = fConst19 + 1.0f;
		fConst57 = 1.0f / fConst56;
		fConst58 = 1.0f - fConst12;
		fConst59 = fConst12 + 1.0f;
		fConst60 = 1.0f / fConst59;
		fConst61 = 1.0f / (fConst1 * fConst14);
		fConst62 = 1.0f - fConst5;
		fConst63 = fConst5 + 1.0f;
		fConst64 = 1.0f / fConst63;
		fConst65 = std::exp(-(1e+02f / fConst0));
		fConst66 = 1.0f / (fConst2 * fConst7);
		fConst67 = 1.0f - fConst65;
		iConst68 = static_cast<int>(0.02f * fConst0);
		fConst69 = std::exp(-(5e+01f / fConst0));
		fConst70 = 1.0f - fConst62 / fConst1;
		fConst71 = 1.0f / (fConst63 / fConst1 + 1.0f);
		fConst72 = 1.0f / (fConst9 * fConst21);
		fConst73 = 1.0f / (fConst10 * fConst14);
		fConst74 = 1.0f - fConst58 / fConst9;
		fConst75 = 1.0f / (fConst59 / fConst9 + 1.0f);
		fConst76 = 1.0f / (fConst16 * fConst28);
		fConst77 = 1.0f / (fConst17 * fConst21);
		fConst78 = 1.0f - fConst55 / fConst16;
		fConst79 = 1.0f / (fConst56 / fConst16 + 1.0f);
		fConst80 = 1.0f / (fConst23 * fConst35);
		fConst81 = 1.0f / (fConst24 * fConst28);
		fConst82 = 1.0f - fConst52 / fConst23;
		fConst83 = 1.0f / (fConst53 / fConst23 + 1.0f);
		fConst84 = 1.0f / (fConst30 * fConst42);
		fConst85 = 1.0f / (fConst31 * fConst35);
		fConst86 = 1.0f - fConst49 / fConst30;
		fConst87 = 1.0f / (fConst50 / fConst30 + 1.0f);
		fConst88 = 1.0f / (fConst38 * fConst42);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(-6e+01f);
		fHslider1 = static_cast<FAUSTFLOAT>(-6e+01f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec12[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec11[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec10[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fVec2[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec9[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec8[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec6[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fVec4[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec5[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = faust_wrap_add(l13, 1)) {
			fRec4[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fVec5[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec3[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 3; l16 = faust_wrap_add(l16, 1)) {
			fRec2[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fVec6[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec1[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 3; l19 = faust_wrap_add(l19, 1)) {
			fRec0[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec14[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			iVec7[l21] = 0;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			iRec15[l22] = 0;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec13[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec17[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 3; l25 = faust_wrap_add(l25, 1)) {
			fRec16[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec19[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			iVec8[l27] = 0;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			iRec20[l28] = 0;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec18[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec23[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 3; l31 = faust_wrap_add(l31, 1)) {
			fRec22[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 3; l32 = faust_wrap_add(l32, 1)) {
			fRec21[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec25[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			iVec9[l34] = 0;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			iRec26[l35] = 0;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec24[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec30[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 3; l38 = faust_wrap_add(l38, 1)) {
			fRec29[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 3; l39 = faust_wrap_add(l39, 1)) {
			fRec28[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 3; l40 = faust_wrap_add(l40, 1)) {
			fRec27[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec32[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			iVec10[l42] = 0;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			iRec33[l43] = 0;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec31[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec38[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 3; l46 = faust_wrap_add(l46, 1)) {
			fRec37[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 3; l47 = faust_wrap_add(l47, 1)) {
			fRec36[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 3; l48 = faust_wrap_add(l48, 1)) {
			fRec35[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 3; l49 = faust_wrap_add(l49, 1)) {
			fRec34[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec40[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			iVec11[l51] = 0;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			iRec41[l52] = 0;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fRec39[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fRec47[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 3; l55 = faust_wrap_add(l55, 1)) {
			fRec46[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 3; l56 = faust_wrap_add(l56, 1)) {
			fRec45[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 3; l57 = faust_wrap_add(l57, 1)) {
			fRec44[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 3; l58 = faust_wrap_add(l58, 1)) {
			fRec43[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 3; l59 = faust_wrap_add(l59, 1)) {
			fRec42[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = faust_wrap_add(l60, 1)) {
			fRec49[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = faust_wrap_add(l61, 1)) {
			iVec12[l61] = 0;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			iRec50[l62] = 0;
		}
		for (int l63 = 0; l63 < 2; l63 = faust_wrap_add(l63, 1)) {
			fRec48[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 2; l64 = faust_wrap_add(l64, 1)) {
			fRec57[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 3; l65 = faust_wrap_add(l65, 1)) {
			fRec56[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 3; l66 = faust_wrap_add(l66, 1)) {
			fRec55[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 3; l67 = faust_wrap_add(l67, 1)) {
			fRec54[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 3; l68 = faust_wrap_add(l68, 1)) {
			fRec53[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 3; l69 = faust_wrap_add(l69, 1)) {
			fRec52[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 3; l70 = faust_wrap_add(l70, 1)) {
			fRec51[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = faust_wrap_add(l71, 1)) {
			fRec59[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = faust_wrap_add(l72, 1)) {
			iVec13[l72] = 0;
		}
		for (int l73 = 0; l73 < 2; l73 = faust_wrap_add(l73, 1)) {
			iRec60[l73] = 0;
		}
		for (int l74 = 0; l74 < 2; l74 = faust_wrap_add(l74, 1)) {
			fRec58[l74] = 0.0f;
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
	
	virtual KppDeadgate* clone() {
		return new KppDeadgate(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("KPP Dead Gate");
		ui_interface->declare(&fHslider0, "0", "");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("Dead Zone", &fHslider0, FAUSTFLOAT(-6e+01f), FAUSTFLOAT(-1.2e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("Noise Gate", &fHslider1, FAUSTFLOAT(-6e+01f), FAUSTFLOAT(-1.2e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("Level", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = std::pow(1e+01f, 0.05f * static_cast<float>(fHslider0));
		float fSlow1 = std::pow(1e+01f, 0.05f * static_cast<float>(fHslider1));
		float fSlow2 = std::pow(1e+01f, 0.05f * static_cast<float>(fHslider2));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			float fTemp0 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp0;
			fRec12[0] = -(fConst46 * (fConst45 * fRec12[1] - fConst44 * (fTemp0 - fVec0[1])));
			float fTemp1 = std::max<float>(fSlow0, fRec12[0]) + std::min<float>(-fSlow0, fRec12[0]);
			fVec1[0] = fTemp1;
			fRec11[0] = -(fConst48 * (fConst47 * fRec11[1] - (fTemp1 + fVec1[1])));
			fRec10[0] = fRec11[0] - fConst43 * (fConst41 * fRec10[2] + fConst39 * fRec10[1]);
			float fTemp2 = fRec10[2] + fRec10[0] + 2.0f * fRec10[1];
			fVec2[0] = fTemp2;
			fRec9[0] = -(fConst51 * (fConst49 * fRec9[1] - fConst43 * (fTemp2 + fVec2[1])));
			fRec8[0] = fRec9[0] - fConst36 * (fConst34 * fRec8[2] + fConst32 * fRec8[1]);
			float fTemp3 = fRec8[2] + fRec8[0] + 2.0f * fRec8[1];
			fVec3[0] = fTemp3;
			fRec7[0] = -(fConst54 * (fConst52 * fRec7[1] - fConst36 * (fTemp3 + fVec3[1])));
			fRec6[0] = fRec7[0] - fConst29 * (fConst27 * fRec6[2] + fConst25 * fRec6[1]);
			float fTemp4 = fRec6[2] + fRec6[0] + 2.0f * fRec6[1];
			fVec4[0] = fTemp4;
			fRec5[0] = -(fConst57 * (fConst55 * fRec5[1] - fConst29 * (fTemp4 + fVec4[1])));
			fRec4[0] = fRec5[0] - fConst22 * (fConst20 * fRec4[2] + fConst18 * fRec4[1]);
			float fTemp5 = fRec4[2] + fRec4[0] + 2.0f * fRec4[1];
			fVec5[0] = fTemp5;
			fRec3[0] = -(fConst60 * (fConst58 * fRec3[1] - fConst22 * (fTemp5 + fVec5[1])));
			fRec2[0] = fRec3[0] - fConst15 * (fConst13 * fRec2[2] + fConst11 * fRec2[1]);
			float fTemp6 = fRec2[2] + fRec2[0] + 2.0f * fRec2[1];
			fVec6[0] = fTemp6;
			fRec1[0] = -(fConst64 * (fConst62 * fRec1[1] - fConst61 * (fTemp6 - fVec6[1])));
			fRec0[0] = fRec1[0] - fConst8 * (fConst6 * fRec0[2] + fConst4 * fRec0[1]);
			float fTemp7 = fRec0[2] + (fRec0[0] - 2.0f * fRec0[1]);
			fRec14[0] = fConst67 * std::fabs(fConst66 * fTemp7) + fConst65 * fRec14[1];
			int iTemp8 = fRec14[0] > fSlow1;
			iVec7[0] = iTemp8;
			iRec15[0] = std::max<int>(faust_wrap_mul(iConst68, iTemp8 < iVec7[1]), faust_wrap_add(iRec15[1], -1));
			float fTemp9 = std::fabs(std::max<float>(static_cast<float>(iTemp8), static_cast<float>(iRec15[0] > 0)));
			float fTemp10 = ((fTemp9 > fRec13[1]) ? fConst65 : fConst69);
			fRec13[0] = fTemp9 * (1.0f - fTemp10) + fRec13[1] * fTemp10;
			fRec17[0] = -(fConst64 * (fConst62 * fRec17[1] - fConst15 * (fTemp6 + fVec6[1])));
			fRec16[0] = fRec17[0] - fConst8 * (fConst6 * fRec16[2] + fConst4 * fRec16[1]);
			float fTemp11 = fRec16[2] + fRec16[0] + 2.0f * fRec16[1];
			fRec19[0] = fConst67 * std::fabs(fConst8 * fTemp11) + fConst65 * fRec19[1];
			int iTemp12 = fRec19[0] > fSlow1;
			iVec8[0] = iTemp12;
			iRec20[0] = std::max<int>(faust_wrap_mul(iConst68, iTemp12 < iVec8[1]), faust_wrap_add(iRec20[1], -1));
			float fTemp13 = std::fabs(std::max<float>(static_cast<float>(iTemp12), static_cast<float>(iRec20[0] > 0)));
			float fTemp14 = ((fTemp13 > fRec18[1]) ? fConst65 : fConst69);
			fRec18[0] = fTemp13 * (1.0f - fTemp14) + fRec18[1] * fTemp14;
			float fTemp15 = fConst4 * fRec21[1];
			fRec23[0] = -(fConst60 * (fConst58 * fRec23[1] - fConst72 * (fTemp5 - fVec5[1])));
			fRec22[0] = fRec23[0] - fConst15 * (fConst13 * fRec22[2] + fConst11 * fRec22[1]);
			fRec21[0] = fConst73 * (fRec22[2] + (fRec22[0] - 2.0f * fRec22[1])) - fConst71 * (fConst70 * fRec21[2] + fTemp15);
			float fTemp16 = fRec21[2] + fConst71 * (fTemp15 + fConst70 * fRec21[0]);
			fRec25[0] = fConst67 * std::fabs(fTemp16) + fConst65 * fRec25[1];
			int iTemp17 = fRec25[0] > fSlow1;
			iVec9[0] = iTemp17;
			iRec26[0] = std::max<int>(faust_wrap_mul(iConst68, iTemp17 < iVec9[1]), faust_wrap_add(iRec26[1], -1));
			float fTemp18 = std::fabs(std::max<float>(static_cast<float>(iTemp17), static_cast<float>(iRec26[0] > 0)));
			float fTemp19 = ((fTemp18 > fRec24[1]) ? fConst65 : fConst69);
			fRec24[0] = fTemp18 * (1.0f - fTemp19) + fRec24[1] * fTemp19;
			float fTemp20 = fConst4 * fRec27[1];
			float fTemp21 = fConst11 * fRec28[1];
			fRec30[0] = -(fConst57 * (fConst55 * fRec30[1] - fConst76 * (fTemp4 - fVec4[1])));
			fRec29[0] = fRec30[0] - fConst22 * (fConst20 * fRec29[2] + fConst18 * fRec29[1]);
			fRec28[0] = fConst77 * (fRec29[2] + (fRec29[0] - 2.0f * fRec29[1])) - fConst75 * (fConst74 * fRec28[2] + fTemp21);
			fRec27[0] = fRec28[2] + fConst75 * (fTemp21 + fConst74 * fRec28[0]) - fConst71 * (fConst70 * fRec27[2] + fTemp20);
			float fTemp22 = fRec27[2] + fConst71 * (fTemp20 + fConst70 * fRec27[0]);
			fRec32[0] = fConst67 * std::fabs(fTemp22) + fConst65 * fRec32[1];
			int iTemp23 = fRec32[0] > fSlow1;
			iVec10[0] = iTemp23;
			iRec33[0] = std::max<int>(faust_wrap_mul(iConst68, iTemp23 < iVec10[1]), faust_wrap_add(iRec33[1], -1));
			float fTemp24 = std::fabs(std::max<float>(static_cast<float>(iTemp23), static_cast<float>(iRec33[0] > 0)));
			float fTemp25 = ((fTemp24 > fRec31[1]) ? fConst65 : fConst69);
			fRec31[0] = fTemp24 * (1.0f - fTemp25) + fRec31[1] * fTemp25;
			float fTemp26 = fConst4 * fRec34[1];
			float fTemp27 = fConst11 * fRec35[1];
			float fTemp28 = fConst18 * fRec36[1];
			fRec38[0] = -(fConst54 * (fConst52 * fRec38[1] - fConst80 * (fTemp3 - fVec3[1])));
			fRec37[0] = fRec38[0] - fConst29 * (fConst27 * fRec37[2] + fConst25 * fRec37[1]);
			fRec36[0] = fConst81 * (fRec37[2] + (fRec37[0] - 2.0f * fRec37[1])) - fConst79 * (fConst78 * fRec36[2] + fTemp28);
			fRec35[0] = fRec36[2] + fConst79 * (fTemp28 + fConst78 * fRec36[0]) - fConst75 * (fConst74 * fRec35[2] + fTemp27);
			fRec34[0] = fRec35[2] + fConst75 * (fTemp27 + fConst74 * fRec35[0]) - fConst71 * (fConst70 * fRec34[2] + fTemp26);
			float fTemp29 = fRec34[2] + fConst71 * (fTemp26 + fConst70 * fRec34[0]);
			fRec40[0] = fConst67 * std::fabs(fTemp29) + fConst65 * fRec40[1];
			int iTemp30 = fRec40[0] > fSlow1;
			iVec11[0] = iTemp30;
			iRec41[0] = std::max<int>(faust_wrap_mul(iConst68, iTemp30 < iVec11[1]), faust_wrap_add(iRec41[1], -1));
			float fTemp31 = std::fabs(std::max<float>(static_cast<float>(iTemp30), static_cast<float>(iRec41[0] > 0)));
			float fTemp32 = ((fTemp31 > fRec39[1]) ? fConst65 : fConst69);
			fRec39[0] = fTemp31 * (1.0f - fTemp32) + fRec39[1] * fTemp32;
			float fTemp33 = fConst4 * fRec42[1];
			float fTemp34 = fConst11 * fRec43[1];
			float fTemp35 = fConst18 * fRec44[1];
			float fTemp36 = fConst25 * fRec45[1];
			fRec47[0] = -(fConst51 * (fConst49 * fRec47[1] - fConst84 * (fTemp2 - fVec2[1])));
			fRec46[0] = fRec47[0] - fConst36 * (fConst34 * fRec46[2] + fConst32 * fRec46[1]);
			fRec45[0] = fConst85 * (fRec46[2] + (fRec46[0] - 2.0f * fRec46[1])) - fConst83 * (fConst82 * fRec45[2] + fTemp36);
			fRec44[0] = fRec45[2] + fConst83 * (fTemp36 + fConst82 * fRec45[0]) - fConst79 * (fConst78 * fRec44[2] + fTemp35);
			fRec43[0] = fRec44[2] + fConst79 * (fTemp35 + fConst78 * fRec44[0]) - fConst75 * (fConst74 * fRec43[2] + fTemp34);
			fRec42[0] = fRec43[2] + fConst75 * (fTemp34 + fConst74 * fRec43[0]) - fConst71 * (fConst70 * fRec42[2] + fTemp33);
			float fTemp37 = fRec42[2] + fConst71 * (fTemp33 + fConst70 * fRec42[0]);
			fRec49[0] = fConst67 * std::fabs(fTemp37) + fConst65 * fRec49[1];
			int iTemp38 = fRec49[0] > fSlow1;
			iVec12[0] = iTemp38;
			iRec50[0] = std::max<int>(faust_wrap_mul(iConst68, iTemp38 < iVec12[1]), faust_wrap_add(iRec50[1], -1));
			float fTemp39 = std::fabs(std::max<float>(static_cast<float>(iTemp38), static_cast<float>(iRec50[0] > 0)));
			float fTemp40 = ((fTemp39 > fRec48[1]) ? fConst65 : fConst69);
			fRec48[0] = fTemp39 * (1.0f - fTemp40) + fRec48[1] * fTemp40;
			float fTemp41 = fConst4 * fRec51[1];
			float fTemp42 = fConst11 * fRec52[1];
			float fTemp43 = fConst18 * fRec53[1];
			float fTemp44 = fConst25 * fRec54[1];
			float fTemp45 = fConst32 * fRec55[1];
			fRec57[0] = -(fConst48 * (fConst47 * fRec57[1] - fConst40 * (fTemp1 - fVec1[1])));
			fRec56[0] = fRec57[0] - fConst43 * (fConst41 * fRec56[2] + fConst39 * fRec56[1]);
			fRec55[0] = fConst88 * (fRec56[2] + (fRec56[0] - 2.0f * fRec56[1])) - fConst87 * (fConst86 * fRec55[2] + fTemp45);
			fRec54[0] = fRec55[2] + fConst87 * (fTemp45 + fConst86 * fRec55[0]) - fConst83 * (fConst82 * fRec54[2] + fTemp44);
			fRec53[0] = fRec54[2] + fConst83 * (fTemp44 + fConst82 * fRec54[0]) - fConst79 * (fConst78 * fRec53[2] + fTemp43);
			fRec52[0] = fRec53[2] + fConst79 * (fTemp43 + fConst78 * fRec53[0]) - fConst75 * (fConst74 * fRec52[2] + fTemp42);
			fRec51[0] = fRec52[2] + fConst75 * (fTemp42 + fConst74 * fRec52[0]) - fConst71 * (fConst70 * fRec51[2] + fTemp41);
			float fTemp46 = fRec51[2] + fConst71 * (fTemp41 + fConst70 * fRec51[0]);
			fRec59[0] = fConst67 * std::fabs(fTemp46) + fConst65 * fRec59[1];
			int iTemp47 = fRec59[0] > fSlow1;
			iVec13[0] = iTemp47;
			iRec60[0] = std::max<int>(faust_wrap_mul(iConst68, iTemp47 < iVec13[1]), faust_wrap_add(iRec60[1], -1));
			float fTemp48 = std::fabs(std::max<float>(static_cast<float>(iTemp47), static_cast<float>(iRec60[0] > 0)));
			float fTemp49 = ((fTemp48 > fRec58[1]) ? fConst65 : fConst69);
			fRec58[0] = fTemp48 * (1.0f - fTemp49) + fRec58[1] * fTemp49;
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow2 * (fRec58[0] * fTemp46 + fRec48[0] * fTemp37 + fRec39[0] * fTemp29 + fRec31[0] * fTemp22 + fRec24[0] * fTemp16 + fConst8 * (fRec18[0] * fTemp11 + fConst3 * fRec13[0] * fTemp7)));
			fVec0[1] = fVec0[0];
			fRec12[1] = fRec12[0];
			fVec1[1] = fVec1[0];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fVec2[1] = fVec2[0];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fVec3[1] = fVec3[0];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fVec4[1] = fVec4[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fVec5[1] = fVec5[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fVec6[1] = fVec6[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec14[1] = fRec14[0];
			iVec7[1] = iVec7[0];
			iRec15[1] = iRec15[0];
			fRec13[1] = fRec13[0];
			fRec17[1] = fRec17[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec19[1] = fRec19[0];
			iVec8[1] = iVec8[0];
			iRec20[1] = iRec20[0];
			fRec18[1] = fRec18[0];
			fRec23[1] = fRec23[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec25[1] = fRec25[0];
			iVec9[1] = iVec9[0];
			iRec26[1] = iRec26[0];
			fRec24[1] = fRec24[0];
			fRec30[1] = fRec30[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec32[1] = fRec32[0];
			iVec10[1] = iVec10[0];
			iRec33[1] = iRec33[0];
			fRec31[1] = fRec31[0];
			fRec38[1] = fRec38[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec40[1] = fRec40[0];
			iVec11[1] = iVec11[0];
			iRec41[1] = iRec41[0];
			fRec39[1] = fRec39[0];
			fRec47[1] = fRec47[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec49[1] = fRec49[0];
			iVec12[1] = iVec12[0];
			iRec50[1] = iRec50[0];
			fRec48[1] = fRec48[0];
			fRec57[1] = fRec57[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fRec55[2] = fRec55[1];
			fRec55[1] = fRec55[0];
			fRec54[2] = fRec54[1];
			fRec54[1] = fRec54[0];
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
			fRec59[1] = fRec59[0];
			iVec13[1] = iVec13[0];
			iRec60[1] = iRec60[0];
			fRec58[1] = fRec58[0];
		}
	}

};

#endif
