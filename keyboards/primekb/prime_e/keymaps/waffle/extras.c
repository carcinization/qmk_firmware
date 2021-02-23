#pragma once

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LWRSPC:
            return TAPPING_TERM - 45;
        default:
            return TAPPING_TERM;
    }
}
