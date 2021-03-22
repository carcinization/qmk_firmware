#include "waffleus.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_waffle(
        ________________QAZQWERTY1_________________,
        ________________QAZQWERTY2_________________,
        ________________QAZQWERTY3_________________,
        ___________QAZQWERTY4_BIGSPACE_____________
    )
};
