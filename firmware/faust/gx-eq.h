/* ------------------------------------------------------------
copyright: "(c)GRAME 2006"
license: "BSD"
name: "gx-eq"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxEq -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxEq_H__
#define  __GxEq_H__

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
#define FAUSTCLASS GxEq
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

static double GxEq_faustpower2_f(double value) {
	return value * value;
}

class GxEq : public chdsp {
	
 private:
	
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	double fConst3;
	double fConst4;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT fVslider3;
	double fConst5;
	double fConst6;
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT fVslider5;
	double fConst7;
	double fConst8;
	FAUSTFLOAT fVslider6;
	FAUSTFLOAT fVslider7;
	double fConst9;
	double fConst10;
	FAUSTFLOAT fVslider8;
	FAUSTFLOAT fVslider9;
	double fConst11;
	double fConst12;
	FAUSTFLOAT fVslider10;
	FAUSTFLOAT fVslider11;
	double fConst13;
	double fConst14;
	FAUSTFLOAT fVslider12;
	FAUSTFLOAT fVslider13;
	double fConst15;
	double fConst16;
	FAUSTFLOAT fVslider14;
	FAUSTFLOAT fVslider15;
	double fConst17;
	double fConst18;
	FAUSTFLOAT fVslider16;
	FAUSTFLOAT fVslider17;
	double fConst19;
	double fConst20;
	FAUSTFLOAT fVslider18;
	FAUSTFLOAT fVslider19;
	double fRec9[3];
	double fRec8[3];
	double fRec7[3];
	double fRec6[3];
	double fRec5[3];
	double fRec4[3];
	double fRec3[3];
	double fRec2[3];
	double fRec1[3];
	double fRec0[3];
	
 public:
	GxEq() {
	}
	
	GxEq(const GxEq&) = default;
	
	virtual ~GxEq() = default;
	
	GxEq& operator=(const GxEq&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxEq -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("copyright", "(c)GRAME 2006");
		m->declare("filename", "gx-eq.dsp");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "eq");
		m->declare("license", "BSD");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "gx-eq");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
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
		fConst1 = std::tan(50265.48245743669 / fConst0);
		fConst2 = 2.0 * (GxEq_faustpower2_f(fConst1) + -1.0);
		fConst3 = std::tan(25132.741228718343 / fConst0);
		fConst4 = 2.0 * (GxEq_faustpower2_f(fConst3) + -1.0);
		fConst5 = std::tan(12566.370614359172 / fConst0);
		fConst6 = 2.0 * (GxEq_faustpower2_f(fConst5) + -1.0);
		fConst7 = std::tan(6283.185307179586 / fConst0);
		fConst8 = 2.0 * (GxEq_faustpower2_f(fConst7) + -1.0);
		fConst9 = std::tan(3141.592653589793 / fConst0);
		fConst10 = 2.0 * (GxEq_faustpower2_f(fConst9) + -1.0);
		fConst11 = std::tan(1570.7963267948965 / fConst0);
		fConst12 = 2.0 * (GxEq_faustpower2_f(fConst11) + -1.0);
		fConst13 = std::tan(785.3981633974482 / fConst0);
		fConst14 = 2.0 * (GxEq_faustpower2_f(fConst13) + -1.0);
		fConst15 = std::tan(392.6990816987241 / fConst0);
		fConst16 = 2.0 * (GxEq_faustpower2_f(fConst15) + -1.0);
		fConst17 = std::tan(196.34954084936206 / fConst0);
		fConst18 = 2.0 * (GxEq_faustpower2_f(fConst17) + -1.0);
		fConst19 = std::tan(98.17477042468103 / fConst0);
		fConst20 = 2.0 * (GxEq_faustpower2_f(fConst19) + -1.0);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider1 = static_cast<FAUSTFLOAT>(0.0);
		fVslider2 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider3 = static_cast<FAUSTFLOAT>(0.0);
		fVslider4 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider5 = static_cast<FAUSTFLOAT>(0.0);
		fVslider6 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider7 = static_cast<FAUSTFLOAT>(0.0);
		fVslider8 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider9 = static_cast<FAUSTFLOAT>(0.0);
		fVslider10 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider11 = static_cast<FAUSTFLOAT>(0.0);
		fVslider12 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider13 = static_cast<FAUSTFLOAT>(0.0);
		fVslider14 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider15 = static_cast<FAUSTFLOAT>(0.0);
		fVslider16 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider17 = static_cast<FAUSTFLOAT>(0.0);
		fVslider18 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider19 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 3; l0 = faust_wrap_add(l0, 1)) {
			fRec9[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 3; l1 = faust_wrap_add(l1, 1)) {
			fRec8[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec7[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 3; l3 = faust_wrap_add(l3, 1)) {
			fRec6[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec5[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec3[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec2[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec1[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec0[l9] = 0.0;
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
	
	virtual GxEq* clone() {
		return new GxEq(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("gx-eq");
		ui_interface->addVerticalSlider("Q125", &fVslider14, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Q16k", &fVslider0, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Q1k", &fVslider8, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Q250", &fVslider12, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Q2k", &fVslider6, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Q31_25", &fVslider18, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Q4k", &fVslider4, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Q500", &fVslider10, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Q62_5", &fVslider16, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Q8k", &fVslider2, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider15, "tooltip", "gain (dB) at 125 Hz");
		ui_interface->addVerticalSlider("f125", &fVslider15, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider1, "tooltip", "gain (dB) at 16 kHz");
		ui_interface->addVerticalSlider("f16k", &fVslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider9, "tooltip", "gain (dB) at 1 kHz");
		ui_interface->addVerticalSlider("f1k", &fVslider9, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider13, "tooltip", "gain (dB) at 250 Hz");
		ui_interface->addVerticalSlider("f250", &fVslider13, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider7, "tooltip", "gain (dB) at 2 kHz");
		ui_interface->addVerticalSlider("f2k", &fVslider7, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider19, "tooltip", "gain (dB) at 31.25 Hz");
		ui_interface->addVerticalSlider("f31_25", &fVslider19, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider5, "tooltip", "gain (dB) at 4 kHz");
		ui_interface->addVerticalSlider("f4k", &fVslider5, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider11, "tooltip", "gain (dB) at 500 Hz");
		ui_interface->addVerticalSlider("f500", &fVslider11, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider17, "tooltip", "gain (dB) at 62.5 Hz");
		ui_interface->addVerticalSlider("f62_5", &fVslider17, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider3, "tooltip", "gain (dB) at 8 kHz");
		ui_interface->addVerticalSlider("f8k", &fVslider3, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fVslider0);
		double fSlow1 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider1))) / fSlow0;
		double fSlow2 = fConst1 * (fConst1 - fSlow1) + 1.0;
		double fSlow3 = 1.0 / (fConst1 * (fConst1 + fSlow1) + 1.0);
		double fSlow4 = static_cast<double>(fVslider2);
		double fSlow5 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider3))) / fSlow4;
		double fSlow6 = fConst3 * (fConst3 - fSlow5) + 1.0;
		double fSlow7 = 1.0 / (fConst3 * (fConst3 + fSlow5) + 1.0);
		double fSlow8 = static_cast<double>(fVslider4);
		double fSlow9 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider5))) / fSlow8;
		double fSlow10 = fConst5 * (fConst5 - fSlow9) + 1.0;
		double fSlow11 = 1.0 / (fConst5 * (fConst5 + fSlow9) + 1.0);
		double fSlow12 = static_cast<double>(fVslider6);
		double fSlow13 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider7))) / fSlow12;
		double fSlow14 = fConst7 * (fConst7 - fSlow13) + 1.0;
		double fSlow15 = 1.0 / (fConst7 * (fConst7 + fSlow13) + 1.0);
		double fSlow16 = static_cast<double>(fVslider8);
		double fSlow17 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider9))) / fSlow16;
		double fSlow18 = fConst9 * (fConst9 - fSlow17) + 1.0;
		double fSlow19 = 1.0 / (fConst9 * (fConst9 + fSlow17) + 1.0);
		double fSlow20 = static_cast<double>(fVslider10);
		double fSlow21 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider11))) / fSlow20;
		double fSlow22 = fConst11 * (fConst11 - fSlow21) + 1.0;
		double fSlow23 = 1.0 / (fConst11 * (fConst11 + fSlow21) + 1.0);
		double fSlow24 = static_cast<double>(fVslider12);
		double fSlow25 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider13))) / fSlow24;
		double fSlow26 = fConst13 * (fConst13 - fSlow25) + 1.0;
		double fSlow27 = 1.0 / (fConst13 * (fConst13 + fSlow25) + 1.0);
		double fSlow28 = static_cast<double>(fVslider14);
		double fSlow29 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider15))) / fSlow28;
		double fSlow30 = fConst15 * (fConst15 - fSlow29) + 1.0;
		double fSlow31 = 1.0 / (fConst15 * (fConst15 + fSlow29) + 1.0);
		double fSlow32 = static_cast<double>(fVslider16);
		double fSlow33 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider17))) / fSlow32;
		double fSlow34 = fConst17 * (fConst17 - fSlow33) + 1.0;
		double fSlow35 = 1.0 / (fConst17 * (fConst17 + fSlow33) + 1.0);
		double fSlow36 = static_cast<double>(fVslider18);
		double fSlow37 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider19))) / fSlow36;
		double fSlow38 = fConst19 * (fConst19 - fSlow37) + 1.0;
		double fSlow39 = 1.0 / (fConst19 * (fConst19 + fSlow37) + 1.0);
		double fSlow40 = 1.0 / fSlow36;
		double fSlow41 = 1.0 - fConst19 * (fSlow40 - fConst19);
		double fSlow42 = fConst19 * (fConst19 + fSlow40) + 1.0;
		double fSlow43 = 1.0 / fSlow32;
		double fSlow44 = 1.0 - fConst17 * (fSlow43 - fConst17);
		double fSlow45 = fConst17 * (fConst17 + fSlow43) + 1.0;
		double fSlow46 = 1.0 / fSlow28;
		double fSlow47 = 1.0 - fConst15 * (fSlow46 - fConst15);
		double fSlow48 = fConst15 * (fConst15 + fSlow46) + 1.0;
		double fSlow49 = 1.0 / fSlow24;
		double fSlow50 = 1.0 - fConst13 * (fSlow49 - fConst13);
		double fSlow51 = fConst13 * (fConst13 + fSlow49) + 1.0;
		double fSlow52 = 1.0 / fSlow20;
		double fSlow53 = 1.0 - fConst11 * (fSlow52 - fConst11);
		double fSlow54 = fConst11 * (fConst11 + fSlow52) + 1.0;
		double fSlow55 = 1.0 / fSlow16;
		double fSlow56 = 1.0 - fConst9 * (fSlow55 - fConst9);
		double fSlow57 = fConst9 * (fConst9 + fSlow55) + 1.0;
		double fSlow58 = 1.0 / fSlow12;
		double fSlow59 = 1.0 - fConst7 * (fSlow58 - fConst7);
		double fSlow60 = fConst7 * (fConst7 + fSlow58) + 1.0;
		double fSlow61 = 1.0 / fSlow8;
		double fSlow62 = 1.0 - fConst5 * (fSlow61 - fConst5);
		double fSlow63 = fConst5 * (fConst5 + fSlow61) + 1.0;
		double fSlow64 = 1.0 / fSlow4;
		double fSlow65 = 1.0 - fConst3 * (fSlow64 - fConst3);
		double fSlow66 = fConst3 * (fConst3 + fSlow64) + 1.0;
		double fSlow67 = 1.0 / fSlow0;
		double fSlow68 = 1.0 - fConst1 * (fSlow67 - fConst1);
		double fSlow69 = fConst1 * (fConst1 + fSlow67) + 1.0;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = fConst2 * fRec0[1];
			double fTemp1 = fConst4 * fRec1[1];
			double fTemp2 = fConst6 * fRec2[1];
			double fTemp3 = fConst8 * fRec3[1];
			double fTemp4 = fConst10 * fRec4[1];
			double fTemp5 = fConst12 * fRec5[1];
			double fTemp6 = fConst14 * fRec6[1];
			double fTemp7 = fConst16 * fRec7[1];
			double fTemp8 = fConst18 * fRec8[1];
			double fTemp9 = fConst20 * fRec9[1];
			fRec9[0] = static_cast<double>(input0[i0]) - fSlow39 * (fSlow38 * fRec9[2] + fTemp9);
			fRec8[0] = fSlow39 * (fTemp9 + fSlow42 * fRec9[0] + fSlow41 * fRec9[2]) - fSlow35 * (fSlow34 * fRec8[2] + fTemp8);
			fRec7[0] = fSlow35 * (fTemp8 + fSlow45 * fRec8[0] + fSlow44 * fRec8[2]) - fSlow31 * (fSlow30 * fRec7[2] + fTemp7);
			fRec6[0] = fSlow31 * (fTemp7 + fSlow48 * fRec7[0] + fSlow47 * fRec7[2]) - fSlow27 * (fSlow26 * fRec6[2] + fTemp6);
			fRec5[0] = fSlow27 * (fTemp6 + fSlow51 * fRec6[0] + fSlow50 * fRec6[2]) - fSlow23 * (fSlow22 * fRec5[2] + fTemp5);
			fRec4[0] = fSlow23 * (fTemp5 + fSlow54 * fRec5[0] + fSlow53 * fRec5[2]) - fSlow19 * (fSlow18 * fRec4[2] + fTemp4);
			fRec3[0] = fSlow19 * (fTemp4 + fSlow57 * fRec4[0] + fSlow56 * fRec4[2]) - fSlow15 * (fSlow14 * fRec3[2] + fTemp3);
			fRec2[0] = fSlow15 * (fTemp3 + fSlow60 * fRec3[0] + fSlow59 * fRec3[2]) - fSlow11 * (fSlow10 * fRec2[2] + fTemp2);
			fRec1[0] = fSlow11 * (fTemp2 + fSlow63 * fRec2[0] + fSlow62 * fRec2[2]) - fSlow7 * (fSlow6 * fRec1[2] + fTemp1);
			fRec0[0] = fSlow7 * (fTemp1 + fSlow66 * fRec1[0] + fSlow65 * fRec1[2]) - fSlow3 * (fSlow2 * fRec0[2] + fTemp0);
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow3 * (fTemp0 + fSlow69 * fRec0[0] + fSlow68 * fRec0[2]));
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
