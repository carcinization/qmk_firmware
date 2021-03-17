#include QMK_KEYBOARD_H
enum custom_keycodes {
    BICAM = SAFE_RANGE, //list of macros
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case BICAM:
        if (record->event.pressed) {
            SEND_STRING("TorobatL"SS_TAP(X_ENTER));
        } else {
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ortho_4x4(
        KC_MUTE,    TG(1),        LOPT(KC_D),   LGUI(KC_W),
        BICAM,      HYPR(KC_G),   LGUI(KC_Z),   LGUI(KC_C),
        KC_LGUI,    LCTL(KC_Q),   HYPR(KC_C),   LGUI(KC_Y),
        LGUI(KC_Q), KC_HYPR,      KC_LGUI,      KC_ENT
  ),
  [1] = LAYOUT_ortho_4x4(
        KC_MUTE, TG(2), KC_ENT, LGUI(KC_W),
        KC_P7, KC_P8,   KC_P9,      KC_PPLS,
        KC_P4, KC_P5,   KC_P6,      KC_PMNS,
        KC_P1, KC_PDOT, KC_P3,    KC_P0
  ),
  [2] = LAYOUT_ortho_4x4(
        KC_MUTE, TG(0),   LGUI(KC_M),      LGUI(KC_W),
        LGUI(KC_S), KC_I,   LGUI(KC_T),      LGUI(KC_I),
        KC_C, KC_O,   LGUI(KC_Z),      LGUI(KC_Y),
        KC_V, LOPT(KC_X), KC_LOPT,    KC_ENT
  )
};

// Set led state during powerup
void keyboard_post_init_user(void) {
    writePinHigh(LED_RED);
}
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(C(S(KC_TAB)));
        } else {
            tap_code16(C(KC_TAB));
        } //second encoder (E2)
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
