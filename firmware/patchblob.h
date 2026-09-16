// Patch blob — the on-pedal patch table the studio writes straight into QSPI.
//
// The firmware ships with EVERY effect in the catalog compiled in, so changing patches never means
// recompiling: the studio serialises the four patches into this fixed-layout blob (js/app.js
// buildPatchBlob) and DFU-writes it to PATCH_BLOB_ADDR. At boot the firmware validates the magic +
// CRC-32 and uses it; if nothing valid is there it falls back to the built-in table in patches.h.
//
// Everything is little-endian, packed, fixed size (77 KB). Strings are NUL-padded char arrays.
// Keep this file in sync with buildPatchBlob() in js/app.js.
#pragma once
#include <cstdint>

#define PATCH_BLOB_ADDR   0x90780000u          // last 256 KB of the 8 MB QSPI (64 KB sectors), above the app
#define PATCH_BLOB_MAGIC  0x54504843u          // "CHPT"
#define PATCH_BLOB_VERSION 1u

enum { PB_PATCHES = 4, PB_STAGES = 7, PB_VALUES = 40, PB_PATH = 64, PB_ID = 32, PB_NAME = 8 };

struct __attribute__((packed)) PbValue { char path[PB_PATH]; float value; };                      // 68
struct __attribute__((packed)) PbStage { uint16_t effect; char id[PB_ID]; uint8_t on; uint8_t nvalues; PbValue values[PB_VALUES]; };  // 36 + 40*68 = 2756
struct __attribute__((packed)) PbPot   { int8_t stage; uint8_t pad[3]; char path[PB_PATH]; };      // 68
struct __attribute__((packed)) PbPatch { char name[PB_NAME]; uint8_t potsLocked; uint8_t nstages; uint16_t hue; uint8_t pad[4]; PbStage stages[PB_STAGES]; PbPot pots[3]; };  // 16 + 7*2756 + 3*68 = 19512
struct __attribute__((packed)) PbHeader { uint32_t magic; uint32_t version; uint32_t length; uint32_t crc; uint32_t npatches; uint32_t reserved[3]; };  // 32
struct __attribute__((packed)) PatchBlob { PbHeader h; PbPatch patches[PB_PATCHES]; };             // 32 + 4*19512 = 78080

static_assert(sizeof(PbValue) == 68, "PbValue layout");
static_assert(sizeof(PbStage) == 2756, "PbStage layout");
static_assert(sizeof(PbPatch) == 19512, "PbPatch layout");
static_assert(sizeof(PatchBlob) == 78080, "PatchBlob layout");

// CRC-32 (IEEE, same as zlib / JS) over everything after the header
static inline uint32_t pb_crc32(const uint8_t* p, uint32_t n) {
    uint32_t c = 0xFFFFFFFFu;
    for (uint32_t i = 0; i < n; i++) { c ^= p[i]; for (int k = 0; k < 8; k++) c = (c >> 1) ^ (0xEDB88320u & (0u - (c & 1u))); }
    return ~c;
}
static inline bool pb_valid(const PatchBlob* b) {
    if (b->h.magic != PATCH_BLOB_MAGIC || b->h.version != PATCH_BLOB_VERSION) return false;
    if (b->h.length != sizeof(PatchBlob) || b->h.npatches != PB_PATCHES) return false;
    return pb_crc32((const uint8_t*)b->patches, sizeof(b->patches)) == b->h.crc;
}
