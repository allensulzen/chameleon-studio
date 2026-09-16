/* ------------------------------------------------------------
author: "Bart Brouns"
license: "GPL-3.0-only"
name: "RMS Compressor"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibRmsCompressor -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibRmsCompressor_H__
#define  __LibRmsCompressor_H__

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
#define FAUSTCLASS LibRmsCompressor
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

static float LibRmsCompressor_faustpower2_f(float value) {
	return value * value;
}

class LibRmsCompressor : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec1[2];
	int IOTA0;
	float fRec3[524288];
	FAUSTFLOAT fHslider2;
	float fConst3;
	FAUSTFLOAT fHslider3;
	float fConst4;
	float fRec2[2];
	FAUSTFLOAT fHslider4;
	float fRec4[2];
	FAUSTFLOAT fHslider5;
	float fRec5[2];
	
 public:
	LibRmsCompressor() {
	}
	
	LibRmsCompressor(const LibRmsCompressor&) = default;
	
	virtual ~LibRmsCompressor() = default;
	
	LibRmsCompressor& operator=(const LibRmsCompressor&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Bart Brouns");
		m->declare("basics.lib/bypass1:author", "Julius Smith");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibRmsCompressor -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("compressors.lib/RMS_compression_gain_mono:author", "Bart Brouns");
		m->declare("compressors.lib/RMS_compression_gain_mono:license", "GPL-3.0-only");
		m->declare("compressors.lib/RMS_compression_gain_mono_db:author", "Bart Brouns");
		m->declare("compressors.lib/RMS_compression_gain_mono_db:license", "GPL-3.0-only");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "1.6.0");
		m->declare("description", "RMS-detected compression gain (co.RMS_compression_gain_mono) - smooth, level-riding sustain");
		m->declare("family", "dynamics");
		m->declare("filename", "lib-rms-compressor.dsp");
		m->declare("filters.lib/integrator:author", "Julius O. Smith III");
		m->declare("filters.lib/integrator:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/integrator:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("license", "GPL-3.0-only");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "RMS Compressor");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "LicenseRef-STK-4.3");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/compressors.lib co.RMS_compression_gain_mono");
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
		fConst3 = 0.001f * fConst0;
		fConst4 = 1.0f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(6.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(-3e+01f);
		fHslider2 = static_cast<FAUSTFLOAT>(2e+02f);
		fHslider3 = static_cast<FAUSTFLOAT>(2e+01f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.7f);
		fHslider5 = static_cast<FAUSTFLOAT>(6.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 524288; l2 = faust_wrap_add(l2, 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec5[l5] = 0.0f;
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
	
	virtual LibRmsCompressor* clone() {
		return new LibRmsCompressor(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("RMS Compressor");
		ui_interface->declare(&fHslider4, "0", "");
		ui_interface->addHorizontalSlider("Strength", &fHslider4, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("Threshold", &fHslider1, FAUSTFLOAT(-3e+01f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->declare(&fHslider3, "unit", "ms");
		ui_interface->addHorizontalSlider("Attack", &fHslider3, FAUSTFLOAT(2e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider2, "3", "");
		ui_interface->declare(&fHslider2, "unit", "ms");
		ui_interface->addHorizontalSlider("Release", &fHslider2, FAUSTFLOAT(2e+02f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(1.5e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "4", "");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("Knee", &fHslider0, FAUSTFLOAT(6.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider5, "5", "");
		ui_interface->declare(&fHslider5, "unit", "dB");
		ui_interface->addHorizontalSlider("Makeup", &fHslider5, FAUSTFLOAT(6.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		int iSlow2 = std::max<int>(1, static_cast<int>(fConst3 * static_cast<float>(fHslider2)));
		int iSlow3 = std::max<int>(0, iSlow2);
		float fSlow4 = 1.0f / static_cast<float>(iSlow2);
		float fSlow5 = 0.001f * static_cast<float>(fHslider3);
		int iSlow6 = std::fabs(fSlow5) < 1.1920929e-07f;
		float fSlow7 = ((iSlow6) ? 0.0f : std::exp(-(fConst4 / ((iSlow6) ? 1.0f : fSlow5))));
		float fSlow8 = fConst1 * static_cast<float>(fHslider4);
		float fSlow9 = fConst1 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider5));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = 0.5f * fRec0[0];
			fRec1[0] = fSlow1 + fConst2 * fRec1[1];
			float fTemp1 = static_cast<float>(input0[i0]);
			fRec3[IOTA0 & 524287] = LibRmsCompressor_faustpower2_f(fTemp1) + fRec3[(faust_wrap_sub(IOTA0, 1)) & 524287];
			float fTemp2 = std::sqrt(fSlow4 * (fRec3[IOTA0 & 524287] - fRec3[(faust_wrap_sub(IOTA0, iSlow3)) & 524287]));
			float fTemp3 = ((fTemp2 > fRec2[1]) ? fSlow7 : 0.0f);
			fRec2[0] = fTemp2 * (1.0f - fTemp3) + fRec2[1] * fTemp3;
			float fTemp4 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec2[0]));
			int iTemp5 = (fTemp4 > (fRec1[0] - fTemp0)) + (fTemp4 > (fRec1[0] + fTemp0));
			fRec4[0] = fSlow8 + fConst2 * fRec4[1];
			fRec5[0] = fSlow9 + fConst2 * fRec5[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp1 * fRec5[0] * std::pow(1e+01f, -(0.05f * fRec4[0] * std::max<float>(0.0f, ((iTemp5 == 0) ? 0.0f : ((iTemp5 == 1) ? 0.5f * (LibRmsCompressor_faustpower2_f(fTemp4 + fTemp0 - fRec1[0]) / std::max<float>(1.1920929e-07f, fRec0[0])) : fTemp4 - fRec1[0]))))));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
		}
	}

};

#endif
