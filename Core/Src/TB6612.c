#include "TB6612.h"
#include "tim.h"

void TB6612_Init(void)
{
  // 初始化电机驱动
  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
  HAL_GPIO_WritePin(STBY_GPIO_Port, STBY_Pin, GPIO_PIN_SET);
}

void TB6612_Stop(void)
{
  // 停止电机驱动
  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
  HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_RESET);
}

void TB6612_SetDuty(int16_t duty)
{
    
}
