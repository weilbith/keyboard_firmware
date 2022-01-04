#define LAYOUT_ergodox_34_keys( \
  k00, k01, k02, k03, k04, \
  k10, k11, k12, k13, k14, \
  k20, k21, k22, k23,      \
            k28, k29, k30, \
                           \
  k05, k06, k07, k08, k09, \
  k15, k16, k17, k18, k19, \
       k24, k25, k26, k27, \
  k31, k32, k33            \
) { \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, k00,   k10,   k20,   KC_NO, KC_NO }, \
    { KC_NO, k01,   k11,   k21,   KC_NO, k30   }, \
    { KC_NO, k02,   k12,   k22,   KC_NO, k29   }, \
    { KC_NO, k03,   k13,   k23,   k28,   KC_NO }, \
    { KC_NO, k04,   k14,   KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
                                                  \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, k05,   k15,   KC_NO, KC_NO, KC_NO }, \
    { KC_NO, k06,   k16,   k24,   k33,   KC_NO }, \
    { KC_NO, k07,   k17,   k25,   KC_NO, k32   }, \
    { KC_NO, k08,   k18,   k26,   KC_NO, k31   }, \
    { KC_NO, k09,   k19,   k27,   KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
  }

#define LAYOUT_ergodox_34_keys_left_hand( \
  k00, k01, k02, k03, k04, \
  k10, k11, k12, k13, k14, \
  k20, k21, k22, k23,      \
            k28, k29, k30  \
) \
  LAYOUT_ergodox_34_keys( \
    k00,            k01,            k02,            k03,            k04,            \
    k10,            k11,            k12,            k13,            k14,            \
    k20,            k21,            k22,            k23,                            \
                                    k28,            k29,            k30,            \
                                                                                    \
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, \
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, \
                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, \
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                  \
  )

#define LAYOUT_ergodox_34_keys_right_hand( \
  k05, k06, k07, k08, k09, \
  k15, k16, k17, k18, k19, \
       k24, k25, k26, k27, \
  k31, k32, k33            \
) \
  LAYOUT_ergodox_34_keys( \
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, \
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, \
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 \
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, \
                                                                                    \
    k05,            k06,            k07,            k08,            k09,            \
    k15,            k16,            k17,            k18,            k19,            \
                    k24,            k25,            k26,            k27,            \
    k31,            k32,            k33                                             \
  )
