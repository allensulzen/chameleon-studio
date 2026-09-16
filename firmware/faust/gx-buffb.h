/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Buffer Booster"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBuffb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxBuffb_H__
#define  __GxBuffb_H__

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
#define FAUSTCLASS GxBuffb
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

static double GxBuffb_faustpower3_f(double value) {
	return value * value * value;
}
static double GxBuffb_faustpower2_f(double value) {
	return value * value;
}
static double GxBuffb_faustpower4_f(double value) {
	return value * value * value * value;
}

class GxBuffb : public chdsp {
	
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
	double fRec1[5];
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
	FAUSTFLOAT fVslider1;
	double fRec2[2];
	
 public:
	GxBuffb() {
	}
	
	GxBuffb(const GxBuffb&) = default;
	
	virtual ~GxBuffb() = default;
	
	GxBuffb& operator=(const GxBuffb&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Tone Control");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBuffb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Buffer Booster");
		m->declare("filename", "gx-buffb.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "buffb");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Buffer Booster");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "Buffer Boost");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 2.88228949502788e-20 * fConst0;
		fConst2 = fConst0 * (fConst0 * (-3.1353376203179e-14 - fConst1) + -9.57866164137552e-13) + -4.00199516463868e-12;
		fConst3 = 3.01067992749548e-20 * fConst0;
		fConst4 = fConst0 * (fConst0 * (fConst3 + 3.28941142776728e-14) + 4.37053187936949e-12) + 2.10094331121784e-11;
		fConst5 = 6.84245438067155e-19 * fConst0;
		fConst6 = fConst0 * (fConst5 + 7.47593506310745e-13) + 9.93302699856702e-11;
		fConst7 = 2.84995035519639e-20 * fConst0;
		fConst8 = 6.45077038297955e-16 - fConst7;
		fConst9 = 2.97690025361778e-20 * fConst0;
		fConst10 = fConst9 + 3.02300377935444e-13;
		fConst11 = GxBuffb_faustpower3_f(fConst0);
		fConst12 = 6.76568239458587e-19 * fConst0;
		fConst13 = GxBuffb_faustpower2_f(fConst0);
		fConst14 = fConst13 * (-6.87046313489645e-12 - fConst12);
		fConst15 = fConst0 * (fConst0 * (3.1353376203179e-14 - fConst1) + -9.57866164137552e-13) + 4.00199516463868e-12;
		fConst16 = fConst0 * (fConst0 * (fConst3 + -3.28941142776728e-14) + 4.37053187936949e-12) + -2.10094331121784e-11;
		fConst17 = fConst0 * (7.47593506310745e-13 - fConst5) + -9.93302699856702e-11;
		fConst18 = 1.15291579801115e-19 * fConst0;
		fConst19 = fConst13 * (fConst18 + -6.27067524063581e-14) + 8.00399032927735e-12;
		fConst20 = 1.20427197099819e-19 * fConst0;
		fConst21 = fConst13 * (6.57882285553455e-14 - fConst20) + -4.20188662243568e-11;
		fConst22 = 1.36849087613431e-18 * fConst13;
		fConst23 = fConst22 + -1.9866053997134e-10;
		fConst24 = 1.9157323282751e-12 - 1.72937369701673e-19 * fConst13;
		fConst25 = 1.80640795649729e-19 * fConst13 + -8.74106375873897e-12;
		fConst26 = fConst13 * (fConst18 + 6.27067524063581e-14) + -8.00399032927735e-12;
		fConst27 = fConst13 * (-6.57882285553455e-14 - fConst20) + 4.20188662243568e-11;
		fConst28 = 1.9866053997134e-10 - fConst22;
		fConst29 = 1.13998014207856e-19 * fConst0;
		fConst30 = fConst29 + -1.29015407659591e-15;
		fConst31 = 1.19076010144711e-19 * fConst0;
		fConst32 = -6.04600755870888e-13 - fConst31;
		fConst33 = GxBuffb_faustpower4_f(fConst0);
		fConst34 = 1.37409262697929e-11 * fConst13;
		fConst35 = fConst29 + 1.29015407659591e-15;
		fConst36 = 6.04600755870888e-13 - fConst31;
		fConst37 = -6.45077038297955e-16 - fConst7;
		fConst38 = fConst9 + -3.02300377935444e-13;
		fConst39 = fConst13 * (fConst12 + -6.87046313489645e-12);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 5; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
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
	
	virtual GxBuffb* clone() {
		return new GxBuffb(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Buffer Booster");
		ui_interface->declare(&fVslider0, "name", "Intensity");
		ui_interface->addVerticalSlider("Intensity", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider1, "name", "Volume");
		ui_interface->addVerticalSlider("Volume", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * static_cast<double>(fVslider0);
		double fSlow1 = 0.007000000000000006 * static_cast<double>(fVslider1);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			double fTemp0 = fConst0 * (fConst6 + fRec0[0] * (fConst4 + fConst2 * fRec0[0])) + 4.77487116185873e-10;
			fRec1[0] = static_cast<double>(input0[i0]) - (fRec1[1] * (fConst0 * (fConst28 + fRec0[0] * (fConst27 + fConst26 * fRec0[0])) + 1.90994846474349e-09) + fRec1[2] * (fConst13 * (fRec0[0] * (fConst25 + fConst24 * fRec0[0]) + -1.49518701262149e-12) + 2.86492269711524e-09) + fRec1[3] * (fConst0 * (fConst23 + fRec0[0] * (fConst21 + fConst19 * fRec0[0])) + 1.90994846474349e-09) + fRec1[4] * (fConst0 * (fConst17 + fRec0[0] * (fConst16 + fConst15 * fRec0[0])) + 4.77487116185873e-10)) / fTemp0;
			fRec2[0] = fSlow1 + 0.993 * fRec2[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fRec2[0] * (fRec1[0] * (fConst39 + fConst11 * fRec0[0] * (fConst38 + fConst37 * fRec0[0])) + fConst11 * fRec1[1] * (fRec0[0] * (fConst36 + fConst35 * fRec0[0]) + -1.35313647891717e-18) + fRec1[2] * (fConst34 + fConst33 * fRec0[0] * (1.78614015217067e-19 - 1.70997021311783e-19 * fRec0[0])) + fConst11 * fRec1[3] * (fRec0[0] * (fConst32 + fConst30 * fRec0[0]) + 1.35313647891717e-18) + fRec1[4] * (fConst14 + fConst11 * fRec0[0] * (fConst10 + fConst8 * fRec0[0]))) / fTemp0);
			fRec0[1] = fRec0[0];
			for (int j0 = 4; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec1[j0] = fRec1[faust_wrap_sub(j0, 1)];
			}
			fRec2[1] = fRec2[0];
		}
	}

};

#endif
