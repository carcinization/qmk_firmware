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

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_CYAN);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
#ifdef RGBLIGHT_LAYERS
    rgblight_layers = my_rgb_layers;
#endif
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
