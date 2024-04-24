
/**
 * @file bsp_led.c
 * @brief Initialization for Board Leds
 * @author Disen-Shaw <DisenShaw@gmail.com>
 * @date 2024-04-23
 * @version lts 1.0
 */

#include "bsp_led.h"

/**
 * @brief BSP Led Function Init
 *
 * @param none
 *
 * @retval none
 */
void bsp_led_init(void)
{
	GPIO_InitTypeDef led = {0};
	
	__BSP_LED_R_CLK_ENABLE();
	__BSP_LED_G_CLK_ENABLE();
	__BSP_LED_B_CLK_ENABLE();
	
	led.Pull = GPIO_PULLUP;
	led.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	led.Mode = GPIO_MODE_OUTPUT_PP;
	
	led.Pin = __BSP_LED_R_PIN;
	HAL_GPIO_Init(__BSP_LED_R_PORT, &led);
	
	led.Pin = __BSP_LED_G_PIN;
	HAL_GPIO_Init(__BSP_LED_G_PORT, &led);
	
	led.Pin = __BSP_LED_B_PIN;
	HAL_GPIO_Init(__BSP_LED_B_PORT, &led);
	
	// Lights Out
	BSP_LED_B_OFF;
	BSP_LED_G_OFF;
	BSP_LED_R_OFF;
}

