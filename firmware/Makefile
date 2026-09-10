# Chameleon Pedal firmware — Daisy Seed (libDaisy core build)
#   make                       -> build/chameleon.bin for the Daisy bootloader (runs from 8 MB QSPI)
#   make APP_TYPE=BOOT_NONE    -> small internal-flash image (128 KB limit, no bootloader needed)
#   make program-boot          -> one-time: install the Daisy bootloader (Seed in STM32 DFU: hold BOOT, tap RESET)
#   make program-dfu           -> flash the app (Seed in the Daisy bootloader: tap RESET, press BOOT while the LED breathes)
TARGET = chameleon
APP_TYPE ?= BOOT_QSPI
CPP_SOURCES = main.cpp
LIBDAISY_DIR ?= ../../fw/libDaisy
DAISYSP_DIR  ?= ../../fw/DaisySP
C_INCLUDES += -I. -Ifaust
OPT = -O3
CPPFLAGS += -fno-exceptions -fno-rtti -Wno-unused-variable -Wno-unused-but-set-variable
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile
