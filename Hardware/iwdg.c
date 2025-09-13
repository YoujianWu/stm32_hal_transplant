#include "iwdg.h"

IWDG_HandleTypeDef hiwdg;

/* IWDG init function */
void iwdg_init(void)
{	
  hiwdg.Instance = IWDG;
  // 通常iwdg是使用lSI低速内部时钟的，其运行频率为30-60KHZ	，但会出现漂移，这里选40KHZ
  hiwdg.Init.Prescaler = IWDG_PRESCALER_64;  // 分频系数
  hiwdg.Init.Reload = 1250; //重装数
	
  // 64/40*1250 = 2000ms，超过2s不喂狗就会重启程序	
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
    while(1);
  }

}
