#include QMK_KEYBOARD_H
#include "waffleus.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
        ________________CRKBDQWERTY1_______________,
        ________________CRKBDQWERTY2_______________,
        ________________CRKBDQWERTY3_______________,
        ________________CRKBDQWERTY4_______________
    ),
    [_LOWER] = LAYOUT_wrapper(
        ________________CRKBDLOWER1________________,
        ________________CRKBDLOWER2________________,
        ________________CRKBDLOWER3________________,
        ________________CRKBDLOWER4________________
    ),
    [_RAISE] = LAYOUT_wrapper(
        ________________CRKBDRAISE1________________,
        ________________CRKBDRAISE2________________,
        ________________CRKBDRAISE3________________,
        ________________CRKBDRAISE4________________
    )
};
