#include "waffleus.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_waffle_all(
        ______________ROMEOQWERTY1________________
        ______________ROMEOQWERTY2________________
        ______________ROMEOQWERTY3________________
        ______________ROMEOQWERTY4________________
    ),
    [1] = LAYOUT_waffle_all(
        ______________ROMEOLOWER1_________________
        ______________ROMEOLOWER2_________________
        ______________ROMEOLOWER3_________________
        ______________ROMEOLOWER4_________________
    ),
    [2] = LAYOUT_waffle_all(
        ______________ROMEORAISE1_________________
        ______________ROMEORAISE2_________________
        ______________ROMEORAISE3_________________
        ______________ROMEORAISE4_________________
    ),
    [3] = LAYOUT_all(
  	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
