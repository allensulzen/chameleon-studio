/* ------------------------------------------------------------
author: "Bart Brouns (compressors), Julius O. Smith III (filterbank)"
license: "GPL-3.0-only"
name: "3-Band Compressor"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn Lib3bandCompressor -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __Lib3bandCompressor_H__
#define  __Lib3bandCompressor_H__

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
#define FAUSTCLASS Lib3bandCompressor
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

static float Lib3bandCompressor_faustpower2_f(float value) {
	return value * value;
}

class Lib3bandCompressor : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fVec0[2];
	float fRec5[2];
	float fRec4[3];
	float fVec1[2];
	float fRec3[2];
	float fRec2[3];
	FAUSTFLOAT fHslider3;
	float fConst4;
	FAUSTFLOAT fHslider4;
	float fRec1[2];
	FAUSTFLOAT fHslider5;
	float fRec6[2];
	float fRec9[2];
	float fRec8[3];
	float fRec7[2];
	FAUSTFLOAT fHslider6;
	float fRec10[2];
	float fRec14[2];
	float fRec13[3];
	float fRec12[3];
	float fRec11[2];
	FAUSTFLOAT fHslider7;
	float fRec15[2];
	FAUSTFLOAT fHslider8;
	float fRec16[2];
	
 public:
	Lib3bandCompressor() {
	}
	
	Lib3bandCompressor(const Lib3bandCompressor&) = default;
	
	virtual ~Lib3bandCompressor() = default;
	
	Lib3bandCompressor& operator=(const Lib3bandCompressor&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Bart Brouns (compressors), Julius O. Smith III (filterbank)");
		m->declare("basics.lib/bypass1:author", "Julius Smith");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "drum");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn Lib3bandCompressor -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("compressors.lib/FFcompressor_N_chan:author", "Bart Brouns");
		m->declare("compressors.lib/FFcompressor_N_chan:license", "GPL-3.0-only");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/peak_compression_gain_N_chan_db:author", "Bart Brouns");
		m->declare("compressors.lib/peak_compression_gain_N_chan_db:license", "GPL-3.0-only");
		m->declare("compressors.lib/peak_compression_gain_mono_db:author", "Bart Brouns");
		m->declare("compressors.lib/peak_compression_gain_mono_db:license", "GPL-3.0-only");
		m->declare("compressors.lib/version", "1.6.0");
		m->declare("description", "fi.filterbank 3-way split into three Bart Brouns feed-forward compressors with per-band strength - multiband drum control");
		m->declare("family", "dynamics");
		m->declare("filename", "lib-3band-compressor.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass_plus_lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass_plus_lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:license", "LicenseRef-STK-4.3");
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
		m->declare("license", "GPL-3.0-only");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "3-Band Compressor");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "LicenseRef-STK-4.3");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/compressors.lib co.FFcompressor_N_chan + fi.filterbank");
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
		fConst4 = 1.0f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(-3e+01f);
		fHslider1 = static_cast<FAUSTFLOAT>(2e+02f);
		fHslider2 = static_cast<FAUSTFLOAT>(2.5e+03f);
		fHslider3 = static_cast<FAUSTFLOAT>(1.5e+02f);
		fHslider4 = static_cast<FAUSTFLOAT>(8.0f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider6 = static_cast<FAUSTFLOAT>(0.6f);
		fHslider7 = static_cast<FAUSTFLOAT>(0.4f);
		fHslider8 = static_cast<FAUSTFLOAT>(6.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec5[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec1[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec8[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec7[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec10[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec14[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = faust_wrap_add(l14, 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 3; l15 = faust_wrap_add(l15, 1)) {
			fRec12[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec11[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec16[l18] = 0.0f;
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
	
	virtual Lib3bandCompressor* clone() {
		return new Lib3bandCompressor(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("3-Band Compressor");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->declare(&fHslider1, "scale", "log");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Low Xover", &fHslider1, FAUSTFLOAT(2e+02f), FAUSTFLOAT(6e+01f), FAUSTFLOAT(8e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->declare(&fHslider2, "scale", "log");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("High Xover", &fHslider2, FAUSTFLOAT(2.5e+03f), FAUSTFLOAT(8e+02f), FAUSTFLOAT(8e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider6, "2", "");
		ui_interface->addHorizontalSlider("Low Strength", &fHslider6, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider5, "3", "");
		ui_interface->addHorizontalSlider("Mid Strength", &fHslider5, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider7, "4", "");
		ui_interface->addHorizontalSlider("High Strength", &fHslider7, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "5", "");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("Threshold", &fHslider0, FAUSTFLOAT(-3e+01f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider4, "6", "");
		ui_interface->declare(&fHslider4, "unit", "ms");
		ui_interface->addHorizontalSlider("Attack", &fHslider4, FAUSTFLOAT(8.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider3, "7", "");
		ui_interface->declare(&fHslider3, "unit", "ms");
		ui_interface->addHorizontalSlider("Release", &fHslider3, FAUSTFLOAT(1.5e+02f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider8, "8", "");
		ui_interface->declare(&fHslider8, "unit", "dB");
		ui_interface->addHorizontalSlider("Makeup", &fHslider8, FAUSTFLOAT(6.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = std::tan(fConst3 * static_cast<float>(fHslider1));
		float fSlow2 = Lib3bandCompressor_faustpower2_f(fSlow1);
		float fSlow3 = 1.0f / fSlow2;
		float fSlow4 = 2.0f * (1.0f - fSlow3);
		float fSlow5 = 1.0f / fSlow1;
		float fSlow6 = (fSlow5 + -1.0f) / fSlow1 + 1.0f;
		float fSlow7 = (fSlow5 + 1.0f) / fSlow1 + 1.0f;
		float fSlow8 = 1.0f / fSlow7;
		float fSlow9 = std::tan(fConst3 * static_cast<float>(fHslider2));
		float fSlow10 = Lib3bandCompressor_faustpower2_f(fSlow9);
		float fSlow11 = 2.0f * (1.0f - 1.0f / fSlow10);
		float fSlow12 = 1.0f / fSlow9;
		float fSlow13 = (fSlow12 + -1.0f) / fSlow9 + 1.0f;
		float fSlow14 = (fSlow12 + 1.0f) / fSlow9 + 1.0f;
		float fSlow15 = 1.0f / fSlow14;
		float fSlow16 = 1.0f - fSlow12;
		float fSlow17 = 1.0f / (fSlow12 + 1.0f);
		float fSlow18 = 1.0f - fSlow5;
		float fSlow19 = fSlow5 + 1.0f;
		float fSlow20 = 1.0f / fSlow19;
		float fSlow21 = 1.0f / (fSlow2 * fSlow7);
		float fSlow22 = 0.001f * static_cast<float>(fHslider3);
		int iSlow23 = std::fabs(fSlow22) < 1.1920929e-07f;
		float fSlow24 = ((iSlow23) ? 0.0f : std::exp(-(fConst4 / ((iSlow23) ? 1.0f : fSlow22))));
		float fSlow25 = 0.001f * static_cast<float>(fHslider4);
		int iSlow26 = std::fabs(fSlow25) < 1.1920929e-07f;
		float fSlow27 = ((iSlow26) ? 0.0f : std::exp(-(fConst4 / ((iSlow26) ? 1.0f : fSlow25))));
		float fSlow28 = fConst1 * static_cast<float>(fHslider5);
		float fSlow29 = fConst1 * static_cast<float>(fHslider6);
		float fSlow30 = 1.0f - fSlow18 / fSlow1;
		float fSlow31 = 1.0f / (fSlow19 / fSlow1 + 1.0f);
		float fSlow32 = 1.0f / (fSlow10 * fSlow14);
		float fSlow33 = fConst1 * static_cast<float>(fHslider7);
		float fSlow34 = fConst1 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider8));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = fRec0[0] + 3.0f;
			float fTemp1 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp1;
			fRec5[0] = -(fSlow17 * (fSlow16 * fRec5[1] - (fTemp1 + fVec0[1])));
			fRec4[0] = fRec5[0] - fSlow15 * (fSlow13 * fRec4[2] + fSlow11 * fRec4[1]);
			float fTemp2 = fSlow15 * (fRec4[2] + fRec4[0] + 2.0f * fRec4[1]);
			fVec1[0] = fTemp2;
			fRec3[0] = -(fSlow20 * (fSlow18 * fRec3[1] - fSlow5 * (fTemp2 - fVec1[1])));
			fRec2[0] = fRec3[0] - fSlow8 * (fSlow6 * fRec2[2] + fSlow4 * fRec2[1]);
			float fTemp3 = fRec2[2] + (fRec2[0] - 2.0f * fRec2[1]);
			float fTemp4 = std::fabs(fSlow21 * fTemp3);
			float fTemp5 = ((fTemp4 > fRec1[1]) ? fSlow27 : fSlow24);
			fRec1[0] = fTemp4 * (1.0f - fTemp5) + fRec1[1] * fTemp5;
			float fTemp6 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec1[0]));
			float fTemp7 = fRec0[0] + -3.0f;
			int iTemp8 = (fTemp6 > fTemp7) + (fTemp6 > fTemp0);
			float fTemp9 = 3.0f - fRec0[0];
			fRec6[0] = fSlow28 + fConst2 * fRec6[1];
			fRec9[0] = -(fSlow20 * (fSlow18 * fRec9[1] - (fTemp2 + fVec1[1])));
			fRec8[0] = fRec9[0] - fSlow8 * (fSlow6 * fRec8[2] + fSlow4 * fRec8[1]);
			float fTemp10 = fRec8[2] + fRec8[0] + 2.0f * fRec8[1];
			float fTemp11 = std::fabs(fSlow8 * fTemp10);
			float fTemp12 = ((fTemp11 > fRec7[1]) ? fSlow27 : fSlow24);
			fRec7[0] = fTemp11 * (1.0f - fTemp12) + fRec7[1] * fTemp12;
			float fTemp13 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec7[0]));
			int iTemp14 = (fTemp13 > fTemp7) + (fTemp13 > fTemp0);
			fRec10[0] = fSlow29 + fConst2 * fRec10[1];
			float fTemp15 = fSlow4 * fRec12[1];
			fRec14[0] = -(fSlow17 * (fSlow16 * fRec14[1] - fSlow12 * (fTemp1 - fVec0[1])));
			fRec13[0] = fRec14[0] - fSlow15 * (fSlow13 * fRec13[2] + fSlow11 * fRec13[1]);
			fRec12[0] = fSlow32 * (fRec13[2] + (fRec13[0] - 2.0f * fRec13[1])) - fSlow31 * (fSlow30 * fRec12[2] + fTemp15);
			float fTemp16 = fRec12[2] + fSlow31 * (fTemp15 + fSlow30 * fRec12[0]);
			float fTemp17 = std::fabs(fTemp16);
			float fTemp18 = ((fTemp17 > fRec11[1]) ? fSlow27 : fSlow24);
			fRec11[0] = fTemp17 * (1.0f - fTemp18) + fRec11[1] * fTemp18;
			float fTemp19 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec11[0]));
			int iTemp20 = (fTemp19 > fTemp7) + (fTemp19 > fTemp0);
			fRec15[0] = fSlow33 + fConst2 * fRec15[1];
			fRec16[0] = fSlow34 + fConst2 * fRec16[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fRec16[0] * (fTemp16 * std::pow(1e+01f, -(0.05f * fRec15[0] * std::max<float>(0.0f, ((iTemp20 == 0) ? 0.0f : ((iTemp20 == 1) ? 0.083333336f * Lib3bandCompressor_faustpower2_f(fTemp19 + fTemp9) : fTemp19 - fRec0[0]))))) + fSlow8 * (fTemp10 * std::pow(1e+01f, -(0.05f * fRec10[0] * std::max<float>(0.0f, ((iTemp14 == 0) ? 0.0f : ((iTemp14 == 1) ? 0.083333336f * Lib3bandCompressor_faustpower2_f(fTemp13 + fTemp9) : fTemp13 - fRec0[0]))))) + fSlow3 * fTemp3 * std::pow(1e+01f, -(0.05f * fRec6[0] * std::max<float>(0.0f, ((iTemp8 == 0) ? 0.0f : ((iTemp8 == 1) ? 0.083333336f * Lib3bandCompressor_faustpower2_f(fTemp6 + fTemp9) : fTemp6 - fRec0[0]))))))));
			fRec0[1] = fRec0[0];
			fVec0[1] = fVec0[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fVec1[1] = fVec1[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec6[1] = fRec6[0];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fRec10[1] = fRec10[0];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
		}
	}

};

#endif
