#include "waffleus.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_waffle_33(
        ______________DEFAULTQWERTY1_______________,
        ______________DEFAULTQWERTY2_______________,
        ______________DEFAULTQWERTY3_______________,
        KC_LGUI, LWRSPC, RAISE
    ),
    [_LOWER] = LAYOUT_waffle_33(
        ______________DEFAULTLOWER1_______________,
        ______________DEFAULTLOWER2_______________,
        ______________DEFAULTLOWER3_______________,
        KC_LALT, KC_TRNS, KC_RALT
    ),
    [_RAISE] = LAYOUT_waffle_33(
        ______________DEFAULTRAISE1_______________,
        ______________DEFAULTRAISE2_______________,
        ______________DEFAULTRAISE3_______________,
        KC_LCTL, KC_SCLN, KC_TRNS
    ),
};

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_RED);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
