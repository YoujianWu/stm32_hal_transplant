/******************MACRO***********************/
#define MAIN_CONFIG

/******************INCLUDE***********************/
#include "config.h"
#include "LED.h"	

int main(void)
{
	sys_init(); // 系统滴答、HAL库、时钟初始化
	led_init();
	while (1)
	{	
		led_toggle();
		HAL_Delay(500);
	}
}



