#!/usr/bin/env node
/**
 * build-firmware.mjs — build the Chameleon firmware with EVERY catalog effect compiled in.
 *
 *   node tools/build-firmware.mjs --default --make               # full build -> firmware/chameleon.bin
 *   node tools/build-firmware.mjs chameleon-patches.json --make  # same, with these patches as the fallback set
 *
 * Patches are not part of the firmware any more: the studio writes them into QSPI as a PatchBlob
 * (firmware/patchblob.h) whenever you click Connect & flash. The patches given here only become the
 * built-in fallback (firmware/patches.h) used when no blob is present. The firmware is rebuilt only when
 * the effect catalog or the engine changes; each build gets a random FW_ID that the studio compares
 * against the pedal's `ID?` reply to decide whether the big image needs re-flashing.
 *
 * Writes firmware/faust/<id>.h + firmware/fx/<id>.cpp for all effects (native Faust compiler: `faust`
 * on PATH or FAUST=/path/to/faust; FAUST_LIBS=/path/to/faustlibraries if it can't find stdfaust.lib),
 * firmware/effects.h (the registry), firmware/patches.h, and with --make firmware/chameleon.bin +
 * firmware/chameleon.json.
 */
import fs from 'node:fs';
import path from 'node:path';
import { execFileSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const argv = process.argv.slice(2);
const doMake = argv.includes('--make');
const useDefault = argv.includes('--default');
const input = argv.find(a => !a.startsWith('--'));
const FAUST = process.env.FAUST || 'faust';
const LIBS = process.env.FAUST_LIBS || '';   // extra -I for stdfaust.lib when faust can't find it

const EFFECTS_CATALOG = new Function(fs.readFileSync(path.join(root, 'js/effects-data.js'), 'utf8') + '\n;return EFFECTS_CATALOG;')();
const byId = new Map(EFFECTS_CATALOG.map(e => [e.id, e]));

// Same rule as js/app.js hueOf(): family hue + a per-effect wobble
const FAMILY_HUE = { time: 178, reverb: 200, mod: 268, dirt: 18, dynamics: 112, filter: 44, pitch: 320, amp: 30, eq: 60, utility: 220 };
function hueOf(e) { let h = 0; for (const c of e.id) h = (h * 31 + c.charCodeAt(0)) >>> 0; return (FAMILY_HUE[e.family] || 200) + ((h % 21) - 10); }

const DEFAULT = {
  version: 2,
  patches: [
    { name: 'A', potsLocked: false, chain: [{ uid: 1, id: 'dynamic-overdrive', on: true, values: {} }], pots: [{ uid: 1, path: '/DynamicOverdrive/Gain' }, { uid: 1, path: '/DynamicOverdrive/Tone' }, { uid: 1, path: '/DynamicOverdrive/Level' }] },
    { name: 'B', potsLocked: false, chain: [{ uid: 2, id: 'dynamic-overdrive', on: true, values: { '/DynamicOverdrive/Gain': 36, '/DynamicOverdrive/Tone': 1800, '/DynamicOverdrive/Level': 0.5 } }], pots: [{ uid: 2, path: '/DynamicOverdrive/Gain' }, { uid: 2, path: '/DynamicOverdrive/Tone' }, { uid: 2, path: '/DynamicOverdrive/Level' }] },
    { name: 'C', potsLocked: false, chain: [{ uid: 3, id: 'clean-boost', on: true, values: {} }], pots: [{ uid: 3, path: '/JFETBoost/Boost' }, { uid: 3, path: '/JFETBoost/Tilt_EQ' }, { uid: 3, path: '/JFETBoost/Master' }] },
    { name: 'D', potsLocked: false, chain: [{ uid: 4, id: 'tape-delay', on: true, values: {} }], pots: [{ uid: 4, path: '/TapeDelay/Time' }, { uid: 4, path: '/TapeDelay/Feedback' }, { uid: 4, path: '/TapeDelay/Mix' }] },
  ],
};

const doc = useDefault || !input ? DEFAULT : JSON.parse(fs.readFileSync(input, 'utf8'));
if (!Array.isArray(doc.patches) || doc.patches.length !== 4) { console.error('Expected a studio export with 4 patches'); process.exit(1); }

const cls = (id) => id.replace(/(^|-)([a-z0-9])/g, (_, __, c) => c.toUpperCase());
const cstr = (s) => JSON.stringify(String(s));
const f = (v) => { let s = String(+Number(v).toPrecision(7)); if (!/[.e]/.test(s)) s += '.0'; return s + 'f'; };

// ---- every effect in the catalog, in catalog order (the index the studio's blob uses)
const used = EFFECTS_CATALOG.map(e => e.id);
for (const p of doc.patches) for (const s of p.chain || []) if (!byId.has(s.id)) { console.error(`Unknown effect id "${s.id}"`); process.exit(1); }

// ---- generate Faust C++ + one translation unit per effect (269 classes in one file would take forever)
const fwDir = path.join(root, 'firmware'); const faustDir = path.join(fwDir, 'faust'); const fxDir = path.join(fwDir, 'fx');
fs.mkdirSync(faustDir, { recursive: true }); fs.mkdirSync(fxDir, { recursive: true });
const dspLib = path.join(root, 'dsp/lib');
const stale = (src, out) => !fs.existsSync(out) || fs.statSync(out).mtimeMs < fs.statSync(src).mtimeMs;
let regenerated = 0;
for (const id of used) {
  const e = byId.get(id);
  const prec = /-double/.test(e.flags || '') ? '-double' : '-single';
  const dsp = path.join(root, 'dsp', `${id}.dsp`), hp = path.join(faustDir, `${id}.h`);
  if (!argv.includes('--force') && !stale(dsp, hp)) continue;
  const args = ['-lang', 'cpp', prec, '-cn', cls(id), '-scn', 'chdsp', '-i', '-I', path.join(root, 'dsp'), '-I', dspLib, ...(LIBS ? ['-I', LIBS, '-I', path.join(LIBS, 'old')] : []), dsp, '-o', hp];
  try { execFileSync(FAUST, args, { stdio: ['ignore', 'inherit', 'inherit'] }); regenerated++; }
  catch (err) { console.error(`Faust failed on ${id} — is the native compiler installed? (brew install faust)`); process.exit(1); }
  // Faust's file-scope lookup tables (sine tables, waveforms) would eat the 512 KB of SRAM; put them in SDRAM.
  fs.writeFileSync(hp, fs.readFileSync(hp, 'utf8').replace(/^static (float|double|int) (ftbl\w+|itbl\w+)\[/gm, 'static $1 DSY_SDRAM_BSS $2['));
}
console.log(`faust: ${used.length} effects (${regenerated} regenerated)`);
for (const id of used) {
  const fn = id.replace(/-/g, '_');
  const src = `// GENERATED by tools/build-firmware.mjs — do not edit.\n#include <new>\n#include "daisy_seed.h"\n#include "chameleon_faust.h"\n#include "faust/${id}.h"\nchdsp* fx_make_${fn}(void* mem) { return new (mem) ${cls(id)}(); }\nsize_t fx_size_${fn}() { return sizeof(${cls(id)}); }\n`;
  const out = path.join(fxDir, `${id}.cpp`);
  if (!fs.existsSync(out) || fs.readFileSync(out, 'utf8') !== src) fs.writeFileSync(out, src);
}
// effects.h — the registry main.cpp indexes into
{
  const l = ['// GENERATED by tools/build-firmware.mjs — do not edit. Every effect in js/effects-data.js, catalog order.', '#pragma once', '#include <cstddef>', '#include "chameleon_faust.h"', ''];
  for (const id of used) { const fn = id.replace(/-/g, '_'); l.push(`chdsp* fx_make_${fn}(void*); size_t fx_size_${fn}();`); }
  l.push('', 'struct EffectEntry { const char* id; chdsp* (*make)(void*); size_t (*size)(); };');
  l.push(`enum { NUM_EFFECTS = ${used.length} };`);
  l.push('static const EffectEntry EFFECTS[NUM_EFFECTS] = {');
  for (const id of used) { const fn = id.replace(/-/g, '_'); l.push(`    { ${cstr(id)}, fx_make_${fn}, fx_size_${fn} },`); }
  l.push('};', '');
  fs.writeFileSync(path.join(fwDir, 'effects.h'), l.join('\n'));
}

// ---- patches.h (fallback set only)
const lines = [];
lines.push('// GENERATED by tools/build-firmware.mjs — do not edit. Fallback patch set used when QSPI holds no PatchBlob. Source: ' + (useDefault || !input ? 'built-in default set' : path.basename(input)));
lines.push('#pragma once');
lines.push('');
lines.push('enum { NUM_PATCHES = 4, MAX_STAGES = 7, MAX_VALUES = 40 };');
lines.push('struct ValueDef { const char* path; float value; };');
lines.push('struct StageDef { int effect; bool on; int nvalues; ValueDef values[MAX_VALUES]; };');
lines.push('struct PotDef   { int stage; const char* path; };');
lines.push('struct PatchDef { const char* name; bool potsLocked; int hue; int nstages; StageDef stages[MAX_STAGES]; PotDef pots[3]; };');
lines.push('');
lines.push('static const PatchDef PATCHES[NUM_PATCHES] = {');
doc.patches.forEach((p, pi) => {
  const chain = (p.chain || []).slice(0, 7);
  const first = chain.find(s => s.on !== false) || chain[0];
  const hue = first ? hueOf(byId.get(first.id)) : 178;
  const stages = chain.map(s => {
    const e = byId.get(s.id);
    const vals = e.params.map(prm => ({ path: prm.path, value: (s.values && s.values[prm.path] != null) ? s.values[prm.path] : prm.default })).slice(0, 40);
    return `      { ${used.indexOf(s.id)}, ${s.on === false ? 'false' : 'true'}, ${vals.length}, { ${vals.map(v => `{ ${cstr(v.path)}, ${f(v.value)} }`).join(', ')} } }`;
  });
  const pots = [0, 1, 2].map(k => { const a = (p.pots || [])[k]; const si = a ? chain.findIndex(s => s.uid === a.uid) : -1; return si >= 0 ? `{ ${si}, ${cstr(a.path)} }` : '{ -1, "" }'; });
  lines.push(`    // Patch ${'ABCD'[pi]}: ${chain.map(s => byId.get(s.id).name).join(' -> ') || '(empty)'}`);
  lines.push(`    { ${cstr(p.name || 'ABCD'[pi])}, ${p.potsLocked ? 'true' : 'false'}, ${hue}, ${stages.length},`);
  lines.push(`      { ${stages.length ? '\n' + stages.join(',\n') + '\n      ' : ''}},`);
  lines.push(`      { ${pots.join(', ')} } },`);
});
lines.push('};');
fs.writeFileSync(path.join(fwDir, 'patches.h'), lines.join('\n') + '\n');
console.log(`wrote firmware/effects.h (${used.length} effects) and firmware/patches.h (fallback set)`);

if (doMake) {
  const appType = process.env.APP_TYPE || 'BOOT_QSPI';
  if (appType !== 'BOOT_QSPI') { console.error('The full-catalog firmware only fits in QSPI (APP_TYPE=BOOT_QSPI).'); process.exit(1); }
  const fwId = process.env.FW_ID || (Date.now().toString(36) + Math.random().toString(36).slice(2, 6));
  const jobs = String(process.env.JOBS || 8);
  execFileSync('make', ['-j' + jobs, `APP_TYPE=${appType}`, `FW_ID=${fwId}`], { cwd: fwDir, stdio: 'inherit' });
  const bin = path.join(fwDir, 'build/chameleon.bin');
  const size = fs.statSync(bin).size;
  const PATCH_BLOB_ADDR = 0x90780000, APP_ADDR = 0x90040000;
  if (APP_ADDR + size > PATCH_BLOB_ADDR) { console.error(`firmware is ${(size / 1048576).toFixed(2)} MB — it would overlap the patch blob at 0x90780000`); process.exit(1); }
  fs.copyFileSync(bin, path.join(fwDir, 'chameleon.bin'));
  // bootloader image for the studio's "Install bootloader" button
  const libdaisy = process.env.LIBDAISY_DIR || path.join(fwDir, '../../fw/libDaisy');
  const boot = path.join(libdaisy, 'core/dsy_bootloader_v6_4-intdfu-2000ms.bin');
  if (fs.existsSync(boot)) fs.copyFileSync(boot, path.join(fwDir, 'dsy_bootloader.bin'));
  const info = { built: new Date().toISOString(), fwId, appType, address: APP_ADDR, size, patchAddress: PATCH_BLOB_ADDR, blobVersion: 1, effects: used,
    fallbackPatches: doc.patches.map((p, i) => ({ name: p.name || 'ABCD'[i], chain: (p.chain || []).map(s => s.id) })) };
  fs.writeFileSync(path.join(fwDir, 'chameleon.json'), JSON.stringify(info, null, 2) + '\n');
  console.log(`firmware/chameleon.bin: ${(size / 1048576).toFixed(2)} MB, ${used.length} effects, FW_ID ${fwId} (@ 0x${APP_ADDR.toString(16)}, patches @ 0x${PATCH_BLOB_ADDR.toString(16)})`);
}
