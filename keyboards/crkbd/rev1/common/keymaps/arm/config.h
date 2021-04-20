#pragma once
#define MASTER_LEFT
#undef USE_I2C
#undef SDD1306OLED
#define USE_SERIAL_PD2
#ifdef RGBLIGHT_ENABLE
#undef RGBLED_NUM
#define RGBLED_NUM 24
#define RGBLED_SPLIT { 12, 12 }
#undef RGB_DI_PIN
#define RGB_DI_PIN B5
#define RGBLIGHT_LIMIT_VAL 175
#endif //rgb
#ifdef OLED_DRIVER_ENABLE
#define OLED_TIMEOUT 30000
#define OLED_FONT_H "keyboards/crkbd/rev1/common/keymaps/arm/glcdfont.c"
#endif //oled
#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM3
#define WS2812_DMA_CHANNEL 3
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D3
#define SELECT_SOFT_SERIAL_SPEED 1
#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_TX_PAL_MODE 7
