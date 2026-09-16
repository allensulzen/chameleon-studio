/* ------------------------------------------------------------
author: "brummer"
copyright: "(c)brummer 2008"
license: "BSD"
name: "3 Band EQ"
version: "0.01"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTonecontroll -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxTonecontroll_H__
#define  __GxTonecontroll_H__

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
#define FAUSTCLASS GxTonecontroll
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

static double GxTonecontroll_faustpower2_f(double value) {
	return value * value;
}

class GxTonecontroll : public chdsp {
	
 private:
	
	FAUSTFLOAT fCheckbox0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	double fConst11;
	double fConst12;
	double fConst13;
	double fVec0[2];
	double fConst14;
	double fConst15;
	double fRec3[2];
	double fRec2[3];
	double fVec1[2];
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fRec1[2];
	double fRec0[3];
	FAUSTFLOAT fVslider0;
	double fRec4[2];
	double fRec6[2];
	double fRec5[3];
	FAUSTFLOAT fVslider1;
	double fRec7[2];
	double fConst20;
	double fConst21;
	double fRec10[2];
	double fRec9[3];
	double fConst22;
	double fRec8[3];
	FAUSTFLOAT fVslider2;
	double fRec11[2];
	double fConst23;
	double fConst24;
	double fRec12[2];
	FAUSTFLOAT fVslider3;
	
 public:
	GxTonecontroll() {
	}
	
	GxTonecontroll(const GxTonecontroll&) = default;
	
	virtual ~GxTonecontroll() = default;
	
	GxTonecontroll& operator=(const GxTonecontroll&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "brummer");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Tone Control");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTonecontroll -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("copyright", "(c)brummer 2008");
		m->declare("filename", "gx-tonecontroll.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass_plus_lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass_plus_lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:license", "LicenseRef-STK-4.3");
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
		m->declare("id", "tonemodul");
		m->declare("license", "BSD");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "3 Band EQ");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
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
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = std::tan(1884.9555921538758 / fConst0);
		fConst2 = 1.0 / GxTonecontroll_faustpower2_f(fConst1);
		fConst3 = 2.0 * (1.0 - fConst2);
		fConst4 = 1.0 / fConst1;
		fConst5 = (fConst4 + -1.0000000000000004) / fConst1 + 1.0;
		fConst6 = 1.0 / ((fConst4 + 1.0000000000000004) / fConst1 + 1.0);
		fConst7 = std::tan(7539.822368615503 / fConst0);
		fConst8 = GxTonecontroll_faustpower2_f(fConst7);
		fConst9 = 2.0 * (1.0 - 1.0 / fConst8);
		fConst10 = 1.0 / fConst7;
		fConst11 = (fConst10 + -1.0000000000000004) / fConst7 + 1.0;
		fConst12 = (fConst10 + 1.0000000000000004) / fConst7 + 1.0;
		fConst13 = 1.0 / fConst12;
		fConst14 = 1.0 - fConst10;
		fConst15 = 1.0 / (fConst10 + 1.0);
		fConst16 = 1.0 / (fConst1 * fConst12);
		fConst17 = 1.0 - fConst4;
		fConst18 = fConst4 + 1.0;
		fConst19 = 1.0 / fConst18;
		fConst20 = 1.0 - fConst17 / fConst1;
		fConst21 = 1.0 / (fConst18 / fConst1 + 1.0);
		fConst22 = 1.0 / (fConst8 * fConst12);
		fConst23 = std::exp(-(0.2 / fConst0));
		fConst24 = std::exp(-(2e+02 / fConst0));
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider1 = static_cast<FAUSTFLOAT>(0.0);
		fVslider2 = static_cast<FAUSTFLOAT>(0.0);
		fVslider3 = static_cast<FAUSTFLOAT>(-2.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec3[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec1[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec0[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec4[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec6[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec5[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec7[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec10[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 3; l11 = faust_wrap_add(l11, 1)) {
			fRec9[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 3; l12 = faust_wrap_add(l12, 1)) {
			fRec8[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec11[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec12[l14] = 0.0;
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
	
	virtual GxTonecontroll* clone() {
		return new GxTonecontroll(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("3 Band EQ");
		ui_interface->addVerticalSlider("Bass", &fVslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-5.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.01));
		ui_interface->addVerticalSlider("Middle", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(-5.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.01));
		ui_interface->addCheckButton("ON", &fCheckbox0);
		ui_interface->addVerticalSlider("Treble", &fVslider2, FAUSTFLOAT(0.0), FAUSTFLOAT(-5.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider3, "name", "sharper");
		ui_interface->addVerticalSlider("sharper", &fVslider3, FAUSTFLOAT(-2.0), FAUSTFLOAT(-2.5), FAUSTFLOAT(5.0), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		int iSlow0 = static_cast<int>(static_cast<double>(fCheckbox0));
		double fSlow1 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider0));
		double fSlow2 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider1));
		double fSlow3 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider2));
		double fSlow4 = static_cast<double>(fVslider3);
		double fSlow5 = 5.0 * fSlow4;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			fVec0[0] = fTemp0;
			fRec3[0] = -(fConst15 * (fConst14 * fRec3[1] - (fTemp0 + fVec0[1])));
			fRec2[0] = fRec3[0] - fConst13 * (fConst11 * fRec2[2] + fConst9 * fRec2[1]);
			double fTemp1 = fRec2[2] + fRec2[0] + 2.0 * fRec2[1];
			fVec1[0] = fTemp1;
			fRec1[0] = -(fConst19 * (fConst17 * fRec1[1] - fConst16 * (fTemp1 - fVec1[1])));
			fRec0[0] = fRec1[0] - fConst6 * (fConst5 * fRec0[2] + fConst3 * fRec0[1]);
			fRec4[0] = fSlow1 + 0.999 * fRec4[1];
			fRec6[0] = -(fConst19 * (fConst17 * fRec6[1] - fConst13 * (fTemp1 + fVec1[1])));
			fRec5[0] = fRec6[0] - fConst6 * (fConst5 * fRec5[2] + fConst3 * fRec5[1]);
			fRec7[0] = fSlow2 + 0.999 * fRec7[1];
			double fTemp2 = fConst3 * fRec8[1];
			fRec10[0] = -(fConst15 * (fConst14 * fRec10[1] - fConst10 * (fTemp0 - fVec0[1])));
			fRec9[0] = fRec10[0] - fConst13 * (fConst11 * fRec9[2] + fConst9 * fRec9[1]);
			fRec8[0] = fConst22 * (fRec9[2] + (fRec9[0] - 2.0 * fRec9[1])) - fConst21 * (fConst20 * fRec8[2] + fTemp2);
			fRec11[0] = fSlow3 + 0.999 * fRec11[1];
			double fTemp3 = fRec11[0] * (fRec8[2] + fConst21 * (fTemp2 + fConst20 * fRec8[0])) + fConst6 * (fRec7[0] * (fRec5[2] + fRec5[0] + 2.0 * fRec5[1]) + fConst2 * fRec4[0] * (fRec0[2] + (fRec0[0] - 2.0 * fRec0[1])));
			double fTemp4 = std::max<double>(1.0, std::fabs(fTemp3));
			double fTemp5 = fConst24 * static_cast<double>(fRec12[1] < fTemp4) + fConst23 * static_cast<double>(fRec12[1] >= fTemp4);
			fRec12[0] = fRec12[1] * fTemp5 + fTemp4 * (1.0 - fTemp5);
			double fTemp6 = std::max<double>(0.0, fSlow5 + 2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec12[0])));
			double fTemp7 = std::min<double>(1.0, std::max<double>(0.0, 0.09522902580706599 * fTemp6));
			output0[i0] = static_cast<FAUSTFLOAT>(((iSlow0) ? fTemp3 * std::pow(1e+01, 0.05 * (fSlow4 - 2.0 * (fTemp6 * fTemp7 / (2.0 * fTemp7 + 1.0)))) : fTemp3));
			fVec0[1] = fVec0[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec7[1] = fRec7[0];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
		}
	}

};

#endif
