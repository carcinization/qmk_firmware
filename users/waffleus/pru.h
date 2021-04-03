#pragma once
#include "waffleus.h"

enum custom_keycodes {
    CP_PSTE = SAFE_RANGE,
#ifdef UNICODEMAP_ENABLE
    UNIT,
    UNIT2,
    UNIT3,
    UNIT4,
#endif
#ifdef RGBLIGHT_ENABLE
    RGBRST,
#endif
    ALT_TAB,
    MAKE
};
