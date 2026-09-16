/* ------------------------------------------------------------
author: "Jakob Zerbian (Faust port), Jon Dattorro"
license: "LicenseRef-STK-4.3"
name: "Dattorro Plate"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibDattorro -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibDattorro_H__
#define  __LibDattorro_H__

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
#define FAUSTCLASS LibDattorro
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


class LibDattorro : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fRec4[2];
	FAUSTFLOAT fHslider1;
	float fRec5[2];
	int IOTA0;
	float fVec0[1024];
	float fRec7[2];
	float fVec1[8192];
	FAUSTFLOAT fHslider2;
	float fRec9[2];
	float fRec6[2];
	float fVec2[4096];
	float fRec2[2];
	float fVec3[4096];
	FAUSTFLOAT fHslider3;
	float fRec12[2];
	FAUSTFLOAT fHslider4;
	float fRec20[2];
	float fRec19[3];
	float fVec4[256];
	float fRec17[2];
	float fVec5[128];
	float fRec15[2];
	float fVec6[512];
	float fRec13[2];
	float fVec7[512];
	float fRec10[2];
	float fRec0[2];
	float fVec8[1024];
	float fRec24[2];
	float fVec9[8192];
	float fRec23[2];
	float fVec10[2048];
	float fRec21[2];
	float fVec11[2048];
	float fRec1[2];
	FAUSTFLOAT fHslider5;
	float fRec26[2];
	
 public:
	LibDattorro() {
	}
	
	LibDattorro(const LibDattorro&) = default;
	
	virtual ~LibDattorro() = default;
	
	LibDattorro& operator=(const LibDattorro&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Jakob Zerbian (Faust port), Jon Dattorro");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibDattorro -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Jon Dattorro's 1997 figure-of-eight plate reverb (input diffusion + modulated tank)");
		m->declare("family", "reverb");
		m->declare("filename", "lib-dattorro.dsp");
		m->declare("license", "LicenseRef-STK-4.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Dattorro Plate");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/dattorro_rev:author", "Jakob Zerbian");
		m->declare("reverbs.lib/dattorro_rev:licence", "LicenseRef-STK-4.3");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.5.1");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/reverbs.lib re.dattorro_rev");
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
		fConst0 = 44.1f / std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 1.0f - fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.625f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.6f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.625f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.7f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.35f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec4[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec5[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 1024; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec7[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 8192; l4 = faust_wrap_add(l4, 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec9[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 4096; l7 = faust_wrap_add(l7, 1)) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec2[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 4096; l9 = faust_wrap_add(l9, 1)) {
			fVec3[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec12[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec20[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 3; l12 = faust_wrap_add(l12, 1)) {
			fRec19[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 256; l13 = faust_wrap_add(l13, 1)) {
			fVec4[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec17[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 128; l15 = faust_wrap_add(l15, 1)) {
			fVec5[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec15[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 512; l17 = faust_wrap_add(l17, 1)) {
			fVec6[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec13[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 512; l19 = faust_wrap_add(l19, 1)) {
			fVec7[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec10[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec0[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 1024; l22 = faust_wrap_add(l22, 1)) {
			fVec8[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec24[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 8192; l24 = faust_wrap_add(l24, 1)) {
			fVec9[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec23[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2048; l26 = faust_wrap_add(l26, 1)) {
			fVec10[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec21[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2048; l28 = faust_wrap_add(l28, 1)) {
			fVec11[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec1[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec26[l30] = 0.0f;
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
	
	virtual LibDattorro* clone() {
		return new LibDattorro(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Dattorro Plate");
		ui_interface->declare(&fHslider4, "0", "");
		ui_interface->addHorizontalSlider("Bandwidth", &fHslider4, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->addHorizontalSlider("Input Diffusion", &fHslider3, FAUSTFLOAT(0.625f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->addHorizontalSlider("Decay", &fHslider1, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.99f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider0, "3", "");
		ui_interface->addHorizontalSlider("Tank Diffusion", &fHslider0, FAUSTFLOAT(0.625f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider2, "4", "");
		ui_interface->addHorizontalSlider("Damping", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider5, "5", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider5, FAUSTFLOAT(0.35f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst0 * static_cast<float>(fHslider0);
		float fSlow1 = fConst0 * static_cast<float>(fHslider1);
		float fSlow2 = fConst0 * static_cast<float>(fHslider2);
		float fSlow3 = fConst0 * static_cast<float>(fHslider3);
		float fSlow4 = fConst0 * static_cast<float>(fHslider4);
		float fSlow5 = fConst0 * static_cast<float>(fHslider5);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec4[0] = fSlow0 + fConst1 * fRec4[1];
			fRec5[0] = fSlow1 + fConst1 * fRec5[1];
			float fTemp0 = 1.12f * fRec4[0] * fRec7[1] + fRec1[1];
			fVec0[IOTA0 & 1023] = fTemp0;
			fRec7[0] = fVec0[(faust_wrap_sub(IOTA0, 908)) & 1023];
			float fRec8 = -(1.12f * fRec4[0] * fTemp0);
			fVec1[IOTA0 & 8191] = fRec8 + fRec7[1];
			fRec9[0] = fSlow2 + fConst1 * fRec9[1];
			float fTemp1 = 1.0f - fRec9[0];
			fRec6[0] = fRec9[0] * fRec6[1] + fTemp1 * fVec1[(faust_wrap_sub(IOTA0, 4217)) & 8191];
			float fTemp2 = fRec6[0] * fRec5[0] - fRec4[0] * fRec2[1];
			fVec2[IOTA0 & 4095] = fTemp2;
			fRec2[0] = fVec2[(faust_wrap_sub(IOTA0, 2656)) & 4095];
			float fRec3 = fRec4[0] * fTemp2;
			fVec3[IOTA0 & 4095] = fRec3 + fRec2[1];
			fRec12[0] = fSlow3 + fConst1 * fRec12[1];
			fRec20[0] = fSlow4 + fConst1 * fRec20[1];
			float fTemp3 = static_cast<float>(input0[i0]);
			fRec19[0] = (1.0f - fRec20[0]) * fRec19[2] + fTemp3 * fRec20[0];
			float fTemp4 = fRec19[0] - fRec12[0] * fRec17[1];
			fVec4[IOTA0 & 255] = fTemp4;
			fRec17[0] = fVec4[(faust_wrap_sub(IOTA0, 142)) & 255];
			float fRec18 = fRec12[0] * fTemp4;
			float fTemp5 = fRec18 + fRec17[1] - fRec12[0] * fRec15[1];
			fVec5[IOTA0 & 127] = fTemp5;
			fRec15[0] = fVec5[(faust_wrap_sub(IOTA0, 107)) & 127];
			float fRec16 = fRec12[0] * fTemp5;
			float fTemp6 = fRec16 + fRec15[1] - 0.8f * fRec12[0] * fRec13[1];
			fVec6[IOTA0 & 511] = fTemp6;
			fRec13[0] = fVec6[(faust_wrap_sub(IOTA0, 379)) & 511];
			float fRec14 = 0.8f * fRec12[0] * fTemp6;
			float fTemp7 = fRec14 + fRec13[1] - 0.8f * fRec12[0] * fRec10[1];
			fVec7[IOTA0 & 511] = fTemp7;
			fRec10[0] = fVec7[(faust_wrap_sub(IOTA0, 277)) & 511];
			float fRec11 = 0.8f * fRec12[0] * fTemp7;
			fRec0[0] = fRec10[1] + fRec11 + fRec5[0] * fVec3[(faust_wrap_sub(IOTA0, 2656)) & 4095];
			float fTemp8 = 1.12f * fRec4[0] * fRec24[1] + fRec0[1];
			fVec8[IOTA0 & 1023] = fTemp8;
			fRec24[0] = fVec8[(faust_wrap_sub(IOTA0, 672)) & 1023];
			float fRec25 = -(1.12f * fRec4[0] * fTemp8);
			fVec9[IOTA0 & 8191] = fRec25 + fRec24[1];
			fRec23[0] = fRec9[0] * fRec23[1] + fTemp1 * fVec9[(faust_wrap_sub(IOTA0, 4453)) & 8191];
			float fTemp9 = fRec5[0] * fRec23[0] - fRec4[0] * fRec21[1];
			fVec10[IOTA0 & 2047] = fTemp9;
			fRec21[0] = fVec10[(faust_wrap_sub(IOTA0, 1800)) & 2047];
			float fRec22 = fRec4[0] * fTemp9;
			fVec11[IOTA0 & 2047] = fRec22 + fRec21[1];
			fRec1[0] = fRec11 + fRec10[1] + fRec5[0] * fVec11[(faust_wrap_sub(IOTA0, 1800)) & 2047];
			fRec26[0] = fSlow5 + fConst1 * fRec26[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp3 * (1.0f - fRec26[0]) + 0.5f * fRec26[0] * (fRec0[0] + fRec1[0]));
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec7[1] = fRec7[0];
			fRec9[1] = fRec9[0];
			fRec6[1] = fRec6[0];
			fRec2[1] = fRec2[0];
			fRec12[1] = fRec12[0];
			fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec17[1] = fRec17[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec10[1] = fRec10[0];
			fRec0[1] = fRec0[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec21[1] = fRec21[0];
			fRec1[1] = fRec1[0];
			fRec26[1] = fRec26[0];
		}
	}

};

#endif
