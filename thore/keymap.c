#include QMK_KEYBOARD_H
#include "thore.h"

enum layer_names {
  LAYER_QWERTY = 0,
  LAYER_SYMBOLS,
  LAYER_NUMBERS,
  LAYER_WORKMAN,
};

enum custom_keycodes {
  F_CTRL         = LCTL_T(KC_F), // QWERTY
  T_CTRL         = LCTL_T(KC_T), // Workman
  J_CTRL         = RCTL_T(KC_J), // QWERTY
  N_CTRL         = RCTL_T(KC_N), // Workman
  D_ALT          = LALT_T(KC_D), // QWERTY
  H_ALT          = LALT_T(KC_H), // Workman
  K_ALT          = RALT_T(KC_K), // QWERTY
  E_ALT          = RALT_T(KC_E), // Workman
  ESCAPE_SHIFT   = LSFT_T(KC_ESCAPE),
  DELETE_SHIFT   = LSFT_T(KC_DELETE),
  SPACE_SYMBOLS  = LT(LAYER_SYMBOLS, KC_SPACE),
  BSPACE_SYMBOLS = LT(LAYER_SYMBOLS, KC_BSPACE),
  ENTER_NUMBERS  = LT(LAYER_NUMBERS, KC_ENTER),
  TAB_NUMBERS    = LT(LAYER_NUMBERS, KC_TAB),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT_ergodox_pretty(
    TG(LAYER_WORKMAN), KC_NO,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_PSCREEN,
    KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_NO,                                          KC_NO,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_NO,
    ESCAPE_SHIFT,   KC_A,           KC_S,           D_ALT,          F_CTRL,         KC_G,                                                                           KC_H,           J_CTRL,         K_ALT,          KC_L,           KC_SCOLON,      DELETE_SHIFT,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_B,                                                                                                           KC_N,           KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                                    KC_NO,          KC_NO,
                                                                                    BSPACE_SYMBOLS, TAB_NUMBERS,    OSM(MOD_LGUI),  LALT(KC_GRAVE), ENTER_NUMBERS,  SPACE_SYMBOLS
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,                                                                         KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F5,                                                                                                          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_WORKMAN] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_PSCREEN,
    KC_NO,          KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,           KC_NO,                                          KC_NO,          KC_J,           KC_F,           KC_U,           KC_P,           KC_SCOLON,      KC_NO,
    ESCAPE_SHIFT,   KC_A,           KC_S,           H_ALT,          T_CTRL,         KC_G,                                                                           KC_Y,           N_CTRL,         E_ALT,          KC_O,           KC_I,           DELETE_SHIFT,
    KC_NO,          KC_Z,           KC_X,           KC_M,           KC_C,           KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_L,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_V,                                                                                                           KC_K,           KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                                    KC_NO,          KC_NO,
                                                                                    BSPACE_SYMBOLS, TAB_NUMBERS,    OSM(MOD_LGUI),  LALT(KC_GRAVE), ENTER_NUMBERS,  SPACE_SYMBOLS
  ),
};

backlight_hsv_color_t backlight_modifier_colors[] = {};
backlight_hsv_color_t backlight_layer_colors[] = {};

void matrix_scan_user(void) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  backlight_apply_for_modifier_and_layer();
};
