/* ------------------------------------------------------------
author: "brummer"
copyright: "(c)brummer 2008"
license: "BSD"
name: "Stereo Verb"
version: "0.01"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxStereoverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxStereoverb_H__
#define  __GxStereoverb_H__

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
#define FAUSTCLASS GxStereoverb
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


class GxStereoverb : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	int iVec0[2];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	double fConst0;
	double fRec0[2];
	double fRec1[2];
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fVslider1;
	double fRec11[2];
	FAUSTFLOAT fVslider2;
	int IOTA0;
	double fVec1[2048];
	double fRec10[2];
	double fRec13[2];
	double fVec2[2048];
	double fRec12[2];
	double fRec15[2];
	double fVec3[2048];
	double fRec14[2];
	double fRec17[2];
	double fVec4[2048];
	double fRec16[2];
	double fRec19[2];
	double fVec5[2048];
	double fRec18[2];
	double fRec21[2];
	double fVec6[2048];
	double fRec20[2];
	double fRec23[2];
	double fVec7[2048];
	double fRec22[2];
	double fRec25[2];
	double fVec8[2048];
	double fRec24[2];
	double fVec9[1024];
	double fRec8[2];
	double fVec10[512];
	double fRec6[2];
	double fVec11[512];
	double fRec4[2];
	double fVec12[256];
	double fRec2[2];
	
 public:
	GxStereoverb() {
	}
	
	GxStereoverb(const GxStereoverb&) = default;
	
	virtual ~GxStereoverb() = default;
	
	GxStereoverb& operator=(const GxStereoverb&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "brummer");
		m->declare("category", "Reverb");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxStereoverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("copyright", "(c)brummer 2008");
		m->declare("filename", "gx-stereoverb.dsp");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "BSD");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Stereo Verb");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
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
		fConst0 = 6.283185307179586 / std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(5e+01);
		fHslider0 = static_cast<FAUSTFLOAT>(0.2);
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider1 = static_cast<FAUSTFLOAT>(0.5);
		fVslider2 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec0[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec1[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec11[l3] = 0.0;
		}
		IOTA0 = 0;
		for (int l4 = 0; l4 < 2048; l4 = faust_wrap_add(l4, 1)) {
			fVec1[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec10[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec13[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2048; l7 = faust_wrap_add(l7, 1)) {
			fVec2[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec12[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec15[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2048; l10 = faust_wrap_add(l10, 1)) {
			fVec3[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec14[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec17[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2048; l13 = faust_wrap_add(l13, 1)) {
			fVec4[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec16[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec19[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 2048; l16 = faust_wrap_add(l16, 1)) {
			fVec5[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec18[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec21[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2048; l19 = faust_wrap_add(l19, 1)) {
			fVec6[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec20[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec23[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 2048; l22 = faust_wrap_add(l22, 1)) {
			fVec7[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec22[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec25[l24] = 0.0;
		}
		for (int l25 = 0; l25 < 2048; l25 = faust_wrap_add(l25, 1)) {
			fVec8[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec24[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 1024; l27 = faust_wrap_add(l27, 1)) {
			fVec9[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec8[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 512; l29 = faust_wrap_add(l29, 1)) {
			fVec10[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec6[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 512; l31 = faust_wrap_add(l31, 1)) {
			fVec11[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec4[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 256; l33 = faust_wrap_add(l33, 1)) {
			fVec12[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec2[l34] = 0.0;
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
	
	virtual GxStereoverb* clone() {
		return new GxStereoverb(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Stereo Verb");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("LFO freq", &fHslider0, FAUSTFLOAT(0.2), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.01));
		ui_interface->addVerticalSlider("RoomSize", &fVslider2, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.025));
		ui_interface->addVerticalSlider("damp", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.025));
		ui_interface->declare(&fCheckbox0, "enum", "linear|pingpong");
		ui_interface->addCheckButton("invert", &fCheckbox0);
		ui_interface->declare(&fVslider0, "name", "wet/dry");
		ui_interface->addVerticalSlider("wet_dry", &fVslider0, FAUSTFLOAT(5e+01), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fVslider0);
		double fSlow1 = 1.0 - 0.01 * fSlow0;
		double fSlow2 = 2.0 * fSlow1;
		double fSlow3 = fConst0 * static_cast<double>(fHslider0);
		double fSlow4 = std::cos(fSlow3);
		double fSlow5 = std::sin(fSlow3);
		double fSlow6 = static_cast<double>(fCheckbox0);
		double fSlow7 = fSlow0 * (0.01 * fSlow1 + 0.00015);
		double fSlow8 = static_cast<double>(fVslider1);
		double fSlow9 = 1.0 - fSlow8;
		double fSlow10 = 0.28 * static_cast<double>(fVslider2) + 0.7;
		double fSlow11 = 0.00015 * fSlow0;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			iVec0[0] = 1;
			fRec0[0] = fSlow5 * fRec1[1] + fSlow4 * fRec0[1];
			fRec1[0] = static_cast<double>(faust_wrap_sub(1, iVec0[1])) + fSlow4 * fRec1[1] - fSlow5 * fRec0[1];
			double fTemp1 = fSlow6 * fRec0[0];
			fRec11[0] = fSlow8 * fRec11[1] + fSlow9 * fRec10[1];
			double fTemp2 = fSlow11 * fTemp0;
			fVec1[IOTA0 & 2047] = fTemp2 + fSlow10 * fRec11[0];
			fRec10[0] = fVec1[(faust_wrap_sub(IOTA0, 1640)) & 2047];
			fRec13[0] = fSlow8 * fRec13[1] + fSlow9 * fRec12[1];
			fVec2[IOTA0 & 2047] = fTemp2 + fSlow10 * fRec13[0];
			fRec12[0] = fVec2[(faust_wrap_sub(IOTA0, 1580)) & 2047];
			fRec15[0] = fSlow8 * fRec15[1] + fSlow9 * fRec14[1];
			fVec3[IOTA0 & 2047] = fTemp2 + fSlow10 * fRec15[0];
			fRec14[0] = fVec3[(faust_wrap_sub(IOTA0, 1514)) & 2047];
			fRec17[0] = fSlow8 * fRec17[1] + fSlow9 * fRec16[1];
			fVec4[IOTA0 & 2047] = fTemp2 + fSlow10 * fRec17[0];
			fRec16[0] = fVec4[(faust_wrap_sub(IOTA0, 1445)) & 2047];
			fRec19[0] = fSlow8 * fRec19[1] + fSlow9 * fRec18[1];
			fVec5[IOTA0 & 2047] = fTemp2 + fSlow10 * fRec19[0];
			fRec18[0] = fVec5[(faust_wrap_sub(IOTA0, 1379)) & 2047];
			fRec21[0] = fSlow8 * fRec21[1] + fSlow9 * fRec20[1];
			fVec6[IOTA0 & 2047] = fTemp2 + fSlow10 * fRec21[0];
			fRec20[0] = fVec6[(faust_wrap_sub(IOTA0, 1300)) & 2047];
			fRec23[0] = fSlow8 * fRec23[1] + fSlow9 * fRec22[1];
			fVec7[IOTA0 & 2047] = fTemp2 + fSlow10 * fRec23[0];
			fRec22[0] = fVec7[(faust_wrap_sub(IOTA0, 1211)) & 2047];
			fRec25[0] = fSlow8 * fRec25[1] + fSlow9 * fRec24[1];
			fVec8[IOTA0 & 2047] = fTemp2 + fSlow10 * fRec25[0];
			fRec24[0] = fVec8[(faust_wrap_sub(IOTA0, 1139)) & 2047];
			double fTemp3 = fRec24[0] + fRec22[0] + fRec20[0] + fRec18[0] + fRec16[0] + fRec14[0] + fRec12[0] + fRec10[0];
			fVec9[IOTA0 & 1023] = fTemp3 + 0.5 * fRec8[1];
			fRec8[0] = fVec9[(faust_wrap_sub(IOTA0, 579)) & 1023];
			double fRec9 = fRec8[1] - fTemp3;
			fVec10[IOTA0 & 511] = fRec9 + 0.5 * fRec6[1];
			fRec6[0] = fVec10[(faust_wrap_sub(IOTA0, 464)) & 511];
			double fRec7 = fRec6[1] - fRec9;
			fVec11[IOTA0 & 511] = fRec7 + 0.5 * fRec4[1];
			fRec4[0] = fVec11[(faust_wrap_sub(IOTA0, 364)) & 511];
			double fRec5 = fRec4[1] - fRec7;
			fVec12[IOTA0 & 255] = fRec5 + 0.5 * fRec2[1];
			fRec2[0] = fVec12[(faust_wrap_sub(IOTA0, 248)) & 255];
			double fRec3 = fRec2[1] - fRec5;
			output0[i0] = static_cast<FAUSTFLOAT>(0.5 * ((fRec3 + fSlow7 * fTemp0) * (1.0 - fTemp1 + fTemp1 + 1.0) + fSlow2 * fTemp0));
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec11[1] = fRec11[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec10[1] = fRec10[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
		}
	}

};

#endif
