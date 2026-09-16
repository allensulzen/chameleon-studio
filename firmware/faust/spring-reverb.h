/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "SpringReverb"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn SpringReverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __SpringReverb_H__
#define  __SpringReverb_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
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
#define FAUSTCLASS SpringReverb
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

static float SpringReverb_faustpower2_f(float value) {
	return value * value;
}

class SpringReverb : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	float fConst3;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider1;
	float fRec5[2];
	float fVec0[2];
	float fConst6;
	float fRec4[2];
	float fVec1[2];
	float fConst7;
	float fConst8;
	float fConst9;
	float fRec26[2];
	int IOTA0;
	float fVec2[32];
	float fRec24[2];
	float fVec3[32];
	float fRec22[2];
	float fVec4[64];
	float fRec20[2];
	float fVec5[64];
	float fRec18[2];
	float fVec6[64];
	float fRec16[2];
	float fVec7[64];
	float fRec14[2];
	float fVec8[64];
	float fRec12[2];
	float fVec9[64];
	float fRec10[2];
	float fVec10[64];
	float fRec8[2];
	float fVec11[128];
	float fRec6[2];
	float fVec12[4096];
	float fRec3[2];
	float fVec13[2];
	float fRec28[2];
	float fVec14[4096];
	float fRec27[2];
	float fRec2[3];
	float fVec15[2];
	float fConst10;
	float fConst11;
	float fConst12;
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	float fRec29[2];
	
 public:
	SpringReverb() {
	}
	
	SpringReverb(const SpringReverb&) = default;
	
	virtual ~SpringReverb() = default;
	
	SpringReverb& operator=(const SpringReverb&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn SpringReverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Dispersive spring tank model: allpass chirp chain + twin springs");
		m->declare("filename", "spring-reverb.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "LicenseRef-STK-4.3");
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
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "SpringReverb");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
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
		fConst3 = 3.1415927f / fConst0;
		fConst4 = 1.0f / std::tan(8168.141f / fConst0);
		fConst5 = 1.0f - fConst4;
		fConst6 = 1.0f / (fConst4 + 1.0f);
		fConst7 = 1.0f / std::tan(691.1504f / fConst0);
		fConst8 = 1.0f - fConst7;
		fConst9 = 1.0f / (fConst7 + 1.0f);
		fConst10 = 1.0f / std::tan(471.2389f / fConst0);
		fConst11 = 1.0f - fConst10;
		fConst12 = 1.0f / (fConst10 + 1.0f);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(3.2e+03f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.6f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.45f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec5[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec26[l5] = 0.0f;
		}
		IOTA0 = 0;
		for (int l6 = 0; l6 < 32; l6 = faust_wrap_add(l6, 1)) {
			fVec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec24[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 32; l8 = faust_wrap_add(l8, 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec22[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 64; l10 = faust_wrap_add(l10, 1)) {
			fVec4[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec20[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 64; l12 = faust_wrap_add(l12, 1)) {
			fVec5[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec18[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 64; l14 = faust_wrap_add(l14, 1)) {
			fVec6[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec16[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 64; l16 = faust_wrap_add(l16, 1)) {
			fVec7[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec14[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 64; l18 = faust_wrap_add(l18, 1)) {
			fVec8[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec12[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 64; l20 = faust_wrap_add(l20, 1)) {
			fVec9[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec10[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 64; l22 = faust_wrap_add(l22, 1)) {
			fVec10[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec8[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 128; l24 = faust_wrap_add(l24, 1)) {
			fVec11[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec6[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 4096; l26 = faust_wrap_add(l26, 1)) {
			fVec12[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec3[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fVec13[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec28[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 4096; l30 = faust_wrap_add(l30, 1)) {
			fVec14[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec27[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 3; l32 = faust_wrap_add(l32, 1)) {
			fRec2[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fVec15[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec0[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec29[l35] = 0.0f;
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
	
	virtual SpringReverb* clone() {
		return new SpringReverb(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("SpringReverb");
		ui_interface->addHorizontalSlider("Dwell", &fHslider1, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Mix", &fHslider2, FAUSTFLOAT(0.45f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("Tone", &fHslider0, FAUSTFLOAT(3.2e+03f), FAUSTFLOAT(8e+02f), FAUSTFLOAT(7e+03f), FAUSTFLOAT(5e+01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow0 + fConst2 * fRec1[1];
			float fTemp0 = std::tan(fConst3 * fRec1[0]);
			float fTemp1 = 1.0f / fTemp0;
			float fTemp2 = (fTemp1 + 1.4142135f) / fTemp0 + 1.0f;
			fRec5[0] = fSlow1 + fConst2 * fRec5[1];
			float fTemp3 = 0.13f * fRec5[0] + 0.82f;
			float fTemp4 = fTemp3 * fRec3[1];
			fVec0[0] = fTemp4;
			fRec4[0] = fConst6 * (0.95f * (fTemp4 + fVec0[1]) - fConst5 * fRec4[1]);
			float fTemp5 = static_cast<float>(input0[i0]);
			fVec1[0] = fTemp5;
			fRec26[0] = -(fConst9 * (fConst8 * fRec26[1] - fConst7 * (fTemp5 - fVec1[1])));
			float fTemp6 = tanhf(fRec26[0] * (3.0f * fRec5[0] + 1.0f)) / (1.2f * fRec5[0] + 1.0f) - 0.62f * fRec24[1];
			fVec2[IOTA0 & 31] = fTemp6;
			fRec24[0] = fVec2[(faust_wrap_sub(IOTA0, 22)) & 31];
			float fRec25 = 0.62f * fTemp6;
			float fTemp7 = fRec25 + fRec24[1] - 0.62f * fRec22[1];
			fVec3[IOTA0 & 31] = fTemp7;
			fRec22[0] = fVec3[(faust_wrap_sub(IOTA0, 27)) & 31];
			float fRec23 = 0.62f * fTemp7;
			float fTemp8 = fRec23 + fRec22[1] - 0.62f * fRec20[1];
			fVec4[IOTA0 & 63] = fTemp8;
			fRec20[0] = fVec4[(faust_wrap_sub(IOTA0, 32)) & 63];
			float fRec21 = 0.62f * fTemp8;
			float fTemp9 = fRec21 + fRec20[1] - 0.62f * fRec18[1];
			fVec5[IOTA0 & 63] = fTemp9;
			fRec18[0] = fVec5[(faust_wrap_sub(IOTA0, 37)) & 63];
			float fRec19 = 0.62f * fTemp9;
			float fTemp10 = fRec19 + fRec18[1] - 0.62f * fRec16[1];
			fVec6[IOTA0 & 63] = fTemp10;
			fRec16[0] = fVec6[(faust_wrap_sub(IOTA0, 42)) & 63];
			float fRec17 = 0.62f * fTemp10;
			float fTemp11 = fRec17 + fRec16[1] - 0.62f * fRec14[1];
			fVec7[IOTA0 & 63] = fTemp11;
			fRec14[0] = fVec7[(faust_wrap_sub(IOTA0, 47)) & 63];
			float fRec15 = 0.62f * fTemp11;
			float fTemp12 = fRec15 + fRec14[1] - 0.62f * fRec12[1];
			fVec8[IOTA0 & 63] = fTemp12;
			fRec12[0] = fVec8[(faust_wrap_sub(IOTA0, 52)) & 63];
			float fRec13 = 0.62f * fTemp12;
			float fTemp13 = fRec13 + fRec12[1] - 0.62f * fRec10[1];
			fVec9[IOTA0 & 63] = fTemp13;
			fRec10[0] = fVec9[(faust_wrap_sub(IOTA0, 57)) & 63];
			float fRec11 = 0.62f * fTemp13;
			float fTemp14 = fRec11 + fRec10[1] - 0.62f * fRec8[1];
			fVec10[IOTA0 & 63] = fTemp14;
			fRec8[0] = fVec10[(faust_wrap_sub(IOTA0, 62)) & 63];
			float fRec9 = 0.62f * fTemp14;
			float fTemp15 = fRec9 + fRec8[1] - 0.62f * fRec6[1];
			fVec11[IOTA0 & 127] = fTemp15;
			fRec6[0] = fVec11[(faust_wrap_sub(IOTA0, 67)) & 127];
			float fRec7 = 0.62f * fTemp15;
			fVec12[IOTA0 & 4095] = fRec6[1] + fRec7 + fRec4[0];
			fRec3[0] = fVec12[(faust_wrap_sub(IOTA0, 3379)) & 4095];
			float fTemp16 = fRec27[1] * fTemp3;
			fVec13[0] = fTemp16;
			fRec28[0] = -(fConst6 * (fConst5 * fRec28[1] - (fTemp16 + fVec13[1])));
			fVec14[IOTA0 & 4095] = fRec6[1] + fRec28[0] + fRec7;
			fRec27[0] = fVec14[(faust_wrap_sub(IOTA0, 2103)) & 4095];
			fRec2[0] = 0.5f * (fRec27[0] + fRec3[0]) - (fRec2[2] * ((fTemp1 + -1.4142135f) / fTemp0 + 1.0f) + 2.0f * fRec2[1] * (1.0f - 1.0f / SpringReverb_faustpower2_f(fTemp0))) / fTemp2;
			float fTemp17 = (fRec2[2] + fRec2[0] + 2.0f * fRec2[1]) / fTemp2;
			fVec15[0] = fTemp17;
			fRec0[0] = -(fConst12 * (fConst11 * fRec0[1] - fConst10 * (fTemp17 - fVec15[1])));
			fRec29[0] = fSlow2 + fConst2 * fRec29[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp5 * (1.0f - fRec29[0]) + 1.1f * fRec29[0] * fRec0[0]);
			fRec1[1] = fRec1[0];
			fRec5[1] = fRec5[0];
			fVec0[1] = fVec0[0];
			fRec4[1] = fRec4[0];
			fVec1[1] = fVec1[0];
			fRec26[1] = fRec26[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec24[1] = fRec24[0];
			fRec22[1] = fRec22[0];
			fRec20[1] = fRec20[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec3[1] = fRec3[0];
			fVec13[1] = fVec13[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fVec15[1] = fVec15[0];
			fRec0[1] = fRec0[0];
			fRec29[1] = fRec29[0];
		}
	}

};

#endif
