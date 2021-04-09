/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 5 has a pushbutton attached to it
int pushButton = 5;
int LED=9;   // digital pin 9 has LED attached to it
// the setup routine runs once when you press reset:
void setup() {
  
  Serial.begin(9600);// initialize serial communication at 9600 bits per second:
  
  pinMode(pushButton, INPUT);// make the pushbutton's pin an input:
  pinMode(LED,OUTPUT); // make the LED pin an output
}

// the loop routine runs over and over again forever:
void loop() {
  
  int buttonState = digitalRead(pushButton);// read the input pin and save it variable named buttonState
  
  if (buttonState==HIGH)// when the pushbutton is pressed
  {
    digitalWrite(LED,HIGH); // Sending HIGH Signal to LED
    Serial.print (" Toggle Switch is ON. Pushbutton is pressed, value is : ");
  Serial.println(buttonState);// print out the state of the button:
  }
  else
  {
    digitalWrite(LED,LOW); // Sending LOW signal to LED
    Serial.print (" Toggle Switch is OFF. Pushbutton is not pressed, value is : ");
  Serial.println(buttonState); // print out the state of the button:
  }
  delay(1);        // delay in between reads for stability
}
