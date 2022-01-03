#pragma once

#include "process_tap_dance.h"

/*
* The feature Dancing Brackets makes use of the dap dance functionality to save
* keys.
* Therefore a single tap of such a key gets the opening bracket character.
* Double tap the matching closing bracket character and triple tap both
* together.
* This reduces the amount of keys for bracket characters by half.
* This is more convenient for environments where closing brackets get usually
* inserted automatically. So a single tap is the most common case.
*/

typedef struct {
  uint16_t open_char;
  uint16_t close_char;
} dancing_bracket_config_t;

# define ACTION_TAP_DANCE_DANCING_BRACKET(open_char, close_char) \
    { \
      .fn = { \
        tap_dance_dancing_bracket_on_each_tap, \
        tap_dance_dancing_bracket_finished, \
        tap_dance_dancing_bracket_reset \
      }, \
      .user_data = (void *)&((dancing_bracket_config_t){open_char, close_char }), \
    }

void tap_dance_dancing_bracket_on_each_tap(qk_tap_dance_state_t *state, void *user_data);
void tap_dance_dancing_bracket_finished(qk_tap_dance_state_t *state, void *user_data);
void tap_dance_dancing_bracket_reset(qk_tap_dance_state_t *state, void *user_data);
