#include "app.h"

extern unsigned int Image$$RW_IRAM2$$Base;
extern unsigned int Image$$RW_IRAM2$$Limit;

void do_init(void)
{
	uint8_t taskID = 0;
	init_function_list *call = (init_function_list *)&Image$$RW_IRAM2$$Base;
	init_function_list *end = (init_function_list *)&Image$$RW_IRAM2$$Limit;
  do
	{
		(*call)(taskID++);
		call++;
	}while(call < end);
}



int main()
{
	do_init();

	// write your code ...

	while(1)
	{
		// write your code ...
	}
}
