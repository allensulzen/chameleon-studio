// Minimal offline host for Faust-generated C++ (mydsp): reads a float/int WAV, renders, writes float WAV.
// usage: host <in.wav|-> <out.wav> <seconds> [Label=value ...]   (Label matched as case-insensitive substring of param path)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "faust/gui/APIUI.h"
#include "faust/gui/meta.h"
#include "faust/dsp/dsp.h"
#include "DSP.h"   // generated: class mydsp
static std::vector<float> readWav(const char* p, int& sr) {
    FILE* f = fopen(p, "rb"); if (!f) { perror(p); exit(1); }
    std::vector<unsigned char> b; unsigned char buf[65536]; size_t n; while ((n = fread(buf, 1, sizeof buf, f))) b.insert(b.end(), buf, buf + n); fclose(f);
    int fmt = 1, ch = 1, bits = 16; sr = 48000; size_t pos = 12; std::vector<float> out;
    while (pos + 8 <= b.size()) {
        std::string id((char*)&b[pos], 4); unsigned sz = *(unsigned*)&b[pos + 4]; size_t d = pos + 8;
        if (id == "fmt ") { fmt = *(unsigned short*)&b[d]; ch = *(unsigned short*)&b[d + 2]; sr = *(int*)&b[d + 4]; bits = *(unsigned short*)&b[d + 14]; if (fmt == 0xFFFE) fmt = *(unsigned short*)&b[d + 24]; }
        else if (id == "data") {
            size_t frames = sz / (ch * bits / 8);
            for (size_t i = 0; i < frames; i++) { double acc = 0; for (int c = 0; c < ch; c++) { size_t o = d + (i * ch + c) * bits / 8; double v;
                if (fmt == 3 && bits == 32) v = *(float*)&b[o]; else if (bits == 16) v = *(short*)&b[o] / 32768.0; else if (bits == 24) { int x = (b[o] | (b[o+1] << 8) | (b[o+2] << 16)); if (x & 0x800000) x |= ~0xFFFFFF; v = x / 8388608.0; } else if (bits == 32) v = *(int*)&b[o] / 2147483648.0; else v = 0; acc += v; }
                out.push_back((float)(acc / ch)); }
        }
        pos = d + sz + (sz & 1);
    }
    return out;
}
static void writeWav(const char* p, const std::vector<float>& y, int sr) {
    FILE* f = fopen(p, "wb"); unsigned dataLen = y.size() * 4; unsigned riff = 36 + dataLen; unsigned short one = 1, three = 3, four = 4, b32 = 32, sixteen = 16; unsigned bps = sr * 4; unsigned sixteenU = 16;
    fwrite("RIFF", 1, 4, f); fwrite(&riff, 4, 1, f); fwrite("WAVEfmt ", 1, 8, f); fwrite(&sixteenU, 4, 1, f); fwrite(&three, 2, 1, f); fwrite(&one, 2, 1, f); fwrite(&sr, 4, 1, f); fwrite(&bps, 4, 1, f); fwrite(&four, 2, 1, f); fwrite(&b32, 2, 1, f); fwrite("data", 1, 4, f); fwrite(&dataLen, 4, 1, f); fwrite(y.data(), 4, y.size(), f); fclose(f);
}
int main(int argc, char** argv) {
    if (argc < 3) { fprintf(stderr, "usage: host in.wav out.wav seconds [Param=value...]\n"); return 1; }
    int SR = 48000; std::vector<float> in; if (strcmp(argv[1], "-") != 0) in = readWav(argv[1], SR); if (getenv("SR")) SR = atoi(getenv("SR"));
    mydsp& dsp = *new mydsp(); APIUI ui; dsp.init(SR); dsp.buildUserInterface(&ui);
    if (argc >= 3 && std::string(argv[2]) == "--list") { for (int i = 0; i < ui.getParamsCount(); i++) printf("  %s [%g..%g] init=%g\n", ui.getParamAddress(i), ui.getParamMin(i), ui.getParamMax(i), ui.getParamInit(i)); return 0; }
    if (0) { for (int i = 0; i < ui.getParamsCount(); i++) printf("  %s [%g..%g] init=%g\n", ui.getParamAddress(i), ui.getParamMin(i), ui.getParamMax(i), ui.getParamInit(i)); return 0; }
    for (int a = 4; a < argc; a++) { std::string s(argv[a]); auto eq = s.find('='); std::string k = s.substr(0, eq); float v = atof(s.substr(eq + 1).c_str());
        std::string kk; for (char c : k) kk += isalnum((unsigned char)c) ? (char)tolower(c) : '_'; bool hit = false;
        for (int i = 0; i < ui.getParamsCount(); i++) { std::string p = ui.getParamAddress(i); std::string pp; for (char c : p) pp += isalnum((unsigned char)c) ? (char)tolower(c) : '_'; if (pp.find(kk) != std::string::npos) { ui.setParamValue(p.c_str(), v); hit = true; break; } }
        if (!hit) { fprintf(stderr, "no param %s\n", k.c_str()); for (int i = 0; i < ui.getParamsCount(); i++) fprintf(stderr, "  %s\n", ui.getParamAddress(i)); return 1; } }
    size_t N = (size_t)(atof(argv[3]) * SR); int nin = dsp.getNumInputs(), nout = dsp.getNumOutputs();
    std::vector<float> y(N); const int B = 64; std::vector<std::vector<float>> ib(nin, std::vector<float>(B)), ob(nout, std::vector<float>(B));
    std::vector<float*> ip(nin), op(nout); for (int c = 0; c < nin; c++) ip[c] = ib[c].data(); for (int c = 0; c < nout; c++) op[c] = ob[c].data();
    float peak = 0; bool nan = false;
    for (size_t pos = 0; pos < N; pos += B) { int n = std::min((size_t)B, N - pos);
        for (int c = 0; c < nin; c++) for (int i = 0; i < n; i++) ib[c][i] = (pos + i < in.size()) ? in[pos + i] : 0.f;
        dsp.compute(n, ip.data(), op.data());
        for (int i = 0; i < n; i++) { float v = nout > 1 ? 0.5f * (ob[0][i] + ob[1][i]) : ob[0][i]; if (!std::isfinite(v)) { nan = true; v = 0; } peak = std::max(peak, fabsf(v)); y[pos + i] = v; } }
    writeWav(argv[2], y, SR); printf("peak=%.3f%s\n", peak, nan ? " NAN!" : ""); return 0;
}
