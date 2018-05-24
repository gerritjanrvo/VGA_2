/*
 * IO_Layer.c
 *
 * Gemaakt door: Joost Kouijzer & Gerrit Jan Rijken van Olst
 */

void init(){
	SystemInit(); // System speed to 168MHz
	UART_init();

	UB_VGA_Screen_Init(); // Init VGA-Screen
}
