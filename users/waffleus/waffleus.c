#include "waffleus.h"
#include "quantum.h"

bool process_record_user_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
        add_keylog(keycode);
#endif
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LWRSPC:
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PINK}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_lower_layer,
    my_raise_layer,
    my_adjust_layer
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}
#endif

#ifdef RGBLIGHT_ENALBE
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_CYAN);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
#ifdef RGBLIGHT_LAYERS
    rgblight_layers = my_rgb_layers;
#endif
}
#endif

#ifdef UNICODEMAP_ENABLE
const uint32_t PROGMEM unicode_map[] = {
   [SIDE] = 0x30C4,
   [UPAR] = 0x16CF,
   [HAS] = 0x262D,
   [STAR] = 0x2605,
   [VIB] = 0x0950,
};
#endif

#ifdef BOOTLOADER_nanoboot
void bootloader_jump(void) {
    /* nanoBoot sets up 2 registers (r2,r3), copies then clears the MCUSR register,
    disables the watchdog timer and then checks the EXTRF. It'll only continue in the
    bootloader if the flag is set, otherwise it'll boot the application (jmp 0) when
    using the reset vector (0x7E00). This code jumps past the reset vector straight into
    the bootloader skipping the EXTRF check, so prior setup is required.
    This code is mostly from  from tmk_core/common/avr/bootloader.c */
    cli();
    UDCON  = 1;
    USBCON = (1 << FRZCLK);  // disable USB
    UCSR1B = 0;
    _delay_ms(5);
    EIMSK  = 0;
    PCICR  = 0;
    SPCR   = 0;
    ACSR   = 0;
    EECR   = 0;
    ADCSRA = 0;
    TIMSK0 = 0;
    TIMSK1 = 0;
    TIMSK3 = 0;
    TIMSK4 = 0;
    UCSR1B = 0;
    TWCR   = 0;
    DDRB   = 0;
    DDRC   = 0;
    DDRD   = 0;
    DDRE   = 0;
    DDRF   = 0;
    TWCR   = 0;
    PORTB  = 0;
    PORTC  = 0;
    PORTD  = 0;
    PORTE  = 0;
    PORTF  = 0;
    asm volatile("clr r2");      // clear register (rZERO in bootloader)
    asm volatile("clr r3");      // clear register (rONE in bootloader)
    asm volatile("inc r3");      // increment register
    asm volatile("jmp 0x7e6a");  // jump to bootloader skipping some setup and extrf check.
}
#endif
