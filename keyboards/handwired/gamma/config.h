#pragma once
#include "config_common.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    RYKB
#define PRODUCT         Matcha59
#define MATRIX_ROWS 5
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { F0, F1, C7, D5, B7 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, B6, B5, B4, E6, D7 }
#define DIODE_DIRECTION COL2ROW
#define ENCODERS_PAD_A { D2 }
#define ENCODERS_PAD_B { D3 }
