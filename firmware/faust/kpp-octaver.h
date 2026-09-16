/* ------------------------------------------------------------
author: "Oleg Kapitonov"
license: "GPL-3.0-or-later"
name: "KPP Octaver"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn KppOctaver -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __KppOctaver_H__
#define  __KppOctaver_H__

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
#define FAUSTCLASS KppOctaver
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

static float KppOctaver_faustpower2_f(float value) {
	return value * value;
}

class KppOctaver : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	float fVec0[2];
	FAUSTFLOAT fHslider1;
	float fRec2[2];
	FAUSTFLOAT fHslider2;
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
	float fRec7[2];
	float fRec6[3];
	float fConst16;
	float fRec5[3];
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
	float fRec20[2];
	float fConst37;
	float fConst38;
	float fRec19[2];
	float fRec18[3];
	float fRec17[3];
	float fConst39;
	float fConst40;
	float fConst41;
	float fRec16[3];
	float fConst42;
	float fConst43;
	float fConst44;
	float fConst45;
	float fRec15[2];
	float fConst46;
	float fConst47;
	float fRec14[2];
	float fRec13[2];
	float fRec12[2];
	float fRec11[2];
	float fRec10[2];
	float fRec9[2];
	float fRec8[2];
	float fVec1[2];
	float fConst48;
	float fRec4[2];
	float fRec3[3];
	FAUSTFLOAT fHslider3;
	float fRec21[2];
	float fConst49;
	float fConst50;
	float fConst51;
	float fConst52;
	float fConst53;
	float fConst54;
	float fConst55;
	float fConst56;
	float fConst57;
	float fConst58;
	float fConst59;
	float fRec27[2];
	float fVec2[2];
	float fRec26[2];
	float fRec25[3];
	float fVec3[2];
	float fConst60;
	float fConst61;
	float fRec24[2];
	float fRec23[3];
	float fVec4[2];
	float fConst62;
	float fRec22[2];
	float fVec5[2];
	float fRec1[2];
	
 public:
	KppOctaver() {
	}
	
	KppOctaver(const KppOctaver&) = default;
	
	virtual ~KppOctaver() = default;
	
	KppOctaver& operator=(const KppOctaver&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Oleg Kapitonov");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn KppOctaver -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
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
		m->declare("description", "Analog-style octaver: extracts the fundamental, squares it, divides by 2 and 4 and modulates the input for -1 and -2 octave tones");
		m->declare("family", "pitch");
		m->declare("filename", "kpp-octaver.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/peak_eq:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "LicenseRef-STK-4.3");
		m->declare("license", "GPL-3.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "KPP Octaver");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "LicenseRef-STK-4.3");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_octaver/kpp_octaver.dsp");
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
		fConst3 = 1.5707964f / fConst0;
		fConst4 = std::tan(753.98224f / fConst0);
		fConst5 = KppOctaver_faustpower2_f(fConst4);
		fConst6 = 2.0f * (1.0f - 1.0f / fConst5);
		fConst7 = 1.0f / fConst4;
		fConst8 = (fConst7 + -0.618034f) / fConst4 + 1.0f;
		fConst9 = (fConst7 + 0.618034f) / fConst4 + 1.0f;
		fConst10 = 1.0f / fConst9;
		fConst11 = (fConst7 + -1.618034f) / fConst4 + 1.0f;
		fConst12 = (fConst7 + 1.618034f) / fConst4 + 1.0f;
		fConst13 = 1.0f / fConst12;
		fConst14 = 1.0f - fConst7;
		fConst15 = 1.0f / (fConst7 + 1.0f);
		fConst16 = 1.0f / (fConst5 * fConst12);
		fConst17 = std::exp(-(1e+01f / fConst0));
		fConst18 = std::tan(1382.3008f / fConst0);
		fConst19 = 2.0f * (1.0f - 1.0f / KppOctaver_faustpower2_f(fConst18));
		fConst20 = fConst0 * std::sin(2764.6016f / fConst0);
		fConst21 = 628.31854f / fConst20;
		fConst22 = 1.0f / fConst18;
		fConst23 = (fConst22 - fConst21) / fConst18 + 1.0f;
		fConst24 = 1.0f / ((fConst22 + fConst21) / fConst18 + 1.0f);
		fConst25 = std::tan(314.15927f / fConst0);
		fConst26 = 2.0f * (1.0f - 1.0f / KppOctaver_faustpower2_f(fConst25));
		fConst27 = fConst0 * std::sin(628.31854f / fConst0);
		fConst28 = 251.32741f / fConst27;
		fConst29 = 1.0f / fConst25;
		fConst30 = (fConst29 - fConst28) / fConst25 + 1.0f;
		fConst31 = 1.0f / ((fConst29 + fConst28) / fConst25 + 1.0f);
		fConst32 = std::tan(251.32741f / fConst0);
		fConst33 = 2.0f * (1.0f - 1.0f / KppOctaver_faustpower2_f(fConst32));
		fConst34 = 1.0f / fConst32;
		fConst35 = (fConst34 + -1.0f) / fConst32 + 1.0f;
		fConst36 = 1.0f / ((fConst34 + 1.0f) / fConst32 + 1.0f);
		fConst37 = 1.0f - fConst34;
		fConst38 = 1.0f / (fConst34 + 1.0f);
		fConst39 = 7947.6704f / fConst27;
		fConst40 = (fConst29 - fConst39) / fConst25 + 1.0f;
		fConst41 = (fConst29 + fConst39) / fConst25 + 1.0f;
		fConst42 = 6283.1855f / fConst20;
		fConst43 = (fConst22 - fConst42) / fConst18 + 1.0f;
		fConst44 = (fConst22 + fConst42) / fConst18 + 1.0f;
		fConst45 = 1.0f - fConst17;
		fConst46 = std::exp(-(2e+01f / fConst0));
		fConst47 = 0.99f * (1.0f - fConst46);
		fConst48 = 1.0f / (fConst5 * fConst9);
		fConst49 = std::tan(125.663704f / fConst0);
		fConst50 = KppOctaver_faustpower2_f(fConst49);
		fConst51 = 2.0f * (1.0f - 1.0f / fConst50);
		fConst52 = 1.0f / fConst49;
		fConst53 = (fConst52 + -1.0f) / fConst49 + 1.0f;
		fConst54 = (fConst52 + 1.0f) / fConst49 + 1.0f;
		fConst55 = 1.0f / fConst54;
		fConst56 = 3.1415927f / fConst0;
		fConst57 = 1.0f / std::tan(816.8141f / fConst0);
		fConst58 = 1.0f - fConst57;
		fConst59 = 1.0f / (fConst57 + 1.0f);
		fConst60 = 1.0f - fConst52;
		fConst61 = 1.0f / (fConst52 + 1.0f);
		fConst62 = 1.0f / (fConst32 * fConst50 * fConst54);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(3e+01f);
		fHslider1 = static_cast<FAUSTFLOAT>(1e+01f);
		fHslider2 = static_cast<FAUSTFLOAT>(1.6e+02f);
		fHslider3 = static_cast<FAUSTFLOAT>(2e+01f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec7[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec6[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec20[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec19[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec18[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec17[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec16[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec15[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec14[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec13[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec12[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec11[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec10[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec9[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec8[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fVec1[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec4[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 3; l21 = faust_wrap_add(l21, 1)) {
			fRec3[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec21[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec27[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fVec2[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec26[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 3; l26 = faust_wrap_add(l26, 1)) {
			fRec25[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fVec3[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec24[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 3; l29 = faust_wrap_add(l29, 1)) {
			fRec23[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fVec4[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec22[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fVec5[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec1[l33] = 0.0f;
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
	
	virtual KppOctaver* clone() {
		return new KppOctaver(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("KPP Octaver");
		ui_interface->declare(&fHslider3, "0", "");
		ui_interface->addHorizontalSlider("Octave 1", &fHslider3, FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Octave 2", &fHslider1, FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->addHorizontalSlider("Dry", &fHslider0, FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "3", "");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("Cutoff", &fHslider2, FAUSTFLOAT(1.6e+02f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(2e+02f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = static_cast<float>(fHslider2);
		float fSlow3 = std::tan(fConst3 * fSlow2);
		float fSlow4 = 2.0f * (1.0f - 1.0f / KppOctaver_faustpower2_f(fSlow3));
		float fSlow5 = 1.0f / fSlow3;
		float fSlow6 = (fSlow5 + -1.0f) / fSlow3 + 1.0f;
		float fSlow7 = 1.0f / ((fSlow5 + 1.0f) / fSlow3 + 1.0f);
		float fSlow8 = 1.0f - fSlow5;
		float fSlow9 = 1.0f / (fSlow5 + 1.0f);
		float fSlow10 = fConst1 * static_cast<float>(fHslider3);
		float fSlow11 = std::tan(fConst56 * fSlow2);
		float fSlow12 = 2.0f * (1.0f - 1.0f / KppOctaver_faustpower2_f(fSlow11));
		float fSlow13 = 1.0f / fSlow11;
		float fSlow14 = (fSlow13 + -1.0f) / fSlow11 + 1.0f;
		float fSlow15 = 1.0f / ((fSlow13 + 1.0f) / fSlow11 + 1.0f);
		float fSlow16 = 1.0f - fSlow13;
		float fSlow17 = 1.0f / (fSlow13 + 1.0f);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp0;
			fRec2[0] = fSlow1 + fConst2 * fRec2[1];
			float fTemp1 = fTemp0 - fVec0[1];
			fRec7[0] = -(fConst15 * (fConst14 * fRec7[1] - fConst7 * fTemp1));
			fRec6[0] = fRec7[0] - fConst13 * (fConst11 * fRec6[2] + fConst6 * fRec6[1]);
			fRec5[0] = fConst16 * (fRec6[2] + (fRec6[0] - 2.0f * fRec6[1])) - fConst10 * (fConst8 * fRec5[2] + fConst6 * fRec5[1]);
			float fTemp2 = fConst19 * fRec16[1];
			float fTemp3 = fConst26 * fRec17[1];
			fRec20[0] = fTemp0 + 0.995f * fRec20[1] - fVec0[1];
			fRec19[0] = -(fConst38 * (fConst37 * fRec19[1] - (fRec20[0] + fRec20[1])));
			fRec18[0] = fRec19[0] - fConst36 * (fConst35 * fRec18[2] + fConst33 * fRec18[1]);
			fRec17[0] = fConst36 * (fRec18[2] + fRec18[0] + 2.0f * fRec18[1]) - fConst31 * (fConst30 * fRec17[2] + fTemp3);
			fRec16[0] = fConst31 * (fTemp3 + fConst41 * fRec17[0] + fConst40 * fRec17[2]) - fConst24 * (fConst23 * fRec16[2] + fTemp2);
			float fTemp4 = fRec13[1] + fConst24 * (fTemp2 + fConst44 * fRec16[0] + fConst43 * fRec16[2]);
			fRec15[0] = fConst45 * std::fabs(fTemp4) + fConst17 * fRec15[1];
			fRec14[0] = fConst46 * fRec14[1] - fConst47 * std::max<float>(2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec15[0])) + 8e+01f, 0.0f);
			float fTemp5 = fTemp4 * std::pow(1e+01f, 0.05f * fRec14[0]);
			fRec13[0] = std::min<float>(1e-07f, std::max<float>(-1e-07f, static_cast<float>((fTemp5 > 0.0f) - (fTemp5 < 0.0f))));
			float fTemp6 = std::max<float>(0.0f, fRec13[0] - fRec13[1]);
			fRec12[0] = std::min<float>(1.0f, std::max<float>(-1.0f, 1e+04f * (fRec12[1] * (1.0f - 2.0f * static_cast<float>((fTemp6 > 0.0f) - (fTemp6 < 0.0f))) + 0.1f)));
			float fTemp7 = std::min<float>(1.0f, std::max<float>(0.0f, fRec12[0]));
			float fTemp8 = fTemp7 + fRec9[1] + -0.5f;
			fRec11[0] = fConst45 * std::fabs(fTemp8) + fConst17 * fRec11[1];
			fRec10[0] = fConst46 * fRec10[1] - fConst47 * std::max<float>(2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec11[0])) + 8e+01f, 0.0f);
			float fTemp9 = fTemp8 * std::pow(1e+01f, 0.05f * fRec10[0]);
			fRec9[0] = std::min<float>(1e-07f, std::max<float>(-1e-07f, static_cast<float>((fTemp9 > 0.0f) - (fTemp9 < 0.0f))));
			float fTemp10 = std::max<float>(0.0f, fRec9[0] - fRec9[1]);
			fRec8[0] = std::min<float>(1.0f, std::max<float>(-1.0f, 1e+04f * (fRec8[1] * (1.0f - 2.0f * static_cast<float>((fTemp10 > 0.0f) - (fTemp10 < 0.0f))) + 0.1f)));
			float fTemp11 = std::min<float>(1.0f, std::max<float>(0.0f, fRec8[0])) * (fRec5[2] + (fRec5[0] - 2.0f * fRec5[1]));
			fVec1[0] = fTemp11;
			fRec4[0] = -(fSlow9 * (fSlow8 * fRec4[1] - fConst48 * (fTemp11 + fVec1[1])));
			fRec3[0] = fRec4[0] - fSlow7 * (fSlow6 * fRec3[2] + fSlow4 * fRec3[1]);
			fRec21[0] = fSlow10 + fConst2 * fRec21[1];
			fRec27[0] = -(fConst59 * (fConst58 * fRec27[1] - fConst57 * fTemp1));
			float fTemp12 = fRec27[0] * fTemp7;
			fVec2[0] = fTemp12;
			fRec26[0] = -(fSlow17 * (fSlow16 * fRec26[1] - (fTemp12 + fVec2[1])));
			fRec25[0] = fRec26[0] - fSlow15 * (fSlow14 * fRec25[2] + fSlow12 * fRec25[1]);
			float fTemp13 = fSlow15 * (fRec25[2] + fRec25[0] + 2.0f * fRec25[1]);
			fVec3[0] = fTemp13;
			fRec24[0] = -(fConst61 * (fConst60 * fRec24[1] - fConst52 * (fTemp13 - fVec3[1])));
			fRec23[0] = fRec24[0] - fConst55 * (fConst53 * fRec23[2] + fConst51 * fRec23[1]);
			float fTemp14 = fRec23[2] + (fRec23[0] - 2.0f * fRec23[1]);
			fVec4[0] = fTemp14;
			fRec22[0] = -(fConst38 * (fConst37 * fRec22[1] - fConst62 * (fTemp14 - fVec4[1])));
			float fTemp15 = fRec22[0] * std::pow(1e+01f, 0.05f * (fRec21[0] + -2e+01f)) + fSlow7 * (fRec3[2] + fRec3[0] + 2.0f * fRec3[1]) * std::pow(1e+01f, 0.05f * (fRec2[0] + -2e+01f));
			fVec5[0] = fTemp15;
			fRec1[0] = 0.995f * fRec1[1] + 2.0f * (fTemp15 - fVec5[1]);
			output0[i0] = static_cast<FAUSTFLOAT>(fRec1[0] + fTemp0 * std::pow(1e+01f, 0.05f * (fRec0[0] + -3e+01f)));
			fRec0[1] = fRec0[0];
			fVec0[1] = fVec0[0];
			fRec2[1] = fRec2[0];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fVec1[1] = fVec1[0];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec21[1] = fRec21[0];
			fRec27[1] = fRec27[0];
			fVec2[1] = fVec2[0];
			fRec26[1] = fRec26[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fVec3[1] = fVec3[0];
			fRec24[1] = fRec24[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fVec4[1] = fVec4[0];
			fRec22[1] = fRec22[0];
			fVec5[1] = fVec5[0];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
