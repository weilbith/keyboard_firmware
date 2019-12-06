#pragma once

#include QMK_KEYBOARD_H

int cur_dance_state (qk_tap_dance_state_t *state);
void mt_clone_tap_dance_finished (qk_tap_dance_state_t *state, int keycode, int modifier);
void mt_clone_tap_dance_reset (qk_tap_dance_state_t *state, int keycode, int modifier);
