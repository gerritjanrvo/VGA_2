
#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include <string.h>

struct dataStruct
{
	char data1[20];
	char data2[20];
	char data3[20];
	char data4[40]; // vanwege max tekst lengte
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

int handleKleur(char *datakleur){
	if(strcmp(datakleur, "zwart")== 0) { UART_puts("\n Zwart ");
		return(0);
	}
	else if(strcmp(datakleur, "blauw")== 0){UART_puts("\n blauw ");
		return(3);
	}
	if(strcmp(datakleur, "lichtblauw")== 0) { UART_puts("\n lichtblauw ");
		return(111);
	}
	else if(strcmp(datakleur, "groen")== 0){ UART_puts("\n groen ");
		return(28);
	}
	if(strcmp(datakleur, "lichtgroen")== 0) { UART_puts("\n lichtgroen");
		return(125);
	}
	else if(strcmp(datakleur, "cyaan")== 0){ UART_puts("\n cyaan ");
		return(31);
	}
	if(strcmp(datakleur, "lichtcyaan")== 0) { UART_puts("\n lichtcyaan ");
		return(127);
	}
	else if(strcmp(datakleur, "rood")== 0) { UART_puts("\n rood ");
		return(224);
	}
	if(strcmp(datakleur, "lichtrood")== 0) { UART_puts("\n lichtrood ");
		return(237);
	}
	else if(strcmp(datakleur, "magenta")== 0) { UART_puts("\n magenta ");
		return(227);
	}
	if(strcmp(datakleur, "lichtmagenta")== 0) { UART_puts("\n lichtmagenta ");
		return(239);
	}
	else if(strcmp(datakleur, "geel")== 0) { UART_puts("\n geel ");
		return(252);
	}
	if(strcmp(datakleur, "bruin")== 0) { UART_puts("\n bruin ");
		return(68);
	}
	else if(strcmp(datakleur, "grijs")== 0) { UART_puts("\n grijs ");
		return(110);
	}
	if(strcmp(datakleur, "wit")== 0) { UART_puts("\n wit ");
		return(255);
		}
}

void handleFirstArgument(){
	if(strcmp(dataArg.data1, "lijn")== 0) { UART_puts("\n Hij heeft lijn");
		int kleurcode = handleKleur(&dataArg.data7);
		maak_lijn (&dataArg.data2, &dataArg.data3, &dataArg.data4, &dataArg.data5, &dataArg.data6, kleurcode);
	}
	else if(strcmp(dataArg.data1, "ellips")== 0){UART_puts("\n Hij heeft ellips");
		int kleurcode = handleKleur(&dataArg.data6);
		maak_ellips(&dataArg.data2, &dataArg.data3, &dataArg.data4, &dataArg.data5, kleurcode);
	}
	if(strcmp(dataArg.data1, "rechthoek")== 0) { UART_puts("\n Hij heeft rechthoek");
		int kleurcode = handleKleur(&dataArg.data6);
		maak_rechthoek(&dataArg.data2, &dataArg.data3, &dataArg.data4, &dataArg.data5, kleurcode);
	}
	else if(strcmp(dataArg.data1, "driehoek")== 0){ UART_puts("\n Hij heeft driehoek");
		int kleurcode = handleKleur(&dataArg.data8);
		maak_driehoek(&dataArg.data2, &dataArg.data3, &dataArg.data4, &dataArg.data5, &dataArg.data6, &dataArg.data7, kleurcode);
	}
	if(strcmp(dataArg.data1, "tekst")== 0) { UART_puts("\n Hij heeft tekst");
		int kleurcode = handleKleur(&dataArg.data6);
		maak_tekst(&dataArg.data2, &dataArg.data3, &dataArg.data4, &dataArg.data5, kleurcode, &dataArg.data7);
	}
	else if(strcmp(dataArg.data1, "bitmap")== 0){ UART_puts("\n Hij heeft bitmap");
		maak_bitmap(&dataArg.data2, &dataArg.data3, &dataArg.data4);
	}
	if(strcmp(dataArg.data1, "clearscherm")== 0) { UART_puts("\n Hij heeft clearscherm");
		int kleurcode = handleKleur(&dataArg.data2);
		maak_clearscherm(kleurcode);
	}
	else if(strcmp(dataArg.data1, "wacht")== 0) { UART_puts("\n Hij heeft wacht");
		wacht(&dataArg.data2);
	}
}

