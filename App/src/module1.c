#include "app.h"
#include "stdio.h"

static void module1_init(uint8_t taskID)
{
	// write your code ...
	printf("Module1 init done!\n");
}

MODULE_INIT(module1_init);
