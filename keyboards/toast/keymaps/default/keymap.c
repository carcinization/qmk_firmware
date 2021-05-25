#include QMK_KEYBOARD_H
#include "pimoroni_trackball.h"
#include "pointing_device.h"
enum custom_keycode {
    BALL_HUI,
    BALL_WHITE,
    BALL_DECREASE,
    BALL_SCROLL,
    BALL_NCL,
    BALL_RCL,
    BALL_MCL,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( KC_A, KC_B )
};

//ball
uint8_t white = 0;
uint8_t red = 255;
uint8_t green = 0;
uint8_t blue = 0;
void ball_increase_hue(void) {
    if (red != 255 && green != 255 && blue != 255) { red = 255; }
    if (red == 255 && green < 255 && blue == 0) { green += 15; }
    else if (green == 255 && green < 255 && blue == 0) { red -= 15; }
    else if (red == 0 && blue < 255 && green == 255) { blue += 15; }
    else if (blue == 255 && green > 0 && red == 0) { green -= 15; }
    else if (green == 0 && blue == 255 && red < 255) { red += 15; }
    else if (green == 0 && blue > 0 && red == 255) { blue -= 15; }
    trackball_set_rgbw(red, green, blue, white);
}

void decrease_color(void) {
    if (green > 0) { green -= 15; }
    if (red > 0) { red -= 15; }
    if (blue > 0) { blue -= 15; }
    trackball_set_rgbw(red, green, blue, white);
}

void cycle_white(void) {
    if (white < 255) { white += 15; }
    else { white = 0; }
    trackball_set_rgbw(red, green, blue, white);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BALL_HUI:
            if (record->event.pressed) { ball_increase_hue(); }
            break;
        case BALL_WHITE:
            if (record->event.pressed) { cycle_white(); }
            break;
        case BALL_DECREASE:
            if (record->event.pressed) { decrease_color(); }
            break;
        case BALL_SCROLL:
            if (record->event.pressed) { trackball_set_scrolling(true); }
            else { trackball_set_scrolling(false); }
            break;
        case BALL_NCL:
            record->event.pressed ? register_code(KC_BTN1) : unregister_code(KC_BTN1);
            break;
        case BALL_RCL:
            record->event.pressed ? register_code(KC_BTN2) : unregister_code(KC_BTN2);
            break;
        case BALL_MCL:
            record->event.pressed ? register_code(KC_BTN3) : unregister_code(KC_BTN3);
            break;
    }
    return true;
}
