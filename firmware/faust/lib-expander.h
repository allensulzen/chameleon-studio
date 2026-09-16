/* ------------------------------------------------------------
author: "Bart Brouns"
license: "GPL-3.0-only"
name: "Expander"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibExpander -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibExpander_H__
#define  __LibExpander_H__

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
#define FAUSTCLASS LibExpander
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

static float LibExpander_faustpower2_f(float value) {
	return value * value;
}

class LibExpander : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec1[2];
	FAUSTFLOAT fHslider3;
	float fRec2[2];
	FAUSTFLOAT fHslider4;
	float fConst3;
	float fVec0[2];
	float fConst4;
	float fVec1[3];
	float fConst5;
	float fVec2[5];
	float fConst6;
	float fVec3[12];
	float fConst7;
	int IOTA0;
	float fVec4[32];
	float fConst8;
	float fVec5[64];
	float fConst9;
	float fVec6[128];
	float fConst10;
	float fVec7[256];
	float fConst11;
	float fVec8[512];
	float fConst12;
	float fVec9[1024];
	float fConst13;
	float fVec10[2048];
	float fConst14;
	float fVec11[4096];
	float fConst15;
	float fVec12[8192];
	float fConst16;
	float fVec13[16384];
	float fConst17;
	float fVec14[32768];
	FAUSTFLOAT fHslider5;
	float fConst18;
	FAUSTFLOAT fHslider6;
	float fRec3[2];
	
 public:
	LibExpander() {
	}
	
	LibExpander(const LibExpander&) = default;
	
	virtual ~LibExpander() = default;
	
	LibExpander& operator=(const LibExpander&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Bart Brouns");
		m->declare("basics.lib/bypass1:author", "Julius Smith");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/parallelOp:author", "Bart Brouns");
		m->declare("basics.lib/parallelOp:copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/parallelOp:licence", "GPL-3.0-only");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibExpander -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("compressors.lib/expanderSC_N_chan:author", "Bart Brouns");
		m->declare("compressors.lib/expanderSC_N_chan:license", "GPL-3.0-only");
		m->declare("compressors.lib/expander_N_chan:author", "Bart Brouns");
		m->declare("compressors.lib/expander_N_chan:license", "GPL-3.0-only");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/peak_expansion_gain_N_chan_db:author", "Bart Brouns");
		m->declare("compressors.lib/peak_expansion_gain_N_chan_db:license", "GPL-3.0-only");
		m->declare("compressors.lib/peak_expansion_gain_mono_db:author", "Bart Brouns");
		m->declare("compressors.lib/peak_expansion_gain_mono_db:license", "GPL-3.0-only");
		m->declare("compressors.lib/version", "1.6.0");
		m->declare("description", "Downward expander (co.expander_N_chan) with range, hold and knee - tightens noise between notes");
		m->declare("family", "dynamics");
		m->declare("filename", "lib-expander.dsp");
		m->declare("license", "GPL-3.0-only");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Expander");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/lag_ud:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/lag_ud:licence", "LicenseRef-STK-4.3");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "LicenseRef-STK-4.3");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/compressors.lib co.expander_N_chan");
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
		fConst4 = 0.0005f * fConst0;
		fConst5 = 0.00025f * fConst0;
		fConst6 = 0.000125f * fConst0;
		fConst7 = 6.25e-05f * fConst0;
		fConst8 = 3.125e-05f * fConst0;
		fConst9 = 1.5625e-05f * fConst0;
		fConst10 = 7.8125e-06f * fConst0;
		fConst11 = 3.90625e-06f * fConst0;
		fConst12 = 1.953125e-06f * fConst0;
		fConst13 = 9.765625e-07f * fConst0;
		fConst14 = 4.882813e-07f * fConst0;
		fConst15 = 2.4414064e-07f * fConst0;
		fConst16 = 1.2207032e-07f * fConst0;
		fConst17 = 6.103516e-08f * fConst0;
		fConst18 = 1.0f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(2.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(4e+01f);
		fHslider2 = static_cast<FAUSTFLOAT>(6.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(-4e+01f);
		fHslider4 = static_cast<FAUSTFLOAT>(2e+01f);
		fHslider5 = static_cast<FAUSTFLOAT>(1e+02f);
		fHslider6 = static_cast<FAUSTFLOAT>(2.0f);
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
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec0[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 5; l5 = faust_wrap_add(l5, 1)) {
			fVec2[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 12; l6 = faust_wrap_add(l6, 1)) {
			fVec3[l6] = 0.0f;
		}
		IOTA0 = 0;
		for (int l7 = 0; l7 < 32; l7 = faust_wrap_add(l7, 1)) {
			fVec4[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 64; l8 = faust_wrap_add(l8, 1)) {
			fVec5[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 128; l9 = faust_wrap_add(l9, 1)) {
			fVec6[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 256; l10 = faust_wrap_add(l10, 1)) {
			fVec7[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 512; l11 = faust_wrap_add(l11, 1)) {
			fVec8[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 1024; l12 = faust_wrap_add(l12, 1)) {
			fVec9[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2048; l13 = faust_wrap_add(l13, 1)) {
			fVec10[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 4096; l14 = faust_wrap_add(l14, 1)) {
			fVec11[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 8192; l15 = faust_wrap_add(l15, 1)) {
			fVec12[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 16384; l16 = faust_wrap_add(l16, 1)) {
			fVec13[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 32768; l17 = faust_wrap_add(l17, 1)) {
			fVec14[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec3[l18] = 0.0f;
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
	
	virtual LibExpander* clone() {
		return new LibExpander(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Expander");
		ui_interface->declare(&fHslider0, "0", "");
		ui_interface->addHorizontalSlider("Strength", &fHslider0, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->declare(&fHslider3, "unit", "dB");
		ui_interface->addHorizontalSlider("Threshold", &fHslider3, FAUSTFLOAT(-4e+01f), FAUSTFLOAT(-8e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("Range", &fHslider1, FAUSTFLOAT(4e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(8e+01f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider6, "3", "");
		ui_interface->declare(&fHslider6, "unit", "ms");
		ui_interface->addHorizontalSlider("Attack", &fHslider6, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider4, "4", "");
		ui_interface->declare(&fHslider4, "unit", "ms");
		ui_interface->addHorizontalSlider("Hold", &fHslider4, FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider5, "5", "");
		ui_interface->declare(&fHslider5, "unit", "ms");
		ui_interface->addHorizontalSlider("Release", &fHslider5, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "6", "");
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("Knee", &fHslider2, FAUSTFLOAT(6.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider2);
		float fSlow2 = fConst1 * static_cast<float>(fHslider3);
		float fSlow3 = static_cast<float>(fHslider4);
		int iSlow4 = static_cast<int>(std::floor(fConst3 * fSlow3)) % 2;
		int iSlow5 = static_cast<int>(std::floor(fConst4 * fSlow3)) % 2;
		int iSlow6 = static_cast<int>(std::floor(fConst5 * fSlow3)) % 2;
		int iSlow7 = faust_wrap_add(iSlow4, faust_wrap_mul(2, iSlow5));
		int iSlow8 = static_cast<int>(std::floor(fConst6 * fSlow3)) % 2;
		int iSlow9 = faust_wrap_add(iSlow7, faust_wrap_mul(4, iSlow6));
		int iSlow10 = static_cast<int>(std::floor(fConst7 * fSlow3)) % 2;
		int iSlow11 = faust_wrap_add(iSlow9, faust_wrap_mul(8, iSlow8));
		int iSlow12 = static_cast<int>(std::floor(fConst8 * fSlow3)) % 2;
		int iSlow13 = faust_wrap_add(iSlow11, faust_wrap_mul(16, iSlow10));
		int iSlow14 = static_cast<int>(std::floor(fConst9 * fSlow3)) % 2;
		int iSlow15 = faust_wrap_add(iSlow13, faust_wrap_mul(32, iSlow12));
		int iSlow16 = static_cast<int>(std::floor(fConst10 * fSlow3)) % 2;
		int iSlow17 = faust_wrap_add(iSlow15, faust_wrap_mul(64, iSlow14));
		int iSlow18 = static_cast<int>(std::floor(fConst11 * fSlow3)) % 2;
		int iSlow19 = faust_wrap_add(iSlow17, faust_wrap_mul(128, iSlow16));
		int iSlow20 = static_cast<int>(std::floor(fConst12 * fSlow3)) % 2;
		int iSlow21 = faust_wrap_add(iSlow19, faust_wrap_mul(256, iSlow18));
		int iSlow22 = static_cast<int>(std::floor(fConst13 * fSlow3)) % 2;
		int iSlow23 = faust_wrap_add(iSlow21, faust_wrap_mul(512, iSlow20));
		int iSlow24 = static_cast<int>(std::floor(fConst14 * fSlow3)) % 2;
		int iSlow25 = faust_wrap_add(iSlow23, faust_wrap_mul(1024, iSlow22));
		int iSlow26 = static_cast<int>(std::floor(fConst15 * fSlow3)) % 2;
		int iSlow27 = faust_wrap_add(iSlow25, faust_wrap_mul(2048, iSlow24));
		int iSlow28 = static_cast<int>(std::floor(fConst16 * fSlow3)) % 2;
		int iSlow29 = faust_wrap_add(iSlow27, faust_wrap_mul(4096, iSlow26));
		int iSlow30 = static_cast<int>(std::floor(fConst17 * fSlow3)) % 2;
		int iSlow31 = faust_wrap_add(iSlow29, faust_wrap_mul(8192, iSlow28));
		float fSlow32 = 0.001f * static_cast<float>(fHslider5);
		int iSlow33 = std::fabs(fSlow32) < 1.1920929e-07f;
		float fSlow34 = ((iSlow33) ? 0.0f : std::exp(-(fConst18 / ((iSlow33) ? 1.0f : fSlow32))));
		float fSlow35 = 0.001f * static_cast<float>(fHslider6);
		int iSlow36 = std::fabs(fSlow35) < 1.1920929e-07f;
		float fSlow37 = ((iSlow36) ? 0.0f : std::exp(-(fConst18 / ((iSlow36) ? 1.0f : fSlow35))));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			fRec1[0] = fSlow1 + fConst2 * fRec1[1];
			float fTemp0 = 0.5f * fRec1[0];
			fRec2[0] = fSlow2 + fConst2 * fRec2[1];
			float fTemp1 = fRec2[0] + fTemp0;
			float fTemp2 = static_cast<float>(input0[i0]);
			float fTemp3 = std::fabs(fTemp2);
			fVec0[0] = fTemp3;
			float fTemp4 = std::max<float>(fTemp3, fVec0[1]);
			fVec1[0] = fTemp4;
			float fTemp5 = std::max<float>(fTemp4, fVec1[2]);
			fVec2[0] = fTemp5;
			float fTemp6 = std::max<float>(fTemp5, fVec2[4]);
			fVec3[0] = fTemp6;
			float fTemp7 = std::max<float>(fTemp6, fVec3[8]);
			fVec4[IOTA0 & 31] = fTemp7;
			float fTemp8 = std::max<float>(fTemp7, fVec4[(faust_wrap_sub(IOTA0, 16)) & 31]);
			fVec5[IOTA0 & 63] = fTemp8;
			float fTemp9 = std::max<float>(fTemp8, fVec5[(faust_wrap_sub(IOTA0, 32)) & 63]);
			fVec6[IOTA0 & 127] = fTemp9;
			float fTemp10 = std::max<float>(fTemp9, fVec6[(faust_wrap_sub(IOTA0, 64)) & 127]);
			fVec7[IOTA0 & 255] = fTemp10;
			float fTemp11 = std::max<float>(fTemp10, fVec7[(faust_wrap_sub(IOTA0, 128)) & 255]);
			fVec8[IOTA0 & 511] = fTemp11;
			float fTemp12 = std::max<float>(fTemp11, fVec8[(faust_wrap_sub(IOTA0, 256)) & 511]);
			fVec9[IOTA0 & 1023] = fTemp12;
			float fTemp13 = std::max<float>(fTemp12, fVec9[(faust_wrap_sub(IOTA0, 512)) & 1023]);
			fVec10[IOTA0 & 2047] = fTemp13;
			float fTemp14 = std::max<float>(fTemp13, fVec10[(faust_wrap_sub(IOTA0, 1024)) & 2047]);
			fVec11[IOTA0 & 4095] = fTemp14;
			float fTemp15 = std::max<float>(fTemp14, fVec11[(faust_wrap_sub(IOTA0, 2048)) & 4095]);
			fVec12[IOTA0 & 8191] = fTemp15;
			float fTemp16 = std::max<float>(fTemp15, fVec12[(faust_wrap_sub(IOTA0, 4096)) & 8191]);
			fVec13[IOTA0 & 16383] = fTemp16;
			fVec14[IOTA0 & 32767] = std::max<float>(fTemp16, fVec13[(faust_wrap_sub(IOTA0, 8192)) & 16383]);
			float fTemp17 = std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(((iSlow4) ? fTemp3 : -3.4028235e+38f), ((iSlow5) ? fVec1[iSlow4] : -3.4028235e+38f)), ((iSlow6) ? fVec2[iSlow7] : -3.4028235e+38f)), ((iSlow8) ? fVec3[iSlow9] : -3.4028235e+38f)), ((iSlow10) ? fVec4[(faust_wrap_sub(IOTA0, iSlow11)) & 31] : -3.4028235e+38f)), ((iSlow12) ? fVec5[(faust_wrap_sub(IOTA0, iSlow13)) & 63] : -3.4028235e+38f)), ((iSlow14) ? fVec6[(faust_wrap_sub(IOTA0, iSlow15)) & 127] : -3.4028235e+38f)), ((iSlow16) ? fVec7[(faust_wrap_sub(IOTA0, iSlow17)) & 255] : -3.4028235e+38f)), ((iSlow18) ? fVec8[(faust_wrap_sub(IOTA0, iSlow19)) & 511] : -3.4028235e+38f)), ((iSlow20) ? fVec9[(faust_wrap_sub(IOTA0, iSlow21)) & 1023] : -3.4028235e+38f)), ((iSlow22) ? fVec10[(faust_wrap_sub(IOTA0, iSlow23)) & 2047] : -3.4028235e+38f)), ((iSlow24) ? fVec11[(faust_wrap_sub(IOTA0, iSlow25)) & 4095] : -3.4028235e+38f)), ((iSlow26) ? fVec12[(faust_wrap_sub(IOTA0, iSlow27)) & 8191] : -3.4028235e+38f)), ((iSlow28) ? fVec13[(faust_wrap_sub(IOTA0, iSlow29)) & 16383] : -3.4028235e+38f)), ((iSlow30) ? fVec14[(faust_wrap_sub(IOTA0, iSlow31)) & 32767] : -3.4028235e+38f));
			float fTemp18 = ((fTemp17 > fRec3[1]) ? fSlow37 : fSlow34);
			fRec3[0] = fTemp17 * (1.0f - fTemp18) + fRec3[1] * fTemp18;
			float fTemp19 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec3[0]));
			int iTemp20 = (fTemp19 > (fRec2[0] - fTemp0)) + (fTemp19 > fTemp1);
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp2 * std::pow(1e+01f, 0.05f * std::max<float>(-(static_cast<float>(fHslider1)), std::fabs(fRec0[0]) * ((iTemp20 == 0) ? fTemp19 - fRec2[0] : ((iTemp20 == 1) ? LibExpander_faustpower2_f(fTemp19 - fTemp1) / std::min<float>(1.1920929e-07f, -(2.0f * fRec1[0])) : 0.0f))) * static_cast<float>(faust_wrap_add(faust_wrap_mul(2, fRec0[0] > 0.0f), -1))));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fVec0[1] = fVec0[0];
			fVec1[2] = fVec1[1];
			fVec1[1] = fVec1[0];
			for (int j0 = 4; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fVec2[j0] = fVec2[faust_wrap_sub(j0, 1)];
			}
			for (int j1 = 11; j1 > 0; j1 = faust_wrap_sub(j1, 1)) {
				fVec3[j1] = fVec3[faust_wrap_sub(j1, 1)];
			}
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
