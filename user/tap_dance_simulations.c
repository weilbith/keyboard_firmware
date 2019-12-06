#include QMK_KEYBOARD_H
#include "tap_dance_simulations.h"


typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    MULTI_TAP,
    // TODO: Think about tap-hold case
} td_state_t;

static td_state_t td_state;


int cur_dance_state (qk_tap_dance_state_t *state);
int cur_dance_state (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  } else {
    return MULTI_TAP;
  }
};


/*
 * Clone the MT() functionality via simulation by ACTION_TAP_DANCE_FN_ADVANCED
 * The advantage is that the PERMISSIVE_HOLD option does not apply to it.
 * It is not possible to use MT() with and without permissive hold. Therefore,
 * the basic MT() usage takes advantage of it, while all occurrences with tap
 * dance will ignore it.
 */
void tap_dance_mt_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance_state(state);
  tap_dance_mt_config_t *config = (tap_dance_mt_config_t *)user_data;

  switch(td_state) {
    case SINGLE_TAP:
      register_code16(config->keycode);
      break;

    case SINGLE_HOLD:
      register_mods(MOD_BIT(config->modifier));
      break;

    case MULTI_TAP:
      for (int i = 0; i < state->count; i = i+1) {
        tap_code16(config->keycode);
      }
      break;
  }
}

void tap_dance_mt_reset (qk_tap_dance_state_t *state, void *user_data) {
  tap_dance_mt_config_t *config = (tap_dance_mt_config_t *)user_data;

  switch(td_state) {
    case SINGLE_TAP:
      unregister_code16(config->keycode);
      break;

    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(config->modifier));
      break;

    case MULTI_TAP:
      break;
  }
}
