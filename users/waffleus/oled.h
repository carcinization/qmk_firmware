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
#include "quantum.h"
#include "oled_driver.h"
#define WPM "WPM:"
bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);
#define BONGO_IDLE_FRAMES 5
#define BONGO_SIZE 512
#define BONGO_TAP_FRAMES 2
#define BONGO_IDLE_SPEED 30
#define BONGO_TAP_SPEED 40
#define BONGO_FELIX_FRAME_DURATION 200
#define FELIX_SIZE 96
#define MIN_WALK_SPEED 30
#define MIN_RUN_SPEED 45
#define LAYER_FRAME_DURATION 250
#define LAYER_TAP_FRAMES 3
#define LAYER_SIZE 520
#define XANIM_SIZE 650
#define FLOWER_FRAMES 7
#define FLOWER_SIZE 512
#define GROW_RATE 300
#define KEYLOG_LEN 5
