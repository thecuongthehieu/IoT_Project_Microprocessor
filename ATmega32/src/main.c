/* Built Library */
#include "include/uart.h"
#include "include/adc.h"
#include "include/esp8266_01.h"

/* DECLARE FUNCTION */
void setup();
void loop();

/* MAIN */
int main() {
	setup();
	loop();
}

void setup() {
	init_uart();
	init_adc();
	init_printf();
	init_esp8266();
}

void loop() {
    while(1)
    {
    	int temperature = get_temperature();
    	update_temperature_GET_API(temperature);

    	/* Updating Period */
    	delay(10);
    }
}
