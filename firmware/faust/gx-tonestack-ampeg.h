/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Ampeg"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTonestackAmpeg -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxTonestackAmpeg_H__
#define  __GxTonestackAmpeg_H__

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
#define FAUSTCLASS GxTonestackAmpeg
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

static double GxTonestackAmpeg_faustpower2_f(double value) {
	return value * value;
}
static double GxTonestackAmpeg_faustpower3_f(double value) {
	return value * value * value;
}

class GxTonestackAmpeg : public chdsp {
	
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
	GxTonestackAmpeg() {
	}
	
	GxTonestackAmpeg(const GxTonestackAmpeg&) = default;
	
	virtual ~GxTonestackAmpeg() = default;
	
	GxTonestackAmpeg& operator=(const GxTonestackAmpeg&) = default;
	
	void metadata(Meta* m) { 
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTonestackAmpeg -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-tonestack-ampeg.dsp");
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
		m->declare("id", "Ampeg");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Ampeg");
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
		fConst1 = GxTonestackAmpeg_faustpower2_f(fConst0);
		fConst2 = GxTonestackAmpeg_faustpower3_f(fConst0);
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
	
	virtual GxTonestackAmpeg* clone() {
		return new GxTonestackAmpeg(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Ampeg");
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
		double fSlow2 = 3.0896250000000005e-07 * fSlow1;
		double fSlow3 = fConst1 * (fSlow1 * (1.2358500000000002e-05 * fSlow0 + -1.361249999999999e-08 - fSlow2) + 1.8734760000000003e-05 * fSlow0 + 6.338090000000001e-07);
		double fSlow4 = 1.8198400000000004e-09 * fSlow0;
		double fSlow5 = 1.6037340000000005e-09 * fSlow0 - 4.0093350000000015e-11 * fSlow1;
		double fSlow6 = fConst2 * (fSlow1 * (fSlow5 + -5.40265e-12) + fSlow4 + 4.5496000000000015e-11);
		double fSlow7 = 0.022470000000000004 * fSlow0;
		double fSlow8 = 0.00055 * fSlow1;
		double fSlow9 = fConst0 * (fSlow8 + fSlow7 + 0.00208725);
		double fSlow10 = fSlow9 + fSlow6 + (-1.0 - fSlow3);
		double fSlow11 = fSlow9 + fSlow3;
		double fSlow12 = fSlow11 - 3.0 * (fSlow6 + 1.0);
		double fSlow13 = fSlow3 - (fSlow9 + 3.0 * (1.0 - fSlow6));
		double fSlow14 = 1.0 / (-1.0 - (fSlow11 + fSlow6));
		double fSlow15 = static_cast<double>(fVslider2);
		double fSlow16 = fSlow1 * (fSlow5 + 4.0093350000000015e-11) + fSlow15 * (fSlow4 + 4.5496000000000015e-11 * (1.0 - fSlow1));
		double fSlow17 = fConst2 * fSlow16;
		double fSlow18 = fConst1 * (1.6544000000000003e-07 * fSlow15 + fSlow1 * (3.735875000000001e-07 - fSlow2) + fSlow0 * (1.2358500000000002e-05 * fSlow1 + 3.24676e-06) + 8.1169e-08);
		double fSlow19 = fConst0 * (fSlow7 + fSlow8 + 0.00011750000000000001 * fSlow15 + 0.0005617500000000001);
		double fSlow20 = fSlow19 + fSlow18;
		double fSlow21 = fSlow20 + fSlow17;
		double fSlow22 = fSlow19 + fSlow17 - fSlow18;
		double fSlow23 = fConst3 * fSlow16;
		double fSlow24 = fSlow20 - fSlow23;
		double fSlow25 = fSlow18 + fSlow23 - fSlow19;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = static_cast<double>(input0[i0]) - fSlow14 * (fSlow13 * fRec0[1] + fSlow12 * fRec0[2] + fSlow10 * fRec0[3]);
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow14 * (fSlow25 * fRec0[1] + fSlow24 * fRec0[2] + fSlow22 * fRec0[3] - fSlow21 * fRec0[0]));
			for (int j0 = 3; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec0[j0] = fRec0[faust_wrap_sub(j0, 1)];
			}
		}
	}

};

#endif
