/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Tube Screamer"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTs9sim -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxTs9sim_H__
#define  __GxTs9sim_H__

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
#define FAUSTCLASS GxTs9sim
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

const static double fGxTs9simSIG0Wave0[100] = {0.0,-0.0296990148227,-0.0599780676992,-0.0908231643281,-0.122163239629,-0.15376009788,-0.184938007182,-0.214177260107,-0.239335434213,-0.259232575019,-0.274433909887,-0.286183308354,-0.29553854444,-0.303222323477,-0.309706249977,-0.315301338712,-0.320218440785,-0.324604982281,-0.328567120703,-0.332183356975,-0.335513124719,-0.33860236542,-0.34148724693,-0.344196707008,-0.346754233717,-0.34917913798,-0.351487480543,-0.35369275887,-0.355806424152,-0.357838275995,-0.359796767655,-0.361689244919,-0.363522135105,-0.365301098113,-0.367031148289,-0.368716753588,-0.370361916943,-0.371970243537,-0.373544996828,-0.375089145544,-0.376605403346,-0.378096262548,-0.379564022938,-0.381010816596,-0.382438629377,-0.383849319643,-0.385244634694,-0.386626225283,-0.387995658543,-0.389354429565,-0.39070397188,-0.392045667012,-0.393380853288,-0.39471083403,-0.396036885269,-0.397360263098,-0.398682210753,-0.400003965547,-0.401326765733,-0.402651857394,-0.403980501471,-0.405313980999,-0.406653608692,-0.40800073496,-0.409356756504,-0.410723125631,-0.412101360439,-0.413493056085,-0.414899897347,-0.416323672745,-0.417766290556,-0.419229797097,-0.420716397759,-0.422228481377,-0.423768648654,-0.425339745558,-0.426944902828,-0.428587583057,-0.430271637224,-0.432001373102,-0.433781638746,-0.435617925286,-0.437516494692,-0.439484540257,-0.441530390423,-0.443663770898,-0.445896146322,-0.448241172434,-0.450715304661,-0.453338632988,-0.45613605235,-0.45913894467,-0.46238766699,-0.465935359011,-0.469854010456,-0.474244617411,-0.479255257451,-0.48511588606,-0.492212726244,-0.501272723631};
class GxTs9simSIG0 {
	
  private:
	
	int fGxTs9simSIG0Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxTs9simSIG0() {
		return 0;
	}
	int getNumOutputsGxTs9simSIG0() {
		return 1;
	}
	
	void instanceInitGxTs9simSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		fGxTs9simSIG0Wave0_idx = 0;
	}
	
	void fillGxTs9simSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			table[i1] = fGxTs9simSIG0Wave0[fGxTs9simSIG0Wave0_idx];
			fGxTs9simSIG0Wave0_idx = (faust_wrap_add(1, fGxTs9simSIG0Wave0_idx)) % 100;
		}
	}

};

static GxTs9simSIG0* newGxTs9simSIG0() { return (GxTs9simSIG0*)new GxTs9simSIG0(); }
static void deleteGxTs9simSIG0(GxTs9simSIG0* dsp) { delete dsp; }

static double DSY_SDRAM_BSS ftbl0GxTs9simSIG0[100];

class GxTs9sim : public chdsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	double fRec0[2];
	double fVec0[2];
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fRec2[2];
	double fConst5;
	double fConst6;
	double fVec1[2];
	FAUSTFLOAT fHslider2;
	double fConst7;
	double fRec1[2];
	
 public:
	GxTs9sim() {
	}
	
	GxTs9sim(const GxTs9sim&) = default;
	
	virtual ~GxTs9sim() = default;
	
	GxTs9sim& operator=(const GxTs9sim&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Distortion");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxTs9sim -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-ts9sim.dsp");
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
		m->declare("filters.lib/version", "1.9.0");
		m->declare("gx_tables.lib/license", "GPL-2.0-or-later");
		m->declare("id", "ts9sim");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Tube Screamer");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("samplerate", "96000");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		GxTs9simSIG0* sig0 = newGxTs9simSIG0();
		sig0->instanceInitGxTs9simSIG0(sample_rate);
		sig0->fillGxTs9simSIG0(100, ftbl0GxTs9simSIG0);
		deleteGxTs9simSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 9.4e-08 * fConst0;
		fConst2 = 0.00044179999999999995 * fConst0;
		fConst3 = 1.0 - fConst2;
		fConst4 = 1.0 / (fConst2 + 1.0);
		fConst5 = ftbl0GxTs9simSIG0[99];
		fConst6 = ftbl0GxTs9simSIG0[0];
		fConst7 = 3.141592653589793 / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(-16.0);
		fHslider1 = static_cast<FAUSTFLOAT>(0.5);
		fHslider2 = static_cast<FAUSTFLOAT>(4e+02);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fVec0[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec1[l4] = 0.0;
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
	
	virtual GxTs9sim* clone() {
		return new GxTs9sim(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Tube Screamer");
		ui_interface->declare(&fHslider1, "name", "Drive");
		ui_interface->addHorizontalSlider("drive", &fHslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider0, "name", "Level");
		ui_interface->addHorizontalSlider("level", &fHslider0, FAUSTFLOAT(-16.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(4.0), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider2, "log", "");
		ui_interface->declare(&fHslider2, "name", "Tone");
		ui_interface->addHorizontalSlider("tone", &fHslider2, FAUSTFLOAT(4e+02), FAUSTFLOAT(1e+02), FAUSTFLOAT(1e+03), FAUSTFLOAT(1.03));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fHslider0));
		double fSlow1 = fConst1 * (5e+05 * static_cast<double>(fHslider1) + 5.57e+04);
		double fSlow2 = 1.0 - fSlow1;
		double fSlow3 = fSlow1 + 1.0;
		double fSlow4 = 1.0 / std::tan(fConst7 * static_cast<double>(fHslider2));
		double fSlow5 = 1.0 - fSlow4;
		double fSlow6 = 1.0 / (fSlow4 + 1.0);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.999 * fRec0[1];
			double fTemp0 = static_cast<double>(input0[i0]);
			fVec0[0] = fTemp0;
			fRec2[0] = -(fConst4 * (fConst3 * fRec2[1] - (fSlow3 * fTemp0 + fSlow2 * fVec0[1])));
			double fTemp1 = fRec2[0] - fTemp0;
			double fTemp2 = std::fabs(fTemp1);
			double fTemp3 = 101.97 * (fTemp2 / (fTemp2 + 3.0));
			double fTemp4 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp3) | std::isinf(fTemp3)) ? 0.0 : fTemp3)));
			int iTemp5 = static_cast<int>(fTemp4);
			int iTemp6 = std::max<int>(0, std::min<int>(98, iTemp5));
			double fTemp7 = static_cast<double>(iTemp6);
			double fTemp8 = fTemp0 - copysign(((iTemp5 < 0) ? fConst6 : ((iTemp5 >= 99) ? fConst5 : ftbl0GxTs9simSIG0[iTemp6] * (fTemp7 + (1.0 - fTemp4)) + (fTemp4 - fTemp7) * ftbl0GxTs9simSIG0[faust_wrap_add(iTemp6, 1)])), -fTemp1);
			fVec1[0] = fTemp8;
			fRec1[0] = -(fSlow6 * (fSlow5 * fRec1[1] - (fTemp8 + fVec1[1])));
			output0[i0] = static_cast<FAUSTFLOAT>(fRec1[0] * fRec0[0]);
			fRec0[1] = fRec0[0];
			fVec0[1] = fVec0[0];
			fRec2[1] = fRec2[0];
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
