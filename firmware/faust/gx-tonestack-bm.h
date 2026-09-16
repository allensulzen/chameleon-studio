/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "gx-tonestack-bm"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTonestackBm -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxTonestackBm_H__
#define  __GxTonestackBm_H__

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
#define FAUSTCLASS GxTonestackBm
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

static double GxTonestackBm_faustpower2_f(double value) {
	return value * value;
}
static double GxTonestackBm_faustpower3_f(double value) {
	return value * value * value;
}

class GxTonestackBm : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fRec0[4];
	double fConst3;
	
 public:
	GxTonestackBm() {
	}
	
	GxTonestackBm(const GxTonestackBm&) = default;
	
	virtual ~GxTonestackBm() = default;
	
	GxTonestackBm& operator=(const GxTonestackBm&) = default;
	
	void metadata(Meta* m) { 
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTonestackBm -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-tonestack-bm.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "tonestack_bm");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "gx-tonestack-bm");
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
		fConst1 = GxTonestackBm_faustpower2_f(fConst0);
		fConst2 = GxTonestackBm_faustpower3_f(fConst0);
		fConst3 = 3.0 * fConst2;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
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
	
	virtual GxTonestackBm* clone() {
		return new GxTonestackBm(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("gx-tonestack-bm");
		ui_interface->declare(&fVslider0, "alias", "");
		ui_interface->addVerticalSlider(".amp.tonestack.tone", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fVslider0);
		double fSlow1 = std::exp(-(3.4 * fSlow0));
		double fSlow2 = fConst1 * (2.9272500000000005e-05 * fSlow1 + 5.441562499999999e-07);
		double fSlow3 = fConst2 * (1.7825000000000002e-09 * fSlow1 + 2.2281250000000004e-11);
		double fSlow4 = 0.02025 * fSlow1;
		double fSlow5 = fConst0 * (fSlow4 + 0.0030587500000000007);
		double fSlow6 = fSlow5 + fSlow3 + (-1.0 - fSlow2);
		double fSlow7 = fSlow5 + fSlow2;
		double fSlow8 = fSlow7 - 3.0 * (fSlow3 + 1.0);
		double fSlow9 = fSlow2 - (fSlow5 + 3.0 * (1.0 - fSlow3));
		double fSlow10 = 1.0 / (-1.0 - (fSlow7 + fSlow3));
		double fSlow11 = 3.825000000000001e-10 * fSlow1 + fSlow0 * (1.4000000000000001e-09 * fSlow1 + 1.7500000000000004e-11) + 4.7812500000000005e-12;
		double fSlow12 = fConst2 * fSlow11;
		double fSlow13 = fConst1 * (1.4e-07 * fSlow0 + 6.872500000000001e-06 * fSlow1 + 1.2415625e-07);
		double fSlow14 = fConst0 * (fSlow4 + 6.25e-05 * fSlow0 + 0.00075625);
		double fSlow15 = fSlow14 + fSlow13;
		double fSlow16 = fSlow15 + fSlow12;
		double fSlow17 = fSlow14 + fSlow12 - fSlow13;
		double fSlow18 = fConst3 * fSlow11;
		double fSlow19 = fSlow15 - fSlow18;
		double fSlow20 = fSlow13 + fSlow18 - fSlow14;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = static_cast<double>(input0[i0]) - fSlow10 * (fSlow9 * fRec0[1] + fSlow8 * fRec0[2] + fSlow6 * fRec0[3]);
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow10 * (fSlow20 * fRec0[1] + fSlow19 * fRec0[2] + fSlow17 * fRec0[3] - fSlow16 * fRec0[0]));
			for (int j0 = 3; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec0[j0] = fRec0[faust_wrap_sub(j0, 1)];
			}
		}
	}

};

#endif
