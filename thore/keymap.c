#include QMK_KEYBOARD_H

enum layer_names {
  LAYER_BASE  = 0,
  LAYER_SYMBOLS,
  LAYER_NUMBERS,
};

enum custom_keycodes {
  ESCAPE_SHIFT   = SFT_T(KC_ESCAPE),
  DELETE_SHIFT   = SFT_T(KC_DELETE),
  /* GUI_CONTROL      = MT(MOD_LALT, OSM(MOD_LGUI)), */
  /* TMUX_ALT   = MT(MOD_LCTL, LALT(KC_GRAVE)), */
  SPACE_SYMBOLS  = LT(LAYER_SYMBOLS, KC_SPACE),
  BSPACE_SYMBOLS = LT(LAYER_SYMBOLS, KC_BSPACE),
  ENTER_NUMBERS  = LT(LAYER_NUMBERS, KC_ENTER),
  TAB_NUMBERS    = LT(LAYER_NUMBERS, KC_TAB),
};

enum tab_dance_codes {
  // Basic
  AE = 0,
  OE,
  UE,
  SS,

  // Advanced
  GUI_CONTROL,
  TMUX_ALT,
};

typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
} td_state_t;

static td_state_t td_state;
int cur_dance (qk_tap_dance_state_t *state);

// Finished and reset functions for advanced tap dance keycodes.
void gui_control_finished (qk_tap_dance_state_t *state, void *user_data);
void gui_control_reset (qk_tap_dance_state_t *state, void *user_data);

void tmux_alt_finished (qk_tap_dance_state_t *state, void *user_data);
void tmux_alt_reset (qk_tap_dance_state_t *state, void *user_data);

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  }
  else { return 2; }
};

void gui_control_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      set_oneshot_mods(MOD_BIT(KC_LGUI));
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LCTL));
      break;
  }
};

void gui_control_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      clear_oneshot_mods();
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LCTL));
      break;
  }
};



void tmux_alt_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);

  switch (td_state) {
    case SINGLE_TAP:
      register_mods(MOD_BIT(KC_LALT));
      register_code16(KC_GRAVE);
      break;

    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LALT));
      break;
  }
};

void tmux_alt_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_mods(MOD_BIT(KC_LALT));
      unregister_code16(KC_GRAVE);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LALT));
      break;
  }
};

// TODO: use shiftable unicodes with XT()
qk_tap_dance_action_t tap_dance_actions[] = {
  // Basic
  [AE] = ACTION_TAP_DANCE_DOUBLE(KC_A, UC(0x00e4)),
  [OE] = ACTION_TAP_DANCE_DOUBLE(KC_O, UC(0x00f6)),
  [UE] = ACTION_TAP_DANCE_DOUBLE(KC_U, UC(0x00fc)),
  [SS] = ACTION_TAP_DANCE_DOUBLE(KC_S, UC(0x00df)),

  // Advanced
  [GUI_CONTROL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_control_finished, gui_control_reset),
  [TMUX_ALT]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tmux_alt_finished, tmux_alt_reset),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_ergodox_pretty(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_PSCREEN,
    KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_NO,                                          KC_NO,          KC_Y,           TD(UE),         KC_I,           TD(OE),         KC_P,           KC_NO,
    ESCAPE_SHIFT,   TD(AE),         TD(SS),         KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      DELETE_SHIFT,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_NO,                                          KC_NO,          KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          TD(GUI_CONTROL),                                                                                                TD(TMUX_ALT),   KC_NO,          KC_NO,          KC_NO,          KC_NO,
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
