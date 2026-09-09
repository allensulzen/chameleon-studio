# Chameleon Pedal firmware — Daisy Seed (libDaisy core build)
#   make            -> build/chameleon.bin
#   make program-dfu -> flash over USB (Seed in DFU mode: hold BOOT, tap RESET)
TARGET = chameleon
CPP_SOURCES = main.cpp
LIBDAISY_DIR ?= ../../fw/libDaisy
DAISYSP_DIR  ?= ../../fw/DaisySP
C_INCLUDES += -I. -Ifaust
OPT = -O3
CPPFLAGS += -fno-exceptions -fno-rtti -Wno-unused-variable -Wno-unused-but-set-variable
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile
