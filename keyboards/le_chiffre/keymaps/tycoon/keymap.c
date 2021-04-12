#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUM_SYM,
  _NUMPAD
};

enum combos {
    combo_ESC,
    combo_BACK,
    combo_TAB,
    combo_DELETE,
    combo_ENTER,
    combo_QUOT,
    combo_LPRN,
    combo_RPRN
};

const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_P, KC_SCLN, COMBO_END};
const uint16_t PROGMEM lprn_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM rprn_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [combo_ESC] = COMBO(esc_combo, KC_ESC),
    [combo_BACK] = COMBO(bspc_combo, KC_BSPC),
    [combo_TAB] = COMBO(tab_combo, KC_TAB),
    [combo_DELETE] = COMBO(del_combo, KC_DEL),
    [combo_ENTER] = COMBO(enter_combo, KC_ENT),
    [combo_QUOT] = COMBO(quot_combo, KC_QUOT),
   	[combo_LPRN] = COMBO(lprn_combo, KC_LPRN),
    [combo_RPRN] = COMBO(rprn_combo, KC_RPRN)
};

#define BASE TO(_BASE)
#define NUM MO(_NUM_SYM)
#define NUMPAD TO(_NUMPAD)
#define xxx KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
   KC_Q, KC_W, KC_E, KC_R, KC_T,         NUMPAD,  KC_Y, KC_U, KC_I, KC_O, KC_P,
   KC_A, KC_S, KC_D, KC_F, KC_G,                  KC_H, KC_J, KC_K, KC_L, KC_SCLN,
   LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,          KC_N, KC_M, KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
                   KC_LCTL, NUM,                  KC_SPC, KC_RALT
  ),

  [_NUM_SYM] = LAYOUT(
    KC_1, KC_2, KC_3, KC_4, KC_5,              xxx,     KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_EXLM,  KC_AT, KC_HASH, KC_DLR, KC_PERC,          KC_CIRC,  KC_AMPR,  KC_ASTR, KC_MINS, KC_EQUAL,
    KC_LEFT,KC_DOWN, KC_UP, KC_RGHT, KC_HOME,           KC_END, KC_LEFT,KC_DOWN,  KC_UP,  KC_RGHT,
                                   xxx, xxx,            xxx,  xxx
  ),

  [_NUMPAD] = LAYOUT(
  	xxx, xxx, xxx, xxx, xxx, BASE, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PEQL,
  	xxx, xxx, xxx, xxx, xxx,       KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
  	xxx, xxx, xxx, xxx, xxx,       KC_PMNS, KC_P1, KC_P2, KC_P3, KC_PENT,
  	               xxx, xxx,       KC_P0, KC_PDOT
   ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}

void render_lechiffre_logo(void) {
    static const char PROGMEM lechiffre_logo[] = {
   0x00, 0x3e, 0x20, 0x20, 0x00, 0x18, 0x2c, 0xa8, 0x80, 0x00, 0x1c, 0x22, 0x22, 0x00, 0x3e, 0x08,
0x30, 0x00, 0x34, 0x00, 0x3c, 0x0a, 0x00, 0xbc, 0x8a, 0x00, 0x38, 0x08, 0x00, 0x18, 0x2c, 0x28,
0x00, 0xb6, 0xb6, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00,
0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xb6, 0xb6, 0x00,
0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00,
0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00
};

  oled_write_raw_P(lechiffre_logo, sizeof(lechiffre_logo));
}

static void render_layer_status(void) {
    oled_write_P(PSTR("-----"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _NUM_SYM:
            oled_write_ln_P(PSTR(" SYM"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
}

#    define KEYLOG_LEN 11
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

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

void render_keylogger_status(void) {
    oled_write_P(PSTR("-----"), false);
    oled_write(keylog_str, false);
}

void render_keylock_status(led_t led_state) {
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("C"), led_state.caps_lock);
  oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
  oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), led_state.scroll_lock);
}

void render_mod_status(uint8_t modifiers) {
       oled_write_P(PSTR("-----"), false);
    oled_write_ln_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_ln_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
    oled_write_ln_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));
    oled_write_ln_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
}

void oled_task_user(void) {
    render_lechiffre_logo();
    oled_set_cursor(0,3);
    render_layer_status();
  render_mod_status(get_mods()|get_oneshot_mods());
  render_keylock_status(host_keyboard_led_state());
  render_keylogger_status();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      add_keylog(keycode);
    }
    return true;
  }
#endif
