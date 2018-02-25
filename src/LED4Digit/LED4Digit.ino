/*
4 Digit LED

This is an introduction on how to drive a 4 digit LED using only a Arduino.  

- 1x 4 digit LED (461BS)
- 12x male:male wires
- 8x 220 ohm resistors

@TODO There's an issue with this demo in that the digits can be written independently
 */

#include <Arduino.h>

// cathode interface
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int dp = 8;

// anode interface
int d4 = 9;
int d3 = 10;
int d2 = 11;
int d1 = 12;

#define OFF HIGH
#define ON LOW

#define ACTIVE HIGH
#define INACTIVE LOW

void setup() {
    pinMode(d1, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(d3, OUTPUT);
    pinMode(d4, OUTPUT);
	
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(dp, OUTPUT);
}

void loop() {
	digitalWrite(d1, ACTIVE);
	num_1();
	delay(1000);
	digitalWrite(d1, INACTIVE);

	digitalWrite(d2, ACTIVE);
	num_2();
	delay(1000);
	digitalWrite(d2, INACTIVE);

	digitalWrite(d3, ACTIVE);
	num_3();
	delay(1000);
	digitalWrite(d3, INACTIVE);

	digitalWrite(d4, ACTIVE);
	num_4();
	delay(1000);
	digitalWrite(d4, INACTIVE);
}

void num_0() {
    digitalWrite(a, ON);
    digitalWrite(b, ON);
    digitalWrite(c, ON);
    digitalWrite(d, ON);
    digitalWrite(e, ON);
    digitalWrite(f, ON);
    digitalWrite(g, OFF);
    digitalWrite(dp, OFF);
}

void num_1() {
    digitalWrite(a, OFF);
    digitalWrite(b, ON);
    digitalWrite(c, ON);
    digitalWrite(d, OFF);
    digitalWrite(e, OFF);
    digitalWrite(f, OFF);
    digitalWrite(g, OFF);
    digitalWrite(dp, ON);
}

void num_2() {
    digitalWrite(a, ON);
    digitalWrite(b, ON);
    digitalWrite(c, OFF);
    digitalWrite(d, ON);
    digitalWrite(e, ON);
    digitalWrite(f, OFF);
    digitalWrite(g, ON);
    digitalWrite(dp, OFF);
}

void num_3() {
    digitalWrite(a, ON);
    digitalWrite(b, ON);
    digitalWrite(c, ON);
    digitalWrite(d, ON);
    digitalWrite(e, OFF);
    digitalWrite(f, OFF);
    digitalWrite(g, ON);
    digitalWrite(dp, OFF);
}

void num_4() {
    digitalWrite(a, OFF);
    digitalWrite(b, ON);
    digitalWrite(c, ON);
    digitalWrite(d, OFF);
    digitalWrite(e, OFF);
    digitalWrite(f, ON);
    digitalWrite(g, ON);
    digitalWrite(dp, OFF);
}

void clear() {
    digitalWrite(a, OFF);
    digitalWrite(b, OFF);
    digitalWrite(c, OFF);
    digitalWrite(d, OFF);
    digitalWrite(e, OFF);
    digitalWrite(f, OFF);
    digitalWrite(g, OFF);
    digitalWrite(dp, OFF);
}

void clearAll() {
	digitalWrite(d1, HIGH);
	clear();
	digitalWrite(d2, HIGH);
	clear();
	digitalWrite(d3, HIGH);
	clear();
	digitalWrite(d4, HIGH);
	clear();
}
