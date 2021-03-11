#pragma once

enum {
  HAP_SAD,
  QMK,
  DOCS,
};

void dance_pep_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING(":widepeepohappy1"SS_TAP(X_ENTER)SS_TAP(X_BSPC)":widepeepohappy2"SS_TAP(X_ENTER)SS_TAP(X_BSPC)SS_TAP(X_ENTER));
    } else {
      SEND_STRING(":widepeeposad1"SS_TAP(X_ENTER)SS_TAP(X_BSPC)":widepeeposad2"SS_TAP(X_ENTER)SS_TAP(X_BSPC)SS_TAP(X_ENTER));
    }
}

void dance_qmk_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("https://github.com/qmk/qmk_firmware/find/master"SS_TAP(X_ENTER));
    } else {
      SEND_STRING("https://config.qmk.fm/#/"SS_TAP(X_ENTER));
    }
}

void dance_doc_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("https://docs.qmk.fm/#/newbs_getting_started");
    } else {
      SEND_STRING("https://docs.qmk.fm/#/driver_installation_zadig");
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [HAP_SAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_pep_finished, NULL),
    [QMK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_qmk_finished, NULL),
    [DOCS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_doc_finished, NULL),
};
