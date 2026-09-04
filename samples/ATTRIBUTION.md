# Sample attribution

All processed files in this folder are 48 kHz, mono, 16-bit WAV, peak-normalised
to -1 dBFS. Untouched source files are kept in `original/` (prefixed with the id
they were used for). Processing was done with librosa/soundfile on 2026-09-04.

Only CC0 and CC-BY material is included. Every license statement below was read
directly from the source repository's README at the time of download. The
Freesound pages themselves and wiki.laptop.org were NOT reachable from the
sourcing environment, so the *original* Freesound/OLPC titles could not be
re-verified; where a title is unknown the sample's name in the source repo is
given instead.

## Sources

### Sonic Pi bundled samples (CC0)
- Repo: https://github.com/sonic-pi-net/sonic-pi (directory `etc/samples/`)
- License statement (from `etc/samples/README.md`): "All other samples in this
  directory are from http://freesound.org and have also been placed in the
  public domain via the Creative Commons 0 License:
  http://creativecommons.org/publicdomain/zero/1.0/ ... Many of the samples have
  been slightly modified and trimmed for use with Sonic Pi."
- Each sample below lists the Freesound author and URL exactly as given in that README.

### OLPC Berklee Sound Library, via Tone.js audio repo (CC BY 3.0)
- Repo: https://github.com/Tonejs/audio (directory `berklee/`)
- License statement (from `berklee/README.md`): "Files from the OLPC Berklee
  Sound Library — http://wiki.laptop.org/go/Sound_samples — Licensed under CC BY 3.0"
- Author / attribution party: Berklee College of Music (OLPC "Sound samples" project).
- Files in that repo are 44.1 kHz MP3 transcodes of the original OLPC WAV/OGG files.

## Files

| id | file | duration | license | author | original title / sample name | source URL |
|---|---|---|---|---|---|---|
| (removed — had audible ambience) guitar-clean | `guitar-clean.wav` | 9.97 s | CC0 1.0 | Sub-d (Freesound) | Sonic Pi `guit_em9` (electric guitar Em9 chord, clean) | https://raw.githubusercontent.com/sonic-pi-net/sonic-pi/dev/etc/samples/guit_em9.flac — original: http://www.freesound.org/people/Sub-d/sounds/46992/ |
| guitar-heavy | `guitar-heavy.wav` | 9.76 s | CC BY 3.0 | Berklee College of Music (OLPC Berklee Sound Library) | `guitar_riff_cutup4` (distorted rhythm-guitar riff, amped) | https://raw.githubusercontent.com/Tonejs/audio/master/berklee/guitar_riff_cutup4.mp3 — library page: http://wiki.laptop.org/go/Sound_samples |
| drums-analog | `drums-analog.wav` | 8.00 s (loops) | CC0 1.0 | Garzul (Freesound) | Sonic Pi `loop_garzul` (120 BPM four-on-the-floor electronic drum loop) | https://raw.githubusercontent.com/sonic-pi-net/sonic-pi/dev/etc/samples/loop_garzul.flac — original: http://freesound.org/people/Garzul/sounds/213524/ |
| drums-lofi | `drums-lofi.wav` | 10.91 s (4 bars @ 88 BPM, loops) | CC0 1.0 (derived work; see note) | see note | Programmed boom-bap groove from Sonic Pi one-shots | see note |
| (removed — had audible ambience) guitar-lead | `guitar-lead.wav` | 4.33 s | CC0 1.0 | Suva (Freesound) | Sonic Pi `guit_e_slide` (single electric-guitar slide lick with tail) | https://raw.githubusercontent.com/sonic-pi-net/sonic-pi/dev/etc/samples/guit_e_slide.flac — original: http://freesound.org/people/Suva/sounds/2410/ |
| drums-break (extra) | `drums-break.wav` | 6.86 s (loops) | CC0 1.0 | gowers (Freesound) | Sonic Pi `loop_amen_full` (Amen break, ~137 BPM) | https://raw.githubusercontent.com/sonic-pi-net/sonic-pi/dev/etc/samples/loop_amen_full.flac — original: http://freesound.org/people/gowers/sounds/202537/ |

### Note on `drums-lofi.wav`
No ready-made CC0/CC-BY lo-fi drum-machine loop was reachable, so this groove was
**programmed** (4 bars, 88 BPM, swung 8th-note hats, backbeat snare, syncopated
kick) from the following CC0 one-shots, then given lo-fi treatment (band-limited
to ~9 kHz, 12-bit quantisation, soft saturation, low-level vinyl hiss bed):

| Sonic Pi sample | role | author (Freesound) | original URL |
|---|---|---|---|
| `bd_808` | kick | EKVelika | http://freesound.org/people/EKVelika/sounds/208447/ |
| `sn_dolf` | snare | Dolfeus | http://freesound.org/people/Dolfeus/sounds/57534/ |
| `hat_zild` | closed hat | pjcohen | https://freesound.org/people/pjcohen/sounds/45668/ |
| `drum_cymbal_open` | open hat | menegass | http://www.freesound.org/people/menegass/sounds/100055/ |
| `drum_cymbal_pedal` | pedal hat | menegass | http://www.freesound.org/people/menegass/sounds/100054/ |
| `vinyl_hiss` | noise bed | veezay | http://freesound.org/people/veezay/sounds/130393/ |

All from https://github.com/sonic-pi-net/sonic-pi/tree/dev/etc/samples (CC0 per README).
The arrangement itself is original work created for this project and is released CC0.

## Processing applied
- All: decode, mix to mono, resample to 48 kHz, peak-normalise to -1 dBFS, write 16-bit PCM WAV.
- No trimming was needed (all sources were 4–10 s). `guitar_riff_cutup5` (20 s) from the same
  Berklee set was considered and would have needed trimming; `cutup4` was used instead.
- `drums-lofi`: synthesised as described above.

## Alternatives that were looked at but not used
- Berklee `guitar_chord1..4` (CC BY 3.0): single clean chord hits, ~4 s each.
- Berklee `guitar_riff_cutup1..3`, `cutup5` (CC BY 3.0): more rhythm-guitar riffs (4 s, 3.7 s, 3 s, 20 s).
- Berklee `techno_sequence1..3` (CC BY 3.0): synth sequences, not drums.
- Sonic Pi `loop_mika` (CC0, mika55, freesound 188551): 8 s 120 BPM electronic loop with a bass line.
- Sonic Pi `arovane_beat_a..e` (CC0, donated by Uwe Zahn/Arovane): 7–15 s IDM beats, 129 BPM.
- Sonic Pi `guit_e_fifths` (CC0, Sub-d, freesound 46990): 6 s clean power-chord hit.
- Boochi44/free-drum-samples (claims CC0): hip-hop one-shot kits, but several filenames
  (`cy0000`, `oh00`, `ht00`) match the circulated Roland TR-808 sample set, so provenance was
  judged too uncertain to ship commercially.


---

# Dry DI guitar samples (added Sep 2026)

Files: `di-lead.wav` (= A_clean_lead_line_karoryfer), `di-chords.wav` (= B_strummed_chords_nam), `di-riff.wav` (= C_riff_chops_nam), `di-full-take.wav` (= nam_guitar_di_full). The earlier clean-guitar clips were CC0 but recorded with audible reverb/room, which made delays and reverbs impossible to judge; these are true direct-input recordings.

# samples-di — attribution

Dry (direct-input, no amp / cab / reverb / delay) electric-guitar audio used as
demo/test material. All deliverables are 48 kHz, mono, 24-bit PCM WAV,
peak-normalized to -3 dBFS. Unmodified originals (plus the license files that
were fetched with them) are in `original/`.

Every license below was read from the source repository at the commit noted;
nothing here is assumed.

---

## 1. `B_strummed_chords_nam.wav`, `C_riff_chops_nam.wav`, `nam_guitar_di_full.wav`

| | |
|---|---|
| Source file | `REAPER/Guitar DI.wav` |
| Repository | https://github.com/sdatkinson/NeuralAmpModelerPlugin |
| Raw URL | https://raw.githubusercontent.com/sdatkinson/NeuralAmpModelerPlugin/main/REAPER/Guitar%20DI.wav |
| Commit verified | `16be869746b8915885c7a35bafdcc0061faeb50e` (main, 2026-08-10) |
| Author / copyright | Steven Atkinson (repository owner; the file is the DI test clip referenced by the plugin's REAPER development project `NeuralAmpModeler/NeuralAmpModeler.RPP`) |
| License | MIT (repository `LICENSE`, copied to `original/nam_plugin_LICENSE.txt`) |
| Original format | 48 kHz, mono, 24-bit PCM, 16.0 s, peak -8.6 dBFS, not an LFS pointer |

License text as fetched from the repository:

> MIT License
>
> Copyright (c) 2022 Steven Atkinson
>
> Permission is hereby granted, free of charge, to any person obtaining a copy
> of this software and associated documentation files (the "Software"), to deal
> in the Software without restriction, including without limitation the rights
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
> copies of the Software, and to permit persons to whom the Software is
> furnished to do so, subject to the following conditions:
>
> The above copyright notice and this permission notice shall be included in all
> copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
> SOFTWARE.

Note: the LICENSE is a repository-wide MIT grant; the audio file has no
separate license statement. The MIT notice above must ship with the clips.

Content of the 16 s original (from spectrogram / onset analysis):
0.0–2.0 s single sustained low note; 2.0–3.9 s a very quiet chord (~-60 dBFS);
3.9–7.0 s three ringing strummed chords; 7.0–8.0 s slide; 8.0–14.2 s strummed
chord riff; 14.2–16.0 s staccato/muted chops.

**Trimming / processing (all three files):** cut at the offsets below, 10 ms
fade-in / 30 ms fade-out at the cut points, peak-normalized to -3 dBFS.
No EQ, no resampling (already 48 kHz), no dynamics.

| Deliverable | Offset in original | Length |
|---|---|---|
| `B_strummed_chords_nam.wav` | 3.90 s – 9.75 s | 5.85 s |
| `C_riff_chops_nam.wav` | 9.75 s – 16.00 s | 6.25 s |
| `nam_guitar_di_full.wav` | 0.00 s – 16.00 s (whole file) | 16.0 s |

Dryness check (20 ms RMS frames on the original): frames more than 40 dB
below peak have median RMS -55.8 dBFS; 5th-percentile frame level -57 dBFS;
note decays are monotonic with no tail/echo visible on the spectrogram.
Within the trimmed B/C regions the playing is dense so gaps are few; C ends
with staccato chops whose inter-hit gaps drop to about -45 dBFS RMS
(instrument/string noise, no reverb tail).

---

## 2. `A_clean_lead_line_karoryfer.wav`  (constructed from single-note DI samples)

No permissively licensed *performed* single-note lead line could be found on
GitHub (see "Rejected" below), so this clip was **assembled** from single-note
DI samples: a monophonic 12 s A-minor line with rests, built by placing
individual note samples at chosen onsets, truncating each note at its written
length with a 40 ms release fade, and peak-normalizing the result to -3 dBFS.
Gaps between phrases are digital silence (the source samples were individually
onset-trimmed). It is a sequenced phrase, not a human performance.

| | |
|---|---|
| Source files | `Samples/green/ord/twang_{a4,b4,c5,d4,d5,e4,e5,g4,g5,a5}_mf_rr1.wav` (only a4, c5, d5, e5, g5, g4 are used in the clip; all fetched files are kept in `original/karoryfer_black-and-green_green_ord/`) |
| Repository | https://github.com/sfzinstruments/karoryfer.black-and-green-guitars |
| Raw URL pattern | https://raw.githubusercontent.com/sfzinstruments/karoryfer.black-and-green-guitars/main/Samples/green/ord/twang_a4_mf_rr1.wav |
| Commit verified | `b3b3249d37dc977a1a297bd2dc053e6d9b6b805c` (main, 2022-08-08) |
| Instrument | "green" = Gretsch Anniversary electric guitar, articulation "twang" (ordinary pick), dynamic mf, round-robin 1 |
| Author / copyright | Karoryfer Lecolds (D. Smolken); samples "recorded and photographed by Brian Wood" per `readme.txt` |
| License | CC0 1.0 Universal (repository `LICENSE`, copied to `original/karoryfer_black-and-green_green_ord/LICENSE`) |
| Original format | 44.1 kHz, mono, 24-bit PCM, 4.4–5.9 s per note, not LFS pointers (`.gitattributes` only sets text/eol) |

From the repository `readme.txt` (copied to `original/.../readme.txt`):

> Black And Green Guitars is a free sample library for Plogue Sforzando version 1.971 or newer. It contains samples of a green Gretsch Anniversary and a black Hofner Club, recorded and photographed by Brian Wood.
> [...]
> Royalty-free for all commercial and non-commercial use. Copyright 2022 Karoryfer Lecolds.

From the repository `LICENSE` (CC0 1.0 Universal, opening lines):

> Creative Commons Legal Code
>
> CC0 1.0 Universal
> [...]
> Statement of Purpose
> [...]
> 2. Waiver. To the greatest extent permitted by, but not in contravention of, applicable law, Affirmer hereby overtly, fully, permanently, irrevocably and unconditionally waives, abandons, and surrenders all of Affirmer's Copyright and Related Rights and associated claims and causes of action, whether now known or unknown (including existing as well as future claims and causes of action), in the Work [...]

CC0 requires no attribution; it is given here anyway.

Processing: 44.1 kHz -> 48 kHz (polyphase resampling), leading silence trimmed
to 3 ms before onset, each note peak-equalized to -6 dBFS before sequencing,
40 ms release fade at note ends, mix peak-normalized to -3 dBFS.

Note sequence (note, onset, sounding length): a4 0.00 s 0.60 s; c5 0.60 0.60;
d5 1.20 0.55; e5 1.80 1.60; g5 3.60 0.50; e5 4.10 0.55; d5 4.70 1.50;
c5 6.40 0.55; a4 6.95 1.60; g4 8.70 0.45; a4 9.20 2.30.

Dryness check (source samples, 20 ms frames): quiet frames have median RMS
-56 to -70 dBFS, 88–100 % of quiet frames are below -50 dBFS; decays are
clean exponential with no tail on the spectrogram — genuinely dry DI.

---

## Rejected candidates (not shipped) and why

| Candidate | Result |
|---|---|
| `GuitarML/PedalNetRT` `data/ts9_test1_in_FP32.wav` | Repo is GPL-3.0 only. Worse: the file lineage is `teddykoker/pedalnet` `data/in.wav`, whose README says it is "Concatenation of a few samples from the IDMT-SMT-Guitar dataset" (non-commercial). Rejected. |
| `GuitarML/Automated-GuitarAmpModelling` & `Alec-Wright/Automated-GuitarAmpModelling` `Data/*/ht1-input.wav`, `muff-input.wav` | Real, very dry DI (gap RMS -60 to -83 dBFS) but only license in either repo is GPL-3.0; no separate data license. Rejected per brief. |
| `GuitarML/Proteus`, `GuitarML/NeuralPi`, `GuitarML/GuitarLSTM`, `GuitarML/SmartGuitarPedal` | GPL-3.0; contain only IRs, no DI. |
| `sdatkinson/neural-amp-modeler` | MIT, but only a 1 s loudness-calibration tone and a 0 s test stub; the standardized `input.wav` lives on Google Drive (blocked) with no stated license. |
| `sdatkinson/NeuralAmpModelerCore` `example_audio/input.wav` | MIT, but only 2.0 s and half of it is digital silence; too short to be useful. |
| `jatinchowdhury18/AnalogTapeModel` `Testing/Canada_Dry.wav` | Dry guitar-like clip, but repo is GPL-3.0. |
| `jatinchowdhury18/KlonCentaur` `GainStageTraining/DataIn/*.wav` | BSD-3, but the wavs are 0.5 s SPICE-generated test tones, not guitar. |
| `rerdavies/ToobAmp` `Assets/Guitar-E2.flac` etc. | MIT, but single sustained test notes at -15 to -19 dBFS with a -50 dBFS floor; inferior to the Karoryfer set. |
| `Alec-Wright/CoreAudioML` `result_test/.../*-input.wav` | 100 % sub-250 Hz energy, no onsets: a synthetic test signal. |
| `micbuffa/WebAudio-Guitar-Amplifier-Simulator` `assets/audio/*DI*.mp3` | Repo LICENSE is MIT and several clips are dry DI, but the audio has no provenance/credit at all and most are covers of copyrighted songs (Black Sabbath, Nirvana, Green Day, Muse); two are well-known forum DI tracks by other people. Ownership by the repo author cannot be established. Rejected. |
| `sonic-pi-net/sonic-pi` `etc/samples/guit_*.flac` | CC0 (per samples README) but each is a single chord hit / slide / harmonics of 3–10 s; `guit_e_fifths` and `guit_em9` are stereo with dense highs and long sustain, likely amped/compressed. Not usable as A/B/C. |
| `Tonejs/audio` `audio/berklee/guitar_*.mp3` | CC BY 3.0 (OLPC Berklee library) but mic'd/noisy: quiet frames ~-36 dBFS, 0–3 % below -50 dBFS. Not dry DI. `audio/loop/` is CC BY-NC-SA. |
| `mdn/webaudio-examples` `multi-track/leadguitar.mp3` | Repo CC0, but the clip has an obvious amp/room character (quiet frames -47 dBFS, only 26 % < -50) and no provenance. |
| `tidalcycles/Dirt-Samples` `gtr/*.wav` | No license file in the repo. |
| `ss12f32v/Guitar-Transcription` (EGDB demo `*_DI.wav`) | Genuine DI clips but no license anywhere in repo or page. |
| `mir-dataset-loaders/mirdata` GuitarSet / EGFxSet test resources | Silent or 1 s stub files. |
| `egfxset/egfxset.github.io` `Audios/*/1-0.wav` | CC BY 4.0 dataset, but the site only hosts effected (BD-2, RAT, chorus, delay, reverb…) demo notes, no clean one. |
| `hegelespaul/Electric-Guitar-Dataset`, `mcomunita/tonetwist-afx-dataset`, `nlpodyssey/waveny`, `coxyDev/ML_Amp_Study`, `guitar-techs/guitar-techs.github.io` | No audio in the repos; data lives on Zenodo / Google Drive (blocked). Guitar-TECHS (CC BY 4.0, Zenodo 14963133) and EGFxSet Clean (CC BY 4.0, Zenodo 7044411) would be the best sources if Zenodo access is ever available. |
| `sgossner/VCSL` (CC0) | No electric guitar in the library. |
| `andywiggins/tab-cnn`, `cwitkowitz/*`, `marl/GuitarSet`, `MTG/essentia`, `spotify/basic-pitch`, `CPJKU/madmom`, `aubio/aubio`, `marl/crepe`, `mikeoliphant/*`, `AidaDSP/*`, `Chowdhury-DSP/BYOD`, `pelennor2170/NAM_models`, `webprofusion/soundshed-guitar` | No guitar DI audio in tree (IRs / stubs only). |
