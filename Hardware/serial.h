#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx.h"
#include "config.h"

extern UART_HandleTypeDef huart1;

void serial_init(void);


#ifdef __cplusplus
}
#endif

#endif
