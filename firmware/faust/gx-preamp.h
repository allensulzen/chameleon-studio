/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "gx-preamp"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxPreamp -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxPreamp_H__
#define  __GxPreamp_H__

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
#define FAUSTCLASS GxPreamp
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


class GxPreamp : public chdsp {
	
 private:
	
	double fVec0[3];
	int iVec1[2];
	double fRec0[2];
	FAUSTFLOAT fVslider0;
	double fVec2[3];
	int fSampleRate;
	
 public:
	GxPreamp() {
	}
	
	GxPreamp(const GxPreamp&) = default;
	
	virtual ~GxPreamp() = default;
	
	GxPreamp& operator=(const GxPreamp&) = default;
	
	void metadata(Meta* m) { 
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxPreamp -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-preamp.dsp");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("name", "gx-preamp");
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
		fVslider0 = static_cast<FAUSTFLOAT>(1.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 3; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec0[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fVec2[l3] = 0.0;
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
	
	virtual GxPreamp* clone() {
		return new GxPreamp(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("gx-preamp");
		ui_interface->declare(&fVslider0, "name", "drive");
		ui_interface->declare(&fVslider0, "tooltip", "Input level for pre-amp (higher level gives more distortion)");
		ui_interface->addVerticalSlider("atan", &fVslider0, FAUSTFLOAT(1.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fVslider0);
		double fSlow1 = 0.75 / std::atan(fSlow0);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			fVec0[0] = fTemp0;
			iVec1[0] = 1;
			double fTemp1 = fTemp0 + fVec0[1] + fVec0[2];
			fRec0[0] = 1e-20 * static_cast<double>(faust_wrap_sub(1, iVec1[1])) - fRec0[1];
			double fTemp2 = fTemp1 * (0.3333333333333333 - 0.016666666666666663 * fTemp1 - 0.016666666666666663 * fTemp1 * (fRec0[0] + 0.3333333333333333 * fTemp1));
			double fTemp3 = fSlow1 * std::atan(fSlow0 * fTemp2 * (1.5 - 0.5 * fTemp2 * (fRec0[0] + fTemp2)));
			fVec2[0] = fTemp3;
			output0[i0] = static_cast<FAUSTFLOAT>(0.3333333333333333 * (fTemp3 + fVec2[1] + fVec2[2]));
			fVec0[2] = fVec0[1];
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fRec0[1] = fRec0[0];
			fVec2[2] = fVec2[1];
			fVec2[1] = fVec2[0];
		}
	}

};

#endif
