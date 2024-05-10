
#include "bsp.h"

int main(void)
{	
	bsp_init();
	
	while(1) {
		bsp_run();
		
	}
}
