#include QMK_KEYBOARD_H
#include "thore.h"

void matrix_scan_user(void) {
  #ifdef USER_BACKLIGHT_ENABLE
    backlight_apply_for_modifier_and_layer();
  #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  #ifdef USER_CAPS_WORD_ENABLE
    if (!possibly_process_caps_word(keycode, record)) {
      return false;
    }
  #endif

  return true;
}
