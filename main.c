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

#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include <string.h>


//char een, twee, drie, vier, vijf, zes, zeven, acht;


// void firstArgument (char arg, )
// {

/*	 UART_puts(arg);
	 if(strcmp(een, "lijn")== 0) {
		// UART_puts("\n Hij heeft lijn");
		// tekenlijn(een,twee,drie,vier,vijf,zes);
	 }
	 else if(strcmp(een, "ellips")== 0){
		// UART_puts("\n Hij heeft ellips");
	 }
	 if(strcmp(een, "rechthoek")) {
	 }
	 else if(strcmp(een, "driehoek")){
	 }
	 if(strcmp(een, "tekst")) {
	 }
	 else if(strcmp(een, "bitmap")){
	 }
	 if(strcmp(een, "wacht")) {
	 }*/
// }

 /*void handleArgument(int nr, char *arg)
 {
	  	switch (nr)
	  	{
			case 0:
				//figuur = atoi(arg);								// stringcompair gebruiken om stringen te vergelijken
				een = arg;
				//UART_puts("\n Een=");								//	x = atoi(arg); string to int
				//UART_puts(arg);
			//	UART_puts(arg);
					 if(strcmp(arg, "lijn")== 0) {
						 UART_puts("\n Hij heeft lijn");
						 //tekenLijn(een,twee,drie,vier,vijf,zes);
					 }
					 else if(strcmp(arg, "ellips")== 0){
						 UART_puts("\n Hij heeft ellips");
					 }
					 if(strcmp(een, "rechthoek")) {
					 }
					 else if(strcmp(een, "driehoek")){
					 }
					 if(strcmp(een, "tekst")) {
					 }
					 else if(strcmp(een, "bitmap")){
					 }
					 if(strcmp(een, "wacht")) {
					 }
				break;

			case 1:
				twee = arg;
				//UART_puts("\n Twee=");
				//UART_puts(arg);
				break;

			case 2:
				drie = arg;
				UART_puts("\n Drie=");
				UART_puts(drie);
				break;
			case 3:
				vier = arg;
				UART_puts("\n Vier=");
				UART_puts(vier);
				break;
			case 4:
				vijf = arg;
				UART_puts("\n Vijf=");
				UART_puts(vijf);
				break;
			case 5:
				zes = arg;
				UART_puts("\n Zes=");
				UART_puts(zes);
				break;
			case 6:
				zeven = arg;
				UART_puts("\n Zeven=");
				UART_puts(zeven);
				break;
			case 7:
				acht = arg;
				UART_puts("\n Acht=");
				UART_puts(acht);
				break;
			default:
				UART_puts("\n Te veel argumenten:");
				UART_puts(arg);
				break;
		}
 }*/

int main(void)
{
	//  uint32_t n;
	SystemInit(); // System speed to 168MHz
	UART_init();

	UB_VGA_Screen_Init(); // Init VGA-Screen

	UB_VGA_FillScreen(VGA_COL_BLACK);
//	UB_VGA_SetPixel(10,10,10);

	UART_puts("Type iets in de uart\n");

  while(1)
  {
	  uartLezen(arg1);
  }
}

/*char *token;
char input[100];
UART_gets(input,0);

int x, y, kleur, i=0;

token = strtok(input, ",");	// kijken naar een komma
handleArgument(i++, token);

while (token != NULL )
{
	  	  token = strtok(NULL, ",");// kijken naar een komma
		  handleArgument(i++, token);
}*/

/*	 int result;
	 char example1[50];
	 strcpy(example1, "lijn");

	 result = strcmp(example1, arg);

	 if (result == 0) UART_puts("\n Het is lijn:");
	 if (result < 0) UART_puts("\n Het is geen lijn:");
	 UART_putint(result);
	 return 0;
*/
