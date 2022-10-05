/*
 * update7SEG.c
 *
 *  Created on: Sep 28, 2022
 *      Author: Tam Thanh Tin
 */
#include "update7SEG.h"
#include "display7SEG.h"
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {9 , 2 , 3 , 4};
void update7SEG(int index){
	switch (index){
	case 0:{
		display7SEG(led_buffer[0]);
		break;
	};
	case 1:{
		display7SEG(led_buffer[1]);
		break;
	};
	case 2:{
		display7SEG(led_buffer[2]);
		break;
		};
	case 3:{
		display7SEG(led_buffer[3]);
		break;
		}
	}
}
