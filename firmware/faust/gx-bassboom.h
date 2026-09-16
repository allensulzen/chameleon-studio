/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Bass Boom"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBassboom -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxBassboom_H__
#define  __GxBassboom_H__

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
#define FAUSTCLASS GxBassboom
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

static double GxBassboom_faustpower2_f(double value) {
	return value * value;
}

class GxBassboom : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fRec2[2];
	double fVec1[2];
	double fConst7;
	double fConst8;
	double fRec1[2];
	double fRec0[3];
	FAUSTFLOAT fHslider0;
	double fRec3[2];
	double fRec5[2];
	double fRec4[3];
	double fConst9;
	FAUSTFLOAT fVslider0;
	double fRec6[2];
	
 public:
	GxBassboom() {
	}
	
	GxBassboom(const GxBassboom&) = default;
	
	virtual ~GxBassboom() = default;
	
	GxBassboom& operator=(const GxBassboom&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Distortion");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBassboom -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Sub Bass Booster");
		m->declare("filename", "gx-bassboom.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass0_highpass1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "bboom");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Bass Boom");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "B Boom");
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
		fConst0 = std::tan(345.57519189487726 / std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate))));
		fConst1 = GxBassboom_faustpower2_f(fConst0);
		fConst2 = 2.0 * (1.0 - 1.0 / fConst1);
		fConst3 = 1.0 / fConst0;
		fConst4 = (fConst3 + -1.0000000000000004) / fConst0 + 1.0;
		fConst5 = (fConst3 + 1.0000000000000004) / fConst0 + 1.0;
		fConst6 = 1.0 / fConst5;
		fConst7 = 1.0 - fConst3;
		fConst8 = 1.0 / (fConst3 + 1.0);
		fConst9 = 1.0 / (fConst1 * fConst5);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.33);
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec2[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fVec1[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec0[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec5[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec4[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec6[l8] = 0.0;
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
	
	virtual GxBassboom* clone() {
		return new GxBassboom(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Bass Boom");
		ui_interface->declare(&fHslider0, "tooltip", "Amount of SubBass Harmonics");
		ui_interface->addHorizontalSlider("Drive", &fHslider0, FAUSTFLOAT(0.33), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addVerticalSlider("Gain", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(-4e+01), FAUSTFLOAT(4.0), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.0010000000000000009 * static_cast<double>(fHslider0);
		double fSlow1 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider0));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec2[0] = 1e-20 * static_cast<double>(faust_wrap_sub(1, iVec0[1])) - fRec2[1];
			double fTemp0 = static_cast<double>(input0[i0]) + fRec2[0];
			fVec1[0] = fTemp0;
			fRec1[0] = -(fConst8 * (fConst7 * fRec1[1] - (fTemp0 + fVec1[1])));
			fRec0[0] = fRec1[0] - fConst6 * (fConst4 * fRec0[2] + fConst2 * fRec0[1]);
			fRec3[0] = fSlow0 + 0.999 * fRec3[1];
			double fTemp1 = std::pow(1e+01, 1.5 * fRec3[0]);
			double fTemp2 = std::max<double>(-1.0, std::min<double>(1.0, fConst6 * fTemp1 * (fRec0[2] + fRec0[0] + 2.0 * fRec0[1])));
			double fTemp3 = 4.0 * fTemp2;
			double fTemp4 = std::exp(fTemp3);
			fRec5[0] = -(fConst8 * (fConst7 * fRec5[1] - fConst3 * (fTemp0 - fVec1[1])));
			fRec4[0] = fRec5[0] - fConst6 * (fConst4 * fRec4[2] + fConst2 * fRec4[1]);
			fRec6[0] = fSlow1 + 0.999 * fRec6[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fRec6[0] * (fConst9 * (fRec4[2] + (fRec4[0] - 2.0 * fRec4[1])) + 0.25 * ((fTemp4 - std::exp(-(4.8 * fTemp2))) * std::max<double>(1.0, 0.4 / fTemp1) / (fTemp4 + std::exp(-fTemp3)))));
			iVec0[1] = iVec0[0];
			fRec2[1] = fRec2[0];
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
		}
	}

};

#endif
