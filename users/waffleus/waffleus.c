#include "waffleus.h"
#include "quantum.h"

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (is_keyboard_master())    { return OLED_ROTATION_270; }
	else if (is_keyboard_left()) { return OLED_ROTATION_0; }
	else                         { return OLED_ROTATION_180; }
}

void oled_task_user(void) {
	if (is_keyboard_master()) { render_primary(); }
	#ifndef PRIMARY_ONLY
	else                      { render_secondary(); }
	#endif
}

bool process_record_user_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
        add_keylog(keycode);
#endif
    }
    return true;
}
#endif
