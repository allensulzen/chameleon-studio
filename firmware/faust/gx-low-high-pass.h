/* ------------------------------------------------------------
author: "brummer"
copyright: "(c)brummer 2008"
license: "BSD"
name: "low high pass"
version: "0.01"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxLowHighPass -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxLowHighPass_H__
#define  __GxLowHighPass_H__

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
#define FAUSTCLASS GxLowHighPass
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

static double GxLowHighPass_faustpower2_f(double value) {
	return value * value;
}

class GxLowHighPass : public chdsp {
	
 private:
	
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fCheckbox1;
	int iVec0[2];
	double fRec2[2];
	double fVec1[2];
	FAUSTFLOAT fEntry0;
	int fSampleRate;
	double fConst0;
	double fRec1[2];
	FAUSTFLOAT fEntry1;
	double fRec0[2];
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	double fVec2[2];
	double fRec6[2];
	double fVec3[2];
	double fRec5[2];
	double fRec4[3];
	double fRec3[3];
	
 public:
	GxLowHighPass() {
	}
	
	GxLowHighPass(const GxLowHighPass&) = default;
	
	virtual ~GxLowHighPass() = default;
	
	GxLowHighPass& operator=(const GxLowHighPass&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "brummer");
		m->declare("category", "Tone Control");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxLowHighPass -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("copyright", "(c)brummer 2008");
		m->declare("filename", "gx-low-high-pass.dsp");
		m->declare("filters.lib/dcblockerat:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblockerat:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblockerat:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "LicenseRef-STK-4.3");
		m->declare("groups", ".low_high_pass.lhp[low_highpass], .low_high_pass.lhc[low_highcutoff]");
		m->declare("id", "low_highpass");
		m->declare("license", "BSD");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/speakerbp:author", "Julius O. Smith III");
		m->declare("misceffects.lib/speakerbp:license", "LicenseRef-STK-4.3");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "low high pass");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "L/H/Filter");
		m->declare("version", "0.01");
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
		fConst0 = 3.141592653589793 / std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0);
		fCheckbox1 = static_cast<FAUSTFLOAT>(0.0);
		fEntry0 = static_cast<FAUSTFLOAT>(5e+03);
		fEntry1 = static_cast<FAUSTFLOAT>(1.3e+02);
		fVslider0 = static_cast<FAUSTFLOAT>(5e+03);
		fVslider1 = static_cast<FAUSTFLOAT>(1.3e+02);
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
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec0[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fVec2[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec6[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fVec3[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec5[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec4[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec3[l10] = 0.0;
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
	
	virtual GxLowHighPass* clone() {
		return new GxLowHighPass(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("low high pass");
		ui_interface->openHorizontalBox(".low_high_pass.lhc");
		ui_interface->declare(&fVslider0, "name", "high freq");
		ui_interface->declare(&fVslider0, "tooltip", "high-freq cutoff Hz");
		ui_interface->addVerticalSlider("highfreq", &fVslider0, FAUSTFLOAT(5e+03), FAUSTFLOAT(1e+03), FAUSTFLOAT(1.2e+04), FAUSTFLOAT(1e+01));
		ui_interface->declare(&fVslider1, "name", "low freq");
		ui_interface->declare(&fVslider1, "tooltip", "low-freq cutoff Hz");
		ui_interface->addVerticalSlider("lowfreq", &fVslider1, FAUSTFLOAT(1.3e+02), FAUSTFLOAT(2e+01), FAUSTFLOAT(1e+03), FAUSTFLOAT(1e+01));
		ui_interface->declare(&fCheckbox0, "name", "low highcutoff");
		ui_interface->addCheckButton("onoff", &fCheckbox0);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox(".low_high_pass.lhp");
		ui_interface->declare(&fEntry1, "name", "high freq");
		ui_interface->addNumEntry("high_freq", &fEntry1, FAUSTFLOAT(1.3e+02), FAUSTFLOAT(2e+01), FAUSTFLOAT(7.04e+03), FAUSTFLOAT(1e+01));
		ui_interface->declare(&fEntry0, "name", "low freq");
		ui_interface->addNumEntry("low_freq", &fEntry0, FAUSTFLOAT(5e+03), FAUSTFLOAT(2e+01), FAUSTFLOAT(1.2e+04), FAUSTFLOAT(1e+01));
		ui_interface->declare(&fCheckbox1, "name", "low fi.highpass");
		ui_interface->addCheckButton("on_off", &fCheckbox1);
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		int iSlow0 = static_cast<int>(static_cast<double>(fCheckbox0));
		int iSlow1 = static_cast<int>(static_cast<double>(fCheckbox1));
		double fSlow2 = 1.0 / std::tan(fConst0 * static_cast<double>(fEntry0));
		double fSlow3 = 1.0 - fSlow2;
		double fSlow4 = 1.0 / (fSlow2 + 1.0);
		double fSlow5 = 1.0 / std::tan(fConst0 * static_cast<double>(fEntry1));
		double fSlow6 = 1.0 - fSlow5;
		double fSlow7 = 1.0 / (fSlow5 + 1.0);
		double fSlow8 = std::tan(fConst0 * static_cast<double>(fVslider0));
		double fSlow9 = 2.0 * (1.0 - 1.0 / GxLowHighPass_faustpower2_f(fSlow8));
		double fSlow10 = 1.0 / fSlow8;
		double fSlow11 = (fSlow10 + -0.7653668647301795) / fSlow8 + 1.0;
		double fSlow12 = 1.0 / ((fSlow10 + 0.7653668647301795) / fSlow8 + 1.0);
		double fSlow13 = (fSlow10 + -1.8477590650225735) / fSlow8 + 1.0;
		double fSlow14 = 1.0 / ((fSlow10 + 1.8477590650225735) / fSlow8 + 1.0);
		double fSlow15 = fConst0 * static_cast<double>(fVslider1);
		double fSlow16 = 1.0 / (fSlow15 + 1.0);
		double fSlow17 = 1.0 - fSlow15;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			iVec0[0] = 1;
			fRec2[0] = 1e-20 * static_cast<double>(faust_wrap_sub(1, iVec0[1])) - fRec2[1];
			double fTemp1 = fTemp0 + fRec2[0];
			fVec1[0] = fTemp1;
			fRec1[0] = -(fSlow4 * (fSlow3 * fRec1[1] - (fTemp1 + fVec1[1])));
			fRec0[0] = -(fSlow7 * (fSlow6 * fRec0[1] - fSlow5 * (fRec1[0] - fRec1[1])));
			double fTemp2 = ((iSlow1) ? fRec0[0] : fTemp0);
			double fTemp3 = fRec2[0] + fTemp2;
			fVec2[0] = fSlow16 * fTemp3;
			fRec6[0] = fSlow16 * (fTemp3 + fSlow17 * fRec6[1]) - fVec2[1];
			fVec3[0] = fSlow16 * fRec6[0];
			fRec5[0] = fSlow16 * (fRec6[0] + fSlow17 * fRec5[1]) - fVec3[1];
			fRec4[0] = fRec5[0] - fSlow14 * (fSlow13 * fRec4[2] + fSlow9 * fRec4[1]);
			fRec3[0] = fSlow14 * (fRec4[2] + fRec4[0] + 2.0 * fRec4[1]) - fSlow12 * (fSlow11 * fRec3[2] + fSlow9 * fRec3[1]);
			output0[i0] = static_cast<FAUSTFLOAT>(((iSlow0) ? fSlow12 * (fRec3[2] + fRec3[0] + 2.0 * fRec3[1]) : fTemp2));
			iVec0[1] = iVec0[0];
			fRec2[1] = fRec2[0];
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			fVec2[1] = fVec2[0];
			fRec6[1] = fRec6[0];
			fVec3[1] = fVec3[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
