#include "mButton.h" 

Button button1;

uint8_t read_button_gpio(uint8_t button_id)
{
    switch (button_id) {
        case 1:
            return HAL_GPIO_ReadPin(Button_PB2_GPIO_Port, Button_PB2_Pin);
        default:
            return 0;
    }
}	

void mButton1_callback(Button* button)
{
	switch(button_get_event(button)){
        case BTN_PRESS_DOWN:
            printf("mButton1 reach BTN_PRESS_DOWN \n");
        case BTN_PRESS_UP:
            printf("mButton1 reach BTN_PRESS_UP \n");
        case BTN_PRESS_REPEAT:
            printf("mButton1 reach BTN_PRESS_REPEAT \n");
        case BTN_SINGLE_CLICK:
            printf("mButton1 reach BTN_SINGLE_CLICK \n");
        case BTN_DOUBLE_CLICK:
            printf("mButton1 reach BTN_DOUBLE_CLICK \n");
        case BTN_LONG_PRESS_START:
            printf("mButton1 reach BTN_LONG_PRESS_START \n");
        case BTN_LONG_PRESS_HOLD:
            printf("mButton1 reach BTN_LONG_PRESS_HOLD \n");			
	}
}	

void mButton_init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin : Button_PB2_Pin */
  GPIO_InitStruct.Pin = Button_PB2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(Button_PB2_GPIO_Port, &GPIO_InitStruct);

  button_init(&button1, read_button_gpio, RESET, 1);
  button_attach(&button1, BTN_SINGLE_CLICK, mButton1_callback);
  button_start(&button1);
}
