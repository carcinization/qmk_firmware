#include QMK_KEYBOARD_H

//////////////////////////
//////////LAYERS//////////
//////////////////////////
#define _QWERTY 0
#define _FN 1
#define _FN2 2
//////////////////////////
//////////LAYERS//////////
//////////////////////////

/////////////////////////////
//////////SHORTCUTS//////////
/////////////////////////////
#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_SPCSHFT MT(MOD_LSFT, KC_SPC)
#define KC_FSQ LT(MO(4), KC_F)
#define KC_GO LT(MO(3), KC_ENT)
#define KC_CLNDNC TD(TD_COLONDANCE)
#define KC_DBLDSH TD(TD_DOUBLEDASH)
#define KC_LOCK LCTL(LGUI(KC_Q))
/////////////////////////////
//////////SHORTCUTS//////////
/////////////////////////////


//////////////////////////////////////////
//////////TAP DANCE DECLARATIONS//////////
//////////////////////////////////////////
enum {
  TD_CAD = 0,
  TD_ALTF4 = 1,
  TD_DOUBLEDASH = 2,
  TD_SUPACAPS = 3,
  TD_COLONDANCE = 4,
  TD_LOCK = 5,
  TD_CMDQ = 6,
};
//////////////////////////////////////////
//////////TAP DANCE DECLARATIONS//////////
//////////////////////////////////////////



enum custom_keycodes {
  SCRNSHT = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    TD(TD_CMDQ), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,                 KC_EQL, KC_NO, KC_NO,
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,                 KC_DEL, KC_NO, KC_NO,
    MT(_FN,KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, KC_RSFT,              KC_UP,
    TD(TD_LOCK), KC_LGUI, MO(2),                 KC_SPC,              MO(1), KC_LGUI, KC_RCTL,      KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_FN] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_VAI, RGB_HUI,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______, _______, RESET,
    _______, KC_BSLS, KC_LPRN, KC_RPRN, KC_COLON, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,_______, _______, _______
  ),

  [_FN2] = LAYOUT(
    SCRNSHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_VAI, RGB_HUI,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______, _______,
    _______, _______, _______, _______, _______, _______,_______, _______, _______, _______
  ),

};

void keyboard_post_init_user(void) {
  // rgblight_sethsv(180, 255, 255);
  rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
  // rgblight_setrgb(RGB_BLUE);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SCRNSHT:
      if (record->event.pressed) {
        // when keycode SCRNSHT is pressed
        register_code(KC_LGUI);
	register_code(KC_LSFT);
	register_code(KC_LCTL);
	register_code(KC_4);
	unregister_code(KC_LGUI);
	unregister_code(KC_LSFT);
	unregister_code(KC_LCTL);
	unregister_code(KC_4);
      } else {
        // when keycode is released
      }
      break;

  }
  return true;
};

/////////////////////////////////////////
//////////TAP DANCE DEFINITIONS//////////
/////////////////////////////////////////
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Nothin, twice for CTRLALTDEL
  [TD_CAD]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_CAD),
  //Tap once for esc, twice for Alt+F4
  [TD_ALTF4] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4)),
  //Tap once for dash, twice for underscore
  [TD_DOUBLEDASH] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
  //Tap once for noting, twice for Caps Lock
  [TD_SUPACAPS] = ACTION_TAP_DANCE_DOUBLE(KC_NO, KC_CAPS),
  //Tap once for semicolon, twice for colon
  [TD_COLONDANCE] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
  //Tap once for alt and twice for the osx lock combo(ctrl,cmd,q)
  [TD_LOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LOCK),
  //Tap once for ESC, twice for CMD + Q to quit app
  [TD_CMDQ] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, LGUI(KC_Q)),
// Other declarations would go here, separated by commas, if you have them
};
/////////////////////////////////////////
//////////TAP DANCE DEFINITIONS//////////
/////////////////////////////////////////