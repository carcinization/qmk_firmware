/*     INCLUDE THIS IN artsey.h:

	APPLYSTYLES,
	HEAD1,
	HEAD2,
	HEAD3,
	HEAD4,
	LVL1,
	LVL3,
	TBLLVL1,
	TBLLVL3,
	QRGB1,
	QRGB2,
	QRGB3,
	TBLQRGB1,
	TBLQRGB2,
	TBLQRGB3,
	BODY1,
	BODY2,
	BODY3,
	BODY4,
	TBLBOD1,
	TBLBOD2,
	TBLBOD3,
	TBLBOD4,
	NOTE,
	WARN,
	TBLNOTE,
	TBLWARN,
	STRONG,
	SUBEM,
	CON,
	INT,
	MSJG*/
 
 
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
 
	case MSJG:
		if (record->event.pressed) {
			