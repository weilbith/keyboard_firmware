#include "key_utilities.h"

bool is_alphabetical_keycode(uint16_t keycode) {
  switch (keycode) {
    case KC_A ... KC_Z:
      return true;

    default:
      return false;
  }
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

uint16_t parse_possible_tap_or_hold_keycode(uint16_t keycode) {
  if (is_tap_or_hold_keycode(keycode)) {
    return keycode & 0xff;
  } else {
    return keycode;
  }
}

bool is_key_press_event(keyrecord_t* record) {
  return record->event.pressed;
}

bool tap_or_hold_key_got_tapped(keyrecord_t* record) {
  return record->tap.count > 0;
}

bool key_got_tapped(uint16_t keycode, keyrecord_t* record) {
  if (!is_key_press_event(record)) {
    return false;
  } else if (is_tap_or_hold_keycode(keycode)) {
    return tap_or_hold_key_got_tapped(record);
  } else {
    return true;
  }
}
