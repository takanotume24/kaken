const int button = 2;
int val = 0;
int time = 0;
int once = 0;

void setup() {
pinMode(button, INPUT);
pinMode(5,OUTPUT);
Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop(){
  val = digitalRead(button);
if (val == HIGH) {
time++; //一加算ここで時間をはかる
 Serial.println(time) ; 
delay(1);
} else {
time = 0; 
once = 0; //もう一度送信できるように
}
if (time > 400) { //長押しif文
time = 401;
if (!once) {  
Serial.print("A"); //Ａと送信
digitalWrite(5,HIGH);
once=1;
//連続で送信されないように
}
}
if (!once) {
  if(time<45&&time>0){  
Serial.print("B"); //Bと送信
digitalWrite(5,LOW);
once=0;
//連続で送信されないように
}
  // put your main code here, to run repeatedly:

}}
