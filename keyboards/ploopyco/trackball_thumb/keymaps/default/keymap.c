/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
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

// safe range starts at `PLOOPY_SAFE_RANGE` instead.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_LCTL, DF(1), KC_BTN1, KC_BTN3, KC_BTN2, KC_LSFT
    ),
      [1] = LAYOUT( /* Horizontal Scroll */
        KC_TRNS, DF(0),KC_TRNS,KC_TRNS,KC_TRNS,MO(2)
    ),
     [2] = LAYOUT( /* Horizontal Scroll */
        KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    )
};

enum combos {
DPI
};

const uint16_t PROGMEM dpi_combo[] = {DF(1), KC_LSFT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DPI] = COMBO(dpi_combo, DPI_CONFIG)
};
