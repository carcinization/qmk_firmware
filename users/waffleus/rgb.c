#include "rgb.h"

bool process_record_user_rgblight(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CYAN:
            if (record->event.pressed) {
                rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
                rgblight_sethsv(0, 255, 255);
            }
            break;
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

void keyboard_post_init_rgblight(void) {
#ifdef RGBLIGHT_LAYERS
    rgblight_layers = my_rgb_layers;
#endif
}
