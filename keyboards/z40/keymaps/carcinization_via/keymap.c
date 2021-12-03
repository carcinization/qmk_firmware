#include "z40.h"

enum layers {
  _QWERTY,
  _LOWER,
  _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	  [_QWERTY] = LAYOUT(
		KC_ESC,  KC_Q,  KC_W,  KC_F,  KC_P,  KC_G, KC_J,  KC_L,  KC_U,  KC_Y,  KC_SCLN, KC_BSPC,
	    KC_TAB,  KC_A,  KC_R,  KC_S,  KC_T,  KC_D, KC_H,  KC_N,  KC_E,  KC_I, KC_O, KC_QUOT,
		KC_LCTL,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B, KC_K,  KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_ENT,
		KC_MINS, KC_EQUAL, KC_LALT, KC_LGUI, LT(_NAV, KC_DEL), LT(_LOWER, KC_SPC), KC_LSFT, KC_BSLS, KC_GRAVE, KC_PSCREEN, KC_ENT),

	  [_LOWER] = LAYOUT(
		TG(_NAV), KC_1, KC_2,   KC_3,   KC_4,   KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_TRNS,
		KC_LBRC, KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_TRNS, KC_TRNS,KC_LEFT,KC_UP,KC_DOWN,KC_RIGHT,KC_RBRC,
		KC_LCBR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_MS_WH_LEFT,KC_MS_WH_UP,KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_RCBR,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),

    [_NAV] = LAYOUT(
    	TG(_NAV), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
		KC_LBRC, KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_VOLU, KC_VOLD,KC_HOME,KC_PGUP,KC_PGDN,KC_END,KC_TRNS,
		KC_LCBR, KC_UP, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI,RGB_VAI,RGB_SPI,KC_TRNS,KC_TRNS, KC_UP, KC_TRNS,
		KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT, KC_LEFT, KC_DOWN, KC_RIGHT),



};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }
