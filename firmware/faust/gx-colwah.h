/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "ColorSound Wah"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxColwah -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxColwah_H__
#define  __GxColwah_H__

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
#define FAUSTCLASS GxColwah
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

static double GxColwah_faustpower2_f(double value) {
	return value * value;
}
static double GxColwah_faustpower3_f(double value) {
	return value * value * value;
}

class GxColwah : public chdsp {
	
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
	FAUSTFLOAT fVslider3;
	double fConst34;
	double fConst35;
	double fConst36;
	double fVec1[2];
	double fConst37;
	double fConst38;
	double fRec8[2];
	double fRec7[5];
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
	
 public:
	GxColwah() {
	}
	
	GxColwah(const GxColwah&) = default;
	
	virtual ~GxColwah() = default;
	
	GxColwah& operator=(const GxColwah&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Guitar Effects");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxColwah -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "ColorSound Wah");
		m->declare("filename", "gx-colwah.dsp");
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
		m->declare("id", "colwah");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "ColorSound Wah");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "ColorSound Wah");
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
		fConst6 = 6.9713352578405e-20 * fConst0;
		fConst7 = fConst0 * (fConst0 * (-5.83030654431973e-18 - fConst6) + -2.29684974478901e-14) + -2.35672055328543e-13;
		fConst8 = 3.97687174092932e-19 * fConst0;
		fConst9 = fConst0 * (fConst0 * (fConst8 + 2.70551577331849e-17) + 1.90255378851155e-14) + 7.09396691797023e-13;
		fConst10 = 6.54938497087849e-21 * fConst0;
		fConst11 = fConst0 * (fConst0 * (fConst10 + 5.15430968663743e-18) + 1.2663530557943e-13) + 3.94769224069978e-12;
		fConst12 = 8.31249052050881e-22 * fConst0;
		fConst13 = GxColwah_faustpower2_f(fConst0);
		fConst14 = fConst13 * (fConst0 * (fConst12 + -1.912505767204e-17) + 2.9122542229415e-14);
		fConst15 = 8.22579827731233e-22 * fConst0;
		fConst16 = fConst0 * (fConst0 * (fConst0 * (1.89445663105706e-17 - fConst15) + -2.92311751105741e-14) + 6.25519484069141e-13);
		fConst17 = 2.66926675132622e-21 * fConst0;
		fConst18 = fConst0 * (fConst0 * (fConst0 * (8.43534115306834e-17 - fConst17) + -1.31405791553819e-13) + 6.81633101368958e-13);
		fConst19 = fConst0 * (fConst0 * (5.83030654431973e-18 - fConst6) + -2.29684974478901e-14) + 2.35672055328543e-13;
		fConst20 = fConst0 * (fConst0 * (fConst8 + -2.70551577331849e-17) + 1.90255378851155e-14) + -7.09396691797023e-13;
		fConst21 = fConst0 * (fConst0 * (fConst10 + -5.15430968663743e-18) + 1.2663530557943e-13) + -3.94769224069978e-12;
		fConst22 = 2.7885341031362e-19 * fConst0;
		fConst23 = fConst13 * (fConst22 + -1.16606130886395e-17) + 4.71344110657085e-13;
		fConst24 = 1.59074869637173e-18 * fConst0;
		fConst25 = fConst13 * (5.41103154663699e-17 - fConst24) + -1.41879338359405e-12;
		fConst26 = 2.6197539883514e-20 * fConst0;
		fConst27 = fConst13 * (1.03086193732749e-17 - fConst26) + -7.89538448139956e-12;
		fConst28 = 4.59369948957802e-14 - 4.1828011547043e-19 * fConst13;
		fConst29 = 2.38612304455759e-18 * fConst13 + -3.8051075770231e-14;
		fConst30 = 3.9296309825271e-20 * fConst13 + -2.5327061115886e-13;
		fConst31 = fConst13 * (fConst22 + 1.16606130886395e-17) + -4.71344110657085e-13;
		fConst32 = fConst13 * (-5.41103154663699e-17 - fConst24) + 1.41879338359405e-12;
		fConst33 = fConst13 * (-1.03086193732749e-17 - fConst26) + 7.89538448139956e-12;
		fConst34 = 491.77839701345533 / fConst0;
		fConst35 = fConst34 + 1.0;
		fConst36 = 0.01 / fConst35;
		fConst37 = 1.0 - fConst34;
		fConst38 = 1.0 / fConst35;
		fConst39 = 3.32499620820352e-21 * fConst0;
		fConst40 = GxColwah_faustpower3_f(fConst0);
		fConst41 = fConst40 * (3.825011534408e-17 - fConst39);
		fConst42 = 3.29031931092493e-21 * fConst0;
		fConst43 = fConst0 * (fConst13 * (fConst42 + -3.78891326211413e-17) + 1.25103896813828e-12);
		fConst44 = 1.06770670053049e-20 * fConst0;
		fConst45 = fConst0 * (fConst13 * (fConst44 + -1.68706823061367e-16) + 1.36326620273792e-12);
		fConst46 = 4.98749431230529e-21 * fConst13 + -5.824508445883e-14;
		fConst47 = 5.84623502211483e-14 - 4.9354789663874e-21 * fConst13;
		fConst48 = 2.62811583107638e-13 - 1.60156005079573e-20 * fConst13;
		fConst49 = fConst40 * (-3.825011534408e-17 - fConst39);
		fConst50 = fConst0 * (fConst13 * (fConst42 + 3.78891326211413e-17) + -1.25103896813828e-12);
		fConst51 = fConst0 * (fConst13 * (fConst44 + 1.68706823061367e-16) + -1.36326620273792e-12);
		fConst52 = fConst13 * (fConst0 * (fConst12 + 1.912505767204e-17) + 2.9122542229415e-14);
		fConst53 = fConst0 * (fConst0 * (fConst0 * (-1.89445663105706e-17 - fConst15) + -2.92311751105741e-14) + -6.25519484069141e-13);
		fConst54 = fConst0 * (fConst0 * (fConst0 * (-8.43534115306834e-17 - fConst17) + -1.31405791553819e-13) + -6.81633101368958e-13);
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
	
	virtual GxColwah* clone() {
		return new GxColwah(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("ColorSound Wah");
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
		double fSlow4 = 4.748558434412966e-05 * (std::exp(5.0 * (1.0 - std::max<double>(0.01, static_cast<double>(fVslider2)))) + -1.0);
		double fSlow5 = static_cast<double>(fVslider3);
		double fSlow6 = fConst36 * fSlow5;
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
			fRec3[0] = 0.007000000000000006 * std::max<double>(0.02, std::min<double>(1.0, fRec4[0])) + 0.993 * fRec3[1];
			fRec6[0] = fSlow4 + 0.993 * fRec6[1];
			double fTemp2 = ((iSlow1) ? fRec6[0] : ((iSlow2) ? fRec3[0] : 1.0 - std::max<double>(0.02, std::min<double>(0.98, 0.5 * (fRec0[0] + 1.0)))));
			double fTemp3 = fConst0 * (fConst11 + fTemp2 * (fConst9 + fConst7 * fTemp2)) + 1.63948058636323e-11;
			fVec1[0] = fSlow6 * fTemp0;
			fRec8[0] = fConst38 * (fSlow7 * fTemp0 + fConst37 * fRec8[1]) - fVec1[1];
			fRec7[0] = fRec8[0] - (fRec7[1] * (fConst0 * (fConst33 + fTemp2 * (fConst32 + fConst31 * fTemp2)) + 6.55792234545291e-11) + fRec7[2] * (fConst13 * (fConst30 + fTemp2 * (fConst29 + fConst28 * fTemp2)) + 9.83688351817936e-11) + fRec7[3] * (fConst0 * (fConst27 + fTemp2 * (fConst25 + fConst23 * fTemp2)) + 6.55792234545291e-11) + fRec7[4] * (fConst0 * (fConst21 + fTemp2 * (fConst20 + fConst19 * fTemp2)) + 1.63948058636323e-11)) / fTemp3;
			output0[i0] = static_cast<FAUSTFLOAT>(fSlow8 * fTemp0 + (fRec7[0] * (fConst54 + fTemp2 * (fConst53 + fConst52 * fTemp2)) + fRec7[1] * (fConst51 + fTemp2 * (fConst50 + fConst49 * fTemp2)) + fConst13 * fRec7[2] * (fConst48 + fTemp2 * (fConst47 + fConst46 * fTemp2)) + fRec7[3] * (fConst45 + fTemp2 * (fConst43 + fConst41 * fTemp2)) + fRec7[4] * (fConst18 + fTemp2 * (fConst16 + fConst14 * fTemp2))) / fTemp3);
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
