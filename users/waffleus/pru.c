/* Copyright 2021 @Itswaffle/@waffle#6666
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
#include "pru.h"
#include <stdio.h>

uint16_t alt_tab_timer = 0;
bool is_alt_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    process_record_user_oled(keycode, record);
#endif
    switch (keycode) {
        case CP_PSTE:
            if (record->event.pressed) {
                tap_code16(C(KC_C));
            } else {
                tap_code16(C(KC_V));
            }
            return false;

        case MT(MOD_LSFT, KC_F23):
            if (record->tap.count > 0) {
            if (record->event.pressed) {
                register_code16(KC_EXLM);
            } else {
                unregister_code16(KC_EXLM);
            }
            return false;
            }
            break;

        case MT(MOD_RSFT, KC_F24):
            if (record->tap.count > 0) {
            if (record->event.pressed) {
                register_code16(KC_RPRN);
            } else {
                unregister_code16(KC_RPRN);
            }
            return false;
            }
            break;
#ifdef UNICODEMAP_ENABLE
        case UNIT:
            if (record->event.pressed) {
                send_unicode_string("(＾▽＾)");
            } else {
            }
            break;

        case UNIT2:
            if (record->event.pressed) {
                send_unicode_string("≧ω≦");
            } else {
            }
            break;

        case UNIT3:
            if (record->event.pressed) {
            send_unicode_string("(╯°□°）╯︵ ┻━┻");
            } else {
            }
            break;

        case UNIT4:
            if (record->event.pressed) {
                send_unicode_string("┬──┬ ノ( ゜-゜ノ)");
            } else {
            }
            break;
#endif
#ifdef RGBLIGHT_ENABLE
        case RGBRST:
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
            break;
#endif
        case ALT_TAB:
            if (record->event.pressed) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;

        case MAKE:
            if (!record->event.pressed) {
                SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP
#if (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
                        ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
                        ":teensy"
#elif defined(BOOLOADER_CATERINA)
                        ":avrdude"
#elif defined(BOOTLOADER_USBASP)
                        ":usbasp"
#endif
                        SS_TAP(X_ENTER)SS_DELAY(500));
                        reset_keyboard();
            }
            return false;
            break;

    }
    return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
