#pragma once

#include "config_common.h"
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER Arcana
#define PRODUCT      arc8
#define MATRIX_ROWS 2
#define MATRIX_COLS 4
#define MATRIX_ROW_PINS { F6, B6 }
#define MATRIX_COL_PINS { F5, F4, D2, D3 }
#define UNUSED_PINS
#define ENCODERS_PAD_A { B1, F7 }
#define ENCODERS_PAD_B { B2, B3 }
#define DIODE_DIRECTION COL2ROW
