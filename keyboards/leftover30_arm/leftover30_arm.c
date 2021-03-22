/* Copyright 2020 TJ Campie @tominabox1
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
#include "leftover30_arm.h"

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(B10);
  setPinOutput(B11);
}

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   0, 1, 2, 3, 4, 5, 6, 7 }
}, {

  // LED Index to Physical Position
  { 0, 48 }, { 0, 64 }, { 20, 55 }, { 112, 64 }, { 202, 64 }, { 244, 64 }, { 244, 48 }, { 244, 20 },
}, {

  /* Utilize the following mask to turn on and off the spacebar LEDs.
   * use `2, 2, 4, 0, 0, 2, 2, 4` for off
   * or  `2, 2, 4, 2, 2, 2, 2, 4` for on
   */
  2, 2, 0, 0, 0, 2, 2, 0
} };
