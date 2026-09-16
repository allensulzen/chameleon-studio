/* ------------------------------------------------------------
license: "BSD"
name: "Flanger Mono"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFlangerMono -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxFlangerMono_H__
#define  __GxFlangerMono_H__

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
#define FAUSTCLASS GxFlangerMono
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


class GxFlangerMono : public chdsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fVslider0;
	int iVec0[2];
	int IOTA0;
	double fVec1[4096];
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec1[2];
	double fRec2[2];
	double fRec0[2];
	
 public:
	GxFlangerMono() {
	}
	
	GxFlangerMono(const GxFlangerMono&) = default;
	
	virtual ~GxFlangerMono() = default;
	
	GxFlangerMono& operator=(const GxFlangerMono&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Modulation");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFlangerMono -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-flanger-mono.dsp");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "flanger_mono");
		m->declare("license", "BSD");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Flanger Mono");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
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
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 6.283185307179586 / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider0 = static_cast<FAUSTFLOAT>(1e+02);
		fHslider1 = static_cast<FAUSTFLOAT>(0.2);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 4096; l1 = faust_wrap_add(l1, 1)) {
			fVec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec1[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec2[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec0[l4] = 0.0;
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
	
	virtual GxFlangerMono* clone() {
		return new GxFlangerMono(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Flanger Mono");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(0.2), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("level", &fHslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(-6e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider0, "name", "wet/dry");
		ui_interface->declare(&fVslider0, "tooltip", "percentage of processed signal in output signal");
		ui_interface->addVerticalSlider("wet_dry", &fVslider0, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fVslider0);
		double fSlow1 = 0.01 * fSlow0 * std::pow(1e+01, 0.05 * static_cast<double>(fHslider0));
		double fSlow2 = fConst1 * static_cast<double>(fHslider1);
		double fSlow3 = std::cos(fSlow2);
		double fSlow4 = std::sin(fSlow2);
		double fSlow5 = 1.0 - 0.01 * fSlow0;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			double fTemp1 = fSlow1 * fTemp0;
			iVec0[0] = 1;
			double fTemp2 = 0.5 * fRec0[1] - fTemp1;
			fVec1[IOTA0 & 4095] = fTemp2;
			fRec1[0] = fSlow4 * fRec2[1] + fSlow3 * fRec1[1];
			fRec2[0] = static_cast<double>(faust_wrap_sub(1, iVec0[1])) + fSlow3 * fRec2[1] - fSlow4 * fRec1[1];
			double fTemp3 = fConst0 * (0.005 * (fRec1[0] + 1.0) + 0.001);
			int iTemp4 = static_cast<int>(fTemp3);
			double fTemp5 = std::floor(fTemp3);
			fRec0[0] = fVec1[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, iTemp4)))) & 4095] * (fTemp5 + (1.0 - fTemp3)) + (fTemp3 - fTemp5) * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(2049, std::max<int>(0, faust_wrap_add(iTemp4, 1))))) & 4095];
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow5 * fTemp0 + 0.5 * (fTemp1 - fRec0[0]));
			iVec0[1] = iVec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
