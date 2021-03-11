#pragma once
#include "waffleus.h"
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define ________________CRKBDQWERTY1_______________ KC_TRNS, ALTQ, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, GPSCR
#define ________________CRKBDQWERTY2_______________ KC_TRNS, SFA, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SFCLN, KC_MPLY
#define ________________CRKBDQWERTY3_______________ KC_TRNS, CTLZ, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, CTLSLH, CTLS
#define ________________CRKBDQWERTY4_______________ KC_MS_L, LOWER, KC_SPC,    KC_BSPC, RAISE, KC_MS_R

#define ________________CRKBDLOWER1________________ KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MNXT
#define ________________CRKBDLOWER2________________ KC_SLCK, SFEXM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, SFPRN, KC_TRNS
#define ________________CRKBDLOWER3________________ KC_NLCK, CTLESC, KC_TAB, KC_CAPS, KC_TILD, KC_GRV, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_RCTL, KC_MRPV
#define ________________CRKBDLOWER4________________ KC_LGUI, KC_TRNS, KC_SPC, KC_VOLU, KC_MS_U, KC_PGUP

#define ________________CRKBDRAISE1________________ UC_M_WC, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CG_SWAP
#define ________________CRKBDRAISE2________________ UC_M_MA, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASSOFF, KC_TRNS, CG_NORM
#define ________________CRKBDRAISE3________________ UC_M_LN, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CMB_TOG
#define ________________CRKBDRAISE4________________ KC_PGDN, KC_MS_D, KC_VOLD, KC_BSPC, KC_TRNS, KC_RALT
