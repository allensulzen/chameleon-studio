/* ------------------------------------------------------------
author: "Julius O. Smith III"
license: "LicenseRef-STK-4.3"
name: "FDN Reverb 16"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibFdnReverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibFdnReverb_H__
#define  __LibFdnReverb_H__

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
#define FAUSTCLASS LibFdnReverb
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

static float LibFdnReverb_faustpower2_f(float value) {
	return value * value;
}

class LibFdnReverb : public chdsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	float fConst18;
	float fConst19;
	float fConst20;
	float fConst21;
	float fConst22;
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fRec23[2];
	float fRec22[3];
	float fVec0[2];
	float fConst30;
	float fConst31;
	float fConst32;
	float fRec21[2];
	float fRec20[3];
	float fVec1[2];
	float fConst33;
	float fConst34;
	float fConst35;
	float fRec19[2];
	float fRec18[3];
	float fVec2[2];
	float fConst36;
	float fConst37;
	float fConst38;
	float fRec17[2];
	float fRec16[3];
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fConst39;
	float fConst40;
	float fConst41;
	float fRec25[2];
	float fRec24[3];
	FAUSTFLOAT fHslider2;
	float fConst42;
	float fConst43;
	float fConst44;
	float fRec28[2];
	float fRec27[3];
	float fConst45;
	float fRec26[3];
	float fConst46;
	float fConst47;
	float fConst48;
	float fRec32[2];
	float fRec31[3];
	float fConst49;
	float fRec30[3];
	float fRec29[3];
	float fConst50;
	float fConst51;
	float fRec37[2];
	float fRec36[3];
	float fConst52;
	float fRec35[3];
	float fRec34[3];
	float fRec33[3];
	float fRec45[2];
	float fRec44[3];
	float fVec3[2];
	float fRec43[2];
	float fRec42[3];
	float fVec4[2];
	float fRec41[2];
	float fRec40[3];
	float fVec5[2];
	float fRec39[2];
	float fRec38[3];
	FAUSTFLOAT fHslider3;
	float fRec47[2];
	float fRec46[3];
	float fRec50[2];
	float fRec49[3];
	float fRec48[3];
	float fRec54[2];
	float fRec53[3];
	float fRec52[3];
	float fRec51[3];
	float fRec59[2];
	float fRec58[3];
	float fRec57[3];
	float fRec56[3];
	float fRec55[3];
	float fRec67[2];
	float fRec66[3];
	float fVec6[2];
	float fRec65[2];
	float fRec64[3];
	float fVec7[2];
	float fRec63[2];
	float fRec62[3];
	float fVec8[2];
	float fRec61[2];
	float fRec60[3];
	float fRec69[2];
	float fRec68[3];
	float fRec72[2];
	float fRec71[3];
	float fRec70[3];
	float fRec76[2];
	float fRec75[3];
	float fRec74[3];
	float fRec73[3];
	float fRec81[2];
	float fRec80[3];
	float fRec79[3];
	float fRec78[3];
	float fRec77[3];
	float fRec89[2];
	float fRec88[3];
	float fVec9[2];
	float fRec87[2];
	float fRec86[3];
	float fVec10[2];
	float fRec85[2];
	float fRec84[3];
	float fVec11[2];
	float fRec83[2];
	float fRec82[3];
	float fRec91[2];
	float fRec90[3];
	float fRec94[2];
	float fRec93[3];
	float fRec92[3];
	float fRec98[2];
	float fRec97[3];
	float fRec96[3];
	float fRec95[3];
	float fRec103[2];
	float fRec102[3];
	float fRec101[3];
	float fRec100[3];
	float fRec99[3];
	float fRec111[2];
	float fRec110[3];
	float fVec12[2];
	float fRec109[2];
	float fRec108[3];
	float fVec13[2];
	float fRec107[2];
	float fRec106[3];
	float fVec14[2];
	float fRec105[2];
	float fRec104[3];
	float fRec113[2];
	float fRec112[3];
	float fRec116[2];
	float fRec115[3];
	float fRec114[3];
	float fRec120[2];
	float fRec119[3];
	float fRec118[3];
	float fRec117[3];
	float fRec125[2];
	float fRec124[3];
	float fRec123[3];
	float fRec122[3];
	float fRec121[3];
	float fRec133[2];
	float fRec132[3];
	float fVec15[2];
	float fRec131[2];
	float fRec130[3];
	float fVec16[2];
	float fRec129[2];
	float fRec128[3];
	float fVec17[2];
	float fRec127[2];
	float fRec126[3];
	float fRec135[2];
	float fRec134[3];
	float fRec138[2];
	float fRec137[3];
	float fRec136[3];
	float fRec142[2];
	float fRec141[3];
	float fRec140[3];
	float fRec139[3];
	float fRec147[2];
	float fRec146[3];
	float fRec145[3];
	float fRec144[3];
	float fRec143[3];
	float fRec155[2];
	float fRec154[3];
	float fVec18[2];
	float fRec153[2];
	float fRec152[3];
	float fVec19[2];
	float fRec151[2];
	float fRec150[3];
	float fVec20[2];
	float fRec149[2];
	float fRec148[3];
	float fRec157[2];
	float fRec156[3];
	float fRec160[2];
	float fRec159[3];
	float fRec158[3];
	float fRec164[2];
	float fRec163[3];
	float fRec162[3];
	float fRec161[3];
	float fRec169[2];
	float fRec168[3];
	float fRec167[3];
	float fRec166[3];
	float fRec165[3];
	float fRec177[2];
	float fRec176[3];
	float fVec21[2];
	float fRec175[2];
	float fRec174[3];
	float fVec22[2];
	float fRec173[2];
	float fRec172[3];
	float fVec23[2];
	float fRec171[2];
	float fRec170[3];
	float fRec179[2];
	float fRec178[3];
	float fRec182[2];
	float fRec181[3];
	float fRec180[3];
	float fRec186[2];
	float fRec185[3];
	float fRec184[3];
	float fRec183[3];
	float fRec191[2];
	float fRec190[3];
	float fRec189[3];
	float fRec188[3];
	float fRec187[3];
	float fRec199[2];
	float fRec198[3];
	float fVec24[2];
	float fRec197[2];
	float fRec196[3];
	float fVec25[2];
	float fRec195[2];
	float fRec194[3];
	float fVec26[2];
	float fRec193[2];
	float fRec192[3];
	float fRec201[2];
	float fRec200[3];
	float fRec204[2];
	float fRec203[3];
	float fRec202[3];
	float fRec208[2];
	float fRec207[3];
	float fRec206[3];
	float fRec205[3];
	float fRec213[2];
	float fRec212[3];
	float fRec211[3];
	float fRec210[3];
	float fRec209[3];
	float fRec221[2];
	float fRec220[3];
	float fVec27[2];
	float fRec219[2];
	float fRec218[3];
	float fVec28[2];
	float fRec217[2];
	float fRec216[3];
	float fVec29[2];
	float fRec215[2];
	float fRec214[3];
	float fRec223[2];
	float fRec222[3];
	float fRec226[2];
	float fRec225[3];
	float fRec224[3];
	float fRec230[2];
	float fRec229[3];
	float fRec228[3];
	float fRec227[3];
	float fRec235[2];
	float fRec234[3];
	float fRec233[3];
	float fRec232[3];
	float fRec231[3];
	float fRec243[2];
	float fRec242[3];
	float fVec30[2];
	float fRec241[2];
	float fRec240[3];
	float fVec31[2];
	float fRec239[2];
	float fRec238[3];
	float fVec32[2];
	float fRec237[2];
	float fRec236[3];
	float fRec245[2];
	float fRec244[3];
	float fRec248[2];
	float fRec247[3];
	float fRec246[3];
	float fRec252[2];
	float fRec251[3];
	float fRec250[3];
	float fRec249[3];
	float fRec257[2];
	float fRec256[3];
	float fRec255[3];
	float fRec254[3];
	float fRec253[3];
	float fRec265[2];
	float fRec264[3];
	float fVec33[2];
	float fRec263[2];
	float fRec262[3];
	float fVec34[2];
	float fRec261[2];
	float fRec260[3];
	float fVec35[2];
	float fRec259[2];
	float fRec258[3];
	float fRec267[2];
	float fRec266[3];
	float fRec270[2];
	float fRec269[3];
	float fRec268[3];
	float fRec274[2];
	float fRec273[3];
	float fRec272[3];
	float fRec271[3];
	float fRec279[2];
	float fRec278[3];
	float fRec277[3];
	float fRec276[3];
	float fRec275[3];
	float fRec287[2];
	float fRec286[3];
	float fVec36[2];
	float fRec285[2];
	float fRec284[3];
	float fVec37[2];
	float fRec283[2];
	float fRec282[3];
	float fVec38[2];
	float fRec281[2];
	float fRec280[3];
	float fRec289[2];
	float fRec288[3];
	float fRec292[2];
	float fRec291[3];
	float fRec290[3];
	float fRec296[2];
	float fRec295[3];
	float fRec294[3];
	float fRec293[3];
	float fRec301[2];
	float fRec300[3];
	float fRec299[3];
	float fRec298[3];
	float fRec297[3];
	float fRec309[2];
	float fRec308[3];
	float fVec39[2];
	float fRec307[2];
	float fRec306[3];
	float fVec40[2];
	float fRec305[2];
	float fRec304[3];
	float fVec41[2];
	float fRec303[2];
	float fRec302[3];
	float fRec311[2];
	float fRec310[3];
	float fRec314[2];
	float fRec313[3];
	float fRec312[3];
	float fRec318[2];
	float fRec317[3];
	float fRec316[3];
	float fRec315[3];
	float fRec323[2];
	float fRec322[3];
	float fRec321[3];
	float fRec320[3];
	float fRec319[3];
	float fRec331[2];
	float fRec330[3];
	float fVec42[2];
	float fRec329[2];
	float fRec328[3];
	float fVec43[2];
	float fRec327[2];
	float fRec326[3];
	float fVec44[2];
	float fRec325[2];
	float fRec324[3];
	float fRec333[2];
	float fRec332[3];
	float fRec336[2];
	float fRec335[3];
	float fRec334[3];
	float fRec340[2];
	float fRec339[3];
	float fRec338[3];
	float fRec337[3];
	float fRec345[2];
	float fRec344[3];
	float fRec343[3];
	float fRec342[3];
	float fRec341[3];
	float fRec353[2];
	float fRec352[3];
	float fVec45[2];
	float fRec351[2];
	float fRec350[3];
	float fVec46[2];
	float fRec349[2];
	float fRec348[3];
	float fVec47[2];
	float fRec347[2];
	float fRec346[3];
	float fRec355[2];
	float fRec354[3];
	float fRec358[2];
	float fRec357[3];
	float fRec356[3];
	float fRec362[2];
	float fRec361[3];
	float fRec360[3];
	float fRec359[3];
	float fRec367[2];
	float fRec366[3];
	float fRec365[3];
	float fRec364[3];
	float fRec363[3];
	int IOTA0;
	float fVec48[16384];
	float fRec0[3];
	float fVec49[16384];
	float fRec1[3];
	float fVec50[16384];
	float fRec2[3];
	float fVec51[16384];
	float fRec3[3];
	float fVec52[16384];
	float fRec4[3];
	float fVec53[16384];
	float fRec5[3];
	float fVec54[16384];
	float fRec6[3];
	float fVec55[16384];
	float fRec7[3];
	float fVec56[16384];
	float fRec8[3];
	float fVec57[16384];
	float fRec9[3];
	float fVec58[16384];
	float fRec10[3];
	float fVec59[16384];
	float fRec11[3];
	float fVec60[16384];
	float fRec12[3];
	float fVec61[16384];
	float fRec13[3];
	float fVec62[16384];
	float fRec14[3];
	float fVec63[16384];
	float fRec15[3];
	float fConst53;
	float fConst54;
	FAUSTFLOAT fHslider4;
	float fRec368[2];
	
 public:
	LibFdnReverb() {
	}
	
	LibFdnReverb(const LibFdnReverb&) = default;
	
	virtual ~LibFdnReverb() = default;
	
	LibFdnReverb& operator=(const LibFdnReverb&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Julius O. Smith III");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibFdnReverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/prime_power_delays:author", "Julius O. Smith III");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "16-line feedback delay network with 5-band decay times and room dimension (fdnrev0)");
		m->declare("family", "reverb");
		m->declare("filename", "lib-fdn-reverb.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/highpass_plus_lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass_plus_lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:license", "LicenseRef-STK-4.3");
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
		m->declare("license", "LicenseRef-STK-4.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "FDN Reverb 16");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.5.1");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/reverbs.lib re.fdnrev0");
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
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = std::tan(1570.7964f / fConst0);
		fConst2 = 1.0f / LibFdnReverb_faustpower2_f(fConst1);
		fConst3 = 2.0f * (1.0f - fConst2);
		fConst4 = 1.0f / fConst1;
		fConst5 = (fConst4 + -1.0f) / fConst1 + 1.0f;
		fConst6 = 1.0f / ((fConst4 + 1.0f) / fConst1 + 1.0f);
		fConst7 = std::tan(3141.5928f / fConst0);
		fConst8 = LibFdnReverb_faustpower2_f(fConst7);
		fConst9 = 2.0f * (1.0f - 1.0f / fConst8);
		fConst10 = 1.0f / fConst7;
		fConst11 = (fConst10 + -1.0f) / fConst7 + 1.0f;
		fConst12 = (fConst10 + 1.0f) / fConst7 + 1.0f;
		fConst13 = 1.0f / fConst12;
		fConst14 = std::tan(6283.1855f / fConst0);
		fConst15 = LibFdnReverb_faustpower2_f(fConst14);
		fConst16 = 2.0f * (1.0f - 1.0f / fConst15);
		fConst17 = 1.0f / fConst14;
		fConst18 = (fConst17 + -1.0f) / fConst14 + 1.0f;
		fConst19 = (fConst17 + 1.0f) / fConst14 + 1.0f;
		fConst20 = 1.0f / fConst19;
		fConst21 = std::tan(12566.371f / fConst0);
		fConst22 = LibFdnReverb_faustpower2_f(fConst21);
		fConst23 = 2.0f * (1.0f - 1.0f / fConst22);
		fConst24 = 1.0f / fConst21;
		fConst25 = (fConst24 + -1.0f) / fConst21 + 1.0f;
		fConst26 = (fConst24 + 1.0f) / fConst21 + 1.0f;
		fConst27 = 1.0f / fConst26;
		fConst28 = 1.0f - fConst24;
		fConst29 = 1.0f / (fConst24 + 1.0f);
		fConst30 = 1.0f - fConst17;
		fConst31 = fConst17 + 1.0f;
		fConst32 = 1.0f / fConst31;
		fConst33 = 1.0f - fConst10;
		fConst34 = fConst10 + 1.0f;
		fConst35 = 1.0f / fConst34;
		fConst36 = 1.0f - fConst4;
		fConst37 = fConst4 + 1.0f;
		fConst38 = 1.0f / fConst37;
		fConst39 = 0.002915452f * fConst0;
		fConst40 = 6.9077554f / fConst0;
		fConst41 = 1.0f / (fConst1 * fConst12);
		fConst42 = 1.0f - fConst36 / fConst1;
		fConst43 = 1.0f / (fConst37 / fConst1 + 1.0f);
		fConst44 = 1.0f / (fConst7 * fConst19);
		fConst45 = 1.0f / (fConst8 * fConst12);
		fConst46 = 1.0f - fConst33 / fConst7;
		fConst47 = 1.0f / (fConst34 / fConst7 + 1.0f);
		fConst48 = 1.0f / (fConst14 * fConst26);
		fConst49 = 1.0f / (fConst15 * fConst19);
		fConst50 = 1.0f - fConst30 / fConst14;
		fConst51 = 1.0f / (fConst31 / fConst14 + 1.0f);
		fConst52 = 1.0f / (fConst22 * fConst26);
		fConst53 = 44.1f / fConst0;
		fConst54 = 1.0f - fConst53;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(3.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(45.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(1.2f);
		fHslider3 = static_cast<FAUSTFLOAT>(2e+01f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.35f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec23[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 3; l1 = faust_wrap_add(l1, 1)) {
			fRec22[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec21[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = faust_wrap_add(l4, 1)) {
			fRec20[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec19[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = faust_wrap_add(l7, 1)) {
			fRec18[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fVec2[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec17[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = faust_wrap_add(l10, 1)) {
			fRec16[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec25[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 3; l12 = faust_wrap_add(l12, 1)) {
			fRec24[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec28[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = faust_wrap_add(l14, 1)) {
			fRec27[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 3; l15 = faust_wrap_add(l15, 1)) {
			fRec26[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec32[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 3; l17 = faust_wrap_add(l17, 1)) {
			fRec31[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 3; l18 = faust_wrap_add(l18, 1)) {
			fRec30[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 3; l19 = faust_wrap_add(l19, 1)) {
			fRec29[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec37[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 3; l21 = faust_wrap_add(l21, 1)) {
			fRec36[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 3; l22 = faust_wrap_add(l22, 1)) {
			fRec35[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 3; l23 = faust_wrap_add(l23, 1)) {
			fRec34[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 3; l24 = faust_wrap_add(l24, 1)) {
			fRec33[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec45[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 3; l26 = faust_wrap_add(l26, 1)) {
			fRec44[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fVec3[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec43[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 3; l29 = faust_wrap_add(l29, 1)) {
			fRec42[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fVec4[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec41[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 3; l32 = faust_wrap_add(l32, 1)) {
			fRec40[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fVec5[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec39[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 3; l35 = faust_wrap_add(l35, 1)) {
			fRec38[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec47[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 3; l37 = faust_wrap_add(l37, 1)) {
			fRec46[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fRec50[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 3; l39 = faust_wrap_add(l39, 1)) {
			fRec49[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 3; l40 = faust_wrap_add(l40, 1)) {
			fRec48[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec54[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 3; l42 = faust_wrap_add(l42, 1)) {
			fRec53[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 3; l43 = faust_wrap_add(l43, 1)) {
			fRec52[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 3; l44 = faust_wrap_add(l44, 1)) {
			fRec51[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec59[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 3; l46 = faust_wrap_add(l46, 1)) {
			fRec58[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 3; l47 = faust_wrap_add(l47, 1)) {
			fRec57[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 3; l48 = faust_wrap_add(l48, 1)) {
			fRec56[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 3; l49 = faust_wrap_add(l49, 1)) {
			fRec55[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec67[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 3; l51 = faust_wrap_add(l51, 1)) {
			fRec66[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fVec6[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fRec65[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 3; l54 = faust_wrap_add(l54, 1)) {
			fRec64[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			fVec7[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fRec63[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 3; l57 = faust_wrap_add(l57, 1)) {
			fRec62[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = faust_wrap_add(l58, 1)) {
			fVec8[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = faust_wrap_add(l59, 1)) {
			fRec61[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 3; l60 = faust_wrap_add(l60, 1)) {
			fRec60[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = faust_wrap_add(l61, 1)) {
			fRec69[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 3; l62 = faust_wrap_add(l62, 1)) {
			fRec68[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = faust_wrap_add(l63, 1)) {
			fRec72[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 3; l64 = faust_wrap_add(l64, 1)) {
			fRec71[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 3; l65 = faust_wrap_add(l65, 1)) {
			fRec70[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = faust_wrap_add(l66, 1)) {
			fRec76[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 3; l67 = faust_wrap_add(l67, 1)) {
			fRec75[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 3; l68 = faust_wrap_add(l68, 1)) {
			fRec74[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 3; l69 = faust_wrap_add(l69, 1)) {
			fRec73[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2; l70 = faust_wrap_add(l70, 1)) {
			fRec81[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 3; l71 = faust_wrap_add(l71, 1)) {
			fRec80[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 3; l72 = faust_wrap_add(l72, 1)) {
			fRec79[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 3; l73 = faust_wrap_add(l73, 1)) {
			fRec78[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 3; l74 = faust_wrap_add(l74, 1)) {
			fRec77[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 2; l75 = faust_wrap_add(l75, 1)) {
			fRec89[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 3; l76 = faust_wrap_add(l76, 1)) {
			fRec88[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 2; l77 = faust_wrap_add(l77, 1)) {
			fVec9[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 2; l78 = faust_wrap_add(l78, 1)) {
			fRec87[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 3; l79 = faust_wrap_add(l79, 1)) {
			fRec86[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 2; l80 = faust_wrap_add(l80, 1)) {
			fVec10[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 2; l81 = faust_wrap_add(l81, 1)) {
			fRec85[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 3; l82 = faust_wrap_add(l82, 1)) {
			fRec84[l82] = 0.0f;
		}
		for (int l83 = 0; l83 < 2; l83 = faust_wrap_add(l83, 1)) {
			fVec11[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 2; l84 = faust_wrap_add(l84, 1)) {
			fRec83[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 3; l85 = faust_wrap_add(l85, 1)) {
			fRec82[l85] = 0.0f;
		}
		for (int l86 = 0; l86 < 2; l86 = faust_wrap_add(l86, 1)) {
			fRec91[l86] = 0.0f;
		}
		for (int l87 = 0; l87 < 3; l87 = faust_wrap_add(l87, 1)) {
			fRec90[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 2; l88 = faust_wrap_add(l88, 1)) {
			fRec94[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 3; l89 = faust_wrap_add(l89, 1)) {
			fRec93[l89] = 0.0f;
		}
		for (int l90 = 0; l90 < 3; l90 = faust_wrap_add(l90, 1)) {
			fRec92[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 2; l91 = faust_wrap_add(l91, 1)) {
			fRec98[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 3; l92 = faust_wrap_add(l92, 1)) {
			fRec97[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 3; l93 = faust_wrap_add(l93, 1)) {
			fRec96[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 3; l94 = faust_wrap_add(l94, 1)) {
			fRec95[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 2; l95 = faust_wrap_add(l95, 1)) {
			fRec103[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 3; l96 = faust_wrap_add(l96, 1)) {
			fRec102[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 3; l97 = faust_wrap_add(l97, 1)) {
			fRec101[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 3; l98 = faust_wrap_add(l98, 1)) {
			fRec100[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 3; l99 = faust_wrap_add(l99, 1)) {
			fRec99[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 2; l100 = faust_wrap_add(l100, 1)) {
			fRec111[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 3; l101 = faust_wrap_add(l101, 1)) {
			fRec110[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 2; l102 = faust_wrap_add(l102, 1)) {
			fVec12[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 2; l103 = faust_wrap_add(l103, 1)) {
			fRec109[l103] = 0.0f;
		}
		for (int l104 = 0; l104 < 3; l104 = faust_wrap_add(l104, 1)) {
			fRec108[l104] = 0.0f;
		}
		for (int l105 = 0; l105 < 2; l105 = faust_wrap_add(l105, 1)) {
			fVec13[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 2; l106 = faust_wrap_add(l106, 1)) {
			fRec107[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 3; l107 = faust_wrap_add(l107, 1)) {
			fRec106[l107] = 0.0f;
		}
		for (int l108 = 0; l108 < 2; l108 = faust_wrap_add(l108, 1)) {
			fVec14[l108] = 0.0f;
		}
		for (int l109 = 0; l109 < 2; l109 = faust_wrap_add(l109, 1)) {
			fRec105[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 3; l110 = faust_wrap_add(l110, 1)) {
			fRec104[l110] = 0.0f;
		}
		for (int l111 = 0; l111 < 2; l111 = faust_wrap_add(l111, 1)) {
			fRec113[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 3; l112 = faust_wrap_add(l112, 1)) {
			fRec112[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 2; l113 = faust_wrap_add(l113, 1)) {
			fRec116[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 3; l114 = faust_wrap_add(l114, 1)) {
			fRec115[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 3; l115 = faust_wrap_add(l115, 1)) {
			fRec114[l115] = 0.0f;
		}
		for (int l116 = 0; l116 < 2; l116 = faust_wrap_add(l116, 1)) {
			fRec120[l116] = 0.0f;
		}
		for (int l117 = 0; l117 < 3; l117 = faust_wrap_add(l117, 1)) {
			fRec119[l117] = 0.0f;
		}
		for (int l118 = 0; l118 < 3; l118 = faust_wrap_add(l118, 1)) {
			fRec118[l118] = 0.0f;
		}
		for (int l119 = 0; l119 < 3; l119 = faust_wrap_add(l119, 1)) {
			fRec117[l119] = 0.0f;
		}
		for (int l120 = 0; l120 < 2; l120 = faust_wrap_add(l120, 1)) {
			fRec125[l120] = 0.0f;
		}
		for (int l121 = 0; l121 < 3; l121 = faust_wrap_add(l121, 1)) {
			fRec124[l121] = 0.0f;
		}
		for (int l122 = 0; l122 < 3; l122 = faust_wrap_add(l122, 1)) {
			fRec123[l122] = 0.0f;
		}
		for (int l123 = 0; l123 < 3; l123 = faust_wrap_add(l123, 1)) {
			fRec122[l123] = 0.0f;
		}
		for (int l124 = 0; l124 < 3; l124 = faust_wrap_add(l124, 1)) {
			fRec121[l124] = 0.0f;
		}
		for (int l125 = 0; l125 < 2; l125 = faust_wrap_add(l125, 1)) {
			fRec133[l125] = 0.0f;
		}
		for (int l126 = 0; l126 < 3; l126 = faust_wrap_add(l126, 1)) {
			fRec132[l126] = 0.0f;
		}
		for (int l127 = 0; l127 < 2; l127 = faust_wrap_add(l127, 1)) {
			fVec15[l127] = 0.0f;
		}
		for (int l128 = 0; l128 < 2; l128 = faust_wrap_add(l128, 1)) {
			fRec131[l128] = 0.0f;
		}
		for (int l129 = 0; l129 < 3; l129 = faust_wrap_add(l129, 1)) {
			fRec130[l129] = 0.0f;
		}
		for (int l130 = 0; l130 < 2; l130 = faust_wrap_add(l130, 1)) {
			fVec16[l130] = 0.0f;
		}
		for (int l131 = 0; l131 < 2; l131 = faust_wrap_add(l131, 1)) {
			fRec129[l131] = 0.0f;
		}
		for (int l132 = 0; l132 < 3; l132 = faust_wrap_add(l132, 1)) {
			fRec128[l132] = 0.0f;
		}
		for (int l133 = 0; l133 < 2; l133 = faust_wrap_add(l133, 1)) {
			fVec17[l133] = 0.0f;
		}
		for (int l134 = 0; l134 < 2; l134 = faust_wrap_add(l134, 1)) {
			fRec127[l134] = 0.0f;
		}
		for (int l135 = 0; l135 < 3; l135 = faust_wrap_add(l135, 1)) {
			fRec126[l135] = 0.0f;
		}
		for (int l136 = 0; l136 < 2; l136 = faust_wrap_add(l136, 1)) {
			fRec135[l136] = 0.0f;
		}
		for (int l137 = 0; l137 < 3; l137 = faust_wrap_add(l137, 1)) {
			fRec134[l137] = 0.0f;
		}
		for (int l138 = 0; l138 < 2; l138 = faust_wrap_add(l138, 1)) {
			fRec138[l138] = 0.0f;
		}
		for (int l139 = 0; l139 < 3; l139 = faust_wrap_add(l139, 1)) {
			fRec137[l139] = 0.0f;
		}
		for (int l140 = 0; l140 < 3; l140 = faust_wrap_add(l140, 1)) {
			fRec136[l140] = 0.0f;
		}
		for (int l141 = 0; l141 < 2; l141 = faust_wrap_add(l141, 1)) {
			fRec142[l141] = 0.0f;
		}
		for (int l142 = 0; l142 < 3; l142 = faust_wrap_add(l142, 1)) {
			fRec141[l142] = 0.0f;
		}
		for (int l143 = 0; l143 < 3; l143 = faust_wrap_add(l143, 1)) {
			fRec140[l143] = 0.0f;
		}
		for (int l144 = 0; l144 < 3; l144 = faust_wrap_add(l144, 1)) {
			fRec139[l144] = 0.0f;
		}
		for (int l145 = 0; l145 < 2; l145 = faust_wrap_add(l145, 1)) {
			fRec147[l145] = 0.0f;
		}
		for (int l146 = 0; l146 < 3; l146 = faust_wrap_add(l146, 1)) {
			fRec146[l146] = 0.0f;
		}
		for (int l147 = 0; l147 < 3; l147 = faust_wrap_add(l147, 1)) {
			fRec145[l147] = 0.0f;
		}
		for (int l148 = 0; l148 < 3; l148 = faust_wrap_add(l148, 1)) {
			fRec144[l148] = 0.0f;
		}
		for (int l149 = 0; l149 < 3; l149 = faust_wrap_add(l149, 1)) {
			fRec143[l149] = 0.0f;
		}
		for (int l150 = 0; l150 < 2; l150 = faust_wrap_add(l150, 1)) {
			fRec155[l150] = 0.0f;
		}
		for (int l151 = 0; l151 < 3; l151 = faust_wrap_add(l151, 1)) {
			fRec154[l151] = 0.0f;
		}
		for (int l152 = 0; l152 < 2; l152 = faust_wrap_add(l152, 1)) {
			fVec18[l152] = 0.0f;
		}
		for (int l153 = 0; l153 < 2; l153 = faust_wrap_add(l153, 1)) {
			fRec153[l153] = 0.0f;
		}
		for (int l154 = 0; l154 < 3; l154 = faust_wrap_add(l154, 1)) {
			fRec152[l154] = 0.0f;
		}
		for (int l155 = 0; l155 < 2; l155 = faust_wrap_add(l155, 1)) {
			fVec19[l155] = 0.0f;
		}
		for (int l156 = 0; l156 < 2; l156 = faust_wrap_add(l156, 1)) {
			fRec151[l156] = 0.0f;
		}
		for (int l157 = 0; l157 < 3; l157 = faust_wrap_add(l157, 1)) {
			fRec150[l157] = 0.0f;
		}
		for (int l158 = 0; l158 < 2; l158 = faust_wrap_add(l158, 1)) {
			fVec20[l158] = 0.0f;
		}
		for (int l159 = 0; l159 < 2; l159 = faust_wrap_add(l159, 1)) {
			fRec149[l159] = 0.0f;
		}
		for (int l160 = 0; l160 < 3; l160 = faust_wrap_add(l160, 1)) {
			fRec148[l160] = 0.0f;
		}
		for (int l161 = 0; l161 < 2; l161 = faust_wrap_add(l161, 1)) {
			fRec157[l161] = 0.0f;
		}
		for (int l162 = 0; l162 < 3; l162 = faust_wrap_add(l162, 1)) {
			fRec156[l162] = 0.0f;
		}
		for (int l163 = 0; l163 < 2; l163 = faust_wrap_add(l163, 1)) {
			fRec160[l163] = 0.0f;
		}
		for (int l164 = 0; l164 < 3; l164 = faust_wrap_add(l164, 1)) {
			fRec159[l164] = 0.0f;
		}
		for (int l165 = 0; l165 < 3; l165 = faust_wrap_add(l165, 1)) {
			fRec158[l165] = 0.0f;
		}
		for (int l166 = 0; l166 < 2; l166 = faust_wrap_add(l166, 1)) {
			fRec164[l166] = 0.0f;
		}
		for (int l167 = 0; l167 < 3; l167 = faust_wrap_add(l167, 1)) {
			fRec163[l167] = 0.0f;
		}
		for (int l168 = 0; l168 < 3; l168 = faust_wrap_add(l168, 1)) {
			fRec162[l168] = 0.0f;
		}
		for (int l169 = 0; l169 < 3; l169 = faust_wrap_add(l169, 1)) {
			fRec161[l169] = 0.0f;
		}
		for (int l170 = 0; l170 < 2; l170 = faust_wrap_add(l170, 1)) {
			fRec169[l170] = 0.0f;
		}
		for (int l171 = 0; l171 < 3; l171 = faust_wrap_add(l171, 1)) {
			fRec168[l171] = 0.0f;
		}
		for (int l172 = 0; l172 < 3; l172 = faust_wrap_add(l172, 1)) {
			fRec167[l172] = 0.0f;
		}
		for (int l173 = 0; l173 < 3; l173 = faust_wrap_add(l173, 1)) {
			fRec166[l173] = 0.0f;
		}
		for (int l174 = 0; l174 < 3; l174 = faust_wrap_add(l174, 1)) {
			fRec165[l174] = 0.0f;
		}
		for (int l175 = 0; l175 < 2; l175 = faust_wrap_add(l175, 1)) {
			fRec177[l175] = 0.0f;
		}
		for (int l176 = 0; l176 < 3; l176 = faust_wrap_add(l176, 1)) {
			fRec176[l176] = 0.0f;
		}
		for (int l177 = 0; l177 < 2; l177 = faust_wrap_add(l177, 1)) {
			fVec21[l177] = 0.0f;
		}
		for (int l178 = 0; l178 < 2; l178 = faust_wrap_add(l178, 1)) {
			fRec175[l178] = 0.0f;
		}
		for (int l179 = 0; l179 < 3; l179 = faust_wrap_add(l179, 1)) {
			fRec174[l179] = 0.0f;
		}
		for (int l180 = 0; l180 < 2; l180 = faust_wrap_add(l180, 1)) {
			fVec22[l180] = 0.0f;
		}
		for (int l181 = 0; l181 < 2; l181 = faust_wrap_add(l181, 1)) {
			fRec173[l181] = 0.0f;
		}
		for (int l182 = 0; l182 < 3; l182 = faust_wrap_add(l182, 1)) {
			fRec172[l182] = 0.0f;
		}
		for (int l183 = 0; l183 < 2; l183 = faust_wrap_add(l183, 1)) {
			fVec23[l183] = 0.0f;
		}
		for (int l184 = 0; l184 < 2; l184 = faust_wrap_add(l184, 1)) {
			fRec171[l184] = 0.0f;
		}
		for (int l185 = 0; l185 < 3; l185 = faust_wrap_add(l185, 1)) {
			fRec170[l185] = 0.0f;
		}
		for (int l186 = 0; l186 < 2; l186 = faust_wrap_add(l186, 1)) {
			fRec179[l186] = 0.0f;
		}
		for (int l187 = 0; l187 < 3; l187 = faust_wrap_add(l187, 1)) {
			fRec178[l187] = 0.0f;
		}
		for (int l188 = 0; l188 < 2; l188 = faust_wrap_add(l188, 1)) {
			fRec182[l188] = 0.0f;
		}
		for (int l189 = 0; l189 < 3; l189 = faust_wrap_add(l189, 1)) {
			fRec181[l189] = 0.0f;
		}
		for (int l190 = 0; l190 < 3; l190 = faust_wrap_add(l190, 1)) {
			fRec180[l190] = 0.0f;
		}
		for (int l191 = 0; l191 < 2; l191 = faust_wrap_add(l191, 1)) {
			fRec186[l191] = 0.0f;
		}
		for (int l192 = 0; l192 < 3; l192 = faust_wrap_add(l192, 1)) {
			fRec185[l192] = 0.0f;
		}
		for (int l193 = 0; l193 < 3; l193 = faust_wrap_add(l193, 1)) {
			fRec184[l193] = 0.0f;
		}
		for (int l194 = 0; l194 < 3; l194 = faust_wrap_add(l194, 1)) {
			fRec183[l194] = 0.0f;
		}
		for (int l195 = 0; l195 < 2; l195 = faust_wrap_add(l195, 1)) {
			fRec191[l195] = 0.0f;
		}
		for (int l196 = 0; l196 < 3; l196 = faust_wrap_add(l196, 1)) {
			fRec190[l196] = 0.0f;
		}
		for (int l197 = 0; l197 < 3; l197 = faust_wrap_add(l197, 1)) {
			fRec189[l197] = 0.0f;
		}
		for (int l198 = 0; l198 < 3; l198 = faust_wrap_add(l198, 1)) {
			fRec188[l198] = 0.0f;
		}
		for (int l199 = 0; l199 < 3; l199 = faust_wrap_add(l199, 1)) {
			fRec187[l199] = 0.0f;
		}
		for (int l200 = 0; l200 < 2; l200 = faust_wrap_add(l200, 1)) {
			fRec199[l200] = 0.0f;
		}
		for (int l201 = 0; l201 < 3; l201 = faust_wrap_add(l201, 1)) {
			fRec198[l201] = 0.0f;
		}
		for (int l202 = 0; l202 < 2; l202 = faust_wrap_add(l202, 1)) {
			fVec24[l202] = 0.0f;
		}
		for (int l203 = 0; l203 < 2; l203 = faust_wrap_add(l203, 1)) {
			fRec197[l203] = 0.0f;
		}
		for (int l204 = 0; l204 < 3; l204 = faust_wrap_add(l204, 1)) {
			fRec196[l204] = 0.0f;
		}
		for (int l205 = 0; l205 < 2; l205 = faust_wrap_add(l205, 1)) {
			fVec25[l205] = 0.0f;
		}
		for (int l206 = 0; l206 < 2; l206 = faust_wrap_add(l206, 1)) {
			fRec195[l206] = 0.0f;
		}
		for (int l207 = 0; l207 < 3; l207 = faust_wrap_add(l207, 1)) {
			fRec194[l207] = 0.0f;
		}
		for (int l208 = 0; l208 < 2; l208 = faust_wrap_add(l208, 1)) {
			fVec26[l208] = 0.0f;
		}
		for (int l209 = 0; l209 < 2; l209 = faust_wrap_add(l209, 1)) {
			fRec193[l209] = 0.0f;
		}
		for (int l210 = 0; l210 < 3; l210 = faust_wrap_add(l210, 1)) {
			fRec192[l210] = 0.0f;
		}
		for (int l211 = 0; l211 < 2; l211 = faust_wrap_add(l211, 1)) {
			fRec201[l211] = 0.0f;
		}
		for (int l212 = 0; l212 < 3; l212 = faust_wrap_add(l212, 1)) {
			fRec200[l212] = 0.0f;
		}
		for (int l213 = 0; l213 < 2; l213 = faust_wrap_add(l213, 1)) {
			fRec204[l213] = 0.0f;
		}
		for (int l214 = 0; l214 < 3; l214 = faust_wrap_add(l214, 1)) {
			fRec203[l214] = 0.0f;
		}
		for (int l215 = 0; l215 < 3; l215 = faust_wrap_add(l215, 1)) {
			fRec202[l215] = 0.0f;
		}
		for (int l216 = 0; l216 < 2; l216 = faust_wrap_add(l216, 1)) {
			fRec208[l216] = 0.0f;
		}
		for (int l217 = 0; l217 < 3; l217 = faust_wrap_add(l217, 1)) {
			fRec207[l217] = 0.0f;
		}
		for (int l218 = 0; l218 < 3; l218 = faust_wrap_add(l218, 1)) {
			fRec206[l218] = 0.0f;
		}
		for (int l219 = 0; l219 < 3; l219 = faust_wrap_add(l219, 1)) {
			fRec205[l219] = 0.0f;
		}
		for (int l220 = 0; l220 < 2; l220 = faust_wrap_add(l220, 1)) {
			fRec213[l220] = 0.0f;
		}
		for (int l221 = 0; l221 < 3; l221 = faust_wrap_add(l221, 1)) {
			fRec212[l221] = 0.0f;
		}
		for (int l222 = 0; l222 < 3; l222 = faust_wrap_add(l222, 1)) {
			fRec211[l222] = 0.0f;
		}
		for (int l223 = 0; l223 < 3; l223 = faust_wrap_add(l223, 1)) {
			fRec210[l223] = 0.0f;
		}
		for (int l224 = 0; l224 < 3; l224 = faust_wrap_add(l224, 1)) {
			fRec209[l224] = 0.0f;
		}
		for (int l225 = 0; l225 < 2; l225 = faust_wrap_add(l225, 1)) {
			fRec221[l225] = 0.0f;
		}
		for (int l226 = 0; l226 < 3; l226 = faust_wrap_add(l226, 1)) {
			fRec220[l226] = 0.0f;
		}
		for (int l227 = 0; l227 < 2; l227 = faust_wrap_add(l227, 1)) {
			fVec27[l227] = 0.0f;
		}
		for (int l228 = 0; l228 < 2; l228 = faust_wrap_add(l228, 1)) {
			fRec219[l228] = 0.0f;
		}
		for (int l229 = 0; l229 < 3; l229 = faust_wrap_add(l229, 1)) {
			fRec218[l229] = 0.0f;
		}
		for (int l230 = 0; l230 < 2; l230 = faust_wrap_add(l230, 1)) {
			fVec28[l230] = 0.0f;
		}
		for (int l231 = 0; l231 < 2; l231 = faust_wrap_add(l231, 1)) {
			fRec217[l231] = 0.0f;
		}
		for (int l232 = 0; l232 < 3; l232 = faust_wrap_add(l232, 1)) {
			fRec216[l232] = 0.0f;
		}
		for (int l233 = 0; l233 < 2; l233 = faust_wrap_add(l233, 1)) {
			fVec29[l233] = 0.0f;
		}
		for (int l234 = 0; l234 < 2; l234 = faust_wrap_add(l234, 1)) {
			fRec215[l234] = 0.0f;
		}
		for (int l235 = 0; l235 < 3; l235 = faust_wrap_add(l235, 1)) {
			fRec214[l235] = 0.0f;
		}
		for (int l236 = 0; l236 < 2; l236 = faust_wrap_add(l236, 1)) {
			fRec223[l236] = 0.0f;
		}
		for (int l237 = 0; l237 < 3; l237 = faust_wrap_add(l237, 1)) {
			fRec222[l237] = 0.0f;
		}
		for (int l238 = 0; l238 < 2; l238 = faust_wrap_add(l238, 1)) {
			fRec226[l238] = 0.0f;
		}
		for (int l239 = 0; l239 < 3; l239 = faust_wrap_add(l239, 1)) {
			fRec225[l239] = 0.0f;
		}
		for (int l240 = 0; l240 < 3; l240 = faust_wrap_add(l240, 1)) {
			fRec224[l240] = 0.0f;
		}
		for (int l241 = 0; l241 < 2; l241 = faust_wrap_add(l241, 1)) {
			fRec230[l241] = 0.0f;
		}
		for (int l242 = 0; l242 < 3; l242 = faust_wrap_add(l242, 1)) {
			fRec229[l242] = 0.0f;
		}
		for (int l243 = 0; l243 < 3; l243 = faust_wrap_add(l243, 1)) {
			fRec228[l243] = 0.0f;
		}
		for (int l244 = 0; l244 < 3; l244 = faust_wrap_add(l244, 1)) {
			fRec227[l244] = 0.0f;
		}
		for (int l245 = 0; l245 < 2; l245 = faust_wrap_add(l245, 1)) {
			fRec235[l245] = 0.0f;
		}
		for (int l246 = 0; l246 < 3; l246 = faust_wrap_add(l246, 1)) {
			fRec234[l246] = 0.0f;
		}
		for (int l247 = 0; l247 < 3; l247 = faust_wrap_add(l247, 1)) {
			fRec233[l247] = 0.0f;
		}
		for (int l248 = 0; l248 < 3; l248 = faust_wrap_add(l248, 1)) {
			fRec232[l248] = 0.0f;
		}
		for (int l249 = 0; l249 < 3; l249 = faust_wrap_add(l249, 1)) {
			fRec231[l249] = 0.0f;
		}
		for (int l250 = 0; l250 < 2; l250 = faust_wrap_add(l250, 1)) {
			fRec243[l250] = 0.0f;
		}
		for (int l251 = 0; l251 < 3; l251 = faust_wrap_add(l251, 1)) {
			fRec242[l251] = 0.0f;
		}
		for (int l252 = 0; l252 < 2; l252 = faust_wrap_add(l252, 1)) {
			fVec30[l252] = 0.0f;
		}
		for (int l253 = 0; l253 < 2; l253 = faust_wrap_add(l253, 1)) {
			fRec241[l253] = 0.0f;
		}
		for (int l254 = 0; l254 < 3; l254 = faust_wrap_add(l254, 1)) {
			fRec240[l254] = 0.0f;
		}
		for (int l255 = 0; l255 < 2; l255 = faust_wrap_add(l255, 1)) {
			fVec31[l255] = 0.0f;
		}
		for (int l256 = 0; l256 < 2; l256 = faust_wrap_add(l256, 1)) {
			fRec239[l256] = 0.0f;
		}
		for (int l257 = 0; l257 < 3; l257 = faust_wrap_add(l257, 1)) {
			fRec238[l257] = 0.0f;
		}
		for (int l258 = 0; l258 < 2; l258 = faust_wrap_add(l258, 1)) {
			fVec32[l258] = 0.0f;
		}
		for (int l259 = 0; l259 < 2; l259 = faust_wrap_add(l259, 1)) {
			fRec237[l259] = 0.0f;
		}
		for (int l260 = 0; l260 < 3; l260 = faust_wrap_add(l260, 1)) {
			fRec236[l260] = 0.0f;
		}
		for (int l261 = 0; l261 < 2; l261 = faust_wrap_add(l261, 1)) {
			fRec245[l261] = 0.0f;
		}
		for (int l262 = 0; l262 < 3; l262 = faust_wrap_add(l262, 1)) {
			fRec244[l262] = 0.0f;
		}
		for (int l263 = 0; l263 < 2; l263 = faust_wrap_add(l263, 1)) {
			fRec248[l263] = 0.0f;
		}
		for (int l264 = 0; l264 < 3; l264 = faust_wrap_add(l264, 1)) {
			fRec247[l264] = 0.0f;
		}
		for (int l265 = 0; l265 < 3; l265 = faust_wrap_add(l265, 1)) {
			fRec246[l265] = 0.0f;
		}
		for (int l266 = 0; l266 < 2; l266 = faust_wrap_add(l266, 1)) {
			fRec252[l266] = 0.0f;
		}
		for (int l267 = 0; l267 < 3; l267 = faust_wrap_add(l267, 1)) {
			fRec251[l267] = 0.0f;
		}
		for (int l268 = 0; l268 < 3; l268 = faust_wrap_add(l268, 1)) {
			fRec250[l268] = 0.0f;
		}
		for (int l269 = 0; l269 < 3; l269 = faust_wrap_add(l269, 1)) {
			fRec249[l269] = 0.0f;
		}
		for (int l270 = 0; l270 < 2; l270 = faust_wrap_add(l270, 1)) {
			fRec257[l270] = 0.0f;
		}
		for (int l271 = 0; l271 < 3; l271 = faust_wrap_add(l271, 1)) {
			fRec256[l271] = 0.0f;
		}
		for (int l272 = 0; l272 < 3; l272 = faust_wrap_add(l272, 1)) {
			fRec255[l272] = 0.0f;
		}
		for (int l273 = 0; l273 < 3; l273 = faust_wrap_add(l273, 1)) {
			fRec254[l273] = 0.0f;
		}
		for (int l274 = 0; l274 < 3; l274 = faust_wrap_add(l274, 1)) {
			fRec253[l274] = 0.0f;
		}
		for (int l275 = 0; l275 < 2; l275 = faust_wrap_add(l275, 1)) {
			fRec265[l275] = 0.0f;
		}
		for (int l276 = 0; l276 < 3; l276 = faust_wrap_add(l276, 1)) {
			fRec264[l276] = 0.0f;
		}
		for (int l277 = 0; l277 < 2; l277 = faust_wrap_add(l277, 1)) {
			fVec33[l277] = 0.0f;
		}
		for (int l278 = 0; l278 < 2; l278 = faust_wrap_add(l278, 1)) {
			fRec263[l278] = 0.0f;
		}
		for (int l279 = 0; l279 < 3; l279 = faust_wrap_add(l279, 1)) {
			fRec262[l279] = 0.0f;
		}
		for (int l280 = 0; l280 < 2; l280 = faust_wrap_add(l280, 1)) {
			fVec34[l280] = 0.0f;
		}
		for (int l281 = 0; l281 < 2; l281 = faust_wrap_add(l281, 1)) {
			fRec261[l281] = 0.0f;
		}
		for (int l282 = 0; l282 < 3; l282 = faust_wrap_add(l282, 1)) {
			fRec260[l282] = 0.0f;
		}
		for (int l283 = 0; l283 < 2; l283 = faust_wrap_add(l283, 1)) {
			fVec35[l283] = 0.0f;
		}
		for (int l284 = 0; l284 < 2; l284 = faust_wrap_add(l284, 1)) {
			fRec259[l284] = 0.0f;
		}
		for (int l285 = 0; l285 < 3; l285 = faust_wrap_add(l285, 1)) {
			fRec258[l285] = 0.0f;
		}
		for (int l286 = 0; l286 < 2; l286 = faust_wrap_add(l286, 1)) {
			fRec267[l286] = 0.0f;
		}
		for (int l287 = 0; l287 < 3; l287 = faust_wrap_add(l287, 1)) {
			fRec266[l287] = 0.0f;
		}
		for (int l288 = 0; l288 < 2; l288 = faust_wrap_add(l288, 1)) {
			fRec270[l288] = 0.0f;
		}
		for (int l289 = 0; l289 < 3; l289 = faust_wrap_add(l289, 1)) {
			fRec269[l289] = 0.0f;
		}
		for (int l290 = 0; l290 < 3; l290 = faust_wrap_add(l290, 1)) {
			fRec268[l290] = 0.0f;
		}
		for (int l291 = 0; l291 < 2; l291 = faust_wrap_add(l291, 1)) {
			fRec274[l291] = 0.0f;
		}
		for (int l292 = 0; l292 < 3; l292 = faust_wrap_add(l292, 1)) {
			fRec273[l292] = 0.0f;
		}
		for (int l293 = 0; l293 < 3; l293 = faust_wrap_add(l293, 1)) {
			fRec272[l293] = 0.0f;
		}
		for (int l294 = 0; l294 < 3; l294 = faust_wrap_add(l294, 1)) {
			fRec271[l294] = 0.0f;
		}
		for (int l295 = 0; l295 < 2; l295 = faust_wrap_add(l295, 1)) {
			fRec279[l295] = 0.0f;
		}
		for (int l296 = 0; l296 < 3; l296 = faust_wrap_add(l296, 1)) {
			fRec278[l296] = 0.0f;
		}
		for (int l297 = 0; l297 < 3; l297 = faust_wrap_add(l297, 1)) {
			fRec277[l297] = 0.0f;
		}
		for (int l298 = 0; l298 < 3; l298 = faust_wrap_add(l298, 1)) {
			fRec276[l298] = 0.0f;
		}
		for (int l299 = 0; l299 < 3; l299 = faust_wrap_add(l299, 1)) {
			fRec275[l299] = 0.0f;
		}
		for (int l300 = 0; l300 < 2; l300 = faust_wrap_add(l300, 1)) {
			fRec287[l300] = 0.0f;
		}
		for (int l301 = 0; l301 < 3; l301 = faust_wrap_add(l301, 1)) {
			fRec286[l301] = 0.0f;
		}
		for (int l302 = 0; l302 < 2; l302 = faust_wrap_add(l302, 1)) {
			fVec36[l302] = 0.0f;
		}
		for (int l303 = 0; l303 < 2; l303 = faust_wrap_add(l303, 1)) {
			fRec285[l303] = 0.0f;
		}
		for (int l304 = 0; l304 < 3; l304 = faust_wrap_add(l304, 1)) {
			fRec284[l304] = 0.0f;
		}
		for (int l305 = 0; l305 < 2; l305 = faust_wrap_add(l305, 1)) {
			fVec37[l305] = 0.0f;
		}
		for (int l306 = 0; l306 < 2; l306 = faust_wrap_add(l306, 1)) {
			fRec283[l306] = 0.0f;
		}
		for (int l307 = 0; l307 < 3; l307 = faust_wrap_add(l307, 1)) {
			fRec282[l307] = 0.0f;
		}
		for (int l308 = 0; l308 < 2; l308 = faust_wrap_add(l308, 1)) {
			fVec38[l308] = 0.0f;
		}
		for (int l309 = 0; l309 < 2; l309 = faust_wrap_add(l309, 1)) {
			fRec281[l309] = 0.0f;
		}
		for (int l310 = 0; l310 < 3; l310 = faust_wrap_add(l310, 1)) {
			fRec280[l310] = 0.0f;
		}
		for (int l311 = 0; l311 < 2; l311 = faust_wrap_add(l311, 1)) {
			fRec289[l311] = 0.0f;
		}
		for (int l312 = 0; l312 < 3; l312 = faust_wrap_add(l312, 1)) {
			fRec288[l312] = 0.0f;
		}
		for (int l313 = 0; l313 < 2; l313 = faust_wrap_add(l313, 1)) {
			fRec292[l313] = 0.0f;
		}
		for (int l314 = 0; l314 < 3; l314 = faust_wrap_add(l314, 1)) {
			fRec291[l314] = 0.0f;
		}
		for (int l315 = 0; l315 < 3; l315 = faust_wrap_add(l315, 1)) {
			fRec290[l315] = 0.0f;
		}
		for (int l316 = 0; l316 < 2; l316 = faust_wrap_add(l316, 1)) {
			fRec296[l316] = 0.0f;
		}
		for (int l317 = 0; l317 < 3; l317 = faust_wrap_add(l317, 1)) {
			fRec295[l317] = 0.0f;
		}
		for (int l318 = 0; l318 < 3; l318 = faust_wrap_add(l318, 1)) {
			fRec294[l318] = 0.0f;
		}
		for (int l319 = 0; l319 < 3; l319 = faust_wrap_add(l319, 1)) {
			fRec293[l319] = 0.0f;
		}
		for (int l320 = 0; l320 < 2; l320 = faust_wrap_add(l320, 1)) {
			fRec301[l320] = 0.0f;
		}
		for (int l321 = 0; l321 < 3; l321 = faust_wrap_add(l321, 1)) {
			fRec300[l321] = 0.0f;
		}
		for (int l322 = 0; l322 < 3; l322 = faust_wrap_add(l322, 1)) {
			fRec299[l322] = 0.0f;
		}
		for (int l323 = 0; l323 < 3; l323 = faust_wrap_add(l323, 1)) {
			fRec298[l323] = 0.0f;
		}
		for (int l324 = 0; l324 < 3; l324 = faust_wrap_add(l324, 1)) {
			fRec297[l324] = 0.0f;
		}
		for (int l325 = 0; l325 < 2; l325 = faust_wrap_add(l325, 1)) {
			fRec309[l325] = 0.0f;
		}
		for (int l326 = 0; l326 < 3; l326 = faust_wrap_add(l326, 1)) {
			fRec308[l326] = 0.0f;
		}
		for (int l327 = 0; l327 < 2; l327 = faust_wrap_add(l327, 1)) {
			fVec39[l327] = 0.0f;
		}
		for (int l328 = 0; l328 < 2; l328 = faust_wrap_add(l328, 1)) {
			fRec307[l328] = 0.0f;
		}
		for (int l329 = 0; l329 < 3; l329 = faust_wrap_add(l329, 1)) {
			fRec306[l329] = 0.0f;
		}
		for (int l330 = 0; l330 < 2; l330 = faust_wrap_add(l330, 1)) {
			fVec40[l330] = 0.0f;
		}
		for (int l331 = 0; l331 < 2; l331 = faust_wrap_add(l331, 1)) {
			fRec305[l331] = 0.0f;
		}
		for (int l332 = 0; l332 < 3; l332 = faust_wrap_add(l332, 1)) {
			fRec304[l332] = 0.0f;
		}
		for (int l333 = 0; l333 < 2; l333 = faust_wrap_add(l333, 1)) {
			fVec41[l333] = 0.0f;
		}
		for (int l334 = 0; l334 < 2; l334 = faust_wrap_add(l334, 1)) {
			fRec303[l334] = 0.0f;
		}
		for (int l335 = 0; l335 < 3; l335 = faust_wrap_add(l335, 1)) {
			fRec302[l335] = 0.0f;
		}
		for (int l336 = 0; l336 < 2; l336 = faust_wrap_add(l336, 1)) {
			fRec311[l336] = 0.0f;
		}
		for (int l337 = 0; l337 < 3; l337 = faust_wrap_add(l337, 1)) {
			fRec310[l337] = 0.0f;
		}
		for (int l338 = 0; l338 < 2; l338 = faust_wrap_add(l338, 1)) {
			fRec314[l338] = 0.0f;
		}
		for (int l339 = 0; l339 < 3; l339 = faust_wrap_add(l339, 1)) {
			fRec313[l339] = 0.0f;
		}
		for (int l340 = 0; l340 < 3; l340 = faust_wrap_add(l340, 1)) {
			fRec312[l340] = 0.0f;
		}
		for (int l341 = 0; l341 < 2; l341 = faust_wrap_add(l341, 1)) {
			fRec318[l341] = 0.0f;
		}
		for (int l342 = 0; l342 < 3; l342 = faust_wrap_add(l342, 1)) {
			fRec317[l342] = 0.0f;
		}
		for (int l343 = 0; l343 < 3; l343 = faust_wrap_add(l343, 1)) {
			fRec316[l343] = 0.0f;
		}
		for (int l344 = 0; l344 < 3; l344 = faust_wrap_add(l344, 1)) {
			fRec315[l344] = 0.0f;
		}
		for (int l345 = 0; l345 < 2; l345 = faust_wrap_add(l345, 1)) {
			fRec323[l345] = 0.0f;
		}
		for (int l346 = 0; l346 < 3; l346 = faust_wrap_add(l346, 1)) {
			fRec322[l346] = 0.0f;
		}
		for (int l347 = 0; l347 < 3; l347 = faust_wrap_add(l347, 1)) {
			fRec321[l347] = 0.0f;
		}
		for (int l348 = 0; l348 < 3; l348 = faust_wrap_add(l348, 1)) {
			fRec320[l348] = 0.0f;
		}
		for (int l349 = 0; l349 < 3; l349 = faust_wrap_add(l349, 1)) {
			fRec319[l349] = 0.0f;
		}
		for (int l350 = 0; l350 < 2; l350 = faust_wrap_add(l350, 1)) {
			fRec331[l350] = 0.0f;
		}
		for (int l351 = 0; l351 < 3; l351 = faust_wrap_add(l351, 1)) {
			fRec330[l351] = 0.0f;
		}
		for (int l352 = 0; l352 < 2; l352 = faust_wrap_add(l352, 1)) {
			fVec42[l352] = 0.0f;
		}
		for (int l353 = 0; l353 < 2; l353 = faust_wrap_add(l353, 1)) {
			fRec329[l353] = 0.0f;
		}
		for (int l354 = 0; l354 < 3; l354 = faust_wrap_add(l354, 1)) {
			fRec328[l354] = 0.0f;
		}
		for (int l355 = 0; l355 < 2; l355 = faust_wrap_add(l355, 1)) {
			fVec43[l355] = 0.0f;
		}
		for (int l356 = 0; l356 < 2; l356 = faust_wrap_add(l356, 1)) {
			fRec327[l356] = 0.0f;
		}
		for (int l357 = 0; l357 < 3; l357 = faust_wrap_add(l357, 1)) {
			fRec326[l357] = 0.0f;
		}
		for (int l358 = 0; l358 < 2; l358 = faust_wrap_add(l358, 1)) {
			fVec44[l358] = 0.0f;
		}
		for (int l359 = 0; l359 < 2; l359 = faust_wrap_add(l359, 1)) {
			fRec325[l359] = 0.0f;
		}
		for (int l360 = 0; l360 < 3; l360 = faust_wrap_add(l360, 1)) {
			fRec324[l360] = 0.0f;
		}
		for (int l361 = 0; l361 < 2; l361 = faust_wrap_add(l361, 1)) {
			fRec333[l361] = 0.0f;
		}
		for (int l362 = 0; l362 < 3; l362 = faust_wrap_add(l362, 1)) {
			fRec332[l362] = 0.0f;
		}
		for (int l363 = 0; l363 < 2; l363 = faust_wrap_add(l363, 1)) {
			fRec336[l363] = 0.0f;
		}
		for (int l364 = 0; l364 < 3; l364 = faust_wrap_add(l364, 1)) {
			fRec335[l364] = 0.0f;
		}
		for (int l365 = 0; l365 < 3; l365 = faust_wrap_add(l365, 1)) {
			fRec334[l365] = 0.0f;
		}
		for (int l366 = 0; l366 < 2; l366 = faust_wrap_add(l366, 1)) {
			fRec340[l366] = 0.0f;
		}
		for (int l367 = 0; l367 < 3; l367 = faust_wrap_add(l367, 1)) {
			fRec339[l367] = 0.0f;
		}
		for (int l368 = 0; l368 < 3; l368 = faust_wrap_add(l368, 1)) {
			fRec338[l368] = 0.0f;
		}
		for (int l369 = 0; l369 < 3; l369 = faust_wrap_add(l369, 1)) {
			fRec337[l369] = 0.0f;
		}
		for (int l370 = 0; l370 < 2; l370 = faust_wrap_add(l370, 1)) {
			fRec345[l370] = 0.0f;
		}
		for (int l371 = 0; l371 < 3; l371 = faust_wrap_add(l371, 1)) {
			fRec344[l371] = 0.0f;
		}
		for (int l372 = 0; l372 < 3; l372 = faust_wrap_add(l372, 1)) {
			fRec343[l372] = 0.0f;
		}
		for (int l373 = 0; l373 < 3; l373 = faust_wrap_add(l373, 1)) {
			fRec342[l373] = 0.0f;
		}
		for (int l374 = 0; l374 < 3; l374 = faust_wrap_add(l374, 1)) {
			fRec341[l374] = 0.0f;
		}
		for (int l375 = 0; l375 < 2; l375 = faust_wrap_add(l375, 1)) {
			fRec353[l375] = 0.0f;
		}
		for (int l376 = 0; l376 < 3; l376 = faust_wrap_add(l376, 1)) {
			fRec352[l376] = 0.0f;
		}
		for (int l377 = 0; l377 < 2; l377 = faust_wrap_add(l377, 1)) {
			fVec45[l377] = 0.0f;
		}
		for (int l378 = 0; l378 < 2; l378 = faust_wrap_add(l378, 1)) {
			fRec351[l378] = 0.0f;
		}
		for (int l379 = 0; l379 < 3; l379 = faust_wrap_add(l379, 1)) {
			fRec350[l379] = 0.0f;
		}
		for (int l380 = 0; l380 < 2; l380 = faust_wrap_add(l380, 1)) {
			fVec46[l380] = 0.0f;
		}
		for (int l381 = 0; l381 < 2; l381 = faust_wrap_add(l381, 1)) {
			fRec349[l381] = 0.0f;
		}
		for (int l382 = 0; l382 < 3; l382 = faust_wrap_add(l382, 1)) {
			fRec348[l382] = 0.0f;
		}
		for (int l383 = 0; l383 < 2; l383 = faust_wrap_add(l383, 1)) {
			fVec47[l383] = 0.0f;
		}
		for (int l384 = 0; l384 < 2; l384 = faust_wrap_add(l384, 1)) {
			fRec347[l384] = 0.0f;
		}
		for (int l385 = 0; l385 < 3; l385 = faust_wrap_add(l385, 1)) {
			fRec346[l385] = 0.0f;
		}
		for (int l386 = 0; l386 < 2; l386 = faust_wrap_add(l386, 1)) {
			fRec355[l386] = 0.0f;
		}
		for (int l387 = 0; l387 < 3; l387 = faust_wrap_add(l387, 1)) {
			fRec354[l387] = 0.0f;
		}
		for (int l388 = 0; l388 < 2; l388 = faust_wrap_add(l388, 1)) {
			fRec358[l388] = 0.0f;
		}
		for (int l389 = 0; l389 < 3; l389 = faust_wrap_add(l389, 1)) {
			fRec357[l389] = 0.0f;
		}
		for (int l390 = 0; l390 < 3; l390 = faust_wrap_add(l390, 1)) {
			fRec356[l390] = 0.0f;
		}
		for (int l391 = 0; l391 < 2; l391 = faust_wrap_add(l391, 1)) {
			fRec362[l391] = 0.0f;
		}
		for (int l392 = 0; l392 < 3; l392 = faust_wrap_add(l392, 1)) {
			fRec361[l392] = 0.0f;
		}
		for (int l393 = 0; l393 < 3; l393 = faust_wrap_add(l393, 1)) {
			fRec360[l393] = 0.0f;
		}
		for (int l394 = 0; l394 < 3; l394 = faust_wrap_add(l394, 1)) {
			fRec359[l394] = 0.0f;
		}
		for (int l395 = 0; l395 < 2; l395 = faust_wrap_add(l395, 1)) {
			fRec367[l395] = 0.0f;
		}
		for (int l396 = 0; l396 < 3; l396 = faust_wrap_add(l396, 1)) {
			fRec366[l396] = 0.0f;
		}
		for (int l397 = 0; l397 < 3; l397 = faust_wrap_add(l397, 1)) {
			fRec365[l397] = 0.0f;
		}
		for (int l398 = 0; l398 < 3; l398 = faust_wrap_add(l398, 1)) {
			fRec364[l398] = 0.0f;
		}
		for (int l399 = 0; l399 < 3; l399 = faust_wrap_add(l399, 1)) {
			fRec363[l399] = 0.0f;
		}
		IOTA0 = 0;
		for (int l400 = 0; l400 < 16384; l400 = faust_wrap_add(l400, 1)) {
			fVec48[l400] = 0.0f;
		}
		for (int l401 = 0; l401 < 3; l401 = faust_wrap_add(l401, 1)) {
			fRec0[l401] = 0.0f;
		}
		for (int l402 = 0; l402 < 16384; l402 = faust_wrap_add(l402, 1)) {
			fVec49[l402] = 0.0f;
		}
		for (int l403 = 0; l403 < 3; l403 = faust_wrap_add(l403, 1)) {
			fRec1[l403] = 0.0f;
		}
		for (int l404 = 0; l404 < 16384; l404 = faust_wrap_add(l404, 1)) {
			fVec50[l404] = 0.0f;
		}
		for (int l405 = 0; l405 < 3; l405 = faust_wrap_add(l405, 1)) {
			fRec2[l405] = 0.0f;
		}
		for (int l406 = 0; l406 < 16384; l406 = faust_wrap_add(l406, 1)) {
			fVec51[l406] = 0.0f;
		}
		for (int l407 = 0; l407 < 3; l407 = faust_wrap_add(l407, 1)) {
			fRec3[l407] = 0.0f;
		}
		for (int l408 = 0; l408 < 16384; l408 = faust_wrap_add(l408, 1)) {
			fVec52[l408] = 0.0f;
		}
		for (int l409 = 0; l409 < 3; l409 = faust_wrap_add(l409, 1)) {
			fRec4[l409] = 0.0f;
		}
		for (int l410 = 0; l410 < 16384; l410 = faust_wrap_add(l410, 1)) {
			fVec53[l410] = 0.0f;
		}
		for (int l411 = 0; l411 < 3; l411 = faust_wrap_add(l411, 1)) {
			fRec5[l411] = 0.0f;
		}
		for (int l412 = 0; l412 < 16384; l412 = faust_wrap_add(l412, 1)) {
			fVec54[l412] = 0.0f;
		}
		for (int l413 = 0; l413 < 3; l413 = faust_wrap_add(l413, 1)) {
			fRec6[l413] = 0.0f;
		}
		for (int l414 = 0; l414 < 16384; l414 = faust_wrap_add(l414, 1)) {
			fVec55[l414] = 0.0f;
		}
		for (int l415 = 0; l415 < 3; l415 = faust_wrap_add(l415, 1)) {
			fRec7[l415] = 0.0f;
		}
		for (int l416 = 0; l416 < 16384; l416 = faust_wrap_add(l416, 1)) {
			fVec56[l416] = 0.0f;
		}
		for (int l417 = 0; l417 < 3; l417 = faust_wrap_add(l417, 1)) {
			fRec8[l417] = 0.0f;
		}
		for (int l418 = 0; l418 < 16384; l418 = faust_wrap_add(l418, 1)) {
			fVec57[l418] = 0.0f;
		}
		for (int l419 = 0; l419 < 3; l419 = faust_wrap_add(l419, 1)) {
			fRec9[l419] = 0.0f;
		}
		for (int l420 = 0; l420 < 16384; l420 = faust_wrap_add(l420, 1)) {
			fVec58[l420] = 0.0f;
		}
		for (int l421 = 0; l421 < 3; l421 = faust_wrap_add(l421, 1)) {
			fRec10[l421] = 0.0f;
		}
		for (int l422 = 0; l422 < 16384; l422 = faust_wrap_add(l422, 1)) {
			fVec59[l422] = 0.0f;
		}
		for (int l423 = 0; l423 < 3; l423 = faust_wrap_add(l423, 1)) {
			fRec11[l423] = 0.0f;
		}
		for (int l424 = 0; l424 < 16384; l424 = faust_wrap_add(l424, 1)) {
			fVec60[l424] = 0.0f;
		}
		for (int l425 = 0; l425 < 3; l425 = faust_wrap_add(l425, 1)) {
			fRec12[l425] = 0.0f;
		}
		for (int l426 = 0; l426 < 16384; l426 = faust_wrap_add(l426, 1)) {
			fVec61[l426] = 0.0f;
		}
		for (int l427 = 0; l427 < 3; l427 = faust_wrap_add(l427, 1)) {
			fRec13[l427] = 0.0f;
		}
		for (int l428 = 0; l428 < 16384; l428 = faust_wrap_add(l428, 1)) {
			fVec62[l428] = 0.0f;
		}
		for (int l429 = 0; l429 < 3; l429 = faust_wrap_add(l429, 1)) {
			fRec14[l429] = 0.0f;
		}
		for (int l430 = 0; l430 < 16384; l430 = faust_wrap_add(l430, 1)) {
			fVec63[l430] = 0.0f;
		}
		for (int l431 = 0; l431 < 3; l431 = faust_wrap_add(l431, 1)) {
			fRec15[l431] = 0.0f;
		}
		for (int l432 = 0; l432 < 2; l432 = faust_wrap_add(l432, 1)) {
			fRec368[l432] = 0.0f;
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
	
	virtual LibFdnReverb* clone() {
		return new LibFdnReverb(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("FDN Reverb 16");
		ui_interface->declare(&fHslider3, "0", "");
		ui_interface->declare(&fHslider3, "scale", "log");
		ui_interface->declare(&fHslider3, "unit", "m");
		ui_interface->addHorizontalSlider("Room Min", &fHslider3, FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.5f), FAUSTFLOAT(63.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "scale", "log");
		ui_interface->declare(&fHslider1, "unit", "m");
		ui_interface->addHorizontalSlider("Room Max", &fHslider1, FAUSTFLOAT(45.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(63.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->declare(&fHslider0, "unit", "s");
		ui_interface->addHorizontalSlider("Low RT60", &fHslider0, FAUSTFLOAT(3.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider2, "3", "");
		ui_interface->declare(&fHslider2, "unit", "s");
		ui_interface->addHorizontalSlider("High RT60", &fHslider2, FAUSTFLOAT(1.2f), FAUSTFLOAT(0.1f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider4, "4", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider4, FAUSTFLOAT(0.35f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = static_cast<float>(fHslider0);
		float fSlow1 = static_cast<float>(fHslider1);
		float fSlow2 = std::pow(53.0f, std::floor(0.25187066f * std::log(fConst39 * fSlow1) + 0.5f));
		float fSlow3 = std::exp(-(fConst40 * (fSlow2 / fSlow0)));
		float fSlow4 = static_cast<float>(fHslider2);
		float fSlow5 = fSlow0 - fSlow4;
		float fSlow6 = fSlow4 + 0.75f * fSlow5;
		float fSlow7 = fConst2 * std::exp(-(fConst40 * (fSlow2 / fSlow6)));
		float fSlow8 = fSlow4 + 0.5f * fSlow5;
		float fSlow9 = std::exp(-(fConst40 * (fSlow2 / fSlow8)));
		float fSlow10 = fSlow4 + 0.25f * fSlow5;
		float fSlow11 = std::exp(-(fConst40 * (fSlow2 / fSlow10)));
		float fSlow12 = std::exp(-(fConst40 * (fSlow2 / fSlow4)));
		float fSlow13 = static_cast<float>(fHslider3);
		float fSlow14 = fSlow1 / fSlow13;
		float fSlow15 = std::pow(19.0f, std::floor(0.33962327f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.46666667f)) + 0.5f));
		float fSlow16 = std::exp(-(fConst40 * (fSlow15 / fSlow0)));
		float fSlow17 = fConst2 * std::exp(-(fConst40 * (fSlow15 / fSlow6)));
		float fSlow18 = std::exp(-(fConst40 * (fSlow15 / fSlow8)));
		float fSlow19 = std::exp(-(fConst40 * (fSlow15 / fSlow10)));
		float fSlow20 = std::exp(-(fConst40 * (fSlow15 / fSlow4)));
		float fSlow21 = std::pow(37.0f, std::floor(0.2769379f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.73333335f)) + 0.5f));
		float fSlow22 = std::exp(-(fConst40 * (fSlow21 / fSlow0)));
		float fSlow23 = fConst2 * std::exp(-(fConst40 * (fSlow21 / fSlow6)));
		float fSlow24 = std::exp(-(fConst40 * (fSlow21 / fSlow8)));
		float fSlow25 = std::exp(-(fConst40 * (fSlow21 / fSlow10)));
		float fSlow26 = std::exp(-(fConst40 * (fSlow21 / fSlow4)));
		float fSlow27 = std::pow(7.0f, std::floor(0.5138983f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.2f)) + 0.5f));
		float fSlow28 = std::exp(-(fConst40 * (fSlow27 / fSlow0)));
		float fSlow29 = fConst2 * std::exp(-(fConst40 * (fSlow27 / fSlow6)));
		float fSlow30 = std::exp(-(fConst40 * (fSlow27 / fSlow8)));
		float fSlow31 = std::exp(-(fConst40 * (fSlow27 / fSlow10)));
		float fSlow32 = std::exp(-(fConst40 * (fSlow27 / fSlow4)));
		float fSlow33 = std::pow(43.0f, std::floor(0.2658726f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.8666667f)) + 0.5f));
		float fSlow34 = std::exp(-(fConst40 * (fSlow33 / fSlow0)));
		float fSlow35 = fConst2 * std::exp(-(fConst40 * (fSlow33 / fSlow6)));
		float fSlow36 = std::exp(-(fConst40 * (fSlow33 / fSlow8)));
		float fSlow37 = std::exp(-(fConst40 * (fSlow33 / fSlow10)));
		float fSlow38 = std::exp(-(fConst40 * (fSlow33 / fSlow4)));
		float fSlow39 = std::pow(13.0f, std::floor(0.38987124f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.33333334f)) + 0.5f));
		float fSlow40 = std::exp(-(fConst40 * (fSlow39 / fSlow0)));
		float fSlow41 = fConst2 * std::exp(-(fConst40 * (fSlow39 / fSlow6)));
		float fSlow42 = std::exp(-(fConst40 * (fSlow39 / fSlow8)));
		float fSlow43 = std::exp(-(fConst40 * (fSlow39 / fSlow10)));
		float fSlow44 = std::exp(-(fConst40 * (fSlow39 / fSlow4)));
		float fSlow45 = std::pow(29.0f, std::floor(0.2969742f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.6f)) + 0.5f));
		float fSlow46 = std::exp(-(fConst40 * (fSlow45 / fSlow0)));
		float fSlow47 = fConst2 * std::exp(-(fConst40 * (fSlow45 / fSlow6)));
		float fSlow48 = std::exp(-(fConst40 * (fSlow45 / fSlow8)));
		float fSlow49 = std::exp(-(fConst40 * (fSlow45 / fSlow10)));
		float fSlow50 = std::exp(-(fConst40 * (fSlow45 / fSlow4)));
		float fSlow51 = std::pow(3.0f, std::floor(0.9102392f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.06666667f)) + 0.5f));
		float fSlow52 = std::exp(-(fConst40 * (fSlow51 / fSlow0)));
		float fSlow53 = fConst2 * std::exp(-(fConst40 * (fSlow51 / fSlow6)));
		float fSlow54 = std::exp(-(fConst40 * (fSlow51 / fSlow8)));
		float fSlow55 = std::exp(-(fConst40 * (fSlow51 / fSlow10)));
		float fSlow56 = std::exp(-(fConst40 * (fSlow51 / fSlow4)));
		float fSlow57 = std::pow(47.0f, std::floor(0.2597303f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.93333334f)) + 0.5f));
		float fSlow58 = std::exp(-(fConst40 * (fSlow57 / fSlow0)));
		float fSlow59 = fConst2 * std::exp(-(fConst40 * (fSlow57 / fSlow6)));
		float fSlow60 = std::exp(-(fConst40 * (fSlow57 / fSlow8)));
		float fSlow61 = std::exp(-(fConst40 * (fSlow57 / fSlow10)));
		float fSlow62 = std::exp(-(fConst40 * (fSlow57 / fSlow4)));
		float fSlow63 = std::pow(17.0f, std::floor(0.35295612f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.4f)) + 0.5f));
		float fSlow64 = std::exp(-(fConst40 * (fSlow63 / fSlow0)));
		float fSlow65 = fConst2 * std::exp(-(fConst40 * (fSlow63 / fSlow6)));
		float fSlow66 = std::exp(-(fConst40 * (fSlow63 / fSlow8)));
		float fSlow67 = std::exp(-(fConst40 * (fSlow63 / fSlow10)));
		float fSlow68 = std::exp(-(fConst40 * (fSlow63 / fSlow4)));
		float fSlow69 = std::pow(31.0f, std::floor(0.2912067f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.6666667f)) + 0.5f));
		float fSlow70 = std::exp(-(fConst40 * (fSlow69 / fSlow0)));
		float fSlow71 = fConst2 * std::exp(-(fConst40 * (fSlow69 / fSlow6)));
		float fSlow72 = std::exp(-(fConst40 * (fSlow69 / fSlow8)));
		float fSlow73 = std::exp(-(fConst40 * (fSlow69 / fSlow10)));
		float fSlow74 = std::exp(-(fConst40 * (fSlow69 / fSlow4)));
		float fSlow75 = std::pow(5.0f, std::floor(0.6213349f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.13333334f)) + 0.5f));
		float fSlow76 = std::exp(-(fConst40 * (fSlow75 / fSlow0)));
		float fSlow77 = fConst2 * std::exp(-(fConst40 * (fSlow75 / fSlow6)));
		float fSlow78 = std::exp(-(fConst40 * (fSlow75 / fSlow8)));
		float fSlow79 = std::exp(-(fConst40 * (fSlow75 / fSlow10)));
		float fSlow80 = std::exp(-(fConst40 * (fSlow75 / fSlow4)));
		float fSlow81 = std::pow(41.0f, std::floor(0.26928252f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.8f)) + 0.5f));
		float fSlow82 = std::exp(-(fConst40 * (fSlow81 / fSlow0)));
		float fSlow83 = fConst2 * std::exp(-(fConst40 * (fSlow81 / fSlow6)));
		float fSlow84 = std::exp(-(fConst40 * (fSlow81 / fSlow8)));
		float fSlow85 = std::exp(-(fConst40 * (fSlow81 / fSlow10)));
		float fSlow86 = std::exp(-(fConst40 * (fSlow81 / fSlow4)));
		float fSlow87 = std::pow(11.0f, std::floor(0.4170324f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.26666668f)) + 0.5f));
		float fSlow88 = std::exp(-(fConst40 * (fSlow87 / fSlow0)));
		float fSlow89 = fConst2 * std::exp(-(fConst40 * (fSlow87 / fSlow6)));
		float fSlow90 = std::exp(-(fConst40 * (fSlow87 / fSlow8)));
		float fSlow91 = std::exp(-(fConst40 * (fSlow87 / fSlow10)));
		float fSlow92 = std::exp(-(fConst40 * (fSlow87 / fSlow4)));
		float fSlow93 = std::pow(23.0f, std::floor(0.318929f * std::log(fConst39 * fSlow13 * std::pow(fSlow14, 0.53333336f)) + 0.5f));
		float fSlow94 = std::exp(-(fConst40 * (fSlow93 / fSlow0)));
		float fSlow95 = fConst2 * std::exp(-(fConst40 * (fSlow93 / fSlow6)));
		float fSlow96 = std::exp(-(fConst40 * (fSlow93 / fSlow8)));
		float fSlow97 = std::exp(-(fConst40 * (fSlow93 / fSlow10)));
		float fSlow98 = std::exp(-(fConst40 * (fSlow93 / fSlow4)));
		float fSlow99 = std::pow(2.0f, std::floor(1.442695f * std::log(fConst39 * fSlow13) + 0.5f));
		float fSlow100 = std::exp(-(fConst40 * (fSlow99 / fSlow0)));
		float fSlow101 = fConst2 * std::exp(-(fConst40 * (fSlow99 / fSlow6)));
		float fSlow102 = std::exp(-(fConst40 * (fSlow99 / fSlow8)));
		float fSlow103 = std::exp(-(fConst40 * (fSlow99 / fSlow10)));
		float fSlow104 = std::exp(-(fConst40 * (fSlow99 / fSlow4)));
		int iSlow105 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow99 + -1.0f)));
		int iSlow106 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow51 + -1.0f)));
		int iSlow107 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow75 + -1.0f)));
		int iSlow108 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow27 + -1.0f)));
		int iSlow109 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow87 + -1.0f)));
		int iSlow110 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow39 + -1.0f)));
		int iSlow111 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow63 + -1.0f)));
		int iSlow112 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow15 + -1.0f)));
		int iSlow113 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow93 + -1.0f)));
		int iSlow114 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow45 + -1.0f)));
		int iSlow115 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow69 + -1.0f)));
		int iSlow116 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow21 + -1.0f)));
		int iSlow117 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow81 + -1.0f)));
		int iSlow118 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow33 + -1.0f)));
		int iSlow119 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow57 + -1.0f)));
		int iSlow120 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fSlow2 + -1.0f)));
		float fSlow121 = fConst53 * static_cast<float>(fHslider4);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec23[0] = -(fConst29 * (fConst28 * fRec23[1] - (fRec15[1] + fRec15[2])));
			fRec22[0] = fRec23[0] - fConst27 * (fConst25 * fRec22[2] + fConst23 * fRec22[1]);
			float fTemp0 = fRec22[2] + fRec22[0] + 2.0f * fRec22[1];
			fVec0[0] = fTemp0;
			fRec21[0] = -(fConst32 * (fConst30 * fRec21[1] - fConst27 * (fTemp0 + fVec0[1])));
			fRec20[0] = fRec21[0] - fConst20 * (fConst18 * fRec20[2] + fConst16 * fRec20[1]);
			float fTemp1 = fRec20[2] + fRec20[0] + 2.0f * fRec20[1];
			fVec1[0] = fTemp1;
			fRec19[0] = -(fConst35 * (fConst33 * fRec19[1] - fConst20 * (fTemp1 + fVec1[1])));
			fRec18[0] = fRec19[0] - fConst13 * (fConst11 * fRec18[2] + fConst9 * fRec18[1]);
			float fTemp2 = fRec18[2] + fRec18[0] + 2.0f * fRec18[1];
			fVec2[0] = fTemp2;
			fRec17[0] = -(fConst38 * (fConst36 * fRec17[1] - fConst13 * (fTemp2 + fVec2[1])));
			fRec16[0] = fRec17[0] - fConst6 * (fConst5 * fRec16[2] + fConst3 * fRec16[1]);
			fRec25[0] = -(fConst38 * (fConst36 * fRec25[1] - fConst41 * (fTemp2 - fVec2[1])));
			fRec24[0] = fRec25[0] - fConst6 * (fConst5 * fRec24[2] + fConst3 * fRec24[1]);
			float fTemp3 = fConst3 * fRec26[1];
			fRec28[0] = -(fConst35 * (fConst33 * fRec28[1] - fConst44 * (fTemp1 - fVec1[1])));
			fRec27[0] = fRec28[0] - fConst13 * (fConst11 * fRec27[2] + fConst9 * fRec27[1]);
			fRec26[0] = fConst45 * (fRec27[2] + (fRec27[0] - 2.0f * fRec27[1])) - fConst43 * (fConst42 * fRec26[2] + fTemp3);
			float fTemp4 = fConst3 * fRec29[1];
			float fTemp5 = fConst9 * fRec30[1];
			fRec32[0] = -(fConst32 * (fConst30 * fRec32[1] - fConst48 * (fTemp0 - fVec0[1])));
			fRec31[0] = fRec32[0] - fConst20 * (fConst18 * fRec31[2] + fConst16 * fRec31[1]);
			fRec30[0] = fConst49 * (fRec31[2] + (fRec31[0] - 2.0f * fRec31[1])) - fConst47 * (fConst46 * fRec30[2] + fTemp5);
			fRec29[0] = fRec30[2] + fConst47 * (fTemp5 + fConst46 * fRec30[0]) - fConst43 * (fConst42 * fRec29[2] + fTemp4);
			float fTemp6 = fConst3 * fRec33[1];
			float fTemp7 = fConst9 * fRec34[1];
			float fTemp8 = fConst16 * fRec35[1];
			fRec37[0] = -(fConst29 * (fConst28 * fRec37[1] - fConst24 * (fRec15[1] - fRec15[2])));
			fRec36[0] = fRec37[0] - fConst27 * (fConst25 * fRec36[2] + fConst23 * fRec36[1]);
			fRec35[0] = fConst52 * (fRec36[2] + (fRec36[0] - 2.0f * fRec36[1])) - fConst51 * (fConst50 * fRec35[2] + fTemp8);
			fRec34[0] = fRec35[2] + fConst51 * (fTemp8 + fConst50 * fRec35[0]) - fConst47 * (fConst46 * fRec34[2] + fTemp7);
			fRec33[0] = fRec34[2] + fConst47 * (fTemp7 + fConst46 * fRec34[0]) - fConst43 * (fConst42 * fRec33[2] + fTemp6);
			float fTemp9 = fSlow12 * (fRec33[2] + fConst43 * (fTemp6 + fConst42 * fRec33[0])) + fSlow11 * (fRec29[2] + fConst43 * (fTemp4 + fConst42 * fRec29[0])) + fSlow9 * (fRec26[2] + fConst43 * (fTemp3 + fConst42 * fRec26[0])) + fConst6 * (fSlow7 * (fRec24[2] + (fRec24[0] - 2.0f * fRec24[1])) + fSlow3 * (fRec16[2] + fRec16[0] + 2.0f * fRec16[1]));
			fRec45[0] = -(fConst29 * (fConst28 * fRec45[1] - (fRec7[1] + fRec7[2])));
			fRec44[0] = fRec45[0] - fConst27 * (fConst25 * fRec44[2] + fConst23 * fRec44[1]);
			float fTemp10 = fRec44[2] + fRec44[0] + 2.0f * fRec44[1];
			fVec3[0] = fTemp10;
			fRec43[0] = -(fConst32 * (fConst30 * fRec43[1] - fConst27 * (fTemp10 + fVec3[1])));
			fRec42[0] = fRec43[0] - fConst20 * (fConst18 * fRec42[2] + fConst16 * fRec42[1]);
			float fTemp11 = fRec42[2] + fRec42[0] + 2.0f * fRec42[1];
			fVec4[0] = fTemp11;
			fRec41[0] = -(fConst35 * (fConst33 * fRec41[1] - fConst20 * (fTemp11 + fVec4[1])));
			fRec40[0] = fRec41[0] - fConst13 * (fConst11 * fRec40[2] + fConst9 * fRec40[1]);
			float fTemp12 = fRec40[2] + fRec40[0] + 2.0f * fRec40[1];
			fVec5[0] = fTemp12;
			fRec39[0] = -(fConst38 * (fConst36 * fRec39[1] - fConst13 * (fTemp12 + fVec5[1])));
			fRec38[0] = fRec39[0] - fConst6 * (fConst5 * fRec38[2] + fConst3 * fRec38[1]);
			fRec47[0] = -(fConst38 * (fConst36 * fRec47[1] - fConst41 * (fTemp12 - fVec5[1])));
			fRec46[0] = fRec47[0] - fConst6 * (fConst5 * fRec46[2] + fConst3 * fRec46[1]);
			float fTemp13 = fConst3 * fRec48[1];
			fRec50[0] = -(fConst35 * (fConst33 * fRec50[1] - fConst44 * (fTemp11 - fVec4[1])));
			fRec49[0] = fRec50[0] - fConst13 * (fConst11 * fRec49[2] + fConst9 * fRec49[1]);
			fRec48[0] = fConst45 * (fRec49[2] + (fRec49[0] - 2.0f * fRec49[1])) - fConst43 * (fConst42 * fRec48[2] + fTemp13);
			float fTemp14 = fConst3 * fRec51[1];
			float fTemp15 = fConst9 * fRec52[1];
			fRec54[0] = -(fConst32 * (fConst30 * fRec54[1] - fConst48 * (fTemp10 - fVec3[1])));
			fRec53[0] = fRec54[0] - fConst20 * (fConst18 * fRec53[2] + fConst16 * fRec53[1]);
			fRec52[0] = fConst49 * (fRec53[2] + (fRec53[0] - 2.0f * fRec53[1])) - fConst47 * (fConst46 * fRec52[2] + fTemp15);
			fRec51[0] = fRec52[2] + fConst47 * (fTemp15 + fConst46 * fRec52[0]) - fConst43 * (fConst42 * fRec51[2] + fTemp14);
			float fTemp16 = fConst3 * fRec55[1];
			float fTemp17 = fConst9 * fRec56[1];
			float fTemp18 = fConst16 * fRec57[1];
			fRec59[0] = -(fConst29 * (fConst28 * fRec59[1] - fConst24 * (fRec7[1] - fRec7[2])));
			fRec58[0] = fRec59[0] - fConst27 * (fConst25 * fRec58[2] + fConst23 * fRec58[1]);
			fRec57[0] = fConst52 * (fRec58[2] + (fRec58[0] - 2.0f * fRec58[1])) - fConst51 * (fConst50 * fRec57[2] + fTemp18);
			fRec56[0] = fRec57[2] + fConst51 * (fTemp18 + fConst50 * fRec57[0]) - fConst47 * (fConst46 * fRec56[2] + fTemp17);
			fRec55[0] = fRec56[2] + fConst47 * (fTemp17 + fConst46 * fRec56[0]) - fConst43 * (fConst42 * fRec55[2] + fTemp16);
			float fTemp19 = fSlow20 * (fRec55[2] + fConst43 * (fTemp16 + fConst42 * fRec55[0])) + fSlow19 * (fRec51[2] + fConst43 * (fTemp14 + fConst42 * fRec51[0])) + fSlow18 * (fRec48[2] + fConst43 * (fTemp13 + fConst42 * fRec48[0])) + fConst6 * (fSlow17 * (fRec46[2] + (fRec46[0] - 2.0f * fRec46[1])) + fSlow16 * (fRec38[2] + fRec38[0] + 2.0f * fRec38[1]));
			float fTemp20 = fTemp19 + fTemp9;
			fRec67[0] = -(fConst29 * (fConst28 * fRec67[1] - (fRec11[1] + fRec11[2])));
			fRec66[0] = fRec67[0] - fConst27 * (fConst25 * fRec66[2] + fConst23 * fRec66[1]);
			float fTemp21 = fRec66[2] + fRec66[0] + 2.0f * fRec66[1];
			fVec6[0] = fTemp21;
			fRec65[0] = -(fConst32 * (fConst30 * fRec65[1] - fConst27 * (fTemp21 + fVec6[1])));
			fRec64[0] = fRec65[0] - fConst20 * (fConst18 * fRec64[2] + fConst16 * fRec64[1]);
			float fTemp22 = fRec64[2] + fRec64[0] + 2.0f * fRec64[1];
			fVec7[0] = fTemp22;
			fRec63[0] = -(fConst35 * (fConst33 * fRec63[1] - fConst20 * (fTemp22 + fVec7[1])));
			fRec62[0] = fRec63[0] - fConst13 * (fConst11 * fRec62[2] + fConst9 * fRec62[1]);
			float fTemp23 = fRec62[2] + fRec62[0] + 2.0f * fRec62[1];
			fVec8[0] = fTemp23;
			fRec61[0] = -(fConst38 * (fConst36 * fRec61[1] - fConst13 * (fTemp23 + fVec8[1])));
			fRec60[0] = fRec61[0] - fConst6 * (fConst5 * fRec60[2] + fConst3 * fRec60[1]);
			fRec69[0] = -(fConst38 * (fConst36 * fRec69[1] - fConst41 * (fTemp23 - fVec8[1])));
			fRec68[0] = fRec69[0] - fConst6 * (fConst5 * fRec68[2] + fConst3 * fRec68[1]);
			float fTemp24 = fConst3 * fRec70[1];
			fRec72[0] = -(fConst35 * (fConst33 * fRec72[1] - fConst44 * (fTemp22 - fVec7[1])));
			fRec71[0] = fRec72[0] - fConst13 * (fConst11 * fRec71[2] + fConst9 * fRec71[1]);
			fRec70[0] = fConst45 * (fRec71[2] + (fRec71[0] - 2.0f * fRec71[1])) - fConst43 * (fConst42 * fRec70[2] + fTemp24);
			float fTemp25 = fConst3 * fRec73[1];
			float fTemp26 = fConst9 * fRec74[1];
			fRec76[0] = -(fConst32 * (fConst30 * fRec76[1] - fConst48 * (fTemp21 - fVec6[1])));
			fRec75[0] = fRec76[0] - fConst20 * (fConst18 * fRec75[2] + fConst16 * fRec75[1]);
			fRec74[0] = fConst49 * (fRec75[2] + (fRec75[0] - 2.0f * fRec75[1])) - fConst47 * (fConst46 * fRec74[2] + fTemp26);
			fRec73[0] = fRec74[2] + fConst47 * (fTemp26 + fConst46 * fRec74[0]) - fConst43 * (fConst42 * fRec73[2] + fTemp25);
			float fTemp27 = fConst3 * fRec77[1];
			float fTemp28 = fConst9 * fRec78[1];
			float fTemp29 = fConst16 * fRec79[1];
			fRec81[0] = -(fConst29 * (fConst28 * fRec81[1] - fConst24 * (fRec11[1] - fRec11[2])));
			fRec80[0] = fRec81[0] - fConst27 * (fConst25 * fRec80[2] + fConst23 * fRec80[1]);
			fRec79[0] = fConst52 * (fRec80[2] + (fRec80[0] - 2.0f * fRec80[1])) - fConst51 * (fConst50 * fRec79[2] + fTemp29);
			fRec78[0] = fRec79[2] + fConst51 * (fTemp29 + fConst50 * fRec79[0]) - fConst47 * (fConst46 * fRec78[2] + fTemp28);
			fRec77[0] = fRec78[2] + fConst47 * (fTemp28 + fConst46 * fRec78[0]) - fConst43 * (fConst42 * fRec77[2] + fTemp27);
			float fTemp30 = fSlow26 * (fRec77[2] + fConst43 * (fTemp27 + fConst42 * fRec77[0])) + fSlow25 * (fRec73[2] + fConst43 * (fTemp25 + fConst42 * fRec73[0])) + fSlow24 * (fRec70[2] + fConst43 * (fTemp24 + fConst42 * fRec70[0])) + fConst6 * (fSlow23 * (fRec68[2] + (fRec68[0] - 2.0f * fRec68[1])) + fSlow22 * (fRec60[2] + fRec60[0] + 2.0f * fRec60[1]));
			fRec89[0] = -(fConst29 * (fConst28 * fRec89[1] - (fRec3[1] + fRec3[2])));
			fRec88[0] = fRec89[0] - fConst27 * (fConst25 * fRec88[2] + fConst23 * fRec88[1]);
			float fTemp31 = fRec88[2] + fRec88[0] + 2.0f * fRec88[1];
			fVec9[0] = fTemp31;
			fRec87[0] = -(fConst32 * (fConst30 * fRec87[1] - fConst27 * (fTemp31 + fVec9[1])));
			fRec86[0] = fRec87[0] - fConst20 * (fConst18 * fRec86[2] + fConst16 * fRec86[1]);
			float fTemp32 = fRec86[2] + fRec86[0] + 2.0f * fRec86[1];
			fVec10[0] = fTemp32;
			fRec85[0] = -(fConst35 * (fConst33 * fRec85[1] - fConst20 * (fTemp32 + fVec10[1])));
			fRec84[0] = fRec85[0] - fConst13 * (fConst11 * fRec84[2] + fConst9 * fRec84[1]);
			float fTemp33 = fRec84[2] + fRec84[0] + 2.0f * fRec84[1];
			fVec11[0] = fTemp33;
			fRec83[0] = -(fConst38 * (fConst36 * fRec83[1] - fConst13 * (fTemp33 + fVec11[1])));
			fRec82[0] = fRec83[0] - fConst6 * (fConst5 * fRec82[2] + fConst3 * fRec82[1]);
			fRec91[0] = -(fConst38 * (fConst36 * fRec91[1] - fConst41 * (fTemp33 - fVec11[1])));
			fRec90[0] = fRec91[0] - fConst6 * (fConst5 * fRec90[2] + fConst3 * fRec90[1]);
			float fTemp34 = fConst3 * fRec92[1];
			fRec94[0] = -(fConst35 * (fConst33 * fRec94[1] - fConst44 * (fTemp32 - fVec10[1])));
			fRec93[0] = fRec94[0] - fConst13 * (fConst11 * fRec93[2] + fConst9 * fRec93[1]);
			fRec92[0] = fConst45 * (fRec93[2] + (fRec93[0] - 2.0f * fRec93[1])) - fConst43 * (fConst42 * fRec92[2] + fTemp34);
			float fTemp35 = fConst3 * fRec95[1];
			float fTemp36 = fConst9 * fRec96[1];
			fRec98[0] = -(fConst32 * (fConst30 * fRec98[1] - fConst48 * (fTemp31 - fVec9[1])));
			fRec97[0] = fRec98[0] - fConst20 * (fConst18 * fRec97[2] + fConst16 * fRec97[1]);
			fRec96[0] = fConst49 * (fRec97[2] + (fRec97[0] - 2.0f * fRec97[1])) - fConst47 * (fConst46 * fRec96[2] + fTemp36);
			fRec95[0] = fRec96[2] + fConst47 * (fTemp36 + fConst46 * fRec96[0]) - fConst43 * (fConst42 * fRec95[2] + fTemp35);
			float fTemp37 = fConst3 * fRec99[1];
			float fTemp38 = fConst9 * fRec100[1];
			float fTemp39 = fConst16 * fRec101[1];
			fRec103[0] = -(fConst29 * (fConst28 * fRec103[1] - fConst24 * (fRec3[1] - fRec3[2])));
			fRec102[0] = fRec103[0] - fConst27 * (fConst25 * fRec102[2] + fConst23 * fRec102[1]);
			fRec101[0] = fConst52 * (fRec102[2] + (fRec102[0] - 2.0f * fRec102[1])) - fConst51 * (fConst50 * fRec101[2] + fTemp39);
			fRec100[0] = fRec101[2] + fConst51 * (fTemp39 + fConst50 * fRec101[0]) - fConst47 * (fConst46 * fRec100[2] + fTemp38);
			fRec99[0] = fRec100[2] + fConst47 * (fTemp38 + fConst46 * fRec100[0]) - fConst43 * (fConst42 * fRec99[2] + fTemp37);
			float fTemp40 = fSlow32 * (fRec99[2] + fConst43 * (fTemp37 + fConst42 * fRec99[0])) + fSlow31 * (fRec95[2] + fConst43 * (fTemp35 + fConst42 * fRec95[0])) + fSlow30 * (fRec92[2] + fConst43 * (fTemp34 + fConst42 * fRec92[0])) + fConst6 * (fSlow29 * (fRec90[2] + (fRec90[0] - 2.0f * fRec90[1])) + fSlow28 * (fRec82[2] + fRec82[0] + 2.0f * fRec82[1]));
			float fTemp41 = fTemp40 + fTemp30;
			float fTemp42 = fTemp41 + fTemp20;
			fRec111[0] = -(fConst29 * (fConst28 * fRec111[1] - (fRec13[1] + fRec13[2])));
			fRec110[0] = fRec111[0] - fConst27 * (fConst25 * fRec110[2] + fConst23 * fRec110[1]);
			float fTemp43 = fRec110[2] + fRec110[0] + 2.0f * fRec110[1];
			fVec12[0] = fTemp43;
			fRec109[0] = -(fConst32 * (fConst30 * fRec109[1] - fConst27 * (fTemp43 + fVec12[1])));
			fRec108[0] = fRec109[0] - fConst20 * (fConst18 * fRec108[2] + fConst16 * fRec108[1]);
			float fTemp44 = fRec108[2] + fRec108[0] + 2.0f * fRec108[1];
			fVec13[0] = fTemp44;
			fRec107[0] = -(fConst35 * (fConst33 * fRec107[1] - fConst20 * (fTemp44 + fVec13[1])));
			fRec106[0] = fRec107[0] - fConst13 * (fConst11 * fRec106[2] + fConst9 * fRec106[1]);
			float fTemp45 = fRec106[2] + fRec106[0] + 2.0f * fRec106[1];
			fVec14[0] = fTemp45;
			fRec105[0] = -(fConst38 * (fConst36 * fRec105[1] - fConst13 * (fTemp45 + fVec14[1])));
			fRec104[0] = fRec105[0] - fConst6 * (fConst5 * fRec104[2] + fConst3 * fRec104[1]);
			fRec113[0] = -(fConst38 * (fConst36 * fRec113[1] - fConst41 * (fTemp45 - fVec14[1])));
			fRec112[0] = fRec113[0] - fConst6 * (fConst5 * fRec112[2] + fConst3 * fRec112[1]);
			float fTemp46 = fConst3 * fRec114[1];
			fRec116[0] = -(fConst35 * (fConst33 * fRec116[1] - fConst44 * (fTemp44 - fVec13[1])));
			fRec115[0] = fRec116[0] - fConst13 * (fConst11 * fRec115[2] + fConst9 * fRec115[1]);
			fRec114[0] = fConst45 * (fRec115[2] + (fRec115[0] - 2.0f * fRec115[1])) - fConst43 * (fConst42 * fRec114[2] + fTemp46);
			float fTemp47 = fConst3 * fRec117[1];
			float fTemp48 = fConst9 * fRec118[1];
			fRec120[0] = -(fConst32 * (fConst30 * fRec120[1] - fConst48 * (fTemp43 - fVec12[1])));
			fRec119[0] = fRec120[0] - fConst20 * (fConst18 * fRec119[2] + fConst16 * fRec119[1]);
			fRec118[0] = fConst49 * (fRec119[2] + (fRec119[0] - 2.0f * fRec119[1])) - fConst47 * (fConst46 * fRec118[2] + fTemp48);
			fRec117[0] = fRec118[2] + fConst47 * (fTemp48 + fConst46 * fRec118[0]) - fConst43 * (fConst42 * fRec117[2] + fTemp47);
			float fTemp49 = fConst3 * fRec121[1];
			float fTemp50 = fConst9 * fRec122[1];
			float fTemp51 = fConst16 * fRec123[1];
			fRec125[0] = -(fConst29 * (fConst28 * fRec125[1] - fConst24 * (fRec13[1] - fRec13[2])));
			fRec124[0] = fRec125[0] - fConst27 * (fConst25 * fRec124[2] + fConst23 * fRec124[1]);
			fRec123[0] = fConst52 * (fRec124[2] + (fRec124[0] - 2.0f * fRec124[1])) - fConst51 * (fConst50 * fRec123[2] + fTemp51);
			fRec122[0] = fRec123[2] + fConst51 * (fTemp51 + fConst50 * fRec123[0]) - fConst47 * (fConst46 * fRec122[2] + fTemp50);
			fRec121[0] = fRec122[2] + fConst47 * (fTemp50 + fConst46 * fRec122[0]) - fConst43 * (fConst42 * fRec121[2] + fTemp49);
			float fTemp52 = fSlow38 * (fRec121[2] + fConst43 * (fTemp49 + fConst42 * fRec121[0])) + fSlow37 * (fRec117[2] + fConst43 * (fTemp47 + fConst42 * fRec117[0])) + fSlow36 * (fRec114[2] + fConst43 * (fTemp46 + fConst42 * fRec114[0])) + fConst6 * (fSlow35 * (fRec112[2] + (fRec112[0] - 2.0f * fRec112[1])) + fSlow34 * (fRec104[2] + fRec104[0] + 2.0f * fRec104[1]));
			fRec133[0] = -(fConst29 * (fConst28 * fRec133[1] - (fRec5[1] + fRec5[2])));
			fRec132[0] = fRec133[0] - fConst27 * (fConst25 * fRec132[2] + fConst23 * fRec132[1]);
			float fTemp53 = fRec132[2] + fRec132[0] + 2.0f * fRec132[1];
			fVec15[0] = fTemp53;
			fRec131[0] = -(fConst32 * (fConst30 * fRec131[1] - fConst27 * (fTemp53 + fVec15[1])));
			fRec130[0] = fRec131[0] - fConst20 * (fConst18 * fRec130[2] + fConst16 * fRec130[1]);
			float fTemp54 = fRec130[2] + fRec130[0] + 2.0f * fRec130[1];
			fVec16[0] = fTemp54;
			fRec129[0] = -(fConst35 * (fConst33 * fRec129[1] - fConst20 * (fTemp54 + fVec16[1])));
			fRec128[0] = fRec129[0] - fConst13 * (fConst11 * fRec128[2] + fConst9 * fRec128[1]);
			float fTemp55 = fRec128[2] + fRec128[0] + 2.0f * fRec128[1];
			fVec17[0] = fTemp55;
			fRec127[0] = -(fConst38 * (fConst36 * fRec127[1] - fConst13 * (fTemp55 + fVec17[1])));
			fRec126[0] = fRec127[0] - fConst6 * (fConst5 * fRec126[2] + fConst3 * fRec126[1]);
			fRec135[0] = -(fConst38 * (fConst36 * fRec135[1] - fConst41 * (fTemp55 - fVec17[1])));
			fRec134[0] = fRec135[0] - fConst6 * (fConst5 * fRec134[2] + fConst3 * fRec134[1]);
			float fTemp56 = fConst3 * fRec136[1];
			fRec138[0] = -(fConst35 * (fConst33 * fRec138[1] - fConst44 * (fTemp54 - fVec16[1])));
			fRec137[0] = fRec138[0] - fConst13 * (fConst11 * fRec137[2] + fConst9 * fRec137[1]);
			fRec136[0] = fConst45 * (fRec137[2] + (fRec137[0] - 2.0f * fRec137[1])) - fConst43 * (fConst42 * fRec136[2] + fTemp56);
			float fTemp57 = fConst3 * fRec139[1];
			float fTemp58 = fConst9 * fRec140[1];
			fRec142[0] = -(fConst32 * (fConst30 * fRec142[1] - fConst48 * (fTemp53 - fVec15[1])));
			fRec141[0] = fRec142[0] - fConst20 * (fConst18 * fRec141[2] + fConst16 * fRec141[1]);
			fRec140[0] = fConst49 * (fRec141[2] + (fRec141[0] - 2.0f * fRec141[1])) - fConst47 * (fConst46 * fRec140[2] + fTemp58);
			fRec139[0] = fRec140[2] + fConst47 * (fTemp58 + fConst46 * fRec140[0]) - fConst43 * (fConst42 * fRec139[2] + fTemp57);
			float fTemp59 = fConst3 * fRec143[1];
			float fTemp60 = fConst9 * fRec144[1];
			float fTemp61 = fConst16 * fRec145[1];
			fRec147[0] = -(fConst29 * (fConst28 * fRec147[1] - fConst24 * (fRec5[1] - fRec5[2])));
			fRec146[0] = fRec147[0] - fConst27 * (fConst25 * fRec146[2] + fConst23 * fRec146[1]);
			fRec145[0] = fConst52 * (fRec146[2] + (fRec146[0] - 2.0f * fRec146[1])) - fConst51 * (fConst50 * fRec145[2] + fTemp61);
			fRec144[0] = fRec145[2] + fConst51 * (fTemp61 + fConst50 * fRec145[0]) - fConst47 * (fConst46 * fRec144[2] + fTemp60);
			fRec143[0] = fRec144[2] + fConst47 * (fTemp60 + fConst46 * fRec144[0]) - fConst43 * (fConst42 * fRec143[2] + fTemp59);
			float fTemp62 = fSlow44 * (fRec143[2] + fConst43 * (fTemp59 + fConst42 * fRec143[0])) + fSlow43 * (fRec139[2] + fConst43 * (fTemp57 + fConst42 * fRec139[0])) + fSlow42 * (fRec136[2] + fConst43 * (fTemp56 + fConst42 * fRec136[0])) + fConst6 * (fSlow41 * (fRec134[2] + (fRec134[0] - 2.0f * fRec134[1])) + fSlow40 * (fRec126[2] + fRec126[0] + 2.0f * fRec126[1]));
			float fTemp63 = fTemp62 + fTemp52;
			fRec155[0] = -(fConst29 * (fConst28 * fRec155[1] - (fRec9[1] + fRec9[2])));
			fRec154[0] = fRec155[0] - fConst27 * (fConst25 * fRec154[2] + fConst23 * fRec154[1]);
			float fTemp64 = fRec154[2] + fRec154[0] + 2.0f * fRec154[1];
			fVec18[0] = fTemp64;
			fRec153[0] = -(fConst32 * (fConst30 * fRec153[1] - fConst27 * (fTemp64 + fVec18[1])));
			fRec152[0] = fRec153[0] - fConst20 * (fConst18 * fRec152[2] + fConst16 * fRec152[1]);
			float fTemp65 = fRec152[2] + fRec152[0] + 2.0f * fRec152[1];
			fVec19[0] = fTemp65;
			fRec151[0] = -(fConst35 * (fConst33 * fRec151[1] - fConst20 * (fTemp65 + fVec19[1])));
			fRec150[0] = fRec151[0] - fConst13 * (fConst11 * fRec150[2] + fConst9 * fRec150[1]);
			float fTemp66 = fRec150[2] + fRec150[0] + 2.0f * fRec150[1];
			fVec20[0] = fTemp66;
			fRec149[0] = -(fConst38 * (fConst36 * fRec149[1] - fConst13 * (fTemp66 + fVec20[1])));
			fRec148[0] = fRec149[0] - fConst6 * (fConst5 * fRec148[2] + fConst3 * fRec148[1]);
			fRec157[0] = -(fConst38 * (fConst36 * fRec157[1] - fConst41 * (fTemp66 - fVec20[1])));
			fRec156[0] = fRec157[0] - fConst6 * (fConst5 * fRec156[2] + fConst3 * fRec156[1]);
			float fTemp67 = fConst3 * fRec158[1];
			fRec160[0] = -(fConst35 * (fConst33 * fRec160[1] - fConst44 * (fTemp65 - fVec19[1])));
			fRec159[0] = fRec160[0] - fConst13 * (fConst11 * fRec159[2] + fConst9 * fRec159[1]);
			fRec158[0] = fConst45 * (fRec159[2] + (fRec159[0] - 2.0f * fRec159[1])) - fConst43 * (fConst42 * fRec158[2] + fTemp67);
			float fTemp68 = fConst3 * fRec161[1];
			float fTemp69 = fConst9 * fRec162[1];
			fRec164[0] = -(fConst32 * (fConst30 * fRec164[1] - fConst48 * (fTemp64 - fVec18[1])));
			fRec163[0] = fRec164[0] - fConst20 * (fConst18 * fRec163[2] + fConst16 * fRec163[1]);
			fRec162[0] = fConst49 * (fRec163[2] + (fRec163[0] - 2.0f * fRec163[1])) - fConst47 * (fConst46 * fRec162[2] + fTemp69);
			fRec161[0] = fRec162[2] + fConst47 * (fTemp69 + fConst46 * fRec162[0]) - fConst43 * (fConst42 * fRec161[2] + fTemp68);
			float fTemp70 = fConst3 * fRec165[1];
			float fTemp71 = fConst9 * fRec166[1];
			float fTemp72 = fConst16 * fRec167[1];
			fRec169[0] = -(fConst29 * (fConst28 * fRec169[1] - fConst24 * (fRec9[1] - fRec9[2])));
			fRec168[0] = fRec169[0] - fConst27 * (fConst25 * fRec168[2] + fConst23 * fRec168[1]);
			fRec167[0] = fConst52 * (fRec168[2] + (fRec168[0] - 2.0f * fRec168[1])) - fConst51 * (fConst50 * fRec167[2] + fTemp72);
			fRec166[0] = fRec167[2] + fConst51 * (fTemp72 + fConst50 * fRec167[0]) - fConst47 * (fConst46 * fRec166[2] + fTemp71);
			fRec165[0] = fRec166[2] + fConst47 * (fTemp71 + fConst46 * fRec166[0]) - fConst43 * (fConst42 * fRec165[2] + fTemp70);
			float fTemp73 = fSlow50 * (fRec165[2] + fConst43 * (fTemp70 + fConst42 * fRec165[0])) + fSlow49 * (fRec161[2] + fConst43 * (fTemp68 + fConst42 * fRec161[0])) + fSlow48 * (fRec158[2] + fConst43 * (fTemp67 + fConst42 * fRec158[0])) + fConst6 * (fSlow47 * (fRec156[2] + (fRec156[0] - 2.0f * fRec156[1])) + fSlow46 * (fRec148[2] + fRec148[0] + 2.0f * fRec148[1]));
			fRec177[0] = -(fConst29 * (fConst28 * fRec177[1] - (fRec1[1] + fRec1[2])));
			fRec176[0] = fRec177[0] - fConst27 * (fConst25 * fRec176[2] + fConst23 * fRec176[1]);
			float fTemp74 = fRec176[2] + fRec176[0] + 2.0f * fRec176[1];
			fVec21[0] = fTemp74;
			fRec175[0] = -(fConst32 * (fConst30 * fRec175[1] - fConst27 * (fTemp74 + fVec21[1])));
			fRec174[0] = fRec175[0] - fConst20 * (fConst18 * fRec174[2] + fConst16 * fRec174[1]);
			float fTemp75 = fRec174[2] + fRec174[0] + 2.0f * fRec174[1];
			fVec22[0] = fTemp75;
			fRec173[0] = -(fConst35 * (fConst33 * fRec173[1] - fConst20 * (fTemp75 + fVec22[1])));
			fRec172[0] = fRec173[0] - fConst13 * (fConst11 * fRec172[2] + fConst9 * fRec172[1]);
			float fTemp76 = fRec172[2] + fRec172[0] + 2.0f * fRec172[1];
			fVec23[0] = fTemp76;
			fRec171[0] = -(fConst38 * (fConst36 * fRec171[1] - fConst13 * (fTemp76 + fVec23[1])));
			fRec170[0] = fRec171[0] - fConst6 * (fConst5 * fRec170[2] + fConst3 * fRec170[1]);
			fRec179[0] = -(fConst38 * (fConst36 * fRec179[1] - fConst41 * (fTemp76 - fVec23[1])));
			fRec178[0] = fRec179[0] - fConst6 * (fConst5 * fRec178[2] + fConst3 * fRec178[1]);
			float fTemp77 = fConst3 * fRec180[1];
			fRec182[0] = -(fConst35 * (fConst33 * fRec182[1] - fConst44 * (fTemp75 - fVec22[1])));
			fRec181[0] = fRec182[0] - fConst13 * (fConst11 * fRec181[2] + fConst9 * fRec181[1]);
			fRec180[0] = fConst45 * (fRec181[2] + (fRec181[0] - 2.0f * fRec181[1])) - fConst43 * (fConst42 * fRec180[2] + fTemp77);
			float fTemp78 = fConst3 * fRec183[1];
			float fTemp79 = fConst9 * fRec184[1];
			fRec186[0] = -(fConst32 * (fConst30 * fRec186[1] - fConst48 * (fTemp74 - fVec21[1])));
			fRec185[0] = fRec186[0] - fConst20 * (fConst18 * fRec185[2] + fConst16 * fRec185[1]);
			fRec184[0] = fConst49 * (fRec185[2] + (fRec185[0] - 2.0f * fRec185[1])) - fConst47 * (fConst46 * fRec184[2] + fTemp79);
			fRec183[0] = fRec184[2] + fConst47 * (fTemp79 + fConst46 * fRec184[0]) - fConst43 * (fConst42 * fRec183[2] + fTemp78);
			float fTemp80 = fConst3 * fRec187[1];
			float fTemp81 = fConst9 * fRec188[1];
			float fTemp82 = fConst16 * fRec189[1];
			fRec191[0] = -(fConst29 * (fConst28 * fRec191[1] - fConst24 * (fRec1[1] - fRec1[2])));
			fRec190[0] = fRec191[0] - fConst27 * (fConst25 * fRec190[2] + fConst23 * fRec190[1]);
			fRec189[0] = fConst52 * (fRec190[2] + (fRec190[0] - 2.0f * fRec190[1])) - fConst51 * (fConst50 * fRec189[2] + fTemp82);
			fRec188[0] = fRec189[2] + fConst51 * (fTemp82 + fConst50 * fRec189[0]) - fConst47 * (fConst46 * fRec188[2] + fTemp81);
			fRec187[0] = fRec188[2] + fConst47 * (fTemp81 + fConst46 * fRec188[0]) - fConst43 * (fConst42 * fRec187[2] + fTemp80);
			float fTemp83 = fSlow56 * (fRec187[2] + fConst43 * (fTemp80 + fConst42 * fRec187[0])) + fSlow55 * (fRec183[2] + fConst43 * (fTemp78 + fConst42 * fRec183[0])) + fSlow54 * (fRec180[2] + fConst43 * (fTemp77 + fConst42 * fRec180[0])) + fConst6 * (fSlow53 * (fRec178[2] + (fRec178[0] - 2.0f * fRec178[1])) + fSlow52 * (fRec170[2] + fRec170[0] + 2.0f * fRec170[1]));
			float fTemp84 = fTemp83 + fTemp73;
			float fTemp85 = fTemp84 + fTemp63;
			float fTemp86 = fTemp85 + fTemp42;
			fRec199[0] = -(fConst29 * (fConst28 * fRec199[1] - (fRec14[1] + fRec14[2])));
			fRec198[0] = fRec199[0] - fConst27 * (fConst25 * fRec198[2] + fConst23 * fRec198[1]);
			float fTemp87 = fRec198[2] + fRec198[0] + 2.0f * fRec198[1];
			fVec24[0] = fTemp87;
			fRec197[0] = -(fConst32 * (fConst30 * fRec197[1] - fConst27 * (fTemp87 + fVec24[1])));
			fRec196[0] = fRec197[0] - fConst20 * (fConst18 * fRec196[2] + fConst16 * fRec196[1]);
			float fTemp88 = fRec196[2] + fRec196[0] + 2.0f * fRec196[1];
			fVec25[0] = fTemp88;
			fRec195[0] = -(fConst35 * (fConst33 * fRec195[1] - fConst20 * (fTemp88 + fVec25[1])));
			fRec194[0] = fRec195[0] - fConst13 * (fConst11 * fRec194[2] + fConst9 * fRec194[1]);
			float fTemp89 = fRec194[2] + fRec194[0] + 2.0f * fRec194[1];
			fVec26[0] = fTemp89;
			fRec193[0] = -(fConst38 * (fConst36 * fRec193[1] - fConst13 * (fTemp89 + fVec26[1])));
			fRec192[0] = fRec193[0] - fConst6 * (fConst5 * fRec192[2] + fConst3 * fRec192[1]);
			fRec201[0] = -(fConst38 * (fConst36 * fRec201[1] - fConst41 * (fTemp89 - fVec26[1])));
			fRec200[0] = fRec201[0] - fConst6 * (fConst5 * fRec200[2] + fConst3 * fRec200[1]);
			float fTemp90 = fConst3 * fRec202[1];
			fRec204[0] = -(fConst35 * (fConst33 * fRec204[1] - fConst44 * (fTemp88 - fVec25[1])));
			fRec203[0] = fRec204[0] - fConst13 * (fConst11 * fRec203[2] + fConst9 * fRec203[1]);
			fRec202[0] = fConst45 * (fRec203[2] + (fRec203[0] - 2.0f * fRec203[1])) - fConst43 * (fConst42 * fRec202[2] + fTemp90);
			float fTemp91 = fConst3 * fRec205[1];
			float fTemp92 = fConst9 * fRec206[1];
			fRec208[0] = -(fConst32 * (fConst30 * fRec208[1] - fConst48 * (fTemp87 - fVec24[1])));
			fRec207[0] = fRec208[0] - fConst20 * (fConst18 * fRec207[2] + fConst16 * fRec207[1]);
			fRec206[0] = fConst49 * (fRec207[2] + (fRec207[0] - 2.0f * fRec207[1])) - fConst47 * (fConst46 * fRec206[2] + fTemp92);
			fRec205[0] = fRec206[2] + fConst47 * (fTemp92 + fConst46 * fRec206[0]) - fConst43 * (fConst42 * fRec205[2] + fTemp91);
			float fTemp93 = fConst3 * fRec209[1];
			float fTemp94 = fConst9 * fRec210[1];
			float fTemp95 = fConst16 * fRec211[1];
			fRec213[0] = -(fConst29 * (fConst28 * fRec213[1] - fConst24 * (fRec14[1] - fRec14[2])));
			fRec212[0] = fRec213[0] - fConst27 * (fConst25 * fRec212[2] + fConst23 * fRec212[1]);
			fRec211[0] = fConst52 * (fRec212[2] + (fRec212[0] - 2.0f * fRec212[1])) - fConst51 * (fConst50 * fRec211[2] + fTemp95);
			fRec210[0] = fRec211[2] + fConst51 * (fTemp95 + fConst50 * fRec211[0]) - fConst47 * (fConst46 * fRec210[2] + fTemp94);
			fRec209[0] = fRec210[2] + fConst47 * (fTemp94 + fConst46 * fRec210[0]) - fConst43 * (fConst42 * fRec209[2] + fTemp93);
			float fTemp96 = fSlow62 * (fRec209[2] + fConst43 * (fTemp93 + fConst42 * fRec209[0])) + fSlow61 * (fRec205[2] + fConst43 * (fTemp91 + fConst42 * fRec205[0])) + fSlow60 * (fRec202[2] + fConst43 * (fTemp90 + fConst42 * fRec202[0])) + fConst6 * (fSlow59 * (fRec200[2] + (fRec200[0] - 2.0f * fRec200[1])) + fSlow58 * (fRec192[2] + fRec192[0] + 2.0f * fRec192[1]));
			fRec221[0] = -(fConst29 * (fConst28 * fRec221[1] - (fRec6[1] + fRec6[2])));
			fRec220[0] = fRec221[0] - fConst27 * (fConst25 * fRec220[2] + fConst23 * fRec220[1]);
			float fTemp97 = fRec220[2] + fRec220[0] + 2.0f * fRec220[1];
			fVec27[0] = fTemp97;
			fRec219[0] = -(fConst32 * (fConst30 * fRec219[1] - fConst27 * (fTemp97 + fVec27[1])));
			fRec218[0] = fRec219[0] - fConst20 * (fConst18 * fRec218[2] + fConst16 * fRec218[1]);
			float fTemp98 = fRec218[2] + fRec218[0] + 2.0f * fRec218[1];
			fVec28[0] = fTemp98;
			fRec217[0] = -(fConst35 * (fConst33 * fRec217[1] - fConst20 * (fTemp98 + fVec28[1])));
			fRec216[0] = fRec217[0] - fConst13 * (fConst11 * fRec216[2] + fConst9 * fRec216[1]);
			float fTemp99 = fRec216[2] + fRec216[0] + 2.0f * fRec216[1];
			fVec29[0] = fTemp99;
			fRec215[0] = -(fConst38 * (fConst36 * fRec215[1] - fConst13 * (fTemp99 + fVec29[1])));
			fRec214[0] = fRec215[0] - fConst6 * (fConst5 * fRec214[2] + fConst3 * fRec214[1]);
			fRec223[0] = -(fConst38 * (fConst36 * fRec223[1] - fConst41 * (fTemp99 - fVec29[1])));
			fRec222[0] = fRec223[0] - fConst6 * (fConst5 * fRec222[2] + fConst3 * fRec222[1]);
			float fTemp100 = fConst3 * fRec224[1];
			fRec226[0] = -(fConst35 * (fConst33 * fRec226[1] - fConst44 * (fTemp98 - fVec28[1])));
			fRec225[0] = fRec226[0] - fConst13 * (fConst11 * fRec225[2] + fConst9 * fRec225[1]);
			fRec224[0] = fConst45 * (fRec225[2] + (fRec225[0] - 2.0f * fRec225[1])) - fConst43 * (fConst42 * fRec224[2] + fTemp100);
			float fTemp101 = fConst3 * fRec227[1];
			float fTemp102 = fConst9 * fRec228[1];
			fRec230[0] = -(fConst32 * (fConst30 * fRec230[1] - fConst48 * (fTemp97 - fVec27[1])));
			fRec229[0] = fRec230[0] - fConst20 * (fConst18 * fRec229[2] + fConst16 * fRec229[1]);
			fRec228[0] = fConst49 * (fRec229[2] + (fRec229[0] - 2.0f * fRec229[1])) - fConst47 * (fConst46 * fRec228[2] + fTemp102);
			fRec227[0] = fRec228[2] + fConst47 * (fTemp102 + fConst46 * fRec228[0]) - fConst43 * (fConst42 * fRec227[2] + fTemp101);
			float fTemp103 = fConst3 * fRec231[1];
			float fTemp104 = fConst9 * fRec232[1];
			float fTemp105 = fConst16 * fRec233[1];
			fRec235[0] = -(fConst29 * (fConst28 * fRec235[1] - fConst24 * (fRec6[1] - fRec6[2])));
			fRec234[0] = fRec235[0] - fConst27 * (fConst25 * fRec234[2] + fConst23 * fRec234[1]);
			fRec233[0] = fConst52 * (fRec234[2] + (fRec234[0] - 2.0f * fRec234[1])) - fConst51 * (fConst50 * fRec233[2] + fTemp105);
			fRec232[0] = fRec233[2] + fConst51 * (fTemp105 + fConst50 * fRec233[0]) - fConst47 * (fConst46 * fRec232[2] + fTemp104);
			fRec231[0] = fRec232[2] + fConst47 * (fTemp104 + fConst46 * fRec232[0]) - fConst43 * (fConst42 * fRec231[2] + fTemp103);
			float fTemp106 = fSlow68 * (fRec231[2] + fConst43 * (fTemp103 + fConst42 * fRec231[0])) + fSlow67 * (fRec227[2] + fConst43 * (fTemp101 + fConst42 * fRec227[0])) + fSlow66 * (fRec224[2] + fConst43 * (fTemp100 + fConst42 * fRec224[0])) + fConst6 * (fSlow65 * (fRec222[2] + (fRec222[0] - 2.0f * fRec222[1])) + fSlow64 * (fRec214[2] + fRec214[0] + 2.0f * fRec214[1]));
			float fTemp107 = fTemp106 + fTemp96;
			fRec243[0] = -(fConst29 * (fConst28 * fRec243[1] - (fRec10[1] + fRec10[2])));
			fRec242[0] = fRec243[0] - fConst27 * (fConst25 * fRec242[2] + fConst23 * fRec242[1]);
			float fTemp108 = fRec242[2] + fRec242[0] + 2.0f * fRec242[1];
			fVec30[0] = fTemp108;
			fRec241[0] = -(fConst32 * (fConst30 * fRec241[1] - fConst27 * (fTemp108 + fVec30[1])));
			fRec240[0] = fRec241[0] - fConst20 * (fConst18 * fRec240[2] + fConst16 * fRec240[1]);
			float fTemp109 = fRec240[2] + fRec240[0] + 2.0f * fRec240[1];
			fVec31[0] = fTemp109;
			fRec239[0] = -(fConst35 * (fConst33 * fRec239[1] - fConst20 * (fTemp109 + fVec31[1])));
			fRec238[0] = fRec239[0] - fConst13 * (fConst11 * fRec238[2] + fConst9 * fRec238[1]);
			float fTemp110 = fRec238[2] + fRec238[0] + 2.0f * fRec238[1];
			fVec32[0] = fTemp110;
			fRec237[0] = -(fConst38 * (fConst36 * fRec237[1] - fConst13 * (fTemp110 + fVec32[1])));
			fRec236[0] = fRec237[0] - fConst6 * (fConst5 * fRec236[2] + fConst3 * fRec236[1]);
			fRec245[0] = -(fConst38 * (fConst36 * fRec245[1] - fConst41 * (fTemp110 - fVec32[1])));
			fRec244[0] = fRec245[0] - fConst6 * (fConst5 * fRec244[2] + fConst3 * fRec244[1]);
			float fTemp111 = fConst3 * fRec246[1];
			fRec248[0] = -(fConst35 * (fConst33 * fRec248[1] - fConst44 * (fTemp109 - fVec31[1])));
			fRec247[0] = fRec248[0] - fConst13 * (fConst11 * fRec247[2] + fConst9 * fRec247[1]);
			fRec246[0] = fConst45 * (fRec247[2] + (fRec247[0] - 2.0f * fRec247[1])) - fConst43 * (fConst42 * fRec246[2] + fTemp111);
			float fTemp112 = fConst3 * fRec249[1];
			float fTemp113 = fConst9 * fRec250[1];
			fRec252[0] = -(fConst32 * (fConst30 * fRec252[1] - fConst48 * (fTemp108 - fVec30[1])));
			fRec251[0] = fRec252[0] - fConst20 * (fConst18 * fRec251[2] + fConst16 * fRec251[1]);
			fRec250[0] = fConst49 * (fRec251[2] + (fRec251[0] - 2.0f * fRec251[1])) - fConst47 * (fConst46 * fRec250[2] + fTemp113);
			fRec249[0] = fRec250[2] + fConst47 * (fTemp113 + fConst46 * fRec250[0]) - fConst43 * (fConst42 * fRec249[2] + fTemp112);
			float fTemp114 = fConst3 * fRec253[1];
			float fTemp115 = fConst9 * fRec254[1];
			float fTemp116 = fConst16 * fRec255[1];
			fRec257[0] = -(fConst29 * (fConst28 * fRec257[1] - fConst24 * (fRec10[1] - fRec10[2])));
			fRec256[0] = fRec257[0] - fConst27 * (fConst25 * fRec256[2] + fConst23 * fRec256[1]);
			fRec255[0] = fConst52 * (fRec256[2] + (fRec256[0] - 2.0f * fRec256[1])) - fConst51 * (fConst50 * fRec255[2] + fTemp116);
			fRec254[0] = fRec255[2] + fConst51 * (fTemp116 + fConst50 * fRec255[0]) - fConst47 * (fConst46 * fRec254[2] + fTemp115);
			fRec253[0] = fRec254[2] + fConst47 * (fTemp115 + fConst46 * fRec254[0]) - fConst43 * (fConst42 * fRec253[2] + fTemp114);
			float fTemp117 = fSlow74 * (fRec253[2] + fConst43 * (fTemp114 + fConst42 * fRec253[0])) + fSlow73 * (fRec249[2] + fConst43 * (fTemp112 + fConst42 * fRec249[0])) + fSlow72 * (fRec246[2] + fConst43 * (fTemp111 + fConst42 * fRec246[0])) + fConst6 * (fSlow71 * (fRec244[2] + (fRec244[0] - 2.0f * fRec244[1])) + fSlow70 * (fRec236[2] + fRec236[0] + 2.0f * fRec236[1]));
			fRec265[0] = -(fConst29 * (fConst28 * fRec265[1] - (fRec2[1] + fRec2[2])));
			fRec264[0] = fRec265[0] - fConst27 * (fConst25 * fRec264[2] + fConst23 * fRec264[1]);
			float fTemp118 = fRec264[2] + fRec264[0] + 2.0f * fRec264[1];
			fVec33[0] = fTemp118;
			fRec263[0] = -(fConst32 * (fConst30 * fRec263[1] - fConst27 * (fTemp118 + fVec33[1])));
			fRec262[0] = fRec263[0] - fConst20 * (fConst18 * fRec262[2] + fConst16 * fRec262[1]);
			float fTemp119 = fRec262[2] + fRec262[0] + 2.0f * fRec262[1];
			fVec34[0] = fTemp119;
			fRec261[0] = -(fConst35 * (fConst33 * fRec261[1] - fConst20 * (fTemp119 + fVec34[1])));
			fRec260[0] = fRec261[0] - fConst13 * (fConst11 * fRec260[2] + fConst9 * fRec260[1]);
			float fTemp120 = fRec260[2] + fRec260[0] + 2.0f * fRec260[1];
			fVec35[0] = fTemp120;
			fRec259[0] = -(fConst38 * (fConst36 * fRec259[1] - fConst13 * (fTemp120 + fVec35[1])));
			fRec258[0] = fRec259[0] - fConst6 * (fConst5 * fRec258[2] + fConst3 * fRec258[1]);
			fRec267[0] = -(fConst38 * (fConst36 * fRec267[1] - fConst41 * (fTemp120 - fVec35[1])));
			fRec266[0] = fRec267[0] - fConst6 * (fConst5 * fRec266[2] + fConst3 * fRec266[1]);
			float fTemp121 = fConst3 * fRec268[1];
			fRec270[0] = -(fConst35 * (fConst33 * fRec270[1] - fConst44 * (fTemp119 - fVec34[1])));
			fRec269[0] = fRec270[0] - fConst13 * (fConst11 * fRec269[2] + fConst9 * fRec269[1]);
			fRec268[0] = fConst45 * (fRec269[2] + (fRec269[0] - 2.0f * fRec269[1])) - fConst43 * (fConst42 * fRec268[2] + fTemp121);
			float fTemp122 = fConst3 * fRec271[1];
			float fTemp123 = fConst9 * fRec272[1];
			fRec274[0] = -(fConst32 * (fConst30 * fRec274[1] - fConst48 * (fTemp118 - fVec33[1])));
			fRec273[0] = fRec274[0] - fConst20 * (fConst18 * fRec273[2] + fConst16 * fRec273[1]);
			fRec272[0] = fConst49 * (fRec273[2] + (fRec273[0] - 2.0f * fRec273[1])) - fConst47 * (fConst46 * fRec272[2] + fTemp123);
			fRec271[0] = fRec272[2] + fConst47 * (fTemp123 + fConst46 * fRec272[0]) - fConst43 * (fConst42 * fRec271[2] + fTemp122);
			float fTemp124 = fConst3 * fRec275[1];
			float fTemp125 = fConst9 * fRec276[1];
			float fTemp126 = fConst16 * fRec277[1];
			fRec279[0] = -(fConst29 * (fConst28 * fRec279[1] - fConst24 * (fRec2[1] - fRec2[2])));
			fRec278[0] = fRec279[0] - fConst27 * (fConst25 * fRec278[2] + fConst23 * fRec278[1]);
			fRec277[0] = fConst52 * (fRec278[2] + (fRec278[0] - 2.0f * fRec278[1])) - fConst51 * (fConst50 * fRec277[2] + fTemp126);
			fRec276[0] = fRec277[2] + fConst51 * (fTemp126 + fConst50 * fRec277[0]) - fConst47 * (fConst46 * fRec276[2] + fTemp125);
			fRec275[0] = fRec276[2] + fConst47 * (fTemp125 + fConst46 * fRec276[0]) - fConst43 * (fConst42 * fRec275[2] + fTemp124);
			float fTemp127 = fSlow80 * (fRec275[2] + fConst43 * (fTemp124 + fConst42 * fRec275[0])) + fSlow79 * (fRec271[2] + fConst43 * (fTemp122 + fConst42 * fRec271[0])) + fSlow78 * (fRec268[2] + fConst43 * (fTemp121 + fConst42 * fRec268[0])) + fConst6 * (fSlow77 * (fRec266[2] + (fRec266[0] - 2.0f * fRec266[1])) + fSlow76 * (fRec258[2] + fRec258[0] + 2.0f * fRec258[1]));
			float fTemp128 = fTemp127 + fTemp117;
			float fTemp129 = fTemp128 + fTemp107;
			fRec287[0] = -(fConst29 * (fConst28 * fRec287[1] - (fRec12[1] + fRec12[2])));
			fRec286[0] = fRec287[0] - fConst27 * (fConst25 * fRec286[2] + fConst23 * fRec286[1]);
			float fTemp130 = fRec286[2] + fRec286[0] + 2.0f * fRec286[1];
			fVec36[0] = fTemp130;
			fRec285[0] = -(fConst32 * (fConst30 * fRec285[1] - fConst27 * (fTemp130 + fVec36[1])));
			fRec284[0] = fRec285[0] - fConst20 * (fConst18 * fRec284[2] + fConst16 * fRec284[1]);
			float fTemp131 = fRec284[2] + fRec284[0] + 2.0f * fRec284[1];
			fVec37[0] = fTemp131;
			fRec283[0] = -(fConst35 * (fConst33 * fRec283[1] - fConst20 * (fTemp131 + fVec37[1])));
			fRec282[0] = fRec283[0] - fConst13 * (fConst11 * fRec282[2] + fConst9 * fRec282[1]);
			float fTemp132 = fRec282[2] + fRec282[0] + 2.0f * fRec282[1];
			fVec38[0] = fTemp132;
			fRec281[0] = -(fConst38 * (fConst36 * fRec281[1] - fConst13 * (fTemp132 + fVec38[1])));
			fRec280[0] = fRec281[0] - fConst6 * (fConst5 * fRec280[2] + fConst3 * fRec280[1]);
			fRec289[0] = -(fConst38 * (fConst36 * fRec289[1] - fConst41 * (fTemp132 - fVec38[1])));
			fRec288[0] = fRec289[0] - fConst6 * (fConst5 * fRec288[2] + fConst3 * fRec288[1]);
			float fTemp133 = fConst3 * fRec290[1];
			fRec292[0] = -(fConst35 * (fConst33 * fRec292[1] - fConst44 * (fTemp131 - fVec37[1])));
			fRec291[0] = fRec292[0] - fConst13 * (fConst11 * fRec291[2] + fConst9 * fRec291[1]);
			fRec290[0] = fConst45 * (fRec291[2] + (fRec291[0] - 2.0f * fRec291[1])) - fConst43 * (fConst42 * fRec290[2] + fTemp133);
			float fTemp134 = fConst3 * fRec293[1];
			float fTemp135 = fConst9 * fRec294[1];
			fRec296[0] = -(fConst32 * (fConst30 * fRec296[1] - fConst48 * (fTemp130 - fVec36[1])));
			fRec295[0] = fRec296[0] - fConst20 * (fConst18 * fRec295[2] + fConst16 * fRec295[1]);
			fRec294[0] = fConst49 * (fRec295[2] + (fRec295[0] - 2.0f * fRec295[1])) - fConst47 * (fConst46 * fRec294[2] + fTemp135);
			fRec293[0] = fRec294[2] + fConst47 * (fTemp135 + fConst46 * fRec294[0]) - fConst43 * (fConst42 * fRec293[2] + fTemp134);
			float fTemp136 = fConst3 * fRec297[1];
			float fTemp137 = fConst9 * fRec298[1];
			float fTemp138 = fConst16 * fRec299[1];
			fRec301[0] = -(fConst29 * (fConst28 * fRec301[1] - fConst24 * (fRec12[1] - fRec12[2])));
			fRec300[0] = fRec301[0] - fConst27 * (fConst25 * fRec300[2] + fConst23 * fRec300[1]);
			fRec299[0] = fConst52 * (fRec300[2] + (fRec300[0] - 2.0f * fRec300[1])) - fConst51 * (fConst50 * fRec299[2] + fTemp138);
			fRec298[0] = fRec299[2] + fConst51 * (fTemp138 + fConst50 * fRec299[0]) - fConst47 * (fConst46 * fRec298[2] + fTemp137);
			fRec297[0] = fRec298[2] + fConst47 * (fTemp137 + fConst46 * fRec298[0]) - fConst43 * (fConst42 * fRec297[2] + fTemp136);
			float fTemp139 = fSlow86 * (fRec297[2] + fConst43 * (fTemp136 + fConst42 * fRec297[0])) + fSlow85 * (fRec293[2] + fConst43 * (fTemp134 + fConst42 * fRec293[0])) + fSlow84 * (fRec290[2] + fConst43 * (fTemp133 + fConst42 * fRec290[0])) + fConst6 * (fSlow83 * (fRec288[2] + (fRec288[0] - 2.0f * fRec288[1])) + fSlow82 * (fRec280[2] + fRec280[0] + 2.0f * fRec280[1]));
			fRec309[0] = -(fConst29 * (fConst28 * fRec309[1] - (fRec4[1] + fRec4[2])));
			fRec308[0] = fRec309[0] - fConst27 * (fConst25 * fRec308[2] + fConst23 * fRec308[1]);
			float fTemp140 = fRec308[2] + fRec308[0] + 2.0f * fRec308[1];
			fVec39[0] = fTemp140;
			fRec307[0] = -(fConst32 * (fConst30 * fRec307[1] - fConst27 * (fTemp140 + fVec39[1])));
			fRec306[0] = fRec307[0] - fConst20 * (fConst18 * fRec306[2] + fConst16 * fRec306[1]);
			float fTemp141 = fRec306[2] + fRec306[0] + 2.0f * fRec306[1];
			fVec40[0] = fTemp141;
			fRec305[0] = -(fConst35 * (fConst33 * fRec305[1] - fConst20 * (fTemp141 + fVec40[1])));
			fRec304[0] = fRec305[0] - fConst13 * (fConst11 * fRec304[2] + fConst9 * fRec304[1]);
			float fTemp142 = fRec304[2] + fRec304[0] + 2.0f * fRec304[1];
			fVec41[0] = fTemp142;
			fRec303[0] = -(fConst38 * (fConst36 * fRec303[1] - fConst13 * (fTemp142 + fVec41[1])));
			fRec302[0] = fRec303[0] - fConst6 * (fConst5 * fRec302[2] + fConst3 * fRec302[1]);
			fRec311[0] = -(fConst38 * (fConst36 * fRec311[1] - fConst41 * (fTemp142 - fVec41[1])));
			fRec310[0] = fRec311[0] - fConst6 * (fConst5 * fRec310[2] + fConst3 * fRec310[1]);
			float fTemp143 = fConst3 * fRec312[1];
			fRec314[0] = -(fConst35 * (fConst33 * fRec314[1] - fConst44 * (fTemp141 - fVec40[1])));
			fRec313[0] = fRec314[0] - fConst13 * (fConst11 * fRec313[2] + fConst9 * fRec313[1]);
			fRec312[0] = fConst45 * (fRec313[2] + (fRec313[0] - 2.0f * fRec313[1])) - fConst43 * (fConst42 * fRec312[2] + fTemp143);
			float fTemp144 = fConst3 * fRec315[1];
			float fTemp145 = fConst9 * fRec316[1];
			fRec318[0] = -(fConst32 * (fConst30 * fRec318[1] - fConst48 * (fTemp140 - fVec39[1])));
			fRec317[0] = fRec318[0] - fConst20 * (fConst18 * fRec317[2] + fConst16 * fRec317[1]);
			fRec316[0] = fConst49 * (fRec317[2] + (fRec317[0] - 2.0f * fRec317[1])) - fConst47 * (fConst46 * fRec316[2] + fTemp145);
			fRec315[0] = fRec316[2] + fConst47 * (fTemp145 + fConst46 * fRec316[0]) - fConst43 * (fConst42 * fRec315[2] + fTemp144);
			float fTemp146 = fConst3 * fRec319[1];
			float fTemp147 = fConst9 * fRec320[1];
			float fTemp148 = fConst16 * fRec321[1];
			fRec323[0] = -(fConst29 * (fConst28 * fRec323[1] - fConst24 * (fRec4[1] - fRec4[2])));
			fRec322[0] = fRec323[0] - fConst27 * (fConst25 * fRec322[2] + fConst23 * fRec322[1]);
			fRec321[0] = fConst52 * (fRec322[2] + (fRec322[0] - 2.0f * fRec322[1])) - fConst51 * (fConst50 * fRec321[2] + fTemp148);
			fRec320[0] = fRec321[2] + fConst51 * (fTemp148 + fConst50 * fRec321[0]) - fConst47 * (fConst46 * fRec320[2] + fTemp147);
			fRec319[0] = fRec320[2] + fConst47 * (fTemp147 + fConst46 * fRec320[0]) - fConst43 * (fConst42 * fRec319[2] + fTemp146);
			float fTemp149 = fSlow92 * (fRec319[2] + fConst43 * (fTemp146 + fConst42 * fRec319[0])) + fSlow91 * (fRec315[2] + fConst43 * (fTemp144 + fConst42 * fRec315[0])) + fSlow90 * (fRec312[2] + fConst43 * (fTemp143 + fConst42 * fRec312[0])) + fConst6 * (fSlow89 * (fRec310[2] + (fRec310[0] - 2.0f * fRec310[1])) + fSlow88 * (fRec302[2] + fRec302[0] + 2.0f * fRec302[1]));
			float fTemp150 = fTemp149 + fTemp139;
			fRec331[0] = -(fConst29 * (fConst28 * fRec331[1] - (fRec8[1] + fRec8[2])));
			fRec330[0] = fRec331[0] - fConst27 * (fConst25 * fRec330[2] + fConst23 * fRec330[1]);
			float fTemp151 = fRec330[2] + fRec330[0] + 2.0f * fRec330[1];
			fVec42[0] = fTemp151;
			fRec329[0] = -(fConst32 * (fConst30 * fRec329[1] - fConst27 * (fTemp151 + fVec42[1])));
			fRec328[0] = fRec329[0] - fConst20 * (fConst18 * fRec328[2] + fConst16 * fRec328[1]);
			float fTemp152 = fRec328[2] + fRec328[0] + 2.0f * fRec328[1];
			fVec43[0] = fTemp152;
			fRec327[0] = -(fConst35 * (fConst33 * fRec327[1] - fConst20 * (fTemp152 + fVec43[1])));
			fRec326[0] = fRec327[0] - fConst13 * (fConst11 * fRec326[2] + fConst9 * fRec326[1]);
			float fTemp153 = fRec326[2] + fRec326[0] + 2.0f * fRec326[1];
			fVec44[0] = fTemp153;
			fRec325[0] = -(fConst38 * (fConst36 * fRec325[1] - fConst13 * (fTemp153 + fVec44[1])));
			fRec324[0] = fRec325[0] - fConst6 * (fConst5 * fRec324[2] + fConst3 * fRec324[1]);
			fRec333[0] = -(fConst38 * (fConst36 * fRec333[1] - fConst41 * (fTemp153 - fVec44[1])));
			fRec332[0] = fRec333[0] - fConst6 * (fConst5 * fRec332[2] + fConst3 * fRec332[1]);
			float fTemp154 = fConst3 * fRec334[1];
			fRec336[0] = -(fConst35 * (fConst33 * fRec336[1] - fConst44 * (fTemp152 - fVec43[1])));
			fRec335[0] = fRec336[0] - fConst13 * (fConst11 * fRec335[2] + fConst9 * fRec335[1]);
			fRec334[0] = fConst45 * (fRec335[2] + (fRec335[0] - 2.0f * fRec335[1])) - fConst43 * (fConst42 * fRec334[2] + fTemp154);
			float fTemp155 = fConst3 * fRec337[1];
			float fTemp156 = fConst9 * fRec338[1];
			fRec340[0] = -(fConst32 * (fConst30 * fRec340[1] - fConst48 * (fTemp151 - fVec42[1])));
			fRec339[0] = fRec340[0] - fConst20 * (fConst18 * fRec339[2] + fConst16 * fRec339[1]);
			fRec338[0] = fConst49 * (fRec339[2] + (fRec339[0] - 2.0f * fRec339[1])) - fConst47 * (fConst46 * fRec338[2] + fTemp156);
			fRec337[0] = fRec338[2] + fConst47 * (fTemp156 + fConst46 * fRec338[0]) - fConst43 * (fConst42 * fRec337[2] + fTemp155);
			float fTemp157 = fConst3 * fRec341[1];
			float fTemp158 = fConst9 * fRec342[1];
			float fTemp159 = fConst16 * fRec343[1];
			fRec345[0] = -(fConst29 * (fConst28 * fRec345[1] - fConst24 * (fRec8[1] - fRec8[2])));
			fRec344[0] = fRec345[0] - fConst27 * (fConst25 * fRec344[2] + fConst23 * fRec344[1]);
			fRec343[0] = fConst52 * (fRec344[2] + (fRec344[0] - 2.0f * fRec344[1])) - fConst51 * (fConst50 * fRec343[2] + fTemp159);
			fRec342[0] = fRec343[2] + fConst51 * (fTemp159 + fConst50 * fRec343[0]) - fConst47 * (fConst46 * fRec342[2] + fTemp158);
			fRec341[0] = fRec342[2] + fConst47 * (fTemp158 + fConst46 * fRec342[0]) - fConst43 * (fConst42 * fRec341[2] + fTemp157);
			float fTemp160 = fSlow98 * (fRec341[2] + fConst43 * (fTemp157 + fConst42 * fRec341[0])) + fSlow97 * (fRec337[2] + fConst43 * (fTemp155 + fConst42 * fRec337[0])) + fSlow96 * (fRec334[2] + fConst43 * (fTemp154 + fConst42 * fRec334[0])) + fConst6 * (fSlow95 * (fRec332[2] + (fRec332[0] - 2.0f * fRec332[1])) + fSlow94 * (fRec324[2] + fRec324[0] + 2.0f * fRec324[1]));
			fRec353[0] = -(fConst29 * (fConst28 * fRec353[1] - (fRec0[1] + fRec0[2])));
			fRec352[0] = fRec353[0] - fConst27 * (fConst25 * fRec352[2] + fConst23 * fRec352[1]);
			float fTemp161 = fRec352[2] + fRec352[0] + 2.0f * fRec352[1];
			fVec45[0] = fTemp161;
			fRec351[0] = -(fConst32 * (fConst30 * fRec351[1] - fConst27 * (fTemp161 + fVec45[1])));
			fRec350[0] = fRec351[0] - fConst20 * (fConst18 * fRec350[2] + fConst16 * fRec350[1]);
			float fTemp162 = fRec350[2] + fRec350[0] + 2.0f * fRec350[1];
			fVec46[0] = fTemp162;
			fRec349[0] = -(fConst35 * (fConst33 * fRec349[1] - fConst20 * (fTemp162 + fVec46[1])));
			fRec348[0] = fRec349[0] - fConst13 * (fConst11 * fRec348[2] + fConst9 * fRec348[1]);
			float fTemp163 = fRec348[2] + fRec348[0] + 2.0f * fRec348[1];
			fVec47[0] = fTemp163;
			fRec347[0] = -(fConst38 * (fConst36 * fRec347[1] - fConst13 * (fTemp163 + fVec47[1])));
			fRec346[0] = fRec347[0] - fConst6 * (fConst5 * fRec346[2] + fConst3 * fRec346[1]);
			fRec355[0] = -(fConst38 * (fConst36 * fRec355[1] - fConst41 * (fTemp163 - fVec47[1])));
			fRec354[0] = fRec355[0] - fConst6 * (fConst5 * fRec354[2] + fConst3 * fRec354[1]);
			float fTemp164 = fConst3 * fRec356[1];
			fRec358[0] = -(fConst35 * (fConst33 * fRec358[1] - fConst44 * (fTemp162 - fVec46[1])));
			fRec357[0] = fRec358[0] - fConst13 * (fConst11 * fRec357[2] + fConst9 * fRec357[1]);
			fRec356[0] = fConst45 * (fRec357[2] + (fRec357[0] - 2.0f * fRec357[1])) - fConst43 * (fConst42 * fRec356[2] + fTemp164);
			float fTemp165 = fConst3 * fRec359[1];
			float fTemp166 = fConst9 * fRec360[1];
			fRec362[0] = -(fConst32 * (fConst30 * fRec362[1] - fConst48 * (fTemp161 - fVec45[1])));
			fRec361[0] = fRec362[0] - fConst20 * (fConst18 * fRec361[2] + fConst16 * fRec361[1]);
			fRec360[0] = fConst49 * (fRec361[2] + (fRec361[0] - 2.0f * fRec361[1])) - fConst47 * (fConst46 * fRec360[2] + fTemp166);
			fRec359[0] = fRec360[2] + fConst47 * (fTemp166 + fConst46 * fRec360[0]) - fConst43 * (fConst42 * fRec359[2] + fTemp165);
			float fTemp167 = fConst3 * fRec363[1];
			float fTemp168 = fConst9 * fRec364[1];
			float fTemp169 = fConst16 * fRec365[1];
			fRec367[0] = -(fConst29 * (fConst28 * fRec367[1] - fConst24 * (fRec0[1] - fRec0[2])));
			fRec366[0] = fRec367[0] - fConst27 * (fConst25 * fRec366[2] + fConst23 * fRec366[1]);
			fRec365[0] = fConst52 * (fRec366[2] + (fRec366[0] - 2.0f * fRec366[1])) - fConst51 * (fConst50 * fRec365[2] + fTemp169);
			fRec364[0] = fRec365[2] + fConst51 * (fTemp169 + fConst50 * fRec365[0]) - fConst47 * (fConst46 * fRec364[2] + fTemp168);
			fRec363[0] = fRec364[2] + fConst47 * (fTemp168 + fConst46 * fRec364[0]) - fConst43 * (fConst42 * fRec363[2] + fTemp167);
			float fTemp170 = fSlow104 * (fRec363[2] + fConst43 * (fTemp167 + fConst42 * fRec363[0])) + fSlow103 * (fRec359[2] + fConst43 * (fTemp165 + fConst42 * fRec359[0])) + fSlow102 * (fRec356[2] + fConst43 * (fTemp164 + fConst42 * fRec356[0])) + fConst6 * (fSlow101 * (fRec354[2] + (fRec354[0] - 2.0f * fRec354[1])) + fSlow100 * (fRec346[2] + fRec346[0] + 2.0f * fRec346[1]));
			float fTemp171 = fTemp170 + fTemp160;
			float fTemp172 = fTemp171 + fTemp150;
			float fTemp173 = fTemp172 + fTemp129;
			float fTemp174 = static_cast<float>(input0[i0]);
			fVec48[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp173 + fTemp86);
			fRec0[0] = fVec48[(faust_wrap_sub(IOTA0, iSlow105)) & 16383];
			fVec49[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp173 - fTemp86);
			fRec1[0] = fVec49[(faust_wrap_sub(IOTA0, iSlow106)) & 16383];
			float fTemp175 = fTemp85 - fTemp42;
			float fTemp176 = fTemp172 - fTemp129;
			fVec50[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp176 + fTemp175);
			fRec2[0] = fVec50[(faust_wrap_sub(IOTA0, iSlow107)) & 16383];
			fVec51[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp176 - fTemp175);
			fRec3[0] = fVec51[(faust_wrap_sub(IOTA0, iSlow108)) & 16383];
			float fTemp177 = fTemp41 - fTemp20;
			float fTemp178 = fTemp84 - fTemp63;
			float fTemp179 = fTemp178 + fTemp177;
			float fTemp180 = fTemp128 - fTemp107;
			float fTemp181 = fTemp171 - fTemp150;
			float fTemp182 = fTemp181 + fTemp180;
			fVec52[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp182 + fTemp179);
			fRec4[0] = fVec52[(faust_wrap_sub(IOTA0, iSlow109)) & 16383];
			fVec53[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp182 - fTemp179);
			fRec5[0] = fVec53[(faust_wrap_sub(IOTA0, iSlow110)) & 16383];
			float fTemp183 = fTemp178 - fTemp177;
			float fTemp184 = fTemp181 - fTemp180;
			fVec54[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp184 + fTemp183);
			fRec6[0] = fVec54[(faust_wrap_sub(IOTA0, iSlow111)) & 16383];
			fVec55[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp184 - fTemp183);
			fRec7[0] = fVec55[(faust_wrap_sub(IOTA0, iSlow112)) & 16383];
			float fTemp185 = fTemp19 - fTemp9;
			float fTemp186 = fTemp40 - fTemp30;
			float fTemp187 = fTemp186 + fTemp185;
			float fTemp188 = fTemp62 - fTemp52;
			float fTemp189 = fTemp83 - fTemp73;
			float fTemp190 = fTemp189 + fTemp188;
			float fTemp191 = fTemp190 + fTemp187;
			float fTemp192 = fTemp106 - fTemp96;
			float fTemp193 = fTemp127 - fTemp117;
			float fTemp194 = fTemp193 + fTemp192;
			float fTemp195 = fTemp149 - fTemp139;
			float fTemp196 = fTemp170 - fTemp160;
			float fTemp197 = fTemp196 + fTemp195;
			float fTemp198 = fTemp197 + fTemp194;
			fVec56[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp198 + fTemp191);
			fRec8[0] = fVec56[(faust_wrap_sub(IOTA0, iSlow113)) & 16383];
			fVec57[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp198 - fTemp191);
			fRec9[0] = fVec57[(faust_wrap_sub(IOTA0, iSlow114)) & 16383];
			float fTemp199 = fTemp190 - fTemp187;
			float fTemp200 = fTemp197 - fTemp194;
			fVec58[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp200 + fTemp199);
			fRec10[0] = fVec58[(faust_wrap_sub(IOTA0, iSlow115)) & 16383];
			fVec59[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp200 - fTemp199);
			fRec11[0] = fVec59[(faust_wrap_sub(IOTA0, iSlow116)) & 16383];
			float fTemp201 = fTemp186 - fTemp185;
			float fTemp202 = fTemp189 - fTemp188;
			float fTemp203 = fTemp202 + fTemp201;
			float fTemp204 = fTemp193 - fTemp192;
			float fTemp205 = fTemp196 - fTemp195;
			float fTemp206 = fTemp205 + fTemp204;
			fVec60[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp206 + fTemp203);
			fRec12[0] = fVec60[(faust_wrap_sub(IOTA0, iSlow117)) & 16383];
			fVec61[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp206 - fTemp203);
			fRec13[0] = fVec61[(faust_wrap_sub(IOTA0, iSlow118)) & 16383];
			float fTemp207 = fTemp202 - fTemp201;
			float fTemp208 = fTemp205 - fTemp204;
			fVec62[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp208 + fTemp207);
			fRec14[0] = fVec62[(faust_wrap_sub(IOTA0, iSlow119)) & 16383];
			fVec63[IOTA0 & 16383] = fTemp174 + 0.25f * (fTemp208 - fTemp207);
			fRec15[0] = fVec63[(faust_wrap_sub(IOTA0, iSlow120)) & 16383];
			fRec368[0] = fSlow121 + fConst54 * fRec368[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp174 * (1.0f - fRec368[0]) + 0.03f * fRec368[0] * (fRec0[0] + fRec1[0] + fRec2[0] + fRec3[0] + fRec4[0] + fRec5[0] + fRec6[0] + fRec7[0] + fRec8[0] + fRec9[0] + fRec10[0] + fRec11[0] + fRec12[0] + fRec13[0] + fRec14[0] + fRec15[0]));
			fRec23[1] = fRec23[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fVec0[1] = fVec0[0];
			fRec21[1] = fRec21[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fVec1[1] = fVec1[0];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fVec2[1] = fVec2[0];
			fRec17[1] = fRec17[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec25[1] = fRec25[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec28[1] = fRec28[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec32[1] = fRec32[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec37[1] = fRec37[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec45[1] = fRec45[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fVec3[1] = fVec3[0];
			fRec43[1] = fRec43[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fVec4[1] = fVec4[0];
			fRec41[1] = fRec41[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fVec5[1] = fVec5[0];
			fRec39[1] = fRec39[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec47[1] = fRec47[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec50[1] = fRec50[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec54[1] = fRec54[0];
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
			fRec59[1] = fRec59[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fRec55[2] = fRec55[1];
			fRec55[1] = fRec55[0];
			fRec67[1] = fRec67[0];
			fRec66[2] = fRec66[1];
			fRec66[1] = fRec66[0];
			fVec6[1] = fVec6[0];
			fRec65[1] = fRec65[0];
			fRec64[2] = fRec64[1];
			fRec64[1] = fRec64[0];
			fVec7[1] = fVec7[0];
			fRec63[1] = fRec63[0];
			fRec62[2] = fRec62[1];
			fRec62[1] = fRec62[0];
			fVec8[1] = fVec8[0];
			fRec61[1] = fRec61[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec69[1] = fRec69[0];
			fRec68[2] = fRec68[1];
			fRec68[1] = fRec68[0];
			fRec72[1] = fRec72[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec76[1] = fRec76[0];
			fRec75[2] = fRec75[1];
			fRec75[1] = fRec75[0];
			fRec74[2] = fRec74[1];
			fRec74[1] = fRec74[0];
			fRec73[2] = fRec73[1];
			fRec73[1] = fRec73[0];
			fRec81[1] = fRec81[0];
			fRec80[2] = fRec80[1];
			fRec80[1] = fRec80[0];
			fRec79[2] = fRec79[1];
			fRec79[1] = fRec79[0];
			fRec78[2] = fRec78[1];
			fRec78[1] = fRec78[0];
			fRec77[2] = fRec77[1];
			fRec77[1] = fRec77[0];
			fRec89[1] = fRec89[0];
			fRec88[2] = fRec88[1];
			fRec88[1] = fRec88[0];
			fVec9[1] = fVec9[0];
			fRec87[1] = fRec87[0];
			fRec86[2] = fRec86[1];
			fRec86[1] = fRec86[0];
			fVec10[1] = fVec10[0];
			fRec85[1] = fRec85[0];
			fRec84[2] = fRec84[1];
			fRec84[1] = fRec84[0];
			fVec11[1] = fVec11[0];
			fRec83[1] = fRec83[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			fRec91[1] = fRec91[0];
			fRec90[2] = fRec90[1];
			fRec90[1] = fRec90[0];
			fRec94[1] = fRec94[0];
			fRec93[2] = fRec93[1];
			fRec93[1] = fRec93[0];
			fRec92[2] = fRec92[1];
			fRec92[1] = fRec92[0];
			fRec98[1] = fRec98[0];
			fRec97[2] = fRec97[1];
			fRec97[1] = fRec97[0];
			fRec96[2] = fRec96[1];
			fRec96[1] = fRec96[0];
			fRec95[2] = fRec95[1];
			fRec95[1] = fRec95[0];
			fRec103[1] = fRec103[0];
			fRec102[2] = fRec102[1];
			fRec102[1] = fRec102[0];
			fRec101[2] = fRec101[1];
			fRec101[1] = fRec101[0];
			fRec100[2] = fRec100[1];
			fRec100[1] = fRec100[0];
			fRec99[2] = fRec99[1];
			fRec99[1] = fRec99[0];
			fRec111[1] = fRec111[0];
			fRec110[2] = fRec110[1];
			fRec110[1] = fRec110[0];
			fVec12[1] = fVec12[0];
			fRec109[1] = fRec109[0];
			fRec108[2] = fRec108[1];
			fRec108[1] = fRec108[0];
			fVec13[1] = fVec13[0];
			fRec107[1] = fRec107[0];
			fRec106[2] = fRec106[1];
			fRec106[1] = fRec106[0];
			fVec14[1] = fVec14[0];
			fRec105[1] = fRec105[0];
			fRec104[2] = fRec104[1];
			fRec104[1] = fRec104[0];
			fRec113[1] = fRec113[0];
			fRec112[2] = fRec112[1];
			fRec112[1] = fRec112[0];
			fRec116[1] = fRec116[0];
			fRec115[2] = fRec115[1];
			fRec115[1] = fRec115[0];
			fRec114[2] = fRec114[1];
			fRec114[1] = fRec114[0];
			fRec120[1] = fRec120[0];
			fRec119[2] = fRec119[1];
			fRec119[1] = fRec119[0];
			fRec118[2] = fRec118[1];
			fRec118[1] = fRec118[0];
			fRec117[2] = fRec117[1];
			fRec117[1] = fRec117[0];
			fRec125[1] = fRec125[0];
			fRec124[2] = fRec124[1];
			fRec124[1] = fRec124[0];
			fRec123[2] = fRec123[1];
			fRec123[1] = fRec123[0];
			fRec122[2] = fRec122[1];
			fRec122[1] = fRec122[0];
			fRec121[2] = fRec121[1];
			fRec121[1] = fRec121[0];
			fRec133[1] = fRec133[0];
			fRec132[2] = fRec132[1];
			fRec132[1] = fRec132[0];
			fVec15[1] = fVec15[0];
			fRec131[1] = fRec131[0];
			fRec130[2] = fRec130[1];
			fRec130[1] = fRec130[0];
			fVec16[1] = fVec16[0];
			fRec129[1] = fRec129[0];
			fRec128[2] = fRec128[1];
			fRec128[1] = fRec128[0];
			fVec17[1] = fVec17[0];
			fRec127[1] = fRec127[0];
			fRec126[2] = fRec126[1];
			fRec126[1] = fRec126[0];
			fRec135[1] = fRec135[0];
			fRec134[2] = fRec134[1];
			fRec134[1] = fRec134[0];
			fRec138[1] = fRec138[0];
			fRec137[2] = fRec137[1];
			fRec137[1] = fRec137[0];
			fRec136[2] = fRec136[1];
			fRec136[1] = fRec136[0];
			fRec142[1] = fRec142[0];
			fRec141[2] = fRec141[1];
			fRec141[1] = fRec141[0];
			fRec140[2] = fRec140[1];
			fRec140[1] = fRec140[0];
			fRec139[2] = fRec139[1];
			fRec139[1] = fRec139[0];
			fRec147[1] = fRec147[0];
			fRec146[2] = fRec146[1];
			fRec146[1] = fRec146[0];
			fRec145[2] = fRec145[1];
			fRec145[1] = fRec145[0];
			fRec144[2] = fRec144[1];
			fRec144[1] = fRec144[0];
			fRec143[2] = fRec143[1];
			fRec143[1] = fRec143[0];
			fRec155[1] = fRec155[0];
			fRec154[2] = fRec154[1];
			fRec154[1] = fRec154[0];
			fVec18[1] = fVec18[0];
			fRec153[1] = fRec153[0];
			fRec152[2] = fRec152[1];
			fRec152[1] = fRec152[0];
			fVec19[1] = fVec19[0];
			fRec151[1] = fRec151[0];
			fRec150[2] = fRec150[1];
			fRec150[1] = fRec150[0];
			fVec20[1] = fVec20[0];
			fRec149[1] = fRec149[0];
			fRec148[2] = fRec148[1];
			fRec148[1] = fRec148[0];
			fRec157[1] = fRec157[0];
			fRec156[2] = fRec156[1];
			fRec156[1] = fRec156[0];
			fRec160[1] = fRec160[0];
			fRec159[2] = fRec159[1];
			fRec159[1] = fRec159[0];
			fRec158[2] = fRec158[1];
			fRec158[1] = fRec158[0];
			fRec164[1] = fRec164[0];
			fRec163[2] = fRec163[1];
			fRec163[1] = fRec163[0];
			fRec162[2] = fRec162[1];
			fRec162[1] = fRec162[0];
			fRec161[2] = fRec161[1];
			fRec161[1] = fRec161[0];
			fRec169[1] = fRec169[0];
			fRec168[2] = fRec168[1];
			fRec168[1] = fRec168[0];
			fRec167[2] = fRec167[1];
			fRec167[1] = fRec167[0];
			fRec166[2] = fRec166[1];
			fRec166[1] = fRec166[0];
			fRec165[2] = fRec165[1];
			fRec165[1] = fRec165[0];
			fRec177[1] = fRec177[0];
			fRec176[2] = fRec176[1];
			fRec176[1] = fRec176[0];
			fVec21[1] = fVec21[0];
			fRec175[1] = fRec175[0];
			fRec174[2] = fRec174[1];
			fRec174[1] = fRec174[0];
			fVec22[1] = fVec22[0];
			fRec173[1] = fRec173[0];
			fRec172[2] = fRec172[1];
			fRec172[1] = fRec172[0];
			fVec23[1] = fVec23[0];
			fRec171[1] = fRec171[0];
			fRec170[2] = fRec170[1];
			fRec170[1] = fRec170[0];
			fRec179[1] = fRec179[0];
			fRec178[2] = fRec178[1];
			fRec178[1] = fRec178[0];
			fRec182[1] = fRec182[0];
			fRec181[2] = fRec181[1];
			fRec181[1] = fRec181[0];
			fRec180[2] = fRec180[1];
			fRec180[1] = fRec180[0];
			fRec186[1] = fRec186[0];
			fRec185[2] = fRec185[1];
			fRec185[1] = fRec185[0];
			fRec184[2] = fRec184[1];
			fRec184[1] = fRec184[0];
			fRec183[2] = fRec183[1];
			fRec183[1] = fRec183[0];
			fRec191[1] = fRec191[0];
			fRec190[2] = fRec190[1];
			fRec190[1] = fRec190[0];
			fRec189[2] = fRec189[1];
			fRec189[1] = fRec189[0];
			fRec188[2] = fRec188[1];
			fRec188[1] = fRec188[0];
			fRec187[2] = fRec187[1];
			fRec187[1] = fRec187[0];
			fRec199[1] = fRec199[0];
			fRec198[2] = fRec198[1];
			fRec198[1] = fRec198[0];
			fVec24[1] = fVec24[0];
			fRec197[1] = fRec197[0];
			fRec196[2] = fRec196[1];
			fRec196[1] = fRec196[0];
			fVec25[1] = fVec25[0];
			fRec195[1] = fRec195[0];
			fRec194[2] = fRec194[1];
			fRec194[1] = fRec194[0];
			fVec26[1] = fVec26[0];
			fRec193[1] = fRec193[0];
			fRec192[2] = fRec192[1];
			fRec192[1] = fRec192[0];
			fRec201[1] = fRec201[0];
			fRec200[2] = fRec200[1];
			fRec200[1] = fRec200[0];
			fRec204[1] = fRec204[0];
			fRec203[2] = fRec203[1];
			fRec203[1] = fRec203[0];
			fRec202[2] = fRec202[1];
			fRec202[1] = fRec202[0];
			fRec208[1] = fRec208[0];
			fRec207[2] = fRec207[1];
			fRec207[1] = fRec207[0];
			fRec206[2] = fRec206[1];
			fRec206[1] = fRec206[0];
			fRec205[2] = fRec205[1];
			fRec205[1] = fRec205[0];
			fRec213[1] = fRec213[0];
			fRec212[2] = fRec212[1];
			fRec212[1] = fRec212[0];
			fRec211[2] = fRec211[1];
			fRec211[1] = fRec211[0];
			fRec210[2] = fRec210[1];
			fRec210[1] = fRec210[0];
			fRec209[2] = fRec209[1];
			fRec209[1] = fRec209[0];
			fRec221[1] = fRec221[0];
			fRec220[2] = fRec220[1];
			fRec220[1] = fRec220[0];
			fVec27[1] = fVec27[0];
			fRec219[1] = fRec219[0];
			fRec218[2] = fRec218[1];
			fRec218[1] = fRec218[0];
			fVec28[1] = fVec28[0];
			fRec217[1] = fRec217[0];
			fRec216[2] = fRec216[1];
			fRec216[1] = fRec216[0];
			fVec29[1] = fVec29[0];
			fRec215[1] = fRec215[0];
			fRec214[2] = fRec214[1];
			fRec214[1] = fRec214[0];
			fRec223[1] = fRec223[0];
			fRec222[2] = fRec222[1];
			fRec222[1] = fRec222[0];
			fRec226[1] = fRec226[0];
			fRec225[2] = fRec225[1];
			fRec225[1] = fRec225[0];
			fRec224[2] = fRec224[1];
			fRec224[1] = fRec224[0];
			fRec230[1] = fRec230[0];
			fRec229[2] = fRec229[1];
			fRec229[1] = fRec229[0];
			fRec228[2] = fRec228[1];
			fRec228[1] = fRec228[0];
			fRec227[2] = fRec227[1];
			fRec227[1] = fRec227[0];
			fRec235[1] = fRec235[0];
			fRec234[2] = fRec234[1];
			fRec234[1] = fRec234[0];
			fRec233[2] = fRec233[1];
			fRec233[1] = fRec233[0];
			fRec232[2] = fRec232[1];
			fRec232[1] = fRec232[0];
			fRec231[2] = fRec231[1];
			fRec231[1] = fRec231[0];
			fRec243[1] = fRec243[0];
			fRec242[2] = fRec242[1];
			fRec242[1] = fRec242[0];
			fVec30[1] = fVec30[0];
			fRec241[1] = fRec241[0];
			fRec240[2] = fRec240[1];
			fRec240[1] = fRec240[0];
			fVec31[1] = fVec31[0];
			fRec239[1] = fRec239[0];
			fRec238[2] = fRec238[1];
			fRec238[1] = fRec238[0];
			fVec32[1] = fVec32[0];
			fRec237[1] = fRec237[0];
			fRec236[2] = fRec236[1];
			fRec236[1] = fRec236[0];
			fRec245[1] = fRec245[0];
			fRec244[2] = fRec244[1];
			fRec244[1] = fRec244[0];
			fRec248[1] = fRec248[0];
			fRec247[2] = fRec247[1];
			fRec247[1] = fRec247[0];
			fRec246[2] = fRec246[1];
			fRec246[1] = fRec246[0];
			fRec252[1] = fRec252[0];
			fRec251[2] = fRec251[1];
			fRec251[1] = fRec251[0];
			fRec250[2] = fRec250[1];
			fRec250[1] = fRec250[0];
			fRec249[2] = fRec249[1];
			fRec249[1] = fRec249[0];
			fRec257[1] = fRec257[0];
			fRec256[2] = fRec256[1];
			fRec256[1] = fRec256[0];
			fRec255[2] = fRec255[1];
			fRec255[1] = fRec255[0];
			fRec254[2] = fRec254[1];
			fRec254[1] = fRec254[0];
			fRec253[2] = fRec253[1];
			fRec253[1] = fRec253[0];
			fRec265[1] = fRec265[0];
			fRec264[2] = fRec264[1];
			fRec264[1] = fRec264[0];
			fVec33[1] = fVec33[0];
			fRec263[1] = fRec263[0];
			fRec262[2] = fRec262[1];
			fRec262[1] = fRec262[0];
			fVec34[1] = fVec34[0];
			fRec261[1] = fRec261[0];
			fRec260[2] = fRec260[1];
			fRec260[1] = fRec260[0];
			fVec35[1] = fVec35[0];
			fRec259[1] = fRec259[0];
			fRec258[2] = fRec258[1];
			fRec258[1] = fRec258[0];
			fRec267[1] = fRec267[0];
			fRec266[2] = fRec266[1];
			fRec266[1] = fRec266[0];
			fRec270[1] = fRec270[0];
			fRec269[2] = fRec269[1];
			fRec269[1] = fRec269[0];
			fRec268[2] = fRec268[1];
			fRec268[1] = fRec268[0];
			fRec274[1] = fRec274[0];
			fRec273[2] = fRec273[1];
			fRec273[1] = fRec273[0];
			fRec272[2] = fRec272[1];
			fRec272[1] = fRec272[0];
			fRec271[2] = fRec271[1];
			fRec271[1] = fRec271[0];
			fRec279[1] = fRec279[0];
			fRec278[2] = fRec278[1];
			fRec278[1] = fRec278[0];
			fRec277[2] = fRec277[1];
			fRec277[1] = fRec277[0];
			fRec276[2] = fRec276[1];
			fRec276[1] = fRec276[0];
			fRec275[2] = fRec275[1];
			fRec275[1] = fRec275[0];
			fRec287[1] = fRec287[0];
			fRec286[2] = fRec286[1];
			fRec286[1] = fRec286[0];
			fVec36[1] = fVec36[0];
			fRec285[1] = fRec285[0];
			fRec284[2] = fRec284[1];
			fRec284[1] = fRec284[0];
			fVec37[1] = fVec37[0];
			fRec283[1] = fRec283[0];
			fRec282[2] = fRec282[1];
			fRec282[1] = fRec282[0];
			fVec38[1] = fVec38[0];
			fRec281[1] = fRec281[0];
			fRec280[2] = fRec280[1];
			fRec280[1] = fRec280[0];
			fRec289[1] = fRec289[0];
			fRec288[2] = fRec288[1];
			fRec288[1] = fRec288[0];
			fRec292[1] = fRec292[0];
			fRec291[2] = fRec291[1];
			fRec291[1] = fRec291[0];
			fRec290[2] = fRec290[1];
			fRec290[1] = fRec290[0];
			fRec296[1] = fRec296[0];
			fRec295[2] = fRec295[1];
			fRec295[1] = fRec295[0];
			fRec294[2] = fRec294[1];
			fRec294[1] = fRec294[0];
			fRec293[2] = fRec293[1];
			fRec293[1] = fRec293[0];
			fRec301[1] = fRec301[0];
			fRec300[2] = fRec300[1];
			fRec300[1] = fRec300[0];
			fRec299[2] = fRec299[1];
			fRec299[1] = fRec299[0];
			fRec298[2] = fRec298[1];
			fRec298[1] = fRec298[0];
			fRec297[2] = fRec297[1];
			fRec297[1] = fRec297[0];
			fRec309[1] = fRec309[0];
			fRec308[2] = fRec308[1];
			fRec308[1] = fRec308[0];
			fVec39[1] = fVec39[0];
			fRec307[1] = fRec307[0];
			fRec306[2] = fRec306[1];
			fRec306[1] = fRec306[0];
			fVec40[1] = fVec40[0];
			fRec305[1] = fRec305[0];
			fRec304[2] = fRec304[1];
			fRec304[1] = fRec304[0];
			fVec41[1] = fVec41[0];
			fRec303[1] = fRec303[0];
			fRec302[2] = fRec302[1];
			fRec302[1] = fRec302[0];
			fRec311[1] = fRec311[0];
			fRec310[2] = fRec310[1];
			fRec310[1] = fRec310[0];
			fRec314[1] = fRec314[0];
			fRec313[2] = fRec313[1];
			fRec313[1] = fRec313[0];
			fRec312[2] = fRec312[1];
			fRec312[1] = fRec312[0];
			fRec318[1] = fRec318[0];
			fRec317[2] = fRec317[1];
			fRec317[1] = fRec317[0];
			fRec316[2] = fRec316[1];
			fRec316[1] = fRec316[0];
			fRec315[2] = fRec315[1];
			fRec315[1] = fRec315[0];
			fRec323[1] = fRec323[0];
			fRec322[2] = fRec322[1];
			fRec322[1] = fRec322[0];
			fRec321[2] = fRec321[1];
			fRec321[1] = fRec321[0];
			fRec320[2] = fRec320[1];
			fRec320[1] = fRec320[0];
			fRec319[2] = fRec319[1];
			fRec319[1] = fRec319[0];
			fRec331[1] = fRec331[0];
			fRec330[2] = fRec330[1];
			fRec330[1] = fRec330[0];
			fVec42[1] = fVec42[0];
			fRec329[1] = fRec329[0];
			fRec328[2] = fRec328[1];
			fRec328[1] = fRec328[0];
			fVec43[1] = fVec43[0];
			fRec327[1] = fRec327[0];
			fRec326[2] = fRec326[1];
			fRec326[1] = fRec326[0];
			fVec44[1] = fVec44[0];
			fRec325[1] = fRec325[0];
			fRec324[2] = fRec324[1];
			fRec324[1] = fRec324[0];
			fRec333[1] = fRec333[0];
			fRec332[2] = fRec332[1];
			fRec332[1] = fRec332[0];
			fRec336[1] = fRec336[0];
			fRec335[2] = fRec335[1];
			fRec335[1] = fRec335[0];
			fRec334[2] = fRec334[1];
			fRec334[1] = fRec334[0];
			fRec340[1] = fRec340[0];
			fRec339[2] = fRec339[1];
			fRec339[1] = fRec339[0];
			fRec338[2] = fRec338[1];
			fRec338[1] = fRec338[0];
			fRec337[2] = fRec337[1];
			fRec337[1] = fRec337[0];
			fRec345[1] = fRec345[0];
			fRec344[2] = fRec344[1];
			fRec344[1] = fRec344[0];
			fRec343[2] = fRec343[1];
			fRec343[1] = fRec343[0];
			fRec342[2] = fRec342[1];
			fRec342[1] = fRec342[0];
			fRec341[2] = fRec341[1];
			fRec341[1] = fRec341[0];
			fRec353[1] = fRec353[0];
			fRec352[2] = fRec352[1];
			fRec352[1] = fRec352[0];
			fVec45[1] = fVec45[0];
			fRec351[1] = fRec351[0];
			fRec350[2] = fRec350[1];
			fRec350[1] = fRec350[0];
			fVec46[1] = fVec46[0];
			fRec349[1] = fRec349[0];
			fRec348[2] = fRec348[1];
			fRec348[1] = fRec348[0];
			fVec47[1] = fVec47[0];
			fRec347[1] = fRec347[0];
			fRec346[2] = fRec346[1];
			fRec346[1] = fRec346[0];
			fRec355[1] = fRec355[0];
			fRec354[2] = fRec354[1];
			fRec354[1] = fRec354[0];
			fRec358[1] = fRec358[0];
			fRec357[2] = fRec357[1];
			fRec357[1] = fRec357[0];
			fRec356[2] = fRec356[1];
			fRec356[1] = fRec356[0];
			fRec362[1] = fRec362[0];
			fRec361[2] = fRec361[1];
			fRec361[1] = fRec361[0];
			fRec360[2] = fRec360[1];
			fRec360[1] = fRec360[0];
			fRec359[2] = fRec359[1];
			fRec359[1] = fRec359[0];
			fRec367[1] = fRec367[0];
			fRec366[2] = fRec366[1];
			fRec366[1] = fRec366[0];
			fRec365[2] = fRec365[1];
			fRec365[1] = fRec365[0];
			fRec364[2] = fRec364[1];
			fRec364[1] = fRec364[0];
			fRec363[2] = fRec363[1];
			fRec363[1] = fRec363[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec368[1] = fRec368[0];
		}
	}

};

#endif
