MCU = STM32F103
BOOTLOADER = stm32duino
BOOTMAGIC_ENABLE = lite
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
SLEEP_LED_ENABLE = no
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no
BLUETOOTH_ENABLE = no
AUDIO_ENABLE = no
OLED_DRIVER_ENABLE = yes
ENCODER_ENABLE = yes
WPM_ENABLE = yes
TAP_DANCE_ENABLE = yes
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
