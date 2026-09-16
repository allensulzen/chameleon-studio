/* ------------------------------------------------------------
author: "Luca Spanedda (Faust port), Keith Barr"
license: "GPL-3.0-only"
name: "Spin ROM Reverb"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibKbRomRev1 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibKbRomRev1_H__
#define  __LibKbRomRev1_H__

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
#define FAUSTCLASS LibKbRomRev1
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

class LibKbRomRev1SIG0 {
	
  private:
	
	int iVec12[2];
	int iRec45[2];
	int fSampleRate;
	
  public:
	
	int getNumInputsLibKbRomRev1SIG0() {
		return 0;
	}
	int getNumOutputsLibKbRomRev1SIG0() {
		return 1;
	}
	
	void instanceInitLibKbRomRev1SIG0(int sample_rate) {
		fSampleRate = sample_rate;
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			iVec12[l21] = 0;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			iRec45[l22] = 0;
		}
	}
	
	void fillLibKbRomRev1SIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			iVec12[0] = 1;
			iRec45[0] = (faust_wrap_add(iVec12[1], iRec45[1])) % 65536;
			table[i1] = std::sin(9.58738e-05f * static_cast<float>(iRec45[0]));
			iVec12[1] = iVec12[0];
			iRec45[1] = iRec45[0];
		}
	}

};

static LibKbRomRev1SIG0* newLibKbRomRev1SIG0() { return (LibKbRomRev1SIG0*)new LibKbRomRev1SIG0(); }
static void deleteLibKbRomRev1SIG0(LibKbRomRev1SIG0* dsp) { delete dsp; }

static float DSY_SDRAM_BSS ftbl0LibKbRomRev1SIG0[65536];

class LibKbRomRev1 : public chdsp {
	
 private:
	
	int IOTA0;
	float fVec0[16384];
	float fVec1[32768];
	int fSampleRate;
	float fConst0;
	int iConst1;
	int iConst2;
	int iVec2[2];
	float fVec3[2048];
	int iConst3;
	float fRec22[2];
	float fVec4[2048];
	int iConst4;
	float fRec20[2];
	float fVec5[2048];
	int iConst5;
	float fRec18[2];
	float fVec6[4096];
	int iConst6;
	float fRec16[2];
	float fVec7[1024];
	int iConst7;
	float fRec42[2];
	float fVec8[2048];
	int iConst8;
	float fRec40[2];
	float fVec9[2048];
	int iConst9;
	float fRec38[2];
	float fVec10[4096];
	int iConst10;
	float fRec36[2];
	int iConst11;
	float fConst12;
	float fConst13;
	FAUSTFLOAT fHslider0;
	float fRec44[2];
	float fVec11[8192];
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	float fRec46[2];
	float fRec34[2];
	float fVec13[16384];
	int iConst18;
	float fRec32[2];
	FAUSTFLOAT fHslider1;
	float fRec47[2];
	float fRec31[2];
	float fRec30[65536];
	int iConst19;
	float fVec14[16384];
	int iConst20;
	float fRec28[2];
	float fVec15[8192];
	int iConst21;
	float fRec26[2];
	float fRec25[2];
	float fRec24[32768];
	int iConst22;
	float fVec16[16384];
	float fConst23;
	float fConst24;
	float fRec14[2];
	float fVec17[16384];
	int iConst25;
	float fRec12[2];
	float fRec11[2];
	float fRec10[32768];
	int iConst26;
	float fVec18[8192];
	int iConst27;
	float fRec8[2];
	float fVec19[8192];
	int iConst28;
	float fRec6[2];
	float fRec5[2];
	float fRec4[2];
	float fRec0[32768];
	int iConst29;
	int iConst30;
	float fVec20[32768];
	int iConst31;
	float fVec21[32768];
	int iConst32;
	int iConst33;
	int iConst34;
	FAUSTFLOAT fHslider2;
	float fRec48[2];
	
 public:
	LibKbRomRev1() {
	}
	
	LibKbRomRev1(const LibKbRomRev1&) = default;
	
	virtual ~LibKbRomRev1() = default;
	
	LibKbRomRev1& operator=(const LibKbRomRev1&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Luca Spanedda (Faust port), Keith Barr");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibKbRomRev1 -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Keith Barr's Spin Semiconductor rom_rev1 allpass-loop reverb - classic FV-1 pedal tail");
		m->declare("family", "reverb");
		m->declare("filename", "lib-kb-rom-rev1.dsp");
		m->declare("license", "GPL-3.0-only");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Spin ROM Reverb");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/kb_rom_rev1:author", "Luca Spanedda");
		m->declare("reverbs.lib/kb_rom_rev1:license", "GPL-3.0-only");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.5.1");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.0");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/reverbs.lib re.kb_rom_rev1");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		LibKbRomRev1SIG0* sig0 = newLibKbRomRev1SIG0();
		sig0->instanceInitLibKbRomRev1SIG0(sample_rate);
		sig0->fillLibKbRomRev1SIG0(65536, ftbl0LibKbRomRev1SIG0);
		deleteLibKbRomRev1SIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		iConst1 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.035491943f * fConst0))));
		iConst2 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.09765625f * fConst0))));
		iConst3 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.0056762695f * fConst0))) + -1.0f);
		iConst4 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.0077209473f * fConst0))) + -1.0f);
		iConst5 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.009216309f * fConst0))) + -1.0f);
		iConst6 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.015197754f * fConst0))) + -1.0f);
		iConst7 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.004760742f * fConst0))) + -1.0f);
		iConst8 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.00680542f * fConst0))) + -1.0f);
		iConst9 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.010131836f * fConst0))) + -1.0f);
		iConst10 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.016723633f * fConst0))) + -1.0f);
		iConst11 = faust_wrap_add(static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.1394043f * fConst0))) + -1.0f), 1);
		fConst12 = 44.1f / fConst0;
		fConst13 = 1.0f - fConst12;
		fConst14 = std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.00061035156f * fConst0)));
		fConst15 = std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.03817749f * fConst0)));
		fConst16 = fConst15 + fConst14;
		fConst17 = 0.5f / fConst0;
		iConst18 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.05343628f * fConst0))) + -1.0f);
		iConst19 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.17880249f * fConst0))));
		iConst20 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.044036865f * fConst0))) + -1.0f);
		iConst21 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.040985107f * fConst0))) + -1.0f);
		iConst22 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.12649536f * fConst0))));
		fConst23 = std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.04827881f * fConst0)));
		fConst24 = fConst14 + fConst23;
		iConst25 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.060455322f * fConst0))) + -1.0f);
		iConst26 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.1060791f * fConst0))));
		iConst27 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.038879395f * fConst0))) + -1.0f);
		iConst28 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.042175293f * fConst0))) + -1.0f);
		iConst29 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.07385254f * fConst0))));
		iConst30 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.08026123f * fConst0))));
		iConst31 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.08029175f * fConst0))));
		iConst32 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.059295654f * fConst0))));
		iConst33 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.101623535f * fConst0))));
		iConst34 = static_cast<int>(std::max<float>(1.1920929e-07f, static_cast<float>(static_cast<int>(0.122558594f * fConst0))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.6f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.4f);
	}
	
	virtual void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 16384; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 32768; l1 = faust_wrap_add(l1, 1)) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			iVec2[l2] = 0;
		}
		for (int l3 = 0; l3 < 2048; l3 = faust_wrap_add(l3, 1)) {
			fVec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec22[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2048; l5 = faust_wrap_add(l5, 1)) {
			fVec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec20[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2048; l7 = faust_wrap_add(l7, 1)) {
			fVec5[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec18[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 4096; l9 = faust_wrap_add(l9, 1)) {
			fVec6[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec16[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 1024; l11 = faust_wrap_add(l11, 1)) {
			fVec7[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec42[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2048; l13 = faust_wrap_add(l13, 1)) {
			fVec8[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec40[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2048; l15 = faust_wrap_add(l15, 1)) {
			fVec9[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec38[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 4096; l17 = faust_wrap_add(l17, 1)) {
			fVec10[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec36[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec44[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 8192; l20 = faust_wrap_add(l20, 1)) {
			fVec11[l20] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec46[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec34[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 16384; l25 = faust_wrap_add(l25, 1)) {
			fVec13[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec32[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec47[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec31[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 65536; l29 = faust_wrap_add(l29, 1)) {
			fRec30[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 16384; l30 = faust_wrap_add(l30, 1)) {
			fVec14[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec28[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 8192; l32 = faust_wrap_add(l32, 1)) {
			fVec15[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec26[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec25[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 32768; l35 = faust_wrap_add(l35, 1)) {
			fRec24[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 16384; l36 = faust_wrap_add(l36, 1)) {
			fVec16[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec14[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 16384; l38 = faust_wrap_add(l38, 1)) {
			fVec17[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec12[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec11[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 32768; l41 = faust_wrap_add(l41, 1)) {
			fRec10[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 8192; l42 = faust_wrap_add(l42, 1)) {
			fVec18[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec8[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 8192; l44 = faust_wrap_add(l44, 1)) {
			fVec19[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec6[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fRec5[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fRec4[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 32768; l48 = faust_wrap_add(l48, 1)) {
			fRec0[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 32768; l49 = faust_wrap_add(l49, 1)) {
			fVec20[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 32768; l50 = faust_wrap_add(l50, 1)) {
			fVec21[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fRec48[l51] = 0.0f;
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
	
	virtual LibKbRomRev1* clone() {
		return new LibKbRomRev1(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Spin ROM Reverb");
		ui_interface->declare(&fHslider0, "0", "");
		ui_interface->addHorizontalSlider("Reverb Time", &fHslider0, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Damping", &fHslider1, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.99f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider2, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst12 * static_cast<float>(fHslider0);
		float fSlow1 = fConst12 * static_cast<float>(fHslider1);
		float fSlow2 = fConst12 * static_cast<float>(fHslider2);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fVec0[IOTA0 & 16383] = 1.5f;
			fVec1[IOTA0 & 32767] = 1.0f;
			iVec2[0] = 1;
			float fTemp0 = static_cast<float>(input0[i0]);
			float fTemp1 = fTemp0 + 0.5f * fRec22[1];
			fVec3[IOTA0 & 2047] = fTemp1;
			fRec22[0] = fVec3[(faust_wrap_sub(IOTA0, iConst3)) & 2047];
			float fRec23 = -(0.5f * fTemp1);
			float fTemp2 = fRec22[1] + fRec23 + 0.5f * fRec20[1];
			fVec4[IOTA0 & 2047] = fTemp2;
			fRec20[0] = fVec4[(faust_wrap_sub(IOTA0, iConst4)) & 2047];
			float fRec21 = -(0.5f * fTemp2);
			float fTemp3 = fRec20[1] + fRec21 + 0.5f * fRec18[1];
			fVec5[IOTA0 & 2047] = fTemp3;
			fRec18[0] = fVec5[(faust_wrap_sub(IOTA0, iConst5)) & 2047];
			float fRec19 = -(0.5f * fTemp3);
			float fTemp4 = fRec18[1] + fRec19 + 0.5f * fRec16[1];
			fVec6[IOTA0 & 4095] = fTemp4;
			fRec16[0] = fVec6[(faust_wrap_sub(IOTA0, iConst6)) & 4095];
			float fRec17 = -(0.5f * fTemp4);
			float fTemp5 = fTemp0 + 0.5f * fRec42[1];
			fVec7[IOTA0 & 1023] = fTemp5;
			fRec42[0] = fVec7[(faust_wrap_sub(IOTA0, iConst7)) & 1023];
			float fRec43 = -(0.5f * fTemp5);
			float fTemp6 = fRec42[1] + fRec43 + 0.5f * fRec40[1];
			fVec8[IOTA0 & 2047] = fTemp6;
			fRec40[0] = fVec8[(faust_wrap_sub(IOTA0, iConst8)) & 2047];
			float fRec41 = -(0.5f * fTemp6);
			float fTemp7 = fRec40[1] + fRec41 + 0.5f * fRec38[1];
			fVec9[IOTA0 & 2047] = fTemp7;
			fRec38[0] = fVec9[(faust_wrap_sub(IOTA0, iConst9)) & 2047];
			float fRec39 = -(0.5f * fTemp7);
			float fTemp8 = fRec38[1] + fRec39 + 0.5f * fRec36[1];
			fVec10[IOTA0 & 4095] = fTemp8;
			fRec36[0] = fVec10[(faust_wrap_sub(IOTA0, iConst10)) & 4095];
			float fRec37 = -(0.5f * fTemp8);
			fRec44[0] = fSlow0 + fConst13 * fRec44[1];
			float fTemp9 = fRec36[1] + fRec44[0] * fRec0[(faust_wrap_sub(IOTA0, iConst11)) & 32767] + fRec37 + 0.6f * fRec34[1];
			fVec11[IOTA0 & 8191] = fTemp9;
			float fTemp10 = ((faust_wrap_sub(1, iVec2[1])) ? 0.0f : fConst17 + fRec46[1]);
			fRec46[0] = fTemp10 - std::floor(fTemp10);
			float fTemp11 = fConst14 * ftbl0LibKbRomRev1SIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec46[0]), 65535))];
			float fTemp12 = fTemp11 + -1.0f;
			float fTemp13 = fConst15 + fTemp12;
			int iTemp14 = static_cast<int>(fTemp13);
			float fTemp15 = std::floor(fTemp13);
			float fTemp16 = 2.0f - fTemp11;
			fRec34[0] = fVec11[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst16, static_cast<float>(std::max<int>(0, iTemp14)))))) & 8191] * (fTemp15 + fTemp16 - fConst15) + (fConst15 + fTemp11 + (-1.0f - fTemp15)) * fVec11[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst16, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp14, 1))))))) & 8191];
			float fRec35 = -(0.6f * fTemp9);
			float fTemp17 = fRec34[1] + fRec35 + 0.6f * fRec32[1];
			fVec13[IOTA0 & 16383] = fTemp17;
			fRec32[0] = fVec13[(faust_wrap_sub(IOTA0, iConst18)) & 16383];
			float fRec33 = -(0.6f * fTemp17);
			fRec47[0] = fSlow1 + fConst13 * fRec47[1];
			float fTemp18 = 1.0f - std::fabs(fRec47[0]);
			fRec31[0] = fRec47[0] * fRec31[1] + fTemp18 * (fRec33 + fRec32[1]);
			fRec30[IOTA0 & 65535] = 0.95f * fRec31[0] - 0.05f * fRec30[(faust_wrap_sub(IOTA0, 1)) & 65535];
			float fTemp19 = 0.6f * fRec28[1] + fRec44[0] * fRec30[(faust_wrap_sub(IOTA0, iConst19)) & 65535];
			fVec14[IOTA0 & 16383] = fTemp19;
			fRec28[0] = fVec14[(faust_wrap_sub(IOTA0, iConst20)) & 16383];
			float fRec29 = -(0.6f * fTemp19);
			float fTemp20 = fRec28[1] + fRec29 + 0.6f * fRec26[1];
			fVec15[IOTA0 & 8191] = fTemp20;
			fRec26[0] = fVec15[(faust_wrap_sub(IOTA0, iConst21)) & 8191];
			float fRec27 = -(0.6f * fTemp20);
			fRec25[0] = fRec47[0] * fRec25[1] + fTemp18 * (fRec27 + fRec26[1]);
			fRec24[IOTA0 & 32767] = 0.95f * fRec25[0] - 0.05f * fRec24[(faust_wrap_sub(IOTA0, 1)) & 32767];
			float fTemp21 = fRec16[1] + fRec44[0] * fRec24[(faust_wrap_sub(IOTA0, iConst22)) & 32767] + fRec17 + 0.6f * fRec14[1];
			fVec16[IOTA0 & 16383] = fTemp21;
			float fTemp22 = fConst23 + fTemp12;
			int iTemp23 = static_cast<int>(fTemp22);
			float fTemp24 = std::floor(fTemp22);
			fRec14[0] = fVec16[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst24, static_cast<float>(std::max<int>(0, iTemp23)))))) & 16383] * (fTemp24 + fTemp16 - fConst23) + (fConst23 + fTemp11 + (-1.0f - fTemp24)) * fVec16[(faust_wrap_sub(IOTA0, static_cast<int>(std::min<float>(fConst24, static_cast<float>(std::max<int>(0, faust_wrap_add(iTemp23, 1))))))) & 16383];
			float fRec15 = -(0.6f * fTemp21);
			float fTemp25 = fRec14[1] + fRec15 + 0.6f * fRec12[1];
			fVec17[IOTA0 & 16383] = fTemp25;
			fRec12[0] = fVec17[(faust_wrap_sub(IOTA0, iConst25)) & 16383];
			float fRec13 = -(0.6f * fTemp25);
			fRec11[0] = fRec47[0] * fRec11[1] + fTemp18 * (fRec13 + fRec12[1]);
			fRec10[IOTA0 & 32767] = 0.95f * fRec11[0] - 0.05f * fRec10[(faust_wrap_sub(IOTA0, 1)) & 32767];
			float fTemp26 = 0.6f * fRec8[1] + fRec44[0] * fRec10[(faust_wrap_sub(IOTA0, iConst26)) & 32767];
			fVec18[IOTA0 & 8191] = fTemp26;
			fRec8[0] = fVec18[(faust_wrap_sub(IOTA0, iConst27)) & 8191];
			float fRec9 = -(0.6f * fTemp26);
			float fTemp27 = fRec8[1] + fRec9 + 0.6f * fRec6[1];
			fVec19[IOTA0 & 8191] = fTemp27;
			fRec6[0] = fVec19[(faust_wrap_sub(IOTA0, iConst28)) & 8191];
			float fRec7 = -(0.6f * fTemp27);
			fRec5[0] = fRec47[0] * fRec5[1] + fTemp18 * (fRec7 + fRec6[1]);
			fRec4[0] = 0.95f * fRec5[0] - 0.05f * fRec4[1];
			fRec0[IOTA0 & 32767] = fRec4[0];
			float fRec1 = fRec10[IOTA0 & 32767];
			float fRec2 = fRec24[IOTA0 & 32767];
			float fRec3 = fRec30[IOTA0 & 65535];
			fVec20[IOTA0 & 32767] = 0.8f;
			fVec21[IOTA0 & 32767] = 1.2f;
			fRec48[0] = fSlow2 + fConst13 * fRec48[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * (1.0f - fRec48[0]) + 0.5f * fRec48[0] * (fRec0[IOTA0 & 32767] * (fVec20[(faust_wrap_sub(IOTA0, iConst34)) & 32767] + fVec21[(faust_wrap_sub(IOTA0, iConst33)) & 32767]) + fRec2 * (fVec21[(faust_wrap_sub(IOTA0, iConst32)) & 32767] + fVec20[(faust_wrap_sub(IOTA0, iConst31)) & 32767]) + fRec3 * (fVec0[(faust_wrap_sub(IOTA0, iConst30)) & 16383] + fVec1[(faust_wrap_sub(IOTA0, iConst29)) & 32767]) + fRec1 * (fVec1[(faust_wrap_sub(IOTA0, iConst2)) & 32767] + fVec0[(faust_wrap_sub(IOTA0, iConst1)) & 16383])));
			IOTA0 = faust_wrap_add(IOTA0, 1);
			iVec2[1] = iVec2[0];
			fRec22[1] = fRec22[0];
			fRec20[1] = fRec20[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
			fRec38[1] = fRec38[0];
			fRec36[1] = fRec36[0];
			fRec44[1] = fRec44[0];
			fRec46[1] = fRec46[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec47[1] = fRec47[0];
			fRec31[1] = fRec31[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec48[1] = fRec48[0];
		}
	}

};

#endif
