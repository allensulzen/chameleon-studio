/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "gx-reso-tube"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxResoTube -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxResoTube_H__
#define  __GxResoTube_H__

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
#define FAUSTCLASS GxResoTube
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


class GxResoTube : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	double fVec0[2];
	FAUSTFLOAT fVslider1;
	double fRec0[2];
	FAUSTFLOAT fVslider2;
	int fSampleRate;
	
 public:
	GxResoTube() {
	}
	
	GxResoTube(const GxResoTube&) = default;
	
	virtual ~GxResoTube() = default;
	
	GxResoTube& operator=(const GxResoTube&) = default;
	
	void metadata(Meta* m) { 
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxResoTube -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-reso-tube.dsp");
		m->declare("id", "tube2");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "gx-reso-tube");
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
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(1.0);
		fVslider2 = static_cast<FAUSTFLOAT>(1.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
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
	
	virtual GxResoTube* clone() {
		return new GxResoTube(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("gx-reso-tube");
		ui_interface->declare(&fVslider2, "alias", "");
		ui_interface->declare(&fVslider2, "name", "tube");
		ui_interface->addVerticalSlider("fuzzy", &fVslider2, FAUSTFLOAT(1.0), FAUSTFLOAT(-3.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider0, "alias", "");
		ui_interface->addVerticalSlider("resonanz", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(0.9), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider1, "alias", "");
		ui_interface->addVerticalSlider("vibrato", &fVslider1, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fVslider0) + 0.09999999999999998;
		double fSlow1 = static_cast<double>(fVslider1);
		int iSlow2 = static_cast<int>(std::min<double>(4096.0, std::max<double>(0.0, 1.0 - fSlow1)));
		int iSlow3 = static_cast<int>(std::min<double>(4096.0, std::max<double>(0.0, -fSlow1)));
		double fSlow4 = 0.5 * static_cast<double>(fVslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			double fTemp1 = fTemp0 + 1e-20;
			double fTemp2 = fSlow0 * fRec0[1] + 0.5 * (fTemp1 * (2.0 - std::fabs(fTemp1)) + (-1e-20 - fTemp0));
			fVec0[0] = fTemp2;
			fRec0[0] = 0.5 * (fVec0[iSlow3] + fVec0[iSlow2]);
			output0[i0] = static_cast<FAUSTFLOAT>(std::max<double>(-0.7, std::min<double>(0.7, fTemp0 + (1e-20 - std::max<double>(-0.7, std::min<double>(0.7, fSlow4 * fRec0[0]))))));
			fVec0[1] = fVec0[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
