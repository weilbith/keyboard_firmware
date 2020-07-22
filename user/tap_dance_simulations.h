#pragma once

#include "process_tap_dance.h"

typedef struct {
  uint16_t keycode;
  uint16_t modifier;
} tap_dance_mt_config_t;

# define ACTION_TAP_DANCE_MT(keycode, modifier) \
    { .fn = {tap_dance_mt_on_each_tap, tap_dance_mt_finished, tap_dance_mt_reset}, .user_data = (void *)&((tap_dance_mt_config_t){keycode, modifier}), }

void tap_dance_mt_on_each_tap (qk_tap_dance_state_t *state, void *user_data);
void tap_dance_mt_finished (qk_tap_dance_state_t *state, void *user_data);
void tap_dance_mt_reset (qk_tap_dance_state_t *state, void *user_data);
