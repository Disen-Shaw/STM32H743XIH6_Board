
/**
 * @file bsp_i2c_eeprom.c
 * @brief BSP EEPROM Driver
 * @author Disen-Shaw <DisenShaw@gmail.com>
 * @date 2024-04-28
 * @version lts 1.0
 *
 * @note
 *    EEPROM SCL:        I2C1_SCL, PB6
 *    EEPROM SDA:        I2C1_SDA, PB7
 */

#include "bsp_i2c_eeprom.h"

I2C_HandleTypeDef g_bsp_eeprom_i2c_handle = {0};

/**
 * @brief 板卡 EEPROM I2C 初始化
 *
 * @param none
 *
 * @retval none
 */
void bsp_i2c_eeprom_init(void)
{
	/**
	 * @note GPIO Config
	 */
	__BSP_EEPROM_SCL_CLK_ENABLE;
	__BSP_EEPROM_SDA_CLK_ENABLE;
	
	GPIO_InitTypeDef i2c_pins = {0};
	i2c_pins.Mode = GPIO_MODE_AF_OD;
	i2c_pins.Pull = GPIO_PULLUP;
	i2c_pins.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	
	i2c_pins.Pin = __BSP_EEPROM_SCL_PIN;
	HAL_GPIO_Init(__BSP_EEPROM_SCL_INSTANCE, &i2c_pins);
	
	i2c_pins.Pin = __BSP_EEPROM_SDA_PIN;
	HAL_GPIO_Init(__BSP_EEPROM_SDA_INSTANCE, &i2c_pins);
	
	/**
	 * @note I2C Config
	 */
	__BSP_EEPROM_I2C_CLK_ENABLE;
	g_bsp_eeprom_i2c_handle.Instance = __BSP_EEPROM_I2C_INSTANCE;
	g_bsp_eeprom_i2c_handle.Mode = HAL_I2C_MODE_MASTER;
	g_bsp_eeprom_i2c_handle.Init.OwnAddress1 = __BSP_I2C_OWN_ADDRESS;
	g_bsp_eeprom_i2c_handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;		//!< 7Bit Address Mode
	
}


