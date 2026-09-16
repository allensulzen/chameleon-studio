/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "Fat Furry Freak"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFfreak -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxFfreak_H__
#define  __GxFfreak_H__

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
#define FAUSTCLASS GxFfreak
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

static double GxFfreak_faustpower2_f(double value) {
	return value * value;
}
static double GxFfreak_faustpower3_f(double value) {
	return value * value * value;
}
static double GxFfreak_faustpower4_f(double value) {
	return value * value * value * value;
}

class GxFfreak : public chdsp {
	
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
	FAUSTFLOAT fVslider1;
	double fRec1[2];
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
	FAUSTFLOAT fVslider2;
	double fRec2[2];
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
	double fConst72;
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fConst77;
	double fConst78;
	double fConst79;
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fConst86;
	double fConst87;
	double fConst88;
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fConst93;
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fConst114;
	double fConst115;
	double fRec3[6];
	double fConst116;
	double fConst117;
	double fConst118;
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fConst123;
	double fConst124;
	double fConst125;
	double fConst126;
	double fConst127;
	double fConst128;
	double fConst129;
	double fConst130;
	double fConst131;
	double fConst132;
	double fConst133;
	double fConst134;
	double fConst135;
	double fConst136;
	double fConst137;
	double fConst138;
	double fConst139;
	double fConst140;
	double fConst141;
	double fConst142;
	double fConst143;
	double fConst144;
	double fConst145;
	double fConst146;
	double fConst147;
	double fConst148;
	double fConst149;
	double fConst150;
	double fConst151;
	double fConst152;
	double fConst153;
	double fConst154;
	double fConst155;
	double fConst156;
	double fConst157;
	double fConst158;
	double fConst159;
	double fConst160;
	double fConst161;
	double fConst162;
	double fConst163;
	double fConst164;
	double fConst165;
	double fConst166;
	double fConst167;
	double fConst168;
	double fConst169;
	double fConst170;
	double fConst171;
	FAUSTFLOAT fVslider3;
	double fRec4[2];
	
 public:
	GxFfreak() {
	}
	
	GxFfreak(const GxFfreak&) = default;
	
	virtual ~GxFfreak() = default;
	
	GxFfreak& operator=(const GxFfreak&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "Fuzz");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxFfreak -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("description", "Extreme Bass Fuzz Monster");
		m->declare("drywetbox", "true");
		m->declare("filename", "gx-ffreak.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.9.0");
		m->declare("id", "ffreak");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "Fat Furry Freak");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("shortname", "Fat FFreak");
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
		fConst1 = GxFfreak_faustpower2_f(fConst0);
		fConst2 = 5.5846598379774e-24 * fConst0;
		fConst3 = (fConst0 * (fConst0 * (fConst2 + 3.42119219586653e-20) + 3.19454127568422e-17) + 2.62717307381708e-15) * fConst1;
		fConst4 = 5.71839588129828e-24 * fConst0;
		fConst5 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-3.49001694087958e-20 - fConst4) + -3.20489931550843e-17) + -2.65988017960028e-15) + -2.62717307381708e-15);
		fConst6 = 7.85412319843037e-24 * fConst0;
		fConst7 = fConst1 * (fConst0 * (fConst0 * (-7.55784595381368e-20 - fConst6) + -7.35486357301917e-17) + -3.92585764869989e-15);
		fConst8 = 8.04220615975415e-24 * fConst0;
		fConst9 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst8 + 7.72040670186403e-20) + 7.37353569889037e-17) + 4.00054450346227e-15) + 3.92585764869989e-15);
		fConst10 = 6.54379653368279e-24 * fConst0;
		fConst11 = fConst0 * (fConst0 * (fConst0 * (fConst10 + 5.8178250366366e-20) + 1.85568523263077e-17) + 1.66102929456909e-16) + 5.00381548719697e-17;
		fConst12 = 6.70053233478593e-24 * fConst0;
		fConst13 = fConst0 * (fConst0 * (fConst0 * (-5.95782688271891e-20 - fConst12) + -1.90595008624394e-17) + -1.88638248347695e-16) + -2.17339588935373e-16;
		fConst14 = 4.65295447579144e-24 * fConst0;
		fConst15 = fConst1 * (fConst0 * (fConst0 * (-2.3734396603456e-20 - fConst14) + -2.32762902199933e-18) + -1.88310920685508e-17);
		fConst16 = 4.76440117855883e-24 * fConst0;
		fConst17 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst16 + 2.43075314241076e-20) + 2.40711435730575e-18) + 2.16097599157672e-17) + 1.88310920685508e-17);
		fConst18 = fConst1 * (fConst0 * (fConst0 * (fConst10 + 5.62612870500991e-20) + 3.66325429672487e-18) + 2.81398235873665e-17);
		fConst19 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-5.76153907610497e-20 - fConst12) + -3.80725717138185e-18) + -3.24770777204501e-17) + -2.81398235873665e-17);
		fConst20 = fConst0 * (fConst0 * (fConst0 * (-7.78792746651557e-20 - fConst6) + -9.37831383212842e-17) + -2.2395439003671e-14) + -6.9809489892874e-15;
		fConst21 = fConst0 * (fConst0 * (fConst0 * (fConst8 + 7.95599798455062e-20) + 9.44004344622607e-17) + 2.24958749395835e-14) + 2.93784119708285e-14;
		fConst22 = 1.87753470001801e-18 * fConst0;
		fConst23 = GxFfreak_faustpower3_f(fConst0);
		fConst24 = fConst23 * (1.56079959618215e-14 - fConst22);
		fConst25 = 2.70062186191725e-18 * fConst0;
		fConst26 = fConst1 * (fConst0 * (fConst25 + -2.24522189930002e-14) + 1.56079959618215e-14);
		fConst27 = 2.79019064029167e-21 * fConst0;
		fConst28 = GxFfreak_faustpower4_f(fConst0);
		fConst29 = fConst28 * (fConst27 + -1.39597416617563e-17);
		fConst30 = 4.01337447559094e-21 * fConst0;
		fConst31 = fConst23 * (fConst0 * (2.00823037773104e-17 - fConst30) + -1.39597416617563e-17);
		fConst32 = 2.31663605170274e-21 * fConst0;
		fConst33 = fConst28 * (1.15904771305164e-17 - fConst32);
		fConst34 = 3.33595591445214e-21 * fConst0;
		fConst35 = fConst23 * (fConst0 * (fConst34 + -1.66926037039962e-17) + 1.15904771305164e-17);
		fConst36 = 1.55887720056646e-18 * fConst0;
		fConst37 = fConst23 * (fConst36 + -1.29589876827223e-14);
		fConst38 = 2.24478316881583e-18 * fConst0;
		fConst39 = fConst1 * (fConst0 * (1.86625011403217e-14 - fConst38) + -1.29589876827223e-14);
		fConst40 = fConst1 * (fConst0 * (fConst0 * (3.42119219586653e-20 - fConst2) + -3.19454127568422e-17) + 2.62717307381708e-15);
		fConst41 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst4 + -3.49001694087958e-20) + 3.20489931550843e-17) + -2.65988017960028e-15) + 2.62717307381708e-15);
		fConst42 = fConst1 * (fConst0 * (fConst0 * (fConst6 + -7.55784595381368e-20) + 7.35486357301917e-17) + -3.92585764869989e-15);
		fConst43 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (7.72040670186403e-20 - fConst8) + -7.37353569889037e-17) + 4.00054450346227e-15) + -3.92585764869989e-15);
		fConst44 = fConst0 * (fConst0 * (fConst0 * (5.8178250366366e-20 - fConst10) + -1.85568523263077e-17) + 1.66102929456909e-16) + -5.00381548719697e-17;
		fConst45 = fConst0 * (fConst0 * (fConst0 * (fConst12 + -5.95782688271891e-20) + 1.90595008624394e-17) + -1.88638248347695e-16) + 2.17339588935373e-16;
		fConst46 = fConst1 * (fConst0 * (fConst0 * (fConst14 + -2.3734396603456e-20) + 2.32762902199933e-18) + -1.88310920685508e-17);
		fConst47 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (2.43075314241076e-20 - fConst16) + -2.40711435730575e-18) + 2.16097599157672e-17) + -1.88310920685508e-17);
		fConst48 = fConst1 * (fConst0 * (fConst0 * (5.62612870500991e-20 - fConst10) + -3.66325429672487e-18) + 2.81398235873665e-17);
		fConst49 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst12 + -5.76153907610497e-20) + 3.80725717138185e-18) + -3.24770777204501e-17) + 2.81398235873665e-17);
		fConst50 = fConst0 * (fConst0 * (fConst0 * (fConst6 + -7.78792746651557e-20) + 9.37831383212842e-17) + -2.2395439003671e-14) + 6.9809489892874e-15;
		fConst51 = fConst0 * (fConst0 * (fConst0 * (7.95599798455062e-20 - fConst8) + -9.44004344622607e-17) + 2.24958749395835e-14) + -2.93784119708285e-14;
		fConst52 = 2.7923299189887e-23 * fConst0;
		fConst53 = fConst1 * (fConst0 * (fConst0 * (fConst52 + -1.02635765875996e-19) + 3.19454127568422e-17) + 2.62717307381708e-15);
		fConst54 = 2.85919794064914e-23 * fConst0;
		fConst55 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (1.04700508226387e-19 - fConst54) + -3.20489931550843e-17) + -2.65988017960028e-15) + 7.88151922145125e-15);
		fConst56 = 3.92706159921519e-23 * fConst0;
		fConst57 = fConst1 * (fConst0 * (fConst0 * (2.2673537861441e-19 - fConst56) + -7.35486357301917e-17) + -3.92585764869989e-15);
		fConst58 = 4.02110307987707e-23 * fConst0;
		fConst59 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst58 + -2.31612201055921e-19) + 7.37353569889037e-17) + 4.00054450346227e-15) + -1.17775729460997e-14);
		fConst60 = 3.27189826684139e-23 * fConst0;
		fConst61 = fConst0 * (fConst0 * (fConst0 * (fConst60 + -1.74534751099098e-19) + 1.85568523263077e-17) + 1.66102929456909e-16) + -1.50114464615909e-16;
		fConst62 = 3.35026616739297e-23 * fConst0;
		fConst63 = fConst0 * (fConst0 * (fConst0 * (1.78734806481567e-19 - fConst62) + -1.90595008624394e-17) + -1.88638248347695e-16) + 6.52018766806119e-16;
		fConst64 = 2.32647723789572e-23 * fConst0;
		fConst65 = fConst1 * (fConst0 * (fConst0 * (7.1203189810368e-20 - fConst64) + -2.32762902199933e-18) + -1.88310920685508e-17);
		fConst66 = 2.38220058927942e-23 * fConst0;
		fConst67 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst66 + -7.29225942723227e-20) + 2.40711435730575e-18) + 2.16097599157672e-17) + -5.64932762056525e-17);
		fConst68 = fConst1 * (fConst0 * (fConst0 * (fConst60 + -1.68783861150297e-19) + 3.66325429672487e-18) + 2.81398235873665e-17);
		fConst69 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (1.72846172283149e-19 - fConst62) + -3.80725717138185e-18) + -3.24770777204501e-17) + 8.44194707620995e-17);
		fConst70 = fConst0 * (fConst0 * (fConst0 * (2.33637823995467e-19 - fConst56) + -9.37831383212842e-17) + -2.2395439003671e-14) + 2.09428469678622e-14;
		fConst71 = fConst0 * (fConst0 * (fConst0 * (fConst58 + -2.38679939536519e-19) + 9.44004344622607e-17) + 2.24958749395835e-14) + -8.81352359124856e-14;
		fConst72 = 5.5846598379774e-23 * fConst0;
		fConst73 = fConst1 * (fConst0 * (fConst0 * (6.84238439173306e-20 - fConst72) + 6.38908255136844e-17) + -5.25434614763417e-15);
		fConst74 = 5.71839588129828e-23 * fConst0;
		fConst75 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst74 + -6.98003388175915e-20) + -6.40979863101685e-17) + 5.31976035920056e-15) + 5.25434614763417e-15);
		fConst76 = 7.85412319843037e-23 * fConst0;
		fConst77 = fConst1 * (fConst0 * (fConst0 * (fConst76 + -1.51156919076274e-19) + -1.47097271460383e-16) + 7.85171529739978e-15);
		fConst78 = 8.04220615975415e-23 * fConst0;
		fConst79 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (1.54408134037281e-19 - fConst78) + 1.47470713977807e-16) + -8.00108900692453e-15) + -7.85171529739978e-15);
		fConst80 = 6.54379653368279e-23 * fConst0;
		fConst81 = fConst0 * (fConst0 * (fConst0 * (1.16356500732732e-19 - fConst80) + 3.71137046526153e-17) + -3.32205858913818e-16) + -1.00076309743939e-16;
		fConst82 = 6.70053233478593e-23 * fConst0;
		fConst83 = fConst0 * (fConst0 * (fConst0 * (fConst82 + -1.19156537654378e-19) + -3.81190017248788e-17) + 3.7727649669539e-16) + 4.34679177870746e-16;
		fConst84 = 4.65295447579144e-23 * fConst0;
		fConst85 = fConst1 * (fConst0 * (fConst0 * (fConst84 + -4.7468793206912e-20) + -4.65525804399867e-18) + 3.76621841371017e-17);
		fConst86 = 4.76440117855883e-23 * fConst0;
		fConst87 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (4.86150628482151e-20 - fConst86) + 4.8142287146115e-18) + -4.32195198315344e-17) + -3.76621841371017e-17);
		fConst88 = fConst1 * (fConst0 * (fConst0 * (1.12522574100198e-19 - fConst80) + 7.32650859344974e-18) + -5.6279647174733e-17);
		fConst89 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst82 + -1.15230781522099e-19) + -7.6145143427637e-18) + 6.49541554409002e-17) + 5.6279647174733e-17);
		fConst90 = fConst0 * (fConst0 * (fConst0 * (fConst76 + -1.55758549330311e-19) + -1.87566276642568e-16) + 4.4790878007342e-14) + 1.39618979785748e-14;
		fConst91 = fConst0 * (fConst0 * (fConst0 * (1.59119959691012e-19 - fConst78) + 1.88800868924521e-16) + -4.49917498791669e-14) + -5.87568239416571e-14;
		fConst92 = fConst1 * (fConst0 * (fConst0 * (fConst72 + 6.84238439173306e-20) + -6.38908255136844e-17) + -5.25434614763417e-15);
		fConst93 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-6.98003388175915e-20 - fConst74) + 6.40979863101685e-17) + 5.31976035920056e-15) + -5.25434614763417e-15);
		fConst94 = fConst1 * (fConst0 * (fConst0 * (-1.51156919076274e-19 - fConst76) + 1.47097271460383e-16) + 7.85171529739978e-15);
		fConst95 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst78 + 1.54408134037281e-19) + -1.47470713977807e-16) + -8.00108900692453e-15) + 7.85171529739978e-15);
		fConst96 = fConst0 * (fConst0 * (fConst0 * (fConst80 + 1.16356500732732e-19) + -3.71137046526153e-17) + -3.32205858913818e-16) + 1.00076309743939e-16;
		fConst97 = fConst0 * (fConst0 * (fConst0 * (-1.19156537654378e-19 - fConst82) + 3.81190017248788e-17) + 3.7727649669539e-16) + -4.34679177870746e-16;
		fConst98 = fConst1 * (fConst0 * (fConst0 * (-4.7468793206912e-20 - fConst84) + 4.65525804399867e-18) + 3.76621841371017e-17);
		fConst99 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst86 + 4.86150628482151e-20) + -4.8142287146115e-18) + -4.32195198315344e-17) + 3.76621841371017e-17);
		fConst100 = fConst1 * (fConst0 * (fConst0 * (fConst80 + 1.12522574100198e-19) + -7.32650859344974e-18) + -5.6279647174733e-17);
		fConst101 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-1.15230781522099e-19 - fConst82) + 7.6145143427637e-18) + 6.49541554409002e-17) + -5.6279647174733e-17);
		fConst102 = fConst0 * (fConst0 * (fConst0 * (-1.55758549330311e-19 - fConst76) + 1.87566276642568e-16) + 4.4790878007342e-14) + -1.39618979785748e-14;
		fConst103 = fConst0 * (fConst0 * (fConst0 * (fConst78 + 1.59119959691012e-19) + -1.88800868924521e-16) + -4.49917498791669e-14) + 5.87568239416571e-14;
		fConst104 = fConst1 * (fConst0 * (fConst0 * (-1.02635765875996e-19 - fConst52) + -3.19454127568422e-17) + 2.62717307381708e-15);
		fConst105 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst54 + 1.04700508226387e-19) + 3.20489931550843e-17) + -2.65988017960028e-15) + -7.88151922145125e-15);
		fConst106 = fConst1 * (fConst0 * (fConst0 * (fConst56 + 2.2673537861441e-19) + 7.35486357301917e-17) + -3.92585764869989e-15);
		fConst107 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-2.31612201055921e-19 - fConst58) + -7.37353569889037e-17) + 4.00054450346227e-15) + 1.17775729460997e-14);
		fConst108 = fConst0 * (fConst0 * (fConst0 * (-1.74534751099098e-19 - fConst60) + -1.85568523263077e-17) + 1.66102929456909e-16) + 1.50114464615909e-16;
		fConst109 = fConst0 * (fConst0 * (fConst0 * (fConst62 + 1.78734806481567e-19) + 1.90595008624394e-17) + -1.88638248347695e-16) + -6.52018766806119e-16;
		fConst110 = fConst1 * (fConst0 * (fConst0 * (fConst64 + 7.1203189810368e-20) + 2.32762902199933e-18) + -1.88310920685508e-17);
		fConst111 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-7.29225942723227e-20 - fConst66) + -2.40711435730575e-18) + 2.16097599157672e-17) + 5.64932762056525e-17);
		fConst112 = fConst1 * (fConst0 * (fConst0 * (-1.68783861150297e-19 - fConst60) + -3.66325429672487e-18) + 2.81398235873665e-17);
		fConst113 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst62 + 1.72846172283149e-19) + 3.80725717138185e-18) + -3.24770777204501e-17) + -8.44194707620995e-17);
		fConst114 = fConst0 * (fConst0 * (fConst0 * (fConst56 + 2.33637823995467e-19) + 9.37831383212842e-17) + -2.2395439003671e-14) + -2.09428469678622e-14;
		fConst115 = fConst0 * (fConst0 * (fConst0 * (-2.38679939536519e-19 - fConst58) + -9.44004344622607e-17) + 2.24958749395835e-14) + 8.81352359124856e-14;
		fConst116 = 5.63260410005403e-18 * fConst0;
		fConst117 = fConst23 * (fConst116 + -1.56079959618215e-14);
		fConst118 = 8.10186558575176e-18 * fConst0;
		fConst119 = fConst1 * (fConst0 * (2.24522189930002e-14 - fConst118) + 1.56079959618215e-14);
		fConst120 = 1.39509532014583e-20 * fConst0;
		fConst121 = fConst28 * (4.18792249852688e-17 - fConst120);
		fConst122 = 2.00668723779547e-20 * fConst0;
		fConst123 = fConst23 * (fConst0 * (fConst122 + -6.02469113319311e-17) + 1.39597416617563e-17);
		fConst124 = 1.15831802585137e-20 * fConst0;
		fConst125 = fConst28 * (fConst124 + -3.47714313915491e-17);
		fConst126 = 1.66797795722607e-20 * fConst0;
		fConst127 = fConst23 * (fConst0 * (5.00778111119886e-17 - fConst126) + -1.15904771305164e-17);
		fConst128 = 4.67663160169938e-18 * fConst0;
		fConst129 = fConst23 * (1.29589876827223e-14 - fConst128);
		fConst130 = 6.7343495064475e-18 * fConst0;
		fConst131 = fConst1 * (fConst0 * (fConst130 + -1.86625011403217e-14) + -1.29589876827223e-14);
		fConst132 = 3.75506940003602e-18 * fConst0;
		fConst133 = fConst23 * (-3.12159919236431e-14 - fConst132);
		fConst134 = 5.40124372383451e-18 * fConst0;
		fConst135 = fConst1 * (fConst0 * (fConst134 + 4.49044379860004e-14) + -3.12159919236431e-14);
		fConst136 = 2.79019064029167e-20 * fConst0;
		fConst137 = fConst28 * (fConst136 + -2.79194833235126e-17);
		fConst138 = 4.01337447559094e-20 * fConst0;
		fConst139 = fConst23 * (fConst0 * (4.01646075546207e-17 - fConst138) + 2.79194833235126e-17);
		fConst140 = 2.31663605170274e-20 * fConst0;
		fConst141 = fConst28 * (2.31809542610327e-17 - fConst140);
		fConst142 = 3.33595591445214e-20 * fConst0;
		fConst143 = fConst23 * (fConst0 * (fConst142 + -3.33852074079924e-17) + -2.31809542610327e-17);
		fConst144 = 3.11775440113292e-18 * fConst0;
		fConst145 = fConst23 * (fConst144 + 2.59179753654445e-14);
		fConst146 = 4.48956633763166e-18 * fConst0;
		fConst147 = fConst1 * (fConst0 * (-3.73250022806433e-14 - fConst146) + 2.59179753654445e-14);
		fConst148 = fConst23 * (3.12159919236431e-14 - fConst132);
		fConst149 = fConst1 * (fConst0 * (fConst134 + -4.49044379860004e-14) + -3.12159919236431e-14);
		fConst150 = fConst28 * (-2.79194833235126e-17 - fConst136);
		fConst151 = fConst23 * (fConst0 * (fConst138 + 4.01646075546207e-17) + -2.79194833235126e-17);
		fConst152 = fConst28 * (fConst140 + 2.31809542610327e-17);
		fConst153 = fConst23 * (fConst0 * (-3.33852074079924e-17 - fConst142) + 2.31809542610327e-17);
		fConst154 = fConst23 * (fConst144 + -2.59179753654445e-14);
		fConst155 = fConst1 * (fConst0 * (3.73250022806433e-14 - fConst146) + 2.59179753654445e-14);
		fConst156 = fConst23 * (fConst116 + 1.56079959618215e-14);
		fConst157 = fConst1 * (fConst0 * (-2.24522189930002e-14 - fConst118) + 1.56079959618215e-14);
		fConst158 = fConst28 * (fConst120 + 4.18792249852688e-17);
		fConst159 = fConst23 * (fConst0 * (-6.02469113319311e-17 - fConst122) + -1.39597416617563e-17);
		fConst160 = fConst28 * (-3.47714313915491e-17 - fConst124);
		fConst161 = fConst23 * (fConst0 * (fConst126 + 5.00778111119886e-17) + 1.15904771305164e-17);
		fConst162 = fConst23 * (-1.29589876827223e-14 - fConst128);
		fConst163 = fConst1 * (fConst0 * (fConst130 + 1.86625011403217e-14) + -1.29589876827223e-14);
		fConst164 = fConst23 * (-1.56079959618215e-14 - fConst22);
		fConst165 = fConst1 * (fConst0 * (fConst25 + 2.24522189930002e-14) + 1.56079959618215e-14);
		fConst166 = fConst28 * (-1.39597416617563e-17 - fConst27);
		fConst167 = fConst23 * (fConst0 * (fConst30 + 2.00823037773104e-17) + 1.39597416617563e-17);
		fConst168 = fConst28 * (fConst32 + 1.15904771305164e-17);
		fConst169 = fConst23 * (fConst0 * (-1.66926037039962e-17 - fConst34) + -1.15904771305164e-17);
		fConst170 = fConst23 * (fConst36 + 1.29589876827223e-14);
		fConst171 = fConst1 * (fConst0 * (-1.86625011403217e-14 - fConst38) + -1.29589876827223e-14);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(0.5);
		fVslider2 = static_cast<FAUSTFLOAT>(0.5);
		fVslider3 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec2[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 6; l3 = faust_wrap_add(l3, 1)) {
			fRec3[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec4[l4] = 0.0;
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
	
	virtual GxFfreak* clone() {
		return new GxFfreak(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Fat Furry Freak");
		ui_interface->declare(&fVslider0, "name", "Fuzz");
		ui_interface->addVerticalSlider("Fuzz", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider2, "name", "Gate");
		ui_interface->addVerticalSlider("Gate", &fVslider2, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider3, "name", "Level");
		ui_interface->addVerticalSlider("Level", &fVslider3, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider1, "name", "Tone");
		ui_interface->addVerticalSlider("Tone", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = 0.007000000000000006 * static_cast<double>(fVslider0);
		double fSlow1 = 0.007000000000000006 * static_cast<double>(fVslider1);
		double fSlow2 = 0.007000000000000006 * static_cast<double>(fVslider2);
		double fSlow3 = 0.0003500000000000003 * (static_cast<double>(fVslider3) + 0.01);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec0[0] = fSlow0 + 0.993 * fRec0[1];
			fRec1[0] = fSlow1 + 0.993 * fRec1[1];
			fRec2[0] = fSlow2 + 0.993 * fRec2[1];
			double fTemp0 = fConst0 * (fConst21 + fConst20 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst19 + fConst18 * fRec0[0] + fRec1[0] * (fConst17 + fConst15 * fRec0[0])) + fConst0 * (fConst13 + fConst11 * fRec0[0]) + -5.00381548719697e-17) + fRec1[0] * (fConst9 + fConst7 * fRec0[0] + fRec1[0] * (fConst5 + fConst3 * fRec0[0])) + 6.9809489892874e-15;
			fRec3[0] = static_cast<double>(input0[i0]) - (fRec3[1] * (fConst0 * (fConst115 + fConst114 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst113 + fConst112 * fRec0[0] + fRec1[0] * (fConst111 + fConst110 * fRec0[0])) + fConst0 * (fConst109 + fConst108 * fRec0[0]) + -2.50190774359849e-16) + fRec1[0] * (fConst107 + fConst106 * fRec0[0] + fRec1[0] * (fConst105 + fConst104 * fRec0[0])) + 3.4904744946437e-14) + fRec3[2] * (fConst0 * (fConst103 + fConst102 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst101 + fConst100 * fRec0[0] + fRec1[0] * (fConst99 + fConst98 * fRec0[0])) + fConst0 * (fConst97 + fConst96 * fRec0[0]) + -5.00381548719697e-16) + fRec1[0] * (fConst95 + fConst94 * fRec0[0] + fRec1[0] * (fConst93 + fConst92 * fRec0[0])) + 6.9809489892874e-14) + fRec3[3] * (fConst0 * (fConst91 + fConst90 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst89 + fConst88 * fRec0[0] + fRec1[0] * (fConst87 + fConst85 * fRec0[0])) + fConst0 * (fConst83 + fConst81 * fRec0[0]) + -5.00381548719697e-16) + fRec1[0] * (fConst79 + fConst77 * fRec0[0] + fRec1[0] * (fConst75 + fConst73 * fRec0[0])) + 6.9809489892874e-14) + fRec3[4] * (fConst0 * (fConst71 + fConst70 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst69 + fConst68 * fRec0[0] + fRec1[0] * (fConst67 + fConst65 * fRec0[0])) + fConst0 * (fConst63 + fConst61 * fRec0[0]) + -2.50190774359849e-16) + fRec1[0] * (fConst59 + fConst57 * fRec0[0] + fRec1[0] * (fConst55 + fConst53 * fRec0[0])) + 3.4904744946437e-14) + fRec3[5] * (fConst0 * (fConst51 + fConst50 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst49 + fConst48 * fRec0[0] + fRec1[0] * (fConst47 + fConst46 * fRec0[0])) + fConst0 * (fConst45 + fConst44 * fRec0[0]) + -5.00381548719697e-17) + fRec1[0] * (fConst43 + fConst42 * fRec0[0] + fRec1[0] * (fConst41 + fConst40 * fRec0[0])) + 6.9809489892874e-15)) / fTemp0;
			fRec4[0] = fSlow3 + 0.993 * fRec4[1];
			output0[i0] = static_cast<FAUSTFLOAT>(0.3183098861837907 * std::atan(fRec4[0] * (fRec3[0] * (fRec2[0] * (fConst171 + fConst170 * fRec0[0] + fRec1[0] * (fConst169 + fConst168 * fRec0[0])) + fRec1[0] * (fConst167 + fConst166 * fRec0[0]) + fConst165 + fConst164 * fRec0[0]) + fRec3[1] * (fRec2[0] * (fConst163 + fConst162 * fRec0[0] + fRec1[0] * (fConst161 + fConst160 * fRec0[0])) + fRec1[0] * (fConst159 + fConst158 * fRec0[0]) + fConst157 + fConst156 * fRec0[0]) + fRec3[2] * (fRec2[0] * (fConst155 + fConst154 * fRec0[0] + fRec1[0] * (fConst153 + fConst152 * fRec0[0])) + fRec1[0] * (fConst151 + fConst150 * fRec0[0]) + fConst149 + fConst148 * fRec0[0]) + fRec3[3] * (fRec2[0] * (fConst147 + fConst145 * fRec0[0] + fRec1[0] * (fConst143 + fConst141 * fRec0[0])) + fRec1[0] * (fConst139 + fConst137 * fRec0[0]) + fConst135 + fConst133 * fRec0[0]) + fRec3[4] * (fRec2[0] * (fConst131 + fConst129 * fRec0[0] + fRec1[0] * (fConst127 + fConst125 * fRec0[0])) + fRec1[0] * (fConst123 + fConst121 * fRec0[0]) + fConst119 + fConst117 * fRec0[0]) + fRec3[5] * (fRec2[0] * (fConst39 + fConst37 * fRec0[0] + fRec1[0] * (fConst35 + fConst33 * fRec0[0])) + fRec1[0] * (fConst31 + fConst29 * fRec0[0]) + fConst26 + fConst24 * fRec0[0])) / fTemp0));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			for (int j0 = 5; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec3[j0] = fRec3[faust_wrap_sub(j0, 1)];
			}
			fRec4[1] = fRec4[0];
		}
	}

};

#endif
