/*
 * CHALLENGE 1: IR Sensor and IR LED 
 * 
 * TODO: Locate the commented lines with "TODO:" and 
 * complete the task in the descriptions
 * 
 * This Challenge has similar setup as Lab 0 Challenge 4
 */
#include <TimerOne.h>;
// constants won't change. They're used here to set pin numbers: 
const int irledPin =   ;    // TODO: Assign the number of the IR LED pin for Arduino Mega
const int sensorPin =   ; // TODO: Assign the number of the IR sensor pin 
const int ledPin = 3; // the number of the LED pin
// variables will change: 
int lightLevel; // variable for storing the sensor data 
int irledState; //variable to store the irLED state: HIGH = on, LOW = off

void setup() { 
 Serial.begin(9600); 
 pinMode( _____  , INPUT);  // TODO: Replace the "_____" to assign irledPin/sensorPin as input, refer to Lab 0 Challenge 4
 pinMode( _____ , OUTPUT);  // TODO: Replace the "_____" to assign irledPin/sensorPin as output, refer to Lab 0 Challenge 4
 pinMode(ledPin, OUTPUT);
 Timer1.initialize(26); // set a timer of length 26 microseconds (or 38kHz)  
 Timer1.attachInterrupt(callback); //attach the routine that will happen at the  interrupt 
} 

void loop(){ 
 lightLevel = digitalRead(sensorPin); 
 Serial.print("The IR Sensor is reading:"); 
 Serial.println(lightLevel); 
 delay(1000); // delay in order to give some time to read the button press  //you can change this value and observe the difference 

 irledState = digitalRead( irledPin ); // read the state of the irLED value:
  if (irledState == HIGH) { // check if the irLED is ON
  digitalWrite(ledPin , HIGH); // turn LED on
  } 
  else if (irledState == LOW) { // check if the irLED is OFF
  digitalWrite(ledPin, LOW); // turn LED off
  }
} 

void callback() // time sensitive function to toggle the IR LED 
{ 
 digitalWrite(irledPin, digitalRead(irledPin) ^ 1); //Toggle the IR LED 
}
