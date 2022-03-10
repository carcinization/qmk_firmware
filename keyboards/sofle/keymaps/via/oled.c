 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

//Sets up what the OLED screens display.

#ifdef OLED_ENABLE

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//         0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//         0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
//     };

//     oled_write_P(qmk_logo, false);
// }

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}



// static void print_status_narrow(void) {
//     // Print current mode
//     oled_write_P(PSTR("\n\n"), false);

//     switch (get_highest_layer(layer_state)) {
//         case 0:
//             oled_write_ln_P(PSTR("Qwrt"), false);
//             break;
//         case 1:
//             oled_write_ln_P(PSTR("Clmk"), false);
//             break;
//         default:
//             oled_write_P(PSTR("Mod\n"), false);
//             break;
//     }
//     oled_write_P(PSTR("\n\n"), false);
//     // Print current layer
//     oled_write_ln_P(PSTR("LAYER"), false);
//     switch (get_highest_layer(layer_state)) {
//         case 0:
//         case 1:
//             oled_write_P(PSTR("Base\n"), false);
//             break;
//         case 2:
//             oled_write_P(PSTR("Raise"), false);
//             break;
//         case 3:
//             oled_write_P(PSTR("Lower"), false);
//             break;
//         default:
//             oled_write_ln_P(PSTR("Undef"), false);
//     }
//     oled_write_P(PSTR("\n\n"), false);
//     led_t led_usb_state = host_keyboard_led_state();
//     oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
// }

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     if (is_keyboard_master()) {
//         return OLED_ROTATION_270;
//     }
//     return rotation;
// }

// void oled_task_user(void) {
//     if (is_keyboard_master()) {
//         print_status_narrow();
//     } else {
//         render_logo();
//     }
// }


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}


led_t led_usb_state;


void render_mod_status(void) {
    bool blink = (timer_read() % 1000) < 500;
    uint8_t modifiers = get_mods() | get_oneshot_mods();
        if (modifiers & MOD_MASK_CTRL) {
            oled_write_ln_P(blink ? PSTR("$ctl_") : PSTR("$ctl "), false);
        } else if (modifiers & MOD_MASK_SHIFT) {
            oled_write_ln_P(blink ? PSTR("$sft_") : PSTR("$sft "), false);
		} else if (modifiers & MOD_MASK_ALT) {
            oled_write_ln_P(blink ? PSTR("$alt_") : PSTR("$alt "), false);
        } else if (modifiers & MOD_MASK_GUI) {
            oled_write_ln_P(blink ? PSTR("$gui_") : PSTR("$gui "), false);
        } else {
            oled_write_ln_P(blink ? PSTR("$_  ") : PSTR("$    "), false);
        }
}

void render_keylock_status(uint8_t led_usb_state) {
    bool blink = (timer_read() % 1000) < 500;
        if (led_usb_state & (1 << USB_LED_CAPS_LOCK)) {
            oled_write_ln_P(blink ? PSTR("%cap_") : PSTR("%cap "), false);
        } else if (led_usb_state & (1 << USB_LED_NUM_LOCK)) {
            oled_write_ln_P(blink ? PSTR("%num_") : PSTR("%num "), false);
        } else if (led_usb_state & (1 << USB_LED_SCROLL_LOCK)) {
            oled_write_ln_P(blink ? PSTR("%scr_") : PSTR("%scr "), false);
        } else {
            oled_write_ln_P(blink ? PSTR("%_  ") : PSTR("%    "), false);
        }
}
void render_layer_state(void) {
    bool blink = (timer_read() % 1000) < 500;
        switch (get_highest_layer(layer_state)){
			case 0:
				oled_write_ln_P(blink ? PSTR(">_ ") : PSTR(">  "), false);
			break;
			case 1:
				oled_write_ln_P(blink ? PSTR(">rse_") : PSTR(">rse "), false);
			break;
			case 2:
				oled_write_ln_P(blink ? PSTR(">lwr_") : PSTR(">lwr "), false);
			break;
			case 3:
				oled_write_ln_P(blink ? PSTR(">adj_") : PSTR(">adj "), false);
			break;
			default:
			oled_write_ln_P(blink ? PSTR(">_ ") : PSTR(">  "), false);
		}

}





void oled_task_user(void) {
if (is_keyboard_master()) {
	oled_set_cursor(0,3);
	render_layer_state();
	oled_set_cursor(0,5);
	render_mod_status();
	oled_set_cursor(0,7);
	render_keylock_status(host_keyboard_leds());
	oled_set_cursor(0,13);
     } else {
        oled_set_cursor(0,1);
        render_logo();


}
}

#endif
