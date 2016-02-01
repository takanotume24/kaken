#include <Wire.h>

const int LIS3DH_ADDR = 0x18;

unsigned int readRegister(byte reg) {
  Wire.beginTransmission(LIS3Dh_ADDR);
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

void setup(){
  Wire.begin();
  Serial.begin(9600);

  wireRegister(0x20, 0x27);
  int res = readRegister(0x0F);
  Serial.printf(res);
}

void loop(){
  int x.y.z;
}

