/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Bassbooster"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBassbooster -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxBassbooster_H__
#define  __GxBassbooster_H__

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
#define FAUSTCLASS GxBassbooster
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

static double GxBassbooster_faustpower2_f(double value) {
	return value * value;
}

class GxBassbooster : public chdsp {
	
 private:
	
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fRec0[3];
	FAUSTFLOAT fVslider0;
	
 public:
	GxBassbooster() {
	}
	
	GxBassbooster(const GxBassbooster&) = default;
	
	virtual ~GxBassbooster() = default;
	
	GxBassbooster& operator=(const GxBassbooster&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBassbooster -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-bassbooster.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("groups", ".bassbooster[Bassbooster]");
		m->declare("id", "amp.bass_boost");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Bassbooster");
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
		fConst0 = std::tan(376.99111843077515 / std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate))));
		fConst1 = GxBassbooster_faustpower2_f(fConst0);
		fConst2 = 2.0 * (fConst1 + -1.0);
		fConst3 = fConst0 * (fConst0 + -1.4142135623730951) + 1.0;
		fConst4 = 1.0 / (fConst0 * (fConst0 + 1.4142135623730951) + 1.0);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(1e+01);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 3; l0 = faust_wrap_add(l0, 1)) {
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
	
	virtual GxBassbooster* clone() {
		return new GxBassbooster(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Bassbooster");
		ui_interface->addVerticalSlider(".bassbooster.Level", &fVslider0, FAUSTFLOAT(1e+01), FAUSTFLOAT(0.5), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.5));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = std::pow(1e+01, 0.05 * static_cast<double>(fVslider0));
		double fSlow1 = fConst0 * fSlow0;
		double fSlow2 = std::sqrt(2.0 * fSlow0);
		double fSlow3 = 1.0 - fConst0 * (fSlow2 - fSlow1);
		double fSlow4 = 2.0 * (fConst1 * fSlow0 + -1.0);
		double fSlow5 = fConst0 * (fSlow2 + fSlow1) + 1.0;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = static_cast<double>(input0[i0]) - fConst4 * (fConst3 * fRec0[2] + fConst2 * fRec0[1]);
			output0[i0] = static_cast<FAUSTFLOAT>(fConst4 * (fSlow5 * fRec0[0] + fSlow4 * fRec0[1] + fSlow3 * fRec0[2]));
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
