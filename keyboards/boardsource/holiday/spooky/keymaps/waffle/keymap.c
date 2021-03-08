#include QMK_KEYBOARD_H
#include <stdio.h>
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_2x3(
      KC_A,  KC_B, KC_C,
      TG(1), TG(2),TG(3)
    ),
    [1] = LAYOUT_ortho_2x3(
      KC_D,  KC_E, KC_F,
      TG(1), KC_G, KC_H
    ),
    [2] = LAYOUT_ortho_2x3(
      KC_A, KC_B, KC_C,
      KC_I, TG(2), KC_J
    ),
    [3] = LAYOUT_ortho_2x3(
      KC_A,  KC_B, KC_C,
      KC_K,  KC_L, TG(3)
    )
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
    return rotation;
}

char keylog_str[24] = {};
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
        if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
            (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP)) { keycode = keycode & 0xFF; }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
        record->event.key.row, record->event.key.col,
        keycode, name);

}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_task_user(void) {
    oled_render_keylog();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return true;
}
