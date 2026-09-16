/* ------------------------------------------------------------
author: "Till Bovermann, Julian Parker"
license: "GPL-2.0-or-later"
name: "JPverb"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibJpverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __LibJpverb_H__
#define  __LibJpverb_H__

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
#define FAUSTCLASS LibJpverb
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

const static int iLibJpverbSIG0Wave0[2048] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,2441,2447,2459,2467,2473,2477,2503,2521,2531,2539,2543,2549,2551,2557,2579,2591,2593,2609,2617,2621,2633,2647,2657,2659,2663,2671,2677,2683,2687,2689,2693,2699,2707,2711,2713,2719,2729,2731,2741,2749,2753,2767,2777,2789,2791,2797,2801,2803,2819,2833,2837,2843,2851,2857,2861,2879,2887,2897,2903,2909,2917,2927,2939,2953,2957,2963,2969,2971,2999,3001,3011,3019,3023,3037,3041,3049,3061,3067,3079,3083,3089,3109,3119,3121,3137,3163,3167,3169,3181,3187,3191,3203,3209,3217,3221,3229,3251,3253,3257,3259,3271,3299,3301,3307,3313,3319,3323,3329,3331,3343,3347,3359,3361,3371,3373,3389,3391,3407,3413,3433,3449,3457,3461,3463,3467,3469,3491,3499,3511,3517,3527,3529,3533,3539,3541,3547,3557,3559,3571,3581,3583,3593,3607,3613,3617,3623,3631,3637,3643,3659,3671,3673,3677,3691,3697,3701,3709,3719,3727,3733,3739,3761,3767,3769,3779,3793,3797,3803,3821,3823,3833,3847,3851,3853,3863,3877,3881,3889,3907,3911,3917,3919,3923,3929,3931,3943,3947,3967,3989,4001,4003,4007,4013,4019,4021,4027,4049,4051,4057,4073,4079,4091,4093,4099,4111,4127,4129,4133,4139,4153,4157,4159,4177,4201,4211,4217,4219,4229,4231,4241,4243,4253,4259,4261,4271,4273,4283,4289,4297,4327,4337,4339,4349,4357,4363,4373,4391,4397,4409,4421,4423,4441,4447,4451,4457,4463,4481,4483,4493,4507,4513,4517,4519,4523,4547,4549,4561,4567,4583,4591,4597,4603,4621,4637,4639,4643,4649,4651,4657,4663,4673,4679,4691,4703,4721,4723,4729,4733,4751,4759,4783,4787,4789,4793,4799,4801,4813,4817,4831,4861,4871,4877,4889,4903,4909,4919,4931,4933,4937,4943,4951,4957,4967,4969,4973,4987,4993,4999,5003,5009,5011,5021,5023,5039,5051,5059,5077,5081,5087,5099,5101,5107,5113,5119,5147,5153,5167,5171,5179,5189,5197,5209,5227,5231,5233,5237,5261,5273,5279,5281,5297,5303,5309,5323,5333,5347,5351,5381,5387,5393,5399,5407,5413,5417,5419,5431,5437,5441,5443,5449,5471,5477,5479,5483,5501,5503,5507,5519,5521,5527,5531,5557,5563,5569,5573,5581,5591,5623,5639,5641,5647,5651,5653,5657,5659,5669,5683,5689,5693,5701,5711,5717,5737,5741,5743,5749,5779,5783,5791,5801,5807,5813,5821,5827,5839,5843,5849,5851,5857,5861,5867,5869,5879,5881,5897,5903,5923,5927,5939,5953,5981,5987,6007,6011,6029,6037,6043,6047,6053,6067,6073,6079,6089,6091,6101,6113,6121,6131,6133,6143,6151,6163,6173,6197,6199,6203,6211,6217,6221,6229,6247,6257,6263,6269,6271,6277,6287,6299,6301,6311,6317,6323,6329,6337,6343,6353,6359,6361,6367,6373,6379,6389,6397,6421,6427,6449,6451,6469,6473,6481,6491,6521,6529,6547,6551,6553,6563,6569,6571,6577,6581,6599,6607,6619,6637,6653,6659,6661,6673,6679,6689,6691,6701,6703,6709,6719,6733,6737,6761,6763,6779,6781,6791,6793,6803,6823,6827,6829,6833,6841,6857,6863,6869,6871,6883,6899,6907,6911,6917,6947,6949,6959,6961,6967,6971,6977,6983,6991,6997,7001,7013,7019,7027,7039,7043,7057,7069,7079,7103,7109,7121,7127,7129,7151,7159,7177,7187,7193,7207,7211,7213,7219,7229,7237,7243,7247,7253,7283,7297,7307,7309,7321,7331,7333,7349,7351,7369,7393,7411,7417,7433,7451,7457,7459,7477,7481,7487,7489,7499,7507,7517,7523,7529,7537,7541,7547,7549,7559,7561,7573,7577,7583,7589,7591,7603,7607,7621,7639,7643,7649,7669,7673,7681,7687,7691,7699,7703,7717,7723,7727,7741,7753,7757,7759,7789,7793,7817,7823,7829,7841,7853,7867,7873,7877,7879,7883,7901,7907,7919,7927,7933,7937,7949,7951,7963,7993,8009,8011,8017,8039,8053,8059,8069,8081,8087,8089,8093,8101,8111,8117,8123,8147,8161,8167,8171,8179,8191,8209,8219,8221,8231,8233,8237,8243,8263,8269,8273,8287,8291,8293,8297,8311,8317,8329,8353,8363,8369,8377,8387,8389,8419,8423,8429,8431,8443,8447,8461,8467,8501,8513,8521,8527,8537,8539,8543,8563,8573,8581,8597,8599,8609,8623,8627,8629,8641,8647,8663,8669,8677,8681,8689,8693,8699,8707,8713,8719,8731,8737,8741,8747,8753,8761,8779,8783,8803,8807,8819,8821,8831,8837,8839,8849,8861,8863,8867,8887,8893,8923,8929,8933,8941,8951,8963,8969,8971,8999,9001,9007,9011,9013,9029,9041,9043,9049,9059,9067,9091,9103,9109,9127,9133,9137,9151,9157,9161,9173,9181,9187,9199,9203,9209,9221,9227,9239,9241,9257,9277,9281,9283,9293,9311,9319,9323,9337,9341,9343,9349,9371,9377,9391,9397,9403,9413,9419,9421,9431,9433,9437,9439,9461,9463,9467,9473,9479,9491,9497,9511,9521,9533,9539,9547,9551,9587,9601,9613,9619,9623,9629,9631,9643,9649,9661,9677,9679,9689,9697,9719,9721,9733,9739,9743,9749,9767,9769,9781,9787,9791,9803,9811,9817,9829,9833,9839,9851,9857,9859,9871,9883,9887,9901,9907,9923,9929,9931,9941,9949,9967,9973,10007,10009,10037,10039,10061,10067,10069,10079,10091,10093,10099,10103,10111,10133,10139,10141,10151,10159,10163,10169,10177,10181,10193,10211,10223,10243,10247,10253,10259,10267,10271,10273,10289,10301,10303,10313,10321,10331,10333,10337,10343,10357,10369,10391,10399,10427,10429,10433,10453,10457,10459,10463,10477,10487,10499,10501,10513,10529,10531,10559,10567,10589,10597,10601,10607,10613,10627,10631,10639,10651,10657,10663,10667,10687,10691,10709,10711,10723,10729,10733,10739,10753,10771,10781,10789,10799,10831,10837,10847,10853,10859,10861,10867,10883,10889,10891,10903,10909,10937,10939,10949,10957,10973,10979,10987,10993,11003,11027,11047,11057,11059,11069,11071,11083,11087,11093,11113,11117,11119,11131,11149,11159,11161,11171,11173,11177,11197,11213,11239,11243,11251,11257,11261,11273,11279,11287,11299,11311,11317,11321,11329,11351,11353,11369,11383,11393,11399,11411,11423,11437,11443,11447,11467,11471,11483,11489,11491,11497,11503,11519,11527,11549,11551,11579,11587,11593,11597,11617,11621,11633,11657,11677,11681,11689,11699,11701,11717,11719,11731,11743,11777,11779,11783,11789,11801,11807,11813,11821,11827,11831,11833,11839,11863,11867,11887,11897,11903,11909,11923,11927,11933,11939,11941,11953,11959,11969,11971,11981,11987,12007,12011,12037,12041,12043,12049,12071,12073,12097,12101,12107,12109,12113,12119,12143,12149,12157,12161,12163,12197,12203,12211,12227,12239,12241,12251,12253,12263,12269,12277,12281,12289,12301,12323,12329,12343,12347,12373,12377,12379,12391,12401,12409,12413,12421,12433,12437,12451,12457,12473,12479,12487,12491,12497,12503,12511,12517,12527,12539,12541,12547,12553,12569,12577,12583,12589,12601,12611,12613,12619,12637,12641,12647,12653,12659,12671,12689,12697,12703,12713,12721,12739,12743,12757,12763,12781,12791,12799,12809,12821,12823,12829,12841,12853,12889,12893,12899,12907,12911,12917,12919,12923,12941,12953,12959,12967,12973,12979,12983,13001,13003,13007,13009,13033,13037,13043,13049,13063,13093,13099,13103,13109,13121,13127,13147,13151,13159,13163,13171,13177,13183,13187,13217,13219,13229,13241,13249,13259,13267,13291,13297,13309,13313,13327,13331,13337,13339,13367,13381,13397,13399,13411,13417,13421,13441,13451,13457,13463,13469,13477,13487,13499,13513,13523,13537,13553,13567,13577,13591,13597,13613,13619,13627,13633,13649,13669,13679,13681,13687,13691,13693,13697,13709,13711,13721,13723,13729,13751,13757,13759,13763,13781,13789,13799,13807,13829,13831,13841,13859,13873,13877,13879,13883,13901,13903,13907,13913,13921,13931,13933,13963,13967,13997,13999,14009,14011,14029,14033,14051,14057,14071,14081,14083,14087,14107,14143,14149,14153,14159,14173,14177,14197,14207,14221,14243,14249,14251,14281,14293,14303,14321,14323,14327,14341,14347,14369,14387,14389,14401,14407,14411,14419,14423,14431,14437,14447,14449,14461,14479,14489,14503,14519,14533,14537,14543,14549,14551,14557,14561,14563,14591,14593,14621,14627,14629,14633,14639,14653,14657,14669,14683,14699,14713,14717,14723,14731,14737,14741,14747,14753,14759,14767,14771,14779,14783,14797,14813,14821,14827,14831,14843,14851,14867,14869,14879,14887,14891,14897,14923,14929,14939,14947,14951,14957,14969,14983,15013,15017,15031,15053,15061,15073,15077,15083,15091,15101,15107,15121,15131,15137,15139,15149,15161,15173,15187,15193,15199,15217,15227,15233,15241,15259,15263,15269,15271,15277,15287,15289,15299,15307,15313,15319,15329,15331,15349,15359,15361,15373,15377,15383,15391,15401,15413,15427,15439,15443,15451,15461,15467,15473,15493,15497,15511,15527,15541,15551,15559,15569,15581,15583,15601,15607,15619,15629,15641,15643,15647,15649,15661,15667,15671,15679,15683,15727,15731,15733,15737,15739,15749,15761,15767,15773,15787,15791,15797,15803,15809,15817,15823,15859,15877,15881,15887,15889,15901,15907,15913,15919,15923,15937,15959,15971,15973,15991,16001,16007,16033,16057,16061,16063,16067,16069,16073,16087,16091,16097,16103,16111,16127,16139,16141,16183,16187,16189,16193,16217,16223,16229,16231,16249,16253,16267,16273,16301,16319,16333,16339,16349,16361,16363,16369,16381,16411,16417,16421,16427,16433,16447,16451,16453,16477,16481,16487,16493,16519,16529,16547,16553,16561,16567,16573,16603,16607,16619,16631,16633,16649,16651,16657,16661,16673,16691,16693,16699,16703,16729,16741,16747,16759,16763,16787,16811,16823,16829,16831,16843,16871,16879,16883,16889,16901,16903,16921,16927,16931,16937,16943,16963,16979,16981,16987,16993,17011,17021,17027,17029,17033,17041,17047,17053,17077,17093,17099,17107,17117,17123,17137,17159,17167,17183,17189,17191,17203,17207,17209,17231,17239,17257,17291,17293,17299,17317,17321,17327,17333,17341,17351,17359,17377,17383,17387,17389,17393,17401,17417,17419,17431,17443,17449,17467,17471,17477,17483,17489,17491,17497,17509,17519,17539,17551,17569,17573,17579,17581,17597,17599,17609,17623,17627,17657,17659,17669,17681,17683,17707,17713,17729,17737,17747,17749,17761,17783,17789,17791,17807,17827,17837,17839,17851,17863};
class LibJpverbSIG0 {
	
  private:
	
	int iLibJpverbSIG0Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsLibJpverbSIG0() {
		return 0;
	}
	int getNumOutputsLibJpverbSIG0() {
		return 1;
	}
	
	void instanceInitLibJpverbSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		iLibJpverbSIG0Wave0_idx = 0;
	}
	
	void fillLibJpverbSIG0(int count, int* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			table[i1] = iLibJpverbSIG0Wave0[iLibJpverbSIG0Wave0_idx];
			iLibJpverbSIG0Wave0_idx = (faust_wrap_add(1, iLibJpverbSIG0Wave0_idx)) % 2048;
		}
	}

};

static LibJpverbSIG0* newLibJpverbSIG0() { return (LibJpverbSIG0*)new LibJpverbSIG0(); }
static void deleteLibJpverbSIG0(LibJpverbSIG0* dsp) { delete dsp; }

static float LibJpverb_faustpower2_f(float value) {
	return value * value;
}
static int DSY_SDRAM_BSS itbl0LibJpverbSIG0[2048];

class LibJpverb : public chdsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec3[2];
	FAUSTFLOAT fHslider1;
	float fConst3;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fRec11[2];
	float fRec13[2];
	float fRec17[2];
	int IOTA0;
	float fVec1[16384];
	float fVec2[2];
	float fRec16[2];
	float fRec14[2];
	float fRec19[2];
	float fVec3[16384];
	float fVec4[2];
	float fRec18[2];
	float fRec15[2];
	float fRec23[2];
	float fVec5[16384];
	float fVec6[2];
	float fRec22[2];
	float fRec20[2];
	float fRec25[2];
	float fVec7[16384];
	float fVec8[2];
	float fRec24[2];
	float fRec21[2];
	float fRec29[2];
	float fVec9[16384];
	float fVec10[2];
	float fRec28[2];
	float fRec26[2];
	float fRec31[2];
	float fVec11[16384];
	float fVec12[2];
	float fRec30[2];
	float fRec27[2];
	float fRec35[2];
	float fVec13[16384];
	float fVec14[2];
	float fRec34[2];
	float fRec32[2];
	float fRec37[2];
	float fVec15[16384];
	float fVec16[2];
	float fRec36[2];
	float fRec33[2];
	float fRec41[2];
	float fVec17[16384];
	float fVec18[2];
	float fRec40[2];
	float fRec38[2];
	float fRec43[2];
	float fVec19[16384];
	float fVec20[2];
	float fRec42[2];
	float fRec39[2];
	float fVec21[1024];
	FAUSTFLOAT fHslider4;
	float fRec46[2];
	float fConst4;
	float fRec44[2];
	float fRec45[2];
	FAUSTFLOAT fHslider5;
	float fRec47[2];
	float fVec22[16384];
	float fVec23[2];
	float fRec12[2];
	float fRec51[2];
	float fRec53[2];
	float fVec24[1024];
	float fVec25[16384];
	float fVec26[2];
	float fRec52[2];
	float fVec27[16384];
	float fVec28[2];
	float fRec50[2];
	float fRec48[2];
	float fRec55[2];
	float fVec29[16384];
	float fVec30[2];
	float fRec54[2];
	float fRec49[2];
	float fRec59[2];
	float fVec31[16384];
	float fVec32[2];
	float fRec58[2];
	float fRec56[2];
	float fRec61[2];
	float fVec33[16384];
	float fVec34[2];
	float fRec60[2];
	float fRec57[2];
	float fRec65[2];
	float fVec35[16384];
	float fVec36[2];
	float fRec64[2];
	float fRec62[2];
	float fRec67[2];
	float fVec37[16384];
	float fVec38[2];
	float fRec66[2];
	float fRec63[2];
	float fRec71[2];
	float fVec39[16384];
	float fVec40[2];
	float fRec70[2];
	float fRec68[2];
	float fRec73[2];
	float fVec41[16384];
	float fVec42[2];
	float fRec72[2];
	float fRec69[2];
	float fRec77[2];
	float fVec43[16384];
	float fVec44[2];
	float fRec76[2];
	float fRec74[2];
	float fRec79[2];
	float fVec45[16384];
	float fVec46[2];
	float fRec78[2];
	float fRec75[2];
	float fVec47[16384];
	float fVec48[16384];
	float fVec49[2];
	float fRec10[2];
	float fRec9[2];
	float fRec8[3];
	float fRec7[3];
	float fVec50[2];
	float fRec6[2];
	float fRec5[3];
	float fRec4[3];
	FAUSTFLOAT fHslider6;
	float fRec80[2];
	float fRec83[2];
	float fRec82[3];
	float fRec81[3];
	FAUSTFLOAT fHslider7;
	float fRec84[2];
	float fRec88[2];
	float fRec87[3];
	float fRec86[3];
	float fRec85[3];
	FAUSTFLOAT fHslider8;
	float fRec89[2];
	FAUSTFLOAT fHslider9;
	float fVec51[1024];
	float fRec2[2];
	FAUSTFLOAT fHslider10;
	float fRec90[2];
	float fRec102[2];
	float fVec52[16384];
	float fVec53[16384];
	float fVec54[2];
	float fRec101[2];
	float fRec100[2];
	float fRec99[3];
	float fRec98[3];
	float fVec55[2];
	float fRec97[2];
	float fRec96[3];
	float fRec95[3];
	float fRec105[2];
	float fRec104[3];
	float fRec103[3];
	float fRec109[2];
	float fRec108[3];
	float fRec107[3];
	float fRec106[3];
	float fVec56[1024];
	float fRec94[2];
	float fVec57[16384];
	float fVec58[2];
	float fRec93[2];
	float fRec91[2];
	float fRec111[2];
	float fVec59[16384];
	float fVec60[2];
	float fRec110[2];
	float fRec92[2];
	float fVec61[16384];
	float fVec62[2];
	float fRec114[2];
	float fRec112[2];
	float fVec63[16384];
	float fVec64[2];
	float fRec115[2];
	float fRec113[2];
	float fVec65[16384];
	float fVec66[2];
	float fRec118[2];
	float fRec116[2];
	float fRec120[2];
	float fVec67[16384];
	float fVec68[2];
	float fRec119[2];
	float fRec117[2];
	float fRec124[2];
	float fVec69[16384];
	float fVec70[2];
	float fRec123[2];
	float fRec121[2];
	float fVec71[16384];
	float fVec72[2];
	float fRec125[2];
	float fRec122[2];
	float fRec0[2];
	float fRec1[2];
	FAUSTFLOAT fHslider11;
	float fRec126[2];
	
 public:
	LibJpverb() {
	}
	
	LibJpverb(const LibJpverb&) = default;
	
	virtual ~LibJpverb() = default;
	
	LibJpverb& operator=(const LibJpverb&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("author", "Till Bovermann, Julian Parker");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("category", "guitar");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn LibJpverb -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/fdelay1a:author", "Julius O. Smith III");
		m->declare("delays.lib/fdelay4:author", "Julius O. Smith III");
		m->declare("delays.lib/fdelayltv:author", "Julius O. Smith III");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("description", "Julian Parker's lush algorithmic reverb with modulation and 3-band decay");
		m->declare("family", "reverb");
		m->declare("filename", "lib-jpverb.dsp");
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
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "LicenseRef-STK-4.3");
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
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "JPverb");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.8.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/jpverb:author", "Julian Parker, bug fixes and minor interface changes by Till Bovermann");
		m->declare("reverbs.lib/jpverb:license", "MIT");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.5.1");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.7.0");
		m->declare("source", "grame-cncm/faustlibraries/reverbs.lib re.jpverb");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		LibJpverbSIG0* sig0 = newLibJpverbSIG0();
		sig0->instanceInitLibJpverbSIG0(sample_rate);
		sig0->fillLibJpverbSIG0(2048, itbl0LibJpverbSIG0);
		deleteLibJpverbSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 3.1415927f / fConst0;
		fConst4 = 6.2831855f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.2f);
		fHslider1 = static_cast<FAUSTFLOAT>(5e+02f);
		fHslider2 = static_cast<FAUSTFLOAT>(2e+03f);
		fHslider3 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider4 = static_cast<FAUSTFLOAT>(2.0f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.1f);
		fHslider6 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider7 = static_cast<FAUSTFLOAT>(1.0f);
		fHslider8 = static_cast<FAUSTFLOAT>(0.8f);
		fHslider9 = static_cast<FAUSTFLOAT>(2.0f);
		fHslider10 = static_cast<FAUSTFLOAT>(0.707f);
		fHslider11 = static_cast<FAUSTFLOAT>(0.35f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec11[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec13[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec17[l4] = 0.0f;
		}
		IOTA0 = 0;
		for (int l5 = 0; l5 < 16384; l5 = faust_wrap_add(l5, 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fRec16[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec14[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec19[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 16384; l10 = faust_wrap_add(l10, 1)) {
			fVec3[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fVec4[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec18[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec15[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec23[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 16384; l15 = faust_wrap_add(l15, 1)) {
			fVec5[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fVec6[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec22[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec20[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec25[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 16384; l20 = faust_wrap_add(l20, 1)) {
			fVec7[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fVec8[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fRec24[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec21[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec29[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 16384; l25 = faust_wrap_add(l25, 1)) {
			fVec9[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fVec10[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fRec28[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec26[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec31[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 16384; l30 = faust_wrap_add(l30, 1)) {
			fVec11[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fVec12[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec30[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec27[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec35[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 16384; l35 = faust_wrap_add(l35, 1)) {
			fVec13[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fVec14[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec34[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fRec32[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fRec37[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 16384; l40 = faust_wrap_add(l40, 1)) {
			fVec15[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fVec16[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			fRec36[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec33[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec41[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 16384; l45 = faust_wrap_add(l45, 1)) {
			fVec17[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fVec18[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fRec40[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec38[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec43[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 16384; l50 = faust_wrap_add(l50, 1)) {
			fVec19[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fVec20[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec42[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fRec39[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 1024; l54 = faust_wrap_add(l54, 1)) {
			fVec21[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			fRec46[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fRec44[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = faust_wrap_add(l57, 1)) {
			fRec45[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = faust_wrap_add(l58, 1)) {
			fRec47[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 16384; l59 = faust_wrap_add(l59, 1)) {
			fVec22[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = faust_wrap_add(l60, 1)) {
			fVec23[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = faust_wrap_add(l61, 1)) {
			fRec12[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			fRec51[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = faust_wrap_add(l63, 1)) {
			fRec53[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 1024; l64 = faust_wrap_add(l64, 1)) {
			fVec24[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 16384; l65 = faust_wrap_add(l65, 1)) {
			fVec25[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = faust_wrap_add(l66, 1)) {
			fVec26[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 2; l67 = faust_wrap_add(l67, 1)) {
			fRec52[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 16384; l68 = faust_wrap_add(l68, 1)) {
			fVec27[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 2; l69 = faust_wrap_add(l69, 1)) {
			fVec28[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2; l70 = faust_wrap_add(l70, 1)) {
			fRec50[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = faust_wrap_add(l71, 1)) {
			fRec48[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = faust_wrap_add(l72, 1)) {
			fRec55[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 16384; l73 = faust_wrap_add(l73, 1)) {
			fVec29[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 2; l74 = faust_wrap_add(l74, 1)) {
			fVec30[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 2; l75 = faust_wrap_add(l75, 1)) {
			fRec54[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 2; l76 = faust_wrap_add(l76, 1)) {
			fRec49[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 2; l77 = faust_wrap_add(l77, 1)) {
			fRec59[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 16384; l78 = faust_wrap_add(l78, 1)) {
			fVec31[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 2; l79 = faust_wrap_add(l79, 1)) {
			fVec32[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 2; l80 = faust_wrap_add(l80, 1)) {
			fRec58[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 2; l81 = faust_wrap_add(l81, 1)) {
			fRec56[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 2; l82 = faust_wrap_add(l82, 1)) {
			fRec61[l82] = 0.0f;
		}
		for (int l83 = 0; l83 < 16384; l83 = faust_wrap_add(l83, 1)) {
			fVec33[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 2; l84 = faust_wrap_add(l84, 1)) {
			fVec34[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 2; l85 = faust_wrap_add(l85, 1)) {
			fRec60[l85] = 0.0f;
		}
		for (int l86 = 0; l86 < 2; l86 = faust_wrap_add(l86, 1)) {
			fRec57[l86] = 0.0f;
		}
		for (int l87 = 0; l87 < 2; l87 = faust_wrap_add(l87, 1)) {
			fRec65[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 16384; l88 = faust_wrap_add(l88, 1)) {
			fVec35[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 2; l89 = faust_wrap_add(l89, 1)) {
			fVec36[l89] = 0.0f;
		}
		for (int l90 = 0; l90 < 2; l90 = faust_wrap_add(l90, 1)) {
			fRec64[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 2; l91 = faust_wrap_add(l91, 1)) {
			fRec62[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 2; l92 = faust_wrap_add(l92, 1)) {
			fRec67[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 16384; l93 = faust_wrap_add(l93, 1)) {
			fVec37[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 2; l94 = faust_wrap_add(l94, 1)) {
			fVec38[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 2; l95 = faust_wrap_add(l95, 1)) {
			fRec66[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 2; l96 = faust_wrap_add(l96, 1)) {
			fRec63[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 2; l97 = faust_wrap_add(l97, 1)) {
			fRec71[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 16384; l98 = faust_wrap_add(l98, 1)) {
			fVec39[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 2; l99 = faust_wrap_add(l99, 1)) {
			fVec40[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 2; l100 = faust_wrap_add(l100, 1)) {
			fRec70[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 2; l101 = faust_wrap_add(l101, 1)) {
			fRec68[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 2; l102 = faust_wrap_add(l102, 1)) {
			fRec73[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 16384; l103 = faust_wrap_add(l103, 1)) {
			fVec41[l103] = 0.0f;
		}
		for (int l104 = 0; l104 < 2; l104 = faust_wrap_add(l104, 1)) {
			fVec42[l104] = 0.0f;
		}
		for (int l105 = 0; l105 < 2; l105 = faust_wrap_add(l105, 1)) {
			fRec72[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 2; l106 = faust_wrap_add(l106, 1)) {
			fRec69[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 2; l107 = faust_wrap_add(l107, 1)) {
			fRec77[l107] = 0.0f;
		}
		for (int l108 = 0; l108 < 16384; l108 = faust_wrap_add(l108, 1)) {
			fVec43[l108] = 0.0f;
		}
		for (int l109 = 0; l109 < 2; l109 = faust_wrap_add(l109, 1)) {
			fVec44[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 2; l110 = faust_wrap_add(l110, 1)) {
			fRec76[l110] = 0.0f;
		}
		for (int l111 = 0; l111 < 2; l111 = faust_wrap_add(l111, 1)) {
			fRec74[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 2; l112 = faust_wrap_add(l112, 1)) {
			fRec79[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 16384; l113 = faust_wrap_add(l113, 1)) {
			fVec45[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 2; l114 = faust_wrap_add(l114, 1)) {
			fVec46[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 2; l115 = faust_wrap_add(l115, 1)) {
			fRec78[l115] = 0.0f;
		}
		for (int l116 = 0; l116 < 2; l116 = faust_wrap_add(l116, 1)) {
			fRec75[l116] = 0.0f;
		}
		for (int l117 = 0; l117 < 16384; l117 = faust_wrap_add(l117, 1)) {
			fVec47[l117] = 0.0f;
		}
		for (int l118 = 0; l118 < 16384; l118 = faust_wrap_add(l118, 1)) {
			fVec48[l118] = 0.0f;
		}
		for (int l119 = 0; l119 < 2; l119 = faust_wrap_add(l119, 1)) {
			fVec49[l119] = 0.0f;
		}
		for (int l120 = 0; l120 < 2; l120 = faust_wrap_add(l120, 1)) {
			fRec10[l120] = 0.0f;
		}
		for (int l121 = 0; l121 < 2; l121 = faust_wrap_add(l121, 1)) {
			fRec9[l121] = 0.0f;
		}
		for (int l122 = 0; l122 < 3; l122 = faust_wrap_add(l122, 1)) {
			fRec8[l122] = 0.0f;
		}
		for (int l123 = 0; l123 < 3; l123 = faust_wrap_add(l123, 1)) {
			fRec7[l123] = 0.0f;
		}
		for (int l124 = 0; l124 < 2; l124 = faust_wrap_add(l124, 1)) {
			fVec50[l124] = 0.0f;
		}
		for (int l125 = 0; l125 < 2; l125 = faust_wrap_add(l125, 1)) {
			fRec6[l125] = 0.0f;
		}
		for (int l126 = 0; l126 < 3; l126 = faust_wrap_add(l126, 1)) {
			fRec5[l126] = 0.0f;
		}
		for (int l127 = 0; l127 < 3; l127 = faust_wrap_add(l127, 1)) {
			fRec4[l127] = 0.0f;
		}
		for (int l128 = 0; l128 < 2; l128 = faust_wrap_add(l128, 1)) {
			fRec80[l128] = 0.0f;
		}
		for (int l129 = 0; l129 < 2; l129 = faust_wrap_add(l129, 1)) {
			fRec83[l129] = 0.0f;
		}
		for (int l130 = 0; l130 < 3; l130 = faust_wrap_add(l130, 1)) {
			fRec82[l130] = 0.0f;
		}
		for (int l131 = 0; l131 < 3; l131 = faust_wrap_add(l131, 1)) {
			fRec81[l131] = 0.0f;
		}
		for (int l132 = 0; l132 < 2; l132 = faust_wrap_add(l132, 1)) {
			fRec84[l132] = 0.0f;
		}
		for (int l133 = 0; l133 < 2; l133 = faust_wrap_add(l133, 1)) {
			fRec88[l133] = 0.0f;
		}
		for (int l134 = 0; l134 < 3; l134 = faust_wrap_add(l134, 1)) {
			fRec87[l134] = 0.0f;
		}
		for (int l135 = 0; l135 < 3; l135 = faust_wrap_add(l135, 1)) {
			fRec86[l135] = 0.0f;
		}
		for (int l136 = 0; l136 < 3; l136 = faust_wrap_add(l136, 1)) {
			fRec85[l136] = 0.0f;
		}
		for (int l137 = 0; l137 < 2; l137 = faust_wrap_add(l137, 1)) {
			fRec89[l137] = 0.0f;
		}
		for (int l138 = 0; l138 < 1024; l138 = faust_wrap_add(l138, 1)) {
			fVec51[l138] = 0.0f;
		}
		for (int l139 = 0; l139 < 2; l139 = faust_wrap_add(l139, 1)) {
			fRec2[l139] = 0.0f;
		}
		for (int l140 = 0; l140 < 2; l140 = faust_wrap_add(l140, 1)) {
			fRec90[l140] = 0.0f;
		}
		for (int l141 = 0; l141 < 2; l141 = faust_wrap_add(l141, 1)) {
			fRec102[l141] = 0.0f;
		}
		for (int l142 = 0; l142 < 16384; l142 = faust_wrap_add(l142, 1)) {
			fVec52[l142] = 0.0f;
		}
		for (int l143 = 0; l143 < 16384; l143 = faust_wrap_add(l143, 1)) {
			fVec53[l143] = 0.0f;
		}
		for (int l144 = 0; l144 < 2; l144 = faust_wrap_add(l144, 1)) {
			fVec54[l144] = 0.0f;
		}
		for (int l145 = 0; l145 < 2; l145 = faust_wrap_add(l145, 1)) {
			fRec101[l145] = 0.0f;
		}
		for (int l146 = 0; l146 < 2; l146 = faust_wrap_add(l146, 1)) {
			fRec100[l146] = 0.0f;
		}
		for (int l147 = 0; l147 < 3; l147 = faust_wrap_add(l147, 1)) {
			fRec99[l147] = 0.0f;
		}
		for (int l148 = 0; l148 < 3; l148 = faust_wrap_add(l148, 1)) {
			fRec98[l148] = 0.0f;
		}
		for (int l149 = 0; l149 < 2; l149 = faust_wrap_add(l149, 1)) {
			fVec55[l149] = 0.0f;
		}
		for (int l150 = 0; l150 < 2; l150 = faust_wrap_add(l150, 1)) {
			fRec97[l150] = 0.0f;
		}
		for (int l151 = 0; l151 < 3; l151 = faust_wrap_add(l151, 1)) {
			fRec96[l151] = 0.0f;
		}
		for (int l152 = 0; l152 < 3; l152 = faust_wrap_add(l152, 1)) {
			fRec95[l152] = 0.0f;
		}
		for (int l153 = 0; l153 < 2; l153 = faust_wrap_add(l153, 1)) {
			fRec105[l153] = 0.0f;
		}
		for (int l154 = 0; l154 < 3; l154 = faust_wrap_add(l154, 1)) {
			fRec104[l154] = 0.0f;
		}
		for (int l155 = 0; l155 < 3; l155 = faust_wrap_add(l155, 1)) {
			fRec103[l155] = 0.0f;
		}
		for (int l156 = 0; l156 < 2; l156 = faust_wrap_add(l156, 1)) {
			fRec109[l156] = 0.0f;
		}
		for (int l157 = 0; l157 < 3; l157 = faust_wrap_add(l157, 1)) {
			fRec108[l157] = 0.0f;
		}
		for (int l158 = 0; l158 < 3; l158 = faust_wrap_add(l158, 1)) {
			fRec107[l158] = 0.0f;
		}
		for (int l159 = 0; l159 < 3; l159 = faust_wrap_add(l159, 1)) {
			fRec106[l159] = 0.0f;
		}
		for (int l160 = 0; l160 < 1024; l160 = faust_wrap_add(l160, 1)) {
			fVec56[l160] = 0.0f;
		}
		for (int l161 = 0; l161 < 2; l161 = faust_wrap_add(l161, 1)) {
			fRec94[l161] = 0.0f;
		}
		for (int l162 = 0; l162 < 16384; l162 = faust_wrap_add(l162, 1)) {
			fVec57[l162] = 0.0f;
		}
		for (int l163 = 0; l163 < 2; l163 = faust_wrap_add(l163, 1)) {
			fVec58[l163] = 0.0f;
		}
		for (int l164 = 0; l164 < 2; l164 = faust_wrap_add(l164, 1)) {
			fRec93[l164] = 0.0f;
		}
		for (int l165 = 0; l165 < 2; l165 = faust_wrap_add(l165, 1)) {
			fRec91[l165] = 0.0f;
		}
		for (int l166 = 0; l166 < 2; l166 = faust_wrap_add(l166, 1)) {
			fRec111[l166] = 0.0f;
		}
		for (int l167 = 0; l167 < 16384; l167 = faust_wrap_add(l167, 1)) {
			fVec59[l167] = 0.0f;
		}
		for (int l168 = 0; l168 < 2; l168 = faust_wrap_add(l168, 1)) {
			fVec60[l168] = 0.0f;
		}
		for (int l169 = 0; l169 < 2; l169 = faust_wrap_add(l169, 1)) {
			fRec110[l169] = 0.0f;
		}
		for (int l170 = 0; l170 < 2; l170 = faust_wrap_add(l170, 1)) {
			fRec92[l170] = 0.0f;
		}
		for (int l171 = 0; l171 < 16384; l171 = faust_wrap_add(l171, 1)) {
			fVec61[l171] = 0.0f;
		}
		for (int l172 = 0; l172 < 2; l172 = faust_wrap_add(l172, 1)) {
			fVec62[l172] = 0.0f;
		}
		for (int l173 = 0; l173 < 2; l173 = faust_wrap_add(l173, 1)) {
			fRec114[l173] = 0.0f;
		}
		for (int l174 = 0; l174 < 2; l174 = faust_wrap_add(l174, 1)) {
			fRec112[l174] = 0.0f;
		}
		for (int l175 = 0; l175 < 16384; l175 = faust_wrap_add(l175, 1)) {
			fVec63[l175] = 0.0f;
		}
		for (int l176 = 0; l176 < 2; l176 = faust_wrap_add(l176, 1)) {
			fVec64[l176] = 0.0f;
		}
		for (int l177 = 0; l177 < 2; l177 = faust_wrap_add(l177, 1)) {
			fRec115[l177] = 0.0f;
		}
		for (int l178 = 0; l178 < 2; l178 = faust_wrap_add(l178, 1)) {
			fRec113[l178] = 0.0f;
		}
		for (int l179 = 0; l179 < 16384; l179 = faust_wrap_add(l179, 1)) {
			fVec65[l179] = 0.0f;
		}
		for (int l180 = 0; l180 < 2; l180 = faust_wrap_add(l180, 1)) {
			fVec66[l180] = 0.0f;
		}
		for (int l181 = 0; l181 < 2; l181 = faust_wrap_add(l181, 1)) {
			fRec118[l181] = 0.0f;
		}
		for (int l182 = 0; l182 < 2; l182 = faust_wrap_add(l182, 1)) {
			fRec116[l182] = 0.0f;
		}
		for (int l183 = 0; l183 < 2; l183 = faust_wrap_add(l183, 1)) {
			fRec120[l183] = 0.0f;
		}
		for (int l184 = 0; l184 < 16384; l184 = faust_wrap_add(l184, 1)) {
			fVec67[l184] = 0.0f;
		}
		for (int l185 = 0; l185 < 2; l185 = faust_wrap_add(l185, 1)) {
			fVec68[l185] = 0.0f;
		}
		for (int l186 = 0; l186 < 2; l186 = faust_wrap_add(l186, 1)) {
			fRec119[l186] = 0.0f;
		}
		for (int l187 = 0; l187 < 2; l187 = faust_wrap_add(l187, 1)) {
			fRec117[l187] = 0.0f;
		}
		for (int l188 = 0; l188 < 2; l188 = faust_wrap_add(l188, 1)) {
			fRec124[l188] = 0.0f;
		}
		for (int l189 = 0; l189 < 16384; l189 = faust_wrap_add(l189, 1)) {
			fVec69[l189] = 0.0f;
		}
		for (int l190 = 0; l190 < 2; l190 = faust_wrap_add(l190, 1)) {
			fVec70[l190] = 0.0f;
		}
		for (int l191 = 0; l191 < 2; l191 = faust_wrap_add(l191, 1)) {
			fRec123[l191] = 0.0f;
		}
		for (int l192 = 0; l192 < 2; l192 = faust_wrap_add(l192, 1)) {
			fRec121[l192] = 0.0f;
		}
		for (int l193 = 0; l193 < 16384; l193 = faust_wrap_add(l193, 1)) {
			fVec71[l193] = 0.0f;
		}
		for (int l194 = 0; l194 < 2; l194 = faust_wrap_add(l194, 1)) {
			fVec72[l194] = 0.0f;
		}
		for (int l195 = 0; l195 < 2; l195 = faust_wrap_add(l195, 1)) {
			fRec125[l195] = 0.0f;
		}
		for (int l196 = 0; l196 < 2; l196 = faust_wrap_add(l196, 1)) {
			fRec122[l196] = 0.0f;
		}
		for (int l197 = 0; l197 < 2; l197 = faust_wrap_add(l197, 1)) {
			fRec0[l197] = 0.0f;
		}
		for (int l198 = 0; l198 < 2; l198 = faust_wrap_add(l198, 1)) {
			fRec1[l198] = 0.0f;
		}
		for (int l199 = 0; l199 < 2; l199 = faust_wrap_add(l199, 1)) {
			fRec126[l199] = 0.0f;
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
	
	virtual LibJpverb* clone() {
		return new LibJpverb(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("JPverb");
		ui_interface->declare(&fHslider9, "0", "");
		ui_interface->declare(&fHslider9, "unit", "s");
		ui_interface->addHorizontalSlider("Decay", &fHslider9, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider2, "10", "");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("High Band", &fHslider2, FAUSTFLOAT(2e+03f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider11, "11", "");
		ui_interface->addHorizontalSlider("Mix", &fHslider11, FAUSTFLOAT(0.35f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->addHorizontalSlider("Damping", &fHslider0, FAUSTFLOAT(0.2f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.999f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->addHorizontalSlider("Size", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider10, "3", "");
		ui_interface->addHorizontalSlider("Early Diffusion", &fHslider10, FAUSTFLOAT(0.707f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.99f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider5, "4", "");
		ui_interface->addHorizontalSlider("Mod Depth", &fHslider5, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider4, "5", "");
		ui_interface->declare(&fHslider4, "unit", "Hz");
		ui_interface->addHorizontalSlider("Mod Rate", &fHslider4, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider7, "6", "");
		ui_interface->addHorizontalSlider("Low Decay X", &fHslider7, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider6, "7", "");
		ui_interface->addHorizontalSlider("Mid Decay X", &fHslider6, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider8, "8", "");
		ui_interface->addHorizontalSlider("High Decay X", &fHslider8, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "9", "");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Low Band", &fHslider1, FAUSTFLOAT(5e+02f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(6e+03f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = std::tan(fConst3 * static_cast<float>(fHslider1));
		float fSlow2 = LibJpverb_faustpower2_f(fSlow1);
		float fSlow3 = 1.0f / fSlow2;
		float fSlow4 = 2.0f * (1.0f - fSlow3);
		float fSlow5 = 1.0f / fSlow1;
		float fSlow6 = (fSlow5 + -0.618034f) / fSlow1 + 1.0f;
		float fSlow7 = 1.0f / ((fSlow5 + 0.618034f) / fSlow1 + 1.0f);
		float fSlow8 = (fSlow5 + -1.618034f) / fSlow1 + 1.0f;
		float fSlow9 = (fSlow5 + 1.618034f) / fSlow1 + 1.0f;
		float fSlow10 = 1.0f / fSlow9;
		float fSlow11 = std::tan(fConst3 * static_cast<float>(fHslider2));
		float fSlow12 = LibJpverb_faustpower2_f(fSlow11);
		float fSlow13 = 2.0f * (1.0f - 1.0f / fSlow12);
		float fSlow14 = 1.0f / fSlow11;
		float fSlow15 = (fSlow14 + -0.618034f) / fSlow11 + 1.0f;
		float fSlow16 = (fSlow14 + 0.618034f) / fSlow11 + 1.0f;
		float fSlow17 = 1.0f / fSlow16;
		float fSlow18 = (fSlow14 + -1.618034f) / fSlow11 + 1.0f;
		float fSlow19 = (fSlow14 + 1.618034f) / fSlow11 + 1.0f;
		float fSlow20 = 1.0f / fSlow19;
		float fSlow21 = static_cast<float>(fHslider3);
		int iSlow22 = itbl0LibJpverbSIG0[static_cast<int>(134.0f * fSlow21)];
		float fSlow23 = 0.005f * static_cast<float>(iSlow22);
		int iSlow24 = itbl0LibJpverbSIG0[static_cast<int>(54.0f * fSlow21)];
		float fSlow25 = 0.005f * static_cast<float>(iSlow24);
		int iSlow26 = itbl0LibJpverbSIG0[static_cast<int>(1e+01f * fSlow21)];
		float fSlow27 = 0.0001f * static_cast<float>(iSlow26);
		int iSlow28 = itbl0LibJpverbSIG0[static_cast<int>(1.1e+02f * fSlow21)];
		float fSlow29 = 0.0001f * static_cast<float>(iSlow28);
		int iSlow30 = itbl0LibJpverbSIG0[static_cast<int>(4e+01f * fSlow21)];
		float fSlow31 = 0.0001f * static_cast<float>(iSlow30);
		int iSlow32 = itbl0LibJpverbSIG0[static_cast<int>(1.4e+02f * fSlow21)];
		float fSlow33 = 0.0001f * static_cast<float>(iSlow32);
		int iSlow34 = itbl0LibJpverbSIG0[static_cast<int>(7e+01f * fSlow21)];
		float fSlow35 = 0.0001f * static_cast<float>(iSlow34);
		int iSlow36 = itbl0LibJpverbSIG0[static_cast<int>(1.7e+02f * fSlow21)];
		float fSlow37 = 0.0001f * static_cast<float>(iSlow36);
		int iSlow38 = itbl0LibJpverbSIG0[static_cast<int>(1e+02f * fSlow21)];
		float fSlow39 = 0.0001f * static_cast<float>(iSlow38);
		int iSlow40 = itbl0LibJpverbSIG0[static_cast<int>(2e+02f * fSlow21)];
		float fSlow41 = 0.0001f * static_cast<float>(iSlow40);
		int iSlow42 = itbl0LibJpverbSIG0[static_cast<int>(1.3e+02f * fSlow21)];
		float fSlow43 = 0.0001f * static_cast<float>(iSlow42);
		int iSlow44 = itbl0LibJpverbSIG0[static_cast<int>(2.3e+02f * fSlow21)];
		float fSlow45 = 0.0001f * static_cast<float>(iSlow44);
		float fSlow46 = fConst1 * static_cast<float>(fHslider4);
		float fSlow47 = fConst1 * static_cast<float>(fHslider5);
		int iSlow48 = itbl0LibJpverbSIG0[static_cast<int>(125.0f * fSlow21)];
		float fSlow49 = 0.0001f * static_cast<float>(iSlow48);
		int iSlow50 = itbl0LibJpverbSIG0[static_cast<int>(204.0f * fSlow21)];
		float fSlow51 = 0.005f * static_cast<float>(iSlow50);
		int iSlow52 = itbl0LibJpverbSIG0[static_cast<int>(25.0f * fSlow21)];
		float fSlow53 = 0.0001f * static_cast<float>(iSlow52);
		int iSlow54 = itbl0LibJpverbSIG0[static_cast<int>(155.0f * fSlow21)];
		float fSlow55 = 0.0001f * static_cast<float>(iSlow54);
		int iSlow56 = itbl0LibJpverbSIG0[static_cast<int>(55.0f * fSlow21)];
		float fSlow57 = 0.0001f * static_cast<float>(iSlow56);
		int iSlow58 = itbl0LibJpverbSIG0[static_cast<int>(185.0f * fSlow21)];
		float fSlow59 = 0.0001f * static_cast<float>(iSlow58);
		int iSlow60 = itbl0LibJpverbSIG0[static_cast<int>(85.0f * fSlow21)];
		float fSlow61 = 0.0001f * static_cast<float>(iSlow60);
		int iSlow62 = itbl0LibJpverbSIG0[static_cast<int>(215.0f * fSlow21)];
		float fSlow63 = 0.0001f * static_cast<float>(iSlow62);
		int iSlow64 = itbl0LibJpverbSIG0[static_cast<int>(115.0f * fSlow21)];
		float fSlow65 = 0.0001f * static_cast<float>(iSlow64);
		int iSlow66 = itbl0LibJpverbSIG0[static_cast<int>(245.0f * fSlow21)];
		float fSlow67 = 0.0001f * static_cast<float>(iSlow66);
		int iSlow68 = itbl0LibJpverbSIG0[static_cast<int>(145.0f * fSlow21)];
		float fSlow69 = 0.0001f * static_cast<float>(iSlow68);
		float fSlow70 = 1.0f - fSlow14;
		float fSlow71 = 1.0f / (fSlow14 + 1.0f);
		float fSlow72 = 1.0f - fSlow5;
		float fSlow73 = 1.0f / (fSlow5 + 1.0f);
		float fSlow74 = 1.0f / (fSlow2 * fSlow9);
		float fSlow75 = fConst1 * static_cast<float>(fHslider6);
		float fSlow76 = fConst1 * static_cast<float>(fHslider7);
		float fSlow77 = (fSlow5 + -1.618034f) / fSlow1 + 1.0f;
		float fSlow78 = 1.0f / ((fSlow5 + 1.618034f) / fSlow1 + 1.0f);
		float fSlow79 = 1.0f / (fSlow12 * fSlow19);
		float fSlow80 = 1.0f / (fSlow12 * fSlow16);
		float fSlow81 = fConst1 * static_cast<float>(fHslider8);
		float fSlow82 = std::pow(1e+01f, -(0.51f * ((1.25f * fSlow21 + -0.25f) / static_cast<float>(fHslider9))));
		float fSlow83 = fConst1 * static_cast<float>(fHslider10);
		int iSlow84 = itbl0LibJpverbSIG0[static_cast<int>(34.0f * fSlow21)];
		float fSlow85 = 0.005f * static_cast<float>(iSlow84);
		int iSlow86 = itbl0LibJpverbSIG0[static_cast<int>(2.4e+02f * fSlow21)];
		float fSlow87 = 0.0001f * static_cast<float>(iSlow86);
		int iSlow88 = itbl0LibJpverbSIG0[static_cast<int>(1.9e+02f * fSlow21)];
		float fSlow89 = 0.0001f * static_cast<float>(iSlow88);
		int iSlow90 = itbl0LibJpverbSIG0[static_cast<int>(175.0f * fSlow21)];
		float fSlow91 = 0.0001f * static_cast<float>(iSlow90);
		float fSlow92 = fConst1 * static_cast<float>(fHslider11);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			iVec0[0] = 1;
			fRec3[0] = fSlow0 + fConst2 * fRec3[1];
			int iTemp0 = faust_wrap_sub(1, iVec0[1]);
			fRec11[0] = 0.995f * (fRec11[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow22))) + fSlow23;
			float fTemp1 = fRec11[0] + -1.49999f;
			float fTemp2 = std::floor(fTemp1);
			fRec13[0] = 0.995f * (fRec13[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow24))) + fSlow25;
			float fTemp3 = fRec13[0] + -1.49999f;
			float fTemp4 = std::floor(fTemp3);
			fRec17[0] = 0.9999f * (fRec17[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow26))) + fSlow27;
			float fTemp5 = fRec17[0] + -1.49999f;
			float fTemp6 = std::floor(fTemp5);
			float fTemp7 = 0.7602446f * fRec1[1];
			float fTemp8 = 0.6496369f * fRec15[1];
			float fTemp9 = 0.7602446f * fRec0[1] - 0.6496369f * fRec14[1];
			fVec1[IOTA0 & 16383] = 0.70710677f * fTemp9 + 0.70710677f * (fTemp8 - fTemp7);
			float fTemp10 = fVec1[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp5))))) & 16383];
			fVec2[0] = fTemp10;
			fRec16[0] = fVec2[1] - (fTemp6 + (2.0f - fRec17[0])) * (fRec16[1] - fTemp10) / (fRec17[0] - fTemp6);
			fRec14[0] = fRec16[0];
			fRec19[0] = 0.9999f * (fRec19[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow28))) + fSlow29;
			float fTemp11 = fRec19[0] + -1.49999f;
			float fTemp12 = std::floor(fTemp11);
			fVec3[IOTA0 & 16383] = 0.70710677f * fTemp9 + 0.70710677f * (fTemp7 - fTemp8);
			float fTemp13 = fVec3[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp11))))) & 16383];
			fVec4[0] = fTemp13;
			fRec18[0] = fVec4[1] - (fTemp12 + (2.0f - fRec19[0])) * (fRec18[1] - fTemp13) / (fRec19[0] - fTemp12);
			fRec15[0] = fRec18[0];
			float fTemp14 = 0.7602446f * fRec14[1] + 0.6496369f * fRec0[1];
			fRec23[0] = 0.9999f * (fRec23[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow30))) + fSlow31;
			float fTemp15 = fRec23[0] + -1.49999f;
			float fTemp16 = std::floor(fTemp15);
			float fTemp17 = 0.7602446f * fRec15[1] + 0.6496369f * fRec1[1];
			float fTemp18 = 0.7602446f * fTemp17;
			float fTemp19 = 0.6496369f * fRec21[1];
			float fTemp20 = 0.7602446f * fTemp14 - 0.6496369f * fRec20[1];
			fVec5[IOTA0 & 16383] = 0.70710677f * fTemp20 + 0.70710677f * (fTemp19 - fTemp18);
			float fTemp21 = fVec5[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp15))))) & 16383];
			fVec6[0] = fTemp21;
			fRec22[0] = fVec6[1] - (fTemp16 + (2.0f - fRec23[0])) * (fRec22[1] - fTemp21) / (fRec23[0] - fTemp16);
			fRec20[0] = fRec22[0];
			fRec25[0] = 0.9999f * (fRec25[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow32))) + fSlow33;
			float fTemp22 = fRec25[0] + -1.49999f;
			float fTemp23 = std::floor(fTemp22);
			fVec7[IOTA0 & 16383] = 0.70710677f * fTemp20 + 0.70710677f * (fTemp18 - fTemp19);
			float fTemp24 = fVec7[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp22))))) & 16383];
			fVec8[0] = fTemp24;
			fRec24[0] = fVec8[1] - (fTemp23 + (2.0f - fRec25[0])) * (fRec24[1] - fTemp24) / (fRec25[0] - fTemp23);
			fRec21[0] = fRec24[0];
			float fTemp25 = 0.7602446f * fRec20[1] + 0.6496369f * fTemp14;
			fRec29[0] = 0.9999f * (fRec29[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow34))) + fSlow35;
			float fTemp26 = fRec29[0] + -1.49999f;
			float fTemp27 = std::floor(fTemp26);
			float fTemp28 = 0.7602446f * fRec21[1] + 0.6496369f * fTemp17;
			float fTemp29 = 0.7602446f * fTemp28;
			float fTemp30 = 0.6496369f * fRec27[1];
			float fTemp31 = 0.7602446f * fTemp25 - 0.6496369f * fRec26[1];
			fVec9[IOTA0 & 16383] = 0.70710677f * fTemp31 + 0.70710677f * (fTemp30 - fTemp29);
			float fTemp32 = fVec9[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp26))))) & 16383];
			fVec10[0] = fTemp32;
			fRec28[0] = fVec10[1] - (fTemp27 + (2.0f - fRec29[0])) * (fRec28[1] - fTemp32) / (fRec29[0] - fTemp27);
			fRec26[0] = fRec28[0];
			fRec31[0] = 0.9999f * (fRec31[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow36))) + fSlow37;
			float fTemp33 = fRec31[0] + -1.49999f;
			float fTemp34 = std::floor(fTemp33);
			fVec11[IOTA0 & 16383] = 0.70710677f * fTemp31 + 0.70710677f * (fTemp29 - fTemp30);
			float fTemp35 = fVec11[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp33))))) & 16383];
			fVec12[0] = fTemp35;
			fRec30[0] = fVec12[1] - (fTemp34 + (2.0f - fRec31[0])) * (fRec30[1] - fTemp35) / (fRec31[0] - fTemp34);
			fRec27[0] = fRec30[0];
			float fTemp36 = 0.7602446f * fRec26[1] + 0.6496369f * fTemp25;
			fRec35[0] = 0.9999f * (fRec35[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow38))) + fSlow39;
			float fTemp37 = fRec35[0] + -1.49999f;
			float fTemp38 = std::floor(fTemp37);
			float fTemp39 = 0.7602446f * fRec27[1] + 0.6496369f * fTemp28;
			float fTemp40 = 0.7602446f * fTemp39;
			float fTemp41 = 0.6496369f * fRec33[1];
			float fTemp42 = 0.7602446f * fTemp36 - 0.6496369f * fRec32[1];
			fVec13[IOTA0 & 16383] = 0.70710677f * fTemp42 + 0.70710677f * (fTemp41 - fTemp40);
			float fTemp43 = fVec13[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp37))))) & 16383];
			fVec14[0] = fTemp43;
			fRec34[0] = fVec14[1] - (fTemp38 + (2.0f - fRec35[0])) * (fRec34[1] - fTemp43) / (fRec35[0] - fTemp38);
			fRec32[0] = fRec34[0];
			fRec37[0] = 0.9999f * (fRec37[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow40))) + fSlow41;
			float fTemp44 = fRec37[0] + -1.49999f;
			float fTemp45 = std::floor(fTemp44);
			fVec15[IOTA0 & 16383] = 0.70710677f * fTemp42 + 0.70710677f * (fTemp40 - fTemp41);
			float fTemp46 = fVec15[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp44))))) & 16383];
			fVec16[0] = fTemp46;
			fRec36[0] = fVec16[1] - (fTemp45 + (2.0f - fRec37[0])) * (fRec36[1] - fTemp46) / (fRec37[0] - fTemp45);
			fRec33[0] = fRec36[0];
			float fTemp47 = 0.7602446f * fRec32[1] + 0.6496369f * fTemp36;
			fRec41[0] = 0.9999f * (fRec41[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow42))) + fSlow43;
			float fTemp48 = fRec41[0] + -1.49999f;
			float fTemp49 = std::floor(fTemp48);
			float fTemp50 = 0.7602446f * fRec33[1] + 0.6496369f * fTemp39;
			float fTemp51 = 0.7602446f * fTemp50;
			float fTemp52 = 0.6496369f * fRec39[1];
			float fTemp53 = 0.7602446f * fTemp47 - 0.6496369f * fRec38[1];
			fVec17[IOTA0 & 16383] = 0.70710677f * fTemp53 + 0.70710677f * (fTemp52 - fTemp51);
			float fTemp54 = fVec17[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp48))))) & 16383];
			fVec18[0] = fTemp54;
			fRec40[0] = fVec18[1] - (fTemp49 + (2.0f - fRec41[0])) * (fRec40[1] - fTemp54) / (fRec41[0] - fTemp49);
			fRec38[0] = fRec40[0];
			fRec43[0] = 0.9999f * (fRec43[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow44))) + fSlow45;
			float fTemp55 = fRec43[0] + -1.49999f;
			float fTemp56 = std::floor(fTemp55);
			fVec19[IOTA0 & 16383] = 0.70710677f * fTemp53 + 0.70710677f * (fTemp51 - fTemp52);
			float fTemp57 = fVec19[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp55))))) & 16383];
			fVec20[0] = fTemp57;
			fRec42[0] = fVec20[1] - (fTemp56 + (2.0f - fRec43[0])) * (fRec42[1] - fTemp57) / (fRec43[0] - fTemp56);
			fRec39[0] = fRec42[0];
			float fTemp58 = 0.7602446f * fRec38[1] + 0.6496369f * fTemp47;
			fVec21[IOTA0 & 1023] = fTemp58;
			fRec46[0] = fSlow46 + fConst2 * fRec46[1];
			float fTemp59 = fConst4 * fRec46[0];
			float fTemp60 = std::cos(fTemp59);
			float fTemp61 = std::sin(fTemp59);
			fRec44[0] = fRec45[1] * fTemp61 + fRec44[1] * fTemp60;
			fRec45[0] = static_cast<float>(iTemp0) + fRec45[1] * fTemp60 - fTemp61 * fRec44[1];
			fRec47[0] = fSlow47 + fConst2 * fRec47[1];
			float fTemp62 = 5e+01f * fRec47[0] * (fRec45[0] + 1.0f);
			float fTemp63 = fTemp62 + 3.500005f;
			int iTemp64 = static_cast<int>(fTemp63);
			int iTemp65 = std::min<int>(512, std::max<int>(0, faust_wrap_add(iTemp64, 4)));
			float fTemp66 = std::floor(fTemp63);
			float fTemp67 = fTemp62 + (2.0f - fTemp66);
			float fTemp68 = fTemp62 + (3.0f - fTemp66);
			float fTemp69 = fTemp62 + (4.0f - fTemp66);
			float fTemp70 = fTemp62 + (5.0f - fTemp66);
			float fTemp71 = fTemp70 * fTemp69;
			float fTemp72 = fTemp71 * fTemp68;
			float fTemp73 = fTemp72 * fTemp67;
			int iTemp74 = std::min<int>(512, std::max<int>(0, faust_wrap_add(iTemp64, 3)));
			int iTemp75 = std::min<int>(512, std::max<int>(0, faust_wrap_add(iTemp64, 2)));
			int iTemp76 = std::min<int>(512, std::max<int>(0, faust_wrap_add(iTemp64, 1)));
			int iTemp77 = std::min<int>(512, std::max<int>(0, iTemp64));
			float fTemp78 = fTemp62 + (1.0f - fTemp66);
			fVec22[IOTA0 & 16383] = fTemp78 * (fTemp67 * (fTemp68 * (0.041666668f * fVec21[(faust_wrap_sub(IOTA0, iTemp77)) & 1023] * fTemp69 - 0.16666667f * fTemp70 * fVec21[(faust_wrap_sub(IOTA0, iTemp76)) & 1023]) + 0.25f * fTemp71 * fVec21[(faust_wrap_sub(IOTA0, iTemp75)) & 1023]) - 0.16666667f * fTemp72 * fVec21[(faust_wrap_sub(IOTA0, iTemp74)) & 1023]) + 0.041666668f * fTemp73 * fVec21[(faust_wrap_sub(IOTA0, iTemp65)) & 1023];
			float fTemp79 = fVec22[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp3))))) & 16383];
			fVec23[0] = fTemp79;
			fRec12[0] = fVec23[1] - (fTemp4 + (2.0f - fRec13[0])) * (fRec12[1] - fTemp79) / (fRec13[0] - fTemp4);
			fRec51[0] = 0.9999f * (fRec51[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow48))) + fSlow49;
			float fTemp80 = fRec51[0] + -1.49999f;
			float fTemp81 = std::floor(fTemp80);
			fRec53[0] = 0.995f * (fRec53[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow50))) + fSlow51;
			float fTemp82 = fRec53[0] + -1.49999f;
			float fTemp83 = std::floor(fTemp82);
			float fTemp84 = 0.7602446f * fRec39[1] + 0.6496369f * fTemp50;
			fVec24[IOTA0 & 1023] = fTemp84;
			float fTemp85 = 5e+01f * fRec47[0] * (1.0f - fRec45[0]);
			float fTemp86 = fTemp85 + 3.500005f;
			int iTemp87 = static_cast<int>(fTemp86);
			float fTemp88 = std::floor(fTemp86);
			float fTemp89 = fTemp85 + (2.0f - fTemp88);
			float fTemp90 = fTemp85 + (3.0f - fTemp88);
			float fTemp91 = fTemp85 + (4.0f - fTemp88);
			float fTemp92 = fTemp85 + (5.0f - fTemp88);
			float fTemp93 = fTemp92 * fTemp91;
			float fTemp94 = fTemp93 * fTemp90;
			fVec25[IOTA0 & 16383] = (fTemp85 + (1.0f - fTemp88)) * (fTemp89 * (fTemp90 * (0.041666668f * fVec24[(faust_wrap_sub(IOTA0, std::min<int>(512, std::max<int>(0, iTemp87)))) & 1023] * fTemp91 - 0.16666667f * fTemp92 * fVec24[(faust_wrap_sub(IOTA0, std::min<int>(512, std::max<int>(0, faust_wrap_add(iTemp87, 1))))) & 1023]) + 0.25f * fTemp93 * fVec24[(faust_wrap_sub(IOTA0, std::min<int>(512, std::max<int>(0, faust_wrap_add(iTemp87, 2))))) & 1023]) - 0.16666667f * fTemp94 * fVec24[(faust_wrap_sub(IOTA0, std::min<int>(512, std::max<int>(0, faust_wrap_add(iTemp87, 3))))) & 1023]) + 0.041666668f * fTemp94 * fTemp89 * fVec24[(faust_wrap_sub(IOTA0, std::min<int>(512, std::max<int>(0, faust_wrap_add(iTemp87, 4))))) & 1023];
			float fTemp95 = fVec25[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp82))))) & 16383];
			fVec26[0] = fTemp95;
			fRec52[0] = fVec26[1] - (fTemp83 + (2.0f - fRec53[0])) * (fRec52[1] - fTemp95) / (fRec53[0] - fTemp83);
			float fTemp96 = 0.7602446f * fRec52[0];
			float fTemp97 = 0.6496369f * fRec49[1];
			float fTemp98 = 0.7602446f * fRec12[0] - 0.6496369f * fRec48[1];
			fVec27[IOTA0 & 16383] = 0.70710677f * fTemp98 + 0.70710677f * (fTemp97 - fTemp96);
			float fTemp99 = fVec27[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp80))))) & 16383];
			fVec28[0] = fTemp99;
			fRec50[0] = fVec28[1] - (fTemp81 + (2.0f - fRec51[0])) * (fRec50[1] - fTemp99) / (fRec51[0] - fTemp81);
			fRec48[0] = fRec50[0];
			fRec55[0] = 0.9999f * (fRec55[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow52))) + fSlow53;
			float fTemp100 = fRec55[0] + -1.49999f;
			float fTemp101 = std::floor(fTemp100);
			fVec29[IOTA0 & 16383] = 0.70710677f * fTemp98 + 0.70710677f * (fTemp96 - fTemp97);
			float fTemp102 = fVec29[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp100))))) & 16383];
			fVec30[0] = fTemp102;
			fRec54[0] = fVec30[1] - (fTemp101 + (2.0f - fRec55[0])) * (fRec54[1] - fTemp102) / (fRec55[0] - fTemp101);
			fRec49[0] = fRec54[0];
			float fTemp103 = 0.7602446f * fRec48[1] + 0.6496369f * fRec12[0];
			fRec59[0] = 0.9999f * (fRec59[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow54))) + fSlow55;
			float fTemp104 = fRec59[0] + -1.49999f;
			float fTemp105 = std::floor(fTemp104);
			float fTemp106 = 0.7602446f * fRec49[1] + 0.6496369f * fRec52[0];
			float fTemp107 = 0.7602446f * fTemp106;
			float fTemp108 = 0.6496369f * fRec57[1];
			float fTemp109 = 0.7602446f * fTemp103 - 0.6496369f * fRec56[1];
			fVec31[IOTA0 & 16383] = 0.70710677f * fTemp109 + 0.70710677f * (fTemp108 - fTemp107);
			float fTemp110 = fVec31[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp104))))) & 16383];
			fVec32[0] = fTemp110;
			fRec58[0] = fVec32[1] - (fTemp105 + (2.0f - fRec59[0])) * (fRec58[1] - fTemp110) / (fRec59[0] - fTemp105);
			fRec56[0] = fRec58[0];
			fRec61[0] = 0.9999f * (fRec61[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow56))) + fSlow57;
			float fTemp111 = fRec61[0] + -1.49999f;
			float fTemp112 = std::floor(fTemp111);
			float fTemp113 = fRec61[0] - fTemp112;
			fVec33[IOTA0 & 16383] = 0.70710677f * fTemp109 + 0.70710677f * (fTemp107 - fTemp108);
			int iTemp114 = std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp111)));
			float fTemp115 = fVec33[(faust_wrap_sub(IOTA0, iTemp114)) & 16383];
			fVec34[0] = fTemp115;
			float fTemp116 = fTemp112 + (2.0f - fRec61[0]);
			fRec60[0] = fVec34[1] - fTemp116 * (fRec60[1] - fTemp115) / fTemp113;
			fRec57[0] = fRec60[0];
			float fTemp117 = 0.7602446f * fRec56[1] + 0.6496369f * fTemp103;
			fRec65[0] = 0.9999f * (fRec65[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow58))) + fSlow59;
			float fTemp118 = fRec65[0] + -1.49999f;
			float fTemp119 = std::floor(fTemp118);
			float fTemp120 = 0.7602446f * fRec57[1] + 0.6496369f * fTemp106;
			float fTemp121 = 0.7602446f * fTemp120;
			float fTemp122 = 0.6496369f * fRec63[1];
			float fTemp123 = 0.7602446f * fTemp117 - 0.6496369f * fRec62[1];
			fVec35[IOTA0 & 16383] = 0.70710677f * fTemp123 + 0.70710677f * (fTemp122 - fTemp121);
			float fTemp124 = fVec35[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp118))))) & 16383];
			fVec36[0] = fTemp124;
			fRec64[0] = fVec36[1] - (fTemp119 + (2.0f - fRec65[0])) * (fRec64[1] - fTemp124) / (fRec65[0] - fTemp119);
			fRec62[0] = fRec64[0];
			fRec67[0] = 0.9999f * (fRec67[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow60))) + fSlow61;
			float fTemp125 = fRec67[0] + -1.49999f;
			float fTemp126 = std::floor(fTemp125);
			float fTemp127 = fRec67[0] - fTemp126;
			fVec37[IOTA0 & 16383] = 0.70710677f * fTemp123 + 0.70710677f * (fTemp121 - fTemp122);
			int iTemp128 = std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp125)));
			float fTemp129 = fVec37[(faust_wrap_sub(IOTA0, iTemp128)) & 16383];
			fVec38[0] = fTemp129;
			float fTemp130 = fTemp126 + (2.0f - fRec67[0]);
			fRec66[0] = fVec38[1] - fTemp130 * (fRec66[1] - fTemp129) / fTemp127;
			fRec63[0] = fRec66[0];
			float fTemp131 = 0.7602446f * fRec62[1] + 0.6496369f * fTemp117;
			fRec71[0] = 0.9999f * (fRec71[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow62))) + fSlow63;
			float fTemp132 = fRec71[0] + -1.49999f;
			float fTemp133 = std::floor(fTemp132);
			float fTemp134 = fRec71[0] - fTemp133;
			float fTemp135 = 0.7602446f * fRec63[1] + 0.6496369f * fTemp120;
			float fTemp136 = 0.7602446f * fTemp135;
			float fTemp137 = 0.6496369f * fRec69[1];
			float fTemp138 = 0.7602446f * fTemp131 - 0.6496369f * fRec68[1];
			fVec39[IOTA0 & 16383] = 0.70710677f * fTemp138 + 0.70710677f * (fTemp137 - fTemp136);
			int iTemp139 = std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp132)));
			float fTemp140 = fVec39[(faust_wrap_sub(IOTA0, iTemp139)) & 16383];
			fVec40[0] = fTemp140;
			float fTemp141 = fTemp133 + (2.0f - fRec71[0]);
			fRec70[0] = fVec40[1] - fTemp141 * (fRec70[1] - fTemp140) / fTemp134;
			fRec68[0] = fRec70[0];
			fRec73[0] = 0.9999f * (fRec73[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow64))) + fSlow65;
			float fTemp142 = fRec73[0] + -1.49999f;
			float fTemp143 = std::floor(fTemp142);
			float fTemp144 = fRec73[0] - fTemp143;
			fVec41[IOTA0 & 16383] = 0.70710677f * fTemp138 + 0.70710677f * (fTemp136 - fTemp137);
			int iTemp145 = std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp142)));
			float fTemp146 = fVec41[(faust_wrap_sub(IOTA0, iTemp145)) & 16383];
			fVec42[0] = fTemp146;
			float fTemp147 = fTemp143 + (2.0f - fRec73[0]);
			fRec72[0] = fVec42[1] - fTemp147 * (fRec72[1] - fTemp146) / fTemp144;
			fRec69[0] = fRec72[0];
			float fTemp148 = 0.7602446f * fRec68[1] + 0.6496369f * fTemp131;
			fRec77[0] = 0.9999f * (fRec77[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow66))) + fSlow67;
			float fTemp149 = fRec77[0] + -1.49999f;
			float fTemp150 = std::floor(fTemp149);
			float fTemp151 = 0.7602446f * fRec69[1] + 0.6496369f * fTemp135;
			float fTemp152 = 0.7602446f * fTemp151;
			float fTemp153 = 0.6496369f * fRec75[1];
			float fTemp154 = 0.7602446f * fTemp148 - 0.6496369f * fRec74[1];
			fVec43[IOTA0 & 16383] = 0.70710677f * fTemp154 + 0.70710677f * (fTemp153 - fTemp152);
			float fTemp155 = fVec43[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp149))))) & 16383];
			fVec44[0] = fTemp155;
			fRec76[0] = fVec44[1] - (fTemp150 + (2.0f - fRec77[0])) * (fRec76[1] - fTemp155) / (fRec77[0] - fTemp150);
			fRec74[0] = fRec76[0];
			fRec79[0] = 0.9999f * (fRec79[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow68))) + fSlow69;
			float fTemp156 = fRec79[0] + -1.49999f;
			float fTemp157 = std::floor(fTemp156);
			float fTemp158 = fRec79[0] - fTemp157;
			fVec45[IOTA0 & 16383] = 0.70710677f * fTemp154 + 0.70710677f * (fTemp152 - fTemp153);
			int iTemp159 = std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp156)));
			float fTemp160 = fVec45[(faust_wrap_sub(IOTA0, iTemp159)) & 16383];
			fVec46[0] = fTemp160;
			float fTemp161 = fTemp157 + (2.0f - fRec79[0]);
			fRec78[0] = fVec46[1] - fTemp161 * (fRec78[1] - fTemp160) / fTemp158;
			fRec75[0] = fRec78[0];
			float fTemp162 = 0.7602446f * fRec74[1] + 0.6496369f * fTemp148;
			fVec47[IOTA0 & 16383] = fTemp162;
			float fTemp163 = 5e+01f * fRec47[0] * (fRec44[0] + 1.0f);
			float fTemp164 = fTemp163 + 3.500005f;
			int iTemp165 = static_cast<int>(fTemp164);
			int iTemp166 = std::max<int>(0, faust_wrap_add(iTemp165, 4));
			float fTemp167 = std::floor(fTemp164);
			float fTemp168 = fTemp163 + (2.0f - fTemp167);
			float fTemp169 = fTemp163 + (3.0f - fTemp167);
			float fTemp170 = fTemp163 + (4.0f - fTemp167);
			float fTemp171 = fTemp163 + (5.0f - fTemp167);
			float fTemp172 = fTemp171 * fTemp170;
			float fTemp173 = fTemp172 * fTemp169;
			float fTemp174 = fTemp173 * fTemp168;
			int iTemp175 = std::max<int>(0, faust_wrap_add(iTemp165, 3));
			int iTemp176 = std::max<int>(0, faust_wrap_add(iTemp165, 2));
			int iTemp177 = std::max<int>(0, faust_wrap_add(iTemp165, 1));
			int iTemp178 = std::max<int>(0, iTemp165);
			float fTemp179 = fTemp163 + (1.0f - fTemp167);
			fVec48[IOTA0 & 16383] = fTemp179 * (fTemp168 * (fTemp169 * (0.041666668f * fVec47[(faust_wrap_sub(IOTA0, std::min<int>(8192, iTemp178))) & 16383] * fTemp170 - 0.16666667f * fTemp171 * fVec47[(faust_wrap_sub(IOTA0, std::min<int>(8192, iTemp177))) & 16383]) + 0.25f * fTemp172 * fVec47[(faust_wrap_sub(IOTA0, std::min<int>(8192, iTemp176))) & 16383]) - 0.16666667f * fTemp173 * fVec47[(faust_wrap_sub(IOTA0, std::min<int>(8192, iTemp175))) & 16383]) + 0.041666668f * fTemp174 * fVec47[(faust_wrap_sub(IOTA0, std::min<int>(8192, iTemp166))) & 16383];
			float fTemp180 = fVec48[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp1))))) & 16383];
			fVec49[0] = fTemp180;
			fRec10[0] = fVec49[1] - (fTemp2 + (2.0f - fRec11[0])) * (fRec10[1] - fTemp180) / (fRec11[0] - fTemp2);
			fRec9[0] = -(fSlow71 * (fSlow70 * fRec9[1] - (fRec10[0] + fRec10[1])));
			fRec8[0] = fRec9[0] - fSlow20 * (fSlow18 * fRec8[2] + fSlow13 * fRec8[1]);
			fRec7[0] = fSlow20 * (fRec8[2] + fRec8[0] + 2.0f * fRec8[1]) - fSlow17 * (fSlow15 * fRec7[2] + fSlow13 * fRec7[1]);
			float fTemp181 = fSlow17 * (fRec7[2] + fRec7[0] + 2.0f * fRec7[1]);
			fVec50[0] = fTemp181;
			fRec6[0] = -(fSlow73 * (fSlow72 * fRec6[1] - fSlow5 * (fTemp181 - fVec50[1])));
			fRec5[0] = fRec6[0] - fSlow10 * (fSlow8 * fRec5[2] + fSlow4 * fRec5[1]);
			fRec4[0] = fSlow74 * (fRec5[2] + (fRec5[0] - 2.0f * fRec5[1])) - fSlow7 * (fSlow6 * fRec4[2] + fSlow4 * fRec4[1]);
			fRec80[0] = fSlow75 + fConst2 * fRec80[1];
			fRec83[0] = -(fSlow73 * (fSlow72 * fRec83[1] - (fTemp181 + fVec50[1])));
			fRec82[0] = fRec83[0] - fSlow10 * (fSlow8 * fRec82[2] + fSlow4 * fRec82[1]);
			fRec81[0] = fSlow10 * (fRec82[2] + fRec82[0] + 2.0f * fRec82[1]) - fSlow7 * (fSlow6 * fRec81[2] + fSlow4 * fRec81[1]);
			fRec84[0] = fSlow76 + fConst2 * fRec84[1];
			float fTemp182 = fSlow4 * fRec85[1];
			fRec88[0] = -(fSlow71 * (fSlow70 * fRec88[1] - fSlow14 * (fRec10[0] - fRec10[1])));
			fRec87[0] = fRec88[0] - fSlow20 * (fSlow18 * fRec87[2] + fSlow13 * fRec87[1]);
			fRec86[0] = fSlow79 * (fRec87[2] + (fRec87[0] - 2.0f * fRec87[1])) - fSlow17 * (fSlow15 * fRec86[2] + fSlow13 * fRec86[1]);
			fRec85[0] = fSlow80 * (fRec86[2] + (fRec86[0] - 2.0f * fRec86[1])) - fSlow78 * (fSlow77 * fRec85[2] + fTemp182);
			fRec89[0] = fSlow81 + fConst2 * fRec89[1];
			float fTemp183 = static_cast<float>(input0[i0]);
			float fTemp184 = fTemp183 + fSlow82 * (fRec89[0] * (fRec85[2] + fSlow78 * (fTemp182 + fSlow77 * fRec85[0])) + fSlow7 * (fRec84[0] * (fRec81[2] + fRec81[0] + 2.0f * fRec81[1]) + fSlow3 * fRec80[0] * (fRec4[2] + (fRec4[0] - 2.0f * fRec4[1]))));
			fVec51[IOTA0 & 1023] = fTemp184;
			float fTemp185 = 1.0f - fRec3[0];
			fRec2[0] = fTemp185 * (fTemp179 * (fTemp168 * (fTemp169 * (0.041666668f * fTemp170 * fVec51[(faust_wrap_sub(IOTA0, std::min<int>(512, iTemp178))) & 1023] - 0.16666667f * fTemp171 * fVec51[(faust_wrap_sub(IOTA0, std::min<int>(512, iTemp177))) & 1023]) + 0.25f * fTemp172 * fVec51[(faust_wrap_sub(IOTA0, std::min<int>(512, iTemp176))) & 1023]) - 0.16666667f * fTemp173 * fVec51[(faust_wrap_sub(IOTA0, std::min<int>(512, iTemp175))) & 1023]) + 0.041666668f * fTemp174 * fVec51[(faust_wrap_sub(IOTA0, std::min<int>(512, iTemp166))) & 1023]) + fRec3[0] * fRec2[1];
			fRec90[0] = fSlow83 + fConst2 * fRec90[1];
			float fTemp186 = std::sin(fRec90[0]);
			fRec102[0] = 0.995f * (fRec102[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow84))) + fSlow85;
			float fTemp187 = fRec102[0] + -1.49999f;
			float fTemp188 = std::floor(fTemp187);
			float fTemp189 = 0.7602446f * fRec75[1] + 0.6496369f * fTemp151;
			fVec52[IOTA0 & 16383] = fTemp189;
			float fTemp190 = 5e+01f * fRec47[0] * (1.0f - fRec44[0]);
			float fTemp191 = fTemp190 + 3.500005f;
			int iTemp192 = static_cast<int>(fTemp191);
			float fTemp193 = std::floor(fTemp191);
			float fTemp194 = fTemp190 + (2.0f - fTemp193);
			float fTemp195 = fTemp190 + (3.0f - fTemp193);
			float fTemp196 = fTemp190 + (4.0f - fTemp193);
			float fTemp197 = fTemp190 + (5.0f - fTemp193);
			float fTemp198 = fTemp197 * fTemp196;
			float fTemp199 = fTemp198 * fTemp195;
			fVec53[IOTA0 & 16383] = (fTemp190 + (1.0f - fTemp193)) * (fTemp194 * (fTemp195 * (0.041666668f * fVec52[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, iTemp192)))) & 16383] * fTemp196 - 0.16666667f * fTemp197 * fVec52[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, faust_wrap_add(iTemp192, 1))))) & 16383]) + 0.25f * fTemp198 * fVec52[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, faust_wrap_add(iTemp192, 2))))) & 16383]) - 0.16666667f * fTemp199 * fVec52[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, faust_wrap_add(iTemp192, 3))))) & 16383]) + 0.041666668f * fTemp199 * fTemp194 * fVec52[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, faust_wrap_add(iTemp192, 4))))) & 16383];
			float fTemp200 = fVec53[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp187))))) & 16383];
			fVec54[0] = fTemp200;
			fRec101[0] = fVec54[1] - (fTemp188 + (2.0f - fRec102[0])) * (fRec101[1] - fTemp200) / (fRec102[0] - fTemp188);
			fRec100[0] = -(fSlow71 * (fSlow70 * fRec100[1] - (fRec101[0] + fRec101[1])));
			fRec99[0] = fRec100[0] - fSlow20 * (fSlow18 * fRec99[2] + fSlow13 * fRec99[1]);
			fRec98[0] = fSlow20 * (fRec99[2] + fRec99[0] + 2.0f * fRec99[1]) - fSlow17 * (fSlow15 * fRec98[2] + fSlow13 * fRec98[1]);
			float fTemp201 = fSlow17 * (fRec98[2] + fRec98[0] + 2.0f * fRec98[1]);
			fVec55[0] = fTemp201;
			fRec97[0] = -(fSlow73 * (fSlow72 * fRec97[1] - fSlow5 * (fTemp201 - fVec55[1])));
			fRec96[0] = fRec97[0] - fSlow10 * (fSlow8 * fRec96[2] + fSlow4 * fRec96[1]);
			fRec95[0] = fSlow74 * (fRec96[2] + (fRec96[0] - 2.0f * fRec96[1])) - fSlow7 * (fSlow6 * fRec95[2] + fSlow4 * fRec95[1]);
			fRec105[0] = -(fSlow73 * (fSlow72 * fRec105[1] - (fTemp201 + fVec55[1])));
			fRec104[0] = fRec105[0] - fSlow10 * (fSlow8 * fRec104[2] + fSlow4 * fRec104[1]);
			fRec103[0] = fSlow10 * (fRec104[2] + fRec104[0] + 2.0f * fRec104[1]) - fSlow7 * (fSlow6 * fRec103[2] + fSlow4 * fRec103[1]);
			float fTemp202 = fSlow4 * fRec106[1];
			fRec109[0] = -(fSlow71 * (fSlow70 * fRec109[1] - fSlow14 * (fRec101[0] - fRec101[1])));
			fRec108[0] = fRec109[0] - fSlow20 * (fSlow18 * fRec108[2] + fSlow13 * fRec108[1]);
			fRec107[0] = fSlow79 * (fRec108[2] + (fRec108[0] - 2.0f * fRec108[1])) - fSlow17 * (fSlow15 * fRec107[2] + fSlow13 * fRec107[1]);
			fRec106[0] = fSlow80 * (fRec107[2] + (fRec107[0] - 2.0f * fRec107[1])) - fSlow78 * (fSlow77 * fRec106[2] + fTemp202);
			float fTemp203 = fTemp183 + fSlow82 * (fRec89[0] * (fRec106[2] + fSlow78 * (fTemp202 + fSlow77 * fRec106[0])) + fSlow7 * (fRec84[0] * (fRec103[2] + fRec103[0] + 2.0f * fRec103[1]) + fSlow3 * fRec80[0] * (fRec95[2] + (fRec95[0] - 2.0f * fRec95[1]))));
			fVec56[IOTA0 & 1023] = fTemp203;
			fRec94[0] = fTemp185 * (fTemp78 * (fTemp67 * (fTemp68 * (0.041666668f * fTemp69 * fVec56[(faust_wrap_sub(IOTA0, iTemp77)) & 1023] - 0.16666667f * fTemp70 * fVec56[(faust_wrap_sub(IOTA0, iTemp76)) & 1023]) + 0.25f * fTemp71 * fVec56[(faust_wrap_sub(IOTA0, iTemp75)) & 1023]) - 0.16666667f * fTemp72 * fVec56[(faust_wrap_sub(IOTA0, iTemp74)) & 1023]) + 0.041666668f * fTemp73 * fVec56[(faust_wrap_sub(IOTA0, iTemp65)) & 1023]) + fRec3[0] * fRec94[1];
			float fTemp204 = std::cos(fRec90[0]);
			float fTemp205 = fTemp204 * fRec94[0];
			float fTemp206 = fTemp186 * fRec92[1];
			float fTemp207 = fRec2[0] * fTemp204 - fTemp186 * fRec91[1];
			fVec57[IOTA0 & 16383] = 0.70710677f * fTemp207 + 0.70710677f * (fTemp206 - fTemp205);
			float fTemp208 = fVec57[(faust_wrap_sub(IOTA0, iTemp114)) & 16383];
			fVec58[0] = fTemp208;
			fRec93[0] = fVec58[1] - fTemp116 * (fRec93[1] - fTemp208) / fTemp113;
			fRec91[0] = fRec93[0];
			fRec111[0] = 0.9999f * (fRec111[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow86))) + fSlow87;
			float fTemp209 = fRec111[0] + -1.49999f;
			float fTemp210 = std::floor(fTemp209);
			fVec59[IOTA0 & 16383] = 0.70710677f * fTemp207 + 0.70710677f * (fTemp205 - fTemp206);
			float fTemp211 = fVec59[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp209))))) & 16383];
			fVec60[0] = fTemp211;
			fRec110[0] = fVec60[1] - (fTemp210 + (2.0f - fRec111[0])) * (fRec110[1] - fTemp211) / (fRec111[0] - fTemp210);
			fRec92[0] = fRec110[0];
			float fTemp212 = fTemp204 * fRec91[1] + fTemp186 * fRec2[0];
			float fTemp213 = fTemp204 * fRec92[1] + fTemp186 * fRec94[0];
			float fTemp214 = fTemp204 * fTemp213;
			float fTemp215 = fTemp186 * fRec113[1];
			float fTemp216 = fTemp204 * fTemp212 - fTemp186 * fRec112[1];
			fVec61[IOTA0 & 16383] = 0.70710677f * fTemp216 + 0.70710677f * (fTemp215 - fTemp214);
			float fTemp217 = fVec61[(faust_wrap_sub(IOTA0, iTemp139)) & 16383];
			fVec62[0] = fTemp217;
			fRec114[0] = fVec62[1] - fTemp141 * (fRec114[1] - fTemp217) / fTemp134;
			fRec112[0] = fRec114[0];
			fVec63[IOTA0 & 16383] = 0.70710677f * fTemp216 + 0.70710677f * (fTemp214 - fTemp215);
			float fTemp218 = fVec63[(faust_wrap_sub(IOTA0, iTemp128)) & 16383];
			fVec64[0] = fTemp218;
			fRec115[0] = fVec64[1] - fTemp130 * (fRec115[1] - fTemp218) / fTemp127;
			fRec113[0] = fRec115[0];
			float fTemp219 = fTemp204 * fRec112[1] + fTemp186 * fTemp212;
			float fTemp220 = fTemp204 * fRec113[1] + fTemp186 * fTemp213;
			float fTemp221 = fTemp204 * fTemp220;
			float fTemp222 = fTemp186 * fRec117[1];
			float fTemp223 = fTemp204 * fTemp219 - fTemp186 * fRec116[1];
			fVec65[IOTA0 & 16383] = 0.70710677f * fTemp223 + 0.70710677f * (fTemp222 - fTemp221);
			float fTemp224 = fVec65[(faust_wrap_sub(IOTA0, iTemp145)) & 16383];
			fVec66[0] = fTemp224;
			fRec118[0] = fVec66[1] - fTemp147 * (fRec118[1] - fTemp224) / fTemp144;
			fRec116[0] = fRec118[0];
			fRec120[0] = 0.9999f * (fRec120[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow88))) + fSlow89;
			float fTemp225 = fRec120[0] + -1.49999f;
			float fTemp226 = std::floor(fTemp225);
			fVec67[IOTA0 & 16383] = 0.70710677f * fTemp223 + 0.70710677f * (fTemp221 - fTemp222);
			float fTemp227 = fVec67[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp225))))) & 16383];
			fVec68[0] = fTemp227;
			fRec119[0] = fVec68[1] - (fTemp226 + (2.0f - fRec120[0])) * (fRec119[1] - fTemp227) / (fRec120[0] - fTemp226);
			fRec117[0] = fRec119[0];
			float fTemp228 = fTemp204 * fRec116[1] + fTemp186 * fTemp219;
			fRec124[0] = 0.9999f * (fRec124[1] + static_cast<float>(faust_wrap_mul(iTemp0, iSlow90))) + fSlow91;
			float fTemp229 = fRec124[0] + -1.49999f;
			float fTemp230 = std::floor(fTemp229);
			float fTemp231 = fTemp204 * fRec117[1] + fTemp186 * fTemp220;
			float fTemp232 = fTemp204 * fTemp231;
			float fTemp233 = fTemp186 * fRec122[1];
			float fTemp234 = fTemp204 * fTemp228 - fTemp186 * fRec121[1];
			fVec69[IOTA0 & 16383] = 0.70710677f * fTemp234 + 0.70710677f * (fTemp233 - fTemp232);
			float fTemp235 = fVec69[(faust_wrap_sub(IOTA0, std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp229))))) & 16383];
			fVec70[0] = fTemp235;
			fRec123[0] = fVec70[1] - (fTemp230 + (2.0f - fRec124[0])) * (fRec123[1] - fTemp235) / (fRec124[0] - fTemp230);
			fRec121[0] = fRec123[0];
			fVec71[IOTA0 & 16383] = 0.70710677f * fTemp234 + 0.70710677f * (fTemp232 - fTemp233);
			float fTemp236 = fVec71[(faust_wrap_sub(IOTA0, iTemp159)) & 16383];
			fVec72[0] = fTemp236;
			fRec125[0] = fVec72[1] - fTemp161 * (fRec125[1] - fTemp236) / fTemp158;
			fRec122[0] = fRec125[0];
			fRec0[0] = fTemp204 * fRec121[1] + fTemp186 * fTemp228;
			fRec1[0] = fTemp204 * fRec122[1] + fTemp186 * fTemp231;
			fRec126[0] = fSlow92 + fConst2 * fRec126[1];
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp183 * (1.0f - fRec126[0]) + 0.5f * fRec126[0] * (fRec0[0] + fRec1[0]));
			iVec0[1] = iVec0[0];
			fRec3[1] = fRec3[0];
			fRec11[1] = fRec11[0];
			fRec13[1] = fRec13[0];
			fRec17[1] = fRec17[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fVec2[1] = fVec2[0];
			fRec16[1] = fRec16[0];
			fRec14[1] = fRec14[0];
			fRec19[1] = fRec19[0];
			fVec4[1] = fVec4[0];
			fRec18[1] = fRec18[0];
			fRec15[1] = fRec15[0];
			fRec23[1] = fRec23[0];
			fVec6[1] = fVec6[0];
			fRec22[1] = fRec22[0];
			fRec20[1] = fRec20[0];
			fRec25[1] = fRec25[0];
			fVec8[1] = fVec8[0];
			fRec24[1] = fRec24[0];
			fRec21[1] = fRec21[0];
			fRec29[1] = fRec29[0];
			fVec10[1] = fVec10[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec31[1] = fRec31[0];
			fVec12[1] = fVec12[0];
			fRec30[1] = fRec30[0];
			fRec27[1] = fRec27[0];
			fRec35[1] = fRec35[0];
			fVec14[1] = fVec14[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec37[1] = fRec37[0];
			fVec16[1] = fVec16[0];
			fRec36[1] = fRec36[0];
			fRec33[1] = fRec33[0];
			fRec41[1] = fRec41[0];
			fVec18[1] = fVec18[0];
			fRec40[1] = fRec40[0];
			fRec38[1] = fRec38[0];
			fRec43[1] = fRec43[0];
			fVec20[1] = fVec20[0];
			fRec42[1] = fRec42[0];
			fRec39[1] = fRec39[0];
			fRec46[1] = fRec46[0];
			fRec44[1] = fRec44[0];
			fRec45[1] = fRec45[0];
			fRec47[1] = fRec47[0];
			fVec23[1] = fVec23[0];
			fRec12[1] = fRec12[0];
			fRec51[1] = fRec51[0];
			fRec53[1] = fRec53[0];
			fVec26[1] = fVec26[0];
			fRec52[1] = fRec52[0];
			fVec28[1] = fVec28[0];
			fRec50[1] = fRec50[0];
			fRec48[1] = fRec48[0];
			fRec55[1] = fRec55[0];
			fVec30[1] = fVec30[0];
			fRec54[1] = fRec54[0];
			fRec49[1] = fRec49[0];
			fRec59[1] = fRec59[0];
			fVec32[1] = fVec32[0];
			fRec58[1] = fRec58[0];
			fRec56[1] = fRec56[0];
			fRec61[1] = fRec61[0];
			fVec34[1] = fVec34[0];
			fRec60[1] = fRec60[0];
			fRec57[1] = fRec57[0];
			fRec65[1] = fRec65[0];
			fVec36[1] = fVec36[0];
			fRec64[1] = fRec64[0];
			fRec62[1] = fRec62[0];
			fRec67[1] = fRec67[0];
			fVec38[1] = fVec38[0];
			fRec66[1] = fRec66[0];
			fRec63[1] = fRec63[0];
			fRec71[1] = fRec71[0];
			fVec40[1] = fVec40[0];
			fRec70[1] = fRec70[0];
			fRec68[1] = fRec68[0];
			fRec73[1] = fRec73[0];
			fVec42[1] = fVec42[0];
			fRec72[1] = fRec72[0];
			fRec69[1] = fRec69[0];
			fRec77[1] = fRec77[0];
			fVec44[1] = fVec44[0];
			fRec76[1] = fRec76[0];
			fRec74[1] = fRec74[0];
			fRec79[1] = fRec79[0];
			fVec46[1] = fVec46[0];
			fRec78[1] = fRec78[0];
			fRec75[1] = fRec75[0];
			fVec49[1] = fVec49[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fVec50[1] = fVec50[0];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec80[1] = fRec80[0];
			fRec83[1] = fRec83[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			fRec84[1] = fRec84[0];
			fRec88[1] = fRec88[0];
			fRec87[2] = fRec87[1];
			fRec87[1] = fRec87[0];
			fRec86[2] = fRec86[1];
			fRec86[1] = fRec86[0];
			fRec85[2] = fRec85[1];
			fRec85[1] = fRec85[0];
			fRec89[1] = fRec89[0];
			fRec2[1] = fRec2[0];
			fRec90[1] = fRec90[0];
			fRec102[1] = fRec102[0];
			fVec54[1] = fVec54[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec99[2] = fRec99[1];
			fRec99[1] = fRec99[0];
			fRec98[2] = fRec98[1];
			fRec98[1] = fRec98[0];
			fVec55[1] = fVec55[0];
			fRec97[1] = fRec97[0];
			fRec96[2] = fRec96[1];
			fRec96[1] = fRec96[0];
			fRec95[2] = fRec95[1];
			fRec95[1] = fRec95[0];
			fRec105[1] = fRec105[0];
			fRec104[2] = fRec104[1];
			fRec104[1] = fRec104[0];
			fRec103[2] = fRec103[1];
			fRec103[1] = fRec103[0];
			fRec109[1] = fRec109[0];
			fRec108[2] = fRec108[1];
			fRec108[1] = fRec108[0];
			fRec107[2] = fRec107[1];
			fRec107[1] = fRec107[0];
			fRec106[2] = fRec106[1];
			fRec106[1] = fRec106[0];
			fRec94[1] = fRec94[0];
			fVec58[1] = fVec58[0];
			fRec93[1] = fRec93[0];
			fRec91[1] = fRec91[0];
			fRec111[1] = fRec111[0];
			fVec60[1] = fVec60[0];
			fRec110[1] = fRec110[0];
			fRec92[1] = fRec92[0];
			fVec62[1] = fVec62[0];
			fRec114[1] = fRec114[0];
			fRec112[1] = fRec112[0];
			fVec64[1] = fVec64[0];
			fRec115[1] = fRec115[0];
			fRec113[1] = fRec113[0];
			fVec66[1] = fVec66[0];
			fRec118[1] = fRec118[0];
			fRec116[1] = fRec116[0];
			fRec120[1] = fRec120[0];
			fVec68[1] = fVec68[0];
			fRec119[1] = fRec119[0];
			fRec117[1] = fRec117[0];
			fRec124[1] = fRec124[0];
			fVec70[1] = fVec70[0];
			fRec123[1] = fRec123[0];
			fRec121[1] = fRec121[0];
			fVec72[1] = fVec72[0];
			fRec125[1] = fRec125[0];
			fRec122[1] = fRec122[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec126[1] = fRec126[0];
		}
	}

};

#endif
