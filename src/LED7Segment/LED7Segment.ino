/*
7 Segment LED

This is an introduction on how to drive a 7 Segment LED using only a Arduino.  
This is not the best way to do this.  
To save pins, one would use a dedicated IC using SPI or a Shift Register.

- 1x 7 segment LED (5011AS)
- 11x male:make wires
- 2x 220 ohm resistors
- note: connect only ground
 
digitalWrite(A, HIGH) = turn on the segment in the LED display
digitalWrite(B, LOW)  = turn off the segment in the LED display

Thank you to Riley Porter for the wiring diagram
*/

#include <Arduino.h>

#define A 8
#define B 9
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6

// clear all LEDs
void all_on() {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
}

// light up all LEDs
void all_off() {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
}

// pin setup
void setup() {
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    Serial.begin(9600);
}

#define TOP 8
#define MIDDLE 5
#define BOTTOM 3

#define UPPER_LEFT 6
#define LOWER_LEFT 4

#define UPPER_RIGHT 9
#define LOWER_RIGHT 2

// letter A
int a[] = {LOWER_LEFT, UPPER_LEFT, TOP, UPPER_RIGHT, LOWER_RIGHT, MIDDLE};
int b[] = {LOWER_LEFT, UPPER_LEFT, TOP, UPPER_RIGHT, MIDDLE, LOWER_RIGHT, BOTTOM};
int c[] = {TOP, UPPER_LEFT, LOWER_LEFT, BOTTOM};
int d[] = {UPPER_LEFT, LOWER_LEFT, BOTTOM, LOWER_RIGHT, UPPER_RIGHT, TOP};
int e[] = {UPPER_LEFT, LOWER_LEFT, TOP, MIDDLE, BOTTOM};
int f[] = {UPPER_LEFT, LOWER_LEFT, TOP, MIDDLE};
int h[] = {UPPER_LEFT, LOWER_LEFT, UPPER_RIGHT, LOWER_RIGHT, MIDDLE};
int l[] = {UPPER_LEFT, LOWER_LEFT, BOTTOM};
int o[] = {UPPER_LEFT, LOWER_LEFT, BOTTOM, LOWER_RIGHT, UPPER_RIGHT, TOP};
int z[] = {TOP, UPPER_RIGHT, MIDDLE, LOWER_LEFT, BOTTOM};

// toogles the character LEDs
#define writeChar(arr) _writeChar(arr, sizeof(arr)/sizeof(int))
void _writeChar(int arr[], int count) {
    all_off();
    for (int i = 0; i < count; i++) {
        digitalWrite(arr[i], HIGH);
        delay(100);
    }
}

// main loop
void loop() {
    Serial.println("Starting ...");

    writeChar(c);
    delay(1000);

    writeChar(h);
    delay(1000);

    writeChar(l);
    delay(1000);

    writeChar(o);
    delay(1000);

    writeChar(e);
    delay(1000);
}
