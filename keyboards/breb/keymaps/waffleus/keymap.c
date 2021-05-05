#include "waffleus.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT_smol(
     KC_A, KC_B, LT(1, KC_C)
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
