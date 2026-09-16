/* ------------------------------------------------------------
author: "Luca Spanedda"
license: "MIT"
name: "Chamberlin Reverb"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LucaChamberlin -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LucaChamberlin_H__
#define  __LucaChamberlin_H__

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
#define FAUSTCLASS LucaChamberlin
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


class LucaChamberlin : public chdsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int IOTA0;
	float fVec0[16384];
	int fSampleRate;
	float fConst0;
	int iConst1;
	float fRec8[2];
	float fVec1[8192];
	int iConst2;
	float fRec6[2];
	float fVec2[8192];
	int iConst3;
	float fRec4[2];
	float fVec3[4096];
	int iConst4;
	float fRec2[2];
	float fVec4[4096];
	int iConst5;
	float fRec0[2];
	float fVec5[4096];
	int iConst6;
	float fRec12[2];
	float fVec6[4096];
	int iConst7;
	float fRec10[2];
	float fConst8;
	float fConst9;
	FAUSTFLOAT fHslider1;
	float fRec14[2];
	
 public:
	LucaChamberlin() {
	}
	
	LucaChamberlin(const LucaChamberlin&) = default;
	
	virtual ~LucaChamberlin() = default;
	
	LucaChamberlin& operator=(const LucaChamberlin&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Luca Spanedda");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LucaChamberlin -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Hal Chamberlin's 1979 all-allpass reverberator (3 series + 2x2 output allpasses) with T60 decay control - vintage chip-reverb smear");
		m->declare("family", "reverb");
		m->declare("filename", "luca-chamberlin.dsp");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Chamberlin Reverb");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "LucaSpanedda/Digital_Reverberation_in_Faust src/reverberation.lib chamberlinDecay");
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
		iConst1 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.0496f * fConst0)), -1);
		iConst2 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.03475f * fConst0)), -1);
		iConst3 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.02418f * fConst0)), -1);
		iConst4 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.01801f * fConst0)), -1);
		iConst5 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.01082f * fConst0)), -1);
		iConst6 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.01785f * fConst0)), -1);
		iConst7 = faust_wrap_add(std::max<int>(2, static_cast<int>(0.01098f * fConst0)), -1);
		fConst8 = 44.1f / fConst0;
		fConst9 = 1.0f - fConst8;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(3.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.35f);
	}
	
	virtual void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 16384; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec8[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 8192; l2 = faust_wrap_add(l2, 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec6[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 8192; l4 = faust_wrap_add(l4, 1)) {
			fVec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 4096; l6 = faust_wrap_add(l6, 1)) {
			fVec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 4096; l8 = faust_wrap_add(l8, 1)) {
			fVec4[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec0[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 4096; l10 = faust_wrap_add(l10, 1)) {
			fVec5[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec12[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 4096; l12 = faust_wrap_add(l12, 1)) {
			fVec6[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec10[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec14[l14] = 0.0f;
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
	
	virtual LucaChamberlin* clone() {
		return new LucaChamberlin(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Chamberlin Reverb");
		ui_interface->declare(&fHslider0, "0", "");
		ui_interface->declare(&fHslider0, "unit", "s");
		ui_interface->addHorizontalSlider("Decay", &fHslider0, FAUSTFLOAT(3.0f), FAUSTFLOAT(0.2f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider1, FAUSTFLOAT(0.35f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = static_cast<float>(fHslider0);
		float fSlow1 = std::pow(0.001f, 0.01082f / fSlow0);
		float fSlow2 = std::pow(0.001f, 0.01801f / fSlow0);
		float fSlow3 = std::pow(0.001f, 0.02418f / fSlow0);
		float fSlow4 = std::pow(0.001f, 0.03475f / fSlow0);
		float fSlow5 = std::pow(0.001f, 0.0496f / fSlow0);
		float fSlow6 = std::pow(0.001f, 0.01098f / fSlow0);
		float fSlow7 = std::pow(0.001f, 0.01785f / fSlow0);
		float fSlow8 = fConst8 * static_cast<float>(fHslider1);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			float fTemp0 = static_cast<float>(input0[i0]);
			float fTemp1 = fTemp0 + fSlow5 * fRec8[1];
			fVec0[IOTA0 & 16383] = fTemp1;
			fRec8[0] = fVec0[(faust_wrap_sub(IOTA0, iConst1)) & 16383];
			float fRec9 = -(fSlow5 * fTemp1);
			float fTemp2 = fRec8[1] + fRec9 + fSlow4 * fRec6[1];
			fVec1[IOTA0 & 8191] = fTemp2;
			fRec6[0] = fVec1[(faust_wrap_sub(IOTA0, iConst2)) & 8191];
			float fRec7 = -(fSlow4 * fTemp2);
			float fTemp3 = fRec6[1] + fRec7 + fSlow3 * fRec4[1];
			fVec2[IOTA0 & 8191] = fTemp3;
			fRec4[0] = fVec2[(faust_wrap_sub(IOTA0, iConst3)) & 8191];
			float fRec5 = -(fSlow3 * fTemp3);
			float fTemp4 = fRec5 + fRec4[1] + fSlow2 * fRec2[1];
			fVec3[IOTA0 & 4095] = fTemp4;
			fRec2[0] = fVec3[(faust_wrap_sub(IOTA0, iConst4)) & 4095];
			float fRec3 = -(fSlow2 * fTemp4);
			float fTemp5 = fRec2[1] + fRec3 + fSlow1 * fRec0[1];
			fVec4[IOTA0 & 4095] = fTemp5;
			fRec0[0] = fVec4[(faust_wrap_sub(IOTA0, iConst5)) & 4095];
			float fRec1 = -(fSlow1 * fTemp5);
			float fTemp6 = fRec4[1] + fRec5 + fSlow7 * fRec12[1];
			fVec5[IOTA0 & 4095] = fTemp6;
			fRec12[0] = fVec5[(faust_wrap_sub(IOTA0, iConst6)) & 4095];
			float fRec13 = -(fSlow7 * fTemp6);
			float fTemp7 = fRec12[1] + fRec13 + fSlow6 * fRec10[1];
			fVec6[IOTA0 & 4095] = fTemp7;
			fRec10[0] = fVec6[(faust_wrap_sub(IOTA0, iConst7)) & 4095];
			float fRec11 = -(fSlow6 * fTemp7);
			fRec14[0] = fSlow8 + fConst9 * fRec14[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec14[0]) + 0.5f * fRec14[0] * (fRec0[1] + fRec10[1] + fRec11 + fRec1));
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec14[1] = fRec14[0];
		}
	}

};

#endif
