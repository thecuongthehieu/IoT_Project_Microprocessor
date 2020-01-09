#ifndef ESP8266_01_H
#define ESP8266_01_H

/* AVR Library */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/* C Standard Library */
#include <stdio.h>
#include <string.h>

/* For ESP8266 */
#define CMD_SEND_BEGIN  "AT+CIPSEND=0"
#define CMD_SEND_END    "AT+CIPCLOSE=0"
 
#define DELAY_SEED	3000
#define DELAY_1X    1 	
#define DELAY_2X    2
#define DELAY_3X    3
#define DELAY_4X    4
#define DELAY_5X    5

#define MAX_MESS_LEN 100

/* WIFI CONNECTION INF*/
#define WIFI_NAME "\"boat&bookcoffee tang 2\""
#define WIFI_PASSWORD "\"thuyensach32\""

/* SERVER CONNECTION*/
#define HOST "\"e19b153d.ngrok.io\""
#define HOST_STRING "e19b153d.ngrok.io"
#define PORT 80

/* Helper Function */
void delay(int time);


/* Helper Function */
void deliverMessage(const char *msg, int dt);

/* AT Command Initiation */ 
void init_esp8266();

/* AT Command GET URL API */ 
void update_temperature_GET_API(int temperature);

#endif