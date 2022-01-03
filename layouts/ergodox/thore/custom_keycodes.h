#pragma once

#include QMK_KEYBOARD_H
#include "layer_names.h"

#define G_I18N          LT(LAYER_I18N, KC_G)
#define H_I18N          LT(LAYER_I18N, KC_H)
#define F_CTRL          LCTL_T(KC_F)
#define J_CTRL          RCTL_T(KC_J)
#define D_SHIFT         LSFT_T(KC_D)
#define K_SHIFT         RSFT_T(KC_K)
#define S_GUI           LGUI_T(KC_S)
#define L_GUI           RGUI_T(KC_L)
#define A_ALT           LALT_T(KC_A)
#define SCOLON_ALT      LALT_T(KC_SCOLON)
#define SPACE_SYMBOLS   LT(LAYER_SYMBOLS, KC_SPACE)
#define BSPACE_SYMBOLS  LT(LAYER_SYMBOLS, KC_BACKSPACE)
#define ENTER_NUMBERS   LT(LAYER_NUMBERS, KC_ENTER)
#define TAB_NUMBERS     LT(LAYER_NUMBERS, KC_TAB)
#define KC_AE           RALT(KC_Q)
#define KC_OE           RALT(KC_P)
#define KC_UE           RALT(KC_Y)
#define KC_SZ           RALT(KC_S)
#define KC_EURO         RALT(KC_5)
