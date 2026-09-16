/* ------------------------------------------------------------
license: "GPL-2.0-or-later"
name: "gx-gx-studiopre"
Code generated with Faust 2.87.11 (https://faust.grame.fr)
Compilation options: -lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxGxStudiopre -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __GxGxStudiopre_H__
#define  __GxGxStudiopre_H__

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
#define FAUSTCLASS GxGxStudiopre
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

const static double fGxGxStudiopreSIG0Wave0[200] = {0.0,-0.016281378935,-0.028448874763,-0.037669841617,-0.044778139761,-0.050370154903,-0.054873062693,-0.05859337651,-0.06175148656,-0.064506243972,-0.066972468955,-0.069233428062,-0.071349733339,-0.073365695623,-0.075313865558,-0.077218283761,-0.079096810919,-0.080962801532,-0.082826308941,-0.084694955265,-0.086574561408,-0.088469604978,-0.090383554547,-0.092319114818,-0.094278407432,-0.096263105135,-0.098274532001,-0.100313738868,-0.102381560552,-0.104478659623,-0.106605560181,-0.108762674158,-0.110950321977,-0.113168748931,-0.115418138275,-0.117698621773,-0.120010288275,-0.122353190722,-0.124727351916,-0.127132769302,-0.129569418941,-0.132037258837,-0.134536231722,-0.137066267413,-0.139627284793,-0.142219193488,-0.1448418953,-0.147495285411,-0.150179253422,-0.152893684225,-0.155638458758,-0.158413454644,-0.161218546736,-0.164053607588,-0.166918507854,-0.169813116627,-0.172737301738,-0.175690930001,-0.178673867431,-0.181685979425,-0.184727130923,-0.187797186539,-0.190896010678,-0.194023467633,-0.197179421672,-0.200363737108,-0.203576278359,-0.206816910006,-0.210085496833,-0.213381903865,-0.216705996407,-0.220057640062,-0.223436700766,-0.226843044797,-0.230276538799,-0.233737049797,-0.237224445203,-0.240738592832,-0.244279360909,-0.247846618073,-0.251440233388,-0.255060076346,-0.258706016868,-0.262377925312,-0.266075672472,-0.269799129582,-0.273548168316,-0.27732266079,-0.281122479563,-0.284947497637,-0.288797588459,-0.292672625915,-0.296572484338,-0.300497038503,-0.304446163624,-0.308419735361,-0.312417629812,-0.316439723514,-0.320485893446,-0.324556017023,-0.328649972096,-0.332767636955,-0.336908890321,-0.341073611351,-0.345261679634,-0.349472975191,-0.35370737847,-0.357964770352,-0.362245032143,-0.366548045574,-0.370873692805,-0.375221856416,-0.379592419411,-0.383985265215,-0.388400277672,-0.392837341047,-0.39729634002,-0.401777159686,-0.406279685559,-0.410803803561,-0.415349400029,-0.419916361711,-0.424504575764,-0.429113929751,-0.433744311646,-0.438395609826,-0.443067713071,-0.447760510566,-0.452473891899,-0.457207747054,-0.461961966418,-0.466736440774,-0.471531061303,-0.476345719579,-0.481180307572,-0.486034717644,-0.490908842548,-0.495802575428,-0.500715809816,-0.505648439633,-0.510600359185,-0.515571463164,-0.520561646645,-0.525570805086,-0.530598834328,-0.535645630589,-0.540711090469,-0.545795110944,-0.550897589365,-0.556018423462,-0.561157511336,-0.566314751462,-0.571490042685,-0.576683284221,-0.581894375657,-0.587123216946,-0.592369708407,-0.597633750725,-0.602915244951,-0.608214092496,-0.613530195135,-0.618863455003,-0.624213774594,-0.629581056761,-0.634965204714,-0.640366122017,-0.645783712592,-0.651217880711,-0.656668531001,-0.662135568439,-0.667618898352,-0.673118426415,-0.678634058652,-0.684165701434,-0.689713261474,-0.695276645834,-0.700855761915,-0.706450517461,-0.712060820557,-0.717686579629,-0.723327703439,-0.728984101087,-0.734655682009,-0.740342355978,-0.746044033098,-0.751760623807,-0.757492038875,-0.763238189403,-0.768998986819,-0.774774342882,-0.780564169677,-0.786368379615,-0.792186885432,-0.798019600188,-0.803866437265,-0.809727310369,-0.815602133523,-0.821490821073,-0.82739328768,-0.833309448326};
class GxGxStudiopreSIG0 {
	
  private:
	
	int fGxGxStudiopreSIG0Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxGxStudiopreSIG0() {
		return 0;
	}
	int getNumOutputsGxGxStudiopreSIG0() {
		return 1;
	}
	
	void instanceInitGxGxStudiopreSIG0(int sample_rate) {
		fSampleRate = sample_rate;
		fGxGxStudiopreSIG0Wave0_idx = 0;
	}
	
	void fillGxGxStudiopreSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = faust_wrap_add(i1, 1)) {
			table[i1] = fGxGxStudiopreSIG0Wave0[fGxGxStudiopreSIG0Wave0_idx];
			fGxGxStudiopreSIG0Wave0_idx = (faust_wrap_add(1, fGxGxStudiopreSIG0Wave0_idx)) % 200;
		}
	}

};

static GxGxStudiopreSIG0* newGxGxStudiopreSIG0() { return (GxGxStudiopreSIG0*)new GxGxStudiopreSIG0(); }
static void deleteGxGxStudiopreSIG0(GxGxStudiopreSIG0* dsp) { delete dsp; }

const static double fGxGxStudiopreSIG1Wave0[200] = {0.0,0.016239521366,0.028340428309,0.037476970437,0.04448777198,0.049972504317,0.054360603207,0.057960130568,0.06099253145,0.063617369378,0.065949939533,0.06807381893,0.070049816213,0.0719223601,0.07372406478,0.075478996993,0.077205017838,0.078915464605,0.080620361406,0.082327292963,0.084042037256,0.08576902527,0.087511676487,0.089272644903,0.091054000406,0.092857363332,0.094684004955,0.096534923089,0.098410899435,0.100312543429,0.102240326081,0.104194606314,0.106175651655,0.108183654637,0.110218745905,0.112281004793,0.114370467901,0.11648713612,0.11863098042,0.120801946634,0.122999959452,0.125224925751,0.127476737403,0.129755273627,0.132060402989,0.134391985089,0.136749871993,0.139133909458,0.141543937963,0.143979793598,0.146441308821,0.148928313101,0.151440633468,0.153978094989,0.156540521167,0.159127734288,0.161739555716,0.164375806147,0.16703630582,0.169720874707,0.17242933267,0.175161499594,0.177917195503,0.180696240661,0.183498455652,0.186323661453,0.189171679499,0.192042331728,0.19493544063,0.19785082928,0.200788321374,0.203747741254,0.206728913927,0.209731665088,0.212755821132,0.21580120917,0.218867657037,0.2219549933,0.225063047268,0.228191648994,0.231340629281,0.234509819684,0.237699052513,0.240908160833,0.244136978466,0.247385339991,0.250653080742,0.253940036809,0.257246045036,0.26057094302,0.263914569108,0.267276762396,0.270657362728,0.27405621069,0.277473147613,0.280908015564,0.284360657348,0.287830916506,0.291318637308,0.294823664751,0.29834584456,0.301885023182,0.305441047782,0.309013766242,0.312603027158,0.316208679836,0.319830574289,0.323468561235,0.327122492093,0.330792218979,0.334477594706,0.338178472779,0.341894707391,0.34562615342,0.34937266643,0.353134102663,0.356910319039,0.360701173151,0.364506523263,0.368326228307,0.372160147882,0.376008142248,0.379870072321,0.383745799679,0.387635186549,0.39153809581,0.395454390988,0.399383936255,0.403326596422,0.407282236942,0.411250723903,0.415231924026,0.419225704661,0.423231933788,0.427250480012,0.431281212558,0.435324001271,0.439378716614,0.443445229662,0.447523412102,0.45161313623,0.455714274946,0.459826701755,0.463950290761,0.468084916665,0.472230454766,0.476386780952,0.480553771703,0.484731304085,0.488919255749,0.493117504929,0.497325930437,0.501544411661,0.505772828567,0.510011061689,0.514258992131,0.518516501566,0.522783472229,0.527059786918,0.531345328989,0.535639982356,0.539943631487,0.544256161402,0.54857745767,0.552907406408,0.557245894278,0.561592808482,0.565948036765,0.570311467407,0.574682989225,0.579062491568,0.583449864316,0.587844997877,0.592247783184,0.596658111696,0.601075875391,0.605500966766,0.609933278837,0.614372705133,0.618819139694,0.623272477074,0.62773261233,0.632199441028,0.636672859237,0.641152763526,0.645639050964,0.650131619116,0.654630366043,0.659135190298,0.663645990924,0.668162667453,0.672685119904,0.677213248778,0.681746955059,0.686286140213,0.69083070618,0.695380555379,0.699935590702,0.704495715512,0.709060833642};
class GxGxStudiopreSIG1 {
	
  private:
	
	int fGxGxStudiopreSIG1Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxGxStudiopreSIG1() {
		return 0;
	}
	int getNumOutputsGxGxStudiopreSIG1() {
		return 1;
	}
	
	void instanceInitGxGxStudiopreSIG1(int sample_rate) {
		fSampleRate = sample_rate;
		fGxGxStudiopreSIG1Wave0_idx = 0;
	}
	
	void fillGxGxStudiopreSIG1(int count, double* table) {
		for (int i2 = 0; i2 < count; i2 = faust_wrap_add(i2, 1)) {
			table[i2] = fGxGxStudiopreSIG1Wave0[fGxGxStudiopreSIG1Wave0_idx];
			fGxGxStudiopreSIG1Wave0_idx = (faust_wrap_add(1, fGxGxStudiopreSIG1Wave0_idx)) % 200;
		}
	}

};

static GxGxStudiopreSIG1* newGxGxStudiopreSIG1() { return (GxGxStudiopreSIG1*)new GxGxStudiopreSIG1(); }
static void deleteGxGxStudiopreSIG1(GxGxStudiopreSIG1* dsp) { delete dsp; }

const static double fGxGxStudiopreSIG2Wave0[200] = {0.0,-0.009470083223,-0.017731640171,-0.024967931771,-0.031335264428,-0.036966948878,-0.041976678005,-0.046461408795,-0.050503821185,-0.054174415857,-0.057533303969,-0.060631734028,-0.063513394487,-0.066215524993,-0.068769864373,-0.071203459345,-0.073539354388,-0.07579718024,-0.077993655908,-0.080143016896,-0.082257380488,-0.084347057341,-0.086420817261,-0.088486115921,-0.090549288232,-0.092615713287,-0.094689955055,-0.096775882372,-0.098876771299,-0.100995392421,-0.103134085302,-0.105294821989,-0.107479261182,-0.109688794424,-0.111924585502,-0.114187604048,-0.116478654197,-0.118798399029,-0.121147381411,-0.123526041774,-0.125934733272,-0.128373734712,-0.130843261577,-0.133343475431,-0.135874491932,-0.138436387674,-0.141029206016,-0.143652962052,-0.146307646854,-0.148993231082,-0.151709668072,-0.15445689646,-0.157234842425,-0.160043421601,-0.162882540702,-0.165752098914,-0.16865198908,-0.171582098706,-0.174542310823,-0.177532504724,-0.180552556584,-0.183602339992,-0.186681726414,-0.18979058557,-0.192928785768,-0.196096194186,-0.19929267711,-0.202518100137,-0.205772328349,-0.209055226463,-0.212366658953,-0.21570649016,-0.219074584382,-0.22247080595,-0.225895019296,-0.229347089009,-0.23282687988,-0.236334256942,-0.239869085509,-0.243431231199,-0.247020559961,-0.250636938096,-0.254280232273,-0.257950309543,-0.261647037355,-0.265370283562,-0.269119916429,-0.272895804646,-0.276697817326,-0.280525824016,-0.284379694696,-0.288259299786,-0.292164510146,-0.296095197078,-0.300051232329,-0.304032488089,-0.308038836993,-0.312070152125,-0.316126307011,-0.320207175624,-0.324312632382,-0.328442552146,-0.332596810225,-0.336775282367,-0.340977844765,-0.345204374052,-0.349454747302,-0.353728842028,-0.358026536184,-0.362347708157,-0.366692236774,-0.371060001294,-0.375450881411,-0.379864757251,-0.384301509372,-0.38876101876,-0.393243166833,-0.397747835433,-0.402274906828,-0.406824263715,-0.411395789209,-0.41598936685,-0.420604880599,-0.425242214835,-0.429901254356,-0.434581884378,-0.43928399053,-0.444007458857,-0.448752175816,-0.453518028277,-0.458304903518,-0.463112689229,-0.467941273504,-0.472790544845,-0.477660392161,-0.482550704763,-0.487461372362,-0.492392285074,-0.497343333413,-0.502314408293,-0.507305401022,-0.512316203307,-0.517346707248,-0.522396805341,-0.52746639047,-0.532555355912,-0.537663595335,-0.542791002792,-0.547937472726,-0.553102899964,-0.558287179719,-0.563490207584,-0.568711879538,-0.573952091937,-0.579210741521,-0.584487725403,-0.589782941076,-0.595096286409,-0.600427659644,-0.605776959396,-0.611144084655,-0.616528934778,-0.621931409493,-0.627351408898,-0.632788833455,-0.638243583994,-0.643715561709,-0.649204668158,-0.654710805261,-0.660233875299,-0.665773780911,-0.671330425099,-0.676903711218,-0.682493542981,-0.688099824457,-0.693722460068,-0.699361354588,-0.705016413144,-0.710687541211,-0.716374644616,-0.722077629533,-0.727796402481,-0.733530870326,-0.739280940281,-0.745046519897,-0.750827517071,-0.756623840041,-0.762435397383,-0.768262098012,-0.774103851183,-0.779960566484,-0.78583215384,-0.791718523511,-0.797619586088,-0.803535252495,-0.809465433988,-0.81541004215,-0.821368988895,-0.827342186461,-0.833329547417};
class GxGxStudiopreSIG2 {
	
  private:
	
	int fGxGxStudiopreSIG2Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxGxStudiopreSIG2() {
		return 0;
	}
	int getNumOutputsGxGxStudiopreSIG2() {
		return 1;
	}
	
	void instanceInitGxGxStudiopreSIG2(int sample_rate) {
		fSampleRate = sample_rate;
		fGxGxStudiopreSIG2Wave0_idx = 0;
	}
	
	void fillGxGxStudiopreSIG2(int count, double* table) {
		for (int i3 = 0; i3 < count; i3 = faust_wrap_add(i3, 1)) {
			table[i3] = fGxGxStudiopreSIG2Wave0[fGxGxStudiopreSIG2Wave0_idx];
			fGxGxStudiopreSIG2Wave0_idx = (faust_wrap_add(1, fGxGxStudiopreSIG2Wave0_idx)) % 200;
		}
	}

};

static GxGxStudiopreSIG2* newGxGxStudiopreSIG2() { return (GxGxStudiopreSIG2*)new GxGxStudiopreSIG2(); }
static void deleteGxGxStudiopreSIG2(GxGxStudiopreSIG2* dsp) { delete dsp; }

const static double fGxGxStudiopreSIG3Wave0[200] = {0.0,0.009458983398,0.017690162983,0.024879727704,0.031186387875,0.036745427321,0.04167215765,0.046064862957,0.050007310167,0.053570889135,0.056816437133,0.059795794308,0.062553129787,0.065126072271,0.067546673952,0.069842232346,0.072035990974,0.074147736786,0.076194309518,0.078190036005,0.080147100472,0.082075860282,0.083985115146,0.085882336674,0.087773864111,0.089665071231,0.091560508652,0.093464025183,0.0953788713,0.097307787382,0.099253078951,0.10121668083,0.103200211853,0.105205021523,0.107232229795,0.109282761001,0.111357372783,0.113456680763,0.115581179586,0.117731260856,0.119907228441,0.122109311521,0.124337675712,0.126592432557,0.128873647618,0.131181347375,0.133515525115,0.135876145945,0.138263151075,0.140676461468,0.143115980948,0.145581598857,0.148073192318,0.15059062816,0.153133764568,0.155702452485,0.158296536802,0.160915857384,0.163560249936,0.166229546744,0.168923577305,0.171642168865,0.174385146878,0.177152335397,0.179943557403,0.18275863509,0.185597390108,0.188459643762,0.191345217192,0.194253931518,0.197185607965,0.200140067972,0.203117133281,0.206116626015,0.20913836874,0.212182184522,0.215247896973,0.218335330291,0.221444309288,0.224574659423,0.227726206822,0.230898778295,0.234092201357,0.237306304234,0.240540915879,0.243795865977,0.247070984955,0.250366103982,0.253681054977,0.257015670612,0.260369784309,0.263743230247,0.267135843359,0.270547459334,0.273977914614,0.277427046394,0.280894692621,0.284380691992,0.287884883954,0.291407108697,0.294947207157,0.298505021011,0.302080392675,0.305673165301,0.309283182775,0.312910289712,0.316554331457,0.32021515408,0.323892604371,0.32758652984,0.331296778713,0.33502319993,0.33876564314,0.342523958698,0.346297997665,0.350087611801,0.353892653564,0.357712976108,0.361548433278,0.365398879607,0.369264170314,0.373144161301,0.377038709149,0.380947671117,0.384870905134,0.388808269804,0.392759624396,0.396724828843,0.400703743743,0.404696230349,0.408702150572,0.412721366975,0.416753742772,0.420799141823,0.424857428632,0.428928468346,0.43301212675,0.437108270263,0.441216765939,0.44533748146,0.449470285139,0.453615045908,0.457771633325,0.461939917566,0.466119769422,0.470311060298,0.474513662211,0.478727447784,0.482952290247,0.487188063431,0.491434641769,0.49569190029,0.499959714619,0.50423796097,0.50852651615,0.512825257551,0.51713406315,0.521452811505,0.525781381754,0.53011965361,0.534467507362,0.538824823869,0.543191484559,0.547567371428,0.551952367035,0.556346354499,0.560749217501,0.565160840276,0.569581107614,0.574009904857,0.578447117897,0.582892633171,0.587346337661,0.591808118892,0.596277864928,0.600755464371,0.605240806357,0.609733780555,0.614234277164,0.618742186913,0.623257401054,0.627779811364,0.632309310141,0.6368457902,0.641389144876,0.645939268016,0.650496053979,0.655059397635,0.659629194362,0.664205340041,0.668787731059,0.673376264303,0.677970837159,0.682571347509,0.687177693731,0.691789774695,0.696407489761,0.701030738778,0.705659422079,0.710293440484};
class GxGxStudiopreSIG3 {
	
  private:
	
	int fGxGxStudiopreSIG3Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxGxStudiopreSIG3() {
		return 0;
	}
	int getNumOutputsGxGxStudiopreSIG3() {
		return 1;
	}
	
	void instanceInitGxGxStudiopreSIG3(int sample_rate) {
		fSampleRate = sample_rate;
		fGxGxStudiopreSIG3Wave0_idx = 0;
	}
	
	void fillGxGxStudiopreSIG3(int count, double* table) {
		for (int i4 = 0; i4 < count; i4 = faust_wrap_add(i4, 1)) {
			table[i4] = fGxGxStudiopreSIG3Wave0[fGxGxStudiopreSIG3Wave0_idx];
			fGxGxStudiopreSIG3Wave0_idx = (faust_wrap_add(1, fGxGxStudiopreSIG3Wave0_idx)) % 200;
		}
	}

};

static GxGxStudiopreSIG3* newGxGxStudiopreSIG3() { return (GxGxStudiopreSIG3*)new GxGxStudiopreSIG3(); }
static void deleteGxGxStudiopreSIG3(GxGxStudiopreSIG3* dsp) { delete dsp; }

const static double fGxGxStudiopreSIG4Wave0[200] = {0.0,-0.004810042467,-0.009637593449,-0.014482420501,-0.01934429215,-0.024222977849,-0.029118247932,-0.034029873577,-0.038957626757,-0.043901280204,-0.048860607361,-0.053835382345,-0.058825379902,-0.063830375371,-0.068850144635,-0.073884464092,-0.078933110605,-0.083995861471,-0.089072494376,-0.094162787364,-0.099266518792,-0.1043834673,-0.10951341177,-0.114656131293,-0.119811405134,-0.124979012698,-0.130158733493,-0.135350347102,-0.140553633147,-0.145768371258,-0.150994341041,-0.156231322047,-0.161479093745,-0.166737435484,-0.172006126471,-0.177284945737,-0.182573672108,-0.187872084174,-0.193179960264,-0.198497078411,-0.203823216324,-0.209158151356,-0.214501660474,-0.219853520225,-0.225213506702,-0.23058139551,-0.235956961731,-0.241339979879,-0.246730223868,-0.252127466959,-0.257531481723,-0.262942039983,-0.268358912764,-0.273781870235,-0.279210681647,-0.28464511526,-0.290084938276,-0.295529916752,-0.300979815516,-0.306434398065,-0.31189342647,-0.317356661249,-0.322823861251,-0.328294783514,-0.333769183118,-0.339246813018,-0.344727423868,-0.35021076361,-0.355696576666,-0.361184604271,-0.366674584934,-0.372166253864,-0.377659342594,-0.383153578627,-0.388648685067,-0.394144380224,-0.399640377197,-0.405136383423,-0.410632100181,-0.416127222072,-0.421621436447,-0.427114422797,-0.432605852087,-0.438095386054,-0.443582676434,-0.449067364147,-0.454549078409,-0.46002743579,-0.465502039199,-0.470972476797,-0.476438320839,-0.481899126429,-0.487354430206,-0.492803748927,-0.498246577974,-0.503682389757,-0.509110632032,-0.514530726109,-0.519942064964,-0.525344011249,-0.530735895197,-0.536117012422,-0.541486621622,-0.546843942177,-0.55218815166,-0.557518383253,-0.562833723094,-0.568133207551,-0.573415820451,-0.578680490282,-0.58392608738,-0.589151421154,-0.594355237362,-0.599536215486,-0.604692966268,-0.609824029441,-0.614927871739,-0.620002885242,-0.625047386155,-0.630059614093,-0.635037731981,-0.639979826671,-0.644883910381,-0.649747923076,-0.654569735907,-0.659347155807,-0.664077931368,-0.668759760072,-0.673390296968,-0.677967164838,-0.682487965871,-0.686950294831,-0.691351753666,-0.695689967431,-0.699962601388,-0.704167379046,-0.708302100884,-0.712364663435,-0.716353078371,-0.720265491192,-0.7241001991,-0.727855667655,-0.731530545786,-0.7351236788,-0.738634119051,-0.74206113401,-0.745404211545,-0.748663062315,-0.751837619246,-0.754928034181,-0.757934671837,-0.760858101307,-0.763699085386,-0.766458568055,-0.769137660469,-0.771737625831,-0.774259863517,-0.776705892792,-0.779077336465,-0.781375904752,-0.783603379609,-0.785761599753,-0.787852446515,-0.789877830672,-0.791839680324,-0.793739929886,-0.795580510189,-0.797363339704,-0.799090316851,-0.800763313349,-0.802384168548,-0.803954684678,-0.805476622943,-0.806951700384,-0.808381587437,-0.809767906116,-0.81111222874,-0.812416077142,-0.813680922305,-0.814908184355,-0.816099232856,-0.817255387375,-0.818377918256,-0.819468047574,-0.820526950228,-0.821555755154,-0.822555546618,-0.823527365577,-0.824472211077,-0.825391041689,-0.826284776949,-0.827154298802,-0.828000453038,-0.828824050706,-0.829625869513,-0.830406655184,-0.831167122791,-0.831907958052,-0.832629818578,-0.833333335089};
class GxGxStudiopreSIG4 {
	
  private:
	
	int fGxGxStudiopreSIG4Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxGxStudiopreSIG4() {
		return 0;
	}
	int getNumOutputsGxGxStudiopreSIG4() {
		return 1;
	}
	
	void instanceInitGxGxStudiopreSIG4(int sample_rate) {
		fSampleRate = sample_rate;
		fGxGxStudiopreSIG4Wave0_idx = 0;
	}
	
	void fillGxGxStudiopreSIG4(int count, double* table) {
		for (int i5 = 0; i5 < count; i5 = faust_wrap_add(i5, 1)) {
			table[i5] = fGxGxStudiopreSIG4Wave0[fGxGxStudiopreSIG4Wave0_idx];
			fGxGxStudiopreSIG4Wave0_idx = (faust_wrap_add(1, fGxGxStudiopreSIG4Wave0_idx)) % 200;
		}
	}

};

static GxGxStudiopreSIG4* newGxGxStudiopreSIG4() { return (GxGxStudiopreSIG4*)new GxGxStudiopreSIG4(); }
static void deleteGxGxStudiopreSIG4(GxGxStudiopreSIG4* dsp) { delete dsp; }

const static double fGxGxStudiopreSIG5Wave0[200] = {0.0,0.004791170118,0.00956211814,0.014312633699,0.019042505689,0.023751522214,0.028439470554,0.033106137116,0.037751307401,0.042374765953,0.04697629633,0.051555681058,0.056112701594,0.060647138294,0.065158770368,0.069647375855,0.074112731581,0.078554613132,0.082972794822,0.087367049664,0.091737149342,0.096082864186,0.100403963149,0.104700213786,0.108971382234,0.113217233197,0.11743752993,0.121632034231,0.125800506431,0.129942705388,0.13405838849,0.138147311652,0.142209229328,0.146243894514,0.150251058769,0.154230472229,0.158181883635,0.162105040358,0.165999688436,0.169865572614,0.173702436387,0.177510022056,0.181288070782,0.185036322659,0.188754516779,0.192442391318,0.196099683624,0.199726130312,0.203321467373,0.206885430286,0.210417754146,0.213918173798,0.217386423979,0.22082223948,0.224225355308,0.227595506869,0.230932430156,0.234235861955,0.237505540061,0.24074120351,0.243942592816,0.247109450238,0.250241520045,0.253338548807,0.256400285694,0.259426482795,0.262416895452,0.265371282605,0.268289407159,0.27117103636,0.274015942198,0.27682390181,0.279594697915,0.282328119249,0.28502396103,0.287682025425,0.290302122038,0.292884068411,0.295427690535,0.297932823373,0.300399311398,0.302827009138,0.305215781723,0.307565505451,0.309876068352,0.312147370751,0.314379325845,0.316571860267,0.318724914652,0.320838444203,0.322912419236,0.324946825732,0.326941665857,0.32889695848,0.330812739667,0.332689063148,0.334526000766,0.336323642892,0.33808209881,0.339801497064,0.341481985771,0.343123732886,0.344726926431,0.346291774665,0.347818506213,0.349307370136,0.350758635952,0.352172593588,0.35354955329,0.354889845454,0.356193820407,0.357461848124,0.358694317878,0.359891637834,0.361054234573,0.36218255256,0.363277053558,0.364338215969,0.365366534137,0.366362517588,0.367326690226,0.368259589476,0.369161765399,0.370033779755,0.370876205043,0.371689623508,0.372474626125,0.373231811573,0.373961785179,0.374665157875,0.375342545135,0.375994565926,0.376621841658,0.377224995158,0.377804649648,0.378361427751,0.378895950528,0.379408836531,0.379900700907,0.380372154517,0.380823803116,0.381256246559,0.381670078057,0.382065883475,0.382444240685,0.382805718954,0.383150878388,0.383480269429,0.383794432385,0.384093897025,0.384379182212,0.384650795581,0.384909233271,0.385154979691,0.385388507337,0.385610276642,0.38582073587,0.386020321049,0.386209455932,0.386388551994,0.386558008467,0.386718212391,0.386869538701,0.387012350337,0.387146998372,0.387273822169,0.387393149546,0.387505296965,0.387610569737,0.387709262231,0.387801658104,0.387888030534,0.387968642465,0.388043746858,0.388113586945,0.38817839649,0.388238400053,0.38829381325,0.388344843024,0.388391687908,0.388434538288,0.388473576669,0.388508977933,0.3885409096,0.388569532078,0.388594998918,0.388617457055,0.388637047054,0.388653903344,0.388668154451,0.388679923219,0.388689327037,0.388696478047,0.388701483355,0.388704445232,0.388705461314,0.388704624788,0.388702024575,0.388697745516,0.388691868535};
class GxGxStudiopreSIG5 {
	
  private:
	
	int fGxGxStudiopreSIG5Wave0_idx;
	int fSampleRate;
	
  public:
	
	int getNumInputsGxGxStudiopreSIG5() {
		return 0;
	}
	int getNumOutputsGxGxStudiopreSIG5() {
		return 1;
	}
	
	void instanceInitGxGxStudiopreSIG5(int sample_rate) {
		fSampleRate = sample_rate;
		fGxGxStudiopreSIG5Wave0_idx = 0;
	}
	
	void fillGxGxStudiopreSIG5(int count, double* table) {
		for (int i6 = 0; i6 < count; i6 = faust_wrap_add(i6, 1)) {
			table[i6] = fGxGxStudiopreSIG5Wave0[fGxGxStudiopreSIG5Wave0_idx];
			fGxGxStudiopreSIG5Wave0_idx = (faust_wrap_add(1, fGxGxStudiopreSIG5Wave0_idx)) % 200;
		}
	}

};

static GxGxStudiopreSIG5* newGxGxStudiopreSIG5() { return (GxGxStudiopreSIG5*)new GxGxStudiopreSIG5(); }
static void deleteGxGxStudiopreSIG5(GxGxStudiopreSIG5* dsp) { delete dsp; }

static double GxGxStudiopre_faustpower2_f(double value) {
	return value * value;
}
static double GxGxStudiopre_faustpower3_f(double value) {
	return value * value * value;
}
static double GxGxStudiopre_faustpower4_f(double value) {
	return value * value * value * value;
}
static double DSY_SDRAM_BSS ftbl0GxGxStudiopreSIG0[200];
static double DSY_SDRAM_BSS ftbl1GxGxStudiopreSIG1[200];
static double DSY_SDRAM_BSS ftbl2GxGxStudiopreSIG2[200];
static double DSY_SDRAM_BSS ftbl3GxGxStudiopreSIG3[200];
static double DSY_SDRAM_BSS ftbl4GxGxStudiopreSIG4[200];
static double DSY_SDRAM_BSS ftbl5GxGxStudiopreSIG5[200];

class GxGxStudiopre : public chdsp {
	
 private:
	
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fVslider0;
	double fRec1[2];
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	FAUSTFLOAT fVslider1;
	double fRec2[2];
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;
	FAUSTFLOAT fVslider2;
	double fRec3[2];
	FAUSTFLOAT fVslider3;
	double fRec4[2];
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
	double fConst172;
	double fConst173;
	double fConst174;
	double fConst175;
	double fConst176;
	double fConst177;
	double fConst178;
	double fConst179;
	double fConst180;
	double fConst181;
	double fConst182;
	double fConst183;
	double fConst184;
	double fConst185;
	double fConst186;
	double fConst187;
	double fConst188;
	double fConst189;
	double fConst190;
	double fConst191;
	double fConst192;
	double fConst193;
	double fConst194;
	double fConst195;
	double fConst196;
	double fConst197;
	double fConst198;
	double fConst199;
	double fConst200;
	double fConst201;
	double fConst202;
	double fConst203;
	double fConst204;
	double fConst205;
	double fConst206;
	double fConst207;
	double fConst208;
	double fConst209;
	double fConst210;
	double fConst211;
	double fConst212;
	double fConst213;
	double fConst214;
	double fConst215;
	double fConst216;
	double fConst217;
	double fConst218;
	double fConst219;
	double fConst220;
	double fConst221;
	double fConst222;
	double fConst223;
	double fConst224;
	double fConst225;
	double fConst226;
	double fConst227;
	double fConst228;
	double fConst229;
	double fConst230;
	double fConst231;
	double fConst232;
	double fConst233;
	double fConst234;
	double fConst235;
	double fConst236;
	double fConst237;
	double fConst238;
	double fConst239;
	double fConst240;
	double fConst241;
	double fConst242;
	double fConst243;
	double fConst244;
	double fConst245;
	double fConst246;
	double fConst247;
	double fConst248;
	double fConst249;
	double fConst250;
	double fConst251;
	double fConst252;
	double fConst253;
	double fConst254;
	double fConst255;
	double fConst256;
	double fConst257;
	double fConst258;
	double fConst259;
	double fConst260;
	double fConst261;
	double fConst262;
	double fConst263;
	double fVec0[2];
	double fConst264;
	double fConst265;
	double fRec13[2];
	double fRec12[3];
	double fVec1[2];
	double fConst266;
	double fConst267;
	double fConst268;
	double fRec11[2];
	double fRec10[3];
	double fVec2[2];
	double fConst269;
	double fConst270;
	double fConst271;
	double fRec9[2];
	double fRec8[3];
	double fVec3[2];
	double fConst272;
	double fConst273;
	double fConst274;
	double fRec7[2];
	double fRec6[3];
	double fRec5[6];
	double fConst275;
	double fConst276;
	double fConst277;
	double fConst278;
	double fConst279;
	double fConst280;
	double fConst281;
	double fConst282;
	double fConst283;
	double fConst284;
	double fConst285;
	double fConst286;
	double fConst287;
	double fConst288;
	double fConst289;
	double fConst290;
	double fConst291;
	double fConst292;
	double fConst293;
	double fConst294;
	double fConst295;
	double fConst296;
	double fConst297;
	double fConst298;
	double fConst299;
	double fConst300;
	double fConst301;
	double fConst302;
	double fConst303;
	double fConst304;
	double fConst305;
	double fConst306;
	double fConst307;
	double fConst308;
	double fConst309;
	double fConst310;
	double fConst311;
	double fConst312;
	double fConst313;
	double fConst314;
	double fConst315;
	double fConst316;
	double fConst317;
	double fConst318;
	double fConst319;
	double fConst320;
	double fConst321;
	double fConst322;
	double fConst323;
	double fConst324;
	double fConst325;
	double fConst326;
	double fConst327;
	double fConst328;
	double fConst329;
	double fConst330;
	double fConst331;
	double fConst332;
	double fConst333;
	double fConst334;
	double fConst335;
	double fConst336;
	double fConst337;
	double fConst338;
	double fConst339;
	double fConst340;
	double fConst341;
	double fConst342;
	double fConst343;
	double fConst344;
	double fConst345;
	double fConst346;
	double fConst347;
	double fConst348;
	double fConst349;
	double fConst350;
	double fConst351;
	double fConst352;
	double fConst353;
	double fConst354;
	double fConst355;
	double fConst356;
	double fConst357;
	double fConst358;
	double fConst359;
	double fConst360;
	double fConst361;
	double fConst362;
	double fConst363;
	double fConst364;
	double fConst365;
	double fConst366;
	double fConst367;
	double fConst368;
	double fConst369;
	double fConst370;
	double fConst371;
	double fConst372;
	double fConst373;
	double fConst374;
	double fConst375;
	double fConst376;
	double fConst377;
	double fConst378;
	double fConst379;
	double fConst380;
	double fConst381;
	double fConst382;
	double fConst383;
	double fConst384;
	double fConst385;
	double fConst386;
	double fConst387;
	double fConst388;
	double fConst389;
	double fConst390;
	double fConst391;
	double fConst392;
	double fConst393;
	double fConst394;
	double fConst395;
	double fConst396;
	double fConst397;
	double fConst398;
	double fConst399;
	double fConst400;
	double fConst401;
	double fConst402;
	double fConst403;
	double fConst404;
	double fConst405;
	double fConst406;
	double fConst407;
	double fConst408;
	double fConst409;
	double fConst410;
	double fConst411;
	double fConst412;
	double fConst413;
	double fConst414;
	double fConst415;
	double fConst416;
	double fConst417;
	double fConst418;
	double fConst419;
	double fConst420;
	double fConst421;
	double fConst422;
	double fConst423;
	double fConst424;
	double fConst425;
	double fConst426;
	double fConst427;
	double fConst428;
	double fConst429;
	double fConst430;
	double fConst431;
	double fConst432;
	double fConst433;
	double fConst434;
	double fConst435;
	double fConst436;
	double fConst437;
	double fConst438;
	double fConst439;
	double fRec14[5];
	double fConst440;
	double fConst441;
	double fConst442;
	double fConst443;
	double fConst444;
	double fConst445;
	double fConst446;
	double fConst447;
	double fConst448;
	double fConst449;
	double fConst450;
	double fConst451;
	double fConst452;
	double fConst453;
	double fConst454;
	double fConst455;
	double fConst456;
	double fConst457;
	double fConst458;
	double fConst459;
	double fConst460;
	double fConst461;
	double fConst462;
	double fConst463;
	double fConst464;
	double fConst465;
	double fConst466;
	double fConst467;
	double fConst468;
	double fConst469;
	double fConst470;
	double fConst471;
	double fConst472;
	double fConst473;
	double fConst474;
	double fConst475;
	double fConst476;
	double fRec0[3];
	double fConst477;
	double fConst478;
	double fConst479;
	double fConst480;
	FAUSTFLOAT fVslider4;
	double fRec15[2];
	double fConst481;
	double fConst482;
	double fConst483;
	double fConst484;
	double fConst485;
	double fRec19[2];
	double fRec18[3];
	double fConst486;
	double fRec17[6];
	double fRec20[5];
	double fRec16[3];
	double fConst487;
	double fConst488;
	double fConst489;
	double fRec25[2];
	double fRec24[3];
	double fConst490;
	double fRec23[3];
	double fRec22[6];
	double fRec26[5];
	double fRec21[3];
	double fConst491;
	double fConst492;
	double fConst493;
	double fRec32[2];
	double fRec31[3];
	double fConst494;
	double fRec30[3];
	double fRec29[3];
	double fRec28[6];
	double fRec33[5];
	double fRec27[3];
	double fConst495;
	double fConst496;
	double fRec40[2];
	double fRec39[3];
	double fConst497;
	double fRec38[3];
	double fRec37[3];
	double fRec36[3];
	double fRec35[6];
	double fRec41[5];
	double fRec34[3];
	
 public:
	GxGxStudiopre() {
	}
	
	GxGxStudiopre(const GxGxStudiopre&) = default;
	
	virtual ~GxGxStudiopre() = default;
	
	GxGxStudiopre& operator=(const GxGxStudiopre&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.4.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("chameleon_flags", "-double");
		m->declare("compile_options", "-lang cpp -i -fpga-mem-th 4 -ct 1 -cn GxGxStudiopre -scn chdsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("filename", "gx-gx-studiopre.dsp");
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
		m->declare("gx_tables.lib/license", "GPL-2.0-or-later");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "gx-gx-studiopre");
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
		GxGxStudiopreSIG0* sig0 = newGxGxStudiopreSIG0();
		sig0->instanceInitGxGxStudiopreSIG0(sample_rate);
		sig0->fillGxGxStudiopreSIG0(200, ftbl0GxGxStudiopreSIG0);
		GxGxStudiopreSIG1* sig1 = newGxGxStudiopreSIG1();
		sig1->instanceInitGxGxStudiopreSIG1(sample_rate);
		sig1->fillGxGxStudiopreSIG1(200, ftbl1GxGxStudiopreSIG1);
		GxGxStudiopreSIG2* sig2 = newGxGxStudiopreSIG2();
		sig2->instanceInitGxGxStudiopreSIG2(sample_rate);
		sig2->fillGxGxStudiopreSIG2(200, ftbl2GxGxStudiopreSIG2);
		GxGxStudiopreSIG3* sig3 = newGxGxStudiopreSIG3();
		sig3->instanceInitGxGxStudiopreSIG3(sample_rate);
		sig3->fillGxGxStudiopreSIG3(200, ftbl3GxGxStudiopreSIG3);
		GxGxStudiopreSIG4* sig4 = newGxGxStudiopreSIG4();
		sig4->instanceInitGxGxStudiopreSIG4(sample_rate);
		sig4->fillGxGxStudiopreSIG4(200, ftbl4GxGxStudiopreSIG4);
		GxGxStudiopreSIG5* sig5 = newGxGxStudiopreSIG5();
		sig5->instanceInitGxGxStudiopreSIG5(sample_rate);
		sig5->fillGxGxStudiopreSIG5(200, ftbl5GxGxStudiopreSIG5);
		deleteGxGxStudiopreSIG0(sig0);
		deleteGxGxStudiopreSIG1(sig1);
		deleteGxGxStudiopreSIG2(sig2);
		deleteGxGxStudiopreSIG3(sig3);
		deleteGxGxStudiopreSIG4(sig4);
		deleteGxGxStudiopreSIG5(sig5);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, static_cast<double>(fSampleRate)));
		fConst1 = 4.33864919358014e-10 * fConst0;
		fConst2 = fConst0 * (fConst1 + -7.81664517527894e-09) + 2.68307231780644e-08;
		fConst3 = GxGxStudiopre_faustpower2_f(fConst0);
		fConst4 = 5.36614463561288e-08 - 8.67729838716027e-10 * fConst3;
		fConst5 = 1.0 / (fConst0 * (fConst1 + 7.81664517527894e-09) + 2.68307231780644e-08);
		fConst6 = 1.59749650223354e-24 * fConst0;
		fConst7 = GxGxStudiopre_faustpower3_f(fConst0);
		fConst8 = fConst7 * (fConst0 * (-9.17181360088287e-21 - fConst6) + -1.17096473699268e-19);
		fConst9 = 9.99285046078002e-23 * fConst0;
		fConst10 = fConst3 * (fConst0 * (-5.73269784908691e-19 - fConst9) + -7.31891791891218e-18);
		fConst11 = 1.6929383555757e-23 * fConst0;
		fConst12 = fConst3 * (fConst0 * (fConst0 * (-1.25906879957409e-19 - fConst11) + -1.62857548261884e-17) + -1.83118953550983e-16);
		fConst13 = 1.05898697136012e-21 * fConst0;
		fConst14 = fConst0 * (fConst0 * (fConst0 * (-7.77799604390716e-18 - fConst13) + -6.02464692946613e-16) + -6.14466029015632e-15);
		fConst15 = 2.40088747236654e-22 * fConst0;
		fConst16 = fConst3 * (fConst0 * (fConst15 + 1.8779602481101e-20) + 1.91826477713424e-19);
		fConst17 = 2.15430751633278e-22 * fConst0;
		fConst18 = fConst0 * (fConst0 * (fConst0 * (1.90693980601459e-18 - fConst17) + 1.50232520281226e-16) + 1.53616507253908e-15);
		fConst19 = 1.78443758228215e-23 * fConst0;
		fConst20 = fConst7 * (fConst19 + 2.28327872258084e-22);
		fConst21 = 2.49821261519501e-23 * fConst0;
		fConst22 = fConst3 * (fConst0 * (1.42192566937971e-19 - fConst21) + 1.82351647640129e-18);
		fConst23 = 2.85267232541704e-25 * fConst0;
		fConst24 = GxGxStudiopre_faustpower4_f(fConst0);
		fConst25 = fConst24 * (fConst23 + 3.65013945446597e-24);
		fConst26 = 3.99374125558385e-25 * fConst0;
		fConst27 = fConst7 * (fConst0 * (2.27132232044654e-21 - fConst26) + 2.91281128466384e-20);
		fConst28 = 1.54230955969265e-24 * fConst0;
		fConst29 = fConst3 * (fConst0 * (fConst0 * (fConst28 + 5.65134377825805e-21) + -2.30032611736055e-20) + -1.1695046812109e-18);
		fConst30 = 9.64763852233277e-23 * fConst0;
		fConst31 = fConst0 * (fConst0 * (fConst0 * (fConst30 + 3.53068929659391e-19) + -5.29245486955245e-19) + -6.14466029015632e-17);
		fConst32 = 3.83815344221861e-24 * fConst0;
		fConst33 = fConst7 * (fConst0 * (fConst32 + 5.06664243269087e-22) + 5.70819680645209e-21);
		fConst34 = 3.44396099549798e-24 * fConst0;
		fConst35 = fConst3 * (fConst0 * (fConst0 * (3.00670847416855e-20 - fConst34) + 4.03664924154006e-18) + 4.55514105154877e-17);
		fConst36 = 1.65351911090363e-23 * fConst0;
		fConst37 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst36 + 9.5068384229614e-20) + 1.02988983768651e-17) + -1.30486302011578e-17) + -1.53616507253908e-15);
		fConst38 = 1.03432897575674e-21 * fConst0;
		fConst39 = fConst0 * (fConst0 * (fConst0 * (fConst38 + 5.85227663541147e-18) + 4.52040346187673e-16) + 4.60849521761724e-15);
		fConst40 = fConst0 * (fConst0 * (-1.01914938263382e-18 - fConst15) + -7.84401701489674e-17) + -7.99276990472601e-16;
		fConst41 = fConst0 * (fConst0 * (fConst17 + -1.00931167420926e-18) + -8.09581504534201e-15) + -6.27504999577649e-13;
		fConst42 = fConst3 * (fConst0 * (-7.45798938006809e-20 - fConst19) + -9.51366134408682e-19);
		fConst43 = fConst0 * (fConst0 * (fConst0 * (fConst21 + -3.81003746381788e-20) + -5.94292545384613e-16) + -7.59798531833873e-15);
		fConst44 = fConst7 * (fConst0 * (-1.19226360837823e-21 - fConst23) + -1.52089143936082e-20);
		fConst45 = fConst3 * (fConst0 * (fConst0 * (fConst26 + -6.07263463953272e-22) + -9.49297111470724e-18) + -1.21367136860993e-16);
		fConst46 = 5.51869425408882e-26 * fConst0;
		fConst47 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst46 + 1.04066508425183e-20) + 5.30246139994882e-17) + 1.0728203737318e-15) + 4.87293617171206e-15);
		fConst48 = 3.45211938447258e-24 * fConst0;
		fConst49 = fConst0 * (fConst0 * (fConst0 * (fConst48 + 6.50953455217104e-19) + 3.31397583073083e-15) + 6.32576187894833e-14);
		fConst50 = fConst3 * (fConst0 * (fConst0 * (-1.64989702525133e-20 - fConst32) + -2.11680921042765e-18) + -2.37841533602171e-17);
		fConst51 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst34 + -1.57172472604439e-20) + -1.29316168998563e-16) + -1.68649232502658e-14) + -1.89797543814532e-13);
		fConst52 = 3.9419244672063e-25 * fConst0;
		fConst53 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst52 + 1.03020062404785e-19) + 6.59092588471003e-16) + 9.2998714565051e-14) + 1.58189673716889e-12);
		fConst54 = 2.46579956033756e-23 * fConst0;
		fConst55 = fConst0 * (fConst0 * (fConst0 * (fConst54 + 6.44090677084358e-18) + 4.05825720651041e-14) + 3.13857383051234e-12);
		fConst56 = fConst7 * (fConst0 * (fConst6 + -9.17181360088287e-21) + 1.17096473699268e-19);
		fConst57 = fConst3 * (fConst0 * (5.73269784908691e-19 - fConst9) + -7.31891791891218e-18);
		fConst58 = fConst3 * (fConst0 * (fConst0 * (fConst11 + -1.25906879957409e-19) + 1.62857548261884e-17) + -1.83118953550983e-16);
		fConst59 = fConst0 * (fConst0 * (fConst0 * (7.77799604390716e-18 - fConst13) + -6.02464692946613e-16) + 6.14466029015632e-15);
		fConst60 = fConst3 * (fConst0 * (fConst15 + -1.8779602481101e-20) + 1.91826477713424e-19);
		fConst61 = fConst0 * (fConst0 * (fConst0 * (-1.90693980601459e-18 - fConst17) + 1.50232520281226e-16) + -1.53616507253908e-15);
		fConst62 = fConst7 * (fConst19 + -2.28327872258084e-22);
		fConst63 = fConst3 * (fConst0 * (-1.42192566937971e-19 - fConst21) + 1.82351647640129e-18);
		fConst64 = fConst24 * (3.65013945446597e-24 - fConst23);
		fConst65 = fConst7 * (fConst0 * (fConst26 + 2.27132232044654e-21) + -2.91281128466384e-20);
		fConst66 = fConst3 * (fConst0 * (fConst0 * (5.65134377825805e-21 - fConst28) + 2.30032611736055e-20) + -1.1695046812109e-18);
		fConst67 = fConst0 * (fConst0 * (fConst0 * (fConst30 + -3.53068929659391e-19) + -5.29245486955245e-19) + 6.14466029015632e-17);
		fConst68 = fConst7 * (fConst0 * (5.06664243269087e-22 - fConst32) + -5.70819680645209e-21);
		fConst69 = fConst3 * (fConst0 * (fConst0 * (fConst34 + 3.00670847416855e-20) + -4.03664924154006e-18) + 4.55514105154877e-17);
		fConst70 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (9.5068384229614e-20 - fConst36) + -1.02988983768651e-17) + -1.30486302011578e-17) + 1.53616507253908e-15);
		fConst71 = fConst0 * (fConst0 * (fConst0 * (fConst38 + -5.85227663541147e-18) + 4.52040346187673e-16) + -4.60849521761724e-15);
		fConst72 = fConst0 * (fConst0 * (1.01914938263382e-18 - fConst15) + -7.84401701489674e-17) + 7.99276990472601e-16;
		fConst73 = fConst0 * (fConst0 * (fConst17 + 1.00931167420926e-18) + -8.09581504534201e-15) + 6.27504999577649e-13;
		fConst74 = fConst3 * (fConst0 * (7.45798938006809e-20 - fConst19) + -9.51366134408682e-19);
		fConst75 = fConst0 * (fConst0 * (fConst0 * (fConst21 + 3.81003746381788e-20) + -5.94292545384613e-16) + 7.59798531833873e-15);
		fConst76 = fConst7 * (fConst0 * (fConst23 + -1.19226360837823e-21) + 1.52089143936082e-20);
		fConst77 = fConst3 * (fConst0 * (fConst0 * (-6.07263463953272e-22 - fConst26) + 9.49297111470724e-18) + -1.21367136860993e-16);
		fConst78 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (1.04066508425183e-20 - fConst46) + -5.30246139994882e-17) + 1.0728203737318e-15) + -4.87293617171206e-15);
		fConst79 = fConst0 * (fConst0 * (fConst0 * (fConst48 + -6.50953455217104e-19) + 3.31397583073083e-15) + -6.32576187894833e-14);
		fConst80 = fConst3 * (fConst0 * (fConst0 * (fConst32 + -1.64989702525133e-20) + 2.11680921042765e-18) + -2.37841533602171e-17);
		fConst81 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-1.57172472604439e-20 - fConst34) + 1.29316168998563e-16) + -1.68649232502658e-14) + 1.89797543814532e-13);
		fConst82 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (1.03020062404785e-19 - fConst52) + -6.59092588471003e-16) + 9.2998714565051e-14) + -1.58189673716889e-12);
		fConst83 = fConst0 * (fConst0 * (fConst0 * (fConst54 + -6.44090677084358e-18) + 4.05825720651041e-14) + -3.13857383051234e-12);
		fConst84 = 7.98748251116771e-24 * fConst0;
		fConst85 = fConst7 * (fConst0 * (2.75154408026486e-20 - fConst84) + -1.17096473699268e-19);
		fConst86 = 2.99785513823401e-22 * fConst0;
		fConst87 = fConst3 * (fConst0 * (fConst86 + -5.73269784908691e-19) + -7.31891791891218e-18);
		fConst88 = 8.46469177787849e-23 * fConst0;
		fConst89 = fConst3 * (fConst0 * (fConst0 * (3.77720639872226e-19 - fConst88) + -1.62857548261884e-17) + -1.83118953550983e-16);
		fConst90 = 3.17696091408035e-21 * fConst0;
		fConst91 = fConst0 * (fConst0 * (fConst0 * (fConst90 + -7.77799604390716e-18) + -6.02464692946613e-16) + 1.8433980870469e-14);
		fConst92 = 7.20266241709961e-22 * fConst0;
		fConst93 = fConst3 * (fConst0 * (1.8779602481101e-20 - fConst92) + 1.91826477713424e-19);
		fConst94 = 6.46292254899834e-22 * fConst0;
		fConst95 = fConst0 * (fConst0 * (fConst0 * (fConst94 + 1.90693980601459e-18) + 1.50232520281226e-16) + -4.60849521761724e-15);
		fConst96 = 5.35331274684644e-23 * fConst0;
		fConst97 = fConst7 * (2.28327872258084e-22 - fConst96);
		fConst98 = 7.49463784558502e-23 * fConst0;
		fConst99 = fConst3 * (fConst0 * (fConst98 + 1.42192566937971e-19) + 1.82351647640129e-18);
		fConst100 = 1.42633616270852e-24 * fConst0;
		fConst101 = fConst24 * (fConst100 + -1.09504183633979e-23);
		fConst102 = 1.99687062779193e-24 * fConst0;
		fConst103 = fConst7 * (fConst0 * (-6.81396696133963e-21 - fConst102) + 2.91281128466384e-20);
		fConst104 = 7.71154779846327e-24 * fConst0;
		fConst105 = fConst3 * (fConst0 * (fConst0 * (fConst104 + -1.69540313347742e-20) + -2.30032611736055e-20) + -1.1695046812109e-18);
		fConst106 = 2.89429155669983e-22 * fConst0;
		fConst107 = fConst0 * (fConst0 * (fConst0 * (3.53068929659391e-19 - fConst106) + -5.29245486955245e-19) + 1.8433980870469e-16);
		fConst108 = 1.91907672110931e-23 * fConst0;
		fConst109 = fConst7 * (fConst0 * (fConst108 + -1.51999272980726e-21) + 5.70819680645209e-21);
		fConst110 = 1.72198049774899e-23 * fConst0;
		fConst111 = fConst3 * (fConst0 * (fConst0 * (-9.02012542250564e-20 - fConst110) + 4.03664924154006e-18) + 4.55514105154877e-17);
		fConst112 = 8.26759555451817e-23 * fConst0;
		fConst113 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst112 + -2.85205152688842e-19) + 1.02988983768651e-17) + -1.30486302011578e-17) + 4.60849521761724e-15);
		fConst114 = 3.10298692727022e-21 * fConst0;
		fConst115 = fConst0 * (fConst0 * (fConst0 * (5.85227663541147e-18 - fConst114) + 4.52040346187673e-16) + -1.38254856528517e-14);
		fConst116 = fConst0 * (fConst0 * (fConst92 + -1.01914938263382e-18) + -7.84401701489674e-17) + 2.3978309714178e-15;
		fConst117 = fConst0 * (fConst0 * (-1.00931167420926e-18 - fConst94) + -8.09581504534201e-15) + 1.88251499873295e-12;
		fConst118 = fConst3 * (fConst0 * (fConst96 + -7.45798938006809e-20) + -9.51366134408682e-19);
		fConst119 = fConst0 * (fConst0 * (fConst0 * (-3.81003746381788e-20 - fConst98) + -5.94292545384613e-16) + 2.27939559550162e-14);
		fConst120 = fConst7 * (fConst0 * (3.5767908251347e-21 - fConst100) + -1.52089143936082e-20);
		fConst121 = fConst3 * (fConst0 * (fConst0 * (fConst102 + 1.82179039185982e-21) + -9.49297111470724e-18) + -1.21367136860993e-16);
		fConst122 = 2.75934712704441e-25 * fConst0;
		fConst123 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst122 + -3.12199525275548e-20) + 5.30246139994882e-17) + 1.0728203737318e-15) + -1.46188085151362e-14);
		fConst124 = 1.03563581534178e-23 * fConst0;
		fConst125 = fConst0 * (fConst0 * (fConst0 * (6.50953455217104e-19 - fConst124) + 3.31397583073083e-15) + -1.8977285636845e-13);
		fConst126 = fConst3 * (fConst0 * (fConst0 * (4.94969107575399e-20 - fConst108) + -2.11680921042765e-18) + -2.37841533602171e-17);
		fConst127 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst110 + 4.71517417813316e-20) + -1.29316168998563e-16) + -1.68649232502658e-14) + 5.69392631443596e-13);
		fConst128 = 1.97096223360315e-24 * fConst0;
		fConst129 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst128 + -3.09060187214354e-19) + 6.59092588471003e-16) + 9.2998714565051e-14) + -4.74569021150667e-12);
		fConst130 = 7.39739868101268e-23 * fConst0;
		fConst131 = fConst0 * (fConst0 * (fConst0 * (6.44090677084358e-18 - fConst130) + 4.05825720651041e-14) + -9.41572149153703e-12);
		fConst132 = 1.59749650223354e-23 * fConst0;
		fConst133 = fConst7 * (fConst0 * (fConst132 + -1.83436272017657e-20) + -2.34192947398536e-19);
		fConst134 = 1.998570092156e-22 * fConst0;
		fConst135 = fConst3 * (fConst0 * (-1.14653956981738e-18 - fConst134) + 1.46378358378244e-17);
		fConst136 = 1.6929383555757e-22 * fConst0;
		fConst137 = fConst3 * (fConst0 * (fConst0 * (fConst136 + -2.51813759914817e-19) + -3.25715096523769e-17) + 3.66237907101966e-16);
		fConst138 = 2.11797394272023e-21 * fConst0;
		fConst139 = fConst0 * (fConst0 * (fConst0 * (-1.55559920878143e-17 - fConst138) + 1.20492938589323e-15) + 1.22893205803126e-14);
		fConst140 = 4.80177494473307e-22 * fConst0;
		fConst141 = fConst3 * (fConst0 * (fConst140 + 3.75592049622019e-20) + -3.83652955426848e-19);
		fConst142 = 4.30861503266556e-22 * fConst0;
		fConst143 = fConst0 * (fConst0 * (fConst0 * (3.81387961202917e-18 - fConst142) + -3.00465040562453e-16) + -3.07233014507816e-15);
		fConst144 = 3.56887516456429e-23 * fConst0;
		fConst145 = fConst7 * (fConst144 + 4.56655744516168e-22);
		fConst146 = 4.99642523039001e-23 * fConst0;
		fConst147 = fConst3 * (fConst0 * (2.84385133875941e-19 - fConst146) + -3.64703295280259e-18);
		fConst148 = 2.85267232541704e-24 * fConst0;
		fConst149 = fConst24 * (7.30027890893193e-24 - fConst148);
		fConst150 = 3.99374125558385e-24 * fConst0;
		fConst151 = fConst7 * (fConst0 * (fConst150 + 4.54264464089309e-21) + 5.82562256932768e-20);
		fConst152 = 1.54230955969265e-23 * fConst0;
		fConst153 = fConst3 * (fConst0 * (fConst0 * (1.13026875565161e-20 - fConst152) + -4.60065223472111e-20) + 2.33900936242179e-18);
		fConst154 = 1.92952770446655e-22 * fConst0;
		fConst155 = fConst0 * (fConst0 * (fConst0 * (fConst154 + 7.06137859318782e-19) + 1.05849097391049e-18) + 1.22893205803126e-16);
		fConst156 = 3.83815344221861e-23 * fConst0;
		fConst157 = fConst7 * (fConst0 * (1.01332848653817e-21 - fConst156) + 1.14163936129042e-20);
		fConst158 = 3.44396099549798e-23 * fConst0;
		fConst159 = fConst3 * (fConst0 * (fConst0 * (fConst158 + 6.01341694833709e-20) + 8.07329848308013e-18) + -9.11028210309754e-17);
		fConst160 = 1.65351911090363e-22 * fConst0;
		fConst161 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (1.90136768459228e-19 - fConst160) + 2.05977967537302e-17) + 2.60972604023156e-17) + 3.07233014507816e-15);
		fConst162 = 2.06865795151348e-21 * fConst0;
		fConst163 = fConst0 * (fConst0 * (fConst0 * (fConst162 + 1.17045532708229e-17) + -9.04080692375347e-16) + -9.21699043523448e-15);
		fConst164 = fConst0 * (fConst0 * (-2.03829876526765e-18 - fConst140) + 1.56880340297935e-16) + 1.5985539809452e-15;
		fConst165 = fConst0 * (fConst0 * (fConst142 + -2.01862334841852e-18) + 1.6191630090684e-14) + 1.2550099991553e-12;
		fConst166 = fConst3 * (fConst0 * (-1.49159787601362e-19 - fConst144) + 1.90273226881736e-18);
		fConst167 = fConst0 * (fConst0 * (fConst0 * (fConst146 + -7.62007492763576e-20) + 1.18858509076923e-15) + 1.51959706366775e-14);
		fConst168 = fConst7 * (fConst0 * (fConst148 + -2.38452721675646e-21) + -3.04178287872164e-20);
		fConst169 = fConst3 * (fConst0 * (fConst0 * (-1.21452692790654e-21 - fConst150) + -1.89859422294145e-17) + 2.42734273721987e-16);
		fConst170 = 5.51869425408882e-25 * fConst0;
		fConst171 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (2.08133016850365e-20 - fConst170) + 1.06049227998976e-16) + -2.1456407474636e-15) + -9.74587234342413e-15);
		fConst172 = 6.90423876894517e-24 * fConst0;
		fConst173 = fConst0 * (fConst0 * (fConst0 * (fConst172 + 1.30190691043421e-18) + -6.62795166146167e-15) + -1.26515237578967e-13);
		fConst174 = fConst3 * (fConst0 * (fConst0 * (fConst156 + -3.29979405050266e-20) + -4.23361842085529e-18) + 4.75683067204341e-17);
		fConst175 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-3.14344945208878e-20 - fConst158) + -2.58632337997126e-16) + 3.37298465005315e-14) + 3.79595087629064e-13);
		fConst176 = 3.9419244672063e-24 * fConst0;
		fConst177 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (2.06040124809569e-19 - fConst176) + 1.31818517694201e-15) + -1.85997429130102e-13) + -3.16379347433778e-12);
		fConst178 = 4.93159912067512e-23 * fConst0;
		fConst179 = fConst0 * (fConst0 * (fConst0 * (fConst178 + 1.28818135416872e-17) + -8.11651441302083e-14) + -6.27714766102469e-12);
		fConst180 = fConst7 * (fConst0 * (-1.83436272017657e-20 - fConst132) + 2.34192947398536e-19);
		fConst181 = fConst3 * (fConst0 * (1.14653956981738e-18 - fConst134) + 1.46378358378244e-17);
		fConst182 = fConst3 * (fConst0 * (fConst0 * (-2.51813759914817e-19 - fConst136) + 3.25715096523769e-17) + 3.66237907101966e-16);
		fConst183 = fConst0 * (fConst0 * (fConst0 * (1.55559920878143e-17 - fConst138) + 1.20492938589323e-15) + -1.22893205803126e-14);
		fConst184 = fConst3 * (fConst0 * (fConst140 + -3.75592049622019e-20) + -3.83652955426848e-19);
		fConst185 = fConst0 * (fConst0 * (fConst0 * (-3.81387961202917e-18 - fConst142) + -3.00465040562453e-16) + 3.07233014507816e-15);
		fConst186 = fConst7 * (fConst144 + -4.56655744516168e-22);
		fConst187 = fConst3 * (fConst0 * (-2.84385133875941e-19 - fConst146) + -3.64703295280259e-18);
		fConst188 = fConst24 * (fConst148 + 7.30027890893193e-24);
		fConst189 = fConst7 * (fConst0 * (4.54264464089309e-21 - fConst150) + -5.82562256932768e-20);
		fConst190 = fConst3 * (fConst0 * (fConst0 * (fConst152 + 1.13026875565161e-20) + 4.60065223472111e-20) + 2.33900936242179e-18);
		fConst191 = fConst0 * (fConst0 * (fConst0 * (fConst154 + -7.06137859318782e-19) + 1.05849097391049e-18) + -1.22893205803126e-16);
		fConst192 = fConst7 * (fConst0 * (fConst156 + 1.01332848653817e-21) + -1.14163936129042e-20);
		fConst193 = fConst3 * (fConst0 * (fConst0 * (6.01341694833709e-20 - fConst158) + -8.07329848308013e-18) + -9.11028210309754e-17);
		fConst194 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst160 + 1.90136768459228e-19) + -2.05977967537302e-17) + 2.60972604023156e-17) + -3.07233014507816e-15);
		fConst195 = fConst0 * (fConst0 * (fConst0 * (fConst162 + -1.17045532708229e-17) + -9.04080692375347e-16) + 9.21699043523448e-15);
		fConst196 = fConst0 * (fConst0 * (2.03829876526765e-18 - fConst140) + 1.56880340297935e-16) + -1.5985539809452e-15;
		fConst197 = fConst0 * (fConst0 * (fConst142 + 2.01862334841852e-18) + 1.6191630090684e-14) + -1.2550099991553e-12;
		fConst198 = fConst3 * (fConst0 * (1.49159787601362e-19 - fConst144) + 1.90273226881736e-18);
		fConst199 = fConst0 * (fConst0 * (fConst0 * (fConst146 + 7.62007492763576e-20) + 1.18858509076923e-15) + -1.51959706366775e-14);
		fConst200 = fConst7 * (fConst0 * (-2.38452721675646e-21 - fConst148) + 3.04178287872164e-20);
		fConst201 = fConst3 * (fConst0 * (fConst0 * (fConst150 + -1.21452692790654e-21) + 1.89859422294145e-17) + 2.42734273721987e-16);
		fConst202 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst170 + 2.08133016850365e-20) + -1.06049227998976e-16) + -2.1456407474636e-15) + 9.74587234342413e-15);
		fConst203 = fConst0 * (fConst0 * (fConst0 * (fConst172 + -1.30190691043421e-18) + -6.62795166146167e-15) + 1.26515237578967e-13);
		fConst204 = fConst3 * (fConst0 * (fConst0 * (-3.29979405050266e-20 - fConst156) + 4.23361842085529e-18) + 4.75683067204341e-17);
		fConst205 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst158 + -3.14344945208878e-20) + 2.58632337997126e-16) + 3.37298465005315e-14) + -3.79595087629064e-13);
		fConst206 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst176 + 2.06040124809569e-19) + -1.31818517694201e-15) + -1.85997429130102e-13) + 3.16379347433778e-12);
		fConst207 = fConst0 * (fConst0 * (fConst0 * (fConst178 + -1.28818135416872e-17) + -8.11651441302083e-14) + 6.27714766102469e-12);
		fConst208 = fConst7 * (fConst0 * (fConst84 + 2.75154408026486e-20) + 1.17096473699268e-19);
		fConst209 = fConst3 * (fConst0 * (fConst86 + 5.73269784908691e-19) + -7.31891791891218e-18);
		fConst210 = fConst3 * (fConst0 * (fConst0 * (fConst88 + 3.77720639872226e-19) + 1.62857548261884e-17) + -1.83118953550983e-16);
		fConst211 = fConst0 * (fConst0 * (fConst0 * (fConst90 + 7.77799604390716e-18) + -6.02464692946613e-16) + -1.8433980870469e-14);
		fConst212 = fConst3 * (fConst0 * (-1.8779602481101e-20 - fConst92) + 1.91826477713424e-19);
		fConst213 = fConst0 * (fConst0 * (fConst0 * (fConst94 + -1.90693980601459e-18) + 1.50232520281226e-16) + 4.60849521761724e-15);
		fConst214 = fConst7 * (-2.28327872258084e-22 - fConst96);
		fConst215 = fConst3 * (fConst0 * (fConst98 + -1.42192566937971e-19) + 1.82351647640129e-18);
		fConst216 = fConst24 * (-1.09504183633979e-23 - fConst100);
		fConst217 = fConst7 * (fConst0 * (fConst102 + -6.81396696133963e-21) + -2.91281128466384e-20);
		fConst218 = fConst3 * (fConst0 * (fConst0 * (-1.69540313347742e-20 - fConst104) + 2.30032611736055e-20) + -1.1695046812109e-18);
		fConst219 = fConst0 * (fConst0 * (fConst0 * (-3.53068929659391e-19 - fConst106) + -5.29245486955245e-19) + -1.8433980870469e-16);
		fConst220 = fConst7 * (fConst0 * (-1.51999272980726e-21 - fConst108) + -5.70819680645209e-21);
		fConst221 = fConst3 * (fConst0 * (fConst0 * (fConst110 + -9.02012542250564e-20) + -4.03664924154006e-18) + 4.55514105154877e-17);
		fConst222 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-2.85205152688842e-19 - fConst112) + -1.02988983768651e-17) + -1.30486302011578e-17) + -4.60849521761724e-15);
		fConst223 = fConst0 * (fConst0 * (fConst0 * (-5.85227663541147e-18 - fConst114) + 4.52040346187673e-16) + 1.38254856528517e-14);
		fConst224 = fConst0 * (fConst0 * (fConst92 + 1.01914938263382e-18) + -7.84401701489674e-17) + -2.3978309714178e-15;
		fConst225 = fConst0 * (fConst0 * (1.00931167420926e-18 - fConst94) + -8.09581504534201e-15) + -1.88251499873295e-12;
		fConst226 = fConst3 * (fConst0 * (fConst96 + 7.45798938006809e-20) + -9.51366134408682e-19);
		fConst227 = fConst0 * (fConst0 * (fConst0 * (3.81003746381788e-20 - fConst98) + -5.94292545384613e-16) + -2.27939559550162e-14);
		fConst228 = fConst7 * (fConst0 * (fConst100 + 3.5767908251347e-21) + 1.52089143936082e-20);
		fConst229 = fConst3 * (fConst0 * (fConst0 * (1.82179039185982e-21 - fConst102) + 9.49297111470724e-18) + -1.21367136860993e-16);
		fConst230 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-3.12199525275548e-20 - fConst122) + -5.30246139994882e-17) + 1.0728203737318e-15) + 1.46188085151362e-14);
		fConst231 = fConst0 * (fConst0 * (fConst0 * (-6.50953455217104e-19 - fConst124) + 3.31397583073083e-15) + 1.8977285636845e-13);
		fConst232 = fConst3 * (fConst0 * (fConst0 * (fConst108 + 4.94969107575399e-20) + 2.11680921042765e-18) + -2.37841533602171e-17);
		fConst233 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (4.71517417813316e-20 - fConst110) + 1.29316168998563e-16) + -1.68649232502658e-14) + -5.69392631443596e-13);
		fConst234 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-3.09060187214354e-19 - fConst128) + -6.59092588471003e-16) + 9.2998714565051e-14) + 4.74569021150667e-12);
		fConst235 = fConst0 * (fConst0 * (fConst0 * (-6.44090677084358e-18 - fConst130) + 4.05825720651041e-14) + 9.41572149153703e-12);
		fConst236 = std::tan(270.1769682087222 / fConst0);
		fConst237 = GxGxStudiopre_faustpower2_f(fConst236);
		fConst238 = 2.0 * (1.0 - 1.0 / fConst237);
		fConst239 = 1.0 / fConst236;
		fConst240 = (fConst239 + -1.0000000000000004) / fConst236 + 1.0;
		fConst241 = (fConst239 + 1.0000000000000004) / fConst236 + 1.0;
		fConst242 = 1.0 / fConst241;
		fConst243 = std::tan(659.7344572538566 / fConst0);
		fConst244 = GxGxStudiopre_faustpower2_f(fConst243);
		fConst245 = 2.0 * (1.0 - 1.0 / fConst244);
		fConst246 = 1.0 / fConst243;
		fConst247 = (fConst246 + -1.0000000000000004) / fConst243 + 1.0;
		fConst248 = (fConst246 + 1.0000000000000004) / fConst243 + 1.0;
		fConst249 = 1.0 / fConst248;
		fConst250 = std::tan(3769.9111843077517 / fConst0);
		fConst251 = GxGxStudiopre_faustpower2_f(fConst250);
		fConst252 = 2.0 * (1.0 - 1.0 / fConst251);
		fConst253 = 1.0 / fConst250;
		fConst254 = (fConst253 + -1.0000000000000004) / fConst250 + 1.0;
		fConst255 = (fConst253 + 1.0000000000000004) / fConst250 + 1.0;
		fConst256 = 1.0 / fConst255;
		fConst257 = std::tan(20517.741620594938 / fConst0);
		fConst258 = GxGxStudiopre_faustpower2_f(fConst257);
		fConst259 = 2.0 * (1.0 - 1.0 / fConst258);
		fConst260 = 1.0 / fConst257;
		fConst261 = (fConst260 + -1.0000000000000004) / fConst257 + 1.0;
		fConst262 = (fConst260 + 1.0000000000000004) / fConst257 + 1.0;
		fConst263 = 1.0 / fConst262;
		fConst264 = 1.0 - fConst260;
		fConst265 = 1.0 / (fConst260 + 1.0);
		fConst266 = 1.0 - fConst253;
		fConst267 = fConst253 + 1.0;
		fConst268 = 1.0 / fConst267;
		fConst269 = 1.0 - fConst246;
		fConst270 = fConst246 + 1.0;
		fConst271 = 1.0 / fConst270;
		fConst272 = 1.0 - fConst239;
		fConst273 = fConst239 + 1.0;
		fConst274 = 1.0 / fConst273;
		fConst275 = 4.32789516321643e-20 * fConst0;
		fConst276 = fConst0 * (1.76059952898192e-18 - fConst275) + -9.8138212317832e-18;
		fConst277 = fConst0 * (fConst275 + -1.76059952898192e-18) + 9.8138212317832e-18;
		fConst278 = 9.68624155577011e-23 * fConst0;
		fConst279 = fConst7 * (fConst0 * (5.55529015703311e-19 - fConst278) + -3.69922177510836e-18);
		fConst280 = 6.05905322850301e-21 * fConst0;
		fConst281 = fConst3 * (fConst0 * (fConst280 + -3.47224379213122e-17) + 2.31213628220812e-16);
		fConst282 = 6.91874396840722e-22 * fConst0;
		fConst283 = fConst24 * (fConst282 + -4.6124959789381e-21);
		fConst284 = fConst3 * (fConst0 * (fConst0 * (1.21495106849477e-19 - fConst282) + -5.91080564497569e-16) + 3.93534231394506e-15);
		fConst285 = fConst3 * (fConst0 * (fConst0 * (fConst278 + -9.59122413860399e-19) + 2.31840345387224e-15) + -1.54134240629515e-14);
		fConst286 = fConst0 * (fConst0 * (fConst0 * (5.99684930400747e-17 - fConst280) + -1.44908038300355e-13) + 9.63390117586717e-13);
		fConst287 = fConst7 * (fConst0 * (2.88742248281528e-18 - fConst282) + -1.92187332455754e-17);
		fConst288 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst282 + -3.00430509368582e-18) + 1.09731017637039e-15) + -2.46677102772048e-12) + 1.63972596414378e-11);
		fConst289 = fConst0 * (fConst0 * (fConst275 + -1.82089564663e-16) + 7.34564519198978e-15) + -4.08909217990967e-14;
		fConst290 = fConst0 * (fConst0 * (1.82089564663e-16 - fConst275) + -7.34564519198978e-15) + 4.08909217990967e-14;
		fConst291 = 1.29836854896493e-19 * fConst0;
		fConst292 = fConst0 * (fConst291 + -1.76059952898192e-18) + -9.8138212317832e-18;
		fConst293 = fConst0 * (1.76059952898192e-18 - fConst291) + 9.8138212317832e-18;
		fConst294 = 4.84312077788506e-22 * fConst0;
		fConst295 = fConst7 * (fConst0 * (fConst294 + -1.66658704710993e-18) + 3.69922177510836e-18);
		fConst296 = 1.8177159685509e-20 * fConst0;
		fConst297 = fConst3 * (fConst0 * (3.47224379213122e-17 - fConst296) + 2.31213628220812e-16);
		fConst298 = 3.45937198420361e-21 * fConst0;
		fConst299 = fConst24 * (1.38374879368143e-20 - fConst298);
		fConst300 = fConst3 * (fConst0 * (fConst0 * (fConst298 + -3.64485320548431e-19) + 5.91080564497569e-16) + 3.93534231394506e-15);
		fConst301 = fConst3 * (fConst0 * (fConst0 * (2.8773672415812e-18 - fConst294) + -2.31840345387224e-15) + -1.54134240629515e-14);
		fConst302 = fConst0 * (fConst0 * (fConst0 * (fConst296 + -5.99684930400747e-17) + -1.44908038300355e-13) + 2.89017035276015e-12);
		fConst303 = fConst7 * (fConst0 * (fConst298 + -8.66226744844584e-18) + 1.92187332455754e-17);
		fConst304 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (9.01291528105746e-18 - fConst298) + -1.09731017637039e-15) + -2.46677102772048e-12) + 4.91917789243133e-11);
		fConst305 = fConst0 * (fConst0 * (1.82089564663e-16 - fConst291) + 7.34564519198978e-15) + -1.2267276539729e-13;
		fConst306 = fConst0 * (fConst0 * (fConst291 + -1.82089564663e-16) + -7.34564519198978e-15) + 1.2267276539729e-13;
		fConst307 = 8.65579032643287e-20 * fConst0;
		fConst308 = fConst0 * (-3.52119905796384e-18 - fConst307) + 1.96276424635664e-17;
		fConst309 = fConst0 * (fConst307 + 3.52119905796384e-18) + -1.96276424635664e-17;
		fConst310 = 9.68624155577011e-22 * fConst0;
		fConst311 = fConst7 * (fConst0 * (1.11105803140662e-18 - fConst310) + 7.39844355021672e-18);
		fConst312 = 1.2118106457006e-20 * fConst0;
		fConst313 = fConst3 * (fConst0 * (fConst312 + 6.94448758426244e-17) + -4.62427256441624e-16);
		fConst314 = 6.91874396840722e-21 * fConst0;
		fConst315 = fConst24 * (fConst314 + -9.2249919578762e-21);
		fConst316 = fConst3 * (fConst0 * (fConst0 * (2.42990213698954e-19 - fConst314) + 1.18216112899514e-15) + -7.87068462789012e-15);
		fConst317 = fConst3 * (fConst0 * (fConst0 * (fConst310 + -1.9182448277208e-18) + -4.63680690774447e-15) + 3.0826848125903e-14);
		fConst318 = fConst0 * (fConst0 * (fConst0 * (-1.19936986080149e-16 - fConst312) + 2.8981607660071e-13) + 1.92678023517343e-12);
		fConst319 = fConst7 * (fConst0 * (5.77484496563056e-18 - fConst314) + 3.84374664911509e-17);
		fConst320 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst314 + -6.00861018737164e-18) + -2.19462035274078e-15) + 4.93354205544096e-12) + 3.27945192828755e-11);
		fConst321 = fConst0 * (fConst0 * (fConst307 + 3.64179129326e-16) + -1.46912903839796e-14) + -8.17818435981933e-14;
		fConst322 = fConst0 * (fConst0 * (-3.64179129326e-16 - fConst307) + 1.46912903839796e-14) + 8.17818435981933e-14;
		fConst323 = fConst0 * (3.52119905796384e-18 - fConst307) + 1.96276424635664e-17;
		fConst324 = fConst0 * (fConst307 + -3.52119905796384e-18) + -1.96276424635664e-17;
		fConst325 = fConst7 * (fConst0 * (fConst310 + 1.11105803140662e-18) + -7.39844355021672e-18);
		fConst326 = fConst3 * (fConst0 * (fConst312 + -6.94448758426244e-17) + -4.62427256441624e-16);
		fConst327 = fConst24 * (-9.2249919578762e-21 - fConst314);
		fConst328 = fConst3 * (fConst0 * (fConst0 * (fConst314 + 2.42990213698954e-19) + -1.18216112899514e-15) + -7.87068462789012e-15);
		fConst329 = fConst3 * (fConst0 * (fConst0 * (-1.9182448277208e-18 - fConst310) + 4.63680690774447e-15) + 3.0826848125903e-14);
		fConst330 = fConst0 * (fConst0 * (fConst0 * (1.19936986080149e-16 - fConst312) + 2.8981607660071e-13) + -1.92678023517343e-12);
		fConst331 = fConst7 * (fConst0 * (fConst314 + 5.77484496563056e-18) + -3.84374664911509e-17);
		fConst332 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-6.00861018737164e-18 - fConst314) + 2.19462035274078e-15) + 4.93354205544096e-12) + -3.27945192828755e-11);
		fConst333 = fConst0 * (fConst0 * (fConst307 + -3.64179129326e-16) + -1.46912903839796e-14) + 8.17818435981933e-14;
		fConst334 = fConst0 * (fConst0 * (3.64179129326e-16 - fConst307) + 1.46912903839796e-14) + -8.17818435981933e-14;
		fConst335 = fConst0 * (fConst291 + 1.76059952898192e-18) + -9.8138212317832e-18;
		fConst336 = fConst0 * (-1.76059952898192e-18 - fConst291) + 9.8138212317832e-18;
		fConst337 = fConst7 * (fConst0 * (-1.66658704710993e-18 - fConst294) + -3.69922177510836e-18);
		fConst338 = fConst3 * (fConst0 * (-3.47224379213122e-17 - fConst296) + 2.31213628220812e-16);
		fConst339 = fConst24 * (fConst298 + 1.38374879368143e-20);
		fConst340 = fConst3 * (fConst0 * (fConst0 * (-3.64485320548431e-19 - fConst298) + -5.91080564497569e-16) + 3.93534231394506e-15);
		fConst341 = fConst3 * (fConst0 * (fConst0 * (fConst294 + 2.8773672415812e-18) + 2.31840345387224e-15) + -1.54134240629515e-14);
		fConst342 = fConst0 * (fConst0 * (fConst0 * (fConst296 + 5.99684930400747e-17) + -1.44908038300355e-13) + -2.89017035276015e-12);
		fConst343 = fConst7 * (fConst0 * (-8.66226744844584e-18 - fConst298) + -1.92187332455754e-17);
		fConst344 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst298 + 9.01291528105746e-18) + 1.09731017637039e-15) + -2.46677102772048e-12) + -4.91917789243133e-11);
		fConst345 = fConst0 * (fConst0 * (-1.82089564663e-16 - fConst291) + 7.34564519198978e-15) + 1.2267276539729e-13;
		fConst346 = fConst0 * (fConst0 * (fConst291 + 1.82089564663e-16) + -7.34564519198978e-15) + -1.2267276539729e-13;
		fConst347 = fConst0 * (-1.76059952898192e-18 - fConst275) + -9.8138212317832e-18;
		fConst348 = fConst0 * (fConst275 + 1.76059952898192e-18) + 9.8138212317832e-18;
		fConst349 = fConst7 * (fConst0 * (fConst278 + 5.55529015703311e-19) + 3.69922177510836e-18);
		fConst350 = fConst3 * (fConst0 * (fConst280 + 3.47224379213122e-17) + 2.31213628220812e-16);
		fConst351 = fConst24 * (-4.6124959789381e-21 - fConst282);
		fConst352 = fConst3 * (fConst0 * (fConst0 * (fConst282 + 1.21495106849477e-19) + 5.91080564497569e-16) + 3.93534231394506e-15);
		fConst353 = fConst3 * (fConst0 * (fConst0 * (-9.59122413860399e-19 - fConst278) + -2.31840345387224e-15) + -1.54134240629515e-14);
		fConst354 = fConst0 * (fConst0 * (fConst0 * (-5.99684930400747e-17 - fConst280) + -1.44908038300355e-13) + -9.63390117586717e-13);
		fConst355 = fConst7 * (fConst0 * (fConst282 + 2.88742248281528e-18) + 1.92187332455754e-17);
		fConst356 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-3.00430509368582e-18 - fConst282) + -1.09731017637039e-15) + -2.46677102772048e-12) + -1.63972596414378e-11);
		fConst357 = fConst0 * (fConst0 * (fConst275 + 1.82089564663e-16) + 7.34564519198978e-15) + 4.08909217990967e-14;
		fConst358 = fConst0 * (fConst0 * (-1.82089564663e-16 - fConst275) + -7.34564519198978e-15) + -4.08909217990967e-14;
		fConst359 = ftbl0GxGxStudiopreSIG0[199];
		fConst360 = ftbl0GxGxStudiopreSIG0[0];
		fConst361 = ftbl1GxGxStudiopreSIG1[199];
		fConst362 = ftbl1GxGxStudiopreSIG1[0];
		fConst363 = 4.09065163112436e-18 * fConst0;
		fConst364 = fConst0 * (-3.1996842386608e-16 - fConst363) + -3.26835558922325e-15;
		fConst365 = 3.67052678836745e-18 * fConst0;
		fConst366 = fConst0 * (fConst365 + -3.2490595714095e-14) + -2.55967413440181e-12;
		fConst367 = 3.04033952423208e-19 * fConst0;
		fConst368 = fConst3 * (-3.89026940579609e-18 - fConst367);
		fConst369 = 4.25647533392492e-19 * fConst0;
		fConst370 = fConst0 * (fConst0 * (fConst369 + -2.42268872585805e-15) + -3.10692264109157e-14);
		fConst371 = 4.86040672241183e-21 * fConst0;
		fConst372 = fConst7 * (-6.21913816572845e-20 - fConst371);
		fConst373 = 6.80456941137657e-21 * fConst0;
		fConst374 = fConst3 * (fConst0 * (fConst373 + -3.86989777105262e-17) + -4.9628722562513e-16);
		fConst375 = 2.8158557055486e-20 * fConst0;
		fConst376 = fConst0 * (fConst0 * (fConst0 * (fConst375 + 2.16252174019074e-16) + 4.38213044301358e-15) + 1.99261186829939e-14);
		fConst377 = 1.76140761155593e-18 * fConst0;
		fConst378 = fConst0 * (fConst0 * (fConst377 + 1.35192183493901e-14) + 2.58417996561413e-13);
		fConst379 = 6.53947709737567e-20 * fConst0;
		fConst380 = fConst3 * (fConst0 * (-8.63258735389604e-18 - fConst379) + -9.72567351449023e-17);
		fConst381 = 5.86784894739014e-20 * fConst0;
		fConst382 = fConst0 * (fConst0 * (fConst0 * (fConst381 + -5.12285438072112e-16) + -6.87767642075504e-14) + -7.76108746456321e-13);
		fConst383 = 2.95160491394304e-19 * fConst0;
		fConst384 = fConst0 * (fConst0 * (fConst0 * (fConst383 + 2.67064048181331e-15) + 3.79482593534319e-13) + 6.46231565548504e-12);
		fConst385 = 1.8463230738282e-17 * fConst0;
		fConst386 = fConst0 * (fConst0 * (fConst385 + 1.6533269438527e-13) + 1.28277858723121e-11);
		fConst387 = fConst0 * (fConst363 + -3.1996842386608e-16) + 3.26835558922325e-15;
		fConst388 = fConst0 * (-3.2490595714095e-14 - fConst365) + 2.55967413440181e-12;
		fConst389 = fConst3 * (fConst367 + -3.89026940579609e-18);
		fConst390 = fConst0 * (fConst0 * (-2.42268872585805e-15 - fConst369) + 3.10692264109157e-14);
		fConst391 = fConst7 * (6.21913816572845e-20 - fConst371);
		fConst392 = fConst3 * (fConst0 * (fConst373 + 3.86989777105262e-17) + -4.9628722562513e-16);
		fConst393 = fConst0 * (fConst0 * (fConst0 * (fConst375 + -2.16252174019074e-16) + 4.38213044301358e-15) + -1.99261186829939e-14);
		fConst394 = fConst0 * (fConst0 * (1.35192183493901e-14 - fConst377) + -2.58417996561413e-13);
		fConst395 = fConst3 * (fConst0 * (8.63258735389604e-18 - fConst379) + -9.72567351449023e-17);
		fConst396 = fConst0 * (fConst0 * (fConst0 * (fConst381 + 5.12285438072112e-16) + -6.87767642075504e-14) + 7.76108746456321e-13);
		fConst397 = fConst0 * (fConst0 * (fConst0 * (fConst383 + -2.67064048181331e-15) + 3.79482593534319e-13) + -6.46231565548504e-12);
		fConst398 = fConst0 * (fConst0 * (1.6533269438527e-13 - fConst385) + -1.28277858723121e-11);
		fConst399 = 8.18130326224871e-18 * fConst3;
		fConst400 = 6.5367111784465e-15 - fConst399;
		fConst401 = 7.3410535767349e-18 * fConst3;
		fConst402 = fConst401 + 5.11934826880362e-12;
		fConst403 = 6.08067904846417e-19 * fConst7;
		fConst404 = 8.51295066784983e-19 * fConst3;
		fConst405 = fConst0 * (fConst404 + 6.21384528218315e-14);
		fConst406 = 1.94416268896473e-20 * fConst0;
		fConst407 = fConst406 + -1.24382763314569e-19;
		fConst408 = 2.72182776455063e-20 * fConst0;
		fConst409 = -7.73979554210525e-17 - fConst408;
		fConst410 = 1.12634228221944e-19 * fConst0;
		fConst411 = fConst0 * (fConst3 * (4.32504348038148e-16 - fConst410) + -3.98522373659879e-14);
		fConst412 = 3.52281522311187e-18 * fConst3;
		fConst413 = fConst0 * (fConst412 + -5.16835993122826e-13);
		fConst414 = 2.61579083895027e-19 * fConst0;
		fConst415 = fConst7 * (fConst414 + -1.72651747077921e-17);
		fConst416 = 2.34713957895606e-19 * fConst0;
		fConst417 = fConst0 * (fConst3 * (-1.02457087614422e-15 - fConst416) + 1.55221749291264e-12);
		fConst418 = 1.18064196557721e-18 * fConst0;
		fConst419 = fConst0 * (fConst3 * (5.34128096362661e-15 - fConst418) + -1.29246313109701e-11);
		fConst420 = 3.69264614765639e-17 * fConst3;
		fConst421 = fConst0 * (fConst420 + -2.56555717446241e-11);
		fConst422 = 3.3066538877054e-13 * fConst3;
		fConst423 = 2.9162440334471e-20 * fConst24;
		fConst424 = fConst3 * (4.08274164682594e-20 * fConst3 + 9.9257445125026e-16);
		fConst425 = fConst3 * (1.68951342332916e-19 * fConst3 + -8.76426088602715e-15);
		fConst426 = 1.94513470289805e-16 - 3.9236862584254e-19 * fConst3;
		fConst427 = 3.52070936843408e-19 * fConst3 + 1.37553528415101e-13;
		fConst428 = 1.77096294836582e-18 * fConst3 + -7.58965187068638e-13;
		fConst429 = fConst399 + -6.5367111784465e-15;
		fConst430 = -5.11934826880362e-12 - fConst401;
		fConst431 = fConst0 * (-6.21384528218315e-14 - fConst404);
		fConst432 = fConst406 + 1.24382763314569e-19;
		fConst433 = 7.73979554210525e-17 - fConst408;
		fConst434 = fConst0 * (fConst3 * (-4.32504348038148e-16 - fConst410) + 3.98522373659879e-14);
		fConst435 = fConst0 * (5.16835993122826e-13 - fConst412);
		fConst436 = fConst7 * (fConst414 + 1.72651747077921e-17);
		fConst437 = fConst0 * (fConst3 * (1.02457087614422e-15 - fConst416) + -1.55221749291264e-12);
		fConst438 = fConst0 * (fConst3 * (-5.34128096362661e-15 - fConst418) + 1.29246313109701e-11);
		fConst439 = fConst0 * (2.56555717446241e-11 - fConst420);
		fConst440 = 7.37390446187197e-16 * fConst0;
		fConst441 = fConst0 * (2.99972440013567e-14 - fConst440) + -1.67208717956279e-13;
		fConst442 = fConst0 * (fConst440 + -2.99972440013567e-14) + 1.67208717956279e-13;
		fConst443 = 1.65035004622849e-18 * fConst0;
		fConst444 = fConst3 * (fConst0 * (9.46515045560758e-15 - fConst443) + -6.30276541464398e-14);
		fConst445 = 1.03234662466208e-16 * fConst0;
		fConst446 = fConst0 * (fConst0 * (fConst445 + -5.91603840340603e-13) + 3.93943739504993e-12);
		fConst447 = 1.17882146159178e-17 * fConst0;
		fConst448 = fConst7 * (fConst447 + -7.85880974394511e-17);
		fConst449 = fConst0 * (fConst0 * (fConst0 * (2.07004392829875e-15 - fConst447) + -1.0070880757276e-11) + 6.70506959004678e-11);
		fConst450 = 1.47478089237439e-15 * fConst3;
		fConst451 = fConst450 + -3.34417435912558e-13;
		fConst452 = 3.34417435912558e-13 - fConst450;
		fConst453 = 6.60140018491395e-18 * fConst0;
		fConst454 = fConst7 * (fConst453 + -1.89303009112152e-14);
		fConst455 = 2.06469324932415e-16 * fConst3;
		fConst456 = fConst0 * (7.87887479009986e-12 - fConst455);
		fConst457 = 4.71528584636711e-17 * fConst0;
		fConst458 = fConst7 * (1.57176194878902e-16 - fConst457);
		fConst459 = fConst0 * (fConst3 * (fConst457 + -4.1400878565975e-15) + 1.34101391800936e-10);
		fConst460 = 1.2605530829288e-13 - 9.90210027737093e-18 * fConst3;
		fConst461 = 7.07292876955067e-17 * fConst24;
		fConst462 = fConst3 * (2.0141761514552e-11 - 7.07292876955067e-17 * fConst3);
		fConst463 = fConst7 * (fConst453 + 1.89303009112152e-14);
		fConst464 = fConst0 * (fConst455 + -7.87887479009986e-12);
		fConst465 = fConst7 * (-1.57176194878902e-16 - fConst457);
		fConst466 = fConst0 * (fConst3 * (fConst457 + 4.1400878565975e-15) + -1.34101391800936e-10);
		fConst467 = fConst0 * (fConst440 + 2.99972440013567e-14) + 1.67208717956279e-13;
		fConst468 = fConst0 * (-2.99972440013567e-14 - fConst440) + -1.67208717956279e-13;
		fConst469 = fConst3 * (fConst0 * (-9.46515045560758e-15 - fConst443) + -6.30276541464398e-14);
		fConst470 = fConst0 * (fConst0 * (-5.91603840340603e-13 - fConst445) + -3.93943739504993e-12);
		fConst471 = fConst7 * (fConst447 + 7.85880974394511e-17);
		fConst472 = fConst0 * (fConst0 * (fConst0 * (-2.07004392829875e-15 - fConst447) + -1.0070880757276e-11) + -6.70506959004678e-11);
		fConst473 = ftbl2GxGxStudiopreSIG2[199];
		fConst474 = ftbl2GxGxStudiopreSIG2[0];
		fConst475 = ftbl3GxGxStudiopreSIG3[199];
		fConst476 = ftbl3GxGxStudiopreSIG3[0];
		fConst477 = 2.54284690253705e-08 * fConst0;
		fConst478 = fConst0 * (1.69523126835804e-07 - fConst477);
		fConst479 = 5.0856938050741e-08 * fConst3;
		fConst480 = fConst0 * (-1.69523126835804e-07 - fConst477);
		fConst481 = ftbl4GxGxStudiopreSIG4[199];
		fConst482 = ftbl4GxGxStudiopreSIG4[0];
		fConst483 = ftbl5GxGxStudiopreSIG5[199];
		fConst484 = ftbl5GxGxStudiopreSIG5[0];
		fConst485 = 1.0 / (fConst236 * fConst248);
		fConst486 = 1.0 / (fConst237 * fConst241);
		fConst487 = 1.0 - fConst272 / fConst236;
		fConst488 = 1.0 / (fConst273 / fConst236 + 1.0);
		fConst489 = 1.0 / (fConst243 * fConst255);
		fConst490 = 1.0 / (fConst244 * fConst248);
		fConst491 = 1.0 - fConst269 / fConst243;
		fConst492 = 1.0 / (fConst270 / fConst243 + 1.0);
		fConst493 = 1.0 / (fConst250 * fConst262);
		fConst494 = 1.0 / (fConst251 * fConst255);
		fConst495 = 1.0 - fConst266 / fConst250;
		fConst496 = 1.0 / (fConst267 / fConst250 + 1.0);
		fConst497 = 1.0 / (fConst258 * fConst262);
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0);
		fVslider0 = static_cast<FAUSTFLOAT>(0.5);
		fVslider1 = static_cast<FAUSTFLOAT>(0.5);
		fVslider2 = static_cast<FAUSTFLOAT>(0.5);
		fVslider3 = static_cast<FAUSTFLOAT>(0.5);
		fVslider4 = static_cast<FAUSTFLOAT>(0.5);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fRec1[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			fRec2[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec3[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fRec4[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fVec0[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fRec13[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 3; l6 = faust_wrap_add(l6, 1)) {
			fRec12[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fVec1[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fRec11[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 3; l9 = faust_wrap_add(l9, 1)) {
			fRec10[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fVec2[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fRec9[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 3; l12 = faust_wrap_add(l12, 1)) {
			fRec8[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fVec3[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec7[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 3; l15 = faust_wrap_add(l15, 1)) {
			fRec6[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 6; l16 = faust_wrap_add(l16, 1)) {
			fRec5[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 5; l17 = faust_wrap_add(l17, 1)) {
			fRec14[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 3; l18 = faust_wrap_add(l18, 1)) {
			fRec0[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fRec15[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec19[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 3; l21 = faust_wrap_add(l21, 1)) {
			fRec18[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 6; l22 = faust_wrap_add(l22, 1)) {
			fRec17[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 5; l23 = faust_wrap_add(l23, 1)) {
			fRec20[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 3; l24 = faust_wrap_add(l24, 1)) {
			fRec16[l24] = 0.0;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec25[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 3; l26 = faust_wrap_add(l26, 1)) {
			fRec24[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 3; l27 = faust_wrap_add(l27, 1)) {
			fRec23[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 6; l28 = faust_wrap_add(l28, 1)) {
			fRec22[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 5; l29 = faust_wrap_add(l29, 1)) {
			fRec26[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 3; l30 = faust_wrap_add(l30, 1)) {
			fRec21[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fRec32[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 3; l32 = faust_wrap_add(l32, 1)) {
			fRec31[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 3; l33 = faust_wrap_add(l33, 1)) {
			fRec30[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 3; l34 = faust_wrap_add(l34, 1)) {
			fRec29[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 6; l35 = faust_wrap_add(l35, 1)) {
			fRec28[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 5; l36 = faust_wrap_add(l36, 1)) {
			fRec33[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 3; l37 = faust_wrap_add(l37, 1)) {
			fRec27[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fRec40[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 3; l39 = faust_wrap_add(l39, 1)) {
			fRec39[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 3; l40 = faust_wrap_add(l40, 1)) {
			fRec38[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 3; l41 = faust_wrap_add(l41, 1)) {
			fRec37[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 3; l42 = faust_wrap_add(l42, 1)) {
			fRec36[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 6; l43 = faust_wrap_add(l43, 1)) {
			fRec35[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 5; l44 = faust_wrap_add(l44, 1)) {
			fRec41[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 3; l45 = faust_wrap_add(l45, 1)) {
			fRec34[l45] = 0.0;
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
	
	virtual GxGxStudiopre* clone() {
		return new GxGxStudiopre(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("gx-gx-studiopre");
		ui_interface->declare(&fVslider0, "name", "Bass_L");
		ui_interface->addVerticalSlider("Bass_L", &fVslider0, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider4, "name", "Master_L");
		ui_interface->addVerticalSlider("Master_L", &fVslider4, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider1, "name", "Middle_L");
		ui_interface->addVerticalSlider("Middle_L", &fVslider1, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider3, "name", "Treble_L");
		ui_interface->addVerticalSlider("Treble_L", &fVslider3, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fVslider2, "name", "Volume_L");
		ui_interface->addVerticalSlider("Volume_L", &fVslider2, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addCheckButton("bright_L", &fCheckbox0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		int iSlow0 = static_cast<int>(static_cast<double>(fCheckbox0));
		double fSlow1 = 0.00036676987543879196 * (std::exp(3.0 * static_cast<double>(fVslider0)) + -1.0);
		double fSlow2 = 0.007000000000000006 * static_cast<double>(fVslider1);
		double fSlow3 = 0.00036676987543879196 * (std::exp(3.0 * static_cast<double>(fVslider2)) + -1.0);
		double fSlow4 = 0.007000000000000006 * (1.0 - static_cast<double>(fVslider3));
		double fSlow5 = 0.00036676987543879196 * (std::exp(3.0 * static_cast<double>(fVslider4)) + -1.0);
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			fRec1[0] = fSlow1 + 0.993 * fRec1[1];
			fRec2[0] = fSlow2 + 0.993 * fRec2[1];
			fRec3[0] = fSlow3 + 0.993 * fRec3[1];
			fRec4[0] = fSlow4 + 0.993 * fRec4[1];
			double fTemp0 = fConst55 + fRec1[0] * (fConst53 + fRec4[0] * (fConst51 + fConst50 * fRec4[0]) + 6.40068780224617e-12) + fRec2[0] * (fConst49 + fRec1[0] * (fConst47 + fRec4[0] * (fConst45 + fConst44 * fRec4[0])) + fRec4[0] * (fConst43 + fConst42 * fRec4[0]) + 2.56027512089847e-13) + fRec4[0] * (fConst0 * (fConst41 + fConst40 * fRec4[0]) + -6.40068780224617e-12) + fRec3[0] * (fConst39 + fRec1[0] * (fConst37 + fRec4[0] * (fConst35 + fConst33 * fRec4[0])) + fRec2[0] * (fConst31 + fRec1[0] * (fConst29 + fRec4[0] * (fConst27 + fConst25 * fRec4[0])) + fRec4[0] * (fConst22 + fConst20 * fRec4[0])) + fRec4[0] * (fConst18 + fConst16 * fRec4[0]) + fRec3[0] * (fConst14 + fConst12 * fRec1[0] + fRec2[0] * (fConst10 + fConst8 * fRec1[0]))) + 3.20034390112309e-11;
			double fTemp1 = fConst83 + fRec1[0] * (fConst82 + fRec4[0] * (fConst81 + fConst80 * fRec4[0]) + 6.40068780224617e-12) + fRec2[0] * (fConst79 + fRec1[0] * (fConst78 + fRec4[0] * (fConst77 + fConst76 * fRec4[0])) + fRec4[0] * (fConst75 + fConst74 * fRec4[0]) + 2.56027512089847e-13) + fRec4[0] * (fConst0 * (fConst73 + fConst72 * fRec4[0]) + -6.40068780224617e-12) + fRec3[0] * (fConst71 + fRec1[0] * (fConst70 + fRec4[0] * (fConst69 + fConst68 * fRec4[0])) + fRec2[0] * (fConst67 + fRec1[0] * (fConst66 + fRec4[0] * (fConst65 + fConst64 * fRec4[0])) + fRec4[0] * (fConst63 + fConst62 * fRec4[0])) + fRec4[0] * (fConst61 + fConst60 * fRec4[0]) + fRec3[0] * (fConst59 + fConst58 * fRec1[0] + fRec2[0] * (fConst57 + fConst56 * fRec1[0]))) + 3.20034390112309e-11;
			double fTemp2 = fConst131 + fRec1[0] * (fConst129 + fRec4[0] * (fConst127 + fConst126 * fRec4[0]) + 3.20034390112309e-11) + fRec2[0] * (fConst125 + fRec1[0] * (fConst123 + fRec4[0] * (fConst121 + fConst120 * fRec4[0])) + fRec4[0] * (fConst119 + fConst118 * fRec4[0]) + 1.28013756044923e-12) + fRec4[0] * (fConst0 * (fConst117 + fConst116 * fRec4[0]) + -3.20034390112309e-11) + fRec3[0] * (fConst115 + fRec1[0] * (fConst113 + fRec4[0] * (fConst111 + fConst109 * fRec4[0])) + fRec2[0] * (fConst107 + fRec1[0] * (fConst105 + fRec4[0] * (fConst103 + fConst101 * fRec4[0])) + fRec4[0] * (fConst99 + fConst97 * fRec4[0])) + fRec4[0] * (fConst95 + fConst93 * fRec4[0]) + fRec3[0] * (fConst91 + fConst89 * fRec1[0] + fRec2[0] * (fConst87 + fConst85 * fRec1[0]))) + 1.60017195056154e-10;
			double fTemp3 = fConst179 + fRec1[0] * (fConst177 + fRec4[0] * (fConst175 + fConst174 * fRec4[0]) + 6.40068780224617e-11) + fRec2[0] * (fConst173 + fRec1[0] * (fConst171 + fRec4[0] * (fConst169 + fConst168 * fRec4[0])) + fRec4[0] * (fConst167 + fConst166 * fRec4[0]) + 2.56027512089847e-12) + fRec4[0] * (fConst0 * (fConst165 + fConst164 * fRec4[0]) + -6.40068780224617e-11) + fRec3[0] * (fConst163 + fRec1[0] * (fConst161 + fRec4[0] * (fConst159 + fConst157 * fRec4[0])) + fRec2[0] * (fConst155 + fRec1[0] * (fConst153 + fRec4[0] * (fConst151 + fConst149 * fRec4[0])) + fRec4[0] * (fConst147 + fConst145 * fRec4[0])) + fRec4[0] * (fConst143 + fConst141 * fRec4[0]) + fRec3[0] * (fConst139 + fConst137 * fRec1[0] + fRec2[0] * (fConst135 + fConst133 * fRec1[0]))) + 3.20034390112308e-10;
			double fTemp4 = fConst207 + fRec1[0] * (fConst206 + fRec4[0] * (fConst205 + fConst204 * fRec4[0]) + 6.40068780224617e-11) + fRec2[0] * (fConst203 + fRec1[0] * (fConst202 + fRec4[0] * (fConst201 + fConst200 * fRec4[0])) + fRec4[0] * (fConst199 + fConst198 * fRec4[0]) + 2.56027512089847e-12) + fRec4[0] * (fConst0 * (fConst197 + fConst196 * fRec4[0]) + -6.40068780224617e-11) + fRec3[0] * (fConst195 + fRec1[0] * (fConst194 + fRec4[0] * (fConst193 + fConst192 * fRec4[0])) + fRec2[0] * (fConst191 + fRec1[0] * (fConst190 + fRec4[0] * (fConst189 + fConst188 * fRec4[0])) + fRec4[0] * (fConst187 + fConst186 * fRec4[0])) + fRec4[0] * (fConst185 + fConst184 * fRec4[0]) + fRec3[0] * (fConst183 + fConst182 * fRec1[0] + fRec2[0] * (fConst181 + fConst180 * fRec1[0]))) + 3.20034390112308e-10;
			double fTemp5 = fConst235 + fRec1[0] * (fConst234 + fRec4[0] * (fConst233 + fConst232 * fRec4[0]) + 3.20034390112309e-11) + fRec2[0] * (fConst231 + fRec1[0] * (fConst230 + fRec4[0] * (fConst229 + fConst228 * fRec4[0])) + fRec4[0] * (fConst227 + fConst226 * fRec4[0]) + 1.28013756044923e-12) + fRec4[0] * (fConst0 * (fConst225 + fConst224 * fRec4[0]) + -3.20034390112309e-11) + fRec3[0] * (fConst223 + fRec1[0] * (fConst222 + fRec4[0] * (fConst221 + fConst220 * fRec4[0])) + fRec2[0] * (fConst219 + fRec1[0] * (fConst218 + fRec4[0] * (fConst217 + fConst216 * fRec4[0])) + fRec4[0] * (fConst215 + fConst214 * fRec4[0])) + fRec4[0] * (fConst213 + fConst212 * fRec4[0]) + fRec3[0] * (fConst211 + fConst210 * fRec1[0] + fRec2[0] * (fConst209 + fConst208 * fRec1[0]))) + 1.60017195056154e-10;
			double fTemp6 = static_cast<double>(input0[i0]);
			fVec0[0] = fTemp6;
			fRec13[0] = -(fConst265 * (fConst264 * fRec13[1] - (fTemp6 + fVec0[1])));
			fRec12[0] = fRec13[0] - fConst263 * (fConst261 * fRec12[2] + fConst259 * fRec12[1]);
			double fTemp7 = fRec12[2] + fRec12[0] + 2.0 * fRec12[1];
			fVec1[0] = fTemp7;
			fRec11[0] = -(fConst268 * (fConst266 * fRec11[1] - fConst263 * (fTemp7 + fVec1[1])));
			fRec10[0] = fRec11[0] - fConst256 * (fConst254 * fRec10[2] + fConst252 * fRec10[1]);
			double fTemp8 = fRec10[2] + fRec10[0] + 2.0 * fRec10[1];
			fVec2[0] = fTemp8;
			fRec9[0] = -(fConst271 * (fConst269 * fRec9[1] - fConst256 * (fTemp8 + fVec2[1])));
			fRec8[0] = fRec9[0] - fConst249 * (fConst247 * fRec8[2] + fConst245 * fRec8[1]);
			double fTemp9 = fRec8[2] + fRec8[0] + 2.0 * fRec8[1];
			fVec3[0] = fTemp9;
			fRec7[0] = -(fConst274 * (fConst272 * fRec7[1] - fConst249 * (fTemp9 + fVec3[1])));
			fRec6[0] = fRec7[0] - fConst242 * (fConst240 * fRec6[2] + fConst238 * fRec6[1]);
			double fTemp10 = fConst242 * (fRec6[2] + fRec6[0] + 2.0 * fRec6[1]);
			fRec5[0] = fTemp10 - (fTemp5 * fRec5[1] + fTemp4 * fRec5[2] + fTemp3 * fRec5[3] + fTemp2 * fRec5[4] + fTemp1 * fRec5[5]) / fTemp0;
			double fTemp11 = fConst0 * (fConst290 + fConst289 * fRec4[0]) + fRec1[0] * (fConst288 + fConst287 * fRec4[0]) + fRec2[0] * (fConst286 + fConst285 * fRec1[0]) + fRec3[0] * (fRec1[0] * (fConst284 + fConst283 * fRec4[0]) + fRec2[0] * (fConst281 + fConst279 * fRec1[0]) + fConst3 * (fConst277 + fConst276 * fRec4[0]));
			double fTemp12 = fConst0 * (fConst306 + fConst305 * fRec4[0]) + fRec1[0] * (fConst304 + fConst303 * fRec4[0]) + fRec2[0] * (fConst302 + fConst301 * fRec1[0]) + fRec3[0] * (fRec1[0] * (fConst300 + fConst299 * fRec4[0]) + fRec2[0] * (fConst297 + fConst295 * fRec1[0]) + fConst3 * (fConst293 + fConst292 * fRec4[0]));
			double fTemp13 = fConst0 * (fConst322 + fConst321 * fRec4[0]) + fRec1[0] * (fConst320 + fConst319 * fRec4[0]) + fRec2[0] * (fConst318 + fConst317 * fRec1[0]) + fRec3[0] * (fRec1[0] * (fConst316 + fConst315 * fRec4[0]) + fRec2[0] * (fConst313 + fConst311 * fRec1[0]) + fConst3 * (fConst309 + fConst308 * fRec4[0]));
			double fTemp14 = fConst0 * (fConst334 + fConst333 * fRec4[0]) + fRec1[0] * (fConst332 + fConst331 * fRec4[0]) + fRec2[0] * (fConst330 + fConst329 * fRec1[0]) + fRec3[0] * (fRec1[0] * (fConst328 + fConst327 * fRec4[0]) + fRec2[0] * (fConst326 + fConst325 * fRec1[0]) + fConst3 * (fConst324 + fConst323 * fRec4[0]));
			double fTemp15 = fConst0 * (fConst346 + fConst345 * fRec4[0]) + fRec1[0] * (fConst344 + fConst343 * fRec4[0]) + fRec2[0] * (fConst342 + fConst341 * fRec1[0]) + fRec3[0] * (fRec1[0] * (fConst340 + fConst339 * fRec4[0]) + fRec2[0] * (fConst338 + fConst337 * fRec1[0]) + fConst3 * (fConst336 + fConst335 * fRec4[0]));
			double fTemp16 = fConst0 * (fConst358 + fConst357 * fRec4[0]) + fRec1[0] * (fConst356 + fConst355 * fRec4[0]) + fRec2[0] * (fConst354 + fConst353 * fRec1[0]) + fRec3[0] * (fRec1[0] * (fConst352 + fConst351 * fRec4[0]) + fRec2[0] * (fConst350 + fConst349 * fRec1[0]) + fConst3 * (fConst348 + fConst347 * fRec4[0]));
			double fTemp17 = fRec3[0] * (fRec5[0] * fTemp16 + fTemp15 * fRec5[1] + fTemp14 * fRec5[2] + fTemp13 * fRec5[3] + fTemp12 * fRec5[4] + fTemp11 * fRec5[5]) / fTemp0;
			double fTemp18 = 99.5 * std::fabs(fTemp17);
			double fTemp19 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp18) | std::isinf(fTemp18)) ? 0.0 : fTemp18)));
			int iTemp20 = static_cast<int>(fTemp19);
			int iTemp21 = iTemp20 < 0;
			int iTemp22 = iTemp20 >= 199;
			int iTemp23 = std::max<int>(0, std::min<int>(198, iTemp20));
			int iTemp24 = faust_wrap_add(iTemp23, 1);
			double fTemp25 = static_cast<double>(iTemp23);
			double fTemp26 = fTemp19 - fTemp25;
			double fTemp27 = fTemp25 + (1.0 - fTemp19);
			double fTemp28 = fConst386 + fRec1[0] * (fConst384 + fRec4[0] * (fConst382 + fConst380 * fRec4[0]) + 2.61733091315125e-11) + fRec2[0] * (fConst378 + fRec1[0] * (fConst376 + fRec4[0] * (fConst374 + fConst372 * fRec4[0])) + fRec4[0] * (fConst370 + fConst368 * fRec4[0]) + 1.0469323652605e-12) + fRec4[0] * (fConst0 * (fConst366 + fConst364 * fRec4[0]) + -2.61733091315125e-11) + 1.30866545657562e-10;
			double fTemp29 = fConst398 + fRec1[0] * (fConst397 + fRec4[0] * (fConst396 + fConst395 * fRec4[0]) + 2.61733091315125e-11) + fRec2[0] * (fConst394 + fRec1[0] * (fConst393 + fRec4[0] * (fConst392 + fConst391 * fRec4[0])) + fRec4[0] * (fConst390 + fConst389 * fRec4[0]) + 1.0469323652605e-12) + fRec4[0] * (fConst0 * (fConst388 + fConst387 * fRec4[0]) + -2.61733091315125e-11) + 1.30866545657562e-10;
			double fTemp30 = fConst403 * fRec4[0];
			double fTemp31 = fConst421 + fRec1[0] * (fConst419 + fRec4[0] * (fConst417 + fConst415 * fRec4[0]) + 1.0469323652605e-10) + fRec2[0] * (fConst413 + fRec1[0] * (fConst411 + fConst7 * fRec4[0] * (fConst409 + fConst407 * fRec4[0])) + fRec4[0] * (fConst405 - fTemp30) + 4.187729461042e-12) + fRec4[0] * (fConst0 * (fConst402 + fConst400 * fRec4[0]) + -1.0469323652605e-10) + 5.2346618263025e-10;
			double fTemp32 = fRec1[0] * (fConst3 * (fConst428 + fRec4[0] * (fConst427 + fConst426 * fRec4[0])) + 1.57039854789075e-10) + fRec2[0] * (fRec1[0] * (fConst425 + fRec4[0] * (fConst424 - fConst423 * fRec4[0])) + fConst3 * (fRec4[0] * (7.78053881159219e-18 * fRec4[0] + 4.84537745171611e-15) + -2.70384366987801e-14) + 6.281594191563e-12) + fRec4[0] * (fConst3 * (6.3993684773216e-16 * fRec4[0] + 6.498119142819e-14) + -1.57039854789075e-10) + 7.85199273945375e-10 - fConst422;
			double fTemp33 = fConst439 + fRec1[0] * (fConst438 + fRec4[0] * (fConst437 + fConst436 * fRec4[0]) + 1.0469323652605e-10) + fRec2[0] * (fConst435 + fRec1[0] * (fConst434 + fConst7 * fRec4[0] * (fConst433 + fConst432 * fRec4[0])) + fRec4[0] * (fConst431 + fTemp30) + 4.187729461042e-12) + fRec4[0] * (fConst0 * (fConst430 + fConst429 * fRec4[0]) + -1.0469323652605e-10) + 5.2346618263025e-10;
			fRec14[0] = fTemp10 - (fTemp33 * fRec14[1] + fTemp32 * fRec14[2] + fTemp31 * fRec14[3] + fTemp29 * fRec14[4]) / fTemp28;
			double fTemp34 = fRec1[0] * (fConst449 + fConst448 * fRec4[0]) + fRec2[0] * (fConst446 + fConst444 * fRec1[0]) + fConst0 * (fConst442 + fConst441 * fRec4[0]);
			double fTemp35 = fRec1[0] * (fConst459 + fConst458 * fRec4[0]) + fRec2[0] * (fConst456 + fConst454 * fRec1[0]) + fConst0 * (fConst452 + fConst451 * fRec4[0]);
			double fTemp36 = fRec1[0] * (fConst462 + fConst461 * fRec4[0]) + fConst3 * (fRec2[0] * (fConst460 * fRec1[0] + 1.18320768068121e-12) - 5.99944880027134e-14 * fRec4[0] + 5.99944880027134e-14);
			double fTemp37 = fRec1[0] * (fConst466 + fConst465 * fRec4[0]) + fRec2[0] * (fConst464 + fConst463 * fRec1[0]) + fConst0 * (fConst451 + fConst452 * fRec4[0]);
			double fTemp38 = fRec1[0] * (fConst472 + fConst471 * fRec4[0]) + fRec2[0] * (fConst470 + fConst469 * fRec1[0]) + fConst0 * (fConst468 + fConst467 * fRec4[0]);
			double fTemp39 = fRec3[0] * (fRec14[0] * fTemp38 + fTemp37 * fRec14[1] + fTemp36 * fRec14[2] + fTemp35 * fRec14[3] + fTemp34 * fRec14[4]) / fTemp28;
			double fTemp40 = 99.5 * std::fabs(fTemp39);
			double fTemp41 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp40) | std::isinf(fTemp40)) ? 0.0 : fTemp40)));
			int iTemp42 = static_cast<int>(fTemp41);
			int iTemp43 = iTemp42 < 0;
			int iTemp44 = iTemp42 >= 199;
			int iTemp45 = std::max<int>(0, std::min<int>(198, iTemp42));
			int iTemp46 = faust_wrap_add(iTemp45, 1);
			double fTemp47 = static_cast<double>(iTemp45);
			double fTemp48 = fTemp41 - fTemp47;
			double fTemp49 = fTemp47 + (1.0 - fTemp41);
			fRec0[0] = ((iSlow0) ? ((fTemp39 < 0.0) ? copysign(((iTemp43) ? fConst476 : ((iTemp44) ? fConst475 : fTemp49 * ftbl3GxGxStudiopreSIG3[iTemp45] + fTemp48 * ftbl3GxGxStudiopreSIG3[iTemp46])), fTemp39) : copysign(((iTemp43) ? fConst474 : ((iTemp44) ? fConst473 : ftbl2GxGxStudiopreSIG2[iTemp45] * fTemp49 + fTemp48 * ftbl2GxGxStudiopreSIG2[iTemp46])), fTemp39)) : ((fTemp17 < 0.0) ? copysign(((iTemp21) ? fConst362 : ((iTemp22) ? fConst361 : fTemp27 * ftbl1GxGxStudiopreSIG1[iTemp23] + fTemp26 * ftbl1GxGxStudiopreSIG1[iTemp24])), fTemp17) : copysign(((iTemp21) ? fConst360 : ((iTemp22) ? fConst359 : ftbl0GxGxStudiopreSIG0[iTemp23] * fTemp27 + fTemp26 * ftbl0GxGxStudiopreSIG0[iTemp24])), fTemp17))) - fConst5 * (fConst4 * fRec0[1] + fConst2 * fRec0[2]);
			fRec15[0] = fSlow5 + 0.993 * fRec15[1];
			double fTemp50 = fConst5 * fRec15[0] * (fConst480 * fRec0[0] + fConst479 * fRec0[1] + fConst478 * fRec0[2]);
			double fTemp51 = 16.5833 * std::fabs(fTemp50);
			double fTemp52 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp51) | std::isinf(fTemp51)) ? 0.0 : fTemp51)));
			int iTemp53 = static_cast<int>(fTemp52);
			int iTemp54 = iTemp53 < 0;
			int iTemp55 = iTemp53 >= 199;
			int iTemp56 = std::max<int>(0, std::min<int>(198, iTemp53));
			int iTemp57 = faust_wrap_add(iTemp56, 1);
			double fTemp58 = static_cast<double>(iTemp56);
			double fTemp59 = fTemp52 - fTemp58;
			double fTemp60 = fTemp58 + (1.0 - fTemp52);
			fRec19[0] = -(fConst274 * (fConst272 * fRec19[1] - fConst485 * (fTemp9 - fVec3[1])));
			fRec18[0] = fRec19[0] - fConst242 * (fConst240 * fRec18[2] + fConst238 * fRec18[1]);
			double fTemp61 = fConst486 * (fRec18[2] + (fRec18[0] - 2.0 * fRec18[1]));
			fRec17[0] = fTemp61 - (fTemp5 * fRec17[1] + fTemp4 * fRec17[2] + fTemp3 * fRec17[3] + fTemp2 * fRec17[4] + fTemp1 * fRec17[5]) / fTemp0;
			double fTemp62 = fRec3[0] * (fRec17[0] * fTemp16 + fTemp15 * fRec17[1] + fTemp14 * fRec17[2] + fTemp13 * fRec17[3] + fTemp12 * fRec17[4] + fTemp11 * fRec17[5]) / fTemp0;
			double fTemp63 = 99.5 * std::fabs(fTemp62);
			double fTemp64 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp63) | std::isinf(fTemp63)) ? 0.0 : fTemp63)));
			int iTemp65 = static_cast<int>(fTemp64);
			int iTemp66 = iTemp65 < 0;
			int iTemp67 = iTemp65 >= 199;
			int iTemp68 = std::max<int>(0, std::min<int>(198, iTemp65));
			int iTemp69 = faust_wrap_add(iTemp68, 1);
			double fTemp70 = static_cast<double>(iTemp68);
			double fTemp71 = fTemp64 - fTemp70;
			double fTemp72 = fTemp70 + (1.0 - fTemp64);
			fRec20[0] = fTemp61 - (fTemp33 * fRec20[1] + fTemp32 * fRec20[2] + fTemp31 * fRec20[3] + fTemp29 * fRec20[4]) / fTemp28;
			double fTemp73 = fRec3[0] * (fRec20[0] * fTemp38 + fTemp37 * fRec20[1] + fTemp36 * fRec20[2] + fTemp35 * fRec20[3] + fTemp34 * fRec20[4]) / fTemp28;
			double fTemp74 = 99.5 * std::fabs(fTemp73);
			double fTemp75 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp74) | std::isinf(fTemp74)) ? 0.0 : fTemp74)));
			int iTemp76 = static_cast<int>(fTemp75);
			int iTemp77 = iTemp76 < 0;
			int iTemp78 = iTemp76 >= 199;
			int iTemp79 = std::max<int>(0, std::min<int>(198, iTemp76));
			int iTemp80 = faust_wrap_add(iTemp79, 1);
			double fTemp81 = static_cast<double>(iTemp79);
			double fTemp82 = fTemp75 - fTemp81;
			double fTemp83 = fTemp81 + (1.0 - fTemp75);
			fRec16[0] = ((iSlow0) ? ((fTemp73 < 0.0) ? copysign(((iTemp77) ? fConst476 : ((iTemp78) ? fConst475 : fTemp83 * ftbl3GxGxStudiopreSIG3[iTemp79] + fTemp82 * ftbl3GxGxStudiopreSIG3[iTemp80])), fTemp73) : copysign(((iTemp77) ? fConst474 : ((iTemp78) ? fConst473 : ftbl2GxGxStudiopreSIG2[iTemp79] * fTemp83 + fTemp82 * ftbl2GxGxStudiopreSIG2[iTemp80])), fTemp73)) : ((fTemp62 < 0.0) ? copysign(((iTemp66) ? fConst362 : ((iTemp67) ? fConst361 : fTemp72 * ftbl1GxGxStudiopreSIG1[iTemp68] + fTemp71 * ftbl1GxGxStudiopreSIG1[iTemp69])), fTemp62) : copysign(((iTemp66) ? fConst360 : ((iTemp67) ? fConst359 : ftbl0GxGxStudiopreSIG0[iTemp68] * fTemp72 + fTemp71 * ftbl0GxGxStudiopreSIG0[iTemp69])), fTemp62))) - fConst5 * (fConst4 * fRec16[1] + fConst2 * fRec16[2]);
			double fTemp84 = fConst5 * fRec15[0] * (fConst480 * fRec16[0] + fConst479 * fRec16[1] + fConst478 * fRec16[2]);
			double fTemp85 = 16.5833 * std::fabs(fTemp84);
			double fTemp86 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp85) | std::isinf(fTemp85)) ? 0.0 : fTemp85)));
			int iTemp87 = static_cast<int>(fTemp86);
			int iTemp88 = iTemp87 < 0;
			int iTemp89 = iTemp87 >= 199;
			int iTemp90 = std::max<int>(0, std::min<int>(198, iTemp87));
			int iTemp91 = faust_wrap_add(iTemp90, 1);
			double fTemp92 = static_cast<double>(iTemp90);
			double fTemp93 = fTemp86 - fTemp92;
			double fTemp94 = fTemp92 + (1.0 - fTemp86);
			double fTemp95 = fConst238 * fRec23[1];
			fRec25[0] = -(fConst271 * (fConst269 * fRec25[1] - fConst489 * (fTemp8 - fVec2[1])));
			fRec24[0] = fRec25[0] - fConst249 * (fConst247 * fRec24[2] + fConst245 * fRec24[1]);
			fRec23[0] = fConst490 * (fRec24[2] + (fRec24[0] - 2.0 * fRec24[1])) - fConst488 * (fConst487 * fRec23[2] + fTemp95);
			double fTemp96 = fRec23[2] + fConst488 * (fTemp95 + fConst487 * fRec23[0]);
			fRec22[0] = fTemp96 - (fTemp5 * fRec22[1] + fTemp4 * fRec22[2] + fTemp3 * fRec22[3] + fTemp2 * fRec22[4] + fTemp1 * fRec22[5]) / fTemp0;
			double fTemp97 = fRec3[0] * (fRec22[0] * fTemp16 + fTemp15 * fRec22[1] + fTemp14 * fRec22[2] + fTemp13 * fRec22[3] + fTemp12 * fRec22[4] + fTemp11 * fRec22[5]) / fTemp0;
			double fTemp98 = 99.5 * std::fabs(fTemp97);
			double fTemp99 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp98) | std::isinf(fTemp98)) ? 0.0 : fTemp98)));
			int iTemp100 = static_cast<int>(fTemp99);
			int iTemp101 = iTemp100 < 0;
			int iTemp102 = iTemp100 >= 199;
			int iTemp103 = std::max<int>(0, std::min<int>(198, iTemp100));
			int iTemp104 = faust_wrap_add(iTemp103, 1);
			double fTemp105 = static_cast<double>(iTemp103);
			double fTemp106 = fTemp99 - fTemp105;
			double fTemp107 = fTemp105 + (1.0 - fTemp99);
			fRec26[0] = fTemp96 - (fTemp33 * fRec26[1] + fTemp32 * fRec26[2] + fTemp31 * fRec26[3] + fTemp29 * fRec26[4]) / fTemp28;
			double fTemp108 = fRec3[0] * (fRec26[0] * fTemp38 + fTemp37 * fRec26[1] + fTemp36 * fRec26[2] + fTemp35 * fRec26[3] + fTemp34 * fRec26[4]) / fTemp28;
			double fTemp109 = 99.5 * std::fabs(fTemp108);
			double fTemp110 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp109) | std::isinf(fTemp109)) ? 0.0 : fTemp109)));
			int iTemp111 = static_cast<int>(fTemp110);
			int iTemp112 = iTemp111 < 0;
			int iTemp113 = iTemp111 >= 199;
			int iTemp114 = std::max<int>(0, std::min<int>(198, iTemp111));
			int iTemp115 = faust_wrap_add(iTemp114, 1);
			double fTemp116 = static_cast<double>(iTemp114);
			double fTemp117 = fTemp110 - fTemp116;
			double fTemp118 = fTemp116 + (1.0 - fTemp110);
			fRec21[0] = ((iSlow0) ? ((fTemp108 < 0.0) ? copysign(((iTemp112) ? fConst476 : ((iTemp113) ? fConst475 : fTemp118 * ftbl3GxGxStudiopreSIG3[iTemp114] + fTemp117 * ftbl3GxGxStudiopreSIG3[iTemp115])), fTemp108) : copysign(((iTemp112) ? fConst474 : ((iTemp113) ? fConst473 : ftbl2GxGxStudiopreSIG2[iTemp114] * fTemp118 + fTemp117 * ftbl2GxGxStudiopreSIG2[iTemp115])), fTemp108)) : ((fTemp97 < 0.0) ? copysign(((iTemp101) ? fConst362 : ((iTemp102) ? fConst361 : fTemp107 * ftbl1GxGxStudiopreSIG1[iTemp103] + fTemp106 * ftbl1GxGxStudiopreSIG1[iTemp104])), fTemp97) : copysign(((iTemp101) ? fConst360 : ((iTemp102) ? fConst359 : ftbl0GxGxStudiopreSIG0[iTemp103] * fTemp107 + fTemp106 * ftbl0GxGxStudiopreSIG0[iTemp104])), fTemp97))) - fConst5 * (fConst4 * fRec21[1] + fConst2 * fRec21[2]);
			double fTemp119 = fConst5 * fRec15[0] * (fConst480 * fRec21[0] + fConst479 * fRec21[1] + fConst478 * fRec21[2]);
			double fTemp120 = 16.5833 * std::fabs(fTemp119);
			double fTemp121 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp120) | std::isinf(fTemp120)) ? 0.0 : fTemp120)));
			int iTemp122 = static_cast<int>(fTemp121);
			int iTemp123 = iTemp122 < 0;
			int iTemp124 = iTemp122 >= 199;
			int iTemp125 = std::max<int>(0, std::min<int>(198, iTemp122));
			int iTemp126 = faust_wrap_add(iTemp125, 1);
			double fTemp127 = static_cast<double>(iTemp125);
			double fTemp128 = fTemp121 - fTemp127;
			double fTemp129 = fTemp127 + (1.0 - fTemp121);
			double fTemp130 = fConst238 * fRec29[1];
			double fTemp131 = fConst245 * fRec30[1];
			fRec32[0] = -(fConst268 * (fConst266 * fRec32[1] - fConst493 * (fTemp7 - fVec1[1])));
			fRec31[0] = fRec32[0] - fConst256 * (fConst254 * fRec31[2] + fConst252 * fRec31[1]);
			fRec30[0] = fConst494 * (fRec31[2] + (fRec31[0] - 2.0 * fRec31[1])) - fConst492 * (fConst491 * fRec30[2] + fTemp131);
			fRec29[0] = fRec30[2] + fConst492 * (fTemp131 + fConst491 * fRec30[0]) - fConst488 * (fConst487 * fRec29[2] + fTemp130);
			double fTemp132 = fRec29[2] + fConst488 * (fTemp130 + fConst487 * fRec29[0]);
			fRec28[0] = fTemp132 - (fTemp5 * fRec28[1] + fTemp4 * fRec28[2] + fTemp3 * fRec28[3] + fTemp2 * fRec28[4] + fTemp1 * fRec28[5]) / fTemp0;
			double fTemp133 = fRec3[0] * (fRec28[0] * fTemp16 + fTemp15 * fRec28[1] + fTemp14 * fRec28[2] + fTemp13 * fRec28[3] + fTemp12 * fRec28[4] + fTemp11 * fRec28[5]) / fTemp0;
			double fTemp134 = 99.5 * std::fabs(fTemp133);
			double fTemp135 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp134) | std::isinf(fTemp134)) ? 0.0 : fTemp134)));
			int iTemp136 = static_cast<int>(fTemp135);
			int iTemp137 = iTemp136 < 0;
			int iTemp138 = iTemp136 >= 199;
			int iTemp139 = std::max<int>(0, std::min<int>(198, iTemp136));
			int iTemp140 = faust_wrap_add(iTemp139, 1);
			double fTemp141 = static_cast<double>(iTemp139);
			double fTemp142 = fTemp135 - fTemp141;
			double fTemp143 = fTemp141 + (1.0 - fTemp135);
			fRec33[0] = fTemp132 - (fTemp33 * fRec33[1] + fTemp32 * fRec33[2] + fTemp31 * fRec33[3] + fTemp29 * fRec33[4]) / fTemp28;
			double fTemp144 = fRec3[0] * (fRec33[0] * fTemp38 + fTemp37 * fRec33[1] + fTemp36 * fRec33[2] + fTemp35 * fRec33[3] + fTemp34 * fRec33[4]) / fTemp28;
			double fTemp145 = 99.5 * std::fabs(fTemp144);
			double fTemp146 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp145) | std::isinf(fTemp145)) ? 0.0 : fTemp145)));
			int iTemp147 = static_cast<int>(fTemp146);
			int iTemp148 = iTemp147 < 0;
			int iTemp149 = iTemp147 >= 199;
			int iTemp150 = std::max<int>(0, std::min<int>(198, iTemp147));
			int iTemp151 = faust_wrap_add(iTemp150, 1);
			double fTemp152 = static_cast<double>(iTemp150);
			double fTemp153 = fTemp146 - fTemp152;
			double fTemp154 = fTemp152 + (1.0 - fTemp146);
			fRec27[0] = ((iSlow0) ? ((fTemp144 < 0.0) ? copysign(((iTemp148) ? fConst476 : ((iTemp149) ? fConst475 : fTemp154 * ftbl3GxGxStudiopreSIG3[iTemp150] + fTemp153 * ftbl3GxGxStudiopreSIG3[iTemp151])), fTemp144) : copysign(((iTemp148) ? fConst474 : ((iTemp149) ? fConst473 : ftbl2GxGxStudiopreSIG2[iTemp150] * fTemp154 + fTemp153 * ftbl2GxGxStudiopreSIG2[iTemp151])), fTemp144)) : ((fTemp133 < 0.0) ? copysign(((iTemp137) ? fConst362 : ((iTemp138) ? fConst361 : fTemp143 * ftbl1GxGxStudiopreSIG1[iTemp139] + fTemp142 * ftbl1GxGxStudiopreSIG1[iTemp140])), fTemp133) : copysign(((iTemp137) ? fConst360 : ((iTemp138) ? fConst359 : ftbl0GxGxStudiopreSIG0[iTemp139] * fTemp143 + fTemp142 * ftbl0GxGxStudiopreSIG0[iTemp140])), fTemp133))) - fConst5 * (fConst4 * fRec27[1] + fConst2 * fRec27[2]);
			double fTemp155 = fConst5 * fRec15[0] * (fConst480 * fRec27[0] + fConst479 * fRec27[1] + fConst478 * fRec27[2]);
			double fTemp156 = 16.5833 * std::fabs(fTemp155);
			double fTemp157 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp156) | std::isinf(fTemp156)) ? 0.0 : fTemp156)));
			int iTemp158 = static_cast<int>(fTemp157);
			int iTemp159 = iTemp158 < 0;
			int iTemp160 = iTemp158 >= 199;
			int iTemp161 = std::max<int>(0, std::min<int>(198, iTemp158));
			int iTemp162 = faust_wrap_add(iTemp161, 1);
			double fTemp163 = static_cast<double>(iTemp161);
			double fTemp164 = fTemp157 - fTemp163;
			double fTemp165 = fTemp163 + (1.0 - fTemp157);
			double fTemp166 = fConst238 * fRec36[1];
			double fTemp167 = fConst245 * fRec37[1];
			double fTemp168 = fConst252 * fRec38[1];
			fRec40[0] = -(fConst265 * (fConst264 * fRec40[1] - fConst260 * (fTemp6 - fVec0[1])));
			fRec39[0] = fRec40[0] - fConst263 * (fConst261 * fRec39[2] + fConst259 * fRec39[1]);
			fRec38[0] = fConst497 * (fRec39[2] + (fRec39[0] - 2.0 * fRec39[1])) - fConst496 * (fConst495 * fRec38[2] + fTemp168);
			fRec37[0] = fRec38[2] + fConst496 * (fTemp168 + fConst495 * fRec38[0]) - fConst492 * (fConst491 * fRec37[2] + fTemp167);
			fRec36[0] = fRec37[2] + fConst492 * (fTemp167 + fConst491 * fRec37[0]) - fConst488 * (fConst487 * fRec36[2] + fTemp166);
			double fTemp169 = fRec36[2] + fConst488 * (fTemp166 + fConst487 * fRec36[0]);
			fRec35[0] = fTemp169 - (fRec35[1] * fTemp5 + fRec35[2] * fTemp4 + fRec35[3] * fTemp3 + fRec35[4] * fTemp2 + fRec35[5] * fTemp1) / fTemp0;
			double fTemp170 = fRec3[0] * (fRec35[0] * fTemp16 + fRec35[1] * fTemp15 + fRec35[2] * fTemp14 + fRec35[3] * fTemp13 + fRec35[4] * fTemp12 + fRec35[5] * fTemp11) / fTemp0;
			double fTemp171 = 99.5 * std::fabs(fTemp170);
			double fTemp172 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp171) | std::isinf(fTemp171)) ? 0.0 : fTemp171)));
			int iTemp173 = static_cast<int>(fTemp172);
			int iTemp174 = iTemp173 < 0;
			int iTemp175 = iTemp173 >= 199;
			int iTemp176 = std::max<int>(0, std::min<int>(198, iTemp173));
			int iTemp177 = faust_wrap_add(iTemp176, 1);
			double fTemp178 = static_cast<double>(iTemp176);
			double fTemp179 = fTemp172 - fTemp178;
			double fTemp180 = fTemp178 + (1.0 - fTemp172);
			fRec41[0] = fTemp169 - (fRec41[1] * fTemp33 + fRec41[2] * fTemp32 + fRec41[3] * fTemp31 + fRec41[4] * fTemp29) / fTemp28;
			double fTemp181 = fRec3[0] * (fRec41[0] * fTemp38 + fRec41[1] * fTemp37 + fRec41[2] * fTemp36 + fRec41[3] * fTemp35 + fRec41[4] * fTemp34) / fTemp28;
			double fTemp182 = 99.5 * std::fabs(fTemp181);
			double fTemp183 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp182) | std::isinf(fTemp182)) ? 0.0 : fTemp182)));
			int iTemp184 = static_cast<int>(fTemp183);
			int iTemp185 = iTemp184 < 0;
			int iTemp186 = iTemp184 >= 199;
			int iTemp187 = std::max<int>(0, std::min<int>(198, iTemp184));
			int iTemp188 = faust_wrap_add(iTemp187, 1);
			double fTemp189 = static_cast<double>(iTemp187);
			double fTemp190 = fTemp183 - fTemp189;
			double fTemp191 = fTemp189 + (1.0 - fTemp183);
			fRec34[0] = ((iSlow0) ? ((fTemp181 < 0.0) ? copysign(((iTemp185) ? fConst476 : ((iTemp186) ? fConst475 : fTemp191 * ftbl3GxGxStudiopreSIG3[iTemp187] + fTemp190 * ftbl3GxGxStudiopreSIG3[iTemp188])), fTemp181) : copysign(((iTemp185) ? fConst474 : ((iTemp186) ? fConst473 : ftbl2GxGxStudiopreSIG2[iTemp187] * fTemp191 + fTemp190 * ftbl2GxGxStudiopreSIG2[iTemp188])), fTemp181)) : ((fTemp170 < 0.0) ? copysign(((iTemp174) ? fConst362 : ((iTemp175) ? fConst361 : fTemp180 * ftbl1GxGxStudiopreSIG1[iTemp176] + fTemp179 * ftbl1GxGxStudiopreSIG1[iTemp177])), fTemp170) : copysign(((iTemp174) ? fConst360 : ((iTemp175) ? fConst359 : ftbl0GxGxStudiopreSIG0[iTemp176] * fTemp180 + fTemp179 * ftbl0GxGxStudiopreSIG0[iTemp177])), fTemp170))) - fConst5 * (fConst4 * fRec34[1] + fConst2 * fRec34[2]);
			double fTemp192 = fConst5 * fRec15[0] * (fConst480 * fRec34[0] + fConst479 * fRec34[1] + fConst478 * fRec34[2]);
			double fTemp193 = 16.5833 * std::fabs(fTemp192);
			double fTemp194 = std::min<double>(201.0, std::max<double>(-1.0, ((std::isnan(fTemp193) | std::isinf(fTemp193)) ? 0.0 : fTemp193)));
			int iTemp195 = static_cast<int>(fTemp194);
			int iTemp196 = iTemp195 < 0;
			int iTemp197 = iTemp195 >= 199;
			int iTemp198 = std::max<int>(0, std::min<int>(198, iTemp195));
			int iTemp199 = faust_wrap_add(iTemp198, 1);
			double fTemp200 = static_cast<double>(iTemp198);
			double fTemp201 = fTemp194 - fTemp200;
			double fTemp202 = fTemp200 + (1.0 - fTemp194);
			output0[i0] = static_cast<FAUSTFLOAT>(((fTemp192 < 0.0) ? copysign(((iTemp196) ? fConst484 : ((iTemp197) ? fConst483 : fTemp202 * ftbl5GxGxStudiopreSIG5[iTemp198] + fTemp201 * ftbl5GxGxStudiopreSIG5[iTemp199])), fTemp192) : copysign(((iTemp196) ? fConst482 : ((iTemp197) ? fConst481 : ftbl4GxGxStudiopreSIG4[iTemp198] * fTemp202 + fTemp201 * ftbl4GxGxStudiopreSIG4[iTemp199])), fTemp192)) + ((fTemp155 < 0.0) ? copysign(((iTemp159) ? fConst484 : ((iTemp160) ? fConst483 : fTemp165 * ftbl5GxGxStudiopreSIG5[iTemp161] + fTemp164 * ftbl5GxGxStudiopreSIG5[iTemp162])), fTemp155) : copysign(((iTemp159) ? fConst482 : ((iTemp160) ? fConst481 : ftbl4GxGxStudiopreSIG4[iTemp161] * fTemp165 + fTemp164 * ftbl4GxGxStudiopreSIG4[iTemp162])), fTemp155)) + ((fTemp119 < 0.0) ? copysign(((iTemp123) ? fConst484 : ((iTemp124) ? fConst483 : fTemp129 * ftbl5GxGxStudiopreSIG5[iTemp125] + fTemp128 * ftbl5GxGxStudiopreSIG5[iTemp126])), fTemp119) : copysign(((iTemp123) ? fConst482 : ((iTemp124) ? fConst481 : ftbl4GxGxStudiopreSIG4[iTemp125] * fTemp129 + fTemp128 * ftbl4GxGxStudiopreSIG4[iTemp126])), fTemp119)) + ((fTemp84 < 0.0) ? copysign(((iTemp88) ? fConst484 : ((iTemp89) ? fConst483 : fTemp94 * ftbl5GxGxStudiopreSIG5[iTemp90] + fTemp93 * ftbl5GxGxStudiopreSIG5[iTemp91])), fTemp84) : copysign(((iTemp88) ? fConst482 : ((iTemp89) ? fConst481 : ftbl4GxGxStudiopreSIG4[iTemp90] * fTemp94 + fTemp93 * ftbl4GxGxStudiopreSIG4[iTemp91])), fTemp84)) + ((fTemp50 < 0.0) ? copysign(((iTemp54) ? fConst484 : ((iTemp55) ? fConst483 : fTemp60 * ftbl5GxGxStudiopreSIG5[iTemp56] + fTemp59 * ftbl5GxGxStudiopreSIG5[iTemp57])), fTemp50) : copysign(((iTemp54) ? fConst482 : ((iTemp55) ? fConst481 : ftbl4GxGxStudiopreSIG4[iTemp56] * fTemp60 + fTemp59 * ftbl4GxGxStudiopreSIG4[iTemp57])), fTemp50)));
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fVec0[1] = fVec0[0];
			fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fVec1[1] = fVec1[0];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fVec2[1] = fVec2[0];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fVec3[1] = fVec3[0];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			for (int j0 = 5; j0 > 0; j0 = faust_wrap_sub(j0, 1)) {
				fRec5[j0] = fRec5[faust_wrap_sub(j0, 1)];
			}
			for (int j1 = 4; j1 > 0; j1 = faust_wrap_sub(j1, 1)) {
				fRec14[j1] = fRec14[faust_wrap_sub(j1, 1)];
			}
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec15[1] = fRec15[0];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			for (int j2 = 5; j2 > 0; j2 = faust_wrap_sub(j2, 1)) {
				fRec17[j2] = fRec17[faust_wrap_sub(j2, 1)];
			}
			for (int j3 = 4; j3 > 0; j3 = faust_wrap_sub(j3, 1)) {
				fRec20[j3] = fRec20[faust_wrap_sub(j3, 1)];
			}
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec25[1] = fRec25[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			for (int j4 = 5; j4 > 0; j4 = faust_wrap_sub(j4, 1)) {
				fRec22[j4] = fRec22[faust_wrap_sub(j4, 1)];
			}
			for (int j5 = 4; j5 > 0; j5 = faust_wrap_sub(j5, 1)) {
				fRec26[j5] = fRec26[faust_wrap_sub(j5, 1)];
			}
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec32[1] = fRec32[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			for (int j6 = 5; j6 > 0; j6 = faust_wrap_sub(j6, 1)) {
				fRec28[j6] = fRec28[faust_wrap_sub(j6, 1)];
			}
			for (int j7 = 4; j7 > 0; j7 = faust_wrap_sub(j7, 1)) {
				fRec33[j7] = fRec33[faust_wrap_sub(j7, 1)];
			}
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec40[1] = fRec40[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			for (int j8 = 5; j8 > 0; j8 = faust_wrap_sub(j8, 1)) {
				fRec35[j8] = fRec35[faust_wrap_sub(j8, 1)];
			}
			for (int j9 = 4; j9 > 0; j9 = faust_wrap_sub(j9, 1)) {
				fRec41[j9] = fRec41[faust_wrap_sub(j9, 1)];
			}
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
		}
	}

};

#endif
