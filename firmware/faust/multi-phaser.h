/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "MultiStagePhaser"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn MultiPhaser -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __MultiPhaser_H__
#define  __MultiPhaser_H__

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
#define FAUSTCLASS MultiPhaser
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

static float MultiPhaser_faustpower2_f(float value) {
	return value * value;
}

class MultiPhaser : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec3[2];
	float fConst3;
	float fRec1[2];
	float fRec2[2];
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	FAUSTFLOAT fHslider1;
	float fRec7[2];
	float fRec6[3];
	float fRec5[3];
	float fRec4[3];
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	float fRec8[2];
	
 public:
	MultiPhaser() {
	}
	
	MultiPhaser(const MultiPhaser&) = default;
	
	virtual ~MultiPhaser() = default;
	
	MultiPhaser& operator=(const MultiPhaser&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn MultiPhaser -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Six-notch all-pass phaser with resonant feedback (Phase 90 to Small Stone)");
		m->declare("filename", "multi-phaser.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "MultiStagePhaser");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("phaflangers.lib/name", "Faust Phaser and Flanger Library");
		m->declare("phaflangers.lib/version", "1.1.0");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 6.2831855f / fConst0;
		fConst4 = 3.375f / fConst0;
		fConst5 = 2.25f / fConst0;
		fConst6 = 1.5f / fConst0;
		fConst7 = std::exp(-(3141.5928f / fConst0));
		fConst8 = MultiPhaser_faustpower2_f(fConst7);
		fConst9 = 2.0f * fConst7;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(1.5f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.55f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.75f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec7[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec4[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec0[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec8[l9] = 0.0f;
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
	
	virtual MultiPhaser* clone() {
		return new MultiPhaser(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("MultiStagePhaser");
		ui_interface->addHorizontalSlider("Depth", &fHslider2, FAUSTFLOAT(0.75f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Feedback", &fHslider1, FAUSTFLOAT(0.55f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.9f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("Rate", &fHslider0, FAUSTFLOAT(1.5f), FAUSTFLOAT(0.1f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.05f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec3[0] = fSlow0 + fConst2 * fRec3[1];
			float fTemp0 = fConst3 * fRec3[0];
			float fTemp1 = std::cos(fTemp0);
			float fTemp2 = std::sin(fTemp0);
			fRec1[0] = fRec2[1] * fTemp2 + fRec1[1] * fTemp1;
			fRec2[0] = static_cast<float>(faust_wrap_sub(1, iVec0[1])) + fRec2[1] * fTemp1 - fTemp2 * fRec1[1];
			float fTemp3 = 9676.105f * (1.0f - fRec1[0]) + 753.98224f;
			float fTemp4 = fRec4[1] * std::cos(fConst4 * fTemp3);
			float fTemp5 = fRec5[1] * std::cos(fConst5 * fTemp3);
			float fTemp6 = fRec6[1] * std::cos(fConst6 * fTemp3);
			fRec7[0] = fSlow1 + fConst2 * fRec7[1];
			float fTemp7 = static_cast<float>(input0[i0]);
			fRec6[0] = fTemp7 + fRec7[0] * fRec0[1] + fConst9 * fTemp6 - fConst8 * fRec6[2];
			fRec5[0] = fRec6[2] + fConst8 * (fRec6[0] - fRec5[2]) - fConst9 * (fTemp6 - fTemp5);
			fRec4[0] = fRec5[2] + fConst8 * (fRec5[0] - fRec4[2]) - fConst9 * (fTemp5 - fTemp4);
			fRec0[0] = fRec4[2] + fConst8 * fRec4[0] - fConst9 * fTemp4;
			fRec8[0] = fSlow2 + fConst2 * fRec8[1];
			output0[i0] = static_cast<FAUSTFLOAT>(tanhf(fTemp7 * (1.0f - 0.5f * fRec8[0]) + 0.5f * fRec8[0] * fRec0[0]));
			iVec0[1] = iVec0[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec0[1] = fRec0[0];
			fRec8[1] = fRec8[0];
		}
	}

};

#endif
