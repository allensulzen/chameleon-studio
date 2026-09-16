/* ------------------------------------------------------------
author: "Bart Brouns (port of Katja Vetter's qompander), Hilbert coefficients by Olli Niemitalo"
license: "GPL-3.0"
name: "Qompander"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn OwlQompander -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __OwlQompander_H__
#define  __OwlQompander_H__

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
#define FAUSTCLASS OwlQompander
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

static float OwlQompander_faustpower2_f(float value) {
	return value * value;
}

class OwlQompander : public chdsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fVec0[2];
	float fRec6[3];
	float fRec5[3];
	float fRec4[3];
	float fRec3[3];
	float fRec10[3];
	float fRec9[3];
	float fRec8[3];
	float fRec7[3];
	FAUSTFLOAT fHslider1;
	float fRec11[2];
	float fRec2[2];
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	float fRec12[2];
	FAUSTFLOAT fHslider3;
	float fRec13[2];
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider4;
	float fRec14[2];
	
 public:
	OwlQompander() {
	}
	
	OwlQompander(const OwlQompander&) = default;
	
	virtual ~OwlQompander() = default;
	
	OwlQompander& operator=(const OwlQompander&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Bart Brouns (port of Katja Vetter's qompander), Hilbert coefficients by Olli Niemitalo");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn OwlQompander -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Katja Vetter's Hilbert-envelope compander (Bart Brouns port): upward companding that adds sustain and bite");
		m->declare("family", "dynamics");
		m->declare("filename", "owl-qompander.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "GPL-3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Qompander");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "pingdynasty/OwlPatches Faust/Qompander.dsp");
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
		fConst2 = 44.1f / fConst0;
		fConst3 = 1.0f - fConst2;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(2e+01f);
		fHslider2 = static_cast<FAUSTFLOAT>(3.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(-4e+01f);
		fHslider4 = static_cast<FAUSTFLOAT>(-6.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec6[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec10[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec9[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec11[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec2[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec0[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec14[l15] = 0.0f;
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
	
	virtual OwlQompander* clone() {
		return new OwlQompander(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Qompander");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->addHorizontalSlider("Factor", &fHslider2, FAUSTFLOAT(3.0f), FAUSTFLOAT(0.8f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->declare(&fHslider3, "unit", "dB");
		ui_interface->addHorizontalSlider("Threshold", &fHslider3, FAUSTFLOAT(-4e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->declare(&fHslider0, "unit", "ms");
		ui_interface->addHorizontalSlider("Attack", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->declare(&fHslider1, "unit", "ms");
		ui_interface->addHorizontalSlider("Release", &fHslider1, FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider4, "4", "");
		ui_interface->declare(&fHslider4, "unit", "dB");
		ui_interface->addHorizontalSlider("Level", &fHslider4, FAUSTFLOAT(-6.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = 0.001f * static_cast<float>(fHslider0);
		float fSlow1 = 0.001f * static_cast<float>(fHslider1);
		float fSlow2 = 0.001f * static_cast<float>(fHslider2);
		float fSlow3 = 0.001f * static_cast<float>(fHslider3);
		float fSlow4 = fConst2 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider4));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow0 + 0.999f * fRec1[1];
			float fTemp0 = std::max<float>(0.001f, 0.001f * fRec1[0]);
			int iTemp1 = std::fabs(fTemp0) < 1.1920929e-07f;
			float fTemp2 = ((iTemp1) ? 0.0f : std::exp(-(fConst1 / ((iTemp1) ? 1.0f : fTemp0))));
			float fTemp3 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp3;
			fRec6[0] = fVec0[1] + 0.479401f * fRec6[2];
			fRec5[0] = 0.479401f * fRec6[0] + 0.876218f * fRec5[2] - fRec6[2];
			fRec4[0] = 0.876218f * fRec5[0] + 0.976599f * fRec4[2] - fRec5[2];
			fRec3[0] = 0.976599f * fRec4[0] + 0.9975f * fRec3[2] - fRec4[2];
			float fTemp4 = 0.9975f * fRec3[0] - fRec3[2];
			fRec10[0] = fTemp3 + 0.161758f * fRec10[2];
			fRec9[0] = 0.161758f * fRec10[0] + 0.733029f * fRec9[2] - fRec10[2];
			fRec8[0] = 0.733029f * fRec9[0] + 0.94535f * fRec8[2] - fRec9[2];
			fRec7[0] = 0.94535f * fRec8[0] + 0.990598f * fRec7[2] - fRec8[2];
			float fTemp5 = 0.990598f * fRec7[0] - fRec7[2];
			float fTemp6 = std::fabs(std::min<float>(1e+02f, std::max<float>(1e-05f, std::sqrt(OwlQompander_faustpower2_f(fTemp5) + OwlQompander_faustpower2_f(fTemp4)))));
			fRec11[0] = fSlow1 + 0.999f * fRec11[1];
			float fTemp7 = std::max<float>(0.02f, 0.001f * fRec11[0]);
			int iTemp8 = std::fabs(fTemp7) < 1.1920929e-07f;
			float fTemp9 = ((iTemp8) ? 0.0f : std::exp(-(fConst1 / ((iTemp8) ? 1.0f : fTemp7))));
			fRec2[0] = std::max<float>(fTemp6, fRec2[1] * fTemp9 + fTemp6 * (1.0f - fTemp9));
			fRec0[0] = fRec2[0] * (1.0f - fTemp2) + fTemp2 * fRec0[1];
			fRec12[0] = fSlow2 + 0.999f * fRec12[1];
			fRec13[0] = fSlow3 + 0.999f * fRec13[1];
			float fTemp10 = std::pow(1e+01f, 0.05f * fRec13[0]);
			fRec14[0] = fSlow4 + fConst3 * fRec14[1];
			output0[i0] = static_cast<FAUSTFLOAT>(0.70710677f * (fRec14[0] * std::pow(std::min<float>(1.0f, std::max<float>(1e-07f, std::sin(1.5707964f * fRec12[0] * std::min<float>(1.0f / fRec12[0], fRec0[0])))), std::log(fTemp10) / std::log(std::sin(1.5707964f * fRec12[0] * fTemp10))) * (fTemp5 + fTemp4) / fRec0[0]));
			fRec1[1] = fRec1[0];
			fVec0[1] = fVec0[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec11[1] = fRec11[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
		}
	}

};

#endif
