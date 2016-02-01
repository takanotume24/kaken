#include <Wire.h>

void setup(){
  Wire.begin();
  Serial.begin(9600);
}

void loop(){
  Serial.println("I2C transmission start");
  Wire.beginTransmission(0x18);
  Wire.write(0x0F);
  int ans = Wire.endTransmission();
  switch (ans) {
  case 0:
    Serial.println("succesful");
    Wire.requestFrom(0x18, 1);
    Serial.println(Wire.read(), HEX);
    break;
  case 1:
    Serial.println("Buffer overflow");
    break;
  case 2:  
    Serial.println("NACK to the slave address");
    break;
  case 3:
    Serial.println("NACK to the date byte");
    break;
  case 4:
    Serial.println("unknow");
    break; 
  }
  delay(1000);
}

