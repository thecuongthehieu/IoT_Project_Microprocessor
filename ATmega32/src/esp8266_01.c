#include "include/esp8266_01.h"

void delay(int time) {
	while(time--) {
		_delay_ms(DELAY_SEED);
	}
}

void deliverMessage(const char *msg, int dt) {
	printf("%s\n", msg);
	delay(dt);
}

void init_esp8266() {
	/* MODE SELECTION */
	deliverMessage("AT+CWMODE=1", DELAY_2X);
	deliverMessage("AT+CIPMUX=0", DELAY_2X);

	/* WIFI CONNECTION */
	char wifi_connection_cmd[MAX_MESS_LEN];
	sprintf(wifi_connection_cmd,"%s%s%s%s", "AT+CWJAP=", WIFI_NAME, ",", WIFI_PASSWORD);
	deliverMessage(wifi_connection_cmd, DELAY_4X);
} 

void update_temperature_GET_API(int temperature) {
	/* HOST CONNECTION COMMAND */
	char host_connection_cmd[MAX_MESS_LEN];
	sprintf(host_connection_cmd, "%s%s%s%s%d", "AT+CIPSTART=\"TCP\"", ",", HOST, ",", PORT);
	deliverMessage(host_connection_cmd, DELAY_2X);

	/* GET API SENDING */
	char mess1[MAX_MESS_LEN];
	sprintf(mess1, "%s%d%s", "GET /update/", temperature, " HTTP/1.1");
	char mess2[MAX_MESS_LEN];
	sprintf(mess2, "%s%s", "Host: ", HOST_STRING);
	char mess3[] = "Connection: keep-alive";


	int mess_len = strlen(mess1) + strlen(mess2) + strlen(mess3) + 8;
	char send_cmd[MAX_MESS_LEN];
	sprintf(send_cmd, "%s%d", "AT+CIPSEND=", mess_len);
	
	deliverMessage(send_cmd, DELAY_2X);
	deliverMessage(mess1, 0);
	deliverMessage(mess2, 0);
	deliverMessage(mess3, 0);
	printf("\n");
}