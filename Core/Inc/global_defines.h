#pragma once

/* Include correct version of Hardware Abstraction Layer */
#include "stm32f4xx_hal.h"

/* Include IO pin definitions from STM CubeIDE*/
#include "main.h"

/**************************************************************************/
// Define constants used to identify the peripherals.
// Cube define these in main.c. Not the smartest thing to do, but we must handle it.
/**************************************************************************/

extern TIM_HandleTypeDef 		htim4;
extern UART_HandleTypeDef huart2;

#define UART_CONSOLE				(USART2)			///< Console port using LL, not HAL

#define TIM_USEC_TICK			(& htim4)		///< 32-bit timer counting useconds since start of everything

/* Define functions exported from main.c */
extern void MX_USART2_UART_Init(void);			///< Initialise Console link

