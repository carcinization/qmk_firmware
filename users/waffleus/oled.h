#pragma once
#include "quantum.h"
#include "oled_driver.h"
#define WPM "WPM:"
#define KEYLOG_LENGTH 5
uint8_t keylogs_str_idx = 0;
bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);
