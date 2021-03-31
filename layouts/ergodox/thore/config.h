#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD

// In progress to find the optimium. Starting high...
#undef TAPPING_TERM
#define TAPPING_TERM 300
#define TAPPING_TERM_DANCING_BRACKETS 175
#define TAPPING_TERM_PER_KEY

#undef DEBOUNCE
#define DEBOUNCE 2

// Make sure that some options are not disabled by the keyboard configuration.
#undef NO_ACTION_LAYER
#undef NO_ACTION_TAPPING
#undef NO_ACTION_ONESHOT
