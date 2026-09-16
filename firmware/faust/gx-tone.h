/* ------------------------------------------------------------
author: "brummer"
copyright: "(c)brummer 2008"
license: "BSD"
name: "gx-tone"
version: "0.01"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTone -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxTone_H__
#define  __GxTone_H__

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
#define FAUSTCLASS GxTone
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


class GxTone : public chdsp {
	
 private:
	
	double fVec0[3];
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fRec3[3];
	double fConst4;
	double fConst5;
	double fConst6;
	double fRec2[3];
	double fRec1[3];
	FAUSTFLOAT fVslider2;
	double fRec0[3];
	
 public:
	GxTone() {
	}
	
	GxTone(const GxTone&) = default;
	
	virtual ~GxTone() = default;
	
	GxTone& operator=(const GxTone&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "brummer");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTone -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("copyright", "(c)brummer 2008");
		m->declare("filename", "gx-tone.dsp");
		m->declare("id", "amp.tone");
		m->declare("license", "BSD");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "gx-tone");
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
		fConst1 = 3769.9111843077517 / fConst0;
		fConst2 = 1.4142135623730951 * std::sin(fConst1);
		fConst3 = std::cos(fConst1);
		fConst4 = 15079.644737231007 / fConst0;
		fConst5 = 1.4142135623730951 * std::sin(fConst4);
		fConst6 = std::cos(fConst4);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider1 = static_cast<FAUSTFLOAT>(0.0);
		fVslider2 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 3; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 3; l1 = faust_wrap_add(l1, 1)) {
			fRec3[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fRec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec0[l4] = 0.0;
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
	
	virtual GxTone* clone() {
		return new GxTone(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("gx-tone");
		ui_interface->declare(&fVslider1, "name", "bass");
		ui_interface->addVerticalSlider("bass", &fVslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider0, "name", "middle");
		ui_interface->addVerticalSlider("middle", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider2, "name", "treble");
		ui_interface->addVerticalSlider("treble", &fVslider2, FAUSTFLOAT(0.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fVslider0);
		double fSlow1 = 0.5 * fSlow0;
		double fSlow2 = std::pow(1e+01, 0.025 * (static_cast<double>(fVslider1) - fSlow1));
		double fSlow3 = fConst2 * std::sqrt(fSlow2);
		double fSlow4 = fConst3 * (fSlow2 + -1.0);
		double fSlow5 = fSlow2 + (1.0 - (fSlow4 + fSlow3));
		double fSlow6 = fConst3 * (fSlow2 + 1.0);
		double fSlow7 = 2.0 * (fSlow2 + (-1.0 - fSlow6));
		double fSlow8 = fSlow2 + fSlow3 + (1.0 - fSlow4);
		double fSlow9 = fSlow2 + fSlow4;
		double fSlow10 = fSlow9 + (1.0 - fSlow3);
		double fSlow11 = 2.0 * (fSlow2 + fSlow6 + -1.0);
		double fSlow12 = 1.0 / (fSlow9 + fSlow3 + 1.0);
		double fSlow13 = std::pow(1e+01, 0.0125 * fSlow0);
		double fSlow14 = std::sqrt(fSlow13);
		double fSlow15 = fConst5 * fSlow14;
		double fSlow16 = fSlow13 + -1.0;
		double fSlow17 = fConst6 * fSlow16;
		double fSlow18 = fSlow13 + (1.0 - (fSlow17 + fSlow15));
		double fSlow19 = fSlow13 + 1.0;
		double fSlow20 = fConst6 * fSlow19;
		double fSlow21 = 2.0 * (fSlow13 + (-1.0 - fSlow20));
		double fSlow22 = fSlow13 + fSlow15 + (1.0 - fSlow17);
		double fSlow23 = fSlow13 + fSlow17;
		double fSlow24 = fSlow23 + (1.0 - fSlow15);
		double fSlow25 = 2.0 * (fSlow13 + fSlow20 + -1.0);
		double fSlow26 = 1.0 / (fSlow23 + fSlow15 + 1.0);
		double fSlow27 = fConst2 * fSlow14;
		double fSlow28 = fConst3 * fSlow16;
		double fSlow29 = fSlow13 + fSlow28;
		double fSlow30 = fSlow29 + (1.0 - fSlow27);
		double fSlow31 = fConst3 * fSlow19;
		double fSlow32 = 2.0 * (fSlow13 + fSlow31 + -1.0);
		double fSlow33 = fSlow27 + fSlow29 + 1.0;
		double fSlow34 = 2.0 * (fSlow13 + (-1.0 - fSlow31));
		double fSlow35 = fSlow13 + (1.0 - (fSlow28 + fSlow27));
		double fSlow36 = 1.0 / (fSlow13 + fSlow27 + (1.0 - fSlow28));
		double fSlow37 = std::pow(1e+01, 0.025 * (static_cast<double>(fVslider2) - fSlow1));
		double fSlow38 = fConst5 * std::sqrt(fSlow37);
		double fSlow39 = fConst6 * (fSlow37 + -1.0);
		double fSlow40 = fSlow37 + fSlow39;
		double fSlow41 = fSlow40 + (1.0 - fSlow38);
		double fSlow42 = fConst6 * (fSlow37 + 1.0);
		double fSlow43 = 2.0 * (fSlow37 + fSlow42 + -1.0);
		double fSlow44 = fSlow38 + fSlow40 + 1.0;
		double fSlow45 = 2.0 * (fSlow37 + (-1.0 - fSlow42));
		double fSlow46 = fSlow37 + (1.0 - (fSlow39 + fSlow38));
		double fSlow47 = 1.0 / (fSlow37 + fSlow38 + (1.0 - fSlow39));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]) + 1e-20;
			fVec0[0] = fTemp0;
			fRec3[0] = fSlow12 * (fSlow11 * fRec3[1] - fSlow10 * fRec3[2] + fSlow2 * (fSlow8 * fTemp0 + fSlow7 * fVec0[1] + fSlow5 * fVec0[2]));
			fRec2[0] = fSlow26 * (fSlow25 * fRec2[1] - fSlow24 * fRec2[2] + fSlow13 * (fSlow22 * fRec3[0] + fSlow21 * fRec3[1] + fSlow18 * fRec3[2]));
			fRec1[0] = -(fSlow36 * (fSlow35 * fRec1[2] + fSlow34 * fRec1[1] - fSlow13 * (fSlow33 * fRec2[0] - fSlow32 * fRec2[1] + fSlow30 * fRec2[2])));
			fRec0[0] = -(fSlow47 * (fSlow46 * fRec0[2] + fSlow45 * fRec0[1] - fSlow37 * (fSlow44 * fRec1[0] - fSlow43 * fRec1[1] + fSlow41 * fRec1[2])));
			output0[i0] = static_cast<FAUSTFLOAT>(fRec0[0]);
			fVec0[2] = fVec0[1];
			fVec0[1] = fVec0[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
