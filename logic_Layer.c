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
				UART_puts("\n Een=");
				strcpy (dataArg.data1, arg);
				UART_puts(dataArg.data1);
				break;

			case 1:
				UART_puts("\n Twee=");
				strcpy (dataArg.data2, arg);
				UART_puts(dataArg.data2);
				break;

			case 2:
				UART_puts("\n Drie=");
				strcpy (dataArg.data3, arg);
				UART_puts(dataArg.data3);
				break;
			case 3:
				UART_puts("\n Vier=");
				strcpy (dataArg.data4, arg);
				UART_puts(dataArg.data4);
				break;
			case 4:
				UART_puts("\n Vijf=");
				strcpy (dataArg.data5, arg);
				UART_puts(dataArg.data5);
				break;
			case 5:
				UART_puts("\n Zes=");
				strcpy (dataArg.data6, arg);
				UART_puts(dataArg.data6);
				break;
			case 6:
				UART_puts("\n Zeven=");
				strcpy (dataArg.data7, arg);
				UART_puts(dataArg.data7);
				break;
			case 7:
				UART_puts("\n Acht=");
				strcpy (dataArg.data8, arg);
				UART_puts(dataArg.data8);
				break;
			default:
				UART_puts("\n Error: Te veel argumenten");
				break;
		}
 }

/*
 * @brief Kijk welke kleur het is en return de waarde van de kleur
 */
int handleKleur(char *datakleur){
	if(strcmp(datakleur, "zwart")== 0) {
		return(0);
	}
	else if(strcmp(datakleur, "blauw")== 0){
		return(3);
	}
	if(strcmp(datakleur, "lichtblauw")== 0){
		return(111);
	}
	else if(strcmp(datakleur, "groen")== 0){
		return(28);
	}
	if(strcmp(datakleur, "lichtgroen")== 0){
		return(125);
	}
	else if(strcmp(datakleur, "cyaan")== 0){
		return(31);
	}
	if(strcmp(datakleur, "lichtcyaan")== 0){
		return(127);
	}
	else if(strcmp(datakleur, "rood")== 0){
		return(224);
	}
	if(strcmp(datakleur, "lichtrood")== 0){
		return(237);
	}
	else if(strcmp(datakleur, "magenta")== 0){
		return(227);
	}
	if(strcmp(datakleur, "lichtmagenta")== 0){
		return(239);
	}
	else if(strcmp(datakleur, "geel")== 0){
		return(252);
	}
	if(strcmp(datakleur, "bruin")== 0){
		return(68);
	}
	else if(strcmp(datakleur, "grijs")== 0){
		return(110);
	}
	if(strcmp(datakleur, "wit")== 0){
		return(255);
		}
	else UART_puts("\n Error: kleur onbekend");
}

void handleFirstArgument(){
	if(strcmp(dataArg.data1, "lijn")== 0){
		int kleurcode = handleKleur(&dataArg.data7);
		maak_lijn (&dataArg.data2, &dataArg.data3, &dataArg.data4, &dataArg.data5, &dataArg.data6, kleurcode);
	}
	else if(strcmp(dataArg.data1, "ellips")== 0){
		int kleurcode = handleKleur(&dataArg.data6);
		maak_ellips(&dataArg.data2, &dataArg.data3, &dataArg.data4, &dataArg.data5, kleurcode);
	}
	if(strcmp(dataArg.data1, "rechthoek")== 0){
		int kleurcode = handleKleur(&dataArg.data6);
		maak_rechthoek(&dataArg.data2, &dataArg.data3, &dataArg.data4, &dataArg.data5, kleurcode);
	}
	else if(strcmp(dataArg.data1, "driehoek")== 0){
		int kleurcode = handleKleur(&dataArg.data8);
		maak_driehoek(&dataArg.data2, &dataArg.data3, &dataArg.data4, &dataArg.data5, &dataArg.data6, &dataArg.data7, kleurcode);
	}
	if(strcmp(dataArg.data1, "tekst")== 0){
		int kleurcode = handleKleur(&dataArg.data6);
		maak_tekst(&dataArg.data2, &dataArg.data3, &dataArg.data4, &dataArg.data5, kleurcode, &dataArg.data7);
	}
	else if(strcmp(dataArg.data1, "bitmap")== 0){
		maak_bitmap(&dataArg.data2, &dataArg.data3, &dataArg.data4);
	}
	if(strcmp(dataArg.data1, "clearscherm")== 0){
		int kleurcode = handleKleur(&dataArg.data2);
		maak_clearscherm(kleurcode);
	}
	else if(strcmp(dataArg.data1, "wacht")== 0){
		wacht(&dataArg.data2);
	}
	else UART_puts("\n Error: onbekent eerste argument");
}

