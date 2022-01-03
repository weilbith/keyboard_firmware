#pragma once

#include QMK_KEYBOARD_H
#include "custom_keycodes.h"

enum combos {
  ESCAPE_COMBO,
  ANGLE_BRACKET_COMBO,
  PARENTHESES_COMBO,
  BRACKET_COMBO,
  CURLY_BRACES_COMBO,
  LAST_COMBO_INDEX,
};

const uint16_t PROGMEM escape_combo[]         = { S_GUI, D_SHIFT, COMBO_END };
const uint16_t PROGMEM angle_bracket_combo[]  = { KC_LEFT_PAREN, KC_LEFT_ANGLE_BRACKET, COMBO_END };
const uint16_t PROGMEM parentheses_combo[]    = { KC_LEFT_BRACKET, KC_LEFT_PAREN, COMBO_END };
const uint16_t PROGMEM bracket_combo[]        = { KC_LEFT_CURLY_BRACE, KC_LEFT_BRACKET, COMBO_END };
const uint16_t PROGMEM curly_braces_combo[]   = { KC_PIPE, KC_LEFT_CURLY_BRACE, COMBO_END };

// TODO: Why does this not work?
// uint16_t COMBO_LEN = LAST_COMBO_INDEX;
// combo_t key_combos[] = {
combo_t key_combos[COMBO_COUNT] = {
  [ESCAPE_COMBO]        = COMBO(escape_combo, KC_ESCAPE),
  [ANGLE_BRACKET_COMBO] = COMBO(angle_bracket_combo, KC_RIGHT_ANGLE_BRACKET),
  [PARENTHESES_COMBO]   = COMBO(parentheses_combo, KC_RIGHT_PAREN),
  [BRACKET_COMBO]       = COMBO(bracket_combo, KC_RIGHT_BRACKET),
  [CURLY_BRACES_COMBO]  = COMBO(curly_braces_combo, KC_RIGHT_CURLY_BRACE),
};
