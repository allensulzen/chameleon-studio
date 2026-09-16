/* ------------------------------------------------------------
author: "Guitarix project / David Yeh (tonestack analysis)"
license: "LGPL-2.1-or-later"
name: "Tone Stack"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibToneStack -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibToneStack_H__
#define  __LibToneStack_H__

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
#define FAUSTCLASS LibToneStack
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

static float LibToneStack_faustpower3_f(float value) {
	return value * value * value;
}
static float LibToneStack_faustpower2_f(float value) {
	return value * value;
}

class LibToneStack : public chdsp {
	
 private:
	
	FAUSTFLOAT fEntry0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec1[2];
	float fConst3;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider2;
	float fRec2[2];
	float fRec3[4];
	float fConst6;
	float fRec4[4];
	float fRec5[4];
	float fRec6[4];
	float fRec7[4];
	float fRec8[4];
	float fRec9[4];
	FAUSTFLOAT fHslider3;
	float fRec10[2];
	
 public:
	LibToneStack() {
	}
	
	LibToneStack(const LibToneStack&) = default;
	
	virtual ~LibToneStack() = default;
	
	LibToneStack& operator=(const LibToneStack&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Guitarix project / David Yeh (tonestack analysis)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibToneStack -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Passive amp tone stacks from exact component values: Bassman, JCM800, Twin, AC30, Mesa, Soldano, Princeton");
		m->declare("family", "filter");
		m->declare("filename", "lib-tone-stack.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "LGPL-2.1-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Tone Stack");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/tonestacks.lib");
		m->declare("tonestacks.lib/author", "Guitarix project (<http://guitarix.sourceforge.net/>)");
		m->declare("tonestacks.lib/copyright", "Guitarix project");
		m->declare("tonestacks.lib/license", "LGPL-2.1-or-later");
		m->declare("tonestacks.lib/name", "Faust Tonestack Emulation Library");
		m->declare("tonestacks.lib/version", "1.28.0");
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
		fConst3 = 2.0f * fConst0;
		fConst4 = LibToneStack_faustpower3_f(fConst3);
		fConst5 = LibToneStack_faustpower2_f(fConst3);
		fConst6 = 3.0f * fConst4;
	}
	
	virtual void instanceResetUserInterface() {
		fEntry0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider0 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider3 = static_cast<FAUSTFLOAT>(6.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 4; l3 = faust_wrap_add(l3, 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 4; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 4; l5 = faust_wrap_add(l5, 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 4; l6 = faust_wrap_add(l6, 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 4; l7 = faust_wrap_add(l7, 1)) {
			fRec7[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 4; l8 = faust_wrap_add(l8, 1)) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 4; l9 = faust_wrap_add(l9, 1)) {
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec10[l10] = 0.0f;
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
	
	virtual LibToneStack* clone() {
		return new LibToneStack(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Tone Stack");
		ui_interface->declare(&fEntry0, "0", "");
		ui_interface->declare(&fEntry0, "style", "menu{'Bassman':0;'JCM800':1;'Twin':2;'AC30':3;'Mesa':4;'Soldano':5;'Princeton':6}");
		ui_interface->addNumEntry("Model", &fEntry0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(6.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->addHorizontalSlider("Bass", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->addHorizontalSlider("Middle", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "3", "");
		ui_interface->addHorizontalSlider("Treble", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "4", "");
		ui_interface->declare(&fHslider3, "unit", "dB");
		ui_interface->addHorizontalSlider("Level", &fHslider3, FAUSTFLOAT(6.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = static_cast<float>(fEntry0);
		int iSlow1 = fSlow0 >= 4.0f;
		int iSlow2 = fSlow0 >= 2.0f;
		int iSlow3 = fSlow0 >= 1.0f;
		float fSlow4 = fConst1 * static_cast<float>(fHslider0);
		float fSlow5 = fConst1 * static_cast<float>(fHslider1);
		float fSlow6 = fConst1 * static_cast<float>(fHslider2);
		int iSlow7 = fSlow0 >= 3.0f;
		int iSlow8 = fSlow0 >= 6.0f;
		int iSlow9 = fSlow0 >= 5.0f;
		float fSlow10 = fConst1 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider3));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow4 + fConst2 * fRec0[1];
			float fTemp0 = std::exp(3.4f * (fRec0[0] + -1.0f));
			float fTemp1 = 1.4e-09f * fTemp0;
			fRec1[0] = fSlow5 + fConst2 * fRec1[1];
			float fTemp2 = 7.65e-10f * fTemp0 - 1.9125e-11f * fRec1[0];
			float fTemp3 = fConst4 * (fRec1[0] * (fTemp2 + -1.5875e-11f) + fTemp1 + 3.5e-11f);
			float fTemp4 = 2.53125e-07f * fRec1[0];
			float fTemp5 = fConst5 * (fRec1[0] * (1.0125e-05f * fTemp0 + -2.75625e-07f - fTemp4) + 2.421e-05f * fTemp0 + 7.4525e-07f);
			float fTemp6 = 0.02025f * fTemp0;
			float fTemp7 = 0.0005f * fRec1[0];
			float fTemp8 = fConst3 * (fTemp7 + fTemp6 + 0.00280875f);
			float fTemp9 = fTemp8 + fTemp5;
			float fTemp10 = -1.0f - (fTemp9 + fTemp3);
			float fTemp11 = 1.0f - fRec1[0];
			fRec2[0] = fSlow6 + fConst2 * fRec2[1];
			float fTemp12 = fRec1[0] * (fTemp2 + 1.9125e-11f) + fRec2[0] * (fTemp1 + 3.5e-11f * fTemp11);
			float fTemp13 = fConst4 * fTemp12;
			float fTemp14 = fConst5 * (1.4e-07f * fRec2[0] + fRec1[0] * (2.84375e-07f - fTemp4) + fTemp0 * (1.0125e-05f * fRec1[0] + 1.81e-06f) + 4.525e-08f);
			float fTemp15 = 6.25e-05f * fRec2[0];
			float fTemp16 = fConst3 * (fTemp6 + fTemp7 + fTemp15 + 0.00050625f);
			float fTemp17 = fTemp16 + fTemp14;
			float fTemp18 = static_cast<float>(input0[i0]);
			fRec3[0] = fTemp18 - (fRec3[1] * (fTemp5 - (fTemp8 + 3.0f * (1.0f - fTemp3))) + fRec3[2] * (fTemp9 - 3.0f * (fTemp3 + 1.0f)) + fRec3[3] * (fTemp8 + fTemp3 + (-1.0f - fTemp5))) / fTemp10;
			float fTemp19 = fConst6 * fTemp12;
			float fTemp20 = 1.6515048e-09f * fTemp0;
			float fTemp21 = 1.2661536e-09f * fTemp0 - 2.7855381e-11f * fRec1[0];
			float fTemp22 = fConst4 * (fRec1[0] * (fTemp21 + -8.477725e-12f) + fTemp20 + 3.6333107e-11f);
			float fTemp23 = 2.3926057e-07f * fRec1[0];
			float fTemp24 = fConst5 * (fRec1[0] * (1.087548e-05f * fTemp0 + -6.207784e-08f - fTemp23) + 1.892924e-05f * fTemp0 + 5.6658007e-07f);
			float fTemp25 = 0.02247f * fTemp0;
			float fTemp26 = 0.000484f * fRec1[0];
			float fTemp27 = fConst3 * (fTemp26 + fTemp25 + 0.00204974f);
			float fTemp28 = fTemp27 + fTemp24;
			float fTemp29 = -1.0f - (fTemp28 + fTemp22);
			float fTemp30 = fRec1[0] * (fTemp21 + 2.7855381e-11f) + fRec2[0] * (fTemp20 + 3.6333107e-11f * fTemp11);
			float fTemp31 = fConst4 * fTemp30;
			float fTemp32 = fConst5 * (1.501368e-07f * fRec2[0] + fRec1[0] * (2.8930617e-07f - fTemp23) + fTemp0 * (1.087548e-05f * fRec1[0] + 2.95724e-06f) + 6.505928e-08f);
			float fTemp33 = fConst3 * (fTemp25 + fTemp26 + 0.0001034f * fRec2[0] + 0.00049434f);
			float fTemp34 = fTemp33 + fTemp32;
			fRec4[0] = fTemp18 - (fRec4[1] * (fTemp24 - (fTemp27 + 3.0f * (1.0f - fTemp22))) + fRec4[2] * (fTemp28 - 3.0f * (fTemp22 + 1.0f)) + fRec4[3] * (fTemp27 + fTemp22 + (-1.0f - fTemp24))) / fTemp29;
			float fTemp35 = fConst6 * fTemp30;
			float fTemp36 = 3.525e-09f * fTemp0;
			float fTemp37 = 4.935e-10f * fTemp0;
			float fTemp38 = fTemp37 - 1.974e-11f * fRec1[0];
			float fTemp39 = fConst4 * (fRec1[0] * (fTemp38 + -1.2126e-10f) + fTemp36 + 1.41e-10f);
			float fTemp40 = 4.70564e-07f * fRec1[0];
			float fTemp41 = fConst5 * (fRec1[0] * (1.17641e-05f * fTemp0 + -4.215336e-06f - fTemp40) + 0.000118691f * fTemp0 + 5.18864e-06f);
			float fTemp42 = 0.02503f * fTemp0;
			float fTemp43 = 0.00047f * fRec1[0];
			float fTemp44 = fConst3 * (fTemp43 + fTemp42 + 0.0157312f);
			float fTemp45 = fTemp44 + fTemp41;
			float fTemp46 = -1.0f - (fTemp45 + fTemp39);
			float fTemp47 = 1.41e-10f * fTemp11;
			float fTemp48 = fRec1[0] * (fTemp38 + 1.974e-11f) + fRec2[0] * (fTemp36 + fTemp47);
			float fTemp49 = fConst4 * fTemp48;
			float fTemp50 = fConst5 * (4.41e-07f * fRec2[0] + fRec1[0] * (4.84664e-07f - fTemp40) + fTemp0 * (1.17641e-05f * fRec1[0] + 1.191e-06f) + 4.764e-08f);
			float fTemp51 = fConst3 * (fTemp42 + fTemp43 + 3e-05f * fRec2[0] + 0.0010012f);
			float fTemp52 = fTemp51 + fTemp50;
			fRec5[0] = fTemp18 - (fRec5[1] * (fTemp41 - (fTemp44 + 3.0f * (1.0f - fTemp39))) + fRec5[2] * (fTemp45 - 3.0f * (fTemp39 + 1.0f)) + fRec5[3] * (fTemp44 + fTemp39 + (-1.0f - fTemp41))) / fTemp46;
			float fTemp53 = fConst6 * fTemp48;
			float fTemp54 = 2.42e-09f * fTemp0;
			float fTemp55 = 2.662e-10f * fTemp0 - 2.662e-12f * fRec1[0];
			float fTemp56 = fConst4 * (fRec1[0] * (fTemp55 + -2.1538e-11f) + fTemp54 + 2.42e-11f);
			float fTemp57 = 4.851e-08f * fRec1[0];
			float fTemp58 = fConst5 * (fRec1[0] * (4.851e-06f * fTemp0 + -4.2449e-07f - fTemp57) + 4.972e-05f * fTemp0 + 7.172e-07f);
			float fTemp59 = 0.02205f * fTemp0;
			float fTemp60 = 0.00022f * fRec1[0];
			float fTemp61 = fConst3 * (fTemp60 + fTemp59 + 0.0046705f);
			float fTemp62 = fTemp61 + fTemp58;
			float fTemp63 = -1.0f - (fTemp62 + fTemp56);
			float fTemp64 = fRec1[0] * (fTemp55 + 2.662e-12f) + fRec2[0] * (fTemp54 + 2.42e-11f * fTemp11);
			float fTemp65 = fConst4 * fTemp64;
			float fTemp66 = fConst5 * (2.2e-07f * fRec2[0] + fRec1[0] * (5.951e-08f - fTemp57) + fTemp0 * (4.851e-06f * fRec1[0] + 1.32e-06f) + 1.32e-08f);
			float fTemp67 = fConst3 * (fTemp59 + fTemp60 + 5e-05f * fRec2[0] + 0.0002205f);
			float fTemp68 = fTemp67 + fTemp66;
			fRec6[0] = fTemp18 - (fRec6[1] * (fTemp58 - (fTemp61 + 3.0f * (1.0f - fTemp56))) + fRec6[2] * (fTemp62 - 3.0f * (fTemp56 + 1.0f)) + fRec6[3] * (fTemp61 + fTemp56 + (-1.0f - fTemp58))) / fTemp63;
			float fTemp69 = fConst6 * fTemp64;
			float fTemp70 = 7.34375e-09f * fTemp0;
			float fTemp71 = 2.5703124e-09f * fTemp0 - 2.5703126e-10f * fRec1[0];
			float fTemp72 = fConst4 * (fRec1[0] * (fTemp71 + -4.773438e-10f) + fTemp70 + 7.34375e-10f);
			float fTemp73 = 0.00011998125f * fTemp0;
			float fTemp74 = 2.9448438e-06f * fRec1[0];
			float fTemp75 = fConst5 * (fRec1[0] * (2.9448438e-05f * fTemp0 + -8.7317185e-06f - fTemp74) + fTemp73 + 1.2916875e-05f);
			float fTemp76 = 0.0250625f * fTemp0;
			float fTemp77 = 0.001175f * fRec1[0];
			float fTemp78 = fConst3 * (fTemp77 + fTemp76 + 0.01726875f);
			float fTemp79 = fTemp78 + fTemp75;
			float fTemp80 = -1.0f - (fTemp79 + fTemp72);
			float fTemp81 = fRec1[0] * (fTemp71 + 2.5703126e-10f) + fRec2[0] * (fTemp70 + 7.34375e-10f * fTemp11);
			float fTemp82 = fConst4 * fTemp81;
			float fTemp83 = 9.1875e-07f * fRec2[0];
			float fTemp84 = fConst5 * (fTemp83 + fRec1[0] * (3.0182812e-06f - fTemp74) + fTemp0 * (2.9448438e-05f * fRec1[0] + 2.48125e-06f) + 2.48125e-07f);
			float fTemp85 = fConst3 * (fTemp76 + fTemp15 + fTemp77 + 0.00250625f);
			float fTemp86 = fTemp85 + fTemp84;
			fRec7[0] = fTemp18 - (fRec7[1] * (fTemp75 - (fTemp78 + 3.0f * (1.0f - fTemp72))) + fRec7[2] * (fTemp79 - 3.0f * (fTemp72 + 1.0f)) + fRec7[3] * (fTemp78 + fTemp72 + (-1.0f - fTemp75))) / fTemp80;
			float fTemp87 = fConst6 * fTemp81;
			float fTemp88 = 2.209e-09f * fTemp0;
			float fTemp89 = 1.3959e-09f * fTemp0 - 3.48975e-11f * fRec1[0];
			float fTemp90 = fConst4 * (fRec1[0] * (fTemp89 + -2.03275e-11f) + fTemp88 + 5.5225e-11f);
			float fTemp91 = 2.55875e-07f * fRec1[0];
			float fTemp92 = fConst5 * (fRec1[0] * (1.0235e-05f * fTemp0 + -1.55375e-07f - fTemp91) + 2.20336e-05f * fTemp0 + 7.7174e-07f);
			float fTemp93 = 0.02047f * fTemp0;
			float fTemp94 = fConst3 * (fTemp7 + fTemp93 + 0.00250925f);
			float fTemp95 = fTemp94 + fTemp92;
			float fTemp96 = -1.0f - (fTemp95 + fTemp90);
			float fTemp97 = fRec1[0] * (fTemp89 + 3.48975e-11f) + fRec2[0] * (fTemp88 + 5.5225e-11f * fTemp11);
			float fTemp98 = fConst4 * fTemp97;
			float fTemp99 = fConst5 * (2.209e-07f * fRec2[0] + fRec1[0] * (3.14625e-07f - fTemp91) + fTemp0 * (1.0235e-05f * fRec1[0] + 3.2336e-06f) + 8.084e-08f);
			float fTemp100 = fConst3 * (fTemp93 + fTemp7 + 0.0001175f * fRec2[0] + 0.00051175f);
			float fTemp101 = fTemp100 + fTemp99;
			fRec8[0] = fTemp18 - (fRec8[1] * (fTemp92 - (fTemp94 + 3.0f * (1.0f - fTemp90))) + fRec8[2] * (fTemp95 - 3.0f * (fTemp90 + 1.0f)) + fRec8[3] * (fTemp94 + fTemp90 + (-1.0f - fTemp92))) / fTemp96;
			float fTemp102 = fConst6 * fTemp97;
			float fTemp103 = fTemp37 - 9.4752e-12f * fRec1[0];
			float fTemp104 = fConst4 * (fTemp70 + fRec1[0] * (fTemp103 + -1.315248e-10f) + 1.41e-10f);
			float fTemp105 = 1.0855872e-07f * fRec1[0];
			float fTemp106 = fConst5 * (fTemp73 + fRec1[0] * (5.6541e-06f * fTemp0 + -2.1333412e-06f - fTemp105) + 3.22239e-06f);
			float fTemp107 = 0.0002256f * fRec1[0];
			float fTemp108 = fConst3 * (fTemp76 + fTemp107 + 0.0152437f);
			float fTemp109 = fTemp108 + fTemp106;
			float fTemp110 = -1.0f - (fTemp109 + fTemp104);
			float fTemp111 = fRec1[0] * (fTemp103 + 9.4752e-12f) + fRec2[0] * (fTemp47 + fTemp70);
			float fTemp112 = fConst4 * fTemp111;
			float fTemp113 = fConst5 * (fTemp83 + fRec1[0] * (1.2265872e-07f - fTemp105) + fTemp0 * (5.6541e-06f * fRec1[0] + 2.48125e-06f) + 4.764e-08f);
			float fTemp114 = fConst3 * (fTemp76 + fTemp15 + fTemp107 + 0.0004812f);
			float fTemp115 = fTemp114 + fTemp113;
			fRec9[0] = fTemp18 - (fRec9[1] * (fTemp106 - (fTemp108 + 3.0f * (1.0f - fTemp104))) + fRec9[2] * (fTemp109 - 3.0f * (fTemp104 + 1.0f)) + fRec9[3] * (fTemp108 + fTemp104 + (-1.0f - fTemp106))) / fTemp110;
			float fTemp116 = fConst6 * fTemp111;
			fRec10[0] = fSlow10 + fConst2 * fRec10[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fRec10[0] * ((iSlow1) ? ((iSlow8) ? (fRec9[1] * (fTemp113 + fTemp116 - fTemp114) + fRec9[2] * (fTemp115 - fTemp116) + fRec9[3] * (fTemp114 + fTemp112 - fTemp113) - fRec9[0] * (fTemp115 + fTemp112)) / fTemp110 : ((iSlow9) ? (fRec8[1] * (fTemp99 + fTemp102 - fTemp100) + fRec8[2] * (fTemp101 - fTemp102) + fRec8[3] * (fTemp100 + fTemp98 - fTemp99) - fRec8[0] * (fTemp101 + fTemp98)) / fTemp96 : (fRec7[1] * (fTemp84 + fTemp87 - fTemp85) + fRec7[2] * (fTemp86 - fTemp87) + fRec7[3] * (fTemp85 + fTemp82 - fTemp84) - fRec7[0] * (fTemp86 + fTemp82)) / fTemp80)) : ((iSlow2) ? ((iSlow7) ? (fRec6[1] * (fTemp66 + fTemp69 - fTemp67) + fRec6[2] * (fTemp68 - fTemp69) + fRec6[3] * (fTemp67 + fTemp65 - fTemp66) - fRec6[0] * (fTemp68 + fTemp65)) / fTemp63 : (fRec5[1] * (fTemp50 + fTemp53 - fTemp51) + fRec5[2] * (fTemp52 - fTemp53) + fRec5[3] * (fTemp51 + fTemp49 - fTemp50) - fRec5[0] * (fTemp52 + fTemp49)) / fTemp46) : ((iSlow3) ? (fRec4[1] * (fTemp32 + fTemp35 - fTemp33) + fRec4[2] * (fTemp34 - fTemp35) + fRec4[3] * (fTemp33 + fTemp31 - fTemp32) - fRec4[0] * (fTemp34 + fTemp31)) / fTemp29 : (fRec3[1] * (fTemp14 + fTemp19 - fTemp16) + fRec3[2] * (fTemp17 - fTemp19) + fRec3[3] * (fTemp16 + fTemp13 - fTemp14) - fRec3[0] * (fTemp17 + fTemp13)) / fTemp10))));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			for (int j0 = 3; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec3[j0] = fRec3[faust_wrap_sub(j0, 1)];
			}
			for (int j1 = 3; j1 > 0; j1 = faust_wrap_sub(j1, 1)) {
				fRec4[j1] = fRec4[faust_wrap_sub(j1, 1)];
			}
			for (int j2 = 3; j2 > 0; j2 = faust_wrap_sub(j2, 1)) {
				fRec5[j2] = fRec5[faust_wrap_sub(j2, 1)];
			}
			for (int j3 = 3; j3 > 0; j3 = faust_wrap_sub(j3, 1)) {
				fRec6[j3] = fRec6[faust_wrap_sub(j3, 1)];
			}
			for (int j4 = 3; j4 > 0; j4 = faust_wrap_sub(j4, 1)) {
				fRec7[j4] = fRec7[faust_wrap_sub(j4, 1)];
			}
			for (int j5 = 3; j5 > 0; j5 = faust_wrap_sub(j5, 1)) {
				fRec8[j5] = fRec8[faust_wrap_sub(j5, 1)];
			}
			for (int j6 = 3; j6 > 0; j6 = faust_wrap_sub(j6, 1)) {
				fRec9[j6] = fRec9[faust_wrap_sub(j6, 1)];
			}
			fRec10[1] = fRec10[0];
		}
	}

};

#endif
