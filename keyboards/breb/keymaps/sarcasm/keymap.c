#include QMK_KEYBOARD_H
enum custom_keycodes {
    MOCKLOCK = SAFE_RANGE,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT_smol(
     KC_A, KC_B, LT(1, KC_C)
 ),
 [1] = LAYOUT_smol(
     MOCKLOCK, KC_TRNS, KC_TRNS
 )
};

#define MODS_MASK (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL))
bool is_mocklock_active = false;
bool random_bool(void) {
    bool rbool = rand() & 1;
    return rbool;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_Z: {
            if (is_mocklock_active && record->event.pressed) {
                if (random_bool()) {
                    register_code(KC_LSFT);
                }
            }
            break;
        }
        case MOCKLOCK:
            if ((keyboard_report->mods & MODS_MASK) && record->event.pressed) is_mocklock_active = !is_mocklock_active;
            break;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_Z: {
            if (is_mocklock_active && record->event.pressed) {
                unregister_code(KC_LSFT);
            }
        }
    }
}
