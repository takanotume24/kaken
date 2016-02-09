char sleepCheck() {
  //     _                 _
  // ___| |____||||||_____| |___
  //   PRESS   bounds  DoubleClick
  char r = 0;
  if (SWITCH == 0) {
    delay(30); //チャンリング除去
    //スイッチが押された
    if (sleepTimer == 0) //始めて押された
      sleepTimer = millis(); //ボタンを押し始めた時間をセット
    else
      //長押し中?
      if (millis() - sleepTimer > SLEEPTIME) { //長押し判定
        fadeoutGreen();
        cli();
        sleep_enable();
        sei();
        attachInterrupt(0, wakeup, LOW);
        delay(1000);
        sleep_cpu();
        sleep_disable();
        sleepTimer = 0;
        r = LONGPRESS;
      }
  } else {
    //スイッチは押されていない
    if (sleepTimer == 0)
      r = 0; //以前スイッチは押されていないし、今も押されていないときは、キー入力なし(0)
    else {
      //以前スイッチが押されていた場合(sleepTimer>0)はクリック種別判定へ
      long a = millis() - sleepTimer;
      if (a <= DEBOUNDS)
        r = 0; //チャタリング期間中はキーOFF判定無視
      else {
        if (a < DEBOUNDS + 500) {
          //ダフルクリック判定期間(チャンリング期間経過後+500ms)
          long b = millis(); //今の時間
          while (millis() - b < 500) {
            if (SWITCH == 0) {
              r = DOUBLECLICK; //500ms以内にスイッチが押されればダブルクリックと判定する
              sleepTimer = 0;
            }
          }
        } else {
          //ダフルクリック判定期間経過後はシングルとして判定
          r = SINGLECLICK;
          sleepTimer = 0;
        }
      }
    }
  }
  return r;
}
