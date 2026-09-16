/* ------------------------------------------------------------
author: "Albert Graef"
license: "GPL-2.0-or-later"
name: "Chorus"
version: "1.0"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxChorus -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxChorus_H__
#define  __GxChorus_H__

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
#define FAUSTCLASS GxChorus
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

class GxChorusSIG0 {
	
  private:
	
	int iRec4[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsGxChorusSIG0() {
		return 0;
	}
	int getNumOutputsGxChorusSIG0() {
		return 1;
	}
	
	void instanceInitGxChorusSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iRec4[l1] = 0;
		}
	}
	
	void fillGxChorusSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iRec4[0] = faust_wrap_add(iRec4[1], 1);
			table[i1] = std::sin(9.587379924285257e-05 * static_cast<double>(iRec4[1]));
			iRec4[1] = iRec4[0];
		}
	}

};

static GxChorusSIG0* newGxChorusSIG0() { return (GxChorusSIG0*)new GxChorusSIG0(); }
static void deleteGxChorusSIG0(GxChorusSIG0* dsp) { delete dsp; }

static double DSY_SDRAM_BSS ftbl0GxChorusSIG0[65536];

class GxChorus : public chdsp {
	
 private:
	
	int IOTA0;
	double fVec0[131072];
	FAUSTFLOAT fHslider0;
	double fRec6[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec5[2];
	FAUSTFLOAT fHslider1;
	double fRec7[2];
	FAUSTFLOAT fHslider2;
	double fRec8[2];
	double fConst2;
	double fConst3;
	double fRec0[2];
	double fRec1[2];
	double fRec2[2];
	double fRec3[2];
	double fRec9[2];
	double fRec10[2];
	double fRec11[2];
	double fRec12[2];
	FAUSTFLOAT fHslider3;
	double fRec13[2];
	
 public:
	GxChorus() {
	}
	
	GxChorus(const GxChorus&) = default;
	
	virtual ~GxChorus() = default;
	
	GxChorus& operator=(const GxChorus&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Albert Graef");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Modulation");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxChorus -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-chorus.dsp");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Chorus");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("version", "1.0");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		GxChorusSIG0* sig0 = newGxChorusSIG0();
		sig0->instanceInitGxChorusSIG0(sample_rate);
		sig0->fillGxChorusSIG0(65536, ftbl0GxChorusSIG0);
		deleteGxChorusSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 1.0 / fConst0;
		fConst2 = 0.5 * fConst0;
		fConst3 = 1e+03 / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(3.0);
		fHslider1 = static_cast<FAUSTFLOAT>(0.02);
		fHslider2 = static_cast<FAUSTFLOAT>(0.02);
		fHslider3 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 131072; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec6[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec5[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec7[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec8[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec0[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec1[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec2[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec3[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec9[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec10[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec11[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec12[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec13[l14] = 0.0;
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
	
	virtual GxChorus* clone() {
		return new GxChorus(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("chorus");
		ui_interface->addHorizontalSlider("de.delay", &fHslider2, FAUSTFLOAT(0.02), FAUSTFLOAT(0.0), FAUSTFLOAT(0.2), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("depth", &fHslider1, FAUSTFLOAT(0.02), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(3.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("level", &fHslider3, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * static_cast<double>(fHslider0);
		double fSlow1 = 0.007000000000000006 * static_cast<double>(fHslider1);
		double fSlow2 = 0.007000000000000006 * static_cast<double>(fHslider2);
		double fSlow3 = 0.007000000000000006 * static_cast<double>(fHslider3);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			fVec0[IOTA0 & 131071] = fTemp0;
			fRec6[0] = fSlow0 + 0.993 * fRec6[1];
			double fTemp1 = fRec5[1] + fConst1 * fRec6[0];
			fRec5[0] = fTemp1 - std::floor(fTemp1);
			double fTemp2 = 65536.0 * (fRec5[0] - std::floor(fRec5[0]));
			double fTemp3 = std::floor(fTemp2);
			int iTemp4 = static_cast<int>(fTemp3);
			fRec7[0] = fSlow1 + 0.993 * fRec7[1];
			fRec8[0] = fSlow2 + 0.993 * fRec8[1];
			double fTemp5 = fConst2 * fRec8[0] * (fRec7[0] * ((fTemp3 + (1.0 - fTemp2)) * ftbl0GxChorusSIG0[iTemp4 & 65535] + (fTemp2 - fTemp3) * ftbl0GxChorusSIG0[(faust_wrap_add(iTemp4, 1)) & 65535]) + 1.0);
			double fTemp6 = ((fRec0[1] != 0.0) ? (((fRec1[1] > 0.0) & (fRec1[1] < 1.0)) ? fRec0[1] : 0.0) : (((fRec1[1] == 0.0) & (fTemp5 != fRec2[1])) ? fConst3 : (((fRec1[1] == 1.0) & (fTemp5 != fRec3[1])) ? -fConst3 : 0.0)));
			fRec0[0] = fTemp6;
			fRec1[0] = std::max<double>(0.0, std::min<double>(1.0, fRec1[1] + fTemp6));
			fRec2[0] = (((fRec1[1] >= 1.0) & (fRec3[1] != fTemp5)) ? fTemp5 : fRec2[1]);
			fRec3[0] = (((fRec1[1] <= 0.0) & (fRec2[1] != fTemp5)) ? fTemp5 : fRec3[1]);
			double fTemp7 = fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(65536.0, std::max<double>(0.0, fRec2[0]))))) & 131071];
			double fTemp8 = 65536.0 * (fRec5[0] + (0.25 - std::floor(fRec5[0] + 0.25)));
			double fTemp9 = std::floor(fTemp8);
			int iTemp10 = static_cast<int>(fTemp9);
			double fTemp11 = fConst2 * fRec8[0] * (fRec7[0] * ((fTemp9 + (1.0 - fTemp8)) * ftbl0GxChorusSIG0[iTemp10 & 65535] + (fTemp8 - fTemp9) * ftbl0GxChorusSIG0[(faust_wrap_add(iTemp10, 1)) & 65535]) + 1.0);
			double fTemp12 = ((fRec9[1] != 0.0) ? (((fRec10[1] > 0.0) & (fRec10[1] < 1.0)) ? fRec9[1] : 0.0) : (((fRec10[1] == 0.0) & (fTemp11 != fRec11[1])) ? fConst3 : (((fRec10[1] == 1.0) & (fTemp11 != fRec12[1])) ? -fConst3 : 0.0)));
			fRec9[0] = fTemp12;
			fRec10[0] = std::max<double>(0.0, std::min<double>(1.0, fRec10[1] + fTemp12));
			fRec11[0] = (((fRec10[1] >= 1.0) & (fRec12[1] != fTemp11)) ? fTemp11 : fRec11[1]);
			fRec12[0] = (((fRec10[1] <= 0.0) & (fRec11[1] != fTemp11)) ? fTemp11 : fRec12[1]);
			double fTemp13 = fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(65536.0, std::max<double>(0.0, fRec11[0]))))) & 131071];
			fRec13[0] = fSlow3 + 0.993 * fRec13[1];
			output0[i0] = static_cast<FAUSTFLOAT>(0.5 * (fRec13[0] * (fTemp13 + fRec10[0] * (fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(65536.0, std::max<double>(0.0, fRec12[0]))))) & 131071] - fTemp13) + fTemp7 + fRec1[0] * (fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(65536.0, std::max<double>(0.0, fRec3[0]))))) & 131071] - fTemp7)) + 2.0 * fTemp0));
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
		}
	}

};

#endif
