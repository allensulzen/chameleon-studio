// Minimal Faust runtime for the Chameleon firmware.
// The Faust compiler emits a class per effect (firmware/faust/*.h) that expects a base
// class (we call it `chdsp`), a `UI` visitor and a `Meta` sink. This header provides
// lightweight, allocation-free versions of all three so the generated code builds
// cleanly against newlib on the Cortex-M7.
#pragma once
#include <cstring>
#include <cmath>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class Meta {
public:
    virtual ~Meta() {}
    virtual void declare(const char* /*key*/, const char* /*value*/) {}
};

class UI {
public:
    virtual ~UI() {}
    virtual void openTabBox(const char* label)        { openBox(label); }
    virtual void openHorizontalBox(const char* label) { openBox(label); }
    virtual void openVerticalBox(const char* label)   { openBox(label); }
    virtual void closeBox() {}
    virtual void addButton(const char* label, FAUSTFLOAT* zone)                                          { addParam(label, zone, 0, 0, 1, 1); }
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)                                     { addParam(label, zone, 0, 0, 1, 1); }
    virtual void addVerticalSlider(const char* l, FAUSTFLOAT* z, FAUSTFLOAT i, FAUSTFLOAT mn, FAUSTFLOAT mx, FAUSTFLOAT s)   { addParam(l, z, i, mn, mx, s); }
    virtual void addHorizontalSlider(const char* l, FAUSTFLOAT* z, FAUSTFLOAT i, FAUSTFLOAT mn, FAUSTFLOAT mx, FAUSTFLOAT s) { addParam(l, z, i, mn, mx, s); }
    virtual void addNumEntry(const char* l, FAUSTFLOAT* z, FAUSTFLOAT i, FAUSTFLOAT mn, FAUSTFLOAT mx, FAUSTFLOAT s)         { addParam(l, z, i, mn, mx, s); }
    virtual void addHorizontalBargraph(const char*, FAUSTFLOAT*, FAUSTFLOAT, FAUSTFLOAT) {}
    virtual void addVerticalBargraph(const char*, FAUSTFLOAT*, FAUSTFLOAT, FAUSTFLOAT) {}
    virtual void addSoundfile(const char*, const char*, void**) {}
    virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
protected:
    virtual void openBox(const char*) {}
    virtual void addParam(const char*, FAUSTFLOAT*, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT) {}
};

class chdsp {
public:
    virtual ~chdsp() {}
    virtual int  getNumInputs()  = 0;
    virtual int  getNumOutputs() = 0;
    virtual void buildUserInterface(UI* ui) = 0;
    virtual int  getSampleRate() = 0;
    virtual void init(int sr) = 0;
    virtual void instanceInit(int sr) = 0;
    virtual void instanceConstants(int sr) = 0;
    virtual void instanceResetUserInterface() = 0;
    virtual void instanceClear() = 0;
    virtual chdsp* clone() = 0;
    virtual void metadata(Meta* m) = 0;
    virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
};

// Collects every slider of a Faust class as "/Box/Label" -> zone, so the patch table can
// address parameters with the same paths the studio uses (effects-data.js `path`).
struct ParamMap : public UI {
    static constexpr int MAX_PARAMS = 24;
    static constexpr int MAX_PATH   = 96;
    struct Param { char path[MAX_PATH]; FAUSTFLOAT* zone; FAUSTFLOAT init, min, max; };
    Param params[MAX_PARAMS];
    int   count = 0;

    void build(chdsp* d) { count = 0; depth_ = 0; prefix_[0] = 0; d->buildUserInterface(this); }
    Param* find(const char* path) {
        for (int i = 0; i < count; i++) if (std::strcmp(params[i].path, path) == 0) return &params[i];
        return nullptr;
    }
    // set by path; value is in the parameter's own units (dB, Hz, 0..1 ...)
    bool set(const char* path, float v) { Param* p = find(path); if (!p) return false; *p->zone = clamp(p, v); return true; }
    // set from a normalised 0..1 pot position
    bool setNorm(const char* path, float n) { Param* p = find(path); if (!p) return false; *p->zone = p->min + (p->max - p->min) * (n < 0 ? 0 : n > 1 ? 1 : n); return true; }
    static float clamp(const Param* p, float v) { return v < p->min ? p->min : v > p->max ? p->max : v; }
    static float norm(const Param* p, float v) { return p->max > p->min ? (v - p->min) / (p->max - p->min) : 0.f; }

protected:
    char prefix_[MAX_PATH];
    int  depth_ = 0;
    void openBox(const char* label) override {
        // Faust puts the top-level box name first; keep "/Name/..." like the JSON UI paths
        size_t n = std::strlen(prefix_);
        if (n + std::strlen(label) + 2 < MAX_PATH) { prefix_[n] = '/'; std::strcpy(prefix_ + n + 1, label); }
        depth_++;
    }
    void closeBox() override {
        char* s = std::strrchr(prefix_, '/'); if (s) *s = 0; depth_--;
    }
    void addParam(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT mn, FAUSTFLOAT mx, FAUSTFLOAT) override {
        if (count >= MAX_PARAMS) return;
        Param& p = params[count++];
        std::strncpy(p.path, prefix_, MAX_PATH - 1); p.path[MAX_PATH - 1] = 0;
        size_t n = std::strlen(p.path); if (n + 1 < MAX_PATH) { p.path[n] = '/'; std::strncpy(p.path + n + 1, label, MAX_PATH - n - 2); p.path[MAX_PATH - 1] = 0; }
        p.zone = zone; p.init = init; p.min = mn; p.max = mx;
    }
};
