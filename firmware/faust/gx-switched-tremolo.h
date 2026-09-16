/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "gx-switched-tremolo"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxSwitchedTremolo -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxSwitchedTremolo_H__
#define  __GxSwitchedTremolo_H__

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
#define FAUSTCLASS GxSwitchedTremolo
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

class GxSwitchedTremoloSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec0[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsGxSwitchedTremoloSIG0() {
		return 0;
	}
	int getNumOutputsGxSwitchedTremoloSIG0() {
		return 1;
	}
	
	void instanceInitGxSwitchedTremoloSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iRec0[l1] = 0;
		}
	}
	
	void fillGxSwitchedTremoloSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec0[0] = 1;
			iRec0[0] = (faust_wrap_add(iVec0[1], iRec0[1])) % 65536;
			table[i1] = std::sin(9.587379924285257e-05 * static_cast<double>(iRec0[0]));
			iVec0[1] = iVec0[0];
			iRec0[1] = iRec0[0];
		}
	}

};

static GxSwitchedTremoloSIG0* newGxSwitchedTremoloSIG0() { return (GxSwitchedTremoloSIG0*)new GxSwitchedTremoloSIG0(); }
static void deleteGxSwitchedTremoloSIG0(GxSwitchedTremoloSIG0* dsp) { delete dsp; }

static double DSY_SDRAM_BSS ftbl0GxSwitchedTremoloSIG0[65536];

class GxSwitchedTremolo : public chdsp {
	
 private:
	
	int iVec1[2];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec1[2];
	double fConst2;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	double fRec3[2];
	double fConst3;
	double fRec2[2];
	FAUSTFLOAT fHslider3;
	double fRec4[2];
	double fRec5[2];
	FAUSTFLOAT fHslider4;
	double fRec6[2];
	double fRec7[2];
	FAUSTFLOAT fHslider5;
	double fRec8[2];
	double fRec9[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fVslider0;
	
 public:
	GxSwitchedTremolo() {
	}
	
	GxSwitchedTremolo(const GxSwitchedTremolo&) = default;
	
	virtual ~GxSwitchedTremolo() = default;
	
	GxSwitchedTremolo& operator=(const GxSwitchedTremolo&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxSwitchedTremolo -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-switched-tremolo.dsp");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "gx-switched-tremolo");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "LicenseRef-STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
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
		GxSwitchedTremoloSIG0* sig0 = newGxSwitchedTremoloSIG0();
		sig0->instanceInitGxSwitchedTremoloSIG0(sample_rate);
		sig0->fillGxSwitchedTremoloSIG0(65536, ftbl0GxSwitchedTremoloSIG0);
		deleteGxSwitchedTremoloSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 1.0 / fConst0;
		fConst2 = std::exp(-(2e+01 / fConst0));
		fConst3 = 1.0 - fConst2;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(1.0);
		fHslider1 = static_cast<FAUSTFLOAT>(4.0);
		fHslider2 = static_cast<FAUSTFLOAT>(1.0);
		fHslider3 = static_cast<FAUSTFLOAT>(1.0);
		fHslider4 = static_cast<FAUSTFLOAT>(1.0);
		fHslider5 = static_cast<FAUSTFLOAT>(1.0);
		fHslider6 = static_cast<FAUSTFLOAT>(0.5);
		fVslider0 = static_cast<FAUSTFLOAT>(1e+02);
	}
	
	virtual void instanceClear() {
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			iVec1[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec3[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec2[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec4[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec5[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec6[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec7[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec8[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec9[l11] = 0.0;
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
	
	virtual GxSwitchedTremolo* clone() {
		return new GxSwitchedTremolo(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("gx-switched-tremolo");
		ui_interface->addHorizontalSlider("Depth", &fHslider6, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addHorizontalSlider("Freq 0", &fHslider5, FAUSTFLOAT(1.0), FAUSTFLOAT(0.25), FAUSTFLOAT(15.0), FAUSTFLOAT(0.5));
		ui_interface->addHorizontalSlider("Freq 1", &fHslider4, FAUSTFLOAT(1.0), FAUSTFLOAT(0.25), FAUSTFLOAT(15.0), FAUSTFLOAT(0.5));
		ui_interface->addHorizontalSlider("Freq 2", &fHslider3, FAUSTFLOAT(1.0), FAUSTFLOAT(0.25), FAUSTFLOAT(15.0), FAUSTFLOAT(0.5));
		ui_interface->addHorizontalSlider("Freq 3", &fHslider0, FAUSTFLOAT(1.0), FAUSTFLOAT(0.25), FAUSTFLOAT(15.0), FAUSTFLOAT(0.5));
		ui_interface->addHorizontalSlider("Steps", &fHslider1, FAUSTFLOAT(4.0), FAUSTFLOAT(1.0), FAUSTFLOAT(4.0), FAUSTFLOAT(1.0));
		ui_interface->addHorizontalSlider("Switch Freq", &fHslider2, FAUSTFLOAT(1.0), FAUSTFLOAT(0.25), FAUSTFLOAT(5.0), FAUSTFLOAT(0.25));
		ui_interface->declare(&fVslider0, "name", "wet/dry");
		ui_interface->declare(&fVslider0, "tooltip", "percentage of processed signal in output signal");
		ui_interface->addVerticalSlider("wet_dry", &fVslider0, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = fConst1 * static_cast<double>(fHslider0);
		double fSlow1 = static_cast<double>(fHslider1);
		double fSlow2 = 3.0 / fSlow1;
		double fSlow3 = fConst1 * static_cast<double>(fHslider2);
		double fSlow4 = 4.0 / fSlow1;
		double fSlow5 = fConst1 * static_cast<double>(fHslider3);
		double fSlow6 = 2.0 / fSlow1;
		double fSlow7 = fConst1 * static_cast<double>(fHslider4);
		double fSlow8 = 1.0 / fSlow1;
		double fSlow9 = fConst1 * static_cast<double>(fHslider5);
		double fSlow10 = static_cast<double>(fHslider6);
		double fSlow11 = 0.01 * static_cast<double>(fVslider0);
		double fSlow12 = 1.0 - fSlow11;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec1[0] = 1;
			int iTemp0 = faust_wrap_sub(1, iVec1[1]);
			double fTemp1 = ((iTemp0) ? 0.0 : fSlow0 + fRec1[1]);
			fRec1[0] = fTemp1 - std::floor(fTemp1);
			double fTemp2 = ((iTemp0) ? 0.0 : fSlow3 + fRec3[1]);
			fRec3[0] = fTemp2 - std::floor(fTemp2);
			fRec2[0] = fConst3 * static_cast<double>((fRec3[0] <= fSlow4) * (fRec3[0] > fSlow2)) + fConst2 * fRec2[1];
			double fTemp3 = ((iTemp0) ? 0.0 : fSlow5 + fRec4[1]);
			fRec4[0] = fTemp3 - std::floor(fTemp3);
			fRec5[0] = fConst3 * static_cast<double>((fRec3[0] <= fSlow2) * (fRec3[0] > fSlow6)) + fConst2 * fRec5[1];
			double fTemp4 = ((iTemp0) ? 0.0 : fSlow7 + fRec6[1]);
			fRec6[0] = fTemp4 - std::floor(fTemp4);
			fRec7[0] = fConst3 * static_cast<double>((fRec3[0] <= fSlow6) * (fRec3[0] > fSlow8)) + fConst2 * fRec7[1];
			double fTemp5 = ((iTemp0) ? 0.0 : fSlow9 + fRec8[1]);
			fRec8[0] = fTemp5 - std::floor(fTemp5);
			fRec9[0] = fConst3 * static_cast<double>((fRec3[0] <= fSlow8) * (fRec3[0] > 0.0)) + fConst2 * fRec9[1];
			output0[i0] = static_cast<FAUSTFLOAT>(static_cast<double>(input0[i0]) * (fSlow12 + fSlow11 * (1.0 - fSlow10 * (1.0 - (fRec9[0] * ftbl0GxSwitchedTremoloSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0 * fRec8[0]), 65535))] + fRec7[0] * ftbl0GxSwitchedTremoloSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0 * fRec6[0]), 65535))] + fRec5[0] * ftbl0GxSwitchedTremoloSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0 * fRec4[0]), 65535))] + fRec2[0] * ftbl0GxSwitchedTremoloSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0 * fRec1[0]), 65535))])))));
			iVec1[1] = iVec1[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
		}
	}

};

#endif
