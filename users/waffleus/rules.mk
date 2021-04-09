BOOTMAGIC_ENABLE = lite
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
AUTO_SHIFT_ENABLE = no
LTO_ENABLE = yes
UNICODEMAP_ENABLE = yes

ifeq ($(strip $(KEYBOARD)), crkbd/rev1/common)
MCU = atmega32u4
BOOTLOADER = caterina
RGBLIGHT_ENABLE = yes
OLED_DRIVER_ENABLE = yes
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes
WPM_ENABLE = yes
UNICODEMAP_ENABLE = yes
POINTING_DEVICE_ENABLE = no
VIA_ENABLE = no

endif

SRC += waffleus.c \
		tapdance.c \
		combos.c \
		pru.c

#ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
#  SRC += secrets.c
#endif

ifeq ($(strip $(NO_SECRETS)), yes)
	OPT_DEFS += -DNO_SECRETS
endif

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    POINTING_DEVICE_ENABLE := yes
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
    SRC += pimoroni_trackball.c
    QUANTUM_LIB_SRC += i2c_master.c
endif

ifeq ($(strip $(BOOTLOADER)), nanoboot)
	BOOTLOADER_SIZE = 512
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += oled.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += rgb.c
endif
