#include <stdio.h>
#include<stdint.h>
#include<stm32f411xe.h>
#include <uart.h>
#include <adc.h>
#include <systick.h>
#define GPIOAEN			(1U<<0)
#define PIN5			(1U<<5)
#define LED				PIN5

int main(void)
{
	RCC->AHB1ENR|=(1U<<0);
	GPIOA->MODER|=(1U<<10);
	GPIOA->MODER&=~(1U<<11);
	uart2_txrx_init();
	systick_1hz_interrrupt();
	while(1)
	{

	}
}
static void systick_callback(void)
{
	printf("A second passed!\n\r");
	GPIOA->ODR^=LED;
}
/*SysTick_Handler find in startup_stm32f411*/
void SysTick_Handler(void)
{
	/*Do something*/
	systick_callback();
}


