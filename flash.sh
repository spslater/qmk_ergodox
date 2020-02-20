#!/usr/bin/env bash

QMK="$HOME/Documents/qmk_firmware"
CUR=$(pwd)

cd "$QMK" && \
make ergodox_ez:sean && \

cd "$CUR" && \
mv "$QMK/ergodox_ez_sean.hex" "$CUR/ergodox_ez_sean.hex" && \

/Applications/wally-cli "./ergodox_ez_sean.hex"
