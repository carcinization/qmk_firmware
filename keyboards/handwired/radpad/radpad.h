#pragma once
#include "quantum.h"
#define LAYOUT_kc( \
    k00, k01, k02, k03, k04, \
    k10, k11, k12, k13, k14, \
    k20, k21, k22, k23, k24, \
    k30, k31, k32, k33, k34  \
) \
{ \
    { KC_##k00, KC_##k01, KC_##k02, KC_##k03, KC_##k04 }, \
    { KC_##k10, KC_##k11, KC_##k12, KC_##k13, KC_##k14 }, \
    { RGB_##k20, RGB_##k21, RGB_##k22, RGB_##k23, RGB_##k24 }, \
    { RGB_##k30, RGB_##k31, RGB_##k32, RGB_##k33, RGB_##k34 }, \
}
