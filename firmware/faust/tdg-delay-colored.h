/* ------------------------------------------------------------
author: "thedrgreenthumb (Sergey Konstantinov)"
license: "MIT"
name: "Delay Colored"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgDelayColored -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __TdgDelayColored_H__
#define  __TdgDelayColored_H__

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
#define FAUSTCLASS TdgDelayColored
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

static float TdgDelayColored_faustpower2_f(float value) {
	return value * value;
}

class TdgDelayColored : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
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
	FAUSTFLOAT fHslider1;
	float fRec5[2];
	int IOTA0;
	float fVec0[262144];
	float fConst13;
	FAUSTFLOAT fHslider2;
	float fConst14;
	float fRec6[2];
	float fConst15;
	float fRec4[2];
	float fConst16;
	float fConst17;
	float fRec3[2];
	float fRec2[3];
	float fConst18;
	float fRec1[3];
	float fRec9[2];
	float fRec8[3];
	float fRec7[3];
	float fConst19;
	float fConst20;
	float fConst21;
	float fConst22;
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fConst30;
	float fRec12[2];
	float fRec11[3];
	float fConst31;
	float fRec10[3];
	float fRec15[2];
	float fRec14[3];
	float fRec13[3];
	FAUSTFLOAT fHslider3;
	float fRec16[2];
	
 public:
	TdgDelayColored() {
	}
	
	TdgDelayColored(const TdgDelayColored&) = default;
	
	virtual ~TdgDelayColored() = default;
	
	TdgDelayColored& operator=(const TdgDelayColored&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "thedrgreenthumb (Sergey Konstantinov)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn TdgDelayColored -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Feedback delay with a tilt-style coloration filter on the repeats (dark low-shelf to bright high-shelf)");
		m->declare("family", "time");
		m->declare("filename", "tdg-delay-colored.dsp");
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
		m->declare("filters.lib/lowshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/lowshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowshelf:license", "LicenseRef-STK-4.3");
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
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Delay Colored");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "thedrgreenthumb/faust circles/delay_colored.dsp + geometry.lib");
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
		fConst3 = std::tan(2764.6016f / fConst0);
		fConst4 = TdgDelayColored_faustpower2_f(fConst3);
		fConst5 = 1.0f / fConst4;
		fConst6 = 2.0f * (1.0f - fConst5);
		fConst7 = 1.0f / fConst3;
		fConst8 = (fConst7 + -0.618034f) / fConst3 + 1.0f;
		fConst9 = 1.0f / ((fConst7 + 0.618034f) / fConst3 + 1.0f);
		fConst10 = (fConst7 + -1.618034f) / fConst3 + 1.0f;
		fConst11 = (fConst7 + 1.618034f) / fConst3 + 1.0f;
		fConst12 = 1.0f / fConst11;
		fConst13 = std::exp(-(2e+01f / fConst0));
		fConst14 = 1.0f - fConst13;
		fConst15 = 0.001f * fConst0;
		fConst16 = 1.0f - fConst7;
		fConst17 = 1.0f / (fConst7 + 1.0f);
		fConst18 = 1.0f / (fConst4 * fConst11);
		fConst19 = std::tan(1382.3008f / fConst0);
		fConst20 = TdgDelayColored_faustpower2_f(fConst19);
		fConst21 = 1.0f / fConst20;
		fConst22 = 2.0f * (1.0f - fConst21);
		fConst23 = 1.0f / fConst19;
		fConst24 = (fConst23 + -0.618034f) / fConst19 + 1.0f;
		fConst25 = 1.0f / ((fConst23 + 0.618034f) / fConst19 + 1.0f);
		fConst26 = (fConst23 + -1.618034f) / fConst19 + 1.0f;
		fConst27 = (fConst23 + 1.618034f) / fConst19 + 1.0f;
		fConst28 = 1.0f / fConst27;
		fConst29 = 1.0f - fConst23;
		fConst30 = 1.0f / (fConst23 + 1.0f);
		fConst31 = 1.0f / (fConst20 * fConst27);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider2 = static_cast<FAUSTFLOAT>(5e+02f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec5[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 262144; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec6[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec1[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec9[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec7[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec12[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 3; l12 = faust_wrap_add(l12, 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = faust_wrap_add(l13, 1)) {
			fRec10[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec15[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 3; l15 = faust_wrap_add(l15, 1)) {
			fRec14[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 3; l16 = faust_wrap_add(l16, 1)) {
			fRec13[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec16[l17] = 0.0f;
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
	
	virtual TdgDelayColored* clone() {
		return new TdgDelayColored(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Delay Colored");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "unit", "ms");
		ui_interface->addHorizontalSlider("Time", &fHslider2, FAUSTFLOAT(5e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Feedback", &fHslider1, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->addHorizontalSlider("Coloration", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "9", "");
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst1 * static_cast<float>(fHslider1);
		float fSlow2 = fConst14 * static_cast<float>(fHslider2);
		float fSlow3 = fConst1 * static_cast<float>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			fRec5[0] = fSlow1 + fConst2 * fRec5[1];
			float fTemp0 = static_cast<float>(input0[i0]);
			float fTemp1 = fTemp0 + fRec5[0] * fRec4[1];
			fVec0[IOTA0 & 262143] = fTemp1;
			fRec6[0] = fSlow2 + fConst13 * fRec6[1];
			float fTemp2 = fConst15 * fRec6[0];
			int iTemp3 = static_cast<int>(fTemp2);
			float fTemp4 = std::floor(fTemp2);
			fRec4[0] = fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, iTemp3)))) & 262143] * (fTemp4 + (1.0f - fTemp2)) + (fTemp2 - fTemp4) * fVec0[(faust_wrap_sub(IOTA0, std::min<int>(131073, std::max<int>(0, faust_wrap_add(iTemp3, 1))))) & 262143];
			float fTemp5 = fRec4[0] - fRec4[1];
			fRec3[0] = -(fConst17 * (fConst16 * fRec3[1] - fConst7 * fTemp5));
			fRec2[0] = fRec3[0] - fConst12 * (fConst10 * fRec2[2] + fConst6 * fRec2[1]);
			fRec1[0] = fConst18 * (fRec2[2] + (fRec2[0] - 2.0f * fRec2[1])) - fConst9 * (fConst8 * fRec1[2] + fConst6 * fRec1[1]);
			float fTemp6 = fRec4[0] + fRec4[1];
			fRec9[0] = -(fConst17 * (fConst16 * fRec9[1] - fTemp6));
			fRec8[0] = fRec9[0] - fConst12 * (fConst10 * fRec8[2] + fConst6 * fRec8[1]);
			fRec7[0] = fConst12 * (fRec8[2] + fRec8[0] + 2.0f * fRec8[1]) - fConst9 * (fConst8 * fRec7[2] + fConst6 * fRec7[1]);
			fRec12[0] = -(fConst30 * (fConst29 * fRec12[1] - fConst23 * fTemp5));
			fRec11[0] = fRec12[0] - fConst28 * (fConst26 * fRec11[2] + fConst22 * fRec11[1]);
			fRec10[0] = fConst31 * (fRec11[2] + (fRec11[0] - 2.0f * fRec11[1])) - fConst25 * (fConst24 * fRec10[2] + fConst22 * fRec10[1]);
			fRec15[0] = -(fConst30 * (fConst29 * fRec15[1] - fTemp6));
			fRec14[0] = fRec15[0] - fConst28 * (fConst26 * fRec14[2] + fConst22 * fRec14[1]);
			fRec13[0] = fConst28 * (fRec14[2] + fRec14[0] + 2.0f * fRec14[1]) - fConst25 * (fConst24 * fRec13[2] + fConst22 * fRec13[1]);
			fRec16[0] = fSlow3 + fConst2 * fRec16[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec16[0]) + 0.17782794f * fRec16[0] * (fConst25 * ((fRec13[2] + fRec13[0] + 2.0f * fRec13[1]) * std::pow(1e+01f, 0.6f * (1.0f - fRec0[0])) + fConst21 * (fRec10[2] + (fRec10[0] - 2.0f * fRec10[1]))) + fConst9 * (fRec7[2] + fRec7[0] + 2.0f * fRec7[1] + fConst5 * (fRec1[2] + (fRec1[0] - 2.0f * fRec1[1])) * std::pow(1e+01f, 0.6f * fRec0[0]))));
			fRec0[1] = fRec0[0];
			fRec5[1] = fRec5[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec16[1] = fRec16[0];
		}
	}

};

#endif
