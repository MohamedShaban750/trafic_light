/*
 * GccApplication1.c
 *
 * Created: 27/09/2022 12:31:09 
 * Author : M7med
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include "led.h"
#include "CTC_intr.h"
volatile unsigned char counter=0;
unsigned char counter_green=20;
unsigned char counter_yellow=5;
unsigned char counter_red=15;

int main(void)
{
	led_init('B',0);
	led_init('B',1);
	led_init('B',2);
	lcd_init();
	timer_CTC_init_intr();
	 
	while(1)
	{
		counter_green=20;
		counter_yellow=5;
		counter_red=15;
		
		lcd_send_cmd(CLR_SCREEN);
		lcd_send_string("remaining 20 sec");
		led_on('B',0);
		while (counter_green>0)
		{
			if(counter>=100)
			{
				counter=0;
				counter_green--;
				lcd_move_cursor(1,11);
				if (counter_green<10)
				{
					lcd_send_char(0x20);
					lcd_send_char(counter_green+48);
				}
				else if (counter_green<100)
				{
					lcd_send_char(counter_green/10+48);
					lcd_send_char(counter_green%10+48);
				}
			}
		}
		//while(counter<=100);
		//counter=0;
		_delay_ms(1000);
		counter=0;
		led_off('B',0);
		
		led_on('B',1);
		lcd_send_cmd(CLR_SCREEN);
		lcd_send_string("remaining  5 sec");
		while (counter_yellow>0)
		{
			if(counter>=100)
			{
				counter=0;
				counter_yellow--;
				lcd_move_cursor(1,11);
				if (counter_yellow<10)
				{
					lcd_send_char(0x20);
					lcd_send_char(counter_yellow+48);
				}
				else if (counter_yellow<100)
				{
					lcd_send_char(counter_yellow/10+48);
					lcd_send_char(counter_yellow%10+48);
				}
			}
		}
		while(counter<=100);
		counter=0;
		led_off('B',1);
		
		lcd_send_cmd(CLR_SCREEN);
		lcd_send_string("remaining 15 sec");
		led_on('B',2);
		while (counter_red>0)
		{
			if(counter>=100)
			{
				counter=0;
				counter_red--;
				lcd_move_cursor(1,11);
				if (counter_red<10)
				{
					lcd_send_char(0x20);
					lcd_send_char(counter_red+48);
				}
				else if (counter_red<100)
				{
					lcd_send_char(counter_red/10+48);
					lcd_send_char(counter_red%10+48);
				}
			}
		}
		while(counter<=100);
		counter=0;
		led_off('B',2);
		
	}
	
}

ISR(TIMER0_COMP_vect)
{
	counter++;
}