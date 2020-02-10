/*
 * print_function.c
 *
 *  Created on: Feb 9, 2020
 *      Author: s3rf
 */
#include "main.h"
#include "stdio.h"
#include "stm32f4xx_hal_uart.h"

#include  <errno.h>
#include  <sys/unistd.h> // STDOUT_FILENO, STDERR_FILENO
#ifndef STDOUT_USART
#define STDOUT_USART
#endif
#ifndef STDERR_USART
#define STDERR_USART 2
#endif
#ifndef STDIN_USART
#define STDIN_USART 1
#endif
#define CONSOLE_WRITE_TIMEOUT 500u

int _write(int file, char *data, int len)
{
   if ((file != STDOUT_FILENO) && (file != STDERR_FILENO))
   {
      errno = EBADF;
      return -1;
   }

   // arbitrary timeout CONSOLE_WRITE_TIMEOUT
   HAL_StatusTypeDef status =  HAL_UART_Transmit_IT(&huart2, (uint8_t*)data, len, CONSOLE_WRITE_TIMEOUT);

   // return # of bytes written - as best we can tell
   return (status == HAL_OK ? len : 0);
}
