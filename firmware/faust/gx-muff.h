/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Muff"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMuff -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxMuff_H__
#define  __GxMuff_H__

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
#define FAUSTCLASS GxMuff
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

static double GxMuff_faustpower2_f(double value) {
	return value * value;
}
static double GxMuff_faustpower3_f(double value) {
	return value * value * value;
}
static double GxMuff_faustpower4_f(double value) {
	return value * value * value * value;
}

class GxMuff : public chdsp {
	
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
	double fRec1[7];
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
	double fConst61;
	double fConst62;
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	
 public:
	GxMuff() {
	}
	
	GxMuff(const GxMuff&) = default;
	
	virtual ~GxMuff() = default;
	
	GxMuff& operator=(const GxMuff&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Fuzz");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMuff -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Muff");
		m->declare("filename", "gx-muff.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "muff");
		m->declare("insert_p", "tranyclipper");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Muff");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "Muff");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("volume_p", "Volume");
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
		fConst1 = 5.75452574944698e-29 * fConst0;
		fConst2 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-7.27469124190795e-25 - fConst1) + -2.36761929650589e-21) + -2.15665382234029e-18) + -5.3389212423117e-16) + -3.40686364113531e-15;
		fConst3 = 5.77317651704237e-29 * fConst0;
		fConst4 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst3 + 7.91492198040202e-25) + 2.5773097315087e-21) + 2.02385759012812e-18) + 5.21709009014916e-16) + 3.33278467477534e-15;
		fConst5 = 4.64196013276193e-29 * fConst0;
		fConst6 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst5 + 7.1140905248404e-25) + 2.87245155338884e-21) + 3.60543982135142e-18) + 8.93675308928682e-16) + 1.16723639524299e-14;
		fConst7 = 1.29955117406144e-31 * fConst0;
		fConst8 = fConst0 * (fConst0 * (-3.73173380397863e-25 - fConst7) + 1.11415567049164e-24) + 3.19936025718332e-18;
		fConst9 = 5.90705079118838e-30 * fConst0;
		fConst10 = fConst0 * (fConst0 * (-1.6962426381721e-23 - fConst9) + 5.06434395678016e-23) + 1.45425466235606e-16;
		fConst11 = 1.38925083422393e-26 * fConst0;
		fConst12 = fConst0 * (fConst11 + 3.98287967295002e-20) + -1.84690342119219e-16;
		fConst13 = 3.05635183529265e-28 * fConst0;
		fConst14 = fConst0 * (fConst13 + 8.76233528049005e-22) + -4.06318752662282e-18;
		fConst15 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (7.27469124190795e-25 - fConst1) + -2.36761929650589e-21) + 2.15665382234029e-18) + -5.3389212423117e-16) + 3.40686364113531e-15;
		fConst16 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst3 + -7.91492198040202e-25) + 2.5773097315087e-21) + -2.02385759012812e-18) + 5.21709009014916e-16) + -3.33278467477534e-15;
		fConst17 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst5 + -7.1140905248404e-25) + 2.87245155338884e-21) + -3.60543982135142e-18) + 8.93675308928682e-16) + -1.16723639524299e-14;
		fConst18 = 3.45271544966819e-28 * fConst0;
		fConst19 = GxMuff_faustpower2_f(fConst0);
		fConst20 = fConst0 * (fConst19 * (fConst0 * (fConst18 + -2.90987649676318e-24) + 4.73523859301178e-21) + -1.06778424846234e-15) + 1.36274545645413e-14;
		fConst21 = 3.46390591022542e-28 * fConst0;
		fConst22 = fConst0 * (fConst19 * (fConst0 * (3.16596879216081e-24 - fConst21) + -5.15461946301739e-21) + 1.04341801802983e-15) + -1.33311386991013e-14;
		fConst23 = 2.78517607965716e-28 * fConst0;
		fConst24 = fConst0 * (fConst19 * (fConst0 * (2.84563620993616e-24 - fConst23) + -5.74490310677768e-21) + 1.78735061785736e-15) + -4.66894558097195e-14;
		fConst25 = 8.63178862417047e-28 * fConst0;
		fConst26 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (3.63734562095397e-24 - fConst25) + 2.36761929650589e-21) + -6.46996146702087e-18) + 5.3389212423117e-16) + 1.70343182056766e-14;
		fConst27 = 8.65976477556356e-28 * fConst0;
		fConst28 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst27 + -3.95746099020101e-24) + -2.5773097315087e-21) + 6.07157277038437e-18) + -5.21709009014916e-16) + -1.66639233738767e-14;
		fConst29 = 6.96294019914289e-28 * fConst0;
		fConst30 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst29 + -3.5570452624202e-24) + -2.87245155338884e-21) + 1.08163194640543e-17) + -8.93675308928682e-16) + -5.83618197621494e-14;
		fConst31 = fConst19 * (1.1509051498894e-27 * fConst19 + -9.47047718602356e-21) + 2.13556849692468e-15;
		fConst32 = fConst19 * (1.03092389260348e-20 - 1.15463530340847e-27 * fConst19) + -2.08683603605967e-15;
		fConst33 = fConst19 * (1.14898062135554e-20 - 9.28392026552386e-28 * fConst19) + -3.57470123571473e-15;
		fConst34 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-3.63734562095397e-24 - fConst25) + 2.36761929650589e-21) + 6.46996146702087e-18) + 5.3389212423117e-16) + -1.70343182056766e-14;
		fConst35 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst27 + 3.95746099020101e-24) + -2.5773097315087e-21) + -6.07157277038437e-18) + -5.21709009014916e-16) + 1.66639233738767e-14;
		fConst36 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst29 + 3.5570452624202e-24) + -2.87245155338884e-21) + -1.08163194640543e-17) + -8.93675308928682e-16) + 5.83618197621494e-14;
		fConst37 = fConst0 * (fConst19 * (fConst0 * (fConst18 + 2.90987649676318e-24) + 4.73523859301178e-21) + -1.06778424846234e-15) + -1.36274545645413e-14;
		fConst38 = fConst0 * (fConst19 * (fConst0 * (-3.16596879216081e-24 - fConst21) + -5.15461946301739e-21) + 1.04341801802983e-15) + 1.33311386991013e-14;
		fConst39 = fConst0 * (fConst19 * (fConst0 * (-2.84563620993616e-24 - fConst23) + -5.74490310677768e-21) + 1.78735061785736e-15) + 4.66894558097195e-14;
		fConst40 = GxMuff_faustpower3_f(fConst0);
		fConst41 = 7.79730704436866e-31 * fConst0;
		fConst42 = fConst0 * (fConst41 + 1.49269352159145e-24) + -2.22831134098327e-24;
		fConst43 = 3.54423047471303e-29 * fConst0;
		fConst44 = fConst0 * (fConst43 + 6.78497055268842e-23) + -1.01286879135603e-22;
		fConst45 = 5.55700333689573e-26 * fConst0;
		fConst46 = -7.96575934590005e-20 - fConst45;
		fConst47 = 1.22254073411706e-27 * fConst0;
		fConst48 = -1.75246705609801e-21 - fConst47;
		fConst49 = GxMuff_faustpower4_f(fConst0);
		fConst50 = 1.94932676109216e-30 * fConst0;
		fConst51 = fConst0 * (fConst0 * (-1.86586690198932e-24 - fConst50) + -1.11415567049164e-24) + -9.59808077154997e-18;
		fConst52 = 8.86057618678257e-29 * fConst0;
		fConst53 = fConst0 * (fConst0 * (-8.48121319086052e-23 - fConst52) + -5.06434395678016e-23) + -4.36276398706817e-16;
		fConst54 = 6.94625417111967e-26 * fConst0;
		fConst55 = fConst0 * (fConst54 + -3.98287967295002e-20) + 5.54071026357658e-16;
		fConst56 = 1.52817591764633e-27 * fConst0;
		fConst57 = fConst0 * (fConst56 + -8.76233528049005e-22) + 1.21895625798685e-17;
		fConst58 = 2.59910234812289e-30 * fConst19 + 4.45662268196654e-24;
		fConst59 = 1.18141015823768e-28 * fConst19 + 2.02573758271206e-22;
		fConst60 = fConst0 * (fConst0 * (1.86586690198932e-24 - fConst50) + -1.11415567049164e-24) + 9.59808077154997e-18;
		fConst61 = fConst0 * (fConst0 * (8.48121319086052e-23 - fConst52) + -5.06434395678016e-23) + 4.36276398706817e-16;
		fConst62 = fConst0 * (-3.98287967295002e-20 - fConst54) + -5.54071026357658e-16;
		fConst63 = fConst0 * (-8.76233528049005e-22 - fConst56) + -1.21895625798685e-17;
		fConst64 = fConst0 * (fConst41 + -1.49269352159145e-24) + -2.22831134098327e-24;
		fConst65 = fConst0 * (fConst43 + -6.78497055268842e-23) + -1.01286879135603e-22;
		fConst66 = fConst45 + -7.96575934590005e-20;
		fConst67 = fConst47 + -1.75246705609801e-21;
		fConst68 = fConst0 * (fConst0 * (3.73173380397863e-25 - fConst7) + 1.11415567049164e-24) + -3.19936025718332e-18;
		fConst69 = fConst0 * (fConst0 * (1.6962426381721e-23 - fConst9) + 5.06434395678016e-23) + -1.45425466235606e-16;
		fConst70 = fConst0 * (3.98287967295002e-20 - fConst11) + 1.84690342119219e-16;
		fConst71 = fConst0 * (8.76233528049005e-22 - fConst13) + 4.06318752662282e-18;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 7; l1 = faust_wrap_add(l1, 1)) {
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
	
	virtual GxMuff* clone() {
		return new GxMuff(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Muff");
		ui_interface->declare(&fVslider0, "name", "Tone");
		ui_interface->addVerticalSlider("Tone", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * static_cast<double>(fVslider0);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			double fTemp0 = fConst0 * (fConst6 + fRec0[0] * (fConst4 + fConst2 * fRec0[0])) + 3.91224189243262e-14;
			fRec1[0] = static_cast<double>(input0[i0]) - (fRec1[1] * (fConst0 * (fConst39 + fRec0[0] * (fConst38 + fConst37 * fRec0[0])) + 2.34734513545957e-13) + fRec1[2] * (fConst0 * (fConst36 + fRec0[0] * (fConst35 + fConst34 * fRec0[0])) + 5.86836283864892e-13) + fRec1[3] * (fConst19 * (fConst33 + fRec0[0] * (fConst32 + fConst31 * fRec0[0])) + 7.82448378486523e-13) + fRec1[4] * (fConst0 * (fConst30 + fRec0[0] * (fConst28 + fConst26 * fRec0[0])) + 5.86836283864892e-13) + fRec1[5] * (fConst0 * (fConst24 + fRec0[0] * (fConst22 + fConst20 * fRec0[0])) + 2.34734513545957e-13) + fRec1[6] * (fConst0 * (fConst17 + fRec0[0] * (fConst16 + fConst15 * fRec0[0])) + 3.91224189243262e-14)) / fTemp0;
			output0[i0] = static_cast<FAUSTFLOAT>((fConst40 * fRec1[0] * (fConst71 + fConst70 + fConst69 * fRec0[0] + fConst68 * fRec0[0]) + fConst49 * fRec1[1] * (fConst67 + fConst66 + fConst65 * fRec0[0] + fConst64 * fRec0[0]) + fConst40 * fRec1[2] * (fConst63 + fConst62 + fConst61 * fRec0[0] + fConst60 * fRec0[0]) + fConst49 * fRec1[3] * (fConst59 * fRec0[0] + 1.59315186918001e-19 + fConst58 * fRec0[0] + 3.50493411219602e-21) + fConst40 * fRec1[4] * (fConst57 + fConst55 + fConst53 * fRec0[0] + fConst51 * fRec0[0]) + fConst49 * fRec1[5] * (fConst48 + fConst46 + fConst44 * fRec0[0] + fConst42 * fRec0[0]) + fConst40 * fRec1[6] * (fConst14 + fConst12 + fConst10 * fRec0[0] + fConst8 * fRec0[0])) / fTemp0);
			fRec0[1] = fRec0[0];
			for (int j0 = 6; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec1[j0] = fRec1[faust_wrap_sub(j0, 1)];
			}
		}
	}

};

#endif
