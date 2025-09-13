#ifndef __IWDG_H__
#define __IWDG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx.h"

extern IWDG_HandleTypeDef hiwdg;

void iwdg_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __IWDG_H__ */
