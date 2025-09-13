#ifndef __MTIMER_H
#define __MTIMER_H

#include "multi_timer.h"
#include "led.h"
#include "serial.h"
#include "mButton.h"
#include "iwdg.h"

#ifdef __cplusplus
extern "C" {
#endif

extern struct Timer mtimer1;
extern struct Timer mtimer2;
extern struct Timer mtimer3;
extern struct Timer mtimer4;
extern struct Timer mtimer5;

void mTimer_init(void);
void mtimer1_callback(void *arg);
void mtimer2_callback(void *arg);
void mtimer3_callback(void *arg);
void mtimer4_callback(void *arg);
void mtimer5_callback(void *arg);


#ifdef __cplusplus
}
#endif

#endif
