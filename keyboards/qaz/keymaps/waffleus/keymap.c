#include "waffleus.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_waffle_qaz(
        ________________QAZQWERTY1_________________,
        ________________QAZQWERTY2_________________,
        ________________QAZQWERTY3_________________,
        ___________QAZQWERTY4_BIGSPACE_____________
    ),
    [_LOWER] = LAYOUT_waffle_qaz(
        _________________QAZLOWER1_________________,
        _________________QAZLOWER2_________________,
        _________________QAZLOWER3_________________,
        ___________QAZLOWER4_BIGSPACE______________
    ),
    [_RAISE] = LAYOUT_waffle_qaz(
        _________________QAZRAISE1_________________,
        _________________QAZRAISE2_________________,
        _________________QAZRAISE3_________________,
        ____________QAZRAISE4_BIGSPACE_____________
    )
};
