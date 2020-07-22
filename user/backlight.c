#include QMK_KEYBOARD_H
#include "backlight.h"


#define is_backlight_hsv_color_null(color) (color.hue + color.saturation + color.value) <= 0

backlight_hsv_color_t last_color;

void backlight_apply_for_modifier_and_layer(void) {
  uint8_t layer = biton32(layer_state);
  backlight_hsv_color_t layer_color = backlight_layer_colors[layer];
  backlight_hsv_color_t modifier_color = backlight_modifier_colors[keyboard_report->mods];
  backlight_hsv_color_t final_color; // Defaults to no color/off.

  // Modifiers take preference over layer, since they are "included" in a layer.
  if (is_backlight_hsv_color_null(modifier_color)) {
    final_color = layer_color;
  } else {
    final_color = modifier_color;
  }

  // Avoid flickering by resetting the color.
  if (final_color != last_color) {
    rgblight_sethsv_noeeprom(final_color.hue, final_color.saturation, final_color.value);
    rgblight_mode_noeeprom(0);
    rgblight_enable_noeeprom();
    last_color = final_color;
  }
};
