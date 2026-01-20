/*
 * utils.c
 *
 *  Created on: Sep 25, 2023
 *      Author: antotauv
 */

#include "utils.h"
#include "main.h"
#include "utils.h"
#include "ssd1315.h"
#include "fonts.h"
//#include "cityDataBase.h"
#include <stdio.h>

void setup(){
	printf ("TP1 ENSEA by A.T. \r\n");
	ssd1315_Init();
	ssd1315_Clear(SSD1315_COLOR_BLACK);
	ssd1315_Draw_String(0,0,"GPS Lab",&Font_16x26);
	ssd1315_Refresh();
	HAL_GPIO_WritePin(GPS_ENN_GPIO_Port,GPS_ENN_Pin,1);
}

static char buffer[BUFFER_SIZE]={0};

void loop(){
	int size = fillBuffer(buffer);
	printf("Just received : %s\r\n",buffer);

}
