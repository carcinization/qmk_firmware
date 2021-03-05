#include "waffleus.h"
#include "quantum.h"

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (is_keyboard_master())    { return OLED_ROTATION_270; }
	else if (is_keyboard_left()) { return OLED_ROTATION_0; }
	else                         { return OLED_ROTATION_180; }
}

// Render modules on both OLED
void oled_task_user(void) {
	if (is_keyboard_master()) { render_primary(); }
	#ifndef PRIMARY_ONLY
	else                      { render_secondary(); }
	#endif
}
#endif
