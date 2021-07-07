/*
Copyright 2021 @mangoiv

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
#include "pimoroni_trackball.h"
#include "pointing_device.h"
#include "i2c_master.h"

enum layer_number {
  _BASE,
  _NUM,
  _SYM,
  _ADJUST,
  _MOUS
};

enum {
    TD_QESC,
    TD_WTAB,
    TD_QUOTJ,
    TD_YSCLN,
    TD_ZMINS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_QESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_WTAB] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_TAB),
    [TD_QUOTJ] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_QUOT),
    [TD_YSCLN] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_SCLN),
    [TD_ZMINS] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_MINS),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_X):
            return TAPPING_TERM + 250;
        default:
            return TAPPING_TERM;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_X):
            return true;
        default:
            return false;
    }
}

enum custom_keycodes {
  BALL_HUE = SAFE_RANGE, //hold + scroll ball up and down to cycle hue
  BALL_SAT,//hold + scroll ball up and down to cycle saturation
  BALL_VAL,//hold + scroll ball up and down to cycle value
  BALL_RCL,//hold + mouse click for right click,
  BALL_DRG,//hold + mouse click for drag mouse
};


char wpm_as_str[8];

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] =  LAYOUT(
        TD(TD_QESC),  TD(TD_WTAB),    KC_F,    KC_P,    KC_G,                        TD(TD_QUOTJ),            KC_L,       KC_U,    TD(TD_YSCLN),    KC_BSPC,
        KC_A,         KC_R,    KC_S,    KC_T,    KC_D,                                         KC_H,            KC_N,             KC_E,    KC_I,    KC_O,
        TD(TD_ZMINS), LALT_T(KC_X),    KC_C,    KC_V,    KC_B,                                 KC_K,     KC_M,    KC_COMM, KC_DOT,  KC_ENT,
                                                 KC_MUTE,                                      TO(_ADJUST),
                                        TO(_NUM), LCTL_T(KC_INS), LT(_NUM,KC_SPC),    KC_NO,   KC_LSFT, LT(_SYM,KC_DEL)
    ),
    [_NUM] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN,                      KC_EQUAL, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT,
        KC_MINS, KC_PGDN, KC_PGUP, KC_END, LCTL(KC_PSCREEN),              KC_LBRC, KC_RBRC,  KC_BSLS, KC_GRAVE, KC_SLSH,
                                            XXXXXXX,                      KC_TRNS,
                                   TO(_BASE), KC_TRNS, XXXXXXX,    KC_NO,   _______, KC_TRNS
    ),
    [_SYM] = LAYOUT(
        KC_EXLM,  KC_AT,   KC_HASH,   KC_DOLLAR,   KC_PERC,               KC_CIRC, KC_AMPR, KC_ASTERISK, KC_LPRN,  KC_RPRN,
        KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6, KC_F7, KC_F8, KC_F9,  KC_F10,
        KC_LCTL, KC_LALT, KC_LGUI, KC_DEL, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, KC_F11, KC_F12,
                                            XXXXXXX,                       XXXXXXX,
                                   KC_LALT, XXXXXXX, XXXXXXX,    XXXXXXX, KC_NO,   _______
    ),
    [_ADJUST] = LAYOUT(
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       BALL_HUE, BALL_VAL, BALL_SAT, XXXXXXX, XXXXXXX,
        EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX,                       TO(_BASE),
                                   XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MOUS] = LAYOUT(
        XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      BALL_HUE, BALL_VAL, BALL_SAT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, BALL_DRG, BALL_RCL,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX,                      _______,
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX
    )
};


#ifdef OLED_DRIVER_ENABLE


oled_rotation_t oled_init_user(oled_rotation_t rotation) {

 if (is_keyboard_master()) {
    if(is_keyboard_left()){
      return OLED_ROTATION_270;
      }
      else {
        return OLED_ROTATION_90;
      }
    } else {
	    return OLED_ROTATION_0;
    }
}
static void render_logo(void) {
  static const char PROGMEM drac_logo[] = {
    // drac_logo, 128x64px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x0c, 0x18, 0x78, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x07, 0x3e, 0xfc, 0xf0, 0x00, 0x00, 0x00,
    0xf0, 0xf0, 0x60, 0x30, 0x30, 0x30, 0x00, 0x00, 0xe0, 0xe0, 0x30, 0x30, 0x30, 0x30, 0x30, 0xe0,
    0xe0, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x30, 0x30, 0x30, 0x70, 0xe0, 0xc0, 0x00, 0x00,
    0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0,
    0x80, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xf0, 0x80, 0xc0, 0xe0, 0xf0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0x7c, 0x3f, 0x0f, 0x00, 0x00, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf8, 0xcc, 0x8c, 0x84, 0x86, 0x86, 0xc6, 0xff,
    0xff, 0x80, 0x80, 0x00, 0x3f, 0x7f, 0xe0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xf0, 0x71, 0x00, 0x00,
    0x1f, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x1f,
    0x7f, 0x7f, 0x3e, 0x3e, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf8, 0xfc,
    0xfc, 0xfe, 0xfe, 0x7e, 0x7c, 0x78, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x60, 0x60,
    0x60, 0x60, 0x60, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xe0, 0x60, 0x60, 0x60, 0xc0,
    0xc0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07,
    0x0f, 0x3e, 0x7c, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8,
    0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf1, 0x99, 0x18, 0x08,
    0x0c, 0x0c, 0x8c, 0xff, 0xff, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc3, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01,
    0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  oled_write_raw_P(drac_logo, sizeof(drac_logo));
}

static void render_status(void) {
  oled_write_P(PSTR("This is\n~~~~~~~~~\nDracu\nLad\n~~~~~~~~~\nv1.0\n~~~~~~~~~\n"), false);
  sprintf(wpm_as_str, "WPM %03d", get_current_wpm());
  oled_write(wpm_as_str,false);
  led_t led_state = host_keyboard_led_state();
  oled_write_P(PSTR("\nCaps: "), false);
  oled_write_P(led_state.caps_lock ? PSTR("on ") : PSTR("off"), false);
  oled_write_P(PSTR("\n"),false);
  switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base   "), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numbers"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust "), false);
            break;
        case _MOUS:
            oled_write_P(PSTR("Mouse  "), false);
            break;
        default:
            oled_write_P(PSTR("Unkn "), false);
            break;
    }
}

void oled_task_user(void) {
      if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
    }
}

#endif

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
  user_config.tb_hue = 255;
  user_config.tb_saturation = 255;
  user_config.tb_value = 255;
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
		} else
        if (state.button_triggered && (drag_mode_enabled == 1)) {
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
                h_offset += (state.x);
                v_offset -= (state.y);
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


#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 2) {
      switch (get_highest_layer(layer_state)) {
        case _MOUS:
            clockwise?tap_code(KC_WH_U):tap_code(KC_WH_D);
            break;
        default:
            clockwise?tap_code(KC_PGUP):tap_code(KC_PGDN);
            break;
      }
    }
    // I only have 2 encoders on the the pimoroni example board, just add else ifs for your other encoders...
    // the missing ones are encoder 1 on the right side and encoder 3 on the left side
}
#endif
