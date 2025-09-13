/******************MACRO***********************/
#define MAIN_CONFIG

/******************INCLUDE***********************/
#include "config.h"
#include "LED.h"	
#include "mTimer.h"
#include "serial.h"
#include "key.h"
#include "mButton.h"

int main(void)
{
	sys_init(); // 系统滴答、HAL库、时钟初始化
	led_init();
	mTimer_init();
	serial_init(); // 需要真实硬件测试
	key_init(); // 需要真实硬件测试
	mButton_init(); // 需要真实硬件测试
//	iwdg_init(); // 需要真实硬件测试
	while (1)
	{	
//		led1_toggle();
//		HAL_Delay(500);
//		led2_toggle();
//		HAL_Delay(250);
		
		timer_loop(); // for multii_timer
	}
}



