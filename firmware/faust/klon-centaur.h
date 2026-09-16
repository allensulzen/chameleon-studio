/* ------------------------------------------------------------
author: "Chameleon DSP (wrapper) / Jatin Chowdhury (model)"
license: "BSD-3-Clause"
name: "KlonCentaur"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn KlonCentaur -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __KlonCentaur_H__
#define  __KlonCentaur_H__

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
#define FAUSTCLASS KlonCentaur
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

static float KlonCentaur_faustpower2_f(float value) {
	return value * value;
}

class KlonCentaur : public chdsp {
	
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
	FAUSTFLOAT fHslider0;
	float fRec4[2];
	float fVec0[2];
	float fConst8;
	float fRec2[2];
	float fRec3[2];
	float fConst9;
	FAUSTFLOAT fHslider1;
	float fRec8[2];
	float fVec1[2];
	float fRec6[2];
	float fRec7[2];
	float fConst10;
	float fConst11;
	float fConst12;
	int iRec10[2];
	FAUSTFLOAT fHslider2;
	float fRec25[2];
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
	float fVec2[2];
	float fConst36;
	float fConst37;
	float fRec26[2];
	float fConst38;
	float fRec11[2];
	float fConst39;
	float fConst40;
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec12[2];
	int iRec13[2];
	int iRec14[2];
	float fConst44;
	float fConst45;
	float fConst46;
	float fRec16[2];
	int iRec17[2];
	int iRec18[2];
	int iRec19[2];
	int iRec20[2];
	float fRec21[2];
	int iRec22[2];
	int iRec23[2];
	float fRec24[2];
	float fConst47;
	float fConst48;
	float fConst49;
	float fConst50;
	float fConst51;
	float fConst52;
	float fConst53;
	float fConst54;
	float fConst55;
	float fConst56;
	float fConst57;
	float fRec27[2];
	float fConst58;
	float fRec28[2];
	int iRec29[2];
	float fConst59;
	float fRec31[2];
	int iRec33[2];
	float fConst60;
	float fConst61;
	float fConst62;
	float fRec35[2];
	int iRec36[2];
	float fVec3[2];
	float fRec43[2];
	float fRec44[2];
	float fConst63;
	float fRec45[3];
	float fRec37[2];
	float fConst64;
	float fConst65;
	float fConst66;
	float fConst67;
	float fConst68;
	float fConst69;
	float fConst70;
	float fConst71;
	float fConst72;
	float fConst73;
	float fConst74;
	float fConst75;
	float fConst76;
	float fRec38[2];
	int iRec39[2];
	float fVec4[2];
	float fRec40[2];
	float fConst77;
	float fRec42[2];
	float fVec5[2];
	float fConst78;
	float fRec9[2];
	float fVec6[2];
	float fRec5[2];
	float fVec7[2];
	float fRec1[2];
	float fRec0[3];
	float fConst79;
	
 public:
	KlonCentaur() {
	}
	
	KlonCentaur(const KlonCentaur&) = default;
	
	virtual ~KlonCentaur() = default;
	
	KlonCentaur& operator=(const KlonCentaur&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP (wrapper) / Jatin Chowdhury (model)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn KlonCentaur -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Klon Centaur overdrive: full wave-digital-filter circuit model (ve.klonCentaur, port of ChowCentaur)");
		m->declare("filename", "klon-centaur.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("interpolators.lib/name", "Faust Interpolator Library");
		m->declare("interpolators.lib/remap:author", "David Braun");
		m->declare("interpolators.lib/version", "1.6.0");
		m->declare("license", "BSD-3-Clause");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "KlonCentaur");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("vaeffects.lib/klonCentaur:author", "David Braun");
		m->declare("vaeffects.lib/klonCentaur:copyright", "Chowdhury-DSP");
		m->declare("vaeffects.lib/klonCentaur:license", "BSD-3-Clause");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/version", "1.6.0");
		m->declare("wdmodels.lib/builddown:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/builddown:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/builddown:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/buildout:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/buildout:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/buildout:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/buildtree:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/buildtree:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/buildtree:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/capacitor:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/capacitor:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/capacitor:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/capacitor_Iout:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/getres:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/getres:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/getres:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/name", "Faust Wave Digital Model Library");
		m->declare("wdmodels.lib/omega:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/parallel:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/parallel:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/parallel:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/parres:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/parres:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/parres:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/resVoltage:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/resVoltage:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/resVoltage:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/resVoltage_Vout:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/resVoltage_Vout:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/resVoltage_Vout:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/resistor:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/resistor:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/resistor:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/resistor_Iout:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/resistor_Iout:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/resistor_Iout:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/resistor_Vout:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/resistor_Vout:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/resistor_Vout:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/series:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/series:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/series:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/u_diodeAntiparallel_omega:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/u_voltage:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/u_voltage:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/u_voltage:license", "LicenseRef-STK-4.3");
		m->declare("wdmodels.lib/version", "1.4.0");
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
		fConst1 = std::tan(109.95574f / fConst0);
		fConst2 = 2.0f * (KlonCentaur_faustpower2_f(fConst1) + -1.0f);
		fConst3 = fConst1 * (fConst1 + -1.4142135f) + 1.0f;
		fConst4 = fConst1 * (fConst1 + 1.4142135f) + 1.0f;
		fConst5 = 1.0f / fConst4;
		fConst6 = 44.1f / fConst0;
		fConst7 = 1.0f - fConst6;
		fConst8 = 0.05f * fConst0;
		fConst9 = 9.4e-06f * fConst0;
		fConst10 = 1e-05f / std::tan(1282.0513f / fConst0);
		fConst11 = 0.00064288f * fConst0;
		fConst12 = 1.0f - fConst11;
		fConst13 = 2.2727272e+08f / fConst0;
		fConst14 = fConst13 + 6.9e+04f;
		fConst15 = 18518518.0f / fConst0;
		fConst16 = fConst15 + 1.2e+04f;
		fConst17 = 1.0f / fConst16;
		fConst18 = fConst17 + 1.0f / fConst14;
		fConst19 = 1282051.2f / fConst0;
		fConst20 = fConst19 + 1e+03f;
		fConst21 = 1.0f / fConst20;
		fConst22 = 1.36e-07f * fConst0;
		fConst23 = 1.0f / (fConst22 + 0.00019607843f);
		fConst24 = 1.0f / (fConst18 + 3.7037036e-05f);
		fConst25 = fConst15 + 3.9e+04f;
		fConst26 = fConst14 / fConst25;
		fConst27 = fConst17 + 3.7037036e-05f;
		fConst28 = 1.0f / fConst27;
		fConst29 = fConst28 + fConst13 + 6.9e+04f;
		fConst30 = 1.0f / fConst29;
		fConst31 = 7352941.0f / fConst0;
		fConst32 = fConst31 + 5.1e+03f;
		fConst33 = 1.0f / fConst32;
		fConst34 = 0.202f * fConst0;
		fConst35 = 1.0f - fConst34;
		fConst36 = 0.2f * fConst0;
		fConst37 = 1.0f / (fConst34 + 1.0f);
		fConst38 = 7352941.0f / (fConst0 * fConst32);
		fConst39 = fConst13 + 2.2e+04f;
		fConst40 = 1.0f / fConst25;
		fConst41 = fConst14 / fConst29;
		fConst42 = 2.2727272e+08f / (fConst0 * fConst14);
		fConst43 = 1.0f / fConst39;
		fConst44 = 1.0638298e-05f / fConst14;
		fConst45 = fConst16 / fConst25;
		fConst46 = 1.0f / (fConst27 * fConst29);
		fConst47 = 1.0f / (fConst22 + 0.0001f);
		fConst48 = 1.0f / (2e-06f * fConst0 + 6.666667e-05f);
		fConst49 = fConst48 + 1.5e+03f;
		fConst50 = 1.0f / fConst49;
		fConst51 = 5e+06f / fConst0;
		fConst52 = fConst48 + fConst47;
		fConst53 = 5e+05f / fConst0;
		fConst54 = fConst53 + 1.5e+04f;
		fConst55 = 1.0f / fConst54;
		fConst56 = fConst31 + 1e+04f;
		fConst57 = 1.0f / fConst56;
		fConst58 = 7352941.0f / (fConst0 * fConst56);
		fConst59 = 1e+04f / fConst56;
		fConst60 = 1.5e+04f / fConst54;
		fConst61 = 1.5e+03f / fConst54;
		fConst62 = 5e+05f / (fConst0 * fConst54);
		fConst63 = 0.5f / fConst0;
		fConst64 = fConst53 + 1.0f;
		fConst65 = fConst53 + 1001.0f;
		fConst66 = fConst53 + 4.7e+04f;
		fConst67 = 1e+06f / fConst0 + 48001.0f;
		fConst68 = 1.0f / fConst67;
		fConst69 = 38.68472f / fConst67;
		fConst70 = 1.0f / fConst66;
		fConst71 = 1.0f / fConst65;
		fConst72 = fConst71 + fConst70;
		fConst73 = 9.748549e-08f / fConst72;
		fConst74 = fConst73 + std::log(std::max<float>(fConst73, 1e-18f));
		fConst75 = 2.52e-09f / fConst72;
		fConst76 = 1.0f / fConst64;
		fConst77 = 1e-06f * (fConst0 / fConst66);
		fConst78 = 1.0f / (fConst11 + 1.0f);
		fConst79 = 0.262f / fConst4;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.7f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.55f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec4[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec8[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec7[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			iRec10[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec25[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec26[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			iRec13[l14] = 0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			iRec14[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec16[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			iRec17[l17] = 0;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			iRec18[l18] = 0;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			iRec19[l19] = 0;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			iRec20[l20] = 0;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec21[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			iRec22[l22] = 0;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			iRec23[l23] = 0;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec24[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec27[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec28[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			iRec29[l27] = 0;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec31[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			iRec33[l29] = 0;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec35[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			iRec36[l31] = 0;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fVec3[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec43[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec44[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 3; l35 = faust_wrap_add(l35, 1)) {
			fRec45[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec37[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec38[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			iRec39[l38] = 0;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fVec4[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec40[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec42[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			fVec5[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec9[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fVec6[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec5[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fVec7[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fRec1[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 3; l48 = faust_wrap_add(l48, 1)) {
			fRec0[l48] = 0.0f;
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
	
	virtual KlonCentaur* clone() {
		return new KlonCentaur(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("KlonCentaur");
		ui_interface->addHorizontalSlider("Gain", &fHslider2, FAUSTFLOAT(0.55f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Level", &fHslider0, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Treble", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst6 * static_cast<float>(fHslider0);
		float fSlow1 = fConst6 * static_cast<float>(fHslider1);
		float fSlow2 = fConst6 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec4[0] = fSlow0 + fConst7 * fRec4[1];
			float fTemp0 = std::log(std::max<float>(std::max<float>(1e-05f, std::min<float>(1.0f, fRec4[0])), 1e-05f));
			fVec0[0] = fTemp0;
			float fTemp1 = ((fTemp0 != fVec0[1]) ? fConst8 : fRec2[1] + -1.0f);
			fRec2[0] = fTemp1;
			fRec3[0] = ((fTemp1 > 0.0f) ? fRec3[1] + (fTemp0 - fRec3[1]) / fTemp1 : fTemp0);
			float fTemp2 = std::exp(fRec3[0]);
			float fTemp3 = fConst9 * (1e+04f * (fTemp2 + (1.0f - fTemp2)) + 561.0f);
			fRec8[0] = fSlow1 + fConst7 * fRec8[1];
			float fTemp4 = std::max<float>(0.0f, std::min<float>(1.0f, fRec8[0]));
			fVec1[0] = fTemp4;
			float fTemp5 = ((fTemp4 != fVec1[1]) ? fConst8 : fRec6[1] + -1.0f);
			fRec6[0] = fTemp5;
			fRec7[0] = ((fTemp5 > 0.0f) ? fRec7[1] + (fTemp4 - fRec7[1]) / fTemp5 : fTemp4);
			float fTemp6 = 1.0f / (1e+04f * (1.0f - fRec7[0]) + 1.8e+03f);
			float fTemp7 = 1.0f / (1e+04f * fRec7[0] + 4.7e+03f);
			float fTemp8 = 1e-05f * (fTemp7 + fTemp6);
			float fTemp9 = fConst10 * (fTemp7 + -1e-05f);
			float fTemp10 = fConst10 * (fTemp6 + 1e-05f);
			iRec10[0] = 0;
			fRec25[0] = fSlow2 + fConst7 * fRec25[1];
			float fTemp11 = std::max<float>(0.0f, std::min<float>(1.0f, fRec25[0]));
			float fTemp12 = 1e+05f * fTemp11;
			float fTemp13 = std::max<float>(fTemp12, 1.0f);
			float fTemp14 = std::max<float>(1e+05f * (1.0f - fTemp11), 1.0f);
			float fTemp15 = fConst18 + 1.0f / fTemp14 + 3.7037036e-05f;
			float fTemp16 = 1.0f / fTemp15 + fTemp13;
			float fTemp17 = 1.0f / fTemp16;
			float fTemp18 = fConst21 + fTemp17 + 0.00066666666f;
			float fTemp19 = 1.0f / fTemp18 + 1e-09f;
			float fTemp20 = fConst23 + fTemp19;
			float fTemp21 = fConst21 + fTemp17;
			float fTemp22 = 1.0f / fTemp21 + 1.5e+03f;
			float fTemp23 = fConst19 + fTemp16 + 1e+03f;
			float fTemp24 = static_cast<float>(iRec22[1]);
			float fTemp25 = fRec21[1] + fTemp24;
			float fTemp26 = static_cast<float>(iRec20[1]);
			float fTemp27 = fConst24 + fTemp14;
			float fTemp28 = static_cast<float>(iRec19[1]);
			float fTemp29 = static_cast<float>(iRec17[1]);
			float fTemp30 = fRec16[1] + fTemp29;
			float fTemp31 = static_cast<float>(iRec18[1]);
			float fTemp32 = fConst16 * fTemp31 - 2.7e+04f * fTemp30;
			float fTemp33 = static_cast<float>(iRec14[1]);
			float fTemp34 = static_cast<float>(iRec13[1]);
			float fTemp35 = fRec12[1] + fTemp34;
			float fTemp36 = fTemp35 - fTemp33;
			float fTemp37 = fConst28 * fTemp36 + fConst26 * fTemp32;
			float fTemp38 = fConst30 * fTemp37 * fTemp14 + fConst24 * fTemp28;
			float fTemp39 = fTemp38 / fTemp27 + fTemp26;
			float fTemp40 = (fConst20 * fTemp39 + fTemp16 * fTemp25) / fTemp23;
			float fTemp41 = static_cast<float>(iRec23[1]);
			float fTemp42 = (fTemp41 / fTemp21 - 1.5e+03f * fTemp40) / fTemp22;
			float fTemp43 = fConst23 * (fTemp42 + fRec24[1]);
			float fTemp44 = static_cast<float>(iRec10[1]);
			float fTemp45 = fConst31 * fTemp44 + 5.1e+03f * fRec11[1];
			float fTemp46 = static_cast<float>(input0[i0]);
			fVec2[0] = fTemp46;
			fRec26[0] = fConst37 * (fConst36 * (fTemp46 - fVec2[1]) - fConst35 * fRec26[1]);
			float fTemp47 = 2.0f * std::max<float>(-4.5f, std::min<float>(4.5f, fRec26[0]));
			float fTemp48 = fConst33 * fTemp45;
			float fTemp49 = fTemp48 - (fRec24[1] + fTemp47 + fTemp42);
			fRec11[0] = fConst38 * (fTemp44 - fRec11[1]) - (fConst23 * fTemp49 - fConst33 * fTemp45 * fTemp19 - fTemp43) / fTemp20;
			float fTemp50 = fConst39 * fTemp33;
			float fTemp51 = ((fTemp43 + fTemp19 * (fTemp48 + fTemp49)) / (fTemp18 * fTemp20) + 1e-09f * fTemp42 - fRec24[1] / fTemp18) / fTemp19 + (fTemp40 + fTemp41) / (fTemp21 * fTemp22);
			float fTemp52 = ((fTemp51 - fTemp16 * (fTemp25 - fTemp39) / fTemp23) / fTemp15 - fTemp38 * fTemp13 / fTemp27 + fTemp26 / fTemp15) / fTemp16;
			float fTemp53 = fConst40 * fTemp32;
			float fTemp54 = fConst24 * ((fTemp28 - fConst30 * fTemp37) / fTemp27);
			float fTemp55 = fTemp54 + fConst41 * (fTemp53 - fTemp36);
			fRec12[0] = fConst43 * (fConst42 * (fConst39 * (fTemp55 - fTemp52) + 4.7e+04f * fTemp35 + fTemp50) + 2.2e+04f * fRec12[1] - fConst13 * fTemp34);
			iRec13[0] = 0;
			iRec14[0] = 0;
			float fRec15 = fConst44 * (fTemp50 + 4.7e+04f * (fTemp35 + (fTemp52 - fTemp55)));
			fRec16[0] = fConst17 * (1.2e+04f * fRec16[1] - fConst15 * (fTemp54 + fConst46 * (fTemp36 - fTemp53) + fConst45 * (fTemp30 + fTemp31) - fTemp52) - fConst15 * fTemp29);
			iRec17[0] = 0;
			iRec18[0] = 0;
			iRec19[0] = 0;
			iRec20[0] = 0;
			fRec21[0] = fConst21 * (1e+03f * fRec21[1] - fConst19 * (fTemp51 - fConst20 * ((fTemp39 - fTemp25) / fTemp23)) - fConst19 * fTemp24);
			iRec22[0] = 0;
			iRec23[0] = 0;
			fRec24[0] = 0.0f;
			float fTemp56 = std::max<float>(fTemp12, 1e-09f);
			float fTemp57 = fConst47 + fTemp56;
			float fTemp58 = fConst50 + 1.0f / fTemp57;
			float fTemp59 = fConst51 + 1.0f / fTemp58;
			float fTemp60 = fConst52 + fTemp56 + 1.5e+03f;
			float fTemp61 = static_cast<float>(iRec36[1]);
			float fTemp62 = static_cast<float>(iRec33[1]);
			float fTemp63 = fConst53 * fTemp62 + 1.5e+04f * fRec35[1];
			float fTemp64 = fConst55 * fTemp63 + fTemp61;
			float fTemp65 = static_cast<float>(iRec29[1]);
			float fTemp66 = 1e+04f * fRec28[1] + fConst31 * fTemp65;
			float fTemp67 = fConst57 * fTemp66;
			float fTemp68 = fTemp67 + fRec31[1];
			float fTemp69 = (fConst49 * fTemp68 + fTemp57 * fTemp64) / fTemp60;
			float fTemp70 = fConst51 * fTemp69;
			float fTemp71 = fRec27[1] - (fTemp69 + fTemp47);
			fRec27[0] = (fRec27[1] / fTemp58 - fConst51 * fTemp71 + fTemp70) / fTemp59;
			float fTemp72 = fConst47 * fRec31[1];
			float fTemp73 = (fTemp70 + (fRec27[1] + fTemp71) / fTemp58) / fTemp59;
			float fTemp74 = fTemp73 + fTemp57 * (fTemp64 - fTemp68) / fTemp60;
			float fTemp75 = (fConst47 * fTemp74 + fConst57 * fTemp66 * fTemp56 - fTemp72) / fTemp57;
			fRec28[0] = fTemp75 + fConst58 * (fTemp65 - fRec28[1]);
			iRec29[0] = 0;
			float fRec30 = 0.5f * (fTemp75 + fConst59 * (fRec28[1] - fTemp65));
			fRec31[0] = 0.0f;
			float fRec32 = 0.5f * ((fTemp72 - fTemp56 * (fTemp67 - fTemp74)) / fTemp57);
			iRec33[0] = 0;
			float fTemp76 = fConst50 * (fConst61 * fTemp63 - fConst48 * (fConst49 * (fTemp64 / fTemp60) - (fConst49 * (fTemp68 / fTemp60) + fTemp73)) - fConst48 * fTemp61);
			float fRec34 = 3.3333334e-05f * (fTemp76 + fConst60 * (fRec35[1] - fTemp62));
			fRec35[0] = fTemp76 + fConst62 * (fTemp62 - fRec35[1]);
			iRec36[0] = 0;
			float fTemp77 = std::log(std::max<float>(1.02e+05f - 1e+05f * std::max<float>(0.0f, std::min<float>(1.0f, fTemp11)), 2e+03f));
			fVec3[0] = fTemp77;
			float fTemp78 = ((fTemp77 != fVec3[1]) ? fConst8 : fRec43[1] + -1.0f);
			fRec43[0] = fTemp78;
			fRec44[0] = ((fTemp78 > 0.0f) ? fRec44[1] + (fTemp77 - fRec44[1]) / fTemp78 : fTemp77);
			float fTemp79 = std::exp(fRec44[0]);
			float fTemp80 = fTemp79 + 1.5e+04f;
			float fTemp81 = 0.00016458f * fTemp80 + 0.00123f * fTemp79;
			float fTemp82 = std::max<float>(2469948.2f * (std::sqrt(-(std::min<float>(0.0f, KlonCentaur_faustpower2_f(fTemp81) - 8.097336e-07f * fTemp79 * fTemp80))) / fTemp79), 1e-10f);
			float fTemp83 = std::tan(fConst63 * fTemp82);
			float fTemp84 = 2.024334e-07f * (fTemp79 * fTemp82 / fTemp83);
			float fTemp85 = fTemp79 + fTemp82 * (fTemp81 + fTemp84) / fTemp83 + 1.5e+04f;
			float fTemp86 = fTemp81 + 519.06f;
			float fTemp87 = fTemp79 * (1.0f - 2.024334e-07f * (KlonCentaur_faustpower2_f(fTemp82) / KlonCentaur_faustpower2_f(fTemp83)));
			fRec45[0] = fRec30 + fRec32 - (fRec45[2] * (fTemp79 + fTemp82 * (fTemp84 - fTemp81) / fTemp83 + 1.5e+04f) + 2.0f * fRec45[1] * (fTemp87 + 1.5e+04f)) / fTemp85;
			fRec37[0] = -(std::max<float>(-4.5f, std::min<float>(4.5f, (fRec45[0] * (fTemp79 + fTemp82 * (fTemp84 + fTemp86) / fTemp83 + 4.37e+05f) + 2.0f * fRec45[1] * (fTemp87 + 4.37e+05f) + fRec45[2] * (fTemp79 + fTemp82 * (fTemp84 - fTemp86) / fTemp83 + 4.37e+05f)) / fTemp85)));
			float fTemp88 = static_cast<float>(iRec39[1]);
			float fTemp89 = fRec37[1] + fRec38[1];
			float fTemp90 = fTemp89 - fTemp88;
			float fTemp91 = fRec40[1] + fRec42[1];
			float fTemp92 = fConst65 * fTemp91;
			float fTemp93 = fConst66 * fTemp90;
			float fTemp94 = fTemp93 - fTemp92;
			float fTemp95 = fConst68 * fTemp94;
			int iTemp96 = (fTemp95 > 0.0f) - (fTemp95 < 0.0f);
			float fTemp97 = fConst69 * fTemp94 * static_cast<float>(iTemp96);
			float fTemp98 = fConst74 + fTemp97;
			float fTemp99 = ((fTemp98 < -3.3414595f) ? 0.0f : ((fTemp98 < 8.0f) ? fTemp98 * (fTemp98 * (0.047759313f - 0.0013142931f * fTemp98) + 0.36319527f) + 0.63131833f : fConst74 + (fTemp97 - std::log(std::max<float>(fTemp98, 1e-10f)))));
			float fTemp100 = static_cast<float>(faust_wrap_mul(2, iTemp96)) * (fConst75 - 0.02585f * (fTemp99 - (fTemp99 - std::exp(fConst74 + (fTemp97 - fTemp99))) / (fTemp99 + 1.0f)));
			fRec38[0] = fConst76 * (fRec38[1] + fConst53 * (fConst71 * (fConst64 * (fTemp100 - fConst68 * (fTemp92 - (fTemp94 - fConst65 * fTemp90))) + 1e+03f * fTemp89 + fConst64 * fTemp88) - fRec37[1]));
			iRec39[0] = 0;
			float fTemp101 = 4.7e+04f * fRec40[1] - fConst53 * (fTemp100 + fConst68 * (fTemp93 + fTemp94 + fConst66 * fTemp91)) - fConst53 * fRec42[1];
			fVec4[0] = fTemp101;
			fRec40[0] = fConst70 * fTemp101;
			float fRec41 = fConst77 * (fTemp101 - fVec4[1]);
			fRec42[0] = 4.5f;
			float fTemp102 = fRec41 + fRec34 + fRec15;
			fVec5[0] = fTemp102;
			fRec9[0] = fConst78 * (3.92e+05f * (fTemp102 + fVec5[1]) - fConst12 * fRec9[1]);
			float fTemp103 = std::max<float>(-13.1f, std::min<float>(11.7f, fRec9[0]));
			fVec6[0] = fTemp103;
			fRec5[0] = (fRec5[1] * (fTemp9 - fTemp8) - (fTemp103 * (fTemp8 + fTemp10) + fVec6[1] * (fTemp8 - fTemp10))) / (fTemp9 + fTemp8);
			float fTemp104 = std::max<float>(-13.1f, std::min<float>(11.7f, -fRec5[0]));
			fVec7[0] = fTemp104;
			fRec1[0] = (fConst9 * (1e+04f * fTemp2 + 1.0f) * (fTemp104 - fVec7[1]) - fRec1[1] * (1.0f - fTemp3)) / (fTemp3 + 1.0f);
			fRec0[0] = fRec1[0] - fConst5 * (fConst3 * fRec0[2] + fConst2 * fRec0[1]);
			output0[i0] = static_cast<FAUSTFLOAT>(fConst79 * (fRec0[2] + (fRec0[0] - 2.0f * fRec0[1])));
			fRec4[1] = fRec4[0];
			fVec0[1] = fVec0[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec8[1] = fRec8[0];
			fVec1[1] = fVec1[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			iRec10[1] = iRec10[0];
			fRec25[1] = fRec25[0];
			fVec2[1] = fVec2[0];
			fRec26[1] = fRec26[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			iRec13[1] = iRec13[0];
			iRec14[1] = iRec14[0];
			fRec16[1] = fRec16[0];
			iRec17[1] = iRec17[0];
			iRec18[1] = iRec18[0];
			iRec19[1] = iRec19[0];
			iRec20[1] = iRec20[0];
			fRec21[1] = fRec21[0];
			iRec22[1] = iRec22[0];
			iRec23[1] = iRec23[0];
			fRec24[1] = fRec24[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			iRec29[1] = iRec29[0];
			fRec31[1] = fRec31[0];
			iRec33[1] = iRec33[0];
			fRec35[1] = fRec35[0];
			iRec36[1] = iRec36[0];
			fVec3[1] = fVec3[0];
			fRec43[1] = fRec43[0];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec37[1] = fRec37[0];
			fRec38[1] = fRec38[0];
			iRec39[1] = iRec39[0];
			fVec4[1] = fVec4[0];
			fRec40[1] = fRec40[0];
			fRec42[1] = fRec42[0];
			fVec5[1] = fVec5[0];
			fRec9[1] = fRec9[0];
			fVec6[1] = fVec6[0];
			fRec5[1] = fRec5[0];
			fVec7[1] = fVec7[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
