/*
 * CHALLENGE 3: Serial Output
 * 
 * Prints "Hello World" to the serial monitor on a loop
 * 
 * TODO: Locate the commented lines with "TODO:" and 
 * complete the task in the descriptions
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // sets the baude rate of the serial communication, 9600 bits per second
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(""); // TODO: Print "Hello World !" or any other message to the serial monitor
  //Prints the text between the quotation to the serial monitor
  Serial.print("\n");
}
