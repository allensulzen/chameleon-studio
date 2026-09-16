/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "BigMuffPi"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBmp -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxBmp_H__
#define  __GxBmp_H__

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
#define FAUSTCLASS GxBmp
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

const static double fGxBmpSIG0Wave0[100] = {0.00548195523036,0.016445865691,0.0274097761516,0.0383736866119,0.0493375970718,0.060301507531,0.0712654179894,0.0822293284464,0.0931932389016,0.104157149354,0.115121059803,0.126084970245,0.13704888068,0.148012791103,0.158976701508,0.169940611889,0.180904522235,0.19186843253,0.202832342751,0.213796252866,0.224760162828,0.23572407257,0.246687981995,0.257651890962,0.26861579927,0.279579706628,0.290543612617,0.301507516632,0.312471417804,0.323435314878,0.334399206045,0.3453630887,0.356326959087,0.367290811794,0.378254639021,0.389218429528,0.400182167115,0.411145828437,0.422109379849,0.433072772871,0.444035937638,0.454998773485,0.465961135365,0.476922814321,0.48788350936,0.498842787024,0.509800023297,0.520754320256,0.531704386732,0.542648367922,0.55358360312,0.564506283341,0.575410971703,0.586289940184,0.597132269761,0.607922663898,0.618639951041,0.629255322196,0.639730493837,0.650016225239,0.660051925492,0.669767316942,0.679086989359,0.687937882416,0.696258343947,0.704006183628,0.711163121782,0.717734492237,0.723745022743,0.72923269117,0.734242606851,0.738822090117,0.743017303269,0.74687127245,0.750422944114,0.7537069184,0.756753578753,0.759589425229,0.762237491115,0.764717773458,0.767047640962,0.769242202516,0.771314630963,0.773276442704,0.775137736666,0.776907397287,0.778593266396,0.780202288563,0.781740634041,0.783213802858,0.784626713121,0.785983776084,0.787288960129,0.788545845459,0.789757670968,0.790927374556,0.792057627879,0.793150866414,0.794209315546,0.795235013262};
class GxBmpSIG0 {
	
  private:
	
	int fGxBmpSIG0Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxBmpSIG0() {
		return 0;
	}
	int getNumOutputsGxBmpSIG0() {
		return 1;
	}
	
	void instanceInitGxBmpSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		fGxBmpSIG0Wave0_idx = 0;
	}
	
	void fillGxBmpSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			table[i1] = fGxBmpSIG0Wave0[fGxBmpSIG0Wave0_idx];
			fGxBmpSIG0Wave0_idx = (faust_wrap_add(1, fGxBmpSIG0Wave0_idx)) % 100;
		}
	}

};

static GxBmpSIG0* newGxBmpSIG0() { return (GxBmpSIG0*)new GxBmpSIG0(); }
static void deleteGxBmpSIG0(GxBmpSIG0* dsp) { delete dsp; }

static double GxBmp_faustpower2_f(double value) {
	return value * value;
}
static double DSY_SDRAM_BSS ftbl0GxBmpSIG0[100];

class GxBmp : public chdsp {
	
 private:
	
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
	FAUSTFLOAT fVslider0;
	double fRec2[2];
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fConst24;
	FAUSTFLOAT fVslider1;
	double fRec5[2];
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fRec7[3];
	double fConst42;
	double fRec6[3];
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fRec4[3];
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fRec3[3];
	double fConst51;
	double fRec1[3];
	FAUSTFLOAT fVslider2;
	double fRec8[2];
	double fConst52;
	double fRec0[3];
	double fConst53;
	double fConst54;
	double fConst55;
	
 public:
	GxBmp() {
	}
	
	GxBmp(const GxBmp&) = default;
	
	virtual ~GxBmp() = default;
	
	GxBmp& operator=(const GxBmp&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Fuzz");
		m->declare("chameleon_flags", "-double");
		m->declare("clipping.lib/license", "GPL-2.0-or-later");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBmp -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "BigMuffPi");
		m->declare("filename", "gx-bmp.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/peak_eq:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/peak_eq_cq:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq_cq:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq_cq:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("gx_tables.lib/license", "GPL-2.0-or-later");
		m->declare("id", "bmp");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "BigMuffPi");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("samplerate", "96000");
		m->declare("shortname", "BMP");
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
		GxBmpSIG0* sig0 = newGxBmpSIG0();
		sig0->instanceInitGxBmpSIG0(sample_rate);
		sig0->fillGxBmpSIG0(100, ftbl0GxBmpSIG0);
		deleteGxBmpSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = std::tan(37699.11184307752 / fConst0);
		fConst2 = 2.0 * (1.0 - 1.0 / GxBmp_faustpower2_f(fConst1));
		fConst3 = fConst0 * std::sin(75398.22368615503 / fConst0);
		fConst4 = 11800.82018976876 / fConst3;
		fConst5 = 1.0 / fConst1;
		fConst6 = (fConst5 - fConst4) / fConst1 + 1.0;
		fConst7 = 1.0 / ((fConst5 + fConst4) / fConst1 + 1.0);
		fConst8 = 4.33884681055068e-10 * fConst0;
		fConst9 = fConst0 * (fConst8 + -6.86809013445937e-09) + 2.65226702159437e-08;
		fConst10 = GxBmp_faustpower2_f(fConst0);
		fConst11 = 5.30453404318874e-08 - 8.67769362110135e-10 * fConst10;
		fConst12 = fConst0 * (fConst8 + 6.86809013445937e-09) + 2.65226702159437e-08;
		fConst13 = 1.0 / fConst12;
		fConst14 = 8.67101574539126e-07 * fConst0;
		fConst15 = 3.68688858465455e-10 * fConst10 + -0.00316091270975185;
		fConst16 = 3.68688858465455e-10 * fConst0;
		fConst17 = fConst0 * (fConst16 + -3.03485551088694e-06) + 0.00486780557301784;
		fConst18 = 7.37377716930911e-10 * fConst10;
		fConst19 = 0.00973561114603569 - fConst18;
		fConst20 = 1.0 / (fConst0 * (fConst16 + 3.03485551088694e-06) + 0.00486780557301784);
		fConst21 = 3.920487958595e-10 * fConst0;
		fConst22 = fConst0 * (fConst21 + -2.00478727462711e-06) + 0.000489785157611555;
		fConst23 = 0.000979570315223111 - 7.84097591718999e-10 * fConst10;
		fConst24 = 1.0 / (fConst0 * (fConst21 + 2.00478727462711e-06) + 0.000489785157611555);
		fConst25 = 1.13446519814126e-09 * fConst0;
		fConst26 = -2.89110812782566e-06 - fConst25;
		fConst27 = 1.12312054615984e-09 * fConst0;
		fConst28 = fConst27 + 2.8621970465474e-06;
		fConst29 = 1.2821120020393e-10 * fConst0;
		fConst30 = fConst29 + 6.26521815410076e-07;
		fConst31 = 2.26293387153501e-12 * fConst0;
		fConst32 = fConst31 + 1.17905906929765e-05;
		fConst33 = 2.26293387153501e-14 * fConst0;
		fConst34 = fConst33 + 1.17905906929765e-07;
		fConst35 = 2.89110812782566e-06 - fConst25;
		fConst36 = fConst27 + -2.8621970465474e-06;
		fConst37 = fConst29 + -6.26521815410076e-07;
		fConst38 = 2.08287704934496e-05 * fConst0;
		fConst39 = 0.000219016314271736 - fConst38;
		fConst40 = fConst38 + 0.000219016314271736;
		fConst41 = 1.0 / fConst40;
		fConst42 = 3.7454979802542e-06 * (fConst0 / fConst40);
		fConst43 = fConst31 + -1.17905906929765e-05;
		fConst44 = fConst33 + -1.17905906929765e-07;
		fConst45 = ftbl0GxBmpSIG0[99];
		fConst46 = ftbl0GxBmpSIG0[0];
		fConst47 = 7.66731214399861e-12 * fConst0;
		fConst48 = fConst0 * (fConst47 + 3.99490857178962e-05);
		fConst49 = 1.53346242879972e-11 * fConst10;
		fConst50 = fConst0 * (fConst47 + -3.99490857178962e-05);
		fConst51 = -0.00632182541950369 - fConst18;
		fConst52 = fConst10 / fConst12;
		fConst53 = 4435.189628597355 / fConst3;
		fConst54 = (fConst5 - fConst53) / fConst1 + 1.0;
		fConst55 = (fConst5 + fConst53) / fConst1 + 1.0;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(0.5);
		fVslider2 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec2[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec5[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec7[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fRec6[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec1[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec8[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec0[l8] = 0.0;
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
	
	virtual GxBmp* clone() {
		return new GxBmp(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("BigMuffPi");
		ui_interface->declare(&fVslider1, "name", "Sustain");
		ui_interface->addVerticalSlider("Sustain", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider0, "name", "Tone");
		ui_interface->addVerticalSlider("Tone", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider2, "name", "Volume");
		ui_interface->addVerticalSlider("Volume", &fVslider2, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * static_cast<double>(fVslider0);
		double fSlow1 = 0.007000000000000006 * static_cast<double>(fVslider1);
		double fSlow2 = 0.007000000000000006 * static_cast<double>(fVslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = fConst2 * fRec0[1];
			fRec2[0] = fSlow0 + 0.993 * fRec2[1];
			double fTemp1 = fConst15 * fRec2[0] + 0.00401435914138484;
			fRec5[0] = fSlow1 + 0.993 * fRec5[1];
			double fTemp2 = fConst0 * (fConst30 + fRec5[0] * (fConst28 + fConst26 * fRec5[0])) + 0.000146000960455196;
			fRec7[0] = static_cast<double>(input0[i0]) - fConst41 * (fConst39 * fRec7[2] + 0.000438032628543473 * fRec7[1]);
			fRec6[0] = fConst42 * (fRec7[0] - fRec7[2]) - (fRec6[1] * (fConst10 * (fRec5[0] * (2.26893039628251e-09 * fRec5[0] + -2.24624109231969e-09) + -2.5642240040786e-10) + 0.000292001920910392) + fRec6[2] * (fConst0 * (fConst37 + fRec5[0] * (fConst36 + fConst35 * fRec5[0])) + 0.000146000960455196)) / fTemp2;
			double fTemp3 = (fConst0 * fRec6[0] * (fConst44 + fConst43 * fRec5[0]) + fConst10 * fRec6[1] * (-4.52586774307001e-14 - 4.52586774307001e-12 * fRec5[0]) + fConst0 * fRec6[2] * (fConst34 + fConst32 * fRec5[0])) / fTemp2;
			double fTemp4 = std::fabs(fTemp3);
			double fTemp5 = 101.97 * (fTemp4 / (fTemp4 + 3.0) + -0.005);
			double fTemp6 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp5) | std::isinf(fTemp5)) ? 0.0 : fTemp5)));
			int iTemp7 = static_cast<int>(fTemp6);
			int iTemp8 = std::max<int>(0, std::min<int>(98, iTemp7));
			double fTemp9 = static_cast<double>(iTemp8);
			fRec4[0] = copysign(((iTemp7 < 0) ? fConst46 : ((iTemp7 >= 99) ? fConst45 : ftbl0GxBmpSIG0[iTemp8] * (fTemp9 + (1.0 - fTemp6)) + (fTemp6 - fTemp9) * ftbl0GxBmpSIG0[faust_wrap_add(iTemp8, 1)])), -fTemp3) - fConst24 * (fConst23 * fRec4[1] + fConst22 * fRec4[2]);
			double fTemp10 = fConst24 * (fConst50 * fRec4[0] - fConst49 * fRec4[1] + fConst48 * fRec4[2]);
			double fTemp11 = std::fabs(fTemp10);
			double fTemp12 = 101.97 * (fTemp11 / (fTemp11 + 3.0) + -0.005);
			double fTemp13 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp12) | std::isinf(fTemp12)) ? 0.0 : fTemp12)));
			int iTemp14 = static_cast<int>(fTemp13);
			int iTemp15 = std::max<int>(0, std::min<int>(98, iTemp14));
			double fTemp16 = static_cast<double>(iTemp15);
			fRec3[0] = copysign(((iTemp14 < 0) ? fConst46 : ((iTemp14 >= 99) ? fConst45 : ftbl0GxBmpSIG0[iTemp15] * (fTemp16 + (1.0 - fTemp13)) + (fTemp13 - fTemp16) * ftbl0GxBmpSIG0[faust_wrap_add(iTemp15, 1)])), -fTemp10) - fConst20 * (fConst19 * fRec3[1] + fConst17 * fRec3[2]);
			fRec1[0] = fConst20 * (fRec3[0] * (fConst14 + fTemp1) + fRec3[1] * (fConst51 * fRec2[0] + 0.00802871828276969) + fRec3[2] * (fTemp1 - fConst14)) - fConst13 * (fConst11 * fRec1[1] + fConst9 * fRec1[2]);
			fRec8[0] = fSlow2 + 0.993 * fRec8[1];
			fRec0[0] = fConst52 * fRec8[0] * (3.48651798046856e-09 * fRec1[1] - 1.74325899023428e-09 * fRec1[0] - 1.74325899023428e-09 * fRec1[2]) - fConst7 * (fConst6 * fRec0[2] + fTemp0);
			output0[i0] = static_cast<FAUSTFLOAT>(fConst7 * (fTemp0 + fConst55 * fRec0[0] + fConst54 * fRec0[2]));
			fRec2[1] = fRec2[0];
			fRec5[1] = fRec5[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec8[1] = fRec8[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
