#pragma once

#include QMK_KEYBOARD_H
#include "thore.h"

enum tab_dance_codes {
  PARENTHESES = 0,
  BRACKETS,
  CURLY_BRACES,
  ANGLE_BRACKETS,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [PARENTHESES]     = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LEFT_PAREN, KC_RIGHT_PAREN),
  [BRACKETS]        = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LEFT_BRACKET, KC_RBRACKET),
  [CURLY_BRACES]    = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
  [ANGLE_BRACKETS]  = ACTION_TAP_DANCE_DANCING_BRACKET(KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD(PARENTHESES):
    case TD(BRACKETS):
    case TD(CURLY_BRACES):
    case TD(ANGLE_BRACKETS):
        return TAPPING_TERM_DANCING_BRACKETS;

    default:
        return TAPPING_TERM;
  }
}
