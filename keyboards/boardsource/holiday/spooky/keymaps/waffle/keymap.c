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

#define KEYLOG_LEN 11
char keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx = 0;
uint16_t log_timer = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger(void) {
    oled_write(keylog_str, false);
}

void render_keylogger_status(void) {
    bool blink = (timer_read() % 1000) < 500;
    oled_write_ln_P(blink ? PSTR("~ _") : PSTR("~  "), false);
}

void oled_task_user(void) {
    update_log();
    oled_set_cursor(6, 1);
    render_keylogger();
    oled_set_cursor(5, 1);
    render_keylogger_status();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      add_keylog(keycode);
    }
    return true;
}
