#pragma once
#include "config_common.h"
#undef VENDOR_ID
#define VENDOR_ID 0x2847
#undef PRODUCT_ID
#define PRODUCT_ID 0xACC8
#undef MANUFACTURER
#define MANUFACTURER Waffle
#undef PRODUCT
#define PRODUCT Uno V2
#define MATRIX_ROWS 1
#define MATRIX_COLS 1
#undef DIRECT_PINS
#define DIRECT_PINS { \
    { D0 } \
}
#define UNUSED_PINS
#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B3 }
#define ENCODER_RESOLUTION 4
#ifdef RGBLIGHT_ENABLE
#undef RGB_DI_PIN
#define RGB_DI_PIN D1
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 32
#define RGBLIGHT_SAT_STEP 32
#define RGBLIGHT_VAL_STEP 32
#endif
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
