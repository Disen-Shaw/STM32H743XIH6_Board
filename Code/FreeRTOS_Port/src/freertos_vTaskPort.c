
#include "bsp_led.h"

#include "generic_log.h"

#include "FreeRTOS.h"
#include "task.h"

/**
 * @brief Task Stack OverFlow Hook
 *
 * @param[in] XTask Task Handle
 * @param[in] pcTaskName Task Name for Stack Overflow
 *
 * @retval none
 */
void vApplicationStackOverflowHook( TaskHandle_t xTask, char * pcTaskName )
{
	BSP_LED_R_ON;
	LOG("%s Task Memory OverFlow", pcTaskName);
}

