
#include <stdio.h>

#include "bsp_led.h"
#include "bsp_uart.h"

UART_HandleTypeDef g_bsp_uart_dbg_handle;

void bsp_uart_init(void)
{
	GPIO_InitTypeDef usart_pins = {0};
	
	__BSP_UART_DBG_CLK_ENABLE;
	__BSP_UART_DBG_TX_CLK_ENABLE;
	__BSP_UART_DBG_RX_CLK_ENABLE;
	
	usart_pins.Alternate = GPIO_AF7_USART1;
	usart_pins.Mode = GPIO_MODE_AF_PP;
	usart_pins.Pull = GPIO_PULLUP;
	usart_pins.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	
	usart_pins.Pin = __BSP_UART_DBG_TX_PIN;
	HAL_GPIO_Init(__BSP_UART_DBG_TX_INSTANCE, &usart_pins);
	
	usart_pins.Pin = __BSP_UART_DBG_RX_PIN;
	HAL_GPIO_Init(__BSP_UART_DBG_RX_INSTANCE, &usart_pins);
	
	RCC_PeriphCLKInitTypeDef uart_dbg_clk_init = {0};
	uart_dbg_clk_init.Usart16ClockSelection = RCC_USART16CLKSOURCE_D2PCLK2;
	uart_dbg_clk_init.PeriphClockSelection = RCC_PERIPHCLK_USART1;
	HAL_RCCEx_PeriphCLKConfig(&uart_dbg_clk_init);
	
	g_bsp_uart_dbg_handle.Instance = __BSP_UART_DBG_INSTANCE;
	g_bsp_uart_dbg_handle.Init.BaudRate = __BSP_UART_DBG_BAUDRATE;
	g_bsp_uart_dbg_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	g_bsp_uart_dbg_handle.Init.Mode = UART_MODE_TX_RX;
	g_bsp_uart_dbg_handle.Init.OneBitSampling = UART_ONEBIT_SAMPLING_DISABLED;
	g_bsp_uart_dbg_handle.Init.OverSampling = UART_OVERSAMPLING_16;
	g_bsp_uart_dbg_handle.Init.Parity = UART_PARITY_NONE;
	g_bsp_uart_dbg_handle.Init.StopBits = UART_STOPBITS_1;
	g_bsp_uart_dbg_handle.Init.WordLength = UART_WORDLENGTH_8B;
	g_bsp_uart_dbg_handle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if(HAL_UART_Init(&g_bsp_uart_dbg_handle) != HAL_OK) {
		BSP_LED_R_ON;
		while(1);
	}
}

/**
 *	@breif 	标准输出对接为调试串口
 */
int fputc(int ch, FILE *f)
{
	HAL_UART_Transmit(&g_bsp_uart_dbg_handle, (uint8_t *)&ch, 1, 0xFF);
	while(!__HAL_UART_GET_FLAG(&g_bsp_uart_dbg_handle, UART_FLAG_TC));
	return (ch);
}


