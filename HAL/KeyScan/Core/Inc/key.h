#ifndef __BSP_KEY_H__
#define __BSP_KEY_H__
#include "main.h"
typedef enum{
	NoKey=0u,
	Key1,
	Key2,
} KeyNum;
KeyNum KeyScan(){
	if(HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)==GPIO_PIN_SET){
		while(HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)==GPIO_PIN_SET);
		return Key1;
	}else if(HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)==GPIO_PIN_SET){
		while(HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)==GPIO_PIN_SET);
		return Key2;
	}
	return NoKey;
}
#endif
