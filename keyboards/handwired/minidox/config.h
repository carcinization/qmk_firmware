#pragma once
#include "config_common.h"

#define VENDOR_ID       0x9237
#define PRODUCT_ID      0x1972
#define DEVICE_VER      0x0000
#define MANUFACTURER    Waffle Inc.
#define PRODUCT         Minidox

#define MATRIX_ROWS 8
#define MATRIX_COLS 5
#define MATRIX_ROW_PINS { B2, B6, B4, B5 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1 }
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2
#define RGB_DI_PIN D7
#define DIODE_DIRECTION COL2ROW
#define USB_POLLING_INTERVAL_MS 1
#define DEBOUNCE 5
#define LOCKING_RESYNC_ENABLE
#define USB_MAX_POWER_CONSUMPTION 500
#define FORCE_NKRO
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LAYERS
#define RGBLED_NUM 30
#define RGBLED_SPLIT { 15, 15 }
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10
#endif
#define EE_HANDS
