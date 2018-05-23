
#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include <string.h>

struct dataStruct
{
	char data1[20];
	char data2[20];
	char data3[20];
	char data4[20]; // vanwege max tekst lengte
	char data5[20];
	char data6[20];
	char data7[20];
	char data8[20];
};
struct dataStruct dataArg;
char *p = (char*)&dataArg;

void string_Splitten (char* input)
{
	char *token;
	int i=0;
	token = strtok(input, ",");	// kijken naar een komma			//char *token; char input[100]; UART_gets(input,0);
	handleArgument(i++, token);

	while (token != NULL )
	{
		token = strtok(NULL, ",");// kijken naar een komma
		handleArgument(i++, token);
	  }
	handleFirstArgument();
}

void handleArgument(int nr, char *arg)
 {

	  	switch (nr)
	  	{
			case 0:
				//figuur = atoi(arg);								// stringcompair gebruiken om stringen te vergelijken
				UART_puts("\n Een=");								//	x = atoi(arg); string to int
				//UART_puts(arg);										// strcpy (dataArg.data1, arg);
				strcpy (dataArg.data1, arg);
				UART_puts(dataArg.data1);
				break;

			case 1:
				UART_puts("\n Twee=");
				//UART_puts(arg);
				strcpy (dataArg.data1, arg);
				UART_puts(dataArg.data1);
				break;

			case 2:
				UART_puts("\n Drie=");
				//UART_puts(arg);
				strcpy (dataArg.data1, arg);
				UART_puts(dataArg.data1);
				break;
			case 3:
				UART_puts("\n Vier=");
				//UART_puts(arg);
				strcpy (dataArg.data1, arg);
				UART_puts(dataArg.data1);
				break;
			case 4:
				UART_puts("\n Vijf=");
				//UART_puts(arg);
				strcpy (dataArg.data1, arg);
				UART_puts(dataArg.data1);
				break;
			case 5:
				UART_puts("\n Zes=");
				//UART_puts(arg);
				strcpy (dataArg.data1, arg);
				UART_puts(dataArg.data1);
				break;
			case 6:
				UART_puts("\n Zeven=");
				//UART_puts(arg);
				strcpy (dataArg.data1, arg);
				UART_puts(dataArg.data1);
				break;
			case 7:
				UART_puts("\n Acht=");
				//UART_puts(arg);
				strcpy (dataArg.data1, arg);
				UART_puts(dataArg.data1);
				break;
			default:
				UART_puts("\n Te veel argumenten:");
				UART_puts(arg);
				break;
		}
 }

void handleFirstArgument(){
	if(strcmp(dataArg.data1, "lijn")== 0) { UART_puts("\n Hij heeft lijn");
		 //tekenLijn(een,twee,drie,vier,vijf,zes);
	}
	else if(strcmp(dataArg.data1, "ellips")== 0){UART_puts("\n Hij heeft ellips");
	}
	if(strcmp(dataArg.data1, "rechthoek")== 0) { UART_puts("\n Hij heeft rechthoek");
	}
	else if(strcmp(dataArg.data1, "driehoek")== 0){ UART_puts("\n Hij heeft driehoek");
	}
	if(strcmp(dataArg.data1, "tekst")== 0) { UART_puts("\n Hij heeft tekst");
	}
	else if(strcmp(dataArg.data1, "bitmap")== 0){ UART_puts("\n Hij heeft bitmap");
	}
	if(strcmp(dataArg.data1, "wacht")== 0) { UART_puts("\n Hij heeft wacht");
	}
}

