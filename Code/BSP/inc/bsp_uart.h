
#pragma once

#include "stm32h7xx_hal.h"

#define __BSP_USART_DBG_INSTANCE			(USART1)
#define __BSP_USART_DBG_BAUDRATE			(115200U)
#define __BSP_USART_DBG_PARITY				(USART_PARITY_NONE)
#define __BSP_USART_DBG_STOPBITS			(USART_STOPBITS_1)
#define __BSP_USART_DBG_WORDLENGTH			(8U)
#define __BSP_USART_DBG_CLK_ENABLE			do { __HAL_RCC_USART1_CLK_ENABLE(); } while(0)


void bsp_uart_init(void);
