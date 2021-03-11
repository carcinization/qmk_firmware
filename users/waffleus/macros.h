#pragma once
#include <stdio.h>
#include <time.h>
#include <print.h>
#ifdef RANDICT
#include "users/ridingqwerty/dict.h"
#endif
#define MODS_MASK (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_LCTRL))

uint16_t alt_tab_timer = 0;
uint16_t typing_mode;
uint16_t rand_key;
uint8_t temp_keycode;
bool is_alt_tab_active = false;
bool randword_seed = false;
bool is_sponge_active = false;
bool random_bool(void){
    bool rbool = rand() & 1;
     return rbool;
}

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

enum custom_keycodes {
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
