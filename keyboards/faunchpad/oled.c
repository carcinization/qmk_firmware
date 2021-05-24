/* Blinking mod status, keylock status, and layer state adapted with permission from @Itswaffle/@waffle#6666 
at https://github.com/ItsWaffIe/qmk_firmware/blob/waffle/users/waffleus/oled.c#L76-#L124 */



// Set coordinates for visualizer to show
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
 return 3;
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
			case _A_BASE:
				oled_write_ln_P(blink ? PSTR(">_ ") : PSTR(">  "), false);
			break;
			case _A_NUM:
				oled_write_ln_P(blink ? PSTR(">num_") : PSTR(">num "), false);
			break;
			case _A_NAV:
				oled_write_ln_P(blink ? PSTR(">nav_") : PSTR(">nav "), false);
			break;
			case _A_SYM:
				oled_write_ln_P(blink ? PSTR(">sym_") : PSTR(">sym "), false);
			break;
			case _A_BRAC:
				oled_write_ln_P(blink ? PSTR(">brc_") : PSTR(">brc "), false);
			break;
			case _A_MOU:
				oled_write_ln_P(blink ? PSTR(">mou_") : PSTR(">mou "), false);
			break;
			case _A_CUSTOM:
				oled_write_ln_P(blink ? PSTR(">cus_") : PSTR(">cus "), false);
			break;
			default:
			oled_write_ln_P(blink ? PSTR(">_ ") : PSTR(">  "), false);
		}
}
			

void render_map(void) {
	switch (get_highest_layer(layer_state)) {
        case _A_BASE:
			if (get_mods() & MOD_BIT(KC_LSFT)) {
				oled_write(shifted_base_map, false);
			} 
			else if (get_oneshot_mods() & MOD_BIT(KC_LSFT)){
				oled_write(shifted_base_map, false);
			} else if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)){
				oled_write(shifted_base_map, false);
			}else{
            oled_write(base_map, false);}
            break;
        case _A_NUM:
            if (get_mods() & MOD_BIT(KC_LSFT)) {
				oled_write(shifted_num_map, false);
			} 
			else if (get_oneshot_mods() & MOD_BIT(KC_LSFT)){
				oled_write(shifted_num_map, false);
			} else {
            oled_write(num_map, false);}
            break;
        case _A_NAV:
            oled_write_P(nav_map, false);
            break;
		case _A_SYM:
			if (get_mods() & MOD_BIT(KC_LSFT)) {
				oled_write(shifted_sym_map, false);
			} 
			else if (get_oneshot_mods() & MOD_BIT(KC_LSFT)){
				oled_write(shifted_sym_map, false);
			} else {
            oled_write(sym_map, false);}
			break;
		case _A_BRAC:
		    if (get_mods() & MOD_BIT(KC_LSFT)) {
				oled_write(shifted_brac_map, false);
			} 
			else if (get_oneshot_mods() & MOD_BIT(KC_LSFT)){
				oled_write(shifted_brac_map, false);
			} else {
            oled_write(brac_map, false);}
            break;
		case _A_MOU:
			oled_write_P(mou_map, false);
			break;
		case _A_CUSTOM:
			    oled_write_ln_P(PSTR("Undefined"), false);
			break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_clear();
    }
}

void oled_task_user(void) {
	render_map();
	oled_set_cursor(0,3);
	render_layer_state();
	oled_set_cursor(0,5);
	render_mod_status();
	oled_set_cursor(0,7);
	render_keylock_status(host_keyboard_leds());

    
	
    
}



