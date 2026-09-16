/* ------------------------------------------------------------
author: "Grame (ef.transpose)"
license: "LGPL-2.1-or-later"
name: "Harmonizer"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibHarmonizer -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibHarmonizer_H__
#define  __LibHarmonizer_H__

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
#define FAUSTCLASS LibHarmonizer
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


class LibHarmonizer : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	float fRec0[2];
	int IOTA0;
	float fVec0[131072];
	FAUSTFLOAT fHslider1;
	float fRec2[2];
	FAUSTFLOAT fHslider2;
	float fRec4[2];
	float fRec3[2];
	FAUSTFLOAT fHslider3;
	float fRec5[2];
	FAUSTFLOAT fHslider4;
	float fRec6[2];
	
 public:
	LibHarmonizer() {
	}
	
	LibHarmonizer(const LibHarmonizer&) = default;
	
	virtual ~LibHarmonizer() = default;
	
	LibHarmonizer& operator=(const LibHarmonizer&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Grame (ef.transpose)");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibHarmonizer -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Two ef.transpose voices at independent intervals mixed with the dry note - instant intervals");
		m->declare("family", "pitch");
		m->declare("filename", "lib-harmonizer.dsp");
		m->declare("license", "LGPL-2.1-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "Harmonizer");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/misceffects.lib ef.transpose");
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
		fConst0 = 44.1f / std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 1.0f - fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(-12.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(7.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.7f);
		fHslider4 = static_cast<FAUSTFLOAT>(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec0[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 131072; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec6[l7] = 0.0f;
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
	
	virtual LibHarmonizer* clone() {
		return new LibHarmonizer(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Harmonizer");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "unit", "semi");
		ui_interface->addHorizontalSlider("Voice 1", &fHslider2, FAUSTFLOAT(7.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->addHorizontalSlider("Voice 1 Level", &fHslider3, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->declare(&fHslider0, "unit", "semi");
		ui_interface->addHorizontalSlider("Voice 2", &fHslider0, FAUSTFLOAT(-12.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->addHorizontalSlider("Voice 2 Level", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider4, "4", "");
		ui_interface->addHorizontalSlider("Dry", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst0 * static_cast<float>(fHslider0);
		float fSlow1 = fConst0 * static_cast<float>(fHslider1);
		float fSlow2 = fConst0 * static_cast<float>(fHslider2);
		float fSlow3 = fConst0 * static_cast<float>(fHslider3);
		float fSlow4 = fConst0 * static_cast<float>(fHslider4);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow0 + fConst1 * fRec1[1];
			fRec0[0] = std::fmod(fRec0[1] + (1501.0f - std::pow(2.0f, 0.083333336f * fRec1[0])), 1.5e+03f);
			float fTemp0 = std::min<float>(0.0033333334f * fRec0[0], 1.0f);
			float fTemp1 = fRec0[0] + 1.5e+03f;
			float fTemp2 = std::floor(fTemp1);
			float fTemp3 = static_cast<float>(input0[i0]);
			fVec0[IOTA0 & 131071] = fTemp3;
			int iTemp4 = static_cast<int>(fTemp1);
			int iTemp5 = static_cast<int>(fRec0[0]);
			float fTemp6 = std::floor(fRec0[0]);
			fRec2[0] = fSlow1 + fConst1 * fRec2[1];
			fRec4[0] = fSlow2 + fConst1 * fRec4[1];
			fRec3[0] = std::fmod(fRec3[1] + (1501.0f - std::pow(2.0f, 0.083333336f * fRec4[0])), 1.5e+03f);
			float fTemp7 = std::min<float>(0.0033333334f * fRec3[0], 1.0f);
			float fTemp8 = fRec3[0] + 1.5e+03f;
			float fTemp9 = std::floor(fTemp8);
			int iTemp10 = static_cast<int>(fTemp8);
			int iTemp11 = static_cast<int>(fRec3[0]);
			float fTemp12 = std::floor(fRec3[0]);
			fRec5[0] = fSlow3 + fConst1 * fRec5[1];
			fRec6[0] = fSlow4 + fConst1 * fRec6[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp3 * fRec6[0] + fRec5[0] * ((fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp11)))) & 131071] * (fTemp12 + (1.0f - fRec3[0])) + (fRec3[0] - fTemp12) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp11, 1))))) & 131071]) * fTemp7 + (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp10)))) & 131071] * (fTemp9 + (-1499.0f - fRec3[0])) + fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp10, 1))))) & 131071] * (fRec3[0] + (1.5e+03f - fTemp9))) * (1.0f - fTemp7)) + fRec2[0] * ((fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp5)))) & 131071] * (fTemp6 + (1.0f - fRec0[0])) + (fRec0[0] - fTemp6) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp5, 1))))) & 131071]) * fTemp0 + (fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, iTemp4)))) & 131071] * (fTemp2 + (-1499.0f - fRec0[0])) + fVec0[(faust_wrap_sub(IOTA0, std::min<int>(65537, std::max<int>(0, faust_wrap_add(iTemp4, 1))))) & 131071] * (fRec0[0] + (1.5e+03f - fTemp2))) * (1.0f - fTemp0)));
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
		}
	}

};

#endif
