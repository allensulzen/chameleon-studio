/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Bass Fuzz Pedal"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBfuzz -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxBfuzz_H__
#define  __GxBfuzz_H__

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
#define FAUSTCLASS GxBfuzz
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

static double GxBfuzz_faustpower3_f(double value) {
	return value * value * value;
}
static double GxBfuzz_faustpower2_f(double value) {
	return value * value;
}

class GxBfuzz : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	double fRec0[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	FAUSTFLOAT fVslider1;
	double fRec1[2];
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
	double fConst29;
	double fConst30;
	double fConst31;
	double fConst32;
	FAUSTFLOAT fVslider2;
	double fRec2[5];
	double fConst33;
	double fConst34;
	FAUSTFLOAT fVslider3;
	double fRec3[2];
	
 public:
	GxBfuzz() {
	}
	
	GxBfuzz(const GxBfuzz&) = default;
	
	virtual ~GxBfuzz() = default;
	
	GxBfuzz& operator=(const GxBfuzz&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Fuzz");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxBfuzz -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Bass Fuzz Pedal");
		m->declare("filename", "gx-bfuzz.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "bfuzz");
		m->declare("insert_p", "tranyclipper");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Bass Fuzz Pedal");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "Bass Fuzz");
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
		fConst1 = 1.8235902618655e-20 * fConst0;
		fConst2 = fConst0 * (fConst0 * (fConst1 + 8.73857822258011e-15) + 9.51587528271067e-12) + 4.14452332248826e-10;
		fConst3 = 1.90624114055858e-19 * fConst0;
		fConst4 = fConst0 * (fConst0 * (-9.05150991318089e-15 - fConst3) + -9.57238853136628e-11) + -4.70914107604798e-09;
		fConst5 = fConst0 * (fConst0 * (fConst3 + 1.0005063720083e-14) + 1.41002006493022e-10) + 6.98583678876617e-09;
		fConst6 = fConst0 * (fConst0 * (fConst0 * (-8.82979918090661e-15 - fConst1) + -5.32286268006641e-11) + -2.42569918771087e-09) + -9.41937118747331e-10;
		fConst7 = GxBfuzz_faustpower3_f(fConst0);
		fConst8 = 1.65780932898435e-16 * fConst0;
		fConst9 = fConst8 + -8.29281439339673e-13;
		fConst10 = 7.76911913609341e-14 * fConst0;
		fConst11 = fConst10 + -3.88632527694127e-10;
		fConst12 = GxBfuzz_faustpower2_f(fConst0);
		fConst13 = fConst0 * (fConst0 * (fConst1 + -8.73857822258011e-15) + 9.51587528271067e-12) + -4.14452332248826e-10;
		fConst14 = fConst0 * (fConst0 * (9.05150991318089e-15 - fConst3) + -9.57238853136628e-11) + 4.70914107604798e-09;
		fConst15 = fConst0 * (fConst0 * (fConst3 + -1.0005063720083e-14) + 1.41002006493022e-10) + -6.98583678876617e-09;
		fConst16 = fConst0 * (fConst0 * (fConst0 * (8.82979918090661e-15 - fConst1) + -5.32286268006641e-11) + 2.42569918771087e-09) + -9.41937118747331e-10;
		fConst17 = 7.294361047462e-20 * fConst0;
		fConst18 = fConst12 * (1.74771564451602e-14 - fConst17) + -8.28904664497652e-10;
		fConst19 = 7.6249645622343e-19 * fConst0;
		fConst20 = fConst12 * (fConst19 + -1.81030198263618e-14) + 9.41828215209595e-09;
		fConst21 = fConst12 * (2.00101274401661e-14 - fConst19) + -1.39716735775323e-08;
		fConst22 = fConst0 * (fConst12 * (fConst17 + -1.76595983618132e-14) + 4.85139837542174e-09) + -3.76774847498933e-09;
		fConst23 = 1.0941541571193e-19 * fConst12;
		fConst24 = fConst23 + -1.90317505654213e-11;
		fConst25 = 1.14374468433515e-18 * fConst12;
		fConst26 = 1.91447770627326e-10 - fConst25;
		fConst27 = fConst25 + -2.82004012986045e-10;
		fConst28 = fConst12 * (1.06457253601328e-10 - fConst23) + -5.65162271248399e-09;
		fConst29 = fConst12 * (-1.74771564451602e-14 - fConst17) + 8.28904664497652e-10;
		fConst30 = fConst12 * (fConst19 + 1.81030198263618e-14) + -9.41828215209595e-09;
		fConst31 = fConst12 * (-2.00101274401661e-14 - fConst19) + 1.39716735775323e-08;
		fConst32 = fConst0 * (fConst12 * (fConst17 + 1.76595983618132e-14) + -4.85139837542174e-09) + -3.76774847498933e-09;
		fConst33 = -8.29281439339673e-13 - fConst8;
		fConst34 = -3.88632527694127e-10 - fConst10;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(0.5);
		fVslider2 = static_cast<FAUSTFLOAT>(1e+02);
		fVslider3 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 5; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec3[l3] = 0.0;
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
	
	virtual GxBfuzz* clone() {
		return new GxBfuzz(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Bass Fuzz Pedal");
		ui_interface->declare(&fVslider0, "name", "Drive");
		ui_interface->addVerticalSlider("Drive", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider3, "name", "Level");
		ui_interface->addVerticalSlider("Level", &fVslider3, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider1, "name", "Thickness");
		ui_interface->addVerticalSlider("Thickness", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider2, "name", "Wet/Dry");
		ui_interface->declare(&fVslider2, "tooltip", "percentage of processed signal in output signal");
		ui_interface->addVerticalSlider("wet_dry", &fVslider2, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * static_cast<double>(fVslider0);
		double fSlow1 = 0.007000000000000006 * static_cast<double>(fVslider1);
		double fSlow2 = 0.01 * static_cast<double>(fVslider2);
		double fSlow3 = 0.007000000000000006 * static_cast<double>(fVslider3);
		double fSlow4 = 1.0 - fSlow2;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			fRec1[0] = fSlow1 + 0.993 * fRec1[1];
			double fTemp0 = fConst6 * fRec0[0] + fConst0 * (fConst5 + fRec1[0] * (fConst4 + fConst2 * fRec0[0])) + 1.07025933546545e-08;
			double fTemp1 = 1.65780932898435e-16 * fRec0[0];
			double fTemp2 = static_cast<double>(input0[i0]);
			fRec2[0] = fSlow2 * fTemp2 - (fRec2[1] * (fConst32 * fRec0[0] + fConst0 * (fConst31 + fRec1[0] * (fConst30 + fConst29 * fRec0[0])) + 4.2810373418618e-08) + fRec2[2] * (fConst28 * fRec0[0] + fConst12 * (fConst27 + fRec1[0] * (fConst26 + fConst24 * fRec0[0])) + 6.4215560127927e-08) + fRec2[3] * (fConst22 * fRec0[0] + fConst0 * (fConst21 + fRec1[0] * (fConst20 + fConst18 * fRec0[0])) + 4.2810373418618e-08) + fRec2[4] * (fConst16 * fRec0[0] + fConst0 * (fConst15 + fRec1[0] * (fConst14 + fConst13 * fRec0[0])) + 1.07025933546545e-08)) / fTemp0;
			double fTemp3 = 3.3156186579687e-16 * fRec0[0];
			double fTemp4 = fTemp3 + 1.55382382721868e-13;
			double fTemp5 = -1.55382382721868e-13 - fTemp3;
			fRec3[0] = fSlow3 + 0.993 * fRec3[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow4 * fTemp2 + fRec3[0] * (fRec2[0] * (fConst12 * (fConst34 + fConst33 * fRec0[0]) + fConst7 * fRec1[0] * (fTemp1 + 7.76911913609341e-14)) + fConst7 * fRec2[1] * (fTemp4 + fRec1[0] * fTemp5) + fConst12 * fRec2[2] * (1.65856287867935e-12 * fRec0[0] + 7.77265055388254e-10) + fConst7 * fRec2[3] * (fTemp5 + fRec1[0] * fTemp4) + fRec2[4] * (fConst12 * (fConst11 + fConst9 * fRec0[0]) + fConst7 * fRec1[0] * (-7.76911913609341e-14 - fTemp1))) / fTemp0);
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			for (int j0 = 4; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec2[j0] = fRec2[faust_wrap_sub(j0, 1)];
			}
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
