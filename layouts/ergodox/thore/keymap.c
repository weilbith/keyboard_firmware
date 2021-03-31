#include QMK_KEYBOARD_H
#include "thore.h"
#include "print.h"

enum layer_names {
  LAYER_QWERTY = 0,
  LAYER_SYMBOLS,
  LAYER_NUMBERS,
  LAYER_I18N,
  LAYER_WORKMAN,
};

enum custom_keycodes {
  F_CTRL         = LCTL_T(KC_F), // QWERTY
  T_CTRL         = LCTL_T(KC_T), // Workman
  J_CTRL         = RCTL_T(KC_J), // QWERTY
  N_CTRL         = RCTL_T(KC_N), // Workman
  D_SHIFT        = LSFT_T(KC_D), // QWERTY
  H_SHIFT        = LSFT_T(KC_H), // Workman
  K_SHIFT        = RSFT_T(KC_K), // QWERTY
  E_SHIFT        = RSFT_T(KC_E), // Workman
  S_GUI          = LGUI_T(KC_S), // QWERTY & Workman
  L_GUI          = RGUI_T(KC_L), // QWERTY
  O_GUI          = RGUI_T(KC_E), // Workman
  A_ALT          = LALT_T(KC_A), // QWERTY & Workman
  SCOLON_ALT     = LALT_T(KC_SCOLON), // QWERTY
  I_ALT          = LALT_T(KC_I), // Workman
  SPACE_SYMBOLS  = LT(LAYER_SYMBOLS, KC_SPACE),
  BSPACE_SYMBOLS = LT(LAYER_SYMBOLS, KC_BSPACE),
  ENTER_NUMBERS  = LT(LAYER_NUMBERS, KC_ENTER),
  TAB_NUMBERS    = LT(LAYER_NUMBERS, KC_TAB),
  ESCAPE_I18N    = LT(LAYER_I18N, KC_ESCAPE),
  DELETE_I18N    = LT(LAYER_I18N, KC_DELETE),
  KC_AE          = RALT(KC_Q),
  KC_OE          = RALT(KC_P),
  KC_UE          = RALT(KC_Y),
  KC_SZ          = RALT(KC_S),
  KC_EURO        = RALT(KC_5),
};

enum tab_dance_codes {
  PARENTS = 0,
  SQUARES,
  CURLY,
  ANGLES,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [PARENTS] = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LEFT_PAREN, KC_RIGHT_PAREN),
  [SQUARES] = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LBRACKET, KC_RBRACKET),
  [CURLY]   = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
  [ANGLES]  = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT_ergodox_pretty(
    TG(LAYER_WORKMAN), KC_NO,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_PSCREEN,
    KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_NO,                                          KC_NO,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_NO,
    KC_NO,          A_ALT,          S_GUI,          D_SHIFT,        F_CTRL,         KC_G,                                                                           KC_H,           J_CTRL,         K_SHIFT,        L_GUI,          SCOLON_ALT,     KC_NO,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_B,                                                                                                           KC_N,           KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                                    KC_NO,          KC_NO,
                                                                                    BSPACE_SYMBOLS, TAB_NUMBERS,    ESCAPE_I18N,    DELETE_I18N,    ENTER_NUMBERS,  SPACE_SYMBOLS
  ),
  

  [LAYER_SYMBOLS] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXCLAIM,     KC_AT,          KC_HASH,        KC_DOLLAR,      KC_PERCENT,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRCUMFLEX,  KC_AMPERSAND,   KC_ASTERISK,    KC_KP_MINUS,    KC_UNDERSCORE,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_GRAVE,       TD(CURLY),      TD(SQUARES),    TD(PARENTS),    TD(ANGLES),                                                                     KC_RABK,        KC_RIGHT_PAREN, KC_RBRACKET,    KC_RCBR,        KC_COLON,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TILDE,       KC_PIPE,        KC_BSLASH,      KC_QUOTE,       KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_DOUBLE_QUOTE,KC_PLUS,        KC_EQUAL,       KC_QUESTION,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_NUMBERS] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,                                                                         KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F5,                                                                                                          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_I18N] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_EURO,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_UE,          KC_TRANSPARENT, KC_OE,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AE,          KC_SZ,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_WORKMAN] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_PSCREEN,
    KC_NO,          KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,           KC_NO,                                          KC_NO,          KC_J,           KC_F,           KC_U,           KC_P,           KC_SCOLON,      KC_NO,
    KC_NO,          A_ALT,          S_GUI,          H_SHIFT,        T_CTRL,         KC_G,                                                                           KC_Y,           N_CTRL,         E_SHIFT,        O_GUI,          I_ALT,          KC_NO,
    KC_NO,          KC_Z,           KC_X,           KC_M,           KC_C,           KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_L,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_V,                                                                                                           KC_K,           KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                                    KC_NO,          KC_NO,
                                                                                    BSPACE_SYMBOLS, TAB_NUMBERS,    ESCAPE_I18N,    DELETE_I18N,    ENTER_NUMBERS,  SPACE_SYMBOLS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    uprintf(
      "0x%04X,%u,%u,%u\n",
      keycode,
      record->event.key.row,
      record->event.key.col,
      get_highest_layer(layer_state)
    );
  }

  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD(PARENTS):
    case TD(SQUARES):
    case TD(CURLY):
    case TD(ANGLES):
        return TAPPING_TERM_DANCING_BRACKETS;

    default:
        return TAPPING_TERM;
  }
}
