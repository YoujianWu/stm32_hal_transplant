#include "LED.h"

void led_init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_PA3_GPIO_Port, LED_PA3_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_PB0_GPIO_Port, LED_PB0_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : LED_PA3_Pin */
  GPIO_InitStruct.Pin = LED_PA3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED_PA3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_PB0_Pin */
  GPIO_InitStruct.Pin = LED_PB0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED_PB0_GPIO_Port, &GPIO_InitStruct);
  

}

void led1_toggle(void)
{
	HAL_GPIO_TogglePin(LED_PA3_GPIO_Port,LED_PA3_Pin);
}

void led2_toggle(void)
{
	HAL_GPIO_TogglePin(LED_PB0_GPIO_Port,LED_PB0_Pin);
}

