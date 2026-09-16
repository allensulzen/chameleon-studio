/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Jen Wah"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxJenwah -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxJenwah_H__
#define  __GxJenwah_H__

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
#define FAUSTCLASS GxJenwah
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

static double GxJenwah_faustpower2_f(double value) {
	return value * value;
}
static double GxJenwah_faustpower3_f(double value) {
	return value * value * value;
}

class GxJenwah : public chdsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	int iVec0[2];
	FAUSTFLOAT fVslider1;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fRec2[2];
	double fRec1[2];
	double fRec0[2];
	double fConst2;
	double fConst3;
	double fConst4;
	double fRec5[2];
	double fConst5;
	double fRec4[2];
	double fRec3[2];
	FAUSTFLOAT fVslider2;
	double fRec6[2];
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
	double fConst33;
	double fConst34;
	FAUSTFLOAT fVslider3;
	double fConst35;
	double fConst36;
	double fConst37;
	double fVec1[2];
	double fConst38;
	double fConst39;
	double fRec8[2];
	double fRec7[5];
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
	
 public:
	GxJenwah() {
	}
	
	GxJenwah(const GxJenwah&) = default;
	
	virtual ~GxJenwah() = default;
	
	GxJenwah& operator=(const GxJenwah&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Guitar Effects");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxJenwah -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Jen Wah");
		m->declare("filename", "gx-jenwah.dsp");
		m->declare("filters.lib/dcblockerat:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblockerat:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblockerat:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "LicenseRef-STK-4.3");
		m->declare("id", "jenwah");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Jen Wah");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "Jen Wah");
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
		fConst1 = 0.10471975511965977 / fConst0;
		fConst2 = std::exp(-(1e+02 / fConst0));
		fConst3 = std::exp(-(1e+01 / fConst0));
		fConst4 = 1.0 - fConst3;
		fConst5 = 1.0 - fConst2;
		fConst6 = 6.99671191908366e-20 * fConst0;
		fConst7 = GxJenwah_faustpower2_f(fConst0);
		fConst8 = fConst7 * (fConst0 * (-1.39394278118629e-17 - fConst6) + -1.21159485597039e-13);
		fConst9 = 3.85720103312511e-19 * fConst0;
		fConst10 = fConst0 * (fConst0 * (fConst0 * (fConst9 + 2.77707619975565e-17) + 1.05494945988648e-13) + 2.75362467265997e-12);
		fConst11 = 1.18553561246751e-20 * fConst0;
		fConst12 = fConst0 * (fConst0 * (fConst0 * (fConst11 + 3.2569797714609e-17) + 5.79248390117011e-13) + 1.0981649358109e-11);
		fConst13 = 4.26313918949843e-21 * fConst0;
		fConst14 = fConst7 * (fConst0 * (fConst13 + -6.7438235280676e-17) + 9.21166476483994e-14);
		fConst15 = 4.24968880185418e-21 * fConst0;
		fConst16 = fConst0 * (fConst0 * (fConst0 * (6.74722090896416e-17 - fConst15) + -9.33056295237144e-14) + 1.7091597982174e-12);
		fConst17 = 7.44753937081794e-21 * fConst0;
		fConst18 = fConst0 * (fConst0 * (fConst0 * (2.45894566379345e-16 - fConst17) + -3.53469573143013e-13) + 2.09356017382726e-14);
		fConst19 = fConst7 * (fConst0 * (1.39394278118629e-17 - fConst6) + -1.21159485597039e-13);
		fConst20 = fConst0 * (fConst0 * (fConst0 * (fConst9 + -2.77707619975565e-17) + 1.05494945988648e-13) + -2.75362467265997e-12);
		fConst21 = fConst0 * (fConst0 * (fConst0 * (fConst11 + -3.2569797714609e-17) + 5.79248390117011e-13) + -1.0981649358109e-11);
		fConst22 = 2.79868476763347e-19 * fConst0;
		fConst23 = GxJenwah_faustpower3_f(fConst0);
		fConst24 = fConst23 * (fConst22 + -2.78788556237258e-17);
		fConst25 = 1.54288041325004e-18 * fConst0;
		fConst26 = fConst0 * (fConst7 * (5.55415239951129e-17 - fConst25) + -5.50724934531995e-12);
		fConst27 = 4.74214244987003e-20 * fConst0;
		fConst28 = fConst0 * (fConst7 * (6.51395954292179e-17 - fConst27) + -2.19632987162179e-11);
		fConst29 = 2.42318971194078e-13 - 4.1980271514502e-19 * fConst7;
		fConst30 = 2.31432061987506e-18 * fConst7 + -2.10989891977295e-13;
		fConst31 = 7.11321367480505e-20 * fConst7 + -1.15849678023402e-12;
		fConst32 = fConst23 * (fConst22 + 2.78788556237258e-17);
		fConst33 = fConst0 * (fConst7 * (-5.55415239951129e-17 - fConst25) + 5.50724934531995e-12);
		fConst34 = fConst0 * (fConst7 * (-6.51395954292179e-17 - fConst27) + 2.19632987162179e-11);
		fConst35 = 716.9748491638952 / fConst0;
		fConst36 = fConst35 + 1.0;
		fConst37 = 0.01 / fConst36;
		fConst38 = 1.0 - fConst35;
		fConst39 = 1.0 / fConst36;
		fConst40 = 1.70525567579937e-20 * fConst0;
		fConst41 = fConst23 * (1.34876470561352e-16 - fConst40);
		fConst42 = 1.69987552074167e-20 * fConst0;
		fConst43 = fConst0 * (fConst7 * (fConst42 + -1.34944418179283e-16) + 3.41831959643481e-12);
		fConst44 = 2.97901574832717e-20 * fConst0;
		fConst45 = fConst0 * (fConst7 * (fConst44 + -4.9178913275869e-16) + 4.18712034765452e-14);
		fConst46 = 2.55788351369906e-20 * fConst7 + -1.84233295296799e-13;
		fConst47 = 1.86611259047429e-13 - 2.54981328111251e-20 * fConst7;
		fConst48 = 7.06939146286026e-13 - 4.46852362249076e-20 * fConst7;
		fConst49 = fConst23 * (-1.34876470561352e-16 - fConst40);
		fConst50 = fConst0 * (fConst7 * (fConst42 + 1.34944418179283e-16) + -3.41831959643481e-12);
		fConst51 = fConst0 * (fConst7 * (fConst44 + 4.9178913275869e-16) + -4.18712034765452e-14);
		fConst52 = fConst7 * (fConst0 * (fConst13 + 6.7438235280676e-17) + 9.21166476483994e-14);
		fConst53 = fConst0 * (fConst0 * (fConst0 * (-6.74722090896416e-17 - fConst15) + -9.33056295237144e-14) + -1.7091597982174e-12);
		fConst54 = fConst0 * (fConst0 * (fConst0 * (-2.45894566379345e-16 - fConst17) + -3.53469573143013e-13) + -2.09356017382726e-14);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider1 = static_cast<FAUSTFLOAT>(24.0);
		fVslider2 = static_cast<FAUSTFLOAT>(0.0);
		fVslider3 = static_cast<FAUSTFLOAT>(1e+02);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec2[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec1[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec0[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec5[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec4[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec3[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec6[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fVec1[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec8[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 5; l10 = faust_wrap_add(l10, 1)) {
			fRec7[l10] = 0.0;
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
	
	virtual GxJenwah* clone() {
		return new GxJenwah(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Jen Wah");
		ui_interface->declare(&fVslider2, "alias", "");
		ui_interface->addVerticalSlider(".wah.Wah", &fVslider2, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider1, "alias", "");
		ui_interface->declare(&fVslider1, "name", "Alien Freq");
		ui_interface->declare(&fVslider1, "tooltip", "LFO in Beats per Minute");
		ui_interface->addVerticalSlider(".wah.freq", &fVslider1, FAUSTFLOAT(24.0), FAUSTFLOAT(24.0), FAUSTFLOAT(3.6e+02), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider0, "alias", "");
		ui_interface->declare(&fVslider0, "enum", "manual|auto|alien");
		ui_interface->addVerticalSlider(".wah.mode", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(2.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider3, "alias", "");
		ui_interface->declare(&fVslider3, "name", "dry/wet");
		ui_interface->addVerticalSlider(".wah.wet_dry", &fVslider3, FAUSTFLOAT(1e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = static_cast<double>(fVslider0);
		int iSlow1 = fSlow0 == 0.0;
		int iSlow2 = fSlow0 == 1.0;
		double fSlow3 = fConst1 * static_cast<double>(fVslider1);
		double fSlow4 = 0.007000000000000006 * (1.0 - static_cast<double>(fVslider2));
		double fSlow5 = static_cast<double>(fVslider3);
		double fSlow6 = fConst37 * fSlow5;
		double fSlow7 = 0.01 * fSlow5;
		double fSlow8 = 1.0 - fSlow7;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec2[0] = fRec2[1] - fSlow3 * fRec0[1];
			fRec1[0] = fSlow3 * fRec2[0] + static_cast<double>(faust_wrap_sub(1, iVec0[1])) + fRec1[1];
			fRec0[0] = fRec1[0];
			double fTemp0 = static_cast<double>(input0[i0]);
			double fTemp1 = std::fabs(fTemp0);
			fRec5[0] = std::max<double>(fTemp1, fConst3 * fRec5[1] + fConst4 * fTemp1);
			fRec4[0] = fConst5 * fRec5[0] + fConst2 * fRec4[1];
			fRec3[0] = 0.007000000000000006 * std::max<double>(0.1, std::min<double>(0.99, fRec4[0])) + 0.993 * fRec3[1];
			fRec6[0] = fSlow4 + 0.993 * fRec6[1];
			double fTemp2 = ((iSlow1) ? fRec6[0] : ((iSlow2) ? fRec3[0] : 1.0 - std::max<double>(0.01, std::min<double>(0.98, 0.5 * (fRec0[0] + 1.0)))));
			double fTemp3 = fConst12 + fTemp2 * (fConst10 + fConst8 * fTemp2) + 6.25823789240903e-13;
			fVec1[0] = fSlow6 * fTemp0;
			fRec8[0] = fConst39 * (fSlow7 * fTemp0 + fConst38 * fRec8[1]) - fVec1[1];
			fRec7[0] = fRec8[0] - (fRec7[1] * (fConst34 + fTemp2 * (fConst33 + fConst32 * fTemp2) + 2.50329515696361e-12) + fRec7[2] * (fConst7 * (fConst31 + fTemp2 * (fConst30 + fConst29 * fTemp2)) + 3.75494273544542e-12) + fRec7[3] * (fConst28 + fTemp2 * (fConst26 + fConst24 * fTemp2) + 2.50329515696361e-12) + fRec7[4] * (fConst21 + fTemp2 * (fConst20 + fConst19 * fTemp2) + 6.25823789240903e-13)) / fTemp3;
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow8 * fTemp0 + (fRec7[0] * (fConst54 + fTemp2 * (fConst53 + fConst52 * fTemp2)) + fRec7[1] * (fConst51 + fTemp2 * (fConst50 + fConst49 * fTemp2)) + fConst7 * fRec7[2] * (fConst48 + fTemp2 * (fConst47 + fConst46 * fTemp2)) + fRec7[3] * (fConst45 + fTemp2 * (fConst43 + fConst41 * fTemp2)) + fRec7[4] * (fConst18 + fTemp2 * (fConst16 + fConst14 * fTemp2))) / fTemp3);
			iVec0[1] = iVec0[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec6[1] = fRec6[0];
			fVec1[1] = fVec1[0];
			fRec8[1] = fRec8[0];
			for (int j0 = 4; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec7[j0] = fRec7[faust_wrap_sub(j0, 1)];
			}
		}
	}

};

#endif
