#pragma once
#include "quantum.h"
#include <stdio.h>
//#define FELIX
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 0;
uint8_t current_frame = 0;
#define LAYER_FRAME_DURATION 250
#define BONGO_FRAME_DURATION 200
#define LAYER_SIZE 520
#define BONGO_SIZE 512
#define XANIM_SIZE 650
#define BONGO_TAP_SPEED 40
#define BONGO_TAP_FRAMES 2
#define BONGO_IDLE_SPEED 30
#define BONGO_IDLE_FRAMES 5
#define LAYER_TAP_FRAMES 3
bool anim_phase = false;
uint8_t get_current_wpm(void);
#ifdef FELIX
#define MIN_WALK_SPEED 30
#define MIN_RUN_SPEED 45
#define FELIX_SIZE 96
#define FELIX_FRAME_DURATION 200
int current_wpm = 0;
led_t led_usb_state;
bool isSneaking = false;
bool isJumping = false;
bool showedJump = true;
#endif

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#ifdef KEYBOARD_crkbd_rev1_common
    if (!is_keyboard_master()) {
        return 2;
    } else {
        return 3;
    }
#endif
#ifdef KEYBOARD_crkbd_rev1
    if (is_master) {
        return 3;
    } else {
        return 2;
    }
#endif
    return rotation;
}

void oled_task_user(void) {
#ifdef KEYBOARD_crkbd_rev1_common
    if (is_keyboard_master()) {
        render_main();
    } else {
        render_secondary();
    }
#ifdef KEYBOARD_crkbd_rev1
    if (is_master) {
        render_main();
    } else {
        render_bongo();
    }
}
