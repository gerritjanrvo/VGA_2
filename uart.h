#ifndef __UART_H
#define __UART_H

#include "main.h"



//----------------------------------------------------------
// Global Function Call
//----------------------------------------------------------
void UART_init(void);
signed int UART_printf(size_t length, const char *pFormat, ...);
void UART_INT_init(void);
void UART_putchar(char c);
void UART_puts(char *s);
void UART_putnum(unsigned int num, unsigned char deel);
void UART_putint(unsigned int num);
char UART_get(void);
void UART_gets(char *s, int echo);



#endif  // __UART_H
