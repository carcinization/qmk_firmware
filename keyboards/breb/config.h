/* Copyright 2020 @wafflekeebs/@waffle#6666
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define VENDOR_ID       0xF108
#define PRODUCT_ID      0x9472
#define DEVICE_VER      0x0001
#define MANUFACTURER    Waffle
#define PRODUCT         Brebborb

#define MATRIX_ROWS 1
#define MATRIX_COLS 1
#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 5
#define MATRIX_COL_PINS { A9 }
#define MATRIX_ROW_PINS { A11 }

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_ANIMATIONS
#define RGB_DI_PIN A4
#define RGBLED_NUM 16
#define RGBLIGHT_LIMIT_VAL 128
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
#endif

#ifdef OLED_DRIVER_ENABLE
#define OLED_DISPLAY_128X32
#define OLED_TIMEOUT 0
#endif

#ifdef ENCODER_ENABLE
#define TAP_CODE_DELAY 5
#define ENCODERS_PAD_A { A0 }
#define ENCODERS_PAD_B { A1 }
#endif

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
