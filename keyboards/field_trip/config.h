/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xADAD
#define PRODUCT_ID      0x4654 /* "FT" */
#define DEVICE_VER      0x0001
#define MANUFACTURER AeternusDecorum
#define PRODUCT Field Trip
#define DESCRIPTION Field Trip Keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

#define MATRIX_ROW_PINS { B2, B10, B11, A3, A4 }
#define MATRIX_COL_PINS { A15, B3, B4, B5, B6, B7, B8, B9, C14, C15, F0, F1, A0, A1, A2 }

#define DIODE_DIRECTION COL2ROW

#define RGBLIGHT_ANIMATIONS
#define RGB_DI_PIN B15
#define RGBLED_NUM 26

#define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 }
// #define RGBLIGHT_LED_MAP { 0, 25, 24, 1, 2, 23, 22, 3, 4, 21, 20, 5, 6, 19, 18, 7, 8, 17, 16, 9, 10, 15, 14, 11, 12, 13 }

/*
#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_PAL_MODE 1

#define I2C1_TIMINGR_PRESC  0U
#define I2C1_TIMINGR_SCLDEL 3U
#define I2C1_TIMINGR_SDADEL 1U
#define I2C1_TIMINGR_SCLH   3U
#define I2C1_TIMINGR_SCLL   9U
*/
#define WS2812_EXTERNAL_PULLUP


// TODO: Enable this once LEDs are on SPI pin
#define WS2812_SPI SPID2
#define WS2812_SPI_MOSI_PAL_MODE 0


#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
