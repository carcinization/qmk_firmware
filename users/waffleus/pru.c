/* Copyright 2021 @waffle#6666
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

#include "waffleus.h"
#ifdef RANDICT
#include "users/ridingqwerty/dict.h"
uint16_t rand_key;
bool randword_seed = false;
bool random_word(void){
    bool rbool = rand() & 1;
    return rbool;
}
#endif
uint16_t alt_tab_timer = 0;
bool is_alt_tab_active = false;

#ifdef SECRETS
__attribute__ ((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
__attribute__ ((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    process_record_user_oled(keycode, record);
#endif
    switch (keycode) {
        case CP_PSTE:
            if (record->event.pressed) { tap_code16(C(KC_C)); } else {
                tap_code16(C(KC_V));
                tap_code(KC_ENT); }
            return false;

        case MAC_PSTE:
            if (record->event.pressed) { tap_code16(G(KC_C)); } else { tap_code16(G(KC_V)); }
            return false;

        case ROFL:
            if (record->event.pressed) {
                SEND_STRING("```Incoming ROFLCOPTER!\n"
                            "\n   ROFL:ROFL:ROFL:ROFL\n"
                            "         ___^___ _\n"
                            " L    __/      []  \\ \n"
                            "LOL===__            \\ \n"
                            " L      \\___ ___ ___ ]\n"
                            "           I   I\n"
                            "         ----------/```"SS_TAP(X_ENT));
            }
            break;

        case MT(MOD_LSFT, KC_F23):
            if (record->tap.count > 0) {
            if (record->event.pressed) { register_code16(KC_EXLM); } else { unregister_code16(KC_EXLM); }
            return false;
            }
            break;

        case MT(MOD_RSFT, KC_F24):
            if (record->tap.count > 0) {
            if (record->event.pressed) { register_code16(KC_RPRN); } else { unregister_code16(KC_RPRN); }
            return false;
            }
            break;
#ifdef UNICODEMAP_ENABLE
        case UNIT:
            if (record->event.pressed) { send_unicode_string("(＾▽＾)"); } break;
        case UNIT2:
            if (record->event.pressed) { send_unicode_string("≧ω≦"); } break;
        case TABLE1: // ┬──┬ ノ( ゜-゜ノ)
            if (record->event.pressed) { send_unicode_hex_string("252C 2500 2500 252C 0020 30CE 0028 0020 309C 002D 309C 30CE 0029"); } break;
        case TABLE2: // (╯°□°)╯︵┻━┻
            if (record->event.pressed) { send_unicode_hex_string("0028 256F 00b0 25A1 00B0 0029 256F FE35 253B 2501 253B"); } break;
        case LENNY: // ( ͡° ͜ʖ ͡°)
            if (record->event.pressed) { send_unicode_hex_string("0028 0020 0361 00B0 0020 035C 0296 0020 0361 00b0 0029"); } break;
        case DANCE: // ༼ つ ◕_◕ ༽つ
            if (record->event.pressed) { send_unicode_hex_string("0F3C 0020 3064 0020 25D5 005F 25D5 0020 0F3D 3064"); } break;
        case SHRUG: //¯\_(ツ)_/¯
            if (record->event.pressed) { send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF"); } break;
#endif
#ifdef RGBLIGHT_ENABLE
        case RGBRST:
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
            break;
#endif
#ifdef RANDICT
        case RWORD:
            if (randword_seed == false) {
                randword_seed = true;
                srand(timer_read32());
            }
            rand_key = rand() % NUMBER_OF_WORDS;
            if (record->event.pressed) {
                send_string(dict[rand_key]);
                tap_code(KC_SPC);
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
#elif defined(BOOLOADER_CATERINA)
                        ":avrdude"
#elif (defined(MCU_STM32F072) || defined(MCU_STM32F303) || defined(MCU_STM32F103))
                        ":dfu-util"
#endif
                        SS_TAP(X_ENTER));
            }
            return false;
            break;
    }
    return true;
#ifdef SECRETS
    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
#endif
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
