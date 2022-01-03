SRC += thore.c

ifeq ($(strip $(USER_DANCING_BRACKETS_ENABLE)), yes)
	TAP_DANCE_ENABLE = yes
	SRC += features/dancing_brackets.c
  OPT_DEFS += -DUSER_DANCING_BRACKETS_ENABLE
endif

ifeq ($(strip $(USER_BACKLIGHT_ENABLE)), yes)
	RGBLIGHT_ENABLE = yes
	SRC += features/backlight.c
  OPT_DEFS += -DUSER_BACKLIGHT_ENABLE
endif
