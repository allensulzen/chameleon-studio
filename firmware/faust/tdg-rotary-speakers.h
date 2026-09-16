/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Rotary Speakers"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgRotarySpeakers -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgRotarySpeakers_H__
#define  __TdgRotarySpeakers_H__

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
#define FAUSTCLASS TdgRotarySpeakers
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

class TdgRotarySpeakersSIG0 {
	
  private:
	
	int iVec2[2];
	int iRec3[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsTdgRotarySpeakersSIG0() {
		return 0;
	}
	int getNumOutputsTdgRotarySpeakersSIG0() {
		return 1;
	}
	
	void instanceInitTdgRotarySpeakersSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			iVec2[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			iRec3[l3] = 0;
		}
	}
	
	void fillTdgRotarySpeakersSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec2[0] = 1;
			iRec3[0] = (faust_wrap_add(iVec2[1], iRec3[1])) % 65536;
			table[i1] = std::sin(9.58738e-05f * static_cast<float>(iRec3[0]));
			iVec2[1] = iVec2[0];
			iRec3[1] = iRec3[0];
		}
	}

};

static TdgRotarySpeakersSIG0* newTdgRotarySpeakersSIG0() { return (TdgRotarySpeakersSIG0*)new TdgRotarySpeakersSIG0(); }
static void deleteTdgRotarySpeakersSIG0(TdgRotarySpeakersSIG0* dsp) { delete dsp; }

static float TdgRotarySpeakers_faustpower2_f(float value) {
	return value * value;
}
static float DSY_SDRAM_BSS ftbl0TdgRotarySpeakersSIG0[65536];

class TdgRotarySpeakers : public chdsp {
	
 private:
	
	int iVec0[2];
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
	int IOTA0;
	float fVec1[512];
	float fConst11;
	float fConst12;
	FAUSTFLOAT fHslider0;
	float fRec5[2];
	float fConst13;
	float fRec4[2];
	FAUSTFLOAT fHslider1;
	float fRec6[2];
	float fVec3[2];
	float fConst14;
	float fConst15;
	float fRec2[2];
	float fRec1[3];
	float fConst16;
	float fRec0[3];
	FAUSTFLOAT fHslider2;
	float fRec7[2];
	float fRec10[2];
	float fRec9[3];
	float fRec8[3];
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
	float fRec13[2];
	float fRec12[3];
	float fConst29;
	float fRec11[3];
	float fRec16[2];
	float fRec15[3];
	float fRec14[3];
	float fVec4[2];
	float fRec19[2];
	float fRec18[3];
	float fRec17[3];
	float fRec22[2];
	float fRec21[3];
	float fRec20[3];
	float fRec25[2];
	float fRec24[3];
	float fRec23[3];
	float fRec28[2];
	float fRec27[3];
	float fRec26[3];
	FAUSTFLOAT fHslider3;
	float fRec29[2];
	
 public:
	TdgRotarySpeakers() {
	}
	
	TdgRotarySpeakers(const TdgRotarySpeakers&) = default;
	
	virtual ~TdgRotarySpeakers() = default;
	
	TdgRotarySpeakers& operator=(const TdgRotarySpeakers&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgRotarySpeakers -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Leslie-style rotary: two counter-modulated delay lines with amplitude modulation and horn/drum coloration, summed to mono");
		m->declare("family", "mod");
		m->declare("filename", "tdg-rotary-speakers.dsp");
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
		m->declare("name", "Rotary Speakers");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust rotary_speakers.dsp");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		TdgRotarySpeakersSIG0* sig0 = newTdgRotarySpeakersSIG0();
		sig0->instanceInitTdgRotarySpeakersSIG0(sample_rate);
		sig0->fillTdgRotarySpeakersSIG0(65536, ftbl0TdgRotarySpeakersSIG0);
		deleteTdgRotarySpeakersSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = std::tan(2764.6016f / fConst0);
		fConst2 = TdgRotarySpeakers_faustpower2_f(fConst1);
		fConst3 = 1.0f / fConst2;
		fConst4 = 2.0f * (1.0f - fConst3);
		fConst5 = 1.0f / fConst1;
		fConst6 = (fConst5 + -0.618034f) / fConst1 + 1.0f;
		fConst7 = 1.0f / ((fConst5 + 0.618034f) / fConst1 + 1.0f);
		fConst8 = (fConst5 + -1.618034f) / fConst1 + 1.0f;
		fConst9 = (fConst5 + 1.618034f) / fConst1 + 1.0f;
		fConst10 = 1.0f / fConst9;
		fConst11 = 44.1f / fConst0;
		fConst12 = 1.0f - fConst11;
		fConst13 = 1.0f / fConst0;
		fConst14 = 1.0f - fConst5;
		fConst15 = 1.0f / (fConst5 + 1.0f);
		fConst16 = 1.0f / (fConst2 * fConst9);
		fConst17 = std::tan(1382.3008f / fConst0);
		fConst18 = TdgRotarySpeakers_faustpower2_f(fConst17);
		fConst19 = 1.0f / fConst18;
		fConst20 = 2.0f * (1.0f - fConst19);
		fConst21 = 1.0f / fConst17;
		fConst22 = (fConst21 + -0.618034f) / fConst17 + 1.0f;
		fConst23 = 1.0f / ((fConst21 + 0.618034f) / fConst17 + 1.0f);
		fConst24 = (fConst21 + -1.618034f) / fConst17 + 1.0f;
		fConst25 = (fConst21 + 1.618034f) / fConst17 + 1.0f;
		fConst26 = 1.0f / fConst25;
		fConst27 = 1.0f - fConst21;
		fConst28 = 1.0f / (fConst21 + 1.0f);
		fConst29 = 1.0f / (fConst18 * fConst25);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(6.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(5e+01f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 512; l1 = faust_wrap_add(l1, 1)) {
			fVec1[l1] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fVec3[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec2[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec1[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec0[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec7[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec10[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = faust_wrap_add(l13, 1)) {
			fRec9[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = faust_wrap_add(l14, 1)) {
			fRec8[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec13[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 3; l16 = faust_wrap_add(l16, 1)) {
			fRec12[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 3; l17 = faust_wrap_add(l17, 1)) {
			fRec11[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 3; l19 = faust_wrap_add(l19, 1)) {
			fRec15[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 3; l20 = faust_wrap_add(l20, 1)) {
			fRec14[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fVec4[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec19[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 3; l23 = faust_wrap_add(l23, 1)) {
			fRec18[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 3; l24 = faust_wrap_add(l24, 1)) {
			fRec17[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec22[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 3; l26 = faust_wrap_add(l26, 1)) {
			fRec21[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 3; l27 = faust_wrap_add(l27, 1)) {
			fRec20[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec25[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 3; l29 = faust_wrap_add(l29, 1)) {
			fRec24[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 3; l30 = faust_wrap_add(l30, 1)) {
			fRec23[l30] = 0.0f;
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
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec29[l34] = 0.0f;
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
	
	virtual TdgRotarySpeakers* clone() {
		return new TdgRotarySpeakers(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Rotary Speakers");
		ui_interface->declare(&fHslider0, "0", "");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("Speed", &fHslider0, FAUSTFLOAT(6.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "unit", "samples");
		ui_interface->addHorizontalSlider("Depth", &fHslider1, FAUSTFLOAT(5e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(2e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->addHorizontalSlider("Coloration", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.05f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst11 * static_cast<float>(fHslider0);
		float fSlow1 = fConst11 * static_cast<float>(fHslider1);
		float fSlow2 = fConst11 * static_cast<float>(fHslider2);
		float fSlow3 = fConst11 * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			float fTemp0 = static_cast<float>(input0[i0]);
			fVec1[IOTA0 & 511] = fTemp0;
			fRec5[0] = fSlow0 + fConst12 * fRec5[1];
			float fTemp1 = ((faust_wrap_sub(1, iVec0[1])) ? 0.0f : fRec4[1] + fConst13 * fRec5[0]);
			fRec4[0] = fTemp1 - std::floor(fTemp1);
			float fTemp2 = ftbl0TdgRotarySpeakersSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec4[0]), 65535))];
			float fTemp3 = fTemp2 + 1.0f;
			fRec6[0] = fSlow1 + fConst12 * fRec6[1];
			float fTemp4 = 0.5f * fRec6[0] * fTemp3;
			float fTemp5 = fTemp4 + 1.0f;
			int iTemp6 = static_cast<int>(fTemp5);
			float fTemp7 = std::floor(fTemp5);
			float fTemp8 = fVec1[(faust_wrap_sub(IOTA0, std::min<int>(501, std::max<int>(0, iTemp6)))) & 511] * (fTemp7 - fTemp4) + (fTemp4 + (1.0f - fTemp7)) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(501, std::max<int>(0, faust_wrap_add(iTemp6, 1))))) & 511];
			float fTemp9 = fTemp3 * fTemp8;
			fVec3[0] = fTemp9;
			float fTemp10 = fTemp9 - fVec3[1];
			fRec2[0] = -(fConst15 * (fConst14 * fRec2[1] - fConst5 * fTemp10));
			fRec1[0] = fRec2[0] - fConst10 * (fConst8 * fRec1[2] + fConst4 * fRec1[1]);
			fRec0[0] = fConst16 * (fRec1[2] + (fRec1[0] - 2.0f * fRec1[1])) - fConst7 * (fConst6 * fRec0[2] + fConst4 * fRec0[1]);
			fRec7[0] = fSlow2 + fConst12 * fRec7[1];
			float fTemp11 = std::pow(1e+01f, 0.6f * fRec7[0]);
			float fTemp12 = fTemp9 + fVec3[1];
			fRec10[0] = -(fConst15 * (fConst14 * fRec10[1] - fTemp12));
			fRec9[0] = fRec10[0] - fConst10 * (fConst8 * fRec9[2] + fConst4 * fRec9[1]);
			fRec8[0] = fConst10 * (fRec9[2] + fRec9[0] + 2.0f * fRec9[1]) - fConst7 * (fConst6 * fRec8[2] + fConst4 * fRec8[1]);
			fRec13[0] = -(fConst28 * (fConst27 * fRec13[1] - fConst21 * fTemp10));
			fRec12[0] = fRec13[0] - fConst26 * (fConst24 * fRec12[2] + fConst20 * fRec12[1]);
			fRec11[0] = fConst29 * (fRec12[2] + (fRec12[0] - 2.0f * fRec12[1])) - fConst23 * (fConst22 * fRec11[2] + fConst20 * fRec11[1]);
			fRec16[0] = -(fConst28 * (fConst27 * fRec16[1] - fTemp12));
			fRec15[0] = fRec16[0] - fConst26 * (fConst24 * fRec15[2] + fConst20 * fRec15[1]);
			fRec14[0] = fConst26 * (fRec15[2] + fRec15[0] + 2.0f * fRec15[1]) - fConst23 * (fConst22 * fRec14[2] + fConst20 * fRec14[1]);
			float fTemp13 = std::pow(1e+01f, 0.6f * (1.0f - fRec7[0]));
			float fTemp14 = fTemp8 * (1.0f - fTemp2);
			fVec4[0] = fTemp14;
			float fTemp15 = fTemp14 - fVec4[1];
			fRec19[0] = -(fConst15 * (fConst14 * fRec19[1] - fConst5 * fTemp15));
			fRec18[0] = fRec19[0] - fConst10 * (fConst8 * fRec18[2] + fConst4 * fRec18[1]);
			fRec17[0] = fConst16 * (fRec18[2] + (fRec18[0] - 2.0f * fRec18[1])) - fConst7 * (fConst6 * fRec17[2] + fConst4 * fRec17[1]);
			float fTemp16 = fTemp14 + fVec4[1];
			fRec22[0] = -(fConst15 * (fConst14 * fRec22[1] - fTemp16));
			fRec21[0] = fRec22[0] - fConst10 * (fConst8 * fRec21[2] + fConst4 * fRec21[1]);
			fRec20[0] = fConst10 * (fRec21[2] + fRec21[0] + 2.0f * fRec21[1]) - fConst7 * (fConst6 * fRec20[2] + fConst4 * fRec20[1]);
			fRec25[0] = -(fConst28 * (fConst27 * fRec25[1] - fConst21 * fTemp15));
			fRec24[0] = fRec25[0] - fConst26 * (fConst24 * fRec24[2] + fConst20 * fRec24[1]);
			fRec23[0] = fConst29 * (fRec24[2] + (fRec24[0] - 2.0f * fRec24[1])) - fConst23 * (fConst22 * fRec23[2] + fConst20 * fRec23[1]);
			fRec28[0] = -(fConst28 * (fConst27 * fRec28[1] - fTemp16));
			fRec27[0] = fRec28[0] - fConst26 * (fConst24 * fRec27[2] + fConst20 * fRec27[1]);
			fRec26[0] = fConst26 * (fRec27[2] + fRec27[0] + 2.0f * fRec27[1]) - fConst23 * (fConst22 * fRec26[2] + fConst20 * fRec26[1]);
			fRec29[0] = fSlow3 + fConst12 * fRec29[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec29[0]) + 0.35565588f * fRec29[0] * (fConst23 * ((fRec26[2] + fRec26[0] + 2.0f * fRec26[1]) * fTemp13 + fConst19 * (fRec23[2] + (fRec23[0] - 2.0f * fRec23[1]))) + fConst7 * (fRec20[2] + fRec20[0] + 2.0f * fRec20[1] + fConst3 * (fRec17[2] + (fRec17[0] - 2.0f * fRec17[1])) * fTemp11) + fConst23 * (fTemp13 * (fRec14[2] + fRec14[0] + 2.0f * fRec14[1]) + fConst19 * (fRec11[2] + (fRec11[0] - 2.0f * fRec11[1]))) + fConst7 * (fRec8[2] + fRec8[0] + 2.0f * fRec8[1] + fConst3 * fTemp11 * (fRec0[2] + (fRec0[0] - 2.0f * fRec0[1])))));
			iVec0[1] = iVec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fVec3[1] = fVec3[0];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec7[1] = fRec7[0];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec16[1] = fRec16[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fVec4[1] = fVec4[0];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec22[1] = fRec22[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec25[1] = fRec25[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec28[1] = fRec28[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec29[1] = fRec29[0];
		}
	}

};

#endif
