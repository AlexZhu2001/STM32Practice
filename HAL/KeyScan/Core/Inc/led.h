#ifndef __BSP_LED_H__
#define __BSP_LED_H__
#include "stm32f1xx.h"
#define LED_GPIO_PORT GPIOB
#define LED_R GPIO_PIN_5
#define LED_G GPIO_PIN_0
#define LED_B GPIO_PIN_1
#define LED_GPIO_CLK_EN() __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED_ON GPIO_PIN_RESET
#define LED_OFF GPIO_PIN_SET
/**
@brief 
*/
void TurnOnLed(uint16_t led){
	HAL_GPIO_WritePin(LED_GPIO_PORT,led,LED_ON);
}
/**
*/
void TurnOffLed(uint16_t led){
	HAL_GPIO_WritePin(LED_GPIO_PORT,led,LED_OFF);
}
/**
*/
void RGB_On(){
	TurnOnLed(LED_R|LED_G|LED_B);
}
/**
*/
void RGB_Off(){
	TurnOffLed(LED_R|LED_G|LED_B);
}
/**
*/
void InitLed(){
	LED_GPIO_CLK_EN();
	GPIO_InitTypeDef ledpin;
	ledpin.Mode=GPIO_MODE_OUTPUT_PP;
	ledpin.Speed=GPIO_SPEED_HIGH;
	ledpin.Pin=LED_R;
	HAL_GPIO_Init(LED_GPIO_PORT,&ledpin);
	ledpin.Pin=LED_G;
	HAL_GPIO_Init(LED_GPIO_PORT,&ledpin);
	ledpin.Pin=LED_B;
	HAL_GPIO_Init(LED_GPIO_PORT,&ledpin);
	TurnOffLed(LED_R|LED_G|LED_B);
}
#endif
