/**
 * @file uart.h
 * @author rohirto
 * @brief UART Header
 * @version 0.1
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __UART_H
#define __UART_H

#include "main.h"
#include <stdarg.h>

#define debugLog(fmt, ...) _debugLog(fmt, ##__VA_ARGS__)


extern UART_HandleTypeDef huart1;

void USART1_UART_Init(void);
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void _debugLog(const char *format, ...);



#endif