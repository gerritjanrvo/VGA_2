//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: J.F. van der Bent
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

/*
 * @mainpage
 * 	\n VGA programma
 * 	\n Joost Kouijzer & Gerrit Jan Rijken van Olst
 *
 */

#include "main.h"

int main(void)
{
	init();
	UB_VGA_FillScreen(VGA_COL_BLACK);
	UART_puts("Type iets in de uart\n");

  while(1)
  {
	  uartLezen(arg1);
  }
}
