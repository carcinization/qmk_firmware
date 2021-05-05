/* Copyright 2021 @waffle#6666
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

#pragma once
#include "waffleus.h"
#define LAYOUT_waffle(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_waffle_corne(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_waffle_all(...) LAYOUT_all(__VA_ARGS__)
#define LAYOUT_waffle_yoink(...) LAYOUT_split_bar(__VA_ARGS__)

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

#define ________________CRKBDQWERTY1_______________ QMKTD, ALTQ, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, ALTP, KC_MNXT
#define ________________CRKBDQWERTY2_______________ ALT_TAB, SFA, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SFCLN, KC_MPLY
#define ________________CRKBDQWERTY3_______________ CP_PSTE, CTLZ, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, CTLSLH, KC_MPRV
#define ________________CRKBDQWERTY4_______________ MSLGTD, LOWER, KC_SPC, KC_BSPC, RAISE, CLIPST

#define ________________CRKBDLOWER1________________ DOCSTD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, GPSCR
#define ________________CRKBDLOWER2________________ KC_SLCK, SFEXM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, SFPRN, MAKE
#define ________________CRKBDLOWER3________________ KC_NLCK, CTLESC, KC_TAB, KC_CAPS, KC_TILD, KC_GRV, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_RCTL, HAPSAD
#define ________________CRKBDLOWER4________________ KC_LGUI, KC_TRNS, KC_SPC, KC_VOLU, KC_MS_U, KC_PGUP

#define ________________CRKBDRAISE1________________ UC_M_WC, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  CG_NORM, CG_SWAP, STARX, TABLE1, TABLE2, ROFL
#define ________________CRKBDRAISE2________________ UC_M_MA, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_ASON, KC_ASOFF, KC_TRNS, KC_TRNS, KC_TRNS, RWORD
#define ________________CRKBDRAISE3________________ UC_M_LN, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, ADJUST
#define ________________CRKBDRAISE4________________ KC_PGDN, KC_MS_D, KC_VOLD, KC_BSPC, KC_TRNS, KC_RALT

#define _______________CRKBDADJUST1________________ RGB_TOG, RGB_M_P, RGB_M_G, RGB_HUD, RGB_HUI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET
#define _______________CRKBDADJUST2________________ RGB_MOD, RGB_M_B, CYAN, RGB_SAD, RGB_SAI, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define _______________CRKBDADJUST3________________ RGB_RMOD, RGB_M_R, RGB_M_SW, RGB_VAD, RGB_VAI, RGBRST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define _______________CRKBDADJUST4________________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

/*
███╗   ███╗██╗ ██████╗██████╗  ██████╗ ██████╗  ██████╗ ██╗  ██╗
████╗ ████║██║██╔════╝██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗╚██╗██╔╝
██╔████╔██║██║██║     ██████╔╝██║   ██║██║  ██║██║   ██║ ╚███╔╝
██║╚██╔╝██║██║██║     ██╔══██╗██║   ██║██║  ██║██║   ██║ ██╔██╗
██║ ╚═╝ ██║██║╚██████╗██║  ██║╚██████╔╝██████╔╝╚██████╔╝██╔╝ ██╗
╚═╝     ╚═╝╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝
*/

#define ________________MDOXQWERTY1________________ ALTQ, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, ALTP
#define ________________MDOXQWERTY2________________ SFA, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SFCLN
#define ________________MDOXQWERTY3________________ CMDZ, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, CMDSLSH
#define ________________MDOXQWERTY4________________ LOWER, KC_SPC, KC_MS_L, KC_MS_R, KC_BSPC, RAISE

#define ________________MDOXLOWER1________________ KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0
#define ________________MDOXLOWER2________________ SFEXM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, SFPRN
#define ________________MDOXLOWER3________________ CMDESC, KC_TAB, KC_CAPS, KC_TILD, KC_GRV, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_RGUI
#define ________________MDOXLOWER4________________ KC_TRNS, KC_SPC, KC_LGUI, KC_PGUP, KC_VOLU, KC_MS_U

#define ________________MDOXRAISE1________________ KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  RGB_HUI, RGB_M_G, RGB_M_P, RGB_MOD, RGB_TOG
#define ________________MDOXRAISE2________________ KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, RGB_HUD, RGB_M_SW, RGB_M_R, RGB_SAD, RGB_SAI
#define ________________MDOXRAISE3________________ QMKTD, DOCSTD, HAPSAD, KC_TRNS, MACTAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define ________________MDOXRAISE4________________ KC_MS_D, KC_VOLD, KC_PGDN, KC_RALT, KC_BSPC, KC_TRNS

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
#define ______________DEFAULTQWERTY3_______________ CTLZ, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, CTLDOT//, CTLSLH

#define ______________DEFAULTLOWER1_______________ KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0
#define ______________DEFAULTLOWER2_______________ SFEXM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, SFPRN
#define ______________DEFAULTLOWER3_______________ CTLESC, KC_TAB, KC_CAPS, KC_TILD, KC_GRV, KC_LEFT, KC_UP, KC_DOWN, CTLRGHT//, KC_LCTL

#define ______________DEFAULTRAISE1_______________ KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_TOG
#define ______________DEFAULTRAISE2_______________ KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, RGB_M_SW, RGB_VAD, RGB_VAI, RGB_RMOD, RGB_RMOD
#define ______________DEFAULTRAISE3_______________ QMKTD, DOCSTD, HAPSAD, STARX, ZHAP, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
