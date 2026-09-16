/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "BBDChorus"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn BbdChorus -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __BbdChorus_H__
#define  __BbdChorus_H__

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
#define FAUSTCLASS BbdChorus
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

class BbdChorusSIG0 {
	
  private:
	
	int iVec2[2];
	int iRec1[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsBbdChorusSIG0() {
		return 0;
	}
	int getNumOutputsBbdChorusSIG0() {
		return 1;
	}
	
	void instanceInitBbdChorusSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			iVec2[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			iRec1[l3] = 0;
		}
	}
	
	void fillBbdChorusSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec2[0] = 1;
			iRec1[0] = (faust_wrap_add(iVec2[1], iRec1[1])) % 65536;
			table[i1] = std::cos(9.58738e-05f * static_cast<float>(iRec1[0]));
			iVec2[1] = iVec2[0];
			iRec1[1] = iRec1[0];
		}
	}

};

static BbdChorusSIG0* newBbdChorusSIG0() { return (BbdChorusSIG0*)new BbdChorusSIG0(); }
static void deleteBbdChorusSIG0(BbdChorusSIG0* dsp) { delete dsp; }

class BbdChorusSIG1 {
	
  private:
	
	int iVec3[2];
	int iRec6[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsBbdChorusSIG1() {
		return 0;
	}
	int getNumOutputsBbdChorusSIG1() {
		return 1;
	}
	
	void instanceInitBbdChorusSIG1(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			iVec3[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			iRec6[l9] = 0;
		}
	}
	
	void fillBbdChorusSIG1(int count, float* table) {
		for (int i2 = 0; i2 < count; i2 = faust_wrap_add(i2, 1)) {
			iVec3[0] = 1;
			iRec6[0] = (faust_wrap_add(iVec3[1], iRec6[1])) % 65536;
			table[i2] = std::sin(9.58738e-05f * static_cast<float>(iRec6[0]));
			iVec3[1] = iVec3[0];
			iRec6[1] = iRec6[0];
		}
	}

};

static BbdChorusSIG1* newBbdChorusSIG1() { return (BbdChorusSIG1*)new BbdChorusSIG1(); }
static void deleteBbdChorusSIG1(BbdChorusSIG1* dsp) { delete dsp; }

static float BbdChorus_faustpower2_f(float value) {
	return value * value;
}
static float DSY_SDRAM_BSS ftbl0BbdChorusSIG0[65536];
static float DSY_SDRAM_BSS ftbl1BbdChorusSIG1[65536];

class BbdChorus : public chdsp {
	
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
	int IOTA0;
	float fVec1[4096];
	float fConst7;
	float fConst8;
	FAUSTFLOAT fHslider0;
	float fRec3[2];
	float fConst9;
	float fRec2[2];
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	float fRec0[3];
	float fConst10;
	float fRec7[2];
	float fRec5[3];
	FAUSTFLOAT fHslider2;
	float fRec8[2];
	float fConst11;
	
 public:
	BbdChorus() {
	}
	
	BbdChorus(const BbdChorus&) = default;
	
	virtual ~BbdChorus() = default;
	
	BbdChorus& operator=(const BbdChorus&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn BbdChorus -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Two-voice bucket-brigade chorus with band-limited delay lines");
		m->declare("filename", "bbd-chorus.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
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
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "BBDChorus");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		BbdChorusSIG0* sig0 = newBbdChorusSIG0();
		sig0->instanceInitBbdChorusSIG0(sample_rate);
		sig0->fillBbdChorusSIG0(65536, ftbl0BbdChorusSIG0);
		BbdChorusSIG1* sig1 = newBbdChorusSIG1();
		sig1->instanceInitBbdChorusSIG1(sample_rate);
		sig1->fillBbdChorusSIG1(65536, ftbl1BbdChorusSIG1);
		deleteBbdChorusSIG0(sig0);
		deleteBbdChorusSIG1(sig1);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = std::tan(23561.945f / fConst0);
		fConst2 = 2.0f * (1.0f - 1.0f / BbdChorus_faustpower2_f(fConst1));
		fConst3 = 1.0f / fConst1;
		fConst4 = (fConst3 + -1.4142135f) / fConst1 + 1.0f;
		fConst5 = (fConst3 + 1.4142135f) / fConst1 + 1.0f;
		fConst6 = 1.0f / fConst5;
		fConst7 = 44.1f / fConst0;
		fConst8 = 1.0f - fConst7;
		fConst9 = 0.93f / fConst0;
		fConst10 = 1.0f / fConst0;
		fConst11 = 0.55f / fConst5;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(1.2f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.65f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 4096; l1 = faust_wrap_add(l1, 1)) {
			fVec1[l1] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec2[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec4[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec0[l7] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec7[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 3; l11 = faust_wrap_add(l11, 1)) {
			fRec5[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec8[l12] = 0.0f;
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
	
	virtual BbdChorus* clone() {
		return new BbdChorus(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("BBDChorus");
		ui_interface->addHorizontalSlider("Blend", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Depth", &fHslider1, FAUSTFLOAT(0.65f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("Speed", &fHslider0, FAUSTFLOAT(1.2f), FAUSTFLOAT(0.1f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.05f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst7 * static_cast<float>(fHslider0);
		float fSlow1 = fConst7 * static_cast<float>(fHslider1);
		float fSlow2 = fConst7 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			float fTemp0 = static_cast<float>(input0[i0]);
			fVec1[IOTA0 & 4095] = fTemp0;
			int iTemp1 = faust_wrap_sub(1, iVec0[1]);
			fRec3[0] = fSlow0 + fConst8 * fRec3[1];
			float fTemp2 = ((iTemp1) ? 0.0f : fRec2[1] + fConst9 * fRec3[0]);
			fRec2[0] = fTemp2 - std::floor(fTemp2);
			fRec4[0] = fSlow1 + fConst8 * fRec4[1];
			float fTemp3 = fConst0 * (0.0028f * fRec4[0] * ftbl0BbdChorusSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec2[0]), 65535))] + 0.009f);
			int iTemp4 = static_cast<int>(fTemp3);
			float fTemp5 = std::floor(fTemp3);
			fRec0[0] = fVec1[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, iTemp4)))) & 4095] * (fTemp5 + (1.0f - fTemp3)) + (fTemp3 - fTemp5) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, faust_wrap_add(iTemp4, 1))))) & 4095] - fConst6 * (fConst4 * fRec0[2] + fConst2 * fRec0[1]);
			float fTemp6 = ((iTemp1) ? 0.0f : fRec7[1] + fConst10 * fRec3[0]);
			fRec7[0] = fTemp6 - std::floor(fTemp6);
			float fTemp7 = fConst0 * (0.003f * fRec4[0] * ftbl1BbdChorusSIG1[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec7[0]), 65535))] + 0.0065f);
			int iTemp8 = static_cast<int>(fTemp7);
			float fTemp9 = std::floor(fTemp7);
			fRec5[0] = fVec1[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, iTemp8)))) & 4095] * (fTemp9 + (1.0f - fTemp7)) + (fTemp7 - fTemp9) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, faust_wrap_add(iTemp8, 1))))) & 4095] - fConst6 * (fConst4 * fRec5[2] + fConst2 * fRec5[1]);
			fRec8[0] = fSlow2 + fConst8 * fRec8[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - 0.5f * fRec8[0]) + fConst11 * fRec8[0] * (fRec5[2] + fRec5[0] + 2.0f * fRec5[1] + fRec0[2] + fRec0[0] + 2.0f * fRec0[1]));
			iVec0[1] = iVec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec7[1] = fRec7[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec8[1] = fRec8[0];
		}
	}

};

#endif
