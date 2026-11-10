#ifndef INC_TB6612_H_
#define INC_TB6612_H_

#include "main.h"

void TB6612_Init(void);
void TB6612_SetDuty(int16_t speed);
void TB6612_Stop(void);
void TB6612_Break(void);

#endif
