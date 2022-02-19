/*
 * CHALLENGE 1: Blinking LED Circuit
 * 
 * Creates a blinking LED
 * 
 * TODO: Locate the commented lines with "TODO:" and 
 * complete the task in the descriptions
 */

// TODO: assign an integer value of the pin number on on the arduino connected to the led
int led = ;
// setup() function runs once when the Arduino turns on or is reset
void setup() { 
  // initialize the digital pin as output.
  // assign variable led as this output
  pinMode(led, OUTPUT); 
}
// loop() function runs the code inside repeatedly while Arduino is still on
void loop() {
  digitalWrite(led, _____); // Replace "_____", turn the LED on (HIGH is the voltage level), 
  delay(2000); // wait for two seconds
  digitalWrite(led, _____); // Replace "_____", turn the LED off by making the voltage LOW
  delay(1000); // wait for a second
}
