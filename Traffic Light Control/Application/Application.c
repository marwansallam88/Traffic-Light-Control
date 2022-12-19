/*
 * Application.c
 *
 * Created: 06/12/2022 23:38:34
 * Author: marwan
 */ 
//Include .h
#include "Application.h"

//Global variables
uint8_t carLED = 0; //0 green 1 yellow 2 red
uint8_t prevCarLED = 0;
uint8_t mode = 1; //1 normal 0 pedestrian
uint8_t count = 0;
uint8_t loop = 0;


//All application function prototypes
void App_init(void)
{
	//Button initialization
	Button_init(Button_Port,Button_Pin);

	//Pedestrian LED initialization
	LED_init(LED_Ped_Port,LED_Ped_G_Pin);
	LED_init(LED_Ped_Port,LED_Ped_Y_Pin);
	LED_init(LED_Ped_Port,LED_Ped_R_Pin);

	//Car LED initialization
	LED_init(LED_Car_Port,LED_Car_G_Pin);
	LED_init(LED_Car_Port,LED_Car_Y_Pin);
	LED_init(LED_Car_Port,LED_Car_R_Pin);

	//Timer initialization
	Timer_init();

	//Enable global interrupts 
	sei();
	
	//Setup rising edge detection for button
	RISING_EDGE_SETUP();
	
	//Setup pin D2 for external interrupts
	SETUP_INT0();
	
}

void App_start(void)
{
		if(carLED == 0)
		{
			
			LED_off(LED_Ped_Port,LED_Ped_G_Pin);
			LED_off(LED_Ped_Port,LED_Ped_Y_Pin);
			LED_off(LED_Ped_Port,LED_Ped_R_Pin);
			LED_off(LED_Car_Port,LED_Car_G_Pin);
			LED_off(LED_Car_Port,LED_Car_Y_Pin);
			LED_off(LED_Car_Port,LED_Car_R_Pin);
			if(mode == 0)
			{
				LED_on(LED_Ped_Port,LED_Ped_R_Pin);
			}
			mode = 1;
			if(mode == 1)
			{
				LED_on(LED_Car_Port,LED_Car_G_Pin);
				while(loop < 10){ 
					Timer_delay(500);
					if(mode == 0)
					{
						break;
					}
					loop++;	
				}
				loop = 0;
			}
			carLED = 1;
			prevCarLED = 0;
		}
		if(carLED == 1)
		{
			LED_off(LED_Ped_Port,LED_Ped_G_Pin);
			LED_off(LED_Ped_Port,LED_Ped_Y_Pin);
			LED_off(LED_Ped_Port,LED_Ped_R_Pin);
			LED_off(LED_Car_Port,LED_Car_G_Pin);
			LED_off(LED_Car_Port,LED_Car_Y_Pin);
			LED_off(LED_Car_Port,LED_Car_R_Pin);
			if(mode == 1)
			{
				if(prevCarLED == 0)
				{
					carLED = 2;
				}
				else if(prevCarLED == 2)
				{
					carLED = 0;
				}
				while(count < 10)
				{
					LED_toggle(LED_Car_Port,LED_Car_Y_Pin);
					Timer_delay(500);
					count++;
					if(mode == 0)
					{
						break;
					}
				}
				count = 0;
			}
			if(mode == 0)
			{
				if(prevCarLED == 0)
				{
					LED_on(LED_Ped_Port,LED_Ped_R_Pin);
					carLED = 2;
				}
				else if(prevCarLED == 2)
				{
					LED_on(LED_Ped_Port,LED_Ped_G_Pin);
					carLED = 0;
				}
				LED_off(LED_Ped_Port,LED_Ped_Y_Pin);
				LED_off(LED_Car_Port,LED_Car_Y_Pin);
				while(count < 10)
				{
					LED_toggle(LED_Ped_Port,LED_Ped_Y_Pin);
					LED_toggle(LED_Car_Port,LED_Car_Y_Pin);
					Timer_delay(500);
					count++;
				}
				count = 0;
			}
			
		}
		if(carLED == 2)
		{
			prevCarLED = 2;
			LED_off(LED_Ped_Port,LED_Ped_G_Pin);
			LED_off(LED_Ped_Port,LED_Ped_Y_Pin);
			LED_off(LED_Ped_Port,LED_Ped_R_Pin);
			LED_off(LED_Car_Port,LED_Car_G_Pin);
			LED_off(LED_Car_Port,LED_Car_Y_Pin);
			LED_off(LED_Car_Port,LED_Car_R_Pin);
			if(mode == 1)
			{
				LED_on(LED_Car_Port,LED_Car_R_Pin);
				while(loop < 10){ 
					Timer_delay(500);
					if(mode == 0)
					{
						break;
					}
					loop++;	
				}
				loop = 0;
			}
			if(mode == 0)
			{
				LED_on(LED_Car_Port,LED_Car_R_Pin);
				LED_on(LED_Ped_Port,LED_Ped_G_Pin);
				Timer_delay(5000);
			}
			carLED = 1;
		}
}

ISR(EXT_INT_0){
	mode = 0;
	if(carLED == 1 && prevCarLED == 0){
		LED_on(LED_Ped_Port,LED_Ped_R_Pin);
	}
}