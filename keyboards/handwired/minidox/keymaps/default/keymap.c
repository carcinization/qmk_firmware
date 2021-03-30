#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum {
    MSLGUI,
    HAP_SAD,
    QMK,
    DOCS
};

enum combos {
  RU_ENT,
  GH_QUOT,
  VM_QUES,
  CM_DQUO,
  TY_COLN,
  BN_UNDS,
  FJ_MINS,
  DF_BTN1,
  JK_BTN2,
  VB_WHD,
  NM_WHU,
  SD_MSD,
  KL_MSU,
  XC_CLICK,
  ADJMD
};

//---layers---
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TGADJ TG(_ADJUST)
#define LWRSPC LT(_LOWER, KC_SPC)
//---general---
#define SFA SFT_T(KC_A)
#define SFCLN RSFT_T(KC_SCLN)
#define SFL SFT_T(KC_L)
#define SFEXM MT(MOD_LSFT, KC_F23)
#define SFPRN MT(MOD_RSFT, KC_F24)
#define ALTQ ALT_T(KC_Q)
#define ALTP ALT_T(KC_P)
//---mac---
#define MPSCR G(S(KC_4))
#define MACTAB G(KC_TAB)
#define CMDZ CMD_T(KC_Z)
#define CMDESC CMD_T(KC_ESC)
#define CMDSLSH CMD_T(KC_SLSH)
#define CMDS G(KC_S)
//---tap dance---
#define HAPSAD TD(HAP_SAD)
#define DOCSTD TD(DOCS)
#define QMKTD TD(QMK)
#define MSGTD TD(MSLGUI)
//---unicode---
#define ZHAP X(SIDE)
#define ARWUP X(UPAR)
#define STARX X(STAR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        ALTQ, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, ALTP,
        SFA, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SFCLN,
        CMDZ, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, CMDSLSH,
        LOWER, KC_SPC, KC_MS_L, KC_MS_R, KC_BSPC, RAISE
    ),
    [_LOWER] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        SFEXM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, SFPRN,
        CMDESC, KC_TAB, KC_CAPS, KC_TILD, KC_GRV, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_RGUI,
        KC_TRNS, KC_SPC, KC_LGUI, KC_PGUP, KC_VOLU, KC_MS_U
    ),
    [_RAISE] = LAYOUT(
        KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  RGB_HUI, RGB_M_G, RGB_M_P, RGB_MOD, RGB_TOG,
        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, RGB_HUD, RGB_M_SW, RGB_M_R, RGB_SAD, RGB_SAI,
        QMKTD, /*DOCSTD*/KC_TRNS, /*HAPSAD*/KC_TRNS, KC_TRNS, KC_TRNS/*ALT_TAB*/, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        KC_MS_D, KC_VOLD, KC_PGDN, KC_RALT, KC_BSPC, KC_TRNS
    )
};

const uint16_t PROGMEM ru_combo[] = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM vm_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM cm_combo[] = {KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM ty_combo[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM bn_combo[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM click_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM adj_combo[] = {KC_Q, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
[RU_ENT] = COMBO(ru_combo, KC_ENT),
[GH_QUOT] = COMBO(gh_combo, KC_QUOT),
[VM_QUES] = COMBO(vm_combo, KC_QUES),
[CM_DQUO] = COMBO(cm_combo, KC_DQUO),
[TY_COLN] = COMBO(ty_combo, KC_COLN),
[BN_UNDS] = COMBO(bn_combo, KC_UNDS),
[FJ_MINS] = COMBO(fj_combo, KC_MINS),
[DF_BTN1] = COMBO(df_combo, KC_BTN1),
[JK_BTN2] = COMBO(jk_combo, KC_BTN2),
[VB_WHD] = COMBO(vb_combo, KC_WH_D),
[NM_WHU] = COMBO(nm_combo, KC_WH_U),
[SD_MSD] = COMBO(sd_combo, KC_MS_D),
[KL_MSU] = COMBO(kl_combo, KC_MS_U),
[XC_CLICK] = COMBO_ACTION(click_combo),
[ADJMD] = COMBO_ACTION(adj_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case XC_CLICK:
        if (pressed) {
            SEND_STRING(SS_DOWN(X_TAB)SS_TAP(X_ENTER)SS_UP(X_TAB)SS_TAP(X_ENTER));
        }
        break;

    case ADJMD:
        if (pressed) {
            layer_on(_ADJUST);
        }
        break;
  }
}

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD
};

uint8_t cur_dance(qk_tap_dance_state_t *state);
void msgui_finished(qk_tap_dance_state_t *state, void *user_data);
void msgui_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8;
}

static tap msgui_tap_state = {
    .is_press_action = true,
    .state = 0
};

void msgui_finished(qk_tap_dance_state_t *state, void *user_data) {
    msgui_tap_state.state = cur_dance(state);
    switch (msgui_tap_state.state) {
        case SINGLE_TAP: register_code(KC_LGUI); break;
        case SINGLE_HOLD: register_code16(KC_MS_L); break;
        case DOUBLE_TAP: register_code(KC_LGUI); break;
        case DOUBLE_HOLD: register_code16(KC_MS_L); break;
        case DOUBLE_SINGLE_TAP: tap_code(KC_LGUI); register_code(KC_LGUI);
    }
}

void msgui_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (msgui_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_LGUI); break;
        case SINGLE_HOLD: unregister_code16(KC_MS_L); break;
        case DOUBLE_TAP: unregister_code(KC_LGUI); break;
        case DOUBLE_HOLD: unregister_code16(KC_MS_L);
        case DOUBLE_SINGLE_TAP: unregister_code(KC_LGUI);
    }
    msgui_tap_state.state = 0;
}

void dance_pep_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING(":widepeepohappy1"SS_TAP(X_ENTER)SS_TAP(X_BSPC)":widepeepohappy2"SS_TAP(X_ENTER)SS_TAP(X_BSPC)SS_TAP(X_ENTER));
    } else {
      SEND_STRING(":widepeeposad1"SS_TAP(X_ENTER)SS_TAP(X_BSPC)":widepeeposad2"SS_TAP(X_ENTER)SS_TAP(X_BSPC)SS_TAP(X_ENTER));
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
    [HAP_SAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_pep_finished, NULL),
    [QMK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_qmk_finished, NULL),
    [DOCS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_doc_finished, NULL),
    [MSLGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, msgui_finished, msgui_reset)
};
