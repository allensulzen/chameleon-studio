/* ------------------------------------------------------------
author: "Oleg Kapitonov"
license: "GPL-3.0-or-later"
name: "KPP Tube Amp"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn KppTubeamp -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __KppTubeamp_H__
#define  __KppTubeamp_H__

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
#define FAUSTCLASS KppTubeamp
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

static float KppTubeamp_faustpower2_f(float value) {
	return value * value;
}

class KppTubeamp : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
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
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	float fConst18;
	float fConst19;
	float fConst20;
	float fConst21;
	FAUSTFLOAT fHslider0;
	float fRec4[2];
	FAUSTFLOAT fEntry0;
	FAUSTFLOAT fHslider1;
	float fRec6[2];
	float fConst22;
	float fVec0[2];
	float fRec8[2];
	FAUSTFLOAT fHslider2;
	float fRec11[2];
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	FAUSTFLOAT fHslider3;
	float fRec13[2];
	float fConst27;
	float fConst28;
	float fConst29;
	float fConst30;
	FAUSTFLOAT fHslider4;
	float fRec15[2];
	float fConst31;
	float fConst32;
	float fConst33;
	float fConst34;
	FAUSTFLOAT fHslider5;
	float fRec17[2];
	FAUSTFLOAT fHslider6;
	float fRec20[2];
	float fVec1[2];
	float fRec21[2];
	float fVec2[2];
	float fConst35;
	float fConst36;
	float fConst37;
	float fRec19[2];
	float fVec3[2];
	float fRec18[2];
	float fRec16[3];
	float fRec14[3];
	float fRec12[3];
	float fVec4[2];
	float fRec10[2];
	float fVec5[2];
	float fRec9[2];
	float fRec7[2];
	float fVec6[2];
	float fRec5[2];
	float fRec3[3];
	float fConst38;
	float fRec2[3];
	float fConst39;
	float fConst40;
	float fConst41;
	float fVec7[2];
	float fConst42;
	float fConst43;
	float fRec1[2];
	float fRec0[3];
	
 public:
	KppTubeamp() {
	}
	
	KppTubeamp(const KppTubeamp&) = default;
	
	virtual ~KppTubeamp() = default;
	
	KppTubeamp& operator=(const KppTubeamp&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Oleg Kapitonov");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn KppTubeamp -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Profile-driven tube amp: preamp waveshaper, 3-band tonestack, push-pull power stage with supply sag. 8 built-in profiles (American Clean/Vintage, British Crunch, Modern Metal, Classic Hard, JCM800, MarkII, Twin) baked in from the .tapf files");
		m->declare("family", "amp");
		m->declare("filename", "kpp-tubeamp.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "LicenseRef-STK-4.3");
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
		m->declare("name", "KPP Tube Amp");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "olegkapitonov/Kapitonov-Plugins-Pack LV2/kpp_tubeamp/kpp_tubeamp.dsp (+ profiles/*.tapf header values)");
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
		fConst1 = std::tan(16336.282f / fConst0);
		fConst2 = 2.0f * (1.0f - 1.0f / KppTubeamp_faustpower2_f(fConst1));
		fConst3 = 1.0f / fConst1;
		fConst4 = (fConst3 + -1.0f) / fConst1 + 1.0f;
		fConst5 = 1.0f / ((fConst3 + 1.0f) / fConst1 + 1.0f);
		fConst6 = std::tan(7853.9814f / fConst0);
		fConst7 = 2.0f * (1.0f - 1.0f / KppTubeamp_faustpower2_f(fConst6));
		fConst8 = fConst0 * std::sin(15707.963f / fConst0);
		fConst9 = 4712.389f / fConst8;
		fConst10 = 1.0f / fConst6;
		fConst11 = (fConst10 - fConst9) / fConst6 + 1.0f;
		fConst12 = 1.0f / ((fConst10 + fConst9) / fConst6 + 1.0f);
		fConst13 = std::tan(282.74335f / fConst0);
		fConst14 = KppTubeamp_faustpower2_f(fConst13);
		fConst15 = 2.0f * (1.0f - 1.0f / fConst14);
		fConst16 = 1.0f / fConst13;
		fConst17 = (fConst16 + -1.4142135f) / fConst13 + 1.0f;
		fConst18 = (fConst16 + 1.4142135f) / fConst13 + 1.0f;
		fConst19 = 1.0f / fConst18;
		fConst20 = 44.1f / fConst0;
		fConst21 = 1.0f - fConst20;
		fConst22 = 3.1415927f / fConst0;
		fConst23 = 56548.668f / (fConst0 * std::sin(62831.85f / fConst0));
		fConst24 = std::tan(31415.926f / fConst0);
		fConst25 = 1.0f / fConst24;
		fConst26 = 2.0f * (1.0f - 1.0f / KppTubeamp_faustpower2_f(fConst24));
		fConst27 = 1256.6371f / (fConst0 * std::sin(3141.5928f / fConst0));
		fConst28 = std::tan(1570.7964f / fConst0);
		fConst29 = 1.0f / fConst28;
		fConst30 = 2.0f * (1.0f - 1.0f / KppTubeamp_faustpower2_f(fConst28));
		fConst31 = 1256.6371f / (fConst0 * std::sin(125.663704f / fConst0));
		fConst32 = std::tan(62.831852f / fConst0);
		fConst33 = 1.0f / fConst32;
		fConst34 = 2.0f * (1.0f - 1.0f / KppTubeamp_faustpower2_f(fConst32));
		fConst35 = 1.0f / std::tan(34557.52f / fConst0);
		fConst36 = 1.0f - fConst35;
		fConst37 = 1.0f / (fConst35 + 1.0f);
		fConst38 = 1.0f / (fConst14 * fConst18);
		fConst39 = 7468.6333f / fConst8;
		fConst40 = (fConst10 - fConst39) / fConst6 + 1.0f;
		fConst41 = (fConst10 + fConst39) / fConst6 + 1.0f;
		fConst42 = 1.0f - fConst3;
		fConst43 = 1.0f / (fConst3 + 1.0f);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(1.0f);
		fEntry0 = static_cast<FAUSTFLOAT>(2.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider5 = static_cast<FAUSTFLOAT>(5e+01f);
		fHslider6 = static_cast<FAUSTFLOAT>(1e+02f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec4[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec6[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec8[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec11[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec13[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec15[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec17[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec20[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fVec1[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec21[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fVec2[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec19[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fVec3[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec18[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 3; l15 = faust_wrap_add(l15, 1)) {
			fRec16[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 3; l16 = faust_wrap_add(l16, 1)) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 3; l17 = faust_wrap_add(l17, 1)) {
			fRec12[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fVec4[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec10[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fVec5[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec9[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec7[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fVec6[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec5[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 3; l25 = faust_wrap_add(l25, 1)) {
			fRec3[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 3; l26 = faust_wrap_add(l26, 1)) {
			fRec2[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fVec7[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec1[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 3; l29 = faust_wrap_add(l29, 1)) {
			fRec0[l29] = 0.0f;
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
	
	virtual KppTubeamp* clone() {
		return new KppTubeamp(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("KPP Tube Amp");
		ui_interface->declare(&fEntry0, "0", "");
		ui_interface->declare(&fEntry0, "style", "menu{'American Clean':0;'American Vintage':1;'British Crunch':2;'Modern Metal':3;'Classic Hard':4;'JCM800':5;'MarkII':6;'Twin Reverb':7}");
		ui_interface->addNumEntry("Profile", &fEntry0, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(7.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider6, "1", "");
		ui_interface->addHorizontalSlider("Drive", &fHslider6, FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider4, "2", "");
		ui_interface->declare(&fHslider4, "unit", "dB");
		ui_interface->addHorizontalSlider("Bass", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->declare(&fHslider3, "unit", "dB");
		ui_interface->addHorizontalSlider("Middle", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider2, "4", "");
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("Treble", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider5, "5", "");
		ui_interface->addHorizontalSlider("Master", &fHslider5, FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "6", "");
		ui_interface->addHorizontalSlider("Volume", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider0, "7", "");
		ui_interface->addHorizontalSlider("Cab Sim", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst20 * static_cast<float>(fHslider0);
		float fSlow1 = static_cast<float>(fEntry0);
		int iSlow2 = fSlow1 >= 4.0f;
		int iSlow3 = fSlow1 >= 2.0f;
		int iSlow4 = fSlow1 >= 1.0f;
		int iSlow5 = fSlow1 >= 3.0f;
		int iSlow6 = fSlow1 >= 6.0f;
		int iSlow7 = fSlow1 >= 5.0f;
		int iSlow8 = fSlow1 >= 7.0f;
		float fSlow9 = ((iSlow2) ? ((iSlow6) ? ((iSlow8) ? 0.18f : 0.33f) : ((iSlow7) ? 0.13f : 0.06f)) : ((iSlow3) ? ((iSlow5) ? 0.2f : 0.1333f) : ((iSlow4) ? 0.5f : 0.3125f)));
		float fSlow10 = fConst20 * static_cast<float>(fHslider1);
		float fSlow11 = ((iSlow2) ? ((iSlow6) ? ((iSlow8) ? 0.68f : 0.0f) : 0.5f) : ((iSlow3) ? ((iSlow5) ? 0.0f : 0.5f) : ((iSlow4) ? 5.0f : 0.0f)));
		float fSlow12 = 1.0f / std::tan(fConst22 * ((iSlow2) ? ((iSlow6) ? ((iSlow8) ? 0.3f : 0.1f) : 0.3f) : ((iSlow3) ? ((iSlow5) ? 0.1f : 0.3f) : 0.3f)));
		float fSlow13 = fSlow12 + 1.0f;
		float fSlow14 = 1.0f - fSlow12;
		float fSlow15 = ((iSlow2) ? ((iSlow6) ? ((iSlow8) ? 0.2f : 0.5f) : 0.2f) : ((iSlow3) ? ((iSlow5) ? 0.5f : 0.2f) : 0.2f));
		float fSlow16 = fConst20 * static_cast<float>(fHslider2);
		float fSlow17 = fConst20 * static_cast<float>(fHslider3);
		float fSlow18 = fConst20 * static_cast<float>(fHslider4);
		float fSlow19 = fConst20 * static_cast<float>(fHslider5);
		float fSlow20 = ((iSlow2) ? ((iSlow6) ? ((iSlow8) ? 0.5909f : 0.1811f) : ((iSlow7) ? 0.7925f : 1e+01f)) : ((iSlow3) ? ((iSlow5) ? 0.06f : 1.5f) : ((iSlow4) ? 0.25f : 0.2f)));
		float fSlow21 = ((iSlow2) ? ((iSlow6) ? ((iSlow8) ? 0.8f : 0.39f) : 0.8f) : ((iSlow3) ? ((iSlow5) ? 0.2f : 0.8f) : 0.8f));
		float fSlow22 = ((iSlow2) ? ((iSlow6) ? ((iSlow8) ? 0.8f : 6.57f) : 0.8f) : ((iSlow3) ? ((iSlow5) ? 2.0f : 0.8f) : 0.8f));
		float fSlow23 = ((iSlow2) ? ((iSlow6) ? ((iSlow8) ? 0.005f : 0.1155f) : ((iSlow7) ? 0.0795f : 0.0071f)) : ((iSlow3) ? ((iSlow5) ? 2.0f : 0.005f) : 0.005f));
		float fSlow24 = fConst20 * static_cast<float>(fHslider6);
		float fSlow25 = ((iSlow2) ? ((iSlow6) ? ((iSlow8) ? 0.7f : 1.0f) : 0.7f) : ((iSlow3) ? ((iSlow5) ? 1.0f : 0.7f) : ((iSlow4) ? 0.7f : 0.5f)));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			float fTemp0 = fConst7 * fRec2[1];
			fRec4[0] = fSlow0 + fConst21 * fRec4[1];
			fRec6[0] = fSlow10 + fConst21 * fRec6[1];
			float fTemp1 = KppTubeamp_faustpower2_f(fRec7[1]);
			fVec0[0] = fTemp1;
			fRec8[0] = -((fRec8[1] * fSlow14 - (fTemp1 + fVec0[1])) / fSlow13);
			float fTemp2 = std::min<float>(2.5f, std::max<float>(1.0f, fRec8[0] * fSlow11));
			fRec11[0] = fSlow16 + fConst21 * fRec11[1];
			int iTemp3 = fRec11[0] > 0.0f;
			float fTemp4 = fConst23 * std::pow(1e+01f, 0.05f * std::fabs(fRec11[0]));
			float fTemp5 = ((iTemp3) ? fConst23 : fTemp4);
			float fTemp6 = fConst25 * (fConst25 + fTemp5) + 1.0f;
			float fTemp7 = ((iTemp3) ? fTemp4 : fConst23);
			float fTemp8 = fConst26 * fRec12[1];
			fRec13[0] = fSlow17 + fConst21 * fRec13[1];
			int iTemp9 = fRec13[0] > 0.0f;
			float fTemp10 = fConst27 * std::pow(1e+01f, 0.05f * std::fabs(fRec13[0]));
			float fTemp11 = ((iTemp9) ? fConst27 : fTemp10);
			float fTemp12 = fConst29 * (fConst29 + fTemp11) + 1.0f;
			float fTemp13 = ((iTemp9) ? fTemp10 : fConst27);
			float fTemp14 = fConst30 * fRec14[1];
			fRec15[0] = fSlow18 + fConst21 * fRec15[1];
			int iTemp15 = fRec15[0] > 0.0f;
			float fTemp16 = fConst31 * std::pow(1e+01f, 0.05f * std::fabs(fRec15[0]));
			float fTemp17 = ((iTemp15) ? fConst31 : fTemp16);
			float fTemp18 = fConst33 * (fConst33 + fTemp17) + 1.0f;
			float fTemp19 = ((iTemp15) ? fTemp16 : fConst31);
			float fTemp20 = fConst34 * fRec16[1];
			fRec17[0] = fSlow19 + fConst21 * fRec17[1];
			fRec20[0] = fSlow24 + fConst21 * fRec20[1];
			float fTemp21 = static_cast<float>(input0[i0]);
			fVec1[0] = fTemp21;
			fRec21[0] = fTemp21 + 0.995f * fRec21[1] - fVec1[1];
			float fTemp22 = fRec21[0] * (std::pow(1e+01f, 0.02f * fRec20[0]) + -1.0f) * fSlow23;
			fVec2[0] = fTemp22;
			fRec19[0] = -(fConst37 * (fConst36 * fRec19[1] - (fTemp22 + fVec2[1])));
			float fTemp23 = std::max<float>((fRec19[0] - fSlow21) * fSlow22, 0.0f) + 1.0f;
			float fTemp24 = std::max<float>(-fSlow21, fRec19[0] / fTemp23 + fSlow21 * (1.0f - 1.0f / fTemp23));
			fVec3[0] = fTemp24;
			fRec18[0] = 0.995f * fRec18[1] + fTemp24 - fVec3[1];
			fRec16[0] = fRec18[0] * fSlow20 * (std::pow(1e+01f, 0.02f * fRec17[0]) + -1.0f) - (fRec16[2] * (fConst33 * (fConst33 - fTemp17) + 1.0f) + fTemp20) / fTemp18;
			fRec14[0] = (fTemp20 + fRec16[0] * (fConst33 * (fConst33 + fTemp19) + 1.0f) + fRec16[2] * (fConst33 * (fConst33 - fTemp19) + 1.0f)) / fTemp18 - (fRec14[2] * (fConst29 * (fConst29 - fTemp11) + 1.0f) + fTemp14) / fTemp12;
			fRec12[0] = (fTemp14 + fRec14[0] * (fConst29 * (fConst29 + fTemp13) + 1.0f) + fRec14[2] * (fConst29 * (fConst29 - fTemp13) + 1.0f)) / fTemp12 - (fRec12[2] * (fConst25 * (fConst25 - fTemp5) + 1.0f) + fTemp8) / fTemp6;
			float fTemp25 = (fTemp8 + fRec12[0] * (fConst25 * (fConst25 + fTemp7) + 1.0f) + fRec12[2] * (fConst25 * (fConst25 - fTemp7) + 1.0f)) / fTemp6;
			fVec4[0] = fTemp25;
			fRec10[0] = -(fConst37 * (fConst36 * fRec10[1] - (fTemp25 + fVec4[1])));
			float fTemp26 = fRec10[0] * fTemp2;
			float fTemp27 = std::max<float>(-(fSlow25 * (fTemp26 + fSlow15)), 0.0f) + 1.0f;
			float fTemp28 = std::max<float>((fTemp26 - fSlow15) * fSlow25, 0.0f) + 1.0f;
			float fTemp29 = std::max<float>(0.0f, fTemp26 / fTemp28 + fSlow15 * (1.0f - 1.0f / fTemp28) + 0.2f) - std::max<float>(0.0f, fSlow15 * (1.0f - 1.0f / fTemp27) + (0.2f - fTemp26 / fTemp27));
			fVec5[0] = fTemp29;
			fRec9[0] = -(fConst37 * (fConst36 * fRec9[1] - (fTemp29 + fVec5[1])));
			fRec7[0] = fRec9[0] / fTemp2;
			float fTemp30 = fRec7[0] * fRec6[0] * fSlow9;
			fVec6[0] = fTemp30;
			fRec5[0] = fTemp30 + 0.995f * fRec5[1] - fVec6[1];
			fRec3[0] = fRec5[0] * fRec4[0] - fConst19 * (fConst17 * fRec3[2] + fConst15 * fRec3[1]);
			fRec2[0] = fConst38 * (fRec3[2] + (fRec3[0] - 2.0f * fRec3[1])) - fConst12 * (fConst11 * fRec2[2] + fTemp0);
			float fTemp31 = fTemp0 + fConst41 * fRec2[0] + fConst40 * fRec2[2];
			fVec7[0] = fTemp31;
			fRec1[0] = -(fConst43 * (fConst42 * fRec1[1] - fConst12 * (fTemp31 + fVec7[1])));
			fRec0[0] = fRec1[0] - fConst5 * (fConst4 * fRec0[2] + fConst2 * fRec0[1]);
			output0[i0] = static_cast<FAUSTFLOAT>(fRec5[0] * (1.0f - fRec4[0]) + fConst5 * (fRec0[2] + fRec0[0] + 2.0f * fRec0[1]));
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fVec0[1] = fVec0[0];
			fRec8[1] = fRec8[0];
			fRec11[1] = fRec11[0];
			fRec13[1] = fRec13[0];
			fRec15[1] = fRec15[0];
			fRec17[1] = fRec17[0];
			fRec20[1] = fRec20[0];
			fVec1[1] = fVec1[0];
			fRec21[1] = fRec21[0];
			fVec2[1] = fVec2[0];
			fRec19[1] = fRec19[0];
			fVec3[1] = fVec3[0];
			fRec18[1] = fRec18[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fVec4[1] = fVec4[0];
			fRec10[1] = fRec10[0];
			fVec5[1] = fVec5[0];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fVec6[1] = fVec6[0];
			fRec5[1] = fRec5[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fVec7[1] = fVec7[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
