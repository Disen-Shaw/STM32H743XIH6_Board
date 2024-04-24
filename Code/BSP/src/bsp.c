
#include "bsp.h"
#include "bsp_rcc.h"
#include "bsp_led.h"
#include "bsp_uart.h"

void bsp_init(void)
{
	HAL_Init();
	bsp_rcc_init();
	bsp_led_init();
	bsp_uart_init();
}


void bsp_run(void)
{
}
