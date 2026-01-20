/*
 * mesure_consommation_courant.c
 *
 *  Created on: Jun 19, 2024
 *      Author: antotauv
 */
#include "main.h"
#include "mesure_consommation_courant.h"
#include "led.h"
#include <stdio.h>

void setup(){
	printf("**** TP5 : liaisons et bus, consommation electrique**** \r\n");
	HAL_TIM_Base_Start(&htim4);
	HAL_ADC_Start_IT(&hadc1);
}

void loop(){
	HAL_PWR_EnterSLEEPMode(NULL,PWR_SLEEPENTRY_WFI);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	static int isOn=0;
	if(GPIO_Pin==ENC_BTN_Pin){
		printf("BTN pressed \r\n");
		LED_Set_Value_With_Int((isOn==0)?0:255);
		isOn=1-isOn;
		LED_Update();
	}
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){
	if(hadc->Instance == ADC1){
		uint16_t adc_read=HAL_ADC_GetValue(&hadc1);
		float voltage = (adc_read*3.3)/4095;
		float intensity = (voltage*1000)/(0.4*200);
		printf("Mesure courant : %d \t %f \t %f\r\n",(int) adc_read, voltage, intensity);
	}
}
