/*
 * command_line_functions.h
 *
 *  Created on: Feb 10, 2020
 *      Author: s3rf
 */

#pragma once
#include "cmsis_os.h"
#include "FreeRTOS_CLI.h"

BaseType_t clearCommand( char *pcWriteBuffer,size_t xWriteBufferLen, const char *pcCommandString );
