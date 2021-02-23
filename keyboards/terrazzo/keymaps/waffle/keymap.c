#include QMK_KEYBOARD_H

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
uint16_t typing_mode;
uint8_t temp_keycode;

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _EXTRA
};

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
  UNIT4,
  UNIT5,
  SSH_PI,
  GIT,
  SETUP,
  ZAD,
  CONF,
  CD1,
  CTLS,
  WEEB,
  WIDHAP,
  WIDSAD,
  CAD,
  NKINV,
  MMAP,
  VIA,
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

enum unicodemap_names {
    SIDE,
    UPAR,
    HAS,
    STAR,
    VIB
};

enum {
  HAP_SAD,
  QMK,
  DOCS,
  LINKS,
};

enum combos {
  RU_ENT,
  EI_BSP,
  GH_QUOT,
  VM_QUES,
  CM_DQUO,
  TY_COLN,
  DF_BTN1,
  JK_BTN2,
  VB_WHD,
  NM_WHU
};

#define SFA SFT_T(KC_A)
#define RAISE MO(2)
#define ADJUST TG(3)
#define LWRSPC LT(1, KC_SPC)
#define CTLTZ CTL_T(KC_Z)
#define CTLDOT CTL_T(KC_DOT)
#define SFL SFT_T(KC_L)
#define SFEXM MT(MOD_LSFT, KC_F23)
#define SFPRN MT(MOD_RSFT, KC_F24)
#define GPSCR G(KC_PSCR)
#define CTLRGT CTL_T(KC_RGHT)
#define CTLESC CTL_T(KC_ESC)
#define CTLSLSH CTL_T(KC_SLSH)
#define CTLVIB CTL_T(X(VIB))
#define CTLBSP CTL_T(KC_BSPC)
#define HAPSAD TD(HAP_SAD)
#define DOCSTD TD(DOCS)
#define LINKSTD TD(LINKS)
#define QMKTD TD(QMK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
	  	KC_MPLY, QMKTD,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  GPSCR,
	    TZ_NXT,  ALT_TAB, SFA,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    SFL,            KC_BSPC,
	    TZ_PRV,  DOCSTD,  CTLTZ,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, CTLDOT,         CTLSLSH,
	    TZ_OFF,           HAPSAD, KC_LGUI,          LWRSPC,           RAISE,            KC_RGUI,  CTLS
    ),

    [_LOWER] = LAYOUT(
        KC_MUTE, LINKSTD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
	    UNIT,    WEEB,    SFEXM,   KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,        SFPRN,
	    UNIT4,   VIA,     CTLESC,  KC_TAB,  KC_CAPS, KC_TILD, KC_GRV,  KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,        CTLVIB,
	    UNIT5,            KC_LALT,  KC_LGUI,          KC_TRNS,          KC_SLSH,          KC_RGUI, WEEB
    ),

    [_RAISE] = LAYOUT(
        RESET,   X(SIDE), KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, CG_NORM, KC_ASUP, KC_ASON,  KC_AUSSIE, KC_WIDE, KC_NOMODE,
	    UC_M_WC, X(UPAR), KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, CG_SWAP, KC_ASDN, KC_ASOFF, KC_REGIONAL,        KC_BLOCKS,
	    UC_M_MA, X(STAR), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   UNIT,    UNIT2,   UNIT4,    UNIT5,              KC_SCRIPT,
	    MAKE,             WIDHAP,  KC_LGUI,          KC_SCLN,          KC_TRNS,          KC_RGUI,  WIDSAD
    ),

    [_EXTRA] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______,          _______,          _______,          _______, _______
    )
};

const uint16_t PROGMEM ru_combo[] = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM vm_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM cm_combo[] = {KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM ty_combo[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
[RU_ENT] = COMBO(ru_combo, KC_ENT),
[EI_BSP] = COMBO(ei_combo, CTLBSP),
[GH_QUOT] = COMBO(gh_combo, KC_QUOT),
[VM_QUES] = COMBO(vm_combo, KC_QUES),
[CM_DQUO] = COMBO(cm_combo, KC_DQUO),
[TY_COLN] = COMBO(ty_combo, KC_COLN),
[DF_BTN1] = COMBO(df_combo, KC_BTN1),
[JK_BTN2] = COMBO(jk_combo, KC_BTN2),
[VB_WHD] = COMBO(vb_combo, KC_WH_D),
[NM_WHU] = COMBO(nm_combo, KC_WH_U)
};
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LWRSPC:
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}

 const uint32_t PROGMEM unicode_map[] = {
   [SIDE] = 0x30C4,
   [UPAR] = 0x16CF,
   [HAS] = 0x262D,
   [STAR] = 0x2605,
   [VIB] = 0x0950,
};
#ifdef TAP_DANCE_ENABLE
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

void dance_link_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING(":checkpinsbich: "SS_TAP(X_ENTER));
      SEND_STRING("https://www.mechmap.tech/themap"SS_TAP(X_ENTER));
    } else {
      SEND_STRING("NovelKeys Inventory Updates - https://novelkeys.xyz/pages/inventory"SS_TAP(X_ENTER));
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
    [DOCS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_link_finished, NULL),
    [LINKS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_doc_finished, NULL),
};
#endif

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void tap_code16_nomods(uint8_t kc) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_code16(kc);
    set_mods(temp_mod);
}

void tap_unicode_glyph(uint32_t glyph) {
    unicode_input_start();
    register_hex32(glyph);
    unicode_input_finish();
}

void tap_unicode_glyph_nomods(uint32_t glyph) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_unicode_glyph(glyph);
    set_mods(temp_mod);
}

typedef uint32_t (*translator_function_t)(bool is_shifted, uint32_t keycode);

#define DEFINE_UNICODE_RANGE_TRANSLATOR(translator_name, lower_alpha, upper_alpha, zero_glyph, number_one, space_glyph) \
    static inline uint32_t translator_name(bool is_shifted, uint32_t keycode) {                                         \
        switch (keycode) {                                                                                              \
            case KC_A ... KC_Z:                                                                                         \
                return (is_shifted ? upper_alpha : lower_alpha) + keycode - KC_A;                                       \
            case KC_0:                                                                                                  \
                return zero_glyph;                                                                                      \
            case KC_1 ... KC_9:                                                                                         \
                return (number_one + keycode - KC_1);                                                                   \
            case KC_SPACE:                                                                                              \
                return space_glyph;                                                                                     \
        }                                                                                                               \
        return keycode;                                                                                                 \
    }

#define DEFINE_UNICODE_LUT_TRANSLATOR(translator_name, ...)                     \
    static inline uint32_t translator_name(bool is_shifted, uint32_t keycode) { \
        static const uint32_t translation[] = {__VA_ARGS__};                    \
        uint32_t              ret           = keycode;                          \
        if ((keycode - KC_A) < (sizeof(translation) / sizeof(uint32_t))) {      \
            ret = translation[keycode - KC_A];                                  \
        }                                                                       \
        return ret;                                                             \
    }

bool process_record_glyph_replacement(uint16_t keycode, keyrecord_t *record, translator_function_t translator) {
    uint8_t temp_mod   = get_mods();
    uint8_t temp_osm   = get_oneshot_mods();
    bool    is_shifted = (temp_mod | temp_osm) & MOD_MASK_SHIFT;
    if (((temp_mod | temp_osm) & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI)) == 0) {
        if (KC_A <= keycode && keycode <= KC_Z) {
            if (record->event.pressed) {
                tap_unicode_glyph_nomods(translator(is_shifted, keycode));
            }
            return false;
        } else if (KC_1 <= keycode && keycode <= KC_0) {
            if (is_shifted) {
                return process_record_keymap(keycode, record);
            }
            if (record->event.pressed) {
                tap_unicode_glyph(translator(is_shifted, keycode));
            }
            return false;
        } else if (keycode == KC_SPACE) {
            if (record->event.pressed) {
                tap_unicode_glyph(translator(is_shifted, keycode));
            }
            return false;
        }
    }
    return process_record_keymap(keycode, record);
}

DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_wide, 0xFF41, 0xFF21, 0xFF10, 0xFF11, 0x2003);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_script, 0x1D4EA, 0x1D4D0, 0x1D7CE, 0x1D7C1, 0x2002);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_boxes, 0x1F170, 0x1F170, '0', '1', 0x2002);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_regional, 0x1F1E6, 0x1F1E6, '0', '1', 0x2003);

DEFINE_UNICODE_LUT_TRANSLATOR(unicode_lut_translator_aussie,
                              0x0250,  // a
                              'q',     // b
                              0x0254,  // c
                              'p',     // d
                              0x01DD,  // e
                              0x025F,  // f
                              0x0183,  // g
                              0x0265,  // h
                              0x1D09,  // i
                              0x027E,  // j
                              0x029E,  // k
                              'l',     // l
                              0x026F,  // m
                              'u',     // n
                              'o',     // o
                              'd',     // p
                              'b',     // q
                              0x0279,  // r
                              's',     // s
                              0x0287,  // t
                              'n',     // u
                              0x028C,  // v
                              0x028D,  // w
                              0x2717,  // x
                              0x028E,  // y
                              'z',     // z
                              0x0269,  // 1
                              0x3139,  // 2
                              0x0190,  // 3
                              0x3123,  // 4
                              0x03DB,  // 5
                              '9',     // 6
                              0x3125,  // 7
                              '8',     // 8
                              '6',     // 9
                              '0'      // 0
);

bool process_record_aussie(uint16_t keycode, keyrecord_t *record) {
    bool is_shifted = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
    if ((KC_A <= keycode) && (keycode <= KC_0)) {
        if (record->event.pressed) {
            if (!process_record_glyph_replacement(keycode, record, unicode_lut_translator_aussie)) {
                tap_code16_nomods(KC_LEFT);
                return false;
            }
        }
    } else if (record->event.pressed && keycode == KC_SPACE) {
        tap_code16_nomods(KC_SPACE);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_ENTER) {
        tap_code16_nomods(KC_END);
        tap_code16_nomods(KC_ENTER);
        return false;
    } else if (record->event.pressed && keycode == KC_HOME) {
        tap_code16_nomods(KC_END);
        return false;
    } else if (record->event.pressed && keycode == KC_END) {
        tap_code16_nomods(KC_HOME);
        return false;
    } else if (record->event.pressed && keycode == KC_BSPC) {
        tap_code16_nomods(KC_DELT);
        return false;
    } else if (record->event.pressed && keycode == KC_DELT) {
        tap_code16_nomods(KC_BSPC);
        return false;
    } else if (record->event.pressed && keycode == KC_QUOT) {
        tap_unicode_glyph_nomods(is_shifted ? 0x201E : 0x201A);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_COMMA) {
        tap_unicode_glyph_nomods(is_shifted ? '<' : 0x2018);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_DOT) {
        tap_unicode_glyph_nomods(is_shifted ? '>' : 0x02D9);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_SLASH) {
        tap_unicode_glyph_nomods(is_shifted ? 0x00BF : '/');
        tap_code16_nomods(KC_LEFT);
        return false;
    }
    return process_record_keymap(keycode, record);
}

bool process_record_zalgo(uint16_t keycode, keyrecord_t *record) {
    if ((KC_A <= keycode) && (keycode <= KC_0)) {
        if (record->event.pressed) {
            tap_code16_nomods(keycode);

            int number = (rand() % (8 + 1 - 2)) + 2;
            for (int index = 0; index < number; index++) {
                uint16_t hex = (rand() % (0x036F + 1 - 0x0300)) + 0x0300;
                tap_unicode_glyph(hex);
            }

            return false;
        }
    }
    return process_record_keymap(keycode, record);
}

bool no_mod_taps = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  temp_keycode = keycode;
    if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) {
        temp_keycode &= 0xFF;
    }
  switch (keycode) {
      case CP_PSTE:
        if (record->event.pressed) {
            tap_code16(C(KC_C));
        } else {
            tap_code16(C(KC_V));
        }
        return false;

      case MT(MOD_LSFT, KC_F23):
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            register_code16(KC_EXLM);
          } else {
            unregister_code16(KC_EXLM);
          }
          return false;
        }
        break;


      case MT(MOD_RSFT, KC_F24):
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            register_code16(KC_RPRN);
          } else {
            unregister_code16(KC_RPRN);
          }
          return false;
        }
        break;

      case UNIT:
        if (record->event.pressed) {
          send_unicode_string("(＾▽＾)");
        } else {
        }
        break;

      case CTLS:
        if (record->event.pressed) {
         SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_S)SS_UP(X_LGUI));
        } else {
        }
        break;

      case UNIT2:
        if (record->event.pressed) {
          send_unicode_string("≧ω≦");
        } else {
        }
        break;

      case UNIT4:
        if (record->event.pressed) {
          send_unicode_string("(╯°□°）╯︵ ┻━┻");
        } else {
        }
        break;

      case UNIT5:
        if (record->event.pressed) {
          send_unicode_string("┬──┬ ノ( ゜-゜ノ)");
        } else {
        }
        break;

      case WEEB:
        if (record->event.pressed) {
          SEND_STRING(":WeebsDie1"SS_TAP(X_ENTER)SS_TAP(X_BSPC)":WeebsDie2"SS_TAP(X_ENTER)SS_TAP(X_BSPC)":WeebsDie3"SS_TAP(X_ENTER)SS_TAP(X_BSPC)SS_TAP(X_ENTER));
        } else {
        }
        break;

      case WIDHAP:
        if (record->event.pressed) {
            SEND_STRING(":widepeepohappy1"SS_TAP(X_ENTER)SS_TAP(X_BSPC)":widepeepohappy2"SS_TAP(X_ENTER)SS_TAP(X_BSPC)SS_TAP(X_ENTER));
        } else {
        }
        break;

      case WIDSAD:
        if (record->event.pressed) {
            SEND_STRING(":widepeeposad1"SS_TAP(X_ENTER)SS_TAP(X_BSPC)":widepeeposad2"SS_TAP(X_ENTER)SS_TAP(X_BSPC)SS_TAP(X_ENTER));
        } else {
        }
        break;

      case SSH_PI:
        if (record->event.pressed) {
            SEND_STRING("ssh pi@applepi.local"SS_TAP(X_ENTER) SS_DELAY(2000) "Rasp91111"SS_TAP(X_ENTER));
        } else {
        }
        break;

      case GIT:
        if (record->event.pressed) {
          SEND_STRING("https://github.com/qmk/qmk_firmware/find/master"SS_TAP(X_ENTER));
        } else {
        }
        break;

      case SETUP:
        if (record->event.pressed) {
          SEND_STRING("https://docs.qmk.fm/#/newbs_getting_started");
        } else {
        }
        break;

      case ZAD:
        if (record->event.pressed) {
          SEND_STRING("https://docs.qmk.fm/#/driver_installation_zadig");
        } else {
        }
        break;

      case CONF:
        if (record->event.pressed) {
          SEND_STRING("https://config.qmk.fm/#/"SS_TAP(X_ENTER));
        } else {
        }
        break;

      case MMAP:
        if (record->event.pressed) {
            SEND_STRING(":checkpinsbich:"SS_TAP(X_ENTER)SS_TAP(X_ENTER));
            SEND_STRING("https://www.mechmap.tech/themap"SS_TAP(X_ENTER));
        } else {
        }
        break;

      case NKINV:
        if (record->event.pressed) {
            SEND_STRING("NovelKeys Inventory Updates - https://novelkeys.xyz/pages/inventory");
        } else {
        }
        break;

      case VIA:
        if (record->event.pressed) {
            SEND_STRING("https://caniusevia.com/docs/download_firmware"SS_TAP(X_ENTER));
        } else {
        }
        break;

      case CD1:
        if (record->event.pressed) {
          SEND_STRING("cd /c/Users/apple/qmk_firmware"SS_TAP(X_ENTER));
        } else {
        }
        break;

      case KC_NOMODE ... KC_ZALGO:
          if (record->event.pressed) {
            typing_mode = keycode - KC_REGIONAL;
          }
          return true;

      case ALT_TAB:
        if (record->event.pressed) {
          if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
          }
          alt_tab_timer = timer_read();
          register_code(KC_TAB);
        } else {
          unregister_code(KC_TAB);
        }
        break;

      case CAD:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_BSPC))));
          return false;
        }
        break;

      case MAKE:
        if (!record->event.pressed) {
          //SEND_STRING("cd /c/Users/apple/qmk_firmware"SS_TAP(X_ENTER)SS_DELAY(500));
          SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP
#if (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
                          ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
                          ":teensy"
#elif defined(BOOLOADER_CATERINA)
                          ":avrdude"
#endif
                          SS_TAP(X_ENTER)SS_DELAY(5000));
                          reset_keyboard();
            }
            return false;
            break;

  }

  if (typing_mode) {
      if (((KC_A <= temp_keycode) && (temp_keycode <= KC_0)) || temp_keycode == KC_SPACE) {
          if (typing_mode == TM_WIDE) { return process_record_glyph_replacement(temp_keycode, record, unicode_range_translator_wide);}
          if (typing_mode == TM_SCRIPT) {return process_record_glyph_replacement(temp_keycode, record, unicode_range_translator_script);}
          if (typing_mode == TM_BLOCKS) {return process_record_glyph_replacement(temp_keycode, record, unicode_range_translator_boxes);}
          if (typing_mode == TM_REGIONAL) {return process_record_glyph_replacement(temp_keycode, record, unicode_range_translator_regional);}
      } else {
          if (typing_mode == TM_AUSSIE) {return process_record_aussie(temp_keycode, record);}
          if (typing_mode == TM_ZALGO) {return process_record_zalgo(temp_keycode, record);}
          //if (typing_mode == MODE_WOWMODE) {return process_record_glyph_replacement(keycode, record, unicode_range_translator_wowmode);}
          //if (typing_mode == MODE_D3MODE) {return process_record_glyph_replacement(keycode, record, unicode_range_translator_d3mode);}
      }
  }
    return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    terrazzo_scroll_pixel(clockwise);
    switch(get_highest_layer(layer_state)) {
        case _QWERTY:
            clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
            break;
        case _LOWER:
            clockwise ? tap_code(KC_MNXT) : tap_code(KC_MPRV);
            break;
    }
}
