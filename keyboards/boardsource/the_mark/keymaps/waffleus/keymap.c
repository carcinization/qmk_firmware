#include "waffleus.h"
#define XXX KC_NO
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_all(
		XXX,  XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX, XXX,  XXX, XXX, KC_MPLY,
		QMKTD,           ALTQ,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    ALTP,    MPSCR, XXX, XXX, KC_MNXT,
		MACTAB,          SFA,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    SFL,    KC_BSPC, XXX,          XXX,  KC_MPRV,
		MAC_PSTE, MAC_PSTE, CMDZ,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, CMDOT,  CMDSLSH, XXX,          KC_VOLU,
	    KC_LCTL, KC_LGUI, KC_LALT,          LWRSPC,           CLIPST,           RAISE,           KC_RALT, KC_RCTL, KC_RCTL,  RGB_RMOD, KC_VOLD, RGB_MOD
	),
    [_LOWER] = LAYOUT_all(
        XXX,      XXX,     XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,     XXX,     XXX,     XXX,    XXX,    XXX,
        DOCSTD,                KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ROFL,    XXX,    XXX,    XXX,
        KC_SLCK,                  SFEXM,    KC_AT,    KC_HASH,    KC_DLR,    KC_PERC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    SFPRN,    XXX,    XXX,                XXX,    XXX,
        KC_NLCK,    KC_NLCK,    CMDESC,    KC_TAB,    KC_CAPS,    KC_TILD,    KC_GRV,    KC_LEFT,    KC_UP,    KC_DOWN,    KC_RIGHT,    KC_RGUI,    XXX,                XXX,
        XXX,    XXX,    XXX,                KC_TRNS,                KC_SPC,                KC_SLSH,                XXX,    XXX,    XXX,    XXX,    XXX,    XXX
    ),
    [_RAISE] = LAYOUT_all(
        XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    RESET,
        XXX,                KC_MINS,    KC_EQL,    KC_LBRC,    KC_RBRC,    KC_BSLS,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    MAKE,
        XXX,                KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_PIPE,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    EEP_RST,
        XXX,    XXX,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                _______,
        XXX,    XXX,    XXX,                KC_SCLN,                KC_SPC,                KC_TRNS,                XXX,    XXX,    XXX,    XXX,    XXX,    XXX
    ),
    [_ADJUST] = LAYOUT_all(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,
        _______,    _______,    _______,                _______,                _______,                _______,                _______,    _______,    _______,    _______,    _______,    _______
    )
};
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_PURPLE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
