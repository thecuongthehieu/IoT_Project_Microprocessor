#ifndef UART_H
#define UART_H

/* AVR Library */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/* C Standard Library */
#include <stdio.h>
#include <string.h>

/* Write Delay Time */
#define DELAY_TIME_UART_WRITE 10

/**
*	UART write 1 byte
*/
void uart_char_tx(unsigned char chr);

/*
*	UART Initiation
*	Baud Rate: 115 200 (CLK = 16 Mhz)
*
*/
void init_uart();

/* SET Output Stream */
void init_printf();

/* DEBUGGING Function */
void hello_world();

#endif