/*
Copyright 2020 MisonoWorks

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

#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "combos.h"
#include "tapdance.c"
#include "extras.c"
#include "macros.h"
#ifdef UNICODEMAP_ENABLE
#include "unicodes.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_big_space(
    KC_MPLY, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
    ALT_TAB, SFA,  KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, SFL, KC_BSPC,
    QMKTD,     CTLTZ, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, CTLDOT, WEEB, //<-- encoder
    HAPSAD,    KC_LGUI,           LWRSPC,                                  RAISE
  ),

  [_LOWER] = LAYOUT_big_space(
    UC_M_MA, KC_1,   KC_2,   KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    NKINV,   SFEXM,  KC_AT,  KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, SFPRN,
    MMAP,    CTLESC, KC_TAB, KC_CAPS, KC_TILD, KC_GRV,  KC_LEFT, KC_UP,   KC_DOWN, CTLRGHT, UC_M_WC,
    VIA,     KC_LGUI,                 _______,                                              KC_SLSH
  ),

  [_RAISE] = LAYOUT_big_space(
    MAKE, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, CG_NORM, CG_SWAP,  KC_BLOCKS, KC_SCRIPT, KC_NOMODE,
    _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_ASON, KC_ASOFF, KC_AUSSIE, KC_WIDE, KC_REGIONAL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   UNIT,    UNIT2,    UNIT3,     UNIT4,   KC_MSTP,
    _______, RESET,                     KC_SCLN,                                                  _______
  )
};
