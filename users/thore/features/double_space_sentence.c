#include "double_space_sentence.h"
#include "key_utilities.h"

uint16_t last_two_tapped_keycodes[2] = { KC_NO, KC_NO };

void update_last_tapped_keycodes(uint16_t keycode) {
  uint16_t last_tapped_keycode = last_two_tapped_keycodes[1];
  last_two_tapped_keycodes[0] = last_tapped_keycode;
  last_two_tapped_keycodes[1] = keycode;
}

void finishSentenceAndStartNewOne(void) {
  tap_code16(KC_BACKSPACE);
  tap_code16(KC_DOT);
  tap_code16(KC_SPACE);
  add_oneshot_mods(MOD_LSFT);
}

bool possibly_process_double_space_sentence(uint16_t keycode, keyrecord_t* record) {
  if (!key_got_tapped(keycode, record)) {
    return true;
  }

  keycode = parse_possible_tap_or_hold_keycode(keycode);

  if (
    keycode == KC_SPACE &&
    last_two_tapped_keycodes[1] == KC_SPACE &&
    is_alphabetical_keycode(last_two_tapped_keycodes[0])
  ) {
    finishSentenceAndStartNewOne();
    update_last_tapped_keycodes(keycode);
    return false;
  }

  update_last_tapped_keycodes(keycode);
  return true;
}
