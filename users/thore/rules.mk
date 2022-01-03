ifeq ($(strip $(USER_DANCING_BRACKETS_ENABLE)), yes)
	TAP_DANCE_ENABLE = yes
	SRC += features/dancing_brackets.c
  OPT_DEFS += -DUSER_DANCING_BRACKETS_ENABLE
endif
