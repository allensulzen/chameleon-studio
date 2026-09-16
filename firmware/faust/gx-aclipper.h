/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Rat"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxAclipper -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxAclipper_H__
#define  __GxAclipper_H__

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
#define FAUSTCLASS GxAclipper
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

const static double fGxAclipperSIG0Wave0[100] = {0.0,-0.0297094517538,-0.0600106764386,-0.0909157810379,-0.122426702394,-0.154512792375,-0.187043325084,-0.219597292059,-0.251049236888,-0.279269262629,-0.302229948146,-0.319764727359,-0.333093000826,-0.343502317962,-0.351909526762,-0.358908857328,-0.36488466473,-0.370092137015,-0.374706320512,-0.378851176595,-0.382617067841,-0.386071573306,-0.389266381829,-0.392241815715,-0.395029880998,-0.397656375663,-0.400142379724,-0.402505329872,-0.40475980878,-0.40691813447,-0.40899080703,-0.410986851861,-0.412914086728,-0.41477933192,-0.416588577398,-0.418347117027,-0.420059657378,-0.421730406641,-0.423363147893,-0.42496129992,-0.426527968065,-0.428065987051,-0.429577957267,-0.431066275734,-0.432533162692,-0.433980684588,-0.435410774074,-0.436825247529,-0.438225820518,-0.439614121545,-0.440991704367,-0.442360059136,-0.443720622562,-0.445074787283,-0.446423910594,-0.447769322678,-0.449112334467,-0.450454245238,-0.451796350073,-0.45313994727,-0.454486345819,-0.455836873054,-0.457192882585,-0.458555762643,-0.459926944953,-0.461307914299,-0.462700218942,-0.464105482085,-0.465525414618,-0.466961829402,-0.468416657431,-0.469891966247,-0.471389981094,-0.472913109397,-0.474463969287,-0.47604542308,-0.477660616872,-0.479313027692,-0.481006520102,-0.482745414666,-0.484534571498,-0.4863794931,-0.488286452181,-0.49026265218,-0.492316431132,-0.494457523819,-0.496697403477,-0.499049733989,-0.501530978499,-0.504161234316,-0.506965403328,-0.509974874057,-0.513230009815,-0.516783956265,-0.520708708794,-0.525105268876,-0.530121719205,-0.535988020132,-0.543090399279,-0.552155806647};
class GxAclipperSIG0 {
	
  private:
	
	int fGxAclipperSIG0Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxAclipperSIG0() {
		return 0;
	}
	int getNumOutputsGxAclipperSIG0() {
		return 1;
	}
	
	void instanceInitGxAclipperSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		fGxAclipperSIG0Wave0_idx = 0;
	}
	
	void fillGxAclipperSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			table[i1] = fGxAclipperSIG0Wave0[fGxAclipperSIG0Wave0_idx];
			fGxAclipperSIG0Wave0_idx = (faust_wrap_add(1, fGxAclipperSIG0Wave0_idx)) % 100;
		}
	}

};

static GxAclipperSIG0* newGxAclipperSIG0() { return (GxAclipperSIG0*)new GxAclipperSIG0(); }
static void deleteGxAclipperSIG0(GxAclipperSIG0* dsp) { delete dsp; }

const static double fGxAclipperSIG1Wave0[100] = {0.00603015075336,0.01809045226,0.0301507537665,0.0422110552725,0.054271356778,0.0663316582824,0.0783919597854,0.0904522612862,0.102512562784,0.114572864276,0.126633165761,0.138693467235,0.150753768692,0.162814070124,0.174874371519,0.186934672858,0.198994974114,0.211055275246,0.223115576191,0.235175876859,0.24723617711,0.259296476741,0.271356775442,0.283417072754,0.295477367991,0.307537660124,0.319597947619,0.33165822818,0.343718498377,0.35577875308,0.367838984624,0.379899181548,0.391959326723,0.404019394543,0.416079346735,0.428139126093,0.44019864711,0.452257781997,0.464316339777,0.476374035093,0.488430441641,0.500484922745,0.512536527968,0.52458383943,0.536624744012,0.548656097127,0.560673229563,0.572669231058,0.584633924534,0.596552429766,0.608403220677,0.620155639626,0.63176700187,0.643179775928,0.654319889611,0.665097826872,0.675414318824,0.685171302576,0.694286194217,0.702704815041,0.71040803695,0.717410208734,0.723751367845,0.729487174377,0.734679852345,0.739391662215,0.74368098868,0.747600451592,0.751196334507,0.754508761438,0.757572238239,0.760416328696,0.763066340394,0.765543959883,0.767867813202,0.77005394711,0.772116235666,0.774066720635,0.775915895143,0.777672939604,0.779345917964,0.780941941157,0.782467303561,0.783927597227,0.78532780782,0.786672395464,0.787965363123,0.789210314642,0.790410504198,0.791568878578,0.792688113463,0.793770644671,0.794818695151,0.795834298389,0.796819318764,0.797775469305,0.798704327239,0.799607347627,0.800485875375,0.801341155829};
class GxAclipperSIG1 {
	
  private:
	
	int fGxAclipperSIG1Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxAclipperSIG1() {
		return 0;
	}
	int getNumOutputsGxAclipperSIG1() {
		return 1;
	}
	
	void instanceInitGxAclipperSIG1(int sample_rate) {
		fSampleRate = sample_rate;
		fGxAclipperSIG1Wave0_idx = 0;
	}
	
	void fillGxAclipperSIG1(int count, double* table) {
		for (int i2 = 0; i2 < count; i2 = faust_wrap_add(i2, 1)) {
			table[i2] = fGxAclipperSIG1Wave0[fGxAclipperSIG1Wave0_idx];
			fGxAclipperSIG1Wave0_idx = (faust_wrap_add(1, fGxAclipperSIG1Wave0_idx)) % 100;
		}
	}

};

static GxAclipperSIG1* newGxAclipperSIG1() { return (GxAclipperSIG1*)new GxAclipperSIG1(); }
static void deleteGxAclipperSIG1(GxAclipperSIG1* dsp) { delete dsp; }

const static double fGxAclipperSIG2Wave0[100] = {0.00603015075328,0.0180904522597,0.0301507537658,0.0422110552712,0.0542713567753,0.0663316582773,0.078391959776,0.0904522612693,0.102512562754,0.114572864224,0.126633165671,0.13869346708,0.150753768428,0.162814069678,0.174874370768,0.186934671599,0.198994972011,0.211055271743,0.223115570375,0.235175867223,0.247236161183,0.259296450464,0.271356732165,0.283417001586,0.295477251114,0.307537468417,0.319597633515,0.331657714047,0.343717657587,0.355777379216,0.367836741391,0.379895521352,0.391953358382,0.404009668522,0.416063506807,0.428113345128,0.440156715064,0.452189636343,0.464205709192,0.476194690918,0.488140309251,0.500017017012,0.511785451024,0.523386716927,0.534736595687,0.545722570336,0.556208530181,0.56605156534,0.575129292087,0.583366759758,0.5907490069,0.597314431205,0.603136232325,0.608302762065,0.6129031933,0.617019547246,0.620723468998,0.624075776976,0.627127339389,0.629920429937,0.632490135982,0.634865635819,0.637071286256,0.639127519071,0.641051567552,0.642858050645,0.644559441301,0.646166442152,0.647688287613,0.649132987724,0.65050752585,0.651818019782,0.653069853672,0.654267786673,0.655416042855,0.656518386013,0.657578182216,0.658598452376,0.659581916616,0.660531031912,0.661448024156,0.662334915578,0.66319354831,0.664025604701,0.664832624893,0.665616022099,0.666377095908,0.667117043929,0.667836971995,0.668537903148,0.669220785565,0.669886499569,0.670535863855,0.671169641018,0.671788542494,0.672393232966,0.67298433432,0.673562429184,0.674128064128,0.674681752538};
class GxAclipperSIG2 {
	
  private:
	
	int fGxAclipperSIG2Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxAclipperSIG2() {
		return 0;
	}
	int getNumOutputsGxAclipperSIG2() {
		return 1;
	}
	
	void instanceInitGxAclipperSIG2(int sample_rate) {
		fSampleRate = sample_rate;
		fGxAclipperSIG2Wave0_idx = 0;
	}
	
	void fillGxAclipperSIG2(int count, double* table) {
		for (int i3 = 0; i3 < count; i3 = faust_wrap_add(i3, 1)) {
			table[i3] = fGxAclipperSIG2Wave0[fGxAclipperSIG2Wave0_idx];
			fGxAclipperSIG2Wave0_idx = (faust_wrap_add(1, fGxAclipperSIG2Wave0_idx)) % 100;
		}
	}

};

static GxAclipperSIG2* newGxAclipperSIG2() { return (GxAclipperSIG2*)new GxAclipperSIG2(); }
static void deleteGxAclipperSIG2(GxAclipperSIG2* dsp) { delete dsp; }

static double GxAclipper_faustpower2_f(double value) {
	return value * value;
}
static double DSY_SDRAM_BSS ftbl0GxAclipperSIG0[100];
static double DSY_SDRAM_BSS ftbl1GxAclipperSIG1[100];
static double DSY_SDRAM_BSS ftbl2GxAclipperSIG2[100];

class GxAclipper : public chdsp {
	
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
	double fRec4[3];
	double fConst15;
	double fVec0[2];
	FAUSTFLOAT fHslider0;
	double fRec6[2];
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fRec5[2];
	double fConst20;
	double fConst21;
	double fRec3[2];
	double fConst22;
	double fRec2[3];
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fRec1[2];
	FAUSTFLOAT fHslider1;
	double fRec7[2];
	
 public:
	GxAclipper() {
	}
	
	GxAclipper(const GxAclipper&) = default;
	
	virtual ~GxAclipper() = default;
	
	GxAclipper& operator=(const GxAclipper&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Distortion");
		m->declare("chameleon_flags", "-double");
		m->declare("clipping.lib/license", "GPL-2.0-or-later");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxAclipper -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-aclipper.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("gx_tables.lib/license", "GPL-2.0-or-later");
		m->declare("id", "aclipper");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Rat");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("samplerate", "96000");
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
		GxAclipperSIG0* sig0 = newGxAclipperSIG0();
		sig0->instanceInitGxAclipperSIG0(sample_rate);
		sig0->fillGxAclipperSIG0(100, ftbl0GxAclipperSIG0);
		GxAclipperSIG1* sig1 = newGxAclipperSIG1();
		sig1->instanceInitGxAclipperSIG1(sample_rate);
		sig1->fillGxAclipperSIG1(100, ftbl1GxAclipperSIG1);
		GxAclipperSIG2* sig2 = newGxAclipperSIG2();
		sig2->instanceInitGxAclipperSIG2(sample_rate);
		sig2->fillGxAclipperSIG2(100, ftbl2GxAclipperSIG2);
		deleteGxAclipperSIG0(sig0);
		deleteGxAclipperSIG1(sig1);
		deleteGxAclipperSIG2(sig2);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 3.91923990498812e-05 * fConst0;
		fConst2 = 4.3384046341364e-10 * fConst0;
		fConst3 = fConst0 * (fConst2 + -8.99037897457717e-09) + 3.41041934946762e-08;
		fConst4 = GxAclipper_faustpower2_f(fConst0);
		fConst5 = 6.82083869893523e-08 - 8.6768092682728e-10 * fConst4;
		fConst6 = fConst0 * (fConst2 + 8.99037897457717e-09) + 3.41041934946762e-08;
		fConst7 = 1.0 / fConst6;
		fConst8 = 2.08332871602678e-05 * fConst0;
		fConst9 = fConst8 + 2.21630714470934e-06;
		fConst10 = (2.21630714470934e-06 - fConst8) / fConst9;
		fConst11 = 3.64865447573811e-11 * fConst0;
		fConst12 = fConst0 * (fConst11 + -1.9073341271921e-05) + 0.000414619826788421;
		fConst13 = 0.000829239653576842 - 7.29730895147621e-11 * fConst4;
		fConst14 = 1.0 / (fConst0 * (fConst11 + 1.9073341271921e-05) + 0.000414619826788421);
		fConst15 = 1.82432723786905e-05 * fConst0;
		fConst16 = 9.4e-08 * fConst0;
		fConst17 = 0.00044179999999999995 * fConst0;
		fConst18 = 1.0 - fConst17;
		fConst19 = 1.0 / (fConst17 + 1.0);
		fConst20 = ftbl0GxAclipperSIG0[99];
		fConst21 = ftbl0GxAclipperSIG0[0];
		fConst22 = 2.08332871602678e-05 * (fConst0 / fConst9);
		fConst23 = fConst4 / fConst6;
		fConst24 = ftbl1GxAclipperSIG1[99];
		fConst25 = ftbl1GxAclipperSIG1[0];
		fConst26 = ftbl2GxAclipperSIG2[99];
		fConst27 = ftbl2GxAclipperSIG2[0];
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fHslider0 = static_cast<FAUSTFLOAT>(0.5);
		fHslider1 = static_cast<FAUSTFLOAT>(-2.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 3; l1 = faust_wrap_add(l1, 1)) {
			fRec4[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec6[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec5[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec3[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec2[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec1[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec7[l8] = 0.0;
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
	
	virtual GxAclipper* clone() {
		return new GxAclipper(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Rat");
		ui_interface->declare(&fHslider0, "name", "Drive");
		ui_interface->addHorizontalSlider("drive", &fHslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider1, "name", "Level");
		ui_interface->addHorizontalSlider("level", &fHslider1, FAUSTFLOAT(-2.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(12.0), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider0, "name", "Tone");
		ui_interface->addVerticalSlider("tone", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * (1.0 - static_cast<double>(fVslider0));
		double fSlow1 = 0.007000000000000006 * static_cast<double>(fHslider0);
		double fSlow2 = 0.007000000000000006 * std::pow(1e+01, 0.05 * static_cast<double>(fHslider1));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			double fTemp0 = fConst1 * (1.0 - fRec0[0]);
			double fTemp1 = fTemp0 + 0.0593824228028504;
			fRec4[0] = static_cast<double>(input0[i0]) - fConst14 * (fConst13 * fRec4[1] + fConst12 * fRec4[2]);
			double fTemp2 = 0.000829239653576842 * fRec4[1] + fConst15 * fRec4[0] - fConst15 * fRec4[2];
			fVec0[0] = fTemp2;
			double fTemp3 = fConst14 * fTemp2;
			fRec6[0] = fSlow1 + 0.993 * fRec6[1];
			double fTemp4 = fConst16 * (5e+05 * fRec6[0] + 5.7e+03);
			fRec5[0] = -(fConst19 * (fConst18 * fRec5[1] - fConst14 * (fTemp2 * (fTemp4 + 1.0) + fVec0[1] * (1.0 - fTemp4))));
			double fTemp5 = std::fabs(fRec5[0] - fTemp3);
			double fTemp6 = 101.97 * (fTemp5 / (fTemp5 + 3.0));
			double fTemp7 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp6) | std::isinf(fTemp6)) ? 0.0 : fTemp6)));
			int iTemp8 = static_cast<int>(fTemp7);
			int iTemp9 = std::max<int>(0, std::min<int>(98, iTemp8));
			double fTemp10 = static_cast<double>(iTemp9);
			fRec3[0] = fTemp3 - (copysign(((iTemp8 < 0) ? fConst21 : ((iTemp8 >= 99) ? fConst20 : ftbl0GxAclipperSIG0[iTemp9] * (fTemp10 + (1.0 - fTemp7)) + (fTemp7 - fTemp10) * ftbl0GxAclipperSIG0[faust_wrap_add(iTemp9, 1)])), fTemp3 - fRec5[0]) + fConst10 * fRec3[1]);
			fRec2[0] = fConst22 * (fRec3[0] - fRec3[1]) - fConst7 * (fConst5 * fRec2[1] + fConst3 * fRec2[2]);
			double fTemp11 = fConst23 * (0.75 * fRec6[0] + 0.5) * (1.85360131346578e-09 * fRec2[1] - 9.26800656732889e-10 * fRec2[0] - 9.26800656732889e-10 * fRec2[2]);
			double fTemp12 = 101.97 * (std::fabs(fTemp11) + -0.006);
			double fTemp13 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp12) | std::isinf(fTemp12)) ? 0.0 : fTemp12)));
			int iTemp14 = static_cast<int>(fTemp13);
			int iTemp15 = iTemp14 < 0;
			int iTemp16 = iTemp14 >= 99;
			int iTemp17 = std::max<int>(0, std::min<int>(98, iTemp14));
			int iTemp18 = faust_wrap_add(iTemp17, 1);
			double fTemp19 = static_cast<double>(iTemp17);
			double fTemp20 = fTemp13 - fTemp19;
			double fTemp21 = fTemp19 + (1.0 - fTemp13);
			fRec1[0] = copysign(((fTemp11 < 0.0) ? ((iTemp15) ? fConst27 : ((iTemp16) ? fConst26 : fTemp21 * ftbl2GxAclipperSIG2[iTemp17] + fTemp20 * ftbl2GxAclipperSIG2[iTemp18])) : ((iTemp15) ? fConst25 : ((iTemp16) ? fConst24 : ftbl1GxAclipperSIG1[iTemp17] * fTemp21 + fTemp20 * ftbl1GxAclipperSIG1[iTemp18]))), fTemp11) - fRec1[1] * (0.0593824228028504 - fTemp0) / fTemp1;
			fRec7[0] = fSlow2 + 0.993 * fRec7[1];
			output0[i0] = static_cast<FAUSTFLOAT>(0.0593824228028504 * (fRec7[0] * (fRec1[0] + fRec1[1]) / fTemp1));
			fRec0[1] = fRec0[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fVec0[1] = fVec0[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec7[1] = fRec7[0];
		}
	}

};

#endif
