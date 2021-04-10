#include "waffleus.h"
#include "quantum.h"

#ifdef OLED_DRIVER_ENABLE
#include "oled.c"
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LWRSPC:
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

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
