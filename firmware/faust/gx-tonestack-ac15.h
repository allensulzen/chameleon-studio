/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "AC-15"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTonestackAc15 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxTonestackAc15_H__
#define  __GxTonestackAc15_H__

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
#define FAUSTCLASS GxTonestackAc15
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

static double GxTonestackAc15_faustpower2_f(double value) {
	return value * value;
}
static double GxTonestackAc15_faustpower3_f(double value) {
	return value * value * value;
}

class GxTonestackAc15 : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fRec0[4];
	FAUSTFLOAT fVslider2;
	double fConst3;
	
 public:
	GxTonestackAc15() {
	}
	
	GxTonestackAc15(const GxTonestackAc15&) = default;
	
	virtual ~GxTonestackAc15() = default;
	
	GxTonestackAc15& operator=(const GxTonestackAc15&) = default;
	
	void metadata(Meta* m) { 
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTonestackAc15 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-tonestack-ac15.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("gx-tonestack.dsp/chameleon_flags", "-double");
		m->declare("gx-tonestack.dsp/id", "tonestack_imp");
		m->declare("gx-tonestack.dsp/license", "GPL-2.0-or-later");
		m->declare("id", "AC-15");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "AC-15");
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
		fConst0 = 2.0 * std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = GxTonestackAc15_faustpower2_f(fConst0);
		fConst2 = GxTonestackAc15_faustpower3_f(fConst0);
		fConst3 = 3.0 * fConst2;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(0.5);
		fVslider2 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 4; l0 = faust_wrap_add(l0, 1)) {
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
	
	virtual GxTonestackAc15* clone() {
		return new GxTonestackAc15(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("AC-15");
		ui_interface->declare(&fVslider0, "alias", "");
		ui_interface->addVerticalSlider(".amp.tonestack.Bass", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider1, "alias", "");
		ui_interface->addVerticalSlider(".amp.tonestack.Middle", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider2, "alias", "");
		ui_interface->addVerticalSlider(".amp.tonestack.Treble", &fVslider2, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = std::exp(3.4 * (static_cast<double>(fVslider0) + -1.0));
		double fSlow1 = static_cast<double>(fVslider1);
		double fSlow2 = 0.00022854915600000004 * fSlow1;
		double fSlow3 = fConst1 * (fSlow1 * (0.00022854915600000004 * fSlow0 + 0.00012621831200000002 - fSlow2) + 0.00010719478000000002 * fSlow0 + 0.00010871476000000002);
		double fSlow4 = fSlow0 + 1.0;
		double fSlow5 = fSlow0 - fSlow1;
		double fSlow6 = fConst2 * (fSlow1 * (3.421299200000001e-08 * fSlow5 + 2.3521432000000005e-08) + 1.0691560000000003e-08 * fSlow4);
		double fSlow7 = 0.01034 * fSlow1;
		double fSlow8 = fConst0 * (fSlow7 + 0.022103400000000002 * fSlow0 + 0.036906800000000003);
		double fSlow9 = fSlow8 + fSlow6 + (-1.0 - fSlow3);
		double fSlow10 = fSlow8 + fSlow3;
		double fSlow11 = fSlow10 - 3.0 * (fSlow6 + 1.0);
		double fSlow12 = fSlow3 - (fSlow8 + 3.0 * (1.0 - fSlow6));
		double fSlow13 = 1.0 / (-1.0 - (fSlow10 + fSlow6));
		double fSlow14 = static_cast<double>(fVslider2);
		double fSlow15 = 3.421299200000001e-08 * fSlow1 * (fSlow5 + 1.0) + 1.0691560000000003e-08 * fSlow14 * (fSlow0 + (1.0 - fSlow1));
		double fSlow16 = fConst2 * fSlow15;
		double fSlow17 = fConst1 * (1.5199800000000001e-06 * fSlow14 + fSlow1 * (0.00022961831200000004 - fSlow2) + fSlow0 * (fSlow2 + 3.7947800000000004e-06) + 3.7947800000000004e-06);
		double fSlow18 = fConst0 * (fSlow7 + 0.0001034 * fSlow14 + 0.022103400000000002 * fSlow4);
		double fSlow19 = fSlow18 + fSlow17;
		double fSlow20 = fSlow19 + fSlow16;
		double fSlow21 = fSlow18 + fSlow16 - fSlow17;
		double fSlow22 = fConst3 * fSlow15;
		double fSlow23 = fSlow19 - fSlow22;
		double fSlow24 = fSlow17 + fSlow22 - fSlow18;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = static_cast<double>(input0[i0]) - fSlow13 * (fSlow12 * fRec0[1] + fSlow11 * fRec0[2] + fSlow9 * fRec0[3]);
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow13 * (fSlow24 * fRec0[1] + fSlow23 * fRec0[2] + fSlow21 * fRec0[3] - fSlow20 * fRec0[0]));
			for (int j0 = 3; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec0[j0] = fRec0[faust_wrap_sub(j0, 1)];
			}
		}
	}

};

#endif
