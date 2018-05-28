/*
 * front_Layer.c
 *
 * Gemaakt door: Joost Kouijzer & Gerrit-Jan Rijken van Olst
 */

#include "front_Layer.h"

void uartLezen(char* input)
{
	UART_gets(input,0);
	string_Splitten(input);
}
