bool is_shift_lock_active = false; 
bool other_key_pressed = false;
bool is_alt_tab_active = false; // ADD this near the begining of keymap.c;
uint16_t key_timer = 0;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {


  switch (keycode) {


    case LOCK_SHIFT:
      if (record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        }
        else{
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        }         
      } 
    break;
case A_BASE_AR:
if(record->event.pressed) {
tap_code(KC_F);
}
else {}
 break;
case A_BASE_AS:
if(record->event.pressed) {
tap_code(KC_W);
}
else {}
 break;
case A_BASE_RT:
if(record->event.pressed) {
tap_code(KC_G);
}
else {}
 break;
case A_BASE_RS:
if(record->event.pressed) {
tap_code(KC_V);
}
else {}
 break;
case A_BASE_TS:
if(record->event.pressed) {
tap_code(KC_J);
}
else {}
 break;
case A_BASE_ART:
if(record->event.pressed) {
tap_code(KC_D);
}
else {}
 break;
case A_BASE_ATS:
if(record->event.pressed) {
tap_code(KC_Q);
}
else {}
 break;
case A_BASE_RTS:
if(record->event.pressed) {
tap_code(KC_X);
}
else {}
 break;
case A_BASE_EY:
if(record->event.pressed) {
tap_code(KC_C);
}
else {}
 break;
case A_BASE_EI:
if(record->event.pressed) {
tap_code(KC_H);
}
else {}
 break;
case A_BASE_EO:
if(record->event.pressed) {
tap_code(KC_B);
}
else {}
 break;
case A_BASE_YI:
if(record->event.pressed) {
tap_code(KC_U);
}
else {}
 break;
case A_BASE_YO:
if(record->event.pressed) {
tap_code(KC_K);
}
else {}
 break;
case A_BASE_IO:
if(record->event.pressed) {
tap_code(KC_Y);
}
else {}
 break;
case A_BASE_EYI:
if(record->event.pressed) {
tap_code(KC_L);
}
else {}
 break;
case A_BASE_EIO:
if(record->event.pressed) {
tap_code(KC_P);
}
else {}
 break;
case A_BASE_YIO:
if(record->event.pressed) {
tap_code(KC_M);
}
else {}
 break;
case A_BASE_ARTS:
if(record->event.pressed) {
tap_code(KC_Z);
}
else {}
 break;
case A_BASE_AYI:
if(record->event.pressed) {
tap_code(KC_QUOT);
}
else {}
 break;
case A_BASE_AY:
if(record->event.pressed) {
tap_code(KC_COMMA);
}
else {}
 break;
case A_BASE_AI:
if(record->event.pressed) {
tap_code(KC_DOT);
}
else {}
 break;
case A_BASE_TI:
if(record->event.pressed) {
SEND_STRING("!");
}
else {}
 break;
case A_BASE_AO:
if(record->event.pressed) {
tap_code(KC_SLSH);
}
else {}
 break;
case A_BASE_RE:
if(record->event.pressed) {
tap_code(KC_BSPC);
}
else {}
 break;
case A_NUM_RE:
if(record->event.pressed) {
tap_code(KC_BSPC);
}
else {}
 break;
case A_SYM_RE:
if(record->event.pressed) {
tap_code(KC_BSPC);
}
else {}
 break;
case A_BRAC_RE:
if(record->event.pressed) {
tap_code(KC_BSPC);
}
else {}
 break;
case A_NAV_RE:
if(record->event.pressed) {
tap_code(KC_BSPC);
}
else {}
 break;
case A_MOU_RE:
if(record->event.pressed) {
tap_code(KC_BSPC);
}
else {}
 break;
case A_CUSTOM_RE:
if(record->event.pressed) {
tap_code(KC_BSPC);
}
else {}
 break;
case A_BASE_RTSE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LSHIFT));
}
else {}
 break;
case A_NUM_RTSE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LSHIFT));
}
else {}
 break;
case A_SYM_RTSE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LSHIFT));
}
else {}
 break;
case A_BRAC_RTSE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LSHIFT));
}
else {}
 break;
case A_NAV_RTSE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LSHIFT));
}
else {}
 break;
case A_MOU_RTSE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LSHIFT));
}
else {}
 break;
case A_CUSTOM_RTSE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LSHIFT));
}
else {}
 break;
case A_BASE_AE:
if(record->event.pressed) {
tap_code(KC_ENTER);
}
else {}
 break;
case A_NUM_AE:
if(record->event.pressed) {
tap_code(KC_ENTER);
}
else {}
 break;
case A_SYM_AE:
if(record->event.pressed) {
tap_code(KC_ENTER);
}
else {}
 break;
case A_BRAC_AE:
if(record->event.pressed) {
tap_code(KC_ENTER);
}
else {}
 break;
case A_NAV_AE:
if(record->event.pressed) {
tap_code(KC_ENTER);
}
else {}
 break;
case A_MOU_AE:
if(record->event.pressed) {
tap_code(KC_ENTER);
}
else {}
 break;
case A_CUSTOM_AE:
if(record->event.pressed) {
tap_code(KC_ENTER);
}
else {}
 break;
case A_BASE_ARO:
if(record->event.pressed) {
tap_code(KC_ESC);
}
else {}
 break;
case A_NUM_ARO:
if(record->event.pressed) {
tap_code(KC_ESC);
}
else {}
 break;
case A_SYM_ARO:
if(record->event.pressed) {
tap_code(KC_ESC);
}
else {}
 break;
case A_BRAC_ARO:
if(record->event.pressed) {
tap_code(KC_ESC);
}
else {}
 break;
case A_NAV_ARO:
if(record->event.pressed) {
tap_code(KC_ESC);
}
else {}
 break;
case A_MOU_ARO:
if(record->event.pressed) {
tap_code(KC_ESC);
}
else {}
 break;
case A_CUSTOM_ARO:
if(record->event.pressed) {
tap_code(KC_ESC);
}
else {}
 break;
case A_BASE_SE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LCTRL));
}
else {}
 break;
case A_NUM_SE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LCTRL));
}
else {}
 break;
case A_SYM_SE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LCTRL));
}
else {}
 break;
case A_BRAC_SE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LCTRL));
}
else {}
 break;
case A_NAV_SE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LCTRL));
}
else {}
 break;
case A_MOU_SE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LCTRL));
}
else {}
 break;
case A_CUSTOM_SE:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LCTRL));
}
else {}
 break;
case A_BASE_SY:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LGUI));
}
else {}
 break;
case A_NUM_SY:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LGUI));
}
else {}
 break;
case A_SYM_SY:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LGUI));
}
else {}
 break;
case A_BRAC_SY:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LGUI));
}
else {}
 break;
case A_NAV_SY:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LGUI));
}
else {}
 break;
case A_MOU_SY:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LGUI));
}
else {}
 break;
case A_CUSTOM_SY:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LGUI));
}
else {}
 break;
case A_BASE_SI:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LALT));
}
else {}
 break;
case A_NUM_SI:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LALT));
}
else {}
 break;
case A_SYM_SI:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LALT));
}
else {}
 break;
case A_BRAC_SI:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LALT));
}
else {}
 break;
case A_NAV_SI:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LALT));
}
else {}
 break;
case A_MOU_SI:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LALT));
}
else {}
 break;
case A_CUSTOM_SI:
if(record->event.pressed) {
set_oneshot_mods(MOD_BIT(KC_LALT));
}
else {}
 break;
case A_BASE_EYIO:
if(record->event.pressed) {
tap_code(KC_SPACE);
}
else {}
 break;
case A_NUM_EYIO:
if(record->event.pressed) {
tap_code(KC_SPACE);
}
else {}
 break;
case A_SYM_EYIO:
if(record->event.pressed) {
tap_code(KC_SPACE);
}
else {}
 break;
case A_BRAC_EYIO:
if(record->event.pressed) {
tap_code(KC_SPACE);
}
else {}
 break;
case A_NAV_EYIO:
if(record->event.pressed) {
tap_code(KC_SPACE);
}
else {}
 break;
case A_MOU_EYIO:
if(record->event.pressed) {
tap_code(KC_SPACE);
}
else {}
 break;
case A_CUSTOM_EYIO:
if(record->event.pressed) {
tap_code(KC_SPACE);
}
else {}
 break;
case A_BASE_ARTO:
if(record->event.pressed) {
tap_code(KC_TAB);
}
else {}
 break;
case A_NUM_ARTO:
if(record->event.pressed) {
tap_code(KC_TAB);
}
else {}
 break;
case A_SYM_ARTO:
if(record->event.pressed) {
tap_code(KC_TAB);
}
else {}
 break;
case A_BRAC_ARTO:
if(record->event.pressed) {
tap_code(KC_TAB);
}
else {}
 break;
case A_NAV_ARTO:
if(record->event.pressed) {
tap_code(KC_TAB);
}
else {}
 break;
case A_MOU_ARTO:
if(record->event.pressed) {
tap_code(KC_TAB);
}
else {}
 break;
case A_CUSTOM_ARTO:
if(record->event.pressed) {
tap_code(KC_TAB);
}
else {}
 break;
case A_BASE_RY:
if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        }
        else{
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
}
else {}
 break;
case A_NUM_RY:
if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        }
        else{
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
}
else {}
 break;
case A_SYM_RY:
if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        }
        else{
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
}
else {}
 break;
case A_BRAC_RY:
if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        }
        else{
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
}
else {}
 break;
case A_NAV_RY:
if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        }
        else{
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
}
else {}
 break;
case A_MOU_RY:
if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        }
        else{
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
}
else {}
 break;
case A_CUSTOM_RY:
if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        }
        else{
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
}
else {}
 break;
case A_NUM_AR:
if(record->event.pressed) {
tap_code(KC_7);
}
else {}
 break;
case A_NUM_RT:
if(record->event.pressed) {
tap_code(KC_8);
}
else {}
 break;
case A_NUM_EY:
if(record->event.pressed) {
tap_code(KC_9);
}
else {}
 break;
case A_NUM_YI:
if(record->event.pressed) {
tap_code(KC_0);
}
else {}
 break;
case A_BASE_ATY:
if(record->event.pressed) {
layer_move(_A_MOU);
}
else {}
 break;
case A_NUM_ATY:
if(record->event.pressed) {
layer_move(_A_MOU);
}
else {}
 break;
case A_SYM_ATY:
if(record->event.pressed) {
layer_move(_A_MOU);
}
else {}
 break;
case A_BRAC_ATY:
if(record->event.pressed) {
layer_move(_A_MOU);
}
else {}
 break;
case A_NAV_ATY:
if(record->event.pressed) {
layer_move(_A_MOU);
}
else {}
 break;
case A_CUSTOM_ATY:
if(record->event.pressed) {
layer_move(_A_MOU);
}
else {}
 break;
case A_MOU_ATY:
if(record->event.pressed) {
layer_move(_A_BASE);
}
else {}
 break;
case A_BASE_REI:
if(record->event.pressed) {
layer_move(_A_NAV);
}
else {}
 break;
case A_NUM_REI:
if(record->event.pressed) {
layer_move(_A_NAV);
}
else {}
 break;
case A_SYM_REI:
if(record->event.pressed) {
layer_move(_A_NAV);
}
else {}
 break;
case A_BRAC_REI:
if(record->event.pressed) {
layer_move(_A_NAV);
}
else {}
 break;
case A_MOU_REI:
if(record->event.pressed) {
layer_move(_A_NAV);
}
else {}
 break;
case A_CUSTOM_REI:
if(record->event.pressed) {
layer_move(_A_NAV);
}
else {}
 break;
case A_NAV_REI:
if(record->event.pressed) {
layer_move(_A_BASE);
}
else {}
 break;
case A_BASE_SO:
if(record->event.pressed) {
layer_move(_A_CUSTOM);
}
else {}
 break;
case A_CUSTOM_SO:
if(record->event.pressed) {
layer_move(_A_BASE);
}
else {}
 break;
case A_BASE_AYIO:
if(record->event.pressed) {
tap_code(KC_CAPS);
}
else {}
 break;
 
 case APPLYSTYLES:
        if (record->event.pressed) {
            // when keycode APPLYSTYLES is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s")));
        } else {
            // when keycode APPLYSTYLES is released
		}
        break;
	
	case HEAD1:
        if (record->event.pressed) {
            // when keycode HEAD1 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Heading 1"SS_TAP(X_ENT));
        } else {
            // when keycode HEAD1 is released
		}
        break;
	
	case HEAD2:
        if (record->event.pressed) {
            // when keycode HEAD2 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Heading 2"SS_TAP(X_ENT));
        } else {
            // when keycode HEAD2 is released
		}
        break;
	
	case HEAD3:
        if (record->event.pressed) {
            // when keycode HEAD3 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Heading 3"SS_TAP(X_ENT));
        } else {
            // when keycode HEAD3 is released
		}
        break;
		
	case HEAD4:
        if (record->event.pressed) {
            // when keycode HEAD4 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Heading 4"SS_TAP(X_ENT));
        } else {
            // when keycode HEAD4 is released
		}
        break;
 
	case LVL1:
        if (record->event.pressed) {
            // when keycode LVL1 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Level 1"SS_TAP(X_ENT));
        } else {
            // when keycode LVL1 is released
		}
        break;

	case LVL3:
        if (record->event.pressed) {
            // when keycode LVL3 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Level 3"SS_TAP(X_ENT));
        } else {
            // when keycode LVL3 is released
		}
        break;

	case TBLLVL1:
        if (record->event.pressed) {
            // when keycode TBLLVL1 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Table Level 1"SS_TAP(X_ENT));
        } else {
            // when keycode TBLLVL1 is released
		}
        break;
  
	case TBLLVL3:
        if (record->event.pressed) {
            // when keycode TBLLVL3 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Table Level 3"SS_TAP(X_ENT));
        } else {
            // when keycode TBLLVL3 is released
		}
        break;

	case QRGB1:
        if (record->event.pressed) {
            // when keycode QRGB1 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"QRG Bullet 1"SS_TAP(X_ENT));
        } else {
            // when keycode QRGB1 is released
		}
        break;
  
	case QRGB2:
        if (record->event.pressed) {
            // when keycode QRGB2 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"QRG Bullet 2"SS_TAP(X_ENT));
        } else {
            // when keycode QRGB2 is released
		}
        break;
   
	case QRGB3:
        if (record->event.pressed) {
            // when keycode QRGB3 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"QRG Bullet 3"SS_TAP(X_ENT));
        } else {
            // when keycode QRGB3 is released
		}
        break;
	
	case TBLQRGB1:
        if (record->event.pressed) {
            // when keycode TBLQRGB1 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Table Bullet 1"SS_TAP(X_ENT));
        } else {
            // when keycode TBLQRGB1 is released
		}
        break;
	
	case TBLQRGB2:
        if (record->event.pressed) {
            // when keycode TBLQRGB2 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Table Bullet 2"SS_TAP(X_ENT));
        } else {
            // when keycode TBLQRGB2 is released
		}
        break;
	
	case TBLQRGB3:
        if (record->event.pressed) {
            // when keycode TBLQRGB3 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Table Bullet 3"SS_TAP(X_ENT));
        } else {
            // when keycode TBLQRGB3 is released
		}
        break;
	
	case BODY1:
        if (record->event.pressed) {
            // when keycode BODY1 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Body 1"SS_TAP(X_ENT));
        } else {
            // when keycode BODY1 is released
		}
        break;
	
	case BODY2:
        if (record->event.pressed) {
            // when keycode BODY2 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Body 2"SS_TAP(X_ENT));
        } else {
            // when keycode BODY2 is released
		}
        break;
	
	case BODY3:
        if (record->event.pressed) {
            // when keycode BODY3 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Body 3"SS_TAP(X_ENT));
        } else {
            // when keycode BODY3 is released
		}
        break;
	
	case BODY4:
        if (record->event.pressed) {
            // when keycode BODY4 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Body 4"SS_TAP(X_ENT));
        } else {
            // when keycode BODY4 is released
		}
        break;
	
	case TBLBOD1:
        if (record->event.pressed) {
            // when keycode TBLBOD1 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Table Body 1"SS_TAP(X_ENT));
        } else {
            // when keycode TBLBOD1 is released
		}
        break;
	
	case TBLBOD2:
        if (record->event.pressed) {
            // when keycode TBLBOD2 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Table Body 2"SS_TAP(X_ENT));
        } else {
            // when keycode TBLBOD2 is released
		}
        break;
	
	case TBLBOD3:
        if (record->event.pressed) {
            // when keycode TBLBOD3 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Table Body 3"SS_TAP(X_ENT));
        } else {
            // when keycode TBLBOD3 is released
		}
        break;
	
	case TBLBOD4:
        if (record->event.pressed) {
            // when keycode TBLBOD4 is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Table Body 4"SS_TAP(X_ENT));
        } else {
            // when keycode TBLBOD4 is released
		}
        break;
	
	case NOTE:
        if (record->event.pressed) {
            // when keycode NOTE is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Note Text"SS_TAP(X_ENT));
        } else {
            // when keycode NOTE is released
		}
        break;
	
	case WARN:
        if (record->event.pressed) {
            // when keycode WARN is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Warning Text"SS_TAP(X_ENT));
        } else {
            // when keycode WARN is released
		}
        break;
	
	case TBLNOTE:
        if (record->event.pressed) {
            // when keycode TBLNOTE is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Table Note Text"SS_TAP(X_ENT));
        } else {
            // when keycode TBLNOTE is released
		}
        break;
	
	case TBLWARN:
        if (record->event.pressed) {
            // when keycode TBLWARN is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Table Warning Text"SS_TAP(X_ENT));
        } else {
            // when keycode TBLWARN is released
		}
        break;
	
	case STRONG:
        if (record->event.pressed) {
            // when keycode STRONG is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Strong"SS_TAP(X_ENT));
        } else {
            // when keycode STRONG is released
		}
        break;
	
	case SUBEM:
        if (record->event.pressed) {
            // when keycode SUBEM is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"Subtle Emphasis"SS_TAP(X_ENT));
        } else {
            // when keycode SUBEM is released
		}
        break;
	
	case CON:
        if (record->event.pressed) {
            // when keycode CON is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"QRG Contents"SS_TAP(X_ENT));
        } else {
            // when keycode CON is released
		}
        break;
	
	case INT:
        if (record->event.pressed) {
            // when keycode INT is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("s"))"QRG Introduction"SS_TAP(X_ENT));
        } else {
            // when keycode INT is released
		}
        break;
 
  }
  return true;
};

