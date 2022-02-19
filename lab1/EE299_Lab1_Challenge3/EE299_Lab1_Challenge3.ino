/*
 * CHALLENGE 3: IR Controlled RGB LED
 * 
 * TODO: Locate the commented lines with "TODO:" and 
 * complete the task in the descriptions
 */
 
#include <IRremote.h>;
const int RECV_PIN = ;  // TODO: Assign the number of the RECV pin, according to the circuit diagram
const int redPin = 5;     
const int greenPin = 4;  
const int bluePin = 3;   
int i = 0;
int red = 0;
int green = 0;
int blue = 0;
int *active;
int OnOff = 0;
int ColorActive = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
Serial.begin(9600);
irrecv.enableIRIn(); // Start the receiver
// Set the three LED Pins as outputs
pinMode(redPin, _____ );    // TODO: Replace the "_____" to assign redPin as OUTPUT
pinMode(greenPin, _____ );  // TODO: Replace the "_____" to assign greenPin as OUTPUT
pinMode(bluePin, ______ );   // TODO: Replace the "_____" to assign bluePin as OUTPUT
}

void loop() {
if (irrecv.decode(&results)) {
//Serial.println(results.value, HEX);
irrecv.resume(); // Receive the next value
  if (results.value == 0x_______ && OnOff == 1){   // TODO: Replace the "_____" with the HEX code of the ON button
                                                   // Remember not to delete the 0x
  //Power off
  Serial.println("Turning off");
  setColor(0,0,0);
  OnOff = 0;
  ColorActive = 0;
}
else if (results.value == 0x______ && OnOff == 0){ // TODO: Replace the "_____" with the HEX code of the ON button
Serial.println("Turning on");
setColor(red,green,blue);
OnOff = 1;
}

if (OnOff == 1){
if (results.value == 0x______ && ColorActive == 1){  // TODO: Replace the "_____" with the HEX code of the Up arrow button
//Up arrow, increment the active color
colorUp(*active);
}
if (results.value == 0x______ && ColorActive == 1){  // TODO: Replace the "_____" with the HEX code of the Down arrow button
//Down arrow, decrement the active color
colorDown(*active);
}
if (results.value == 0x______ && ColorActive == 1){  // TODO: Replace the "_____" with the HEX code of the Right arrow button
//Right arrow, maximize the active color
*active = 230;
colorUp(*active);
}
if (results.value == 0x______ && ColorActive == 1){  // TODO: Replace the "_____" with the HEX code of the Left arrow button
//Left arrow, minimize the active color
*active = 25;
colorDown(*active);
}

if (results.value == 0x______ ){  // TODO: Replace the "_____" with the HEX code of the circle button
// Circle button
circle();
}

if (results.value == 0x______ ){  // TODO: Replace the "_____" with the HEX code of the red button
//A, Set red as the active color, and turn on Red as an indicator
Serial.println("Red is active");
active = &red;
ColorActive = 1;
}
if (results.value == 0x______ ){  // TODO: Replace the "_____" with the HEX code of the green button
//B, Set green as the active color, and turn on Green as an indicator
Serial.println("Green is active");
active = &green;
ColorActive = 1;
}
if (results.value == 0x______ ){ // TODO: Replace the "_____" with the HEX code of the blue button
//C, Set blue as the active color, and turn on Blue as an indicator
Serial.println("Blue is active");
active = &blue;
ColorActive = 1;
}
}
}
delay(100);
}

// Incrememnt the active color by 25
void colorUp(int &color){
color = (color + 25) % 256;
setColor(red,green,blue);
Serial.println(color);
}

// Decrememnt the active color by 25
void colorDown(int &color){
color = (color - 25) % 256;
setColor(red,green,blue);
Serial.println(color);
}

// Set the colors to the parameter values
void setColor(int red, int green, int blue){
analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);
}

// display the color cycle
void circle(){
red = 255;
green = 127;
blue = 0;
Serial.println("Start Circle");
while(true) {
red = (red + 25 +256) % 256;
green = (green + 25 +256) % 256;
blue = (blue + 25 +256) % 256;
setColor(red,green,blue);
delay(150);
if (irrecv.decode(&results)) {
Serial.println("Stop Circle");
irrecv.resume();
return;
}
}
}
