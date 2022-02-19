/**
 * @file EE299_Lab1_Challenge3.ino
 * @author Alex Knowlton (ak247@uw.edu)
 * @brief A file for controlling an RGB LED using an IR remote
 * @version 0.1
 * @date 2022-02-18
 * This file, when compiled and uploaded to an Arduino, allows control of an
 * RGB LED through the use of an IR remote. There are several different modes
 * of operation, including brightening, dimming, and switching colors, in
 * addition to cycling through the color palette made by the LED.
 * 
 * This file uses Ken Shiriff's IR remote library, assuming version 1.0, to
 * communicate with the IR remote. It also uses a timer library for setting
 * and controlling an interrupt.
 * @copyright Copyright (c) 2022
 * 
 */

#include <IRremote.h>

#define OR_EQUAL(val, a, b) (val == a || val == b)

// define statements make code easier to read and stay efficient
#define RED_LED 5
#define GREEN_LED 4
#define BLUE_LED 3
#define RECV_PIN 9

// amount the active color should increment by
#define INCREMENT 25
#define CYCLE_INCREMENT 2

// button codes when received by the IR remote.
// easy to read using an IRremote example
#define ON 0xFFA25D
#define UP 0xFF906F
#define DOWN 0xFFE01F
#define RIGHT 0xFFC23D
#define LEFT 0xFF22DD
#define RED 0xFF30CF
#define GREEN 0xFF18E7
#define BLUE 0xFF7A85
#define CIRCLE 0xFF02FD

// values for the IR receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

// color levels that should be written to the RGB LED.
// standard color channel order: red, green, blue
// begin with red on at half power
// the active color denotes which value will be incremented when up/down/left/right is pressed
int colors[3] = {127, 0, 0};
int activeColor = 0;

// boolean value tracking whether the leds are on or not
bool ledsAreOn;

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn(); // enable IR reception from the remote

    // set pin modes - don't have to do it for the IR pin because irrecv already did it
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
}

void loop()
{
    if (irrecv.decode(&results)) { // if there is a result available, interpret it
        interpretResults();
    }
    delay(100);
}

void interpretResults() {
    irrecv.resume();
    Serial.print("Command: ");
    Serial.println(results.value, HEX);
    if (results.value == ON) { // if the on button pressed and we are on, turn everything off
        if (ledsAreOn) {
            clearColors();
        } else {
            setColors();
        }
        ledsAreOn = !ledsAreOn;
    }

    // if the system is on, interpret the value, otherwise do nothing
    if (ledsAreOn) {
        switch(results.value) {
            case UP: {
              addToActiveColor(INCREMENT);
              break;
            }
            case DOWN: {
              addToActiveColor(-INCREMENT);
              break;
            }
            case LEFT: {
              minimizeActiveColor();
              break;
            }
            case RIGHT: {
              maximizeActiveColor();
              break;
            }
            case RED: {
              setActiveColor(0);
              break;
            }
            case BLUE: {
              setActiveColor(1);
              break;
            }
            case GREEN: {
              setActiveColor(2);
              break;
            }
            case CIRCLE: {
              colorCircle();
              break;
            }
            default: {
              Serial.print("Invalid Command: 0x");
              Serial.println(results.value, HEX);
              break;
            }
        }
    }
}

// adds the given increment to the active color
void addToActiveColor(int increment) {
    colors[activeColor] += increment;
    setColors();
}

// sets the active color to 0
void minimizeActiveColor() {
    colors[activeColor] = 0;
    setColors();
}

// sets the active color to 255
void maximizeActiveColor() {
    colors[activeColor] = 255;
    setColors();
}

// sets the given active color
void setActiveColor(int color) {
    char* colors[3] = {"RED", "GREEN", "BLUE"};
    Serial.print("Setting active color: ");
    Serial.println(colors[color]);
    activeColor = color;
}

// cycles through the color cycle
void colorCircle() {
    colors[0] = 255;
    colors[1] = 127;
    colors[2] = 0;
    delay(250);
    while(!irrecv.decode(&results)) {
      setColors();
      colors[0] = (colors[0] + CYCLE_INCREMENT + 256) % 256;
      colors[1] = (colors[1] + CYCLE_INCREMENT + 256) % 256;
      colors[2] = (colors[2] + CYCLE_INCREMENT + 256) % 256;
      delay(1);
    }
    interpretResults();
}

void setColors() {
    Serial.print("Setting Colors: ");
    for (int i = 0; i < 3; i++) {
        Serial.print(colors[i], HEX);
        Serial.print(" ");
    }
    Serial.println();
    analogWrite(RED_LED, colors[0]);
    analogWrite(GREEN_LED, colors[1]);
    analogWrite(BLUE_LED, colors[2]);
}

void clearColors() {
    Serial.println("Clearing Colors");
    analogWrite(RED_LED, 0);
    analogWrite(GREEN_LED, 0);
    analogWrite(BLUE_LED, 0);
}
