#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "macros.h"
#include "unicodes.h"
#include "combos.h"
#include "tapdance.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WIN] = LAYOUT(
		QMKTD, KC_Q,   KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,   KC_P, GPSCR,                     KC_7, KC_8, KC_9,
		ALT_TAB,  SFA,     KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,     SFL,  KC_BSPC,                      KC_4, KC_5, KC_6,
		LINKSTD,   CTLTZ,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM,  CTLDOT,        KC_VOLU,             KC_1, KC_2, KC_3,
		HAPSAD,  KC_LALT,    KC_LGUI,   LWRSPC,          RAISE,          KC_RGUI, KC_RALT,        KC_MPRV, KC_VOLD, KC_MNXT,        KC_0, MAC
    ),

    [_MAC] = LAYOUT(
		QMKTD, KC_Q,   KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,   KC_P, GPSCR,                     KC_7, KC_8, KC_9,
		ALT_TAB,  SFA,     KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,     SFL,  KC_BSPC,                      KC_4, KC_5, KC_6,
		LINKSTD,   CMDZ,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM,  CMDDOT,        KC_VOLU,             KC_1, KC_2, KC_3,
		HAPSAD,  KC_LALT,    KC_LGUI,   LWRSPC,          RAISE,          KC_RGUI, KC_RALT,        KC_MPRV, KC_VOLD, KC_MNXT,        KC_0, WIN
    ),

    [_LOWER] = LAYOUT(
		DOCSTD, KC_1,   KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,   KC_8,     KC_9,   KC_0, KC_DEL,                             RGB_RMOD, RGB_MOD, RGB_TOG,
		WEEB,    SFEXM,   KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, SFPRN,                                RGB_M_SW, RGB_M_SN, RGB_M_G,
		VIA,       CTLESC,    KC_TAB,  KC_CAPS,   KC_TILD,  KC_GRV,    KC_LEFT,  KC_UP,    KC_DOWN,  KC_RGHT,        RGB_HUI,             RGB_M_B, RGB_M_P, RGB_M_R,
		XWIDE,    KC_LALT,    KC_LGUI,   KC_TRNS,          KC_SCLN,          KC_RGUI, KC_RALT,        RGB_SAD, RGB_HUD, RGB_SAI,            RGB_VAD, RGB_VAI
    ),

    [_RAISE] = LAYOUT(
		RESET,    KC_MINS, KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,  CG_NORM,  KC_ASUP,  KC_ASON,     UNIT,   UNIT4, UNIT3,       KC_SCRIPT, KC_BLOCKS, KC_NOMODE,
		UC_M_WC,  KC_UNDS, KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,  CG_SWAP,  KC_ASDN,  KC_ASOFF,  LAG_SWP, LAG_NRM,                    KC_WIDE, KC_AUSSIE, KC_REGIONAL,
		UC_M_MA,  KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,  KC_F7,    KC_F8,  KC_F9,                KC_UP,              _______, _______, _______,
		MAKE,  KC_LALT,    KC_LGUI,   KC_SLSH,          KC_TRNS,          KC_RGUI, KC_RALT,                KC_LEFT, KC_DOWN, KC_RGHT,        _______, _______
    )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LWRSPC:
            return TAPPING_TERM - 25;
        default:
            return TAPPING_TERM;
    }
}
