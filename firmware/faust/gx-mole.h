/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "The Mole"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMole -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxMole_H__
#define  __GxMole_H__

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
#define FAUSTCLASS GxMole
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

static double GxMole_faustpower2_f(double value) {
	return value * value;
}

class GxMole : public chdsp {
	
 private:
	
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	FAUSTFLOAT fVslider0;
	double fRec0[4];
	FAUSTFLOAT fVslider1;
	double fRec1[2];
	double fConst8;
	
 public:
	GxMole() {
	}
	
	GxMole(const GxMole&) = default;
	
	virtual ~GxMole() = default;
	
	GxMole& operator=(const GxMole&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Tone Control");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMole -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "EHX Mole");
		m->declare("filename", "gx-mole.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "mole");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "The Mole");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "The Mole");
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
		fConst1 = 8.93878454194095e-15 * fConst0;
		fConst2 = fConst0 * (fConst0 * (4.96556855945694e-12 - fConst1) + -2.64572840995574e-11) + 2.70404912477885e-11;
		fConst3 = 2.68163536258229e-14 * fConst0;
		fConst4 = fConst0 * (fConst0 * (fConst3 + -4.96556855945694e-12) + -2.64572840995574e-11) + 8.11214737433656e-11;
		fConst5 = fConst0 * (fConst0 * (-4.96556855945694e-12 - fConst3) + 2.64572840995574e-11) + 8.11214737433656e-11;
		fConst6 = fConst0 * (fConst0 * (fConst1 + 4.96556855945694e-12) + 2.64572840995574e-11) + 2.70404912477885e-11;
		fConst7 = 1.0 / fConst6;
		fConst8 = 9.74268345040146e-11 * (GxMole_faustpower2_f(fConst0) / fConst6);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(1e+02);
		fVslider1 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 4; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0;
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
	
	virtual GxMole* clone() {
		return new GxMole(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("The Mole");
		ui_interface->declare(&fVslider1, "name", "Boost");
		ui_interface->addVerticalSlider("Boost", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider0, "name", "wet/dry");
		ui_interface->declare(&fVslider0, "tooltip", "percentage of processed signal in output signal");
		ui_interface->addVerticalSlider("wet_dry", &fVslider0, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.01 * static_cast<double>(fVslider0);
		double fSlow1 = 0.007000000000000006 * static_cast<double>(fVslider1);
		double fSlow2 = 1.0 - fSlow0;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			fRec0[0] = fSlow0 * fTemp0 - fConst7 * (fConst5 * fRec0[1] + fConst4 * fRec0[2] + fConst2 * fRec0[3]);
			fRec1[0] = fSlow1 + 0.993 * fRec1[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow2 * fTemp0 - fConst8 * fRec1[0] * (fRec0[3] + (fRec0[0] - fRec0[1] - fRec0[2])));
			for (int j0 = 3; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec0[j0] = fRec0[faust_wrap_sub(j0, 1)];
			}
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
