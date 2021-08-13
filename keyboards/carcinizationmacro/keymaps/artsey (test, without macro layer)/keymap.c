#include "kb.h"

//MAKE SURE THESE ARE INCLUDED
#include "artsey.h"
#include "keymap_combo.h"
#include "artsey.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_A_BASE] = LAYOUT(
		KC_ESC, KC_LCTL, KC_LALT, KC_DEL, KC_NO, KC_NO, 
		KC_NO, A_BASE_A, A_BASE_R, A_BASE_T, A_BASE_S, KC_NO, 
		KC_NO, A_BASE_E,A_BASE_Y,A_BASE_I,A_BASE_O, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
		
	[_A_NUM] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, A_NUM_A,A_NUM_R,A_NUM_T,A_NUM_S, KC_TRNS, 
		KC_TRNS, A_NUM_E,A_NUM_Y,A_NUM_I,A_NUM_O, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_A_NAV] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, A_NAV_A,A_NAV_R,A_NAV_T,A_NAV_S, KC_TRNS, 
		KC_TRNS, A_NAV_E,A_NAV_Y,A_NAV_I,A_NAV_O, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_A_SYM] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, A_SYM_A,A_SYM_R,A_SYM_T,A_SYM_S, KC_TRNS, 
		KC_TRNS, A_SYM_E,A_SYM_Y,A_SYM_I,A_SYM_O, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_A_BRAC] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, A_BRAC_A,A_BRAC_R,A_BRAC_T,A_BRAC_S, KC_TRNS, 
		KC_TRNS, A_BRAC_E,A_BRAC_Y,A_BRAC_I,A_BRAC_O, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_A_MOU] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, A_MOU_A,A_MOU_R,A_MOU_T,A_MOU_S, KC_TRNS, 
		KC_TRNS, A_MOU_E,A_MOU_Y,A_MOU_I,A_MOU_O, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_A_CUSTOM] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, A_CUSTOM_A,A_CUSTOM_R,A_CUSTOM_T,A_CUSTOM_S, KC_TRNS, 
		KC_TRNS, A_CUSTOM_E,A_CUSTOM_Y,A_CUSTOM_I,A_CUSTOM_O, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	
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