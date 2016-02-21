int aPin=2;
  int bPin=4;
  int LPin=7;
  int RPin=8;
  int cPin = 11;//緑(左）
  int dPin = 10;//黄色(右
  int rPin = 12;
  int lPin = 13;
  const int PWM_mot = 9;
void setup() {
  Serial.begin(9600);
Serial.println("setup");
pinMode(cPin,OUTPUT);
pinMode(dPin,OUTPUT);
pinMode(rPin,OUTPUT);
pinMode(lPin,OUTPUT);

  // put your setup code here, to run once:

}

void loop() {
Serial.println("A");
digitalWrite(cPin,HIGH);
digitalWrite(dPin,LOW);
digitalWrite(lPin,HIGH);
digitalWrite(rPin,LOW);
 analogWrite(PWM_mot,40); //速度調節　0～255
delay(500);
Serial.println("B");
digitalWrite(cPin,LOW);
digitalWrite(dPin,HIGH);
digitalWrite(lPin,LOW);
digitalWrite(rPin,HIGH);
 analogWrite(PWM_mot,40); 
delay(500);
Serial.println("C");
digitalWrite(cPin,HIGH);
digitalWrite(dPin,LOW);
digitalWrite(lPin,LOW);
digitalWrite(rPin,HIGH);
 analogWrite(PWM_mot,40); 
delay(500);
Serial.println("D");
digitalWrite(cPin,LOW);
digitalWrite(dPin,HIGH);
digitalWrite(lPin,HIGH);
digitalWrite(rPin,LOW);
 analogWrite(PWM_mot,40); 
delay(500);
digitalWrite(cPin,LOW);
digitalWrite(dPin,LOW);
digitalWrite(rPin,LOW);
digitalWrite(lPin,LOW);

delay(100);

}
