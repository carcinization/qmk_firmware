#include "waffleus.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_waffle_corne(
        ________________CRKBDQWERTY1_______________
        ________________CRKBDQWERTY2_______________
        ________________CRKBDQWERTY3_______________
        ________________CRKBDQWERTY4_______________
    ),
    [_LOWER] = LAYOUT_waffle_corne(
        ________________CRKBDLOWER1________________
        ________________CRKBDLOWER2________________
        ________________CRKBDLOWER3________________
        ________________CRKBDLOWER4________________
    ),
    [_RAISE] = LAYOUT_waffle_corne(
        ________________CRKBDRAISE1________________
        ________________CRKBDRAISE2________________
        ________________CRKBDRAISE3________________
        ________________CRKBDRAISE4________________
    ),
    [_ADJUST] = LAYOUT_waffle_corne(
        _______________CRKBDADJUST1________________
        _______________CRKBDADJUST2________________
        _______________CRKBDADJUST3________________
        _______________CRKBDADJUST4________________
    )
};
