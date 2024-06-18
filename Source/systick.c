#include<systick.h>
#include <stm32f411xe.h>

#define SYSTICK_LOAD_VAL      16000/*tần số là 16MHz tức 16 triệu cky trên giây
ta ghi 16000 tức là 16000 cky trên ms*/
#define CRTL_ENABLE           (1U<<0)
#define CRTL_CLKSOURCE        (1U<<2)
#define CRTL_COUNTFLAG        (1U<<16)

#define ONE_SEC_LOAD		  16000000
#define CRTL_TICKINT		  (1U<<1)
/**/
void systickDelayMS(int delay)
{

	/*Reload with number of clocks per millisecond*/
	SysTick->LOAD=SYSTICK_LOAD_VAL;
	/*Clear systick current value register*/
	SysTick->VAL=0;
	/*Enable systick and select internal clock course*/
	SysTick->CTRL|=CRTL_ENABLE;
	SysTick->CTRL|=CRTL_CLKSOURCE;
	for(int i=0;i<delay;i++)
	{
		/*Wait until the COUNTFLAG is set*/
		while(!(SysTick->CTRL&CRTL_COUNTFLAG));
	}/*Detele all CTRL*/
	SysTick->CTRL=0;
}

void systick_1hz_interrrupt()
{
	/*Reload with number of clocks persecond*/
	SysTick->LOAD=ONE_SEC_LOAD-1;
	/*Clear systick current value register*/
	SysTick->VAL=0;
	/*Enable systick and select internal clock course*/
	SysTick->CTRL|=CRTL_ENABLE;
	SysTick->CTRL|=CRTL_CLKSOURCE;
	/*Enable Systick Interrupt*/
	SysTick->CTRL|=CRTL_TICKINT;
}
