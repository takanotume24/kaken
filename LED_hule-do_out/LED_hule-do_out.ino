#define FADE_TIME 1.7
 
// LEDをつなぐピンを定義
int led_pins[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
 
// 初期化
void setup(){
 
  int i;
 
  // LEDのピンを出力に
  for (i=0; i<12; i++) {
    pinMode(led_pins[i], OUTPUT);
  }
 
}
 
// メインループ
void loop() {
 
  int i,j;
 
  // LEDを暗から明へフェード
  for (j=0; j<12; j++) {
    for (i=0; i<256; i++) {
      analogWrite(led_pins[j], i);
      delay(FADE_TIME);
    }
  }
 
  // LEDを明から暗へフェード
  for (j=0; j<12; j++) {
    for (i=256; i>-1; i--) {
      analogWrite(led_pins[j], i);
      delay(FADE_TIME);
    }
  }
}
