#pragma once
#include "quantum.h"
#include "oled_driver.h"
uint8_t keylogs_str_idx = 0;
uint16_t log_timer = 0;
bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);
//extern uint32_t oled_timer;
#define KEYLOG_LEN 5
#define WPM "WPM:"
