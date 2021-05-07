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
#include QMK_KEYBOARD_H
#include "wrappers.h"
#include "tapdance.h"
#include "combos.h"
#include "pru.h"
#ifdef RGBLIGHT_ENABLE
#include "rgb.h"
#endif
#ifdef OLED_DRIVER_ENABLE
#include "oled.h"
#endif

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#ifdef UNICODEMAP_ENABLE
enum unicodemap_names {
    SIDE,
    UPAR,
    HAS,
    STAR,
    VIB
};
#endif

//---layers---
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define TGADJ TG(_ADJUST)
#define LWRSPC LT(_LOWER, KC_SPC)
//---general---
#define SFA SFT_T(KC_A)
#define SFCLN RSFT_T(KC_SCLN)
#define SFL SFT_T(KC_L)
#define SFEXM MT(MOD_LSFT, KC_F23)
#define SFPRN MT(MOD_RSFT, KC_F24)
#define ALTQ ALT_T(KC_Q)
#define ALTP ALT_T(KC_P)
//---linux/windows---
#define GPSCR G(KC_PSCR)
#define CTLZ CTL_T(KC_Z)
#define CTLESC CTL_T(KC_ESC)
#define CTLSLH CTL_T(KC_SLSH)
#define CTLDOT CTL_T(KC_DOT)
#define CTLRGHT CTL_T(KC_RIGHT)
#define CLIPST C(S(KC_V))
//---mac---
#define MPSCR G(S(KC_4))
#define MACTAB G(KC_TAB)
#define CMDZ CMD_T(KC_Z)
#define CMDESC CMD_T(KC_ESC)
#define CMDSLSH CMD_T(KC_SLSH)
#define CMDRGHT CMD_T(KC_RIGHT)
#define CMDOT CMD_T(KC_DOT)
//---tap dance---
#define HAPSAD TD(HAP_SAD)
#define DOCSTD TD(DOCS)
#define QMKTD TD(QMK)
#define MSLGTD TD(MSLGUI)
#define GCPTD TD(GCLIPST)
//---unicode---
#define HAP X(SIDE)
#define ARWUP X(UPAR)
#define STARX X(STAR)
