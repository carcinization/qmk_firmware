#include QMK_KEYBOARD_H
#include "waffleus.h"
#define LAYOUT(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    ________________QWERTY_L1__________________, ________________QWERTY_R1__________________,
    ________________QWERTY_L2__________________, ________________QWERTY_R2__________________,
    ________________QWERTY_L3__________________, ________________QWERTY_R3__________________,
    ________________QWERTY_LR4__________________
  )
};
