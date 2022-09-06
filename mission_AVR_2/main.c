/*
 * main.c
 *
 *  Created on: 8 Oct 2021
 *  Author: Elsayed Ayman Habib
 */

#include "gpio.h"
#include "avr/io.h"
#include "avr/delay.h"
#include "uart.h"
#include "common_macros.h"
int main(void)
{

	uint8 data ;
	GPIO_setupPinDirection(PORTC_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID, PIN1_ID, PIN_OUTPUT);
	UART_init(9600);

	while (1) {
		data = UART_recieveByte();

		if (data == 0) { //stop motor
			GPIO_writePort(PORTC_ID, data);

		} else if (data == 1) { //clock wise
			GPIO_writePort(PORTC_ID, data);

		} else if (data == 2) { //anti clockwise
			GPIO_writePort(PORTC_ID, data);
		}
	}
}
