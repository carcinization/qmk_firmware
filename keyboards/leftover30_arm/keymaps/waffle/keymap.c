/* Copyright 2020 marksard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum layer_number {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum {
    QMK,
    DOCS,
    ATQ,
};

enum custom_keycodes {
    KANJI = SAFE_RANGE,
    ALT_TAB,
    RGBRST,
    SPONGE
};

enum combos {
  RU_ENT,
  GH_QUOT,
  VM_QUES,
  CM_DQUO,
  TY_COLN,
  BN_UNDS,
  XC_CLICK
};

#define LWRSPC LT(_LOWER, KC_SPC)
#define ADJPLY LT(_ADJUST, KC_MPLY)
#define RAISE MO(_RAISE)
#define SFA SFT_T(KC_A)
#define CTLSLSH CTL_T(KC_SLSH)
#define SFEXM MT(MOD_LSFT, KC_F23)
#define SFPRN MT(MOD_RSFT, KC_F24)
#define CTLESC CTL_T(KC_ESC)
#define CTLZ CTL_T(KC_Z)
#define SFL SFT_T(KC_L)
#define QMKTD TD(QMK)
#define DOCSTD TD(DOCS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, QMKTD,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               SFA,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    SFL,     KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               CTLZ, KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,     CTLSLSH,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      ADJPLY, KC_LGUI,                                LWRSPC,                                KC_SCLN, RAISE
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_LOWER] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
               KC_1,   KC_2,   KC_3,   KC_4,   KC_5, KC_6,  KC_7, KC_8, KC_9, KC_0, DOCSTD,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_EXLM,   KC_AT,   KC_HASH,   KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,     KC_RPRN,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               CTLESC, KC_TAB, KC_CAPS, KC_TILD, KC_GRV, KC_LEFT,  KC_UP,   KC_DOWN, KC_RGHT,     KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      KC_MUTE, KC_SCLN,                                KC_TRNS,                                 KC_RALT, KC_SLSH
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_RAISE] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
               KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,    CG_NORM,   KC_ASUP,    KC_ASON, _______,  _______, ALT_TAB,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,    CG_SWAP,   KC_ASDN,   KC_ASOFF, _______,  _______,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_F1, KC_F2,     KC_F3,   KC_F4,   KC_F5,      KC_F6, KC_F7,  KC_F8, KC_F9,     KC_F11,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, KC_LCTL,                                KC_SPC,                                 KC_RCTL, _______
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
                RGB_TOG,  RGB_HUI, RGB_HUD, _______, _______, _______, _______, _______,  _______,  _______, RESET,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               RGB_MOD, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, _______,     _______,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               RGBRST, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______,     _______,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      KC_TRNS, _______,                                _______,                                 _______, _______
  //`-----------------------------------------------------------------------------------------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LWRSPC:
            return TAPPING_TERM - 38;
        case ADJPLY:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    case KANJI:
      if (record->event.pressed) {
          register_code16(keymap_config.swap_lalt_lgui ? A(KC_GRV) : KC_LANG2);
      } else {
          unregister_code16(keymap_config.swap_lalt_lgui ? A(KC_GRV) : KC_LANG2);
      }
    break;

    case ALT_TAB:
        if (record->event.pressed) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            register_code(KC_TAB);
        } else {
            unregister_code(KC_TAB);
        }
        break;

#ifdef RGBLIGHT_ENABLE
    case RGBRST:
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
    break;
#endif
    default:
      result = true;
      break;
  }

  return result;
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_CYAN);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left encoder
        if (IS_LAYER_ON(_ADJUST)) {
            tap_code((clockwise == true) ? KC_LEFT : KC_RGHT);
        } else if (IS_LAYER_ON(_LOWER)) {
          tap_code((clockwise == true) ? KC_MNXT : KC_MPRV);
        } else if (IS_LAYER_ON(_RAISE)) {
          tap_code((clockwise == true) ? KC_PGDN : KC_PGUP);
        } else {
          tap_code((clockwise == true) ? KC_VOLU : KC_VOLD);
        }
    }
}

// for exsample customize of LED inducator
bool led_update_user(led_t led_state) {
    writePin(B10, IS_LAYER_ON(_LOWER));
    writePin(B11, IS_LAYER_ON(_RAISE));
    return false;
}

const uint16_t PROGMEM ru_combo[] = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM vm_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM cm_combo[] = {KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM ty_combo[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM bn_combo[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM click_combo[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
[RU_ENT] = COMBO(ru_combo, KC_ENT),
[GH_QUOT] = COMBO(gh_combo, KC_QUOT),
[VM_QUES] = COMBO(vm_combo, KC_QUES),
[CM_DQUO] = COMBO(cm_combo, KC_DQUO),
[TY_COLN] = COMBO(ty_combo, KC_COLN),
[BN_UNDS] = COMBO(bn_combo, KC_UNDS),
[XC_CLICK] = COMBO_ACTION(click_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case XC_CLICK:
            if (pressed) {
                SEND_STRING(SS_DOWN(X_TAB)SS_TAP(X_ENTER)SS_UP(X_TAB)SS_TAP(X_ENTER));
            }
            break;
    }
}

void dance_qmk_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("https://github.com/qmk/qmk_firmware/find/master"SS_TAP(X_ENTER));
    } else {
      SEND_STRING("https://config.qmk.fm/#/"SS_TAP(X_ENTER));
    }
}

void dance_doc_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("https://docs.qmk.fm/#/newbs_getting_started");
    } else {
      SEND_STRING("https://docs.qmk.fm/#/driver_installation_zadig");
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [QMK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_qmk_finished, NULL),
    [DOCS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_doc_finished, NULL),
};

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}
