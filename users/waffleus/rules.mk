SRC += waffleus.c

BOOTMAGIC_ENABLE = lite
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
AUTO_SHIFT_ENABLE = no
LTO_ENABLE = yes
ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    POINTING_DEVICE_ENABLE := yes
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
    SRC += pimoroni_trackball.c
    QUANTUM_LIB_SRC += i2c_master.c
endif

ifeq ($(strip $(KEYBOARD)), crkbd/rev1/common)
MCU = STM32F303
CTPC = yes
DEBUG_MATRIX_SCAN_RATE_ENABLE = yes
SERIAL_DRIVER = usart
WS2812_DRIVER = pwm
#PWM needs patch to <https://github.com/qmk/qmk_firmware/blob/master/platforms/chibios/GENERIC_STM32_F303XC/configs/proton_c.mk>, otherwise defaults to bitbang.
#See develop PR <https://github.com/qmk/qmk_firmware/pull/11864>
VIA_ENABLE = yes
OLED_DRIVER_ENABLE = yes
WPM_ENABLE = yes
COMMAND_ENABLE = yes
UNICODEMAP_ENABLE = yes
AUTO_SHIFT_ENABLE = no
CONSOLE_ENABLE = yes
POINTING_DEVICE_ENABLE = no
SPLIT_KEYBOARD = yes
RGBLIGHT_ENABLE = yes
NKRO_ENABLE = yes
endif
ifeq ($(strip $(KEYBOARD)), crkbd/rev1)
MCU = atmega32u4
BOOTLOADER = caterina
#BOOTLOADER = nano-boot
#BOOTLOADER_SIZE = 512
RGBLIGHT_ENABLE = no
AUDIO_ENABLE = no
OLED_DRIVER_ENABLE = no
GRAVE_ESC_ENABLE = no
EXTRAKEY_ENABLE = no
LTO_ENABLE = yes
WPM_ENABLE = yes
UNICODEMAP_ENABLE = no
POINTING_DEVICE_ENABLE = no
endif
