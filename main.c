/**
 * @mainpage
 * 	\n File		: VGA Opdracht
 * 	\n Versie	: 1
 * 	\n Blok		: D
 * 	\n Leerjaar	: 3
 * 	\n Datum	: 28 Mei 2018
 * 	\n Autor	: Joost Kouijzer & Gerrit Jan Rijken van Olst
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
