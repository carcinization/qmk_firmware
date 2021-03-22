#pragma once
#include "config_common.h"
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xC456
#define DEVICE_VER      0x0001
#define MANUFACTURER    MisonoWorks
#define PRODUCT         Chocolate Bar
#define DESCRIPTION     An 1800-styled Choc Keyboard
#define MATRIX_ROWS 4
#define MATRIX_COLS 16
#define MATRIX_ROW_PINS { D0, D1, D2, D3 }
#define MATRIX_COL_PINS { F0, F1, F4, F5, F6, F7, C7, C6, B6, B5, B4, D7, D6, D4, B3, B2 }
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif
#define DEBOUNCE 5
#define FORCE_NKRO
#define MK_3_SPEED
#define TERMINAL_HELP
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
#define RGB_DI_PIN B1
#ifdef RGB_DI_PIN
#define RGBLED_NUM 12
#define RGBLIGHT_ANIMATIONS
#endif
