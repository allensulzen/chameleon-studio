/* ------------------------------------------------------------
author: "David Braun"
license: "LicenseRef-STK-4.3"
name: "Tape Stop"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibTapeStop -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibTapeStop_H__
#define  __LibTapeStop_H__

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
#define FAUSTCLASS LibTapeStop
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


class LibTapeStop : public chdsp {
	
 private:
	
	FAUSTFLOAT fCheckbox0;
	float fVec0[2];
	int iRec2[2];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	int IOTA0;
	float fVec1[262144];
	FAUSTFLOAT fHslider3;
	float fConst2;
	float fRec3[2];
	
 public:
	LibTapeStop() {
	}
	
	LibTapeStop(const LibTapeStop&) = default;
	
	virtual ~LibTapeStop() = default;
	
	LibTapeStop& operator=(const LibTapeStop&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "David Braun");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibTapeStop -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/fdelayltv:author", "Julius O. Smith III");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "David Braun's tape-stop: engage Stop and playback decelerates to a halt with adjustable curve");
		m->declare("family", "pitch");
		m->declare("filename", "lib-tape-stop.dsp");
		m->declare("license", "LicenseRef-STK-4.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/tapeStop:author", "David Braun");
		m->declare("misceffects.lib/tapeStop:copyright", "Copyright (C) 2024 by David Braun <braun@ccrma.stanford.edu>");
		m->declare("misceffects.lib/tapeStop:license", "LicenseRef-STK-4.3");
		m->declare("misceffects.lib/version", "2.6.0");
		m->declare("name", "Tape Stop");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/misceffects.lib ef.tapeStop");
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
		fConst1 = 1e+03f / fConst0;
		fConst2 = 0.001f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider0 = static_cast<FAUSTFLOAT>(6e+02f);
		fHslider1 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(3.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iRec2[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec0[l2] = 0.0f;
		}
		IOTA0 = 0;
		for (int l3 = 0; l3 < 262144; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec3[l4] = 0.0f;
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
	
	virtual LibTapeStop* clone() {
		return new LibTapeStop(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Tape Stop");
		ui_interface->declare(&fCheckbox0, "0", "");
		ui_interface->addCheckButton("Stop", &fCheckbox0);
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "unit", "ms");
		ui_interface->addHorizontalSlider("Stop Time", &fHslider0, FAUSTFLOAT(6e+02f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(4e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->addHorizontalSlider("Stop Curve", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "3", "");
		ui_interface->addHorizontalSlider("Gain Curve", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "4", "");
		ui_interface->declare(&fHslider3, "unit", "ms");
		ui_interface->addHorizontalSlider("Crossfade", &fHslider3, FAUSTFLOAT(3.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(125.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = static_cast<float>(fCheckbox0);
		int iSlow1 = static_cast<int>(fSlow0);
		float fSlow2 = fConst1 / static_cast<float>(fHslider0);
		float fSlow3 = static_cast<float>(fHslider1);
		float fSlow4 = static_cast<float>(fHslider2);
		float fSlow5 = static_cast<float>(fSlow0 >= 1.0f);
		float fSlow6 = 1.0f / ((iSlow1) ? 0.0f : fConst2 * static_cast<float>(fHslider3));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fVec0[0] = fSlow0;
			int iTemp0 = iSlow1 & static_cast<int>(1.0f - fVec0[1]);
			iRec2[0] = faust_wrap_add(faust_wrap_mul(iRec2[1], ((iTemp0) ? 0 : 1)), 1);
			float fTemp1 = std::max<float>(0.0f, 1.0f - fSlow2 * static_cast<float>(faust_wrap_add(iRec2[0], -1)));
			float fTemp2 = ((iTemp0) ? 1.0f : fRec0[1]) + (1.0f - std::pow(fTemp1, fSlow3));
			fRec0[0] = fTemp2;
			float fTemp3 = static_cast<float>(input0[i0]);
			fVec1[IOTA0 & 262143] = fTemp3;
			float fTemp4 = std::max<float>(fTemp2, 1.0f);
			float fTemp5 = fTemp4 + -0.999995f;
			int iTemp6 = static_cast<int>(fTemp5);
			float fTemp7 = std::floor(fTemp5);
			float fTemp8 = fTemp4 + (-2.0f - fTemp7);
			float fTemp9 = fTemp4 + (-1.0f - fTemp7);
			float fTemp10 = fTemp4 - fTemp7;
			float fTemp11 = fTemp10 * fTemp9;
			float fTemp12 = fRec3[1] + fSlow6;
			float fTemp13 = fRec3[1] - fSlow6;
			fRec3[0] = ((fTemp12 < fSlow5) ? fTemp12 : ((fTemp13 > fSlow5) ? fTemp13 : fSlow5));
			float fRec1 = fVec1[(faust_wrap_sub(IOTA0, 1)) & 262143] * (1.0f - fRec3[0]) + fRec3[0] * ((fTemp4 + (-3.0f - fTemp7)) * (fTemp8 * (0.5f * fTemp10 * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(192000, std::max<int>(0, faust_wrap_add(iTemp6, 1))))) & 262143] - 0.16666667f * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(192000, std::max<int>(0, iTemp6)))) & 262143] * fTemp9) - 0.5f * fTemp11 * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(192000, std::max<int>(0, faust_wrap_add(iTemp6, 2))))) & 262143]) + 0.16666667f * fTemp11 * fTemp8 * fVec1[(faust_wrap_sub(IOTA0, std::min<int>(192000, std::max<int>(0, faust_wrap_add(iTemp6, 3))))) & 262143]) * std::pow(fTemp1, fSlow4);
			output0[i0] = static_cast<FAUSTFLOAT>(fRec1);
			fVec0[1] = fVec0[0];
			iRec2[1] = iRec2[0];
			fRec0[1] = fRec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
