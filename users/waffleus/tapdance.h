#pragma once
#include "waffleus.h"
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum tapdance_types {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD
};

enum custom_tapdances {
    MSLGUI,
    HAP_SAD,
    QMK,
    DOCS,
};

uint8_t cur_dance(qk_tap_dance_state_t *state);
void msgui_finished(qk_tap_dance_state_t *state, void *user_data);
void msgui_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_pep_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_qmk_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_doc_finished(qk_tap_dance_state_t *state, void *user_data);
