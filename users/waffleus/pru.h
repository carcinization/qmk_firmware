#pragma once
#include "waffleus.h"
//#define RANDICT
bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

enum userspace_custom_keycodes {
    CP_PSTE = SAFE_RANGE,
    MAC_PSTE,
    ROFL,
#ifdef UNICODEMAP_ENABLE
    UNIT,
    UNIT2,
    TABLE1,
    TABLE2,
    LENNY,
    DANCE,
#endif
#ifdef RGBLIGHT_ENABLE
    RGBRST,
#endif
#ifdef RANDICT
    RWORD,
#endif
    ALT_TAB,
    MAKE,
    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    KC_SECRET_4,
    KC_SECRET_5
};
