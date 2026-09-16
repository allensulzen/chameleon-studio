/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "MultiBand Clipper"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbclipper -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxMbclipper_H__
#define  __GxMbclipper_H__

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
#define FAUSTCLASS GxMbclipper
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

const static double fGxMbclipperSIG0Wave0[100] = {0.00548195523036,0.016445865691,0.0274097761516,0.0383736866119,0.0493375970718,0.060301507531,0.0712654179894,0.0822293284464,0.0931932389016,0.104157149354,0.115121059803,0.126084970245,0.13704888068,0.148012791103,0.158976701508,0.169940611889,0.180904522235,0.19186843253,0.202832342751,0.213796252866,0.224760162828,0.23572407257,0.246687981995,0.257651890962,0.26861579927,0.279579706628,0.290543612617,0.301507516632,0.312471417804,0.323435314878,0.334399206045,0.3453630887,0.356326959087,0.367290811794,0.378254639021,0.389218429528,0.400182167115,0.411145828437,0.422109379849,0.433072772871,0.444035937638,0.454998773485,0.465961135365,0.476922814321,0.48788350936,0.498842787024,0.509800023297,0.520754320256,0.531704386732,0.542648367922,0.55358360312,0.564506283341,0.575410971703,0.586289940184,0.597132269761,0.607922663898,0.618639951041,0.629255322196,0.639730493837,0.650016225239,0.660051925492,0.669767316942,0.679086989359,0.687937882416,0.696258343947,0.704006183628,0.711163121782,0.717734492237,0.723745022743,0.72923269117,0.734242606851,0.738822090117,0.743017303269,0.74687127245,0.750422944114,0.7537069184,0.756753578753,0.759589425229,0.762237491115,0.764717773458,0.767047640962,0.769242202516,0.771314630963,0.773276442704,0.775137736666,0.776907397287,0.778593266396,0.780202288563,0.781740634041,0.783213802858,0.784626713121,0.785983776084,0.787288960129,0.788545845459,0.789757670968,0.790927374556,0.792057627879,0.793150866414,0.794209315546,0.795235013262};
class GxMbclipperSIG0 {
	
  private:
	
	int fGxMbclipperSIG0Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxMbclipperSIG0() {
		return 0;
	}
	int getNumOutputsGxMbclipperSIG0() {
		return 1;
	}
	
	void instanceInitGxMbclipperSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		fGxMbclipperSIG0Wave0_idx = 0;
	}
	
	void fillGxMbclipperSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			table[i1] = fGxMbclipperSIG0Wave0[fGxMbclipperSIG0Wave0_idx];
			fGxMbclipperSIG0Wave0_idx = (faust_wrap_add(1, fGxMbclipperSIG0Wave0_idx)) % 100;
		}
	}

};

static GxMbclipperSIG0* newGxMbclipperSIG0() { return (GxMbclipperSIG0*)new GxMbclipperSIG0(); }
static void deleteGxMbclipperSIG0(GxMbclipperSIG0* dsp) { delete dsp; }

static double GxMbclipper_faustpower2_f(double value) {
	return value * value;
}
static double DSY_SDRAM_BSS ftbl0GxMbclipperSIG0[100];

class GxMbclipper : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fHslider0;
	double fConst2;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	double fRec11[2];
	double fVec1[2];
	double fRec10[2];
	double fRec9[3];
	double fVec2[2];
	double fRec8[2];
	double fRec7[3];
	double fVec3[2];
	double fRec6[2];
	double fRec5[3];
	double fVec4[2];
	double fRec4[2];
	double fRec3[3];
	FAUSTFLOAT fHslider4;
	double fRec12[2];
	double fConst3;
	double fConst4;
	FAUSTFLOAT fVslider0;
	double fRec13[2];
	double fRec0[2];
	int iRec1[2];
	double fRec2[2];
	FAUSTFLOAT fVbargraph0;
	double fRec18[2];
	double fRec17[3];
	FAUSTFLOAT fHslider5;
	double fRec19[2];
	FAUSTFLOAT fVslider1;
	double fRec20[2];
	double fRec14[2];
	int iRec15[2];
	double fRec16[2];
	FAUSTFLOAT fVbargraph1;
	double fRec26[2];
	double fRec25[3];
	double fRec24[3];
	FAUSTFLOAT fHslider6;
	double fRec27[2];
	FAUSTFLOAT fVslider2;
	double fRec28[2];
	double fRec21[2];
	int iRec22[2];
	double fRec23[2];
	FAUSTFLOAT fVbargraph2;
	double fRec35[2];
	double fRec34[3];
	double fRec33[3];
	double fRec32[3];
	FAUSTFLOAT fHslider7;
	double fRec36[2];
	FAUSTFLOAT fVslider3;
	double fRec37[2];
	double fRec29[2];
	int iRec30[2];
	double fRec31[2];
	FAUSTFLOAT fVbargraph3;
	double fRec45[2];
	double fRec44[3];
	double fRec43[3];
	double fRec42[3];
	double fRec41[3];
	FAUSTFLOAT fHslider8;
	double fRec46[2];
	FAUSTFLOAT fVslider4;
	double fRec47[2];
	double fRec38[2];
	int iRec39[2];
	double fRec40[2];
	FAUSTFLOAT fVbargraph4;
	FAUSTFLOAT fVslider5;
	double fRec48[2];
	
 public:
	GxMbclipper() {
	}
	
	GxMbclipper(const GxMbclipper&) = default;
	
	virtual ~GxMbclipper() = default;
	
	GxMbclipper& operator=(const GxMbclipper&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Distortion");
		m->declare("chameleon_flags", "-double");
		m->declare("clipping.lib/license", "GPL-2.0-or-later");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMbclipper -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "MultiBand Clipper");
		m->declare("filename", "gx-mbclipper.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass_plus_lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass_plus_lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:license", "LicenseRef-STK-4.3");
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
		m->declare("gx_tables.lib/license", "GPL-2.0-or-later");
		m->declare("id", "mbclip");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "MultiBand Clipper");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reducemaps.lib/author", "Yann Orlarey");
		m->declare("reducemaps.lib/copyright", "Grame and Yann Orlarey");
		m->declare("reducemaps.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("reducemaps.lib/name", "Reduce Library");
		m->declare("reducemaps.lib/version", "1.2.0");
		m->declare("shortname", "MB Clipper");
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
		GxMbclipperSIG0* sig0 = newGxMbclipperSIG0();
		sig0->instanceInitGxMbclipperSIG0(sample_rate);
		sig0->fillGxMbclipperSIG0(100, ftbl0GxMbclipperSIG0);
		deleteGxMbclipperSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 1.0 / fConst0;
		fConst2 = 3.141592653589793 / fConst0;
		fConst3 = ftbl0GxMbclipperSIG0[99];
		fConst4 = ftbl0GxMbclipperSIG0[0];
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(8e+01);
		fHslider1 = static_cast<FAUSTFLOAT>(2.1e+02);
		fHslider2 = static_cast<FAUSTFLOAT>(1.7e+03);
		fHslider3 = static_cast<FAUSTFLOAT>(5e+03);
		fHslider4 = static_cast<FAUSTFLOAT>(0.33);
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
		fHslider5 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(0.0);
		fHslider6 = static_cast<FAUSTFLOAT>(0.65);
		fVslider2 = static_cast<FAUSTFLOAT>(0.0);
		fHslider7 = static_cast<FAUSTFLOAT>(0.33);
		fVslider3 = static_cast<FAUSTFLOAT>(0.0);
		fHslider8 = static_cast<FAUSTFLOAT>(0.1);
		fVslider4 = static_cast<FAUSTFLOAT>(0.0);
		fVslider5 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec11[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fVec1[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec10[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec9[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fVec2[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec8[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec7[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fVec3[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec6[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec5[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fVec4[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec4[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 3; l13 = faust_wrap_add(l13, 1)) {
			fRec3[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec12[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fRec13[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec0[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			iRec1[l17] = 0;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec2[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec18[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 3; l20 = faust_wrap_add(l20, 1)) {
			fRec17[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fRec19[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec20[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec14[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			iRec15[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec16[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec26[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 3; l27 = faust_wrap_add(l27, 1)) {
			fRec25[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 3; l28 = faust_wrap_add(l28, 1)) {
			fRec24[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec27[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec28[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec21[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			iRec22[l32] = 0;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec23[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec35[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 3; l35 = faust_wrap_add(l35, 1)) {
			fRec34[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 3; l36 = faust_wrap_add(l36, 1)) {
			fRec33[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 3; l37 = faust_wrap_add(l37, 1)) {
			fRec32[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fRec36[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec37[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec29[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			iRec30[l41] = 0;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			fRec31[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec45[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 3; l44 = faust_wrap_add(l44, 1)) {
			fRec44[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 3; l45 = faust_wrap_add(l45, 1)) {
			fRec43[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 3; l46 = faust_wrap_add(l46, 1)) {
			fRec42[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 3; l47 = faust_wrap_add(l47, 1)) {
			fRec41[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec46[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec47[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec38[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			iRec39[l51] = 0;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec40[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fRec48[l53] = 0.0;
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
	
	virtual GxMbclipper* clone() {
		return new GxMbclipper(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("MultiBand Clipper");
		ui_interface->declare(&fHslider4, "tooltip", "Amount of distortion");
		ui_interface->addHorizontalSlider("Drive1", &fHslider4, FAUSTFLOAT(0.33), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider5, "tooltip", "Amount of distortion");
		ui_interface->addHorizontalSlider("Drive2", &fHslider5, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider6, "tooltip", "Amount of distortion");
		ui_interface->addHorizontalSlider("Drive3", &fHslider6, FAUSTFLOAT(0.65), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider7, "tooltip", "Amount of distortion");
		ui_interface->addHorizontalSlider("Drive4", &fHslider7, FAUSTFLOAT(0.33), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider8, "tooltip", "Amount of distortion");
		ui_interface->addHorizontalSlider("Drive5", &fHslider8, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addVerticalSlider("Gain", &fVslider5, FAUSTFLOAT(0.0), FAUSTFLOAT(-4e+01), FAUSTFLOAT(4.0), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("Gain1", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(-4e+01), FAUSTFLOAT(4.0), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("Gain2", &fVslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-4e+01), FAUSTFLOAT(4.0), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("Gain3", &fVslider2, FAUSTFLOAT(0.0), FAUSTFLOAT(-4e+01), FAUSTFLOAT(4.0), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("Gain4", &fVslider3, FAUSTFLOAT(0.0), FAUSTFLOAT(-4e+01), FAUSTFLOAT(4.0), FAUSTFLOAT(0.1));
		ui_interface->addVerticalSlider("Gain5", &fVslider4, FAUSTFLOAT(0.0), FAUSTFLOAT(-4e+01), FAUSTFLOAT(4.0), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider0, "log", "");
		ui_interface->declare(&fHslider0, "name", "Crossover B1-B2 (hz)");
		ui_interface->declare(&fHslider0, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b1_b2", &fHslider0, FAUSTFLOAT(8e+01), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fHslider1, "log", "");
		ui_interface->declare(&fHslider1, "name", "Crossover B2-B3 (hz)");
		ui_interface->declare(&fHslider1, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b2_b3", &fHslider1, FAUSTFLOAT(2.1e+02), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fHslider2, "log", "");
		ui_interface->declare(&fHslider2, "name", "Crossover B3-B4 (hz)");
		ui_interface->declare(&fHslider2, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b3_b4", &fHslider2, FAUSTFLOAT(1.7e+03), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fHslider3, "log", "");
		ui_interface->declare(&fHslider3, "name", "Crossover B4-B5 (hz)");
		ui_interface->declare(&fHslider3, "tooltip", "Crossover fi.bandpass frequency");
		ui_interface->addHorizontalSlider("crossover_b4_b5", &fHslider3, FAUSTFLOAT(5e+03), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.08));
		ui_interface->declare(&fVbargraph0, "log", "");
		ui_interface->declare(&fVbargraph0, "nomidi", "");
		ui_interface->addVerticalBargraph("v1", &fVbargraph0, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph1, "log", "");
		ui_interface->declare(&fVbargraph1, "nomidi", "");
		ui_interface->addVerticalBargraph("v2", &fVbargraph1, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph2, "log", "");
		ui_interface->declare(&fVbargraph2, "nomidi", "");
		ui_interface->addVerticalBargraph("v3", &fVbargraph2, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph3, "log", "");
		ui_interface->declare(&fVbargraph3, "nomidi", "");
		ui_interface->addVerticalBargraph("v4", &fVbargraph3, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph4, "log", "");
		ui_interface->declare(&fVbargraph4, "nomidi", "");
		ui_interface->addVerticalBargraph("v5", &fVbargraph4, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = std::tan(fConst2 * static_cast<double>(fHslider0));
		double fSlow1 = GxMbclipper_faustpower2_f(fSlow0);
		double fSlow2 = 2.0 * (1.0 - 1.0 / fSlow1);
		double fSlow3 = 1.0 / fSlow0;
		double fSlow4 = (fSlow3 + -1.0000000000000004) / fSlow0 + 1.0;
		double fSlow5 = (fSlow3 + 1.0000000000000004) / fSlow0 + 1.0;
		double fSlow6 = 1.0 / fSlow5;
		double fSlow7 = std::tan(fConst2 * static_cast<double>(fHslider1));
		double fSlow8 = GxMbclipper_faustpower2_f(fSlow7);
		double fSlow9 = 2.0 * (1.0 - 1.0 / fSlow8);
		double fSlow10 = 1.0 / fSlow7;
		double fSlow11 = (fSlow10 + -1.0000000000000004) / fSlow7 + 1.0;
		double fSlow12 = (fSlow10 + 1.0000000000000004) / fSlow7 + 1.0;
		double fSlow13 = 1.0 / fSlow12;
		double fSlow14 = std::tan(fConst2 * static_cast<double>(fHslider2));
		double fSlow15 = GxMbclipper_faustpower2_f(fSlow14);
		double fSlow16 = 2.0 * (1.0 - 1.0 / fSlow15);
		double fSlow17 = 1.0 / fSlow14;
		double fSlow18 = (fSlow17 + -1.0000000000000004) / fSlow14 + 1.0;
		double fSlow19 = (fSlow17 + 1.0000000000000004) / fSlow14 + 1.0;
		double fSlow20 = 1.0 / fSlow19;
		double fSlow21 = std::tan(fConst2 * static_cast<double>(fHslider3));
		double fSlow22 = GxMbclipper_faustpower2_f(fSlow21);
		double fSlow23 = 2.0 * (1.0 - 1.0 / fSlow22);
		double fSlow24 = 1.0 / fSlow21;
		double fSlow25 = (fSlow24 + -1.0000000000000004) / fSlow21 + 1.0;
		double fSlow26 = (fSlow24 + 1.0000000000000004) / fSlow21 + 1.0;
		double fSlow27 = 1.0 / fSlow26;
		double fSlow28 = 1.0 - fSlow24;
		double fSlow29 = 1.0 / (fSlow24 + 1.0);
		double fSlow30 = 1.0 - fSlow17;
		double fSlow31 = fSlow17 + 1.0;
		double fSlow32 = 1.0 / fSlow31;
		double fSlow33 = 1.0 - fSlow10;
		double fSlow34 = fSlow10 + 1.0;
		double fSlow35 = 1.0 / fSlow34;
		double fSlow36 = 1.0 - fSlow3;
		double fSlow37 = fSlow3 + 1.0;
		double fSlow38 = 1.0 / fSlow37;
		double fSlow39 = 0.0010000000000000009 * static_cast<double>(fHslider4);
		double fSlow40 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider0));
		double fSlow41 = 0.0010000000000000009 * static_cast<double>(fHslider5);
		double fSlow42 = 1.0 / (fSlow1 * fSlow5);
		double fSlow43 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider1));
		double fSlow44 = 1.0 - fSlow36 / fSlow0;
		double fSlow45 = 1.0 / (fSlow37 / fSlow0 + 1.0);
		double fSlow46 = 1.0 / (fSlow8 * fSlow12);
		double fSlow47 = 0.0010000000000000009 * static_cast<double>(fHslider6);
		double fSlow48 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider2));
		double fSlow49 = 1.0 - fSlow33 / fSlow7;
		double fSlow50 = 1.0 / (fSlow34 / fSlow7 + 1.0);
		double fSlow51 = 1.0 / (fSlow15 * fSlow19);
		double fSlow52 = 0.0010000000000000009 * static_cast<double>(fHslider7);
		double fSlow53 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider3));
		double fSlow54 = 1.0 - fSlow30 / fSlow14;
		double fSlow55 = 1.0 / (fSlow31 / fSlow14 + 1.0);
		double fSlow56 = 1.0 / (fSlow22 * fSlow26);
		double fSlow57 = 0.0010000000000000009 * static_cast<double>(fHslider8);
		double fSlow58 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider4));
		double fSlow59 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider5));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			int iTemp0 = iRec1[1] < 4096;
			fRec11[0] = 1e-20 * static_cast<double>(faust_wrap_sub(1, iVec0[1])) - fRec11[1];
			double fTemp1 = static_cast<double>(input0[i0]) + fRec11[0];
			fVec1[0] = fTemp1;
			fRec10[0] = -(fSlow29 * (fSlow28 * fRec10[1] - (fTemp1 + fVec1[1])));
			fRec9[0] = fRec10[0] - fSlow27 * (fSlow25 * fRec9[2] + fSlow23 * fRec9[1]);
			double fTemp2 = fSlow27 * (fRec9[2] + fRec9[0] + 2.0 * fRec9[1]);
			fVec2[0] = fTemp2;
			fRec8[0] = -(fSlow32 * (fSlow30 * fRec8[1] - (fTemp2 + fVec2[1])));
			fRec7[0] = fRec8[0] - fSlow20 * (fSlow18 * fRec7[2] + fSlow16 * fRec7[1]);
			double fTemp3 = fSlow20 * (fRec7[2] + fRec7[0] + 2.0 * fRec7[1]);
			fVec3[0] = fTemp3;
			fRec6[0] = -(fSlow35 * (fSlow33 * fRec6[1] - (fTemp3 + fVec3[1])));
			fRec5[0] = fRec6[0] - fSlow13 * (fSlow11 * fRec5[2] + fSlow9 * fRec5[1]);
			double fTemp4 = fSlow13 * (fRec5[2] + fRec5[0] + 2.0 * fRec5[1]);
			fVec4[0] = fTemp4;
			fRec4[0] = -(fSlow38 * (fSlow36 * fRec4[1] - (fTemp4 + fVec4[1])));
			fRec3[0] = fRec4[0] - fSlow6 * (fSlow4 * fRec3[2] + fSlow2 * fRec3[1]);
			fRec12[0] = fSlow39 + 0.999 * fRec12[1];
			double fTemp5 = std::pow(1e+01, 2.0 * fRec12[0]);
			double fTemp6 = fSlow6 * fTemp5 * (fRec3[2] + fRec3[0] + 2.0 * fRec3[1]);
			double fTemp7 = std::fabs(fTemp6);
			double fTemp8 = 101.97 * (fTemp7 / (fTemp7 + 3.0) + -0.005);
			double fTemp9 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp8) | std::isinf(fTemp8)) ? 0.0 : fTemp8)));
			int iTemp10 = static_cast<int>(fTemp9);
			int iTemp11 = std::max<int>(0, std::min<int>(98, iTemp10));
			double fTemp12 = static_cast<double>(iTemp11);
			fRec13[0] = fSlow40 + 0.999 * fRec13[1];
			double fTemp13 = fRec13[0] * std::max<double>(1.0, 1.0 / fTemp5) * copysign(((iTemp10 < 0) ? fConst4 : ((iTemp10 >= 99) ? fConst3 : ftbl0GxMbclipperSIG0[iTemp11] * (fTemp12 + (1.0 - fTemp9)) + (fTemp9 - fTemp12) * ftbl0GxMbclipperSIG0[faust_wrap_add(iTemp11, 1)])), -fTemp6);
			double fTemp14 = std::max<double>(fConst1, std::fabs(fTemp13));
			fRec0[0] = ((iTemp0) ? fTemp14 + fRec0[1] : fTemp14);
			iRec1[0] = ((iTemp0) ? faust_wrap_add(iRec1[1], 1) : 1);
			fRec2[0] = ((iTemp0) ? fRec2[1] : 0.000244140625 * fRec0[1]);
			fVbargraph0 = static_cast<FAUSTFLOAT>(fRec2[0]);
			int iTemp15 = iRec15[1] < 4096;
			fRec18[0] = -(fSlow38 * (fSlow36 * fRec18[1] - fSlow3 * (fTemp4 - fVec4[1])));
			fRec17[0] = fRec18[0] - fSlow6 * (fSlow4 * fRec17[2] + fSlow2 * fRec17[1]);
			fRec19[0] = fSlow41 + 0.999 * fRec19[1];
			double fTemp16 = std::pow(1e+01, 2.0 * fRec19[0]);
			double fTemp17 = fSlow42 * fTemp16 * (fRec17[2] + (fRec17[0] - 2.0 * fRec17[1]));
			double fTemp18 = std::fabs(fTemp17);
			double fTemp19 = 101.97 * (fTemp18 / (fTemp18 + 3.0) + -0.005);
			double fTemp20 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp19) | std::isinf(fTemp19)) ? 0.0 : fTemp19)));
			int iTemp21 = static_cast<int>(fTemp20);
			int iTemp22 = std::max<int>(0, std::min<int>(98, iTemp21));
			double fTemp23 = static_cast<double>(iTemp22);
			fRec20[0] = fSlow43 + 0.999 * fRec20[1];
			double fTemp24 = fRec20[0] * std::max<double>(1.0, 1.0 / fTemp16) * copysign(((iTemp21 < 0) ? fConst4 : ((iTemp21 >= 99) ? fConst3 : ftbl0GxMbclipperSIG0[iTemp22] * (fTemp23 + (1.0 - fTemp20)) + (fTemp20 - fTemp23) * ftbl0GxMbclipperSIG0[faust_wrap_add(iTemp22, 1)])), -fTemp17);
			double fTemp25 = std::max<double>(fConst1, std::fabs(fTemp24));
			fRec14[0] = ((iTemp15) ? fTemp25 + fRec14[1] : fTemp25);
			iRec15[0] = ((iTemp15) ? faust_wrap_add(iRec15[1], 1) : 1);
			fRec16[0] = ((iTemp15) ? fRec16[1] : 0.000244140625 * fRec14[1]);
			fVbargraph1 = static_cast<FAUSTFLOAT>(fRec16[0]);
			int iTemp26 = iRec22[1] < 4096;
			double fTemp27 = fSlow2 * fRec24[1];
			fRec26[0] = -(fSlow35 * (fSlow33 * fRec26[1] - fSlow10 * (fTemp3 - fVec3[1])));
			fRec25[0] = fRec26[0] - fSlow13 * (fSlow11 * fRec25[2] + fSlow9 * fRec25[1]);
			fRec24[0] = fSlow46 * (fRec25[2] + (fRec25[0] - 2.0 * fRec25[1])) - fSlow45 * (fSlow44 * fRec24[2] + fTemp27);
			fRec27[0] = fSlow47 + 0.999 * fRec27[1];
			double fTemp28 = std::pow(1e+01, 2.0 * fRec27[0]);
			double fTemp29 = fTemp28 * (fRec24[2] + fSlow45 * (fTemp27 + fSlow44 * fRec24[0]));
			double fTemp30 = std::fabs(fTemp29);
			double fTemp31 = 101.97 * (fTemp30 / (fTemp30 + 3.0) + -0.005);
			double fTemp32 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp31) | std::isinf(fTemp31)) ? 0.0 : fTemp31)));
			int iTemp33 = static_cast<int>(fTemp32);
			int iTemp34 = std::max<int>(0, std::min<int>(98, iTemp33));
			double fTemp35 = static_cast<double>(iTemp34);
			fRec28[0] = fSlow48 + 0.999 * fRec28[1];
			double fTemp36 = fRec28[0] * std::max<double>(1.0, 1.0 / fTemp28) * copysign(((iTemp33 < 0) ? fConst4 : ((iTemp33 >= 99) ? fConst3 : ftbl0GxMbclipperSIG0[iTemp34] * (fTemp35 + (1.0 - fTemp32)) + (fTemp32 - fTemp35) * ftbl0GxMbclipperSIG0[faust_wrap_add(iTemp34, 1)])), -fTemp29);
			double fTemp37 = std::max<double>(fConst1, std::fabs(fTemp36));
			fRec21[0] = ((iTemp26) ? fTemp37 + fRec21[1] : fTemp37);
			iRec22[0] = ((iTemp26) ? faust_wrap_add(iRec22[1], 1) : 1);
			fRec23[0] = ((iTemp26) ? fRec23[1] : 0.000244140625 * fRec21[1]);
			fVbargraph2 = static_cast<FAUSTFLOAT>(fRec23[0]);
			int iTemp38 = iRec30[1] < 4096;
			double fTemp39 = fSlow2 * fRec32[1];
			double fTemp40 = fSlow9 * fRec33[1];
			fRec35[0] = -(fSlow32 * (fSlow30 * fRec35[1] - fSlow17 * (fTemp2 - fVec2[1])));
			fRec34[0] = fRec35[0] - fSlow20 * (fSlow18 * fRec34[2] + fSlow16 * fRec34[1]);
			fRec33[0] = fSlow51 * (fRec34[2] + (fRec34[0] - 2.0 * fRec34[1])) - fSlow50 * (fSlow49 * fRec33[2] + fTemp40);
			fRec32[0] = fRec33[2] + fSlow50 * (fTemp40 + fSlow49 * fRec33[0]) - fSlow45 * (fSlow44 * fRec32[2] + fTemp39);
			fRec36[0] = fSlow52 + 0.999 * fRec36[1];
			double fTemp41 = std::pow(1e+01, 2.0 * fRec36[0]);
			double fTemp42 = fTemp41 * (fRec32[2] + fSlow45 * (fTemp39 + fSlow44 * fRec32[0]));
			double fTemp43 = std::fabs(fTemp42);
			double fTemp44 = 101.97 * (fTemp43 / (fTemp43 + 3.0) + -0.005);
			double fTemp45 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp44) | std::isinf(fTemp44)) ? 0.0 : fTemp44)));
			int iTemp46 = static_cast<int>(fTemp45);
			int iTemp47 = std::max<int>(0, std::min<int>(98, iTemp46));
			double fTemp48 = static_cast<double>(iTemp47);
			fRec37[0] = fSlow53 + 0.999 * fRec37[1];
			double fTemp49 = fRec37[0] * std::max<double>(1.0, 1.0 / fTemp41) * copysign(((iTemp46 < 0) ? fConst4 : ((iTemp46 >= 99) ? fConst3 : ftbl0GxMbclipperSIG0[iTemp47] * (fTemp48 + (1.0 - fTemp45)) + (fTemp45 - fTemp48) * ftbl0GxMbclipperSIG0[faust_wrap_add(iTemp47, 1)])), -fTemp42);
			double fTemp50 = std::max<double>(fConst1, std::fabs(fTemp49));
			fRec29[0] = ((iTemp38) ? fTemp50 + fRec29[1] : fTemp50);
			iRec30[0] = ((iTemp38) ? faust_wrap_add(iRec30[1], 1) : 1);
			fRec31[0] = ((iTemp38) ? fRec31[1] : 0.000244140625 * fRec29[1]);
			fVbargraph3 = static_cast<FAUSTFLOAT>(fRec31[0]);
			int iTemp51 = iRec39[1] < 4096;
			double fTemp52 = fSlow2 * fRec41[1];
			double fTemp53 = fSlow9 * fRec42[1];
			double fTemp54 = fSlow16 * fRec43[1];
			fRec45[0] = -(fSlow29 * (fSlow28 * fRec45[1] - fSlow24 * (fTemp1 - fVec1[1])));
			fRec44[0] = fRec45[0] - fSlow27 * (fSlow25 * fRec44[2] + fSlow23 * fRec44[1]);
			fRec43[0] = fSlow56 * (fRec44[2] + (fRec44[0] - 2.0 * fRec44[1])) - fSlow55 * (fSlow54 * fRec43[2] + fTemp54);
			fRec42[0] = fRec43[2] + fSlow55 * (fTemp54 + fSlow54 * fRec43[0]) - fSlow50 * (fSlow49 * fRec42[2] + fTemp53);
			fRec41[0] = fRec42[2] + fSlow50 * (fTemp53 + fSlow49 * fRec42[0]) - fSlow45 * (fSlow44 * fRec41[2] + fTemp52);
			fRec46[0] = fSlow57 + 0.999 * fRec46[1];
			double fTemp55 = std::pow(1e+01, 2.0 * fRec46[0]);
			double fTemp56 = fTemp55 * (fRec41[2] + fSlow45 * (fTemp52 + fSlow44 * fRec41[0]));
			double fTemp57 = std::fabs(fTemp56);
			double fTemp58 = 101.97 * (fTemp57 / (fTemp57 + 3.0) + -0.005);
			double fTemp59 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp58) | std::isinf(fTemp58)) ? 0.0 : fTemp58)));
			int iTemp60 = static_cast<int>(fTemp59);
			int iTemp61 = std::max<int>(0, std::min<int>(98, iTemp60));
			double fTemp62 = static_cast<double>(iTemp61);
			fRec47[0] = fSlow58 + 0.999 * fRec47[1];
			double fTemp63 = fRec47[0] * std::max<double>(1.0, 1.0 / fTemp55) * copysign(((iTemp60 < 0) ? fConst4 : ((iTemp60 >= 99) ? fConst3 : ftbl0GxMbclipperSIG0[iTemp61] * (fTemp62 + (1.0 - fTemp59)) + (fTemp59 - fTemp62) * ftbl0GxMbclipperSIG0[faust_wrap_add(iTemp61, 1)])), -fTemp56);
			double fTemp64 = std::max<double>(fConst1, std::fabs(fTemp63));
			fRec38[0] = ((iTemp51) ? fTemp64 + fRec38[1] : fTemp64);
			iRec39[0] = ((iTemp51) ? faust_wrap_add(iRec39[1], 1) : 1);
			fRec40[0] = ((iTemp51) ? fRec40[1] : 0.000244140625 * fRec38[1]);
			fVbargraph4 = static_cast<FAUSTFLOAT>(fRec40[0]);
			fRec48[0] = fSlow59 + 0.999 * fRec48[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fRec48[0] * (fTemp63 + fTemp49 + fTemp36 + fTemp24 + fTemp13));
			iVec0[1] = iVec0[0];
			fRec11[1] = fRec11[0];
			fVec1[1] = fVec1[0];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fVec2[1] = fVec2[0];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fVec3[1] = fVec3[0];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fVec4[1] = fVec4[0];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec0[1] = fRec0[0];
			iRec1[1] = iRec1[0];
			fRec2[1] = fRec2[0];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
			fRec14[1] = fRec14[0];
			iRec15[1] = iRec15[0];
			fRec16[1] = fRec16[0];
			fRec26[1] = fRec26[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec21[1] = fRec21[0];
			iRec22[1] = iRec22[0];
			fRec23[1] = fRec23[0];
			fRec35[1] = fRec35[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec29[1] = fRec29[0];
			iRec30[1] = iRec30[0];
			fRec31[1] = fRec31[0];
			fRec45[1] = fRec45[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec46[1] = fRec46[0];
			fRec47[1] = fRec47[0];
			fRec38[1] = fRec38[0];
			iRec39[1] = iRec39[0];
			fRec40[1] = fRec40[0];
			fRec48[1] = fRec48[0];
		}
	}

};

#endif
