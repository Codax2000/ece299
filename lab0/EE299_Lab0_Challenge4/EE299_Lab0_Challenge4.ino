/*
 * CHALLENGE 4: Photoresistor and LED
 * 
 * Photoresistor senses the illuminance of an LED and changes resistance,
 * updates the serial monitor resistance value based on a blinking LED
 * 
 * TODO: Locate the commented lines with "TODO:" and 
 * complete the task in the descriptions
 */
 
// constants won't change. They're used here to set pin numbers:
const int sensorPin = ; // TODO: Assign the number of the sensor pin
int led = 13;
// variables will change:
int lightLevel; // variable for storing the photodiode data


void setup() {
 Serial.begin(9600);
 pinMode(led, OUTPUT); 
 pinMode(_____, INPUT); // TODO: Replace the "_____" to assign sensorPin as input
}

void loop(){
 digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
 delay(2000); // wait for two seconds
 
 lightLevel = analogRead(sensorPin);
 Serial.print("The photodiode is reading:");
 Serial.println(lightLevel);
 
 digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
 delay(1000); // wait for a second 
  
 lightLevel = analogRead(sensorPin);
 Serial.print("The photodiode is reading:");
 Serial.println(lightLevel);
}
