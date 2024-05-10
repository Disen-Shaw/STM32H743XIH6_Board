
#pragma once

#include "stm32h7xx_hal.h"

#define __BSP_UART_DBG_INSTANCE			(USART1)
#define __BSP_UART_DBG_CLK_ENABLE		do { __HAL_RCC_USART1_CLK_ENABLE(); } while(0)
#define __BSP_UART_DBG_BAUDRATE			(115200U)

#define __BSP_UART_DBG_TX_CLK_ENABLE	do { __HAL_RCC_GPIOA_CLK_ENABLE();  } while(0)
#define __BSP_UART_DBG_TX_INSTANCE		(GPIOA)
#define __BSP_UART_DBG_TX_PIN			(GPIO_PIN_9)
#define __BSP_UART_DBG_RX_CLK_ENABLE	do { __HAL_RCC_GPIOA_CLK_ENABLE();  } while(0)
#define __BSP_UART_DBG_RX_INSTANCE		(GPIOA)
#define __BSP_UART_DBG_RX_PIN			(GPIO_PIN_10)

void bsp_uart_init(void);
