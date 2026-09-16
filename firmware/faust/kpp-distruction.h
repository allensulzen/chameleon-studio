/* ------------------------------------------------------------
author: "Oleg Kapitonov"
license: "GPL-3.0-or-later"
name: "KPP Distruction"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn KppDistruction -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __KppDistruction_H__
#define  __KppDistruction_H__

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
#define FAUSTCLASS KppDistruction
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

static float KppDistruction_faustpower2_f(float value) {
	return value * value;
}

class KppDistruction : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec2[2];
	FAUSTFLOAT fHslider2;
	float fRec3[2];
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fConst13;
	FAUSTFLOAT fHslider3;
	float fRec9[2];
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	FAUSTFLOAT fHslider4;
	float fRec11[2];
	float fConst18;
	float fConst19;
	float fConst20;
	float fConst21;
	FAUSTFLOAT fHslider5;
	float fRec13[2];
	float fConst22;
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	FAUSTFLOAT fHslider6;
	float fRec17[2];
	float fVec0[2];
	float fRec18[2];
	float fVec1[2];
	float fConst28;
	float fRec16[2];
	float fConst29;
	float fConst30;
	float fRec15[2];
	float fRec14[3];
	float fRec12[3];
	float fRec10[3];
	float fVec2[2];
	float fRec8[2];
	float fConst31;
	float fConst32;
	float fConst33;
	float fRec7[2];
	float fRec6[3];
	float fConst34;
	float fConst35;
	float fConst36;
	float fVec3[2];
	float fConst37;
	float fConst38;
	float fConst39;
	float fRec5[2];
	float fRec4[3];
	float fRec20[2];
	float fRec19[3];
	float fVec4[2];
	float fRec1[2];
	
 public:
	KppDistruction() {
	}
	
	KppDistruction(const KppDistruction&) = default;
	
	virtual ~KppDistruction() = default;
	
	KppDistruction& operator=(const KppDistruction&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Oleg Kapitonov");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn KppDistruction -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Hi-gain distortion: bandpassed pre-filter, push-pull tube clipper, 3-band EQ, voice-controlled presence");
		m->declare("family", "dirt");
		m->declare("filename", "kpp-distruction.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/highshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/peak_eq:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "LicenseRef-STK-4.3");
		m->declare("license", "GPL-3.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "KPP Distruction");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_distruction/kpp_distruction.dsp");
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
		fConst3 = std::tan(1727.876f / fConst0);
		fConst4 = 1.0f / KppDistruction_faustpower2_f(fConst3);
		fConst5 = 2.0f * (1.0f - fConst4);
		fConst6 = 1.0f / fConst3;
		fConst7 = (fConst6 + -1.0f) / fConst3 + 1.0f;
		fConst8 = 1.0f / ((fConst6 + 1.0f) / fConst3 + 1.0f);
		fConst9 = fConst0 * std::sin(3455.752f / fConst0);
		fConst10 = 3134.1506f / fConst9;
		fConst11 = (fConst6 - fConst10) / fConst3 + 1.0f;
		fConst12 = (fConst6 + fConst10) / fConst3 + 1.0f;
		fConst13 = 1.0f / fConst12;
		fConst14 = 6283.1855f / (fConst0 * std::sin(20734.512f / fConst0));
		fConst15 = std::tan(10367.256f / fConst0);
		fConst16 = 1.0f / fConst15;
		fConst17 = 2.0f * (1.0f - 1.0f / KppDistruction_faustpower2_f(fConst15));
		fConst18 = 2199.1147f / (fConst0 * std::sin(4398.2295f / fConst0));
		fConst19 = std::tan(2199.1147f / fConst0);
		fConst20 = 1.0f / fConst19;
		fConst21 = 2.0f * (1.0f - 1.0f / KppDistruction_faustpower2_f(fConst19));
		fConst22 = 628.31854f / (fConst0 * std::sin(628.31854f / fConst0));
		fConst23 = std::tan(314.15927f / fConst0);
		fConst24 = 1.0f / fConst23;
		fConst25 = 2.0f * (1.0f - 1.0f / KppDistruction_faustpower2_f(fConst23));
		fConst26 = 1.0f / std::tan(9424.778f / fConst0);
		fConst27 = 1.0f - fConst26;
		fConst28 = 1.0f / (fConst26 + 1.0f);
		fConst29 = 1.0f - fConst16;
		fConst30 = 1.0f / (fConst16 + 1.0f);
		fConst31 = 1.0f / std::tan(94.24778f / fConst0);
		fConst32 = 1.0f - fConst31;
		fConst33 = 1.0f / (fConst31 + 1.0f);
		fConst34 = 1570.7964f / fConst9;
		fConst35 = (fConst6 - fConst34) / fConst3 + 1.0f;
		fConst36 = (fConst6 + fConst34) / fConst3 + 1.0f;
		fConst37 = 1.0f / (fConst3 * fConst12);
		fConst38 = 1.0f - fConst6;
		fConst39 = 1.0f / (fConst6 + 1.0f);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(12.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.8f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider6 = static_cast<FAUSTFLOAT>(63.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec9[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec11[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec13[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec17[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fVec0[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec18[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fVec1[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec16[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec15[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 3; l12 = faust_wrap_add(l12, 1)) {
			fRec14[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = faust_wrap_add(l13, 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = faust_wrap_add(l14, 1)) {
			fRec10[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fVec2[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec8[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec7[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 3; l18 = faust_wrap_add(l18, 1)) {
			fRec6[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fVec3[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec5[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 3; l21 = faust_wrap_add(l21, 1)) {
			fRec4[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec20[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 3; l23 = faust_wrap_add(l23, 1)) {
			fRec19[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fVec4[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec1[l25] = 0.0f;
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
	
	virtual KppDistruction* clone() {
		return new KppDistruction(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("KPP Distruction");
		ui_interface->declare(&fHslider6, "0", "");
		ui_interface->addHorizontalSlider("Drive", &fHslider6, FAUSTFLOAT(63.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->addHorizontalSlider("Voice", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider5, "2", "");
		ui_interface->declare(&fHslider5, "unit", "dB");
		ui_interface->addHorizontalSlider("Bass", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider4, "3", "");
		ui_interface->declare(&fHslider4, "unit", "dB");
		ui_interface->addHorizontalSlider("Middle", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider3, "4", "");
		ui_interface->declare(&fHslider3, "unit", "dB");
		ui_interface->addHorizontalSlider("Treble", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "5", "");
		ui_interface->addHorizontalSlider("Volume", &fHslider1, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider0, "6", "");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("Level", &fHslider0, FAUSTFLOAT(12.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider0));
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		float fSlow4 = fConst1 * static_cast<float>(fHslider4);
		float fSlow5 = fConst1 * static_cast<float>(fHslider5);
		float fSlow6 = fConst1 * static_cast<float>(fHslider6);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			fRec2[0] = fSlow1 + fConst2 * fRec2[1];
			fRec3[0] = fSlow2 + fConst2 * fRec3[1];
			float fTemp0 = fConst5 * fRec6[1];
			fRec9[0] = fSlow3 + fConst2 * fRec9[1];
			int iTemp1 = fRec9[0] > 0.0f;
			float fTemp2 = fConst14 * std::pow(1e+01f, 0.05f * std::fabs(fRec9[0]));
			float fTemp3 = ((iTemp1) ? fConst14 : fTemp2);
			float fTemp4 = fConst16 * (fConst16 + fTemp3) + 1.0f;
			float fTemp5 = ((iTemp1) ? fTemp2 : fConst14);
			float fTemp6 = fConst17 * fRec10[1];
			fRec11[0] = fSlow4 + fConst2 * fRec11[1];
			int iTemp7 = fRec11[0] > 0.0f;
			float fTemp8 = fConst18 * std::pow(1e+01f, 0.05f * std::fabs(fRec11[0]));
			float fTemp9 = ((iTemp7) ? fConst18 : fTemp8);
			float fTemp10 = fConst20 * (fConst20 + fTemp9) + 1.0f;
			float fTemp11 = ((iTemp7) ? fTemp8 : fConst18);
			float fTemp12 = fConst21 * fRec12[1];
			fRec13[0] = fSlow5 + fConst2 * fRec13[1];
			int iTemp13 = fRec13[0] > 0.0f;
			float fTemp14 = fConst22 * std::pow(1e+01f, 0.05f * std::fabs(fRec13[0]));
			float fTemp15 = ((iTemp13) ? fConst22 : fTemp14);
			float fTemp16 = fConst24 * (fConst24 + fTemp15) + 1.0f;
			float fTemp17 = ((iTemp13) ? fTemp14 : fConst22);
			float fTemp18 = fConst25 * fRec14[1];
			fRec17[0] = fSlow6 + fConst2 * fRec17[1];
			float fTemp19 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp19;
			fRec18[0] = fTemp19 + 0.995f * fRec18[1] - fVec0[1];
			float fTemp20 = std::max<float>(-2.0f, std::min<float>(2.0f, fRec18[0])) * (std::pow(1e+01f, 0.035f * fRec17[0]) + -1.0f);
			fVec1[0] = fTemp20;
			fRec16[0] = fConst28 * (5.0f * (fTemp20 + fVec1[1]) - fConst27 * fRec16[1]);
			fRec15[0] = -(fConst30 * (fConst29 * fRec15[1] - fConst16 * (fRec16[0] - fRec16[1])));
			float fTemp21 = std::max<float>(-0.2f - fRec15[0], 0.0f) + 1.0f;
			float fTemp22 = std::max<float>(fRec15[0] + -0.2f, 0.0f) + 1.0f;
			fRec14[0] = std::max<float>(0.0f, fRec15[0] / fTemp22 + 0.2f * (1.0f - 1.0f / fTemp22 + 1.0f)) - (std::max<float>(0.0f, 0.2f * (1.0f - 1.0f / fTemp21 + 1.0f) - fRec15[0] / fTemp21) + (fRec14[2] * (fConst24 * (fConst24 - fTemp15) + 1.0f) + fTemp18) / fTemp16);
			fRec12[0] = (fTemp18 + fRec14[0] * (fConst24 * (fConst24 + fTemp17) + 1.0f) + fRec14[2] * (fConst24 * (fConst24 - fTemp17) + 1.0f)) / fTemp16 - (fRec12[2] * (fConst20 * (fConst20 - fTemp9) + 1.0f) + fTemp12) / fTemp10;
			fRec10[0] = (fTemp12 + fRec12[0] * (fConst20 * (fConst20 + fTemp11) + 1.0f) + fRec12[2] * (fConst20 * (fConst20 - fTemp11) + 1.0f)) / fTemp10 - (fRec10[2] * (fConst16 * (fConst16 - fTemp3) + 1.0f) + fTemp6) / fTemp4;
			float fTemp23 = (fTemp6 + fRec10[0] * (fConst16 * (fConst16 + fTemp5) + 1.0f) + fRec10[2] * (fConst16 * (fConst16 - fTemp5) + 1.0f)) / fTemp4;
			fVec2[0] = fTemp23;
			fRec8[0] = -(fConst28 * (fConst27 * fRec8[1] - (fTemp23 + fVec2[1])));
			fRec7[0] = -(fConst33 * (fConst32 * fRec7[1] - fConst31 * (fRec8[0] - fRec8[1])));
			fRec6[0] = fRec7[0] - fConst13 * (fConst11 * fRec6[2] + fTemp0);
			float fTemp24 = fTemp0 + fConst36 * fRec6[0] + fConst35 * fRec6[2];
			fVec3[0] = fTemp24;
			fRec5[0] = -(fConst39 * (fConst38 * fRec5[1] - fConst37 * (fTemp24 - fVec3[1])));
			fRec4[0] = fRec5[0] - fConst8 * (fConst7 * fRec4[2] + fConst5 * fRec4[1]);
			fRec20[0] = -(fConst39 * (fConst38 * fRec20[1] - fConst13 * (fTemp24 + fVec3[1])));
			fRec19[0] = fRec20[0] - fConst8 * (fConst7 * fRec19[2] + fConst5 * fRec19[1]);
			float fTemp25 = std::max<float>(-2.0f, std::min<float>(2.0f, fConst8 * (fRec19[2] + fRec19[0] + 2.0f * fRec19[1] + fConst4 * (fRec4[2] + (fRec4[0] - 2.0f * fRec4[1])) * std::pow(1e+01f, -(1.0f - fRec3[0]))))) * (std::pow(1e+01f, 1.25f * fRec2[0]) + -1.0f);
			fVec4[0] = fTemp25;
			fRec1[0] = 0.995f * fRec1[1] + 0.01f * (fTemp25 - fVec4[1]);
			output0[i0] = static_cast<FAUSTFLOAT>(fRec1[0] * fRec0[0]);
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			fRec13[1] = fRec13[0];
			fRec17[1] = fRec17[0];
			fVec0[1] = fVec0[0];
			fRec18[1] = fRec18[0];
			fVec1[1] = fVec1[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fVec2[1] = fVec2[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fVec3[1] = fVec3[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fVec4[1] = fVec4[0];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
