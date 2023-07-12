/*
 * led.c
 *
 * Created: 04/10/2022 08:20:35 م
 *  Author: M7med
 */ 
#include "DIO.h"

void led_init(unsigned char portname, unsigned char portnumber)
{
	DIO_VsetPINDir(portname, portnumber, 1);
}

void led_on(unsigned char portname, unsigned char portnumber)
{
	DIO_vwrite(portname, portnumber, 1);
}

void led_off(unsigned char portname, unsigned char portnumber)
{
	DIO_vwrite(portname, portnumber, 0);
}

void led_toggle(unsigned char portname, unsigned char portnumber)
{
	DIO_vtoggle(portname, portnumber);
}

unsigned char led_read_status(unsigned char portname, unsigned char portnumber)
{
	return DIO_u8read(portname, portnumber);
}


