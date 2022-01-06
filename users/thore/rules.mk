SRC += thore.c features/key_utilities.c

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

ifeq ($(strip $(USER_CAPS_WORD_ENABLE)), yes)
	SRC += features/caps_word.c
  OPT_DEFS += -DUSER_CAPS_WORD_ENABLE
endif

ifeq ($(strip $(USER_DOUBLE_SPACE_SENTENCE_ENABLE)), yes)
	SRC += features/double_space_sentence.c
  OPT_DEFS += -DUSER_DOUBLE_SPACE_SENTENCE_ENABLE
endif
