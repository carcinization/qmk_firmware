#pragma once
#include QMK_KEYBOARD_H
#include "wrappers.h"
#include "macros.c"
#ifdef TAP_DANCE_ENABLE
#include "tapdance.c"
#endif
#ifdef COMBO_ENABLE
#include "combos.c"
#endif
#ifdef OLED_DRIVER_ENABLE
#include "oled.c"
#endif

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
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
//---windows---
#define GPSCR G(KC_PSCR)
#define CTLZ CTL_T(KC_Z)
#define CTLESC CTL_T(KC_ESC)
#define CTLSLH CTL_T(KC_SLSH)
#define CTLDOT CTL_T(KC_DOT)
#define CTLS C(KC_S)
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
//---unicode---
#define ZHAP X(SIDE)
#define ARWUP X(UPAR)
#define STARX X(STAR)

void dance_pep_finished(qk_tap_dance_state_t*, void*);
void dance_qmk_finished(qk_tap_dance_state_t*, void*);
void dance_doc_finished(qk_tap_dance_state_t*, void*);
