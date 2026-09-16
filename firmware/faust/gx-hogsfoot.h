/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Hogs Foot"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxHogsfoot -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxHogsfoot_H__
#define  __GxHogsfoot_H__

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
#define FAUSTCLASS GxHogsfoot
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

static double GxHogsfoot_faustpower2_f(double value) {
	return value * value;
}

class GxHogsfoot : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	double fRec0[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	FAUSTFLOAT fVslider1;
	double fRec1[4];
	double fConst8;
	
 public:
	GxHogsfoot() {
	}
	
	GxHogsfoot(const GxHogsfoot&) = default;
	
	virtual ~GxHogsfoot() = default;
	
	GxHogsfoot& operator=(const GxHogsfoot&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Tone Control");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxHogsfoot -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Hogs Foot Bass Booster");
		m->declare("filename", "gx-hogsfoot.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "hogsfoot");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Hogs Foot");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "Hogs Foot");
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
		fConst1 = 8.93887847679127e-15 * fConst0;
		fConst2 = fConst0 * (fConst0 * (4.96106145708971e-12 - fConst1) + -2.63723081667839e-11) + 2.67730449581491e-11;
		fConst3 = 2.68166354303738e-14 * fConst0;
		fConst4 = fConst0 * (fConst0 * (fConst3 + -4.96106145708971e-12) + -2.63723081667839e-11) + 8.03191348744474e-11;
		fConst5 = fConst0 * (fConst0 * (-4.96106145708971e-12 - fConst3) + 2.63723081667839e-11) + 8.03191348744474e-11;
		fConst6 = fConst0 * (fConst0 * (fConst1 + 4.96106145708971e-12) + 2.63723081667839e-11) + 2.67730449581491e-11;
		fConst7 = 1.0 / fConst6;
		fConst8 = GxHogsfoot_faustpower2_f(fConst0) / fConst6;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(1e+02);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 4; l1 = faust_wrap_add(l1, 1)) {
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
	
	virtual GxHogsfoot* clone() {
		return new GxHogsfoot(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Hogs Foot");
		ui_interface->declare(&fVslider0, "name", "Volume");
		ui_interface->addVerticalSlider("Volume", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider1, "name", "wet/dry");
		ui_interface->declare(&fVslider1, "tooltip", "percentage of processed signal in output signal");
		ui_interface->addVerticalSlider("wet_dry", &fVslider1, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * static_cast<double>(fVslider0);
		double fSlow1 = 0.01 * static_cast<double>(fVslider1);
		double fSlow2 = 1.0 - fSlow1;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			double fTemp0 = 9.64632260709932e-11 * fRec0[0];
			double fTemp1 = -9.64632260709932e-13 - fTemp0;
			double fTemp2 = static_cast<double>(input0[i0]);
			fRec1[0] = fSlow1 * fTemp2 - fConst7 * (fConst5 * fRec1[1] + fConst4 * fRec1[2] + fConst2 * fRec1[3]);
			double fTemp3 = fTemp0 + 9.64632260709932e-13;
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow2 * fTemp2 + fConst8 * (fRec1[0] * fTemp1 + fRec1[1] * fTemp3 + fRec1[2] * fTemp3 + fRec1[3] * fTemp1));
			fRec0[1] = fRec0[0];
			for (int j0 = 3; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec1[j0] = fRec1[faust_wrap_sub(j0, 1)];
			}
		}
	}

};

#endif
