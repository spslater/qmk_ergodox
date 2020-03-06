#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"



// Layers
#define SPS_DEFAULT 0
#define SPS_AUDACITY 1
#define SPS_GIMP 2
#define SPS_FUNC 13
#define SPS_NUMPAD 14
#define SPS_NAV 15


// Key Codes
#define _____ KC_NO

#define KC_MAC_UNDO  LGUI(KC_Z)
#define KC_MAC_CUT   LGUI(KC_X)
#define KC_MAC_COPY  LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO   LCTL(KC_Z)
#define KC_PC_CUT    LCTL(KC_X)
#define KC_PC_COPY   LCTL(KC_C)
#define KC_PC_PASTE  LCTL(KC_V)
#define ES_LESS_MAC  KC_GRAVE
#define ES_GRTR_MAC  LSFT(KC_GRAVE)
#define ES_BSLS_MAC  ALGR(KC_6)
#define NO_PIPE_ALT  KC_GRAVE
#define NO_BSLS_ALT  KC_EQUAL

#define KC_CUT       LGUI(KC_X)
#define KC_COPY      LGUI(KC_C)
#define KC_PASTE     LGUI(KC_V)
#define KC_UNDO      LGUI(KC_Z)
#define KC_SLCT_ALL  LGUI(KC_A)
#define KC_REDO      LSFT(LGUI(KC_Z))
#define KC_SFT_CAP   LSFT_T(KC_CAPS)
#define KC_WIN_LEFT  LCTL(KC_LEFT)
#define KC_WIN_RIGHT LCTL(KC_RIGHT)
#define KC_MAC_LOCK  LGUI(LSFT(KC_L))

#define KC_SAVE      LGUI(KC_S)


// Colors
#define HSV_BLACK 0, 0, 0
#define ________ HSV_BLACK



enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_172_255_255,
  HSV_86_255_128,
  HSV_27_255_255,
  EPRM,
};


// https://docs.qmk.fm/#/keycodes
// https://docs.qmk.fm/#/feature_advanced_keycodes

/* Template (Copy this one for each new layer)

  ,--------------------------------------------------.     ,--------------------------------------------------.
  |        |      |      |      |      |      |      |     |      |      |      |      |      |      |        |
  |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
  |        |      |      |      |      |      |      |     |      |      |      |      |      |      |        |
  |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
  |        |      |      |      |      |      |------|     |------|      |      |      |      |      |        |
  |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
  |        |      |      |      |      |      |      |     |      |      |      |      |      |      |        |
  `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
    |      |      |      |      |      | ,-------------. ,-------------. |      |      |      |      |      |
    `----------------------------------' |      |      | |      |      | `----------------------------------'
                                  ,------|------|------| |------+------+------.
                                  |      |      |      | |      |      |      |
                                  |      |      |------| |------|      |      |
                                  |      |      |      | |      |      |      |
                                  `--------------------' `--------------------'

  [X] = LAYOUT_ergodox_pretty(
    _____,  _____,  _____,  _____,  _____,  _____,  _____,                   _____,  _____,  _____,  _____,  _____,  _____,  _____,
    _____,  _____,  _____,  _____,  _____,  _____,  _____,                   _____,  _____,  _____,  _____,  _____,  _____,  _____,
    _____,  _____,  _____,  _____,  _____,  _____,                                   _____,  _____,  _____,  _____,  _____,  _____,
    _____,  _____,  _____,  _____,  _____,  _____,  _____,                   _____,  _____,  _____,  _____,  _____,  _____,  _____,
    _____,  _____,  _____,  _____,  _____,                                                   _____,  _____,  _____,  _____,  _____,
                                                    _____,  _____,   _____,  _____,
                                                            _____,   _____,
                                            _____,  _____,  _____,   _____,  _____,  _____
  ),
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* [0] Keyboard // DEFAULT
    
    ,--------------------------------------------------.     ,--------------------------------------------------.
    | Caps   |  1   |  2   |  3   |  4   |  5   |TO 15 |     | TO 1 |  6   |  7   |  8   |  9   |  0   |        |
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
    | MO 14  |  Q   |  W   |  E   |  R   |  T   |DELETE|     |DELETE|  Y   |  U   |  I   |  O   |  P   | MO 14  |
    |--------+------+------+------+------+------|  ←   |     |  ←   |------+------+------+------+------+--------|
    | Tab  ↹ |  A   |  S   |  D   |  F   |  G   |------|     |------|  H   |  J   |  K   |  L   |  ;   | ' "    |
    |--------+------+------+------+------+------|BCKSPC|     |BCKSPC|------+------+------+------+------+--------|
    | Shift  |  Z   |  X   |  C   |  V   |  B   |  ⌫   |     |  ⌫   |  N   |  M   |  ,<  |  .>  |  /?  | Shift  |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |MO 15 |MO 13 | CTRL | CMD  | ALT  | ,-------------. ,-------------. |  - _ |  =   | [ {  | ] }  |MO 15 |
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |SPACE |ENTER |      | |      |ENTER |SPACE |
                                    |  ␣   |  ↵   |------| |------|  ↵   |  ␣   |
                                    |      |      | ESC  | | ESC  |      |      |
                                    `--------------------' `--------------------'
  */
  [SPS_DEFAULT] = LAYOUT_ergodox_pretty(
    KC_CAPS,         KC_1,          KC_2,      KC_3,     KC_4,     KC_5,       TO(SPS_NAV),                     TO(SPS_AUDACITY),  KC_6,  KC_7,      KC_8,      KC_9,          KC_0,         _____,
    MO(SPS_NUMPAD),  KC_Q,          KC_W,      KC_E,     KC_R,     KC_T,       KC_DEL,                          KC_DEL,            KC_Y,  KC_U,      KC_I,      KC_O,          KC_P,         MO(SPS_NUMPAD),
    KC_TAB,          KC_A,          KC_S,      KC_D,     KC_F,     KC_G,                                                           KC_H,  KC_J,      KC_K,      KC_L,          KC_SCOLON,    KC_QUOTE,
    KC_LSFT,         KC_Z,          KC_X,      KC_C,     KC_V,     KC_B,       KC_BSPACE,                       KC_BSPACE,         KC_N,  KC_M,      KC_COMMA,  KC_DOT,        KC_SLASH,     KC_LSFT,
    MO(SPS_NAV),     MO(SPS_FUNC),  KC_LCTRL,  KC_LGUI,  KC_LALT,                                                                         KC_MINUS,  KC_EQUAL,  KC_LBRACKET,   KC_RBRACKET,  MO(SPS_NAV),
                                                                               _____,        _____,    _____,   _____,
                                                                                             _____,    _____,
                                                                   KC_SPACE,   KC_ENTER,     KC_ESC,   KC_ESC,  KC_ENTER,          KC_SPACE
  ),
 
  /* [1] Audacity // AUDACITY
  
    ,--------------------------------------------------.     ,--------------------------------------------------. CSK: Cursor to Select
    |        |      |      |      |      |      | TO 3 |     | TO 5 |      |      |      |      |      |        | SLNC: Silence
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------| S DEL: Split Delete
    |  ESC   | CSK  |ZOOM +|SPLIT |      | REDO |      |     |      |      |  LC  |  M↑  |  RC  |      |        | SEL TL: Select Tool
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------| TME TL: Time Shift Tool
    |  DEL   | SLNC |ZOOM -|CUR ← |CUR → | UNDO |------|     |------|      |  M←  |  M↓  |  M→  |      |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    |  S DEL |      |CLICK |SEL TL|TIMETL|      |      |     |      |      |      |      |      |      |        |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |MO 15 |MO 13 |      |      |      | ,-------------. ,-------------. |      |      |      |      |      |
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      |      | |      |      |      |
                                    | PLAY |ENTER |------| |------|      |      |
                                    |      |      | SAVE | |      |      |      |
                                    `--------------------' `--------------------'

    Notes: Move cursor > and cursor < to f and d location. move time and sel tool to v and c maybe.

  */
  [SPS_AUDACITY] = LAYOUT_ergodox_pretty(
    _____,             _____,             _____,       _____,       _____,   _____,      TO(SPS_DEFAULT),                     TO(SPS_GIMP),  _____,  _____,       _____,       _____,        _____,  _____,
    KC_ESC,            LCTL(LSFT(KC_K)),  LGUI(KC_1),  LGUI(KC_I),  _____,   KC_REDO,    _____,                               _____,         _____,  KC_MS_BTN1,  KC_MS_UP,    KC_MS_BTN2,   _____,  _____,
    KC_DELETE,         LGUI(KC_L),        LGUI(KC_3),  KC_COMMA,    KC_DOT,  KC_UNDO,                                                        _____,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  _____,  _____,
    LALT(LGUI(KC_K)),  _____,             KC_MS_BTN1,  KC_F1,       KC_F5,   _____,      _____,                               _____,         _____,  _____,       _____,       _____,        _____,  _____,
    MO(SPS_NAV),       MO(SPS_FUNC),      _____,       _____,       _____,                                                                           _____,       _____,       _____,        _____,  _____,
                                                                                         _____,            _____,     _____,  _____,
                                                                                                           _____,     _____,
                                                                             KC_SPACE,   KC_ENTER,         KC_SAVE,   _____,  _____,         _____
  ),

  /* [2] Gimp // GIMP

    ,--------------------------------------------------.     ,--------------------------------------------------.
    |        |      |      |      |      |      | TO 1 |     |TO 13 |      |      |  /   | *    |  -   |        |
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
    | ESC    | FLIP | SCLE | CPKR | CSLT |      |      |     |      |      |  7   |  8   |  9   |  +   |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    |SLT ALL | ROTA | MOVE | BUKT | RECT | FREE |------|     |------|      |  4   |  5   |  6   |  .   |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    | SHIFT  |      | SWAP | TEXT | FUZY |INVRT |      |     |      |      |  1   |  2   |  3   |BKSPC |        |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |MO 15 |      |      | UNDO | REDO | ,-------------. ,-------------. |      |      |      |      |MO 15 |
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      |      | |      |      |      |
                                    | CMD  | DEL  |------| |------|   ↵  |  0   |
                                    |      |      | SAVE | | TAB  |      |      |
                                    `--------------------' `--------------------'
  */
  [SPS_GIMP] = LAYOUT_ergodox_pretty(
    _____,       _____,       _____,       _____,       _____,       _____,         TO(SPS_AUDACITY),                      TO(SPS_FUNC),  _____,  _____,  KC_SLASH,  KC_ASTERISK,  KC_MINUS,   _____,
    KC_ESC,      LSFT(KC_L),  LSFT(KC_S),  KC_O,        LSFT(KC_O),  _____,         _____,                                 _____,         _____,  KC_7,   KC_8,      KC_9,         KC_PLUS,    _____,
    LGUI(KC_A),  LSFT(KC_R),  KC_M,        LSFT(KC_B),  KC_R,        KC_F,                                                                _____,  KC_4,   KC_5,      KC_6,         KC_DOT,     _____,
    KC_LSFT,     _____,       KC_X,        KC_T,        KC_U,        LGUI(KC_I),    _____,                                 _____,         _____,  KC_1,   KC_2,      KC_3,         KC_BSPACE,  _____,
    MO(SPS_NAV), _____,       _____,       LGUI(KC_Z),  LGUI(KC_Y),                                                                               _____,  _____,     _____,        _____,      MO(SPS_NAV),
                                                                                    _____,             _____,     _____,   _____,
                                                                                                       _____,     _____,
                                                                     KC_LGUI,       KC_DEL,            KC_SAVE,   KC_TAB,  KC_ENTER,      KC_0
  ),

  /* [13] Functional // FUNC

    ,--------------------------------------------------.     ,--------------------------------------------------.
    |        |      |      |      |      |      | TO 2 |     |TO 14 |      |      |      |      |      |        | A BAK: Audio Back
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------| A FOR: Audio Forward
    |        |      |      |      |      |      |      |     |      |  F1  |  F2  |  F3  |  F4  |      |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    |        |      |VOL ↓ | MUTE |VOL ↑ |      |------|     |------|  F5  |  F6  |  F7  |  F8  |      |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    |        |      |A BAK | PLAY |A FOR |      |      |     |      |  F9  |  F10 |  F11 |  F12 |      |        |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |      |`MO 13|      |      |      | ,-------------. ,-------------. |      |      |      |      |      |
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      |      | |      |      |      |
                                    |      |      |------| |------|      |      |
                                    |      |      |      | |      |      |      |
                                    `--------------------' `--------------------'
  */
  [SPS_FUNC] = LAYOUT_ergodox_pretty(
    _____,  _____,         _____,    _____,    _____,    _____,  TO(SPS_GIMP),                   TO(SPS_NUMPAD),  _____,  _____,   _____,   _____,   _____,   _____,
    _____,  _____,         _____,    _____,    _____,    _____,  _____,                          _____,           _____,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _____,
    _____,  _____,         KC_VOLD,  KC_MUTE,  KC_VOLU,  _____,                                                   _____,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _____,
    _____,  _____,         KC_MPRV,  KC_MPLY,  KC_MNXT,  _____,  _____,                          _____,           _____,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _____,
    _____,  MO(SPS_FUNC),  _____,    _____,    _____,                                                                     _____,   _____,   _____,   _____,   _____,
                                                                 _____,         _____,   _____,  _____,
                                                                                _____,   _____,
                                                         _____,  _____,         _____,   _____,  _____,           _____
  ),
 
  /* [14] Special / Number Pad // NUMPAD
    
    ,--------------------------------------------------.     ,--------------------------------------------------.
    |        |      |      |      |      |      |TO 13 |     |TO 15 |      |      |  /   | *    |  -   |        |
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
    | `MO 14 |  :   |  (   |  *   |  &   |      |DELETE|     |DELETE|      |  7   |  8   |  9   |  +   | `MO 14 |
    |--------+------+------+------+------+------|  ←   |     |  ←   |------+------+------+------+------+--------|
    | Tab  ↹ |  ~   |  ^   |  %   |  $   |  `   |------|     |------|      |  4   |  5   |  6   |  .   |        |
    |--------+------+------+------+------+------|BCKSPC|     |BCKSPC|------+------+------+------+------+--------|
    |        |  \   |  #   |  @   |  !   |  |   |  ⌫   |     |  ⌫   |      |  1   |  2   |  3   |  ↵   |        |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |      |      |      |      |      | ,-------------. ,-------------. |      |      |      |      |      |
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      |      | |      |      |      |
                                    |SPACE |ENTER |------| |------|BKSPC |  0   |
                                    |      |      |      | |      |      |      |
                                    `--------------------' `--------------------'
  */
  [SPS_NUMPAD] = LAYOUT_ergodox_pretty(
    _____,           _____,      _____,    _____,        _____,         _____,      TO(SPS_FUNC),                    TO(SPS_NAV),  _____,  _____,  KC_KP_SLASH,  KC_KP_ASTERISK,  KC_KP_MINUS,  _____,
    MO(SPS_NUMPAD),  KC_COLON,   KC_LPRN,  KC_ASTERISK,  KC_AMPERSAND,  _____,      KC_DEL,                          KC_DEL,       _____,  KC_7,   KC_8,         KC_9,            KC_KP_PLUS,   MO(SPS_NUMPAD),
    KC_TAB,          KC_TILDE,   KC_CIRC,  KC_PERCENT,   KC_DOLLAR,     KC_GRAVE,                                                  _____,  KC_4,   KC_5,         KC_6,            KC_KP_DOT,    _____,
    _____,           KC_BSLASH,  KC_HASH,  KC_AT,        KC_EXCLAIM,    KC_PIPE,    KC_BSPACE,                       KC_BSPACE,    _____,  KC_1,   KC_2,         KC_3,            KC_KP_ENTER,  _____,
    _____,           _____,      _____,    _____,        _____,                                                                            _____,  _____,        _____,           _____,        _____,
                                                                                    _____,         _____,    _____,  _____,
                                                                                                   _____,    _____,
                                                                        KC_SPACE,   KC_ENTER,      KC_ESC,   _____,  KC_SPACE,     KC_0
  ),
 
  /* [15] Navigation // NAV
    
    ,--------------------------------------------------.     ,--------------------------------------------------.  WU: Wheel Up
    |        |      |      |      |      |      |TO 14 |     | TO 0 |      |      |      |      |      | LOCK   |  WD: Wheel Down
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|  LC: Left Click
    |        |      |  LC  |  M↑  |  RC  | MC   |DELETE|     |DELETE| HOME |PG DWN|PG UP | END  |      |        |  RC: Right Click
    |--------+------+------+------+------+------|  ←   |     |  ←   |------+------+------+------+------+--------|  MC: Middle Click
    |        | ALL  |  M←  |  M↓  |  M→  | WU   |------|     |------|  ←   |  ↓   |  ↑   |  →   | ALT  |        |
    |--------+------+------+------+------+------|BCKSPC|     |BCKSPC|------+------+------+------+------+--------| 
    | SHIFT  | UNDO | CUT  | COPY |PASTE | WD   |  ⌫   |     |  ⌫   |      |      |      |      |      |        |  
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |`MO 15|      |      |      |      | ,-------------. ,-------------. |      |      |CTRL ←|CTRL →|`MO 15|
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      |      | |      |      |      |
                                    | CTRL |      |------| |------|      | CMD  |
                                    |      |      | ESC  | | ESC  |      |      |
                                    `--------------------' `--------------------'
  */
  [SPS_NAV] = LAYOUT_ergodox_pretty(
    _____,        _____,        _____,       _____,       _____,        _____,          TO(SPS_NUMPAD),                     TO(SPS_DEFAULT),  _____,    _____,      _____,    _____,        _____,         KC_MAC_LOCK,
    _____,        _____,        KC_MS_BTN1,  KC_MS_UP,    KC_MS_BTN2,   KC_MS_BTN3,     KC_DEL,                             KC_DEL,           KC_HOME,  KC_PGDOWN,  KC_PGUP,  KC_END,       _____,         _____,
    _____,        KC_SLCT_ALL,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  KC_MS_WH_UP,                                                          KC_LEFT,  KC_DOWN,    KC_UP,    KC_RIGHT,     KC_LALT,       _____,
    KC_LSFT,      KC_UNDO,      KC_CUT,      KC_COPY,     KC_PASTE,     KC_MS_WH_DOWN,  KC_BSPACE,                          KC_BSPACE,        _____,    _____,      _____,    _____,        _____,         _____,
    MO(SPS_NAV),  _____,        _____,       _____,       _____,                                                                                        _____,      _____,    KC_WIN_LEFT,  KC_WIN_RIGHT,  MO(SPS_NAV),
                                                                                        _____,           _____,    _____,   _____,
                                                                                                         _____,    _____,
                                                                        KC_LCTRL,       _____,           KC_ESC,   KC_ESC,  _____,  KC_LGUI
  ),
};


// https://docs.qmk.fm/#/feature_rgb_matrix

bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(172,255,255);
        #endif
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(86,255,128);
        #endif
      }
      return false;
    case HSV_27_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(27,255,255);
        #endif
      }
      return false;
  }
  return true;
}

/* Layer Colors
  AZURE      	132,	102,	255
  BLUE       	170,	255,	255
  CHARTREUSE 	64, 	255,	255
  CORAL      	11, 	176,	255
  CYAN       	128,	255,	255
  GOLD       	36, 	255,	255
  GOLDENROD  	30, 	218,	218
  GREEN      	85, 	255,	255
  MAGENTA    	213,	255,	255
  ORANGE     	28, 	255,	255
  PINK       	234,	128,	255
  PURPLE     	191,	255,	255
  RED        	0,  	255,	255
  SPRINGGREEN	106,	255,	255
  TEAL       	128,	255,	128
  TURQUOISE  	123,	90, 	112
  WHITE      	0,  	0,  	255
  YELLOW     	43, 	255,	255
*/
extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

/* Color Template
  [X] = {
    {________}, {________}, {________}, {________}, {________},   {________}, {________}, {________}, {________}, {________},
    {________}, {________}, {________}, {________}, {________},   {________}, {________}, {________}, {________}, {________},
    {________}, {________}, {________}, {________}, {________},   {________}, {________}, {________}, {________}, {________},
    {________}, {________}, {________}, {________}, {________},   {________}, {________}, {________}, {________}, {________},
    {________}, {________}, {________}, {________},                           {________}, {________}, {________}, {________}, 
  },
*/
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [SPS_DEFAULT] = {
    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE},   {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE},
    {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},     {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},
    {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},     {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_GREEN},
    {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},     {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_BLUE},   {HSV_GREEN},
    {HSV_CYAN},   {HSV_GREEN},  {HSV_GREEN},  {HSV_GREEN},                                {HSV_GREEN},  {HSV_GREEN},  {HSV_GREEN},  {HSV_GREEN},
  }, 

  [SPS_AUDACITY] = { 
    {________}, {________}, {________}, {________}, {________},   {________}, {________}, {________}, {________}, {________}, 
    {HSV_RED},  {HSV_RED},  {HSV_RED},  {HSV_RED},  {HSV_RED},    {________}, {HSV_PINK}, {HSV_TEAL}, {HSV_PINK}, {________}, 
    {HSV_RED},  {HSV_RED},  {HSV_RED},  {HSV_RED},  {HSV_RED},    {________}, {HSV_TEAL}, {HSV_TEAL}, {HSV_TEAL}, {________}, 
    {HSV_RED},  {HSV_RED},  {________}, {HSV_RED},  {________},   {________}, {________}, {________}, {________}, {________}, 
    {________}, {________}, {________}, {________},                           {________}, {________}, {________}, {________},
  },
  
  [SPS_GIMP] = {
    {________},  {________},  {________},  {________},  {________},    {________}, {________},   {HSV_GREEN},    {HSV_GREEN},    {HSV_GREEN},
    {________},  {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {________},    {________}, {HSV_ORANGE}, {HSV_ORANGE},   {HSV_ORANGE},   {HSV_GREEN},
    {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN},   {________}, {HSV_ORANGE}, {HSV_ORANGE},   {HSV_ORANGE},   {HSV_GREEN},
    {________},  {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN},   {________}, {HSV_ORANGE}, {HSV_ORANGE},   {HSV_ORANGE},   {HSV_GREEN},
    {________},  {________},  {HSV_GREEN}, {HSV_GREEN},                            {________},   {________},     {________},     {________},
  },
  
  [SPS_FUNC] = {
    {________}, {________},      {________},      {________},      {________},   {________}, {________},   {________},   {________},   {________},
    {________}, {________},      {________},      {________},      {________},   {________}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE},
    {________}, {HSV_GOLDENROD}, {HSV_GOLDENROD}, {HSV_GOLDENROD}, {________},   {________}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE},
    {________}, {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_TURQUOISE}, {________},   {________}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE},
    {________}, {________},      {________},      {________},                                {________},   {________},   {________},   {________},
  },

  [SPS_NUMPAD] = {
    {________},  {________},  {________},  {________},  {________},    {________}, {________},   {HSV_GREEN},  {HSV_GREEN},  {HSV_GREEN},
    {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {________},    {________}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_GREEN},
    {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN},   {________}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_GREEN},
    {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN},   {________}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_GREEN},
    {________},  {________},  {________},  {________},                             {________},   {________},   {________},   {________},
  },

  [SPS_NAV] = {
    {________}, {________}, {________}, {________}, {________},   {________},   {________},   {________},   {________},   {________},
    {________}, {HSV_PINK}, {HSV_TEAL}, {HSV_PINK}, {HSV_PINK},   {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {________},
    {HSV_RED},  {HSV_TEAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_PINK},   {HSV_TEAL},   {HSV_TEAL},   {HSV_TEAL},   {HSV_TEAL},   {HSV_YELLOW},
    {HSV_RED},  {HSV_RED},  {HSV_RED},  {HSV_RED},  {HSV_PINK},   {________},   {________},   {________},   {________},   {________},
    {________}, {________}, {________}, {________},                             {________},   {________},   {HSV_RED},    {HSV_RED}, 
  },
};


/*
* ,----------------------------------.  ,----------------------------------.
* |  28  |  27  |  26  |  25  |  24  |  |   0  |   1  |   2  |   3  |   4  |
* |------+------+------+------+------|  |------+------+------+------+------|
* |  33  |  32  |  31  |  30  |  29  |  |   5  |   6  |   7  |   8  |   9  |
* |------+------+------+------+------|  |------+------+------+------+------|
* |  38  |  37  |  36  |  35  |  34  |  |  10  |  11  |  12  |  13  |  14  |
* |------+------+------+------+------|  |------+------+------+------+------|
* |  43  |  42  |  41  |  40  |  39  |  |  15  |  16  |  17  |  18  |  19  |
* |------+------+------+------+------'  `------+------+------+------+------'
* |  47  |  46  |  45  |  44  |                |  20  |  21  |  22  |  23  |
* `---------------------------'                `---------------------------'
*/
void skc(int layer, int idx, int key) { // set_key_color
  HSV hsv = {
    .h = pgm_read_byte(&ledmap[layer][idx][0]),
    .s = pgm_read_byte(&ledmap[layer][idx][1]),
    .v = pgm_read_byte(&ledmap[layer][idx][2]),
  };
  if (!hsv.h && !hsv.s && !hsv.v) {
      rgb_matrix_set_color( key, 0, 0, 0 );
  } else {
      RGB rgb = hsv_to_rgb( hsv );
      float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
      rgb_matrix_set_color( key, f * rgb.r, f * rgb.g, f * rgb.b );
  }
}

void set_layer_color(int l) { // l : layer
    skc(l, 0,28);skc(l, 1,27);skc(l, 2,26);skc(l, 3,25);skc(l, 4,24);  skc(l, 5, 0);skc(l, 6, 1);skc(l, 7, 2);skc(l, 8, 3);skc(l, 9, 4);
    skc(l,10,33);skc(l,11,32);skc(l,12,31);skc(l,13,30);skc(l,14,29);  skc(l,15, 5);skc(l,16, 6);skc(l,17, 7);skc(l,18, 8);skc(l,19, 9);
    skc(l,20,38);skc(l,21,37);skc(l,22,36);skc(l,23,35);skc(l,24,34);  skc(l,25,10);skc(l,26,11);skc(l,27,12);skc(l,28,13);skc(l,29,14);
    skc(l,30,43);skc(l,31,42);skc(l,32,41);skc(l,33,40);skc(l,34,39);  skc(l,35,15);skc(l,36,16);skc(l,37,17);skc(l,38,18);skc(l,39,19);
    skc(l,40,47);skc(l,41,46);skc(l,42,45);skc(l,43,44);                            skc(l,44,20);skc(l,45,21);skc(l,46,22);skc(l,47,23);
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case SPS_DEFAULT:
      set_layer_color(SPS_DEFAULT);
      break;
   case SPS_AUDACITY:
      set_layer_color(SPS_AUDACITY);
      break;
   case SPS_GIMP:
      set_layer_color(SPS_GIMP);
      break;
   case SPS_FUNC:
      set_layer_color(SPS_FUNC);
      break;
   case SPS_NUMPAD:
      set_layer_color(SPS_NUMPAD);
      break;
   case SPS_NAV:
      set_layer_color(SPS_NAV);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

/* Layer LED Indicators
 *  0: 000
 *  1: 001
 *  2: 010
 *  3: 011
 *  4: 100
 *  5: 101
 *  6: 110
 *  7: 111
 *  8: 000
 *  9: 001
 * 10: 010
 * 11: 011
 * 12: 100
 * 13: 101
 * 14: 110
 * 15: 111
 */
void sps_led_000(void) { ergodox_right_led_1_off(); ergodox_right_led_2_off(); ergodox_right_led_3_off(); }
void sps_led_001(void) { ergodox_right_led_1_off(); ergodox_right_led_2_off(); ergodox_right_led_3_on();  }
void sps_led_010(void) { ergodox_right_led_1_off(); ergodox_right_led_2_on();  ergodox_right_led_3_off(); }
void sps_led_011(void) { ergodox_right_led_1_off(); ergodox_right_led_2_on();  ergodox_right_led_3_on();  }
void sps_led_100(void) { ergodox_right_led_1_on();  ergodox_right_led_2_off(); ergodox_right_led_3_off(); }
void sps_led_101(void) { ergodox_right_led_1_on();  ergodox_right_led_2_off(); ergodox_right_led_3_on();  }
void sps_led_110(void) { ergodox_right_led_1_on();  ergodox_right_led_2_on();  ergodox_right_led_3_off(); }
void sps_led_111(void) { ergodox_right_led_1_on();  ergodox_right_led_2_on();  ergodox_right_led_3_on();  }


uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    switch (biton32(state)) {
      case 0: 
        sps_led_000();
        break;
      case 1:
        sps_led_001();
        break;
      case 2:
        sps_led_010();
        break;
      case 3:
        sps_led_011();
        break;
      case 4:
        sps_led_100();
        break;
      case 5:
        sps_led_101();
        break;
      case 6:
        sps_led_110();
        break;
      case 7:
        sps_led_111();
        break;
      case 8: 
        sps_led_000();
        break;
      case  9: 
        sps_led_001();
        break;
      case 10: 
        sps_led_010();
        break;
      case 11: 
        sps_led_011();
        break;
      case 12: 
        sps_led_100();
        break;
      case 13: 
        sps_led_101();
        break;
      case 14: 
        sps_led_110();
        break;
      case 15: 
        sps_led_111();
        break;
      default:
        break;
    }
    return state;

};

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
  rgb_matrix_enable();
}
