#include "waffleus.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_waffle_yoink(
        QMKTD,   ______________DEFAULTQWERTY1_______________,    STARX,            KC_MPLY,
        ALT_TAB,    ______________DEFAULTQWERTY2_______________,             KC_MNXT,
        CP_PSTE,    ______________DEFAULTQWERTY3_______________,            KC_UP,   KC_MPRV,
        KC_LCTL, KC_LALT, KC_LGUI, LWRSPC, RAISE, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LOWER] = LAYOUT_waffle_yoink(
        DOCSTD,  ______________DEFAULTLOWER1_______________,    ROFL,  KC_MUTE,
        KC_TRNS, ______________DEFAULTLOWER2_______________,          KC_TRNS,
        HAPSAD, ______________DEFAULTLOWER3_______________, RGB_M_P,          KC_TRNS,
        KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_SLSH, KC_RGUI, KC_RCTL, RGB_RMOD, RGB_M_SN, RGB_MOD
    ),

    [_RAISE] = LAYOUT_waffle_yoink(
        UC_M_LN,  ______________DEFAULTRAISE1_______________,    ARWUP,  RESET,
        UC_M_MA, ______________DEFAULTRAISE2_______________,          MAKE,
        UC_M_WC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, TABLE1, TABLE2, DANCE, LENNY, RGB_VAI, KC_TRNS,
        KC_LCTL, KC_LALT, KC_LGUI, KC_SCLN, KC_TRNS, KC_RGUI, KC_RCTL, KC_TRNS, RGB_VAD, KC_TRNS
    )
};

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_CYAN);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {
        case _QWERTY:
            clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
            break;
        case _LOWER:
            clockwise ? rgblight_increase_hue() : rgblight_decrease_hue();
            break;
        case _RAISE:
            clockwise ? rgblight_increase_sat() : rgblight_decrease_sat();
            break;
    }
}


