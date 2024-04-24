
/**
 * @file bsp_led.h
 * @brief Basic Operation of Leds on Board
 * @author Disen-Shaw <DisenShaw@gmail.com>
 * @date 2024-04-23
 * @version lts 1.0
 *
 * @note Pin Maps:
 *     - RED 	PB0
 *     - GREEN 	PB1
 *     - BLUE 	PA3
 */

#pragma once

#include "stm32h7xx_hal.h"

/**
 * @brief BSP LED Port and Pin Defination
 */
#define __BSP_LED_R_PORT					(GPIOB)			//!< Red Led Port
#define __BSP_LED_R_PIN						(GPIO_PIN_0)	//!< Red Led Pin
#define __BSP_LED_G_PORT					(GPIOB)			//!< Green Led Port
#define __BSP_LED_G_PIN						(GPIO_PIN_1)	//!< Green Led Pin
#define __BSP_LED_B_PORT					(GPIOA)			//!< Blue Led Port
#define __BSP_LED_B_PIN						(GPIO_PIN_3)	//!< Blue Led Pin

/**
 * @brief Led Clock
 */
#define __BSP_LED_R_CLK_ENABLE()			do { __HAL_RCC_GPIOB_CLK_ENABLE(); } while(0)
#define __BSP_LED_G_CLK_ENABLE()			do { __HAL_RCC_GPIOB_CLK_ENABLE(); } while(0)
#define __BSP_LED_B_CLK_ENABLE()			do { __HAL_RCC_GPIOA_CLK_ENABLE(); } while(0)

/**
 * @brief Digital Pin Operation
 *
 * @param[in] port GPIO Port
 * @param[in] pin_idx Pin index
 */
#define __DIGITAL_HIGH(port, pin_idx)		do { port->BSRR =  pin_idx;      } while(0)
#define __DIGITAL_LOW(port, pin_idx)		do { port->BSRR = (pin_idx<<16); } while(0)
#define __DIGITAL_TOGGLE(port, pin_idx)		do { port->ODR  ^= pin_idx;      } while(0)

/**
 * @brief LED Operation
 */
#define BSP_LED_R_ON						__DIGITAL_LOW(__BSP_LED_R_PORT, __BSP_LED_R_PIN)
#define BSP_LED_R_OFF						__DIGITAL_HIGH(__BSP_LED_R_PORT, __BSP_LED_R_PIN)
#define BSP_LED_R_TOGGLE					__DIGITAL_TOGGLE(__BSP_LED_R_PORT, __BSP_LED_R_PIN)
#define BSP_LED_G_ON						__DIGITAL_LOW(__BSP_LED_G_PORT, __BSP_LED_G_PIN)
#define BSP_LED_G_OFF						__DIGITAL_HIGH(__BSP_LED_G_PORT, __BSP_LED_G_PIN)
#define BSP_LED_G_TOGGLE					__DIGITAL_TOGGLE(__BSP_LED_G_PORT, __BSP_LED_G_PIN)
#define BSP_LED_B_ON						__DIGITAL_LOW(__BSP_LED_B_PORT, __BSP_LED_B_PIN)
#define BSP_LED_B_OFF						__DIGITAL_HIGH(__BSP_LED_B_PORT, __BSP_LED_B_PIN)
#define BSP_LED_B_TOGGLE					__DIGITAL_TOGGLE(__BSP_LED_B_PORT, __BSP_LED_B_PIN)

void bsp_led_init(void);
