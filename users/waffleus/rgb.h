#pragma once
#include "waffleus.h"
enum rgb_userspace_keycodes {
    CYAN
};

bool process_record_user_rgb_light(uint16_t keycode, keyrecord_t *record);
void keyboard_post_init_rgb_light(void);
