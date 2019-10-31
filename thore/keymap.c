#include QMK_KEYBOARD_H
#include "version.h"

// Custom key names
#define MOD_TMUX LALT(KC_GRAVE)
#define SUPER MOD_LGUI

enum layer_names {
  LAYER_BASE  = 0,
  LAYER_ARROW,
  LAYER_MOUSE,
};

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum tab_dance_codes {
  TD_A = 0,
  TD_B,
  TD_C,
  TD_D,
  TD_E,
  TD_F,
  TD_G,
  TD_H,
  TD_I,
  TD_J,
  TD_K,
  TD_L,
  TD_M,
  TD_N,
  TD_O,
  TD_P,
  TD_Q,
  TD_R,
  TD_S,
  TD_T,
  TD_U,
  TD_V,
  TD_W,
  TD_X,
  TD_Y,
  TD_Z,
  TD_SCOLON,
  TD_SLASH,
  TD_COMMA,
  TD_DOT,
  TD_TMUX,
};

// To keep this list always complete, not used keys are dancing with themselves.
// The idea is that they can be statically used in the layout and only the
// alternative key code must be edited here.

qk_tap_dance_action_t tap_dance_actions[] = {
[TD_A]      = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_GRAVE), // A `
[TD_B]      = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_B), // B B
[TD_C]      = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_BSLASH), // C 
[TD_D]      = ACTION_TAP_DANCE_DOUBLE(KC_D, KC_LBRACKET), // D [
[TD_E]      = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_HASH), // E #
[TD_F]      = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_LPRN), // F (
[TD_G]      = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_LABK), // G <
[TD_H]      = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_RABK), // H >
[TD_I]      = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_ASTR), // I *
[TD_J]      = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_RPRN), // J )
[TD_K]      = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_RBRACKET), // K ]
[TD_L]      = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_RCBR), // L }
[TD_M]      = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_DQUO), // M "
[TD_N]      = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_N), // N N
[TD_O]      = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_KP_MINUS), // O -
[TD_P]      = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_UNDS), // P _
[TD_Q]      = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_EXCLAIM), // Q !
[TD_R]      = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_DLR), // R $
[TD_S]      = ACTION_TAP_DANCE_DOUBLE(KC_S, KC_LCBR), // S {
[TD_T]      = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_PERC), // T %
[TD_U]      = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_AMPR), // U &
[TD_V]      = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_QUOTE), // V '
[TD_W]      = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_AT), // W @
[TD_X]      = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_PIPE), // X |
[TD_Y]      = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_CIRC), // Y ^
[TD_Z]      = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_TILD), // Z ~
[TD_SCOLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON, KC_COLON), // ; :
[TD_SLASH]  = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_QUESTION), // / ?
[TD_COMMA]  = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_PLUS), // , +
[TD_DOT]    = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_EQUAL), // . =
/* [TD_TMUX]   = ACTION_TAP_DANCE_DOUBLE(, TAB), */
};

// Modifier should be always OSM.
// Letters should use tab dance for special characters.
//
// TODO (can they be optimized?):
//  zsh complete suggestion: alt tab
//  zsh use suggestion: alt return
//  fasd directory: alt d
//  fasd file: alt f
//  fzf folder: ctrl d
//  fzf file: ctrl f
//  fzf history: ctrl h
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = LAYOUT_ergodox_pretty(
  KC_NO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,                                          KC_NO,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_PSCREEN,
  KC_TAB,         TD(TD_Q),       TD(TD_W),       TD(TD_E),       TD(TD_R),       TD(TD_T),       KC_NO,                                          TG(1),          TD(TD_Y),       TD(TD_U),       TD(TD_I),       TD(TD_O),       TD(TD_P),       KC_DELETE,
  KC_ESCAPE,      TD(TD_A),       TD(TD_S),       TD(TD_D),       TD(TD_F),       TD(TD_G),                                                                       TD(TD_H),       TD(TD_J),       TD(TD_K),       TD(TD_L),       TD(TD_SCOLON),  OSM(MOD_LCTL),
  OSM(MOD_LSFT),  TD(TD_Z),       TD(TD_X),       TD(TD_C),       TD(TD_V),       TD(TD_B),       KC_NO,                                          TG(2),          TD(TD_N),       TD(TD_M),       TD(TD_COMMA),   TD(TD_DOT),     TD(TD_SLASH),   OSM(MOD_LALT),
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          OSM(SUPER),                                                                                                     MOD_TMUX,       KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                  KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                                  KC_NO,          KC_NO,
                                                                                  KC_SPACE,       KC_BSPACE,      KC_NO,          KC_NO,          KC_TAB,         KC_ENTER
),

[LAYER_ARROW] = LAYOUT_ergodox_pretty(
  KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_9,           KC_F10,          KC_F12,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

[LAYER_MOUSE] = LAYOUT_ergodox_pretty(
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2
),
};


rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    switch (layer) {
      case 1:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(0,255,255);
        }
        break;
      case 2:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(168,255,255);
        }
        break;
      case 3:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(38,255,255);
        }
        break;
      default:
        if(!disable_layer_color) {
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
        }
        break;
    }
    return state;

};
