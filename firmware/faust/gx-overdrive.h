/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Overdrive"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxOverdrive -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxOverdrive_H__
#define  __GxOverdrive_H__

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
#define FAUSTCLASS GxOverdrive
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

static double GxOverdrive_faustpower2_f(double value) {
	return value * value;
}

class GxOverdrive : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	double fRec0[2];
	int fSampleRate;
	
 public:
	GxOverdrive() {
	}
	
	GxOverdrive(const GxOverdrive&) = default;
	
	virtual ~GxOverdrive() = default;
	
	GxOverdrive& operator=(const GxOverdrive&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Distortion");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxOverdrive -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-overdrive.dsp");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("name", "Overdrive");
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
		fVslider0 = static_cast<FAUSTFLOAT>(1e+02);
		fVslider1 = static_cast<FAUSTFLOAT>(1.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
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
	
	virtual GxOverdrive* clone() {
		return new GxOverdrive(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Overdrive");
		ui_interface->addVerticalSlider("drive", &fVslider1, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider0, "name", "wet/dry");
		ui_interface->declare(&fVslider0, "tooltip", "percentage of processed signal in output signal");
		ui_interface->addVerticalSlider("wet_dry", &fVslider0, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fVslider0);
		double fSlow1 = 0.01 * fSlow0;
		double fSlow2 = static_cast<double>(fVslider1);
		double fSlow3 = fSlow2 + -1.0;
		double fSlow4 = 0.0001 * GxOverdrive_faustpower2_f(fSlow0);
		double fSlow5 = 0.0010000000000000009 * std::pow(1e+01, -(0.025 * fSlow2));
		double fSlow6 = 1.0 - fSlow1;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			double fTemp1 = std::fabs(fSlow1 * fTemp0);
			fRec0[0] = fSlow5 + 0.999 * fRec0[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (fSlow6 + fSlow1 * (fRec0[0] * (fSlow2 + fTemp1) / (fSlow4 * GxOverdrive_faustpower2_f(fTemp0) + fSlow3 * fTemp1 + 1.0))));
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
