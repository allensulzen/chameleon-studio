/* ------------------------------------------------------------
author: "Bart Brouns (based on blushcomp by Sampo Savolainen)"
license: "GPL-2.0"
name: "Character Compressor"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn MagCharacterCompressor -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __MagCharacterCompressor_H__
#define  __MagCharacterCompressor_H__

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
#define FAUSTCLASS MagCharacterCompressor
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

static float MagCharacterCompressor_faustpower2_f(float value) {
	return value * value;
}
static float MagCharacterCompressor_faustpower3_f(float value) {
	return value * value * value;
}

class MagCharacterCompressor : public chdsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fConst2;
	FAUSTFLOAT fHslider5;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider6;
	float fRec6[2];
	FAUSTFLOAT fHslider7;
	float fVec0[3];
	float fRec5[3];
	float fVec1[2];
	float fVec2[3];
	float fVec3[5];
	float fVec4[12];
	int IOTA0;
	float fVec5[32];
	float fVec6[64];
	float fVec7[128];
	float fVec8[256];
	float fVec9[512];
	float fVec10[1024];
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
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	float fConst15;
	FAUSTFLOAT fHslider11;
	float fConst16;
	float fRec4[2];
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	float fVec11[3];
	FAUSTFLOAT fHslider16;
	float fVec12[2];
	float fVec13[3];
	float fVec14[5];
	float fVec15[12];
	float fVec16[32];
	float fVec17[64];
	float fVec18[128];
	float fVec19[256];
	float fVec20[512];
	float fVec21[1024];
	FAUSTFLOAT fHslider17;
	float fConst17;
	FAUSTFLOAT fHslider18;
	float fRec2[2];
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	float fConst18;
	float fVec22[2];
	float fRec8[2];
	float fRec7[3];
	float fRec10[2];
	float fRec9[3];
	float fRec1[2];
	
 public:
	MagCharacterCompressor() {
	}
	
	MagCharacterCompressor(const MagCharacterCompressor&) = default;
	
	virtual ~MagCharacterCompressor() = default;
	
	MagCharacterCompressor& operator=(const MagCharacterCompressor&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Bart Brouns (based on blushcomp by Sampo Savolainen)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn MagCharacterCompressor -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Bart Brouns' blushcomp-derived colour compressor (after Sampo Savolainen): peak/RMS detector, power/curve/shape gain-law, rate-limited GR, gain-vs-high-shelf output");
		m->declare("family", "dynamics");
		m->declare("filename", "mag-character-compressor.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/highshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:license", "LicenseRef-STK-4.3");
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
		m->declare("license", "GPL-2.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Character Compressor");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "magnetophon/CharacterCompressor CharacterCompressorMono.dsp + lib/*.lib");
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
		fConst1 = 1.0f / fConst0;
		fConst2 = 86.13281f / fConst0;
		fConst3 = 6.2831855f / fConst0;
		fConst4 = 6.532758f / fConst0;
		fConst5 = 172.26562f / fConst0;
		fConst6 = 344.53125f / fConst0;
		fConst7 = 689.0625f / fConst0;
		fConst8 = 1378.125f / fConst0;
		fConst9 = 2756.25f / fConst0;
		fConst10 = 5512.5f / fConst0;
		fConst11 = 11025.0f / fConst0;
		fConst12 = 2.205e+04f / fConst0;
		fConst13 = 4.41e+04f / fConst0;
		fConst14 = 2.2675737e-05f * fConst0;
		fConst15 = 339.78522f / fConst0;
		fConst16 = 1812.1879f / fConst0;
		fConst17 = 2.2675736e-07f * fConst0;
		fConst18 = 3.1415927f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(-15.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(3813.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(1.02e+03f);
		fHslider4 = static_cast<FAUSTFLOAT>(96.0f);
		fHslider5 = static_cast<FAUSTFLOAT>(154.0f);
		fHslider6 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider7 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider8 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider9 = static_cast<FAUSTFLOAT>(-27.1f);
		fHslider10 = static_cast<FAUSTFLOAT>(23.7f);
		fHslider11 = static_cast<FAUSTFLOAT>(0.1f);
		fHslider12 = static_cast<FAUSTFLOAT>(2e+01f);
		fHslider13 = static_cast<FAUSTFLOAT>(1.881f);
		fHslider14 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider15 = static_cast<FAUSTFLOAT>(94.0f);
		fHslider16 = static_cast<FAUSTFLOAT>(108.0f);
		fHslider17 = static_cast<FAUSTFLOAT>(2e+04f);
		fHslider18 = static_cast<FAUSTFLOAT>(5e+01f);
		fHslider19 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider20 = static_cast<FAUSTFLOAT>(0.811f);
		fHslider21 = static_cast<FAUSTFLOAT>(134.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec6[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fVec0[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fVec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 5; l7 = faust_wrap_add(l7, 1)) {
			fVec3[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 12; l8 = faust_wrap_add(l8, 1)) {
			fVec4[l8] = 0.0f;
		}
		IOTA0 = 0;
		for (int l9 = 0; l9 < 32; l9 = faust_wrap_add(l9, 1)) {
			fVec5[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 64; l10 = faust_wrap_add(l10, 1)) {
			fVec6[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 128; l11 = faust_wrap_add(l11, 1)) {
			fVec7[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 256; l12 = faust_wrap_add(l12, 1)) {
			fVec8[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 512; l13 = faust_wrap_add(l13, 1)) {
			fVec9[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 1024; l14 = faust_wrap_add(l14, 1)) {
			fVec10[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec4[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 3; l16 = faust_wrap_add(l16, 1)) {
			fVec11[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fVec12[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 3; l18 = faust_wrap_add(l18, 1)) {
			fVec13[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 5; l19 = faust_wrap_add(l19, 1)) {
			fVec14[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 12; l20 = faust_wrap_add(l20, 1)) {
			fVec15[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 32; l21 = faust_wrap_add(l21, 1)) {
			fVec16[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 64; l22 = faust_wrap_add(l22, 1)) {
			fVec17[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 128; l23 = faust_wrap_add(l23, 1)) {
			fVec18[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 256; l24 = faust_wrap_add(l24, 1)) {
			fVec19[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 512; l25 = faust_wrap_add(l25, 1)) {
			fVec20[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 1024; l26 = faust_wrap_add(l26, 1)) {
			fVec21[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec2[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fVec22[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec8[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 3; l30 = faust_wrap_add(l30, 1)) {
			fRec7[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec10[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 3; l32 = faust_wrap_add(l32, 1)) {
			fRec9[l32] = 0.0f;
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
	
	virtual MagCharacterCompressor* clone() {
		return new MagCharacterCompressor(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Character Compressor");
		ui_interface->declare(&fHslider7, "0", "");
		ui_interface->declare(&fHslider7, "tooltip", "");
		ui_interface->addHorizontalSlider("feedback/feedforward", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider19, "0", "");
		ui_interface->declare(&fHslider19, "tooltip", "");
		ui_interface->addHorizontalSlider("ratelimit amount", &fHslider19, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider6, "1", "");
		ui_interface->declare(&fHslider6, "tooltip", "The input signal level is increased by this amount (in dB) to make up for the level lost due to compression");
		ui_interface->declare(&fHslider6, "unit", "dB");
		ui_interface->addHorizontalSlider("Input Gain", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-4e+01f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider21, "1", "");
		ui_interface->declare(&fHslider21, "tooltip", "");
		ui_interface->addHorizontalSlider("hi shelf freq", &fHslider21, FAUSTFLOAT(134.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->declare(&fHslider3, "tooltip", "");
		ui_interface->declare(&fHslider3, "unit", "dB/s");
		ui_interface->addHorizontalSlider("max attack", &fHslider3, FAUSTFLOAT(1.02e+03f), FAUSTFLOAT(6.0f), FAUSTFLOAT(8e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider13, "1", "");
		ui_interface->declare(&fHslider13, "tooltip", "");
		ui_interface->addHorizontalSlider("power", &fHslider13, FAUSTFLOAT(1.881f), FAUSTFLOAT(-33.0f), FAUSTFLOAT(33.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->declare(&fHslider1, "tooltip", "The maximum amount of gain reduction");
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("Max Gain Reduction", &fHslider1, FAUSTFLOAT(-15.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider8, "2", "");
		ui_interface->addHorizontalSlider("peak/RMS", &fHslider8, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider20, "2", "");
		ui_interface->declare(&fHslider20, "tooltip", "");
		ui_interface->addHorizontalSlider("gain/hi-shelve crossfade", &fHslider20, FAUSTFLOAT(0.811f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "tooltip", "");
		ui_interface->declare(&fHslider2, "unit", "dB/s");
		ui_interface->addHorizontalSlider("max decay", &fHslider2, FAUSTFLOAT(3813.0f), FAUSTFLOAT(6.0f), FAUSTFLOAT(8e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider4, "3", "");
		ui_interface->declare(&fHslider4, "tooltip", "");
		ui_interface->addHorizontalSlider("RMS size", &fHslider4, FAUSTFLOAT(96.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(512.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider14, "3", "");
		ui_interface->declare(&fHslider14, "tooltip", "");
		ui_interface->addHorizontalSlider("curve", &fHslider14, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider17, "3", "");
		ui_interface->declare(&fHslider17, "tooltip", "");
		ui_interface->addHorizontalSlider("decayMult", &fHslider17, FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider0, "3", "");
		ui_interface->declare(&fHslider0, "tooltip", "");
		ui_interface->addHorizontalSlider("output gain (dB)", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-4e+01f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider9, "4", "");
		ui_interface->declare(&fHslider9, "tooltip", "When the signal level exceeds the Threshold (in dB), its level is compressed according to the Ratio");
		ui_interface->declare(&fHslider9, "unit", "dB");
		ui_interface->addHorizontalSlider("Threshold", &fHslider9, FAUSTFLOAT(-27.1f), FAUSTFLOAT(-8e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider18, "4", "");
		ui_interface->declare(&fHslider18, "tooltip", "");
		ui_interface->addHorizontalSlider("decayPower", &fHslider18, FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider15, "4", "");
		ui_interface->declare(&fHslider15, "tooltip", "");
		ui_interface->addHorizontalSlider("shape", &fHslider15, FAUSTFLOAT(94.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider12, "5", "");
		ui_interface->declare(&fHslider12, "tooltip", "A compression Ratio of N means that for each N dB increase in input signal level above Threshold, the output level goes up 1 dB");
		ui_interface->addHorizontalSlider("Ratio", &fHslider12, FAUSTFLOAT(2e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider16, "5", "");
		ui_interface->declare(&fHslider16, "tooltip", "");
		ui_interface->addHorizontalSlider("IM_size", &fHslider16, FAUSTFLOAT(108.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(512.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider10, "6", "");
		ui_interface->declare(&fHslider10, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new lower target level (the compression `kicking in')");
		ui_interface->declare(&fHslider10, "unit", "ms");
		ui_interface->addHorizontalSlider("Attack", &fHslider10, FAUSTFLOAT(23.7f), FAUSTFLOAT(0.1f), FAUSTFLOAT(5e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider11, "7", "");
		ui_interface->declare(&fHslider11, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new higher target level (the compression 'releasing')");
		ui_interface->declare(&fHslider11, "unit", "ms");
		ui_interface->addHorizontalSlider("Release", &fHslider11, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.1f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider5, "8", "");
		ui_interface->declare(&fHslider5, "tooltip", "");
		ui_interface->addHorizontalSlider("sidechain hpf", &fHslider5, FAUSTFLOAT(154.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4e+02f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = 0.001f * static_cast<float>(fHslider0);
		float fSlow1 = 0.001f * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider1));
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		float fSlow3 = static_cast<float>(fHslider4);
		int iSlow4 = static_cast<int>(std::floor(fConst2 * fSlow3)) % 2;
		float fSlow5 = static_cast<float>(fHslider5);
		float fSlow6 = fConst3 * fSlow5;
		float fSlow7 = std::sin(fSlow6);
		float fSlow8 = fSlow7 * sinhf(fConst4 * (fSlow5 / fSlow7));
		float fSlow9 = fSlow8 + -1.0f;
		float fSlow10 = std::cos(fSlow6);
		float fSlow11 = 2.0f * fSlow10;
		float fSlow12 = 0.001f * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider6));
		float fSlow13 = static_cast<float>(fHslider7);
		float fSlow14 = 1.0f - fSlow13;
		float fSlow15 = 0.5f * (fSlow10 + 1.0f);
		float fSlow16 = -1.0f - fSlow10;
		float fSlow17 = 1.0f / (fSlow8 + 1.0f);
		int iSlow18 = static_cast<int>(std::floor(fConst5 * fSlow3)) % 2;
		int iSlow19 = static_cast<int>(std::floor(fConst6 * fSlow3)) % 2;
		int iSlow20 = static_cast<int>(std::floor(fConst7 * fSlow3)) % 2;
		int iSlow21 = static_cast<int>(std::floor(fConst8 * fSlow3)) % 2;
		int iSlow22 = static_cast<int>(std::floor(fConst9 * fSlow3)) % 2;
		int iSlow23 = static_cast<int>(std::floor(fConst10 * fSlow3)) % 2;
		int iSlow24 = static_cast<int>(std::floor(fConst11 * fSlow3)) % 2;
		int iSlow25 = static_cast<int>(std::floor(fConst12 * fSlow3)) % 2;
		float fSlow26 = fConst13 * fSlow3;
		int iSlow27 = static_cast<int>(std::floor(fSlow26)) % 2;
		int iSlow28 = faust_wrap_add(iSlow27, faust_wrap_mul(2, iSlow25));
		int iSlow29 = faust_wrap_add(iSlow28, faust_wrap_mul(4, iSlow24));
		int iSlow30 = faust_wrap_add(iSlow29, faust_wrap_mul(8, iSlow23));
		int iSlow31 = faust_wrap_add(iSlow30, faust_wrap_mul(16, iSlow22));
		int iSlow32 = faust_wrap_add(iSlow31, faust_wrap_mul(32, iSlow21));
		int iSlow33 = faust_wrap_add(iSlow32, faust_wrap_mul(64, iSlow20));
		int iSlow34 = faust_wrap_add(iSlow33, faust_wrap_mul(128, iSlow19));
		int iSlow35 = faust_wrap_add(iSlow34, faust_wrap_mul(256, iSlow18));
		int iSlow36 = fSlow26 == 0.0f;
		float fSlow37 = fConst14 / fSlow3;
		float fSlow38 = static_cast<float>(fHslider8);
		float fSlow39 = 1.0f - fSlow38;
		float fSlow40 = static_cast<float>(fHslider9);
		float fSlow41 = fConst15 / static_cast<float>(fHslider10);
		float fSlow42 = fConst16 / static_cast<float>(fHslider11);
		float fSlow43 = 0.05f * (1.0f - 1.0f / static_cast<float>(fHslider12));
		float fSlow44 = static_cast<float>(fHslider13);
		float fSlow45 = static_cast<float>(fSlow44 >= 0.0f) / MagCharacterCompressor_faustpower3_f(fSlow44 + 1.0f) + static_cast<float>(fSlow44 < 0.0f) * MagCharacterCompressor_faustpower3_f(1.0f - fSlow44);
		float fSlow46 = std::exp(-(6.931472f * static_cast<float>(fHslider14)));
		float fSlow47 = MagCharacterCompressor_faustpower2_f(101.0f - static_cast<float>(fHslider15));
		float fSlow48 = static_cast<float>(fHslider16);
		int iSlow49 = static_cast<int>(std::floor(fConst2 * fSlow48)) % 2;
		int iSlow50 = static_cast<int>(std::floor(fConst5 * fSlow48)) % 2;
		int iSlow51 = static_cast<int>(std::floor(fConst6 * fSlow48)) % 2;
		int iSlow52 = static_cast<int>(std::floor(fConst7 * fSlow48)) % 2;
		int iSlow53 = static_cast<int>(std::floor(fConst8 * fSlow48)) % 2;
		int iSlow54 = static_cast<int>(std::floor(fConst9 * fSlow48)) % 2;
		int iSlow55 = static_cast<int>(std::floor(fConst10 * fSlow48)) % 2;
		int iSlow56 = static_cast<int>(std::floor(fConst11 * fSlow48)) % 2;
		int iSlow57 = static_cast<int>(std::floor(fConst12 * fSlow48)) % 2;
		float fSlow58 = fConst13 * fSlow48;
		int iSlow59 = static_cast<int>(std::floor(fSlow58)) % 2;
		int iSlow60 = faust_wrap_add(iSlow59, faust_wrap_mul(2, iSlow57));
		int iSlow61 = faust_wrap_add(iSlow60, faust_wrap_mul(4, iSlow56));
		int iSlow62 = faust_wrap_add(iSlow61, faust_wrap_mul(8, iSlow55));
		int iSlow63 = faust_wrap_add(iSlow62, faust_wrap_mul(16, iSlow54));
		int iSlow64 = faust_wrap_add(iSlow63, faust_wrap_mul(32, iSlow53));
		int iSlow65 = faust_wrap_add(iSlow64, faust_wrap_mul(64, iSlow52));
		int iSlow66 = faust_wrap_add(iSlow65, faust_wrap_mul(128, iSlow51));
		int iSlow67 = faust_wrap_add(iSlow66, faust_wrap_mul(256, iSlow50));
		int iSlow68 = fSlow58 == 0.0f;
		float fSlow69 = fConst17 * (static_cast<float>(fHslider17) / fSlow48);
		float fSlow70 = static_cast<float>(fHslider18);
		float fSlow71 = static_cast<float>(fHslider19);
		float fSlow72 = 2e+01f * (1.0f - fSlow71);
		float fSlow73 = static_cast<float>(fHslider20);
		float fSlow74 = std::tan(fConst18 * static_cast<float>(fHslider21));
		float fSlow75 = 1.0f / MagCharacterCompressor_faustpower2_f(fSlow74);
		float fSlow76 = 2.0f * (1.0f - fSlow75);
		float fSlow77 = 1.0f / fSlow74;
		float fSlow78 = (fSlow77 + -1.0f) / fSlow74 + 1.0f;
		float fSlow79 = 1.0f / ((fSlow77 + 1.0f) / fSlow74 + 1.0f);
		float fSlow80 = 1.0f - fSlow73;
		float fSlow81 = 1.0f - fSlow77;
		float fSlow82 = 1.0f / (fSlow77 + 1.0f);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.999f * fRec0[1];
			fRec3[0] = fSlow1 + 0.999f * fRec3[1];
			float fTemp0 = 1.0f - fRec3[0];
			fRec6[0] = fSlow12 + 0.999f * fRec6[1];
			float fTemp1 = static_cast<float>(input0[i0]) * fRec6[0];
			float fTemp2 = fSlow14 * fRec1[1] + fSlow13 * fTemp1;
			fVec0[0] = fTemp2;
			fRec5[0] = fSlow17 * (fSlow16 * fVec0[1] + fSlow15 * fTemp2 + fSlow15 * fVec0[2] + fSlow11 * fRec5[1] + fSlow9 * fRec5[2]);
			float fTemp3 = MagCharacterCompressor_faustpower2_f(fRec5[0]);
			fVec1[0] = fTemp3;
			float fTemp4 = fTemp3 + fVec1[1];
			fVec2[0] = fTemp4;
			float fTemp5 = fTemp4 + fVec2[2];
			fVec3[0] = fTemp5;
			float fTemp6 = fTemp5 + fVec3[4];
			fVec4[0] = fTemp6;
			float fTemp7 = fTemp6 + fVec4[8];
			fVec5[IOTA0 & 31] = fTemp7;
			float fTemp8 = fTemp7 + fVec5[(faust_wrap_sub(IOTA0, 16)) & 31];
			fVec6[IOTA0 & 63] = fTemp8;
			float fTemp9 = fTemp8 + fVec6[(faust_wrap_sub(IOTA0, 32)) & 63];
			fVec7[IOTA0 & 127] = fTemp9;
			float fTemp10 = fTemp9 + fVec7[(faust_wrap_sub(IOTA0, 64)) & 127];
			fVec8[IOTA0 & 255] = fTemp10;
			float fTemp11 = fTemp10 + fVec8[(faust_wrap_sub(IOTA0, 128)) & 255];
			fVec9[IOTA0 & 511] = fTemp11;
			fVec10[IOTA0 & 1023] = fTemp11 + fVec9[(faust_wrap_sub(IOTA0, 256)) & 511];
			float fTemp12 = 2e+01f * std::log10(std::max<float>(fSlow39 * fRec5[0] + fSlow38 * std::sqrt(fSlow37 * (((iSlow36) ? fTemp3 : ((iSlow27) ? fTemp3 : 0.0f)) + ((iSlow25) ? fVec2[iSlow27] : 0.0f) + ((iSlow24) ? fVec3[iSlow28] : 0.0f) + ((iSlow23) ? fVec4[iSlow29] : 0.0f) + ((iSlow22) ? fVec5[(faust_wrap_sub(IOTA0, iSlow30)) & 31] : 0.0f) + ((iSlow21) ? fVec6[(faust_wrap_sub(IOTA0, iSlow31)) & 63] : 0.0f) + ((iSlow20) ? fVec7[(faust_wrap_sub(IOTA0, iSlow32)) & 127] : 0.0f) + ((iSlow19) ? fVec8[(faust_wrap_sub(IOTA0, iSlow33)) & 255] : 0.0f) + ((iSlow18) ? fVec9[(faust_wrap_sub(IOTA0, iSlow34)) & 511] : 0.0f) + ((iSlow4) ? fVec10[(faust_wrap_sub(IOTA0, iSlow35)) & 1023] : 0.0f))), 1e-09f));
			float fTemp13 = (fTemp12 - fSlow40) * static_cast<float>(fSlow40 < fTemp12);
			float fTemp14 = ((fTemp13 < fRec4[1]) ? fSlow42 : fSlow41);
			fRec4[0] = fTemp13 * fTemp14 + fRec4[1] * (1.0f - fTemp14);
			float fTemp15 = std::max<float>(1e-38f, std::min<float>(0.99999f, std::pow(1e+01f, -(fSlow43 * fRec4[0]))));
			float fTemp16 = std::log(fTemp15);
			float fTemp17 = std::pow(fTemp15, std::min<float>(-(87.49823f / fTemp16), std::max<float>(88.59685f / fTemp16, fSlow45))) - fRec3[0];
			float fTemp18 = fTemp17 / fTemp0;
			float fTemp19 = std::log10(std::max<float>(1.1754944e-38f, fRec3[0] + fTemp0 * (tanhf(fSlow47 * (std::pow(fTemp17 * static_cast<float>(fTemp18 > 0.0f) / fTemp0, fSlow46) + (-1.0f - std::pow(-(fTemp17 * static_cast<float>(fTemp18 <= 0.0f) / fTemp0), fSlow46)))) + 1.0f)));
			float fTemp20 = 2e+01f * fTemp19 - fRec2[1];
			fVec11[0] = fTemp20;
			float fTemp21 = std::fabs(fVec11[1] - fVec11[2]);
			fVec12[0] = fTemp21;
			float fTemp22 = fTemp21 + fVec12[1];
			fVec13[0] = fTemp22;
			float fTemp23 = fTemp22 + fVec13[2];
			fVec14[0] = fTemp23;
			float fTemp24 = fTemp23 + fVec14[4];
			fVec15[0] = fTemp24;
			float fTemp25 = fTemp24 + fVec15[8];
			fVec16[IOTA0 & 31] = fTemp25;
			float fTemp26 = fTemp25 + fVec16[(faust_wrap_sub(IOTA0, 16)) & 31];
			fVec17[IOTA0 & 63] = fTemp26;
			float fTemp27 = fTemp26 + fVec17[(faust_wrap_sub(IOTA0, 32)) & 63];
			fVec18[IOTA0 & 127] = fTemp27;
			float fTemp28 = fTemp27 + fVec18[(faust_wrap_sub(IOTA0, 64)) & 127];
			fVec19[IOTA0 & 255] = fTemp28;
			float fTemp29 = fTemp28 + fVec19[(faust_wrap_sub(IOTA0, 128)) & 255];
			fVec20[IOTA0 & 511] = fTemp29;
			fVec21[IOTA0 & 1023] = fTemp29 + fVec20[(faust_wrap_sub(IOTA0, 256)) & 511];
			fRec2[0] = std::max<float>(2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec3[0])), std::min<float>(0.0f, fRec2[1] + std::min<float>(fSlow2, std::max<float>(-(fConst1 * static_cast<float>(fHslider3)), ((fTemp20 > 0.0f) ? fTemp20 * std::pow(1e+01f, -(0.05f * std::fabs(std::pow(fSlow69 * (((iSlow68) ? fTemp21 : ((iSlow59) ? fTemp21 : 0.0f)) + ((iSlow57) ? fVec13[iSlow59] : 0.0f) + ((iSlow56) ? fVec14[iSlow60] : 0.0f) + ((iSlow55) ? fVec15[iSlow61] : 0.0f) + ((iSlow54) ? fVec16[(faust_wrap_sub(IOTA0, iSlow62)) & 31] : 0.0f) + ((iSlow53) ? fVec17[(faust_wrap_sub(IOTA0, iSlow63)) & 63] : 0.0f) + ((iSlow52) ? fVec18[(faust_wrap_sub(IOTA0, iSlow64)) & 127] : 0.0f) + ((iSlow51) ? fVec19[(faust_wrap_sub(IOTA0, iSlow65)) & 255] : 0.0f) + ((iSlow50) ? fVec20[(faust_wrap_sub(IOTA0, iSlow66)) & 511] : 0.0f) + ((iSlow49) ? fVec21[(faust_wrap_sub(IOTA0, iSlow67)) & 1023] : 0.0f)) + 1.0f, fSlow70) + -1.0f))) : fTemp20)))));
			float fTemp30 = std::log10(std::max<float>(1.1754944e-38f, std::pow(1e+01f, 0.05f * (fSlow72 * fTemp19 + fSlow71 * fRec2[0]))));
			float fTemp31 = fTemp1 * std::pow(1e+01f, fSlow80 * fTemp30);
			fVec22[0] = fTemp31;
			fRec8[0] = -(fSlow82 * (fSlow81 * fRec8[1] - fSlow77 * (fTemp31 - fVec22[1])));
			fRec7[0] = fRec8[0] - fSlow79 * (fSlow78 * fRec7[2] + fSlow76 * fRec7[1]);
			fRec10[0] = -(fSlow82 * (fSlow81 * fRec10[1] - (fTemp31 + fVec22[1])));
			fRec9[0] = fRec10[0] - fSlow79 * (fSlow78 * fRec9[2] + fSlow76 * fRec9[1]);
			fRec1[0] = fSlow79 * (fRec9[2] + fRec9[0] + 2.0f * fRec9[1] + fSlow75 * (fRec7[2] + (fRec7[0] - 2.0f * fRec7[1])) * std::pow(1e+01f, fSlow73 * fTemp30));
			output0[i0] = static_cast<FAUSTFLOAT>(fRec1[0] * std::pow(1e+01f, 0.05f * fRec0[0]));
			fRec0[1] = fRec0[0];
			fRec3[1] = fRec3[0];
			fRec6[1] = fRec6[0];
			fVec0[2] = fVec0[1];
			fVec0[1] = fVec0[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fVec1[1] = fVec1[0];
			fVec2[2] = fVec2[1];
			fVec2[1] = fVec2[0];
			for (int j0 = 4; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fVec3[j0] = fVec3[faust_wrap_sub(j0, 1)];
			}
			for (int j1 = 11; j1 > 0; j1 = faust_wrap_sub(j1, 1)) {
				fVec4[j1] = fVec4[faust_wrap_sub(j1, 1)];
			}
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec4[1] = fRec4[0];
			fVec11[2] = fVec11[1];
			fVec11[1] = fVec11[0];
			fVec12[1] = fVec12[0];
			fVec13[2] = fVec13[1];
			fVec13[1] = fVec13[0];
			for (int j2 = 4; j2 > 0; j2 = faust_wrap_sub(j2, 1)) {
				fVec14[j2] = fVec14[faust_wrap_sub(j2, 1)];
			}
			for (int j3 = 11; j3 > 0; j3 = faust_wrap_sub(j3, 1)) {
				fVec15[j3] = fVec15[faust_wrap_sub(j3, 1)];
			}
			fRec2[1] = fRec2[0];
			fVec22[1] = fVec22[0];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
