#!/usr/bin/env node
/**
 * Render one effect offline through a WAV file — hear an effect without a browser or a pedal.
 *
 * usage: node tools/render-effect.mjs <effect-id> <input.wav> <output.wav> [Knob=value ...]
 *   e.g. node tools/render-effect.mjs tape-delay samples/guitar-lead.wav /tmp/out.wav Feedback=0.9 Time=350
 * Knob names match the slider labels in the .dsp (case-insensitive substring); values are in slider units.
 * Output is 48 kHz 32-bit float mono, 10 s long; prints the peak level and flags NaN.
 */
import fs from 'fs'; import path from 'path';
import { fileURLToPath } from 'url';
import { instantiateFaustModuleFromFile, LibFaust, FaustCompiler, FaustMonoDspGenerator, WavDecoder } from '../vendor/faustwasm/index.js';
const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const [id, inWav, outWav, ...params] = process.argv.slice(2);
if (!id || !inWav || !outWav) { console.error('usage: node tools/render-effect.mjs <effect-id> <input.wav> <output.wav> [Knob=value ...]'); process.exit(1); }
const SR = 48000, N = 480000;
const fm = await instantiateFaustModuleFromFile(path.join(root, 'vendor/faustwasm/libfaust-wasm.js'));
const compiler = new FaustCompiler(new LibFaust(fm));
const gen = new FaustMonoDspGenerator();
await gen.compile(compiler, id.replace(/[^a-zA-Z0-9_]/g, '_'), fs.readFileSync(path.join(root, `dsp/${id}.dsp`), 'utf8'), '');
const proc = await gen.createOfflineProcessor(SR, 64);
const buf = fs.readFileSync(inWav); const input = WavDecoder.decode(buf.buffer.slice(buf.byteOffset, buf.byteOffset + buf.byteLength)).channelData;
const paths = proc.getParams();
for (const p of params) { const [k, v] = p.split('='); const hit = paths.find(x => x.toLowerCase().includes(k.toLowerCase().replace(/[^a-z0-9]/g,'_'))); if (!hit) { console.error('no param', k, paths); process.exit(1);} proc.setParamValue(hit, +v); }
const out = proc.render(input, N);
// write 32-bit float via our own encoder to avoid clipping
const y = out[0]; const hdr = Buffer.alloc(44); const data = Buffer.alloc(y.length*4); for (let i=0;i<y.length;i++) data.writeFloatLE(y[i], i*4);
hdr.write('RIFF',0); hdr.writeUInt32LE(36+data.length,4); hdr.write('WAVE',8); hdr.write('fmt ',12); hdr.writeUInt32LE(16,16); hdr.writeUInt16LE(3,20); hdr.writeUInt16LE(1,22); hdr.writeUInt32LE(SR,24); hdr.writeUInt32LE(SR*4,28); hdr.writeUInt16LE(4,32); hdr.writeUInt16LE(32,34); hdr.write('data',36); hdr.writeUInt32LE(data.length,40);
fs.writeFileSync(outWav, Buffer.concat([hdr, data]));
let peak=0, nan=false; for (const v of y){ if (Number.isNaN(v)||!Number.isFinite(v)) nan=true; else peak=Math.max(peak,Math.abs(v)); }
console.log(`${id} ${params.join(' ')||'(defaults)'} peak=${peak.toFixed(2)}${nan?' NAN!':''}`);
