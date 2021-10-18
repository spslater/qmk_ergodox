# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LTO_ENABLE = yes
COMMAND_ENABLE = no

WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
SRC = matrix.c

RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes

UNICODE_ENABLE = no
UNICODEMAP_ENABLE = yes

EXTRAFLAGS += -flto