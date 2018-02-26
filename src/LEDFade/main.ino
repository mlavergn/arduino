/*
Fade an LED

This is a very basic project to fade an LED on and off

- 1x LED
- 2x male:male wires
- 1x 220 ohm resistors
 */

#include <Arduino.h>

int led = 9;
int brightness = 0;
int fadeAmount = 5;

// setup, runs once
void setup() {
    pinMode(led, OUTPUT);
}

// main loop, runs repeatedly
void loop() {
    analogWrite(led, brightness);

    brightness += fadeAmount;

    if (brightness == 0 || brightness == 255) {
        fadeAmount = -fadeAmount;
    }

    delay(30);
}
