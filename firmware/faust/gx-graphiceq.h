/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Graphic EQ"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxGraphiceq -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxGraphiceq_H__
#define  __GxGraphiceq_H__

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
#define FAUSTCLASS GxGraphiceq
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

static double GxGraphiceq_faustpower2_f(double value) {
	return value * value;
}

class GxGraphiceq : public chdsp {
	
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
	double fVec0[2];
	double fConst72;
	double fConst73;
	double fRec22[2];
	double fRec21[3];
	double fVec1[2];
	double fConst74;
	double fConst75;
	double fConst76;
	double fRec20[2];
	double fRec19[3];
	double fVec2[2];
	double fConst77;
	double fConst78;
	double fConst79;
	double fRec18[2];
	double fRec17[3];
	double fVec3[2];
	double fConst80;
	double fConst81;
	double fConst82;
	double fRec16[2];
	double fRec15[3];
	double fVec4[2];
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec14[2];
	double fRec13[3];
	double fVec5[2];
	double fConst86;
	double fConst87;
	double fConst88;
	double fRec12[2];
	double fRec11[3];
	double fVec6[2];
	double fConst89;
	double fConst90;
	double fConst91;
	double fRec10[2];
	double fRec9[3];
	double fVec7[2];
	double fConst92;
	double fConst93;
	double fConst94;
	double fRec8[2];
	double fRec7[3];
	double fVec8[2];
	double fConst95;
	double fConst96;
	double fConst97;
	double fRec6[2];
	double fRec5[3];
	double fVec9[2];
	double fConst98;
	double fConst99;
	double fConst100;
	double fRec4[2];
	double fRec3[3];
	FAUSTFLOAT fVslider0;
	double fRec23[2];
	double fRec0[2];
	int iRec1[2];
	double fRec2[2];
	FAUSTFLOAT fVbargraph0;
	double fConst101;
	double fRec28[2];
	double fRec27[3];
	FAUSTFLOAT fVslider1;
	double fRec29[2];
	double fConst102;
	double fRec24[2];
	int iRec25[2];
	double fRec26[2];
	FAUSTFLOAT fVbargraph1;
	double fConst103;
	double fConst104;
	double fConst105;
	double fRec35[2];
	double fRec34[3];
	double fConst106;
	double fRec33[3];
	FAUSTFLOAT fVslider2;
	double fRec36[2];
	double fRec30[2];
	int iRec31[2];
	double fRec32[2];
	FAUSTFLOAT fVbargraph2;
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec43[2];
	double fRec42[3];
	double fConst110;
	double fRec41[3];
	double fRec40[3];
	FAUSTFLOAT fVslider3;
	double fRec44[2];
	double fRec37[2];
	int iRec38[2];
	double fRec39[2];
	FAUSTFLOAT fVbargraph3;
	double fConst111;
	double fConst112;
	double fConst113;
	double fRec52[2];
	double fRec51[3];
	double fConst114;
	double fRec50[3];
	double fRec49[3];
	double fRec48[3];
	FAUSTFLOAT fVslider4;
	double fRec53[2];
	double fRec45[2];
	int iRec46[2];
	double fRec47[2];
	FAUSTFLOAT fVbargraph4;
	double fConst115;
	double fConst116;
	double fConst117;
	double fRec62[2];
	double fRec61[3];
	double fConst118;
	double fRec60[3];
	double fRec59[3];
	double fRec58[3];
	double fRec57[3];
	FAUSTFLOAT fVslider5;
	double fRec63[2];
	double fRec54[2];
	int iRec55[2];
	double fRec56[2];
	FAUSTFLOAT fVbargraph5;
	double fConst119;
	double fConst120;
	double fConst121;
	double fRec73[2];
	double fRec72[3];
	double fConst122;
	double fRec71[3];
	double fRec70[3];
	double fRec69[3];
	double fRec68[3];
	double fRec67[3];
	FAUSTFLOAT fVslider6;
	double fRec74[2];
	double fRec64[2];
	int iRec65[2];
	double fRec66[2];
	FAUSTFLOAT fVbargraph6;
	double fConst123;
	double fConst124;
	double fConst125;
	double fRec85[2];
	double fRec84[3];
	double fConst126;
	double fRec83[3];
	double fRec82[3];
	double fRec81[3];
	double fRec80[3];
	double fRec79[3];
	double fRec78[3];
	FAUSTFLOAT fVslider7;
	double fRec86[2];
	double fRec75[2];
	int iRec76[2];
	double fRec77[2];
	FAUSTFLOAT fVbargraph7;
	double fConst127;
	double fConst128;
	double fConst129;
	double fRec98[2];
	double fRec97[3];
	double fConst130;
	double fRec96[3];
	double fRec95[3];
	double fRec94[3];
	double fRec93[3];
	double fRec92[3];
	double fRec91[3];
	double fRec90[3];
	FAUSTFLOAT fVslider8;
	double fRec99[2];
	double fRec87[2];
	int iRec88[2];
	double fRec89[2];
	FAUSTFLOAT fVbargraph8;
	double fConst131;
	double fConst132;
	double fConst133;
	double fRec112[2];
	double fRec111[3];
	double fConst134;
	double fRec110[3];
	double fRec109[3];
	double fRec108[3];
	double fRec107[3];
	double fRec106[3];
	double fRec105[3];
	double fRec104[3];
	double fRec103[3];
	FAUSTFLOAT fVslider9;
	double fRec113[2];
	double fRec100[2];
	int iRec101[2];
	double fRec102[2];
	FAUSTFLOAT fVbargraph9;
	double fConst135;
	double fConst136;
	double fRec127[2];
	double fRec126[3];
	double fConst137;
	double fRec125[3];
	double fRec124[3];
	double fRec123[3];
	double fRec122[3];
	double fRec121[3];
	double fRec120[3];
	double fRec119[3];
	double fRec118[3];
	double fRec117[3];
	FAUSTFLOAT fVslider10;
	double fRec128[2];
	double fRec114[2];
	int iRec115[2];
	double fRec116[2];
	FAUSTFLOAT fVbargraph10;
	
 public:
	GxGraphiceq() {
	}
	
	GxGraphiceq(const GxGraphiceq&) = default;
	
	virtual ~GxGraphiceq() = default;
	
	GxGraphiceq& operator=(const GxGraphiceq&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Tone Control");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxGraphiceq -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Graphic EQ");
		m->declare("filename", "gx-graphiceq.dsp");
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
		m->declare("id", "graphiceq");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Graphic EQ");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reducemaps.lib/author", "Yann Orlarey");
		m->declare("reducemaps.lib/copyright", "Grame and Yann Orlarey");
		m->declare("reducemaps.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("reducemaps.lib/name", "Reduce Library");
		m->declare("reducemaps.lib/version", "1.2.0");
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
		fConst1 = 1.0 / fConst0;
		fConst2 = std::tan(138.23007675795088 / fConst0);
		fConst3 = GxGraphiceq_faustpower2_f(fConst2);
		fConst4 = 2.0 * (1.0 - 1.0 / fConst3);
		fConst5 = 1.0 / fConst2;
		fConst6 = (fConst5 + -1.0000000000000004) / fConst2 + 1.0;
		fConst7 = (fConst5 + 1.0000000000000004) / fConst2 + 1.0;
		fConst8 = 1.0 / fConst7;
		fConst9 = std::tan(276.46015351590177 / fConst0);
		fConst10 = GxGraphiceq_faustpower2_f(fConst9);
		fConst11 = 2.0 * (1.0 - 1.0 / fConst10);
		fConst12 = 1.0 / fConst9;
		fConst13 = (fConst12 + -1.0000000000000004) / fConst9 + 1.0;
		fConst14 = (fConst12 + 1.0000000000000004) / fConst9 + 1.0;
		fConst15 = 1.0 / fConst14;
		fConst16 = std::tan(556.0618996853934 / fConst0);
		fConst17 = GxGraphiceq_faustpower2_f(fConst16);
		fConst18 = 2.0 * (1.0 - 1.0 / fConst17);
		fConst19 = 1.0 / fConst16;
		fConst20 = (fConst19 + -1.0000000000000004) / fConst16 + 1.0;
		fConst21 = (fConst19 + 1.0000000000000004) / fConst16 + 1.0;
		fConst22 = 1.0 / fConst21;
		fConst23 = std::tan(1112.1237993707869 / fConst0);
		fConst24 = GxGraphiceq_faustpower2_f(fConst23);
		fConst25 = 2.0 * (1.0 - 1.0 / fConst24);
		fConst26 = 1.0 / fConst23;
		fConst27 = (fConst26 + -1.0000000000000004) / fConst23 + 1.0;
		fConst28 = (fConst26 + 1.0000000000000004) / fConst23 + 1.0;
		fConst29 = 1.0 / fConst28;
		fConst30 = std::tan(2221.1060060879836 / fConst0);
		fConst31 = GxGraphiceq_faustpower2_f(fConst30);
		fConst32 = 2.0 * (1.0 - 1.0 / fConst31);
		fConst33 = 1.0 / fConst30;
		fConst34 = (fConst33 + -1.0000000000000004) / fConst30 + 1.0;
		fConst35 = (fConst33 + 1.0000000000000004) / fConst30 + 1.0;
		fConst36 = 1.0 / fConst35;
		fConst37 = std::tan(4442.212012175967 / fConst0);
		fConst38 = GxGraphiceq_faustpower2_f(fConst37);
		fConst39 = 2.0 * (1.0 - 1.0 / fConst38);
		fConst40 = 1.0 / fConst37;
		fConst41 = (fConst40 + -1.0000000000000004) / fConst37 + 1.0;
		fConst42 = (fConst40 + 1.0000000000000004) / fConst37 + 1.0;
		fConst43 = 1.0 / fConst42;
		fConst44 = std::tan(8884.424024351934 / fConst0);
		fConst45 = GxGraphiceq_faustpower2_f(fConst44);
		fConst46 = 2.0 * (1.0 - 1.0 / fConst45);
		fConst47 = 1.0 / fConst44;
		fConst48 = (fConst47 + -1.0000000000000004) / fConst44 + 1.0;
		fConst49 = (fConst47 + 1.0000000000000004) / fConst44 + 1.0;
		fConst50 = 1.0 / fConst49;
		fConst51 = std::tan(17771.98964135746 / fConst0);
		fConst52 = GxGraphiceq_faustpower2_f(fConst51);
		fConst53 = 2.0 * (1.0 - 1.0 / fConst52);
		fConst54 = 1.0 / fConst51;
		fConst55 = (fConst54 + -1.0000000000000004) / fConst51 + 1.0;
		fConst56 = (fConst54 + 1.0000000000000004) / fConst51 + 1.0;
		fConst57 = 1.0 / fConst56;
		fConst58 = std::tan(35763.890768466204 / fConst0);
		fConst59 = GxGraphiceq_faustpower2_f(fConst58);
		fConst60 = 2.0 * (1.0 - 1.0 / fConst59);
		fConst61 = 1.0 / fConst58;
		fConst62 = (fConst61 + -1.0000000000000004) / fConst58 + 1.0;
		fConst63 = (fConst61 + 1.0000000000000004) / fConst58 + 1.0;
		fConst64 = 1.0 / fConst63;
		fConst65 = std::tan(56894.24295651115 / fConst0);
		fConst66 = GxGraphiceq_faustpower2_f(fConst65);
		fConst67 = 2.0 * (1.0 - 1.0 / fConst66);
		fConst68 = 1.0 / fConst65;
		fConst69 = (fConst68 + -1.0000000000000004) / fConst65 + 1.0;
		fConst70 = (fConst68 + 1.0000000000000004) / fConst65 + 1.0;
		fConst71 = 1.0 / fConst70;
		fConst72 = 1.0 - fConst68;
		fConst73 = 1.0 / (fConst68 + 1.0);
		fConst74 = 1.0 - fConst61;
		fConst75 = fConst61 + 1.0;
		fConst76 = 1.0 / fConst75;
		fConst77 = 1.0 - fConst54;
		fConst78 = fConst54 + 1.0;
		fConst79 = 1.0 / fConst78;
		fConst80 = 1.0 - fConst47;
		fConst81 = fConst47 + 1.0;
		fConst82 = 1.0 / fConst81;
		fConst83 = 1.0 - fConst40;
		fConst84 = fConst40 + 1.0;
		fConst85 = 1.0 / fConst84;
		fConst86 = 1.0 - fConst33;
		fConst87 = fConst33 + 1.0;
		fConst88 = 1.0 / fConst87;
		fConst89 = 1.0 - fConst26;
		fConst90 = fConst26 + 1.0;
		fConst91 = 1.0 / fConst90;
		fConst92 = 1.0 - fConst19;
		fConst93 = fConst19 + 1.0;
		fConst94 = 1.0 / fConst93;
		fConst95 = 1.0 - fConst12;
		fConst96 = fConst12 + 1.0;
		fConst97 = 1.0 / fConst96;
		fConst98 = 1.0 - fConst5;
		fConst99 = fConst5 + 1.0;
		fConst100 = 1.0 / fConst99;
		fConst101 = 1.0 / (fConst2 * fConst14);
		fConst102 = 1.0 / (fConst3 * fConst7);
		fConst103 = 1.0 - fConst98 / fConst2;
		fConst104 = 1.0 / (fConst99 / fConst2 + 1.0);
		fConst105 = 1.0 / (fConst9 * fConst21);
		fConst106 = 1.0 / (fConst10 * fConst14);
		fConst107 = 1.0 - fConst95 / fConst9;
		fConst108 = 1.0 / (fConst96 / fConst9 + 1.0);
		fConst109 = 1.0 / (fConst16 * fConst28);
		fConst110 = 1.0 / (fConst17 * fConst21);
		fConst111 = 1.0 - fConst92 / fConst16;
		fConst112 = 1.0 / (fConst93 / fConst16 + 1.0);
		fConst113 = 1.0 / (fConst23 * fConst35);
		fConst114 = 1.0 / (fConst24 * fConst28);
		fConst115 = 1.0 - fConst89 / fConst23;
		fConst116 = 1.0 / (fConst90 / fConst23 + 1.0);
		fConst117 = 1.0 / (fConst30 * fConst42);
		fConst118 = 1.0 / (fConst31 * fConst35);
		fConst119 = 1.0 - fConst86 / fConst30;
		fConst120 = 1.0 / (fConst87 / fConst30 + 1.0);
		fConst121 = 1.0 / (fConst37 * fConst49);
		fConst122 = 1.0 / (fConst38 * fConst42);
		fConst123 = 1.0 - fConst83 / fConst37;
		fConst124 = 1.0 / (fConst84 / fConst37 + 1.0);
		fConst125 = 1.0 / (fConst44 * fConst56);
		fConst126 = 1.0 / (fConst45 * fConst49);
		fConst127 = 1.0 - fConst80 / fConst44;
		fConst128 = 1.0 / (fConst81 / fConst44 + 1.0);
		fConst129 = 1.0 / (fConst51 * fConst63);
		fConst130 = 1.0 / (fConst52 * fConst56);
		fConst131 = 1.0 - fConst77 / fConst51;
		fConst132 = 1.0 / (fConst78 / fConst51 + 1.0);
		fConst133 = 1.0 / (fConst58 * fConst70);
		fConst134 = 1.0 / (fConst59 * fConst63);
		fConst135 = 1.0 - fConst74 / fConst58;
		fConst136 = 1.0 / (fConst75 / fConst58 + 1.0);
		fConst137 = 1.0 / (fConst66 * fConst70);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider1 = static_cast<FAUSTFLOAT>(0.0);
		fVslider2 = static_cast<FAUSTFLOAT>(0.0);
		fVslider3 = static_cast<FAUSTFLOAT>(0.0);
		fVslider4 = static_cast<FAUSTFLOAT>(0.0);
		fVslider5 = static_cast<FAUSTFLOAT>(0.0);
		fVslider6 = static_cast<FAUSTFLOAT>(0.0);
		fVslider7 = static_cast<FAUSTFLOAT>(0.0);
		fVslider8 = static_cast<FAUSTFLOAT>(0.0);
		fVslider9 = static_cast<FAUSTFLOAT>(0.0);
		fVslider10 = static_cast<FAUSTFLOAT>(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec22[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = faust_wrap_add(l2, 1)) {
			fRec21[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec1[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec20[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = faust_wrap_add(l5, 1)) {
			fRec19[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec2[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec18[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 3; l8 = faust_wrap_add(l8, 1)) {
			fRec17[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fVec3[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec16[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 3; l11 = faust_wrap_add(l11, 1)) {
			fRec15[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fVec4[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec14[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 3; l14 = faust_wrap_add(l14, 1)) {
			fRec13[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fVec5[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec12[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 3; l17 = faust_wrap_add(l17, 1)) {
			fRec11[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fVec6[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec10[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 3; l20 = faust_wrap_add(l20, 1)) {
			fRec9[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fVec7[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec8[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 3; l23 = faust_wrap_add(l23, 1)) {
			fRec7[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fVec8[l24] = 0.0;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec6[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 3; l26 = faust_wrap_add(l26, 1)) {
			fRec5[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fVec9[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec4[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 3; l29 = faust_wrap_add(l29, 1)) {
			fRec3[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec23[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec0[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			iRec1[l32] = 0;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec2[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec28[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 3; l35 = faust_wrap_add(l35, 1)) {
			fRec27[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec29[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec24[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			iRec25[l38] = 0;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec26[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec35[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 3; l41 = faust_wrap_add(l41, 1)) {
			fRec34[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 3; l42 = faust_wrap_add(l42, 1)) {
			fRec33[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec36[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec30[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			iRec31[l45] = 0;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fRec32[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fRec43[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 3; l48 = faust_wrap_add(l48, 1)) {
			fRec42[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 3; l49 = faust_wrap_add(l49, 1)) {
			fRec41[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 3; l50 = faust_wrap_add(l50, 1)) {
			fRec40[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fRec44[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec37[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			iRec38[l53] = 0;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fRec39[l54] = 0.0;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			fRec52[l55] = 0.0;
		}
		for (int l56 = 0; l56 < 3; l56 = faust_wrap_add(l56, 1)) {
			fRec51[l56] = 0.0;
		}
		for (int l57 = 0; l57 < 3; l57 = faust_wrap_add(l57, 1)) {
			fRec50[l57] = 0.0;
		}
		for (int l58 = 0; l58 < 3; l58 = faust_wrap_add(l58, 1)) {
			fRec49[l58] = 0.0;
		}
		for (int l59 = 0; l59 < 3; l59 = faust_wrap_add(l59, 1)) {
			fRec48[l59] = 0.0;
		}
		for (int l60 = 0; l60 < 2; l60 = faust_wrap_add(l60, 1)) {
			fRec53[l60] = 0.0;
		}
		for (int l61 = 0; l61 < 2; l61 = faust_wrap_add(l61, 1)) {
			fRec45[l61] = 0.0;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			iRec46[l62] = 0;
		}
		for (int l63 = 0; l63 < 2; l63 = faust_wrap_add(l63, 1)) {
			fRec47[l63] = 0.0;
		}
		for (int l64 = 0; l64 < 2; l64 = faust_wrap_add(l64, 1)) {
			fRec62[l64] = 0.0;
		}
		for (int l65 = 0; l65 < 3; l65 = faust_wrap_add(l65, 1)) {
			fRec61[l65] = 0.0;
		}
		for (int l66 = 0; l66 < 3; l66 = faust_wrap_add(l66, 1)) {
			fRec60[l66] = 0.0;
		}
		for (int l67 = 0; l67 < 3; l67 = faust_wrap_add(l67, 1)) {
			fRec59[l67] = 0.0;
		}
		for (int l68 = 0; l68 < 3; l68 = faust_wrap_add(l68, 1)) {
			fRec58[l68] = 0.0;
		}
		for (int l69 = 0; l69 < 3; l69 = faust_wrap_add(l69, 1)) {
			fRec57[l69] = 0.0;
		}
		for (int l70 = 0; l70 < 2; l70 = faust_wrap_add(l70, 1)) {
			fRec63[l70] = 0.0;
		}
		for (int l71 = 0; l71 < 2; l71 = faust_wrap_add(l71, 1)) {
			fRec54[l71] = 0.0;
		}
		for (int l72 = 0; l72 < 2; l72 = faust_wrap_add(l72, 1)) {
			iRec55[l72] = 0;
		}
		for (int l73 = 0; l73 < 2; l73 = faust_wrap_add(l73, 1)) {
			fRec56[l73] = 0.0;
		}
		for (int l74 = 0; l74 < 2; l74 = faust_wrap_add(l74, 1)) {
			fRec73[l74] = 0.0;
		}
		for (int l75 = 0; l75 < 3; l75 = faust_wrap_add(l75, 1)) {
			fRec72[l75] = 0.0;
		}
		for (int l76 = 0; l76 < 3; l76 = faust_wrap_add(l76, 1)) {
			fRec71[l76] = 0.0;
		}
		for (int l77 = 0; l77 < 3; l77 = faust_wrap_add(l77, 1)) {
			fRec70[l77] = 0.0;
		}
		for (int l78 = 0; l78 < 3; l78 = faust_wrap_add(l78, 1)) {
			fRec69[l78] = 0.0;
		}
		for (int l79 = 0; l79 < 3; l79 = faust_wrap_add(l79, 1)) {
			fRec68[l79] = 0.0;
		}
		for (int l80 = 0; l80 < 3; l80 = faust_wrap_add(l80, 1)) {
			fRec67[l80] = 0.0;
		}
		for (int l81 = 0; l81 < 2; l81 = faust_wrap_add(l81, 1)) {
			fRec74[l81] = 0.0;
		}
		for (int l82 = 0; l82 < 2; l82 = faust_wrap_add(l82, 1)) {
			fRec64[l82] = 0.0;
		}
		for (int l83 = 0; l83 < 2; l83 = faust_wrap_add(l83, 1)) {
			iRec65[l83] = 0;
		}
		for (int l84 = 0; l84 < 2; l84 = faust_wrap_add(l84, 1)) {
			fRec66[l84] = 0.0;
		}
		for (int l85 = 0; l85 < 2; l85 = faust_wrap_add(l85, 1)) {
			fRec85[l85] = 0.0;
		}
		for (int l86 = 0; l86 < 3; l86 = faust_wrap_add(l86, 1)) {
			fRec84[l86] = 0.0;
		}
		for (int l87 = 0; l87 < 3; l87 = faust_wrap_add(l87, 1)) {
			fRec83[l87] = 0.0;
		}
		for (int l88 = 0; l88 < 3; l88 = faust_wrap_add(l88, 1)) {
			fRec82[l88] = 0.0;
		}
		for (int l89 = 0; l89 < 3; l89 = faust_wrap_add(l89, 1)) {
			fRec81[l89] = 0.0;
		}
		for (int l90 = 0; l90 < 3; l90 = faust_wrap_add(l90, 1)) {
			fRec80[l90] = 0.0;
		}
		for (int l91 = 0; l91 < 3; l91 = faust_wrap_add(l91, 1)) {
			fRec79[l91] = 0.0;
		}
		for (int l92 = 0; l92 < 3; l92 = faust_wrap_add(l92, 1)) {
			fRec78[l92] = 0.0;
		}
		for (int l93 = 0; l93 < 2; l93 = faust_wrap_add(l93, 1)) {
			fRec86[l93] = 0.0;
		}
		for (int l94 = 0; l94 < 2; l94 = faust_wrap_add(l94, 1)) {
			fRec75[l94] = 0.0;
		}
		for (int l95 = 0; l95 < 2; l95 = faust_wrap_add(l95, 1)) {
			iRec76[l95] = 0;
		}
		for (int l96 = 0; l96 < 2; l96 = faust_wrap_add(l96, 1)) {
			fRec77[l96] = 0.0;
		}
		for (int l97 = 0; l97 < 2; l97 = faust_wrap_add(l97, 1)) {
			fRec98[l97] = 0.0;
		}
		for (int l98 = 0; l98 < 3; l98 = faust_wrap_add(l98, 1)) {
			fRec97[l98] = 0.0;
		}
		for (int l99 = 0; l99 < 3; l99 = faust_wrap_add(l99, 1)) {
			fRec96[l99] = 0.0;
		}
		for (int l100 = 0; l100 < 3; l100 = faust_wrap_add(l100, 1)) {
			fRec95[l100] = 0.0;
		}
		for (int l101 = 0; l101 < 3; l101 = faust_wrap_add(l101, 1)) {
			fRec94[l101] = 0.0;
		}
		for (int l102 = 0; l102 < 3; l102 = faust_wrap_add(l102, 1)) {
			fRec93[l102] = 0.0;
		}
		for (int l103 = 0; l103 < 3; l103 = faust_wrap_add(l103, 1)) {
			fRec92[l103] = 0.0;
		}
		for (int l104 = 0; l104 < 3; l104 = faust_wrap_add(l104, 1)) {
			fRec91[l104] = 0.0;
		}
		for (int l105 = 0; l105 < 3; l105 = faust_wrap_add(l105, 1)) {
			fRec90[l105] = 0.0;
		}
		for (int l106 = 0; l106 < 2; l106 = faust_wrap_add(l106, 1)) {
			fRec99[l106] = 0.0;
		}
		for (int l107 = 0; l107 < 2; l107 = faust_wrap_add(l107, 1)) {
			fRec87[l107] = 0.0;
		}
		for (int l108 = 0; l108 < 2; l108 = faust_wrap_add(l108, 1)) {
			iRec88[l108] = 0;
		}
		for (int l109 = 0; l109 < 2; l109 = faust_wrap_add(l109, 1)) {
			fRec89[l109] = 0.0;
		}
		for (int l110 = 0; l110 < 2; l110 = faust_wrap_add(l110, 1)) {
			fRec112[l110] = 0.0;
		}
		for (int l111 = 0; l111 < 3; l111 = faust_wrap_add(l111, 1)) {
			fRec111[l111] = 0.0;
		}
		for (int l112 = 0; l112 < 3; l112 = faust_wrap_add(l112, 1)) {
			fRec110[l112] = 0.0;
		}
		for (int l113 = 0; l113 < 3; l113 = faust_wrap_add(l113, 1)) {
			fRec109[l113] = 0.0;
		}
		for (int l114 = 0; l114 < 3; l114 = faust_wrap_add(l114, 1)) {
			fRec108[l114] = 0.0;
		}
		for (int l115 = 0; l115 < 3; l115 = faust_wrap_add(l115, 1)) {
			fRec107[l115] = 0.0;
		}
		for (int l116 = 0; l116 < 3; l116 = faust_wrap_add(l116, 1)) {
			fRec106[l116] = 0.0;
		}
		for (int l117 = 0; l117 < 3; l117 = faust_wrap_add(l117, 1)) {
			fRec105[l117] = 0.0;
		}
		for (int l118 = 0; l118 < 3; l118 = faust_wrap_add(l118, 1)) {
			fRec104[l118] = 0.0;
		}
		for (int l119 = 0; l119 < 3; l119 = faust_wrap_add(l119, 1)) {
			fRec103[l119] = 0.0;
		}
		for (int l120 = 0; l120 < 2; l120 = faust_wrap_add(l120, 1)) {
			fRec113[l120] = 0.0;
		}
		for (int l121 = 0; l121 < 2; l121 = faust_wrap_add(l121, 1)) {
			fRec100[l121] = 0.0;
		}
		for (int l122 = 0; l122 < 2; l122 = faust_wrap_add(l122, 1)) {
			iRec101[l122] = 0;
		}
		for (int l123 = 0; l123 < 2; l123 = faust_wrap_add(l123, 1)) {
			fRec102[l123] = 0.0;
		}
		for (int l124 = 0; l124 < 2; l124 = faust_wrap_add(l124, 1)) {
			fRec127[l124] = 0.0;
		}
		for (int l125 = 0; l125 < 3; l125 = faust_wrap_add(l125, 1)) {
			fRec126[l125] = 0.0;
		}
		for (int l126 = 0; l126 < 3; l126 = faust_wrap_add(l126, 1)) {
			fRec125[l126] = 0.0;
		}
		for (int l127 = 0; l127 < 3; l127 = faust_wrap_add(l127, 1)) {
			fRec124[l127] = 0.0;
		}
		for (int l128 = 0; l128 < 3; l128 = faust_wrap_add(l128, 1)) {
			fRec123[l128] = 0.0;
		}
		for (int l129 = 0; l129 < 3; l129 = faust_wrap_add(l129, 1)) {
			fRec122[l129] = 0.0;
		}
		for (int l130 = 0; l130 < 3; l130 = faust_wrap_add(l130, 1)) {
			fRec121[l130] = 0.0;
		}
		for (int l131 = 0; l131 < 3; l131 = faust_wrap_add(l131, 1)) {
			fRec120[l131] = 0.0;
		}
		for (int l132 = 0; l132 < 3; l132 = faust_wrap_add(l132, 1)) {
			fRec119[l132] = 0.0;
		}
		for (int l133 = 0; l133 < 3; l133 = faust_wrap_add(l133, 1)) {
			fRec118[l133] = 0.0;
		}
		for (int l134 = 0; l134 < 3; l134 = faust_wrap_add(l134, 1)) {
			fRec117[l134] = 0.0;
		}
		for (int l135 = 0; l135 < 2; l135 = faust_wrap_add(l135, 1)) {
			fRec128[l135] = 0.0;
		}
		for (int l136 = 0; l136 < 2; l136 = faust_wrap_add(l136, 1)) {
			fRec114[l136] = 0.0;
		}
		for (int l137 = 0; l137 < 2; l137 = faust_wrap_add(l137, 1)) {
			iRec115[l137] = 0;
		}
		for (int l138 = 0; l138 < 2; l138 = faust_wrap_add(l138, 1)) {
			fRec116[l138] = 0.0;
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
	
	virtual GxGraphiceq* clone() {
		return new GxGraphiceq(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Graphic EQ");
		ui_interface->declare(&fVslider9, "tooltip", "gain (dB) at 16 kHz");
		ui_interface->addVerticalSlider("g10", &fVslider9, FAUSTFLOAT(0.0), FAUSTFLOAT(-3e+01), FAUSTFLOAT(5.2), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider10, "tooltip", "gain (dB) above 16 kHz");
		ui_interface->addVerticalSlider("g11", &fVslider10, FAUSTFLOAT(0.0), FAUSTFLOAT(-3e+01), FAUSTFLOAT(5.2), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider0, "tooltip", "gain (dB) below 31.25 Hz");
		ui_interface->addVerticalSlider("g1", &fVslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(-6e+01), FAUSTFLOAT(5.2), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider1, "tooltip", "gain (dB) at 62.5 Hz");
		ui_interface->addVerticalSlider("g2", &fVslider1, FAUSTFLOAT(0.0), FAUSTFLOAT(-3e+01), FAUSTFLOAT(5.2), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider2, "tooltip", "gain (dB) at 125 Hz");
		ui_interface->addVerticalSlider("g3", &fVslider2, FAUSTFLOAT(0.0), FAUSTFLOAT(-3e+01), FAUSTFLOAT(5.2), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider3, "tooltip", "gain (dB) at 250 Hz");
		ui_interface->addVerticalSlider("g4", &fVslider3, FAUSTFLOAT(0.0), FAUSTFLOAT(-3e+01), FAUSTFLOAT(5.2), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider4, "tooltip", "gain (dB) at 500 Hz");
		ui_interface->addVerticalSlider("g5", &fVslider4, FAUSTFLOAT(0.0), FAUSTFLOAT(-3e+01), FAUSTFLOAT(5.2), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider5, "tooltip", "gain (dB) at 1 kHz");
		ui_interface->addVerticalSlider("g6", &fVslider5, FAUSTFLOAT(0.0), FAUSTFLOAT(-3e+01), FAUSTFLOAT(5.2), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider6, "tooltip", "gain (dB) at 2 kHz");
		ui_interface->addVerticalSlider("g7", &fVslider6, FAUSTFLOAT(0.0), FAUSTFLOAT(-3e+01), FAUSTFLOAT(5.2), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider7, "tooltip", "gain (dB) at 4 kHz");
		ui_interface->addVerticalSlider("g8", &fVslider7, FAUSTFLOAT(0.0), FAUSTFLOAT(-3e+01), FAUSTFLOAT(5.2), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider8, "tooltip", "gain (dB) at 8 kHz");
		ui_interface->addVerticalSlider("g9", &fVslider8, FAUSTFLOAT(0.0), FAUSTFLOAT(-3e+01), FAUSTFLOAT(5.2), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVbargraph9, "nomidi", "no");
		ui_interface->addVerticalBargraph("v10", &fVbargraph9, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph10, "nomidi", "no");
		ui_interface->addVerticalBargraph("v11", &fVbargraph10, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph0, "nomidi", "no");
		ui_interface->addVerticalBargraph("v1", &fVbargraph0, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph1, "nomidi", "no");
		ui_interface->addVerticalBargraph("v2", &fVbargraph1, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph2, "nomidi", "no");
		ui_interface->addVerticalBargraph("v3", &fVbargraph2, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph3, "nomidi", "no");
		ui_interface->addVerticalBargraph("v4", &fVbargraph3, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph4, "nomidi", "no");
		ui_interface->addVerticalBargraph("v5", &fVbargraph4, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph5, "nomidi", "no");
		ui_interface->addVerticalBargraph("v6", &fVbargraph5, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph6, "nomidi", "no");
		ui_interface->addVerticalBargraph("v7", &fVbargraph6, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph7, "nomidi", "no");
		ui_interface->addVerticalBargraph("v8", &fVbargraph7, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->declare(&fVbargraph8, "nomidi", "no");
		ui_interface->addVerticalBargraph("v9", &fVbargraph8, FAUSTFLOAT(-7e+01), FAUSTFLOAT(5.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider0));
		double fSlow1 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider1));
		double fSlow2 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider2));
		double fSlow3 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider3));
		double fSlow4 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider4));
		double fSlow5 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider5));
		double fSlow6 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider6));
		double fSlow7 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider7));
		double fSlow8 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider8));
		double fSlow9 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider9));
		double fSlow10 = 0.0010000000000000009 * std::pow(1e+01, 0.05 * static_cast<double>(fVslider10));
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			int iTemp0 = iRec1[1] < 4096;
			double fTemp1 = static_cast<double>(input0[i0]);
			fVec0[0] = fTemp1;
			fRec22[0] = -(fConst73 * (fConst72 * fRec22[1] - (fTemp1 + fVec0[1])));
			fRec21[0] = fRec22[0] - fConst71 * (fConst69 * fRec21[2] + fConst67 * fRec21[1]);
			double fTemp2 = fRec21[2] + fRec21[0] + 2.0 * fRec21[1];
			fVec1[0] = fTemp2;
			fRec20[0] = -(fConst76 * (fConst74 * fRec20[1] - fConst71 * (fTemp2 + fVec1[1])));
			fRec19[0] = fRec20[0] - fConst64 * (fConst62 * fRec19[2] + fConst60 * fRec19[1]);
			double fTemp3 = fRec19[2] + fRec19[0] + 2.0 * fRec19[1];
			fVec2[0] = fTemp3;
			fRec18[0] = -(fConst79 * (fConst77 * fRec18[1] - fConst64 * (fTemp3 + fVec2[1])));
			fRec17[0] = fRec18[0] - fConst57 * (fConst55 * fRec17[2] + fConst53 * fRec17[1]);
			double fTemp4 = fRec17[2] + fRec17[0] + 2.0 * fRec17[1];
			fVec3[0] = fTemp4;
			fRec16[0] = -(fConst82 * (fConst80 * fRec16[1] - fConst57 * (fTemp4 + fVec3[1])));
			fRec15[0] = fRec16[0] - fConst50 * (fConst48 * fRec15[2] + fConst46 * fRec15[1]);
			double fTemp5 = fRec15[2] + fRec15[0] + 2.0 * fRec15[1];
			fVec4[0] = fTemp5;
			fRec14[0] = -(fConst85 * (fConst83 * fRec14[1] - fConst50 * (fTemp5 + fVec4[1])));
			fRec13[0] = fRec14[0] - fConst43 * (fConst41 * fRec13[2] + fConst39 * fRec13[1]);
			double fTemp6 = fRec13[2] + fRec13[0] + 2.0 * fRec13[1];
			fVec5[0] = fTemp6;
			fRec12[0] = -(fConst88 * (fConst86 * fRec12[1] - fConst43 * (fTemp6 + fVec5[1])));
			fRec11[0] = fRec12[0] - fConst36 * (fConst34 * fRec11[2] + fConst32 * fRec11[1]);
			double fTemp7 = fRec11[2] + fRec11[0] + 2.0 * fRec11[1];
			fVec6[0] = fTemp7;
			fRec10[0] = -(fConst91 * (fConst89 * fRec10[1] - fConst36 * (fTemp7 + fVec6[1])));
			fRec9[0] = fRec10[0] - fConst29 * (fConst27 * fRec9[2] + fConst25 * fRec9[1]);
			double fTemp8 = fRec9[2] + fRec9[0] + 2.0 * fRec9[1];
			fVec7[0] = fTemp8;
			fRec8[0] = -(fConst94 * (fConst92 * fRec8[1] - fConst29 * (fTemp8 + fVec7[1])));
			fRec7[0] = fRec8[0] - fConst22 * (fConst20 * fRec7[2] + fConst18 * fRec7[1]);
			double fTemp9 = fRec7[2] + fRec7[0] + 2.0 * fRec7[1];
			fVec8[0] = fTemp9;
			fRec6[0] = -(fConst97 * (fConst95 * fRec6[1] - fConst22 * (fTemp9 + fVec8[1])));
			fRec5[0] = fRec6[0] - fConst15 * (fConst13 * fRec5[2] + fConst11 * fRec5[1]);
			double fTemp10 = fRec5[2] + fRec5[0] + 2.0 * fRec5[1];
			fVec9[0] = fTemp10;
			fRec4[0] = -(fConst100 * (fConst98 * fRec4[1] - fConst15 * (fTemp10 + fVec9[1])));
			fRec3[0] = fRec4[0] - fConst8 * (fConst6 * fRec3[2] + fConst4 * fRec3[1]);
			fRec23[0] = fSlow0 + 0.999 * fRec23[1];
			double fTemp11 = fConst8 * fRec23[0] * (fRec3[2] + fRec3[0] + 2.0 * fRec3[1]);
			double fTemp12 = std::max<double>(fConst1, std::fabs(fTemp11));
			fRec0[0] = ((iTemp0) ? std::max<double>(fRec0[1], fTemp12) : fTemp12);
			iRec1[0] = ((iTemp0) ? faust_wrap_add(iRec1[1], 1) : 1);
			fRec2[0] = ((iTemp0) ? fRec2[1] : fRec0[1]);
			fVbargraph0 = static_cast<FAUSTFLOAT>(fRec2[0]);
			int iTemp13 = iRec25[1] < 4096;
			fRec28[0] = -(fConst100 * (fConst98 * fRec28[1] - fConst101 * (fTemp10 - fVec9[1])));
			fRec27[0] = fRec28[0] - fConst8 * (fConst6 * fRec27[2] + fConst4 * fRec27[1]);
			fRec29[0] = fSlow1 + 0.999 * fRec29[1];
			double fTemp14 = fConst102 * fRec29[0] * (fRec27[2] + (fRec27[0] - 2.0 * fRec27[1]));
			double fTemp15 = std::max<double>(fConst1, std::fabs(fTemp14));
			fRec24[0] = ((iTemp13) ? std::max<double>(fRec24[1], fTemp15) : fTemp15);
			iRec25[0] = ((iTemp13) ? faust_wrap_add(iRec25[1], 1) : 1);
			fRec26[0] = ((iTemp13) ? fRec26[1] : fRec24[1]);
			fVbargraph1 = static_cast<FAUSTFLOAT>(fRec26[0]);
			int iTemp16 = iRec31[1] < 4096;
			double fTemp17 = fConst4 * fRec33[1];
			fRec35[0] = -(fConst97 * (fConst95 * fRec35[1] - fConst105 * (fTemp9 - fVec8[1])));
			fRec34[0] = fRec35[0] - fConst15 * (fConst13 * fRec34[2] + fConst11 * fRec34[1]);
			fRec33[0] = fConst106 * (fRec34[2] + (fRec34[0] - 2.0 * fRec34[1])) - fConst104 * (fConst103 * fRec33[2] + fTemp17);
			fRec36[0] = fSlow2 + 0.999 * fRec36[1];
			double fTemp18 = fRec36[0] * (fRec33[2] + fConst104 * (fTemp17 + fConst103 * fRec33[0]));
			double fTemp19 = std::max<double>(fConst1, std::fabs(fTemp18));
			fRec30[0] = ((iTemp16) ? std::max<double>(fRec30[1], fTemp19) : fTemp19);
			iRec31[0] = ((iTemp16) ? faust_wrap_add(iRec31[1], 1) : 1);
			fRec32[0] = ((iTemp16) ? fRec32[1] : fRec30[1]);
			fVbargraph2 = static_cast<FAUSTFLOAT>(fRec32[0]);
			int iTemp20 = iRec38[1] < 4096;
			double fTemp21 = fConst4 * fRec40[1];
			double fTemp22 = fConst11 * fRec41[1];
			fRec43[0] = -(fConst94 * (fConst92 * fRec43[1] - fConst109 * (fTemp8 - fVec7[1])));
			fRec42[0] = fRec43[0] - fConst22 * (fConst20 * fRec42[2] + fConst18 * fRec42[1]);
			fRec41[0] = fConst110 * (fRec42[2] + (fRec42[0] - 2.0 * fRec42[1])) - fConst108 * (fConst107 * fRec41[2] + fTemp22);
			fRec40[0] = fRec41[2] + fConst108 * (fTemp22 + fConst107 * fRec41[0]) - fConst104 * (fConst103 * fRec40[2] + fTemp21);
			fRec44[0] = fSlow3 + 0.999 * fRec44[1];
			double fTemp23 = fRec44[0] * (fRec40[2] + fConst104 * (fTemp21 + fConst103 * fRec40[0]));
			double fTemp24 = std::max<double>(fConst1, std::fabs(fTemp23));
			fRec37[0] = ((iTemp20) ? std::max<double>(fRec37[1], fTemp24) : fTemp24);
			iRec38[0] = ((iTemp20) ? faust_wrap_add(iRec38[1], 1) : 1);
			fRec39[0] = ((iTemp20) ? fRec39[1] : fRec37[1]);
			fVbargraph3 = static_cast<FAUSTFLOAT>(fRec39[0]);
			int iTemp25 = iRec46[1] < 4096;
			double fTemp26 = fConst4 * fRec48[1];
			double fTemp27 = fConst11 * fRec49[1];
			double fTemp28 = fConst18 * fRec50[1];
			fRec52[0] = -(fConst91 * (fConst89 * fRec52[1] - fConst113 * (fTemp7 - fVec6[1])));
			fRec51[0] = fRec52[0] - fConst29 * (fConst27 * fRec51[2] + fConst25 * fRec51[1]);
			fRec50[0] = fConst114 * (fRec51[2] + (fRec51[0] - 2.0 * fRec51[1])) - fConst112 * (fConst111 * fRec50[2] + fTemp28);
			fRec49[0] = fRec50[2] + fConst112 * (fTemp28 + fConst111 * fRec50[0]) - fConst108 * (fConst107 * fRec49[2] + fTemp27);
			fRec48[0] = fRec49[2] + fConst108 * (fTemp27 + fConst107 * fRec49[0]) - fConst104 * (fConst103 * fRec48[2] + fTemp26);
			fRec53[0] = fSlow4 + 0.999 * fRec53[1];
			double fTemp29 = fRec53[0] * (fRec48[2] + fConst104 * (fTemp26 + fConst103 * fRec48[0]));
			double fTemp30 = std::max<double>(fConst1, std::fabs(fTemp29));
			fRec45[0] = ((iTemp25) ? std::max<double>(fRec45[1], fTemp30) : fTemp30);
			iRec46[0] = ((iTemp25) ? faust_wrap_add(iRec46[1], 1) : 1);
			fRec47[0] = ((iTemp25) ? fRec47[1] : fRec45[1]);
			fVbargraph4 = static_cast<FAUSTFLOAT>(fRec47[0]);
			int iTemp31 = iRec55[1] < 4096;
			double fTemp32 = fConst4 * fRec57[1];
			double fTemp33 = fConst11 * fRec58[1];
			double fTemp34 = fConst18 * fRec59[1];
			double fTemp35 = fConst25 * fRec60[1];
			fRec62[0] = -(fConst88 * (fConst86 * fRec62[1] - fConst117 * (fTemp6 - fVec5[1])));
			fRec61[0] = fRec62[0] - fConst36 * (fConst34 * fRec61[2] + fConst32 * fRec61[1]);
			fRec60[0] = fConst118 * (fRec61[2] + (fRec61[0] - 2.0 * fRec61[1])) - fConst116 * (fConst115 * fRec60[2] + fTemp35);
			fRec59[0] = fRec60[2] + fConst116 * (fTemp35 + fConst115 * fRec60[0]) - fConst112 * (fConst111 * fRec59[2] + fTemp34);
			fRec58[0] = fRec59[2] + fConst112 * (fTemp34 + fConst111 * fRec59[0]) - fConst108 * (fConst107 * fRec58[2] + fTemp33);
			fRec57[0] = fRec58[2] + fConst108 * (fTemp33 + fConst107 * fRec58[0]) - fConst104 * (fConst103 * fRec57[2] + fTemp32);
			fRec63[0] = fSlow5 + 0.999 * fRec63[1];
			double fTemp36 = fRec63[0] * (fRec57[2] + fConst104 * (fTemp32 + fConst103 * fRec57[0]));
			double fTemp37 = std::max<double>(fConst1, std::fabs(fTemp36));
			fRec54[0] = ((iTemp31) ? std::max<double>(fRec54[1], fTemp37) : fTemp37);
			iRec55[0] = ((iTemp31) ? faust_wrap_add(iRec55[1], 1) : 1);
			fRec56[0] = ((iTemp31) ? fRec56[1] : fRec54[1]);
			fVbargraph5 = static_cast<FAUSTFLOAT>(fRec56[0]);
			int iTemp38 = iRec65[1] < 4096;
			double fTemp39 = fConst4 * fRec67[1];
			double fTemp40 = fConst11 * fRec68[1];
			double fTemp41 = fConst18 * fRec69[1];
			double fTemp42 = fConst25 * fRec70[1];
			double fTemp43 = fConst32 * fRec71[1];
			fRec73[0] = -(fConst85 * (fConst83 * fRec73[1] - fConst121 * (fTemp5 - fVec4[1])));
			fRec72[0] = fRec73[0] - fConst43 * (fConst41 * fRec72[2] + fConst39 * fRec72[1]);
			fRec71[0] = fConst122 * (fRec72[2] + (fRec72[0] - 2.0 * fRec72[1])) - fConst120 * (fConst119 * fRec71[2] + fTemp43);
			fRec70[0] = fRec71[2] + fConst120 * (fTemp43 + fConst119 * fRec71[0]) - fConst116 * (fConst115 * fRec70[2] + fTemp42);
			fRec69[0] = fRec70[2] + fConst116 * (fTemp42 + fConst115 * fRec70[0]) - fConst112 * (fConst111 * fRec69[2] + fTemp41);
			fRec68[0] = fRec69[2] + fConst112 * (fTemp41 + fConst111 * fRec69[0]) - fConst108 * (fConst107 * fRec68[2] + fTemp40);
			fRec67[0] = fRec68[2] + fConst108 * (fTemp40 + fConst107 * fRec68[0]) - fConst104 * (fConst103 * fRec67[2] + fTemp39);
			fRec74[0] = fSlow6 + 0.999 * fRec74[1];
			double fTemp44 = fRec74[0] * (fRec67[2] + fConst104 * (fTemp39 + fConst103 * fRec67[0]));
			double fTemp45 = std::max<double>(fConst1, std::fabs(fTemp44));
			fRec64[0] = ((iTemp38) ? std::max<double>(fRec64[1], fTemp45) : fTemp45);
			iRec65[0] = ((iTemp38) ? faust_wrap_add(iRec65[1], 1) : 1);
			fRec66[0] = ((iTemp38) ? fRec66[1] : fRec64[1]);
			fVbargraph6 = static_cast<FAUSTFLOAT>(fRec66[0]);
			int iTemp46 = iRec76[1] < 4096;
			double fTemp47 = fConst4 * fRec78[1];
			double fTemp48 = fConst11 * fRec79[1];
			double fTemp49 = fConst18 * fRec80[1];
			double fTemp50 = fConst25 * fRec81[1];
			double fTemp51 = fConst32 * fRec82[1];
			double fTemp52 = fConst39 * fRec83[1];
			fRec85[0] = -(fConst82 * (fConst80 * fRec85[1] - fConst125 * (fTemp4 - fVec3[1])));
			fRec84[0] = fRec85[0] - fConst50 * (fConst48 * fRec84[2] + fConst46 * fRec84[1]);
			fRec83[0] = fConst126 * (fRec84[2] + (fRec84[0] - 2.0 * fRec84[1])) - fConst124 * (fConst123 * fRec83[2] + fTemp52);
			fRec82[0] = fRec83[2] + fConst124 * (fTemp52 + fConst123 * fRec83[0]) - fConst120 * (fConst119 * fRec82[2] + fTemp51);
			fRec81[0] = fRec82[2] + fConst120 * (fTemp51 + fConst119 * fRec82[0]) - fConst116 * (fConst115 * fRec81[2] + fTemp50);
			fRec80[0] = fRec81[2] + fConst116 * (fTemp50 + fConst115 * fRec81[0]) - fConst112 * (fConst111 * fRec80[2] + fTemp49);
			fRec79[0] = fRec80[2] + fConst112 * (fTemp49 + fConst111 * fRec80[0]) - fConst108 * (fConst107 * fRec79[2] + fTemp48);
			fRec78[0] = fRec79[2] + fConst108 * (fTemp48 + fConst107 * fRec79[0]) - fConst104 * (fConst103 * fRec78[2] + fTemp47);
			fRec86[0] = fSlow7 + 0.999 * fRec86[1];
			double fTemp53 = fRec86[0] * (fRec78[2] + fConst104 * (fTemp47 + fConst103 * fRec78[0]));
			double fTemp54 = std::max<double>(fConst1, std::fabs(fTemp53));
			fRec75[0] = ((iTemp46) ? std::max<double>(fRec75[1], fTemp54) : fTemp54);
			iRec76[0] = ((iTemp46) ? faust_wrap_add(iRec76[1], 1) : 1);
			fRec77[0] = ((iTemp46) ? fRec77[1] : fRec75[1]);
			fVbargraph7 = static_cast<FAUSTFLOAT>(fRec77[0]);
			int iTemp55 = iRec88[1] < 4096;
			double fTemp56 = fConst4 * fRec90[1];
			double fTemp57 = fConst11 * fRec91[1];
			double fTemp58 = fConst18 * fRec92[1];
			double fTemp59 = fConst25 * fRec93[1];
			double fTemp60 = fConst32 * fRec94[1];
			double fTemp61 = fConst39 * fRec95[1];
			double fTemp62 = fConst46 * fRec96[1];
			fRec98[0] = -(fConst79 * (fConst77 * fRec98[1] - fConst129 * (fTemp3 - fVec2[1])));
			fRec97[0] = fRec98[0] - fConst57 * (fConst55 * fRec97[2] + fConst53 * fRec97[1]);
			fRec96[0] = fConst130 * (fRec97[2] + (fRec97[0] - 2.0 * fRec97[1])) - fConst128 * (fConst127 * fRec96[2] + fTemp62);
			fRec95[0] = fRec96[2] + fConst128 * (fTemp62 + fConst127 * fRec96[0]) - fConst124 * (fConst123 * fRec95[2] + fTemp61);
			fRec94[0] = fRec95[2] + fConst124 * (fTemp61 + fConst123 * fRec95[0]) - fConst120 * (fConst119 * fRec94[2] + fTemp60);
			fRec93[0] = fRec94[2] + fConst120 * (fTemp60 + fConst119 * fRec94[0]) - fConst116 * (fConst115 * fRec93[2] + fTemp59);
			fRec92[0] = fRec93[2] + fConst116 * (fTemp59 + fConst115 * fRec93[0]) - fConst112 * (fConst111 * fRec92[2] + fTemp58);
			fRec91[0] = fRec92[2] + fConst112 * (fTemp58 + fConst111 * fRec92[0]) - fConst108 * (fConst107 * fRec91[2] + fTemp57);
			fRec90[0] = fRec91[2] + fConst108 * (fTemp57 + fConst107 * fRec91[0]) - fConst104 * (fConst103 * fRec90[2] + fTemp56);
			fRec99[0] = fSlow8 + 0.999 * fRec99[1];
			double fTemp63 = fRec99[0] * (fRec90[2] + fConst104 * (fTemp56 + fConst103 * fRec90[0]));
			double fTemp64 = std::max<double>(fConst1, std::fabs(fTemp63));
			fRec87[0] = ((iTemp55) ? std::max<double>(fRec87[1], fTemp64) : fTemp64);
			iRec88[0] = ((iTemp55) ? faust_wrap_add(iRec88[1], 1) : 1);
			fRec89[0] = ((iTemp55) ? fRec89[1] : fRec87[1]);
			fVbargraph8 = static_cast<FAUSTFLOAT>(fRec89[0]);
			int iTemp65 = iRec101[1] < 4096;
			double fTemp66 = fConst4 * fRec103[1];
			double fTemp67 = fConst11 * fRec104[1];
			double fTemp68 = fConst18 * fRec105[1];
			double fTemp69 = fConst25 * fRec106[1];
			double fTemp70 = fConst32 * fRec107[1];
			double fTemp71 = fConst39 * fRec108[1];
			double fTemp72 = fConst46 * fRec109[1];
			double fTemp73 = fConst53 * fRec110[1];
			fRec112[0] = -(fConst76 * (fConst74 * fRec112[1] - fConst133 * (fTemp2 - fVec1[1])));
			fRec111[0] = fRec112[0] - fConst64 * (fConst62 * fRec111[2] + fConst60 * fRec111[1]);
			fRec110[0] = fConst134 * (fRec111[2] + (fRec111[0] - 2.0 * fRec111[1])) - fConst132 * (fConst131 * fRec110[2] + fTemp73);
			fRec109[0] = fRec110[2] + fConst132 * (fTemp73 + fConst131 * fRec110[0]) - fConst128 * (fConst127 * fRec109[2] + fTemp72);
			fRec108[0] = fRec109[2] + fConst128 * (fTemp72 + fConst127 * fRec109[0]) - fConst124 * (fConst123 * fRec108[2] + fTemp71);
			fRec107[0] = fRec108[2] + fConst124 * (fTemp71 + fConst123 * fRec108[0]) - fConst120 * (fConst119 * fRec107[2] + fTemp70);
			fRec106[0] = fRec107[2] + fConst120 * (fTemp70 + fConst119 * fRec107[0]) - fConst116 * (fConst115 * fRec106[2] + fTemp69);
			fRec105[0] = fRec106[2] + fConst116 * (fTemp69 + fConst115 * fRec106[0]) - fConst112 * (fConst111 * fRec105[2] + fTemp68);
			fRec104[0] = fRec105[2] + fConst112 * (fTemp68 + fConst111 * fRec105[0]) - fConst108 * (fConst107 * fRec104[2] + fTemp67);
			fRec103[0] = fRec104[2] + fConst108 * (fTemp67 + fConst107 * fRec104[0]) - fConst104 * (fConst103 * fRec103[2] + fTemp66);
			fRec113[0] = fSlow9 + 0.999 * fRec113[1];
			double fTemp74 = fRec113[0] * (fRec103[2] + fConst104 * (fTemp66 + fConst103 * fRec103[0]));
			double fTemp75 = std::max<double>(fConst1, std::fabs(fTemp74));
			fRec100[0] = ((iTemp65) ? std::max<double>(fRec100[1], fTemp75) : fTemp75);
			iRec101[0] = ((iTemp65) ? faust_wrap_add(iRec101[1], 1) : 1);
			fRec102[0] = ((iTemp65) ? fRec102[1] : fRec100[1]);
			fVbargraph9 = static_cast<FAUSTFLOAT>(fRec102[0]);
			int iTemp76 = iRec115[1] < 4096;
			double fTemp77 = fConst4 * fRec117[1];
			double fTemp78 = fConst11 * fRec118[1];
			double fTemp79 = fConst18 * fRec119[1];
			double fTemp80 = fConst25 * fRec120[1];
			double fTemp81 = fConst32 * fRec121[1];
			double fTemp82 = fConst39 * fRec122[1];
			double fTemp83 = fConst46 * fRec123[1];
			double fTemp84 = fConst53 * fRec124[1];
			double fTemp85 = fConst60 * fRec125[1];
			fRec127[0] = -(fConst73 * (fConst72 * fRec127[1] - fConst68 * (fTemp1 - fVec0[1])));
			fRec126[0] = fRec127[0] - fConst71 * (fConst69 * fRec126[2] + fConst67 * fRec126[1]);
			fRec125[0] = fConst137 * (fRec126[2] + (fRec126[0] - 2.0 * fRec126[1])) - fConst136 * (fConst135 * fRec125[2] + fTemp85);
			fRec124[0] = fRec125[2] + fConst136 * (fTemp85 + fConst135 * fRec125[0]) - fConst132 * (fConst131 * fRec124[2] + fTemp84);
			fRec123[0] = fRec124[2] + fConst132 * (fTemp84 + fConst131 * fRec124[0]) - fConst128 * (fConst127 * fRec123[2] + fTemp83);
			fRec122[0] = fRec123[2] + fConst128 * (fTemp83 + fConst127 * fRec123[0]) - fConst124 * (fConst123 * fRec122[2] + fTemp82);
			fRec121[0] = fRec122[2] + fConst124 * (fTemp82 + fConst123 * fRec122[0]) - fConst120 * (fConst119 * fRec121[2] + fTemp81);
			fRec120[0] = fRec121[2] + fConst120 * (fTemp81 + fConst119 * fRec121[0]) - fConst116 * (fConst115 * fRec120[2] + fTemp80);
			fRec119[0] = fRec120[2] + fConst116 * (fTemp80 + fConst115 * fRec120[0]) - fConst112 * (fConst111 * fRec119[2] + fTemp79);
			fRec118[0] = fRec119[2] + fConst112 * (fTemp79 + fConst111 * fRec119[0]) - fConst108 * (fConst107 * fRec118[2] + fTemp78);
			fRec117[0] = fRec118[2] + fConst108 * (fTemp78 + fConst107 * fRec118[0]) - fConst104 * (fConst103 * fRec117[2] + fTemp77);
			fRec128[0] = fSlow10 + 0.999 * fRec128[1];
			double fTemp86 = fRec128[0] * (fRec117[2] + fConst104 * (fTemp77 + fConst103 * fRec117[0]));
			double fTemp87 = std::max<double>(fConst1, std::fabs(fTemp86));
			fRec114[0] = ((iTemp76) ? std::max<double>(fRec114[1], fTemp87) : fTemp87);
			iRec115[0] = ((iTemp76) ? faust_wrap_add(iRec115[1], 1) : 1);
			fRec116[0] = ((iTemp76) ? fRec116[1] : fRec114[1]);
			fVbargraph10 = static_cast<FAUSTFLOAT>(fRec116[0]);
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp86 + fTemp74 + fTemp63 + fTemp53 + fTemp44 + fTemp36 + fTemp29 + fTemp23 + fTemp18 + fTemp14 + fTemp11);
			fVec0[1] = fVec0[0];
			fRec22[1] = fRec22[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fVec1[1] = fVec1[0];
			fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fVec2[1] = fVec2[0];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fVec3[1] = fVec3[0];
			fRec16[1] = fRec16[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fVec4[1] = fVec4[0];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fVec5[1] = fVec5[0];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fVec6[1] = fVec6[0];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fVec7[1] = fVec7[0];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fVec8[1] = fVec8[0];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fVec9[1] = fVec9[0];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec23[1] = fRec23[0];
			fRec0[1] = fRec0[0];
			iRec1[1] = iRec1[0];
			fRec2[1] = fRec2[0];
			fRec28[1] = fRec28[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec29[1] = fRec29[0];
			fRec24[1] = fRec24[0];
			iRec25[1] = iRec25[0];
			fRec26[1] = fRec26[0];
			fRec35[1] = fRec35[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec36[1] = fRec36[0];
			fRec30[1] = fRec30[0];
			iRec31[1] = iRec31[0];
			fRec32[1] = fRec32[0];
			fRec43[1] = fRec43[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec44[1] = fRec44[0];
			fRec37[1] = fRec37[0];
			iRec38[1] = iRec38[0];
			fRec39[1] = fRec39[0];
			fRec52[1] = fRec52[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec53[1] = fRec53[0];
			fRec45[1] = fRec45[0];
			iRec46[1] = iRec46[0];
			fRec47[1] = fRec47[0];
			fRec62[1] = fRec62[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec63[1] = fRec63[0];
			fRec54[1] = fRec54[0];
			iRec55[1] = iRec55[0];
			fRec56[1] = fRec56[0];
			fRec73[1] = fRec73[0];
			fRec72[2] = fRec72[1];
			fRec72[1] = fRec72[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec69[2] = fRec69[1];
			fRec69[1] = fRec69[0];
			fRec68[2] = fRec68[1];
			fRec68[1] = fRec68[0];
			fRec67[2] = fRec67[1];
			fRec67[1] = fRec67[0];
			fRec74[1] = fRec74[0];
			fRec64[1] = fRec64[0];
			iRec65[1] = iRec65[0];
			fRec66[1] = fRec66[0];
			fRec85[1] = fRec85[0];
			fRec84[2] = fRec84[1];
			fRec84[1] = fRec84[0];
			fRec83[2] = fRec83[1];
			fRec83[1] = fRec83[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			fRec80[2] = fRec80[1];
			fRec80[1] = fRec80[0];
			fRec79[2] = fRec79[1];
			fRec79[1] = fRec79[0];
			fRec78[2] = fRec78[1];
			fRec78[1] = fRec78[0];
			fRec86[1] = fRec86[0];
			fRec75[1] = fRec75[0];
			iRec76[1] = iRec76[0];
			fRec77[1] = fRec77[0];
			fRec98[1] = fRec98[0];
			fRec97[2] = fRec97[1];
			fRec97[1] = fRec97[0];
			fRec96[2] = fRec96[1];
			fRec96[1] = fRec96[0];
			fRec95[2] = fRec95[1];
			fRec95[1] = fRec95[0];
			fRec94[2] = fRec94[1];
			fRec94[1] = fRec94[0];
			fRec93[2] = fRec93[1];
			fRec93[1] = fRec93[0];
			fRec92[2] = fRec92[1];
			fRec92[1] = fRec92[0];
			fRec91[2] = fRec91[1];
			fRec91[1] = fRec91[0];
			fRec90[2] = fRec90[1];
			fRec90[1] = fRec90[0];
			fRec99[1] = fRec99[0];
			fRec87[1] = fRec87[0];
			iRec88[1] = iRec88[0];
			fRec89[1] = fRec89[0];
			fRec112[1] = fRec112[0];
			fRec111[2] = fRec111[1];
			fRec111[1] = fRec111[0];
			fRec110[2] = fRec110[1];
			fRec110[1] = fRec110[0];
			fRec109[2] = fRec109[1];
			fRec109[1] = fRec109[0];
			fRec108[2] = fRec108[1];
			fRec108[1] = fRec108[0];
			fRec107[2] = fRec107[1];
			fRec107[1] = fRec107[0];
			fRec106[2] = fRec106[1];
			fRec106[1] = fRec106[0];
			fRec105[2] = fRec105[1];
			fRec105[1] = fRec105[0];
			fRec104[2] = fRec104[1];
			fRec104[1] = fRec104[0];
			fRec103[2] = fRec103[1];
			fRec103[1] = fRec103[0];
			fRec113[1] = fRec113[0];
			fRec100[1] = fRec100[0];
			iRec101[1] = iRec101[0];
			fRec102[1] = fRec102[0];
			fRec127[1] = fRec127[0];
			fRec126[2] = fRec126[1];
			fRec126[1] = fRec126[0];
			fRec125[2] = fRec125[1];
			fRec125[1] = fRec125[0];
			fRec124[2] = fRec124[1];
			fRec124[1] = fRec124[0];
			fRec123[2] = fRec123[1];
			fRec123[1] = fRec123[0];
			fRec122[2] = fRec122[1];
			fRec122[1] = fRec122[0];
			fRec121[2] = fRec121[1];
			fRec121[1] = fRec121[0];
			fRec120[2] = fRec120[1];
			fRec120[1] = fRec120[0];
			fRec119[2] = fRec119[1];
			fRec119[1] = fRec119[0];
			fRec118[2] = fRec118[1];
			fRec118[1] = fRec118[0];
			fRec117[2] = fRec117[1];
			fRec117[1] = fRec117[0];
			fRec128[1] = fRec128[0];
			fRec114[1] = fRec114[0];
			iRec115[1] = iRec115[0];
			fRec116[1] = fRec116[0];
		}
	}

};

#endif
