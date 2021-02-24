#!/usr/bin/env sh

QMK="$HOME/Documents/qmk_firmware"
CUR=$(pwd)

cd "$QMK" && \
qmk compile -kb ergodox_ez -km sean && \

cd "$CUR" && \
mv "$QMK/ergodox_ez_sean.hex" "$CUR/ergodox_ez_sean.hex" && \

/Applications/wally-cli "./ergodox_ez_sean.hex"
