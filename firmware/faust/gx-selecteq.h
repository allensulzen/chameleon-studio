/* ------------------------------------------------------------
copyright: "(c)GRAME 2006"
license: "BSD"
name: "Scaleable EQ"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxSelecteq -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxSelecteq_H__
#define  __GxSelecteq_H__

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
#define FAUSTCLASS GxSelecteq
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

static double GxSelecteq_faustpower2_f(double value) {
	return value * value;
}

class GxSelecteq : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	double fConst0;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT fVslider6;
	FAUSTFLOAT fVslider7;
	FAUSTFLOAT fVslider8;
	FAUSTFLOAT fVslider9;
	FAUSTFLOAT fVslider10;
	FAUSTFLOAT fVslider11;
	FAUSTFLOAT fVslider12;
	FAUSTFLOAT fVslider13;
	FAUSTFLOAT fVslider14;
	FAUSTFLOAT fVslider15;
	FAUSTFLOAT fVslider16;
	FAUSTFLOAT fVslider17;
	FAUSTFLOAT fVslider18;
	FAUSTFLOAT fVslider19;
	FAUSTFLOAT fVslider20;
	FAUSTFLOAT fVslider21;
	FAUSTFLOAT fVslider22;
	FAUSTFLOAT fVslider23;
	FAUSTFLOAT fVslider24;
	FAUSTFLOAT fVslider25;
	FAUSTFLOAT fVslider26;
	FAUSTFLOAT fVslider27;
	FAUSTFLOAT fVslider28;
	FAUSTFLOAT fVslider29;
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
	GxSelecteq() {
	}
	
	GxSelecteq(const GxSelecteq&) = default;
	
	virtual ~GxSelecteq() = default;
	
	GxSelecteq& operator=(const GxSelecteq&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Tone Control");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxSelecteq -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("copyright", "(c)GRAME 2006");
		m->declare("filename", "gx-selecteq.dsp");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "eqs");
		m->declare("license", "BSD");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Scaleable EQ");
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
		fConst0 = 3.141592653589793 / std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(1.6e+04);
		fVslider1 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider2 = static_cast<FAUSTFLOAT>(0.0);
		fVslider3 = static_cast<FAUSTFLOAT>(8e+03);
		fVslider4 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider5 = static_cast<FAUSTFLOAT>(0.0);
		fVslider6 = static_cast<FAUSTFLOAT>(4e+03);
		fVslider7 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider8 = static_cast<FAUSTFLOAT>(0.0);
		fVslider9 = static_cast<FAUSTFLOAT>(2e+03);
		fVslider10 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider11 = static_cast<FAUSTFLOAT>(0.0);
		fVslider12 = static_cast<FAUSTFLOAT>(1e+03);
		fVslider13 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider14 = static_cast<FAUSTFLOAT>(0.0);
		fVslider15 = static_cast<FAUSTFLOAT>(5e+02);
		fVslider16 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider17 = static_cast<FAUSTFLOAT>(0.0);
		fVslider18 = static_cast<FAUSTFLOAT>(2.5e+02);
		fVslider19 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider20 = static_cast<FAUSTFLOAT>(0.0);
		fVslider21 = static_cast<FAUSTFLOAT>(125.0);
		fVslider22 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider23 = static_cast<FAUSTFLOAT>(0.0);
		fVslider24 = static_cast<FAUSTFLOAT>(62.0);
		fVslider25 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider26 = static_cast<FAUSTFLOAT>(0.0);
		fVslider27 = static_cast<FAUSTFLOAT>(31.0);
		fVslider28 = static_cast<FAUSTFLOAT>(5e+01);
		fVslider29 = static_cast<FAUSTFLOAT>(0.0);
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
	
	virtual GxSelecteq* clone() {
		return new GxSelecteq(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Scaleable EQ");
		ui_interface->addVerticalSlider("Qs125", &fVslider22, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Qs16k", &fVslider1, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Qs1k", &fVslider13, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Qs250", &fVslider19, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Qs2k", &fVslider10, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Qs31_25", &fVslider28, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Qs4k", &fVslider7, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Qs500", &fVslider16, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Qs62_5", &fVslider25, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->addVerticalSlider("Qs8k", &fVslider4, FAUSTFLOAT(5e+01), FAUSTFLOAT(1.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider21, "tooltip", "Hz");
		ui_interface->addVerticalSlider("freq125", &fVslider21, FAUSTFLOAT(125.0), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider0, "tooltip", "Hz");
		ui_interface->addVerticalSlider("freq16k", &fVslider0, FAUSTFLOAT(1.6e+04), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider12, "tooltip", "Hz");
		ui_interface->addVerticalSlider("freq1k", &fVslider12, FAUSTFLOAT(1e+03), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider18, "tooltip", "Hz");
		ui_interface->addVerticalSlider("freq250", &fVslider18, FAUSTFLOAT(2.5e+02), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider9, "tooltip", "Hz");
		ui_interface->addVerticalSlider("freq2k", &fVslider9, FAUSTFLOAT(2e+03), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider27, "tooltip", "Hz");
		ui_interface->addVerticalSlider("freq31_25", &fVslider27, FAUSTFLOAT(31.0), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider6, "tooltip", "Hz");
		ui_interface->addVerticalSlider("freq4k", &fVslider6, FAUSTFLOAT(4e+03), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider15, "tooltip", "Hz");
		ui_interface->addVerticalSlider("freq500", &fVslider15, FAUSTFLOAT(5e+02), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider24, "tooltip", "Hz");
		ui_interface->addVerticalSlider("freq62_5", &fVslider24, FAUSTFLOAT(62.0), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider3, "tooltip", "Hz");
		ui_interface->addVerticalSlider("freq8k", &fVslider3, FAUSTFLOAT(8e+03), FAUSTFLOAT(2e+01), FAUSTFLOAT(2e+04), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider23, "tooltip", "gain (dB) at 125 Hz");
		ui_interface->addVerticalSlider("fs125", &fVslider23, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider2, "tooltip", "gain (dB) at 16 kHz");
		ui_interface->addVerticalSlider("fs16k", &fVslider2, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider14, "tooltip", "gain (dB) at 1 kHz");
		ui_interface->addVerticalSlider("fs1k", &fVslider14, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider20, "tooltip", "gain (dB) at 250 Hz");
		ui_interface->addVerticalSlider("fs250", &fVslider20, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider11, "tooltip", "gain (dB) at 2 kHz");
		ui_interface->addVerticalSlider("fs2k", &fVslider11, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider29, "tooltip", "gain (dB) at 31.25 Hz");
		ui_interface->addVerticalSlider("fs31_25", &fVslider29, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider8, "tooltip", "gain (dB) at 4 kHz");
		ui_interface->addVerticalSlider("fs4k", &fVslider8, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider17, "tooltip", "gain (dB) at 500 Hz");
		ui_interface->addVerticalSlider("fs500", &fVslider17, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider26, "tooltip", "gain (dB) at 62.5 Hz");
		ui_interface->addVerticalSlider("fs62_5", &fVslider26, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider5, "tooltip", "gain (dB) at 8 kHz");
		ui_interface->addVerticalSlider("fs8k", &fVslider5, FAUSTFLOAT(0.0), FAUSTFLOAT(-5e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.1));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = std::tan(fConst0 * static_cast<double>(fVslider0));
		double fSlow1 = 2.0 * (GxSelecteq_faustpower2_f(fSlow0) + -1.0);
		double fSlow2 = static_cast<double>(fVslider1);
		double fSlow3 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider2))) / fSlow2;
		double fSlow4 = fSlow0 * (fSlow0 - fSlow3) + 1.0;
		double fSlow5 = 1.0 / (fSlow0 * (fSlow3 + fSlow0) + 1.0);
		double fSlow6 = std::tan(fConst0 * static_cast<double>(fVslider3));
		double fSlow7 = 2.0 * (GxSelecteq_faustpower2_f(fSlow6) + -1.0);
		double fSlow8 = static_cast<double>(fVslider4);
		double fSlow9 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider5))) / fSlow8;
		double fSlow10 = fSlow6 * (fSlow6 - fSlow9) + 1.0;
		double fSlow11 = 1.0 / (fSlow6 * (fSlow9 + fSlow6) + 1.0);
		double fSlow12 = std::tan(fConst0 * static_cast<double>(fVslider6));
		double fSlow13 = 2.0 * (GxSelecteq_faustpower2_f(fSlow12) + -1.0);
		double fSlow14 = static_cast<double>(fVslider7);
		double fSlow15 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider8))) / fSlow14;
		double fSlow16 = fSlow12 * (fSlow12 - fSlow15) + 1.0;
		double fSlow17 = 1.0 / (fSlow12 * (fSlow15 + fSlow12) + 1.0);
		double fSlow18 = std::tan(fConst0 * static_cast<double>(fVslider9));
		double fSlow19 = 2.0 * (GxSelecteq_faustpower2_f(fSlow18) + -1.0);
		double fSlow20 = static_cast<double>(fVslider10);
		double fSlow21 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider11))) / fSlow20;
		double fSlow22 = fSlow18 * (fSlow18 - fSlow21) + 1.0;
		double fSlow23 = 1.0 / (fSlow18 * (fSlow21 + fSlow18) + 1.0);
		double fSlow24 = std::tan(fConst0 * static_cast<double>(fVslider12));
		double fSlow25 = 2.0 * (GxSelecteq_faustpower2_f(fSlow24) + -1.0);
		double fSlow26 = static_cast<double>(fVslider13);
		double fSlow27 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider14))) / fSlow26;
		double fSlow28 = fSlow24 * (fSlow24 - fSlow27) + 1.0;
		double fSlow29 = 1.0 / (fSlow24 * (fSlow27 + fSlow24) + 1.0);
		double fSlow30 = std::tan(fConst0 * static_cast<double>(fVslider15));
		double fSlow31 = 2.0 * (GxSelecteq_faustpower2_f(fSlow30) + -1.0);
		double fSlow32 = static_cast<double>(fVslider16);
		double fSlow33 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider17))) / fSlow32;
		double fSlow34 = fSlow30 * (fSlow30 - fSlow33) + 1.0;
		double fSlow35 = 1.0 / (fSlow30 * (fSlow33 + fSlow30) + 1.0);
		double fSlow36 = std::tan(fConst0 * static_cast<double>(fVslider18));
		double fSlow37 = 2.0 * (GxSelecteq_faustpower2_f(fSlow36) + -1.0);
		double fSlow38 = static_cast<double>(fVslider19);
		double fSlow39 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider20))) / fSlow38;
		double fSlow40 = fSlow36 * (fSlow36 - fSlow39) + 1.0;
		double fSlow41 = 1.0 / (fSlow36 * (fSlow39 + fSlow36) + 1.0);
		double fSlow42 = std::tan(fConst0 * static_cast<double>(fVslider21));
		double fSlow43 = 2.0 * (GxSelecteq_faustpower2_f(fSlow42) + -1.0);
		double fSlow44 = static_cast<double>(fVslider22);
		double fSlow45 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider23))) / fSlow44;
		double fSlow46 = fSlow42 * (fSlow42 - fSlow45) + 1.0;
		double fSlow47 = 1.0 / (fSlow42 * (fSlow45 + fSlow42) + 1.0);
		double fSlow48 = std::tan(fConst0 * static_cast<double>(fVslider24));
		double fSlow49 = 2.0 * (GxSelecteq_faustpower2_f(fSlow48) + -1.0);
		double fSlow50 = static_cast<double>(fVslider25);
		double fSlow51 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider26))) / fSlow50;
		double fSlow52 = fSlow48 * (fSlow48 - fSlow51) + 1.0;
		double fSlow53 = 1.0 / (fSlow48 * (fSlow51 + fSlow48) + 1.0);
		double fSlow54 = std::tan(fConst0 * static_cast<double>(fVslider27));
		double fSlow55 = 2.0 * (GxSelecteq_faustpower2_f(fSlow54) + -1.0);
		double fSlow56 = static_cast<double>(fVslider28);
		double fSlow57 = std::pow(1e+01, -(0.05 * static_cast<double>(fVslider29))) / fSlow56;
		double fSlow58 = fSlow54 * (fSlow54 - fSlow57) + 1.0;
		double fSlow59 = 1.0 / (fSlow54 * (fSlow57 + fSlow54) + 1.0);
		double fSlow60 = 1.0 / fSlow56;
		double fSlow61 = 1.0 - fSlow54 * (fSlow60 - fSlow54);
		double fSlow62 = fSlow54 * (fSlow60 + fSlow54) + 1.0;
		double fSlow63 = 1.0 / fSlow50;
		double fSlow64 = 1.0 - fSlow48 * (fSlow63 - fSlow48);
		double fSlow65 = fSlow48 * (fSlow63 + fSlow48) + 1.0;
		double fSlow66 = 1.0 / fSlow44;
		double fSlow67 = 1.0 - fSlow42 * (fSlow66 - fSlow42);
		double fSlow68 = fSlow42 * (fSlow66 + fSlow42) + 1.0;
		double fSlow69 = 1.0 / fSlow38;
		double fSlow70 = 1.0 - fSlow36 * (fSlow69 - fSlow36);
		double fSlow71 = fSlow36 * (fSlow69 + fSlow36) + 1.0;
		double fSlow72 = 1.0 / fSlow32;
		double fSlow73 = 1.0 - fSlow30 * (fSlow72 - fSlow30);
		double fSlow74 = fSlow30 * (fSlow72 + fSlow30) + 1.0;
		double fSlow75 = 1.0 / fSlow26;
		double fSlow76 = 1.0 - fSlow24 * (fSlow75 - fSlow24);
		double fSlow77 = fSlow24 * (fSlow75 + fSlow24) + 1.0;
		double fSlow78 = 1.0 / fSlow20;
		double fSlow79 = 1.0 - fSlow18 * (fSlow78 - fSlow18);
		double fSlow80 = fSlow18 * (fSlow78 + fSlow18) + 1.0;
		double fSlow81 = 1.0 / fSlow14;
		double fSlow82 = 1.0 - fSlow12 * (fSlow81 - fSlow12);
		double fSlow83 = fSlow12 * (fSlow81 + fSlow12) + 1.0;
		double fSlow84 = 1.0 / fSlow8;
		double fSlow85 = 1.0 - fSlow6 * (fSlow84 - fSlow6);
		double fSlow86 = fSlow6 * (fSlow84 + fSlow6) + 1.0;
		double fSlow87 = 1.0 / fSlow2;
		double fSlow88 = 1.0 - fSlow0 * (fSlow87 - fSlow0);
		double fSlow89 = fSlow0 * (fSlow87 + fSlow0) + 1.0;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = fSlow1 * fRec0[1];
			double fTemp1 = fSlow7 * fRec1[1];
			double fTemp2 = fSlow13 * fRec2[1];
			double fTemp3 = fSlow19 * fRec3[1];
			double fTemp4 = fSlow25 * fRec4[1];
			double fTemp5 = fSlow31 * fRec5[1];
			double fTemp6 = fSlow37 * fRec6[1];
			double fTemp7 = fSlow43 * fRec7[1];
			double fTemp8 = fSlow49 * fRec8[1];
			double fTemp9 = fSlow55 * fRec9[1];
			fRec9[0] = static_cast<double>(input0[i0]) - fSlow59 * (fSlow58 * fRec9[2] + fTemp9);
			fRec8[0] = fSlow59 * (fTemp9 + fSlow62 * fRec9[0] + fSlow61 * fRec9[2]) - fSlow53 * (fSlow52 * fRec8[2] + fTemp8);
			fRec7[0] = fSlow53 * (fTemp8 + fSlow65 * fRec8[0] + fSlow64 * fRec8[2]) - fSlow47 * (fSlow46 * fRec7[2] + fTemp7);
			fRec6[0] = fSlow47 * (fTemp7 + fSlow68 * fRec7[0] + fSlow67 * fRec7[2]) - fSlow41 * (fSlow40 * fRec6[2] + fTemp6);
			fRec5[0] = fSlow41 * (fTemp6 + fSlow71 * fRec6[0] + fSlow70 * fRec6[2]) - fSlow35 * (fSlow34 * fRec5[2] + fTemp5);
			fRec4[0] = fSlow35 * (fTemp5 + fSlow74 * fRec5[0] + fSlow73 * fRec5[2]) - fSlow29 * (fSlow28 * fRec4[2] + fTemp4);
			fRec3[0] = fSlow29 * (fTemp4 + fSlow77 * fRec4[0] + fSlow76 * fRec4[2]) - fSlow23 * (fSlow22 * fRec3[2] + fTemp3);
			fRec2[0] = fSlow23 * (fTemp3 + fSlow80 * fRec3[0] + fSlow79 * fRec3[2]) - fSlow17 * (fSlow16 * fRec2[2] + fTemp2);
			fRec1[0] = fSlow17 * (fTemp2 + fSlow83 * fRec2[0] + fSlow82 * fRec2[2]) - fSlow11 * (fSlow10 * fRec1[2] + fTemp1);
			fRec0[0] = fSlow11 * (fTemp1 + fSlow86 * fRec1[0] + fSlow85 * fRec1[2]) - fSlow5 * (fSlow4 * fRec0[2] + fTemp0);
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow5 * (fTemp0 + fSlow89 * fRec0[0] + fSlow88 * fRec0[2]));
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
