/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Rangemaster"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxRangem -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxRangem_H__
#define  __GxRangem_H__

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
#define FAUSTCLASS GxRangem
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

static double GxRangem_faustpower2_f(double value) {
	return value * value;
}

class GxRangem : public chdsp {
	
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
	FAUSTFLOAT fVslider1;
	double fRec1[4];
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fConst31;
	
 public:
	GxRangem() {
	}
	
	GxRangem(const GxRangem&) = default;
	
	virtual ~GxRangem() = default;
	
	GxRangem& operator=(const GxRangem&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Tone Control");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxRangem -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "High Frequency Booster");
		m->declare("filename", "gx-rangem.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "rangem");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Rangemaster");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "Rangemaster");
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
		fConst1 = 9.6103977657166e-17 * fConst0;
		fConst2 = fConst0 * (fConst0 * (-1.29828683375003e-11 - fConst1) + -3.77055394062117e-11) + -6.47756445986258e-23;
		fConst3 = 6.03049472237275e-17 * fConst0;
		fConst4 = fConst0 * (fConst0 * (1.26333088694976e-11 - fConst3) + 1.95791953523286e-11);
		fConst5 = 4.37071753217797e-15 * fConst0;
		fConst6 = fConst0 * (fConst0 * (fConst5 + 2.23510911173716e-10) + 1.20972656728663e-08);
		fConst7 = 8.31466608544754e-13 * fConst0;
		fConst8 = 2.24531902904193e-12 - fConst7;
		fConst9 = 8.32852386225662e-13 * fConst0;
		fConst10 = fConst9 + -2.24906122742367e-12;
		fConst11 = fConst0 * (fConst0 * (fConst1 + -1.29828683375003e-11) + 3.77055394062117e-11) + -6.47756445986258e-23;
		fConst12 = fConst0 * (fConst0 * (fConst3 + 1.26333088694976e-11) + -1.95791953523286e-11);
		fConst13 = fConst0 * (fConst0 * (2.23510911173716e-10 - fConst5) + -1.20972656728663e-08);
		fConst14 = 2.88311932971498e-16 * fConst0;
		fConst15 = fConst0 * (fConst0 * (1.29828683375003e-11 - fConst14) + 3.77055394062117e-11) + -1.94326933795877e-22;
		fConst16 = 1.80914841671183e-16 * fConst0;
		fConst17 = fConst0 * (fConst0 * (-1.26333088694976e-11 - fConst16) + -1.95791953523286e-11);
		fConst18 = 1.31121525965339e-14 * fConst0;
		fConst19 = fConst0 * (fConst0 * (fConst18 + -2.23510911173716e-10) + -1.20972656728663e-08);
		fConst20 = fConst0 * (fConst0 * (fConst14 + 1.29828683375003e-11) + -3.77055394062117e-11) + -1.94326933795877e-22;
		fConst21 = fConst0 * (fConst0 * (fConst16 + -1.26333088694976e-11) + 1.95791953523286e-11);
		fConst22 = fConst0 * (fConst0 * (-2.23510911173716e-10 - fConst18) + 1.20972656728663e-08);
		fConst23 = 2.49439982563426e-12 * fConst0;
		fConst24 = fConst23 + -2.24531902904193e-12;
		fConst25 = 2.49855715867699e-12 * fConst0;
		fConst26 = 2.24906122742367e-12 - fConst25;
		fConst27 = -2.24531902904193e-12 - fConst23;
		fConst28 = fConst25 + 2.24906122742367e-12;
		fConst29 = fConst7 + 2.24531902904193e-12;
		fConst30 = -2.24906122742367e-12 - fConst9;
		fConst31 = GxRangem_faustpower2_f(fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(1e+02);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 4; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0;
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
	
	virtual GxRangem* clone() {
		return new GxRangem(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Rangemaster");
		ui_interface->declare(&fVslider0, "name", "Boost");
		ui_interface->addVerticalSlider("Boost", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider1, "name", "wet/dry");
		ui_interface->declare(&fVslider1, "tooltip", "percentage of processed signal in output signal");
		ui_interface->addVerticalSlider("wet_dry", &fVslider1, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * (1.0 - static_cast<double>(fVslider0));
		double fSlow1 = 0.01 * static_cast<double>(fVslider1);
		double fSlow2 = 1.0 - fSlow1;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			double fTemp0 = fConst6 + fRec0[0] * (fConst4 + fConst2 * fRec0[0] + 3.36357739377656e-23) + 4.663130715952e-08;
			double fTemp1 = static_cast<double>(input0[i0]);
			fRec1[0] = fSlow1 * fTemp1 - (fRec1[1] * (fConst22 + fRec0[0] * (fConst21 + fConst20 * fRec0[0] + 1.00907321813297e-22) + 1.3989392147856e-07) + fRec1[2] * (fConst19 + fRec0[0] * (fConst17 + fConst15 * fRec0[0] + 1.00907321813297e-22) + 1.3989392147856e-07) + fRec1[3] * (fConst13 + fRec0[0] * (fConst12 + fConst11 * fRec0[0] + 3.36357739377656e-23) + 4.663130715952e-08)) / fTemp0;
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow2 * fTemp1 + fConst31 * ((fRec1[0] * (fConst30 + fConst29 * fRec0[0]) + fRec1[1] * (fConst28 + fConst27 * fRec0[0]) + fRec1[2] * (fConst26 + fConst24 * fRec0[0]) + fRec1[3] * (fConst10 + fConst8 * fRec0[0])) / fTemp0));
			fRec0[1] = fRec0[0];
			for (int j0 = 3; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec1[j0] = fRec1[faust_wrap_sub(j0, 1)];
			}
		}
	}

};

#endif
