/******************MACRO***********************/
#define MAIN_CONFIG

/******************INCLUDE***********************/
#include "config.h"
#include "LED.h"	
#include "mTimer.h"
#include "serial.h"

int main(void)
{
	sys_init(); // 系统滴答、HAL库、时钟初始化
	led_init();
	mTimer_init();
	serial_init();
	while (1)
	{	
//		led1_toggle();
//		HAL_Delay(500);
//		led2_toggle();
//		HAL_Delay(250);
		
		// for multii_timer
		timer_loop();
	}
}



