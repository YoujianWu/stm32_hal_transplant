#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx.h"
#include "config.h"


extern uint8_t rx_buffer[256]; //串口接收缓存区
extern uint8_t rx_dara_pos; // 数据在串口接收缓存区中的位置
extern UART_HandleTypeDef huart1;

void serial_init(void);


#ifdef __cplusplus
}
#endif

#endif
