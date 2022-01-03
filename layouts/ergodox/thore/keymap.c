#include QMK_KEYBOARD_H
#include "thore.h"
#include "print.h"
#include "layer_names.h"
#include "custom_keycodes.h"
#include "key_overrides.h"
// #include "tap_dance.h"
#include "combos.h"
#include "layout.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_ergodox_34_keys(
    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
    A_ALT,          S_GUI,          D_SHIFT,        F_CTRL,         G_I18N,
    KC_Z,           KC_X,           KC_C,           KC_V,
                                    KC_B,           BSPACE_SYMBOLS, TAB_NUMBERS,

    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
    H_I18N,         J_CTRL,         K_SHIFT,        L_GUI,          SCOLON_ALT,
                    KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,
    ENTER_NUMBERS,  SPACE_SYMBOLS,  KC_N
  ),
  

  [LAYER_SYMBOLS] = LAYOUT_ergodox_34_keys(
    KC_EXCLAIM,     KC_AT,                KC_HASH,          KC_DOLLAR,      KC_PERCENT,
    KC_COLON,       KC_LEFT_CURLY_BRACE,  KC_LEFT_BRACKET,  KC_LEFT_PAREN,  KC_LEFT_ANGLE_BRACKET,
    KC_TILDE,       KC_PIPE,              KC_BSLASH,        KC_QUOTE,
                                          KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT,

    KC_CIRCUMFLEX,  KC_AMPERSAND,         KC_ASTERISK,      KC_KP_MINUS,    KC_UNDERSCORE, 
    KC_NO,          KC_NO,                KC_NO,            KC_NO,          KC_COLON,
                    KC_NO,                KC_PLUS,          KC_EQUAL,       KC_QUESTION,
    KC_DOUBLE_QUOTE,KC_QUOTE,             KC_GRAVE
  ),

  [LAYER_NUMBERS] = LAYOUT_ergodox_34_keys(
    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,
    KC_PSCREEN,     KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,
    KC_F1,          KC_F2,          KC_F3,          KC_F4,
                                    KC_F5,          KC_TRANSPARENT, KC_TRANSPARENT,

    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,
    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT,
                    KC_F7,          KC_F8,          KC_F9,          KC_F10,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F6
  ),

  [LAYER_I18N] = LAYOUT_ergodox_34_keys(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_EURO,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_AE,          KC_SZ,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_UE,          KC_TRANSPARENT, KC_OE,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
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
