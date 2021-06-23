/* Copyright 2020 @toastedmangoes
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
#include "pimoroni_trackball.h"
#include "pointing_device.h"
#include "i2c_master.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SFTENT:
            return 50;
        default:
            return TAPPING_TERM;
    }
}

enum layer_names {
    _BASE,
    _NUM,
	_SYM,
    _ADJUST,
    _MOUS
};

enum custom_keycodes {
  BALL_HUE = USER00, //hold + scroll ball up and down to cycle hue
  BALL_SAT,//hold + scroll ball up and down to cycle saturation
  BALL_VAL,//hold + scroll ball up and down to cycle value
  BALL_RCL,
  BALL_DRG,
};

// void keyboard_post_init_user(void) { i2c_init(); }


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,      KC_G,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_LCTL,  KC_A, KC_R, KC_S, KC_T, KC_D,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
                                            KC_NO,   MO(1),    KC_SPC,   MO(2),    LT(3, KC_RALT)
  ),

  [_NUM] = LAYOUT_reviung41(
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_GRV,   KC_TILD,
    _______,  KC_ESC,   KC_LGUI,  KC_LALT,  KC_CAPS,   KC_DQUO,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  RSFT_T(KC_SPC),
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),

  [_SYM] = LAYOUT_reviung41(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
    _______,  KC_ESC,   KC_RGUI,  KC_RALT,  KC_CAPS,   KC_QUOT,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),

  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    BALL_HUE,  BALL_SAT,  BALL_VAL,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
    [_MOUS] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  BALL_RCL,  KC_TRNS,  KC_TRNS,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_C,            KC_TRNS,   BALL_HUE,  BALL_SAT,  BALL_VAL,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  BALL_DRG,  BALL_RCL,  _______
  ),
};

#include "timer.h"
#include "math.h"
#include "quantum/quantum.h"

static int16_t mouse_auto_layer_timer = 0;
static bool hue_mode_enabled = 0;
static bool saturation_mode_enabled = 0;
static bool value_mode_enabled = 0;
static bool right_click_mode_enabled = 0;
static bool drag_mode_enabled = 0;
#define MOUSE_TIMEOUT 1000
#define TRACKBALL_TIMEOUT 5

#define SIGN(x) ((x > 0) - (x < 0))

// user config EEPROM stuff {{{
typedef union {
  uint32_t raw;
  struct {
	uint8_t tb_hue :8;
    uint8_t tb_value :8;
	uint8_t tb_saturation :8;
  };
} user_config_t;

user_config_t user_config;

static uint8_t tb_hue = 1;
static uint8_t tb_saturation = 255;
static uint8_t tb_value = 255;


void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
  tb_hue = user_config.tb_hue;
  tb_saturation = user_config.tb_saturation;
  tb_value = user_config.tb_value;
  trackball_set_hsv(tb_hue, tb_saturation,tb_value);
}

void eeconfig_init_user(void) {
  user_config.raw = 0;
  user_config.tb_hue = 80;
  user_config.tb_saturation = 80;
  user_config.tb_value = 80;
  eeconfig_update_user(user_config.raw);
}
// }}}

void matrix_init_user() {
    trackball_init();
}

void suspend_power_down_user(void) {
    trackball_set_brightness(0);
    /* trackball_sleep(); */
}

__attribute__((weak)) void pointing_device_init(void) { trackball_set_rgbw(0,0,0,tb_value); }

void update_member(int8_t* member, int16_t* offset) {//{{{
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
}//}}}

static int16_t x_offset = 0;
static int16_t y_offset = 0;
static int16_t v_offset = 0;
static int16_t h_offset = 0;
static int16_t tb_timer = 0;
void pointing_device_task() {
    report_mouse_t mouse = pointing_device_get_report();

    if (trackball_get_interrupt() && (!tb_timer || timer_elapsed(tb_timer) > TRACKBALL_TIMEOUT)) {
        tb_timer = timer_read() | 1;

        trackball_state_t state = trackball_get_state();

        uint8_t mods;
        if (state.x || state.y) {
            mods = get_mods();
        }

        if (state.button_triggered && (right_click_mode_enabled == 1)) {
            if(state.button_down) {
                mouse.buttons |= MOUSE_BTN2;
            } else {
                mouse.buttons &= ~MOUSE_BTN2;
            }
            pointing_device_set_report(mouse);
		pointing_device_send();
		} else if (state.button_triggered && (drag_mode_enabled == 1)) {
			if (state.button_down){
			mouse.buttons |= MOUSE_BTN1;
			pointing_device_set_report(mouse);
            pointing_device_send();}
		} else if (state.button_triggered) {
			if(state.button_down) {
				mouse.buttons |= MOUSE_BTN1;
			} else {
				mouse.buttons &= ~MOUSE_BTN1;
			}
			pointing_device_set_report(mouse);
            pointing_device_send();
        } else {
			// on the ADJUST layer with BALL_VAL held, roll ball downwards to change trackball value
            if (layer_state_is(_ADJUST) && value_mode_enabled == 1) {
                tb_value += state.y * 2;
                trackball_set_hsv(tb_hue, tb_saturation, tb_value | 1);
			// on the ADJUST layer with BALL_SAT held, roll ball downwards to change trackball saturation
			} else if (layer_state_is(_ADJUST) && saturation_mode_enabled == 1) {
				tb_saturation += state.y * 2;
                trackball_set_hsv(tb_hue, tb_saturation | 1, tb_value);
			// on the ADJUST layer, or with BALL_HUE held, roll ball downwards to change trackball hue
			} else if (layer_state_is(_ADJUST) || hue_mode_enabled == 1) {
				tb_hue += state.y;
                trackball_set_hsv(tb_hue | 1, tb_saturation, tb_value);
			// on the NUM layer, trackball behaves as vertical scroll
            } else if (layer_state_is(_NUM) || layer_state_is(_SYM)) {
                h_offset += (0.5*state.x);
                v_offset -= (0.5*state.y);
            } else if ((state.x || state.y) && !state.button_down) {

			if (!mouse_auto_layer_timer && !layer_state_is(_NUM)) {
                    layer_on(_MOUS);
                }
                mouse_auto_layer_timer = timer_read() | 1;

                uint8_t scale = 3;
                if (mods & MOD_MASK_CTRL) scale = 2;
                x_offset += state.x * state.x * SIGN(state.x) * scale;
                y_offset += state.y * state.y * SIGN(state.y) * scale;

            }
        }

        /* xprintf("%d, %d, %d, %d, %d\n", */
        /*         s[0], s[1], */
        /*         s[2], s[3], */
        /*         s[4]); */

    }

    while (x_offset || y_offset || h_offset || v_offset) {
        update_member(&mouse.x, &x_offset);
        update_member(&mouse.y, &y_offset);

        update_member(&mouse.v, &v_offset);
        update_member(&mouse.h, &h_offset);

        pointing_device_set_report(mouse);
        pointing_device_send();
    }
}

void matrix_scan_user(void) {/*{{{*/
    if (mouse_auto_layer_timer && timer_elapsed(mouse_auto_layer_timer) > MOUSE_TIMEOUT) {
        report_mouse_t rep = pointing_device_get_report();
        if (rep.buttons) { return; }
        layer_off(_MOUS);
        mouse_auto_layer_timer = 0;
    }
}/*}}}*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {/*{{{*/
    switch (keycode) {
    case BALL_HUE:
        if (record->event.pressed) {
        hue_mode_enabled = 1;
        } else {
        hue_mode_enabled = 0;
        }
        break;
	case BALL_SAT:
		if (record->event.pressed) {
        saturation_mode_enabled = 1;
        } else {
        saturation_mode_enabled = 0;
        }
        break;
	case BALL_VAL:
		if (record->event.pressed) {
        value_mode_enabled = 1;
        } else {
        value_mode_enabled = 0;
        }
        break;
	case BALL_RCL:
	if (record->event.pressed) {
        right_click_mode_enabled = 1;
        } else {
        right_click_mode_enabled = 0;
        }
        break;
	case BALL_DRG:
	if (record->event.pressed) {
        drag_mode_enabled = 1;
        } else {
        drag_mode_enabled = 0;
        }
        break;
/*   case BALL_NCL:
     record->event.pressed?register_code(KC_BTN1):unregister_code(KC_BTN1);
     break;
  case BALL_RCL:
      record->event.pressed?register_code(KC_BTN2):unregister_code(KC_BTN2);
      break;
  case BALL_MCL:
      record->event.pressed?register_code(KC_BTN3):unregister_code(KC_BTN3);
      break; */
    }

	if ((keycode < KC_BTN1 || ((keycode > KC_BTN5) && (keycode < SAFE_RANGE)))
			&& layer_state_is(_MOUS)
            && record->event.pressed) {
        layer_off(_MOUS);
        mouse_auto_layer_timer = 0;
    }
    return true;

}/*}}}*/


static uint8_t last_layer = _BASE;
layer_state_t layer_state_set_user(layer_state_t state) {/*{{{*/
    uint8_t layer = get_highest_layer(state);

    switch(layer) {
        case _NUM:
            trackball_set_hsv(tb_hue + 20, tb_saturation, ((tb_value-30) > 0 ? (tb_value-30) : 0));
            break;
		case _SYM:
			trackball_set_hsv(tb_hue - 20, tb_saturation, ((tb_value-30) > 0 ? (tb_value-30) : 0));
			break;
        case _ADJUST:
            trackball_set_hsv(tb_hue, ((tb_saturation+20) < 255 ? (tb_saturation+20) : 255), tb_value);
            break;
        case _MOUS:
            trackball_set_hsv(tb_hue, tb_saturation, tb_value);
            break;
        default:
            trackball_set_hsv(tb_hue, tb_saturation, ((tb_value-30) > 0 ? (tb_value-30) : 0));
            break;
    }

    // if layer *was* ADJUST, save eeprom
    if (
            last_layer == _ADJUST
            && last_layer != layer
            && (tb_value != user_config.tb_value || tb_hue != user_config.tb_hue || tb_saturation != user_config.tb_saturation)
       ) {
        user_config.tb_value = tb_value;
		user_config.tb_hue = tb_hue;
		user_config.tb_saturation = tb_saturation;
        eeconfig_update_user(user_config.raw);
    }

    last_layer = layer;
    return state;
}/*}}}*/

