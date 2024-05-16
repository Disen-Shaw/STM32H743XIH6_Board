

#include "bsp_led.h"

#include "FreeRTOS.h"
#include "task.h"

#include "freertos_task.h"

TaskHandle_t task_led_blink_handle;

static void task_led_blink_run(void *arg);

void freertos_init(void)
{
	xTaskCreate(task_led_blink_run, "Led_Blink", 128, NULL, 3, &task_led_blink_handle);
	
	// 开始进程调度
	vTaskStartScheduler();
}




static void task_led_blink_run(void *arg)
{
	for(;;) {
		vTaskDelay(1000);
		BSP_LED_B_TOGGLE;
	}
}





