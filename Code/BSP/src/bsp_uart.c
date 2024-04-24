
#include "bsp_led.h"
#include "bsp_uart.h"

USART_HandleTypeDef uart_dbg_handle;

void bsp_uart_init(void)
{
	__BSP_USART_DBG_CLK_ENABLE;
	
	uart_dbg_handle.Instance = __BSP_USART_DBG_INSTANCE;
	uart_dbg_handle.Init.BaudRate = __BSP_USART_DBG_BAUDRATE;
	uart_dbg_handle.Init.WordLength = __BSP_USART_DBG_WORDLENGTH;
	uart_dbg_handle.Init.Parity = __BSP_USART_DBG_PARITY;
	uart_dbg_handle.Init.StopBits = __BSP_USART_DBG_STOPBITS;
	
	if(HAL_USART_Init(&uart_dbg_handle) != HAL_OK) {
		BSP_LED_B_ON;
		while(1);
	}
	
}

