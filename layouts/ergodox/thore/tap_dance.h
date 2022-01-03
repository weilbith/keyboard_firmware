#pragma once

#include QMK_KEYBOARD_H
#include "thore.h"

enum tab_dance_codes {
  PARENTS = 0,
  SQUARES,
  CURLY,
  ANGLES,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [PARENTS] = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LEFT_PAREN, KC_RIGHT_PAREN),
  [SQUARES] = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LEFT_BRACKET, KC_RBRACKET),
  [CURLY]   = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
  [ANGLES]  = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD(PARENTS):
    case TD(SQUARES):
    case TD(CURLY):
    case TD(ANGLES):
        return TAPPING_TERM_DANCING_BRACKETS;

    default:
        return TAPPING_TERM;
  }
}
