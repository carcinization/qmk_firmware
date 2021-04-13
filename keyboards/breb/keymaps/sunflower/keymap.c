#include QMK_KEYBOARD_H
#include "frames.h"
#include <stdio.h>
static int num_keypresses = 0;
static int current_frame = 0;
enum custom_keycodes {
	TESTTTTTT = SAFE_RANGE,
};
enum combos {
    FLWR_RESET,
    //FLWR_GROW,
};
enum layers {
    _BASE,
    _SYM,
    _NUM,
    _DICE,
};
const uint16_t PROGMEM flwr_combo[] = {KC_SPC, KC_ENT, COMBO_END};
//const uint16_t PROGMEM flwr_grow[] = {KC_SPC, KC_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
	[FLWR_RESET] = COMBO_ACTION(flwr_combo),
//	[FLWR_GROW] = COMBO_ACTION(flwr_grow),
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE] = LAYOUT_smol(
     KC_A, KC_B, LT(_DICE, KC_C)
 ),
 [_SYM] = LAYOUT_smol(
     TG(1), KC_A, KC_B
 ),
 [_NUM] = LAYOUT_smol(
     RGB_TOG, TG(2), RGB_RMOD
 ),
 [_DICE] = LAYOUT_smol(
     KC_ENT, KC_SPC, KC_TRNS
 )
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
		num_keypresses = num_keypresses + 1;
		if (current_frame < (ANIM_FRAMES - 1)) {
			if (num_keypresses % GROW_RATE == 0) {
				current_frame = current_frame + 1;
			}
		}
    }
    switch (keycode) {
        case TESTTTTTT:
            if (record->event.pressed) {
                SEND_STRING("hello");
            }
            break;
    }
    return true;
};
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  //srand(time(0));
  return OLED_ROTATION_270;
}
void process_combo_event(uint16_t combo_index, bool pressed) {
	switch(combo_index) {
		case FLWR_RESET:
			if (pressed) {
				num_keypresses = 0;
				current_frame = 0;
			}
			break;
		/*case FLWR_GROW:
			if (pressed) {
				if (current_frame < (ANIM_FRAMES - 1)) {
					current_frame = current_frame + 1;
				}
			}
			break;*/
	}
}
void oled_render_animation_phase(void) {
	oled_write_raw_P(plant_anim[current_frame], ANIM_SIZE);
}
void oled_task_user(void) {
    oled_render_animation_phase();
}
#endif
