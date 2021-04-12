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
#define BONGO_FRAME_DURATION 200
