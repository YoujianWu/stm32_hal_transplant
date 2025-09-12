#include "serial.h"

uint8_t rx_buffer[256]; //串口接收缓存区
uint8_t rx_dara_pos = 0; // 数据在串口接收缓存区中的位置

UART_HandleTypeDef huart1;

void serial_init(void)
{
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    while(1);
  }
  
  // 串口中断有多重接收模式
  // 启动串口接收非空中断（每有一个字节触发一次）
  __HAL_UART_ENABLE_IT(&huart1,UART_IT_RXNE);
  // 启动串口接收空闲中断（由忙到空闲触发一次）
  __HAL_UART_ENABLE_IT(&huart1,UART_IT_RXNE);
  
}	

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
	
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

	  
    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
	  
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
}

void USART1_IRQHandler(void)
{
	uint8_t receive_char;
	
	if(__HAL_USART_GET_FLAG(&huart1, UART_FLAG_RXNE) != RESET) //接收非空中断
	{
		HAL_UART_Receive(&huart1, &receive_char, 1, 1000);
		rx_buffer[rx_dara_pos] = receive_char;
		rx_dara_pos++;
		
		__HAL_USART_CLEAR_FLAG(&huart1,USART_FLAG_RXNE);
	}
	
	if(__HAL_USART_GET_FLAG(&huart1, UART_FLAG_IDLE) != RESET) //接收空闲中断，keil不支持仿真空闲中断，需要在实际硬件上测试
	{
		rx_buffer[rx_dara_pos] = '\0'; // 添加字符串结束符
		printf("usart1 receive : %s \n", rx_buffer);
		rx_dara_pos = 0; // 重置位置
		
		__HAL_USART_CLEAR_IDLEFLAG(&huart1);
	}
}


// for printf
int fputc(int ch, FILE *f) {
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}

// for scanf
int fgetc(FILE *f) 
{
    uint8_t ch = 0;
    HAL_UART_Receive(&huart1, &ch, 1, HAL_MAX_DELAY);
    return ch; 
}
