/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Ruiner"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxRuin -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxRuin_H__
#define  __GxRuin_H__

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
#define FAUSTCLASS GxRuin
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

const static double fGxRuinSIG0Wave0[100] = {0.00548195523036,0.016445865691,0.0274097761516,0.0383736866119,0.0493375970718,0.060301507531,0.0712654179894,0.0822293284464,0.0931932389016,0.104157149354,0.115121059803,0.126084970245,0.13704888068,0.148012791103,0.158976701508,0.169940611889,0.180904522235,0.19186843253,0.202832342751,0.213796252866,0.224760162828,0.23572407257,0.246687981995,0.257651890962,0.26861579927,0.279579706628,0.290543612617,0.301507516632,0.312471417804,0.323435314878,0.334399206045,0.3453630887,0.356326959087,0.367290811794,0.378254639021,0.389218429528,0.400182167115,0.411145828437,0.422109379849,0.433072772871,0.444035937638,0.454998773485,0.465961135365,0.476922814321,0.48788350936,0.498842787024,0.509800023297,0.520754320256,0.531704386732,0.542648367922,0.55358360312,0.564506283341,0.575410971703,0.586289940184,0.597132269761,0.607922663898,0.618639951041,0.629255322196,0.639730493837,0.650016225239,0.660051925492,0.669767316942,0.679086989359,0.687937882416,0.696258343947,0.704006183628,0.711163121782,0.717734492237,0.723745022743,0.72923269117,0.734242606851,0.738822090117,0.743017303269,0.74687127245,0.750422944114,0.7537069184,0.756753578753,0.759589425229,0.762237491115,0.764717773458,0.767047640962,0.769242202516,0.771314630963,0.773276442704,0.775137736666,0.776907397287,0.778593266396,0.780202288563,0.781740634041,0.783213802858,0.784626713121,0.785983776084,0.787288960129,0.788545845459,0.789757670968,0.790927374556,0.792057627879,0.793150866414,0.794209315546,0.795235013262};
class GxRuinSIG0 {
	
  private:
	
	int fGxRuinSIG0Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxRuinSIG0() {
		return 0;
	}
	int getNumOutputsGxRuinSIG0() {
		return 1;
	}
	
	void instanceInitGxRuinSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		fGxRuinSIG0Wave0_idx = 0;
	}
	
	void fillGxRuinSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			table[i1] = fGxRuinSIG0Wave0[fGxRuinSIG0Wave0_idx];
			fGxRuinSIG0Wave0_idx = (faust_wrap_add(1, fGxRuinSIG0Wave0_idx)) % 100;
		}
	}

};

static GxRuinSIG0* newGxRuinSIG0() { return (GxRuinSIG0*)new GxRuinSIG0(); }
static void deleteGxRuinSIG0(GxRuinSIG0* dsp) { delete dsp; }

static double GxRuin_faustpower2_f(double value) {
	return value * value;
}
static double DSY_SDRAM_BSS ftbl0GxRuinSIG0[100];

class GxRuin : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	double fRec0[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	FAUSTFLOAT fVslider1;
	double fRec2[2];
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fConst24;
	double fConst25;
	double fRec3[3];
	double fConst26;
	double fConst27;
	double fConst28;
	double fRec1[4];
	
 public:
	GxRuin() {
	}
	
	GxRuin(const GxRuin&) = default;
	
	virtual ~GxRuin() = default;
	
	GxRuin& operator=(const GxRuin&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Fuzz");
		m->declare("chameleon_flags", "-double");
		m->declare("clipping.lib/license", "GPL-2.0-or-later");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxRuin -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Devi Ever Dark Boost");
		m->declare("drywetbox", "true");
		m->declare("filename", "gx-ruin.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("gx_tables.lib/license", "GPL-2.0-or-later");
		m->declare("id", "ruin");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Ruiner");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("samplerate", "96000");
		m->declare("shortname", "Ruiner");
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
		GxRuinSIG0* sig0 = newGxRuinSIG0();
		sig0->instanceInitGxRuinSIG0(sample_rate);
		sig0->fillGxRuinSIG0(100, ftbl0GxRuinSIG0);
		deleteGxRuinSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 8.62067474057856e-16 * fConst0;
		fConst2 = fConst0 * (-4.46379387426086e-13 - fConst1) + -5.75832602737396e-11;
		fConst3 = 8.53446799317278e-16 * fConst0;
		fConst4 = fConst0 * (fConst3 + 5.28122340957611e-13) + 7.99957173492034e-11;
		fConst5 = 8.71550216272493e-15 * fConst0;
		fConst6 = fConst0 * (fConst0 * (fConst5 + 5.37582514840965e-12) + 8.12279541046302e-10);
		fConst7 = fConst0 * (fConst1 + -4.46379387426086e-13) + 5.75832602737396e-11;
		fConst8 = fConst0 * (5.28122340957611e-13 - fConst3) + -7.99957173492034e-11;
		fConst9 = fConst0 * (fConst0 * (5.37582514840965e-12 - fConst5) + -8.12279541046302e-10);
		fConst10 = 2.58620242217357e-15 * fConst0;
		fConst11 = fConst0 * (4.46379387426086e-13 - fConst10) + 5.75832602737396e-11;
		fConst12 = 2.56034039795183e-15 * fConst0;
		fConst13 = fConst0 * (fConst12 + -5.28122340957611e-13) + -7.99957173492034e-11;
		fConst14 = 2.61465064881748e-14 * fConst0;
		fConst15 = fConst0 * (fConst0 * (fConst14 + -5.37582514840965e-12) + -8.12279541046302e-10);
		fConst16 = fConst0 * (fConst10 + 4.46379387426086e-13) + -5.75832602737396e-11;
		fConst17 = fConst0 * (-5.28122340957611e-13 - fConst12) + 7.99957173492034e-11;
		fConst18 = fConst0 * (fConst0 * (-5.37582514840965e-12 - fConst14) + 8.12279541046302e-10);
		fConst19 = 3.23341143501596e-10 * fConst0;
		fConst20 = fConst19 + 1.83849805831657e-06;
		fConst21 = 2.50211258533327e-10 * fConst0;
		fConst22 = fConst21 + 1.41841348392955e-07;
		fConst23 = fConst19 + -1.83849805831657e-06;
		fConst24 = fConst21 + -1.41841348392955e-07;
		fConst25 = GxRuin_faustpower2_f(fConst0);
		fConst26 = 3.68740376472719e-05 * fConst0;
		fConst27 = ftbl0GxRuinSIG0[99];
		fConst28 = ftbl0GxRuinSIG0[0];
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec2[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec3[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 4; l3 = faust_wrap_add(l3, 1)) {
			fRec1[l3] = 0.0;
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
	
	virtual GxRuin* clone() {
		return new GxRuin(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Ruiner");
		ui_interface->declare(&fVslider1, "name", "Intensity");
		ui_interface->addVerticalSlider("Intensity", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider0, "name", "Level");
		ui_interface->addVerticalSlider("Level", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * static_cast<double>(fVslider0);
		double fSlow1 = 0.007000000000000006 * (1.0 - static_cast<double>(fVslider1));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			double fTemp0 = fConst6 + fRec0[0] * (fConst0 * (fConst4 + fConst2 * fRec0[0]) + 2.87916301368698e-09) + 2.88204217670067e-08;
			double fTemp1 = 1.11891193819806e-10 * fRec0[0];
			double fTemp2 = -1.11891193819806e-12 - fTemp1;
			fRec2[0] = fSlow1 + 0.993 * fRec2[1];
			double fTemp3 = fConst0 * (fConst22 + fConst20 * fRec2[0]) + 9.19249029158284e-05;
			fRec3[0] = static_cast<double>(input0[i0]) - (fRec3[1] * (fConst25 * (-5.00422517066654e-10 - 6.46682287003193e-10 * fRec2[0]) + 0.000183849805831657) + fRec3[2] * (fConst0 * (fConst24 + fConst23 * fRec2[0]) + 9.19249029158284e-05)) / fTemp3;
			double fTemp4 = fConst26 * ((fRec3[0] - fRec3[2]) / fTemp3);
			double fTemp5 = std::fabs(-fTemp4);
			double fTemp6 = 101.97 * (fTemp5 / (fTemp5 + 3.0) + -0.005);
			double fTemp7 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp6) | std::isinf(fTemp6)) ? 0.0 : fTemp6)));
			int iTemp8 = static_cast<int>(fTemp7);
			int iTemp9 = std::max<int>(0, std::min<int>(98, iTemp8));
			double fTemp10 = static_cast<double>(iTemp9);
			fRec1[0] = copysign(((iTemp8 < 0) ? fConst28 : ((iTemp8 >= 99) ? fConst27 : ftbl0GxRuinSIG0[iTemp9] * (fTemp10 + (1.0 - fTemp7)) + (fTemp7 - fTemp10) * ftbl0GxRuinSIG0[faust_wrap_add(iTemp9, 1)])), fTemp4) - (fRec1[1] * (fConst18 + fRec0[0] * (fConst0 * (fConst17 + fConst16 * fRec0[0]) + 8.63748904106094e-09) + 8.646126530102e-08) + fRec1[2] * (fConst15 + fRec0[0] * (fConst0 * (fConst13 + fConst11 * fRec0[0]) + 8.63748904106094e-09) + 8.646126530102e-08) + fRec1[3] * (fConst9 + fRec0[0] * (fConst0 * (fConst8 + fConst7 * fRec0[0]) + 2.87916301368698e-09) + 2.88204217670067e-08)) / fTemp0;
			double fTemp11 = fTemp1 + 1.11891193819806e-12;
			output0[i0] = static_cast<FAUSTFLOAT>(fConst25 * ((fRec1[0] * fTemp2 + fRec1[1] * fTemp11 + fRec1[2] * fTemp11 + fRec1[3] * fTemp2) / fTemp0));
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			for (int j0 = 3; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec1[j0] = fRec1[faust_wrap_sub(j0, 1)];
			}
		}
	}

};

#endif
