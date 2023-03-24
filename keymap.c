#include QMK_KEYBOARD_H
#include "version.h"
#include "process_unicode.h"

// Layers
enum layers {
  L_DEF,
  L_NUM,
  // L_EMOJI,
  L_NAV,
  L_FUNC,
  L_MVE,
  L_AUD,
  L_GIMP,
  L_G_OW,
  LAYER_MAX
};

// Key Codes
#define _____ KC_NO
#define KC_SAVE      LGUI(KC_S)
#define KC_CUT       LGUI(KC_X)
#define KC_COPY      LGUI(KC_C)
#define KC_PASTE     LGUI(KC_V)
#define KC_UNDO      LGUI(KC_Z)
#define KC_SLCT_ALL  LGUI(KC_A)
#define KC_REDO      LSFT(LGUI(KC_Z))
#define KC_WIN_LEFT  LCTL(KC_LEFT)
#define KC_WIN_RIGHT LCTL(KC_RIGHT)
#define KC_MAC_LOCK  LGUI(LSFT(KC_L))

// Hammerspoon
#define KC_HS_Q LCTL(LSFT(LALT(LGUI(RCTL(RSFT(RALT(RGUI(KC_Q))))))))
#define KC_HS_W LCTL(LSFT(LALT(LGUI(RCTL(RSFT(RALT(RGUI(KC_W))))))))
#define KC_HS_E LCTL(LSFT(LALT(LGUI(RCTL(RSFT(RALT(RGUI(KC_E))))))))
#define KC_HS_R LCTL(LSFT(LALT(LGUI(RCTL(RSFT(RALT(RGUI(KC_R))))))))
#define KC_HS_T LCTL(LSFT(LALT(LGUI(RCTL(RSFT(RALT(RGUI(KC_T))))))))
#define KC_HS_G LCTL(LSFT(LALT(LGUI(RCTL(RSFT(RALT(RGUI(KC_G))))))))
#define KC_HS_B LCTL(LSFT(LALT(LGUI(RCTL(RSFT(RALT(RGUI(KC_B))))))))

// Rectangle
#define KC_RT_7 LSFT(LCTL(LALT(KC_7)))
#define KC_RT_8 LSFT(LCTL(LALT(KC_8)))
#define KC_RT_9 LSFT(LCTL(LALT(KC_9)))

#define KC_RT_Y LSFT(LCTL(LALT(KC_Y)))
#define KC_RT_U LSFT(LCTL(LALT(KC_U)))
#define KC_RT_I LSFT(LCTL(LALT(KC_I)))
#define KC_RT_O LSFT(LCTL(LALT(KC_O)))
#define KC_RT_P LSFT(LCTL(LALT(KC_P)))

#define KC_RT_H LSFT(LCTL(LALT(KC_H)))
#define KC_RT_J LSFT(LCTL(LALT(KC_J)))
#define KC_RT_K LSFT(LCTL(LALT(KC_K)))
#define KC_RT_L LSFT(LCTL(LALT(KC_L)))
#define KC_RT_SCN LSFT(LCTL(LALT(KC_SEMICOLON)))

#define KC_RT_N LSFT(LCTL(LALT(KC_N)))
#define KC_RT_M LSFT(LCTL(LALT(KC_M)))
#define KC_RT_COM LSFT(LCTL(LALT(KC_COMMA)))
#define KC_RT_DOT LSFT(LCTL(LALT(KC_DOT)))
#define KC_RT_SLH LSFT(LCTL(LALT(KC_SLASH)))

#define KC_RT_MIN LSFT(LCTL(LALT(KC_MINUS)))
#define KC_RT_EQL LSFT(LCTL(LALT(KC_EQUAL)))
#define KC_RT_BRC LSFT(LCTL(LALT(KC_LEFT_BRACKET)))

#define KC_RT_SPACE LSFT(LCTL(LALT(KC_SPACE)))


// // unicode map
// enum unicode_name {
//   HPPY, // 😊 Smiling Face with Smiling Eyes - U+1F60A
//   KISS, // 😘 Face Blowing a Kiss - U+1F618
//   SAD, // 😟 Worried Face - U+1F61F
//   CRY, // 😢 Crying Face - U+1F622
//   TONG, // 😛 Face with Tongue - U+1F61B
//   HAHA, // 😆 Grinning Squinting Face - U+1F606
//   LOL, // 😂 Face with Tears of Joy - U+1F602
//   ROFL, // 🤣 Rolling on the Floor Laughing - U+1F923
//   TADA, // 🎉 Party Popper - U+1F389
//   PRTY, // 🥳 Partying Face - U+1F973
//   CLAP, // 👏 Clapping Hands - U+1F44F
//   RAISE, // 🙌 Raising Hands - U+1F64C
//   RHRT, // ❤️ Red Heart - U+2764
//   PHRT, // 💜 Purple Heart - U+1F49C
//   RNBW, // 🌈 Rainbow - U+1F308
//   PEACE, // ✌️ Victory Hand - U+270C
//   TUP, // 👍 Thumbs Up - U+1F44D
//   UARW, // ⬆️ Up Arrow - U+2B06
//   TDOWN, // 👎 Thumbs Down - U+1F44E
//   DARW, // ⬇️ Down Arrow - U+2B07
//   CAKE, // 🎂 Birthday Cake - U+1F382
// };

// const uint32_t PROGMEM unicode_map[] = {
//   [TUP]   = 0x1F44D,
//   [TDOWN] = 0x1F44E,
//   [PEACE] = 0x270C,
//   [ROFL]  = 0x1F923,
//   [LOL]   = 0x1F602,
//   [HAHA]  = 0x1F606,
//   [RHRT]  = 0x2764,
//   [PHRT]  = 0x1F49C,
//   [HPPY]  = 0x1F60A,
//   [CLAP]  = 0x1F44F,
//   [RAISE] = 0x1F64C,
//   [CRY]   = 0x1F622,
//   [PRTY]  = 0x1F973,
//   [KISS]  = 0x1F618,
//   [TONG]  = 0x1F61B,
//   [SAD]   = 0x1F61F,
//   [RNBW]  = 0x1F308,
//   [UARW]  = 0x2B06,
//   [DARW]  = 0x2B07,
//   [CAKE]  = 0x1F382,
//   [TADA]  = 0x1F389,
// };

enum custom_keycodes {
  L_PREV = SAFE_RANGE,
  L_NEXT,
  L_MAIN,
  L_MOVE,

  M_GLHF, // glhf
  M_GG, // gg, Good Game!
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
    _____, _____, _____, _____, _____, _____, _____,  _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____, _____, _____,  _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____, _____,                _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____, _____, _____,  _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____,                              _____, _____, _____, _____, _____,
                                       _____, _____,  _____, _____,
                                              _____,  _____,
                                _____, _____, _____,  _____, _____, _____
  ),
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* [L_DEF] Keyboard // DEFAULT
    ,--------------------------------------------------.     ,--------------------------------------------------.  DEF: TO Default (layer 0)
    | Caps   |  1   |  2   |  3   |  4   |  5   | PREV |     | NEXT |  6   |  7   |  8   |  9   |  0   |        |
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
    | MO NUM |  Q   |  W   |  E   |  R   |  T   |ENTER |     |DELETE|  Y   |  U   |  I   |  O   |  P   | TO 3   |
    |--------+------+------+------+------+------|  ↵   |     |  ←   |------+------+------+------+------+--------|
    | Tab  ↹ |  A   |  S   |  D   |  F   |  G   |------|     |------|  H   |  J   |  K   |  L   |  ;   | ' "    |
    |--------+------+------+------+------+------|SPACE |     |BCKSPC|------+------+------+------+------+--------|
    | Shift  |  Z   |  X   |  C   |  V   |  B   |  ␣   |     |  ⌫   |  N   |  M   |  ,<  |  .>  |  /?  | MO NUM |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |MO NAV|MO 13 | CTRL | CMD  | ALT  | ,-------------. ,-------------. |  - _ | = +  | [ {  | ] }  |MO NAV|
      `----------------------------------' |  ↑   |  ↓   | |  ←   |  →   | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |BCKSPC|DELETE| DEF  | |      |ENTER |SPACE |
                                    |  ⌫   |  ←   |------| |------|  ↵   |  ␣   |
                                    |      |      | ESC  | | ESC  |      |      |
                                    `--------------------' `--------------------'
  */
  [L_DEF] = LAYOUT_ergodox_pretty(
    KC_CAPS,   KC_1,       KC_2,     KC_3,    KC_4,      KC_5,   L_PREV,    /**/ L_NEXT,    KC_6,     KC_7,     KC_8,     KC_9,    KC_0,     _____,
    MO(L_NUM), KC_Q,       KC_W,     KC_E,    KC_R,      KC_T,   KC_ENTER,  /**/ KC_DEL,    KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,     _____,
    KC_TAB,    KC_A,       KC_S,     KC_D,    KC_F,      KC_G,              /**/            KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOTE,
    KC_LSFT,   KC_Z,       KC_X,     KC_C,    KC_V,      KC_B,   KC_SPACE,  /**/ KC_BSPC  , KC_N,     KC_M,     KC_COMMA, KC_DOT,  KC_SLASH, MO(L_NUM),
    MO(L_NAV), MO(L_FUNC), KC_LCTL,  KC_LGUI, KC_LALT,                      /**/            KC_MINUS, KC_EQUAL, KC_LBRC , KC_RBRC, MO(L_NAV),
                                                         KC_UP,  KC_DOWN,   /**/ KC_LEFT,   KC_RIGHT,
                                                                 L_MAIN,    /**/ _____,
                                              KC_BSPC  , KC_DEL, KC_ESC,    /**/ KC_ESC,   KC_ENTER, KC_SPACE
  ),
  /* [L_NUM] Special / Number Pad // NUMPAD
    ,--------------------------------------------------.     ,--------------------------------------------------.  DEF: TO Default (layer 0)
    |        |      |      |      |      |      | PREV |     | NEXT |      |      |  /   | *    |  -   |        |
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
    |  `MO   |  :   |  &   |  *   |  (   |  )   |ENTER |     |DELETE|      |  7   |  8   |  9   |  +   |        |
    |--------+------+------+------+------+------|  ↵   |     |  ←   |------+------+------+------+------+--------|
    | Tab  ↹ |  ~   |  $   |  %   |  ^   |  `   |------|     |------|Tab  ↹|  4   |  5   |  6   |  .   |        |
    |--------+------+------+------+------+------|SPACE |     |BCKSPC|------+------+------+------+------+--------|
    |        |  \   |  !   |  @   |  #   |  |   |  ␣   |     |  ⌫   |      |  1   |  2   |  3   |  ↵   |  `MO   |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |      |      |      |      |      | ,-------------. ,-------------. |  -   |      |      |      |      |
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      | DEF  | |      |      |      |
                                    |BCKSPC|DELETE|------| |------|SPACE |  0   |
                                    |      |      |ESCAPE| |ESCAPE|      |      |
                                    `--------------------' `--------------------'
  */
  [L_NUM] = LAYOUT_ergodox_pretty(
    _____,     _____,    _____,        _____,       _____,     _____,    L_PREV,   /**/ L_NEXT,    _____,    _____,       KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, _____,
    MO(L_NUM), KC_COLON, KC_AMPERSAND, KC_ASTERISK, KC_LPRN,   KC_RPRN,  KC_ENTER, /**/ KC_DEL,    _____,    KC_7,        KC_8,        KC_9,           KC_KP_PLUS,  _____,
    KC_TAB,    KC_TILDE, KC_DOLLAR,    KC_PERCENT,  KC_CIRC,   KC_GRAVE,           /**/            KC_TAB,   KC_4,        KC_5,        KC_6,           KC_KP_DOT,   _____,
    _____,     KC_BSLS,  KC_EXCLAIM,   KC_AT,       KC_HASH,   KC_PIPE,  KC_SPACE, /**/ KC_BSPC  , _____,    KC_1,        KC_2,        KC_3,           KC_KP_ENTER, MO(L_NUM),
    _____,     _____,    _____,        _____,       _____,                         /**/                      KC_KP_MINUS, _____,       _____,          _____,       _____,
                                                                _____,    _____,   /**/ _____,     _____,
                                                                          L_MAIN,  /**/ _____,
                                                     KC_BSPC  , KC_DEL,   KC_ESC,  /**/ KC_ESC,    KC_SPACE, KC_0
  ),

  /* [L_NAV] Navigation // NAV
    ,--------------------------------------------------.     ,--------------------------------------------------.  DEF: TO Default (layer 0)
    |        |      |      |      |      |      | PREV |     | NEXT |      |      |      |      |      | LOCK   |  WU: Wheel Up
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|  WD: Wheel Down
    |        | HS_Q | HS_W | HS_E | HS_R | HS_T |      |     |      | HOME |PG DWN|PG UP | END  |      |        |  LC: Left Click
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|  RC: Right Click
    |        | ALL  |  LC  |  MC  |  RC  | HS_G |------|     |------|  ←   |  ↓   |  ↑   |  →   | ALT  |        |  MC: Middle Click
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    | SHIFT  | UNDO | CUT  | COPY |PASTE | HS_B |      |     |      |      |  - _ |  = + |      |      |        |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |`MO NA|      |      |      |      | ,-------------. ,-------------. |      |      |CTRL ←|CTRL →|`MO NA|
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      | DEF  | |      |      |      |
                                    | CTRL |      |------| |------|      | CMD  |
                                    |      |      | ESC  | | ESC  |      |      |
                                    `--------------------' `--------------------'
  */
  [L_NAV] = LAYOUT_ergodox_pretty(
    _____,       _____,       _____,      _____,      _____,      _____,   L_PREV, /**/ L_NEXT, _____,   _____,    _____,    _____,       _____,        KC_MAC_LOCK,
    _____,       KC_HS_Q,     KC_HS_W,    KC_HS_E,    KC_HS_R,    KC_HS_T, _____,  /**/ _____,  KC_HOME, KC_PGDN,  KC_PGUP,  KC_END,      _____,        _____,
    _____,       KC_SLCT_ALL, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, KC_HS_G,         /**/         KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT,    KC_LALT,      _____,
    KC_LSFT,     KC_UNDO,     KC_CUT,     KC_COPY,    KC_PASTE,   KC_HS_B, _____,  /**/ _____,  _____,   KC_MINUS, KC_EQUAL, _____,       _____,        _____,
    MO(L_NAV),   _____,       _____,      _____,      _____,                       /**/         _____,             _____,    KC_WIN_LEFT, KC_WIN_RIGHT, MO(L_NAV),
                                                                  _____,   _____,  /**/ _____,  _____,
                                                                           L_MAIN, /**/ _____,
                                                      KC_LCTL,    _____,   KC_ESC, /**/ KC_ESC, _____,   KC_LGUI
  ),
  /* [L_FUNC] Functional // FUNC
    ,--------------------------------------------------.     ,--------------------------------------------------.  DEF: TO Default (layer 0)
    |        |      |      |      |      |      | PREV |     | NEXT |      |      |      |      |      |        |  A BAK: Audio Back
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|  A FOR: Audio Forward
    |        |      |      |      |      |      |      |     |      |  F1  |  F2  |  F3  |  F4  |      |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    |        |      |VOL ↓ | MUTE |VOL ↑ |      |------|     |------|  F5  |  F6  |  F7  |  F8  |      |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    |        |      |A BAK | PLAY |A FOR |      |      |     |      |  F9  |  F10 |  F11 |  F12 |      |        |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |      | `MO  |      |      |      | ,-------------. ,-------------. |      |      |      |      |      |
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      | DEF  | |      |      |      |
                                    |      |      |------| |------|      |      |
                                    |      |      |      | |      |      |      |
                                    `--------------------' `--------------------'
  */
  [L_FUNC] = LAYOUT_ergodox_pretty(
    _____, _____,      _____,   _____,   _____,   _____,   L_PREV, /**/ L_NEXT, _____, _____, _____,  _____,  _____,  _____,
    _____, _____,      _____,   _____,   _____,   _____,   _____,  /**/ _____,  _____, KC_F1, KC_F2,  KC_F3,  KC_F4,  _____,
    _____, _____,      KC_VOLD, KC_MUTE, KC_VOLU, KC_HS_G,         /**/         _____, KC_F5, KC_F6,  KC_F7,  KC_F8,  _____,
    _____, _____,      KC_MPRV, KC_MPLY, KC_MNXT, _____,   _____,  /**/ _____,  _____, KC_F9, KC_F10, KC_F11, KC_F12, _____,
    _____, MO(L_FUNC), _____,   _____,   _____,                    /**/                _____, _____,  _____,  _____,  _____,
                                                  _____,   _____,  /**/ _____,  _____,
                                                           L_MAIN, /**/ _____,
                                         _____,   _____,   _____,  /**/ _____,  _____, _____
  ),
  /* [L_MVE] Movement // MVE
    ,--------------------------------------------------.     ,--------------------------------------------------.  DEF: TO Default (layer 0)
    |        |      |      |      |      |      | PREV |     | NEXT |      |      |      |      |      |        |  A BAK: Audio Back
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|  A FOR: Audio Forward
    |        |      |      |      |      |      |      |     |      |      |      |      |      |      |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    |        |      |      |      |      |      |------|     |------|      |      |      |      |      |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    |        |      |      |      |      |      |      |     |      |      |      |      |      |      |        |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |      |      |      |      |      | ,-------------. ,-------------. |      |      |      |      |      |
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      | DEF  | |      |      |      |
                                    |      |      |------| |------|      |      |
                                    |      |      |      | |      |      |      |
                                    `--------------------' `--------------------'
  */
  [L_MVE] = LAYOUT_ergodox_pretty(
    _____, _____, _____, _____, _____, _____, L_PREV, /**/ L_NEXT,_____,   KC_RT_7,   KC_RT_8,   KC_RT_9,   _____, _____,
    _____, _____, _____, _____, _____, _____, _____,  /**/ _____, KC_RT_Y, KC_RT_U,   KC_RT_I,   KC_RT_O,   _____, _____,
    _____, _____, _____, _____, _____, _____,         /**/        KC_RT_H, KC_RT_J,   KC_RT_K,   KC_RT_L,   _____, _____,
    _____, _____, _____, _____, _____, _____, _____,  /**/ _____, KC_RT_N, KC_RT_M,   KC_RT_COM, KC_RT_DOT, _____, _____,
    _____, _____, _____, _____, _____,                /**/                 KC_RT_MIN, KC_RT_EQL, KC_RT_BRC, _____, _____,
                                       _____, _____,  /**/ _____, _____,
                                              L_MAIN, /**/ _____,
                                _____, _____, _____,  /**/ _____, _____,   KC_RT_SPACE
  ),
  /* [L_AUD] Audacity // AUDACITY
    ,--------------------------------------------------.     ,--------------------------------------------------.  DEF: TO Default (layer 0)
    |        |      |      |      |      |      | PREV |     | NEXT |      |      |      |      |      |        |  CSK: Cursor to Select
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|  SLNC: Silence
    |  ESC   | CSK  |ZOOM +|SPLIT |      | REDO |      |     |      |      |  LC  |  M↑  |  RC  |      |        |  S DEL: Split Delete
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|  SEL TL: Select Tool
    |  DEL   | SLNC |ZOOM -|CUR ← |CUR → | UNDO |------|     |------|      |  M←  |  M↓  |  M→  |      |        |  TME TL: Time Shift Tool
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    |  S DEL |      |CLICK |SEL TL|TIMETL|      |      |     |      |      |      |      |      |      |        |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |MO NAV|MO FUN|      |      |      | ,-------------. ,-------------. |      |      |      |      |      |
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      | DEF  | |      |      |      |
                                    | PLAY | SAVE |------| |------|      |      |
                                    |      |      |ENTER | |      |      |      |
                                    `--------------------' `--------------------'

    Notes: Move cursor > and cursor < to f and d location. move time and sel tool to v and c maybe.
  */
  [L_AUD] = LAYOUT_ergodox_pretty(
    _____,            _____,            _____,      _____,      _____,    _____,   L_PREV,   /**/ L_NEXT, _____, _____,      _____,      _____,       _____, _____,
    KC_ESC,           LCTL(LSFT(KC_K)), LGUI(KC_1), LGUI(KC_I), _____,    KC_REDO, _____,    /**/ _____,  _____, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  _____, _____,
    KC_DELETE,        LGUI(KC_L),       LGUI(KC_3), KC_COMMA,   KC_DOT,   KC_UNDO,           /**/         _____, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _____, _____,
    LALT(LGUI(KC_K)), _____,            KC_MS_BTN1, KC_F1,      KC_F5,    _____,   _____,    /**/ _____,  _____, _____,      _____,      _____,       _____, _____,
    MO(L_NAV),        MO(L_FUNC),       _____,      _____,      _____,                       /**/                _____,      _____,      _____,       _____, _____,
                                                                          _____,   _____,    /**/ _____,  _____,
                                                                                   L_MAIN,   /**/ _____,
                                                                KC_SPACE, KC_SAVE, KC_ENTER, /**/ _____,  _____, _____
  ),
  /* [L_GIMP] Gimp // GIMP
    ,--------------------------------------------------.     ,--------------------------------------------------.  DEF: TO Default (layer 0)
    |        |      |      |      |      |      | PREV |     | NEXT |      |      |  /   | *    |  -   |        |
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
    | ESC    | FLIP | SCLE | CPKR | CSLT |      |      |     |      |      |  7   |  8   |  9   |  +   |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    |SLT ALL | ROTA | MOVE | BUKT | RECT | FREE |------|     |------|      |  4   |  5   |  6   |  .   |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    | SHIFT  |      | SWAP | TEXT | FUZY |INVRT |      |     |      |      |  1   |  2   |  3   |BKSPC |        |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      |MO NAV|      |      | UNDO | REDO | ,-------------. ,-------------. |      |      |      |      |MO NAV|
      `----------------------------------' |      |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      | DEF  | |      |      |      |
                                    | CMD  | DEL  |------| |------|   ↵  |  0   |
                                    |      |      | SAVE | | TAB  |      |      |
                                    `--------------------' `--------------------'
  */
  [L_GIMP] = LAYOUT_ergodox_pretty(
    _____,      _____,      _____,      _____,      _____,      _____,      L_PREV,  /**/ L_NEXT, _____,    _____, KC_SLASH, KC_ASTERISK, KC_MINUS,  _____,
    KC_ESC,     LSFT(KC_L), LSFT(KC_S), KC_O,       LSFT(KC_O), _____,      _____,   /**/ _____,  _____,    KC_7,  KC_8,     KC_9,        KC_PLUS,   _____,
    LGUI(KC_A), LSFT(KC_R), KC_M,       LSFT(KC_B), KC_R,       KC_F,                /**/         _____,    KC_4,  KC_5,     KC_6,        KC_DOT,    _____,
    KC_LSFT,    _____,      KC_X,       KC_T,       KC_U,       LGUI(KC_I), _____,   /**/ _____,  _____,    KC_1,  KC_2,     KC_3,        KC_BSPC  , _____,
    MO(L_NAV),  _____,      _____,      LGUI(KC_Z), LGUI(KC_Y),                      /**/                   _____, _____,    _____,       _____,     MO(L_NAV),
                                                                _____,      _____,   /**/ _____,  _____,
                                                                            L_MAIN,  /**/ _____,
                                                    KC_LGUI,    KC_DEL,     KC_SAVE, /**/ KC_TAB, KC_ENTER, KC_0
  ),
  /* L_G_OW Game: Overwatch // OW
    ,--------------------------------------------------.     ,--------------------------------------------------.  DEF: TO Default (layer 0)
    |        |      |      |      |      |      | PREV |     | NEXT |      |      |      |      |      |        |
    |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
    |        |  F1  |  Q   |  W   |  R   |      | glhf |     |      |      |      |      |      |      |        |
    |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
    | Tab  ↹ |  V   |  A   |  S   |  D   |  X   |------|     |------|      |      |      |      |      |        |
    |--------+------+------+------+------+------|  gg  |     |      |------+------+------+------+------+--------|
    | Shift  |  1   |  C   |  T   |  E   |  H   |      |     |      |      |      |      |      |      |        |
    `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
      | CTL  |  2   |      |      |      | ,-------------. ,-------------. |      |      |      |      |      |
      `----------------------------------' | ESC  |      | |      |      | `----------------------------------'
                                    ,------|------|------| |------+------+------.
                                    |      |      | DEF  | |      |      |      |
                                    |SPACE |      |------| |------|      |      |
                                    |      |      |ENTER | |      |      |      |
                                    `--------------------' `--------------------'
  */
  [L_G_OW] = LAYOUT_ergodox_pretty(
    LGUI(KC_PSCR), _____, _____, _____, _____,    _____,    L_PREV, /**/ L_NEXT, _____, _____, _____, _____, _____, _____,
    _____,         KC_F1, KC_Q,  KC_W,  KC_E,     KC_R,     M_GLHF, /**/ _____,  _____, _____, _____, _____, _____, _____,
    KC_TAB,        KC_V,  KC_A,  KC_S,  KC_D,     KC_X,             /**/         _____, _____, _____, _____, _____, _____,
    KC_LSFT,       KC_1,  KC_C,  KC_Y,  KC_H,     KC_T,     M_GG,   /**/ _____,  _____, _____, _____, _____, _____, _____,
    KC_LCTL,       KC_2,  _____, _____, KC_N,                       /**/                _____, _____, _____, _____, _____,
                                                  _____,    _____,  /**/ _____,  _____,
                                                            L_MAIN, /**/ _____,
                                        KC_SPACE, KC_ENTER, KC_ESC, /**/ _____,  _____, _____
  ),
};

// https://docs.qmk.fm/#/feature_rgb_matrix

bool suspended = false;

#define DELAY 50

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case L_NEXT:
    case L_PREV:
    case L_MAIN:
    case L_MOVE:
      if (record->event.pressed) {
        int layer = biton32(layer_state);
        switch (keycode) {
          case L_NEXT:
            layer++; break;
          case L_PREV:
            layer--; break;
          case L_MAIN:
            layer = L_DEF; break;
          case L_MOVE:
            layer = L_MVE; break;
        }
        if (layer == LAYER_MAX) {
          layer = 0;
        } else if (layer == -1) {
          layer = LAYER_MAX-1;
        }
        layer_move(layer);
      }
      return false;
    case M_GLHF:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(DELAY) "glhf" SS_DELAY(DELAY) SS_TAP(X_ENTER));
      }
      return false;
    case M_GG:
      if (record->event.pressed) {
        (get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT)
          ? SEND_STRING(
              SS_UP(X_LSFT) SS_TAP(X_ENTER) SS_DELAY(DELAY)
              "Good Game!"
              SS_DELAY(DELAY) SS_TAP(X_ENTER) SS_DOWN(X_LSFT)
            )
          : SEND_STRING(
              SS_TAP(X_ENTER) SS_DELAY(DELAY)
              "gg"
              SS_DELAY(DELAY) SS_TAP(X_ENTER)
            );
      }
      return false;
  }
  return true;
}

/* Layer Colors
  AZURE       132, 102, 255
  BLUE        170, 255, 255
  CHARTREUSE  64,  255, 255
  CORAL       11,  176, 255
  CYAN        128, 255, 255
  GOLD        36,  255, 255
  GOLDENROD   30,  218, 218
  GREEN       85,  255, 255
  MAGENTA     213, 255, 255
  ORANGE      28,  255, 255
  PINK        234, 128, 255
  PURPLE      191, 255, 255
  RED         0,   255, 255
  SPRINGGREEN 106, 255, 255
  TEAL        128, 255, 128
  TURQUOISE   123, 90,  112
  WHITE       0,   0,   255
  YELLOW      43,  255, 255
*/
extern rgb_config_t rgb_matrix_config;

/* Color-Key Combo Meanings for Non-Applications
    BLUE   : Letters
    PURPLE : Numbers
    GREEN  : Special
    YELLOW : Function
    ORANGE : Control
    TEAL   : Navigation (Arrow / Mouse)
    PINK   : Nav Buttons / Mouse Buttons
    WHITE  : Enter / Space / Delete / Backspace / Tab / Caps
    GOLD   : Multi (Ctrl + A)
    CYAN   : Special Alternate
*/
#define HSV_BLACK 0, 0, 0
#define ________ HSV_BLACK
#define C_LTRS   HSV_BLUE
#define C_NUMS   HSV_PURPLE
#define C_SPCL   HSV_GREEN
#define C_SPCL_B HSV_CYAN
#define C_FUNC   HSV_YELLOW
#define C_CTRL   HSV_ORANGE
#define C_NAV    HSV_TEAL
#define C_NAV_B  HSV_PINK
#define C_OTHR   HSV_WHITE
#define C_MUTLI  HSV_GOLD

#define C_MED_S  HSV_GOLD
#define C_MED_P  HSV_GOLDENROD
#define C_VOL_D  HSV_CYAN
#define C_VOL_M  HSV_TURQUOISE

#define C_A_AUD  HSV_RED

#define C_FS_0 HSV_WHITE
#define C_FS_1 HSV_RED
#define C_FS_2 HSV_ORANGE
#define C_FS_3 HSV_YELLOW
#define C_FS_4 HSV_GREEN
#define C_FS_5 HSV_BLUE
#define C_FS_6 HSV_PURPLE

#define G_MOVE HSV_CYAN
#define G_ATTK HSV_RED
#define G_ACTN HSV_YELLOW
#define G_OTHR HSV_PURPLE
#define G_INFO HSV_WHITE
#define G_MENU HSV_PINK

/* Color Template
  [X] = {
    {________}, {________}, {________}, {________}, {________},  {________}, {________}, {________}, {________}, {________},
    {________}, {________}, {________}, {________}, {________},  {________}, {________}, {________}, {________}, {________},
    {________}, {________}, {________}, {________}, {________},  {________}, {________}, {________}, {________}, {________},
    {________}, {________}, {________}, {________}, {________},  {________}, {________}, {________}, {________}, {________},
    {________}, {________}, {________}, {________},                          {________}, {________}, {________}, {________},
  },
*/
const uint8_t PROGMEM ledmap[][MATRIX_ROWS*MATRIX_COLS][3] = {
  [L_DEF] = {
    {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS},  {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS},
    {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS},  {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS},
    {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS},  {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_SPCL},
    {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS},  {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_LTRS}, {C_SPCL},
    {C_OTHR}, {C_CTRL}, {C_CTRL}, {C_CTRL},                      {C_SPCL}, {C_SPCL}, {C_SPCL}, {C_SPCL},
  },
  [L_NUM] = {
    {________}, {________}, {________}, {________}, {________},  {________}, {________}, {C_SPCL},   {C_SPCL},   {C_SPCL},
    {C_SPCL_B}, {C_SPCL},   {C_SPCL},   {C_SPCL},   {C_SPCL_B},  {________}, {C_LTRS},   {C_LTRS},   {C_LTRS},   {C_SPCL},
    {C_SPCL_B}, {C_SPCL},   {C_SPCL},   {C_SPCL},   {C_SPCL_B},  {C_OTHR},   {C_LTRS},   {C_LTRS},   {C_LTRS},   {C_SPCL},
    {C_SPCL_B}, {C_SPCL},   {C_SPCL},   {C_SPCL},   {C_SPCL_B},  {________}, {C_LTRS},   {C_LTRS},   {C_LTRS},   {C_OTHR},
    {________}, {________}, {________}, {________},                          {C_SPCL},   {________}, {________}, {________},
  },
  // [L_EMOJI] = {
  //   {C_FS_0}, {C_FS_1}, {C_FS_2}, {C_FS_3}, {C_FS_4},  {C_FS_4}, {C_FS_3}, {C_FS_2}, {C_FS_1}, {C_FS_0},
  //   {C_FS_1}, {C_FS_2}, {C_FS_3}, {C_FS_4}, {C_FS_5},  {C_FS_5}, {C_FS_4}, {C_FS_3}, {C_FS_2}, {C_FS_1},
  //   {C_FS_2}, {C_FS_3}, {C_FS_4}, {C_FS_5}, {C_FS_6},  {C_FS_6}, {C_FS_5}, {C_FS_4}, {C_FS_3}, {C_FS_2},
  //   {C_FS_3}, {C_FS_4}, {C_FS_5}, {C_FS_6}, {C_FS_0},  {C_FS_0}, {C_FS_6}, {C_FS_5}, {C_FS_4}, {C_FS_3},
  //   {C_FS_4}, {C_FS_5}, {C_FS_6}, {C_FS_0},                      {C_FS_0}, {C_FS_6}, {C_FS_5}, {C_FS_4},
  // },
  [L_NAV] = {
    {________}, {________}, {________}, {________}, {________},  {________}, {________}, {________}, {________}, {________},
    {C_NAV},    {C_NAV},    {C_NAV},    {C_NAV},    {C_NAV},     {C_NAV_B},  {C_NAV_B},  {C_NAV_B},  {C_NAV_B},  {________},
    {C_MUTLI},  {C_NAV_B},  {C_NAV_B},  {C_NAV_B},  {C_NAV},     {C_NAV},    {C_NAV},    {C_NAV},    {C_NAV},    {C_CTRL},
    {C_MUTLI},  {C_MUTLI},  {C_MUTLI},  {C_MUTLI},  {C_NAV},     {________}, {C_SPCL},   {C_SPCL},   {________}, {________},
    {________}, {________}, {________}, {________},                          {________}, {________}, {C_OTHR},   {C_OTHR},
  },
  [L_FUNC] = {
    {________}, {________}, {________}, {________}, {________},  {________}, {________}, {________}, {________}, {________},
    {________}, {________}, {________}, {________}, {________},  {________}, {C_FUNC},   {C_FUNC},   {C_FUNC},   {C_FUNC},
    {________}, {C_VOL_D},  {C_VOL_M},  {C_VOL_D},  {C_OTHR},    {________}, {C_FUNC},   {C_FUNC},   {C_FUNC},   {C_FUNC},
    {________}, {C_MED_S},  {C_MED_P},  {C_MED_S},  {________},  {________}, {C_FUNC},   {C_FUNC},   {C_FUNC},   {C_FUNC},
    {________}, {________}, {________}, {________},                          {________}, {________}, {________}, {________},
  },
  [L_AUD] = {
    {________}, {________}, {________}, {________}, {________},  {________}, {________}, {________}, {________}, {________},
    {C_A_AUD},  {C_A_AUD},  {C_A_AUD},  {C_A_AUD},  {C_A_AUD},   {________}, {C_NAV_B},  {C_NAV},    {C_NAV_B},  {________},
    {C_A_AUD},  {C_A_AUD},  {C_A_AUD},  {C_A_AUD},  {C_A_AUD},   {________}, {C_NAV},    {C_NAV},    {C_NAV},    {________},
    {C_A_AUD},  {C_A_AUD},  {C_A_AUD},  {C_A_AUD},  {________},  {________}, {________}, {________}, {________}, {________},
    {________}, {C_A_AUD},  {________}, {________},                          {________}, {________}, {________}, {________},
  },
  [L_GIMP] = {
    {________}, {________}, {________}, {________}, {________},  {________}, {________}, {C_SPCL},   {C_SPCL},   {C_SPCL},
    {________}, {C_SPCL},   {C_SPCL},   {C_SPCL},   {________},  {________}, {C_LTRS},   {C_LTRS},   {C_LTRS},   {C_SPCL},
    {C_SPCL},   {C_SPCL},   {C_SPCL},   {C_SPCL},   {C_SPCL},    {________}, {C_LTRS},   {C_LTRS},   {C_LTRS},   {C_SPCL},
    {________}, {C_SPCL},   {C_SPCL},   {C_SPCL},   {C_SPCL},    {________}, {C_LTRS},   {C_LTRS},   {C_LTRS},   {C_OTHR},
    {________}, {________}, {C_SPCL},   {C_SPCL},                            {________}, {________}, {________}, {________},
  },
  [L_G_OW] = {
    {________}, {________}, {________}, {________}, {________},  {________}, {________}, {________}, {________}, {________},
    {G_INFO},   {G_ATTK},   {G_MOVE},   {G_ACTN},   {G_ACTN},    {________}, {________}, {________}, {________}, {________},
    {G_ATTK},   {G_MOVE},   {G_MOVE},   {G_MOVE},   {G_ATTK},    {________}, {________}, {________}, {________}, {________},
    {G_ACTN},   {G_INFO},   {G_INFO},   {G_ACTN},   {G_ACTN},    {________}, {________}, {________}, {________}, {________},
    {G_ACTN},   {________}, {________}, {G_MENU},                            {________}, {________}, {________}, {________},
  },
};

/*
* ,----------------------------------. ,----------------------------------.
* |  28  |  27  |  26  |  25  |  24  | |   0  |   1  |   2  |   3  |   4  |
* |------+------+------+------+------| |------+------+------+------+------|
* |  33  |  32  |  31  |  30  |  29  | |   5  |   6  |   7  |   8  |   9  |
* |------+------+------+------+------| |------+------+------+------+------|
* |  38  |  37  |  36  |  35  |  34  | |  10  |  11  |  12  |  13  |  14  |
* |------+------+------+------+------| |------+------+------+------+------|
* |  43  |  42  |  41  |  40  |  39  | |  15  |  16  |  17  |  18  |  19  |
* |------+------+------+------+------' `------+------+------+------+------'
* |  47  |  46  |  45  |  44  |               |  20  |  21  |  22  |  23  |
* `---------------------------'               `---------------------------'
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
    skc(l, 0,28);skc(l, 1,27);skc(l, 2,26);skc(l, 3,25);skc(l, 4,24); skc(l, 5, 0);skc(l, 6, 1);skc(l, 7, 2);skc(l, 8, 3);skc(l, 9, 4);
    skc(l,10,33);skc(l,11,32);skc(l,12,31);skc(l,13,30);skc(l,14,29); skc(l,15, 5);skc(l,16, 6);skc(l,17, 7);skc(l,18, 8);skc(l,19, 9);
    skc(l,20,38);skc(l,21,37);skc(l,22,36);skc(l,23,35);skc(l,24,34); skc(l,25,10);skc(l,26,11);skc(l,27,12);skc(l,28,13);skc(l,29,14);
    skc(l,30,43);skc(l,31,42);skc(l,32,41);skc(l,33,40);skc(l,34,39); skc(l,35,15);skc(l,36,16);skc(l,37,17);skc(l,38,18);skc(l,39,19);
    skc(l,40,47);skc(l,41,46);skc(l,42,45);skc(l,43,44);                           skc(l,44,20);skc(l,45,21);skc(l,46,22);skc(l,47,23);
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  set_layer_color(biton32(layer_state));
  return true;
}

/* Layer LED Indicators
 *  0,  8, 16, 24: 000
 *  1,  9, 17, 25: 001
 *  2, 10, 18, 26: 010
 *  3, 11, 19, 27: 011
 *  4, 12, 20, 28, 100
 *  5, 13, 21, 29: 101
 *  6, 14, 22, 30: 110
 *  7, 15, 23, 31: 111
 */
void sps_led_000(void) { ergodox_right_led_1_off(); ergodox_right_led_2_off(); ergodox_right_led_3_off(); }
void sps_led_001(void) { ergodox_right_led_1_off(); ergodox_right_led_2_off(); ergodox_right_led_3_on();  }
void sps_led_010(void) { ergodox_right_led_1_off(); ergodox_right_led_2_on();  ergodox_right_led_3_off(); }
void sps_led_011(void) { ergodox_right_led_1_off(); ergodox_right_led_2_on();  ergodox_right_led_3_on();  }
void sps_led_100(void) { ergodox_right_led_1_on();  ergodox_right_led_2_off(); ergodox_right_led_3_off(); }
void sps_led_101(void) { ergodox_right_led_1_on();  ergodox_right_led_2_off(); ergodox_right_led_3_on();  }
void sps_led_110(void) { ergodox_right_led_1_on();  ergodox_right_led_2_on();  ergodox_right_led_3_off(); }
void sps_led_111(void) { ergodox_right_led_1_on();  ergodox_right_led_2_on();  ergodox_right_led_3_on();  }

layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    switch (biton32(state)) {
      case 0:
      case 8:
      case 16:
      case 24:
        sps_led_000(); break;
      case 1:
      case 9:
      case 17:
      case 25:
        sps_led_001(); break;
      case 2:
      case 10:
      case 18:
      case 26:
        sps_led_010(); break;
      case 3:
      case 11:
      case 19:
      case 27:
        sps_led_011(); break;
      case 4:
      case 12:
      case 20:
      case 28:
        sps_led_100(); break;
      case 5:
      case 13:
      case 21:
      case 29:
        sps_led_101(); break;
      case 6:
      case 14:
      case 22:
      case 30:
        sps_led_110(); break;
      case 7:
      case 15:
      case 23:
      case 31:
        sps_led_111(); break;
      default:
        break;
    }
    return state;
};

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
  rgb_matrix_enable();
}
