#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "stm32f1xx.h"

void SystemClock_Config(void);

void cpu_init(void);
int sys_init(void); 

#endif

