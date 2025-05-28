#!/usr/bin/env sh

QMK="$HOME/Documents/qmk_firmware"
CUR=$(pwd)

cp config.h keymap.c rules.mk "$QMK/keyboards/ergodox_ez/keymaps/spslater"

cd $QMK && \
qmk compile && \
qmk flash && \

cp "$QMK/ergodox_ez_glow_spslater.hex" $CUR
cd $CUR

