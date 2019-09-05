# 类linux驱动模块框架module_init(init_fun)在STM32上的实现

## 1.试验环境
* 工具链：Keil5
* 开发板：STM32F103ZE

## 2.工程配置说明
* 使用MicroLib
* 自定义链接脚本
* 自定义模块编译顺序

## 3.使用说明

程序运行后，会统一调用各个模块的初始化函数，各个模块的初始化函数会通过USART1(波特率:115200)打印出“xxx init done!”

如下图所示：

![module_init_result](https://github.com/FanHongchuang/module_init/raw/master/doc/result.png)

## 4.工程文件说明
* module1.c,module2.c,module3.c 为3个独立的模块，模拟试验用，其初始化函数都为内部函数(使用static修饰)，符合高内聚低耦合的软件设计思想
* log.c 为一个独立的模块，其功能是通过USART1打印log，其初始化函数都为内部函数(使用static修饰)，符合高内聚低耦合的软件设计
* main.c中，do_init函数直接通过初始化函数的内存地址，对初始化函数逐个进行调用