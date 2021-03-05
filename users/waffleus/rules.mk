SRC += waffleus.c

BOOTMAGIC_ENABLE = lite
AUDIO_ENABLE = no
GRAVE_ESC_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
SWAP_HANDS_ENABLE = no
AUTO_SHIFT_ENABLE = no
UNICODE_ENABLE = no
SPACE_CADET_ENABLE = no
MOUSEKEY_ENABLE = yes
LTO_ENABLE = yes
ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    POINTING_DEVICE_ENABLE := yes
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
    SRC += pimoroni_trackball.c
    QUANTUM_LIB_SRC += i2c_master.c
endif
ifeq ($(strip $(KEYLOGGER)), yes)
	OPT_DEFS += -DKEYLOGGER
endif
ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
	SRC += unicode.c
endif
ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += combos.c
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tapdance.c
endif
ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += oled.c
endif
ifeq ($(strip $(RGB_LIGHT_ENABLE)), yes)
	SRC += rgb.c
endif
