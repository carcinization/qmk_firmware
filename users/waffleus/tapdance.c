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

#include "tapdance.h"

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8;
}

static tap msgui_tap_state = {
    .is_press_action = true,
    .state = 0
};

void mslgui_finished(qk_tap_dance_state_t *state, void *user_data) {
    msgui_tap_state.state = cur_dance(state);
    switch (msgui_tap_state.state) {
        case SINGLE_TAP: register_code(KC_LGUI); break;
        case SINGLE_HOLD: register_code16(KC_MS_L); break;
        case DOUBLE_TAP: register_code(KC_LGUI); break;
        case DOUBLE_HOLD: register_code16(KC_MS_L); break;
        case DOUBLE_SINGLE_TAP: tap_code(KC_LGUI); register_code(KC_LGUI);
    }
}

void mslgui_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (msgui_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_LGUI); break;
        case SINGLE_HOLD: unregister_code16(KC_MS_L); break;
        case DOUBLE_TAP: unregister_code(KC_LGUI); break;
        case DOUBLE_HOLD: unregister_code16(KC_MS_L);
        case DOUBLE_SINGLE_TAP: unregister_code(KC_LGUI);
    }
    msgui_tap_state.state = 0;
}

void dance_pep_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING(":widepeepohappy1::widepeepohappy2::widepeepohappy3::widepeepohappy4:"SS_TAP(X_ENTER));
    } else {
      SEND_STRING(":widepeeposad1::widepeeposad2:"SS_TAP(X_ENTER));
    }
}

void dance_qmk_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("https://github.com/qmk/qmk_firmware/find/master"SS_TAP(X_ENTER));
    } else {
      SEND_STRING("https://config.qmk.fm/#/"SS_TAP(X_ENTER));
    }
}

void dance_doc_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("<https://docs.qmk.fm/#/newbs_getting_started>");
    } else {
      SEND_STRING("<https://docs.qmk.fm/#/driver_installation_zadig>");
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [HAP_SAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_pep_finished, NULL),
    [QMK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_qmk_finished, NULL),
    [DOCS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_doc_finished, NULL),
    [MSLGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mslgui_finished, mslgui_reset),
};
