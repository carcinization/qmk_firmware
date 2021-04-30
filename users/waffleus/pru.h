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

#pragma once
#include "waffleus.h"
bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

enum userspace_custom_keycodes {
    CP_PSTE = SAFE_RANGE,
    MAC_PSTE,
    ROFL,
#ifdef UNICODEMAP_ENABLE
    UNIT,
    UNIT2,
    TABLE1,
    TABLE2,
    LENNY,
    DANCE,
#endif
#ifdef RGBLIGHT_ENABLE
    RGBRST,
#endif
#ifdef RANDICT
    RWORD,
#endif
    ALT_TAB,
    MAKE,
    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    KC_SECRET_4,
    KC_SECRET_5
};
