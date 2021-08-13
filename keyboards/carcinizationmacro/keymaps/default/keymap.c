#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, 
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, 
		KC_SPC, KC_LCTL, KC_LALT, KC_LGUI, KC_A, KC_1),

	

};

/* 
void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

} */