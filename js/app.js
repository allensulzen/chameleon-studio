/**
 * Chameleon Studio — application
 *
 * Model
 *   patch  = { name, chain: [stage…] (≤ MAX_STAGES), pots: [assign|null ×3] }
 *   stage  = { uid, id (effect id), on, values: { paramPath: number } }
 *   assign = { uid, path }            // physical pot -> one parameter of one stage
 *   state  = { patches[4], current, bypassed, selected (stage uid), playing, source, filter, query }
 *
 * Audio: sample -> stage nodes in series (bypassed stages skipped) -> analyser -> out.
 */
document.addEventListener('DOMContentLoaded', () => {
  const MAX_STAGES = 7, N_PATCHES = 4, PATCH_NAMES = ['A', 'B', 'C', 'D'];
  const FAMILY_HUE = { time: 178, reverb: 200, mod: 268, dirt: 18, dynamics: 112, filter: 44, pitch: 320, amp: 30, eq: 60, utility: 220 };
  const SAMPLES = {
    'di-lead': 'samples/di-lead.wav', 'di-chords': 'samples/di-chords.wav', 'di-riff': 'samples/di-riff.wav', 'di-full-take': 'samples/di-full-take.wav',
    'guitar-heavy': 'samples/guitar-heavy.wav', 'drums-analog': 'samples/drums-analog.wav', 'drums-lofi': 'samples/drums-lofi.wav', 'drums-break': 'samples/drums-break.wav',
  };
  const INPUT_TRIM = { guitar: 0.5, drums: 0.7 };
  const $ = (id) => document.getElementById(id);
  const ico = (n, cls) => (typeof icon === 'function' ? icon(n, cls) : '');

  // ------------------------------------------------------------------
  // State
  // ------------------------------------------------------------------
  let uidCounter = 1;
  const newUid = () => 's' + (uidCounter++) + '_' + Math.random().toString(36).slice(2, 6);
  const effectOf = (stage) => getEffectById(stage.id);
  const defaults = (e) => Object.fromEntries(e.params.map(p => [p.path, p.default]));
  const mkStage = (id) => { const e = getEffectById(id); return { uid: newUid(), id, on: true, values: defaults(e) }; };
  const mkPatch = (name, ids = []) => {
    const p = { name, chain: ids.filter(getEffectById).map(mkStage), pots: [null, null, null], potsLocked: false };
    autoAssign(p); return p;
  };
  function autoAssign(p) {
    // fill empty pots with the first parameters of the first stages
    const taken = new Set(p.pots.filter(Boolean).map(a => a.uid + '|' + a.path));
    for (let k = 0; k < 3; k++) {
      if (p.pots[k] && p.chain.some(s => s.uid === p.pots[k].uid)) continue;
      p.pots[k] = null;
      outer: for (const s of p.chain) for (const prm of effectOf(s).params) { const key = s.uid + '|' + prm.path; if (!taken.has(key)) { p.pots[k] = { uid: s.uid, path: prm.path }; taken.add(key); break outer; } }
    }
  }

  const state = { patches: [], current: 0, bypassed: false, selected: null, playing: false, source: 'di-lead', filter: 'all', sourceFilter: '', query: '' };
  (function load() {
    try {
      const saved = JSON.parse(localStorage.getItem('chameleon.v2') || 'null');
      if (saved && Array.isArray(saved.patches) && saved.patches.length === N_PATCHES) {
        state.patches = saved.patches.map((p, i) => ({ name: p.name || PATCH_NAMES[i], chain: (p.chain || []).filter(s => getEffectById(s.id)).slice(0, MAX_STAGES).map(s => ({ uid: s.uid || newUid(), id: s.id, on: s.on !== false, values: { ...defaults(getEffectById(s.id)), ...(s.values || {}) } })), pots: (p.pots || [null, null, null]).slice(0, 3), potsLocked: !!p.potsLocked }));
        state.patches.forEach(autoAssign);
        state.current = Math.min(N_PATCHES - 1, saved.current || 0); state.source = SAMPLES[saved.source] ? saved.source : state.source;
      }
    } catch (e) {}
    if (!state.patches.length) {
      const pick = (...ids) => ids.filter(getEffectById);
      state.patches = [
        mkPatch('A', pick('klon-centaur', 'tape-delay', 'dattorro-plate')),
        mkPatch('B', pick('gx-ts9sim', 'gx-tremolo', 'spring-reverb')),
        mkPatch('C', pick('gx-fuzzface', 'multi-phaser')),
        mkPatch('D', pick('drum-pumping-comp', 'gated-snare-reverb')),
      ];
    }
  })();
  const patch = () => state.patches[state.current];
  const stageByUid = (uid) => patch().chain.find(s => s.uid === uid);
  function persist() { try { localStorage.setItem('chameleon.v2', JSON.stringify({ patches: state.patches, current: state.current, source: state.source })); } catch (e) {} }

  function hueOf(e) { let h = 0; for (const c of e.id) h = (h * 31 + c.charCodeAt(0)) >>> 0; return (FAMILY_HUE[e.family] || 200) + ((h % 21) - 10); }
  function fmt(v, cfg) {
    if (!cfg.unit && cfg.min >= -1 && cfg.max <= 1) return `${Math.round(v * 100)} %`;
    const d = cfg.step >= 1 ? 0 : cfg.step >= 0.1 ? 1 : cfg.step >= 0.01 ? 2 : 3;
    return `${(+v).toFixed(d)}${cfg.unit ? ' ' + cfg.unit : ''}`;
  }
  const paramOf = (stage, path) => effectOf(stage).params.find(p => p.path === path);

  // ------------------------------------------------------------------
  // DOM
  // ------------------------------------------------------------------
  const el = {
    pedal: $('pedal'), lcdSlot: $('pedal-lcd-slot'), lcdName: $('pedal-lcd-name'), lcdState: $('pedal-lcd-state'), lcdChain: $('pedal-lcd-chain'),
    scope: $('lcd-scope'), led: $('pedal-led'), ledCap: $('pedal-status-text'), foot: $('pedal-footswitch'), print: $('pedal-effect-print'),
    potLock: $('pot-lock'),
    knobs: [1, 2, 3].map(i => $(`knob-${i}`)), kOwner: [1, 2, 3].map(i => $(`knob-${i}-owner`)), kLabels: [1, 2, 3].map(i => $(`knob-${i}-label`)), kVals: [1, 2, 3].map(i => $(`knob-${i}-val`)),
    banks: $('banks'), chain: $('chain'), chainCap: $('chain-caption'), info: $('effect-info'), play: $('btn-play-audio'), sources: $('audio-sources'), meter: $('meter').firstElementChild,
    status: $('preview-engine-status'), chipEngine: $('chip-engine'), chipDevice: $('chip-device'),
    cards: $('effect-cards'), filters: $('filters'), sourceFilter: $('source-filter'), search: $('search-effects'), count: $('library-count'), toast: $('toast'),
    flashModal: $('flash-modal'), codeModal: $('code-modal'), dspModal: $('dsp-modal'),
  };
  // inflate data-icon="" placeholders
  document.querySelectorAll('[data-icon]').forEach(n => n.insertAdjacentHTML('afterbegin', ico(n.dataset.icon)));

  // ------------------------------------------------------------------
  // Rendering
  // ------------------------------------------------------------------
  function renderPedal() {
    const p = patch(); const first = p.chain.find(s => s.on) || p.chain[0];
    const e = first ? effectOf(first) : null;
    document.documentElement.style.setProperty('--acc-h', e ? hueOf(e) : 178);
    el.lcdSlot.textContent = `PATCH ${p.name} · ${p.chain.length}/${MAX_STAGES} STAGES`.toUpperCase();
    el.lcdName.textContent = p.chain.length ? p.chain.map(s => effectOf(s).name).join(' → ') : 'Empty patch';
    el.lcdChain.innerHTML = p.chain.map(s => `<i class="${s.on ? '' : 'off'}" style="--h:${hueOf(effectOf(s))}"></i>`).join('');
    el.print.textContent = e ? e.name : `PATCH ${p.name}`;
    el.lcdState.textContent = state.bypassed ? 'BYPASS' : 'ACTIVE';
    el.pedal.classList.toggle('is-bypassed', state.bypassed);
    el.led.classList.toggle('on', !state.bypassed); el.ledCap.textContent = state.bypassed ? 'BYPASS' : 'ON';
    el.pedal.classList.toggle('pots-locked', !!p.potsLocked);
    el.potLock.classList.toggle('on', !!p.potsLocked); el.potLock.setAttribute('aria-pressed', String(!!p.potsLocked));
    el.potLock.querySelector('.pot-lock-ico').innerHTML = ico(p.potsLocked ? 'tabler:lock' : 'tabler:lock-open');
    el.potLock.querySelector('.pot-lock-text').textContent = p.potsLocked ? 'POTS LOCKED' : 'POTS LIVE';
    el.knobs.forEach(k => k.classList.toggle('locked', !!p.potsLocked));
    p.pots.forEach((a, i) => {
      const s = a && stageByUid(a.uid); const cfg = s && paramOf(s, a.path);
      if (!cfg) { el.kOwner[i].textContent = '—'; el.kLabels[i].textContent = `POT ${i + 1}`; el.kVals[i].textContent = 'unassigned'; el.knobs[i].style.setProperty('--f', 0); el.knobs[i].classList.add('idle'); return; }
      el.knobs[i].classList.remove('idle');
      const v = s.values[a.path];
      el.kOwner[i].textContent = effectOf(s).name; el.kLabels[i].textContent = cfg.label; el.kVals[i].textContent = fmt(v, cfg);
      el.knobs[i].style.setProperty('--f', ((v - cfg.min) / (cfg.max - cfg.min)).toFixed(4));
      el.knobs[i].setAttribute('aria-label', `${effectOf(s).name} ${cfg.label}`); el.knobs[i].setAttribute('aria-valuenow', v);
    });
  }

  function renderBanks() {
    el.banks.innerHTML = state.patches.map((p, i) => `<button class="bank ${i === state.current ? 'active' : ''}" data-bank="${i}" title="Select patch (double-click to rename)">
      <span class="bank-letter">${PATCH_NAMES[i]}</span><span class="bank-name">${escapeHtml(p.name === PATCH_NAMES[i] ? '' : p.name)}</span>
      <span class="bank-mini">${p.chain.map(s => `<i class="${s.on ? '' : 'off'}" style="--h:${hueOf(effectOf(s))}"></i>`).join('') || '<em>empty</em>'}</span></button>`).join('');
  }

  function renderChain() {
    const p = patch();
    el.chainCap.textContent = `${p.chain.length} of ${MAX_STAGES} stages · series, in → out · drag to reorder`;
    el.chain.innerHTML = p.chain.map((s, i) => {
      const e = effectOf(s); const potsHere = p.pots.map((a, k) => a && a.uid === s.uid ? k + 1 : null).filter(Boolean);
      return `<div class="stg ${s.on ? '' : 'off'} ${state.selected === s.uid ? 'selected' : ''}" draggable="true" data-uid="${s.uid}" style="--sh:${hueOf(e)}">
        <div class="stg-top"><span class="stg-num">${i + 1}</span><span class="stg-grip" title="Drag to reorder">${ico('tabler:grip-vertical')}</span>
          <button class="stg-power ${s.on ? 'on' : ''}" data-act="power" title="Bypass this stage">${ico('tabler:power')}</button></div>
        <div class="stg-icon">${ico(e.icon)}</div>
        <div class="stg-name">${escapeHtml(e.name)}</div>
        <div class="stg-foot"><span class="stg-pots">${potsHere.map(k => `<b>P${k}</b>`).join('')}</span><button class="stg-remove" data-act="remove" title="Remove">${ico('tabler:x')}</button></div>
      </div>` + (i < p.chain.length - 1 ? `<span class="chain-arrow">${ico('tabler:arrow-right')}</span>` : '');
    }).join('') + (p.chain.length < MAX_STAGES ? `<button class="stg-add" id="btn-add-stage" title="Add an effect from the library">${ico('tabler:plus')}<span>Add stage</span></button>` : '');
  }

  function renderInfo() {
    const s = state.selected && stageByUid(state.selected);
    if (!s) { el.info.innerHTML = `<div class="ei-empty">${ico('tabler:pointer')} Select a stage in the chain to edit its parameters and choose which ones the pedal's three pots control.</div>`; return; }
    const e = effectOf(s); const p = patch();
    const rows = e.params.map(prm => {
      const v = s.values[prm.path]; const f = (v - prm.min) / (prm.max - prm.min);
      const pots = [0, 1, 2].map(k => { const a = p.pots[k]; const mine = a && a.uid === s.uid && a.path === prm.path; return `<button class="pot-assign ${mine ? 'on' : ''}" data-pot="${k}" data-path="${prm.path}" title="${mine ? 'Assigned to pot ' + (k + 1) : 'Put on pot ' + (k + 1)}">${k + 1}</button>`; }).join('');
      return `<div class="prow" data-path="${prm.path}"><label>${escapeHtml(prm.label)}</label>
        <input type="range" min="0" max="1000" value="${Math.round(f * 1000)}" data-path="${prm.path}">
        <span class="pval">${fmt(v, prm)}</span><span class="pots">${pots}</span></div>`;
    }).join('');
    el.info.innerHTML = `
      <div class="ei-head"><span class="ei-icon" style="--th:${hueOf(e)}">${ico(e.icon)}</span><div><div class="ei-title">${escapeHtml(e.name)}</div>
        <div class="ei-tags"><span class="tag fam" style="--th:${hueOf(e)}">${e.familyName}</span><span class="tag">${escapeHtml(e.source)}</span><span class="tag ${/GPL/.test(e.license) ? 'gpl' : ''}">${escapeHtml(e.license || 'licence?')}</span><span class="tag">${e.params.length} params</span></div></div>
        <div class="ei-actions"><button class="btn btn-ghost btn-sm" data-act="dsp">${ico('tabler:file-code')}<span>Source</span></button><button class="btn btn-ghost btn-sm" data-act="reset">${ico('tabler:rotate')}<span>Reset</span></button></div></div>
      ${e.description ? `<p class="ei-desc">${escapeHtml(e.description)}</p>` : ''}
      <div class="params">${rows}</div>
      <p class="ei-hint">Pots: the pedal has three physical knobs; press 1, 2 or 3 next to a parameter to put it on that knob. Everything else keeps the value you set here.</p>`;
  }

  function matches(e) {
    const f = state.filter;
    if (f !== 'all' && e.category !== f && e.family !== f) return false;
    if (state.sourceFilter && e.source !== state.sourceFilter) return false;
    if (!state.query) return true;
    const q = state.query.toLowerCase();
    return [e.name, e.shortDesc, e.description, e.family, e.familyName, e.source, e.id, e.author, ...e.params.map(p => p.label)].join(' ').toLowerCase().includes(q);
  }
  function renderLibrary() {
    const list = EFFECTS_CATALOG.filter(matches);
    el.count.textContent = `${list.length} of ${EFFECTS_CATALOG.length} effects`;
    if (!list.length) { el.cards.innerHTML = `<div class="cards-empty">Nothing matches “${escapeHtml(state.query)}”.</div>`; return; }
    const inChain = new Set(patch().chain.map(s => s.id));
    el.cards.innerHTML = list.map(e => `<article class="card ${inChain.has(e.id) ? 'loaded' : ''}" draggable="true" data-id="${e.id}" style="--ch:${hueOf(e)}">
        <div class="card-top"><span class="card-icon">${ico(e.icon)}</span><div><div class="card-title">${escapeHtml(e.name)}</div><div class="card-fam">${e.familyName} · ${escapeHtml(e.source)}</div></div>
          ${e.source === 'Chameleon' ? '<span class="logo card-logo" title="Chameleon original"></span>' : ''}<span class="card-lic ${/GPL/.test(e.license) ? 'gpl' : ''}" title="${escapeHtml(e.license)}">${/GPL/.test(e.license) ? 'GPL' : e.license ? e.license.split(/[\s-]/)[0] : '?'}</span></div>
        ${e.shortDesc ? `<p class="card-desc">${escapeHtml(e.shortDesc)}</p>` : ''}
        <div class="card-knobs">${e.params.slice(0, 6).map(p => `<span>${escapeHtml(p.label)}</span>`).join('')}${e.params.length > 6 ? `<span>+${e.params.length - 6}</span>` : ''}</div>
        <div class="card-foot"><button class="btn btn-accent btn-sm" data-add="${e.id}">${ico('tabler:plus')}<span>Add to chain</span></button><button class="src-link" data-dsp="${e.id}">.dsp</button></div>
      </article>`).join('');
  }
  function renderSourceFilter() {
    const srcs = [...new Set(EFFECTS_CATALOG.map(e => e.source))].sort();
    el.sourceFilter.innerHTML = '<option value="">All sources</option>' + srcs.map(s => `<option value="${escapeHtml(s)}">${escapeHtml(s)} (${EFFECTS_CATALOG.filter(e => e.source === s).length})</option>`).join('');
  }
  function renderAll() { renderPedal(); renderBanks(); renderChain(); renderInfo(); renderLibrary(); syncAudio(); persist(); }
  function escapeHtml(s) { return String(s ?? '').replace(/[&<>"']/g, c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;' }[c])); }

  // ------------------------------------------------------------------
  // Actions
  // ------------------------------------------------------------------
  function addStage(id, at = null) {
    const p = patch(); const e = getEffectById(id); if (!e) return;
    if (p.chain.length >= MAX_STAGES) { toast(`Patch ${p.name} already has ${MAX_STAGES} stages`); return; }
    const s = mkStage(id); if (at === null || at >= p.chain.length) p.chain.push(s); else p.chain.splice(at, 0, s);
    autoAssign(p); state.selected = s.uid; renderAll(); toast(`${e.name} → patch ${p.name}`);
  }
  function removeStage(uid) { const p = patch(); p.chain = p.chain.filter(s => s.uid !== uid); p.pots = p.pots.map(a => a && a.uid === uid ? null : a); autoAssign(p); if (state.selected === uid) state.selected = null; renderAll(); }
  function moveStage(uid, to) { const p = patch(); const from = p.chain.findIndex(s => s.uid === uid); if (from < 0) return; const [s] = p.chain.splice(from, 1); p.chain.splice(Math.max(0, Math.min(p.chain.length, to)), 0, s); renderAll(); }
  function selectPatch(i) { state.current = i; state.selected = null; renderAll(); }
  function toggleBypass() { state.bypassed = !state.bypassed; click(); renderPedal(); syncAudio(); }
  function togglePotLock() { const p = patch(); p.potsLocked = !p.potsLocked; click(); renderPedal(); persist(); toast(p.potsLocked ? `Pots locked for patch ${p.name} — the pedal ignores them; edit values here in the studio` : `Pots live for patch ${p.name}`); }
  function cyclePatch() { click(); state.current = (state.current + 1) % N_PATCHES; state.selected = null; blinkLed(state.current + 1); renderAll(); }
  function setValue(stage, path, value, { rerender = true } = {}) {
    const cfg = paramOf(stage, path); value = Math.min(cfg.max, Math.max(cfg.min, value));
    if (cfg.step) value = Math.round(value / cfg.step) * cfg.step;
    stage.values[path] = value; applyParam(stage, path); persist();
    if (rerender) renderPedal();
    // live-update the params panel without rebuilding it
    const row = el.info.querySelector(`.prow[data-path="${CSS.escape(path)}"]`);
    if (row && state.selected === stage.uid) { row.querySelector('.pval').textContent = fmt(value, cfg); row.querySelector('input').value = Math.round(((value - cfg.min) / (cfg.max - cfg.min)) * 1000); }
  }
  function assignPot(k, uid, path) { const p = patch(); const cur = p.pots[k]; p.pots[k] = (cur && cur.uid === uid && cur.path === path) ? null : { uid, path }; p.pots.forEach((a, j) => { if (j !== k && a && a.uid === uid && a.path === path) p.pots[j] = null; }); renderPedal(); renderInfo(); renderChain(); persist(); }
  function blinkLed(n) { el.led.classList.remove('on'); let k = 0; const t = setInterval(() => { el.led.classList.toggle('on'); if (++k >= n * 2) { clearInterval(t); el.led.classList.toggle('on', !state.bypassed); } }, 110); }
  let toastTimer; function toast(msg) { el.toast.textContent = msg; el.toast.classList.add('show'); clearTimeout(toastTimer); toastTimer = setTimeout(() => el.toast.classList.remove('show'), 1800); }

  // ------------------------------------------------------------------
  // Audio: samples -> stage nodes in series -> analyser -> out
  // ------------------------------------------------------------------
  let ctx, inGain, outGain, master, analyser, srcNode = null, buildToken = 0;
  const nodes = new Map();        // stage uid -> { node, id }
  const buffers = new Map(); const scopeData = new Float32Array(1024); let scopeGain = 1;

  function ensureCtx() {
    if (ctx) { if (ctx.state === 'suspended') ctx.resume(); return; }
    ctx = new (window.AudioContext || window.webkitAudioContext)();
    inGain = ctx.createGain(); outGain = ctx.createGain(); master = ctx.createGain(); analyser = ctx.createAnalyser();
    analyser.fftSize = 1024; analyser.smoothingTimeConstant = 0.6; master.gain.value = 0.85;
    outGain.connect(analyser); analyser.connect(master); master.connect(ctx.destination);
  }
  async function loadSample(key) { if (buffers.has(key)) return buffers.get(key); const res = await fetch(SAMPLES[key]); if (!res.ok) throw new Error(`HTTP ${res.status} loading ${SAMPLES[key]}`); const buf = await ctx.decodeAudioData(await res.arrayBuffer()); buffers.set(key, buf); return buf; }
  async function startSource() { stopSource(); const key = state.source; const buf = await loadSample(key); if (!state.playing || state.source !== key) return; const s = ctx.createBufferSource(); s.buffer = buf; s.loop = true; const trim = ctx.createGain(); trim.gain.value = key.startsWith('drums') ? INPUT_TRIM.drums : INPUT_TRIM.guitar; s.connect(trim); trim.connect(inGain); s.start(); srcNode = s; }
  function stopSource() { if (srcNode) { try { srcNode.stop(); srcNode.disconnect(); } catch (e) {} srcNode = null; } }

  async function syncAudio() {
    if (!state.playing) return;
    const p = patch(); const token = ++buildToken;
    const active = state.bypassed ? [] : p.chain.filter(s => s.on);
    // create missing nodes (in parallel), drop stale ones
    const missing = active.filter(s => !nodes.has(s.uid) || nodes.get(s.uid).id !== s.id);
    if (missing.length) setStatus(`Loading ${missing.map(s => effectOf(s).name).join(', ')}…`);
    try {
      await Promise.all(missing.map(async s => { const node = await window.ChameleonFaust.createNode(ctx, effectOf(s)); if (nodes.has(s.uid)) { try { nodes.get(s.uid).node.disconnect(); } catch (e) {} } nodes.set(s.uid, { node, id: s.id }); }));
    } catch (err) { console.error(err); setStatus(`Could not load a stage: ${err.message}`); }
    if (token !== buildToken) return;
    for (const [uid, n] of [...nodes]) if (!p.chain.some(s => s.uid === uid && s.id === n.id)) { try { n.node.disconnect(); n.node.destroy && n.node.destroy(); } catch (e) {} nodes.delete(uid); }
    // wire: in -> s1 -> s2 ... -> out
    try { inGain.disconnect(); } catch (e) {}
    nodes.forEach(n => { try { n.node.disconnect(); } catch (e) {} });
    let prev = inGain;
    for (const s of active) { const n = nodes.get(s.uid); if (!n) continue; applyAll(s); prev.connect(n.node); prev = n.node; }
    prev.connect(outGain);
    setStatus(state.bypassed ? 'Bypassed — dry signal' : active.length ? `Live · ${active.map(s => effectOf(s).name).join(' → ')} · real Faust DSP` : 'Live · empty chain (dry)');
  }
  function applyAll(s) { const n = nodes.get(s.uid); if (!n) return; for (const [path, v] of Object.entries(s.values)) n.node.setParamValue(path, v); }
  function applyParam(s, path) { const n = nodes.get(s.uid); if (n) n.node.setParamValue(path, s.values[path]); }

  async function play() {
    const faust = window.ChameleonFaust;
    if (!faust || faust.status === 'error') { toast('Faust engine unavailable — serve the app with python3 server.py'); return; }
    ensureCtx(); state.playing = true; el.play.classList.add('playing'); await faust.ready;
    try { await startSource(); } catch (err) { toast(`Sample failed to load: ${err.message}`); }
    await syncAudio(); drawScope();
  }
  function stop() { state.playing = false; el.play.classList.remove('playing'); stopSource(); setStatus(`Faust ${window.ChameleonFaust?.version || ''} ready — previews use the real dsp/*.dsp algorithms`); }

  const sc = el.scope.getContext('2d'); let raf;
  function drawScope() {
    cancelAnimationFrame(raf); const W = el.scope.width, H = el.scope.height;
    const tick = () => {
      if (!state.playing) { sc.clearRect(0, 0, W, H); el.meter.style.width = '0%'; return; }
      analyser.getFloatTimeDomainData(scopeData);
      const acc = getComputedStyle(document.documentElement).getPropertyValue('--acc-hi').trim();
      sc.clearRect(0, 0, W, H); sc.strokeStyle = 'rgba(255,255,255,.05)'; sc.lineWidth = 1;
      for (let x = 0; x < W; x += W / 8) { sc.beginPath(); sc.moveTo(x, 0); sc.lineTo(x, H); sc.stroke(); }
      sc.beginPath(); sc.moveTo(0, H / 2); sc.lineTo(W, H / 2); sc.stroke();
      let peak = 0; for (let i = 0; i < scopeData.length; i++) peak = Math.max(peak, Math.abs(scopeData[i]));
      const target = Math.min(6, 0.85 / Math.max(peak, 0.02)); scopeGain += (target - scopeGain) * (target < scopeGain ? 0.5 : 0.05);
      sc.beginPath(); sc.strokeStyle = acc; sc.lineWidth = 2; sc.shadowColor = acc; sc.shadowBlur = 8;
      for (let i = 0; i < scopeData.length; i++) { const v = scopeData[i] * scopeGain; const x = (i / scopeData.length) * W, y = H / 2 - Math.max(-1, Math.min(1, v)) * (H / 2) * 0.9 - 0.5; i ? sc.lineTo(x, y) : sc.moveTo(x, y); }
      sc.stroke(); sc.shadowBlur = 0; el.meter.style.width = `${Math.min(100, Math.pow(peak, 0.6) * 100)}%`;
      raf = requestAnimationFrame(tick);
    };
    tick();
  }
  function setStatus(t) { el.status.textContent = t; }
  function click() { if (!ctx) return; const o = ctx.createOscillator(), g = ctx.createGain(); o.frequency.value = 900; g.gain.setValueAtTime(0.08, ctx.currentTime); g.gain.exponentialRampToValueAtTime(0.001, ctx.currentTime + 0.03); o.connect(g); g.connect(ctx.destination); o.start(); o.stop(ctx.currentTime + 0.03); }

  // ------------------------------------------------------------------
  // Physical pots
  // ------------------------------------------------------------------
  const potTarget = (i, quiet) => { if (patch().potsLocked) { if (!quiet) toast(`Pots are locked for patch ${patch().name} — unlock them or edit the value in the stage panel`); return null; } const a = patch().pots[i]; const s = a && stageByUid(a.uid); const cfg = s && paramOf(s, a.path); return cfg ? { s, cfg, path: a.path } : null; };
  el.knobs.forEach((knob, i) => {
    let drag = null;
    knob.addEventListener('pointerdown', (ev) => { const t = potTarget(i); if (!t) { if (!patch().potsLocked) toast('This pot has nothing assigned — pick a parameter in a stage'); return; } knob.setPointerCapture(ev.pointerId); knob.focus(); drag = { y: ev.clientY, v: t.s.values[t.path] }; document.body.style.cursor = 'ns-resize'; });
    knob.addEventListener('pointermove', (ev) => { if (!drag) return; const t = potTarget(i, true); if (!t) return; const range = t.cfg.max - t.cfg.min; setValue(t.s, t.path, drag.v + ((drag.y - ev.clientY) / (ev.shiftKey ? 900 : 180)) * range); });
    const end = () => { drag = null; document.body.style.cursor = ''; };
    knob.addEventListener('pointerup', end); knob.addEventListener('pointercancel', end);
    knob.addEventListener('wheel', (ev) => { ev.preventDefault(); const t = potTarget(i); if (!t) return; const range = t.cfg.max - t.cfg.min; setValue(t.s, t.path, t.s.values[t.path] - Math.sign(ev.deltaY) * range * (ev.shiftKey ? 0.005 : 0.02)); }, { passive: false });
    knob.addEventListener('dblclick', () => { const t = potTarget(i); if (!t) return; setValue(t.s, t.path, t.cfg.default); toast('Reset'); });
    knob.addEventListener('keydown', (ev) => { const t = potTarget(i); if (!t) return; const step = (t.cfg.max - t.cfg.min) * (ev.shiftKey ? 0.002 : 0.02); if (['ArrowUp', 'ArrowRight'].includes(ev.key)) { setValue(t.s, t.path, t.s.values[t.path] + step); ev.preventDefault(); } if (['ArrowDown', 'ArrowLeft'].includes(ev.key)) { setValue(t.s, t.path, t.s.values[t.path] - step); ev.preventDefault(); } });
    knob.addEventListener('click', () => { const t = potTarget(i, true); if (t && state.selected !== t.s.uid) { state.selected = t.s.uid; renderChain(); renderInfo(); } });
  });

  // Footswitch: tap = bypass, hold = next patch
  { let holdTimer = null, held = false; const HOLD_MS = 650;
    el.potLock.addEventListener('click', togglePotLock);
    el.foot.addEventListener('pointerdown', (ev) => { ev.preventDefault(); held = false; el.foot.classList.add('pressed', 'holding'); holdTimer = setTimeout(() => { held = true; el.foot.classList.remove('holding'); cyclePatch(); }, HOLD_MS); });
    const release = () => { if (!el.foot.classList.contains('pressed')) return; clearTimeout(holdTimer); el.foot.classList.remove('pressed', 'holding'); if (!held) toggleBypass(); };
    el.foot.addEventListener('pointerup', release); el.foot.addEventListener('pointerleave', release); el.foot.addEventListener('pointercancel', release);
    el.foot.addEventListener('contextmenu', (e) => { e.preventDefault(); cyclePatch(); }); }

  // ------------------------------------------------------------------
  // Banks, chain, params panel, library
  // ------------------------------------------------------------------
  el.banks.addEventListener('click', (e) => { const b = e.target.closest('.bank'); if (b) selectPatch(+b.dataset.bank); });
  el.banks.addEventListener('dblclick', (e) => { const b = e.target.closest('.bank'); if (!b) return; const p = state.patches[+b.dataset.bank]; const n = prompt('Patch name', p.name); if (n !== null && n.trim()) { p.name = n.trim().slice(0, 18); renderAll(); } });

  el.chain.addEventListener('click', (e) => {
    if (e.target.closest('#btn-add-stage')) { document.getElementById('library').scrollIntoView({ behavior: 'smooth' }); el.search.focus(); return; }
    const st = e.target.closest('.stg'); if (!st) return; const uid = st.dataset.uid; const act = e.target.closest('[data-act]');
    if (act && act.dataset.act === 'power') { const s = stageByUid(uid); s.on = !s.on; renderAll(); return; }
    if (act && act.dataset.act === 'remove') { removeStage(uid); return; }
    state.selected = uid; renderChain(); renderInfo();
  });
  // drag & drop: reorder stages, or drop a library card into the chain
  let dragUid = null;
  el.chain.addEventListener('dragstart', (e) => { const st = e.target.closest('.stg'); if (!st) return; dragUid = st.dataset.uid; e.dataTransfer.setData('text/stage-uid', dragUid); e.dataTransfer.effectAllowed = 'move'; st.classList.add('dragging'); });
  el.chain.addEventListener('dragend', () => { dragUid = null; el.chain.querySelectorAll('.dragging, .drop-before, .drop-after').forEach(x => x.classList.remove('dragging', 'drop-before', 'drop-after')); el.chain.classList.remove('drop-target'); });
  el.chain.addEventListener('dragover', (e) => { e.preventDefault(); el.chain.classList.add('drop-target'); const st = e.target.closest('.stg'); el.chain.querySelectorAll('.drop-before, .drop-after').forEach(x => x.classList.remove('drop-before', 'drop-after')); if (st) { const r = st.getBoundingClientRect(); st.classList.add(e.clientX < r.left + r.width / 2 ? 'drop-before' : 'drop-after'); } });
  el.chain.addEventListener('dragleave', (e) => { if (!el.chain.contains(e.relatedTarget)) el.chain.classList.remove('drop-target'); });
  el.chain.addEventListener('drop', (e) => {
    e.preventDefault(); const p = patch(); const st = e.target.closest('.stg');
    let index = p.chain.length; if (st) { const r = st.getBoundingClientRect(); index = p.chain.findIndex(s => s.uid === st.dataset.uid) + (e.clientX < r.left + r.width / 2 ? 0 : 1); }
    const uid = e.dataTransfer.getData('text/stage-uid'); const id = e.dataTransfer.getData('text/effect-id');
    if (uid) { const from = p.chain.findIndex(s => s.uid === uid); if (from >= 0 && index > from) index--; moveStage(uid, index); }
    else if (id) addStage(id, index);
    el.chain.classList.remove('drop-target');
  });

  el.info.addEventListener('input', (e) => { const r = e.target.closest('input[type=range]'); if (!r) return; const s = stageByUid(state.selected); if (!s) return; const cfg = paramOf(s, r.dataset.path); setValue(s, r.dataset.path, cfg.min + (r.value / 1000) * (cfg.max - cfg.min)); });
  el.info.addEventListener('click', (e) => {
    const s = stageByUid(state.selected); if (!s) return;
    const pa = e.target.closest('.pot-assign'); if (pa) { assignPot(+pa.dataset.pot, s.uid, pa.dataset.path); return; }
    const b = e.target.closest('[data-act]'); if (!b) return;
    if (b.dataset.act === 'dsp') openDsp(s.id);
    if (b.dataset.act === 'reset') { s.values = defaults(effectOf(s)); applyAll(s); renderAll(); toast('Parameters reset'); }
  });
  el.info.addEventListener('dblclick', (e) => { const r = e.target.closest('input[type=range]'); if (!r) return; const s = stageByUid(state.selected); if (!s) return; setValue(s, r.dataset.path, paramOf(s, r.dataset.path).default); });

  el.cards.addEventListener('click', (e) => {
    const add = e.target.closest('[data-add]'); const dsp = e.target.closest('[data-dsp]');
    if (add) { addStage(add.dataset.add); return; }
    if (dsp) { openDsp(dsp.dataset.dsp); return; }
  });
  el.cards.addEventListener('dblclick', (e) => { const c = e.target.closest('.card'); if (c) addStage(c.dataset.id); });
  el.cards.addEventListener('dragstart', (e) => { const c = e.target.closest('.card'); if (!c) return; e.dataTransfer.setData('text/effect-id', c.dataset.id); e.dataTransfer.effectAllowed = 'copy'; c.classList.add('dragging'); });
  el.cards.addEventListener('dragend', (e) => { const c = e.target.closest('.card'); if (c) c.classList.remove('dragging'); });
  el.filters.addEventListener('click', (e) => { const p = e.target.closest('.pill'); if (!p) return; state.filter = p.dataset.filter; el.filters.querySelectorAll('.pill').forEach(x => x.classList.toggle('active', x === p)); renderLibrary(); });
  el.sourceFilter.addEventListener('change', () => { state.sourceFilter = el.sourceFilter.value; renderLibrary(); });
  el.search.addEventListener('input', () => { state.query = el.search.value.trim(); renderLibrary(); });
  $('btn-clear-chain').addEventListener('click', () => { const p = patch(); if (!p.chain.length) return; if (!confirm(`Clear all ${p.chain.length} stages from patch ${p.name}?`)) return; p.chain = []; p.pots = [null, null, null]; state.selected = null; renderAll(); });

  // patch import / export
  $('btn-export-patch').addEventListener('click', () => download('chameleon-patches.json', JSON.stringify({ version: 2, patches: state.patches }, null, 2)));
  $('file-import-patch').addEventListener('change', async (e) => {
    const f = e.target.files[0]; if (!f) return;
    try { const j = JSON.parse(await f.text()); if (!Array.isArray(j.patches)) throw new Error('no patches array'); localStorage.setItem('chameleon.v2', JSON.stringify({ patches: j.patches.slice(0, N_PATCHES), current: 0, source: state.source })); location.reload(); }
    catch (err) { toast('Could not import: ' + err.message); }
    e.target.value = '';
  });

  // ------------------------------------------------------------------
  // Audition controls + keyboard
  // ------------------------------------------------------------------
  el.play.addEventListener('click', () => state.playing ? stop() : play());
  el.sources.addEventListener('click', (e) => { const b = e.target.closest('.src'); if (!b) return; state.source = b.dataset.src; el.sources.querySelectorAll('.src').forEach(x => x.classList.toggle('active', x === b)); persist(); if (state.playing) startSource().catch(err => toast(err.message)); });
  el.sources.querySelectorAll('.src').forEach(b => b.classList.toggle('active', b.dataset.src === state.source));
  document.addEventListener('keydown', (e) => {
    if (e.target.matches('input, textarea, select')) return;
    if (e.code === 'Space') { e.preventDefault(); state.playing ? stop() : play(); }
    else if (e.key === 'b' || e.key === 'B') toggleBypass();
    else if (e.key === 'l' || e.key === 'L') togglePotLock();
    else if (['1', '2', '3', '4'].includes(e.key)) selectPatch(+e.key - 1);
    else if ((e.key === 'Delete' || e.key === 'Backspace') && state.selected) removeStage(state.selected);
    else if (e.key === 'Escape') document.querySelectorAll('.modal.open').forEach(m => m.classList.remove('open'));
  });

  // ------------------------------------------------------------------
  // Modals: DSP source, firmware, flash
  // ------------------------------------------------------------------
  let dspShown = null;
  function openDsp(id) { const e = getEffectById(id); dspShown = e; $('dsp-modal-title').textContent = `${e.name} — dsp/${e.id}.dsp`; $('dsp-modal-meta').textContent = [e.author && `Author: ${e.author}`, e.license && `Licence: ${e.license}`, e.source && `Source: ${e.source}`, e.flags && `Compile flags: ${e.flags}`].filter(Boolean).join(' · '); $('dsp-code').textContent = e.faustCode; el.dspModal.classList.add('open'); }
  $('btn-copy-dsp').addEventListener('click', () => { navigator.clipboard.writeText($('dsp-code').textContent); toast('Faust source copied'); });
  $('btn-download-dsp').addEventListener('click', () => dspShown && download(`${dspShown.id}.dsp`, dspShown.faustCode + '\n'));
  document.querySelectorAll('.close-modal').forEach(b => b.addEventListener('click', () => b.closest('.modal').classList.remove('open')));
  document.querySelectorAll('.modal').forEach(m => m.addEventListener('click', (e) => { if (e.target === m) m.classList.remove('open'); }));
  $('btn-open-code').addEventListener('click', () => { $('code-content').textContent = generateFirmware(); el.codeModal.classList.add('open'); });
  $('btn-copy-code').addEventListener('click', () => { navigator.clipboard.writeText($('code-content').textContent); toast('Firmware copied'); });
  $('btn-download-code').addEventListener('click', () => download('patches.h', $('code-content').textContent));
  $('btn-open-flash').addEventListener('click', () => el.flashModal.classList.add('open'));
  const dfu = new ChameleonDFU();
  // Device awareness. A running Chameleon shows up as a USB serial port (ST CDC 0483:5740) — that's
  // how the studio recognises it and how it sends it to the bootloader. In DFU it's a WebUSB device
  // (0483:DF11). Both are paired once per computer through the browser's picker; after that they're
  // recognised automatically.
  const ST = 0x0483, PID_CDC = 0x5740, PID_DFU = 0xdf11;
  let serialPort = null;
  function setDevice(kind, label) {
    el.chipDevice.className = 'chip chip-btn' + (kind ? ' ok' : '');
    el.chipDevice.lastElementChild.textContent = label;
  }
  async function scanDevices() {
    if (!navigator.usb) { setDevice(null, 'WebUSB not available in this browser'); return; }
    try {
      const ports = navigator.serial ? await navigator.serial.getPorts() : [];
      serialPort = ports.find(p => { const i = p.getInfo(); return i.usbVendorId === ST && (i.usbProductId === PID_CDC || i.usbProductId == null); }) || null;
      const devs = await navigator.usb.getDevices();
      const dfuDev = devs.find(d => d.vendorId === ST && d.productId === PID_DFU);
      if (serialPort) setDevice('run', 'Chameleon connected — ready to flash');
      else if (dfuDev) setDevice('dfu', `Seed in bootloader (${dfuDev.productName || 'DFU'})`);
      else setDevice(null, 'No pedal connected — click to pair');
    } catch (e) { setDevice(null, 'No pedal connected — click to pair'); }
  }
  if (navigator.usb) { navigator.usb.addEventListener('connect', scanDevices); navigator.usb.addEventListener('disconnect', scanDevices); }
  if (navigator.serial) { navigator.serial.addEventListener('connect', scanDevices); navigator.serial.addEventListener('disconnect', scanDevices); }
  el.chipDevice.addEventListener('click', async () => {
    if (!navigator.usb) return;
    try {
      if (navigator.serial) { await navigator.serial.requestPort({ filters: [{ usbVendorId: ST }] }); toast('Paired — the pedal will be recognised automatically from now on'); }
      else { await navigator.usb.requestDevice({ filters: [{ vendorId: ST }] }); toast('Paired'); }
    } catch (e) { toast('No device chosen — is the pedal plugged in with a data cable?'); }
    scanDevices();
  });
  scanDevices();

  // Ask a running pedal to reboot into the bootloader over its serial port. Resolves when the DFU device shows up.
  async function rebootToDfu(log) {
    if (!serialPort) { const ports = await navigator.serial.getPorts(); serialPort = ports.find(p => p.getInfo().usbVendorId === ST) || null; }
    if (!serialPort) return false;
    log('Asking the pedal to enter update mode…');
    await serialPort.open({ baudRate: 115200 });
    const w = serialPort.writable.getWriter(); await w.write(new TextEncoder().encode('DFU\n')); w.releaseLock();
    try { await serialPort.close(); } catch (e) {}
    serialPort = null;
    for (let i = 0; i < 40; i++) { await new Promise(r => setTimeout(r, 250)); const devs = await navigator.usb.getDevices(); if (devs.some(d => d.vendorId === ST && d.productId === PID_DFU)) return true; }
    return 'unpaired';   // it rebooted but this computer hasn't paired the DFU device yet — the picker will handle it
  }

  // Firmware image metadata (written by tools/build-firmware.mjs --make)
  let fwInfo = null;
  async function loadFwInfo() {
    try { fwInfo = await (await fetch('firmware/chameleon.json', { cache: 'no-store' })).json(); }
    catch (e) { fwInfo = { address: 0x08000000, appType: 'BOOT_NONE', note: 'no chameleon.json — assuming an internal-flash image' }; }
    const qspi = fwInfo.address >= 0x90000000;
    $('flash-image-info').innerHTML = `<b>${fwInfo.effects ? fwInfo.effects.length + ' effect(s): ' + fwInfo.effects.join(', ') : 'firmware/chameleon.bin'}</b> · ${fwInfo.size ? (fwInfo.size / 1024).toFixed(0) + ' KB' : ''} · ${qspi ? 'runs from QSPI via the Daisy bootloader' : 'internal flash (no bootloader needed)'}${fwInfo.built ? ' · built ' + fwInfo.built.slice(0, 10) : ''}`;
    $('btn-install-boot').hidden = !qspi;
  }
  $('btn-open-flash').addEventListener('click', loadFwInfo);
  async function flashImage(url, address, label) {
    const log = $('flash-status-text'), bar = $('flash-progress');
    log.textContent = `Fetching ${label}…`; bar.style.width = '0%';
    const res = await fetch(url, { cache: 'no-store' });
    if (!res.ok) throw new Error(`${url} is missing — run tools/build-firmware.mjs --make (see README)`);
    const bin = await res.arrayBuffer();
    if (navigator.serial && address >= 0x90000000) { const r = await rebootToDfu(m => { log.textContent = m; }); if (r === 'unpaired') log.textContent = 'Pedal is in update mode — pick it in the dialog (one-time on this computer)…'; }
    log.textContent = log.textContent || 'Requesting USB device…';
    await dfu.connect();
    dfu.onProgress = (p) => { bar.style.width = `${p}%`; log.textContent = `Flashing ${label} ${(bin.byteLength / 1024).toFixed(1)} KB → 0x${address.toString(16)}… ${p}%`; };
    if (address >= 0x90000000 && !dfu.isDaisyBootloader) throw new Error('This is the STM32 DFU (no QSPI). Install the Daisy bootloader first, then tap RESET and press BOOT while the LED breathes.');
    if (address === 0x08000000 && dfu.isDaisyBootloader && !/bootloader/i.test(label)) throw new Error('You are in the Daisy bootloader — this image is for internal flash. Rebuild with APP_TYPE=BOOT_QSPI.');
    await dfu.flash(bin, { address });
    return bin.byteLength;
  }
  $('btn-start-flash').addEventListener('click', async () => {
    const log = $('flash-status-text'), btn = $('btn-start-flash');
    try {
      btn.disabled = true; if (!fwInfo) await loadFwInfo();
      await flashImage('firmware/chameleon.bin', fwInfo.address || 0x08000000, 'Chameleon');
      log.textContent = 'Done — the pedal rebooted into the new firmware.'; $('flash-progress').style.width = '100%'; setTimeout(scanDevices, 2500);
    } catch (err) { log.textContent = `⚠ ${err.message}`; } finally { btn.disabled = false; }
  });
  $('btn-install-boot').addEventListener('click', async () => {
    const log = $('flash-status-text'), btn = $('btn-install-boot');
    try {
      btn.disabled = true;
      await flashImage('firmware/dsy_bootloader.bin', 0x08000000, 'Daisy bootloader');
      log.textContent = 'Bootloader installed. Now: tap RESET, press BOOT once while the LED breathes, then Connect & flash.'; $('flash-progress').style.width = '100%';
    } catch (err) { log.textContent = `⚠ ${err.message}`; } finally { btn.disabled = false; }
  });
  function download(name, content) { const a = document.createElement('a'); a.href = 'data:text/plain;charset=utf-8,' + encodeURIComponent(content); a.download = name; a.click(); }

  // ------------------------------------------------------------------
  // Firmware exporter
  // ------------------------------------------------------------------
  // Emits firmware/patches.h exactly as tools/build-firmware.mjs does, from the live patches.
  function generateFirmware() {
    const used = []; state.patches.forEach(p => p.chain.forEach(s => { if (!used.includes(s.id)) used.push(s.id); }));
    const cls = (id) => id.replace(/(^|-)([a-z0-9])/g, (_, __, c) => c.toUpperCase());
    const cstr = (x) => JSON.stringify(String(x));
    const f = (v) => { let t = String(+Number(v).toPrecision(7)); if (!/[.e]/.test(t)) t += '.0'; return t + 'f'; };
    const L = [];
    L.push(`// GENERATED by Chameleon Studio (${new Date().toISOString().slice(0, 10)}) — same format as tools/build-firmware.mjs`);
    L.push('// Effects used: ' + (used.join(', ') || '(none)') + '\n// Generate their C++ with:  cd firmware && ./gen-faust.sh ' + used.join(' '));
    L.push('#pragma once');
    used.forEach(id => L.push(`#include "faust/${id}.h"`));
    L.push('', '#define CH_EFFECTS(X) \\', used.map(id => `    X(${cls(id)}, ${cstr(id)})`).join(' \\\n') || '    /* no effects */', '');
    L.push('enum { NUM_PATCHES = 4, MAX_STAGES = 7, MAX_VALUES = 24 };');
    L.push('struct ValueDef { const char* path; float value; };');
    L.push('struct StageDef { int effect; bool on; int nvalues; ValueDef values[MAX_VALUES]; };');
    L.push('struct PotDef   { int stage; const char* path; };');
    L.push('struct PatchDef { const char* name; bool potsLocked; int hue; int nstages; StageDef stages[MAX_STAGES]; PotDef pots[3]; };', '');
    L.push('static const PatchDef PATCHES[NUM_PATCHES] = {');
    state.patches.forEach((p, pi) => {
      const first = p.chain.find(x => x.on) || p.chain[0];
      const hue = first ? hueOf(effectOf(first)) : 178;
      const stages = p.chain.map(st => { const e = effectOf(st); const vals = e.params.slice(0, 24).map(prm => `{ ${cstr(prm.path)}, ${f(st.values[prm.path] ?? prm.default)} }`); return `      { ${used.indexOf(st.id)}, ${st.on ? 'true' : 'false'}, ${vals.length}, { ${vals.join(', ')} } }`; });
      const pots = [0, 1, 2].map(k => { const a = p.pots[k]; const si = a ? p.chain.findIndex(x => x.uid === a.uid) : -1; return si >= 0 ? `{ ${si}, ${cstr(a.path)} }` : '{ -1, "" }'; });
      L.push(`    // Patch ${PATCH_NAMES[pi]}: ${p.chain.map(x => effectOf(x).name).join(' -> ') || '(empty)'}${p.potsLocked ? '  [pots locked]' : ''}`);
      L.push(`    { ${cstr(p.name)}, ${p.potsLocked ? 'true' : 'false'}, ${hue}, ${stages.length},`);
      L.push(`      { ${stages.length ? '\n' + stages.join(',\n') + '\n      ' : ''}},`);
      L.push(`      { ${pots.join(', ')} } },`);
    });
    L.push('};');
    return L.join('\n') + '\n';
  }

  // ------------------------------------------------------------------
  // Boot
  // ------------------------------------------------------------------
  const faust = window.ChameleonFaust;
  if (faust) {
    faust.ready.then(() => {
      if (faust.status === 'ready') { el.chipEngine.className = 'chip ok'; el.chipEngine.lastElementChild.textContent = `Faust ${faust.version} · ${EFFECTS_CATALOG.length} effects`; setStatus(`Faust ${faust.version} ready — previews use the real dsp/*.dsp algorithms`); }
      else { el.chipEngine.className = 'chip err'; el.chipEngine.lastElementChild.textContent = 'Faust failed to load'; setStatus('Faust engine failed to load — serve the app with python3 server.py'); }
    });
  } else { el.chipEngine.className = 'chip err'; el.chipEngine.lastElementChild.textContent = 'No Faust engine'; setStatus('Faust engine not loaded — open the app via python3 server.py, not file://'); }
  renderSourceFilter();
  renderAll();
});
