#include QMK_KEYBOARD_H
#include "thore.h"

void matrix_scan_user(void) {
  #ifdef USER_BACKLIGHT_ENABLE
    backlight_apply_for_modifier_and_layer();
  #endif
}
