#include QMK_KEYBOARD_H
#include "dancing_brackets.h"


typedef enum {
    SINGLE_TAP,
    DOUBLE_TAP,
    TRIPLE_TAP,
    MULTI_TAP,
    HOLDING,
} tap_dance_state_t;

static tap_dance_state_t tap_dance_state;


int get_current_tap_dance_state(qk_tap_dance_state_t *state);
int get_current_tap_dance_state(qk_tap_dance_state_t *state) {
  if (state->interrupted || !state->pressed) {
    switch (state->count) {
      case 1:
        return SINGLE_TAP;
      case 2:
        return DOUBLE_TAP;
      case 3:
        return TRIPLE_TAP;
      default:
        return MULTI_TAP;
    }
  } else {
    return HOLDING;
  }
};

void tap_dance_dancing_bracket_on_each_tap(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count > 3) {
    // There can't be reached any other state here. Stop tap dance.
    timer_clear();
  }
}

void tap_dance_dancing_bracket_finished(qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_state = get_current_tap_dance_state(state);
  dancing_bracket_config_t *config = (dancing_bracket_config_t *)user_data;

  switch(tap_dance_state) {
    case SINGLE_TAP:
      tap_code16(config->open_char);
      break;

    case DOUBLE_TAP:
      tap_code16(config->close_char);
      break;

    case TRIPLE_TAP:
      tap_code16(config->open_char);
      tap_code16(config->close_char);
      break;

    default:
      break;
  }
}

void tap_dance_dancing_bracket_reset(qk_tap_dance_state_t *state, void *user_data) {
  return;
}
