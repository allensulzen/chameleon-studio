#!/usr/bin/env node
/**
 * Chameleon Studio — catalog builder (v2: many effects, any number of parameters)
 *
 * dsp/*.dsp is the single source of truth. This script:
 *   1. compiles every .dsp with the Faust compiler (faustwasm), with dsp/ and dsp/lib/ on the
 *      include path and per-effect flags from `declare chameleon_flags "-double";`
 *   2. refuses to write if anything fails to compile or isn't 1-in/1-out;
 *   3. reads parameters (label / min / max / default / step / unit) from the compiled UI;
 *   4. takes UI metadata from dsp/catalog.json when present, else from the file's declares
 *      (name, description, author, license, source, category, family);
 *   5. precompiles each effect to precompiled/<id>/ (wasm + meta) so the studio loads instantly;
 *   6. writes js/effects-data.js and dsp/lib/index.json (lib list for the in-browser compiler fallback).
 *
 *   node tools/build-catalog.mjs            build everything
 *   node tools/build-catalog.mjs --check    compile only
 *   node tools/build-catalog.mjs --only gx- only ids starting with "gx-" (others keep their previous build)
 *   node tools/build-catalog.mjs --force   recompile everything (by default an effect whose precompiled/<id>
 *                                          is newer than its .dsp and dsp/lib is reused — rebuilds take seconds)
 */
import fs from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';
import { instantiateFaustModuleFromFile, LibFaust, FaustCompiler, FaustMonoDspGenerator } from '../vendor/faustwasm/index.js';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const argv = process.argv.slice(2);
const checkOnly = argv.includes('--check');
const only = argv.includes('--only') ? argv[argv.indexOf('--only') + 1] : null;
const force = argv.includes('--force');   // recompile even when precompiled/<id> is newer than the source

const FAMILY_ICON = {
  time: 'tabler:repeat', reverb: 'tabler:ripple', mod: 'tabler:wave-sine', dirt: 'tabler:flame',
  dynamics: 'tabler:activity', filter: 'tabler:filter', pitch: 'tabler:music', amp: 'tabler:device-speaker',
  utility: 'tabler:tool', eq: 'tabler:adjustments',
};
const FAMILY_NAME = { time: 'Delay', reverb: 'Reverb', mod: 'Modulation', dirt: 'Dirt', dynamics: 'Dynamics', filter: 'Filter', pitch: 'Pitch', amp: 'Amp & Tube', utility: 'Utility', eq: 'EQ & Tone' };

// guitarix `declare category` -> family (with name-based refinements)
function familyFromDeclares(cat, name, id) {
  const c = (cat || '').toLowerCase(), n = (name + ' ' + id).toLowerCase();
  if (/wah|cry|gcb|moog|resonan|multifilter|low_high|lowpass|highpass|\bfilter/.test(n)) return 'filter';
  if (/reverb|verb|room|plate|spring|zita|shimmer/.test(n)) return 'reverb';
  if (/delay|echo|copicat|tape/.test(n)) return 'time';
  if (/compress|limit|gate|expand|sustain|transient|duck/.test(n)) return 'dynamics';
  if (/tremolo|vibrato|chorus|flang|phaser|vibe|rotary|leslie|ring|uni/.test(n)) return 'mod';
  if (/octav|pitch|shift|harmon|transpose/.test(n)) return 'pitch';
  if (/tonestack|tone stack|tone|\beq\b|equal|shelf|presence|tilt|cab|impulse|speaker|bassboo|highboo|biquad/.test(n)) return 'eq';
  if (/fuzz|muff|distor|drive|clip|screamer|\brat\b|ds-?1|centaur|boost|scream|hornet|hogs|rangem|buzz|face|ruin|freak|mole|eldist|coverd|axface|astro|lpb|buff/.test(n)) return 'dirt';
  if (/amp|tube|valve|12ax7|preamp|chump|alembic|studiopre|stage|metal|w20|head/.test(n)) return 'amp';
  if (/exciter|humbucker|pickup|speaker|spectral/.test(n)) return 'eq';
  if (/distortion|fuzz/.test(c)) return 'dirt';
  if (/modulation/.test(c)) return 'mod';
  if (/reverb/.test(c)) return 'reverb';
  if (/echo|delay/.test(c)) return 'time';
  if (/tone/.test(c)) return 'eq';
  if (/tube|amp/.test(c)) return 'amp';
  if (/filter/.test(c)) return 'filter';
  return 'utility';
}

const declare = (code, key) => (code.match(new RegExp(`declare\\s+${key}\\s+"([^"]*)"`)) || [])[1] || '';
const cleanLabel = (label) => label.replace(/\[[^\]]*\]/g, '').replace(/_/g, ' ').trim();
const humanize = (s) => s.replace(/^gx-/, '').replace(/([a-z])([A-Z])/g, '$1 $2').replace(/[-_]+/g, ' ').replace(/\b\w/g, c => c.toUpperCase());

const faustModule = await instantiateFaustModuleFromFile(path.join(root, 'vendor/faustwasm/libfaust-wasm.js'));
const compiler = new FaustCompiler(new LibFaust(faustModule));
const ffs = compiler.fs();
console.log(`Faust ${compiler.version()}`);

// Mirror dsp/ and dsp/lib/ into the compiler's in-memory FS so library()/component()/import() resolve.
const mirror = (src, dst) => { try { ffs.mkdirTree(dst); } catch {} for (const e of fs.readdirSync(src, { withFileTypes: true })) { const s = path.join(src, e.name), d = path.posix.join(dst, e.name); if (e.isDirectory()) mirror(s, d); else if (/\.(dsp|lib)$/i.test(e.name)) ffs.writeFile(d, fs.readFileSync(s)); } };
mirror(path.join(root, 'dsp'), '/faust/user/dsp');
const INC = '-I /faust/user/dsp -I /faust/user/dsp/lib';
const libMtime = Math.max(0, ...fs.readdirSync(path.join(root, 'dsp/lib')).filter(f => /\.(lib|dsp)$/.test(f)).map(f => fs.statSync(path.join(root, 'dsp/lib', f)).mtimeMs));

// UI metadata overlays: dsp/catalog.json (Chameleon originals, defines library order) + any dsp/catalog-*.json
const meta = JSON.parse(fs.readFileSync(path.join(root, 'dsp/catalog.json'), 'utf8'));
for (const f of fs.readdirSync(path.join(root, 'dsp')).filter(f => /^catalog-.*\.json$/.test(f))) Object.assign(meta, Object.fromEntries(Object.entries(JSON.parse(fs.readFileSync(path.join(root, 'dsp', f), 'utf8'))).filter(([k]) => !(k in meta))));
const primaryOrder = Object.keys(JSON.parse(fs.readFileSync(path.join(root, 'dsp/catalog.json'), 'utf8')));
const dspFiles = fs.readdirSync(path.join(root, 'dsp')).filter(f => f.endsWith('.dsp')).sort();
const prev = (() => { try { const s = fs.readFileSync(path.join(root, 'js/effects-data.js'), 'utf8'); return eval(s.replace('const EFFECTS_CATALOG', 'var EFFECTS_CATALOG') + ';EFFECTS_CATALOG'); } catch { return []; } })();

const effects = [];
let failed = 0;
const t0 = Date.now();
for (const file of dspFiles) {
  const id = file.replace(/\.dsp$/, '');
  if (only && !id.startsWith(only)) { const p = prev.find(e => e.id === id); if (p) effects.push(p); continue; }
  const code = fs.readFileSync(path.join(root, 'dsp', file), 'utf8');
  const flags = declare(code, 'chameleon_flags');
  const gen = new FaustMonoDspGenerator();
  const pre = path.join(root, 'precompiled', id);
  const fresh = !force && fs.existsSync(path.join(pre, 'dsp-meta.json')) && fs.statSync(path.join(pre, 'dsp-meta.json')).mtimeMs > Math.max(fs.statSync(path.join(root, 'dsp', file)).mtimeMs, libMtime);
  let ok = false, err = null;
  if (fresh) { gen.factory = { code: fs.readFileSync(path.join(pre, 'dsp-module.wasm')), json: fs.readFileSync(path.join(pre, 'dsp-meta.json'), 'utf8') }; ok = true; }
  else for (const args of [`${INC} ${flags} -ftz 2`, `${INC} ${flags}`]) {
    try { ok = await gen.compile(compiler, id.replace(/[^a-zA-Z0-9_]/g, '_'), code, args); if (ok) break; }
    catch (e) { err = e; }
  }
  if (!ok) { console.error(`✗ ${id}: ${String(err && err.message || 'compile failed').split('\n').filter(l => /ERROR/.test(l))[0] || (err && err.message) || ''}`.slice(0, 220)); failed++; continue; }
  const json = JSON.parse(gen.factory.json);
  const items = []; const walk = (list) => list.forEach(it => (it.items ? walk(it.items) : items.push(it))); walk(json.ui);
  const sliders = items.filter(it => /slider|nentry/.test(it.type));
  if (json.inputs !== 1 || json.outputs !== 1) { console.error(`✗ ${id}: expected 1 in / 1 out, got ${json.inputs}/${json.outputs}`); failed++; continue; }
  if (sliders.length === 0) { console.error(`✗ ${id}: no parameters`); failed++; continue; }

  // parameters in source order
  const order = sliders.map(s => ({ s, pos: code.indexOf(`"${s.label}`) })).sort((a, b) => a.pos - b.pos).map(x => x.s);
  const params = order.map(s => ({
    label: cleanLabel(s.label), min: +s.min, max: +s.max, default: +s.init, step: +s.step || 0.001,
    unit: (s.label.match(/\[unit:([^\]]+)\]/) || [])[1] || ((s.meta || []).find(m => m.unit) || {}).unit || '',
    path: s.address,
  }));

  const m = meta[id] || {};
  const name = m.name || declare(code, 'name') || humanize(id);
  const declaredFamily = declare(code, 'family');
  const family = m.family || m.subCategory || (declaredFamily && declaredFamily !== 'utility' ? declaredFamily : null) || familyFromDeclares(declare(code, 'category'), name, id);
  const category = m.category || declare(code, 'category').match(/^(guitar|drum)$/i)?.[1]?.toLowerCase() || (family === 'dynamics' && /drum/.test(id) ? 'drum' : 'guitar');
  const source = m.source || (id.startsWith('gx-') ? 'guitarix' : id.startsWith('lib-') ? 'faustlibraries' : id.startsWith('tdg-') ? 'thedrgreenthumb' : id.startsWith('kpp-') ? 'KPP' : id.startsWith('owl-') ? 'OWL patches' : id.startsWith('ex-') ? 'Faust examples' : id.startsWith('mag-') ? 'magnetophon' : id.startsWith('luca-') ? 'L. Spanedda' : id.startsWith('barabas-') ? 'Barabas5532' : 'Chameleon');
  const license = m.license || declare(code, 'license') || (source === 'Chameleon' ? 'MIT' : '');

  if (!checkOnly && !fresh) {
    const dir = path.join(root, 'precompiled', id); fs.mkdirSync(dir, { recursive: true });
    fs.writeFileSync(path.join(dir, 'dsp-module.wasm'), gen.factory.code);
    fs.writeFileSync(path.join(dir, 'dsp-meta.json'), gen.factory.json);
  }
  effects.push({
    id, name, category, family, familyName: FAMILY_NAME[family] || family, icon: m.icon || FAMILY_ICON[family] || 'tabler:tool',
    tag: m.tag || (category === 'drum' ? 'DrumBrute / Volca' : 'Guitar'), source, license,
    shortDesc: m.shortDesc || declare(code, 'description') || '', description: m.description || declare(code, 'description') || '',
    author: declare(code, 'author') || m.author || '', flags, params, faustCode: code.trim(),
  });
  process.stdout.write(`${fresh ? '=' : '✓'} ${id.padEnd(32)} ${family.padEnd(8)} ${params.length} params  (${params.map(p => p.label).join(' / ').slice(0, 70)})\n`);
}
console.log(`\n${effects.length} effects OK, ${failed} failed, ${((Date.now() - t0) / 1000).toFixed(0)} s`);
if (failed && !only) { console.error('Catalog NOT written — fix the errors above (or move broken files out of dsp/).'); process.exit(1); }
if (checkOnly) process.exit(0);

// order: Chameleon originals first (catalog.json order), then the rest alphabetically by family/name
const orderIds = primaryOrder;
effects.sort((a, b) => { const ia = orderIds.indexOf(a.id), ib = orderIds.indexOf(b.id); if (ia >= 0 || ib >= 0) return (ia < 0 ? 1e9 : ia) - (ib < 0 ? 1e9 : ib); return (a.family + a.name).localeCompare(b.family + b.name); });

const banner = `/**
 * Chameleon Studio - Effect Catalog
 * GENERATED FILE — do not edit by hand.
 * Source of truth: dsp/*.dsp (Faust) + dsp/catalog.json (UI metadata overrides).
 * Regenerate with:  node tools/build-catalog.mjs
 * Built ${new Date().toISOString()} with Faust ${compiler.version()} — ${effects.length} effects
 */
`;
fs.writeFileSync(path.join(root, 'js/effects-data.js'), banner + `const EFFECTS_CATALOG = ${JSON.stringify(effects, null, 1)};

const FAMILY_NAMES = ${JSON.stringify(FAMILY_NAME)};
function getEffectById(id) { return EFFECTS_CATALOG.find(e => e.id === id) || null; }
`);
const libs = fs.readdirSync(path.join(root, 'dsp/lib')).filter(f => /\.(lib|dsp)$/.test(f));
fs.writeFileSync(path.join(root, 'dsp/lib/index.json'), JSON.stringify(libs));
console.log(`Wrote js/effects-data.js (${effects.length} effects) and dsp/lib/index.json (${libs.length} libs).`);
