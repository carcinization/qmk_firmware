#pragma once

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_CYAN}
);

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
    my_qwerty_layer,
    my_lower_layer,
    my_raise_layer,
    my_adjust_layer
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer(0, layer_state_cmp(state, _QWERTY));
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer(3, layer_state_cmp(state, _ADJUST));
    return state;
}
#endif

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_CYAN);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_layers = my_rgb_layers;
}

