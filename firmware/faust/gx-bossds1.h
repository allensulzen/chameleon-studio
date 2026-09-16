/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Boss DS1"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBossds1 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxBossds1_H__
#define  __GxBossds1_H__

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
#define FAUSTCLASS GxBossds1
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

const static double fGxBossds1SIG0Wave0[100] = {0.00548195523036,0.016445865691,0.0274097761516,0.0383736866119,0.0493375970718,0.060301507531,0.0712654179894,0.0822293284464,0.0931932389016,0.104157149354,0.115121059803,0.126084970245,0.13704888068,0.148012791103,0.158976701508,0.169940611889,0.180904522235,0.19186843253,0.202832342751,0.213796252866,0.224760162828,0.23572407257,0.246687981995,0.257651890962,0.26861579927,0.279579706628,0.290543612617,0.301507516632,0.312471417804,0.323435314878,0.334399206045,0.3453630887,0.356326959087,0.367290811794,0.378254639021,0.389218429528,0.400182167115,0.411145828437,0.422109379849,0.433072772871,0.444035937638,0.454998773485,0.465961135365,0.476922814321,0.48788350936,0.498842787024,0.509800023297,0.520754320256,0.531704386732,0.542648367922,0.55358360312,0.564506283341,0.575410971703,0.586289940184,0.597132269761,0.607922663898,0.618639951041,0.629255322196,0.639730493837,0.650016225239,0.660051925492,0.669767316942,0.679086989359,0.687937882416,0.696258343947,0.704006183628,0.711163121782,0.717734492237,0.723745022743,0.72923269117,0.734242606851,0.738822090117,0.743017303269,0.74687127245,0.750422944114,0.7537069184,0.756753578753,0.759589425229,0.762237491115,0.764717773458,0.767047640962,0.769242202516,0.771314630963,0.773276442704,0.775137736666,0.776907397287,0.778593266396,0.780202288563,0.781740634041,0.783213802858,0.784626713121,0.785983776084,0.787288960129,0.788545845459,0.789757670968,0.790927374556,0.792057627879,0.793150866414,0.794209315546,0.795235013262};
class GxBossds1SIG0 {
	
  private:
	
	int fGxBossds1SIG0Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxBossds1SIG0() {
		return 0;
	}
	int getNumOutputsGxBossds1SIG0() {
		return 1;
	}
	
	void instanceInitGxBossds1SIG0(int sample_rate) {
		fSampleRate = sample_rate;
		fGxBossds1SIG0Wave0_idx = 0;
	}
	
	void fillGxBossds1SIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			table[i1] = fGxBossds1SIG0Wave0[fGxBossds1SIG0Wave0_idx];
			fGxBossds1SIG0Wave0_idx = (faust_wrap_add(1, fGxBossds1SIG0Wave0_idx)) % 100;
		}
	}

};

static GxBossds1SIG0* newGxBossds1SIG0() { return (GxBossds1SIG0*)new GxBossds1SIG0(); }
static void deleteGxBossds1SIG0(GxBossds1SIG0* dsp) { delete dsp; }

const static double fGxBossds1SIG1Wave0[100] = {0.00548195523031,0.0164458656909,0.0274097761512,0.0383736866111,0.0493375970704,0.0603015075285,0.0712654179851,0.082229328439,0.0931932388892,0.104157149333,0.115121059769,0.12608497019,0.137048880591,0.148012790959,0.158976701279,0.169940611525,0.180904521657,0.191868431617,0.202832341314,0.213796250611,0.224760159295,0.235724067049,0.246687973381,0.257651877548,0.268615778413,0.279579674245,0.290543562402,0.301507438861,0.312471297484,0.323435128917,0.334398918898,0.345362645685,0.356326276133,0.367289759716,0.378253019414,0.389215937827,0.400178336023,0.411139941321,0.42210033827,0.433058894088,0.444014645453,0.454966126935,0.465911111815,0.476846222439,0.48776634877,0.498663790599,0.509527014355,0.520338900962,0.531074384332,0.541697496972,0.552158139124,0.56238945844,0.572307512987,0.581815428003,0.590813561352,0.599214490989,0.606958012304,0.614019992825,0.620411898645,0.626172769665,0.631358240814,0.636030621745,0.640251880792,0.644079593827,0.647565120396,0.650753173457,0.653682139425,0.656384734578,0.658888761937,0.661217848132,0.663392107065,0.665428713341,0.667342386264,0.669145793013,0.670849882133,0.672464158558,0.673996910275,0.675455395374,0.676845996735,0.678174350352,0.679445452148,0.680663747232,0.681833204767,0.682957381028,0.68403947273,0.685082362296,0.686088656441,0.687060719194,0.688000700243,0.68891055938,0.689792087638,0.690646925637,0.691476579559,0.692282435105,0.693065769722,0.693827763348,0.694569507883,0.695292015556,0.695996226341,0.696683014544};
class GxBossds1SIG1 {
	
  private:
	
	int fGxBossds1SIG1Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxBossds1SIG1() {
		return 0;
	}
	int getNumOutputsGxBossds1SIG1() {
		return 1;
	}
	
	void instanceInitGxBossds1SIG1(int sample_rate) {
		fSampleRate = sample_rate;
		fGxBossds1SIG1Wave0_idx = 0;
	}
	
	void fillGxBossds1SIG1(int count, double* table) {
		for (int i2 = 0; i2 < count; i2 = faust_wrap_add(i2, 1)) {
			table[i2] = fGxBossds1SIG1Wave0[fGxBossds1SIG1Wave0_idx];
			fGxBossds1SIG1Wave0_idx = (faust_wrap_add(1, fGxBossds1SIG1Wave0_idx)) % 100;
		}
	}

};

static GxBossds1SIG1* newGxBossds1SIG1() { return (GxBossds1SIG1*)new GxBossds1SIG1(); }
static void deleteGxBossds1SIG1(GxBossds1SIG1* dsp) { delete dsp; }

const static double fGxBossds1SIG2Wave0[100] = {0.0,-0.0297094517538,-0.0600106764386,-0.0909157810379,-0.122426702394,-0.154512792375,-0.187043325084,-0.219597292059,-0.251049236888,-0.279269262629,-0.302229948146,-0.319764727359,-0.333093000826,-0.343502317962,-0.351909526762,-0.358908857328,-0.36488466473,-0.370092137015,-0.374706320512,-0.378851176595,-0.382617067841,-0.386071573306,-0.389266381829,-0.392241815715,-0.395029880998,-0.397656375663,-0.400142379724,-0.402505329872,-0.40475980878,-0.40691813447,-0.40899080703,-0.410986851861,-0.412914086728,-0.41477933192,-0.416588577398,-0.418347117027,-0.420059657378,-0.421730406641,-0.423363147893,-0.42496129992,-0.426527968065,-0.428065987051,-0.429577957267,-0.431066275734,-0.432533162692,-0.433980684588,-0.435410774074,-0.436825247529,-0.438225820518,-0.439614121545,-0.440991704367,-0.442360059136,-0.443720622562,-0.445074787283,-0.446423910594,-0.447769322678,-0.449112334467,-0.450454245238,-0.451796350073,-0.45313994727,-0.454486345819,-0.455836873054,-0.457192882585,-0.458555762643,-0.459926944953,-0.461307914299,-0.462700218942,-0.464105482085,-0.465525414618,-0.466961829402,-0.468416657431,-0.469891966247,-0.471389981094,-0.472913109397,-0.474463969287,-0.47604542308,-0.477660616872,-0.479313027692,-0.481006520102,-0.482745414666,-0.484534571498,-0.4863794931,-0.488286452181,-0.49026265218,-0.492316431132,-0.494457523819,-0.496697403477,-0.499049733989,-0.501530978499,-0.504161234316,-0.506965403328,-0.509974874057,-0.513230009815,-0.516783956265,-0.520708708794,-0.525105268876,-0.530121719205,-0.535988020132,-0.543090399279,-0.552155806647};
class GxBossds1SIG2 {
	
  private:
	
	int fGxBossds1SIG2Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxBossds1SIG2() {
		return 0;
	}
	int getNumOutputsGxBossds1SIG2() {
		return 1;
	}
	
	void instanceInitGxBossds1SIG2(int sample_rate) {
		fSampleRate = sample_rate;
		fGxBossds1SIG2Wave0_idx = 0;
	}
	
	void fillGxBossds1SIG2(int count, double* table) {
		for (int i3 = 0; i3 < count; i3 = faust_wrap_add(i3, 1)) {
			table[i3] = fGxBossds1SIG2Wave0[fGxBossds1SIG2Wave0_idx];
			fGxBossds1SIG2Wave0_idx = (faust_wrap_add(1, fGxBossds1SIG2Wave0_idx)) % 100;
		}
	}

};

static GxBossds1SIG2* newGxBossds1SIG2() { return (GxBossds1SIG2*)new GxBossds1SIG2(); }
static void deleteGxBossds1SIG2(GxBossds1SIG2* dsp) { delete dsp; }

const static double fGxBossds1SIG3Wave0[100] = {0.00603015075336,0.01809045226,0.0301507537665,0.0422110552725,0.054271356778,0.0663316582824,0.0783919597854,0.0904522612862,0.102512562784,0.114572864276,0.126633165761,0.138693467235,0.150753768692,0.162814070124,0.174874371519,0.186934672858,0.198994974114,0.211055275246,0.223115576191,0.235175876859,0.24723617711,0.259296476741,0.271356775442,0.283417072754,0.295477367991,0.307537660124,0.319597947619,0.33165822818,0.343718498377,0.35577875308,0.367838984624,0.379899181548,0.391959326723,0.404019394543,0.416079346735,0.428139126093,0.44019864711,0.452257781997,0.464316339777,0.476374035093,0.488430441641,0.500484922745,0.512536527968,0.52458383943,0.536624744012,0.548656097127,0.560673229563,0.572669231058,0.584633924534,0.596552429766,0.608403220677,0.620155639626,0.63176700187,0.643179775928,0.654319889611,0.665097826872,0.675414318824,0.685171302576,0.694286194217,0.702704815041,0.71040803695,0.717410208734,0.723751367845,0.729487174377,0.734679852345,0.739391662215,0.74368098868,0.747600451592,0.751196334507,0.754508761438,0.757572238239,0.760416328696,0.763066340394,0.765543959883,0.767867813202,0.77005394711,0.772116235666,0.774066720635,0.775915895143,0.777672939604,0.779345917964,0.780941941157,0.782467303561,0.783927597227,0.78532780782,0.786672395464,0.787965363123,0.789210314642,0.790410504198,0.791568878578,0.792688113463,0.793770644671,0.794818695151,0.795834298389,0.796819318764,0.797775469305,0.798704327239,0.799607347627,0.800485875375,0.801341155829};
class GxBossds1SIG3 {
	
  private:
	
	int fGxBossds1SIG3Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxBossds1SIG3() {
		return 0;
	}
	int getNumOutputsGxBossds1SIG3() {
		return 1;
	}
	
	void instanceInitGxBossds1SIG3(int sample_rate) {
		fSampleRate = sample_rate;
		fGxBossds1SIG3Wave0_idx = 0;
	}
	
	void fillGxBossds1SIG3(int count, double* table) {
		for (int i4 = 0; i4 < count; i4 = faust_wrap_add(i4, 1)) {
			table[i4] = fGxBossds1SIG3Wave0[fGxBossds1SIG3Wave0_idx];
			fGxBossds1SIG3Wave0_idx = (faust_wrap_add(1, fGxBossds1SIG3Wave0_idx)) % 100;
		}
	}

};

static GxBossds1SIG3* newGxBossds1SIG3() { return (GxBossds1SIG3*)new GxBossds1SIG3(); }
static void deleteGxBossds1SIG3(GxBossds1SIG3* dsp) { delete dsp; }

const static double fGxBossds1SIG4Wave0[100] = {0.00603015075328,0.0180904522597,0.0301507537658,0.0422110552712,0.0542713567753,0.0663316582773,0.078391959776,0.0904522612693,0.102512562754,0.114572864224,0.126633165671,0.13869346708,0.150753768428,0.162814069678,0.174874370768,0.186934671599,0.198994972011,0.211055271743,0.223115570375,0.235175867223,0.247236161183,0.259296450464,0.271356732165,0.283417001586,0.295477251114,0.307537468417,0.319597633515,0.331657714047,0.343717657587,0.355777379216,0.367836741391,0.379895521352,0.391953358382,0.404009668522,0.416063506807,0.428113345128,0.440156715064,0.452189636343,0.464205709192,0.476194690918,0.488140309251,0.500017017012,0.511785451024,0.523386716927,0.534736595687,0.545722570336,0.556208530181,0.56605156534,0.575129292087,0.583366759758,0.5907490069,0.597314431205,0.603136232325,0.608302762065,0.6129031933,0.617019547246,0.620723468998,0.624075776976,0.627127339389,0.629920429937,0.632490135982,0.634865635819,0.637071286256,0.639127519071,0.641051567552,0.642858050645,0.644559441301,0.646166442152,0.647688287613,0.649132987724,0.65050752585,0.651818019782,0.653069853672,0.654267786673,0.655416042855,0.656518386013,0.657578182216,0.658598452376,0.659581916616,0.660531031912,0.661448024156,0.662334915578,0.66319354831,0.664025604701,0.664832624893,0.665616022099,0.666377095908,0.667117043929,0.667836971995,0.668537903148,0.669220785565,0.669886499569,0.670535863855,0.671169641018,0.671788542494,0.672393232966,0.67298433432,0.673562429184,0.674128064128,0.674681752538};
class GxBossds1SIG4 {
	
  private:
	
	int fGxBossds1SIG4Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxBossds1SIG4() {
		return 0;
	}
	int getNumOutputsGxBossds1SIG4() {
		return 1;
	}
	
	void instanceInitGxBossds1SIG4(int sample_rate) {
		fSampleRate = sample_rate;
		fGxBossds1SIG4Wave0_idx = 0;
	}
	
	void fillGxBossds1SIG4(int count, double* table) {
		for (int i5 = 0; i5 < count; i5 = faust_wrap_add(i5, 1)) {
			table[i5] = fGxBossds1SIG4Wave0[fGxBossds1SIG4Wave0_idx];
			fGxBossds1SIG4Wave0_idx = (faust_wrap_add(1, fGxBossds1SIG4Wave0_idx)) % 100;
		}
	}

};

static GxBossds1SIG4* newGxBossds1SIG4() { return (GxBossds1SIG4*)new GxBossds1SIG4(); }
static void deleteGxBossds1SIG4(GxBossds1SIG4* dsp) { delete dsp; }

static double GxBossds1_faustpower2_f(double value) {
	return value * value;
}
static double DSY_SDRAM_BSS ftbl0GxBossds1SIG0[100];
static double DSY_SDRAM_BSS ftbl1GxBossds1SIG1[100];
static double DSY_SDRAM_BSS ftbl2GxBossds1SIG2[100];
static double DSY_SDRAM_BSS ftbl3GxBossds1SIG3[100];
static double DSY_SDRAM_BSS ftbl4GxBossds1SIG4[100];

class GxBossds1 : public chdsp {
	
 private:
	
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	FAUSTFLOAT fVslider0;
	double fRec1[2];
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
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	FAUSTFLOAT fHslider0;
	double fRec5[2];
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fRec8[2];
	double fConst52;
	double fRec7[4];
	double fConst53;
	double fRec6[3];
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fConst58;
	double fConst59;
	double fRec4[3];
	double fConst60;
	double fConst61;
	double fConst62;
	double fConst63;
	double fVec0[2];
	double fRec9[2];
	double fRec3[3];
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fRec2[3];
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	double fRec0[3];
	FAUSTFLOAT fHslider1;
	double fRec10[2];
	double fConst72;
	
 public:
	GxBossds1() {
	}
	
	GxBossds1(const GxBossds1&) = default;
	
	virtual ~GxBossds1() = default;
	
	GxBossds1& operator=(const GxBossds1&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Distortion");
		m->declare("chameleon_flags", "-double");
		m->declare("clipping.lib/license", "GPL-2.0-or-later");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBossds1 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Boss DS1");
		m->declare("filename", "gx-bossds1.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
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
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("gx_tables.lib/license", "GPL-2.0-or-later");
		m->declare("id", "bossds1");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Boss DS1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("samplerate", "96000");
		m->declare("shortname", "DS1");
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
		GxBossds1SIG0* sig0 = newGxBossds1SIG0();
		sig0->instanceInitGxBossds1SIG0(sample_rate);
		sig0->fillGxBossds1SIG0(100, ftbl0GxBossds1SIG0);
		GxBossds1SIG1* sig1 = newGxBossds1SIG1();
		sig1->instanceInitGxBossds1SIG1(sample_rate);
		sig1->fillGxBossds1SIG1(100, ftbl1GxBossds1SIG1);
		GxBossds1SIG2* sig2 = newGxBossds1SIG2();
		sig2->instanceInitGxBossds1SIG2(sample_rate);
		sig2->fillGxBossds1SIG2(100, ftbl2GxBossds1SIG2);
		GxBossds1SIG3* sig3 = newGxBossds1SIG3();
		sig3->instanceInitGxBossds1SIG3(sample_rate);
		sig3->fillGxBossds1SIG3(100, ftbl3GxBossds1SIG3);
		GxBossds1SIG4* sig4 = newGxBossds1SIG4();
		sig4->instanceInitGxBossds1SIG4(sample_rate);
		sig4->fillGxBossds1SIG4(100, ftbl4GxBossds1SIG4);
		deleteGxBossds1SIG0(sig0);
		deleteGxBossds1SIG1(sig1);
		deleteGxBossds1SIG2(sig2);
		deleteGxBossds1SIG3(sig3);
		deleteGxBossds1SIG4(sig4);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 4.33879508860142e-10 * fConst0;
		fConst2 = fConst0 * (fConst1 + -7.11639898820675e-09) + 2.44347979826776e-08;
		fConst3 = GxBossds1_faustpower2_f(fConst0);
		fConst4 = 4.88695959653553e-08 - 8.67759017720285e-10 * fConst3;
		fConst5 = fConst0 * (fConst1 + 7.11639898820675e-09) + 2.44347979826776e-08;
		fConst6 = 1.0 / fConst5;
		fConst7 = 2.89644353783249e-10 * fConst0;
		fConst8 = fConst0 * (-9.44398925362792e-07 - fConst7) + -0.000537812599864916;
		fConst9 = 2.65571689713263e-10 * fConst0;
		fConst10 = fConst0 * (fConst9 + 7.50424979344313e-07);
		fConst11 = 3.3778968192322e-10 * fConst0;
		fConst12 = fConst0 * (fConst11 + 1.55559824875468e-06);
		fConst13 = 2.18842400636233e-10 * fConst0;
		fConst14 = fConst0 * (-5.20602596669238e-08 - fConst13) + 0.000537812599864916;
		fConst15 = fConst0 * (fConst13 + -2.33324618325395e-07);
		fConst16 = fConst0 * (9.44398925362792e-07 - fConst7) + -0.000537812599864916;
		fConst17 = fConst0 * (fConst9 + -7.50424979344313e-07);
		fConst18 = fConst0 * (fConst11 + -1.55559824875468e-06);
		fConst19 = 6.7557936384644e-10 * fConst3;
		fConst20 = 5.31143379426527e-10 * fConst3;
		fConst21 = 5.79288707566498e-10 * fConst3 + -0.00107562519972983;
		fConst22 = std::tan(22619.46710584651 / fConst0);
		fConst23 = 2.0 * (1.0 - 1.0 / GxBossds1_faustpower2_f(fConst22));
		fConst24 = 1.0 / fConst22;
		fConst25 = (fConst24 + -1.414213562373095) / fConst22 + 1.0;
		fConst26 = 1.0 / ((fConst24 + 1.414213562373095) / fConst22 + 1.0);
		fConst27 = std::tan(72.25663103256524 / fConst0);
		fConst28 = GxBossds1_faustpower2_f(fConst27);
		fConst29 = 2.0 * (1.0 - 1.0 / fConst28);
		fConst30 = 1.0 / fConst27;
		fConst31 = (fConst30 + -1.414213562373095) / fConst27 + 1.0;
		fConst32 = (fConst30 + 1.414213562373095) / fConst27 + 1.0;
		fConst33 = 1.0 / fConst32;
		fConst34 = 3.18093350083904e-10 * fConst3;
		fConst35 = 3.0314296262996e-10 * fConst0;
		fConst36 = fConst0 * (fConst35 + -3.38397180940322e-09);
		fConst37 = 1.49503874539434e-11 * fConst0;
		fConst38 = fConst0 * (fConst37 + 1.66555708487018e-05);
		fConst39 = fConst0 * (fConst35 + -1.59012835323858e-05);
		fConst40 = fConst0 * (fConst37 + -7.50903344506575e-07);
		fConst41 = fConst0 * (fConst35 + 3.38397180940322e-09);
		fConst42 = fConst0 * (fConst37 + -1.66555708487018e-05);
		fConst43 = 3.53982651634833e-10 * fConst0;
		fConst44 = fConst0 * (fConst43 + -2.38582349500046e-07) + 1.94656546234155e-05;
		fConst45 = fConst0 * (-2.38582349500046e-07 - fConst43) + 5.83969638702466e-05;
		fConst46 = fConst0 * (2.38582349500046e-07 - fConst43) + 5.83969638702466e-05;
		fConst47 = fConst0 * (fConst43 + 2.38582349500046e-07) + 1.94656546234155e-05;
		fConst48 = 1.0 / fConst47;
		fConst49 = 2.08232145615427e-05 * fConst0;
		fConst50 = fConst49 + 0.000485701045951343;
		fConst51 = (0.000485701045951343 - fConst49) / fConst50;
		fConst52 = 2.07110717442793e-05 * (fConst0 / fConst50);
		fConst53 = 5.51041967277497e-09 * (fConst3 / fConst47);
		fConst54 = fConst0 * (fConst35 + 1.59012835323858e-05);
		fConst55 = fConst0 * (fConst37 + 7.50903344506575e-07);
		fConst56 = ftbl0GxBossds1SIG0[99];
		fConst57 = ftbl0GxBossds1SIG0[0];
		fConst58 = ftbl1GxBossds1SIG1[99];
		fConst59 = ftbl1GxBossds1SIG1[0];
		fConst60 = 1.0 / (fConst28 * fConst32);
		fConst61 = ftbl2GxBossds1SIG2[99];
		fConst62 = ftbl2GxBossds1SIG2[0];
		fConst63 = 9.4e-08 * fConst0;
		fConst64 = ftbl3GxBossds1SIG3[99];
		fConst65 = ftbl3GxBossds1SIG3[0];
		fConst66 = ftbl4GxBossds1SIG4[99];
		fConst67 = ftbl4GxBossds1SIG4[0];
		fConst68 = 4.37684801272465e-10 * fConst3;
		fConst69 = fConst68 + 0.00107562519972983;
		fConst70 = fConst0 * (5.20602596669238e-08 - fConst13) + 0.000537812599864916;
		fConst71 = fConst0 * (fConst13 + 2.33324618325395e-07);
		fConst72 = fConst3 / fConst5;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.7);
		fHslider0 = static_cast<FAUSTFLOAT>(0.5);
		fHslider1 = static_cast<FAUSTFLOAT>(3.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec1[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec5[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec8[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 4; l3 = faust_wrap_add(l3, 1)) {
			fRec7[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec6[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec0[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec9[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec3[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec2[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec0[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec10[l11] = 0.0;
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
	
	virtual GxBossds1* clone() {
		return new GxBossds1(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Boss DS1");
		ui_interface->declare(&fHslider1, "name", "Level");
		ui_interface->addHorizontalSlider("Level", &fHslider1, FAUSTFLOAT(3.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(12.0), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider0, "name", "Tone");
		ui_interface->addVerticalSlider("Tone", &fVslider0, FAUSTFLOAT(0.7), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider0, "name", "Drive");
		ui_interface->addHorizontalSlider("drive", &fHslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * static_cast<double>(fVslider0);
		double fSlow1 = 0.002198000000000002 * static_cast<double>(fHslider0);
		double fSlow2 = 0.007000000000000006 * std::pow(1e+01, 0.05 * static_cast<double>(fHslider1));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow0 + 0.993 * fRec1[1];
			double fTemp0 = fConst12 + fRec1[0] * (fConst10 + fConst8 * fRec1[0] + 0.000537812599864916) + 0.00114855258827151;
			fRec5[0] = fSlow1 + 0.993 * fRec5[1];
			double fTemp1 = fConst34 * fRec5[0];
			double fTemp2 = fConst38 + fRec5[0] * (fConst36 - fTemp1) + 0.000169198590470162;
			double fTemp3 = fConst3 * (fRec5[0] * (6.36186700167807e-10 * fRec5[0] + -6.0628592525992e-10) + -2.99007749078869e-11);
			fRec8[0] = static_cast<double>(input0[i0]) - fConst51 * fRec8[1];
			fRec7[0] = fConst52 * (fRec8[0] - fRec8[1]) - fConst48 * (fConst46 * fRec7[1] + fConst45 * fRec7[2] + fConst44 * fRec7[3]);
			fRec6[0] = -(fConst53 * (fRec7[3] + (fRec7[0] - fRec7[1] - fRec7[2])) + (fRec6[1] * (fTemp3 + 0.000338397180940324) + fRec6[2] * (fConst42 + fRec5[0] * (fConst41 - fTemp1) + 0.000169198590470162)) / fTemp2);
			double fTemp4 = (fRec6[0] * (fConst55 + fRec5[0] * (fConst54 - fTemp1) + 0.000169198590470161) + fRec6[1] * (fTemp3 + 0.000338397180940323) + fRec6[2] * (fConst40 + fRec5[0] * (fConst39 - fTemp1) + 0.000169198590470161)) / fTemp2;
			double fTemp5 = std::fabs(fTemp4);
			double fTemp6 = 101.97 * (fTemp5 / (fTemp5 + 3.0) + -0.005);
			double fTemp7 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp6) | std::isinf(fTemp6)) ? 0.0 : fTemp6)));
			int iTemp8 = static_cast<int>(fTemp7);
			int iTemp9 = iTemp8 < 0;
			int iTemp10 = iTemp8 >= 99;
			int iTemp11 = std::max<int>(0, std::min<int>(98, iTemp8));
			int iTemp12 = faust_wrap_add(iTemp11, 1);
			double fTemp13 = static_cast<double>(iTemp11);
			double fTemp14 = fTemp7 - fTemp13;
			double fTemp15 = fTemp13 + (1.0 - fTemp7);
			fRec4[0] = copysign(((fTemp4 < 0.0) ? ((iTemp9) ? fConst59 : ((iTemp10) ? fConst58 : fTemp15 * ftbl1GxBossds1SIG1[iTemp11] + fTemp14 * ftbl1GxBossds1SIG1[iTemp12])) : ((iTemp9) ? fConst57 : ((iTemp10) ? fConst56 : ftbl0GxBossds1SIG0[iTemp11] * fTemp15 + fTemp14 * ftbl0GxBossds1SIG0[iTemp12]))), -fTemp4) - fConst33 * (fConst31 * fRec4[2] + fConst29 * fRec4[1]);
			double fTemp16 = fConst60 * (fRec4[2] + (fRec4[0] - 2.0 * fRec4[1]));
			double fTemp17 = std::fabs(fTemp16);
			double fTemp18 = 101.97 * (fTemp17 / (fTemp17 + 3.0));
			double fTemp19 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp18) | std::isinf(fTemp18)) ? 0.0 : fTemp18)));
			int iTemp20 = static_cast<int>(fTemp19);
			int iTemp21 = std::max<int>(0, std::min<int>(98, iTemp20));
			double fTemp22 = static_cast<double>(iTemp21);
			double fTemp23 = copysign(((iTemp20 < 0) ? fConst62 : ((iTemp20 >= 99) ? fConst61 : ftbl2GxBossds1SIG2[iTemp21] * (fTemp22 + (1.0 - fTemp19)) + (fTemp19 - fTemp22) * ftbl2GxBossds1SIG2[faust_wrap_add(iTemp21, 1)])), -fTemp16);
			double fTemp24 = 1.0 - fRec5[0];
			double fTemp25 = fConst63 * (1e+05 * fTemp24 + 4.7e+03);
			double fTemp26 = fConst63 * (1e+05 * (fTemp24 + fRec5[0] + 1.0) + 4.7e+03);
			double fTemp27 = fTemp16 - fTemp23;
			fVec0[0] = fTemp27;
			fRec9[0] = -((fRec9[1] * (1.0 - fTemp25) - (fTemp27 * (fTemp26 + 1.0) + fVec0[1] * (1.0 - fTemp26))) / (fTemp25 + 1.0));
			double fTemp28 = fRec9[0] + fTemp23;
			double fTemp29 = std::fabs(fTemp28 - fTemp16);
			double fTemp30 = 101.97 * (fTemp29 / (fTemp29 + 3.0));
			double fTemp31 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp30) | std::isinf(fTemp30)) ? 0.0 : fTemp30)));
			int iTemp32 = static_cast<int>(fTemp31);
			int iTemp33 = std::max<int>(0, std::min<int>(98, iTemp32));
			double fTemp34 = static_cast<double>(iTemp33);
			fRec3[0] = fTemp16 - (fTemp23 + copysign(((iTemp32 < 0) ? fConst62 : ((iTemp32 >= 99) ? fConst61 : ftbl2GxBossds1SIG2[iTemp33] * (fTemp34 + (1.0 - fTemp31)) + (fTemp31 - fTemp34) * ftbl2GxBossds1SIG2[faust_wrap_add(iTemp33, 1)])), fTemp16 - fTemp28) + fConst26 * (fConst25 * fRec3[2] + fConst23 * fRec3[1]));
			double fTemp35 = fConst26 * (fRec3[2] + fRec3[0] + 2.0 * fRec3[1]);
			double fTemp36 = 101.97 * (std::fabs(fTemp35) + -0.006);
			double fTemp37 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp36) | std::isinf(fTemp36)) ? 0.0 : fTemp36)));
			int iTemp38 = static_cast<int>(fTemp37);
			int iTemp39 = iTemp38 < 0;
			int iTemp40 = iTemp38 >= 99;
			int iTemp41 = std::max<int>(0, std::min<int>(98, iTemp38));
			int iTemp42 = faust_wrap_add(iTemp41, 1);
			double fTemp43 = static_cast<double>(iTemp41);
			double fTemp44 = fTemp37 - fTemp43;
			double fTemp45 = fTemp43 + (1.0 - fTemp37);
			fRec2[0] = copysign(((fTemp35 < 0.0) ? ((iTemp39) ? fConst67 : ((iTemp40) ? fConst66 : fTemp45 * ftbl4GxBossds1SIG4[iTemp41] + fTemp44 * ftbl4GxBossds1SIG4[iTemp42])) : ((iTemp39) ? fConst65 : ((iTemp40) ? fConst64 : ftbl3GxBossds1SIG3[iTemp41] * fTemp45 + fTemp44 * ftbl3GxBossds1SIG3[iTemp42]))), fTemp35) - (fRec2[1] * (fRec1[0] * (fConst21 * fRec1[0] + 0.00107562519972983 - fConst20) + 0.00229710517654303 - fConst19) + fRec2[2] * (fConst18 + fRec1[0] * (fConst17 + fConst16 * fRec1[0] + 0.000537812599864916) + 0.00114855258827151)) / fTemp0;
			fRec0[0] = (fRec2[0] * (fConst71 + fConst70 * fRec1[0] + 0.000182856283954071) + fRec2[1] * (fConst69 * fRec1[0] + 0.000365712567908143 - fConst68) + fRec2[2] * (fConst15 + fConst14 * fRec1[0] + 0.000182856283954071)) / fTemp0 - fConst6 * (fConst4 * fRec0[1] + fConst2 * fRec0[2]);
			fRec10[0] = fSlow2 + 0.993 * fRec10[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fConst72 * fRec10[0] * (4.28019579852603e-10 * fRec0[0] - 8.56039159705207e-10 * fRec0[1] + 4.28019579852603e-10 * fRec0[2]));
			fRec1[1] = fRec1[0];
			fRec5[1] = fRec5[0];
			fRec8[1] = fRec8[0];
			for (int j0 = 3; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec7[j0] = fRec7[faust_wrap_sub(j0, 1)];
			}
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fVec0[1] = fVec0[0];
			fRec9[1] = fRec9[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec10[1] = fRec10[0];
		}
	}

};

#endif
