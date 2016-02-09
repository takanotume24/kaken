/*
  DigitalReadSerial
  Reads a digital input on pin 2, prints the result to the serial monitor

  This example code is in the public domain.
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 13;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(38400);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}
long int count_second;
// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);

  if (buttonState == 00) {
    delay(1);
    count_second = 2 + count_second;
  }
  else {
    count_second = 0;
  }


  // delay in between reads for stability
  Serial.print(count_second);
}



