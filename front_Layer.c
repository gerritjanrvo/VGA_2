/*
 * front_Layer.c
 *
 * Gemaakt door: Joost Kouijzer & Gerrit Jan Rijken van Olst
 */

#include "front_Layer.h"

/**
 * 		@brief \n Input buffer.
 */
char input[100];

/**
 * 		@brief \n Lezen van de uart.
 */
void uartLezen()
{
	UART_gets(input,0);
	string_Splitten(input);
}
