#include "caps_word.h"

bool caps_word_enabled = false;

bool both_shift_keys_are_pressed(void) {
  #ifndef NO_ACTION_ONESHOT
    uint8_t active_modifier = get_mods() | get_oneshot_mods();
  #else
    uint8_t active_modifier = get_mods();
  #endif

  return (active_modifier & MOD_MASK_SHIFT) == MOD_MASK_SHIFT;
}

bool is_key_press_event(keyrecord_t* record) {
  return record->event.pressed;
}

bool is_tap_or_hold_keycode(uint16_t keycode) {
  switch(keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      return true;

    default:
      return false;
  }
}

bool tap_or_hold_key_got_tapped(keyrecord_t* record) {
  return record->tap.count > 0;
}

bool is_shifted_caps_word_keycode(uint16_t keycode) {
  switch (keycode) {
    case KC_A ... KC_Z:
      return true;

    default:
      return false;
  }
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
  if (!is_key_press_event(record)) {
    return;
  }

  if (is_tap_or_hold_keycode(keycode)) {
    if (tap_or_hold_key_got_tapped(record)) {
      keycode &= 0xff;
    } else {
      return;
    }
  }

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

