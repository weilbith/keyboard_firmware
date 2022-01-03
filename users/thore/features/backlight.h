#pragma once

typedef struct {
  uint8_t hue;
  uint8_t saturation;
  uint8_t value;
} backlight_hsv_color_t;

extern backlight_hsv_color_t backlight_modifier_colors[];
extern backlight_hsv_color_t backlight_layer_colors[];

void backlight_apply_for_modifier_and_layer(void);
