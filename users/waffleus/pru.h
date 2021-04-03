#pragma once
#include "waffleus.h"

enum userspace_custom_keycodes {
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

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}
