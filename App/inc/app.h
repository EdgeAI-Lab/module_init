#ifndef __APP_H__
#define __APP_H__
#include "stm32f10x.h"

typedef void (*init_function_list)(uint8_t taskID);
#define _init __attribute__((used, section("RAMCODE")))
#define MODULE_INIT(func) init_function_list _fn_##func _init = func


#endif

