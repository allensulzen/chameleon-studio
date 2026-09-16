/* ------------------------------------------------------------
author: "Eric Tarr"
license: "MIT"
name: "Korg 35 HPF"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibKorg35Hpf -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibKorg35Hpf_H__
#define  __LibKorg35Hpf_H__

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
#define FAUSTCLASS LibKorg35Hpf
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


class LibKorg35Hpf : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec5[2];
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	float fRec1[2];
	float fRec2[2];
	float fRec3[2];
	
 public:
	LibKorg35Hpf() {
	}
	
	LibKorg35Hpf(const LibKorg35Hpf&) = default;
	
	virtual ~LibKorg35Hpf() = default;
	
	LibKorg35Hpf& operator=(const LibKorg35Hpf&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Eric Tarr");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibKorg35Hpf -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "MS-20 style Korg35 resonant highpass - thin, squelchy filter sweeps");
		m->declare("family", "filter");
		m->declare("filename", "lib-korg35-hpf.dsp");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Korg 35 HPF");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/vaeffects.lib ve.korg35HPF");
		m->declare("vaeffects.lib/korg35HPF:author", "Eric Tarr");
		m->declare("vaeffects.lib/korg35HPF:license", "LicenseRef-STK-4.3");
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
		fHslider1 = static_cast<FAUSTFLOAT>(3e+02f);
		fHslider2 = static_cast<FAUSTFLOAT>(2.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec5[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec6[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0f;
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
	
	virtual LibKorg35Hpf* clone() {
		return new LibKorg35Hpf(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Korg 35 HPF");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->declare(&fHslider1, "scale", "log");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Cutoff", &fHslider1, FAUSTFLOAT(3e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(8e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->addHorizontalSlider("Resonance", &fHslider2, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.707f), FAUSTFLOAT(9.9f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
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
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			fRec5[0] = fSlow1 + fConst2 * fRec5[1];
			float fTemp0 = std::tan(fConst3 * std::pow(1e+01f, 3.0f * std::min<float>(0.99f, 0.33333334f * std::log10(0.05f * std::max<float>(2e+01f, fRec5[0]))) + 1.0f));
			float fTemp1 = fTemp0 + 1.0f;
			fRec6[0] = fSlow2 + fConst2 * fRec6[1];
			float fTemp2 = std::max<float>(0.707f, fRec6[0]) + -0.70710677f;
			float fTemp3 = 1.0f - 0.21521823f * (fTemp0 * fTemp2 * (1.0f - fTemp0 / fTemp1) / fTemp1);
			float fTemp4 = static_cast<float>(input0[i0]);
			float fTemp5 = (fTemp4 - fRec3[1]) * fTemp0;
			float fTemp6 = fTemp4 - (fRec3[1] + (fTemp5 - fRec1[1] + fTemp0 * fRec2[1] / fTemp1) / fTemp1);
			float fTemp7 = 0.21521823f * (fTemp6 * fTemp2 / fTemp3);
			float fTemp8 = fTemp0 * (fTemp7 - fRec2[1]) / fTemp1;
			fRec1[0] = fRec1[1] + 2.0f * (fTemp0 * (fTemp7 - (fTemp8 + fRec1[1] + fRec2[1])) / fTemp1);
			fRec2[0] = fRec2[1] + 2.0f * fTemp8;
			fRec3[0] = fRec3[1] + 2.0f * (fTemp5 / fTemp1);
			float fRec4 = fTemp6 / fTemp3;
			output0[i0] = static_cast<FAUSTFLOAT>(tanhf(fRec4) * fRec0[0]);
			fRec0[1] = fRec0[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
