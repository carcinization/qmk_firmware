#include "quantum.h"
#include "micro_oled.h"
#include "qwiic.h"
uint16_t last_flush;
enum oled_modes { OLED_DEFAULT, OLED_OFF };
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_smol( KC_A, KC_B, KC_C )
};

void draw_ui() {
    clear_buffer();
    last_flush = timer_read();
    send_command(DISPLAYON);
    switch (oled_mode) {
        default:
        case OLED_DEFAULT:
            draw_default();
            break;
        case OLED_OFF:
            send_command(DISPLAYOFF);
            break;
    }
}
