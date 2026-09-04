#!/bin/bash
# build.sh <file.dsp> <outbinary> [-I dir]... [extra .cc files]  -> compiles Faust to C++ (double precision) and links host
set -e
DSP=$1; OUT=$2; shift 2
FAUST=/home/claude/chameleon/ext/grame-cncm_faust/build/bin/faust
LIBS=/home/claude/chameleon/ext/grame-cncm_faustlibraries
ARCH=/home/claude/chameleon/ext/grame-cncm_faust/architecture
INC=""; EXTRA=""
for a in "$@"; do case $a in -I) ;; *.cc|*.cpp) EXTRA="$EXTRA $a";; *) INC="$INC -I $a";; esac; done
DIR=$(dirname $DSP)
$FAUST -lang cpp -double -cn mydsp -I $LIBS -I $DIR $INC -o /tmp/DSP_$$.h $DSP
mkdir -p /tmp/b$$ && cp /tmp/DSP_$$.h /tmp/b$$/DSP.h
g++ -O2 -std=c++17 -D__rt_data= -include cmath -Dalways_inline=inline -include trany.h -I /home/claude/chameleon/ext/brummer10_guitarix/trunk/src/LV2/DSP -I /home/claude/chameleon/ext/brummer10_guitarix/trunk/src/LV2/DSP/circuit_tables -I /home/claude/chameleon/ext/brummer10_guitarix/trunk/src/LV2/DSP/tube_tables -I /home/claude/chameleon/ext/brummer10_guitarix/trunk/src/LV2/gx_oc_2.lv2 -I /tmp/b$$ -I $ARCH -I $DIR $INC -o $OUT /root/chameleon/cmp/host.cpp $EXTRA -lm
rm -rf /tmp/b$$ /tmp/DSP_$$.h
