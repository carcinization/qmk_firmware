#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUM,
  _NAV,
  _SFT
};
enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
};

#define KC_SZ LSFT_T(KC_Z)
#define KC_SD RSFT_T(KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,
    KC_A,  KC_S,  KC_D,  KC_F,   KC_G,   KC_H,  KC_J,   KC_K,  KC_L, KC_QUOT,
    KC_SZ,   KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M, KC_COMM, KC_SD,
    KC_LCTL, KC_LALT, KC_DEL, LT(_NUM,KC_SPC), KC_SPC, TT(_NAV), TT(_SFT), KC_ENT
  ),

  [_NUM] = LAYOUT_split_space(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_SCLN, KC_QUOT,
    KC_CAPS, KC_LBRC, KC_RBRC, KC_BSLS, KC_COLN, KC_LPRN, KC_RPRN, KC_SLSH, LSFT_T(KC_ENT),
    RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
   [_NAV] = LAYOUT_split_space(
    KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NO, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS,
    KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_MINS,
    KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO,
    RGB_TOG, RGB_MOD, RGB_RMOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS
  ),
    [_SFT] = LAYOUT_split_space(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DQUO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUES, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_E, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc, KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),

};
#endif
