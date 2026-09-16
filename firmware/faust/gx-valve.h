/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "gx-valve"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxValve -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxValve_H__
#define  __GxValve_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#ifndef FAUST_INT_WRAP
#define FAUST_INT_WRAP
inline int faust_wrap_add(int a, int b) { return int((unsigned int)a + (unsigned int)b); }
inline int faust_wrap_sub(int a, int b) { return int((unsigned int)a - (unsigned int)b); }
inline int faust_wrap_mul(int a, int b) { return int((unsigned int)a * (unsigned int)b); }
#endif


#ifndef FAUSTCLASS 
#define FAUSTCLASS GxValve
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

static double GxValve_faustpower3_f(double value) {
	return value * value * value;
}

class GxValve : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	int fSampleRate;
	
 public:
	GxValve() {
	}
	
	GxValve(const GxValve&) = default;
	
	virtual ~GxValve() = default;
	
	GxValve& operator=(const GxValve&) = default;
	
	void metadata(Meta* m) { 
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxValve -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-valve.dsp");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "gx-valve");
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
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider1 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
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
	
	virtual GxValve* clone() {
		return new GxValve(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("gx-valve");
		ui_interface->addVerticalSlider("dist", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(-2.0), FAUSTFLOAT(2.0), FAUSTFLOAT(0.01));
		ui_interface->addVerticalSlider("q", &fVslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-1.7), FAUSTFLOAT(1.7), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = std::pow(1e+01, static_cast<double>(fVslider0));
		double fSlow1 = GxValve_faustpower3_f(static_cast<double>(fVslider1));
		double fSlow2 = fSlow1 * fSlow0;
		double fSlow3 = std::max<double>(-6e+02, -fSlow2);
		double fSlow4 = ((std::fabs(-fSlow2) > 0.0001) ? ((fSlow3 < -5e+01) ? -(fSlow3 * std::exp(fSlow3)) : fSlow3 / (1.0 - std::exp(-fSlow3))) : fSlow2 * (0.08333333333333333 * fSlow2 + -0.5) + 1.0);
		double fSlow5 = 0.08333333333333333 * fSlow0;
		double fSlow6 = 1.0 / fSlow0;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]) - fSlow1;
			double fTemp1 = fSlow0 * fTemp0;
			double fTemp2 = std::max<double>(-6e+02, fTemp1);
			double fTemp3 = fSlow1 + fSlow6 * (((std::fabs(fTemp1) > 0.0001) ? ((fTemp2 < -5e+01) ? -(fTemp2 * std::exp(fTemp2)) : fTemp2 / (1.0 - std::exp(-fTemp2))) : fSlow0 * fTemp0 * (fSlow5 * fTemp0 + 0.5) + 1.0) - fSlow4);
			double fTemp4 = fSlow0 * fTemp3;
			double fTemp5 = std::max<double>(-6e+02, -fTemp4);
			output0[i0] = static_cast<FAUSTFLOAT>(-(fSlow6 * (((std::fabs(-fTemp4) > 0.0001) ? ((fTemp5 < -5e+01) ? -(fTemp5 * std::exp(fTemp5)) : fTemp5 / (1.0 - std::exp(-fTemp5))) : fSlow0 * fTemp3 * (fSlow5 * fTemp3 + -0.5) + 1.0) - fSlow4)));
		}
	}

};

#endif
