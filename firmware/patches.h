// Patch table — first-flash edition (hand-written; tools/build-firmware.mjs will generate this
// from a studio export once the pipeline is proven).
//
// Shape: each patch is a series chain of up to MAX_STAGES stages. Every stage names a Faust
// class (from CH_EFFECTS) and the stored value of each parameter, addressed by the same
// "/Class/Label" path the studio uses. Three pot bindings per patch point at (stage, path).
#pragma once
#include "faust/dynamic-overdrive.h"

// X-macro: class name, id — order defines the effect index used below
#define CH_EFFECTS(X) \
    X(DynamicOverdrive, "dynamic-overdrive")

enum { NUM_PATCHES = 4, MAX_STAGES = 7, MAX_VALUES = 24 };

struct ValueDef { const char* path; float value; };
struct StageDef { int effect; bool on; int nvalues; ValueDef values[MAX_VALUES]; };
struct PotDef   { int stage; const char* path; };   // stage -1 = unassigned
struct PatchDef { const char* name; bool potsLocked; int nstages; StageDef stages[MAX_STAGES]; PotDef pots[3]; };

static const PatchDef PATCHES[NUM_PATCHES] = {
    { "A", false, 1,
      { { 0, true, 3, { { "/DynamicOverdrive/Gain", 18.0f }, { "/DynamicOverdrive/Tone", 2800.0f }, { "/DynamicOverdrive/Level", 0.6f } } } },
      { { 0, "/DynamicOverdrive/Gain" }, { 0, "/DynamicOverdrive/Tone" }, { 0, "/DynamicOverdrive/Level" } } },
    { "B", false, 1,
      { { 0, true, 3, { { "/DynamicOverdrive/Gain", 36.0f }, { "/DynamicOverdrive/Tone", 1800.0f }, { "/DynamicOverdrive/Level", 0.5f } } } },
      { { 0, "/DynamicOverdrive/Gain" }, { 0, "/DynamicOverdrive/Tone" }, { 0, "/DynamicOverdrive/Level" } } },
    { "C", false, 0, {}, { { -1, "" }, { -1, "" }, { -1, "" } } },
    { "D", false, 0, {}, { { -1, "" }, { -1, "" }, { -1, "" } } },
};
