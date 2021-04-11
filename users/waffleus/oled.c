#include "waffleus.h"
#include <stdio.h>
uint32_t oled_timer = 0;
static uint16_t log_timer = 0;

void render_wpm(void) {
    char wpm_wring[5];
    oled_write_ln(WPM, false);
    snprintf(wpm_wring,
    sizeof(wpm_wring), " %3d",
    get_current_wpm());
    oled_write(wpm_wring, false);
}

void render_qmk_logo(void) {
    static const char PROGMEM font_qmk_logo[16] = {0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0};
    oled_write_P(font_qmk_logo, false);
};

void render_keyboard(void) {
    static const char PROGMEM font_keyboard[16] = {0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0};
    oled_write_P(font_keyboard, false);
};

void render_mod_ctrl(void) { // ^
    static const char PROGMEM font_ctrl[3] = {0x93, 0x94, 0};
    oled_write_P(font_ctrl, false);
};

void render_mod_alt(void) { // ⌥
    static const char PROGMEM font_alt[3] = {0xb3, 0xb4, 0};
    oled_write_P(font_alt, false);
};

void render_mod_shift(void) { // ⇧
    static const char PROGMEM font_shift[3] = {0xd3, 0xd4, 0};
    oled_write_P(font_shift, false);
};

void render_mod_gui(void) { // win symbol
    static const char PROGMEM font_gui[3] = {0x95, 0x96, 0};
    oled_write_P(font_gui, false);
};

void render_prompt(void) {
    bool blink = (timer_read() % 1000) < 500;
        if (layer_state_is(1)) {
            oled_write_ln_P(blink ? PSTR("> lo_") : PSTR("> lo "), false);
        } else if (layer_state_is(2)) {
            oled_write_ln_P(blink ? PSTR("> hi_") : PSTR("> hi "), false);
        } else if (layer_state_is(3)) {
            oled_write_ln_P(blink ? PSTR("> ad_") : PSTR("> ad "), false);
        } else {
            oled_write_ln_P(blink ? PSTR("> _ ") : PSTR(">     "), false);
        }
};

void render_mod_status(void) {
    bool blink = (timer_read() % 1000) < 500;
    uint8_t modifiers = get_mods() | get_oneshot_mods();
        if (modifiers & MOD_MASK_CTRL) {
            oled_write_ln_P(blink ? PSTR("$ ctl") : PSTR("$ _  "), false);
        } else if (modifiers & MOD_MASK_SHIFT) {
            oled_write_ln_P(blink ? PSTR("$ sft") : PSTR("$ _  "), false);
        } else if (modifiers & MOD_MASK_ALT) {
            oled_write_ln_P(blink ? PSTR("$ alt") : PSTR("$ _  "), false);
        } else if (modifiers & MOD_MASK_GUI) {
            oled_write_ln_P(blink ? PSTR("$ gui") : PSTR("$ _  "), false);
        } else {
            oled_write_ln_P(blink ? PSTR("$ _  ") : PSTR("$     "), false);
        }
}

void render_keylock_status(uint8_t led_usb_state) {
    bool blink = (timer_read() % 1000) < 500;
        if (led_usb_state & (1 << USB_LED_CAPS_LOCK)) {
            oled_write_ln_P(blink ? PSTR("% cap") : PSTR("% _  "), false);
        } else if (led_usb_state & (1 << USB_LED_NUM_LOCK)) {
            oled_write_ln_P(blink ? PSTR("% num") : PSTR("% _  "), false);
        } else if (led_usb_state & (1 << USB_LED_SCROLL_LOCK)) {
            oled_write_ln_P(blink ? PSTR("% scr") : PSTR("% _  "), false);
        } else {
            oled_write_ln_P(blink ? PSTR("% _  ") : PSTR("%     "), false);
        }
}

static char keylog_str[KEYLOG_LENGTH + 1] = {"\n"};
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }

    for (uint8_t i = (KEYLOG_LENGTH - 1); i > 0; --i) {
        keylog_str[i] = keylog_str[i - 1];
    }

    if (keycode < (sizeof(code_to_name) / sizeof(char))) {
        keylog_str[0] = pgm_read_byte(&code_to_name[keycode]);
    }

    log_timer = timer_read();
}

bool process_record_user_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
        add_keylog(keycode);
#endif
    }
    return true;
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

void render_main(void) {
    if (get_current_wpm() != 000) {
        oled_set_cursor(0, 0);
        render_wpm();
        oled_set_cursor(0, 3);
        render_qmk_logo();
        oled_set_cursor(0, 7);
        render_keyboard();
        oled_set_cursor(0, 9);
        render_prompt();
        oled_set_cursor(0, 11);
        render_mod_status();
        oled_set_cursor(0, 13);
        render_keylock_status(host_keyboard_leds());
        oled_set_cursor(1, 15);
        render_keylogger();
        oled_set_cursor(0, 15);
        render_keylogger_status();
    } else {
        oled_off();
    }
}

void oled_task_user(void) {
    if (is_master) {
        if (timer_elapsed32(oled_timer) > 30000) {
            oled_off();
            return;
        } else {
            oled_on();
        }
        render_main();
    } else {
        render_qmk_logo();
    }
}
