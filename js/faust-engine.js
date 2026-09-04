/**
 * Chameleon Studio — in-browser Faust engine
 *
 * Compiles the exact same Faust code that lives in dsp/*.dsp (via effects-data.js)
 * into a Web Audio AudioWorklet node using faustwasm, so what you hear in the
 * browser IS the algorithm that goes on the pedal — no hand-made approximations.
 *
 * Exposed as window.ChameleonFaust for the non-module app.js:
 *   ChameleonFaust.ready            -> Promise that resolves when the compiler is loaded
 *   ChameleonFaust.status           -> 'loading' | 'ready' | 'error'
 *   ChameleonFaust.createNode(ctx, effect) -> Promise<AudioWorkletNode-like Faust node>
 *   node.setParamValue(path, value) -> real-time parameter change
 *
 * Requires the app to be served over http(s) (python3 server.py) — module
 * imports and .wasm fetches don't work from file://.
 */
import {
  instantiateFaustModuleFromFile,
  LibFaust,
  FaustCompiler,
  FaustMonoDspGenerator,
  FaustWasmInstantiator,
} from '../vendor/faustwasm/index.js';

const engine = {
  status: 'loading',
  error: null,
  version: null,
  compiler: null,
  generators: new Map(), // effect id -> compiled FaustMonoDspGenerator
  ready: null,
};

engine.libsLoaded = false;
// Only needed for the in-browser compile fallback: mirror dsp/lib/*.lib (guitarix tables etc.) into the compiler FS.
engine.loadLibs = async function () {
  if (engine.libsLoaded) return;
  try {
    const list = await (await fetch('dsp/lib/index.json')).json();
    const ffs = engine.compiler.fs();
    try { ffs.mkdirTree('/faust/user/lib'); } catch (e) {}
    await Promise.all(list.map(async (f) => { const t = await (await fetch('dsp/lib/' + f)).text(); ffs.writeFile('/faust/user/lib/' + f, t); }));
    engine.libsLoaded = true;
  } catch (e) { console.warn('[ChameleonFaust] could not load dsp/lib for in-browser compile', e); }
};

engine.ready = (async () => {
  try {
    const faustModule = await instantiateFaustModuleFromFile('vendor/faustwasm/libfaust-wasm.js');
    const libFaust = new LibFaust(faustModule);
    engine.compiler = new FaustCompiler(libFaust);
    engine.version = engine.compiler.version();
    engine.status = 'ready';
    console.log(`[ChameleonFaust] Faust compiler ${engine.version} ready`);
  } catch (err) {
    engine.status = 'error';
    engine.error = err;
    console.error('[ChameleonFaust] failed to load the Faust compiler', err);
  }
})();

/**
 * Compile (once, cached) and instantiate a Faust node for an effect.
 * @param {AudioContext} ctx
 * @param {{id:string, faustCode:string}} effect
 */
engine.createNode = async function createNode(ctx, effect) {
  await engine.ready;
  if (engine.status !== 'ready') throw engine.error || new Error('Faust compiler not available');

  let gen = engine.generators.get(effect.id);
  if (!gen) {
    gen = new FaustMonoDspGenerator();
    const t0 = performance.now();
    const name = effect.id.replace(/[^a-zA-Z0-9_]/g, '_');
    let loaded = false;
    // Fast path: precompiled module written by tools/build-catalog.mjs (same source, same compiler).
    try {
      const factory = await FaustWasmInstantiator.loadDSPFactory(`precompiled/${effect.id}/dsp-module.wasm`, `precompiled/${effect.id}/dsp-meta.json`);
      if (factory) { gen.factory = factory; loaded = true; console.log(`[ChameleonFaust] loaded precompiled ${effect.id} in ${(performance.now() - t0).toFixed(0)} ms`); }
    } catch (e) { console.log(`[ChameleonFaust] no precompiled build for ${effect.id}, compiling in browser`); }
    if (!loaded) {
      await engine.loadLibs();
      const flags = `-I /faust/user/lib ${effect.flags || ''}`;
      let ok = false;
      try { ok = await gen.compile(engine.compiler, name, effect.faustCode, `${flags} -ftz 2`); }
      catch (e) { console.warn(`[ChameleonFaust] ${effect.id}: retrying without -ftz (compiler bug with some WDF code)`, e); }
      if (!ok) ok = await gen.compile(engine.compiler, name, effect.faustCode, flags);
      if (!ok) throw new Error(`Faust compile failed for ${effect.id}`);
      console.log(`[ChameleonFaust] compiled ${effect.id} in ${(performance.now() - t0).toFixed(0)} ms`);
    }
    engine.generators.set(effect.id, gen);
  }
  const node = await gen.createNode(ctx, effect.id.replace(/[^a-zA-Z0-9_]/g, '_'), gen.factory);
  if (!node) throw new Error(`Could not create audio node for ${effect.id}`);
  return node;
};

window.ChameleonFaust = engine;
