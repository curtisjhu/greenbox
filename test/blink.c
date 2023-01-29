#include <Arduino.h>
#include <unity.h>

int i = 0;
int max_blinks = 4;

void test_led_state_high(void)
{
	digitalWrite(GREEN_LED, HIGH);
	digitalWrite(RED_LED, HIGH);
	TEST_ASSERT_EQUAL(HIGH, digitalRead(GREEN_LED));
	TEST_ASSERT_EQUAL(HIGH, digitalRead(RED_LED));
}

void test_led_state_low(void)
{
	digitalWrite(GREEN_LED, LOW);
	digitalWrite(RED_LED, LOW);
	TEST_ASSERT_EQUAL(LOW, digitalRead(GREEN_LED));
	TEST_ASSERT_EQUAL(LOW, digitalRead(RED_LED));
}

void setup() {
	pinMode(GREEN_LED, OUTPUT);
	pinMode(RED_LED, OUTPUT);
	UNITY_BEGIN();
}

void loop() {
	test_led_state_high();
	delay(1000);
	test_led_state_low();
	delay(1000);
	i++;

	if (i > max_blinks) {
		UNITY_END();
	}
}