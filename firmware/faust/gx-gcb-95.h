/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "GCB 95"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxGcb95 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxGcb95_H__
#define  __GxGcb95_H__

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
#define FAUSTCLASS GxGcb95
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

static double GxGcb95_faustpower2_f(double value) {
	return value * value;
}
static double GxGcb95_faustpower3_f(double value) {
	return value * value * value;
}

class GxGcb95 : public chdsp {
	
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
	double fVec0[2];
	double fConst32;
	double fRec2[2];
	double fRec1[5];
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
	FAUSTFLOAT fVslider1;
	double fRec3[2];
	
 public:
	GxGcb95() {
	}
	
	GxGcb95(const GxGcb95&) = default;
	
	virtual ~GxGcb95() = default;
	
	GxGcb95& operator=(const GxGcb95&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Guitar Effects");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxGcb95 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Linear filter simulating the GCB 95 ve.crybaby circuit");
		m->declare("filename", "gx-gcb-95.dsp");
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
		m->declare("id", "GCB_95");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "GCB 95");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
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
		fConst1 = 6.9672955745145e-20 * fConst0;
		fConst2 = GxGcb95_faustpower2_f(fConst0);
		fConst3 = fConst2 * (fConst0 * (-9.30061422376548e-18 - fConst1) + -9.53707992555105e-14);
		fConst4 = 3.8766476861454e-19 * fConst0;
		fConst5 = fConst0 * (fConst0 * (fConst0 * (fConst4 + 2.92076464853813e-17) + 7.68323461702748e-14) + 2.16751816489796e-12);
		fConst6 = 1.08819023657393e-20 * fConst0;
		fConst7 = fConst0 * (fConst0 * (fConst0 * (fConst6 + 2.80985481683452e-17) + 5.44712113689982e-13) + 1.29191360120173e-11);
		fConst8 = 1.96834437163512e-21 * fConst0;
		fConst9 = fConst2 * (fConst0 * (fConst8 + -5.48587515516469e-17) + 8.09470493272714e-14);
		fConst10 = 1.96653248770188e-21 * fConst0;
		fConst11 = fConst0 * (fConst0 * (fConst0 * (5.48942867863191e-17 - fConst10) + -8.21432353321142e-14) + 1.78155704878595e-12);
		fConst12 = 7.41350388334374e-21 * fConst0;
		fConst13 = fConst0 * (fConst0 * (fConst0 * (2.47418541205506e-16 - fConst12) + -3.69672787496925e-13) + 1.8397056665289e-12);
		fConst14 = fConst2 * (fConst0 * (9.30061422376548e-18 - fConst1) + -9.53707992555105e-14);
		fConst15 = fConst0 * (fConst0 * (fConst0 * (fConst4 + -2.92076464853813e-17) + 7.68323461702748e-14) + -2.16751816489796e-12);
		fConst16 = fConst0 * (fConst0 * (fConst0 * (fConst6 + -2.80985481683452e-17) + 5.44712113689982e-13) + -1.29191360120173e-11);
		fConst17 = 2.7869182298058e-19 * fConst0;
		fConst18 = GxGcb95_faustpower3_f(fConst0);
		fConst19 = fConst18 * (fConst17 + -1.8601228447531e-17);
		fConst20 = 1.55065907445816e-18 * fConst0;
		fConst21 = fConst0 * (fConst2 * (5.84152929707626e-17 - fConst20) + -4.33503632979593e-12);
		fConst22 = 4.3527609462957e-20 * fConst0;
		fConst23 = fConst0 * (fConst2 * (5.61970963366905e-17 - fConst22) + -2.58382720240347e-11);
		fConst24 = 1.90741598511021e-13 - 4.1803773447087e-19 * fConst2;
		fConst25 = 2.32598861168724e-18 * fConst2 + -1.5366469234055e-13;
		fConst26 = 6.52914141944355e-20 * fConst2 + -1.08942422737996e-12;
		fConst27 = fConst18 * (fConst17 + 1.8601228447531e-17);
		fConst28 = fConst0 * (fConst2 * (-5.84152929707626e-17 - fConst20) + 4.33503632979593e-12);
		fConst29 = fConst0 * (fConst2 * (-5.61970963366905e-17 - fConst22) + 2.58382720240347e-11);
		fConst30 = 716.6140154481191 / fConst0;
		fConst31 = 1.0 - fConst30;
		fConst32 = 1.0 / (fConst30 + 1.0);
		fConst33 = 7.87337748654046e-21 * fConst0;
		fConst34 = fConst18 * (1.09717503103294e-16 - fConst33);
		fConst35 = 7.86612995080753e-21 * fConst0;
		fConst36 = fConst0 * (fConst2 * (fConst35 + -1.09788573572638e-16) + 3.56311409757189e-12);
		fConst37 = 2.9654015533375e-20 * fConst0;
		fConst38 = fConst0 * (fConst2 * (fConst37 + -4.94837082411013e-16) + 3.67941133305779e-12);
		fConst39 = 1.18100662298107e-20 * fConst2 + -1.61894098654543e-13;
		fConst40 = 1.64286470664228e-13 - 1.17991949262113e-20 * fConst2;
		fConst41 = 7.39345574993849e-13 - 4.44810233000624e-20 * fConst2;
		fConst42 = fConst18 * (-1.09717503103294e-16 - fConst33);
		fConst43 = fConst0 * (fConst2 * (fConst35 + 1.09788573572638e-16) + -3.56311409757189e-12);
		fConst44 = fConst0 * (fConst2 * (fConst37 + 4.94837082411013e-16) + -3.67941133305779e-12);
		fConst45 = fConst2 * (fConst0 * (fConst8 + 5.48587515516469e-17) + 8.09470493272714e-14);
		fConst46 = fConst0 * (fConst0 * (fConst0 * (-5.48942867863191e-17 - fConst10) + -8.21432353321142e-14) + -1.78155704878595e-12);
		fConst47 = fConst0 * (fConst0 * (fConst0 * (-2.47418541205506e-16 - fConst12) + -3.69672787496925e-13) + -1.8397056665289e-12);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fVec0[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 5; l3 = faust_wrap_add(l3, 1)) {
			fRec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec3[l4] = 0.0;
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
	
	virtual GxGcb95* clone() {
		return new GxGcb95(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("GCB 95");
		ui_interface->addVerticalSlider("Volume", &fVslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-2e+01), FAUSTFLOAT(4.0), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider0, "name", "Wah");
		ui_interface->addVerticalSlider("hotpotz", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 4.748558434412966e-05 * (std::exp(5.0 * (1.0 - static_cast<double>(fVslider0))) + -1.0);
		double fSlow1 = 0.007000000000000006 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider1));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			double fTemp0 = fConst7 + fRec0[0] * (fConst5 + fConst3 * fRec0[0]) + 4.92617764749537e-11;
			double fTemp1 = static_cast<double>(input0[i0]);
			fVec0[0] = fTemp1;
			fRec2[0] = fConst32 * (fTemp1 - fVec0[1] + fConst31 * fRec2[1]);
			fRec1[0] = fRec2[0] - (fRec1[1] * (fConst29 + fRec0[0] * (fConst28 + fConst27 * fRec0[0]) + 1.97047105899815e-10) + fRec1[2] * (fConst2 * (fConst26 + fRec0[0] * (fConst25 + fConst24 * fRec0[0])) + 2.95570658849723e-10) + fRec1[3] * (fConst23 + fRec0[0] * (fConst21 + fConst19 * fRec0[0]) + 1.97047105899815e-10) + fRec1[4] * (fConst16 + fRec0[0] * (fConst15 + fConst14 * fRec0[0]) + 4.92617764749537e-11)) / fTemp0;
			fRec3[0] = fSlow1 + 0.993 * fRec3[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fRec3[0] * (fRec1[0] * (fConst47 + fRec0[0] * (fConst46 + fConst45 * fRec0[0])) + fRec1[1] * (fConst44 + fRec0[0] * (fConst43 + fConst42 * fRec0[0])) + fConst2 * fRec1[2] * (fConst41 + fRec0[0] * (fConst40 + fConst39 * fRec0[0])) + fRec1[3] * (fConst38 + fRec0[0] * (fConst36 + fConst34 * fRec0[0])) + fRec1[4] * (fConst13 + fRec0[0] * (fConst11 + fConst9 * fRec0[0]))) / fTemp0);
			fRec0[1] = fRec0[0];
			fVec0[1] = fVec0[0];
			fRec2[1] = fRec2[0];
			for (int j0 = 4; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec1[j0] = fRec1[faust_wrap_sub(j0, 1)];
			}
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
