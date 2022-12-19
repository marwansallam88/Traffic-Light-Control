/*
 * Traffic Light Control.c
 *
 * Created: 06/12/2022 23:27:51
 * Author : marwan
 */ 

//Include .h
#include "Application/Application.h"
uint8_t buttonState = 0; // used for testing

//Main Code
int main(void)
{
	//Initialize
	App_init();
	
	//Main loop
	while(1){
		App_start();
	}
}

// Main Code
// int main(void)
// {
// 	//Initialize
// 	Button_init(Button_Port,Button_Pin);
// 	LED_init(LED_Car_Port, LED_Car_G_Pin);
// 	LED_init(LED_Car_Port, LED_Car_R_Pin);
// 	
// 	//Timer initialization
// 	Timer_init();
// 
// 	//Enable global interrupts
// 	sei();
// 	
// 	//Setup rising edge detection for button
// 	RISING_EDGE_SETUP();
// 	
// 	//Setup pin D2 for external interrupts
// 	SETUP_INT0();
// 	//Main loop
// 	while(1){
// 		Button_read(Button_Port,Button_Pin, &buttonState);
// 		if(buttonState == HIGH)
// 		{
// 			LED_on(LED_Car_Port, LED_Car_G_Pin);
// 		}
// 		else if(buttonState == LOW)
// 		{
// 			LED_off(LED_Car_Port, LED_Car_G_Pin);
// 		}
// 		Timer_delay(500);
// 		LED_toggle(LED_Car_Port, LED_Car_R_Pin);
// 		
// 	}
// }

