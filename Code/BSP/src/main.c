
#include "bsp.h"
#include "freertos_task.h"

int main(void)
{	
	bsp_init();
	freertos_init();
}

