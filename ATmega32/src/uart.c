#include "include/uart.h"

/* UART Printf Stream */
static FILE uartstd = FDEV_SETUP_STREAM(uart_char_tx, NULL, _FDEV_SETUP_WRITE);

void uart_char_tx(unsigned char chr) {
	if (chr == '\n') uart_char_tx('\r'); 
	while (bit_is_clear(UCSRA, UDRE)) {};
		UDR = chr;

	// _delay_ms(DELAY_TIME_UART_WRITE);
}

void init_uart() {
	/* Set up Baud Rate */
	UBRRH = 0;
	UBRRL = 8;

	/* Set Up Both Transmiter And Receiver */
	UCSRA = 0x00;
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
	
	/* Global Interuption For Receiver */
	sei(); 
}

void init_printf() {
	stdout = &uartstd;
}

void hello_world() {
	// fprintf(&uartstd, "In bang ham fprintf\n");
	printf("Hello World\n"); 
}