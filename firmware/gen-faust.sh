#!/usr/bin/env bash
# Generate C++ for the effects the firmware uses: ./gen-faust.sh dynamic-overdrive tape-delay ...
# Needs the native Faust compiler (brew install faust) — class name = CamelCase of the id.
set -e
cd "$(dirname "$0")"
for id in "$@"; do
  cls=$(echo "$id" | sed -E 's/(^|-)([a-z0-9])/\U\2/g')
  flags=$(grep -o 'chameleon_flags "[^"]*"' "../dsp/$id.dsp" | sed 's/.*"\(.*\)"/\1/')
  prec=$( [[ "$flags" == *-double* ]] && echo -double || echo -single )
  faust -lang cpp $prec -cn "$cls" -scn chdsp -i -I ../dsp -I ../dsp/lib "../dsp/$id.dsp" -o "faust/$id.h"
  echo "faust/$id.h  ($cls, $prec)"
done
