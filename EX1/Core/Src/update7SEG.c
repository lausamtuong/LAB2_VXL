/*
 * update7SEG.c
 *
 *  Created on: Sep 28, 2022
 *      Author: Tam Thanh Tin
 */
#include "update7SEG.h"
#include "display7SEG.h"

led_buffer[4] = {9 , 2 , 3 , 4};
void update7SEG(int index){
	index %=4;
	switch (index){
	case 0:{
		display7SEG(led_buffer[0]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
		break;
	};
	case 1:{
		display7SEG(led_buffer[1]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
		break;
	};
	case 2:{
		display7SEG(led_buffer[2]);
		 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
		break;
		};
	case 3:{
		display7SEG(led_buffer[3]);
		 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,0);
		break;
		}
	}
}
