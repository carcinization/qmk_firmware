#pragma once
#include QMK_KEYBOARD_H
#include "wrappers.h"
#include "tapdance.h"

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
//---windows/linux---
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
#define MSGTD TD(MSLGUI)

