#pragma once
#include "waffleus.h"
bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 0;
uint8_t current_frame = 0;
uint8_t get_current_wpm(void);
bool anim_phase = false;
bool isSneaking = false;
bool isJumping = false;
bool showedJump = true;
int current_wpm = 0;
led_t led_usb_state;
#define LAYER_FRAME_DURATION 250
#define BONGO_FELIX_FRAME_DURATION 200
#define LAYER_SIZE 520
#define BONGO_SIZE 512
#define XANIM_SIZE 650
#define BONGO_TAP_SPEED 40
#define BONGO_TAP_FRAMES 2
#define BONGO_IDLE_SPEED 30
#define BONGO_IDLE_FRAMES 5
#define LAYER_TAP_FRAMES 3
#define FELIX_WALK_SPEED 30
#define FELIX_RUN_SPEED 50
#define FELIX_SIZE 96
//#define FELIX
