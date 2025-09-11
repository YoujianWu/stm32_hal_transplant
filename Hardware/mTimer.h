#ifndef __MTIMER_H
#define __MTIMER_H

#include "multi_timer.h"
#include "led.h"
#include "serial.h"

#ifdef __cplusplus
extern "C" {
#endif

void mTimer_init(void);
void mtimer1_callback(void *arg);
void mtimer2_callback(void *arg);
void mtimer3_callback(void *arg);


#ifdef __cplusplus
}
#endif

#endif
