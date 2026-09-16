/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Delay"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxDelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxDelay_H__
#define  __GxDelay_H__

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
#define FAUSTCLASS GxDelay
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


class GxDelay : public chdsp {
	
 private:
	
	int IOTA0;
	double fVec0[524288];
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	double fConst0;
	FAUSTFLOAT fVslider1;
	double fRec0[2];
	
 public:
	GxDelay() {
	}
	
	GxDelay(const GxDelay&) = default;
	
	virtual ~GxDelay() = default;
	
	GxDelay& operator=(const GxDelay&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Echo / Delay");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxDelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/fdelay5s:deprecated", "use de.delay/de.fdelay with an explicit size; the 1s..43s names are power-of-two sample counts, not seconds");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-delay.dsp");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Delay");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
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
		fConst0 = 0.001 * std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider1 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 524288; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
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
	
	virtual GxDelay* clone() {
		return new GxDelay(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Delay");
		ui_interface->addVerticalSlider("de.delay", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5e+03), FAUSTFLOAT(1e+01));
		ui_interface->addVerticalSlider("gain", &fVslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = fConst0 * static_cast<double>(fVslider0);
		int iSlow1 = static_cast<int>(fSlow0);
		int iSlow2 = std::min<int>(262145, std::max<int>(0, faust_wrap_add(iSlow1, 1)));
		double fSlow3 = std::floor(fSlow0);
		double fSlow4 = fSlow0 - fSlow3;
		int iSlow5 = std::min<int>(262145, std::max<int>(0, iSlow1));
		double fSlow6 = fSlow3 + (1.0 - fSlow0);
		double fSlow7 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider1));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			fVec0[IOTA0 & 524287] = fTemp0;
			fRec0[0] = fSlow7 + 0.999 * fRec0[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 + fRec0[0] * (fSlow6 * fVec0[(faust_wrap_sub(IOTA0, iSlow5)) & 524287] + fSlow4 * fVec0[(faust_wrap_sub(IOTA0, iSlow2)) & 524287]));
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
