/* ------------------------------------------------------------
author: "Albert Graef"
license: "GPL-2.0-or-later"
name: "Expander"
version: "1.0"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxExpander -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxExpander_H__
#define  __GxExpander_H__

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
#define FAUSTCLASS GxExpander
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


class GxExpander : public chdsp {
	
 private:
	
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fRec1[2];
	double fConst3;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	double fRec0[2];
	FAUSTFLOAT fEntry0;
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT fEntry2;
	
 public:
	GxExpander() {
	}
	
	GxExpander(const GxExpander&) = default;
	
	virtual ~GxExpander() = default;
	
	GxExpander& operator=(const GxExpander&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Albert Graef");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Guitar Effects");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxExpander -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "expander unit");
		m->declare("filename", "gx-expander.dsp");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Expander");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("version", "1.0");
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
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = std::exp(-(1e+01 / fConst0));
		fConst2 = 1.0 - fConst1;
		fConst3 = 1.0 / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.1);
		fHslider1 = static_cast<FAUSTFLOAT>(0.001);
		fEntry0 = static_cast<FAUSTFLOAT>(-4e+01);
		fEntry1 = static_cast<FAUSTFLOAT>(3.0);
		fEntry2 = static_cast<FAUSTFLOAT>(2.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec1[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec0[l1] = 0.0;
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
	
	virtual GxExpander* clone() {
		return new GxExpander(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Expander");
		ui_interface->addHorizontalSlider("attack", &fHslider1, FAUSTFLOAT(0.001), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.001));
		ui_interface->addNumEntry("knee", &fEntry1, FAUSTFLOAT(3.0), FAUSTFLOAT(0.0), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->addNumEntry("ratio", &fEntry2, FAUSTFLOAT(2.0), FAUSTFLOAT(1.0), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->addHorizontalSlider("release", &fHslider0, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->addNumEntry("threshold", &fEntry0, FAUSTFLOAT(-4e+01), FAUSTFLOAT(-96.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = std::exp(-(fConst3 / std::max<double>(fConst3, static_cast<double>(fHslider0))));
		double fSlow1 = std::exp(-(fConst3 / std::max<double>(fConst3, static_cast<double>(fHslider1))));
		double fSlow2 = static_cast<double>(fEntry1);
		double fSlow3 = fSlow2 + static_cast<double>(fEntry0);
		double fSlow4 = 1.0 / (fSlow2 + 0.001);
		double fSlow5 = 0.05 * (1.0 - static_cast<double>(fEntry2));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			fRec1[0] = fConst1 * fRec1[1] + fConst2 * std::fabs(fTemp0);
			double fTemp1 = std::max<double>(fRec1[0], fTemp0);
			double fTemp2 = fSlow1 * static_cast<double>(fRec0[1] < fTemp1) + fSlow0 * static_cast<double>(fRec0[1] >= fTemp1);
			fRec0[0] = fRec0[1] * fTemp2 + fTemp1 * (1.0 - fTemp2);
			double fTemp3 = std::max<double>(0.0, fSlow3 - 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec0[0])));
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * std::pow(1e+01, fSlow5 * fTemp3 * std::min<double>(1.0, std::max<double>(0.0, fSlow4 * fTemp3))));
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
