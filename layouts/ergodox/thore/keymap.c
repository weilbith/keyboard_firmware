#include QMK_KEYBOARD_H
#include "thore.h"
#include "print.h"
#include "layer_names.h"
#include "custom_keycodes.h"
#include "key_overrides.h"
#include "tap_dance.h"
#include "combos.h"
#include "layout.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_ergodox_34_keys(
    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
    A_ALT,          S_GUI,          D_SHIFT,        F_CTRL,         G_I18N,
    KC_Z,           KC_X,           KC_C,           KC_V,
                                    KC_B,           BSPACE_NUMBERS, TAB_CONTROLS,

    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
    H_I18N,         J_CTRL,         K_SHIFT,        L_GUI,          SCOLON_ALT,
                    KC_M,           KC_COMMA,       KC_DOT,         KC_KP_SLASH,
    ENTER_FUNCTIONS,SPACE_SYMBOLS,  KC_N
  ),
  
  [LAYER_SYMBOLS] = LAYOUT_ergodox_34_keys_left_hand(
    KC_EXCLAIM,     KC_AT,                KC_HASH,          KC_DOLLAR,      KC_PERCENT,
    KC_PIPE,        TD(CURLY_BRACES),     TD(BRACKETS),     TD(PARENTHESES),TD(ANGLE_BRACKETS),
    KC_BACKSLASH,   KC_AMPERSAND,         KC_CIRCUMFLEX,    KC_TILDE,
                                          KC_KP_EQUAL,      KC_UNDERSCORE,  KC_KP_MINUS
  ),

  [LAYER_NUMBERS] = LAYOUT_ergodox_34_keys_right_hand(
    KC_KP_PLUS,     KC_4,                 KC_5,             KC_6,           KC_KP_ASTERISK, 
    KC_0,           KC_1,                 KC_2,             KC_3,           KC_COLON,
                    KC_7,                 KC_8,             KC_9,           KC_QUESTION,
    KC_DOUBLE_QUOTE,KC_QUOTE,             KC_GRAVE
  ),

  [LAYER_FUNCTIONS] = LAYOUT_ergodox_34_keys_left_hand(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_NO,
    KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,
    KC_F9,          KC_F10,         KC_F11,         KC_F12,
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_CONTROLS] = LAYOUT_ergodox_34_keys_right_hand(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,
                    KC_PAGE_DOWN,   KC_PAGE_UP,     KC_END,         KC_NO,
    KC_TRANSPARENT, KC_PRINT_SCREEN,KC_HOME
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
