#pragma once

#include QMK_KEYBOARD_H
#include "custom_keycodes.h"

const key_override_t override_shift_backspace = ko_make_basic(MOD_MASK_SHIFT, BSPACE_SYMBOLS, KC_DELETE);

const key_override_t **key_overrides = (const key_override_t *[]){
    &override_shift_backspace,
    NULL,
};
