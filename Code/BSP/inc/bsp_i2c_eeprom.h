
/**
 * @file bsp_i2c_eeprom.h
 * @brief BSP EEPROM Driver Header
 * @author Disen-Shaw <DisenShaw@gmail.com>
 * @date 2024-04-28
 * @version lts 1.0
 *
 * @note
 *    EEPROM SCL:        I2C1_SCL, PB6
 *    EEPROM SDA:        I2C1_SDA, PB7
 */

#pragma once

#include "stm32h7xx_hal.h"

/**
 * @brief AT24C02 Address Defination
 */
#define __BSP_EEPROM_DEV_ADDRESS			(0b10100000)

/**
 * @brief BSP EEPROM I2C Instance
 */
#define __BSP_I2C_OWN_ADDRESS				(0x0A)		//!< I2C Address for STM32 Processer
#define __BSP_EEPROM_I2C_INSTANCE			(I2C1)
#define __BSP_EEPROM_I2C_CLK_ENABLE			do { __HAL_RCC_I2C1_CLK_ENABLE();  } while(0)
#define __BSP_EEPROM_SCL_CLK_ENABLE			do { __HAL_RCC_GPIOB_CLK_ENABLE(); } while(0)
#define __BSP_EEPROM_SCL_INSTANCE			(GPIOB)
#define __BSP_EEPROM_SCL_PIN				(GPIO_PIN_6)
#define __BSP_EEPROM_SDA_CLK_ENABLE			do { __HAL_RCC_GPIOB_CLK_ENABLE(); } while(0)
#define __BSP_EEPROM_SDA_INSTANCE			(GPIOB)
#define __BSP_EEPROM_SDA_PIN				(GPIO_PIN_7)


extern I2C_HandleTypeDef g_bsp_eeprom_i2c_handle;
