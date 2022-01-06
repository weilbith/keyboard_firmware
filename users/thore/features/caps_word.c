#include "caps_word.h"
#include "key_utilities.h"

bool caps_word_enabled = false;

bool both_shift_keys_are_pressed(void) {
  #ifndef NO_ACTION_ONESHOT
    uint8_t active_modifier = get_mods() | get_oneshot_mods();
  #else
    uint8_t active_modifier = get_mods();
  #endif

  return (active_modifier & MOD_MASK_SHIFT) == MOD_MASK_SHIFT;
}

bool is_shifted_caps_word_keycode(uint16_t keycode) {
  return is_alphabetical_keycode(keycode);
}

bool is_not_shifted_caps_word_keycode(uint16_t keycode) {
  switch (keycode) {
    case KC_1 ... KC_0:
    case KC_BACKSPACE:
    case KC_UNDERSCORE:
      return true;

    default:
      return false;
  }
}

bool is_caps_word_keycode(uint16_t keycode) {
  return is_shifted_caps_word_keycode(keycode) || is_not_shifted_caps_word_keycode(keycode);
}

void handle_caps_word(uint16_t keycode, keyrecord_t* record) {
  if (!key_got_tapped(keycode, record)) {
    return;
  }

  keycode = parse_possible_tap_or_hold_keycode(keycode);

  if (!is_caps_word_keycode(keycode)) {
    caps_word_enabled = false;
  } else if (is_shifted_caps_word_keycode(keycode)) {
    add_oneshot_mods(MOD_LSFT);
  }
}

bool possibly_process_caps_word(uint16_t keycode, keyrecord_t* record) {
  if (!caps_word_enabled && both_shift_keys_are_pressed()) {
    caps_word_enabled = true;
  }

  if (caps_word_enabled) {
    handle_caps_word(keycode, record);
  }

  return true;
}

