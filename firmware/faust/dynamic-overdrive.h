/* ------------------------------------------------------------
author: "Chameleon DSP"
name: "DynamicOverdrive"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn DynamicOverdrive -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __DynamicOverdrive_H__
#define  __DynamicOverdrive_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
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
#define FAUSTCLASS DynamicOverdrive
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

static float DynamicOverdrive_faustpower2_f(float value) {
	return value * value;
}

class DynamicOverdrive : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec1[2];
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
	float fVec0[2];
	float fConst12;
	float fConst13;
	float fConst14;
	float fRec7[2];
	float fRec6[3];
	float fConst15;
	float fConst16;
	float fConst17;
	float fConst18;
	float fVec1[2];
	float fRec5[2];
	float fRec4[3];
	float fVec2[2];
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec2[2];
	
 public:
	DynamicOverdrive() {
	}
	
	DynamicOverdrive(const DynamicOverdrive&) = default;
	
	virtual ~DynamicOverdrive() = default;
	
	DynamicOverdrive& operator=(const DynamicOverdrive&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Chameleon DSP");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn DynamicOverdrive -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Asymmetric tube-style overdrive with pre-emphasis and post tone");
		m->declare("filename", "dynamic-overdrive.dsp");
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
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "DynamicOverdrive");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
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
		fConst4 = std::tan(2356.1946f / fConst0);
		fConst5 = 2.0f * (1.0f - 1.0f / DynamicOverdrive_faustpower2_f(fConst4));
		fConst6 = fConst0 * std::sin(4712.389f / fConst0);
		fConst7 = 2827.4333f / fConst6;
		fConst8 = 1.0f / fConst4;
		fConst9 = (fConst8 - fConst7) / fConst4 + 1.0f;
		fConst10 = (fConst8 + fConst7) / fConst4 + 1.0f;
		fConst11 = 1.0f / fConst10;
		fConst12 = 1.0f / std::tan(282.74335f / fConst0);
		fConst13 = 1.0f - fConst12;
		fConst14 = 1.0f / (fConst12 + 1.0f);
		fConst15 = 5027.967f / fConst6;
		fConst16 = (fConst8 - fConst15) / fConst4 + 1.0f;
		fConst17 = (fConst8 + fConst15) / fConst4 + 1.0f;
		fConst18 = 1.5f / fConst10;
		fConst19 = 1.0f / std::tan(188.49556f / fConst0);
		fConst20 = 1.0f - fConst19;
		fConst21 = 1.0f / (fConst19 + 1.0f);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(18.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.6f);
		fHslider2 = static_cast<FAUSTFLOAT>(2.8e+03f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec0[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec7[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec1[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec5[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec4[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fVec2[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec2[l10] = 0.0f;
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
	
	virtual DynamicOverdrive* clone() {
		return new DynamicOverdrive(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("DynamicOverdrive");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("Gain", &fHslider0, FAUSTFLOAT(18.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.5f));
		ui_interface->addHorizontalSlider("Level", &fHslider1, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("Tone", &fHslider2, FAUSTFLOAT(2.8e+03f), FAUSTFLOAT(5e+02f), FAUSTFLOAT(6e+03f), FAUSTFLOAT(5e+01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst1 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = std::pow(1e+01f, 0.05f * fRec0[0]);
			fRec1[0] = fSlow1 + fConst2 * fRec1[1];
			fRec3[0] = fSlow2 + fConst2 * fRec3[1];
			float fTemp1 = std::tan(fConst3 * fRec3[0]);
			float fTemp2 = 1.0f / fTemp1;
			float fTemp3 = (fTemp2 + 1.4142135f) / fTemp1 + 1.0f;
			float fTemp4 = fConst5 * fRec6[1];
			float fTemp5 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp5;
			fRec7[0] = -(fConst14 * (fConst13 * fRec7[1] - fConst12 * (fTemp5 - fVec0[1])));
			fRec6[0] = fRec7[0] - fConst11 * (fConst9 * fRec6[2] + fTemp4);
			float fTemp6 = (fTemp4 + fConst17 * fRec6[0] + fConst16 * fRec6[2]) * fTemp0;
			float fTemp7 = fConst11 * fTemp6;
			float fTemp8 = ((fTemp7 > 0.0f) ? tanhf(fTemp7) : 0.6666667f * tanhf(fConst18 * fTemp6));
			fVec1[0] = fTemp8;
			fRec5[0] = 0.995f * fRec5[1] + fTemp8 - fVec1[1];
			fRec4[0] = fRec5[0] - (fRec4[2] * ((fTemp2 + -1.4142135f) / fTemp1 + 1.0f) + 2.0f * fRec4[1] * (1.0f - 1.0f / DynamicOverdrive_faustpower2_f(fTemp1))) / fTemp3;
			float fTemp9 = (fRec4[2] + fRec4[0] + 2.0f * fRec4[1]) / fTemp3;
			fVec2[0] = fTemp9;
			fRec2[0] = -(fConst21 * (fConst20 * fRec2[1] - fConst19 * (fTemp9 - fVec2[1])));
			output0[i0] = static_cast<FAUSTFLOAT>(fRec2[0] * fRec1[0] * std::min<float>(1.3f, 2.0f / std::sqrt(fTemp0)));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fVec0[1] = fVec0[0];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fVec1[1] = fVec1[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fVec2[1] = fVec2[0];
			fRec2[1] = fRec2[0];
		}
	}

};

#endif
