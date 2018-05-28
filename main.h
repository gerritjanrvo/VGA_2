#ifndef __MAIN_H
#define __MAIN_H

//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------

//Externe includes
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <string.h>

//cmsis_boot
#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

//CMSIS_LIB-include
#include "misc.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_usart.h"

//ub_lib
#include "stm32_ub_vga_screen.h"

//Eigen programma's
#include "draw_functions.h"
#include "front_Layer.h"
#include "IO_Layer.h"
#include "logic_Layer.h"
#include "uart.h"

//defines
#define TRUE 1
#define FALSE 0

extern int bitmap_A[10][10];


char arg1[100];

#endif // __MAIN_H
