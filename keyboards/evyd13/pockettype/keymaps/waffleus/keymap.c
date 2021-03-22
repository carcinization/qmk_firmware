#include "waffleus.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_waffle_ortho(
  QMKTD,    ______________DEFAULTQWERTY1_______________, KC_TRNS,
  HAPSAD,    ______________DEFAULTQWERTY2_______________, KC_TRNS,
  TG(_LOWER), ______________DEFAULTQWERTY3_______________, TG(_RAISE),
  KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC),

[_LOWER] = LAYOUT_waffle_ortho(
  KC_TRNS,    ______________DEFAULTLOWER1_______________, KC_TRNS,
  KC_TRNS,    ______________DEFAULTLOWER2_______________, KC_TRNS,
  TG(_LOWER), ______________DEFAULTLOWER3_______________, KC_TRNS,
  KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC),

[_RAISE] = LAYOUT_waffle_ortho(
  KC_TRNS,  ______________DEFAULTRAISE1_______________, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
  KC_TRNS,  ______________DEFAULTRAISE2_______________, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,  ______________DEFAULTRAISE3_______________, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_RAISE),
  KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  writePin(F5, (get_highest_layer(state) == _LOWER));
  return state;
}
