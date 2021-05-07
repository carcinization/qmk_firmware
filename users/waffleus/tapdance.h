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
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum tapdance_types {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD
};

enum custom_tapdances {
    MSLGUI,
    GCLIPST,
    HAP_SAD,
    QMK,
    DOCS,
};

uint8_t cur_dance(qk_tap_dance_state_t *state);
void msgui_finished(qk_tap_dance_state_t *state, void *user_data);
void msgui_reset(qk_tap_dance_state_t *state, void *user_data);
void gclipst_finished(qk_tap_dance_state_t *state, void *user_data);
void gclipst_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_pep_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_qmk_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_doc_finished(qk_tap_dance_state_t *state, void *user_data);
