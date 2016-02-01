#include <Wire.h>

const int LIS3DH_ADDR = 0x18;



unsigned int readRegister(byte reg) {
  Wire.beginTransmission(LIS3DH_ADDR);
  Wire.write(reg);
  Wire.endTransmission();

  Wire.requestFrom(LIS3DH_ADDR, 1);
  return Wire.read();
}

void writeRegister(byte reg, byte date) {
  Wire.beginTransmission(LIS3DH_ADDR);
  Wire.write(reg);
  Wire.write(date);
  Wire.endTransmission();
}

void setup() {
    // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Wire.begin();
  Serial.begin(250000);

  writeRegister(0x20, 0x27);
  int res = readRegister(0x0F);
  Serial.print(res);
}

void loop() {
  int x, y, z;
  int h, l;

  writeRegister(0x20, 0x27);
  l = readRegister(0x28);
  h = readRegister(0x29);
  x = h << 8 | l;

  l = readRegister(0x2A);
  h = readRegister(0x2B);
  y = h << 8 | l;

  l = readRegister(0x2C);
  h = readRegister(0x2D);
  z = h << 8 | l;
  
  if (z > 0){
    Serial.print("flont");
    digitalWrite(13, HIGH);
  }
  else{
    Serial.print("back");
    digitalWrite(13, LOW);
  }
  Serial.print("\n");

  delay(0);

}

