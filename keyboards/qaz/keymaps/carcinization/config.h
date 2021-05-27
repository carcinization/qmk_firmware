#pragma once

#ifdef COMBO_ENABLE
#    define COMBO_COUNT 3
#    define COMBO_TERM 200
#endif

#define TAPPING_TOGGLE 3

#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 8
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif