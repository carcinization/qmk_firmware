#pragma once

enum typing_mode {
  TM_NOMODE,
  TM_REGIONAL,
  TM_WIDE,
  TM_SCRIPT,
  TM_BLOCKS,
  TM_AUSSIE,
  TM_ZALGO,
  TM_WOWMODE,
  TM_D3MODE
};

enum waffle_keycodes {
  CP_PSTE = SAFE_RANGE,
  UNIT,
  UNIT2,
  UNIT3,
  UNIT4,
  WEEB,
  RGBRST,
  RWORD,
  SPONGE,
  ALT_TAB,
  MAKE,
  KC_NOMODE,
  KC_REGIONAL,
  KC_WIDE,
  KC_SCRIPT,
  KC_BLOCKS,
  KC_AUSSIE,
  KC_ZALGO,
  KC_WOWMODE,
  KC_D3MODE
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void tap_code16_nomods(uint8_t kc);
void tap_unicode_glyph(uint32_t glyph);
void tap_unicode_glyph_nomods(uint32_t glyph);
bool process_record_glyph_replacement(uint16_t keycode, keyrecord_t *record, translator_function_t translator);
bool process_record_aussie(uint16_t keycode, keyrecord_t *record);
bool process_record_zalgo(uint16_t keycode, keyrecord_t *record);
