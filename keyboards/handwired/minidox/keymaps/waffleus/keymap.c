#include "waffleus.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_waffle(
        ________________MDOXQWERTY1________________,
        ________________MDOXQWERTY2________________,
        ________________MDOXQWERTY3________________,
        ________________MDOXQWERTY4________________
    ),
    [_LOWER] = LAYOUT_waffle(
        ________________MDOXLOWER1________________,
        ________________MDOXLOWER2________________,
        ________________MDOXLOWER3________________,
        ________________MDOXLOWER4________________
    ),
    [_RAISE] = LAYOUT_waffle(
        ________________MDOXRAISE1________________,
        ________________MDOXRAISE2________________,
        ________________MDOXRAISE3________________,
        ________________MDOXRAISE4________________
    )
};
