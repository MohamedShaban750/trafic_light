/*
 * led.h
 *
 * Created: 04/10/2022 08:21:43 م
 *  Author: M7med
 */ 


#ifndef LED_H_
#define LED_H_

void led_init(unsigned char portname, unsigned char portnumber);
void led_on(unsigned char portname, unsigned char portnumber);
void led_off(unsigned char portname, unsigned char portnumber);
void led_toggle(unsigned char portname, unsigned char portnumber);
unsigned char led_read_status(unsigned char portname, unsigned char portnumber);

#endif /* LED_H_ */