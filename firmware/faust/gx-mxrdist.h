/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "MXR Distortion Plus"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMxrdist -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxMxrdist_H__
#define  __GxMxrdist_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
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
#define FAUSTCLASS GxMxrdist
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

const static double fGxMxrdistSIG0Wave0[100] = {0.0,-0.0297117955828,-0.0600180054016,-0.0909366474689,-0.122486475452,-0.154687016603,-0.187558612066,-0.221122459724,-0.255400659785,-0.290416263311,-0.32619332391,-0.362756952842,-0.400133377793,-0.43835000562,-0.477435489371,-0.517419799931,-0.558334302664,-0.600211839473,-0.64308681672,-0.686995299506,-0.731975112846,-0.778065950352,-0.825309491059,-0.873749525136,-0.923432089265,-0.974405612576,-1.0267210741,-1.08043217285,-1.13559551155,-1.19227079528,-1.25052104388,-1.31041280223,-1.3720162023,-1.43540358623,-1.50063467874,-1.5676109484,-1.63471748928,-1.69222628207,-1.72818769616,-1.74925333761,-1.76321031985,-1.77347868583,-1.78157546286,-1.78826553445,-1.79397934372,-1.79898035985,-1.8034405747,-1.80747806592,-1.81117723448,-1.81460043341,-1.81779501238,-1.82079777708,-1.8236379189,-1.8263390017,-1.8289203466,-1.83139802075,-1.83378555835,-1.83609449674,-1.83833478175,-1.84051507916,-1.84264301759,-1.84472538062,-1.84676826077,-1.8487771847,-1.85075721643,-1.85271304361,-1.85464905097,-1.85656938373,-1.85847800364,-1.86037873945,-1.86227533346,-1.86417148579,-1.86607089734,-1.86797731307,-1.8698945665,-1.87182662708,-1.87377765176,-1.8757520425,-1.87775451194,-1.87979015981,-1.88186456341,-1.88398388656,-1.88615501283,-1.88838571081,-1.89068484223,-1.89306262786,-1.89553099258,-1.89810402058,-1.90079856664,-1.90363509344,-1.90663884415,-1.90984152641,-1.91328380224,-1.91701909716,-1.92111966903,-1.92568676559,-1.93086870081,-1.93689565223,-1.94415405144,-1.95337103981};
class GxMxrdistSIG0 {
	
  private:
	
	int fGxMxrdistSIG0Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxMxrdistSIG0() {
		return 0;
	}
	int getNumOutputsGxMxrdistSIG0() {
		return 1;
	}
	
	void instanceInitGxMxrdistSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		fGxMxrdistSIG0Wave0_idx = 0;
	}
	
	void fillGxMxrdistSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			table[i1] = fGxMxrdistSIG0Wave0[fGxMxrdistSIG0Wave0_idx];
			fGxMxrdistSIG0Wave0_idx = (faust_wrap_add(1, fGxMxrdistSIG0Wave0_idx)) % 100;
		}
	}

};

static GxMxrdistSIG0* newGxMxrdistSIG0() { return (GxMxrdistSIG0*)new GxMxrdistSIG0(); }
static void deleteGxMxrdistSIG0(GxMxrdistSIG0* dsp) { delete dsp; }

static double GxMxrdist_faustpower2_f(double value) {
	return value * value;
}
static double DSY_SDRAM_BSS ftbl0GxMxrdistSIG0[100];

class GxMxrdist : public chdsp {
	
 private:
	
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
	double fRec3[3];
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fVec0[2];
	FAUSTFLOAT fHslider0;
	double fRec5[2];
	double fConst20;
	double fRec4[2];
	double fConst21;
	double fConst22;
	double fVec1[2];
	double fConst23;
	double fConst24;
	double fRec2[2];
	double fRec1[3];
	double fRec0[3];
	FAUSTFLOAT fVslider0;
	double fRec6[2];
	double fConst25;
	
 public:
	GxMxrdist() {
	}
	
	GxMxrdist(const GxMxrdist&) = default;
	
	virtual ~GxMxrdist() = default;
	
	GxMxrdist& operator=(const GxMxrdist&) = default;
	
	void metadata(Meta* m) { 
		m->declare("category", "Distortion");
		m->declare("chameleon_flags", "-double");
		m->declare("clipping.lib/license", "GPL-2.0-or-later");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxMxrdist -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-mxrdist.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass0_highpass1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("gx_tables.lib/license", "GPL-2.0-or-later");
		m->declare("id", "mxrdis");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "MXR Distortion Plus");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("samplerate", "96000");
		m->declare("shortname", "MXR+");
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
		GxMxrdistSIG0* sig0 = newGxMxrdistSIG0();
		sig0->instanceInitGxMxrdistSIG0(sample_rate);
		sig0->fillGxMxrdistSIG0(100, ftbl0GxMxrdistSIG0);
		deleteGxMxrdistSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 1.40668739186091e-10 * fConst0;
		fConst2 = fConst0 * (fConst1 + -1.40739073555684e-05) + 0.000351671847965227;
		fConst3 = GxMxrdist_faustpower2_f(fConst0);
		fConst4 = 0.000703343695930453 - 2.81337478372181e-10 * fConst3;
		fConst5 = fConst0 * (fConst1 + 1.40739073555684e-05) + 0.000351671847965227;
		fConst6 = 1.0 / fConst5;
		fConst7 = std::tan(50893.800988154646 / fConst0);
		fConst8 = 2.0 * (1.0 - 1.0 / GxMxrdist_faustpower2_f(fConst7));
		fConst9 = 1.0 / fConst7;
		fConst10 = (fConst9 + -1.0000000000000004) / fConst7 + 1.0;
		fConst11 = 1.0 / ((fConst9 + 1.0000000000000004) / fConst7 + 1.0);
		fConst12 = 4.3356710341455e-10 * fConst0;
		fConst13 = fConst0 * (fConst12 + -2.2111922274142e-08) + 2.14637179908193e-08;
		fConst14 = 4.29274359816386e-08 - 8.671342068291e-10 * fConst3;
		fConst15 = 1.0 / (fConst0 * (fConst12 + 2.2111922274142e-08) + 2.14637179908193e-08);
		fConst16 = 4.29274359816386e-10 * fConst0;
		fConst17 = fConst0 * (fConst16 + -6.43911539724579e-10);
		fConst18 = 8.58548719632772e-10 * fConst3;
		fConst19 = fConst0 * (fConst16 + 6.43911539724579e-10);
		fConst20 = 9.4e-08 * fConst0;
		fConst21 = ftbl0GxMxrdistSIG0[99];
		fConst22 = ftbl0GxMxrdistSIG0[0];
		fConst23 = 1.0 - fConst9;
		fConst24 = 1.0 / (fConst9 + 1.0);
		fConst25 = 7.03343695930453e-06 * (fConst0 / fConst5);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 3; l0 = faust_wrap_add(l0, 1)) {
			fRec3[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fVec0[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec5[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec4[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fVec1[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec2[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec1[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec0[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec6[l8] = 0.0;
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
	
	virtual GxMxrdist* clone() {
		return new GxMxrdist(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("MXR Distortion Plus");
		ui_interface->declare(&fVslider0, "name", "Volume");
		ui_interface->addVerticalSlider("Volume", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider0, "name", "Drive");
		ui_interface->addHorizontalSlider("drive", &fHslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * (0.25 * static_cast<double>(fHslider0) + 0.75);
		double fSlow1 = 0.007000000000000006 * static_cast<double>(fVslider0);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec3[0] = static_cast<double>(input0[i0]) - fConst15 * (fConst14 * fRec3[1] + fConst13 * fRec3[2]);
			double fTemp0 = fConst19 * fRec3[0] - fConst18 * fRec3[1] + fConst17 * fRec3[2];
			fVec0[0] = fTemp0;
			double fTemp1 = fConst15 * fTemp0;
			fRec5[0] = fSlow0 + 0.993 * fRec5[1];
			double fTemp2 = 1.0 - fRec5[0];
			double fTemp3 = fConst20 * (5e+05 * fTemp2 + 4.7e+03);
			double fTemp4 = fConst20 * (5e+05 * (fRec5[0] + fTemp2) + 9.7e+03);
			fRec4[0] = -((fRec4[1] * (1.0 - fTemp3) - fConst15 * (fTemp0 * (fTemp4 + 1.0) + fVec0[1] * (1.0 - fTemp4))) / (fTemp3 + 1.0));
			double fTemp5 = std::fabs(fRec4[0] - fTemp1);
			double fTemp6 = 101.97 * (fTemp5 / (fTemp5 + 3.0));
			double fTemp7 = std::min<double>(101.0, std::max<double>(-1.0, ((std::isnan(fTemp6) | std::isinf(fTemp6)) ? 0.0 : fTemp6)));
			int iTemp8 = static_cast<int>(fTemp7);
			int iTemp9 = std::max<int>(0, std::min<int>(98, iTemp8));
			double fTemp10 = static_cast<double>(iTemp9);
			double fTemp11 = fTemp1 - copysign(((iTemp8 < 0) ? fConst22 : ((iTemp8 >= 99) ? fConst21 : ftbl0GxMxrdistSIG0[iTemp9] * (fTemp10 + (1.0 - fTemp7)) + (fTemp7 - fTemp10) * ftbl0GxMxrdistSIG0[faust_wrap_add(iTemp9, 1)])), fTemp1 - fRec4[0]);
			fVec1[0] = fTemp11;
			fRec2[0] = -(fConst24 * (fConst23 * fRec2[1] - (fTemp11 + fVec1[1])));
			fRec1[0] = fRec2[0] - fConst11 * (fConst10 * fRec1[2] + fConst8 * fRec1[1]);
			fRec0[0] = fConst11 * (fRec1[2] + fRec1[0] + 2.0 * fRec1[1]) - fConst6 * (fConst4 * fRec0[1] + fConst2 * fRec0[2]);
			fRec6[0] = fSlow1 + 0.993 * fRec6[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fConst25 * fRec6[0] * (fRec0[0] - fRec0[2]));
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fVec0[1] = fVec0[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fVec1[1] = fVec1[0];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec6[1] = fRec6[0];
		}
	}

};

#endif
