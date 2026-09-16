/* ------------------------------------------------------------
author: "Dario Sanfilippo"
license: "GPL-3.0-only"
name: "Lookahead Limiter"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibLookaheadLimiter -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibLookaheadLimiter_H__
#define  __LibLookaheadLimiter_H__

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
#define FAUSTCLASS LibLookaheadLimiter
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


class LibLookaheadLimiter : public chdsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst2;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider2;
	float fRec4[2];
	int IOTA0;
	float fVec0[2048];
	int iRec2[2];
	float fRec3[2];
	float fRec1[2];
	FAUSTFLOAT fHslider3;
	float fRec0[2];
	FAUSTFLOAT fHslider4;
	int iConst5;
	
 public:
	LibLookaheadLimiter() {
	}
	
	LibLookaheadLimiter(const LibLookaheadLimiter&) = default;
	
	virtual ~LibLookaheadLimiter() = default;
	
	LibLookaheadLimiter& operator=(const LibLookaheadLimiter&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Dario Sanfilippo");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/peakholder:author", "Dario Sanfilippo");
		m->declare("basics.lib/peakholder:copyright", "Copyright (C) 2022 Dario Sanfilippo <sanfilippo.dario@gmail.com>");
		m->declare("basics.lib/peakholder:license", "LicenseRef-STK-4.3");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "drum");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibLookaheadLimiter -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("compressors.lib/limiter_lad_N:author", "Dario Sanfilippo");
		m->declare("compressors.lib/limiter_lad_N:copyright", "Copyright (C) 2020 Dario Sanfilippo       <sanfilippo.dario@gmail.com>");
		m->declare("compressors.lib/limiter_lad_N:license", "GPL-3.0-only");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "1.6.0");
		m->declare("description", "Dario Sanfilippo's IEM-style lookahead brickwall limiter with ceiling, hold and release");
		m->declare("family", "dynamics");
		m->declare("filename", "lib-lookahead-limiter.dsp");
		m->declare("license", "GPL-3.0-only");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Lookahead Limiter");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/compressors.lib co.limiter_lad_N");
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
		fConst1 = 1.0f / fConst0;
		fConst2 = 0.001f * fConst0;
		fConst3 = 44.1f / fConst0;
		fConst4 = 1.0f - fConst3;
		iConst5 = static_cast<int>(0.01f * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(3.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(3e+01f);
		fHslider2 = static_cast<FAUSTFLOAT>(12.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(1e+02f);
		fHslider4 = static_cast<FAUSTFLOAT>(-1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec4[l0] = 0.0f;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 2048; l1 = faust_wrap_add(l1, 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			iRec2[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec0[l5] = 0.0f;
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
	
	virtual LibLookaheadLimiter* clone() {
		return new LibLookaheadLimiter(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Lookahead Limiter");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("Input", &fHslider2, FAUSTFLOAT(12.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider4, "1", "");
		ui_interface->declare(&fHslider4, "unit", "dB");
		ui_interface->addHorizontalSlider("Ceiling", &fHslider4, FAUSTFLOAT(-1.0f), FAUSTFLOAT(-2e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->declare(&fHslider0, "unit", "ms");
		ui_interface->addHorizontalSlider("Attack", &fHslider0, FAUSTFLOAT(3.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(6.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->declare(&fHslider1, "unit", "ms");
		ui_interface->addHorizontalSlider("Hold", &fHslider1, FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "4", "");
		ui_interface->declare(&fHslider3, "unit", "ms");
		ui_interface->addHorizontalSlider("Release", &fHslider3, FAUSTFLOAT(1e+02f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = 0.001f * static_cast<float>(fHslider0);
		int iSlow1 = std::fabs(fSlow0) < 1.1920929e-07f;
		float fSlow2 = ((iSlow1) ? 0.0f : std::exp(-(fConst1 / ((iSlow1) ? 1.0f : fSlow0))));
		float fSlow3 = 1.0f - fSlow2;
		float fSlow4 = fConst2 * static_cast<float>(fHslider1);
		float fSlow5 = fConst3 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider2));
		float fSlow6 = 0.001f * static_cast<float>(fHslider3);
		int iSlow7 = std::fabs(fSlow6) < 1.1920929e-07f;
		float fSlow8 = ((iSlow7) ? 0.0f : std::exp(-(fConst1 / ((iSlow7) ? 1.0f : fSlow6))));
		float fSlow9 = 1.0f - fSlow8;
		float fSlow10 = std::pow(1e+01f, 0.05f * static_cast<float>(fHslider4));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec4[0] = fSlow5 + fConst4 * fRec4[1];
			float fTemp0 = static_cast<float>(input0[i0]) * fRec4[0];
			fVec0[IOTA0 & 2047] = fTemp0;
			float fTemp1 = std::fabs(fTemp0);
			int iTemp2 = (fTemp1 >= fRec3[1]) | (static_cast<float>(iRec2[1]) >= fSlow4);
			iRec2[0] = ((iTemp2) ? 0 : faust_wrap_add(iRec2[1], 1));
			fRec3[0] = ((iTemp2) ? fTemp1 : fRec3[1]);
			fRec1[0] = fRec3[0] * fSlow3 + fSlow2 * fRec1[1];
			float fTemp3 = std::fabs(fRec1[0]);
			fRec0[0] = std::max<float>(fTemp3, fRec0[1] * fSlow8 + fTemp3 * fSlow9);
			output0[i0] = static_cast<FAUSTFLOAT>(fVec0[(faust_wrap_sub(IOTA0, iConst5)) & 2047] * std::min<float>(1.0f, fSlow10 / std::max<float>(fRec0[0], 1.1920929e-07f)));
			fRec4[1] = fRec4[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			iRec2[1] = iRec2[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
