#include "waffleus.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_waffle_yoink(
        ______________YOINKQWERTY1________________,
        ______________YOINKQWERTY2________________,
        ______________YOINKQWERTY3________________,
        ______________YOINKQWERTY4________________
    ),

    [_LOWER] = LAYOUT_waffle_yoink(
        _______________YOINKLOWER1________________,
        _______________YOINKLOWER2________________,
        _______________YOINKLOWER3________________,
        _______________YOINKLOWER4________________
    ),

    [_RAISE] = LAYOUT_waffle_yoink(
        _______________YOINKRAISE1________________,
        _______________YOINKRAISE2________________,
        _______________YOINKRAISE3________________,
        _______________YOINKRAISE4________________
    )
};
