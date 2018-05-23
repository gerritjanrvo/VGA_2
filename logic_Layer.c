
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
				strcpy (dataArg.data2, arg);
				UART_puts(dataArg.data2);
				break;

			case 2:
				UART_puts("\n Drie=");
				//UART_puts(arg);
				strcpy (dataArg.data3, arg);
				UART_puts(dataArg.data3);
				break;
			case 3:
				UART_puts("\n Vier=");
				//UART_puts(arg);
				strcpy (dataArg.data4, arg);
				UART_puts(dataArg.data4);
				break;
			case 4:
				UART_puts("\n Vijf=");
				//UART_puts(arg);
				strcpy (dataArg.data5, arg);
				UART_puts(dataArg.data5);
				break;
			case 5:
				UART_puts("\n Zes=");
				//UART_puts(arg);
				strcpy (dataArg.data6, arg);
				UART_puts(dataArg.data6);
				break;
			case 6:
				UART_puts("\n Zeven=");
				//UART_puts(arg);
				strcpy (dataArg.data7, arg);
				UART_puts(dataArg.data7);
				break;
			case 7:
				UART_puts("\n Acht=");
				//UART_puts(arg);
				strcpy (dataArg.data8, arg);
				UART_puts(dataArg.data8);
				break;
			default:
				UART_puts("\n Te veel argumenten:");
				UART_puts(arg);
				break;
		}
 }

void handleFirstArgument(){
	UART_puts("\n in handleFirstArgument: ");
	UART_puts(dataArg.data1);
	if(strcmp(dataArg.data1, "lijn")== 0) { UART_puts("\n Hij heeft lijn");
		maak_lijn ();
	}
	else if(strcmp(dataArg.data1, "ellips")== 0){UART_puts("\n Hij heeft ellips");
		maak_ellips();
	}
	if(strcmp(dataArg.data1, "rechthoek")== 0) { UART_puts("\n Hij heeft rechthoek");
		maak_rechthoek();
	}
	else if(strcmp(dataArg.data1, "driehoek")== 0){ UART_puts("\n Hij heeft driehoek");
		maak_driehoek();
	}
	if(strcmp(dataArg.data1, "tekst")== 0) { UART_puts("\n Hij heeft tekst");
		maak_tekst();
	}
	else if(strcmp(dataArg.data1, "bitmap")== 0){ UART_puts("\n Hij heeft bitmap");
		maak_bitmap();
	}
	if(strcmp(dataArg.data1, "clearscherm")== 0) { UART_puts("\n Hij heeft clearscherm");
		maak_clearscherm();
	}
	else if(strcmp(dataArg.data1, "wacht")== 0) { UART_puts("\n Hij heeft wacht");
		wacht();
	}
}

