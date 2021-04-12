#include QMK_KEYBOARD_H
#include "frames.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
uint16_t roll(uint16_t N);
static int num_keypresses = 0;
static int current_frame = 0;
uint8_t die_idx = 0;
uint16_t roll_result = 1;
enum custom_keycodes {
	NEXT_DIE = SAFE_RANGE,
	ROLL,
};
enum combos {
    FLWR_RESET,
    FLWR_GROW,
};
enum layers {
    _BASE,
    _SYM,
    _NUM,
    _DICE,
};
const uint16_t PROGMEM flwr_combo[] = {KC_SPC, KC_ENT, COMBO_END};
const uint16_t PROGMEM flwr_grow[] = {KC_SPC, KC_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
	[FLWR_RESET] = COMBO_ACTION(flwr_combo),
	[FLWR_GROW] = COMBO_ACTION(flwr_grow),
};
const uint16_t dice[7] = {2, 4, 6, 8, 10, 12, 20};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE] = LAYOUT_smol(
     KC_A, KC_B, TG(_DICE)
 ),
 [_SYM] = LAYOUT_smol(
     TG(1), KC_A, KC_B
 ),
 [_NUM] = LAYOUT_smol(
     RGB_TOG, TG(2), RGB_RMOD
 ),
 [_DICE] = LAYOUT_smol(
     KC_1, KC_3, TG(_DICE)
 )
};
uint8_t mod_state;
char roll_str[5] = {};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
		num_keypresses = num_keypresses + 1;
		if (current_frame < (ANIM_FRAMES - 1)) {
			if (num_keypresses % GROW_RATE == 0) {
				current_frame = current_frame + 1;
			}
		}
    }
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else {
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        return true;
	}
	case TG(_DICE):
		{
		if (record->event.pressed) {
		} else {
			oled_clear();
		}
		}
    case NEXT_DIE:
	{
	if (record->event.pressed) {
		if (die_idx < (DICE_FRAMES - 1)) {
			die_idx = die_idx + 1;
		} else {
			die_idx = 0;
		}
	}
	break;
	}
    case ROLL:
		{
		if (record->event.pressed) {
			roll_result = roll(dice[die_idx]);
			snprintf(roll_str, sizeof(roll_str), "%d ", roll_result);
		}
		}
    }
    return true;
};
uint16_t roll(uint16_t n) {
  if ((n - 1) >= RAND_MAX) {
    return rand();
  } else {
    int end = RAND_MAX / n;
    end *= n;
    int r;
    while ((r = rand()) >= end);
    return (r % n) + 1;
  }
}
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  srand(time(0));
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
		case FLWR_GROW:
			if (pressed) {
				if (current_frame < (ANIM_FRAMES - 1)) {
					current_frame = current_frame + 1;
				}
			}
			break;
	}
}
char die_str[4] = {};
void oled_render_layer_state(void) {
	oled_set_cursor(0, 6);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_raw_P(base_logo, LOGO_SIZE);
            break;
        case _SYM:
            oled_write_raw_P(sym_logo, LOGO_SIZE);
            break;
        case _NUM:
            oled_write_raw_P(num_logo, LOGO_SIZE);
            break;
        case _DICE:
			oled_set_cursor(2, 4);
			oled_write(roll_str, false);
			oled_set_cursor(0, 6);
            oled_write_raw_P(dice_frames[die_idx], LOGO_SIZE);
			snprintf(die_str, sizeof(die_str), "d%d ", dice[die_idx]);
			oled_set_cursor(2, 11);
			oled_write(die_str, false);
            break;
    }
}
void oled_render_animation_phase(void) {
	oled_write_raw_P(plant_anim[current_frame], ANIM_SIZE);
}
void oled_task_user(void) {
    oled_render_animation_phase();
}
#endif
