#pragma once
#include "waffleus.h"
#define LAYOUT_waffle_qaz(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_waffle_ortho(...) LAYOUT_ortho_4x12(__VA_ARGS__)

/*
          _____                    _____                    _____                    _____                    _____
         /\    \                  /\    \                  /\    \                  /\    \                  /\    \
        /::\    \                /::\    \                /::\____\                /::\    \                /::\    \
       /::::\    \              /::::\    \              /:::/    /               /::::\    \              /::::\    \
      /::::::\    \            /::::::\    \            /:::/    /               /::::::\    \            /::::::\    \
     /:::/\:::\    \          /:::/\:::\    \          /:::/    /               /:::/\:::\    \          /:::/\:::\    \
    /:::/  \:::\    \        /:::/__\:::\    \        /:::/____/               /:::/__\:::\    \        /:::/  \:::\    \
   /:::/    \:::\    \      /::::\   \:::\    \      /::::\    \              /::::\   \:::\    \      /:::/    \:::\    \
  /:::/    / \:::\    \    /::::::\   \:::\    \    /::::::\____\________    /::::::\   \:::\    \    /:::/    / \:::\    \
 /:::/    /   \:::\    \  /:::/\:::\   \:::\____\  /:::/\:::::::::::\    \  /:::/\:::\   \:::\ ___\  /:::/    /   \:::\ ___\
/:::/____/     \:::\____\/:::/  \:::\   \:::|    |/:::/  |:::::::::::\____\/:::/__\:::\   \:::|    |/:::/____/     \:::|    |
\:::\    \      \::/    /\::/   |::::\  /:::|____|\::/   |::|~~~|~~~~~     \:::\   \:::\  /:::|____|\:::\    \     /:::|____|
 \:::\    \      \/____/  \/____|:::::\/:::/    /  \/____|::|   |           \:::\   \:::\/:::/    /  \:::\    \   /:::/    /
  \:::\    \                    |:::::::::/    /         |::|   |            \:::\   \::::::/    /    \:::\    \ /:::/    /
   \:::\    \                   |::|\::::/    /          |::|   |             \:::\   \::::/    /      \:::\    /:::/    /
    \:::\    \                  |::| \::/____/           |::|   |              \:::\  /:::/    /        \:::\  /:::/    /
     \:::\    \                 |::|  ~|                 |::|   |               \:::\/:::/    /          \:::\/:::/    /
      \:::\    \                |::|   |                 |::|   |                \::::::/    /            \::::::/    /
       \:::\____\               \::|   |                 \::|   |                 \::::/    /              \::::/    /
        \::/    /                \:|   |                  \:|   |                  \::/____/                \::/____/
         \/____/                  \|___|                   \|___|                   ~~                       ~~
*/

#define ________________CRKBDQWERTY1_______________ QMKTD, ALTQ, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, GPSCR
#define ________________CRKBDQWERTY2_______________ ALT_TAB, SFA, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SFCLN, KC_MPLY
#define ________________CRKBDQWERTY3_______________ CP_PSTE, CTLZ, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, CTLSLH, CTLS
#define ________________CRKBDQWERTY4_______________ KC_MS_L, LOWER, KC_SPC,    KC_BSPC, RAISE, KC_MS_R

#define ________________CRKBDLOWER1________________ DOCSTD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MNXT
#define ________________CRKBDLOWER2________________ KC_SLCK, SFEXM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, SFPRN, MAKE
#define ________________CRKBDLOWER3________________ KC_NLCK, CTLESC, KC_TAB, KC_CAPS, KC_TILD, KC_GRV, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_RCTL, KC_MPRV
#define ________________CRKBDLOWER4________________ KC_LGUI, KC_TRNS, KC_SPC, KC_VOLU, KC_MS_U, KC_PGUP

#define ________________CRKBDRAISE1________________ UC_M_WC, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_NOMODE, KC_BLOCKS, KC_AUSSIE, KC_ASON, UNIT2, CG_SWAP
#define ________________CRKBDRAISE2________________ UC_M_MA, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_WIDE,   KC_SCRIPT, KC_REGIONAL, KC_ASOFF, WEEB, CG_NORM
#define ________________CRKBDRAISE3________________ UC_M_LN, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,           UNIT,      UNIT3,     UNIT4, RWORD, SPONG, CMB_TOG
#define ________________CRKBDRAISE4________________ KC_PGDN, KC_MS_D, KC_VOLD, KC_BSPC, KC_TRNS, KC_RALT

#define _______________CRKBDADJUST1________________ RGB_TOG, RGB_M_P, RGB_M_G, RGB_HUD, RGB_HUI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TGADJ
#define _______________CRKBDADJUST2________________ RGB_MOD, RGB_M_B, RGB_M_K, RGB_SAD, RGB_SAI, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define _______________CRKBDADJUST3________________ RGB_RMOD, RGB_M_R, RGB_M_SW, RGB_VAD, RGB_VAI, RGBRST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define _______________CRKBDADJUST4________________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

/*
________/\\\_______        _____/\\\\\\\\\____        __/\\\\\\\\\\\\\\\_
 _____/\\\\/\\\\____        ___/\\\\\\\\\\\\\__        _\////////////\\\__
  ___/\\\//\////\\\__        __/\\\/////////\\\_        ___________/\\\/___
   __/\\\______\//\\\_        _\/\\\_______\/\\\_        _________/\\\/_____
    _\//\\\______/\\\__        _\/\\\\\\\\\\\\\\\_        _______/\\\/_______
     __\///\\\\/\\\\/___        _\/\\\/////////\\\_        _____/\\\/_________
      ____\////\\\//_____        _\/\\\_______\/\\\_        ___/\\\/___________
       _______\///\\\\\\__        _\/\\\_______\/\\\_        __/\\\\\\\\\\\\\\\_
        _________\//////___        _\///________\///__        _\///////////////__
*/

#define ________________QAZQWERTY1_________________ ALTQ, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, ALTP
#define ________________QAZQWERTY2_________________ SFA, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, SFL, KC_BSPC
#define ________________QAZQWERTY3_________________ CTLZ, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, CTLDOT
#define ___________QAZQWERTY4_BIGSPACE_____________ QMKTD, KC_LGUI, LWRSPC, KC_RALT, RAISE
#define ___________QAZQWERTY4_SPLITSPACE___________ QMKTD, KC_LALT, KC_LGUI, LWRSPC, RAISE, KC_RGUI, KC_RALT, DOCSTD

#define _________________QAZLOWER1_________________ KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0
#define _________________QAZLOWER2_________________ SFEXM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, SFPRN
#define _________________QAZLOWER3_________________ CTLESC, KC_TAB, KC_CAPS, KC_TILD, KC_GRV, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT
#define ___________QAZLOWER4_BIGSPACE______________ KC_SCLN, KC_LGUI, KC_TRNS, KC_RGUI, KC_SLSH,
#define ___________QAZLOWER4_SPLITSPACE____________ HAPSAD, KC_LALT, KC_LGUI, KC_TRNS, KC_SLSH, KC_RGUI, KC_RALT, /*WEEB*/KC_TRNS

#define _________________QAZRAISE1_________________ KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, /*KC_SCRIPT, KC_BLOCKS, KC_WIDE, KC_AUSSIE, KC_NOMODE*/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define _________________QAZRAISE2_________________ KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_TOG
#define _________________QAZRAISE3_________________ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9
#define ____________QAZRAISE4_BIGSPACE_____________ KC_SCLN, KC_LGUI, /*UNIT*/KC_TRNS, KC_RALT, KC_TRNS
#define ____________QAZRAISE4_SPLITSPACE___________ /*UNIT*/KC_TRNS, /*UNIT2*/KC_TRNS, KC_LGUI, KC_SCLN, KC_TRNS, KC_RGUI, /*UNIT3*/KC_TRNS, /*UNIT4*/KC_TRNS

/*
███╗   ███╗██╗ ██████╗██████╗  ██████╗ ██████╗  ██████╗ ██╗  ██╗
████╗ ████║██║██╔════╝██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗╚██╗██╔╝
██╔████╔██║██║██║     ██████╔╝██║   ██║██║  ██║██║   ██║ ╚███╔╝
██║╚██╔╝██║██║██║     ██╔══██╗██║   ██║██║  ██║██║   ██║ ██╔██╗
██║ ╚═╝ ██║██║╚██████╗██║  ██║╚██████╔╝██████╔╝╚██████╔╝██╔╝ ██╗
╚═╝     ╚═╝╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝
*/


/*
   ___    ___    ____   __  ___   ____        ____
  / _ \  / _ \  /  _/  /  |/  /  / __/ ____  / __/
 / ___/ / , _/ _/ /   / /|_/ /  / _/  /___/ / _/
/_/    /_/|_| /___/  /_/  /_/  /___/       /___/
*/

/*
                                               tttt
                                            ttt:::t
                                            t:::::t
                                            t:::::t
    eeeeeeeeeeee  xxxxxxx      xxxxxxxttttttt:::::ttttttt   rrrrr   rrrrrrrrr   aaaaaaaaaaaaa
  ee::::::::::::ee x:::::x    x:::::x t:::::::::::::::::t   r::::rrr:::::::::r  a::::::::::::a
 e::::::eeeee:::::eex:::::x  x:::::x  t:::::::::::::::::t   r:::::::::::::::::r aaaaaaaaa:::::a
e::::::e     e:::::e x:::::xx:::::x   tttttt:::::::tttttt   rr::::::rrrrr::::::r         a::::a
e:::::::eeeee::::::e  x::::::::::x          t:::::t          r:::::r     r:::::r  aaaaaaa:::::a
e:::::::::::::::::e    x::::::::x           t:::::t          r:::::r     rrrrrrraa::::::::::::a
e::::::eeeeeeeeeee     x::::::::x           t:::::t          r:::::r           a::::aaaa::::::a
e:::::::e             x::::::::::x          t:::::t    ttttttr:::::r          a::::a    a:::::a
e::::::::e           x:::::xx:::::x         t::::::tttt:::::tr:::::r          a::::a    a:::::a
 e::::::::eeeeeeee  x:::::x  x:::::x        tt::::::::::::::tr:::::r          a:::::aaaa::::::a
  ee:::::::::::::e x:::::x    x:::::x         tt:::::::::::ttr:::::r           a::::::::::aa:::a
    eeeeeeeeeeeeeexxxxxxx      xxxxxxx          ttttttttttt  rrrrrrr            aaaaaaaaaa  aaaa
*/

#define ______________DEFAULTQWERTY1_______________ ALTQ, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, ALTP
#define ______________DEFAULTQWERTY2_______________ SFA, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, SFL, KC_BSPC
#define ______________DEFAULTQWERTY3_______________ CTLZ, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, CTLDOT

#define ______________DEFAULTLOWER1_______________ KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0
#define ______________DEFAULTLOWER2_______________ SFEXM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, SFPRN
#define ______________DEFAULTLOWER3_______________ CTLESC, KC_TAB, KC_CAPS, KC_TILD, KC_GRV, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_LCTL

#define ______________DEFAULTRAISE1_______________ KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS
#define ______________DEFAULTRAISE2_______________ KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE
#define ______________DEFAULTRAISE3_______________ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
