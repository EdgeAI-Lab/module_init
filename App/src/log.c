#include "app.h"
#include "stdio.h"

static void logo_init(uint8_t taskID)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef Usart_InitStr;
	
	// configure clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 , ENABLE);
	USART_DeInit(USART1);
	
	/* Configure USART1 Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Configure USART1 Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// uart configure
	Usart_InitStr.USART_BaudRate			     	= 115200;
	Usart_InitStr.USART_WordLength					= USART_WordLength_8b;
	Usart_InitStr.USART_StopBits					  = USART_StopBits_1;
	Usart_InitStr.USART_Parity						  = USART_Parity_No;
	Usart_InitStr.USART_HardwareFlowControl	= USART_HardwareFlowControl_None;
	Usart_InitStr.USART_Mode						    = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART1, &Usart_InitStr);
	
	USART_Cmd(USART1, ENABLE);
	
	printf("Log module init done!\n");
}

MODULE_INIT(logo_init);

/*
 * rediretc printf use microlib
 */
int fputc(int ch, FILE *f)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
	USART_SendData(USART1, (unsigned char)ch);
	return ch;
}


