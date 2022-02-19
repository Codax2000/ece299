/*
 * CHALLENGE 2: Push Button Circuit
 * 
 * Controls an LED's turn-on state via a pushbutton, when button is down,
 * LED is on, and when the button is up, the LED is off
 * 
 * TODO: Locate the commented lines with "TODO:" and 
 * complete the task in the descriptions
 */

int buttonPin = ; // TODO: assign the integer number of the pin connected to the pushbutton
int ledPin = ;    // TODO: assign the integer number of the pin connected to the LED
// variables will change:
int buttonState; // variable for reading the pushbutton status
int ledState = LOW; // variable to store the LED state: HIGH = on, LOW = off

void setup() {
  // TODO: assign the first value in each pinMode function to buttonPin or ledPin
  //       based on whether the pin is an input of output based on the schematic
  //       (hint: current flows from the output, to the resistor, to the diode, to the input)
  pinMode(_____, INPUT);   
  pinMode(_____, OUTPUT); 
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead( buttonPin );
  
  // check if the pushbutton is pressed (push button state is HIGH)
  if (buttonState == _____ && ledState == LOW) { // TODO: Replace "_____" to change button state
    // turn LED on: 
    digitalWrite(_____ , _____); // TODO: Replace "_____" to turn the LED on by driving the ledPin HIGH
    ledState = ;                 // TODO: Change the LED State variable to the same value (HIGH or LOW)
  } 
  // TODO: Replace "_____" to complete the condition of buttonState and ledState in order to turn LED off
  else if (buttonState == _____ && ledState == _____) { 
    // turn LED off:
    digitalWrite(_____, _____); // TODO: Replace "_____" to turn the LED off
    ledState = ;                // TODO: Change LED State variable to inverse of initial state (opposite of HIGH) 
  }
 delay(100); // delay in order to give some time to read the button press
 //you can change this value and observe the difference
}
