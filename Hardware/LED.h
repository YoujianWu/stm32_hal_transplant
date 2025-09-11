#ifndef __LED_H
#define __LED_H

#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LED_PA3_Pin GPIO_PIN_3
#define LED_PA3_GPIO_Port GPIOA
#define LED_PB0_Pin GPIO_PIN_0
#define LED_PB0_GPIO_Port GPIOB

void led_init(void);
void led1_toggle(void);
void led2_toggle(void);

#ifdef __cplusplus
}
#endif

#endif
