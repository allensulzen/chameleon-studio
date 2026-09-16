/* ------------------------------------------------------------
author: "Albert Graef"
license: "GPL-2.0-or-later"
name: "Chorus Mono"
version: "1.0"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxChorusMono -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxChorusMono_H__
#define  __GxChorusMono_H__

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
#define FAUSTCLASS GxChorusMono
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

class GxChorusMonoSIG0 {
	
  private:
	
	int iRec4[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsGxChorusMonoSIG0() {
		return 0;
	}
	int getNumOutputsGxChorusMonoSIG0() {
		return 1;
	}
	
	void instanceInitGxChorusMonoSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iRec4[l1] = 0;
		}
	}
	
	void fillGxChorusMonoSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iRec4[0] = faust_wrap_add(iRec4[1], 1);
			table[i1] = std::sin(9.587379924285257e-05 * static_cast<double>(iRec4[1]));
			iRec4[1] = iRec4[0];
		}
	}

};

static GxChorusMonoSIG0* newGxChorusMonoSIG0() { return (GxChorusMonoSIG0*)new GxChorusMonoSIG0(); }
static void deleteGxChorusMonoSIG0(GxChorusMonoSIG0* dsp) { delete dsp; }

static double DSY_SDRAM_BSS ftbl0GxChorusMonoSIG0[65536];

class GxChorusMono : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	int IOTA0;
	double fVec0[131072];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec5[2];
	double fConst2;
	double fConst3;
	double fRec0[2];
	double fRec1[2];
	double fRec2[2];
	double fRec3[2];
	FAUSTFLOAT fHslider1;
	double fRec6[2];
	
 public:
	GxChorusMono() {
	}
	
	GxChorusMono(const GxChorusMono&) = default;
	
	virtual ~GxChorusMono() = default;
	
	GxChorusMono& operator=(const GxChorusMono&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Albert Graef");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Modulation");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxChorusMono -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gx-chorus-mono.dsp");
		m->declare("gx-chorus.dsp/author", "Albert Graef");
		m->declare("gx-chorus.dsp/category", "Modulation");
		m->declare("gx-chorus.dsp/chameleon_flags", "-double");
		m->declare("gx-chorus.dsp/license", "GPL-2.0-or-later");
		m->declare("gx-chorus.dsp/name", "Chorus");
		m->declare("gx-chorus.dsp/version", "1.0");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Chorus Mono");
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
		GxChorusMonoSIG0* sig0 = newGxChorusMonoSIG0();
		sig0->instanceInitGxChorusMonoSIG0(sample_rate);
		sig0->fillGxChorusMonoSIG0(65536, ftbl0GxChorusMonoSIG0);
		deleteGxChorusMonoSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 1.0 / fConst0;
		fConst2 = 0.01 * fConst0;
		fConst3 = 1e+03 / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(1e+02);
		fHslider0 = static_cast<FAUSTFLOAT>(2.0);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 131072; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec5[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec0[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec1[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec2[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec3[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec6[l7] = 0.0;
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
	
	virtual GxChorusMono* clone() {
		return new GxChorusMono(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Chorus Mono");
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("level", &fHslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider0, "name", "wet/dry");
		ui_interface->declare(&fVslider0, "tooltip", "percentage of processed signal in output signal");
		ui_interface->addVerticalSlider("wet_dry", &fVslider0, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.01 * static_cast<double>(fVslider0);
		double fSlow1 = fSlow0 + (1.0 - fSlow0);
		double fSlow2 = fConst1 * static_cast<double>(fHslider0);
		double fSlow3 = 0.007000000000000006 * static_cast<double>(fHslider1);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			double fTemp1 = fSlow0 * fTemp0;
			fVec0[IOTA0 & 131071] = fTemp1;
			fRec5[0] = fSlow2 + (fRec5[1] - std::floor(fSlow2 + fRec5[1]));
			double fTemp2 = 65536.0 * (fRec5[0] - std::floor(fRec5[0]));
			double fTemp3 = std::floor(fTemp2);
			int iTemp4 = static_cast<int>(fTemp3);
			double fTemp5 = fConst2 * (0.02 * ((fTemp3 + (1.0 - fTemp2)) * ftbl0GxChorusMonoSIG0[iTemp4 & 65535] + (fTemp2 - fTemp3) * ftbl0GxChorusMonoSIG0[(faust_wrap_add(iTemp4, 1)) & 65535]) + 1.0);
			double fTemp6 = ((fRec0[1] != 0.0) ? (((fRec1[1] > 0.0) & (fRec1[1] < 1.0)) ? fRec0[1] : 0.0) : (((fRec1[1] == 0.0) & (fTemp5 != fRec2[1])) ? fConst3 : (((fRec1[1] == 1.0) & (fTemp5 != fRec3[1])) ? -fConst3 : 0.0)));
			fRec0[0] = fTemp6;
			fRec1[0] = std::max<double>(0.0, std::min<double>(1.0, fRec1[1] + fTemp6));
			fRec2[0] = (((fRec1[1] >= 1.0) & (fRec3[1] != fTemp5)) ? fTemp5 : fRec2[1]);
			fRec3[0] = (((fRec1[1] <= 0.0) & (fRec2[1] != fTemp5)) ? fTemp5 : fRec3[1]);
			double fTemp7 = fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(65536.0, std::max<double>(0.0, fRec2[0]))))) & 131071];
			fRec6[0] = fSlow3 + 0.993 * fRec6[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fRec6[0] * (fTemp7 + fRec1[0] * (fVec0[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<double>(65536.0, std::max<double>(0.0, fRec3[0]))))) & 131071] - fTemp7)) + fSlow1 * fTemp0);
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec5[1] = fRec5[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec6[1] = fRec6[0];
		}
	}

};

#endif
