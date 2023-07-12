/*
 * switch.c
 *
 * Created: 04/10/2022 11:56:18 م
 *  Author: M7med
 */ 
//#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_macros.h"

void timer_CTC_init_intr(void)
{
	//select CTC mode
	SET_BIT(TCCR0, WGM01);
	//load a value in OCR0
	OCR0=80;
	//select timer clock (prescaler 1024) 
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS02);
	//enable interrupt
	sei();
	SET_BIT(TIMSK, OCIE0);
}
/*
void timer_wave_nonPMW(void)
{
	
}
*/