#include "waffleus.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_waffle(
        ______________DEFAULTQWERTY1_______________, KC_MNXT,
        ______________DEFAULTQWERTY2_______________,
        ______________DEFAULTQWERTY3_______________,
        KC_MPLY, KC_LGUI, LWRSPC, CP_PSTE, RAISE
    ),
    [_LOWER] = LAYOUT_waffle(
        ______________DEFAULTLOWER1_______________, KC_MPRV,
        ______________DEFAULTLOWER2_______________,
        ______________DEFAULTLOWER3_______________,
        KC_MUTE, KC_LGUI, KC_TRNS, KC_RGUI, KC_TRNS
    ),
    [_RAISE] = LAYOUT_waffle(
        ______________DEFAULTRAISE1_______________, KC_TRNS,
        ______________DEFAULTRAISE2_______________,
        ______________DEFAULTRAISE3_______________,
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); 
  rgblight_sethsv_noeeprom(HSV_CYAN);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
