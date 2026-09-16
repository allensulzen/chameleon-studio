/* ------------------------------------------------------------
author: "Eric Tarr"
license: "MIT"
name: "Moog Ladder"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibMoogLadder -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibMoogLadder_H__
#define  __LibMoogLadder_H__

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
#define FAUSTCLASS LibMoogLadder
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

static float LibMoogLadder_faustpower4_f(float value) {
	return value * value * value * value;
}

class LibMoogLadder : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec6[2];
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fRec7[2];
	FAUSTFLOAT fHslider3;
	float fRec8[2];
	float fRec1[2];
	float fRec2[2];
	float fRec3[2];
	float fRec4[2];
	
 public:
	LibMoogLadder() {
	}
	
	LibMoogLadder(const LibMoogLadder&) = default;
	
	virtual ~LibMoogLadder() = default;
	
	LibMoogLadder& operator=(const LibMoogLadder&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Eric Tarr");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibMoogLadder -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Zavalishin-style virtual-analog Moog transistor ladder lowpass with resonance and drive");
		m->declare("family", "filter");
		m->declare("filename", "lib-moog-ladder.dsp");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Moog Ladder");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/vaeffects.lib ve.moogLadder");
		m->declare("vaeffects.lib/moogLadder:author", "Dario Sanfilippo");
		m->declare("vaeffects.lib/moogLadder:license", "LicenseRef-STK-4.3");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/version", "1.6.0");
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
		fConst3 = 6.2831855f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(1.2e+03f);
		fHslider2 = static_cast<FAUSTFLOAT>(2.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(6.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec6[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec7[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec8[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec2[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec4[l7] = 0.0f;
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
	
	virtual LibMoogLadder* clone() {
		return new LibMoogLadder(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Moog Ladder");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->declare(&fHslider1, "scale", "log");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Cutoff", &fHslider1, FAUSTFLOAT(1.2e+03f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(1.2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->addHorizontalSlider("Resonance", &fHslider2, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.707f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->declare(&fHslider3, "unit", "dB");
		ui_interface->addHorizontalSlider("Drive", &fHslider3, FAUSTFLOAT(6.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider0, "3", "");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("Level", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider0));
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider3));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			fRec6[0] = fSlow1 + fConst2 * fRec6[1];
			float fTemp0 = std::tan(fConst3 * std::pow(1e+01f, 3.0f * std::min<float>(0.99f, 0.33333334f * std::log10(0.05f * std::max<float>(2e+01f, fRec6[0]))) + 1.0f));
			float fTemp1 = fTemp0 + 1.0f;
			fRec7[0] = fSlow2 + fConst2 * fRec7[1];
			float fTemp2 = std::max<float>(0.707f, fRec7[0]) + -0.70710677f;
			fRec8[0] = fSlow3 + fConst2 * fRec8[1];
			float fTemp3 = fTemp0 * ((static_cast<float>(input0[i0]) * fRec8[0] - 0.1646572f * fTemp2 * (1.0f - fTemp0 / fTemp1) * (fRec4[1] + fTemp0 * (fRec3[1] + fTemp0 * (fRec2[1] + fTemp0 * fRec1[1] / fTemp1) / fTemp1) / fTemp1)) / (0.1646572f * (LibMoogLadder_faustpower4_f(fTemp0) * fTemp2 / LibMoogLadder_faustpower4_f(fTemp1)) + 1.0f) - fRec1[1]) / fTemp1;
			fRec1[0] = fRec1[1] + 2.0f * fTemp3;
			float fTemp4 = fTemp0 * (fRec1[1] + fTemp3 - fRec2[1]) / fTemp1;
			fRec2[0] = fRec2[1] + 2.0f * fTemp4;
			float fTemp5 = fTemp0 * (fRec2[1] + fTemp4 - fRec3[1]) / fTemp1;
			fRec3[0] = fRec3[1] + 2.0f * fTemp5;
			float fTemp6 = fTemp0 * (fRec3[1] + fTemp5 - fRec4[1]) / fTemp1;
			fRec4[0] = fRec4[1] + 2.0f * fTemp6;
			float fRec5 = fRec4[1] + fTemp6;
			output0[i0] = static_cast<FAUSTFLOAT>(fRec5 * fRec0[0]);
			fRec0[1] = fRec0[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
		}
	}

};

#endif
