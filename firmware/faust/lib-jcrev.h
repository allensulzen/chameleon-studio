/* ------------------------------------------------------------
author: "Julius O. Smith III"
license: "LicenseRef-STK-4.3"
name: "JCRev Schroeder"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibJcrev -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibJcrev_H__
#define  __LibJcrev_H__

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
#define FAUSTCLASS LibJcrev
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


class LibJcrev : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	float fConst3;
	int IOTA0;
	float fVec0[512];
	float fRec7[2];
	float fVec1[128];
	float fRec5[2];
	float fVec2[64];
	float fRec3[2];
	float fRec2[4096];
	float fRec9[2048];
	float fRec10[4096];
	float fRec11[2048];
	float fVec3[2];
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec12[2];
	
 public:
	LibJcrev() {
	}
	
	LibJcrev(const LibJcrev&) = default;
	
	virtual ~LibJcrev() = default;
	
	LibJcrev& operator=(const LibJcrev&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Julius O. Smith III");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibJcrev -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "John Chowning's classic Schroeder reverb (3 allpasses + 4 combs) - vintage computer-music hall");
		m->declare("family", "reverb");
		m->declare("filename", "lib-jcrev.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fb_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/fb_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>, revised by Oleg Nesterov");
		m->declare("filters.lib/fb_comb:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fb_comb_common:author", "Oleg Nesterov");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass0_highpass1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/rev1:author", "Julius O. Smith III");
		m->declare("filters.lib/rev1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/rev1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/rev2:author", "Julius O. Smith III");
		m->declare("filters.lib/rev2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/rev2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "LicenseRef-STK-4.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "JCRev Schroeder");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.5.1");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/reverbs.lib re.jcrev");
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
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(6e+03f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.3f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec1[l0] = 0.0f;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 512; l1 = faust_wrap_add(l1, 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec7[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 128; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 64; l5 = faust_wrap_add(l5, 1)) {
			fVec2[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 4096; l7 = faust_wrap_add(l7, 1)) {
			fRec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2048; l8 = faust_wrap_add(l8, 1)) {
			fRec9[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 4096; l9 = faust_wrap_add(l9, 1)) {
			fRec10[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2048; l10 = faust_wrap_add(l10, 1)) {
			fRec11[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fVec3[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec0[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec12[l13] = 0.0f;
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
	
	virtual LibJcrev* clone() {
		return new LibJcrev(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("JCRev Schroeder");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider1, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "scale", "log");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("Tone", &fHslider0, FAUSTFLOAT(6e+03f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.6e+04f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow0 + fConst2 * fRec1[1];
			float fTemp0 = 1.0f / std::tan(fConst3 * fRec1[0]);
			float fTemp1 = static_cast<float>(input0[i0]);
			float fTemp2 = 0.7f * fRec7[1] + 0.06f * fTemp1;
			fVec0[IOTA0 & 511] = fTemp2;
			fRec7[0] = fVec0[(faust_wrap_sub(IOTA0, 346)) & 511];
			float fRec8 = -(0.7f * fTemp2);
			float fTemp3 = fRec7[1] + fRec8 + 0.7f * fRec5[1];
			fVec1[IOTA0 & 127] = fTemp3;
			fRec5[0] = fVec1[(faust_wrap_sub(IOTA0, 112)) & 127];
			float fRec6 = -(0.7f * fTemp3);
			float fTemp4 = fRec5[1] + fRec6 + 0.7f * fRec3[1];
			fVec2[IOTA0 & 63] = fTemp4;
			fRec3[0] = fVec2[(faust_wrap_sub(IOTA0, 36)) & 63];
			float fRec4 = -(0.7f * fTemp4);
			float fTemp5 = fRec4 + fRec3[1];
			fRec2[IOTA0 & 4095] = fTemp5 + 0.753f * fRec2[(faust_wrap_sub(IOTA0, 2053)) & 4095];
			fRec9[IOTA0 & 2047] = fRec3[1] + fRec4 + 0.802f * fRec9[(faust_wrap_sub(IOTA0, 1601)) & 2047];
			float fTemp6 = fRec9[(faust_wrap_sub(IOTA0, 1)) & 2047] + fRec2[(faust_wrap_sub(IOTA0, 1)) & 4095];
			fRec10[IOTA0 & 4095] = fTemp5 + 0.733f * fRec10[(faust_wrap_sub(IOTA0, 2251)) & 4095];
			fRec11[IOTA0 & 2047] = fTemp5 + 0.773f * fRec11[(faust_wrap_sub(IOTA0, 1867)) & 2047];
			float fTemp7 = fRec11[(faust_wrap_sub(IOTA0, 1)) & 2047] + fRec10[(faust_wrap_sub(IOTA0, 1)) & 4095];
			float fTemp8 = fTemp7 - (fTemp6 + (fTemp7 - fTemp6));
			fVec3[0] = fTemp8;
			fRec0[0] = (0.25f * (fTemp8 + fVec3[1]) - fRec0[1] * (1.0f - fTemp0)) / (fTemp0 + 1.0f);
			fRec12[0] = fSlow1 + fConst2 * fRec12[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp1 * (1.0f - fRec12[0]) + fRec12[0] * fRec0[0]);
			fRec1[1] = fRec1[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec7[1] = fRec7[0];
			fRec5[1] = fRec5[0];
			fRec3[1] = fRec3[0];
			fVec3[1] = fVec3[0];
			fRec0[1] = fRec0[0];
			fRec12[1] = fRec12[0];
		}
	}

};

#endif
