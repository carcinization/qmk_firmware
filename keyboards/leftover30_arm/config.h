/*
 * Copyright 2020 TJ Campie @tominabox1
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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x7431
#define PRODUCT_ID 0x4C4F
#define DEVICE_VER 0x0001
#define MANUFACTURER tominabox1
#define PRODUCT Leftover30 ARM Edition

#undef MATRIX_ROWS
#undef MATRIX_COLS
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 11

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
/* Note: These are not used for arm boards. They're here purely as documentation. */
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

#define MATRIX_ROW_PINS { B3, B4, C13, A5 }
#define MATRIX_COL_PINS { A15, B9, B8, B7, B6, B5, C14, C15, F1, F0, A1 }

#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { B12, A7 } // Left, Right
#define ENCODERS_PAD_B { B14, B0 } // Left, Right

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
// #define DEBOUNCE 6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/*
 * WS2812 Underglow Matrix options
 */
#define RGB_DI_PIN B15
#define RGBLED_NUM 8 // Change to 8 if utilizing the space bar LEDs
#define RGBLIGHT_LED_MAP { 0, 1,  3, 4, 5, 6, 2, 7 }

#define DRIVER_LED_TOTAL RGBLED_NUM

#define WS2812_SPI SPID2 // default: SPID1
#define WS2812_SPI_MOSI_PAL_MODE 0 // Pin "alternate func
#define WS2812_EXTERNAL_PULLUP
#define RGBLIGHT_ANIMATIONS

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10
#endif

#ifdef COMBO_ENABLE
#   define COMBO_COUNT 8
#   define COMBO_TERM 50
#endif

#ifdef AUTOSHIFT_ENABLE
#define AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_TIMEOUT 170
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC
#endif

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 150

#define TAP_CODE_DELAY 10
#define RGBLIGHT_SLEEP
