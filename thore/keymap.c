#include QMK_KEYBOARD_H
#include "thore.h"

enum layer_names {
  LAYER_BASE  = 0,
  LAYER_SYMBOLS,
  LAYER_NUMBERS,
};

enum custom_keycodes {
  ESCAPE_SHIFT   = SFT_T(KC_ESCAPE),
  DELETE_SHIFT   = SFT_T(KC_DELETE),
  SPACE_SYMBOLS  = LT(LAYER_SYMBOLS, KC_SPACE),
  BSPACE_SYMBOLS = LT(LAYER_SYMBOLS, KC_BSPACE),
  ENTER_NUMBERS  = LT(LAYER_NUMBERS, KC_ENTER),
  TAB_NUMBERS    = LT(LAYER_NUMBERS, KC_TAB),
};


/*
 * TAP DANCE STUFF
 */

enum tab_dance_codes {
  F_CTRL = 0,
  J_CTRL,
  D_ALT,
  K_ALT,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [F_CTRL] = ACTION_TAP_DANCE_MT(KC_F, KC_LCTL),
  [J_CTRL] = ACTION_TAP_DANCE_MT(KC_J, KC_LCTL),
  [D_ALT]  = ACTION_TAP_DANCE_MT(KC_D, KC_LALT),
  [K_ALT]  = ACTION_TAP_DANCE_MT(KC_K, KC_LALT),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_ergodox_pretty(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_PSCREEN,
    KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_NO,                                          KC_NO,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_NO,
    ESCAPE_SHIFT,   KC_A,           KC_S,           TD(D_ALT),      TD(F_CTRL),     KC_G,                                                                           KC_H,           TD(J_CTRL),     TD(K_ALT),      KC_L,           KC_SCOLON,      DELETE_SHIFT,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_NO,                                          KC_NO,          KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          OSM(MOD_LGUI),                                                                  LALT(KC_GRAVE), KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                                    KC_NO,          KC_NO,
                                                                                    BSPACE_SYMBOLS, TAB_NUMBERS,    KC_NO,          KC_NO,          ENTER_NUMBERS,  SPACE_SYMBOLS
  ),

  [LAYER_SYMBOLS] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXCLAIM,     KC_AT,          KC_HASH,        KC_DOLLAR,      KC_PERCENT,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRCUMFLEX,  KC_AMPERSAND,   KC_ASTERISK,    KC_KP_MINUS,    KC_UNDERSCORE,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_GRAVE,       KC_LCBR,        KC_LBRACKET,    KC_LEFT_PAREN,  KC_LABK,                                                                        KC_RABK,        KC_RIGHT_PAREN, KC_RBRACKET,    KC_RCBR,        KC_COLON,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TILDE,       KC_PIPE,        KC_BSLASH,      KC_QUOTE,       KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_DOUBLE_QUOTE,KC_PLUS,        KC_EQUAL,       KC_QUESTION,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_NUMBERS] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
    case LAYER_BASE:
      switch (keyboard_report->mods) {
        case MOD_BIT(KC_LSFT):
          rgblight_sethsv_noeeprom(HSV_GREEN);
          rgblight_mode_noeeprom(0);
          rgblight_enable_noeeprom();
          break;

        case MOD_BIT(KC_LCTL):
          rgblight_sethsv_noeeprom(HSV_RED);
          rgblight_mode_noeeprom(0);
          rgblight_enable_noeeprom();
          break;

        case MOD_BIT(KC_LALT):
          rgblight_sethsv_noeeprom(HSV_WHITE);
          rgblight_mode_noeeprom(0);
          rgblight_enable_noeeprom();
          break;

        case MOD_BIT(KC_LGUI):
          rgblight_sethsv_noeeprom(HSV_YELLOW);
          rgblight_mode_noeeprom(0);
          rgblight_enable_noeeprom();
          break;

        default:
          rgblight_disable_noeeprom();
          break;
      }
      break;

    case LAYER_SYMBOLS:
      rgblight_sethsv_noeeprom(HSV_BLUE);
      rgblight_mode_noeeprom(0);
      rgblight_enable_noeeprom();
      break;

    case LAYER_NUMBERS:
      rgblight_sethsv_noeeprom(HSV_PINK);
      rgblight_mode_noeeprom(0);
      rgblight_enable_noeeprom();
      break;

    default:
      rgblight_disable_noeeprom();
      break;
  }
}
