#!/usr/bin/env python3
"""Render ours-vs-external comparison sets through the native Faust host, level-match, analyze, emit mp3s + JSON."""
import subprocess, os, json, numpy as np, soundfile as sf
from scipy.signal import resample_poly

OUT = '/root/chameleon/cmp/out'; os.makedirs(OUT, exist_ok=True)
CLIPS = {'A': 'Clean lead line (DI)', 'B': 'Strummed chords (DI)', 'C': 'Riff + chops (DI)'}
SECS = {'A': 13, 'B': 8, 'C': 8, 'S': 3}

# name, binary, sample-rate, params, license, notes
SETS = {
  'overdrive': {'title': 'Overdrive', 'ours': 'dynamic-overdrive', 'clips': ['A', 'B', 'C', 'S'], 'variants': [
    ('Ours — Dynamic Overdrive', 'ours/dynamic-overdrive', 48000, {}, 'ours', ''),
    ('Klon Centaur — faustlibraries ve.klonCentaur (WDF)', 'lib_klon', 48000, {'Gain': 0.6, 'Treble': 0.5, 'Level': 0.8}, 'BSD-3 (Chowdhury-DSP)', 'full wave-digital-filter circuit model, in the standard library'),
    ('Tube Screamer TS-9 — guitarix ts9sim', 'gx_ts9', 96000, {'drive': 0.6, 'level': -4, 'tone': 400}, 'GPL-2+', 'Newton-solved diode clipper via C table'),
    ('Boss DS-1 — guitarix DK circuit sim', 'gx_bossds1', 96000, {'drive': 0.5, 'Level': 3, 'Tone': 0.7}, 'GPL-2+', 'full state-space circuit solution'),
    ('ProCo RAT — guitarix aclipper', 'gx_aclipper', 96000, {'drive': 0.5, 'level': -2, 'tone': 0.5}, 'GPL-2+', ''),
    ('KPP Bluedream', 'kpp_bluedream', 48000, {'drive': 63, 'volume': 0.5}, 'GPL-3', 'hand-tuned waveshaper'),
  ]},
  'fuzz': {'title': 'Fuzz', 'ours': 'silicon-fuzz', 'clips': ['A', 'B', 'C', 'S'], 'variants': [
    ('Ours — Silicon Fuzz', 'ours/silicon-fuzz', 48000, {}, 'ours', ''),
    ('Fuzz Face — guitarix DK circuit sim', 'gx_fuzzface', 96000, {'Fuzz': 0.8, 'Level': 0.6}, 'GPL-2+', 'transistor tables + state-space'),
    ('Big Muff Pi — guitarix DK circuit sim', 'gx_bmp', 96000, {'Sustain': 0.6, 'Tone': 0.5, 'Volume': 0.6}, 'GPL-2+', ''),
    ('KPP Fuzz', 'kpp_fuzz', 48000, {'fuzz': 60, 'volume': 0.5}, 'GPL-3', ''),
  ]},
  'boost': {'title': 'Clean boost / treble booster', 'ours': 'clean-boost', 'clips': ['A', 'B', 'C', 'S'], 'variants': [
    ('Ours — JFET Boost', 'ours/clean-boost', 48000, {}, 'ours', ''),
    ('Rangemaster — guitarix DK sim', 'gx_rangem', 96000, {'Boost': 0.6}, 'GPL-2+', 'germanium treble booster circuit'),
    ('Screaming Bird — guitarix DK sim', 'gx_scream', 96000, {'Scream': 0.5}, 'GPL-2+', ''),
  ]},
  'tremolo': {'title': 'Tremolo', 'ours': 'harmonic-tremolo', 'clips': ['A', 'B'], 'variants': [
    ('Ours — Harmonic Tremolo', 'ours/harmonic-tremolo', 48000, {}, 'ours', ''),
    ('Vactrol (opto) tremolo — guitarix', 'gx_tremolo', 48000, {'freq': 4, 'depth': 0.75, 'SINE': 1}, 'GPL-2+', 'CdS photocell RC model'),
  ]},
  'tape-delay': {'title': 'Tape / tube delay', 'ours': 'tape-delay', 'clips': ['A', 'C'], 'variants': [
    ('Ours — Tape Delay', 'ours/tape-delay', 48000, {}, 'ours', ''),
    ('Watkins Copicat — guitarix gxechocat', 'gx_echocat', 96000, {'Head2': 1, 'Sustain': 0.45, 'BPM': 140, 'Output': 1.0, 'AUDIO_IN': 0.5}, 'GPL-2+', 'multi-head tape echo with valve stages'),
    ('Tube delay — guitarix gxtubedelay', 'gx_tubedelay', 96000, {'de.delay': 420, 'feedback': 0.5, 'level': 0.5, 'Drive': 0.5}, 'GPL-2+', '12AX7 stages around a digital delay'),
  ]},
  'spring': {'title': 'Spring reverb', 'ours': 'spring-reverb', 'clips': ['A', 'B'], 'variants': [
    ('Ours — Spring Reverb (dispersive allpass model)', 'ours/spring-reverb', 48000, {}, 'ours', ''),
    ('re.springreverb — faustlibraries', 'lib_spring', 48000, {'Dwell': 0.5, 'Blend': 0.5, 'Tone': 0.5}, 'STK-4.3 (MIT-like)', 'Hadamard FDN "spring-inspired"'),
  ]},
  'chorus': {'title': 'Chorus', 'ours': 'bbd-chorus', 'clips': ['A', 'B'], 'variants': [
    ('Ours — BBD Chorus', 'ours/bbd-chorus', 48000, {}, 'ours', ''),
    ('Chorus — guitarix (Graef)', 'gx_chorus', 48000, {'freq': 1.2, 'level': 0.5}, 'GPL-2+', ''),
  ]},
  'flanger': {'title': 'Flanger', 'ours': 'analog-flanger', 'clips': ['A', 'B'], 'variants': [
    ('Ours — Jet Flanger', 'ours/analog-flanger', 48000, {}, 'ours', ''),
    ('Flanger GX — guitarix', 'gx_flanger', 48000, {'freq': 0.4}, 'GPL-2+', ''),
  ]},
  'phaser': {'title': 'Phaser', 'ours': 'multi-phaser', 'clips': ['A', 'B'], 'variants': [
    ('Ours — Multi-Stage Phaser', 'ours/multi-phaser', 48000, {}, 'ours', ''),
    ('Phaser — guitarix (JOS phaser2)', 'gx_phaser', 48000, {'Speed': 1.5}, 'GPL-2+', ''),
  ]},
  'compressor': {'title': 'Compressor / sustain', 'ours': 'infinite-compressor', 'clips': ['A', 'B'], 'variants': [
    ('Ours — Infinite Sustain Compressor', 'ours/infinite-compressor', 48000, {}, 'ours', ''),
    ('Compressor — guitarix', 'gx_compressor', 48000, {'ratio': 8, 'threshold': -30, 'attack': 0.01, 'release': 0.3, 'knee': 3}, 'GPL-2+', ''),
    ('1176 (ratio 4) — faustlibraries co.limiter_1176_R4', 'lib_1176', 48000, {'Drive': 4, 'Level': 0.6}, 'LGPL-2.1+', ''),
    ('Sustainer pedal circuit — guitarix susta', 'gx_susta', 96000, {'Sustain': 0.6, 'Volume': 0.5}, 'GPL-2+', 'transistor compressor pedal sim'),
  ]},
  'wah': {'title': 'Auto-wah / envelope filter', 'ours': 'auto-wah', 'clips': ['A', 'C'], 'variants': [
    ('Ours — Auto-Wah', 'ours/auto-wah', 48000, {}, 'ours', ''),
    ('Auto-wah — guitarix (crybaby + envelope)', 'gx_autowah', 48000, {'level': 0.5}, 'GPL-2+', ''),
    ('ve.autowah — faustlibraries', 'lib_autowah', 48000, {'Level': 1}, 'STK-4.3', ''),
  ]},
  'octaver': {'title': 'Octaver', 'ours': 'pitch-octaver', 'clips': ['A', 'B'], 'variants': [
    ('Ours — Pitch Octaver (delay-line shifter)', 'ours/pitch-octaver', 48000, {}, 'ours', ''),
    ('Boss OC-2 — guitarix', 'gx_oc2', 48000, {'DIRECT': 0.5, 'OCTAVE_1': 0.8, 'OCTAVE_2': 0.0}, 'GPL-2+', 'analog flip-flop divider style'),
    ('KPP Octaver', 'kpp_octaver', 48000, {'dry': 30, 'octave1': 30}, 'GPL-3', ''),
  ]},
}

def render(binary, sr, clip, params, secs):
    inp = f'/root/chameleon/cmp/in/{clip}_{"96" if sr == 96000 else "48"}.wav'
    outp = f'/tmp/r_{os.getpid()}.wav'
    env = dict(os.environ, SR=str(sr))
    r = subprocess.run([f'/root/chameleon/cmp/bin/{binary}', inp, outp, str(secs)] + [f'{k}={v}' for k, v in params.items()], capture_output=True, text=True, env=env)
    if r.returncode != 0: raise RuntimeError(r.stderr + r.stdout)
    y, fs = sf.read(outp)
    if fs != 48000: y = resample_poly(y, 1, 2)
    return y.astype(np.float32), r.stdout.strip()

def rms_db(y): return 20 * np.log10(np.sqrt(np.mean(y ** 2)) + 1e-12)
def loud_norm(y, target=-20):
    # RMS over the louder 50% of 50 ms frames, so tails/gaps don't skew the match
    n = 2400; fr = [rms_db(y[i:i + n]) for i in range(0, len(y) - n, n)]; fr = np.array(fr); ref = np.mean(fr[fr >= np.median(fr)])
    g = 10 ** ((target - ref) / 20); y = y * g; pk = np.max(np.abs(y))
    if pk > 0.98: y *= 0.98 / pk
    return y, 20 * np.log10(g)

def sine_metrics(y, f0=220, sr=48000):
    seg = y[int(0.8 * sr):int(2.6 * sr)]; w = np.hanning(len(seg)); S = np.abs(np.fft.rfft(seg * w)); fr = np.fft.rfftfreq(len(seg), 1 / sr)
    def bin_energy(f): i = int(round(f * len(seg) / sr)); return np.sum(S[max(0, i - 3):i + 4] ** 2)
    fund = bin_energy(f0); harm = [bin_energy(f0 * k) for k in range(2, 40) if f0 * k < sr / 2]
    even = sum(harm[0::2]); odd = sum(harm[1::2])
    total = np.sum(S[fr > 30] ** 2); nonharm = total - fund - sum(harm)
    thd = np.sqrt(sum(harm) / fund) * 100
    return {'thd_pct': round(float(thd), 1), 'even_odd_db': round(float(10 * np.log10((even + 1e-12) / (odd + 1e-12))), 1), 'alias_db': round(float(10 * np.log10((nonharm + 1e-12) / (fund + sum(harm) + 1e-12))), 1)}

report = {}
for sid, s in SETS.items():
    report[sid] = {'title': s['title'], 'clips': s['clips'], 'variants': []}
    for vi, (name, binary, sr, params, lic, note) in enumerate(s['variants']):
        v = {'name': name, 'binary': binary, 'sr': sr, 'params': params, 'license': lic, 'note': note, 'renders': {}}
        for clip in s['clips']:
            try:
                y, info = render(binary, sr, clip, params, SECS[clip])
                if clip == 'S': v['sine'] = sine_metrics(y); continue
                raw_rms = rms_db(y); yn, gain = loud_norm(y)
                wav = f'{OUT}/{sid}_{vi}_{clip}.wav'; sf.write(wav, yn, 48000, subtype='PCM_16')
                subprocess.run(['ffmpeg', '-y', '-loglevel', 'error', '-i', wav, '-codec:a', 'libmp3lame', '-b:a', '192k', wav.replace('.wav', '.mp3')], check=True)
                v['renders'][clip] = {'file': os.path.basename(wav).replace('.wav', '.mp3'), 'raw_rms_db': round(raw_rms, 1), 'match_gain_db': round(gain, 1), 'raw': info}
            except Exception as e:
                v['renders'][clip] = {'error': str(e)[:300]}
                print('ERR', sid, name, clip, str(e)[:200])
        report[sid]['variants'].append(v); print(sid, name, v.get('sine', ''), {k: r.get('match_gain_db') for k, r in v['renders'].items()})
# dry references
for clip in CLIPS:
    y, _ = sf.read(f'/root/chameleon/cmp/in/{clip}_48.wav'); yn, g = loud_norm(y.astype(np.float32)); wav = f'{OUT}/dry_{clip}.wav'; sf.write(wav, yn, 48000, subtype='PCM_16')
    subprocess.run(['ffmpeg', '-y', '-loglevel', 'error', '-i', wav, '-codec:a', 'libmp3lame', '-b:a', '192k', wav.replace('.wav', '.mp3')], check=True)
json.dump({'clips': CLIPS, 'sets': report}, open(f'{OUT}/report.json', 'w'), indent=1, default=lambda o: float(o))
print('done')
