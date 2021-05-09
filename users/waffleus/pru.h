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
    SHRUG,
#endif
#ifdef RGBLIGHT_ENABLE
    RGBRST,
#endif
#ifdef RANDICT
    RWORD,
#endif
#ifdef SECRETS
    SECRET1,
    SECRET2,
    SECRET3,
    SECRET4,
    SECRET5,
#endif
    ALT_TAB,
    MAKE
};
