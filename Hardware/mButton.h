#ifndef __MBUTTON_H
#define __MBUTTON_H

#include "multi_button.h"
#include "stm32f1xx.h"
#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define Button_PB2_Pin GPIO_PIN_2
#define Button_PB2_GPIO_Port GPIOB

extern Button button1;

void mButton_init(void);
void mButton1_callback(Button* button);

uint8_t read_button_gpio(uint8_t button_id);

#ifdef __cplusplus
}
#endif

#endif
