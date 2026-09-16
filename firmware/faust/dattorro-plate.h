/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "DattorroPlate"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn DattorroPlate -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __DattorroPlate_H__
#define  __DattorroPlate_H__

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
#define FAUSTCLASS DattorroPlate
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


class DattorroPlate : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec4[2];
	FAUSTFLOAT fHslider1;
	float fRec6[2];
	int IOTA0;
	float fVec0[1024];
	float fRec7[2];
	float fVec1[8192];
	float fRec5[2];
	float fVec2[4096];
	float fRec2[2];
	float fVec3[4096];
	float fVec4[2];
	float fConst3;
	float fConst4;
	float fConst5;
	float fRec18[512];
	float fRec17[3];
	float fVec5[256];
	float fRec15[2];
	float fVec6[128];
	float fRec13[2];
	float fVec7[512];
	float fRec11[2];
	float fVec8[512];
	float fRec9[2];
	float fRec0[2];
	float fVec9[1024];
	float fRec22[2];
	float fVec10[8192];
	float fRec21[2];
	float fVec11[2048];
	float fRec19[2];
	float fVec12[2048];
	float fRec1[2];
	FAUSTFLOAT fHslider2;
	float fRec24[2];
	
 public:
	DattorroPlate() {
	}
	
	DattorroPlate(const DattorroPlate&) = default;
	
	virtual ~DattorroPlate() = default;
	
	DattorroPlate& operator=(const DattorroPlate&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn DattorroPlate -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Dattorro figure-eight plate reverb (true Dattorro tank topology)");
		m->declare("filename", "dattorro-plate.dsp");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass0_highpass1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "DattorroPlate");
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
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.0f / std::tan(282.74335f / fConst0);
		fConst4 = 1.0f - fConst3;
		fConst5 = 1.0f / (fConst3 + 1.0f);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.6f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.65f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.4f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec4[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec6[l1] = 0.0f;
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
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 4096; l6 = faust_wrap_add(l6, 1)) {
			fVec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 4096; l8 = faust_wrap_add(l8, 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fVec4[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 512; l10 = faust_wrap_add(l10, 1)) {
			fRec18[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 3; l11 = faust_wrap_add(l11, 1)) {
			fRec17[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 256; l12 = faust_wrap_add(l12, 1)) {
			fVec5[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec15[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 128; l14 = faust_wrap_add(l14, 1)) {
			fVec6[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec13[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 512; l16 = faust_wrap_add(l16, 1)) {
			fVec7[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec11[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 512; l18 = faust_wrap_add(l18, 1)) {
			fVec8[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec9[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec0[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 1024; l21 = faust_wrap_add(l21, 1)) {
			fVec9[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec22[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 8192; l23 = faust_wrap_add(l23, 1)) {
			fVec10[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec21[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2048; l25 = faust_wrap_add(l25, 1)) {
			fVec11[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec19[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2048; l27 = faust_wrap_add(l27, 1)) {
			fVec12[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec1[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec24[l29] = 0.0f;
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
	
	virtual DattorroPlate* clone() {
		return new DattorroPlate(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("DattorroPlate");
		ui_interface->addHorizontalSlider("Decay", &fHslider0, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Mix", &fHslider2, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Tone", &fHslider1, FAUSTFLOAT(0.65f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec4[0] = fSlow0 + fConst2 * fRec4[1];
			float fTemp0 = 0.48f * fRec4[0] + 0.5f;
			fRec6[0] = fSlow1 + fConst2 * fRec6[1];
			float fTemp1 = 0.85f * (1.0f - fRec6[0]);
			float fTemp2 = 0.98f - fTemp1;
			float fTemp3 = 0.7f * fRec7[1] + fRec1[1];
			fVec0[IOTA0 & 1023] = fTemp3;
			fRec7[0] = fVec0[(faust_wrap_sub(IOTA0, 908)) & 1023];
			float fRec8 = -(0.7f * fTemp3);
			fVec1[IOTA0 & 8191] = fRec8 + fRec7[1];
			float fTemp4 = fTemp1 + 0.02f;
			fRec5[0] = fRec5[1] * fTemp4 + fVec1[(faust_wrap_sub(IOTA0, 4217)) & 8191] * fTemp2;
			float fTemp5 = fRec5[0] * fTemp0 - 0.5f * fRec2[1];
			fVec2[IOTA0 & 4095] = fTemp5;
			fRec2[0] = fVec2[(faust_wrap_sub(IOTA0, 2656)) & 4095];
			float fRec3 = 0.5f * fTemp5;
			fVec3[IOTA0 & 4095] = fRec3 + fRec2[1];
			float fTemp6 = static_cast<float>(input0[i0]);
			fVec4[0] = fTemp6;
			fRec18[IOTA0 & 511] = -(fConst5 * (fConst4 * fRec18[(faust_wrap_sub(IOTA0, 1)) & 511] - fConst3 * (fTemp6 - fVec4[1])));
			float fTemp7 = 0.59f * fRec6[0];
			fRec17[0] = fRec17[2] * (0.6f - fTemp7) + (fTemp7 + 0.4f) * fRec18[(faust_wrap_sub(IOTA0, 480)) & 511];
			float fTemp8 = fRec17[0] - 0.75f * fRec15[1];
			fVec5[IOTA0 & 255] = fTemp8;
			fRec15[0] = fVec5[(faust_wrap_sub(IOTA0, 142)) & 255];
			float fRec16 = 0.75f * fTemp8;
			float fTemp9 = fRec16 + fRec15[1] - 0.75f * fRec13[1];
			fVec6[IOTA0 & 127] = fTemp9;
			fRec13[0] = fVec6[(faust_wrap_sub(IOTA0, 107)) & 127];
			float fRec14 = 0.75f * fTemp9;
			float fTemp10 = fRec14 + fRec13[1] - 0.625f * fRec11[1];
			fVec7[IOTA0 & 511] = fTemp10;
			fRec11[0] = fVec7[(faust_wrap_sub(IOTA0, 379)) & 511];
			float fRec12 = 0.625f * fTemp10;
			float fTemp11 = fRec12 + fRec11[1] - 0.625f * fRec9[1];
			fVec8[IOTA0 & 511] = fTemp11;
			fRec9[0] = fVec8[(faust_wrap_sub(IOTA0, 277)) & 511];
			float fRec10 = 0.625f * fTemp11;
			fRec0[0] = fRec9[1] + fRec10 + fTemp0 * fVec3[(faust_wrap_sub(IOTA0, 2656)) & 4095];
			float fTemp12 = 0.7f * fRec22[1] + fRec0[1];
			fVec9[IOTA0 & 1023] = fTemp12;
			fRec22[0] = fVec9[(faust_wrap_sub(IOTA0, 672)) & 1023];
			float fRec23 = -(0.7f * fTemp12);
			fVec10[IOTA0 & 8191] = fRec23 + fRec22[1];
			fRec21[0] = fTemp4 * fRec21[1] + fTemp2 * fVec10[(faust_wrap_sub(IOTA0, 4453)) & 8191];
			float fTemp13 = fRec21[0] * fTemp0 - 0.5f * fRec19[1];
			fVec11[IOTA0 & 2047] = fTemp13;
			fRec19[0] = fVec11[(faust_wrap_sub(IOTA0, 1800)) & 2047];
			float fRec20 = 0.5f * fTemp13;
			fVec12[IOTA0 & 2047] = fRec20 + fRec19[1];
			fRec1[0] = fRec10 + fRec9[1] + fTemp0 * fVec12[(faust_wrap_sub(IOTA0, 1800)) & 2047];
			fRec24[0] = fSlow2 + fConst2 * fRec24[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp6 * (1.0f - fRec24[0]) + 0.5f * fRec24[0] * (fRec0[0] + fRec1[0]));
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec7[1] = fRec7[0];
			fRec5[1] = fRec5[0];
			fRec2[1] = fRec2[0];
			fVec4[1] = fVec4[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec11[1] = fRec11[0];
			fRec9[1] = fRec9[0];
			fRec0[1] = fRec0[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec1[1] = fRec1[0];
			fRec24[1] = fRec24[0];
		}
	}

};

#endif
