/* ------------------------------------------------------------
author: "Dario Sanfilippo"
license: "LGPL-2.1-or-later"
name: "ADAA Drive"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibAdaaDrive -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibAdaaDrive_H__
#define  __LibAdaaDrive_H__

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
#define FAUSTCLASS LibAdaaDrive
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

static float LibAdaaDrive_faustpower2_f(float value) {
	return value * value;
}
static float LibAdaaDrive_faustpower3_f(float value) {
	return value * value * value;
}

class LibAdaaDrive : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec2[2];
	float fConst3;
	FAUSTFLOAT fEntry0;
	FAUSTFLOAT fHslider2;
	float fRec4[2];
	FAUSTFLOAT fHslider3;
	float fRec6[2];
	float fVec0[2];
	float fRec5[2];
	float fVec1[2];
	float fVec2[2];
	float fRec3[2];
	float fRec1[2];
	
 public:
	LibAdaaDrive() {
	}
	
	LibAdaaDrive(const LibAdaaDrive&) = default;
	
	virtual ~LibAdaaDrive() = default;
	
	LibAdaaDrive& operator=(const LibAdaaDrive&) = default;
	
	void metadata(Meta* m) { 
		m->declare("aanl.lib/ADAA1:author", "Dario Sanfilippo");
		m->declare("aanl.lib/ADAA1:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/ADAA1:license", "MIT");
		m->declare("aanl.lib/hardclip:author", "Dario Sanfilippo");
		m->declare("aanl.lib/hardclip:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/hardclip:license", "MIT");
		m->declare("aanl.lib/name", "Faust Antialiased Nonlinearities");
		m->declare("aanl.lib/softclipQuadratic1:author", "David Braun");
		m->declare("aanl.lib/softclipQuadratic1:copyright", "Copyright (C) 2024 David Braun");
		m->declare("aanl.lib/softclipQuadratic1:license", "MIT");
		m->declare("aanl.lib/tanh1:author", "Dario Sanfilippo");
		m->declare("aanl.lib/tanh1:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/tanh1:license", "MIT");
		m->declare("aanl.lib/version", "1.5.0");
		m->declare("author", "Dario Sanfilippo");
		m->declare("basics.lib/ifNc:author", "Oleg Nesterov");
		m->declare("basics.lib/ifNc:copyright", "Copyright (C) 2023 Oleg Nesterov <oleg@redhat.com>");
		m->declare("basics.lib/ifNc:license", "LicenseRef-STK-4.3");
		m->declare("basics.lib/ifNcNo:author", "Oleg Nesterov");
		m->declare("basics.lib/ifNcNo:copyright", "Copyright (C) 2023 Oleg Nesterov <oleg@redhat.com>");
		m->declare("basics.lib/ifNcNo:license", "LicenseRef-STK-4.3");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibAdaaDrive -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("description", "Alias-suppressed clipper (antiderivative anti-aliasing) with hard/tanh/quadratic modes, pre-gain and tone");
		m->declare("family", "dirt");
		m->declare("filename", "lib-adaa-drive.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass0_highpass1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "LicenseRef-STK-4.3");
		m->declare("license", "LGPL-2.1-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "ADAA Drive");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/aanl.lib aa.hardclip aa.tanh1 aa.softclipQuadratic1");
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
		fHslider0 = static_cast<FAUSTFLOAT>(-6.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(4.5e+03f);
		fEntry0 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(18.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(1e+02f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec4[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec6[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fVec0[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec1[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec3[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec1[l9] = 0.0f;
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
	
	virtual LibAdaaDrive* clone() {
		return new LibAdaaDrive(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("ADAA Drive");
		ui_interface->declare(&fEntry0, "0", "");
		ui_interface->declare(&fEntry0, "style", "menu{'Hard':0;'Tanh':1;'Quadratic':2}");
		ui_interface->addNumEntry("Mode", &fEntry0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("Drive", &fHslider2, FAUSTFLOAT(18.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(48.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->declare(&fHslider3, "scale", "log");
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("Low Cut", &fHslider3, FAUSTFLOAT(1e+02f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(8e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->declare(&fHslider1, "scale", "log");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Tone", &fHslider1, FAUSTFLOAT(4.5e+03f), FAUSTFLOAT(8e+02f), FAUSTFLOAT(1.2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "4", "");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("Level", &fHslider0, FAUSTFLOAT(-6.0f), FAUSTFLOAT(-3e+01f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider0));
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = static_cast<float>(fEntry0);
		int iSlow3 = fSlow2 >= 2.0f;
		int iSlow4 = fSlow2 >= 1.0f;
		float fSlow5 = fConst1 * std::pow(1e+01f, 0.05f * static_cast<float>(fHslider2));
		float fSlow6 = fConst1 * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			fRec2[0] = fSlow1 + fConst2 * fRec2[1];
			float fTemp0 = 1.0f / std::tan(fConst3 * fRec2[0]);
			fRec4[0] = fSlow5 + fConst2 * fRec4[1];
			fRec6[0] = fSlow6 + fConst2 * fRec6[1];
			float fTemp1 = std::tan(fConst3 * fRec6[0]);
			float fTemp2 = 1.0f / fTemp1;
			float fTemp3 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp3;
			fRec5[0] = -((fRec5[1] * (1.0f - fTemp2) - (fTemp3 - fVec0[1]) / fTemp1) / (fTemp2 + 1.0f));
			float fTemp4 = fRec5[0] * fRec4[0];
			fVec1[0] = fTemp4;
			float fTemp5 = fTemp4 - fVec1[1];
			int iTemp6 = std::fabs(fTemp5) <= 0.001f;
			float fTemp7 = LibAdaaDrive_faustpower2_f(fVec1[1]);
			float fTemp8 = LibAdaaDrive_faustpower2_f(fTemp4);
			float fTemp9 = fTemp4 + fVec1[1];
			float fTemp10 = 0.5f * fTemp9;
			float fTemp11 = std::fabs(fVec1[1]);
			float fTemp12 = std::fabs(fTemp4);
			float fTemp13 = std::fabs(fTemp10);
			float fTemp14 = static_cast<float>((fTemp10 > 0.0f) - (fTemp10 < 0.0f));
			float fTemp15 = ((iSlow3) ? ((iTemp6) ? ((fTemp13 < 0.33333334f) ? fTemp9 : ((fTemp13 < 0.6666667f) ? 0.33333334f * fTemp14 * (3.0f - LibAdaaDrive_faustpower2_f(2.0f - 3.0f * fTemp13)) : fTemp14)) : (((fTemp12 < 0.33333334f) ? fTemp8 : ((fTemp12 < 0.6666667f) ? 2.0f * fTemp8 + (0.037037037f - (LibAdaaDrive_faustpower3_f(fTemp12) + 0.33333334f * fTemp12)) : fTemp12 + -0.25925925f)) - ((fTemp11 < 0.33333334f) ? fTemp7 : ((fTemp11 < 0.6666667f) ? 2.0f * fTemp7 + (0.037037037f - (0.33333334f * fTemp11 + LibAdaaDrive_faustpower3_f(fTemp11))) : fTemp11 + -0.25925925f))) / fTemp5) : ((iSlow4) ? ((iTemp6) ? tanhf(fTemp10) : (std::log(std::min<float>(3.4028235e+38f, coshf(fTemp4))) - std::log(std::min<float>(3.4028235e+38f, coshf(fVec1[1])))) / fTemp5) : ((iTemp6) ? std::max<float>(-1.0f, std::min<float>(1.0f, fTemp10)) : ((((fTemp4 <= 1.0f) & (fTemp4 >= -1.0f)) ? 0.5f * fTemp8 : fTemp4 * static_cast<float>((fTemp4 > 0.0f) - (fTemp4 < 0.0f)) + -0.5f) - (((fVec1[1] <= 1.0f) & (fVec1[1] >= -1.0f)) ? 0.5f * fTemp7 : fVec1[1] * static_cast<float>((fVec1[1] > 0.0f) - (fVec1[1] < 0.0f)) + -0.5f)) / fTemp5)));
			fVec2[0] = fTemp15;
			fRec3[0] = 0.995f * fRec3[1] + fTemp15 - fVec2[1];
			fRec1[0] = -((fRec1[1] * (1.0f - fTemp0) - (fRec3[0] + fRec3[1])) / (fTemp0 + 1.0f));
			output0[i0] = static_cast<FAUSTFLOAT>(fRec1[0] * fRec0[0]);
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fVec0[1] = fVec0[0];
			fRec5[1] = fRec5[0];
			fVec1[1] = fVec1[0];
			fVec2[1] = fVec2[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
