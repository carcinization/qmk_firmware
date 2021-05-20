
#ifdef OLED_DRIVER_ENABLE


// Set coordinates for visualizer to show
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
 return 3;
}



const char base_map[]= "arst\n" 
"oien";
const char shifted_base_map[]= "ARST\n" 
"OIEN";
const char num_map[]= " 321\n"
"7654";
const char shifted_num_map[]= " #@!\n"
"&^%$";
const char sym_map[]= "`;\\!\n" 
"=-? ";
const char shifted_sym_map[]= "~:|!\n"
"+_? ";
const char brac_map[]= "{)( \n"
"}][}";
const char shifted_brac_map[]= "{)( \n"
"}}{}";

static char const nav_map[] PROGMEM = {0x1E, 0x11, 0x18, 0x10, 0, 0, 0x1F, 0x1B, 0x19, 0x1A, 0
	};


void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Map: "), false);
	
    switch (get_highest_layer(layer_state)) {
        case _A_BASE:
			if (get_mods() & MOD_BIT(KC_LSFT)) {
				oled_write(shifted_base_map, false);
			} 
			else if (get_oneshot_mods() & MOD_BIT(KC_LSFT)){
				oled_write(shifted_base_map, false);
			} else {
            oled_write(base_map, false);}
            break;
        case _A_NUM:
            oled_write_P(PSTR("NUM"), false);
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
		// case _A_MOU:
		// case _A_CUSTOM:
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}


#endif