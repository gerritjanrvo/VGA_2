/*
 * IO_Layer.c
 *
 * Gemaakt door: Joost Kouijzer & Gerrit Jan Rijken van Olst
 */

#include "IO_Layer.h"

/**
 * 		@brief \n Initialiseren van het syteem, uart en vga scherm.
 */
void init(){
	SystemInit(); // System speed to 168MHz
	UART_init();  // Init UART
	UB_VGA_Screen_Init(); // Init VGA-Screen
}
