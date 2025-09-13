#include "mTimer.h" 


struct Timer mtimer1;
struct Timer mtimer2;
struct Timer mtimer3;
struct Timer mtimer4;
struct Timer mtimer5;

void mtimer1_callback(void *arg)
{
	led1_toggle();
}

void mtimer2_callback(void *arg)
{
	led2_toggle();
}

void mtimer3_callback(void *arg)
{
	// 1s打印一次程序运行了多久
	printf("system running time is : %d s \n", HAL_GetTick()/ (1000u / uwTickFreq));
}

void mtimer4_callback(void *arg)
{
	button_ticks();
}

void mtimer5_callback(void *arg)
{
	HAL_IWDG_Refresh(&hiwdg); //喂看门狗
	printf("Feed dog ok \n");
}

void mTimer_init(void)
{
   timer_init(&mtimer1, mtimer1_callback, 500, 500, NULL);
   timer_start(&mtimer1);
	
   timer_init(&mtimer2, mtimer2_callback, 250, 250, NULL);
   timer_start(&mtimer2);

   timer_init(&mtimer3, mtimer3_callback, 1000, 1000, NULL);
   timer_start(&mtimer3);	

   timer_init(&mtimer4, mtimer4_callback, 0, 5, NULL);
   timer_start(&mtimer4);

   timer_init(&mtimer5, mtimer5_callback, 1000, 1000, NULL);
   timer_start(&mtimer5);			
	
}
