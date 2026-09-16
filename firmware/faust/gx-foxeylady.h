/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Foxey Lady"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFoxeylady -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxFoxeylady_H__
#define  __GxFoxeylady_H__

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
#define FAUSTCLASS GxFoxeylady
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

static double GxFoxeylady_faustpower2_f(double value) {
	return value * value;
}

class GxFoxeylady : public chdsp {
	
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
	FAUSTFLOAT fVslider1;
	double fRec1[2];
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
	double fRec2[7];
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
	GxFoxeylady() {
	}
	
	GxFoxeylady(const GxFoxeylady&) = default;
	
	virtual ~GxFoxeylady() = default;
	
	GxFoxeylady& operator=(const GxFoxeylady&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Fuzz");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFoxeylady -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Foxey Lady fuzz pedal simulation");
		m->declare("filename", "gx-foxeylady.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "foxeylady");
		m->declare("insert_p", "tranyclipper");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Foxey Lady");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "Foxey Lady");
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
		fConst1 = 4.59387215604116e-29 * fConst0;
		fConst2 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-4.36933720361044e-25 - fConst1) + -8.96539812308464e-22) + -3.5938048928126e-19) + -4.96738293767392e-17) + -2.0568206880379e-15;
		fConst3 = 4.57704216569471e-29 * fConst0;
		fConst4 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst3 + 4.12221097685163e-25) + 2.55877854891379e-22) + -9.9587457844786e-19) + -4.94708666311112e-16) + -7.32065571555064e-14;
		fConst5 = 5.24588897595767e-29 * fConst0;
		fConst6 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst5 + 7.02844574269719e-25) + 2.89396306244108e-21) + 3.61888994332083e-18) + 1.29693461432975e-15) + 1.71281273151154e-13);
		fConst7 = 3.28344197367049e-28 * fConst0;
		fConst8 = fConst0 * (fConst0 * (fConst0 * (1.8701619702637e-23 - fConst7) + -2.16157324062859e-19) + 4.33524374895714e-17) + -5.90848481409701e-16;
		fConst9 = 6.42669378638762e-27 * fConst0;
		fConst10 = fConst0 * (fConst0 * (fConst0 * (fConst9 + -2.86240593005591e-23) + 1.79551930386446e-19) + -3.55668379874028e-17) + 4.84302033942378e-16;
		fConst11 = 6.42669378638762e-29 * fConst0;
		fConst12 = fConst0 * (fConst0 * (fConst0 * (fConst11 + -2.86240593005591e-25) + 1.79551930386446e-21) + -3.55668379874028e-19) + 4.84302033942378e-18;
		fConst13 = 3.28344197367049e-30 * fConst0;
		fConst14 = fConst0 * (fConst0 * (fConst0 * (1.8701619702637e-25 - fConst13) + -2.16157324062859e-21) + 4.33524374895714e-19) + -5.90848481409701e-18;
		fConst15 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (4.36933720361044e-25 - fConst1) + -8.96539812308464e-22) + 3.5938048928126e-19) + -4.96738293767392e-17) + 2.0568206880379e-15;
		fConst16 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst3 + -4.12221097685163e-25) + 2.55877854891379e-22) + 9.9587457844786e-19) + -4.94708666311112e-16) + 7.32065571555064e-14;
		fConst17 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst5 + -7.02844574269719e-25) + 2.89396306244108e-21) + -3.61888994332083e-18) + 1.29693461432975e-15) + -1.71281273151154e-13);
		fConst18 = 2.7563232936247e-28 * fConst0;
		fConst19 = GxFoxeylady_faustpower2_f(fConst0);
		fConst20 = fConst0 * (fConst19 * (fConst0 * (fConst18 + -1.74773488144418e-24) + 1.79307962461693e-21) + -9.93476587534785e-17) + 8.22728275215159e-15;
		fConst21 = 2.74622529941683e-28 * fConst0;
		fConst22 = fConst0 * (fConst19 * (fConst0 * (1.64888439074065e-24 - fConst21) + -5.11755709782759e-22) + -9.89417332622223e-16) + 2.92826228622026e-13;
		fConst23 = 3.1475333855746e-28 * fConst0;
		fConst24 = fConst0 * (fConst0 * (fConst19 * (fConst0 * (2.81137829707888e-24 - fConst23) + -5.78792612488216e-21) + 2.5938692286595e-15) + -6.85125092604618e-13);
		fConst25 = 6.89080823406175e-28 * fConst0;
		fConst26 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (2.18466860180522e-24 - fConst25) + 8.96539812308464e-22) + -1.07814146784378e-18) + 4.96738293767392e-17) + 1.02841034401895e-14;
		fConst27 = 6.86556324854206e-28 * fConst0;
		fConst28 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst27 + -2.06110548842582e-24) + -2.55877854891379e-22) + -2.98762373534358e-18) + 4.94708666311112e-16) + 3.66032785777532e-13;
		fConst29 = 7.8688334639365e-28 * fConst0;
		fConst30 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst29 + -3.51422287134859e-24) + -2.89396306244108e-21) + 1.08566698299625e-17) + -1.29693461432975e-15) + -8.56406365755772e-13);
		fConst31 = fConst19 * (9.18774431208233e-28 * fConst19 + -3.58615924923386e-21) + 1.98695317506957e-16;
		fConst32 = fConst19 * (1.02351141956552e-21 - 9.15408433138942e-28 * fConst19) + 1.97883466524445e-15;
		fConst33 = fConst19 * (fConst19 * (1.15758522497643e-20 - 1.04917779519153e-27 * fConst19) + -5.18773845731899e-15);
		fConst34 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-2.18466860180522e-24 - fConst25) + 8.96539812308464e-22) + 1.07814146784378e-18) + 4.96738293767392e-17) + -1.02841034401895e-14;
		fConst35 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst27 + 2.06110548842582e-24) + -2.55877854891379e-22) + 2.98762373534358e-18) + 4.94708666311112e-16) + -3.66032785777532e-13;
		fConst36 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst29 + 3.51422287134859e-24) + -2.89396306244108e-21) + -1.08566698299625e-17) + -1.29693461432975e-15) + 8.56406365755772e-13);
		fConst37 = fConst0 * (fConst19 * (fConst0 * (fConst18 + 1.74773488144418e-24) + 1.79307962461693e-21) + -9.93476587534785e-17) + -8.22728275215159e-15;
		fConst38 = fConst0 * (fConst19 * (fConst0 * (-1.64888439074065e-24 - fConst21) + -5.11755709782759e-22) + -9.89417332622223e-16) + -2.92826228622026e-13;
		fConst39 = fConst0 * (fConst0 * (fConst19 * (fConst0 * (-2.81137829707888e-24 - fConst23) + -5.78792612488216e-21) + 2.5938692286595e-15) + 6.85125092604618e-13);
		fConst40 = 1.97006518420229e-27 * fConst0;
		fConst41 = fConst19 * (fConst0 * (fConst40 + -7.48064788105479e-23) + 4.32314648125718e-19) + -1.1816969628194e-15;
		fConst42 = 3.85601627183257e-26 * fConst0;
		fConst43 = fConst19 * (fConst0 * (1.14496237202237e-22 - fConst42) + -3.59103860772892e-19) + 9.68604067884756e-16;
		fConst44 = 3.85601627183257e-28 * fConst0;
		fConst45 = fConst19 * (fConst0 * (1.14496237202237e-24 - fConst44) + -3.59103860772892e-21) + 9.68604067884756e-18;
		fConst46 = 1.97006518420229e-29 * fConst0;
		fConst47 = fConst19 * (fConst0 * (fConst46 + -7.48064788105479e-25) + 4.32314648125718e-21) + -1.1816969628194e-17;
		fConst48 = 4.92516296050573e-27 * fConst0;
		fConst49 = fConst0 * (fConst0 * (fConst0 * (9.35080985131849e-23 - fConst48) + 2.16157324062859e-19) + -1.30057312468714e-16) + 5.90848481409701e-16;
		fConst50 = 9.64004067958143e-26 * fConst0;
		fConst51 = fConst0 * (fConst0 * (fConst0 * (fConst50 + -1.43120296502796e-22) + -1.79551930386446e-19) + 1.06700513962208e-16) + -4.84302033942378e-16;
		fConst52 = 9.64004067958143e-28 * fConst0;
		fConst53 = fConst0 * (fConst0 * (fConst0 * (fConst52 + -1.43120296502796e-24) + -1.79551930386446e-21) + 1.06700513962208e-18) + -4.84302033942378e-18;
		fConst54 = 4.92516296050573e-29 * fConst0;
		fConst55 = fConst0 * (fConst0 * (fConst0 * (9.35080985131849e-25 - fConst54) + 2.16157324062859e-21) + -1.30057312468714e-18) + 5.90848481409701e-18;
		fConst56 = fConst19 * (6.56688394734098e-27 * fConst19 + -8.64629296251435e-19) + 2.3633939256388e-15;
		fConst57 = fConst19 * (7.18207721545784e-19 - 1.28533875727752e-25 * fConst19) + -1.93720813576951e-15;
		fConst58 = fConst19 * (7.18207721545784e-21 - 1.28533875727752e-27 * fConst19) + -1.93720813576951e-17;
		fConst59 = fConst19 * (6.56688394734098e-29 * fConst19 + -8.64629296251435e-21) + 2.3633939256388e-17;
		fConst60 = fConst0 * (fConst0 * (fConst0 * (-9.35080985131849e-23 - fConst48) + 2.16157324062859e-19) + 1.30057312468714e-16) + 5.90848481409701e-16;
		fConst61 = fConst0 * (fConst0 * (fConst0 * (fConst50 + 1.43120296502796e-22) + -1.79551930386446e-19) + -1.06700513962208e-16) + -4.84302033942378e-16;
		fConst62 = fConst0 * (fConst0 * (fConst0 * (fConst52 + 1.43120296502796e-24) + -1.79551930386446e-21) + -1.06700513962208e-18) + -4.84302033942378e-18;
		fConst63 = fConst0 * (fConst0 * (fConst0 * (-9.35080985131849e-25 - fConst54) + 2.16157324062859e-21) + 1.30057312468714e-18) + 5.90848481409701e-18;
		fConst64 = fConst19 * (fConst0 * (fConst40 + 7.48064788105479e-23) + 4.32314648125718e-19) + -1.1816969628194e-15;
		fConst65 = fConst19 * (fConst0 * (-1.14496237202237e-22 - fConst42) + -3.59103860772892e-19) + 9.68604067884756e-16;
		fConst66 = fConst19 * (fConst0 * (-1.14496237202237e-24 - fConst44) + -3.59103860772892e-21) + 9.68604067884756e-18;
		fConst67 = fConst19 * (fConst0 * (fConst46 + 7.48064788105479e-25) + 4.32314648125718e-21) + -1.1816969628194e-17;
		fConst68 = fConst0 * (fConst0 * (fConst0 * (-1.8701619702637e-23 - fConst7) + -2.16157324062859e-19) + -4.33524374895714e-17) + -5.90848481409701e-16;
		fConst69 = fConst0 * (fConst0 * (fConst0 * (fConst9 + 2.86240593005591e-23) + 1.79551930386446e-19) + 3.55668379874028e-17) + 4.84302033942378e-16;
		fConst70 = fConst0 * (fConst0 * (fConst0 * (fConst11 + 2.86240593005591e-25) + 1.79551930386446e-21) + 3.55668379874028e-19) + 4.84302033942378e-18;
		fConst71 = fConst0 * (fConst0 * (fConst0 * (-1.8701619702637e-25 - fConst13) + -2.16157324062859e-21) + -4.33524374895714e-19) + -5.90848481409701e-18;
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
		for (int l2 = 0; l2 < 7; l2 = faust_wrap_add(l2, 1)) {
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
	
	virtual GxFoxeylady* clone() {
		return new GxFoxeylady(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Foxey Lady");
		ui_interface->declare(&fVslider0, "name", "Fuzz");
		ui_interface->addVerticalSlider("Fuzz", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider1, "name", "Level");
		ui_interface->addVerticalSlider("Level", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * (1.0 - static_cast<double>(fVslider0));
		double fSlow1 = 0.007000000000000006 * static_cast<double>(fVslider1);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			double fTemp0 = fConst6 + fRec0[0] * (fConst0 * (fConst4 + fConst2 * fRec0[0]) + -3.1163949818756e-12) + 6.94956080958259e-12;
			fRec1[0] = fSlow1 + 0.993 * fRec1[1];
			fRec2[0] = static_cast<double>(input0[i0]) - (fRec2[1] * (fConst39 + fRec0[0] * (fConst0 * (fConst38 + fConst37 * fRec0[0]) + -1.86983698912536e-11) + 4.16973648574956e-11) + fRec2[2] * (fConst36 + fRec0[0] * (fConst0 * (fConst35 + fConst34 * fRec0[0]) + -4.6745924728134e-11) + 1.04243412143739e-10) + fRec2[3] * (fConst33 + fRec0[0] * (fConst19 * (fConst32 + fConst31 * fRec0[0]) + -6.23278996375121e-11) + 1.38991216191652e-10) + fRec2[4] * (fConst30 + fRec0[0] * (fConst0 * (fConst28 + fConst26 * fRec0[0]) + -4.6745924728134e-11) + 1.04243412143739e-10) + fRec2[5] * (fConst24 + fRec0[0] * (fConst0 * (fConst22 + fConst20 * fRec0[0]) + -1.86983698912536e-11) + 4.16973648574956e-11) + fRec2[6] * (fConst17 + fRec0[0] * (fConst0 * (fConst16 + fConst15 * fRec0[0]) + -3.1163949818756e-12) + 6.94956080958259e-12)) / fTemp0;
			output0[i0] = static_cast<FAUSTFLOAT>(fConst19 * ((fRec2[0] * (fConst71 + fRec0[0] * (fConst70 + fConst69 * fRec1[0]) + fConst68 * fRec1[0]) + fRec2[1] * (fConst67 + fRec0[0] * (fConst66 + fConst65 * fRec1[0]) + fConst64 * fRec1[0]) + fRec2[2] * (fConst63 + fRec0[0] * (fConst62 + fConst61 * fRec1[0]) + fConst60 * fRec1[0]) + fRec2[3] * (fConst59 + fRec0[0] * (fConst58 + fConst57 * fRec1[0]) + fConst56 * fRec1[0]) + fRec2[4] * (fConst55 + fRec0[0] * (fConst53 + fConst51 * fRec1[0]) + fConst49 * fRec1[0]) + fRec2[5] * (fConst47 + fRec0[0] * (fConst45 + fConst43 * fRec1[0]) + fConst41 * fRec1[0]) + fRec2[6] * (fConst14 + fRec0[0] * (fConst12 + fConst10 * fRec1[0]) + fConst8 * fRec1[0])) / fTemp0));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			for (int j0 = 6; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec2[j0] = fRec2[faust_wrap_sub(j0, 1)];
			}
		}
	}

};

#endif
