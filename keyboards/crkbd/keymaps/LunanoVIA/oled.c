/* Copyright 2021 @Itswaffle/@waffle#6666
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
#include <stdio.h>
#define LUNA
#define BONGO
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 0;
uint8_t current_frame = 0;
bool anim_phase = false;
#define LAYER_FRAME_DURATION 250
#define LAYER_TAP_FRAMES 3
uint8_t get_current_wpm(void);
#ifdef LUNA
#define MIN_WALK_SPEED 30
#define MIN_RUN_SPEED 45
#define ANIM_SIZE 96
#define ANIM_FRAME_DURATION 200
int current_wpm = 0;
led_t led_usb_state;
bool isSneaking = false;
bool isJumping = false;
bool isBarking = false;
bool showedJump = true;
#endif
#ifdef BONGO
#define IDLE_FRAMES 5
#define IDLE_SPEED 30
#define TAP_FRAMES 2
#define TAP_SPEED 45
#define BONGO_ANIM_SIZE 512
static long int oled_timeout = 60;
#endif

static void render_bongo(void) {

    // Idle animation
    static const char PROGMEM idle[IDLE_FRAMES][BONGO_ANIM_SIZE] = {

        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,16,8,8,4,4,4,8,48,64,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,100,130,2,2,2,2,2,1,0,0,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,192,193,193,194,4,8,16,32,64,128,0,0,0,128,128,128,128,64,64,
            64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,56,4,3,0,0,0,0,0,0,0,12,12,12,13,1,0,64,160,33,34,18,17,17,17,9,8,8,8,8,4,4,8,8,16,16,16,16,16,17,15,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,128,64,64,64,64,64,32,32,32,32,32,16,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,1,1,1,2,2,4,4,8,8,8,8,8,7,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        },

        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,16,8,8,4,4,4,8,48,64,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,100,130,2,2,2,2,2,1,0,0,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,192,193,193,194,4,8,16,32,64,128,0,0,0,128,128,128,128,64,64,
            64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,56,4,3,0,0,0,0,0,0,0,12,12,12,13,1,0,64,160,33,34,18,17,17,17,9,8,8,8,8,4,4,8,8,16,16,16,16,16,17,15,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,128,64,64,64,64,64,32,32,32,32,32,16,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,1,1,1,2,2,4,4,8,8,8,8,8,
            7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        },

        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,64,64,64,64,32,32,32,32,16,8,4,2,2,4,24,96,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,194,1,1,2,2,4,4,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,96,96,0,129,130,130,132,8,16,32,64,128,0,0,0,0,128,128,128,128,64,64,64,64,32,
            32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,112,25,6,0,0,0,0,0,0,0,24,24,24,27,3,0,64,160,34,36,20,18,18,18,11,8,8,8,8,5,5,9,9,16,16,16,16,16,17,15,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,128,64,64,64,64,64,32,32,32,32,32,16,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,1,1,1,2,2,4,4,8,8,8,8,8,7,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        },

        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,8,4,2,1,1,2,12,48,64,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,225,0,0,1,1,2,2,1,0,0,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,192,193,193,194,4,8,16,32,64,128,0,0,0,128,128,128,128,64,64,
            64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,112,12,3,0,0,0,0,0,0,0,12,12,12,13,1,0,64,160,33,34,18,17,17,17,9,8,8,8,8,4,4,8,8,16,16,16,16,16,17,15,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,128,64,64,64,64,64,32,32,32,32,32,16,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,1,1,1,2,2,4,4,8,8,8,8,8,
            7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        },

        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,8,8,4,2,2,2,4,56,64,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,226,1,1,2,2,2,2,1,0,0,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,192,193,193,194,4,8,16,32,64,128,0,0,0,128,128,128,128,64,64,64,64,
            32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,112,12,3,0,0,0,0,0,0,0,12,12,12,13,1,0,64,160,33,34,18,17,17,17,9,8,8,8,8,4,4,8,8,16,16,16,16,16,17,15,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,128,64,64,64,64,64,32,32,32,32,32,16,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,1,1,1,2,2,4,4,8,8,8,8,8,7,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        }

    };

    // Prep animation
    static const char PROGMEM prep[][BONGO_ANIM_SIZE] = {

        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,8,4,2,1,1,2,12,48,64,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,225,0,0,1,1,2,2,129,128,128,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,0,1,225,26,6,9,49,53,1,138,124,0,0,128,128,128,128,64,64,
            64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,112,12,3,0,0,24,6,5,152,153,132,195,124,65,65,64,64,32,33,34,18,17,17,17,9,8,8,8,8,4,4,4,4,4,4,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,128,64,64,64,64,64,32,32,32,32,32,16,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        }

    };

    // Typing animation
    static const char PROGMEM tap[TAP_FRAMES][BONGO_ANIM_SIZE] = {

        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,8,4,2,1,1,2,12,48,64,128,0,0,0,0,0,0,0,248,248,248,248,0,0,0,0,0,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,225,0,0,1,1,2,2,129,128,128,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,0,1,1,2,4,8,16,32,67,135,7,1,0,184,188,190,159,
            95,95,79,76,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,112,12,3,0,0,24,6,5,152,153,132,67,124,65,65,64,64,32,33,34,18,17,17,17,9,8,8,8,8,4,4,8,8,16,16,16,16,16,17,15,1,61,124,252,252,252,252,252,60,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,128,64,64,64,64,64,32,32,32,32,32,16,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,
            1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        },

        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,8,4,2,1,1,2,12,48,64,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,225,0,0,1,1,2,2,1,0,0,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,0,1,225,26,6,9,49,53,1,138,124,0,0,128,128,128,128,64,64,64,64,32,
            32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,112,12,3,0,0,0,0,0,0,0,0,0,0,1,1,0,64,160,33,34,18,17,17,17,9,8,8,8,8,4,4,4,4,4,4,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,128,64,64,64,64,64,32,32,32,32,32,16,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,122,122,121,121,121,121,57,49,2,2,4,4,8,8,8,136,136,135,128,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        }

    };

    void animation_phase(void) {

        if (get_current_wpm() <=IDLE_SPEED) {
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], BONGO_ANIM_SIZE);
        }

        if (get_current_wpm() >IDLE_SPEED && get_current_wpm() <TAP_SPEED) {
            oled_write_raw_P(prep[0], BONGO_ANIM_SIZE);
        }

        if (get_current_wpm() >=TAP_SPEED) {
            current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
            oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], BONGO_ANIM_SIZE);
        }
    }

    if (get_current_wpm() != 000) {
        oled_on();

        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }

        anim_sleep = timer_read32();
    } else {
        if (timer_elapsed32(anim_sleep) > oled_timeout) {
            oled_off();
        } else {
            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}
  

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return 2;
    } else {
        return 3;
    }
    return rotation;
}



void render_wpm(void) {
    char wpm_string[5];
        oled_write_ln("WPM:", false);
        snprintf(wpm_string,
    sizeof(wpm_string), " %3d",
    get_current_wpm());
        oled_write(wpm_string, false);
};



void animation_run(void) {
	if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
		oled_off();
	} else {
		if(timer_elapsed32(anim_timer) > LAYER_FRAME_DURATION) {
			anim_timer = timer_read32();
			anim_phase = true;
			}
		}
}

void render_keylock_status(uint8_t led_usb_state) {
    bool blink = (timer_read() % 1000) < 500;
        if (led_usb_state & (1 << USB_LED_CAPS_LOCK)) {
            oled_write_ln_P(blink ? PSTR("%cap_") : PSTR("%cap "), false);
        } else if (led_usb_state & (1 << USB_LED_NUM_LOCK)) {
            oled_write_ln_P(blink ? PSTR("%num_") : PSTR("%num "), false);
        } else if (led_usb_state & (1 << USB_LED_SCROLL_LOCK)) {
            oled_write_ln_P(blink ? PSTR("%scr_") : PSTR("%scr "), false);
        } else {
            oled_write_ln_P(blink ? PSTR("%_   ") : PSTR("%     "), false);
        }
}


void render_prompt(void) {
    bool blink = (timer_read() % 1000) < 500;
        if (layer_state_is(1)) {
            oled_write_ln_P(blink ? PSTR(">lo_") : PSTR(">lo "), false);
        } else if (layer_state_is(2)) {
            oled_write_ln_P(blink ? PSTR(">hi_") : PSTR(">hi "), false);
        } else if (layer_state_is(3)) {
            oled_write_ln_P(blink ? PSTR(">ad_") : PSTR(">ad "), false);
        } else {
            oled_write_ln_P(blink ? PSTR(">_ ") : PSTR(">   "), false);
        }
};

void render_mod_status(void) {
    bool blink = (timer_read() % 1000) < 500;
    uint8_t modifiers = get_mods() | get_oneshot_mods();
        if (modifiers & MOD_MASK_CTRL) {
            oled_write_ln_P(blink ? PSTR("$ctl_") : PSTR("$ctl "), false);
        } else if (modifiers & MOD_MASK_SHIFT) {
            oled_write_ln_P(blink ? PSTR("$sft_") : PSTR("$sft "), false);
        } else if (modifiers & MOD_MASK_ALT) {
            oled_write_ln_P(blink ? PSTR("$alt_") : PSTR("$alt "), false);
        } else if (modifiers & MOD_MASK_GUI) {
            oled_write_ln_P(blink ? PSTR("$gui_") : PSTR("$gui "), false);
        } else {
            oled_write_ln_P(blink ? PSTR("$_  ") : PSTR("$    "), false);
        }
}





#ifdef LUNA
static void render_luna(int LUNA_X, int LUNA_Y) {

    static const char PROGMEM sit[2][ANIM_SIZE] = {

        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfc,
            0xfe, 0xfd, 0xfe, 0xdc, 0xfc, 0xfc, 0xfe, 0x5d, 0xfe, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf8, 0x1c, 0xf0, 0xf8, 0xfc, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xf9, 0xfd, 0x7f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x37,
            0x21, 0x13, 0x3f, 0x3f, 0x3f, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfe,
            0xfd, 0xfe, 0xfc, 0xdc, 0xfc, 0xfe, 0xfd, 0x5e, 0xfc, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf8, 0xfc, 0x80, 0xf0, 0xf8, 0xfc, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xf1, 0xfd, 0x7f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x37,
            0x21, 0x13, 0x3f, 0x3f, 0x3f, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    static const char PROGMEM walk[2][ANIM_SIZE] = {

        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf0, 0x70, 0x30, 0x20, 0x00, 0x80, 0xc0,
            0xc0, 0xf0, 0xf8, 0xf4, 0xf8, 0x70, 0xf0, 0xf0, 0xf8, 0x74, 0xf8, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0xff, 0xfd, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xe7, 0xf5, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x3f, 0x3f, 0x3f, 0x0f, 0x11, 0x1f, 0x1f,
            0x03, 0x07, 0x1f, 0x3f, 0x3f, 0x0f, 0x13, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00,
            0x00, 0xe0, 0xf0, 0xe8, 0xf0, 0xe0, 0xe0, 0xe0, 0xf0, 0xe8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x3f, 0xfb, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xef, 0xcf, 0xea, 0x3f, 0x1f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x0f, 0x03, 0x07, 0x0f, 0x1f, 0x03,
            0x1f, 0x1f, 0x17, 0x0f, 0x1f, 0x3f, 0x3f, 0x33, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    static const char PROGMEM run[2][ANIM_SIZE] = {

        {
            0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xb0, 0xa0, 0x80, 0x80, 0x80, 0x80, 0x80,
            0x80, 0xc0, 0xc0, 0xfc, 0xf4, 0xe4, 0xf8, 0x70, 0xf8, 0xe4, 0xf8, 0x70, 0xc0, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x01, 0x63, 0xe7, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x67, 0x37, 0x35, 0x1f, 0x0f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01,
            0x03, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x3b, 0x33, 0x07, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        {
            0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
            0x80, 0x80, 0xf8, 0xe8, 0xc8, 0xf0, 0xe0, 0xf0, 0xc8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xef, 0xcf, 0x6f, 0x6a, 0x3f, 0x1f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0f, 0x1f, 0x3f, 0x3f, 0x37,
            0x03, 0x1f, 0x3f, 0x3f, 0x1f, 0x0f, 0x1f, 0x3f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    static const char PROGMEM bark[2][ANIM_SIZE] = {

        {
            0x00, 0xc0, 0xe0, 0xf0, 0xf0, 0x30, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0,
            0xfc, 0xf4, 0xe4, 0xf8, 0x70, 0xf8, 0xe4, 0xf8, 0x70, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x07, 0x0f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0x37, 0x35, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0f, 0x1f, 0x3f, 0x3f, 0x37, 0x03, 0x03,
            0x07, 0x0f, 0x1f, 0x3f, 0x3b, 0x33, 0x07, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        {
            0x00, 0xe0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0,
            0xc0, 0xec, 0xf4, 0xe4, 0xf8, 0x70, 0xf8, 0xe4, 0xf8, 0x70, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x07, 0x0f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x77, 0x37, 0x35, 0x1f, 0x0f, 0x20, 0x4a, 0x09, 0x10,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0f, 0x1f, 0x3f, 0x3f, 0x37, 0x03, 0x03,
            0x07, 0x0f, 0x1f, 0x3f, 0x3b, 0x33, 0x07, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    static const char PROGMEM sneak[2][ANIM_SIZE] = {

        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x1e, 0x3f, 0xff, 0xfb, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc, 0xfc, 0xfc,
            0xfc, 0xfe, 0xff, 0xff, 0xfe, 0xff, 0xf7, 0xff, 0x7e, 0x7f, 0x57, 0xfc, 0xf8, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x3f, 0x3f, 0x3f, 0x0f, 0x1f, 0x1f, 0x03, 0x07,
            0x1f, 0x3f, 0x3f, 0x3f, 0x0f, 0x1f, 0x1f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
        },

        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xe0, 0xa0, 0x20, 0xc0, 0x80, 0xc0, 0x20, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x3e, 0x7f, 0xf7, 0xfb, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc, 0xfc, 0xfc, 0xfc,
            0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xbf, 0xbf, 0xab, 0xfe, 0x7c, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x0f, 0x03, 0x07, 0x0f, 0x1f, 0x1f, 0x07,
            0x1f, 0x1f, 0x0f, 0x1f, 0x3f, 0x3f, 0x37, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    void animation_phase(void) {
        if (isJumping || !showedJump) {
            oled_set_cursor(LUNA_X, LUNA_Y +2);
            oled_write("     ", false);
            oled_set_cursor(LUNA_X, LUNA_Y -1);
            showedJump = true;
        } else {
            oled_set_cursor(LUNA_X, LUNA_Y -1);
            oled_write("     ", false);
            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        current_frame = (current_frame + 1) % 2;

        if(isBarking) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);
        } else if(isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);
        } else if(current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);
        } else if(current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);
        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animation_phase();
    }

    if (current_wpm > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
        oled_off();
    }
}
#endif
/* //Setup some mask which can be or'd with bytes to turn off pixels
const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};

static void fade_display(void) {
    //Define the reader structure
    oled_buffer_reader_t reader;
    uint8_t buff_char;
    if (random() % 30 == 0) {
        srand(timer_read());
        // Fetch a pointer for the buffer byte at index 0. The return structure
        // will have the pointer and the number of bytes remaining from this
        // index position if we want to perform a sequential read by
        // incrementing the buffer pointer
        reader = oled_read_raw(0);
        //Loop over the remaining buffer and erase pixels as we go
        for (uint16_t i = 0; i < reader.remaining_element_count; i++) {
            //Get the actual byte in the buffer by dereferencing the pointer
            buff_char = *reader.current_element;
            if (buff_char != 0) {
                oled_write_raw_byte(buff_char & single_bit_masks[rand() % 8], i);
            }
            //increment the pointer to fetch a new byte during the next loop
            reader.current_element++;
        }
    }
} */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
        

        /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
		case MT(MOD_LCTL,KC_MINS):
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
		case KC_LSFT:
		case KC_RSFT:
		case MT(MOD_LSFT,KC_SPC):
		case KC_SFTENT:
			if (record->event.pressed) {
				isBarking = true;
			} else {
				isBarking = false;
			}
			break;

        /* KEYBOARD PET STATUS END */
    }
    return true;
}

void render_main(void) {
    if (get_current_wpm() != 000) {
        oled_set_cursor(0, 0);
        render_wpm();
		oled_set_cursor(0, 3);
		render_luna(0, 3);
        oled_set_cursor(0, 7);
        render_prompt();
        oled_set_cursor(0, 9);
        render_mod_status();
        oled_set_cursor(0, 11);
        render_keylock_status(host_keyboard_leds());
	
    } else {
		// fade_display();
    }
}

void render_secondary(void) {
	if (get_current_wpm() != 000) {
		render_bongo();
	} else {
		// fade_display();
	}
}

void oled_task_user(void) {
	current_wpm = get_current_wpm();
    led_usb_state = host_keyboard_led_state();
    if (is_keyboard_master()) {
        render_main();
    } else {
        render_secondary();
    }
}



