/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Phaser"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxPhaser -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxPhaser_H__
#define  __GxPhaser_H__

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
#define FAUSTCLASS GxPhaser
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

static double GxPhaser_faustpower4_f(double value) {
	return value * value * value * value;
}
static double GxPhaser_faustpower3_f(double value) {
	return value * value * value;
}
static double GxPhaser_faustpower2_f(double value) {
	return value * value;
}

class GxPhaser : public chdsp {
	
 private:
	
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int iVec0[2];
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec1[2];
	double fRec2[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	double fConst2;
	FAUSTFLOAT fHslider6;
	double fConst3;
	FAUSTFLOAT fHslider7;
	double fRec6[3];
	double fRec5[3];
	double fRec4[3];
	double fRec3[3];
	double fRec0[2];
	double fRec11[3];
	double fRec10[3];
	double fRec9[3];
	double fRec8[3];
	double fRec7[2];
	FAUSTFLOAT fCheckbox1;
	
 public:
	GxPhaser() {
	}
	
	GxPhaser(const GxPhaser&) = default;
	
	virtual ~GxPhaser() = default;
	
	GxPhaser& operator=(const GxPhaser&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Modulation");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxPhaser -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-phaser.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "phaser");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Phaser");
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
		fConst1 = 6.283185307179586 / fConst0;
		fConst2 = 1.0 / fConst0;
		fConst3 = 3.141592653589793 / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0);
		fHslider0 = static_cast<FAUSTFLOAT>(1.0);
		fHslider1 = static_cast<FAUSTFLOAT>(0.0);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5);
		fHslider3 = static_cast<FAUSTFLOAT>(1e+02);
		fHslider4 = static_cast<FAUSTFLOAT>(8e+02);
		fHslider5 = static_cast<FAUSTFLOAT>(1.5);
		fHslider6 = static_cast<FAUSTFLOAT>(1e+03);
		fHslider7 = static_cast<FAUSTFLOAT>(0.0);
		fCheckbox1 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fRec6[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec5[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec3[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec0[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec11[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec10[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec9[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 3; l11 = faust_wrap_add(l11, 1)) {
			fRec8[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec7[l12] = 0.0;
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
	
	virtual GxPhaser* clone() {
		return new GxPhaser(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Phaser");
		ui_interface->declare(&fHslider4, "unit", "Hz");
		ui_interface->addHorizontalSlider("MaxNotch1Freq", &fHslider4, FAUSTFLOAT(8e+02), FAUSTFLOAT(2e+01), FAUSTFLOAT(1e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("MinNotch1Freq", &fHslider3, FAUSTFLOAT(1e+02), FAUSTFLOAT(2e+01), FAUSTFLOAT(5e+03), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider6, "unit", "Hz");
		ui_interface->addHorizontalSlider("Notch width", &fHslider6, FAUSTFLOAT(1e+03), FAUSTFLOAT(1e+01), FAUSTFLOAT(5e+03), FAUSTFLOAT(1.0));
		ui_interface->addHorizontalSlider("NotchFreq", &fHslider5, FAUSTFLOAT(1.5), FAUSTFLOAT(1.1), FAUSTFLOAT(4.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("Speed", &fHslider2, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fCheckbox0, "enum", "direct | vibrato");
		ui_interface->addCheckButton("VibratoMode", &fCheckbox0);
		ui_interface->addHorizontalSlider("depth", &fHslider0, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("feedback gain", &fHslider7, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fCheckbox1, "enum", "linear|invert");
		ui_interface->addCheckButton("invert", &fCheckbox1);
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("level", &fHslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-6e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.5 * ((static_cast<int>(static_cast<double>(fCheckbox0))) ? 2.0 : static_cast<double>(fHslider0));
		double fSlow1 = 1.0 - fSlow0;
		double fSlow2 = std::pow(1e+01, 0.05 * static_cast<double>(fHslider1));
		double fSlow3 = 2.0 * fSlow2;
		double fSlow4 = fConst1 * static_cast<double>(fHslider2);
		double fSlow5 = std::cos(fSlow4);
		double fSlow6 = std::sin(fSlow4);
		double fSlow7 = static_cast<double>(fHslider3);
		double fSlow8 = 3.141592653589793 * (fSlow7 - std::max<double>(fSlow7, static_cast<double>(fHslider4)));
		double fSlow9 = 6.283185307179586 * fSlow7;
		double fSlow10 = static_cast<double>(fHslider5);
		double fSlow11 = fConst2 * GxPhaser_faustpower4_f(fSlow10);
		double fSlow12 = fConst2 * GxPhaser_faustpower3_f(fSlow10);
		double fSlow13 = fConst2 * GxPhaser_faustpower2_f(fSlow10);
		double fSlow14 = fConst2 * fSlow10;
		double fSlow15 = std::exp(-(fConst3 * static_cast<double>(fHslider6)));
		double fSlow16 = GxPhaser_faustpower2_f(fSlow15);
		double fSlow17 = 2.0 * fSlow15;
		double fSlow18 = static_cast<double>(fHslider7);
		double fSlow19 = ((static_cast<int>(static_cast<double>(fCheckbox1))) ? -fSlow0 : fSlow0);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			iVec0[0] = 1;
			fRec1[0] = fSlow6 * fRec2[1] + fSlow5 * fRec1[1];
			fRec2[0] = static_cast<double>(faust_wrap_sub(1, iVec0[1])) + fSlow5 * fRec2[1] - fSlow6 * fRec1[1];
			double fTemp1 = fSlow9 - fSlow8 * (1.0 - fRec2[0]);
			double fTemp2 = fRec3[1] * std::cos(fSlow11 * fTemp1);
			double fTemp3 = fRec4[1] * std::cos(fSlow12 * fTemp1);
			double fTemp4 = fRec5[1] * std::cos(fSlow13 * fTemp1);
			double fTemp5 = fRec6[1] * std::cos(fSlow14 * fTemp1);
			double fTemp6 = fSlow2 * fTemp0;
			fRec6[0] = fTemp6 + fSlow18 * fRec0[1] + fSlow17 * fTemp5 - fSlow16 * fRec6[2];
			fRec5[0] = fRec6[2] + fSlow16 * (fRec6[0] - fRec5[2]) - fSlow17 * (fTemp5 - fTemp4);
			fRec4[0] = fRec5[2] + fSlow16 * (fRec5[0] - fRec4[2]) - fSlow17 * (fTemp4 - fTemp3);
			fRec3[0] = fRec4[2] + fSlow16 * (fRec4[0] - fRec3[2]) - fSlow17 * (fTemp3 - fTemp2);
			fRec0[0] = fRec3[2] + fSlow16 * fRec3[0] - fSlow17 * fTemp2;
			double fTemp7 = fSlow9 - fSlow8 * (1.0 - fRec1[0]);
			double fTemp8 = fRec8[1] * std::cos(fSlow11 * fTemp7);
			double fTemp9 = fRec9[1] * std::cos(fSlow12 * fTemp7);
			double fTemp10 = fRec10[1] * std::cos(fSlow13 * fTemp7);
			double fTemp11 = fRec11[1] * std::cos(fSlow14 * fTemp7);
			fRec11[0] = fTemp6 + fSlow18 * fRec7[1] + fSlow17 * fTemp11 - fSlow16 * fRec11[2];
			fRec10[0] = fRec11[2] + fSlow16 * (fRec11[0] - fRec10[2]) - fSlow17 * (fTemp11 - fTemp10);
			fRec9[0] = fRec10[2] + fSlow16 * (fRec10[0] - fRec9[2]) - fSlow17 * (fTemp10 - fTemp9);
			fRec8[0] = fRec9[2] + fSlow16 * (fRec9[0] - fRec8[2]) - fSlow17 * (fTemp9 - fTemp8);
			fRec7[0] = fRec8[2] + fSlow16 * fRec8[0] - fSlow17 * fTemp8;
			output0[i0] = static_cast<FAUSTFLOAT>(0.5 * (fSlow19 * (fRec7[0] + fRec0[0]) + fSlow3 * fTemp0 * fSlow1));
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec0[1] = fRec0[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
		}
	}

};

#endif
