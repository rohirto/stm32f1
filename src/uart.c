/**
 * @file uart.c
 * @author rohirto
 * @brief UART Module
 * @version 0.1
 * @date 2024-04-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "main.h"
#include "uart.h"

UART_HandleTypeDef huart1;

uint8_t RX1_Char = 0x00;

void USART1_UART_Init(void)
{
    
    

    // GPIO_InitStruct.Pin = GPIO_PIN_9;
    // GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    // GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    // HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // GPIO_InitStruct.Pin = GPIO_PIN_10;
    // GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    // GPIO_InitStruct.Pull = GPIO_NOPULL;
    // HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler();
    }
    
    
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if (huart->Instance == USART1)
  {
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    __HAL_RCC_USART1_CLK_DISABLE();
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9 | GPIO_PIN_10);
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  }
}

//---------[ UART Data Reception Completion CallBackFunc. ]---------
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    HAL_UART_Receive_IT(&huart1, &RX1_Char, 1);
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    // Data transmission completed
    
  }
}

void _debugLog(const char *format, ...) 
{
    va_list args;
    va_start(args, format);

    // Determine the length of the formatted string
    int length = vsnprintf(NULL, 0, format, args);
    if (length < 0) {
        // Error handling
        return;
    }

    // Allocate memory for the formatted string
    char buffer[length + 1];  // +1 for null terminator

    // Format the string
    vsnprintf(buffer, length + 1, format, args);

    va_end(args);

    // Transmit the formatted string via UART
    HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}


