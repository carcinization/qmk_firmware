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
#include <stdio.h>
#include <time.h>
#include <print.h>
#ifdef RANDICT
#include "users/ridingqwerty/dict.h"
uint16_t rand_key;
bool randword_seed = false;
bool random_word(void){
    bool rbool = rand() & 1;
    return rbool;
}
#endif
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }
uint16_t alt_tab_timer = 0;
bool is_alt_tab_active = false;
uint8_t temp_keycode;
uint16_t typing_mode;

void tap_code16_nomods(uint8_t kc) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_code16(kc);
    set_mods(temp_mod);
}

void tap_unicode_glyph(uint32_t glyph) {
    unicode_input_start();
    register_hex32(glyph);
    unicode_input_finish();
}

void tap_unicode_glyph_nomods(uint32_t glyph) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_unicode_glyph(glyph);
    set_mods(temp_mod);
}

typedef uint32_t (*translator_function_t)(bool is_shifted, uint32_t keycode);

#define DEFINE_UNICODE_RANGE_TRANSLATOR(translator_name, lower_alpha, upper_alpha, zero_glyph, number_one, space_glyph) \
    static inline uint32_t translator_name(bool is_shifted, uint32_t keycode) {                                         \
        switch (keycode) {                                                                                              \
            case KC_A ... KC_Z:                                                                                         \
                return (is_shifted ? upper_alpha : lower_alpha) + keycode - KC_A;                                       \
            case KC_0:                                                                                                  \
                return zero_glyph;                                                                                      \
            case KC_1 ... KC_9:                                                                                         \
                return (number_one + keycode - KC_1);                                                                   \
            case KC_SPACE:                                                                                              \
                return space_glyph;                                                                                     \
        }                                                                                                               \
        return keycode;                                                                                                 \
    }

#define DEFINE_UNICODE_LUT_TRANSLATOR(translator_name, ...)                     \
    static inline uint32_t translator_name(bool is_shifted, uint32_t keycode) { \
        static const uint32_t translation[] = {__VA_ARGS__};                    \
        uint32_t              ret           = keycode;                          \
        if ((keycode - KC_A) < (sizeof(translation) / sizeof(uint32_t))) {      \
            ret = translation[keycode - KC_A];                                  \
        }                                                                       \
        return ret;                                                             \
    }

bool process_record_glyph_replacement(uint16_t keycode, keyrecord_t *record, translator_function_t translator) {
    uint8_t temp_mod   = get_mods();
    uint8_t temp_osm   = get_oneshot_mods();
    bool    is_shifted = (temp_mod | temp_osm) & MOD_MASK_SHIFT;
    if (((temp_mod | temp_osm) & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI)) == 0) {
        if (KC_A <= keycode && keycode <= KC_Z) {
            if (record->event.pressed) {
                tap_unicode_glyph_nomods(translator(is_shifted, keycode));
            }
            return false;
        } else if (KC_1 <= keycode && keycode <= KC_0) {
            if (is_shifted) {
                return process_record_keymap(keycode, record);
            }
            if (record->event.pressed) {
                tap_unicode_glyph(translator(is_shifted, keycode));
            }
            return false;
        } else if (keycode == KC_SPACE) {
            if (record->event.pressed) {
                tap_unicode_glyph(translator(is_shifted, keycode));
            }
            return false;
        }
    }
    return process_record_keymap(keycode, record);
}

DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_wide, 0xFF41, 0xFF21, 0xFF10, 0xFF11, 0x2003);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_blocks, 0x1D4EA, 0x1D4D0, 0x1D7CE, 0x1D7C1, 0x2002);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_fancy, 0x1F170, 0x1F170, '0', '1', 0x2002);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_regional, 0x1F1E6, 0x1F1E6, '0', '1', 0x2003);
DEFINE_UNICODE_LUT_TRANSLATOR(unicode_lut_translator_aussie,
                              0x0250,  // a
                              'q',     // b
                              0x0254,  // c
                              'p',     // d
                              0x01DD,  // e
                              0x025F,  // f
                              0x0183,  // g
                              0x0265,  // h
                              0x1D09,  // i
                              0x027E,  // j
                              0x029E,  // k
                              'l',     // l
                              0x026F,  // m
                              'u',     // n
                              'o',     // o
                              'd',     // p
                              'b',     // q
                              0x0279,  // r
                              's',     // s
                              0x0287,  // t
                              'n',     // u
                              0x028C,  // v
                              0x028D,  // w
                              0x2717,  // x
                              0x028E,  // y
                              'z',     // z
                              0x0269,  // 1
                              0x3139,  // 2
                              0x0190,  // 3
                              0x3123,  // 4
                              0x03DB,  // 5
                              '9',     // 6
                              0x3125,  // 7
                              '8',     // 8
                              '6',     // 9
                              '0'      // 0
);

bool process_record_aussie(uint16_t keycode, keyrecord_t *record) {
    bool is_shifted = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
    if ((KC_A <= keycode) && (keycode <= KC_0)) {
        if (record->event.pressed) {
            if (!process_record_glyph_replacement(keycode, record, unicode_lut_translator_aussie)) {
                tap_code16_nomods(KC_LEFT);
                return false;
            }
        }
    } else if (record->event.pressed && keycode == KC_SPACE) {
        tap_code16_nomods(KC_SPACE);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_ENTER) {
        tap_code16_nomods(KC_END);
        tap_code16_nomods(KC_ENTER);
        return false;
    } else if (record->event.pressed && keycode == KC_HOME) {
        tap_code16_nomods(KC_END);
        return false;
    } else if (record->event.pressed && keycode == KC_END) {
        tap_code16_nomods(KC_HOME);
        return false;
    } else if (record->event.pressed && keycode == KC_BSPC) {
        tap_code16_nomods(KC_DELT);
        return false;
    } else if (record->event.pressed && keycode == KC_DELT) {
        tap_code16_nomods(KC_BSPC);
        return false;
    } else if (record->event.pressed && keycode == KC_QUOT) {
        tap_unicode_glyph_nomods(is_shifted ? 0x201E : 0x201A);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_COMMA) {
        tap_unicode_glyph_nomods(is_shifted ? '<' : 0x2018);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_DOT) {
        tap_unicode_glyph_nomods(is_shifted ? '>' : 0x02D9);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_SLASH) {
        tap_unicode_glyph_nomods(is_shifted ? 0x00BF : '/');
        tap_code16_nomods(KC_LEFT);
        return false;
    }
    return process_record_keymap(keycode, record);
}

bool process_record_zalgo(uint16_t keycode, keyrecord_t *record) {
    if ((KC_A <= keycode) && (keycode <= KC_0)) {
        if (record->event.pressed) {
            tap_code16_nomods(keycode);

            int number = (rand() % (8 + 1 - 2)) + 2;
            for (int index = 0; index < number; index++) {
                uint16_t hex = (rand() % (0x036F + 1 - 0x0300)) + 0x0300;
                tap_unicode_glyph(hex);
            }

            return false;
        }
    }
    return process_record_keymap(keycode, record);
}

bool no_mods = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    process_record_user_oled(keycode, record);
#endif
#ifdef UNICODEMAP_ENABLE
    temp_keycode = keycode;
    if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) { temp_keycode &= 0xFF; }
#endif
    switch (keycode) {
        case CP_PSTE:
            if (record->event.pressed) { tap_code16(C(KC_C)); } else { tap_code16(C(KC_V)); }
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
        case KC_NOMODE ... KC_ZALGO:
            if (record->event.pressed) { typing_mode = keycode - KC_REGIONAL; }
            return true;
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
#elif defined(BOOTLOADER_HALFKAY)
                        ":teensy"
#elif defined(BOOLOADER_CATERINA)
                        ":avrdude"
#elif defined(BOOTLOADER_USBASP)
                        ":usbasp"
#endif
                        SS_TAP(X_ENTER));
            }
            return false;
            break;
    }
    if (typing_mode) {
        if (((KC_A <= temp_keycode) && (temp_keycode <= KC_0)) || temp_keycode == KC_SPACE) {
            if (typing_mode == TM_WIDE) { return process_record_glyph_replacement(temp_keycode, record, unicode_range_translator_wide); }
            if (typing_mode == TM_BLOCKS) { return process_record_glyph_replacement(temp_keycode, record, unicode_range_translator_blocks); }
            if (typing_mode == TM_FANCY) { return process_record_glyph_replacement(temp_keycode, record, unicode_range_translator_fancy); }
            if (typing_mode == TM_REGIONAL) { return process_record_glyph_replacement(temp_keycode, record, unicode_range_translator_regional); }
        } else {
            if (typing_mode == TM_AUSSIE) { return process_record_aussie(temp_keycode, record); }
            if (typing_mode == TM_ZALGO) { return process_record_zalgo(temp_keycode, record); }
        }
    }
    return true;
    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
