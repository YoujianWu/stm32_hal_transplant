#ifndef __PWM_H__
#define __PWM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx.h"

// complementary pwm
// PWM Mode1: CH1是占空比的时候，为高电平，CH1N为低电平
// PWM Mode2: CH1是占空比的时候，为低电平，CH1N为高电平
// 不输出PWM波时，肯定是分频、计数、脉宽有一个没设置好

#define TIM1_CH1N_Pin GPIO_PIN_7
#define TIM1_CH1N_GPIO_Port GPIOA
#define TIM1_CH1_Pin GPIO_PIN_8
#define TIM1_CH1_GPIO_Port GPIOA
#define PWM_PRESCA 72-1
#define PWM_PERIOD 100-1
#define PWM_PLUSE (100-1)*0.5
#define PWM_DEADTIME (100-1)*0.3 //死区时间是互补PWM波之间的相移

extern TIM_HandleTypeDef htim1;

void pwm_init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

#ifdef __cplusplus
}
#endif

#endif 
