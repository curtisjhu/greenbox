/**
 * Curtis Hu
 * Read data pins
 * Address lines.
*/
#include <Arduino.h>

#define CLOCK P2_0
#define R_W P2_3

// Going from A0 -> 15
uint8_t ADDR[] = {P3_5, P3_6, P7_0, P6_4, P6_3, P6_2, P6_1, P4_1, P4_2, P2_7, P3_2, P6_6, P1_6, P3_3, P3_4, P6_5};
// Going from D0-7
uint8_t DATA[] = {P8_2, P3_7, P4_0, P4_3, P1_2, P1_3, P1_4, P1_5};

void cycle() {
	int address = 0;
	for (int i = 0; i < 16; i++) {
		int bit = digitalRead(ADDR[i]) ? 1 : 0;
		address = address<<1 + bit;
		Serial.print(bit);
	}

	Serial.print("    ");

	int databus = 0;
	for (int j = 0; j < 8; j++) {
		int bit = digitalRead(DATA[j]) ? 1 : 0;
		databus = (databus<<1) + 1;
		Serial.print(bit);
	}

	Serial.print("    ");

	char output[15];
	char read_write = digitalRead(R_W) ? 'r' : 'w';
	sprintf(output, "%04x   %c   %02x", address, read_write, databus);
	Serial.println(output);
}

void print() {
	Serial.println("PRINT");
}

void setup()
{
	Serial.begin(57600);
	Serial.print("HELOO WORLD");

	pinMode(CLOCK, INPUT);
	pinMode(R_W, INPUT);
	for (int i = 0; i < 16; i++)
		pinMode(ADDR[i], INPUT);
	for (int i = 0; i < 8; i++)
		pinMode(ADDR[i], INPUT);

	attachInterrupt(digitalPinToInterrupt(CLOCK), print, CHANGE);
}

void loop(){}