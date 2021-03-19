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
#include <print.h>
#include "i2c_master.h"
#include "quantum.h"
#include "pointing_device.h"
#include "oled.c"
bool show_img = false;
static bool bsdel_mods = false;
static bool flipeql_mods = false;
uint16_t bc = KC_BSPC;
uint16_t pc = KC_PLUS;

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
    FLIPEQL,
    BSDEL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT_smol(
     TG(1), KC_CAPS, KC_A
 ),
 [1] = LAYOUT_smol(
     TG(1), KC_A, KC_B
 ),
 [2] = LAYOUT_smol(
     RGB_TOG, TG(2), RGB_RMOD
 ),
 [3] = LAYOUT_smol(
     KC_1, KC_3, TG(3)
 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %b, time: %5u, int: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    process_record_user_oled(keycode, record);
    switch (keycode) {
#ifdef BONGO_LAYERS
        default:
            anim_sleep = timer_read32();
            return true;
#endif
        case RTEST:
            if (record->event.pressed) {
                show_img ^= 1;
            }
            break;

        case BSDEL:
            if (record->event.pressed) {
                if (keyboard_report->mods) {
                    bc = KC_DEL;
                }
                register_code(bc);
                bsdel_mods = keyboard_report->mods;
            }
            else {
                if (bsdel_mods) {
                    bc = KC_DEL;
                }
                unregister_code(bc);
            }

        case FLIPEQL:
            if (record->event.pressed) {
                if (keyboard_report->mods) {
                    pc = KC_EQL;
                }
                register_code(pc);
                flipeql_mods = keyboard_report->mods;
            } else {
                if (flipeql_mods) {
                    pc = KC_EQL;
                }
                unregister_code(pc);
            }

    }
    return true;
};


#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(C(S(KC_TAB)));
        } else {
            tap_code16(C(KC_TAB));
        }
    } else if (index == 1) {
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
        case SINGLE_TAP: register_code(KC_CAPS); break;
        case SINGLE_HOLD: register_code(KC_LCTRL); break;
        case DOUBLE_TAP: register_code(KC_LSHIFT); break;
        case DOUBLE_HOLD: register_code(KC_LALT); break;
        case DOUBLE_SINGLE_TAP: tap_code(KC_F); register_code(KC_F);
    }
}

void cap_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (captap_state.state) {
        case SINGLE_TAP: unregister_code(KC_CAPS); break;
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

#ifdef POINTING_DEVICE_ENABLE
static uint8_t scrolling      = 0;
static int16_t x_offset       = 0;
static int16_t y_offset       = 0;
static int16_t h_offset       = 0;
static int16_t v_offset       = 0;
static float   precisionSpeed = 1;

#ifndef I2C_TIMEOUT
#    define I2C_TIMEOUT 100
#endif
#ifndef MOUSE_DEBOUNCE
#    define MOUSE_DEBOUNCE 5
#endif

void trackball_set_rgbw(uint8_t red, uint8_t green, uint8_t blue, uint8_t white) {
    uint8_t data[] = {0x00, red, green, blue, white};
    i2c_transmit(TRACKBALL_WRITE, data, sizeof(data), I2C_TIMEOUT);
}

int16_t mouse_offset(uint8_t positive, uint8_t negative, int16_t scale) {
    int16_t offset    = (int16_t)positive - (int16_t)negative;
    int16_t magnitude = (int16_t)(scale * offset * offset * precisionSpeed);
    return offset < 0 ? -magnitude : magnitude;
}

void update_member(int8_t* member, int16_t* offset) {
    if (*offset > 127) {
        *member = 127;
        *offset -= 127;
    } else if (*offset < -127) {
        *member = -127;
        *offset += 127;
    } else {
        *member = *offset;
        *offset = 0;
    }
}

__attribute__((weak)) void trackball_check_click(bool pressed, report_mouse_t* mouse) {
    if (pressed) {
        mouse->buttons |= MOUSE_BTN1;
    } else {
        mouse->buttons &= ~MOUSE_BTN1;
    }
}

void trackball_register_button(bool pressed, enum mouse_buttons button) {
    report_mouse_t currentReport = pointing_device_get_report();
    if (pressed) {
        currentReport.buttons |= button;
    } else {
        currentReport.buttons &= ~button;
    }
    pointing_device_set_report(currentReport);
}

float trackball_get_precision(void) { return precisionSpeed; }
void  trackball_set_precision(float precision) { precisionSpeed = precision; }
bool  trackball_is_scrolling(void) { return scrolling; }
void  trackball_set_scrolling(bool scroll) { scrolling = scroll; }

bool has_report_changed (report_mouse_t first, report_mouse_t second) {
    return !(
        (!first.buttons && first.buttons == second.buttons) &&
        (!first.x && first.x == second.x) &&
        (!first.y && first.y == second.y) &&
        (!first.h && first.h == second.h) &&
        (!first.v && first.v == second.v) );
}


__attribute__((weak)) void pointing_device_init(void) { trackball_set_rgbw(0x00, 0x00, 0x00, 0x4F); }

void pointing_device_task(void) {
    static bool     debounce;
    static uint16_t debounce_timer;
    uint8_t         state[5] = {};
    if (i2c_readReg(TRACKBALL_WRITE, 0x04, state, 5, I2C_TIMEOUT) == I2C_STATUS_SUCCESS) {
        if (!state[4] && !debounce) {
            if (scrolling) {
#ifdef PIMORONI_TRACKBALL_INVERT_X
                h_offset += mouse_offset(state[2], state[3], 1);
#else
                h_offset -= mouse_offset(state[2], state[3], 1);
#endif
#ifdef PIMORONI_TRACKBALL_INVERT_Y
                v_offset += mouse_offset(state[1], state[0], 1);
#else
                v_offset -= mouse_offset(state[1], state[0], 1);
#endif
            } else {
#ifdef PIMORONI_TRACKBALL_INVERT_X
                x_offset -= mouse_offset(state[2], state[3], 5);
#else
                x_offset += mouse_offset(state[2], state[3], 5);
#endif
#ifdef PIMORONI_TRACKBALL_INVERT_Y
                y_offset -= mouse_offset(state[1], state[0], 5);
#else
                y_offset += mouse_offset(state[1], state[0], 5);
#endif
            }
        } else {
            if (state[4]) {
                debounce       = true;
                debounce_timer = timer_read();
            }
        }
    }

    if (timer_elapsed(debounce_timer) > MOUSE_DEBOUNCE) debounce = false;

    report_mouse_t mouse = pointing_device_get_report();

    trackball_check_click(state[4] & (1 << 7), &mouse);

#ifndef PIMORONI_TRACKBALL_ROTATE
    update_member(&mouse.x, &x_offset);
    update_member(&mouse.y, &y_offset);
    update_member(&mouse.h, &h_offset);
    update_member(&mouse.v, &v_offset);
#else
    update_member(&mouse.x, &y_offset);
    update_member(&mouse.y, &x_offset);
    update_member(&mouse.h, &v_offset);
    update_member(&mouse.v, &h_offset);
#endif
    pointing_device_set_report(mouse);
    if (has_report_changed(mouse, pointing_device_get_report())) {
        pointing_device_send();
    }
}

#ifndef TRACKBALL_ADDRESS
#    define TRACKBALL_ADDRESS 0x0A
#endif
#define TRACKBALL_WRITE ((TRACKBALL_ADDRESS << 1) | I2C_WRITE)
#define TRACKBALL_READ  ((TRACKBALL_ADDRESS << 1) | I2C_READ)

void trackball_set_rgbw(uint8_t red, uint8_t green, uint8_t blue, uint8_t white);
void trackball_check_click(bool pressed, report_mouse_t *mouse);
void trackball_register_button(bool pressed, enum mouse_buttons button);

float trackball_get_precision(void);
void    trackball_set_precision(float precision);
bool    trackball_is_scrolling(void);
void    trackball_set_scrolling(bool scroll);
#endif
