#pragma once

#include QMK_KEYBOARD_H
#include "custom_keycodes.h"

enum combos {
  ESC_COMBO_CODE,
  LAST_COMBO_INDEX,
};

const uint16_t PROGMEM esc_combo[] = {S_GUI, D_SHIFT, COMBO_END};

// TODO: Why does this not work?
// uint16_t COMBO_LEN = LAST_COMBO_INDEX;
// combo_t key_combos[] = {
combo_t key_combos[COMBO_COUNT] = {
  [ESC_COMBO_CODE] = COMBO(esc_combo, KC_ESCAPE),
};
