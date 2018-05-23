
#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include <string.h>

//struct dataStruct dataArg;
//char *p = (char*)&dataArg;

void string_Splitten (char* input)
{
	char *token;
	int x, y, kleur, i=0;
	token = strtok(input, ",");	// kijken naar een komma			//char *token; char input[100]; UART_gets(input,0);
	handleArgument(i++, token);

	while (token != NULL )
	{
		token = strtok(NULL, ",");// kijken naar een komma
		handleArgument(i++, token);
	  }


}

void handleArgument(int nr, char *arg)
 {
	  	switch (nr)
	  	{
			case 0:
				//figuur = atoi(arg);								// stringcompair gebruiken om stringen te vergelijken
				UART_puts("\n Een=");								//	x = atoi(arg); string to int
				UART_puts(arg);

				break;

			case 1:
				UART_puts("\n Twee=");
				UART_puts(arg);
				break;

			case 2:
				UART_puts("\n Drie=");
				UART_puts(arg);
				break;
			case 3:
				UART_puts("\n Vier=");
				UART_puts(arg);
				break;
			case 4:
				UART_puts("\n Vijf=");
				UART_puts(arg);
				break;
			case 5:
				UART_puts("\n Zes=");
				UART_puts(arg);
				break;
			case 6:
				UART_puts("\n Zeven=");
				UART_puts(arg);
				break;
			case 7:
				UART_puts("\n Acht=");
				UART_puts(arg);
				break;
			default:
				UART_puts("\n Te veel argumenten:");
				UART_puts(arg);
				break;
		}
 }

/*void handleFirstArgument(){
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
}*/

