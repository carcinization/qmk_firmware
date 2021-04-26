#pragma once
#include QMK_KEYBOARD_H
#include "wrappers.h"
#include "tapdance.h"
#include "combos.h"
#include "pru.h"
#ifdef RGBLIGHT_ENABLE
#include "rgb.h"
#endif
#ifdef OLED_DRIVER_ENABLE
#include "oled.h"
#endif
//#include "secrets.h"

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#ifdef UNICODEMAP_ENABLE
enum unicodemap_names {
    SIDE,
    UPAR,
    HAS,
    STAR,
    VIB
};

enum typing_mode {
    TM_NOMODE,
    TM_REGIONAL,
    TM_WIDE,
    TM_BLOCKS,
    TM_FANCY,
    TM_AUSSIE,
    TM_ZALGO,
};
#endif 

//---layers---
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
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
//---linux/windows---
#define GPSCR G(KC_PSCR)
#define CTLZ CTL_T(KC_Z)
#define CTLESC CTL_T(KC_ESC)
#define CTLSLH CTL_T(KC_SLSH)
#define CTLDOT CTL_T(KC_DOT)
#define CTLS C(KC_S)
#define CTLRGHT CTL_T(KC_RIGHT)
//---mac---
#define MPSCR G(S(KC_4))
#define MACTAB G(KC_TAB)
#define CMDZ CMD_T(KC_Z)
#define CMDESC CMD_T(KC_ESC)
#define CMDSLSH CMD_T(KC_SLSH)
#define CMDS G(KC_S)
#define CMDRGHT CMD_T(KC_RIGHT)
//---tap dance---
#define HAPSAD TD(HAP_SAD)
#define DOCSTD TD(DOCS)
#define QMKTD TD(QMK)
#define MSLGTD TD(MSLGUI)
//---unicode---
#define ZHAP X(SIDE)
#define ARWUP X(UPAR)
#define STARX X(STAR)
