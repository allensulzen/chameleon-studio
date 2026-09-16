/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Duck Delay"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxDuckDelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxDuckDelay_H__
#define  __GxDuckDelay_H__

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
#define FAUSTCLASS GxDuckDelay
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


class GxDuckDelay : public chdsp {
	
 private:
	
	int fSampleRate;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fHslider0;
	double fConst2;
	FAUSTFLOAT fHslider1;
	double fRec2[2];
	double fRec1[2];
	double fConst3;
	double fConst4;
	FAUSTFLOAT fHslider2;
	double fRec3[2];
	double fConst5;
	double fRec0[2];
	FAUSTFLOAT fHslider3;
	int IOTA0;
	double fVec0[524288];
	FAUSTFLOAT fHslider4;
	double fRec5[2];
	double fConst6;
	double fRec4[2];
	
 public:
	GxDuckDelay() {
	}
	
	GxDuckDelay(const GxDuckDelay&) = default;
	
	virtual ~GxDuckDelay() = default;
	
	GxDuckDelay& operator=(const GxDuckDelay&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Echo / Delay");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxDuckDelay -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-duck-delay.dsp");
		m->declare("id", "duckDelay");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Duck Delay");
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
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = std::exp(-(1e+01 / fConst0));
		fConst2 = 1.0 / fConst0;
		fConst3 = 44.1 / fConst0;
		fConst4 = 1.0 - fConst3;
		fConst5 = 1.0 - fConst1;
		fConst6 = 0.001 * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.1);
		fHslider1 = static_cast<FAUSTFLOAT>(0.1);
		fHslider2 = static_cast<FAUSTFLOAT>(12.0);
		fHslider3 = static_cast<FAUSTFLOAT>(0.0);
		fHslider4 = static_cast<FAUSTFLOAT>(5e+02);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec2[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec3[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec0[l3] = 0.0;
		}
		IOTA0 = 0;
		for (int l4 = 0; l4 < 524288; l4 = faust_wrap_add(l4, 1)) {
			fVec0[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec5[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec4[l6] = 0.0;
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
	
	virtual GxDuckDelay* clone() {
		return new GxDuckDelay(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Duck Delay");
		ui_interface->addHorizontalSlider("amount", &fHslider2, FAUSTFLOAT(12.0), FAUSTFLOAT(0.0), FAUSTFLOAT(4e+01), FAUSTFLOAT(0.5));
		ui_interface->addHorizontalSlider("attack", &fHslider0, FAUSTFLOAT(0.1), FAUSTFLOAT(0.05), FAUSTFLOAT(0.5), FAUSTFLOAT(0.05));
		ui_interface->addHorizontalSlider("feedback", &fHslider3, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addHorizontalSlider("relese", &fHslider1, FAUSTFLOAT(0.1), FAUSTFLOAT(0.05), FAUSTFLOAT(2.0), FAUSTFLOAT(0.05));
		ui_interface->addHorizontalSlider("time", &fHslider4, FAUSTFLOAT(5e+02), FAUSTFLOAT(1.0), FAUSTFLOAT(2e+03), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fHslider0);
		int iSlow1 = std::fabs(fSlow0) < 2.220446049250313e-16;
		double fSlow2 = ((iSlow1) ? 0.0 : std::exp(-(fConst2 / ((iSlow1) ? 1.0 : fSlow0))));
		double fSlow3 = 1.0 - fSlow2;
		double fSlow4 = static_cast<double>(fHslider1);
		int iSlow5 = std::fabs(fSlow4) < 2.220446049250313e-16;
		double fSlow6 = ((iSlow5) ? 0.0 : std::exp(-(fConst2 / ((iSlow5) ? 1.0 : fSlow4))));
		double fSlow7 = 1.0 - fSlow6;
		double fSlow8 = fConst3 * static_cast<double>(fHslider2);
		double fSlow9 = static_cast<double>(fHslider3);
		double fSlow10 = fConst5 * static_cast<double>(fHslider4);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			double fTemp1 = std::fabs(fTemp0);
			fRec2[0] = std::max<double>(fTemp1, fRec2[1] * fSlow6 + fTemp1 * fSlow7);
			fRec1[0] = fRec2[0] * fSlow3 + fSlow2 * fRec1[1];
			fRec3[0] = fSlow8 + fConst4 * fRec3[1];
			fRec0[0] = fConst5 * std::pow(1e+01, -(0.05 * fRec3[0] * std::min<double>(1.0, 4.0 * fRec1[0]))) + fConst1 * fRec0[1];
			double fTemp2 = fTemp0 + fSlow9 * fRec4[1];
			fVec0[IOTA0 & 524287] = fTemp2;
			fRec5[0] = fSlow10 + fConst1 * fRec5[1];
			double fTemp3 = fConst6 * fRec5[0];
			int iTemp4 = static_cast<int>(fTemp3);
			double fTemp5 = std::floor(fTemp3);
			fRec4[0] = fVec0[(faust_wrap_sub(IOTA0, std::min<int>(393217, std::max<int>(0, iTemp4)))) & 524287] * (fTemp5 + (1.0 - fTemp3)) + (fTemp3 - fTemp5) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(393217, std::max<int>(0, faust_wrap_add(iTemp4, 1))))) & 524287];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 + fRec4[0] * fRec0[0]);
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec0[1] = fRec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
		}
	}

};

#endif
