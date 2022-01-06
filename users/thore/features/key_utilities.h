#pragma once

#include QMK_KEYBOARD_H

bool is_alphabetical_keycode(uint16_t keycode);
bool is_tap_or_hold_keycode(uint16_t keycode);
uint16_t parse_possible_tap_or_hold_keycode(uint16_t keycode);

bool is_key_press_event(keyrecord_t* record);
bool tap_or_hold_key_got_tapped(keyrecord_t* record);

bool key_got_tapped(uint16_t keycode, keyrecord_t* record);
