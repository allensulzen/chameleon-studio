/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Phaser Mono"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxPhaserMono -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxPhaserMono_H__
#define  __GxPhaserMono_H__

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
#define FAUSTCLASS GxPhaserMono
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

static double GxPhaserMono_faustpower2_f(double value) {
	return value * value;
}

class GxPhaserMono : public chdsp {
	
 private:
	
	int iVec0[2];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec1[2];
	double fRec2[2];
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fVslider0;
	double fRec6[3];
	double fRec5[3];
	double fRec4[3];
	double fRec3[3];
	double fRec0[2];
	
 public:
	GxPhaserMono() {
	}
	
	GxPhaserMono(const GxPhaserMono&) = default;
	
	virtual ~GxPhaserMono() = default;
	
	GxPhaserMono& operator=(const GxPhaserMono&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Modulation");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxPhaserMono -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-phaser-mono.dsp");
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
		m->declare("gx-phaser.dsp/category", "Modulation");
		m->declare("gx-phaser.dsp/chameleon_flags", "-double");
		m->declare("gx-phaser.dsp/id", "phaser");
		m->declare("gx-phaser.dsp/license", "GPL-2.0-or-later");
		m->declare("gx-phaser.dsp/name", "Phaser");
		m->declare("id", "phaser_mono");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Phaser Mono");
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
		fConst2 = 16.0 / fConst0;
		fConst3 = 8.0 / fConst0;
		fConst4 = 4.0 / fConst0;
		fConst5 = 2.0 / fConst0;
		fConst6 = std::exp(-(3141.592653589793 / fConst0));
		fConst7 = GxPhaserMono_faustpower2_f(fConst6);
		fConst8 = 2.0 * fConst6;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.5);
		fHslider1 = static_cast<FAUSTFLOAT>(0.0);
		fVslider0 = static_cast<FAUSTFLOAT>(1e+02);
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
	
	virtual GxPhaserMono* clone() {
		return new GxPhaserMono(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Phaser Mono");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("Speed", &fHslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("level", &fHslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-6e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider0, "name", "wet/dry");
		ui_interface->declare(&fVslider0, "tooltip", "percentage of processed signal in output signal");
		ui_interface->addVerticalSlider("wet_dry", &fVslider0, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = fConst1 * static_cast<double>(fHslider0);
		double fSlow1 = std::cos(fSlow0);
		double fSlow2 = std::sin(fSlow0);
		double fSlow3 = static_cast<double>(fVslider0);
		double fSlow4 = 0.01 * fSlow3 * std::pow(1e+01, 0.05 * static_cast<double>(fHslider1));
		double fSlow5 = 1.0 - 0.01 * fSlow3;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec1[0] = fSlow2 * fRec2[1] + fSlow1 * fRec1[1];
			fRec2[0] = static_cast<double>(faust_wrap_sub(1, iVec0[1])) + fSlow1 * fRec2[1] - fSlow2 * fRec1[1];
			double fTemp0 = 2199.1148575128555 * (1.0 - fRec1[0]) + 628.3185307179587;
			double fTemp1 = fRec3[1] * std::cos(fConst2 * fTemp0);
			double fTemp2 = fRec4[1] * std::cos(fConst3 * fTemp0);
			double fTemp3 = fRec5[1] * std::cos(fConst4 * fTemp0);
			double fTemp4 = fRec6[1] * std::cos(fConst5 * fTemp0);
			double fTemp5 = static_cast<double>(input0[i0]);
			fRec6[0] = fSlow4 * fTemp5 + 0.5 * fRec0[1] + fConst8 * fTemp4 - fConst7 * fRec6[2];
			fRec5[0] = fRec6[2] + fConst7 * (fRec6[0] - fRec5[2]) - fConst8 * (fTemp4 - fTemp3);
			fRec4[0] = fRec5[2] + fConst7 * (fRec5[0] - fRec4[2]) - fConst8 * (fTemp3 - fTemp2);
			fRec3[0] = fRec4[2] + fConst7 * (fRec4[0] - fRec3[2]) - fConst8 * (fTemp2 - fTemp1);
			fRec0[0] = fRec3[2] + fConst7 * fRec3[0] - fConst8 * fTemp1;
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow5 * fTemp5 - fRec0[0]);
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
		}
	}

};

#endif
