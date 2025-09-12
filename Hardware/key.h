#ifndef __KEY_H
#define __KEY_H

#include "stm32f1xx.h"
#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define KEY_PA4_Pin GPIO_PIN_4
#define KEY_PA4_GPIO_Port GPIOA
#define KEY_PA4_EXTI_IRQn EXTI4_IRQn

void key_init(void);

#ifdef __cplusplus
}
#endif

#endif
