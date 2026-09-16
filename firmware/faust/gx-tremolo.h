/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Tremolo"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTremolo -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxTremolo_H__
#define  __GxTremolo_H__

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
#define FAUSTCLASS GxTremolo
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


class GxTremolo : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fVslider0;
	double fConst2;
	int iRec2[2];
	int iRec1[2];
	double fConst3;
	double fRec5[2];
	double fRec4[2];
	double fRec3[2];
	FAUSTFLOAT fVslider1;
	double fRec0[2];
	FAUSTFLOAT fVslider2;
	
 public:
	GxTremolo() {
	}
	
	GxTremolo(const GxTremolo&) = default;
	
	virtual ~GxTremolo() = default;
	
	GxTremolo& operator=(const GxTremolo&) = default;
	
	void metadata(Meta* m) { 
		m->declare("category", "Modulation");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTremolo -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-tremolo.dsp");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Tremolo");
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
		fConst1 = 1.0 / fConst0;
		fConst2 = 0.5 * fConst0;
		fConst3 = 6.283185307179586 / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider0 = static_cast<FAUSTFLOAT>(5.0);
		fVslider1 = static_cast<FAUSTFLOAT>(0.5);
		fVslider2 = static_cast<FAUSTFLOAT>(1e+02);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iRec2[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			iRec1[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec5[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec0[l6] = 0.0;
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
	
	virtual GxTremolo* clone() {
		return new GxTremolo(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Tremolo");
		ui_interface->declare(&fCheckbox0, "enum", "os.triangle|sine");
		ui_interface->addCheckButton("SINE", &fCheckbox0);
		ui_interface->addVerticalSlider("depth", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addVerticalSlider("freq", &fVslider0, FAUSTFLOAT(5.0), FAUSTFLOAT(0.1), FAUSTFLOAT(5e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider2, "name", "wet/dry");
		ui_interface->declare(&fVslider2, "tooltip", "percentage of processed signal in output signal");
		ui_interface->addVerticalSlider("wet_dry", &fVslider2, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		int iSlow0 = static_cast<int>(static_cast<double>(fCheckbox0));
		double fSlow1 = static_cast<double>(fVslider0);
		int iSlow2 = static_cast<int>(fConst2 / fSlow1);
		double fSlow3 = 1.0 / static_cast<double>(iSlow2);
		double fSlow4 = fConst3 * fSlow1;
		double fSlow5 = static_cast<double>(fVslider1);
		double fSlow6 = static_cast<double>(fVslider2);
		double fSlow7 = 27.0 * fSlow6;
		double fSlow8 = 1.0 - 0.01 * fSlow6;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			double fTemp0 = fRec0[1] * (1.0 - fConst1 / (fConst1 + 0.06 * std::exp(-(2.4849066497880004 * fRec0[1]))));
			iRec2[0] = ((iRec2[1] > 0) ? faust_wrap_add(faust_wrap_mul(2, iRec1[1] < iSlow2), -1) : faust_wrap_sub(1, faust_wrap_mul(2, iRec1[1] > 0)));
			iRec1[0] = faust_wrap_add(iRec2[0], iRec1[1]);
			fRec5[0] = fRec5[1] - fSlow4 * fRec3[1];
			fRec4[0] = fSlow4 * fRec5[0] + static_cast<double>(faust_wrap_sub(1, iVec0[1])) + fRec4[1];
			fRec3[0] = fRec4[0];
			fRec0[0] = fTemp0 + fConst1 * (std::pow(1.0 - fSlow5 * (1.0 - ((iSlow0) ? std::max<double>(0.0, 0.5 * (fRec3[0] + 1.0)) : fSlow3 * static_cast<double>(iRec1[0]))), 1.9) / (fConst1 + 0.06 * std::exp(-(2.4849066497880004 * fTemp0))));
			output0[i0] = static_cast<FAUSTFLOAT>(static_cast<double>(input0[i0]) * (fSlow8 + fSlow7 / (std::exp(13.815510557964274 / std::log(8.551967507929417 * fRec0[0] + 2.718281828459045)) + 2.7e+03)));
			iVec0[1] = iVec0[0];
			iRec2[1] = iRec2[0];
			iRec1[1] = iRec1[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
