/* ------------------------------------------------------------
author: "brummer"
copyright: "(c)brummer 2008"
license: "BSD"
name: "Multi Band Distortion"
version: "0.01"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxGxDistortion -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxGxDistortion_H__
#define  __GxGxDistortion_H__

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
#define FAUSTCLASS GxGxDistortion
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

static double GxGxDistortion_faustpower2_f(double value) {
	return value * value;
}

class GxGxDistortion : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	int iVec0[2];
	FAUSTFLOAT fVslider1;
	double fRec0[2];
	FAUSTFLOAT fEntry0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT fEntry2;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fVslider2;
	double fVec1[2];
	FAUSTFLOAT fVslider3;
	double fRec10[2];
	double fRec11[2];
	double fRec9[3];
	double fVec2[2];
	double fConst8;
	double fConst9;
	double fConst10;
	double fConst11;
	double fConst12;
	double fRec8[2];
	double fRec7[2];
	double fRec6[3];
	double fVec3[2];
	double fRec5[2];
	double fRec4[3];
	double fVec4[2];
	double fRec3[2];
	double fRec2[3];
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT fVslider6;
	FAUSTFLOAT fVslider7;
	double fRec12[2];
	double fRec14[2];
	double fRec13[3];
	FAUSTFLOAT fVslider8;
	FAUSTFLOAT fVslider9;
	double fRec15[2];
	double fRec18[2];
	double fRec17[3];
	double fRec16[3];
	FAUSTFLOAT fVslider10;
	FAUSTFLOAT fVslider11;
	double fRec19[2];
	double fRec23[2];
	double fRec22[3];
	double fRec21[3];
	double fRec20[3];
	FAUSTFLOAT fVslider12;
	FAUSTFLOAT fVslider13;
	double fRec24[2];
	double fVec5[2];
	double fConst13;
	double fConst14;
	double fConst15;
	double fRec1[2];
	
 public:
	GxGxDistortion() {
	}
	
	GxGxDistortion(const GxGxDistortion&) = default;
	
	virtual ~GxGxDistortion() = default;
	
	GxGxDistortion& operator=(const GxGxDistortion&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "brummer");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Distortion");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxGxDistortion -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("copyright", "(c)brummer 2008");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-gx-distortion.dsp");
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
		m->declare("groups", "resonator[Distortion resonator]");
		m->declare("license", "BSD");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/cubicnl:author", "Julius O. Smith III");
		m->declare("misceffects.lib/cubicnl:license", "LicenseRef-STK-4.3");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "Multi Band Distortion");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "Distortion");
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
		fConst1 = 3.141592653589793 / fConst0;
		fConst2 = std::tan(47123.8898038469 / fConst0);
		fConst3 = 2.0 * (1.0 - 1.0 / GxGxDistortion_faustpower2_f(fConst2));
		fConst4 = 1.0 / fConst2;
		fConst5 = (fConst4 + -1.414213562373095) / fConst2 + 1.0;
		fConst6 = (fConst4 + 1.414213562373095) / fConst2 + 1.0;
		fConst7 = 1.0 / fConst6;
		fConst8 = std::tan(97.38937226128358 / fConst0);
		fConst9 = 1.0 / (fConst8 * fConst6);
		fConst10 = 1.0 / fConst8;
		fConst11 = 1.0 - fConst10;
		fConst12 = 1.0 / (fConst10 + 1.0);
		fConst13 = 1.0 / std::tan(20517.741620594938 / fConst0);
		fConst14 = 1.0 - fConst13;
		fConst15 = 1.0 / (fConst13 + 1.0);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(1e+02);
		fVslider1 = static_cast<FAUSTFLOAT>(2.0);
		fEntry0 = static_cast<FAUSTFLOAT>(2.5e+02);
		fEntry1 = static_cast<FAUSTFLOAT>(6.5e+02);
		fEntry2 = static_cast<FAUSTFLOAT>(1.25e+03);
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider2 = static_cast<FAUSTFLOAT>(0.12);
		fVslider3 = static_cast<FAUSTFLOAT>(1.0);
		fVslider4 = static_cast<FAUSTFLOAT>(1.0);
		fVslider5 = static_cast<FAUSTFLOAT>(0.64);
		fVslider6 = static_cast<FAUSTFLOAT>(0.0);
		fVslider7 = static_cast<FAUSTFLOAT>(1e+01);
		fVslider8 = static_cast<FAUSTFLOAT>(1.0);
		fVslider9 = static_cast<FAUSTFLOAT>(1e+01);
		fVslider10 = static_cast<FAUSTFLOAT>(1.0);
		fVslider11 = static_cast<FAUSTFLOAT>(1e+01);
		fVslider12 = static_cast<FAUSTFLOAT>(1.0);
		fVslider13 = static_cast<FAUSTFLOAT>(1e+01);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec0[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fVec1[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec10[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec11[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec9[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec2[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec8[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec7[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec6[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fVec3[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec5[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 3; l12 = faust_wrap_add(l12, 1)) {
			fRec4[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fVec4[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec3[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 3; l15 = faust_wrap_add(l15, 1)) {
			fRec2[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec12[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec14[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 3; l18 = faust_wrap_add(l18, 1)) {
			fRec13[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec15[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec18[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 3; l21 = faust_wrap_add(l21, 1)) {
			fRec17[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 3; l22 = faust_wrap_add(l22, 1)) {
			fRec16[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec19[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec23[l24] = 0.0;
		}
		for (int l25 = 0; l25 < 3; l25 = faust_wrap_add(l25, 1)) {
			fRec22[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 3; l26 = faust_wrap_add(l26, 1)) {
			fRec21[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 3; l27 = faust_wrap_add(l27, 1)) {
			fRec20[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec24[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fVec5[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec1[l30] = 0.0;
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
	
	virtual GxGxDistortion* clone() {
		return new GxGxDistortion(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Multi Band Distortion");
		ui_interface->addVerticalSlider("drive", &fVslider5, FAUSTFLOAT(0.64), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addVerticalSlider("gain", &fVslider1, FAUSTFLOAT(2.0), FAUSTFLOAT(-1e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider12, "name", "high");
		ui_interface->addVerticalSlider("high_drive", &fVslider12, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider13, "name", "high");
		ui_interface->addVerticalSlider("high_gain", &fVslider13, FAUSTFLOAT(1e+01), FAUSTFLOAT(-1e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("level", &fVslider6, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(0.5), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider4, "name", "low");
		ui_interface->addVerticalSlider("low_drive", &fVslider4, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider7, "name", "low");
		ui_interface->addVerticalSlider("low_gain", &fVslider7, FAUSTFLOAT(1e+01), FAUSTFLOAT(-1e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider10, "name", "middle h.");
		ui_interface->addVerticalSlider("middle_h_drive", &fVslider10, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider11, "name", "middle h.");
		ui_interface->addVerticalSlider("middle_h_gain", &fVslider11, FAUSTFLOAT(1e+01), FAUSTFLOAT(-1e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider8, "name", "middle l.");
		ui_interface->addVerticalSlider("middle_l_drive", &fVslider8, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider9, "name", "middle l.");
		ui_interface->addVerticalSlider("middle_l_gain", &fVslider9, FAUSTFLOAT(1e+01), FAUSTFLOAT(-1e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fCheckbox0, "name", "resonat");
		ui_interface->addCheckButton("resonator.on_off", &fCheckbox0);
		ui_interface->addNumEntry("split_high_freq", &fEntry2, FAUSTFLOAT(1.25e+03), FAUSTFLOAT(1.25e+03), FAUSTFLOAT(1.2e+04), FAUSTFLOAT(1e+01));
		ui_interface->addNumEntry("split_low_freq", &fEntry0, FAUSTFLOAT(2.5e+02), FAUSTFLOAT(2e+01), FAUSTFLOAT(6e+02), FAUSTFLOAT(1e+01));
		ui_interface->addNumEntry("split_middle_freq", &fEntry1, FAUSTFLOAT(6.5e+02), FAUSTFLOAT(6e+02), FAUSTFLOAT(1.25e+03), FAUSTFLOAT(1e+01));
		ui_interface->addVerticalSlider("trigger", &fVslider2, FAUSTFLOAT(0.12), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addVerticalSlider("vibrato", &fVslider3, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider0, "name", "wet/dry");
		ui_interface->declare(&fVslider0, "tooltip", "percentage of processed signal in output signal");
		ui_interface->addVerticalSlider("wet_dry", &fVslider0, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.01 * static_cast<double>(fVslider0);
		double fSlow1 = 1.0 - fSlow0;
		double fSlow2 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (static_cast<double>(fVslider1) + -1e+01));
		double fSlow3 = std::tan(fConst1 * static_cast<double>(fEntry0));
		double fSlow4 = GxGxDistortion_faustpower2_f(fSlow3);
		double fSlow5 = 2.0 * (1.0 - 1.0 / fSlow4);
		double fSlow6 = 1.0 / fSlow3;
		double fSlow7 = (fSlow6 + -1.0000000000000004) / fSlow3 + 1.0;
		double fSlow8 = (fSlow6 + 1.0000000000000004) / fSlow3 + 1.0;
		double fSlow9 = 1.0 / fSlow8;
		double fSlow10 = std::tan(fConst1 * static_cast<double>(fEntry1));
		double fSlow11 = GxGxDistortion_faustpower2_f(fSlow10);
		double fSlow12 = 2.0 * (1.0 - 1.0 / fSlow11);
		double fSlow13 = 1.0 / fSlow10;
		double fSlow14 = (fSlow13 + -1.0000000000000004) / fSlow10 + 1.0;
		double fSlow15 = (fSlow13 + 1.0000000000000004) / fSlow10 + 1.0;
		double fSlow16 = 1.0 / fSlow15;
		double fSlow17 = std::tan(fConst1 * static_cast<double>(fEntry2));
		double fSlow18 = GxGxDistortion_faustpower2_f(fSlow17);
		double fSlow19 = 2.0 * (1.0 - 1.0 / fSlow18);
		double fSlow20 = 1.0 / fSlow17;
		double fSlow21 = (fSlow20 + -1.0000000000000004) / fSlow17 + 1.0;
		double fSlow22 = (fSlow20 + 1.0000000000000004) / fSlow17 + 1.0;
		double fSlow23 = 1.0 / fSlow22;
		int iSlow24 = static_cast<int>(static_cast<double>(fCheckbox0));
		double fSlow25 = 1.0 - static_cast<double>(fVslider2);
		double fSlow26 = static_cast<double>(fVslider3);
		int iSlow27 = static_cast<int>(std::min<double>(4096.0, std::max<double>(0.0, fSlow26)));
		int iSlow28 = static_cast<int>(std::min<double>(4096.0, std::max<double>(0.0, fSlow26 + -1.0)));
		double fSlow29 = 1.0 - fSlow20;
		double fSlow30 = 1.0 / (fSlow20 + 1.0);
		double fSlow31 = 1.0 - fSlow13;
		double fSlow32 = fSlow13 + 1.0;
		double fSlow33 = 1.0 / fSlow32;
		double fSlow34 = 1.0 - fSlow6;
		double fSlow35 = fSlow6 + 1.0;
		double fSlow36 = 1.0 / fSlow35;
		double fSlow37 = static_cast<double>(fVslider5);
		double fSlow38 = std::pow(1e+01, 2.0 * fSlow37 * static_cast<double>(fVslider4)) / fSlow8;
		double fSlow39 = static_cast<double>(fVslider6);
		double fSlow40 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (static_cast<double>(fVslider7) + -1e+01));
		double fSlow41 = std::pow(1e+01, 2.0 * fSlow37 * static_cast<double>(fVslider8)) / (fSlow4 * fSlow8);
		double fSlow42 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (static_cast<double>(fVslider9) + -1e+01));
		double fSlow43 = 1.0 - fSlow34 / fSlow3;
		double fSlow44 = 1.0 / (fSlow35 / fSlow3 + 1.0);
		double fSlow45 = 1.0 / (fSlow11 * fSlow15);
		double fSlow46 = std::pow(1e+01, 2.0 * fSlow37 * static_cast<double>(fVslider10));
		double fSlow47 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (static_cast<double>(fVslider11) + -1e+01));
		double fSlow48 = 1.0 - fSlow31 / fSlow10;
		double fSlow49 = 1.0 / (fSlow32 / fSlow10 + 1.0);
		double fSlow50 = 1.0 / (fSlow18 * fSlow22);
		double fSlow51 = std::pow(1e+01, 2.0 * fSlow37 * static_cast<double>(fVslider12));
		double fSlow52 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * (static_cast<double>(fVslider13) + -1e+01));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			iVec0[0] = 1;
			fRec0[0] = fSlow2 + 0.999 * fRec0[1];
			double fTemp1 = fSlow0 * fTemp0;
			double fTemp2 = fTemp1 + fSlow25 * fRec10[1];
			fVec1[0] = fTemp2;
			fRec10[0] = 0.5 * (fVec1[iSlow28] + fVec1[iSlow27]);
			fRec11[0] = 1e-20 * static_cast<double>(faust_wrap_sub(1, iVec0[1])) - fRec11[1];
			fRec9[0] = fRec11[0] + ((iSlow24) ? fRec10[0] : fTemp1) - fConst7 * (fConst5 * fRec9[2] + fConst3 * fRec9[1]);
			double fTemp3 = fRec9[2] + fRec9[0] + 2.0 * fRec9[1];
			fVec2[0] = fTemp3;
			fRec8[0] = -(fConst12 * (fConst11 * fRec8[1] - fConst9 * (fTemp3 - fVec2[1])));
			fRec7[0] = -(fSlow30 * (fSlow29 * fRec7[1] - (fRec8[0] + fRec8[1])));
			fRec6[0] = fRec7[0] - fSlow23 * (fSlow21 * fRec6[2] + fSlow19 * fRec6[1]);
			double fTemp4 = fSlow23 * (fRec6[2] + fRec6[0] + 2.0 * fRec6[1]);
			fVec3[0] = fTemp4;
			fRec5[0] = -(fSlow33 * (fSlow31 * fRec5[1] - (fTemp4 + fVec3[1])));
			fRec4[0] = fRec5[0] - fSlow16 * (fSlow14 * fRec4[2] + fSlow12 * fRec4[1]);
			double fTemp5 = fSlow16 * (fRec4[2] + fRec4[0] + 2.0 * fRec4[1]);
			fVec4[0] = fTemp5;
			fRec3[0] = -(fSlow36 * (fSlow34 * fRec3[1] - (fTemp5 + fVec4[1])));
			fRec2[0] = fRec3[0] - fSlow9 * (fSlow7 * fRec2[2] + fSlow5 * fRec2[1]);
			double fTemp6 = std::max<double>(-1.0, std::min<double>(1.0, fSlow39 + fSlow38 * (fRec2[2] + fRec2[0] + 2.0 * fRec2[1])));
			fRec12[0] = fSlow40 + 0.999 * fRec12[1];
			fRec14[0] = -(fSlow36 * (fSlow34 * fRec14[1] - fSlow6 * (fTemp5 - fVec4[1])));
			fRec13[0] = fRec14[0] - fSlow9 * (fSlow7 * fRec13[2] + fSlow5 * fRec13[1]);
			double fTemp7 = std::max<double>(-1.0, std::min<double>(1.0, fSlow39 + fSlow41 * (fRec13[2] + (fRec13[0] - 2.0 * fRec13[1]))));
			fRec15[0] = fSlow42 + 0.999 * fRec15[1];
			double fTemp8 = fSlow5 * fRec16[1];
			fRec18[0] = -(fSlow33 * (fSlow31 * fRec18[1] - fSlow13 * (fTemp4 - fVec3[1])));
			fRec17[0] = fRec18[0] - fSlow16 * (fSlow14 * fRec17[2] + fSlow12 * fRec17[1]);
			fRec16[0] = fSlow45 * (fRec17[2] + (fRec17[0] - 2.0 * fRec17[1])) - fSlow44 * (fSlow43 * fRec16[2] + fTemp8);
			double fTemp9 = std::max<double>(-1.0, std::min<double>(1.0, fSlow39 + fSlow46 * (fRec16[2] + fSlow44 * (fTemp8 + fSlow43 * fRec16[0]))));
			fRec19[0] = fSlow47 + 0.999 * fRec19[1];
			double fTemp10 = fSlow5 * fRec20[1];
			double fTemp11 = fSlow12 * fRec21[1];
			fRec23[0] = -(fSlow30 * (fSlow29 * fRec23[1] - fSlow20 * (fRec8[0] - fRec8[1])));
			fRec22[0] = fRec23[0] - fSlow23 * (fSlow21 * fRec22[2] + fSlow19 * fRec22[1]);
			fRec21[0] = fSlow50 * (fRec22[2] + (fRec22[0] - 2.0 * fRec22[1])) - fSlow49 * (fSlow48 * fRec21[2] + fTemp11);
			fRec20[0] = fRec21[2] + fSlow49 * (fTemp11 + fSlow48 * fRec21[0]) - fSlow44 * (fSlow43 * fRec20[2] + fTemp10);
			double fTemp12 = std::max<double>(-1.0, std::min<double>(1.0, fSlow39 + fSlow51 * (fRec20[2] + fSlow44 * (fTemp10 + fSlow43 * fRec20[0]))));
			fRec24[0] = fSlow52 + 0.999 * fRec24[1];
			double fTemp13 = fRec24[0] * fTemp12 * (1.0 - 0.3333333333333333 * GxGxDistortion_faustpower2_f(fTemp12)) + fRec19[0] * fTemp9 * (1.0 - 0.3333333333333333 * GxGxDistortion_faustpower2_f(fTemp9)) + fRec15[0] * fTemp7 * (1.0 - 0.3333333333333333 * GxGxDistortion_faustpower2_f(fTemp7)) + fRec12[0] * fTemp6 * (1.0 - 0.3333333333333333 * GxGxDistortion_faustpower2_f(fTemp6));
			fVec5[0] = fTemp13;
			fRec1[0] = -(fConst15 * (fConst14 * fRec1[1] - (fTemp13 + fVec5[1])));
			output0[i0] = static_cast<FAUSTFLOAT>(fRec1[0] * fRec0[0] + fSlow1 * fTemp0);
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			fVec1[1] = fVec1[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fVec2[1] = fVec2[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fVec3[1] = fVec3[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fVec4[1] = fVec4[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec12[1] = fRec12[0];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec15[1] = fRec15[0];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec19[1] = fRec19[0];
			fRec23[1] = fRec23[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec24[1] = fRec24[0];
			fVec5[1] = fVec5[0];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
