/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Fuzz Face Mayer"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFuzzfacerm -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxFuzzfacerm_H__
#define  __GxFuzzfacerm_H__

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
#define FAUSTCLASS GxFuzzfacerm
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

static double GxFuzzfacerm_faustpower2_f(double value) {
	return value * value;
}
static double GxFuzzfacerm_faustpower3_f(double value) {
	return value * value * value;
}

class GxFuzzfacerm : public chdsp {
	
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
	FAUSTFLOAT fVslider1;
	double fRec1[2];
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
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fConst58;
	double fConst59;
	double fConst60;
	double fRec2[4];
	double fConst61;
	double fConst62;
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	
 public:
	GxFuzzfacerm() {
	}
	
	GxFuzzfacerm(const GxFuzzfacerm&) = default;
	
	virtual ~GxFuzzfacerm() = default;
	
	GxFuzzfacerm& operator=(const GxFuzzfacerm&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Fuzz");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFuzzfacerm -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Roger Mayer Fuzz Face simulation");
		m->declare("filename", "gx-fuzzfacerm.dsp");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("filter.lib/version", "1.29");
		m->declare("id", "fuzzfacerm");
		m->declare("insert_p", "tranyclipper3");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/version", "1.0");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/version", "1.0");
		m->declare("name", "Fuzz Face Mayer");
		m->declare("shortname", "FF Mayer");
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
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 5.85504578964162e-29 * fConst0;
		fConst2 = fConst0 * (fConst1 + 4.00083755606776e-26) + 2.83746860731297e-29;
		fConst3 = 1.19490650740761e-31 * fConst0;
		fConst4 = fConst0 * (fConst3 + 2.08767320417856e-28) + 8.68612838978577e-26;
		fConst5 = 6.18674104772942e-29 * fConst0;
		fConst6 = fConst0 * (-4.00204457374009e-26 - fConst5) + -2.83832448080453e-29;
		fConst7 = 1.26259937209307e-31 * fConst0;
		fConst8 = fConst0 * (-2.15993317197785e-28 - fConst7) + -8.68874841067831e-26;
		fConst9 = 3.22405119745267e-14 * fConst0;
		fConst10 = fConst0 * (-2.08898268350887e-11 - fConst9) + -2.21793415696022e-11;
		fConst11 = 3.05119726906337e-14 * fConst0;
		fConst12 = fConst0 * (fConst11 + 2.08816997599123e-11) + 2.21726535708769e-11;
		fConst13 = 1.72853928389298e-15 * fConst0;
		fConst14 = fConst0 * (fConst13 + 4.32740215906676e-13) + 2.6123111187704e-10;
		fConst15 = 3.31695258087803e-30 * fConst0;
		fConst16 = fConst0 * (fConst0 * (fConst15 + 8.26874714950455e-28) + 5.00406457485288e-25) + 3.54897544287011e-28;
		fConst17 = 6.76928646854567e-33 * fConst0;
		fConst18 = fConst0 * (fConst0 * (fConst17 + 8.88886207590151e-30) + 2.81644163364677e-27);
		fConst19 = 2.23179427996828e-12 * fConst0;
		fConst20 = fConst19 + -2.84573463334658e-11;
		fConst21 = 2.27734110200845e-12 * fConst0;
		fConst22 = 2.90381085035365e-11 - fConst21;
		fConst23 = GxFuzzfacerm_faustpower2_f(fConst0);
		fConst24 = GxFuzzfacerm_faustpower3_f(fConst0);
		fConst25 = fConst0 * (4.00083755606776e-26 - fConst1) + -2.83746860731297e-29;
		fConst26 = fConst0 * (2.08767320417856e-28 - fConst3) + -8.68612838978577e-26;
		fConst27 = fConst0 * (fConst5 + -4.00204457374009e-26) + 2.83832448080453e-29;
		fConst28 = fConst0 * (fConst7 + -2.15993317197785e-28) + 8.68874841067831e-26;
		fConst29 = fConst0 * (fConst9 + -2.08898268350887e-11) + 2.21793415696022e-11;
		fConst30 = fConst0 * (2.08816997599123e-11 - fConst11) + -2.21726535708769e-11;
		fConst31 = fConst0 * (4.32740215906676e-13 - fConst13) + -2.6123111187704e-10;
		fConst32 = fConst0 * (fConst0 * (8.26874714950455e-28 - fConst15) + -5.00406457485288e-25) + 3.54897544287011e-28;
		fConst33 = fConst0 * (fConst0 * (8.88886207590151e-30 - fConst17) + -2.81644163364677e-27);
		fConst34 = 1.75651373689249e-28 * fConst0;
		fConst35 = fConst0 * (fConst34 + -4.00083755606776e-26) + -2.83746860731297e-29;
		fConst36 = 3.58471952222284e-31 * fConst0;
		fConst37 = fConst0 * (fConst36 + -2.08767320417856e-28) + -8.68612838978577e-26;
		fConst38 = 1.85602231431883e-28 * fConst0;
		fConst39 = fConst0 * (4.00204457374009e-26 - fConst38) + 2.83832448080453e-29;
		fConst40 = 3.78779811627921e-31 * fConst0;
		fConst41 = fConst0 * (2.15993317197785e-28 - fConst40) + 8.68874841067831e-26;
		fConst42 = 9.67215359235801e-14 * fConst0;
		fConst43 = fConst0 * (2.08898268350887e-11 - fConst42) + 2.21793415696022e-11;
		fConst44 = 9.15359180719011e-14 * fConst0;
		fConst45 = fConst0 * (fConst44 + -2.08816997599123e-11) + -2.21726535708769e-11;
		fConst46 = 5.18561785167894e-15 * fConst0;
		fConst47 = fConst0 * (fConst46 + -4.32740215906676e-13) + -2.6123111187704e-10;
		fConst48 = 9.95085774263408e-30 * fConst0;
		fConst49 = fConst0 * (fConst0 * (fConst48 + -8.26874714950455e-28) + -5.00406457485288e-25) + 1.06469263286103e-27;
		fConst50 = 2.0307859405637e-32 * fConst0;
		fConst51 = fConst0 * (fConst0 * (fConst50 + -8.88886207590151e-30) + -2.81644163364677e-27);
		fConst52 = fConst0 * (-4.00083755606776e-26 - fConst34) + 2.83746860731297e-29;
		fConst53 = fConst0 * (-2.08767320417856e-28 - fConst36) + 8.68612838978577e-26;
		fConst54 = fConst0 * (fConst38 + 4.00204457374009e-26) + -2.83832448080453e-29;
		fConst55 = fConst0 * (fConst40 + 2.15993317197785e-28) + -8.68874841067831e-26;
		fConst56 = fConst0 * (fConst42 + 2.08898268350887e-11) + -2.21793415696022e-11;
		fConst57 = fConst0 * (-2.08816997599123e-11 - fConst44) + 2.21726535708769e-11;
		fConst58 = fConst0 * (-4.32740215906676e-13 - fConst46) + 2.6123111187704e-10;
		fConst59 = fConst0 * (fConst0 * (-8.26874714950455e-28 - fConst48) + 5.00406457485288e-25) + 1.06469263286103e-27;
		fConst60 = fConst0 * (fConst0 * (-8.88886207590151e-30 - fConst50) + 2.81644163364677e-27);
		fConst61 = 6.69538283990485e-12 * fConst0;
		fConst62 = 2.84573463334658e-11 - fConst61;
		fConst63 = 6.83202330602535e-12 * fConst0;
		fConst64 = fConst63 + -2.90381085035365e-11;
		fConst65 = fConst61 + 2.84573463334658e-11;
		fConst66 = -2.90381085035365e-11 - fConst63;
		fConst67 = -2.84573463334658e-11 - fConst19;
		fConst68 = fConst21 + 2.90381085035365e-11;
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
			fRec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 4; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0;
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
	
	virtual GxFuzzfacerm* clone() {
		return new GxFuzzfacerm(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Fuzz Face Mayer");
		ui_interface->declare(&fVslider1, "name", "Fuzz");
		ui_interface->addVerticalSlider("Fuzz", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider0, "name", "Level");
		ui_interface->addVerticalSlider("Level", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * (1.0 - 0.05239569649125595 * (std::exp(3.0 * static_cast<double>(fVslider0)) + -1.0));
		double fSlow1 = 0.007000000000000006 * (1.0 - static_cast<double>(fVslider1));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			fRec1[0] = fSlow1 + 0.993 * fRec1[1];
			double fTemp0 = fRec0[0] * (fConst18 + fConst16 * fRec0[0] + 1.08642105394636e-24) + fConst0 * (fConst14 + fRec1[0] * (fConst12 + fRec1[0] * (fConst10 + fRec0[0] * (fConst8 + fConst6 * fRec0[0])) + fRec0[0] * (fConst4 + fConst2 * fRec0[0]))) + 2.77325369604093e-10;
			double fTemp1 = 2.1870008532593e-12 * fRec0[0];
			double fTemp2 = 4.47934267089816e-14 * fRec0[0];
			fRec2[0] = static_cast<double>(input0[i0]) - (fRec2[1] * (fRec0[0] * (fConst60 + fConst59 * fRec0[0] + 3.25926316183907e-24) + fConst0 * (fConst58 + fRec1[0] * (fConst57 + fRec1[0] * (fConst56 + fRec0[0] * (fConst55 + fConst54 * fRec0[0])) + fRec0[0] * (fConst53 + fConst52 * fRec0[0]))) + 8.3197610881228e-10) + fRec2[2] * (fRec0[0] * (fConst51 + fConst49 * fRec0[0] + 3.25926316183907e-24) + fConst0 * (fConst47 + fRec1[0] * (fConst45 + fRec1[0] * (fConst43 + fRec0[0] * (fConst41 + fConst39 * fRec0[0])) + fRec0[0] * (fConst37 + fConst35 * fRec0[0]))) + 8.3197610881228e-10) + fRec2[3] * (fRec0[0] * (fConst33 + fConst32 * fRec0[0] + 1.08642105394636e-24) + fConst0 * (fConst31 + fRec1[0] * (fConst30 + fRec1[0] * (fConst29 + fRec0[0] * (fConst28 + fConst27 * fRec0[0])) + fRec0[0] * (fConst26 + fConst25 * fRec0[0]))) + 2.77325369604093e-10)) / fTemp0;
			double fTemp3 = 1.34380280126945e-13 * fRec0[0];
			double fTemp4 = 6.5610025597779e-12 * fRec0[0];
			output0[i0] = static_cast<FAUSTFLOAT>((fRec2[0] * (fConst24 * fRec1[0] * (fTemp1 + fRec1[0] * (fTemp2 + -4.57075782744711e-14) + -2.23163352373398e-12) + fConst23 * (fConst68 + fConst67 * fRec0[0])) + fRec2[1] * (fConst24 * fRec1[0] * (fRec1[0] * (1.37122734823413e-13 - fTemp3) - fTemp4 + 6.69490057120194e-12) + fConst23 * (fConst66 + fConst65 * fRec0[0])) + fRec2[2] * (fConst24 * fRec1[0] * (fTemp4 + fRec1[0] * (fTemp3 + -1.37122734823413e-13) + -6.69490057120194e-12) + fConst23 * (fConst64 + fConst62 * fRec0[0])) + fRec2[3] * (fConst24 * fRec1[0] * (fRec1[0] * (4.57075782744711e-14 - fTemp2) - fTemp1 + 2.23163352373398e-12) + fConst23 * (fConst22 + fConst20 * fRec0[0]))) / fTemp0);
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			for (int j0 = 3; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec2[j0] = fRec2[faust_wrap_sub(j0, 1)];
			}
		}
	}

};

#endif
