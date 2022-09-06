/*
 * main.c
 *
 *  Created on: 8 Oct 2021
 *  Author: Elsayed Ayman Habib
 */

#include "gpio.h"
#include "uart.h"
#include "avr/io.h"
#include "avr/delay.h"
#include "Common_Macros.h"
int main(void)
{
	uint8 data_1 = 0 ;
	uint8 data_2 = 0;
	uint8 data_3 = 0;
	UART_init(9600);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_INPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN2_ID, PIN_INPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_INPUT);
	GPIO_setupPinDirection(PORTC_ID, PIN1_ID, PIN_OUTPUT);
	while(1)
	{
		if (BIT_IS_SET(PINB, PIN1_ID)) {
			_delay_us(30);
			if (BIT_IS_SET(PINB,PIN1_ID))
			{
				GPIO_writePin(PORTC_ID, PIN1_ID, LOGIC_HIGH);
				data_1 = 1;
				UART_sendByte(data_1);
			}
		}
		else if (BIT_IS_SET(PINB, PIN2_ID)) {
			_delay_us(30);
			if (BIT_IS_SET(PINB,PIN2_ID))
			{
				GPIO_writePin(PORTC_ID, PIN1_ID, LOGIC_HIGH);
				data_2 = 2 ;
				UART_sendByte(data_2);
			}
		}
		else if (BIT_IS_SET(PINB, PIN3_ID)) {
			_delay_us(30);
			if (BIT_IS_SET(PINB,PIN3_ID))
			{
				GPIO_writePin(PORTC_ID, PIN1_ID, LOGIC_HIGH);
				data_3 = 0;
				UART_sendByte(data_3);
			}
		}
	}
}
