/* Copyright 2020 @wafflekeebs/@waffle#6666
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

#include QMK_KEYBOARD_H
bool show_img = false;

#ifdef TAP_DANCE_ENABLE
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD
};

enum {
    CAP_CTL
};

uint8_t cur_dance(qk_tap_dance_state_t *state);
void cap_finished(qk_tap_dance_state_t *state, void *user_data);
void cap_reset(qk_tap_dance_state_t *state, void *user_data);
#endif

enum custom_keycodes {
    BREAD = SAFE_RANGE,
    RTEST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT_smol(
     TD(CAP_CTL)
 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BREAD:
            if (record->event.pressed) {
                SEND_STRING("Hello This Is A One Key Keyboard I built");
            }
            break;

        case RTEST:
            if (record->event.pressed) {
                show_img ^= 1;
            }
            break;
    }
    return true;
};

#include "oled.c"

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
#endif

#ifdef TAP_DANCE_ENABLE
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

static tap captap_state = {
    .is_press_action = true,
    .state = 0
};

void cap_finished(qk_tap_dance_state_t *state, void *user_data) {
    captap_state.state = cur_dance(state);
    switch (captap_state.state) {
        case SINGLE_TAP: register_code(KC_LGUI); break;
        case SINGLE_HOLD: register_code(KC_LCTRL); break;
        case DOUBLE_TAP: register_code(KC_LSHIFT); break;
        case DOUBLE_HOLD: register_code(KC_LALT); break;
        case DOUBLE_SINGLE_TAP: tap_code(KC_F); register_code(KC_F);
    }
}

void cap_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (captap_state.state) {
        case SINGLE_TAP: unregister_code(KC_LGUI); break;
        case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
        case DOUBLE_TAP: unregister_code(KC_LSHIFT); break;
        case DOUBLE_HOLD: unregister_code(KC_LALT);
        case DOUBLE_SINGLE_TAP: unregister_code(KC_F);
    }
    captap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [CAP_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cap_finished, cap_reset)
};
#endif
